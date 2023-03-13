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
EXTERN int p_title;
EXTERN int p_ri;
EXTERN int p_paste;
EXTERN char_u farsi_text_5 [];
EXTERN int p_fkmap;
EXTERN int p_hkmap;
EXTERN char_u *edit_submode_pre INIT (= NULL);
EXTERN char_u *edit_submode_extra INIT (= NULL);
EXTERN int p_smd;
EXTERN char_u *edit_submode INIT (= NULL);
EXTERN int p_ru;
EXTERN char_u *p_sbr;
EXTERN char_u *p_sel;
EXTERN int p_tf;
foldinfo_T win_foldinfo;
EXTERN long  p_rdt;
EXTERN char_u *p_stl;
EXTERN char_u *p_ruf;
EXTERN char_u *NameBuff;
EXTERN char_u *p_tal;
EXTERN win_T *firstwin;
EXTERN int KeyTyped;
EXTERN int p_lz;
EXTERN long  p_wmh;
EXTERN long  p_ls;
EXTERN win_T *lastwin;
EXTERN short  *TabPageIdxs INIT (= NULL);
EXTERN char_u *LineWraps INIT (= NULL);
EXTERN unsigned  *LineOffset INIT (= NULL);
EXTERN long  Rows;
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
int redrawing_for_callback = 0;
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
match_T search_hl;
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
schar_T *current_ScreenLine;
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
int screen_char_attr = 0;
int screen_attr = 0;
EXTERN typebuf_T typebuf;
EXTERN long_u scrollbar_value;
EXTERN except_T *caught_stack INIT (= NULL);
EXTERN int did_uncaught_emsg;
EXTERN int arrow_used;
EXTERN int mouse_row;
EXTERN int msg_row;
EXTERN int cmdline_row;
int screen_cur_row;
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
int screen_cur_col;
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

int screen_valid (int doclear) {
    screenalloc (doclear);
    return (ScreenLines != NULL);
}

void screenalloc (int doclear) {
    int new_row, old_row;
    int old_Rows;
    win_T *wp;
    int outofmem = FALSE;
    int len;
    schar_T *new_ScreenLines;
    sattr_T *new_ScreenAttrs;
    unsigned  *new_LineOffset;
    char_u *new_LineWraps;
    short  *new_TabPageIdxs;
    tabpage_T *tp;
    static int entered = FALSE;
    static int done_outofmem_msg = FALSE;
    int retry_count = 0;
retry :
    if ((ScreenLines != NULL && Rows == screen_Rows && Columns == screen_Columns) || Rows == 0 || Columns == 0 || (!full_screen && ScreenLines == NULL))
        return;
    if (entered)
        return;
    entered = TRUE;
    ++RedrawingDisabled;
    win_new_shellsize ();
    comp_col ();
    FOR_ALL_TAB_WINDOWS (tp, wp)
        win_free_lsize (wp);
    if (aucmd_win != NULL)
        win_free_lsize (aucmd_win);
    new_ScreenLines = (schar_T *) lalloc ((long_u) ((Rows + 1) * Columns * sizeof (schar_T)), FALSE);
    new_ScreenAttrs = (sattr_T *) lalloc ((long_u) ((Rows + 1) * Columns * sizeof (sattr_T)), FALSE);
    new_LineOffset = (unsigned  *) lalloc ((long_u) (Rows * sizeof (unsigned )), FALSE);
    new_LineWraps = (char_u *) lalloc ((long_u) (Rows * sizeof (char_u)), FALSE);
    new_TabPageIdxs = (short  *) lalloc ((long_u) (Columns * sizeof (short )), FALSE);
    FOR_ALL_TAB_WINDOWS (tp, wp) {
        if (win_alloc_lines (wp) == FAIL) {
            outofmem = TRUE;
            goto give_up;
        }
    }
    if (aucmd_win != NULL && aucmd_win->w_lines == NULL && win_alloc_lines (aucmd_win) == FAIL)
        outofmem = TRUE;
give_up :
    if (new_ScreenLines == NULL || new_ScreenAttrs == NULL || new_LineOffset == NULL || new_LineWraps == NULL || new_TabPageIdxs == NULL || outofmem) {
        if (ScreenLines != NULL || !done_outofmem_msg) {
            do_outofmem_msg ((long_u) ((Rows + 1) * Columns));
            done_outofmem_msg = TRUE;
        }
        VIM_CLEAR (new_ScreenLines);
        VIM_CLEAR (new_ScreenAttrs);
        VIM_CLEAR (new_LineOffset);
        VIM_CLEAR (new_LineWraps);
        VIM_CLEAR (new_TabPageIdxs);
    }
    else {
        done_outofmem_msg = FALSE;
        for (new_row = 0; new_row < Rows; ++new_row) {
            new_LineOffset[new_row] = new_row * Columns;
            new_LineWraps[new_row] = FALSE;
            if (!doclear) {
                (void) vim_memset (new_ScreenLines +new_row * Columns, ' ', (size_t) Columns * sizeof (schar_T));
                (void) vim_memset (new_ScreenAttrs +new_row * Columns, 0, (size_t) Columns * sizeof (sattr_T));
                old_row = new_row + (screen_Rows - Rows);
                if (old_row >= 0 && ScreenLines != NULL) {
                    if (screen_Columns < Columns)
                        len = screen_Columns;
                    else
                        len = Columns;
                    mch_memmove (new_ScreenLines + new_LineOffset [new_row], ScreenLines + LineOffset [old_row], (size_t) len * sizeof (schar_T));
                    mch_memmove (new_ScreenAttrs + new_LineOffset [new_row], ScreenAttrs + LineOffset [old_row], (size_t) len * sizeof (sattr_T));
                }
            }
        }
        current_ScreenLine = new_ScreenLines + Rows * Columns;
    }
    free_screenlines ();
    ScreenLines = new_ScreenLines;
    ScreenAttrs = new_ScreenAttrs;
    LineOffset = new_LineOffset;
    LineWraps = new_LineWraps;
    TabPageIdxs = new_TabPageIdxs;
    old_Rows = screen_Rows;
    screen_Rows = Rows;
    screen_Columns = Columns;
    must_redraw = CLEAR;
    if (doclear)
        screenclear2 ();
    else if (gui.in_use && !gui.starting && ScreenLines != NULL && old_Rows != Rows) {
        (void) gui_redraw_block (0, 0, (int) Rows - 1, (int) Columns - 1, 0);
        if (msg_row >= Rows)
            msg_row = Rows - 1;
        else if (Rows > old_Rows)
            msg_row += Rows - old_Rows;
        if (msg_col >= Columns)
            msg_col = Columns - 1;
    }
    entered = FALSE;
    --RedrawingDisabled;
    if (starting == 0 && ++retry_count <= 3) {
        apply_autocmds (EVENT_VIMRESIZED, NULL, NULL, FALSE, curbuf);
        goto retry;
    }
}

void win_redr_status_matches (expand_T *xp, int num_matches, char_u **matches, int match, int showtail) {

    #define L_MATCH(m) (showtail ? sm_gettail(matches[m]) : matches[m])
    int row;
    char_u *buf;
    int len;
    int clen;
    int fillchar;
    int attr;
    int i;
    int highlight = TRUE;
    char_u *selstart = NULL;
    int selstart_col = 0;
    char_u *selend = NULL;
    static int first_match = 0;
    int add_left = FALSE;
    char_u *s;
    int emenu;
    int l;
    if (matches == NULL)
        return;
    buf = alloc ((unsigned ) Columns + 1);
    if (buf == NULL)
        return;
    if (match == -1) {
        match = 0;
        highlight = FALSE;
    }
    clen = status_match_len (xp, L_MATCH (match)) + 3;
    if (match == 0)
        first_match = 0;
    else if (match < first_match) {
        first_match = match;
        add_left = TRUE;
    }
    else {
        for (i = first_match; i < match; ++i)
            clen += status_match_len (xp, L_MATCH (i)) + 2;
        if (first_match > 0)
            clen += 2;
        if ((long ) clen > Columns) {
            first_match = match;
            clen = 2;
            for (i = match; i < num_matches; ++i) {
                clen += status_match_len (xp, L_MATCH (i)) + 2;
                if ((long ) clen >= Columns)
                    break;
            }
            if (i == num_matches)
                add_left = TRUE;
        }
    }
    if (add_left)
        while (first_match > 0) {
            clen += status_match_len (xp, L_MATCH (first_match - 1)) + 2;
            if ((long ) clen >= Columns)
                break;
            --first_match;
        }
    fillchar = fillchar_status (&attr, curwin);
    if (first_match == 0) {
        *buf = NUL;
        len = 0;
    }
    else {
        STRCPY (buf, "< ");
        len = 2;
    }
    clen = len;
    i = first_match;
    while ((long ) (clen + status_match_len (xp, L_MATCH (i)) + 2) < Columns) {
        if (i == match) {
            selstart = buf + len;
            selstart_col = clen;
        }
        s = L_MATCH (i);
        emenu = (xp->xp_context == EXPAND_MENUS || xp->xp_context == EXPAND_MENUNAMES);
        if (emenu && menu_is_separator (s)) {
            STRCPY (buf + len, transchar ('|'));
            l = (int) STRLEN (buf +len);
            len += l;
            clen += l;
        }
        else
            for (; *s != NUL; ++s) {
                s += skip_status_match_char (xp, s);
                clen += ptr2cells (s);
                {
                    STRCPY (buf + len, transchar_byte (* s));
                    len += (int) STRLEN (buf +len);
                }
            }
        if (i == match)
            selend = buf + len;
        *(buf + len++) = ' ';
        *(buf + len++) = ' ';
        clen += 2;
        if (++i == num_matches)
            break;
    }
    if (i != num_matches) {
        *(buf + len++) = '>';
        ++clen;
    }
    buf[len] = NUL;
    row = cmdline_row - 1;
    if (row >= 0) {
        if (wild_menu_showing == 0) {
            if (msg_scrolled > 0) {
                if (cmdline_row == Rows - 1) {
                    screen_del_lines (0, 0, 1, (int) Rows, TRUE, 0, NULL);
                    ++msg_scrolled;
                }
                else {
                    ++cmdline_row;
                    ++row;
                }
                wild_menu_showing = WM_SCROLLED;
            }
            else {
                if (lastwin->w_status_height == 0) {
                    save_p_ls = p_ls;
                    save_p_wmh = p_wmh;
                    p_ls = 2;
                    p_wmh = 0;
                    last_status (FALSE);
                }
                wild_menu_showing = WM_SHOWN;
            }
        }
        screen_puts (buf, row, 0, attr);
        if (selstart != NULL && highlight) {
            *selend = NUL;
            screen_puts (selstart, row, selstart_col, HL_ATTR (HLF_WM));
        }
        screen_fill (row, row + 1, clen, (int) Columns, fillchar, fillchar, attr);
    }
    win_redraw_last_status (topframe);
    vim_free (buf);
}

static int status_match_len (expand_T *xp, char_u *s) {
    int len = 0;
    int emenu = (xp->xp_context == EXPAND_MENUS || xp->xp_context == EXPAND_MENUNAMES);
    if (emenu && menu_is_separator (s))
        return 1;
    while (*s != NUL) {
        s += skip_status_match_char (xp, s);
        len += ptr2cells (s);
        MB_PTR_ADV (s);
    }
    return len;
}

static int skip_status_match_char (expand_T *xp, char_u *s) {
    if ((rem_backslash (s) && xp->xp_context != EXPAND_HELP) || ((xp->xp_context == EXPAND_MENUS || xp->xp_context == EXPAND_MENUNAMES) && (s[0] == '\t' || (s[0] == '\\' && s[1] != NUL)))) {
        if (xp->xp_shell && csh_like_shell () && s[1] == '\\' && s[2] == '!')
            return 2;
        return 1;
    }
    return 0;
}

static int fillchar_status (int *attr, win_T *wp) {
    int fill;
    if (bt_terminal (wp->w_buffer)) {
        if (wp == curwin) {
            *attr = HL_ATTR (HLF_ST);
            fill = fill_stl;
        }
        else {
            *attr = HL_ATTR (HLF_STNC);
            fill = fill_stlnc;
        }
    }
    else if (wp == curwin) {
        *attr = HL_ATTR (HLF_S);
        fill = fill_stl;
    }
    else {
        *attr = HL_ATTR (HLF_SNC);
        fill = fill_stlnc;
    }
    if (*attr != 0 && ((HL_ATTR (HLF_S) != HL_ATTR (HLF_SNC) || wp != curwin || ONE_WINDOW) || (fill_stl != fill_stlnc)))
        return fill;
    if (wp == curwin)
        return '^';
    return '=';
}

int screen_del_lines (int off, int row, int line_count, int end, int force, int clear_attr, win_T *wp) {
    int j;
    int i;
    unsigned  temp;
    int cursor_row;
    int cursor_end;
    int result_empty;
    int can_delete;
    int type;
    if (!screen_valid (TRUE) || line_count <= 0 || (!force && line_count > p_ttyscroll))
        return FAIL;
    result_empty = row + line_count >= end;
    can_delete = (*T_DB == NUL || can_clear (T_CE));
    if (wp != NULL && wp->w_width != Columns && *T_CSV == NUL)
        type = USE_REDRAW;
    else if (can_clear (T_CD) && result_empty)
        type = USE_T_CD;
    else if (row == 0 && (line_count == 1 || *T_CDL == NUL))
        type = USE_NL;
    else if (*T_CDL != NUL && line_count > 1 && can_delete)
        type = USE_T_CDL;
    else if (can_clear (T_CE) && result_empty && (wp == NULL || wp->w_width == Columns))
        type = USE_T_CE;
    else if (*T_DL != NUL && can_delete)
        type = USE_T_DL;
    else if (*T_CDL != NUL && can_delete)
        type = USE_T_CDL;
    else
        return FAIL;
    gui_dont_update_cursor (gui.cursor_row >= row + off && gui.cursor_row < end + off);
    if (*T_CCS != NUL) {
        cursor_row = row;
        cursor_end = end;
    }
    else {
        cursor_row = row + off;
        cursor_end = end + off;
    }
    row += off;
    end += off;
    for (i = 0; i < line_count; ++i) {
        if (wp != NULL && wp->w_width != Columns) {
            j = row + i;
            while ((j += line_count) <= end - 1)
                linecopy (j -line_count, j, wp);
            j -= line_count;
            if (can_clear ((char_u *) " "))
                lineclear (LineOffset[j] + wp->w_wincol, wp->w_width, clear_attr);
            else
                lineinvalid (LineOffset[j] + wp->w_wincol, wp->w_width);
            LineWraps[j] = FALSE;
        }
        else {
            j = row + i;
            temp = LineOffset[j];
            while ((j += line_count) <= end - 1) {
                LineOffset[j - line_count] = LineOffset[j];
                LineWraps[j - line_count] = LineWraps[j];
            }
            LineOffset[j - line_count] = temp;
            LineWraps[j - line_count] = FALSE;
            if (can_clear ((char_u *) " "))
                lineclear (temp, (int) Columns, clear_attr);
            else
                lineinvalid (temp, (int) Columns);
        }
    }
    if (screen_attr != clear_attr)
        screen_stop_highlight ();
    if (clear_attr != 0)
        screen_start_highlight (clear_attr);
    if (type == USE_REDRAW)
        redraw_block (row, end, wp);
    else if (type == USE_T_CD) {
        windgoto (cursor_row, 0);
        out_str (T_CD);
        screen_start ();
    }
    else if (type == USE_T_CDL) {
        windgoto (cursor_row, 0);
        term_delete_lines (line_count);
        screen_start ();
    }
    else if (type == USE_NL) {
        windgoto (cursor_end - 1, 0);
        for (i = line_count; --i >= 0;)
            out_char ('\n');
    }
    else {
        for (i = line_count; --i >= 0;) {
            if (type == USE_T_DL) {
                windgoto (cursor_row, 0);
                out_str (T_DL);
            }
            else {
                windgoto (cursor_row + i, 0);
                out_str (T_CE);
            }
            screen_start ();
        }
    }
    if (*T_DB && (type == USE_T_DL || type == USE_T_CDL)) {
        for (i = line_count; i > 0; --i) {
            windgoto (cursor_end - i, 0);
            out_str (T_CE);
            screen_start ();
        }
    }
    gui_can_update_cursor ();
    if (gui.in_use)
        out_flush ();
    return OK;
}

int can_clear (char_u *p) {
    return (*p != NUL && (t_colors <= 1 || gui.in_use || (p_tgc && cterm_normal_bg_gui_color == INVALCOLOR) || (!p_tgc && cterm_normal_bg_color == 0) || *T_UT != NUL));
}

void screen_draw_rectangle (int row, int col, int height, int width, int invert) {
    int r, c;
    int off;
    if (ScreenLines == NULL)
        return;
    if (invert)
        screen_char_attr = HL_INVERSE;
    for (r = row; r < row + height; ++r) {
        off = LineOffset[r];
        for (c = col; c < col + width; ++c) {
            {
                screen_char (off + c, r, c);
            }
        }
    }
    screen_char_attr = 0;
}

static void screen_char (unsigned  off, int row, int col) {
    int attr;
    if (row >= screen_Rows || col >= screen_Columns)
        return;
    if (*T_XN == NUL && row == screen_Rows - 1 && col == screen_Columns - 1 && !cmdmsg_rl) {
        ScreenAttrs[off] = (sattr_T) -1;
        return;
    }
    if (screen_char_attr != 0)
        attr = screen_char_attr;
    else
        attr = ScreenAttrs[off];
    if (screen_attr != attr)
        screen_stop_highlight ();
    windgoto (row, col);
    if (screen_attr != attr)
        screen_start_highlight (attr);
    {
        out_char (ScreenLines [off]);
    }
    screen_cur_col++;
}

void screen_stop_highlight (void) {
    int do_ME = FALSE;
    if (screen_attr != 0) {
        if (gui.in_use) {
            char buf [20];
            sprintf (buf, IF_EB ("\033|%dH", ESC_STR "|%dH"), screen_attr);
            OUT_STR (buf);
        }
        else {
            if (screen_attr > HL_ALL) {
                attrentry_T *aep;
                if (IS_CTERM) {
                    aep = syn_cterm_attr2entry (screen_attr);
                    if (aep != NULL && (p_tgc ? (aep->ae_u.cterm.fg_rgb != INVALCOLOR || aep->ae_u.cterm.bg_rgb != INVALCOLOR) : (aep->ae_u.cterm.fg_color || aep->ae_u.cterm.bg_color)))
                        do_ME = TRUE;
                }
                else {
                    aep = syn_term_attr2entry (screen_attr);
                    if (aep != NULL && aep->ae_u.term.stop != NULL) {
                        if (STRCMP (aep->ae_u.term.stop, T_ME) == 0)
                            do_ME = TRUE;
                        else
                            out_str (aep->ae_u.term.stop);
                    }
                }
                if (aep == NULL)
                    screen_attr = 0;
                else
                    screen_attr = aep->ae_attr;
            }
            if (screen_attr & HL_STANDOUT) {
                if (STRCMP (T_SE, T_ME) == 0)
                    do_ME = TRUE;
                else
                    out_str (T_SE);
            }
            if ((screen_attr & HL_UNDERCURL) && *T_UCE != NUL) {
                if (STRCMP (T_UCE, T_ME) == 0)
                    do_ME = TRUE;
                else
                    out_str (T_UCE);
            }
            if ((screen_attr & HL_UNDERLINE) || ((screen_attr & HL_UNDERCURL) && *T_UCE == NUL)) {
                if (STRCMP (T_UE, T_ME) == 0)
                    do_ME = TRUE;
                else
                    out_str (T_UE);
            }
            if (screen_attr & HL_ITALIC) {
                if (STRCMP (T_CZR, T_ME) == 0)
                    do_ME = TRUE;
                else
                    out_str (T_CZR);
            }
            if (screen_attr & HL_STRIKETHROUGH) {
                if (STRCMP (T_STE, T_ME) == 0)
                    do_ME = TRUE;
                else
                    out_str (T_STE);
            }
            if (do_ME || (screen_attr & (HL_BOLD | HL_INVERSE)))
                out_str (T_ME);
            if (p_tgc) {
                if (cterm_normal_fg_gui_color != INVALCOLOR)
                    term_fg_rgb_color (cterm_normal_fg_gui_color);
                if (cterm_normal_bg_gui_color != INVALCOLOR)
                    term_bg_rgb_color (cterm_normal_bg_gui_color);
            }
            else {
                if (t_colors > 1) {
                    if (cterm_normal_fg_color != 0)
                        term_fg_color (cterm_normal_fg_color -1);
                    if (cterm_normal_bg_color != 0)
                        term_bg_color (cterm_normal_bg_color -1);
                    if (cterm_normal_fg_bold)
                        out_str (T_MD);
                }
            }
        }
    }
    screen_attr = 0;
}

