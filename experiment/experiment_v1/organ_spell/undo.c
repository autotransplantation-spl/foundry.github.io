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
EXTERN char_u e_modifiable [] INIT (= N_ ("E21: Cannot make changes, 'modifiable' is off"));
EXTERN char_u e_nbreadonly [] INIT (= N_ ("E744: NetBeans does not allow changes in read-only files"));
EXTERN char_u e_guarded [] INIT (= N_ ("E463: Region is guarded, cannot modify"));
int undo_undoes = FALSE;
char_u e_not_open [] = N_ ("E828: Cannot open undo file for writing: %s");
EXTERN char_u *p_udir;
EXTERN long  p_verbose;
EXTERN long  p_ul;
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
int lastmark = 0;
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
long  u_oldcount;
long  u_newcount;
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
EXTERN int p_hls;
EXTERN long  p_hi;
EXTERN long  p_ls;
EXTERN int p_lrm;
EXTERN int p_js;
EXTERN char bot_top_msg [] INIT (= N_ ("search hit BOTTOM, continuing at TOP"));

int curbufIsChanged (void) {
    return bufIsChanged (curbuf);
}

int bufIsChanged (buf_T *buf) {
    if (term_job_running (buf->b_term))
        return TRUE;
    return bufIsChangedNotTerm (buf);
}

void u_blockfree (buf_T *buf) {
    while (buf->b_u_oldhead != NULL)
        u_freeheader (buf, buf->b_u_oldhead, NULL);
    vim_free (buf -> b_u_line_ptr);
}

static void u_freeheader (buf_T *buf, u_header_T *uhp, u_header_T **uhpp) {
    u_header_T *uhap;
    if (uhp->uh_alt_next.ptr != NULL)
        u_freebranch (buf, uhp->uh_alt_next.ptr, uhpp);
    if (uhp->uh_alt_prev.ptr != NULL)
        uhp->uh_alt_prev.ptr->uh_alt_next.ptr = NULL;
    if (uhp->uh_next.ptr == NULL)
        buf->b_u_oldhead = uhp->uh_prev.ptr;
    else
        uhp->uh_next.ptr->uh_prev.ptr = uhp->uh_prev.ptr;
    if (uhp->uh_prev.ptr == NULL)
        buf->b_u_newhead = uhp->uh_next.ptr;
    else
        for (uhap = uhp->uh_prev.ptr; uhap != NULL; uhap = uhap->uh_alt_next.ptr)
            uhap->uh_next.ptr = uhp->uh_next.ptr;
    u_freeentries (buf, uhp, uhpp);
}

static void u_freebranch (buf_T *buf, u_header_T *uhp, u_header_T **uhpp) {
    u_header_T *tofree, *next;
    if (uhp == buf->b_u_oldhead) {
        while (buf->b_u_oldhead != NULL)
            u_freeheader (buf, buf->b_u_oldhead, uhpp);
        return;
    }
    if (uhp->uh_alt_prev.ptr != NULL)
        uhp->uh_alt_prev.ptr->uh_alt_next.ptr = NULL;
    next = uhp;
    while (next != NULL) {
        tofree = next;
        if (tofree->uh_alt_next.ptr != NULL)
            u_freebranch (buf, tofree->uh_alt_next.ptr, uhpp);
        next = tofree->uh_prev.ptr;
        u_freeentries (buf, tofree, uhpp);
    }
}

static void u_freeentries (buf_T *buf, u_header_T *uhp, u_header_T **uhpp) {
    u_entry_T *uep, *nuep;
    if (buf->b_u_curhead == uhp)
        buf->b_u_curhead = NULL;
    if (buf->b_u_newhead == uhp)
        buf->b_u_newhead = NULL;
    if (uhpp != NULL && uhp == *uhpp)
        *uhpp = NULL;
    for (uep = uhp->uh_entry; uep != NULL; uep = nuep) {
        nuep = uep->ue_next;
        u_freeentry (uep, uep -> ue_size);
    }
    vim_free ((char_u *) uhp);
    --buf->b_u_numhead;
}

static void u_freeentry (u_entry_T *uep, long  n) {
    while (n > 0)
        vim_free (uep->ue_array[--n]);
    vim_free ((char_u *) uep -> ue_array);
    vim_free ((char_u *) uep);
}

void u_clearall (buf_T *buf) {
    buf->b_u_newhead = buf->b_u_oldhead = buf->b_u_curhead = NULL;
    buf->b_u_synced = TRUE;
    buf->b_u_numhead = 0;
    buf->b_u_line_ptr = NULL;
    buf->b_u_line_lnum = 0;
}

void u_sync (int force) {
    if (curbuf->b_u_synced || (!force && no_u_sync > 0))
        return;
    if (get_undolevel () < 0)
        curbuf->b_u_synced = TRUE;
    else {
        u_getbot ();
        curbuf->b_u_curhead = NULL;
    }
}

static long  get_undolevel (void) {
    if (curbuf->b_p_ul == NO_LOCAL_UNDOLEVEL)
        return p_ul;
    return curbuf->b_p_ul;
}

static void u_getbot (void) {
    u_entry_T *uep;
    linenr_T extra;
    uep = u_get_headentry ();
    if (uep == NULL)
        return;
    uep = curbuf->b_u_newhead->uh_getbot_entry;
    if (uep != NULL) {
        extra = curbuf->b_ml.ml_line_count - uep->ue_lcount;
        uep->ue_bot = uep->ue_top + uep->ue_size + 1 + extra;
        if (uep->ue_bot < 1 || uep->ue_bot > curbuf->b_ml.ml_line_count) {
            IEMSG (_ ("E440: undo line missing"));
            uep->ue_bot = uep->ue_top + 1;
        }
        curbuf->b_u_newhead->uh_getbot_entry = NULL;
    }
    curbuf->b_u_synced = TRUE;
}

static u_entry_T *u_get_headentry (void) {
    if (curbuf->b_u_newhead == NULL || curbuf->b_u_newhead->uh_entry == NULL) {
        IEMSG (_ ("E439: undo list corrupt"));
        return NULL;
    }
    return curbuf->b_u_newhead->uh_entry;
}

