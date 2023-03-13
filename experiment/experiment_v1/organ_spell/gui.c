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
EXTERN int p_mousef;
EXTERN vimmenu_T *root_menu INIT (= NULL);
EXTERN char_u *p_go;
EXTERN long  Rows;
EXTERN unsigned  *LineOffset INIT (= NULL);
EXTERN long  p_ut;
EXTERN long  p_so;
EXTERN win_T *firstwin;
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
int can_update_cursor = TRUE;
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
EXTERN int p_confirm;
EXTERN typebuf_T typebuf;
EXTERN long_u scrollbar_value;
EXTERN except_T *caught_stack INIT (= NULL);
EXTERN int did_uncaught_emsg;
EXTERN int arrow_used;
EXTERN int mouse_row;
EXTERN int msg_row;
EXTERN int cmdline_row;
int prev_which_scrollbars [3];
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
linenr_T longest_lnum = 0;
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
gui_T gui;
EXTERN pos_T Insstart_orig;
EXTERN pos_T Insstart;
EXTERN pos_T VIsual;
EXTERN int p_hls;
EXTERN long  p_hi;
EXTERN long  p_ls;
EXTERN int p_lrm;
EXTERN int p_js;
EXTERN char bot_top_msg [] INIT (= N_ ("search hit BOTTOM, continuing at TOP"));

void gui_menu_cb (vimmenu_T *menu) {
    char_u bytes [sizeof (long_u)];
    if (hold_gui_events)
        return;
    bytes[0] = CSI;
    bytes[1] = KS_MENU;
    bytes[2] = KE_FILLER;
    add_to_input_buf (bytes, 3);
    add_long_to_buf ((long_u) menu, bytes);
    add_to_input_buf_csi (bytes, sizeof (long_u));
}

scrollbar_T *gui_find_scrollbar (long  ident) {
    win_T *wp;
    if (gui.bottom_sbar.ident == ident)
        return &gui.bottom_sbar;
    FOR_ALL_WINDOWS (wp) {
        if (wp->w_scrollbars[SBAR_LEFT].ident == ident)
            return &wp->w_scrollbars[SBAR_LEFT];
        if (wp->w_scrollbars[SBAR_RIGHT].ident == ident)
            return &wp->w_scrollbars[SBAR_RIGHT];
    }
    return NULL;
}

void gui_drag_scrollbar (scrollbar_T *sb, long  value, int still_dragging) {
    win_T *wp;
    int sb_num;
    char_u bytes [sizeof (long_u)];
    int byte_count;
    if (sb == NULL)
        return;
    if (hold_gui_events)
        return;
    if (still_dragging) {
        if (sb->wp == NULL)
            gui.dragged_sb = SBAR_BOTTOM;
        else if (sb == &sb->wp->w_scrollbars[SBAR_LEFT])
            gui.dragged_sb = SBAR_LEFT;
        else
            gui.dragged_sb = SBAR_RIGHT;
        gui.dragged_wp = sb->wp;
    }
    else {
        gui.dragged_sb = SBAR_NONE;
    }
    if (sb->wp != NULL)
        sb = &sb->wp->w_scrollbars[0];
    if (value < 0)
        value = 0;
    if (value > sb->max - sb->size + 1)
        value = sb->max - sb->size + 1;
    sb->value = value;
    if ((sb->wp == NULL || sb->wp == curwin) && pum_visible ())
        return;
    if (sb->wp == NULL && curwin->w_p_rl) {
        value = sb->max + 1 - sb->size - value;
        if (value < 0)
            value = 0;
    }
    if (sb->wp != NULL) {
        sb_num = 0;
        for (wp = firstwin; wp != sb->wp && wp != NULL; wp = wp->w_next)
            sb_num++;
        if (wp == NULL)
            return;
        bytes[0] = CSI;
        bytes[1] = KS_VER_SCROLLBAR;
        bytes[2] = KE_FILLER;
        bytes[3] = (char_u) sb_num;
        byte_count = 4;
    }
    else {
        bytes[0] = CSI;
        bytes[1] = KS_HOR_SCROLLBAR;
        bytes[2] = KE_FILLER;
        byte_count = 3;
    }
    add_to_input_buf (bytes, byte_count);
    add_long_to_buf ((long_u) value, bytes);
    add_to_input_buf_csi (bytes, sizeof (long_u));
}

int gui_do_scroll (void) {
    win_T *wp, *save_wp;
    int i;
    long  nlines;
    pos_T old_cursor;
    linenr_T old_topline;
    int old_topfill;
    for (wp = firstwin, i = 0; i < current_scrollbar; wp = W_NEXT (wp), i++)
        if (wp == NULL)
            break;
    if (wp == NULL)
        return FALSE;
    nlines = (long ) scrollbar_value + 1 - (long ) wp->w_topline;
    if (nlines == 0)
        return FALSE;
    save_wp = curwin;
    old_topline = wp->w_topline;
    old_topfill = wp->w_topfill;
    old_cursor = wp->w_cursor;
    curwin = wp;
    curbuf = wp->w_buffer;
    if (nlines < 0)
        scrolldown (-nlines, gui.dragged_wp == NULL);
    else
        scrollup (nlines, gui.dragged_wp == NULL);
    if (gui.dragged_sb == SBAR_NONE)
        gui.dragged_wp = NULL;
    if (old_topline != wp->w_topline || old_topfill != wp->w_topfill) {
        if (p_so != 0) {
            cursor_correct ();
            update_topline ();
        }
        if (old_cursor.lnum != wp->w_cursor.lnum)
            coladvance (wp->w_curswant);
        wp->w_scbind_pos = wp->w_topline;
    }
    validate_cursor ();
    curwin = save_wp;
    curbuf = save_wp->w_buffer;
    if (old_topline != wp->w_topline || wp->w_redr_type != 0 || old_topfill != wp->w_topfill) {
        int type = VALID;
        if (pum_visible ()) {
            type = NOT_VALID;
            wp->w_lines_valid = 0;
        }
        if (wp->w_redr_type < type)
            wp->w_redr_type = type;
        mch_disable_flush ();
        updateWindow (wp);
        mch_enable_flush ();
    }
    if (pum_visible ())
        pum_redraw ();
    return (wp == curwin && !EQUAL_POS (curwin->w_cursor, old_cursor));
}

void gui_new_shellsize (void) {
    gui_reset_scroll_region ();
}

void gui_reset_scroll_region (void) {
    gui.scroll_region_top = 0;
    gui.scroll_region_bot = gui.num_rows - 1;
    gui.scroll_region_left = 0;
    gui.scroll_region_right = gui.num_cols - 1;
}