void screen_fill (int start_row, int end_row, int start_col, int end_col, int c1, int c2, int attr) {
    int row;
    int col;
    int off;
    int end_off;
    int did_delete;
    int c;
    int norm_term;
    int force_next = FALSE;
    if (end_row > screen_Rows)
        end_row = screen_Rows;
    if (end_col > screen_Columns)
        end_col = screen_Columns;
    if (ScreenLines == NULL || start_row >= end_row || start_col >= end_col)
        return;
    norm_term = (!gui.in_use && !IS_CTERM);
    for (row = start_row; row < end_row; ++row) {
        did_delete = FALSE;
        if (c2 == ' ' && end_col == Columns && can_clear (T_CE) && (attr == 0 || (norm_term && attr <= HL_ALL && ((attr & ~(HL_BOLD | HL_ITALIC)) == 0)))) {
            col = start_col;
            if (c1 != ' ')
                ++col;
            off = LineOffset[row] + col;
            end_off = LineOffset[row] + end_col;
            while (off < end_off && ScreenLines[off] == ' ' && ScreenAttrs[off] == 0)
                ++off;
            if (off < end_off) {
                col = off - LineOffset[row];
                screen_stop_highlight ();
                term_windgoto (row, col);
                out_str (T_CE);
                screen_start ();
                col = end_col - col;
                while (col--) {
                    space_to_screenline (off, 0);
                    ++off;
                }
            }
            did_delete = TRUE;
        }
        off = LineOffset[row] + start_col;
        c = c1;
        for (col = start_col; col < end_col; ++col) {
            if (ScreenLines[off] != c || ScreenAttrs[off] != attr || force_next || (gui.in_use && col + 1 < end_col && ScreenLines[off + 1] != c)) {
                if (gui.in_use || term_is_xterm) {
                    force_next = (ScreenLines[off] != ' ');
                }
                ScreenLines[off] = c;
                ScreenAttrs[off] = attr;
                if (!did_delete || c != ' ')
                    screen_char (off, row, col);
            }
            ++off;
            if (col == start_col) {
                if (did_delete)
                    break;
                c = c2;
            }
        }
        if (end_col == Columns)
            LineWraps[row] = FALSE;
        if (row == Rows - 1) {
            redraw_cmdline = TRUE;
            if (c1 == ' ' && c2 == ' ')
                clear_cmdline = FALSE;
            if (start_col == 0)
                mode_displayed = FALSE;
        }
    }
}

void screen_start (void) {
    screen_cur_row = screen_cur_col = 9999;
}

void redraw_all_later (int type) {
    win_T *wp;
    FOR_ALL_WINDOWS (wp) {
        redraw_win_later (wp, type);
    }
}

void redraw_win_later (win_T *wp, int type) {
    if (!exiting && wp->w_redr_type < type) {
        wp->w_redr_type = type;
        if (type >= NOT_VALID)
            wp->w_lines_valid = 0;
        if (must_redraw < type)
            must_redraw = type;
    }
}

int number_width (win_T *wp) {
    int n;
    linenr_T lnum;
    if (wp->w_p_rnu && !wp->w_p_nu)
        lnum = wp->w_height;
    else
        lnum = wp->w_buffer->b_ml.ml_line_count;
    if (lnum == wp->w_nrwidth_line_count && wp->w_nuw_cached == wp->w_p_nuw)
        return wp->w_nrwidth_width;
    wp->w_nrwidth_line_count = lnum;
    n = 0;
    do {
        lnum /= 10;
        ++n;
    }
    while (lnum > 0);
    if (n < wp->w_p_nuw - 1)
        n = wp->w_p_nuw - 1;
    wp->w_nrwidth_width = n;
    wp->w_nuw_cached = wp->w_p_nuw;
    return n;
}

void setcursor (void) {
    if (redrawing ()) {
        validate_cursor ();
        windgoto (W_WINROW (curwin) + curwin -> w_wrow, curwin -> w_wincol + (curwin -> w_p_rl ? ((int) curwin -> w_width - curwin -> w_wcol - (1)) : curwin -> w_wcol));
    }
}

int redrawing (void) {
    if (disable_redraw_for_testing)
        return 0;
    else
        return (!RedrawingDisabled && !(p_lz && char_avail () && !KeyTyped && !do_redraw));
}

void windgoto (int row, int col) {
    sattr_T *p;
    int i;
    int plan;
    int cost;
    int wouldbe_col;
    int noinvcurs;
    char_u *bs;
    int goto_cost;
    int attr;

    #define GOTO_COST   7	/* assume a term_windgoto() takes about 7 chars */

    #define HIGHL_COST  5	/* assume unhighlight takes 5 chars */

    #define PLAN_LE	    1

    #define PLAN_CR	    2

    #define PLAN_NL	    3

    #define PLAN_WRITE  4
    if (ScreenLines == NULL)
        return;
    if (col != screen_cur_col || row != screen_cur_row) {
        if (row < 0)
            row = 0;
        if (row >= screen_Rows)
            row = screen_Rows - 1;
        if (col >= screen_Columns)
            col = screen_Columns - 1;
        if (screen_attr && *T_MS == NUL)
            noinvcurs = HIGHL_COST;
        else
            noinvcurs = 0;
        goto_cost = GOTO_COST + noinvcurs;
        if (row >= screen_cur_row && screen_cur_col < Columns) {
            bs = NULL;
            attr = screen_attr;
            if (row == screen_cur_row && col < screen_cur_col) {
                if (*T_LE)
                    bs = T_LE;
                else
                    bs = T_BC;
                if (*bs)
                    cost = (screen_cur_col - col) * (int) STRLEN (bs);
                else
                    cost = 999;
                if (col + 1 < cost) {
                    plan = PLAN_CR;
                    wouldbe_col = 0;
                    cost = 1;
                }
                else {
                    plan = PLAN_LE;
                    wouldbe_col = col;
                }
                if (noinvcurs) {
                    cost += noinvcurs;
                    attr = 0;
                }
            }
            else if (row > screen_cur_row) {
                plan = PLAN_NL;
                wouldbe_col = 0;
                cost = (row - screen_cur_row) * 2;
                if (noinvcurs) {
                    cost += noinvcurs;
                    attr = 0;
                }
            }
            else {
                plan = PLAN_WRITE;
                wouldbe_col = screen_cur_col;
                cost = 0;
            }
            i = col - wouldbe_col;
            if (i > 0)
                cost += i;
            if (cost < goto_cost && i > 0) {
                p = ScreenAttrs + LineOffset[row] + wouldbe_col;
                while (i && *p++ == attr)
                    --i;
                if (i != 0) {
                    if (*--p == 0) {
                        cost += noinvcurs;
                        while (i && *p++ == 0)
                            --i;
                    }
                    if (i != 0)
                        cost = 999;
                }
            }
            if (cost < goto_cost) {
                if (plan == PLAN_LE) {
                    if (noinvcurs)
                        screen_stop_highlight ();
                    while (screen_cur_col > col) {
                        out_str (bs);
                        --screen_cur_col;
                    }
                }
                else if (plan == PLAN_CR) {
                    if (noinvcurs)
                        screen_stop_highlight ();
                    out_char ('\r');
                    screen_cur_col = 0;
                }
                else if (plan == PLAN_NL) {
                    if (noinvcurs)
                        screen_stop_highlight ();
                    while (screen_cur_row < row) {
                        out_char ('\n');
                        ++screen_cur_row;
                    }
                    screen_cur_col = 0;
                }
                i = col - screen_cur_col;
                if (i > 0) {
                    if (T_ND[0] != NUL && T_ND[1] == NUL) {
                        while (i-- > 0)
                            out_char (*T_ND);
                    }
                    else {
                        int off;
                        off = LineOffset[row] + screen_cur_col;
                        while (i-- > 0) {
                            if (ScreenAttrs[off] != screen_attr)
                                screen_stop_highlight ();
                            out_char (ScreenLines [off]);
                            ++off;
                        }
                    }
                }
            }
        }
        else
            cost = 999;
        if (cost >= goto_cost) {
            if (noinvcurs)
                screen_stop_highlight ();
            if (row == screen_cur_row && (col > screen_cur_col) && *T_CRI != NUL)
                term_cursor_right (col -screen_cur_col);
            else
                term_windgoto (row, col);
        }
        screen_cur_row = row;
        screen_cur_col = col;
    }
}

int update_screen (int type_arg) {
    int type = type_arg;
    win_T *wp;
    static int did_intro = FALSE;
    int did_one;
    int did_undraw = FALSE;
    int gui_cursor_col;
    int gui_cursor_row;
    int no_update = FALSE;
    if (!screen_valid (TRUE))
        return FAIL;
    if (type == VALID_NO_UPDATE) {
        no_update = TRUE;
        type = 0;
    }
    if (must_redraw) {
        if (type < must_redraw)
            type = must_redraw;
        must_redraw = 0;
    }
    if (curwin->w_lines_valid == 0 && type < NOT_VALID)
        type = NOT_VALID;
    if (!redrawing () || updating_screen) {
        redraw_later (type);
        must_redraw = type;
        if (type > INVERTED_ALL)
            curwin->w_lines_valid = 0;
        return FAIL;
    }
    updating_screen = TRUE;
    ++display_tick;
    if (no_update)
        ++no_win_do_lines_ins;
    if (msg_scrolled) {
        clear_cmdline = TRUE;
        if (msg_scrolled > Rows - 5)
            type = CLEAR;
        else if (type != CLEAR) {
            check_for_delay (FALSE);
            if (screen_ins_lines (0, 0, msg_scrolled, (int) Rows, 0, NULL) == FAIL)
                type = CLEAR;
            FOR_ALL_WINDOWS (wp) {
                if (W_WINROW (wp) < msg_scrolled) {
                    if (W_WINROW (wp) + wp->w_height > msg_scrolled && wp->w_redr_type < REDRAW_TOP && wp->w_lines_valid > 0 && wp->w_topline == wp->w_lines[0].wl_lnum) {
                        wp->w_upd_rows = msg_scrolled - W_WINROW (wp);
                        wp->w_redr_type = REDRAW_TOP;
                    }
                    else {
                        wp->w_redr_type = NOT_VALID;
                        if (W_WINROW (wp) + wp->w_height + wp->w_status_height <= msg_scrolled)
                            wp->w_redr_status = TRUE;
                    }
                }
            }
            if (!no_update)
                redraw_cmdline = TRUE;
            redraw_tabline = TRUE;
        }
        msg_scrolled = 0;
        need_wait_return = FALSE;
    }
    compute_cmdrow ();
    if (need_highlight_changed)
        highlight_changed ();
    if (type == CLEAR) {
        screenclear ();
        type = NOT_VALID;
        must_redraw = 0;
    }
    if (clear_cmdline)
        check_for_delay (FALSE);
    if (curwin->w_redr_type < NOT_VALID && curwin->w_nrwidth != ((curwin->w_p_nu || curwin->w_p_rnu) ? number_width (curwin) : 0))
        curwin->w_redr_type = NOT_VALID;
    if (type == INVERTED)
        update_curswant ();
    if (curwin->w_redr_type < type && !((type == VALID && curwin->w_lines[0].wl_valid && curwin->w_topfill == curwin->w_old_topfill && curwin->w_botfill == curwin->w_old_botfill && curwin->w_topline == curwin->w_lines[0].wl_lnum) || (type == INVERTED && VIsual_active && curwin->w_old_cursor_lnum == curwin->w_cursor.lnum && curwin->w_old_visual_mode == VIsual_mode && (curwin->w_valid & VALID_VIRTCOL) && curwin->w_old_curswant == curwin->w_curswant)))
        curwin->w_redr_type = type;
    if (redraw_tabline || type >= NOT_VALID)
        draw_tabline ();
    FOR_ALL_WINDOWS (wp) {
        if (wp->w_buffer->b_mod_set) {
            win_T *wwp;
            for (wwp = firstwin; wwp != wp; wwp = wwp->w_next)
                if (wwp->w_buffer == wp->w_buffer)
                    break;
            if (wwp == wp && syntax_present (wp))
                syn_stack_apply_changes (wp->w_buffer);
        }
    }
    did_one = FALSE;
    search_hl.rm.regprog = NULL;
    FOR_ALL_WINDOWS (wp) {
        if (wp->w_redr_type != 0) {
            cursor_off ();
            if (!did_one) {
                did_one = TRUE;
                start_search_hl ();
                if (gui.in_use && wp == curwin) {
                    gui_cursor_col = gui.cursor_col;
                    gui_cursor_row = gui.cursor_row;
                    gui_undraw_cursor ();
                    did_undraw = TRUE;
                }
            }
            win_update (wp);
        }
        if (wp->w_redr_status) {
            cursor_off ();
            win_redr_status (wp);
        }
    }
    end_search_hl ();
    if (pum_visible ())
        pum_redraw ();
    FOR_ALL_WINDOWS (wp)
        wp->w_buffer->b_mod_set = FALSE;
    updating_screen = FALSE;
    gui_may_resize_shell ();
    if (clear_cmdline || redraw_cmdline)
        showmode ();
    if (no_update)
        --no_win_do_lines_ins;
    if (!did_intro)
        maybe_intro_message ();
    did_intro = TRUE;
    if (gui.in_use) {
        if (did_undraw && !gui_mch_is_blink_off ()) {
            mch_disable_flush ();
            out_flush ();
            mch_enable_flush ();
            gui.col = gui_cursor_col;
            gui.row = gui_cursor_row;
            gui_update_cursor (FALSE, FALSE);
            gui_may_flush ();
            screen_cur_col = gui.col;
            screen_cur_row = gui.row;
        }
        else
            out_flush ();
        gui_update_scrollbars (FALSE);
    }
    return OK;
}

void redraw_later (int type) {
    redraw_win_later (curwin, type);
}

void check_for_delay (int check_msg_scroll) {
    if ((emsg_on_display || (check_msg_scroll && msg_scroll)) && !did_wait_return && emsg_silent == 0) {
        out_flush ();
        ui_delay (1000L, TRUE);
        emsg_on_display = FALSE;
        if (check_msg_scroll)
            msg_scroll = FALSE;
    }
}

int screen_ins_lines (int off, int row, int line_count, int end, int clear_attr, win_T *wp) {
    int i;
    int j;
    unsigned  temp;
    int cursor_row;
    int type;
    int result_empty;
    int can_ce = can_clear (T_CE);
    if (!screen_valid (TRUE) || line_count <= 0 || line_count > p_ttyscroll)
        return FAIL;
    result_empty = (row + line_count >= end);
    if (wp != NULL && wp->w_width != Columns && *T_CSV == NUL)
        type = USE_REDRAW;
    else if (can_clear (T_CD) && result_empty)
        type = USE_T_CD;
    else if (*T_CAL != NUL && (line_count > 1 || *T_AL == NUL))
        type = USE_T_CAL;
    else if (*T_CDL != NUL && result_empty && (line_count > 1 || !can_ce))
        type = USE_T_CDL;
    else if (*T_AL != NUL)
        type = USE_T_AL;
    else if (can_ce && result_empty)
        type = USE_T_CE;
    else if (*T_DL != NUL && result_empty)
        type = USE_T_DL;
    else if (*T_SR != NUL && row == 0 && (*T_DA == NUL || can_ce))
        type = USE_T_SR;
    else
        return FAIL;
    if (type == USE_T_CD || type == USE_T_CDL || type == USE_T_CE || type == USE_T_DL)
        return screen_del_lines (off, row, line_count, end, FALSE, 0, wp);
    if (*T_DB)
        screen_del_lines (off, end -line_count, line_count, end, FALSE, 0, wp);
    gui_dont_update_cursor (row + off <= gui.cursor_row);
    if (*T_CCS != NUL)
        cursor_row = row;
    else
        cursor_row = row + off;
    row += off;
    end += off;
    for (i = 0; i < line_count; ++i) {
        if (wp != NULL && wp->w_width != Columns) {
            j = end - 1 - i;
            while ((j -= line_count) >= row)
                linecopy (j +line_count, j, wp);
            j += line_count;
            if (can_clear ((char_u *) " "))
                lineclear (LineOffset[j] + wp->w_wincol, wp->w_width, clear_attr);
            else
                lineinvalid (LineOffset[j] + wp->w_wincol, wp->w_width);
            LineWraps[j] = FALSE;
        }
        else {
            j = end - 1 - i;
            temp = LineOffset[j];
            while ((j -= line_count) >= row) {
                LineOffset[j + line_count] = LineOffset[j];
                LineWraps[j + line_count] = LineWraps[j];
            }
            LineOffset[j + line_count] = temp;
            LineWraps[j + line_count] = FALSE;
            if (can_clear ((char_u *) " "))
                lineclear (temp, (int) Columns, clear_attr);
            else
                lineinvalid (temp, (int) Columns);
        }
    }
    screen_stop_highlight ();
    windgoto (cursor_row, 0);
    if (clear_attr != 0)
        screen_start_highlight (clear_attr);
    if (type == USE_REDRAW)
        redraw_block (row, end, wp);
    else if (type == USE_T_CAL) {
        term_append_lines (line_count);
        screen_start ();
    }
    else {
        for (i = 0; i < line_count; i++) {
            if (type == USE_T_AL) {
                if (i && cursor_row != 0)
                    windgoto (cursor_row, 0);
                out_str (T_AL);
            }
            else
                out_str (T_SR);
            screen_start ();
        }
    }
    if (type == USE_T_SR && *T_DA) {
        for (i = 0; i < line_count; ++i) {
            windgoto (off + i, 0);
            out_str (T_CE);
            screen_start ();
        }
    }
    gui_can_update_cursor ();
    if (gui.in_use)
        out_flush ();
    return OK;
}

static void linecopy (int to, int from, win_T *wp) {
    unsigned  off_to = LineOffset[to] + wp->w_wincol;
    unsigned  off_from = LineOffset[from] + wp->w_wincol;
    mch_memmove (ScreenLines + off_to, ScreenLines + off_from, wp -> w_width * sizeof (schar_T));
    mch_memmove (ScreenAttrs + off_to, ScreenAttrs + off_from, wp -> w_width * sizeof (sattr_T));
}

static void lineclear (unsigned  off, int width, int attr) {
    (void) vim_memset (ScreenLines +off, ' ', (size_t) width * sizeof (schar_T));
    (void) vim_memset (ScreenAttrs +off, attr, (size_t) width * sizeof (sattr_T));
}

static void lineinvalid (unsigned  off, int width) {
    (void) vim_memset (ScreenAttrs +off, -1, (size_t) width * sizeof (sattr_T));
}

