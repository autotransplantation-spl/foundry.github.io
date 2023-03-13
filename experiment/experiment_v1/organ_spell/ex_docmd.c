static struct {
    int expand;
    char *name;
} command_complete [] = {{EXPAND_AUGROUP, "augroup"}, {EXPAND_BEHAVE, "behave"}, {EXPAND_BUFFERS, "buffer"}, {EXPAND_COLORS, "color"}, {EXPAND_COMMANDS, "command"}, {EXPAND_COMPILER, "compiler"}, {EXPAND_USER_DEFINED, "custom"}, {EXPAND_USER_LIST, "customlist"}, {EXPAND_DIRECTORIES, "dir"}, {EXPAND_ENV_VARS, "environment"}, {EXPAND_EVENTS, "event"}, {EXPAND_EXPRESSION, "expression"}, {EXPAND_FILES, "file"}, {EXPAND_FILES_IN_PATH, "file_in_path"}, {EXPAND_FILETYPE, "filetype"}, {EXPAND_FUNCTIONS, "function"}, {EXPAND_HELP, "help"}, {EXPAND_HIGHLIGHT, "highlight"}, {EXPAND_MAPCLEAR, "mapclear"}, {EXPAND_MAPPINGS, "mapping"}, {EXPAND_MENUS, "menu"}, {EXPAND_MESSAGES, "messages"}, {EXPAND_OWNSYNTAX, "syntax"}, {EXPAND_SYNTIME, "syntime"}, {EXPAND_SETTINGS, "option"}, {EXPAND_PACKADD, "packadd"}, {EXPAND_SHELLCMD, "shellcmd"}, {EXPAND_SIGN, "sign"}, {EXPAND_TAGS, "tag"}, {EXPAND_TAGS_LISTFILES, "tag_listfiles"}, {EXPAND_USER, "user"}, {EXPAND_USER_VARS, "var"}, {0, NULL}};
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
struct w_line {
    linenr_T wl_lnum;
    short_u wl_size;
    char wl_valid;
    char wl_folded;
    linenr_T wl_lastlnum;
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
struct hashtable_S {
    long_u ht_mask;
    long_u ht_used;
    long_u ht_filled;
    int ht_locked;
    int ht_error;
    hashitem_T *ht_array;
    hashitem_T ht_smallarray [HT_INIT_SIZE];
};
struct hashitem_S {
    long_u hi_hash;
    char_u *hi_key;
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
struct arglist {
    garray_T al_ga;
    int al_refcount;
    int id;
};
struct ml_chunksize {
    int mlcs_numlines;
    long  mlcs_totalsize;
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
struct mf_hashtab_S {
    long_u mht_mask;
    long_u mht_count;
    mf_hashitem_T **mht_buckets;
    mf_hashitem_T *mht_small_buckets [MHT_INIT_SIZE];
    char mht_fixed;
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
struct foldinfo {
    int fi_level;
    int fi_lnum;
    int fi_low_level;
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
struct filemark {
    pos_T mark;
    int fnum;
};
struct cmdmod {
    char *name;
    int minlen;
    int has_count;
};
struct dbg_stuff {
    int trylevel;
    int force_abort;
    except_T *caught_stack;
    char_u *vv_exception;
    char_u *vv_throwpoint;
    int did_emsg;
    int got_int;
    int did_throw;
    int need_rethrow;
    int check_cstack;
    except_T *current_exception;
};
struct loop_cookie {
    garray_T *lines_gap;
    int current_line;
    int repeating;
    char_u * (*getline) (int, void *, int);
    void *cookie;
};
struct ucmd {
    char_u *uc_name;
    long_u uc_argt;
    char_u *uc_rep;
    long  uc_def;
    int uc_compl;
    int uc_addr_type;
    scid_T uc_scriptID;
    char_u *uc_compl_arg;
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
struct dictitem16_S {
    typval_T di_tv;
    char_u di_flags;
    char_u di_key [17];
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
struct signlist {
    int id;
    linenr_T lnum;
    int typenr;
    signlist_T *next;
    signlist_T *prev;
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
struct nfa_state {
    int c;
    nfa_state_T *out;
    nfa_state_T *out1;
    int id;
    int lastlist [2];
    int val;
};
struct regengine {
    regprog_T * (*regcomp) (char_u *, int);
    void (*regfree) (regprog_T *);
    int (*regexec_nl) (regmatch_T *, char_u *, colnr_T, int);
    long  (*regexec_multi) (regmmatch_T *, win_T *, buf_T *, linenr_T, colnr_T, proftime_T *, int *);
    char_u *expr;
};
struct growarray {
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    int ga_growsize;
    void *ga_data;
};
struct regprog {
    regengine_T *engine;
    unsigned  regflags;
    unsigned  re_engine;
    unsigned  re_flags;
};
struct stl_hlrec {
    char_u *start;
    int userhl;
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
struct buf_state {
    int bs_idx;
    int bs_flags;
    int bs_seqnr;
    int bs_cchar;
    reg_extmatch_T *bs_extmatch;
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
struct info_pointer {
    blocknr_T ip_bnum;
    linenr_T ip_low;
    linenr_T ip_high;
    int ip_index;
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
struct posmatch {
    llpos_T pos [MAXPOSMATCH];
    int cur;
    linenr_T toplnum;
    linenr_T botlnum;
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
EXTERN char_u e_wildexpand [] INIT (= N_ ("E79: Cannot expand wildcards"));
EXTERN char_u *p_wop;
EXTERN int p_write;
EXTERN long  Rows;
int ex_pressedreturn = FALSE;
EXTERN long  p_verbose;
EXTERN int KeyTyped;
EXTERN long  p_mfd;
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u *p_titlestring;
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
EXTERN win_T *au_pending_free_win INIT (= NULL);
EXTERN tabpage_T *first_tabpage;
EXTERN char_u e_umark [] INIT (= N_ ("E78: Unknown mark"));
EXTERN char_u e_marknotset [] INIT (= N_ ("E20: Mark not set"));
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
EXTERN linenr_T sub_nlines;
EXTERN char_u e_prev_dir [] INIT (= N_ ("E459: Cannot go back to previous directory"));
EXTERN char_u e_noprevre [] INIT (= N_ ("E35: No previous regular expression"));
EXTERN char_u e_noprev [] INIT (= N_ ("E34: No previous command"));
EXTERN win_T *prevwin INIT (= NULL);
char_u *prev_dir = NULL;
EXTERN char_u e_maxmempat [] INIT (= N_ ("E363: pattern uses more memory than 'maxmempattern'"));
EXTERN char_u e_winheight [] INIT (= N_ ("E591: 'winheight' cannot be smaller than 'winminheight'"));
EXTERN char_u e_notopen [] INIT (= N_ ("E484: Can't open file %s"));
EXTERN frame_T *topframe;
EXTERN int *eval_lavars_used INIT (= NULL);
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
EXTERN int called_vim_beep;
EXTERN dict_T globvardict;
EXTERN dict_T vimvardict;
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
EXTERN char_u *p_inc;
EXTERN char_u *p_cpo;
EXTERN char_u *p_cot;
EXTERN int p_cp;
EXTERN long  p_ch;
EXTERN int p_beval;
EXTERN char_u *p_cm;
EXTERN unsigned  bkc_flags;
EXTERN char_u *p_bkc;
EXTERN int p_acd;
struct cmdmod cmdmods [] = {{"aboveleft", 3, FALSE}, {"belowright", 3, FALSE}, {"botright", 2, FALSE}, {"browse", 3, FALSE}, {"confirm", 4, FALSE}, {"filter", 4, FALSE}, {"hide", 3, FALSE}, {"keepalt", 5, FALSE}, {"keepjumps", 5, FALSE}, {"keepmarks", 3, FALSE}, {"keeppatterns", 5, FALSE}, {"leftabove", 5, FALSE}, {"lockmarks", 3, FALSE}, {"noautocmd", 3, FALSE}, {"noswapfile", 3, FALSE}, {"rightbelow", 6, FALSE}, {"sandbox", 3, FALSE}, {"silent", 3, FALSE}, {"tab", 3, TRUE}, {"topleft", 2, FALSE}, {"unsilent", 3, FALSE}, {"verbose", 4, TRUE}, {"vertical", 4, FALSE},};
char_u dollar_command [2] = {'$', 0};
garray_T ucmds = {0, 0, sizeof (ucmd_T), 4, NULL};
EXTERN proftime_T bevalexpr_due;
EXTERN char_u e_invexpr2 [] INIT (= N_ ("E15: Invalid expression: %s"));
EXTERN char_u *p_pexpr;
EXTERN char_u *p_bexpr;
EXTERN int arrow_used;
EXTERN int mouse_row;
EXTERN int cmdline_row;
EXTERN char_u e_invargval [] INIT (= N_ ("E475: Invalid value for argument %s"));
EXTERN int autocmd_fname_full;
EXTERN char_u *autocmd_fname INIT (= NULL);
EXTERN unsigned  swb_flags;
EXTERN time_T starttime;
EXTERN int stop_insert_mode;
EXTERN pos_T where_paste_started;
EXTERN char *font_argument INIT (= NULL);
EXTERN int p_guipty;
EXTERN char_u *p_guifont;
EXTERN char need_key_msg [] INIT (= N_ ("Need encryption key for \"%s\""));
EXTERN char bot_top_msg [] INIT (= N_ ("search hit BOTTOM, continuing at TOP"));
EXTERN char top_bot_msg [] INIT (= N_ ("search hit TOP, continuing at BOTTOM"));
EXTERN char_u no_lines_msg [] INIT (= N_ ("--No lines in buffer--"));
EXTERN struct msglist **msg_list INIT (= NULL);
EXTERN int called_emsg;
EXTERN char_u *keep_msg INIT (= NULL);
EXTERN int msg_scrolled;
EXTERN int msg_row;
const unsigned  char cmdidxs2 [26] [26] = {{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 6, 0, 0, 0, 7, 15, 0, 16, 0, 0, 0, 0, 0}, {2, 0, 0, 4, 5, 7, 0, 0, 0, 0, 0, 8, 9, 10, 11, 12, 0, 13, 0, 0, 0, 0, 22, 0, 0, 0}, {3, 10, 12, 14, 16, 18, 21, 0, 0, 0, 0, 29, 33, 36, 42, 51, 53, 54, 55, 0, 57, 0, 60, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 6, 15, 0, 16, 0, 0, 17, 0, 0, 19, 20, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 7, 9, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 4, 5, 0, 0, 0, 0}, {5, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 3, 0, 0, 0, 4, 0, 5, 6, 0, 0, 0, 0, 0, 13, 0, 15, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {3, 9, 11, 15, 16, 20, 23, 28, 0, 0, 0, 30, 33, 36, 40, 46, 0, 48, 57, 49, 50, 54, 56, 0, 0, 0}, {1, 0, 0, 0, 9, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 8, 10, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 5, 0, 0, 0, 0, 0, 0, 9, 0, 11, 0, 0, 0}, {1, 0, 3, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 9, 0, 0, 16, 17, 26, 0, 27, 0, 28, 0}, {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 18, 0, 0, 0, 0}, {2, 6, 15, 0, 18, 22, 0, 24, 25, 0, 0, 28, 30, 34, 38, 40, 0, 48, 0, 49, 0, 61, 62, 0, 63, 0}, {2, 0, 19, 0, 22, 24, 0, 25, 0, 26, 0, 27, 28, 31, 33, 34, 0, 35, 37, 0, 38, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 9, 12, 0, 0, 0, 0, 15, 0, 16, 0, 0, 0, 0, 0}, {2, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 0, 8, 0, 9, 10, 0, 12, 0, 13, 14, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
const unsigned  short  cmdidxs1 [26] = {0, 19, 42, 103, 125, 145, 161, 167, 176, 194, 196, 201, 259, 279, 299, 311, 350, 353, 372, 439, 479, 490, 508, 523, 532, 533};
EXTERN char_u e_invalidreg [] INIT (= N_ ("E850: Invalid register name"));
EXTERN char_u e_usingsid [] INIT (= N_ ("E81: Using <SID> not in a script context"));
EXTERN char_u e_winwidth [] INIT (= N_ ("E592: 'winwidth' cannot be smaller than 'winminwidth'"));
EXTERN char_u e_listidx [] INIT (= N_ ("E684: list index out of range: %ld"));
EXTERN hlf_T edit_submode_highl;
EXTERN int ru_wid;
EXTERN int did_emsg_syntax;
EXTERN int did_emsg;
EXTERN int p_tbidi;
EXTERN int p_hls;
EXTERN char_u *p_hl;
EXTERN int p_hid;
EXTERN char_u *p_hlg;
int did_lcd;
EXTERN char_u e_au_recursive [] INIT (= N_ ("E952: Autocommand caused recursive behavior"));
EXTERN char_u e_secure [] INIT (= N_ ("E523: Not allowed here"));
EXTERN char_u e_positive [] INIT (= N_ ("E487: Argument must be positive"));
EXTERN char_u e_curdir [] INIT (= N_ ("E12: Command not allowed from exrc/vimrc in current dir or tag search"));
EXTERN pos_T saved_cursor;
EXTERN tabpage_T *curtab;
EXTERN win_T *curwin;
EXTERN int current_scrollbar;
EXTERN vimmenu_T *current_menu;
EXTERN except_T *current_exception;
EXTERN int p_secure;
EXTERN char_u e_nobufnr [] INIT (= N_ ("E86: Buffer %ld does not exist"));
EXTERN char_u e_emptybuf [] INIT (= N_ ("E749: empty buffer"));
EXTERN char_u e_invexprmsg [] INIT (= N_ ("E449: Invalid expression received"));
EXTERN char_u e_notmp [] INIT (= N_ ("E483: Can't get temp file name"));
EXTERN pos_T last_cursormoved;
EXTERN char_u msg_buf [MSG_BUF_LEN];
EXTERN char_u *IObuff;
EXTERN buf_T *curbuf INIT (= NULL);
EXTERN buf_T *lastbuf INIT (= NULL);
EXTERN buf_T *firstbuf INIT (= NULL);
EXTERN buf_T *au_pending_free_buf INIT (= NULL);
EXTERN int highlight_attr [HLF_COUNT];
EXTERN long  p_ttm;
EXTERN long  p_tm;
EXTERN int p_stmp;
EXTERN int p_lrm;
EXTERN int p_confirm;
EXTERN int p_bevalterm;
int quitmore = 0;
EXTERN typebuf_T typebuf;
EXTERN long_u scrollbar_value;
EXTERN except_T *caught_stack INIT (= NULL);
EXTERN int did_uncaught_emsg;
int filetype_indent = FALSE;
int filetype_plugin = FALSE;
int filetype_detect = FALSE;
EXTERN int searchcmdlen;
EXTERN long  p_titlelen;
const int command_count = 546;
EXTERN char_u e_zerocount [] INIT (= N_ ("E939: Positive count required"));
EXTERN char_u e_nomatch2 [] INIT (= N_ ("E480: No match: %s"));
EXTERN char_u e_nomatch [] INIT (= N_ ("E479: No match"));
EXTERN char_u *autocmd_match INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_out INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_in INIT (= NULL);
EXTERN linenr_T search_match_lines;
EXTERN int sc_col;
EXTERN int ru_col;
EXTERN int mouse_col;
EXTERN colnr_T search_match_endcol;
EXTERN int msg_col;
EXTERN int p_cc_cols [256];
EXTERN long  p_columnspace;
EXTERN int fuoptions_bgcolor;
EXTERN pos_T Insstart_orig;
EXTERN pos_T Insstart;
EXTERN pos_T VIsual;
EXTERN char_u *p_hf;
EXTERN long  p_hh;
EXTERN int p_lnr;
EXTERN int p_js;
EXTERN int p_is;
EXTERN char_u e_bufloaded [] INIT (= N_ ("E139: File is loaded in another buffer"));

int do_cmdline (char_u *cmdline, char_u * (*fgetline) (int, void *, int), void *cookie, int flags) {
    char_u *next_cmdline;
    char_u *cmdline_copy = NULL;
    int used_getline = FALSE;
    static int recursive = 0;
    int msg_didout_before_start = 0;
    int count = 0;
    int did_inc = FALSE;
    int retval = OK;
    struct condstack cstack;
    garray_T lines_ga;
    int current_line = 0;
    char_u *fname = NULL;
    linenr_T *breakpoint = NULL;
    int *dbg_tick = NULL;
    struct dbg_stuff debug_saved;
    int initial_trylevel;
    struct msglist **saved_msg_list = NULL;
    struct msglist *private_msg_list;
    char_u * (*cmd_getline) (int, void *, int);
    void *cmd_cookie;
    struct loop_cookie cmd_loop_cookie;
    void *real_cookie;
    int getline_is_func;
    static int call_depth = 0;
    saved_msg_list = msg_list;
    msg_list = &private_msg_list;
    private_msg_list = NULL;
    if (call_depth >= 200 && call_depth >= p_mfd) {
        EMSG (_ ("E169: Command too recursive"));
        do_errthrow ((struct condstack *) NULL, (char_u *) NULL);
        msg_list = saved_msg_list;
        return FAIL;
    }
    ++call_depth;
    cstack.cs_idx = -1;
    cstack.cs_looplevel = 0;
    cstack.cs_trylevel = 0;
    cstack.cs_emsg_silent_list = NULL;
    cstack.cs_lflags = 0;
    ga_init2 (& lines_ga, (int) sizeof (wcmd_T), 10);
    real_cookie = getline_cookie (fgetline, cookie);
    getline_is_func = getline_equal (fgetline, cookie, get_func_line);
    if (getline_is_func && ex_nesting_level == func_level (real_cookie))
        ++ex_nesting_level;
    if (getline_is_func) {
        fname = func_name (real_cookie);
        breakpoint = func_breakpoint (real_cookie);
        dbg_tick = func_dbg_tick (real_cookie);
    }
    else if (getline_equal (fgetline, cookie, getsourceline)) {
        fname = sourcing_name;
        breakpoint = source_breakpoint (real_cookie);
        dbg_tick = source_dbg_tick (real_cookie);
    }
    if (!recursive) {
        force_abort = FALSE;
        suppress_errthrow = FALSE;
    }
    if (flags & DOCMD_EXCRESET)
        save_dbg_stuff (&debug_saved);
    else
        vim_memset (&debug_saved, 0, sizeof (debug_saved));
    initial_trylevel = trylevel;
    did_throw = FALSE;
    did_emsg = FALSE;
    if (!(flags & DOCMD_KEYTYPED) && !getline_equal (fgetline, cookie, getexline))
        KeyTyped = FALSE;
    next_cmdline = cmdline;
    do {
        getline_is_func = getline_equal (fgetline, cookie, get_func_line);
        if (next_cmdline == NULL && !force_abort && cstack.cs_idx < 0 && !(getline_is_func && func_has_abort (real_cookie)))
            did_emsg = FALSE;
        if (cstack.cs_looplevel > 0 && current_line < lines_ga.ga_len) {
            VIM_CLEAR (cmdline_copy);
            if (getline_is_func) {
                if (do_profiling == PROF_YES)
                    func_line_end (real_cookie);
                if (func_has_ended (real_cookie)) {
                    retval = FAIL;
                    break;
                }
            }
            else if (do_profiling == PROF_YES && getline_equal (fgetline, cookie, getsourceline))
                script_line_end ();
            if (source_finished (fgetline, cookie)) {
                retval = FAIL;
                break;
            }
            if (breakpoint != NULL && dbg_tick != NULL && *dbg_tick != debug_tick) {
                *breakpoint = dbg_find_breakpoint (getline_equal (fgetline, cookie, getsourceline), fname, sourcing_lnum);
                *dbg_tick = debug_tick;
            }
            next_cmdline = ((wcmd_T *) (lines_ga.ga_data))[current_line].line;
            sourcing_lnum = ((wcmd_T *) (lines_ga.ga_data))[current_line].lnum;
            if (breakpoint != NULL && *breakpoint != 0 && *breakpoint <= sourcing_lnum) {
                dbg_breakpoint (fname, sourcing_lnum);
                *breakpoint = dbg_find_breakpoint (getline_equal (fgetline, cookie, getsourceline), fname, sourcing_lnum);
                *dbg_tick = debug_tick;
            }
            if (do_profiling == PROF_YES) {
                if (getline_is_func)
                    func_line_start (real_cookie);
                else if (getline_equal (fgetline, cookie, getsourceline))
                    script_line_start ();
            }
        }
        if (cstack.cs_looplevel > 0) {
            cmd_getline = get_loop_line;
            cmd_cookie = (void *) &cmd_loop_cookie;
            cmd_loop_cookie.lines_gap = &lines_ga;
            cmd_loop_cookie.current_line = current_line;
            cmd_loop_cookie.getline = fgetline;
            cmd_loop_cookie.cookie = cookie;
            cmd_loop_cookie.repeating = (current_line < lines_ga.ga_len);
        }
        else {
            cmd_getline = fgetline;
            cmd_cookie = cookie;
        }
        if (next_cmdline == NULL) {
            if (count == 1 && getline_equal (fgetline, cookie, getexline))
                msg_didout = TRUE;
            if (fgetline == NULL || (next_cmdline = fgetline (':', cookie, cstack.cs_idx < 0 ? 0 : (cstack.cs_idx + 1) * 2)) == NULL) {
                if (KeyTyped && !(flags & DOCMD_REPEAT))
                    need_wait_return = FALSE;
                retval = FAIL;
                break;
            }
            used_getline = TRUE;
            if (flags & DOCMD_KEEPLINE) {
                vim_free (repeat_cmdline);
                if (count == 0)
                    repeat_cmdline = vim_strsave (next_cmdline);
                else
                    repeat_cmdline = NULL;
            }
        }
        else if (cmdline_copy == NULL) {
            next_cmdline = vim_strsave (next_cmdline);
            if (next_cmdline == NULL) {
                EMSG (_ (e_outofmem));
                retval = FAIL;
                break;
            }
        }
        cmdline_copy = next_cmdline;
        if (current_line == lines_ga.ga_len && (cstack.cs_looplevel || has_loop_cmd (next_cmdline))) {
            if (store_loop_line (&lines_ga, next_cmdline) == FAIL) {
                retval = FAIL;
                break;
            }
        }
        did_endif = FALSE;
        if (count++ == 0) {
            if (!(flags & DOCMD_NOWAIT) && !recursive) {
                msg_didout_before_start = msg_didout;
                msg_didany = FALSE;
                msg_start ();
                msg_scroll = TRUE;
                ++no_wait_return;
                ++RedrawingDisabled;
                did_inc = TRUE;
            }
        }
        if (p_verbose >= 15 && sourcing_name != NULL) {
            ++no_wait_return;
            verbose_enter_scroll ();
            smsg ((char_u *) _ ("line %ld: %s"), (long) sourcing_lnum, cmdline_copy);
            if (msg_silent == 0)
                msg_puts ((char_u *) "\n");
            verbose_leave_scroll ();
            --no_wait_return;
        }
        ++recursive;
        next_cmdline = do_one_cmd (&cmdline_copy, flags &DOCMD_VERBOSE, &cstack, cmd_getline, cmd_cookie);
        --recursive;
        if (cmd_cookie == (void *) &cmd_loop_cookie)
            current_line = cmd_loop_cookie.current_line;
        if (next_cmdline == NULL) {
            VIM_CLEAR (cmdline_copy);
        }
        else {
            STRMOVE (cmdline_copy, next_cmdline);
            next_cmdline = cmdline_copy;
        }
        if (did_emsg && !force_abort && getline_equal (fgetline, cookie, get_func_line) && !func_has_abort (real_cookie))
            did_emsg = FALSE;
        if (cstack.cs_looplevel > 0) {
            ++current_line;
            if (cstack.cs_lflags & (CSL_HAD_CONT | CSL_HAD_ENDLOOP)) {
                cstack.cs_lflags &= ~(CSL_HAD_CONT | CSL_HAD_ENDLOOP);
                if (!did_emsg && !got_int && !did_throw && cstack.cs_idx >= 0 && (cstack.cs_flags[cstack.cs_idx] & (CSF_WHILE | CSF_FOR)) && cstack.cs_line[cstack.cs_idx] >= 0 && (cstack.cs_flags[cstack.cs_idx] & CSF_ACTIVE)) {
                    current_line = cstack.cs_line[cstack.cs_idx];
                    cstack.cs_lflags |= CSL_HAD_LOOP;
                    line_breakcheck ();
                    if (breakpoint != NULL) {
                        *breakpoint = dbg_find_breakpoint (getline_equal (fgetline, cookie, getsourceline), fname, ((wcmd_T *) lines_ga.ga_data)[current_line].lnum - 1);
                        *dbg_tick = debug_tick;
                    }
                }
                else {
                    if (cstack.cs_idx >= 0)
                        rewind_conditionals (&cstack, cstack.cs_idx - 1, CSF_WHILE | CSF_FOR, &cstack.cs_looplevel);
                }
            }
            else if (cstack.cs_lflags & CSL_HAD_LOOP) {
                cstack.cs_lflags &= ~CSL_HAD_LOOP;
                cstack.cs_line[cstack.cs_idx] = current_line - 1;
            }
        }
        if (breakpoint != NULL && has_watchexpr ()) {
            *breakpoint = dbg_find_breakpoint (FALSE, fname, sourcing_lnum);
            *dbg_tick = debug_tick;
        }
        if (cstack.cs_looplevel == 0) {
            if (lines_ga.ga_len > 0) {
                sourcing_lnum = ((wcmd_T *) lines_ga.ga_data)[lines_ga.ga_len - 1].lnum;
                free_cmdlines (& lines_ga);
            }
            current_line = 0;
        }
        if (cstack.cs_lflags & CSL_HAD_FINA) {
            cstack.cs_lflags &= ~CSL_HAD_FINA;
            report_make_pending (cstack.cs_pending [cstack.cs_idx] & (CSTP_ERROR | CSTP_INTERRUPT | CSTP_THROW), did_throw ? (void *) current_exception : NULL);
            did_emsg = got_int = did_throw = FALSE;
            cstack.cs_flags[cstack.cs_idx] |= CSF_ACTIVE | CSF_FINALLY;
        }
        trylevel = initial_trylevel + cstack.cs_trylevel;
        if (trylevel == 0 && !did_emsg && !got_int && !did_throw)
            force_abort = FALSE;
        (void) do_intthrow (&cstack);
    }
    while (!((got_int || (did_emsg && force_abort) || did_throw) && cstack.cs_trylevel == 0) && !(did_emsg && (cstack.cs_trylevel == 0 || did_emsg_syntax) && used_getline && (getline_equal (fgetline, cookie, getexmodeline) || getline_equal (fgetline, cookie, getexline))) && (next_cmdline != NULL || cstack.cs_idx >= 0 || (flags & DOCMD_REPEAT)));
    vim_free (cmdline_copy);
    did_emsg_syntax = FALSE;
    free_cmdlines (& lines_ga);
    ga_clear (& lines_ga);
    if (cstack.cs_idx >= 0) {
        if (!got_int && !did_throw && ((getline_equal (fgetline, cookie, getsourceline) && !source_finished (fgetline, cookie)) || (getline_equal (fgetline, cookie, get_func_line) && !func_has_ended (real_cookie)))) {
            if (cstack.cs_flags[cstack.cs_idx] & CSF_TRY)
                EMSG (_ (e_endtry));
            else if (cstack.cs_flags[cstack.cs_idx] & CSF_WHILE)
                EMSG (_ (e_endwhile));
            else if (cstack.cs_flags[cstack.cs_idx] & CSF_FOR)
                EMSG (_ (e_endfor));
            else
                EMSG (_ (e_endif));
        }
        do {
            int idx = cleanup_conditionals (&cstack, 0, TRUE);
            if (idx >= 0)
                --idx;
            rewind_conditionals (& cstack, idx, CSF_WHILE | CSF_FOR, & cstack.cs_looplevel);
        }
        while (cstack.cs_idx >= 0);
        trylevel = initial_trylevel;
    }
    do_errthrow (& cstack, getline_equal (fgetline, cookie, get_func_line) ? (char_u *) "endfunction" : (char_u *) NULL);
    if (trylevel == 0) {
        if (did_throw) {
            void *p = NULL;
            char_u *saved_sourcing_name;
            int saved_sourcing_lnum;
            struct msglist *messages = NULL, *next;
            switch (current_exception->type) {
            case ET_USER :
                vim_snprintf ((char *) IObuff, IOSIZE, _ ("E605: Exception not caught: %s"), current_exception->value);
                p = vim_strsave (IObuff);
                break;
            case ET_ERROR :
                messages = current_exception->messages;
                current_exception->messages = NULL;
                break;
            case ET_INTERRUPT :
                break;
            }
            saved_sourcing_name = sourcing_name;
            saved_sourcing_lnum = sourcing_lnum;
            sourcing_name = current_exception->throw_name;
            sourcing_lnum = current_exception->throw_lnum;
            current_exception->throw_name = NULL;
            discard_current_exception ();
            suppress_errthrow = TRUE;
            force_abort = TRUE;
            if (messages != NULL) {
                do {
                    next = messages->next;
                    emsg (messages -> msg);
                    vim_free (messages -> msg);
                    vim_free (messages);
                    messages = next;
                }
                while (messages != NULL);
            }
            else if (p != NULL) {
                emsg (p);
                vim_free (p);
            }
            vim_free (sourcing_name);
            sourcing_name = saved_sourcing_name;
            sourcing_lnum = saved_sourcing_lnum;
        }
        else if (got_int || (did_emsg && force_abort))
            suppress_errthrow = TRUE;
    }
    if (did_throw)
        need_rethrow = TRUE;
    if ((getline_equal (fgetline, cookie, getsourceline) && ex_nesting_level > source_level (real_cookie)) || (getline_equal (fgetline, cookie, get_func_line) && ex_nesting_level > func_level (real_cookie) + 1)) {
        if (!did_throw)
            check_cstack = TRUE;
    }
    else {
        if (getline_equal (fgetline, cookie, get_func_line))
            --ex_nesting_level;
        if ((getline_equal (fgetline, cookie, getsourceline) || getline_equal (fgetline, cookie, get_func_line)) && ex_nesting_level + 1 <= debug_break_level)
            do_debug (getline_equal (fgetline, cookie, getsourceline) ? (char_u *) _ ("End of sourced file") : (char_u *) _ ("End of function"));
    }
    if (flags & DOCMD_EXCRESET)
        restore_dbg_stuff (&debug_saved);
    msg_list = saved_msg_list;
    if (did_inc) {
        --RedrawingDisabled;
        --no_wait_return;
        msg_scroll = FALSE;
        if (retval == FAIL || (did_endif && KeyTyped && !did_emsg)) {
            need_wait_return = FALSE;
            msg_didany = FALSE;
        }
        else if (need_wait_return) {
            msg_didout |= msg_didout_before_start;
            wait_return (FALSE);
        }
    }
    did_endif = FALSE;
    --call_depth;
    return retval;
}

int ends_excmd (int c) {
    return (c == NUL || c == '|' || c == '"' || c == '\n');
}

char_u *check_nextcmd (char_u *p) {
    char_u *s = skipwhite (p);
    if (*s == '|' || *s == '\n')
        return (s + 1);
    else
        return NULL;
}

void uc_clear (garray_T *gap) {
    int i;
    ucmd_T *cmd;
    for (i = 0; i < gap->ga_len; ++i) {
        cmd = USER_CMD_GA (gap, i);
        vim_free (cmd -> uc_name);
        vim_free (cmd -> uc_rep);
        vim_free (cmd -> uc_compl_arg);
    }
    ga_clear (gap);
}

void alist_unlink (alist_T *al) {
    if (al != &global_alist && --al->al_refcount <= 0) {
        alist_clear (al);
        vim_free (al);
    }
}

void alist_clear (alist_T *al) {
    while (--al->al_ga.ga_len >= 0)
        vim_free (AARGLIST (al)[al->al_ga.ga_len].ae_fname);
    ga_clear (& al -> al_ga);
}

void dialog_msg (char_u *buff, char *format, char_u *fname) {
    if (fname == NULL)
        fname = (char_u *) _ ("Untitled");
    vim_snprintf ((char *) buff, DIALOG_MSG_SIZE, format, fname);
}

int do_cmdline_cmd (char_u *cmd) {
    return do_cmdline (cmd, NULL, NULL, DOCMD_VERBOSE | DOCMD_NOWAIT | DOCMD_KEYTYPED);
}

void do_exmode (int improved) {
    int save_msg_scroll;
    int prev_msg_row;
    linenr_T prev_line;
    varnumber_T changedtick;
    if (improved)
        exmode_active = EXMODE_VIM;
    else
        exmode_active = EXMODE_NORMAL;
    State = NORMAL;
    if (global_busy)
        return;
    save_msg_scroll = msg_scroll;
    ++RedrawingDisabled;
    ++no_wait_return;
    ++hold_gui_events;
    MSG (_ ("Entering Ex mode.  Type \"visual\" to go to Normal mode."));
    while (exmode_active) {
        if (ex_normal_busy > 0 && typebuf.tb_len == 0) {
            exmode_active = FALSE;
            break;
        }
        msg_scroll = TRUE;
        need_wait_return = FALSE;
        ex_pressedreturn = FALSE;
        ex_no_reprint = FALSE;
        changedtick = CHANGEDTICK (curbuf);
        prev_msg_row = msg_row;
        prev_line = curwin->w_cursor.lnum;
        if (improved) {
            cmdline_row = msg_row;
            do_cmdline (NULL, getexline, NULL, 0);
        }
        else
            do_cmdline (NULL, getexmodeline, NULL, DOCMD_NOWAIT);
        lines_left = Rows - 1;
        if ((prev_line != curwin->w_cursor.lnum || changedtick != CHANGEDTICK (curbuf)) && !ex_no_reprint) {
            if (curbuf->b_ml.ml_flags & ML_EMPTY)
                EMSG (_ (e_emptybuf));
            else {
                if (ex_pressedreturn) {
                    msg_row = prev_msg_row;
                    if (prev_msg_row == Rows - 1)
                        msg_row--;
                }
                msg_col = 0;
                print_line_no_prefix (curwin -> w_cursor.lnum, FALSE, FALSE);
                msg_clr_eos ();
            }
        }
        else if (ex_pressedreturn && !ex_no_reprint) {
            if (curbuf->b_ml.ml_flags & ML_EMPTY)
                EMSG (_ (e_emptybuf));
            else
                EMSG (_ ("E501: At end-of-file"));
        }
    }
    --hold_gui_events;
    --RedrawingDisabled;
    --no_wait_return;
    update_screen (CLEAR);
    need_wait_return = FALSE;
    msg_scroll = save_msg_scroll;
}

void do_sleep (long  msec) {
    long  done;
    long  wait_now;
    cursor_on ();
    out_flush ();
    for (done = 0; !got_int && done < msec; done += wait_now) {
        wait_now = msec - done > 1000L ? 1000L : msec - done;
        {
            long  due_time = check_due_timer ();
            if (due_time > 0 && due_time < wait_now)
                wait_now = due_time;
        }
        if (has_any_channel () && wait_now > 100L)
            wait_now = 100L;
        ui_delay (wait_now, TRUE);
        if (has_any_channel ())
            ui_breakcheck_force (TRUE);
        else
            ui_breakcheck ();
    }
}

void tabpage_new (void) {
    exarg_T ea;
    vim_memset (& ea, 0, sizeof (ea));
    ea.cmdidx = CMD_tabnew;
    ea.cmd = (char_u *) "tabn";
    ea.arg = (char_u *) "";
    ex_splitview (& ea);
}

void ex_splitview (exarg_T *eap) {
    win_T *old_curwin = curwin;
    char_u *fname = NULL;
    need_mouse_correct = TRUE;
    if (bt_quickfix (curbuf) && cmdmod.tab == 0) {
        if (eap->cmdidx == CMD_split)
            eap->cmdidx = CMD_new;
        if (eap->cmdidx == CMD_vsplit)
            eap->cmdidx = CMD_vnew;
    }
    if (eap->cmdidx == CMD_sfind || eap->cmdidx == CMD_tabfind) {
        fname = find_file_in_path (eap->arg, (int) STRLEN (eap->arg), FNAME_MESS, TRUE, curbuf->b_ffname);
        if (fname == NULL)
            goto theend;
        eap->arg = fname;
    }
    if (eap->cmdidx == CMD_tabedit || eap->cmdidx == CMD_tabfind || eap->cmdidx == CMD_tabnew) {
        if (win_new_tabpage (cmdmod.tab != 0 ? cmdmod.tab : eap->addr_count == 0 ? 0 : (int) eap->line2 + 1) != FAIL) {
            do_exedit (eap, old_curwin);
            if (curwin != old_curwin && win_valid (old_curwin) && old_curwin->w_buffer != curbuf && !cmdmod.keepalt)
                old_curwin->w_alt_fnum = curbuf->b_fnum;
        }
    }
    else if (win_split (eap->addr_count > 0 ? (int) eap->line2 : 0, *eap->cmd == 'v' ? WSP_VERT : 0) != FAIL) {
        if (*eap->arg != NUL) {
            RESET_BINDING (curwin);
        }
        else
            do_check_scrollbind (FALSE);
        do_exedit (eap, old_curwin);
    }
theend :
    vim_free (fname);
}

void do_exedit (exarg_T *eap, win_T *old_curwin) {
    int n;
    int need_hide;
    int exmode_was = exmode_active;
    if (exmode_active && (eap->cmdidx == CMD_visual || eap->cmdidx == CMD_view)) {
        exmode_active = FALSE;
        if (*eap->arg == NUL) {
            if (global_busy) {
                int rd = RedrawingDisabled;
                int nwr = no_wait_return;
                int ms = msg_scroll;
                int he = hold_gui_events;
                if (eap->nextcmd != NULL) {
                    stuffReadbuff (eap -> nextcmd);
                    eap->nextcmd = NULL;
                }
                if (exmode_was != EXMODE_VIM)
                    settmode (TMODE_RAW);
                RedrawingDisabled = 0;
                no_wait_return = 0;
                need_wait_return = FALSE;
                msg_scroll = 0;
                hold_gui_events = 0;
                must_redraw = CLEAR;
                main_loop (FALSE, TRUE);
                RedrawingDisabled = rd;
                no_wait_return = nwr;
                msg_scroll = ms;
                hold_gui_events = he;
            }
            return;
        }
    }
    if ((eap->cmdidx == CMD_new || eap->cmdidx == CMD_tabnew || eap->cmdidx == CMD_tabedit || eap->cmdidx == CMD_vnew) && *eap->arg == NUL) {
        setpcmark ();
        (void) do_ecmd (0, NULL, NULL, eap, ECMD_ONE, ECMD_HIDE +(eap->forceit ? ECMD_FORCEIT : 0), old_curwin == NULL ? curwin : NULL);
    }
    else if ((eap->cmdidx != CMD_split && eap->cmdidx != CMD_vsplit) || *eap->arg != NUL) {
        if (*eap->arg != NUL && curbuf_locked ())
            return;
        n = readonlymode;
        if (eap->cmdidx == CMD_view || eap->cmdidx == CMD_sview)
            readonlymode = TRUE;
        else if (eap->cmdidx == CMD_enew)
            readonlymode = FALSE;
        setpcmark ();
        if (do_ecmd (0, (eap->cmdidx == CMD_enew ? NULL : eap->arg), NULL, eap, (*eap->arg == NUL && eap->do_ecmd_lnum == 0 && vim_strchr (p_cpo, CPO_GOTO1) != NULL) ? ECMD_ONE : eap->do_ecmd_lnum, (buf_hide (curbuf) ? ECMD_HIDE : 0) + (eap->forceit ? ECMD_FORCEIT : 0) + (old_curwin != NULL ? ECMD_OLDBUF : 0) + (eap->cmdidx == CMD_badd ? ECMD_ADDBUF : 0), old_curwin == NULL ? curwin : NULL) == FAIL) {
            if (old_curwin != NULL) {
                need_hide = (curbufIsChanged () && curbuf->b_nwindows <= 1);
                if (!need_hide || buf_hide (curbuf)) {
                    cleanup_T cs;
                    enter_cleanup (& cs);
                    need_mouse_correct = TRUE;
                    win_close (curwin, ! need_hide && ! buf_hide (curbuf));
                    leave_cleanup (& cs);
                }
            }
        }
        else if (readonlymode && curbuf->b_nwindows == 1) {
            curbuf->b_p_ro = TRUE;
        }
        readonlymode = n;
    }
    else {
        if (eap->do_ecmd_cmd != NULL)
            do_cmdline_cmd (eap->do_ecmd_cmd);
        n = curwin->w_arg_idx_invalid;
        check_arg_idx (curwin);
        if (n != curwin->w_arg_idx_invalid)
            maketitle ();
    }
    if (old_curwin != NULL && *eap->arg != NUL && curwin != old_curwin && win_valid (old_curwin) && old_curwin->w_buffer != curbuf && !cmdmod.keepalt)
        old_curwin->w_alt_fnum = curbuf->b_fnum;
    ex_no_reprint = TRUE;
}

void tabpage_close (int forceit) {
    if (!ONE_WINDOW)
        close_others (TRUE, forceit);
    if (ONE_WINDOW)
        ex_win_close (forceit, curwin, NULL);
    need_mouse_correct = TRUE;
}

static void ex_win_close (int forceit, win_T *win, tabpage_T *tp) {
    int need_hide;
    buf_T *buf = win->w_buffer;
    need_hide = (bufIsChanged (buf) && buf->b_nwindows <= 1);
    if (need_hide && !buf_hide (buf) && !forceit) {
        if ((p_confirm || cmdmod.confirm) && p_write) {
            bufref_T bufref;
            set_bufref (& bufref, buf);
            dialog_changed (buf, FALSE);
            if (bufref_valid (&bufref) && bufIsChanged (buf))
                return;
            need_hide = FALSE;
        }
        else {
            no_write_message ();
            return;
        }
    }
    need_mouse_correct = TRUE;
    if (tp == NULL)
        win_close (win, !need_hide && !buf_hide (buf));
    else
        win_close_othertab (win, !need_hide && !buf_hide (buf), tp);
}

void tabpage_close_other (tabpage_T *tp, int forceit) {
    int done = 0;
    win_T *wp;
    int h = tabline_height ();
    while (++done < 1000) {
        wp = tp->tp_firstwin;
        ex_win_close (forceit, wp, tp);
        if (!valid_tabpage (tp) || tp->tp_firstwin == wp)
            break;
    }
    apply_autocmds (EVENT_TABCLOSED, NULL, NULL, FALSE, curbuf);
    redraw_tabline = TRUE;
    if (h != tabline_height ())
        shell_new_rows ();
}

char_u *set_one_cmd_context (expand_T *xp, char_u *buff) {
    char_u *p;
    char_u *cmd, *arg;
    int len = 0;
    exarg_T ea;
    int compl = EXPAND_NOTHING;
    int delim;
    int forceit = FALSE;
    int usefilter = FALSE;
    ExpandInit (xp);
    xp->xp_pattern = buff;
    xp->xp_context = EXPAND_COMMANDS;
    ea.argt = 0;
    for (cmd = buff; vim_strchr ((char_u *) " \t:|", *cmd) != NULL; cmd++)
        ;
    xp->xp_pattern = cmd;
    if (*cmd == NUL)
        return NULL;
    if (*cmd == '"') {
        xp->xp_context = EXPAND_NOTHING;
        return NULL;
    }
    cmd = skip_range (cmd, &xp->xp_context);
    xp->xp_pattern = cmd;
    if (*cmd == NUL)
        return NULL;
    if (*cmd == '"') {
        xp->xp_context = EXPAND_NOTHING;
        return NULL;
    }
    if (*cmd == '|' || *cmd == '\n')
        return cmd + 1;
    if (*cmd == 'k' && cmd[1] != 'e') {
        ea.cmdidx = CMD_k;
        p = cmd + 1;
    }
    else {
        p = cmd;
        while (ASCII_ISALPHA (*p) || *p == '*')
            ++p;
        if (ASCII_ISUPPER (cmd[0]))
            while (ASCII_ISALNUM (*p) || *p == '*')
                ++p;
        if (cmd[0] == 'p' && cmd[1] == 'y' && p == cmd + 2 && *p == '3') {
            ++p;
            while (ASCII_ISALPHA (*p) || *p == '*')
                ++p;
        }
        if (p == cmd && vim_strchr ((char_u *) "@*!=><&~#", *p) != NULL)
            ++p;
        len = (int) (p - cmd);
        if (len == 0) {
            xp->xp_context = EXPAND_UNSUCCESSFUL;
            return NULL;
        }
        for (ea.cmdidx = (cmdidx_T) 0; (int) ea.cmdidx < (int) CMD_SIZE; ea.cmdidx = (cmdidx_T) ((int) ea.cmdidx + 1))
            if (STRNCMP (cmdnames[(int) ea.cmdidx].cmd_name, cmd, (size_t) len) == 0)
                break;
        if (cmd[0] >= 'A' && cmd[0] <= 'Z')
            while (ASCII_ISALNUM (*p) || *p == '*')
                ++p;
    }
    if (*p == NUL && ASCII_ISALNUM (p[-1]))
        return NULL;
    if (ea.cmdidx == CMD_SIZE) {
        if (*cmd == 's' && vim_strchr ((char_u *) "cgriI", cmd[1]) != NULL) {
            ea.cmdidx = CMD_substitute;
            p = cmd + 1;
        }
        else if (cmd[0] >= 'A' && cmd[0] <= 'Z') {
            ea.cmd = cmd;
            p = find_ucmd (&ea, p, NULL, xp, &compl);
            if (p == NULL)
                ea.cmdidx = CMD_SIZE;
        }
    }
    if (ea.cmdidx == CMD_SIZE) {
        xp->xp_context = EXPAND_UNSUCCESSFUL;
        return NULL;
    }
    xp->xp_context = EXPAND_NOTHING;
    if (*p == '!') {
        forceit = TRUE;
        ++p;
    }
    if (!IS_USER_CMDIDX (ea.cmdidx))
        ea.argt = (long ) cmdnames[(int) ea.cmdidx].cmd_argt;
    arg = skipwhite (p);
    if (ea.cmdidx == CMD_write || ea.cmdidx == CMD_update) {
        if (*arg == '>') {
            if (*++arg == '>')
                ++arg;
            arg = skipwhite (arg);
        }
        else if (*arg == '!' && ea.cmdidx == CMD_write) {
            ++arg;
            usefilter = TRUE;
        }
    }
    if (ea.cmdidx == CMD_read) {
        usefilter = forceit;
        if (*arg == '!') {
            ++arg;
            usefilter = TRUE;
        }
    }
    if (ea.cmdidx == CMD_lshift || ea.cmdidx == CMD_rshift) {
        while (*arg == *cmd)
            ++arg;
        arg = skipwhite (arg);
    }
    if ((ea.argt & EDITCMD) && !usefilter && *arg == '+') {
        p = arg + 1;
        arg = skip_cmd_arg (arg, FALSE);
        if (*arg == NUL)
            return p;
        arg = skipwhite (arg);
    }
    if ((ea.argt & TRLBAR) && !usefilter) {
        p = arg;
        if (ea.cmdidx == CMD_redir && p[0] == '@' && p[1] == '"')
            p += 2;
        while (*p) {
            if (*p == Ctrl_V) {
                if (p[1] != NUL)
                    ++p;
            }
            else if ((*p == '"' && !(ea.argt & NOTRLCOM)) || *p == '|' || *p == '\n') {
                if (*(p - 1) != '\\') {
                    if (*p == '|' || *p == '\n')
                        return p + 1;
                    return NULL;
                }
            }
            MB_PTR_ADV (p);
        }
    }
    if (!(ea.argt & EXTRA) && *arg != NUL && vim_strchr ((char_u *) "|\"", *arg) == NULL)
        return NULL;
    p = buff;
    xp->xp_pattern = p;
    len = (int) STRLEN (buff);
    while (*p && p < buff + len) {
        if (*p == ' ' || *p == TAB) {
            xp->xp_pattern = ++p;
        }
        else {
            if (*p == '\\' && *(p + 1) != NUL)
                ++p;
            MB_PTR_ADV (p);
        }
    }
    if (ea.argt & XFILE) {
        int c;
        int in_quote = FALSE;
        char_u *bow = NULL;
        xp->xp_pattern = skipwhite (arg);
        p = xp->xp_pattern;
        while (*p != NUL) {
            c = *p;
            if (c == '\\' && p[1] != NUL)
                ++p;
            else if (c == '`') {
                if (!in_quote) {
                    xp->xp_pattern = p;
                    bow = p + 1;
                }
                in_quote = !in_quote;
            }
            else if (c == '|' || c == '\n' || c == '"' || (VIM_ISWHITE (c))) {
                len = 0;
                while (*p != NUL) {
                    c = *p;
                    if (c == '`' || vim_isfilec_or_wc (c))
                        break;
                    len = 1;
                    MB_PTR_ADV (p);
                }
                if (in_quote)
                    bow = p;
                else
                    xp->xp_pattern = p;
                p -= len;
            }
            MB_PTR_ADV (p);
        }
        if (bow != NULL && in_quote)
            xp->xp_pattern = bow;
        xp->xp_context = EXPAND_FILES;
        if (usefilter || ea.cmdidx == CMD_bang || ea.cmdidx == CMD_terminal) {
            xp->xp_shell = TRUE;
            if (xp->xp_pattern == skipwhite (arg))
                xp->xp_context = EXPAND_SHELLCMD;
        }
        if (*xp->xp_pattern == '$') {
            for (p = xp->xp_pattern + 1; *p != NUL; ++p)
                if (!vim_isIDc (*p))
                    break;
            if (*p == NUL) {
                xp->xp_context = EXPAND_ENV_VARS;
                ++xp->xp_pattern;
                if (compl != EXPAND_USER_DEFINED && compl != EXPAND_USER_LIST)
                    compl = EXPAND_ENV_VARS;
            }
        }
        if (*xp->xp_pattern == '~') {
            for (p = xp->xp_pattern + 1; *p != NUL && *p != '/'; ++p)
                ;
            if (*p == NUL && p > xp->xp_pattern + 1 && match_user (xp->xp_pattern + 1) == 1) {
                xp->xp_context = EXPAND_USER;
                ++xp->xp_pattern;
            }
        }
    }
    switch (ea.cmdidx) {
    case CMD_find :
    case CMD_sfind :
    case CMD_tabfind :
        if (xp->xp_context == EXPAND_FILES)
            xp->xp_context = EXPAND_FILES_IN_PATH;
        break;
    case CMD_cd :
    case CMD_chdir :
    case CMD_lcd :
    case CMD_lchdir :
        if (xp->xp_context == EXPAND_FILES)
            xp->xp_context = EXPAND_DIRECTORIES;
        break;
    case CMD_help :
        xp->xp_context = EXPAND_HELP;
        xp->xp_pattern = arg;
        break;
    case CMD_aboveleft :
    case CMD_argdo :
    case CMD_belowright :
    case CMD_botright :
    case CMD_browse :
    case CMD_bufdo :
    case CMD_cdo :
    case CMD_cfdo :
    case CMD_confirm :
    case CMD_debug :
    case CMD_folddoclosed :
    case CMD_folddoopen :
    case CMD_hide :
    case CMD_keepalt :
    case CMD_keepjumps :
    case CMD_keepmarks :
    case CMD_keeppatterns :
    case CMD_ldo :
    case CMD_leftabove :
    case CMD_lfdo :
    case CMD_lockmarks :
    case CMD_noautocmd :
    case CMD_noswapfile :
    case CMD_rightbelow :
    case CMD_sandbox :
    case CMD_silent :
    case CMD_tab :
    case CMD_tabdo :
    case CMD_topleft :
    case CMD_verbose :
    case CMD_vertical :
    case CMD_windo :
        return arg;
    case CMD_filter :
        if (*arg != NUL)
            arg = skip_vimgrep_pat (arg, NULL, NULL);
        if (arg == NULL || *arg == NUL) {
            xp->xp_context = EXPAND_NOTHING;
            return NULL;
        }
        return skipwhite (arg);
    case CMD_match :
        if (*arg == NUL || !ends_excmd (*arg)) {
            set_context_in_echohl_cmd (xp, arg);
            arg = skipwhite (skiptowhite (arg));
            if (*arg != NUL) {
                xp->xp_context = EXPAND_NOTHING;
                arg = skip_regexp (arg +1, *arg, p_magic, NULL);
            }
        }
        return find_nextcmd (arg);
    case CMD_command :
        while (*arg == '-') {
            arg++;
            p = skiptowhite (arg);
            if (*p == NUL) {
                p = vim_strchr (arg, '=');
                if (p == NULL) {
                    xp->xp_context = EXPAND_USER_CMD_FLAGS;
                    xp->xp_pattern = arg;
                    return NULL;
                }
                if (STRNICMP (arg, "complete", p -arg) == 0) {
                    xp->xp_context = EXPAND_USER_COMPLETE;
                    xp->xp_pattern = p + 1;
                    return NULL;
                }
                else if (STRNICMP (arg, "nargs", p -arg) == 0) {
                    xp->xp_context = EXPAND_USER_NARGS;
                    xp->xp_pattern = p + 1;
                    return NULL;
                }
                else if (STRNICMP (arg, "addr", p -arg) == 0) {
                    xp->xp_context = EXPAND_USER_ADDR_TYPE;
                    xp->xp_pattern = p + 1;
                    return NULL;
                }
                return NULL;
            }
            arg = skipwhite (p);
        }
        p = skiptowhite (arg);
        if (*p == NUL) {
            xp->xp_context = EXPAND_USER_COMMANDS;
            xp->xp_pattern = arg;
            break;
        }
        return skipwhite (p);
    case CMD_delcommand :
        xp->xp_context = EXPAND_USER_COMMANDS;
        xp->xp_pattern = arg;
        break;
    case CMD_global :
    case CMD_vglobal :
        delim = *arg;
        if (delim)
            ++arg;
        while (arg[0] != NUL && arg[0] != delim) {
            if (arg[0] == '\\' && arg[1] != NUL)
                ++arg;
            ++arg;
        }
        if (arg[0] != NUL)
            return arg + 1;
        break;
    case CMD_and :
    case CMD_substitute :
        delim = *arg;
        if (delim) {
            ++arg;
            arg = skip_regexp (arg, delim, p_magic, NULL);
        }
        while (arg[0] != NUL && arg[0] != delim) {
            if (arg[0] == '\\' && arg[1] != NUL)
                ++arg;
            ++arg;
        }
        if (arg[0] != NUL)
            ++arg;
        while (arg[0] && vim_strchr ((char_u *) "|\"#", arg[0]) == NULL)
            ++arg;
        if (arg[0] != NUL)
            return arg;
        break;
    case CMD_isearch :
    case CMD_dsearch :
    case CMD_ilist :
    case CMD_dlist :
    case CMD_ijump :
    case CMD_psearch :
    case CMD_djump :
    case CMD_isplit :
    case CMD_dsplit :
        arg = skipwhite (skipdigits (arg));
        if (*arg == '/') {
            for (++arg; *arg && *arg != '/'; arg++)
                if (*arg == '\\' && arg[1] != NUL)
                    arg++;
            if (*arg) {
                arg = skipwhite (arg +1);
                if (*arg && vim_strchr ((char_u *) "|\"\n", *arg) == NULL)
                    xp->xp_context = EXPAND_NOTHING;
                else
                    return arg;
            }
        }
        break;
    case CMD_autocmd :
        return set_context_in_autocmd (xp, arg, FALSE);
    case CMD_doautocmd :
    case CMD_doautoall :
        return set_context_in_autocmd (xp, arg, TRUE);
    case CMD_set :
        set_context_in_set_cmd (xp, arg, 0);
        break;
    case CMD_setglobal :
        set_context_in_set_cmd (xp, arg, OPT_GLOBAL);
        break;
    case CMD_setlocal :
        set_context_in_set_cmd (xp, arg, OPT_LOCAL);
        break;
    case CMD_tag :
    case CMD_stag :
    case CMD_ptag :
    case CMD_ltag :
    case CMD_tselect :
    case CMD_stselect :
    case CMD_ptselect :
    case CMD_tjump :
    case CMD_stjump :
    case CMD_ptjump :
        if (*p_wop != NUL)
            xp->xp_context = EXPAND_TAGS_LISTFILES;
        else
            xp->xp_context = EXPAND_TAGS;
        xp->xp_pattern = arg;
        break;
    case CMD_augroup :
        xp->xp_context = EXPAND_AUGROUP;
        xp->xp_pattern = arg;
        break;
    case CMD_syntax :
        set_context_in_syntax_cmd (xp, arg);
        break;
    case CMD_let :
    case CMD_if :
    case CMD_elseif :
    case CMD_while :
    case CMD_for :
    case CMD_echo :
    case CMD_echon :
    case CMD_execute :
    case CMD_echomsg :
    case CMD_echoerr :
    case CMD_call :
    case CMD_return :
    case CMD_cexpr :
    case CMD_caddexpr :
    case CMD_cgetexpr :
    case CMD_lexpr :
    case CMD_laddexpr :
    case CMD_lgetexpr :
        set_context_for_expression (xp, arg, ea.cmdidx);
        break;
    case CMD_unlet :
        while ((xp->xp_pattern = vim_strchr (arg, ' ')) != NULL)
            arg = xp->xp_pattern + 1;
        xp->xp_context = EXPAND_USER_VARS;
        xp->xp_pattern = arg;
        break;
    case CMD_function :
    case CMD_delfunction :
        xp->xp_context = EXPAND_USER_FUNC;
        xp->xp_pattern = arg;
        break;
    case CMD_echohl :
        set_context_in_echohl_cmd (xp, arg);
        break;
    case CMD_highlight :
        set_context_in_highlight_cmd (xp, arg);
        break;
    case CMD_sign :
        set_context_in_sign_cmd (xp, arg);
        break;
    case CMD_bdelete :
    case CMD_bwipeout :
    case CMD_bunload :
        while ((xp->xp_pattern = vim_strchr (arg, ' ')) != NULL)
            arg = xp->xp_pattern + 1;
    case CMD_buffer :
    case CMD_sbuffer :
    case CMD_checktime :
        xp->xp_context = EXPAND_BUFFERS;
        xp->xp_pattern = arg;
        break;
    case CMD_USER :
    case CMD_USER_BUF :
        if (compl != EXPAND_NOTHING) {
            if (!(ea.argt & XFILE)) {
                if (compl == EXPAND_MENUS)
                    return set_context_in_menu_cmd (xp, cmd, arg, forceit);
                if (compl == EXPAND_COMMANDS)
                    return arg;
                if (compl == EXPAND_MAPPINGS)
                    return set_context_in_map_cmd (xp, (char_u *) "map", arg, forceit, FALSE, FALSE, CMD_map);
                p = arg;
                while (*p) {
                    if (*p == ' ')
                        arg = p + 1;
                    else if (*p == '\\' && *(p + 1) != NUL)
                        ++p;
                    MB_PTR_ADV (p);
                }
                xp->xp_pattern = arg;
            }
            xp->xp_context = compl;
        }
        break;
    case CMD_map :
    case CMD_noremap :
    case CMD_nmap :
    case CMD_nnoremap :
    case CMD_vmap :
    case CMD_vnoremap :
    case CMD_omap :
    case CMD_onoremap :
    case CMD_imap :
    case CMD_inoremap :
    case CMD_cmap :
    case CMD_cnoremap :
    case CMD_lmap :
    case CMD_lnoremap :
    case CMD_smap :
    case CMD_snoremap :
    case CMD_tmap :
    case CMD_tnoremap :
    case CMD_xmap :
    case CMD_xnoremap :
        return set_context_in_map_cmd (xp, cmd, arg, forceit, FALSE, FALSE, ea.cmdidx);
    case CMD_unmap :
    case CMD_nunmap :
    case CMD_vunmap :
    case CMD_ounmap :
    case CMD_iunmap :
    case CMD_cunmap :
    case CMD_lunmap :
    case CMD_sunmap :
    case CMD_tunmap :
    case CMD_xunmap :
        return set_context_in_map_cmd (xp, cmd, arg, forceit, FALSE, TRUE, ea.cmdidx);
    case CMD_mapclear :
    case CMD_nmapclear :
    case CMD_vmapclear :
    case CMD_omapclear :
    case CMD_imapclear :
    case CMD_cmapclear :
    case CMD_lmapclear :
    case CMD_smapclear :
    case CMD_tmapclear :
    case CMD_xmapclear :
        xp->xp_context = EXPAND_MAPCLEAR;
        xp->xp_pattern = arg;
        break;
    case CMD_abbreviate :
    case CMD_noreabbrev :
    case CMD_cabbrev :
    case CMD_cnoreabbrev :
    case CMD_iabbrev :
    case CMD_inoreabbrev :
        return set_context_in_map_cmd (xp, cmd, arg, forceit, TRUE, FALSE, ea.cmdidx);
    case CMD_unabbreviate :
    case CMD_cunabbrev :
    case CMD_iunabbrev :
        return set_context_in_map_cmd (xp, cmd, arg, forceit, TRUE, TRUE, ea.cmdidx);
    case CMD_menu :
    case CMD_noremenu :
    case CMD_unmenu :
    case CMD_amenu :
    case CMD_anoremenu :
    case CMD_aunmenu :
    case CMD_nmenu :
    case CMD_nnoremenu :
    case CMD_nunmenu :
    case CMD_vmenu :
    case CMD_vnoremenu :
    case CMD_vunmenu :
    case CMD_omenu :
    case CMD_onoremenu :
    case CMD_ounmenu :
    case CMD_imenu :
    case CMD_inoremenu :
    case CMD_iunmenu :
    case CMD_cmenu :
    case CMD_cnoremenu :
    case CMD_cunmenu :
    case CMD_tmenu :
    case CMD_tunmenu :
    case CMD_popup :
    case CMD_tearoff :
    case CMD_emenu :
    case CMD_macmenu :
        return set_context_in_menu_cmd (xp, cmd, arg, forceit);
    case CMD_colorscheme :
        xp->xp_context = EXPAND_COLORS;
        xp->xp_pattern = arg;
        break;
    case CMD_compiler :
        xp->xp_context = EXPAND_COMPILER;
        xp->xp_pattern = arg;
        break;
    case CMD_ownsyntax :
        xp->xp_context = EXPAND_OWNSYNTAX;
        xp->xp_pattern = arg;
        break;
    case CMD_setfiletype :
        xp->xp_context = EXPAND_FILETYPE;
        xp->xp_pattern = arg;
        break;
    case CMD_packadd :
        xp->xp_context = EXPAND_PACKADD;
        xp->xp_pattern = arg;
        break;
    case CMD_profile :
        set_context_in_profile_cmd (xp, arg);
        break;
    case CMD_behave :
        xp->xp_context = EXPAND_BEHAVE;
        xp->xp_pattern = arg;
        break;
    case CMD_messages :
        xp->xp_context = EXPAND_MESSAGES;
        xp->xp_pattern = arg;
        break;
    case CMD_syntime :
        xp->xp_context = EXPAND_SYNTIME;
        xp->xp_pattern = arg;
        break;
    case CMD_macaction :
        xp->xp_context = EXPAND_MACACTION;
        xp->xp_pattern = arg;
        break;
    default :
        break;
    }
    return NULL;
}

char_u *skip_range (char_u *cmd, int *ctx) {
    unsigned  delim;
    while (vim_strchr ((char_u *) " \t0123456789.$%'/?-+,;\\", *cmd) != NULL) {
        if (*cmd == '\\') {
            if (cmd[1] == '?' || cmd[1] == '/' || cmd[1] == '&')
                ++cmd;
            else
                break;
        }
        else if (*cmd == '\'') {
            if (*++cmd == NUL && ctx != NULL)
                *ctx = EXPAND_NOTHING;
        }
        else if (*cmd == '/' || *cmd == '?') {
            delim = *cmd++;
            while (*cmd != NUL && *cmd != delim)
                if (*cmd++ == '\\' && *cmd != NUL)
                    ++cmd;
            if (*cmd == NUL && ctx != NULL)
                *ctx = EXPAND_NOTHING;
        }
        if (*cmd != NUL)
            ++cmd;
    }
    while (*cmd == ':')
        cmd = skipwhite (cmd +1);
    return cmd;
}

static char_u *find_ucmd (exarg_T *eap, char_u *p, int *full, expand_T *xp, int *compl) {
    int len = (int) (p - eap->cmd);
    int j, k, matchlen = 0;
    ucmd_T *uc;
    int found = FALSE;
    int possible = FALSE;
    char_u *cp, *np;
    garray_T *gap;
    int amb_local = FALSE;
    gap = &curbuf->b_ucmds;
    for (;;) {
        for (j = 0; j < gap->ga_len; ++j) {
            uc = USER_CMD_GA (gap, j);
            cp = eap->cmd;
            np = uc->uc_name;
            k = 0;
            while (k < len && *np != NUL && *cp++ == *np++)
                k++;
            if (k == len || (*np == NUL && vim_isdigit (eap->cmd[k]))) {
                if (k == len && found && *np != NUL) {
                    if (gap == &ucmds)
                        return NULL;
                    amb_local = TRUE;
                }
                if (!found || (k == len && *np == NUL)) {
                    if (k == len)
                        found = TRUE;
                    else
                        possible = TRUE;
                    if (gap == &ucmds)
                        eap->cmdidx = CMD_USER;
                    else
                        eap->cmdidx = CMD_USER_BUF;
                    eap->argt = (long ) uc->uc_argt;
                    eap->useridx = j;
                    eap->addr_type = uc->uc_addr_type;
                    if (compl != NULL)
                        *compl = uc->uc_compl;
                    if (xp != NULL) {
                        xp->xp_arg = uc->uc_compl_arg;
                        xp->xp_scriptID = uc->uc_scriptID;
                    }
                    matchlen = k;
                    if (k == len && *np == NUL) {
                        if (full != NULL)
                            *full = TRUE;
                        amb_local = FALSE;
                        break;
                    }
                }
            }
        }
        if (j < gap->ga_len || gap == &ucmds)
            break;
        gap = &ucmds;
    }
    if (amb_local) {
        if (xp != NULL)
            xp->xp_context = EXPAND_UNSUCCESSFUL;
        return NULL;
    }
    if (found || possible)
        return p + (matchlen - len);
    return p;
}

static char_u *skip_cmd_arg (char_u *p, int rembs) {
    while (*p && !vim_isspace (*p)) {
        if (*p == '\\' && p[1] != NUL) {
            if (rembs)
                STRMOVE (p, p +1);
            else
                ++p;
        }
        MB_PTR_ADV (p);
    }
    return p;
}

char_u *find_nextcmd (char_u *p) {
    while (*p != '|' && *p != '\n') {
        if (*p == NUL)
            return NULL;
        ++p;
    }
    return (p + 1);
}

char_u *eval_vars (char_u *src, char_u *srcstart, int *usedlen, linenr_T *lnump, char_u **errormsg, int *escaped) {
    int i;
    char_u *s;
    char_u *result;
    char_u *resultbuf = NULL;
    int resultlen;
    buf_T *buf;
    int valid = VALID_HEAD + VALID_PATH;
    int spec_idx;
    int skip_mod = FALSE;
    char_u strbuf [30];
    *errormsg = NULL;
    if (escaped != NULL)
        *escaped = FALSE;
    spec_idx = find_cmdline_var (src, usedlen);
    if (spec_idx < 0) {
        *usedlen = 1;
        return NULL;
    }
    if (src > srcstart && src[-1] == '\\') {
        *usedlen = 0;
        STRMOVE (src - 1, src);
        return NULL;
    }
    if (spec_idx == SPEC_CWORD || spec_idx == SPEC_CCWORD || spec_idx == SPEC_CEXPR) {
        resultlen = find_ident_under_cursor (&result, spec_idx == SPEC_CWORD ? (FIND_IDENT | FIND_STRING) : spec_idx == SPEC_CEXPR ? (FIND_IDENT | FIND_STRING | FIND_EVAL) : FIND_STRING);
        if (resultlen == 0) {
            *errormsg = (char_u *) "";
            return NULL;
        }
    }
    else {
        switch (spec_idx) {
        case SPEC_PERC :
            if (curbuf->b_fname == NULL) {
                result = (char_u *) "";
                valid = 0;
            }
            else
                result = curbuf->b_fname;
            break;
        case SPEC_HASH :
            if (src[1] == '#') {
                result = arg_all ();
                resultbuf = result;
                *usedlen = 2;
                if (escaped != NULL)
                    *escaped = TRUE;
                skip_mod = TRUE;
                break;
            }
            s = src + 1;
            if (*s == '<')
                ++s;
            i = (int) getdigits (&s);
            if (s == src + 2 && src[1] == '-')
                s--;
            *usedlen = (int) (s - src);
            if (src[1] == '<' && i != 0) {
                if (*usedlen < 2) {
                    *usedlen = 1;
                    return NULL;
                }
                result = list_find_str (get_vim_var_list (VV_OLDFILES), (long ) i);
                if (result == NULL) {
                    *errormsg = (char_u *) "";
                    return NULL;
                }
            }
            else {
                if (i == 0 && src[1] == '<' && *usedlen > 1)
                    *usedlen = 1;
                buf = buflist_findnr (i);
                if (buf == NULL) {
                    *errormsg = (char_u *) _ ("E194: No alternate file name to substitute for '#'");
                    return NULL;
                }
                if (lnump != NULL)
                    *lnump = ECMD_LAST;
                if (buf->b_fname == NULL) {
                    result = (char_u *) "";
                    valid = 0;
                }
                else
                    result = buf->b_fname;
            }
            break;
        case SPEC_CFILE :
            result = file_name_at_cursor (FNAME_MESS | FNAME_HYP, 1L, NULL);
            if (result == NULL) {
                *errormsg = (char_u *) "";
                return NULL;
            }
            resultbuf = result;
            break;
        case SPEC_AFILE :
            result = autocmd_fname;
            if (result != NULL && !autocmd_fname_full) {
                autocmd_fname_full = TRUE;
                result = FullName_save (autocmd_fname, FALSE);
                vim_free (autocmd_fname);
                autocmd_fname = result;
            }
            if (result == NULL) {
                *errormsg = (char_u *) _ ("E495: no autocommand file name to substitute for \"<afile>\"");
                return NULL;
            }
            result = shorten_fname1 (result);
            break;
        case SPEC_ABUF :
            if (autocmd_bufnr <= 0) {
                *errormsg = (char_u *) _ ("E496: no autocommand buffer number to substitute for \"<abuf>\"");
                return NULL;
            }
            sprintf ((char *) strbuf, "%d", autocmd_bufnr);
            result = strbuf;
            break;
        case SPEC_AMATCH :
            result = autocmd_match;
            if (result == NULL) {
                *errormsg = (char_u *) _ ("E497: no autocommand match name to substitute for \"<amatch>\"");
                return NULL;
            }
            break;
        case SPEC_SFILE :
            result = sourcing_name;
            if (result == NULL) {
                *errormsg = (char_u *) _ ("E498: no :source file name to substitute for \"<sfile>\"");
                return NULL;
            }
            break;
        case SPEC_SLNUM :
            if (sourcing_name == NULL || sourcing_lnum == 0) {
                *errormsg = (char_u *) _ ("E842: no line number to use for \"<slnum>\"");
                return NULL;
            }
            sprintf ((char *) strbuf, "%ld", (long) sourcing_lnum);
            result = strbuf;
            break;
        case SPEC_CLIENT :
            sprintf ((char *) strbuf, PRINTF_HEX_LONG_U, (long_u) clientWindow);
            result = strbuf;
            break;
        default :
            result = (char_u *) "";
            break;
        }
        resultlen = (int) STRLEN (result);
        if (src[*usedlen] == '<') {
            ++*usedlen;
            if ((s = vim_strrchr (result, '.')) != NULL && s >= gettail (result))
                resultlen = (int) (s - result);
        }
        else if (!skip_mod) {
            valid |= modify_fname (src, usedlen, &result, &resultbuf, &resultlen);
            if (result == NULL) {
                *errormsg = (char_u *) "";
                return NULL;
            }
        }
    }
    if (resultlen == 0 || valid != VALID_HEAD + VALID_PATH) {
        if (valid != VALID_HEAD + VALID_PATH)
            *errormsg = (char_u *) _ ("E499: Empty file name for '%' or '#', only works with \":p:h\"");
        else
            *errormsg = (char_u *) _ ("E500: Evaluates to an empty string");
        result = NULL;
    }
    else
        result = vim_strnsave (result, resultlen);
    vim_free (resultbuf);
    return result;
}

int find_cmdline_var (char_u *src, int *usedlen) {
    int len;
    int i;
    static char * (spec_str []) = {"%", 
        #define SPEC_PERC   0
        "#", 
        #define SPEC_HASH   (SPEC_PERC + 1)
        "<cword>", 
        #define SPEC_CWORD  (SPEC_HASH + 1)
        "<cWORD>", 
        #define SPEC_CCWORD (SPEC_CWORD + 1)
        "<cexpr>", 
        #define SPEC_CEXPR  (SPEC_CCWORD + 1)
        "<cfile>", 
        #define SPEC_CFILE  (SPEC_CEXPR + 1)
        "<sfile>", 
        #define SPEC_SFILE  (SPEC_CFILE + 1)
        "<slnum>", 
        #define SPEC_SLNUM  (SPEC_SFILE + 1)
        "<afile>", 
        # define SPEC_AFILE (SPEC_SLNUM + 1)
        "<abuf>", 
        # define SPEC_ABUF  (SPEC_AFILE + 1)
        "<amatch>", 
        # define SPEC_AMATCH (SPEC_ABUF + 1)
        "<client>" 
        #  define SPEC_CLIENT (SPEC_AMATCH + 1)

    };
    for (i = 0; i < (int) (sizeof (spec_str) / sizeof (char *)); ++i) {
        len = (int) STRLEN (spec_str[i]);
        if (STRNCMP (src, spec_str[i], len) == 0) {
            *usedlen = len;
            return i;
        }
    }
    return -1;
}

static char_u *arg_all (void) {
    int len;
    int idx;
    char_u *retval = NULL;
    char_u *p;
    for (;;) {
        len = 0;
        for (idx = 0; idx < ARGCOUNT; ++idx) {
            p = alist_name (&ARGLIST[idx]);
            if (p != NULL) {
                if (len > 0) {
                    if (retval != NULL)
                        retval[len] = ' ';
                    ++len;
                }
                for (; *p != NUL; ++p) {
                    if (*p == ' ' || *p == '\\') {
                        if (retval != NULL)
                            retval[len] = '\\';
                        ++len;
                    }
                    if (retval != NULL)
                        retval[len] = *p;
                    ++len;
                }
            }
        }
        if (retval != NULL) {
            retval[len] = NUL;
            break;
        }
        retval = alloc ((unsigned ) len + 1);
        if (retval == NULL)
            break;
    }
    return retval;
}

char_u *get_command_name (expand_T *xp, int idx) {
    if (idx >= (int) CMD_SIZE)
        return get_user_command_name (idx);
    return cmdnames[idx].cmd_name;
}

static char_u *get_user_command_name (int idx) {
    return get_user_commands (NULL, idx -(int)CMD_SIZE);
}

char_u *get_user_commands (expand_T *xp, int idx) {
    if (idx < curbuf->b_ucmds.ga_len)
        return USER_CMD_GA (&curbuf->b_ucmds, idx)->uc_name;
    idx -= curbuf->b_ucmds.ga_len;
    if (idx < ucmds.ga_len)
        return USER_CMD (idx)->uc_name;
    return NULL;
}

char_u *get_behave_arg (expand_T *xp, int idx) {
    if (idx == 0)
        return (char_u *) "mswin";
    if (idx == 1)
        return (char_u *) "xterm";
    return NULL;
}

char_u *get_user_cmd_flags (expand_T *xp, int idx) {
    static char *user_cmd_flags [] = {"addr", "bang", "bar", "buffer", "complete", "count", "nargs", "range", "register"};
    if (idx >= (int) (sizeof (user_cmd_flags) / sizeof (user_cmd_flags[0])))
        return NULL;
    return (char_u *) user_cmd_flags[idx];
}

char_u *get_user_cmd_nargs (expand_T *xp, int idx) {
    static char *user_cmd_nargs [] = {"0", "1", "*", "?", "+"};
    if (idx >= (int) (sizeof (user_cmd_nargs) / sizeof (user_cmd_nargs[0])))
        return NULL;
    return (char_u *) user_cmd_nargs[idx];
}

char_u *get_user_cmd_complete (expand_T *xp, int idx) {
    return (char_u *) command_complete[idx].name;
}