void gui_write (char_u *s, int len) {
    char_u *p;
    int arg1 = 0, arg2 = 0;
    int force_cursor = FALSE;
    int force_scrollbar = FALSE;
    static win_T *old_curwin = NULL;
    while (len) {
        if (s[0] == ESC && s[1] == '|') {
            p = s + 2;
            if (VIM_ISDIGIT (*p) || (*p == '-' && VIM_ISDIGIT (*(p + 1)))) {
                arg1 = getdigits (&p);
                if (p > s + len)
                    break;
                if (*p == ';') {
                    ++p;
                    arg2 = getdigits (&p);
                    if (p > s + len)
                        break;
                }
            }
            switch (*p) {
            case 'C' :
                clip_scroll_selection (9999);
                gui_mch_clear_all ();
                gui.cursor_is_valid = FALSE;
                force_scrollbar = TRUE;
                break;
            case 'M' :
                gui_set_cursor (arg1, arg2);
                break;
            case 's' :
                force_cursor = TRUE;
                break;
            case 'R' :
                if (arg1 < arg2) {
                    gui.scroll_region_top = arg1;
                    gui.scroll_region_bot = arg2;
                }
                else {
                    gui.scroll_region_top = arg2;
                    gui.scroll_region_bot = arg1;
                }
                break;
            case 'V' :
                if (arg1 < arg2) {
                    gui.scroll_region_left = arg1;
                    gui.scroll_region_right = arg2;
                }
                else {
                    gui.scroll_region_left = arg2;
                    gui.scroll_region_right = arg1;
                }
                break;
            case 'd' :
                gui_delete_lines (gui.row, 1);
                break;
            case 'D' :
                gui_delete_lines (gui.row, arg1);
                break;
            case 'i' :
                gui_insert_lines (gui.row, 1);
                break;
            case 'I' :
                gui_insert_lines (gui.row, arg1);
                break;
            case '$' :
                gui_clear_block (gui.row, gui.col, gui.row, (int) Columns - 1);
                break;
            case 'h' :
                gui_start_highlight (arg1);
                break;
            case 'H' :
                gui_stop_highlight (arg1);
                break;
            case 'f' :
                gui_mch_flash (arg1 == 0 ? 20 : arg1);
                break;
            default :
                p = s + 1;
                break;
            }
            len -= (int) (++p - s);
            s = p;
        }
        else if (s[0] < 0x20) {
            if (s[0] == '\n') {
                gui.col = 0;
                if (gui.row < gui.scroll_region_bot)
                    gui.row++;
                else
                    gui_delete_lines (gui.scroll_region_top, 1);
            }
            else if (s[0] == '\r') {
                gui.col = 0;
            }
            else if (s[0] == '\b') {
                if (gui.col)
                    --gui.col;
            }
            else if (s[0] == Ctrl_L) {
                ++gui.col;
            }
            else if (s[0] == Ctrl_G) {
                gui_mch_beep ();
            }
            --len;
            ++s;
        }
        else {
            p = s;
            while (len > 0 && (*p >= 0x20)) {
                len--;
                p++;
            }
            gui_outstr (s, (int) (p - s));
            s = p;
        }
    }
    if (force_cursor)
        gui_update_cursor (TRUE, TRUE);
    if (old_curwin != curwin)
        gui.dragged_sb = SBAR_NONE;
    if (force_scrollbar || old_curwin != curwin)
        gui_update_scrollbars (force_scrollbar);
    else
        gui_update_horiz_scrollbar (FALSE);
    old_curwin = curwin;
    gui_may_flush ();
}

void gui_set_cursor (int row, int col) {
    gui.row = row;
    gui.col = col;
}

static void gui_delete_lines (int row, int count) {
    if (count <= 0)
        return;
    if (row + count > gui.scroll_region_bot)
        gui_clear_block (row, gui.scroll_region_left, gui.scroll_region_bot, gui.scroll_region_right);
    else {
        gui_mch_delete_lines (row, count);
        if (gui.cursor_row >= row && gui.cursor_col >= gui.scroll_region_left && gui.cursor_col <= gui.scroll_region_right) {
            if (gui.cursor_row < row + count)
                gui.cursor_is_valid = FALSE;
            else if (gui.cursor_row <= gui.scroll_region_bot)
                gui.cursor_row -= count;
        }
    }
}

void gui_clear_block (int row1, int col1, int row2, int col2) {
    clip_may_clear_selection (row1, row2);
    gui_mch_clear_block (row1, col1, row2, col2);
    if (gui.cursor_row >= row1 && gui.cursor_row <= row2 && gui.cursor_col >= col1 && gui.cursor_col <= col2)
        gui.cursor_is_valid = FALSE;
}

static void gui_insert_lines (int row, int count) {
    if (count <= 0)
        return;
    if (row + count > gui.scroll_region_bot)
        gui_clear_block (row, gui.scroll_region_left, gui.scroll_region_bot, gui.scroll_region_right);
    else {
        gui_mch_insert_lines (row, count);
        if (gui.cursor_row >= gui.row && gui.cursor_col >= gui.scroll_region_left && gui.cursor_col <= gui.scroll_region_right) {
            if (gui.cursor_row <= gui.scroll_region_bot - count)
                gui.cursor_row += count;
            else if (gui.cursor_row <= gui.scroll_region_bot)
                gui.cursor_is_valid = FALSE;
        }
    }
}

void gui_start_highlight (int mask) {
    if (mask > HL_ALL)
        gui.highlight_mask = mask;
    else
        gui.highlight_mask |= mask;
}

void gui_stop_highlight (int mask) {
    if (mask > HL_ALL)
        gui.highlight_mask = HL_NORMAL;
    else
        gui.highlight_mask &= ~mask;
}

int gui_wait_for_chars (long  wtime, int tb_change_cnt) {
    int retval;
    if (wtime != 0)
        gui_update_menus (0);
    gui_mch_update ();
    if (input_available ())
        return OK;
    if (wtime == 0)
        return FAIL;
    gui_mch_flush ();
    if (wtime > 0) {
        gui_mch_start_blink ();
        retval = gui_wait_for_chars_or_timer (wtime);
        gui_mch_stop_blink (TRUE);
        return retval;
    }
    gui_mch_start_blink ();
    retval = FAIL;
    if (gui_wait_for_chars_or_timer (p_ut) == OK)
        retval = OK;
    else if (trigger_cursorhold () && typebuf.tb_change_cnt == tb_change_cnt) {
        char_u buf [3];
        buf[0] = CSI;
        buf[1] = KS_EXTRA;
        buf[2] = (int) KE_CURSORHOLD;
        add_to_input_buf (buf, 3);
        retval = OK;
    }
    if (retval == FAIL && typebuf.tb_change_cnt == tb_change_cnt) {
        before_blocking ();
        retval = gui_wait_for_chars_or_timer (-1L);
    }
    gui_mch_stop_blink (TRUE);
    return retval;
}

