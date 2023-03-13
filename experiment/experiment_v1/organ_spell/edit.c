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
struct m_info {
    short_u m_size;
    minfo_T *m_next;
};
struct foldinfo {
    int fi_level;
    int fi_lnum;
    int fi_low_level;
};
struct filemark {
    pos_T mark;
    int fnum;
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
struct buffheader {
    buffblock_T bh_first;
    buffblock_T *bh_curr;
    int bh_index;
    int bh_space;
};
struct stl_hlrec {
    char_u *start;
    int userhl;
};
struct nfa_state {
    int c;
    nfa_state_T *out;
    nfa_state_T *out1;
    int id;
    int lastlist [2];
    int val;
};
struct regengine {
    regprog_T * (*regcomp) (char_u *, int);
    void (*regfree) (regprog_T *);
    int (*regexec_nl) (regmatch_T *, char_u *, colnr_T, int);
    long  (*regexec_multi) (regmmatch_T *, win_T *, buf_T *, linenr_T, colnr_T, proftime_T *, int *);
    char_u *expr;
};
struct diffblock_S {
    diff_T *df_next;
    linenr_T df_lnum [DB_COUNT];
    linenr_T df_count [DB_COUNT];
};
struct hashitem_S {
    long_u hi_hash;
    char_u *hi_key;
};
struct mf_hashitem_S {
    mf_hashitem_T *mhi_next;
    mf_hashitem_T *mhi_prev;
    blocknr_T mhi_key;
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
struct regprog {
    regengine_T *engine;
    unsigned  regflags;
    unsigned  re_engine;
    unsigned  re_flags;
};
struct spelltab_S {
    char_u st_isw [256];
    char_u st_isu [256];
    char_u st_fold [256];
    char_u st_upper [256];
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
struct compl_S {
    compl_T *cp_next;
    compl_T *cp_prev;
    char_u *cp_str;
    char cp_icase;
    char_u * (cp_text [CPT_COUNT]);
    char_u *cp_fname;
    int cp_flags;
    int cp_number;
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
struct buf_state {
    int bs_idx;
    int bs_flags;
    int bs_seqnr;
    int bs_cchar;
    reg_extmatch_T *bs_extmatch;
};
struct growarray {
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    int ga_growsize;
    void *ga_data;
};
struct msglist {
    char_u *msg;
    char_u *throw_msg;
    struct msglist *next;
};
struct vim_exception {
    except_type_T type;
    char_u *value;
    struct msglist *messages;
    char_u *throw_name;
    linenr_T throw_lnum;
    except_T *caught;
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
struct u_entry {
    u_entry_T *ue_next;
    linenr_T ue_top;
    linenr_T ue_bot;
    linenr_T ue_lcount;
    char_u **ue_array;
    long  ue_size;
};
struct buffblock {
    buffblock_T *b_next;
    char_u b_str [1];
};
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
char e_hitend [] = N_ ("Hit end of paragraph");
EXTERN char_u e_listreq [] INIT (= N_ ("E714: List required"));
EXTERN alist_T global_alist;
EXTERN char_u e_readonlyvar [] INIT (= N_ ("E46: Cannot change read-only variable \"%s\""));
EXTERN char_u e_noroom [] INIT (= N_ ("E36: Not enough room"));
EXTERN char_u e_invarg2 [] INIT (= N_ ("E475: Invalid argument: %s"));
EXTERN char_u e_invarg [] INIT (= N_ ("E474: Invalid argument"));
EXTERN char_u wim_flags [4];
EXTERN char breakat_flags [256];
EXTERN unsigned  vop_flags;
EXTERN unsigned  ttym_flags;
EXTERN unsigned  tbis_flags;
EXTERN unsigned  toolbar_flags;
EXTERN unsigned  ssop_flags;
EXTERN unsigned  fuoptions_flags;
EXTERN unsigned  dy_flags;
EXTERN unsigned  bo_flags;
EXTERN win_T *au_pending_free_win INIT (= NULL);
EXTERN char_u e_umark [] INIT (= N_ ("E78: Unknown mark"));
EXTERN char_u e_marknotset [] INIT (= N_ ("E20: Mark not set"));
EXTERN char *font_argument INIT (= NULL);
EXTERN int p_guipty;
EXTERN char_u *p_guifont;
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
EXTERN FILE *scriptout INIT (= NULL);
EXTERN FILE *scriptin [NSCRIPT];
EXTERN win_T *aucmd_win;
EXTERN char_u *use_gvimrc INIT (= NULL);
EXTERN int called_vim_beep;
EXTERN dict_T globvardict;
EXTERN dict_T vimvardict;
EXTERN int cmdline_row;
EXTERN sattr_T *ScreenAttrs INIT (= NULL);
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
EXTERN int p_icon;
EXTERN char_u *p_penc;
EXTERN int p_fullscreen;
EXTERN char_u *p_fcl;
EXTERN long  p_fic;
EXTERN char_u *p_dict;
EXTERN char_u *p_cot;
EXTERN int p_cp;
EXTERN long  p_ch;
EXTERN int p_beval;
EXTERN char_u *p_cm;
EXTERN unsigned  bkc_flags;
EXTERN char_u *p_bkc;
EXTERN int p_acd;
int compl_opt_refresh_always = FALSE;
expand_T compl_xp;
int compl_cont_mode = 0;
char_u *compl_orig_text = NULL;
int compl_pending = 0;
int compl_shows_dir = FORWARD;
int compl_direction = FORWARD;
int compl_was_interrupted = FALSE;
int compl_no_select = FALSE;
int compl_no_insert = FALSE;
char_u *compl_leader = NULL;
EXTERN proftime_T bevalexpr_due;
EXTERN char_u e_invexpr2 [] INIT (= N_ ("E15: Invalid expression: %s"));
EXTERN char_u *p_pexpr;
EXTERN char_u *p_bexpr;
EXTERN char_u e_prev_dir [] INIT (= N_ ("E459: Cannot go back to previous directory"));
EXTERN char_u e_noprevre [] INIT (= N_ ("E35: No previous regular expression"));
EXTERN char_u e_noprev [] INIT (= N_ ("E34: No previous command"));
EXTERN win_T *prevwin INIT (= NULL);
EXTERN char_u e_au_recursive [] INIT (= N_ ("E952: Autocommand caused recursive behavior"));
EXTERN char_u e_curdir [] INIT (= N_ ("E12: Command not allowed from exrc/vimrc in current dir or tag search"));
EXTERN int current_scrollbar;
EXTERN vimmenu_T *current_menu;
EXTERN except_T *current_exception;
EXTERN int p_secure;
EXTERN char_u e_bufloaded [] INIT (= N_ ("E139: File is loaded in another buffer"));
EXTERN char_u e_nobufnr [] INIT (= N_ ("E86: Buffer %ld does not exist"));
EXTERN char_u e_emptybuf [] INIT (= N_ ("E749: empty buffer"));
EXTERN char_u e_notmp [] INIT (= N_ ("E483: Can't get temp file name"));
EXTERN char_u *IObuff;
EXTERN buf_T *lastbuf INIT (= NULL);
EXTERN buf_T *firstbuf INIT (= NULL);
EXTERN buf_T *au_pending_free_buf INIT (= NULL);
EXTERN long  p_ttm;
EXTERN long  p_tm;
EXTERN int p_stmp;
EXTERN int p_lrm;
EXTERN int p_bevalterm;
EXTERN char_u e_positive [] INIT (= N_ ("E487: Argument must be positive"));
EXTERN hlf_T edit_submode_highl;
EXTERN int highlight_attr [HLF_COUNT];
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
EXTERN time_T starttime;
char_u *compl_pattern = NULL;
int compl_restarting = FALSE;
const int command_count = 546;
EXTERN char_u e_zerocount [] INIT (= N_ ("E939: Positive count required"));
EXTERN char_u e_nomatch2 [] INIT (= N_ ("E480: No match: %s"));
EXTERN char_u e_nomatch [] INIT (= N_ ("E479: No match"));
EXTERN char_u *autocmd_match INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_out INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_in INIT (= NULL);
EXTERN linenr_T search_match_lines;
pumitem_T *compl_match_array = NULL;
compl_T *compl_old_match = NULL;
compl_T *compl_curr_match = NULL;
compl_T *compl_first_match = NULL;
EXTERN char_u e_maxmempat [] INIT (= N_ ("E363: pattern uses more memory than 'maxmempattern'"));
EXTERN char_u e_winwidth [] INIT (= N_ ("E592: 'winwidth' cannot be smaller than 'winminwidth'"));
EXTERN char_u e_winheight [] INIT (= N_ ("E591: 'winheight' cannot be smaller than 'winminheight'"));
EXTERN char_u e_notopen [] INIT (= N_ ("E484: Can't open file %s"));
EXTERN frame_T *topframe;
int compl_match_arraysize;
EXTERN int searchcmdlen;
EXTERN long  p_titlelen;
pos_T compl_startpos;
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
EXTERN int autocmd_fname_full;
EXTERN char_u *autocmd_fname INIT (= NULL);
EXTERN char_u *sourcing_name INIT (= NULL);
EXTERN char_u *p_titlestring;
EXTERN char_u *p_iconstring;
EXTERN unsigned  swb_flags;
EXTERN tabpage_T *curtab;
EXTERN int p_confirm;
EXTERN int sc_col;
EXTERN int ru_col;
EXTERN colnr_T search_match_endcol;
EXTERN int p_cc_cols [256];
EXTERN long  p_columnspace;
EXTERN int fuoptions_bgcolor;
EXTERN tabpage_T *first_tabpage;
EXTERN char_u *p_ww;
EXTERN int mouse_col;
EXTERN int mouse_row;
EXTERN int p_sta;
EXTERN int p_altkeymap;
EXTERN char_u e_noinstext [] INIT (= N_ ("E29: No inserted text yet"));
EXTERN char_u *p_sbr;
int did_add_space = FALSE;
EXTERN pos_T saved_cursor;
EXTERN cmdmod_T cmdmod;
long  replace_stack_len = 0;
char_u *replace_stack = NULL;
long  replace_stack_nr = 0;
EXTERN char_u *p_cpo;
int pc_attr;
char_u pc_bytes [MB_MAXBYTES + 1];
int pc_status;
int pc_col;
int pc_row;
EXTERN schar_T *ScreenLines INIT (= NULL);
EXTERN pos_T last_cursormoved;
EXTERN pos_T VIsual;
EXTERN int p_paste;
EXTERN int p_ari;
EXTERN unsigned  ve_flags;
int compl_enter_selects = FALSE;
int compl_used_match;
EXTERN long  p_so;
int ctrl_x_mode = CTRL_X_NORMAL;
int compl_get_longest = FALSE;
colnr_T compl_col = 0;
compl_T *compl_shown_match = NULL;
EXTERN int KeyTyped;
EXTERN int p_hkmap;
int dont_sync_undo = FALSE;
EXTERN unsigned  fdo_flags;
EXTERN char_u farsi_text_3 [];
EXTERN int p_fkmap;
EXTERN char_u e_secure [] INIT (= N_ ("E523: Not allowed here"));
int old_indent = 0;
EXTERN int p_smd;
EXTERN int p_im;
int can_cindent;
EXTERN int p_ek;
int revins_scol;
int revins_legal;
int revins_chars;
EXTERN int p_ri;
int revins_on;
EXTERN int stop_insert_mode;
colnr_T Insstart_blank_vcol;
EXTERN pos_T where_paste_started;
int compl_busy = FALSE;
int compl_started = FALSE;
int did_restart_edit;
EXTERN buf_T *curbuf INIT (= NULL);
int new_insert_skip;
colnr_T Insstart_textlen;
EXTERN pos_T Insstart_orig;
int update_Insstart_orig = TRUE;
EXTERN pos_T Insstart;
EXTERN int arrow_used;
int ins_need_undo;
EXTERN win_T *curwin;
EXTERN int p_sol;
EXTERN long  p_aleph;
EXTERN int p_hkmapp;
int last_insert_skip;
char_u *last_insert = NULL;
int compl_matches = 0;
EXTERN char need_key_msg [] INIT (= N_ ("Need encryption key for \"%s\""));
EXTERN char bot_top_msg [] INIT (= N_ ("search hit BOTTOM, continuing at TOP"));
EXTERN char top_bot_msg [] INIT (= N_ ("search hit TOP, continuing at BOTTOM"));
EXTERN char_u e_invexprmsg [] INIT (= N_ ("E449: Invalid expression received"));
EXTERN char_u no_lines_msg [] INIT (= N_ ("--No lines in buffer--"));
EXTERN char_u msg_buf [MSG_BUF_LEN];
EXTERN struct msglist **msg_list INIT (= NULL);
EXTERN int called_emsg;
EXTERN int did_emsg_syntax;
EXTERN int did_emsg;
EXTERN char_u *keep_msg INIT (= NULL);
EXTERN int msg_scrolled;
EXTERN int msg_row;
EXTERN int msg_col;
char *ctrl_x_msgs [] = {N_ (" Keyword completion (^N^P)"), N_ (" ^X mode (^]^D^E^F^I^K^L^N^O^Ps^U^V^Y)"), NULL, N_ (" Whole line completion (^L^N^P)"), N_ (" File name completion (^F^N^P)"), N_ (" Tag completion (^]^N^P)"), N_ (" Path pattern completion (^N^P)"), N_ (" Definition completion (^D^N^P)"), NULL, N_ (" Dictionary completion (^K^N^P)"), N_ (" Thesaurus completion (^T^N^P)"), N_ (" Command-line completion (^V^N^P)"), N_ (" User defined completion (^U^N^P)"), N_ (" Omni completion (^O^N^P)"), N_ (" Spelling suggestion (s^N^P)"), N_ (" Keyword Local completion (^N^P)"), NULL,};
EXTERN typebuf_T typebuf;
EXTERN long_u scrollbar_value;
EXTERN except_T *caught_stack INIT (= NULL);
EXTERN int did_uncaught_emsg;
EXTERN char_u *p_def;
EXTERN char_u *p_inc;
EXTERN long  p_fdls;
EXTERN int p_exrc;
EXTERN char_u *p_efm;
EXTERN char_u e_patnotf [] INIT (= N_ ("Pattern not found"));

char_u *add_char2buf (int c, char_u *s) {
    if (c == K_SPECIAL) {
        *s++ = K_SPECIAL;
        *s++ = KS_SPECIAL;
        *s++ = KE_FILLER;
    }
    else if (c == CSI) {
        *s++ = CSI;
        *s++ = KS_EXTRA;
        *s++ = (int) KE_CSI;
    }
    else
        *s++ = c;
    return s;
}

char_u *get_last_insert_save (void) {
    char_u *s;
    int len;
    if (last_insert == NULL)
        return NULL;
    s = vim_strsave (last_insert +last_insert_skip);
    if (s != NULL) {
        len = (int) STRLEN (s);
        if (len > 0 && s[len - 1] == ESC)
            s[len - 1] = NUL;
    }
    return s;
}

int hkmap (int c) {
    if (p_hkmapp) {
        enum {hALEF = 0, BET, GIMEL, DALET, HEI, VAV, ZAIN, HET, TET, IUD, KAFsofit, hKAF, LAMED, MEMsofit, MEM, NUNsofit, NUN, SAMEH, AIN, PEIsofit, PEI, ZADIsofit, ZADI, KOF, RESH, hSHIN, TAV};
        static char_u map [26] = {(char_u) hALEF, (char_u) BET, (char_u) hKAF, (char_u) DALET, (char_u) -1, (char_u) PEIsofit, (char_u) GIMEL, (char_u) HEI, (char_u) IUD, (char_u) HET, (char_u) KOF, (char_u) LAMED, (char_u) MEM, (char_u) NUN, (char_u) SAMEH, (char_u) PEI, (char_u) -1, (char_u) RESH, (char_u) ZAIN, (char_u) TAV, (char_u) TET, (char_u) VAV, (char_u) hSHIN, (char_u) -1, (char_u) AIN, (char_u) ZADI};
        if (c == 'N' || c == 'M' || c == 'P' || c == 'C' || c == 'Z')
            return (int) (map[CharOrd (c)] - 1 + p_aleph);
        else if (c == 'x')
            return 'X';
        else if (c == 'q')
            return '\'';
        else if (c == 246)
            return ' ';
        else if (c == 228)
            return ' ';
        else if (c == 252)
            return ' ';
        else if (c >= 'a' && c <= 'z')
            return (int) (map[CharOrdLow (c)] + p_aleph);
        else
            return c;
    }
    else {
        switch (c) {
        case '`' :
            return ';';
        case '/' :
            return '.';
        case '\'' :
            return ',';
        case 'q' :
            return '/';
        case 'w' :
            return '\'';
        case ',' :
            c = '{';
            break;
        case '.' :
            c = 'v';
            break;
        case ';' :
            c = 't';
            break;
        default :
            {
                static char str [] = "zqbcxlsjphmkwonu ydafe rig";
                if (c < 'a' || c > 'z')
                    return c;
                c = str[CharOrdLow (c)];
                break;
            }
        }
        return (int) (CharOrdLow (c) + p_aleph);
    }
}

void beginline (int flags) {
    if ((flags & BL_SOL) && !p_sol)
        coladvance (curwin->w_curswant);
    else {
        curwin->w_cursor.col = 0;
        curwin->w_cursor.coladd = 0;
        if (flags & (BL_WHITE | BL_SOL)) {
            char_u *ptr;
            for (ptr = ml_get_curline (); VIM_ISWHITE (*ptr) && !((flags & BL_FIX) && ptr[1] == NUL); ++ptr)
                ++curwin->w_cursor.col;
        }
        curwin->w_set_curswant = TRUE;
    }
}

int stop_arrow (void) {
    if (arrow_used) {
        Insstart = curwin->w_cursor;
        if (Insstart.col > Insstart_orig.col && !ins_need_undo)
            update_Insstart_orig = FALSE;
        Insstart_textlen = (colnr_T) linetabsize (ml_get_curline ());
        if (u_save_cursor () == OK) {
            arrow_used = FALSE;
            ins_need_undo = FALSE;
        }
        ai_col = 0;
        if (State & VREPLACE_FLAG) {
            orig_line_count = curbuf->b_ml.ml_line_count;
            vr_lines_changed = 1;
        }
        ResetRedobuff ();
        AppendToRedobuff ((char_u *) "1i");
        new_insert_skip = 2;
    }
    else if (ins_need_undo) {
        if (u_save_cursor () == OK)
            ins_need_undo = FALSE;
    }
    foldOpenCursor ();
    return (arrow_used || ins_need_undo ? FAIL : OK);
}

int edit (int cmdchar, int startln, long  count) {
    int c = 0;
    char_u *ptr;
    int lastc = 0;
    int mincol;
    static linenr_T o_lnum = 0;
    int i;
    int did_backspace = TRUE;
    int line_is_white = FALSE;
    linenr_T old_topline = 0;
    int old_topfill = -1;
    int inserted_space = FALSE;
    int replaceState = REPLACE;
    int nomove = FALSE;
    did_restart_edit = restart_edit;
    check_for_delay (TRUE);
    update_Insstart_orig = TRUE;
    if (textlock != 0) {
        EMSG (_ (e_secure));
        return FALSE;
    }
    if (compl_started || compl_busy || pum_visible ()) {
        EMSG (_ (e_secure));
        return FALSE;
    }
    ins_compl_clear ();
    if (cmdchar != 'r' && cmdchar != 'v') {
        pos_T save_cursor = curwin->w_cursor;
        if (cmdchar == 'R')
            ptr = (char_u *) "r";
        else if (cmdchar == 'V')
            ptr = (char_u *) "v";
        else
            ptr = (char_u *) "i";
        set_vim_var_string (VV_INSERTMODE, ptr, 1);
        set_vim_var_string (VV_CHAR, NULL, - 1);
        apply_autocmds (EVENT_INSERTENTER, NULL, NULL, FALSE, curbuf);
        if (!EQUAL_POS (curwin->w_cursor, save_cursor) && *get_vim_var_str (VV_CHAR) == NUL && save_cursor.lnum <= curbuf->b_ml.ml_line_count) {
            int save_state = State;
            curwin->w_cursor = save_cursor;
            State = INSERT;
            check_cursor_col ();
            State = save_state;
        }
    }
    conceal_check_cursur_line ();
    if (where_paste_started.lnum != 0)
        Insstart = where_paste_started;
    else {
        Insstart = curwin->w_cursor;
        if (startln)
            Insstart.col = 0;
    }
    Insstart_textlen = (colnr_T) linetabsize (ml_get_curline ());
    Insstart_blank_vcol = MAXCOL;
    if (!did_ai)
        ai_col = 0;
    if (cmdchar != NUL && restart_edit == 0) {
        ResetRedobuff ();
        AppendNumberToRedobuff (count);
        if (cmdchar == 'V' || cmdchar == 'v') {
            AppendCharToRedobuff ('g');
            AppendCharToRedobuff ((cmdchar == 'v') ? 'r' : 'R');
        }
        else {
            if (cmdchar == K_PS)
                AppendCharToRedobuff ('a');
            else
                AppendCharToRedobuff (cmdchar);
            if (cmdchar == 'g')
                AppendCharToRedobuff ('I');
            else if (cmdchar == 'r')
                count = 1;
        }
    }
    if (cmdchar == 'R') {
        if (p_fkmap && p_ri) {
            beep_flush ();
            EMSG (farsi_text_3);
            State = INSERT;
        }
        else
            State = REPLACE;
    }
    else if (cmdchar == 'V' || cmdchar == 'v') {
        State = VREPLACE;
        replaceState = VREPLACE;
        orig_line_count = curbuf->b_ml.ml_line_count;
        vr_lines_changed = 1;
    }
    else
        State = INSERT;
    stop_insert_mode = FALSE;
    curs_columns (TRUE);
    if (curbuf->b_p_iminsert == B_IMODE_LMAP)
        State |= LANGMAP;
    setmouse ();
    clear_showcmd ();
    revins_on = (State == INSERT && p_ri);
    if (revins_on)
        undisplay_dollar ();
    revins_chars = 0;
    revins_legal = 0;
    revins_scol = -1;
    if (!p_ek)
        out_str (T_BD);
    if (restart_edit != 0 && stuff_empty ()) {
        if (where_paste_started.lnum)
            arrow_used = FALSE;
        else
            arrow_used = TRUE;
        restart_edit = 0;
        validate_virtcol ();
        update_curswant ();
        if (((ins_at_eol && curwin->w_cursor.lnum == o_lnum) || curwin->w_curswant > curwin->w_virtcol) && *(ptr = ml_get_curline () + curwin->w_cursor.col) != NUL) {
            if (ptr[1] == NUL)
                ++curwin->w_cursor.col;
        }
        ins_at_eol = FALSE;
    }
    else
        arrow_used = FALSE;
    need_start_insertmode = FALSE;
    ins_need_undo = TRUE;
    where_paste_started.lnum = 0;
    can_cindent = TRUE;
    if (!p_im && did_restart_edit == 0)
        foldOpenCursor ();
    i = 0;
    if (p_smd && msg_silent == 0)
        i = showmode ();
    if (!p_im && did_restart_edit == 0)
        change_warning (i == 0 ? 0 : i + 1);
    do_digraph (- 1);
    ptr = get_inserted ();
    if (ptr == NULL)
        new_insert_skip = 0;
    else {
        new_insert_skip = (int) STRLEN (ptr);
        vim_free (ptr);
    }
    old_indent = 0;
    for (;;) {
        if (!revins_legal)
            revins_scol = -1;
        else
            revins_legal = 0;
        if (arrow_used)
            count = 0;
        if (update_Insstart_orig)
            Insstart_orig = Insstart;
        if (stop_insert_mode && !pum_visible ()) {
            count = 0;
            goto doESCkey;
        }
        if (!arrow_used)
            curwin->w_set_curswant = TRUE;
        if (stuff_empty ()) {
            did_check_timestamps = FALSE;
            if (need_check_timestamps)
                check_timestamps (FALSE);
        }
        msg_scroll = FALSE;
        if (need_mouse_correct)
            gui_mouse_correct ();
        if (fdo_flags & FDO_INSERT)
            foldOpenCursor ();
        if (!char_avail ())
            foldCheckClose ();
        if (curbuf->b_mod_set && curwin->w_p_wrap && !did_backspace && curwin->w_topline == old_topline && curwin->w_topfill == old_topfill) {
            mincol = curwin->w_wcol;
            validate_cursor_col ();
            if ((int) curwin->w_wcol < mincol - curbuf->b_p_ts && curwin->w_wrow == W_WINROW (curwin) + curwin->w_height - 1 - p_so && (curwin->w_cursor.lnum != curwin->w_topline || curwin->w_topfill > 0)) {
                if (curwin->w_topfill > 0)
                    --curwin->w_topfill;
                else if (hasFolding (curwin->w_topline, NULL, &old_topline))
                    set_topline (curwin, old_topline +1);
                else
                    set_topline (curwin, curwin->w_topline + 1);
            }
        }
        update_topline ();
        did_backspace = FALSE;
        validate_cursor ();
        ins_redraw (TRUE);
        if (curwin->w_p_scb)
            do_check_scrollbind (TRUE);
        if (curwin->w_p_crb)
            do_check_cursorbind ();
        update_curswant ();
        old_topline = curwin->w_topline;
        old_topfill = curwin->w_topfill;
        if (c != K_CURSORHOLD)
            lastc = c;
        if (dont_sync_undo == MAYBE)
            dont_sync_undo = TRUE;
        else
            dont_sync_undo = FALSE;
        if (cmdchar == K_PS)
            c = K_PS;
        else
            do {
                c = safe_vgetc ();
            }
            while (c == K_IGNORE || c == K_NOP);
        did_cursorhold = TRUE;
        if (p_hkmap && KeyTyped)
            c = hkmap (c);
        if (p_fkmap && KeyTyped)
            c = fkmap (c);
        if (compl_started && pum_wanted () && curwin->w_cursor.col >= compl_col && (compl_shown_match == NULL || compl_shown_match != compl_shown_match->cp_next)) {
            if ((c == K_BS || c == Ctrl_H) && curwin->w_cursor.col > compl_col && (c = ins_compl_bs ()) == NUL)
                continue;
            if (!compl_used_match) {
                if (c == Ctrl_L && (!CTRL_X_MODE_LINE_OR_EVAL (ctrl_x_mode) || (int) STRLEN (compl_shown_match->cp_str) > curwin->w_cursor.col - compl_col)) {
                    ins_compl_addfrommatch ();
                    continue;
                }
                if (ins_compl_accept_char (c)) {
                    char_u *str = do_insert_char_pre (c);
                    char_u *p;
                    if (str != NULL) {
                        for (p = str; *p != NUL; MB_PTR_ADV (p))
                            ins_compl_addleader (PTR2CHAR (p));
                        vim_free (str);
                    }
                    else
                        ins_compl_addleader (c);
                    continue;
                }
                if ((c == Ctrl_Y || (compl_enter_selects && (c == CAR || c == K_KENTER || c == NL))) && stop_arrow () == OK) {
                    ins_compl_delete ();
                    ins_compl_insert (FALSE);
                }
            }
        }
        compl_get_longest = FALSE;
        if (ins_compl_prep (c))
            continue;
        if (c == Ctrl_BSL) {
            ins_redraw (FALSE);
            ++no_mapping;
            ++allow_keys;
            c = plain_vgetc ();
            --no_mapping;
            --allow_keys;
            if (c != Ctrl_N && c != Ctrl_G && c != Ctrl_O) {
                vungetc (c);
                c = Ctrl_BSL;
            }
            else if (c == Ctrl_G && p_im)
                continue;
            else {
                if (c == Ctrl_O) {
                    ins_ctrl_o ();
                    ins_at_eol = FALSE;
                    nomove = TRUE;
                }
                count = 0;
                goto doESCkey;
            }
        }
        c = do_digraph (c);
        if ((c == Ctrl_V || c == Ctrl_Q) && ctrl_x_mode == CTRL_X_CMDLINE)
            goto docomplete;
        if (c == Ctrl_V || c == Ctrl_Q) {
            ins_ctrl_v ();
            c = Ctrl_V;
            continue;
        }
        if (cindent_on () && ctrl_x_mode == 0) {
            line_is_white = inindent (0);
            if (in_cinkeys (c, '!', line_is_white))
                goto force_cindent;
            if (can_cindent && in_cinkeys (c, '*', line_is_white) && stop_arrow () == OK)
                do_c_expr_indent ();
        }
        if (curwin->w_p_rl)
            switch (c) {
            case K_LEFT :
                c = K_RIGHT;
                break;
            case K_S_LEFT :
                c = K_S_RIGHT;
                break;
            case K_C_LEFT :
                c = K_C_RIGHT;
                break;
            case K_RIGHT :
                c = K_LEFT;
                break;
            case K_S_RIGHT :
                c = K_S_LEFT;
                break;
            case K_C_RIGHT :
                c = K_C_LEFT;
                break;
            }
        if (ins_start_select (c))
            continue;
        switch (c) {
        case ESC :
            if (echeck_abbr (ESC +ABBR_OFF))
                break;
        case Ctrl_C :
        do_intr :
            if (goto_im ()) {
                if (got_int) {
                    (void) vgetc ();
                    got_int = FALSE;
                }
                else
                    vim_beep (BO_IM);
                break;
            }
        doESCkey :
            if (ins_at_eol && gchar_cursor () == NUL)
                o_lnum = curwin->w_cursor.lnum;
            if (ins_esc (&count, cmdchar, nomove)) {
                if (cmdchar != 'r' && cmdchar != 'v')
                    apply_autocmds (EVENT_INSERTLEAVE, NULL, NULL, FALSE, curbuf);
                did_cursorhold = FALSE;
                return (c == Ctrl_O);
            }
            continue;
        case Ctrl_Z :
            if (!p_im)
                goto normalchar;
            do_cmdline_cmd ((char_u *) "stop");
            continue;
        case Ctrl_O :
            if (echeck_abbr (Ctrl_O +ABBR_OFF))
                break;
            ins_ctrl_o ();
            if (ve_flags & VE_ONEMORE) {
                ins_at_eol = FALSE;
                nomove = TRUE;
            }
            count = 0;
            goto doESCkey;
        case K_INS :
        case K_KINS :
            ins_insert (replaceState);
            break;
        case K_SELECT :
            break;
        case K_HELP :
        case K_F1 :
        case K_XF1 :
            stuffcharReadbuff (K_HELP);
            if (p_im)
                need_start_insertmode = TRUE;
            goto doESCkey;
        case K_F21 :
            ++no_mapping;
            i = plain_vgetc ();
            --no_mapping;
            netbeans_keycommand (i);
            break;
        case K_ZERO :
        case NUL :
        case Ctrl_A :
            if (stuff_inserted (NUL, 1L, (c == Ctrl_A)) == FAIL && c != Ctrl_A && !p_im)
                goto doESCkey;
            inserted_space = FALSE;
            break;
        case Ctrl_R :
            ins_reg ();
            auto_format (FALSE, TRUE);
            inserted_space = FALSE;
            break;
        case Ctrl_G :
            ins_ctrl_g ();
            break;
        case Ctrl_HAT :
            ins_ctrl_hat ();
            break;
        case Ctrl__ :
            if (!p_ari)
                goto normalchar;
            ins_ctrl_ ();
            break;
        case Ctrl_D :
            if (ctrl_x_mode == CTRL_X_PATH_DEFINES)
                goto docomplete;
        case Ctrl_T :
            if (c == Ctrl_T && ctrl_x_mode == CTRL_X_THESAURUS) {
                if (has_compl_option (FALSE))
                    goto docomplete;
                break;
            }
            ins_shift (c, lastc);
            auto_format (FALSE, TRUE);
            inserted_space = FALSE;
            break;
        case K_DEL :
        case K_KDEL :
            ins_del ();
            auto_format (FALSE, TRUE);
            break;
        case K_BS :
        case Ctrl_H :
            did_backspace = ins_bs (c, BACKSPACE_CHAR, &inserted_space);
            auto_format (FALSE, TRUE);
            break;
        case Ctrl_W :
            did_backspace = ins_bs (c, BACKSPACE_WORD, &inserted_space);
            auto_format (FALSE, TRUE);
            break;
        case Ctrl_U :
            did_backspace = ins_bs (c, BACKSPACE_LINE, &inserted_space);
            auto_format (FALSE, TRUE);
            inserted_space = FALSE;
            break;
        case K_LEFTMOUSE :
        case K_LEFTMOUSE_NM :
        case K_LEFTDRAG :
        case K_LEFTRELEASE :
        case K_LEFTRELEASE_NM :
        case K_MOUSEMOVE :
        case K_MIDDLEMOUSE :
        case K_MIDDLEDRAG :
        case K_MIDDLERELEASE :
        case K_RIGHTMOUSE :
        case K_RIGHTDRAG :
        case K_RIGHTRELEASE :
        case K_X1MOUSE :
        case K_X1DRAG :
        case K_X1RELEASE :
        case K_X2MOUSE :
        case K_X2DRAG :
        case K_X2RELEASE :
            ins_mouse (c);
            break;
        case K_MOUSEDOWN :
            ins_mousescroll (MSCR_DOWN);
            break;
        case K_MOUSEUP :
            ins_mousescroll (MSCR_UP);
            break;
        case K_MOUSELEFT :
            ins_mousescroll (MSCR_LEFT);
            break;
        case K_MOUSERIGHT :
            ins_mousescroll (MSCR_RIGHT);
            break;
        case K_SWIPELEFT :
        case K_SWIPERIGHT :
        case K_SWIPEUP :
        case K_SWIPEDOWN :
            break;
        case K_PS :
            bracketed_paste (PASTE_INSERT, FALSE, NULL);
            if (cmdchar == K_PS)
                goto doESCkey;
            break;
        case K_PE :
            break;
        case K_IGNORE :
            break;
        case K_CURSORHOLD :
            apply_autocmds (EVENT_CURSORHOLDI, NULL, NULL, FALSE, curbuf);
            did_cursorhold = TRUE;
            break;
        case K_VER_SCROLLBAR :
            ins_scroll ();
            break;
        case K_HOR_SCROLLBAR :
            ins_horscroll ();
            break;
        case K_HOME :
        case K_KHOME :
        case K_S_HOME :
        case K_C_HOME :
            ins_home (c);
            break;
        case K_END :
        case K_KEND :
        case K_S_END :
        case K_C_END :
            ins_end (c);
            break;
        case K_LEFT :
            if (mod_mask & (MOD_MASK_SHIFT | MOD_MASK_CTRL))
                ins_s_left ();
            else
                ins_left (dont_sync_undo == FALSE);
            break;
        case K_S_LEFT :
        case K_C_LEFT :
            ins_s_left ();
            break;
        case K_RIGHT :
            if (mod_mask & (MOD_MASK_SHIFT | MOD_MASK_CTRL))
                ins_s_right ();
            else
                ins_right (dont_sync_undo == FALSE);
            break;
        case K_S_RIGHT :
        case K_C_RIGHT :
            ins_s_right ();
            break;
        case K_UP :
            if (pum_visible ())
                goto docomplete;
            if (mod_mask & MOD_MASK_SHIFT)
                ins_pageup ();
            else
                ins_up (FALSE);
            break;
        case K_S_UP :
        case K_PAGEUP :
        case K_KPAGEUP :
            if (pum_visible ())
                goto docomplete;
            ins_pageup ();
            break;
        case K_DOWN :
            if (pum_visible ())
                goto docomplete;
            if (mod_mask & MOD_MASK_SHIFT)
                ins_pagedown ();
            else
                ins_down (FALSE);
            break;
        case K_S_DOWN :
        case K_PAGEDOWN :
        case K_KPAGEDOWN :
            if (pum_visible ())
                goto docomplete;
            ins_pagedown ();
            break;
        case K_S_TAB :
            c = TAB;
        case TAB :
            if (ctrl_x_mode == CTRL_X_PATH_PATTERNS)
                goto docomplete;
            inserted_space = FALSE;
            if (ins_tab ())
                goto normalchar;
            auto_format (FALSE, TRUE);
            break;
        case K_KENTER :
            c = CAR;
        case CAR :
        case NL :
            if (bt_quickfix (curbuf) && c == CAR) {
                if (curwin->w_llist_ref == NULL)
                    do_cmdline_cmd ((char_u *) ".cc");
                else
                    do_cmdline_cmd ((char_u *) ".ll");
                break;
            }
            if (ins_eol (c) && !p_im)
                goto doESCkey;
            auto_format (FALSE, FALSE);
            inserted_space = FALSE;
            break;
        case Ctrl_K :
            if (ctrl_x_mode == CTRL_X_DICTIONARY) {
                if (has_compl_option (TRUE))
                    goto docomplete;
                break;
            }
            c = ins_digraph ();
            if (c == NUL)
                break;
            goto normalchar;
        case Ctrl_X :
            ins_ctrl_x ();
            break;
        case Ctrl_RSB :
            if (ctrl_x_mode != CTRL_X_TAGS)
                goto normalchar;
            goto docomplete;
        case Ctrl_F :
            if (ctrl_x_mode != CTRL_X_FILES)
                goto normalchar;
            goto docomplete;
        case 's' :
        case Ctrl_S :
            if (ctrl_x_mode != CTRL_X_SPELL)
                goto normalchar;
            goto docomplete;
        case Ctrl_L :
            if (ctrl_x_mode != CTRL_X_WHOLE_LINE) {
                if (p_im) {
                    if (echeck_abbr (Ctrl_L +ABBR_OFF))
                        break;
                    goto doESCkey;
                }
                goto normalchar;
            }
        case Ctrl_P :
        case Ctrl_N :
            if (*curbuf->b_p_cpt == NUL && (ctrl_x_mode == CTRL_X_NORMAL || ctrl_x_mode == CTRL_X_WHOLE_LINE) && !(compl_cont_status & CONT_LOCAL))
                goto normalchar;
        docomplete :
            compl_busy = TRUE;
            disable_fold_update++;
            if (ins_complete (c, TRUE) == FAIL)
                compl_cont_status = 0;
            disable_fold_update--;
            compl_busy = FALSE;
            break;
        case Ctrl_Y :
        case Ctrl_E :
            c = ins_ctrl_ey (c);
            break;
        default :
            if (c == intr_char)
                goto do_intr;
        normalchar :
            if (!p_paste) {
                char_u *str = do_insert_char_pre (c);
                char_u *p;
                if (str != NULL) {
                    if (*str != NUL && stop_arrow () != FAIL) {
                        for (p = str; *p != NUL; MB_PTR_ADV (p)) {
                            c = PTR2CHAR (p);
                            if (c == CAR || c == K_KENTER || c == NL)
                                ins_eol (c);
                            else
                                ins_char (c);
                        }
                        AppendToRedobuffLit (str, - 1);
                    }
                    vim_free (str);
                    c = NUL;
                }
                if (c == NUL)
                    break;
            }
            ins_try_si (c);
            if (c == ' ') {
                inserted_space = TRUE;
                if (inindent (0))
                    can_cindent = FALSE;
                if (Insstart_blank_vcol == MAXCOL && curwin->w_cursor.lnum == Insstart.lnum)
                    Insstart_blank_vcol = get_nolist_virtcol ();
            }
            if (vim_iswordc (c) || (!echeck_abbr (c) && c != Ctrl_RSB)) {
                insert_special (c, FALSE, FALSE);
                revins_legal++;
                revins_chars++;
            }
            auto_format (FALSE, TRUE);
            foldOpenCursor ();
            break;
        }
        if (c != K_CURSORHOLD)
            did_cursorhold = FALSE;
        if (arrow_used)
            inserted_space = FALSE;
        if (can_cindent && cindent_on () && ctrl_x_mode == CTRL_X_NORMAL) {
        force_cindent :
            if (in_cinkeys (c, ' ', line_is_white)) {
                if (stop_arrow () == OK)
                    do_c_expr_indent ();
            }
        }
    }
}

static void undisplay_dollar (void) {
    if (dollar_vcol >= 0) {
        dollar_vcol = -1;
        redrawWinline (curwin -> w_cursor.lnum, FALSE);
    }
}

static void ins_redraw (int ready) {
    linenr_T conceal_old_cursor_line = 0;
    linenr_T conceal_new_cursor_line = 0;
    int conceal_update_lines = FALSE;
    if (char_avail ())
        return;
    if (ready && (has_cursormovedI () || curwin->w_p_cole > 0) && !EQUAL_POS (last_cursormoved, curwin->w_cursor) && !pum_visible ()) {
        if (syntax_present (curwin) && must_redraw)
            update_screen (0);
        if (has_cursormovedI ()) {
            update_curswant ();
            apply_autocmds (EVENT_CURSORMOVEDI, NULL, NULL, FALSE, curbuf);
        }
        if (curwin->w_p_cole > 0) {
            conceal_old_cursor_line = last_cursormoved.lnum;
            conceal_new_cursor_line = curwin->w_cursor.lnum;
            conceal_update_lines = TRUE;
        }
        last_cursormoved = curwin->w_cursor;
    }
    if (ready && has_textchangedI () && curbuf->b_last_changedtick != CHANGEDTICK (curbuf) && !pum_visible ()) {
        apply_autocmds (EVENT_TEXTCHANGEDI, NULL, NULL, FALSE, curbuf);
        curbuf->b_last_changedtick = CHANGEDTICK (curbuf);
    }
    if (ready && has_textchangedP () && curbuf->b_last_changedtick_pum != CHANGEDTICK (curbuf) && pum_visible ()) {
        apply_autocmds (EVENT_TEXTCHANGEDP, NULL, NULL, FALSE, curbuf);
        curbuf->b_last_changedtick_pum = CHANGEDTICK (curbuf);
    }
    if (must_redraw)
        update_screen (0);
    else if (clear_cmdline || redraw_cmdline)
        showmode ();
    if ((conceal_update_lines && (conceal_old_cursor_line != conceal_new_cursor_line || conceal_cursor_line (curwin))) || need_cursor_line_redraw) {
        if (conceal_old_cursor_line != conceal_new_cursor_line)
            update_single_line (curwin, conceal_old_cursor_line);
        update_single_line (curwin, conceal_new_cursor_line == 0 ? curwin -> w_cursor.lnum : conceal_new_cursor_line);
        curwin->w_valid &= ~VALID_CROW;
    }
    showruler (FALSE);
    setcursor ();
    emsg_on_display = FALSE;
}

static void ins_ctrl_o (void) {
    if (State & VREPLACE_FLAG)
        restart_edit = 'V';
    else if (State & REPLACE_FLAG)
        restart_edit = 'R';
    else
        restart_edit = 'I';
    if (virtual_active ())
        ins_at_eol = FALSE;
    else
        ins_at_eol = (gchar_cursor () == NUL);
}

static void ins_ctrl_v (void) {
    int c;
    int did_putchar = FALSE;
    ins_redraw (FALSE);
    if (redrawing () && !char_avail ()) {
        edit_putchar ('^', TRUE);
        did_putchar = TRUE;
    }
    AppendToRedobuff ((char_u *) CTRL_V_STR);
    add_to_showcmd_c (Ctrl_V);
    c = get_literal ();
    if (did_putchar)
        edit_unputchar ();
    clear_showcmd ();
    insert_special (c, FALSE, TRUE);
    revins_chars++;
    revins_legal++;
}

void edit_putchar (int c, int highlight) {
    int attr;
    if (ScreenLines != NULL) {
        update_topline ();
        validate_cursor ();
        if (highlight)
            attr = HL_ATTR (HLF_8);
        else
            attr = 0;
        pc_row = W_WINROW (curwin) + curwin->w_wrow;
        pc_col = curwin->w_wincol;
        pc_status = PC_STATUS_UNSET;
        if (curwin->w_p_rl) {
            pc_col += curwin->w_width - 1 - curwin->w_wcol;
        }
        else {
            pc_col += curwin->w_wcol;
        }
        if (pc_status == PC_STATUS_UNSET) {
            screen_getbytes (pc_row, pc_col, pc_bytes, & pc_attr);
            pc_status = PC_STATUS_SET;
        }
        screen_putchar (c, pc_row, pc_col, attr);
    }
}

int get_literal (void) {
    int cc;
    int nc;
    int i;
    int hex = FALSE;
    int octal = FALSE;
    if (got_int)
        return Ctrl_C;
    if (gui.in_use)
        ++allow_keys;
    ++no_mapping;
    cc = 0;
    i = 0;
    for (;;) {
        nc = plain_vgetc ();
        if (!(State & CMDLINE))
            add_to_showcmd (nc);
        if (nc == 'x' || nc == 'X')
            hex = TRUE;
        else if (nc == 'o' || nc == 'O')
            octal = TRUE;
        else {
            if (hex) {
                if (!vim_isxdigit (nc))
                    break;
                cc = cc * 16 + hex2nr (nc);
            }
            else if (octal) {
                if (nc < '0' || nc > '7')
                    break;
                cc = cc * 8 + nc - '0';
            }
            else {
                if (!VIM_ISDIGIT (nc))
                    break;
                cc = cc * 10 + nc - '0';
            }
            ++i;
        }
        if (cc > 255)
            cc = 255;
        nc = 0;
        if (hex) {
            if (i >= 2)
                break;
        }
        else if (i >= 3)
            break;
    }
    if (i == 0) {
        if (nc == K_ZERO) {
            cc = '\n';
            nc = 0;
        }
        else {
            cc = nc;
            nc = 0;
        }
    }
    if (cc == 0)
        cc = '\n';
    --no_mapping;
    if (gui.in_use)
        --allow_keys;
    if (nc)
        vungetc (nc);
    got_int = FALSE;
    return cc;
}

void edit_unputchar (void) {
    if (pc_status != PC_STATUS_UNSET && pc_row >= msg_scrolled) {
        screen_puts (pc_bytes, pc_row - msg_scrolled, pc_col, pc_attr);
    }
}

static void insert_special (int c, int allow_modmask, int ctrlv) {
    char_u *p;
    int len;
    if (mod_mask & MOD_MASK_CMD)
        allow_modmask = TRUE;
    if (IS_SPECIAL (c) || (mod_mask && allow_modmask)) {
        p = get_special_key_name (c, mod_mask);
        len = (int) STRLEN (p);
        c = p[len - 1];
        if (len > 2) {
            if (stop_arrow () == FAIL)
                return;
            p[len - 1] = NUL;
            ins_str (p);
            AppendToRedobuffLit (p, - 1);
            ctrlv = FALSE;
        }
    }
    if (stop_arrow () == OK)
        insertchar (c, ctrlv ? INSCHAR_CTRLV : 0, -1);
}

# define ISSPECIAL(c)	((c) < ' ' || (c) >= DEL || (c) == '0' || (c) == '^')

# define WHITECHAR(cc) VIM_ISWHITE(cc)

void insertchar (int c, int flags, int second_indent) {
    int textwidth;
    char_u *p;
    int fo_ins_blank;
    int force_format = flags & INSCHAR_FORMAT;
    textwidth = comp_textwidth (force_format);
    fo_ins_blank = has_format_option (FO_INS_BLANK);
    if (textwidth > 0 && (force_format || (!VIM_ISWHITE (c) && !((State & REPLACE_FLAG) && !(State & VREPLACE_FLAG) && *ml_get_cursor () != NUL) && (curwin->w_cursor.lnum != Insstart.lnum || ((!has_format_option (FO_INS_LONG) || Insstart_textlen <= (colnr_T) textwidth) && (!fo_ins_blank || Insstart_blank_vcol <= (colnr_T) textwidth)))))) {
        int do_internal = TRUE;
        colnr_T virtcol = get_nolist_virtcol () + char2cells (c != NUL ? c : gchar_cursor ());
        if (*curbuf->b_p_fex != NUL && (flags & INSCHAR_NO_FEX) == 0 && (force_format || virtcol > (colnr_T) textwidth)) {
            do_internal = (fex_format (curwin->w_cursor.lnum, 1L, c) != 0);
            ins_need_undo = TRUE;
        }
        if (do_internal)
            internal_format (textwidth, second_indent, flags, c == NUL, c);
    }
    if (c == NUL)
        return;
    if (did_ai && (int) c == end_comment_pending) {
        char_u *line;
        char_u lead_end [COM_MAX_LEN];
        int middle_len, end_len;
        int i;
        i = get_leader_len (line = ml_get_curline (), &p, FALSE, TRUE);
        if (i > 0 && vim_strchr (p, COM_MIDDLE) != NULL) {
            while (*p && p[-1] != ':')
                ++p;
            middle_len = copy_option_part (&p, lead_end, COM_MAX_LEN, ",");
            while (middle_len > 0 && VIM_ISWHITE (lead_end[middle_len - 1]))
                --middle_len;
            while (*p && p[-1] != ':')
                ++p;
            end_len = copy_option_part (&p, lead_end, COM_MAX_LEN, ",");
            i = curwin->w_cursor.col;
            while (--i >= 0 && VIM_ISWHITE (line[i]))
                ;
            i++;
            i -= middle_len;
            if (i >= 0 && lead_end[end_len - 1] == end_comment_pending) {
                backspace_until_column (i);
                ins_bytes_len (lead_end, end_len - 1);
            }
        }
    }
    end_comment_pending = NUL;
    did_ai = FALSE;
    did_si = FALSE;
    can_si = FALSE;
    can_si_back = FALSE;
    if (!ISSPECIAL (c) && vpeekc () != NUL && !(State & REPLACE_FLAG) && !cindent_on () && !p_ri && !has_insertcharpre ()) {

        #define INPUT_BUFLEN 100
        char_u buf [INPUT_BUFLEN + 1];
        int i;
        colnr_T virtcol = 0;
        buf[0] = c;
        i = 1;
        if (textwidth > 0)
            virtcol = get_nolist_virtcol ();
        while ((c = vpeekc ()) != NUL && !ISSPECIAL (c) && i < INPUT_BUFLEN && !(p_fkmap && KeyTyped) && (textwidth == 0 || (virtcol += byte2cells (buf[i - 1])) < (colnr_T) textwidth) && !(!no_abbr && !vim_iswordc (c) && vim_iswordc (buf[i - 1]))) {
            c = vgetc ();
            if (p_hkmap && KeyTyped)
                c = hkmap (c);
            buf[i++] = c;
        }
        do_digraph (- 1);
        do_digraph (buf [i - 1]);
        buf[i] = NUL;
        ins_str (buf);
        if (flags & INSCHAR_CTRLV) {
            redo_literal (*buf);
            i = 1;
        }
        else
            i = 0;
        if (buf[i] != NUL)
            AppendToRedobuffLit (buf +i, -1);
    }
    else {
        {
            ins_char (c);
            if (flags & INSCHAR_CTRLV)
                redo_literal (c);
            else
                AppendCharToRedobuff (c);
        }
    }
}

int comp_textwidth (int ff) {
    int textwidth;
    textwidth = curbuf->b_p_tw;
    if (textwidth == 0 && curbuf->b_p_wm) {
        textwidth = curwin->w_width - curbuf->b_p_wm;
        textwidth -= curwin->w_p_fdc;
        if (signcolumn_on (curwin))
            textwidth -= 1;
        if (curwin->w_p_nu || curwin->w_p_rnu)
            textwidth -= 8;
    }
    if (textwidth < 0)
        textwidth = 0;
    if (ff && textwidth == 0) {
        textwidth = curwin->w_width - 1;
        if (textwidth > 79)
            textwidth = 79;
    }
    return textwidth;
}

static void internal_format (int textwidth, int second_indent, int flags, int format_only, int c) {
    int cc;
    int save_char = NUL;
    int haveto_redraw = FALSE;
    int fo_ins_blank = has_format_option (FO_INS_BLANK);
    int fo_white_par = has_format_option (FO_WHITE_PAR);
    int first_line = TRUE;
    colnr_T leader_len;
    int no_leader = FALSE;
    int do_comments = (flags & INSCHAR_DO_COM);
    int has_lbr = curwin->w_p_lbr;
    curwin->w_p_lbr = FALSE;
    if (!curbuf->b_p_ai && !(State & VREPLACE_FLAG)) {
        cc = gchar_cursor ();
        if (VIM_ISWHITE (cc)) {
            save_char = cc;
            pchar_cursor ('x');
        }
    }
    while (!got_int) {
        int startcol;
        int wantcol;
        int foundcol;
        int end_foundcol = 0;
        colnr_T len;
        colnr_T virtcol;
        int orig_col = 0;
        char_u *saved_text = NULL;
        colnr_T col;
        colnr_T end_col;
        virtcol = get_nolist_virtcol () + char2cells (c != NUL ? c : gchar_cursor ());
        if (virtcol <= (colnr_T) textwidth)
            break;
        if (no_leader)
            do_comments = FALSE;
        else if (!(flags & INSCHAR_FORMAT) && has_format_option (FO_WRAP_COMS))
            do_comments = TRUE;
        if (do_comments)
            leader_len = get_leader_len (ml_get_curline (), NULL, FALSE, TRUE);
        else
            leader_len = 0;
        if (leader_len == 0)
            no_leader = TRUE;
        if (!(flags & INSCHAR_FORMAT) && leader_len == 0 && !has_format_option (FO_WRAP))
            break;
        if ((startcol = curwin->w_cursor.col) == 0)
            break;
        coladvance ((colnr_T) textwidth);
        wantcol = curwin->w_cursor.col;
        curwin->w_cursor.col = startcol;
        foundcol = 0;
        while ((!fo_ins_blank && !has_format_option (FO_INS_VI)) || (flags & INSCHAR_FORMAT) || curwin->w_cursor.lnum != Insstart.lnum || curwin->w_cursor.col >= Insstart.col) {
            if (curwin->w_cursor.col == startcol && c != NUL)
                cc = c;
            else
                cc = gchar_cursor ();
            if (WHITECHAR (cc)) {
                end_col = curwin->w_cursor.col;
                while (curwin->w_cursor.col > 0 && WHITECHAR (cc)) {
                    dec_cursor ();
                    cc = gchar_cursor ();
                }
                if (curwin->w_cursor.col == 0 && WHITECHAR (cc))
                    break;
                if (curwin->w_cursor.col < leader_len)
                    break;
                if (has_format_option (FO_ONE_LETTER)) {
                    if (curwin->w_cursor.col == 0)
                        break;
                    if (curwin->w_cursor.col <= leader_len)
                        break;
                    col = curwin->w_cursor.col;
                    dec_cursor ();
                    cc = gchar_cursor ();
                    if (WHITECHAR (cc))
                        continue;
                    curwin->w_cursor.col = col;
                }
                inc_cursor ();
                end_foundcol = end_col + 1;
                foundcol = curwin->w_cursor.col;
                if (curwin->w_cursor.col <= (colnr_T) wantcol)
                    break;
            }
            if (curwin->w_cursor.col == 0)
                break;
            dec_cursor ();
        }
        if (foundcol == 0) {
            curwin->w_cursor.col = startcol;
            break;
        }
        undisplay_dollar ();
        if (State & VREPLACE_FLAG)
            orig_col = startcol;
        else
            replace_offset = startcol - end_foundcol;
        curwin->w_cursor.col = foundcol;
        while ((cc = gchar_cursor (), WHITECHAR (cc)) && (!fo_white_par || curwin->w_cursor.col < startcol))
            inc_cursor ();
        startcol -= curwin->w_cursor.col;
        if (startcol < 0)
            startcol = 0;
        if (State & VREPLACE_FLAG) {
            saved_text = vim_strsave (ml_get_cursor ());
            curwin->w_cursor.col = orig_col;
            if (saved_text == NULL)
                break;
            saved_text[startcol] = NUL;
            if (!fo_white_par)
                backspace_until_column (foundcol);
        }
        else {
            if (!fo_white_par)
                curwin->w_cursor.col = foundcol;
        }
        open_line (FORWARD, OPENLINE_DELSPACES + OPENLINE_MARKFIX + (fo_white_par ? OPENLINE_KEEPTRAIL : 0) + (do_comments ? OPENLINE_DO_COM : 0) + ((flags & INSCHAR_COM_LIST) ? OPENLINE_COM_LIST : 0), ((flags & INSCHAR_COM_LIST) ? second_indent : old_indent));
        if (!(flags & INSCHAR_COM_LIST))
            old_indent = 0;
        replace_offset = 0;
        if (first_line) {
            if (!(flags & INSCHAR_COM_LIST)) {
                if (second_indent < 0 && has_format_option (FO_Q_NUMBER))
                    second_indent = get_number_indent (curwin->w_cursor.lnum - 1);
                if (second_indent >= 0) {
                    if (State & VREPLACE_FLAG)
                        change_indent (INDENT_SET, second_indent, FALSE, NUL, TRUE);
                    else if (leader_len > 0 && second_indent - leader_len > 0) {
                        int i;
                        int padding = second_indent - leader_len;
                        for (i = 0; i < padding; i++)
                            ins_str ((char_u *) " ");
                        changed_bytes (curwin -> w_cursor.lnum, leader_len);
                    }
                    else {
                        (void) set_indent (second_indent, SIN_CHANGED);
                    }
                }
            }
            first_line = FALSE;
        }
        if (State & VREPLACE_FLAG) {
            ins_bytes (saved_text);
            vim_free (saved_text);
        }
        else {
            curwin->w_cursor.col += startcol;
            len = (colnr_T) STRLEN (ml_get_curline ());
            if (curwin->w_cursor.col > len)
                curwin->w_cursor.col = len;
        }
        haveto_redraw = TRUE;
        can_cindent = TRUE;
        did_ai = FALSE;
        did_si = FALSE;
        can_si = FALSE;
        can_si_back = FALSE;
        line_breakcheck ();
    }
    if (save_char != NUL)
        pchar_cursor (save_char);
    curwin->w_p_lbr = has_lbr;
    if (!format_only && haveto_redraw) {
        update_topline ();
        redraw_curbuf_later (VALID);
    }
}

static colnr_T get_nolist_virtcol (void) {
    if (curwin->w_p_list && vim_strchr (p_cpo, CPO_LISTWM) == NULL)
        return getvcol_nolist (&curwin->w_cursor);
    validate_virtcol ();
    return curwin->w_virtcol;
}

void backspace_until_column (int col) {
    while ((int) curwin->w_cursor.col > col) {
        curwin->w_cursor.col--;
        if (State & REPLACE_FLAG)
            replace_do_bs (col);
        else if (!del_char_after_col (col))
            break;
    }
}

static void replace_do_bs (int limit_col) {
    int cc;
    int orig_len = 0;
    int ins_len;
    int orig_vcols = 0;
    colnr_T start_vcol;
    char_u *p;
    int i;
    int vcol;
    cc = replace_pop ();
    if (cc > 0) {
        if (State & VREPLACE_FLAG) {
            getvcol (curwin, & curwin -> w_cursor, NULL, & start_vcol, NULL);
            orig_vcols = chartabsize (ml_get_cursor (), start_vcol);
        }
        {
            pchar_cursor (cc);
            if (State & VREPLACE_FLAG)
                orig_len = (int) STRLEN (ml_get_cursor ()) - 1;
        }
        replace_pop_ins ();
        if (State & VREPLACE_FLAG) {
            p = ml_get_cursor ();
            ins_len = (int) STRLEN (p) - orig_len;
            vcol = start_vcol;
            for (i = 0; i < ins_len; ++i) {
                vcol += chartabsize (p +i, vcol);
            }
            vcol -= start_vcol;
            curwin->w_cursor.col += ins_len;
            while (vcol > orig_vcols && gchar_cursor () == ' ') {
                del_char (FALSE);
                ++orig_vcols;
            }
            curwin->w_cursor.col -= ins_len;
        }
        changed_bytes (curwin -> w_cursor.lnum, curwin -> w_cursor.col);
    }
    else if (cc == 0)
        (void) del_char_after_col (limit_col);
}

static int replace_pop (void) {
    if (replace_stack_nr == 0)
        return -1;
    return (int) replace_stack[--replace_stack_nr];
}

static void replace_pop_ins (void) {
    int cc;
    int oldState = State;
    State = NORMAL;
    while ((cc = replace_pop ()) > 0) {
        ins_char (cc);
        dec_cursor ();
    }
    State = oldState;
}

void replace_push (int c) {
    char_u *p;
    if (replace_stack_nr < replace_offset)
        return;
    if (replace_stack_len <= replace_stack_nr) {
        replace_stack_len += 50;
        p = lalloc (sizeof (char_u) * replace_stack_len, TRUE);
        if (p == NULL) {
            replace_stack_len -= 50;
            return;
        }
        if (replace_stack != NULL) {
            mch_memmove (p, replace_stack, (size_t) (replace_stack_nr * sizeof (char_u)));
            vim_free (replace_stack);
        }
        replace_stack = p;
    }
    p = replace_stack + replace_stack_nr - replace_offset;
    if (replace_offset)
        mch_memmove (p +1, p, (size_t) (replace_offset * sizeof (char_u)));
    *p = c;
    ++replace_stack_nr;
}

static int del_char_after_col (int limit_col) {
    (void) del_char (FALSE);
    return TRUE;
}

void truncate_spaces (char_u *line) {
    int i;
    for (i = (int) STRLEN (line) - 1; i >= 0 && VIM_ISWHITE (line[i]); i--) {
        if (State & REPLACE_FLAG)
            replace_join (0);
    }
    line[i + 1] = NUL;
}

static void replace_join (int off) {
    int i;
    for (i = replace_stack_nr; --i >= 0;)
        if (replace_stack[i] == NUL && off-- <= 0) {
            --replace_stack_nr;
            mch_memmove (replace_stack + i, replace_stack + i + 1, (size_t) (replace_stack_nr - i));
            return;
        }
}

void fixthisline (int (*get_the_indent) (void)) {
    int amount = get_the_indent ();
    if (amount >= 0) {
        change_indent (INDENT_SET, amount, FALSE, 0, TRUE);
        if (linewhite (curwin->w_cursor.lnum))
            did_ai = TRUE;
    }
}

int in_cinkeys (int keytyped, int when, int line_is_empty) {
    char_u *look;
    int try_match;
    int try_match_word;
    char_u *p;
    char_u *line;
    int icase;
    int i;
    if (keytyped == NUL)
        return FALSE;
    if (*curbuf->b_p_inde != NUL)
        look = curbuf->b_p_indk;
    else
        look = curbuf->b_p_cink;
    while (*look) {
        switch (when) {
        case '*' :
            try_match = (*look == '*');
            break;
        case '!' :
            try_match = (*look == '!');
            break;
        default :
            try_match = (*look != '*');
            break;
        }
        if (*look == '*' || *look == '!')
            ++look;
        if (*look == '0') {
            try_match_word = try_match;
            if (!line_is_empty)
                try_match = FALSE;
            ++look;
        }
        else
            try_match_word = FALSE;
        if (*look == '^' && look[1] >= '?' && look[1] <= '_') {
            if (try_match && keytyped == Ctrl_chr (look[1]))
                return TRUE;
            look += 2;
        }
        else if (*look == 'o') {
            if (try_match && keytyped == KEY_OPEN_FORW)
                return TRUE;
            ++look;
        }
        else if (*look == 'O') {
            if (try_match && keytyped == KEY_OPEN_BACK)
                return TRUE;
            ++look;
        }
        else if (*look == 'e') {
            if (try_match && keytyped == 'e' && curwin->w_cursor.col >= 4) {
                p = ml_get_curline ();
                if (skipwhite (p) == p + curwin->w_cursor.col - 4 && STRNCMP (p +curwin->w_cursor.col - 4, "else", 4) == 0)
                    return TRUE;
            }
            ++look;
        }
        else if (*look == ':') {
            if (try_match && keytyped == ':') {
                p = ml_get_curline ();
                if (cin_iscase (p, FALSE) || cin_isscopedecl (p) || cin_islabel ())
                    return TRUE;
                p = ml_get_curline ();
                if (curwin->w_cursor.col > 2 && p[curwin->w_cursor.col - 1] == ':' && p[curwin->w_cursor.col - 2] == ':') {
                    p[curwin->w_cursor.col - 1] = ' ';
                    i = (cin_iscase (p, FALSE) || cin_isscopedecl (p) || cin_islabel ());
                    p = ml_get_curline ();
                    p[curwin->w_cursor.col - 1] = ':';
                    if (i)
                        return TRUE;
                }
            }
            ++look;
        }
        else if (*look == '<') {
            if (try_match) {
                if (vim_strchr ((char_u *) "<>!*oOe0:", look[1]) != NULL && keytyped == look[1])
                    return TRUE;
                if (keytyped == get_special_key_code (look +1))
                    return TRUE;
            }
            while (*look && *look != '>')
                look++;
            while (*look == '>')
                look++;
        }
        else if (*look == '=' && look[1] != ',' && look[1] != NUL) {
            ++look;
            if (*look == '~') {
                icase = TRUE;
                ++look;
            }
            else
                icase = FALSE;
            p = vim_strchr (look, ',');
            if (p == NULL)
                p = look + STRLEN (look);
            if ((try_match || try_match_word) && curwin->w_cursor.col >= (colnr_T) (p - look)) {
                int match = FALSE;
                if (keytyped == KEY_COMPLETE) {
                    char_u *s;
                    line = ml_get_curline ();
                    for (s = line + curwin->w_cursor.col; s > line; --s)
                        if (!vim_iswordc (s[-1]))
                            break;
                    if (s + (p - look) <= line + curwin->w_cursor.col && (icase ? MB_STRNICMP (s, look, p -look) : STRNCMP (s, look, p -look)) == 0)
                        match = TRUE;
                }
                else if (keytyped == (int) p[-1] || (icase && keytyped < 256 && TOLOWER_LOC (keytyped) == TOLOWER_LOC ((int) p[-1]))) {
                    line = ml_get_cursor ();
                    if ((curwin->w_cursor.col == (colnr_T) (p - look) || !vim_iswordc (line[-(p - look) - 1])) && (icase ? MB_STRNICMP (line -(p - look), look, p -look) : STRNCMP (line -(p - look), look, p -look)) == 0)
                        match = TRUE;
                }
                if (match && try_match_word && !try_match) {
                    if (getwhitecols_curline () != (int) (curwin->w_cursor.col - (p - look)))
                        match = FALSE;
                }
                if (match)
                    return TRUE;
            }
            look = p;
        }
        else {
            if (try_match && *look == keytyped)
                return TRUE;
            if (*look != NUL)
                ++look;
        }
        look = skip_to_option_part (look);
    }
    return FALSE;
}

void change_indent (int type, int amount, int round, int replaced, int call_changed_bytes) {
    int vcol;
    int last_vcol;
    int insstart_less;
    int new_cursor_col;
    int i;
    char_u *ptr;
    int save_p_list;
    int start_col;
    colnr_T vc;
    colnr_T orig_col = 0;
    char_u *new_line, *orig_line = NULL;
    if (State & VREPLACE_FLAG) {
        orig_line = vim_strsave (ml_get_curline ());
        orig_col = curwin->w_cursor.col;
    }
    save_p_list = curwin->w_p_list;
    curwin->w_p_list = FALSE;
    vc = getvcol_nolist (&curwin->w_cursor);
    vcol = vc;
    start_col = curwin->w_cursor.col;
    new_cursor_col = curwin->w_cursor.col;
    beginline (BL_WHITE);
    new_cursor_col -= curwin->w_cursor.col;
    insstart_less = curwin->w_cursor.col;
    if (new_cursor_col < 0)
        vcol = get_indent () - vcol;
    if (new_cursor_col > 0)
        start_col = -1;
    if (type == INDENT_SET)
        (void) set_indent (amount, call_changed_bytes ? SIN_CHANGED : 0);
    else {
        int save_State = State;
        if (State & VREPLACE_FLAG)
            State = INSERT;
        shift_line (type == INDENT_DEC, round, 1, call_changed_bytes);
        State = save_State;
    }
    insstart_less -= curwin->w_cursor.col;
    if (new_cursor_col >= 0) {
        if (new_cursor_col == 0)
            insstart_less = MAXCOL;
        new_cursor_col += curwin->w_cursor.col;
    }
    else if (!(State & INSERT))
        new_cursor_col = curwin->w_cursor.col;
    else {
        vcol = get_indent () - vcol;
        curwin->w_virtcol = (colnr_T) ((vcol < 0) ? 0 : vcol);
        vcol = last_vcol = 0;
        new_cursor_col = -1;
        ptr = ml_get_curline ();
        while (vcol <= (int) curwin->w_virtcol) {
            last_vcol = vcol;
            ++new_cursor_col;
            vcol += lbr_chartabsize (ptr, ptr +new_cursor_col, (colnr_T) vcol);
        }
        vcol = last_vcol;
        if (vcol != (int) curwin->w_virtcol) {
            curwin->w_cursor.col = (colnr_T) new_cursor_col;
            i = (int) curwin->w_virtcol - vcol;
            ptr = alloc ((unsigned ) (i + 1));
            if (ptr != NULL) {
                new_cursor_col += i;
                ptr[i] = NUL;
                while (--i >= 0)
                    ptr[i] = ' ';
                ins_str (ptr);
                vim_free (ptr);
            }
        }
        insstart_less = MAXCOL;
    }
    curwin->w_p_list = save_p_list;
    if (new_cursor_col <= 0)
        curwin->w_cursor.col = 0;
    else
        curwin->w_cursor.col = (colnr_T) new_cursor_col;
    curwin->w_set_curswant = TRUE;
    changed_cline_bef_curs ();
    if (State & INSERT) {
        if (curwin->w_cursor.lnum == Insstart.lnum && Insstart.col != 0) {
            if ((int) Insstart.col <= insstart_less)
                Insstart.col = 0;
            else
                Insstart.col -= insstart_less;
        }
        if ((int) ai_col <= insstart_less)
            ai_col = 0;
        else
            ai_col -= insstart_less;
    }
    if (REPLACE_NORMAL (State) && start_col >= 0) {
        while (start_col > (int) curwin->w_cursor.col) {
            replace_join (0);
            --start_col;
        }
        while (start_col < (int) curwin->w_cursor.col || replaced) {
            replace_push (NUL);
            if (replaced) {
                replace_push (replaced);
                replaced = NUL;
            }
            ++start_col;
        }
    }
    if (State & VREPLACE_FLAG) {
        if (orig_line == NULL)
            return;
        new_line = vim_strsave (ml_get_curline ());
        if (new_line == NULL)
            return;
        new_line[curwin->w_cursor.col] = NUL;
        ml_replace (curwin -> w_cursor.lnum, orig_line, FALSE);
        curwin->w_cursor.col = orig_col;
        backspace_until_column (0);
        ins_bytes (new_line);
        vim_free (new_line);
    }
}

static int cindent_on (void) {
    return (!p_paste && (curbuf->b_p_cin || *curbuf->b_p_inde != NUL));
}

static void redo_literal (int c) {
    char_u buf [10];
    if (VIM_ISDIGIT (c)) {
        vim_snprintf ((char *) buf, sizeof (buf), "%03d", c);
        AppendToRedobuff (buf);
    }
    else
        AppendCharToRedobuff (c);
}

static int ins_start_select (int c) {
    if (km_startsel)
        switch (c) {
        case K_KHOME :
        case K_KEND :
        case K_PAGEUP :
        case K_KPAGEUP :
        case K_PAGEDOWN :
        case K_KPAGEDOWN :
        case K_LEFT :
        case K_RIGHT :
        case K_UP :
        case K_DOWN :
        case K_END :
        case K_HOME :
            if (!(mod_mask & MOD_MASK_SHIFT))
                break;
        case K_S_LEFT :
        case K_S_RIGHT :
        case K_S_UP :
        case K_S_DOWN :
        case K_S_END :
        case K_S_HOME :
            start_selection ();
            stuffcharReadbuff (Ctrl_O);
            if (mod_mask) {
                char_u buf [4];
                buf[0] = K_SPECIAL;
                buf[1] = KS_MODIFIER;
                buf[2] = mod_mask;
                buf[3] = NUL;
                stuffReadbuff (buf);
            }
            stuffcharReadbuff (c);
            return TRUE;
        }
    return FALSE;
}

static int echeck_abbr (int c) {
    if (p_paste || no_abbr || arrow_used)
        return FALSE;
    return check_abbr (c, ml_get_curline (), curwin->w_cursor.col, curwin->w_cursor.lnum == Insstart.lnum ? Insstart.col : 0);
}

static int ins_esc (long  *count, int cmdchar, int nomove) {
    int temp;
    static int disabled_redraw = FALSE;
    temp = curwin->w_cursor.col;
    if (disabled_redraw) {
        --RedrawingDisabled;
        disabled_redraw = FALSE;
    }
    if (!arrow_used) {
        if (cmdchar != 'r' && cmdchar != 'v')
            AppendToRedobuff (p_im ? (char_u *) "\014" : ESC_STR);
        if (*count > 0) {
            line_breakcheck ();
            if (got_int)
                *count = 0;
        }
        if (--*count > 0) {
            if (vim_strchr (p_cpo, CPO_REPLCNT) != NULL)
                State &= ~REPLACE_FLAG;
            (void) start_redo_ins ();
            if (cmdchar == 'r' || cmdchar == 'v')
                stuffRedoReadbuff (ESC_STR);
            ++RedrawingDisabled;
            disabled_redraw = TRUE;
            return FALSE;
        }
        stop_insert (& curwin -> w_cursor, TRUE, nomove);
        undisplay_dollar ();
    }
    if (restart_edit == NUL && (colnr_T) temp == curwin->w_cursor.col)
        curwin->w_set_curswant = TRUE;
    if (!cmdmod.keepjumps)
        curbuf->b_last_insert = curwin->w_cursor;
    if (!nomove && (curwin->w_cursor.col != 0 || curwin->w_cursor.coladd > 0) && (restart_edit == NUL || (gchar_cursor () == NUL && !VIsual_active)) && !revins_on) {
        if (curwin->w_cursor.coladd > 0 || ve_flags == VE_ALL) {
            oneleft ();
            if (restart_edit != NUL)
                ++curwin->w_cursor.coladd;
        }
        else {
            --curwin->w_cursor.col;
        }
    }
    State = NORMAL;
    changed_cline_bef_curs ();
    setmouse ();
    if (!p_ek)
        out_str (T_BE);
    if (Recording || restart_edit != NUL)
        showmode ();
    else if (p_smd)
        MSG ("");
    return TRUE;
}

static void stop_insert (pos_T *end_insert_pos, int esc, int nomove) {
    int cc;
    char_u *ptr;
    stop_redo_ins ();
    replace_flush ();
    ptr = get_inserted ();
    if (did_restart_edit == 0 || (ptr != NULL && (int) STRLEN (ptr) > new_insert_skip)) {
        vim_free (last_insert);
        last_insert = ptr;
        last_insert_skip = new_insert_skip;
    }
    else
        vim_free (ptr);
    if (!arrow_used && end_insert_pos != NULL) {
        if (!ins_need_undo && has_format_option (FO_AUTO)) {
            pos_T tpos = curwin->w_cursor;
            cc = 'x';
            if (curwin->w_cursor.col > 0 && gchar_cursor () == NUL) {
                dec_cursor ();
                cc = gchar_cursor ();
                if (!VIM_ISWHITE (cc))
                    curwin->w_cursor = tpos;
            }
            auto_format (TRUE, FALSE);
            if (VIM_ISWHITE (cc)) {
                if (gchar_cursor () != NUL)
                    inc_cursor ();
                if (gchar_cursor () == NUL && curwin->w_cursor.lnum == tpos.lnum && curwin->w_cursor.col == tpos.col)
                    curwin->w_cursor.coladd = tpos.coladd;
            }
        }
        check_auto_format (TRUE);
        if (!nomove && did_ai && (esc || (vim_strchr (p_cpo, CPO_INDENT) == NULL && curwin->w_cursor.lnum != end_insert_pos->lnum)) && end_insert_pos->lnum <= curbuf->b_ml.ml_line_count) {
            pos_T tpos = curwin->w_cursor;
            curwin->w_cursor = *end_insert_pos;
            check_cursor_col ();
            for (;;) {
                if (gchar_cursor () == NUL && curwin->w_cursor.col > 0)
                    --curwin->w_cursor.col;
                cc = gchar_cursor ();
                if (!VIM_ISWHITE (cc))
                    break;
                if (del_char (TRUE) == FAIL)
                    break;
            }
            if (curwin->w_cursor.lnum != tpos.lnum)
                curwin->w_cursor = tpos;
            else {
                tpos = curwin->w_cursor;
                tpos.col++;
                if (cc != NUL && gchar_pos (&tpos) == NUL)
                    ++curwin->w_cursor.col;
            }
            if (VIsual_active && VIsual.lnum == curwin->w_cursor.lnum) {
                int len = (int) STRLEN (ml_get_curline ());
                if (VIsual.col > len) {
                    VIsual.col = len;
                    VIsual.coladd = 0;
                }
            }
        }
    }
    did_ai = FALSE;
    did_si = FALSE;
    can_si = FALSE;
    can_si_back = FALSE;
    if (end_insert_pos != NULL) {
        curbuf->b_op_start = Insstart;
        curbuf->b_op_start_orig = Insstart_orig;
        curbuf->b_op_end = *end_insert_pos;
    }
}

static void replace_flush (void) {
    VIM_CLEAR (replace_stack);
    replace_stack_len = 0;
    replace_stack_nr = 0;
}

void auto_format (int trailblank, int prev_line) {
    pos_T pos;
    colnr_T len;
    char_u *old;
    char_u *new, *pnew;
    int wasatend;
    int cc;
    if (!has_format_option (FO_AUTO))
        return;
    pos = curwin->w_cursor;
    old = ml_get_curline ();
    check_auto_format (FALSE);
    wasatend = (pos.col == (colnr_T) STRLEN (old));
    if (*old != NUL && !trailblank && wasatend) {
        dec_cursor ();
        cc = gchar_cursor ();
        if (!WHITECHAR (cc) && curwin->w_cursor.col > 0 && has_format_option (FO_ONE_LETTER))
            dec_cursor ();
        cc = gchar_cursor ();
        if (WHITECHAR (cc)) {
            curwin->w_cursor = pos;
            return;
        }
        curwin->w_cursor = pos;
    }
    if (has_format_option (FO_WRAP_COMS) && !has_format_option (FO_WRAP) && get_leader_len (old, NULL, FALSE, TRUE) == 0)
        return;
    if (prev_line && !paragraph_start (curwin->w_cursor.lnum)) {
        --curwin->w_cursor.lnum;
        if (u_save_cursor () == FAIL)
            return;
    }
    saved_cursor = pos;
    format_lines ((linenr_T) - 1, FALSE);
    curwin->w_cursor = saved_cursor;
    saved_cursor.lnum = 0;
    if (curwin->w_cursor.lnum > curbuf->b_ml.ml_line_count) {
        curwin->w_cursor.lnum = curbuf->b_ml.ml_line_count;
        coladvance ((colnr_T) MAXCOL);
    }
    else
        check_cursor_col ();
    if (!wasatend && has_format_option (FO_WHITE_PAR)) {
        new = ml_get_curline ();
        len = (colnr_T) STRLEN (new);
        if (curwin->w_cursor.col == len) {
            pnew = vim_strnsave (new, len +2);
            pnew[len] = ' ';
            pnew[len + 1] = NUL;
            ml_replace (curwin -> w_cursor.lnum, pnew, FALSE);
            did_add_space = TRUE;
        }
        else
            check_auto_format (FALSE);
    }
    check_cursor ();
}

static void check_auto_format (int end_insert) {
    int c = ' ';
    int cc;
    if (did_add_space) {
        cc = gchar_cursor ();
        if (!WHITECHAR (cc))
            did_add_space = FALSE;
        else {
            if (!end_insert) {
                inc_cursor ();
                c = gchar_cursor ();
                dec_cursor ();
            }
            if (c != NUL) {
                del_char (FALSE);
                did_add_space = FALSE;
            }
        }
    }
}

int oneleft (void) {
    if (virtual_active ()) {
        int width;
        int v = getviscol ();
        if (v == 0)
            return FAIL;
        width = 1;
        for (;;) {
            coladvance (v - width);
            if ((*p_sbr == NUL && !curwin->w_p_bri) || getviscol () < v)
                break;
            ++width;
        }
        if (curwin->w_cursor.coladd == 1) {
            char_u *ptr;
            ptr = ml_get_cursor ();
            if (*ptr != TAB && vim_isprintc (*ptr) && ptr2cells (ptr) > 1)
                curwin->w_cursor.coladd = 0;
        }
        curwin->w_set_curswant = TRUE;
        return OK;
    }
    if (curwin->w_cursor.col == 0)
        return FAIL;
    curwin->w_set_curswant = TRUE;
    --curwin->w_cursor.col;
    return OK;
}

static void ins_insert (int replaceState) {
    if (p_fkmap && p_ri) {
        beep_flush ();
        EMSG (farsi_text_3);
        return;
    }
    set_vim_var_string (VV_INSERTMODE, (char_u *) ((State & REPLACE_FLAG) ? "i" : replaceState == VREPLACE ? "v" : "r"), 1);
    apply_autocmds (EVENT_INSERTCHANGE, NULL, NULL, FALSE, curbuf);
    if (State & REPLACE_FLAG)
        State = INSERT | (State & LANGMAP);
    else
        State = replaceState | (State & LANGMAP);
    AppendCharToRedobuff (K_INS);
    showmode ();
}

int stuff_inserted (int c, long  count, int no_esc) {
    char_u *esc_ptr;
    char_u *ptr;
    char_u *last_ptr;
    char_u last = NUL;
    ptr = get_last_insert ();
    if (ptr == NULL) {
        EMSG (_ (e_noinstext));
        return FAIL;
    }
    if (c != NUL)
        stuffcharReadbuff (c);
    if ((esc_ptr = (char_u *) vim_strrchr (ptr, ESC)) != NULL)
        *esc_ptr = NUL;
    last_ptr = (esc_ptr ? esc_ptr : ptr + STRLEN (ptr)) - 1;
    if (last_ptr >= ptr && (*last_ptr == '0' || *last_ptr == '^') && (no_esc || (*ptr == Ctrl_D && count > 1))) {
        last = *last_ptr;
        *last_ptr = NUL;
    }
    do {
        stuffReadbuff (ptr);
        if (last)
            stuffReadbuff ((char_u *) (last == '0' ? IF_EB ("\026\060\064\070", CTRL_V_STR "xf0") : IF_EB ("\026^", CTRL_V_STR "^")));
    }
    while (--count > 0);
    if (last)
        *last_ptr = last;
    if (esc_ptr != NULL)
        *esc_ptr = ESC;
    if (!no_esc)
        stuffcharReadbuff (ESC);
    return OK;
}

char_u *get_last_insert (void) {
    if (last_insert == NULL)
        return NULL;
    return last_insert + last_insert_skip;
}

static void ins_reg (void) {
    int need_redraw = FALSE;
    int regname;
    int literally = 0;
    int vis_active = VIsual_active;
    pc_status = PC_STATUS_UNSET;
    if (redrawing () && !char_avail ()) {
        ins_redraw (FALSE);
        edit_putchar ('"', TRUE);
        add_to_showcmd_c (Ctrl_R);
    }
    ++no_mapping;
    regname = plain_vgetc ();
    LANGMAP_ADJUST (regname, TRUE);
    if (regname == Ctrl_R || regname == Ctrl_O || regname == Ctrl_P) {
        literally = regname;
        add_to_showcmd_c (literally);
        regname = plain_vgetc ();
        LANGMAP_ADJUST (regname, TRUE);
    }
    --no_mapping;
    ++no_u_sync;
    if (regname == '=') {
        u_sync_once = 2;
        regname = get_expr_register ();
    }
    if (regname == NUL || !valid_yank_reg (regname, FALSE)) {
        vim_beep (BO_REG);
        need_redraw = TRUE;
    }
    else {
        if (literally == Ctrl_O || literally == Ctrl_P) {
            AppendCharToRedobuff (Ctrl_R);
            AppendCharToRedobuff (literally);
            AppendCharToRedobuff (regname);
            do_put (regname, BACKWARD, 1L, (literally == Ctrl_P ? PUT_FIXINDENT : 0) | PUT_CURSEND);
        }
        else if (insert_reg (regname, literally) == FAIL) {
            vim_beep (BO_REG);
            need_redraw = TRUE;
        }
        else if (stop_insert_mode)
            need_redraw = TRUE;
    }
    --no_u_sync;
    if (u_sync_once == 1)
        ins_need_undo = TRUE;
    u_sync_once = 0;
    clear_showcmd ();
    if (need_redraw || stuff_empty ())
        edit_unputchar ();
    if (!vis_active && VIsual_active)
        end_visual_mode ();
}

static void ins_ctrl_g (void) {
    int c;
    setcursor ();
    ++no_mapping;
    c = plain_vgetc ();
    --no_mapping;
    switch (c) {
    case K_UP :
    case Ctrl_K :
    case 'k' :
        ins_up (TRUE);
        break;
    case K_DOWN :
    case Ctrl_J :
    case 'j' :
        ins_down (TRUE);
        break;
    case 'u' :
        u_sync (TRUE);
        ins_need_undo = TRUE;
        update_Insstart_orig = FALSE;
        Insstart = curwin->w_cursor;
        break;
    case 'U' :
        dont_sync_undo = MAYBE;
        break;
    default :
        vim_beep (BO_CTRLG);
    }
}

static void ins_up (int startcol) {
    pos_T tpos;
    linenr_T old_topline = curwin->w_topline;
    int old_topfill = curwin->w_topfill;
    undisplay_dollar ();
    tpos = curwin->w_cursor;
    if (cursor_up (1L, TRUE) == OK) {
        if (startcol)
            coladvance (getvcol_nolist (&Insstart));
        if (old_topline != curwin->w_topline || old_topfill != curwin->w_topfill)
            redraw_later (VALID);
        start_arrow (& tpos);
        can_cindent = TRUE;
    }
    else
        vim_beep (BO_CRSR);
}

int cursor_up (long  n, int upd_topline) {
    linenr_T lnum;
    if (n > 0) {
        lnum = curwin->w_cursor.lnum;
        if (lnum <= 1 || (n >= lnum && vim_strchr (p_cpo, CPO_MINUS) != NULL))
            return FAIL;
        if (n >= lnum)
            lnum = 1;
        else if (hasAnyFolding (curwin)) {
            (void) hasFolding (lnum, &lnum, NULL);
            while (n--) {
                --lnum;
                if (lnum <= 1)
                    break;
                if (n > 0 || !((State & INSERT) || (fdo_flags & FDO_ALL)))
                    (void) hasFolding (lnum, &lnum, NULL);
            }
            if (lnum < 1)
                lnum = 1;
        }
        else
            lnum -= n;
        curwin->w_cursor.lnum = lnum;
    }
    coladvance (curwin -> w_curswant);
    if (upd_topline)
        update_topline ();
    return OK;
}

static void start_arrow (pos_T *end_insert_pos) {
    start_arrow_common (end_insert_pos, TRUE);
}

static void ins_down (int startcol) {
    pos_T tpos;
    linenr_T old_topline = curwin->w_topline;
    int old_topfill = curwin->w_topfill;
    undisplay_dollar ();
    tpos = curwin->w_cursor;
    if (cursor_down (1L, TRUE) == OK) {
        if (startcol)
            coladvance (getvcol_nolist (&Insstart));
        if (old_topline != curwin->w_topline || old_topfill != curwin->w_topfill)
            redraw_later (VALID);
        start_arrow (& tpos);
        can_cindent = TRUE;
    }
    else
        vim_beep (BO_CRSR);
}

int cursor_down (long  n, int upd_topline) {
    linenr_T lnum;
    if (n > 0) {
        lnum = curwin->w_cursor.lnum;
        (void) hasFolding (lnum, NULL, &lnum);
        if (lnum >= curbuf->b_ml.ml_line_count || (lnum + n > curbuf->b_ml.ml_line_count && vim_strchr (p_cpo, CPO_MINUS) != NULL))
            return FAIL;
        if (lnum + n >= curbuf->b_ml.ml_line_count)
            lnum = curbuf->b_ml.ml_line_count;
        else if (hasAnyFolding (curwin)) {
            linenr_T last;
            while (n--) {
                if (hasFolding (lnum, NULL, &last))
                    lnum = last + 1;
                else
                    ++lnum;
                if (lnum >= curbuf->b_ml.ml_line_count)
                    break;
            }
            if (lnum > curbuf->b_ml.ml_line_count)
                lnum = curbuf->b_ml.ml_line_count;
        }
        else
            lnum += n;
        curwin->w_cursor.lnum = lnum;
    }
    coladvance (curwin -> w_curswant);
    if (upd_topline)
        update_topline ();
    return OK;
}

static void ins_ctrl_hat (void) {
    if (map_to_exists_mode ((char_u *) "", LANGMAP, FALSE)) {
        if (State & LANGMAP) {
            curbuf->b_p_iminsert = B_IMODE_NONE;
            State &= ~LANGMAP;
        }
        else {
            curbuf->b_p_iminsert = B_IMODE_LMAP;
            State |= LANGMAP;
        }
    }
    set_iminsert_global ();
    showmode ();
    if (gui.in_use)
        gui_update_cursor (TRUE, FALSE);
    status_redraw_curbuf ();
}

static void ins_ctrl_ (void) {
    if (revins_on && revins_chars && revins_scol >= 0) {
        while (gchar_cursor () != NUL && revins_chars--)
            ++curwin->w_cursor.col;
    }
    p_ri = !p_ri;
    revins_on = (State == INSERT && p_ri);
    if (revins_on) {
        revins_scol = curwin->w_cursor.col;
        revins_legal++;
        revins_chars = 0;
        undisplay_dollar ();
    }
    else
        revins_scol = -1;
    if (p_altkeymap) {
        arrow_used = TRUE;
        (void) stop_arrow ();
        p_fkmap = curwin->w_p_rl ^ p_ri;
        if (p_fkmap && p_ri)
            State = INSERT;
    }
    else
        p_hkmap = curwin->w_p_rl ^ p_ri;
    showmode ();
}

static void ins_shift (int c, int lastc) {
    if (stop_arrow () == FAIL)
        return;
    AppendCharToRedobuff (c);
    if (c == Ctrl_D && (lastc == '0' || lastc == '^') && curwin->w_cursor.col > 0) {
        --curwin->w_cursor.col;
        (void) del_char (FALSE);
        if (State & REPLACE_FLAG)
            replace_pop_ins ();
        if (lastc == '^')
            old_indent = get_indent ();
        change_indent (INDENT_SET, 0, TRUE, 0, TRUE);
    }
    else
        change_indent (c == Ctrl_D ? INDENT_DEC : INDENT_INC, 0, TRUE, 0, TRUE);
    if (did_ai && *skipwhite (ml_get_curline ()) != NUL)
        did_ai = FALSE;
    did_si = FALSE;
    can_si = FALSE;
    can_si_back = FALSE;
    can_cindent = FALSE;
}

static void ins_del (void) {
    int temp;
    if (stop_arrow () == FAIL)
        return;
    if (gchar_cursor () == NUL) {
        temp = curwin->w_cursor.col;
        if (!can_bs (BS_EOL) || do_join (2, FALSE, TRUE, FALSE, FALSE) == FAIL)
            vim_beep (BO_BS);
        else
            curwin->w_cursor.col = temp;
    }
    else if (del_char (FALSE) == FAIL)
        vim_beep (BO_BS);
    did_ai = FALSE;
    did_si = FALSE;
    can_si = FALSE;
    can_si_back = FALSE;
    AppendCharToRedobuff (K_DEL);
}

static int ins_bs (int c, int mode, int *inserted_space_p) {
    linenr_T lnum;
    int cc;
    int temp = 0;
    colnr_T save_col;
    colnr_T mincol;
    int did_backspace = FALSE;
    int in_indent;
    int oldState;
    if (BUFEMPTY () || (!revins_on && ((curwin->w_cursor.lnum == 1 && curwin->w_cursor.col == 0) || (!can_bs (BS_START) && (arrow_used || (curwin->w_cursor.lnum == Insstart_orig.lnum && curwin->w_cursor.col <= Insstart_orig.col))) || (!can_bs (BS_INDENT) && !arrow_used && ai_col > 0 && curwin->w_cursor.col <= ai_col) || (!can_bs (BS_EOL) && curwin->w_cursor.col == 0)))) {
        vim_beep (BO_BS);
        return FALSE;
    }
    if (stop_arrow () == FAIL)
        return FALSE;
    in_indent = inindent (0);
    if (in_indent)
        can_cindent = FALSE;
    end_comment_pending = NUL;
    if (revins_on)
        inc_cursor ();
    if (curwin->w_cursor.coladd > 0) {
        if (mode == BACKSPACE_CHAR) {
            --curwin->w_cursor.coladd;
            return TRUE;
        }
        if (mode == BACKSPACE_WORD) {
            curwin->w_cursor.coladd = 0;
            return TRUE;
        }
        curwin->w_cursor.coladd = 0;
    }
    if (curwin->w_cursor.col == 0) {
        lnum = Insstart.lnum;
        if (curwin->w_cursor.lnum == lnum || revins_on) {
            if (u_save ((linenr_T) (curwin->w_cursor.lnum - 2), (linenr_T) (curwin->w_cursor.lnum + 1)) == FAIL)
                return FALSE;
            --Insstart.lnum;
            Insstart.col = (colnr_T) STRLEN (ml_get (Insstart.lnum));
        }
        cc = -1;
        if (State & REPLACE_FLAG)
            cc = replace_pop ();
        if ((State & REPLACE_FLAG) && curwin->w_cursor.lnum <= lnum) {
            dec_cursor ();
        }
        else {
            if (!(State & VREPLACE_FLAG) || curwin->w_cursor.lnum > orig_line_count) {
                temp = gchar_cursor ();
                --curwin->w_cursor.lnum;
                if (has_format_option (FO_AUTO) && has_format_option (FO_WHITE_PAR)) {
                    char_u *ptr = ml_get_buf (curbuf, curwin->w_cursor.lnum, TRUE);
                    int len;
                    len = (int) STRLEN (ptr);
                    if (len > 0 && ptr[len - 1] == ' ')
                        ptr[len - 1] = NUL;
                }
                (void) do_join (2, FALSE, FALSE, FALSE, FALSE);
                if (temp == NUL && gchar_cursor () != NUL)
                    inc_cursor ();
            }
            else
                dec_cursor ();
            if (State & REPLACE_FLAG) {
                oldState = State;
                State = NORMAL;
                while (cc > 0) {
                    save_col = curwin->w_cursor.col;
                    ins_char (cc);
                    curwin->w_cursor.col = save_col;
                    cc = replace_pop ();
                }
                replace_pop_ins ();
                State = oldState;
            }
        }
        did_ai = FALSE;
    }
    else {
        if (revins_on)
            dec_cursor ();
        mincol = 0;
        if (mode == BACKSPACE_LINE && (curbuf->b_p_ai || cindent_on ()) && !revins_on) {
            save_col = curwin->w_cursor.col;
            beginline (BL_WHITE);
            if (curwin->w_cursor.col < save_col)
                mincol = curwin->w_cursor.col;
            curwin->w_cursor.col = save_col;
        }
        if (mode == BACKSPACE_CHAR && ((p_sta && in_indent) || (get_sts_value () != 0 && curwin->w_cursor.col > 0 && (*(ml_get_cursor () - 1) == TAB || (*(ml_get_cursor () - 1) == ' ' && (!*inserted_space_p || arrow_used)))))) {
            int ts;
            colnr_T vcol;
            colnr_T want_vcol;
            colnr_T start_vcol;
            *inserted_space_p = FALSE;
            if (p_sta && in_indent)
                ts = (int) get_sw_value (curbuf);
            else
                ts = (int) get_sts_value ();
            getvcol (curwin, & curwin -> w_cursor, & vcol, NULL, NULL);
            start_vcol = vcol;
            dec_cursor ();
            getvcol (curwin, & curwin -> w_cursor, NULL, NULL, & want_vcol);
            inc_cursor ();
            want_vcol = (want_vcol / ts) * ts;
            while (vcol > want_vcol && (cc = *(ml_get_cursor () - 1), VIM_ISWHITE (cc)))
                ins_bs_one (&vcol);
            while (vcol < want_vcol) {
                if (curwin->w_cursor.lnum == Insstart_orig.lnum && curwin->w_cursor.col < Insstart_orig.col)
                    Insstart_orig.col = curwin->w_cursor.col;
                if (State & VREPLACE_FLAG)
                    ins_char (' ');
                else {
                    ins_str ((char_u *) " ");
                    if ((State & REPLACE_FLAG))
                        replace_push (NUL);
                }
                getvcol (curwin, & curwin -> w_cursor, & vcol, NULL, NULL);
            }
            if (vcol >= start_vcol)
                ins_bs_one (&vcol);
        }
        else {
            do {
                if (!revins_on)
                    dec_cursor ();
                cc = gchar_cursor ();
                if (mode == BACKSPACE_WORD && !vim_isspace (cc)) {
                    mode = BACKSPACE_WORD_NOT_SPACE;
                    temp = vim_iswordc (cc);
                }
                else if (mode == BACKSPACE_WORD_NOT_SPACE && ((vim_isspace (cc) || vim_iswordc (cc) != temp))) {
                    if (!revins_on)
                        inc_cursor ();
                    else if (State & REPLACE_FLAG)
                        dec_cursor ();
                    break;
                }
                if (State & REPLACE_FLAG)
                    replace_do_bs (-1);
                else {
                    (void) del_char (FALSE);
                    if (revins_chars) {
                        revins_chars--;
                        revins_legal++;
                    }
                    if (revins_on && gchar_cursor () == NUL)
                        break;
                }
                if (mode == BACKSPACE_CHAR)
                    break;
            }
            while (revins_on || (curwin->w_cursor.col > mincol && (curwin->w_cursor.lnum != Insstart_orig.lnum || curwin->w_cursor.col != Insstart_orig.col)));
        }
        did_backspace = TRUE;
    }
    did_si = FALSE;
    can_si = FALSE;
    can_si_back = FALSE;
    if (curwin->w_cursor.col <= 1)
        did_ai = FALSE;
    AppendCharToRedobuff (c);
    if (curwin->w_cursor.lnum == Insstart_orig.lnum && curwin->w_cursor.col < Insstart_orig.col)
        Insstart_orig.col = curwin->w_cursor.col;
    if (vim_strchr (p_cpo, CPO_BACKSPACE) != NULL && dollar_vcol == -1)
        dollar_vcol = curwin->w_virtcol;
    if (did_backspace)
        foldOpenCursor ();
    return did_backspace;
}

static void ins_bs_one (colnr_T *vcolp) {
    dec_cursor ();
    getvcol (curwin, & curwin -> w_cursor, vcolp, NULL, NULL);
    if (State & REPLACE_FLAG) {
        if (curwin->w_cursor.lnum != Insstart.lnum || curwin->w_cursor.col >= Insstart.col)
            replace_do_bs (-1);
    }
    else
        (void) del_char (FALSE);
}

static void ins_mouse (int c) {
    pos_T tpos;
    win_T *old_curwin = curwin;
    if (!gui.in_use)
        if (!mouse_has (MOUSE_INSERT))
            return;
    undisplay_dollar ();
    tpos = curwin->w_cursor;
    if (do_mouse (NULL, c, BACKWARD, 1L, 0)) {
        win_T *new_curwin = curwin;
        if (curwin != old_curwin && win_valid (old_curwin)) {
            curwin = old_curwin;
            curbuf = curwin->w_buffer;
        }
        start_arrow (curwin == old_curwin ? & tpos : NULL);
        if (curwin != new_curwin && win_valid (new_curwin)) {
            curwin = new_curwin;
            curbuf = curwin->w_buffer;
        }
        can_cindent = TRUE;
    }
    redraw_statuslines ();
}

static void ins_mousescroll (int dir) {
    pos_T tpos;
    win_T *old_curwin = curwin, *wp;
    int did_scroll = FALSE;
    tpos = curwin->w_cursor;
    if (mouse_row >= 0 && mouse_col >= 0) {
        int row, col;
        row = mouse_row;
        col = mouse_col;
        wp = mouse_find_win (&row, &col);
        if (wp == NULL)
            return;
        curwin = wp;
        curbuf = curwin->w_buffer;
    }
    if (curwin == old_curwin)
        undisplay_dollar ();
    if (!pum_visible () || curwin != old_curwin) {
        if (dir == MSCR_DOWN || dir == MSCR_UP) {
            if (mod_mask & (MOD_MASK_SHIFT | MOD_MASK_CTRL))
                scroll_redraw (dir, (long ) (curwin->w_botline - curwin->w_topline));
            else
                scroll_redraw (dir, 3L);
        }
        else {
            int val, step = 6;
            if (mod_mask & (MOD_MASK_SHIFT | MOD_MASK_CTRL))
                step = curwin->w_width;
            val = curwin->w_leftcol + (dir == MSCR_RIGHT ? -step : step);
            if (val < 0)
                val = 0;
            gui_do_horiz_scroll (val, TRUE);
        }
        did_scroll = TRUE;
    }
    curwin->w_redr_status = TRUE;
    curwin = old_curwin;
    curbuf = curwin->w_buffer;
    if (pum_visible () && did_scroll) {
        redraw_all_later (NOT_VALID);
        ins_compl_show_pum ();
    }
    if (!EQUAL_POS (curwin->w_cursor, tpos)) {
        start_arrow (& tpos);
        can_cindent = TRUE;
    }
}

void ins_scroll (void) {
    pos_T tpos;
    undisplay_dollar ();
    tpos = curwin->w_cursor;
    if (gui_do_scroll ()) {
        start_arrow (& tpos);
        can_cindent = TRUE;
    }
}

void ins_horscroll (void) {
    pos_T tpos;
    undisplay_dollar ();
    tpos = curwin->w_cursor;
    if (gui_do_horiz_scroll (scrollbar_value, FALSE)) {
        start_arrow (& tpos);
        can_cindent = TRUE;
    }
}

static void ins_home (int c) {
    pos_T tpos;
    if ((fdo_flags & FDO_HOR) && KeyTyped)
        foldOpenCursor ();
    undisplay_dollar ();
    tpos = curwin->w_cursor;
    if (c == K_C_HOME)
        curwin->w_cursor.lnum = 1;
    curwin->w_cursor.col = 0;
    curwin->w_cursor.coladd = 0;
    curwin->w_curswant = 0;
    start_arrow (& tpos);
}

static void ins_end (int c) {
    pos_T tpos;
    if ((fdo_flags & FDO_HOR) && KeyTyped)
        foldOpenCursor ();
    undisplay_dollar ();
    tpos = curwin->w_cursor;
    if (c == K_C_END)
        curwin->w_cursor.lnum = curbuf->b_ml.ml_line_count;
    coladvance ((colnr_T) MAXCOL);
    curwin->w_curswant = MAXCOL;
    start_arrow (& tpos);
}

static void ins_s_left (void) {
    if ((fdo_flags & FDO_HOR) && KeyTyped)
        foldOpenCursor ();
    undisplay_dollar ();
    if (curwin->w_cursor.lnum > 1 || curwin->w_cursor.col > 0) {
        start_arrow (& curwin -> w_cursor);
        (void) bck_word (1L, FALSE, FALSE);
        curwin->w_set_curswant = TRUE;
    }
    else
        vim_beep (BO_CRSR);
}

static void ins_left (int end_change) {
    pos_T tpos;
    if ((fdo_flags & FDO_HOR) && KeyTyped)
        foldOpenCursor ();
    undisplay_dollar ();
    tpos = curwin->w_cursor;
    if (oneleft () == OK) {
        {
            start_arrow_with_change (& tpos, end_change);
            if (!end_change)
                AppendCharToRedobuff (K_LEFT);
        }
        if (revins_scol != -1 && (int) curwin->w_cursor.col >= revins_scol)
            revins_legal++;
        revins_chars++;
    }
    else if (vim_strchr (p_ww, '[') != NULL && curwin->w_cursor.lnum > 1) {
        start_arrow (& tpos);
        --(curwin->w_cursor.lnum);
        coladvance ((colnr_T) MAXCOL);
        curwin->w_set_curswant = TRUE;
    }
    else
        vim_beep (BO_CRSR);
    dont_sync_undo = FALSE;
}

static void ins_s_right (void) {
    if ((fdo_flags & FDO_HOR) && KeyTyped)
        foldOpenCursor ();
    undisplay_dollar ();
    if (curwin->w_cursor.lnum < curbuf->b_ml.ml_line_count || gchar_cursor () != NUL) {
        start_arrow (& curwin -> w_cursor);
        (void) fwd_word (1L, FALSE, 0);
        curwin->w_set_curswant = TRUE;
    }
    else
        vim_beep (BO_CRSR);
}

static void ins_right (int end_change) {
    if ((fdo_flags & FDO_HOR) && KeyTyped)
        foldOpenCursor ();
    undisplay_dollar ();
    if (gchar_cursor () != NUL || virtual_active ()) {
        start_arrow_with_change (& curwin -> w_cursor, end_change);
        if (!end_change)
            AppendCharToRedobuff (K_RIGHT);
        curwin->w_set_curswant = TRUE;
        if (virtual_active ())
            oneright ();
        else {
            ++curwin->w_cursor.col;
        }
        revins_legal++;
        if (revins_chars)
            revins_chars--;
    }
    else if (vim_strchr (p_ww, ']') != NULL && curwin->w_cursor.lnum < curbuf->b_ml.ml_line_count) {
        start_arrow (& curwin -> w_cursor);
        curwin->w_set_curswant = TRUE;
        ++curwin->w_cursor.lnum;
        curwin->w_cursor.col = 0;
    }
    else
        vim_beep (BO_CRSR);
    dont_sync_undo = FALSE;
}

int oneright (void) {
    char_u *ptr;
    int l;
    if (virtual_active ()) {
        pos_T prevpos = curwin->w_cursor;
        ptr = ml_get_cursor ();
        coladvance (getviscol () + ((* ptr != TAB && vim_isprintc (* ptr)) ? ptr2cells (ptr) : 1));
        curwin->w_set_curswant = TRUE;
        return (prevpos.col != curwin->w_cursor.col || prevpos.coladd != curwin->w_cursor.coladd) ? OK : FAIL;
    }
    ptr = ml_get_cursor ();
    if (*ptr == NUL)
        return FAIL;
    l = 1;
    if (ptr[l] == NUL && (ve_flags & VE_ONEMORE) == 0)
        return FAIL;
    curwin->w_cursor.col += l;
    curwin->w_set_curswant = TRUE;
    return OK;
}

static void ins_pageup (void) {
    pos_T tpos;
    undisplay_dollar ();
    if (mod_mask & MOD_MASK_CTRL) {
        if (first_tabpage->tp_next != NULL) {
            start_arrow (& curwin -> w_cursor);
            goto_tabpage (- 1);
        }
        return;
    }
    tpos = curwin->w_cursor;
    if (onepage (BACKWARD, 1L) == OK) {
        start_arrow (& tpos);
        can_cindent = TRUE;
    }
    else
        vim_beep (BO_CRSR);
}

static void ins_pagedown (void) {
    pos_T tpos;
    undisplay_dollar ();
    if (mod_mask & MOD_MASK_CTRL) {
        if (first_tabpage->tp_next != NULL) {
            start_arrow (& curwin -> w_cursor);
            goto_tabpage (0);
        }
        return;
    }
    tpos = curwin->w_cursor;
    if (onepage (FORWARD, 1L) == OK) {
        start_arrow (& tpos);
        can_cindent = TRUE;
    }
    else
        vim_beep (BO_CRSR);
}

static int ins_tab (void) {
    int ind;
    int i;
    int temp;
    if (Insstart_blank_vcol == MAXCOL && curwin->w_cursor.lnum == Insstart.lnum)
        Insstart_blank_vcol = get_nolist_virtcol ();
    if (echeck_abbr (TAB +ABBR_OFF))
        return FALSE;
    ind = inindent (0);
    if (ind)
        can_cindent = FALSE;
    if (!curbuf->b_p_et && !(p_sta && ind && curbuf->b_p_ts != get_sw_value (curbuf)) && get_sts_value () == 0)
        return TRUE;
    if (stop_arrow () == FAIL)
        return TRUE;
    did_ai = FALSE;
    did_si = FALSE;
    can_si = FALSE;
    can_si_back = FALSE;
    AppendToRedobuff ((char_u *) "\t");
    if (p_sta && ind)
        temp = (int) get_sw_value (curbuf);
    else if (curbuf->b_p_sts != 0)
        temp = (int) get_sts_value ();
    else
        temp = (int) curbuf->b_p_ts;
    temp -= get_nolist_virtcol () % temp;
    ins_char (' ');
    while (--temp > 0) {
        if (State & VREPLACE_FLAG)
            ins_char (' ');
        else {
            ins_str ((char_u *) " ");
            if (State & REPLACE_FLAG)
                replace_push (NUL);
        }
    }
    if (!curbuf->b_p_et && (get_sts_value () || (p_sta && ind))) {
        char_u *ptr;
        char_u *saved_line = NULL;
        pos_T pos;
        pos_T fpos;
        pos_T *cursor;
        colnr_T want_vcol, vcol;
        int change_col = -1;
        int save_list = curwin->w_p_list;
        if (State & VREPLACE_FLAG) {
            pos = curwin->w_cursor;
            cursor = &pos;
            saved_line = vim_strsave (ml_get_curline ());
            if (saved_line == NULL)
                return FALSE;
            ptr = saved_line + pos.col;
        }
        else {
            ptr = ml_get_cursor ();
            cursor = &curwin->w_cursor;
        }
        if (vim_strchr (p_cpo, CPO_LISTWM) == NULL)
            curwin->w_p_list = FALSE;
        fpos = curwin->w_cursor;
        while (fpos.col > 0 && VIM_ISWHITE (ptr[-1])) {
            --fpos.col;
            --ptr;
        }
        if ((State & REPLACE_FLAG) && fpos.lnum == Insstart.lnum && fpos.col < Insstart.col) {
            ptr += Insstart.col - fpos.col;
            fpos.col = Insstart.col;
        }
        getvcol (curwin, & fpos, & vcol, NULL, NULL);
        getvcol (curwin, cursor, & want_vcol, NULL, NULL);
        while (VIM_ISWHITE (*ptr)) {
            i = lbr_chartabsize (NULL, (char_u *) "\t", vcol);
            if (vcol + i > want_vcol)
                break;
            if (*ptr != TAB) {
                *ptr = TAB;
                if (change_col < 0) {
                    change_col = fpos.col;
                    if (fpos.lnum == Insstart.lnum && fpos.col < Insstart.col)
                        Insstart.col = fpos.col;
                }
            }
            ++fpos.col;
            ++ptr;
            vcol += i;
        }
        if (change_col >= 0) {
            int repl_off = 0;
            char_u *line = ptr;
            while (vcol < want_vcol && *ptr == ' ') {
                vcol += lbr_chartabsize (line, ptr, vcol);
                ++ptr;
                ++repl_off;
            }
            if (vcol > want_vcol) {
                --ptr;
                --repl_off;
            }
            fpos.col += repl_off;
            i = cursor->col - fpos.col;
            if (i > 0) {
                STRMOVE (ptr, ptr + i);
                if ((State & REPLACE_FLAG) && !(State & VREPLACE_FLAG))
                    for (temp = i; --temp >= 0;)
                        replace_join (repl_off);
            }
            if (netbeans_active ()) {
                netbeans_removed (curbuf, fpos.lnum, cursor -> col, (long) (i + 1));
                netbeans_inserted (curbuf, fpos.lnum, cursor -> col, (char_u *) "\t", 1);
            }
            cursor->col -= i;
            if (State & VREPLACE_FLAG) {
                backspace_until_column (change_col);
                ins_bytes_len (saved_line + change_col, cursor -> col - change_col);
            }
        }
        if (State & VREPLACE_FLAG)
            vim_free (saved_line);
        curwin->w_p_list = save_list;
    }
    return FALSE;
}

static int ins_eol (int c) {
    int i;
    if (echeck_abbr (c +ABBR_OFF))
        return FALSE;
    if (stop_arrow () == FAIL)
        return TRUE;
    undisplay_dollar ();
    if ((State & REPLACE_FLAG) && !(State & VREPLACE_FLAG))
        replace_push (NUL);
    if (virtual_active () && curwin->w_cursor.coladd > 0)
        coladvance (getviscol ());
    if (p_altkeymap && p_fkmap)
        fkmap (NL);
    if (revins_on)
        curwin->w_cursor.col += (colnr_T) STRLEN (ml_get_cursor ());
    AppendToRedobuff (NL_STR);
    i = open_line (FORWARD, has_format_option (FO_RET_COMS) ? OPENLINE_DO_COM : 0, old_indent);
    old_indent = 0;
    can_cindent = TRUE;
    foldOpenCursor ();
    return (!i);
}

static int ins_digraph (void) {
    int c;
    int cc;
    int did_putchar = FALSE;
    pc_status = PC_STATUS_UNSET;
    if (redrawing () && !char_avail ()) {
        ins_redraw (FALSE);
        edit_putchar ('?', TRUE);
        did_putchar = TRUE;
        add_to_showcmd_c (Ctrl_K);
    }
    ++no_mapping;
    ++allow_keys;
    c = plain_vgetc ();
    --no_mapping;
    --allow_keys;
    if (did_putchar)
        edit_unputchar ();
    if (IS_SPECIAL (c) || mod_mask) {
        clear_showcmd ();
        insert_special (c, TRUE, FALSE);
        return NUL;
    }
    if (c != ESC) {
        did_putchar = FALSE;
        if (redrawing () && !char_avail ()) {
            ins_redraw (FALSE);
            if (char2cells (c) == 1) {
                ins_redraw (FALSE);
                edit_putchar (c, TRUE);
                did_putchar = TRUE;
            }
            add_to_showcmd_c (c);
        }
        ++no_mapping;
        ++allow_keys;
        cc = plain_vgetc ();
        --no_mapping;
        --allow_keys;
        if (did_putchar)
            edit_unputchar ();
        if (cc != ESC) {
            AppendToRedobuff ((char_u *) CTRL_V_STR);
            c = getdigraph (c, cc, TRUE);
            clear_showcmd ();
            return c;
        }
    }
    clear_showcmd ();
    return NUL;
}

static int ins_ctrl_ey (int tc) {
    int c = tc;
    if (ctrl_x_mode == CTRL_X_SCROLL) {
        if (c == Ctrl_Y)
            scrolldown_clamp ();
        else
            scrollup_clamp ();
        redraw_later (VALID);
    }
    else {
        c = ins_copychar (curwin->w_cursor.lnum + (c == Ctrl_Y ? -1 : 1));
        if (c != NUL) {
            long  tw_save;
            if (c < 256 && !isalnum (c))
                AppendToRedobuff ((char_u *) CTRL_V_STR);
            tw_save = curbuf->b_p_tw;
            curbuf->b_p_tw = -1;
            insert_special (c, TRUE, FALSE);
            curbuf->b_p_tw = tw_save;
            revins_chars++;
            revins_legal++;
            c = Ctrl_V;
            auto_format (FALSE, TRUE);
        }
    }
    return c;
}

int ins_copychar (linenr_T lnum) {
    int c;
    int temp;
    char_u *ptr, *prev_ptr;
    char_u *line;
    if (lnum < 1 || lnum > curbuf->b_ml.ml_line_count) {
        vim_beep (BO_COPY);
        return NUL;
    }
    temp = 0;
    line = ptr = ml_get (lnum);
    prev_ptr = ptr;
    validate_virtcol ();
    while ((colnr_T) temp < curwin->w_virtcol && *ptr != NUL) {
        prev_ptr = ptr;
        temp += lbr_chartabsize_adv (line, &ptr, (colnr_T) temp);
    }
    if ((colnr_T) temp > curwin->w_virtcol)
        ptr = prev_ptr;
    c = *ptr;
    if (c == NUL)
        vim_beep (BO_COPY);
    return c;
}

static char_u *do_insert_char_pre (int c) {
    char_u *res;
    char_u buf [MB_MAXBYTES + 1];
    if (!has_insertcharpre ())
        return NULL;
    {
        buf[0] = c;
        buf[1] = NUL;
    }
    ++textlock;
    set_vim_var_string (VV_CHAR, buf, - 1);
    res = NULL;
    if (apply_autocmds (EVENT_INSERTCHARPRE, NULL, NULL, FALSE, curbuf)) {
        if (STRCMP (buf, get_vim_var_str (VV_CHAR)) != 0)
            res = vim_strsave (get_vim_var_str (VV_CHAR));
    }
    set_vim_var_string (VV_CHAR, NULL, - 1);
    --textlock;
    return res;
}

static void ins_try_si (int c) {
    pos_T *pos, old_pos;
    char_u *ptr;
    int i;
    int temp;
    if (((did_si || can_si_back) && c == '{') || (can_si && c == '}')) {
        if (c == '}' && (pos = findmatch (NULL, '{')) != NULL) {
            old_pos = curwin->w_cursor;
            ptr = ml_get (pos->lnum);
            i = pos->col;
            if (i > 0)
                while (--i > 0 && VIM_ISWHITE (ptr[i]))
                    ;
            curwin->w_cursor.lnum = pos->lnum;
            curwin->w_cursor.col = i;
            if (ptr[i] == ')' && (pos = findmatch (NULL, '(')) != NULL)
                curwin->w_cursor = *pos;
            i = get_indent ();
            curwin->w_cursor = old_pos;
            if (State & VREPLACE_FLAG)
                change_indent (INDENT_SET, i, FALSE, NUL, TRUE);
            else
                (void) set_indent (i, SIN_CHANGED);
        }
        else if (curwin->w_cursor.col > 0) {
            temp = TRUE;
            if (c == '{' && can_si_back && curwin->w_cursor.lnum > 1) {
                old_pos = curwin->w_cursor;
                i = get_indent ();
                while (curwin->w_cursor.lnum > 1) {
                    ptr = skipwhite (ml_get (--(curwin->w_cursor.lnum)));
                    if (*ptr != '#' && *ptr != NUL)
                        break;
                }
                if (get_indent () >= i)
                    temp = FALSE;
                curwin->w_cursor = old_pos;
            }
            if (temp)
                shift_line (TRUE, FALSE, 1, TRUE);
        }
    }
    if (curwin->w_cursor.col > 0 && can_si && c == '#') {
        old_indent = get_indent ();
        (void) set_indent (0, SIN_CHANGED);
    }
    if (ai_col > curwin->w_cursor.col)
        ai_col = curwin->w_cursor.col;
}

void display_dollar (colnr_T col) {
    colnr_T save_col;
    if (!redrawing ())
        return;
    cursor_off ();
    save_col = curwin->w_cursor.col;
    curwin->w_cursor.col = col;
    curs_columns (FALSE);
    if (curwin->w_wcol < curwin->w_width) {
        edit_putchar ('$', FALSE);
        dollar_vcol = curwin->w_virtcol;
    }
    curwin->w_cursor.col = save_col;
}

void fix_indent (void) {
    if (p_paste)
        return;
    if (curbuf->b_p_lisp && curbuf->b_p_ai)
        fixthisline (get_lisp_indent);
    else if (cindent_on ())
        do_c_expr_indent ();
}

