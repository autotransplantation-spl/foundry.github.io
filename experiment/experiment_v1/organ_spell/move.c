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
struct buffheader {
    buffblock_T bh_first;
    buffblock_T *bh_curr;
    int bh_index;
    int bh_space;
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
struct buffblock {
    buffblock_T *b_next;
    char_u b_str [1];
};
EXTERN long  p_sj;
EXTERN long  Rows;
EXTERN long  p_window;
EXTERN long  p_ss;
EXTERN long  p_siso;
EXTERN char_u *p_sbr;
EXTERN long  p_so;
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
EXTERN int p_altkeymap;
EXTERN int p_arshape;
EXTERN int p_macligatures;
EXTERN long  p_stal;
EXTERN int p_lrm;
EXTERN char *ignoredp;

void scrolldown (long  line_count, int byfold) {
    long  done = 0;
    int wrow;
    int moved = FALSE;
    linenr_T first;
    (void) hasFolding (curwin->w_topline, &curwin->w_topline, NULL);
    validate_cursor ();
    while (line_count-- > 0) {
        if (curwin->w_topfill < diff_check (curwin, curwin->w_topline) && curwin->w_topfill < curwin->w_height - 1) {
            ++curwin->w_topfill;
            ++done;
        }
        else {
            if (curwin->w_topline == 1)
                break;
            --curwin->w_topline;
            curwin->w_topfill = 0;
            if (hasFolding (curwin->w_topline, &first, NULL)) {
                ++done;
                if (!byfold)
                    line_count -= curwin->w_topline - first - 1;
                curwin->w_botline -= curwin->w_topline - first;
                curwin->w_topline = first;
            }
            else
                done += PLINES_NOFILL (curwin->w_topline);
        }
        --curwin->w_botline;
        invalidate_botline ();
    }
    curwin->w_wrow += done;
    curwin->w_cline_row += done;
    if (curwin->w_cursor.lnum == curwin->w_topline)
        curwin->w_cline_row = 0;
    check_topfill (curwin, TRUE);
    wrow = curwin->w_wrow;
    if (curwin->w_p_wrap && curwin->w_width != 0) {
        validate_virtcol ();
        validate_cheight ();
        wrow += curwin->w_cline_height - 1 - curwin->w_virtcol / curwin->w_width;
    }
    while (wrow >= curwin->w_height && curwin->w_cursor.lnum > 1) {
        if (hasFolding (curwin->w_cursor.lnum, &first, NULL)) {
            --wrow;
            if (first == 1)
                curwin->w_cursor.lnum = 1;
            else
                curwin->w_cursor.lnum = first - 1;
        }
        else
            wrow -= plines (curwin->w_cursor.lnum--);
        curwin->w_valid &= ~(VALID_WROW | VALID_WCOL | VALID_CHEIGHT | VALID_CROW | VALID_VIRTCOL);
        moved = TRUE;
    }
    if (moved) {
        foldAdjustCursor ();
        coladvance (curwin -> w_curswant);
    }
}

void validate_cursor (void) {
    check_cursor_moved (curwin);
    if ((curwin->w_valid & (VALID_WCOL | VALID_WROW)) != (VALID_WCOL | VALID_WROW))
        curs_columns (TRUE);
}

void check_cursor_moved (win_T *wp) {
    if (wp->w_cursor.lnum != wp->w_valid_cursor.lnum) {
        wp->w_valid &= ~(VALID_WROW | VALID_WCOL | VALID_VIRTCOL | VALID_CHEIGHT | VALID_CROW | VALID_TOPLINE);
        wp->w_valid_cursor = wp->w_cursor;
        wp->w_valid_leftcol = wp->w_leftcol;
    }
    else if (wp->w_cursor.col != wp->w_valid_cursor.col || wp->w_leftcol != wp->w_valid_leftcol || wp->w_cursor.coladd != wp->w_valid_cursor.coladd) {
        wp->w_valid &= ~(VALID_WROW | VALID_WCOL | VALID_VIRTCOL);
        wp->w_valid_cursor.col = wp->w_cursor.col;
        wp->w_valid_leftcol = wp->w_leftcol;
        wp->w_valid_cursor.coladd = wp->w_cursor.coladd;
    }
}

void curs_columns (int may_scroll) {
    int diff;
    int extra;
    int off_left, off_right;
    int n;
    int p_lines;
    int width = 0;
    int textwidth;
    int new_leftcol;
    colnr_T startcol;
    colnr_T endcol;
    colnr_T prev_skipcol;
    update_topline ();
    if (!(curwin->w_valid & VALID_CROW))
        curs_rows (curwin);
    if (curwin->w_cline_folded)
        startcol = curwin->w_virtcol = endcol = curwin->w_leftcol;
    else
        getvvcol (curwin, &curwin->w_cursor, &startcol, &(curwin->w_virtcol), &endcol);
    if (startcol > dollar_vcol)
        dollar_vcol = -1;
    extra = curwin_col_off ();
    curwin->w_wcol = curwin->w_virtcol + extra;
    endcol += extra;
    curwin->w_wrow = curwin->w_cline_row;
    textwidth = curwin->w_width - extra;
    if (textwidth <= 0) {
        curwin->w_wcol = curwin->w_width - 1;
        curwin->w_wrow = curwin->w_height - 1;
    }
    else if (curwin->w_p_wrap && curwin->w_width != 0) {
        width = textwidth + curwin_col_off2 ();
        if (curwin->w_wcol >= curwin->w_width) {
            n = (curwin->w_wcol - curwin->w_width) / width + 1;
            curwin->w_wcol -= n * width;
            curwin->w_wrow += n;
            if (*p_sbr && *ml_get_cursor () == NUL && curwin->w_wcol == (int) vim_strsize (p_sbr))
                curwin->w_wcol = 0;
        }
    }
    else if (may_scroll && !curwin->w_cline_folded) {
        off_left = (int) startcol - (int) curwin->w_leftcol - p_siso;
        off_right = (int) endcol - (int) (curwin->w_leftcol + curwin->w_width - p_siso) + 1;
        if (off_left < 0 || off_right > 0) {
            if (off_left < 0)
                diff = -off_left;
            else
                diff = off_right;
            if (p_ss == 0 || diff >= textwidth / 2 || off_right >= off_left)
                new_leftcol = curwin->w_wcol - extra - textwidth / 2;
            else {
                if (diff < p_ss)
                    diff = p_ss;
                if (off_left < 0)
                    new_leftcol = curwin->w_leftcol - diff;
                else
                    new_leftcol = curwin->w_leftcol + diff;
            }
            if (new_leftcol < 0)
                new_leftcol = 0;
            if (new_leftcol != (int) curwin->w_leftcol) {
                curwin->w_leftcol = new_leftcol;
                redraw_later (NOT_VALID);
            }
        }
        curwin->w_wcol -= curwin->w_leftcol;
    }
    else if (curwin->w_wcol > (int) curwin->w_leftcol)
        curwin->w_wcol -= curwin->w_leftcol;
    else
        curwin->w_wcol = 0;
    if (curwin->w_cursor.lnum == curwin->w_topline)
        curwin->w_wrow += curwin->w_topfill;
    else
        curwin->w_wrow += diff_check_fill (curwin, curwin->w_cursor.lnum);
    prev_skipcol = curwin->w_skipcol;
    p_lines = 0;
    if ((curwin->w_wrow >= curwin->w_height || ((prev_skipcol > 0 || curwin->w_wrow + p_so >= curwin->w_height) && (p_lines = plines_win_nofill (curwin, curwin->w_cursor.lnum, FALSE)) - 1 >= curwin->w_height)) && curwin->w_height != 0 && curwin->w_cursor.lnum == curwin->w_topline && width > 0 && curwin->w_width != 0) {
        extra = 0;
        if (curwin->w_skipcol + p_so * width > curwin->w_virtcol)
            extra = 1;
        if (p_lines == 0)
            p_lines = plines_win (curwin, curwin->w_cursor.lnum, FALSE);
        --p_lines;
        if (p_lines > curwin->w_wrow + p_so)
            n = curwin->w_wrow + p_so;
        else
            n = p_lines;
        if ((colnr_T) n >= curwin->w_height + curwin->w_skipcol / width)
            extra += 2;
        if (extra == 3 || p_lines < p_so * 2) {
            n = curwin->w_virtcol / width;
            if (n > curwin->w_height / 2)
                n -= curwin->w_height / 2;
            else
                n = 0;
            if (n > p_lines - curwin->w_height + 1)
                n = p_lines - curwin->w_height + 1;
            curwin->w_skipcol = n * width;
        }
        else if (extra == 1) {
            extra = (curwin->w_skipcol + p_so * width - curwin->w_virtcol + width - 1) / width;
            if (extra > 0) {
                if ((colnr_T) (extra * width) > curwin->w_skipcol)
                    extra = curwin->w_skipcol / width;
                curwin->w_skipcol -= extra * width;
            }
        }
        else if (extra == 2) {
            endcol = (n - curwin->w_height + 1) * width;
            while (endcol > curwin->w_virtcol)
                endcol -= width;
            if (endcol > curwin->w_skipcol)
                curwin->w_skipcol = endcol;
        }
        curwin->w_wrow -= curwin->w_skipcol / width;
        if (curwin->w_wrow >= curwin->w_height) {
            extra = curwin->w_wrow - curwin->w_height + 1;
            curwin->w_skipcol += extra * width;
            curwin->w_wrow -= extra;
        }
        extra = ((int) prev_skipcol - (int) curwin->w_skipcol) / width;
        if (extra > 0)
            win_ins_lines (curwin, 0, extra, FALSE, FALSE);
        else if (extra < 0)
            win_del_lines (curwin, 0, -extra, FALSE, FALSE, 0);
    }
    else
        curwin->w_skipcol = 0;
    if (prev_skipcol != curwin->w_skipcol)
        redraw_later (NOT_VALID);
    if (curwin->w_p_cuc && (curwin->w_valid & VALID_VIRTCOL) == 0 && !pum_visible ())
        redraw_later (SOME_VALID);
    curwin->w_valid |= VALID_WCOL | VALID_WROW | VALID_VIRTCOL;
}

void update_topline (void) {
    long  line_count;
    int halfheight;
    int n;
    linenr_T old_topline;
    int old_topfill;
    linenr_T lnum;
    int check_topline = FALSE;
    int check_botline = FALSE;
    int save_so = p_so;
    if (!screen_valid (TRUE) || curwin->w_height == 0) {
        curwin->w_topline = curwin->w_cursor.lnum;
        curwin->w_botline = curwin->w_topline;
        curwin->w_valid |= VALID_BOTLINE | VALID_BOTLINE_AP;
        curwin->w_scbind_pos = 1;
        return;
    }
    check_cursor_moved (curwin);
    if (curwin->w_valid & VALID_TOPLINE)
        return;
    if (mouse_dragging > 0)
        p_so = mouse_dragging - 1;
    old_topline = curwin->w_topline;
    old_topfill = curwin->w_topfill;
    if (BUFEMPTY ()) {
        if (curwin->w_topline != 1)
            redraw_later (NOT_VALID);
        curwin->w_topline = 1;
        curwin->w_botline = 2;
        curwin->w_valid |= VALID_BOTLINE | VALID_BOTLINE_AP;
        curwin->w_scbind_pos = 1;
    }
    else {
        if (curwin->w_topline > 1) {
            if (curwin->w_cursor.lnum < curwin->w_topline)
                check_topline = TRUE;
            else if (check_top_offset ())
                check_topline = TRUE;
        }
        if (!check_topline && curwin->w_topfill > diff_check_fill (curwin, curwin->w_topline))
            check_topline = TRUE;
        if (check_topline) {
            halfheight = curwin->w_height / 2 - 1;
            if (halfheight < 2)
                halfheight = 2;
            if (hasAnyFolding (curwin)) {
                n = 0;
                for (lnum = curwin->w_cursor.lnum; lnum < curwin->w_topline + p_so; ++lnum) {
                    ++n;
                    if (lnum >= curbuf->b_ml.ml_line_count || n >= halfheight)
                        break;
                    (void) hasFolding (lnum, NULL, &lnum);
                }
            }
            else
                n = curwin->w_topline + p_so - curwin->w_cursor.lnum;
            if (n >= halfheight)
                scroll_cursor_halfway (FALSE);
            else {
                scroll_cursor_top (scrolljump_value (), FALSE);
                check_botline = TRUE;
            }
        }
        else {
            (void) hasFolding (curwin->w_topline, &curwin->w_topline, NULL);
            check_botline = TRUE;
        }
    }
    if (check_botline) {
        if (!(curwin->w_valid & VALID_BOTLINE_AP))
            validate_botline ();
        if (curwin->w_botline <= curbuf->b_ml.ml_line_count) {
            if (curwin->w_cursor.lnum < curwin->w_botline) {
                if (((long ) curwin->w_cursor.lnum >= (long ) curwin->w_botline - p_so || hasAnyFolding (curwin))) {
                    lineoff_T loff;
                    n = curwin->w_empty_rows;
                    loff.lnum = curwin->w_cursor.lnum;
                    (void) hasFolding (loff.lnum, NULL, &loff.lnum);
                    loff.fill = 0;
                    n += curwin->w_filler_rows;
                    loff.height = 0;
                    while (loff.lnum < curwin->w_botline && (loff.lnum + 1 < curwin->w_botline || loff.fill == 0)) {
                        n += loff.height;
                        if (n >= p_so)
                            break;
                        botline_forw (& loff);
                    }
                    if (n >= p_so)
                        check_botline = FALSE;
                }
                else
                    check_botline = FALSE;
            }
            if (check_botline) {
                if (hasAnyFolding (curwin)) {
                    line_count = 0;
                    for (lnum = curwin->w_cursor.lnum; lnum >= curwin->w_botline - p_so; --lnum) {
                        ++line_count;
                        if (lnum <= 0 || line_count > curwin->w_height + 1)
                            break;
                        (void) hasFolding (lnum, &lnum, NULL);
                    }
                }
                else
                    line_count = curwin->w_cursor.lnum - curwin->w_botline + 1 + p_so;
                if (line_count <= curwin->w_height + 1)
                    scroll_cursor_bot (scrolljump_value (), FALSE);
                else
                    scroll_cursor_halfway (FALSE);
            }
        }
    }
    curwin->w_valid |= VALID_TOPLINE;
    if (curwin->w_topline != old_topline || curwin->w_topfill != old_topfill) {
        dollar_vcol = -1;
        if (curwin->w_skipcol != 0) {
            curwin->w_skipcol = 0;
            redraw_later (NOT_VALID);
        }
        else
            redraw_later (VALID);
        if (curwin->w_cursor.lnum == curwin->w_topline)
            validate_cursor ();
    }
    p_so = save_so;
}

void validate_virtcol (void) {
    validate_virtcol_win (curwin);
}

void validate_virtcol_win (win_T *wp) {
    check_cursor_moved (wp);
    if (!(wp->w_valid & VALID_VIRTCOL)) {
        getvvcol (wp, & wp -> w_cursor, NULL, & (wp -> w_virtcol), NULL);
        wp->w_valid |= VALID_VIRTCOL;
        if (wp->w_p_cuc && !pum_visible ())
            redraw_win_later (wp, SOME_VALID);
    }
}

int win_col_off (win_T *wp) {
    return (((wp->w_p_nu || wp->w_p_rnu) ? number_width (wp) + 1 : 0) + wp->w_p_fdc + (signcolumn_on (wp) ? 2 : 0));
}

int win_col_off2 (win_T *wp) {
    if ((wp->w_p_nu || wp->w_p_rnu) && vim_strchr (p_cpo, CPO_NUMCOL) != NULL)
        return number_width (wp) + 1;
    return 0;
}

void changed_window_setting (void) {
    changed_window_setting_win (curwin);
}

void changed_window_setting_win (win_T *wp) {
    wp->w_lines_valid = 0;
    changed_line_abv_curs_win (wp);
    wp->w_valid &= ~(VALID_BOTLINE | VALID_BOTLINE_AP | VALID_TOPLINE);
    redraw_win_later (wp, NOT_VALID);
}

void changed_line_abv_curs_win (win_T *wp) {
    wp->w_valid &= ~(VALID_WROW | VALID_WCOL | VALID_VIRTCOL | VALID_CROW | VALID_CHEIGHT | VALID_TOPLINE);
}

void update_curswant (void) {
    if (curwin->w_set_curswant) {
        validate_virtcol ();
        curwin->w_curswant = curwin->w_virtcol;
        curwin->w_set_curswant = FALSE;
    }
}

void changed_line_abv_curs (void) {
    curwin->w_valid &= ~(VALID_WROW | VALID_WCOL | VALID_VIRTCOL | VALID_CROW | VALID_CHEIGHT | VALID_TOPLINE);
}

void invalidate_botline (void) {
    curwin->w_valid &= ~(VALID_BOTLINE | VALID_BOTLINE_AP);
}

void invalidate_botline_win (win_T *wp) {
    wp->w_valid &= ~(VALID_BOTLINE | VALID_BOTLINE_AP);
}

void check_topfill (win_T *wp, int down) {
    int n;
    if (wp->w_topfill > 0) {
        n = plines_win_nofill (wp, wp->w_topline, TRUE);
        if (wp->w_topfill + n > wp->w_height) {
            if (down && wp->w_topline > 1) {
                --wp->w_topline;
                wp->w_topfill = 0;
            }
            else {
                wp->w_topfill = wp->w_height - n;
                if (wp->w_topfill < 0)
                    wp->w_topfill = 0;
            }
        }
    }
}

void scrollup (long  line_count, int byfold) {
    linenr_T lnum;
    if ((byfold && hasAnyFolding (curwin)) || curwin->w_p_diff) {
        lnum = curwin->w_topline;
        while (line_count--) {
            if (curwin->w_topfill > 0)
                --curwin->w_topfill;
            else {
                if (byfold)
                    (void) hasFolding (lnum, NULL, &lnum);
                if (lnum >= curbuf->b_ml.ml_line_count)
                    break;
                ++lnum;
                curwin->w_topfill = diff_check_fill (curwin, lnum);
            }
        }
        curwin->w_botline += lnum - curwin->w_topline;
        curwin->w_topline = lnum;
    }
    else {
        curwin->w_topline += line_count;
        curwin->w_botline += line_count;
    }
    if (curwin->w_topline > curbuf->b_ml.ml_line_count)
        curwin->w_topline = curbuf->b_ml.ml_line_count;
    if (curwin->w_botline > curbuf->b_ml.ml_line_count + 1)
        curwin->w_botline = curbuf->b_ml.ml_line_count + 1;
    check_topfill (curwin, FALSE);
    if (hasAnyFolding (curwin))
        (void) hasFolding (curwin->w_topline, &curwin->w_topline, NULL);
    curwin->w_valid &= ~(VALID_WROW | VALID_CROW | VALID_BOTLINE);
    if (curwin->w_cursor.lnum < curwin->w_topline) {
        curwin->w_cursor.lnum = curwin->w_topline;
        curwin->w_valid &= ~(VALID_WROW | VALID_WCOL | VALID_CHEIGHT | VALID_CROW | VALID_VIRTCOL);
        coladvance (curwin -> w_curswant);
    }
}

void cursor_correct (void) {
    int above = 0;
    linenr_T topline;
    int below = 0;
    linenr_T botline;
    int above_wanted, below_wanted;
    linenr_T cln;
    int max_off;
    above_wanted = p_so;
    below_wanted = p_so;
    if (mouse_dragging > 0) {
        above_wanted = mouse_dragging - 1;
        below_wanted = mouse_dragging - 1;
    }
    if (curwin->w_topline == 1) {
        above_wanted = 0;
        max_off = curwin->w_height / 2;
        if (below_wanted > max_off)
            below_wanted = max_off;
    }
    validate_botline ();
    if (curwin->w_botline == curbuf->b_ml.ml_line_count + 1 && mouse_dragging == 0) {
        below_wanted = 0;
        max_off = (curwin->w_height - 1) / 2;
        if (above_wanted > max_off)
            above_wanted = max_off;
    }
    cln = curwin->w_cursor.lnum;
    if (cln >= curwin->w_topline + above_wanted && cln < curwin->w_botline - below_wanted && !hasAnyFolding (curwin))
        return;
    topline = curwin->w_topline;
    botline = curwin->w_botline - 1;
    above = curwin->w_topfill;
    below = curwin->w_filler_rows;
    while ((above < above_wanted || below < below_wanted) && topline < botline) {
        if (below < below_wanted && (below <= above || above >= above_wanted)) {
            if (hasFolding (botline, &botline, NULL))
                ++below;
            else
                below += plines (botline);
            --botline;
        }
        if (above < above_wanted && (above < below || below >= below_wanted)) {
            if (hasFolding (topline, NULL, &topline))
                ++above;
            else
                above += PLINES_NOFILL (topline);
            if (topline < botline)
                above += diff_check_fill (curwin, topline +1);
            ++topline;
        }
    }
    if (topline == botline || botline == 0)
        curwin->w_cursor.lnum = topline;
    else if (topline > botline)
        curwin->w_cursor.lnum = botline;
    else {
        if (cln < topline && curwin->w_topline > 1) {
            curwin->w_cursor.lnum = topline;
            curwin->w_valid &= ~(VALID_WROW | VALID_WCOL | VALID_CHEIGHT | VALID_CROW);
        }
        if (cln > botline && curwin->w_botline <= curbuf->b_ml.ml_line_count) {
            curwin->w_cursor.lnum = botline;
            curwin->w_valid &= ~(VALID_WROW | VALID_WCOL | VALID_CHEIGHT | VALID_CROW);
        }
    }
    curwin->w_valid |= VALID_TOPLINE;
}

void validate_botline (void) {
    if (!(curwin->w_valid & VALID_BOTLINE))
        comp_botline (curwin);
}

static void comp_botline (win_T *wp) {
    int n;
    linenr_T lnum;
    int done;
    linenr_T last;
    int folded;
    check_cursor_moved (wp);
    if (wp->w_valid & VALID_CROW) {
        lnum = wp->w_cursor.lnum;
        done = wp->w_cline_row;
    }
    else {
        lnum = wp->w_topline;
        done = 0;
    }
    for (; lnum <= wp->w_buffer->b_ml.ml_line_count; ++lnum) {
        last = lnum;
        folded = FALSE;
        if (hasFoldingWin (wp, lnum, NULL, &last, TRUE, NULL)) {
            n = 1;
            folded = TRUE;
        }
        else if (lnum == wp->w_topline)
            n = plines_win_nofill (wp, lnum, TRUE) + wp->w_topfill;
        else
            n = plines_win (wp, lnum, TRUE);
        if (lnum <= wp->w_cursor.lnum && last >= wp->w_cursor.lnum) {
            wp->w_cline_row = done;
            wp->w_cline_height = n;
            wp->w_cline_folded = folded;
            redraw_for_cursorline (wp);
            wp->w_valid |= (VALID_CROW | VALID_CHEIGHT);
        }
        if (done + n > wp->w_height)
            break;
        done += n;
        lnum = last;
    }
    wp->w_botline = lnum;
    wp->w_valid |= VALID_BOTLINE | VALID_BOTLINE_AP;
    set_empty_rows (wp, done);
}

static void redraw_for_cursorline (win_T *wp) {
    if ((wp->w_p_rnu || wp->w_p_cul) && (wp->w_valid & VALID_CROW) == 0 && !pum_visible ())
        redraw_win_later (wp, SOME_VALID);
}

void set_empty_rows (win_T *wp, int used) {
    wp->w_filler_rows = 0;
    if (used == 0)
        wp->w_empty_rows = 0;
    else {
        wp->w_empty_rows = wp->w_height - used;
        if (wp->w_botline <= wp->w_buffer->b_ml.ml_line_count) {
            wp->w_filler_rows = diff_check_fill (wp, wp->w_botline);
            if (wp->w_empty_rows > wp->w_filler_rows)
                wp->w_empty_rows -= wp->w_filler_rows;
            else {
                wp->w_filler_rows = wp->w_empty_rows;
                wp->w_empty_rows = 0;
            }
        }
    }
}

void changed_cline_bef_curs (void) {
    curwin->w_valid &= ~(VALID_WROW | VALID_WCOL | VALID_VIRTCOL | VALID_CHEIGHT | VALID_TOPLINE);
}

int curwin_col_off (void) {
    return win_col_off (curwin);
}

void scroll_cursor_halfway (int atend) {
    int above = 0;
    linenr_T topline;
    int topfill = 0;
    int below = 0;
    int used;
    lineoff_T loff;
    lineoff_T boff;
    linenr_T old_topline = curwin->w_topline;
    loff.lnum = boff.lnum = curwin->w_cursor.lnum;
    (void) hasFolding (loff.lnum, &loff.lnum, &boff.lnum);
    used = plines_nofill (loff.lnum);
    loff.fill = 0;
    boff.fill = 0;
    topline = loff.lnum;
    while (topline > 1) {
        if (below <= above) {
            if (boff.lnum < curbuf->b_ml.ml_line_count) {
                botline_forw (& boff);
                used += boff.height;
                if (used > curwin->w_height)
                    break;
                below += boff.height;
            }
            else {
                ++below;
                if (atend)
                    ++used;
            }
        }
        if (below > above) {
            topline_back (& loff);
            if (loff.height == MAXCOL)
                used = MAXCOL;
            else
                used += loff.height;
            if (used > curwin->w_height)
                break;
            above += loff.height;
            topline = loff.lnum;
            topfill = loff.fill;
        }
    }
    if (!hasFolding (topline, &curwin->w_topline, NULL))
        curwin->w_topline = topline;
    curwin->w_topfill = topfill;
    if (old_topline > curwin->w_topline + curwin->w_height)
        curwin->w_botfill = FALSE;
    check_topfill (curwin, FALSE);
    curwin->w_valid &= ~(VALID_WROW | VALID_CROW | VALID_BOTLINE | VALID_BOTLINE_AP);
    curwin->w_valid |= VALID_TOPLINE;
}

static void botline_forw (lineoff_T *lp) {
    if (lp->fill < diff_check_fill (curwin, lp->lnum + 1)) {
        ++lp->fill;
        lp->height = 1;
    }
    else {
        ++lp->lnum;
        lp->fill = 0;
        if (lp->lnum > curbuf->b_ml.ml_line_count)
            lp->height = MAXCOL;
        else if (hasFolding (lp->lnum, NULL, &lp->lnum))
            lp->height = 1;
        else {
            lp->height = PLINES_NOFILL (lp->lnum);
        }
    }
}

static void topline_back (lineoff_T *lp) {
    if (lp->fill < diff_check_fill (curwin, lp->lnum)) {
        ++lp->fill;
        lp->height = 1;
    }
    else {
        --lp->lnum;
        lp->fill = 0;
        if (lp->lnum < 1)
            lp->height = MAXCOL;
        else if (hasFolding (lp->lnum, &lp->lnum, NULL))
            lp->height = 1;
        else
            lp->height = PLINES_NOFILL (lp->lnum);
    }
}

void validate_cline_row (void) {
    update_topline ();
    check_cursor_moved (curwin);
    if (!(curwin->w_valid & VALID_CROW))
        curs_rows (curwin);
}

static void curs_rows (win_T *wp) {
    linenr_T lnum;
    int i;
    int all_invalid;
    int valid;
    long  fold_count;
    all_invalid = (!redrawing () || wp->w_lines_valid == 0 || wp->w_lines[0].wl_lnum > wp->w_topline);
    i = 0;
    wp->w_cline_row = 0;
    for (lnum = wp->w_topline; lnum < wp->w_cursor.lnum; ++i) {
        valid = FALSE;
        if (!all_invalid && i < wp->w_lines_valid) {
            if (wp->w_lines[i].wl_lnum < lnum || !wp->w_lines[i].wl_valid)
                continue;
            if (wp->w_lines[i].wl_lnum == lnum) {
                if (!wp->w_buffer->b_mod_set || wp->w_lines[i].wl_lastlnum < wp->w_cursor.lnum || wp->w_buffer->b_mod_top > wp->w_lines[i].wl_lastlnum + 1)
                    valid = TRUE;
            }
            else if (wp->w_lines[i].wl_lnum > lnum)
                --i;
        }
        if (valid && (lnum != wp->w_topline || !wp->w_p_diff)) {
            lnum = wp->w_lines[i].wl_lastlnum + 1;
            if (lnum > wp->w_cursor.lnum)
                break;
            wp->w_cline_row += wp->w_lines[i].wl_size;
        }
        else {
            fold_count = foldedCount (wp, lnum, NULL);
            if (fold_count) {
                lnum += fold_count;
                if (lnum > wp->w_cursor.lnum)
                    break;
                ++wp->w_cline_row;
            }
            else if (lnum == wp->w_topline)
                wp->w_cline_row += plines_win_nofill (wp, lnum++, TRUE) + wp->w_topfill;
            else
                wp->w_cline_row += plines_win (wp, lnum++, TRUE);
        }
    }
    check_cursor_moved (wp);
    if (!(wp->w_valid & VALID_CHEIGHT)) {
        if (all_invalid || i == wp->w_lines_valid || (i < wp->w_lines_valid && (!wp->w_lines[i].wl_valid || wp->w_lines[i].wl_lnum != wp->w_cursor.lnum))) {
            if (wp->w_cursor.lnum == wp->w_topline)
                wp->w_cline_height = plines_win_nofill (wp, wp->w_cursor.lnum, TRUE) + wp->w_topfill;
            else
                wp->w_cline_height = plines_win (wp, wp->w_cursor.lnum, TRUE);
            wp->w_cline_folded = hasFoldingWin (wp, wp->w_cursor.lnum, NULL, NULL, TRUE, NULL);
        }
        else if (i > wp->w_lines_valid) {
            wp->w_cline_height = 0;
            wp->w_cline_folded = hasFoldingWin (wp, wp->w_cursor.lnum, NULL, NULL, TRUE, NULL);
        }
        else {
            wp->w_cline_height = wp->w_lines[i].wl_size;
            wp->w_cline_folded = wp->w_lines[i].wl_folded;
        }
    }
    redraw_for_cursorline (curwin);
    redraw_for_ligatures (curwin);
    wp->w_valid |= VALID_CROW | VALID_CHEIGHT;
}

void do_check_cursorbind (void) {
    linenr_T line = curwin->w_cursor.lnum;
    colnr_T col = curwin->w_cursor.col;
    colnr_T coladd = curwin->w_cursor.coladd;
    colnr_T curswant = curwin->w_curswant;
    int set_curswant = curwin->w_set_curswant;
    win_T *old_curwin = curwin;
    buf_T *old_curbuf = curbuf;
    int restart_edit_save;
    int old_VIsual_select = VIsual_select;
    int old_VIsual_active = VIsual_active;
    VIsual_select = VIsual_active = 0;
    FOR_ALL_WINDOWS (curwin) {
        curbuf = curwin->w_buffer;
        if (curwin != old_curwin && curwin->w_p_crb) {
            if (curwin->w_p_diff)
                curwin->w_cursor.lnum = diff_get_corresponding_line (old_curbuf, line);
            else
                curwin->w_cursor.lnum = line;
            curwin->w_cursor.col = col;
            curwin->w_cursor.coladd = coladd;
            curwin->w_curswant = curswant;
            curwin->w_set_curswant = set_curswant;
            restart_edit_save = restart_edit;
            restart_edit = TRUE;
            check_cursor ();
            if (curwin->w_p_cul || curwin->w_p_cuc)
                validate_cursor ();
            restart_edit = restart_edit_save;
            redraw_later (VALID);
            if (!curwin->w_p_scb)
                update_topline ();
            curwin->w_redr_status = TRUE;
        }
    }
    VIsual_select = old_VIsual_select;
    VIsual_active = old_VIsual_active;
    curwin = old_curwin;
    curbuf = old_curbuf;
}

void validate_cursor_col (void) {
    colnr_T off;
    colnr_T col;
    int width;
    validate_virtcol ();
    if (!(curwin->w_valid & VALID_WCOL)) {
        col = curwin->w_virtcol;
        off = curwin_col_off ();
        col += off;
        width = curwin->w_width - off + curwin_col_off2 ();
        if (curwin->w_p_wrap && col >= (colnr_T) curwin->w_width && width > 0)
            col -= ((col - curwin->w_width) / width + 1) * width;
        if (col > (int) curwin->w_leftcol)
            col -= curwin->w_leftcol;
        else
            col = 0;
        curwin->w_wcol = col;
        curwin->w_valid |= VALID_WCOL;
    }
}

int curwin_col_off2 (void) {
    return win_col_off2 (curwin);
}

void set_topline (win_T *wp, linenr_T lnum) {
    (void) hasFoldingWin (wp, lnum, &lnum, NULL, TRUE, NULL);
    wp->w_botline += lnum - wp->w_topline;
    wp->w_topline = lnum;
    wp->w_topline_was_set = TRUE;
    wp->w_topfill = 0;
    wp->w_valid &= ~(VALID_WROW | VALID_CROW | VALID_BOTLINE | VALID_TOPLINE);
    redraw_later (VALID);
}

int onepage (int dir, long  count) {
    long  n;
    int retval = OK;
    lineoff_T loff;
    linenr_T old_topline = curwin->w_topline;
    if (curbuf->b_ml.ml_line_count == 1) {
        beep_flush ();
        return FAIL;
    }
    for (; count > 0; --count) {
        validate_botline ();
        if (dir == FORWARD ? ((curwin->w_topline >= curbuf->b_ml.ml_line_count - p_so) && curwin->w_botline > curbuf->b_ml.ml_line_count) : (curwin->w_topline == 1 && curwin->w_topfill == diff_check_fill (curwin, curwin->w_topline))) {
            beep_flush ();
            retval = FAIL;
            break;
        }
        loff.fill = 0;
        if (dir == FORWARD) {
            if (ONE_WINDOW && p_window > 0 && p_window < Rows - 1) {
                if (p_window <= 2)
                    ++curwin->w_topline;
                else
                    curwin->w_topline += p_window - 2;
                if (curwin->w_topline > curbuf->b_ml.ml_line_count)
                    curwin->w_topline = curbuf->b_ml.ml_line_count;
                curwin->w_cursor.lnum = curwin->w_topline;
            }
            else if (curwin->w_botline > curbuf->b_ml.ml_line_count) {
                curwin->w_topline = curbuf->b_ml.ml_line_count;
                curwin->w_topfill = 0;
                curwin->w_valid &= ~(VALID_WROW | VALID_CROW);
            }
            else {
                loff.lnum = curwin->w_botline;
                loff.fill = diff_check_fill (curwin, loff.lnum) - curwin->w_filler_rows;
                get_scroll_overlap (& loff, - 1);
                curwin->w_topline = loff.lnum;
                curwin->w_topfill = loff.fill;
                check_topfill (curwin, FALSE);
                curwin->w_cursor.lnum = curwin->w_topline;
                curwin->w_valid &= ~(VALID_WCOL | VALID_CHEIGHT | VALID_WROW | VALID_CROW | VALID_BOTLINE | VALID_BOTLINE_AP);
            }
        }
        else {
            if (curwin->w_topline == 1) {
                max_topfill ();
                continue;
            }
            if (ONE_WINDOW && p_window > 0 && p_window < Rows - 1) {
                if (p_window <= 2)
                    --curwin->w_topline;
                else
                    curwin->w_topline -= p_window - 2;
                if (curwin->w_topline < 1)
                    curwin->w_topline = 1;
                curwin->w_cursor.lnum = curwin->w_topline + p_window - 1;
                if (curwin->w_cursor.lnum > curbuf->b_ml.ml_line_count)
                    curwin->w_cursor.lnum = curbuf->b_ml.ml_line_count;
                continue;
            }
            loff.lnum = curwin->w_topline - 1;
            loff.fill = diff_check_fill (curwin, loff.lnum + 1) - curwin->w_topfill;
            get_scroll_overlap (& loff, 1);
            if (loff.lnum >= curbuf->b_ml.ml_line_count) {
                loff.lnum = curbuf->b_ml.ml_line_count;
                loff.fill = 0;
            }
            else {
                botline_topline (& loff);
            }
            curwin->w_cursor.lnum = loff.lnum;
            n = 0;
            while (n <= curwin->w_height && loff.lnum >= 1) {
                topline_back (& loff);
                if (loff.height == MAXCOL)
                    n = MAXCOL;
                else
                    n += loff.height;
            }
            if (loff.lnum < 1) {
                curwin->w_topline = 1;
                max_topfill ();
                curwin->w_valid &= ~(VALID_WROW | VALID_CROW | VALID_BOTLINE);
            }
            else {
                topline_botline (& loff);
                botline_forw (& loff);
                botline_forw (& loff);
                botline_topline (& loff);
                (void) hasFolding (loff.lnum, &loff.lnum, NULL);
                if (loff.lnum >= curwin->w_topline && (loff.lnum > curwin->w_topline || loff.fill >= curwin->w_topfill)) {
                    loff.fill = curwin->w_topfill;
                    if (curwin->w_topfill < diff_check_fill (curwin, curwin->w_topline))
                        max_topfill ();
                    if (curwin->w_topfill == loff.fill) {
                        --curwin->w_topline;
                        curwin->w_topfill = 0;
                    }
                    comp_botline (curwin);
                    curwin->w_cursor.lnum = curwin->w_botline - 1;
                    curwin->w_valid &= ~(VALID_WCOL | VALID_CHEIGHT | VALID_WROW | VALID_CROW);
                }
                else {
                    curwin->w_topline = loff.lnum;
                    curwin->w_topfill = loff.fill;
                    check_topfill (curwin, FALSE);
                    curwin->w_valid &= ~(VALID_WROW | VALID_CROW | VALID_BOTLINE);
                }
            }
        }
    }
    foldAdjustCursor ();
    cursor_correct ();
    check_cursor_col ();
    if (retval == OK)
        beginline (BL_SOL | BL_FIX);
    curwin->w_valid &= ~(VALID_WCOL | VALID_WROW | VALID_VIRTCOL);
    if (retval == OK && dir == FORWARD && check_top_offset ()) {
        scroll_cursor_top (1, FALSE);
        if (curwin->w_topline <= old_topline && old_topline < curbuf->b_ml.ml_line_count) {
            curwin->w_topline = old_topline + 1;
            (void) hasFolding (curwin->w_topline, &curwin->w_topline, NULL);
        }
    }
    redraw_later (VALID);
    return retval;
}

static void get_scroll_overlap (lineoff_T *lp, int dir) {
    int h1, h2, h3, h4;
    int min_height = curwin->w_height - 2;
    lineoff_T loff0, loff1, loff2;
    if (lp->fill > 0)
        lp->height = 1;
    else
        lp->height = plines_nofill (lp->lnum);
    h1 = lp->height;
    if (h1 > min_height)
        return;
    loff0 = *lp;
    if (dir > 0)
        botline_forw (lp);
    else
        topline_back (lp);
    h2 = lp->height;
    if (h2 == MAXCOL || h2 + h1 > min_height) {
        *lp = loff0;
        return;
    }
    loff1 = *lp;
    if (dir > 0)
        botline_forw (lp);
    else
        topline_back (lp);
    h3 = lp->height;
    if (h3 == MAXCOL || h3 + h2 > min_height) {
        *lp = loff0;
        return;
    }
    loff2 = *lp;
    if (dir > 0)
        botline_forw (lp);
    else
        topline_back (lp);
    h4 = lp->height;
    if (h4 == MAXCOL || h4 + h3 + h2 > min_height || h3 + h2 + h1 > min_height)
        *lp = loff1;
    else
        *lp = loff2;
    return;
}

static void max_topfill (void) {
    int n;
    n = plines_nofill (curwin->w_topline);
    if (n >= curwin->w_height)
        curwin->w_topfill = 0;
    else {
        curwin->w_topfill = diff_check_fill (curwin, curwin->w_topline);
        if (curwin->w_topfill + n > curwin->w_height)
            curwin->w_topfill = curwin->w_height - n;
    }
}

static void botline_topline (lineoff_T *lp) {
    if (lp->fill > 0) {
        ++lp->lnum;
        lp->fill = diff_check_fill (curwin, lp->lnum) - lp->fill + 1;
    }
}

static void topline_botline (lineoff_T *lp) {
    if (lp->fill > 0) {
        lp->fill = diff_check_fill (curwin, lp->lnum) - lp->fill + 1;
        --lp->lnum;
    }
}

static int check_top_offset (void) {
    lineoff_T loff;
    int n;
    if (curwin->w_cursor.lnum < curwin->w_topline + p_so || hasAnyFolding (curwin)) {
        loff.lnum = curwin->w_cursor.lnum;
        loff.fill = 0;
        n = curwin->w_topfill;
        while (n < p_so) {
            topline_back (& loff);
            if (loff.lnum < curwin->w_topline || (loff.lnum == curwin->w_topline && loff.fill > 0))
                break;
            n += loff.height;
        }
        if (n < p_so)
            return TRUE;
    }
    return FALSE;
}

void scroll_cursor_top (int min_scroll, int always) {
    int scrolled = 0;
    int extra = 0;
    int used;
    int i;
    linenr_T top;
    linenr_T bot;
    linenr_T old_topline = curwin->w_topline;
    linenr_T old_topfill = curwin->w_topfill;
    linenr_T new_topline;
    int off = p_so;
    if (mouse_dragging > 0)
        off = mouse_dragging - 1;
    validate_cheight ();
    used = curwin->w_cline_height;
    if (curwin->w_cursor.lnum < curwin->w_topline)
        scrolled = used;
    if (hasFolding (curwin->w_cursor.lnum, &top, &bot)) {
        --top;
        ++bot;
    }
    else {
        top = curwin->w_cursor.lnum - 1;
        bot = curwin->w_cursor.lnum + 1;
    }
    new_topline = top + 1;
    extra += diff_check_fill (curwin, curwin->w_cursor.lnum);
    while (top > 0) {
        if (hasFolding (top, &top, NULL))
            i = 1;
        else
            i = PLINES_NOFILL (top);
        used += i;
        if (extra + i <= off && bot < curbuf->b_ml.ml_line_count) {
            if (hasFolding (bot, NULL, &bot))
                ++used;
            else
                used += plines (bot);
        }
        if (used > curwin->w_height)
            break;
        if (top < curwin->w_topline)
            scrolled += i;
        if ((new_topline >= curwin->w_topline || scrolled > min_scroll) && extra >= off)
            break;
        extra += i;
        new_topline = top;
        --top;
        ++bot;
    }
    if (used > curwin->w_height)
        scroll_cursor_halfway (FALSE);
    else {
        if (new_topline < curwin->w_topline || always)
            curwin->w_topline = new_topline;
        if (curwin->w_topline > curwin->w_cursor.lnum)
            curwin->w_topline = curwin->w_cursor.lnum;
        curwin->w_topfill = diff_check_fill (curwin, curwin->w_topline);
        if (curwin->w_topfill > 0 && extra > off) {
            curwin->w_topfill -= extra - off;
            if (curwin->w_topfill < 0)
                curwin->w_topfill = 0;
        }
        check_topfill (curwin, FALSE);
        if (curwin->w_topline != old_topline || curwin->w_topfill != old_topfill)
            curwin->w_valid &= ~(VALID_WROW | VALID_CROW | VALID_BOTLINE | VALID_BOTLINE_AP);
        curwin->w_valid |= VALID_TOPLINE;
    }
}

static void validate_cheight (void) {
    check_cursor_moved (curwin);
    if (!(curwin->w_valid & VALID_CHEIGHT)) {
        if (curwin->w_cursor.lnum == curwin->w_topline)
            curwin->w_cline_height = plines_nofill (curwin->w_cursor.lnum) + curwin->w_topfill;
        else
            curwin->w_cline_height = plines (curwin->w_cursor.lnum);
        curwin->w_cline_folded = hasFolding (curwin->w_cursor.lnum, NULL, NULL);
        curwin->w_valid |= VALID_CHEIGHT;
    }
}

void changed_cline_bef_curs_win (win_T *wp) {
    wp->w_valid &= ~(VALID_WROW | VALID_WCOL | VALID_VIRTCOL | VALID_CHEIGHT | VALID_TOPLINE);
}

void approximate_botline_win (win_T *wp) {
    wp->w_valid &= ~VALID_BOTLINE;
}

void update_topline_redraw (void) {
    update_topline ();
    if (must_redraw)
        update_screen (0);
}

static int scrolljump_value (void) {
    if (p_sj >= 0)
        return (int) p_sj;
    return (curwin->w_height * -p_sj) / 100;
}

void scroll_cursor_bot (int min_scroll, int set_topbot) {
    int used;
    int scrolled = 0;
    int extra = 0;
    int i;
    linenr_T line_count;
    linenr_T old_topline = curwin->w_topline;
    lineoff_T loff;
    lineoff_T boff;
    int old_topfill = curwin->w_topfill;
    int fill_below_window;
    linenr_T old_botline = curwin->w_botline;
    linenr_T old_valid = curwin->w_valid;
    int old_empty_rows = curwin->w_empty_rows;
    linenr_T cln;
    cln = curwin->w_cursor.lnum;
    if (set_topbot) {
        used = 0;
        curwin->w_botline = cln + 1;
        loff.fill = 0;
        for (curwin->w_topline = curwin->w_botline; curwin->w_topline > 1; curwin->w_topline = loff.lnum) {
            loff.lnum = curwin->w_topline;
            topline_back (& loff);
            if (loff.height == MAXCOL || used + loff.height > curwin->w_height)
                break;
            used += loff.height;
            curwin->w_topfill = loff.fill;
        }
        set_empty_rows (curwin, used);
        curwin->w_valid |= VALID_BOTLINE | VALID_BOTLINE_AP;
        if (curwin->w_topline != old_topline || curwin->w_topfill != old_topfill)
            curwin->w_valid &= ~(VALID_WROW | VALID_CROW);
    }
    else
        validate_botline ();
    used = plines_nofill (cln);
    if (cln >= curwin->w_botline) {
        scrolled = used;
        if (cln == curwin->w_botline)
            scrolled -= curwin->w_empty_rows;
    }
    if (!hasFolding (curwin->w_cursor.lnum, &loff.lnum, &boff.lnum)) {
        loff.lnum = cln;
        boff.lnum = cln;
    }
    loff.fill = 0;
    boff.fill = 0;
    fill_below_window = diff_check_fill (curwin, curwin->w_botline) - curwin->w_filler_rows;
    while (loff.lnum > 1) {
        if ((((scrolled <= 0 || scrolled >= min_scroll) && extra >= (mouse_dragging > 0 ? mouse_dragging - 1 : p_so)) || boff.lnum + 1 > curbuf->b_ml.ml_line_count) && loff.lnum <= curwin->w_botline && (loff.lnum < curwin->w_botline || loff.fill >= fill_below_window))
            break;
        topline_back (& loff);
        if (loff.height == MAXCOL)
            used = MAXCOL;
        else
            used += loff.height;
        if (used > curwin->w_height)
            break;
        if (loff.lnum >= curwin->w_botline && (loff.lnum > curwin->w_botline || loff.fill <= fill_below_window)) {
            scrolled += loff.height;
            if (loff.lnum == curwin->w_botline && boff.fill == 0)
                scrolled -= curwin->w_empty_rows;
        }
        if (boff.lnum < curbuf->b_ml.ml_line_count) {
            botline_forw (& boff);
            used += boff.height;
            if (used > curwin->w_height)
                break;
            if (extra < (mouse_dragging > 0 ? mouse_dragging - 1 : p_so) || scrolled < min_scroll) {
                extra += boff.height;
                if (boff.lnum >= curwin->w_botline || (boff.lnum + 1 == curwin->w_botline && boff.fill > curwin->w_filler_rows)) {
                    scrolled += boff.height;
                    if (boff.lnum == curwin->w_botline && boff.fill == 0)
                        scrolled -= curwin->w_empty_rows;
                }
            }
        }
    }
    if (scrolled <= 0)
        line_count = 0;
    else if (used > curwin->w_height)
        line_count = used;
    else {
        line_count = 0;
        boff.fill = curwin->w_topfill;
        boff.lnum = curwin->w_topline - 1;
        for (i = 0; i < scrolled && boff.lnum < curwin->w_botline;) {
            botline_forw (& boff);
            i += boff.height;
            ++line_count;
        }
        if (i < scrolled)
            line_count = 9999;
    }
    if (line_count >= curwin->w_height && line_count > min_scroll)
        scroll_cursor_halfway (FALSE);
    else
        scrollup (line_count, TRUE);
    if (curwin->w_topline == old_topline && set_topbot) {
        curwin->w_botline = old_botline;
        curwin->w_empty_rows = old_empty_rows;
        curwin->w_valid = old_valid;
    }
    curwin->w_valid |= VALID_TOPLINE;
}

