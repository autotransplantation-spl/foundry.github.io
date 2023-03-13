static struct {
    FMFontFamily family;
    FMFontSize size;
    FMFontStyle style;
    Boolean isPanelVisible;
} gFontPanelInfo = {0, 0, 0, false};
static struct {
    KeySym key_sym;
    char_u vim_code0;
    char_u vim_code1;
} special_keys [] = {{vk_Up, 'k', 'u'}, {vk_Down, 'k', 'd'}, {vk_Left, 'k', 'l'}, {vk_Right, 'k', 'r'}, {vk_F1, 'k', '1'}, {vk_F2, 'k', '2'}, {vk_F3, 'k', '3'}, {vk_F4, 'k', '4'}, {vk_F5, 'k', '5'}, {vk_F6, 'k', '6'}, {vk_F7, 'k', '7'}, {vk_F8, 'k', '8'}, {vk_F9, 'k', '9'}, {vk_F10, 'k', ';'}, {vk_F11, 'F', '1'}, {vk_F12, 'F', '2'}, {vk_F13, 'F', '3'}, {vk_F14, 'F', '4'}, {vk_F15, 'F', '5'}, {vk_Insert, 'k', 'I'}, {vk_FwdDelete, 'k', 'D'}, {vk_Home, 'k', 'h'}, {vk_End, '@', '7'}, {vk_PageUp, 'k', 'P'}, {vk_PageDown, 'k', 'N'}, {(KeySym) 0, 0, 0}};
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
EXTERN int p_mh;
EventHandlerUPP mouseWheelHandlerUPP = NULL;
short  *gDialogHotKeys;
EXTERN char_u *p_go;
EXTERN long  Rows;
EXTERN vimmenu_T *root_menu INIT (= NULL);
RgnHandle dragRgn;
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
RGBColor specialColor;
ControlActionUPP gScrollDrag;
ControlActionUPP gScrollAction;
short  clickIsPopup;
short  dragRectControl;
short  dragRectEnbl;
Rect dragRect;
long  lastMouseTick = 0;
SInt32 gMacSystemVersion;
EXTERN proftime_T bevalexpr_due;
EXTERN char_u e_invexpr2 [] INIT (= N_ ("E15: Invalid expression: %s"));
EXTERN char_u *p_pexpr;
EXTERN char_u *p_bexpr;
int allow_scrollbar = FALSE;
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
RgnHandle cursorRgn;
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
ControlHandle dragged_sb = NULL;
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
EXTERN int p_bevalterm;
EXTERN pos_T Insstart_orig;
EXTERN pos_T Insstart;
EXTERN pos_T VIsual;
EXTERN int p_prompt;
EXTERN char_u *p_guifont;
EXTERN char_u *p_isp;
EXTERN int p_is;
EXTERN int p_altkeymap;
EXTERN char_u e_nbreadonly [] INIT (= N_ ("E744: NetBeans does not allow changes in read-only files"));

void gui_mch_update (void) {
    EventRecord theEvent;
    if (EventAvail (everyEvent, &theEvent))
        if (theEvent.what != nullEvent)
            gui_mch_wait_for_chars (0);
}

int gui_mch_wait_for_chars (int wtime) {
    EventMask mask = (everyEvent);
    EventRecord event;
    long  entryTick;
    long  currentTick;
    long  sleeppyTick;
    if (dragged_sb != NULL)
        return FAIL;
    entryTick = TickCount ();
    allow_scrollbar = TRUE;
    do {
        if (dragRectControl == kCreateRect) {
            dragRgn = cursorRgn;
            RectRgn (dragRgn, & dragRect);
            dragRectControl = kNothing;
        }
        if (wtime > -1)
            sleeppyTick = 60 * wtime / 1000;
        else
            sleeppyTick = 32767;
        if (WaitNextEventWrp (mask, &event, sleeppyTick, dragRgn)) {
            gui_mac_handle_event (& event);
            if (input_available ()) {
                allow_scrollbar = FALSE;
                return OK;
            }
        }
        currentTick = TickCount ();
    }
    while ((wtime == -1) || ((currentTick - entryTick) < 60 * wtime / 1000));
    allow_scrollbar = FALSE;
    return FAIL;
}

pascal Boolean WaitNextEventWrp (EventMask eventMask, EventRecord *theEvent, UInt32 sleep, RgnHandle mouseRgn) {
    if (((long ) sleep) < -1)
        sleep = 32767;
    return WaitNextEvent (eventMask, theEvent, sleep, mouseRgn);
}

void gui_mac_handle_event (EventRecord *event) {
    OSErr error;
    if (IsShowContextualMenuClick (event)) {
        gui_mac_doMouseDownEvent (event);
        return;
    }
    switch (event->what) {
    case (keyDown) :
    case (autoKey) :
        gui_mac_doKeyEvent (event);
        break;
    case (keyUp) :
        break;
    case (mouseDown) :
        gui_mac_doMouseDownEvent (event);
        break;
    case (mouseUp) :
        gui_mac_doMouseUpEvent (event);
        break;
    case (updateEvt) :
        gui_mac_doUpdateEvent (event);
        break;
    case (diskEvt) :
        break;
    case (activateEvt) :
        gui_mac_doActivateEvent (event);
        break;
    case (osEvt) :
        switch ((event->message >> 24) & 0xFF) {
        case (0xFA) :
            gui_mac_doMouseMovedEvent (event);
            break;
        case (0x01) :
            gui_mac_doSuspendEvent (event);
            break;
        }
        break;
    }
}

void gui_mac_handle_menu (long  menuChoice) {
    short  menu = HiWord (menuChoice);
    short  item = LoWord (menuChoice);
    vimmenu_T *theVimMenu = root_menu;
    if (menu == 256) {
        if (item == 1)
            gui_mch_beep ();
    }
    else if (item != 0) {
        theVimMenu = gui_mac_get_vim_menu (menu, item, root_menu);
        if (theVimMenu)
            gui_menu_cb (theVimMenu);
    }
    HiliteMenu (0);
}

void gui_mch_beep (void) {
    SysBeep (1);
}

static vimmenu_T *gui_mac_get_vim_menu (short  menuID, short  itemIndex, vimmenu_T *pMenu) {
    short  index;
    vimmenu_T *pChildMenu;
    vimmenu_T *pElder = pMenu->parent;
    if ((pElder) &&(pElder->submenu_id == menuID)) {
        for (index = 1; (index != itemIndex) && (pMenu != NULL); index++)
            pMenu = pMenu->next;
    }
    else {
        for (; pMenu != NULL; pMenu = pMenu->next) {
            if (pMenu->children != NULL) {
                pChildMenu = gui_mac_get_vim_menu (menuID, itemIndex, pMenu->children);
                if (pChildMenu) {
                    pMenu = pChildMenu;
                    break;
                }
            }
        }
    }
    return pMenu;
}

void gui_mac_doMouseDownEvent (EventRecord *theEvent) {
    short  thePart;
    WindowPtr whichWindow;
    thePart = FindWindow (theEvent->where, &whichWindow);
    switch (thePart) {
    case (inDesk) :
        break;
    case (inMenuBar) :
        gui_mac_handle_menu (MenuSelect (theEvent->where));
        break;
    case (inContent) :
        gui_mac_doInContentClick (theEvent, whichWindow);
        break;
    case (inDrag) :
        gui_mac_doInDragClick (theEvent->where, whichWindow);
        break;
    case (inGrow) :
        gui_mac_doInGrowClick (theEvent->where, whichWindow);
        break;
    case (inGoAway) :
        if (TrackGoAway (whichWindow, theEvent->where))
            gui_shell_closed ();
        break;
    case (inZoomIn) :
    case (inZoomOut) :
        gui_mac_doInZoomClick (theEvent, whichWindow);
        break;
    }
}

void gui_mac_doInContentClick (EventRecord *theEvent, WindowPtr whichWindow) {
    Point thePoint;
    int_u vimModifiers;
    short  thePortion;
    ControlHandle theControl;
    int vimMouseButton;
    short  dblClick;
    thePoint = theEvent->where;
    GlobalToLocal (& thePoint);
    SelectWindow (whichWindow);
    thePortion = FindControl (thePoint, whichWindow, &theControl);
    if (theControl != NUL) {
        if (thePortion != kControlIndicatorPart) {
            dragged_sb = theControl;
            TrackControl (theControl, thePoint, gScrollAction);
            dragged_sb = NULL;
        }
        else {
            dragged_sb = theControl;
            TrackControl (theControl, thePoint, NULL);
            gui_mac_drag_thumb (theControl, 0);
            dragged_sb = NULL;
        }
    }
    else {
        vimModifiers = EventModifiers2VimMouseModifiers (theEvent->modifiers);
        vimMouseButton = MOUSE_LEFT;
        clickIsPopup = FALSE;
        if (mouse_model_popup () && IsShowContextualMenuClick (theEvent)) {
            vimMouseButton = MOUSE_RIGHT;
            vimModifiers &= ~MOUSE_CTRL;
            clickIsPopup = TRUE;
        }
        dblClick = ((theEvent->when - lastMouseTick) < GetDblTime ());
        gui_send_mouse_event (vimMouseButton, thePoint.h, thePoint.v, dblClick, vimModifiers);
        {
            SetRect (& dragRect, FILL_X (X_2_COL (thePoint.h)), FILL_Y (Y_2_ROW (thePoint.v)), FILL_X (X_2_COL (thePoint.h) + 1), FILL_Y (Y_2_ROW (thePoint.v) + 1));
            dragRectEnbl = TRUE;
            dragRectControl = kCreateRect;
        }
    }
}

