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
struct eslist_elem {
    int saved_emsg_silent;
    eslist_T *next;
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
struct filemark {
    pos_T mark;
    int fnum;
};
struct spelltab_S {
    char_u st_isw [256];
    char_u st_isu [256];
    char_u st_fold [256];
    char_u st_upper [256];
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
struct argentry {
    char_u *ae_fname;
    int ae_fnum;
};
struct arglist {
    garray_T al_ga;
    int al_refcount;
    int id;
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
struct nv_cmd {
    int cmd_char;
    nv_func_T cmd_func;
    short_u cmd_flags;
    short  cmd_arg;
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
EXTERN int arrow_used;
EXTERN char_u *globaldir INIT (= NULL);
EXTERN char_u e_listreq [] INIT (= N_ ("E714: List required"));
EXTERN alist_T global_alist;
EXTERN char_u e_readonlyvar [] INIT (= N_ ("E46: Cannot change read-only variable \"%s\""));
EXTERN char_u e_noroom [] INIT (= N_ ("E36: Not enough room"));
EXTERN char_u e_umark [] INIT (= N_ ("E78: Unknown mark"));
EXTERN char_u e_marknotset [] INIT (= N_ ("E20: Mark not set"));
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
EXTERN char_u *p_titlestring;
EXTERN char_u *p_guifont;
EXTERN int *eval_lavars_used INIT (= NULL);
EXTERN char_u e_invalpat [] INIT (= N_ ("E682: Invalid search pattern or delimiter"));
EXTERN char_u e_toocompl [] INIT (= N_ ("E74: Command too complex"));
EXTERN char_u e_tagstack [] INIT (= N_ ("E73: tag stack empty"));
EXTERN char_u e_swapclose [] INIT (= N_ ("E72: Close error on swap file"));
EXTERN char_u e_scroll [] INIT (= N_ ("E49: Invalid scroll size"));
EXTERN char_u e_screenmode [] INIT (= N_ ("E359: Screen mode setting not supported"));
EXTERN char_u e_dictkey [] INIT (= N_ ("E716: Key not present in Dictionary: %s"));
EXTERN char_u e_dictreq [] INIT (= N_ ("E715: Dictionary required"));
EXTERN char_u e_re_corr [] INIT (= N_ ("E44: Corrupted regexp program"));
EXTERN char_u e_loclist [] INIT (= N_ ("E776: No location list"));
EXTERN char_u e_quickfix [] INIT (= N_ ("E42: No Errors"));
EXTERN char_u e_outofmem [] INIT (= N_ ("E41: Out of memory!"));
EXTERN char_u e_notcreate [] INIT (= N_ ("E482: Can't create file %s"));
EXTERN char_u e_markinval [] INIT (= N_ ("E19: Mark has invalid line number"));
EXTERN char_u e_backslash [] INIT (= N_ ("E10: \\ should be followed by /, ? or &"));
EXTERN char_u langmap_mapchar [256];
EXTERN char_u *escape_chars INIT (= (char_u *) " \t\\\"|");
EXTERN FILE *scriptout INIT (= NULL);
EXTERN FILE *scriptin [NSCRIPT];
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
EXTERN char_u *p_tc;
EXTERN int p_scs;
EXTERN char_u *p_shcf;
EXTERN char_u *p_sections;
EXTERN char_u *p_cdpath;
EXTERN char_u *p_cc;
EXTERN char_u *p_scl;
EXTERN int p_magic;
EXTERN int p_macthinstrokes;
EXTERN int p_macligatures;
EXTERN char_u *p_lcs;
EXTERN long  p_linespace;
EXTERN int p_ic;
EXTERN char_u *p_iconstring;
EXTERN char_u *p_penc;
EXTERN int p_fullscreen;
EXTERN char_u *p_fcl;
EXTERN long  p_fic;
EXTERN int p_exrc;
EXTERN char_u *p_dict;
EXTERN char_u *p_inc;
EXTERN char_u *p_cot;
EXTERN int p_cp;
EXTERN long  p_ch;
EXTERN int p_beval;
EXTERN char_u *p_cm;
EXTERN char_u *p_bkc;
EXTERN int p_acd;
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
EXTERN int current_scrollbar;
EXTERN vimmenu_T *current_menu;
EXTERN except_T *current_exception;
EXTERN int p_secure;
EXTERN char_u e_bufloaded [] INIT (= N_ ("E139: File is loaded in another buffer"));
EXTERN char_u e_nobufnr [] INIT (= N_ ("E86: Buffer %ld does not exist"));
EXTERN char_u e_notmp [] INIT (= N_ ("E483: Can't get temp file name"));
EXTERN pos_T last_cursormoved;
EXTERN char_u *IObuff;
EXTERN buf_T *lastbuf INIT (= NULL);
EXTERN buf_T *firstbuf INIT (= NULL);
EXTERN int p_stmp;
EXTERN int p_lrm;
EXTERN int p_confirm;
EXTERN char_u e_positive [] INIT (= N_ ("E487: Argument must be positive"));
EXTERN hlf_T edit_submode_highl;
EXTERN int highlight_attr [HLF_COUNT];
EXTERN int p_hls;
EXTERN char_u *p_hl;
EXTERN char_u *p_hlg;
EXTERN char_u e_nolastcmd [] INIT (= N_ ("E30: No previous command line"));
EXTERN char_u e_invcmd [] INIT (= N_ ("E476: Invalid command"));
EXTERN char_u wim_flags [4];
EXTERN char breakat_flags [256];
EXTERN int autocmd_fname_full;
EXTERN char_u *autocmd_fname INIT (= NULL);
EXTERN char_u *last_cmdline INIT (= NULL);
EXTERN cmdmod_T cmdmod;
EXTERN win_T *aucmd_win;
EXTERN int cmdline_row;
EXTERN unsigned  vop_flags;
EXTERN unsigned  ttym_flags;
EXTERN unsigned  tbis_flags;
EXTERN unsigned  toolbar_flags;
EXTERN unsigned  tc_flags;
EXTERN unsigned  ssop_flags;
EXTERN unsigned  fuoptions_flags;
EXTERN unsigned  fdo_flags;
EXTERN unsigned  dy_flags;
EXTERN unsigned  bo_flags;
EXTERN unsigned  bkc_flags;
const unsigned  char cmdidxs2 [26] [26] = {{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 6, 0, 0, 0, 7, 15, 0, 16, 0, 0, 0, 0, 0}, {2, 0, 0, 4, 5, 7, 0, 0, 0, 0, 0, 8, 9, 10, 11, 12, 0, 13, 0, 0, 0, 0, 22, 0, 0, 0}, {3, 10, 12, 14, 16, 18, 21, 0, 0, 0, 0, 29, 33, 36, 42, 51, 53, 54, 55, 0, 57, 0, 60, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 6, 15, 0, 16, 0, 0, 17, 0, 0, 19, 20, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 7, 9, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 4, 5, 0, 0, 0, 0}, {5, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 3, 0, 0, 0, 4, 0, 5, 6, 0, 0, 0, 0, 0, 13, 0, 15, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {3, 9, 11, 15, 16, 20, 23, 28, 0, 0, 0, 30, 33, 36, 40, 46, 0, 48, 57, 49, 50, 54, 56, 0, 0, 0}, {1, 0, 0, 0, 9, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 8, 10, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 5, 0, 0, 0, 0, 0, 0, 9, 0, 11, 0, 0, 0}, {1, 0, 3, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 9, 0, 0, 16, 17, 26, 0, 27, 0, 28, 0}, {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 18, 0, 0, 0, 0}, {2, 6, 15, 0, 18, 22, 0, 24, 25, 0, 0, 28, 30, 34, 38, 40, 0, 48, 0, 49, 0, 61, 62, 0, 63, 0}, {2, 0, 19, 0, 22, 24, 0, 25, 0, 26, 0, 27, 28, 31, 33, 34, 0, 35, 37, 0, 38, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 9, 12, 0, 0, 0, 0, 15, 0, 16, 0, 0, 0, 0, 0}, {2, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 0, 8, 0, 9, 10, 0, 12, 0, 13, 14, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
const unsigned  short  cmdidxs1 [26] = {0, 19, 42, 103, 125, 145, 161, 167, 176, 194, 196, 201, 259, 279, 299, 311, 350, 353, 372, 439, 479, 490, 508, 523, 532, 533};
EXTERN char_u e_invalidreg [] INIT (= N_ ("E850: Invalid register name"));
EXTERN char_u e_usingsid [] INIT (= N_ ("E81: Using <SID> not in a script context"));
EXTERN char_u e_listidx [] INIT (= N_ ("E684: list index out of range: %ld"));
EXTERN int ru_wid;
EXTERN int p_tbidi;
EXTERN int p_hid;
const int command_count = 546;
EXTERN char_u e_zerocount [] INIT (= N_ ("E939: Positive count required"));
EXTERN char_u e_nomatch2 [] INIT (= N_ ("E480: No match: %s"));
EXTERN char_u e_nomatch [] INIT (= N_ ("E479: No match"));
EXTERN char_u *autocmd_match INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_out INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_in INIT (= NULL);
EXTERN linenr_T search_match_lines;
EXTERN char_u e_maxmempat [] INIT (= N_ ("E363: pattern uses more memory than 'maxmempattern'"));
EXTERN char_u e_winwidth [] INIT (= N_ ("E592: 'winwidth' cannot be smaller than 'winminwidth'"));
EXTERN char_u e_winheight [] INIT (= N_ ("E591: 'winheight' cannot be smaller than 'winminheight'"));
EXTERN char_u e_notopen [] INIT (= N_ ("E484: Can't open file %s"));
EXTERN int stop_insert_mode;
EXTERN frame_T *topframe;
EXTERN int searchcmdlen;
EXTERN long  p_titlelen;
EXTERN char_u e_listdictarg [] INIT (= N_ ("E712: Argument of %s must be a List or Dictionary"));
EXTERN char_u e_toomanyarg [] INIT (= N_ ("E118: Too many arguments for function: %s"));
EXTERN char_u e_invargNval [] INIT (= N_ ("E475: Invalid value for argument %s: %s"));
EXTERN char_u e_invargval [] INIT (= N_ ("E475: Invalid value for argument %s"));
EXTERN char_u e_invarg2 [] INIT (= N_ ("E475: Invalid argument: %s"));
EXTERN char_u e_invarg [] INIT (= N_ ("E474: Invalid argument"));
EXTERN char_u e_argreq [] INIT (= N_ ("E471: Argument required"));
EXTERN char *font_argument INIT (= NULL);
EXTERN unsigned  swb_flags;
EXTERN time_T starttime;
EXTERN char_u e_shellempty [] INIT (= N_ ("E91: 'shell' option is empty"));
EXTERN char_u e_emptykey [] INIT (= N_ ("E713: Cannot use empty key for Dictionary"));
EXTERN char_u e_endfor [] INIT (= N_ ("E170: Missing :endfor"));
EXTERN char_u e_endwhile [] INIT (= N_ ("E170: Missing :endwhile"));
EXTERN char_u e_endtry [] INIT (= N_ ("E600: Missing :endtry"));
EXTERN char_u e_endif [] INIT (= N_ ("E171: Missing :endif"));
EXTERN win_T *au_pending_free_win INIT (= NULL);
EXTERN buf_T *au_pending_free_buf INIT (= NULL);
EXTERN int ru_col;
EXTERN colnr_T search_match_endcol;
EXTERN int p_cc_cols [256];
EXTERN long  p_columnspace;
EXTERN int fuoptions_bgcolor;
EXTERN char_u *p_opfunc;
char_u old_showcmd_buf [SHOWCMD_BUFLEN];
EXTERN proftime_T bevalexpr_due;
EXTERN long  p_bdlay;
EXTERN int p_bevalterm;
EXTERN pos_T where_paste_started;
EXTERN char_u *p_mousem;
EXTERN tabpage_T *first_tabpage;
EXTERN tabpage_T *curtab;
EXTERN short  *TabPageIdxs INIT (= NULL);
EXTERN int mouse_col;
EXTERN long  p_so;
EXTERN win_T *firstwin;
EXTERN int mouse_row;
EXTERN unsigned  ve_flags;
EXTERN char_u *p_slm;
int nv_max_linear;
short  nv_cmd_idx [NV_CMDS_SIZE];
EXTERN long  p_ttm;
EXTERN long  p_tm;
EXTERN int p_fkmap;
EXTERN int p_hkmap;
int restart_VIsual_select = 0;
EXTERN int p_smd;
EXTERN int KeyStuffed;
struct nv_cmd nv_cmds [] = {{NUL, nv_error, 0, 0}, {Ctrl_A, nv_addsub, 0, 0}, {Ctrl_B, nv_page, NV_STS, BACKWARD}, {Ctrl_C, nv_esc, 0, TRUE}, {Ctrl_D, nv_halfpage, 0, 0}, {Ctrl_E, nv_scroll_line, 0, TRUE}, {Ctrl_F, nv_page, NV_STS, FORWARD}, {Ctrl_G, nv_ctrlg, 0, 0}, {Ctrl_H, nv_ctrlh, 0, 0}, {Ctrl_I, nv_pcmark, 0, 0}, {NL, nv_down, 0, FALSE}, {Ctrl_K, nv_error, 0, 0}, {Ctrl_L, nv_clear, 0, 0}, {Ctrl_M, nv_down, 0, TRUE}, {Ctrl_N, nv_down, NV_STS, FALSE}, {Ctrl_O, nv_ctrlo, 0, 0}, {Ctrl_P, nv_up, NV_STS, FALSE}, {Ctrl_Q, nv_visual, 0, FALSE}, {Ctrl_R, nv_redo, 0, 0}, {Ctrl_S, nv_ignore, 0, 0}, {Ctrl_T, nv_tagpop, NV_NCW, 0}, {Ctrl_U, nv_halfpage, 0, 0}, {Ctrl_V, nv_visual, 0, FALSE}, {'V', nv_visual, 0, FALSE}, {'v', nv_visual, 0, FALSE}, {Ctrl_W, nv_window, 0, 0}, {Ctrl_X, nv_addsub, 0, 0}, {Ctrl_Y, nv_scroll_line, 0, FALSE}, {Ctrl_Z, nv_suspend, 0, 0}, {ESC, nv_esc, 0, FALSE}, {Ctrl_BSL, nv_normal, NV_NCH_ALW, 0}, {Ctrl_RSB, nv_ident, NV_NCW, 0}, {Ctrl_HAT, nv_hat, NV_NCW, 0}, {Ctrl__, nv_error, 0, 0}, {' ', nv_right, 0, 0}, {'!', nv_operator, 0, 0}, {'"', nv_regname, NV_NCH_NOP | NV_KEEPREG, 0}, {'#', nv_ident, 0, 0}, {'$', nv_dollar, 0, 0}, {'%', nv_percent, 0, 0}, {'&', nv_optrans, 0, 0}, {'\'', nv_gomark, NV_NCH_ALW, TRUE}, {'(', nv_brace, 0, BACKWARD}, {')', nv_brace, 0, FORWARD}, {'*', nv_ident, 0, 0}, {'+', nv_down, 0, TRUE}, {',', nv_csearch, 0, TRUE}, {'-', nv_up, 0, TRUE}, {'.', nv_dot, NV_KEEPREG, 0}, {'/', nv_search, 0, FALSE}, {'0', nv_beginline, 0, 0}, {'1', nv_ignore, 0, 0}, {'2', nv_ignore, 0, 0}, {'3', nv_ignore, 0, 0}, {'4', nv_ignore, 0, 0}, {'5', nv_ignore, 0, 0}, {'6', nv_ignore, 0, 0}, {'7', nv_ignore, 0, 0}, {'8', nv_ignore, 0, 0}, {'9', nv_ignore, 0, 0}, {':', nv_colon, 0, 0}, {';', nv_csearch, 0, FALSE}, {'<', nv_operator, NV_RL, 0}, {'=', nv_operator, 0, 0}, {'>', nv_operator, NV_RL, 0}, {'?', nv_search, 0, FALSE}, {'@', nv_at, NV_NCH_NOP, FALSE}, {'A', nv_edit, 0, 0}, {'B', nv_bck_word, 0, 1}, {'C', nv_abbrev, NV_KEEPREG, 0}, {'D', nv_abbrev, NV_KEEPREG, 0}, {'E', nv_wordcmd, 0, TRUE}, {'F', nv_csearch, NV_NCH_ALW | NV_LANG, BACKWARD}, {'G', nv_goto, 0, TRUE}, {'H', nv_scroll, 0, 0}, {'I', nv_edit, 0, 0}, {'J', nv_join, 0, 0}, {'K', nv_ident, 0, 0}, {'L', nv_scroll, 0, 0}, {'M', nv_scroll, 0, 0}, {'N', nv_next, 0, SEARCH_REV}, {'O', nv_open, 0, 0}, {'P', nv_put, 0, 0}, {'Q', nv_exmode, NV_NCW, 0}, {'R', nv_Replace, 0, FALSE}, {'S', nv_subst, NV_KEEPREG, 0}, {'T', nv_csearch, NV_NCH_ALW | NV_LANG, BACKWARD}, {'U', nv_Undo, 0, 0}, {'W', nv_wordcmd, 0, TRUE}, {'X', nv_abbrev, NV_KEEPREG, 0}, {'Y', nv_abbrev, NV_KEEPREG, 0}, {'Z', nv_Zet, NV_NCH_NOP | NV_NCW, 0}, {'[', nv_brackets, NV_NCH_ALW, BACKWARD}, {'\\', nv_error, 0, 0}, {']', nv_brackets, NV_NCH_ALW, FORWARD}, {'^', nv_beginline, 0, BL_WHITE | BL_FIX}, {'_', nv_lineop, 0, 0}, {'`', nv_gomark, NV_NCH_ALW, FALSE}, {'a', nv_edit, NV_NCH, 0}, {'b', nv_bck_word, 0, 0}, {'c', nv_operator, 0, 0}, {'d', nv_operator, 0, 0}, {'e', nv_wordcmd, 0, FALSE}, {'f', nv_csearch, NV_NCH_ALW | NV_LANG, FORWARD}, {'g', nv_g_cmd, NV_NCH_ALW, FALSE}, {'h', nv_left, NV_RL, 0}, {'i', nv_edit, NV_NCH, 0}, {'j', nv_down, 0, FALSE}, {'k', nv_up, 0, FALSE}, {'l', nv_right, NV_RL, 0}, {'m', nv_mark, NV_NCH_NOP, 0}, {'n', nv_next, 0, 0}, {'o', nv_open, 0, 0}, {'p', nv_put, 0, 0}, {'q', nv_record, NV_NCH, 0}, {'r', nv_replace, NV_NCH_NOP | NV_LANG, 0}, {'s', nv_subst, NV_KEEPREG, 0}, {'t', nv_csearch, NV_NCH_ALW | NV_LANG, FORWARD}, {'u', nv_undo, 0, 0}, {'w', nv_wordcmd, 0, FALSE}, {'x', nv_abbrev, NV_KEEPREG, 0}, {'y', nv_operator, 0, 0}, {'z', nv_zet, NV_NCH_ALW, 0}, {'{', nv_findpar, 0, BACKWARD}, {'|', nv_pipe, 0, 0}, {'}', nv_findpar, 0, FORWARD}, {'~', nv_tilde, 0, 0}, {POUND, nv_ident, 0, 0}, {K_MOUSEUP, nv_mousescroll, 0, MSCR_UP}, {K_MOUSEDOWN, nv_mousescroll, 0, MSCR_DOWN}, {K_MOUSELEFT, nv_mousescroll, 0, MSCR_LEFT}, {K_MOUSERIGHT, nv_mousescroll, 0, MSCR_RIGHT}, {K_LEFTMOUSE, nv_mouse, 0, 0}, {K_LEFTMOUSE_NM, nv_mouse, 0, 0}, {K_LEFTDRAG, nv_mouse, 0, 0}, {K_LEFTRELEASE, nv_mouse, 0, 0}, {K_LEFTRELEASE_NM, nv_mouse, 0, 0}, {K_MOUSEMOVE, nv_mouse, 0, 0}, {
  K_MIDDLEMOUSE, nv_mouse, 0, 0}, {K_MIDDLEDRAG, nv_mouse, 0, 0}, {K_MIDDLERELEASE, nv_mouse, 0, 0}, {K_RIGHTMOUSE, nv_mouse, 0, 0}, {K_RIGHTDRAG, nv_mouse, 0, 0}, {K_RIGHTRELEASE, nv_mouse, 0, 0}, {K_X1MOUSE, nv_mouse, 0, 0}, {K_X1DRAG, nv_mouse, 0, 0}, {K_X1RELEASE, nv_mouse, 0, 0}, {K_X2MOUSE, nv_mouse, 0, 0}, {K_X2DRAG, nv_mouse, 0, 0}, {K_X2RELEASE, nv_mouse, 0, 0}, {K_IGNORE, nv_ignore, NV_KEEPREG, 0}, {K_NOP, nv_nop, 0, 0}, {K_INS, nv_edit, 0, 0}, {K_KINS, nv_edit, 0, 0}, {K_BS, nv_ctrlh, 0, 0}, {K_UP, nv_up, NV_SSS | NV_STS, FALSE}, {K_S_UP, nv_page, NV_SS, BACKWARD}, {K_DOWN, nv_down, NV_SSS | NV_STS, FALSE}, {K_S_DOWN, nv_page, NV_SS, FORWARD}, {K_LEFT, nv_left, NV_SSS | NV_STS | NV_RL, 0}, {K_S_LEFT, nv_bck_word, NV_SS | NV_RL, 0}, {K_C_LEFT, nv_bck_word, NV_SSS | NV_RL | NV_STS, 1}, {K_RIGHT, nv_right, NV_SSS | NV_STS | NV_RL, 0}, {K_S_RIGHT, nv_wordcmd, NV_SS | NV_RL, FALSE}, {K_C_RIGHT, nv_wordcmd, NV_SSS | NV_RL | NV_STS, TRUE}, {K_PAGEUP, nv_page, NV_SSS | NV_STS, BACKWARD}, {K_KPAGEUP, nv_page, NV_SSS | NV_STS, BACKWARD}, {K_PAGEDOWN, nv_page, NV_SSS | NV_STS, FORWARD}, {K_KPAGEDOWN, nv_page, NV_SSS | NV_STS, FORWARD}, {K_END, nv_end, NV_SSS | NV_STS, FALSE}, {K_KEND, nv_end, NV_SSS | NV_STS, FALSE}, {K_S_END, nv_end, NV_SS, FALSE}, {K_C_END, nv_end, NV_SSS | NV_STS, TRUE}, {K_HOME, nv_home, NV_SSS | NV_STS, 0}, {K_KHOME, nv_home, NV_SSS | NV_STS, 0}, {K_S_HOME, nv_home, NV_SS, 0}, {K_C_HOME, nv_goto, NV_SSS | NV_STS, FALSE}, {K_DEL, nv_abbrev, 0, 0}, {K_KDEL, nv_abbrev, 0, 0}, {K_UNDO, nv_kundo, 0, 0}, {K_HELP, nv_help, NV_NCW, 0}, {K_F1, nv_help, NV_NCW, 0}, {K_XF1, nv_help, NV_NCW, 0}, {K_SELECT, nv_select, 0, 0}, {K_VER_SCROLLBAR, nv_ver_scrollbar, 0, 0}, {K_HOR_SCROLLBAR, nv_hor_scrollbar, 0, 0}, {K_F8, farsi_f8, 0, 0}, {K_F9, farsi_f9, 0, 0}, {K_F21, nv_nbcmd, NV_NCH_ALW, 0}, {K_CURSORHOLD, nv_cursorhold, NV_KEEPREG, 0}, {K_PS, nv_edit, 0, 0},};
EXTERN int sc_col;
EXTERN long  Rows;
int showcmd_is_clear = TRUE;
EXTERN char_u *empty_option INIT (= (char_u *) "");
EXTERN char_u *p_sbr;
int showcmd_visual = FALSE;
char_u showcmd_buf [SHOWCMD_BUFLEN];
EXTERN int p_sc;
EXTERN char_u *p_sbo;
char *e_noident = N_ ("E349: No identifier under cursor");
EXTERN pos_T Insstart_orig;
EXTERN pos_T Insstart;
EXTERN int p_sol;
EXTERN int KeyTyped;
EXTERN int p_im;
EXTERN char_u *p_fp;
linenr_T resel_VIsual_line_count;
colnr_T resel_VIsual_vcol;
int resel_VIsual_mode = NUL;
int VIsual_mode_orig = NUL;
EXTERN char_u *repeat_cmdline INIT (= NULL);
EXTERN int VIsual_reselect;
EXTERN pos_T VIsual;
EXTERN char_u *p_sel;
EXTERN buf_T *curbuf INIT (= NULL);
EXTERN char_u *p_cpo;
EXTERN win_T *curwin;
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
EXTERN typebuf_T typebuf;
EXTERN long_u scrollbar_value;
EXTERN except_T *caught_stack INIT (= NULL);
EXTERN int did_uncaught_emsg;
EXTERN int p_guipty;
EXTERN char_u *p_mouseshape;
EXTERN char_u *p_kp;
EXTERN char_u *p_isf;
EXTERN int p_icon;
EXTERN char_u e_emptybuf [] INIT (= N_ ("E749: empty buffer"));

void do_pending_operator (cmdarg_T *cap, int old_col, int gui_yank) {
    oparg_T *oap = cap->oap;
    pos_T old_cursor;
    int empty_region_error;
    int restart_edit_save;
    int lbr_saved = curwin->w_p_lbr;
    static int redo_VIsual_mode = NUL;
    static linenr_T redo_VIsual_line_count;
    static colnr_T redo_VIsual_vcol;
    static long  redo_VIsual_count;
    static int redo_VIsual_arg;
    int include_line_break = FALSE;
    old_cursor = curwin->w_cursor;
    if ((finish_op || VIsual_active) && oap->op_type != OP_NOP) {
        if (curwin->w_p_lbr)
            curwin->w_valid &= ~VALID_VIRTCOL;
        curwin->w_p_lbr = FALSE;
        oap->is_VIsual = VIsual_active;
        if (oap->motion_force == 'V')
            oap->motion_type = MLINE;
        else if (oap->motion_force == 'v') {
            if (oap->motion_type == MLINE)
                oap->inclusive = FALSE;
            else if (oap->motion_type == MCHAR)
                oap->inclusive = !oap->inclusive;
            oap->motion_type = MCHAR;
        }
        else if (oap->motion_force == Ctrl_V) {
            VIsual_active = TRUE;
            VIsual = oap->start;
            VIsual_mode = Ctrl_V;
            VIsual_select = FALSE;
            VIsual_reselect = FALSE;
        }
        if ((vim_strchr (p_cpo, CPO_YANK) != NULL || oap->op_type != OP_YANK) && ((!VIsual_active || oap->motion_force) || (VIsual_active && cap->cmdchar == ':' && oap->op_type != OP_COLON)) && cap->cmdchar != 'D' && oap->op_type != OP_FOLD && oap->op_type != OP_FOLDOPEN && oap->op_type != OP_FOLDOPENREC && oap->op_type != OP_FOLDCLOSE && oap->op_type != OP_FOLDCLOSEREC && oap->op_type != OP_FOLDDEL && oap->op_type != OP_FOLDDELREC) {
            prep_redo (oap -> regname, cap -> count0, get_op_char (oap -> op_type), get_extra_op_char (oap -> op_type), oap -> motion_force, cap -> cmdchar, cap -> nchar);
            if (cap->cmdchar == '/' || cap->cmdchar == '?') {
                if (vim_strchr (p_cpo, CPO_REDO) == NULL)
                    AppendToRedobuffLit (cap->searchbuf, -1);
                AppendToRedobuff (NL_STR);
            }
            else if (cap->cmdchar == ':') {
                if (repeat_cmdline == NULL)
                    ResetRedobuff ();
                else {
                    AppendToRedobuffLit (repeat_cmdline, - 1);
                    AppendToRedobuff (NL_STR);
                    VIM_CLEAR (repeat_cmdline);
                }
            }
        }
        if (redo_VIsual_busy) {
            oap->start = curwin->w_cursor;
            curwin->w_cursor.lnum += redo_VIsual_line_count - 1;
            if (curwin->w_cursor.lnum > curbuf->b_ml.ml_line_count)
                curwin->w_cursor.lnum = curbuf->b_ml.ml_line_count;
            VIsual_mode = redo_VIsual_mode;
            if (redo_VIsual_vcol == MAXCOL || VIsual_mode == 'v') {
                if (VIsual_mode == 'v') {
                    if (redo_VIsual_line_count <= 1) {
                        validate_virtcol ();
                        curwin->w_curswant = curwin->w_virtcol + redo_VIsual_vcol - 1;
                    }
                    else
                        curwin->w_curswant = redo_VIsual_vcol;
                }
                else {
                    curwin->w_curswant = MAXCOL;
                }
                coladvance (curwin -> w_curswant);
            }
            cap->count0 = redo_VIsual_count;
            if (redo_VIsual_count != 0)
                cap->count1 = redo_VIsual_count;
            else
                cap->count1 = 1;
        }
        else if (VIsual_active) {
            if (!gui_yank) {
                curbuf->b_visual.vi_start = VIsual;
                curbuf->b_visual.vi_end = curwin->w_cursor;
                curbuf->b_visual.vi_mode = VIsual_mode;
                if (VIsual_mode_orig != NUL) {
                    curbuf->b_visual.vi_mode = VIsual_mode_orig;
                    VIsual_mode_orig = NUL;
                }
                curbuf->b_visual.vi_curswant = curwin->w_curswant;
                curbuf->b_visual_mode_eval = VIsual_mode;
            }
            if (VIsual_select && VIsual_mode == 'V' && cap->oap->op_type != OP_DELETE) {
                if (LT_POS (VIsual, curwin->w_cursor)) {
                    VIsual.col = 0;
                    curwin->w_cursor.col = (colnr_T) STRLEN (ml_get (curwin->w_cursor.lnum));
                }
                else {
                    curwin->w_cursor.col = 0;
                    VIsual.col = (colnr_T) STRLEN (ml_get (VIsual.lnum));
                }
                VIsual_mode = 'v';
            }
            else if (VIsual_mode == 'v') {
                include_line_break = unadjust_for_sel ();
            }
            oap->start = VIsual;
            if (VIsual_mode == 'V') {
                oap->start.col = 0;
                oap->start.coladd = 0;
            }
        }
        if (LT_POS (oap->start, curwin->w_cursor)) {
            if (!VIsual_active) {
                if (hasFolding (oap->start.lnum, &oap->start.lnum, NULL))
                    oap->start.col = 0;
                if (hasFolding (curwin->w_cursor.lnum, NULL, &curwin->w_cursor.lnum))
                    curwin->w_cursor.col = (colnr_T) STRLEN (ml_get_curline ());
            }
            oap->end = curwin->w_cursor;
            curwin->w_cursor = oap->start;
            curwin->w_valid &= ~VALID_VIRTCOL;
        }
        else {
            if (!VIsual_active && oap->motion_type == MLINE) {
                if (hasFolding (curwin->w_cursor.lnum, &curwin->w_cursor.lnum, NULL))
                    curwin->w_cursor.col = 0;
                if (hasFolding (oap->start.lnum, NULL, &oap->start.lnum))
                    oap->start.col = (colnr_T) STRLEN (ml_get (oap->start.lnum));
            }
            oap->end = oap->start;
            oap->start = curwin->w_cursor;
        }
        check_pos (curwin -> w_buffer, & oap -> end);
        oap->line_count = oap->end.lnum - oap->start.lnum + 1;
        virtual_op = virtual_active ();
        if (VIsual_active || redo_VIsual_busy) {
            get_op_vcol (oap, redo_VIsual_vcol, TRUE);
            if (!redo_VIsual_busy && !gui_yank) {
                resel_VIsual_mode = VIsual_mode;
                if (curwin->w_curswant == MAXCOL)
                    resel_VIsual_vcol = MAXCOL;
                else {
                    if (VIsual_mode != Ctrl_V)
                        getvvcol (curwin, &(oap->end), NULL, NULL, &oap->end_vcol);
                    if (VIsual_mode == Ctrl_V || oap->line_count <= 1) {
                        if (VIsual_mode != Ctrl_V)
                            getvvcol (curwin, &(oap->start), &oap->start_vcol, NULL, NULL);
                        resel_VIsual_vcol = oap->end_vcol - oap->start_vcol + 1;
                    }
                    else
                        resel_VIsual_vcol = oap->end_vcol;
                }
                resel_VIsual_line_count = oap->line_count;
            }
            if ((vim_strchr (p_cpo, CPO_YANK) != NULL || oap->op_type != OP_YANK) && oap->op_type != OP_COLON && oap->op_type != OP_FOLD && oap->op_type != OP_FOLDOPEN && oap->op_type != OP_FOLDOPENREC && oap->op_type != OP_FOLDCLOSE && oap->op_type != OP_FOLDCLOSEREC && oap->op_type != OP_FOLDDEL && oap->op_type != OP_FOLDDELREC && oap->motion_force == NUL) {
                if (cap->cmdchar == 'g' && (cap->nchar == 'n' || cap->nchar == 'N'))
                    prep_redo (oap->regname, cap->count0, get_op_char (oap->op_type), get_extra_op_char (oap->op_type), oap->motion_force, cap->cmdchar, cap->nchar);
                else if (cap->cmdchar != ':') {
                    int nchar = oap->op_type == OP_REPLACE ? cap->nchar : NUL;
                    if (nchar == REPLACE_CR_NCHAR)
                        nchar = CAR;
                    else if (nchar == REPLACE_NL_NCHAR)
                        nchar = NL;
                    prep_redo (oap -> regname, 0L, NUL, 'v', get_op_char (oap -> op_type), get_extra_op_char (oap -> op_type), nchar);
                }
                if (!redo_VIsual_busy) {
                    redo_VIsual_mode = resel_VIsual_mode;
                    redo_VIsual_vcol = resel_VIsual_vcol;
                    redo_VIsual_line_count = resel_VIsual_line_count;
                    redo_VIsual_count = cap->count0;
                    redo_VIsual_arg = cap->arg;
                }
            }
            if (oap->motion_force == NUL || oap->motion_type == MLINE)
                oap->inclusive = TRUE;
            if (VIsual_mode == 'V')
                oap->motion_type = MLINE;
            else {
                oap->motion_type = MCHAR;
                if (VIsual_mode != Ctrl_V && *ml_get_pos (&(oap->end)) == NUL && (include_line_break || !virtual_op)) {
                    oap->inclusive = FALSE;
                    if (*p_sel != 'o' && !op_on_lines (oap->op_type) && oap->end.lnum < curbuf->b_ml.ml_line_count) {
                        ++oap->end.lnum;
                        oap->end.col = 0;
                        oap->end.coladd = 0;
                        ++oap->line_count;
                    }
                }
            }
            redo_VIsual_busy = FALSE;
            if (!gui_yank) {
                VIsual_active = FALSE;
                setmouse ();
                mouse_dragging = 0;
                may_clear_cmdline ();
                if ((oap->op_type == OP_YANK || oap->op_type == OP_COLON || oap->op_type == OP_FUNCTION || oap->op_type == OP_FILTER) && oap->motion_force == NUL) {
                    curwin->w_p_lbr = lbr_saved;
                    redraw_curbuf_later (INVERTED);
                }
            }
        }
        curwin->w_set_curswant = TRUE;
        oap->empty = (oap->motion_type == MCHAR && (!oap->inclusive || (oap->op_type == OP_YANK && gchar_pos (&oap->end) == NUL)) && EQUAL_POS (oap->start, oap->end) && !(virtual_op && oap->start.coladd != oap->end.coladd));
        empty_region_error = (oap->empty && vim_strchr (p_cpo, CPO_EMPTYREGION) != NULL);
        if (oap->is_VIsual && (oap->empty || !curbuf->b_p_ma || oap->op_type == OP_FOLD)) {
            curwin->w_p_lbr = lbr_saved;
            redraw_curbuf_later (INVERTED);
        }
        if (oap->motion_type == MCHAR && oap->inclusive == FALSE && !(cap->retval & CA_NO_ADJ_OP_END) && oap->end.col == 0 && (!oap->is_VIsual || *p_sel == 'o') && !oap->block_mode && oap->line_count > 1) {
            oap->end_adjusted = TRUE;
            --oap->line_count;
            --oap->end.lnum;
            if (inindent (0))
                oap->motion_type = MLINE;
            else {
                oap->end.col = (colnr_T) STRLEN (ml_get (oap->end.lnum));
                if (oap->end.col) {
                    --oap->end.col;
                    oap->inclusive = TRUE;
                }
            }
        }
        else
            oap->end_adjusted = FALSE;
        switch (oap->op_type) {
        case OP_LSHIFT :
        case OP_RSHIFT :
            op_shift (oap, TRUE, oap->is_VIsual ? (int) cap->count1 : 1);
            auto_format (FALSE, TRUE);
            break;
        case OP_JOIN_NS :
        case OP_JOIN :
            if (oap->line_count < 2)
                oap->line_count = 2;
            if (curwin->w_cursor.lnum + oap->line_count - 1 > curbuf->b_ml.ml_line_count)
                beep_flush ();
            else {
                (void) do_join (oap->line_count, oap->op_type == OP_JOIN, TRUE, TRUE, TRUE);
                auto_format (FALSE, TRUE);
            }
            break;
        case OP_DELETE :
            VIsual_reselect = FALSE;
            if (empty_region_error) {
                vim_beep (BO_OPER);
                CancelRedo ();
            }
            else {
                (void) op_delete (oap);
                if (oap->motion_type == MLINE && has_format_option (FO_AUTO))
                    u_save_cursor ();
                auto_format (FALSE, TRUE);
            }
            break;
        case OP_YANK :
            if (empty_region_error) {
                if (!gui_yank) {
                    vim_beep (BO_OPER);
                    CancelRedo ();
                }
            }
            else {
                curwin->w_p_lbr = lbr_saved;
                (void) op_yank (oap, FALSE, !gui_yank);
            }
            check_cursor_col ();
            break;
        case OP_CHANGE :
            VIsual_reselect = FALSE;
            if (empty_region_error) {
                vim_beep (BO_OPER);
                CancelRedo ();
            }
            else {
                if (p_im || !KeyTyped)
                    restart_edit_save = restart_edit;
                else
                    restart_edit_save = 0;
                restart_edit = 0;
                if (curwin->w_p_lbr != lbr_saved) {
                    curwin->w_p_lbr = lbr_saved;
                    get_op_vcol (oap, redo_VIsual_mode, FALSE);
                }
                finish_op = FALSE;
                if (op_change (oap))
                    cap->retval |= CA_COMMAND_BUSY;
                if (restart_edit == 0)
                    restart_edit = restart_edit_save;
            }
            break;
        case OP_FILTER :
            if (vim_strchr (p_cpo, CPO_FILTER) != NULL)
                AppendToRedobuff ((char_u *) "!\r");
            else
                bangredo = TRUE;
        case OP_INDENT :
        case OP_COLON :
            if (oap->op_type == OP_INDENT && *get_equalprg () == NUL) {
                if (curbuf->b_p_lisp) {
                    op_reindent (oap, get_lisp_indent);
                    break;
                }
                op_reindent (oap, * curbuf -> b_p_inde != NUL ? get_expr_indent : get_c_indent);
                break;
            }
            op_colon (oap);
            break;
        case OP_TILDE :
        case OP_UPPER :
        case OP_LOWER :
        case OP_ROT13 :
            if (empty_region_error) {
                vim_beep (BO_OPER);
                CancelRedo ();
            }
            else
                op_tilde (oap);
            check_cursor_col ();
            break;
        case OP_FORMAT :
            if (*curbuf->b_p_fex != NUL)
                op_formatexpr (oap);
            else if (*p_fp != NUL || *curbuf->b_p_fp != NUL)
                op_colon (oap);
            else
                op_format (oap, FALSE);
            break;
        case OP_FORMAT2 :
            op_format (oap, TRUE);
            break;
        case OP_FUNCTION :
            curwin->w_p_lbr = lbr_saved;
            op_function (oap);
            break;
        case OP_INSERT :
        case OP_APPEND :
            VIsual_reselect = FALSE;
            if (empty_region_error) {
                vim_beep (BO_OPER);
                CancelRedo ();
            }
            else {
                restart_edit_save = restart_edit;
                restart_edit = 0;
                if (curwin->w_p_lbr != lbr_saved) {
                    curwin->w_p_lbr = lbr_saved;
                    get_op_vcol (oap, redo_VIsual_mode, FALSE);
                }
                op_insert (oap, cap -> count1);
                curwin->w_p_lbr = FALSE;
                auto_format (FALSE, TRUE);
                if (restart_edit == 0)
                    restart_edit = restart_edit_save;
                else
                    cap->retval |= CA_COMMAND_BUSY;
            }
            break;
        case OP_REPLACE :
            VIsual_reselect = FALSE;
            if (empty_region_error) {
                vim_beep (BO_OPER);
                CancelRedo ();
            }
            else {
                if (curwin->w_p_lbr != lbr_saved) {
                    curwin->w_p_lbr = lbr_saved;
                    get_op_vcol (oap, redo_VIsual_mode, FALSE);
                }
                op_replace (oap, cap -> nchar);
            }
            break;
        case OP_FOLD :
            VIsual_reselect = FALSE;
            foldCreate (oap -> start.lnum, oap -> end.lnum);
            break;
        case OP_FOLDOPEN :
        case OP_FOLDOPENREC :
        case OP_FOLDCLOSE :
        case OP_FOLDCLOSEREC :
            VIsual_reselect = FALSE;
            opFoldRange (oap -> start.lnum, oap -> end.lnum, oap -> op_type == OP_FOLDOPEN || oap -> op_type == OP_FOLDOPENREC, oap -> op_type == OP_FOLDOPENREC || oap -> op_type == OP_FOLDCLOSEREC, oap -> is_VIsual);
            break;
        case OP_FOLDDEL :
        case OP_FOLDDELREC :
            VIsual_reselect = FALSE;
            deleteFold (oap -> start.lnum, oap -> end.lnum, oap -> op_type == OP_FOLDDELREC, oap -> is_VIsual);
            break;
        case OP_NR_ADD :
        case OP_NR_SUB :
            if (empty_region_error) {
                vim_beep (BO_OPER);
                CancelRedo ();
            }
            else {
                VIsual_active = TRUE;
                curwin->w_p_lbr = lbr_saved;
                op_addsub (oap, cap -> count1, redo_VIsual_arg);
                VIsual_active = FALSE;
            }
            check_cursor_col ();
            break;
        default :
            clearopbeep (oap);
        }
        virtual_op = MAYBE;
        if (!gui_yank) {
            if (!p_sol && oap->motion_type == MLINE && !oap->end_adjusted && (oap->op_type == OP_LSHIFT || oap->op_type == OP_RSHIFT || oap->op_type == OP_DELETE)) {
                curwin->w_p_lbr = FALSE;
                coladvance (curwin -> w_curswant = old_col);
            }
        }
        else {
            curwin->w_cursor = old_cursor;
        }
        oap->block_mode = FALSE;
        clearop (oap);
    }
    curwin->w_p_lbr = lbr_saved;
}

static void prep_redo (int regname, long  num, int cmd1, int cmd2, int cmd3, int cmd4, int cmd5) {
    ResetRedobuff ();
    if (regname != 0) {
        AppendCharToRedobuff ('"');
        AppendCharToRedobuff (regname);
    }
    if (num)
        AppendNumberToRedobuff (num);
    if (cmd1 != NUL)
        AppendCharToRedobuff (cmd1);
    if (cmd2 != NUL)
        AppendCharToRedobuff (cmd2);
    if (cmd3 != NUL)
        AppendCharToRedobuff (cmd3);
    if (cmd4 != NUL)
        AppendCharToRedobuff (cmd4);
    if (cmd5 != NUL)
        AppendCharToRedobuff (cmd5);
}

int find_ident_under_cursor (char_u **string, int find_type) {
    return find_ident_at_pos (curwin, curwin->w_cursor.lnum, curwin->w_cursor.col, string, find_type);
}

int find_ident_at_pos (win_T *wp, linenr_T lnum, colnr_T startcol, char_u **string, int find_type) {
    char_u *ptr;
    int col = 0;
    int i;
    int bn = 0;
    ptr = ml_get_buf (wp->w_buffer, lnum, FALSE);
    for (i = (find_type & FIND_IDENT) ? 0 : 1; i < 2; ++i) {
        col = startcol;
        while (ptr[col] != NUL && (i == 0 ? !vim_iswordc (ptr[col]) : VIM_ISWHITE (ptr[col])) && (!(find_type & FIND_EVAL) || ptr[col] != ']'))
            ++col;
        bn = ptr[col] == ']';
        {
            while (col > 0 && ((i == 0 ? vim_iswordc (ptr[col - 1]) : (!VIM_ISWHITE (ptr[col - 1]) && (!(find_type & FIND_IDENT) || !vim_iswordc (ptr[col - 1])))) || ((find_type & FIND_EVAL) && col > 1 && find_is_eval_item (ptr +col - 1, &col, &bn, BACKWARD))))
                --col;
            if (!(find_type & FIND_STRING) || vim_iswordc (ptr[col]))
                break;
        }
    }
    if (ptr[col] == NUL || (i == 0 && (has_mbyte ? this_class != 2 : !vim_iswordc (ptr[col])))) {
        if (find_type & FIND_STRING)
            EMSG (_ ("E348: No string under cursor"));
        else
            EMSG (_ (e_noident));
        return 0;
    }
    ptr += col;
    *string = ptr;
    bn = 0;
    startcol -= col;
    col = 0;
    while ((i == 0 ? vim_iswordc (ptr[col]) : (ptr[col] != NUL && !VIM_ISWHITE (ptr[col]))) || ((find_type & FIND_EVAL) && col <= (int) startcol && find_is_eval_item (ptr +col, &col, &bn, FORWARD))) {
        ++col;
    }
    return col;
}

static int find_is_eval_item (char_u *ptr, int *colp, int *bnp, int dir) {
    if ((*ptr == ']' && dir == BACKWARD) || (*ptr == '[' && dir == FORWARD))
        ++*bnp;
    if (*bnp > 0) {
        if ((*ptr == '[' && dir == BACKWARD) || (*ptr == ']' && dir == FORWARD))
            --*bnp;
        return TRUE;
    }
    if (*ptr == '.')
        return TRUE;
    if (ptr[dir == BACKWARD ? 0 : 1] == '>' && ptr[dir == BACKWARD ? -1 : 0] == '-') {
        *colp += dir;
        return TRUE;
    }
    return FALSE;
}

void do_check_scrollbind (int check) {
    static win_T *old_curwin = NULL;
    static linenr_T old_topline = 0;
    static int old_topfill = 0;
    static buf_T *old_buf = NULL;
    static colnr_T old_leftcol = 0;
    if (check && curwin->w_p_scb) {
        if (did_syncbind)
            did_syncbind = FALSE;
        else if (curwin == old_curwin) {
            if ((curwin->w_buffer == old_buf || curwin->w_p_diff) && (curwin->w_topline != old_topline || curwin->w_topfill != old_topfill || curwin->w_leftcol != old_leftcol)) {
                check_scrollbind (curwin -> w_topline - old_topline, (long) (curwin -> w_leftcol - old_leftcol));
            }
        }
        else if (vim_strchr (p_sbo, 'j')) {
            check_scrollbind (curwin -> w_topline - curwin -> w_scbind_pos, 0L);
        }
        curwin->w_scbind_pos = curwin->w_topline;
    }
    old_curwin = curwin;
    old_topline = curwin->w_topline;
    old_topfill = curwin->w_topfill;
    old_buf = curwin->w_buffer;
    old_leftcol = curwin->w_leftcol;
}

void check_scrollbind (linenr_T topline_diff, long  leftcol_diff) {
    int want_ver;
    int want_hor;
    win_T *old_curwin = curwin;
    buf_T *old_curbuf = curbuf;
    int old_VIsual_select = VIsual_select;
    int old_VIsual_active = VIsual_active;
    colnr_T tgt_leftcol = curwin->w_leftcol;
    long  topline;
    long  y;
    want_ver = (vim_strchr (p_sbo, 'v') && topline_diff != 0);
    want_ver |= old_curwin->w_p_diff;
    want_hor = (vim_strchr (p_sbo, 'h') && (leftcol_diff || topline_diff != 0));
    VIsual_select = VIsual_active = 0;
    FOR_ALL_WINDOWS (curwin) {
        curbuf = curwin->w_buffer;
        if (curwin != old_curwin && curwin->w_p_scb) {
            if (want_ver) {
                if (old_curwin->w_p_diff && curwin->w_p_diff) {
                    diff_set_topline (old_curwin, curwin);
                }
                else {
                    curwin->w_scbind_pos += topline_diff;
                    topline = curwin->w_scbind_pos;
                    if (topline > curbuf->b_ml.ml_line_count)
                        topline = curbuf->b_ml.ml_line_count;
                    if (topline < 1)
                        topline = 1;
                    y = topline - curwin->w_topline;
                    if (y > 0)
                        scrollup (y, FALSE);
                    else
                        scrolldown (-y, FALSE);
                }
                redraw_later (VALID);
                cursor_correct ();
                curwin->w_redr_status = TRUE;
            }
            if (want_hor && curwin->w_leftcol != tgt_leftcol) {
                curwin->w_leftcol = tgt_leftcol;
                leftcol_changed ();
            }
        }
    }
    VIsual_select = old_VIsual_select;
    VIsual_active = old_VIsual_active;
    curwin = old_curwin;
    curbuf = old_curbuf;
}

void clear_showcmd (void) {
    if (!p_sc)
        return;
    if (VIsual_active && !char_avail ()) {
        int cursor_bot = LT_POS (VIsual, curwin->w_cursor);
        long  lines;
        colnr_T leftcol, rightcol;
        linenr_T top, bot;
        if (cursor_bot) {
            top = VIsual.lnum;
            bot = curwin->w_cursor.lnum;
        }
        else {
            top = curwin->w_cursor.lnum;
            bot = VIsual.lnum;
        }
        (void) hasFolding (top, &top, NULL);
        (void) hasFolding (bot, NULL, &bot);
        lines = bot - top + 1;
        if (VIsual_mode == Ctrl_V) {
            char_u *saved_sbr = p_sbr;
            p_sbr = empty_option;
            getvcols (curwin, & curwin -> w_cursor, & VIsual, & leftcol, & rightcol);
            p_sbr = saved_sbr;
            sprintf ((char *) showcmd_buf, "%ldx%ld", lines, (long) (rightcol - leftcol + 1));
        }
        else if (VIsual_mode == 'V' || VIsual.lnum != curwin->w_cursor.lnum)
            sprintf ((char *) showcmd_buf, "%ld", lines);
        else {
            char_u *s, *e;
            int l;
            int bytes = 0;
            int chars = 0;
            if (cursor_bot) {
                s = ml_get_pos (&VIsual);
                e = ml_get_cursor ();
            }
            else {
                s = ml_get_cursor ();
                e = ml_get_pos (&VIsual);
            }
            while ((*p_sel != 'e') ? s <= e : s < e) {
                l = (*s == NUL) ? 0 : 1;
                if (l == 0) {
                    ++bytes;
                    ++chars;
                    break;
                }
                bytes += l;
                ++chars;
                s += l;
            }
            if (bytes == chars)
                sprintf ((char *) showcmd_buf, "%d", chars);
            else
                sprintf ((char *) showcmd_buf, "%d-%d", chars, bytes);
        }
        showcmd_buf[SHOWCMD_COLS] = NUL;
        showcmd_visual = TRUE;
    }
    else {
        showcmd_buf[0] = NUL;
        showcmd_visual = FALSE;
        if (showcmd_is_clear)
            return;
    }
    display_showcmd ();
}

static void display_showcmd (void) {
    int len;
    cursor_off ();
    len = (int) STRLEN (showcmd_buf);
    if (len == 0)
        showcmd_is_clear = TRUE;
    else {
        screen_puts (showcmd_buf, (int) Rows - 1, sc_col, 0);
        showcmd_is_clear = FALSE;
    }
    screen_puts ((char_u *) "          " + len, (int) Rows - 1, sc_col + len, 0);
    setcursor ();
}

void reset_VIsual_and_resel (void) {
    if (VIsual_active) {
        end_visual_mode ();
        redraw_curbuf_later (INVERTED);
    }
    VIsual_reselect = FALSE;
}

void end_visual_mode (void) {
    VIsual_active = FALSE;
    setmouse ();
    mouse_dragging = 0;
    curbuf->b_visual.vi_mode = VIsual_mode;
    curbuf->b_visual.vi_start = VIsual;
    curbuf->b_visual.vi_end = curwin->w_cursor;
    curbuf->b_visual.vi_curswant = curwin->w_curswant;
    curbuf->b_visual_mode_eval = VIsual_mode;
    if (!virtual_active ())
        curwin->w_cursor.coladd = 0;
    may_clear_cmdline ();
    adjust_cursor_eol ();
}

void reset_VIsual (void) {
    if (VIsual_active) {
        end_visual_mode ();
        redraw_curbuf_later (INVERTED);
        VIsual_reselect = FALSE;
    }
}

void normal_cmd (oparg_T *oap, int toplevel) {
    cmdarg_T ca;
    int c;
    int ctrl_w = FALSE;
    int old_col = curwin->w_curswant;
    int need_flushbuf;
    pos_T old_pos;
    int mapped_len;
    static int old_mapped_len = 0;
    int idx;
    int set_prevcount = FALSE;
    vim_memset (& ca, 0, sizeof (ca));
    ca.oap = oap;
    ca.opcount = opcount;
    finish_op = (oap->op_type != OP_NOP);
    if (!finish_op && !oap->regname) {
        ca.opcount = 0;
        set_prevcount = TRUE;
    }
    if (oap->prev_opcount > 0 || oap->prev_count0 > 0) {
        ca.opcount = oap->prev_opcount;
        ca.count0 = oap->prev_count0;
        oap->prev_opcount = 0;
        oap->prev_count0 = 0;
    }
    mapped_len = typebuf_maplen ();
    State = NORMAL_BUSY;
    if (toplevel && readbuf1_empty ())
        set_vcount_ca (&ca, &set_prevcount);
    c = safe_vgetc ();
    LANGMAP_ADJUST (c, get_real_state () != SELECTMODE);
    if (restart_edit == 0)
        old_mapped_len = 0;
    else if (old_mapped_len || (VIsual_active && mapped_len == 0 && typebuf_maplen () > 0))
        old_mapped_len = typebuf_maplen ();
    if (c == NUL)
        c = K_ZERO;
    if (VIsual_active && VIsual_select && (vim_isprintc (c) || c == NL || c == CAR || c == K_KENTER)) {
        ins_char_typebuf (c);
        if (restart_edit != 0)
            c = 'd';
        else
            c = 'c';
        msg_nowait = TRUE;
        old_mapped_len = 0;
    }
    need_flushbuf = add_to_showcmd (c);
getcount :
    if (!(VIsual_active && VIsual_select)) {
        while ((c >= '1' && c <= '9') || (ca.count0 != 0 && (c == K_DEL || c == K_KDEL || c == '0'))) {
            if (c == K_DEL || c == K_KDEL) {
                ca.count0 /= 10;
                del_from_showcmd (4);
            }
            else
                ca.count0 = ca.count0 * 10 + (c - '0');
            if (ca.count0 < 0)
                ca.count0 = 999999999L;
            if (toplevel && readbuf1_empty ())
                set_vcount_ca (&ca, &set_prevcount);
            if (ctrl_w) {
                ++no_mapping;
                ++allow_keys;
            }
            ++no_zero_mapping;
            c = plain_vgetc ();
            LANGMAP_ADJUST (c, TRUE);
            --no_zero_mapping;
            if (ctrl_w) {
                --no_mapping;
                --allow_keys;
            }
            need_flushbuf |= add_to_showcmd (c);
        }
        if (c == Ctrl_W && !ctrl_w && oap->op_type == OP_NOP) {
            ctrl_w = TRUE;
            ca.opcount = ca.count0;
            ca.count0 = 0;
            ++no_mapping;
            ++allow_keys;
            c = plain_vgetc ();
            LANGMAP_ADJUST (c, TRUE);
            --no_mapping;
            --allow_keys;
            need_flushbuf |= add_to_showcmd (c);
            goto getcount;
        }
    }
    if (c == K_CURSORHOLD) {
        oap->prev_opcount = ca.opcount;
        oap->prev_count0 = ca.count0;
    }
    else if (ca.opcount != 0) {
        if (ca.count0)
            ca.count0 *= ca.opcount;
        else
            ca.count0 = ca.opcount;
    }
    ca.opcount = ca.count0;
    ca.count1 = (ca.count0 == 0 ? 1 : ca.count0);
    if (toplevel && readbuf1_empty ())
        set_vcount (ca.count0, ca.count1, set_prevcount);
    if (ctrl_w) {
        ca.nchar = c;
        ca.cmdchar = Ctrl_W;
    }
    else
        ca.cmdchar = c;
    idx = find_command (ca.cmdchar);
    if (idx < 0) {
        clearopbeep (oap);
        goto normal_end;
    }
    if (text_locked () && (nv_cmds[idx].cmd_flags & NV_NCW)) {
        clearopbeep (oap);
        text_locked_msg ();
        goto normal_end;
    }
    if ((nv_cmds[idx].cmd_flags & NV_NCW) && curbuf_locked ())
        goto normal_end;
    if (VIsual_active) {
        if (km_stopsel && (nv_cmds[idx].cmd_flags & NV_STS) && !(mod_mask & MOD_MASK_SHIFT)) {
            end_visual_mode ();
            redraw_curbuf_later (INVERTED);
        }
        if (km_startsel) {
            if (nv_cmds[idx].cmd_flags & NV_SS) {
                unshift_special (& ca);
                idx = find_command (ca.cmdchar);
                if (idx < 0) {
                    clearopbeep (oap);
                    goto normal_end;
                }
            }
            else if ((nv_cmds[idx].cmd_flags & NV_SSS) && (mod_mask & MOD_MASK_SHIFT)) {
                mod_mask &= ~MOD_MASK_SHIFT;
            }
        }
    }
    if (curwin->w_p_rl && KeyTyped && !KeyStuffed && (nv_cmds[idx].cmd_flags & NV_RL)) {
        switch (ca.cmdchar) {
        case 'l' :
            ca.cmdchar = 'h';
            break;
        case K_RIGHT :
            ca.cmdchar = K_LEFT;
            break;
        case K_S_RIGHT :
            ca.cmdchar = K_S_LEFT;
            break;
        case K_C_RIGHT :
            ca.cmdchar = K_C_LEFT;
            break;
        case 'h' :
            ca.cmdchar = 'l';
            break;
        case K_LEFT :
            ca.cmdchar = K_RIGHT;
            break;
        case K_S_LEFT :
            ca.cmdchar = K_S_RIGHT;
            break;
        case K_C_LEFT :
            ca.cmdchar = K_C_RIGHT;
            break;
        case '>' :
            ca.cmdchar = '<';
            break;
        case '<' :
            ca.cmdchar = '>';
            break;
        }
        idx = find_command (ca.cmdchar);
    }
    if ((nv_cmds[idx].cmd_flags & NV_NCH) && (((nv_cmds[idx].cmd_flags & NV_NCH_NOP) == NV_NCH_NOP && oap->op_type == OP_NOP) || (nv_cmds[idx].cmd_flags & NV_NCH_ALW) == NV_NCH_ALW || (ca.cmdchar == 'q' && oap->op_type == OP_NOP && !Recording && !Exec_reg) || ((ca.cmdchar == 'a' || ca.cmdchar == 'i') && (oap->op_type != OP_NOP || VIsual_active)))) {
        int *cp;
        int repl = FALSE;
        int lit = FALSE;
        int langmap_active = FALSE;
        int lang;
        ++no_mapping;
        ++allow_keys;
        did_cursorhold = TRUE;
        if (ca.cmdchar == 'g') {
            ca.nchar = plain_vgetc ();
            LANGMAP_ADJUST (ca.nchar, TRUE);
            need_flushbuf |= add_to_showcmd (ca.nchar);
            if (ca.nchar == 'r' || ca.nchar == '\'' || ca.nchar == '`' || ca.nchar == Ctrl_BSL) {
                cp = &ca.extra_char;
                if (ca.nchar != 'r')
                    lit = TRUE;
                else
                    repl = TRUE;
            }
            else
                cp = NULL;
        }
        else {
            if (ca.cmdchar == 'r')
                repl = TRUE;
            cp = &ca.nchar;
        }
        lang = (repl || (nv_cmds[idx].cmd_flags & NV_LANG));
        if (cp != NULL) {
            if (lang && curbuf->b_p_iminsert == B_IMODE_LMAP) {
                --no_mapping;
                --allow_keys;
                if (repl)
                    State = LREPLACE;
                else
                    State = LANGMAP;
                langmap_active = TRUE;
            }
            *cp = plain_vgetc ();
            if (langmap_active) {
                ++no_mapping;
                ++allow_keys;
                State = NORMAL_BUSY;
            }
            need_flushbuf |= add_to_showcmd (*cp);
            if (!lit) {
                if (*cp == Ctrl_K && ((nv_cmds[idx].cmd_flags & NV_LANG) || cp == &ca.extra_char) && vim_strchr (p_cpo, CPO_DIGRAPH) == NULL) {
                    c = get_digraph (FALSE);
                    if (c > 0) {
                        *cp = c;
                        del_from_showcmd (3);
                        need_flushbuf |= add_to_showcmd (*cp);
                    }
                }
                LANGMAP_ADJUST (* cp, ! lang);
                if (p_hkmap && lang && KeyTyped)
                    *cp = hkmap (*cp);
                if (p_fkmap && lang && KeyTyped)
                    *cp = fkmap (*cp);
            }
            if (cp == &ca.extra_char && ca.nchar == Ctrl_BSL && (ca.extra_char == Ctrl_N || ca.extra_char == Ctrl_G)) {
                ca.cmdchar = Ctrl_BSL;
                ca.nchar = ca.extra_char;
                idx = find_command (ca.cmdchar);
            }
            else if ((ca.nchar == 'n' || ca.nchar == 'N') && ca.cmdchar == 'g')
                ca.oap->op_type = get_op_type (*cp, NUL);
            else if (*cp == Ctrl_BSL) {
                long  towait = (p_ttm >= 0 ? p_ttm : p_tm);
                while ((c = vpeekc ()) <= 0 && towait > 0L) {
                    do_sleep (towait > 50L ? 50L : towait);
                    towait -= 50L;
                }
                if (c > 0) {
                    c = plain_vgetc ();
                    if (c != Ctrl_N && c != Ctrl_G)
                        vungetc (c);
                    else {
                        ca.cmdchar = Ctrl_BSL;
                        ca.nchar = c;
                        idx = find_command (ca.cmdchar);
                    }
                }
            }
        }
        --no_mapping;
        --allow_keys;
    }
    if (need_flushbuf)
        out_flush ();
    if (ca.cmdchar != K_IGNORE)
        did_cursorhold = FALSE;
    State = NORMAL;
    if (ca.nchar == ESC) {
        clearop (oap);
        if (restart_edit == 0 && goto_im ())
            restart_edit = 'a';
        goto normal_end;
    }
    if (ca.cmdchar != K_IGNORE) {
        msg_didout = FALSE;
        msg_col = 0;
    }
    old_pos = curwin->w_cursor;
    if (!VIsual_active && km_startsel) {
        if (nv_cmds[idx].cmd_flags & NV_SS) {
            start_selection ();
            unshift_special (& ca);
            idx = find_command (ca.cmdchar);
        }
        else if ((nv_cmds[idx].cmd_flags & NV_SSS) && (mod_mask & MOD_MASK_SHIFT)) {
            start_selection ();
            mod_mask &= ~MOD_MASK_SHIFT;
        }
    }
    ca.arg = nv_cmds[idx].cmd_arg;
    (nv_cmds[idx].cmd_func) (&ca);
    if (!finish_op && !oap->op_type && (idx < 0 || !(nv_cmds[idx].cmd_flags & NV_KEEPREG))) {
        clearop (oap);
        {
            int regname = 0;
            set_reg_var (regname);
        }
    }
    if (old_mapped_len > 0)
        old_mapped_len = typebuf_maplen ();
    do_pending_operator (& ca, old_col, FALSE);
    if (((p_smd && msg_silent == 0 && (restart_edit != 0 || (VIsual_active && old_pos.lnum == curwin->w_cursor.lnum && old_pos.col == curwin->w_cursor.col)) && (clear_cmdline || redraw_cmdline) && (msg_didout || (msg_didany && msg_scroll)) && !msg_nowait && KeyTyped) || (restart_edit != 0 && !VIsual_active && (msg_scroll || emsg_on_display))) && oap->regname == 0 && !(ca.retval & CA_COMMAND_BUSY) && stuff_empty () && typebuf_typed () && emsg_silent == 0 && !did_wait_return && oap->op_type == OP_NOP) {
        int save_State = State;
        if (restart_edit != 0)
            State = INSERT;
        if (must_redraw && keep_msg != NULL && !emsg_on_display) {
            char_u *kmsg;
            kmsg = keep_msg;
            keep_msg = NULL;
            update_screen (0);
            keep_msg = kmsg;
            msg_attr (kmsg, keep_msg_attr);
            vim_free (kmsg);
        }
        setcursor ();
        cursor_on ();
        out_flush ();
        if (msg_scroll || emsg_on_display)
            ui_delay (1000L, TRUE);
        ui_delay (3000L, FALSE);
        State = save_State;
        msg_scroll = FALSE;
        emsg_on_display = FALSE;
    }
normal_end :
    msg_nowait = FALSE;
    finish_op = FALSE;
    if (oap->op_type == OP_NOP && oap->regname == 0 && ca.cmdchar != K_CURSORHOLD)
        clear_showcmd ();
    checkpcmark ();
    vim_free (ca.searchbuf);
    if (curwin->w_p_scb && toplevel) {
        validate_cursor ();
        do_check_scrollbind (TRUE);
    }
    if (curwin->w_p_crb && toplevel) {
        validate_cursor ();
        do_check_cursorbind ();
    }
    if (term_job_running (curbuf->b_term))
        restart_edit = 0;
    if (oap->op_type == OP_NOP && ((restart_edit != 0 && !VIsual_active && old_mapped_len == 0) || restart_VIsual_select == 1) && !(ca.retval & CA_COMMAND_BUSY) && stuff_empty () && oap->regname == 0) {
        if (restart_VIsual_select == 1) {
            VIsual_select = TRUE;
            showmode ();
            restart_VIsual_select = 0;
        }
        if (restart_edit != 0 && !VIsual_active && old_mapped_len == 0)
            (void) edit (restart_edit, FALSE, 1L);
    }
    if (restart_VIsual_select == 2)
        restart_VIsual_select = 1;
    opcount = ca.opcount;
}

static void set_vcount_ca (cmdarg_T *cap, int *set_prevcount) {
    long  count = cap->count0;
    if (cap->opcount != 0)
        count = cap->opcount * (count == 0 ? 1 : count);
    set_vcount (count, count == 0 ? 1 : count, * set_prevcount);
    *set_prevcount = FALSE;
}

int add_to_showcmd (int c) {
    char_u *p;
    int old_len;
    int extra_len;
    int overflow;
    int i;
    static int ignore [] = {K_VER_SCROLLBAR, K_HOR_SCROLLBAR, K_LEFTMOUSE_NM, K_LEFTRELEASE_NM, K_IGNORE, K_PS, K_LEFTMOUSE, K_LEFTDRAG, K_LEFTRELEASE, K_MOUSEMOVE, K_MIDDLEMOUSE, K_MIDDLEDRAG, K_MIDDLERELEASE, K_RIGHTMOUSE, K_RIGHTDRAG, K_RIGHTRELEASE, K_MOUSEDOWN, K_MOUSEUP, K_MOUSELEFT, K_MOUSERIGHT, K_X1MOUSE, K_X1DRAG, K_X1RELEASE, K_X2MOUSE, K_X2DRAG, K_X2RELEASE, K_CURSORHOLD, K_SWIPELEFT, K_SWIPERIGHT, K_SWIPEUP, K_SWIPEDOWN, 0};
    if (!p_sc || msg_silent != 0)
        return FALSE;
    if (showcmd_visual) {
        showcmd_buf[0] = NUL;
        showcmd_visual = FALSE;
    }
    if (IS_SPECIAL (c))
        for (i = 0; ignore[i] != 0; ++i)
            if (ignore[i] == c)
                return FALSE;
    p = transchar (c);
    if (*p == ' ')
        STRCPY (p, "<20>");
    old_len = (int) STRLEN (showcmd_buf);
    extra_len = (int) STRLEN (p);
    overflow = old_len + extra_len - SHOWCMD_COLS;
    if (overflow > 0)
        mch_memmove (showcmd_buf, showcmd_buf +overflow, old_len -overflow + 1);
    STRCAT (showcmd_buf, p);
    if (char_avail ())
        return FALSE;
    display_showcmd ();
    return TRUE;
}

static void del_from_showcmd (int len) {
    int old_len;
    if (!p_sc)
        return;
    old_len = (int) STRLEN (showcmd_buf);
    if (len > old_len)
        len = old_len;
    showcmd_buf[old_len - len] = NUL;
    if (!char_avail ())
        display_showcmd ();
}

static int find_command (int cmdchar) {
    int i;
    int idx;
    int top, bot;
    int c;
    if (cmdchar < 0)
        cmdchar = -cmdchar;
    if (cmdchar <= nv_max_linear)
        return nv_cmd_idx[cmdchar];
    bot = nv_max_linear + 1;
    top = NV_CMDS_SIZE - 1;
    idx = -1;
    while (bot <= top) {
        i = (top + bot) / 2;
        c = nv_cmds[nv_cmd_idx[i]].cmd_char;
        if (c < 0)
            c = -c;
        if (cmdchar == c) {
            idx = nv_cmd_idx[i];
            break;
        }
        if (cmdchar > c)
            bot = i + 1;
        else
            top = i - 1;
    }
    return idx;
}

static void clearopbeep (oparg_T *oap) {
    clearop (oap);
    beep_flush ();
}

static void clearop (oparg_T *oap) {
    oap->op_type = OP_NOP;
    oap->regname = 0;
    oap->motion_force = NUL;
    oap->use_reg_one = FALSE;
}

static void unshift_special (cmdarg_T *cap) {
    switch (cap->cmdchar) {
    case K_S_RIGHT :
        cap->cmdchar = K_RIGHT;
        break;
    case K_S_LEFT :
        cap->cmdchar = K_LEFT;
        break;
    case K_S_UP :
        cap->cmdchar = K_UP;
        break;
    case K_S_DOWN :
        cap->cmdchar = K_DOWN;
        break;
    case K_S_HOME :
        cap->cmdchar = K_HOME;
        break;
    case K_S_END :
        cap->cmdchar = K_END;
        break;
    }
    cap->cmdchar = simplify_key (cap->cmdchar, &mod_mask);
}

void start_selection (void) {
    may_start_select ('k');
    n_start_visual_mode ('v');
}

void may_start_select (int c) {
    VIsual_select = (stuff_empty () && typebuf_typed () && (vim_strchr (p_slm, c) != NULL));
}

static void n_start_visual_mode (int c) {
    conceal_check_cursur_line ();
    VIsual_mode = c;
    VIsual_active = TRUE;
    VIsual_reselect = TRUE;
    if (c == Ctrl_V && (ve_flags & VE_BLOCK) && gchar_cursor () == TAB) {
        validate_virtcol ();
        coladvance (curwin -> w_virtcol);
    }
    VIsual = curwin->w_cursor;
    foldAdjustVisual ();
    setmouse ();
    conceal_check_cursur_line ();
    if (p_smd && msg_silent == 0)
        redraw_cmdline = TRUE;
    if (curwin->w_redr_type < INVERTED) {
        curwin->w_old_cursor_lnum = curwin->w_cursor.lnum;
        curwin->w_old_visual_lnum = curwin->w_cursor.lnum;
    }
}

void add_to_showcmd_c (int c) {
    if (!add_to_showcmd (c))
        setcursor ();
}

int do_mouse (oparg_T *oap, int c, int dir, long  count, int fixindent) {
    static int do_always = FALSE;
    static int got_click = FALSE;
    int which_button;
    int is_click;
    int is_drag;
    int jump_flags = 0;
    pos_T start_visual;
    int moved;
    int in_status_line;
    static int in_tab_line = FALSE;
    int in_sep_line;
    int c1, c2;
    pos_T save_cursor;
    win_T *old_curwin = curwin;
    static pos_T orig_cursor;
    colnr_T leftcol, rightcol;
    pos_T end_visual;
    int diff;
    int old_active = VIsual_active;
    int old_mode = VIsual_mode;
    int regname;
    save_cursor = curwin->w_cursor;
    if (do_always)
        do_always = FALSE;
    else if (!gui.in_use) {
        if (VIsual_active) {
            if (!mouse_has (MOUSE_VISUAL))
                return FALSE;
        }
        else if (State == NORMAL && !mouse_has (MOUSE_NORMAL))
            return FALSE;
    }
    for (;;) {
        which_button = get_mouse_button (KEY2TERMCAP1 (c), &is_click, &is_drag);
        if (is_drag) {
            if (vpeekc () != NUL) {
                int nc;
                int save_mouse_row = mouse_row;
                int save_mouse_col = mouse_col;
                nc = safe_vgetc ();
                if (c == nc)
                    continue;
                vungetc (nc);
                mouse_row = save_mouse_row;
                mouse_col = save_mouse_col;
            }
        }
        break;
    }
    if (c == K_MOUSEMOVE) {
        return FALSE;
    }
    if (is_click)
        got_click = TRUE;
    else {
        if (!got_click)
            return FALSE;
        if (!is_drag) {
            got_click = FALSE;
            if (in_tab_line) {
                in_tab_line = FALSE;
                return FALSE;
            }
        }
    }
    if (is_click && (mod_mask & MOD_MASK_CTRL) && which_button == MOUSE_RIGHT) {
        if (State & INSERT)
            stuffcharReadbuff (Ctrl_O);
        if (count > 1)
            stuffnumReadbuff (count);
        stuffcharReadbuff (Ctrl_T);
        got_click = FALSE;
        return FALSE;
    }
    if ((mod_mask & MOD_MASK_CTRL) && which_button != MOUSE_LEFT)
        return FALSE;
    if ((mod_mask & (MOD_MASK_SHIFT | MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_META)) && (!is_click || (mod_mask & MOD_MASK_MULTI_CLICK) || which_button == MOUSE_MIDDLE) && !((mod_mask & (MOD_MASK_SHIFT | MOD_MASK_ALT)) && mouse_model_popup () && which_button == MOUSE_LEFT) && !((mod_mask & MOD_MASK_ALT) && !mouse_model_popup () && which_button == MOUSE_RIGHT))
        return FALSE;
    if (!is_click && which_button == MOUSE_MIDDLE)
        return FALSE;
    if (oap != NULL)
        regname = oap->regname;
    else
        regname = 0;
    if (which_button == MOUSE_MIDDLE) {
        if (State == NORMAL) {
            if (oap != NULL && oap->op_type != OP_NOP) {
                clearopbeep (oap);
                return FALSE;
            }
            if (VIsual_active) {
                if (VIsual_select) {
                    stuffcharReadbuff (Ctrl_G);
                    stuffReadbuff ((char_u *) "\"+p");
                }
                else {
                    stuffcharReadbuff ('y');
                    stuffcharReadbuff (K_MIDDLEMOUSE);
                }
                do_always = TRUE;
                return FALSE;
            }
        }
        else if ((State & INSERT) == 0)
            return FALSE;
        if ((State & INSERT) || !mouse_has (MOUSE_NORMAL)) {
            if (regname == '.')
                insert_reg (regname, TRUE);
            else {
                if ((State & REPLACE_FLAG) && !yank_register_mline (regname))
                    insert_reg (regname, TRUE);
                else {
                    do_put (regname, BACKWARD, 1L, fixindent | PUT_CURSEND);
                    AppendCharToRedobuff (Ctrl_R);
                    AppendCharToRedobuff (fixindent ? Ctrl_P : Ctrl_O);
                    AppendCharToRedobuff (regname == 0 ? '"' : regname);
                }
            }
            return FALSE;
        }
    }
    if (!is_click)
        jump_flags |= MOUSE_FOCUS | MOUSE_DID_MOVE;
    start_visual.lnum = 0;
    if (mouse_row == 0 && firstwin->w_winrow > 0) {
        if (is_drag) {
            if (in_tab_line) {
                c1 = TabPageIdxs[mouse_col];
                tabpage_move (c1 <= 0 ? 9999 : c1 < tabpage_index (curtab) ? c1 - 1 : c1);
            }
            return FALSE;
        }
        if (is_click && mouse_col < Columns) {
            in_tab_line = TRUE;
            c1 = TabPageIdxs[mouse_col];
            if (c1 >= 0) {
                if ((mod_mask & MOD_MASK_MULTI_CLICK) == MOD_MASK_2CLICK) {
                    end_visual_mode ();
                    tabpage_new ();
                    tabpage_move (c1 == 0 ? 9999 : c1 - 1);
                }
                else {
                    goto_tabpage (c1);
                    if (curwin != old_curwin)
                        end_visual_mode ();
                }
            }
            else if (c1 < 0) {
                tabpage_T *tp;
                if (c1 == -999)
                    tp = curtab;
                else
                    tp = find_tabpage (-c1);
                if (tp == curtab) {
                    if (first_tabpage->tp_next != NULL)
                        tabpage_close (FALSE);
                }
                else if (tp != NULL)
                    tabpage_close_other (tp, FALSE);
            }
        }
        return TRUE;
    }
    else if (is_drag && in_tab_line) {
        c1 = TabPageIdxs[mouse_col];
        tabpage_move (c1 <= 0 ? 9999 : c1 - 1);
        return FALSE;
    }
    if (mouse_model_popup ()) {
        if (which_button == MOUSE_RIGHT && !(mod_mask & (MOD_MASK_SHIFT | MOD_MASK_CTRL))) {
            if (!is_click)
                return FALSE;
            if (gui.in_use) {
                jump_flags = 0;
                if (STRCMP (p_mousem, "popup_setpos") == 0) {
                    if (VIsual_active) {
                        pos_T m_pos;
                        if (mouse_row < curwin->w_winrow || mouse_row > (curwin->w_winrow + curwin->w_height))
                            jump_flags = MOUSE_MAY_STOP_VIS;
                        else if (get_fpos_of_mouse (&m_pos) != IN_BUFFER)
                            jump_flags = MOUSE_MAY_STOP_VIS;
                        else {
                            if ((LT_POS (curwin->w_cursor, VIsual) && (LT_POS (m_pos, curwin->w_cursor) || LT_POS (VIsual, m_pos))) || (LT_POS (VIsual, curwin->w_cursor) && (LT_POS (m_pos, VIsual) || LT_POS (curwin->w_cursor, m_pos)))) {
                                jump_flags = MOUSE_MAY_STOP_VIS;
                            }
                            else if (VIsual_mode == Ctrl_V) {
                                getvcols (curwin, & curwin -> w_cursor, & VIsual, & leftcol, & rightcol);
                                getvcol (curwin, & m_pos, NULL, & m_pos.col, NULL);
                                if (m_pos.col < leftcol || m_pos.col > rightcol)
                                    jump_flags = MOUSE_MAY_STOP_VIS;
                            }
                        }
                    }
                    else
                        jump_flags = MOUSE_MAY_STOP_VIS;
                }
                if (jump_flags) {
                    jump_flags = jump_to_mouse (jump_flags, NULL, which_button);
                    update_curbuf (VIsual_active ? INVERTED : VALID);
                    setcursor ();
                    out_flush ();
                }
                gui_show_popupmenu ();
                return (jump_flags & CURSOR_MOVED) != 0;
            }
            else
                return FALSE;
        }
        if (which_button == MOUSE_LEFT && (mod_mask & (MOD_MASK_SHIFT | MOD_MASK_ALT))) {
            which_button = MOUSE_RIGHT;
            mod_mask &= ~MOD_MASK_SHIFT;
        }
    }
    if ((State & (NORMAL | INSERT)) && !(mod_mask & (MOD_MASK_SHIFT | MOD_MASK_CTRL))) {
        if (which_button == MOUSE_LEFT) {
            if (is_click) {
                if (VIsual_active)
                    jump_flags |= MOUSE_MAY_STOP_VIS;
            }
            else if (mouse_has (MOUSE_VISUAL))
                jump_flags |= MOUSE_MAY_VIS;
        }
        else if (which_button == MOUSE_RIGHT) {
            if (is_click && VIsual_active) {
                if (LT_POS (curwin->w_cursor, VIsual)) {
                    start_visual = curwin->w_cursor;
                    end_visual = VIsual;
                }
                else {
                    start_visual = VIsual;
                    end_visual = curwin->w_cursor;
                }
            }
            jump_flags |= MOUSE_FOCUS;
            if (mouse_has (MOUSE_VISUAL))
                jump_flags |= MOUSE_MAY_VIS;
        }
    }
    if (!is_drag && oap != NULL && oap->op_type != OP_NOP) {
        got_click = FALSE;
        oap->motion_type = MCHAR;
    }
    if (!is_click && !is_drag)
        jump_flags |= MOUSE_RELEASED;
    jump_flags = jump_to_mouse (jump_flags, oap == NULL ? NULL : &(oap->inclusive), which_button);
    if (jump_flags & MOUSE_WINBAR)
        return FALSE;
    moved = (jump_flags & CURSOR_MOVED);
    in_status_line = (jump_flags & IN_STATUS_LINE);
    in_sep_line = (jump_flags & IN_SEP_LINE);
    if (isNetbeansBuffer (curbuf) && !(jump_flags & (IN_STATUS_LINE | IN_SEP_LINE))) {
        int key = KEY2TERMCAP1 (c);
        if (key == (int) KE_LEFTRELEASE || key == (int) KE_MIDDLERELEASE || key == (int) KE_RIGHTRELEASE)
            netbeans_button_release (which_button);
    }
    if (curwin != old_curwin && oap != NULL && oap->op_type != OP_NOP)
        clearop (oap);
    if (mod_mask == 0 && !is_drag && (jump_flags & (MOUSE_FOLD_CLOSE | MOUSE_FOLD_OPEN)) && which_button == MOUSE_LEFT) {
        if (jump_flags & MOUSE_FOLD_OPEN)
            openFold (curwin->w_cursor.lnum, 1L);
        else
            closeFold (curwin->w_cursor.lnum, 1L);
        if (curwin == old_curwin)
            curwin->w_cursor = save_cursor;
    }
    if (VIsual_active && is_drag && p_so) {
        if (mouse_row == 0)
            mouse_dragging = 2;
        else
            mouse_dragging = 1;
    }
    if (is_drag && mouse_row < 0 && !in_status_line) {
        scroll_redraw (FALSE, 1L);
        mouse_row = 0;
    }
    if (start_visual.lnum) {
        if (mod_mask & MOD_MASK_ALT)
            VIsual_mode = Ctrl_V;
        if (VIsual_mode == Ctrl_V) {
            getvcols (curwin, & start_visual, & end_visual, & leftcol, & rightcol);
            if (curwin->w_curswant > (leftcol + rightcol) / 2)
                end_visual.col = leftcol;
            else
                end_visual.col = rightcol;
            if (curwin->w_cursor.lnum >= (start_visual.lnum + end_visual.lnum) / 2)
                end_visual.lnum = start_visual.lnum;
            start_visual = curwin->w_cursor;
            curwin->w_cursor = end_visual;
            coladvance (end_visual.col);
            VIsual = curwin->w_cursor;
            curwin->w_cursor = start_visual;
        }
        else {
            if (LT_POS (curwin->w_cursor, start_visual))
                VIsual = end_visual;
            else if (LT_POS (end_visual, curwin->w_cursor))
                VIsual = start_visual;
            else {
                if (end_visual.lnum == start_visual.lnum) {
                    if (curwin->w_cursor.col - start_visual.col > end_visual.col - curwin->w_cursor.col)
                        VIsual = start_visual;
                    else
                        VIsual = end_visual;
                }
                else {
                    diff = (curwin->w_cursor.lnum - start_visual.lnum) - (end_visual.lnum - curwin->w_cursor.lnum);
                    if (diff > 0)
                        VIsual = start_visual;
                    else if (diff < 0)
                        VIsual = end_visual;
                    else {
                        if (curwin->w_cursor.col < (start_visual.col + end_visual.col) / 2)
                            VIsual = end_visual;
                        else
                            VIsual = start_visual;
                    }
                }
            }
        }
    }
    else if ((State & INSERT) && VIsual_active)
        stuffcharReadbuff (Ctrl_O);
    if (which_button == MOUSE_MIDDLE) {
        if (yank_register_mline (regname)) {
            if (mouse_past_bottom)
                dir = FORWARD;
        }
        else if (mouse_past_eol)
            dir = FORWARD;
        if (fixindent) {
            c1 = (dir == BACKWARD) ? '[' : ']';
            c2 = 'p';
        }
        else {
            c1 = (dir == FORWARD) ? 'p' : 'P';
            c2 = NUL;
        }
        prep_redo (regname, count, NUL, c1, NUL, c2, NUL);
        if (restart_edit != 0)
            where_paste_started = curwin->w_cursor;
        do_put (regname, dir, count, fixindent | PUT_CURSEND);
    }
    else if (((mod_mask & MOD_MASK_CTRL) || (mod_mask & MOD_MASK_MULTI_CLICK) == MOD_MASK_2CLICK) && bt_quickfix (curbuf)) {
        if (curwin->w_llist_ref == NULL)
            do_cmdline_cmd ((char_u *) ".cc");
        else
            do_cmdline_cmd ((char_u *) ".ll");
        got_click = FALSE;
    }
    else if ((mod_mask & MOD_MASK_CTRL) || (curbuf->b_help && (mod_mask & MOD_MASK_MULTI_CLICK) == MOD_MASK_2CLICK)) {
        if (State & INSERT)
            stuffcharReadbuff (Ctrl_O);
        stuffcharReadbuff (Ctrl_RSB);
        got_click = FALSE;
    }
    else if ((mod_mask & MOD_MASK_SHIFT)) {
        if ((State & INSERT) || (VIsual_active && VIsual_select))
            stuffcharReadbuff (Ctrl_O);
        if (which_button == MOUSE_LEFT)
            stuffcharReadbuff ('*');
        else
            stuffcharReadbuff ('#');
    }
    else if (in_status_line) {
    }
    else if (in_sep_line) {
    }
    else if ((mod_mask & MOD_MASK_MULTI_CLICK) && (State & (NORMAL | INSERT)) && mouse_has (MOUSE_VISUAL)) {
        if (is_click || !VIsual_active) {
            if (VIsual_active)
                orig_cursor = VIsual;
            else {
                check_visual_highlight ();
                VIsual = curwin->w_cursor;
                orig_cursor = VIsual;
                VIsual_active = TRUE;
                VIsual_reselect = TRUE;
                may_start_select ('o');
                setmouse ();
            }
            if ((mod_mask & MOD_MASK_MULTI_CLICK) == MOD_MASK_2CLICK) {
                if (mod_mask & MOD_MASK_ALT)
                    VIsual_mode = Ctrl_V;
                else
                    VIsual_mode = 'v';
            }
            else if ((mod_mask & MOD_MASK_MULTI_CLICK) == MOD_MASK_3CLICK)
                VIsual_mode = 'V';
            else if ((mod_mask & MOD_MASK_MULTI_CLICK) == MOD_MASK_4CLICK)
                VIsual_mode = Ctrl_V;
        }
        if ((mod_mask & MOD_MASK_MULTI_CLICK) == MOD_MASK_2CLICK) {
            pos_T *pos = NULL;
            int gc;
            if (is_click) {
                end_visual = curwin->w_cursor;
                while (gc = gchar_pos (&end_visual), VIM_ISWHITE (gc))
                    inc (&end_visual);
                if (oap != NULL)
                    oap->motion_type = MCHAR;
                if (oap != NULL && VIsual_mode == 'v' && !vim_iswordc (gchar_pos (&end_visual)) && EQUAL_POS (curwin->w_cursor, VIsual) && (pos = findmatch (oap, NUL)) != NULL) {
                    curwin->w_cursor = *pos;
                    if (oap->motion_type == MLINE)
                        VIsual_mode = 'V';
                    else if (*p_sel == 'e') {
                        if (LT_POS (curwin->w_cursor, VIsual))
                            ++VIsual.col;
                        else
                            ++curwin->w_cursor.col;
                    }
                }
            }
            if (pos == NULL && (is_click || is_drag)) {
                if (LT_POS (curwin->w_cursor, orig_cursor)) {
                    find_start_of_word (& curwin -> w_cursor);
                    find_end_of_word (& VIsual);
                }
                else {
                    find_start_of_word (& VIsual);
                    if (*p_sel == 'e' && *ml_get_cursor () != NUL)
                        ++curwin->w_cursor.col;
                    find_end_of_word (& curwin -> w_cursor);
                }
            }
            curwin->w_set_curswant = TRUE;
        }
        if (is_click)
            redraw_curbuf_later (INVERTED);
    }
    else if (VIsual_active && !old_active) {
        if (mod_mask & MOD_MASK_ALT)
            VIsual_mode = Ctrl_V;
        else
            VIsual_mode = 'v';
    }
    if ((!VIsual_active && old_active && mode_displayed) || (VIsual_active && p_smd && msg_silent == 0 && (!old_active || VIsual_mode != old_mode)))
        redraw_cmdline = TRUE;
    return moved;
}

void check_visual_highlight (void) {
    static int did_check = FALSE;
    if (full_screen) {
        if (!did_check && HL_ATTR (HLF_V) == 0)
            MSG (_ ("Warning: terminal cannot highlight"));
        did_check = TRUE;
    }
}

void scroll_redraw (int up, long  count) {
    linenr_T prev_topline = curwin->w_topline;
    int prev_topfill = curwin->w_topfill;
    linenr_T prev_lnum = curwin->w_cursor.lnum;
    if (up)
        scrollup (count, TRUE);
    else
        scrolldown (count, TRUE);
    if (p_so) {
        cursor_correct ();
        check_cursor_moved (curwin);
        curwin->w_valid |= VALID_TOPLINE;
        while (curwin->w_topline == prev_topline && curwin->w_topfill == prev_topfill) {
            if (up) {
                if (curwin->w_cursor.lnum > prev_lnum || cursor_down (1L, FALSE) == FAIL)
                    break;
            }
            else {
                if (curwin->w_cursor.lnum < prev_lnum || prev_topline == 1L || cursor_up (1L, FALSE) == FAIL)
                    break;
            }
            check_cursor_moved (curwin);
            curwin->w_valid |= VALID_TOPLINE;
        }
    }
    if (curwin->w_cursor.lnum != prev_lnum)
        coladvance (curwin->w_curswant);
    redraw_later (VALID);
}

static void find_start_of_word (pos_T *pos) {
    char_u *line;
    int cclass;
    int col;
    line = ml_get (pos->lnum);
    cclass = get_mouse_class (line +pos->col);
    while (pos->col > 0) {
        col = pos->col - 1;
        if (get_mouse_class (line +col) != cclass)
            break;
        pos->col = col;
    }
}

static int get_mouse_class (char_u *p) {
    int c;
    c = *p;
    if (c == ' ' || c == '\t')
        return 0;
    if (vim_iswordc (c))
        return 2;
    if (c != NUL && vim_strchr ((char_u *) "-+*/%<>&|^!=", c) != NULL)
        return 1;
    return c;
}

static void find_end_of_word (pos_T *pos) {
    char_u *line;
    int cclass;
    int col;
    line = ml_get (pos->lnum);
    if (*p_sel == 'e' && pos->col > 0) {
        --pos->col;
    }
    cclass = get_mouse_class (line +pos->col);
    while (line[pos->col] != NUL) {
        col = pos->col + 1;
        if (get_mouse_class (line +col) != cclass) {
            if (*p_sel == 'e')
                pos->col = col;
            break;
        }
        pos->col = col;
    }
}

void push_showcmd (void) {
    if (p_sc)
        STRCPY (old_showcmd_buf, showcmd_buf);
}

void pop_showcmd (void) {
    if (!p_sc)
        return;
    STRCPY (showcmd_buf, old_showcmd_buf);
    display_showcmd ();
}

static int unadjust_for_sel (void) {
    pos_T *pp;
    if (*p_sel == 'e' && !EQUAL_POS (VIsual, curwin->w_cursor)) {
        if (LT_POS (VIsual, curwin->w_cursor))
            pp = &curwin->w_cursor;
        else
            pp = &VIsual;
        if (pp->coladd > 0)
            --pp->coladd;
        else if (pp->col > 0) {
            --pp->col;
        }
        else if (pp->lnum > 1) {
            --pp->lnum;
            pp->col = (colnr_T) STRLEN (ml_get (pp->lnum));
            return TRUE;
        }
    }
    return FALSE;
}

static void op_colon (oparg_T *oap) {
    stuffcharReadbuff (':');
    if (oap->is_VIsual)
        stuffReadbuff ((char_u *) "'<,'>");
    else {
        if (oap->start.lnum == curwin->w_cursor.lnum)
            stuffcharReadbuff ('.');
        else
            stuffnumReadbuff ((long ) oap->start.lnum);
        if (oap->end.lnum != oap->start.lnum) {
            stuffcharReadbuff (',');
            if (oap->end.lnum == curwin->w_cursor.lnum)
                stuffcharReadbuff ('.');
            else if (oap->end.lnum == curbuf->b_ml.ml_line_count)
                stuffcharReadbuff ('$');
            else if (oap->start.lnum == curwin->w_cursor.lnum) {
                stuffReadbuff ((char_u *) ".+");
                stuffnumReadbuff ((long) oap -> line_count - 1);
            }
            else
                stuffnumReadbuff ((long ) oap->end.lnum);
        }
    }
    if (oap->op_type != OP_COLON)
        stuffReadbuff ((char_u *) "!");
    if (oap->op_type == OP_INDENT) {
        stuffReadbuff (get_equalprg ());
        stuffReadbuff ((char_u *) "\n");
    }
    else if (oap->op_type == OP_FORMAT) {
        if (*curbuf->b_p_fp != NUL)
            stuffReadbuff (curbuf->b_p_fp);
        else if (*p_fp != NUL)
            stuffReadbuff (p_fp);
        else
            stuffReadbuff ((char_u *) "fmt");
        stuffReadbuff ((char_u *) "\n']");
    }
}

static void op_function (oparg_T *oap) {
    char_u * (argv [1]);
    int save_virtual_op = virtual_op;
    if (*p_opfunc == NUL)
        EMSG (_ ("E774: 'operatorfunc' is empty"));
    else {
        curbuf->b_op_start = oap->start;
        curbuf->b_op_end = oap->end;
        if (oap->motion_type != MLINE && !oap->inclusive)
            decl (&curbuf->b_op_end);
        if (oap->block_mode)
            argv[0] = (char_u *) "block";
        else if (oap->motion_type == MLINE)
            argv[0] = (char_u *) "line";
        else
            argv[0] = (char_u *) "char";
        virtual_op = MAYBE;
        (void) call_func_retnr (p_opfunc, 1, argv, FALSE);
        virtual_op = save_virtual_op;
    }
}

int do_mouse (oparg_T *oap, int c, int dir, long  count, int fixindent) {
    static int do_always = FALSE;
    static int got_click = FALSE;
    int which_button;
    int is_click;
    int is_drag;
    int jump_flags = 0;
    pos_T start_visual;
    int moved;
    int in_status_line;
    static int in_tab_line = FALSE;
    int in_sep_line;
    int c1, c2;
    pos_T save_cursor;
    win_T *old_curwin = curwin;
    static pos_T orig_cursor;
    colnr_T leftcol, rightcol;
    pos_T end_visual;
    int diff;
    int old_active = VIsual_active;
    int old_mode = VIsual_mode;
    int regname;
    save_cursor = curwin->w_cursor;
    if (do_always)
        do_always = FALSE;
    else if (!gui.in_use) {
        if (VIsual_active) {
            if (!mouse_has (MOUSE_VISUAL))
                return FALSE;
        }
        else if (State == NORMAL && !mouse_has (MOUSE_NORMAL))
            return FALSE;
    }
    for (;;) {
        which_button = get_mouse_button (KEY2TERMCAP1 (c), &is_click, &is_drag);
        if (is_drag) {
            if (vpeekc () != NUL) {
                int nc;
                int save_mouse_row = mouse_row;
                int save_mouse_col = mouse_col;
                nc = safe_vgetc ();
                if (c == nc)
                    continue;
                vungetc (nc);
                mouse_row = save_mouse_row;
                mouse_col = save_mouse_col;
            }
        }
        break;
    }
    if (c == K_MOUSEMOVE) {
        ui_may_remove_balloon ();
        if (p_bevalterm && !VIsual_active) {
            profile_setlimit (p_bdlay, & bevalexpr_due);
            bevalexpr_due_set = TRUE;
        }
        return FALSE;
    }
    if (!is_drag && drag_status_line) {
        drag_status_line = FALSE;
        update_mouseshape (SHAPE_IDX_STATUS);
    }
    if (!is_drag && drag_sep_line) {
        drag_sep_line = FALSE;
        update_mouseshape (SHAPE_IDX_VSEP);
    }
    if (is_click)
        got_click = TRUE;
    else {
        if (!got_click)
            return FALSE;
        if (!is_drag) {
            got_click = FALSE;
            if (in_tab_line) {
                in_tab_line = FALSE;
                return FALSE;
            }
        }
    }
    if (is_click && (mod_mask & MOD_MASK_CTRL) && which_button == MOUSE_RIGHT) {
        if (State & INSERT)
            stuffcharReadbuff (Ctrl_O);
        if (count > 1)
            stuffnumReadbuff (count);
        stuffcharReadbuff (Ctrl_T);
        got_click = FALSE;
        return FALSE;
    }
    if ((mod_mask & MOD_MASK_CTRL) && which_button != MOUSE_LEFT)
        return FALSE;
    if ((mod_mask & (MOD_MASK_SHIFT | MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_META)) && (!is_click || (mod_mask & MOD_MASK_MULTI_CLICK) || which_button == MOUSE_MIDDLE) && !((mod_mask & (MOD_MASK_SHIFT | MOD_MASK_ALT)) && mouse_model_popup () && which_button == MOUSE_LEFT) && !((mod_mask & MOD_MASK_ALT) && !mouse_model_popup () && which_button == MOUSE_RIGHT))
        return FALSE;
    if (!is_click && which_button == MOUSE_MIDDLE)
        return FALSE;
    if (oap != NULL)
        regname = oap->regname;
    else
        regname = 0;
    if (which_button == MOUSE_MIDDLE) {
        if (State == NORMAL) {
            if (oap != NULL && oap->op_type != OP_NOP) {
                clearopbeep (oap);
                return FALSE;
            }
            if (VIsual_active) {
                if (VIsual_select) {
                    stuffcharReadbuff (Ctrl_G);
                    stuffReadbuff ((char_u *) "\"+p");
                }
                else {
                    stuffcharReadbuff ('y');
                    stuffcharReadbuff (K_MIDDLEMOUSE);
                }
                do_always = TRUE;
                return FALSE;
            }
        }
        else if ((State & INSERT) == 0)
            return FALSE;
        if ((State & INSERT) || !mouse_has (MOUSE_NORMAL)) {
            if (regname == '.')
                insert_reg (regname, TRUE);
            else {
                if ((State & REPLACE_FLAG) && !yank_register_mline (regname))
                    insert_reg (regname, TRUE);
                else {
                    do_put (regname, BACKWARD, 1L, fixindent | PUT_CURSEND);
                    AppendCharToRedobuff (Ctrl_R);
                    AppendCharToRedobuff (fixindent ? Ctrl_P : Ctrl_O);
                    AppendCharToRedobuff (regname == 0 ? '"' : regname);
                }
            }
            return FALSE;
        }
    }
    if (!is_click)
        jump_flags |= MOUSE_FOCUS | MOUSE_DID_MOVE;
    start_visual.lnum = 0;
    if (mouse_row == 0 && firstwin->w_winrow > 0) {
        if (is_drag) {
            if (in_tab_line) {
                c1 = TabPageIdxs[mouse_col];
                tabpage_move (c1 <= 0 ? 9999 : c1 < tabpage_index (curtab) ? c1 - 1 : c1);
            }
            return FALSE;
        }
        if (is_click && mouse_col < Columns) {
            in_tab_line = TRUE;
            c1 = TabPageIdxs[mouse_col];
            if (c1 >= 0) {
                if ((mod_mask & MOD_MASK_MULTI_CLICK) == MOD_MASK_2CLICK) {
                    end_visual_mode ();
                    tabpage_new ();
                    tabpage_move (c1 == 0 ? 9999 : c1 - 1);
                }
                else {
                    goto_tabpage (c1);
                    if (curwin != old_curwin)
                        end_visual_mode ();
                }
            }
            else if (c1 < 0) {
                tabpage_T *tp;
                if (c1 == -999)
                    tp = curtab;
                else
                    tp = find_tabpage (-c1);
                if (tp == curtab) {
                    if (first_tabpage->tp_next != NULL)
                        tabpage_close (FALSE);
                }
                else if (tp != NULL)
                    tabpage_close_other (tp, FALSE);
            }
        }
        return TRUE;
    }
    else if (is_drag && in_tab_line) {
        c1 = TabPageIdxs[mouse_col];
        tabpage_move (c1 <= 0 ? 9999 : c1 - 1);
        return FALSE;
    }
    if (mouse_model_popup ()) {
        if (which_button == MOUSE_RIGHT && !(mod_mask & (MOD_MASK_SHIFT | MOD_MASK_CTRL))) {
            if (!is_click)
                return FALSE;
            if (gui.in_use) {
                jump_flags = 0;
                if (STRCMP (p_mousem, "popup_setpos") == 0) {
                    if (VIsual_active) {
                        pos_T m_pos;
                        if (mouse_row < curwin->w_winrow || mouse_row > (curwin->w_winrow + curwin->w_height))
                            jump_flags = MOUSE_MAY_STOP_VIS;
                        else if (get_fpos_of_mouse (&m_pos) != IN_BUFFER)
                            jump_flags = MOUSE_MAY_STOP_VIS;
                        else {
                            if ((LT_POS (curwin->w_cursor, VIsual) && (LT_POS (m_pos, curwin->w_cursor) || LT_POS (VIsual, m_pos))) || (LT_POS (VIsual, curwin->w_cursor) && (LT_POS (m_pos, VIsual) || LT_POS (curwin->w_cursor, m_pos)))) {
                                jump_flags = MOUSE_MAY_STOP_VIS;
                            }
                            else if (VIsual_mode == Ctrl_V) {
                                getvcols (curwin, & curwin -> w_cursor, & VIsual, & leftcol, & rightcol);
                                getvcol (curwin, & m_pos, NULL, & m_pos.col, NULL);
                                if (m_pos.col < leftcol || m_pos.col > rightcol)
                                    jump_flags = MOUSE_MAY_STOP_VIS;
                            }
                        }
                    }
                    else
                        jump_flags = MOUSE_MAY_STOP_VIS;
                }
                if (jump_flags) {
                    jump_flags = jump_to_mouse (jump_flags, NULL, which_button);
                    update_curbuf (VIsual_active ? INVERTED : VALID);
                    setcursor ();
                    out_flush ();
                }
                gui_show_popupmenu ();
                return (jump_flags & CURSOR_MOVED) != 0;
            }
            else
                return FALSE;
        }
        if (which_button == MOUSE_LEFT && (mod_mask & (MOD_MASK_SHIFT | MOD_MASK_ALT))) {
            which_button = MOUSE_RIGHT;
            mod_mask &= ~MOD_MASK_SHIFT;
        }
    }
    if ((State & (NORMAL | INSERT)) && !(mod_mask & (MOD_MASK_SHIFT | MOD_MASK_CTRL))) {
        if (which_button == MOUSE_LEFT) {
            if (is_click) {
                if (VIsual_active)
                    jump_flags |= MOUSE_MAY_STOP_VIS;
            }
            else if (mouse_has (MOUSE_VISUAL))
                jump_flags |= MOUSE_MAY_VIS;
        }
        else if (which_button == MOUSE_RIGHT) {
            if (is_click && VIsual_active) {
                if (LT_POS (curwin->w_cursor, VIsual)) {
                    start_visual = curwin->w_cursor;
                    end_visual = VIsual;
                }
                else {
                    start_visual = VIsual;
                    end_visual = curwin->w_cursor;
                }
            }
            jump_flags |= MOUSE_FOCUS;
            if (mouse_has (MOUSE_VISUAL))
                jump_flags |= MOUSE_MAY_VIS;
        }
    }
    if (!is_drag && oap != NULL && oap->op_type != OP_NOP) {
        got_click = FALSE;
        oap->motion_type = MCHAR;
    }
    if (!is_click && !is_drag)
        jump_flags |= MOUSE_RELEASED;
    jump_flags = jump_to_mouse (jump_flags, oap == NULL ? NULL : &(oap->inclusive), which_button);
    if (jump_flags & MOUSE_WINBAR)
        return FALSE;
    moved = (jump_flags & CURSOR_MOVED);
    in_status_line = (jump_flags & IN_STATUS_LINE);
    in_sep_line = (jump_flags & IN_SEP_LINE);
    if (isNetbeansBuffer (curbuf) && !(jump_flags & (IN_STATUS_LINE | IN_SEP_LINE))) {
        int key = KEY2TERMCAP1 (c);
        if (key == (int) KE_LEFTRELEASE || key == (int) KE_MIDDLERELEASE || key == (int) KE_RIGHTRELEASE)
            netbeans_button_release (which_button);
    }
    if (curwin != old_curwin && oap != NULL && oap->op_type != OP_NOP)
        clearop (oap);
    if (mod_mask == 0 && !is_drag && (jump_flags & (MOUSE_FOLD_CLOSE | MOUSE_FOLD_OPEN)) && which_button == MOUSE_LEFT) {
        if (jump_flags & MOUSE_FOLD_OPEN)
            openFold (curwin->w_cursor.lnum, 1L);
        else
            closeFold (curwin->w_cursor.lnum, 1L);
        if (curwin == old_curwin)
            curwin->w_cursor = save_cursor;
    }
    if (VIsual_active && is_drag && p_so) {
        if (mouse_row == 0)
            mouse_dragging = 2;
        else
            mouse_dragging = 1;
    }
    if (is_drag && mouse_row < 0 && !in_status_line) {
        scroll_redraw (FALSE, 1L);
        mouse_row = 0;
    }
    if (start_visual.lnum) {
        if (mod_mask & MOD_MASK_ALT)
            VIsual_mode = Ctrl_V;
        if (VIsual_mode == Ctrl_V) {
            getvcols (curwin, & start_visual, & end_visual, & leftcol, & rightcol);
            if (curwin->w_curswant > (leftcol + rightcol) / 2)
                end_visual.col = leftcol;
            else
                end_visual.col = rightcol;
            if (curwin->w_cursor.lnum >= (start_visual.lnum + end_visual.lnum) / 2)
                end_visual.lnum = start_visual.lnum;
            start_visual = curwin->w_cursor;
            curwin->w_cursor = end_visual;
            coladvance (end_visual.col);
            VIsual = curwin->w_cursor;
            curwin->w_cursor = start_visual;
        }
        else {
            if (LT_POS (curwin->w_cursor, start_visual))
                VIsual = end_visual;
            else if (LT_POS (end_visual, curwin->w_cursor))
                VIsual = start_visual;
            else {
                if (end_visual.lnum == start_visual.lnum) {
                    if (curwin->w_cursor.col - start_visual.col > end_visual.col - curwin->w_cursor.col)
                        VIsual = start_visual;
                    else
                        VIsual = end_visual;
                }
                else {
                    diff = (curwin->w_cursor.lnum - start_visual.lnum) - (end_visual.lnum - curwin->w_cursor.lnum);
                    if (diff > 0)
                        VIsual = start_visual;
                    else if (diff < 0)
                        VIsual = end_visual;
                    else {
                        if (curwin->w_cursor.col < (start_visual.col + end_visual.col) / 2)
                            VIsual = end_visual;
                        else
                            VIsual = start_visual;
                    }
                }
            }
        }
    }
    else if ((State & INSERT) && VIsual_active)
        stuffcharReadbuff (Ctrl_O);
    if (which_button == MOUSE_MIDDLE) {
        if (yank_register_mline (regname)) {
            if (mouse_past_bottom)
                dir = FORWARD;
        }
        else if (mouse_past_eol)
            dir = FORWARD;
        if (fixindent) {
            c1 = (dir == BACKWARD) ? '[' : ']';
            c2 = 'p';
        }
        else {
            c1 = (dir == FORWARD) ? 'p' : 'P';
            c2 = NUL;
        }
        prep_redo (regname, count, NUL, c1, NUL, c2, NUL);
        if (restart_edit != 0)
            where_paste_started = curwin->w_cursor;
        do_put (regname, dir, count, fixindent | PUT_CURSEND);
    }
    else if (((mod_mask & MOD_MASK_CTRL) || (mod_mask & MOD_MASK_MULTI_CLICK) == MOD_MASK_2CLICK) && bt_quickfix (curbuf)) {
        if (curwin->w_llist_ref == NULL)
            do_cmdline_cmd ((char_u *) ".cc");
        else
            do_cmdline_cmd ((char_u *) ".ll");
        got_click = FALSE;
    }
    else if ((mod_mask & MOD_MASK_CTRL) || (curbuf->b_help && (mod_mask & MOD_MASK_MULTI_CLICK) == MOD_MASK_2CLICK)) {
        if (State & INSERT)
            stuffcharReadbuff (Ctrl_O);
        stuffcharReadbuff (Ctrl_RSB);
        got_click = FALSE;
    }
    else if ((mod_mask & MOD_MASK_SHIFT)) {
        if ((State & INSERT) || (VIsual_active && VIsual_select))
            stuffcharReadbuff (Ctrl_O);
        if (which_button == MOUSE_LEFT)
            stuffcharReadbuff ('*');
        else
            stuffcharReadbuff ('#');
    }
    else if (in_status_line) {
        if ((is_drag || is_click) && !drag_status_line) {
            drag_status_line = TRUE;
            update_mouseshape (- 1);
        }
    }
    else if (in_sep_line) {
        if ((is_drag || is_click) && !drag_sep_line) {
            drag_sep_line = TRUE;
            update_mouseshape (- 1);
        }
    }
    else if ((mod_mask & MOD_MASK_MULTI_CLICK) && (State & (NORMAL | INSERT)) && mouse_has (MOUSE_VISUAL)) {
        if (is_click || !VIsual_active) {
            if (VIsual_active)
                orig_cursor = VIsual;
            else {
                check_visual_highlight ();
                VIsual = curwin->w_cursor;
                orig_cursor = VIsual;
                VIsual_active = TRUE;
                VIsual_reselect = TRUE;
                may_start_select ('o');
                setmouse ();
            }
            if ((mod_mask & MOD_MASK_MULTI_CLICK) == MOD_MASK_2CLICK) {
                if (mod_mask & MOD_MASK_ALT)
                    VIsual_mode = Ctrl_V;
                else
                    VIsual_mode = 'v';
            }
            else if ((mod_mask & MOD_MASK_MULTI_CLICK) == MOD_MASK_3CLICK)
                VIsual_mode = 'V';
            else if ((mod_mask & MOD_MASK_MULTI_CLICK) == MOD_MASK_4CLICK)
                VIsual_mode = Ctrl_V;
        }
        if ((mod_mask & MOD_MASK_MULTI_CLICK) == MOD_MASK_2CLICK) {
            pos_T *pos = NULL;
            int gc;
            if (is_click) {
                end_visual = curwin->w_cursor;
                while (gc = gchar_pos (&end_visual), VIM_ISWHITE (gc))
                    inc (&end_visual);
                if (oap != NULL)
                    oap->motion_type = MCHAR;
                if (oap != NULL && VIsual_mode == 'v' && !vim_iswordc (gchar_pos (&end_visual)) && EQUAL_POS (curwin->w_cursor, VIsual) && (pos = findmatch (oap, NUL)) != NULL) {
                    curwin->w_cursor = *pos;
                    if (oap->motion_type == MLINE)
                        VIsual_mode = 'V';
                    else if (*p_sel == 'e') {
                        if (LT_POS (curwin->w_cursor, VIsual))
                            ++VIsual.col;
                        else
                            ++curwin->w_cursor.col;
                    }
                }
            }
            if (pos == NULL && (is_click || is_drag)) {
                if (LT_POS (curwin->w_cursor, orig_cursor)) {
                    find_start_of_word (& curwin -> w_cursor);
                    find_end_of_word (& VIsual);
                }
                else {
                    find_start_of_word (& VIsual);
                    if (*p_sel == 'e' && *ml_get_cursor () != NUL)
                        ++curwin->w_cursor.col;
                    find_end_of_word (& curwin -> w_cursor);
                }
            }
            curwin->w_set_curswant = TRUE;
        }
        if (is_click)
            redraw_curbuf_later (INVERTED);
    }
    else if (VIsual_active && !old_active) {
        if (mod_mask & MOD_MASK_ALT)
            VIsual_mode = Ctrl_V;
        else
            VIsual_mode = 'v';
    }
    if ((!VIsual_active && old_active && mode_displayed) || (VIsual_active && p_smd && msg_silent == 0 && (!old_active || VIsual_mode != old_mode)))
        redraw_cmdline = TRUE;
    return moved;
}

