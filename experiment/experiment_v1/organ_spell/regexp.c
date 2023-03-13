struct spelltab_S {
    char_u st_isw [256];
    char_u st_isu [256];
    char_u st_fold [256];
    char_u st_upper [256];
};
struct langp_S {
    slang_T *lp_slang;
    slang_T *lp_sallang;
    slang_T *lp_replang;
    int lp_region;
};
struct salitem_S {
    char_u *sm_lead;
    int sm_leadlen;
    char_u *sm_oneof;
    char_u *sm_rules;
    char_u *sm_to;
};
struct fromto_S {
    char_u *ft_from;
    char_u *ft_to;
};
struct slang_S {
    slang_T *sl_next;
    char_u *sl_name;
    char_u *sl_fname;
    int sl_add;
    char_u *sl_fbyts;
    idx_T *sl_fidxs;
    char_u *sl_kbyts;
    idx_T *sl_kidxs;
    char_u *sl_pbyts;
    idx_T *sl_pidxs;
    char_u *sl_info;
    char_u sl_regions [MAXREGIONS * 2 + 1];
    char_u *sl_midword;
    hashtab_T sl_wordcount;
    int sl_compmax;
    int sl_compminlen;
    int sl_compsylmax;
    int sl_compoptions;
    garray_T sl_comppat;
    regprog_T *sl_compprog;
    char_u *sl_comprules;
    char_u *sl_compstartflags;
    char_u *sl_compallflags;
    char_u sl_nobreak;
    char_u *sl_syllable;
    garray_T sl_syl_items;
    int sl_prefixcnt;
    regprog_T **sl_prefprog;
    garray_T sl_rep;
    short  sl_rep_first [256];
    garray_T sl_sal;
    salfirst_T sl_sal_first [256];
    int sl_followup;
    int sl_collapse;
    int sl_rem_accents;
    int sl_sofo;
    garray_T sl_repsal;
    short  sl_repsal_first [256];
    int sl_nosplitsugs;
    int sl_nocompoundsugs;
    time_t sl_sugtime;
    char_u *sl_sbyts;
    idx_T *sl_sidxs;
    buf_T *sl_sugbuf;
    int sl_sugloaded;
    int sl_has_map;
    char_u sl_map_array [256];
    hashtab_T sl_sounddone;
};
struct exarg {
    char_u *arg;
    char_u *nextcmd;
    char_u *cmd;
    char_u **cmdlinep;
    cmdidx_T cmdidx;
    long  argt;
    int skip;
    int forceit;
    int addr_count;
    linenr_T line1;
    linenr_T line2;
    int addr_type;
    int flags;
    char_u *do_ecmd_cmd;
    linenr_T do_ecmd_lnum;
    int append;
    int usefilter;
    int amount;
    int regname;
    int force_bin;
    int read_edit;
    int force_ff;
    int useridx;
    char_u *errmsg;
    char_u * (*getline) (int, void *, int);
    void *cookie;
    struct condstack *cstack;
};
struct lval_S {
    char_u *ll_name;
    char_u *ll_exp_name;
    typval_T *ll_tv;
    listitem_T *ll_li;
    list_T *ll_list;
    int ll_range;
    long  ll_n1;
    long  ll_n2;
    int ll_empty2;
    dict_T *ll_dict;
    dictitem_T *ll_di;
    char_u *ll_newkey;
};
struct timer_S {
    long  tr_id;
    timer_T *tr_next;
    timer_T *tr_prev;
    proftime_T tr_due;
    char tr_firing;
    char tr_paused;
    int tr_repeat;
    long  tr_interval;
    char_u *tr_callback;
    partial_T *tr_partial;
    int tr_emsg_count;
};
struct js_reader {
    char_u *js_buf;
    char_u *js_end;
    int js_used;
    int (*js_fill) (struct js_reader *);
    void *js_cookie;
    int js_cookie_arg;
};
struct cmdarg_S {
    oparg_T *oap;
    int prechar;
    int cmdchar;
    int nchar;
    int extra_char;
    long  opcount;
    long  count0;
    long  count1;
    int arg;
    int retval;
    char_u *searchbuf;
};
struct oparg_S {
    int op_type;
    int regname;
    int motion_type;
    int motion_force;
    int use_reg_one;
    int inclusive;
    int end_adjusted;
    pos_T start;
    pos_T end;
    pos_T cursor_start;
    long  line_count;
    int empty;
    int is_VIsual;
    int block_mode;
    colnr_T start_vcol;
    colnr_T end_vcol;
    long  prev_opcount;
    long  prev_count0;
};
struct diffblock_S {
    diff_T *df_next;
    linenr_T df_lnum [DB_COUNT];
    linenr_T df_count [DB_COUNT];
};
struct list_stack_S {
    list_T *list;
    struct list_stack_S *prev;
};
struct ht_stack_S {
    hashtab_T *ht;
    struct ht_stack_S *prev;
};
struct channel_S {
    channel_T *ch_next;
    channel_T *ch_prev;
    int ch_id;
    int ch_last_msg_id;
    chanpart_T ch_part [PART_COUNT];
    int ch_write_text_mode;
    char *ch_hostname;
    int ch_port;
    int ch_to_be_closed;
    int ch_to_be_freed;
    int ch_error;
    void (*ch_nb_close_cb) (void);
    char_u *ch_callback;
    partial_T *ch_partial;
    char_u *ch_close_cb;
    partial_T *ch_close_partial;
    int ch_drop_never;
    int ch_keep_open;
    job_T *ch_job;
    int ch_job_killed;
    int ch_refcount;
    int ch_copyID;
};
struct cbq_S {
    char_u *cq_callback;
    partial_T *cq_partial;
    int cq_seq_nr;
    cbq_T *cq_next;
    cbq_T *cq_prev;
};
struct jsonq_S {
    typval_T *jq_value;
    jsonq_T *jq_next;
    jsonq_T *jq_prev;
    int jq_no_callback;
};
struct writeq_S {
    garray_T wq_ga;
    writeq_T *wq_next;
    writeq_T *wq_prev;
};
struct readq_S {
    char_u *rq_buffer;
    long_u rq_buflen;
    readq_T *rq_next;
    readq_T *rq_prev;
};
struct jobvar_S {
    job_T *jv_next;
    job_T *jv_prev;
    pid_t jv_pid;
    char_u *jv_tty_in;
    char_u *jv_tty_out;
    jobstatus_T jv_status;
    char_u *jv_stoponexit;
    int jv_exitval;
    char_u *jv_exit_cb;
    partial_T *jv_exit_partial;
    buf_T *jv_in_buf;
    int jv_refcount;
    int jv_copyID;
    channel_T *jv_channel;
};
struct partial_S {
    int pt_refcount;
    char_u *pt_name;
    ufunc_T *pt_func;
    int pt_auto;
    int pt_argc;
    typval_T *pt_argv;
    dict_T *pt_dict;
};
struct funccall_S {
    ufunc_T *func;
    int linenr;
    int returned;
    struct {
        dictitem_T var;
        char_u room [VAR_SHORT_LEN];
    } fixvar [FIXVAR_CNT];
    dict_T l_vars;
    dictitem_T l_vars_var;
    dict_T l_avars;
    dictitem_T l_avars_var;
    list_T l_varlist;
    listitem_T l_listitems [MAX_FUNC_ARGS];
    typval_T *rettv;
    linenr_T breakpoint;
    int dbg_tick;
    int level;
    proftime_T prof_child;
    funccall_T *caller;
    int fc_refcount;
    int fc_copyID;
    garray_T fc_funcs;
};
struct dictitem16_S {
    typval_T di_tv;
    char_u di_flags;
    char_u di_key [17];
};
struct listvar_S {
    listitem_T *lv_first;
    listitem_T *lv_last;
    int lv_refcount;
    int lv_len;
    listwatch_T *lv_watch;
    int lv_idx;
    listitem_T *lv_idx_item;
    int lv_copyID;
    list_T *lv_copylist;
    char lv_lock;
    list_T *lv_used_next;
    list_T *lv_used_prev;
};
struct listwatch_S {
    listitem_T *lw_item;
    listwatch_T *lw_next;
};
struct listitem_S {
    listitem_T *li_next;
    listitem_T *li_prev;
    typval_T li_tv;
};
struct hashitem_S {
    long_u hi_hash;
    char_u *hi_key;
};
struct mapblock {
    mapblock_T *m_next;
    char_u *m_keys;
    char_u *m_str;
    char_u *m_orig_str;
    int m_keylen;
    int m_mode;
    int m_noremap;
    char m_silent;
    char m_nowait;
    char m_expr;
    scid_T m_script_ID;
};
struct keyentry {
    keyentry_T *ke_next;
    struct sp_syn k_syn;
    short  *next_list;
    int flags;
    int k_char;
    char_u keyword [1];
};
struct sp_syn {
    int inc_tag;
    short  id;
    short  *cont_in_list;
};
struct cleanup_stuff {
    int pending;
    except_T *exception;
};
struct condstack {
    short  cs_flags [CSTACK_LEN];
    char cs_pending [CSTACK_LEN];
    union {
        void *csp_rv [CSTACK_LEN];
        void *csp_ex [CSTACK_LEN];
    } cs_pend;
    void *cs_forinfo [CSTACK_LEN];
    int cs_line [CSTACK_LEN];
    int cs_idx;
    int cs_looplevel;
    int cs_trylevel;
    eslist_T *cs_emsg_silent_list;
    char cs_lflags;
};
struct eslist_elem {
    int saved_emsg_silent;
    eslist_T *next;
};
struct argentry {
    char_u *ae_fname;
    int ae_fnum;
};
struct memline {
    linenr_T ml_line_count;
    memfile_T *ml_mfp;

    #define ML_EMPTY	1	/* empty buffer */

    #define ML_LINE_DIRTY	2	/* cached line was changed and allocated */

    #define ML_LOCKED_DIRTY	4	/* ml_locked was changed */

    #define ML_LOCKED_POS	8	/* ml_locked needs positive block number */
    int ml_flags;
    infoptr_T *ml_stack;
    int ml_stack_top;
    int ml_stack_size;
    linenr_T ml_line_lnum;
    char_u *ml_line_ptr;
    bhdr_T *ml_locked;
    linenr_T ml_locked_low;
    linenr_T ml_locked_high;
    int ml_locked_lineadd;
    chunksize_T *ml_chunksize;
    int ml_numchunks;
    int ml_usedchunks;
};
struct memfile {
    char_u *mf_fname;
    char_u *mf_ffname;
    int mf_fd;
    bhdr_T *mf_free_first;
    bhdr_T *mf_used_first;
    bhdr_T *mf_used_last;
    unsigned  mf_used_count;
    unsigned  mf_used_count_max;
    mf_hashtab_T mf_hash;
    mf_hashtab_T mf_trans;
    blocknr_T mf_blocknr_max;
    blocknr_T mf_blocknr_min;
    blocknr_T mf_neg_count;
    blocknr_T mf_infile_count;
    unsigned  mf_page_size;
    int mf_dirty;
    buf_T *mf_buffer;
    char_u mf_seed [MF_SEED_LEN];
    char_u *mf_old_key;
    int mf_old_cm;
    char_u mf_old_seed [MF_SEED_LEN];
};
struct expand {
    int xp_context;
    char_u *xp_pattern;
    int xp_pattern_len;
    char_u *xp_arg;
    int xp_scriptID;
    int xp_backslash;
    int xp_shell;
    int xp_numfiles;
    char_u **xp_files;
    char_u *xp_line;
    int xp_col;
};
struct nr_trans {
    mf_hashitem_T nt_hashitem;

    #define nt_old_bnum nt_hashitem.mhi_key	/* old, negative, number */
    blocknr_T nt_new_bnum;
};
struct block_hdr {
    mf_hashitem_T bh_hashitem;

    #define bh_bnum bh_hashitem.mhi_key /* block number, part of bh_hashitem */
    bhdr_T *bh_next;
    bhdr_T *bh_prev;
    char_u *bh_data;
    int bh_page_count;

    #define BH_DIRTY    1

    #define BH_LOCKED   2
    char bh_flags;
};
struct mf_hashitem_S {
    mf_hashitem_T *mhi_next;
    mf_hashitem_T *mhi_prev;
    blocknr_T mhi_key;
};
struct m_info {
    short_u m_size;
    minfo_T *m_next;
};
struct u_header {
    union {
        u_header_T *ptr;
        long  seq;
    } uh_next;
    union {
        u_header_T *ptr;
        long  seq;
    } uh_prev;
    union {
        u_header_T *ptr;
        long  seq;
    } uh_alt_next;
    union {
        u_header_T *ptr;
        long  seq;
    } uh_alt_prev;
    long  uh_seq;
    int uh_walk;
    u_entry_T *uh_entry;
    u_entry_T *uh_getbot_entry;
    pos_T uh_cursor;
    long  uh_cursor_vcol;
    int uh_flags;
    pos_T uh_namedm [NMARKS];
    visualinfo_T uh_visual;
    time_T uh_time;
    long  uh_save_nr;
};
struct u_entry {
    u_entry_T *ue_next;
    linenr_T ue_top;
    linenr_T ue_bot;
    linenr_T ue_lcount;
    char_u **ue_array;
    long  ue_size;
};
struct foldinfo {
    int fi_level;
    int fi_lnum;
    int fi_low_level;
};
struct wininfo_S {
    wininfo_T *wi_next;
    wininfo_T *wi_prev;
    win_T *wi_win;
    pos_T wi_fpos;
    int wi_optset;
    winopt_T wi_opt;
    int wi_fold_manual;
    garray_T wi_folds;
};
struct filemark {
    pos_T mark;
    int fnum;
};
struct regstar_S {
    int nextb;
    int nextb_ic;
    long  count;
    long  minval;
    long  maxval;
};
struct regitem_S {
    regstate_T rs_state;
    char_u *rs_scan;
    union {
        save_se_T sesave;
        regsave_T regsave;
    } rs_un;
    short  rs_no;
};
struct regbehind_S {
    regsave_T save_after;
    regsave_T save_behind;
    int save_need_clear_subexpr;
    save_se_T save_start [NSUBEXP];
    save_se_T save_end [NSUBEXP];
};
struct attr_entry {
    short  ae_attr;
    union {
        struct {
            char_u *start;
            char_u *stop;
        } term;
        struct {
            short_u fg_color;
            short_u bg_color;
            guicolor_T fg_rgb;
            guicolor_T bg_rgb;
        } cterm;
        struct {
            guicolor_T fg_color;
            guicolor_T bg_color;
            guicolor_T sp_color;
            GuiFont font;
        } gui;
    } ae_u;
};
struct buffheader {
    buffblock_T bh_first;
    buffblock_T *bh_curr;
    int bh_index;
    int bh_space;
};
struct buffblock {
    buffblock_T *b_next;
    char_u b_str [1];
};
struct msglist {
    char_u *msg;
    char_u *throw_msg;
    struct msglist *next;
};
struct stl_hlrec {
    char_u *start;
    int userhl;
};
struct regprog {
    regengine_T *engine;
    unsigned  regflags;
    unsigned  re_engine;
    unsigned  re_flags;
};
struct hashtable_S {
    long_u ht_mask;
    long_u ht_used;
    long_u ht_filled;
    int ht_locked;
    int ht_error;
    hashitem_T *ht_array;
    hashitem_T ht_smallarray [HT_INIT_SIZE];
};
struct mf_hashtab_S {
    long_u mht_mask;
    long_u mht_count;
    mf_hashitem_T **mht_buckets;
    mf_hashitem_T *mht_small_buckets [MHT_INIT_SIZE];
    char mht_fixed;
};
struct nfa_state {
    int c;
    nfa_state_T *out;
    nfa_state_T *out1;
    int id;
    int lastlist [2];
    int val;
};
struct syn_state {
    synstate_T *sst_next;
    linenr_T sst_lnum;
    union {
        bufstate_T sst_stack [SST_FIX_STATES];
        garray_T sst_ga;
    } sst_union;
    int sst_next_flags;
    int sst_stacksize;
    short  *sst_next_list;
    disptick_T sst_tick;
    linenr_T sst_change_lnum;
};
struct buf_state {
    int bs_idx;
    int bs_flags;
    int bs_seqnr;
    int bs_cchar;
    reg_extmatch_T *bs_extmatch;
};
struct regengine {
    regprog_T * (*regcomp) (char_u *, int);
    void (*regfree) (regprog_T *);
    int (*regexec_nl) (regmatch_T *, char_u *, colnr_T, int);
    long  (*regexec_multi) (regmmatch_T *, win_T *, buf_T *, linenr_T, colnr_T, proftime_T *, int *);
    char_u *expr;
};
struct tabpage_S {
    tabpage_T *tp_next;
    frame_T *tp_topframe;
    win_T *tp_curwin;
    win_T *tp_prevwin;
    win_T *tp_firstwin;
    win_T *tp_lastwin;
    long  tp_old_Rows;
    long  tp_old_Columns;
    long  tp_ch_used;
    int tp_prev_which_scrollbars [3];
    diff_T *tp_first_diff;
    buf_T * (tp_diffbuf [DB_COUNT]);
    int tp_diff_invalid;
    frame_T * (tp_snapshot [SNAP_COUNT]);
    dictitem_T tp_winvar;
    dict_T *tp_vars;
};
struct vim_exception {
    except_type_T type;
    char_u *value;
    struct msglist *messages;
    char_u *throw_name;
    linenr_T throw_lnum;
    except_T *caught;
};
struct matchitem {
    matchitem_T *next;
    int id;
    int priority;
    char_u *pattern;
    int hlg_id;
    regmmatch_T match;
    posmatch_T pos;
    match_T hl;
    int conceal_char;
};
struct w_line {
    linenr_T wl_lnum;
    short_u wl_size;
    char wl_valid;
    char wl_folded;
    linenr_T wl_lastlnum;
};
struct dictitem_S {
    typval_T di_tv;
    char_u di_flags;
    char_u di_key [1];
};
struct dictvar_S {
    char dv_lock;
    char dv_scope;
    int dv_refcount;
    int dv_copyID;
    hashtab_T dv_hashtab;
    dict_T *dv_copydict;
    dict_T *dv_used_next;
    dict_T *dv_used_prev;
};
struct arglist {
    garray_T al_ga;
    int al_refcount;
    int id;
};
struct taggy {
    char_u *tagname;
    fmark_T fmark;
    int cur_match;
    int cur_fnum;
};
struct xfilemark {
    fmark_T fmark;
    char_u *fname;
    time_T time_set;
};
struct file_buffer {
    memline_T b_ml;
    buf_T *b_next;
    buf_T *b_prev;
    int b_nwindows;
    int b_flags;
    int b_locked;
    char_u *b_ffname;
    char_u *b_sfname;
    char_u *b_fname;
    int b_dev_valid;
    dev_t b_dev;
    ino_t b_ino;
    int b_fnum;
    char_u b_key [VIM_SIZEOF_INT * 2 + 1];
    int b_changed;
    dictitem16_T b_ct_di;

    #define CHANGEDTICK(buf) ((buf)->b_ct_di.di_tv.vval.v_number)
    varnumber_T b_last_changedtick;
    varnumber_T b_last_changedtick_pum;
    int b_saving;
    int b_mod_set;
    linenr_T b_mod_top;
    linenr_T b_mod_bot;
    long  b_mod_xlines;
    wininfo_T *b_wininfo;
    long  b_mtime;
    long  b_mtime_read;
    off_T b_orig_size;
    int b_orig_mode;
    time_T b_last_used;
    pos_T b_namedm [NMARKS];
    visualinfo_T b_visual;
    int b_visual_mode_eval;
    pos_T b_last_cursor;
    pos_T b_last_insert;
    pos_T b_last_change;
    pos_T b_changelist [JUMPLISTSIZE];
    int b_changelistlen;
    int b_new_change;
    char_u b_chartab [32];
    mapblock_T * (b_maphash [256]);
    mapblock_T *b_first_abbr;
    garray_T b_ucmds;
    pos_T b_op_start;
    pos_T b_op_start_orig;
    pos_T b_op_end;
    int b_marks_read;
    u_header_T *b_u_oldhead;
    u_header_T *b_u_newhead;
    u_header_T *b_u_curhead;
    int b_u_numhead;
    int b_u_synced;
    long  b_u_seq_last;
    long  b_u_save_nr_last;
    long  b_u_seq_cur;
    time_T b_u_time_cur;
    long  b_u_save_nr_cur;
    char_u *b_u_line_ptr;
    linenr_T b_u_line_lnum;
    colnr_T b_u_line_colnr;
    int b_scanned;
    long  b_p_iminsert;
    long  b_p_imsearch;

    #define B_IMODE_USE_INSERT -1	/*	Use b_p_iminsert value for search */

    #define B_IMODE_NONE 0		/*	Input via none */

    #define B_IMODE_LMAP 1		/*	Input via langmap */

    #define B_IMODE_IM 2		/*	Input via input method */

    #define B_IMODE_LAST 2
    short  b_kmap_state;

    # define KEYMAP_INIT	1	/* 'keymap' was set, call keymap_init() */

    # define KEYMAP_LOADED	2	/* 'keymap' mappings have been loaded */
    garray_T b_kmap_ga;
    int b_p_initialized;
    int b_p_scriptID [BV_COUNT];
    int b_p_ai;
    int b_p_ai_nopaste;
    char_u *b_p_bkc;
    unsigned  b_bkc_flags;
    int b_p_ci;
    int b_p_bin;
    char_u *b_p_bh;
    char_u *b_p_bt;