pascal void gui_mac_drag_thumb (ControlHandle theControl, short  partCode) {
    scrollbar_T *sb;
    int value, dragging;
    ControlHandle theControlToUse;
    int dont_scroll_save = dont_scroll;
    theControlToUse = dragged_sb;
    sb = gui_find_scrollbar ((long ) GetControlReference (theControlToUse));
    if (sb == NULL)
        return;
    value = GetControl32BitValue (theControlToUse);
    dragging = (partCode != 0);
    dont_scroll = !allow_scrollbar;
    gui_drag_scrollbar (sb, value, dragging);
    dont_scroll = dont_scroll_save;
}

void gui_mch_invert_rectangle (int r, int c, int nr, int nc) {
    Rect rc;
    rc.left = FILL_X (c);
    rc.top = FILL_Y (r);
    rc.right = rc.left + nc * gui.char_width;
    rc.bottom = rc.top + nr * gui.char_height;
    InvertRect (& rc);
}

void gui_mch_clear_all (void) {
    Rect rc;
    rc.left = 0;
    rc.top = 0;
    rc.right = Columns * gui.char_width + 2 * gui.border_width;
    rc.bottom = Rows * gui.char_height + 2 * gui.border_width;
    gui_mch_set_bg_color (gui.back_pixel);
    EraseRect (& rc);
}

void gui_mch_set_bg_color (guicolor_T color) {
    RGBColor TheColor;
    TheColor.red = Red (color) * 0x0101;
    TheColor.green = Green (color) * 0x0101;
    TheColor.blue = Blue (color) * 0x0101;
    RGBBackColor (& TheColor);
}

void gui_mch_clear_block (int row1, int col1, int row2, int col2) {
    Rect rc;
    rc.left = FILL_X (col1);
    rc.top = FILL_Y (row1);
    rc.right = FILL_X (col2 +1) + (col2 == Columns - 1);
    rc.bottom = FILL_Y (row2 +1);
    gui_mch_set_bg_color (gui.back_pixel);
    EraseRect (& rc);
}

void gui_mch_delete_lines (int row, int num_lines) {
    Rect rc;
    rc.left = FILL_X (gui.scroll_region_left);
    rc.right = FILL_X (gui.scroll_region_right + 1);
    rc.top = FILL_Y (row);
    rc.bottom = FILL_Y (gui.scroll_region_bot + 1);
    gui_mch_set_bg_color (gui.back_pixel);
    ScrollRect (& rc, 0, - num_lines * gui.char_height, (RgnHandle) nil);
    gui_clear_block (gui.scroll_region_bot - num_lines + 1, gui.scroll_region_left, gui.scroll_region_bot, gui.scroll_region_right);
}

void gui_mch_insert_lines (int row, int num_lines) {
    Rect rc;
    rc.left = FILL_X (gui.scroll_region_left);
    rc.right = FILL_X (gui.scroll_region_right + 1);
    rc.top = FILL_Y (row);
    rc.bottom = FILL_Y (gui.scroll_region_bot + 1);
    gui_mch_set_bg_color (gui.back_pixel);
    ScrollRect (& rc, 0, gui.char_height * num_lines, (RgnHandle) nil);
    if (gui.cursor_row >= gui.row && gui.cursor_col >= gui.scroll_region_left && gui.cursor_col <= gui.scroll_region_right) {
        if (gui.cursor_row <= gui.scroll_region_bot - num_lines)
            gui.cursor_row += num_lines;
        else if (gui.cursor_row <= gui.scroll_region_bot)
            gui.cursor_is_valid = FALSE;
    }
    gui_clear_block (row, gui.scroll_region_left, row + num_lines - 1, gui.scroll_region_right);
}

void gui_mch_flash (int msec) {
    Rect rc;
    rc.left = 0;
    rc.top = 0;
    rc.right = gui.num_cols * gui.char_width;
    rc.bottom = gui.num_rows * gui.char_height;
    InvertRect (& rc);
    ui_delay ((long) msec, TRUE);
    InvertRect (& rc);
}

void gui_mch_menu_grey (vimmenu_T *menu, int grey) {
    short  index = gui_mac_get_menu_item_index (menu);
    if (grey) {
        if (menu->children)
            DisableMenuItem (menu->submenu_handle, index);
        if (menu->parent)
            if (menu->parent->submenu_handle)
                DisableMenuItem (menu->parent->submenu_handle, index);
    }
    else {
        if (menu->children)
            EnableMenuItem (menu->submenu_handle, index);
        if (menu->parent)
            if (menu->parent->submenu_handle)
                EnableMenuItem (menu->parent->submenu_handle, index);
    }
}

short  gui_mac_get_menu_item_index (vimmenu_T *pMenu) {
    short  index;
    short  itemIndex = -1;
    vimmenu_T *pBrother;
    if (pMenu->parent) {
        pBrother = pMenu->parent->children;
        index = 1;
        while ((pBrother) &&(itemIndex == -1)) {
            if (pBrother == pMenu)
                itemIndex = index;
            index++;
            pBrother = pBrother->next;
        }
    }
    return itemIndex;
}

void gui_mch_menu_hidden (vimmenu_T *menu, int hidden) {
    gui_mch_menu_grey (menu, hidden);
}

void gui_mch_draw_menubar (void) {
    DrawMenuBar ();
}

void gui_mch_flush (void) {
}

void gui_mch_start_blink (void) {
    gui_update_cursor (TRUE, FALSE);
}

void gui_mch_set_font (GuiFont font) {
    TextSize (font >> 16);
    TextFont (font & 0xFFFF);
}

void gui_mch_set_fg_color (guicolor_T color) {
    RGBColor TheColor;
    TheColor.red = Red (color) * 0x0101;
    TheColor.green = Green (color) * 0x0101;
    TheColor.blue = Blue (color) * 0x0101;
    RGBForeColor (& TheColor);
}

void gui_mch_set_sp_color (guicolor_T color) {
    specialColor.red = Red (color) * 0x0101;
    specialColor.green = Green (color) * 0x0101;
    specialColor.blue = Blue (color) * 0x0101;
}

void gui_mch_draw_string (int row, int col, char_u *s, int len, int flags) {
    draw_string_QD (row, col, s, len, flags);
}

static void draw_undercurl (int flags, int row, int col, int cells) {
    int x;
    int offset;
    const static int val [8] = {1, 0, 0, 0, 1, 2, 2, 2};
    int y = FILL_Y (row +1) - 1;
    RGBForeColor (& specialColor);
    offset = val[FILL_X (col) % 8];
    MoveTo (FILL_X (col), y - offset);
    for (x = FILL_X (col); x < FILL_X (col +cells); ++x) {
        offset = val[x % 8];
        LineTo (x, y - offset);
    }
}

static void draw_string_QD (int row, int col, char_u *s, int len, int flags) {
    if (gMacSystemVersion >= 0x1020) {
        UInt32 qd_flags = (p_antialias ? kQDUseCGTextRendering | kQDUseCGTextMetrics : 0);
        QDSwapTextFlags (qd_flags);
    }
    if (((gMacSystemVersion >= 0x1020 && p_antialias) || p_linespace != 0) && !(flags & DRAW_TRANSP)) {
        Rect rc;
        rc.left = FILL_X (col);
        rc.top = FILL_Y (row);
        rc.right = FILL_X (col +len) + (col + len == Columns);
        rc.bottom = FILL_Y (row +1);
        EraseRect (& rc);
    }
    if (gMacSystemVersion >= 0x1020 && p_antialias) {
        StyleParameter face;
        face = normal;
        if (flags & DRAW_BOLD)
            face |= bold;
        if (flags & DRAW_UNDERL)
            face |= underline;
        TextFace (face);
        TextMode (srcOr);
        MoveTo (TEXT_X (col), TEXT_Y (row));
        DrawText ((char *) s, 0, len);
    }
    else {
        TextMode (srcCopy);
        TextFace (normal);
        if (flags & DRAW_TRANSP) {
            TextMode (srcOr);
        }
        MoveTo (TEXT_X (col), TEXT_Y (row));
        DrawText ((char *) s, 0, len);
        if (flags & DRAW_BOLD) {
            TextMode (srcOr);
            MoveTo (TEXT_X (col) + 1, TEXT_Y (row));
            DrawText ((char *) s, 0, len);
        }
        if (flags & DRAW_UNDERL) {
            MoveTo (FILL_X (col), FILL_Y (row + 1) - 1);
            LineTo (FILL_X (col + len) - 1, FILL_Y (row + 1) - 1);
        }
        if (flags & DRAW_STRIKE) {
            MoveTo (FILL_X (col), FILL_Y (row + 1) - gui.char_height / 2);
            LineTo (FILL_X (col + len) - 1, FILL_Y (row + 1) - gui.char_height / 2);
        }
    }
    if (flags & DRAW_UNDERC)
        draw_undercurl (flags, row, col, len);
}