void gui_update_cursor (int force, int clear_selection) {
    int cur_width = 0;
    int cur_height = 0;
    int old_hl_mask;
    cursorentry_T *shape;
    int id;
    guicolor_T shape_fg = INVALCOLOR;
    guicolor_T shape_bg = INVALCOLOR;
    guicolor_T cfg, cbg, cc;
    int cattr;
    int attr;
    attrentry_T *aep = NULL;
    if (!can_update_cursor || screen_Columns != gui.num_cols || screen_Rows != gui.num_rows)
        return;
    gui_check_pos ();
    if (!gui.cursor_is_valid || force || gui.row != gui.cursor_row || gui.col != gui.cursor_col) {
        gui_undraw_cursor ();
        if (gui.row < 0)
            return;
        gui.cursor_row = gui.row;
        gui.cursor_col = gui.col;
        if (!screen_cleared || ScreenLines == NULL)
            return;
        if (clear_selection)
            clip_may_clear_selection (gui.row, gui.row);
        if (gui.row >= screen_Rows || gui.col >= screen_Columns)
            return;
        gui.cursor_is_valid = TRUE;
        if (terminal_is_active ())
            shape = term_get_cursor_shape (&shape_fg, &shape_bg);
        else
            shape = &shape_table[get_shape_idx (FALSE)];
        if (State & LANGMAP)
            id = shape->id_lm;
        else
            id = shape->id;
        cfg = INVALCOLOR;
        cbg = INVALCOLOR;
        cattr = HL_INVERSE;
        gui_mch_set_blinking (shape -> blinkwait, shape -> blinkon, shape -> blinkoff);
        if (shape->blinkwait == 0 || shape->blinkon == 0 || shape->blinkoff == 0)
            gui_mch_stop_blink (FALSE);
        if (shape_bg != INVALCOLOR) {
            cattr = 0;
            cfg = shape_fg;
            cbg = shape_bg;
        }
        else if (id > 0) {
            cattr = syn_id2colors (id, &cfg, &cbg);
        }
        attr = ScreenAttrs[LineOffset[gui.row] + gui.col];
        if (attr > HL_ALL)
            aep = syn_gui_attr2entry (attr);
        if (aep != NULL) {
            attr = aep->ae_attr;
            if (cfg == INVALCOLOR)
                cfg = ((attr & HL_INVERSE) ? aep->ae_u.gui.bg_color : aep->ae_u.gui.fg_color);
            if (cbg == INVALCOLOR)
                cbg = ((attr & HL_INVERSE) ? aep->ae_u.gui.fg_color : aep->ae_u.gui.bg_color);
        }
        if (cfg == INVALCOLOR)
            cfg = (attr & HL_INVERSE) ? gui.back_pixel : gui.norm_pixel;
        if (cbg == INVALCOLOR)
            cbg = (attr & HL_INVERSE) ? gui.norm_pixel : gui.back_pixel;
        attr &= ~HL_INVERSE;
        if (cattr & HL_INVERSE) {
            cc = cbg;
            cbg = cfg;
            cfg = cc;
        }
        cattr &= ~HL_INVERSE;
        if (!gui.in_focus) {
            gui_mch_draw_hollow_cursor (cbg);
            return;
        }
        old_hl_mask = gui.highlight_mask;
        if (shape->shape == SHAPE_BLOCK) {
            gui.highlight_mask = (cattr | attr);
            (void) gui_screenchar (LineOffset[gui.row] + gui.col, GUI_MON_IS_CURSOR | GUI_MON_NOCLEAR, cfg, cbg, 0);
        }
        else {
            if (shape->shape == SHAPE_VER) {
                cur_height = gui.char_height;
                cur_width = (gui.char_width * shape->percentage + 99) / 100;
            }
            else {
                cur_height = (gui.char_height * shape->percentage + 99) / 100;
                cur_width = gui.char_width;
            }
            gui_mch_draw_part_cursor (cur_width, cur_height, cbg);
            gui.highlight_mask = ScreenAttrs[LineOffset[gui.row] + gui.col];
            (void) gui_screenchar (LineOffset[gui.row] + gui.col, GUI_MON_TRS_CURSOR | GUI_MON_NOCLEAR, (guicolor_T) 0, (guicolor_T) 0, 0);
        }
        gui.highlight_mask = old_hl_mask;
    }
}

static void gui_check_pos (void) {
    if (gui.row >= screen_Rows)
        gui.row = screen_Rows - 1;
    if (gui.col >= screen_Columns)
        gui.col = screen_Columns - 1;
    if (gui.cursor_row >= screen_Rows || gui.cursor_col >= screen_Columns)
        gui.cursor_is_valid = FALSE;
}

void gui_undraw_cursor (void) {
    if (gui.cursor_is_valid) {
        if (gui_redraw_block (gui.cursor_row, gui.cursor_col, gui.cursor_row, gui.cursor_col, GUI_MON_NOCLEAR) && gui.cursor_col > 0)
            (void) gui_redraw_block (gui.cursor_row, gui.cursor_col - 1, gui.cursor_row, gui.cursor_col - 1, GUI_MON_NOCLEAR);
        gui.cursor_is_valid = FALSE;
    }
}

int gui_redraw_block (int row1, int col1, int row2, int col2, int flags) {
    int old_row, old_col;
    long_u old_hl_mask;
    int off;
    sattr_T first_attr;
    int idx, len;
    int back, nback;
    int retval = FALSE;
    if (!screen_cleared || ScreenLines == NULL)
        return retval;
    col1 = check_col (col1);
    col2 = check_col (col2);
    row1 = check_row (row1);
    row2 = check_row (row2);
    old_row = gui.row;
    old_col = gui.col;
    old_hl_mask = gui.highlight_mask;
    for (gui.row = row1; gui.row <= row2; gui.row++) {
        gui.col = col1;
        off = LineOffset[gui.row] + gui.col;
        len = col2 - col1 + 1;
        for (back = 0; back < col1; ++back)
            if (ScreenAttrs[off - 1 - back] != ScreenAttrs[off] || ScreenLines[off - 1 - back] == ' ')
                break;
        retval = (col1 > 0 && ScreenAttrs[off - 1] != 0 && back == 0 && ScreenLines[off - 1] != ' ');
        while (len > 0) {
            first_attr = ScreenAttrs[off];
            gui.highlight_mask = first_attr;
            {
                for (idx = 0; idx < len && ScreenAttrs[off + idx] == first_attr; idx++) {
                }
                nback = gui_outstr_nowrap (ScreenLines +off, idx, flags, (guicolor_T) 0, (guicolor_T) 0, back);
            }
            if (nback == FAIL) {
                off -= back;
                len += back;
                gui.col -= back;
            }
            else {
                off += idx;
                len -= idx;
            }
            back = 0;
        }
    }
    gui.row = old_row;
    gui.col = old_col;
    gui.highlight_mask = (int) old_hl_mask;
    return retval;
}

int gui_outstr_nowrap (char_u *s, int len, int flags, guicolor_T fg, guicolor_T bg, int back) {
    long_u highlight_mask;
    long_u hl_mask_todo;
    guicolor_T fg_color;
    guicolor_T bg_color;
    guicolor_T sp_color;
    attrentry_T *aep = NULL;
    int draw_flags;
    int col = gui.col;
    if (len < 0)
        len = (int) STRLEN (s);
    if (len == 0)
        return OK;
    if (gui.highlight_mask > HL_ALL) {
        aep = syn_gui_attr2entry (gui.highlight_mask);
        if (aep == NULL)
            highlight_mask = 0;
        else
            highlight_mask = aep->ae_attr;
    }
    else
        highlight_mask = gui.highlight_mask;
    hl_mask_todo = highlight_mask;
    draw_flags = 0;
    bg_color = gui.back_pixel;
    if ((flags & GUI_MON_IS_CURSOR) && gui.in_focus) {
        draw_flags |= DRAW_CURSOR;
        fg_color = fg;
        bg_color = bg;
        sp_color = fg;
    }
    else if (aep != NULL) {
        fg_color = aep->ae_u.gui.fg_color;
        if (fg_color == INVALCOLOR)
            fg_color = gui.norm_pixel;
        bg_color = aep->ae_u.gui.bg_color;
        if (bg_color == INVALCOLOR)
            bg_color = gui.back_pixel;
        sp_color = aep->ae_u.gui.sp_color;
        if (sp_color == INVALCOLOR)
            sp_color = fg_color;
    }
    else {
        fg_color = gui.norm_pixel;
        sp_color = fg_color;
    }
    if (highlight_mask & (HL_INVERSE | HL_STANDOUT)) {
        gui_mch_set_fg_color (bg_color);
        gui_mch_set_bg_color (fg_color);
    }
    else {
        gui_mch_set_fg_color (fg_color);
        gui_mch_set_bg_color (bg_color);
    }
    gui_mch_set_sp_color (sp_color);
    if (!(flags & GUI_MON_NOCLEAR))
        clip_may_clear_selection (gui.row, gui.row);
    if (hl_mask_todo & (HL_BOLD | HL_STANDOUT))
        draw_flags |= DRAW_BOLD;
    if (back != 0 && ((draw_flags & DRAW_BOLD) || (highlight_mask & HL_ITALIC)))
        return FAIL;
    if (hl_mask_todo & HL_ITALIC)
        draw_flags |= DRAW_ITALIC;
    if (hl_mask_todo & HL_UNDERLINE)
        draw_flags |= DRAW_UNDERL;
    if (hl_mask_todo & HL_UNDERCURL)
        draw_flags |= DRAW_UNDERC;
    if (hl_mask_todo & HL_STRIKETHROUGH)
        draw_flags |= DRAW_STRIKE;
    if (flags & GUI_MON_TRS_CURSOR)
        draw_flags |= DRAW_TRANSP;
    {
        gui_mch_draw_string (gui.row, col, s, len, len, draw_flags);
    }
    if (!(flags & (GUI_MON_IS_CURSOR | GUI_MON_TRS_CURSOR)))
        gui.col = col + len;
    if (flags & GUI_MON_NOCLEAR)
        clip_may_redraw_selection (gui.row, col, len);
    if (!(flags & (GUI_MON_IS_CURSOR | GUI_MON_TRS_CURSOR))) {
        if (gui.cursor_row == gui.row && gui.cursor_col >= col && gui.cursor_col < col + len)
            gui.cursor_is_valid = FALSE;
    }
    return OK;
}

