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
struct buffblock {
    buffblock_T *b_next;
    char_u b_str [1];
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
struct buffheader {
    buffblock_T bh_first;
    buffblock_T *bh_curr;
    int bh_index;
    int bh_space;
};
EXTERN char_u *p_isp;
EXTERN char_u *p_isi;
EXTERN char_u *p_isf;
EXTERN char_u *p_sel;
EXTERN char_u *p_sbr;
EXTERN int p_altkeymap;
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
char_u g_chartab [256];
int chartab_initialized = FALSE;
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
char_u transchar_buf [7];
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

char_u *skiphex (char_u *q) {
    char_u *p = q;
    while (vim_isxdigit (*p))
        ++p;
    return p;
}

int vim_isxdigit (int c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

char_u *skipdigits (char_u *q) {
    char_u *p = q;
    while (VIM_ISDIGIT (*p))
        ++p;
    return p;
}

char_u *skipwhite (char_u *q) {
    char_u *p = q;
    while (VIM_ISWHITE (*p))
        ++p;
    return p;
}

int vim_isIDc (int c) {
    return (c > 0 && c < 0x100 && (g_chartab[c] & CT_ID_CHAR));
}

int vim_isfilec (int c) {
    return (c >= 0x100 || (c > 0 && (g_chartab[c] & CT_FNAME_CHAR)));
}

int rem_backslash (char_u *str) {
    return (str[0] == '\\' && str[1] != NUL);
}

int ptr2cells (char_u *p) {
    return (g_chartab[*p] & CT_CELL_MASK);
}

char_u *transchar (int c) {
    int i;
    i = 0;
    if (IS_SPECIAL (c)) {
        transchar_buf[0] = '~';
        transchar_buf[1] = '@';
        i = 2;
        c = K_SECOND (c);
    }
    if ((!chartab_initialized && ((c >= ' ' && c <= '~') || (p_altkeymap && F_ischar (c)))) || (c < 256 && vim_isprintc_strict (c))) {
        transchar_buf[i] = c;
        transchar_buf[i + 1] = NUL;
    }
    else
        transchar_nonprint (transchar_buf +i, c);
    return transchar_buf;
}

int vim_isprintc_strict (int c) {
    return (c >= 0x100 || (c > 0 && (g_chartab[c] & CT_PRINT_CHAR)));
}

void transchar_nonprint (char_u *buf, int c) {
    if (c == NL)
        c = NUL;
    else if (c == CAR && get_fileformat (curbuf) == EOL_MAC)
        c = NL;
    if (dy_flags & DY_UHEX)
        transchar_hex (buf, c);
    else if (c <= 0x7f) {
        buf[0] = '^';
        buf[1] = c ^ 0x40;
        buf[2] = NUL;
    }
    else if (c >= ' ' + 0x80 && c <= '~' + 0x80) {
        buf[0] = '|';
        buf[1] = c - 0x80;
        buf[2] = NUL;
    }
    else {
        buf[0] = '~';
        buf[1] = (c - 0x80) ^ 0x40;
        buf[2] = NUL;
    }
}

void transchar_hex (char_u *buf, int c) {
    int i = 0;
    buf[0] = '<';
    buf[++i] = nr2hex ((unsigned ) c >> 4);
    buf[++i] = nr2hex ((unsigned ) c);
    buf[++i] = '>';
    buf[++i] = NUL;
}

static unsigned  nr2hex (unsigned  c) {
    if ((c & 0xf) <= 9)
        return (c & 0xf) + '0';
    return (c & 0xf) - 10 + 'a';
}

long  getdigits (char_u **pp) {
    char_u *p;
    long  retval;
    p = *pp;
    retval = atol ((char *) p);
    if (*p == '-')
        ++p;
    p = skipdigits (p);
    *pp = p;
    return retval;
}

void vim_str2nr (char_u *start, int *prep, int *len, int what, varnumber_T *nptr, uvarnumber_T *unptr, int maxlen) {
    char_u *ptr = start;
    int pre = 0;
    int negative = FALSE;
    uvarnumber_T un = 0;
    int n;
    if (ptr[0] == '-') {
        negative = TRUE;
        ++ptr;
    }
    if (ptr[0] == '0' && ptr[1] != '8' && ptr[1] != '9' && (maxlen == 0 || maxlen > 1)) {
        pre = ptr[1];
        if ((what & STR2NR_HEX) && (pre == 'X' || pre == 'x') && vim_isxdigit (ptr[2]) && (maxlen == 0 || maxlen > 2))
            ptr += 2;
        else if ((what & STR2NR_BIN) && (pre == 'B' || pre == 'b') && vim_isbdigit (ptr[2]) && (maxlen == 0 || maxlen > 2))
            ptr += 2;
        else {
            pre = 0;
            if (what & STR2NR_OCT) {
                for (n = 1; n != maxlen && VIM_ISDIGIT (ptr[n]); ++n) {
                    if (ptr[n] > '7') {
                        pre = 0;
                        break;
                    }
                    pre = '0';
                }
            }
        }
    }
    n = 1;
    if (pre == 'B' || pre == 'b' || what == STR2NR_BIN + STR2NR_FORCE) {
        if (pre != 0)
            n += 2;
        while ('0' <= *ptr && *ptr <= '1') {
            if (un < UVARNUM_MAX / 2)
                un = 2 * un + (unsigned  long ) (*ptr - '0');
            else
                un = UVARNUM_MAX;
            ++ptr;
            if (n++ == maxlen)
                break;
        }
    }
    else if (pre == '0' || what == STR2NR_OCT + STR2NR_FORCE) {
        while ('0' <= *ptr && *ptr <= '7') {
            if (un < UVARNUM_MAX / 8)
                un = 8 * un + (uvarnumber_T) (*ptr - '0');
            else
                un = UVARNUM_MAX;
            ++ptr;
            if (n++ == maxlen)
                break;
        }
    }
    else if (pre != 0 || what == STR2NR_HEX + STR2NR_FORCE) {
        if (pre != 0)
            n += 2;
        while (vim_isxdigit (*ptr)) {
            if (un < UVARNUM_MAX / 16)
                un = 16 * un + (uvarnumber_T) hex2nr (*ptr);
            else
                un = UVARNUM_MAX;
            ++ptr;
            if (n++ == maxlen)
                break;
        }
    }
    else {
        while (VIM_ISDIGIT (*ptr)) {
            if (un < UVARNUM_MAX / 10)
                un = 10 * un + (uvarnumber_T) (*ptr - '0');
            else
                un = UVARNUM_MAX;
            ++ptr;
            if (n++ == maxlen)
                break;
        }
    }
    if (prep != NULL)
        *prep = pre;
    if (len != NULL)
        *len = (int) (ptr - start);
    if (nptr != NULL) {
        if (negative) {
            if (un > VARNUM_MAX)
                *nptr = VARNUM_MIN;
            else
                *nptr = -(varnumber_T)un;
        }
        else {
            if (un > VARNUM_MAX)
                un = VARNUM_MAX;
            *nptr = (varnumber_T) un;
        }
    }
    if (unptr != NULL)
        *unptr = un;
}

int hex2nr (int c) {
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return c - '0';
}

int vim_isdigit (int c) {
    return (c >= '0' && c <= '9');
}

void getvvcol (win_T *wp, pos_T *pos, colnr_T *start, colnr_T *cursor, colnr_T *end) {
    colnr_T col;
    colnr_T coladd;
    colnr_T endadd;
    if (virtual_active ()) {
        getvcol (wp, pos, & col, NULL, NULL);
        coladd = pos->coladd;
        endadd = 0;
        col += coladd;
        if (start != NULL)
            *start = col;
        if (cursor != NULL)
            *cursor = col;
        if (end != NULL)
            *end = col + endadd;
    }
    else
        getvcol (wp, pos, start, cursor, end);
}

void getvcol (win_T *wp, pos_T *pos, colnr_T *start, colnr_T *cursor, colnr_T *end) {
    colnr_T vcol;
    char_u *ptr;
    char_u *posptr;
    char_u *line;
    int incr;
    int head;
    int ts = wp->w_buffer->b_p_ts;
    int c;
    vcol = 0;
    line = ptr = ml_get_buf (wp->w_buffer, pos->lnum, FALSE);
    if (pos->col == MAXCOL)
        posptr = NULL;
    else {
        if (*ptr == NUL)
            pos->col = 0;
        posptr = ptr + pos->col;
    }
    if ((!wp->w_p_list || lcs_tab1 != NUL) && !wp->w_p_lbr && *p_sbr == NUL && !wp->w_p_bri) {
        head = 0;
        for (;;) {
            c = *ptr;
            if (c == NUL) {
                incr = 1;
                break;
            }
            if (c == TAB)
                incr = ts - (vcol % ts);
            else {
                incr = g_chartab[c] & CT_CELL_MASK;
            }
            if (posptr != NULL && ptr >= posptr)
                break;
            vcol += incr;
            MB_PTR_ADV (ptr);
        }
    }
    else {
        for (;;) {
            head = 0;
            incr = win_lbr_chartabsize (wp, line, ptr, vcol, &head);
            if (*ptr == NUL) {
                incr = 1;
                break;
            }
            if (posptr != NULL && ptr >= posptr)
                break;
            vcol += incr;
            MB_PTR_ADV (ptr);
        }
    }
    if (start != NULL)
        *start = vcol + head;
    if (end != NULL)
        *end = vcol + incr - 1;
    if (cursor != NULL) {
        if (*ptr == TAB && (State & NORMAL) && !wp->w_p_list && !virtual_active () && !(VIsual_active && (*p_sel == 'e' || LTOREQ_POS (*pos, VIsual))))
            *cursor = vcol + incr - 1;
        else
            *cursor = vcol + head;
    }
}

int win_lbr_chartabsize (win_T *wp, char_u *line, char_u *s, colnr_T col, int *headp) {
    int c;
    int size;
    colnr_T col2;
    colnr_T col_adj = 0;
    colnr_T colmax;
    int added;

    #  define mb_added 0
    int numberextra;
    char_u *ps;
    int tab_corr = (*s == TAB);
    int n;
    if (!wp->w_p_lbr && !wp->w_p_bri && *p_sbr == NUL) {
        RET_WIN_BUF_CHARTABSIZE (wp, wp -> w_buffer, s, col)
    }
    size = win_chartabsize (wp, s, col);
    c = *s;
    if (tab_corr)
        col_adj = size - 1;
    if (wp->w_p_lbr && VIM_ISBREAK (c) && !VIM_ISBREAK ((int) s[1]) && wp->w_p_wrap && wp->w_width != 0) {
        numberextra = win_col_off (wp);
        col2 = col;
        colmax = (colnr_T) (wp->w_width - numberextra - col_adj);
        if (col >= colmax) {
            colmax += col_adj;
            n = colmax + win_col_off2 (wp);
            if (n > 0)
                colmax += (((col - colmax) / n) + 1) * n - col_adj;
        }
        for (;;) {
            ps = s;
            MB_PTR_ADV (s);
            c = *s;
            if (!(c != NUL && (VIM_ISBREAK (c) || (!VIM_ISBREAK (c) && (col2 == col || !VIM_ISBREAK ((int) *ps))))))
                break;
            col2 += win_chartabsize (wp, s, col2);
            if (col2 >= colmax) {
                size = colmax - col + col_adj;
                tab_corr = FALSE;
                break;
            }
        }
    }
    added = 0;
    if ((*p_sbr != NUL || wp->w_p_bri) && wp->w_p_wrap && col != 0) {
        colnr_T sbrlen = 0;
        int numberwidth = win_col_off (wp);
        numberextra = numberwidth;
        col += numberextra + mb_added;
        if (col >= (colnr_T) wp->w_width) {
            col -= wp->w_width;
            numberextra = wp->w_width - (numberextra - win_col_off2 (wp));
            if (col >= numberextra && numberextra > 0)
                col %= numberextra;
            if (*p_sbr != NUL) {
                sbrlen = (colnr_T) MB_CHARLEN (p_sbr);
                if (col >= sbrlen)
                    col -= sbrlen;
            }
            if (col >= numberextra && numberextra > 0)
                col = col % numberextra;
            else if (col > 0 && numberextra > 0)
                col += numberwidth - win_col_off2 (wp);
            numberwidth -= win_col_off2 (wp);
        }
        if (col == 0 || col + size + sbrlen > (colnr_T) wp->w_width) {
            added = 0;
            if (*p_sbr != NUL) {
                if (size + sbrlen + numberwidth > (colnr_T) wp->w_width) {
                    int width = (colnr_T) wp->w_width - sbrlen - numberwidth;
                    int prev_width = col ? ((colnr_T) wp->w_width - (sbrlen + col)) : 0;
                    if (width == 0)
                        width = (colnr_T) wp->w_width;
                    added += ((size - prev_width) / width) * vim_strsize (p_sbr);
                    if ((size - prev_width) % width)
                        added += vim_strsize (p_sbr);
                }
                else
                    added += vim_strsize (p_sbr);
            }
            if (wp->w_p_bri)
                added += get_breakindent_win (wp, line);
            size += added;
            if (col != 0)
                added = 0;
        }
    }
    if (headp != NULL)
        *headp = added + mb_added;
    return size;
}

static int win_chartabsize (win_T *wp, char_u *p, colnr_T col) {
    RET_WIN_BUF_CHARTABSIZE (wp, wp -> w_buffer, p, col)
}

int vim_strsize (char_u *s) {
    return vim_strnsize (s, (int) MAXCOL);
}

int vim_strnsize (char_u *s, int len) {
    int size = 0;
    while (*s != NUL && --len >= 0) {
        size += byte2cells (*s++);
    }
    return size;
}

#define RET_WIN_BUF_CHARTABSIZE(wp, buf, p, col) if (*(p) == TAB && (!(wp)->w_p_list || lcs_tab1)) { int ts; ts = (buf)->b_p_ts; return (int)(ts - (col % ts)); } else return ptr2cells(p);

int byte2cells (int b) {
    return (g_chartab[b] & CT_CELL_MASK);
}

int linetabsize (char_u *s) {
    return linetabsize_col (0, s);
}

int linetabsize_col (int startcol, char_u *s) {
    colnr_T col = startcol;
    char_u *line = s;
    while (*s != NUL)
        col += lbr_chartabsize_adv (line, &s, col);
    return (int) col;
}

int lbr_chartabsize_adv (char_u *line, char_u **s, colnr_T col) {
    int retval;
    retval = lbr_chartabsize (line, *s, col);
    MB_PTR_ADV (*s);
    return retval;
}

int lbr_chartabsize (char_u *line, unsigned  char *s, colnr_T col) {
    if (!curwin->w_p_lbr && *p_sbr == NUL && !curwin->w_p_bri) {
        RET_WIN_BUF_CHARTABSIZE (curwin, curbuf, s, col)
    }
    return win_lbr_chartabsize (curwin, line == NULL ? s : line, s, col, NULL);
}

int vim_isprintc (int c) {
    return (c >= 0x100 || (c > 0 && (g_chartab[c] & CT_PRINT_CHAR)));
}

int vim_iswordc (int c) {
    return vim_iswordc_buf (c, curbuf);
}

int vim_iswordc_buf (int c, buf_T *buf) {
    if (c >= 0x100) {
        return FALSE;
    }
    return (c > 0 && GET_CHARTAB (buf, c) != 0);
}

int init_chartab (void) {
    return buf_init_chartab (curbuf, TRUE);
}

int buf_init_chartab (buf_T *buf, int global) {
    int c;
    int c2;
    char_u *p;
    int i;
    int tilde;
    int do_isalpha;
    if (global) {
        c = 0;
        while (c < ' ')
            g_chartab[c++] = (dy_flags & DY_UHEX) ? 4 : 2;
        while (c <= '~')
            g_chartab[c++] = 1 + CT_PRINT_CHAR;
        if (p_altkeymap) {
            while (c < YE)
                g_chartab[c++] = 1 + CT_PRINT_CHAR;
        }
        while (c < 256) {
            g_chartab[c++] = (dy_flags & DY_UHEX) ? 4 : 2;
        }
    }
    vim_memset (buf -> b_chartab, 0, (size_t) 32);
    if (buf->b_p_lisp)
        SET_CHARTAB (buf, '-');
    for (i = global ? 0 : 3; i <= 3; ++i) {
        if (i == 0)
            p = p_isi;
        else if (i == 1)
            p = p_isp;
        else if (i == 2)
            p = p_isf;
        else
            p = buf->b_p_isk;
        while (*p) {
            tilde = FALSE;
            do_isalpha = FALSE;
            if (*p == '^' && p[1] != NUL) {
                tilde = TRUE;
                ++p;
            }
            if (VIM_ISDIGIT (*p))
                c = getdigits (&p);
            else
                c = *p++;
            c2 = -1;
            if (*p == '-' && p[1] != NUL) {
                ++p;
                if (VIM_ISDIGIT (*p))
                    c2 = getdigits (&p);
                else
                    c2 = *p++;
            }
            if (c <= 0 || c >= 256 || (c2 < c && c2 != -1) || c2 >= 256 || !(*p == NUL || *p == ','))
                return FAIL;
            if (c2 == -1) {
                if (c == '@') {
                    do_isalpha = TRUE;
                    c = 1;
                    c2 = 255;
                }
                else
                    c2 = c;
            }
            while (c <= c2) {
                if (!do_isalpha || MB_ISLOWER (c) || MB_ISUPPER (c) || (p_altkeymap && (F_isalpha (c) || F_isdigit (c)))) {
                    if (i == 0) {
                        if (tilde)
                            g_chartab[c] &= ~CT_ID_CHAR;
                        else
                            g_chartab[c] |= CT_ID_CHAR;
                    }
                    else if (i == 1) {
                        if ((c < ' ' || c > '~' || (p_altkeymap && (F_isalpha (c) || F_isdigit (c))))) {
                            if (tilde) {
                                g_chartab[c] = (g_chartab[c] & ~CT_CELL_MASK) + ((dy_flags & DY_UHEX) ? 4 : 2);
                                g_chartab[c] &= ~CT_PRINT_CHAR;
                            }
                            else {
                                g_chartab[c] = (g_chartab[c] & ~CT_CELL_MASK) + 1;
                                g_chartab[c] |= CT_PRINT_CHAR;
                            }
                        }
                    }
                    else if (i == 2) {
                        if (tilde)
                            g_chartab[c] &= ~CT_FNAME_CHAR;
                        else
                            g_chartab[c] |= CT_FNAME_CHAR;
                    }
                    else {
                        if (tilde)
                            RESET_CHARTAB (buf, c);
                        else
                            SET_CHARTAB (buf, c);
                    }
                }
                ++c;
            }
            c = *p;
            p = skip_to_option_part (p);
            if (c == ',' && *p == NUL)
                return FAIL;
        }
    }
    chartab_initialized = TRUE;
    return OK;
}

void trans_characters (char_u *buf, int bufsize) {
    int len;
    int room;
    char_u *trs;
    int trs_len;
    len = (int) STRLEN (buf);
    room = bufsize - len;
    while (*buf != 0) {
        {
            trs = transchar_byte (*buf);
            trs_len = (int) STRLEN (trs);
            if (trs_len > 1) {
                room -= trs_len - 1;
                if (room <= 0)
                    return;
                mch_memmove (buf + trs_len, buf + 1, (size_t) len);
            }
            mch_memmove (buf, trs, (size_t) trs_len);
            --len;
        }
        buf += trs_len;
    }
}

char_u *transstr (char_u *s) {
    char_u *res;
    char_u *p;
    res = alloc ((unsigned ) (vim_strsize (s) + 1));
    if (res != NULL) {
        *res = NUL;
        p = s;
        while (*p != NUL) {
            STRCAT (res, transchar_byte (* p ++));
        }
    }
    return res;
}

int win_linetabsize (win_T *wp, char_u *line, colnr_T len) {
    colnr_T col = 0;
    char_u *s;
    for (s = line; *s != NUL && (len == MAXCOL || s < line + len); MB_PTR_ADV (s))
        col += win_lbr_chartabsize (wp, line, s, col, NULL);
    return (int) col;
}

int chartabsize (char_u *p, colnr_T col) {
    RET_WIN_BUF_CHARTABSIZE (curwin, curbuf, p, col)
}

void getvcols (win_T *wp, pos_T *pos1, pos_T *pos2, colnr_T *left, colnr_T *right) {
    colnr_T from1, from2, to1, to2;
    if (LT_POSP (pos1, pos2)) {
        getvvcol (wp, pos1, & from1, NULL, & to1);
        getvvcol (wp, pos2, & from2, NULL, & to2);
    }
    else {
        getvvcol (wp, pos2, & from1, NULL, & to1);
        getvvcol (wp, pos1, & from2, NULL, & to2);
    }
    if (from2 < from1)
        *left = from2;
    else
        *left = from1;
    if (to2 > to1) {
        if (*p_sel == 'e' && from2 - 1 >= to1)
            *right = from2 - 1;
        else
            *right = to2;
    }
    else
        *right = to1;
}

int vim_iswordp_buf (char_u *p, buf_T *buf) {
    int c = *p;
    return vim_iswordc_buf (c, buf);
}

char_u *str_foldcase (char_u *str, int orglen, char_u *buf, int buflen) {
    garray_T ga;
    int i;
    int len = orglen;

    #define GA_CHAR(i)  ((char_u *)ga.ga_data)[i]

    #define GA_PTR(i)   ((char_u *)ga.ga_data + i)

    #define STR_CHAR(i)  (buf == NULL ? GA_CHAR(i) : buf[i])

    #define STR_PTR(i)   (buf == NULL ? GA_PTR(i) : buf + i)
    if (buf == NULL) {
        ga_init2 (& ga, 1, 10);
        if (ga_grow (&ga, len +1) == FAIL)
            return NULL;
        mch_memmove (ga.ga_data, str, (size_t) len);
        ga.ga_len = len;
    }
    else {
        if (len >= buflen)
            len = buflen - 1;
        mch_memmove (buf, str, (size_t) len);
    }
    if (buf == NULL)
        GA_CHAR (len) = NUL;
    else
        buf[len] = NUL;
    i = 0;
    while (STR_CHAR (i) != NUL) {
        {
            if (buf == NULL)
                GA_CHAR (i) = TOLOWER_LOC (GA_CHAR (i));
            else
                buf[i] = TOLOWER_LOC (buf[i]);
            ++i;
        }
    }
    if (buf == NULL)
        return (char_u *) ga.ga_data;
    return buf;
}

int char2cells (int c) {
    if (IS_SPECIAL (c))
        return char2cells (K_SECOND (c)) + 2;
    return (g_chartab[c & 0xff] & CT_CELL_MASK);
}

char_u *skiptowhite (char_u *p) {
    while (*p != ' ' && *p != '\t' && *p != NUL)
        ++p;
    return p;
}

int hexhex2nr (char_u *p) {
    if (!vim_isxdigit (p[0]) || !vim_isxdigit (p[1]))
        return -1;
    return (hex2nr (p[0]) << 4) + hex2nr (p[1]);
}

colnr_T getvcol_nolist (pos_T *posp) {
    int list_save = curwin->w_p_list;
    colnr_T vcol;
    curwin->w_p_list = FALSE;
    getvcol (curwin, posp, NULL, & vcol, NULL);
    curwin->w_p_list = list_save;
    return vcol;
}

int vim_isfilec_or_wc (int c) {
    char_u buf [2];
    buf[0] = (char_u) c;
    buf[1] = NUL;
    return vim_isfilec (c) || c == ']' || mch_has_wildcard (buf);
}

int vim_isblankline (char_u *lbuf) {
    char_u *p;
    p = skipwhite (lbuf);
    return (*p == NUL || *p == '\r' || *p == '\n');
}

char_u *backslash_halve_save (char_u *p) {
    char_u *res;
    res = vim_strsave (p);
    if (res == NULL)
        return p;
    backslash_halve (res);
    return res;
}

void backslash_halve (char_u *p) {
    for (; *p; ++p)
        if (rem_backslash (p))
            STRMOVE (p, p +1);
}

char_u *skiptowhite_esc (char_u *p) {
    while (*p != ' ' && *p != '\t' && *p != NUL) {
        if ((*p == '\\' || *p == Ctrl_V) && *(p + 1) != NUL)
            ++p;
        ++p;
    }
    return p;
}