void gui_mch_getmouse (int *x, int *y) {
    Point where;
    GetMouse (& where);
    *x = where.h;
    *y = where.v;
}

void gui_mch_set_blinking (long  wait, long  on, long  off) {
}

void gui_mch_draw_hollow_cursor (guicolor_T color) {
    Rect rc;
    rc.left = FILL_X (gui.col);
    rc.top = FILL_Y (gui.row);
    rc.right = rc.left + gui.char_width;
    rc.bottom = rc.top + gui.char_height;
    gui_mch_set_fg_color (color);
    FrameRect (& rc);
}

void gui_mch_draw_part_cursor (int w, int h, guicolor_T color) {
    Rect rc;
    if (CURSOR_BAR_RIGHT)
        rc.left = FILL_X (gui.col + 1) - w;
    else
        rc.left = FILL_X (gui.col);
    rc.top = FILL_Y (gui.row) + gui.char_height - h;
    rc.right = rc.left + w;
    rc.bottom = rc.top + h;
    gui_mch_set_fg_color (color);
    FrameRect (& rc);
}

void gui_mch_stop_blink (int may_call_gui_update_cursor) {
    if (may_call_gui_update_cursor)
        gui_update_cursor (TRUE, FALSE);
}

int clip_mch_own_selection (VimClipboard *cbd) {
    return OK;
}

void clip_mch_set_selection (VimClipboard *cbd) {
    Handle textOfClip;
    long  scrapSize;
    int type;
    ScrapRef scrap;
    char_u *str = NULL;
    if (!cbd->owned)
        return;
    clip_get_selection (cbd);
    cbd->owned = FALSE;
    type = clip_convert_selection (&str, (long_u *) &scrapSize, cbd);
    if (type >= 0) {
        ClearCurrentScrap ();
        textOfClip = NewHandle (scrapSize +1);
        HLock (textOfClip);
        **textOfClip = type;
        mch_memmove (* textOfClip + 1, str, scrapSize);
        GetCurrentScrap (& scrap);
        PutScrapFlavor (scrap, SCRAPTEXTFLAVOR, kScrapFlavorMaskNone, scrapSize, * textOfClip + 1);
        PutScrapFlavor (scrap, VIMSCRAPFLAVOR, kScrapFlavorMaskNone, scrapSize + 1, * textOfClip);
        HUnlock (textOfClip);
        DisposeHandle (textOfClip);
    }
    vim_free (str);
}

int gui_mch_haskey (char_u *name) {
    int i;
    for (i = 0; special_keys[i].key_sym != (KeySym) 0; i++)
        if (name[0] == special_keys[i].vim_code0 && name[1] == special_keys[i].vim_code1)
            return OK;
    return FAIL;
}

int gui_mch_get_winpos (int *x, int *y) {
    Rect bounds;
    OSStatus status;
    status = GetWindowBounds (gui.VimWindow, kWindowStructureRgn, &bounds);
    if (status != noErr)
        return FAIL;
    *x = bounds.left;
    *y = bounds.top;
    return OK;
}

void gui_mch_get_screen_dimensions (int *screen_w, int *screen_h) {
    GDHandle dominantDevice = GetMainDevice ();
    Rect screenRect = (**dominantDevice).gdRect;
    *screen_w = screenRect.right - 10;
    *screen_h = screenRect.bottom - 40;
}

void gui_mch_set_shellsize (int width, int height, int min_width, int min_height, int base_width, int base_height, int direction) {
    CGrafPtr VimPort;
    Rect VimBound;
    if (gui.which_scrollbars[SBAR_LEFT]) {
        VimPort = GetWindowPort (gui.VimWindow);
        GetPortBounds (VimPort, & VimBound);
        VimBound.left = -gui.scrollbar_width;
        SetPortBounds (VimPort, & VimBound);
    }
    else {
        VimPort = GetWindowPort (gui.VimWindow);
        GetPortBounds (VimPort, & VimBound);
        VimBound.left = 0;
        SetPortBounds (VimPort, & VimBound);
    }
    SizeWindow (gui.VimWindow, width, height, TRUE);
    gui_resize_shell (width, height);
}

void gui_mch_set_text_area_pos (int x, int y, int w, int h) {
    Rect VimBound;
    GetWindowBounds (gui.VimWindow, kWindowGlobalPortRgn, & VimBound);
    if (gui.which_scrollbars[SBAR_LEFT]) {
        VimBound.left = -gui.scrollbar_width + 1;
    }
    else {
        VimBound.left = 0;
    }
    SetWindowBounds (gui.VimWindow, kWindowGlobalPortRgn, & VimBound);
    ShowWindow (gui.VimWindow);
}

void gui_mch_set_menu_pos (int x, int y, int w, int h) {
}

void gui_mch_set_scrollbar_pos (scrollbar_T *sb, int x, int y, int w, int h) {
    gui_mch_set_bg_color (gui.back_pixel);
    if (sb == &gui.bottom_sbar)
        h += 1;
    else
        w += 1;
    if (gui.which_scrollbars[SBAR_LEFT])
        x -= 15;
    MoveControl (sb -> id, x, y);
    SizeControl (sb -> id, w, h);
}

void gui_mch_set_scrollbar_thumb (scrollbar_T *sb, long  val, long  size, long  max) {
    SetControl32BitMaximum (sb -> id, max);
    SetControl32BitMinimum (sb -> id, 0);
    SetControl32BitValue (sb -> id, val);
    SetControlViewSize (sb -> id, size);
}

void gui_mch_enable_scrollbar (scrollbar_T *sb, int flag) {
    if (flag)
        ShowControl (sb->id);
    else
        HideControl (sb->id);
}

void gui_mch_set_winpos (int x, int y) {
    MoveWindowStructure (gui.VimWindow, x, y);
}

void gui_mch_create_scrollbar (scrollbar_T *sb, int orient) {
    Rect bounds;
    bounds.top = -16;
    bounds.bottom = -10;
    bounds.right = -10;
    bounds.left = -16;
    sb->id = NewControl (gui.VimWindow, &bounds, "\pScrollBar", TRUE, 0, 0, 0, kControlScrollBarLiveProc, (long ) sb->ident);
}

void gui_mch_destroy_scrollbar (scrollbar_T *sb) {
    gui_mch_set_bg_color (gui.back_pixel);
    DisposeControl (sb -> id);
}

void gui_mch_enable_menu (int flag) {
}

void gui_mch_toggle_tearoffs (int enable) {
}

