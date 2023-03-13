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
struct mf_hashtab_S {
    long_u mht_mask;
    long_u mht_count;
    mf_hashitem_T **mht_buckets;
    mf_hashitem_T *mht_small_buckets [MHT_INIT_SIZE];
    char mht_fixed;
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
struct regengine {
    regprog_T * (*regcomp) (char_u *, int);
    void (*regfree) (regprog_T *);
    int (*regexec_nl) (regmatch_T *, char_u *, colnr_T, int);
    long  (*regexec_multi) (regmmatch_T *, win_T *, buf_T *, linenr_T, colnr_T, proftime_T *, int *);
    char_u *expr;
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
struct ml_chunksize {
    int mlcs_numlines;
    long  mlcs_totalsize;
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
struct u_entry {
    u_entry_T *ue_next;
    linenr_T ue_top;
    linenr_T ue_bot;
    linenr_T ue_lcount;
    char_u **ue_array;
    long  ue_size;
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
struct mf_hashitem_S {
    mf_hashitem_T *mhi_next;
    mf_hashitem_T *mhi_prev;
    blocknr_T mhi_key;
};
struct cleanup_stuff {
    int pending;
    except_T *exception;
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
struct_bf_test_data bf_test_data [] = {{"password", "salt", "plaintxt", "\xad\x3d\xfa\x7f\xe8\xea\x40\xf6", "\x72\x50\x3b\x38\x10\x60\x22\xa7", 0x56701b5du},};
UINT32_T pax_init [18] = {0x243f6a88u, 0x85a308d3u, 0x13198a2eu, 0x03707344u, 0xa4093822u, 0x299f31d0u, 0x082efa98u, 0xec4e6c89u, 0x452821e6u, 0x38d01377u, 0xbe5466cfu, 0x34e90c6cu, 0xc0ac29b7u, 0xc97c50ddu, 0x3f84d5b5u, 0xb5470917u, 0x9216d5d9u, 0x8979fb1bu};
UINT32_T sbx_init [4] [256] = {{0xd1310ba6u, 0x98dfb5acu, 0x2ffd72dbu, 0xd01adfb7u, 0xb8e1afedu, 0x6a267e96u, 0xba7c9045u, 0xf12c7f99u, 0x24a19947u, 0xb3916cf7u, 0x0801f2e2u, 0x858efc16u, 0x636920d8u, 0x71574e69u, 0xa458fea3u, 0xf4933d7eu, 0x0d95748fu, 0x728eb658u, 0x718bcd58u, 0x82154aeeu, 0x7b54a41du, 0xc25a59b5u, 0x9c30d539u, 0x2af26013u, 0xc5d1b023u, 0x286085f0u, 0xca417918u, 0xb8db38efu, 0x8e79dcb0u, 0x603a180eu, 0x6c9e0e8bu, 0xb01e8a3eu, 0xd71577c1u, 0xbd314b27u, 0x78af2fdau, 0x55605c60u, 0xe65525f3u, 0xaa55ab94u, 0x57489862u, 0x63e81440u, 0x55ca396au, 0x2aab10b6u, 0xb4cc5c34u, 0x1141e8ceu, 0xa15486afu, 0x7c72e993u, 0xb3ee1411u, 0x636fbc2au, 0x2ba9c55du, 0x741831f6u, 0xce5c3e16u, 0x9b87931eu, 0xafd6ba33u, 0x6c24cf5cu, 0x7a325381u, 0x28958677u, 0x3b8f4898u, 0x6b4bb9afu, 0xc4bfe81bu, 0x66282193u, 0x61d809ccu, 0xfb21a991u, 0x487cac60u, 0x5dec8032u, 0xef845d5du, 0xe98575b1u, 0xdc262302u, 0xeb651b88u, 0x23893e81u, 0xd396acc5u, 0x0f6d6ff3u, 0x83f44239u, 0x2e0b4482u, 0xa4842004u, 0x69c8f04au, 0x9e1f9b5eu, 0x21c66842u, 0xf6e96c9au, 0x670c9c61u, 0xabd388f0u, 0x6a51a0d2u, 0xd8542f68u, 0x960fa728u, 0xab5133a3u, 0x6eef0b6cu, 0x137a3be4u, 0xba3bf050u, 0x7efb2a98u, 0xa1f1651du, 0x39af0176u, 0x66ca593eu, 0x82430e88u, 0x8cee8619u, 0x456f9fb4u, 0x7d84a5c3u, 0x3b8b5ebeu, 0xe06f75d8u, 0x85c12073u, 0x401a449fu, 0x56c16aa6u, 0x4ed3aa62u, 0x363f7706u, 0x1bfedf72u, 0x429b023du, 0x37d0d724u, 0xd00a1248u, 0xdb0fead3u, 0x49f1c09bu, 0x075372c9u, 0x80991b7bu, 0x25d479d8u, 0xf6e8def7u, 0xe3fe501au, 0xb6794c3bu, 0x976ce0bdu, 0x04c006bau, 0xc1a94fb6u, 0x409f60c4u, 0x5e5c9ec2u, 0x196a2463u, 0x68fb6fafu, 0x3e6c53b5u, 0x1339b2ebu, 0x3b52ec6fu, 0x6dfc511fu, 0x9b30952cu, 0xcc814544u, 0xaf5ebd09u, 0xbee3d004u, 0xde334afdu, 0x660f2807u, 0x192e4bb3u, 0xc0cba857u, 0x45c8740fu, 0xd20b5f39u, 0xb9d3fbdbu, 0x5579c0bdu, 0x1a60320au, 0xd6a100c6u, 0x402c7279u, 0x679f25feu, 0xfb1fa3ccu, 0x8ea5e9f8u, 0xdb3222f8u, 0x3c7516dfu, 0xfd616b15u, 0x2f501ec8u, 0xad0552abu, 0x323db5fau, 0xfd238760u, 0x53317b48u, 0x3e00df82u, 0x9e5c57bbu, 0xca6f8ca0u, 0x1a87562eu, 0xdf1769dbu, 0xd542a8f6u, 0x287effc3u, 0xac6732c6u, 0x8c4f5573u, 0x695b27b0u, 0xbbca58c8u, 0xe1ffa35du, 0xb8f011a0u, 0x10fa3d98u, 0xfd2183b8u, 0x4afcb56cu, 0x2dd1d35bu, 0x9a53e479u, 0xb6f84565u, 0xd28e49bcu, 0x4bfb9790u, 0xe1ddf2dau, 0xa4cb7e33u, 0x62fb1341u, 0xcee4c6e8u, 0xef20cadau, 0x36774c01u, 0xd07e9efeu, 0x2bf11fb4u, 0x95dbda4du, 0xae909198u, 0xeaad8e71u, 0x6b93d5a0u, 0xd08ed1d0u, 0xafc725e0u, 0x8e3c5b2fu, 0x8e7594b7u, 0x8ff6e2fbu, 0xf2122b64u, 0x8888b812u, 0x900df01cu, 0x4fad5ea0u, 0x688fc31cu, 0xd1cff191u, 0xb3a8c1adu, 0x2f2f2218u, 0xbe0e1777u, 0xea752dfeu, 0x8b021fa1u, 0xe5a0cc0fu, 0xb56f74e8u, 0x18acf3d6u, 0xce89e299u, 0xb4a84fe0u, 0xfd13e0b7u, 0x7cc43b81u, 0xd2ada8d9u, 0x165fa266u, 0x80957705u, 0x93cc7314u, 0x211a1477u, 0xe6ad2065u, 0x77b5fa86u, 0xc75442f5u, 0xfb9d35cfu, 0xebcdaf0cu, 0x7b3e89a0u, 0xd6411bd3u, 0xae1e7e49u, 0x00250e2du, 0x2071b35eu, 0x226800bbu, 0x57b8e0afu, 0x2464369bu, 0xf009b91eu, 0x5563911du, 0x59dfa6aau, 0x78c14389u, 0xd95a537fu, 0x207d5ba2u, 0x02e5b9c5u, 0x83260376u, 0x6295cfa9u, 0x11c81968u, 0x4e734a41u, 0xb3472dcau, 0x7b14a94au, 0x1b510052u, 0x9a532915u, 0xd60f573fu, 0xbc9bc6e4u, 0x2b60a476u, 0x81e67400u, 0x08ba6fb5u, 0x571be91fu, 0xf296ec6bu, 0x2a0dd915u, 0xb6636521u, 0xe7b9f9b6u, 0xff34052eu, 0xc5855664u, 0x53b02d5du, 0xa99f8fa1u, 0x08ba4799u, 0x6e85076au}, {0x4b7a70e9u, 0xb5b32944u, 0xdb75092eu, 0xc4192623u, 0xad6ea6b0u, 0x49a7df7du, 0x9cee60b8u, 0x8fedb266u, 0xecaa8c71u, 0x699a17ffu, 0x5664526cu, 0xc2b19ee1u, 0x193602a5u, 0x75094c29u, 0xa0591340u, 0xe4183a3eu, 0x3f54989au, 0x5b429d65u, 0x6b8fe4d6u, 0x99f73fd6u, 0xa1d29c07u, 0xefe830f5u, 0x4d2d38e6u, 0xf0255dc1u, 0x4cdd2086u, 0x8470eb26u, 0x6382e9c6u, 0x021ecc5eu, 0x09686b3fu, 0x3ebaefc9u, 0x3c971814u, 0x6b6a70a1u, 0x687f3584u, 0x52a0e286u, 0xb79c5305u, 0xaa500737u, 0x3e07841cu, 0x7fdeae5cu, 0x8e7d44ecu, 0x5716f2b8u, 0xb03ada37u, 0xf0500c0du, 0xf01c1f04u, 0x0200b3ffu, 0xae0cf51au, 0x3cb574b2u, 0x25837a58u, 0xdc0921bdu, 0xd19113f9u, 0x7ca92ff6u, 0x94324773u, 0x22f54701u, 0x3ae5e581u, 0x37c2dadcu, 0xc8b57634u, 0x9af3dda7u,
  0xa9446146u, 0x0fd0030eu, 0xecc8c73eu, 0xa4751e41u, 0xe238cd99u, 0x3bea0e2fu, 0x3280bba1u, 0x183eb331u, 0x4e548b38u, 0x4f6db908u, 0x6f420d03u, 0xf60a04bfu, 0x2cb81290u, 0x24977c79u, 0x5679b072u, 0xbcaf89afu, 0xde9a771fu, 0xd9930810u, 0xb38bae12u, 0xdccf3f2eu, 0x5512721fu, 0x2e6b7124u, 0x501adde6u, 0x9f84cd87u, 0x7a584718u, 0x7408da17u, 0xbc9f9abcu, 0xe94b7d8cu, 0xec7aec3au, 0xdb851dfau, 0x63094366u, 0xc464c3d2u, 0xef1c1847u, 0x3215d908u, 0xdd433b37u, 0x24c2ba16u, 0x12a14d43u, 0x2a65c451u, 0x50940002u, 0x133ae4ddu, 0x71dff89eu, 0x10314e55u, 0x81ac77d6u, 0x5f11199bu, 0x043556f1u, 0xd7a3c76bu, 0x3c11183bu, 0x5924a509u, 0xf28fe6edu, 0x97f1fbfau, 0x9ebabf2cu, 0x1e153c6eu, 0x86e34570u, 0xeae96fb1u, 0x860e5e0au, 0x5a3e2ab3u, 0x771fe71cu, 0x4e3d06fau, 0x2965dcb9u, 0x99e71d0fu, 0x803e89d6u, 0x5266c825u, 0x2e4cc978u, 0x9c10b36au, 0xc6150ebau, 0x94e2ea78u, 0xa5fc3c53u, 0x1e0a2df4u, 0xf2f74ea7u, 0x361d2b3du, 0x1939260fu, 0x19c27960u, 0x5223a708u, 0xf71312b6u, 0xebadfe6eu, 0xeac31f66u, 0xe3bc4595u, 0xa67bc883u, 0xb17f37d1u, 0x018cff28u, 0xc332ddefu, 0xbe6c5aa5u, 0x65582185u, 0x68ab9802u, 0xeecea50fu, 0xdb2f953bu, 0x2aef7dadu, 0x5b6e2f84u, 0x1521b628u, 0x29076170u, 0xecdd4775u, 0x619f1510u, 0x13cca830u, 0xeb61bd96u, 0x0334fe1eu, 0xaa0363cfu, 0xb5735c90u, 0x4c70a239u, 0xd59e9e0bu, 0xcbaade14u, 0xeecc86bcu, 0x60622ca7u, 0x9cab5cabu, 0xb2f3846eu, 0x648b1eafu, 0x19bdf0cau, 0xa02369b9u, 0x655abb50u, 0x40685a32u, 0x3c2ab4b3u, 0x319ee9d5u, 0xc021b8f7u, 0x9b540b19u, 0x875fa099u, 0x95f7997eu, 0x623d7da8u, 0xf837889au, 0x97e32d77u, 0x11ed935fu, 0x16681281u, 0x0e358829u, 0xc7e61fd6u, 0x96dedfa1u, 0x7858ba99u, 0x57f584a5u, 0x1b227263u, 0x9b83c3ffu, 0x1ac24696u, 0xcdb30aebu, 0x532e3054u, 0x8fd948e4u, 0x6dbc3128u, 0x58ebf2efu, 0x34c6ffeau, 0xfe28ed61u, 0xee7c3c73u, 0x5d4a14d9u, 0xe864b7e3u, 0x42105d14u, 0x203e13e0u, 0x45eee2b6u, 0xa3aaabeau, 0xdb6c4f15u, 0xfacb4fd0u, 0xc742f442u, 0xef6abbb5u, 0x654f3b1du, 0x41cd2105u, 0xd81e799eu, 0x86854dc7u, 0xe44b476au, 0x3d816250u, 0xcf62a1f2u, 0x5b8d2646u, 0xfc8883a0u, 0xc1c7b6a3u, 0x7f1524c3u, 0x69cb7492u, 0x47848a0bu, 0x5692b285u, 0x095bbf00u, 0xad19489du, 0x1462b174u, 0x23820e00u, 0x58428d2au, 0x0c55f5eau, 0x1dadf43eu, 0x233f7061u, 0x3372f092u, 0x8d937e41u, 0xd65fecf1u, 0x6c223bdbu, 0x7cde3759u, 0xcbee7460u, 0x4085f2a7u, 0xce77326eu, 0xa6078084u, 0x19f8509eu, 0xe8efd855u, 0x61d99735u, 0xa969a7aau, 0xc50c06c2u, 0x5a04abfcu, 0x800bcadcu, 0x9e447a2eu, 0xc3453484u, 0xfdd56705u, 0x0e1e9ec9u, 0xdb73dbd3u, 0x105588cdu, 0x675fda79u, 0xe3674340u, 0xc5c43465u, 0x713e38d8u, 0x3d28f89eu, 0xf16dff20u, 0x153e21e7u, 0x8fb03d4au, 0xe6e39f2bu, 0xdb83adf7u}, {0xe93d5a68u, 0x948140f7u, 0xf64c261cu, 0x94692934u, 0x411520f7u, 0x7602d4f7u, 0xbcf46b2eu, 0xd4a20068u, 0xd4082471u, 0x3320f46au, 0x43b7d4b7u, 0x500061afu, 0x1e39f62eu, 0x97244546u, 0x14214f74u, 0xbf8b8840u, 0x4d95fc1du, 0x96b591afu, 0x70f4ddd3u, 0x66a02f45u, 0xbfbc09ecu, 0x03bd9785u, 0x7fac6dd0u, 0x31cb8504u, 0x96eb27b3u, 0x55fd3941u, 0xda2547e6u, 0xabca0a9au, 0x28507825u, 0x530429f4u, 0x0a2c86dau, 0xe9b66dfbu, 0x68dc1462u, 0xd7486900u, 0x680ec0a4u, 0x27a18deeu, 0x4f3ffea2u, 0xe887ad8cu, 0xb58ce006u, 0x7af4d6b6u, 0xaace1e7cu, 0xd3375fecu, 0xce78a399u, 0x406b2a42u, 0x20fe9e35u, 0xd9f385b9u, 0xee39d7abu, 0x3b124e8bu, 0x1dc9faf7u, 0x4b6d1856u, 0x26a36631u, 0xeae397b2u, 0x3a6efa74u, 0xdd5b4332u, 0x6841e7f7u, 0xca7820fbu, 0xfb0af54eu, 0xd8feb397u, 0x454056acu, 0xba489527u, 0x55533a3au, 0x20838d87u, 0xfe6ba9b7u, 0xd096954bu, 0x55a867bcu, 0xa1159a58u, 0xcca92963u, 0x99e1db33u, 0xa62a4a56u, 0x3f3125f9u, 0x5ef47e1cu, 0x9029317cu, 0xfdf8e802u, 0x04272f70u, 0x80bb155cu, 0x05282ce3u, 0x95c11548u, 0xe4c66d22u, 0x48c1133fu, 0xc70f86dcu, 0x07f9c9eeu, 0x41041f0fu, 0x404779a4u, 0x5d886e17u, 0x325f51ebu, 0xd59bc0d1u, 0xf2bcc18fu, 0x41113564u, 0x257b7834u, 0x602a9c60u, 0xdff8e8a3u, 0x1f636c1bu, 0x0e12b4c2u, 0x02e1329eu, 0xaf664fd1u, 0xcad18115u, 0x6b2395e0u, 0x333e92e1u, 0x3b240b62u, 0xeebeb922u, 0x85b2a20eu, 0xe6ba0d99u, 0xde720c8cu, 0x2da2f728u, 0xd0127845u, 0x95b794fdu, 0x647d0862u, 0xe7ccf5f0u, 0x5449a36fu, 0x877d48fau, 0xc39dfd27u, 0xf33e8d1eu, 0x0a476341u, 0x992eff74u,
  0x3a6f6eabu, 0xf4f8fd37u, 0xa812dc60u, 0xa1ebddf8u, 0x991be14cu, 0xdb6e6b0du, 0xc67b5510u, 0x6d672c37u, 0x2765d43bu, 0xdcd0e804u, 0xf1290dc7u, 0xcc00ffa3u, 0xb5390f92u, 0x690fed0bu, 0x667b9ffbu, 0xcedb7d9cu, 0xa091cf0bu, 0xd9155ea3u, 0xbb132f88u, 0x515bad24u, 0x7b9479bfu, 0x763bd6ebu, 0x37392eb3u, 0xcc115979u, 0x8026e297u, 0xf42e312du, 0x6842ada7u, 0xc66a2b3bu, 0x12754cccu, 0x782ef11cu, 0x6a124237u, 0xb79251e7u, 0x06a1bbe6u, 0x4bfb6350u, 0x1a6b1018u, 0x11caedfau, 0x3d25bdd8u, 0xe2e1c3c9u, 0x44421659u, 0x0a121386u, 0xd90cec6eu, 0xd5abea2au, 0x64af674eu, 0xda86a85fu, 0xbebfe988u, 0x64e4c3feu, 0x9dbc8057u, 0xf0f7c086u, 0x60787bf8u, 0x6003604du, 0xd1fd8346u, 0xf6381fb0u, 0x7745ae04u, 0xd736fcccu, 0x83426b33u, 0xf01eab71u, 0xb0804187u, 0x3c005e5fu, 0x77a057beu, 0xbde8ae24u, 0x55464299u, 0xbf582e61u, 0x4e58f48fu, 0xf2ddfda2u, 0xf474ef38u, 0x8789bdc2u, 0x5366f9c3u, 0xc8b38e74u, 0xb475f255u, 0x46fcd9b9u, 0x7aeb2661u, 0x8b1ddf84u, 0x846a0e79u, 0x915f95e2u, 0x466e598eu, 0x20b45770u, 0x8cd55591u, 0xc902de4cu, 0xb90bace1u, 0xbb8205d0u, 0x11a86248u, 0x7574a99eu, 0xb77f19b6u, 0xe0a9dc09u, 0x662d09a1u, 0xc4324633u, 0xe85a1f02u, 0x09f0be8cu, 0x4a99a025u, 0x1d6efe10u, 0x1ab93d1du, 0x0ba5a4dfu, 0xa186f20fu, 0x2868f169u, 0xdcb7da83u, 0x573906feu, 0xa1e2ce9bu, 0x4fcd7f52u, 0x50115e01u, 0xa70683fau, 0xa002b5c4u, 0x0de6d027u, 0x9af88c27u, 0x773f8641u, 0xc3604c06u, 0x61a806b5u, 0xf0177a28u, 0xc0f586e0u, 0x006058aau, 0x30dc7d62u, 0x11e69ed7u, 0x2338ea63u, 0x53c2dd94u, 0xc2c21634u, 0xbbcbee56u, 0x90bcb6deu, 0xebfc7da1u, 0xce591d76u, 0x6f05e409u, 0x4b7c0188u, 0x39720a3du, 0x7c927c24u, 0x86e3725fu, 0x724d9db9u, 0x1ac15bb4u, 0xd39eb8fcu, 0xed545578u, 0x08fca5b5u, 0xd83d7cd3u, 0x4dad0fc4u, 0x1e50ef5eu, 0xb161e6f8u, 0xa28514d9u, 0x6c51133cu, 0x6fd5c7e7u, 0x56e14ec4u, 0x362abfceu, 0xddc6c837u, 0xd79a3234u, 0x92638212u, 0x670efa8eu, 0x406000e0u}, {0x3a39ce37u, 0xd3faf5cfu, 0xabc27737u, 0x5ac52d1bu, 0x5cb0679eu, 0x4fa33742u, 0xd3822740u, 0x99bc9bbeu, 0xd5118e9du, 0xbf0f7315u, 0xd62d1c7eu, 0xc700c47bu, 0xb78c1b6bu, 0x21a19045u, 0xb26eb1beu, 0x6a366eb4u, 0x5748ab2fu, 0xbc946e79u, 0xc6a376d2u, 0x6549c2c8u, 0x530ff8eeu, 0x468dde7du, 0xd5730a1du, 0x4cd04dc6u, 0x2939bbdbu, 0xa9ba4650u, 0xac9526e8u, 0xbe5ee304u, 0xa1fad5f0u, 0x6a2d519au, 0x63ef8ce2u, 0x9a86ee22u, 0xc089c2b8u, 0x43242ef6u, 0xa51e03aau, 0x9cf2d0a4u, 0x83c061bau, 0x9be96a4du, 0x8fe51550u, 0xba645bd6u, 0x2826a2f9u, 0xa73a3ae1u, 0x4ba99586u, 0xef5562e9u, 0xc72fefd3u, 0xf752f7dau, 0x3f046f69u, 0x77fa0a59u, 0x80e4a915u, 0x87b08601u, 0x9b09e6adu, 0x3b3ee593u, 0xe990fd5au, 0x9e34d797u, 0x2cf0b7d9u, 0x022b8b51u, 0x96d5ac3au, 0x017da67du, 0xd1cf3ed6u, 0x7c7d2d28u, 0x1f9f25cfu, 0xadf2b89bu, 0x5ad6b472u, 0x5a88f54cu, 0xe029ac71u, 0xe019a5e6u, 0x47b0acfdu, 0xed93fa9bu, 0xe8d3c48du, 0x283b57ccu, 0xf8d56629u, 0x79132e28u, 0x785f0191u, 0xed756055u, 0xf7960e44u, 0xe3d35e8cu, 0x15056dd4u, 0x88f46dbau, 0x03a16125u, 0x0564f0bdu, 0xc3eb9e15u, 0x3c9057a2u, 0x97271aecu, 0xa93a072au, 0x1b3f6d9bu, 0x1e6321f5u, 0xf59c66fbu, 0x26dcf319u, 0x7533d928u, 0xb155fdf5u, 0x03563482u, 0x8aba3cbbu, 0x28517711u, 0xc20ad9f8u, 0xabcc5167u, 0xccad925fu, 0x4de81751u, 0x3830dc8eu, 0x379d5862u, 0x9320f991u, 0xea7a90c2u, 0xfb3e7bceu, 0x5121ce64u, 0x774fbe32u, 0xa8b6e37eu, 0xc3293d46u, 0x48de5369u, 0x6413e680u, 0xa2ae0810u, 0xdd6db224u, 0x69852dfdu, 0x09072166u, 0xb39a460au, 0x6445c0ddu, 0x586cdecfu, 0x1c20c8aeu, 0x5bbef7ddu, 0x1b588d40u, 0xccd2017fu, 0x6bb4e3bbu, 0xdda26a7eu, 0x3a59ff45u, 0x3e350a44u, 0xbcb4cdd5u, 0x72eacea8u, 0xfa6484bbu, 0x8d6612aeu, 0xbf3c6f47u, 0xd29be463u, 0x542f5d9eu, 0xaec2771bu, 0xf64e6370u, 0x740e0d8du, 0xe75b1357u, 0xf8721671u, 0xaf537d5du, 0x4040cb08u, 0x4eb4e2ccu, 0x34d2466au, 0x0115af84u, 0xe1b00428u, 0x95983a1du, 0x06b89fb4u, 0xce6ea048u, 0x6f3f3b82u, 0x3520ab82u, 0x011a1d4bu, 0x277227f8u, 0x611560b1u, 0xe7933fdcu, 0xbb3a792bu, 0x344525bdu, 0xa08839e1u, 0x51ce794bu, 0x2f32c9b7u, 0xa01fbac9u, 0xe01cc87eu, 0xbcc7d1f6u, 0xcf0111c3u, 0xa1e8aac7u, 0x1a908749u, 0xd44fbd9au, 0xd0dadecbu, 0xd50ada38u, 0x0339c32au, 0xc6913667u, 0x8df9317cu, 0xe0b12b4fu, 0xf79e59b7u, 0x43f5bb3au, 0xf2d519ffu, 0x27d9459cu,
  0xbf97222cu, 0x15e6fc2au, 0x0f91fc71u, 0x9b941525u, 0xfae59361u, 0xceb69cebu, 0xc2a86459u, 0x12baa8d1u, 0xb6c1075eu, 0xe3056a0cu, 0x10d25065u, 0xcb03a442u, 0xe0ec6e0eu, 0x1698db3bu, 0x4c98a0beu, 0x3278e964u, 0x9f1f9532u, 0xe0d392dfu, 0xd3a0342bu, 0x8971f21eu, 0x1b0a7441u, 0x4ba3348cu, 0xc5be7120u, 0xc37632d8u, 0xdf359f8du, 0x9b992f2eu, 0xe60b6f47u, 0x0fe3f11du, 0xe54cda54u, 0x1edad891u, 0xce6279cfu, 0xcd3e7e6fu, 0x1618b166u, 0xfd2c1d05u, 0x848fd2c5u, 0xf6fb2299u, 0xf523f357u, 0xa6327623u, 0x93a83531u, 0x56cccd02u, 0xacf08162u, 0x5a75ebb5u, 0x6e163697u, 0x88d273ccu, 0xde966292u, 0x81b949d0u, 0x4c50901bu, 0x71c65614u, 0xe6c6c7bdu, 0x327a140au, 0x45e1d006u, 0xc3f27b9au, 0xc9aa53fdu, 0x62a80f00u, 0xbb25bfe2u, 0x35bdd2f6u, 0x71126905u, 0xb2040222u, 0xb6cbcf7cu, 0xcd769c2bu, 0x53113ec0u, 0x1640e3d3u, 0x38abbd60u, 0x2547adf0u, 0xba38209cu, 0xf746ce76u, 0x77afa1c5u, 0x20756060u, 0x85cbfe4eu, 0x8ae88dd8u, 0x7aaaf9b0u, 0x4cf9aa7eu, 0x1948c25cu, 0x02fb8a8cu, 0x01c36ae4u, 0xd6ebe1f9u, 0x90d4f869u, 0xa65cdea0u, 0x3f09252du, 0xc208e69fu, 0xb74e6132u, 0xce77e25bu, 0x578fdfe3u, 0x3ac372e6u}};
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
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
EXTERN tabpage_T *first_tabpage;
EXTERN char_u e_umark [] INIT (= N_ ("E78: Unknown mark"));
EXTERN char_u e_marknotset [] INIT (= N_ ("E20: Mark not set"));
EXTERN char_u e_prev_dir [] INIT (= N_ ("E459: Cannot go back to previous directory"));
EXTERN char_u e_noprevre [] INIT (= N_ ("E35: No previous regular expression"));
EXTERN char_u e_noprev [] INIT (= N_ ("E34: No previous command"));
EXTERN win_T *prevwin INIT (= NULL);
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
EXTERN proftime_T bevalexpr_due;
EXTERN char_u e_invexpr2 [] INIT (= N_ ("E15: Invalid expression: %s"));
EXTERN char_u *p_pexpr;
EXTERN char_u *p_bexpr;
EXTERN char_u e_invargval [] INIT (= N_ ("E475: Invalid value for argument %s"));
EXTERN int autocmd_fname_full;
EXTERN char_u *autocmd_fname INIT (= NULL);
EXTERN unsigned  swb_flags;
EXTERN char need_key_msg [] INIT (= N_ ("Need encryption key for \"%s\""));
EXTERN char_u no_lines_msg [] INIT (= N_ ("--No lines in buffer--"));
EXTERN struct msglist **msg_list INIT (= NULL);
EXTERN int called_emsg;
EXTERN char_u *keep_msg INIT (= NULL);
EXTERN int msg_scrolled;
EXTERN char bot_top_msg [] INIT (= N_ ("search hit BOTTOM, continuing at TOP"));
EXTERN char top_bot_msg [] INIT (= N_ ("search hit TOP, continuing at BOTTOM"));
EXTERN char_u e_maxmempat [] INIT (= N_ ("E363: pattern uses more memory than 'maxmempattern'"));
EXTERN char_u e_winheight [] INIT (= N_ ("E591: 'winheight' cannot be smaller than 'winminheight'"));
EXTERN char_u e_notopen [] INIT (= N_ ("E484: Can't open file %s"));
EXTERN frame_T *topframe;
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
EXTERN char_u e_au_recursive [] INIT (= N_ ("E952: Autocommand caused recursive behavior"));
EXTERN char_u e_secure [] INIT (= N_ ("E523: Not allowed here"));
EXTERN char_u e_positive [] INIT (= N_ ("E487: Argument must be positive"));
EXTERN char_u e_curdir [] INIT (= N_ ("E12: Command not allowed from exrc/vimrc in current dir or tag search"));
EXTERN pos_T saved_cursor;
EXTERN tabpage_T *curtab;
EXTERN win_T *curwin;
EXTERN int current_scrollbar;
EXTERN vimmenu_T *current_menu;
EXTERN int p_secure;
EXTERN char_u e_bufloaded [] INIT (= N_ ("E139: File is loaded in another buffer"));
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
EXTERN int highlight_attr [HLF_COUNT];
EXTERN long  p_ttm;
EXTERN long  p_tm;
EXTERN int p_stmp;
EXTERN int p_lrm;
EXTERN int p_confirm;
EXTERN typebuf_T typebuf;
EXTERN long_u scrollbar_value;
EXTERN except_T *caught_stack INIT (= NULL);
EXTERN int did_uncaught_emsg;
EXTERN int arrow_used;
EXTERN int mouse_row;
EXTERN int msg_row;
EXTERN int cmdline_row;
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
EXTERN win_T *au_pending_free_win INIT (= NULL);
EXTERN buf_T *au_pending_free_buf INIT (= NULL);
EXTERN except_T *current_exception;
EXTERN int stop_insert_mode;
EXTERN pos_T where_paste_started;
EXTERN char *font_argument INIT (= NULL);
EXTERN int p_guipty;
EXTERN char_u *p_guifont;
EXTERN int p_bevalterm;
EXTERN pos_T Insstart_orig;
EXTERN pos_T Insstart;
EXTERN pos_T VIsual;
EXTERN int p_hkmap;
EXTERN int p_hkmapp;
EXTERN char_u *p_lcs;
EXTERN long  p_linespace;
EXTERN char_u *p_km;
EXTERN time_T starttime;

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