static int gui_screenchar (int off, int flags, guicolor_T fg, guicolor_T bg, int back) {
    return gui_outstr_nowrap (ScreenLines +off, 1, flags, fg, bg, back);
}

void gui_dont_update_cursor (int undraw) {
    if (gui.in_use) {
        if (undraw)
            gui_undraw_cursor ();
        can_update_cursor = FALSE;
    }
}

void gui_can_update_cursor (void) {
    can_update_cursor = TRUE;
}

void gui_set_shellsize (int mustset, int fit_to_display, int direction) {
    int base_width;
    int base_height;
    int width;
    int height;
    int min_width;
    int min_height;
    int screen_w;
    int screen_h;
    int x = -1, y = -1;
    if (!gui.shell_created)
        return;
    base_width = gui_get_base_width ();
    base_height = gui_get_base_height ();
    if (fit_to_display)
        (void) gui_mch_get_winpos (&x, &y);
    {
        width = Columns * gui.char_width + base_width;
        height = Rows * gui.char_height + base_height;
    }
    if (fit_to_display) {
        gui_mch_get_screen_dimensions (& screen_w, & screen_h);
        if ((direction & RESIZE_HOR) && width > screen_w) {
            Columns = (screen_w - base_width) / gui.char_width;
            if (Columns < MIN_COLUMNS)
                Columns = MIN_COLUMNS;
            width = Columns * gui.char_width + base_width;
        }
        if ((direction & RESIZE_VERT) && height > screen_h) {
            Rows = (screen_h - base_height) / gui.char_height;
            check_shellsize ();
            height = Rows * gui.char_height + base_height;
        }
    }
    limit_screen_size ();
    gui.num_cols = Columns;
    gui.num_rows = Rows;
    min_width = base_width + MIN_COLUMNS * gui.char_width;
    min_height = base_height + MIN_LINES * gui.char_height;
    min_height += tabline_height () * gui.char_height;
    gui_mch_set_shellsize (width, height, min_width, min_height, base_width, base_height, direction);
    if (fit_to_display && x >= 0 && y >= 0) {
        gui_mch_update ();
        if (gui_mch_get_winpos (&x, &y) == OK && (x < 0 || y < 0))
            gui_mch_set_winpos (x < 0 ? 0 : x, y < 0 ? 0 : y);
    }
    gui_position_components (width);
    gui_update_scrollbars (TRUE);
    gui_reset_scroll_region ();
}

int gui_get_base_width (void) {
    int base_width;
    base_width = 2 * gui.border_offset;
    if (gui.which_scrollbars[SBAR_LEFT])
        base_width += gui.scrollbar_width;
    if (gui.which_scrollbars[SBAR_RIGHT])
        base_width += gui.scrollbar_width;
    return base_width;
}

int gui_get_base_height (void) {
    int base_height;
    base_height = 2 * gui.border_offset;
    if (gui.which_scrollbars[SBAR_BOTTOM])
        base_height += gui.scrollbar_height;
    return base_height;
}

void gui_resize_shell (int pixel_width, int pixel_height) {
    static int busy = FALSE;
    if (!gui.shell_created)
        return;
    if (updating_screen || busy) {
        new_pixel_width = pixel_width;
        new_pixel_height = pixel_height;
        return;
    }
again :
    new_pixel_width = 0;
    new_pixel_height = 0;
    busy = TRUE;
    out_flush ();
    gui.num_cols = (pixel_width - gui_get_base_width ()) / gui.char_width;
    gui.num_rows = (pixel_height - gui_get_base_height ()) / gui.char_height;
    gui_position_components (pixel_width);
    gui_reset_scroll_region ();
    if (State == ASKMORE || State == CONFIRM)
        gui.row = gui.num_rows;
    if (gui.num_rows != screen_Rows || gui.num_cols != screen_Columns || gui.num_rows != Rows || gui.num_cols != Columns)
        shell_resized ();
    gui_update_scrollbars (TRUE);
    gui_update_cursor (FALSE, TRUE);
    busy = FALSE;
    if (new_pixel_height) {
        if (pixel_width == new_pixel_width && pixel_height == new_pixel_height) {
            new_pixel_width = 0;
            new_pixel_height = 0;
        }
        else {
            pixel_width = new_pixel_width;
            pixel_height = new_pixel_height;
            goto again;
        }
    }
}

static void gui_position_components (int total_width) {
    int text_area_x;
    int text_area_y;
    int text_area_width;
    int text_area_height;
    ++hold_gui_events;
    text_area_x = 0;
    if (gui.which_scrollbars[SBAR_LEFT])
        text_area_x += gui.scrollbar_width;
    text_area_y = 0;
    text_area_width = gui.num_cols * gui.char_width + gui.border_offset * 2;
    text_area_height = gui.num_rows * gui.char_height + gui.border_offset * 2;
    gui_mch_set_text_area_pos (text_area_x, text_area_y, text_area_width, text_area_height);
    gui_position_menu ();
    if (gui.which_scrollbars[SBAR_BOTTOM])
        gui_mch_set_scrollbar_pos (&gui.bottom_sbar, text_area_x, text_area_y +text_area_height, text_area_width, gui.scrollbar_height);
    gui.left_sbar_x = 0;
    gui.right_sbar_x = text_area_x + text_area_width;
    --hold_gui_events;
}

void gui_position_menu (void) {
}

int gui_get_shellsize (void) {
    Rows = gui.num_rows;
    Columns = gui.num_cols;
    return OK;
}