int gui_mch_dialog (int type, char_u *title, char_u *message, char_u *buttons, int dfltbutton, char_u *textfield, int ex_cmd) {
    Handle buttonDITL;
    Handle iconDITL;
    Handle inputDITL;
    Handle messageDITL;
    Handle itemHandle;
    Handle iconHandle;
    DialogPtr theDialog;
    char_u len;
    char_u PascalTitle [256];
    char_u name [256];
    GrafPtr oldPort;
    short  itemHit;
    char_u *buttonChar;
    short  hotKeys [256];
    char_u aHotKey;
    Rect box;
    short  button;
    short  lastButton;
    short  itemType;
    short  useIcon;
    short  width;
    short  totalButtonWidth = 0;
    short  widestButton = 0;
    short  dfltButtonEdge = 20;
    short  dfltElementSpacing = 13;
    short  dfltIconSideSpace = 23;
    short  maximumWidth = 400;
    short  maxButtonWidth = 175;
    short  vertical;
    short  dialogHeight;
    short  messageLines = 3;
    FontInfo textFontInfo;
    vgmDlgItm iconItm;
    vgmDlgItm messageItm;
    vgmDlgItm inputItm;
    vgmDlgItm buttonItm;
    WindowRef theWindow;
    ModalFilterUPP dialogUPP;
    vertical = (vim_strchr (p_go, GO_VERTICAL) != NULL);
    theDialog = GetNewDialog (129, nil, (WindowRef) -1);
    theWindow = GetDialogWindow (theDialog);
    HideWindow (theWindow);
    GetPort (& oldPort);
    SetPortDialogPort (theDialog);
    GetFontInfo (& textFontInfo);
    if (title != NULL) {
        (void) C2PascalString (title, &PascalTitle);
        SetWTitle (theWindow, PascalTitle);
    }
    buttonDITL = GetResource ('DITL', 130);
    buttonChar = buttons;
    button = 0;
    vim_memset (hotKeys, 0, sizeof (hotKeys));
    for (; *buttonChar != 0;) {
        button++;
        len = 0;
        for (; ((*buttonChar != DLG_BUTTON_SEP) && (*buttonChar != 0) && (len < 255)); buttonChar++) {
            if (*buttonChar != DLG_HOTKEY_CHAR)
                name[++len] = *buttonChar;
            else {
                aHotKey = (char_u) *(buttonChar + 1);
                if (aHotKey >= 'A' && aHotKey <= 'Z')
                    aHotKey = (char_u) ((int) aHotKey + (int) 'a' - (int) 'A');
                hotKeys[aHotKey] = button;
            }
        }
        if (*buttonChar != 0)
            buttonChar++;
        name[0] = len;
        AppendDITL (theDialog, buttonDITL, overlayDITL);
        macSetDialogItemText (theDialog, button, name);
        width = StringWidth (name) + 2 * dfltButtonEdge;
        if (width > maxButtonWidth)
            width = maxButtonWidth;
        macSizeDialogItem (theDialog, button, width, 0);
        totalButtonWidth += width;
        if (width > widestButton)
            widestButton = width;
    }
    ReleaseResource (buttonDITL);
    lastButton = button;
    iconItm.idx = lastButton + 1;
    iconDITL = GetResource ('DITL', 131);
    switch (type) {
    case VIM_GENERIC :
    case VIM_INFO :
    case VIM_QUESTION :
        useIcon = kNoteIcon;
        break;
    case VIM_WARNING :
        useIcon = kCautionIcon;
        break;
    case VIM_ERROR :
        useIcon = kStopIcon;
        break;
    default :
        useIcon = kStopIcon;
    }
    AppendDITL (theDialog, iconDITL, overlayDITL);
    ReleaseResource (iconDITL);
    GetDialogItem (theDialog, iconItm.idx, & itemType, & itemHandle, & box);
    iconHandle = GetIcon (useIcon);
    SetDialogItem (theDialog, iconItm.idx, itemType, iconHandle, & box);
    messageItm.idx = lastButton + 2;
    messageDITL = GetResource ('DITL', 132);
    AppendDITL (theDialog, messageDITL, overlayDITL);
    ReleaseResource (messageDITL);
    GetDialogItem (theDialog, messageItm.idx, & itemType, & itemHandle, & box);
    (void) C2PascalString (message, &name);
    SetDialogItemText (itemHandle, name);
    messageItm.width = StringWidth (name);
    if (textfield != NULL) {
        inputItm.idx = lastButton + 3;
        inputDITL = GetResource ('DITL', 132);
        AppendDITL (theDialog, inputDITL, overlayDITL);
        ReleaseResource (inputDITL);
        GetDialogItem (theDialog, inputItm.idx, & itemType, & itemHandle, & box);
        (void) C2PascalString (textfield, &name);
        SetDialogItemText (itemHandle, name);
        inputItm.width = StringWidth (name);
        gDialogHotKeys = NULL;
    }
    else
        gDialogHotKeys = (short  *) &hotKeys;
    SetDialogDefaultItem (theDialog, dfltbutton);
    SetDialogCancelItem (theDialog, 0);
    if (totalButtonWidth > maximumWidth)
        vertical = TRUE;
    macMoveDialogItem (theDialog, iconItm.idx, dfltIconSideSpace, dfltElementSpacing, & box);
    iconItm.box.right = box.right;
    iconItm.box.bottom = box.bottom;
    messageItm.box.left = iconItm.box.right + dfltIconSideSpace;
    macSizeDialogItem (theDialog, messageItm.idx, 0, messageLines * (textFontInfo.ascent + textFontInfo.descent));
    macMoveDialogItem (theDialog, messageItm.idx, messageItm.box.left, dfltElementSpacing, & messageItm.box);
    if (textfield != NULL) {
        inputItm.box.left = messageItm.box.left;
        inputItm.box.top = messageItm.box.bottom + dfltElementSpacing;
        macSizeDialogItem (theDialog, inputItm.idx, 0, textFontInfo.ascent + textFontInfo.descent);
        macMoveDialogItem (theDialog, inputItm.idx, inputItm.box.left, inputItm.box.top, & inputItm.box);
        GetDialogItem (theDialog, inputItm.idx, & itemType, & itemHandle, & inputItm.box);
        SetDialogItem (theDialog, inputItm.idx, kEditTextDialogItem, itemHandle, & inputItm.box);
        SelectDialogItemText (theDialog, inputItm.idx, 0, 32767);
    }
    if (textfield != NULL) {
        buttonItm.box.left = inputItm.box.left;
        buttonItm.box.top = inputItm.box.bottom + dfltElementSpacing;
    }
    else {
        buttonItm.box.left = messageItm.box.left;
        buttonItm.box.top = messageItm.box.bottom + dfltElementSpacing;
    }
    for (button = 1; button <= lastButton; button++) {
        macMoveDialogItem (theDialog, button, buttonItm.box.left, buttonItm.box.top, & box);
        if (vertical) {
            macSizeDialogItem (theDialog, button, widestButton, 0);
            GetDialogItem (theDialog, button, & itemType, & itemHandle, & box);
        }
        if (vertical)
            buttonItm.box.top = box.bottom + dfltElementSpacing;
        else
            buttonItm.box.left = box.right + dfltElementSpacing;
    }
    dialogHeight = box.bottom + dfltElementSpacing;
    SizeWindow (theWindow, maximumWidth, dialogHeight, TRUE);
    AutoSizeDialog (theDialog);
    ShowWindow (theWindow);
    SelectWindow (theWindow);
    dialogUPP = NewModalFilterUPP (DialogHotkeyFilterProc);
    do {
        ModalDialog (dialogUPP, & itemHit);
    }
    while ((itemHit < 1) || (itemHit > lastButton));
    if (textfield != NULL) {
        GetDialogItem (theDialog, inputItm.idx, & itemType, & itemHandle, & box);
        GetDialogItemText (itemHandle, (char_u *) & name);
        vim_strncpy (textfield, & name [1], name [0]);
    }
    SetPort (oldPort);
    DisposeRoutineDescriptor (dialogUPP);
    DisposeDialog (theDialog);
    return itemHit;
}

int C2PascalString (char_u *CString, Str255 *PascalString) {
    char_u *PascalPtr = (char_u *) PascalString;
    int len;
    int i;
    PascalPtr[0] = 0;
    if (CString == NULL)
        return 0;
    len = STRLEN (CString);
    if (len > 255)
        len = 255;
    for (i = 0; i < len; i++)
        PascalPtr[i + 1] = CString[i];
    PascalPtr[0] = len;
    return 0;
}

static void macSetDialogItemText (DialogRef theDialog, short  itemNumber, Str255 itemName) {
    short  itemType;
    Handle itemHandle;
    Rect itemBox;
    GetDialogItem (theDialog, itemNumber, & itemType, & itemHandle, & itemBox);
    if (itemType & kControlDialogItem)
        SetControlTitle ((ControlRef) itemHandle, itemName);
    else
        SetDialogItemText (itemHandle, itemName);
}

static void macSizeDialogItem (DialogRef theDialog, short  itemNumber, short  width, short  height) {
    short  itemType;
    Handle itemHandle;
    Rect itemBox;
    GetDialogItem (theDialog, itemNumber, & itemType, & itemHandle, & itemBox);
    if (width == 0)
        width = itemBox.right - itemBox.left;
    if (height == 0)
        height = itemBox.bottom - itemBox.top;
    itemBox.right = itemBox.left + width;
    itemBox.bottom = itemBox.top + height;
    if (itemType & kControlDialogItem)
        SizeControl ((ControlRef) itemHandle, width, height);
    SetDialogItem (theDialog, itemNumber, itemType, itemHandle, & itemBox);
}

static void macMoveDialogItem (DialogRef theDialog, short  itemNumber, short  X, short  Y, Rect *inBox) {
    short  itemType;
    Handle itemHandle;
    Rect localBox;
    Rect *itemBox = &localBox;
    if (inBox != nil)
        itemBox = inBox;
    GetDialogItem (theDialog, itemNumber, & itemType, & itemHandle, itemBox);
    OffsetRect (itemBox, - itemBox -> left, - itemBox -> top);
    OffsetRect (itemBox, X, Y);
    if (1)
        MoveControl ((ControlRef) itemHandle, X, Y);
    SetDialogItem (theDialog, itemNumber, itemType, itemHandle, itemBox);
}

static pascal Boolean DialogHotkeyFilterProc (DialogRef theDialog, EventRecord *event, DialogItemIndex *itemHit) {
    char_u keyHit;
    if (event->what == keyDown || event->what == autoKey) {
        keyHit = (event->message & charCodeMask);
        if (gDialogHotKeys && gDialogHotKeys[keyHit]) {
            *itemHit = gDialogHotKeys[keyHit];
            event->what = kEventControlSimulateHit;
            return true;
        }
        return StdFilterProc (theDialog, event, itemHit);
    }
    return false;
}

int gui_mch_init (void) {
    Rect windRect;
    MenuHandle pomme;
    EventHandlerRef mouseWheelHandlerRef;
    EventTypeSpec eventTypeSpec;
    ControlRef rootControl;
    if (Gestalt (gestaltSystemVersion, &gMacSystemVersion) != noErr)
        gMacSystemVersion = 0x1000;
    display_errors ();
    gui.norm_pixel = 0x00000000;
    gui.back_pixel = 0x00FFFFFF;
    set_normal_colors ();
    gui_check_colors ();
    gui.def_norm_pixel = gui.norm_pixel;
    gui.def_back_pixel = gui.back_pixel;
    highlight_gui_started ();
    gui.menu_height = 0;
    gui.scrollbar_height = gui.scrollbar_width = 15;
    gui.border_offset = gui.border_width = 2;
    vim_setenv ((char_u *) "QDTEXT_MINSIZE", (char_u *) "1");
    eventTypeSpec.eventClass = kEventClassMouse;
    eventTypeSpec.eventKind = kEventMouseWheelMoved;
    mouseWheelHandlerUPP = NewEventHandlerUPP (gui_mac_mouse_wheel);
    if (noErr != InstallApplicationEventHandler (mouseWheelHandlerUPP, 1, &eventTypeSpec, NULL, &mouseWheelHandlerRef)) {
        mouseWheelHandlerRef = NULL;
        DisposeEventHandlerUPP (mouseWheelHandlerUPP);
        mouseWheelHandlerUPP = NULL;
    }
    return OK;
}