static void redraw_block (int row, int end, win_T *wp) {
    int col;
    int width;
    if (wp == NULL) {
        col = 0;
        width = Columns;
    }
    else {
        col = wp->w_wincol;
        width = wp->w_width;
    }
    screen_draw_rectangle (row, col, end - row, width, FALSE);
}

void screenclear (void) {
    check_for_delay (FALSE);
    screenalloc (FALSE);
    screenclear2 ();
}

static void screenclear2 (void) {
    int i;
    if (starting == NO_SCREEN || ScreenLines == NULL || (gui.in_use && gui.starting))
        return;
    if (!gui.in_use)
        screen_attr = -1;
    screen_stop_highlight ();
    for (i = 0; i < Rows; ++i) {
        lineclear (LineOffset [i], (int) Columns, 0);
        LineWraps[i] = FALSE;
    }
    if (can_clear (T_CL)) {
        out_str (T_CL);
        clear_cmdline = FALSE;
        mode_displayed = FALSE;
    }
    else {
        for (i = 0; i < Rows; ++i)
            lineinvalid (LineOffset[i], (int) Columns);
        clear_cmdline = TRUE;
    }
    screen_cleared = TRUE;
    win_rest_invalid (firstwin);
    redraw_cmdline = TRUE;
    redraw_tabline = TRUE;
    if (must_redraw == CLEAR)
        must_redraw = NOT_VALID;
    compute_cmdrow ();
    msg_row = cmdline_row;
    msg_col = 0;
    screen_start ();
    msg_scrolled = 0;
    msg_didany = FALSE;
    msg_didout = FALSE;
}

static void win_rest_invalid (win_T *wp) {
    while (wp != NULL) {
        redraw_win_later (wp, NOT_VALID);
        wp->w_redr_status = TRUE;
        wp = wp->w_next;
    }
    redraw_cmdline = TRUE;
}

#define USE_T_CAL   1

#define USE_T_CDL   2

#define USE_T_AL    3

#define USE_T_CE    4

#define USE_T_DL    5

#define USE_T_SR    6

#define USE_NL	    7

#define USE_T_CD    8

#define USE_REDRAW  9

static void draw_tabline (void) {
    int tabcount = 0;
    tabpage_T *tp;
    int tabwidth;
    int col = 0;
    int scol = 0;
    int attr;
    win_T *wp;
    win_T *cwp;
    int wincount;
    int modified;
    int c;
    int len;
    int attr_sel = HL_ATTR (HLF_TPS);
    int attr_nosel = HL_ATTR (HLF_TP);
    int attr_fill = HL_ATTR (HLF_TPF);
    char_u *p;
    int room;
    int use_sep_chars = (t_colors < 8 && !gui.in_use && !p_tgc);
    if (ScreenLines == NULL)
        return;
    redraw_tabline = FALSE;
    if (tabline_height () < 1)
        return;
    for (scol = 0; scol < Columns; ++scol)
        TabPageIdxs[scol] = 0;
    if (*p_tal != NUL) {
        int saved_did_emsg = did_emsg;
        did_emsg = FALSE;
        win_redr_custom (NULL, FALSE);
        if (did_emsg)
            set_string_option_direct ((char_u *) "tabline", -1, (char_u *) "", OPT_FREE, SID_ERROR);
        did_emsg |= saved_did_emsg;
    }
    else {
        FOR_ALL_TABPAGES (tp)
            ++tabcount;
        tabwidth = (Columns - 1 + tabcount / 2) / tabcount;
        if (tabwidth < 6)
            tabwidth = 6;
        attr = attr_nosel;
        tabcount = 0;
        scol = 0;
        for (tp = first_tabpage; tp != NULL && col < Columns - 4; tp = tp->tp_next) {
            scol = col;
            if (tp->tp_topframe == topframe)
                attr = attr_sel;
            if (use_sep_chars && col > 0)
                screen_putchar ('|', 0, col++, attr);
            if (tp->tp_topframe != topframe)
                attr = attr_nosel;
            screen_putchar (' ', 0, col ++, attr);
            if (tp == curtab) {
                cwp = curwin;
                wp = firstwin;
            }
            else {
                cwp = tp->tp_curwin;
                wp = tp->tp_firstwin;
            }
            modified = FALSE;
            for (wincount = 0; wp != NULL; wp = wp->w_next, ++wincount)
                if (bufIsChanged (wp->w_buffer))
                    modified = TRUE;
            if (modified || wincount > 1) {
                if (wincount > 1) {
                    vim_snprintf ((char *) NameBuff, MAXPATHL, "%d", wincount);
                    len = (int) STRLEN (NameBuff);
                    if (col + len >= Columns - 3)
                        break;
                    screen_puts_len (NameBuff, len, 0, col, hl_combine_attr (attr, HL_ATTR (HLF_T)));
                    col += len;
                }
                if (modified)
                    screen_puts_len ((char_u *) "+", 1, 0, col++, attr);
                screen_putchar (' ', 0, col ++, attr);
            }
            room = scol - col + tabwidth - 1;
            if (room > 0) {
                get_trans_bufname (cwp -> w_buffer);
                shorten_dir (NameBuff);
                len = vim_strsize (NameBuff);
                p = NameBuff;
                if (len > room) {
                    p += len - room;
                    len = room;
                }
                if (len > Columns - col - 1)
                    len = Columns - col - 1;
                screen_puts_len (p, (int) STRLEN (p), 0, col, attr);
                col += len;
            }
            screen_putchar (' ', 0, col ++, attr);
            ++tabcount;
            while (scol < col)
                TabPageIdxs[scol++] = tabcount;
        }
        if (use_sep_chars)
            c = '_';
        else
            c = ' ';
        screen_fill (0, 1, col, (int) Columns, c, c, attr_fill);
        if (first_tabpage->tp_next != NULL) {
            screen_putchar ('X', 0, (int) Columns - 1, attr_nosel);
            TabPageIdxs[Columns - 1] = -999;
        }
    }
    redraw_tabline = FALSE;
}

int get_keymap_str (win_T *wp, char_u *fmt, char_u *buf, int len) {
    char_u *p;
    if (wp->w_buffer->b_p_iminsert != B_IMODE_LMAP)
        return FALSE;
    {
        buf_T *old_curbuf = curbuf;
        win_T *old_curwin = curwin;
        char_u *s;
        curbuf = wp->w_buffer;
        curwin = wp;
        STRCPY (buf, "b:keymap_name");
        ++emsg_skip;
        s = p = eval_to_string (buf, NULL, FALSE);
        --emsg_skip;
        curbuf = old_curbuf;
        curwin = old_curwin;
        if (p == NULL || *p == NUL) {
            if (wp->w_buffer->b_kmap_state & KEYMAP_LOADED)
                p = wp->w_buffer->b_p_keymap;
            else
                p = (char_u *) "lang";
        }
        if (vim_snprintf ((char *) buf, len, (char *) fmt, p) > len - 1)
            buf[0] = NUL;
        vim_free (s);
    }
    return buf[0] != NUL;
}

void get_trans_bufname (buf_T *buf) {
    if (buf_spname (buf) != NULL)
        vim_strncpy (NameBuff, buf_spname (buf), MAXPATHL -1);
    else
        home_replace (buf, buf->b_fname, NameBuff, MAXPATHL, TRUE);
    trans_characters (NameBuff, MAXPATHL);
}

void screen_puts (char_u *text, int row, int col, int attr) {
    screen_puts_len (text, - 1, row, col, attr);
}

void screen_puts_len (char_u *text, int textlen, int row, int col, int attr) {
    unsigned  off;
    char_u *ptr = text;
    int len = textlen;
    int c;
    int force_redraw_this;
    int force_redraw_next = FALSE;
    int need_redraw;
    if (ScreenLines == NULL || row >= screen_Rows)
        return;
    off = LineOffset[row] + col;
    while (col < screen_Columns && (len < 0 || (int) (ptr - text) < len) && *ptr != NUL) {
        c = *ptr;
        force_redraw_this = force_redraw_next;
        force_redraw_next = FALSE;
        need_redraw = ScreenLines[off] != c || ScreenAttrs[off] != attr || exmode_active;
        if (need_redraw || force_redraw_this) {
            if (need_redraw && ScreenLines[off] != ' ' && (gui.in_use || term_is_xterm)) {
                int n = ScreenAttrs[off];
                if (n > HL_ALL)
                    n = syn_attr2attr (n);
                force_redraw_next = TRUE;
            }
            ScreenLines[off] = c;
            ScreenAttrs[off] = attr;
            screen_char (off, row, col);
        }
        {
            ++off;
            ++col;
            ++ptr;
        }
    }
    if (force_redraw_next && col < screen_Columns) {
        screen_char (off, row, col);
    }
}

static void win_redr_custom (win_T *wp, int draw_ruler) {
    static int entered = FALSE;
    int attr;
    int curattr;
    int row;
    int col = 0;
    int maxwidth;
    int width;
    int n;
    int len;
    int fillchar;
    char_u buf [MAXPATHL];
    char_u *stl;
    char_u *p;
    struct stl_hlrec hltab [STL_MAX_ITEM];
    struct stl_hlrec tabtab [STL_MAX_ITEM];
    int use_sandbox = FALSE;
    win_T *ewp;
    int p_crb_save;
    if (entered)
        return;
    entered = TRUE;
    if (wp == NULL) {
        stl = p_tal;
        row = 0;
        fillchar = ' ';
        attr = HL_ATTR (HLF_TPF);
        maxwidth = Columns;
        use_sandbox = was_set_insecurely ((char_u *) "tabline", 0);
    }
    else {
        row = W_WINROW (wp) + wp->w_height;
        fillchar = fillchar_status (&attr, wp);
        maxwidth = wp->w_width;
        if (draw_ruler) {
            stl = p_ruf;
            if (*stl == '%') {
                if (*++stl == '-')
                    stl++;
                if (atoi ((char *) stl))
                    while (VIM_ISDIGIT (*stl))
                        stl++;
                if (*stl++ != '(')
                    stl = p_ruf;
            }
            col = ru_col - (Columns - wp->w_width);
            if (col < (wp->w_width + 1) / 2)
                col = (wp->w_width + 1) / 2;
            maxwidth = wp->w_width - col;
            if (!wp->w_status_height) {
                row = Rows - 1;
                --maxwidth;
                fillchar = ' ';
                attr = 0;
            }
            use_sandbox = was_set_insecurely ((char_u *) "rulerformat", 0);
        }
        else {
            if (*wp->w_p_stl != NUL)
                stl = wp->w_p_stl;
            else
                stl = p_stl;
            use_sandbox = was_set_insecurely ((char_u *) "statusline", *wp->w_p_stl == NUL ? 0 : OPT_LOCAL);
        }
        col += wp->w_wincol;
    }
    if (maxwidth <= 0)
        goto theend;
    ewp = wp == NULL ? curwin : wp;
    p_crb_save = ewp->w_p_crb;
    ewp->w_p_crb = FALSE;
    stl = vim_strsave (stl);
    width = build_stl_str_hl (ewp, buf, sizeof (buf), stl, use_sandbox, fillchar, maxwidth, hltab, tabtab);
    vim_free (stl);
    ewp->w_p_crb = p_crb_save;
    p = transstr (buf);
    if (p != NULL) {
        vim_strncpy (buf, p, sizeof (buf) - 1);
        vim_free (p);
    }
    len = (int) STRLEN (buf);
    while (width < maxwidth && len < (int) sizeof (buf) - 1) {
        buf[len++] = fillchar;
        ++width;
    }
    buf[len] = NUL;
    curattr = attr;
    p = buf;
    for (n = 0; hltab[n].start != NULL; n++) {
        len = (int) (hltab[n].start - p);
        screen_puts_len (p, len, row, col, curattr);
        col += vim_strnsize (p, len);
        p = hltab[n].start;
        if (hltab[n].userhl == 0)
            curattr = attr;
        else if (hltab[n].userhl < 0)
            curattr = syn_id2attr (-hltab[n].userhl);
        else if (wp != NULL && wp != curwin && bt_terminal (wp->w_buffer) && wp->w_status_height != 0)
            curattr = highlight_stltermnc[hltab[n].userhl - 1];
        else if (wp != NULL && bt_terminal (wp->w_buffer) && wp->w_status_height != 0)
            curattr = highlight_stlterm[hltab[n].userhl - 1];
        else if (wp != NULL && wp != curwin && wp->w_status_height != 0)
            curattr = highlight_stlnc[hltab[n].userhl - 1];
        else
            curattr = highlight_user[hltab[n].userhl - 1];
    }
    screen_puts (p, row, col, curattr);
    if (wp == NULL) {
        col = 0;
        len = 0;
        p = buf;
        fillchar = 0;
        for (n = 0; tabtab[n].start != NULL; n++) {
            len += vim_strnsize (p, (int) (tabtab[n].start - p));
            while (col < len)
                TabPageIdxs[col++] = fillchar;
            p = tabtab[n].start;
            fillchar = tabtab[n].userhl;
        }
        while (col < Columns)
            TabPageIdxs[col++] = fillchar;
    }
theend :
    entered = FALSE;
}

void screen_putchar (int c, int row, int col, int attr) {
    char_u buf [MB_MAXBYTES + 1];
    {
        buf[0] = c;
        buf[1] = NUL;
    }
    screen_puts (buf, row, col, attr);
}

static void start_search_hl (void) {
    if (p_hls && !no_hlsearch) {
        last_pat_prog (& search_hl.rm);
        search_hl.attr = HL_ATTR (HLF_L);
        profile_setlimit (p_rdt, & search_hl.tm);
    }
}