void gui_update_scrollbars (int force) {
    win_T *wp;
    scrollbar_T *sb;
    long  val, size, max;
    int which_sb;
    int h, y;
    static win_T *prev_curwin = NULL;
    gui_update_horiz_scrollbar (force);
    if (!gui.which_scrollbars[SBAR_LEFT] && !gui.which_scrollbars[SBAR_RIGHT])
        return;
    if (!force && (gui.dragged_sb == SBAR_LEFT || gui.dragged_sb == SBAR_RIGHT) && gui.which_scrollbars[SBAR_LEFT] && gui.which_scrollbars[SBAR_RIGHT]) {
        which_sb = SBAR_LEFT + SBAR_RIGHT - gui.dragged_sb;
        if (gui.dragged_wp != NULL)
            gui_mch_set_scrollbar_thumb (&gui.dragged_wp->w_scrollbars[which_sb], gui.dragged_wp->w_scrollbars[0].value, gui.dragged_wp->w_scrollbars[0].size, gui.dragged_wp->w_scrollbars[0].max);
    }
    ++hold_gui_events;
    for (wp = firstwin; wp != NULL; wp = W_NEXT (wp)) {
        if (wp->w_buffer == NULL)
            continue;
        if (!force && (gui.dragged_sb == SBAR_LEFT || gui.dragged_sb == SBAR_RIGHT) && gui.dragged_wp == wp)
            continue;
        max = wp->w_buffer->b_ml.ml_line_count + wp->w_height - 2;
        if (max < 0)
            max = 0;
        val = wp->w_topline - 1;
        size = wp->w_height;
        if (size > max + 1)
            size = max + 1;
        if (val > max - size + 1)
            val = max - size + 1;
        if (val < 0)
            val = 0;
        sb = &wp->w_scrollbars[0];
        if (size < 1 || wp->w_botline - 2 > max) {
            sb->height = 0;
            if (gui.which_scrollbars[SBAR_LEFT])
                gui_do_scrollbar (wp, SBAR_LEFT, FALSE);
            if (gui.which_scrollbars[SBAR_RIGHT])
                gui_do_scrollbar (wp, SBAR_RIGHT, FALSE);
            continue;
        }
        if (force || sb->height != wp->w_height || sb->top != wp->w_winrow || sb->status_height != wp->w_status_height || sb->width != wp->w_width || prev_curwin != curwin) {
            sb->height = wp->w_height;
            sb->top = wp->w_winrow;
            sb->status_height = wp->w_status_height;
            sb->width = wp->w_width;
            h = (sb->height + sb->status_height) * gui.char_height;
            y = sb->top * gui.char_height + gui.border_offset;
            if (wp->w_winrow == 0) {
                h += gui.border_offset;
                y -= gui.border_offset;
            }
            if (gui.which_scrollbars[SBAR_LEFT]) {
                gui_mch_set_scrollbar_pos (& wp -> w_scrollbars [SBAR_LEFT], gui.left_sbar_x, y, gui.scrollbar_width, h);
                gui_do_scrollbar (wp, SBAR_LEFT, TRUE);
            }
            if (gui.which_scrollbars[SBAR_RIGHT]) {
                gui_mch_set_scrollbar_pos (& wp -> w_scrollbars [SBAR_RIGHT], gui.right_sbar_x, y, gui.scrollbar_width, h);
                gui_do_scrollbar (wp, SBAR_RIGHT, TRUE);
            }
        }
        if (force || sb->value != val || sb->size != size || sb->max != max) {
            sb->value = val;
            sb->size = size;
            sb->max = max;
            if (gui.which_scrollbars[SBAR_LEFT] && (gui.dragged_sb != SBAR_LEFT || gui.dragged_wp != wp))
                gui_mch_set_scrollbar_thumb (&wp->w_scrollbars[SBAR_LEFT], val, size, max);
            if (gui.which_scrollbars[SBAR_RIGHT] && (gui.dragged_sb != SBAR_RIGHT || gui.dragged_wp != wp))
                gui_mch_set_scrollbar_thumb (&wp->w_scrollbars[SBAR_RIGHT], val, size, max);
        }
    }
    prev_curwin = curwin;
    --hold_gui_events;
}

static void gui_update_horiz_scrollbar (int force) {
    long  value, size, max;
    if (!gui.which_scrollbars[SBAR_BOTTOM])
        return;
    if (!force && gui.dragged_sb == SBAR_BOTTOM)
        return;
    if (!force && curwin->w_p_wrap && gui.prev_wrap)
        return;
    if (curwin->w_cursor.lnum > curbuf->b_ml.ml_line_count) {
        gui.bottom_sbar.value = -1;
        return;
    }
    size = curwin->w_width;
    if (curwin->w_p_wrap) {
        value = 0;
        max = curwin->w_width - 1;
    }
    else {
        value = curwin->w_leftcol;
        longest_lnum = gui_find_longest_lnum ();
        max = scroll_line_len (longest_lnum);
        if (virtual_active ()) {
            if (curwin->w_virtcol >= (colnr_T) max)
                max = curwin->w_virtcol;
        }
        max += curwin->w_width - 1;
        size -= curwin_col_off ();
        max -= curwin_col_off ();
    }
    if (value > max - size + 1)
        value = max - size + 1;
    if (curwin->w_p_rl) {
        value = max + 1 - size - value;
        if (value < 0) {
            size += value;
            value = 0;
        }
    }
    if (!force && value == gui.bottom_sbar.value && size == gui.bottom_sbar.size && max == gui.bottom_sbar.max)
        return;
    gui.bottom_sbar.value = value;
    gui.bottom_sbar.size = size;
    gui.bottom_sbar.max = max;
    gui.prev_wrap = curwin->w_p_wrap;
    gui_mch_set_scrollbar_thumb (& gui.bottom_sbar, value, size, max);
}

static linenr_T gui_find_longest_lnum (void) {
    linenr_T ret = 0;
    if (vim_strchr (p_go, GO_HORSCROLL) == NULL && curwin->w_topline <= curwin->w_cursor.lnum && curwin->w_botline > curwin->w_cursor.lnum && curwin->w_botline <= curbuf->b_ml.ml_line_count + 1) {
        linenr_T lnum;
        colnr_T n;
        long  max = 0;
        for (lnum = curwin->w_topline; lnum < curwin->w_botline; ++lnum) {
            n = scroll_line_len (lnum);
            if (n > (colnr_T) max) {
                max = n;
                ret = lnum;
            }
            else if (n == (colnr_T) max && abs ((int) (lnum - curwin->w_cursor.lnum)) < abs ((int) (ret - curwin->w_cursor.lnum)))
                ret = lnum;
        }
    }
    else
        ret = curwin->w_cursor.lnum;
    return ret;
}

static colnr_T scroll_line_len (linenr_T lnum) {
    char_u *p;
    colnr_T col;
    int w;
    p = ml_get (lnum);
    col = 0;
    if (*p != NUL)
        for (;;) {
            w = chartabsize (p, col);
            MB_PTR_ADV (p);
            if (*p == NUL)
                break;
            col += w;
        }
    return col;
}

static void gui_do_scrollbar (win_T *wp, int which, int enable) {
    int midcol = curwin->w_wincol + curwin->w_width / 2;
    int has_midcol = (wp->w_wincol <= midcol && wp->w_wincol + wp->w_width >= midcol);
    if (gui.which_scrollbars[SBAR_RIGHT] != gui.which_scrollbars[SBAR_LEFT]) {
        if (!has_midcol)
            enable = FALSE;
    }
    else {
        if (midcol > Columns / 2) {
            if (which == SBAR_LEFT ? wp->w_wincol != 0 : !has_midcol)
                enable = FALSE;
        }
        else {
            if (which == SBAR_RIGHT ? wp->w_wincol + wp->w_width != Columns : !has_midcol)
                enable = FALSE;
        }
    }
    gui_mch_enable_scrollbar (& wp -> w_scrollbars [which], enable);
}

void gui_may_resize_shell (void) {
    if (new_pixel_height)
        gui_resize_shell (new_pixel_width, new_pixel_height);
}

void gui_create_scrollbar (scrollbar_T *sb, int type, win_T *wp) {
    static int32_t sbar_ident = 0;
    sb->ident = sbar_ident++;
    sb->wp = wp;
    sb->type = type;
    sb->value = 0;
    sb->size = 1;
    sb->max = 1;
    sb->top = 0;
    sb->height = 0;
    sb->width = 0;
    sb->status_height = 0;
    gui_mch_create_scrollbar (sb, (wp == NULL) ? SBAR_HORIZ : SBAR_VERT);
}

