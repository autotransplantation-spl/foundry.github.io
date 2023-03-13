
#include "InterfaceHeader.h"
int close_win = FALSE;
char_u *oldwindowtitle = NULL;
struct Window *wb_window;
BPTR raw_out = (BPTR) NULL;
int size_set = FALSE;
BPTR raw_in = (BPTR) NULL;

long_u mch_avail_mem (int special) {
    return (long_u) (AvailMem (special ? (long ) MEMF_CHIP : (long ) MEMF_ANY)) >> 10;
}

void mch_new_shellsize (void) {
}

int mch_setenv (char *var, char *value, int x) {
    if (SetVar ((UBYTE *) var, (UBYTE *) value, (LONG) -1, (ULONG) GVF_LOCAL_ONLY))
        return 0;
    return -1;
}

int mch_FullName (char_u *fname, char_u *buf, int len, int force) {
    BPTR l;
    int retval = FAIL;
    int i;
    if ((l = Lock ((UBYTE *) fname, (long ) ACCESS_READ)) != (BPTR) 0) {
        retval = lock2name (l, buf, (long ) len - 1);
        UnLock (l);
    }
    else if (force || !mch_isFullName (fname)) {
        if ((l = Lock ((UBYTE *) "", (long ) ACCESS_READ)) != (BPTR) NULL) {
            retval = lock2name (l, buf, (long ) len);
            UnLock (l);
            if (retval == OK) {
                i = STRLEN (buf);
                if (i == 0 || *fname != NUL) {
                    if (i < len - 1 && (i == 0 || buf[i - 1] != ':'))
                        buf[i++] = '/';
                    vim_strncpy (buf + i, fname, len - i - 1);
                }
            }
        }
    }
    if (*buf == 0 || *buf == ':')
        retval = FAIL;
    return retval;
}

static int lock2name (BPTR lock, char_u *buf, long  len) {
    return ((int) NameFromLock (lock, (UBYTE *) buf, len) ? OK : FAIL);
}

int mch_isFullName (char_u *fname) {
    return (vim_strchr (fname, ':') != NULL && *fname != ':');
}

char_u *mch_getenv (char_u *var) {
    int len;
    UBYTE *buf;
    char_u *retval;
    static char_u *alloced = NULL;
    {
        VIM_CLEAR (alloced);
        retval = NULL;
        buf = alloc (IOSIZE);
        if (buf == NULL)
            return NULL;
        len = GetVar ((UBYTE *) var, buf, (long ) (IOSIZE - 1), (long ) 0);
        if (len >= 0) {
            retval = vim_strsave ((char_u *) buf);
            alloced = retval;
        }
        vim_free (buf);
    }
    if (retval == NULL && STRCMP (var, "VIM") == 0)
        retval = (char_u *) "vim:";
    return retval;
}

int mch_isdir (char_u *name) {
    struct FileInfoBlock *fib;
    int retval = FALSE;
    fib = get_fib (name);
    if (fib != NULL) {
        retval = ((fib->fib_DirEntryType >= 0) ? TRUE : FALSE);
        free_fib (fib);
    }
    return retval;
}

static struct FileInfoBlock *get_fib (char_u *fname) {
    BPTR flock;
    struct FileInfoBlock *fib;
    if (fname == NULL)
        return NULL;
    fib = (struct FileInfoBlock *) alloc (sizeof (struct FileInfoBlock));
    if (fib != NULL) {
        flock = Lock ((UBYTE *) fname, (long ) ACCESS_READ);
        if (flock == (BPTR) NULL || !Examine (flock, fib)) {
            free_fib (fib);
            fib = NULL;
        }
        if (flock)
            UnLock (flock);
    }
    return fib;
}

int mch_dirname (char_u *buf, int len) {
    return mch_FullName ((char_u *) "", buf, len, FALSE);
}

void mch_hide (char_u *name) {
}

