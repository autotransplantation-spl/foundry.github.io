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
struct block_def {
    int startspaces;
    int endspaces;
    int textlen;
    char_u *textstart;
    colnr_T textcol;
    colnr_T start_vcol;
    colnr_T end_vcol;
    int is_short;
    int is_MAX;
    int is_oneChar;
    int pre_whitesp;
    int pre_whitesp_c;
    colnr_T end_char_vcols;
    colnr_T start_char_vcols;
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
struct nr_trans {
    mf_hashitem_T nt_hashitem;

    #define nt_old_bnum nt_hashitem.mhi_key	/* old, negative, number */
    blocknr_T nt_new_bnum;
};
EXTERN int p_paste;
EXTERN char_u *p_sel;
EXTERN char_u e_abort [] INIT (= N_ ("E470: Command aborted"));
EXTERN char_u e_modifiable [] INIT (= N_ ("E21: Cannot make changes, 'modifiable' is off"));
EXTERN int p_ri;
EXTERN int p_sr;
EXTERN long  p_report;
EXTERN int p_js;
EXTERN int p_smd;
yankreg_T *y_read_regs = NULL;
EXTERN char_u e_noinstext [] INIT (= N_ ("E29: No inserted text yet"));
yankreg_T y_regs [NUM_REGISTERS];
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
int y_append;
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
yankreg_T *y_previous = NULL;
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
int execreg_lastc = NUL;
char opchars [] [3] = {{NUL, NUL, FALSE}, {'d', NUL, FALSE}, {'y', NUL, FALSE}, {'c', NUL, FALSE}, {'<', NUL, TRUE}, {'>', NUL, TRUE}, {'!', NUL, TRUE}, {'g', '~', FALSE}, {'=', NUL, TRUE}, {'g', 'q', TRUE}, {':', NUL, TRUE}, {'g', 'U', FALSE}, {'g', 'u', FALSE}, {'J', NUL, TRUE}, {'g', 'J', TRUE}, {'g', '?', FALSE}, {'r', NUL, FALSE}, {'I', NUL, FALSE}, {'A', NUL, FALSE}, {'z', 'f', TRUE}, {'z', 'o', TRUE}, {'z', 'O', TRUE}, {'z', 'c', TRUE}, {'z', 'C', TRUE}, {'z', 'd', TRUE}, {'z', 'D', TRUE}, {'g', 'w', TRUE}, {'g', '@', FALSE}, {Ctrl_A, NUL, FALSE}, {Ctrl_X, NUL, FALSE},};
EXTERN proftime_T bevalexpr_due;
EXTERN char_u e_invexpr2 [] INIT (= N_ ("E15: Invalid expression: %s"));
EXTERN char_u *p_pexpr;
EXTERN char_u *p_bexpr;
char_u *expr_line = NULL;
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
yankreg_T *y_current;
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
EXTERN time_T starttime;
EXTERN int stop_insert_mode;
EXTERN pos_T where_paste_started;
EXTERN char *font_argument INIT (= NULL);
EXTERN int p_guipty;
EXTERN char_u *p_guifont;
EXTERN int p_bevalterm;
EXTERN pos_T Insstart_orig;
EXTERN pos_T Insstart;
EXTERN pos_T VIsual;
EXTERN char_u *p_hlg;
EXTERN int p_hid;
EXTERN char_u *p_lm;
EXTERN char_u *p_km;
EXTERN char_u *p_isf;
EXTERN char_u e_dirnotf [] INIT (= N_ ("E919: Directory not found in '%s': \"%s\""));

void write_reg_contents (int name, char_u *str, int maxlen, int must_append) {
    write_reg_contents_ex (name, str, maxlen, must_append, MAUTO, 0L);
}

void write_reg_contents_ex (int name, char_u *str, int maxlen, int must_append, int yank_type, long  block_len) {
    yankreg_T *old_y_previous, *old_y_current;
    long  len;
    if (maxlen >= 0)
        len = maxlen;
    else
        len = (long ) STRLEN (str);
    if (name == '/') {
        set_last_search_pat (str, RE_SEARCH, TRUE, TRUE);
        return;
    }
    if (name == '#') {
        buf_T *buf;
        if (VIM_ISDIGIT (*str)) {
            int num = atoi ((char *) str);
            buf = buflist_findnr (num);
            if (buf == NULL)
                EMSGN (_ (e_nobufnr), (long ) num);
        }
        else
            buf = buflist_findnr (buflist_findpat (str, str + STRLEN (str), TRUE, FALSE, FALSE));
        if (buf == NULL)
            return;
        curwin->w_alt_fnum = buf->b_fnum;
        return;
    }
    if (name == '=') {
        char_u *p, *s;
        p = vim_strnsave (str, (int) len);
        if (p == NULL)
            return;
        if (must_append) {
            s = concat_str (get_expr_line_src (), p);
            vim_free (p);
            p = s;
        }
        set_expr_line (p);
        return;
    }
    if (name == '_')
        return;
    if (init_write_reg (name, &old_y_previous, &old_y_current, must_append, &yank_type) == FAIL)
        return;
    str_to_reg (y_current, yank_type, str, len, block_len, FALSE);
    finish_write_reg (name, old_y_previous, old_y_current);
}

char_u *get_expr_line_src (void) {
    if (expr_line == NULL)
        return NULL;
    return vim_strsave (expr_line);
}

void set_expr_line (char_u *new_line) {
    vim_free (expr_line);
    expr_line = new_line;
}

static int init_write_reg (int name, yankreg_T **old_y_previous, yankreg_T **old_y_current, int must_append, int *yank_type) {
    if (!valid_yank_reg (name, TRUE)) {
        emsg_invreg (name);
        return FAIL;
    }
    *old_y_previous = y_previous;
    *old_y_current = y_current;
    get_yank_register (name, TRUE);
    if (!y_append && !must_append)
        free_yank_all ();
    return OK;
}

int valid_yank_reg (int regname, int writing) {
    if ((regname > 0 && ASCII_ISALNUM (regname)) || (!writing && vim_strchr ((char_u *) "/.%:=", regname) != NULL) || regname == '#' || regname == '"' || regname == '-' || regname == '_')
        return TRUE;
    return FALSE;
}

void get_yank_register (int regname, int writing) {
    int i;
    y_append = FALSE;
    if ((regname == 0 || regname == '"') && !writing && y_previous != NULL) {
        y_current = y_previous;
        return;
    }
    i = regname;
    if (VIM_ISDIGIT (i))
        i -= '0';
    else if (ASCII_ISLOWER (i))
        i = CharOrdLow (i) + 10;
    else if (ASCII_ISUPPER (i)) {
        i = CharOrdUp (i) + 10;
        y_append = TRUE;
    }
    else if (regname == '-')
        i = DELETION_REGISTER;
    else
        i = 0;
    y_current = &(y_regs[i]);
    if (writing)
        y_previous = y_current;
}

static void free_yank_all (void) {
    free_yank (y_current -> y_size);
}

static void free_yank (long  n) {
    if (y_current->y_array != NULL) {
        long  i;
        for (i = n; --i >= 0;) {
            vim_free (y_current -> y_array [i]);
        }
        VIM_CLEAR (y_current -> y_array);
    }
}

static void str_to_reg (yankreg_T *y_ptr, int yank_type, char_u *str, long  len, long  blocklen, int str_list) {
    int type;
    int lnum;
    long  start;
    long  i;
    int extra;
    int newlines;
    int extraline = 0;
    int append = FALSE;
    char_u *s;
    char_u **ss;
    char_u **pp;
    long  maxlen;
    if (y_ptr->y_array == NULL)
        y_ptr->y_size = 0;
    if (yank_type == MAUTO)
        type = ((str_list || (len > 0 && (str[len - 1] == NL || str[len - 1] == CAR))) ? MLINE : MCHAR);
    else
        type = yank_type;
    newlines = 0;
    if (str_list) {
        for (ss = (char_u **) str; *ss != NULL; ++ss)
            ++newlines;
    }
    else {
        for (i = 0; i < len; i++)
            if (str[i] == '\n')
                ++newlines;
        if (type == MCHAR || len == 0 || str[len - 1] != '\n') {
            extraline = 1;
            ++newlines;
        }
        if (y_ptr->y_size > 0 && y_ptr->y_type == MCHAR) {
            append = TRUE;
            --newlines;
        }
    }
    if (y_ptr->y_size + newlines == 0) {
        VIM_CLEAR (y_ptr -> y_array);
        return;
    }
    pp = (char_u **) lalloc_clear ((y_ptr->y_size + newlines) * sizeof (char_u *), TRUE);
    if (pp == NULL)
        return;
    for (lnum = 0; lnum < y_ptr->y_size; ++lnum)
        pp[lnum] = y_ptr->y_array[lnum];
    vim_free (y_ptr -> y_array);
    y_ptr->y_array = pp;
    maxlen = 0;
    if (str_list) {
        for (ss = (char_u **) str; *ss != NULL; ++ss, ++lnum) {
            i = (long ) STRLEN (*ss);
            pp[lnum] = vim_strnsave (*ss, i);
            if (i > maxlen)
                maxlen = i;
        }
    }
    else {
        for (start = 0; start < len + extraline; start += i + 1) {
            for (i = start; i < len; ++i)
                if (str[i] == '\n')
                    break;
            i -= start;
            if (i > maxlen)
                maxlen = i;
            if (append) {
                --lnum;
                extra = (int) STRLEN (y_ptr->y_array[lnum]);
            }
            else
                extra = 0;
            s = alloc ((unsigned ) (i + extra + 1));
            if (s == NULL)
                break;
            if (extra)
                mch_memmove (s, y_ptr->y_array[lnum], (size_t) extra);
            if (append)
                vim_free (y_ptr->y_array[lnum]);
            if (i)
                mch_memmove (s +extra, str +start, (size_t) i);
            extra += i;
            s[extra] = NUL;
            y_ptr->y_array[lnum++] = s;
            while (--extra >= 0) {
                if (*s == NUL)
                    *s = '\n';
                ++s;
            }
            append = FALSE;
        }
    }
    y_ptr->y_type = type;
    y_ptr->y_size = lnum;
    if (type == MBLOCK)
        y_ptr->y_width = (blocklen < 0 ? maxlen - 1 : blocklen);
    else
        y_ptr->y_width = 0;
    y_ptr->y_time_set = vim_time ();
}

static void finish_write_reg (int name, yankreg_T *old_y_previous, yankreg_T *old_y_current) {
    if (name != '"')
        y_previous = old_y_previous;
    y_current = old_y_current;
}

void clear_oparg (oparg_T *oap) {
    vim_memset (oap, 0, sizeof (oparg_T));
}

int get_op_char (int optype) {
    return opchars[optype][0];
}

int get_extra_op_char (int optype) {
    return opchars[optype][1];
}

char_u *get_reg_contents (int regname, int flags) {
    long  i;
    char_u *retval;
    int allocated;
    long  len;
    if (regname == '=') {
        if (flags & GREG_NO_EXPR)
            return NULL;
        if (flags & GREG_EXPR_SRC)
            return getreg_wrap_one_line (get_expr_line_src (), flags);
        return getreg_wrap_one_line (get_expr_line (), flags);
    }
    if (regname == '@')
        regname = '"';
    if (regname != NUL && !valid_yank_reg (regname, FALSE))
        return NULL;
    if (get_spec_reg (regname, &retval, &allocated, FALSE)) {
        if (retval == NULL)
            return NULL;
        if (allocated)
            return getreg_wrap_one_line (retval, flags);
        return getreg_wrap_one_line (vim_strsave (retval), flags);
    }
    get_yank_register (regname, FALSE);
    if (y_current->y_array == NULL)
        return NULL;
    if (flags & GREG_LIST) {
        list_T *list = list_alloc ();
        int error = FALSE;
        if (list == NULL)
            return NULL;
        for (i = 0; i < y_current->y_size; ++i)
            if (list_append_string (list, y_current->y_array[i], -1) == FAIL)
                error = TRUE;
        if (error) {
            list_free (list);
            return NULL;
        }
        return (char_u *) list;
    }
    len = 0;
    for (i = 0; i < y_current->y_size; ++i) {
        len += (long ) STRLEN (y_current->y_array[i]);
        if (y_current->y_type == MLINE || i < y_current->y_size - 1)
            ++len;
    }
    retval = lalloc (len +1, TRUE);
    if (retval != NULL) {
        len = 0;
        for (i = 0; i < y_current->y_size; ++i) {
            STRCPY (retval + len, y_current -> y_array [i]);
            len += (long ) STRLEN (retval +len);
            if (y_current->y_type == MLINE || i < y_current->y_size - 1)
                retval[len++] = '\n';
        }
        retval[len] = NUL;
    }
    return retval;
}

static char_u *getreg_wrap_one_line (char_u *s, int flags) {
    if (flags & GREG_LIST) {
        list_T *list = list_alloc ();
        if (list != NULL) {
            if (list_append_string (list, NULL, -1) == FAIL) {
                list_free (list);
                return NULL;
            }
            list->lv_first->li_tv.vval.v_string = s;
        }
        return (char_u *) list;
    }
    return s;
}

char_u *get_expr_line (void) {
    char_u *expr_copy;
    char_u *rv;
    static int nested = 0;
    if (expr_line == NULL)
        return NULL;
    expr_copy = vim_strsave (expr_line);
    if (expr_copy == NULL)
        return NULL;
    if (nested >= 10)
        return expr_copy;
    ++nested;
    rv = eval_to_string (expr_copy, NULL, TRUE);
    --nested;
    vim_free (expr_copy);
    return rv;
}

int get_spec_reg (int regname, char_u **argp, int *allocated, int errmsg) {
    int cnt;
    *argp = NULL;
    *allocated = FALSE;
    switch (regname) {
    case '%' :
        if (errmsg)
            check_fname ();
        *argp = curbuf->b_fname;
        return TRUE;
    case '#' :
        *argp = getaltfname (errmsg);
        return TRUE;
    case '=' :
        *argp = get_expr_line ();
        *allocated = TRUE;
        return TRUE;
    case ':' :
        if (last_cmdline == NULL && errmsg)
            EMSG (_ (e_nolastcmd));
        *argp = last_cmdline;
        return TRUE;
    case '/' :
        if (last_search_pat () == NULL && errmsg)
            EMSG (_ (e_noprevre));
        *argp = last_search_pat ();
        return TRUE;
    case '.' :
        *argp = get_last_insert_save ();
        *allocated = TRUE;
        if (*argp == NULL && errmsg)
            EMSG (_ (e_noinstext));
        return TRUE;
    case Ctrl_F :
    case Ctrl_P :
        if (!errmsg)
            return FALSE;
        *argp = file_name_at_cursor (FNAME_MESS | FNAME_HYP | (regname == Ctrl_P ? FNAME_EXP : 0), 1L, NULL);
        *allocated = TRUE;
        return TRUE;
    case Ctrl_W :
    case Ctrl_A :
        if (!errmsg)
            return FALSE;
        cnt = find_ident_under_cursor (argp, regname == Ctrl_W ? (FIND_IDENT | FIND_STRING) : FIND_STRING);
        *argp = cnt ? vim_strnsave (*argp, cnt) : NULL;
        *allocated = TRUE;
        return TRUE;
    case '_' :
        *argp = (char_u *) "";
        return TRUE;
    }
    return FALSE;
}

int read_viminfo_register (vir_T *virp, int force) {
    int eof;
    int do_it = TRUE;
    int size;
    int limit;
    int i;
    int set_prev = FALSE;
    char_u *str;
    char_u **array = NULL;
    int new_type = MCHAR;
    colnr_T new_width = 0;
    str = virp->vir_line + 1;
    if (*str == '"') {
        set_prev = TRUE;
        str++;
    }
    if (!ASCII_ISALNUM (*str) && *str != '-') {
        if (viminfo_error ("E577: ", _ ("Illegal register name"), virp->vir_line))
            return TRUE;
        do_it = FALSE;
    }
    get_yank_register (* str ++, FALSE);
    if (!force && y_current->y_array != NULL)
        do_it = FALSE;
    if (*str == '@') {
        if (force || execreg_lastc == NUL)
            execreg_lastc = str[-1];
    }
    size = 0;
    limit = 100;
    if (do_it) {
        if (set_prev)
            y_previous = y_current;
        array = (char_u **) alloc ((unsigned ) (limit * sizeof (char_u *)));
        str = skipwhite (skiptowhite (str));
        if (STRNCMP (str, "CHAR", 4) == 0)
            new_type = MCHAR;
        else if (STRNCMP (str, "BLOCK", 5) == 0)
            new_type = MBLOCK;
        else
            new_type = MLINE;
        str = skipwhite (skiptowhite (str));
        new_width = getdigits (&str);
    }
    while (!(eof = viminfo_readline (virp)) && (virp->vir_line[0] == TAB || virp->vir_line[0] == '<')) {
        if (do_it) {
            if (size == limit) {
                char_u **new_array = (char_u **) alloc ((unsigned ) (limit * 2 * sizeof (char_u *)));
                if (new_array == NULL) {
                    do_it = FALSE;
                    break;
                }
                for (i = 0; i < limit; i++)
                    new_array[i] = array[i];
                vim_free (array);
                array = new_array;
                limit *= 2;
            }
            str = viminfo_readstring (virp, 1, TRUE);
            if (str != NULL)
                array[size++] = str;
            else
                do_it = FALSE;
        }
    }
    if (do_it) {
        for (i = 0; i < y_current->y_size; i++)
            vim_free (y_current->y_array[i]);
        vim_free (y_current -> y_array);
        y_current->y_type = new_type;
        y_current->y_width = new_width;
        y_current->y_size = size;
        y_current->y_time_set = 0;
        if (size == 0) {
            y_current->y_array = NULL;
        }
        else {
            y_current->y_array = (char_u **) alloc ((unsigned ) (size * sizeof (char_u *)));
            for (i = 0; i < size; i++) {
                if (y_current->y_array == NULL)
                    vim_free (array[i]);
                else
                    y_current->y_array[i] = array[i];
            }
        }
    }
    else {
        for (i = 0; i < size; i++)
            vim_free (array[i]);
    }
    vim_free (array);
    return eof;
}

void write_viminfo_registers (FILE *fp) {
    int i, j;
    char_u *type;
    char_u c;
    int num_lines;
    int max_num_lines;
    int max_kbyte;
    long  len;
    yankreg_T *y_ptr;
    fputs (_ ("\n# Registers:\n"), fp);
    max_num_lines = get_viminfo_parameter ('<');
    if (max_num_lines < 0)
        max_num_lines = get_viminfo_parameter ('"');
    if (max_num_lines == 0)
        return;
    max_kbyte = get_viminfo_parameter ('s');
    if (max_kbyte == 0)
        return;
    for (i = 0; i < NUM_REGISTERS; i++) {
        if (y_read_regs != NULL && y_read_regs[i].y_array != NULL && (y_regs[i].y_array == NULL || y_read_regs[i].y_time_set > y_regs[i].y_time_set))
            y_ptr = &y_read_regs[i];
        else if (y_regs[i].y_array == NULL)
            continue;
        else
            y_ptr = &y_regs[i];
        num_lines = y_ptr->y_size;
        if (num_lines == 0 || (num_lines == 1 && y_ptr->y_type == MCHAR && *y_ptr->y_array[0] == NUL))
            continue;
        if (max_kbyte > 0) {
            len = 0;
            for (j = 0; j < num_lines; j++)
                len += (long ) STRLEN (y_ptr->y_array[j]) + 1L;
            if (len > (long ) max_kbyte * 1024L)
                continue;
        }
        switch (y_ptr->y_type) {
        case MLINE :
            type = (char_u *) "LINE";
            break;
        case MCHAR :
            type = (char_u *) "CHAR";
            break;
        case MBLOCK :
            type = (char_u *) "BLOCK";
            break;
        default :
            sprintf ((char *) IObuff, _ ("E574: Unknown register type %d"), y_ptr->y_type);
            emsg (IObuff);
            type = (char_u *) "LINE";
            break;
        }
        if (y_previous == &y_regs[i])
            fprintf (fp, "\"");
        c = get_register_name (i);
        fprintf (fp, "\"%c", c);
        if (c == execreg_lastc)
            fprintf (fp, "@");
        fprintf (fp, "\t%s\t%d\n", type, (int) y_ptr -> y_width);
        if (max_num_lines > 0 && num_lines > max_num_lines)
            num_lines = max_num_lines;
        for (j = 0; j < num_lines; j++) {
            putc ('\t', fp);
            viminfo_writestring (fp, y_ptr -> y_array [j]);
        }
        {
            int flags = 0;
            int remaining;
            if (y_previous == &y_regs[i])
                flags |= REG_PREVIOUS;
            if (c == execreg_lastc)
                flags |= REG_EXEC;
            fprintf (fp, "|%d,%d,%d,%d,%d,%d,%ld", BARTYPE_REGISTER, flags, i, y_ptr -> y_type, num_lines, (int) y_ptr -> y_width, (long) y_ptr -> y_time_set);
            remaining = LSIZE - 71;
            for (j = 0; j < num_lines; j++) {
                putc (',', fp);
                --remaining;
                remaining = barline_writestring (fp, y_ptr->y_array[j], remaining);
            }
            putc ('\n', fp);
        }
    }
}

int get_register_name (int num) {
    if (num == -1)
        return '"';
    else if (num < 10)
        return num + '0';
    else if (num == DELETION_REGISTER)
        return '-';
    else {
        return num + 'a' - 10;
    }
}

int get_expr_register (void) {
    char_u *new_line;
    new_line = getcmdline ('=', 0L, 0);
    if (new_line == NULL)
        return NUL;
    if (*new_line == NUL)
        vim_free (new_line);
    else
        set_expr_line (new_line);
    return '=';
}

void adjust_cursor_eol (void) {
    if (curwin->w_cursor.col > 0 && gchar_cursor () == NUL && (ve_flags & VE_ONEMORE) == 0 && !(restart_edit || (State & INSERT))) {
        dec_cursor ();
        if (ve_flags == VE_ALL) {
            colnr_T scol, ecol;
            getvcol (curwin, & curwin -> w_cursor, & scol, NULL, & ecol);
            curwin->w_cursor.coladd = ecol - scol + 1;
        }
    }
}

int get_op_type (int char1, int char2) {
    int i;
    if (char1 == 'r')
        return OP_REPLACE;
    if (char1 == '~')
        return OP_TILDE;
    if (char1 == 'g' && char2 == Ctrl_A)
        return OP_NR_ADD;
    if (char1 == 'g' && char2 == Ctrl_X)
        return OP_NR_SUB;
    for (i = 0;; ++i) {
        if (opchars[i][0] == char1 && opchars[i][1] == char2)
            break;
        if (i == (int) (sizeof (opchars) / sizeof (char [3]) - 1)) {
            internal_error ("get_op_type()");
            break;
        }
    }
    return i;
}

int fex_format (linenr_T lnum, long  count, int c) {
    int use_sandbox = was_set_insecurely ((char_u *) "formatexpr", OPT_LOCAL);
    int r;
    char_u *fex;
    set_vim_var_nr (VV_LNUM, lnum);
    set_vim_var_nr (VV_COUNT, count);
    set_vim_var_char (c);
    fex = vim_strsave (curbuf->b_p_fex);
    if (fex == NULL)
        return 0;
    if (use_sandbox)
        ++sandbox;
    r = (int) eval_to_number (fex);
    if (use_sandbox)
        --sandbox;
    set_vim_var_string (VV_CHAR, NULL, - 1);
    vim_free (fex);
    return r;
}

void shift_line (int left, int round, int amount, int call_changed_bytes) {
    int count;
    int i, j;
    int p_sw = (int) get_sw_value (curbuf);
    count = get_indent ();
    if (round) {
        i = count / p_sw;
        j = count % p_sw;
        if (j && left)
            --amount;
        if (left) {
            i -= amount;
            if (i < 0)
                i = 0;
        }
        else
            i += amount;
        count = i * p_sw;
    }
    else {
        if (left) {
            count -= p_sw * amount;
            if (count < 0)
                count = 0;
        }
        else
            count += p_sw * amount;
    }
    if (State & VREPLACE_FLAG)
        change_indent (INDENT_SET, count, FALSE, NUL, call_changed_bytes);
    else
        (void) set_indent (count, call_changed_bytes ? SIN_CHANGED : 0);
}

int paragraph_start (linenr_T lnum) {
    char_u *p;
    int leader_len = 0;
    char_u *leader_flags = NULL;
    int next_leader_len;
    char_u *next_leader_flags;
    int do_comments;
    if (lnum <= 1)
        return TRUE;
    p = ml_get (lnum -1);
    if (*p == NUL)
        return TRUE;
    do_comments = has_format_option (FO_Q_COMS);
    if (fmt_check_par (lnum -1, &leader_len, &leader_flags, do_comments))
        return TRUE;
    if (fmt_check_par (lnum, &next_leader_len, &next_leader_flags, do_comments))
        return TRUE;
    if (has_format_option (FO_WHITE_PAR) && !ends_in_white (lnum -1))
        return TRUE;
    if (has_format_option (FO_Q_NUMBER) && (get_number_indent (lnum) > 0))
        return TRUE;
    if (!same_leader (lnum -1, leader_len, leader_flags, next_leader_len, next_leader_flags))
        return TRUE;
    return FALSE;
}

static int fmt_check_par (linenr_T lnum, int *leader_len, char_u **leader_flags, int do_comments) {
    char_u *flags = NULL;
    char_u *ptr;
    ptr = ml_get (lnum);
    if (do_comments)
        *leader_len = get_leader_len (ptr, leader_flags, FALSE, TRUE);
    else
        *leader_len = 0;
    if (*leader_len > 0) {
        flags = *leader_flags;
        while (*flags && *flags != ':' && *flags != COM_END)
            ++flags;
    }
    return (*skipwhite (ptr +*leader_len) == NUL || (*leader_len > 0 && *flags == COM_END) || startPS (lnum, NUL, FALSE));
}

static int ends_in_white (linenr_T lnum) {
    char_u *s = ml_get (lnum);
    size_t l;
    if (*s == NUL)
        return FALSE;
    l = STRLEN (s) - 1;
    return VIM_ISWHITE (s[l]);
}

static int same_leader (linenr_T lnum, int leader1_len, char_u *leader1_flags, int leader2_len, char_u *leader2_flags) {
    int idx1 = 0, idx2 = 0;
    char_u *p;
    char_u *line1;
    char_u *line2;
    if (leader1_len == 0)
        return (leader2_len == 0);
    if (leader1_flags != NULL) {
        for (p = leader1_flags; *p && *p != ':'; ++p) {
            if (*p == COM_FIRST)
                return (leader2_len == 0);
            if (*p == COM_END)
                return FALSE;
            if (*p == COM_START) {
                if (*(ml_get (lnum) + leader1_len) == NUL)
                    return FALSE;
                if (leader2_flags == NULL || leader2_len == 0)
                    return FALSE;
                for (p = leader2_flags; *p && *p != ':'; ++p)
                    if (*p == COM_MIDDLE)
                        return TRUE;
                return FALSE;
            }
        }
    }
    line1 = vim_strsave (ml_get (lnum));
    if (line1 != NULL) {
        for (idx1 = 0; VIM_ISWHITE (line1[idx1]); ++idx1)
            ;
        line2 = ml_get (lnum +1);
        for (idx2 = 0; idx2 < leader2_len; ++idx2) {
            if (!VIM_ISWHITE (line2[idx2])) {
                if (line1[idx1++] != line2[idx2])
                    break;
            }
            else
                while (VIM_ISWHITE (line1[idx1]))
                    ++idx1;
        }
        vim_free (line1);
    }
    return (idx2 == leader2_len && idx1 == leader1_len);
}

void format_lines (linenr_T line_count, int avoid_fex) {
    int max_len;
    int is_not_par;
    int next_is_not_par;
    int is_end_par;
    int prev_is_end_par = FALSE;
    int next_is_start_par = FALSE;
    int leader_len = 0;
    int next_leader_len;
    char_u *leader_flags = NULL;
    char_u *next_leader_flags;
    int do_comments;
    int do_comments_list = 0;
    int advance = TRUE;
    int second_indent = -1;
    int do_second_indent;
    int do_number_indent;
    int do_trail_white;
    int first_par_line = TRUE;
    int smd_save;
    long  count;
    int need_set_indent = TRUE;
    int force_format = FALSE;
    int old_State = State;
    max_len = comp_textwidth (TRUE) * 3;
    do_comments = has_format_option (FO_Q_COMS);
    do_second_indent = has_format_option (FO_Q_SECOND);
    do_number_indent = has_format_option (FO_Q_NUMBER);
    do_trail_white = has_format_option (FO_WHITE_PAR);
    if (curwin->w_cursor.lnum > 1)
        is_not_par = fmt_check_par (curwin->w_cursor.lnum - 1, &leader_len, &leader_flags, do_comments);
    else
        is_not_par = TRUE;
    next_is_not_par = fmt_check_par (curwin->w_cursor.lnum, &next_leader_len, &next_leader_flags, do_comments);
    is_end_par = (is_not_par || next_is_not_par);
    if (!is_end_par && do_trail_white)
        is_end_par = !ends_in_white (curwin->w_cursor.lnum - 1);
    curwin->w_cursor.lnum--;
    for (count = line_count; count != 0 && !got_int; --count) {
        if (advance) {
            curwin->w_cursor.lnum++;
            prev_is_end_par = is_end_par;
            is_not_par = next_is_not_par;
            leader_len = next_leader_len;
            leader_flags = next_leader_flags;
        }
        if (count == 1 || curwin->w_cursor.lnum == curbuf->b_ml.ml_line_count) {
            next_is_not_par = TRUE;
            next_leader_len = 0;
            next_leader_flags = NULL;
        }
        else {
            next_is_not_par = fmt_check_par (curwin->w_cursor.lnum + 1, &next_leader_len, &next_leader_flags, do_comments);
            if (do_number_indent)
                next_is_start_par = (get_number_indent (curwin->w_cursor.lnum + 1) > 0);
        }
        advance = TRUE;
        is_end_par = (is_not_par || next_is_not_par || next_is_start_par);
        if (!is_end_par && do_trail_white)
            is_end_par = !ends_in_white (curwin->w_cursor.lnum);
        if (is_not_par) {
            if (line_count < 0)
                break;
        }
        else {
            if (first_par_line && (do_second_indent || do_number_indent) && prev_is_end_par && curwin->w_cursor.lnum < curbuf->b_ml.ml_line_count) {
                if (do_second_indent && !LINEEMPTY (curwin->w_cursor.lnum + 1)) {
                    if (leader_len == 0 && next_leader_len == 0) {
                        second_indent = get_indent_lnum (curwin->w_cursor.lnum + 1);
                    }
                    else {
                        second_indent = next_leader_len;
                        do_comments_list = 1;
                    }
                }
                else if (do_number_indent) {
                    if (leader_len == 0 && next_leader_len == 0) {
                        second_indent = get_number_indent (curwin->w_cursor.lnum);
                    }
                    else {
                        second_indent = get_number_indent (curwin->w_cursor.lnum);
                        do_comments_list = 1;
                    }
                }
            }
            if (curwin->w_cursor.lnum >= curbuf->b_ml.ml_line_count || !same_leader (curwin->w_cursor.lnum, leader_len, leader_flags, next_leader_len, next_leader_flags))
                is_end_par = TRUE;
            if (is_end_par || force_format) {
                if (need_set_indent)
                    (void) set_indent (get_indent (), SIN_CHANGED);
                State = NORMAL;
                coladvance ((colnr_T) MAXCOL);
                while (curwin->w_cursor.col && vim_isspace (gchar_cursor ()))
                    dec_cursor ();
                State = INSERT;
                smd_save = p_smd;
                p_smd = FALSE;
                insertchar (NUL, INSCHAR_FORMAT + (do_comments ? INSCHAR_DO_COM : 0) + (do_comments && do_comments_list ? INSCHAR_COM_LIST : 0) + (avoid_fex ? INSCHAR_NO_FEX : 0), second_indent);
                State = old_State;
                p_smd = smd_save;
                second_indent = -1;
                need_set_indent = is_end_par;
                if (is_end_par) {
                    if (line_count < 0)
                        break;
                    first_par_line = TRUE;
                }
                force_format = FALSE;
            }
            if (!is_end_par) {
                advance = FALSE;
                curwin->w_cursor.lnum++;
                curwin->w_cursor.col = 0;
                if (line_count < 0 && u_save_cursor () == FAIL)
                    break;
                if (next_leader_len > 0) {
                    (void) del_bytes ((long ) next_leader_len, FALSE, FALSE);
                    mark_col_adjust (curwin -> w_cursor.lnum, (colnr_T) 0, 0L, (long) - next_leader_len);
                }
                else if (second_indent > 0) {
                    int indent = getwhitecols_curline ();
                    if (indent > 0) {
                        (void) del_bytes (indent, FALSE, FALSE);
                        mark_col_adjust (curwin -> w_cursor.lnum, (colnr_T) 0, 0L, (long) - indent);
                    }
                }
                curwin->w_cursor.lnum--;
                if (do_join (2, TRUE, FALSE, FALSE, FALSE) == FAIL) {
                    beep_flush ();
                    break;
                }
                first_par_line = FALSE;
                if (STRLEN (ml_get_curline ()) > (size_t) max_len)
                    force_format = TRUE;
                else
                    force_format = FALSE;
            }
        }
        line_breakcheck ();
    }
}

int do_join (long  count, int insert_space, int save_undo, int use_formatoptions, int setmark) {
    char_u *curr = NULL;
    char_u *curr_start = NULL;
    char_u *cend;
    char_u *newp;
    char_u *spaces;
    int endcurr1 = NUL;
    int endcurr2 = NUL;
    int currsize = 0;
    int sumsize = 0;
    linenr_T t;
    colnr_T col = 0;
    int ret = OK;
    int *comments = NULL;
    int remove_comments = (use_formatoptions == TRUE) && has_format_option (FO_REMOVE_COMS);
    int prev_was_comment;
    if (save_undo && u_save ((linenr_T) (curwin->w_cursor.lnum - 1), (linenr_T) (curwin->w_cursor.lnum + count)) == FAIL)
        return FAIL;
    spaces = lalloc_clear ((long_u) count, TRUE);
    if (spaces == NULL)
        return FAIL;
    if (remove_comments) {
        comments = (int *) lalloc_clear ((long_u) count * sizeof (int), TRUE);
        if (comments == NULL) {
            vim_free (spaces);
            return FAIL;
        }
    }
    for (t = 0; t < count; ++t) {
        curr = curr_start = ml_get ((linenr_T) (curwin->w_cursor.lnum + t));
        if (t == 0 && setmark) {
            curwin->w_buffer->b_op_start.lnum = curwin->w_cursor.lnum;
            curwin->w_buffer->b_op_start.col = (colnr_T) STRLEN (curr);
        }
        if (remove_comments) {
            if (t > 0 && prev_was_comment) {
                char_u *new_curr = skip_comment (curr, TRUE, insert_space, &prev_was_comment);
                comments[t] = (int) (new_curr - curr);
                curr = new_curr;
            }
            else
                curr = skip_comment (curr, FALSE, insert_space, &prev_was_comment);
        }
        if (insert_space && t > 0) {
            curr = skipwhite (curr);
            if (*curr != ')' && currsize != 0 && endcurr1 != TAB) {
                if (endcurr1 == ' ')
                    endcurr1 = endcurr2;
                else
                    ++spaces[t];
                if (p_js && (endcurr1 == '.' || (vim_strchr (p_cpo, CPO_JOINSP) == NULL && (endcurr1 == '?' || endcurr1 == '!'))))
                    ++spaces[t];
            }
        }
        currsize = (int) STRLEN (curr);
        sumsize += currsize + spaces[t];
        endcurr1 = endcurr2 = NUL;
        if (insert_space && currsize > 0) {
            {
                endcurr1 = *(curr + currsize - 1);
                if (currsize > 1)
                    endcurr2 = *(curr + currsize - 2);
            }
        }
        line_breakcheck ();
        if (got_int) {
            ret = FAIL;
            goto theend;
        }
    }
    col = sumsize - currsize - spaces[count - 1];
    newp = alloc_check ((unsigned ) (sumsize + 1));
    cend = newp + sumsize;
    *cend = 0;
    for (t = count - 1;; --t) {
        cend -= currsize;
        mch_memmove (cend, curr, (size_t) currsize);
        if (spaces[t] > 0) {
            cend -= spaces[t];
            vim_memset (cend, ' ', (size_t) (spaces [t]));
        }
        mark_col_adjust (curwin -> w_cursor.lnum + t, (colnr_T) 0, (linenr_T) - t, (long) (cend - newp + spaces [t] - (curr - curr_start)));
        if (t == 0)
            break;
        curr = curr_start = ml_get ((linenr_T) (curwin->w_cursor.lnum + t - 1));
        if (remove_comments)
            curr += comments[t - 1];
        if (insert_space && t > 1)
            curr = skipwhite (curr);
        currsize = (int) STRLEN (curr);
    }
    ml_replace (curwin -> w_cursor.lnum, newp, FALSE);
    if (setmark) {
        curwin->w_buffer->b_op_end.lnum = curwin->w_cursor.lnum;
        curwin->w_buffer->b_op_end.col = (colnr_T) STRLEN (newp);
    }
    changed_lines (curwin -> w_cursor.lnum, currsize, curwin -> w_cursor.lnum + 1, 0L);
    t = curwin->w_cursor.lnum;
    ++curwin->w_cursor.lnum;
    del_lines (count - 1, FALSE);
    curwin->w_cursor.lnum = t;
    curwin->w_cursor.col = (vim_strchr (p_cpo, CPO_JOINCOL) != NULL ? currsize : col);
    check_cursor_col ();
    curwin->w_cursor.coladd = 0;
    curwin->w_set_curswant = TRUE;
theend :
    vim_free (spaces);
    if (remove_comments)
        vim_free (comments);
    return ret;
}

char_u *skip_comment (char_u *line, int process, int include_space, int *is_comment) {
    char_u *comment_flags = NULL;
    int lead_len;
    int leader_offset = get_last_leader_offset (line, &comment_flags);
    *is_comment = FALSE;
    if (leader_offset != -1) {
        while (*comment_flags) {
            if (*comment_flags == COM_END || *comment_flags == ':')
                break;
            ++comment_flags;
        }
        if (*comment_flags != COM_END)
            *is_comment = TRUE;
    }
    if (process == FALSE)
        return line;
    lead_len = get_leader_len (line, &comment_flags, FALSE, include_space);
    if (lead_len == 0)
        return line;
    while (*comment_flags) {
        if (*comment_flags == COM_END || *comment_flags == ':') {
            break;
        }
        ++comment_flags;
    }
    if (*comment_flags == ':' || *comment_flags == NUL)
        line += lead_len;
    return line;
}

void do_put (int regname, int dir, long  count, int flags) {
    char_u *ptr;
    char_u *newp, *oldp;
    int yanklen;
    int totlen = 0;
    linenr_T lnum;
    colnr_T col;
    long  i;
    int y_type;
    long  y_size;
    int oldlen;
    long  y_width = 0;
    colnr_T vcol;
    int delcount;
    int incr = 0;
    long  j;
    struct block_def bd;
    char_u **y_array = NULL;
    long  nr_lines = 0;
    pos_T new_cursor;
    int indent;
    int orig_indent = 0;
    int indent_diff = 0;
    int first_indent = TRUE;
    int lendiff = 0;
    pos_T old_pos;
    char_u *insert_string = NULL;
    int allocated = FALSE;
    long  cnt;
    if (flags & PUT_FIXINDENT)
        orig_indent = get_indent ();
    curbuf->b_op_start = curwin->w_cursor;
    curbuf->b_op_end = curwin->w_cursor;
    if (regname == '.') {
        if (VIsual_active)
            stuffcharReadbuff (VIsual_mode);
        (void) stuff_inserted ((dir == FORWARD ? (count == -1 ? 'o' : 'a') : (count == -1 ? 'O' : 'i')), count, FALSE);
        if ((flags & PUT_CURSEND) && gchar_cursor () != NUL)
            stuffcharReadbuff ('l');
        return;
    }
    if (get_spec_reg (regname, &insert_string, &allocated, TRUE)) {
        if (insert_string == NULL)
            return;
    }
    u_save (curwin -> w_cursor.lnum, curwin -> w_cursor.lnum + 1);
    if (insert_string != NULL) {
        y_type = MCHAR;
        if (regname == '=') {
            for (;;) {
                y_size = 0;
                ptr = insert_string;
                while (ptr != NULL) {
                    if (y_array != NULL)
                        y_array[y_size] = ptr;
                    ++y_size;
                    ptr = vim_strchr (ptr, '\n');
                    if (ptr != NULL) {
                        if (y_array != NULL)
                            *ptr = NUL;
                        ++ptr;
                        if (*ptr == NUL) {
                            y_type = MLINE;
                            break;
                        }
                    }
                }
                if (y_array != NULL)
                    break;
                y_array = (char_u **) alloc ((unsigned ) (y_size * sizeof (char_u *)));
                if (y_array == NULL)
                    goto end;
            }
        }
        else {
            y_size = 1;
            y_array = &insert_string;
        }
    }
    else {
        get_yank_register (regname, FALSE);
        y_type = y_current->y_type;
        y_width = y_current->y_width;
        y_size = y_current->y_size;
        y_array = y_current->y_array;
    }
    if (y_type == MLINE) {
        if (flags & PUT_LINE_SPLIT) {
            char_u *p;
            if (u_save_cursor () == FAIL)
                goto end;
            p = ml_get_cursor ();
            if (dir == FORWARD && *p != NUL)
                MB_PTR_ADV (p);
            ptr = vim_strsave (p);
            if (ptr == NULL)
                goto end;
            ml_append (curwin -> w_cursor.lnum, ptr, (colnr_T) 0, FALSE);
            vim_free (ptr);
            oldp = ml_get_curline ();
            p = oldp + curwin->w_cursor.col;
            if (dir == FORWARD && *p != NUL)
                MB_PTR_ADV (p);
            ptr = vim_strnsave (oldp, p -oldp);
            if (ptr == NULL)
                goto end;
            ml_replace (curwin -> w_cursor.lnum, ptr, FALSE);
            ++nr_lines;
            dir = FORWARD;
        }
        if (flags & PUT_LINE_FORWARD) {
            curwin->w_cursor = curbuf->b_visual.vi_end;
            dir = FORWARD;
        }
        curbuf->b_op_start = curwin->w_cursor;
        curbuf->b_op_end = curwin->w_cursor;
    }
    if (flags & PUT_LINE)
        y_type = MLINE;
    if (y_size == 0 || y_array == NULL) {
        EMSG2 (_ ("E353: Nothing in register %s"), regname == 0 ? (char_u *) "\"" : transchar (regname));
        goto end;
    }
    if (y_type == MBLOCK) {
        lnum = curwin->w_cursor.lnum + y_size + 1;
        if (lnum > curbuf->b_ml.ml_line_count)
            lnum = curbuf->b_ml.ml_line_count + 1;
        if (u_save (curwin->w_cursor.lnum - 1, lnum) == FAIL)
            goto end;
    }
    else if (y_type == MLINE) {
        lnum = curwin->w_cursor.lnum;
        if (dir == BACKWARD)
            (void) hasFolding (lnum, &lnum, NULL);
        else
            (void) hasFolding (lnum, NULL, &lnum);
        if (dir == FORWARD)
            ++lnum;
        if ((BUFEMPTY () ? u_save (0, 2) : u_save (lnum -1, lnum)) == FAIL)
            goto end;
        if (dir == FORWARD)
            curwin->w_cursor.lnum = lnum - 1;
        else
            curwin->w_cursor.lnum = lnum;
        curbuf->b_op_start = curwin->w_cursor;
    }
    else if (u_save_cursor () == FAIL)
        goto end;
    yanklen = (int) STRLEN (y_array[0]);
    if (ve_flags == VE_ALL && y_type == MCHAR) {
        if (gchar_cursor () == TAB) {
            if (dir == FORWARD ? (int) curwin->w_cursor.coladd < curbuf->b_p_ts - 1 : curwin->w_cursor.coladd > 0)
                coladvance_force (getviscol ());
            else
                curwin->w_cursor.coladd = 0;
        }
        else if (curwin->w_cursor.coladd > 0 || gchar_cursor () == NUL)
            coladvance_force (getviscol () + (dir == FORWARD));
    }
    lnum = curwin->w_cursor.lnum;
    col = curwin->w_cursor.col;
    if (y_type == MBLOCK) {
        int c = gchar_cursor ();
        colnr_T endcol2 = 0;
        if (dir == FORWARD && c != NUL) {
            if (ve_flags == VE_ALL)
                getvcol (curwin, &curwin->w_cursor, &col, NULL, &endcol2);
            else
                getvcol (curwin, &curwin->w_cursor, NULL, NULL, &col);
            if (c != TAB || ve_flags != VE_ALL)
                ++curwin->w_cursor.col;
            ++col;
        }
        else
            getvcol (curwin, &curwin->w_cursor, &col, NULL, &endcol2);
        col += curwin->w_cursor.coladd;
        if (ve_flags == VE_ALL && (curwin->w_cursor.coladd > 0 || endcol2 == curwin->w_cursor.col)) {
            if (dir == FORWARD && c == NUL)
                ++col;
            if (dir != FORWARD && c != NUL)
                ++curwin->w_cursor.col;
            if (c == TAB) {
                if (dir == BACKWARD && curwin->w_cursor.col)
                    curwin->w_cursor.col--;
                if (dir == FORWARD && col - 1 == endcol2)
                    curwin->w_cursor.col++;
            }
        }
        curwin->w_cursor.coladd = 0;
        bd.textcol = 0;
        for (i = 0; i < y_size; ++i) {
            int spaces;
            char shortline;
            bd.startspaces = 0;
            bd.endspaces = 0;
            vcol = 0;
            delcount = 0;
            if (curwin->w_cursor.lnum > curbuf->b_ml.ml_line_count) {
                if (ml_append (curbuf->b_ml.ml_line_count, (char_u *) "", (colnr_T) 1, FALSE) == FAIL)
                    break;
                ++nr_lines;
            }
            oldp = ml_get_curline ();
            oldlen = (int) STRLEN (oldp);
            for (ptr = oldp; vcol < col && *ptr;) {
                incr = lbr_chartabsize_adv (oldp, &ptr, (colnr_T) vcol);
                vcol += incr;
            }
            bd.textcol = (colnr_T) (ptr - oldp);
            shortline = (vcol < col) || (vcol == col && !*ptr);
            if (vcol < col)
                bd.startspaces = col - vcol;
            else if (vcol > col) {
                bd.endspaces = vcol - col;
                bd.startspaces = incr - bd.endspaces;
                --bd.textcol;
                delcount = 1;
                if (oldp[bd.textcol] != TAB) {
                    delcount = 0;
                    bd.endspaces = 0;
                }
            }
            yanklen = (int) STRLEN (y_array[i]);
            spaces = y_width + 1;
            for (j = 0; j < yanklen; j++)
                spaces -= lbr_chartabsize (NULL, &y_array[i][j], 0);
            if (spaces < 0)
                spaces = 0;
            totlen = count * (yanklen + spaces) + bd.startspaces + bd.endspaces;
            newp = alloc_check ((unsigned ) totlen + oldlen + 1);
            if (newp == NULL)
                break;
            ptr = newp;
            mch_memmove (ptr, oldp, (size_t) bd.textcol);
            ptr += bd.textcol;
            vim_memset (ptr, ' ', (size_t) bd.startspaces);
            ptr += bd.startspaces;
            for (j = 0; j < count; ++j) {
                mch_memmove (ptr, y_array [i], (size_t) yanklen);
                ptr += yanklen;
                if ((j < count - 1 || !shortline) && spaces) {
                    vim_memset (ptr, ' ', (size_t) spaces);
                    ptr += spaces;
                }
            }
            vim_memset (ptr, ' ', (size_t) bd.endspaces);
            ptr += bd.endspaces;
            mch_memmove (ptr, oldp + bd.textcol + delcount, (size_t) (oldlen - bd.textcol - delcount + 1));
            ml_replace (curwin -> w_cursor.lnum, newp, FALSE);
            ++curwin->w_cursor.lnum;
            if (i == 0)
                curwin->w_cursor.col += bd.startspaces;
        }
        changed_lines (lnum, 0, curwin -> w_cursor.lnum, nr_lines);
        curbuf->b_op_start = curwin->w_cursor;
        curbuf->b_op_start.lnum = lnum;
        curbuf->b_op_end.lnum = curwin->w_cursor.lnum - 1;
        curbuf->b_op_end.col = bd.textcol + totlen - 1;
        curbuf->b_op_end.coladd = 0;
        if (flags & PUT_CURSEND) {
            colnr_T len;
            curwin->w_cursor = curbuf->b_op_end;
            curwin->w_cursor.col++;
            len = (colnr_T) STRLEN (ml_get_curline ());
            if (curwin->w_cursor.col > len)
                curwin->w_cursor.col = len;
        }
        else
            curwin->w_cursor.lnum = lnum;
    }
    else {
        if (y_type == MCHAR) {
            if (dir == FORWARD && gchar_cursor () != NUL) {
                {
                    ++col;
                    if (yanklen) {
                        ++curwin->w_cursor.col;
                        ++curbuf->b_op_end.col;
                    }
                }
            }
            curbuf->b_op_start = curwin->w_cursor;
        }
        else if (dir == BACKWARD)
            --lnum;
        new_cursor = curwin->w_cursor;
        if (y_type == MCHAR && y_size == 1) {
            linenr_T end_lnum = 0;
            if (VIsual_active) {
                end_lnum = curbuf->b_visual.vi_end.lnum;
                if (end_lnum < curbuf->b_visual.vi_start.lnum)
                    end_lnum = curbuf->b_visual.vi_start.lnum;
            }
            do {
                totlen = count * yanklen;
                if (totlen > 0) {
                    oldp = ml_get (lnum);
                    if (VIsual_active && col > (int) STRLEN (oldp)) {
                        lnum++;
                        continue;
                    }
                    newp = alloc_check ((unsigned ) (STRLEN (oldp) + totlen + 1));
                    if (newp == NULL)
                        goto end;
                    mch_memmove (newp, oldp, (size_t) col);
                    ptr = newp + col;
                    for (i = 0; i < count; ++i) {
                        mch_memmove (ptr, y_array [0], (size_t) yanklen);
                        ptr += yanklen;
                    }
                    STRMOVE (ptr, oldp + col);
                    ml_replace (lnum, newp, FALSE);
                    if (lnum == curwin->w_cursor.lnum) {
                        changed_cline_bef_curs ();
                        curwin->w_cursor.col += (colnr_T) (totlen - 1);
                    }
                }
                if (VIsual_active)
                    lnum++;
            }
            while (VIsual_active && lnum <= end_lnum);
            if (VIsual_active)
                lnum--;
            curbuf->b_op_end = curwin->w_cursor;
            if (totlen && (restart_edit != 0 || (flags & PUT_CURSEND)))
                ++curwin->w_cursor.col;
            changed_bytes (lnum, col);
        }
        else {
            for (cnt = 1; cnt <= count; ++cnt) {
                i = 0;
                if (y_type == MCHAR) {
                    lnum = new_cursor.lnum;
                    ptr = ml_get (lnum) + col;
                    totlen = (int) STRLEN (y_array[y_size - 1]);
                    newp = alloc_check ((unsigned ) (STRLEN (ptr) + totlen + 1));
                    if (newp == NULL)
                        goto error;
                    STRCPY (newp, y_array [y_size - 1]);
                    STRCAT (newp, ptr);
                    ml_append (lnum, newp, (colnr_T) 0, FALSE);
                    vim_free (newp);
                    oldp = ml_get (lnum);
                    newp = alloc_check ((unsigned ) (col + yanklen + 1));
                    if (newp == NULL)
                        goto error;
                    mch_memmove (newp, oldp, (size_t) col);
                    mch_memmove (newp + col, y_array [0], (size_t) (yanklen + 1));
                    ml_replace (lnum, newp, FALSE);
                    curwin->w_cursor.lnum = lnum;
                    i = 1;
                }
                for (; i < y_size; ++i) {
                    if ((y_type != MCHAR || i < y_size - 1) && ml_append (lnum, y_array[i], (colnr_T) 0, FALSE) == FAIL)
                        goto error;
                    lnum++;
                    ++nr_lines;
                    if (flags & PUT_FIXINDENT) {
                        old_pos = curwin->w_cursor;
                        curwin->w_cursor.lnum = lnum;
                        ptr = ml_get (lnum);
                        if (cnt == count && i == y_size - 1)
                            lendiff = (int) STRLEN (ptr);
                        if (*ptr == '#' && preprocs_left ())
                            indent = 0;
                        else if (*ptr == NUL)
                            indent = 0;
                        else if (first_indent) {
                            indent_diff = orig_indent - get_indent ();
                            indent = orig_indent;
                            first_indent = FALSE;
                        }
                        else if ((indent = get_indent () + indent_diff) < 0)
                            indent = 0;
                        (void) set_indent (indent, 0);
                        curwin->w_cursor = old_pos;
                        if (cnt == count && i == y_size - 1)
                            lendiff -= (int) STRLEN (ml_get (lnum));
                    }
                }
            }
        error :
            if (y_type == MLINE) {
                curbuf->b_op_start.col = 0;
                if (dir == FORWARD)
                    curbuf->b_op_start.lnum++;
            }
            if (curbuf->b_op_start.lnum + (y_type == MCHAR) - 1 + nr_lines < curbuf->b_ml.ml_line_count || curwin->w_p_diff)
                mark_adjust (curbuf->b_op_start.lnum + (y_type == MCHAR), (linenr_T) MAXLNUM, nr_lines, 0L);
            if (y_type == MCHAR)
                changed_lines (curwin->w_cursor.lnum, col, curwin->w_cursor.lnum + 1, nr_lines);
            else
                changed_lines (curbuf->b_op_start.lnum, 0, curbuf->b_op_start.lnum, nr_lines);
            curbuf->b_op_end.lnum = lnum;
            col = (colnr_T) STRLEN (y_array[y_size - 1]) - lendiff;
            if (col > 1)
                curbuf->b_op_end.col = col - 1;
            else
                curbuf->b_op_end.col = 0;
            if (flags & PUT_CURSLINE) {
                curwin->w_cursor.lnum = lnum;
                beginline (BL_WHITE | BL_FIX);
            }
            else if (flags & PUT_CURSEND) {
                if (y_type == MLINE) {
                    if (lnum >= curbuf->b_ml.ml_line_count)
                        curwin->w_cursor.lnum = curbuf->b_ml.ml_line_count;
                    else
                        curwin->w_cursor.lnum = lnum + 1;
                    curwin->w_cursor.col = 0;
                }
                else {
                    curwin->w_cursor.lnum = lnum;
                    curwin->w_cursor.col = col;
                }
            }
            else if (y_type == MLINE) {
                curwin->w_cursor.col = 0;
                if (dir == FORWARD)
                    ++curwin->w_cursor.lnum;
                beginline (BL_WHITE | BL_FIX);
            }
            else
                curwin->w_cursor = new_cursor;
        }
    }
    msgmore (nr_lines);
    curwin->w_set_curswant = TRUE;
end :
    if (allocated)
        vim_free (insert_string);
    if (regname == '=')
        vim_free (y_array);
    VIsual_active = FALSE;
    adjust_cursor_eol ();
}

int preprocs_left (void) {
    return (curbuf->b_p_si && !curbuf->b_p_cin) || (curbuf->b_p_cin && in_cinkeys ('#', ' ', TRUE) && curbuf->b_ind_hash_comment == 0);
}

int insert_reg (int regname, int literally) {
    long  i;
    int retval = OK;
    char_u *arg;
    int allocated;
    ui_breakcheck ();
    if (got_int)
        return FAIL;
    if (regname != NUL && !valid_yank_reg (regname, FALSE))
        return FAIL;
    if (regname == '.')
        retval = stuff_inserted (NUL, 1L, TRUE);
    else if (get_spec_reg (regname, &arg, &allocated, TRUE)) {
        if (arg == NULL)
            return FAIL;
        stuffescaped (arg, literally);
        if (allocated)
            vim_free (arg);
    }
    else {
        get_yank_register (regname, FALSE);
        if (y_current->y_array == NULL)
            retval = FAIL;
        else {
            for (i = 0; i < y_current->y_size; ++i) {
                stuffescaped (y_current -> y_array [i], literally);
                if (y_current->y_type == MLINE || i < y_current->y_size - 1)
                    stuffcharReadbuff ('\n');
            }
        }
    }
    return retval;
}

static void stuffescaped (char_u *arg, int literally) {
    int c;
    char_u *start;
    while (*arg != NUL) {
        start = arg;
        while ((*arg >= ' ' && *arg < DEL) || (*arg == K_SPECIAL && !literally))
            ++arg;
        if (arg > start)
            stuffReadbuffLen (start, (long ) (arg - start));
        if (*arg != NUL) {
            c = *arg++;
            if (literally && ((c < ' ' && c != TAB) || c == DEL))
                stuffcharReadbuff (Ctrl_V);
            stuffcharReadbuff (c);
        }
    }
}

int yank_register_mline (int regname) {
    if (regname != 0 && !valid_yank_reg (regname, FALSE))
        return FALSE;
    if (regname == '_')
        return FALSE;
    get_yank_register (regname, FALSE);
    return (y_current->y_type == MLINE);
}

int cmdline_paste_reg (int regname, int literally, int remcr) {
    long  i;
    get_yank_register (regname, FALSE);
    if (y_current->y_array == NULL)
        return FAIL;
    for (i = 0; i < y_current->y_size; ++i) {
        cmdline_paste_str (y_current -> y_array [i], literally);
        if ((y_current->y_type == MLINE || i < y_current->y_size - 1) && !remcr)
            cmdline_paste_str ((char_u *) "\r", literally);
        ui_breakcheck ();
        if (got_int)
            return FAIL;
    }
    return OK;
}

int op_on_lines (int op) {
    return opchars[op][2];
}

void op_shift (oparg_T *oap, int curs_top, int amount) {
    long  i;
    int first_char;
    char_u *s;
    int block_col = 0;
    if (u_save ((linenr_T) (oap->start.lnum - 1), (linenr_T) (oap->end.lnum + 1)) == FAIL)
        return;
    if (oap->block_mode)
        block_col = curwin->w_cursor.col;
    for (i = oap->line_count; --i >= 0;) {
        first_char = *ml_get_curline ();
        if (first_char == NUL)
            curwin->w_cursor.col = 0;
        else if (oap->block_mode)
            shift_block (oap, amount);
        else if (first_char != '#' || !preprocs_left ()) {
            shift_line (oap -> op_type == OP_LSHIFT, p_sr, amount, FALSE);
        }
        ++curwin->w_cursor.lnum;
    }
    changed_lines (oap -> start.lnum, 0, oap -> end.lnum + 1, 0L);
    if (oap->block_mode) {
        curwin->w_cursor.lnum = oap->start.lnum;
        curwin->w_cursor.col = block_col;
    }
    else if (curs_top) {
        curwin->w_cursor.lnum = oap->start.lnum;
        beginline (BL_SOL | BL_FIX);
    }
    else
        --curwin->w_cursor.lnum;
    foldOpenCursor ();
    if (oap->line_count > p_report) {
        if (oap->op_type == OP_RSHIFT)
            s = (char_u *) ">";
        else
            s = (char_u *) "<";
        if (oap->line_count == 1) {
            if (amount == 1)
                sprintf ((char *) IObuff, _ ("1 line %sed 1 time"), s);
            else
                sprintf ((char *) IObuff, _ ("1 line %sed %d times"), s, amount);
        }
        else {
            if (amount == 1)
                sprintf ((char *) IObuff, _ ("%ld lines %sed 1 time"), oap->line_count, s);
            else
                sprintf ((char *) IObuff, _ ("%ld lines %sed %d times"), oap->line_count, s, amount);
        }
        msg (IObuff);
    }
    curbuf->b_op_start = oap->start;
    curbuf->b_op_end.lnum = oap->end.lnum;
    curbuf->b_op_end.col = (colnr_T) STRLEN (ml_get (oap->end.lnum));
    if (curbuf->b_op_end.col > 0)
        --curbuf->b_op_end.col;
}

static void shift_block (oparg_T *oap, int amount) {
    int left = (oap->op_type == OP_LSHIFT);
    int oldstate = State;
    int total;
    char_u *newp, *oldp;
    int oldcol = curwin->w_cursor.col;
    int p_sw = (int) get_sw_value (curbuf);
    int p_ts = (int) curbuf->b_p_ts;
    struct block_def bd;
    int incr;
    colnr_T ws_vcol;
    int i = 0, j = 0;
    int len;
    int old_p_ri = p_ri;
    p_ri = 0;
    State = INSERT;
    block_prep (oap, & bd, curwin -> w_cursor.lnum, TRUE);
    if (bd.is_short)
        return;
    total = (int) ((unsigned ) amount * (unsigned ) p_sw);
    if ((total / p_sw) != amount)
        return;
    oldp = ml_get_curline ();
    if (!left) {
        total += bd.pre_whitesp;
        ws_vcol = bd.start_vcol - bd.pre_whitesp;
        if (bd.startspaces) {
            ++bd.textstart;
        }
        for (; VIM_ISWHITE (*bd.textstart);) {
            incr = lbr_chartabsize_adv (bd.textstart, &bd.textstart, (colnr_T) (bd.start_vcol));
            total += incr;
            bd.start_vcol += incr;
        }
        if (!curbuf->b_p_et)
            i = ((ws_vcol % p_ts) + total) / p_ts;
        if (i)
            j = ((ws_vcol % p_ts) + total) % p_ts;
        else
            j = total;
        bd.textcol -= bd.pre_whitesp_c - (bd.startspaces != 0);
        len = (int) STRLEN (bd.textstart) + 1;
        newp = alloc_check ((unsigned ) (bd.textcol + i + j + len));
        if (newp == NULL)
            return;
        vim_memset (newp, NUL, (size_t) (bd.textcol + i + j + len));
        mch_memmove (newp, oldp, (size_t) bd.textcol);
        vim_memset (newp + bd.textcol, TAB, (size_t) i);
        vim_memset (newp + bd.textcol + i, ' ', (size_t) j);
        mch_memmove (newp + bd.textcol + i + j, bd.textstart, (size_t) len);
    }
    else {
        colnr_T destination_col;
        char_u *verbatim_copy_end;
        colnr_T verbatim_copy_width;
        unsigned  fill;
        unsigned  new_line_len;
        size_t block_space_width;
        size_t shift_amount;
        char_u *non_white = bd.textstart;
        colnr_T non_white_col;
        if (bd.startspaces)
            MB_PTR_ADV (non_white);
        non_white_col = bd.start_vcol;
        while (VIM_ISWHITE (*non_white)) {
            incr = lbr_chartabsize_adv (bd.textstart, &non_white, non_white_col);
            non_white_col += incr;
        }
        block_space_width = non_white_col - oap->start_vcol;
        shift_amount = (block_space_width < (size_t) total ? block_space_width : (size_t) total);
        destination_col = (colnr_T) (non_white_col - shift_amount);
        verbatim_copy_end = bd.textstart;
        verbatim_copy_width = bd.start_vcol;
        if (bd.startspaces)
            verbatim_copy_width -= bd.start_char_vcols;
        while (verbatim_copy_width < destination_col) {
            char_u *line = verbatim_copy_end;
            incr = lbr_chartabsize (line, verbatim_copy_end, verbatim_copy_width);
            if (verbatim_copy_width + incr > destination_col)
                break;
            verbatim_copy_width += incr;
            MB_PTR_ADV (verbatim_copy_end);
        }
        fill = destination_col - verbatim_copy_width;
        new_line_len = (unsigned ) (verbatim_copy_end - oldp) + fill + (unsigned ) STRLEN (non_white) + 1;
        newp = alloc_check (new_line_len);
        if (newp == NULL)
            return;
        mch_memmove (newp, oldp, (size_t) (verbatim_copy_end - oldp));
        vim_memset (newp + (verbatim_copy_end - oldp), ' ', (size_t) fill);
        STRMOVE (newp + (verbatim_copy_end - oldp) + fill, non_white);
    }
    ml_replace (curwin -> w_cursor.lnum, newp, FALSE);
    changed_bytes (curwin -> w_cursor.lnum, (colnr_T) bd.textcol);
    State = oldstate;
    curwin->w_cursor.col = oldcol;
    p_ri = old_p_ri;
}

static void block_prep (oparg_T *oap, struct block_def *bdp, linenr_T lnum, int is_del) {
    int incr = 0;
    char_u *pend;
    char_u *pstart;
    char_u *line;
    char_u *prev_pstart;
    char_u *prev_pend;
    bdp->startspaces = 0;
    bdp->endspaces = 0;
    bdp->textlen = 0;
    bdp->start_vcol = 0;
    bdp->end_vcol = 0;
    bdp->is_short = FALSE;
    bdp->is_oneChar = FALSE;
    bdp->pre_whitesp = 0;
    bdp->pre_whitesp_c = 0;
    bdp->end_char_vcols = 0;
    bdp->start_char_vcols = 0;
    line = ml_get (lnum);
    pstart = line;
    prev_pstart = line;
    while (bdp->start_vcol < oap->start_vcol && *pstart) {
        incr = lbr_chartabsize (line, pstart, (colnr_T) bdp->start_vcol);
        bdp->start_vcol += incr;
        if (VIM_ISWHITE (*pstart)) {
            bdp->pre_whitesp += incr;
            bdp->pre_whitesp_c++;
        }
        else {
            bdp->pre_whitesp = 0;
            bdp->pre_whitesp_c = 0;
        }
        prev_pstart = pstart;
        MB_PTR_ADV (pstart);
    }
    bdp->start_char_vcols = incr;
    if (bdp->start_vcol < oap->start_vcol) {
        bdp->end_vcol = bdp->start_vcol;
        bdp->is_short = TRUE;
        if (!is_del || oap->op_type == OP_APPEND)
            bdp->endspaces = oap->end_vcol - oap->start_vcol + 1;
    }
    else {
        bdp->startspaces = bdp->start_vcol - oap->start_vcol;
        if (is_del && bdp->startspaces)
            bdp->startspaces = bdp->start_char_vcols - bdp->startspaces;
        pend = pstart;
        bdp->end_vcol = bdp->start_vcol;
        if (bdp->end_vcol > oap->end_vcol) {
            bdp->is_oneChar = TRUE;
            if (oap->op_type == OP_INSERT)
                bdp->endspaces = bdp->start_char_vcols - bdp->startspaces;
            else if (oap->op_type == OP_APPEND) {
                bdp->startspaces += oap->end_vcol - oap->start_vcol + 1;
                bdp->endspaces = bdp->start_char_vcols - bdp->startspaces;
            }
            else {
                bdp->startspaces = oap->end_vcol - oap->start_vcol + 1;
                if (is_del && oap->op_type != OP_LSHIFT) {
                    bdp->startspaces = bdp->start_char_vcols - (bdp->start_vcol - oap->start_vcol);
                    bdp->endspaces = bdp->end_vcol - oap->end_vcol - 1;
                }
            }
        }
        else {
            prev_pend = pend;
            while (bdp->end_vcol <= oap->end_vcol && *pend != NUL) {
                prev_pend = pend;
                incr = lbr_chartabsize_adv (line, &pend, (colnr_T) bdp->end_vcol);
                bdp->end_vcol += incr;
            }
            if (bdp->end_vcol <= oap->end_vcol && (!is_del || oap->op_type == OP_APPEND || oap->op_type == OP_REPLACE)) {
                bdp->is_short = TRUE;
                if (oap->op_type == OP_APPEND || virtual_op)
                    bdp->endspaces = oap->end_vcol - bdp->end_vcol + oap->inclusive;
                else
                    bdp->endspaces = 0;
            }
            else if (bdp->end_vcol > oap->end_vcol) {
                bdp->endspaces = bdp->end_vcol - oap->end_vcol - 1;
                if (!is_del && bdp->endspaces) {
                    bdp->endspaces = incr - bdp->endspaces;
                    if (pend != pstart)
                        pend = prev_pend;
                }
            }
        }
        bdp->end_char_vcols = incr;
        if (is_del && bdp->startspaces)
            pstart = prev_pstart;
        bdp->textlen = (int) (pend - pstart);
    }
    bdp->textcol = (colnr_T) (pstart - line);
    bdp->textstart = pstart;
}

int op_delete (oparg_T *oap) {
    int n;
    linenr_T lnum;
    char_u *ptr;
    char_u *newp, *oldp;
    struct block_def bd;
    linenr_T old_lcount = curbuf->b_ml.ml_line_count;
    int did_yank = FALSE;
    int orig_regname = oap->regname;
    if (curbuf->b_ml.ml_flags & ML_EMPTY)
        return OK;
    if (oap->empty)
        return u_save_cursor ();
    if (!curbuf->b_p_ma) {
        EMSG (_ (e_modifiable));
        return FAIL;
    }
    if (oap->motion_type == MCHAR && !oap->is_VIsual && !oap->block_mode && oap->line_count > 1 && oap->motion_force == NUL && oap->op_type == OP_DELETE) {
        ptr = ml_get (oap->end.lnum) + oap->end.col;
        if (*ptr != NUL)
            ptr += oap->inclusive;
        ptr = skipwhite (ptr);
        if (*ptr == NUL && inindent (0))
            oap->motion_type = MLINE;
    }
    if (oap->motion_type == MCHAR && oap->line_count == 1 && oap->op_type == OP_DELETE && *ml_get (oap->start.lnum) == NUL) {
        if (virtual_op)
            goto setmarks;
        if (vim_strchr (p_cpo, CPO_EMPTYREGION) != NULL)
            beep_flush ();
        return OK;
    }
    if (oap->regname != '_') {
        if (oap->regname != 0) {
            if (!valid_yank_reg (oap->regname, TRUE)) {
                beep_flush ();
                return OK;
            }
            get_yank_register (oap -> regname, TRUE);
            if (op_yank (oap, TRUE, FALSE) == OK)
                did_yank = TRUE;
        }
        if (orig_regname != 0 || oap->motion_type == MLINE || oap->line_count > 1 || oap->use_reg_one) {
            shift_delete_registers ();
            if (op_yank (oap, TRUE, FALSE) == OK)
                did_yank = TRUE;
        }
        if ((oap->regname == 0) && oap->motion_type != MLINE && oap->line_count == 1) {
            oap->regname = '-';
            get_yank_register (oap -> regname, TRUE);
            if (op_yank (oap, TRUE, FALSE) == OK)
                did_yank = TRUE;
            oap->regname = 0;
        }
        if (!did_yank) {
            int msg_silent_save = msg_silent;
            msg_silent = 0;
            n = ask_yesno ((char_u *) _ ("cannot yank; delete anyway"), TRUE);
            msg_silent = msg_silent_save;
            if (n != 'y') {
                EMSG (_ (e_abort));
                return FAIL;
            }
        }
        if (did_yank && has_textyankpost ())
            yank_do_autocmd (oap, y_current);
    }
    if (oap->block_mode) {
        if (u_save ((linenr_T) (oap->start.lnum - 1), (linenr_T) (oap->end.lnum + 1)) == FAIL)
            return FAIL;
        for (lnum = curwin->w_cursor.lnum; lnum <= oap->end.lnum; ++lnum) {
            block_prep (oap, & bd, lnum, TRUE);
            if (bd.textlen == 0)
                continue;
            if (lnum == curwin->w_cursor.lnum) {
                curwin->w_cursor.col = bd.textcol + bd.startspaces;
                curwin->w_cursor.coladd = 0;
            }
            n = bd.textlen - bd.startspaces - bd.endspaces;
            oldp = ml_get (lnum);
            newp = alloc_check ((unsigned ) STRLEN (oldp) + 1 - n);
            if (newp == NULL)
                continue;
            mch_memmove (newp, oldp, (size_t) bd.textcol);
            vim_memset (newp + bd.textcol, ' ', (size_t) (bd.startspaces + bd.endspaces));
            oldp += bd.textcol + bd.textlen;
            STRMOVE (newp + bd.textcol + bd.startspaces + bd.endspaces, oldp);
            ml_replace (lnum, newp, FALSE);
        }
        check_cursor_col ();
        changed_lines (curwin -> w_cursor.lnum, curwin -> w_cursor.col, oap -> end.lnum + 1, 0L);
        oap->line_count = 0;
    }
    else if (oap->motion_type == MLINE) {
        if (oap->op_type == OP_CHANGE) {
            if (oap->line_count > 1) {
                lnum = curwin->w_cursor.lnum;
                ++curwin->w_cursor.lnum;
                del_lines ((long) (oap -> line_count - 1), TRUE);
                curwin->w_cursor.lnum = lnum;
            }
            if (u_save_cursor () == FAIL)
                return FAIL;
            if (curbuf->b_p_ai) {
                beginline (BL_WHITE);
                did_ai = TRUE;
                ai_col = curwin->w_cursor.col;
            }
            else
                beginline (0);
            truncate_line (FALSE);
            if (oap->line_count > 1)
                u_clearline ();
        }
        else {
            del_lines (oap -> line_count, TRUE);
            beginline (BL_WHITE | BL_FIX);
            u_clearline ();
        }
    }
    else {
        if (virtual_op) {
            int endcol = 0;
            if (gchar_pos (&oap->start) == '\t') {
                if (u_save_cursor () == FAIL)
                    return FAIL;
                if (oap->line_count == 1)
                    endcol = getviscol2 (oap->end.col, oap->end.coladd);
                coladvance_force (getviscol2 (oap -> start.col, oap -> start.coladd));
                oap->start = curwin->w_cursor;
                if (oap->line_count == 1) {
                    coladvance (endcol);
                    oap->end.col = curwin->w_cursor.col;
                    oap->end.coladd = curwin->w_cursor.coladd;
                    curwin->w_cursor = oap->start;
                }
            }
            if (gchar_pos (&oap->end) == '\t' && (int) oap->end.coladd < oap->inclusive) {
                if (u_save ((linenr_T) (oap->end.lnum - 1), (linenr_T) (oap->end.lnum + 1)) == FAIL)
                    return FAIL;
                curwin->w_cursor = oap->end;
                coladvance_force (getviscol2 (oap -> end.col, oap -> end.coladd));
                oap->end = curwin->w_cursor;
                curwin->w_cursor = oap->start;
            }
        }
        if (oap->line_count == 1) {
            if (u_save_cursor () == FAIL)
                return FAIL;
            if (vim_strchr (p_cpo, CPO_DOLLAR) != NULL && oap->op_type == OP_CHANGE && oap->end.lnum == curwin->w_cursor.lnum && !oap->is_VIsual)
                display_dollar (oap->end.col - !oap->inclusive);
            n = oap->end.col - oap->start.col + 1 - !oap->inclusive;
            if (virtual_op) {
                char_u *curline = ml_get_curline ();
                int len = (int) STRLEN (curline);
                if (oap->end.coladd != 0 && (int) oap->end.col >= len - 1 && !(oap->start.coladd && (int) oap->end.col >= len - 1))
                    n++;
                if (n == 0 && oap->start.coladd != oap->end.coladd)
                    n = 1;
                if (gchar_cursor () != NUL)
                    curwin->w_cursor.coladd = 0;
            }
            (void) del_bytes ((long ) n, !virtual_op, oap->op_type == OP_DELETE && !oap->is_VIsual);
        }
        else {
            pos_T curpos;
            if (u_save ((linenr_T) (curwin->w_cursor.lnum - 1), (linenr_T) (curwin->w_cursor.lnum + oap->line_count)) == FAIL)
                return FAIL;
            truncate_line (TRUE);
            curpos = curwin->w_cursor;
            ++curwin->w_cursor.lnum;
            del_lines ((long) (oap -> line_count - 2), FALSE);
            n = (oap->end.col + 1 - !oap->inclusive);
            curwin->w_cursor.col = 0;
            (void) del_bytes ((long ) n, !virtual_op, oap->op_type == OP_DELETE && !oap->is_VIsual);
            curwin->w_cursor = curpos;
            (void) do_join (2, FALSE, FALSE, FALSE, FALSE);
        }
    }
    msgmore (curbuf -> b_ml.ml_line_count - old_lcount);
setmarks :
    if (oap->block_mode) {
        curbuf->b_op_end.lnum = oap->end.lnum;
        curbuf->b_op_end.col = oap->start.col;
    }
    else
        curbuf->b_op_end = oap->start;
    curbuf->b_op_start = oap->start;
    return OK;
}

int op_yank (oparg_T *oap, int deleting, int mess) {
    long  y_idx;
    yankreg_T *curr;
    yankreg_T newreg;
    char_u **new_ptr;
    linenr_T lnum;
    long  j;
    int yanktype = oap->motion_type;
    long  yanklines = oap->line_count;
    linenr_T yankendlnum = oap->end.lnum;
    char_u *p;
    char_u *pnew;
    struct block_def bd;
    if (oap->regname != 0 && !valid_yank_reg (oap->regname, TRUE)) {
        beep_flush ();
        return FAIL;
    }
    if (oap->regname == '_')
        return OK;
    if (!deleting)
        get_yank_register (oap->regname, TRUE);
    curr = y_current;
    if (y_append && y_current->y_array != NULL)
        y_current = &newreg;
    else
        free_yank_all ();
    if (oap->motion_type == MCHAR && oap->start.col == 0 && !oap->inclusive && (!oap->is_VIsual || *p_sel == 'o') && !oap->block_mode && oap->end.col == 0 && yanklines > 1) {
        yanktype = MLINE;
        --yankendlnum;
        --yanklines;
    }
    y_current->y_size = yanklines;
    y_current->y_type = yanktype;
    y_current->y_width = 0;
    y_current->y_array = (char_u **) lalloc_clear ((long_u) (sizeof (char_u *) * yanklines), TRUE);
    if (y_current->y_array == NULL) {
        y_current = curr;
        return FAIL;
    }
    y_current->y_time_set = vim_time ();
    y_idx = 0;
    lnum = oap->start.lnum;
    if (oap->block_mode) {
        y_current->y_type = MBLOCK;
        y_current->y_width = oap->end_vcol - oap->start_vcol;
        if (curwin->w_curswant == MAXCOL && y_current->y_width > 0)
            y_current->y_width--;
    }
    for (; lnum <= yankendlnum; lnum++, y_idx++) {
        switch (y_current->y_type) {
        case MBLOCK :
            block_prep (oap, &bd, lnum, FALSE);
            if (yank_copy_line (&bd, y_idx) == FAIL)
                goto fail;
            break;
        case MLINE :
            if ((y_current->y_array[y_idx] = vim_strsave (ml_get (lnum))) == NULL)
                goto fail;
            break;
        case MCHAR :
            {
                colnr_T startcol = 0, endcol = MAXCOL;
                int is_oneChar = FALSE;
                colnr_T cs, ce;
                p = ml_get (lnum);
                bd.startspaces = 0;
                bd.endspaces = 0;
                if (lnum == oap->start.lnum) {
                    startcol = oap->start.col;
                    if (virtual_op) {
                        getvcol (curwin, & oap -> start, & cs, NULL, & ce);
                        if (ce != cs && oap->start.coladd > 0) {
                            bd.startspaces = (ce - cs + 1) - oap->start.coladd;
                            startcol++;
                        }
                    }
                }
                if (lnum == oap->end.lnum) {
                    endcol = oap->end.col;
                    if (virtual_op) {
                        getvcol (curwin, & oap -> end, & cs, NULL, & ce);
                        if (p[endcol] == NUL || (cs + oap->end.coladd < ce)) {
                            if (oap->start.lnum == oap->end.lnum && oap->start.col == oap->end.col) {
                                is_oneChar = TRUE;
                                bd.startspaces = oap->end.coladd - oap->start.coladd + oap->inclusive;
                                endcol = startcol;
                            }
                            else {
                                bd.endspaces = oap->end.coladd + oap->inclusive;
                                endcol -= oap->inclusive;
                            }
                        }
                    }
                }
                if (endcol == MAXCOL)
                    endcol = (colnr_T) STRLEN (p);
                if (startcol > endcol || is_oneChar)
                    bd.textlen = 0;
                else {
                    bd.textlen = endcol - startcol + oap->inclusive;
                }
                bd.textstart = p + startcol;
                if (yank_copy_line (&bd, y_idx) == FAIL)
                    goto fail;
                break;
            }
        }
    }
    if (curr != y_current) {
        new_ptr = (char_u **) lalloc ((long_u) (sizeof (char_u *) * (curr->y_size + y_current->y_size)), TRUE);
        if (new_ptr == NULL)
            goto fail;
        for (j = 0; j < curr->y_size; ++j)
            new_ptr[j] = curr->y_array[j];
        vim_free (curr -> y_array);
        curr->y_array = new_ptr;
        curr->y_time_set = vim_time ();
        if (yanktype == MLINE)
            curr->y_type = MLINE;
        if (curr->y_type == MCHAR && vim_strchr (p_cpo, CPO_REGAPPEND) == NULL) {
            pnew = lalloc ((long_u) (STRLEN (curr->y_array[curr->y_size - 1]) + STRLEN (y_current->y_array[0]) + 1), TRUE);
            if (pnew == NULL) {
                y_idx = y_current->y_size - 1;
                goto fail;
            }
            STRCPY (pnew, curr -> y_array [-- j]);
            STRCAT (pnew, y_current -> y_array [0]);
            vim_free (curr -> y_array [j]);
            vim_free (y_current -> y_array [0]);
            curr->y_array[j++] = pnew;
            y_idx = 1;
        }
        else
            y_idx = 0;
        while (y_idx < y_current->y_size)
            curr->y_array[j++] = y_current->y_array[y_idx++];
        curr->y_size = j;
        vim_free (y_current -> y_array);
        y_current = curr;
    }
    if (curwin->w_p_rnu)
        redraw_later (SOME_VALID);
    if (mess) {
        if (yanktype == MCHAR && !oap->block_mode && yanklines == 1)
            yanklines = 0;
        if (yanklines > p_report) {
            char namebuf [100];
            if (oap->regname == NUL)
                *namebuf = NUL;
            else
                vim_snprintf (namebuf, sizeof (namebuf), _ (" into \"%c"), oap->regname);
            update_topline_redraw ();
            if (yanklines == 1) {
                if (oap->block_mode)
                    smsg ((char_u *) _ ("block of 1 line yanked%s"), namebuf);
                else
                    smsg ((char_u *) _ ("1 line yanked%s"), namebuf);
            }
            else if (oap->block_mode)
                smsg ((char_u *) _ ("block of %ld lines yanked%s"), yanklines, namebuf);
            else
                smsg ((char_u *) _ ("%ld lines yanked%s"), yanklines, namebuf);
        }
    }
    curbuf->b_op_start = oap->start;
    curbuf->b_op_end = oap->end;
    if (yanktype == MLINE && !oap->block_mode) {
        curbuf->b_op_start.col = 0;
        curbuf->b_op_end.col = MAXCOL;
    }
    if (!deleting && has_textyankpost ())
        yank_do_autocmd (oap, y_current);
    return OK;
fail :
    free_yank (y_idx +1);
    y_current = curr;
    return FAIL;
}

static int yank_copy_line (struct block_def *bd, long  y_idx) {
    char_u *pnew;
    if ((pnew = alloc (bd->startspaces + bd->endspaces + bd->textlen + 1)) == NULL)
        return FAIL;
    y_current->y_array[y_idx] = pnew;
    vim_memset (pnew, ' ', (size_t) bd -> startspaces);
    pnew += bd->startspaces;
    mch_memmove (pnew, bd -> textstart, (size_t) bd -> textlen);
    pnew += bd->textlen;
    vim_memset (pnew, ' ', (size_t) bd -> endspaces);
    pnew += bd->endspaces;
    *pnew = NUL;
    return OK;
}

int op_change (oparg_T *oap) {
    colnr_T l;
    int retval;
    long  offset;
    linenr_T linenr;
    long  ins_len;
    long  pre_textlen = 0;
    long  pre_indent = 0;
    char_u *firstline;
    char_u *ins_text, *newp, *oldp;
    struct block_def bd;
    l = oap->start.col;
    if (oap->motion_type == MLINE) {
        l = 0;
        if (!p_paste && curbuf->b_p_si && !curbuf->b_p_cin)
            can_si = TRUE;
    }
    if (curbuf->b_ml.ml_flags & ML_EMPTY) {
        if (u_save_cursor () == FAIL)
            return FALSE;
    }
    else if (op_delete (oap) == FAIL)
        return FALSE;
    if ((l > curwin->w_cursor.col) && !LINEEMPTY (curwin->w_cursor.lnum) && !virtual_op)
        inc_cursor ();
    if (oap->block_mode) {
        if (virtual_op && (curwin->w_cursor.coladd > 0 || gchar_cursor () == NUL))
            coladvance_force (getviscol ());
        firstline = ml_get (oap->start.lnum);
        pre_textlen = (long ) STRLEN (firstline);
        pre_indent = (long ) getwhitecols (firstline);
        bd.textcol = curwin->w_cursor.col;
    }
    if (oap->motion_type == MLINE)
        fix_indent ();
    retval = edit (NUL, FALSE, (linenr_T) 1);
    if (oap->block_mode && oap->start.lnum != oap->end.lnum && !got_int) {
        firstline = ml_get (oap->start.lnum);
        if (bd.textcol > (colnr_T) pre_indent) {
            long  new_indent = (long ) getwhitecols (firstline);
            pre_textlen += new_indent - pre_indent;
            bd.textcol += new_indent - pre_indent;
        }
        ins_len = (long ) STRLEN (firstline) - pre_textlen;
        if (ins_len > 0) {
            if ((ins_text = alloc_check ((unsigned ) (ins_len + 1))) != NULL) {
                vim_strncpy (ins_text, firstline + bd.textcol, (size_t) ins_len);
                for (linenr = oap->start.lnum + 1; linenr <= oap->end.lnum; linenr++) {
                    block_prep (oap, & bd, linenr, TRUE);
                    if (!bd.is_short || virtual_op) {
                        pos_T vpos;
                        if (bd.is_short) {
                            vpos.lnum = linenr;
                            (void) getvpos (&vpos, oap->start_vcol);
                        }
                        else
                            vpos.coladd = 0;
                        oldp = ml_get (linenr);
                        newp = alloc_check ((unsigned ) (STRLEN (oldp) + vpos.coladd + ins_len + 1));
                        if (newp == NULL)
                            continue;
                        mch_memmove (newp, oldp, (size_t) bd.textcol);
                        offset = bd.textcol;
                        vim_memset (newp + offset, ' ', (size_t) vpos.coladd);
                        offset += vpos.coladd;
                        mch_memmove (newp + offset, ins_text, (size_t) ins_len);
                        offset += ins_len;
                        oldp += bd.textcol;
                        STRMOVE (newp + offset, oldp);
                        ml_replace (linenr, newp, FALSE);
                    }
                }
                check_cursor ();
                changed_lines (oap -> start.lnum + 1, 0, oap -> end.lnum + 1, 0L);
            }
            vim_free (ins_text);
        }
    }
    return retval;
}

void op_reindent (oparg_T *oap, int (*how) (void)) {
    long  i;
    char_u *l;
    int amount;
    linenr_T first_changed = 0;
    linenr_T last_changed = 0;
    linenr_T start_lnum = curwin->w_cursor.lnum;
    if (!curbuf->b_p_ma) {
        EMSG (_ (e_modifiable));
        return;
    }
    for (i = oap->line_count; --i >= 0 && !got_int;) {
        if (i > 1 && (i % 50 == 0 || i == oap->line_count - 1) && oap->line_count > p_report)
            smsg ((char_u *) _ ("%ld lines to indent... "), i);
        if (i != oap->line_count - 1 || oap->line_count == 1 || how != get_lisp_indent) {
            l = skipwhite (ml_get_curline ());
            if (*l == NUL)
                amount = 0;
            else
                amount = how ();
            if (amount >= 0 && set_indent (amount, SIN_UNDO)) {
                if (first_changed == 0)
                    first_changed = curwin->w_cursor.lnum;
                last_changed = curwin->w_cursor.lnum;
            }
        }
        ++curwin->w_cursor.lnum;
        curwin->w_cursor.col = 0;
    }
    curwin->w_cursor.lnum = start_lnum;
    beginline (BL_SOL | BL_FIX);
    if (last_changed != 0)
        changed_lines (first_changed, 0, oap->is_VIsual ? start_lnum + oap->line_count : last_changed + 1, 0L);
    else if (oap->is_VIsual)
        redraw_curbuf_later (INVERTED);
    if (oap->line_count > p_report) {
        i = oap->line_count - (i + 1);
        if (i == 1)
            MSG (_ ("1 line indented "));
        else
            smsg ((char_u *) _ ("%ld lines indented "), i);
    }
    curbuf->b_op_start = oap->start;
    curbuf->b_op_end = oap->end;
}

void op_tilde (oparg_T *oap) {
    pos_T pos;
    struct block_def bd;
    int did_change = FALSE;
    if (u_save ((linenr_T) (oap->start.lnum - 1), (linenr_T) (oap->end.lnum + 1)) == FAIL)
        return;
    pos = oap->start;
    if (oap->block_mode) {
        for (; pos.lnum <= oap->end.lnum; ++pos.lnum) {
            int one_change;
            block_prep (oap, & bd, pos.lnum, FALSE);
            pos.col = bd.textcol;
            one_change = swapchars (oap->op_type, &pos, bd.textlen);
            did_change |= one_change;
            if (netbeans_active () && one_change) {
                char_u *ptr = ml_get_buf (curbuf, pos.lnum, FALSE);
                netbeans_removed (curbuf, pos.lnum, bd.textcol, (long) bd.textlen);
                netbeans_inserted (curbuf, pos.lnum, bd.textcol, & ptr [bd.textcol], bd.textlen);
            }
        }
        if (did_change)
            changed_lines (oap->start.lnum, 0, oap->end.lnum + 1, 0L);
    }
    else {
        if (oap->motion_type == MLINE) {
            oap->start.col = 0;
            pos.col = 0;
            oap->end.col = (colnr_T) STRLEN (ml_get (oap->end.lnum));
            if (oap->end.col)
                --oap->end.col;
        }
        else if (!oap->inclusive)
            dec (&(oap->end));
        if (pos.lnum == oap->end.lnum)
            did_change = swapchars (oap->op_type, &pos, oap->end.col - pos.col + 1);
        else
            for (;;) {
                did_change |= swapchars (oap->op_type, &pos, pos.lnum == oap->end.lnum ? oap->end.col + 1 : (int) STRLEN (ml_get_pos (&pos)));
                if (LTOREQ_POS (oap->end, pos) || inc (&pos) == -1)
                    break;
            }
        if (did_change) {
            changed_lines (oap -> start.lnum, oap -> start.col, oap -> end.lnum + 1, 0L);
            if (netbeans_active () && did_change) {
                char_u *ptr;
                int count;
                pos = oap->start;
                while (pos.lnum < oap->end.lnum) {
                    ptr = ml_get_buf (curbuf, pos.lnum, FALSE);
                    count = (int) STRLEN (ptr) - pos.col;
                    netbeans_removed (curbuf, pos.lnum, pos.col, (long) count);
                    netbeans_inserted (curbuf, pos.lnum, pos.col, & ptr [pos.col], count);
                    pos.col = 0;
                    pos.lnum++;
                }
                ptr = ml_get_buf (curbuf, pos.lnum, FALSE);
                count = oap->end.col - pos.col + 1;
                netbeans_removed (curbuf, pos.lnum, pos.col, (long) count);
                netbeans_inserted (curbuf, pos.lnum, pos.col, & ptr [pos.col], count);
            }
        }
    }
    if (!did_change && oap->is_VIsual)
        redraw_curbuf_later (INVERTED);
    curbuf->b_op_start = oap->start;
    curbuf->b_op_end = oap->end;
    if (oap->line_count > p_report) {
        if (oap->line_count == 1)
            MSG (_ ("1 line changed"));
        else
            smsg ((char_u *) _ ("%ld lines changed"), oap->line_count);
    }
}

static int swapchars (int op_type, pos_T *pos, int length) {
    int todo;
    int did_change = 0;
    for (todo = length; todo > 0; --todo) {
        did_change |= swapchar (op_type, pos);
        if (inc (pos) == -1)
            break;
    }
    return did_change;
}

int swapchar (int op_type, pos_T *pos) {
    int c;
    int nc;
    c = gchar_pos (pos);
    if (c >= 0x80 && op_type == OP_ROT13)
        return FALSE;
    nc = c;
    if (MB_ISLOWER (c)) {
        if (op_type == OP_ROT13)
            nc = ROT13 (c, 'a');
        else if (op_type != OP_LOWER)
            nc = MB_TOUPPER (c);
    }
    else if (MB_ISUPPER (c)) {
        if (op_type == OP_ROT13)
            nc = ROT13 (c, 'A');
        else if (op_type != OP_UPPER)
            nc = MB_TOLOWER (c);
    }
    if (nc != c) {
        PCHAR (* pos, nc);
        return TRUE;
    }
    return FALSE;
}

void op_formatexpr (oparg_T *oap) {
    if (oap->is_VIsual)
        redraw_curbuf_later (INVERTED);
    if (fex_format (oap->start.lnum, oap->line_count, NUL) != 0)
        op_format (oap, FALSE);
}

void op_format (oparg_T *oap, int keep_cursor) {
    long  old_line_count = curbuf->b_ml.ml_line_count;
    curwin->w_cursor = oap->cursor_start;
    if (u_save ((linenr_T) (oap->start.lnum - 1), (linenr_T) (oap->end.lnum + 1)) == FAIL)
        return;
    curwin->w_cursor = oap->start;
    if (oap->is_VIsual)
        redraw_curbuf_later (INVERTED);
    curbuf->b_op_start = oap->start;
    if (keep_cursor)
        saved_cursor = oap->cursor_start;
    format_lines (oap -> line_count, keep_cursor);
    if (oap->end_adjusted && curwin->w_cursor.lnum < curbuf->b_ml.ml_line_count)
        ++curwin->w_cursor.lnum;
    beginline (BL_WHITE | BL_FIX);
    old_line_count = curbuf->b_ml.ml_line_count - old_line_count;
    msgmore (old_line_count);
    curbuf->b_op_end = curwin->w_cursor;
    if (keep_cursor) {
        curwin->w_cursor = saved_cursor;
        saved_cursor.lnum = 0;
    }
    if (oap->is_VIsual) {
        win_T *wp;
        FOR_ALL_WINDOWS (wp) {
            if (wp->w_old_cursor_lnum != 0) {
                if (wp->w_old_cursor_lnum > wp->w_old_visual_lnum)
                    wp->w_old_cursor_lnum += old_line_count;
                else
                    wp->w_old_visual_lnum += old_line_count;
            }
        }
    }
}

void op_insert (oparg_T *oap, long  count1) {
    long  ins_len, pre_textlen = 0;
    char_u *firstline, *ins_text;
    colnr_T ind_pre = 0, ind_post;
    struct block_def bd;
    int i;
    pos_T t1;
    bd.is_MAX = (curwin->w_curswant == MAXCOL);
    curwin->w_cursor.lnum = oap->start.lnum;
    update_screen (INVERTED);
    if (oap->block_mode) {
        if (curwin->w_cursor.coladd > 0) {
            int old_ve_flags = ve_flags;
            ve_flags = VE_ALL;
            if (u_save_cursor () == FAIL)
                return;
            coladvance_force (oap -> op_type == OP_APPEND ? oap -> end_vcol + 1 : getviscol ());
            if (oap->op_type == OP_APPEND)
                --curwin->w_cursor.col;
            ve_flags = old_ve_flags;
        }
        block_prep (oap, & bd, oap -> start.lnum, TRUE);
        ind_pre = (colnr_T) getwhitecols_curline ();
        firstline = ml_get (oap->start.lnum) + bd.textcol;
        if (oap->op_type == OP_APPEND)
            firstline += bd.textlen;
        pre_textlen = (long ) STRLEN (firstline);
    }
    if (oap->op_type == OP_APPEND) {
        if (oap->block_mode && curwin->w_cursor.coladd == 0) {
            curwin->w_set_curswant = TRUE;
            while (*ml_get_cursor () != NUL && (curwin->w_cursor.col < bd.textcol + bd.textlen))
                ++curwin->w_cursor.col;
            if (bd.is_short && !bd.is_MAX) {
                if (u_save_cursor () == FAIL)
                    return;
                for (i = 0; i < bd.endspaces; ++i)
                    ins_char (' ');
                bd.textlen += bd.endspaces;
            }
        }
        else {
            curwin->w_cursor = oap->end;
            check_cursor_col ();
            if (!LINEEMPTY (curwin->w_cursor.lnum) && oap->start_vcol != oap->end_vcol)
                inc_cursor ();
        }
    }
    t1 = oap->start;
    (void) edit (NUL, FALSE, (linenr_T) count1);
    if (t1.lnum == curbuf->b_op_start_orig.lnum && LT_POS (curbuf->b_op_start_orig, t1))
        oap->start = curbuf->b_op_start_orig;
    if (curwin->w_cursor.lnum != oap->start.lnum || got_int)
        return;
    if (oap->block_mode) {
        struct block_def bd2;
        ind_post = (colnr_T) getwhitecols_curline ();
        if (curbuf->b_op_start.col > ind_pre && ind_post > ind_pre) {
            bd.textcol += ind_post - ind_pre;
            bd.start_vcol += ind_post - ind_pre;
        }
        if (oap->start.lnum == curbuf->b_op_start_orig.lnum && !bd.is_MAX) {
            if (oap->op_type == OP_INSERT && oap->start.col + oap->start.coladd != curbuf->b_op_start_orig.col + curbuf->b_op_start_orig.coladd) {
                int t = getviscol2 (curbuf->b_op_start_orig.col, curbuf->b_op_start_orig.coladd);
                oap->start.col = curbuf->b_op_start_orig.col;
                pre_textlen -= t - oap->start_vcol;
                oap->start_vcol = t;
            }
            else if (oap->op_type == OP_APPEND && oap->end.col + oap->end.coladd >= curbuf->b_op_start_orig.col + curbuf->b_op_start_orig.coladd) {
                int t = getviscol2 (curbuf->b_op_start_orig.col, curbuf->b_op_start_orig.coladd);
                oap->start.col = curbuf->b_op_start_orig.col;
                pre_textlen += bd.textlen;
                pre_textlen -= t - oap->start_vcol;
                oap->start_vcol = t;
                oap->op_type = OP_INSERT;
            }
        }
        block_prep (oap, & bd2, oap -> start.lnum, TRUE);
        if (!bd.is_MAX || bd2.textlen < bd.textlen) {
            if (oap->op_type == OP_APPEND) {
                pre_textlen += bd2.textlen - bd.textlen;
                if (bd2.endspaces)
                    --bd2.textlen;
            }
            bd.textcol = bd2.textcol;
            bd.textlen = bd2.textlen;
        }
        firstline = ml_get (oap->start.lnum) + bd.textcol;
        if (oap->op_type == OP_APPEND)
            firstline += bd.textlen;
        if (pre_textlen >= 0 && (ins_len = (long ) STRLEN (firstline) - pre_textlen) > 0) {
            ins_text = vim_strnsave (firstline, (int) ins_len);
            if (ins_text != NULL) {
                if (u_save (oap->start.lnum, (linenr_T) (oap->end.lnum + 1)) == OK)
                    block_insert (oap, ins_text, (oap->op_type == OP_INSERT), &bd);
                curwin->w_cursor.col = oap->start.col;
                check_cursor ();
                vim_free (ins_text);
            }
        }
    }
}

static void block_insert (oparg_T *oap, char_u *s, int b_insert, struct block_def *bdp) {
    int p_ts;
    int count = 0;
    int spaces = 0;
    colnr_T offset;
    unsigned  s_len;
    char_u *newp, *oldp;
    linenr_T lnum;
    int oldstate = State;
    State = INSERT;
    s_len = (unsigned ) STRLEN (s);
    for (lnum = oap->start.lnum + 1; lnum <= oap->end.lnum; lnum++) {
        block_prep (oap, bdp, lnum, TRUE);
        if (bdp->is_short && b_insert)
            continue;
        oldp = ml_get (lnum);
        if (b_insert) {
            p_ts = bdp->start_char_vcols;
            spaces = bdp->startspaces;
            if (spaces != 0)
                count = p_ts - 1;
            offset = bdp->textcol;
        }
        else {
            p_ts = bdp->end_char_vcols;
            if (!bdp->is_short) {
                spaces = (bdp->endspaces ? p_ts - bdp->endspaces : 0);
                if (spaces != 0)
                    count = p_ts - 1;
                offset = bdp->textcol + bdp->textlen - (spaces != 0);
            }
            else {
                if (!bdp->is_MAX)
                    spaces = (oap->end_vcol - bdp->end_vcol) + 1;
                count = spaces;
                offset = bdp->textcol + bdp->textlen;
            }
        }
        newp = alloc_check ((unsigned ) (STRLEN (oldp)) +s_len + count + 1);
        if (newp == NULL)
            continue;
        mch_memmove (newp, oldp, (size_t) (offset));
        oldp += offset;
        vim_memset (newp + offset, ' ', (size_t) spaces);
        mch_memmove (newp + offset + spaces, s, (size_t) s_len);
        offset += s_len;
        if (spaces && !bdp->is_short) {
            vim_memset (newp + offset + spaces, ' ', (size_t) (p_ts - spaces));
            oldp++;
            count++;
        }
        if (spaces > 0)
            offset += count;
        STRMOVE (newp + offset, oldp);
        ml_replace (lnum, newp, FALSE);
        if (lnum == oap->end.lnum) {
            curbuf->b_op_end.lnum = oap->end.lnum;
            curbuf->b_op_end.col = offset;
        }
    }
    changed_lines (oap -> start.lnum + 1, 0, oap -> end.lnum + 1, 0L);
    State = oldstate;
}

int op_replace (oparg_T *oap, int c) {
    int n, numc;
    char_u *newp, *oldp;
    size_t oldlen;
    struct block_def bd;
    char_u *after_p = NULL;
    int had_ctrl_v_cr = FALSE;
    if ((curbuf->b_ml.ml_flags & ML_EMPTY) || oap->empty)
        return OK;
    if (c == REPLACE_CR_NCHAR) {
        had_ctrl_v_cr = TRUE;
        c = CAR;
    }
    else if (c == REPLACE_NL_NCHAR) {
        had_ctrl_v_cr = TRUE;
        c = NL;
    }
    if (u_save ((linenr_T) (oap->start.lnum - 1), (linenr_T) (oap->end.lnum + 1)) == FAIL)
        return FAIL;
    if (oap->block_mode) {
        bd.is_MAX = (curwin->w_curswant == MAXCOL);
        for (; curwin->w_cursor.lnum <= oap->end.lnum; ++curwin->w_cursor.lnum) {
            curwin->w_cursor.col = 0;
            block_prep (oap, & bd, curwin -> w_cursor.lnum, TRUE);
            if (bd.textlen == 0 && (!virtual_op || bd.is_MAX))
                continue;
            if (virtual_op && bd.is_short && *bd.textstart == NUL) {
                pos_T vpos;
                vpos.lnum = curwin->w_cursor.lnum;
                getvpos (& vpos, oap -> start_vcol);
                bd.startspaces += vpos.coladd;
                n = bd.startspaces;
            }
            else
                n = (bd.startspaces ? bd.start_char_vcols - 1 : 0);
            n += (bd.endspaces && !bd.is_oneChar && bd.end_char_vcols > 0) ? bd.end_char_vcols - 1 : 0;
            numc = oap->end_vcol - oap->start_vcol + 1;
            if (bd.is_short && (!virtual_op || bd.is_MAX))
                numc -= (oap->end_vcol - bd.end_vcol) + 1;
            n += numc - bd.textlen;
            oldp = ml_get_curline ();
            oldlen = STRLEN (oldp);
            newp = alloc_check ((unsigned ) oldlen + 1 + n);
            if (newp == NULL)
                continue;
            vim_memset (newp, NUL, (size_t) (oldlen + 1 + n));
            mch_memmove (newp, oldp, (size_t) bd.textcol);
            oldp += bd.textcol + bd.textlen;
            vim_memset (newp + bd.textcol, ' ', (size_t) bd.startspaces);
            if (had_ctrl_v_cr || (c != '\r' && c != '\n')) {
                vim_memset (newp + STRLEN (newp), c, (size_t) numc);
                if (!bd.is_short) {
                    vim_memset (newp + STRLEN (newp), ' ', (size_t) bd.endspaces);
                    STRMOVE (newp + STRLEN (newp), oldp);
                }
            }
            else {
                after_p = alloc_check ((unsigned ) (oldlen + 1 + n - STRLEN (newp)));
                if (after_p != NULL)
                    STRMOVE (after_p, oldp);
            }
            ml_replace (curwin -> w_cursor.lnum, newp, FALSE);
            if (after_p != NULL) {
                ml_append (curwin -> w_cursor.lnum ++, after_p, 0, FALSE);
                appended_lines_mark (curwin -> w_cursor.lnum, 1L);
                oap->end.lnum++;
                vim_free (after_p);
            }
        }
    }
    else {
        if (oap->motion_type == MLINE) {
            oap->start.col = 0;
            curwin->w_cursor.col = 0;
            oap->end.col = (colnr_T) STRLEN (ml_get (oap->end.lnum));
            if (oap->end.col)
                --oap->end.col;
        }
        else if (!oap->inclusive)
            dec (&(oap->end));
        while (LTOREQ_POS (curwin->w_cursor, oap->end)) {
            n = gchar_cursor ();
            if (n != NUL) {
                {
                    if (n == TAB) {
                        int end_vcol = 0;
                        if (curwin->w_cursor.lnum == oap->end.lnum) {
                            end_vcol = getviscol2 (oap->end.col, oap->end.coladd);
                        }
                        coladvance_force (getviscol ());
                        if (curwin->w_cursor.lnum == oap->end.lnum)
                            getvpos (&oap->end, end_vcol);
                    }
                    PCHAR (curwin -> w_cursor, c);
                }
            }
            else if (virtual_op && curwin->w_cursor.lnum == oap->end.lnum) {
                int virtcols = oap->end.coladd;
                if (curwin->w_cursor.lnum == oap->start.lnum && oap->start.col == oap->end.col && oap->start.coladd)
                    virtcols -= oap->start.coladd;
                coladvance_force (getviscol2 (oap -> end.col, oap -> end.coladd) + 1);
                curwin->w_cursor.col -= (virtcols + 1);
                for (; virtcols >= 0; virtcols--) {
                    PCHAR (curwin -> w_cursor, c);
                    if (inc (&curwin->w_cursor) == -1)
                        break;
                }
            }
            if (inc_cursor () == -1)
                break;
        }
    }
    curwin->w_cursor = oap->start;
    check_cursor ();
    changed_lines (oap -> start.lnum, oap -> start.col, oap -> end.lnum + 1, 0L);
    curbuf->b_op_start = oap->start;
    curbuf->b_op_end = oap->end;
    return OK;
}