void gui_init_which_components (char_u *oldval) {
    static int prev_menu_is_active = -1;
    static int prev_toolbar = -1;
    int using_toolbar = FALSE;
    static int prev_tearoff = -1;
    int using_tearoff = FALSE;
    char_u *p;
    int i;
    int grey_old, grey_new;
    char_u *temp;
    win_T *wp;
    int need_set_size;
    int fix_size;
    if (oldval != NULL && gui.in_use) {
        grey_old = (vim_strchr (oldval, GO_GREY) != NULL);
        grey_new = (vim_strchr (p_go, GO_GREY) != NULL);
        if (grey_old != grey_new) {
            temp = p_go;
            p_go = oldval;
            gui_update_menus (MENU_ALL_MODES);
            p_go = temp;
        }
    }
    gui.menu_is_active = FALSE;
    for (i = 0; i < 3; i++)
        gui.which_scrollbars[i] = FALSE;
    for (p = p_go; *p; p++)
        switch (*p) {
        case GO_LEFT :
            gui.which_scrollbars[SBAR_LEFT] = TRUE;
            break;
        case GO_RIGHT :
            gui.which_scrollbars[SBAR_RIGHT] = TRUE;
            break;
        case GO_VLEFT :
            if (win_hasvertsplit ())
                gui.which_scrollbars[SBAR_LEFT] = TRUE;
            break;
        case GO_VRIGHT :
            if (win_hasvertsplit ())
                gui.which_scrollbars[SBAR_RIGHT] = TRUE;
            break;
        case GO_BOT :
            gui.which_scrollbars[SBAR_BOTTOM] = TRUE;
            break;
        case GO_MENUS :
            gui.menu_is_active = TRUE;
            break;
        case GO_GREY :
            break;
        case GO_TOOLBAR :
            using_toolbar = TRUE;
            break;
        case GO_TEAROFF :
            using_tearoff = TRUE;
            break;
        default :
            break;
        }
    if (gui.in_use) {
        need_set_size = 0;
        fix_size = FALSE;
        for (i = 0; i < 3; i++) {
            if (gui.which_scrollbars[i] != prev_which_scrollbars[i] || gui.which_scrollbars[i] != curtab->tp_prev_which_scrollbars[i]) {
                if (i == SBAR_BOTTOM)
                    gui_mch_enable_scrollbar (&gui.bottom_sbar, gui.which_scrollbars[i]);
                else {
                    FOR_ALL_WINDOWS (wp) {
                        gui_do_scrollbar (wp, i, gui.which_scrollbars [i]);
                    }
                }
                if (gui.which_scrollbars[i] != prev_which_scrollbars[i]) {
                    if (i == SBAR_BOTTOM)
                        need_set_size |= RESIZE_VERT;
                    else
                        need_set_size |= RESIZE_HOR;
                    if (gui.which_scrollbars[i])
                        fix_size = TRUE;
                }
            }
            curtab->tp_prev_which_scrollbars[i] = gui.which_scrollbars[i];
            prev_which_scrollbars[i] = gui.which_scrollbars[i];
        }
        if (gui.menu_is_active != prev_menu_is_active) {
            i = Rows;
            gui_mch_enable_menu (gui.menu_is_active);
            Rows = i;
            prev_menu_is_active = gui.menu_is_active;
            need_set_size |= RESIZE_VERT;
            if (gui.menu_is_active)
                fix_size = TRUE;
        }
        if (using_toolbar != prev_toolbar) {
            gui_mch_show_toolbar (using_toolbar);
            prev_toolbar = using_toolbar;
            need_set_size |= RESIZE_VERT;
            if (using_toolbar)
                fix_size = TRUE;
        }
        if (using_tearoff != prev_tearoff) {
            gui_mch_toggle_tearoffs (using_tearoff);
            prev_tearoff = using_tearoff;
        }
        if (need_set_size != 0) {
            gui_set_shellsize (FALSE, fix_size, need_set_size);
        }
        if (firstwin->w_winrow != tabline_height ())
            shell_new_rows ();
    }
}

void gui_init (void) {
    win_T *wp;
    static int recursive = 0;
    if (!recursive) {
        ++recursive;
        clip_init (TRUE);
        if (gui_init_check () == FAIL) {
            --recursive;
            clip_init (FALSE);
            return;
        }
        set_option_value ((char_u *) "paste", 0L, NULL, 0);
        if (!option_was_set ((char_u *) "mouse"))
            set_string_option_direct ((char_u *) "mouse", -1, (char_u *) "a", OPT_FREE, SID_NONE);
        if (use_gvimrc != NULL) {
            if (STRCMP (use_gvimrc, "NONE") != 0 && STRCMP (use_gvimrc, "NORC") != 0 && do_source (use_gvimrc, FALSE, DOSO_NONE) != OK)
                EMSG2 (_ ("E230: Cannot read from \"%s\""), use_gvimrc);
        }
        else {
            if (process_env ((char_u *) "GVIMINIT", FALSE) == FAIL && do_source ((char_u *) USR_GVIMRC_FILE, TRUE, DOSO_GVIMRC) == FAIL) {
            }
            if (p_exrc) {
                {
                    stat_T s;
                    if (mch_stat (GVIMRC_FILE, &s) || s.st_uid != getuid ())
                        secure = p_secure;
                }
                if (fullpathcmp ((char_u *) USR_GVIMRC_FILE, (char_u *) GVIMRC_FILE, FALSE) != FPC_SAME)
                    do_source ((char_u *) GVIMRC_FILE, TRUE, DOSO_GVIMRC);
                if (secure == 2)
                    need_wait_return = TRUE;
                secure = 0;
            }
        }
        if (need_wait_return || msg_didany)
            wait_return (TRUE);
        --recursive;
    }
    if (gui.in_use)
        return;
    gui.in_use = TRUE;
    if (gui_mch_init () == FAIL)
        goto error;
    emsg_on_display = FALSE;
    msg_scrolled = 0;
    clear_sb_text (TRUE);
    need_wait_return = FALSE;
    msg_didany = FALSE;
    if (gui.border_width < 0)
        gui.border_width = 0;
    if (font_argument != NULL)
        set_option_value ((char_u *) "gfn", 0L, (char_u *) font_argument, 0);
    if (gui_init_font (*p_guifont == NUL ? hl_get_font_name () : p_guifont, FALSE) == FAIL) {
        EMSG (_ ("E665: Cannot start GUI, no valid font found"));
        goto error2;
    }
    gui.num_cols = Columns;
    gui.num_rows = Rows;
    gui_reset_scroll_region ();
    FOR_ALL_WINDOWS (wp) {
        gui_create_scrollbar (& wp -> w_scrollbars [SBAR_LEFT], SBAR_LEFT, wp);
        gui_create_scrollbar (& wp -> w_scrollbars [SBAR_RIGHT], SBAR_RIGHT, wp);
    }
    gui_create_scrollbar (& gui.bottom_sbar, SBAR_BOTTOM, NULL);
    gui_create_initial_menus (root_menu);
    gui_init_which_components (NULL);
    gui.shell_created = TRUE;
    gui_set_shellsize (TRUE, TRUE, RESIZE_BOTH);
    if (gui_mch_open () != FAIL) {
        maketitle ();
        resettitle ();
        init_gui_options ();
        p_tbidi = FALSE;
        win_new_shellsize ();
        if (balloonEval != NULL)
            vim_free (balloonEval);
        balloonEvalForTerm = FALSE;
        balloonEval = gui_mch_create_beval_area (NULL, NULL, &general_beval_cb, NULL);
        if (!p_beval)
            gui_mch_disable_beval_area (balloonEval);
        if (p_ch != 1L)
            command_height ();
        return;
    }
error2 :
error :
    gui.in_use = FALSE;
    clip_init (FALSE);
}