static void win_update (win_T *wp) {
    buf_T *buf = wp->w_buffer;
    int type;
    int top_end = 0;
    int mid_start = 999;
    int mid_end = 0;
    int bot_start = 999;
    int scrolled_down = FALSE;
    matchitem_T *cur;
    int top_to_mod = FALSE;
    int row;
    linenr_T lnum;
    int idx;
    int srow;
    int eof = FALSE;
    int didline = FALSE;
    int i;
    long  j;
    static int recursive = FALSE;
    int old_botline = wp->w_botline;
    long  fold_count;

    #define DID_NONE 1	/* didn't update a line */

    #define DID_LINE 2	/* updated a normal line */

    #define DID_FOLD 3	/* updated a folded line */
    int did_update = DID_NONE;
    linenr_T syntax_last_parsed = 0;
    linenr_T mod_top = 0;
    linenr_T mod_bot = 0;
    int save_got_int;
    type = wp->w_redr_type;
    if (type == NOT_VALID) {
        wp->w_redr_status = TRUE;
        wp->w_lines_valid = 0;
    }
    if (wp->w_height + WINBAR_HEIGHT (wp) == 0) {
        wp->w_redr_type = 0;
        return;
    }
    if (wp->w_width == 0) {
        draw_vsep_win (wp, 0);
        wp->w_redr_type = 0;
        return;
    }
    if (term_update_window (wp) == OK) {
        if (winbar_height (wp) > 0)
            redraw_win_toolbar (wp);
        wp->w_redr_type = 0;
        return;
    }
    init_search_hl (wp);
    i = (wp->w_p_nu || wp->w_p_rnu) ? number_width (wp) : 0;
    if (wp->w_nrwidth != i) {
        type = NOT_VALID;
        wp->w_nrwidth = i;
    }
    else if (buf->b_mod_set && buf->b_mod_xlines != 0 && wp->w_redraw_top != 0) {
        type = NOT_VALID;
    }
    else {
        mod_top = wp->w_redraw_top;
        if (wp->w_redraw_bot != 0)
            mod_bot = wp->w_redraw_bot + 1;
        else
            mod_bot = 0;
        wp->w_redraw_top = 0;
        wp->w_redraw_bot = 0;
        if (buf->b_mod_set) {
            if (mod_top == 0 || mod_top > buf->b_mod_top) {
                mod_top = buf->b_mod_top;
                if (syntax_present (wp)) {
                    mod_top -= buf->b_s.b_syn_sync_linebreaks;
                    if (mod_top < 1)
                        mod_top = 1;
                }
            }
            if (mod_bot == 0 || mod_bot < buf->b_mod_bot)
                mod_bot = buf->b_mod_bot;
            if (search_hl.rm.regprog != NULL && re_multiline (search_hl.rm.regprog))
                top_to_mod = TRUE;
            else {
                cur = wp->w_match_head;
                while (cur != NULL) {
                    if (cur->match.regprog != NULL && re_multiline (cur->match.regprog)) {
                        top_to_mod = TRUE;
                        break;
                    }
                    cur = cur->next;
                }
            }
        }
        if (mod_top != 0 && hasAnyFolding (wp)) {
            linenr_T lnumt, lnumb;
            lnumt = wp->w_topline;
            lnumb = MAXLNUM;
            for (i = 0; i < wp->w_lines_valid; ++i)
                if (wp->w_lines[i].wl_valid) {
                    if (wp->w_lines[i].wl_lastlnum < mod_top)
                        lnumt = wp->w_lines[i].wl_lastlnum + 1;
                    if (lnumb == MAXLNUM && wp->w_lines[i].wl_lnum >= mod_bot) {
                        lnumb = wp->w_lines[i].wl_lnum;
                        if (compute_foldcolumn (wp, 0) > 0)
                            ++lnumb;
                    }
                }
            (void) hasFoldingWin (wp, mod_top, &mod_top, NULL, TRUE, NULL);
            if (mod_top > lnumt)
                mod_top = lnumt;
            --mod_bot;
            (void) hasFoldingWin (wp, mod_bot, NULL, &mod_bot, TRUE, NULL);
            ++mod_bot;
            if (mod_bot < lnumb)
                mod_bot = lnumb;
        }
        if (mod_top != 0 && mod_top < wp->w_topline) {
            if (mod_bot > wp->w_topline)
                mod_top = wp->w_topline;
            else if (syntax_present (wp))
                top_end = 1;
        }
        if (mod_top != 0 && buf->b_mod_xlines != 0 && wp->w_p_nu)
            mod_bot = MAXLNUM;
    }
    if (type == REDRAW_TOP) {
        j = 0;
        for (i = 0; i < wp->w_lines_valid; ++i) {
            j += wp->w_lines[i].wl_size;
            if (j >= wp->w_upd_rows) {
                top_end = j;
                break;
            }
        }
        if (top_end == 0)
            type = NOT_VALID;
        else
            type = VALID;
    }
    if (screen_cleared)
        screen_cleared = MAYBE;
    if ((type == VALID || type == SOME_VALID || type == INVERTED || type == INVERTED_ALL) && !wp->w_botfill && !wp->w_old_botfill) {
        if (mod_top != 0 && wp->w_topline == mod_top) {
        }
        else if (wp->w_lines[0].wl_valid && (wp->w_topline < wp->w_lines[0].wl_lnum || (wp->w_topline == wp->w_lines[0].wl_lnum && wp->w_topfill > wp->w_old_topfill))) {
            if (hasAnyFolding (wp)) {
                linenr_T ln;
                j = 0;
                for (ln = wp->w_topline; ln < wp->w_lines[0].wl_lnum; ++ln) {
                    ++j;
                    if (j >= wp->w_height - 2)
                        break;
                    (void) hasFoldingWin (wp, ln, NULL, &ln, TRUE, NULL);
                }
            }
            else
                j = wp->w_lines[0].wl_lnum - wp->w_topline;
            if (j < wp->w_height - 2) {
                i = plines_m_win (wp, wp->w_topline, wp->w_lines[0].wl_lnum - 1);
                if (wp->w_lines[0].wl_lnum != wp->w_topline)
                    i += diff_check_fill (wp, wp->w_lines[0].wl_lnum) - wp->w_old_topfill;
                if (i < wp->w_height - 2) {
                    if (i > 0)
                        check_for_delay (FALSE);
                    if (win_ins_lines (wp, 0, i, FALSE, wp == firstwin) == OK) {
                        if (wp->w_lines_valid != 0) {
                            top_end = i;
                            scrolled_down = TRUE;
                            if ((wp->w_lines_valid += j) > wp->w_height)
                                wp->w_lines_valid = wp->w_height;
                            for (idx = wp->w_lines_valid; idx - j >= 0; idx--)
                                wp->w_lines[idx] = wp->w_lines[idx - j];
                            while (idx >= 0)
                                wp->w_lines[idx--].wl_valid = FALSE;
                        }
                    }
                    else
                        mid_start = 0;
                }
                else
                    mid_start = 0;
            }
            else
                mid_start = 0;
        }
        else {
            j = -1;
            row = 0;
            for (i = 0; i < wp->w_lines_valid; i++) {
                if (wp->w_lines[i].wl_valid && wp->w_lines[i].wl_lnum == wp->w_topline) {
                    j = i;
                    break;
                }
                row += wp->w_lines[i].wl_size;
            }
            if (j == -1) {
                mid_start = 0;
            }
            else {
                if (wp->w_lines[0].wl_lnum == wp->w_topline)
                    row += wp->w_old_topfill;
                else
                    row += diff_check_fill (wp, wp->w_topline);
                row -= wp->w_topfill;
                if (row > 0) {
                    check_for_delay (FALSE);
                    if (win_del_lines (wp, 0, row, FALSE, wp == firstwin, 0) == OK)
                        bot_start = wp->w_height - row;
                    else
                        mid_start = 0;
                }
                if ((row == 0 || bot_start < 999) && wp->w_lines_valid != 0) {
                    bot_start = 0;
                    idx = 0;
                    for (;;) {
                        wp->w_lines[idx] = wp->w_lines[j];
                        if (row > 0 && bot_start + row + (int) wp->w_lines[j].wl_size > wp->w_height) {
                            wp->w_lines_valid = idx + 1;
                            break;
                        }
                        bot_start += wp->w_lines[idx++].wl_size;
                        if (++j >= wp->w_lines_valid) {
                            wp->w_lines_valid = idx;
                            break;
                        }
                    }
                    if (wp->w_p_diff && bot_start > 0)
                        wp->w_lines[0].wl_size = plines_win_nofill (wp, wp->w_topline, TRUE) + wp->w_topfill;
                }
            }
        }
        if (mid_start == 0) {
            mid_end = wp->w_height;
            if (ONE_WINDOW) {
                if (screen_cleared != TRUE)
                    screenclear ();
                if (redraw_tabline)
                    draw_tabline ();
            }
        }
        if (screen_cleared == TRUE)
            must_redraw = 0;
    }
    else {
        mid_start = 0;
        mid_end = wp->w_height;
    }
    if (type == SOME_VALID) {
        mid_start = 0;
        mid_end = wp->w_height;
        type = NOT_VALID;
    }
    if ((VIsual_active && buf == curwin->w_buffer) || (wp->w_old_cursor_lnum != 0 && type != NOT_VALID)) {
        linenr_T from, to;
        if (VIsual_active) {
            if (VIsual_active && (VIsual_mode != wp->w_old_visual_mode || type == INVERTED_ALL)) {
                if (curwin->w_cursor.lnum < VIsual.lnum) {
                    from = curwin->w_cursor.lnum;
                    to = VIsual.lnum;
                }
                else {
                    from = VIsual.lnum;
                    to = curwin->w_cursor.lnum;
                }
                if (wp->w_old_cursor_lnum < from)
                    from = wp->w_old_cursor_lnum;
                if (wp->w_old_cursor_lnum > to)
                    to = wp->w_old_cursor_lnum;
                if (wp->w_old_visual_lnum < from)
                    from = wp->w_old_visual_lnum;
                if (wp->w_old_visual_lnum > to)
                    to = wp->w_old_visual_lnum;
            }
            else {
                if (curwin->w_cursor.lnum < wp->w_old_cursor_lnum) {
                    from = curwin->w_cursor.lnum;
                    to = wp->w_old_cursor_lnum;
                }
                else {
                    from = wp->w_old_cursor_lnum;
                    to = curwin->w_cursor.lnum;
                    if (from == 0)
                        from = to;
                }
                if (VIsual.lnum != wp->w_old_visual_lnum || VIsual.col != wp->w_old_visual_col) {
                    if (wp->w_old_visual_lnum < from && wp->w_old_visual_lnum != 0)
                        from = wp->w_old_visual_lnum;
                    if (wp->w_old_visual_lnum > to)
                        to = wp->w_old_visual_lnum;
                    if (VIsual.lnum < from)
                        from = VIsual.lnum;
                    if (VIsual.lnum > to)
                        to = VIsual.lnum;
                }
            }
            if (VIsual_mode == Ctrl_V) {
                colnr_T fromc, toc;
                int save_ve_flags = ve_flags;
                if (curwin->w_p_lbr)
                    ve_flags = VE_ALL;
                getvcols (wp, & VIsual, & curwin -> w_cursor, & fromc, & toc);
                ve_flags = save_ve_flags;
                ++toc;
                if (curwin->w_curswant == MAXCOL)
                    toc = MAXCOL;
                if (fromc != wp->w_old_cursor_fcol || toc != wp->w_old_cursor_lcol) {
                    if (from > VIsual.lnum)
                        from = VIsual.lnum;
                    if (to < VIsual.lnum)
                        to = VIsual.lnum;
                }
                wp->w_old_cursor_fcol = fromc;
                wp->w_old_cursor_lcol = toc;
            }
        }
        else {
            if (wp->w_old_cursor_lnum < wp->w_old_visual_lnum) {
                from = wp->w_old_cursor_lnum;
                to = wp->w_old_visual_lnum;
            }
            else {
                from = wp->w_old_visual_lnum;
                to = wp->w_old_cursor_lnum;
            }
        }
        if (from < wp->w_topline)
            from = wp->w_topline;
        if (wp->w_valid & VALID_BOTLINE) {
            if (from >= wp->w_botline)
                from = wp->w_botline - 1;
            if (to >= wp->w_botline)
                to = wp->w_botline - 1;
        }
        if (mid_start > 0) {
            lnum = wp->w_topline;
            idx = 0;
            srow = 0;
            if (scrolled_down)
                mid_start = top_end;
            else
                mid_start = 0;
            while (lnum < from && idx < wp->w_lines_valid) {
                if (wp->w_lines[idx].wl_valid)
                    mid_start += wp->w_lines[idx].wl_size;
                else if (!scrolled_down)
                    srow += wp->w_lines[idx].wl_size;
                ++idx;
                if (idx < wp->w_lines_valid && wp->w_lines[idx].wl_valid)
                    lnum = wp->w_lines[idx].wl_lnum;
                else
                    ++lnum;
            }
            srow += mid_start;
            mid_end = wp->w_height;
            for (; idx < wp->w_lines_valid; ++idx) {
                if (wp->w_lines[idx].wl_valid && wp->w_lines[idx].wl_lnum >= to + 1) {
                    mid_end = srow;
                    break;
                }
                srow += wp->w_lines[idx].wl_size;
            }
        }
    }
    if (VIsual_active && buf == curwin->w_buffer) {
        wp->w_old_visual_mode = VIsual_mode;
        wp->w_old_cursor_lnum = curwin->w_cursor.lnum;
        wp->w_old_visual_lnum = VIsual.lnum;
        wp->w_old_visual_col = VIsual.col;
        wp->w_old_curswant = curwin->w_curswant;
    }
    else {
        wp->w_old_visual_mode = 0;
        wp->w_old_cursor_lnum = 0;
        wp->w_old_visual_lnum = 0;
        wp->w_old_visual_col = 0;
    }
    save_got_int = got_int;
    got_int = 0;
    win_foldinfo.fi_level = 0;
    if (winbar_height (wp) > 0)
        redraw_win_toolbar (wp);
    idx = 0;
    row = 0;
    srow = 0;
    lnum = wp->w_topline;
    for (;;) {
        if (row == wp->w_height) {
            didline = TRUE;
            break;
        }
        if (lnum > buf->b_ml.ml_line_count) {
            eof = TRUE;
            break;
        }
        srow = row;
        if (row < top_end || (row >= mid_start && row < mid_end) || top_to_mod || idx >= wp->w_lines_valid || (row + wp->w_lines[idx].wl_size > bot_start) || (mod_top != 0 && (lnum == mod_top || (lnum >= mod_top && (lnum < mod_bot || did_update == DID_FOLD || (did_update == DID_LINE && syntax_present (wp) && ((foldmethodIsSyntax (wp) && hasAnyFolding (wp)) || syntax_check_changed (lnum))) || (wp->w_match_head != NULL && buf->b_mod_xlines != 0)))))) {
            if (lnum == mod_top)
                top_to_mod = FALSE;
            if (lnum == mod_top && mod_bot != MAXLNUM && !(dollar_vcol >= 0 && mod_bot == mod_top + 1)) {
                int old_rows = 0;
                int new_rows = 0;
                int xtra_rows;
                linenr_T l;
                for (i = idx; i < wp->w_lines_valid; ++i) {
                    if (wp->w_lines[i].wl_valid && wp->w_lines[i].wl_lnum == mod_bot)
                        break;
                    old_rows += wp->w_lines[i].wl_size;
                    if (wp->w_lines[i].wl_valid && wp->w_lines[i].wl_lastlnum + 1 == mod_bot) {
                        ++i;
                        while (i < wp->w_lines_valid && !wp->w_lines[i].wl_valid)
                            old_rows += wp->w_lines[i++].wl_size;
                        break;
                    }
                }
                if (i >= wp->w_lines_valid) {
                    bot_start = 0;
                }
                else {
                    j = idx;
                    for (l = lnum; l < mod_bot; ++l) {
                        if (hasFoldingWin (wp, l, NULL, &l, TRUE, NULL))
                            ++new_rows;
                        else if (l == wp->w_topline)
                            new_rows += plines_win_nofill (wp, l, TRUE) + wp->w_topfill;
                        else
                            new_rows += plines_win (wp, l, TRUE);
                        ++j;
                        if (new_rows > wp->w_height - row - 2) {
                            new_rows = 9999;
                            break;
                        }
                    }
                    xtra_rows = new_rows - old_rows;
                    if (xtra_rows < 0) {
                        if (row - xtra_rows >= wp->w_height - 2)
                            mod_bot = MAXLNUM;
                        else {
                            check_for_delay (FALSE);
                            if (win_del_lines (wp, row, -xtra_rows, FALSE, FALSE, 0) == FAIL)
                                mod_bot = MAXLNUM;
                            else
                                bot_start = wp->w_height + xtra_rows;
                        }
                    }
                    else if (xtra_rows > 0) {
                        if (row + xtra_rows >= wp->w_height - 2)
                            mod_bot = MAXLNUM;
                        else {
                            check_for_delay (FALSE);
                            if (win_ins_lines (wp, row +old_rows, xtra_rows, FALSE, FALSE) == FAIL)
                                mod_bot = MAXLNUM;
                            else if (top_end > row + old_rows)
                                top_end += xtra_rows;
                        }
                    }
                    if (mod_bot != MAXLNUM && i != j) {
                        if (j < i) {
                            int x = row + new_rows;
                            for (;;) {
                                if (i >= wp->w_lines_valid) {
                                    wp->w_lines_valid = j;
                                    break;
                                }
                                wp->w_lines[j] = wp->w_lines[i];
                                if (x + (int) wp->w_lines[j].wl_size > wp->w_height) {
                                    wp->w_lines_valid = j + 1;
                                    break;
                                }
                                x += wp->w_lines[j++].wl_size;
                                ++i;
                            }
                            if (bot_start > x)
                                bot_start = x;
                        }
                        else {
                            j -= i;
                            wp->w_lines_valid += j;
                            if (wp->w_lines_valid > wp->w_height)
                                wp->w_lines_valid = wp->w_height;
                            for (i = wp->w_lines_valid; i - j >= idx; --i)
                                wp->w_lines[i] = wp->w_lines[i - j];
                            while (i >= idx) {
                                wp->w_lines[i].wl_size = 0;
                                wp->w_lines[i--].wl_valid = FALSE;
                            }
                        }
                    }
                }
            }
            fold_count = foldedCount (wp, lnum, &win_foldinfo);
            if (fold_count != 0) {
                fold_line (wp, fold_count, & win_foldinfo, lnum, row);
                ++row;
                --fold_count;
                wp->w_lines[idx].wl_folded = TRUE;
                wp->w_lines[idx].wl_lastlnum = lnum + fold_count;
                did_update = DID_FOLD;
            }
            else if (idx < wp->w_lines_valid && wp->w_lines[idx].wl_valid && wp->w_lines[idx].wl_lnum == lnum && lnum > wp->w_topline && !(dy_flags & (DY_LASTLINE | DY_TRUNCATE)) && srow + wp->w_lines[idx].wl_size > wp->w_height && diff_check_fill (wp, lnum) == 0) {
                row = wp->w_height + 1;
            }
            else {
                prepare_search_hl (wp, lnum);
                if (syntax_last_parsed != 0 && syntax_last_parsed + 1 < lnum && syntax_present (wp))
                    syntax_end_parsing (syntax_last_parsed +1);
                row = win_line (wp, lnum, srow, wp->w_height, mod_top == 0);
                wp->w_lines[idx].wl_folded = FALSE;
                wp->w_lines[idx].wl_lastlnum = lnum;
                did_update = DID_LINE;
                syntax_last_parsed = lnum;
            }
            wp->w_lines[idx].wl_lnum = lnum;
            wp->w_lines[idx].wl_valid = TRUE;
            if (row > wp->w_height || row + wp->w_winrow >= Rows) {
                if (dollar_vcol == -1)
                    wp->w_lines[idx].wl_size = plines_win (wp, lnum, TRUE);
                ++idx;
                break;
            }
            if (dollar_vcol == -1)
                wp->w_lines[idx].wl_size = row - srow;
            ++idx;
            lnum += fold_count + 1;
        }
        else {
            row += wp->w_lines[idx++].wl_size;
            if (row > wp->w_height)
                break;
            lnum = wp->w_lines[idx - 1].wl_lastlnum + 1;
            did_update = DID_NONE;
        }
        if (lnum > buf->b_ml.ml_line_count) {
            eof = TRUE;
            break;
        }
    }
    if (idx > wp->w_lines_valid)
        wp->w_lines_valid = idx;
    if (syntax_last_parsed != 0 && syntax_present (wp))
        syntax_end_parsing (syntax_last_parsed +1);
    wp->w_empty_rows = 0;
    wp->w_filler_rows = 0;
    if (!eof && !didline) {
        if (lnum == wp->w_topline) {
            wp->w_botline = lnum + 1;
        }
        else if (diff_check_fill (wp, lnum) >= wp->w_height - srow) {
            wp->w_botline = lnum;
            wp->w_filler_rows = wp->w_height - srow;
        }
        else if (dy_flags & DY_TRUNCATE) {
            int scr_row = W_WINROW (wp) + wp->w_height - 1;
            screen_puts_len ((char_u *) "@@", 2, scr_row, wp -> w_wincol, HL_ATTR (HLF_AT));
            screen_fill (scr_row, scr_row + 1, (int) wp -> w_wincol + 2, (int) W_ENDCOL (wp), '@', ' ', HL_ATTR (HLF_AT));
            set_empty_rows (wp, srow);
            wp->w_botline = lnum;
        }
        else if (dy_flags & DY_LASTLINE) {
            screen_fill (W_WINROW (wp) + wp -> w_height - 1, W_WINROW (wp) + wp -> w_height, (int) W_ENDCOL (wp) - 3, (int) W_ENDCOL (wp), '@', '@', HL_ATTR (HLF_AT));
            set_empty_rows (wp, srow);
            wp->w_botline = lnum;
        }
        else {
            win_draw_end (wp, '@', ' ', srow, wp -> w_height, HLF_AT);
            wp->w_botline = lnum;
        }
    }
    else {
        draw_vsep_win (wp, row);
        if (eof) {
            wp->w_botline = buf->b_ml.ml_line_count + 1;
            j = diff_check_fill (wp, wp->w_botline);
            if (j > 0 && !wp->w_botfill) {
                if (char2cells (fill_diff) > 1)
                    i = '-';
                else
                    i = fill_diff;
                if (row + j > wp->w_height)
                    j = wp->w_height - row;
                win_draw_end (wp, i, i, row, row + (int) j, HLF_DED);
                row += j;
            }
        }
        else if (dollar_vcol == -1)
            wp->w_botline = lnum;
        win_draw_end (wp, '~', ' ', row, wp -> w_height, HLF_EOB);
    }
    wp->w_redr_type = 0;
    wp->w_old_topfill = wp->w_topfill;
    wp->w_old_botfill = wp->w_botfill;
    if (dollar_vcol == -1) {
        wp->w_valid |= VALID_BOTLINE;
        if (wp == curwin && wp->w_botline != old_botline && !recursive) {
            recursive = TRUE;
            curwin->w_valid &= ~VALID_TOPLINE;
            update_topline ();
            if (must_redraw != 0) {
                i = curbuf->b_mod_set;
                curbuf->b_mod_set = FALSE;
                win_update (curwin);
                must_redraw = 0;
                curbuf->b_mod_set = i;
            }
            recursive = FALSE;
        }
    }
    if (!got_int)
        got_int = save_got_int;
}

static void draw_vsep_win (win_T *wp, int row) {
    int hl;
    int c;
    if (wp->w_vsep_width) {
        c = fillchar_vsep (&hl);
        screen_fill (W_WINROW (wp) + row, W_WINROW (wp) + wp -> w_height, W_ENDCOL (wp), W_ENDCOL (wp) + 1, c, ' ', hl);
    }
}

static int fillchar_vsep (int *attr) {
    *attr = HL_ATTR (HLF_C);
    if (*attr == 0 && fill_vert == ' ')
        return '|';
    else
        return fill_vert;
}

static void init_search_hl (win_T *wp) {
    matchitem_T *cur;
    cur = wp->w_match_head;
    while (cur != NULL) {
        cur->hl.rm = cur->match;
        if (cur->hlg_id == 0)
            cur->hl.attr = 0;
        else
            cur->hl.attr = syn_id2attr (cur->hlg_id);
        cur->hl.buf = wp->w_buffer;
        cur->hl.lnum = 0;
        cur->hl.first_lnum = 0;
        profile_setlimit (p_rdt, & (cur -> hl.tm));
        cur = cur->next;
    }
    search_hl.buf = wp->w_buffer;
    search_hl.lnum = 0;
    search_hl.first_lnum = 0;
}

int win_ins_lines (win_T *wp, int row, int line_count, int invalid, int mayclear) {
    int did_delete;
    int nextrow;
    int lastrow;
    int retval;
    if (invalid)
        wp->w_lines_valid = 0;
    if (wp->w_height < 5)
        return FAIL;
    if (line_count > wp->w_height - row)
        line_count = wp->w_height - row;
    retval = win_do_lines (wp, row, line_count, mayclear, FALSE, 0);
    if (retval != MAYBE)
        return retval;
    did_delete = FALSE;
    if (wp->w_next != NULL || wp->w_status_height) {
        if (screen_del_lines (0, W_WINROW (wp) +wp->w_height - line_count, line_count, (int) Rows, FALSE, 0, NULL) == OK)
            did_delete = TRUE;
        else if (wp->w_next)
            return FAIL;
    }
    if (!did_delete) {
        wp->w_redr_status = TRUE;
        redraw_cmdline = TRUE;
        nextrow = W_WINROW (wp) + wp->w_height + wp->w_status_height;
        lastrow = nextrow + line_count;
        if (lastrow > Rows)
            lastrow = Rows;
        screen_fill (nextrow - line_count, lastrow - line_count, wp -> w_wincol, (int) W_ENDCOL (wp), ' ', ' ', 0);
    }
    if (screen_ins_lines (0, W_WINROW (wp) +row, line_count, (int) Rows, 0, NULL) == FAIL) {
        if (did_delete) {
            wp->w_redr_status = TRUE;
            win_rest_invalid (W_NEXT (wp));
        }
        return FAIL;
    }
    return OK;
}