    #define BUF_HAS_QF_ENTRY 1

    #define BUF_HAS_LL_ENTRY 2
    int b_has_qf_entry;
    int b_p_bl;
    int b_p_cin;
    char_u *b_p_cino;
    char_u *b_p_cink;
    char_u *b_p_cinw;
    char_u *b_p_com;
    char_u *b_p_cms;
    char_u *b_p_cpt;
    int b_p_eol;
    int b_p_fixeol;
    int b_p_et;
    int b_p_et_nobin;
    int b_p_et_nopaste;
    char_u *b_p_ff;
    char_u *b_p_ft;
    char_u *b_p_fo;
    char_u *b_p_flp;
    int b_p_inf;
    char_u *b_p_isk;
    char_u *b_p_def;
    char_u *b_p_inc;
    char_u *b_p_inex;
    long_u b_p_inex_flags;
    char_u *b_p_inde;
    long_u b_p_inde_flags;
    char_u *b_p_indk;
    char_u *b_p_fp;
    char_u *b_p_fex;
    long_u b_p_fex_flags;
    char_u *b_p_key;
    char_u *b_p_kp;
    int b_p_lisp;
    char_u *b_p_mps;
    int b_p_ml;
    int b_p_ml_nobin;
    int b_p_ma;
    char_u *b_p_nf;
    int b_p_pi;
    char_u *b_p_qe;
    int b_p_ro;
    long  b_p_sw;
    int b_p_sn;
    int b_p_si;
    long  b_p_sts;
    long  b_p_sts_nopaste;
    char_u *b_p_sua;
    int b_p_swf;
    long  b_p_smc;
    char_u *b_p_syn;
    long  b_p_ts;
    int b_p_tx;
    long  b_p_tw;
    long  b_p_tw_nobin;
    long  b_p_tw_nopaste;
    long  b_p_wm;
    long  b_p_wm_nobin;
    long  b_p_wm_nopaste;
    char_u *b_p_keymap;
    char_u *b_p_gp;
    char_u *b_p_mp;
    char_u *b_p_efm;
    char_u *b_p_ep;
    char_u *b_p_path;
    int b_p_ar;
    char_u *b_p_tags;
    char_u *b_p_tc;
    unsigned  b_tc_flags;
    char_u *b_p_dict;
    char_u *b_p_tsr;
    long  b_p_ul;
    int b_p_udf;
    int b_p_mmta;
    char_u *b_p_lw;
    int b_ind_level;
    int b_ind_open_imag;
    int b_ind_no_brace;
    int b_ind_first_open;
    int b_ind_open_extra;
    int b_ind_close_extra;
    int b_ind_open_left_imag;
    int b_ind_jump_label;
    int b_ind_case;
    int b_ind_case_code;
    int b_ind_case_break;
    int b_ind_param;
    int b_ind_func_type;
    int b_ind_comment;
    int b_ind_in_comment;
    int b_ind_in_comment2;
    int b_ind_cpp_baseclass;
    int b_ind_continuation;
    int b_ind_unclosed;
    int b_ind_unclosed2;
    int b_ind_unclosed_noignore;
    int b_ind_unclosed_wrapped;
    int b_ind_unclosed_whiteok;
    int b_ind_matching_paren;
    int b_ind_paren_prev;
    int b_ind_maxparen;
    int b_ind_maxcomment;
    int b_ind_scopedecl;
    int b_ind_scopedecl_code;
    int b_ind_java;
    int b_ind_js;
    int b_ind_keep_case_label;
    int b_ind_hash_comment;
    int b_ind_cpp_namespace;
    int b_ind_if_for_while;
    int b_ind_cpp_extern_c;
    linenr_T b_no_eol_lnum;
    int b_start_eol;
    int b_start_ffc;
    dictitem_T b_bufvar;
    dict_T *b_vars;
    char_u *b_p_bexpr;
    long_u b_p_bexpr_flags;
    char_u *b_p_cm;
    int b_may_swap;
    int b_did_warn;
    int b_help;
    int b_shortname;
    synblock_T b_s;
    signlist_T *b_signlist;
    int b_has_sign_column;
    int b_netbeans_file;
    int b_was_netbeans_file;
    int b_write_to_channel;
    cryptstate_T *b_cryptstate;
    int b_mapped_ctrl_c;
    term_T *b_term;
};
struct frame_S {
    char fr_layout;
    int fr_width;
    int fr_newwidth;
    int fr_height;
    int fr_newheight;
    frame_T *fr_parent;
    frame_T *fr_next;
    frame_T *fr_prev;
    frame_T *fr_child;
    win_T *fr_win;
};
struct ml_chunksize {
    int mlcs_numlines;
    long  mlcs_totalsize;
};
struct growarray {
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    int ga_growsize;
    void *ga_data;
};
struct info_pointer {
    blocknr_T ip_bnum;
    linenr_T ip_low;
    linenr_T ip_high;
    int ip_index;
};
struct window_S {
    int w_id;
    buf_T *w_buffer;
    synblock_T *w_s;
    win_T *w_prev;
    win_T *w_next;
    int w_closing;
    frame_T *w_frame;
    pos_T w_cursor;
    colnr_T w_curswant;
    int w_set_curswant;
    char w_old_visual_mode;
    linenr_T w_old_cursor_lnum;
    colnr_T w_old_cursor_fcol;
    colnr_T w_old_cursor_lcol;
    linenr_T w_old_visual_lnum;
    colnr_T w_old_visual_col;
    colnr_T w_old_curswant;
    linenr_T w_topline;
    char w_topline_was_set;
    int w_topfill;
    int w_old_topfill;
    int w_botfill;
    int w_old_botfill;
    colnr_T w_leftcol;
    colnr_T w_skipcol;
    int w_winrow;
    int w_height;
    int w_status_height;
    int w_wincol;
    int w_width;
    int w_vsep_width;
    int w_valid;
    pos_T w_valid_cursor;
    colnr_T w_valid_leftcol;
    int w_cline_height;
    int w_cline_folded;
    int w_cline_row;
    colnr_T w_virtcol;
    int w_wrow, w_wcol;
    linenr_T w_botline;
    int w_empty_rows;
    int w_filler_rows;
    int w_lines_valid;
    wline_T *w_lines;
    garray_T w_folds;
    char w_fold_manual;
    char w_foldinvalid;
    int w_nrwidth;
    int w_redr_type;
    int w_upd_rows;
    linenr_T w_redraw_top;
    linenr_T w_redraw_bot;
    int w_redr_status;
    pos_T w_ru_cursor;
    colnr_T w_ru_virtcol;
    linenr_T w_ru_topline;
    linenr_T w_ru_line_count;
    int w_ru_topfill;
    char w_ru_empty;
    int w_alt_fnum;
    alist_T *w_alist;
    int w_arg_idx;
    int w_arg_idx_invalid;
    char_u *w_localdir;
    vimmenu_T *w_winbar;
    winbar_item_T *w_winbar_items;
    int w_winbar_height;
    winopt_T w_onebuf_opt;
    winopt_T w_allbuf_opt;
    long_u w_p_stl_flags;
    long_u w_p_fde_flags;
    long_u w_p_fdt_flags;
    int *w_p_cc_cols;
    int w_p_brimin;
    int w_p_brishift;
    int w_p_brisbr;