void u_compute_hash (char_u *hash) {
    context_sha256_T ctx;
    linenr_T lnum;
    char_u *p;
    sha256_start (& ctx);
    for (lnum = 1; lnum <= curbuf->b_ml.ml_line_count; ++lnum) {
        p = ml_get (lnum);
        sha256_update (& ctx, p, (UINT32_T) (STRLEN (p) + 1));
    }
    sha256_finish (& ctx, hash);
}

void u_read_undo (char_u *name, char_u *hash, char_u *orig_name) {
    char_u *file_name;
    FILE *fp;
    long  version, str_len;
    char_u *line_ptr = NULL;
    linenr_T line_lnum;
    colnr_T line_colnr;
    linenr_T line_count;
    long  num_head = 0;
    long  old_header_seq, new_header_seq, cur_header_seq;
    long  seq_last, seq_cur;
    long  last_save_nr = 0;
    short  old_idx = -1, new_idx = -1, cur_idx = -1;
    long  num_read_uhps = 0;
    time_t seq_time;
    int i, j;
    int c;
    u_header_T *uhp;
    u_header_T **uhp_table = NULL;
    char_u read_hash [UNDO_HASH_SIZE];
    char_u magic_buf [UF_START_MAGIC_LEN];
    stat_T st_orig;
    stat_T st_undo;
    bufinfo_T bi;
    vim_memset (& bi, 0, sizeof (bi));
    if (name == NULL) {
        file_name = u_get_undo_file_name (curbuf->b_ffname, TRUE);
        if (file_name == NULL)
            return;
        if (mch_stat ((char *) orig_name, &st_orig) >= 0 && mch_stat ((char *) file_name, &st_undo) >= 0 && st_orig.st_uid != st_undo.st_uid && st_undo.st_uid != getuid ()) {
            if (p_verbose > 0) {
                verbose_enter ();
                smsg ((char_u *) _ ("Not reading undo file, owner differs: %s"), file_name);
                verbose_leave ();
            }
            return;
        }
    }
    else
        file_name = name;
    if (p_verbose > 0) {
        verbose_enter ();
        smsg ((char_u *) _ ("Reading undo file: %s"), file_name);
        verbose_leave ();
    }
    fp = mch_fopen ((char *) file_name, "r");
    if (fp == NULL) {
        if (name != NULL || p_verbose > 0)
            EMSG2 (_ ("E822: Cannot open undo file for reading: %s"), file_name);
        goto error;
    }
    bi.bi_buf = curbuf;
    bi.bi_fp = fp;
    if (fread (magic_buf, UF_START_MAGIC_LEN, 1, fp) != 1 || memcmp (magic_buf, UF_START_MAGIC, UF_START_MAGIC_LEN) != 0) {
        EMSG2 (_ ("E823: Not an undo file: %s"), file_name);
        goto error;
    }
    version = get2c (fp);
    if (version == UF_VERSION_CRYPT) {
        if (*curbuf->b_p_key == NUL) {
            EMSG2 (_ ("E832: Non-encrypted file has encrypted undo file: %s"), file_name);
            goto error;
        }
        bi.bi_state = crypt_create_from_file (fp, curbuf->b_p_key);
        if (bi.bi_state == NULL) {
            EMSG2 (_ ("E826: Undo file decryption failed: %s"), file_name);
            goto error;
        }
        if (crypt_whole_undofile (bi.bi_state->method_nr)) {
            bi.bi_buffer = alloc (CRYPT_BUF_SIZE);
            if (bi.bi_buffer == NULL) {
                crypt_free_state (bi.bi_state);
                bi.bi_state = NULL;
                goto error;
            }
            bi.bi_avail = 0;
            bi.bi_used = 0;
        }
    }
    else if (version != UF_VERSION) {
        EMSG2 (_ ("E824: Incompatible undo file: %s"), file_name);
        goto error;
    }
    if (undo_read (&bi, read_hash, (size_t) UNDO_HASH_SIZE) == FAIL) {
        corruption_error ("hash", file_name);
        goto error;
    }
    line_count = (linenr_T) undo_read_4c (&bi);
    if (memcmp (hash, read_hash, UNDO_HASH_SIZE) != 0 || line_count != curbuf->b_ml.ml_line_count) {
        if (p_verbose > 0 || name != NULL) {
            if (name == NULL)
                verbose_enter ();
            give_warning ((char_u *) _ ("File contents changed, cannot use undo info"), TRUE);
            if (name == NULL)
                verbose_leave ();
        }
        goto error;
    }
    str_len = undo_read_4c (&bi);
    if (str_len < 0)
        goto error;
    if (str_len > 0)
        line_ptr = read_string_decrypt (&bi, str_len);
    line_lnum = (linenr_T) undo_read_4c (&bi);
    line_colnr = (colnr_T) undo_read_4c (&bi);
    if (line_lnum < 0 || line_colnr < 0) {
        corruption_error ("line lnum/col", file_name);
        goto error;
    }
    old_header_seq = undo_read_4c (&bi);
    new_header_seq = undo_read_4c (&bi);
    cur_header_seq = undo_read_4c (&bi);
    num_head = undo_read_4c (&bi);
    seq_last = undo_read_4c (&bi);
    seq_cur = undo_read_4c (&bi);
    seq_time = undo_read_time (&bi);
    for (;;) {
        int len = undo_read_byte (&bi);
        int what;
        if (len == 0 || len == EOF)
            break;
        what = undo_read_byte (&bi);
        switch (what) {
        case UF_LAST_SAVE_NR :
            last_save_nr = undo_read_4c (&bi);
            break;
        default :
            while (--len >= 0)
                (void) undo_read_byte (&bi);
        }
    }
    if (num_head > 0) {
        if (num_head < LONG_MAX / (long ) sizeof (u_header_T *))
            uhp_table = (u_header_T **) U_ALLOC_LINE (num_head * sizeof (u_header_T *));
        if (uhp_table == NULL)
            goto error;
    }
    while ((c = undo_read_2c (&bi)) == UF_HEADER_MAGIC) {
        if (num_read_uhps >= num_head) {
            corruption_error ("num_head too small", file_name);
            goto error;
        }
        uhp = unserialize_uhp (&bi, file_name);
        if (uhp == NULL)
            goto error;
        uhp_table[num_read_uhps++] = uhp;
    }
    if (num_read_uhps != num_head) {
        corruption_error ("num_head", file_name);
        goto error;
    }
    if (c != UF_HEADER_END_MAGIC) {
        corruption_error ("end marker", file_name);
        goto error;
    }

    # define SET_FLAG(j)
    for (i = 0; i < num_head; i++) {
        uhp = uhp_table[i];
        if (uhp == NULL)
            continue;
        for (j = 0; j < num_head; j++)
            if (uhp_table[j] != NULL && i != j && uhp_table[i]->uh_seq == uhp_table[j]->uh_seq) {
                corruption_error ("duplicate uh_seq", file_name);
                goto error;
            }
        for (j = 0; j < num_head; j++)
            if (uhp_table[j] != NULL && uhp_table[j]->uh_seq == uhp->uh_next.seq) {
                uhp->uh_next.ptr = uhp_table[j];
                SET_FLAG (j);
                break;
            }
        for (j = 0; j < num_head; j++)
            if (uhp_table[j] != NULL && uhp_table[j]->uh_seq == uhp->uh_prev.seq) {
                uhp->uh_prev.ptr = uhp_table[j];
                SET_FLAG (j);
                break;
            }
        for (j = 0; j < num_head; j++)
            if (uhp_table[j] != NULL && uhp_table[j]->uh_seq == uhp->uh_alt_next.seq) {
                uhp->uh_alt_next.ptr = uhp_table[j];
                SET_FLAG (j);
                break;
            }
        for (j = 0; j < num_head; j++)
            if (uhp_table[j] != NULL && uhp_table[j]->uh_seq == uhp->uh_alt_prev.seq) {
                uhp->uh_alt_prev.ptr = uhp_table[j];
                SET_FLAG (j);
                break;
            }
        if (old_header_seq > 0 && old_idx < 0 && uhp->uh_seq == old_header_seq) {
            old_idx = i;
            SET_FLAG (i);
        }
        if (new_header_seq > 0 && new_idx < 0 && uhp->uh_seq == new_header_seq) {
            new_idx = i;
            SET_FLAG (i);
        }
        if (cur_header_seq > 0 && cur_idx < 0 && uhp->uh_seq == cur_header_seq) {
            cur_idx = i;
            SET_FLAG (i);
        }
    }
    u_blockfree (curbuf);
    curbuf->b_u_oldhead = old_idx < 0 ? NULL : uhp_table[old_idx];
    curbuf->b_u_newhead = new_idx < 0 ? NULL : uhp_table[new_idx];
    curbuf->b_u_curhead = cur_idx < 0 ? NULL : uhp_table[cur_idx];
    curbuf->b_u_line_ptr = line_ptr;
    curbuf->b_u_line_lnum = line_lnum;
    curbuf->b_u_line_colnr = line_colnr;
    curbuf->b_u_numhead = num_head;
    curbuf->b_u_seq_last = seq_last;
    curbuf->b_u_seq_cur = seq_cur;
    curbuf->b_u_time_cur = seq_time;
    curbuf->b_u_save_nr_last = last_save_nr;
    curbuf->b_u_save_nr_cur = last_save_nr;
    curbuf->b_u_synced = TRUE;
    vim_free (uhp_table);
    if (name != NULL)
        smsg ((char_u *) _ ("Finished reading undo file %s"), file_name);
    goto theend;
error :
    vim_free (line_ptr);
    if (uhp_table != NULL) {
        for (i = 0; i < num_read_uhps; i++)
            if (uhp_table[i] != NULL)
                u_free_uhp (uhp_table[i]);
        vim_free (uhp_table);
    }
theend :
    if (bi.bi_state != NULL)
        crypt_free_state (bi.bi_state);
    vim_free (bi.bi_buffer);
    if (fp != NULL)
        fclose (fp);
    if (file_name != name)
        vim_free (file_name);
    return;
}