int mch_get_user_name (char_u *s, int len) {
    *s = NUL;
    return FAIL;
}

long  mch_getperm (char_u *name) {
    struct FileInfoBlock *fib;
    long  retval = -1;
    fib = get_fib (name);
    if (fib != NULL) {
        retval = fib->fib_Protection;
        free_fib (fib);
    }
    return retval;
}

void mch_get_host_name (char_u *s, int len) {
    vim_strncpy (s, "Amiga", len - 1);
}

long  mch_get_pid (void) {
    return (long ) 0;
}

int mch_char_avail (void) {
    return (WaitForChar (raw_in, 100L) != 0);
}

int mch_get_shellsize (void) {
    struct ConUnit *conUnit;
    char id_a [sizeof (struct InfoData) + 3];
    struct InfoData *id = 0;
    if (!term_console)
        goto out;
    id = (struct InfoData *) (((long ) id_a + 3L) & ~3L);
    if (size_set)
        OUT_STR ("\233t\233u");
    out_flush ();
    if (dos_packet (MP (raw_out), (long ) ACTION_DISK_INFO, ((ULONG) id) >> 2) == 0 || (wb_window = (struct Window *) id->id_VolumeNode) == NULL) {
        term_console = FALSE;
        goto out;
    }
    if (oldwindowtitle == NULL)
        oldwindowtitle = (char_u *) wb_window->Title;
    if (id->id_InUse == (BPTR) NULL) {
        mch_errmsg (_ ("mch_get_shellsize: not a console??\n"));
        return FAIL;
    }
    conUnit = (struct ConUnit *) ((struct IOStdReq *) id->id_InUse)->io_Unit;
    Rows = conUnit->cu_YMax + 1;
    Columns = conUnit->cu_XMax + 1;
    if (Rows < 0 || Rows > 200) {
        Columns = 80;
        Rows = 24;
        term_console = FALSE;
        return FAIL;
    }
    return OK;
out :
    return FAIL;
}

void mch_set_shellsize (void) {
    if (term_console) {
        size_set = TRUE;
        out_char (CSI);
        out_num ((long) Rows);
        out_char ('t');
        out_char (CSI);
        out_num ((long) Columns);
        out_char ('u');
        out_flush ();
    }
}

static void out_num (long  n) {
    OUT_STR_NF (tltoa ((unsigned long) n));
}

int mch_setperm (char_u *name, long  perm) {
    perm &= ~FIBF_ARCHIVE;
    return (SetProtection ((UBYTE *) name, (long ) perm) ? OK : FAIL);
}

int mch_inchar (char_u *buf, int maxlen, long  time, int tb_change_cnt) {
    int len;
    long  utime;
    if (time >= 0) {
        if (time == 0)
            utime = 100L;
        else
            utime = time * 1000L;
        if (WaitForChar (raw_in, utime) == 0)
            return 0;
    }
    else {
        if (WaitForChar (raw_in, p_ut *1000L) == 0) {
            if (trigger_cursorhold () && maxlen >= 3) {
                buf[0] = K_SPECIAL;
                buf[1] = KS_EXTRA;
                buf[2] = (int) KE_CURSORHOLD;
                return 3;
            }
            before_blocking ();
        }
    }
    for (;;) {
        len = Read (raw_in, (char *) buf, (long ) maxlen);
        if (len > 0) {
            return len;
        }
    }
}

void mch_delay (long  msec, int ignoreinput) {
    void Delay (long);
    if (msec > 0) {
        if (ignoreinput)
            Delay (msec / 20L);
        else
            WaitForChar (raw_in, msec *1000L);
    }
}

void mch_restore_title (int which) {
    if (which & 1)
        mch_settitle (oldwindowtitle, NULL);
}

void mch_settitle (char_u *title, char_u *icon) {
    if (wb_window != NULL && title != NULL)
        SetWindowTitles (wb_window, (UBYTE *) title, (UBYTE *) -1L);
}