    #define GLOBAL_WO(p)	((char *)p + sizeof(winopt_T))
    long  w_scbind_pos;
    dictitem_T w_winvar;
    dict_T *w_vars;
    int w_farsi;
    pos_T w_pcmark;
    pos_T w_prev_pcmark;
    xfmark_T w_jumplist [JUMPLISTSIZE];
    int w_jumplistlen;
    int w_jumplistidx;
    int w_changelistidx;
    matchitem_T *w_match_head;
    int w_next_match_id;
    taggy_T w_tagstack [TAGSTACKSIZE];
    int w_tagstackidx;
    int w_tagstacklen;
    int w_fraction;
    int w_prev_fraction_row;
    scrollbar_T w_scrollbars [2];
    linenr_T w_nrwidth_line_count;
    long  w_nuw_cached;
    int w_nrwidth_width;
    qf_info_T *w_llist;
    qf_info_T *w_llist_ref;
};
struct posmatch {
    llpos_T pos [MAXPOSMATCH];
    int cur;
    linenr_T toplnum;
    linenr_T botlnum;
};
struct backpos_S {
    char_u *bp_scan;
    regsave_T bp_pos;
};
struct signlist {
    int id;
    linenr_T lnum;
    int typenr;
    signlist_T *next;
    signlist_T *prev;
};
char_u *reg_tofree = NULL;
EXTERN char_u *p_sel;
EXTERN char_u e_re_damg [] INIT (= N_ ("E43: Damaged match string"));
regsubmatch_T rsm;
EXTERN char_u e_null [] INIT (= N_ ("E38: Null argument"));
char_u e_reverse_range [] = N_ ("E944: Reverse range in character class");
EXTERN char_u e_toomsbra [] INIT (= N_ ("E76: Too many ["));
char_u e_missing_sb [] = N_ ("E69: Missing ] after %s%%[");
char_u e_z1_not_allowed [] = N_ ("E67: \\z1 et al. not allowed here");
int re_has_z;
char_u e_z_not_allowed [] = N_ ("E66: \\z( not allowed here");
EXTERN char_u e_internal [] INIT (= N_ ("E473: Internal error"));
int had_eol;
EXTERN char_u e_trailing [] INIT (= N_ ("E488: Trailing characters"));
int reg_toolong;
int regnzpar;
char_u REGEXP_ABBR [] = "nrtebdoxuU";
char_u REGEXP_INRANGE [] = "]^-n\\";
EXTERN long  p_re;
EXTERN long  p_mmp;
char_u *regline;
regexec_T rex;
char_u *reginput;
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
EXTERN char_u *p_titlestring;
int reg_string;
EXTERN int arrow_used;
EXTERN int mouse_row;
int rex_in_use = FALSE;
EXTERN char_u *globaldir INIT (= NULL);
EXTERN char_u e_toomanyarg [] INIT (= N_ ("E118: Too many arguments for function: %s"));
EXTERN char_u e_argreq [] INIT (= N_ ("E471: Argument required"));
EXTERN char_u e_shellempty [] INIT (= N_ ("E91: 'shell' option is empty"));
EXTERN char_u e_emptykey [] INIT (= N_ ("E713: Cannot use empty key for Dictionary"));
EXTERN char_u e_endfor [] INIT (= N_ ("E170: Missing :endfor"));
EXTERN char_u e_endwhile [] INIT (= N_ ("E170: Missing :endwhile"));
EXTERN char_u e_endtry [] INIT (= N_ ("E600: Missing :endtry"));
EXTERN char_u e_endif [] INIT (= N_ ("E171: Missing :endif"));
EXTERN char_u *empty_option INIT (= (char_u *) "");
char_u *reg_endzp [NSUBEXP];
char_u e_empty_sb [] = N_ ("E70: Empty %s%%[]");
EXTERN char_u e_listreq [] INIT (= N_ ("E714: List required"));
EXTERN alist_T global_alist;
EXTERN char_u e_readonlyvar [] INIT (= N_ ("E46: Cannot change read-only variable \"%s\""));
EXTERN char_u e_noroom [] INIT (= N_ ("E36: Not enough room"));
EXTERN char_u e_invarg2 [] INIT (= N_ ("E475: Invalid argument: %s"));
EXTERN char_u e_invarg [] INIT (= N_ ("E474: Invalid argument"));
EXTERN char_u wim_flags [4];
EXTERN char breakat_flags [256];
EXTERN unsigned  ve_flags;
EXTERN unsigned  vop_flags;
EXTERN unsigned  ttym_flags;
EXTERN unsigned  tbis_flags;
EXTERN unsigned  toolbar_flags;
EXTERN unsigned  ssop_flags;
EXTERN unsigned  fuoptions_flags;
EXTERN unsigned  fdo_flags;
EXTERN unsigned  dy_flags;
EXTERN unsigned  bo_flags;
char_u META_flags [] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1};
EXTERN win_T *au_pending_free_win INIT (= NULL);
EXTERN tabpage_T *first_tabpage;
EXTERN char_u e_umark [] INIT (= N_ ("E78: Unknown mark"));
EXTERN char_u e_marknotset [] INIT (= N_ ("E20: Mark not set"));
EXTERN char *font_argument INIT (= NULL);
EXTERN int p_guipty;
EXTERN char_u *p_guifont;
EXTERN char need_key_msg [] INIT (= N_ ("Need encryption key for \"%s\""));
EXTERN char_u no_lines_msg [] INIT (= N_ ("--No lines in buffer--"));
EXTERN struct msglist **msg_list INIT (= NULL);
EXTERN char_u *keep_msg INIT (= NULL);
EXTERN int msg_row;
EXTERN char_u e_invalpat [] INIT (= N_ ("E682: Invalid search pattern or delimiter"));
EXTERN char_u e_toocompl [] INIT (= N_ ("E74: Command too complex"));
EXTERN char_u e_tagstack [] INIT (= N_ ("E73: tag stack empty"));
EXTERN char_u e_swapclose [] INIT (= N_ ("E72: Close error on swap file"));
EXTERN char_u e_scroll [] INIT (= N_ ("E49: Invalid scroll size"));
EXTERN char_u e_screenmode [] INIT (= N_ ("E359: Screen mode setting not supported"));
EXTERN char_u e_listdictarg [] INIT (= N_ ("E712: Argument of %s must be a List or Dictionary"));
EXTERN char_u e_dictkey [] INIT (= N_ ("E716: Key not present in Dictionary: %s"));
EXTERN char_u e_dictreq [] INIT (= N_ ("E715: Dictionary required"));
EXTERN char_u e_re_corr [] INIT (= N_ ("E44: Corrupted regexp program"));
EXTERN char_u e_loclist [] INIT (= N_ ("E776: No location list"));
EXTERN char_u e_quickfix [] INIT (= N_ ("E42: No Errors"));
EXTERN char_u e_outofmem [] INIT (= N_ ("E41: Out of memory!"));
EXTERN char_u e_notcreate [] INIT (= N_ ("E482: Can't create file %s"));
EXTERN char_u e_nolastcmd [] INIT (= N_ ("E30: No previous command line"));
EXTERN char_u e_markinval [] INIT (= N_ ("E19: Mark has invalid line number"));
EXTERN char_u e_invcmd [] INIT (= N_ ("E476: Invalid command"));
EXTERN char_u e_invargNval [] INIT (= N_ ("E475: Invalid value for argument %s: %s"));
EXTERN char_u e_invargval [] INIT (= N_ ("E475: Invalid value for argument %s"));
EXTERN char_u e_backslash [] INIT (= N_ ("E10: \\ should be followed by /, ? or &"));
EXTERN char_u langmap_mapchar [256];
EXTERN char_u *escape_chars INIT (= (char_u *) " \t\\\"|");
EXTERN char_u *repeat_cmdline INIT (= NULL);
EXTERN char_u *last_cmdline INIT (= NULL);
EXTERN FILE *scriptout INIT (= NULL);
EXTERN FILE *scriptin [NSCRIPT];
EXTERN cmdmod_T cmdmod;
EXTERN win_T *aucmd_win;
EXTERN char_u *use_gvimrc INIT (= NULL);
EXTERN char_u *sourcing_name INIT (= NULL);
EXTERN int called_emsg;
EXTERN int called_vim_beep;
EXTERN dict_T globvardict;
EXTERN dict_T vimvardict;
EXTERN int msg_scrolled;
EXTERN int cmdline_row;
EXTERN sattr_T *ScreenAttrs INIT (= NULL);
EXTERN schar_T *ScreenLines INIT (= NULL);
EXTERN long  p_wic;
EXTERN long  p_wcm;
EXTERN long  p_wc;
EXTERN char_u *p_fcs;
EXTERN long  p_uc;
EXTERN long  p_ttyscroll;
EXTERN int p_ttimeout;
EXTERN int p_timeout;
EXTERN int p_tgc;
EXTERN unsigned  tc_flags;
EXTERN char_u *p_tc;
EXTERN int p_scs;
EXTERN int p_sc;
EXTERN char_u *p_shcf;
EXTERN char_u *p_sections;
EXTERN char_u *p_cdpath;
EXTERN char_u *p_opfunc;
EXTERN char_u *p_cc;
EXTERN char_u *p_scl;
EXTERN int p_magic;
EXTERN int p_macthinstrokes;
EXTERN int p_macligatures;
EXTERN char_u *p_lcs;
EXTERN long  p_linespace;
EXTERN int p_ic;
EXTERN char_u *p_iconstring;
EXTERN int p_icon;
EXTERN char_u *p_penc;
EXTERN int p_fullscreen;
EXTERN char_u *p_fcl;
EXTERN long  p_fic;
EXTERN int p_exrc;
EXTERN char_u *p_dict;
EXTERN char_u *p_cpo;
EXTERN char_u *p_cot;
EXTERN int p_cp;
EXTERN long  p_ch;
EXTERN unsigned  bkc_flags;
EXTERN char_u *p_bkc;
EXTERN int p_acd;
long  bl_minval;
garray_T regstack = {0, 0, 0, 0, NULL};
int classcodes [] = {ANY, IDENT, SIDENT, KWORD, SKWORD, FNAME, SFNAME, PRINT, SPRINT, WHITE, NWHITE, DIGIT, NDIGIT, HEX, NHEX, OCTAL, NOCTAL, WORD, NWORD, HEAD, NHEAD, ALPHA, NALPHA, LOWER, NLOWER, UPPER, NUPPER};
char_u *classchars = (char_u *) ".iIkKfFpPsSdDxXoOwWhHaAlLuU";
int reg_cpo_bsl;
int reg_cpo_lit;
int reg_strict;
int reg_magic;
int one_exactly = FALSE;
long  brace_min [10];
char_u had_endbrace [NSUBEXP];
char_u *regcode;
int num_complex_braces;
short  class_tab [256];
char_u e_missingbracket [] = N_ ("E769: Missing ] after %s[");
int regnpar;
char_u *regparse;
EXTERN proftime_T bevalexpr_due;
EXTERN char_u e_invexpr2 [] INIT (= N_ ("E15: Invalid expression: %s"));
EXTERN char_u *p_pexpr;
EXTERN char_u *p_bexpr;
int need_clear_zsubexpr = FALSE;
int need_clear_subexpr;
EXTERN char_u e_bufloaded [] INIT (= N_ ("E139: File is loaded in another buffer"));
EXTERN char_u e_nobufnr [] INIT (= N_ ("E86: Buffer %ld does not exist"));
EXTERN char_u e_emptybuf [] INIT (= N_ ("E749: empty buffer"));
EXTERN char_u e_invexprmsg [] INIT (= N_ ("E449: Invalid expression received"));
EXTERN char_u e_notmp [] INIT (= N_ ("E483: Can't get temp file name"));
EXTERN char_u msg_buf [MSG_BUF_LEN];
EXTERN char_u *IObuff;
EXTERN buf_T *lastbuf INIT (= NULL);
EXTERN buf_T *firstbuf INIT (= NULL);
EXTERN buf_T *au_pending_free_buf INIT (= NULL);
EXTERN long  p_ttm;
EXTERN long  p_tm;
EXTERN int p_stmp;
EXTERN int p_lrm;
EXTERN int p_confirm;
EXTERN int p_bevalterm;
EXTERN except_T *caught_stack INIT (= NULL);
EXTERN hlf_T edit_submode_highl;
EXTERN int highlight_attr [HLF_COUNT];
EXTERN int p_hls;
EXTERN char_u *p_hl;
EXTERN char_u *p_hlg;
EXTERN int autocmd_fname_full;
EXTERN char_u *autocmd_fname INIT (= NULL);
EXTERN unsigned  swb_flags;
EXTERN time_T starttime;
EXTERN pos_T where_paste_started;
char_u *reg_startzp [NSUBEXP];
int at_start;
int regexp_engine = 0;
regengine_T nfa_regengine = {nfa_regcomp, nfa_regfree, nfa_regexec_nl, nfa_regexec_multi, (char_u *) ""};
regengine_T bt_regengine = {bt_regcomp, bt_regfree, bt_regexec_nl, bt_regexec_multi, (char_u *) ""};
regengine_T nfa_regengine;
regengine_T bt_regengine;
unsigned  regflags;
const int command_count = 546;
EXTERN char_u e_zerocount [] INIT (= N_ ("E939: Positive count required"));
EXTERN char_u e_nomatch2 [] INIT (= N_ ("E480: No match: %s"));
EXTERN char_u e_nomatch [] INIT (= N_ ("E479: No match"));
EXTERN char_u *autocmd_match INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_out INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_in INIT (= NULL);
EXTERN linenr_T search_match_lines;
int can_f_submatch = FALSE;
int brace_count [10];
char_u e_unmatchedpar [] = N_ ("E55: Unmatched %s)");
char_u e_unmatchedp [] = N_ ("E54: Unmatched %s(");
char_u e_unmatchedpp [] = N_ ("E53: Unmatched %s%%(");
EXTERN char bot_top_msg [] INIT (= N_ ("search hit BOTTOM, continuing at TOP"));
EXTERN char top_bot_msg [] INIT (= N_ ("search hit TOP, continuing at BOTTOM"));
EXTERN char_u e_maxmempat [] INIT (= N_ ("E363: pattern uses more memory than 'maxmempattern'"));
EXTERN char_u e_winheight [] INIT (= N_ ("E591: 'winheight' cannot be smaller than 'winminheight'"));
EXTERN char_u e_notopen [] INIT (= N_ ("E484: Can't open file %s"));
EXTERN int stop_insert_mode;
EXTERN typebuf_T typebuf;
EXTERN frame_T *topframe;
EXTERN long_u scrollbar_value;
long  bl_maxval;
long  brace_max [10];
long  regsize;
EXTERN char_u e_au_recursive [] INIT (= N_ ("E952: Autocommand caused recursive behavior"));
EXTERN char_u e_secure [] INIT (= N_ ("E523: Not allowed here"));
EXTERN char_u e_curdir [] INIT (= N_ ("E12: Command not allowed from exrc/vimrc in current dir or tag search"));
EXTERN pos_T last_cursormoved;
EXTERN pos_T saved_cursor;
EXTERN buf_T *curbuf INIT (= NULL);
EXTERN tabpage_T *curtab;
EXTERN win_T *curwin;
EXTERN int current_scrollbar;
EXTERN vimmenu_T *current_menu;
EXTERN except_T *current_exception;
EXTERN int p_secure;
int curchr;
EXTERN int *eval_lavars_used INIT (= NULL);
EXTERN char_u e_positive [] INIT (= N_ ("E487: Argument must be positive"));
lpos_T reg_endzpos [NSUBEXP];
lpos_T reg_startzpos [NSUBEXP];
regsave_T behind_pos;
garray_T backpos = {0, 0, 0, 0, NULL};
const unsigned  char cmdidxs2 [26] [26] = {{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 6, 0, 0, 0, 7, 15, 0, 16, 0, 0, 0, 0, 0}, {2, 0, 0, 4, 5, 7, 0, 0, 0, 0, 0, 8, 9, 10, 11, 12, 0, 13, 0, 0, 0, 0, 22, 0, 0, 0}, {3, 10, 12, 14, 16, 18, 21, 0, 0, 0, 0, 29, 33, 36, 42, 51, 53, 54, 55, 0, 57, 0, 60, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 6, 15, 0, 16, 0, 0, 17, 0, 0, 19, 20, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 7, 9, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 4, 5, 0, 0, 0, 0}, {5, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 3, 0, 0, 0, 4, 0, 5, 6, 0, 0, 0, 0, 0, 13, 0, 15, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {3, 9, 11, 15, 16, 20, 23, 28, 0, 0, 0, 30, 33, 36, 40, 46, 0, 48, 57, 49, 50, 54, 56, 0, 0, 0}, {1, 0, 0, 0, 9, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 8, 10, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 5, 0, 0, 0, 0, 0, 0, 9, 0, 11, 0, 0, 0}, {1, 0, 3, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 9, 0, 0, 16, 17, 26, 0, 27, 0, 28, 0}, {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 18, 0, 0, 0, 0}, {2, 6, 15, 0, 18, 22, 0, 24, 25, 0, 0, 28, 30, 34, 38, 40, 0, 48, 0, 49, 0, 61, 62, 0, 63, 0}, {2, 0, 19, 0, 22, 24, 0, 25, 0, 26, 0, 27, 28, 31, 33, 34, 0, 35, 37, 0, 38, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 9, 12, 0, 0, 0, 0, 15, 0, 16, 0, 0, 0, 0, 0}, {2, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 0, 8, 0, 9, 10, 0, 12, 0, 13, 14, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
const unsigned  short  cmdidxs1 [26] = {0, 19, 42, 103, 125, 145, 161, 167, 176, 194, 196, 201, 259, 279, 299, 311, 350, 353, 372, 439, 479, 490, 508, 523, 532, 533};
EXTERN char_u e_invalidreg [] INIT (= N_ ("E850: Invalid register name"));
EXTERN char_u e_usingsid [] INIT (= N_ ("E81: Using <SID> not in a script context"));
EXTERN char_u e_winwidth [] INIT (= N_ ("E592: 'winwidth' cannot be smaller than 'winminwidth'"));
EXTERN char_u e_listidx [] INIT (= N_ ("E684: list index out of range: %ld"));
EXTERN char_u e_prev_dir [] INIT (= N_ ("E459: Cannot go back to previous directory"));
EXTERN char_u e_noprevre [] INIT (= N_ ("E35: No previous regular expression"));
EXTERN char_u e_noprev [] INIT (= N_ ("E34: No previous command"));
EXTERN int ru_wid;
EXTERN win_T *prevwin INIT (= NULL);
EXTERN int did_emsg_syntax;
EXTERN int did_uncaught_emsg;
EXTERN int did_emsg;
EXTERN int p_tbidi;
EXTERN int p_hid;
int prev_at_start;
int nextchr;
int prevprevchr;
int prevchr;
char_u *reg_prev_sub = NULL;
EXTERN int searchcmdlen;
EXTERN long  p_titlelen;
unsigned  reg_tofreelen;
int prevchr_len;
EXTERN int sc_col;
EXTERN int ru_col;
EXTERN int mouse_col;
EXTERN colnr_T search_match_endcol;
EXTERN int msg_col;
EXTERN int p_cc_cols [256];
EXTERN long  p_columnspace;
EXTERN int fuoptions_bgcolor;
linenr_T reglnum;
EXTERN pos_T Insstart_orig;
EXTERN pos_T Insstart;
EXTERN pos_T VIsual;
EXTERN char_u *p_cm;
EXTERN int p_beval;
EXTERN char_u *p_ead;
EXTERN char_u *p_dir;
EXTERN char_u *p_inc;
EXTERN char_u e_nopresub [] INIT (= N_ ("E33: No previous substitute regular expression"));

static int regmatch (char_u *scan, proftime_T *tm, int *timed_out) {
    char_u *next;
    int op;
    int c;
    regitem_T *rp;
    int no;
    int status;

    #define RA_FAIL		1	/* something failed, abort */

    #define RA_CONT		2	/* continue in inner loop */

    #define RA_BREAK	3	/* break inner loop */

    #define RA_MATCH	4	/* successful match */

    #define RA_NOMATCH	5	/* didn't match */
    int tm_count = 0;
    regstack.ga_len = 0;
    backpos.ga_len = 0;
    for (;;) {
        fast_breakcheck ();
        for (;;) {
            if (got_int || scan == NULL) {
                status = RA_FAIL;
                break;
            }
            if (tm != NULL && ++tm_count == 100) {
                tm_count = 0;
                if (profile_passed_limit (tm)) {
                    if (timed_out != NULL)
                        *timed_out = TRUE;
                    status = RA_FAIL;
                    break;
                }
            }
            status = RA_CONT;
            next = regnext (scan);
            op = OP (scan);
            if (!rex.reg_line_lbr && WITH_NL (op) && REG_MULTI && *reginput == NUL && reglnum <= rex.reg_maxline) {
                reg_nextline ();
            }
            else if (rex.reg_line_lbr && WITH_NL (op) && *reginput == '\n') {
                ADVANCE_REGINPUT ();
            }
            else {
                if (WITH_NL (op))
                    op -= ADD_NL;
                c = *reginput;
                switch (op) {
                case BOL :
                    if (reginput != regline)
                        status = RA_NOMATCH;
                    break;
                case EOL :
                    if (c != NUL)
                        status = RA_NOMATCH;
                    break;
                case RE_BOF :
                    if (reglnum != 0 || reginput != regline || (REG_MULTI && rex.reg_firstlnum > 1))
                        status = RA_NOMATCH;
                    break;
                case RE_EOF :
                    if (reglnum != rex.reg_maxline || c != NUL)
                        status = RA_NOMATCH;
                    break;
                case CURSOR :
                    if (rex.reg_win == NULL || (reglnum + rex.reg_firstlnum != rex.reg_win->w_cursor.lnum) || ((colnr_T) (reginput - regline) != rex.reg_win->w_cursor.col))
                        status = RA_NOMATCH;
                    break;
                case RE_MARK :
                    {
                        int mark = OPERAND (scan)[0];
                        int cmp = OPERAND (scan)[1];
                        pos_T *pos;
                        pos = getmark_buf (rex.reg_buf, mark, FALSE);
                        if (pos == NULL || pos->lnum <= 0 || (pos->lnum == reglnum + rex.reg_firstlnum ? (pos->col == (colnr_T) (reginput - regline) ? (cmp == '<' || cmp == '>') : (pos->col < (colnr_T) (reginput - regline) ? cmp != '>' : cmp != '<')) : (pos->lnum < reglnum + rex.reg_firstlnum ? cmp != '>' : cmp != '<')))
                            status = RA_NOMATCH;
                    }
                    break;
                case RE_VISUAL :
                    if (!reg_match_visual ())
                        status = RA_NOMATCH;
                    break;
                case RE_LNUM :
                    if (!REG_MULTI || !re_num_cmp ((long_u) (reglnum + rex.reg_firstlnum), scan))
                        status = RA_NOMATCH;
                    break;
                case RE_COL :
                    if (!re_num_cmp ((long_u) (reginput - regline) + 1, scan))
                        status = RA_NOMATCH;
                    break;
                case RE_VCOL :
                    if (!re_num_cmp ((long_u) win_linetabsize (rex.reg_win == NULL ? curwin : rex.reg_win, regline, (colnr_T) (reginput - regline)) + 1, scan))
                        status = RA_NOMATCH;
                    break;
                case BOW :
                    if (c == NUL)
                        status = RA_NOMATCH;
                    else {
                        if (!vim_iswordc_buf (c, rex.reg_buf) || (reginput > regline && vim_iswordc_buf (reginput[-1], rex.reg_buf)))
                            status = RA_NOMATCH;
                    }
                    break;
                case EOW :
                    if (reginput == regline)
                        status = RA_NOMATCH;
                    else {
                        if (!vim_iswordc_buf (reginput[-1], rex.reg_buf) || (reginput[0] != NUL && vim_iswordc_buf (c, rex.reg_buf)))
                            status = RA_NOMATCH;
                    }
                    break;
                case ANY :
                    if (c == NUL)
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case IDENT :
                    if (!vim_isIDc (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case SIDENT :
                    if (VIM_ISDIGIT (*reginput) || !vim_isIDc (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case KWORD :
                    if (!vim_iswordp_buf (reginput, rex.reg_buf))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case SKWORD :
                    if (VIM_ISDIGIT (*reginput) || !vim_iswordp_buf (reginput, rex.reg_buf))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case FNAME :
                    if (!vim_isfilec (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case SFNAME :
                    if (VIM_ISDIGIT (*reginput) || !vim_isfilec (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case PRINT :
                    if (!vim_isprintc (PTR2CHAR (reginput)))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case SPRINT :
                    if (VIM_ISDIGIT (*reginput) || !vim_isprintc (PTR2CHAR (reginput)))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case WHITE :
                    if (!VIM_ISWHITE (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case NWHITE :
                    if (c == NUL || VIM_ISWHITE (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case DIGIT :
                    if (!ri_digit (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case NDIGIT :
                    if (c == NUL || ri_digit (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case HEX :
                    if (!ri_hex (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case NHEX :
                    if (c == NUL || ri_hex (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case OCTAL :
                    if (!ri_octal (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case NOCTAL :
                    if (c == NUL || ri_octal (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case WORD :
                    if (!ri_word (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case NWORD :
                    if (c == NUL || ri_word (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case HEAD :
                    if (!ri_head (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case NHEAD :
                    if (c == NUL || ri_head (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case ALPHA :
                    if (!ri_alpha (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case NALPHA :
                    if (c == NUL || ri_alpha (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case LOWER :
                    if (!ri_lower (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case NLOWER :
                    if (c == NUL || ri_lower (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case UPPER :
                    if (!ri_upper (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case NUPPER :
                    if (c == NUL || ri_upper (c))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case EXACTLY :
                    {
                        int len;
                        char_u *opnd;
                        opnd = OPERAND (scan);
                        if (*opnd != *reginput && (!rex.reg_ic || (MB_TOLOWER (*opnd) != MB_TOLOWER (*reginput))))
                            status = RA_NOMATCH;
                        else if (*opnd == NUL) {
                        }
                        else {
                            if (opnd[1] == NUL) {
                                len = 1;
                            }
                            else {
                                len = (int) STRLEN (opnd);
                                if (cstrncmp (opnd, reginput, &len) != 0)
                                    status = RA_NOMATCH;
                            }
                            if (status != RA_NOMATCH)
                                reginput += len;
                        }
                    }
                    break;
                case ANYOF :
                case ANYBUT :
                    if (c == NUL)
                        status = RA_NOMATCH;
                    else if ((cstrchr (OPERAND (scan), c) == NULL) == (op == ANYOF))
                        status = RA_NOMATCH;
                    else
                        ADVANCE_REGINPUT ();
                    break;
                case RE_COMPOSING :
                    break;
                case NOTHING :
                    break;
                case BACK :
                    {
                        int i;
                        backpos_T *bp;
                        bp = (backpos_T *) backpos.ga_data;
                        for (i = 0; i < backpos.ga_len; ++i)
                            if (bp[i].bp_scan == scan)
                                break;
                        if (i == backpos.ga_len) {
                            if (ga_grow (&backpos, 1) == FAIL)
                                status = RA_FAIL;
                            else {
                                bp = (backpos_T *) backpos.ga_data;
                                bp[i].bp_scan = scan;
                                ++backpos.ga_len;
                            }
                        }
                        else if (reg_save_equal (&bp[i].bp_pos))
                            status = RA_NOMATCH;
                        if (status != RA_FAIL && status != RA_NOMATCH)
                            reg_save (&bp[i].bp_pos, &backpos);
                    }
                    break;
                case MOPEN + 0 :
                case MOPEN + 1 :
                case MOPEN + 2 :
                case MOPEN + 3 :
                case MOPEN + 4 :
                case MOPEN + 5 :
                case MOPEN + 6 :
                case MOPEN + 7 :
                case MOPEN + 8 :
                case MOPEN + 9 :
                    {
                        no = op - MOPEN;
                        cleanup_subexpr ();
                        rp = regstack_push (RS_MOPEN, scan);
                        if (rp == NULL)
                            status = RA_FAIL;
                        else {
                            rp->rs_no = no;
                            save_se (& rp -> rs_un.sesave, & rex.reg_startpos [no], & rex.reg_startp [no]);
                        }
                    }
                    break;
                case NOPEN :
                case NCLOSE :
                    if (regstack_push (RS_NOPEN, scan) == NULL)
                        status = RA_FAIL;
                    break;
                case ZOPEN + 1 :
                case ZOPEN + 2 :
                case ZOPEN + 3 :
                case ZOPEN + 4 :
                case ZOPEN + 5 :
                case ZOPEN + 6 :
                case ZOPEN + 7 :
                case ZOPEN + 8 :
                case ZOPEN + 9 :
                    {
                        no = op - ZOPEN;
                        cleanup_zsubexpr ();
                        rp = regstack_push (RS_ZOPEN, scan);
                        if (rp == NULL)
                            status = RA_FAIL;
                        else {
                            rp->rs_no = no;
                            save_se (& rp -> rs_un.sesave, & reg_startzpos [no], & reg_startzp [no]);
                        }
                    }
                    break;
                case MCLOSE + 0 :
                case MCLOSE + 1 :
                case MCLOSE + 2 :
                case MCLOSE + 3 :
                case MCLOSE + 4 :
                case MCLOSE + 5 :
                case MCLOSE + 6 :
                case MCLOSE + 7 :
                case MCLOSE + 8 :
                case MCLOSE + 9 :
                    {
                        no = op - MCLOSE;
                        cleanup_subexpr ();
                        rp = regstack_push (RS_MCLOSE, scan);
                        if (rp == NULL)
                            status = RA_FAIL;
                        else {
                            rp->rs_no = no;
                            save_se (& rp -> rs_un.sesave, & rex.reg_endpos [no], & rex.reg_endp [no]);
                        }
                    }
                    break;
                case ZCLOSE + 1 :
                case ZCLOSE + 2 :
                case ZCLOSE + 3 :
                case ZCLOSE + 4 :
                case ZCLOSE + 5 :
                case ZCLOSE + 6 :
                case ZCLOSE + 7 :
                case ZCLOSE + 8 :
                case ZCLOSE + 9 :
                    {
                        no = op - ZCLOSE;
                        cleanup_zsubexpr ();
                        rp = regstack_push (RS_ZCLOSE, scan);
                        if (rp == NULL)
                            status = RA_FAIL;
                        else {
                            rp->rs_no = no;
                            save_se (& rp -> rs_un.sesave, & reg_endzpos [no], & reg_endzp [no]);
                        }
                    }
                    break;
                case BACKREF + 1 :
                case BACKREF + 2 :
                case BACKREF + 3 :
                case BACKREF + 4 :
                case BACKREF + 5 :
                case BACKREF + 6 :
                case BACKREF + 7 :
                case BACKREF + 8 :
                case BACKREF + 9 :
                    {
                        int len;
                        no = op - BACKREF;
                        cleanup_subexpr ();
                        if (!REG_MULTI) {
                            if (rex.reg_startp[no] == NULL || rex.reg_endp[no] == NULL) {
                                len = 0;
                            }
                            else {
                                len = (int) (rex.reg_endp[no] - rex.reg_startp[no]);
                                if (cstrncmp (rex.reg_startp[no], reginput, &len) != 0)
                                    status = RA_NOMATCH;
                            }
                        }
                        else {
                            if (rex.reg_startpos[no].lnum < 0 || rex.reg_endpos[no].lnum < 0) {
                                len = 0;
                            }
                            else {
                                if (rex.reg_startpos[no].lnum == reglnum && rex.reg_endpos[no].lnum == reglnum) {
                                    len = rex.reg_endpos[no].col - rex.reg_startpos[no].col;
                                    if (cstrncmp (regline +rex.reg_startpos[no].col, reginput, &len) != 0)
                                        status = RA_NOMATCH;
                                }
                                else {
                                    int r = match_with_backref (rex.reg_startpos[no].lnum, rex.reg_startpos[no].col, rex.reg_endpos[no].lnum, rex.reg_endpos[no].col, &len);
                                    if (r != RA_MATCH)
                                        status = r;
                                }
                            }
                        }
                        reginput += len;
                    }
                    break;
                case ZREF + 1 :
                case ZREF + 2 :
                case ZREF + 3 :
                case ZREF + 4 :
                case ZREF + 5 :
                case ZREF + 6 :
                case ZREF + 7 :
                case ZREF + 8 :
                case ZREF + 9 :
                    {
                        int len;
                        cleanup_zsubexpr ();
                        no = op - ZREF;
                        if (re_extmatch_in != NULL && re_extmatch_in->matches[no] != NULL) {
                            len = (int) STRLEN (re_extmatch_in->matches[no]);
                            if (cstrncmp (re_extmatch_in->matches[no], reginput, &len) != 0)
                                status = RA_NOMATCH;
                            else
                                reginput += len;
                        }
                        else {
                        }
                    }
                    break;
                case BRANCH :
                    {
                        if (OP (next) != BRANCH)
                            next = OPERAND (scan);
                        else {
                            rp = regstack_push (RS_BRANCH, scan);
                            if (rp == NULL)
                                status = RA_FAIL;
                            else
                                status = RA_BREAK;
                        }
                    }
                    break;
                case BRACE_LIMITS :
                    {
                        if (OP (next) == BRACE_SIMPLE) {
                            bl_minval = OPERAND_MIN (scan);
                            bl_maxval = OPERAND_MAX (scan);
                        }
                        else if (OP (next) >= BRACE_COMPLEX && OP (next) < BRACE_COMPLEX + 10) {
                            no = OP (next) - BRACE_COMPLEX;
                            brace_min[no] = OPERAND_MIN (scan);
                            brace_max[no] = OPERAND_MAX (scan);
                            brace_count[no] = 0;
                        }
                        else {
                            internal_error ("BRACE_LIMITS");
                            status = RA_FAIL;
                        }
                    }
                    break;
                case BRACE_COMPLEX + 0 :
                case BRACE_COMPLEX + 1 :
                case BRACE_COMPLEX + 2 :
                case BRACE_COMPLEX + 3 :
                case BRACE_COMPLEX + 4 :
                case BRACE_COMPLEX + 5 :
                case BRACE_COMPLEX + 6 :
                case BRACE_COMPLEX + 7 :
                case BRACE_COMPLEX + 8 :
                case BRACE_COMPLEX + 9 :
                    {
                        no = op - BRACE_COMPLEX;
                        ++brace_count[no];
                        if (brace_count[no] <= (brace_min[no] <= brace_max[no] ? brace_min[no] : brace_max[no])) {
                            rp = regstack_push (RS_BRCPLX_MORE, scan);
                            if (rp == NULL)
                                status = RA_FAIL;
                            else {
                                rp->rs_no = no;
                                reg_save (& rp -> rs_un.regsave, & backpos);
                                next = OPERAND (scan);
                            }
                            break;
                        }
                        if (brace_min[no] <= brace_max[no]) {
                            if (brace_count[no] <= brace_max[no]) {
                                rp = regstack_push (RS_BRCPLX_LONG, scan);
                                if (rp == NULL)
                                    status = RA_FAIL;
                                else {
                                    rp->rs_no = no;
                                    reg_save (& rp -> rs_un.regsave, & backpos);
                                    next = OPERAND (scan);
                                }
                            }
                        }
                        else {
                            if (brace_count[no] <= brace_min[no]) {
                                rp = regstack_push (RS_BRCPLX_SHORT, scan);
                                if (rp == NULL)
                                    status = RA_FAIL;
                                else {
                                    reg_save (& rp -> rs_un.regsave, & backpos);
                                }
                            }
                        }
                    }
                    break;
                case BRACE_SIMPLE :
                case STAR :
                case PLUS :
                    {
                        regstar_T rst;
                        if (OP (next) == EXACTLY) {
                            rst.nextb = *OPERAND (next);
                            if (rex.reg_ic) {
                                if (MB_ISUPPER (rst.nextb))
                                    rst.nextb_ic = MB_TOLOWER (rst.nextb);
                                else
                                    rst.nextb_ic = MB_TOUPPER (rst.nextb);
                            }
                            else
                                rst.nextb_ic = rst.nextb;
                        }
                        else {
                            rst.nextb = NUL;
                            rst.nextb_ic = NUL;
                        }
                        if (op != BRACE_SIMPLE) {
                            rst.minval = (op == STAR) ? 0 : 1;
                            rst.maxval = MAX_LIMIT;
                        }
                        else {
                            rst.minval = bl_minval;
                            rst.maxval = bl_maxval;
                        }
                        rst.count = regrepeat (OPERAND (scan), rst.maxval);
                        if (got_int) {
                            status = RA_FAIL;
                            break;
                        }
                        if (rst.minval <= rst.maxval ? rst.count >= rst.minval : rst.count >= rst.maxval) {
                            if ((long ) ((unsigned ) regstack.ga_len >> 10) >= p_mmp) {
                                EMSG (_ (e_maxmempat));
                                status = RA_FAIL;
                            }
                            else if (ga_grow (&regstack, sizeof (regstar_T)) == FAIL)
                                status = RA_FAIL;
                            else {
                                regstack.ga_len += sizeof (regstar_T);
                                rp = regstack_push (rst.minval <= rst.maxval ? RS_STAR_LONG : RS_STAR_SHORT, scan);
                                if (rp == NULL)
                                    status = RA_FAIL;
                                else {
                                    *(((regstar_T *) rp) - 1) = rst;
                                    status = RA_BREAK;
                                }
                            }
                        }
                        else
                            status = RA_NOMATCH;
                    }
                    break;
                case NOMATCH :
                case MATCH :
                case SUBPAT :
                    rp = regstack_push (RS_NOMATCH, scan);
                    if (rp == NULL)
                        status = RA_FAIL;
                    else {
                        rp->rs_no = op;
                        reg_save (& rp -> rs_un.regsave, & backpos);
                        next = OPERAND (scan);
                    }
                    break;
                case BEHIND :
                case NOBEHIND :
                    if ((long ) ((unsigned ) regstack.ga_len >> 10) >= p_mmp) {
                        EMSG (_ (e_maxmempat));
                        status = RA_FAIL;
                    }
                    else if (ga_grow (&regstack, sizeof (regbehind_T)) == FAIL)
                        status = RA_FAIL;
                    else {
                        regstack.ga_len += sizeof (regbehind_T);
                        rp = regstack_push (RS_BEHIND1, scan);
                        if (rp == NULL)
                            status = RA_FAIL;
                        else {
                            save_subexpr (((regbehind_T *) rp) - 1);
                            rp->rs_no = op;
                            reg_save (& rp -> rs_un.regsave, & backpos);
                        }
                    }
                    break;
                case BHPOS :
                    if (REG_MULTI) {
                        if (behind_pos.rs_u.pos.col != (colnr_T) (reginput - regline) || behind_pos.rs_u.pos.lnum != reglnum)
                            status = RA_NOMATCH;
                    }
                    else if (behind_pos.rs_u.ptr != reginput)
                        status = RA_NOMATCH;
                    break;
                case NEWL :
                    if ((c != NUL || !REG_MULTI || reglnum > rex.reg_maxline || rex.reg_line_lbr) && (c != '\n' || !rex.reg_line_lbr))
                        status = RA_NOMATCH;
                    else if (rex.reg_line_lbr)
                        ADVANCE_REGINPUT ();
                    else
                        reg_nextline ();
                    break;
                case END :
                    status = RA_MATCH;
                    break;
                default :
                    EMSG (_ (e_re_corr));
                    status = RA_FAIL;
                    break;
                }
            }
            if (status != RA_CONT)
                break;
            scan = next;
        }
        while (regstack.ga_len > 0 && status != RA_FAIL) {
            rp = (regitem_T *) ((char *) regstack.ga_data + regstack.ga_len) - 1;
            switch (rp->rs_state) {
            case RS_NOPEN :
                regstack_pop (&scan);
                break;
            case RS_MOPEN :
                if (status == RA_NOMATCH)
                    restore_se (&rp->rs_un.sesave, &rex.reg_startpos[rp->rs_no], &rex.reg_startp[rp->rs_no]);
                regstack_pop (& scan);
                break;
            case RS_ZOPEN :
                if (status == RA_NOMATCH)
                    restore_se (&rp->rs_un.sesave, &reg_startzpos[rp->rs_no], &reg_startzp[rp->rs_no]);
                regstack_pop (& scan);
                break;
            case RS_MCLOSE :
                if (status == RA_NOMATCH)
                    restore_se (&rp->rs_un.sesave, &rex.reg_endpos[rp->rs_no], &rex.reg_endp[rp->rs_no]);
                regstack_pop (& scan);
                break;
            case RS_ZCLOSE :
                if (status == RA_NOMATCH)
                    restore_se (&rp->rs_un.sesave, &reg_endzpos[rp->rs_no], &reg_endzp[rp->rs_no]);
                regstack_pop (& scan);
                break;
            case RS_BRANCH :
                if (status == RA_MATCH)
                    regstack_pop (&scan);
                else {
                    if (status != RA_BREAK) {
                        reg_restore (& rp -> rs_un.regsave, & backpos);
                        scan = rp->rs_scan;
                    }
                    if (scan == NULL || OP (scan) != BRANCH) {
                        status = RA_NOMATCH;
                        regstack_pop (& scan);
                    }
                    else {
                        rp->rs_scan = regnext (scan);
                        reg_save (& rp -> rs_un.regsave, & backpos);
                        scan = OPERAND (scan);
                    }
                }
                break;
            case RS_BRCPLX_MORE :
                if (status == RA_NOMATCH) {
                    reg_restore (& rp -> rs_un.regsave, & backpos);
                    --brace_count[rp->rs_no];
                }
                regstack_pop (& scan);
                break;
            case RS_BRCPLX_LONG :
                if (status == RA_NOMATCH) {
                    reg_restore (& rp -> rs_un.regsave, & backpos);
                    --brace_count[rp->rs_no];
                    status = RA_CONT;
                }
                regstack_pop (& scan);
                if (status == RA_CONT)
                    scan = regnext (scan);
                break;
            case RS_BRCPLX_SHORT :
                if (status == RA_NOMATCH)
                    reg_restore (&rp->rs_un.regsave, &backpos);
                regstack_pop (& scan);
                if (status == RA_NOMATCH) {
                    scan = OPERAND (scan);
                    status = RA_CONT;
                }
                break;
            case RS_NOMATCH :
                if (status == (rp->rs_no == NOMATCH ? RA_MATCH : RA_NOMATCH))
                    status = RA_NOMATCH;
                else {
                    status = RA_CONT;
                    if (rp->rs_no != SUBPAT)
                        reg_restore (&rp->rs_un.regsave, &backpos);
                }
                regstack_pop (& scan);
                if (status == RA_CONT)
                    scan = regnext (scan);
                break;
            case RS_BEHIND1 :
                if (status == RA_NOMATCH) {
                    regstack_pop (& scan);
                    regstack.ga_len -= sizeof (regbehind_T);
                }
                else {
                    reg_save (& (((regbehind_T *) rp) - 1) -> save_after, & backpos);
                    (((regbehind_T *) rp) - 1)->save_behind = behind_pos;
                    behind_pos = rp->rs_un.regsave;
                    rp->rs_state = RS_BEHIND2;
                    reg_restore (& rp -> rs_un.regsave, & backpos);
                    scan = OPERAND (rp->rs_scan) + 4;
                }
                break;
            case RS_BEHIND2 :
                if (status == RA_MATCH && reg_save_equal (&behind_pos)) {
                    behind_pos = (((regbehind_T *) rp) - 1)->save_behind;
                    if (rp->rs_no == BEHIND)
                        reg_restore (&(((regbehind_T *) rp) - 1)->save_after, &backpos);
                    else {
                        status = RA_NOMATCH;
                        restore_subexpr (((regbehind_T *) rp) - 1);
                    }
                    regstack_pop (& scan);
                    regstack.ga_len -= sizeof (regbehind_T);
                }
                else {
                    long  limit;
                    no = OK;
                    limit = OPERAND_MIN (rp->rs_scan);
                    if (REG_MULTI) {
                        if (limit > 0 && ((rp->rs_un.regsave.rs_u.pos.lnum < behind_pos.rs_u.pos.lnum ? (colnr_T) STRLEN (regline) : behind_pos.rs_u.pos.col) - rp->rs_un.regsave.rs_u.pos.col >= limit))
                            no = FAIL;
                        else if (rp->rs_un.regsave.rs_u.pos.col == 0) {
                            if (rp->rs_un.regsave.rs_u.pos.lnum < behind_pos.rs_u.pos.lnum || reg_getline (--rp->rs_un.regsave.rs_u.pos.lnum) == NULL)
                                no = FAIL;
                            else {
                                reg_restore (& rp -> rs_un.regsave, & backpos);
                                rp->rs_un.regsave.rs_u.pos.col = (colnr_T) STRLEN (regline);
                            }
                        }
                        else {
                            --rp->rs_un.regsave.rs_u.pos.col;
                        }
                    }
                    else {
                        if (rp->rs_un.regsave.rs_u.ptr == regline)
                            no = FAIL;
                        else {
                            MB_PTR_BACK (regline, rp -> rs_un.regsave.rs_u.ptr);
                            if (limit > 0 && (long ) (behind_pos.rs_u.ptr - rp->rs_un.regsave.rs_u.ptr) > limit)
                                no = FAIL;
                        }
                    }
                    if (no == OK) {
                        reg_restore (& rp -> rs_un.regsave, & backpos);
                        scan = OPERAND (rp->rs_scan) + 4;
                        if (status == RA_MATCH) {
                            status = RA_NOMATCH;
                            restore_subexpr (((regbehind_T *) rp) - 1);
                        }
                    }
                    else {
                        behind_pos = (((regbehind_T *) rp) - 1)->save_behind;
                        if (rp->rs_no == NOBEHIND) {
                            reg_restore (& (((regbehind_T *) rp) - 1) -> save_after, & backpos);
                            status = RA_MATCH;
                        }
                        else {
                            if (status == RA_MATCH) {
                                status = RA_NOMATCH;
                                restore_subexpr (((regbehind_T *) rp) - 1);
                            }
                        }
                        regstack_pop (& scan);
                        regstack.ga_len -= sizeof (regbehind_T);
                    }
                }
                break;
            case RS_STAR_LONG :
            case RS_STAR_SHORT :
                {
                    regstar_T *rst = ((regstar_T *) rp) - 1;
                    if (status == RA_MATCH) {
                        regstack_pop (& scan);
                        regstack.ga_len -= sizeof (regstar_T);
                        break;
                    }
                    if (status != RA_BREAK)
                        reg_restore (&rp->rs_un.regsave, &backpos);
                    for (;;) {
                        if (status != RA_BREAK) {
                            if (rp->rs_state == RS_STAR_LONG) {
                                if (--rst->count < rst->minval)
                                    break;
                                if (reginput == regline) {
                                    --reglnum;
                                    regline = reg_getline (reglnum);
                                    if (regline == NULL)
                                        break;
                                    reginput = regline + STRLEN (regline);
                                    fast_breakcheck ();
                                }
                                else
                                    MB_PTR_BACK (regline, reginput);
                            }
                            else {
                                if (rst->count == rst->minval || regrepeat (OPERAND (rp->rs_scan), 1L) == 0)
                                    break;
                                ++rst->count;
                            }
                            if (got_int)
                                break;
                        }
                        else
                            status = RA_NOMATCH;
                        if (rst->nextb == NUL || *reginput == rst->nextb || *reginput == rst->nextb_ic) {
                            reg_save (& rp -> rs_un.regsave, & backpos);
                            scan = regnext (rp->rs_scan);
                            status = RA_CONT;
                            break;
                        }
                    }
                    if (status != RA_CONT) {
                        regstack_pop (& scan);
                        regstack.ga_len -= sizeof (regstar_T);
                        status = RA_NOMATCH;
                    }
                }
                break;
            }
            if (status == RA_CONT || rp == (regitem_T *) ((char *) regstack.ga_data + regstack.ga_len) - 1)
                break;
        }
        if (status == RA_CONT)
            continue;
        if (regstack.ga_len == 0 || status == RA_FAIL) {
            if (scan == NULL) {
                EMSG (_ (e_re_corr));
            }
            return (status == RA_MATCH);
        }
    }
}

regprog_T *vim_regcomp (char_u *expr_arg, int re_flags) {
    regprog_T *prog = NULL;
    char_u *expr = expr_arg;
    regexp_engine = p_re;
    if (STRNCMP (expr, "\\%#=", 4) == 0) {
        int newengine = expr[4] - '0';
        if (newengine == AUTOMATIC_ENGINE || newengine == BACKTRACKING_ENGINE || newengine == NFA_ENGINE) {
            regexp_engine = expr[4] - '0';
            expr += 5;
        }
        else {
            EMSG (_ ("E864: \\%#= can only be followed by 0, 1, or 2. The automatic engine will be used "));
            regexp_engine = AUTOMATIC_ENGINE;
        }
    }
    bt_regengine.expr = expr;
    nfa_regengine.expr = expr;
    if (regexp_engine != BACKTRACKING_ENGINE)
        prog = nfa_regengine.regcomp (expr, re_flags +(regexp_engine == AUTOMATIC_ENGINE ? RE_AUTO : 0));
    else
        prog = bt_regengine.regcomp (expr, re_flags);
    if (prog == NULL) {
        if (regexp_engine == AUTOMATIC_ENGINE) {
            regexp_engine = BACKTRACKING_ENGINE;
            prog = bt_regengine.regcomp (expr, re_flags);
        }
    }
    if (prog != NULL) {
        prog->re_engine = regexp_engine;
        prog->re_flags = re_flags;
    }
    return prog;
}

int vim_regexec (regmatch_T *rmp, char_u *line, colnr_T col) {
    return vim_regexec_string (rmp, line, col, FALSE);
}

void vim_regfree (regprog_T *prog) {
    if (prog != NULL)
        prog->engine->regfree (prog);
}

int vim_regexec_nl (regmatch_T *rmp, char_u *line, colnr_T col) {
    return vim_regexec_string (rmp, line, col, TRUE);
}

void unref_extmatch (reg_extmatch_T *em) {
    int i;
    if (em != NULL && --em->refcnt <= 0) {
        for (i = 0; i < NSUBEXP; ++i)
            vim_free (em->matches[i]);
        vim_free (em);
    }
}

int re_multiline (regprog_T *prog) {
    return (prog->regflags & RF_HASNL);
}

reg_extmatch_T *ref_extmatch (reg_extmatch_T *em) {
    if (em != NULL)
        em->refcnt++;
    return em;
}

long  vim_regexec_multi (regmmatch_T *rmp, win_T *win, buf_T *buf, linenr_T lnum, colnr_T col, proftime_T *tm, int *timed_out) {
    int result;
    regexec_T rex_save;
    int rex_in_use_save = rex_in_use;
    if (rex_in_use)
        rex_save = rex;
    rex_in_use = TRUE;
    result = rmp->regprog->engine->regexec_multi (rmp, win, buf, lnum, col, tm, timed_out);
    if (rmp->regprog->re_engine == AUTOMATIC_ENGINE && result == NFA_TOO_EXPENSIVE) {
        int save_p_re = p_re;
        int re_flags = rmp->regprog->re_flags;
        char_u *pat = vim_strsave (((nfa_regprog_T *) rmp->regprog)->pattern);
        p_re = BACKTRACKING_ENGINE;
        vim_regfree (rmp -> regprog);
        if (pat != NULL) {
            report_re_switch (pat);
            rmp->regprog = vim_regcomp (pat, re_flags);
            if (rmp->regprog != NULL)
                result = rmp->regprog->engine->regexec_multi (rmp, win, buf, lnum, col, tm, timed_out);
            vim_free (pat);
        }
        p_re = save_p_re;
    }
    rex_in_use = rex_in_use_save;
    if (rex_in_use)
        rex = rex_save;
    return result <= 0 ? 0 : result;
}

char_u *skip_regexp (char_u *startp, int dirc, int magic, char_u **newp) {
    int mymagic;
    char_u *p = startp;
    if (magic)
        mymagic = MAGIC_ON;
    else
        mymagic = MAGIC_OFF;
    get_cpo_flags ();
    for (; p[0] != NUL; MB_PTR_ADV (p)) {
        if (p[0] == dirc)
            break;
        if ((p[0] == '[' && mymagic >= MAGIC_ON) || (p[0] == '\\' && p[1] == '[' && mymagic <= MAGIC_OFF)) {
            p = skip_anyof (p +1);
            if (p[0] == NUL)
                break;
        }
        else if (p[0] == '\\' && p[1] != NUL) {
            if (dirc == '?' && newp != NULL && p[1] == '?') {
                if (*newp == NULL) {
                    *newp = vim_strsave (startp);
                    if (*newp != NULL)
                        p = *newp + (p - startp);
                }
                if (*newp != NULL)
                    STRMOVE (p, p +1);
                else
                    ++p;
            }
            else
                ++p;
            if (*p == 'v')
                mymagic = MAGIC_ALL;
            else if (*p == 'V')
                mymagic = MAGIC_NONE;
        }
    }
    return p;
}

static void get_cpo_flags (void) {
    reg_cpo_lit = vim_strchr (p_cpo, CPO_LITERAL) != NULL;
    reg_cpo_bsl = vim_strchr (p_cpo, CPO_BACKSL) != NULL;
}

static char_u *skip_anyof (char_u *p) {
    if (*p == '^')
        ++p;
    if (*p == ']' || *p == '-')
        ++p;
    while (*p != NUL && *p != ']') {
        if (*p == '-') {
            ++p;
            if (*p != ']' && *p != NUL)
                MB_PTR_ADV (p);
        }
        else if (*p == '\\' && !reg_cpo_bsl && (vim_strchr (REGEXP_INRANGE, p[1]) != NULL || (!reg_cpo_lit && vim_strchr (REGEXP_ABBR, p[1]) != NULL)))
            p += 2;
        else if (*p == '[') {
            if (get_char_class (&p) == CLASS_NONE && get_equi_class (&p) == 0 && get_coll_element (&p) == 0 && *p != NUL)
                ++p;
        }
        else
            ++p;
    }
    return p;
}

static int get_char_class (char_u **pp) {
    static const char * (class_names []) = {"alnum:]", 
        #define CLASS_ALNUM 0
        "alpha:]", 
        #define CLASS_ALPHA 1
        "blank:]", 
        #define CLASS_BLANK 2
        "cntrl:]", 
        #define CLASS_CNTRL 3
        "digit:]", 
        #define CLASS_DIGIT 4
        "graph:]", 
        #define CLASS_GRAPH 5
        "lower:]", 
        #define CLASS_LOWER 6
        "print:]", 
        #define CLASS_PRINT 7
        "punct:]", 
        #define CLASS_PUNCT 8
        "space:]", 
        #define CLASS_SPACE 9
        "upper:]", 
        #define CLASS_UPPER 10
        "xdigit:]", 
        #define CLASS_XDIGIT 11
        "tab:]", 
        #define CLASS_TAB 12
        "return:]", 
        #define CLASS_RETURN 13
        "backspace:]", 
        #define CLASS_BACKSPACE 14
        "escape:]", 
        #define CLASS_ESCAPE 15

    };

    #define CLASS_NONE 99
    int i;
    if ((*pp)[1] == ':') {
        for (i = 0; i < (int) (sizeof (class_names) / sizeof (*class_names)); ++i)
            if (STRNCMP (*pp + 2, class_names[i], STRLEN (class_names[i])) == 0) {
                *pp += STRLEN (class_names[i]) + 2;
                return i;
            }
    }
    return CLASS_NONE;
}

static int get_equi_class (char_u **pp) {
    int c;
    int l = 1;
    char_u *p = *pp;
    if (p[1] == '=') {
        if (p[l + 2] == '=' && p[l + 3] == ']') {
            c = p[2];
            *pp += l + 4;
            return c;
        }
    }
    return 0;
}

static int get_coll_element (char_u **pp) {
    int c;
    int l = 1;
    char_u *p = *pp;
    if (p[0] != NUL && p[1] == '.') {
        if (p[l + 2] == '.' && p[l + 3] == ']') {
            c = p[2];
            *pp += l + 4;
            return c;
        }
    }
    return 0;
}

static char_u *reg (int paren, int *flagp) {
    char_u *ret;
    char_u *br;
    char_u *ender;
    int parno = 0;
    int flags;
    *flagp = HASWIDTH;
    if (paren == REG_ZPAREN) {
        if (regnzpar >= NSUBEXP)
            EMSG_RET_NULL (_ ("E50: Too many \\z("));
        parno = regnzpar;
        regnzpar++;
        ret = regnode (ZOPEN +parno);
    }
    else if (paren == REG_PAREN) {
        if (regnpar >= NSUBEXP)
            EMSG2_RET_NULL (_ ("E51: Too many %s("), reg_magic == MAGIC_ALL);
        parno = regnpar;
        ++regnpar;
        ret = regnode (MOPEN +parno);
    }
    else if (paren == REG_NPAREN) {
        ret = regnode (NOPEN);
    }
    else
        ret = NULL;
    br = regbranch (&flags);
    if (br == NULL)
        return NULL;
    if (ret != NULL)
        regtail (ret, br);
    else
        ret = br;
    if (!(flags & HASWIDTH))
        *flagp &= ~HASWIDTH;
    *flagp |= flags & (SPSTART | HASNL | HASLOOKBH);
    while (peekchr () == Magic ('|')) {
        skipchr ();
        br = regbranch (&flags);
        if (br == NULL || reg_toolong)
            return NULL;
        regtail (ret, br);
        if (!(flags & HASWIDTH))
            *flagp &= ~HASWIDTH;
        *flagp |= flags & (SPSTART | HASNL | HASLOOKBH);
    }
    ender = regnode (paren == REG_ZPAREN ? ZCLOSE + parno : paren == REG_PAREN ? MCLOSE + parno : paren == REG_NPAREN ? NCLOSE : END);
    regtail (ret, ender);
    for (br = ret; br != NULL; br = regnext (br))
        regoptail (br, ender);
    if (paren != REG_NOPAREN && getchr () != Magic (')')) {
        if (paren == REG_ZPAREN)
            EMSG_RET_NULL (_ ("E52: Unmatched \\z("));
        else if (paren == REG_NPAREN)
            EMSG2_RET_NULL (_ (e_unmatchedpp), reg_magic == MAGIC_ALL);
        else
            EMSG2_RET_NULL (_ (e_unmatchedp), reg_magic == MAGIC_ALL);
    }
    else if (paren == REG_NOPAREN && peekchr () != NUL) {
        if (curchr == Magic (')'))
            EMSG2_RET_NULL (_ (e_unmatchedpar), reg_magic == MAGIC_ALL);
        else
            EMSG_RET_NULL (_ (e_trailing));
    }
    if (paren == REG_PAREN)
        had_endbrace[parno] = TRUE;
    return ret;
}

static char_u *regnode (int op) {
    char_u *ret;
    ret = regcode;
    if (ret == JUST_CALC_SIZE)
        regsize += 3;
    else {
        *regcode++ = op;
        *regcode++ = NUL;
        *regcode++ = NUL;
    }
    return ret;
}

static char_u *regbranch (int *flagp) {
    char_u *ret;
    char_u *chain = NULL;
    char_u *latest;
    int flags;
    *flagp = WORST | HASNL;
    ret = regnode (BRANCH);
    for (;;) {
        latest = regconcat (&flags);
        if (latest == NULL)
            return NULL;
        *flagp |= flags & (HASWIDTH | SPSTART | HASLOOKBH);
        *flagp &= ~HASNL | (flags & HASNL);
        if (chain != NULL)
            regtail (chain, latest);
        if (peekchr () != Magic ('&'))
            break;
        skipchr ();
        regtail (latest, regnode (END));
        if (reg_toolong)
            break;
        reginsert (MATCH, latest);
        chain = latest;
    }
    return ret;
}

static char_u *regconcat (int *flagp) {
    char_u *first = NULL;
    char_u *chain = NULL;
    char_u *latest;
    int flags;
    int cont = TRUE;
    *flagp = WORST;
    while (cont) {
        switch (peekchr ()) {
        case NUL :
        case Magic ('|') :
        case Magic ('&') :
        case Magic (')') :
            cont = FALSE;
            break;
        case Magic ('Z') :
            skipchr_keepstart ();
            break;
        case Magic ('c') :
            regflags |= RF_ICASE;
            skipchr_keepstart ();
            break;
        case Magic ('C') :
            regflags |= RF_NOICASE;
            skipchr_keepstart ();
            break;
        case Magic ('v') :
            reg_magic = MAGIC_ALL;
            skipchr_keepstart ();
            curchr = -1;
            break;
        case Magic ('m') :
            reg_magic = MAGIC_ON;
            skipchr_keepstart ();
            curchr = -1;
            break;
        case Magic ('M') :
            reg_magic = MAGIC_OFF;
            skipchr_keepstart ();
            curchr = -1;
            break;
        case Magic ('V') :
            reg_magic = MAGIC_NONE;
            skipchr_keepstart ();
            curchr = -1;
            break;
        default :
            latest = regpiece (&flags);
            if (latest == NULL || reg_toolong)
                return NULL;
            *flagp |= flags & (HASWIDTH | HASNL | HASLOOKBH);
            if (chain == NULL)
                *flagp |= flags & SPSTART;
            else
                regtail (chain, latest);
            chain = latest;
            if (first == NULL)
                first = latest;
            break;
        }
    }
    if (first == NULL)
        first = regnode (NOTHING);
    return first;
}

static int peekchr (void) {
    static int after_slash = FALSE;
    if (curchr == -1) {
        switch (curchr = regparse[0]) {
        case '.' :
        case '[' :
        case '~' :
            if (reg_magic >= MAGIC_ON)
                curchr = Magic (curchr);
            break;
        case '(' :
        case ')' :
        case '{' :
        case '%' :
        case '+' :
        case '=' :
        case '?' :
        case '@' :
        case '!' :
        case '&' :
        case '|' :
        case '<' :
        case '>' :
        case '#' :
        case '"' :
        case '\'' :
        case ',' :
        case '-' :
        case ':' :
        case ';' :
        case '`' :
        case '/' :
            if (reg_magic == MAGIC_ALL)
                curchr = Magic (curchr);
            break;
        case '*' :
            if (reg_magic >= MAGIC_ON && !at_start && !(prev_at_start && prevchr == Magic ('^')) && (after_slash || (prevchr != Magic ('(') && prevchr != Magic ('&') && prevchr != Magic ('|'))))
                curchr = Magic ('*');
            break;
        case '^' :
            if (reg_magic >= MAGIC_OFF && (at_start || reg_magic == MAGIC_ALL || prevchr == Magic ('(') || prevchr == Magic ('|') || prevchr == Magic ('&') || prevchr == Magic ('n') || (no_Magic (prevchr) == '(' && prevprevchr == Magic ('%')))) {
                curchr = Magic ('^');
                at_start = TRUE;
                prev_at_start = FALSE;
            }
            break;
        case '$' :
            if (reg_magic >= MAGIC_OFF) {
                char_u *p = regparse + 1;
                int is_magic_all = (reg_magic == MAGIC_ALL);
                while (p[0] == '\\' && (p[1] == 'c' || p[1] == 'C' || p[1] == 'm' || p[1] == 'M' || p[1] == 'v' || p[1] == 'V' || p[1] == 'Z')) {
                    if (p[1] == 'v')
                        is_magic_all = TRUE;
                    else if (p[1] == 'm' || p[1] == 'M' || p[1] == 'V')
                        is_magic_all = FALSE;
                    p += 2;
                }
                if (p[0] == NUL || (p[0] == '\\' && (p[1] == '|' || p[1] == '&' || p[1] == ')' || p[1] == 'n')) || (is_magic_all && (p[0] == '|' || p[0] == '&' || p[0] == ')')) || reg_magic == MAGIC_ALL)
                    curchr = Magic ('$');
            }
            break;
        case '\\' :
            {
                int c = regparse[1];
                if (c == NUL)
                    curchr = '\\';
                else if (c <= '~' && META_flags[c]) {
                    curchr = -1;
                    prev_at_start = at_start;
                    at_start = FALSE;
                    ++regparse;
                    ++after_slash;
                    peekchr ();
                    --regparse;
                    --after_slash;
                    curchr = toggle_Magic (curchr);
                }
                else if (vim_strchr (REGEXP_ABBR, c)) {
                    curchr = backslash_trans (c);
                }
                else if (reg_magic == MAGIC_NONE && (c == '$' || c == '^'))
                    curchr = toggle_Magic (c);
                else {
                    curchr = c;
                }
                break;
            }
        }
    }
    return curchr;
}

static int no_Magic (int x) {
    if (is_Magic (x))
        return un_Magic (x);
    return x;
}

static int toggle_Magic (int x) {
    if (is_Magic (x))
        return un_Magic (x);
    return Magic (x);
}

#define REGMAGIC	0234

#define OP(p)		((int)*(p))

#define NEXT(p)		(((*((p) + 1) & 0377) << 8) + (*((p) + 2) & 0377))

#define OPERAND(p)	((p) + 3)

#define OPERAND_MIN(p)	(((long)(p)[3] << 24) + ((long)(p)[4] << 16) \
			+ ((long)(p)[5] << 8) + (long)(p)[6])

#define OPERAND_MAX(p)	OPERAND_MIN((p) + 4)

#define OPERAND_CMP(p)	(p)[7]

#define UCHARAT(p)	((int)*(char_u *)(p))

#define EMSG_RET_NULL(m) return (EMSG(m), rc_did_emsg = TRUE, (void *)NULL)

#define IEMSG_RET_NULL(m) return (IEMSG(m), rc_did_emsg = TRUE, (void *)NULL)

#define EMSG_RET_FAIL(m) return (EMSG(m), rc_did_emsg = TRUE, FAIL)

#define EMSG2_RET_NULL(m, c) return (EMSG2((m), (c) ? "" : "\\"), rc_did_emsg = TRUE, (void *)NULL)

#define EMSG2_RET_FAIL(m, c) return (EMSG2((m), (c) ? "" : "\\"), rc_did_emsg = TRUE, FAIL)

#define EMSG_ONE_RET_NULL EMSG2_RET_NULL(_("E369: invalid item in %s%%[]"), reg_magic == MAGIC_ALL)

#define MAX_LIMIT	(32767L << 16L)

static int backslash_trans (int c) {
    switch (c) {
    case 'r' :
        return CAR;
    case 't' :
        return TAB;
    case 'e' :
        return ESC;
    case 'b' :
        return BS;
    }
    return c;
}

static void skipchr_keepstart (void) {
    int as = prev_at_start;
    int pr = prevchr;
    int prpr = prevprevchr;
    skipchr ();
    at_start = as;
    prevchr = pr;
    prevprevchr = prpr;
}

static void skipchr (void) {
    if (*regparse == '\\')
        prevchr_len = 1;
    else
        prevchr_len = 0;
    if (regparse[prevchr_len] != NUL) {
        ++prevchr_len;
    }
    regparse += prevchr_len;
    prev_at_start = at_start;
    at_start = FALSE;
    prevprevchr = prevchr;
    prevchr = curchr;
    curchr = nextchr;
    nextchr = -1;
}

static char_u *regpiece (int *flagp) {
    char_u *ret;
    int op;
    char_u *next;
    int flags;
    long  minval;
    long  maxval;
    ret = regatom (&flags);
    if (ret == NULL)
        return NULL;
    op = peekchr ();
    if (re_multi_type (op) == NOT_MULTI) {
        *flagp = flags;
        return ret;
    }
    *flagp = (WORST | SPSTART | (flags & (HASNL | HASLOOKBH)));
    skipchr ();
    switch (op) {
    case Magic ('*') :
        if (flags & SIMPLE)
            reginsert (STAR, ret);
        else {
            reginsert (BRANCH, ret);
            regoptail (ret, regnode (BACK));
            regoptail (ret, ret);
            regtail (ret, regnode (BRANCH));
            regtail (ret, regnode (NOTHING));
        }
        break;
    case Magic ('+') :
        if (flags & SIMPLE)
            reginsert (PLUS, ret);
        else {
            next = regnode (BRANCH);
            regtail (ret, next);
            regtail (regnode (BACK), ret);
            regtail (next, regnode (BRANCH));
            regtail (ret, regnode (NOTHING));
        }
        *flagp = (WORST | HASWIDTH | (flags & (HASNL | HASLOOKBH)));
        break;
    case Magic ('@') :
        {
            int lop = END;
            long  nr;
            nr = getdecchrs ();
            switch (no_Magic (getchr ())) {
            case '=' :
                lop = MATCH;
                break;
            case '!' :
                lop = NOMATCH;
                break;
            case '>' :
                lop = SUBPAT;
                break;
            case '<' :
                switch (no_Magic (getchr ())) {
                case '=' :
                    lop = BEHIND;
                    break;
                case '!' :
                    lop = NOBEHIND;
                    break;
                }
            }
            if (lop == END)
                EMSG2_RET_NULL (_ ("E59: invalid character after %s@"), reg_magic == MAGIC_ALL);
            if (lop == BEHIND || lop == NOBEHIND) {
                regtail (ret, regnode (BHPOS));
                *flagp |= HASLOOKBH;
            }
            regtail (ret, regnode (END));
            if (lop == BEHIND || lop == NOBEHIND) {
                if (nr < 0)
                    nr = 0;
                reginsert_nr (lop, nr, ret);
            }
            else
                reginsert (lop, ret);
            break;
        }
    case Magic ('?') :
    case Magic ('=') :
        reginsert (BRANCH, ret);
        regtail (ret, regnode (BRANCH));
        next = regnode (NOTHING);
        regtail (ret, next);
        regoptail (ret, next);
        break;
    case Magic ('{') :
        if (!read_limits (&minval, &maxval))
            return NULL;
        if (flags & SIMPLE) {
            reginsert (BRACE_SIMPLE, ret);
            reginsert_limits (BRACE_LIMITS, minval, maxval, ret);
        }
        else {
            if (num_complex_braces >= 10)
                EMSG2_RET_NULL (_ ("E60: Too many complex %s{...}s"), reg_magic == MAGIC_ALL);
            reginsert (BRACE_COMPLEX + num_complex_braces, ret);
            regoptail (ret, regnode (BACK));
            regoptail (ret, ret);
            reginsert_limits (BRACE_LIMITS, minval, maxval, ret);
            ++num_complex_braces;
        }
        if (minval > 0 && maxval > 0)
            *flagp = (HASWIDTH | (flags & (HASNL | HASLOOKBH)));
        break;
    }
    if (re_multi_type (peekchr ()) != NOT_MULTI) {
        if (peekchr () == Magic ('*'))
            sprintf ((char *) IObuff, _ ("E61: Nested %s*"), reg_magic >= MAGIC_ON ? "" : "\\");
        else
            sprintf ((char *) IObuff, _ ("E62: Nested %s%c"), reg_magic == MAGIC_ALL ? "" : "\\", no_Magic (peekchr ()));
        EMSG_RET_NULL (IObuff);
    }
    return ret;
}

static char_u *regatom (int *flagp) {
    char_u *ret;
    int flags;
    int c;
    char_u *p;
    int extra = 0;
    int save_prev_at_start = prev_at_start;
    *flagp = WORST;
    c = getchr ();
    switch (c) {
    case Magic ('^') :
        ret = regnode (BOL);
        break;
    case Magic ('$') :
        ret = regnode (EOL);
        had_eol = TRUE;
        break;
    case Magic ('<') :
        ret = regnode (BOW);
        break;
    case Magic ('>') :
        ret = regnode (EOW);
        break;
    case Magic ('_') :
        c = no_Magic (getchr ());
        if (c == '^') {
            ret = regnode (BOL);
            break;
        }
        if (c == '$') {
            ret = regnode (EOL);
            had_eol = TRUE;
            break;
        }
        extra = ADD_NL;
        *flagp |= HASNL;
        if (c == '[')
            goto collection;
    case Magic ('.') :
    case Magic ('i') :
    case Magic ('I') :
    case Magic ('k') :
    case Magic ('K') :
    case Magic ('f') :
    case Magic ('F') :
    case Magic ('p') :
    case Magic ('P') :
    case Magic ('s') :
    case Magic ('S') :
    case Magic ('d') :
    case Magic ('D') :
    case Magic ('x') :
    case Magic ('X') :
    case Magic ('o') :
    case Magic ('O') :
    case Magic ('w') :
    case Magic ('W') :
    case Magic ('h') :
    case Magic ('H') :
    case Magic ('a') :
    case Magic ('A') :
    case Magic ('l') :
    case Magic ('L') :
    case Magic ('u') :
    case Magic ('U') :
        p = vim_strchr (classchars, no_Magic (c));
        if (p == NULL)
            EMSG_RET_NULL (_ ("E63: invalid use of \\_"));
        ret = regnode (classcodes[p - classchars] + extra);
        *flagp |= HASWIDTH | SIMPLE;
        break;
    case Magic ('n') :
        if (reg_string) {
            ret = regnode (EXACTLY);
            regc (NL);
            regc (NUL);
            *flagp |= HASWIDTH | SIMPLE;
        }
        else {
            ret = regnode (NEWL);
            *flagp |= HASWIDTH | HASNL;
        }
        break;
    case Magic ('(') :
        if (one_exactly)
            EMSG_ONE_RET_NULL;
        ret = reg (REG_PAREN, &flags);
        if (ret == NULL)
            return NULL;
        *flagp |= flags & (HASWIDTH | SPSTART | HASNL | HASLOOKBH);
        break;
    case NUL :
    case Magic ('|') :
    case Magic ('&') :
    case Magic (')') :
        if (one_exactly)
            EMSG_ONE_RET_NULL;
        IEMSG_RET_NULL (_ (e_internal));
    case Magic ('=') :
    case Magic ('?') :
    case Magic ('+') :
    case Magic ('@') :
    case Magic ('{') :
    case Magic ('*') :
        c = no_Magic (c);
        sprintf ((char *) IObuff, _ ("E64: %s%c follows nothing"), (c == '*' ? reg_magic >= MAGIC_ON : reg_magic == MAGIC_ALL) ? "" : "\\", c);
        EMSG_RET_NULL (IObuff);
    case Magic ('~') :
        if (reg_prev_sub != NULL) {
            char_u *lp;
            ret = regnode (EXACTLY);
            lp = reg_prev_sub;
            while (*lp != NUL)
                regc (*lp++);
            regc (NUL);
            if (*reg_prev_sub != NUL) {
                *flagp |= HASWIDTH;
                if ((lp - reg_prev_sub) == 1)
                    *flagp |= SIMPLE;
            }
        }
        else
            EMSG_RET_NULL (_ (e_nopresub));
        break;
    case Magic ('1') :
    case Magic ('2') :
    case Magic ('3') :
    case Magic ('4') :
    case Magic ('5') :
    case Magic ('6') :
    case Magic ('7') :
    case Magic ('8') :
    case Magic ('9') :
        {
            int refnum;
            refnum = c - Magic ('0');
            if (!seen_endbrace (refnum))
                return NULL;
            ret = regnode (BACKREF +refnum);
        }
        break;
    case Magic ('z') :
        {
            c = no_Magic (getchr ());
            switch (c) {
            case '(' :
                if (reg_do_extmatch != REX_SET)
                    EMSG_RET_NULL (_ (e_z_not_allowed));
                if (one_exactly)
                    EMSG_ONE_RET_NULL;
                ret = reg (REG_ZPAREN, &flags);
                if (ret == NULL)
                    return NULL;
                *flagp |= flags & (HASWIDTH | SPSTART | HASNL | HASLOOKBH);
                re_has_z = REX_SET;
                break;
            case '1' :
            case '2' :
            case '3' :
            case '4' :
            case '5' :
            case '6' :
            case '7' :
            case '8' :
            case '9' :
                if (reg_do_extmatch != REX_USE)
                    EMSG_RET_NULL (_ (e_z1_not_allowed));
                ret = regnode (ZREF +c - '0');
                re_has_z = REX_USE;
                break;
            case 's' :
                ret = regnode (MOPEN +0);
                if (re_mult_next ("\\zs") == FAIL)
                    return NULL;
                break;
            case 'e' :
                ret = regnode (MCLOSE +0);
                if (re_mult_next ("\\ze") == FAIL)
                    return NULL;
                break;
            default :
                EMSG_RET_NULL (_ ("E68: Invalid character after \\z"));
            }
        }
        break;
    case Magic ('%') :
        {
            c = no_Magic (getchr ());
            switch (c) {
            case '(' :
                if (one_exactly)
                    EMSG_ONE_RET_NULL;
                ret = reg (REG_NPAREN, &flags);
                if (ret == NULL)
                    return NULL;
                *flagp |= flags & (HASWIDTH | SPSTART | HASNL | HASLOOKBH);
                break;
            case '^' :
                ret = regnode (RE_BOF);
                break;
            case '$' :
                ret = regnode (RE_EOF);
                break;
            case '#' :
                ret = regnode (CURSOR);
                break;
            case 'V' :
                ret = regnode (RE_VISUAL);
                break;
            case 'C' :
                ret = regnode (RE_COMPOSING);
                break;
            case '[' :
                if (one_exactly)
                    EMSG_ONE_RET_NULL;
                {
                    char_u *lastbranch;
                    char_u *lastnode = NULL;
                    char_u *br;
                    ret = NULL;
                    while ((c = getchr ()) != ']') {
                        if (c == NUL)
                            EMSG2_RET_NULL (_ (e_missing_sb), reg_magic == MAGIC_ALL);
                        br = regnode (BRANCH);
                        if (ret == NULL)
                            ret = br;
                        else
                            regtail (lastnode, br);
                        ungetchr ();
                        one_exactly = TRUE;
                        lastnode = regatom (flagp);
                        one_exactly = FALSE;
                        if (lastnode == NULL)
                            return NULL;
                    }
                    if (ret == NULL)
                        EMSG2_RET_NULL (_ (e_empty_sb), reg_magic == MAGIC_ALL);
                    lastbranch = regnode (BRANCH);
                    br = regnode (NOTHING);
                    if (ret != JUST_CALC_SIZE) {
                        regtail (lastnode, br);
                        regtail (lastbranch, br);
                        for (br = ret; br != lastnode;) {
                            if (OP (br) == BRANCH) {
                                regtail (br, lastbranch);
                                br = OPERAND (br);
                            }
                            else
                                br = regnext (br);
                        }
                    }
                    *flagp &= ~(HASWIDTH | SIMPLE);
                    break;
                }
            case 'd' :
            case 'o' :
            case 'x' :
            case 'u' :
            case 'U' :
                {
                    long  i;
                    switch (c) {
                    case 'd' :
                        i = getdecchrs ();
                        break;
                    case 'o' :
                        i = getoctchrs ();
                        break;
                    case 'x' :
                        i = gethexchrs (2);
                        break;
                    case 'u' :
                        i = gethexchrs (4);
                        break;
                    case 'U' :
                        i = gethexchrs (8);
                        break;
                    default :
                        i = -1;
                        break;
                    }
                    if (i < 0)
                        EMSG2_RET_NULL (_ ("E678: Invalid character after %s%%[dxouU]"), reg_magic == MAGIC_ALL);
                    ret = regnode (EXACTLY);
                    if (i == 0)
                        regc (0x0a);
                    else
                        regc (i);
                    regc (NUL);
                    *flagp |= HASWIDTH;
                    break;
                }
            default :
                if (VIM_ISDIGIT (c) || c == '<' || c == '>' || c == '\'') {
                    long_u n = 0;
                    int cmp;
                    cmp = c;
                    if (cmp == '<' || cmp == '>')
                        c = getchr ();
                    while (VIM_ISDIGIT (c)) {
                        n = n * 10 + (c - '0');
                        c = getchr ();
                    }
                    if (c == '\'' && n == 0) {
                        c = getchr ();
                        ret = regnode (RE_MARK);
                        if (ret == JUST_CALC_SIZE)
                            regsize += 2;
                        else {
                            *regcode++ = c;
                            *regcode++ = cmp;
                        }
                        break;
                    }
                    else if (c == 'l' || c == 'c' || c == 'v') {
                        if (c == 'l') {
                            ret = regnode (RE_LNUM);
                            if (save_prev_at_start)
                                at_start = TRUE;
                        }
                        else if (c == 'c')
                            ret = regnode (RE_COL);
                        else
                            ret = regnode (RE_VCOL);
                        if (ret == JUST_CALC_SIZE)
                            regsize += 5;
                        else {
                            regcode = re_put_long (regcode, n);
                            *regcode++ = cmp;
                        }
                        break;
                    }
                }
                EMSG2_RET_NULL (_ ("E71: Invalid character after %s%%"), reg_magic == MAGIC_ALL);
            }
        }
        break;
    case Magic ('[') :
    collection :
        {
            char_u *lp;
            lp = skip_anyof (regparse);
            if (*lp == ']') {
                int startc = -1;
                int endc;
                if (*regparse == '^') {
                    ret = regnode (ANYBUT +extra);
                    regparse++;
                }
                else
                    ret = regnode (ANYOF +extra);
                if (*regparse == ']' || *regparse == '-') {
                    startc = *regparse;
                    regc (* regparse ++);
                }
                while (*regparse != NUL && *regparse != ']') {
                    if (*regparse == '-') {
                        ++regparse;
                        if (*regparse == ']' || *regparse == NUL || startc == -1 || (regparse[0] == '\\' && regparse[1] == 'n')) {
                            regc ('-');
                            startc = '-';
                        }
                        else {
                            endc = 0;
                            if (*regparse == '[')
                                endc = get_coll_element (&regparse);
                            if (endc == 0) {
                                endc = *regparse++;
                            }
                            if (endc == '\\' && !reg_cpo_lit && !reg_cpo_bsl)
                                endc = coll_get_char ();
                            if (startc > endc)
                                EMSG_RET_NULL (_ (e_reverse_range));
                            {
                                while (++startc <= endc)
                                    regc (startc);
                            }
                            startc = -1;
                        }
                    }
                    else if (*regparse == '\\' && !reg_cpo_bsl && (vim_strchr (REGEXP_INRANGE, regparse[1]) != NULL || (!reg_cpo_lit && vim_strchr (REGEXP_ABBR, regparse[1]) != NULL))) {
                        regparse++;
                        if (*regparse == 'n') {
                            if (ret != JUST_CALC_SIZE) {
                                if (*ret == ANYOF) {
                                    *ret = ANYOF + ADD_NL;
                                    *flagp |= HASNL;
                                }
                            }
                            regparse++;
                            startc = -1;
                        }
                        else if (*regparse == 'd' || *regparse == 'o' || *regparse == 'x' || *regparse == 'u' || *regparse == 'U') {
                            startc = coll_get_char ();
                            if (startc == 0)
                                regc (0x0a);
                            else
                                regc (startc);
                        }
                        else {
                            startc = backslash_trans (*regparse++);
                            regc (startc);
                        }
                    }
                    else if (*regparse == '[') {
                        int c_class;
                        int cu;
                        c_class = get_char_class (&regparse);
                        startc = -1;
                        switch (c_class) {
                        case CLASS_NONE :
                            c_class = get_equi_class (&regparse);
                            if (c_class != 0) {
                                reg_equi_class (c_class);
                            }
                            else if ((c_class = get_coll_element (&regparse)) != 0) {
                                regmbc (c_class);
                            }
                            else {
                                startc = *regparse++;
                                regc (startc);
                            }
                            break;
                        case CLASS_ALNUM :
                            for (cu = 1; cu < 128; cu++)
                                if (isalnum (cu))
                                    regmbc (cu);
                            break;
                        case CLASS_ALPHA :
                            for (cu = 1; cu < 128; cu++)
                                if (isalpha (cu))
                                    regmbc (cu);
                            break;
                        case CLASS_BLANK :
                            regc (' ');
                            regc ('\t');
                            break;
                        case CLASS_CNTRL :
                            for (cu = 1; cu <= 127; cu++)
                                if (iscntrl (cu))
                                    regmbc (cu);
                            break;
                        case CLASS_DIGIT :
                            for (cu = 1; cu <= 127; cu++)
                                if (VIM_ISDIGIT (cu))
                                    regmbc (cu);
                            break;
                        case CLASS_GRAPH :
                            for (cu = 1; cu <= 127; cu++)
                                if (isgraph (cu))
                                    regmbc (cu);
                            break;
                        case CLASS_LOWER :
                            for (cu = 1; cu <= 255; cu++)
                                if (MB_ISLOWER (cu) && cu != 170 && cu != 186)
                                    regmbc (cu);
                            break;
                        case CLASS_PRINT :
                            for (cu = 1; cu <= 255; cu++)
                                if (vim_isprintc (cu))
                                    regmbc (cu);
                            break;
                        case CLASS_PUNCT :
                            for (cu = 1; cu < 128; cu++)
                                if (ispunct (cu))
                                    regmbc (cu);
                            break;
                        case CLASS_SPACE :
                            for (cu = 9; cu <= 13; cu++)
                                regc (cu);
                            regc (' ');
                            break;
                        case CLASS_UPPER :
                            for (cu = 1; cu <= 255; cu++)
                                if (MB_ISUPPER (cu))
                                    regmbc (cu);
                            break;
                        case CLASS_XDIGIT :
                            for (cu = 1; cu <= 255; cu++)
                                if (vim_isxdigit (cu))
                                    regmbc (cu);
                            break;
                        case CLASS_TAB :
                            regc ('\t');
                            break;
                        case CLASS_RETURN :
                            regc ('\r');
                            break;
                        case CLASS_BACKSPACE :
                            regc ('\b');
                            break;
                        case CLASS_ESCAPE :
                            regc ('\033');
                            break;
                        }
                    }
                    else {
                        {
                            startc = *regparse++;
                            regc (startc);
                        }
                    }
                }
                regc (NUL);
                prevchr_len = 1;
                if (*regparse != ']')
                    EMSG_RET_NULL (_ (e_toomsbra));
                skipchr ();
                *flagp |= HASWIDTH | SIMPLE;
                break;
            }
            else if (reg_strict)
                EMSG2_RET_NULL (_ (e_missingbracket), reg_magic > MAGIC_OFF);
        }
    default :
        {
            int len;
            ret = regnode (EXACTLY);
            for (len = 0; c != NUL && (len == 0 || (re_multi_type (peekchr ()) == NOT_MULTI && !one_exactly && !is_Magic (c))); ++len) {
                c = no_Magic (c);
                regc (c);
                c = getchr ();
            }
            ungetchr ();
            regc (NUL);
            *flagp |= HASWIDTH;
            if (len == 1)
                *flagp |= SIMPLE;
        }
        break;
    }
    return ret;
}

static int getchr (void) {
    int chr = peekchr ();
    skipchr ();
    return chr;
}

static void regc (int b) {
    if (regcode == JUST_CALC_SIZE)
        regsize++;
    else
        *regcode++ = b;
}

static void regtail (char_u *p, char_u *val) {
    char_u *scan;
    char_u *temp;
    int offset;
    if (p == JUST_CALC_SIZE)
        return;
    scan = p;
    for (;;) {
        temp = regnext (scan);
        if (temp == NULL)
            break;
        scan = temp;
    }
    if (OP (scan) == BACK)
        offset = (int) (scan - val);
    else
        offset = (int) (val - scan);
    if (offset > 0xffff)
        reg_toolong = TRUE;
    else {
        *(scan + 1) = (char_u) (((unsigned ) offset >> 8) & 0377);
        *(scan + 2) = (char_u) (offset & 0377);
    }
}

static char_u *regnext (char_u *p) {
    int offset;
    if (p == JUST_CALC_SIZE || reg_toolong)
        return NULL;
    offset = NEXT (p);
    if (offset == 0)
        return NULL;
    if (OP (p) == BACK)
        return p - offset;
    else
        return p + offset;
}

static void ungetchr (void) {
    nextchr = curchr;
    curchr = prevchr;
    prevchr = prevprevchr;
    at_start = prev_at_start;
    prev_at_start = FALSE;
    regparse -= prevchr_len;
}

static long  getdecchrs (void) {
    long_u nr = 0;
    int c;
    int i;
    for (i = 0;; ++i) {
        c = regparse[0];
        if (c < '0' || c > '9')
            break;
        nr *= 10;
        nr += c - '0';
        ++regparse;
        curchr = -1;
    }
    if (i == 0)
        return -1;
    return (long ) nr;
}

static long  getoctchrs (void) {
    long_u nr = 0;
    int c;
    int i;
    for (i = 0; i < 3 && nr < 040; ++i) {
        c = regparse[0];
        if (c < '0' || c > '7')
            break;
        nr <<= 3;
        nr |= hex2nr (c);
        ++regparse;
    }
    if (i == 0)
        return -1;
    return (long ) nr;
}

static long  gethexchrs (int maxinputlen) {
    long_u nr = 0;
    int c;
    int i;
    for (i = 0; i < maxinputlen; ++i) {
        c = regparse[0];
        if (!vim_isxdigit (c))
            break;
        nr <<= 4;
        nr |= hex2nr (c);
        ++regparse;
    }
    if (i == 0)
        return -1;
    return (long ) nr;
}

static char_u *re_put_long (char_u *p, long_u val) {
    *p++ = (char_u) ((val >> 24) & 0377);
    *p++ = (char_u) ((val >> 16) & 0377);
    *p++ = (char_u) ((val >> 8) & 0377);
    *p++ = (char_u) (val & 0377);
    return p;
}

static int coll_get_char (void) {
    long  nr = -1;
    switch (*regparse++) {
    case 'd' :
        nr = getdecchrs ();
        break;
    case 'o' :
        nr = getoctchrs ();
        break;
    case 'x' :
        nr = gethexchrs (2);
        break;
    case 'u' :
        nr = gethexchrs (4);
        break;
    case 'U' :
        nr = gethexchrs (8);
        break;
    }
    if (nr < 0) {
        --regparse;
        nr = '\\';
    }
    return nr;
}

static void reg_equi_class (int c) {
    {
        switch (c) {
        case 'A' :
        case 0xc0 :
        case 0xc1 :
        case 0xc2 :
        case 0xc3 :
        case 0xc4 :
        case 0xc5 :
            CASEMBC (0x100)
            CASEMBC (0x102)
            CASEMBC (0x104)
            CASEMBC (0x1cd)
            CASEMBC (0x1de)
            CASEMBC (0x1e0)
            CASEMBC (0x1ea2)
            regmbc ('A');
            regmbc (0xc0);
            regmbc (0xc1);
            regmbc (0xc2);
            regmbc (0xc3);
            regmbc (0xc4);
            regmbc (0xc5);
            REGMBC (0x100)
            REGMBC (0x102)
            REGMBC (0x104)
            REGMBC (0x1cd)
            REGMBC (0x1de)
            REGMBC (0x1e0)
            REGMBC (0x1ea2)
            return;
        case 'B' :
            CASEMBC (0x1e02)
            CASEMBC (0x1e06)
            regmbc ('B');
            REGMBC (0x1e02)
            REGMBC (0x1e06)
            return;
        case 'C' :
        case 0xc7 :
            CASEMBC (0x106)
            CASEMBC (0x108)
            CASEMBC (0x10a)
            CASEMBC (0x10c)
            regmbc ('C');
            regmbc (0xc7);
            REGMBC (0x106)
            REGMBC (0x108)
            REGMBC (0x10a)
            REGMBC (0x10c)
            return;
        case 'D' :
            CASEMBC (0x10e)
            CASEMBC (0x110)
            CASEMBC (0x1e0a)
            CASEMBC (0x1e0e)
            CASEMBC (0x1e10)
            regmbc ('D');
            REGMBC (0x10e)
            REGMBC (0x110)
            REGMBC (0x1e0a)
            REGMBC (0x1e0e)
            REGMBC (0x1e10)
            return;
        case 'E' :
        case 0xc8 :
        case 0xc9 :
        case 0xca :
        case 0xcb :
            CASEMBC (0x112)
            CASEMBC (0x114)
            CASEMBC (0x116)
            CASEMBC (0x118)
            CASEMBC (0x11a)
            CASEMBC (0x1eba)
            CASEMBC (0x1ebc)
            regmbc ('E');
            regmbc (0xc8);
            regmbc (0xc9);
            regmbc (0xca);
            regmbc (0xcb);
            REGMBC (0x112)
            REGMBC (0x114)
            REGMBC (0x116)
            REGMBC (0x118)
            REGMBC (0x11a)
            REGMBC (0x1eba)
            REGMBC (0x1ebc)
            return;
        case 'F' :
            CASEMBC (0x1e1e)
            regmbc ('F');
            REGMBC (0x1e1e)
            return;
        case 'G' :
            CASEMBC (0x11c)
            CASEMBC (0x11e)
            CASEMBC (0x120)
            CASEMBC (0x122)
            CASEMBC (0x1e4)
            CASEMBC (0x1e6)
            CASEMBC (0x1f4)
            CASEMBC (0x1e20)
            regmbc ('G');
            REGMBC (0x11c)
            REGMBC (0x11e)
            REGMBC (0x120)
            REGMBC (0x122)
            REGMBC (0x1e4)
            REGMBC (0x1e6)
            REGMBC (0x1f4)
            REGMBC (0x1e20)
            return;
        case 'H' :
            CASEMBC (0x124)
            CASEMBC (0x126)
            CASEMBC (0x1e22)
            CASEMBC (0x1e26)
            CASEMBC (0x1e28)
            regmbc ('H');
            REGMBC (0x124)
            REGMBC (0x126)
            REGMBC (0x1e22)
            REGMBC (0x1e26)
            REGMBC (0x1e28)
            return;
        case 'I' :
        case 0xcc :
        case 0xcd :
        case 0xce :
        case 0xcf :
            CASEMBC (0x128)
            CASEMBC (0x12a)
            CASEMBC (0x12c)
            CASEMBC (0x12e)
            CASEMBC (0x130)
            CASEMBC (0x1cf)
            CASEMBC (0x1ec8)
            regmbc ('I');
            regmbc (0xcc);
            regmbc (0xcd);
            regmbc (0xce);
            regmbc (0xcf);
            REGMBC (0x128)
            REGMBC (0x12a)
            REGMBC (0x12c)
            REGMBC (0x12e)
            REGMBC (0x130)
            REGMBC (0x1cf)
            REGMBC (0x1ec8)
            return;
        case 'J' :
            CASEMBC (0x134)
            regmbc ('J');
            REGMBC (0x134)
            return;
        case 'K' :
            CASEMBC (0x136)
            CASEMBC (0x1e8)
            CASEMBC (0x1e30)
            CASEMBC (0x1e34)
            regmbc ('K');
            REGMBC (0x136)
            REGMBC (0x1e8)
            REGMBC (0x1e30)
            REGMBC (0x1e34)
            return;
        case 'L' :
            CASEMBC (0x139)
            CASEMBC (0x13b)
            CASEMBC (0x13d)
            CASEMBC (0x13f)
            CASEMBC (0x141)
            CASEMBC (0x1e3a)
            regmbc ('L');
            REGMBC (0x139)
            REGMBC (0x13b)
            REGMBC (0x13d)
            REGMBC (0x13f)
            REGMBC (0x141)
            REGMBC (0x1e3a)
            return;
        case 'M' :
            CASEMBC (0x1e3e)
            CASEMBC (0x1e40)
            regmbc ('M');
            REGMBC (0x1e3e)
            REGMBC (0x1e40)
            return;
        case 'N' :
        case 0xd1 :
            CASEMBC (0x143)
            CASEMBC (0x145)
            CASEMBC (0x147)
            CASEMBC (0x1e44)
            CASEMBC (0x1e48)
            regmbc ('N');
            regmbc (0xd1);
            REGMBC (0x143)
            REGMBC (0x145)
            REGMBC (0x147)
            REGMBC (0x1e44)
            REGMBC (0x1e48)
            return;
        case 'O' :
        case 0xd2 :
        case 0xd3 :
        case 0xd4 :
        case 0xd5 :
        case 0xd6 :
        case 0xd8 :
            CASEMBC (0x14c)
            CASEMBC (0x14e)
            CASEMBC (0x150)
            CASEMBC (0x1a0)
            CASEMBC (0x1d1)
            CASEMBC (0x1ea)
            CASEMBC (0x1ec)
            CASEMBC (0x1ece)
            regmbc ('O');
            regmbc (0xd2);
            regmbc (0xd3);
            regmbc (0xd4);
            regmbc (0xd5);
            regmbc (0xd6);
            regmbc (0xd8);
            REGMBC (0x14c)
            REGMBC (0x14e)
            REGMBC (0x150)
            REGMBC (0x1a0)
            REGMBC (0x1d1)
            REGMBC (0x1ea)
            REGMBC (0x1ec)
            REGMBC (0x1ece)
            return;
        case 'P' :
        case 0x1e54 :
        case 0x1e56 :
            regmbc ('P');
            REGMBC (0x1e54)
            REGMBC (0x1e56)
            return;
        case 'R' :
            CASEMBC (0x154)
            CASEMBC (0x156)
            CASEMBC (0x158)
            CASEMBC (0x1e58)
            CASEMBC (0x1e5e)
            regmbc ('R');
            REGMBC (0x154)
            REGMBC (0x156)
            REGMBC (0x158)
            REGMBC (0x1e58)
            REGMBC (0x1e5e)
            return;
        case 'S' :
            CASEMBC (0x15a)
            CASEMBC (0x15c)
            CASEMBC (0x15e)
            CASEMBC (0x160)
            CASEMBC (0x1e60)
            regmbc ('S');
            REGMBC (0x15a)
            REGMBC (0x15c)
            REGMBC (0x15e)
            REGMBC (0x160)
            REGMBC (0x1e60)
            return;
        case 'T' :
            CASEMBC (0x162)
            CASEMBC (0x164)
            CASEMBC (0x166)
            CASEMBC (0x1e6a)
            CASEMBC (0x1e6e)
            regmbc ('T');
            REGMBC (0x162)
            REGMBC (0x164)
            REGMBC (0x166)
            REGMBC (0x1e6a)
            REGMBC (0x1e6e)
            return;
        case 'U' :
        case 0xd9 :
        case 0xda :
        case 0xdb :
        case 0xdc :
            CASEMBC (0x168)
            CASEMBC (0x16a)
            CASEMBC (0x16c)
            CASEMBC (0x16e)
            CASEMBC (0x170)
            CASEMBC (0x172)
            CASEMBC (0x1af)
            CASEMBC (0x1d3)
            CASEMBC (0x1ee6)
            regmbc ('U');
            regmbc (0xd9);
            regmbc (0xda);
            regmbc (0xdb);
            regmbc (0xdc);
            REGMBC (0x168)
            REGMBC (0x16a)
            REGMBC (0x16c)
            REGMBC (0x16e)
            REGMBC (0x170)
            REGMBC (0x172)
            REGMBC (0x1af)
            REGMBC (0x1d3)
            REGMBC (0x1ee6)
            return;
        case 'V' :
            CASEMBC (0x1e7c)
            regmbc ('V');
            REGMBC (0x1e7c)
            return;
        case 'W' :
            CASEMBC (0x174)
            CASEMBC (0x1e80)
            CASEMBC (0x1e82)
            CASEMBC (0x1e84)
            CASEMBC (0x1e86)
            regmbc ('W');
            REGMBC (0x174)
            REGMBC (0x1e80)
            REGMBC (0x1e82)
            REGMBC (0x1e84)
            REGMBC (0x1e86)
            return;
        case 'X' :
            CASEMBC (0x1e8a)
            CASEMBC (0x1e8c)
            regmbc ('X');
            REGMBC (0x1e8a)
            REGMBC (0x1e8c)
            return;
        case 'Y' :
        case 0xdd :
            CASEMBC (0x176)
            CASEMBC (0x178)
            CASEMBC (0x1e8e)
            CASEMBC (0x1ef2)
            CASEMBC (0x1ef6)
            CASEMBC (0x1ef8)
            regmbc ('Y');
            regmbc (0xdd);
            REGMBC (0x176)
            REGMBC (0x178)
            REGMBC (0x1e8e)
            REGMBC (0x1ef2)
            REGMBC (0x1ef6)
            REGMBC (0x1ef8)
            return;
        case 'Z' :
            CASEMBC (0x179)
            CASEMBC (0x17b)
            CASEMBC (0x17d)
            CASEMBC (0x1b5)
            CASEMBC (0x1e90)
            CASEMBC (0x1e94)
            regmbc ('Z');
            REGMBC (0x179)
            REGMBC (0x17b)
            REGMBC (0x17d)
            REGMBC (0x1b5)
            REGMBC (0x1e90)
            REGMBC (0x1e94)
            return;
        case 'a' :
        case 0xe0 :
        case 0xe1 :
        case 0xe2 :
        case 0xe3 :
        case 0xe4 :
        case 0xe5 :
            CASEMBC (0x101)
            CASEMBC (0x103)
            CASEMBC (0x105)
            CASEMBC (0x1ce)
            CASEMBC (0x1df)
            CASEMBC (0x1e1)
            CASEMBC (0x1ea3)
            regmbc ('a');
            regmbc (0xe0);
            regmbc (0xe1);
            regmbc (0xe2);
            regmbc (0xe3);
            regmbc (0xe4);
            regmbc (0xe5);
            REGMBC (0x101)
            REGMBC (0x103)
            REGMBC (0x105)
            REGMBC (0x1ce)
            REGMBC (0x1df)
            REGMBC (0x1e1)
            REGMBC (0x1ea3)
            return;
        case 'b' :
            CASEMBC (0x1e03)
            CASEMBC (0x1e07)
            regmbc ('b');
            REGMBC (0x1e03)
            REGMBC (0x1e07)
            return;
        case 'c' :
        case 0xe7 :
            CASEMBC (0x107)
            CASEMBC (0x109)
            CASEMBC (0x10b)
            CASEMBC (0x10d)
            regmbc ('c');
            regmbc (0xe7);
            REGMBC (0x107)
            REGMBC (0x109)
            REGMBC (0x10b)
            REGMBC (0x10d)
            return;
        case 'd' :
            CASEMBC (0x10f)
            CASEMBC (0x111)
            CASEMBC (0x1e0b)
            CASEMBC (0x1e0f)
            CASEMBC (0x1e11)
            regmbc ('d');
            REGMBC (0x10f)
            REGMBC (0x111)
            REGMBC (0x1e0b)
            REGMBC (0x1e0f)
            REGMBC (0x1e11)
            return;
        case 'e' :
        case 0xe8 :
        case 0xe9 :
        case 0xea :
        case 0xeb :
            CASEMBC (0x113)
            CASEMBC (0x115)
            CASEMBC (0x117)
            CASEMBC (0x119)
            CASEMBC (0x11b)
            CASEMBC (0x1ebb)
            CASEMBC (0x1ebd)
            regmbc ('e');
            regmbc (0xe8);
            regmbc (0xe9);
            regmbc (0xea);
            regmbc (0xeb);
            REGMBC (0x113)
            REGMBC (0x115)
            REGMBC (0x117)
            REGMBC (0x119)
            REGMBC (0x11b)
            REGMBC (0x1ebb)
            REGMBC (0x1ebd)
            return;
        case 'f' :
            CASEMBC (0x1e1f)
            regmbc ('f');
            REGMBC (0x1e1f)
            return;
        case 'g' :
            CASEMBC (0x11d)
            CASEMBC (0x11f)
            CASEMBC (0x121)
            CASEMBC (0x123)
            CASEMBC (0x1e5)
            CASEMBC (0x1e7)
            CASEMBC (0x1f5)
            CASEMBC (0x1e21)
            regmbc ('g');
            REGMBC (0x11d)
            REGMBC (0x11f)
            REGMBC (0x121)
            REGMBC (0x123)
            REGMBC (0x1e5)
            REGMBC (0x1e7)
            REGMBC (0x1f5)
            REGMBC (0x1e21)
            return;
        case 'h' :
            CASEMBC (0x125)
            CASEMBC (0x127)
            CASEMBC (0x1e23)
            CASEMBC (0x1e27)
            CASEMBC (0x1e29)
            CASEMBC (0x1e96)
            regmbc ('h');
            REGMBC (0x125)
            REGMBC (0x127)
            REGMBC (0x1e23)
            REGMBC (0x1e27)
            REGMBC (0x1e29)
            REGMBC (0x1e96)
            return;
        case 'i' :
        case 0xec :
        case 0xed :
        case 0xee :
        case 0xef :
            CASEMBC (0x129)
            CASEMBC (0x12b)
            CASEMBC (0x12d)
            CASEMBC (0x12f)
            CASEMBC (0x1d0)
            CASEMBC (0x1ec9)
            regmbc ('i');
            regmbc (0xec);
            regmbc (0xed);
            regmbc (0xee);
            regmbc (0xef);
            REGMBC (0x129)
            REGMBC (0x12b)
            REGMBC (0x12d)
            REGMBC (0x12f)
            REGMBC (0x1d0)
            REGMBC (0x1ec9)
            return;
        case 'j' :
            CASEMBC (0x135)
            CASEMBC (0x1f0)
            regmbc ('j');
            REGMBC (0x135)
            REGMBC (0x1f0)
            return;
        case 'k' :
            CASEMBC (0x137)
            CASEMBC (0x1e9)
            CASEMBC (0x1e31)
            CASEMBC (0x1e35)
            regmbc ('k');
            REGMBC (0x137)
            REGMBC (0x1e9)
            REGMBC (0x1e31)
            REGMBC (0x1e35)
            return;
        case 'l' :
            CASEMBC (0x13a)
            CASEMBC (0x13c)
            CASEMBC (0x13e)
            CASEMBC (0x140)
            CASEMBC (0x142)
            CASEMBC (0x1e3b)
            regmbc ('l');
            REGMBC (0x13a)
            REGMBC (0x13c)
            REGMBC (0x13e)
            REGMBC (0x140)
            REGMBC (0x142)
            REGMBC (0x1e3b)
            return;
        case 'm' :
            CASEMBC (0x1e3f)
            CASEMBC (0x1e41)
            regmbc ('m');
            REGMBC (0x1e3f)
            REGMBC (0x1e41)
            return;
        case 'n' :
        case 0xf1 :
            CASEMBC (0x144)
            CASEMBC (0x146)
            CASEMBC (0x148)
            CASEMBC (0x149)
            CASEMBC (0x1e45)
            CASEMBC (0x1e49)
            regmbc ('n');
            regmbc (0xf1);
            REGMBC (0x144)
            REGMBC (0x146)
            REGMBC (0x148)
            REGMBC (0x149)
            REGMBC (0x1e45)
            REGMBC (0x1e49)
            return;
        case 'o' :
        case 0xf2 :
        case 0xf3 :
        case 0xf4 :
        case 0xf5 :
        case 0xf6 :
        case 0xf8 :
            CASEMBC (0x14d)
            CASEMBC (0x14f)
            CASEMBC (0x151)
            CASEMBC (0x1a1)
            CASEMBC (0x1d2)
            CASEMBC (0x1eb)
            CASEMBC (0x1ed)
            CASEMBC (0x1ecf)
            regmbc ('o');
            regmbc (0xf2);
            regmbc (0xf3);
            regmbc (0xf4);
            regmbc (0xf5);
            regmbc (0xf6);
            regmbc (0xf8);
            REGMBC (0x14d)
            REGMBC (0x14f)
            REGMBC (0x151)
            REGMBC (0x1a1)
            REGMBC (0x1d2)
            REGMBC (0x1eb)
            REGMBC (0x1ed)
            REGMBC (0x1ecf)
            return;
        case 'p' :
            CASEMBC (0x1e55)
            CASEMBC (0x1e57)
            regmbc ('p');
            REGMBC (0x1e55)
            REGMBC (0x1e57)
            return;
        case 'r' :
            CASEMBC (0x155)
            CASEMBC (0x157)
            CASEMBC (0x159)
            CASEMBC (0x1e59)
            CASEMBC (0x1e5f)
            regmbc ('r');
            REGMBC (0x155)
            REGMBC (0x157)
            REGMBC (0x159)
            REGMBC (0x1e59)
            REGMBC (0x1e5f)
            return;
        case 's' :
            CASEMBC (0x15b)
            CASEMBC (0x15d)
            CASEMBC (0x15f)
            CASEMBC (0x161)
            CASEMBC (0x1e61)
            regmbc ('s');
            REGMBC (0x15b)
            REGMBC (0x15d)
            REGMBC (0x15f)
            REGMBC (0x161)
            REGMBC (0x1e61)
            return;
        case 't' :
            CASEMBC (0x163)
            CASEMBC (0x165)
            CASEMBC (0x167)
            CASEMBC (0x1e6b)
            CASEMBC (0x1e6f)
            CASEMBC (0x1e97)
            regmbc ('t');
            REGMBC (0x163)
            REGMBC (0x165)
            REGMBC (0x167)
            REGMBC (0x1e6b)
            REGMBC (0x1e6f)
            REGMBC (0x1e97)
            return;
        case 'u' :
        case 0xf9 :
        case 0xfa :
        case 0xfb :
        case 0xfc :
            CASEMBC (0x169)
            CASEMBC (0x16b)
            CASEMBC (0x16d)
            CASEMBC (0x16f)
            CASEMBC (0x171)
            CASEMBC (0x173)
            CASEMBC (0x1b0)
            CASEMBC (0x1d4)
            CASEMBC (0x1ee7)
            regmbc ('u');
            regmbc (0xf9);
            regmbc (0xfa);
            regmbc (0xfb);
            regmbc (0xfc);
            REGMBC (0x169)
            REGMBC (0x16b)
            REGMBC (0x16d)
            REGMBC (0x16f)
            REGMBC (0x171)
            REGMBC (0x173)
            REGMBC (0x1b0)
            REGMBC (0x1d4)
            REGMBC (0x1ee7)
            return;
        case 'v' :
            CASEMBC (0x1e7d)
            regmbc ('v');
            REGMBC (0x1e7d)
            return;
        case 'w' :
            CASEMBC (0x175)
            CASEMBC (0x1e81)
            CASEMBC (0x1e83)
            CASEMBC (0x1e85)
            CASEMBC (0x1e87)
            CASEMBC (0x1e98)
            regmbc ('w');
            REGMBC (0x175)
            REGMBC (0x1e81)
            REGMBC (0x1e83)
            REGMBC (0x1e85)
            REGMBC (0x1e87)
            REGMBC (0x1e98)
            return;
        case 'x' :
            CASEMBC (0x1e8b)
            CASEMBC (0x1e8d)
            regmbc ('x');
            REGMBC (0x1e8b)
            REGMBC (0x1e8d)
            return;
        case 'y' :
        case 0xfd :
        case 0xff :
            CASEMBC (0x177)
            CASEMBC (0x1e8f)
            CASEMBC (0x1e99)
            CASEMBC (0x1ef3)
            CASEMBC (0x1ef7)
            CASEMBC (0x1ef9)
            regmbc ('y');
            regmbc (0xfd);
            regmbc (0xff);
            REGMBC (0x177)
            REGMBC (0x1e8f)
            REGMBC (0x1e99)
            REGMBC (0x1ef3)
            REGMBC (0x1ef7)
            REGMBC (0x1ef9)
            return;
        case 'z' :
            CASEMBC (0x17a)
            CASEMBC (0x17c)
            CASEMBC (0x17e)
            CASEMBC (0x1b6)
            CASEMBC (0x1e91)
            CASEMBC (0x1e95)
            regmbc ('z');
            REGMBC (0x17a)
            REGMBC (0x17c)
            REGMBC (0x17e)
            REGMBC (0x1b6)
            REGMBC (0x1e91)
            REGMBC (0x1e95)
            return;
        }
    }
    regmbc (c);
}

static int re_multi_type (int c) {
    if (c == Magic ('@') || c == Magic ('=') || c == Magic ('?'))
        return MULTI_ONE;
    if (c == Magic ('*') || c == Magic ('+') || c == Magic ('{'))
        return MULTI_MULT;
    return NOT_MULTI;
}

#define HASWIDTH	0x1	/* Known never to match null string. */

#define SIMPLE		0x2	/* Simple enough to be STAR/PLUS operand. */

#define SPSTART		0x4	/* Starts with * or +. */

#define HASNL		0x8	/* Contains some \n. */

#define HASLOOKBH	0x10	/* Contains "\@<=" or "\@<!". */

#define WORST		0	/* Worst case. */

#define JUST_CALC_SIZE	((char_u *) -1)

static void reginsert (int op, char_u *opnd) {
    char_u *src;
    char_u *dst;
    char_u *place;
    if (regcode == JUST_CALC_SIZE) {
        regsize += 3;
        return;
    }
    src = regcode;
    regcode += 3;
    dst = regcode;
    while (src > opnd)
        *--dst = *--src;
    place = opnd;
    *place++ = op;
    *place++ = NUL;
    *place = NUL;
}

static void regoptail (char_u *p, char_u *val) {
    if (p == NULL || p == JUST_CALC_SIZE || (OP (p) != BRANCH && (OP (p) < BRACE_COMPLEX || OP (p) > BRACE_COMPLEX + 9)))
        return;
    regtail (OPERAND (p), val);
}

static void reginsert_nr (int op, long  val, char_u *opnd) {
    char_u *src;
    char_u *dst;
    char_u *place;
    if (regcode == JUST_CALC_SIZE) {
        regsize += 7;
        return;
    }
    src = regcode;
    regcode += 7;
    dst = regcode;
    while (src > opnd)
        *--dst = *--src;
    place = opnd;
    *place++ = op;
    *place++ = NUL;
    *place++ = NUL;
    place = re_put_long (place, (long_u) val);
}

static int read_limits (long  *minval, long  *maxval) {
    int reverse = FALSE;
    char_u *first_char;
    long  tmp;
    if (*regparse == '-') {
        regparse++;
        reverse = TRUE;
    }
    first_char = regparse;
    *minval = getdigits (&regparse);
    if (*regparse == ',') {
        if (vim_isdigit (*++regparse))
            *maxval = getdigits (&regparse);
        else
            *maxval = MAX_LIMIT;
    }
    else if (VIM_ISDIGIT (*first_char))
        *maxval = *minval;
    else
        *maxval = MAX_LIMIT;
    if (*regparse == '\\')
        regparse++;
    if (*regparse != '}') {
        sprintf ((char *) IObuff, _ ("E554: Syntax error in %s{...}"), reg_magic == MAGIC_ALL ? "" : "\\");
        EMSG_RET_FAIL (IObuff);
    }
    if ((!reverse && *minval > *maxval) || (reverse && *minval < *maxval)) {
        tmp = *minval;
        *minval = *maxval;
        *maxval = tmp;
    }
    skipchr ();
    return OK;
}

static void reginsert_limits (int op, long  minval, long  maxval, char_u *opnd) {
    char_u *src;
    char_u *dst;
    char_u *place;
    if (regcode == JUST_CALC_SIZE) {
        regsize += 11;
        return;
    }
    src = regcode;
    regcode += 11;
    dst = regcode;
    while (src > opnd)
        *--dst = *--src;
    place = opnd;
    *place++ = op;
    *place++ = NUL;
    *place++ = NUL;
    place = re_put_long (place, (long_u) minval);
    place = re_put_long (place, (long_u) maxval);
    regtail (opnd, place);
}

int vim_regsub (regmatch_T *rmp, char_u *source, typval_T *expr, char_u *dest, int copy, int magic, int backslash) {
    int result;
    regexec_T rex_save;
    int rex_in_use_save = rex_in_use;
    if (rex_in_use)
        rex_save = rex;
    rex_in_use = TRUE;
    rex.reg_match = rmp;
    rex.reg_mmatch = NULL;
    rex.reg_maxline = 0;
    rex.reg_buf = curbuf;
    rex.reg_line_lbr = TRUE;
    result = vim_regsub_both (source, expr, dest, copy, magic, backslash);
    rex_in_use = rex_in_use_save;
    if (rex_in_use)
        rex = rex_save;
    return result;
}

static int vim_regsub_both (char_u *source, typval_T *expr, char_u *dest, int copy, int magic, int backslash) {
    char_u *src;
    char_u *dst;
    char_u *s;
    int c;
    int cc;
    int no = -1;
    fptr_T func_all = (fptr_T) NULL;
    fptr_T func_one = (fptr_T) NULL;
    linenr_T clnum = 0;
    int len = 0;
    static char_u *eval_result = NULL;
    if ((source == NULL && expr == NULL) || dest == NULL) {
        EMSG (_ (e_null));
        return 0;
    }
    if (prog_magic_wrong ())
        return 0;
    src = source;
    dst = dest;
    if (expr != NULL || (source[0] == '\\' && source[1] == '=')) {
        if (copy) {
            if (eval_result != NULL) {
                STRCPY (dest, eval_result);
                dst += STRLEN (eval_result);
                VIM_CLEAR (eval_result);
            }
        }
        else {
            int prev_can_f_submatch = can_f_submatch;
            regsubmatch_T rsm_save;
            vim_free (eval_result);
            if (can_f_submatch)
                rsm_save = rsm;
            can_f_submatch = TRUE;
            rsm.sm_match = rex.reg_match;
            rsm.sm_mmatch = rex.reg_mmatch;
            rsm.sm_firstlnum = rex.reg_firstlnum;
            rsm.sm_maxline = rex.reg_maxline;
            rsm.sm_line_lbr = rex.reg_line_lbr;
            if (expr != NULL) {
                typval_T argv [2];
                int dummy;
                char_u buf [NUMBUFLEN];
                typval_T rettv;
                staticList10_T matchList;
                rettv.v_type = VAR_STRING;
                rettv.vval.v_string = NULL;
                argv[0].v_type = VAR_LIST;
                argv[0].vval.v_list = &matchList.sl_list;
                matchList.sl_list.lv_len = 0;
                if (expr->v_type == VAR_FUNC) {
                    s = expr->vval.v_string;
                    call_func (s, (int) STRLEN (s), & rettv, 1, argv, fill_submatch_list, 0L, 0L, & dummy, TRUE, NULL, NULL);
                }
                else if (expr->v_type == VAR_PARTIAL) {
                    partial_T *partial = expr->vval.v_partial;
                    s = partial_name (partial);
                    call_func (s, (int) STRLEN (s), & rettv, 1, argv, fill_submatch_list, 0L, 0L, & dummy, TRUE, partial, NULL);
                }
                if (matchList.sl_list.lv_len > 0)
                    clear_submatch_list (&matchList);
                eval_result = get_tv_string_buf_chk (&rettv, buf);
                if (eval_result != NULL)
                    eval_result = vim_strsave (eval_result);
                clear_tv (& rettv);
            }
            else
                eval_result = eval_to_string (source +2, NULL, TRUE);
            if (eval_result != NULL) {
                int had_backslash = FALSE;
                for (s = eval_result; *s != NUL; MB_PTR_ADV (s)) {
                    if (*s == NL && !rsm.sm_line_lbr)
                        *s = CAR;
                    else if (*s == '\\' && s[1] != NUL) {
                        ++s;
                        if (*s == NL && !rsm.sm_line_lbr)
                            *s = CAR;
                        had_backslash = TRUE;
                    }
                }
                if (had_backslash && backslash) {
                    s = vim_strsave_escaped (eval_result, (char_u *) "\\");
                    if (s != NULL) {
                        vim_free (eval_result);
                        eval_result = s;
                    }
                }
                dst += STRLEN (eval_result);
            }
            can_f_submatch = prev_can_f_submatch;
            if (can_f_submatch)
                rsm = rsm_save;
        }
    }
    else
        while ((c = *src++) != NUL) {
            if (c == '&' && magic)
                no = 0;
            else if (c == '\\' && *src != NUL) {
                if (*src == '&' && !magic) {
                    ++src;
                    no = 0;
                }
                else if ('0' <= *src && *src <= '9') {
                    no = *src++ - '0';
                }
                else if (vim_strchr ((char_u *) "uUlLeE", *src)) {
                    switch (*src++) {
                    case 'u' :
                        func_one = (fptr_T) do_upper;
                        continue;
                    case 'U' :
                        func_all = (fptr_T) do_Upper;
                        continue;
                    case 'l' :
                        func_one = (fptr_T) do_lower;
                        continue;
                    case 'L' :
                        func_all = (fptr_T) do_Lower;
                        continue;
                    case 'e' :
                    case 'E' :
                        func_one = func_all = (fptr_T) NULL;
                        continue;
                    }
                }
            }
            if (no < 0) {
                if (c == K_SPECIAL && src[0] != NUL && src[1] != NUL) {
                    if (copy) {
                        *dst++ = c;
                        *dst++ = *src++;
                        *dst++ = *src++;
                    }
                    else {
                        dst += 3;
                        src += 2;
                    }
                    continue;
                }
                if (c == '\\' && *src != NUL) {
                    switch (*src) {
                    case 'r' :
                        c = CAR;
                        ++src;
                        break;
                    case 'n' :
                        c = NL;
                        ++src;
                        break;
                    case 't' :
                        c = TAB;
                        ++src;
                        break;
                    case 'b' :
                        c = Ctrl_H;
                        ++src;
                        break;
                    default :
                        if (backslash) {
                            if (copy)
                                *dst = '\\';
                            ++dst;
                        }
                        c = *src++;
                    }
                }
                if (func_one != (fptr_T) NULL)
                    func_one = (fptr_T) (func_one (&cc, c));
                else if (func_all != (fptr_T) NULL)
                    func_all = (fptr_T) (func_all (&cc, c));
                else
                    cc = c;
                if (copy)
                    *dst = cc;
                dst++;
            }
            else {
                if (REG_MULTI) {
                    clnum = rex.reg_mmatch->startpos[no].lnum;
                    if (clnum < 0 || rex.reg_mmatch->endpos[no].lnum < 0)
                        s = NULL;
                    else {
                        s = reg_getline (clnum) + rex.reg_mmatch->startpos[no].col;
                        if (rex.reg_mmatch->endpos[no].lnum == clnum)
                            len = rex.reg_mmatch->endpos[no].col - rex.reg_mmatch->startpos[no].col;
                        else
                            len = (int) STRLEN (s);
                    }
                }
                else {
                    s = rex.reg_match->startp[no];
                    if (rex.reg_match->endp[no] == NULL)
                        s = NULL;
                    else
                        len = (int) (rex.reg_match->endp[no] - s);
                }
                if (s != NULL) {
                    for (;;) {
                        if (len == 0) {
                            if (REG_MULTI) {
                                if (rex.reg_mmatch->endpos[no].lnum == clnum)
                                    break;
                                if (copy)
                                    *dst = CAR;
                                ++dst;
                                s = reg_getline (++clnum);
                                if (rex.reg_mmatch->endpos[no].lnum == clnum)
                                    len = rex.reg_mmatch->endpos[no].col;
                                else
                                    len = (int) STRLEN (s);
                            }
                            else
                                break;
                        }
                        else if (*s == NUL) {
                            if (copy)
                                EMSG (_ (e_re_damg));
                            goto exit;
                        }
                        else {
                            if (backslash && (*s == CAR || *s == '\\')) {
                                if (copy) {
                                    dst[0] = '\\';
                                    dst[1] = *s;
                                }
                                dst += 2;
                            }
                            else {
                                c = *s;
                                if (func_one != (fptr_T) NULL)
                                    func_one = (fptr_T) (func_one (&cc, c));
                                else if (func_all != (fptr_T) NULL)
                                    func_all = (fptr_T) (func_all (&cc, c));
                                else
                                    cc = c;
                                if (copy)
                                    *dst = cc;
                                dst++;
                            }
                            ++s;
                            --len;
                        }
                    }
                }
                no = -1;
            }
        }
    if (copy)
        *dst = NUL;
exit :
    return (int) ((dst - dest) + 1);
}

static int prog_magic_wrong (void) {
    regprog_T *prog;
    prog = REG_MULTI ? rex.reg_mmatch->regprog : rex.reg_match->regprog;
    if (prog->engine == &nfa_regengine)
        return FALSE;
    if (UCHARAT (((bt_regprog_T *) prog)->program) != REGMAGIC) {
        EMSG (_ (e_re_corr));
        return TRUE;
    }
    return FALSE;
}

static fptr_T do_upper (int *d, int c) {
    *d = MB_TOUPPER (c);
    return (fptr_T) NULL;
}

static fptr_T do_Upper (int *d, int c) {
    *d = MB_TOUPPER (c);
    return (fptr_T) do_Upper;
}

static fptr_T do_lower (int *d, int c) {
    *d = MB_TOLOWER (c);
    return (fptr_T) NULL;
}

static fptr_T do_Lower (int *d, int c) {
    *d = MB_TOLOWER (c);
    return (fptr_T) do_Lower;
}

static char_u *reg_getline (linenr_T lnum) {
    if (rex.reg_firstlnum + lnum < 1)
        return NULL;
    if (lnum > rex.reg_maxline)
        return (char_u *) "";
    return ml_get_buf (rex.reg_buf, rex.reg_firstlnum + lnum, FALSE);
}

static void reg_nextline (void) {
    regline = reg_getline (++reglnum);
    reginput = regline;
    fast_breakcheck ();
}

static int reg_match_visual (void) {
    pos_T top, bot;
    linenr_T lnum;
    colnr_T col;
    win_T *wp = rex.reg_win == NULL ? curwin : rex.reg_win;
    int mode;
    colnr_T start, end;
    colnr_T start2, end2;
    colnr_T cols;
    if (rex.reg_buf != curbuf || VIsual.lnum == 0)
        return FALSE;
    if (VIsual_active) {
        if (LT_POS (VIsual, wp->w_cursor)) {
            top = VIsual;
            bot = wp->w_cursor;
        }
        else {
            top = wp->w_cursor;
            bot = VIsual;
        }
        mode = VIsual_mode;
    }
    else {
        if (LT_POS (curbuf->b_visual.vi_start, curbuf->b_visual.vi_end)) {
            top = curbuf->b_visual.vi_start;
            bot = curbuf->b_visual.vi_end;
        }
        else {
            top = curbuf->b_visual.vi_end;
            bot = curbuf->b_visual.vi_start;
        }
        mode = curbuf->b_visual.vi_mode;
    }
    lnum = reglnum + rex.reg_firstlnum;
    if (lnum < top.lnum || lnum > bot.lnum)
        return FALSE;
    if (mode == 'v') {
        col = (colnr_T) (reginput - regline);
        if ((lnum == top.lnum && col < top.col) || (lnum == bot.lnum && col >= bot.col + (*p_sel != 'e')))
            return FALSE;
    }
    else if (mode == Ctrl_V) {
        getvvcol (wp, & top, & start, NULL, & end);
        getvvcol (wp, & bot, & start2, NULL, & end2);
        if (start2 < start)
            start = start2;
        if (end2 > end)
            end = end2;
        if (top.col == MAXCOL || bot.col == MAXCOL)
            end = MAXCOL;
        cols = win_linetabsize (wp, regline, (colnr_T) (reginput - regline));
        if (cols < start || cols > end - (*p_sel == 'e'))
            return FALSE;
    }
    return TRUE;
}

#define ADVANCE_REGINPUT() MB_PTR_ADV(reginput)

static int re_num_cmp (long_u val, char_u *scan) {
    long_u n = OPERAND_MIN (scan);
    if (OPERAND_CMP (scan) == '>')
        return val > n;
    if (OPERAND_CMP (scan) == '<')
        return val < n;
    return val == n;
}

static int cstrncmp (char_u *s1, char_u *s2, int *n) {
    int result;
    if (!rex.reg_ic)
        result = STRNCMP (s1, s2, *n);
    else
        result = MB_STRNICMP (s1, s2, *n);
    return result;
}

static char_u *cstrchr (char_u *s, int c) {
    char_u *p;
    int cc;
    if (!rex.reg_ic)
        return vim_strchr (s, c);
    if (MB_ISUPPER (c))
        cc = MB_TOLOWER (c);
    else if (MB_ISLOWER (c))
        cc = MB_TOUPPER (c);
    else
        return vim_strchr (s, c);
    for (p = s; *p != NUL; ++p)
        if (*p == c || *p == cc)
            return p;
    return NULL;
}

static int reg_save_equal (regsave_T *save) {
    if (REG_MULTI)
        return reglnum == save->rs_u.pos.lnum && reginput == regline + save->rs_u.pos.col;
    return reginput == save->rs_u.ptr;
}

static void reg_save (regsave_T *save, garray_T *gap) {
    if (REG_MULTI) {
        save->rs_u.pos.col = (colnr_T) (reginput - regline);
        save->rs_u.pos.lnum = reglnum;
    }
    else
        save->rs_u.ptr = reginput;
    save->rs_len = gap->ga_len;
}

static void cleanup_subexpr (void) {
    if (need_clear_subexpr) {
        if (REG_MULTI) {
            vim_memset (rex.reg_startpos, 0xff, sizeof (lpos_T) * NSUBEXP);
            vim_memset (rex.reg_endpos, 0xff, sizeof (lpos_T) * NSUBEXP);
        }
        else {
            vim_memset (rex.reg_startp, 0, sizeof (char_u *) * NSUBEXP);
            vim_memset (rex.reg_endp, 0, sizeof (char_u *) * NSUBEXP);
        }
        need_clear_subexpr = FALSE;
    }
}

static regitem_T *regstack_push (regstate_T state, char_u *scan) {
    regitem_T *rp;
    if ((long ) ((unsigned ) regstack.ga_len >> 10) >= p_mmp) {
        EMSG (_ (e_maxmempat));
        return NULL;
    }
    if (ga_grow (&regstack, sizeof (regitem_T)) == FAIL)
        return NULL;
    rp = (regitem_T *) ((char *) regstack.ga_data + regstack.ga_len);
    rp->rs_state = state;
    rp->rs_scan = scan;
    regstack.ga_len += sizeof (regitem_T);
    return rp;
}

static void cleanup_zsubexpr (void) {
    if (need_clear_zsubexpr) {
        if (REG_MULTI) {
            vim_memset (reg_startzpos, 0xff, sizeof (lpos_T) * NSUBEXP);
            vim_memset (reg_endzpos, 0xff, sizeof (lpos_T) * NSUBEXP);
        }
        else {
            vim_memset (reg_startzp, 0, sizeof (char_u *) * NSUBEXP);
            vim_memset (reg_endzp, 0, sizeof (char_u *) * NSUBEXP);
        }
        need_clear_zsubexpr = FALSE;
    }
}

static int match_with_backref (linenr_T start_lnum, colnr_T start_col, linenr_T end_lnum, colnr_T end_col, int *bytelen) {
    linenr_T clnum = start_lnum;
    colnr_T ccol = start_col;
    int len;
    char_u *p;
    if (bytelen != NULL)
        *bytelen = 0;
    for (;;) {
        if (regline != reg_tofree) {
            len = (int) STRLEN (regline);
            if (reg_tofree == NULL || len >= (int) reg_tofreelen) {
                len += 50;
                vim_free (reg_tofree);
                reg_tofree = alloc (len);
                if (reg_tofree == NULL)
                    return RA_FAIL;
                reg_tofreelen = len;
            }
            STRCPY (reg_tofree, regline);
            reginput = reg_tofree + (reginput - regline);
            regline = reg_tofree;
        }
        p = reg_getline (clnum);
        if (clnum == end_lnum)
            len = end_col - ccol;
        else
            len = (int) STRLEN (p +ccol);
        if (cstrncmp (p +ccol, reginput, &len) != 0)
            return RA_NOMATCH;
        if (bytelen != NULL)
            *bytelen += len;
        if (clnum == end_lnum)
            break;
        if (reglnum >= rex.reg_maxline)
            return RA_NOMATCH;
        reg_nextline ();
        if (bytelen != NULL)
            *bytelen = 0;
        ++clnum;
        ccol = 0;
        if (got_int)
            return RA_FAIL;
    }
    return RA_MATCH;
}

static int regrepeat (char_u *p, long  maxcount) {
    long  count = 0;
    char_u *scan;
    char_u *opnd;
    int mask;
    int testval = 0;
    scan = reginput;
    opnd = OPERAND (p);
    switch (OP (p)) {
    case ANY :
    case ANY + ADD_NL :
        while (count < maxcount) {
            while (*scan != NUL && count < maxcount) {
                ++count;
                MB_PTR_ADV (scan);
            }
            if (!REG_MULTI || !WITH_NL (OP (p)) || reglnum > rex.reg_maxline || rex.reg_line_lbr || count == maxcount)
                break;
            ++count;
            reg_nextline ();
            scan = reginput;
            if (got_int)
                break;
        }
        break;
    case IDENT :
    case IDENT + ADD_NL :
        testval = TRUE;
    case SIDENT :
    case SIDENT + ADD_NL :
        while (count < maxcount) {
            if (vim_isIDc (PTR2CHAR (scan)) && (testval || !VIM_ISDIGIT (*scan))) {
                MB_PTR_ADV (scan);
            }
            else if (*scan == NUL) {
                if (!REG_MULTI || !WITH_NL (OP (p)) || reglnum > rex.reg_maxline || rex.reg_line_lbr)
                    break;
                reg_nextline ();
                scan = reginput;
                if (got_int)
                    break;
            }
            else if (rex.reg_line_lbr && *scan == '\n' && WITH_NL (OP (p)))
                ++scan;
            else
                break;
            ++count;
        }
        break;
    case KWORD :
    case KWORD + ADD_NL :
        testval = TRUE;
    case SKWORD :
    case SKWORD + ADD_NL :
        while (count < maxcount) {
            if (vim_iswordp_buf (scan, rex.reg_buf) && (testval || !VIM_ISDIGIT (*scan))) {
                MB_PTR_ADV (scan);
            }
            else if (*scan == NUL) {
                if (!REG_MULTI || !WITH_NL (OP (p)) || reglnum > rex.reg_maxline || rex.reg_line_lbr)
                    break;
                reg_nextline ();
                scan = reginput;
                if (got_int)
                    break;
            }
            else if (rex.reg_line_lbr && *scan == '\n' && WITH_NL (OP (p)))
                ++scan;
            else
                break;
            ++count;
        }
        break;
    case FNAME :
    case FNAME + ADD_NL :
        testval = TRUE;
    case SFNAME :
    case SFNAME + ADD_NL :
        while (count < maxcount) {
            if (vim_isfilec (PTR2CHAR (scan)) && (testval || !VIM_ISDIGIT (*scan))) {
                MB_PTR_ADV (scan);
            }
            else if (*scan == NUL) {
                if (!REG_MULTI || !WITH_NL (OP (p)) || reglnum > rex.reg_maxline || rex.reg_line_lbr)
                    break;
                reg_nextline ();
                scan = reginput;
                if (got_int)
                    break;
            }
            else if (rex.reg_line_lbr && *scan == '\n' && WITH_NL (OP (p)))
                ++scan;
            else
                break;
            ++count;
        }
        break;
    case PRINT :
    case PRINT + ADD_NL :
        testval = TRUE;
    case SPRINT :
    case SPRINT + ADD_NL :
        while (count < maxcount) {
            if (*scan == NUL) {
                if (!REG_MULTI || !WITH_NL (OP (p)) || reglnum > rex.reg_maxline || rex.reg_line_lbr)
                    break;
                reg_nextline ();
                scan = reginput;
                if (got_int)
                    break;
            }
            else if (vim_isprintc (PTR2CHAR (scan)) == 1 && (testval || !VIM_ISDIGIT (*scan))) {
                MB_PTR_ADV (scan);
            }
            else if (rex.reg_line_lbr && *scan == '\n' && WITH_NL (OP (p)))
                ++scan;
            else
                break;
            ++count;
        }
        break;
    case WHITE :
    case WHITE + ADD_NL :
        testval = mask = RI_WHITE;
    do_class :
        while (count < maxcount) {
            if (*scan == NUL) {
                if (!REG_MULTI || !WITH_NL (OP (p)) || reglnum > rex.reg_maxline || rex.reg_line_lbr)
                    break;
                reg_nextline ();
                scan = reginput;
                if (got_int)
                    break;
            }
            else if ((class_tab[*scan] & mask) == testval)
                ++scan;
            else if (rex.reg_line_lbr && *scan == '\n' && WITH_NL (OP (p)))
                ++scan;
            else
                break;
            ++count;
        }
        break;
    case NWHITE :
    case NWHITE + ADD_NL :
        mask = RI_WHITE;
        goto do_class;
    case DIGIT :
    case DIGIT + ADD_NL :
        testval = mask = RI_DIGIT;
        goto do_class;
    case NDIGIT :
    case NDIGIT + ADD_NL :
        mask = RI_DIGIT;
        goto do_class;
    case HEX :
    case HEX + ADD_NL :
        testval = mask = RI_HEX;
        goto do_class;
    case NHEX :
    case NHEX + ADD_NL :
        mask = RI_HEX;
        goto do_class;
    case OCTAL :
    case OCTAL + ADD_NL :
        testval = mask = RI_OCTAL;
        goto do_class;
    case NOCTAL :
    case NOCTAL + ADD_NL :
        mask = RI_OCTAL;
        goto do_class;
    case WORD :
    case WORD + ADD_NL :
        testval = mask = RI_WORD;
        goto do_class;
    case NWORD :
    case NWORD + ADD_NL :
        mask = RI_WORD;
        goto do_class;
    case HEAD :
    case HEAD + ADD_NL :
        testval = mask = RI_HEAD;
        goto do_class;
    case NHEAD :
    case NHEAD + ADD_NL :
        mask = RI_HEAD;
        goto do_class;
    case ALPHA :
    case ALPHA + ADD_NL :
        testval = mask = RI_ALPHA;
        goto do_class;
    case NALPHA :
    case NALPHA + ADD_NL :
        mask = RI_ALPHA;
        goto do_class;
    case LOWER :
    case LOWER + ADD_NL :
        testval = mask = RI_LOWER;
        goto do_class;
    case NLOWER :
    case NLOWER + ADD_NL :
        mask = RI_LOWER;
        goto do_class;
    case UPPER :
    case UPPER + ADD_NL :
        testval = mask = RI_UPPER;
        goto do_class;
    case NUPPER :
    case NUPPER + ADD_NL :
        mask = RI_UPPER;
        goto do_class;
    case EXACTLY :
        {
            int cu, cl;
            if (rex.reg_ic) {
                cu = MB_TOUPPER (*opnd);
                cl = MB_TOLOWER (*opnd);
                while (count < maxcount && (*scan == cu || *scan == cl)) {
                    count++;
                    scan++;
                }
            }
            else {
                cu = *opnd;
                while (count < maxcount && *scan == cu) {
                    count++;
                    scan++;
                }
            }
            break;
        }
    case ANYOF :
    case ANYOF + ADD_NL :
        testval = TRUE;
    case ANYBUT :
    case ANYBUT + ADD_NL :
        while (count < maxcount) {
            if (*scan == NUL) {
                if (!REG_MULTI || !WITH_NL (OP (p)) || reglnum > rex.reg_maxline || rex.reg_line_lbr)
                    break;
                reg_nextline ();
                scan = reginput;
                if (got_int)
                    break;
            }
            else if (rex.reg_line_lbr && *scan == '\n' && WITH_NL (OP (p)))
                ++scan;
            else {
                if ((cstrchr (opnd, *scan) == NULL) == testval)
                    break;
                ++scan;
            }
            ++count;
        }
        break;
    case NEWL :
        while (count < maxcount && ((*scan == NUL && reglnum <= rex.reg_maxline && !rex.reg_line_lbr && REG_MULTI) || (*scan == '\n' && rex.reg_line_lbr))) {
            count++;
            if (rex.reg_line_lbr)
                ADVANCE_REGINPUT ();
            else
                reg_nextline ();
            scan = reginput;
            if (got_int)
                break;
        }
        break;
    default :
        EMSG (_ (e_re_corr));
        break;
    }
    reginput = scan;
    return (int) count;
}

static void save_subexpr (regbehind_T *bp) {
    int i;
    bp->save_need_clear_subexpr = need_clear_subexpr;
    if (!need_clear_subexpr) {
        for (i = 0; i < NSUBEXP; ++i) {
            if (REG_MULTI) {
                bp->save_start[i].se_u.pos = rex.reg_startpos[i];
                bp->save_end[i].se_u.pos = rex.reg_endpos[i];
            }
            else {
                bp->save_start[i].se_u.ptr = rex.reg_startp[i];
                bp->save_end[i].se_u.ptr = rex.reg_endp[i];
            }
        }
    }
}

static void regstack_pop (char_u **scan) {
    regitem_T *rp;
    rp = (regitem_T *) ((char *) regstack.ga_data + regstack.ga_len) - 1;
    *scan = rp->rs_scan;
    regstack.ga_len -= sizeof (regitem_T);
}

static void reg_restore (regsave_T *save, garray_T *gap) {
    if (REG_MULTI) {
        if (reglnum != save->rs_u.pos.lnum) {
            reglnum = save->rs_u.pos.lnum;
            regline = reg_getline (reglnum);
        }
        reginput = regline + save->rs_u.pos.col;
    }
    else
        reginput = save->rs_u.ptr;
    gap->ga_len = save->rs_len;
}

static void restore_subexpr (regbehind_T *bp) {
    int i;
    need_clear_subexpr = bp->save_need_clear_subexpr;
    if (!need_clear_subexpr) {
        for (i = 0; i < NSUBEXP; ++i) {
            if (REG_MULTI) {
                rex.reg_startpos[i] = bp->save_start[i].se_u.pos;
                rex.reg_endpos[i] = bp->save_end[i].se_u.pos;
            }
            else {
                rex.reg_startp[i] = bp->save_start[i].se_u.ptr;
                rex.reg_endp[i] = bp->save_end[i].se_u.ptr;
            }
        }
    }
}