int gui_init_check (void) {
    static int result = MAYBE;
    if (result != MAYBE) {
        if (result == FAIL)
            EMSG (_ ("E229: Cannot start the GUI"));
        return result;
    }
    gui.shell_created = FALSE;
    gui.dying = FALSE;
    gui.in_focus = TRUE;
    gui.dragged_sb = SBAR_NONE;
    gui.dragged_wp = NULL;
    gui.pointer_hidden = FALSE;
    gui.col = 0;
    gui.row = 0;
    gui.num_cols = Columns;
    gui.num_rows = Rows;
    gui.cursor_is_valid = FALSE;
    gui.scroll_region_top = 0;
    gui.scroll_region_bot = Rows - 1;
    gui.scroll_region_left = 0;
    gui.scroll_region_right = Columns - 1;
    gui.highlight_mask = HL_NORMAL;
    gui.char_width = 1;
    gui.char_height = 1;
    gui.char_ascent = 0;
    gui.border_width = 0;
    gui.norm_font = NOFONT;
    gui.bold_font = NOFONT;
    gui.ital_font = NOFONT;
    gui.boldital_font = NOFONT;
    gui.menu_font = NOFONT;
    gui.menu_is_active = TRUE;
    gui.scrollbar_width = gui.scrollbar_height = SB_DEFAULT_WIDTH;
    gui.prev_wrap = -1;
    result = gui_mch_init_check ();
    return result;
}

int gui_init_font (char_u *font_list, int fontset) {

    #define FONTLEN 320
    char_u font_name [FONTLEN];
    int font_list_empty = FALSE;
    int ret = FAIL;
    if (!gui.in_use)
        return FAIL;
    font_name[0] = NUL;
    if (*font_list == NUL)
        font_list_empty = TRUE;
    else {
        while (*font_list != NUL) {
            (void) copy_option_part (&font_list, font_name, FONTLEN, ",");
            if (STRCMP (font_name, "*") == 0) {
                gui_mch_init_font (font_name, FALSE);
                return FALSE;
            }
            if (gui_mch_init_font (font_name, FALSE) == OK) {
                ret = OK;
                break;
            }
        }
    }
    if (ret != OK && STRCMP (font_list, "*") != 0 && (font_list_empty || gui.norm_font == NOFONT)) {
        ret = gui_mch_init_font (NULL, FALSE);
    }
    if (ret == OK) {
        gui_mch_set_font (gui.norm_font);
        gui_set_shellsize (TRUE, TRUE, RESIZE_BOTH);
    }
    return ret;
}

guicolor_T gui_get_color (char_u *name) {
    guicolor_T t;
    if (*name == NUL)
        return INVALCOLOR;
    t = gui_mch_get_color (name);
    if (t == INVALCOLOR)
        EMSG2 (_ ("E254: Cannot allocate color %s"), name);
    return t;
}

void gui_check_colors (void) {
    if (gui.norm_pixel == gui.back_pixel || gui.norm_pixel == INVALCOLOR) {
        gui_set_bg_color ((char_u *) "White");
        if (gui.norm_pixel == gui.back_pixel || gui.norm_pixel == INVALCOLOR)
            gui_set_fg_color ((char_u *) "Black");
    }
}

static void gui_set_bg_color (char_u *name) {
    gui.back_pixel = gui_get_color (name);
    hl_set_bg_color_name (vim_strsave (name));
}

static void gui_set_fg_color (char_u *name) {
    gui.norm_pixel = gui_get_color (name);
    hl_set_fg_color_name (vim_strsave (name));
}

void gui_send_mouse_event (int button, int x, int y, int repeated_click, int_u modifiers) {
    static int prev_row = 0, prev_col = 0;
    static int prev_button = -1;
    static int num_clicks = 1;
    char_u string [10];
    enum key_extra button_char;
    int row, col;
    switch (button) {
    case MOUSE_X1 :
        button_char = KE_X1MOUSE;
        goto button_set;
    case MOUSE_X2 :
        button_char = KE_X2MOUSE;
        goto button_set;
    case MOUSE_4 :
        button_char = KE_MOUSEDOWN;
        goto button_set;
    case MOUSE_5 :
        button_char = KE_MOUSEUP;
        goto button_set;
    case MOUSE_6 :
        button_char = KE_MOUSELEFT;
        goto button_set;
    case MOUSE_7 :
        button_char = KE_MOUSERIGHT;
    button_set :
        {
            if (hold_gui_events)
                return;
            string[3] = CSI;
            string[4] = KS_EXTRA;
            string[5] = (int) button_char;
            row = gui_xy2colrow (x, y, &col);
            string[6] = (char_u) (col / 128 + ' ' + 1);
            string[7] = (char_u) (col % 128 + ' ' + 1);
            string[8] = (char_u) (row / 128 + ' ' + 1);
            string[9] = (char_u) (row % 128 + ' ' + 1);
            if (modifiers == 0)
                add_to_input_buf (string +3, 7);
            else {
                string[0] = CSI;
                string[1] = KS_MODIFIER;
                string[2] = 0;
                if (modifiers & MOUSE_SHIFT)
                    string[2] |= MOD_MASK_SHIFT;
                if (modifiers & MOUSE_CTRL)
                    string[2] |= MOD_MASK_CTRL;
                if (modifiers & MOUSE_ALT)
                    string[2] |= MOD_MASK_ALT;
                add_to_input_buf (string, 10);
            }
            return;
        }
    }
    if (hold_gui_events)
        return;
    row = gui_xy2colrow (x, y, &col);
    if (button == MOUSE_DRAG) {
        if (row == prev_row && col == prev_col)
            return;
        if (y < 0)
            row = -1;
    }
    if (curwin->w_topline != gui_prev_topline || curwin->w_topfill != gui_prev_topfill)
        repeated_click = FALSE;
    string[0] = CSI;
    string[1] = KS_MOUSE;
    string[2] = KE_FILLER;
    if (button != MOUSE_DRAG && button != MOUSE_RELEASE) {
        if (repeated_click) {
            if (button != prev_button || row != prev_row || col != prev_col)
                num_clicks = 1;
            else if (++num_clicks > 4)
                num_clicks = 1;
        }
        else
            num_clicks = 1;
        prev_button = button;
        gui_prev_topline = curwin->w_topline;
        gui_prev_topfill = curwin->w_topfill;
        string[3] = (char_u) (button | 0x20);
        SET_NUM_MOUSE_CLICKS (string [3], num_clicks);
    }
    else
        string[3] = (char_u) button;
    string[3] |= modifiers;
    fill_mouse_coord (string + 4, col, row);
    add_to_input_buf (string, 8);
    if (row < 0)
        prev_row = 0;
    else
        prev_row = row;
    prev_col = col;
}

int gui_xy2colrow (int x, int y, int *colp) {
    int col = check_col (X_2_COL (x));
    int row = check_row (Y_2_ROW (y));
    *colp = col;
    return row;
}

static void fill_mouse_coord (char_u *p, int col, int row) {
    p[0] = (char_u) (col / 128 + ' ' + 1);
    p[1] = (char_u) (col % 128 + ' ' + 1);
    p[2] = (char_u) (row / 128 + ' ' + 1);
    p[3] = (char_u) (row % 128 + ' ' + 1);
}

int gui_get_lightness (guicolor_T pixel) {
    long_u rgb = (long_u) gui_mch_get_rgb (pixel);
    return (int) ((((rgb >> 16) & 0xff) * 299) + (((rgb >> 8) & 0xff) * 587) + ((rgb & 0xff) * 114)) / 1000;
}

void gui_update_cursor_later (void) {
    OUT_STR (IF_EB ("\033|s", ESC_STR "|s"));
}

void gui_remove_scrollbars (void) {
    int i;
    win_T *wp;
    for (i = 0; i < 3; i++) {
        if (i == SBAR_BOTTOM)
            gui_mch_enable_scrollbar (&gui.bottom_sbar, FALSE);
        else {
            FOR_ALL_WINDOWS (wp) {
                gui_do_scrollbar (wp, i, FALSE);
            }
        }
        curtab->tp_prev_which_scrollbars[i] = -1;
    }
}

