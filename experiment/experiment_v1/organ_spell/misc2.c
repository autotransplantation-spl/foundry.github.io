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
struct ff_search_ctx_T {
    ff_stack_T *ffsc_stack_ptr;
    ff_visited_list_hdr_T *ffsc_visited_list;
    ff_visited_list_hdr_T *ffsc_dir_visited_list;
    ff_visited_list_hdr_T *ffsc_visited_lists_list;
    ff_visited_list_hdr_T *ffsc_dir_visited_lists_list;
    char_u *ffsc_file_to_search;
    char_u *ffsc_start_dir;
    char_u *ffsc_fix_path;
    char_u *ffsc_wc_path;
    int ffsc_level;
    char_u **ffsc_stopdirs_v;
    int ffsc_find_what;
    int ffsc_tagfile;
};
struct ff_visited_list_hdr {
    struct ff_visited_list_hdr *ffvl_next;
    char_u *ffvl_filename;
    ff_visited_T *ffvl_visited_list;
};
struct ff_visited {
    struct ff_visited *ffv_next;
    char_u *ffv_wc_path;
    int ffv_dev_valid;
    dev_t ffv_dev;
    ino_t ffv_ino;
    char_u ffv_fname [1];
};
struct ff_stack {
    struct ff_stack *ffs_prev;
    char_u *ffs_fix_path;
    char_u *ffs_wc_path;
    char_u **ffs_filearray;
    int ffs_filearray_size;
    char_u ffs_filearray_cur;
    int ffs_stage;
    int ffs_level;
    int ffs_star_star_empty;
};
struct mousetable {
    int pseudo_code;
    int button;
    int is_click;
    int is_drag;
};
struct key_name_entry {
    int key;
    char_u *name;
};
struct modmasktable {
    short  mod_mask;
    short  mod_flag;
    char_u name;
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
struct growarray {
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    int ga_growsize;
    void *ga_data;
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
struct msglist {
    char_u *msg;
    char_u *throw_msg;
    struct msglist *next;
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
struct filemark {
    pos_T mark;
    int fnum;
};
struct vim_exception {
    except_type_T type;
    char_u *value;
    struct msglist *messages;
    char_u *throw_name;
    linenr_T throw_lnum;
    except_T *caught;
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
struct argentry {
    char_u *ae_fname;
    int ae_fnum;
};
struct cleanup_stuff {
    int pending;
    except_T *exception;
};
struct xfilemark {
    fmark_T fmark;
    char_u *fname;
    time_T time_set;
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
EXTERN char_u *p_sxe;
EXTERN char_u *p_sxq;
EXTERN long  p_verbose;
EXTERN char_u *p_sh;
EXTERN char_u *p_ffs;
EXTERN long  p_siso;
EXTERN char_u *NameBuff;
char_u *ff_file_to_find = NULL;
EXTERN char_u *p_path;
EXTERN char_u *p_sel;
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u *p_titlestring;
EXTERN char_u *globaldir INIT (= NULL);
EXTERN char_u e_toomanyarg [] INIT (= N_ ("E118: Too many arguments for function: %s"));
EXTERN char_u e_argreq [] INIT (= N_ ("E471: Argument required"));
EXTERN char_u e_shellempty [] INIT (= N_ ("E91: 'shell' option is empty"));
EXTERN char_u e_endfor [] INIT (= N_ ("E170: Missing :endfor"));
EXTERN char_u e_endwhile [] INIT (= N_ ("E170: Missing :endwhile"));
EXTERN char_u e_endtry [] INIT (= N_ ("E600: Missing :endtry"));
EXTERN char_u e_endif [] INIT (= N_ ("E171: Missing :endif"));
EXTERN char_u *empty_option INIT (= (char_u *) "");
EXTERN char_u e_listreq [] INIT (= N_ ("E714: List required"));
EXTERN alist_T global_alist;
char_u e_pathtoolong [] = N_ ("E854: path too long for completion");
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
struct mousetable mouse_table [] = {{(int) KE_LEFTMOUSE, MOUSE_LEFT, TRUE, FALSE}, {(int) KE_LEFTMOUSE_NM, MOUSE_LEFT, TRUE, FALSE}, {(int) KE_LEFTDRAG, MOUSE_LEFT, FALSE, TRUE}, {(int) KE_LEFTRELEASE, MOUSE_LEFT, FALSE, FALSE}, {(int) KE_LEFTRELEASE_NM, MOUSE_LEFT, FALSE, FALSE}, {(int) KE_MIDDLEMOUSE, MOUSE_MIDDLE, TRUE, FALSE}, {(int) KE_MIDDLEDRAG, MOUSE_MIDDLE, FALSE, TRUE}, {(int) KE_MIDDLERELEASE, MOUSE_MIDDLE, FALSE, FALSE}, {(int) KE_RIGHTMOUSE, MOUSE_RIGHT, TRUE, FALSE}, {(int) KE_RIGHTDRAG, MOUSE_RIGHT, FALSE, TRUE}, {(int) KE_RIGHTRELEASE, MOUSE_RIGHT, FALSE, FALSE}, {(int) KE_X1MOUSE, MOUSE_X1, TRUE, FALSE}, {(int) KE_X1DRAG, MOUSE_X1, FALSE, TRUE}, {(int) KE_X1RELEASE, MOUSE_X1, FALSE, FALSE}, {(int) KE_X2MOUSE, MOUSE_X2, TRUE, FALSE}, {(int) KE_X2DRAG, MOUSE_X2, FALSE, TRUE}, {(int) KE_X2RELEASE, MOUSE_X2, FALSE, FALSE}, {(int) KE_MOUSEMOVE, MOUSE_RELEASE, FALSE, TRUE}, {(int) KE_IGNORE, MOUSE_RELEASE, FALSE, FALSE}, {0, 0, 0, 0},};
EXTERN char_u e_emptykey [] INIT (= N_ ("E713: Cannot use empty key for Dictionary"));
EXTERN int p_altkeymap;
char_u modifier_keys_table [] = {MOD_MASK_SHIFT, '&', '9', '@', '1', MOD_MASK_SHIFT, '&', '0', '@', '2', MOD_MASK_SHIFT, '*', '1', '@', '4', MOD_MASK_SHIFT, '*', '2', '@', '5', MOD_MASK_SHIFT, '*', '3', '@', '6', MOD_MASK_SHIFT, '*', '4', 'k', 'D', MOD_MASK_SHIFT, '*', '5', 'k', 'L', MOD_MASK_SHIFT, '*', '7', '@', '7', MOD_MASK_CTRL, KS_EXTRA, (int) KE_C_END, '@', '7', MOD_MASK_SHIFT, '*', '9', '@', '9', MOD_MASK_SHIFT, '*', '0', '@', '0', MOD_MASK_SHIFT, '#', '1', '%', '1', MOD_MASK_SHIFT, '#', '2', 'k', 'h', MOD_MASK_CTRL, KS_EXTRA, (int) KE_C_HOME, 'k', 'h', MOD_MASK_SHIFT, '#', '3', 'k', 'I', MOD_MASK_SHIFT, '#', '4', 'k', 'l', MOD_MASK_CTRL, KS_EXTRA, (int) KE_C_LEFT, 'k', 'l', MOD_MASK_SHIFT, '%', 'a', '%', '3', MOD_MASK_SHIFT, '%', 'b', '%', '4', MOD_MASK_SHIFT, '%', 'c', '%', '5', MOD_MASK_SHIFT, '%', 'd', '%', '7', MOD_MASK_SHIFT, '%', 'e', '%', '8', MOD_MASK_SHIFT, '%', 'f', '%', '9', MOD_MASK_SHIFT, '%', 'g', '%', '0', MOD_MASK_SHIFT, '%', 'h', '&', '3', MOD_MASK_SHIFT, '%', 'i', 'k', 'r', MOD_MASK_CTRL, KS_EXTRA, (int) KE_C_RIGHT, 'k', 'r', MOD_MASK_SHIFT, '%', 'j', '&', '5', MOD_MASK_SHIFT, '!', '1', '&', '6', MOD_MASK_SHIFT, '!', '2', '&', '7', MOD_MASK_SHIFT, '!', '3', '&', '8', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_UP, 'k', 'u', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_DOWN, 'k', 'd', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_XF1, KS_EXTRA, (int) KE_XF1, MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_XF2, KS_EXTRA, (int) KE_XF2, MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_XF3, KS_EXTRA, (int) KE_XF3, MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_XF4, KS_EXTRA, (int) KE_XF4, MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F1, 'k', '1', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F2, 'k', '2', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F3, 'k', '3', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F4, 'k', '4', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F5, 'k', '5', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F6, 'k', '6', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F7, 'k', '7', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F8, 'k', '8', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F9, 'k', '9', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F10, 'k', ';', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F11, 'F', '1', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F12, 'F', '2', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F13, 'F', '3', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F14, 'F', '4', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F15, 'F', '5', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F16, 'F', '6', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F17, 'F', '7', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F18, 'F', '8', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F19, 'F', '9', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F20, 'F', 'A', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F21, 'F', 'B', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F22, 'F', 'C', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F23, 'F', 'D', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F24, 'F', 'E', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F25, 'F', 'F', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F26, 'F', 'G', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F27, 'F', 'H', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F28, 'F', 'I', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F29, 'F', 'J', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F30, 'F', 'K', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F31, 'F', 'L', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F32, 'F', 'M', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F33, 'F', 'N', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F34, 'F', 'O', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F35, 'F', 'P', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F36, 'F', 'Q', MOD_MASK_SHIFT, KS_EXTRA, (int) KE_S_F37, 'F', 'R', MOD_MASK_SHIFT, 'k', 'B', KS_EXTRA, (int) KE_TAB, NUL};
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
struct key_name_entry key_names_table [] = {{' ', (char_u *) "Space"}, {TAB, (char_u *) "Tab"}, {K_TAB, (char_u *) "Tab"}, {NL, (char_u *) "NL"}, {NL, (char_u *) "NewLine"}, {NL, (char_u *) "LineFeed"}, {NL, (char_u *) "LF"}, {CAR, (char_u *) "CR"}, {CAR, (char_u *) "Return"}, {CAR, (char_u *) "Enter"}, {K_BS, (char_u *) "BS"}, {K_BS, (char_u *) "BackSpace"}, {ESC, (char_u *) "Esc"}, {CSI, (char_u *) "CSI"}, {K_CSI, (char_u *) "xCSI"}, {'|', (char_u *) "Bar"}, {'\\', (char_u *) "Bslash"}, {K_DEL, (char_u *) "Del"}, {K_DEL, (char_u *) "Delete"}, {K_KDEL, (char_u *) "kDel"}, {K_UP, (char_u *) "Up"}, {K_DOWN, (char_u *) "Down"}, {K_LEFT, (char_u *) "Left"}, {K_RIGHT, (char_u *) "Right"}, {K_XUP, (char_u *) "xUp"}, {K_XDOWN, (char_u *) "xDown"}, {K_XLEFT, (char_u *) "xLeft"}, {K_XRIGHT, (char_u *) "xRight"}, {K_PS, (char_u *) "PasteStart"}, {K_PE, (char_u *) "PasteEnd"}, {K_F1, (char_u *) "F1"}, {K_F2, (char_u *) "F2"}, {K_F3, (char_u *) "F3"}, {K_F4, (char_u *) "F4"}, {K_F5, (char_u *) "F5"}, {K_F6, (char_u *) "F6"}, {K_F7, (char_u *) "F7"}, {K_F8, (char_u *) "F8"}, {K_F9, (char_u *) "F9"}, {K_F10, (char_u *) "F10"}, {K_F11, (char_u *) "F11"}, {K_F12, (char_u *) "F12"}, {K_F13, (char_u *) "F13"}, {K_F14, (char_u *) "F14"}, {K_F15, (char_u *) "F15"}, {K_F16, (char_u *) "F16"}, {K_F17, (char_u *) "F17"}, {K_F18, (char_u *) "F18"}, {K_F19, (char_u *) "F19"}, {K_F20, (char_u *) "F20"}, {K_F21, (char_u *) "F21"}, {K_F22, (char_u *) "F22"}, {K_F23, (char_u *) "F23"}, {K_F24, (char_u *) "F24"}, {K_F25, (char_u *) "F25"}, {K_F26, (char_u *) "F26"}, {K_F27, (char_u *) "F27"}, {K_F28, (char_u *) "F28"}, {K_F29, (char_u *) "F29"}, {K_F30, (char_u *) "F30"}, {K_F31, (char_u *) "F31"}, {K_F32, (char_u *) "F32"}, {K_F33, (char_u *) "F33"}, {K_F34, (char_u *) "F34"}, {K_F35, (char_u *) "F35"}, {K_F36, (char_u *) "F36"}, {K_F37, (char_u *) "F37"}, {K_XF1, (char_u *) "xF1"}, {K_XF2, (char_u *) "xF2"}, {K_XF3, (char_u *) "xF3"}, {K_XF4, (char_u *) "xF4"}, {K_HELP, (char_u *) "Help"}, {K_UNDO, (char_u *) "Undo"}, {K_INS, (char_u *) "Insert"}, {K_INS, (char_u *) "Ins"}, {K_KINS, (char_u *) "kInsert"}, {K_HOME, (char_u *) "Home"}, {K_KHOME, (char_u *) "kHome"}, {K_XHOME, (char_u *) "xHome"}, {K_ZHOME, (char_u *) "zHome"}, {K_END, (char_u *) "End"}, {K_KEND, (char_u *) "kEnd"}, {K_XEND, (char_u *) "xEnd"}, {K_ZEND, (char_u *) "zEnd"}, {K_PAGEUP, (char_u *) "PageUp"}, {K_PAGEDOWN, (char_u *) "PageDown"}, {K_KPAGEUP, (char_u *) "kPageUp"}, {K_KPAGEDOWN, (char_u *) "kPageDown"}, {K_KPLUS, (char_u *) "kPlus"}, {K_KMINUS, (char_u *) "kMinus"}, {K_KDIVIDE, (char_u *) "kDivide"}, {K_KMULTIPLY, (char_u *) "kMultiply"}, {K_KENTER, (char_u *) "kEnter"}, {K_KPOINT, (char_u *) "kPoint"}, {K_K0, (char_u *) "k0"}, {K_K1, (char_u *) "k1"}, {K_K2, (char_u *) "k2"}, {K_K3, (char_u *) "k3"}, {K_K4, (char_u *) "k4"}, {K_K5, (char_u *) "k5"}, {K_K6, (char_u *) "k6"}, {K_K7, (char_u *) "k7"}, {K_K8, (char_u *) "k8"}, {K_K9, (char_u *) "k9"}, {'<', (char_u *) "lt"}, {K_MOUSE, (char_u *) "Mouse"}, {K_NETTERM_MOUSE, (char_u *) "NetMouse"}, {K_DEC_MOUSE, (char_u *) "DecMouse"}, {K_URXVT_MOUSE, (char_u *) "UrxvtMouse"}, {K_SGR_MOUSE, (char_u *) "SgrMouse"}, {K_SGR_MOUSERELEASE, (char_u *) "SgrMouseRelelase"}, {K_LEFTMOUSE, (char_u *) "LeftMouse"}, {K_LEFTMOUSE_NM, (char_u *) "LeftMouseNM"}, {K_LEFTDRAG, (char_u *) "LeftDrag"}, {K_LEFTRELEASE, (char_u *) "LeftRelease"}, {K_LEFTRELEASE_NM, (char_u *) "LeftReleaseNM"}, {K_MOUSEMOVE, (char_u *) "MouseMove"}, {K_MIDDLEMOUSE, (char_u *) "MiddleMouse"}, {K_MIDDLEDRAG, (char_u *) "MiddleDrag"}, {K_MIDDLERELEASE, (char_u *) "MiddleRelease"}, {K_RIGHTMOUSE, (char_u *) "RightMouse"}, {K_RIGHTDRAG, (char_u *) "RightDrag"}, {K_RIGHTRELEASE, (char_u *) "RightRelease"}, {K_MOUSEDOWN, (char_u *) "ScrollWheelUp"}, {K_MOUSEUP, (char_u *) "ScrollWheelDown"}, {K_MOUSELEFT, (char_u *) "ScrollWheelRight"}, {K_MOUSERIGHT, (char_u *) "ScrollWheelLeft"}, {K_MOUSEDOWN, (char_u *) "MouseDown"}, {K_MOUSEUP, (char_u *) "MouseUp"}, {K_X1MOUSE, (char_u *) "X1Mouse"}, {K_X1DRAG, (char_u *) "X1Drag"}, {K_X1RELEASE, (char_u *) "X1Release"}, {K_X2MOUSE, (
  char_u *) "X2Mouse"}, {K_X2DRAG, (char_u *) "X2Drag"}, {K_X2RELEASE, (char_u *) "X2Release"}, {K_DROP, (char_u *) "Drop"}, {K_ZERO, (char_u *) "Nul"}, {K_SNR, (char_u *) "SNR"}, {K_PLUG, (char_u *) "Plug"}, {K_CURSORHOLD, (char_u *) "CursorHold"}, {K_SWIPELEFT, (char_u *) "SwipeLeft"}, {K_SWIPERIGHT, (char_u *) "SwipeRight"}, {K_SWIPEUP, (char_u *) "SwipeUp"}, {K_SWIPEDOWN, (char_u *) "SwipeDown"}, {0, NULL}};
struct modmasktable mod_mask_table [] = {{MOD_MASK_ALT, MOD_MASK_ALT, (char_u) 'M'}, {MOD_MASK_META, MOD_MASK_META, (char_u) 'T'}, {MOD_MASK_CTRL, MOD_MASK_CTRL, (char_u) 'C'}, {MOD_MASK_SHIFT, MOD_MASK_SHIFT, (char_u) 'S'}, {MOD_MASK_MULTI_CLICK, MOD_MASK_2CLICK, (char_u) '2'}, {MOD_MASK_MULTI_CLICK, MOD_MASK_3CLICK, (char_u) '3'}, {MOD_MASK_MULTI_CLICK, MOD_MASK_4CLICK, (char_u) '4'}, {MOD_MASK_CMD, MOD_MASK_CMD, (char_u) 'D'}, {MOD_MASK_ALT, MOD_MASK_ALT, (char_u) 'A'}, {0, 0, NUL}};
char_u *username = NULL;
EXTERN char_u e_prev_dir [] INIT (= N_ ("E459: Cannot go back to previous directory"));
EXTERN char_u e_noprevre [] INIT (= N_ ("E35: No previous regular expression"));
EXTERN char_u e_noprev [] INIT (= N_ ("E34: No previous command"));
EXTERN win_T *prevwin INIT (= NULL);
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
void *fdip_search_ctx = NULL;
EXTERN proftime_T bevalexpr_due;
EXTERN char_u e_invexpr2 [] INIT (= N_ ("E15: Invalid expression: %s"));
EXTERN char_u *p_pexpr;
EXTERN char_u *p_bexpr;
EXTERN int arrow_used;
EXTERN int mouse_row;
EXTERN int cmdline_row;
EXTERN char need_key_msg [] INIT (= N_ ("Need encryption key for \"%s\""));
EXTERN char bot_top_msg [] INIT (= N_ ("search hit BOTTOM, continuing at TOP"));
EXTERN char top_bot_msg [] INIT (= N_ ("search hit TOP, continuing at BOTTOM"));
EXTERN char_u no_lines_msg [] INIT (= N_ ("--No lines in buffer--"));
EXTERN struct msglist **msg_list INIT (= NULL);
EXTERN int called_emsg;
EXTERN char_u *keep_msg INIT (= NULL);
EXTERN int msg_scrolled;
EXTERN int msg_row;
EXTERN char_u e_invargval [] INIT (= N_ ("E475: Invalid value for argument %s"));
EXTERN unsigned  swb_flags;
EXTERN time_T starttime;
EXTERN int stop_insert_mode;
EXTERN pos_T where_paste_started;
EXTERN char *font_argument INIT (= NULL);
EXTERN int p_guipty;
EXTERN char_u *p_guifont;
EXTERN char_u e_umark [] INIT (= N_ ("E78: Unknown mark"));
EXTERN char_u e_marknotset [] INIT (= N_ ("E20: Mark not set"));
EXTERN char_u e_markinval [] INIT (= N_ ("E19: Mark has invalid line number"));
EXTERN long_u scrollbar_value;
EXTERN except_T *caught_stack INIT (= NULL);
const unsigned  char cmdidxs2 [26] [26] = {{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 6, 0, 0, 0, 7, 15, 0, 16, 0, 0, 0, 0, 0}, {2, 0, 0, 4, 5, 7, 0, 0, 0, 0, 0, 8, 9, 10, 11, 12, 0, 13, 0, 0, 0, 0, 22, 0, 0, 0}, {3, 10, 12, 14, 16, 18, 21, 0, 0, 0, 0, 29, 33, 36, 42, 51, 53, 54, 55, 0, 57, 0, 60, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 6, 15, 0, 16, 0, 0, 17, 0, 0, 19, 20, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 7, 9, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 4, 5, 0, 0, 0, 0}, {5, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 3, 0, 0, 0, 4, 0, 5, 6, 0, 0, 0, 0, 0, 13, 0, 15, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {3, 9, 11, 15, 16, 20, 23, 28, 0, 0, 0, 30, 33, 36, 40, 46, 0, 48, 57, 49, 50, 54, 56, 0, 0, 0}, {1, 0, 0, 0, 9, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 8, 10, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 5, 0, 0, 0, 0, 0, 0, 9, 0, 11, 0, 0, 0}, {1, 0, 3, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 9, 0, 0, 16, 17, 26, 0, 27, 0, 28, 0}, {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 18, 0, 0, 0, 0}, {2, 6, 15, 0, 18, 22, 0, 24, 25, 0, 0, 28, 30, 34, 38, 40, 0, 48, 0, 49, 0, 61, 62, 0, 63, 0}, {2, 0, 19, 0, 22, 24, 0, 25, 0, 26, 0, 27, 28, 31, 33, 34, 0, 35, 37, 0, 38, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 9, 12, 0, 0, 0, 0, 15, 0, 16, 0, 0, 0, 0, 0}, {2, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 0, 8, 0, 9, 10, 0, 12, 0, 13, 14, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
const unsigned  short  cmdidxs1 [26] = {0, 19, 42, 103, 125, 145, 161, 167, 176, 194, 196, 201, 259, 279, 299, 311, 350, 353, 372, 439, 479, 490, 508, 523, 532, 533};
EXTERN char_u e_usingsid [] INIT (= N_ ("E81: Using <SID> not in a script context"));
EXTERN char_u e_winwidth [] INIT (= N_ ("E592: 'winwidth' cannot be smaller than 'winminwidth'"));
EXTERN char_u e_listidx [] INIT (= N_ ("E684: list index out of range: %ld"));
EXTERN hlf_T edit_submode_highl;
EXTERN int ru_wid;
EXTERN int did_emsg_syntax;
EXTERN int did_uncaught_emsg;
EXTERN int did_emsg;
EXTERN int p_tbidi;
EXTERN int p_hls;
EXTERN char_u *p_hl;
EXTERN int p_hid;
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
EXTERN typebuf_T typebuf;
EXTERN char_u msg_buf [MSG_BUF_LEN];
EXTERN char_u *IObuff;
EXTERN buf_T *curbuf INIT (= NULL);
EXTERN buf_T *lastbuf INIT (= NULL);
EXTERN buf_T *firstbuf INIT (= NULL);
EXTERN int highlight_attr [HLF_COUNT];
EXTERN long  p_ttm;
EXTERN long  p_tm;
EXTERN int p_stmp;
EXTERN int p_confirm;
EXTERN int p_bevalterm;
char_u *ff_expand_buffer = NULL;
EXTERN win_T *au_pending_free_win INIT (= NULL);
EXTERN buf_T *au_pending_free_buf INIT (= NULL);
EXTERN except_T *current_exception;
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
EXTERN int autocmd_fname_full;
EXTERN char_u *autocmd_fname INIT (= NULL);
EXTERN pos_T Insstart_orig;
EXTERN pos_T Insstart;
EXTERN pos_T VIsual;
EXTERN long  p_hh;
EXTERN char_u *p_hlg;
EXTERN int p_lrm;
EXTERN char_u *p_kp;
EXTERN int p_im;
EXTERN char_u e_invalidreg [] INIT (= N_ ("E850: Invalid register name"));

void *vim_memset (void *ptr, int c, size_t size) {
    char *p = ptr;
    while (size-- > 0)
        *p++ = c;
    return ptr;
}

void vim_free (void *x) {
    if (x != NULL && !really_exiting) {
        free (x);
    }
}

char_u *vim_strchr (char_u *string, int c) {
    char_u *p;
    int b;
    p = string;
    while ((b = *p) != NUL) {
        if (b == c)
            return p;
        ++p;
    }
    return NULL;
}

char_u *vim_strsave (char_u *string) {
    char_u *p;
    unsigned  len;
    len = (unsigned ) STRLEN (string) + 1;
    p = alloc (len);
    if (p != NULL)
        mch_memmove (p, string, (size_t) len);
    return p;
}

char_u *alloc (unsigned  size) {
    return (lalloc ((long_u) size, TRUE));
}

char_u *lalloc (long_u size, int message) {
    char_u *p;
    static int releasing = FALSE;
    int try_again;
    if (size == 0) {
        emsg_silent = 0;
        IEMSGN (_ ("E341: Internal error: lalloc(%ld, )"), size);
        return NULL;
    }
    for (;;) {
        if ((p = (char_u *) malloc ((size_t) size)) != NULL) {
            goto theend;
        }
        if (releasing)
            break;
        releasing = TRUE;
        clear_sb_text (TRUE);
        try_again = mf_release_all ();
        releasing = FALSE;
        if (!try_again)
            break;
    }
    if (message && p == NULL)
        do_outofmem_msg (size);
theend :
    return p;
}

void vim_strncpy (char_u *to, char_u *from, size_t len) {
    STRNCPY (to, from, len);
    to[len] = NUL;
}

int copy_option_part (char_u **option, char_u *buf, int maxlen, char *sep_chars) {
    int len = 0;
    char_u *p = *option;
    if (*p == '.')
        buf[len++] = *p++;
    while (*p != NUL && vim_strchr ((char_u *) sep_chars, *p) == NULL) {
        if (p[0] == '\\' && vim_strchr ((char_u *) sep_chars, p[1]) != NULL)
            ++p;
        if (len < maxlen - 1)
            buf[len++] = *p;
        ++p;
    }
    buf[len] = NUL;
    if (*p != NUL && *p != ',')
        ++p;
    p = skip_to_option_part (p);
    *option = p;
    return len;
}

int same_directory (char_u *f1, char_u *f2) {
    char_u ffname [MAXPATHL];
    char_u *t1;
    char_u *t2;
    if (f1 == NULL || f2 == NULL)
        return FALSE;
    (void) vim_FullName (f1, ffname, MAXPATHL, FALSE);
    t1 = gettail_sep (ffname);
    t2 = gettail_sep (f2);
    return (t1 - ffname == t2 - f2 && pathcmp ((char *) ffname, (char *) f2, (int) (t1 - ffname)) == 0);
}

char_u *vim_strnsave (char_u *string, int len) {
    char_u *p;
    p = alloc ((unsigned ) (len + 1));
    if (p != NULL) {
        STRNCPY (p, string, len);
        p[len] = NUL;
    }
    return p;
}

int get_fileformat (buf_T *buf) {
    int c = *buf->b_p_ff;
    if (buf->b_p_bin || c == 'u')
        return EOL_UNIX;
    if (c == 'm')
        return EOL_MAC;
    return EOL_DOS;
}

void vim_strup (char_u *p) {
    char_u *p2;
    int c;
    if (p != NULL) {
        p2 = p;
        while ((c = *p2) != NUL)
            *p2++ = (c < 'a' || c > 'z') ? c : (c - 0x20);
    }
}

int get_real_state (void) {
    if (State & NORMAL) {
        if (VIsual_active) {
            if (VIsual_select)
                return SELECTMODE;
            return VISUAL;
        }
        else if (finish_op)
            return OP_PENDING;
    }
    return State;
}

char_u *lalloc_clear (long_u size, int message) {
    char_u *p;
    p = (lalloc (size, message));
    if (p != NULL)
        (void) vim_memset (p, 0, (size_t) size);
    return p;
}

char_u *alloc_clear (unsigned  size) {
    char_u *p;
    p = lalloc ((long_u) size, TRUE);
    if (p != NULL)
        (void) vim_memset (p, 0, (size_t) size);
    return p;
}

void ga_init2 (garray_T *gap, int itemsize, int growsize) {
    ga_init (gap);
    gap->ga_itemsize = itemsize;
    gap->ga_growsize = growsize;
}

void ga_init (garray_T *gap) {
    gap->ga_data = NULL;
    gap->ga_maxlen = 0;
    gap->ga_len = 0;
}

int virtual_active (void) {
    if (virtual_op != MAYBE)
        return virtual_op;
    return (ve_flags == VE_ALL || ((ve_flags & VE_BLOCK) && VIsual_active && VIsual_mode == Ctrl_V) || ((ve_flags & VE_INSERT) && (State & INSERT)));
}

int coladvance (colnr_T wcol) {
    int rc = getvpos (&curwin->w_cursor, wcol);
    if (wcol == MAXCOL || rc == FAIL)
        curwin->w_valid &= ~VALID_VIRTCOL;
    else if (*ml_get_cursor () != TAB) {
        curwin->w_valid |= VALID_VIRTCOL;
        curwin->w_virtcol = wcol;
    }
    return rc;
}

int getvpos (pos_T *pos, colnr_T wcol) {
    return coladvance2 (pos, FALSE, virtual_active (), wcol);
}

static int coladvance2 (pos_T *pos, int addspaces, int finetune, colnr_T wcol) {
    int idx;
    char_u *ptr;
    char_u *line;
    colnr_T col = 0;
    int csize = 0;
    int one_more;
    int head = 0;
    one_more = (State & INSERT) || restart_edit != NUL || (VIsual_active && *p_sel != 'o') || ((ve_flags & VE_ONEMORE) && wcol < MAXCOL);
    line = ml_get_buf (curbuf, pos->lnum, FALSE);
    if (wcol >= MAXCOL) {
        idx = (int) STRLEN (line) - 1 + one_more;
        col = wcol;
        if ((addspaces || finetune) && !VIsual_active) {
            curwin->w_curswant = linetabsize (line) + one_more;
            if (curwin->w_curswant > 0)
                --curwin->w_curswant;
        }
    }
    else {
        int width = curwin->w_width - win_col_off (curwin);
        if (finetune && curwin->w_p_wrap && curwin->w_width != 0 && wcol >= (colnr_T) width) {
            csize = linetabsize (line);
            if (csize > 0)
                csize--;
            if (wcol / width > (colnr_T) csize / width && ((State & INSERT) == 0 || (int) wcol > csize + 1)) {
                wcol = (csize / width + 1) * width - 1;
            }
        }
        ptr = line;
        while (col <= wcol && *ptr != NUL) {
            csize = win_lbr_chartabsize (curwin, line, ptr, col, &head);
            MB_PTR_ADV (ptr);
            col += csize;
        }
        idx = (int) (ptr - line);
        if (col > wcol || (!virtual_active () && one_more == 0)) {
            idx -= 1;
            csize -= head;
            col -= csize;
        }
        if (virtual_active () && addspaces && ((col != wcol && col != wcol + 1) || csize > 1)) {
            if (line[idx] == NUL) {
                int correct = wcol - col;
                char_u *newline = alloc (idx +correct + 1);
                int t;
                if (newline == NULL)
                    return FAIL;
                for (t = 0; t < idx; ++t)
                    newline[t] = line[t];
                for (t = 0; t < correct; ++t)
                    newline[t + idx] = ' ';
                newline[idx + correct] = NUL;
                ml_replace (pos -> lnum, newline, FALSE);
                changed_bytes (pos -> lnum, (colnr_T) idx);
                idx += correct;
                col = wcol;
            }
            else {
                int linelen = (int) STRLEN (line);
                int correct = wcol - col - csize + 1;
                char_u *newline;
                int t, s = 0;
                int v;
                if (-correct > csize)
                    return FAIL;
                newline = alloc (linelen +csize);
                if (newline == NULL)
                    return FAIL;
                for (t = 0; t < linelen; t++) {
                    if (t != idx)
                        newline[s++] = line[t];
                    else
                        for (v = 0; v < csize; v++)
                            newline[s++] = ' ';
                }
                newline[linelen + csize - 1] = NUL;
                ml_replace (pos -> lnum, newline, FALSE);
                changed_bytes (pos -> lnum, idx);
                idx += (csize - 1 + correct);
                col += correct;
            }
        }
    }
    if (idx < 0)
        pos->col = 0;
    else
        pos->col = idx;
    pos->coladd = 0;
    if (finetune) {
        if (wcol == MAXCOL) {
            if (!one_more) {
                colnr_T scol, ecol;
                getvcol (curwin, pos, & scol, NULL, & ecol);
                pos->coladd = ecol - scol;
            }
        }
        else {
            int b = (int) wcol - (int) col;
            if (b > 0 && b < (MAXCOL - 2 * curwin->w_width))
                pos->coladd = b;
            col += b;
        }
    }
    if (col < wcol)
        return FAIL;
    return OK;
}

int ga_grow (garray_T *gap, int n) {
    size_t old_len;
    size_t new_len;
    char_u *pp;
    if (gap->ga_maxlen - gap->ga_len < n) {
        if (n < gap->ga_growsize)
            n = gap->ga_growsize;
        new_len = gap->ga_itemsize * (gap->ga_len + n);
        pp = (gap->ga_data == NULL) ? alloc ((unsigned ) new_len) : vim_realloc (gap->ga_data, new_len);
        if (pp == NULL)
            return FAIL;
        old_len = gap->ga_itemsize * gap->ga_maxlen;
        vim_memset (pp + old_len, 0, new_len - old_len);
        gap->ga_maxlen = gap->ga_len + n;
        gap->ga_data = pp;
    }
    return OK;
}

char_u *vim_strsave_up (char_u *string) {
    char_u *p1;
    p1 = vim_strsave (string);
    vim_strup (p1);
    return p1;
}

void ga_clear (garray_T *gap) {
    vim_free (gap -> ga_data);
    ga_init (gap);
}

int trans_special (char_u **srcp, char_u *dst, int keycode, int in_string) {
    int modifiers = 0;
    int key;
    int dlen = 0;
    key = find_special_key (srcp, &modifiers, keycode, FALSE, in_string);
    if (key == 0)
        return 0;
    if (modifiers != 0) {
        dst[dlen++] = K_SPECIAL;
        dst[dlen++] = KS_MODIFIER;
        dst[dlen++] = modifiers;
    }
    if (IS_SPECIAL (key)) {
        dst[dlen++] = K_SPECIAL;
        dst[dlen++] = KEY2TERMCAP0 (key);
        dst[dlen++] = KEY2TERMCAP1 (key);
    }
    else if (keycode)
        dlen = (int) (add_char2buf (key, dst +dlen) - dst);
    else
        dst[dlen++] = key;
    return dlen;
}

int find_special_key (char_u **srcp, int *modp, int keycode, int keep_x_key, int in_string) {
    char_u *last_dash;
    char_u *end_of_name;
    char_u *src;
    char_u *bp;
    int modifiers;
    int bit;
    int key;
    uvarnumber_T n;
    int l;
    src = *srcp;
    if (src[0] != '<')
        return 0;
    last_dash = src;
    for (bp = src + 1; *bp == '-' || vim_isIDc (*bp); bp++) {
        if (*bp == '-') {
            last_dash = bp;
            if (bp[1] != NUL) {
                l = 1;
                if (!(in_string && bp[1] == '"') && bp[2] == '>')
                    bp += l;
                else if (in_string && bp[1] == '\\' && bp[2] == '"' && bp[3] == '>')
                    bp += 2;
            }
        }
        if (bp[0] == 't' && bp[1] == '_' && bp[2] && bp[3])
            bp += 3;
        else if (STRNICMP (bp, "char-", 5) == 0) {
            vim_str2nr (bp + 5, NULL, & l, STR2NR_ALL, NULL, NULL, 0);
            bp += l + 5;
            break;
        }
    }
    if (*bp == '>') {
        end_of_name = bp + 1;
        modifiers = 0x0;
        for (bp = src + 1; bp < last_dash; bp++) {
            if (*bp != '-') {
                bit = name_to_mod_mask (*bp);
                if (bit == 0x0)
                    break;
                modifiers |= bit;
            }
        }
        if (bp >= last_dash) {
            if (STRNICMP (last_dash +1, "char-", 5) == 0 && VIM_ISDIGIT (last_dash[6])) {
                vim_str2nr (last_dash + 6, NULL, NULL, STR2NR_ALL, NULL, & n, 0);
                key = (int) n;
            }
            else {
                int off = 1;
                if (in_string && last_dash[1] == '\\' && last_dash[2] == '"')
                    off = 2;
                l = 1;
                if (modifiers != 0 && last_dash[l + off] == '>')
                    key = PTR2CHAR (last_dash +off);
                else {
                    key = get_special_key_code (last_dash +off);
                    if (!keep_x_key)
                        key = handle_x_keys (key);
                }
            }
            if (key != NUL) {
                key = simplify_key (key, &modifiers);
                if (!keycode) {
                    if (key == K_BS)
                        key = BS;
                    else if (key == K_DEL || key == K_KDEL)
                        key = DEL;
                }
                if (!IS_SPECIAL (key))
                    key = extract_modifiers (key, &modifiers);
                *modp = modifiers;
                *srcp = end_of_name;
                return key;
            }
        }
    }
    return 0;
}

int name_to_mod_mask (int c) {
    int i;
    c = TOUPPER_ASC (c);
    for (i = 0; mod_mask_table[i].mod_mask != 0; i++)
        if (c == mod_mask_table[i].name)
            return mod_mask_table[i].mod_flag;
    return 0;
}

int get_special_key_code (char_u *name) {
    char_u *table_name;
    char_u string [3];
    int i, j;
    if (name[0] == 't' && name[1] == '_' && name[2] != NUL && name[3] != NUL) {
        string[0] = name[2];
        string[1] = name[3];
        string[2] = NUL;
        if (add_termcap_entry (string, FALSE) == OK)
            return TERMCAP2KEY (name[2], name[3]);
    }
    else
        for (i = 0; key_names_table[i].name != NULL; i++) {
            table_name = key_names_table[i].name;
            for (j = 0; vim_isIDc (name[j]) && table_name[j] != NUL; j++)
                if (TOLOWER_ASC (table_name[j]) != TOLOWER_ASC (name[j]))
                    break;
            if (!vim_isIDc (name[j]) && table_name[j] == NUL)
                return key_names_table[i].key;
        }
    return 0;
}

int handle_x_keys (int key) {
    switch (key) {
    case K_XUP :
        return K_UP;
    case K_XDOWN :
        return K_DOWN;
    case K_XLEFT :
        return K_LEFT;
    case K_XRIGHT :
        return K_RIGHT;
    case K_XHOME :
        return K_HOME;
    case K_ZHOME :
        return K_HOME;
    case K_XEND :
        return K_END;
    case K_ZEND :
        return K_END;
    case K_XF1 :
        return K_F1;
    case K_XF2 :
        return K_F2;
    case K_XF3 :
        return K_F3;
    case K_XF4 :
        return K_F4;
    case K_S_XF1 :
        return K_S_F1;
    case K_S_XF2 :
        return K_S_F2;
    case K_S_XF3 :
        return K_S_F3;
    case K_S_XF4 :
        return K_S_F4;
    }
    return key;
}

int simplify_key (int key, int *modifiers) {
    int i;
    int key0;
    int key1;
    if (*modifiers & (MOD_MASK_SHIFT | MOD_MASK_CTRL | MOD_MASK_ALT)) {
        if (key == TAB && (*modifiers & MOD_MASK_SHIFT)) {
            *modifiers &= ~MOD_MASK_SHIFT;
            return K_S_TAB;
        }
        key0 = KEY2TERMCAP0 (key);
        key1 = KEY2TERMCAP1 (key);
        for (i = 0; modifier_keys_table[i] != NUL; i += MOD_KEYS_ENTRY_SIZE)
            if (key0 == modifier_keys_table[i + 3] && key1 == modifier_keys_table[i + 4] && (*modifiers & modifier_keys_table[i])) {
                *modifiers &= ~modifier_keys_table[i];
                return TERMCAP2KEY (modifier_keys_table[i + 1], modifier_keys_table[i + 2]);
            }
    }
    return key;
}

int extract_modifiers (int key, int *modp) {
    int modifiers = *modp;
    if (!(modifiers & MOD_MASK_CMD))
        if ((modifiers & MOD_MASK_SHIFT) && ASCII_ISALPHA (key)) {
            key = TOUPPER_ASC (key);
            modifiers &= ~MOD_MASK_SHIFT;
        }
    if ((modifiers & MOD_MASK_CTRL) && ((key >= '?' && key <= '_') || ASCII_ISALPHA (key))) {
        key = Ctrl_chr (key);
        modifiers &= ~MOD_MASK_CTRL;
        if (key == 0)
            key = K_ZERO;
    }
    if (!(modifiers & MOD_MASK_CMD))
        if ((modifiers & MOD_MASK_ALT) && key < 0x80) {
            key |= 0x80;
            modifiers &= ~MOD_MASK_ALT;
        }
    *modp = modifiers;
    return key;
}

void ga_clear_strings (garray_T *gap) {
    int i;
    for (i = 0; i < gap->ga_len; ++i)
        vim_free (((char_u **) (gap->ga_data))[i]);
    ga_clear (gap);
}

char_u *find_file_in_path (char_u *ptr, int len, int options, int first, char_u *rel_fname) {
    return find_file_in_path_option (ptr, len, options, first, *curbuf->b_p_path == NUL ? p_path : curbuf->b_p_path, FINDFILE_BOTH, rel_fname, curbuf->b_p_sua);
}

char_u *find_file_in_path_option (char_u *ptr, int len, int options, int first, char_u *path_option, int find_what, char_u *rel_fname, char_u *suffixes) {
    static char_u *dir;
    static int did_findfile_init = FALSE;
    char_u save_char;
    char_u *file_name = NULL;
    char_u *buf = NULL;
    int rel_to_curdir;
    if (first == TRUE) {
        save_char = ptr[len];
        ptr[len] = NUL;
        expand_env_esc (ptr, NameBuff, MAXPATHL, FALSE, TRUE, NULL);
        ptr[len] = save_char;
        vim_free (ff_file_to_find);
        ff_file_to_find = vim_strsave (NameBuff);
        if (ff_file_to_find == NULL) {
            file_name = NULL;
            goto theend;
        }
        if (options & FNAME_UNESC) {
            for (ptr = ff_file_to_find; *ptr != NUL; ++ptr)
                if (ptr[0] == '\\' && ptr[1] == ' ')
                    mch_memmove (ptr, ptr +1, STRLEN (ptr));
        }
    }
    rel_to_curdir = (ff_file_to_find[0] == '.' && (ff_file_to_find[1] == NUL || vim_ispathsep (ff_file_to_find[1]) || (ff_file_to_find[1] == '.' && (ff_file_to_find[2] == NUL || vim_ispathsep (ff_file_to_find[2])))));
    if (vim_isAbsName (ff_file_to_find) || rel_to_curdir) {
        if (first == TRUE) {
            int l;
            int run;
            if (path_with_url (ff_file_to_find)) {
                file_name = vim_strsave (ff_file_to_find);
                goto theend;
            }
            for (run = 1; run <= 2; ++run) {
                l = (int) STRLEN (ff_file_to_find);
                if (run == 1 && rel_to_curdir && (options & FNAME_REL) && rel_fname != NULL && STRLEN (rel_fname) + l < MAXPATHL) {
                    STRCPY (NameBuff, rel_fname);
                    STRCPY (gettail (NameBuff), ff_file_to_find);
                    l = (int) STRLEN (NameBuff);
                }
                else {
                    STRCPY (NameBuff, ff_file_to_find);
                    run = 2;
                }
                buf = suffixes;
                for (;;) {
                    if (mch_getperm (NameBuff) >= 0 && (find_what == FINDFILE_BOTH || ((find_what == FINDFILE_DIR) == mch_isdir (NameBuff)))) {
                        file_name = vim_strsave (NameBuff);
                        goto theend;
                    }
                    if (*buf == NUL)
                        break;
                    copy_option_part (& buf, NameBuff + l, MAXPATHL - l, ",");
                }
            }
        }
    }
    else {
        if (first == TRUE) {
            vim_findfile_free_visited (fdip_search_ctx);
            dir = path_option;
            did_findfile_init = FALSE;
        }
        for (;;) {
            if (did_findfile_init) {
                file_name = vim_findfile (fdip_search_ctx);
                if (file_name != NULL)
                    break;
                did_findfile_init = FALSE;
            }
            else {
                char_u *r_ptr;
                if (dir == NULL || *dir == NUL) {
                    vim_findfile_cleanup (fdip_search_ctx);
                    fdip_search_ctx = NULL;
                    break;
                }
                if ((buf = alloc ((int) (MAXPATHL))) == NULL)
                    break;
                buf[0] = 0;
                copy_option_part (& dir, buf, MAXPATHL, " ,");
                r_ptr = vim_findfile_stopdir (buf);
                fdip_search_ctx = vim_findfile_init (buf, ff_file_to_find, r_ptr, 100, FALSE, find_what, fdip_search_ctx, FALSE, rel_fname);
                if (fdip_search_ctx != NULL)
                    did_findfile_init = TRUE;
                vim_free (buf);
            }
        }
    }
    if (file_name == NULL && (options & FNAME_MESS)) {
        if (first == TRUE) {
            if (find_what == FINDFILE_DIR)
                EMSG2 (_ ("E344: Can't find directory \"%s\" in cdpath"), ff_file_to_find);
            else
                EMSG2 (_ ("E345: Can't find file \"%s\" in path"), ff_file_to_find);
        }
        else {
            if (find_what == FINDFILE_DIR)
                EMSG2 (_ ("E346: No more directory \"%s\" found in cdpath"), ff_file_to_find);
            else
                EMSG2 (_ ("E347: No more file \"%s\" found in path"), ff_file_to_find);
        }
    }
theend :
    return file_name;
}

void vim_findfile_free_visited (void *search_ctx_arg) {
    ff_search_ctx_T *search_ctx;
    if (search_ctx_arg == NULL)
        return;
    search_ctx = (ff_search_ctx_T *) search_ctx_arg;
    vim_findfile_free_visited_list (& search_ctx -> ffsc_visited_lists_list);
    vim_findfile_free_visited_list (& search_ctx -> ffsc_dir_visited_lists_list);
}

static void vim_findfile_free_visited_list (ff_visited_list_hdr_T **list_headp) {
    ff_visited_list_hdr_T *vp;
    while (*list_headp != NULL) {
        vp = (*list_headp)->ffvl_next;
        ff_free_visited_list ((* list_headp) -> ffvl_visited_list);
        vim_free ((* list_headp) -> ffvl_filename);
        vim_free (*list_headp);
        *list_headp = vp;
    }
    *list_headp = NULL;
}

static void ff_free_visited_list (ff_visited_T *vl) {
    ff_visited_T *vp;
    while (vl != NULL) {
        vp = vl->ffv_next;
        vim_free (vl -> ffv_wc_path);
        vim_free (vl);
        vl = vp;
    }
    vl = NULL;
}

char_u *vim_findfile (void *search_ctx_arg) {
    char_u *file_path;
    char_u *rest_of_wildcards;
    char_u *path_end = NULL;
    ff_stack_T *stackp;
    int len;
    int i;
    char_u *p;
    char_u *suf;
    ff_search_ctx_T *search_ctx;
    if (search_ctx_arg == NULL)
        return NULL;
    search_ctx = (ff_search_ctx_T *) search_ctx_arg;
    if ((file_path = alloc ((int) MAXPATHL)) == NULL)
        return NULL;
    if (search_ctx->ffsc_start_dir != NULL)
        path_end = &search_ctx->ffsc_start_dir[STRLEN (search_ctx->ffsc_start_dir)];
    for (;;) {
        for (;;) {
            ui_breakcheck ();
            if (got_int)
                break;
            stackp = ff_pop (search_ctx);
            if (stackp == NULL)
                break;
            if (stackp->ffs_filearray == NULL && ff_check_visited (&search_ctx->ffsc_dir_visited_list->ffvl_visited_list, stackp->ffs_fix_path, stackp->ffs_wc_path) == FAIL) {
                ff_free_stack_element (stackp);
                continue;
            }
            if (stackp->ffs_level <= 0) {
                ff_free_stack_element (stackp);
                continue;
            }
            file_path[0] = NUL;
            if (stackp->ffs_filearray == NULL) {
                char_u *dirptrs [2];
                dirptrs[0] = file_path;
                dirptrs[1] = NULL;
                if (!vim_isAbsName (stackp->ffs_fix_path) && search_ctx->ffsc_start_dir) {
                    if (STRLEN (search_ctx->ffsc_start_dir) + 1 < MAXPATHL) {
                        STRCPY (file_path, search_ctx -> ffsc_start_dir);
                        add_pathsep (file_path);
                    }
                    else
                        goto fail;
                }
                if (STRLEN (file_path) + STRLEN (stackp->ffs_fix_path) + 1 < MAXPATHL) {
                    STRCAT (file_path, stackp -> ffs_fix_path);
                    add_pathsep (file_path);
                }
                else
                    goto fail;
                rest_of_wildcards = stackp->ffs_wc_path;
                if (*rest_of_wildcards != NUL) {
                    len = (int) STRLEN (file_path);
                    if (STRNCMP (rest_of_wildcards, "**", 2) == 0) {
                        p = rest_of_wildcards + 2;
                        if (*p > 0) {
                            (*p)--;
                            if (len + 1 < MAXPATHL)
                                file_path[len++] = '*';
                            else
                                goto fail;
                        }
                        if (*p == 0) {
                            STRMOVE (rest_of_wildcards, rest_of_wildcards + 3);
                        }
                        else
                            rest_of_wildcards += 3;
                        if (stackp->ffs_star_star_empty == 0) {
                            stackp->ffs_star_star_empty = 1;
                            dirptrs[1] = stackp->ffs_fix_path;
                        }
                    }
                    while (*rest_of_wildcards && !vim_ispathsep (*rest_of_wildcards))
                        if (len + 1 < MAXPATHL)
                            file_path[len++] = *rest_of_wildcards++;
                        else
                            goto fail;
                    file_path[len] = NUL;
                    if (vim_ispathsep (*rest_of_wildcards))
                        rest_of_wildcards++;
                }
                if (path_with_url (dirptrs[0])) {
                    stackp->ffs_filearray = (char_u **) alloc ((unsigned ) sizeof (char *));
                    if (stackp->ffs_filearray != NULL && (stackp->ffs_filearray[0] = vim_strsave (dirptrs[0])) != NULL)
                        stackp->ffs_filearray_size = 1;
                    else
                        stackp->ffs_filearray_size = 0;
                }
                else
                    expand_wildcards ((dirptrs[1] == NULL) ? 1 : 2, dirptrs, &stackp->ffs_filearray_size, &stackp->ffs_filearray, EW_DIR | EW_ADDSLASH | EW_SILENT | EW_NOTWILD);
                stackp->ffs_filearray_cur = 0;
                stackp->ffs_stage = 0;
            }
            else
                rest_of_wildcards = &stackp->ffs_wc_path[STRLEN (stackp->ffs_wc_path)];
            if (stackp->ffs_stage == 0) {
                if (*rest_of_wildcards == NUL) {
                    for (i = stackp->ffs_filearray_cur; i < stackp->ffs_filearray_size; ++i) {
                        if (!path_with_url (stackp->ffs_filearray[i]) && !mch_isdir (stackp->ffs_filearray[i]))
                            continue;
                        if (STRLEN (stackp->ffs_filearray[i]) + 1 + STRLEN (search_ctx->ffsc_file_to_search) < MAXPATHL) {
                            STRCPY (file_path, stackp -> ffs_filearray [i]);
                            add_pathsep (file_path);
                            STRCAT (file_path, search_ctx -> ffsc_file_to_search);
                        }
                        else
                            goto fail;
                        len = (int) STRLEN (file_path);
                        if (search_ctx->ffsc_tagfile)
                            suf = (char_u *) "";
                        else
                            suf = curbuf->b_p_sua;
                        for (;;) {
                            if ((path_with_url (file_path) || (mch_getperm (file_path) >= 0 && (search_ctx->ffsc_find_what == FINDFILE_BOTH || ((search_ctx->ffsc_find_what == FINDFILE_DIR) == mch_isdir (file_path))))) && (ff_check_visited (&search_ctx->ffsc_visited_list->ffvl_visited_list, file_path, (char_u *) "") == OK)) {
                                stackp->ffs_filearray_cur = i + 1;
                                ff_push (search_ctx, stackp);
                                if (!path_with_url (file_path))
                                    simplify_filename (file_path);
                                if (mch_dirname (ff_expand_buffer, MAXPATHL) == OK) {
                                    p = shorten_fname (file_path, ff_expand_buffer);
                                    if (p != NULL)
                                        STRMOVE (file_path, p);
                                }
                                return file_path;
                            }
                            if (*suf == NUL)
                                break;
                            copy_option_part (& suf, file_path + len, MAXPATHL - len, ",");
                        }
                    }
                }
                else {
                    for (i = stackp->ffs_filearray_cur; i < stackp->ffs_filearray_size; ++i) {
                        if (!mch_isdir (stackp->ffs_filearray[i]))
                            continue;
                        ff_push (search_ctx, ff_create_stack_element (stackp -> ffs_filearray [i], rest_of_wildcards, stackp -> ffs_level - 1, 0));
                    }
                }
                stackp->ffs_filearray_cur = 0;
                stackp->ffs_stage = 1;
            }
            if (STRNCMP (stackp->ffs_wc_path, "**", 2) == 0) {
                for (i = stackp->ffs_filearray_cur; i < stackp->ffs_filearray_size; ++i) {
                    if (fnamecmp (stackp->ffs_filearray[i], stackp->ffs_fix_path) == 0)
                        continue;
                    if (!mch_isdir (stackp->ffs_filearray[i]))
                        continue;
                    ff_push (search_ctx, ff_create_stack_element (stackp -> ffs_filearray [i], stackp -> ffs_wc_path, stackp -> ffs_level - 1, 1));
                }
            }
            ff_free_stack_element (stackp);
        }
        if (search_ctx->ffsc_start_dir && search_ctx->ffsc_stopdirs_v != NULL && !got_int) {
            ff_stack_T *sptr;
            if (ff_path_in_stoplist (search_ctx->ffsc_start_dir, (int) (path_end - search_ctx->ffsc_start_dir), search_ctx->ffsc_stopdirs_v) == TRUE)
                break;
            while (path_end > search_ctx->ffsc_start_dir && vim_ispathsep (*path_end))
                path_end--;
            while (path_end > search_ctx->ffsc_start_dir && !vim_ispathsep (path_end[-1]))
                path_end--;
            *path_end = 0;
            path_end--;
            if (*search_ctx->ffsc_start_dir == 0)
                break;
            if (STRLEN (search_ctx->ffsc_start_dir) + 1 + STRLEN (search_ctx->ffsc_fix_path) < MAXPATHL) {
                STRCPY (file_path, search_ctx -> ffsc_start_dir);
                add_pathsep (file_path);
                STRCAT (file_path, search_ctx -> ffsc_fix_path);
            }
            else
                goto fail;
            sptr = ff_create_stack_element (file_path, search_ctx->ffsc_wc_path, search_ctx->ffsc_level, 0);
            if (sptr == NULL)
                break;
            ff_push (search_ctx, sptr);
        }
        else
            break;
    }
fail :
    vim_free (file_path);
    return NULL;
}

static ff_stack_T *ff_pop (ff_search_ctx_T *search_ctx) {
    ff_stack_T *sptr;
    sptr = search_ctx->ffsc_stack_ptr;
    if (search_ctx->ffsc_stack_ptr != NULL)
        search_ctx->ffsc_stack_ptr = search_ctx->ffsc_stack_ptr->ffs_prev;
    return sptr;
}

static int ff_check_visited (ff_visited_T **visited_list, char_u *fname, char_u *wc_path) {
    ff_visited_T *vp;
    stat_T st;
    int url = FALSE;
    if (path_with_url (fname)) {
        vim_strncpy (ff_expand_buffer, fname, MAXPATHL - 1);
        url = TRUE;
    }
    else {
        ff_expand_buffer[0] = NUL;
        if (mch_stat ((char *) fname, &st) < 0)
            return FAIL;
    }
    for (vp = *visited_list; vp != NULL; vp = vp->ffv_next) {
        if (!url ? (vp->ffv_dev_valid && vp->ffv_dev == st.st_dev && vp->ffv_ino == st.st_ino) : fnamecmp (vp->ffv_fname, ff_expand_buffer) == 0) {
            if (ff_wc_equal (vp->ffv_wc_path, wc_path) == TRUE)
                return FAIL;
        }
    }
    vp = (ff_visited_T *) alloc ((unsigned ) (sizeof (ff_visited_T) + STRLEN (ff_expand_buffer)));
    if (vp != NULL) {
        if (!url) {
            vp->ffv_dev_valid = TRUE;
            vp->ffv_ino = st.st_ino;
            vp->ffv_dev = st.st_dev;
            vp->ffv_fname[0] = NUL;
        }
        else {
            vp->ffv_dev_valid = FALSE;
            STRCPY (vp -> ffv_fname, ff_expand_buffer);
        }
        if (wc_path != NULL)
            vp->ffv_wc_path = vim_strsave (wc_path);
        else
            vp->ffv_wc_path = NULL;
        vp->ffv_next = *visited_list;
        *visited_list = vp;
    }
    return OK;
}

static int ff_wc_equal (char_u *s1, char_u *s2) {
    int i, j;
    int c1 = NUL;
    int c2 = NUL;
    int prev1 = NUL;
    int prev2 = NUL;
    if (s1 == s2)
        return TRUE;
    if (s1 == NULL || s2 == NULL)
        return FALSE;
    for (i = 0, j = 0; s1[i] != NUL && s2[j] != NUL;) {
        c1 = PTR2CHAR (s1 +i);
        c2 = PTR2CHAR (s2 +j);
        if ((p_fic ? MB_TOLOWER (c1) != MB_TOLOWER (c2) : c1 != c2) && (prev1 != '*' || prev2 != '*'))
            return FALSE;
        prev2 = prev1;
        prev1 = c1;
        i += MB_PTR2LEN (s1 +i);
        j += MB_PTR2LEN (s2 +j);
    }
    return s1[i] == s2[j];
}

static void ff_free_stack_element (ff_stack_T *stack_ptr) {
    vim_free (stack_ptr -> ffs_fix_path);
    vim_free (stack_ptr -> ffs_wc_path);
    if (stack_ptr->ffs_filearray != NULL)
        FreeWild (stack_ptr->ffs_filearray_size, stack_ptr->ffs_filearray);
    vim_free (stack_ptr);
}

static void ff_push (ff_search_ctx_T *search_ctx, ff_stack_T *stack_ptr) {
    if (stack_ptr != NULL) {
        stack_ptr->ffs_prev = search_ctx->ffsc_stack_ptr;
        search_ctx->ffsc_stack_ptr = stack_ptr;
    }
}

static ff_stack_T *ff_create_stack_element (char_u *fix_part, char_u *wc_part, int level, int star_star_empty) {
    ff_stack_T *new;
    new = (ff_stack_T *) alloc ((unsigned ) sizeof (ff_stack_T));
    if (new == NULL)
        return NULL;
    new->ffs_prev = NULL;
    new->ffs_filearray = NULL;
    new->ffs_filearray_size = 0;
    new->ffs_filearray_cur = 0;
    new->ffs_stage = 0;
    new->ffs_level = level;
    new->ffs_star_star_empty = star_star_empty;
    if (fix_part == NULL)
        fix_part = (char_u *) "";
    new->ffs_fix_path = vim_strsave (fix_part);
    if (wc_part == NULL)
        wc_part = (char_u *) "";
    new->ffs_wc_path = vim_strsave (wc_part);
    if (new->ffs_fix_path == NULL || new->ffs_wc_path == NULL) {
        ff_free_stack_element (new);
        new = NULL;
    }
    return new;
}

static int ff_path_in_stoplist (char_u *path, int path_len, char_u **stopdirs_v) {
    int i = 0;
    while (path_len > 1 && vim_ispathsep (path[path_len - 1]))
        path_len--;
    if (path_len == 0)
        return TRUE;
    for (i = 0; stopdirs_v[i] != NULL; i++) {
        if ((int) STRLEN (stopdirs_v[i]) > path_len) {
            if (fnamencmp (stopdirs_v[i], path, path_len) == 0 && vim_ispathsep (stopdirs_v[i][path_len]))
                return TRUE;
        }
        else {
            if (fnamecmp (stopdirs_v[i], path) == 0)
                return TRUE;
        }
    }
    return FALSE;
}

void vim_findfile_cleanup (void *ctx) {
    if (ctx == NULL)
        return;
    vim_findfile_free_visited (ctx);
    ff_clear (ctx);
    vim_free (ctx);
}

static void ff_clear (ff_search_ctx_T *search_ctx) {
    ff_stack_T *sptr;
    while ((sptr = ff_pop (search_ctx)) != NULL)
        ff_free_stack_element (sptr);
    vim_free (search_ctx -> ffsc_file_to_search);
    vim_free (search_ctx -> ffsc_start_dir);
    vim_free (search_ctx -> ffsc_fix_path);
    vim_free (search_ctx -> ffsc_wc_path);
    if (search_ctx->ffsc_stopdirs_v != NULL) {
        int i = 0;
        while (search_ctx->ffsc_stopdirs_v[i] != NULL) {
            vim_free (search_ctx -> ffsc_stopdirs_v [i]);
            i++;
        }
        vim_free (search_ctx -> ffsc_stopdirs_v);
    }
    search_ctx->ffsc_stopdirs_v = NULL;
    search_ctx->ffsc_file_to_search = NULL;
    search_ctx->ffsc_start_dir = NULL;
    search_ctx->ffsc_fix_path = NULL;
    search_ctx->ffsc_wc_path = NULL;
    search_ctx->ffsc_level = 0;
}

char_u *vim_findfile_stopdir (char_u *buf) {
    char_u *r_ptr = buf;
    while (*r_ptr != NUL && *r_ptr != ';') {
        if (r_ptr[0] == '\\' && r_ptr[1] == ';') {
            STRMOVE (r_ptr, r_ptr + 1);
            r_ptr++;
        }
        r_ptr++;
    }
    if (*r_ptr == ';') {
        *r_ptr = 0;
        r_ptr++;
    }
    else if (*r_ptr == NUL)
        r_ptr = NULL;
    return r_ptr;
}

void *vim_findfile_init (char_u *path, char_u *filename, char_u *stopdirs, int level, int free_visited, int find_what, void *search_ctx_arg, int tagfile, char_u *rel_fname) {
    char_u *wc_part;
    ff_stack_T *sptr;
    ff_search_ctx_T *search_ctx;
    if (search_ctx_arg != NULL)
        search_ctx = search_ctx_arg;
    else {
        search_ctx = (ff_search_ctx_T *) alloc ((unsigned ) sizeof (ff_search_ctx_T));
        if (search_ctx == NULL)
            goto error_return;
        vim_memset (search_ctx, 0, sizeof (ff_search_ctx_T));
    }
    search_ctx->ffsc_find_what = find_what;
    search_ctx->ffsc_tagfile = tagfile;
    ff_clear (search_ctx);
    if (free_visited == TRUE)
        vim_findfile_free_visited (search_ctx);
    else {
        search_ctx->ffsc_visited_list = ff_get_visited_list (filename, &search_ctx->ffsc_visited_lists_list);
        if (search_ctx->ffsc_visited_list == NULL)
            goto error_return;
        search_ctx->ffsc_dir_visited_list = ff_get_visited_list (filename, &search_ctx->ffsc_dir_visited_lists_list);
        if (search_ctx->ffsc_dir_visited_list == NULL)
            goto error_return;
    }
    if (ff_expand_buffer == NULL) {
        ff_expand_buffer = (char_u *) alloc (MAXPATHL);
        if (ff_expand_buffer == NULL)
            goto error_return;
    }
    if (path[0] == '.' && (vim_ispathsep (path[1]) || path[1] == NUL) && (!tagfile || vim_strchr (p_cpo, CPO_DOTTAG) == NULL) && rel_fname != NULL) {
        int len = (int) (gettail (rel_fname) - rel_fname);
        if (!vim_isAbsName (rel_fname) && len + 1 < MAXPATHL) {
            vim_strncpy (ff_expand_buffer, rel_fname, len);
            search_ctx->ffsc_start_dir = FullName_save (ff_expand_buffer, FALSE);
        }
        else
            search_ctx->ffsc_start_dir = vim_strnsave (rel_fname, len);
        if (search_ctx->ffsc_start_dir == NULL)
            goto error_return;
        if (*++path != NUL)
            ++path;
    }
    else if (*path == NUL || !vim_isAbsName (path)) {
        if (mch_dirname (ff_expand_buffer, MAXPATHL) == FAIL)
            goto error_return;
        search_ctx->ffsc_start_dir = vim_strsave (ff_expand_buffer);
        if (search_ctx->ffsc_start_dir == NULL)
            goto error_return;
    }
    if (stopdirs != NULL) {
        char_u *walker = stopdirs;
        int dircount;
        while (*walker == ';')
            walker++;
        dircount = 1;
        search_ctx->ffsc_stopdirs_v = (char_u **) alloc ((unsigned ) sizeof (char_u *));
        if (search_ctx->ffsc_stopdirs_v != NULL) {
            do {
                char_u *helper;
                void *ptr;
                helper = walker;
                ptr = vim_realloc (search_ctx->ffsc_stopdirs_v, (dircount + 1) * sizeof (char_u *));
                if (ptr)
                    search_ctx->ffsc_stopdirs_v = ptr;
                else
                    break;
                walker = vim_strchr (walker, ';');
                if (walker) {
                    search_ctx->ffsc_stopdirs_v[dircount - 1] = vim_strnsave (helper, (int) (walker - helper));
                    walker++;
                }
                else
                    search_ctx->ffsc_stopdirs_v[dircount - 1] = vim_strsave (helper);
                dircount++;
            }
            while (walker != NULL);
            search_ctx->ffsc_stopdirs_v[dircount - 1] = NULL;
        }
    }
    search_ctx->ffsc_level = level;
    wc_part = vim_strchr (path, '*');
    if (wc_part != NULL) {
        int llevel;
        int len;
        char *errpt;
        search_ctx->ffsc_fix_path = vim_strnsave (path, (int) (wc_part - path));
        len = 0;
        while (*wc_part != NUL) {
            if (len + 5 >= MAXPATHL) {
                EMSG (_ (e_pathtoolong));
                break;
            }
            if (STRNCMP (wc_part, "**", 2) == 0) {
                ff_expand_buffer[len++] = *wc_part++;
                ff_expand_buffer[len++] = *wc_part++;
                llevel = strtol ((char *) wc_part, &errpt, 10);
                if ((char_u *) errpt != wc_part && llevel > 0 && llevel < 255)
                    ff_expand_buffer[len++] = llevel;
                else if ((char_u *) errpt != wc_part && llevel == 0)
                    len -= 2;
                else
                    ff_expand_buffer[len++] = FF_MAX_STAR_STAR_EXPAND;
                wc_part = (char_u *) errpt;
                if (*wc_part != NUL && !vim_ispathsep (*wc_part)) {
                    EMSG2 (_ ("E343: Invalid path: '**[number]' must be at the end of the path or be followed by '%s'."), PATHSEPSTR);
                    goto error_return;
                }
            }
            else
                ff_expand_buffer[len++] = *wc_part++;
        }
        ff_expand_buffer[len] = NUL;
        search_ctx->ffsc_wc_path = vim_strsave (ff_expand_buffer);
        if (search_ctx->ffsc_wc_path == NULL)
            goto error_return;
    }
    else
        search_ctx->ffsc_fix_path = vim_strsave (path);
    if (search_ctx->ffsc_start_dir == NULL) {
        search_ctx->ffsc_start_dir = vim_strsave (search_ctx->ffsc_fix_path);
        if (search_ctx->ffsc_start_dir == NULL)
            goto error_return;
        search_ctx->ffsc_fix_path[0] = NUL;
    }
    if (STRLEN (search_ctx->ffsc_start_dir) + STRLEN (search_ctx->ffsc_fix_path) + 3 >= MAXPATHL) {
        EMSG (_ (e_pathtoolong));
        goto error_return;
    }
    STRCPY (ff_expand_buffer, search_ctx -> ffsc_start_dir);
    add_pathsep (ff_expand_buffer);
    {
        int eb_len = (int) STRLEN (ff_expand_buffer);
        char_u *buf = alloc (eb_len +(int)STRLEN (search_ctx->ffsc_fix_path) + 1);
        STRCPY (buf, ff_expand_buffer);
        STRCPY (buf + eb_len, search_ctx -> ffsc_fix_path);
        if (mch_isdir (buf)) {
            STRCAT (ff_expand_buffer, search_ctx -> ffsc_fix_path);
            add_pathsep (ff_expand_buffer);
        }
        else {
            char_u *p = gettail (search_ctx->ffsc_fix_path);
            char_u *wc_path = NULL;
            char_u *temp = NULL;
            int len = 0;
            if (p > search_ctx->ffsc_fix_path) {
                len = (int) (p - search_ctx->ffsc_fix_path) - 1;
                STRNCAT (ff_expand_buffer, search_ctx -> ffsc_fix_path, len);
                add_pathsep (ff_expand_buffer);
            }
            else
                len = (int) STRLEN (search_ctx->ffsc_fix_path);
            if (search_ctx->ffsc_wc_path != NULL) {
                wc_path = vim_strsave (search_ctx->ffsc_wc_path);
                temp = alloc ((int) (STRLEN (search_ctx->ffsc_wc_path) + STRLEN (search_ctx->ffsc_fix_path + len) + 1));
                if (temp == NULL || wc_path == NULL) {
                    vim_free (buf);
                    vim_free (temp);
                    vim_free (wc_path);
                    goto error_return;
                }
                STRCPY (temp, search_ctx -> ffsc_fix_path + len);
                STRCAT (temp, search_ctx -> ffsc_wc_path);
                vim_free (search_ctx -> ffsc_wc_path);
                vim_free (wc_path);
                search_ctx->ffsc_wc_path = temp;
            }
        }
        vim_free (buf);
    }
    sptr = ff_create_stack_element (ff_expand_buffer, search_ctx->ffsc_wc_path, level, 0);
    if (sptr == NULL)
        goto error_return;
    ff_push (search_ctx, sptr);
    search_ctx->ffsc_file_to_search = vim_strsave (filename);
    if (search_ctx->ffsc_file_to_search == NULL)
        goto error_return;
    return search_ctx;
error_return :
    vim_findfile_cleanup (search_ctx);
    return NULL;
}

static ff_visited_list_hdr_T *ff_get_visited_list (char_u *filename, ff_visited_list_hdr_T **list_headp) {
    ff_visited_list_hdr_T *retptr = NULL;
    if (*list_headp != NULL) {
        retptr = *list_headp;
        while (retptr != NULL) {
            if (fnamecmp (filename, retptr->ffvl_filename) == 0) {
                return retptr;
            }
            retptr = retptr->ffvl_next;
        }
    }
    retptr = (ff_visited_list_hdr_T *) alloc ((unsigned ) sizeof (*retptr));
    if (retptr == NULL)
        return NULL;
    retptr->ffvl_visited_list = NULL;
    retptr->ffvl_filename = vim_strsave (filename);
    if (retptr->ffvl_filename == NULL) {
        vim_free (retptr);
        return NULL;
    }
    retptr->ffvl_next = *list_headp;
    *list_headp = retptr;
    return retptr;
}

char_u *vim_strrchr (char_u *string, int c) {
    char_u *retval = NULL;
    char_u *p = string;
    while (*p) {
        if (*p == c)
            retval = p;
        MB_PTR_ADV (p);
    }
    return retval;
}

void ga_concat (garray_T *gap, char_u *s) {
    int len;
    if (s == NULL || *s == NUL)
        return;
    len = (int) STRLEN (s);
    if (ga_grow (gap, len) == OK) {
        mch_memmove ((char *) gap -> ga_data + gap -> ga_len, s, (size_t) len);
        gap->ga_len += len;
    }
}

void ga_append (garray_T *gap, int c) {
    if (ga_grow (gap, 1) == OK) {
        *((char *) gap->ga_data + gap->ga_len) = c;
        ++gap->ga_len;
    }
}

int leftcol_changed (void) {
    long  lastcol;
    colnr_T s, e;
    int retval = FALSE;
    changed_cline_bef_curs ();
    lastcol = curwin->w_leftcol + curwin->w_width - curwin_col_off () - 1;
    validate_virtcol ();
    if (curwin->w_virtcol > (colnr_T) (lastcol - p_siso)) {
        retval = TRUE;
        coladvance ((colnr_T) (lastcol - p_siso));
    }
    else if (curwin->w_virtcol < curwin->w_leftcol + p_siso) {
        retval = TRUE;
        (void) coladvance ((colnr_T) (curwin->w_leftcol + p_siso));
    }
    getvvcol (curwin, & curwin -> w_cursor, & s, NULL, & e);
    if (e > (colnr_T) lastcol) {
        retval = TRUE;
        coladvance (s - 1);
    }
    else if (s < curwin->w_leftcol) {
        retval = TRUE;
        if (coladvance (e +1) == FAIL) {
            curwin->w_leftcol = s;
            changed_cline_bef_curs ();
        }
    }
    if (retval)
        curwin->w_set_curswant = TRUE;
    redraw_later (NOT_VALID);
    return retval;
}

char_u *vim_strpbrk (char_u *s, char_u *charset) {
    while (*s) {
        if (vim_strchr (charset, *s) != NULL)
            return s;
        MB_PTR_ADV (s);
    }
    return NULL;
}

linenr_T get_cursor_rel_lnum (win_T *wp, linenr_T lnum) {
    linenr_T cursor = wp->w_cursor.lnum;
    linenr_T retval = 0;
    if (hasAnyFolding (wp)) {
        if (lnum > cursor) {
            while (lnum > cursor) {
                (void) hasFoldingWin (wp, lnum, &lnum, NULL, TRUE, NULL);
                if (lnum > cursor)
                    retval++;
                lnum--;
            }
        }
        else if (lnum < cursor) {
            while (lnum < cursor) {
                (void) hasFoldingWin (wp, lnum, NULL, &lnum, TRUE, NULL);
                if (lnum < cursor)
                    retval--;
                lnum++;
            }
        }
    }
    else
        retval = lnum - cursor;
    return retval;
}

int vim_isspace (int x) {
    return ((x >= 9 && x <= 13) || x == ' ');
}

void qsort (void *base, size_t elm_count, size_t elm_size, int (*cmp) (const void *, const void *)) {
    char_u *buf;
    char_u *p1;
    char_u *p2;
    int i, j;
    int gap;
    buf = alloc ((unsigned ) elm_size);
    if (buf == NULL)
        return;
    for (gap = elm_count / 2; gap > 0; gap /= 2)
        for (i = gap; i < elm_count; ++i)
            for (j = i - gap; j >= 0; j -= gap) {
                p1 = (char_u *) base + j * elm_size;
                p2 = (char_u *) base + (j + gap) * elm_size;
                if ((*cmp) ((void *) p1, (void *) p2) <= 0)
                    break;
                mch_memmove (buf, p1, elm_size);
                mch_memmove (p1, p2, elm_size);
                mch_memmove (p2, buf, elm_size);
            }
    vim_free (buf);
}

void check_cursor (void) {
    check_cursor_lnum ();
    check_cursor_col ();
}

void check_cursor_lnum (void) {
    if (curwin->w_cursor.lnum > curbuf->b_ml.ml_line_count) {
        if (!hasFolding (curbuf->b_ml.ml_line_count, &curwin->w_cursor.lnum, NULL))
            curwin->w_cursor.lnum = curbuf->b_ml.ml_line_count;
    }
    if (curwin->w_cursor.lnum <= 0)
        curwin->w_cursor.lnum = 1;
}

void check_cursor_col (void) {
    check_cursor_col_win (curwin);
}

void check_cursor_col_win (win_T *win) {
    colnr_T len;
    colnr_T oldcol = win->w_cursor.col;
    colnr_T oldcoladd = win->w_cursor.col + win->w_cursor.coladd;
    len = (colnr_T) STRLEN (ml_get_buf (win->w_buffer, win->w_cursor.lnum, FALSE));
    if (len == 0)
        win->w_cursor.col = 0;
    else if (win->w_cursor.col >= len) {
        if ((State & INSERT) || restart_edit || (VIsual_active && *p_sel != 'o') || (ve_flags & VE_ONEMORE) || virtual_active ())
            win->w_cursor.col = len;
        else {
            win->w_cursor.col = len - 1;
        }
    }
    else if (win->w_cursor.col < 0)
        win->w_cursor.col = 0;
    if (oldcol == MAXCOL)
        win->w_cursor.coladd = 0;
    else if (ve_flags == VE_ALL) {
        if (oldcoladd > win->w_cursor.col) {
            win->w_cursor.coladd = oldcoladd - win->w_cursor.col;
            if (win->w_cursor.col + 1 < len && win->w_cursor.coladd > 0) {
                int cs, ce;
                getvcol (win, & win -> w_cursor, & cs, NULL, & ce);
                if (win->w_cursor.coladd > ce - cs)
                    win->w_cursor.coladd = ce - cs;
            }
        }
        else
            win->w_cursor.coladd = 0;
    }
}

void do_outofmem_msg (long_u size) {
    if (!did_outofmem_msg) {
        emsg_silent = 0;
        did_outofmem_msg = TRUE;
        EMSGN (_ ("E342: Out of memory!  (allocating %lu bytes)"), size);
    }
}

void vim_strcat (char_u *to, char_u *from, size_t tosize) {
    size_t tolen = STRLEN (to);
    size_t fromlen = STRLEN (from);
    if (tolen + fromlen + 1 > tosize) {
        mch_memmove (to + tolen, from, tosize - tolen - 1);
        to[tosize - 1] = NUL;
    }
    else
        mch_memmove (to +tolen, from, fromlen +1);
}

char_u *vim_strnsave_up (char_u *string, int len) {
    char_u *p1;
    p1 = vim_strnsave (string, len);
    vim_strup (p1);
    return p1;
}

char_u *get_special_key_name (int c, int modifiers) {
    static char_u string [MAX_KEY_NAME_LEN + 1];
    int i, idx;
    int table_idx;
    char_u *s;
    string[0] = '<';
    idx = 1;
    if (IS_SPECIAL (c) && KEY2TERMCAP0 (c) == KS_KEY)
        c = KEY2TERMCAP1 (c);
    if (IS_SPECIAL (c)) {
        for (i = 0; modifier_keys_table[i] != 0; i += MOD_KEYS_ENTRY_SIZE)
            if (KEY2TERMCAP0 (c) == (int) modifier_keys_table[i + 1] && (int) KEY2TERMCAP1 (c) == (int) modifier_keys_table[i + 2]) {
                modifiers |= modifier_keys_table[i];
                c = TERMCAP2KEY (modifier_keys_table[i + 3], modifier_keys_table[i + 4]);
                break;
            }
    }
    table_idx = find_special_key_in_table (c);
    if (c > 0) {
        if (table_idx < 0 && (!vim_isprintc (c) || (c & 0x7f) == ' ') && (c & 0x80)) {
            c &= 0x7f;
            modifiers |= MOD_MASK_ALT;
            table_idx = find_special_key_in_table (c);
        }
        if (table_idx < 0 && !vim_isprintc (c) && c < ' ') {
            c += '@';
            modifiers |= MOD_MASK_CTRL;
        }
    }
    for (i = 0; mod_mask_table[i].name != 'A'; i++)
        if ((modifiers & mod_mask_table[i].mod_mask) == mod_mask_table[i].mod_flag) {
            string[idx++] = mod_mask_table[i].name;
            string[idx++] = (char_u) '-';
        }
    if (table_idx < 0) {
        if (IS_SPECIAL (c)) {
            string[idx++] = 't';
            string[idx++] = '_';
            string[idx++] = KEY2TERMCAP0 (c);
            string[idx++] = KEY2TERMCAP1 (c);
        }
        else {
            if (vim_isprintc (c))
                string[idx++] = c;
            else {
                s = transchar (c);
                while (*s)
                    string[idx++] = *s++;
            }
        }
    }
    else {
        size_t len = STRLEN (key_names_table[table_idx].name);
        if (len + idx + 2 <= MAX_KEY_NAME_LEN) {
            STRCPY (string + idx, key_names_table [table_idx].name);
            idx += (int) len;
        }
    }
    string[idx++] = '>';
    string[idx] = NUL;
    return string;
}

int find_special_key_in_table (int c) {
    int i;
    for (i = 0; key_names_table[i].name != NULL; i++)
        if (c == key_names_table[i].key)
            break;
    if (key_names_table[i].name == NULL)
        i = -1;
    return i;
}

int get4c (FILE *fd) {
    unsigned  n;
    n = (unsigned ) getc (fd);
    n = (n << 8) + (unsigned ) getc (fd);
    n = (n << 8) + (unsigned ) getc (fd);
    n = (n << 8) + (unsigned ) getc (fd);
    return (int) n;
}

char_u *read_string (FILE *fd, int cnt) {
    char_u *str;
    int i;
    int c;
    str = alloc ((unsigned ) cnt + 1);
    if (str != NULL) {
        for (i = 0; i < cnt; ++i) {
            c = getc (fd);
            if (c == EOF) {
                vim_free (str);
                return NULL;
            }
            str[i] = c;
        }
        str[i] = NUL;
    }
    return str;
}

int get2c (FILE *fd) {
    int n;
    n = getc (fd);
    n = (n << 8) + getc (fd);
    return n;
}

time_T get8ctime (FILE *fd) {
    time_T n = 0;
    int i;
    for (i = 0; i < 8; ++i)
        n = (n << 8) + getc (fd);
    return n;
}

int get3c (FILE *fd) {
    int n;
    n = getc (fd);
    n = (n << 8) + getc (fd);
    n = (n << 8) + getc (fd);
    return n;
}

void set_fileformat (int t, int opt_flags) {
    char *p = NULL;
    switch (t) {
    case EOL_DOS :
        p = FF_DOS;
        curbuf->b_p_tx = TRUE;
        break;
    case EOL_UNIX :
        p = FF_UNIX;
        curbuf->b_p_tx = FALSE;
        break;
    case EOL_MAC :
        p = FF_MAC;
        curbuf->b_p_tx = FALSE;
        break;
    }
    if (p != NULL)
        set_string_option_direct ((char_u *) "ff", -1, (char_u *) p, OPT_FREE | opt_flags, 0);
    check_status (curbuf);
    redraw_tabline = TRUE;
    need_maketitle = TRUE;
}

int get_pseudo_mouse_code (int button, int is_click, int is_drag) {
    int i;
    for (i = 0; mouse_table[i].pseudo_code; i++)
        if (button == mouse_table[i].button && is_click == mouse_table[i].is_click && is_drag == mouse_table[i].is_drag) {
            if (mouse_col < 0 || mouse_col > MOUSE_COLOFF) {
                if (mouse_col < 0)
                    mouse_col = 0;
                else
                    mouse_col -= MOUSE_COLOFF;
                if (mouse_table[i].pseudo_code == (int) KE_LEFTMOUSE)
                    return (int) KE_LEFTMOUSE_NM;
                if (mouse_table[i].pseudo_code == (int) KE_LEFTRELEASE)
                    return (int) KE_LEFTRELEASE_NM;
            }
            return mouse_table[i].pseudo_code;
        }
    return (int) KE_IGNORE;
}

int dec_cursor (void) {
    return dec (&curwin->w_cursor);
}

int dec (pos_T *lp) {
    char_u *p;
    lp->coladd = 0;
    if (lp->col == MAXCOL) {
        p = ml_get (lp->lnum);
        lp->col = (colnr_T) STRLEN (p);
        return 0;
    }
    if (lp->col > 0) {
        lp->col--;
        return 0;
    }
    if (lp->lnum > 1) {
        lp->lnum--;
        p = ml_get (lp->lnum);
        lp->col = (colnr_T) STRLEN (p);
        return 1;
    }
    return -1;
}

int get_fileformat_force (buf_T *buf, exarg_T *eap) {
    int c;
    if (eap != NULL && eap->force_ff != 0)
        c = eap->cmd[eap->force_ff];
    else {
        if ((eap != NULL && eap->force_bin != 0) ? (eap->force_bin == FORCE_BIN) : buf->b_p_bin)
            return EOL_UNIX;
        c = *buf->b_p_ff;
    }
    if (c == 'u')
        return EOL_UNIX;
    if (c == 'm')
        return EOL_MAC;
    return EOL_DOS;
}

int put_bytes (FILE *fd, long_u nr, int len) {
    int i;
    for (i = len - 1; i >= 0; --i)
        if (putc ((int) (nr >> (i * 8)), fd) == EOF)
            return FAIL;
    return OK;
}

int put_time (FILE *fd, time_T the_time) {
    char_u buf [8];
    time_to_bytes (the_time, buf);
    return fwrite (buf, (size_t) 8, (size_t) 1, fd) == 1 ? OK : FAIL;
}

int default_fileformat (void) {
    switch (*p_ffs) {
    case 'm' :
        return EOL_MAC;
    case 'd' :
        return EOL_DOS;
    }
    return EOL_UNIX;
}

int getviscol (void) {
    colnr_T x;
    getvvcol (curwin, & curwin -> w_cursor, & x, NULL, NULL);
    return (int) x;
}

int vim_chdirfile (char_u *fname, char *trigger_autocmd) {
    char_u dir [MAXPATHL];
    int res;
    vim_strncpy (dir, fname, MAXPATHL - 1);
    *gettail_sep (dir) = NUL;
    res = mch_chdir ((char *) dir) == 0 ? OK : FAIL;
    if (res == OK && trigger_autocmd != NULL)
        apply_autocmds (EVENT_DIRCHANGED, (char_u *) trigger_autocmd, dir, FALSE, curbuf);
    return res;
}

int inc_cursor (void) {
    return inc (&curwin->w_cursor);
}

int inc (pos_T *lp) {
    char_u *p;
    if (lp->col != MAXCOL) {
        p = ml_get_pos (lp);
        if (*p != NUL) {
            lp->col++;
            lp->coladd = 0;
            return ((p[1] != NUL) ? 0 : 2);
        }
    }
    if (lp->lnum != curbuf->b_ml.ml_line_count) {
        lp->col = 0;
        lp->lnum++;
        lp->coladd = 0;
        return 1;
    }
    return -1;
}

int coladvance_force (colnr_T wcol) {
    int rc = coladvance2 (&curwin->w_cursor, TRUE, FALSE, wcol);
    if (wcol == MAXCOL)
        curwin->w_valid &= ~VALID_VIRTCOL;
    else {
        curwin->w_valid |= VALID_VIRTCOL;
        curwin->w_virtcol = wcol;
    }
    return rc;
}

char_u *alloc_check (unsigned  size) {
    return (lalloc ((long_u) size, TRUE));
}

int get_mouse_button (int code, int *is_click, int *is_drag) {
    int i;
    for (i = 0; mouse_table[i].pseudo_code; i++)
        if (code == mouse_table[i].pseudo_code) {
            *is_click = mouse_table[i].is_click;
            *is_drag = mouse_table[i].is_drag;
            return mouse_table[i].button;
        }
    return 0;
}

char_u *vim_strsave_escaped (char_u *string, char_u *esc_chars) {
    return vim_strsave_escaped_ext (string, esc_chars, '\\', FALSE);
}

char_u *vim_strsave_escaped_ext (char_u *string, char_u *esc_chars, int cc, int bsl) {
    char_u *p;
    char_u *p2;
    char_u *escaped_string;
    unsigned  length;
    length = 1;
    for (p = string; *p; p++) {
        if (vim_strchr (esc_chars, *p) != NULL || (bsl && rem_backslash (p)))
            ++length;
        ++length;
    }
    escaped_string = alloc (length);
    if (escaped_string != NULL) {
        p2 = escaped_string;
        for (p = string; *p; p++) {
            if (vim_strchr (esc_chars, *p) != NULL || (bsl && rem_backslash (p)))
                *p2++ = cc;
            *p2++ = *p;
        }
        *p2 = NUL;
    }
    return escaped_string;
}

char_u *get_key_name (int i) {
    if (i >= (int) KEY_NAMES_TABLE_LEN)
        return NULL;
    return key_names_table[i].name;
}

void sort_strings (char_u **files, int count) {
    qsort ((void *) files, (size_t) count, sizeof (char_u *), sort_compare);
}

static int sort_compare (const void *s1, const void *s2) {
    return STRCMP (*(char**) s1, *(char**) s2);
}

int decl (pos_T *lp) {
    int r;
    if ((r = dec (lp)) == 1 && lp->col)
        r = dec (lp);
    return r;
}

int incl (pos_T *lp) {
    int r;
    if ((r = inc (lp)) >= 1 && lp->col)
        r = inc (lp);
    return r;
}

int getviscol2 (colnr_T col, colnr_T coladd) {
    colnr_T x;
    pos_T pos;
    pos.lnum = curwin->w_cursor.lnum;
    pos.col = col;
    pos.coladd = coladd;
    getvvcol (curwin, & pos, & x, NULL, NULL);
    return (int) x;
}

char_u *vim_strsave_shellescape (char_u *string, int do_special, int do_newline) {
    unsigned  length;
    char_u *p;
    char_u *d;
    char_u *escaped_string;
    int l;
    int csh_like;
    csh_like = csh_like_shell ();
    length = (unsigned ) STRLEN (string) + 3;
    for (p = string; *p != NUL; MB_PTR_ADV (p)) {
        if (*p == '\'')
            length += 3;
        if ((*p == '\n' && (csh_like || do_newline)) || (*p == '!' && (csh_like || do_special))) {
            ++length;
            if (csh_like && do_special)
                ++length;
        }
        if (do_special && find_cmdline_var (p, &l) >= 0) {
            ++length;
            p += l - 1;
        }
    }
    escaped_string = alloc (length);
    if (escaped_string != NULL) {
        d = escaped_string;
        *d++ = '\'';
        for (p = string; *p != NUL;) {
            if (*p == '\'') {
                *d++ = '\'';
                *d++ = '\\';
                *d++ = '\'';
                *d++ = '\'';
                ++p;
                continue;
            }
            if ((*p == '\n' && (csh_like || do_newline)) || (*p == '!' && (csh_like || do_special))) {
                *d++ = '\\';
                if (csh_like && do_special)
                    *d++ = '\\';
                *d++ = *p++;
                continue;
            }
            if (do_special && find_cmdline_var (p, &l) >= 0) {
                *d++ = '\\';
                while (--l >= 0)
                    *d++ = *p++;
                continue;
            }
            MB_COPY_CHAR (p, d);
        }
        *d++ = '\'';
        *d = NUL;
    }
    return escaped_string;
}

int csh_like_shell (void) {
    return (strstr ((char *) gettail (p_sh), "csh") != NULL);
}

int get_user_name (char_u *buf, int len) {
    if (username == NULL) {
        if (mch_get_user_name (buf, len) == FAIL)
            return FAIL;
        username = vim_strsave (buf);
    }
    else
        vim_strncpy (buf, username, len -1);
    return OK;
}

int call_shell (char_u *cmd, int opt) {
    char_u *ncmd;
    int retval;
    proftime_T wait_time;
    if (p_verbose > 3) {
        verbose_enter ();
        smsg ((char_u *) _ ("Calling shell to execute: \"%s\""), cmd == NULL ? p_sh : cmd);
        out_char ('\n');
        cursor_on ();
        verbose_leave ();
    }
    if (do_profiling == PROF_YES)
        prof_child_enter (&wait_time);
    if (*p_sh == NUL) {
        EMSG (_ (e_shellempty));
        retval = -1;
    }
    else {
        ++hold_gui_events;
        tag_freematch ();
        if (cmd == NULL || *p_sxq == NUL)
            retval = mch_call_shell (cmd, opt);
        else {
            char_u *ecmd = cmd;
            if (*p_sxe != NUL && STRCMP (p_sxq, "(") == 0) {
                ecmd = vim_strsave_escaped_ext (cmd, p_sxe, '^', FALSE);
                if (ecmd == NULL)
                    ecmd = cmd;
            }
            ncmd = alloc ((unsigned ) (STRLEN (ecmd) + STRLEN (p_sxq) * 2 + 1));
            if (ncmd != NULL) {
                STRCPY (ncmd, p_sxq);
                STRCAT (ncmd, ecmd);
                STRCAT (ncmd, STRCMP (p_sxq, "(") == 0 ? (char_u *) ")" : STRCMP (p_sxq, "\"(") == 0 ? (char_u *) ")\"" : p_sxq);
                retval = mch_call_shell (ncmd, opt);
                vim_free (ncmd);
            }
            else
                retval = -1;
            if (ecmd != cmd)
                vim_free (ecmd);
        }
        --hold_gui_events;
        shell_resized_check ();
    }
    set_vim_var_nr (VV_SHELL_ERROR, (long) retval);
    if (do_profiling == PROF_YES)
        prof_child_exit (&wait_time);
    return retval;
}