char_u *u_get_undo_file_name (char_u *buf_ffname, int reading) {
    char_u *dirp;
    char_u dir_name [IOSIZE + 1];
    char_u *munged_name = NULL;
    char_u *undo_file_name = NULL;
    int dir_len;
    char_u *p;
    stat_T st;
    char_u *ffname = buf_ffname;
    if (ffname == NULL)
        return NULL;
    dirp = p_udir;
    while (*dirp != NUL) {
        dir_len = copy_option_part (&dirp, dir_name, IOSIZE, ",");
        if (dir_len == 1 && dir_name[0] == '.') {
            undo_file_name = vim_strnsave (ffname, (int) (STRLEN (ffname) + 5));
            if (undo_file_name == NULL)
                break;
            p = gettail (undo_file_name);
            mch_memmove (p + 1, p, STRLEN (p) + 1);
            *p = '.';
            STRCAT (p, ".un~");
        }
        else {
            dir_name[dir_len] = NUL;
            if (mch_isdir (dir_name)) {
                if (munged_name == NULL) {
                    munged_name = vim_strsave (ffname);
                    if (munged_name == NULL)
                        return NULL;
                    for (p = munged_name; *p != NUL; MB_PTR_ADV (p))
                        if (vim_ispathsep (*p))
                            *p = '%';
                }
                undo_file_name = concat_fnames (dir_name, munged_name, TRUE);
            }
        }
        if (undo_file_name != NULL && (!reading || mch_stat ((char *) undo_file_name, &st) >= 0))
            break;
        VIM_CLEAR (undo_file_name);
    }
    vim_free (munged_name);
    return undo_file_name;
}

static void corruption_error (char *mesg, char_u *file_name) {
    EMSG3 (_ ("E825: Corrupted undo file (%s): %s"), mesg, file_name);
}