static OSErr receiveHandler (WindowRef theWindow, void *handlerRefCon, DragRef theDrag) {
    int x, y;
    int_u modifiers;
    char_u **fnames = NULL;
    int count;
    int i, j;
    {
        Point point;
        SInt16 mouseUpModifiers;
        UInt16 countItem;
        GetDragMouse (theDrag, & point, NULL);
        GlobalToLocal (& point);
        x = point.h;
        y = point.v;
        GetDragModifiers (theDrag, NULL, NULL, & mouseUpModifiers);
        modifiers = EventModifiers2VimMouseModifiers (mouseUpModifiers);
        CountDragItems (theDrag, & countItem);
        count = countItem;
    }
    fnames = (char_u **) alloc (count * sizeof (char_u *));
    if (fnames == NULL)
        return dragNotAcceptedErr;
    for (i = j = 0; i < count; ++i) {
        DragItemRef item;
        OSErr err;
        Size size;
        FlavorType type = flavorTypeHFS;
        HFSFlavor hfsFlavor;
        fnames[i] = NULL;
        GetDragItemReferenceNumber (theDrag, i + 1, & item);
        err = GetFlavorDataSize (theDrag, item, type, &size);
        if (err != noErr || size > sizeof (hfsFlavor))
            continue;
        err = GetFlavorData (theDrag, item, type, &hfsFlavor, &size, 0);
        if (err != noErr)
            continue;
        fnames[j++] = FullPathFromFSSpec_save (hfsFlavor.fileSpec);
    }
    count = j;
    gui_handle_drop (x, y, modifiers, fnames, count);
    PostEvent (mouseUp, 0);
    return noErr;
}

int_u EventModifiers2VimMouseModifiers (EventModifiers macModifiers) {
    int_u vimModifiers = 0x00;
    if (macModifiers & (shiftKey | rightShiftKey))
        vimModifiers |= MOUSE_SHIFT;
    if (macModifiers & (controlKey | rightControlKey))
        vimModifiers |= MOUSE_CTRL;
    if (macModifiers & (optionKey | rightOptionKey))
        vimModifiers |= MOUSE_ALT;
    return (vimModifiers);
}

char_u *FullPathFromFSSpec_save (FSSpec file) {
    CInfoPBRec theCPB;
    char_u fname [256];
    char_u *filenamePtr = fname;
    OSErr error;
    int folder = 1;
    Str255 directoryName;
    char_u temporary [255];
    char_u *temporaryPtr = temporary;
    vim_strncpy (filenamePtr, & file.name [1], file.name [0]);
    theCPB.dirInfo.ioFDirIndex = 0;
    theCPB.dirInfo.ioNamePtr = file.name;
    theCPB.dirInfo.ioVRefNum = file.vRefNum;
    theCPB.dirInfo.ioDrDirID = file.parID;
    error = PBGetCatInfo (&theCPB, false);
    if ((error) &&(error != fnfErr))
        return NULL;
    if (((theCPB.hFileInfo.ioFlAttrib & ioDirMask) == 0) || (error))
        folder = 0;
    else
        folder = 1;
    theCPB.dirInfo.ioNamePtr = directoryName;
    theCPB.dirInfo.ioDrParID = file.parID;
    theCPB.dirInfo.ioDrDirID = file.parID;
    if ((TRUE) &&(file.parID != fsRtDirID))
        do {
            theCPB.dirInfo.ioFDirIndex = -1;
            theCPB.dirInfo.ioVRefNum = file.vRefNum;
            theCPB.dirInfo.ioDrDirID = theCPB.dirInfo.ioDrParID;
            error = PBGetCatInfo (&theCPB, false);
            if (error)
                return NULL;
            STRCPY (temporaryPtr, filenamePtr);
            vim_strncpy (filenamePtr, & directoryName [1], directoryName [0]);
            STRCAT (filenamePtr, ":");
            STRCAT (filenamePtr, temporaryPtr);
        }
        while (theCPB.dirInfo.ioDrDirID != fsRtDirID);
    theCPB.dirInfo.ioFDirIndex = -1;
    theCPB.dirInfo.ioVRefNum = file.vRefNum;
    theCPB.dirInfo.ioDrDirID = theCPB.dirInfo.ioDrParID;
    error = PBGetCatInfo (&theCPB, false);
    if (error)
        return NULL;
    {
        STRCPY (temporaryPtr, filenamePtr);
        vim_strncpy (filenamePtr, & directoryName [1], directoryName [0]);
        STRCAT (filenamePtr, ":");
        STRCAT (filenamePtr, temporaryPtr);
    }
    if (folder)
        STRCAT (fname, ":");
    return (vim_strsave (fname));
}

pascal void gui_mac_scroll_action (ControlHandle theControl, short  partCode) {
    scrollbar_T *sb, *sb_info;
    long  data;
    long  value;
    int page;
    int dragging = FALSE;
    int dont_scroll_save = dont_scroll;
    sb = gui_find_scrollbar ((long ) GetControlReference (theControl));
    if (sb == NULL)
        return;
    if (sb->wp != NULL) {
        sb_info = &sb->wp->w_scrollbars[0];
        if (sb_info->size > 5)
            page = sb_info->size - 2;
        else
            page = sb_info->size;
    }
    else {
        sb_info = sb;
        page = curwin->w_width - 5;
    }
    switch (partCode) {
    case kControlUpButtonPart :
        data = -1;
        break;
    case kControlDownButtonPart :
        data = 1;
        break;
    case kControlPageDownPart :
        data = page;
        break;
    case kControlPageUpPart :
        data = -page;
        break;
    default :
        data = 0;
        break;
    }
    value = sb_info->value + data;
    dont_scroll = !allow_scrollbar;
    gui_drag_scrollbar (sb, value, dragging);
    dont_scroll = dont_scroll_save;
    out_flush ();
    gui_mch_set_scrollbar_thumb (sb, value, sb_info -> size, sb_info -> max);
}

static void InstallFontPanelHandler (void) {
    EventTypeSpec eventTypes [2];
    EventHandlerUPP handlerUPP;
    eventTypes[0].eventClass = kEventClassFont;
    eventTypes[0].eventKind = kEventFontSelection;
    eventTypes[1].eventClass = kEventClassFont;
    eventTypes[1].eventKind = kEventFontPanelClosed;
    handlerUPP = NewEventHandlerUPP (FontPanelHandler);
    InstallApplicationEventHandler (handlerUPP, 2, eventTypes, NULL, NULL);
}

#define FONT_STYLE_BUFFER_SIZE 32

static OSStatus FontPanelHandler (EventHandlerCallRef inHandlerCallRef, EventRef inEvent, void *inUserData) {
    if (GetEventKind (inEvent) == kEventFontPanelClosed) {
        gFontPanelInfo.isPanelVisible = false;
        return noErr;
    }
    if (GetEventKind (inEvent) == kEventFontSelection) {
        OSStatus status;
        FMFontFamily newFamily;
        FMFontSize newSize;
        FMFontStyle newStyle;
        status = GetEventParameter (inEvent, kEventParamFMFontFamily, typeFMFontFamily, NULL, sizeof (FMFontFamily), NULL, &newFamily);
        if (status == noErr)
            gFontPanelInfo.family = newFamily;
        status = GetEventParameter (inEvent, kEventParamFMFontSize, typeFMFontSize, NULL, sizeof (FMFontSize), NULL, &newSize);
        if (status == noErr)
            gFontPanelInfo.size = newSize;
        status = GetEventParameter (inEvent, kEventParamFMFontStyle, typeFMFontStyle, NULL, sizeof (FMFontStyle), NULL, &newStyle);
        if (status == noErr)
            gFontPanelInfo.style = newStyle;
    }
    return noErr;
}

void gui_mch_free_font (GuiFont font) {
}

GuiFont gui_mch_get_font (char_u *name, int giveErrorIfMissing) {
    GuiFont font;
    font = gui_mac_find_font (name);
    if (font == NOFONT) {
        if (giveErrorIfMissing)
            EMSG2 (_ (e_font), name);
        return NOFONT;
    }
    return font;
}

GuiFont gui_mac_find_font (char_u *font_name) {
    char_u c;
    char_u *p;
    char_u pFontName [256];
    Str255 systemFontname;
    short  font_id;
    short  size = 9;
    GuiFont font;
    for (p = font_name; ((*p != 0) && (*p != ':')); p++)
        ;
    c = *p;
    *p = 0;
    fontNamePtr = C2Pascal_save_and_remove_backslash (font_name);
    GetFNum (fontNamePtr, & font_id);
    if (font_id == 0) {
        if (FMGetFontFamilyName (systemFont, systemFontname) != noErr)
            return NOFONT;
        if (!EqualString (pFontName, systemFontname, false, false))
            return NOFONT;
    }
    if (*p == ':') {
        p++;
        while (*p) {
            switch (*p++) {
            case 'h' :
                size = points_to_pixels (p, &p, TRUE);
                break;
            }
            while (*p == ':')
                p++;
        }
    }
    if (size < 1)
        size = 1;
    font = (size << 16) + ((long ) font_id & 0xFFFF);
    return font;
}