void mch_exit (int r) {
    exiting = TRUE;
    if (raw_in) {
        settmode (TMODE_COOK);
        stoptermcap ();
    }
    out_char ('\n');
    if (raw_out) {
        if (term_console) {
            win_resize_off ();
            if (size_set)
                OUT_STR ("\233t\233u");
        }
        out_flush ();
    }
    mch_restore_title (3);
    ml_close_all (TRUE);
    if (close_win)
        Close (raw_in);
    if (r)
        printf (_ ("Vim exiting with %d\n"), r);
    exit (r);
}

#define MP(xx)	((struct MsgPort *)((struct FileHandle *) (BADDR(xx)))->fh_Type)

void win_resize_off (void) {
    OUT_STR_NF ("\033[12}");
}

void fname_case (char_u *name, int len) {
    struct FileInfoBlock *fib;
    size_t flen;
    fib = get_fib (name);
    if (fib != NULL) {
        flen = STRLEN (name);
        if (flen == strlen (fib->fib_FileName))
            mch_memmove (name, fib->fib_FileName, flen);
        free_fib (fib);
    }
}

int mch_can_restore_title (void) {
    return (wb_window != NULL);
}

int mch_can_restore_icon (void) {
    return FALSE;
}

int mch_nodetype (char_u *name) {
    return NODE_NORMAL;
}

int mch_has_wildcard (char_u *p) {
    for (; *p; MB_PTR_ADV (p)) {
        if (*p == '\\' && p[1] != NUL)
            ++p;
        else if (vim_strchr ((char_u *) "*?[(#$", *p) != NULL || (*p == '~' && p[1] != NUL))
            return TRUE;
    }
    return FALSE;
}

void mch_settmode (int tmode) {
    if (dos_packet (MP (raw_in), (long ) ACTION_SCREEN_MODE, tmode == TMODE_RAW ? -1L : 0L) == 0)
        mch_errmsg (_ ("cannot change console mode ?!\n"));
}

int mch_can_exe (char_u *name, char_u **path, int use_path) {
    return -1;
}

int mch_has_exp_wildcard (char_u *p) {
    for (; *p; MB_PTR_ADV (p)) {
        if (*p == '\\' && p[1] != NUL)
            ++p;
        else if (vim_strchr ((char_u *) "*?[(#", *p) != NULL)
            return TRUE;
    }
    return FALSE;
}

int mch_expandpath (garray_T *gap, char_u *pat, int flags) {
    struct AnchorPath *Anchor;
    LONG Result;
    char_u *starbuf, *sp, *dp;
    int start_len;
    int matches;
    start_len = gap->ga_len;
    Anchor = (struct AnchorPath *) alloc_clear ((unsigned ) ANCHOR_SIZE);
    if (Anchor == NULL)
        return 0;
    Anchor->ap_Strlen = ANCHOR_BUF_SIZE;
    Anchor->ap_Flags = APF_DoDot | APF_DoWild;
    starbuf = alloc ((unsigned ) (2 * STRLEN (pat) + 1));
    if (starbuf == NULL)
        goto Return;
    for (sp = pat, dp = starbuf; *sp; ++sp) {
        if (*sp == '*') {
            *dp++ = '#';
            *dp++ = '?';
        }
        else
            *dp++ = *sp;
    }
    *dp = NUL;
    Result = MatchFirst ((UBYTE *) starbuf, Anchor);
    vim_free (starbuf);
    while (Result == 0) {
        addfile (gap, (char_u *) Anchor -> ap_Buf, flags);
        Result = MatchNext (Anchor);
    }
    matches = gap->ga_len - start_len;
    if (Result == ERROR_BUFFER_OVERFLOW)
        EMSG (_ ("ANCHOR_BUF_SIZE too small."));
    else if (matches == 0 && Result != ERROR_OBJECT_NOT_FOUND && Result != ERROR_DEVICE_NOT_MOUNTED && Result != ERROR_NO_MORE_ENTRIES)
        EMSG (_ ("I/O ERROR"));
    if (matches)
        qsort ((void *) (((char_u **) gap->ga_data) + start_len), (size_t) matches, sizeof (char_u *), sortcmp);
    MatchEnd (Anchor);
Return :
    vim_free (Anchor);
    return matches;
}