static char_u *read_string_decrypt (bufinfo_T *bi, int len) {
    char_u *ptr = alloc ((unsigned ) len + 1);
    if (ptr != NULL) {
        if (len > 0 && undo_read (bi, ptr, len) == FAIL) {
            vim_free (ptr);
            return NULL;
        }
        ptr[len] = NUL;
        if (bi->bi_state != NULL && bi->bi_buffer == NULL)
            crypt_decode_inplace (bi->bi_state, ptr, len);
    }
    return ptr;
}

static u_header_T *unserialize_uhp (bufinfo_T *bi, char_u *file_name) {
    u_header_T *uhp;
    int i;
    u_entry_T *uep, *last_uep;
    int c;
    int error;
    uhp = (u_header_T *) U_ALLOC_LINE (sizeof (u_header_T));
    if (uhp == NULL)
        return NULL;
    vim_memset (uhp, 0, sizeof (u_header_T));
    uhp->uh_next.seq = undo_read_4c (bi);
    uhp->uh_prev.seq = undo_read_4c (bi);
    uhp->uh_alt_next.seq = undo_read_4c (bi);
    uhp->uh_alt_prev.seq = undo_read_4c (bi);
    uhp->uh_seq = undo_read_4c (bi);
    if (uhp->uh_seq <= 0) {
        corruption_error ("uh_seq", file_name);
        vim_free (uhp);
        return NULL;
    }
    unserialize_pos (bi, & uhp -> uh_cursor);
    uhp->uh_cursor_vcol = undo_read_4c (bi);
    uhp->uh_flags = undo_read_2c (bi);
    for (i = 0; i < NMARKS; ++i)
        unserialize_pos (bi, &uhp->uh_namedm[i]);
    unserialize_visualinfo (bi, & uhp -> uh_visual);
    uhp->uh_time = undo_read_time (bi);
    for (;;) {
        int len = undo_read_byte (bi);
        int what;
        if (len == 0)
            break;
        what = undo_read_byte (bi);
        switch (what) {
        case UHP_SAVE_NR :
            uhp->uh_save_nr = undo_read_4c (bi);
            break;
        default :
            while (--len >= 0)
                (void) undo_read_byte (bi);
        }
    }
    last_uep = NULL;
    while ((c = undo_read_2c (bi)) == UF_ENTRY_MAGIC) {
        error = FALSE;
        uep = unserialize_uep (bi, &error, file_name);
        if (last_uep == NULL)
            uhp->uh_entry = uep;
        else
            last_uep->ue_next = uep;
        last_uep = uep;
        if (uep == NULL || error) {
            u_free_uhp (uhp);
            return NULL;
        }
    }
    if (c != UF_ENTRY_END_MAGIC) {
        corruption_error ("entry end", file_name);
        u_free_uhp (uhp);
        return NULL;
    }
    return uhp;
}

static void unserialize_pos (bufinfo_T *bi, pos_T *pos) {
    pos->lnum = undo_read_4c (bi);
    if (pos->lnum < 0)
        pos->lnum = 0;
    pos->col = undo_read_4c (bi);
    if (pos->col < 0)
        pos->col = 0;
    pos->coladd = undo_read_4c (bi);
    if (pos->coladd < 0)
        pos->coladd = 0;
}

static void unserialize_visualinfo (bufinfo_T *bi, visualinfo_T *info) {
    unserialize_pos (bi, & info -> vi_start);
    unserialize_pos (bi, & info -> vi_end);
    info->vi_mode = undo_read_4c (bi);
    info->vi_curswant = undo_read_4c (bi);
}

static u_entry_T *unserialize_uep (bufinfo_T *bi, int *error, char_u *file_name) {
    int i;
    u_entry_T *uep;
    char_u **array = NULL;
    char_u *line;
    int line_len;
    uep = (u_entry_T *) U_ALLOC_LINE (sizeof (u_entry_T));
    if (uep == NULL)
        return NULL;
    vim_memset (uep, 0, sizeof (u_entry_T));
    uep->ue_top = undo_read_4c (bi);
    uep->ue_bot = undo_read_4c (bi);
    uep->ue_lcount = undo_read_4c (bi);
    uep->ue_size = undo_read_4c (bi);
    if (uep->ue_size > 0) {
        if (uep->ue_size < LONG_MAX / (int) sizeof (char_u *))
            array = (char_u **) U_ALLOC_LINE (sizeof (char_u *) * uep->ue_size);
        if (array == NULL) {
            *error = TRUE;
            return uep;
        }
        vim_memset (array, 0, sizeof (char_u *) * uep -> ue_size);
    }
    uep->ue_array = array;
    for (i = 0; i < uep->ue_size; ++i) {
        line_len = undo_read_4c (bi);
        if (line_len >= 0)
            line = read_string_decrypt (bi, line_len);
        else {
            line = NULL;
            corruption_error ("line length", file_name);
        }
        if (line == NULL) {
            *error = TRUE;
            return uep;
        }
        array[i] = line;
    }
    return uep;
}

static void u_free_uhp (u_header_T *uhp) {
    u_entry_T *nuep;
    u_entry_T *uep;
    uep = uhp->uh_entry;
    while (uep != NULL) {
        nuep = uep->ue_next;
        u_freeentry (uep, uep -> ue_size);
        uep = nuep;
    }
    vim_free (uhp);
}

void u_unchanged (buf_T *buf) {
    u_unch_branch (buf -> b_u_oldhead);
    buf->b_did_warn = FALSE;
}

static void u_unch_branch (u_header_T *uhp) {
    u_header_T *uh;
    for (uh = uhp; uh != NULL; uh = uh->uh_prev.ptr) {
        uh->uh_flags |= UH_CHANGED;
        if (uh->uh_alt_next.ptr != NULL)
            u_unch_branch (uh->uh_alt_next.ptr);
    }
}

void u_update_save_nr (buf_T *buf) {
    u_header_T *uhp;
    ++buf->b_u_save_nr_last;
    buf->b_u_save_nr_cur = buf->b_u_save_nr_last;
    uhp = buf->b_u_curhead;
    if (uhp != NULL)
        uhp = uhp->uh_next.ptr;
    else
        uhp = buf->b_u_newhead;
    if (uhp != NULL)
        uhp->uh_save_nr = buf->b_u_save_nr_last;
}