static int win_do_lines (win_T *wp, int row, int line_count, int mayclear, int del, int clear_attr) {
    int retval;
    if (!redrawing () || line_count <= 0)
        return FAIL;
    if (no_win_do_lines_ins && !del)
        return FAIL;
    if (mayclear && Rows - line_count < 5 && wp->w_width == Columns) {
        if (!no_win_do_lines_ins)
            screenclear ();
        return FAIL;
    }
    if (row + line_count >= wp->w_height) {
        screen_fill (W_WINROW (wp) + row, W_WINROW (wp) + wp -> w_height, wp -> w_wincol, (int) W_ENDCOL (wp), ' ', ' ', 0);
        return OK;
    }
    if (!no_win_do_lines_ins)
        clear_cmdline = TRUE;
    if (scroll_region || wp->w_width != Columns) {
        if (scroll_region && (wp->w_width == Columns || *T_CSV != NUL))
            scroll_region_set (wp, row);
        if (del)
            retval = screen_del_lines (W_WINROW (wp) +row, 0, line_count, wp->w_height - row, FALSE, clear_attr, wp);
        else
            retval = screen_ins_lines (W_WINROW (wp) +row, 0, line_count, wp->w_height - row, clear_attr, wp);
        if (scroll_region && (wp->w_width == Columns || *T_CSV != NUL))
            scroll_region_reset ();
        return retval;
    }
    if (wp->w_next != NULL && p_tf)
        return FAIL;
    return MAYBE;
}

int win_del_lines (win_T *wp, int row, int line_count, int invalid, int mayclear, int clear_attr) {
    int retval;
    if (invalid)
        wp->w_lines_valid = 0;
    if (line_count > wp->w_height - row)
        line_count = wp->w_height - row;
    retval = win_do_lines (wp, row, line_count, mayclear, TRUE, clear_attr);
    if (retval != MAYBE)
        return retval;
    if (screen_del_lines (0, W_WINROW (wp) +row, line_count, (int) Rows, FALSE, clear_attr, NULL) == FAIL)
        return FAIL;
    if (wp->w_next || wp->w_status_height || cmdline_row < Rows - 1) {
        if (screen_ins_lines (0, W_WINROW (wp) +wp->w_height - line_count, line_count, (int) Rows, clear_attr, NULL) == FAIL) {
            wp->w_redr_status = TRUE;
            win_rest_invalid (wp -> w_next);
        }
    }
    else
        redraw_cmdline = TRUE;
    return OK;
}

static void prepare_search_hl (win_T *wp, linenr_T lnum) {
    matchitem_T *cur;
    match_T *shl;
    int shl_flag;
    int pos_inprogress;
    int n;
    cur = wp->w_match_head;
    shl_flag = FALSE;
    while (cur != NULL || shl_flag == FALSE) {
        if (shl_flag == FALSE) {
            shl = &search_hl;
            shl_flag = TRUE;
        }
        else
            shl = &cur->hl;
        if (shl->rm.regprog != NULL && shl->lnum == 0 && re_multiline (shl->rm.regprog)) {
            if (shl->first_lnum == 0) {
                for (shl->first_lnum = lnum; shl->first_lnum > wp->w_topline; --shl->first_lnum)
                    if (hasFoldingWin (wp, shl->first_lnum - 1, NULL, NULL, TRUE, NULL))
                        break;
            }
            if (cur != NULL)
                cur->pos.cur = 0;
            pos_inprogress = TRUE;
            n = 0;
            while (shl->first_lnum < lnum && (shl->rm.regprog != NULL || (cur != NULL && pos_inprogress))) {
                next_search_hl (wp, shl, shl -> first_lnum, (colnr_T) n, shl == & search_hl ? NULL : cur);
                pos_inprogress = cur == NULL || cur->pos.cur == 0 ? FALSE : TRUE;
                if (shl->lnum != 0) {
                    shl->first_lnum = shl->lnum + shl->rm.endpos[0].lnum - shl->rm.startpos[0].lnum;
                    n = shl->rm.endpos[0].col;
                }
                else {
                    ++shl->first_lnum;
                    n = 0;
                }
            }
        }
        if (shl != &search_hl && cur != NULL)
            cur = cur->next;
    }
}

static void next_search_hl (win_T *win, match_T *shl, linenr_T lnum, colnr_T mincol, matchitem_T *cur) {
    linenr_T l;
    colnr_T matchcol;
    long  nmatched;
    if (shl->lnum != 0) {
        l = shl->lnum + shl->rm.endpos[0].lnum - shl->rm.startpos[0].lnum;
        if (lnum > l)
            shl->lnum = 0;
        else if (lnum < l || shl->rm.endpos[0].col > mincol)
            return;
    }
    called_emsg = FALSE;
    for (;;) {
        if (profile_passed_limit (&(shl->tm))) {
            shl->lnum = 0;
            break;
        }
        if (shl->lnum == 0)
            matchcol = 0;
        else if (vim_strchr (p_cpo, CPO_SEARCH) == NULL || (shl->rm.endpos[0].lnum == 0 && shl->rm.endpos[0].col <= shl->rm.startpos[0].col)) {
            char_u *ml;
            matchcol = shl->rm.startpos[0].col;
            ml = ml_get_buf (shl->buf, lnum, FALSE) + matchcol;
            if (*ml == NUL) {
                ++matchcol;
                shl->lnum = 0;
                break;
            }
            ++matchcol;
        }
        else
            matchcol = shl->rm.endpos[0].col;
        shl->lnum = lnum;
        if (shl->rm.regprog != NULL) {
            int regprog_is_copy = (shl != &search_hl && cur != NULL && shl == &cur->hl && cur->match.regprog == cur->hl.rm.regprog);
            int timed_out = FALSE;
            nmatched = vim_regexec_multi (&shl->rm, win, shl->buf, lnum, matchcol, &(shl->tm), &timed_out);
            if (regprog_is_copy)
                cur->match.regprog = cur->hl.rm.regprog;
            if (called_emsg || got_int || timed_out) {
                if (shl == &search_hl) {
                    vim_regfree (shl -> rm.regprog);
                    SET_NO_HLSEARCH (TRUE);
                }
                shl->rm.regprog = NULL;
                shl->lnum = 0;
                got_int = FALSE;
                break;
            }
        }
        else if (cur != NULL)
            nmatched = next_search_hl_pos (shl, lnum, &(cur->pos), matchcol);
        else
            nmatched = 0;
        if (nmatched == 0) {
            shl->lnum = 0;
            break;
        }
        if (shl->rm.startpos[0].lnum > 0 || shl->rm.startpos[0].col >= mincol || nmatched > 1 || shl->rm.endpos[0].col > mincol) {
            shl->lnum += shl->rm.startpos[0].lnum;
            break;
        }
    }
}

static int next_search_hl_pos (match_T *shl, linenr_T lnum, posmatch_T *posmatch, colnr_T mincol) {
    int i;
    int found = -1;
    for (i = posmatch->cur; i < MAXPOSMATCH; i++) {
        llpos_T *pos = &posmatch->pos[i];
        if (pos->lnum == 0)
            break;
        if (pos->len == 0 && pos->col < mincol)
            continue;
        if (pos->lnum == lnum) {
            if (found >= 0) {
                if (pos->col < posmatch->pos[found].col) {
                    llpos_T tmp = *pos;
                    *pos = posmatch->pos[found];
                    posmatch->pos[found] = tmp;
                }
            }
            else
                found = i;
        }
    }
    posmatch->cur = 0;
    if (found >= 0) {
        colnr_T start = posmatch->pos[found].col == 0 ? 0 : posmatch->pos[found].col - 1;
        colnr_T end = posmatch->pos[found].col == 0 ? MAXCOL : start + posmatch->pos[found].len;
        shl->lnum = lnum;
        shl->rm.startpos[0].lnum = 0;
        shl->rm.startpos[0].col = start;
        shl->rm.endpos[0].lnum = 0;
        shl->rm.endpos[0].col = end;
        shl->is_addpos = TRUE;
        posmatch->cur = found + 1;
        return 1;
    }
    return 0;
}

