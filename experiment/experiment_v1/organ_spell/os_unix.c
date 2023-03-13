struct buf_state {
    int bs_idx;
    int bs_flags;
    int bs_seqnr;
    int bs_cchar;
    reg_extmatch_T *bs_extmatch;
};
struct growarray {
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    int ga_growsize;
    void *ga_data;
};
struct msglist {
    char_u *msg;
    char_u *throw_msg;
    struct msglist *next;
};
struct vim_exception {
    except_type_T type;
    char_u *value;
    struct msglist *messages;
    char_u *throw_name;
    linenr_T throw_lnum;
    except_T *caught;
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
struct u_entry {
    u_entry_T *ue_next;
    linenr_T ue_top;
    linenr_T ue_bot;
    linenr_T ue_lcount;
    char_u **ue_array;
    long  ue_size;
};
struct buffblock {
    buffblock_T *b_next;
    char_u b_str [1];
};
volatile int do_resize = FALSE;
EXTERN long  p_wd;
EXTERN int ignored;
EXTERN long  p_verbose;
EXTERN char need_key_msg [] INIT (= N_ ("Need encryption key for \"%s\""));
EXTERN char bot_top_msg [] INIT (= N_ ("search hit BOTTOM, continuing at TOP"));
EXTERN char top_bot_msg [] INIT (= N_ ("search hit TOP, continuing at BOTTOM"));
EXTERN char_u e_invexprmsg [] INIT (= N_ ("E449: Invalid expression received"));
EXTERN char_u no_lines_msg [] INIT (= N_ ("--No lines in buffer--"));
EXTERN char_u msg_buf [MSG_BUF_LEN];
EXTERN struct msglist **msg_list INIT (= NULL);
EXTERN int called_emsg;
EXTERN int did_emsg_syntax;
EXTERN int did_emsg;
EXTERN char_u *keep_msg INIT (= NULL);
EXTERN int msg_scrolled;
EXTERN int msg_row;
EXTERN int msg_col;
EXTERN typebuf_T typebuf;
EXTERN long_u scrollbar_value;
EXTERN except_T *caught_stack INIT (= NULL);
EXTERN int did_uncaught_emsg;
EXTERN int p_guipty;
EXTERN char_u *p_mouseshape;
EXTERN char_u *p_kp;
EXTERN char_u *p_isf;
EXTERN int p_icon;
EXTERN char_u e_emptybuf [] INIT (= N_ ("E749: empty buffer"));

int vim_is_iris (char_u *name) {
    if (name == NULL)
        return FALSE;
    return (STRNICMP (name, "iris-ansi", 9) == 0 || STRCMP (name, "builtin_iris-ansi") == 0);
}

int vim_is_xterm (char_u *name) {
    if (name == NULL)
        return FALSE;
    return (STRNICMP (name, "xterm", 5) == 0 || STRNICMP (name, "nxterm", 6) == 0 || STRNICMP (name, "kterm", 5) == 0 || STRNICMP (name, "mlterm", 6) == 0 || STRNICMP (name, "rxvt", 4) == 0 || STRNICMP (name, "screen.xterm", 12) == 0 || STRCMP (name, "builtin_xterm") == 0);
}

vim_acl_T mch_get_acl (char_u *fname) {
    vim_acl_T ret = NULL;
    return ret;
}

void mch_free_acl (vim_acl_T aclent) {
    if (aclent == NULL)
        return;
}

void mch_set_acl (char_u *fname, vim_acl_T aclent) {
    if (aclent == NULL)
        return;
}

int mch_chdir (char *path) {
    if (p_verbose >= 5) {
        verbose_enter ();
        smsg ((char_u *) "chdir(%s)", path);
        verbose_leave ();
    }
    return chdir (path);
}

static int WaitForChar (long  msec, int *interrupted, int ignore_input) {
    return ui_wait_for_chars_or_timer (msec, WaitForCharOrMouse, interrupted, ignore_input) == OK;
}

void mch_write (char_u *s, int len) {
    ignored = (int) write (1, (char *) s, len);
    if (p_wd)
        RealWaitForChar (read_cmd_fd, p_wd, NULL, NULL);
}

static int RealWaitForChar (int fd, long  msec, int *check_for_gpm, int *interrupted) {
    int ret;
    int result;
    {
        struct pollfd fds [6 + 3 * MAX_OPEN_CHANNELS];
        int nfd;
        int towait = (int) msec;
        fds[0].fd = fd;
        fds[0].events = POLLIN;
        nfd = 1;
        nfd = channel_poll_setup (nfd, &fds, &towait);
        if (interrupted != NULL)
            *interrupted = FALSE;
        ret = poll (fds, nfd, towait);
        result = ret > 0 && (fds[0].revents & POLLIN);
        if (result == 0 && interrupted != NULL && ret > 0)
            *interrupted = TRUE;
        if (ret >= 0)
            ret = channel_poll_check (ret, &fds);
    }
    return result;
}

static void handle_resize (void) {
    do_resize = FALSE;
    shell_resized ();
}

int vim_handle_signal (int sig) {
    static int got_signal = 0;
    static int blocked = TRUE;
    switch (sig) {
    case SIGNAL_BLOCK :
        blocked = TRUE;
        break;
    case SIGNAL_UNBLOCK :
        blocked = FALSE;
        if (got_signal != 0) {
            kill (getpid (), got_signal);
            got_signal = 0;
        }
        break;
    default :
        if (!blocked)
            return TRUE;
        got_signal = sig;
        got_int = TRUE;
        break;
    }
    return FALSE;
}

void get_stty (void) {
    ttyinfo_T info;
    char_u buf [2];
    char_u *p;
    if (get_tty_info (read_cmd_fd, &info) == OK) {
        intr_char = info.interrupt;
        buf[0] = info.backspace;
        buf[1] = NUL;
        add_termcode ((char_u *) "kb", buf, FALSE);
        p = find_termcode ((char_u *) "kD");
        if (p != NULL && p[0] == buf[0] && p[1] == buf[1])
            do_fixdel (NULL);
    }
}

int vim_is_fastterm (char_u *name) {
    if (name == NULL)
        return FALSE;
    if (vim_is_xterm (name) || vim_is_vt300 (name) || vim_is_iris (name))
        return TRUE;
    return (STRNICMP (name, "hpterm", 6) == 0 || STRNICMP (name, "sun-cmd", 7) == 0 || STRNICMP (name, "screen", 6) == 0 || STRNICMP (name, "tmux", 4) == 0 || STRNICMP (name, "dtterm", 6) == 0);
}

int vim_is_vt300 (char_u *name) {
    if (name == NULL)
        return FALSE;
    return ((STRNICMP (name, "vt", 2) == 0 && vim_strchr ((char_u *) "12345", name[2]) != NULL) || STRCMP (name, "builtin_vt320") == 0);
}

int mch_get_uname (uid_t uid, char_u *s, int len) {
    sprintf ((char *) s, "%d", (int) uid);
    return FAIL;
}