void u_write_undo (char_u *name, int forceit, buf_T *buf, char_u *hash) {
    u_header_T *uhp;
    char_u *file_name;
    int mark;
    int fd;
    FILE *fp = NULL;
    int perm;
    int write_ok = FALSE;
    int st_old_valid = FALSE;
    stat_T st_old;
    stat_T st_new;
    bufinfo_T bi;
    vim_memset (& bi, 0, sizeof (bi));
    if (name == NULL) {
        file_name = u_get_undo_file_name (buf->b_ffname, FALSE);
        if (file_name == NULL) {
            if (p_verbose > 0) {
                verbose_enter ();
                smsg ((char_u *) _ ("Cannot write undo file in any directory in 'undodir'"));
                verbose_leave ();
            }
            return;
        }
    }
    else
        file_name = name;
    perm = 0600;
    if (buf->b_ffname != NULL) {
        if (mch_stat ((char *) buf->b_ffname, &st_old) >= 0) {
            perm = st_old.st_mode;
            st_old_valid = TRUE;
        }
    }
    perm = perm & 0666;
    if (mch_getperm (file_name) >= 0) {
        if (name == NULL || !forceit) {
            fd = mch_open ((char *) file_name, O_RDONLY | O_EXTRA, 0);
            if (fd < 0) {
                if (name != NULL || p_verbose > 0) {
                    if (name == NULL)
                        verbose_enter ();
                    smsg ((char_u *) _ ("Will not overwrite with undo file, cannot read: %s"), file_name);
                    if (name == NULL)
                        verbose_leave ();
                }
                goto theend;
            }
            else {
                char_u mbuf [UF_START_MAGIC_LEN];
                int len;
                len = read_eintr (fd, mbuf, UF_START_MAGIC_LEN);
                close (fd);
                if (len < UF_START_MAGIC_LEN || memcmp (mbuf, UF_START_MAGIC, UF_START_MAGIC_LEN) != 0) {
                    if (name != NULL || p_verbose > 0) {
                        if (name == NULL)
                            verbose_enter ();
                        smsg ((char_u *) _ ("Will not overwrite, this is not an undo file: %s"), file_name);
                        if (name == NULL)
                            verbose_leave ();
                    }
                    goto theend;
                }
            }
        }
        mch_remove (file_name);
    }
    if (buf->b_u_numhead == 0 && buf->b_u_line_ptr == NULL) {
        if (p_verbose > 0)
            verb_msg ((char_u *) _ ("Skipping undo file write, nothing to undo"));
        goto theend;
    }
    fd = mch_open ((char *) file_name, O_CREAT | O_EXTRA | O_WRONLY | O_EXCL | O_NOFOLLOW, perm);
    if (fd < 0) {
        EMSG2 (_ (e_not_open), file_name);
        goto theend;
    }
    (void) mch_setperm (file_name, perm);
    if (p_verbose > 0) {
        verbose_enter ();
        smsg ((char_u *) _ ("Writing undo file: %s"), file_name);
        verbose_leave ();
    }
    if (st_old_valid && mch_stat ((char *) file_name, &st_new) >= 0 && st_new.st_gid != st_old.st_gid)
        mch_setperm (file_name, (perm & 0707) | ((perm & 07) << 3));
    fp = fdopen (fd, "w");
    if (fp == NULL) {
        EMSG2 (_ (e_not_open), file_name);
        close (fd);
        mch_remove (file_name);
        goto theend;
    }
    u_sync (TRUE);
    bi.bi_buf = buf;
    bi.bi_fp = fp;
    if (serialize_header (&bi, hash) == FAIL)
        goto write_error;
    mark = ++lastmark;
    uhp = buf->b_u_oldhead;
    while (uhp != NULL) {
        if (uhp->uh_walk != mark) {
            uhp->uh_walk = mark;
            if (serialize_uhp (&bi, uhp) == FAIL)
                goto write_error;
        }
        if (uhp->uh_prev.ptr != NULL && uhp->uh_prev.ptr->uh_walk != mark)
            uhp = uhp->uh_prev.ptr;
        else if (uhp->uh_alt_next.ptr != NULL && uhp->uh_alt_next.ptr->uh_walk != mark)
            uhp = uhp->uh_alt_next.ptr;
        else if (uhp->uh_next.ptr != NULL && uhp->uh_alt_prev.ptr == NULL && uhp->uh_next.ptr->uh_walk != mark)
            uhp = uhp->uh_next.ptr;
        else if (uhp->uh_alt_prev.ptr != NULL)
            uhp = uhp->uh_alt_prev.ptr;
        else
            uhp = uhp->uh_next.ptr;
    }
    if (undo_write_bytes (&bi, (long_u) UF_HEADER_END_MAGIC, 2) == OK)
        write_ok = TRUE;
    if (bi.bi_state != NULL && undo_flush (&bi) == FAIL)
        write_ok = FALSE;
write_error :
    fclose (fp);
    if (!write_ok)
        EMSG2 (_ ("E829: write error in undo file: %s"), file_name);
    if (buf->b_ffname != NULL) {
        vim_acl_T acl;
        acl = mch_get_acl (buf->b_ffname);
        mch_set_acl (file_name, acl);
        mch_free_acl (acl);
    }
theend :
    if (bi.bi_state != NULL)
        crypt_free_state (bi.bi_state);
    vim_free (bi.bi_buffer);
    if (file_name != name)
        vim_free (file_name);
}

