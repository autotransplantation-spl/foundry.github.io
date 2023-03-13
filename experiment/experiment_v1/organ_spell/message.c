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
struct vim_exception {
    except_type_T type;
    char_u *value;
    struct msglist *messages;
    char_u *throw_name;
    linenr_T throw_lnum;
    except_T *caught;
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
struct info_pointer {
    blocknr_T ip_bnum;
    linenr_T ip_low;
    linenr_T ip_high;
    int ip_index;
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
struct m_info {
    short_u m_size;
    minfo_T *m_next;
};
struct u_entry {
    u_entry_T *ue_next;
    linenr_T ue_top;
    linenr_T ue_bot;
    linenr_T ue_lcount;
    char_u **ue_array;
    long  ue_size;
};
struct filemark {
    pos_T mark;
    int fnum;
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
struct stl_hlrec {
    char_u *start;
    int userhl;
};
struct regprog {
    regengine_T *engine;
    unsigned  regflags;
    unsigned  re_engine;
    unsigned  re_flags;
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
struct mf_hashtab_S {
    long_u mht_mask;
    long_u mht_count;
    mf_hashitem_T **mht_buckets;
    mf_hashitem_T *mht_small_buckets [MHT_INIT_SIZE];
    char mht_fixed;
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
struct dictitem16_S {
    typval_T di_tv;
    char_u di_flags;
    char_u di_key [17];
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
struct posmatch {
    llpos_T pos [MAXPOSMATCH];
    int cur;
    linenr_T toplnum;
    linenr_T botlnum;
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
struct w_line {
    linenr_T wl_lnum;
    short_u wl_size;
    char wl_valid;
    char wl_folded;
    linenr_T wl_lastlnum;
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
struct arglist {
    garray_T al_ga;
    int al_refcount;
    int id;
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
struct ml_chunksize {
    int mlcs_numlines;
    long  mlcs_totalsize;
};
struct growarray {
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    int ga_growsize;
    void *ga_data;
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
struct msglist {
    char_u *msg;
    char_u *throw_msg;
    struct msglist *next;
};
struct msgchunk_S {
    msgchunk_T *sb_next;
    msgchunk_T *sb_prev;
    char sb_eol;
    int sb_msg_col;
    int sb_attr;
    char_u sb_text [1];
};
struct msg_hist {
    struct msg_hist *next;
    char_u *msg;
    int attr;
};
struct mf_hashitem_S {
    mf_hashitem_T *mhi_next;
    mf_hashitem_T *mhi_prev;
    blocknr_T mhi_key;
};
struct buf_state {
    int bs_idx;
    int bs_flags;
    int bs_seqnr;
    int bs_cchar;
    reg_extmatch_T *bs_extmatch;
};
struct foldinfo {
    int fi_level;
    int fi_lnum;
    int fi_low_level;
};
struct nr_trans {
    mf_hashitem_T nt_hashitem;