void gui_may_update_scrollbars (void) {
    if (gui.in_use && starting == 0) {
        out_flush ();
        gui_init_which_components (NULL);
        gui_update_scrollbars (TRUE);
    }
    need_mouse_correct = TRUE;
}

void gui_mouse_correct (void) {
    int x, y;
    win_T *wp = NULL;
    need_mouse_correct = FALSE;
    if (!(gui.in_use && p_mousef))
        return;
    gui_mch_getmouse (& x, & y);
    if (x < 0 || x > Columns * gui.char_width)
        return;
    if (y >= 0 && Y_2_ROW (y) >= tabline_height ())
        wp = xy2win (x, y);
    if (wp != curwin && wp != NULL) {
        validate_cline_row ();
        gui_mch_setmouse ((int) W_ENDCOL (curwin) * gui.char_width - 3, (W_WINROW (curwin) + curwin -> w_wrow) * gui.char_height + (gui.char_height) / 2);
    }
}

static win_T *xy2win (int x, int y) {
    int row;
    int col;
    win_T *wp;
    row = Y_2_ROW (y);
    col = X_2_COL (x);
    if (row < 0 || col < 0 || col >= Columns || row >= Rows) {
        update_mouseshape (SHAPE_IDX_N);
        return NULL;
    }
    wp = mouse_find_win (&row, &col);
    if (wp == NULL)
        return NULL;
    return wp;
}

int gui_do_horiz_scroll (long_u leftcol, int compute_longest_lnum) {
    if (curwin->w_p_wrap)
        return FALSE;
    if (curwin->w_leftcol == (colnr_T) leftcol)
        return FALSE;
    curwin->w_leftcol = (colnr_T) leftcol;
    if (vim_strchr (p_go, GO_HORSCROLL) == NULL && !virtual_active () && (colnr_T) leftcol > scroll_line_len (curwin->w_cursor.lnum)) {
        if (compute_longest_lnum) {
            curwin->w_cursor.lnum = gui_find_longest_lnum ();
            curwin->w_cursor.col = 0;
        }
        else if (longest_lnum >= curwin->w_topline && longest_lnum < curwin->w_botline) {
            curwin->w_cursor.lnum = longest_lnum;
            curwin->w_cursor.col = 0;
        }
    }
    return leftcol_changed ();
}

static void gui_outstr (char_u *s, int len) {
    int this_len;
    if (len == 0)
        return;
    if (len < 0)
        len = (int) STRLEN (s);
    while (len > 0) {
        if (gui.col + len > Columns)
            this_len = Columns - gui.col;
        else
            this_len = len;
        (void) gui_outstr_nowrap (s, this_len, 0, (guicolor_T) 0, (guicolor_T) 0, 0);
        s += this_len;
        len -= this_len;
        if (gui.col >= Columns) {
            gui.col = 0;
            gui.row++;
        }
    }
}

void gui_start (void) {
    char_u *old_term;
    static int recursive = 0;
    old_term = vim_strsave (T_NAME);
    settmode (TMODE_COOK);
    if (full_screen)
        cursor_on ();
    full_screen = FALSE;
    ++recursive;
    {
        gui_attempt_start ();
    }
    if (!gui.in_use) {
        termcapinit (old_term);
        settmode (TMODE_RAW);
        set_title_defaults ();
    }
    vim_free (old_term);
    gui_mch_update ();
    apply_autocmds (gui.in_use ? EVENT_GUIENTER : EVENT_GUIFAILED, NULL, NULL, FALSE, curbuf);
    --recursive;
}

static void gui_attempt_start (void) {
    static int recursive = 0;
    ++recursive;
    gui.starting = TRUE;
    termcapinit ((char_u *) "builtin_gui");
    gui.starting = recursive - 1;
    --recursive;
}

void gui_redraw (int x, int y, int w, int h) {
    int row1, col1, row2, col2;
    row1 = Y_2_ROW (y);
    col1 = X_2_COL (x);
    row2 = Y_2_ROW (y +h - 1);
    col2 = X_2_COL (x +w - 1);
    (void) gui_redraw_block (row1, col1, row2, col2, GUI_MON_NOCLEAR);
    if (gui.row == gui.cursor_row)
        gui_update_cursor (TRUE, TRUE);
}

void gui_focus_change (int in_focus) {
}

void gui_mouse_moved (int x, int y) {
    win_T *wp;
    char_u st [8];
    if (!gui.in_use || gui.starting)
        return;
    if (p_mousef && !hold_gui_events && (State & (NORMAL | INSERT)) && State != HITRETURN && msg_scrolled == 0 && !need_mouse_correct && gui.in_focus) {
        if (x < 0 || x > Columns * gui.char_width)
            return;
        wp = xy2win (x, y);
        if (wp == curwin || wp == NULL)
            return;
        if (Y_2_ROW (y) < tabline_height ())
            return;
        if (finish_op) {
            st[0] = ESC;
            add_to_input_buf (st, 1);
        }
        st[0] = CSI;
        st[1] = KS_MOUSE;
        st[2] = KE_FILLER;
        st[3] = (char_u) MOUSE_LEFT;
        fill_mouse_coord (st + 4, wp -> w_wincol == 0 ? - 1 : wp -> w_wincol + MOUSE_COLOFF, wp -> w_height + W_WINROW (wp));
        add_to_input_buf (st, 8);
        st[3] = (char_u) MOUSE_RELEASE;
        add_to_input_buf (st, 8);
    }
}

static win_T *xy2win (int x, int y) {
    int row;
    int col;
    win_T *wp;
    row = Y_2_ROW (y);
    col = X_2_COL (x);
    if (row < 0 || col < 0 || col >= Columns || row >= Rows) {
        update_mouseshape (SHAPE_IDX_N);
        return NULL;
    }
    wp = mouse_find_win (&row, &col);
    if (wp == NULL)
        return NULL;
    if (State == HITRETURN || State == ASKMORE) {
        if (Y_2_ROW (y) >= msg_row)
            update_mouseshape (SHAPE_IDX_MOREL);
        else
            update_mouseshape (SHAPE_IDX_MORE);
    }
    else if (row > wp->w_height)
        update_mouseshape (SHAPE_IDX_CLINE);
    else if (!(State & CMDLINE) && wp->w_vsep_width > 0 && col == wp->w_width && (row != wp->w_height || !stl_connected (wp)) && msg_scrolled == 0)
        update_mouseshape (SHAPE_IDX_VSEP);
    else if (!(State & CMDLINE) && wp->w_status_height > 0 && row == wp->w_height && msg_scrolled == 0)
        update_mouseshape (SHAPE_IDX_STATUS);
    else
        update_mouseshape (-2);
    return wp;
}

void gui_mouse_moved (int x, int y) {
    win_T *wp;
    char_u st [8];
    if (!gui.in_use || gui.starting)
        return;
    wp = xy2win (x, y);
    if (p_mousef && !hold_gui_events && (State & (NORMAL | INSERT)) && State != HITRETURN && msg_scrolled == 0 && !need_mouse_correct && gui.in_focus) {
        if (x < 0 || x > Columns * gui.char_width)
            return;
        if (wp == curwin || wp == NULL)
            return;
        if (Y_2_ROW (y) < tabline_height ())
            return;
        if (finish_op) {
            st[0] = ESC;
            add_to_input_buf (st, 1);
        }
        st[0] = CSI;
        st[1] = KS_MOUSE;
        st[2] = KE_FILLER;
        st[3] = (char_u) MOUSE_LEFT;
        fill_mouse_coord (st + 4, wp -> w_wincol == 0 ? - 1 : wp -> w_wincol + MOUSE_COLOFF, wp -> w_height + W_WINROW (wp));
        add_to_input_buf (st, 8);
        st[3] = (char_u) MOUSE_RELEASE;
        add_to_input_buf (st, 8);
    }
}