static int serialize_header (bufinfo_T *bi, char_u *hash) {
    int len;
    buf_T *buf = bi->bi_buf;
    FILE *fp = bi->bi_fp;
    char_u time_buf [8];
    if (fwrite (UF_START_MAGIC, (size_t) UF_START_MAGIC_LEN, (size_t) 1, fp) != 1)
        return FAIL;
    if (*buf->b_p_key != NUL) {
        char_u *header;
        int header_len;
        undo_write_bytes (bi, (long_u) UF_VERSION_CRYPT, 2);
        bi->bi_state = crypt_create_for_writing (crypt_get_method_nr (buf), buf->b_p_key, &header, &header_len);
        if (bi->bi_state == NULL)
            return FAIL;
        len = (int) fwrite (header, (size_t) header_len, (size_t) 1, fp);
        vim_free (header);
        if (len != 1) {
            crypt_free_state (bi -> bi_state);
            bi->bi_state = NULL;
            return FAIL;
        }
        if (crypt_whole_undofile (crypt_get_method_nr (buf))) {
            bi->bi_buffer = alloc (CRYPT_BUF_SIZE);
            if (bi->bi_buffer == NULL) {
                crypt_free_state (bi -> bi_state);
                bi->bi_state = NULL;
                return FAIL;
            }
            bi->bi_used = 0;
        }
    }
    else
        undo_write_bytes (bi, (long_u) UF_VERSION, 2);
    if (undo_write (bi, hash, (size_t) UNDO_HASH_SIZE) == FAIL)
        return FAIL;
    undo_write_bytes (bi, (long_u) buf -> b_ml.ml_line_count, 4);
    len = buf->b_u_line_ptr != NULL ? (int) STRLEN (buf->b_u_line_ptr) : 0;
    undo_write_bytes (bi, (long_u) len, 4);
    if (len > 0 && fwrite_crypt (bi, buf->b_u_line_ptr, (size_t) len) == FAIL)
        return FAIL;
    undo_write_bytes (bi, (long_u) buf -> b_u_line_lnum, 4);
    undo_write_bytes (bi, (long_u) buf -> b_u_line_colnr, 4);
    put_header_ptr (bi, buf -> b_u_oldhead);
    put_header_ptr (bi, buf -> b_u_newhead);
    put_header_ptr (bi, buf -> b_u_curhead);
    undo_write_bytes (bi, (long_u) buf -> b_u_numhead, 4);
    undo_write_bytes (bi, (long_u) buf -> b_u_seq_last, 4);
    undo_write_bytes (bi, (long_u) buf -> b_u_seq_cur, 4);
    time_to_bytes (buf -> b_u_time_cur, time_buf);
    undo_write (bi, time_buf, 8);
    undo_write_bytes (bi, 4, 1);
    undo_write_bytes (bi, UF_LAST_SAVE_NR, 1);
    undo_write_bytes (bi, (long_u) buf -> b_u_save_nr_last, 4);
    undo_write_bytes (bi, 0, 1);
    return OK;
}

static int fwrite_crypt (bufinfo_T *bi, char_u *ptr, size_t len) {
    char_u *copy;
    char_u small_buf [100];
    size_t i;
    if (bi->bi_state != NULL && bi->bi_buffer == NULL) {
        if (len < 100)
            copy = small_buf;
        else {
            copy = lalloc (len, FALSE);
            if (copy == NULL)
                return 0;
        }
        crypt_encode (bi -> bi_state, ptr, len, copy);
        i = fwrite (copy, len, (size_t) 1, bi->bi_fp);
        if (copy != small_buf)
            vim_free (copy);
        return i == 1 ? OK : FAIL;
    }
    return undo_write (bi, ptr, len);
}

static void put_header_ptr (bufinfo_T *bi, u_header_T *uhp) {
    undo_write_bytes (bi, (long_u) (uhp != NULL ? uhp -> uh_seq : 0), 4);
}

static int serialize_uhp (bufinfo_T *bi, u_header_T *uhp) {
    int i;
    u_entry_T *uep;
    char_u time_buf [8];
    if (undo_write_bytes (bi, (long_u) UF_HEADER_MAGIC, 2) == FAIL)
        return FAIL;
    put_header_ptr (bi, uhp -> uh_next.ptr);
    put_header_ptr (bi, uhp -> uh_prev.ptr);
    put_header_ptr (bi, uhp -> uh_alt_next.ptr);
    put_header_ptr (bi, uhp -> uh_alt_prev.ptr);
    undo_write_bytes (bi, uhp -> uh_seq, 4);
    serialize_pos (bi, uhp -> uh_cursor);
    undo_write_bytes (bi, (long_u) uhp -> uh_cursor_vcol, 4);
    undo_write_bytes (bi, (long_u) uhp -> uh_flags, 2);
    for (i = 0; i < NMARKS; ++i)
        serialize_pos (bi, uhp->uh_namedm[i]);
    serialize_visualinfo (bi, & uhp -> uh_visual);
    time_to_bytes (uhp -> uh_time, time_buf);
    undo_write (bi, time_buf, 8);
    undo_write_bytes (bi, 4, 1);
    undo_write_bytes (bi, UHP_SAVE_NR, 1);
    undo_write_bytes (bi, (long_u) uhp -> uh_save_nr, 4);
    undo_write_bytes (bi, 0, 1);
    for (uep = uhp->uh_entry; uep != NULL; uep = uep->ue_next) {
        undo_write_bytes (bi, (long_u) UF_ENTRY_MAGIC, 2);
        if (serialize_uep (bi, uep) == FAIL)
            return FAIL;
    }
    undo_write_bytes (bi, (long_u) UF_ENTRY_END_MAGIC, 2);
    return OK;
}

static void serialize_pos (bufinfo_T *bi, pos_T pos) {
    undo_write_bytes (bi, (long_u) pos.lnum, 4);
    undo_write_bytes (bi, (long_u) pos.col, 4);
    undo_write_bytes (bi, (long_u) pos.coladd, 4);
}

static void serialize_visualinfo (bufinfo_T *bi, visualinfo_T *info) {
    serialize_pos (bi, info -> vi_start);
    serialize_pos (bi, info -> vi_end);
    undo_write_bytes (bi, (long_u) info -> vi_mode, 4);
    undo_write_bytes (bi, (long_u) info -> vi_curswant, 4);
}