    #define nt_old_bnum nt_hashitem.mhi_key	/* old, negative, number */
    blocknr_T nt_new_bnum;
};
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
garray_T ignore_error_list = GA_EMPTY;
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
EXTERN char_u e_invargval [] INIT (= N_ ("E475: Invalid value for argument %s"));
EXTERN char_u e_backslash [] INIT (= N_ ("E10: \\ should be followed by /, ? or &"));
EXTERN char_u langmap_mapchar [256];
EXTERN char_u *escape_chars INIT (= (char_u *) " \t\\\"|");
EXTERN char_u *repeat_cmdline INIT (= NULL);
EXTERN char_u *last_cmdline INIT (= NULL);
EXTERN FILE *scriptin [NSCRIPT];
EXTERN cmdmod_T cmdmod;
EXTERN win_T *aucmd_win;
EXTERN char_u *use_gvimrc INIT (= NULL);
EXTERN except_T *caught_stack INIT (= NULL);
EXTERN int called_vim_beep;
EXTERN dict_T globvardict;
EXTERN dict_T vimvardict;
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
EXTERN char_u e_prev_dir [] INIT (= N_ ("E459: Cannot go back to previous directory"));
EXTERN char_u e_noprevre [] INIT (= N_ ("E35: No previous regular expression"));
EXTERN char_u e_noprev [] INIT (= N_ ("E34: No previous command"));
EXTERN win_T *prevwin INIT (= NULL);
EXTERN char_u e_au_recursive [] INIT (= N_ ("E952: Autocommand caused recursive behavior"));
EXTERN char_u e_secure [] INIT (= N_ ("E523: Not allowed here"));
EXTERN char_u e_curdir [] INIT (= N_ ("E12: Command not allowed from exrc/vimrc in current dir or tag search"));
EXTERN pos_T saved_cursor;
EXTERN tabpage_T *curtab;
EXTERN int current_scrollbar;
EXTERN except_T *current_exception;
EXTERN int p_secure;
EXTERN char_u e_bufloaded [] INIT (= N_ ("E139: File is loaded in another buffer"));
EXTERN char_u e_nobufnr [] INIT (= N_ ("E86: Buffer %ld does not exist"));
EXTERN char_u e_emptybuf [] INIT (= N_ ("E749: empty buffer"));
EXTERN char_u e_notmp [] INIT (= N_ ("E483: Can't get temp file name"));
EXTERN pos_T last_cursormoved;
EXTERN buf_T *lastbuf INIT (= NULL);
EXTERN buf_T *firstbuf INIT (= NULL);
EXTERN buf_T *au_pending_free_buf INIT (= NULL);
EXTERN long  p_ttm;
EXTERN long  p_tm;
EXTERN int p_stmp;
EXTERN int p_lrm;
EXTERN int p_confirm;
EXTERN char_u e_positive [] INIT (= N_ ("E487: Argument must be positive"));
EXTERN hlf_T edit_submode_highl;
EXTERN int p_hls;
EXTERN char_u *p_hl;
EXTERN char_u *p_hlg;
const unsigned  char cmdidxs2 [26] [26] = {{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 6, 0, 0, 0, 7, 15, 0, 16, 0, 0, 0, 0, 0}, {2, 0, 0, 4, 5, 7, 0, 0, 0, 0, 0, 8, 9, 10, 11, 12, 0, 13, 0, 0, 0, 0, 22, 0, 0, 0}, {3, 10, 12, 14, 16, 18, 21, 0, 0, 0, 0, 29, 33, 36, 42, 51, 53, 54, 55, 0, 57, 0, 60, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 6, 15, 0, 16, 0, 0, 17, 0, 0, 19, 20, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 7, 9, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 4, 5, 0, 0, 0, 0}, {5, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 3, 0, 0, 0, 4, 0, 5, 6, 0, 0, 0, 0, 0, 13, 0, 15, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {3, 9, 11, 15, 16, 20, 23, 28, 0, 0, 0, 30, 33, 36, 40, 46, 0, 48, 57, 49, 50, 54, 56, 0, 0, 0}, {1, 0, 0, 0, 9, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 8, 10, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 5, 0, 0, 0, 0, 0, 0, 9, 0, 11, 0, 0, 0}, {1, 0, 3, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 9, 0, 0, 16, 17, 26, 0, 27, 0, 28, 0}, {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 18, 0, 0, 0, 0}, {2, 6, 15, 0, 18, 22, 0, 24, 25, 0, 0, 28, 30, 34, 38, 40, 0, 48, 0, 49, 0, 61, 62, 0, 63, 0}, {2, 0, 19, 0, 22, 24, 0, 25, 0, 26, 0, 27, 28, 31, 33, 34, 0, 35, 37, 0, 38, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 9, 12, 0, 0, 0, 0, 15, 0, 16, 0, 0, 0, 0, 0}, {2, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 0, 8, 0, 9, 10, 0, 12, 0, 13, 14, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
const unsigned  short  cmdidxs1 [26] = {0, 19, 42, 103, 125, 145, 161, 167, 176, 194, 196, 201, 259, 279, 299, 311, 350, 353, 372, 439, 479, 490, 508, 523, 532, 533};
EXTERN char_u e_invalidreg [] INIT (= N_ ("E850: Invalid register name"));
EXTERN char_u e_usingsid [] INIT (= N_ ("E81: Using <SID> not in a script context"));
EXTERN char_u e_listidx [] INIT (= N_ ("E684: list index out of range: %ld"));
EXTERN int ru_wid;
EXTERN int p_tbidi;
EXTERN int p_hid;
EXTERN int autocmd_fname_full;
EXTERN char_u *autocmd_fname INIT (= NULL);
const int command_count = 546;
EXTERN char_u e_zerocount [] INIT (= N_ ("E939: Positive count required"));
EXTERN char_u e_nomatch2 [] INIT (= N_ ("E480: No match: %s"));
EXTERN char_u e_nomatch [] INIT (= N_ ("E479: No match"));
EXTERN char_u *autocmd_match INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_out INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_in INIT (= NULL);
EXTERN linenr_T search_match_lines;
EXTERN int searchcmdlen;
EXTERN long  p_titlelen;
EXTERN char_u e_maxmempat [] INIT (= N_ ("E363: pattern uses more memory than 'maxmempattern'"));
EXTERN char_u e_winwidth [] INIT (= N_ ("E592: 'winwidth' cannot be smaller than 'winminwidth'"));
EXTERN char_u e_winheight [] INIT (= N_ ("E591: 'winheight' cannot be smaller than 'winminheight'"));
EXTERN typebuf_T typebuf;
EXTERN frame_T *topframe;
EXTERN long_u scrollbar_value;
EXTERN unsigned  swb_flags;
EXTERN pos_T Insstart_orig;
EXTERN pos_T Insstart;
EXTERN pos_T VIsual;
EXTERN int arrow_used;
EXTERN int ru_col;
EXTERN int mouse_col;
EXTERN colnr_T search_match_endcol;
EXTERN int p_cc_cols [256];
EXTERN long  p_columnspace;
EXTERN int fuoptions_bgcolor;
EXTERN time_T starttime;
EXTERN int stop_insert_mode;
EXTERN pos_T where_paste_started;
EXTERN char *font_argument INIT (= NULL);
EXTERN int p_guipty;
EXTERN int p_bevalterm;
EXTERN char need_key_msg [] INIT (= N_ ("Need encryption key for \"%s\""));
EXTERN char bot_top_msg [] INIT (= N_ ("search hit BOTTOM, continuing at TOP"));
EXTERN char top_bot_msg [] INIT (= N_ ("search hit TOP, continuing at BOTTOM"));
EXTERN char_u e_invexprmsg [] INIT (= N_ ("E449: Invalid expression received"));
EXTERN char_u no_lines_msg [] INIT (= N_ ("--No lines in buffer--"));
EXTERN char_u msg_buf [MSG_BUF_LEN];
EXTERN int highlight_attr [HLF_COUNT];
EXTERN struct msglist **msg_list INIT (= NULL);
EXTERN int did_emsg_syntax;
EXTERN long  p_verbose;
EXTERN unsigned  *LineOffset INIT (= NULL);
EXTERN sattr_T *ScreenAttrs INIT (= NULL);
EXTERN vimmenu_T *current_menu;
EXTERN buf_T *curbuf INIT (= NULL);
EXTERN win_T *curwin;
sb_clear_T do_clear_sb_text = SB_CLEAR_NONE;
char_u *confirm_msg_tail;
EXTERN char_u *p_go;
EXTERN int did_uncaught_emsg;
EXTERN int did_emsg;
EXTERN int p_eb;
EXTERN char_u *p_debug;
EXTERN int called_emsg;
char_u *confirm_msg = NULL;
int confirm_msg_used = FALSE;
EXTERN int p_more;
EXTERN int p_cp;
EXTERN FILE *scriptout INIT (= NULL);
EXTERN int mouse_row;
char_u *last_sourcing_name = NULL;
int last_sourcing_lnum = 0;
EXTERN char_u *sourcing_name INIT (= NULL);
EXTERN char_u e_notopen [] INIT (= N_ ("E484: Can't open file %s"));
int verbose_did_open = FALSE;
EXTERN FILE *redir_fd INIT (= NULL);
FILE *verbose_fd = NULL;
EXTERN int msg_scrolled;
EXTERN int msg_col;
EXTERN int msg_row;
struct msg_hist *first_msg_hist = NULL;
int msg_hist_len = 0;
EXTERN int sc_col;
EXTERN int cmdline_row;
EXTERN long  Rows;
int emsg_to_channel_log = FALSE;
struct msg_hist *last_msg_hist = NULL;
EXTERN char_u *IObuff;
EXTERN char_u *keep_msg INIT (= NULL);
char *e_printf = N_ ("E766: Insufficient arguments for printf()");
msgchunk_T *last_msgchunk = NULL;
EXTERN int p_prompt;
EXTERN char_u *p_guifont;
EXTERN char_u *p_isp;
EXTERN int p_is;
EXTERN int p_altkeymap;
EXTERN char_u e_nbreadonly [] INIT (= N_ ("E744: NetBeans does not allow changes in read-only files"));

void clear_sb_text (int all) {
    msgchunk_T *mp;
    msgchunk_T **lastp;
    if (all)
        lastp = &last_msgchunk;
    else {
        if (last_msgchunk == NULL)
            return;
        lastp = &last_msgchunk->sb_prev;
    }
    while (*lastp != NULL) {
        mp = (*lastp)->sb_prev;
        vim_free (*lastp);
        *lastp = mp;
    }
}

static int copy_char (char_u *from, char_u *to, int lowercase) {
    {
        if (lowercase)
            *to = (char_u) TOLOWER_LOC (*from);
        else
            *to = *from;
        return 1;
    }
}

int vim_snprintf (char *str, size_t str_m, char *fmt, ... ) {
    va_list ap;
    int str_l;
    va_start (ap, fmt);
    str_l = vim_vsnprintf (str, str_m, fmt, ap);
    va_end (ap);
    return str_l;
}

int vim_vsnprintf (char *str, size_t str_m, char *fmt, va_list ap) {
    return vim_vsnprintf_typval (str, str_m, fmt, ap, NULL);
}

static varnumber_T tv_nr (typval_T *tvs, int *idxp) {
    int idx = *idxp - 1;
    varnumber_T n = 0;
    int err = FALSE;
    if (tvs[idx].v_type == VAR_UNKNOWN)
        EMSG (_ (e_printf));
    else {
        ++*idxp;
        n = get_tv_number_chk (&tvs[idx], &err);
        if (err)
            n = 0;
    }
    return n;
}

static char *tv_str (typval_T *tvs, int *idxp, char_u **tofree) {
    int idx = *idxp - 1;
    char *s = NULL;
    static char_u numbuf [NUMBUFLEN];
    if (tvs[idx].v_type == VAR_UNKNOWN)
        EMSG (_ (e_printf));
    else {
        ++*idxp;
        if (tofree != NULL)
            s = (char *) echo_string (&tvs[idx], tofree, numbuf, get_copyID ());
        else
            s = (char *) get_tv_string_chk (&tvs[idx]);
    }
    return s;
}

static double tv_float (typval_T *tvs, int *idxp) {
    int idx = *idxp - 1;
    double f = 0;
    if (tvs[idx].v_type == VAR_UNKNOWN)
        EMSG (_ (e_printf));
    else {
        ++*idxp;
        if (tvs[idx].v_type == VAR_FLOAT)
            f = tvs[idx].vval.v_float;
        else if (tvs[idx].v_type == VAR_NUMBER)
            f = (double) tvs[idx].vval.v_number;
        else
            EMSG (_ ("E807: Expected Float argument for printf()"));
    }
    return f;
}

void set_keep_msg (char_u *s, int attr) {
    vim_free (keep_msg);
    if (s != NULL && msg_silent == 0)
        keep_msg = vim_strsave (s);
    else
        keep_msg = NULL;
    keep_msg_more = FALSE;
    keep_msg_attr = attr;
}

int smsg (char_u *s, ... ) {
    va_list arglist;
    va_start (arglist, s);
    vim_vsnprintf ((char *) IObuff, IOSIZE, (char *) s, arglist);
    va_end (arglist);
    return msg (IObuff);
}

int msg (char_u *s) {
    return msg_attr_keep (s, 0, FALSE);
}

int msg_attr_keep (char_u *s, int attr, int keep) {
    static int entered = 0;
    int retval;
    char_u *buf = NULL;
    if (!emsg_on_display && message_filtered (s))
        return TRUE;
    if (attr == 0)
        set_vim_var_string (VV_STATUSMSG, s, -1);
    if (entered >= 3)
        return TRUE;
    ++entered;
    if (s != keep_msg || (*s != '<' && last_msg_hist != NULL && last_msg_hist->msg != NULL && STRCMP (s, last_msg_hist->msg)))
        add_msg_hist (s, -1, attr);
    if (emsg_to_channel_log)
        ch_log (NULL, "ERROR: %s", (char *) s);
    if (s == keep_msg)
        keep_msg = NULL;
    msg_start ();
    buf = msg_strtrunc (s, FALSE);
    if (buf != NULL)
        s = buf;
    msg_outtrans_attr (s, attr);
    msg_clr_eos ();
    retval = msg_end ();
    if (keep && retval && vim_strsize (s) < (int) (Rows - cmdline_row - 1) * Columns + sc_col)
        set_keep_msg (s, 0);
    vim_free (buf);
    --entered;
    return retval;
}

static void add_msg_hist (char_u *s, int len, int attr) {
    struct msg_hist *p;
    if (msg_hist_off || msg_silent != 0)
        return;
    while (msg_hist_len > MAX_MSG_HIST_LEN)
        (void) delete_first_msg ();
    p = (struct msg_hist *) alloc ((int) sizeof (struct msg_hist));
    if (p != NULL) {
        if (len < 0)
            len = (int) STRLEN (s);
        while (len > 0 && *s == '\n') {
            ++s;
            --len;
        }
        while (len > 0 && s[len - 1] == '\n')
            --len;
        p->msg = vim_strnsave (s, len);
        p->next = NULL;
        p->attr = attr;
        if (last_msg_hist != NULL)
            last_msg_hist->next = p;
        last_msg_hist = p;
        if (first_msg_hist == NULL)
            first_msg_hist = last_msg_hist;
        ++msg_hist_len;
    }
}

int delete_first_msg (void) {
    struct msg_hist *p;
    if (msg_hist_len <= 0)
        return FAIL;
    p = first_msg_hist;
    first_msg_hist = p->next;
    if (first_msg_hist == NULL)
        last_msg_hist = NULL;
    vim_free (p -> msg);
    vim_free (p);
    --msg_hist_len;
    return OK;
}

void msg_start (void) {
    int did_return = FALSE;
    if (!msg_silent)
        VIM_CLEAR (keep_msg);
    if (need_clr_eos) {
        need_clr_eos = FALSE;
        msg_clr_eos ();
    }
    if (!msg_scroll && full_screen) {
        msg_row = cmdline_row;
        msg_col = cmdmsg_rl ? Columns - 1 : 0;
    }
    else if (msg_didout) {
        msg_putchar ('\n');
        did_return = TRUE;
        if (exmode_active != EXMODE_NORMAL)
            cmdline_row = msg_row;
    }
    if (!msg_didany || lines_left < 0)
        msg_starthere ();
    if (msg_silent == 0) {
        msg_didout = FALSE;
        cursor_off ();
    }
    if (!did_return)
        redir_write ((char_u *) "\n", -1);
}

void msg_clr_eos (void) {
    if (msg_silent == 0)
        msg_clr_eos_force ();
}

void msg_clr_eos_force (void) {
    if (msg_use_printf ()) {
        if (full_screen) {
            if (*T_CD)
                out_str (T_CD);
            else if (*T_CE)
                out_str (T_CE);
        }
    }
    else {
        if (cmdmsg_rl) {
            screen_fill (msg_row, msg_row + 1, 0, msg_col + 1, ' ', ' ', 0);
            screen_fill (msg_row + 1, (int) Rows, 0, (int) Columns, ' ', ' ', 0);
        }
        else {
            screen_fill (msg_row, msg_row + 1, msg_col, (int) Columns, ' ', ' ', 0);
            screen_fill (msg_row + 1, (int) Rows, 0, (int) Columns, ' ', ' ', 0);
        }
    }
}

int msg_use_printf (void) {
    return (!msg_check_screen () || (swapping_screen () && !termcap_active));
}

static int msg_check_screen (void) {
    if (!full_screen || !screen_valid (FALSE))
        return FALSE;
    if (msg_row >= Rows)
        msg_row = Rows - 1;
    if (msg_col >= Columns)
        msg_col = Columns - 1;
    return TRUE;
}

void msg_putchar (int c) {
    msg_putchar_attr (c, 0);
}

void msg_putchar_attr (int c, int attr) {
    char_u buf [4];
    if (IS_SPECIAL (c)) {
        buf[0] = K_SPECIAL;
        buf[1] = K_SECOND (c);
        buf[2] = K_THIRD (c);
        buf[3] = NUL;
    }
    else {
        buf[0] = c;
        buf[1] = NUL;
    }
    msg_puts_attr (buf, attr);
}

void msg_puts_attr (char_u *s, int attr) {
    msg_puts_attr_len (s, - 1, attr);
}

static void msg_puts_attr_len (char_u *str, int maxlen, int attr) {
    redir_write (str, maxlen);
    if (msg_silent != 0)
        return;
    if ((attr & MSG_HIST) && maxlen < 0) {
        add_msg_hist (str, - 1, attr);
        attr &= ~MSG_HIST;
    }
    if (msg_scrolled != 0 && !msg_scrolled_ign)
        need_wait_return = TRUE;
    msg_didany = TRUE;
    if (msg_use_printf ())
        msg_puts_printf (str, maxlen);
    else
        msg_puts_display (str, maxlen, attr, FALSE);
}

static void redir_write (char_u *str, int maxlen) {
    char_u *s = str;
    static int cur_col = 0;
    if (redir_off)
        return;
    if (*p_vfile != NUL && verbose_fd == NULL)
        verbose_open ();
    if (redirecting ()) {
        if (*s != '\n' && *s != '\r') {
            while (cur_col < msg_col) {
                if (redir_execute)
                    execute_redir_str ((char_u *) " ", -1);
                else if (redir_reg)
                    write_reg_contents (redir_reg, (char_u *) " ", -1, TRUE);
                else if (redir_vname)
                    var_redir_str ((char_u *) " ", -1);
                else if (redir_fd != NULL)
                    fputs (" ", redir_fd);
                if (verbose_fd != NULL)
                    fputs (" ", verbose_fd);
                ++cur_col;
            }
        }
        if (redir_execute)
            execute_redir_str (s, maxlen);
        else if (redir_reg)
            write_reg_contents (redir_reg, s, maxlen, TRUE);
        else if (redir_vname)
            var_redir_str (s, maxlen);
        while (*s != NUL && (maxlen < 0 || (int) (s - str) < maxlen)) {
            if (!redir_reg && !redir_vname && !redir_execute)
                if (redir_fd != NULL)
                    putc (*s, redir_fd);
            if (verbose_fd != NULL)
                putc (*s, verbose_fd);
            if (*s == '\r' || *s == '\n')
                cur_col = 0;
            else if (*s == '\t')
                cur_col += (8 - cur_col % 8);
            else
                ++cur_col;
            ++s;
        }
        if (msg_silent != 0)
            msg_col = cur_col;
    }
}

int verbose_open (void) {
    if (verbose_fd == NULL && !verbose_did_open) {
        verbose_did_open = TRUE;
        verbose_fd = mch_fopen ((char *) p_vfile, "a");
        if (verbose_fd == NULL) {
            EMSG2 (_ (e_notopen), p_vfile);
            return FAIL;
        }
    }
    return OK;
}

int redirecting (void) {
    return redir_fd != NULL || *p_vfile != NUL || redir_reg || redir_vname || redir_execute;
}

void emsg_invreg (int name) {
    EMSG2 (_ ("E354: Invalid register name: '%s'"), transchar (name));
}

void verbose_enter (void) {
    if (*p_vfile != NUL)
        ++msg_silent;
}

void verbose_leave (void) {
    if (*p_vfile != NUL)
        if (--msg_silent < 0)
            msg_silent = 0;
}

void verbose_enter_scroll (void) {
    if (*p_vfile != NUL)
        ++msg_silent;
    else
        msg_scroll = TRUE;
}

void msg_puts (char_u *s) {
    msg_puts_attr (s, 0);
}

void verbose_leave_scroll (void) {
    if (*p_vfile != NUL) {
        if (--msg_silent < 0)
            msg_silent = 0;
    }
    else
        cmdline_row = msg_row;
}

void msg_source (int attr) {
    char_u *p;
    ++no_wait_return;
    p = get_emsg_source ();
    if (p != NULL) {
        msg_attr (p, attr);
        vim_free (p);
    }
    p = get_emsg_lnum ();
    if (p != NULL) {
        msg_attr (p, HL_ATTR (HLF_N));
        vim_free (p);
        last_sourcing_lnum = sourcing_lnum;
    }
    if (sourcing_name == NULL || other_sourcing_name ()) {
        vim_free (last_sourcing_name);
        if (sourcing_name == NULL)
            last_sourcing_name = NULL;
        else
            last_sourcing_name = vim_strsave (sourcing_name);
    }
    --no_wait_return;
}

static char_u *get_emsg_source (void) {
    char_u *Buf, *p;
    if (sourcing_name != NULL && other_sourcing_name ()) {
        p = (char_u *) _ ("Error detected while processing %s:");
        Buf = alloc ((unsigned ) (STRLEN (sourcing_name) + STRLEN (p)));
        if (Buf != NULL)
            sprintf ((char *) Buf, (char *) p, sourcing_name);
        return Buf;
    }
    return NULL;
}

static int other_sourcing_name (void) {
    if (sourcing_name != NULL) {
        if (last_sourcing_name != NULL)
            return STRCMP (sourcing_name, last_sourcing_name) != 0;
        return TRUE;
    }
    return FALSE;
}

int msg_attr (char_u *s, int attr) {
    return msg_attr_keep (s, attr, FALSE);
}

static char_u *get_emsg_lnum (void) {
    char_u *Buf, *p;
    if (sourcing_name != NULL && (other_sourcing_name () || sourcing_lnum != last_sourcing_lnum) && sourcing_lnum != 0) {
        p = (char_u *) _ ("line %4ld:");
        Buf = alloc ((unsigned ) (STRLEN (p) + 20));
        if (Buf != NULL)
            sprintf ((char *) Buf, (char *) p, (long ) sourcing_lnum);
        return Buf;
    }
    return NULL;
}

int msg_end (void) {
    if (!exiting && need_wait_return && !(State & CMDLINE)) {
        wait_return (FALSE);
        return FALSE;
    }
    out_flush ();
    return TRUE;
}

void wait_return (int redraw) {
    int c;
    int oldState;
    int tmpState;
    int had_got_int;
    int save_Recording;
    FILE *save_scriptout;
    if (redraw == TRUE)
        must_redraw = CLEAR;
    if (msg_silent != 0)
        return;
    if (vgetc_busy > 0)
        return;
    need_wait_return = TRUE;
    if (no_wait_return) {
        if (!exmode_active)
            cmdline_row = msg_row;
        return;
    }
    redir_off = TRUE;
    oldState = State;
    if (quit_more) {
        c = CAR;
        quit_more = FALSE;
        got_int = FALSE;
    }
    else if (exmode_active) {
        MSG_PUTS (" ");
        c = CAR;
        got_int = FALSE;
    }
    else {
        screenalloc (FALSE);
        State = HITRETURN;
        setmouse ();
        cmdline_row = msg_row;
        if (need_check_timestamps)
            check_timestamps (FALSE);
        hit_return_msg ();
        do {
            had_got_int = got_int;
            ++no_mapping;
            ++allow_keys;
            save_Recording = Recording;
            save_scriptout = scriptout;
            Recording = FALSE;
            scriptout = NULL;
            c = safe_vgetc ();
            if (had_got_int && !global_busy)
                got_int = FALSE;
            --no_mapping;
            --allow_keys;
            Recording = save_Recording;
            scriptout = save_scriptout;
            if (p_more && !p_cp) {
                if (c == 'b' || c == 'k' || c == 'u' || c == 'g' || c == K_UP || c == K_PAGEUP) {
                    if (msg_scrolled > Rows)
                        do_more_prompt (c);
                    else {
                        msg_didout = FALSE;
                        c = K_IGNORE;
                        msg_col = cmdmsg_rl ? Columns - 1 : 0;
                    }
                    if (quit_more) {
                        c = CAR;
                        quit_more = FALSE;
                        got_int = FALSE;
                    }
                    else if (c != K_IGNORE) {
                        c = K_IGNORE;
                        hit_return_msg ();
                    }
                }
                else if (msg_scrolled > Rows - 2 && (c == 'j' || c == 'd' || c == 'f' || c == K_DOWN || c == K_PAGEDOWN))
                    c = K_IGNORE;
            }
        }
        while ((had_got_int && c == Ctrl_C) || c == K_IGNORE || c == K_VER_SCROLLBAR || c == K_HOR_SCROLLBAR || c == K_LEFTDRAG || c == K_LEFTRELEASE || c == K_MIDDLEDRAG || c == K_MIDDLERELEASE || c == K_RIGHTDRAG || c == K_RIGHTRELEASE || c == K_MOUSELEFT || c == K_MOUSERIGHT || c == K_MOUSEDOWN || c == K_MOUSEUP || c == K_MOUSEMOVE || (!mouse_has (MOUSE_RETURN) && mouse_row < msg_row && (c == K_LEFTMOUSE || c == K_MIDDLEMOUSE || c == K_RIGHTMOUSE || c == K_X1MOUSE || c == K_X2MOUSE)) || c == K_SWIPELEFT || c == K_SWIPERIGHT || c == K_SWIPEUP || c == K_SWIPEDOWN);
        ui_breakcheck ();
        if (c == K_LEFTMOUSE || c == K_MIDDLEMOUSE || c == K_RIGHTMOUSE || c == K_X1MOUSE || c == K_X2MOUSE)
            (void) jump_to_mouse (MOUSE_SETPOS, NULL, 0);
        else if (vim_strchr ((char_u *) "\r\n ", c) == NULL && c != Ctrl_C) {
            ins_char_typebuf (c);
            do_redraw = TRUE;
        }
    }
    redir_off = FALSE;
    if (c == ':' || c == '?' || c == '/') {
        if (!exmode_active)
            cmdline_row = msg_row;
        skip_redraw = TRUE;
        do_redraw = FALSE;
    }
    tmpState = State;
    State = oldState;
    setmouse ();
    msg_check ();
    if (swapping_screen () && !termcap_active)
        newline_on_exit = TRUE;
    need_wait_return = FALSE;
    did_wait_return = TRUE;
    emsg_on_display = FALSE;
    lines_left = -1;
    reset_last_sourcing ();
    if (keep_msg != NULL && vim_strsize (keep_msg) >= (Rows - cmdline_row - 1) * Columns + sc_col)
        VIM_CLEAR (keep_msg);
    if (tmpState == SETWSIZE) {
        starttermcap ();
        shell_resized ();
    }
    else if (!skip_redraw && (redraw == TRUE || (msg_scrolled != 0 && redraw != -1))) {
        starttermcap ();
        redraw_later (VALID);
    }
}

void msg_outnum (long  n) {
    char_u buf [20];
    sprintf ((char *) buf, "%ld", n);
    msg_puts (buf);
}

void trunc_string (char_u *s, char_u *buf, int room_in, int buflen) {
    size_t room = room_in - 3;
    size_t half;
    size_t len = 0;
    int e;
    int i;
    int n;
    if (room_in < 3)
        room = 0;
    half = room / 2;
    for (e = 0; len < half && e < buflen; ++e) {
        if (s[e] == NUL) {
            buf[e] = NUL;
            return;
        }
        n = ptr2cells (s +e);
        if (len + n > half)
            break;
        len += n;
        buf[e] = s[e];
    }
    i = e;
    {
        for (i = (int) STRLEN (s); len + (n = ptr2cells (s +i - 1)) <= room; --i)
            len += n;
    }
    if (i <= e + 3) {
        if (s != buf) {
            len = STRLEN (s);
            if (len >= (size_t) buflen)
                len = buflen - 1;
            len = len - e + 1;
            if (len < 1)
                buf[e - 1] = NUL;
            else
                mch_memmove (buf +e, s +e, len);
        }
    }
    else if (e + 3 < buflen) {
        mch_memmove (buf + e, "...", (size_t) 3);
        len = STRLEN (s +i) + 1;
        if (len >= (size_t) buflen - e - 3)
            len = buflen - e - 3 - 1;
        mch_memmove (buf + e + 3, s + i, len);
        buf[e + 3 + len - 1] = NUL;
    }
    else {
        buf[e - 1] = NUL;
    }
}

void repeat_message (void) {
    if (State == ASKMORE) {
        msg_moremsg (TRUE);
        msg_row = Rows - 1;
    }
    else if (State == CONFIRM) {
        display_confirm_msg ();
        msg_row = Rows - 1;
    }
    else if (State == EXTERNCMD) {
        windgoto (msg_row, msg_col);
    }
    else if (State == HITRETURN || State == SETWSIZE) {
        if (msg_row == Rows - 1) {
            msg_didout = FALSE;
            msg_col = 0;
            msg_clr_eos ();
        }
        hit_return_msg ();
        msg_row = Rows - 1;
    }
}

void msg_moremsg (int full) {
    int attr;
    char_u *s = (char_u *) _ ("-- More --");
    attr = HL_ATTR (HLF_M);
    screen_puts (s, (int) Rows - 1, 0, attr);
    if (full)
        screen_puts ((char_u *) _ (" SPACE/d/j: screen/page/line down, b/u/k: up, q: quit "), (int) Rows - 1, vim_strsize (s), attr);
}

void display_confirm_msg (void) {
    ++confirm_msg_used;
    if (confirm_msg != NULL)
        msg_puts_attr (confirm_msg, HL_ATTR (HLF_M));
    --confirm_msg_used;
}

static void hit_return_msg (void) {
    int save_p_more = p_more;
    p_more = FALSE;
    if (msg_didout)
        msg_putchar ('\n');
    if (got_int)
        MSG_PUTS (_ ("Interrupt: "));
    MSG_PUTS_ATTR (_ ("Press ENTER or type command to continue"), HL_ATTR (HLF_R));
    if (!msg_use_printf ())
        msg_clr_eos ();
    p_more = save_p_more;
}

int msg_outtrans_len (char_u *str, int len) {
    return msg_outtrans_len_attr (str, len, 0);
}

int msg_outtrans_len_attr (char_u *msgstr, int len, int attr) {
    int retval = 0;
    char_u *str = msgstr;
    char_u *plain_start = msgstr;
    char_u *s;
    if (attr & MSG_HIST) {
        add_msg_hist (str, len, attr);
        attr &= ~MSG_HIST;
    }
    while (--len >= 0) {
        {
            s = transchar_byte (*str);
            if (s[1] != NUL) {
                if (str > plain_start)
                    msg_puts_attr_len (plain_start, (int) (str - plain_start), attr);
                plain_start = str + 1;
                msg_puts_attr (s, attr == 0 ? HL_ATTR (HLF_8) : attr);
                retval += (int) STRLEN (s);
            }
            else
                ++retval;
            ++str;
        }
    }
    if (str > plain_start)
        msg_puts_attr_len (plain_start, (int) (str - plain_start), attr);
    return retval;
}

void give_warning (char_u *message, int hl) {
    if (msg_silent != 0)
        return;
    ++no_wait_return;
    set_vim_var_string (VV_WARNINGMSG, message, - 1);
    VIM_CLEAR (keep_msg);
    if (hl)
        keep_msg_attr = HL_ATTR (HLF_W);
    else
        keep_msg_attr = 0;
    if (msg_attr (message, keep_msg_attr) && msg_scrolled == 0)
        set_keep_msg (message, keep_msg_attr);
    msg_didout = FALSE;
    msg_nowait = TRUE;
    msg_col = 0;
    --no_wait_return;
}

void msg_clr_cmdline (void) {
    msg_row = cmdline_row;
    msg_col = 0;
    msg_clr_eos_force ();
}

int emsg (char_u *s) {
    int attr;
    char_u *p;
    int r;
    int ignore = FALSE;
    int severe;
    if (emsg_not_now ())
        return TRUE;
    if (ignore_error (s))
        return msg_use_printf () ? FALSE : msg (s);
    called_emsg = TRUE;
    severe = emsg_severe;
    emsg_severe = FALSE;
    if (!emsg_off || vim_strchr (p_debug, 't') != NULL) {
        if (cause_errthrow (s, severe, &ignore) == TRUE) {
            if (!ignore)
                did_emsg = TRUE;
            return TRUE;
        }
        set_vim_var_string (VV_ERRMSG, s, - 1);
        if (emsg_silent != 0) {
            if (emsg_noredir == 0) {
                msg_start ();
                p = get_emsg_source ();
                if (p != NULL) {
                    STRCAT (p, "\n");
                    redir_write (p, - 1);
                    vim_free (p);
                }
                p = get_emsg_lnum ();
                if (p != NULL) {
                    STRCAT (p, "\n");
                    redir_write (p, - 1);
                    vim_free (p);
                }
                redir_write (s, - 1);
            }
            ch_log (NULL, "ERROR: %s", (char *) s);
            return TRUE;
        }
        ex_exitval = 1;
        msg_silent = 0;
        cmd_silent = FALSE;
        if (global_busy)
            ++global_busy;
        if (p_eb)
            beep_flush ();
        else
            flush_buffers (FALSE);
        did_emsg = TRUE;
        did_uncaught_emsg = TRUE;
    }
    emsg_on_display = TRUE;
    ++msg_scroll;
    attr = HL_ATTR (HLF_E);
    if (msg_scrolled != 0)
        need_wait_return = TRUE;
    emsg_to_channel_log = TRUE;
    msg_source (attr);
    msg_nowait = FALSE;
    r = msg_attr (s, attr);
    emsg_to_channel_log = FALSE;
    return r;
}

int emsg_not_now (void) {
    if ((emsg_off > 0 && vim_strchr (p_debug, 'm') == NULL && vim_strchr (p_debug, 't') == NULL) || emsg_skip > 0)
        return TRUE;
    return FALSE;
}

int vim_snprintf_add (char *str, size_t str_m, char *fmt, ... ) {
    va_list ap;
    int str_l;
    size_t len = STRLEN (str);
    size_t space;
    if (str_m <= len)
        space = 0;
    else
        space = str_m - len;
    va_start (ap, fmt);
    str_l = vim_vsnprintf (str +len, space, fmt, ap);
    va_end (ap);
    return str_l;
}

int vim_dialog_yesno (int type, char_u *title, char_u *message, int dflt) {
    if (do_dialog (type, title == NULL ? (char_u *) _ ("Question") : title, message, (char_u *) _ ("&Yes\n&No"), dflt, NULL, FALSE) == 1)
        return VIM_YES;
    return VIM_NO;
}

int do_dialog (int type, char_u *title, char_u *message, char_u *buttons, int dfltbutton, char_u *textfield, int ex_cmd) {
    int oldState;
    int retval = 0;
    char_u *hotkeys;
    int c;
    int i;
    if (silent_mode)
        return dfltbutton;
    if (gui.in_use && vim_strchr (p_go, GO_CONDIALOG) == NULL) {
        c = gui_mch_dialog (type, title, message, buttons, dfltbutton, textfield, ex_cmd);
        need_wait_return = FALSE;
        emsg_on_display = FALSE;
        cmdline_row = msg_row;
        out_flush ();
        gui_mch_update ();
        return c;
    }
    oldState = State;
    State = CONFIRM;
    setmouse ();
    ++no_wait_return;
    hotkeys = msg_show_console_dialog (message, buttons, dfltbutton);
    if (hotkeys != NULL) {
        for (;;) {
            c = get_keystroke ();
            switch (c) {
            case CAR :
            case NL :
                retval = dfltbutton;
                break;
            case Ctrl_C :
            case ESC :
                retval = 0;
                break;
            default :
                if (c < 0)
                    continue;
                if (c == ':' && ex_cmd) {
                    retval = dfltbutton;
                    ins_char_typebuf (':');
                    break;
                }
                c = MB_TOLOWER (c);
                retval = 1;
                for (i = 0; hotkeys[i]; ++i) {
                    if (hotkeys[i] == c)
                        break;
                    ++retval;
                }
                if (hotkeys[i])
                    break;
                continue;
            }
            break;
        }
        vim_free (hotkeys);
    }
    State = oldState;
    setmouse ();
    --no_wait_return;
    msg_end_prompt ();
    return retval;
}

static char_u *msg_show_console_dialog (char_u *message, char_u *buttons, int dfltbutton) {
    int len = 0;

    # define HOTK_LEN 1
    int lenhotkey = HOTK_LEN;
    char_u *hotk = NULL;
    char_u *msgp = NULL;
    char_u *hotkp = NULL;
    char_u *r;
    int copy;

    #define HAS_HOTKEY_LEN 30
    char_u has_hotkey [HAS_HOTKEY_LEN];
    int first_hotkey = FALSE;
    int idx;
    has_hotkey[0] = FALSE;
    for (copy = 0; copy <= 1; ++copy) {
        r = buttons;
        idx = 0;
        while (*r) {
            if (*r == DLG_BUTTON_SEP) {
                if (copy) {
                    *msgp++ = ',';
                    *msgp++ = ' ';
                    ++hotkp;
                    hotkp[copy_char (r +1, hotkp, TRUE)] = NUL;
                    if (dfltbutton)
                        --dfltbutton;
                    if (idx < HAS_HOTKEY_LEN - 1 && !has_hotkey[++idx])
                        first_hotkey = TRUE;
                }
                else {
                    len += 3;
                    lenhotkey += HOTK_LEN;
                    if (idx < HAS_HOTKEY_LEN - 1)
                        has_hotkey[++idx] = FALSE;
                }
            }
            else if (*r == DLG_HOTKEY_CHAR || first_hotkey) {
                if (*r == DLG_HOTKEY_CHAR)
                    ++r;
                first_hotkey = FALSE;
                if (copy) {
                    if (*r == DLG_HOTKEY_CHAR)
                        *msgp++ = *r;
                    else {
                        *msgp++ = (dfltbutton == 1) ? '[' : '(';
                        msgp += copy_char (r, msgp, FALSE);
                        *msgp++ = (dfltbutton == 1) ? ']' : ')';
                        hotkp[copy_char (r, hotkp, TRUE)] = NUL;
                    }
                }
                else {
                    ++len;
                    if (idx < HAS_HOTKEY_LEN - 1)
                        has_hotkey[idx] = TRUE;
                }
            }
            else {
                if (copy)
                    msgp += copy_char (r, msgp, FALSE);
            }
            MB_PTR_ADV (r);
        }
        if (copy) {
            *msgp++ = ':';
            *msgp++ = ' ';
            *msgp = NUL;
        }
        else {
            len += (int) (STRLEN (message) + 2 + STRLEN (buttons) + 3);
            lenhotkey++;
            if (!has_hotkey[0]) {
                first_hotkey = TRUE;
                len += 2;
            }
            vim_free (confirm_msg);
            confirm_msg = alloc (len);
            if (confirm_msg == NULL)
                return NULL;
            *confirm_msg = NUL;
            hotk = alloc (lenhotkey);
            if (hotk == NULL)
                return NULL;
            *confirm_msg = '\n';
            STRCPY (confirm_msg + 1, message);
            msgp = confirm_msg + 1 + STRLEN (message);
            hotkp = hotk;
            hotkp[copy_char (buttons, hotkp, TRUE)] = NUL;
            confirm_msg_tail = msgp;
            *msgp++ = '\n';
        }
    }
    display_confirm_msg ();
    return hotk;
}

int msg_outtrans (char_u *str) {
    return msg_outtrans_attr (str, 0);
}

int msg_outtrans_attr (char_u *str, int attr) {
    return msg_outtrans_len_attr (str, (int) STRLEN (str), attr);
}

void msg_advance (int col) {
    if (msg_silent != 0) {
        msg_col = col;
        return;
    }
    if (col >= Columns)
        col = Columns - 1;
    if (cmdmsg_rl)
        while (msg_col > Columns - col)
            msg_putchar (' ');
        else
            while (msg_col < col)
                msg_putchar (' ');
}

int msg_outtrans_special (char_u *strstart, int from) {
    char_u *str = strstart;
    int retval = 0;
    char_u *string;
    int attr;
    int len;
    attr = HL_ATTR (HLF_8);
    while (*str != NUL) {
        if ((str == strstart || str[1] == NUL) && *str == ' ') {
            string = (char_u *) "<Space>";
            ++str;
        }
        else
            string = str2special (&str, from);
        len = vim_strsize (string);
        msg_puts_attr (string, len > 1 ? attr : 0);
        retval += len;
    }
    return retval;
}

char_u *str2special (char_u **sp, int from) {
    int c;
    static char_u buf [7];
    char_u *str = *sp;
    int modifiers = 0;
    int special = FALSE;
    c = *str;
    if (c == K_SPECIAL && str[1] != NUL && str[2] != NUL) {
        if (str[1] == KS_MODIFIER) {
            modifiers = str[2];
            str += 3;
            c = *str;
        }
        if (c == K_SPECIAL && str[1] != NUL && str[2] != NUL) {
            c = TO_SPECIAL (str[1], str[2]);
            str += 2;
            if (c == KS_ZERO)
                c = NUL;
        }
        if (IS_SPECIAL (c) || modifiers)
            special = TRUE;
    }
    *sp = str + 1;
    if (special || char2cells (c) > 1 || (from && c == ' '))
        return get_special_key_name (c, modifiers);
    buf[0] = c;
    buf[1] = NUL;
    return buf;
}

void verbose_stop (void) {
    if (verbose_fd != NULL) {
        fclose (verbose_fd);
        verbose_fd = NULL;
    }
    verbose_did_open = FALSE;
}

void set_keep_msg_from_hist (void) {
    if (keep_msg == NULL && last_msg_hist != NULL && msg_scrolled == 0 && (State & NORMAL))
        set_keep_msg (last_msg_hist->msg, last_msg_hist->attr);
}

void msg_end_prompt (void) {
    need_wait_return = FALSE;
    emsg_on_display = FALSE;
    cmdline_row = msg_row;
    msg_col = 0;
    msg_clr_eos ();
    lines_left = -1;
}

void msg_home_replace (char_u *fname) {
    msg_home_replace_attr (fname, 0);
}

static void msg_home_replace_attr (char_u *fname, int attr) {
    char_u *name;
    name = home_replace_save (NULL, fname);
    if (name != NULL)
        msg_outtrans_attr (name, attr);
    vim_free (name);
}

void msg_check (void) {
    if (msg_row == Rows - 1 && msg_col >= sc_col) {
        need_wait_return = TRUE;
        redraw_cmdline = TRUE;
    }
}

void str2specialbuf (char_u *sp, char_u *buf, int len) {
    char_u *s;
    *buf = NUL;
    while (*sp) {
        s = str2special (&sp, FALSE);
        if ((int) (STRLEN (s) + STRLEN (buf)) < len)
            STRCAT (buf, s);
    }
}

char_u *msg_may_trunc (int force, char_u *s) {
    int n;
    int room;
    room = (int) (Rows - cmdline_row - 1) * Columns + sc_col - 1;
    if ((force || (shortmess (SHM_TRUNC) && !exmode_active)) && (n = (int) STRLEN (s) - room) > 0) {
        s += n;
        *s = '<';
    }
    return s;
}

int smsg_attr (int attr, char_u *s, ... ) {
    va_list arglist;
    va_start (arglist, s);
    vim_vsnprintf ((char *) IObuff, IOSIZE, (char *) s, arglist);
    va_end (arglist);
    return msg_attr (IObuff, attr);
}

char_u *msg_trunc_attr (char_u *s, int force, int attr) {
    int n;
    add_msg_hist (s, - 1, attr);
    s = msg_may_trunc (force, s);
    msg_hist_off = TRUE;
    n = msg_attr (s, attr);
    msg_hist_off = FALSE;
    if (n)
        return s;
    return NULL;
}

int verb_msg (char_u *s) {
    int n;
    verbose_enter ();
    n = msg_attr_keep (s, 0, FALSE);
    verbose_leave ();
    return n;
}

int vim_dialog_yesnoallcancel (int type, char_u *title, char_u *message, int dflt) {
    switch (do_dialog (type, title == NULL ? (char_u *) "Question" : title, message, (char_u *) _ ("&Yes\n&No\nSave &All\n&Discard All\n&Cancel"), dflt, NULL, FALSE)) {
    case 1 :
        return VIM_YES;
    case 2 :
        return VIM_NO;
    case 3 :
        return VIM_ALL;
    case 4 :
        return VIM_DISCARDALL;
    }
    return VIM_CANCEL;
}

int vim_dialog_yesnocancel (int type, char_u *title, char_u *message, int dflt) {
    switch (do_dialog (type, title == NULL ? (char_u *) _ ("Question") : title, message, (char_u *) _ ("&Yes\n&No\n&Cancel"), dflt, NULL, FALSE)) {
    case 1 :
        return VIM_YES;
    case 2 :
        return VIM_NO;
    }
    return VIM_CANCEL;
}

void may_clear_sb_text (void) {
    do_clear_sb_text = SB_CLEAR_ALL;
}

void msg_prt_line (char_u *s, int list) {
    int c;
    int col = 0;
    int n_extra = 0;
    int c_extra = 0;
    char_u *p_extra = NULL;
    int n;
    int attr = 0;
    char_u *trail = NULL;
    if (curwin->w_p_list)
        list = TRUE;
    if (list && lcs_trail) {
        trail = s + STRLEN (s);
        while (trail > s && VIM_ISWHITE (trail[-1]))
            --trail;
    }
    if (*s == NUL && !(list && lcs_eol != NUL))
        msg_putchar (' ');
    while (!got_int) {
        if (n_extra > 0) {
            --n_extra;
            if (c_extra)
                c = c_extra;
            else
                c = *p_extra++;
        }
        else {
            attr = 0;
            c = *s++;
            if (c == TAB && (!list || lcs_tab1)) {
                n_extra = curbuf->b_p_ts - col % curbuf->b_p_ts - 1;
                if (!list) {
                    c = ' ';
                    c_extra = ' ';
                }
                else {
                    c = lcs_tab1;
                    c_extra = lcs_tab2;
                    attr = HL_ATTR (HLF_8);
                }
            }
            else if (c == 160 && list && lcs_nbsp != NUL) {
                c = lcs_nbsp;
                attr = HL_ATTR (HLF_8);
            }
            else if (c == NUL && list && lcs_eol != NUL) {
                p_extra = (char_u *) "";
                c_extra = NUL;
                n_extra = 1;
                c = lcs_eol;
                attr = HL_ATTR (HLF_AT);
                --s;
            }
            else if (c != NUL && (n = byte2cells (c)) > 1) {
                n_extra = n - 1;
                p_extra = transchar_byte (c);
                c_extra = NUL;
                c = *p_extra++;
                attr = HL_ATTR (HLF_8);
            }
            else if (c == ' ' && trail != NULL && s > trail) {
                c = lcs_trail;
                attr = HL_ATTR (HLF_8);
            }
            else if (c == ' ' && list && lcs_space != NUL) {
                c = lcs_space;
                attr = HL_ATTR (HLF_8);
            }
        }
        if (c == NUL)
            break;
        msg_putchar_attr (c, attr);
        col++;
    }
    msg_clr_eos ();
}

void msg_puts_long_attr (char_u *longstr, int attr) {
    msg_puts_long_len_attr (longstr, (int) STRLEN (longstr), attr);
}

void msg_puts_long_len_attr (char_u *longstr, int len, int attr) {
    int slen = len;
    int room;
    room = Columns - msg_col;
    if (len > room && room >= 20) {
        slen = (room - 3) / 2;
        msg_outtrans_len_attr (longstr, slen, attr);
        msg_puts_attr ((char_u *) "...", HL_ATTR (HLF_8));
    }
    msg_outtrans_len_attr (longstr + len - slen, slen, attr);
}

char_u *msg_strtrunc (char_u *s, int force) {
    char_u *buf = NULL;
    int len;
    int room;
    if ((!msg_scroll && !need_wait_return && shortmess (SHM_TRUNCALL) && !exmode_active && msg_silent == 0) || force) {
        len = vim_strsize (s);
        if (msg_scrolled != 0)
            room = (int) (Rows - msg_row) * Columns - 1;
        else
            room = (int) (Rows - msg_row - 1) * Columns + sc_col - 1;
        if (len > room && room > 0) {
            len = room + 2;
            buf = alloc (len);
            if (buf != NULL)
                trunc_string (s, buf, room, len);
        }
    }
    return buf;
}

void msg_starthere (void) {
    lines_left = cmdline_row;
    msg_didany = FALSE;
}

static int do_more_prompt (int typed_char) {
    static int entered = FALSE;
    int used_typed_char = typed_char;
    int oldState = State;
    int c;
    int retval = FALSE;
    int toscroll;
    msgchunk_T *mp_last = NULL;
    msgchunk_T *mp;
    int i;
    if (entered || (State == HITRETURN && typed_char == 0))
        return FALSE;
    entered = TRUE;
    if (typed_char == 'G') {
        mp_last = msg_sb_start (last_msgchunk);
        for (i = 0; i < Rows - 2 && mp_last != NULL && mp_last->sb_prev != NULL; ++i)
            mp_last = msg_sb_start (mp_last->sb_prev);
    }
    State = ASKMORE;
    setmouse ();
    if (typed_char == NUL)
        msg_moremsg (FALSE);
    for (;;) {
        if (used_typed_char != NUL) {
            c = used_typed_char;
            used_typed_char = NUL;
        }
        else
            c = get_keystroke ();
        if (c == K_MENU) {
            int idx = get_menu_index (current_menu, ASKMORE);
            if (idx == MENU_INDEX_INVALID)
                continue;
            c = *current_menu->strings[idx];
            if (c != NUL && current_menu->strings[idx][1] != NUL)
                ins_typebuf (current_menu->strings[idx] + 1, current_menu->noremap[idx], 0, TRUE, current_menu->silent[idx]);
        }
        toscroll = 0;
        switch (c) {
        case BS :
        case K_BS :
        case 'k' :
        case K_UP :
            toscroll = -1;
            break;
        case CAR :
        case NL :
        case 'j' :
        case K_DOWN :
            toscroll = 1;
            break;
        case 'u' :
            toscroll = -(Rows / 2);
            break;
        case 'd' :
            toscroll = Rows / 2;
            break;
        case 'b' :
        case K_PAGEUP :
            toscroll = -(Rows - 1);
            break;
        case ' ' :
        case 'f' :
        case K_PAGEDOWN :
        case K_LEFTMOUSE :
            toscroll = Rows - 1;
            break;
        case 'g' :
            toscroll = -999999;
            break;
        case 'G' :
            toscroll = 999999;
            lines_left = 999999;
            break;
        case ':' :
            if (!confirm_msg_used) {
                typeahead_noflush (':');
                cmdline_row = Rows - 1;
                skip_redraw = TRUE;
                need_wait_return = FALSE;
            }
        case 'q' :
        case Ctrl_C :
        case ESC :
            if (confirm_msg_used) {
                retval = TRUE;
            }
            else {
                got_int = TRUE;
                quit_more = TRUE;
            }
            lines_left = Rows - 1;
            break;
        default :
            msg_moremsg (TRUE);
            continue;
        }
        if (toscroll != 0) {
            if (toscroll < 0) {
                if (mp_last == NULL)
                    mp = msg_sb_start (last_msgchunk);
                else if (mp_last->sb_prev != NULL)
                    mp = msg_sb_start (mp_last->sb_prev);
                else
                    mp = NULL;
                for (i = 0; i < Rows - 2 && mp != NULL && mp->sb_prev != NULL; ++i)
                    mp = msg_sb_start (mp->sb_prev);
                if (mp != NULL && mp->sb_prev != NULL) {
                    for (i = 0; i > toscroll; --i) {
                        if (mp == NULL || mp->sb_prev == NULL)
                            break;
                        mp = msg_sb_start (mp->sb_prev);
                        if (mp_last == NULL)
                            mp_last = msg_sb_start (last_msgchunk);
                        else
                            mp_last = msg_sb_start (mp_last->sb_prev);
                    }
                    if (toscroll == -1 && screen_ins_lines (0, 0, 1, (int) Rows, 0, NULL) == OK) {
                        (void) disp_sb_line (0, mp);
                    }
                    else {
                        screenclear ();
                        for (i = 0; mp != NULL && i < Rows - 1; ++i) {
                            mp = disp_sb_line (i, mp);
                            ++msg_scrolled;
                        }
                    }
                    toscroll = 0;
                }
            }
            else {
                while (toscroll > 0 && mp_last != NULL) {
                    msg_scroll_up ();
                    inc_msg_scrolled ();
                    screen_fill ((int) Rows - 2, (int) Rows - 1, 0, (int) Columns, ' ', ' ', 0);
                    mp_last = disp_sb_line ((int) Rows - 2, mp_last);
                    --toscroll;
                }
            }
            if (toscroll <= 0) {
                screen_fill ((int) Rows - 1, (int) Rows, 0, (int) Columns, ' ', ' ', 0);
                msg_moremsg (FALSE);
                continue;
            }
            lines_left = toscroll;
        }
        break;
    }
    screen_fill ((int) Rows - 1, (int) Rows, 0, (int) Columns, ' ', ' ', 0);
    State = oldState;
    setmouse ();
    if (quit_more) {
        msg_row = Rows - 1;
        msg_col = 0;
    }
    else if (cmdmsg_rl)
        msg_col = Columns - 1;
    entered = FALSE;
    return retval;
}

static msgchunk_T *msg_sb_start (msgchunk_T *mps) {
    msgchunk_T *mp = mps;
    while (mp != NULL && mp->sb_prev != NULL && !mp->sb_prev->sb_eol)
        mp = mp->sb_prev;
    return mp;
}

static msgchunk_T *disp_sb_line (int row, msgchunk_T *smp) {
    msgchunk_T *mp = smp;
    char_u *p;
    for (;;) {
        msg_row = row;
        msg_col = mp->sb_msg_col;
        p = mp->sb_text;
        if (*p == '\n')
            ++p;
        msg_puts_display (p, - 1, mp -> sb_attr, TRUE);
        if (mp->sb_eol || mp->sb_next == NULL)
            break;
        mp = mp->sb_next;
    }
    return mp->sb_next;
}

static void msg_puts_display (char_u *str, int maxlen, int attr, int recurse) {
    char_u *s = str;
    char_u *t_s = str;
    int t_col = 0;
    char_u *sb_str = str;
    int sb_col = msg_col;
    int wrap;
    int did_last_char;
    did_wait_return = FALSE;
    while ((maxlen < 0 || (int) (s - str) < maxlen) && *s != NUL) {
        if (!recurse && msg_row >= Rows - 1 && (*s == '\n' || (cmdmsg_rl ? (msg_col <= 1 || (*s == TAB && msg_col <= 7)) : (msg_col + t_col >= Columns - 1 || (*s == TAB && msg_col + t_col >= ((Columns - 1) & ~7)) || (has_mbyte && (*mb_ptr2cells) (s) > 1 && msg_col + t_col >= Columns - 2))))) {
            if (t_col > 0)
                t_puts (&t_col, t_s, s, attr);
            if (msg_no_more && lines_left == 0)
                break;
            msg_scroll_up ();
            msg_row = Rows - 2;
            if (msg_col >= Columns)
                msg_col = Columns - 1;
            if (*s >= ' ' && !cmdmsg_rl) {
                msg_screen_putchar (* s ++, attr);
                did_last_char = TRUE;
            }
            else
                did_last_char = FALSE;
            if (p_more)
                store_sb_text (&sb_str, s, attr, &sb_col, TRUE);
            inc_msg_scrolled ();
            need_wait_return = TRUE;
            redraw_cmdline = TRUE;
            if (cmdline_row > 0 && !exmode_active)
                --cmdline_row;
            if (lines_left > 0)
                --lines_left;
            if (p_more && lines_left == 0 && State != HITRETURN && !msg_no_more && !exmode_active) {
                if (do_more_prompt (NUL))
                    s = confirm_msg_tail;
                if (quit_more)
                    return;
            }
            if (did_last_char)
                continue;
        }
        wrap = *s == '\n' || msg_col + t_col >= Columns;
        if (t_col > 0 && (wrap || *s == '\r' || *s == '\b' || *s == '\t' || *s == BELL))
            t_puts (&t_col, t_s, s, attr);
        if (wrap && p_more && !recurse)
            store_sb_text (&sb_str, s, attr, &sb_col, TRUE);
        if (*s == '\n') {
            msg_didout = FALSE;
            if (cmdmsg_rl)
                msg_col = Columns - 1;
            else
                msg_col = 0;
            if (++msg_row >= Rows)
                msg_row = Rows - 1;
        }
        else if (*s == '\r') {
            msg_col = 0;
        }
        else if (*s == '\b') {
            if (msg_col)
                --msg_col;
        }
        else if (*s == TAB) {
            do
                msg_screen_putchar (' ', attr);
            while (msg_col & 7);
        }
        else if (*s == BELL)
            vim_beep (BO_SH);
        else {
            if (cmdmsg_rl) {
                msg_screen_putchar (* s, attr);
            }
            else {
                if (t_col == 0)
                    t_s = s;
                ++t_col;
            }
        }
        ++s;
    }
    if (t_col > 0)
        t_puts (&t_col, t_s, s, attr);
    if (p_more && !recurse)
        store_sb_text (&sb_str, s, attr, &sb_col, FALSE);
    msg_check ();
}

static void t_puts (int *t_col, char_u *t_s, char_u *s, int attr) {
    msg_didout = TRUE;
    screen_puts_len (t_s, (int) (s - t_s), msg_row, msg_col, attr);
    msg_col += *t_col;
    *t_col = 0;
    if (msg_col >= Columns) {
        msg_col = 0;
        ++msg_row;
    }
}

static void msg_scroll_up (void) {
    if (gui.in_use)
        gui_undraw_cursor ();
    mch_disable_flush ();
    screen_del_lines (0, 0, 1, (int) Rows, TRUE, 0, NULL);
    mch_enable_flush ();
    if (!can_clear ((char_u *) " ")) {
        screen_fill ((int) Rows - 1, (int) Rows, 0, (int) Columns, ' ', ' ', 0);
        if (ScreenAttrs[LineOffset[Rows - 2] + Columns - 1] == (sattr_T) -1)
            screen_fill ((int) Rows - 2, (int) Rows - 1, (int) Columns - 1, (int) Columns, ' ', ' ', 0);
    }
}

static void msg_screen_putchar (int c, int attr) {
    msg_didout = TRUE;
    screen_putchar (c, msg_row, msg_col, attr);
    if (cmdmsg_rl) {
        if (--msg_col == 0) {
            msg_col = Columns;
            ++msg_row;
        }
    }
    else {
        if (++msg_col >= Columns) {
            msg_col = 0;
            ++msg_row;
        }
    }
}

static void store_sb_text (char_u **sb_str, char_u *s, int attr, int *sb_col, int finish) {
    msgchunk_T *mp;
    if (do_clear_sb_text == SB_CLEAR_ALL || do_clear_sb_text == SB_CLEAR_CMDLINE_DONE) {
        clear_sb_text (do_clear_sb_text == SB_CLEAR_ALL);
        do_clear_sb_text = SB_CLEAR_NONE;
    }
    if (s > *sb_str) {
        mp = (msgchunk_T *) alloc ((int) (sizeof (msgchunk_T) + (s - *sb_str)));
        if (mp != NULL) {
            mp->sb_eol = finish;
            mp->sb_msg_col = *sb_col;
            mp->sb_attr = attr;
            vim_strncpy (mp -> sb_text, * sb_str, s - * sb_str);
            if (last_msgchunk == NULL) {
                last_msgchunk = mp;
                mp->sb_prev = NULL;
            }
            else {
                mp->sb_prev = last_msgchunk;
                last_msgchunk->sb_next = mp;
                last_msgchunk = mp;
            }
            mp->sb_next = NULL;
        }
    }
    else if (finish && last_msgchunk != NULL)
        last_msgchunk->sb_eol = TRUE;
    *sb_str = s;
    *sb_col = 0;
}

static void inc_msg_scrolled (void) {
    if (*get_vim_var_str (VV_SCROLLSTART) == NUL) {
        char_u *p = sourcing_name;
        char_u *tofree = NULL;
        int len;
        if (p == NULL)
            p = (char_u *) _ ("Unknown");
        else {
            len = (int) STRLEN (p) + 40;
            tofree = alloc (len);
            if (tofree != NULL) {
                vim_snprintf ((char *) tofree, len, _ ("%s line %ld"), p, (long) sourcing_lnum);
                p = tofree;
            }
        }
        set_vim_var_string (VV_SCROLLSTART, p, - 1);
        vim_free (tofree);
    }
    ++msg_scrolled;
    if (must_redraw < VALID)
        must_redraw = VALID;
}

void reset_last_sourcing (void) {
    VIM_CLEAR (last_sourcing_name);
    last_sourcing_lnum = 0;
}

static void msg_puts_printf (char_u *str, int maxlen) {
    char_u *s = str;
    char_u buf [4];
    char_u *p;
    while ((maxlen < 0 || (int) (s - str) < maxlen) && *s != NUL) {
        if (!(silent_mode && p_verbose == 0)) {
            p = &buf[0];
            if (*s == '\n' && !info_message)
                *p++ = '\r';
            *p++ = *s;
            *p = '\0';
            if (info_message)
                mch_msg ((char *) buf);
            else
                mch_errmsg ((char *) buf);
        }
        if (cmdmsg_rl) {
            if (*s == '\r' || *s == '\n')
                msg_col = Columns - 1;
            else
                --msg_col;
        }
        else {
            if (*s == '\r' || *s == '\n')
                msg_col = 0;
            else
                ++msg_col;
        }
        ++s;
    }
    msg_didout = TRUE;
}

