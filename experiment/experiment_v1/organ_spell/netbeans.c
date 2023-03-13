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
struct msglist {
    char_u *msg;
    char_u *throw_msg;
    struct msglist *next;
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
struct eslist_elem {
    int saved_emsg_silent;
    eslist_T *next;
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
struct buffblock {
    buffblock_T *b_next;
    char_u b_str [1];
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
struct w_line {
    linenr_T wl_lnum;
    short_u wl_size;
    char wl_valid;
    char wl_folded;
    linenr_T wl_lastlnum;
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
struct growarray {
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    int ga_growsize;
    void *ga_data;
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
struct argentry {
    char_u *ae_fname;
    int ae_fnum;
};
struct arglist {
    garray_T al_ga;
    int al_refcount;
    int id;
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
struct signlist {
    int id;
    linenr_T lnum;
    int typenr;
    signlist_T *next;
    signlist_T *prev;
};
struct keyqueue {
    char_u *keystr;
    struct keyqueue *next;
    struct keyqueue *prev;
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
struct readq_S {
    char_u *rq_buffer;
    long_u rq_buflen;
    readq_T *rq_next;
    readq_T *rq_prev;
};
struct nbbuf_struct {
    buf_T *bufp;
    unsigned  int fireChanges : 1;
    unsigned  int initDone : 1;
    unsigned  int insertDone : 1;
    unsigned  int modified : 1;
    int nbbuf_number;
    char *displayname;
    int *signmap;
    short_u signmaplen;
    short_u signmapused;
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
EXTERN char_u *globaldir INIT (= NULL);
EXTERN char_u e_listreq [] INIT (= N_ ("E714: List required"));
EXTERN alist_T global_alist;
EXTERN char_u e_readonlyvar [] INIT (= N_ ("E46: Cannot change read-only variable \"%s\""));
EXTERN char_u e_noroom [] INIT (= N_ ("E36: Not enough room"));
EXTERN char need_key_msg [] INIT (= N_ ("Need encryption key for \"%s\""));
EXTERN char_u no_lines_msg [] INIT (= N_ ("--No lines in buffer--"));
EXTERN struct msglist **msg_list INIT (= NULL);
EXTERN char_u e_umark [] INIT (= N_ ("E78: Unknown mark"));
EXTERN char_u e_marknotset [] INIT (= N_ ("E20: Mark not set"));
EXTERN int arrow_used;
EXTERN int mouse_row;
EXTERN int msg_row;
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
EXTERN FILE *scriptout INIT (= NULL);
EXTERN FILE *scriptin [NSCRIPT];
EXTERN char_u *use_gvimrc INIT (= NULL);
EXTERN except_T *caught_stack INIT (= NULL);
EXTERN int called_emsg;
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
EXTERN int p_exrc;
EXTERN char_u *p_dict;
EXTERN char_u *p_inc;
EXTERN char_u *p_cpo;
EXTERN char_u *p_cot;
EXTERN int p_cp;
EXTERN long  p_ch;
EXTERN int p_beval;
EXTERN char_u *p_cm;
EXTERN char_u *p_bkc;
EXTERN proftime_T bevalexpr_due;
EXTERN char_u e_invexpr2 [] INIT (= N_ ("E15: Invalid expression: %s"));
EXTERN char_u *p_pexpr;
EXTERN char_u *p_bexpr;
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
EXTERN char_u *sourcing_name INIT (= NULL);
EXTERN char_u *p_titlestring;
EXTERN char_u *p_iconstring;
EXTERN hlf_T edit_submode_highl;
EXTERN int p_hls;
EXTERN char_u *p_hl;
EXTERN char_u *p_hlg;
EXTERN char_u e_au_recursive [] INIT (= N_ ("E952: Autocommand caused recursive behavior"));
EXTERN char_u e_secure [] INIT (= N_ ("E523: Not allowed here"));
EXTERN char_u e_positive [] INIT (= N_ ("E487: Argument must be positive"));
EXTERN char_u e_curdir [] INIT (= N_ ("E12: Command not allowed from exrc/vimrc in current dir or tag search"));
EXTERN pos_T saved_cursor;
EXTERN int current_scrollbar;
EXTERN vimmenu_T *current_menu;
EXTERN except_T *current_exception;
EXTERN int p_secure;
EXTERN char_u e_bufloaded [] INIT (= N_ ("E139: File is loaded in another buffer"));
EXTERN char_u e_nobufnr [] INIT (= N_ ("E86: Buffer %ld does not exist"));
EXTERN char_u e_invexprmsg [] INIT (= N_ ("E449: Invalid expression received"));
EXTERN char_u e_notmp [] INIT (= N_ ("E483: Can't get temp file name"));
EXTERN pos_T last_cursormoved;
EXTERN char_u msg_buf [MSG_BUF_LEN];
EXTERN buf_T *lastbuf INIT (= NULL);
EXTERN buf_T *firstbuf INIT (= NULL);
EXTERN int highlight_attr [HLF_COUNT];
EXTERN long  p_ttm;
EXTERN long  p_tm;
EXTERN int p_stmp;
EXTERN int p_lrm;
EXTERN int p_bevalterm;
EXTERN char bot_top_msg [] INIT (= N_ ("search hit BOTTOM, continuing at TOP"));
EXTERN char top_bot_msg [] INIT (= N_ ("search hit TOP, continuing at BOTTOM"));
EXTERN char_u e_winheight [] INIT (= N_ ("E591: 'winheight' cannot be smaller than 'winminheight'"));
EXTERN char_u e_notopen [] INIT (= N_ ("E484: Can't open file %s"));
EXTERN int stop_insert_mode;
EXTERN typebuf_T typebuf;
EXTERN frame_T *topframe;
EXTERN long_u scrollbar_value;
EXTERN time_T starttime;
EXTERN char_u e_emptybuf [] INIT (= N_ ("E749: empty buffer"));
EXTERN char_u e_shellempty [] INIT (= N_ ("E91: 'shell' option is empty"));
EXTERN char_u e_emptykey [] INIT (= N_ ("E713: Cannot use empty key for Dictionary"));
EXTERN char_u e_endfor [] INIT (= N_ ("E170: Missing :endfor"));
EXTERN char_u e_endwhile [] INIT (= N_ ("E170: Missing :endwhile"));
EXTERN char_u e_endtry [] INIT (= N_ ("E600: Missing :endtry"));
EXTERN char_u e_endif [] INIT (= N_ ("E171: Missing :endif"));
EXTERN char_u *empty_option INIT (= (char_u *) "");
EXTERN pos_T where_paste_started;
EXTERN win_T *au_pending_free_win INIT (= NULL);
EXTERN buf_T *au_pending_free_buf INIT (= NULL);
EXTERN tabpage_T *curtab;
EXTERN tabpage_T *first_tabpage;
EXTERN int p_confirm;
EXTERN long  p_titlelen;
const int command_count = 546;
EXTERN char_u e_zerocount [] INIT (= N_ ("E939: Positive count required"));
EXTERN char_u e_nomatch2 [] INIT (= N_ ("E480: No match: %s"));
EXTERN char_u e_nomatch [] INIT (= N_ ("E479: No match"));
EXTERN reg_extmatch_T *re_extmatch_out INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_in INIT (= NULL);
EXTERN linenr_T search_match_lines;
EXTERN char_u e_listdictarg [] INIT (= N_ ("E712: Argument of %s must be a List or Dictionary"));
EXTERN char_u e_toomanyarg [] INIT (= N_ ("E118: Too many arguments for function: %s"));
EXTERN char_u e_nolastcmd [] INIT (= N_ ("E30: No previous command line"));
EXTERN char_u e_invcmd [] INIT (= N_ ("E476: Invalid command"));
EXTERN char_u e_invargNval [] INIT (= N_ ("E475: Invalid value for argument %s: %s"));
EXTERN char_u e_invargval [] INIT (= N_ ("E475: Invalid value for argument %s"));
EXTERN char_u e_invarg2 [] INIT (= N_ ("E475: Invalid argument: %s"));
EXTERN char_u e_invarg [] INIT (= N_ ("E474: Invalid argument"));
EXTERN char_u e_argreq [] INIT (= N_ ("E471: Argument required"));
EXTERN char_u wim_flags [4];
EXTERN char breakat_flags [256];
EXTERN char_u *autocmd_match INIT (= NULL);
EXTERN int autocmd_fname_full;
EXTERN char_u *autocmd_fname INIT (= NULL);
EXTERN char_u *repeat_cmdline INIT (= NULL);
EXTERN char_u *last_cmdline INIT (= NULL);
EXTERN int searchcmdlen;
EXTERN cmdmod_T cmdmod;
EXTERN win_T *aucmd_win;
EXTERN char *font_argument INIT (= NULL);
EXTERN int cmdline_row;
EXTERN unsigned  ve_flags;
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
EXTERN char_u e_winwidth [] INIT (= N_ ("E592: 'winwidth' cannot be smaller than 'winminwidth'"));
EXTERN char_u e_listidx [] INIT (= N_ ("E684: list index out of range: %ld"));
EXTERN int ru_wid;
EXTERN int did_emsg_syntax;
EXTERN int did_uncaught_emsg;
EXTERN int did_emsg;
EXTERN int p_tbidi;
EXTERN int p_hid;
EXTERN char_u e_prev_dir [] INIT (= N_ ("E459: Cannot go back to previous directory"));
EXTERN char_u e_noprevre [] INIT (= N_ ("E35: No previous regular expression"));
EXTERN char_u e_noprev [] INIT (= N_ ("E34: No previous command"));
EXTERN win_T *prevwin INIT (= NULL);
EXTERN int modified_was_set;
EXTERN int sc_col;
EXTERN int ru_col;
EXTERN colnr_T search_match_endcol;
EXTERN int msg_col;
EXTERN int p_cc_cols [256];
EXTERN long  p_columnspace;
EXTERN int fuoptions_bgcolor;
char *ExtEdProtocolVersion = "2.5";
int globalsignmaplen = 0;
int globalsignmapused = 0;
char **globalsignmap = NULL;
EXTERN int msg_scrolled;
EXTERN char_u *IObuff;
EXTERN char_u *keep_msg INIT (= NULL);
EXTERN unsigned  swb_flags;
EXTERN int p_write;
int curPCtype = -1;
EXTERN int ignored;
EXTERN char_u *escape_chars INIT (= (char_u *) " \t\\\"|");
EXTERN long  p_verbose;
EXTERN int mouse_col;
EXTERN win_T *curwin;
EXTERN int p_acd;
int dosetvisible = FALSE;
EXTERN buf_T *curbuf INIT (= NULL);
keyQ_T keyHead;
int inAtomic = 0;
int needupdate = 0;
channel_T *nb_channel = NULL;
int buf_list_size = 0;
int buf_list_used = 0;
nbbuf_T *buf_list = NULL;
EXTERN pos_T Insstart_orig;
EXTERN pos_T Insstart;
EXTERN pos_T VIsual;
int r_cmdno;
EXTERN char_u *p_guifont;
EXTERN int p_guipty;
EXTERN int p_js;
EXTERN int p_im;
EXTERN int p_arshape;
EXTERN char_u e_maxmempat [] INIT (= N_ ("E363: pattern uses more memory than 'maxmempattern'"));

int netbeans_active (void) {
    return NETBEANS_OPEN;
}

void netbeans_inserted (buf_T *bufp, linenr_T linenr, colnr_T col, char_u *txt, int newlen) {
    char_u *buf;
    int bufno;
    nbbuf_T *nbbuf;
    pos_T pos;
    long  off;
    char_u *p;
    char_u *newtxt;
    if (!NETBEANS_OPEN)
        return;
    nbbuf = nb_bufp2nbbuf_fire (bufp, &bufno);
    if (nbbuf == NULL)
        return;
    if (nbbuf->insertDone)
        nbbuf->modified = 1;
    pos.lnum = linenr;
    pos.col = col;
    off = pos2off (bufp, &pos);
    newtxt = alloc (newlen +1);
    vim_strncpy (newtxt, txt, newlen);
    p = nb_quote (newtxt);
    if (p != NULL) {
        buf = alloc (128 + 2 * newlen);
        sprintf ((char *) buf, "%d:insert=%d %ld \"%s\"\n", bufno, r_cmdno, off, p);
        nbdebug (("EVT: %s", buf));
        nb_send ((char *) buf, "netbeans_inserted");
        vim_free (p);
        vim_free (buf);
    }
    vim_free (newtxt);
}

static nbbuf_T *nb_bufp2nbbuf_fire (buf_T *bufp, int *bufnop) {
    int bufno;
    nbbuf_T *nbbuf;
    if (!NETBEANS_OPEN || !netbeansFireChanges)
        return NULL;
    bufno = nb_getbufno (bufp);
    if (bufno <= 0)
        return NULL;
    nbbuf = nb_get_buf (bufno);
    if (nbbuf != NULL && !nbbuf->fireChanges)
        return NULL;
    *bufnop = bufno;
    return nbbuf;
}

static int nb_getbufno (buf_T *bufp) {
    int i;
    for (i = 0; i < buf_list_used; i++)
        if (buf_list[i].bufp == bufp)
            return i;
    return -1;
}

static nbbuf_T *nb_get_buf (int bufno) {
    int incr;
    if (bufno <= 0)
        return NULL;
    if (!buf_list) {
        buf_list = (nbbuf_T *) alloc_clear (100 * sizeof (nbbuf_T));
        buf_list_size = 100;
    }
    if (bufno >= buf_list_used) {
        if (bufno >= buf_list_size) {
            nbbuf_T *t_buf_list = buf_list;
            incr = bufno - buf_list_size + 90;
            buf_list_size += incr;
            buf_list = (nbbuf_T *) vim_realloc (buf_list, buf_list_size * sizeof (nbbuf_T));
            if (buf_list == NULL) {
                vim_free (t_buf_list);
                buf_list_size = 0;
                return NULL;
            }
            vim_memset (buf_list + buf_list_size - incr, 0, incr * sizeof (nbbuf_T));
        }
        while (buf_list_used <= bufno) {
            buf_list[buf_list_used].fireChanges = 1;
            ++buf_list_used;
        }
    }
    return buf_list + bufno;
}

static long  pos2off (buf_T *buf, pos_T *pos) {
    long  offset = 0;
    if (!(buf->b_ml.ml_flags & ML_EMPTY)) {
        if ((offset = ml_find_line_or_offset (buf, pos->lnum, 0)) < 0)
            return 0;
        offset += pos->col;
    }
    return offset;
}

static char_u *nb_quote (char_u *txt) {
    char_u *buf = alloc ((unsigned ) (2 * STRLEN (txt) + 1));
    char_u *p = txt;
    char_u *q = buf;
    if (buf == NULL)
        return NULL;
    for (; *p; p++) {
        switch (*p) {
        case '\"' :
        case '\\' :
            *q++ = '\\';
            *q++ = *p;
            break;
        case '\n' :
            *q++ = '\\';
            *q++ = 'n';
            break;
        case '\r' :
            *q++ = '\\';
            *q++ = 'r';
            break;
        default :
            *q++ = *p;
            break;
        }
    }
    *q = '\0';
    return buf;
}

static void nb_send (char *buf, char *fun) {
    if (nb_channel != NULL)
        channel_send (nb_channel, PART_SOCK, (char_u *) buf, (int) STRLEN (buf), fun);
}

void netbeans_parse_messages (void) {
    readq_T *node;
    char_u *buffer;
    char_u *p;
    int own_node;
    while (nb_channel != NULL) {
        node = channel_peek (nb_channel, PART_SOCK);
        if (node == NULL)
            break;
        p = channel_first_nl (node);
        if (p == NULL) {
            if (channel_collapse (nb_channel, PART_SOCK, TRUE) == FAIL)
                return;
            continue;
        }
        *p++ = NUL;
        if (*p == NUL) {
            own_node = TRUE;
            buffer = channel_get (nb_channel, PART_SOCK);
        }
        else {
            own_node = FALSE;
            buffer = node->rq_buffer;
        }
        nb_parse_cmd (buffer);
        if (own_node)
            vim_free (buffer);
        else if (nb_channel != NULL)
            channel_consume (nb_channel, PART_SOCK, (int) (p - buffer));
    }
}

static void nb_parse_cmd (char_u *cmd) {
    char *verb;
    char *q;
    int bufno;
    int isfunc = -1;
    if (STRCMP (cmd, "DISCONNECT") == 0) {
        netbeans_close ();
        getout (0);
    }
    if (STRCMP (cmd, "DETACH") == 0) {
        buf_T *buf;
        FOR_ALL_BUFFERS (buf)
            buf->b_has_sign_column = FALSE;
        netbeans_close ();
        return;
    }
    bufno = strtol ((char *) cmd, &verb, 10);
    if (*verb != ':') {
        nbdebug (("    missing colon: %s\n", cmd));
        EMSG2 ("E627: missing colon: %s", cmd);
        return;
    }
    ++verb;
    for (q = verb; *q; q++) {
        if (*q == '!') {
            *q++ = NUL;
            isfunc = 0;
            break;
        }
        else if (*q == '/') {
            *q++ = NUL;
            isfunc = 1;
            break;
        }
    }
    if (isfunc < 0) {
        nbdebug (("    missing ! or / in: %s\n", cmd));
        EMSG2 ("E628: missing ! or / in: %s", cmd);
        return;
    }
    r_cmdno = strtol (q, &q, 10);
    q = (char *) skipwhite ((char_u *) q);
    if (nb_do_cmd (bufno, (char_u *) verb, isfunc, r_cmdno, (char_u *) q) == FAIL) {
    }
}

static void netbeans_close (void) {
    if (NETBEANS_OPEN) {
        netbeans_send_disconnect ();
        if (nb_channel != NULL) {
            channel_close (nb_channel, TRUE);
            channel_clear (nb_channel);
        }
        nb_channel = NULL;
    }
    bevalServers &= ~BEVAL_NETBEANS;
    needupdate = 0;
    inAtomic = 0;
    nb_free ();
    coloncmd (":sign unplace *");
    changed_window_setting ();
    update_screen (CLEAR);
    setcursor ();
    cursor_on ();
    out_flush_cursor (TRUE, FALSE);
}

#define NB_DEF_HOST "localhost"

#define NB_DEF_ADDR "3219"

#define NB_DEF_PASS "changeme"

void netbeans_send_disconnect (void) {
    char buf [128];
    if (NETBEANS_OPEN) {
        sprintf (buf, "0:disconnect=%d\n", r_cmdno);
        nbdebug (("EVT: %s", buf));
        nb_send (buf, "netbeans_disconnect");
    }
}

static void nb_free (void) {
    keyQ_T *key_node = keyHead.next;
    nbbuf_T buf;
    int i;
    for (i = 0; i < buf_list_used; i++) {
        buf = buf_list[i];
        vim_free (buf.displayname);
        vim_free (buf.signmap);
        if (buf.bufp != NULL) {
            buf.bufp->b_netbeans_file = FALSE;
            buf.bufp->b_was_netbeans_file = FALSE;
        }
    }
    VIM_CLEAR (buf_list);
    buf_list_size = 0;
    buf_list_used = 0;
    while (key_node != NULL && key_node != &keyHead) {
        keyQ_T *next = key_node->next;
        vim_free (key_node -> keystr);
        vim_free (key_node);
        if (next == &keyHead) {
            keyHead.next = &keyHead;
            keyHead.prev = &keyHead;
            break;
        }
        key_node = next;
    }
    if (nb_channel != NULL)
        channel_clear (nb_channel);
}

static void coloncmd (char *cmd, ... ) {
    char buf [1024];
    va_list ap;
    va_start (ap, cmd);
    vim_vsnprintf (buf, sizeof (buf), cmd, ap);
    va_end (ap);
    nbdebug (("    COLONCMD %s\n", buf));
    do_cmdline ((char_u *) buf, NULL, NULL, DOCMD_NOWAIT | DOCMD_KEYTYPED);
    setcursor ();
    out_flush_cursor (TRUE, FALSE);
}

void netbeans_file_killed (buf_T *bufp) {
    int bufno = nb_getbufno (bufp);
    nbbuf_T *nbbuf = nb_get_buf (bufno);
    char buffer [2 * MAXPATHL];
    if (!NETBEANS_OPEN || bufno == -1)
        return;
    nbdebug (("netbeans_file_killed:\n"));
    nbdebug (("    Killing bufno: %d", bufno));
    sprintf (buffer, "%d:killed=%d\n", bufno, r_cmdno);
    nbdebug (("EVT: %s", buffer));
    nb_send (buffer, "netbeans_file_killed");
    if (nbbuf != NULL)
        nbbuf->bufp = NULL;
}

void netbeans_unmodified (buf_T *bufp) {
}

void netbeans_deleted_all_lines (buf_T *bufp) {
    char_u buf [64];
    int bufno;
    nbbuf_T *nbbuf;
    if (!NETBEANS_OPEN)
        return;
    nbbuf = nb_bufp2nbbuf_fire (bufp, &bufno);
    if (nbbuf == NULL)
        return;
    if (nbbuf->insertDone)
        nbbuf->modified = 1;
    sprintf ((char *) buf, "%d:remove=%d 0 -1\n", bufno, r_cmdno);
    nbdebug (("EVT(suppressed): %s", buf));
}

void netbeans_end (void) {
    int i;
    static char buf [128];
    if (!NETBEANS_OPEN)
        return;
    for (i = 0; i < buf_list_used; i++) {
        if (!buf_list[i].bufp)
            continue;
        if (netbeansForcedQuit) {
            sprintf (buf, "%d:unmodified=%d\n", i, r_cmdno);
            nbdebug (("EVT: %s", buf));
            nb_send (buf, "netbeans_end");
        }
        sprintf (buf, "%d:killed=%d\n", i, r_cmdno);
        nbdebug (("EVT: %s", buf));
        nb_send (buf, NULL);
    }
}

int isNetbeansBuffer (buf_T *bufp) {
    return NETBEANS_OPEN && bufp->b_netbeans_file;
}

void netbeans_gutter_click (linenr_T lnum) {
    signlist_T *p;
    if (!NETBEANS_OPEN)
        return;
    for (p = curbuf->b_signlist; p != NULL; p = p->next) {
        if (p->lnum == lnum && p->next && p->next->lnum == lnum) {
            signlist_T *tail;
            if (p->prev)
                p->prev->next = p->next;
            else
                curbuf->b_signlist = p->next;
            p->next->prev = p->prev;
            for (tail = p->next; tail->next && tail->next->lnum == lnum && tail->next->id < GUARDEDOFFSET; tail = tail->next)
                ;
            p->next = tail->next;
            if (tail->next)
                tail->next->prev = p;
            p->prev = tail;
            tail->next = p;
            update_debug_sign (curbuf, lnum);
            break;
        }
    }
}

void netbeans_file_activated (buf_T *bufp) {
    int bufno = nb_getbufno (bufp);
    nbbuf_T *bp = nb_get_buf (bufno);
    char buffer [2 * MAXPATHL];
    char_u *q;
    if (!NETBEANS_OPEN || !bufp->b_netbeans_file || dosetvisible)
        return;
    q = nb_quote (bufp->b_ffname);
    if (q == NULL || bp == NULL)
        return;
    vim_snprintf (buffer, sizeof (buffer), "%d:fileOpened=%d \"%s\" %s %s\n", bufno, bufno, (char *) q, "T", "F");
    vim_free (q);
    nbdebug (("EVT: %s", buffer));
    nb_send (buffer, "netbeans_file_opened");
}

int isNetbeansModified (buf_T *bufp) {
    if (isNetbeansBuffer (bufp)) {
        int bufno = nb_getbufno (bufp);
        if (bufno > 0)
            return buf_list[bufno].modified;
        else
            return FALSE;
    }
    else
        return FALSE;
}

void netbeans_save_buffer (buf_T *bufp) {
    char_u buf [64];
    int bufno;
    nbbuf_T *nbbuf;
    if (!NETBEANS_OPEN)
        return;
    nbbuf = nb_bufp2nbbuf_fire (bufp, &bufno);
    if (nbbuf == NULL)
        return;
    nbbuf->modified = 0;
    sprintf ((char *) buf, "%d:save=%d\n", bufno, r_cmdno);
    nbdebug (("EVT: %s", buf));
    nb_send ((char *) buf, "netbeans_save_buffer");
}

int netbeans_is_guarded (linenr_T top, linenr_T bot) {
    signlist_T *p;
    int lnum;
    if (!NETBEANS_OPEN)
        return FALSE;
    for (p = curbuf->b_signlist; p != NULL; p = p->next)
        if (p->id >= GUARDEDOFFSET)
            for (lnum = top + 1; lnum < bot; lnum++)
                if (lnum == p->lnum)
                    return TRUE;
    return FALSE;
}

void netbeans_file_opened (buf_T *bufp) {
    int bufno = nb_getbufno (bufp);
    char buffer [2 * MAXPATHL];
    char_u *q;
    nbbuf_T *bp = nb_get_buf (nb_getbufno (bufp));
    int bnum;
    if (!NETBEANS_OPEN)
        return;
    q = nb_quote (bufp->b_ffname);
    if (q == NULL)
        return;
    if (bp != NULL)
        bnum = bufno;
    else
        bnum = 0;
    vim_snprintf (buffer, sizeof (buffer), "%d:fileOpened=%d \"%s\" %s %s\n", bnum, 0, (char *) q, "T", "F");
    vim_free (q);
    nbdebug (("EVT: %s", buffer));
    nb_send (buffer, "netbeans_file_opened");
    if (p_acd && vim_chdirfile (bufp->b_ffname, "auto") == OK)
        shorten_fnames (TRUE);
}

int netbeans_keycommand (int key) {
    char keyName [60];
    netbeans_keyname (key, keyName);
    return netbeans_keystring ((char_u *) keyName);
}

static void netbeans_keyname (int key, char *buf) {
    char *name = 0;
    char namebuf [2];
    int ctrl = 0;
    int shift = 0;
    int alt = 0;
    if (mod_mask & MOD_MASK_CTRL)
        ctrl = 1;
    if (mod_mask & MOD_MASK_SHIFT)
        shift = 1;
    if (mod_mask & MOD_MASK_ALT)
        alt = 1;
    switch (key) {
    case K_F1 :
        name = "F1";
        break;
    case K_S_F1 :
        name = "F1";
        shift = 1;
        break;
    case K_F2 :
        name = "F2";
        break;
    case K_S_F2 :
        name = "F2";
        shift = 1;
        break;
    case K_F3 :
        name = "F3";
        break;
    case K_S_F3 :
        name = "F3";
        shift = 1;
        break;
    case K_F4 :
        name = "F4";
        break;
    case K_S_F4 :
        name = "F4";
        shift = 1;
        break;
    case K_F5 :
        name = "F5";
        break;
    case K_S_F5 :
        name = "F5";
        shift = 1;
        break;
    case K_F6 :
        name = "F6";
        break;
    case K_S_F6 :
        name = "F6";
        shift = 1;
        break;
    case K_F7 :
        name = "F7";
        break;
    case K_S_F7 :
        name = "F7";
        shift = 1;
        break;
    case K_F8 :
        name = "F8";
        break;
    case K_S_F8 :
        name = "F8";
        shift = 1;
        break;
    case K_F9 :
        name = "F9";
        break;
    case K_S_F9 :
        name = "F9";
        shift = 1;
        break;
    case K_F10 :
        name = "F10";
        break;
    case K_S_F10 :
        name = "F10";
        shift = 1;
        break;
    case K_F11 :
        name = "F11";
        break;
    case K_S_F11 :
        name = "F11";
        shift = 1;
        break;
    case K_F12 :
        name = "F12";
        break;
    case K_S_F12 :
        name = "F12";
        shift = 1;
        break;
    default :
        if (key >= ' ' && key <= '~') {
            name = namebuf;
            namebuf[0] = key;
            namebuf[1] = NUL;
        }
        else
            name = "X";
        break;
    }
    buf[0] = '\0';
    if (ctrl)
        strcat (buf, "C");
    if (shift)
        strcat (buf, "S");
    if (alt)
        strcat (buf, "M");
    if (ctrl || shift || alt)
        strcat (buf, "-");
    strcat (buf, name);
}

static int netbeans_keystring (char_u *keyName) {
    char buf [2 * MAXPATHL];
    int bufno = nb_getbufno (curbuf);
    long  off;
    char_u *q;
    if (!NETBEANS_OPEN)
        return TRUE;
    if (bufno == -1) {
        nbdebug (("got keycommand for non-NetBeans buffer, opening...\n"));
        q = curbuf->b_ffname == NULL ? (char_u *) "" : nb_quote (curbuf->b_ffname);
        if (q == NULL)
            return TRUE;
        vim_snprintf (buf, sizeof (buf), "0:fileOpened=%d \"%s\" %s %s\n", 0, q, "T", "F");
        if (curbuf->b_ffname != NULL)
            vim_free (q);
        nbdebug (("EVT: %s", buf));
        nb_send (buf, "netbeans_keycommand");
        postpone_keycommand (keyName);
        return FALSE;
    }
    off = pos2off (curbuf, &curwin->w_cursor);
    sprintf (buf, "%d:newDotAndMark=%d %ld %ld\n", bufno, r_cmdno, off, off);
    nbdebug (("EVT: %s", buf));
    nb_send (buf, "netbeans_keycommand");
    vim_snprintf (buf, sizeof (buf), "%d:keyCommand=%d \"%s\"\n", bufno, r_cmdno, keyName);
    nbdebug (("EVT: %s", buf));
    nb_send (buf, "netbeans_keycommand");
    vim_snprintf (buf, sizeof (buf), "%d:keyAtPos=%d \"%s\" %ld %ld/%ld\n", bufno, r_cmdno, keyName, off, (long) curwin -> w_cursor.lnum, (long) curwin -> w_cursor.col);
    nbdebug (("EVT: %s", buf));
    nb_send (buf, "netbeans_keycommand");
    return TRUE;
}

static void postpone_keycommand (char_u *keystr) {
    keyQ_T *node;
    node = (keyQ_T *) alloc (sizeof (keyQ_T));
    if (node == NULL)
        return;
    if (keyHead.next == NULL) {
        keyHead.next = &keyHead;
        keyHead.prev = &keyHead;
    }
    node->next = &keyHead;
    node->prev = keyHead.prev;
    keyHead.prev->next = node;
    keyHead.prev = node;
    node->keystr = vim_strsave (keystr);
}

void netbeans_button_release (int button) {
    char buf [128];
    int bufno;
    if (!NETBEANS_OPEN)
        return;
    bufno = nb_getbufno (curbuf);
    if (bufno >= 0 && curwin != NULL && curwin->w_buffer == curbuf) {
        int col = mouse_col - curwin->w_wincol - ((curwin->w_p_nu || curwin->w_p_rnu) ? 9 : 1);
        long  off = pos2off (curbuf, &curwin->w_cursor);
        sprintf (buf, "%d:newDotAndMark=%d %ld %ld\n", bufno, r_cmdno, off, off);
        nbdebug (("EVT: %s", buf));
        nb_send (buf, "netbeans_button_release[newDotAndMark]");
        sprintf (buf, "%d:buttonRelease=%d %d %ld %d\n", bufno, r_cmdno, button, (long) curwin -> w_cursor.lnum, col);
        nbdebug (("EVT: %s", buf));
        nb_send (buf, "netbeans_button_release");
    }
}

void netbeans_removed (buf_T *bufp, linenr_T linenr, colnr_T col, long  len) {
    char_u buf [128];
    int bufno;
    nbbuf_T *nbbuf;
    pos_T pos;
    long  off;
    if (!NETBEANS_OPEN)
        return;
    nbbuf = nb_bufp2nbbuf_fire (bufp, &bufno);
    if (nbbuf == NULL)
        return;
    if (len < 0) {
        nbdebug (("Negative len %ld in netbeans_removed()!\n", len));
        return;
    }
    nbbuf->modified = 1;
    pos.lnum = linenr;
    pos.col = col;
    off = pos2off (bufp, &pos);
    sprintf ((char *) buf, "%d:remove=%d %ld %ld\n", bufno, r_cmdno, off, len);
    nbdebug (("EVT: %s", buf));
    nb_send ((char *) buf, "netbeans_removed");
}

static int nb_do_cmd (int bufno, char_u *cmd, int func, int cmdno, char_u *args) {
    int do_update = 0;
    long  off = 0;
    nbbuf_T *buf = nb_get_buf (bufno);
    static int skip = 0;
    int retval = OK;
    char *cp;
    nbdebug (("%s %d: (%d) %s %s\n", (func) ? "FUN" : "CMD", cmdno, bufno, cmd, STRCMP (cmd, "insert") == 0 ? "<text>" : (char *) args));
    if (func) {
        if (streq ((char *) cmd, "getModified")) {
            if (buf == NULL || buf->bufp == NULL)
                nb_reply_nr (cmdno, (long ) count_changed_buffers ());
            else
                nb_reply_nr (cmdno, (long ) (buf->bufp->b_changed || isNetbeansModified (buf->bufp)));
        }
        else if (streq ((char *) cmd, "saveAndExit")) {
            coloncmd (":confirm qall");
            nb_reply_nr (cmdno, (long) count_changed_buffers ());
        }
        else if (streq ((char *) cmd, "getCursor")) {
            char_u text [200];
            sprintf ((char *) text, "%d %ld %d %ld", nb_getbufno (curbuf), (long) curwin -> w_cursor.lnum, (int) curwin -> w_cursor.col, pos2off (curbuf, & curwin -> w_cursor));
            nb_reply_text (cmdno, text);
        }
        else if (streq ((char *) cmd, "getAnno")) {
            long  linenum = 0;
            if (buf == NULL || buf->bufp == NULL) {
                nbdebug (("    Invalid buffer identifier in getAnno\n"));
                EMSG ("E652: Invalid buffer identifier in getAnno");
                retval = FAIL;
            }
            else {
                int serNum;
                cp = (char *) args;
                serNum = strtol (cp, &cp, 10);
                linenum = (long ) buf_findsign (buf->bufp, serNum);
            }
            nb_reply_nr (cmdno, linenum);
        }
        else if (streq ((char *) cmd, "getLength")) {
            long  len = 0;
            if (buf == NULL || buf->bufp == NULL) {
                nbdebug (("    invalid buffer identifier in getLength\n"));
                EMSG ("E632: invalid buffer identifier in getLength");
                retval = FAIL;
            }
            else {
                len = get_buf_size (buf->bufp);
            }
            nb_reply_nr (cmdno, len);
        }
        else if (streq ((char *) cmd, "getText")) {
            long  len;
            linenr_T nlines;
            char_u *text = NULL;
            linenr_T lno = 1;
            char_u *p;
            char_u *line;
            if (buf == NULL || buf->bufp == NULL) {
                nbdebug (("    invalid buffer identifier in getText\n"));
                EMSG ("E633: invalid buffer identifier in getText");
                retval = FAIL;
            }
            else {
                len = get_buf_size (buf->bufp);
                nlines = buf->bufp->b_ml.ml_line_count;
                text = alloc ((unsigned ) ((len > 0) ? ((len + nlines) * 2) : 4));
                if (text == NULL) {
                    nbdebug (("    nb_do_cmd: getText has null text field\n"));
                    retval = FAIL;
                }
                else {
                    p = text;
                    *p++ = '\"';
                    for (; lno <= nlines; lno++) {
                        line = nb_quote (ml_get_buf (buf->bufp, lno, FALSE));
                        if (line != NULL) {
                            STRCPY (p, line);
                            p += STRLEN (line);
                            *p++ = '\\';
                            *p++ = 'n';
                            vim_free (line);
                        }
                    }
                    *p++ = '\"';
                    *p = '\0';
                }
            }
            if (text == NULL)
                nb_reply_text (cmdno, (char_u *) "");
            else {
                nb_reply_text (cmdno, text);
                vim_free (text);
            }
        }
        else if (streq ((char *) cmd, "remove")) {
            long  count;
            pos_T first, last;
            pos_T *pos;
            pos_T *next;
            linenr_T del_from_lnum, del_to_lnum;
            int oldFire = netbeansFireChanges;
            int oldSuppress = netbeansSuppressNoLines;
            int wasChanged;
            if (skip >= SKIP_STOP) {
                nbdebug (("    Skipping %s command\n", (char *) cmd));
                nb_reply_nil (cmdno);
                return OK;
            }
            if (buf == NULL || buf->bufp == NULL) {
                nbdebug (("    invalid buffer identifier in remove\n"));
                EMSG ("E634: invalid buffer identifier in remove");
                retval = FAIL;
            }
            else {
                netbeansFireChanges = FALSE;
                netbeansSuppressNoLines = TRUE;
                nb_set_curbuf (buf -> bufp);
                wasChanged = buf->bufp->b_changed;
                cp = (char *) args;
                off = strtol (cp, &cp, 10);
                count = strtol (cp, &cp, 10);
                args = (char_u *) cp;
                pos = off2pos (buf->bufp, off);
                if (!pos) {
                    nbdebug (("    !bad position\n"));
                    nb_reply_text (cmdno, (char_u *) "!bad position");
                    netbeansFireChanges = oldFire;
                    netbeansSuppressNoLines = oldSuppress;
                    return FAIL;
                }
                first = *pos;
                nbdebug (("    FIRST POS: line %d, col %d\n", first.lnum, first.col));
                pos = off2pos (buf->bufp, off +count - 1);
                if (!pos) {
                    nbdebug (("    !bad count\n"));
                    nb_reply_text (cmdno, (char_u *) "!bad count");
                    netbeansFireChanges = oldFire;
                    netbeansSuppressNoLines = oldSuppress;
                    return FAIL;
                }
                last = *pos;
                nbdebug (("    LAST POS: line %d, col %d\n", last.lnum, last.col));
                del_from_lnum = first.lnum;
                del_to_lnum = last.lnum;
                do_update = 1;
                next = off2pos (buf->bufp, off +count);
                if (first.col != 0 || (next != NULL && first.lnum == next->lnum)) {
                    if (first.lnum != last.lnum || (next != NULL && first.lnum != next->lnum)) {
                        nb_partialremove (first.lnum, first.col, (colnr_T) MAXCOL);
                        if (first.lnum == last.lnum) {
                            nb_joinlines (first.lnum, next -> lnum);
                            del_to_lnum = next->lnum;
                        }
                    }
                    else {
                        nb_partialremove (first.lnum, first.col, last.col);
                    }
                    ++del_from_lnum;
                }
                if (first.lnum != last.lnum && next != NULL && next->col != 0 && last.lnum == next->lnum) {
                    nb_partialremove (last.lnum, 0, last.col);
                    if (del_from_lnum > first.lnum) {
                        nb_joinlines (first.lnum, last.lnum);
                    }
                    else
                        --del_to_lnum;
                }
                if (first.lnum != last.lnum && del_from_lnum > first.lnum && next != NULL && last.lnum != next->lnum) {
                    nb_joinlines (first.lnum, next -> lnum);
                    del_to_lnum = next->lnum;
                }
                if (del_to_lnum >= del_from_lnum) {
                    int i;
                    for (i = del_from_lnum; i <= del_to_lnum; i++) {
                        int id = buf_findsign_id (buf->bufp, (linenr_T) i);
                        if (id > 0) {
                            nbdebug (("    Deleting sign %d on line %d\n", id, i));
                            buf_delsign (buf -> bufp, id);
                        }
                        else {
                            nbdebug (("    No sign on line %d\n", i));
                        }
                    }
                    nbdebug (("    Deleting lines %d through %d\n", del_from_lnum, del_to_lnum));
                    curwin->w_cursor.lnum = del_from_lnum;
                    curwin->w_cursor.col = 0;
                    del_lines (del_to_lnum - del_from_lnum + 1, FALSE);
                }
                curwin->w_cursor = first;
                check_cursor_lnum ();
                buf->bufp->b_changed = wasChanged;
                netbeansFireChanges = oldFire;
                netbeansSuppressNoLines = oldSuppress;
                u_blockfree (buf -> bufp);
                u_clearall (buf -> bufp);
            }
            nb_reply_nil (cmdno);
        }
        else if (streq ((char *) cmd, "insert")) {
            char_u *to_free;
            if (skip >= SKIP_STOP) {
                nbdebug (("    Skipping %s command\n", (char *) cmd));
                nb_reply_nil (cmdno);
                return OK;
            }
            cp = (char *) args;
            off = strtol (cp, &cp, 10);
            args = (char_u *) cp;
            args = skipwhite (args);
            args = to_free = (char_u *) nb_unquote (args, NULL);
            if (buf == NULL || buf->bufp == NULL) {
                nbdebug (("    invalid buffer identifier in insert\n"));
                EMSG ("E635: invalid buffer identifier in insert");
                retval = FAIL;
            }
            else if (args != NULL) {
                int ff_detected = EOL_UNKNOWN;
                int buf_was_empty = (buf->bufp->b_ml.ml_flags & ML_EMPTY);
                size_t len = 0;
                int added = 0;
                int oldFire = netbeansFireChanges;
                int old_b_changed;
                char_u *nlp;
                linenr_T lnum;
                linenr_T lnum_start;
                pos_T *pos;
                netbeansFireChanges = 0;
                nb_set_curbuf (buf -> bufp);
                old_b_changed = curbuf->b_changed;
                pos = off2pos (curbuf, off);
                if (pos != NULL) {
                    if (pos->lnum <= 0)
                        lnum_start = 1;
                    else
                        lnum_start = pos->lnum;
                }
                else {
                    if (buf_was_empty)
                        lnum_start = 1;
                    else
                        lnum_start = curbuf->b_ml.ml_line_count + 1;
                }
                lnum = lnum_start;
                do_update = 1;
                while (*args != NUL) {
                    nlp = vim_strchr (args, '\n');
                    if (nlp == NULL) {
                        len = STRLEN (args);
                    }
                    else {
                        len = nlp - args;
                        if (nlp > args && nlp[-1] == '\r') {
                            ff_detected = EOL_DOS;
                            --len;
                        }
                        else
                            ff_detected = EOL_UNIX;
                    }
                    args[len] = NUL;
                    if (lnum == lnum_start && ((pos != NULL && pos->col > 0) || (lnum == 1 && buf_was_empty))) {
                        char_u *oldline = ml_get (lnum);
                        char_u *newline;
                        newline = alloc_check ((unsigned ) (STRLEN (oldline) + len + 1));
                        if (newline != NULL) {
                            mch_memmove (newline, oldline, (size_t) pos -> col);
                            newline[pos->col] = NUL;
                            STRCAT (newline, args);
                            STRCAT (newline, oldline + pos -> col);
                            ml_replace (lnum, newline, FALSE);
                        }
                    }
                    else {
                        ml_append ((linenr_T) (lnum - 1), args, (colnr_T) (len + 1), FALSE);
                        ++added;
                    }
                    if (nlp == NULL)
                        break;
                    ++lnum;
                    args = nlp + 1;
                }
                appended_lines_mark (lnum_start - 1, (long) added);
                if (buf_was_empty) {
                    if (ff_detected == EOL_UNKNOWN)
                        ff_detected = EOL_UNIX;
                    set_fileformat (ff_detected, OPT_LOCAL);
                    curbuf->b_start_ffc = *curbuf->b_p_ff;
                }
                curbuf->b_changed = old_b_changed;
                netbeansFireChanges = oldFire;
                u_blockfree (curbuf);
                u_clearall (curbuf);
            }
            vim_free (to_free);
            nb_reply_nil (cmdno);
        }
        else {
            nbdebug (("UNIMPLEMENTED FUNCTION: %s\n", cmd));
            nb_reply_nil (cmdno);
            retval = FAIL;
        }
    }
    else {
        if (streq ((char *) cmd, "create")) {
            if (buf == NULL) {
                nbdebug (("    invalid buffer identifier in create\n"));
                EMSG ("E636: invalid buffer identifier in create");
                return FAIL;
            }
            VIM_CLEAR (buf -> displayname);
            netbeansReadFile = 0;
            do_ecmd (0, NULL, 0, 0, ECMD_ONE, ECMD_HIDE + ECMD_OLDBUF, curwin);
            netbeansReadFile = 1;
            buf->bufp = curbuf;
            maketitle ();
            buf->insertDone = FALSE;
            if (gui.in_use)
                gui_update_menus (0);
        }
        else if (streq ((char *) cmd, "insertDone")) {
            if (buf == NULL || buf->bufp == NULL) {
                nbdebug (("    invalid buffer identifier in insertDone\n"));
            }
            else {
                buf->bufp->b_start_eol = *args == 'T';
                buf->insertDone = TRUE;
                args += 2;
                buf->bufp->b_p_ro = *args == 'T';
                print_read_msg (buf);
            }
        }
        else if (streq ((char *) cmd, "saveDone")) {
            long  savedChars = atol ((char *) args);
            if (buf == NULL || buf->bufp == NULL) {
                nbdebug (("    invalid buffer identifier in saveDone\n"));
            }
            else
                print_save_msg (buf, savedChars);
        }
        else if (streq ((char *) cmd, "startDocumentListen")) {
            if (buf == NULL) {
                nbdebug (("    invalid buffer identifier in startDocumentListen\n"));
                EMSG ("E637: invalid buffer identifier in startDocumentListen");
                return FAIL;
            }
            buf->fireChanges = 1;
        }
        else if (streq ((char *) cmd, "stopDocumentListen")) {
            if (buf == NULL) {
                nbdebug (("    invalid buffer identifier in stopDocumentListen\n"));
                EMSG ("E638: invalid buffer identifier in stopDocumentListen");
                return FAIL;
            }
            buf->fireChanges = 0;
            if (buf->bufp != NULL && buf->bufp->b_was_netbeans_file) {
                if (!buf->bufp->b_netbeans_file) {
                    nbdebug (("E658: NetBeans connection lost for buffer %ld\n", buf -> bufp -> b_fnum));
                    EMSGN (_ ("E658: NetBeans connection lost for buffer %ld"), buf -> bufp -> b_fnum);
                }
                else {
                    do_bufdel (DOBUF_DEL, (char_u *) "", 1, buf -> bufp -> b_fnum, buf -> bufp -> b_fnum, TRUE);
                    vim_memset (buf, 0, sizeof (nbbuf_T));
                }
            }
        }
        else if (streq ((char *) cmd, "setTitle")) {
            if (buf == NULL) {
                nbdebug (("    invalid buffer identifier in setTitle\n"));
                EMSG ("E639: invalid buffer identifier in setTitle");
                return FAIL;
            }
            vim_free (buf -> displayname);
            buf->displayname = nb_unquote (args, NULL);
        }
        else if (streq ((char *) cmd, "initDone")) {
            if (buf == NULL || buf->bufp == NULL) {
                nbdebug (("    invalid buffer identifier in initDone\n"));
                EMSG ("E640: invalid buffer identifier in initDone");
                return FAIL;
            }
            do_update = 1;
            buf->initDone = TRUE;
            nb_set_curbuf (buf -> bufp);
            apply_autocmds (EVENT_BUFREADPOST, 0, 0, FALSE, buf -> bufp);
            handle_key_queue ();
        }
        else if (streq ((char *) cmd, "setBufferNumber") || streq ((char *) cmd, "putBufferNumber")) {
            char_u *path;
            buf_T *bufp;
            if (buf == NULL) {
                nbdebug (("    invalid buffer identifier in setBufferNumber\n"));
                EMSG ("E641: invalid buffer identifier in setBufferNumber");
                return FAIL;
            }
            path = (char_u *) nb_unquote (args, NULL);
            if (path == NULL)
                return FAIL;
            bufp = buflist_findname (path);
            vim_free (path);
            if (bufp == NULL) {
                nbdebug (("    File %s not found in setBufferNumber\n", args));
                EMSG2 ("E642: File %s not found in setBufferNumber", args);
                return FAIL;
            }
            buf->bufp = bufp;
            buf->nbbuf_number = bufp->b_fnum;
            if (*cmd != 'p')
                coloncmd (":buffer %d", bufp->b_fnum);
            else {
                buf->initDone = TRUE;
                handle_key_queue ();
            }
        }
        else if (streq ((char *) cmd, "setFullName")) {
            if (buf == NULL) {
                nbdebug (("    invalid buffer identifier in setFullName\n"));
                EMSG ("E643: invalid buffer identifier in setFullName");
                return FAIL;
            }
            vim_free (buf -> displayname);
            buf->displayname = nb_unquote (args, NULL);
            netbeansReadFile = 0;
            do_ecmd (0, (char_u *) buf -> displayname, 0, 0, ECMD_ONE, ECMD_HIDE + ECMD_OLDBUF, curwin);
            netbeansReadFile = 1;
            buf->bufp = curbuf;
            maketitle ();
            if (gui.in_use)
                gui_update_menus (0);
        }
        else if (streq ((char *) cmd, "editFile")) {
            if (buf == NULL) {
                nbdebug (("    invalid buffer identifier in editFile\n"));
                EMSG ("E644: invalid buffer identifier in editFile");
                return FAIL;
            }
            vim_free (buf -> displayname);
            buf->displayname = nb_unquote (args, NULL);
            do_ecmd (0, (char_u *) buf -> displayname, NULL, NULL, ECMD_ONE, ECMD_HIDE + ECMD_OLDBUF, curwin);
            buf->bufp = curbuf;
            buf->initDone = TRUE;
            do_update = 1;
            maketitle ();
            if (gui.in_use)
                gui_update_menus (0);
        }
        else if (streq ((char *) cmd, "setVisible")) {
            if (buf == NULL || buf->bufp == NULL) {
                nbdebug (("    invalid buffer identifier in setVisible\n"));
                if (p_verbose > 0)
                    EMSG ("E645: invalid buffer identifier in setVisible");
                return FAIL;
            }
            if (streq ((char *) args, "T") && buf->bufp != curbuf) {
                exarg_T exarg;
                exarg.cmd = (char_u *) "goto";
                exarg.forceit = FALSE;
                dosetvisible = TRUE;
                goto_buffer (& exarg, DOBUF_FIRST, FORWARD, buf -> bufp -> b_fnum);
                do_update = 1;
                dosetvisible = FALSE;
                if (gui.in_use)
                    gui_mch_set_foreground ();
            }
        }
        else if (streq ((char *) cmd, "raise")) {
            if (gui.in_use)
                gui_mch_set_foreground ();
        }
        else if (streq ((char *) cmd, "setModified")) {
            int prev_b_changed;
            if (buf == NULL || buf->bufp == NULL) {
                nbdebug (("    invalid buffer identifier in setModified\n"));
                if (p_verbose > 0)
                    EMSG ("E646: invalid buffer identifier in setModified");
                return FAIL;
            }
            prev_b_changed = buf->bufp->b_changed;
            if (streq ((char *) args, "T"))
                buf->bufp->b_changed = TRUE;
            else {
                stat_T st;
                if (buf->bufp->b_ffname != NULL && mch_stat ((char *) buf->bufp->b_ffname, &st) >= 0)
                    buf_store_time (buf->bufp, &st, buf->bufp->b_ffname);
                buf->bufp->b_changed = FALSE;
            }
            buf->modified = buf->bufp->b_changed;
            if (prev_b_changed != buf->bufp->b_changed) {
                check_status (buf -> bufp);
                redraw_tabline = TRUE;
                maketitle ();
                update_screen (0);
            }
        }
        else if (streq ((char *) cmd, "setModtime")) {
            if (buf == NULL || buf->bufp == NULL)
                nbdebug (("    invalid buffer identifier in setModtime\n"));
            else
                buf->bufp->b_mtime = atoi ((char *) args);
        }
        else if (streq ((char *) cmd, "setReadOnly")) {
            if (buf == NULL || buf->bufp == NULL)
                nbdebug (("    invalid buffer identifier in setReadOnly\n"));
            else if (streq ((char *) args, "T"))
                buf->bufp->b_p_ro = TRUE;
            else
                buf->bufp->b_p_ro = FALSE;
        }
        else if (streq ((char *) cmd, "setMark")) {
        }
        else if (streq ((char *) cmd, "showBalloon")) {
            static char *text = NULL;
            if (balloonEval != NULL) {
                vim_free (text);
                text = nb_unquote (args, NULL);
                if (text != NULL)
                    gui_mch_post_balloon (balloonEval, (char_u *) text);
            }
        }
        else if (streq ((char *) cmd, "setDot")) {
            pos_T *pos;
            if (buf == NULL || buf->bufp == NULL) {
                nbdebug (("    invalid buffer identifier in setDot\n"));
                EMSG ("E647: invalid buffer identifier in setDot");
                return FAIL;
            }
            nb_set_curbuf (buf -> bufp);
            if (VIsual_active)
                end_visual_mode ();
            pos = get_off_or_lnum (buf->bufp, &args);
            if (pos) {
                curwin->w_cursor = *pos;
                check_cursor ();
                foldOpenCursor ();
            }
            else {
                nbdebug (("    BAD POSITION in setDot: %s\n", s));
            }
            update_topline ();
            update_screen (VALID);
            setcursor ();
            cursor_on ();
            out_flush_cursor (TRUE, FALSE);
            if (State == HITRETURN || State == ASKMORE) {
            }
        }
        else if (streq ((char *) cmd, "close")) {
            if (buf == NULL) {
                nbdebug (("    invalid buffer identifier in close\n"));
                EMSG ("E648: invalid buffer identifier in close");
                return FAIL;
            }
            if (buf->bufp == NULL) {
                nbdebug (("    invalid buffer identifier in close\n"));
                if (p_verbose > 0)
                    EMSG ("E649: invalid buffer identifier in close");
            }
            nbdebug (("    CLOSE %d: %s\n", bufno, name));
            need_mouse_correct = TRUE;
            if (buf->bufp != NULL)
                do_buffer (DOBUF_WIPE, DOBUF_FIRST, FORWARD, buf->bufp->b_fnum, TRUE);
            buf->bufp = NULL;
            buf->initDone = FALSE;
            do_update = 1;
        }
        else if (streq ((char *) cmd, "setStyle")) {
            nbdebug (("    setStyle is obsolete!\n"));
        }
        else if (streq ((char *) cmd, "setExitDelay")) {
        }
        else if (streq ((char *) cmd, "defineAnnoType")) {
            int typeNum;
            char_u *typeName;
            char_u *tooltip;
            char_u *p;
            char_u *glyphFile;
            int parse_error = FALSE;
            char_u *fg;
            char_u *bg;
            if (buf == NULL) {
                nbdebug (("    invalid buffer identifier in defineAnnoType\n"));
                EMSG ("E650: invalid buffer identifier in defineAnnoType");
                return FAIL;
            }
            cp = (char *) args;
            typeNum = strtol (cp, &cp, 10);
            args = (char_u *) cp;
            args = skipwhite (args);
            typeName = (char_u *) nb_unquote (args, &args);
            args = skipwhite (args +1);
            tooltip = (char_u *) nb_unquote (args, &args);
            args = skipwhite (args +1);
            p = (char_u *) nb_unquote (args, &args);
            glyphFile = vim_strsave_escaped (p, escape_chars);
            vim_free (p);
            args = skipwhite (args +1);
            p = skiptowhite (args);
            if (*p != NUL) {
                *p = NUL;
                p = skipwhite (p +1);
            }
            fg = vim_strsave (args);
            bg = vim_strsave (p);
            if (STRLEN (fg) > MAX_COLOR_LENGTH || STRLEN (bg) > MAX_COLOR_LENGTH) {
                EMSG ("E532: highlighting color name too long in defineAnnoType");
                vim_free (typeName);
                parse_error = TRUE;
            }
            else if (typeName != NULL && tooltip != NULL && glyphFile != NULL)
                addsigntype (buf, typeNum, typeName, tooltip, glyphFile, fg, bg);
            else
                vim_free (typeName);
            vim_free (fg);
            vim_free (bg);
            vim_free (tooltip);
            vim_free (glyphFile);
            if (parse_error)
                return FAIL;
        }
        else if (streq ((char *) cmd, "addAnno")) {
            int serNum;
            int localTypeNum;
            int typeNum;
            pos_T *pos;
            if (buf == NULL || buf->bufp == NULL) {
                nbdebug (("    invalid buffer identifier in addAnno\n"));
                EMSG ("E651: invalid buffer identifier in addAnno");
                return FAIL;
            }
            do_update = 1;
            cp = (char *) args;
            serNum = strtol (cp, &cp, 10);
            localTypeNum = strtol (cp, &cp, 10);
            args = (char_u *) cp;
            typeNum = mapsigntype (buf, localTypeNum);
            pos = get_off_or_lnum (buf->bufp, &args);
            cp = (char *) args;
            ignored = (int) strtol (cp, &cp, 10);
            args = (char_u *) cp;
            if (serNum >= GUARDEDOFFSET) {
                nbdebug (("    too many annotations! ignoring...\n"));
                return FAIL;
            }
            if (pos) {
                coloncmd (":sign place %d line=%ld name=%d buffer=%d", serNum, pos -> lnum, typeNum, buf -> bufp -> b_fnum);
                if (typeNum == curPCtype)
                    coloncmd (":sign jump %d buffer=%d", serNum, buf->bufp->b_fnum);
            }
        }
        else if (streq ((char *) cmd, "removeAnno")) {
            int serNum;
            if (buf == NULL || buf->bufp == NULL) {
                nbdebug (("    invalid buffer identifier in removeAnno\n"));
                return FAIL;
            }
            do_update = 1;
            cp = (char *) args;
            serNum = strtol (cp, &cp, 10);
            args = (char_u *) cp;
            coloncmd (":sign unplace %d buffer=%d", serNum, buf -> bufp -> b_fnum);
            redraw_buf_later (buf -> bufp, NOT_VALID);
        }
        else if (streq ((char *) cmd, "moveAnnoToFront")) {
            nbdebug (("    moveAnnoToFront: Not Yet Implemented!\n"));
        }
        else if (streq ((char *) cmd, "guard") || streq ((char *) cmd, "unguard")) {
            int len;
            pos_T first;
            pos_T last;
            pos_T *pos;
            int un = (cmd[0] == 'u');
            static int guardId = GUARDEDOFFSET;
            if (skip >= SKIP_STOP) {
                nbdebug (("    Skipping %s command\n", (char *) cmd));
                return OK;
            }
            nb_init_graphics ();
            if (buf == NULL || buf->bufp == NULL) {
                nbdebug (("    invalid buffer identifier in %s command\n", cmd));
                return FAIL;
            }
            nb_set_curbuf (buf -> bufp);
            cp = (char *) args;
            off = strtol (cp, &cp, 10);
            len = strtol (cp, NULL, 10);
            args = (char_u *) cp;
            pos = off2pos (buf->bufp, off);
            do_update = 1;
            if (!pos)
                nbdebug (("    no such start pos in %s, %ld\n", cmd, off));
            else {
                first = *pos;
                pos = off2pos (buf->bufp, off +len - 1);
                if (pos != NULL && pos->col == 0) {
                    pos = off2pos (buf->bufp, off +len - 2);
                }
                if (!pos)
                    nbdebug (("    no such end pos in %s, %ld\n", cmd, off + len - 1));
                else {
                    long  lnum;
                    last = *pos;
                    nbdebug (("    %sGUARD %ld,%d to %ld,%d\n", (un) ? "UN" : "", first.lnum, first.col, last.lnum, last.col));
                    for (lnum = first.lnum; lnum <= last.lnum; lnum++) {
                        if (un) {
                        }
                        else {
                            if (buf_findsigntype_id (buf->bufp, lnum, GUARDED) == 0) {
                                coloncmd (":sign place %d line=%ld name=%d buffer=%d", guardId ++, lnum, GUARDED, buf -> bufp -> b_fnum);
                            }
                        }
                    }
                    redraw_buf_later (buf -> bufp, NOT_VALID);
                }
            }
        }
        else if (streq ((char *) cmd, "startAtomic")) {
            inAtomic = 1;
        }
        else if (streq ((char *) cmd, "endAtomic")) {
            inAtomic = 0;
            if (needupdate) {
                do_update = 1;
                needupdate = 0;
            }
        }
        else if (streq ((char *) cmd, "save")) {
            if (buf == NULL || buf->bufp == NULL) {
                nbdebug (("    invalid buffer identifier in %s command\n", cmd));
                return FAIL;
            }
            if (bufIsChanged (buf->bufp)) {
                if (p_write && !buf->bufp->b_p_ro && buf->bufp->b_ffname != NULL && !bt_dontwrite (buf->bufp)) {
                    bufref_T bufref;
                    set_bufref (& bufref, buf -> bufp);
                    buf_write_all (buf -> bufp, FALSE);
                    if (!bufref_valid (&bufref))
                        buf->bufp = NULL;
                }
            }
            else {
                nbdebug (("    Buffer has no changes!\n"));
            }
        }
        else if (streq ((char *) cmd, "netbeansBuffer")) {
            if (buf == NULL || buf->bufp == NULL) {
                nbdebug (("    invalid buffer identifier in %s command\n", cmd));
                return FAIL;
            }
            if (*args == 'T') {
                buf->bufp->b_netbeans_file = TRUE;
                buf->bufp->b_was_netbeans_file = TRUE;
            }
            else
                buf->bufp->b_netbeans_file = FALSE;
        }
        else if (streq ((char *) cmd, "specialKeys")) {
            special_keys (args);
        }
        else if (streq ((char *) cmd, "actionMenuItem")) {
        }
        else if (streq ((char *) cmd, "version")) {
        }
        else {
            nbdebug (("Unrecognised command: %s\n", cmd));
        }
    }
    if (inAtomic && do_update) {
        needupdate = 1;
        do_update = 0;
    }
    if (buf != NULL && buf->initDone && do_update) {
        update_screen (NOT_VALID);
        setcursor ();
        cursor_on ();
        out_flush_cursor (TRUE, FALSE);
        if (State == HITRETURN || State == ASKMORE) {
        }
    }
    return retval;
}

static void nb_reply_nr (int cmdno, long  result) {
    char reply [32];
    nbdebug (("REP %d: %ld\n", cmdno, result));
    sprintf (reply, "%d %ld\n", cmdno, result);
    nb_send (reply, "nb_reply_nr");
}

static int count_changed_buffers (void) {
    buf_T *bufp;
    int n;
    n = 0;
    FOR_ALL_BUFFERS (bufp)
        if (bufp->b_changed)
            ++n;
    return n;
}

static void nb_reply_text (int cmdno, char_u *result) {
    char_u *reply;
    nbdebug (("REP %d: %s\n", cmdno, (char *) result));
    reply = alloc ((unsigned ) STRLEN (result) + 32);
    sprintf ((char *) reply, "%d %s\n", cmdno, (char *) result);
    nb_send ((char *) reply, "nb_reply_text");
    vim_free (reply);
}

static long  get_buf_size (buf_T *bufp) {
    linenr_T lnum;
    long  char_count = 0;
    int eol_size;
    long  last_check = 100000L;
    if (bufp->b_ml.ml_flags & ML_EMPTY)
        return 0;
    else {
        if (get_fileformat (bufp) == EOL_DOS)
            eol_size = 2;
        else
            eol_size = 1;
        for (lnum = 1; lnum <= bufp->b_ml.ml_line_count; ++lnum) {
            char_count += (long ) STRLEN (ml_get_buf (bufp, lnum, FALSE)) + eol_size;
            if (char_count > last_check) {
                ui_breakcheck ();
                if (got_int)
                    return char_count;
                last_check = char_count + 100000L;
            }
        }
        if (!bufp->b_p_eol && (bufp->b_p_bin || !bufp->b_p_fixeol))
            char_count -= eol_size;
    }
    return char_count;
}

static void nb_reply_nil (int cmdno) {
    char reply [32];
    nbdebug (("REP %d: <none>\n", cmdno));
    if (!NETBEANS_OPEN)
        return;
    sprintf (reply, "%d\n", cmdno);
    nb_send (reply, "nb_reply_nil");
}

static void nb_set_curbuf (buf_T *buf) {
    if (curbuf != buf) {
        if (buf_jump_open_win (buf) != NULL)
            return;
        if ((swb_flags & SWB_USETAB) && buf_jump_open_tab (buf) != NULL)
            return;
        set_curbuf (buf, DOBUF_GOTO);
    }
}

static pos_T *off2pos (buf_T *buf, long  offset) {
    linenr_T lnum;
    static pos_T pos;
    pos.lnum = 0;
    pos.col = 0;
    pos.coladd = 0;
    if (!(buf->b_ml.ml_flags & ML_EMPTY)) {
        if ((lnum = ml_find_line_or_offset (buf, (linenr_T) 0, &offset)) < 0)
            return NULL;
        pos.lnum = lnum;
        pos.col = offset;
    }
    return &pos;
}

static void nb_partialremove (linenr_T lnum, colnr_T first, colnr_T last) {
    char_u *oldtext, *newtext;
    int oldlen;
    int lastbyte = last;
    oldtext = ml_get (lnum);
    oldlen = (int) STRLEN (oldtext);
    if (first >= (colnr_T) oldlen || oldlen == 0)
        return;
    if (lastbyte >= oldlen)
        lastbyte = oldlen - 1;
    newtext = alloc (oldlen -(int)(lastbyte - first));
    if (newtext != NULL) {
        mch_memmove (newtext, oldtext, first);
        STRMOVE (newtext + first, oldtext + lastbyte + 1);
        nbdebug (("    NEW LINE %d: %s\n", lnum, newtext));
        ml_replace (lnum, newtext, FALSE);
    }
}

static void nb_joinlines (linenr_T first, linenr_T other) {
    int len_first, len_other;
    char_u *p;
    len_first = (int) STRLEN (ml_get (first));
    len_other = (int) STRLEN (ml_get (other));
    p = alloc ((unsigned ) (len_first + len_other + 1));
    if (p != NULL) {
        mch_memmove (p, ml_get (first), len_first);
        mch_memmove (p + len_first, ml_get (other), len_other + 1);
        ml_replace (first, p, FALSE);
    }
}

#define SKIP_STOP 2

#define streq(a,b) (strcmp(a,b) == 0)

static char *nb_unquote (char_u *p, char_u **endp) {
    char *result = 0;
    char *q;
    int done = 0;
    result = (char *) alloc_clear ((unsigned ) STRLEN (p) + 1);
    if (result == NULL)
        return NULL;
    if (*p++ != '"') {
        nbdebug (("nb_unquote called with string that doesn't start with a quote!: %s\n", p));
        result[0] = NUL;
        return result;
    }
    for (q = result; !done && *p != NUL;) {
        switch (*p) {
        case '"' :
            done = 1;
            break;
        case '\\' :
            ++p;
            switch (*p) {
            case '\\' :
                *q++ = '\\';
                break;
            case 'n' :
                *q++ = '\n';
                break;
            case 't' :
                *q++ = '\t';
                break;
            case 'r' :
                *q++ = '\r';
                break;
            case '"' :
                *q++ = '"';
                break;
            case NUL :
                --p;
                break;
            }
            ++p;
            break;
        default :
            *q++ = *p++;
        }
    }
    if (endp != NULL)
        *endp = p;
    return result;
}

static void print_read_msg (nbbuf_T *buf) {
    int lnum = buf->bufp->b_ml.ml_line_count;
    off_T nchars = buf->bufp->b_orig_size;
    char_u c;
    msg_add_fname (buf -> bufp, buf -> bufp -> b_ffname);
    c = FALSE;
    if (buf->bufp->b_p_ro) {
        STRCAT (IObuff, shortmess (SHM_RO) ? _ ("[RO]") : _ ("[readonly]"));
        c = TRUE;
    }
    if (!buf->bufp->b_start_eol) {
        STRCAT (IObuff, shortmess (SHM_LAST) ? _ ("[noeol]") : _ ("[Incomplete last line]"));
        c = TRUE;
    }
    msg_add_lines (c, (long) lnum, nchars);
    VIM_CLEAR (keep_msg);
    msg_scrolled_ign = TRUE;
    msg_trunc_attr (IObuff, FALSE, 0);
    msg_scrolled_ign = FALSE;
}

static void print_save_msg (nbbuf_T *buf, off_T nchars) {
    char_u c;
    char_u *p;
    if (nchars >= 0) {
        msg_add_fname (buf -> bufp, buf -> bufp -> b_ffname);
        c = FALSE;
        msg_add_lines (c, buf -> bufp -> b_ml.ml_line_count, buf -> bufp -> b_orig_size);
        VIM_CLEAR (keep_msg);
        msg_scrolled_ign = TRUE;
        p = msg_trunc_attr (IObuff, FALSE, 0);
        if ((msg_scrolled && !need_wait_return) || !buf->initDone) {
            set_keep_msg (p, 0);
        }
        msg_scrolled_ign = FALSE;
    }
    else {
        char_u msgbuf [IOSIZE];
        vim_snprintf ((char *) msgbuf, IOSIZE, _ ("E505: %s is read-only (add ! to override)"), IObuff);
        nbdebug (("    %s\n", msgbuf));
        emsg (msgbuf);
    }
}

static void handle_key_queue (void) {
    int postponed = FALSE;
    while (!postponed && keyHead.next && keyHead.next != &keyHead) {
        keyQ_T *node = keyHead.next;
        keyHead.next = node->next;
        node->next->prev = node->prev;
        if (node->keystr != NULL)
            postponed = !netbeans_keystring (node->keystr);
        vim_free (node -> keystr);
        vim_free (node);
    }
}

static pos_T *get_off_or_lnum (buf_T *buf, char_u **argp) {
    static pos_T mypos;
    long  off;
    off = strtol ((char *) *argp, (char **) argp, 10);
    if (**argp == '/') {
        mypos.lnum = (linenr_T) off;
        ++*argp;
        mypos.col = strtol ((char *) *argp, (char **) argp, 10);
        mypos.coladd = 0;
        return &mypos;
    }
    return off2pos (buf, off);
}

static void addsigntype (nbbuf_T *buf, int typeNum, char_u *typeName, char_u *tooltip, char_u *glyphFile, char_u *fg, char_u *bg) {
    int i, j;
    int use_fg = (*fg && STRCMP (fg, "none") != 0);
    int use_bg = (*bg && STRCMP (bg, "none") != 0);
    for (i = 0; i < globalsignmapused; i++)
        if (STRCMP (typeName, globalsignmap[i]) == 0)
            break;
    if (i == globalsignmapused) {
        nbdebug (("DEFINEANNOTYPE(%d,%s,%s,%s,%s,%s)\n", typeNum, typeName, tooltip, glyphFile, fg, bg));
        if (use_fg || use_bg) {
            char fgbuf [2 * (8 + MAX_COLOR_LENGTH) + 1];
            char bgbuf [2 * (8 + MAX_COLOR_LENGTH) + 1];
            char *ptr;
            int value;
            value = strtol ((char *) fg, &ptr, 10);
            if (ptr != (char *) fg)
                sprintf (fgbuf, "guifg=#%06x", value &0xFFFFFF);
            else
                sprintf (fgbuf, "guifg=%s ctermfg=%s", fg, fg);
            value = strtol ((char *) bg, &ptr, 10);
            if (ptr != (char *) bg)
                sprintf (bgbuf, "guibg=#%06x", value &0xFFFFFF);
            else
                sprintf (bgbuf, "guibg=%s ctermbg=%s", bg, bg);
            coloncmd (":highlight NB_%s %s %s", typeName, (use_fg) ? fgbuf : "", (use_bg) ? bgbuf : "");
            if (*glyphFile == NUL)
                coloncmd (":sign define %d linehl=NB_%s", i +1, typeName);
            else if (vim_strsize (glyphFile) <= 2)
                coloncmd (":sign define %d text=%s texthl=NB_%s", i +1, glyphFile, typeName);
            else
                coloncmd (":sign define %d icon=%s linehl=NB_%s", i +1, glyphFile, typeName);
        }
        else
            coloncmd (":sign define %d icon=%s", i +1, glyphFile);
        if (STRCMP (typeName, "CurrentPC") == 0)
            curPCtype = typeNum;
        if (globalsignmapused == globalsignmaplen) {
            if (globalsignmaplen == 0) {
                globalsignmaplen = 20;
                globalsignmap = (char **) alloc_clear (globalsignmaplen * sizeof (char *));
            }
            else {
                int incr;
                int oldlen = globalsignmaplen;
                char **t_globalsignmap = globalsignmap;
                globalsignmaplen *= 2;
                incr = globalsignmaplen - oldlen;
                globalsignmap = (char **) vim_realloc (globalsignmap, globalsignmaplen * sizeof (char *));
                if (globalsignmap == NULL) {
                    vim_free (t_globalsignmap);
                    globalsignmaplen = 0;
                    return;
                }
                vim_memset (globalsignmap + oldlen, 0, incr * sizeof (char *));
            }
        }
        globalsignmap[i] = (char *) typeName;
        globalsignmapused = i + 1;
    }
    for (j = 0; j < buf->signmapused; j++)
        if (buf->signmap[j] == i + 1)
            return;
    if (buf->signmapused == buf->signmaplen) {
        if (buf->signmaplen == 0) {
            buf->signmaplen = 5;
            buf->signmap = (int *) alloc_clear (buf->signmaplen * sizeof (int));
        }
        else {
            int incr;
            int oldlen = buf->signmaplen;
            int *t_signmap = buf->signmap;
            buf->signmaplen *= 2;
            incr = buf->signmaplen - oldlen;
            buf->signmap = (int *) vim_realloc (buf->signmap, buf->signmaplen * sizeof (int));
            if (buf->signmap == NULL) {
                vim_free (t_signmap);
                buf->signmaplen = 0;
                return;
            }
            vim_memset (buf -> signmap + oldlen, 0, incr * sizeof (int));
        }
    }
    buf->signmap[buf->signmapused++] = i + 1;
}

static int mapsigntype (nbbuf_T *buf, int localsigntype) {
    if (--localsigntype >= 0 && localsigntype < buf->signmapused)
        return buf->signmap[localsigntype];
    return 0;
}

static void nb_init_graphics (void) {
    static int did_init = FALSE;
    if (!did_init) {
        coloncmd (":highlight NBGuarded guibg=Cyan guifg=Black" " ctermbg=LightCyan ctermfg=Black");
        coloncmd (":sign define %d linehl=NBGuarded", GUARDED);
        did_init = TRUE;
    }
}

static void special_keys (char_u *args) {
    char *save_str = nb_unquote (args, NULL);
    char *tok = strtok (save_str, " ");
    char *sep;

    #define KEYBUFLEN 64
    char keybuf [KEYBUFLEN];
    char cmdbuf [256];
    while (tok != NULL) {
        int i = 0;
        if ((sep = strchr (tok, '-')) != NULL) {
            *sep = NUL;
            while (*tok) {
                switch (*tok) {
                case 'A' :
                case 'M' :
                case 'C' :
                case 'S' :
                    keybuf[i++] = *tok;
                    keybuf[i++] = '-';
                    break;
                }
                tok++;
            }
            tok++;
        }
        if (strlen (tok) + i < KEYBUFLEN) {
            strcpy (& keybuf [i], tok);
            vim_snprintf (cmdbuf, sizeof (cmdbuf), "<silent><%s> :nbkey %s<CR>", keybuf, keybuf);
            do_map (0, (char_u *) cmdbuf, NORMAL, FALSE);
        }
        tok = strtok (NULL, " ");
    }
    vim_free (save_str);
}

void netbeans_beval_cb (BalloonEval *beval, int state) {
    win_T *wp;
    char_u *text;
    linenr_T lnum;
    int col;
    char *buf;
    char_u *p;
    if (!can_use_beval () || !NETBEANS_OPEN)
        return;
    if (get_beval_info (beval, TRUE, &wp, &lnum, &text, &col) == OK) {
        if (text != NULL && text[0] != NUL && STRLEN (text) < MAXPATHL) {
            buf = (char *) alloc (MAXPATHL *2 + 25);
            if (buf != NULL) {
                p = nb_quote (text);
                if (p != NULL) {
                    vim_snprintf (buf, MAXPATHL * 2 + 25, "0:balloonText=%d \"%s\"\n", r_cmdno, p);
                    vim_free (p);
                }
                nbdebug (("EVT: %s", buf));
                nb_send (buf, "netbeans_beval_cb");
                vim_free (buf);
            }
        }
        vim_free (text);
    }
}