static int serialize_uep (bufinfo_T *bi, u_entry_T *uep) {
    int i;
    size_t len;
    undo_write_bytes (bi, (long_u) uep -> ue_top, 4);
    undo_write_bytes (bi, (long_u) uep -> ue_bot, 4);
    undo_write_bytes (bi, (long_u) uep -> ue_lcount, 4);
    undo_write_bytes (bi, (long_u) uep -> ue_size, 4);
    for (i = 0; i < uep->ue_size; ++i) {
        len = STRLEN (uep->ue_array[i]);
        if (undo_write_bytes (bi, (long_u) len, 4) == FAIL)
            return FAIL;
        if (len > 0 && fwrite_crypt (bi, uep->ue_array[i], len) == FAIL)
            return FAIL;
    }
    return OK;
}

int u_savecommon (linenr_T top, linenr_T bot, linenr_T newbot, int reload) {
    linenr_T lnum;
    long  i;
    u_header_T *uhp;
    u_header_T *old_curhead;
    u_entry_T *uep;
    u_entry_T *prev_uep;
    long  size;
    if (!reload) {
        if (!undo_allowed ())
            return FAIL;
        if (netbeans_active ()) {
            if (netbeans_is_guarded (top, bot)) {
                EMSG (_ (e_guarded));
                return FAIL;
            }
            if (curbuf->b_p_ro) {
                EMSG (_ (e_nbreadonly));
                return FAIL;
            }
        }
        term_change_in_curbuf ();
        change_warning (0);
        if (bot > curbuf->b_ml.ml_line_count + 1) {
            EMSG (_ ("E881: Line count changed unexpectedly"));
            return FAIL;
        }
    }
    size = bot - top - 1;
    if (curbuf->b_u_synced) {
        curbuf->b_new_change = TRUE;
        if (get_undolevel () >= 0) {
            uhp = (u_header_T *) U_ALLOC_LINE (sizeof (u_header_T));
            if (uhp == NULL)
                goto nomem;
        }
        else
            uhp = NULL;
        old_curhead = curbuf->b_u_curhead;
        if (old_curhead != NULL) {
            curbuf->b_u_newhead = old_curhead->uh_next.ptr;
            curbuf->b_u_curhead = NULL;
        }
        while (curbuf->b_u_numhead > get_undolevel () && curbuf->b_u_oldhead != NULL) {
            u_header_T *uhfree = curbuf->b_u_oldhead;
            if (uhfree == old_curhead)
                u_freebranch (curbuf, uhfree, &old_curhead);
            else if (uhfree->uh_alt_next.ptr == NULL)
                u_freeheader (curbuf, uhfree, &old_curhead);
            else {
                while (uhfree->uh_alt_next.ptr != NULL)
                    uhfree = uhfree->uh_alt_next.ptr;
                u_freebranch (curbuf, uhfree, & old_curhead);
            }
        }
        if (uhp == NULL) {
            if (old_curhead != NULL)
                u_freebranch (curbuf, old_curhead, NULL);
            curbuf->b_u_synced = FALSE;
            return OK;
        }
        uhp->uh_prev.ptr = NULL;
        uhp->uh_next.ptr = curbuf->b_u_newhead;
        uhp->uh_alt_next.ptr = old_curhead;
        if (old_curhead != NULL) {
            uhp->uh_alt_prev.ptr = old_curhead->uh_alt_prev.ptr;
            if (uhp->uh_alt_prev.ptr != NULL)
                uhp->uh_alt_prev.ptr->uh_alt_next.ptr = uhp;
            old_curhead->uh_alt_prev.ptr = uhp;
            if (curbuf->b_u_oldhead == old_curhead)
                curbuf->b_u_oldhead = uhp;
        }
        else
            uhp->uh_alt_prev.ptr = NULL;
        if (curbuf->b_u_newhead != NULL)
            curbuf->b_u_newhead->uh_prev.ptr = uhp;
        uhp->uh_seq = ++curbuf->b_u_seq_last;
        curbuf->b_u_seq_cur = uhp->uh_seq;
        uhp->uh_time = vim_time ();
        uhp->uh_save_nr = 0;
        curbuf->b_u_time_cur = uhp->uh_time + 1;
        uhp->uh_walk = 0;
        uhp->uh_entry = NULL;
        uhp->uh_getbot_entry = NULL;
        uhp->uh_cursor = curwin->w_cursor;
        if (virtual_active () && curwin->w_cursor.coladd > 0)
            uhp->uh_cursor_vcol = getviscol ();
        else
            uhp->uh_cursor_vcol = -1;
        uhp->uh_flags = (curbuf->b_changed ? UH_CHANGED : 0) + ((curbuf->b_ml.ml_flags & ML_EMPTY) ? UH_EMPTYBUF : 0);
        mch_memmove (uhp -> uh_namedm, curbuf -> b_namedm, sizeof (pos_T) * NMARKS);
        uhp->uh_visual = curbuf->b_visual;
        curbuf->b_u_newhead = uhp;
        if (curbuf->b_u_oldhead == NULL)
            curbuf->b_u_oldhead = uhp;
        ++curbuf->b_u_numhead;
    }
    else {
        if (get_undolevel () < 0)
            return OK;
        if (size == 1) {
            uep = u_get_headentry ();
            prev_uep = NULL;
            for (i = 0; i < 10; ++i) {
                if (uep == NULL)
                    break;
                if ((curbuf->b_u_newhead->uh_getbot_entry != uep ? (uep->ue_top + uep->ue_size + 1 != (uep->ue_bot == 0 ? curbuf->b_ml.ml_line_count + 1 : uep->ue_bot)) : uep->ue_lcount != curbuf->b_ml.ml_line_count) || (uep->ue_size > 1 && top >= uep->ue_top && top + 2 <= uep->ue_top + uep->ue_size + 1))
                    break;
                if (uep->ue_size == 1 && uep->ue_top == top) {
                    if (i > 0) {
                        u_getbot ();
                        curbuf->b_u_synced = FALSE;
                        prev_uep->ue_next = uep->ue_next;
                        uep->ue_next = curbuf->b_u_newhead->uh_entry;
                        curbuf->b_u_newhead->uh_entry = uep;
                    }
                    if (newbot != 0)
                        uep->ue_bot = newbot;
                    else if (bot > curbuf->b_ml.ml_line_count)
                        uep->ue_bot = 0;
                    else {
                        uep->ue_lcount = curbuf->b_ml.ml_line_count;
                        curbuf->b_u_newhead->uh_getbot_entry = uep;
                    }
                    return OK;
                }
                prev_uep = uep;
                uep = uep->ue_next;
            }
        }
        u_getbot ();
    }
    uep = (u_entry_T *) U_ALLOC_LINE (sizeof (u_entry_T));
    if (uep == NULL)
        goto nomem;
    vim_memset (uep, 0, sizeof (u_entry_T));
    uep->ue_size = size;
    uep->ue_top = top;
    if (newbot != 0)
        uep->ue_bot = newbot;
    else if (bot > curbuf->b_ml.ml_line_count)
        uep->ue_bot = 0;
    else {
        uep->ue_lcount = curbuf->b_ml.ml_line_count;
        curbuf->b_u_newhead->uh_getbot_entry = uep;
    }
    if (size > 0) {
        if ((uep->ue_array = (char_u **) U_ALLOC_LINE (sizeof (char_u *) * size)) == NULL) {
            u_freeentry (uep, 0L);
            goto nomem;
        }
        for (i = 0, lnum = top + 1; i < size; ++i) {
            fast_breakcheck ();
            if (got_int) {
                u_freeentry (uep, i);
                return FAIL;
            }
            if ((uep->ue_array[i] = u_save_line (lnum++)) == NULL) {
                u_freeentry (uep, i);
                goto nomem;
            }
        }
    }
    else
        uep->ue_array = NULL;
    uep->ue_next = curbuf->b_u_newhead->uh_entry;
    curbuf->b_u_newhead->uh_entry = uep;
    curbuf->b_u_synced = FALSE;
    undo_undoes = FALSE;
    return OK;
nomem :
    msg_silent = 0;
    if (ask_yesno ((char_u *) _ ("No undo possible; continue anyway"), TRUE) == 'y') {
        undo_off = TRUE;
        return OK;
    }
    do_outofmem_msg ((long_u) 0);
    return FAIL;
}