static int win_line (win_T *wp, linenr_T lnum, int startrow, int endrow, int nochange) {
    int col = 0;
    unsigned  off;
    int c = 0;
    long  vcol = 0;
    long  vcol_sbr = -1;
    long  vcol_prev = -1;
    char_u *line;
    char_u *ptr;
    int row;
    int screen_row;
    char_u extra [18];
    int n_extra = 0;
    char_u *p_extra = NULL;
    char_u *p_extra_free = NULL;
    int c_extra = NUL;
    int extra_attr = 0;
    static char_u *at_end_str = (char_u *) "";
    int lcs_eol_one = lcs_eol;
    int lcs_prec_todo = lcs_prec;
    int saved_n_extra = 0;
    char_u *saved_p_extra = NULL;
    int saved_c_extra = 0;
    int saved_char_attr = 0;
    int n_attr = 0;
    int saved_attr2 = 0;
    int n_attr3 = 0;
    int saved_attr3 = 0;
    int n_skip = 0;
    int fromcol, tocol;
    int fromcol_prev = -2;
    int noinvcur = FALSE;
    pos_T *top, *bot;
    int lnum_in_visual_area = FALSE;
    pos_T pos;
    long  v;
    int char_attr = 0;
    int attr_pri = FALSE;
    int area_highlighting = FALSE;
    int attr = 0;
    int area_attr = 0;
    int search_attr = 0;
    int vcol_save_attr = 0;
    int syntax_attr = 0;
    int has_syntax = FALSE;
    int save_did_emsg;
    int eol_hl_off = 0;
    int draw_color_col = FALSE;
    int *color_cols = NULL;
    int extra_check;
    int filler_lines;
    int filler_todo;
    hlf_T diff_hlf = (hlf_T) 0;
    int change_start = MAXCOL;
    int change_end = -1;
    colnr_T trailcol = MAXCOL;
    int need_showbreak = FALSE;

    # define LINE_ATTR
    int line_attr = 0;
    matchitem_T *cur;
    match_T *shl;
    int shl_flag;
    int pos_inprogress;
    int prevcol_hl_flag;
    int prev_c = 0;
    int prev_c1 = 0;
    int did_line_attr = 0;
    int get_term_attr = FALSE;
    int term_attr = 0;

    #define WL_START	0		/* nothing done yet */

    # define WL_CMDLINE	WL_START

    # define WL_FOLD	WL_CMDLINE + 1	/* 'foldcolumn' */

    # define WL_SIGN	WL_FOLD + 1	/* column for signs */

    #define WL_NR		WL_SIGN + 1	/* line number */

    # define WL_BRI		WL_NR + 1	/* 'breakindent' */

    # define WL_SBR		WL_BRI + 1	/* 'showbreak' or 'diff' */

    #define WL_LINE		WL_SBR + 1	/* text in the line */
    int draw_state = WL_START;
    int syntax_flags = 0;
    int syntax_seqnr = 0;
    int prev_syntax_id = 0;
    int conceal_attr = HL_ATTR (HLF_CONCEAL);
    int is_concealing = FALSE;
    int boguscols = 0;
    int vcol_off = 0;
    int did_wcol = FALSE;
    int match_conc = 0;
    int has_match_conc = 0;
    int old_boguscols = 0;

    # define VCOL_HLC (vcol - vcol_off)

    # define FIX_FOR_BOGUSCOLS \
    { \
	n_extra += vcol_off; \
	vcol -= vcol_off; \
	vcol_off = 0; \
	col -= boguscols; \
	old_boguscols = boguscols; \
	boguscols = 0; \
    }
    if (startrow > endrow)
        return startrow;
    row = startrow;
    screen_row = row + W_WINROW (wp);
    extra_check = wp->w_p_lbr;
    if (syntax_present (wp) && !wp->w_s->b_syn_error) {
        save_did_emsg = did_emsg;
        did_emsg = FALSE;
        syntax_start (wp, lnum);
        if (did_emsg)
            wp->w_s->b_syn_error = TRUE;
        else {
            did_emsg = save_did_emsg;
            {
                has_syntax = TRUE;
                extra_check = TRUE;
            }
        }
    }
    color_cols = wp->w_p_cc_cols;
    if (color_cols != NULL)
        draw_color_col = advance_color_col (VCOL_HLC, &color_cols);
    if (term_show_buffer (wp->w_buffer)) {
        extra_check = TRUE;
        get_term_attr = TRUE;
        term_attr = term_get_attr (wp->w_buffer, lnum, -1);
    }
    fromcol = -10;
    tocol = MAXCOL;
    if (VIsual_active && wp->w_buffer == curwin->w_buffer) {
        if (LTOREQ_POS (curwin->w_cursor, VIsual)) {
            top = &curwin->w_cursor;
            bot = &VIsual;
        }
        else {
            top = &VIsual;
            bot = &curwin->w_cursor;
        }
        lnum_in_visual_area = (lnum >= top->lnum && lnum <= bot->lnum);
        if (VIsual_mode == Ctrl_V) {
            if (lnum_in_visual_area) {
                fromcol = wp->w_old_cursor_fcol;
                tocol = wp->w_old_cursor_lcol;
            }
        }
        else {
            if (lnum > top->lnum && lnum <= bot->lnum)
                fromcol = 0;
            else if (lnum == top->lnum) {
                if (VIsual_mode == 'V')
                    fromcol = 0;
                else {
                    getvvcol (wp, top, (colnr_T *) & fromcol, NULL, NULL);
                    if (gchar_pos (top) == NUL)
                        tocol = fromcol + 1;
                }
            }
            if (VIsual_mode != 'V' && lnum == bot->lnum) {
                if (*p_sel == 'e' && bot->col == 0 && bot->coladd == 0) {
                    fromcol = -10;
                    tocol = MAXCOL;
                }
                else if (bot->col == MAXCOL)
                    tocol = MAXCOL;
                else {
                    pos = *bot;
                    if (*p_sel == 'e')
                        getvvcol (wp, &pos, (colnr_T *) &tocol, NULL, NULL);
                    else {
                        getvvcol (wp, & pos, NULL, NULL, (colnr_T *) & tocol);
                        ++tocol;
                    }
                }
            }
        }
        if (!highlight_match && lnum == curwin->w_cursor.lnum && wp == curwin && !gui.in_use)
            noinvcur = TRUE;
        if (fromcol >= 0) {
            area_highlighting = TRUE;
            attr = HL_ATTR (HLF_V);
        }
    }
    else if (highlight_match && wp == curwin && lnum >= curwin->w_cursor.lnum && lnum <= curwin->w_cursor.lnum + search_match_lines) {
        if (lnum == curwin->w_cursor.lnum)
            getvcol (curwin, &(curwin->w_cursor), (colnr_T *) &fromcol, NULL, NULL);
        else
            fromcol = 0;
        if (lnum == curwin->w_cursor.lnum + search_match_lines) {
            pos.lnum = lnum;
            pos.col = search_match_endcol;
            getvcol (curwin, & pos, (colnr_T *) & tocol, NULL, NULL);
        }
        else
            tocol = MAXCOL;
        if (fromcol == tocol)
            tocol = fromcol + 1;
        area_highlighting = TRUE;
        attr = HL_ATTR (HLF_I);
    }
    filler_lines = diff_check (wp, lnum);
    if (filler_lines < 0) {
        if (filler_lines == -1) {
            if (diff_find_change (wp, lnum, &change_start, &change_end))
                diff_hlf = HLF_ADD;
            else if (change_start == 0)
                diff_hlf = HLF_TXD;
            else
                diff_hlf = HLF_CHD;
        }
        else
            diff_hlf = HLF_ADD;
        filler_lines = 0;
        area_highlighting = TRUE;
    }
    if (lnum == wp->w_topline)
        filler_lines = wp->w_topfill;
    filler_todo = filler_lines;
    v = buf_getsigntype (wp->w_buffer, lnum, SIGN_LINEHL);
    if (v != 0)
        line_attr = sign_get_attr ((int) v, TRUE);
    if (bt_quickfix (wp->w_buffer) && qf_current_entry (wp) == lnum)
        line_attr = HL_ATTR (HLF_QFL);
    if (line_attr != 0)
        area_highlighting = TRUE;
    line = ml_get_buf (wp->w_buffer, lnum, FALSE);
    ptr = line;
    if (wp->w_p_list) {
        if (lcs_space || lcs_trail)
            extra_check = TRUE;
        if (lcs_trail) {
            trailcol = (colnr_T) STRLEN (ptr);
            while (trailcol > (colnr_T) 0 && VIM_ISWHITE (ptr[trailcol - 1]))
                --trailcol;
            trailcol += (colnr_T) (ptr - line);
        }
    }
    if (wp->w_p_wrap)
        v = wp->w_skipcol;
    else
        v = wp->w_leftcol;
    if (v > 0) {
        while (vcol < v && *ptr != NUL) {
            c = win_lbr_chartabsize (wp, line, ptr, (colnr_T) vcol, NULL);
            vcol += c;
            MB_PTR_ADV (ptr);
        }
        if (vcol < v && (wp->w_p_cuc || draw_color_col || virtual_active () || (VIsual_active && wp->w_buffer == curwin->w_buffer))) {
            vcol = v;
        }
        if (vcol > v) {
            vcol -= c;
            --ptr;
            if ((*ptr == TAB) && col == 0)
                n_skip = v - vcol;
        }
        if (tocol <= vcol)
            fromcol = 0;
        else if (fromcol >= 0 && fromcol < vcol)
            fromcol = vcol;
        if (wp->w_p_wrap)
            need_showbreak = TRUE;
    }
    if (fromcol >= 0) {
        if (noinvcur) {
            if ((colnr_T) fromcol == wp->w_virtcol) {
                fromcol_prev = fromcol;
                fromcol = -1;
            }
            else if ((colnr_T) fromcol < wp->w_virtcol)
                fromcol_prev = wp->w_virtcol;
        }
        if (fromcol >= tocol)
            fromcol = -1;
    }
    cur = wp->w_match_head;
    shl_flag = FALSE;
    while (cur != NULL || shl_flag == FALSE) {
        if (shl_flag == FALSE) {
            shl = &search_hl;
            shl_flag = TRUE;
        }
        else
            shl = &cur->hl;
        shl->startcol = MAXCOL;
        shl->endcol = MAXCOL;
        shl->attr_cur = 0;
        shl->is_addpos = FALSE;
        v = (long ) (ptr - line);
        if (cur != NULL)
            cur->pos.cur = 0;
        next_search_hl (wp, shl, lnum, (colnr_T) v, shl == & search_hl ? NULL : cur);
        line = ml_get_buf (wp->w_buffer, lnum, FALSE);
        ptr = line + v;
        if (shl->lnum != 0 && shl->lnum <= lnum) {
            if (shl->lnum == lnum)
                shl->startcol = shl->rm.startpos[0].col;
            else
                shl->startcol = 0;
            if (lnum == shl->lnum + shl->rm.endpos[0].lnum - shl->rm.startpos[0].lnum)
                shl->endcol = shl->rm.endpos[0].col;
            else
                shl->endcol = MAXCOL;
            if (shl->startcol == shl->endcol) {
                ++shl->endcol;
            }
            if ((long ) shl->startcol < v) {
                shl->attr_cur = shl->attr;
                search_attr = shl->attr;
            }
            area_highlighting = TRUE;
        }
        if (shl != &search_hl && cur != NULL)
            cur = cur->next;
    }
    if (wp->w_p_cul && lnum == wp->w_cursor.lnum && !(wp == curwin && VIsual_active)) {
        line_attr = HL_ATTR (HLF_CUL);
        area_highlighting = TRUE;
    }
    off = (unsigned ) (current_ScreenLine - ScreenLines);
    col = 0;
    if (wp->w_p_rl) {
        col = wp->w_width - 1;
        off += col;
    }
    for (;;) {
        has_match_conc = 0;
        if (draw_state != WL_LINE) {
            if (draw_state == WL_FOLD - 1 && n_extra == 0) {
                int fdc = compute_foldcolumn (wp, 0);
                draw_state = WL_FOLD;
                if (fdc > 0) {
                    vim_free (p_extra_free);
                    p_extra_free = alloc (12 + 1);
                    if (p_extra_free != NULL) {
                        fill_foldcolumn (p_extra_free, wp, FALSE, lnum);
                        n_extra = fdc;
                        p_extra_free[n_extra] = NUL;
                        p_extra = p_extra_free;
                        c_extra = NUL;
                        char_attr = HL_ATTR (HLF_FC);
                    }
                }
            }
            if (draw_state == WL_SIGN - 1 && n_extra == 0) {
                draw_state = WL_SIGN;
                if (signcolumn_on (wp)) {
                    int text_sign;
                    c_extra = ' ';
                    char_attr = HL_ATTR (HLF_SC);
                    n_extra = 2;
                    if (row == startrow + filler_lines && filler_todo <= 0) {
                        text_sign = buf_getsigntype (wp->w_buffer, lnum, SIGN_TEXT);
                        if (text_sign != 0) {
                            p_extra = sign_get_text (text_sign);
                            if (p_extra != NULL) {
                                c_extra = NUL;
                                n_extra = (int) STRLEN (p_extra);
                            }
                            char_attr = sign_get_attr (text_sign, FALSE);
                        }
                    }
                }
            }
            if (draw_state == WL_NR - 1 && n_extra == 0) {
                draw_state = WL_NR;
                if ((wp->w_p_nu || wp->w_p_rnu) && (row == startrow + filler_lines || vim_strchr (p_cpo, CPO_NUMCOL) == NULL)) {
                    if (row == startrow + filler_lines) {
                        long  num;
                        char *fmt = "%*ld ";
                        if (wp->w_p_nu && !wp->w_p_rnu)
                            num = (long ) lnum;
                        else {
                            num = labs ((long ) get_cursor_rel_lnum (wp, lnum));
                            if (num == 0 && wp->w_p_nu && wp->w_p_rnu) {
                                num = lnum;
                                fmt = "%-*ld ";
                            }
                        }
                        sprintf ((char *) extra, fmt, number_width (wp), num);
                        if (wp->w_skipcol > 0)
                            for (p_extra = extra; *p_extra == ' '; ++p_extra)
                                *p_extra = '-';
                        if (wp->w_p_rl)
                            rl_mirror (extra);
                        p_extra = extra;
                        c_extra = NUL;
                    }
                    else
                        c_extra = ' ';
                    n_extra = number_width (wp) + 1;
                    char_attr = HL_ATTR (HLF_N);
                    if ((wp->w_p_cul || wp->w_p_rnu) && lnum == wp->w_cursor.lnum)
                        char_attr = HL_ATTR (HLF_CLN);
                }
            }
            if (wp->w_p_brisbr && draw_state == WL_BRI - 1 && n_extra == 0 && *p_sbr != NUL)
                draw_state = WL_BRI;
            else if (wp->w_p_brisbr && draw_state == WL_SBR && n_extra == 0)
                draw_state = WL_BRI - 1;
            if (draw_state == WL_BRI - 1 && n_extra == 0) {
                draw_state = WL_BRI;
                if (wp->w_p_bri && n_extra == 0 && (row != startrow || need_showbreak) && filler_lines == 0) {
                    char_attr = 0;
                    if (diff_hlf != (hlf_T) 0) {
                        char_attr = HL_ATTR (diff_hlf);
                        if (wp->w_p_cul && lnum == wp->w_cursor.lnum)
                            char_attr = hl_combine_attr (char_attr, HL_ATTR (HLF_CUL));
                    }
                    p_extra = NULL;
                    c_extra = ' ';
                    n_extra = get_breakindent_win (wp, ml_get_buf (wp->w_buffer, lnum, FALSE));
                    if (tocol == vcol)
                        tocol += n_extra;
                }
            }
            if (draw_state == WL_SBR - 1 && n_extra == 0) {
                draw_state = WL_SBR;
                if (filler_todo > 0) {
                    if (char2cells (fill_diff) > 1)
                        c_extra = '-';
                    else
                        c_extra = fill_diff;
                    if (wp->w_p_rl)
                        n_extra = col + 1;
                    else
                        n_extra = wp->w_width - col;
                    char_attr = HL_ATTR (HLF_DED);
                }
                if (*p_sbr != NUL && need_showbreak) {
                    p_extra = p_sbr;
                    c_extra = NUL;
                    n_extra = (int) STRLEN (p_sbr);
                    char_attr = HL_ATTR (HLF_AT);
                    need_showbreak = FALSE;
                    vcol_sbr = vcol + MB_CHARLEN (p_sbr);
                    if (tocol == vcol)
                        tocol += n_extra;
                    if (wp->w_p_cul && lnum == wp->w_cursor.lnum)
                        char_attr = hl_combine_attr (char_attr, HL_ATTR (HLF_CUL));
                }
            }
            if (draw_state == WL_LINE - 1 && n_extra == 0) {
                draw_state = WL_LINE;
                if (saved_n_extra) {
                    n_extra = saved_n_extra;
                    c_extra = saved_c_extra;
                    p_extra = saved_p_extra;
                    char_attr = saved_char_attr;
                }
                else
                    char_attr = 0;
            }
        }
        if (dollar_vcol >= 0 && wp == curwin && lnum == wp->w_cursor.lnum && vcol >= (long ) wp->w_virtcol && filler_todo <= 0) {
            screen_line (screen_row, wp -> w_wincol, col, - (int) wp -> w_width, HAS_RIGHTLEFT (wp -> w_p_rl));
            if (wp->w_p_cuc)
                row = wp->w_cline_row + wp->w_cline_height;
            else
                row = wp->w_height;
            break;
        }
        if (draw_state == WL_LINE && area_highlighting) {
            if (vcol == fromcol || ((int) vcol_prev == fromcol_prev && vcol_prev < vcol && vcol < tocol))
                area_attr = attr;
            else if (area_attr != 0 && (vcol == tocol || (noinvcur && (colnr_T) vcol == wp->w_virtcol)))
                area_attr = 0;
            if (!n_extra) {
                v = (long ) (ptr - line);
                cur = wp->w_match_head;
                shl_flag = FALSE;
                while (cur != NULL || shl_flag == FALSE) {
                    if (shl_flag == FALSE && ((cur != NULL && cur->priority > SEARCH_HL_PRIORITY) || cur == NULL)) {
                        shl = &search_hl;
                        shl_flag = TRUE;
                    }
                    else
                        shl = &cur->hl;
                    if (cur != NULL)
                        cur->pos.cur = 0;
                    pos_inprogress = TRUE;
                    while (shl->rm.regprog != NULL || (cur != NULL && pos_inprogress)) {
                        if (shl->startcol != MAXCOL && v >= (long ) shl->startcol && v < (long ) shl->endcol) {
                            shl->attr_cur = shl->attr;
                            if (cur != NULL && syn_name2id ((char_u *) "Conceal") == cur->hlg_id) {
                                has_match_conc = v == (long ) shl->startcol ? 2 : 1;
                                match_conc = cur->conceal_char;
                            }
                            else
                                has_match_conc = match_conc = 0;
                        }
                        else if (v == (long ) shl->endcol) {
                            shl->attr_cur = 0;
                            next_search_hl (wp, shl, lnum, (colnr_T) v, shl == & search_hl ? NULL : cur);
                            pos_inprogress = cur == NULL || cur->pos.cur == 0 ? FALSE : TRUE;
                            line = ml_get_buf (wp->w_buffer, lnum, FALSE);
                            ptr = line + v;
                            if (shl->lnum == lnum) {
                                shl->startcol = shl->rm.startpos[0].col;
                                if (shl->rm.endpos[0].lnum == 0)
                                    shl->endcol = shl->rm.endpos[0].col;
                                else
                                    shl->endcol = MAXCOL;
                                if (shl->startcol == shl->endcol) {
                                    ++shl->endcol;
                                }
                                continue;
                            }
                        }
                        break;
                    }
                    if (shl != &search_hl && cur != NULL)
                        cur = cur->next;
                }
                search_attr = search_hl.attr_cur;
                cur = wp->w_match_head;
                shl_flag = FALSE;
                while (cur != NULL || shl_flag == FALSE) {
                    if (shl_flag == FALSE && ((cur != NULL && cur->priority > SEARCH_HL_PRIORITY) || cur == NULL)) {
                        shl = &search_hl;
                        shl_flag = TRUE;
                    }
                    else
                        shl = &cur->hl;
                    if (shl->attr_cur != 0)
                        search_attr = shl->attr_cur;
                    if (shl != &search_hl && cur != NULL)
                        cur = cur->next;
                }
                if (*ptr == NUL && (did_line_attr >= 1 || (wp->w_p_list && lcs_eol_one == -1)))
                    search_attr = 0;
            }
            if (diff_hlf != (hlf_T) 0) {
                if (diff_hlf == HLF_CHD && ptr - line >= change_start && n_extra == 0)
                    diff_hlf = HLF_TXD;
                if (diff_hlf == HLF_TXD && ptr - line > change_end && n_extra == 0)
                    diff_hlf = HLF_CHD;
                line_attr = HL_ATTR (diff_hlf);
                if (wp->w_p_cul && lnum == wp->w_cursor.lnum)
                    line_attr = hl_combine_attr (line_attr, HL_ATTR (HLF_CUL));
            }
            attr_pri = TRUE;
            if (area_attr != 0)
                char_attr = hl_combine_attr (line_attr, area_attr);
            else if (search_attr != 0)
                char_attr = hl_combine_attr (line_attr, search_attr);
            else if (line_attr != 0 && ((fromcol == -10 && tocol == MAXCOL) || vcol < fromcol || vcol_prev < fromcol_prev || vcol >= tocol))
                char_attr = line_attr;
            else {
                attr_pri = FALSE;
                if (has_syntax)
                    char_attr = syntax_attr;
                else
                    char_attr = 0;
            }
        }
        if (n_extra > 0) {
            if (c_extra != NUL) {
                c = c_extra;
            }
            else {
                c = *p_extra;
                ++p_extra;
            }
            --n_extra;
        }
        else {
            int c0;
            if (p_extra_free != NULL)
                VIM_CLEAR (p_extra_free);
            c = *ptr;
            c0 = *ptr;
            ++ptr;
            if (extra_check) {
                if (get_term_attr) {
                    syntax_attr = term_get_attr (wp->w_buffer, lnum, vcol);
                    if (!attr_pri)
                        char_attr = syntax_attr;
                    else
                        char_attr = hl_combine_attr (syntax_attr, char_attr);
                }
                v = (long ) (ptr - line);
                if (has_syntax && v > 0) {
                    save_did_emsg = did_emsg;
                    did_emsg = FALSE;
                    syntax_attr = get_syntax_attr ((colnr_T) v - 1, NULL, FALSE);
                    if (did_emsg) {
                        wp->w_s->b_syn_error = TRUE;
                        has_syntax = FALSE;
                    }
                    else
                        did_emsg = save_did_emsg;
                    line = ml_get_buf (wp->w_buffer, lnum, FALSE);
                    ptr = line + v;
                    if (!attr_pri)
                        char_attr = syntax_attr;
                    else
                        char_attr = hl_combine_attr (syntax_attr, char_attr);
                    if (c == NUL)
                        syntax_flags = 0;
                    else
                        syntax_flags = get_syntax_info (&syntax_seqnr);
                }
                if (wp->w_p_lbr && c0 == c && VIM_ISBREAK (c) && !VIM_ISBREAK ((int) *ptr)) {
                    char_u *p = ptr - (1);
                    n_extra = win_lbr_chartabsize (wp, line, p, (colnr_T) vcol, NULL) - 1;
                    if (c == TAB && n_extra + col > wp->w_width)
                        n_extra = (int) wp->w_buffer->b_p_ts - vcol % (int) wp->w_buffer->b_p_ts - 1;
                    c_extra = ' ';
                    if (VIM_ISWHITE (c)) {
                        if (c == TAB)
                            FIX_FOR_BOGUSCOLS;
                        if (!wp->w_p_list)
                            c = ' ';
                    }
                }
                if (wp->w_p_list && (((c == 160) && lcs_nbsp) || (c == ' ' && lcs_space && ptr - line <= trailcol))) {
                    c = (c == ' ') ? lcs_space : lcs_nbsp;
                    if (area_attr == 0 && search_attr == 0) {
                        n_attr = 1;
                        extra_attr = HL_ATTR (HLF_8);
                        saved_attr2 = char_attr;
                    }
                }
                if (trailcol != MAXCOL && ptr > line + trailcol && c == ' ') {
                    c = lcs_trail;
                    if (!attr_pri) {
                        n_attr = 1;
                        extra_attr = HL_ATTR (HLF_8);
                        saved_attr2 = char_attr;
                    }
                }
            }
            if (!vim_isprintc (c)) {
                if (c == TAB && (!wp->w_p_list || lcs_tab1)) {
                    int tab_len = 0;
                    long  vcol_adjusted = vcol;
                    if (*p_sbr != NUL && vcol == vcol_sbr && wp->w_p_wrap)
                        vcol_adjusted = vcol - MB_CHARLEN (p_sbr);
                    tab_len = (int) wp->w_buffer->b_p_ts - vcol_adjusted % (int) wp->w_buffer->b_p_ts - 1;
                    if (!wp->w_p_lbr || !wp->w_p_list)
                        n_extra = tab_len;
                    else {
                        char_u *p;
                        int len = n_extra;
                        int i;
                        int saved_nextra = n_extra;
                        if (vcol_off > 0)
                            tab_len += vcol_off;
                        if (wp->w_p_list && lcs_tab1 && old_boguscols > 0 && n_extra > tab_len)
                            tab_len += n_extra - tab_len;
                        c = lcs_tab1;
                        p = alloc ((unsigned ) (len + 1));
                        vim_memset (p, ' ', len);
                        p[len] = NUL;
                        vim_free (p_extra_free);
                        p_extra_free = p;
                        for (i = 0; i < tab_len; i++) {
                            p[i] = lcs_tab2;
                        }
                        p_extra = p_extra_free;
                        if (vcol_off > 0)
                            n_extra -= vcol_off;
                    }
                    {
                        int vc_saved = vcol_off;
                        FIX_FOR_BOGUSCOLS;
                        if (n_extra == tab_len + vc_saved && wp->w_p_list && lcs_tab1)
                            tab_len += vc_saved;
                    }
                    if (wp->w_p_list) {
                        c = lcs_tab1;
                        if (wp->w_p_lbr)
                            c_extra = NUL;
                        else
                            c_extra = lcs_tab2;
                        n_attr = tab_len + 1;
                        extra_attr = HL_ATTR (HLF_8);
                        saved_attr2 = char_attr;
                    }
                    else {
                        c_extra = ' ';
                        c = ' ';
                    }
                }
                else if (c == NUL && (wp->w_p_list || ((fromcol >= 0 || fromcol_prev >= 0) && tocol > vcol && VIsual_mode != Ctrl_V && (wp->w_p_rl ? (col >= 0) : (col < wp->w_width)) && !(noinvcur && lnum == wp->w_cursor.lnum && (colnr_T) vcol == wp->w_virtcol))) && lcs_eol_one > 0) {
                    if (diff_hlf == (hlf_T) 0 && line_attr == 0) {
                        if (area_highlighting && virtual_active () && tocol != MAXCOL && vcol < tocol)
                            n_extra = 0;
                        else {
                            p_extra = at_end_str;
                            n_extra = 1;
                            c_extra = NUL;
                        }
                    }
                    if (wp->w_p_list && lcs_eol > 0)
                        c = lcs_eol;
                    else
                        c = ' ';
                    lcs_eol_one = -1;
                    --ptr;
                    if (!attr_pri) {
                        extra_attr = HL_ATTR (HLF_AT);
                        n_attr = 1;
                    }
                }
                else if (c != NUL) {
                    p_extra = transchar (c);
                    if (n_extra == 0)
                        n_extra = byte2cells (c) - 1;
                    if ((dy_flags & DY_UHEX) && wp->w_p_rl)
                        rl_mirror (p_extra);
                    c_extra = NUL;
                    if (wp->w_p_lbr) {
                        char_u *p;
                        c = *p_extra;
                        p = alloc ((unsigned ) n_extra + 1);
                        vim_memset (p, ' ', n_extra);
                        STRNCPY (p, p_extra + 1, STRLEN (p_extra) - 1);
                        p[n_extra] = NUL;
                        vim_free (p_extra_free);
                        p_extra_free = p_extra = p;
                    }
                    else {
                        n_extra = byte2cells (c) - 1;
                        c = *p_extra++;
                    }
                    if (!attr_pri) {
                        n_attr = n_extra + 1;
                        extra_attr = HL_ATTR (HLF_8);
                        saved_attr2 = char_attr;
                    }
                }
                else if (VIsual_active && (VIsual_mode == Ctrl_V || VIsual_mode == 'v') && virtual_active () && tocol != MAXCOL && vcol < tocol && (wp->w_p_rl ? (col >= 0) : (col < wp->w_width))) {
                    c = ' ';
                    --ptr;
                }
                else if ((diff_hlf != (hlf_T) 0 || term_attr != 0 || line_attr != 0) && (wp->w_p_rl ? (col >= 0) : (col - boguscols < wp->w_width))) {
                    c = ' ';
                    --ptr;
                    ++did_line_attr;
                    if (line_attr != 0 && char_attr == search_attr && (did_line_attr > 1 || (wp->w_p_list && lcs_eol > 0)))
                        char_attr = line_attr;
                    if (diff_hlf == HLF_TXD) {
                        diff_hlf = HLF_CHD;
                        if (attr == 0 || char_attr != attr) {
                            char_attr = HL_ATTR (diff_hlf);
                            if (wp->w_p_cul && lnum == wp->w_cursor.lnum)
                                char_attr = hl_combine_attr (char_attr, HL_ATTR (HLF_CUL));
                        }
                    }
                    if (term_attr != 0) {
                        char_attr = term_attr;
                        if (wp->w_p_cul && lnum == wp->w_cursor.lnum)
                            char_attr = hl_combine_attr (char_attr, HL_ATTR (HLF_CUL));
                    }
                }
            }
            if (wp->w_p_cole > 0 && (wp != curwin || lnum != wp->w_cursor.lnum || conceal_cursor_line (wp)) && ((syntax_flags & HL_CONCEAL) != 0 || has_match_conc > 0) && !(lnum_in_visual_area && vim_strchr (wp->w_p_cocu, 'v') == NULL)) {
                char_attr = conceal_attr;
                if ((prev_syntax_id != syntax_seqnr || has_match_conc > 1) && (syn_get_sub_char () != NUL || match_conc || wp->w_p_cole == 1) && wp->w_p_cole != 3) {
                    if (match_conc)
                        c = match_conc;
                    else if (syn_get_sub_char () != NUL)
                        c = syn_get_sub_char ();
                    else if (lcs_conceal != NUL)
                        c = lcs_conceal;
                    else
                        c = ' ';
                    prev_syntax_id = syntax_seqnr;
                    if (n_extra > 0)
                        vcol_off += n_extra;
                    vcol += n_extra;
                    if (wp->w_p_wrap && n_extra > 0) {
                        if (wp->w_p_rl) {
                            col -= n_extra;
                            boguscols -= n_extra;
                        }
                        else {
                            boguscols += n_extra;
                            col += n_extra;
                        }
                    }
                    n_extra = 0;
                    n_attr = 0;
                }
                else if (n_skip == 0) {
                    is_concealing = TRUE;
                    n_skip = 1;
                }
            }
            else {
                prev_syntax_id = 0;
                is_concealing = FALSE;
            }
        }
        if (!did_wcol && draw_state == WL_LINE && wp == curwin && lnum == wp->w_cursor.lnum && conceal_cursor_line (wp) && (int) wp->w_virtcol <= vcol + n_skip) {
            if (wp->w_p_rl)
                wp->w_wcol = wp->w_width - col + boguscols - 1;
            else
                wp->w_wcol = col - boguscols;
            wp->w_wrow = row;
            did_wcol = TRUE;
        }
        if (n_attr > 0 && draw_state == WL_LINE && !attr_pri)
            char_attr = extra_attr;
        if (lcs_prec_todo != NUL && wp->w_p_list && (wp->w_p_wrap ? wp->w_skipcol > 0 : wp->w_leftcol > 0) && filler_todo <= 0 && draw_state > WL_NR && c != NUL) {
            c = lcs_prec;
            lcs_prec_todo = NUL;
            if (!attr_pri) {
                saved_attr3 = char_attr;
                char_attr = HL_ATTR (HLF_AT);
                n_attr3 = 1;
            }
        }
        if (c == NUL || did_line_attr == 1) {
            long  prevcol = (long ) (ptr - line) - (c == NUL);
            if ((long ) (wp->w_p_wrap ? wp->w_skipcol : wp->w_leftcol) > prevcol)
                ++prevcol;
            prevcol_hl_flag = FALSE;
            if (!search_hl.is_addpos && prevcol == (long ) search_hl.startcol)
                prevcol_hl_flag = TRUE;
            else {
                cur = wp->w_match_head;
                while (cur != NULL) {
                    if (!cur->hl.is_addpos && prevcol == (long ) cur->hl.startcol) {
                        prevcol_hl_flag = TRUE;
                        break;
                    }
                    cur = cur->next;
                }
            }
            if (lcs_eol == lcs_eol_one && ((area_attr != 0 && vcol == fromcol && (VIsual_mode != Ctrl_V || lnum == VIsual.lnum || lnum == curwin->w_cursor.lnum) && c == NUL) || (prevcol_hl_flag == TRUE && !(wp->w_p_cul && lnum == wp->w_cursor.lnum && !(wp == curwin && VIsual_active)) && diff_hlf == (hlf_T) 0 && did_line_attr <= 1))) {
                int n = 0;
                if (wp->w_p_rl) {
                    if (col < 0)
                        n = 1;
                }
                else {
                    if (col >= wp->w_width)
                        n = -1;
                }
                if (n != 0) {
                    off += n;
                    col += n;
                }
                else {
                    ScreenLines[off] = ' ';
                }
                if (area_attr == 0) {
                    char_attr = search_hl.attr;
                    cur = wp->w_match_head;
                    shl_flag = FALSE;
                    while (cur != NULL || shl_flag == FALSE) {
                        if (shl_flag == FALSE && ((cur != NULL && cur->priority > SEARCH_HL_PRIORITY) || cur == NULL)) {
                            shl = &search_hl;
                            shl_flag = TRUE;
                        }
                        else
                            shl = &cur->hl;
                        if ((ptr - line) - 1 == (long ) shl->startcol && (shl == &search_hl || !shl->is_addpos))
                            char_attr = shl->attr;
                        if (shl != &search_hl && cur != NULL)
                            cur = cur->next;
                    }
                }
                ScreenAttrs[off] = char_attr;
                if (wp->w_p_rl) {
                    --col;
                    --off;
                }
                else {
                    ++col;
                    ++off;
                }
                ++vcol;
                eol_hl_off = 1;
            }
        }
        if (c == NUL) {
            if (eol_hl_off > 0 && vcol - eol_hl_off == (long ) wp->w_virtcol && lnum == wp->w_cursor.lnum) {
                --col;
                --off;
                --vcol;
            }
            if (wp->w_p_wrap)
                v = wp->w_skipcol;
            else
                v = wp->w_leftcol;
            if (vcol < v + col - win_col_off (wp))
                vcol = v + col - win_col_off (wp);
            col -= boguscols;
            boguscols = 0;
            if (draw_color_col)
                draw_color_col = advance_color_col (VCOL_HLC, &color_cols);
            if (((wp->w_p_cuc && (int) wp->w_virtcol >= VCOL_HLC - eol_hl_off && (int) wp->w_virtcol < wp->w_width * (row - startrow + 1) + v && lnum != wp->w_cursor.lnum) || draw_color_col) && !wp->w_p_rl) {
                int rightmost_vcol = 0;
                int i;
                if (wp->w_p_cuc)
                    rightmost_vcol = wp->w_virtcol;
                if (draw_color_col)
                    for (i = 0; color_cols[i] >= 0; ++i)
                        if (rightmost_vcol < color_cols[i])
                            rightmost_vcol = color_cols[i];
                while (col < wp->w_width) {
                    ScreenLines[off] = ' ';
                    ++col;
                    if (draw_color_col)
                        draw_color_col = advance_color_col (VCOL_HLC, &color_cols);
                    if (wp->w_p_cuc && VCOL_HLC == (long ) wp->w_virtcol)
                        ScreenAttrs[off++] = HL_ATTR (HLF_CUC);
                    else if (draw_color_col && VCOL_HLC == *color_cols)
                        ScreenAttrs[off++] = HL_ATTR (HLF_MC);
                    else
                        ScreenAttrs[off++] = 0;
                    if (VCOL_HLC >= rightmost_vcol)
                        break;
                    ++vcol;
                }
            }
            screen_line (screen_row, wp -> w_wincol, col, (int) wp -> w_width, HAS_RIGHTLEFT (wp -> w_p_rl));
            row++;
            if (wp == curwin && lnum == curwin->w_cursor.lnum) {
                curwin->w_cline_row = startrow;
                curwin->w_cline_height = row - startrow;
                curwin->w_cline_folded = FALSE;
                curwin->w_valid |= (VALID_CHEIGHT | VALID_CROW);
            }
            break;
        }
        if (lcs_ext && !wp->w_p_wrap && filler_todo <= 0 && (wp->w_p_rl ? col == 0 : col == wp->w_width - 1) && (*ptr != NUL || (wp->w_p_list && lcs_eol_one > 0) || (n_extra && (c_extra != NUL || *p_extra != NUL)))) {
            c = lcs_ext;
            char_attr = HL_ATTR (HLF_AT);
        }
        if (draw_color_col)
            draw_color_col = advance_color_col (VCOL_HLC, &color_cols);
        vcol_save_attr = -1;
        if (draw_state == WL_LINE && !lnum_in_visual_area && search_attr == 0 && area_attr == 0) {
            if (wp->w_p_cuc && VCOL_HLC == (long ) wp->w_virtcol && lnum != wp->w_cursor.lnum) {
                vcol_save_attr = char_attr;
                char_attr = hl_combine_attr (char_attr, HL_ATTR (HLF_CUC));
            }
            else if (draw_color_col && VCOL_HLC == *color_cols) {
                vcol_save_attr = char_attr;
                char_attr = hl_combine_attr (char_attr, HL_ATTR (HLF_MC));
            }
        }
        vcol_prev = vcol;
        if (draw_state < WL_LINE || n_skip <= 0) {
            ScreenLines[off] = c;
            ScreenAttrs[off] = char_attr;
            if (wp->w_p_rl) {
                --off;
                --col;
            }
            else {
                ++off;
                ++col;
            }
        }
        else if (wp->w_p_cole > 0 && is_concealing) {
            --n_skip;
            ++vcol_off;
            if (n_extra > 0)
                vcol_off += n_extra;
            if (wp->w_p_wrap) {
                if (n_extra > 0) {
                    vcol += n_extra;
                    if (wp->w_p_rl) {
                        col -= n_extra;
                        boguscols -= n_extra;
                    }
                    else {
                        col += n_extra;
                        boguscols += n_extra;
                    }
                    n_extra = 0;
                    n_attr = 0;
                }
                if (wp->w_p_rl) {
                    --boguscols;
                    --col;
                }
                else {
                    ++boguscols;
                    ++col;
                }
            }
            else {
                if (n_extra > 0) {
                    vcol += n_extra;
                    n_extra = 0;
                    n_attr = 0;
                }
            }
        }
        else
            --n_skip;
        if (draw_state > WL_NR && filler_todo <= 0)
            ++vcol;
        if (vcol_save_attr >= 0)
            char_attr = vcol_save_attr;
        if (draw_state > WL_NR && n_attr3 > 0 && --n_attr3 == 0)
            char_attr = saved_attr3;
        if (n_attr > 0 && draw_state == WL_LINE && --n_attr == 0)
            char_attr = saved_attr2;
        if ((wp->w_p_rl ? (col < 0) : (col >= wp->w_width)) && (*ptr != NUL || filler_todo > 0 || (wp->w_p_list && lcs_eol != NUL && p_extra != at_end_str) || (n_extra != 0 && (c_extra != NUL || *p_extra != NUL)))) {
            screen_line (screen_row, wp -> w_wincol, col - boguscols, (int) wp -> w_width, HAS_RIGHTLEFT (wp -> w_p_rl));
            boguscols = 0;
            ++row;
            ++screen_row;
            if ((!wp->w_p_wrap && filler_todo <= 0) || lcs_eol_one == -1)
                break;
            if (draw_state != WL_LINE && filler_todo <= 0) {
                win_draw_end (wp, '@', ' ', row, wp -> w_height, HLF_AT);
                draw_vsep_win (wp, row);
                row = endrow;
            }
            if (row == endrow) {
                ++row;
                break;
            }
            if (screen_cur_row == screen_row - 1 && filler_todo <= 0 && wp->w_width == Columns) {
                LineWraps[screen_row - 1] = TRUE;
                if (p_tf && !gui.in_use) {
                    if (screen_cur_col != wp->w_width)
                        screen_char (LineOffset[screen_row - 1] + (unsigned ) Columns - 1, screen_row -1, (int) (Columns - 1));
                    out_char (ScreenLines [LineOffset [screen_row - 1] + (Columns - 1)]);
                    ScreenAttrs[LineOffset[screen_row]] = (sattr_T) -1;
                    screen_start ();
                }
            }
            col = 0;
            off = (unsigned ) (current_ScreenLine - ScreenLines);
            if (wp->w_p_rl) {
                col = wp->w_width - 1;
                off += col;
            }
            draw_state = WL_START;
            saved_n_extra = n_extra;
            saved_p_extra = p_extra;
            saved_c_extra = c_extra;
            saved_char_attr = char_attr;
            n_extra = 0;
            lcs_prec_todo = lcs_prec;
            if (filler_todo <= 0)
                need_showbreak = TRUE;
            --filler_todo;
            if (filler_todo == 0 && wp->w_botfill)
                break;
        }
    }
    vim_free (p_extra_free);
    return row;
}