char_u *C2Pascal_save_and_remove_backslash (char_u *Cstring) {
    char_u *PascalString;
    int len;
    char_u *p, *c;
    len = STRLEN (Cstring);
    if (len > 255)
        len = 255;
    PascalString = alloc (len +1);
    if (PascalString != NULL) {
        for (c = Cstring, p = PascalString + 1, len = 0; (*c != 0) && (len < 255); c++) {
            if ((*c == '\\') && (c[1] != 0)) {
                c++;
            }
            *p = *c;
            p++;
            len++;
        }
        PascalString[0] = len;
    }
    return PascalString;
}

static int points_to_pixels (char_u *str, char_u **end, int vertical) {
    int pixels;
    int points = 0;
    int divisor = 0;
    while (*str) {
        if (*str == '.' && divisor == 0) {
            divisor = 1;
            continue;
        }
        if (!isdigit (*str))
            break;
        points *= 10;
        points += *str - '0';
        divisor *= 10;
        ++str;
    }
    if (divisor == 0)
        divisor = 1;
    pixels = points / divisor;
    *end = str;
    return pixels;
}

int gui_mch_init_font (char_u *font_name, int fontset) {
    Str255 suggestedFont = "\pMonaco";
    int suggestedSize = 10;
    FontInfo font_info;
    short  font_id;
    GuiFont font;
    char_u used_font_name [512];
    if (font_name == NULL) {
        GetFNum (suggestedFont, & font_id);
        if (font_id == 0) {
            font_id = GetAppFont ();
            STRCPY (used_font_name, "default");
        }
        else
            STRCPY (used_font_name, "Monaco");
        font = (suggestedSize << 16) + ((long ) font_id & 0xFFFF);
    }
    else if (STRCMP (font_name, "*") == 0) {
        char_u *new_p_guifont;
        font = gui_mac_select_font (used_font_name);
        if (font == NOFONT)
            return FAIL;
        new_p_guifont = alloc (STRLEN (used_font_name) +1);
        if (new_p_guifont != NULL) {
            STRCPY (new_p_guifont, used_font_name);
            vim_free (p_guifont);
            p_guifont = new_p_guifont;
            for (; *new_p_guifont; ++new_p_guifont) {
                if (*new_p_guifont == ' ')
                    *new_p_guifont = '_';
            }
        }
    }
    else {
        font = gui_mac_find_font (font_name);
        vim_strncpy (used_font_name, font_name, sizeof (used_font_name) - 1);
        if (font == NOFONT)
            return FAIL;
    }
    gui.norm_font = font;
    hl_set_font_name (used_font_name);
    TextSize (font >> 16);
    TextFont (font & 0xFFFF);
    GetFontInfo (& font_info);
    gui.char_ascent = font_info.ascent;
    gui.char_width = p_columnspace + CharWidth ('_');
    gui.char_height = font_info.ascent + font_info.descent + p_linespace;
    return OK;
}

static GuiFont gui_mac_select_font (char_u *font_name) {
    GuiFont selected_font = NOFONT;
    OSStatus status;
    FontSelectionQDStyle curr_font;
    curr_font.instance.fontFamily = gui.norm_font & 0xFFFF;
    curr_font.size = (gui.norm_font >> 16);
    curr_font.instance.fontStyle = 0;
    curr_font.hasColor = false;
    curr_font.version = 0;
    status = SetFontInfoForSelection (kFontSelectionQDType, 1, &curr_font, NULL);
    gFontPanelInfo.family = curr_font.instance.fontFamily;
    gFontPanelInfo.style = curr_font.instance.fontStyle;
    gFontPanelInfo.size = curr_font.size;
    status = FPShowHideFontPanel ();
    if (status == noErr) {
        gFontPanelInfo.isPanelVisible = true;
        while (gFontPanelInfo.isPanelVisible) {
            EventRecord e;
            WaitNextEvent (everyEvent, & e, 20, NULL);
        }
        GetFontPanelSelection (font_name);
        selected_font = gui_mac_find_font (font_name);
    }
    return selected_font;
}

static void GetFontPanelSelection (char_u *outName) {
    Str255 buf;
    ByteCount fontNameLen = 0;
    ATSUFontID fid;
    char_u styleString [FONT_STYLE_BUFFER_SIZE];
    if (!outName)
        return;
    if (FMGetFontFamilyName (gFontPanelInfo.family, buf) == noErr) {
        if (FMGetFontFromFontFamilyInstance (gFontPanelInfo.family, gFontPanelInfo.style, &fid, NULL) != noErr)
            return;
        if (ATSUFindFontName (fid, kFontFullName, kFontMacintoshPlatform, kFontNoScriptCode, kFontNoLanguageCode, 255, (char *) outName, &fontNameLen, NULL) != noErr)
            return;
        vim_snprintf ((char *) styleString, FONT_STYLE_BUFFER_SIZE, ":h%d", gFontPanelInfo.size);
        if ((fontNameLen + STRLEN (styleString)) < 255)
            STRCPY (outName +fontNameLen, styleString);
    }
    else {
        *outName = NUL;
    }
}

guicolor_T gui_mch_get_color (char_u *name) {
    RGBColor MacColor;
    if (STRICMP (name, "hilite") == 0) {
        LMGetHiliteRGB (& MacColor);
        return (RGB (MacColor.red >> 8, MacColor.green >> 8, MacColor.blue >> 8));
    }
    return gui_get_color_cmn (name);
}

void gui_mch_new_colors (void) {
}

static pascal OSStatus gui_mac_mouse_wheel (EventHandlerCallRef nextHandler, EventRef theEvent, void *data) {
    Point point;
    Rect bounds;
    UInt32 mod;
    SInt32 delta;
    int_u vim_mod;
    EventMouseWheelAxis axis;
    if (noErr == GetEventParameter (theEvent, kEventParamMouseWheelAxis, typeMouseWheelAxis, NULL, sizeof (axis), NULL, &axis) && axis != kEventMouseWheelAxisY)
        goto bail;
    if (noErr != GetEventParameter (theEvent, kEventParamMouseWheelDelta, typeSInt32, NULL, sizeof (SInt32), NULL, &delta))
        goto bail;
    if (noErr != GetEventParameter (theEvent, kEventParamMouseLocation, typeQDPoint, NULL, sizeof (Point), NULL, &point))
        goto bail;
    if (noErr != GetEventParameter (theEvent, kEventParamKeyModifiers, typeUInt32, NULL, sizeof (UInt32), NULL, &mod))
        goto bail;
    vim_mod = 0;
    if (mod & shiftKey)
        vim_mod |= MOUSE_SHIFT;
    if (mod & controlKey)
        vim_mod |= MOUSE_CTRL;
    if (mod & optionKey)
        vim_mod |= MOUSE_ALT;
    if (noErr == GetWindowBounds (gui.VimWindow, kWindowContentRgn, &bounds)) {
        point.h -= bounds.left;
        point.v -= bounds.top;
    }
    gui_send_mouse_event ((delta > 0) ? MOUSE_4 : MOUSE_5, point.h, point.v, FALSE, vim_mod);
    PostEvent (keyUp, 0);
    return noErr;
bail :
    return CallNextEventHandler (nextHandler, theEvent);
}

static int_u EventModifiers2VimModifiers (EventModifiers macModifiers) {
    int_u vimModifiers = 0x00;
    if (macModifiers & (shiftKey | rightShiftKey))
        vimModifiers |= MOD_MASK_SHIFT;
    if (macModifiers & (controlKey | rightControlKey))
        vimModifiers |= MOD_MASK_CTRL;
    if (macModifiers & (optionKey | rightOptionKey))
        vimModifiers |= MOD_MASK_ALT;
    return (vimModifiers);
}

void gui_mch_add_menu (vimmenu_T *menu, int idx) {
    static long  next_avail_id = 128;
    long  menu_after_me = 0;
    char_u *name;
    short  index;
    vimmenu_T *parent = menu->parent;
    vimmenu_T *brother = menu->next;
    if ((parent != NULL && parent->submenu_id == 0))
        return;
    if (next_avail_id == 1024)
        return;
    while ((brother != NULL) && (!menu_is_menubar (brother->name)))
        brother = brother->next;
    if ((parent == NULL) && (brother != NULL))
        menu_after_me = brother->submenu_id;
    if (!menu_is_menubar (menu->name))
        menu_after_me = hierMenu;
    name = C2Pascal_save (menu->dname);
    if (name == NULL)
        return;
    {
        menu->submenu_id = next_avail_id;
        menu->submenu_handle = NewMenu (menu->submenu_id, name);
        next_avail_id++;
    }
    if (parent == NULL) {
        InsertMenu (menu -> submenu_handle, menu_after_me);
    }
    else {
        index = gui_mac_get_menu_item_index (menu);
        InsertMenuItem (parent -> submenu_handle, "\p ", idx);
        SetMenuItemText (parent -> submenu_handle, idx + 1, name);
        SetItemCmd (parent -> submenu_handle, idx + 1, 0x1B);
        SetItemMark (parent -> submenu_handle, idx + 1, menu -> submenu_id);
        InsertMenu (menu -> submenu_handle, hierMenu);
    }
    vim_free (name);
}

