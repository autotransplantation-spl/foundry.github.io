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
struct ml_chunksize {
    int mlcs_numlines;
    long  mlcs_totalsize;
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
struct u_entry {
    u_entry_T *ue_next;
    linenr_T ue_top;
    linenr_T ue_bot;
    linenr_T ue_lcount;
    char_u **ue_array;
    long  ue_size;
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
struct block0 {
    char_u b0_id [2];
    char_u b0_version [10];
    char_u b0_page_size [4];
    char_u b0_mtime [4];
    char_u b0_ino [4];
    char_u b0_pid [4];
    char_u b0_uname [B0_UNAME_SIZE];
    char_u b0_hname [B0_HNAME_SIZE];
    char_u b0_fname [B0_FNAME_SIZE_ORG];
    long  b0_magic_long;
    int b0_magic_int;
    short  b0_magic_short;
    char_u b0_magic_char;
};
struct data_block {
    short_u db_id;
    unsigned  db_free;
    unsigned  db_txt_start;
    unsigned  db_txt_end;
    linenr_T db_line_count;
    unsigned  db_index [1];
};
struct pointer_block {
    short_u pb_id;
    short_u pb_count;
    short_u pb_count_max;
    PTR_EN pb_pointer [1];
};
struct pointer_entry {
    blocknr_T pe_bnum;
    linenr_T pe_line_count;
    linenr_T pe_old_lnum;
    int pe_page_count;
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
struct mf_hashitem_S {
    mf_hashitem_T *mhi_next;
    mf_hashitem_T *mhi_prev;
    blocknr_T mhi_key;
};
struct xfilemark {
    fmark_T fmark;
    char_u *fname;
    time_T time_set;
};
struct arglist {
    garray_T al_ga;
    int al_refcount;
    int id;
};
struct vim_exception {
    except_type_T type;
    char_u *value;
    struct msglist *messages;
    char_u *throw_name;
    linenr_T throw_lnum;
    except_T *caught;
};
struct filemark {
    pos_T mark;
    int fnum;
};
struct mf_hashtab_S {
    long_u mht_mask;
    long_u mht_count;
    mf_hashitem_T **mht_buckets;
    mf_hashitem_T *mht_small_buckets [MHT_INIT_SIZE];
    char mht_fixed;
};
EXTERN char_u *NameBuff;
EXTERN char_u *p_shm;
EXTERN char_u *p_dir;
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
EXTERN win_T *au_pending_free_win INIT (= NULL);
EXTERN tabpage_T *first_tabpage;
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
int process_still_running;
EXTERN proftime_T bevalexpr_due;
EXTERN char_u e_invexpr2 [] INIT (= N_ ("E15: Invalid expression: %s"));
EXTERN char_u *p_pexpr;
EXTERN char_u *p_bexpr;
EXTERN int arrow_used;
EXTERN int mouse_row;
EXTERN int cmdline_row;
EXTERN char_u e_invargval [] INIT (= N_ ("E475: Invalid value for argument %s"));
EXTERN unsigned  swb_flags;
EXTERN int stop_insert_mode;
EXTERN pos_T where_paste_started;
EXTERN char *font_argument INIT (= NULL);
EXTERN int p_guipty;
EXTERN char_u *p_guifont;
EXTERN hlf_T edit_submode_highl;
EXTERN int p_hls;
EXTERN char_u *p_hl;
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
EXTERN except_T *current_exception;
EXTERN int p_secure;
EXTERN char_u e_bufloaded [] INIT (= N_ ("E139: File is loaded in another buffer"));
EXTERN char_u e_nobufnr [] INIT (= N_ ("E86: Buffer %ld does not exist"));
EXTERN char_u e_emptybuf [] INIT (= N_ ("E749: empty buffer"));
EXTERN char_u e_notmp [] INIT (= N_ ("E483: Can't get temp file name"));
EXTERN pos_T last_cursormoved;
EXTERN char_u *IObuff;
EXTERN buf_T *curbuf INIT (= NULL);
EXTERN buf_T *lastbuf INIT (= NULL);
EXTERN buf_T *firstbuf INIT (= NULL);
EXTERN buf_T *au_pending_free_buf INIT (= NULL);
EXTERN int highlight_attr [HLF_COUNT];
EXTERN long  p_ttm;
EXTERN long  p_tm;
EXTERN int p_stmp;
EXTERN int p_lrm;
EXTERN int p_confirm;
EXTERN int p_bevalterm;
const int command_count = 546;
EXTERN char_u e_zerocount [] INIT (= N_ ("E939: Positive count required"));
EXTERN char_u e_nomatch2 [] INIT (= N_ ("E480: No match: %s"));
EXTERN char_u e_nomatch [] INIT (= N_ ("E479: No match"));
EXTERN char_u *autocmd_match INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_out INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_in INIT (= NULL);
EXTERN linenr_T search_match_lines;
EXTERN char need_key_msg [] INIT (= N_ ("Need encryption key for \"%s\""));
EXTERN char bot_top_msg [] INIT (= N_ ("search hit BOTTOM, continuing at TOP"));
EXTERN char top_bot_msg [] INIT (= N_ ("search hit TOP, continuing at BOTTOM"));
EXTERN char_u e_invexprmsg [] INIT (= N_ ("E449: Invalid expression received"));
EXTERN char_u no_lines_msg [] INIT (= N_ ("--No lines in buffer--"));
EXTERN char_u msg_buf [MSG_BUF_LEN];
EXTERN struct msglist **msg_list INIT (= NULL);
EXTERN int called_emsg;
EXTERN char_u *keep_msg INIT (= NULL);
EXTERN int msg_scrolled;
EXTERN int msg_row;
EXTERN int searchcmdlen;
EXTERN long  p_titlelen;
EXTERN int autocmd_fname_full;
EXTERN char_u *autocmd_fname INIT (= NULL);
EXTERN int sc_col;
EXTERN int ru_col;
EXTERN int mouse_col;
EXTERN colnr_T search_match_endcol;
EXTERN int msg_col;
EXTERN int p_cc_cols [256];
EXTERN long  p_columnspace;
EXTERN int fuoptions_bgcolor;
const unsigned  char cmdidxs2 [26] [26] = {{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 6, 0, 0, 0, 7, 15, 0, 16, 0, 0, 0, 0, 0}, {2, 0, 0, 4, 5, 7, 0, 0, 0, 0, 0, 8, 9, 10, 11, 12, 0, 13, 0, 0, 0, 0, 22, 0, 0, 0}, {3, 10, 12, 14, 16, 18, 21, 0, 0, 0, 0, 29, 33, 36, 42, 51, 53, 54, 55, 0, 57, 0, 60, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 6, 15, 0, 16, 0, 0, 17, 0, 0, 19, 20, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 7, 9, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 4, 5, 0, 0, 0, 0}, {5, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 3, 0, 0, 0, 4, 0, 5, 6, 0, 0, 0, 0, 0, 13, 0, 15, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {3, 9, 11, 15, 16, 20, 23, 28, 0, 0, 0, 30, 33, 36, 40, 46, 0, 48, 57, 49, 50, 54, 56, 0, 0, 0}, {1, 0, 0, 0, 9, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 8, 10, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 5, 0, 0, 0, 0, 0, 0, 9, 0, 11, 0, 0, 0}, {1, 0, 3, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 9, 0, 0, 16, 17, 26, 0, 27, 0, 28, 0}, {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 18, 0, 0, 0, 0}, {2, 6, 15, 0, 18, 22, 0, 24, 25, 0, 0, 28, 30, 34, 38, 40, 0, 48, 0, 49, 0, 61, 62, 0, 63, 0}, {2, 0, 19, 0, 22, 24, 0, 25, 0, 26, 0, 27, 28, 31, 33, 34, 0, 35, 37, 0, 38, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 9, 12, 0, 0, 0, 0, 15, 0, 16, 0, 0, 0, 0, 0}, {2, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 0, 8, 0, 9, 10, 0, 12, 0, 13, 14, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
const unsigned  short  cmdidxs1 [26] = {0, 19, 42, 103, 125, 145, 161, 167, 176, 194, 196, 201, 259, 279, 299, 311, 350, 353, 372, 439, 479, 490, 508, 523, 532, 533};
EXTERN char_u e_invalidreg [] INIT (= N_ ("E850: Invalid register name"));
EXTERN char_u e_usingsid [] INIT (= N_ ("E81: Using <SID> not in a script context"));
EXTERN char_u e_winwidth [] INIT (= N_ ("E592: 'winwidth' cannot be smaller than 'winminwidth'"));
EXTERN char_u e_listidx [] INIT (= N_ ("E684: list index out of range: %ld"));
EXTERN int ru_wid;
EXTERN int did_emsg_syntax;
EXTERN int did_emsg;
EXTERN int p_tbidi;
EXTERN int p_hid;
int id1_codes [] = {BLOCK0_ID1_C0, BLOCK0_ID1_C1, BLOCK0_ID1_C2,};
EXTERN typebuf_T typebuf;
EXTERN long_u scrollbar_value;
EXTERN except_T *caught_stack INIT (= NULL);
EXTERN int did_uncaught_emsg;
EXTERN char_u e_umark [] INIT (= N_ ("E78: Unknown mark"));
EXTERN char_u e_marknotset [] INIT (= N_ ("E20: Mark not set"));
EXTERN char_u e_markinval [] INIT (= N_ ("E19: Mark has invalid line number"));
EXTERN pos_T Insstart_orig;
EXTERN pos_T Insstart;
EXTERN pos_T VIsual;
linenr_T lowest_marked = 0;
EXTERN int p_hkmap;
EXTERN int p_hkmapp;
EXTERN char_u *p_lcs;
EXTERN long  p_linespace;
EXTERN char_u *p_km;
EXTERN time_T starttime;

void ml_open_file (buf_T *buf) {
    memfile_T *mfp;
    char_u *fname;
    char_u *dirp;
    mfp = buf->b_ml.ml_mfp;
    if (mfp == NULL || mfp->mf_fd >= 0 || !buf->b_p_swf || cmdmod.noswapfile)
        return;
    dirp = p_dir;
    for (;;) {
        if (*dirp == NUL)
            break;
        fname = findswapname (buf, &dirp, NULL);
        if (dirp == NULL)
            break;
        if (fname == NULL)
            continue;
        if (mf_open_file (mfp, fname) == OK) {
            ml_upd_block0 (buf, UB_SAME_DIR);
            if (mf_sync (mfp, MFS_ZERO) == OK) {
                mf_set_dirty (mfp);
                break;
            }
            mf_close_file (buf, FALSE);
        }
    }
    if (mfp->mf_fname == NULL) {
        need_wait_return = TRUE;
        ++no_wait_return;
        (void) EMSG2 (_ ("E303: Unable to open swap file for \"%s\", recovery impossible"), buf_spname (buf) != NULL ? buf_spname (buf) : buf->b_fname);
        --no_wait_return;
    }
    buf->b_may_swap = FALSE;
}

static char_u *findswapname (buf_T *buf, char_u **dirp, char_u *old_fname) {
    char_u *fname;
    int n;
    char_u *dir_name;
    int r;
    char_u *buf_fname = buf->b_fname;
    dir_name = alloc ((unsigned ) STRLEN (*dirp) + 1);
    if (dir_name == NULL)
        *dirp = NULL;
    else
        (void) copy_option_part (dirp, dir_name, 31000, ",");
    if (dir_name == NULL)
        fname = NULL;
    else
        fname = makeswapname (buf_fname, buf->b_ffname, buf, dir_name);
    for (;;) {
        if (fname == NULL)
            break;
        if ((n = (int) STRLEN (fname)) == 0) {
            VIM_CLEAR (fname);
            break;
        }
        if (fname[n - 2] == 'w' && fname[n - 1] == 'p' && !(buf->b_p_sn || buf->b_shortname)) {
            char_u *tail;
            char_u *fname2;
            stat_T s1, s2;
            int f1, f2;
            int created1 = FALSE, created2 = FALSE;
            int same = FALSE;
            tail = gettail (buf_fname);
            if (vim_strchr (tail, '.') != NULL || STRLEN (tail) > (size_t) 8 || *gettail (fname) == '.') {
                fname2 = alloc (n +2);
                if (fname2 != NULL) {
                    STRCPY (fname2, fname);
                    if (vim_strchr (tail, '.') != NULL)
                        fname2[n - 1] = 'x';
                    else if (*gettail (fname) == '.') {
                        fname2[n] = 'x';
                        fname2[n + 1] = NUL;
                    }
                    else
                        fname2[n - 5] += 1;
                    f1 = mch_open ((char *) fname, O_RDONLY | O_EXTRA, 0);
                    if (f1 < 0) {
                        f1 = mch_open_rw ((char *) fname, O_RDWR | O_CREAT | O_EXCL | O_EXTRA);
                        created1 = TRUE;
                    }
                    if (f1 >= 0) {
                        f2 = mch_open ((char *) fname2, O_RDONLY | O_EXTRA, 0);
                        if (f2 < 0) {
                            f2 = mch_open_rw ((char *) fname2, O_RDWR | O_CREAT | O_EXCL | O_EXTRA);
                            created2 = TRUE;
                        }
                        if (f2 >= 0) {
                            if (mch_fstat (f1, &s1) != -1 && mch_fstat (f2, &s2) != -1 && s1.st_dev == s2.st_dev && s1.st_ino == s2.st_ino)
                                same = TRUE;
                            close (f2);
                            if (created2)
                                mch_remove (fname2);
                        }
                        close (f1);
                        if (created1)
                            mch_remove (fname);
                    }
                    vim_free (fname2);
                    if (same) {
                        buf->b_shortname = TRUE;
                        vim_free (fname);
                        fname = makeswapname (buf_fname, buf->b_ffname, buf, dir_name);
                        continue;
                    }
                }
            }
        }
        if (mch_getperm (fname) < 0) {
            break;
        }
        if (old_fname != NULL && fnamecmp (fname, old_fname) == 0)
            break;
        if (fname[n - 2] == 'w' && fname[n - 1] == 'p') {
            if (!(buf->b_p_sn || buf->b_shortname)) {
                fname[n - 1] = 'x';
                r = mch_getperm (fname);
                fname[n - 1] = 'p';
                if (r >= 0) {
                    buf->b_shortname = TRUE;
                    vim_free (fname);
                    fname = makeswapname (buf_fname, buf->b_ffname, buf, dir_name);
                    continue;
                }
            }
            if (!recoverymode && buf_fname != NULL && !buf->b_help && !(buf->b_flags & BF_DUMMY)) {
                int fd;
                struct block0 b0;
                int differ = FALSE;
                fd = mch_open ((char *) fname, O_RDONLY | O_EXTRA, 0);
                if (fd >= 0) {
                    if (read_eintr (fd, &b0, sizeof (b0)) == sizeof (b0)) {
                        if (b0.b0_flags & B0_SAME_DIR) {
                            if (fnamecmp (gettail (buf->b_ffname), gettail (b0.b0_fname)) != 0 || !same_directory (fname, buf->b_ffname)) {
                                differ = TRUE;
                            }
                        }
                        else {
                            expand_env (b0.b0_fname, NameBuff, MAXPATHL);
                            if (fnamecmp (NameBuff, buf->b_ffname) != 0)
                                differ = TRUE;
                        }
                    }
                    close (fd);
                }
                if (differ == FALSE && !(curbuf->b_flags & BF_RECOVERED) && vim_strchr (p_shm, SHM_ATTENTION) == NULL) {
                    process_still_running = FALSE;
                    if (swap_exists_action != SEA_NONE && has_autocmd (EVENT_SWAPEXISTS, buf_fname, buf))
                        choice = do_swapexists (buf, fname);
                    if (choice == 0) {
                        if (gui.starting && !gui.in_use)
                            gui_start ();
                        attention_message (buf, fname);
                        got_int = FALSE;
                    }
                    if (swap_exists_action != SEA_NONE && choice == 0) {
                        char_u *name;
                        name = alloc ((unsigned ) (STRLEN (fname) + STRLEN (_ ("Swap file \"")) + STRLEN (_ ("\" already exists!")) + 5));
                        if (name != NULL) {
                            STRCPY (name, _ ("Swap file \""));
                            home_replace (NULL, fname, name + STRLEN (name), 1000, TRUE);
                            STRCAT (name, _ ("\" already exists!"));
                        }
                        choice = do_dialog (VIM_WARNING, (char_u *) _ ("VIM - ATTENTION"), name == NULL ? (char_u *) _ ("Swap file already exists!") : name, process_still_running ? (char_u *) _ ("&Open Read-Only\n&Edit anyway\n&Recover\n&Quit\n&Abort") : (char_u *) _ ("&Open Read-Only\n&Edit anyway\n&Recover\n&Delete it\n&Quit\n&Abort"), 1, NULL, FALSE);
                        if (process_still_running && choice >= 4)
                            choice++;
                        vim_free (name);
                        msg_scrolled = 0;
                        redraw_all_later (NOT_VALID);
                    }
                    {
                        MSG_PUTS ("\n");
                        if (msg_silent == 0)
                            need_wait_return = TRUE;
                    }
                }
            }
        }
        if (fname[n - 1] == 'a') {
            if (fname[n - 2] == 'a') {
                EMSG (_ ("E326: Too many swap files found"));
                VIM_CLEAR (fname);
                break;
            }
            --fname[n - 2];
            fname[n - 1] = 'z' + 1;
        }
        --fname[n - 1];
    }
    vim_free (dir_name);
    return fname;
}

char_u *makeswapname (char_u *fname, char_u *ffname, buf_T *buf, char_u *dir_name) {
    char_u *r, *s;
    char_u *fname_res = fname;
    int len = (int) STRLEN (dir_name);
    s = dir_name + len;
    if (after_pathsep (dir_name, s) && len > 1 && s[-1] == s[-2]) {
        r = NULL;
        if ((s = make_percent_swname (dir_name, fname)) != NULL) {
            r = modname (s, (char_u *) ".swp", FALSE);
            vim_free (s);
        }
        return r;
    }
    r = buf_modname ((buf->b_p_sn || buf->b_shortname), fname_res, (char_u *) ".swp", dir_name[0] == '.' && dir_name[1] == NUL);
    if (r == NULL)
        return NULL;
    s = get_file_in_dir (r, dir_name);
    vim_free (r);
    return s;
}

static char_u *make_percent_swname (char_u *dir, char_u *name) {
    char_u *d, *s, *f;
    f = fix_fname (name != NULL ? name : (char_u *) "");
    d = NULL;
    if (f != NULL) {
        s = alloc ((unsigned ) (STRLEN (f) + 1));
        if (s != NULL) {
            STRCPY (s, f);
            for (d = s; *d != NUL; MB_PTR_ADV (d))
                if (vim_ispathsep (*d))
                    *d = '%';
            d = concat_fnames (dir, s, TRUE);
            vim_free (s);
        }
        vim_free (f);
    }
    return d;
}

char_u *get_file_in_dir (char_u *fname, char_u *dname) {
    char_u *t;
    char_u *tail;
    char_u *retval;
    int save_char;
    tail = gettail (fname);
    if (dname[0] == '.' && dname[1] == NUL)
        retval = vim_strsave (fname);
    else if (dname[0] == '.' && vim_ispathsep (dname[1])) {
        if (tail == fname)
            retval = concat_fnames (dname +2, tail, TRUE);
        else {
            save_char = *tail;
            *tail = NUL;
            t = concat_fnames (fname, dname +2, TRUE);
            *tail = save_char;
            if (t == NULL)
                retval = NULL;
            else {
                retval = concat_fnames (t, tail, TRUE);
                vim_free (t);
            }
        }
    }
    else
        retval = concat_fnames (dname, tail, TRUE);
    return retval;
}

void ml_sync_all (int check_file, int check_char) {
    buf_T *buf;
    stat_T st;
    FOR_ALL_BUFFERS (buf) {
        if (buf->b_ml.ml_mfp == NULL || buf->b_ml.ml_mfp->mf_fname == NULL)
            continue;
        ml_flush_line (buf);
        (void) ml_find_line (buf, (linenr_T) 0, ML_FLUSH);
        if (bufIsChanged (buf) && check_file && mf_need_trans (buf->b_ml.ml_mfp) && buf->b_ffname != NULL) {
            if (mch_stat ((char *) buf->b_ffname, &st) == -1 || st.st_mtime != buf->b_mtime_read || st.st_size != buf->b_orig_size) {
                ml_preserve (buf, FALSE);
                did_check_timestamps = FALSE;
                need_check_timestamps = TRUE;
            }
        }
        if (buf->b_ml.ml_mfp->mf_dirty) {
            (void) mf_sync (buf->b_ml.ml_mfp, (check_char ? MFS_STOP : 0) | (bufIsChanged (buf) ? MFS_FLUSH : 0));
            if (check_char && ui_char_avail ())
                break;
        }
    }
}

static void ml_flush_line (buf_T *buf) {
    bhdr_T *hp;
    DATA_BL *dp;
    linenr_T lnum;
    char_u *new_line;
    char_u *old_line;
    colnr_T new_len;
    int old_len;
    int extra;
    int idx;
    int start;
    int count;
    int i;
    static int entered = FALSE;
    if (buf->b_ml.ml_line_lnum == 0 || buf->b_ml.ml_mfp == NULL)
        return;
    if (buf->b_ml.ml_flags & ML_LINE_DIRTY) {
        if (entered)
            return;
        entered = TRUE;
        lnum = buf->b_ml.ml_line_lnum;
        new_line = buf->b_ml.ml_line_ptr;
        hp = ml_find_line (buf, lnum, ML_FIND);
        if (hp == NULL)
            IEMSGN (_ ("E320: Cannot find line %ld"), lnum);
        else {
            dp = (DATA_BL *) (hp->bh_data);
            idx = lnum - buf->b_ml.ml_locked_low;
            start = ((dp->db_index[idx]) & DB_INDEX_MASK);
            old_line = (char_u *) dp + start;
            if (idx == 0)
                old_len = dp->db_txt_end - start;
            else
                old_len = (dp->db_index[idx - 1] & DB_INDEX_MASK) - start;
            new_len = (colnr_T) STRLEN (new_line) + 1;
            extra = new_len - old_len;
            if ((int) dp->db_free >= extra) {
                count = buf->b_ml.ml_locked_high - buf->b_ml.ml_locked_low + 1;
                if (extra != 0 && idx < count - 1) {
                    mch_memmove ((char *) dp + dp -> db_txt_start - extra, (char *) dp + dp -> db_txt_start, (size_t) (start - dp -> db_txt_start));
                    for (i = idx + 1; i < count; ++i)
                        dp->db_index[i] -= extra;
                }
                dp->db_index[idx] -= extra;
                dp->db_free -= extra;
                dp->db_txt_start -= extra;
                mch_memmove (old_line - extra, new_line, (size_t) new_len);
                buf->b_ml.ml_flags |= (ML_LOCKED_DIRTY | ML_LOCKED_POS);
                ml_updatechunk (buf, lnum, (long) extra, ML_CHNK_UPDLINE);
            }
            else {
                (void) ml_append_int (buf, lnum, new_line, new_len, FALSE, (dp->db_index[idx] & DB_MARKED));
                (void) ml_delete_int (buf, lnum, FALSE);
            }
        }
        vim_free (new_line);
        entered = FALSE;
    }
    buf->b_ml.ml_line_lnum = 0;
}

static bhdr_T *ml_find_line (buf_T *buf, linenr_T lnum, int action) {
    DATA_BL *dp;
    PTR_BL *pp;
    infoptr_T *ip;
    bhdr_T *hp;
    memfile_T *mfp;
    linenr_T t;
    blocknr_T bnum, bnum2;
    int dirty;
    linenr_T low, high;
    int top;
    int page_count;
    int idx;
    mfp = buf->b_ml.ml_mfp;
    if (buf->b_ml.ml_locked) {
        if (ML_SIMPLE (action) && buf->b_ml.ml_locked_low <= lnum && buf->b_ml.ml_locked_high >= lnum && !mf_dont_release) {
            if (action == ML_INSERT) {
                ++(buf->b_ml.ml_locked_lineadd);
                ++(buf->b_ml.ml_locked_high);
            }
            else if (action == ML_DELETE) {
                --(buf->b_ml.ml_locked_lineadd);
                --(buf->b_ml.ml_locked_high);
            }
            return (buf->b_ml.ml_locked);
        }
        mf_put (mfp, buf -> b_ml.ml_locked, buf -> b_ml.ml_flags & ML_LOCKED_DIRTY, buf -> b_ml.ml_flags & ML_LOCKED_POS);
        buf->b_ml.ml_locked = NULL;
        if (buf->b_ml.ml_locked_lineadd != 0)
            ml_lineadd (buf, buf->b_ml.ml_locked_lineadd);
    }
    if (action == ML_FLUSH)
        return NULL;
    bnum = 1;
    page_count = 1;
    low = 1;
    high = buf->b_ml.ml_line_count;
    if (action == ML_FIND) {
        for (top = buf->b_ml.ml_stack_top - 1; top >= 0; --top) {
            ip = &(buf->b_ml.ml_stack[top]);
            if (ip->ip_low <= lnum && ip->ip_high >= lnum) {
                bnum = ip->ip_bnum;
                low = ip->ip_low;
                high = ip->ip_high;
                buf->b_ml.ml_stack_top = top;
                break;
            }
        }
        if (top < 0)
            buf->b_ml.ml_stack_top = 0;
    }
    else
        buf->b_ml.ml_stack_top = 0;
    for (;;) {
        if ((hp = mf_get (mfp, bnum, page_count)) == NULL)
            goto error_noblock;
        if (action == ML_INSERT)
            ++high;
        else if (action == ML_DELETE)
            --high;
        dp = (DATA_BL *) (hp->bh_data);
        if (dp->db_id == DATA_ID) {
            buf->b_ml.ml_locked = hp;
            buf->b_ml.ml_locked_low = low;
            buf->b_ml.ml_locked_high = high;
            buf->b_ml.ml_locked_lineadd = 0;
            buf->b_ml.ml_flags &= ~(ML_LOCKED_DIRTY | ML_LOCKED_POS);
            return hp;
        }
        pp = (PTR_BL *) (dp);
        if (pp->pb_id != PTR_ID) {
            IEMSG (_ ("E317: pointer block id wrong"));
            goto error_block;
        }
        if ((top = ml_add_stack (buf)) < 0)
            goto error_block;
        ip = &(buf->b_ml.ml_stack[top]);
        ip->ip_bnum = bnum;
        ip->ip_low = low;
        ip->ip_high = high;
        ip->ip_index = -1;
        dirty = FALSE;
        for (idx = 0; idx < (int) pp->pb_count; ++idx) {
            t = pp->pb_pointer[idx].pe_line_count;
            CHECK (t == 0, _ ("pe_line_count is zero"));
            if ((low += t) > lnum) {
                ip->ip_index = idx;
                bnum = pp->pb_pointer[idx].pe_bnum;
                page_count = pp->pb_pointer[idx].pe_page_count;
                high = low - 1;
                low -= t;
                if (bnum < 0) {
                    bnum2 = mf_trans_del (mfp, bnum);
                    if (bnum != bnum2) {
                        bnum = bnum2;
                        pp->pb_pointer[idx].pe_bnum = bnum;
                        dirty = TRUE;
                    }
                }
                break;
            }
        }
        if (idx >= (int) pp->pb_count) {
            if (lnum > buf->b_ml.ml_line_count)
                IEMSGN (_ ("E322: line number out of range: %ld past the end"), lnum -buf->b_ml.ml_line_count);
            else
                IEMSGN (_ ("E323: line count wrong in block %ld"), bnum);
            goto error_block;
        }
        if (action == ML_DELETE) {
            pp->pb_pointer[idx].pe_line_count--;
            dirty = TRUE;
        }
        else if (action == ML_INSERT) {
            pp->pb_pointer[idx].pe_line_count++;
            dirty = TRUE;
        }
        mf_put (mfp, hp, dirty, FALSE);
    }
error_block :
    mf_put (mfp, hp, FALSE, FALSE);
error_noblock :
    if (action == ML_DELETE)
        ml_lineadd (buf, 1);
    else if (action == ML_INSERT)
        ml_lineadd (buf, -1);
    buf->b_ml.ml_stack_top = 0;
    return NULL;
}

static void ml_lineadd (buf_T *buf, int count) {
    int idx;
    infoptr_T *ip;
    PTR_BL *pp;
    memfile_T *mfp = buf->b_ml.ml_mfp;
    bhdr_T *hp;
    for (idx = buf->b_ml.ml_stack_top - 1; idx >= 0; --idx) {
        ip = &(buf->b_ml.ml_stack[idx]);
        if ((hp = mf_get (mfp, ip->ip_bnum, 1)) == NULL)
            break;
        pp = (PTR_BL *) (hp->bh_data);
        if (pp->pb_id != PTR_ID) {
            mf_put (mfp, hp, FALSE, FALSE);
            IEMSG (_ ("E317: pointer block id wrong 2"));
            break;
        }
        pp->pb_pointer[ip->ip_index].pe_line_count += count;
        ip->ip_high += count;
        mf_put (mfp, hp, TRUE, FALSE);
    }
}

char_u *ml_encrypt_data (memfile_T *mfp, char_u *data, off_T offset, unsigned  size) {
    DATA_BL *dp = (DATA_BL *) data;
    char_u *head_end;
    char_u *text_start;
    char_u *new_data;
    int text_len;
    cryptstate_T *state;
    if (dp->db_id != DATA_ID)
        return data;
    state = ml_crypt_prepare (mfp, offset, FALSE);
    if (state == NULL)
        return data;
    new_data = (char_u *) alloc (size);
    if (new_data == NULL)
        return NULL;
    head_end = (char_u *) (&dp->db_index[dp->db_line_count]);
    text_start = (char_u *) dp + dp->db_txt_start;
    text_len = size - dp->db_txt_start;
    mch_memmove (new_data, dp, head_end - (char_u *) dp);
    crypt_encode (state, text_start, text_len, new_data + dp -> db_txt_start);
    crypt_free_state (state);
    if (head_end < text_start)
        vim_memset (new_data +(head_end - data), 0, text_start -head_end);
    return new_data;
}

static cryptstate_T *ml_crypt_prepare (memfile_T *mfp, off_T offset, int reading) {
    buf_T *buf = mfp->mf_buffer;
    char_u salt [50];
    int method_nr;
    char_u *key;
    char_u *seed;
    if (reading && mfp->mf_old_key != NULL) {
        method_nr = mfp->mf_old_cm;
        key = mfp->mf_old_key;
        seed = mfp->mf_old_seed;
    }
    else {
        method_nr = crypt_get_method_nr (buf);
        key = buf->b_p_key;
        seed = mfp->mf_seed;
    }
    if (*key == NUL)
        return NULL;
    if (method_nr == CRYPT_M_ZIP) {
        vim_snprintf ((char *) salt, sizeof (salt), "%s%ld", key, (long) offset);
        return crypt_create (method_nr, salt, NULL, 0, NULL, 0);
    }
    vim_snprintf ((char *) salt, sizeof (salt), "%ld", (long) offset);
    return crypt_create (method_nr, key, salt, (int) STRLEN (salt), seed, MF_SEED_LEN);
}

#define MLCS_MAXL 800	/* max no of lines in chunk */

#define MLCS_MINL 400   /* should be half of MLCS_MAXL */

void ml_decrypt_data (memfile_T *mfp, char_u *data, off_T offset, unsigned  size) {
    DATA_BL *dp = (DATA_BL *) data;
    char_u *head_end;
    char_u *text_start;
    int text_len;
    cryptstate_T *state;
    if (dp->db_id == DATA_ID) {
        head_end = (char_u *) (&dp->db_index[dp->db_line_count]);
        text_start = (char_u *) dp + dp->db_txt_start;
        text_len = dp->db_txt_end - dp->db_txt_start;
        if (head_end > text_start || dp->db_txt_start > size || dp->db_txt_end > size)
            return;
        state = ml_crypt_prepare (mfp, offset, TRUE);
        if (state != NULL) {
            crypt_decode_inplace (state, text_start, text_len);
            crypt_free_state (state);
        }
    }
}

static int ml_add_stack (buf_T *buf) {
    int top;
    infoptr_T *newstack;
    top = buf->b_ml.ml_stack_top;
    if (top == buf->b_ml.ml_stack_size) {
        CHECK (top > 0, _ ("Stack size increases"));
        newstack = (infoptr_T *) alloc ((unsigned ) sizeof (infoptr_T) * (buf->b_ml.ml_stack_size + STACK_INCR));
        if (newstack == NULL)
            return -1;
        if (top > 0)
            mch_memmove (newstack, buf->b_ml.ml_stack, (size_t) top * sizeof (infoptr_T));
        vim_free (buf -> b_ml.ml_stack);
        buf->b_ml.ml_stack = newstack;
        buf->b_ml.ml_stack_size += STACK_INCR;
    }
    buf->b_ml.ml_stack_top++;
    return top;
}

static void ml_updatechunk (buf_T *buf, linenr_T line, long  len, int updtype) {
    static buf_T *ml_upd_lastbuf = NULL;
    static linenr_T ml_upd_lastline;
    static linenr_T ml_upd_lastcurline;
    static int ml_upd_lastcurix;
    linenr_T curline = ml_upd_lastcurline;
    int curix = ml_upd_lastcurix;
    long  size;
    chunksize_T *curchnk;
    int rest;
    bhdr_T *hp;
    DATA_BL *dp;
    if (buf->b_ml.ml_usedchunks == -1 || len == 0)
        return;
    if (buf->b_ml.ml_chunksize == NULL) {
        buf->b_ml.ml_chunksize = (chunksize_T *) alloc ((unsigned ) sizeof (chunksize_T) * 100);
        if (buf->b_ml.ml_chunksize == NULL) {
            buf->b_ml.ml_usedchunks = -1;
            return;
        }
        buf->b_ml.ml_numchunks = 100;
        buf->b_ml.ml_usedchunks = 1;
        buf->b_ml.ml_chunksize[0].mlcs_numlines = 1;
        buf->b_ml.ml_chunksize[0].mlcs_totalsize = 1;
    }
    if (updtype == ML_CHNK_UPDLINE && buf->b_ml.ml_line_count == 1) {
        buf->b_ml.ml_usedchunks = 1;
        buf->b_ml.ml_chunksize[0].mlcs_numlines = 1;
        buf->b_ml.ml_chunksize[0].mlcs_totalsize = (long ) STRLEN (buf->b_ml.ml_line_ptr) + 1;
        return;
    }
    if (buf != ml_upd_lastbuf || line != ml_upd_lastline + 1 || updtype != ML_CHNK_ADDLINE) {
        for (curline = 1, curix = 0; curix < buf->b_ml.ml_usedchunks - 1 && line >= curline + buf->b_ml.ml_chunksize[curix].mlcs_numlines; curix++) {
            curline += buf->b_ml.ml_chunksize[curix].mlcs_numlines;
        }
    }
    else if (line >= curline + buf->b_ml.ml_chunksize[curix].mlcs_numlines && curix < buf->b_ml.ml_usedchunks - 1) {
        curline += buf->b_ml.ml_chunksize[curix].mlcs_numlines;
        curix++;
    }
    curchnk = buf->b_ml.ml_chunksize + curix;
    if (updtype == ML_CHNK_DELLINE)
        len = -len;
    curchnk->mlcs_totalsize += len;
    if (updtype == ML_CHNK_ADDLINE) {
        curchnk->mlcs_numlines++;
        if (buf->b_ml.ml_usedchunks + 1 >= buf->b_ml.ml_numchunks) {
            chunksize_T *t_chunksize = buf->b_ml.ml_chunksize;
            buf->b_ml.ml_numchunks = buf->b_ml.ml_numchunks * 3 / 2;
            buf->b_ml.ml_chunksize = (chunksize_T *) vim_realloc (buf->b_ml.ml_chunksize, sizeof (chunksize_T) * buf->b_ml.ml_numchunks);
            if (buf->b_ml.ml_chunksize == NULL) {
                vim_free (t_chunksize);
                buf->b_ml.ml_usedchunks = -1;
                return;
            }
        }
        if (buf->b_ml.ml_chunksize[curix].mlcs_numlines >= MLCS_MAXL) {
            int count;
            int idx;
            int text_end;
            int linecnt;
            mch_memmove (buf -> b_ml.ml_chunksize + curix + 1, buf -> b_ml.ml_chunksize + curix, (buf -> b_ml.ml_usedchunks - curix) * sizeof (chunksize_T));
            size = 0;
            linecnt = 0;
            while (curline < buf->b_ml.ml_line_count && linecnt < MLCS_MINL) {
                if ((hp = ml_find_line (buf, curline, ML_FIND)) == NULL) {
                    buf->b_ml.ml_usedchunks = -1;
                    return;
                }
                dp = (DATA_BL *) (hp->bh_data);
                count = (long ) (buf->b_ml.ml_locked_high) - (long ) (buf->b_ml.ml_locked_low) + 1;
                idx = curline - buf->b_ml.ml_locked_low;
                curline = buf->b_ml.ml_locked_high + 1;
                if (idx == 0)
                    text_end = dp->db_txt_end;
                else
                    text_end = ((dp->db_index[idx - 1]) & DB_INDEX_MASK);
                rest = count - idx;
                if (linecnt + rest > MLCS_MINL) {
                    idx += MLCS_MINL - linecnt - 1;
                    linecnt = MLCS_MINL;
                }
                else {
                    idx = count - 1;
                    linecnt += rest;
                }
                size += text_end - ((dp->db_index[idx]) & DB_INDEX_MASK);
            }
            buf->b_ml.ml_chunksize[curix].mlcs_numlines = linecnt;
            buf->b_ml.ml_chunksize[curix + 1].mlcs_numlines -= linecnt;
            buf->b_ml.ml_chunksize[curix].mlcs_totalsize = size;
            buf->b_ml.ml_chunksize[curix + 1].mlcs_totalsize -= size;
            buf->b_ml.ml_usedchunks++;
            ml_upd_lastbuf = NULL;
            return;
        }
        else if (buf->b_ml.ml_chunksize[curix].mlcs_numlines >= MLCS_MINL && curix == buf->b_ml.ml_usedchunks - 1 && buf->b_ml.ml_line_count - line <= 1) {
            curchnk = buf->b_ml.ml_chunksize + curix + 1;
            buf->b_ml.ml_usedchunks++;
            if (line == buf->b_ml.ml_line_count) {
                curchnk->mlcs_numlines = 0;
                curchnk->mlcs_totalsize = 0;
            }
            else {
                hp = ml_find_line (buf, buf->b_ml.ml_line_count, ML_FIND);
                if (hp == NULL) {
                    buf->b_ml.ml_usedchunks = -1;
                    return;
                }
                dp = (DATA_BL *) (hp->bh_data);
                if (dp->db_line_count == 1)
                    rest = dp->db_txt_end - dp->db_txt_start;
                else
                    rest = ((dp->db_index[dp->db_line_count - 2]) & DB_INDEX_MASK) - dp->db_txt_start;
                curchnk->mlcs_totalsize = rest;
                curchnk->mlcs_numlines = 1;
                curchnk[-1].mlcs_totalsize -= rest;
                curchnk[-1].mlcs_numlines -= 1;
            }
        }
    }
    else if (updtype == ML_CHNK_DELLINE) {
        curchnk->mlcs_numlines--;
        ml_upd_lastbuf = NULL;
        if (curix < (buf->b_ml.ml_usedchunks - 1) && (curchnk->mlcs_numlines + curchnk[1].mlcs_numlines) <= MLCS_MINL) {
            curix++;
            curchnk = buf->b_ml.ml_chunksize + curix;
        }
        else if (curix == 0 && curchnk->mlcs_numlines <= 0) {
            buf->b_ml.ml_usedchunks--;
            mch_memmove (buf -> b_ml.ml_chunksize, buf -> b_ml.ml_chunksize + 1, buf -> b_ml.ml_usedchunks * sizeof (chunksize_T));
            return;
        }
        else if (curix == 0 || (curchnk->mlcs_numlines > 10 && (curchnk->mlcs_numlines + curchnk[-1].mlcs_numlines) > MLCS_MINL)) {
            return;
        }
        curchnk[-1].mlcs_numlines += curchnk->mlcs_numlines;
        curchnk[-1].mlcs_totalsize += curchnk->mlcs_totalsize;
        buf->b_ml.ml_usedchunks--;
        if (curix < buf->b_ml.ml_usedchunks) {
            mch_memmove (buf -> b_ml.ml_chunksize + curix, buf -> b_ml.ml_chunksize + curix + 1, (buf -> b_ml.ml_usedchunks - curix) * sizeof (chunksize_T));
        }
        return;
    }
    ml_upd_lastbuf = buf;
    ml_upd_lastline = line;
    ml_upd_lastcurline = curline;
    ml_upd_lastcurix = curix;
}

static int ml_append_int (buf_T *buf, linenr_T lnum, char_u *line, colnr_T len, int newfile, int mark) {
    int i;
    int line_count;
    int offset;
    int from, to;
    int space_needed;
    int page_size;
    int page_count;
    int db_idx;
    bhdr_T *hp;
    memfile_T *mfp;
    DATA_BL *dp;
    PTR_BL *pp;
    infoptr_T *ip;
    if (lnum > buf->b_ml.ml_line_count || buf->b_ml.ml_mfp == NULL)
        return FAIL;
    if (lowest_marked && lowest_marked > lnum)
        lowest_marked = lnum + 1;
    if (len == 0)
        len = (colnr_T) STRLEN (line) + 1;
    space_needed = len + INDEX_SIZE;
    mfp = buf->b_ml.ml_mfp;
    page_size = mfp->mf_page_size;
    if ((hp = ml_find_line (buf, lnum == 0 ? (linenr_T) 1 : lnum, ML_INSERT)) == NULL)
        return FAIL;
    buf->b_ml.ml_flags &= ~ML_EMPTY;
    if (lnum == 0)
        db_idx = -1;
    else
        db_idx = lnum - buf->b_ml.ml_locked_low;
    line_count = buf->b_ml.ml_locked_high - buf->b_ml.ml_locked_low;
    dp = (DATA_BL *) (hp->bh_data);
    if ((int) dp->db_free < space_needed && db_idx == line_count - 1 && lnum < buf->b_ml.ml_line_count) {
        --(buf->b_ml.ml_locked_lineadd);
        --(buf->b_ml.ml_locked_high);
        if ((hp = ml_find_line (buf, lnum +1, ML_INSERT)) == NULL)
            return FAIL;
        db_idx = -1;
        line_count = buf->b_ml.ml_locked_high - buf->b_ml.ml_locked_low;
        CHECK (buf -> b_ml.ml_locked_low != lnum + 1, "locked_low != lnum + 1");
        dp = (DATA_BL *) (hp->bh_data);
    }
    ++buf->b_ml.ml_line_count;
    if ((int) dp->db_free >= space_needed) {
        dp->db_txt_start -= len;
        dp->db_free -= space_needed;
        ++(dp->db_line_count);
        if (line_count > db_idx + 1) {
            if (db_idx < 0)
                offset = dp->db_txt_end;
            else
                offset = ((dp->db_index[db_idx]) & DB_INDEX_MASK);
            mch_memmove ((char *) dp + dp -> db_txt_start, (char *) dp + dp -> db_txt_start + len, (size_t) (offset - (dp -> db_txt_start + len)));
            for (i = line_count - 1; i > db_idx; --i)
                dp->db_index[i + 1] = dp->db_index[i] - len;
            dp->db_index[db_idx + 1] = offset - len;
        }
        else
            dp->db_index[db_idx + 1] = dp->db_txt_start;
        mch_memmove ((char *) dp + dp -> db_index [db_idx + 1], line, (size_t) len);
        if (mark)
            dp->db_index[db_idx + 1] |= DB_MARKED;
        buf->b_ml.ml_flags |= ML_LOCKED_DIRTY;
        if (!newfile)
            buf->b_ml.ml_flags |= ML_LOCKED_POS;
    }
    else {
        long  line_count_left, line_count_right;
        int page_count_left, page_count_right;
        bhdr_T *hp_left;
        bhdr_T *hp_right;
        bhdr_T *hp_new;
        int lines_moved;
        int data_moved = 0;
        int total_moved = 0;
        DATA_BL *dp_right, *dp_left;
        int stack_idx;
        int in_left;
        int lineadd;
        blocknr_T bnum_left, bnum_right;
        linenr_T lnum_left, lnum_right;
        int pb_idx;
        PTR_BL *pp_new;
        if (db_idx < 0) {
            lines_moved = 0;
            in_left = TRUE;
        }
        else {
            lines_moved = line_count - db_idx - 1;
            if (lines_moved == 0)
                in_left = FALSE;
            else {
                data_moved = ((dp->db_index[db_idx]) & DB_INDEX_MASK) - dp->db_txt_start;
                total_moved = data_moved + lines_moved * INDEX_SIZE;
                if ((int) dp->db_free + total_moved >= space_needed) {
                    in_left = TRUE;
                    space_needed = total_moved;
                }
                else {
                    in_left = FALSE;
                    space_needed += total_moved;
                }
            }
        }
        page_count = ((space_needed + HEADER_SIZE) + page_size - 1) / page_size;
        if ((hp_new = ml_new_data (mfp, newfile, page_count)) == NULL) {
            --(buf->b_ml.ml_locked_lineadd);
            --(buf->b_ml.ml_locked_high);
            return FAIL;
        }
        if (db_idx < 0) {
            hp_left = hp_new;
            hp_right = hp;
            line_count_left = 0;
            line_count_right = line_count;
        }
        else {
            hp_left = hp;
            hp_right = hp_new;
            line_count_left = line_count;
            line_count_right = 0;
        }
        dp_right = (DATA_BL *) (hp_right->bh_data);
        dp_left = (DATA_BL *) (hp_left->bh_data);
        bnum_left = hp_left->bh_bnum;
        bnum_right = hp_right->bh_bnum;
        page_count_left = hp_left->bh_page_count;
        page_count_right = hp_right->bh_page_count;
        if (!in_left) {
            dp_right->db_txt_start -= len;
            dp_right->db_free -= len + INDEX_SIZE;
            dp_right->db_index[0] = dp_right->db_txt_start;
            if (mark)
                dp_right->db_index[0] |= DB_MARKED;
            mch_memmove ((char *) dp_right + dp_right -> db_txt_start, line, (size_t) len);
            ++line_count_right;
        }
        if (lines_moved) {
            dp_right->db_txt_start -= data_moved;
            dp_right->db_free -= total_moved;
            mch_memmove ((char *) dp_right + dp_right -> db_txt_start, (char *) dp_left + dp_left -> db_txt_start, (size_t) data_moved);
            offset = dp_right->db_txt_start - dp_left->db_txt_start;
            dp_left->db_txt_start += data_moved;
            dp_left->db_free += total_moved;
            for (to = line_count_right, from = db_idx + 1; from < line_count_left; ++from, ++to)
                dp_right->db_index[to] = dp->db_index[from] + offset;
            line_count_right += lines_moved;
            line_count_left -= lines_moved;
        }
        if (in_left) {
            dp_left->db_txt_start -= len;
            dp_left->db_free -= len + INDEX_SIZE;
            dp_left->db_index[line_count_left] = dp_left->db_txt_start;
            if (mark)
                dp_left->db_index[line_count_left] |= DB_MARKED;
            mch_memmove ((char *) dp_left + dp_left -> db_txt_start, line, (size_t) len);
            ++line_count_left;
        }
        if (db_idx < 0) {
            lnum_left = lnum + 1;
            lnum_right = 0;
        }
        else {
            lnum_left = 0;
            if (in_left)
                lnum_right = lnum + 2;
            else
                lnum_right = lnum + 1;
        }
        dp_left->db_line_count = line_count_left;
        dp_right->db_line_count = line_count_right;
        if (lines_moved || in_left)
            buf->b_ml.ml_flags |= ML_LOCKED_DIRTY;
        if (!newfile && db_idx >= 0 && in_left)
            buf->b_ml.ml_flags |= ML_LOCKED_POS;
        mf_put (mfp, hp_new, TRUE, FALSE);
        lineadd = buf->b_ml.ml_locked_lineadd;
        buf->b_ml.ml_locked_lineadd = 0;
        ml_find_line (buf, (linenr_T) 0, ML_FLUSH);
        for (stack_idx = buf->b_ml.ml_stack_top - 1; stack_idx >= 0; --stack_idx) {
            ip = &(buf->b_ml.ml_stack[stack_idx]);
            pb_idx = ip->ip_index;
            if ((hp = mf_get (mfp, ip->ip_bnum, 1)) == NULL)
                return FAIL;
            pp = (PTR_BL *) (hp->bh_data);
            if (pp->pb_id != PTR_ID) {
                IEMSG (_ ("E317: pointer block id wrong 3"));
                mf_put (mfp, hp, FALSE, FALSE);
                return FAIL;
            }
            if (pp->pb_count < pp->pb_count_max) {
                if (pb_idx + 1 < (int) pp->pb_count)
                    mch_memmove (&pp->pb_pointer[pb_idx + 2], &pp->pb_pointer[pb_idx + 1], (size_t) (pp->pb_count - pb_idx - 1) * sizeof (PTR_EN));
                ++pp->pb_count;
                pp->pb_pointer[pb_idx].pe_line_count = line_count_left;
                pp->pb_pointer[pb_idx].pe_bnum = bnum_left;
                pp->pb_pointer[pb_idx].pe_page_count = page_count_left;
                pp->pb_pointer[pb_idx + 1].pe_line_count = line_count_right;
                pp->pb_pointer[pb_idx + 1].pe_bnum = bnum_right;
                pp->pb_pointer[pb_idx + 1].pe_page_count = page_count_right;
                if (lnum_left != 0)
                    pp->pb_pointer[pb_idx].pe_old_lnum = lnum_left;
                if (lnum_right != 0)
                    pp->pb_pointer[pb_idx + 1].pe_old_lnum = lnum_right;
                mf_put (mfp, hp, TRUE, FALSE);
                buf->b_ml.ml_stack_top = stack_idx + 1;
                if (lineadd) {
                    --(buf->b_ml.ml_stack_top);
                    ml_lineadd (buf, lineadd);
                    buf->b_ml.ml_stack[buf->b_ml.ml_stack_top].ip_high += lineadd;
                    ++(buf->b_ml.ml_stack_top);
                }
                break;
            }
            else {
                for (;;) {
                    hp_new = ml_new_ptr (mfp);
                    if (hp_new == NULL)
                        return FAIL;
                    pp_new = (PTR_BL *) (hp_new->bh_data);
                    if (hp->bh_bnum != 1)
                        break;
                    mch_memmove (pp_new, pp, (size_t) page_size);
                    pp->pb_count = 1;
                    pp->pb_pointer[0].pe_bnum = hp_new->bh_bnum;
                    pp->pb_pointer[0].pe_line_count = buf->b_ml.ml_line_count;
                    pp->pb_pointer[0].pe_old_lnum = 1;
                    pp->pb_pointer[0].pe_page_count = 1;
                    mf_put (mfp, hp, TRUE, FALSE);
                    hp = hp_new;
                    pp = pp_new;
                    CHECK (stack_idx != 0, _ ("stack_idx should be 0"));
                    ip->ip_index = 0;
                    ++stack_idx;
                }
                total_moved = pp->pb_count - pb_idx - 1;
                if (total_moved) {
                    mch_memmove (& pp_new -> pb_pointer [0], & pp -> pb_pointer [pb_idx + 1], (size_t) (total_moved) * sizeof (PTR_EN));
                    pp_new->pb_count = total_moved;
                    pp->pb_count -= total_moved - 1;
                    pp->pb_pointer[pb_idx + 1].pe_bnum = bnum_right;
                    pp->pb_pointer[pb_idx + 1].pe_line_count = line_count_right;
                    pp->pb_pointer[pb_idx + 1].pe_page_count = page_count_right;
                    if (lnum_right)
                        pp->pb_pointer[pb_idx + 1].pe_old_lnum = lnum_right;
                }
                else {
                    pp_new->pb_count = 1;
                    pp_new->pb_pointer[0].pe_bnum = bnum_right;
                    pp_new->pb_pointer[0].pe_line_count = line_count_right;
                    pp_new->pb_pointer[0].pe_page_count = page_count_right;
                    pp_new->pb_pointer[0].pe_old_lnum = lnum_right;
                }
                pp->pb_pointer[pb_idx].pe_bnum = bnum_left;
                pp->pb_pointer[pb_idx].pe_line_count = line_count_left;
                pp->pb_pointer[pb_idx].pe_page_count = page_count_left;
                if (lnum_left)
                    pp->pb_pointer[pb_idx].pe_old_lnum = lnum_left;
                lnum_left = 0;
                lnum_right = 0;
                line_count_right = 0;
                for (i = 0; i < (int) pp_new->pb_count; ++i)
                    line_count_right += pp_new->pb_pointer[i].pe_line_count;
                line_count_left = 0;
                for (i = 0; i < (int) pp->pb_count; ++i)
                    line_count_left += pp->pb_pointer[i].pe_line_count;
                bnum_left = hp->bh_bnum;
                bnum_right = hp_new->bh_bnum;
                page_count_left = 1;
                page_count_right = 1;
                mf_put (mfp, hp, TRUE, FALSE);
                mf_put (mfp, hp_new, TRUE, FALSE);
            }
        }
        if (stack_idx < 0) {
            IEMSG (_ ("E318: Updated too many blocks?"));
            buf->b_ml.ml_stack_top = 0;
        }
    }
    ml_updatechunk (buf, lnum + 1, (long) len, ML_CHNK_ADDLINE);
    if (netbeans_active ()) {
        if (STRLEN (line) > 0)
            netbeans_inserted (buf, lnum +1, (colnr_T) 0, line, (int) STRLEN (line));
        netbeans_inserted (buf, lnum + 1, (colnr_T) STRLEN (line), (char_u *) "\n", 1);
    }
    if (buf->b_write_to_channel)
        channel_write_new_lines (buf);
    return OK;
}

static bhdr_T *ml_new_data (memfile_T *mfp, int negative, int page_count) {
    bhdr_T *hp;
    DATA_BL *dp;
    if ((hp = mf_new (mfp, negative, page_count)) == NULL)
        return NULL;
    dp = (DATA_BL *) (hp->bh_data);
    dp->db_id = DATA_ID;
    dp->db_txt_start = dp->db_txt_end = page_count * mfp->mf_page_size;
    dp->db_free = dp->db_txt_start - HEADER_SIZE;
    dp->db_line_count = 0;
    return hp;
}

static bhdr_T *ml_new_ptr (memfile_T *mfp) {
    bhdr_T *hp;
    PTR_BL *pp;
    if ((hp = mf_new (mfp, FALSE, 1)) == NULL)
        return NULL;
    pp = (PTR_BL *) (hp->bh_data);
    pp->pb_id = PTR_ID;
    pp->pb_count = 0;
    pp->pb_count_max = (short_u) ((mfp->mf_page_size - sizeof (PTR_BL)) / sizeof (PTR_EN) + 1);
    return hp;
}

long  ml_find_line_or_offset (buf_T *buf, linenr_T lnum, long  *offp) {
    linenr_T curline;
    int curix;
    long  size;
    bhdr_T *hp;
    DATA_BL *dp;
    int count;
    int idx;
    int start_idx;
    int text_end;
    long  offset;
    int len;
    int ffdos = (get_fileformat (buf) == EOL_DOS);
    int extra = 0;
    ml_flush_line (curbuf);
    if (buf->b_ml.ml_usedchunks == -1 || buf->b_ml.ml_chunksize == NULL || lnum < 0)
        return -1;
    if (offp == NULL)
        offset = 0;
    else
        offset = *offp;
    if (lnum == 0 && offset <= 0)
        return 1;
    curline = 1;
    curix = size = 0;
    while (curix < buf->b_ml.ml_usedchunks - 1 && ((lnum != 0 && lnum >= curline + buf->b_ml.ml_chunksize[curix].mlcs_numlines) || (offset != 0 && offset > size + buf->b_ml.ml_chunksize[curix].mlcs_totalsize + ffdos * buf->b_ml.ml_chunksize[curix].mlcs_numlines))) {
        curline += buf->b_ml.ml_chunksize[curix].mlcs_numlines;
        size += buf->b_ml.ml_chunksize[curix].mlcs_totalsize;
        if (offset && ffdos)
            size += buf->b_ml.ml_chunksize[curix].mlcs_numlines;
        curix++;
    }
    while ((lnum != 0 && curline < lnum) || (offset != 0 && size < offset)) {
        if (curline > buf->b_ml.ml_line_count || (hp = ml_find_line (buf, curline, ML_FIND)) == NULL)
            return -1;
        dp = (DATA_BL *) (hp->bh_data);
        count = (long ) (buf->b_ml.ml_locked_high) - (long ) (buf->b_ml.ml_locked_low) + 1;
        start_idx = idx = curline - buf->b_ml.ml_locked_low;
        if (idx == 0)
            text_end = dp->db_txt_end;
        else
            text_end = ((dp->db_index[idx - 1]) & DB_INDEX_MASK);
        if (lnum != 0) {
            if (curline + (count - idx) >= lnum)
                idx += lnum - curline - 1;
            else
                idx = count - 1;
        }
        else {
            extra = 0;
            while (offset >= size + text_end - (int) ((dp->db_index[idx]) & DB_INDEX_MASK) + ffdos) {
                if (ffdos)
                    size++;
                if (idx == count - 1) {
                    extra = 1;
                    break;
                }
                idx++;
            }
        }
        len = text_end - ((dp->db_index[idx]) & DB_INDEX_MASK);
        size += len;
        if (offset != 0 && size >= offset) {
            if (size + ffdos == offset)
                *offp = 0;
            else if (idx == start_idx)
                *offp = offset - size + len;
            else
                *offp = offset - size + len - (text_end - ((dp->db_index[idx - 1]) & DB_INDEX_MASK));
            curline += idx - start_idx + extra;
            if (curline > buf->b_ml.ml_line_count)
                return -1;
            return curline;
        }
        curline = buf->b_ml.ml_locked_high + 1;
    }
    if (lnum != 0) {
        if (ffdos)
            size += lnum - 1;
        if ((!buf->b_p_fixeol || buf->b_p_bin) && !buf->b_p_eol && buf->b_ml.ml_line_count == lnum)
            size -= ffdos + 1;
    }
    return size;
}

static int ml_delete_int (buf_T *buf, linenr_T lnum, int message) {
    bhdr_T *hp;
    memfile_T *mfp;
    DATA_BL *dp;
    PTR_BL *pp;
    infoptr_T *ip;
    int count;
    int idx;
    int stack_idx;
    int text_start;
    int line_start;
    long  line_size;
    int i;
    if (lnum < 1 || lnum > buf->b_ml.ml_line_count)
        return FAIL;
    if (lowest_marked && lowest_marked > lnum)
        lowest_marked--;
    if (buf->b_ml.ml_line_count == 1) {
        if (message && !netbeansSuppressNoLines)
            set_keep_msg ((char_u *) _ (no_lines_msg), 0);
        i = ml_replace ((linenr_T) 1, (char_u *) "", TRUE);
        buf->b_ml.ml_flags |= ML_EMPTY;
        return i;
    }
    mfp = buf->b_ml.ml_mfp;
    if (mfp == NULL)
        return FAIL;
    if ((hp = ml_find_line (buf, lnum, ML_DELETE)) == NULL)
        return FAIL;
    dp = (DATA_BL *) (hp->bh_data);
    count = (long ) (buf->b_ml.ml_locked_high) - (long ) (buf->b_ml.ml_locked_low) + 2;
    idx = lnum - buf->b_ml.ml_locked_low;
    --buf->b_ml.ml_line_count;
    line_start = ((dp->db_index[idx]) & DB_INDEX_MASK);
    if (idx == 0)
        line_size = dp->db_txt_end - line_start;
    else
        line_size = ((dp->db_index[idx - 1]) & DB_INDEX_MASK) - line_start;
    if (netbeans_active ())
        netbeans_removed (buf, lnum, 0, (long ) line_size);
    if (count == 1) {
        mf_free (mfp, hp);
        buf->b_ml.ml_locked = NULL;
        for (stack_idx = buf->b_ml.ml_stack_top - 1; stack_idx >= 0; --stack_idx) {
            buf->b_ml.ml_stack_top = 0;
            ip = &(buf->b_ml.ml_stack[stack_idx]);
            idx = ip->ip_index;
            if ((hp = mf_get (mfp, ip->ip_bnum, 1)) == NULL)
                return FAIL;
            pp = (PTR_BL *) (hp->bh_data);
            if (pp->pb_id != PTR_ID) {
                IEMSG (_ ("E317: pointer block id wrong 4"));
                mf_put (mfp, hp, FALSE, FALSE);
                return FAIL;
            }
            count = --(pp->pb_count);
            if (count == 0)
                mf_free (mfp, hp);
            else {
                if (count != idx)
                    mch_memmove (&pp->pb_pointer[idx], &pp->pb_pointer[idx + 1], (size_t) (count - idx) * sizeof (PTR_EN));
                mf_put (mfp, hp, TRUE, FALSE);
                buf->b_ml.ml_stack_top = stack_idx;
                if (buf->b_ml.ml_locked_lineadd != 0) {
                    ml_lineadd (buf, buf -> b_ml.ml_locked_lineadd);
                    buf->b_ml.ml_stack[buf->b_ml.ml_stack_top].ip_high += buf->b_ml.ml_locked_lineadd;
                }
                ++(buf->b_ml.ml_stack_top);
                break;
            }
        }
        CHECK (stack_idx < 0, _ ("deleted block 1?"));
    }
    else {
        text_start = dp->db_txt_start;
        mch_memmove ((char *) dp + text_start + line_size, (char *) dp + text_start, (size_t) (line_start - text_start));
        for (i = idx; i < count - 1; ++i)
            dp->db_index[i] = dp->db_index[i + 1] + line_size;
        dp->db_free += line_size + INDEX_SIZE;
        dp->db_txt_start += line_size;
        --(dp->db_line_count);
        buf->b_ml.ml_flags |= (ML_LOCKED_DIRTY | ML_LOCKED_POS);
    }
    ml_updatechunk (buf, lnum, line_size, ML_CHNK_DELLINE);
    return OK;
}

int ml_replace (linenr_T lnum, char_u *line, int copy) {
    if (line == NULL)
        return FAIL;
    if (curbuf->b_ml.ml_mfp == NULL && open_buffer (FALSE, NULL, 0) == FAIL)
        return FAIL;
    if (copy && (line = vim_strsave (line)) == NULL)
        return FAIL;
    if (netbeans_active ()) {
        netbeans_removed (curbuf, lnum, 0, (long) STRLEN (ml_get (lnum)));
        netbeans_inserted (curbuf, lnum, 0, line, (int) STRLEN (line));
    }
    if (curbuf->b_ml.ml_line_lnum != lnum)
        ml_flush_line (curbuf);
    else if (curbuf->b_ml.ml_flags & ML_LINE_DIRTY)
        vim_free (curbuf->b_ml.ml_line_ptr);
    curbuf->b_ml.ml_line_ptr = line;
    curbuf->b_ml.ml_line_lnum = lnum;
    curbuf->b_ml.ml_flags = (curbuf->b_ml.ml_flags | ML_LINE_DIRTY) & ~ML_EMPTY;
    return OK;
}

int ml_open (buf_T *buf) {
    memfile_T *mfp;
    bhdr_T *hp = NULL;
    ZERO_BL *b0p;
    PTR_BL *pp;
    DATA_BL *dp;
    buf->b_ml.ml_stack_size = 0;
    buf->b_ml.ml_stack = NULL;
    buf->b_ml.ml_stack_top = 0;
    buf->b_ml.ml_locked = NULL;
    buf->b_ml.ml_line_lnum = 0;
    buf->b_ml.ml_chunksize = NULL;
    if (cmdmod.noswapfile)
        buf->b_p_swf = FALSE;
    if (p_uc && buf->b_p_swf)
        buf->b_may_swap = TRUE;
    else
        buf->b_may_swap = FALSE;
    mfp = mf_open (NULL, 0);
    if (mfp == NULL)
        goto error;
    buf->b_ml.ml_mfp = mfp;
    mfp->mf_buffer = buf;
    buf->b_ml.ml_flags = ML_EMPTY;
    buf->b_ml.ml_line_count = 1;
    curwin->w_nrwidth_line_count = 0;
    if ((hp = mf_new (mfp, FALSE, 1)) == NULL)
        goto error;
    if (hp->bh_bnum != 0) {
        IEMSG (_ ("E298: Didn't get block nr 0?"));
        goto error;
    }
    b0p = (ZERO_BL *) (hp->bh_data);
    b0p->b0_id[0] = BLOCK0_ID0;
    b0p->b0_id[1] = BLOCK0_ID1;
    b0p->b0_magic_long = (long ) B0_MAGIC_LONG;
    b0p->b0_magic_int = (int) B0_MAGIC_INT;
    b0p->b0_magic_short = (short ) B0_MAGIC_SHORT;
    b0p->b0_magic_char = B0_MAGIC_CHAR;
    STRNCPY (b0p -> b0_version, "VIM ", 4);
    STRNCPY (b0p -> b0_version + 4, Version, 6);
    long_to_char ((long) mfp -> mf_page_size, b0p -> b0_page_size);
    {
        b0p->b0_dirty = buf->b_changed ? B0_DIRTY : 0;
        b0p->b0_flags = get_fileformat (buf) + 1;
        set_b0_fname (b0p, buf);
        (void) get_user_name (b0p->b0_uname, B0_UNAME_SIZE);
        b0p->b0_uname[B0_UNAME_SIZE - 1] = NUL;
        mch_get_host_name (b0p -> b0_hname, B0_HNAME_SIZE);
        b0p->b0_hname[B0_HNAME_SIZE - 1] = NUL;
        long_to_char (mch_get_pid (), b0p -> b0_pid);
        ml_set_b0_crypt (buf, b0p);
    }
    mf_put (mfp, hp, TRUE, FALSE);
    if (!buf->b_help && !B_SPELL (buf))
        (void) mf_sync (mfp, 0);
    if ((hp = ml_new_ptr (mfp)) == NULL)
        goto error;
    if (hp->bh_bnum != 1) {
        IEMSG (_ ("E298: Didn't get block nr 1?"));
        goto error;
    }
    pp = (PTR_BL *) (hp->bh_data);
    pp->pb_count = 1;
    pp->pb_pointer[0].pe_bnum = 2;
    pp->pb_pointer[0].pe_page_count = 1;
    pp->pb_pointer[0].pe_old_lnum = 1;
    pp->pb_pointer[0].pe_line_count = 1;
    mf_put (mfp, hp, TRUE, FALSE);
    if ((hp = ml_new_data (mfp, FALSE, 1)) == NULL)
        goto error;
    if (hp->bh_bnum != 2) {
        IEMSG (_ ("E298: Didn't get block nr 2?"));
        goto error;
    }
    dp = (DATA_BL *) (hp->bh_data);
    dp->db_index[0] = --dp->db_txt_start;
    dp->db_free -= 1 + INDEX_SIZE;
    dp->db_line_count = 1;
    *((char_u *) dp + dp->db_txt_start) = NUL;
    return OK;
error :
    if (mfp != NULL) {
        if (hp)
            mf_put (mfp, hp, FALSE, FALSE);
        mf_close (mfp, TRUE);
    }
    buf->b_ml.ml_mfp = NULL;
    return FAIL;
}

static void long_to_char (long  n, char_u *s) {
    s[0] = (char_u) (n & 0xff);
    n = (unsigned ) n >> 8;
    s[1] = (char_u) (n & 0xff);
    n = (unsigned ) n >> 8;
    s[2] = (char_u) (n & 0xff);
    n = (unsigned ) n >> 8;
    s[3] = (char_u) (n & 0xff);
}

static void set_b0_fname (ZERO_BL *b0p, buf_T *buf) {
    stat_T st;
    if (buf->b_ffname == NULL)
        b0p->b0_fname[0] = NUL;
    else {
        size_t flen, ulen;
        char_u uname [B0_UNAME_SIZE];
        home_replace (NULL, buf -> b_ffname, b0p -> b0_fname, B0_FNAME_SIZE_CRYPT, TRUE);
        if (b0p->b0_fname[0] == '~') {
            flen = STRLEN (b0p->b0_fname);
            if (get_user_name (uname, B0_UNAME_SIZE) == FAIL || (ulen = STRLEN (uname)) + flen > B0_FNAME_SIZE_CRYPT - 1)
                vim_strncpy (b0p->b0_fname, buf->b_ffname, B0_FNAME_SIZE_CRYPT -1);
            else {
                mch_memmove (b0p -> b0_fname + ulen + 1, b0p -> b0_fname + 1, flen);
                mch_memmove (b0p -> b0_fname + 1, uname, ulen);
            }
        }
        if (mch_stat ((char *) buf->b_ffname, &st) >= 0) {
            long_to_char ((long) st.st_mtime, b0p -> b0_mtime);
            buf_store_time (buf, & st, buf -> b_ffname);
            buf->b_mtime_read = buf->b_mtime;
        }
        else {
            long_to_char (0L, b0p -> b0_mtime);
            buf->b_mtime = 0;
            buf->b_mtime_read = 0;
            buf->b_orig_size = 0;
            buf->b_orig_mode = 0;
        }
    }
}

char_u *ml_get_buf (buf_T *buf, linenr_T lnum, int will_change) {
    bhdr_T *hp;
    DATA_BL *dp;
    char_u *ptr;
    static int recursive = 0;
    if (lnum > buf->b_ml.ml_line_count) {
        if (recursive == 0) {
            ++recursive;
            IEMSGN (_ ("E315: ml_get: invalid lnum: %ld"), lnum);
            --recursive;
        }
    errorret :
        STRCPY (IObuff, "???");
        return IObuff;
    }
    if (lnum <= 0)
        lnum = 1;
    if (buf->b_ml.ml_mfp == NULL)
        return (char_u *) "";
    if (buf->b_ml.ml_line_lnum != lnum || mf_dont_release) {
        ml_flush_line (buf);
        if ((hp = ml_find_line (buf, lnum, ML_FIND)) == NULL) {
            if (recursive == 0) {
                ++recursive;
                IEMSGN (_ ("E316: ml_get: cannot find line %ld"), lnum);
                --recursive;
            }
            goto errorret;
        }
        dp = (DATA_BL *) (hp->bh_data);
        ptr = (char_u *) dp + ((dp->db_index[lnum - buf->b_ml.ml_locked_low]) & DB_INDEX_MASK);
        buf->b_ml.ml_line_ptr = ptr;
        buf->b_ml.ml_line_lnum = lnum;
        buf->b_ml.ml_flags &= ~ML_LINE_DIRTY;
    }
    if (will_change)
        buf->b_ml.ml_flags |= (ML_LOCKED_DIRTY | ML_LOCKED_POS);
    return buf->b_ml.ml_line_ptr;
}

char_u *ml_get_curline (void) {
    return ml_get_buf (curbuf, curwin->w_cursor.lnum, FALSE);
}

char_u *ml_get (linenr_T lnum) {
    return ml_get_buf (curbuf, lnum, FALSE);
}

char_u *ml_get_pos (pos_T *pos) {
    return (ml_get_buf (curbuf, pos->lnum, FALSE) + pos->col);
}

char_u *ml_get_cursor (void) {
    return (ml_get_buf (curbuf, curwin->w_cursor.lnum, FALSE) + curwin->w_cursor.col);
}

void ml_close (buf_T *buf, int del_file) {
    if (buf->b_ml.ml_mfp == NULL)
        return;
    mf_close (buf -> b_ml.ml_mfp, del_file);
    if (buf->b_ml.ml_line_lnum != 0 && (buf->b_ml.ml_flags & ML_LINE_DIRTY))
        vim_free (buf->b_ml.ml_line_ptr);
    vim_free (buf -> b_ml.ml_stack);
    VIM_CLEAR (buf -> b_ml.ml_chunksize);
    buf->b_ml.ml_mfp = NULL;
    buf->b_flags &= ~BF_RECOVERED;
}

void ml_setflags (buf_T *buf) {
    bhdr_T *hp;
    ZERO_BL *b0p;
    if (!buf->b_ml.ml_mfp)
        return;
    for (hp = buf->b_ml.ml_mfp->mf_used_last; hp != NULL; hp = hp->bh_prev) {
        if (hp->bh_bnum == 0) {
            b0p = (ZERO_BL *) (hp->bh_data);
            b0p->b0_dirty = buf->b_changed ? B0_DIRTY : 0;
            b0p->b0_flags = (b0p->b0_flags & ~B0_FF_MASK) | (get_fileformat (buf) + 1);
            hp->bh_flags |= BH_DIRTY;
            mf_sync (buf -> b_ml.ml_mfp, MFS_ZERO);
            break;
        }
    }
}

void ml_close_notmod (void) {
    buf_T *buf;
    FOR_ALL_BUFFERS (buf)
        if (!bufIsChanged (buf))
            ml_close (buf, TRUE);
}

void ml_close_all (int del_file) {
    buf_T *buf;
    FOR_ALL_BUFFERS (buf)
        ml_close (buf, del_file &&((buf->b_flags & BF_PRESERVED) == 0 || vim_strchr (p_cpo, CPO_PRESERVE) == NULL));
    vim_deltempdir ();
}

void ml_set_crypt_key (buf_T *buf, char_u *old_key, char_u *old_cm) {
    memfile_T *mfp = buf->b_ml.ml_mfp;
    bhdr_T *hp;
    int page_count;
    int idx;
    long  error;
    infoptr_T *ip;
    PTR_BL *pp;
    DATA_BL *dp;
    blocknr_T bnum;
    int top;
    int old_method;
    if (mfp == NULL)
        return;
    old_method = crypt_method_nr_from_name (old_cm);
    {
        char_u *new_key = buf->b_p_key;
        char_u *new_buf_cm = buf->b_p_cm;
        buf->b_p_key = old_key;
        buf->b_p_cm = old_cm;
        ml_preserve (buf, FALSE);
        buf->b_p_key = new_key;
        buf->b_p_cm = new_buf_cm;
    }
    mfp->mf_old_key = old_key;
    mfp->mf_old_cm = old_method;
    if (old_method > 0 && *old_key != NUL)
        mch_memmove (mfp->mf_old_seed, mfp->mf_seed, MF_SEED_LEN);
    ml_upd_block0 (buf, UB_CRYPT);
    if (mfp->mf_infile_count > 2) {
        ml_flush_line (buf);
        (void) ml_find_line (buf, (linenr_T) 0, ML_FLUSH);
        hp = NULL;
        bnum = 1;
        page_count = 1;
        idx = 0;
        error = 0;
        buf->b_ml.ml_stack_top = 0;
        VIM_CLEAR (buf -> b_ml.ml_stack);
        buf->b_ml.ml_stack_size = 0;
        for (; !got_int; line_breakcheck ()) {
            if (hp != NULL)
                mf_put (mfp, hp, FALSE, FALSE);
            if ((hp = mf_get (mfp, (blocknr_T) bnum, page_count)) == NULL) {
                if (bnum == 1)
                    break;
                ++error;
            }
            else {
                pp = (PTR_BL *) (hp->bh_data);
                if (pp->pb_id == PTR_ID) {
                    if (pp->pb_count == 0) {
                        ++error;
                    }
                    else if (idx < (int) pp->pb_count) {
                        if (pp->pb_pointer[idx].pe_bnum < 0) {
                            ++idx;
                            continue;
                        }
                        if ((top = ml_add_stack (buf)) < 0) {
                            ++error;
                            break;
                        }
                        ip = &(buf->b_ml.ml_stack[top]);
                        ip->ip_bnum = bnum;
                        ip->ip_index = idx;
                        bnum = pp->pb_pointer[idx].pe_bnum;
                        page_count = pp->pb_pointer[idx].pe_page_count;
                        idx = 0;
                        continue;
                    }
                }
                else {
                    dp = (DATA_BL *) (hp->bh_data);
                    if (dp->db_id != DATA_ID)
                        ++error;
                    else {
                        mf_put (mfp, hp, TRUE, FALSE);
                        hp = NULL;
                    }
                }
            }
            if (buf->b_ml.ml_stack_top == 0)
                break;
            ip = &(buf->b_ml.ml_stack[--(buf->b_ml.ml_stack_top)]);
            bnum = ip->ip_bnum;
            idx = ip->ip_index + 1;
            page_count = 1;
        }
        if (hp != NULL)
            mf_put (mfp, hp, FALSE, FALSE);
        if (error > 0)
            EMSG (_ ("E843: Error while updating swap file crypt"));
    }
    mfp->mf_old_key = NULL;
}

static void ml_upd_block0 (buf_T *buf, upd_block0_T what) {
    memfile_T *mfp;
    bhdr_T *hp;
    ZERO_BL *b0p;
    mfp = buf->b_ml.ml_mfp;
    if (mfp == NULL)
        return;
    hp = mf_get (mfp, (blocknr_T) 0, 1);
    if (hp == NULL) {
        if (what == UB_CRYPT)
            ml_set_mfp_crypt (buf);
        return;
    }
    b0p = (ZERO_BL *) (hp->bh_data);
    if (ml_check_b0_id (b0p) == FAIL)
        IEMSG (_ ("E304: ml_upd_block0(): Didn't get block 0??"));
    else {
        if (what == UB_FNAME)
            set_b0_fname (b0p, buf);
        else if (what == UB_CRYPT)
            ml_set_b0_crypt (buf, b0p);
        else
            set_b0_dir_flag (b0p, buf);
    }
    mf_put (mfp, hp, TRUE, FALSE);
}

static int ml_check_b0_id (ZERO_BL *b0p) {
    if (b0p->b0_id[0] != BLOCK0_ID0 || (b0p->b0_id[1] != BLOCK0_ID1 && b0p->b0_id[1] != BLOCK0_ID1_C0 && b0p->b0_id[1] != BLOCK0_ID1_C1 && b0p->b0_id[1] != BLOCK0_ID1_C2))
        return FAIL;
    return OK;
}

static void ml_set_b0_crypt (buf_T *buf, ZERO_BL *b0p) {
    if (*buf->b_p_key == NUL)
        b0p->b0_id[1] = BLOCK0_ID1;
    else {
        int method_nr = crypt_get_method_nr (buf);
        b0p->b0_id[1] = id1_codes[method_nr];
        if (method_nr > CRYPT_M_ZIP) {
            sha2_seed (& b0p -> b0_seed, MF_SEED_LEN, NULL, 0);
            mch_memmove (buf -> b_ml.ml_mfp -> mf_seed, & b0p -> b0_seed, MF_SEED_LEN);
        }
    }
}

static void set_b0_dir_flag (ZERO_BL *b0p, buf_T *buf) {
    if (same_directory (buf->b_ml.ml_mfp->mf_fname, buf->b_ffname))
        b0p->b0_flags |= B0_SAME_DIR;
    else
        b0p->b0_flags &= ~B0_SAME_DIR;
}

void ml_open_files (void) {
    buf_T *buf;
    FOR_ALL_BUFFERS (buf)
        if (!buf->b_p_ro || buf->b_changed)
            ml_open_file (buf);
}

void ml_recover (void) {
    buf_T *buf = NULL;
    memfile_T *mfp = NULL;
    char_u *fname;
    char_u *fname_used = NULL;
    bhdr_T *hp = NULL;
    ZERO_BL *b0p;
    int b0_ff;
    char_u *b0_fenc = NULL;
    int b0_cm = -1;
    PTR_BL *pp;
    DATA_BL *dp;
    infoptr_T *ip;
    blocknr_T bnum;
    int page_count;
    stat_T org_stat, swp_stat;
    int len;
    int directly;
    linenr_T lnum;
    char_u *p;
    int i;
    long  error;
    int cannot_open;
    linenr_T line_count;
    int has_error;
    int idx;
    int top;
    int txt_start;
    off_T size;
    int called_from_main;
    int serious_error = TRUE;
    long  mtime;
    int attr;
    int orig_file_status = NOTDONE;
    recoverymode = TRUE;
    called_from_main = (curbuf->b_ml.ml_mfp == NULL);
    attr = HL_ATTR (HLF_E);
    fname = curbuf->b_fname;
    if (fname == NULL)
        fname = (char_u *) "";
    len = (int) STRLEN (fname);
    if (len >= 4 && STRNICMP (fname +len - 4, ".s", 2) == 0 && vim_strchr ((char_u *) "abcdefghijklmnopqrstuvw", TOLOWER_ASC (fname[len - 2])) != NULL && ASCII_ISALPHA (fname[len - 1])) {
        directly = TRUE;
        fname_used = vim_strsave (fname);
    }
    else {
        directly = FALSE;
        len = recover_names (fname, FALSE, 0, NULL);
        if (len == 0) {
            EMSG2 (_ ("E305: No swap file found for %s"), fname);
            goto theend;
        }
        if (len == 1)
            i = 1;
        else {
            (void) recover_names (fname, TRUE, 0, NULL);
            msg_putchar ('\n');
            MSG_PUTS (_ ("Enter number of swap file to use (0 to quit): "));
            i = get_number (FALSE, NULL);
            if (i < 1 || i > len)
                goto theend;
        }
        (void) recover_names (fname, FALSE, i, &fname_used);
    }
    if (fname_used == NULL)
        goto theend;
    if (called_from_main && ml_open (curbuf) == FAIL)
        getout (1);
    buf = (buf_T *) alloc ((unsigned ) sizeof (buf_T));
    if (buf == NULL)
        goto theend;
    buf->b_ml.ml_stack_size = 0;
    buf->b_ml.ml_stack = NULL;
    buf->b_ml.ml_stack_top = 0;
    buf->b_ml.ml_line_lnum = 0;
    buf->b_ml.ml_locked = NULL;
    buf->b_ml.ml_flags = 0;
    buf->b_p_key = empty_option;
    buf->b_p_cm = empty_option;
    p = vim_strsave (fname_used);
    mfp = mf_open (fname_used, O_RDONLY);
    fname_used = p;
    if (mfp == NULL || mfp->mf_fd < 0) {
        if (fname_used != NULL)
            EMSG2 (_ ("E306: Cannot open %s"), fname_used);
        goto theend;
    }
    buf->b_ml.ml_mfp = mfp;
    mfp->mf_buffer = buf;
    mfp->mf_page_size = MIN_SWAP_PAGE_SIZE;
    if ((hp = mf_get (mfp, (blocknr_T) 0, 1)) == NULL) {
        msg_start ();
        MSG_PUTS_ATTR (_ ("Unable to read block 0 from "), attr | MSG_HIST);
        msg_outtrans_attr (mfp -> mf_fname, attr | MSG_HIST);
        MSG_PUTS_ATTR (_ ("\nMaybe no changes were made or Vim did not update the swap file."), attr | MSG_HIST);
        msg_end ();
        goto theend;
    }
    b0p = (ZERO_BL *) (hp->bh_data);
    if (STRNCMP (b0p->b0_version, "VIM 3.0", 7) == 0) {
        msg_start ();
        msg_outtrans_attr (mfp -> mf_fname, MSG_HIST);
        MSG_PUTS_ATTR (_ (" cannot be used with this version of Vim.\n"), MSG_HIST);
        MSG_PUTS_ATTR (_ ("Use Vim version 3.0.\n"), MSG_HIST);
        msg_end ();
        goto theend;
    }
    if (ml_check_b0_id (b0p) == FAIL) {
        EMSG2 (_ ("E307: %s does not look like a Vim swap file"), mfp -> mf_fname);
        goto theend;
    }
    if (b0_magic_wrong (b0p)) {
        msg_start ();
        msg_outtrans_attr (mfp -> mf_fname, attr | MSG_HIST);
        MSG_PUTS_ATTR (_ (" cannot be used on this computer.\n"), attr | MSG_HIST);
        MSG_PUTS_ATTR (_ ("The file was created on "), attr | MSG_HIST);
        b0p->b0_fname[0] = NUL;
        MSG_PUTS_ATTR (b0p -> b0_hname, attr | MSG_HIST);
        MSG_PUTS_ATTR (_ (",\nor the file has been damaged."), attr | MSG_HIST);
        msg_end ();
        goto theend;
    }
    for (i = 0; i < (int) (sizeof (id1_codes) / sizeof (int)); ++i)
        if (id1_codes[i] == b0p->b0_id[1])
            b0_cm = i;
    if (b0_cm > 0)
        mch_memmove (mfp->mf_seed, &b0p->b0_seed, MF_SEED_LEN);
    crypt_set_cm_option (buf, b0_cm < 0 ? 0 : b0_cm);
    if (mfp->mf_page_size != (unsigned ) char_to_long (b0p->b0_page_size)) {
        unsigned  previous_page_size = mfp->mf_page_size;
        mf_new_page_size (mfp, (unsigned) char_to_long (b0p -> b0_page_size));
        if (mfp->mf_page_size < previous_page_size) {
            msg_start ();
            msg_outtrans_attr (mfp -> mf_fname, attr | MSG_HIST);
            MSG_PUTS_ATTR (_ (" has been damaged (page size is smaller than minimum value).\n"), attr | MSG_HIST);
            msg_end ();
            goto theend;
        }
        if ((size = vim_lseek (mfp->mf_fd, (off_T) 0L, SEEK_END)) <= 0)
            mfp->mf_blocknr_max = 0;
        else
            mfp->mf_blocknr_max = (blocknr_T) (size / mfp->mf_page_size);
        mfp->mf_infile_count = mfp->mf_blocknr_max;
        p = alloc (mfp->mf_page_size);
        if (p == NULL)
            goto theend;
        mch_memmove (p, hp -> bh_data, previous_page_size);
        vim_free (hp -> bh_data);
        hp->bh_data = p;
        b0p = (ZERO_BL *) (hp->bh_data);
    }
    if (directly) {
        expand_env (b0p -> b0_fname, NameBuff, MAXPATHL);
        if (setfname (curbuf, NameBuff, NULL, TRUE) == FAIL)
            goto theend;
    }
    home_replace (NULL, mfp -> mf_fname, NameBuff, MAXPATHL, TRUE);
    smsg ((char_u *) _ ("Using swap file \"%s\""), NameBuff);
    if (buf_spname (curbuf) != NULL)
        vim_strncpy (NameBuff, buf_spname (curbuf), MAXPATHL -1);
    else
        home_replace (NULL, curbuf->b_ffname, NameBuff, MAXPATHL, TRUE);
    smsg ((char_u *) _ ("Original file \"%s\""), NameBuff);
    msg_putchar ('\n');
    mtime = char_to_long (b0p->b0_mtime);
    if (curbuf->b_ffname != NULL && mch_stat ((char *) curbuf->b_ffname, &org_stat) != -1 && ((mch_stat ((char *) mfp->mf_fname, &swp_stat) != -1 && org_stat.st_mtime > swp_stat.st_mtime) || org_stat.st_mtime != mtime)) {
        EMSG (_ ("E308: Warning: Original file may have been changed"));
    }
    out_flush ();
    b0_ff = (b0p->b0_flags & B0_FF_MASK);
    if (b0p->b0_flags & B0_HAS_FENC) {
        int fnsize = B0_FNAME_SIZE_NOCRYPT;
        if (b0p->b0_id[1] != BLOCK0_ID1)
            fnsize = B0_FNAME_SIZE_CRYPT;
        for (p = b0p->b0_fname + fnsize; p > b0p->b0_fname && p[-1] != NUL; --p)
            ;
        b0_fenc = vim_strnsave (p, (int) (b0p->b0_fname + fnsize - p));
    }
    mf_put (mfp, hp, FALSE, FALSE);
    hp = NULL;
    while (!(curbuf->b_ml.ml_flags & ML_EMPTY))
        ml_delete ((linenr_T) 1, FALSE);
    if (curbuf->b_ffname != NULL)
        orig_file_status = readfile (curbuf->b_ffname, NULL, (linenr_T) 0, (linenr_T) 0, (linenr_T) MAXLNUM, NULL, READ_NEW);
    if (b0_cm >= 0) {
        if (*curbuf->b_p_key != NUL) {
            smsg ((char_u *) _ ("Swap file is encrypted: \"%s\""), fname_used);
            MSG_PUTS (_ ("\nIf you entered a new crypt key but did not write the text file,"));
            MSG_PUTS (_ ("\nenter the new crypt key."));
            MSG_PUTS (_ ("\nIf you wrote the text file after changing the crypt key press enter"));
            MSG_PUTS (_ ("\nto use the same key for text file and swap file"));
        }
        else
            smsg ((char_u *) _ (need_key_msg), fname_used);
        buf->b_p_key = crypt_get_key (FALSE, FALSE);
        if (buf->b_p_key == NULL)
            buf->b_p_key = curbuf->b_p_key;
        else if (*buf->b_p_key == NUL) {
            vim_free (buf -> b_p_key);
            buf->b_p_key = curbuf->b_p_key;
        }
        if (buf->b_p_key == NULL)
            buf->b_p_key = empty_option;
    }
    if (b0_ff != 0)
        set_fileformat (b0_ff -1, OPT_LOCAL);
    if (b0_fenc != NULL) {
        set_option_value ((char_u *) "fenc", 0L, b0_fenc, OPT_LOCAL);
        vim_free (b0_fenc);
    }
    unchanged (curbuf, TRUE);
    bnum = 1;
    page_count = 1;
    lnum = 0;
    line_count = 0;
    idx = 0;
    error = 0;
    buf->b_ml.ml_stack_top = 0;
    buf->b_ml.ml_stack = NULL;
    buf->b_ml.ml_stack_size = 0;
    if (curbuf->b_ffname == NULL)
        cannot_open = TRUE;
    else
        cannot_open = FALSE;
    serious_error = FALSE;
    for (; !got_int; line_breakcheck ()) {
        if (hp != NULL)
            mf_put (mfp, hp, FALSE, FALSE);
        if ((hp = mf_get (mfp, (blocknr_T) bnum, page_count)) == NULL) {
            if (bnum == 1) {
                EMSG2 (_ ("E309: Unable to read block 1 from %s"), mfp -> mf_fname);
                goto theend;
            }
            ++error;
            ml_append (lnum ++, (char_u *) _ ("???MANY LINES MISSING"), (colnr_T) 0, TRUE);
        }
        else {
            pp = (PTR_BL *) (hp->bh_data);
            if (pp->pb_id == PTR_ID) {
                if (idx == 0 && line_count != 0) {
                    for (i = 0; i < (int) pp->pb_count; ++i)
                        line_count -= pp->pb_pointer[i].pe_line_count;
                    if (line_count != 0) {
                        ++error;
                        ml_append (lnum ++, (char_u *) _ ("???LINE COUNT WRONG"), (colnr_T) 0, TRUE);
                    }
                }
                if (pp->pb_count == 0) {
                    ml_append (lnum ++, (char_u *) _ ("???EMPTY BLOCK"), (colnr_T) 0, TRUE);
                    ++error;
                }
                else if (idx < (int) pp->pb_count) {
                    if (pp->pb_pointer[idx].pe_bnum < 0) {
                        if (!cannot_open) {
                            line_count = pp->pb_pointer[idx].pe_line_count;
                            if (readfile (curbuf->b_ffname, NULL, lnum, pp->pb_pointer[idx].pe_old_lnum - 1, line_count, NULL, 0) != OK)
                                cannot_open = TRUE;
                            else
                                lnum += line_count;
                        }
                        if (cannot_open) {
                            ++error;
                            ml_append (lnum ++, (char_u *) _ ("???LINES MISSING"), (colnr_T) 0, TRUE);
                        }
                        ++idx;
                        continue;
                    }
                    if ((top = ml_add_stack (buf)) < 0) {
                        ++error;
                        break;
                    }
                    ip = &(buf->b_ml.ml_stack[top]);
                    ip->ip_bnum = bnum;
                    ip->ip_index = idx;
                    bnum = pp->pb_pointer[idx].pe_bnum;
                    line_count = pp->pb_pointer[idx].pe_line_count;
                    page_count = pp->pb_pointer[idx].pe_page_count;
                    idx = 0;
                    continue;
                }
            }
            else {
                dp = (DATA_BL *) (hp->bh_data);
                if (dp->db_id != DATA_ID) {
                    if (bnum == 1) {
                        EMSG2 (_ ("E310: Block 1 ID wrong (%s not a .swp file?)"), mfp -> mf_fname);
                        goto theend;
                    }
                    ++error;
                    ml_append (lnum ++, (char_u *) _ ("???BLOCK MISSING"), (colnr_T) 0, TRUE);
                }
                else {
                    has_error = FALSE;
                    if (page_count * mfp->mf_page_size != dp->db_txt_end) {
                        ml_append (lnum ++, (char_u *) _ ("??? from here until ???END lines may be messed up"), (colnr_T) 0, TRUE);
                        ++error;
                        has_error = TRUE;
                        dp->db_txt_end = page_count * mfp->mf_page_size;
                    }
                    *((char_u *) dp + dp->db_txt_end - 1) = NUL;
                    if (line_count != dp->db_line_count) {
                        ml_append (lnum ++, (char_u *) _ ("??? from here until ???END lines may have been inserted/deleted"), (colnr_T) 0, TRUE);
                        ++error;
                        has_error = TRUE;
                    }
                    for (i = 0; i < dp->db_line_count; ++i) {
                        txt_start = (dp->db_index[i] & DB_INDEX_MASK);
                        if (txt_start <= (int) HEADER_SIZE || txt_start >= (int) dp->db_txt_end) {
                            p = (char_u *) "???";
                            ++error;
                        }
                        else
                            p = (char_u *) dp + txt_start;
                        ml_append (lnum ++, p, (colnr_T) 0, TRUE);
                    }
                    if (has_error)
                        ml_append (lnum++, (char_u *) _ ("???END"), (colnr_T) 0, TRUE);
                }
            }
        }
        if (buf->b_ml.ml_stack_top == 0)
            break;
        ip = &(buf->b_ml.ml_stack[--(buf->b_ml.ml_stack_top)]);
        bnum = ip->ip_bnum;
        idx = ip->ip_index + 1;
        page_count = 1;
    }
    if (orig_file_status != OK || curbuf->b_ml.ml_line_count != lnum * 2 + 1) {
        if (!(curbuf->b_ml.ml_line_count == 2 && *ml_get (1) == NUL)) {
            changed_int ();
            ++CHANGEDTICK (curbuf);
        }
    }
    else {
        for (idx = 1; idx <= lnum; ++idx) {
            p = vim_strsave (ml_get (idx));
            i = STRCMP (p, ml_get (idx + lnum));
            vim_free (p);
            if (i != 0) {
                changed_int ();
                ++CHANGEDTICK (curbuf);
                break;
            }
        }
    }
    while (curbuf->b_ml.ml_line_count > lnum && !(curbuf->b_ml.ml_flags & ML_EMPTY))
        ml_delete (curbuf->b_ml.ml_line_count, FALSE);
    curbuf->b_flags |= BF_RECOVERED;
    recoverymode = FALSE;
    if (got_int)
        EMSG (_ ("E311: Recovery Interrupted"));
    else if (error) {
        ++no_wait_return;
        MSG (">>>>>>>>>>>>>");
        EMSG (_ ("E312: Errors detected while recovering; look for lines starting with ???"));
        --no_wait_return;
        MSG (_ ("See \":help E312\" for more information."));
        MSG (">>>>>>>>>>>>>");
    }
    else {
        if (curbuf->b_changed) {
            MSG (_ ("Recovery completed. You should check if everything is OK."));
            MSG_PUTS (_ ("\n(You might want to write out this file under another name\n"));
            MSG_PUTS (_ ("and run diff with the original file to check for changes)"));
        }
        else
            MSG (_ ("Recovery completed. Buffer contents equals file contents."));
        MSG_PUTS (_ ("\nYou may want to delete the .swp file now.\n\n"));
        cmdline_row = msg_row;
    }
    if (*buf->b_p_key != NUL && STRCMP (curbuf->b_p_key, buf->b_p_key) != 0) {
        MSG_PUTS (_ ("Using crypt key from swap file for the text file.\n"));
        set_option_value ((char_u *) "key", 0L, buf -> b_p_key, OPT_LOCAL);
    }
    redraw_curbuf_later (NOT_VALID);
theend :
    vim_free (fname_used);
    recoverymode = FALSE;
    if (mfp != NULL) {
        if (hp != NULL)
            mf_put (mfp, hp, FALSE, FALSE);
        mf_close (mfp, FALSE);
    }
    if (buf != NULL) {
        if (buf->b_p_key != curbuf->b_p_key)
            free_string_option (buf->b_p_key);
        free_string_option (buf -> b_p_cm);
        vim_free (buf -> b_ml.ml_stack);
        vim_free (buf);
    }
    if (serious_error && called_from_main)
        ml_close (curbuf, TRUE);
    else {
        apply_autocmds (EVENT_BUFREADPOST, NULL, curbuf -> b_fname, FALSE, curbuf);
        apply_autocmds (EVENT_BUFWINENTER, NULL, curbuf -> b_fname, FALSE, curbuf);
    }
    return;
}

int recover_names (char_u *fname, int list, int nr, char_u **fname_out) {
    int num_names;
    char_u * (names [6]);
    char_u *tail;
    char_u *p;
    int num_files;
    int file_count = 0;
    char_u **files;
    int i;
    char_u *dirp;
    char_u *dir_name;
    char_u *fname_res = NULL;
    if (fname != NULL) {
        fname_res = fname;
    }
    if (list) {
        msg ((char_u *) _ ("Swap files found:"));
        msg_putchar ('\n');
    }
    dir_name = alloc ((unsigned ) STRLEN (p_dir) + 1);
    dirp = p_dir;
    while (dir_name != NULL && *dirp) {
        (void) copy_option_part (&dirp, dir_name, 31000, ",");
        if (dir_name[0] == '.' && dir_name[1] == NUL) {
            if (fname == NULL) {
                names[0] = vim_strsave ((char_u *) "*.sw?");
                names[1] = vim_strsave ((char_u *) ".*.sw?");
                names[2] = vim_strsave ((char_u *) ".sw?");
                num_names = 3;
            }
            else
                num_names = recov_file_names (names, fname_res, TRUE);
        }
        else {
            if (fname == NULL) {
                names[0] = concat_fnames (dir_name, (char_u *) "*.sw?", TRUE);
                names[1] = concat_fnames (dir_name, (char_u *) ".*.sw?", TRUE);
                names[2] = concat_fnames (dir_name, (char_u *) ".sw?", TRUE);
                num_names = 3;
            }
            else {
                int len = (int) STRLEN (dir_name);
                p = dir_name + len;
                if (after_pathsep (dir_name, p) && len > 1 && p[-1] == p[-2]) {
                    tail = make_percent_swname (dir_name, fname_res);
                }
                else {
                    tail = gettail (fname_res);
                    tail = concat_fnames (dir_name, tail, TRUE);
                }
                if (tail == NULL)
                    num_names = 0;
                else {
                    num_names = recov_file_names (names, tail, FALSE);
                    vim_free (tail);
                }
            }
        }
        for (i = 0; i < num_names; ++i) {
            if (names[i] == NULL) {
                for (i = 0; i < num_names; ++i)
                    vim_free (names[i]);
                num_names = 0;
            }
        }
        if (num_names == 0)
            num_files = 0;
        else if (expand_wildcards (num_names, names, &num_files, &files, EW_KEEPALL | EW_FILE | EW_SILENT) == FAIL)
            num_files = 0;
        if (*dirp == NUL && file_count + num_files == 0 && fname != NULL) {
            stat_T st;
            char_u *swapname;
            swapname = modname (fname_res, (char_u *) ".swp", TRUE);
            if (swapname != NULL) {
                if (mch_stat ((char *) swapname, &st) != -1) {
                    files = (char_u **) alloc ((unsigned ) sizeof (char_u *));
                    if (files != NULL) {
                        files[0] = swapname;
                        swapname = NULL;
                        num_files = 1;
                    }
                }
                vim_free (swapname);
            }
        }
        if (curbuf->b_ml.ml_mfp != NULL && (p = curbuf->b_ml.ml_mfp->mf_fname) != NULL) {
            for (i = 0; i < num_files; ++i)
                if (fullpathcmp (p, files[i], TRUE) & FPC_SAME) {
                    vim_free (files [i]);
                    if (--num_files == 0)
                        vim_free (files);
                    else
                        for (; i < num_files; ++i)
                            files[i] = files[i + 1];
                }
        }
        if (nr > 0) {
            file_count += num_files;
            if (nr <= file_count) {
                *fname_out = vim_strsave (files[nr - 1 + num_files - file_count]);
                dirp = (char_u *) "";
            }
        }
        else if (list) {
            if (dir_name[0] == '.' && dir_name[1] == NUL) {
                if (fname == NULL)
                    MSG_PUTS (_ ("   In current directory:\n"));
                else
                    MSG_PUTS (_ ("   Using specified name:\n"));
            }
            else {
                MSG_PUTS (_ ("   In directory "));
                msg_home_replace (dir_name);
                MSG_PUTS (":\n");
            }
            if (num_files) {
                for (i = 0; i < num_files; ++i) {
                    msg_outnum ((long) ++ file_count);
                    MSG_PUTS (".    ");
                    msg_puts (gettail (files [i]));
                    msg_putchar ('\n');
                    (void) swapfile_info (files[i]);
                }
            }
            else
                MSG_PUTS (_ ("      -- none --\n"));
            out_flush ();
        }
        else
            file_count += num_files;
        for (i = 0; i < num_names; ++i)
            vim_free (names[i]);
        if (num_files > 0)
            FreeWild (num_files, files);
    }
    vim_free (dir_name);
    return file_count;
}

static int recov_file_names (char_u **names, char_u *path, int prepend_dot) {
    int num_names;
    char_u *p;
    int i;
    int shortname = curbuf->b_shortname;
    curbuf->b_shortname = FALSE;
    num_names = 0;
    if (prepend_dot) {
        names[num_names] = modname (path, (char_u *) ".sw?", TRUE);
        if (names[num_names] == NULL)
            goto end;
        ++num_names;
    }
    names[num_names] = concat_fnames (path, (char_u *) ".sw?", FALSE);
    if (names[num_names] == NULL)
        goto end;
    if (num_names >= 1) {
        p = names[num_names - 1];
        i = (int) STRLEN (names[num_names - 1]) - (int) STRLEN (names[num_names]);
        if (i > 0)
            p += i;
        if (STRCMP (p, names[num_names]) != 0)
            ++num_names;
        else
            vim_free (names[num_names]);
    }
    else
        ++num_names;
    curbuf->b_shortname = TRUE;
    names[num_names] = modname (path, (char_u *) ".sw?", FALSE);
    if (names[num_names] == NULL)
        goto end;
    p = names[num_names];
    i = STRLEN (names[num_names]) - STRLEN (names[num_names - 1]);
    if (i > 0)
        p += i;
    if (STRCMP (names[num_names - 1], p) == 0)
        vim_free (names[num_names]);
    else
        ++num_names;
end :
    curbuf->b_shortname = shortname;
    return num_names;
}

static time_t swapfile_info (char_u *fname) {
    stat_T st;
    int fd;
    struct block0 b0;
    time_t x = (time_t) 0;
    char *p;
    char_u uname [B0_UNAME_SIZE];
    if (mch_stat ((char *) fname, &st) != -1) {
        if (mch_get_uname (st.st_uid, uname, B0_UNAME_SIZE) == OK) {
            MSG_PUTS (_ ("          owned by: "));
            msg_outtrans (uname);
            MSG_PUTS (_ ("   dated: "));
        }
        else
            MSG_PUTS (_ ("             dated: "));
        x = st.st_mtime;
        p = ctime (&x);
        if (p == NULL)
            MSG_PUTS ("(invalid)\n");
        else
            MSG_PUTS (p);
    }
    fd = mch_open ((char *) fname, O_RDONLY | O_EXTRA, 0);
    if (fd >= 0) {
        if (read_eintr (fd, &b0, sizeof (b0)) == sizeof (b0)) {
            if (STRNCMP (b0.b0_version, "VIM 3.0", 7) == 0) {
                MSG_PUTS (_ ("         [from Vim version 3.0]"));
            }
            else if (ml_check_b0_id (&b0) == FAIL) {
                MSG_PUTS (_ ("         [does not look like a Vim swap file]"));
            }
            else {
                MSG_PUTS (_ ("         file name: "));
                if (b0.b0_fname[0] == NUL)
                    MSG_PUTS (_ ("[No Name]"));
                else
                    msg_outtrans (b0.b0_fname);
                MSG_PUTS (_ ("\n          modified: "));
                MSG_PUTS (b0.b0_dirty ? _ ("YES") : _ ("no"));
                if (*(b0.b0_uname) != NUL) {
                    MSG_PUTS (_ ("\n         user name: "));
                    msg_outtrans (b0.b0_uname);
                }
                if (*(b0.b0_hname) != NUL) {
                    if (*(b0.b0_uname) != NUL)
                        MSG_PUTS (_ ("   host name: "));
                    else
                        MSG_PUTS (_ ("\n         host name: "));
                    msg_outtrans (b0.b0_hname);
                }
                if (char_to_long (b0.b0_pid) != 0L) {
                    MSG_PUTS (_ ("\n        process ID: "));
                    msg_outnum (char_to_long (b0.b0_pid));
                    if (kill ((pid_t) char_to_long (b0.b0_pid), 0) == 0) {
                        MSG_PUTS (_ (" (still running)"));
                        process_still_running = TRUE;
                    }
                }
                if (b0_magic_wrong (&b0)) {
                    MSG_PUTS (_ ("\n         [not usable on this computer]"));
                }
            }
        }
        else
            MSG_PUTS (_ ("         [cannot be read]"));
        close (fd);
    }
    else
        MSG_PUTS (_ ("         [cannot be opened]"));
    msg_putchar ('\n');
    return x;
}

static long  char_to_long (char_u *s) {
    long  retval;
    retval = s[3];
    retval <<= 8;
    retval |= s[2];
    retval <<= 8;
    retval |= s[1];
    retval <<= 8;
    retval |= s[0];
    return retval;
}

static int b0_magic_wrong (ZERO_BL *b0p) {
    return (b0p->b0_magic_long != (long ) B0_MAGIC_LONG || b0p->b0_magic_int != (int) B0_MAGIC_INT || b0p->b0_magic_short != (short ) B0_MAGIC_SHORT || b0p->b0_magic_char != B0_MAGIC_CHAR);
}

void ml_setname (buf_T *buf) {
    int success = FALSE;
    memfile_T *mfp;
    char_u *fname;
    char_u *dirp;
    mfp = buf->b_ml.ml_mfp;
    if (mfp->mf_fd < 0) {
        if (p_uc != 0 && !cmdmod.noswapfile)
            ml_open_file (buf);
        return;
    }
    dirp = p_dir;
    for (;;) {
        if (*dirp == NUL)
            break;
        fname = findswapname (buf, &dirp, mfp->mf_fname);
        if (dirp == NULL)
            break;
        if (fname == NULL)
            continue;
        if (fnamecmp (fname, mfp->mf_fname) == 0) {
            vim_free (fname);
            success = TRUE;
            break;
        }
        if (mfp->mf_fd >= 0) {
            close (mfp -> mf_fd);
            mfp->mf_fd = -1;
        }
        if (vim_rename (mfp->mf_fname, fname) == 0) {
            success = TRUE;
            vim_free (mfp -> mf_fname);
            mfp->mf_fname = fname;
            vim_free (mfp -> mf_ffname);
            mf_set_ffname (mfp);
            ml_upd_block0 (buf, UB_SAME_DIR);
            break;
        }
        vim_free (fname);
    }
    if (mfp->mf_fd == -1) {
        mfp->mf_fd = mch_open ((char *) mfp->mf_fname, O_RDWR | O_EXTRA, 0);
        if (mfp->mf_fd < 0) {
            EMSG (_ ("E301: Oops, lost the swap file!!!"));
            return;
        }
    }
    if (!success)
        EMSG (_ ("E302: Could not rename swap file"));
}

void ml_timestamp (buf_T *buf) {
    ml_upd_block0 (buf, UB_FNAME);
}

int ml_delete (linenr_T lnum, int message) {
    ml_flush_line (curbuf);
    return ml_delete_int (curbuf, lnum, message);
}

void ml_preserve (buf_T *buf, int message) {
    bhdr_T *hp;
    linenr_T lnum;
    memfile_T *mfp = buf->b_ml.ml_mfp;
    int status;
    int got_int_save = got_int;
    if (mfp == NULL || mfp->mf_fname == NULL) {
        if (message)
            EMSG (_ ("E313: Cannot preserve, there is no swap file"));
        return;
    }
    got_int = FALSE;
    ml_flush_line (buf);
    (void) ml_find_line (buf, (linenr_T) 0, ML_FLUSH);
    status = mf_sync (mfp, MFS_ALL | MFS_FLUSH);
    buf->b_ml.ml_stack_top = 0;
    if (mf_need_trans (mfp) && !got_int) {
        lnum = 1;
        while (mf_need_trans (mfp) && lnum <= buf->b_ml.ml_line_count) {
            hp = ml_find_line (buf, lnum, ML_FIND);
            if (hp == NULL) {
                status = FAIL;
                goto theend;
            }
            CHECK (buf -> b_ml.ml_locked_low != lnum, "low != lnum");
            lnum = buf->b_ml.ml_locked_high + 1;
        }
        (void) ml_find_line (buf, (linenr_T) 0, ML_FLUSH);
        if (mf_sync (mfp, MFS_ALL | MFS_FLUSH) == FAIL)
            status = FAIL;
        buf->b_ml.ml_stack_top = 0;
    }
theend :
    got_int |= got_int_save;
    if (message) {
        if (status == OK)
            MSG (_ ("File preserved"));
        else
            EMSG (_ ("E314: Preserve failed"));
    }
}

int ml_append (linenr_T lnum, char_u *line, colnr_T len, int newfile) {
    if (curbuf->b_ml.ml_mfp == NULL && open_buffer (FALSE, NULL, 0) == FAIL)
        return FAIL;
    if (curbuf->b_ml.ml_line_lnum != 0)
        ml_flush_line (curbuf);
    return ml_append_int (curbuf, lnum, line, len, newfile, FALSE);
}

int ml_line_alloced (void) {
    return (curbuf->b_ml.ml_flags & ML_LINE_DIRTY);
}

void check_need_swap (int newfile) {
    if (curbuf->b_may_swap && (!curbuf->b_p_ro || !newfile))
        ml_open_file (curbuf);
}

static int do_swapexists (buf_T *buf, char_u *fname) {
    set_vim_var_string (VV_SWAPNAME, fname, - 1);
    set_vim_var_string (VV_SWAPCHOICE, NULL, - 1);
    ++allbuf_lock;
    apply_autocmds (EVENT_SWAPEXISTS, buf -> b_fname, NULL, FALSE, NULL);
    --allbuf_lock;
    set_vim_var_string (VV_SWAPNAME, NULL, - 1);
    switch (*get_vim_var_str (VV_SWAPCHOICE)) {
    case 'o' :
        return 1;
    case 'e' :
        return 2;
    case 'r' :
        return 3;
    case 'd' :
        return 4;
    case 'q' :
        return 5;
    case 'a' :
        return 6;
    }
    return 0;
}

static void attention_message (buf_T *buf, char_u *fname) {
    stat_T st;
    time_t x, sx;
    char *p;
    ++no_wait_return;
    (void) EMSG (_ ("E325: ATTENTION"));
    MSG_PUTS (_ ("\nFound a swap file by the name \""));
    msg_home_replace (fname);
    MSG_PUTS ("\"\n");
    sx = swapfile_info (fname);
    MSG_PUTS (_ ("While opening file \""));
    msg_outtrans (buf -> b_fname);
    MSG_PUTS ("\"\n");
    if (mch_stat ((char *) buf->b_fname, &st) != -1) {
        MSG_PUTS (_ ("             dated: "));
        x = st.st_mtime;
        p = ctime (&x);
        if (p == NULL)
            MSG_PUTS ("(invalid)\n");
        else
            MSG_PUTS (p);
        if (sx != 0 && x > sx)
            MSG_PUTS (_ ("      NEWER than swap file!\n"));
    }
    MSG_PUTS (_ ("\n(1) Another program may be editing the same file.  If this is the case,\n    be careful not to end up with two different instances of the same\n    file when making changes.  Quit, or continue with caution.\n"));
    MSG_PUTS (_ ("(2) An edit session for this file crashed.\n"));
    MSG_PUTS (_ ("    If this is the case, use \":recover\" or \"vim -r "));
    msg_outtrans (buf -> b_fname);
    MSG_PUTS (_ ("\"\n    to recover the changes (see \":help recovery\").\n"));
    MSG_PUTS (_ ("    If you did this already, delete the swap file \""));
    msg_outtrans (fname);
    MSG_PUTS (_ ("\"\n    to avoid this message.\n"));
    cmdline_row = msg_row;
    --no_wait_return;
}