static int advance_color_col (int vcol, int **color_cols) {
    while (**color_cols >= 0 && vcol > **color_cols)
        ++*color_cols;
    return (**color_cols >= 0);
}

void rl_mirror (char_u *str) {
    char_u *p1, *p2;
    int t;
    for (p1 = str, p2 = str + STRLEN (str) - 1; p1 < p2; ++p1, --p2) {
        t = *p1;
        *p1 = *p2;
        *p2 = t;
    }
}

int conceal_cursor_line (win_T *wp) {
    int c;
    if (*wp->w_p_cocu == NUL)
        return FALSE;
    if (get_real_state () & VISUAL)
        c = 'v';
    else if (State & INSERT)
        c = 'i';
    else if (State & NORMAL)
        c = 'n';
    else if (State & CMDLINE)
        c = 'c';
    else
        return FALSE;
    return vim_strchr (wp->w_p_cocu, c) != NULL;
}

static void win_draw_end (win_T *wp, int c1, int c2, int row, int endrow, hlf_T hl) {
    int n = 0;

    # define FDC_OFF n
    int fdc = compute_foldcolumn (wp, 0);
    if (wp->w_p_rl) {
        n = fdc;
        if (n > 0) {
            if (n > wp->w_width)
                n = wp->w_width;
            screen_fill (W_WINROW (wp) + row, W_WINROW (wp) + endrow, W_ENDCOL (wp) - n, (int) W_ENDCOL (wp), ' ', ' ', HL_ATTR (HLF_FC));
        }
        if (signcolumn_on (wp)) {
            int nn = n + 2;
            if (nn > wp->w_width)
                nn = wp->w_width;
            screen_fill (W_WINROW (wp) + row, W_WINROW (wp) + endrow, W_ENDCOL (wp) - nn, (int) W_ENDCOL (wp) - n, ' ', ' ', HL_ATTR (HLF_SC));
            n = nn;
        }
        screen_fill (W_WINROW (wp) + row, W_WINROW (wp) + endrow, wp -> w_wincol, W_ENDCOL (wp) - 1 - FDC_OFF, c2, c2, HL_ATTR (hl));
        screen_fill (W_WINROW (wp) + row, W_WINROW (wp) + endrow, W_ENDCOL (wp) - 1 - FDC_OFF, W_ENDCOL (wp) - FDC_OFF, c1, c2, HL_ATTR (hl));
    }
    else {
        if (fdc > 0) {
            int nn = n + fdc;
            if (nn > wp->w_width)
                nn = wp->w_width;
            screen_fill (W_WINROW (wp) + row, W_WINROW (wp) + endrow, wp -> w_wincol + n, (int) wp -> w_wincol + nn, ' ', ' ', HL_ATTR (HLF_FC));
            n = nn;
        }
        if (signcolumn_on (wp)) {
            int nn = n + 2;
            if (nn > wp->w_width)
                nn = wp->w_width;
            screen_fill (W_WINROW (wp) + row, W_WINROW (wp) + endrow, wp -> w_wincol + n, (int) wp -> w_wincol + nn, ' ', ' ', HL_ATTR (HLF_SC));
            n = nn;
        }
        screen_fill (W_WINROW (wp) + row, W_WINROW (wp) + endrow, wp -> w_wincol + FDC_OFF, (int) W_ENDCOL (wp), c1, c2, HL_ATTR (hl));
    }
    set_empty_rows (wp, row);
}

void win_redr_status (win_T *wp) {
    int row;
    char_u *p;
    int len;
    int fillchar;
    int attr;
    int this_ru_col;
    static int busy = FALSE;
    if (busy)
        return;
    busy = TRUE;
    wp->w_redr_status = FALSE;
    if (wp->w_status_height == 0) {
        redraw_cmdline = TRUE;
    }
    else if (!redrawing () || pum_visible ()) {
        wp->w_redr_status = TRUE;
    }
    else if (*p_stl != NUL || *wp->w_p_stl != NUL) {
        redraw_custom_statusline (wp);
    }
    else {
        fillchar = fillchar_status (&attr, wp);
        get_trans_bufname (wp -> w_buffer);
        p = NameBuff;
        len = (int) STRLEN (p);
        if (bt_help (wp->w_buffer) || wp->w_p_pvw || bufIsChanged (wp->w_buffer) || wp->w_buffer->b_p_ro)
            *(p + len++) = ' ';
        if (bt_help (wp->w_buffer)) {
            STRCPY (p + len, _ ("[Help]"));
            len += (int) STRLEN (p +len);
        }
        if (wp->w_p_pvw) {
            STRCPY (p + len, _ ("[Preview]"));
            len += (int) STRLEN (p +len);
        }
        if (bufIsChanged (wp->w_buffer) && !bt_terminal (wp->w_buffer)) {
            STRCPY (p + len, "[+]");
            len += 3;
        }
        if (wp->w_buffer->b_p_ro) {
            STRCPY (p + len, _ ("[RO]"));
            len += (int) STRLEN (p +len);
        }
        this_ru_col = ru_col - (Columns - wp->w_width);
        if (this_ru_col < (wp->w_width + 1) / 2)
            this_ru_col = (wp->w_width + 1) / 2;
        if (this_ru_col <= 1) {
            p = (char_u *) "<";
            len = 1;
        }
        else if (len > this_ru_col - 1) {
            p += len - (this_ru_col - 1);
            *p = '<';
            len = this_ru_col - 1;
        }
        row = W_WINROW (wp) + wp->w_height;
        screen_puts (p, row, wp -> w_wincol, attr);
        screen_fill (row, row + 1, len + wp -> w_wincol, this_ru_col + wp -> w_wincol, fillchar, fillchar, attr);
        if (get_keymap_str (wp, (char_u *) "<%s>", NameBuff, MAXPATHL) && (int) (this_ru_col - len) > (int) (STRLEN (NameBuff) + 1))
            screen_puts (NameBuff, row, (int) (this_ru_col - STRLEN (NameBuff) - 1 + wp->w_wincol), attr);
        win_redr_ruler (wp, TRUE);
    }
    if (wp->w_vsep_width != 0 && wp->w_status_height != 0 && redrawing ()) {
        if (stl_connected (wp))
            fillchar = fillchar_status (&attr, wp);
        else
            fillchar = fillchar_vsep (&attr);
        screen_putchar (fillchar, W_WINROW (wp) + wp -> w_height, W_ENDCOL (wp), attr);
    }
    busy = FALSE;
}

static void redraw_custom_statusline (win_T *wp) {
    static int entered = FALSE;
    int saved_did_emsg = did_emsg;
    if (entered)
        return;
    entered = TRUE;
    did_emsg = FALSE;
    win_redr_custom (wp, FALSE);
    if (did_emsg) {
        set_string_option_direct ((char_u *) "statusline", - 1, (char_u *) "", OPT_FREE | (* wp -> w_p_stl != NUL ? OPT_LOCAL : OPT_GLOBAL), SID_ERROR);
    }
    did_emsg |= saved_did_emsg;
    entered = FALSE;
}