char_u *C2Pascal_save (char_u *Cstring) {
    char_u *PascalString;
    int len;
    if (Cstring == NULL)
        return NULL;
    len = STRLEN (Cstring);
    if (len > 255)
        len = 255;
    PascalString = alloc (len +1);
    if (PascalString != NULL) {
        mch_memmove (PascalString + 1, Cstring, len);
        PascalString[0] = len;
    }
    return PascalString;
}

void gui_mch_add_menu_item (vimmenu_T *menu, int idx) {
    char_u *name;
    vimmenu_T *parent = menu->parent;
    int menu_inserted;
    if (parent->submenu_id == 0)
        return;
    name = C2Pascal_save (menu->dname);
    menu->submenu_id = 0;
    menu->submenu_handle = NULL;
    menu_inserted = 0;
    if (menu->actext) {
        int key = 0;
        int modifiers = 0;
        char_u *p_actext;
        p_actext = menu->actext;
        key = find_special_key (&p_actext, &modifiers, FALSE, FALSE, FALSE);
        if (*p_actext != 0)
            key = 0;
        if (key > 0 && key < 32) {
            modifiers |= MOD_MASK_CTRL;
            key += '@';
        }
        else if (key >= 'A' && key <= 'Z')
            modifiers |= MOD_MASK_SHIFT;
        else if (key >= 'a' && key <= 'z')
            key += 'A' - 'a';
        if (key >= 0x22 && vim_isprintc_strict (key)) {
            int valid = 1;
            char_u mac_mods = kMenuNoModifiers;
            if (modifiers & MOD_MASK_SHIFT)
                mac_mods |= kMenuShiftModifier;
            if (modifiers & MOD_MASK_CTRL)
                mac_mods |= kMenuControlModifier;
            if (!(modifiers & MOD_MASK_CMD))
                mac_mods |= kMenuNoCommandModifier;
            if (modifiers & MOD_MASK_ALT || modifiers & MOD_MASK_MULTI_CLICK)
                valid = 0;
            if (valid) {
                char_u item_txt [10];
                item_txt[0] = 3;
                item_txt[1] = ' ';
                item_txt[2] = '/';
                item_txt[3] = key;
                InsertMenuItem (parent -> submenu_handle, item_txt, idx);
                SetMenuItemModifiers (parent -> submenu_handle, idx + 1, mac_mods);
                menu_inserted = 1;
            }
        }
    }
    if (!menu_inserted)
        InsertMenuItem (parent->submenu_handle, "\p ", idx);
    SetMenuItemText (parent -> submenu_handle, idx + 1, name);
    vim_free (name);
}

int gui_mch_open (void) {
    ShowWindow (gui.VimWindow);
    if (gui_win_x != -1 && gui_win_y != -1)
        gui_mch_set_winpos (gui_win_x, gui_win_y);
    {
        ProcessSerialNumber psn;
        if (GetCurrentProcess (&psn) == noErr)
            SetFrontProcess (&psn);
    }
    return OK;
}

guicolor_T gui_mch_get_rgb (guicolor_T pixel) {
    return (guicolor_T) ((Red (pixel) << 16) + (Green (pixel) << 8) + Blue (pixel));
}

int gui_mch_adjust_charheight (void) {
    FontInfo font_info;
    GetFontInfo (& font_info);
    gui.char_height = font_info.ascent + font_info.descent + p_linespace;
    gui.char_ascent = font_info.ascent + p_linespace / 2;
    return OK;
}

char_u **new_fnames_from_AEDesc (AEDesc *theList, long  *numFiles, OSErr *error) {
    char_u **fnames = NULL;
    OSErr newError;
    long  fileCount;
    FSSpec fileToOpen;
    long  actualSize;
    AEKeyword dummyKeyword;
    DescType dummyType;
    *error = AECountItems (theList, numFiles);
    if (*error)
        return fnames;
    fnames = (char_u **) alloc (*numFiles * sizeof (char_u *));
    for (fileCount = 0; fileCount < *numFiles; fileCount++)
        fnames[fileCount] = NULL;
    for (fileCount = 1; fileCount <= *numFiles; fileCount++) {
        newError = AEGetNthPtr (theList, fileCount, typeFSS, &dummyKeyword, &dummyType, (Ptr) &fileToOpen, sizeof (FSSpec), &actualSize);
        if (newError) {
            return fnames;
        }
        fnames[fileCount - 1] = FullPathFromFSSpec_save (fileToOpen);
    }
    return (fnames);
}

void gui_mch_setmouse (int x, int y) {
}

void gui_mch_show_popupmenu (vimmenu_T *menu) {
    MenuHandle CntxMenu;
    Point where;
    OSStatus status;
    UInt32 CntxType;
    SInt16 CntxMenuID;
    UInt16 CntxMenuItem;
    Str255 HelpName = "";
    GrafPtr savePort;
    GetPort (& savePort);
    GetMouse (& where);
    LocalToGlobal (& where);
    CntxMenu = menu->submenu_handle;
    status = ContextualMenuSelect (CntxMenu, where, false, kCMHelpItemRemoveHelp, HelpName, NULL, &CntxType, &CntxMenuID, &CntxMenuItem);
    if (status == noErr) {
        if (CntxType == kCMMenuItemSelected) {
            gui_mac_handle_menu ((CntxMenuID << 16) + CntxMenuItem);
        }
        else if (CntxMenuID == kCMShowHelpSelected) {
        }
    }
    SetPort (savePort);
}

int GetFSSpecFromPath (char_u *file, FSSpec *fileFSSpec) {
    Str255 filePascal;
    CInfoPBRec myCPB;
    OSErr err;
    (void) C2PascalString (file, &filePascal);
    myCPB.dirInfo.ioNamePtr = filePascal;
    myCPB.dirInfo.ioVRefNum = 0;
    myCPB.dirInfo.ioFDirIndex = 0;
    myCPB.dirInfo.ioDrDirID = 0;
    err = PBGetCatInfo (&myCPB, false);
    FSMakeFSSpec (0, 0, filePascal, fileFSSpec);
    return 0;
}

void gui_mch_set_foreground (void) {
}

void clip_mch_request_selection (VimClipboard *cbd) {
    Handle textOfClip;
    int flavor = 0;
    Size scrapSize;
    ScrapFlavorFlags scrapFlags;
    ScrapRef scrap = nil;
    OSStatus error;
    int type;
    char *searchCR;
    char_u *tempclip;
    error = GetCurrentScrap (&scrap);
    if (error != noErr)
        return;
    error = GetScrapFlavorFlags (scrap, VIMSCRAPFLAVOR, &scrapFlags);
    if (error == noErr) {
        error = GetScrapFlavorSize (scrap, VIMSCRAPFLAVOR, &scrapSize);
        if (error == noErr && scrapSize > 1)
            flavor = 1;
    }
    if (flavor == 0) {
        error = GetScrapFlavorFlags (scrap, SCRAPTEXTFLAVOR, &scrapFlags);
        if (error != noErr)
            return;
        error = GetScrapFlavorSize (scrap, SCRAPTEXTFLAVOR, &scrapSize);
        if (error != noErr)
            return;
    }
    ReserveMem (scrapSize);
    textOfClip = NewHandle (scrapSize);
    HLock (textOfClip);
    error = GetScrapFlavorData (scrap, flavor ? VIMSCRAPFLAVOR : SCRAPTEXTFLAVOR, &scrapSize, *textOfClip);
    scrapSize -= flavor;
    if (flavor)
        type = **textOfClip;
    else
        type = MAUTO;
    tempclip = lalloc (scrapSize +1, TRUE);
    mch_memmove (tempclip, * textOfClip + flavor, scrapSize);
    tempclip[scrapSize] = 0;
    searchCR = (char *) tempclip;
    while (searchCR != NULL) {
        searchCR = strchr (searchCR, '\r');
        if (searchCR != NULL)
            *searchCR = '\n';
    }
    clip_yank_selection (type, tempclip, scrapSize, cbd);
    vim_free (tempclip);
    HUnlock (textOfClip);
    DisposeHandle (textOfClip);
}

void gui_mac_doInDragClick (Point where, WindowPtr whichWindow) {
    Rect movingLimits;
    Rect *movingLimitsPtr = &movingLimits;
    movingLimitsPtr = GetRegionBounds (GetGrayRgn (), &movingLimits);
    DragWindow (whichWindow, where, movingLimitsPtr);
}

void gui_mac_doInGrowClick (Point where, WindowPtr whichWindow) {
    long  newSize;
    unsigned  short  newWidth;
    unsigned  short  newHeight;
    Rect resizeLimits;
    Rect *resizeLimitsPtr = &resizeLimits;
    Rect NewContentRect;
    resizeLimitsPtr = GetRegionBounds (GetGrayRgn (), &resizeLimits);
    resizeLimits.top = 100;
    resizeLimits.left = 100;
    newSize = ResizeWindow (whichWindow, where, &resizeLimits, &NewContentRect);
    newWidth = NewContentRect.right - NewContentRect.left;
    newHeight = NewContentRect.bottom - NewContentRect.top;
    gui_resize_shell (newWidth, newHeight);
    gui_mch_set_bg_color (gui.back_pixel);
    gui_set_shellsize (TRUE, FALSE, RESIZE_BOTH);
}

