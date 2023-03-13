void crypt_blowfish_encode (cryptstate_T *state, char_u *from, size_t len, char_u *to) {
    bf_state_T *bfs = state->method_state;
    size_t i;
    int ztemp, t;
    for (i = 0; i < len; ++i) {
        ztemp = from[i];
        BF_RANBYTE (bfs, t);
        BF_CFB_UPDATE (bfs, ztemp);
        to[i] = t ^ ztemp;
    }
}

void crypt_blowfish_decode (cryptstate_T *state, char_u *from, size_t len, char_u *to) {
    bf_state_T *bfs = state->method_state;
    size_t i;
    int t;
    for (i = 0; i < len; ++i) {
        BF_RANBYTE (bfs, t);
        to[i] = from[i] ^ t;
        BF_CFB_UPDATE (bfs, to [i]);
    }
}

void crypt_blowfish_init (cryptstate_T *state, char_u *key, char_u *salt, int salt_len, char_u *seed, int seed_len) {
    bf_state_T *bfs = (bf_state_T *) alloc_clear (sizeof (bf_state_T));
    state->method_state = bfs;
    bfs->cfb_len = state->method_nr == CRYPT_M_BF ? BF_MAX_CFB_LEN : BF_BLOCK;
    if (blowfish_self_test () == FAIL)
        return;
    bf_key_init (bfs, key, salt, salt_len);
    bf_cfb_init (bfs, seed, seed_len);
}

int blowfish_self_test (void) {
    if (sha256_self_test () == FAIL) {
        EMSG (_ ("E818: sha256 test failed"));
        return FAIL;
    }
    if (bf_self_test () == FAIL) {
        EMSG (_ ("E819: Blowfish test failed"));
        return FAIL;
    }
    return OK;
}

static int bf_self_test (void) {
    int i, bn;
    int err = 0;
    block8 bk;
    UINT32_T ui = 0xffffffffUL;
    bf_state_T state;
    vim_memset (& state, 0, sizeof (bf_state_T));
    state.cfb_len = BF_MAX_CFB_LEN;
    if (ui != 0xffffffffUL || ui + 1 != 0) {
        err++;
        EMSG (_ ("E820: sizeof(uint32_t) != 4"));
    }
    if (!bf_check_tables (pax_init, sbx_init, 0x6ffa520a))
        err++;
    bn = ARRAY_LENGTH (bf_test_data);
    for (i = 0; i < bn; i++) {
        bf_key_init (& state, (char_u *) (bf_test_data [i].password), bf_test_data [i].salt, (int) STRLEN (bf_test_data [i].salt));
        if (!bf_check_tables (state.pax, state.sbx, bf_test_data[i].keysum))
            err++;
        memcpy (bk.uc, bf_test_data [i].plaintxt, 8);
        bf_e_cblock (& state, bk.uc);
        if (memcmp (bk.uc, bf_test_data[i].cryptxt, 8) != 0) {
            if (err == 0 && memcmp (bk.uc, bf_test_data[i].badcryptxt, 8) == 0)
                EMSG (_ ("E817: Blowfish big/little endian use wrong"));
            err++;
        }
    }
    return err > 0 ? FAIL : OK;
}

static int bf_check_tables (UINT32_T pax [18], UINT32_T sbx [4] [256], UINT32_T val) {
    int i, j;
    UINT32_T c = 0;
    for (i = 0; i < 18; i++)
        c ^= pax[i];
    for (i = 0; i < 4; i++)
        for (j = 0; j < 256; j++)
            c ^= sbx[i][j];
    return c == val;
}

static void bf_key_init (bf_state_T *bfs, char_u *password, char_u *salt, int salt_len) {
    int i, j, keypos = 0;
    unsigned  u;
    UINT32_T val, data_l, data_r;
    char_u *key;
    int keylen;
    key = sha256_key (password, salt, salt_len);
    for (i = 0; i < 1000; i++)
        key = sha256_key (key, salt, salt_len);
    keylen = (int) STRLEN (key) / 2;
    if (keylen == 0) {
        IEMSG (_ ("E831: bf_key_init() called with empty password"));
        return;
    }
    for (i = 0; i < keylen; i++) {
        sscanf ((char *) & key [i * 2], "%2x", & u);
        key[i] = u;
    }
    mch_memmove (bfs -> sbx, sbx_init, 4 * 4 * 256);
    for (i = 0; i < 18; ++i) {
        val = 0;
        for (j = 0; j < 4; ++j)
            val = (val << 8) | key[keypos++ % keylen];
        bfs->pax[i] = pax_init[i] ^ val;
    }
    data_l = data_r = 0;
    for (i = 0; i < 18; i += 2) {
        bf_e_block (bfs, & data_l, & data_r);
        bfs->pax[i + 0] = data_l;
        bfs->pax[i + 1] = data_r;
    }
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 256; j += 2) {
            bf_e_block (bfs, & data_l, & data_r);
            bfs->sbx[i][j + 0] = data_l;
            bfs->sbx[i][j + 1] = data_r;
        }
    }
}

static void bf_e_block (bf_state_T *bfs, UINT32_T *p_xl, UINT32_T *p_xr) {
    UINT32_T temp;
    UINT32_T xl = *p_xl;
    UINT32_T xr = *p_xr;
    F1 (0)
    F2 (1)
    F1 (2)
    F2 (3)
    F1 (4)
    F2 (5)
    F1 (6)
    F2 (7)
    F1 (8)
    F2 (9)
    F1 (10)
    F2 (11)
    F1 (12)
    F2 (13)
    F1 (14)
    F2 (15)
    xl ^= bfs->pax[16];
    xr ^= bfs->pax[17];
    temp = xl;
    xl = xr;
    xr = temp;
    *p_xl = xl;
    *p_xr = xr;
}

# define htonl2(x)

static void bf_e_cblock (bf_state_T *bfs, char_u *block) {
    block8 bk;
    memcpy (bk.uc, block, 8);
    htonl2 (bk.ul [0]);
    htonl2 (bk.ul [1]);
    bf_e_block (bfs, & bk.ul [0], & bk.ul [1]);
    htonl2 (bk.ul [0]);
    htonl2 (bk.ul [1]);
    memcpy (block, bk.uc, 8);
}

static void bf_cfb_init (bf_state_T *bfs, char_u *seed, int seed_len) {
    int i, mi;
    bfs->randbyte_offset = bfs->update_offset = 0;
    vim_memset (bfs -> cfb_buffer, 0, bfs -> cfb_len);
    if (seed_len > 0) {
        mi = seed_len > bfs->cfb_len ? seed_len : bfs->cfb_len;
        for (i = 0; i < mi; i++)
            bfs->cfb_buffer[i % bfs->cfb_len] ^= seed[i % seed_len];
    }
}

#define BF_CFB_UPDATE(bfs, c) { bfs->cfb_buffer[bfs->update_offset] ^= (char_u)c; if (++bfs->update_offset == bfs->cfb_len) bfs->update_offset = 0; }

#define BF_RANBYTE(bfs, t) { if ((bfs->randbyte_offset & BF_BLOCK_MASK) == 0) bf_e_cblock(bfs, &(bfs->cfb_buffer[bfs->randbyte_offset])); t = bfs->cfb_buffer[bfs->randbyte_offset]; if (++bfs->randbyte_offset == bfs->cfb_len) bfs->randbyte_offset = 0; }