static void win_redr_ruler (win_T *wp, int always) {

    #define RULER_BUF_LEN 70
    char_u buffer [RULER_BUF_LEN];
    int row;
    int fillchar;
    int attr;
    int empty_line = FALSE;
    colnr_T virtcol;
    int i;
    size_t len;
    int o;
    int this_ru_col;
    int off = 0;
    int width = Columns;
    if (!p_ru)
        return;
    if (wp->w_cursor.lnum > wp->w_buffer->b_ml.ml_line_count)
        return;
    if (wp == lastwin && lastwin->w_status_height == 0)
        if (edit_submode != NULL)
            return;
    if (pum_visible ())
        return;
    if (*p_ruf) {
        int save_called_emsg = called_emsg;
        called_emsg = FALSE;
        win_redr_custom (wp, TRUE);
        if (called_emsg)
            set_string_option_direct ((char_u *) "rulerformat", -1, (char_u *) "", OPT_FREE, SID_ERROR);
        called_emsg |= save_called_emsg;
        return;
    }
    if (!(State & INSERT) && *ml_get_buf (wp->w_buffer, wp->w_cursor.lnum, FALSE) == NUL)
        empty_line = TRUE;
    validate_virtcol_win (wp);
    if (redraw_cmdline || always || wp->w_cursor.lnum != wp->w_ru_cursor.lnum || wp->w_cursor.col != wp->w_ru_cursor.col || wp->w_virtcol != wp->w_ru_virtcol || wp->w_cursor.coladd != wp->w_ru_cursor.coladd || wp->w_topline != wp->w_ru_topline || wp->w_buffer->b_ml.ml_line_count != wp->w_ru_line_count || wp->w_topfill != wp->w_ru_topfill || empty_line != wp->w_ru_empty) {
        cursor_off ();
        if (wp->w_status_height) {
            row = W_WINROW (wp) + wp->w_height;
            fillchar = fillchar_status (&attr, wp);
            off = wp->w_wincol;
            width = wp->w_width;
        }
        else {
            row = Rows - 1;
            fillchar = ' ';
            attr = 0;
            width = Columns;
            off = 0;
        }
        virtcol = wp->w_virtcol;
        if (wp->w_p_list && lcs_tab1 == NUL) {
            wp->w_p_list = FALSE;
            getvvcol (wp, & wp -> w_cursor, NULL, & virtcol, NULL);
            wp->w_p_list = TRUE;
        }
        vim_snprintf ((char *) buffer, RULER_BUF_LEN, "%ld,", (wp -> w_buffer -> b_ml.ml_flags & ML_EMPTY) ? 0L : (long) (wp -> w_cursor.lnum));
        len = STRLEN (buffer);
        col_print (buffer + len, RULER_BUF_LEN - len, empty_line ? 0 : (int) wp -> w_cursor.col + 1, (int) virtcol + 1);
        i = (int) STRLEN (buffer);
        get_rel_pos (wp, buffer + i + 1, RULER_BUF_LEN - i - 1);
        o = i + vim_strsize (buffer +i + 1);
        if (wp->w_status_height == 0)
            ++o;
        this_ru_col = ru_col - (Columns - width);
        if (this_ru_col < 0)
            this_ru_col = 0;
        if (this_ru_col < (width + 1) / 2)
            this_ru_col = (width + 1) / 2;
        if (this_ru_col + o < width) {
            while (this_ru_col + o < width && RULER_BUF_LEN > i + 4) {
                buffer[i++] = fillchar;
                ++o;
            }
            get_rel_pos (wp, buffer + i, RULER_BUF_LEN - i);
        }
        if (this_ru_col + (int) STRLEN (buffer) > width)
            buffer[width - this_ru_col] = NUL;
        screen_puts (buffer, row, this_ru_col + off, attr);
        i = redraw_cmdline;
        screen_fill (row, row + 1, this_ru_col + off + (int) STRLEN (buffer), (int) (off + width), fillchar, fillchar, attr);
        redraw_cmdline = i;
        wp->w_ru_cursor = wp->w_cursor;
        wp->w_ru_virtcol = wp->w_virtcol;
        wp->w_ru_empty = empty_line;
        wp->w_ru_topline = wp->w_topline;
        wp->w_ru_line_count = wp->w_buffer->b_ml.ml_line_count;
        wp->w_ru_topfill = wp->w_topfill;
    }
}

int stl_connected (win_T *wp) {
    frame_T *fr;
    fr = wp->w_frame;
    while (fr->fr_parent != NULL) {
        if (fr->fr_parent->fr_layout == FR_COL) {
            if (fr->fr_next != NULL)
                break;
        }
        else {
            if (fr->fr_next != NULL)
                return TRUE;
        }
        fr = fr->fr_parent;
    }
    return FALSE;
}

static void end_search_hl (void) {
    if (search_hl.rm.regprog != NULL) {
        vim_regfree (search_hl.rm.regprog);
        search_hl.rm.regprog = NULL;
    }
}

int showmode (void) {
    int need_clear;
    int length = 0;
    int do_mode;
    int attr;
    int nwr_save;
    int sub_attr;
    do_mode = ((p_smd && msg_silent == 0) && ((State & INSERT) || restart_edit || VIsual_active));
    if (do_mode || Recording) {
        if (!redrawing () || (char_avail () && !KeyTyped) || msg_silent != 0) {
            redraw_cmdline = TRUE;
            return 0;
        }
        nwr_save = need_wait_return;
        check_for_delay (FALSE);
        need_clear = clear_cmdline;
        if (clear_cmdline && cmdline_row < Rows - 1)
            msg_clr_cmdline ();
        msg_pos_mode ();
        cursor_off ();
        attr = HL_ATTR (HLF_CM);
        if (do_mode) {
            MSG_PUTS_ATTR ("--", attr);
            if (edit_submode != NULL && !shortmess (SHM_COMPLETIONMENU)) {
                length = (Rows - msg_row) * Columns - 3;
                if (edit_submode_extra != NULL)
                    length -= vim_strsize (edit_submode_extra);
                if (length > 0) {
                    if (edit_submode_pre != NULL)
                        length -= vim_strsize (edit_submode_pre);
                    if (length - vim_strsize (edit_submode) > 0) {
                        if (edit_submode_pre != NULL)
                            msg_puts_attr (edit_submode_pre, attr);
                        msg_puts_attr (edit_submode, attr);
                    }
                    if (edit_submode_extra != NULL) {
                        MSG_PUTS_ATTR (" ", attr);
                        if ((int) edit_submode_highl < (int) HLF_COUNT)
                            sub_attr = HL_ATTR (edit_submode_highl);
                        else
                            sub_attr = attr;
                        msg_puts_attr (edit_submode_extra, sub_attr);
                    }
                }
                length = 0;
            }
            else {
                if (State & VREPLACE_FLAG)
                    MSG_PUTS_ATTR (_ (" VREPLACE"), attr);
                else if (State & REPLACE_FLAG)
                    MSG_PUTS_ATTR (_ (" REPLACE"), attr);
                else if (State & INSERT) {
                    if (p_ri)
                        MSG_PUTS_ATTR (_ (" REVERSE"), attr);
                    MSG_PUTS_ATTR (_ (" INSERT"), attr);
                }
                else if (restart_edit == 'I')
                    MSG_PUTS_ATTR (_ (" (insert)"), attr);
                else if (restart_edit == 'R')
                    MSG_PUTS_ATTR (_ (" (replace)"), attr);
                else if (restart_edit == 'V')
                    MSG_PUTS_ATTR (_ (" (vreplace)"), attr);
                if (p_hkmap)
                    MSG_PUTS_ATTR (_ (" Hebrew"), attr);
                if (p_fkmap)
                    MSG_PUTS_ATTR (farsi_text_5, attr);
                if (State & LANGMAP) {
                    if (curwin->w_p_arab)
                        MSG_PUTS_ATTR (_ (" Arabic"), attr);
                    else if (get_keymap_str (curwin, (char_u *) " (%s)", NameBuff, MAXPATHL))
                        MSG_PUTS_ATTR (NameBuff, attr);
                }
                if ((State & INSERT) && p_paste)
                    MSG_PUTS_ATTR (_ (" (paste)"), attr);
                if (VIsual_active) {
                    char *p;
                    switch ((VIsual_select ? 4 : 0) + (VIsual_mode == Ctrl_V) * 2 + (VIsual_mode == 'V')) {
                    case 0 :
                        p = N_ (" VISUAL");
                        break;
                    case 1 :
                        p = N_ (" VISUAL LINE");
                        break;
                    case 2 :
                        p = N_ (" VISUAL BLOCK");
                        break;
                    case 4 :
                        p = N_ (" SELECT");
                        break;
                    case 5 :
                        p = N_ (" SELECT LINE");
                        break;
                    default :
                        p = N_ (" SELECT BLOCK");
                        break;
                    }
                    MSG_PUTS_ATTR (_ (p), attr);
                }
                MSG_PUTS_ATTR (" --", attr);
            }
            need_clear = TRUE;
        }
        if (Recording && edit_submode == NULL) {
            recording_mode (attr);
            need_clear = TRUE;
        }
        mode_displayed = TRUE;
        if (need_clear || clear_cmdline)
            msg_clr_eos ();
        msg_didout = FALSE;
        length = msg_col;
        msg_col = 0;
        need_wait_return = nwr_save;
    }
    else if (clear_cmdline && msg_silent == 0)
        msg_clr_cmdline ();
    if (VIsual_active)
        clear_showcmd ();
    if (redrawing () && lastwin->w_status_height == 0)
        win_redr_ruler (lastwin, TRUE);
    redraw_cmdline = FALSE;
    clear_cmdline = FALSE;
    return length;
}

static void msg_pos_mode (void) {
    msg_col = 0;
    msg_row = Rows - 1;
}

void redraw_buf_later (buf_T *buf, int type) {
    win_T *wp;
    FOR_ALL_WINDOWS (wp) {
        if (wp->w_buffer == buf)
            redraw_win_later (wp, type);
    }
}

void status_redraw_all (void) {
    win_T *wp;
    FOR_ALL_WINDOWS (wp)
        if (wp->w_status_height) {
            wp->w_redr_status = TRUE;
            redraw_later (VALID);
        }
}

void reset_cterm_colors (void) {
    if (IS_CTERM) {
        if (p_tgc ? (cterm_normal_fg_gui_color != INVALCOLOR || cterm_normal_bg_gui_color != INVALCOLOR) : (cterm_normal_fg_color > 0 || cterm_normal_bg_color > 0)) {
            out_str (T_OP);
            screen_attr = -1;
        }
        if (cterm_normal_fg_bold) {
            out_str (T_ME);
            screen_attr = -1;
        }
    }
}

void update_debug_sign (buf_T *buf, linenr_T lnum) {
    win_T *wp;
    int doit = FALSE;
    win_foldinfo.fi_level = 0;
    FOR_ALL_WINDOWS (wp) {
        if (buf != NULL && lnum > 0) {
            if (wp->w_buffer == buf && lnum >= wp->w_topline && lnum < wp->w_botline) {
                if (wp->w_redraw_top == 0 || wp->w_redraw_top > lnum)
                    wp->w_redraw_top = lnum;
                if (wp->w_redraw_bot == 0 || wp->w_redraw_bot < lnum)
                    wp->w_redraw_bot = lnum;
                redraw_win_later (wp, VALID);
            }
        }
        else
            redraw_win_later (wp, VALID);
        if (wp->w_redr_type != 0)
            doit = TRUE;
    }
    if (!doit || updating_screen || State == ASKMORE || State == HITRETURN || msg_scrolled || gui.starting || starting)
        return;
    update_prepare ();
    FOR_ALL_WINDOWS (wp) {
        if (wp->w_redr_type != 0)
            win_update (wp);
        if (wp->w_redr_status)
            win_redr_status (wp);
    }
    update_finish ();
}

static void update_prepare (void) {
    cursor_off ();
    updating_screen = TRUE;
    if (gui.in_use)
        gui_undraw_cursor ();
    start_search_hl ();
}

static void update_finish (void) {
    if (redraw_cmdline)
        showmode ();
    end_search_hl ();
    updating_screen = FALSE;
    gui_may_resize_shell ();
    if (gui.in_use) {
        out_flush_cursor (FALSE, FALSE);
        gui_update_scrollbars (FALSE);
    }
}

void redraw_later_clear (void) {
    redraw_all_later (CLEAR);
    if (gui.in_use)
        screen_attr = HL_ALL + 1;
    else
        screen_attr = HL_BOLD | HL_UNDERLINE | HL_INVERSE | HL_STRIKETHROUGH;
}

void status_redraw_curbuf (void) {
    win_T *wp;
    FOR_ALL_WINDOWS (wp)
        if (wp->w_status_height != 0 && wp->w_buffer == curbuf) {
            wp->w_redr_status = TRUE;
            redraw_later (VALID);
        }
}

void redraw_curbuf_later (int type) {
    redraw_buf_later (curbuf, type);
}

int redraw_asap (int type) {
    int rows;
    int cols = screen_Columns;
    int r;
    int ret = 0;
    schar_T *screenline;
    sattr_T *screenattr;
    redraw_later (type);
    if (msg_scrolled || (State != NORMAL && State != NORMAL_BUSY) || exiting)
        return ret;
    rows = screen_Rows - cmdline_row;
    screenline = (schar_T *) lalloc ((long_u) (rows * cols * sizeof (schar_T)), FALSE);
    screenattr = (sattr_T *) lalloc ((long_u) (rows * cols * sizeof (sattr_T)), FALSE);
    if (screenline == NULL || screenattr == NULL)
        ret = 2;
    if (ret != 2) {
        for (r = 0; r < rows; ++r) {
            mch_memmove (screenline + r * cols, ScreenLines + LineOffset [cmdline_row + r], (size_t) cols * sizeof (schar_T));
            mch_memmove (screenattr + r * cols, ScreenAttrs + LineOffset [cmdline_row + r], (size_t) cols * sizeof (sattr_T));
        }
        update_screen (0);
        ret = 3;
        if (must_redraw == 0) {
            int off = (int) (current_ScreenLine - ScreenLines);
            for (r = 0; r < rows; ++r) {
                mch_memmove (current_ScreenLine, screenline + r * cols, (size_t) cols * sizeof (schar_T));
                mch_memmove (ScreenAttrs + off, screenattr + r * cols, (size_t) cols * sizeof (sattr_T));
                screen_line (cmdline_row + r, 0, cols, cols, FALSE);
            }
            ret = 4;
        }
    }
    vim_free (screenline);
    vim_free (screenattr);
    maybe_intro_message ();
    setcursor ();
    return ret;
}

void conceal_check_cursur_line (void) {
    if (curwin->w_p_cole > 0 && conceal_cursor_line (curwin)) {
        need_cursor_line_redraw = TRUE;
        curs_columns (TRUE);
    }
}

void win_redraw_last_status (frame_T *frp) {
    if (frp->fr_layout == FR_LEAF)
        frp->fr_win->w_redr_status = TRUE;
    else if (frp->fr_layout == FR_ROW) {
        for (frp = frp->fr_child; frp != NULL; frp = frp->fr_next)
            win_redraw_last_status (frp);
    }
    else {
        frp = frp->fr_child;
        while (frp->fr_next != NULL)
            frp = frp->fr_next;
        win_redraw_last_status (frp);
    }
}

void redraw_statuslines (void) {
    win_T *wp;
    FOR_ALL_WINDOWS (wp)
        if (wp->w_redr_status)
            win_redr_status (wp);
    if (redraw_tabline)
        draw_tabline ();
}

void update_single_line (win_T *wp, linenr_T lnum) {
    int row;
    int j;
    if (!screen_valid (TRUE) || updating_screen)
        return;
    if (lnum >= wp->w_topline && lnum < wp->w_botline && foldedCount (wp, lnum, &win_foldinfo) == 0) {
        update_prepare ();
        row = 0;
        for (j = 0; j < wp->w_lines_valid; ++j) {
            if (lnum == wp->w_lines[j].wl_lnum) {
                screen_start ();
                init_search_hl (wp);
                start_search_hl ();
                prepare_search_hl (wp, lnum);
                win_line (wp, lnum, row, row + wp -> w_lines [j].wl_size, FALSE);
                end_search_hl ();
                break;
            }
            row += wp->w_lines[j].wl_size;
        }
        update_finish ();
    }
    need_cursor_line_redraw = FALSE;
}

void update_curbuf (int type) {
    redraw_curbuf_later (type);
    update_screen (type);
}

void showruler (int always) {
    if (!always && !redrawing ())
        return;
    if (pum_visible ()) {
        curwin->w_redr_status = TRUE;
        return;
    }
    if ((*p_stl != NUL || *curwin->w_p_stl != NUL) && curwin->w_status_height) {
        redraw_custom_statusline (curwin);
    }
    else
        win_redr_ruler (curwin, always);
    if (need_maketitle || (p_icon && (stl_syntax & STL_IN_ICON)) || (p_title && (stl_syntax & STL_IN_TITLE)))
        maketitle ();
    if (redraw_tabline)
        draw_tabline ();
}

void redrawWinline (linenr_T lnum, int invalid) {
    int i;
    if (curwin->w_redraw_top == 0 || curwin->w_redraw_top > lnum)
        curwin->w_redraw_top = lnum;
    if (curwin->w_redraw_bot == 0 || curwin->w_redraw_bot < lnum)
        curwin->w_redraw_bot = lnum;
    redraw_later (VALID);
    if (invalid) {
        i = find_wl_entry (curwin, lnum);
        if (i >= 0)
            curwin->w_lines[i].wl_valid = FALSE;
    }
}

void screen_getbytes (int row, int col, char_u *bytes, int *attrp) {
    unsigned  off;
    if (ScreenLines != NULL && row < screen_Rows && col < screen_Columns) {
        off = LineOffset[row] + col;
        *attrp = ScreenAttrs[off];
        bytes[0] = ScreenLines[off];
        bytes[1] = NUL;
    }
}

int messaging (void) {
    return (!(p_lz && char_avail () && !KeyTyped));
}

void unshowmode (int force) {
    if (!redrawing () || (!force && char_avail () && !KeyTyped))
        redraw_cmdline = TRUE;
    else
        clearmode ();
}

static void screen_start_highlight (int attr) {
    attrentry_T *aep = NULL;
    screen_attr = attr;
    if (full_screen) {
        if (gui.in_use) {
            char buf [20];
            sprintf (buf, IF_EB ("\033|%dh", ESC_STR "|%dh"), attr);
            OUT_STR (buf);
        }
        else {
            if (attr > HL_ALL) {
                if (IS_CTERM)
                    aep = syn_cterm_attr2entry (attr);
                else
                    aep = syn_term_attr2entry (attr);
                if (aep == NULL)
                    attr = 0;
                else
                    attr = aep->ae_attr;
            }
            if ((attr & HL_BOLD) && *T_MD != NUL)
                out_str (T_MD);
            else if (aep != NULL && cterm_normal_fg_bold && (p_tgc ? (aep->ae_u.cterm.fg_rgb != INVALCOLOR) : (t_colors > 1 && aep->ae_u.cterm.fg_color)))
                out_str (T_ME);
            if ((attr & HL_STANDOUT) && *T_SO != NUL)
                out_str (T_SO);
            if ((attr & HL_UNDERCURL) && *T_UCS != NUL)
                out_str (T_UCS);
            if (((attr & HL_UNDERLINE) || ((attr & HL_UNDERCURL) && *T_UCS == NUL)) && *T_US != NUL)
                out_str (T_US);
            if ((attr & HL_ITALIC) && *T_CZH != NUL)
                out_str (T_CZH);
            if ((attr & HL_INVERSE) && *T_MR != NUL)
                out_str (T_MR);
            if ((attr & HL_STRIKETHROUGH) && *T_STS != NUL)
                out_str (T_STS);
            if (aep != NULL) {
                if (p_tgc) {
                    if (aep->ae_u.cterm.fg_rgb != INVALCOLOR)
                        term_fg_rgb_color (aep->ae_u.cterm.fg_rgb);
                    if (aep->ae_u.cterm.bg_rgb != INVALCOLOR)
                        term_bg_rgb_color (aep->ae_u.cterm.bg_rgb);
                }
                else {
                    if (t_colors > 1) {
                        if (aep->ae_u.cterm.fg_color)
                            term_fg_color (aep->ae_u.cterm.fg_color - 1);
                        if (aep->ae_u.cterm.bg_color)
                            term_bg_color (aep->ae_u.cterm.bg_color - 1);
                    }
                    else {
                        if (aep->ae_u.term.start != NULL)
                            out_str (aep->ae_u.term.start);
                    }
                }
            }
        }
    }
}

void free_screenlines (void) {
    vim_free (ScreenLines);
    vim_free (ScreenAttrs);
    vim_free (LineOffset);
    vim_free (LineWraps);
    vim_free (TabPageIdxs);
}

void updateWindow (win_T *wp) {
    if (updating_screen)
        return;
    update_prepare ();
    win_update (wp);
    if (redraw_tabline)
        draw_tabline ();
    if (wp->w_redr_status || p_ru || *p_stl != NUL || *wp->w_p_stl != NUL)
        win_redr_status (wp);
    update_finish ();
}