static void gui_mac_doInZoomClick (EventRecord *theEvent, WindowPtr whichWindow) {
    Rect r;
    Point p;
    short  thePart;
    p.h = Columns * gui.char_width + 2 * gui.border_offset;
    if (gui.which_scrollbars[SBAR_LEFT])
        p.h += gui.scrollbar_width;
    if (gui.which_scrollbars[SBAR_RIGHT])
        p.h += gui.scrollbar_width;
    p.v = 15 * 1024;
    thePart = IsWindowInStandardState (whichWindow, &p, &r) ? inZoomIn : inZoomOut;
    if (!TrackBox (whichWindow, theEvent->where, thePart))
        return;
    p.h = r.right - r.left;
    p.v = r.bottom - r.top - 2 * gui.border_offset;
    if (gui.which_scrollbars[SBAR_BOTTOM])
        p.v -= gui.scrollbar_height;
    p.v -= p.v % gui.char_height;
    p.v += 2 * gui.border_width;
    if (gui.which_scrollbars[SBAR_BOTTOM])
        p.v += gui.scrollbar_height;
    ZoomWindowIdeal (whichWindow, thePart, & p);
    GetWindowBounds (whichWindow, kWindowContentRgn, & r);
    gui_resize_shell (r.right - r.left, r.bottom - r.top);
    gui_mch_set_bg_color (gui.back_pixel);
    gui_set_shellsize (TRUE, FALSE, RESIZE_BOTH);
}

void gui_mac_doKeyEvent (EventRecord *theEvent) {
    long  menu;
    unsigned  char string [20];
    short  num, i;
    short  len = 0;
    KeySym key_sym;
    int key_char;
    int modifiers;
    int simplify = FALSE;
    if (p_mh)
        ObscureCursor ();
    key_sym = ((theEvent->message & keyCodeMask) >> 8);
    key_char = theEvent->message & charCodeMask;
    num = 1;
    if (theEvent->modifiers & controlKey) {
        if (key_char == Ctrl_C && ctrl_c_interrupts)
            got_int = TRUE;
        else if ((theEvent->modifiers & ~(controlKey | shiftKey)) == 0 && (key_char == '2' || key_char == '6')) {
            if (key_char == '2')
                key_char = Ctrl_AT;
            else
                key_char = Ctrl_HAT;
            theEvent->modifiers = 0;
        }
    }
    if (theEvent->modifiers & cmdKey)
        if (key_char == '.')
            got_int = TRUE;
    if (theEvent->modifiers & cmdKey)
        if ((theEvent->modifiers & (~(cmdKey | btnState | alphaLock))) == 0) {
            menu = MenuKey (key_char);
            if (HiWord (menu)) {
                gui_mac_handle_menu (menu);
                return;
            }
        }
    modifiers = EventModifiers2VimModifiers (theEvent->modifiers);
    {
        if ((key_char < 0x20) || (key_char == 0x7f))
            for (i = 0; special_keys[i].key_sym != (KeySym) 0; i++)
                if (special_keys[i].key_sym == key_sym) {
                    key_char = TO_SPECIAL (special_keys[i].vim_code0, special_keys[i].vim_code1);
                    simplify = TRUE;
                    break;
                }
    }
    if (simplify || key_char == TAB || key_char == ' ')
        key_char = simplify_key (key_char, &modifiers);
    if (!IS_SPECIAL (key_char) && key_sym != vk_Space && key_sym != vk_Tab && key_sym != vk_Return && key_sym != vk_Enter && key_sym != vk_Esc) {
        if (modifiers & MOD_MASK_CTRL)
            modifiers = modifiers & ~MOD_MASK_CTRL;
        if (modifiers & MOD_MASK_ALT)
            modifiers = modifiers & ~MOD_MASK_ALT;
        if (modifiers & MOD_MASK_SHIFT)
            modifiers = modifiers & ~MOD_MASK_SHIFT;
    }
    if (modifiers) {
        string[len++] = CSI;
        string[len++] = KS_MODIFIER;
        string[len++] = modifiers;
    }
    if (IS_SPECIAL (key_char)) {
        string[len++] = CSI;
        string[len++] = K_SECOND (key_char);
        string[len++] = K_THIRD (key_char);
    }
    else {
        string[len++] = key_char;
    }
    if (len == 1 && string[0] == CSI) {
        string[len++] = KS_EXTRA;
        string[len++] = KE_CSI;
    }
    add_to_input_buf (string, len);
}

void gui_mac_doMouseUpEvent (EventRecord *theEvent) {
    Point thePoint;
    int_u vimModifiers;
    lastMouseTick = theEvent->when;
    dragRectEnbl = FALSE;
    dragRectControl = kCreateEmpty;
    thePoint = theEvent->where;
    GlobalToLocal (& thePoint);
    vimModifiers = EventModifiers2VimMouseModifiers (theEvent->modifiers);
    if (clickIsPopup) {
        vimModifiers &= ~MOUSE_CTRL;
        clickIsPopup = FALSE;
    }
    gui_send_mouse_event (MOUSE_RELEASE, thePoint.h, thePoint.v, FALSE, vimModifiers);
}

void gui_mac_doUpdateEvent (EventRecord *event) {
    WindowPtr whichWindow;
    GrafPtr savePort;
    RgnHandle updateRgn;
    Rect updateRect;
    Rect *updateRectPtr;
    Rect rc;
    Rect growRect;
    RgnHandle saveRgn;
    updateRgn = NewRgn ();
    if (updateRgn == NULL)
        return;
    whichWindow = (WindowPtr) event->message;
    GetPort (& savePort);
    SetPortWindowPort (whichWindow);
    BeginUpdate (whichWindow);
    GetPortVisibleRegion (GetWindowPort (whichWindow), updateRgn);
    HLock ((Handle) updateRgn);
    updateRectPtr = GetRegionBounds (updateRgn, &updateRect);
    gui_redraw (updateRectPtr -> left, updateRectPtr -> top, updateRectPtr -> right - updateRectPtr -> left, updateRectPtr -> bottom - updateRectPtr -> top);
    gui_mch_set_bg_color (gui.back_pixel);
    if (updateRectPtr->left < FILL_X (0)) {
        SetRect (& rc, 0, 0, FILL_X (0), FILL_Y (Rows));
        EraseRect (& rc);
    }
    if (updateRectPtr->top < FILL_Y (0)) {
        SetRect (& rc, 0, 0, FILL_X (Columns), FILL_Y (0));
        EraseRect (& rc);
    }
    if (updateRectPtr->right > FILL_X (Columns)) {
        SetRect (& rc, FILL_X (Columns), 0, FILL_X (Columns) + gui.border_offset, FILL_Y (Rows));
        EraseRect (& rc);
    }
    if (updateRectPtr->bottom > FILL_Y (Rows)) {
        SetRect (& rc, 0, FILL_Y (Rows), FILL_X (Columns) + gui.border_offset, FILL_Y (Rows) + gui.border_offset);
        EraseRect (& rc);
    }
    HUnlock ((Handle) updateRgn);
    DisposeRgn (updateRgn);
    DrawControls (whichWindow);
    saveRgn = NewRgn ();
    GetWindowBounds (whichWindow, kWindowGrowRgn, & growRect);
    GetClip (saveRgn);
    ClipRect (& growRect);
    DrawGrowIcon (whichWindow);
    SetClip (saveRgn);
    DisposeRgn (saveRgn);
    EndUpdate (whichWindow);
    SetPort (savePort);
}

void gui_mac_doActivateEvent (EventRecord *event) {
    WindowPtr whichWindow;
    whichWindow = (WindowPtr) event->message;
    if (whichWindow == gui.VimWindow) {
        ControlRef rootControl;
        GetRootControl (gui.VimWindow, & rootControl);
        if ((event->modifiers) & activeFlag)
            ActivateControl (rootControl);
        else
            DeactivateControl (rootControl);
    }
    gui_focus_change ((event -> modifiers) & activeFlag);
}

void gui_mac_doMouseMovedEvent (EventRecord *event) {
    Point thePoint;
    int_u vimModifiers;
    thePoint = event->where;
    GlobalToLocal (& thePoint);
    vimModifiers = EventModifiers2VimMouseModifiers (event->modifiers);
    if (!Button ())
        gui_mouse_moved (thePoint.h, thePoint.v);
    else if (!clickIsPopup)
        gui_send_mouse_event (MOUSE_DRAG, thePoint.h, thePoint.v, FALSE, vimModifiers);
    SetRect (& dragRect, FILL_X (X_2_COL (thePoint.h)), FILL_Y (Y_2_ROW (thePoint.v)), FILL_X (X_2_COL (thePoint.h) + 1), FILL_Y (Y_2_ROW (thePoint.v) + 1));
    if (dragRectEnbl)
        dragRectControl = kCreateRect;
}

void gui_mac_doSuspendEvent (EventRecord *event) {
    if (event->message & 1)
        gui_focus_change (TRUE);
    else
        gui_focus_change (FALSE);
}