# define UF_START_MAGIC	    "Vim\237UnDo\345"  /* magic at start of undofile */

# define UF_START_MAGIC_LEN	9

# define UF_HEADER_MAGIC	0x5fd0	/* magic at start of header */

# define UF_HEADER_END_MAGIC	0xe7aa	/* magic after last header */

# define UF_ENTRY_MAGIC		0xf518	/* magic at start of entry */

# define UF_ENTRY_END_MAGIC	0x3581	/* magic after last entry */

# define UF_VERSION		2	/* 2-byte undofile version number */

# define UF_VERSION_CRYPT	0x8002	/* idem, encrypted */

# define UF_LAST_SAVE_NR	1

# define UHP_SAVE_NR		1

int undo_allowed (void) {
    if (!curbuf->b_p_ma) {
        EMSG (_ (e_modifiable));
        return FALSE;
    }
    if (textlock != 0) {
        EMSG (_ (e_secure));
        return FALSE;
    }
    return TRUE;
}

static char_u *u_save_line (linenr_T lnum) {
    return vim_strsave (ml_get (lnum));
}

int u_save_cursor (void) {
    return (u_save ((linenr_T) (curwin->w_cursor.lnum - 1), (linenr_T) (curwin->w_cursor.lnum + 1)));
}

int u_save (linenr_T top, linenr_T bot) {
    if (undo_off)
        return OK;
    if (top > curbuf->b_ml.ml_line_count || top >= bot || bot > curbuf->b_ml.ml_line_count + 1)
        return FALSE;
    if (top + 2 == bot)
        u_saveline ((linenr_T) (top + 1));
    return (u_savecommon (top, bot, (linenr_T) 0, FALSE));
}

void u_saveline (linenr_T lnum) {
    if (lnum == curbuf->b_u_line_lnum)
        return;
    if (lnum < 1 || lnum > curbuf->b_ml.ml_line_count)
        return;
    u_clearline ();
    curbuf->b_u_line_lnum = lnum;
    if (curwin->w_cursor.lnum == lnum)
        curbuf->b_u_line_colnr = curwin->w_cursor.col;
    else
        curbuf->b_u_line_colnr = 0;
    if ((curbuf->b_u_line_ptr = u_save_line (lnum)) == NULL)
        do_outofmem_msg ((long_u) 0);
}

void u_clearline (void) {
    if (curbuf->b_u_line_ptr != NULL) {
        VIM_CLEAR (curbuf -> b_u_line_ptr);
        curbuf->b_u_line_lnum = 0;
    }
}

int u_savesub (linenr_T lnum) {
    if (undo_off)
        return OK;
    return (u_savecommon (lnum -1, lnum +1, lnum +1, FALSE));
}

int u_savedel (linenr_T lnum, long  nlines) {
    if (undo_off)
        return OK;
    return (u_savecommon (lnum -1, lnum +nlines, nlines == curbuf->b_ml.ml_line_count ? 2 : lnum, FALSE));
}

void u_find_first_changed (void) {
    u_header_T *uhp = curbuf->b_u_newhead;
    u_entry_T *uep;
    linenr_T lnum;
    if (curbuf->b_u_curhead != NULL || uhp == NULL)
        return;
    uep = uhp->uh_entry;
    if (uep->ue_top != 0 || uep->ue_bot != 0)
        return;
    for (lnum = 1; lnum < curbuf->b_ml.ml_line_count && lnum <= uep->ue_size; ++lnum)
        if (STRCMP (ml_get_buf (curbuf, lnum, FALSE), uep->ue_array[lnum - 1]) != 0) {
            CLEAR_POS (& (uhp -> uh_cursor));
            uhp->uh_cursor.lnum = lnum;
            return;
        }
    if (curbuf->b_ml.ml_line_count != uep->ue_size) {
        CLEAR_POS (& (uhp -> uh_cursor));
        uhp->uh_cursor.lnum = lnum;
    }
}