static int sortcmp (const void *a, const void *b) {
    char *s = *(char**) a;
    char *t = *(char**) b;
    return pathcmp (s, t, -1);
}

void mch_write (char_u *p, int len) {
    Write (raw_out, (char *) p, (long) len);
}

int mch_call_shell (char_u *cmd, int options) {
    BPTR mydir;
    int x;
    int tmode = cur_tmode;
    int retval = 0;
    if (close_win) {
        EMSG (_ ("E360: Cannot execute shell with -f option"));
        return -1;
    }
    if (term_console)
        win_resize_off ();
    out_flush ();
    if (options & SHELL_COOKED)
        settmode (TMODE_COOK);
    mydir = Lock ((UBYTE *) "", (long ) ACCESS_READ);
    if (p_st >= 4 || (p_st >= 2 && !(options & SHELL_FILTER)))
        use_execute = 1;
    else
        use_execute = 0;
    if (!use_execute) {
        shellcmd = vim_strsave (p_sh);
        if (shellcmd == NULL)
            use_execute = 1;
        else {
            shellarg = skiptowhite (shellcmd);
            if (*shellarg != NUL) {
                *shellarg++ = NUL;
                shellarg = skipwhite (shellarg);
            }
        }
    }
    if (cmd == NULL) {
        if (use_execute) {
            x = SystemTags ((UBYTE *) p_sh, SYS_UserShell, TRUE, TAG_DONE);
        }
        else
            x = fexecl ((char *) shellcmd, (char *) shellcmd, (char *) shellarg, NULL);
    }
    else if (use_execute) {
        x = SystemTags ((UBYTE *) cmd, SYS_UserShell, TRUE, TAG_DONE);
    }
    else if (p_st & 1)
        x = fexecl ((char *) shellcmd, (char *) shellcmd, (char *) shellarg, (char *) cmd, NULL);
    else
        x = fexecl ((char *) shellcmd, (char *) shellcmd, (char *) shellarg, (char *) p_shcf, (char *) cmd, NULL);
    if (x < 0) {
        MSG_PUTS (_ ("Cannot execute "));
        if (use_execute) {
            if (cmd == NULL)
                msg_outtrans (p_sh);
            else
                msg_outtrans (cmd);
        }
        else {
            MSG_PUTS (_ ("shell "));
            msg_outtrans (shellcmd);
        }
        msg_putchar ('\n');
        retval = -1;
    }
    else {
        if (use_execute) {
            if (x)
                x = IoErr ();
        }
        else
            x = wait ();
        if (x) {
            if (!(options & SHELL_SILENT) && !emsg_silent) {
                msg_putchar ('\n');
                msg_outnum ((long) x);
                MSG_PUTS (_ (" returned\n"));
            }
            retval = x;
        }
    }
    vim_free (shellcmd);
    if ((mydir = CurrentDir (mydir)) != 0)
        UnLock (mydir);
    if (tmode == TMODE_RAW)
        settmode (TMODE_RAW);
    resettitle ();
    if (term_console)
        win_resize_on ();
    return retval;
}

void win_resize_on (void) {
    OUT_STR_NF ("\033[12{");
}

void mch_breakcheck (int force) {
    if (SetSignal (0L, (long ) (SIGBREAKF_CTRL_C | SIGBREAKF_CTRL_D | SIGBREAKF_CTRL_E | SIGBREAKF_CTRL_F)) & SIGBREAKF_CTRL_C)
        got_int = TRUE;
}

int mch_input_isatty (void) {
    return TRUE;
}

