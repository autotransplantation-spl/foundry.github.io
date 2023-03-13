
#include "InterfaceHeader.h"
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
struct dictitem16_S {
    typval_T di_tv;
    char_u di_flags;
    char_u di_key [17];
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
struct filemark {
    pos_T mark;
    int fnum;
};
struct efm_S {
    regprog_T *prog;
    efm_T *next;
    char_u addr [FMT_PATTERNS];
    char_u prefix;
    char_u flags;
    int conthere;
};
struct qf_list_S {
    int_u qf_id;
    qfline_T *qf_start;
    qfline_T *qf_last;
    qfline_T *qf_ptr;
    int qf_count;
    int qf_index;
    int qf_nonevalid;
    char_u *qf_title;
    typval_T *qf_ctx;
    struct dir_stack_T *qf_dir_stack;
    char_u *qf_directory;
    struct dir_stack_T *qf_file_stack;
    char_u *qf_currfile;
    int qf_multiline;
    int qf_multiignore;
    int qf_multiscan;
    long  qf_changedtick;
};
struct qfline_S {
    qfline_T *qf_next;
    qfline_T *qf_prev;
    linenr_T qf_lnum;
    int qf_fnum;
    int qf_col;
    int qf_nr;
    char_u *qf_pattern;
    char_u *qf_text;
    char_u qf_viscol;
    char_u qf_cleared;
    char_u qf_type;
    char_u qf_valid;
};
struct dir_stack_T {
    struct dir_stack_T *next;
    char_u *dirname;
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
struct buf_state {
    int bs_idx;
    int bs_flags;
    int bs_seqnr;
    int bs_cchar;
    reg_extmatch_T *bs_extmatch;
};
struct fmtpattern {
    char_u convchar;
    char *pattern;
};
struct regengine {
    regprog_T * (*regcomp) (char_u *, int);
    void (*regfree) (regprog_T *);
    int (*regexec_nl) (regmatch_T *, char_u *, colnr_T, int);
    long  (*regexec_multi) (regmmatch_T *, win_T *, buf_T *, linenr_T, colnr_T, proftime_T *, int *);
    char_u *expr;
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
struct qf_info_S {
    int qf_refcount;
    int qf_listcount;
    int qf_curlist;
    qf_list_T qf_lists [LISTCOUNT];
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
    int b_spell;
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
struct growarray {
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    int ga_growsize;
    void *ga_data;
};
struct ml_chunksize {
    int mlcs_numlines;
    long  mlcs_totalsize;
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
EXTERN int KeyTyped;
struct fmtpattern fmt_pat [FMT_PATTERNS] = {{'f', ".\\+"}, {'n', "\\d\\+"}, {'l', "\\d\\+"}, {'c', "\\d\\+"}, {'t', "."}, {'m', ".\\+"}, {'r', ".*"}, {'p', "[- 	.]*"}, {'v', "\\d\\+"}, {'s', ".\\+"}};
EXTERN char_u e_openerrf [] INIT (= N_ ("E40: Can't open errorfile %s"));
EXTERN char_u e_readerrf [] INIT (= N_ ("E47: Error while reading errorfile"));
EXTERN char_u *p_efm;
EXTERN char_u *p_gp;
qf_info_T ql_info;
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
EXTERN char_u *p_titlestring;
EXTERN int arrow_used;
EXTERN int mouse_row;
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
SPELL_EXTERN char_u *int_wordlist SPELL_INIT (= NULL);
EXTERN char_u e_readonlyvar [] INIT (= N_ ("E46: Cannot change read-only variable \"%s\""));
EXTERN char_u e_noroom [] INIT (= N_ ("E36: Not enough room"));
EXTERN char_u e_invarg2 [] INIT (= N_ ("E475: Invalid argument: %s"));
EXTERN char_u e_invarg [] INIT (= N_ ("E474: Invalid argument"));
EXTERN win_T *au_pending_free_win INIT (= NULL);
EXTERN char need_key_msg [] INIT (= N_ ("Need encryption key for \"%s\""));
EXTERN char_u no_lines_msg [] INIT (= N_ ("--No lines in buffer--"));
EXTERN struct msglist **msg_list INIT (= NULL);
EXTERN char_u *keep_msg INIT (= NULL);
EXTERN int msg_row;
EXTERN char_u e_prev_dir [] INIT (= N_ ("E459: Cannot go back to previous directory"));
EXTERN char_u e_noprevre [] INIT (= N_ ("E35: No previous regular expression"));
EXTERN char_u e_noprev [] INIT (= N_ ("E34: No previous command"));
EXTERN win_T *prevwin INIT (= NULL);
EXTERN tabpage_T *first_tabpage;
SPELL_EXTERN spelltab_T spelltab;
EXTERN char_u e_umark [] INIT (= N_ ("E78: Unknown mark"));
EXTERN char_u e_marknotset [] INIT (= N_ ("E20: Mark not set"));
EXTERN char_u e_invaddr [] INIT (= N_ ("E14: Invalid address"));
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
EXTERN int p_guipty;
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
EXTERN char_u e_invargNval [] INIT (= N_ ("E475: Invalid value for argument %s: %s"));
EXTERN char_u e_invargval [] INIT (= N_ ("E475: Invalid value for argument %s"));
EXTERN char_u e_backslash [] INIT (= N_ ("E10: \\ should be followed by /, ? or &"));
EXTERN char_u langmap_mapchar [256];
EXTERN char_u *escape_chars INIT (= (char_u *) " \t\\\"|");
EXTERN char_u *repeat_cmdline INIT (= NULL);
EXTERN char_u *last_cmdline INIT (= NULL);
EXTERN FILE *scriptout INIT (= NULL);
EXTERN FILE *scriptin [NSCRIPT];
EXTERN cmdmod_T cmdmod;
EXTERN win_T *aucmd_win;
EXTERN except_T *caught_stack INIT (= NULL);
EXTERN char_u *sourcing_name INIT (= NULL);
EXTERN int called_emsg;
EXTERN int called_vim_beep;
EXTERN dict_T globvardict;
EXTERN dict_T vimvardict;
EXTERN int cmdline_row;
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
EXTERN int p_ic;
EXTERN char_u *p_iconstring;
EXTERN int p_icon;
EXTERN char_u *p_penc;
EXTERN int p_fullscreen;
EXTERN char_u *p_fcl;
EXTERN long  p_fic;
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
char *e_loc_list_changed = N_ ("E926: Current location list was changed");
EXTERN char_u e_invcmd [] INIT (= N_ ("E476: Invalid command"));
EXTERN char_u *p_lispwords;
EXTERN long  p_linespace;
EXTERN proftime_T bevalexpr_due;
EXTERN char_u e_invexpr2 [] INIT (= N_ ("E15: Invalid expression: %s"));
EXTERN char_u *p_pexpr;
EXTERN char_u *p_bexpr;
EXTERN char_u e_au_recursive [] INIT (= N_ ("E952: Autocommand caused recursive behavior"));
EXTERN char_u e_secure [] INIT (= N_ ("E523: Not allowed here"));
EXTERN char_u e_curdir [] INIT (= N_ ("E12: Command not allowed from exrc/vimrc in current dir or tag search"));
EXTERN pos_T saved_cursor;
EXTERN tabpage_T *curtab;
EXTERN win_T *curwin;
EXTERN int current_scrollbar;
EXTERN vimmenu_T *current_menu;
EXTERN except_T *current_exception;
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
EXTERN buf_T *au_pending_free_buf INIT (= NULL);
SPELL_EXTERN char e_format [] SPELL_INIT (= N_ ("E759: Format error in spell file"));
EXTERN long  p_ttm;
EXTERN long  p_tm;
EXTERN int p_stmp;
EXTERN int p_lrm;
EXTERN int p_confirm;
EXTERN int p_bevalterm;
bufref_T qf_last_bufref = {NULL, 0, 0};
EXTERN char_u e_positive [] INIT (= N_ ("E487: Argument must be positive"));
EXTERN hlf_T edit_submode_highl;
EXTERN int highlight_attr [HLF_COUNT];
EXTERN int p_hls;
EXTERN char_u *p_hl;
EXTERN char_u *p_hlg;
EXTERN char_u e_invalidreg [] INIT (= N_ ("E850: Invalid register name"));
EXTERN char_u e_usingsid [] INIT (= N_ ("E81: Using <SID> not in a script context"));
EXTERN char_u e_listidx [] INIT (= N_ ("E684: list index out of range: %ld"));
EXTERN int ru_wid;
EXTERN int did_emsg_syntax;
EXTERN int did_uncaught_emsg;
EXTERN int did_emsg;
SPELL_EXTERN int did_set_spelltab;
EXTERN int p_tbidi;
EXTERN int p_hid;
int_u last_qf_id = 0;
EXTERN int autocmd_fname_full;
EXTERN char_u *autocmd_fname INIT (= NULL);
char_u *qf_last_bufname = NULL;
EXTERN unsigned  swb_flags;
EXTERN pos_T where_paste_started;
efm_T *fmt_start = NULL;
EXTERN char_u e_zerocount [] INIT (= N_ ("E939: Positive count required"));
EXTERN char_u e_nomatch2 [] INIT (= N_ ("E480: No match: %s"));
EXTERN char_u e_nomatch [] INIT (= N_ ("E479: No match"));
EXTERN char_u *autocmd_match INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_out INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_in INIT (= NULL);
EXTERN linenr_T search_match_lines;
EXTERN char bot_top_msg [] INIT (= N_ ("search hit BOTTOM, continuing at TOP"));
EXTERN char top_bot_msg [] INIT (= N_ ("search hit TOP, continuing at BOTTOM"));
EXTERN char_u e_maxmempat [] INIT (= N_ ("E363: pattern uses more memory than 'maxmempattern'"));
EXTERN char_u e_winwidth [] INIT (= N_ ("E592: 'winwidth' cannot be smaller than 'winminwidth'"));
EXTERN char_u e_winheight [] INIT (= N_ ("E591: 'winheight' cannot be smaller than 'winminheight'"));
EXTERN char_u e_notopen [] INIT (= N_ ("E484: Can't open file %s"));
EXTERN int stop_insert_mode;
EXTERN typebuf_T typebuf;
EXTERN frame_T *topframe;
EXTERN long_u scrollbar_value;
EXTERN int searchcmdlen;
EXTERN long  p_titlelen;
EXTERN int sc_col;
EXTERN int ru_col;
EXTERN int mouse_col;
EXTERN colnr_T search_match_endcol;
EXTERN int msg_col;
EXTERN int p_cc_cols [256];
EXTERN long  p_columnspace;
EXTERN int fuoptions_bgcolor;
EXTERN pos_T Insstart_orig;
EXTERN pos_T Insstart;
EXTERN pos_T VIsual;
EXTERN vimmenu_T *root_menu INIT (= NULL);
EXTERN long  Rows;
EXTERN char_u *p_guifont;
EXTERN char *font_argument INIT (= NULL);
EXTERN int msg_scrolled;
EXTERN int p_secure;
EXTERN int p_exrc;
EXTERN char_u *use_gvimrc INIT (= NULL);
EXTERN time_T starttime;
EXTERN FILE *time_fd INIT (= NULL);

int set_ref_in_quickfix (int copyID) {
    int abort = FALSE;
    tabpage_T *tp;
    win_T *win;
    abort = mark_quickfix_ctx (&ql_info, copyID);
    if (abort)
        return abort;
    FOR_ALL_TAB_WINDOWS (tp, win) {
        if (win->w_llist != NULL) {
            abort = mark_quickfix_ctx (win->w_llist, copyID);
            if (abort)
                return abort;
        }
        if (IS_LL_WINDOW (win) && (win->w_llist_ref->qf_refcount == 1)) {
            abort = mark_quickfix_ctx (win->w_llist_ref, copyID);
            if (abort)
                return abort;
        }
    }
    return abort;
}

static int mark_quickfix_ctx (qf_info_T *qi, int copyID) {
    int i;
    int abort = FALSE;
    typval_T *ctx;
    for (i = 0; i < LISTCOUNT && !abort; ++i) {
        ctx = qi->qf_lists[i].qf_ctx;
        if (ctx != NULL && ctx->v_type != VAR_NUMBER && ctx->v_type != VAR_STRING && ctx->v_type != VAR_FLOAT)
            abort = set_ref_in_item (ctx, copyID, NULL, NULL);
    }
    return abort;
}

void qf_free_all (win_T *wp) {
    int i;
    qf_info_T *qi = &ql_info;
    if (wp != NULL) {
        ll_free_all (& wp -> w_llist);
        ll_free_all (& wp -> w_llist_ref);
    }
    else
        for (i = 0; i < qi->qf_listcount; ++i)
            qf_free (qi, i);
}

static void ll_free_all (qf_info_T **pqi) {
    int i;
    qf_info_T *qi;
    qi = *pqi;
    if (qi == NULL)
        return;
    *pqi = NULL;
    qi->qf_refcount--;
    if (qi->qf_refcount < 1) {
        for (i = 0; i < qi->qf_listcount; ++i)
            qf_free (qi, i);
        vim_free (qi);
    }
}

static void qf_free (qf_info_T *qi, int idx) {
    qf_list_T *qfl = &qi->qf_lists[idx];
    qf_free_items (qi, idx);
    VIM_CLEAR (qfl -> qf_title);
    free_tv (qfl -> qf_ctx);
    qfl->qf_ctx = NULL;
    qfl->qf_id = 0;
    qfl->qf_changedtick = 0L;
}

static void qf_free_items (qf_info_T *qi, int idx) {
    qfline_T *qfp;
    qfline_T *qfpnext;
    int stop = FALSE;
    qf_list_T *qfl = &qi->qf_lists[idx];
    while (qfl->qf_count && qfl->qf_start != NULL) {
        qfp = qfl->qf_start;
        qfpnext = qfp->qf_next;
        if (!stop) {
            vim_free (qfp -> qf_text);
            stop = (qfp == qfpnext);
            vim_free (qfp -> qf_pattern);
            vim_free (qfp);
            if (stop)
                qfl->qf_count = 1;
        }
        qfl->qf_start = qfpnext;
        --qfl->qf_count;
    }
    qfl->qf_index = 0;
    qfl->qf_start = NULL;
    qfl->qf_last = NULL;
    qfl->qf_ptr = NULL;
    qfl->qf_nonevalid = TRUE;
    qf_clean_dir_stack (& qfl -> qf_dir_stack);
    qfl->qf_directory = NULL;
    qf_clean_dir_stack (& qfl -> qf_file_stack);
    qfl->qf_currfile = NULL;
    qfl->qf_multiline = FALSE;
    qfl->qf_multiignore = FALSE;
    qfl->qf_multiscan = FALSE;
}

static void qf_clean_dir_stack (struct dir_stack_T **stackptr) {
    struct dir_stack_T *ds_ptr;
    while ((ds_ptr = *stackptr) != NULL) {
        *stackptr = (*stackptr)->next;
        vim_free (ds_ptr -> dirname);
        vim_free (ds_ptr);
    }
}

void copy_loclist (win_T *from, win_T *to) {
    qf_info_T *qi;
    int idx;
    int i;
    if (IS_LL_WINDOW (from))
        qi = from->w_llist_ref;
    else
        qi = from->w_llist;
    if (qi == NULL)
        return;
    if ((to->w_llist = ll_new_list ()) == NULL)
        return;
    to->w_llist->qf_listcount = qi->qf_listcount;
    for (idx = 0; idx < qi->qf_listcount; idx++) {
        qf_list_T *from_qfl;
        qf_list_T *to_qfl;
        to->w_llist->qf_curlist = idx;
        from_qfl = &qi->qf_lists[idx];
        to_qfl = &to->w_llist->qf_lists[idx];
        to_qfl->qf_nonevalid = from_qfl->qf_nonevalid;
        to_qfl->qf_count = 0;
        to_qfl->qf_index = 0;
        to_qfl->qf_start = NULL;
        to_qfl->qf_last = NULL;
        to_qfl->qf_ptr = NULL;
        if (from_qfl->qf_title != NULL)
            to_qfl->qf_title = vim_strsave (from_qfl->qf_title);
        else
            to_qfl->qf_title = NULL;
        if (from_qfl->qf_ctx != NULL) {
            to_qfl->qf_ctx = alloc_tv ();
            if (to_qfl->qf_ctx != NULL)
                copy_tv (from_qfl->qf_ctx, to_qfl->qf_ctx);
        }
        else
            to_qfl->qf_ctx = NULL;
        if (from_qfl->qf_count) {
            qfline_T *from_qfp;
            qfline_T *prevp;
            for (i = 0, from_qfp = from_qfl->qf_start; i < from_qfl->qf_count && from_qfp != NULL; ++i, from_qfp = from_qfp->qf_next) {
                if (qf_add_entry (to->w_llist, to->w_llist->qf_curlist, NULL, NULL, 0, from_qfp->qf_text, from_qfp->qf_lnum, from_qfp->qf_col, from_qfp->qf_viscol, from_qfp->qf_pattern, from_qfp->qf_nr, 0, from_qfp->qf_valid) == FAIL) {
                    qf_free_all (to);
                    return;
                }
                prevp = to->w_llist->qf_lists[to->w_llist->qf_curlist].qf_last;
                prevp->qf_fnum = from_qfp->qf_fnum;
                prevp->qf_type = from_qfp->qf_type;
                if (from_qfl->qf_ptr == from_qfp)
                    to_qfl->qf_ptr = prevp;
            }
        }
        to_qfl->qf_index = from_qfl->qf_index;
        to_qfl->qf_id = ++last_qf_id;
        to_qfl->qf_changedtick = 0L;
        if (to_qfl->qf_nonevalid) {
            to_qfl->qf_ptr = to_qfl->qf_start;
            to_qfl->qf_index = 1;
        }
    }
    to->w_llist->qf_curlist = qi->qf_curlist;
}

static qf_info_T *ll_new_list (void) {
    qf_info_T *qi;
    qi = (qf_info_T *) alloc ((unsigned ) sizeof (qf_info_T));
    if (qi != NULL) {
        vim_memset (qi, 0, (size_t) (sizeof (qf_info_T)));
        qi->qf_refcount++;
    }
    return qi;
}

static int qf_add_entry (qf_info_T *qi, int qf_idx, char_u *dir, char_u *fname, int bufnum, char_u *mesg, long  lnum, int col, int vis_col, char_u *pattern, int nr, int type, int valid) {
    qfline_T *qfp;
    qfline_T **lastp;
    if ((qfp = (qfline_T *) alloc ((unsigned ) sizeof (qfline_T))) == NULL)
        return FAIL;
    if (bufnum != 0) {
        buf_T *buf = buflist_findnr (bufnum);
        qfp->qf_fnum = bufnum;
        if (buf != NULL)
            buf->b_has_qf_entry |= (qi == &ql_info) ? BUF_HAS_QF_ENTRY : BUF_HAS_LL_ENTRY;
    }
    else
        qfp->qf_fnum = qf_get_fnum (qi, qf_idx, dir, fname);
    if ((qfp->qf_text = vim_strsave (mesg)) == NULL) {
        vim_free (qfp);
        return FAIL;
    }
    qfp->qf_lnum = lnum;
    qfp->qf_col = col;
    qfp->qf_viscol = vis_col;
    if (pattern == NULL || *pattern == NUL)
        qfp->qf_pattern = NULL;
    else if ((qfp->qf_pattern = vim_strsave (pattern)) == NULL) {
        vim_free (qfp -> qf_text);
        vim_free (qfp);
        return FAIL;
    }
    qfp->qf_nr = nr;
    if (type != 1 && !vim_isprintc (type))
        type = 0;
    qfp->qf_type = type;
    qfp->qf_valid = valid;
    lastp = &qi->qf_lists[qf_idx].qf_last;
    if (qi->qf_lists[qf_idx].qf_count == 0) {
        qi->qf_lists[qf_idx].qf_start = qfp;
        qi->qf_lists[qf_idx].qf_ptr = qfp;
        qi->qf_lists[qf_idx].qf_index = 0;
        qfp->qf_prev = NULL;
    }
    else {
        qfp->qf_prev = *lastp;
        (*lastp)->qf_next = qfp;
    }
    qfp->qf_next = NULL;
    qfp->qf_cleared = FALSE;
    *lastp = qfp;
    ++qi->qf_lists[qf_idx].qf_count;
    if (qi->qf_lists[qf_idx].qf_index == 0 && qfp->qf_valid) {
        qi->qf_lists[qf_idx].qf_index = qi->qf_lists[qf_idx].qf_count;
        qi->qf_lists[qf_idx].qf_ptr = qfp;
    }
    return OK;
}

static int qf_get_fnum (qf_info_T *qi, int qf_idx, char_u *directory, char_u *fname) {
    char_u *ptr = NULL;
    buf_T *buf;
    char_u *bufname;
    if (fname == NULL || *fname == NUL)
        return 0;
    if (directory != NULL && !vim_isAbsName (fname) && (ptr = concat_fnames (directory, fname, TRUE)) != NULL) {
        if (mch_getperm (ptr) < 0) {
            vim_free (ptr);
            directory = qf_guess_filepath (qi, qf_idx, fname);
            if (directory)
                ptr = concat_fnames (directory, fname, TRUE);
            else
                ptr = vim_strsave (fname);
        }
        bufname = ptr;
    }
    else
        bufname = fname;
    if (qf_last_bufname != NULL && STRCMP (bufname, qf_last_bufname) == 0 && bufref_valid (&qf_last_bufref)) {
        buf = qf_last_bufref.br_buf;
        vim_free (ptr);
    }
    else {
        vim_free (qf_last_bufname);
        buf = buflist_new (bufname, NULL, (linenr_T) 0, BLN_NOOPT);
        if (bufname == ptr)
            qf_last_bufname = bufname;
        else
            qf_last_bufname = vim_strsave (bufname);
        set_bufref (& qf_last_bufref, buf);
    }
    if (buf == NULL)
        return 0;
    buf->b_has_qf_entry = (qi == &ql_info) ? BUF_HAS_QF_ENTRY : BUF_HAS_LL_ENTRY;
    return buf->b_fnum;
}

static char_u *qf_guess_filepath (qf_info_T *qi, int qf_idx, char_u *filename) {
    struct dir_stack_T *ds_ptr;
    struct dir_stack_T *ds_tmp;
    char_u *fullname;
    qf_list_T *qfl = &qi->qf_lists[qf_idx];
    if (qfl->qf_dir_stack == NULL)
        return NULL;
    ds_ptr = qfl->qf_dir_stack->next;
    fullname = NULL;
    while (ds_ptr) {
        vim_free (fullname);
        fullname = concat_fnames (ds_ptr->dirname, filename, TRUE);
        if ((fullname != NULL) && (mch_getperm (fullname) >= 0))
            break;
        ds_ptr = ds_ptr->next;
    }
    vim_free (fullname);
    while (qfl->qf_dir_stack->next != ds_ptr) {
        ds_tmp = qfl->qf_dir_stack->next;
        qfl->qf_dir_stack->next = qfl->qf_dir_stack->next->next;
        vim_free (ds_tmp -> dirname);
        vim_free (ds_tmp);
    }
    return ds_ptr == NULL ? NULL : ds_ptr->dirname;
}

linenr_T qf_current_entry (win_T *wp) {
    qf_info_T *qi = &ql_info;
    if (IS_LL_WINDOW (wp))
        qi = wp->w_llist_ref;
    return qi->qf_lists[qi->qf_curlist].qf_index;
}

void qf_mark_adjust (win_T *wp, linenr_T line1, linenr_T line2, long  amount, long  amount_after) {
    int i;
    qfline_T *qfp;
    int idx;
    qf_info_T *qi = &ql_info;
    int found_one = FALSE;
    int buf_has_flag = wp == NULL ? BUF_HAS_QF_ENTRY : BUF_HAS_LL_ENTRY;
    if (!(curbuf->b_has_qf_entry & buf_has_flag))
        return;
    if (wp != NULL) {
        if (wp->w_llist == NULL)
            return;
        qi = wp->w_llist;
    }
    for (idx = 0; idx < qi->qf_listcount; ++idx)
        if (qi->qf_lists[idx].qf_count)
            for (i = 0, qfp = qi->qf_lists[idx].qf_start; i < qi->qf_lists[idx].qf_count && qfp != NULL; ++i, qfp = qfp->qf_next)
                if (qfp->qf_fnum == curbuf->b_fnum) {
                    found_one = TRUE;
                    if (qfp->qf_lnum >= line1 && qfp->qf_lnum <= line2) {
                        if (amount == MAXLNUM)
                            qfp->qf_cleared = TRUE;
                        else
                            qfp->qf_lnum += amount;
                    }
                    else if (amount_after && qfp->qf_lnum > line2)
                        qfp->qf_lnum += amount_after;
                }
    if (!found_one)
        curbuf->b_has_qf_entry &= ~buf_has_flag;
}

int qf_get_cur_valid_idx (exarg_T *eap) {
    qf_info_T *qi = &ql_info;
    qf_list_T *qfl;
    qfline_T *qfp;
    int i, eidx = 0;
    int prev_fnum = 0;
    if (eap->cmdidx == CMD_ldo || eap->cmdidx == CMD_lfdo) {
        qi = GET_LOC_LIST (curwin);
        if (qi == NULL)
            return 1;
    }
    qfl = &qi->qf_lists[qi->qf_curlist];
    qfp = qfl->qf_start;
    if (qfl->qf_count <= 0 || qfl->qf_nonevalid)
        return 1;
    for (i = 1; i <= qfl->qf_index && qfp != NULL; i++, qfp = qfp->qf_next) {
        if (qfp->qf_valid) {
            if (eap->cmdidx == CMD_cfdo || eap->cmdidx == CMD_lfdo) {
                if (qfp->qf_fnum > 0 && qfp->qf_fnum != prev_fnum) {
                    eidx++;
                    prev_fnum = qfp->qf_fnum;
                }
            }
            else
                eidx++;
        }
    }
    return eidx ? eidx : 1;
}

int qf_get_size (exarg_T *eap) {
    qf_info_T *qi = &ql_info;
    qfline_T *qfp;
    int i, sz = 0;
    int prev_fnum = 0;
    if (eap->cmdidx == CMD_ldo || eap->cmdidx == CMD_lfdo) {
        qi = GET_LOC_LIST (curwin);
        if (qi == NULL)
            return 0;
    }
    for (i = 0, qfp = qi->qf_lists[qi->qf_curlist].qf_start; i < qi->qf_lists[qi->qf_curlist].qf_count && qfp != NULL; ++i, qfp = qfp->qf_next) {
        if (qfp->qf_valid) {
            if (eap->cmdidx == CMD_cdo || eap->cmdidx == CMD_ldo)
                sz++;
            else if (qfp->qf_fnum > 0 && qfp->qf_fnum != prev_fnum) {
                sz++;
                prev_fnum = qfp->qf_fnum;
            }
        }
    }
    return sz;
}

int grep_internal (cmdidx_T cmdidx) {
    return ((cmdidx == CMD_grep || cmdidx == CMD_lgrep || cmdidx == CMD_grepadd || cmdidx == CMD_lgrepadd) && STRCMP ("internal", *curbuf->b_p_gp == NUL ? p_gp : curbuf->b_p_gp) == 0);
}

int get_errorlist (qf_info_T *qi_arg, win_T *wp, int qf_idx, list_T *list) {
    qf_info_T *qi = qi_arg;
    dict_T *dict;
    char_u buf [2];
    qfline_T *qfp;
    int i;
    int bufnum;
    if (qi == NULL) {
        qi = &ql_info;
        if (wp != NULL) {
            qi = GET_LOC_LIST (wp);
            if (qi == NULL)
                return FAIL;
        }
    }
    if (qf_idx == -1)
        qf_idx = qi->qf_curlist;
    if (qf_idx >= qi->qf_listcount || qi->qf_lists[qf_idx].qf_count == 0)
        return FAIL;
    qfp = qi->qf_lists[qf_idx].qf_start;
    for (i = 1; !got_int && i <= qi->qf_lists[qf_idx].qf_count; ++i) {
        bufnum = qfp->qf_fnum;
        if (bufnum != 0 && (buflist_findnr (bufnum) == NULL))
            bufnum = 0;
        if ((dict = dict_alloc ()) == NULL)
            return FAIL;
        if (list_append_dict (list, dict) == FAIL)
            return FAIL;
        buf[0] = qfp->qf_type;
        buf[1] = NUL;
        if (dict_add_nr_str (dict, "bufnr", (long ) bufnum, NULL) == FAIL || dict_add_nr_str (dict, "lnum", (long ) qfp->qf_lnum, NULL) == FAIL || dict_add_nr_str (dict, "col", (long ) qfp->qf_col, NULL) == FAIL || dict_add_nr_str (dict, "vcol", (long ) qfp->qf_viscol, NULL) == FAIL || dict_add_nr_str (dict, "nr", (long ) qfp->qf_nr, NULL) == FAIL || dict_add_nr_str (dict, "pattern", 0L, qfp->qf_pattern == NULL ? (char_u *) "" : qfp->qf_pattern) == FAIL || dict_add_nr_str (dict, "text", 0L, qfp->qf_text == NULL ? (char_u *) "" : qfp->qf_text) == FAIL || dict_add_nr_str (dict, "type", 0L, buf) == FAIL || dict_add_nr_str (dict, "valid", (long ) qfp->qf_valid, NULL) == FAIL)
            return FAIL;
        qfp = qfp->qf_next;
        if (qfp == NULL)
            break;
    }
    return OK;
}

int qf_get_properties (win_T *wp, dict_T *what, dict_T *retdict) {
    qf_info_T *qi = &ql_info;
    int status = OK;
    int qf_idx;
    dictitem_T *di;
    int flags = QF_GETLIST_NONE;
    if ((di = dict_find (what, (char_u *) "lines", -1)) != NULL)
        return qf_get_list_from_lines (what, di, retdict);
    if (wp != NULL)
        qi = GET_LOC_LIST (wp);
    if (dict_find (what, (char_u *) "all", -1) != NULL)
        flags |= QF_GETLIST_ALL;
    if (dict_find (what, (char_u *) "title", -1) != NULL)
        flags |= QF_GETLIST_TITLE;
    if (dict_find (what, (char_u *) "nr", -1) != NULL)
        flags |= QF_GETLIST_NR;
    if (dict_find (what, (char_u *) "winid", -1) != NULL)
        flags |= QF_GETLIST_WINID;
    if (dict_find (what, (char_u *) "context", -1) != NULL)
        flags |= QF_GETLIST_CONTEXT;
    if (dict_find (what, (char_u *) "id", -1) != NULL)
        flags |= QF_GETLIST_ID;
    if (dict_find (what, (char_u *) "items", -1) != NULL)
        flags |= QF_GETLIST_ITEMS;
    if (dict_find (what, (char_u *) "idx", -1) != NULL)
        flags |= QF_GETLIST_IDX;
    if (dict_find (what, (char_u *) "size", -1) != NULL)
        flags |= QF_GETLIST_SIZE;
    if (dict_find (what, (char_u *) "changedtick", -1) != NULL)
        flags |= QF_GETLIST_TICK;
    if (qi != NULL && qi->qf_listcount != 0) {
        qf_idx = qi->qf_curlist;
        if ((di = dict_find (what, (char_u *) "nr", -1)) != NULL) {
            if (di->di_tv.v_type == VAR_NUMBER) {
                if (di->di_tv.vval.v_number != 0) {
                    qf_idx = di->di_tv.vval.v_number - 1;
                    if (qf_idx < 0 || qf_idx >= qi->qf_listcount)
                        qf_idx = -1;
                }
            }
            else if (di->di_tv.v_type == VAR_STRING && di->di_tv.vval.v_string != NULL && STRCMP (di->di_tv.vval.v_string, "$") == 0)
                qf_idx = qi->qf_listcount - 1;
            else
                qf_idx = -1;
            flags |= QF_GETLIST_NR;
        }
        if ((di = dict_find (what, (char_u *) "id", -1)) != NULL) {
            if (di->di_tv.v_type == VAR_NUMBER) {
                if (di->di_tv.vval.v_number != 0)
                    qf_idx = qf_id2nr (qi, di->di_tv.vval.v_number);
                flags |= QF_GETLIST_ID;
            }
            else
                qf_idx = -1;
        }
    }
    if (qi == NULL || qi->qf_listcount == 0 || qf_idx == -1) {
        if (flags & QF_GETLIST_TITLE)
            status = dict_add_nr_str (retdict, "title", 0L, (char_u *) "");
        if ((status == OK) && (flags & QF_GETLIST_ITEMS)) {
            list_T *l = list_alloc ();
            if (l != NULL)
                status = dict_add_list (retdict, "items", l);
            else
                status = FAIL;
        }
        if ((status == OK) && (flags & QF_GETLIST_NR))
            status = dict_add_nr_str (retdict, "nr", 0L, NULL);
        if ((status == OK) && (flags & QF_GETLIST_WINID))
            status = dict_add_nr_str (retdict, "winid", qf_winid (qi), NULL);
        if ((status == OK) && (flags & QF_GETLIST_CONTEXT))
            status = dict_add_nr_str (retdict, "context", 0L, (char_u *) "");
        if ((status == OK) && (flags & QF_GETLIST_ID))
            status = dict_add_nr_str (retdict, "id", 0L, NULL);
        if ((status == OK) && (flags & QF_GETLIST_IDX))
            status = dict_add_nr_str (retdict, "idx", 0L, NULL);
        if ((status == OK) && (flags & QF_GETLIST_SIZE))
            status = dict_add_nr_str (retdict, "size", 0L, NULL);
        if ((status == OK) && (flags & QF_GETLIST_TICK))
            status = dict_add_nr_str (retdict, "changedtick", 0L, NULL);
        return status;
    }
    if (flags & QF_GETLIST_TITLE) {
        char_u *t;
        t = qi->qf_lists[qf_idx].qf_title;
        if (t == NULL)
            t = (char_u *) "";
        status = dict_add_nr_str (retdict, "title", 0L, t);
    }
    if ((status == OK) && (flags & QF_GETLIST_NR))
        status = dict_add_nr_str (retdict, "nr", qf_idx +1, NULL);
    if ((status == OK) && (flags & QF_GETLIST_WINID))
        status = dict_add_nr_str (retdict, "winid", qf_winid (qi), NULL);
    if ((status == OK) && (flags & QF_GETLIST_ITEMS)) {
        list_T *l = list_alloc ();
        if (l != NULL) {
            (void) get_errorlist (qi, NULL, qf_idx, l);
            dict_add_list (retdict, "items", l);
        }
        else
            status = FAIL;
    }
    if ((status == OK) && (flags & QF_GETLIST_CONTEXT)) {
        if (qi->qf_lists[qf_idx].qf_ctx != NULL) {
            di = dictitem_alloc ((char_u *) "context");
            if (di != NULL) {
                copy_tv (qi -> qf_lists [qf_idx].qf_ctx, & di -> di_tv);
                status = dict_add (retdict, di);
                if (status == FAIL)
                    dictitem_free (di);
            }
            else
                status = FAIL;
        }
        else
            status = dict_add_nr_str (retdict, "context", 0L, (char_u *) "");
    }
    if ((status == OK) && (flags & QF_GETLIST_ID))
        status = dict_add_nr_str (retdict, "id", qi->qf_lists[qf_idx].qf_id, NULL);
    if ((status == OK) && (flags & QF_GETLIST_IDX)) {
        int idx = qi->qf_lists[qf_idx].qf_index;
        if (qi->qf_lists[qf_idx].qf_count == 0)
            idx = 0;
        status = dict_add_nr_str (retdict, "idx", idx, NULL);
    }
    if ((status == OK) && (flags & QF_GETLIST_SIZE))
        status = dict_add_nr_str (retdict, "size", qi->qf_lists[qf_idx].qf_count, NULL);
    if ((status == OK) && (flags & QF_GETLIST_TICK))
        status = dict_add_nr_str (retdict, "changedtick", qi->qf_lists[qf_idx].qf_changedtick, NULL);
    return status;
}

static int qf_get_list_from_lines (dict_T *what, dictitem_T *di, dict_T *retdict) {
    int status = FAIL;
    qf_info_T *qi;
    char_u *errorformat = p_efm;
    dictitem_T *efm_di;
    list_T *l;
    if (di->di_tv.v_type == VAR_LIST && di->di_tv.vval.v_list != NULL) {
        if ((efm_di = dict_find (what, (char_u *) "efm", -1)) != NULL) {
            if (efm_di->di_tv.v_type != VAR_STRING || efm_di->di_tv.vval.v_string == NULL)
                return FAIL;
            errorformat = efm_di->di_tv.vval.v_string;
        }
        l = list_alloc ();
        if (l == NULL)
            return FAIL;
        qi = (qf_info_T *) alloc ((unsigned ) sizeof (qf_info_T));
        if (qi != NULL) {
            vim_memset (qi, 0, (size_t) (sizeof (qf_info_T)));
            qi->qf_refcount++;
            if (qf_init_ext (qi, 0, NULL, NULL, &di->di_tv, errorformat, TRUE, (linenr_T) 0, (linenr_T) 0, NULL, NULL) > 0) {
                (void) get_errorlist (qi, NULL, 0, l);
                qf_free (qi, 0);
            }
            free (qi);
        }
        dict_add_list (retdict, "items", l);
        status = OK;
    }
    return status;
}

static int qf_init_ext (qf_info_T *qi, int qf_idx, char_u *efile, buf_T *buf, typval_T *tv, char_u *errorformat, int newlist, linenr_T lnumfirst, linenr_T lnumlast, char_u *qf_title, char_u *enc) {
    qf_list_T *qfl;
    qfstate_T state;
    qffields_T fields;
    qfline_T *old_last = NULL;
    int adding = FALSE;
    static efm_T *fmt_first = NULL;
    char_u *efm;
    static char_u *last_efm = NULL;
    int retval = -1;
    int status;
    VIM_CLEAR (qf_last_bufname);
    vim_memset (& state, 0, sizeof (state));
    vim_memset (& fields, 0, sizeof (fields));
    fields.namebuf = alloc_id (CMDBUFFSIZE +1, aid_qf_namebuf);
    fields.errmsglen = CMDBUFFSIZE + 1;
    fields.errmsg = alloc_id (fields.errmsglen, aid_qf_errmsg);
    fields.pattern = alloc_id (CMDBUFFSIZE +1, aid_qf_pattern);
    if (fields.namebuf == NULL || fields.errmsg == NULL || fields.pattern == NULL)
        goto qf_init_end;
    if (efile != NULL && (state.fd = mch_fopen ((char *) efile, "r")) == NULL) {
        EMSG2 (_ (e_openerrf), efile);
        goto qf_init_end;
    }
    if (newlist || qf_idx == qi->qf_listcount) {
        qf_new_list (qi, qf_title);
        qf_idx = qi->qf_curlist;
    }
    else {
        adding = TRUE;
        if (qi->qf_lists[qf_idx].qf_count > 0)
            old_last = qi->qf_lists[qf_idx].qf_last;
    }
    qfl = &qi->qf_lists[qf_idx];
    if (errorformat == p_efm && tv == NULL && *buf->b_p_efm != NUL)
        efm = buf->b_p_efm;
    else
        efm = errorformat;
    if (last_efm == NULL || (STRCMP (last_efm, efm) != 0)) {
        VIM_CLEAR (last_efm);
        free_efm_list (& fmt_first);
        fmt_first = parse_efm_option (efm);
        if (fmt_first != NULL)
            last_efm = vim_strsave (efm);
    }
    if (fmt_first == NULL)
        goto error2;
    got_int = FALSE;
    if (tv != NULL) {
        if (tv->v_type == VAR_STRING)
            state.p_str = tv->vval.v_string;
        else if (tv->v_type == VAR_LIST)
            state.p_li = tv->vval.v_list->lv_first;
        state.tv = tv;
    }
    state.buf = buf;
    state.buflnum = lnumfirst;
    state.lnumlast = lnumlast;
    while (!got_int) {
        status = qf_get_nextline (&state);
        if (status == QF_NOMEM)
            goto qf_init_end;
        if (status == QF_END_OF_INPUT)
            break;
        status = qf_parse_line (qi, qf_idx, state.linebuf, state.linelen, fmt_first, &fields);
        if (status == QF_FAIL)
            goto error2;
        if (status == QF_NOMEM)
            goto qf_init_end;
        if (status == QF_IGNORE_LINE)
            continue;
        if (qf_add_entry (qi, qf_idx, qfl->qf_directory, (*fields.namebuf || qfl->qf_directory != NULL) ? fields.namebuf : ((qfl->qf_currfile != NULL && fields.valid) ? qfl->qf_currfile : (char_u *) NULL), 0, fields.errmsg, fields.lnum, fields.col, fields.use_viscol, fields.pattern, fields.enr, fields.type, fields.valid) == FAIL)
            goto error2;
        line_breakcheck ();
    }
    if (state.fd == NULL || !ferror (state.fd)) {
        if (qfl->qf_index == 0) {
            qfl->qf_ptr = qfl->qf_start;
            qfl->qf_index = 1;
            qfl->qf_nonevalid = TRUE;
        }
        else {
            qfl->qf_nonevalid = FALSE;
            if (qfl->qf_ptr == NULL)
                qfl->qf_ptr = qfl->qf_start;
        }
        retval = qfl->qf_count;
        goto qf_init_end;
    }
    EMSG (_ (e_readerrf));
error2 :
    if (!adding) {
        qf_free (qi, qi -> qf_curlist);
        qi->qf_listcount--;
        if (qi->qf_curlist > 0)
            --qi->qf_curlist;
    }
qf_init_end :
    if (state.fd != NULL)
        fclose (state.fd);
    vim_free (fields.namebuf);
    vim_free (fields.errmsg);
    vim_free (fields.pattern);
    vim_free (state.growbuf);
    if (qf_idx == qi->qf_curlist)
        qf_update_buffer (qi, old_last);
    return retval;
}

static void qf_new_list (qf_info_T *qi, char_u *qf_title) {
    int i;
    while (qi->qf_listcount > qi->qf_curlist + 1)
        qf_free (qi, --qi->qf_listcount);
    if (qi->qf_listcount == LISTCOUNT) {
        qf_free (qi, 0);
        for (i = 1; i < LISTCOUNT; ++i)
            qi->qf_lists[i - 1] = qi->qf_lists[i];
        qi->qf_curlist = LISTCOUNT - 1;
    }
    else
        qi->qf_curlist = qi->qf_listcount++;
    vim_memset (& qi -> qf_lists [qi -> qf_curlist], 0, (size_t) (sizeof (qf_list_T)));
    qf_store_title (qi, qi -> qf_curlist, qf_title);
    qi->qf_lists[qi->qf_curlist].qf_id = ++last_qf_id;
}

static void qf_store_title (qf_info_T *qi, int qf_idx, char_u *title) {
    VIM_CLEAR (qi -> qf_lists [qf_idx].qf_title);
    if (title != NULL) {
        char_u *p = alloc ((int) STRLEN (title) + 2);
        qi->qf_lists[qf_idx].qf_title = p;
        if (p != NULL)
            sprintf ((char *) p, ":%s", (char *) title);
    }
}

static void free_efm_list (efm_T **efm_first) {
    efm_T *efm_ptr;
    for (efm_ptr = *efm_first; efm_ptr != NULL; efm_ptr = *efm_first) {
        *efm_first = efm_ptr->next;
        vim_regfree (efm_ptr -> prog);
        vim_free (efm_ptr);
    }
    fmt_start = NULL;
}

static efm_T *parse_efm_option (char_u *efm) {
    char_u *errmsg = NULL;
    int errmsglen;
    efm_T *fmt_ptr = NULL;
    efm_T *fmt_first = NULL;
    efm_T *fmt_last = NULL;
    char_u *fmtstr = NULL;
    int len;
    int i;
    int round;
    errmsglen = CMDBUFFSIZE + 1;
    errmsg = alloc_id (errmsglen, aid_qf_errmsg);
    if (errmsg == NULL)
        goto parse_efm_end;
    i = (FMT_PATTERNS * 3) + ((int) STRLEN (efm) << 2);
    for (round = FMT_PATTERNS; round > 0;)
        i += (int) STRLEN (fmt_pat[--round].pattern);
    i += 2;
    if ((fmtstr = alloc (i)) == NULL)
        goto parse_efm_error;
    while (efm[0] != NUL) {
        fmt_ptr = (efm_T *) alloc_clear ((unsigned ) sizeof (efm_T));
        if (fmt_ptr == NULL)
            goto parse_efm_error;
        if (fmt_first == NULL)
            fmt_first = fmt_ptr;
        else
            fmt_last->next = fmt_ptr;
        fmt_last = fmt_ptr;
        for (len = 0; efm[len] != NUL && efm[len] != ','; ++len)
            if (efm[len] == '\\' && efm[len + 1] != NUL)
                ++len;
        if (efm_to_regpat (efm, len, fmt_ptr, fmtstr, errmsg) == -1)
            goto parse_efm_error;
        if ((fmt_ptr->prog = vim_regcomp (fmtstr, RE_MAGIC +RE_STRING)) == NULL)
            goto parse_efm_error;
        efm = skip_to_option_part (efm +len);
    }
    if (fmt_first == NULL)
        EMSG (_ ("E378: 'errorformat' contains no pattern"));
    goto parse_efm_end;
parse_efm_error :
    free_efm_list (&fmt_first);
parse_efm_end :
    vim_free (fmtstr);
    vim_free (errmsg);
    return fmt_first;
}

static int efm_to_regpat (char_u *efm, int len, efm_T *fmt_ptr, char_u *regpat, char_u *errmsg) {
    char_u *ptr;
    char_u *efmp;
    char_u *srcptr;
    int round;
    int idx = 0;
    ptr = regpat;
    *ptr++ = '^';
    round = 0;
    for (efmp = efm; efmp < efm + len; ++efmp) {
        if (*efmp == '%') {
            ++efmp;
            for (idx = 0; idx < FMT_PATTERNS; ++idx)
                if (fmt_pat[idx].convchar == *efmp)
                    break;
            if (idx < FMT_PATTERNS) {
                if (fmt_ptr->addr[idx]) {
                    sprintf ((char *) errmsg, _ ("E372: Too many %%%c in format string"), * efmp);
                    EMSG (errmsg);
                    return -1;
                }
                if ((idx && idx < 6 && vim_strchr ((char_u *) "DXOPQ", fmt_ptr->prefix) != NULL) || (idx == 6 && vim_strchr ((char_u *) "OPQ", fmt_ptr->prefix) == NULL)) {
                    sprintf ((char *) errmsg, _ ("E373: Unexpected %%%c in format string"), * efmp);
                    EMSG (errmsg);
                    return -1;
                }
                fmt_ptr->addr[idx] = (char_u) ++round;
                *ptr++ = '\\';
                *ptr++ = '(';
                if (*efmp == 'f' && efmp[1] != NUL) {
                    if (efmp[1] != '\\' && efmp[1] != '%') {
                        STRCPY (ptr, ".\\{-1,}");
                        ptr += 7;
                    }
                    else {
                        STRCPY (ptr, "\\f\\+");
                        ptr += 4;
                    }
                }
                else {
                    srcptr = (char_u *) fmt_pat[idx].pattern;
                    while ((*ptr = *srcptr++) != NUL)
                        ++ptr;
                }
                *ptr++ = '\\';
                *ptr++ = ')';
            }
            else if (*efmp == '*') {
                if (*++efmp == '[' || *efmp == '\\') {
                    if ((*ptr++ = *efmp) == '[') {
                        if (efmp[1] == '^')
                            *ptr++ = *++efmp;
                        if (efmp < efm + len) {
                            *ptr++ = *++efmp;
                            while (efmp < efm + len && (*ptr++ = *++efmp) != ']')
                                ;
                            if (efmp == efm + len) {
                                EMSG (_ ("E374: Missing ] in format string"));
                                return -1;
                            }
                        }
                    }
                    else if (efmp < efm + len)
                        *ptr++ = *++efmp;
                    *ptr++ = '\\';
                    *ptr++ = '+';
                }
                else {
                    sprintf ((char *) errmsg, _ ("E375: Unsupported %%%c in format string"), * efmp);
                    EMSG (errmsg);
                    return -1;
                }
            }
            else if (vim_strchr ((char_u *) "%\\.^$~[", *efmp) != NULL)
                *ptr++ = *efmp;
            else if (*efmp == '#')
                *ptr++ = '*';
            else if (*efmp == '>')
                fmt_ptr->conthere = TRUE;
            else if (efmp == efm + 1) {
                if (vim_strchr ((char_u *) "+-", *efmp) != NULL)
                    fmt_ptr->flags = *efmp++;
                if (vim_strchr ((char_u *) "DXAEWICZGOPQ", *efmp) != NULL)
                    fmt_ptr->prefix = *efmp;
                else {
                    sprintf ((char *) errmsg, _ ("E376: Invalid %%%c in format string prefix"), * efmp);
                    EMSG (errmsg);
                    return -1;
                }
            }
            else {
                sprintf ((char *) errmsg, _ ("E377: Invalid %%%c in format string"), * efmp);
                EMSG (errmsg);
                return -1;
            }
        }
        else {
            if (*efmp == '\\' && efmp + 1 < efm + len)
                ++efmp;
            else if (vim_strchr ((char_u *) ".*^$~[", *efmp) != NULL)
                *ptr++ = '\\';
            if (*efmp)
                *ptr++ = *efmp;
        }
    }
    *ptr++ = '$';
    *ptr = NUL;
    return 0;
}

static int qf_get_nextline (qfstate_T *state) {
    int status = QF_FAIL;
    if (state->fd == NULL) {
        if (state->tv != NULL) {
            if (state->tv->v_type == VAR_STRING)
                status = qf_get_next_str_line (state);
            else if (state->tv->v_type == VAR_LIST)
                status = qf_get_next_list_line (state);
        }
        else
            status = qf_get_next_buf_line (state);
    }
    else
        status = qf_get_next_file_line (state);
    if (status != QF_OK)
        return status;
    if (state->linelen > 0 && state->linebuf[state->linelen - 1] == '\n') {
        state->linebuf[state->linelen - 1] = NUL;
    }
    return QF_OK;
}

static int qf_get_next_str_line (qfstate_T *state) {
    char_u *p_str = state->p_str;
    char_u *p;
    int len;
    if (*p_str == NUL)
        return QF_END_OF_INPUT;
    p = vim_strchr (p_str, '\n');
    if (p != NULL)
        len = (int) (p - p_str) + 1;
    else
        len = (int) STRLEN (p_str);
    if (len > IOSIZE - 2) {
        state->linebuf = qf_grow_linebuf (state, len);
        if (state->linebuf == NULL)
            return QF_NOMEM;
    }
    else {
        state->linebuf = IObuff;
        state->linelen = len;
    }
    vim_strncpy (state -> linebuf, p_str, state -> linelen);
    p_str += len;
    state->p_str = p_str;
    return QF_OK;
}

static char_u *qf_grow_linebuf (qfstate_T *state, int newsz) {
    state->linelen = newsz > LINE_MAXLEN ? LINE_MAXLEN - 1 : newsz;
    if (state->growbuf == NULL) {
        state->growbuf = alloc (state->linelen + 1);
        if (state->growbuf == NULL)
            return NULL;
        state->growbufsiz = state->linelen;
    }
    else if (state->linelen > state->growbufsiz) {
        state->growbuf = vim_realloc (state->growbuf, state->linelen + 1);
        if (state->growbuf == NULL)
            return NULL;
        state->growbufsiz = state->linelen;
    }
    return state->growbuf;
}

static int qf_get_next_list_line (qfstate_T *state) {
    listitem_T *p_li = state->p_li;
    int len;
    while (p_li != NULL && (p_li->li_tv.v_type != VAR_STRING || p_li->li_tv.vval.v_string == NULL))
        p_li = p_li->li_next;
    if (p_li == NULL) {
        state->p_li = NULL;
        return QF_END_OF_INPUT;
    }
    len = (int) STRLEN (p_li->li_tv.vval.v_string);
    if (len > IOSIZE - 2) {
        state->linebuf = qf_grow_linebuf (state, len);
        if (state->linebuf == NULL)
            return QF_NOMEM;
    }
    else {
        state->linebuf = IObuff;
        state->linelen = len;
    }
    vim_strncpy (state -> linebuf, p_li -> li_tv.vval.v_string, state -> linelen);
    state->p_li = p_li->li_next;
    return QF_OK;
}

static int qf_get_next_buf_line (qfstate_T *state) {
    char_u *p_buf = NULL;
    int len;
    if (state->buflnum > state->lnumlast)
        return QF_END_OF_INPUT;
    p_buf = ml_get_buf (state->buf, state->buflnum, FALSE);
    state->buflnum += 1;
    len = (int) STRLEN (p_buf);
    if (len > IOSIZE - 2) {
        state->linebuf = qf_grow_linebuf (state, len);
        if (state->linebuf == NULL)
            return QF_NOMEM;
    }
    else {
        state->linebuf = IObuff;
        state->linelen = len;
    }
    vim_strncpy (state -> linebuf, p_buf, state -> linelen);
    return QF_OK;
}

static int qf_get_next_file_line (qfstate_T *state) {
    int discard;
    int growbuflen;
    if (fgets ((char *) IObuff, IOSIZE, state->fd) == NULL)
        return QF_END_OF_INPUT;
    discard = FALSE;
    state->linelen = (int) STRLEN (IObuff);
    if (state->linelen == IOSIZE - 1 && !(IObuff[state->linelen - 1] == '\n')) {
        if (state->growbuf == NULL) {
            state->growbufsiz = 2 * (IOSIZE - 1);
            state->growbuf = alloc (state->growbufsiz);
            if (state->growbuf == NULL)
                return QF_NOMEM;
        }
        memcpy (state -> growbuf, IObuff, IOSIZE - 1);
        growbuflen = state->linelen;
        for (;;) {
            if (fgets ((char *) state->growbuf + growbuflen, state->growbufsiz - growbuflen, state->fd) == NULL)
                break;
            state->linelen = (int) STRLEN (state->growbuf + growbuflen);
            growbuflen += state->linelen;
            if ((state->growbuf)[growbuflen - 1] == '\n')
                break;
            if (state->growbufsiz == LINE_MAXLEN) {
                discard = TRUE;
                break;
            }
            state->growbufsiz = 2 * state->growbufsiz < LINE_MAXLEN ? 2 * state->growbufsiz : LINE_MAXLEN;
            state->growbuf = vim_realloc (state->growbuf, state->growbufsiz);
            if (state->growbuf == NULL)
                return QF_NOMEM;
        }
        while (discard) {
            if (fgets ((char *) IObuff, IOSIZE, state->fd) == NULL || (int) STRLEN (IObuff) < IOSIZE - 1 || IObuff[IOSIZE - 1] == '\n')
                break;
        }
        state->linebuf = state->growbuf;
        state->linelen = growbuflen;
    }
    else
        state->linebuf = IObuff;
    return QF_OK;
}

static int qf_parse_line (qf_info_T *qi, int qf_idx, char_u *linebuf, int linelen, efm_T *fmt_first, qffields_T *fields) {
    efm_T *fmt_ptr;
    char_u *ptr;
    int len;
    int i;
    int idx = 0;
    char_u *tail = NULL;
    regmatch_T regmatch;
    qf_list_T *qfl = &qi->qf_lists[qf_idx];
    regmatch.rm_ic = TRUE;
    if (fmt_start == NULL)
        fmt_ptr = fmt_first;
    else {
        fmt_ptr = fmt_start;
        fmt_start = NULL;
    }
    fields->valid = TRUE;
restofline :
    for (; fmt_ptr != NULL; fmt_ptr = fmt_ptr->next) {
        int r;
        idx = fmt_ptr->prefix;
        if (qfl->qf_multiscan && vim_strchr ((char_u *) "OPQ", idx) == NULL)
            continue;
        fields->namebuf[0] = NUL;
        fields->pattern[0] = NUL;
        if (!qfl->qf_multiscan)
            fields->errmsg[0] = NUL;
        fields->lnum = 0;
        fields->col = 0;
        fields->use_viscol = FALSE;
        fields->enr = -1;
        fields->type = 0;
        tail = NULL;
        regmatch.regprog = fmt_ptr->prog;
        r = vim_regexec (&regmatch, linebuf, (colnr_T) 0);
        fmt_ptr->prog = regmatch.regprog;
        if (r) {
            if ((idx == 'C' || idx == 'Z') && !qfl->qf_multiline)
                continue;
            if (vim_strchr ((char_u *) "EWI", idx) != NULL)
                fields->type = idx;
            else
                fields->type = 0;
            if ((i = (int) fmt_ptr->addr[0]) > 0) {
                int c;
                if (regmatch.startp[i] == NULL || regmatch.endp[i] == NULL)
                    continue;
                c = *regmatch.endp[i];
                *regmatch.endp[i] = NUL;
                expand_env (regmatch.startp [i], fields -> namebuf, CMDBUFFSIZE);
                *regmatch.endp[i] = c;
                if (vim_strchr ((char_u *) "OPQ", idx) != NULL && mch_getperm (fields->namebuf) == -1)
                    continue;
            }
            if ((i = (int) fmt_ptr->addr[1]) > 0) {
                if (regmatch.startp[i] == NULL)
                    continue;
                fields->enr = (int) atol ((char *) regmatch.startp[i]);
            }
            if ((i = (int) fmt_ptr->addr[2]) > 0) {
                if (regmatch.startp[i] == NULL)
                    continue;
                fields->lnum = atol ((char *) regmatch.startp[i]);
            }
            if ((i = (int) fmt_ptr->addr[3]) > 0) {
                if (regmatch.startp[i] == NULL)
                    continue;
                fields->col = (int) atol ((char *) regmatch.startp[i]);
            }
            if ((i = (int) fmt_ptr->addr[4]) > 0) {
                if (regmatch.startp[i] == NULL)
                    continue;
                fields->type = *regmatch.startp[i];
            }
            if (fmt_ptr->flags == '+' && !qfl->qf_multiscan) {
                if (linelen >= fields->errmsglen) {
                    if ((fields->errmsg = vim_realloc (fields->errmsg, linelen +1)) == NULL)
                        return QF_NOMEM;
                    fields->errmsglen = linelen + 1;
                }
                vim_strncpy (fields -> errmsg, linebuf, linelen);
            }
            else if ((i = (int) fmt_ptr->addr[5]) > 0) {
                if (regmatch.startp[i] == NULL || regmatch.endp[i] == NULL)
                    continue;
                len = (int) (regmatch.endp[i] - regmatch.startp[i]);
                if (len >= fields->errmsglen) {
                    if ((fields->errmsg = vim_realloc (fields->errmsg, len +1)) == NULL)
                        return QF_NOMEM;
                    fields->errmsglen = len + 1;
                }
                vim_strncpy (fields -> errmsg, regmatch.startp [i], len);
            }
            if ((i = (int) fmt_ptr->addr[6]) > 0) {
                if (regmatch.startp[i] == NULL)
                    continue;
                tail = regmatch.startp[i];
            }
            if ((i = (int) fmt_ptr->addr[7]) > 0) {
                char_u *match_ptr;
                if (regmatch.startp[i] == NULL || regmatch.endp[i] == NULL)
                    continue;
                fields->col = 0;
                for (match_ptr = regmatch.startp[i]; match_ptr != regmatch.endp[i]; ++match_ptr) {
                    ++fields->col;
                    if (*match_ptr == TAB) {
                        fields->col += 7;
                        fields->col -= fields->col % 8;
                    }
                }
                ++fields->col;
                fields->use_viscol = TRUE;
            }
            if ((i = (int) fmt_ptr->addr[8]) > 0) {
                if (regmatch.startp[i] == NULL)
                    continue;
                fields->col = (int) atol ((char *) regmatch.startp[i]);
                fields->use_viscol = TRUE;
            }
            if ((i = (int) fmt_ptr->addr[9]) > 0) {
                if (regmatch.startp[i] == NULL || regmatch.endp[i] == NULL)
                    continue;
                len = (int) (regmatch.endp[i] - regmatch.startp[i]);
                if (len > CMDBUFFSIZE - 5)
                    len = CMDBUFFSIZE - 5;
                STRCPY (fields -> pattern, "^\\V");
                STRNCAT (fields -> pattern, regmatch.startp [i], len);
                fields->pattern[len + 3] = '\\';
                fields->pattern[len + 4] = '$';
                fields->pattern[len + 5] = NUL;
            }
            break;
        }
    }
    qfl->qf_multiscan = FALSE;
    if (fmt_ptr == NULL || idx == 'D' || idx == 'X') {
        if (fmt_ptr != NULL) {
            if (idx == 'D') {
                if (*fields->namebuf == NUL) {
                    EMSG (_ ("E379: Missing or empty directory name"));
                    return QF_FAIL;
                }
                qfl->qf_directory = qf_push_dir (fields->namebuf, &qfl->qf_dir_stack, FALSE);
                if (qfl->qf_directory == NULL)
                    return QF_FAIL;
            }
            else if (idx == 'X')
                qfl->qf_directory = qf_pop_dir (&qfl->qf_dir_stack);
        }
        fields->namebuf[0] = NUL;
        fields->lnum = 0;
        fields->valid = FALSE;
        if (linelen >= fields->errmsglen) {
            if ((fields->errmsg = vim_realloc (fields->errmsg, linelen +1)) == NULL)
                return QF_NOMEM;
            fields->errmsglen = linelen + 1;
        }
        vim_strncpy (fields -> errmsg, linebuf, linelen);
        if (fmt_ptr == NULL)
            qfl->qf_multiline = qfl->qf_multiignore = FALSE;
    }
    else if (fmt_ptr != NULL) {
        if (fmt_ptr->conthere)
            fmt_start = fmt_ptr;
        if (vim_strchr ((char_u *) "AEWI", idx) != NULL) {
            qfl->qf_multiline = TRUE;
            qfl->qf_multiignore = FALSE;
        }
        else if (vim_strchr ((char_u *) "CZ", idx) != NULL) {
            if (!qfl->qf_multiignore) {
                qfline_T *qfprev = qfl->qf_last;
                if (qfprev == NULL)
                    return QF_FAIL;
                if (*fields->errmsg && !qfl->qf_multiignore) {
                    len = (int) STRLEN (qfprev->qf_text);
                    if ((ptr = alloc ((unsigned ) (len + STRLEN (fields->errmsg) + 2))) == NULL)
                        return QF_FAIL;
                    STRCPY (ptr, qfprev -> qf_text);
                    vim_free (qfprev -> qf_text);
                    qfprev->qf_text = ptr;
                    *(ptr += len) = '\n';
                    STRCPY (++ ptr, fields -> errmsg);
                }
                if (qfprev->qf_nr == -1)
                    qfprev->qf_nr = fields->enr;
                if (vim_isprintc (fields->type) && !qfprev->qf_type)
                    qfprev->qf_type = fields->type;
                if (!qfprev->qf_lnum)
                    qfprev->qf_lnum = fields->lnum;
                if (!qfprev->qf_col)
                    qfprev->qf_col = fields->col;
                qfprev->qf_viscol = fields->use_viscol;
                if (!qfprev->qf_fnum)
                    qfprev->qf_fnum = qf_get_fnum (qi, qf_idx, qfl->qf_directory, *fields->namebuf || qfl->qf_directory != NULL ? fields->namebuf : qfl->qf_currfile != NULL && fields->valid ? qfl->qf_currfile : 0);
            }
            if (idx == 'Z')
                qfl->qf_multiline = qfl->qf_multiignore = FALSE;
            line_breakcheck ();
            return QF_IGNORE_LINE;
        }
        else if (vim_strchr ((char_u *) "OPQ", idx) != NULL) {
            fields->valid = FALSE;
            if (*fields->namebuf == NUL || mch_getperm (fields->namebuf) >= 0) {
                if (*fields->namebuf && idx == 'P')
                    qfl->qf_currfile = qf_push_dir (fields->namebuf, &qfl->qf_file_stack, TRUE);
                else if (idx == 'Q')
                    qfl->qf_currfile = qf_pop_dir (&qfl->qf_file_stack);
                *fields->namebuf = NUL;
                if (tail && *tail) {
                    STRMOVE (IObuff, skipwhite (tail));
                    qfl->qf_multiscan = TRUE;
                    goto restofline;
                }
            }
        }
        if (fmt_ptr->flags == '-') {
            if (qfl->qf_multiline)
                qfl->qf_multiignore = TRUE;
            return QF_IGNORE_LINE;
        }
    }
    return QF_OK;
}

static char_u *qf_push_dir (char_u *dirbuf, struct dir_stack_T **stackptr, int is_file_stack) {
    struct dir_stack_T *ds_new;
    struct dir_stack_T *ds_ptr;
    ds_new = (struct dir_stack_T *) alloc ((unsigned ) sizeof (struct dir_stack_T));
    if (ds_new == NULL)
        return NULL;
    ds_new->next = *stackptr;
    *stackptr = ds_new;
    if (vim_isAbsName (dirbuf) || (*stackptr)->next == NULL || (*stackptr && is_file_stack))
        (*stackptr)->dirname = vim_strsave (dirbuf);
    else {
        ds_new = (*stackptr)->next;
        (*stackptr)->dirname = NULL;
        while (ds_new) {
            vim_free ((* stackptr) -> dirname);
            (*stackptr)->dirname = concat_fnames (ds_new->dirname, dirbuf, TRUE);
            if (mch_isdir ((*stackptr)->dirname) == TRUE)
                break;
            ds_new = ds_new->next;
        }
        while ((*stackptr)->next != ds_new) {
            ds_ptr = (*stackptr)->next;
            (*stackptr)->next = (*stackptr)->next->next;
            vim_free (ds_ptr -> dirname);
            vim_free (ds_ptr);
        }
        if (ds_new == NULL) {
            vim_free ((* stackptr) -> dirname);
            (*stackptr)->dirname = vim_strsave (dirbuf);
        }
    }
    if ((*stackptr)->dirname != NULL)
        return (*stackptr)->dirname;
    else {
        ds_ptr = *stackptr;
        *stackptr = (*stackptr)->next;
        vim_free (ds_ptr);
        return NULL;
    }
}

static char_u *qf_pop_dir (struct dir_stack_T **stackptr) {
    struct dir_stack_T *ds_ptr;
    if (*stackptr != NULL) {
        ds_ptr = *stackptr;
        *stackptr = (*stackptr)->next;
        vim_free (ds_ptr -> dirname);
        vim_free (ds_ptr);
    }
    return *stackptr ? (*stackptr)->dirname : NULL;
}

static void qf_update_buffer (qf_info_T *qi, qfline_T *old_last) {
    buf_T *buf;
    win_T *win;
    aco_save_T aco;
    buf = qf_find_buf (qi);
    if (buf != NULL) {
        linenr_T old_line_count = buf->b_ml.ml_line_count;
        if (old_last == NULL)
            aucmd_prepbuf (&aco, buf);
        qf_update_win_titlevar (qi);
        qf_fill_buffer (qi, buf, old_last);
        ++CHANGEDTICK (buf);
        if (old_last == NULL) {
            (void) qf_win_pos_update (qi, 0);
            aucmd_restbuf (& aco);
        }
        if ((win = qf_find_win (qi)) != NULL && old_line_count < win->w_botline)
            redraw_buf_later (buf, NOT_VALID);
    }
}

static buf_T *qf_find_buf (qf_info_T *qi) {
    tabpage_T *tp;
    win_T *win;
    FOR_ALL_TAB_WINDOWS (tp, win)
        if (is_qf_win (win, qi))
            return win->w_buffer;
    return NULL;
}

static int is_qf_win (win_T *win, qf_info_T *qi) {
    if (bt_quickfix (win->w_buffer))
        if ((qi == &ql_info && win->w_llist_ref == NULL) || (qi != &ql_info && win->w_llist_ref == qi))
            return TRUE;
    return FALSE;
}

static void qf_update_win_titlevar (qf_info_T *qi) {
    win_T *win;
    win_T *curwin_save;
    if ((win = qf_find_win (qi)) != NULL) {
        curwin_save = curwin;
        curwin = win;
        qf_set_title_var (qi);
        curwin = curwin_save;
    }
}

static win_T *qf_find_win (qf_info_T *qi) {
    win_T *win;
    FOR_ALL_WINDOWS (win)
        if (is_qf_win (win, qi))
            return win;
    return NULL;
}

static void qf_set_title_var (qf_info_T *qi) {
    if (qi->qf_lists[qi->qf_curlist].qf_title != NULL)
        set_internal_string_var ((char_u *) "w:quickfix_title", qi->qf_lists[qi->qf_curlist].qf_title);
}

static void qf_fill_buffer (qf_info_T *qi, buf_T *buf, qfline_T *old_last) {
    linenr_T lnum;
    qfline_T *qfp;
    buf_T *errbuf;
    int len;
    int old_KeyTyped = KeyTyped;
    if (old_last == NULL) {
        if (buf != curbuf) {
            internal_error ("qf_fill_buffer()");
            return;
        }
        while ((curbuf->b_ml.ml_flags & ML_EMPTY) == 0)
            (void) ml_delete ((linenr_T) 1, FALSE);
    }
    if (qi->qf_curlist < qi->qf_listcount) {
        if (old_last == NULL) {
            qfp = qi->qf_lists[qi->qf_curlist].qf_start;
            lnum = 0;
        }
        else {
            qfp = old_last->qf_next;
            lnum = buf->b_ml.ml_line_count;
        }
        while (lnum < qi->qf_lists[qi->qf_curlist].qf_count) {
            if (qfp->qf_fnum != 0 && (errbuf = buflist_findnr (qfp->qf_fnum)) != NULL && errbuf->b_fname != NULL) {
                if (qfp->qf_type == 1)
                    STRCPY (IObuff, gettail (errbuf->b_fname));
                else
                    STRCPY (IObuff, errbuf->b_fname);
                len = (int) STRLEN (IObuff);
            }
            else
                len = 0;
            IObuff[len++] = '|';
            if (qfp->qf_lnum > 0) {
                sprintf ((char *) IObuff + len, "%ld", qfp -> qf_lnum);
                len += (int) STRLEN (IObuff +len);
                if (qfp->qf_col > 0) {
                    sprintf ((char *) IObuff + len, " col %d", qfp -> qf_col);
                    len += (int) STRLEN (IObuff +len);
                }
                sprintf ((char *) IObuff + len, "%s", (char *) qf_types (qfp -> qf_type, qfp -> qf_nr));
                len += (int) STRLEN (IObuff +len);
            }
            else if (qfp->qf_pattern != NULL) {
                qf_fmt_text (qfp -> qf_pattern, IObuff + len, IOSIZE - len);
                len += (int) STRLEN (IObuff +len);
            }
            IObuff[len++] = '|';
            IObuff[len++] = ' ';
            qf_fmt_text (len > 3 ? skipwhite (qfp -> qf_text) : qfp -> qf_text, IObuff + len, IOSIZE - len);
            if (ml_append_buf (buf, lnum, IObuff, (colnr_T) STRLEN (IObuff) + 1, FALSE) == FAIL)
                break;
            ++lnum;
            qfp = qfp->qf_next;
            if (qfp == NULL)
                break;
        }
        if (old_last == NULL)
            (void) ml_delete (lnum +1, FALSE);
    }
    check_lnums (TRUE);
    if (old_last == NULL) {
        ++curbuf_lock;
        set_option_value ((char_u *) "ft", 0L, (char_u *) "qf", OPT_LOCAL);
        curbuf->b_p_ma = FALSE;
        keep_filetype = TRUE;
        apply_autocmds (EVENT_BUFREADPOST, (char_u *) "quickfix", NULL, FALSE, curbuf);
        apply_autocmds (EVENT_BUFWINENTER, (char_u *) "quickfix", NULL, FALSE, curbuf);
        keep_filetype = FALSE;
        --curbuf_lock;
        redraw_curbuf_later (NOT_VALID);
    }
    KeyTyped = old_KeyTyped;
}

static char_u *qf_types (int c, int nr) {
    static char_u buf [20];
    static char_u cc [3];
    char_u *p;
    if (c == 'W' || c == 'w')
        p = (char_u *) " warning";
    else if (c == 'I' || c == 'i')
        p = (char_u *) " info";
    else if (c == 'E' || c == 'e' || (c == 0 && nr > 0))
        p = (char_u *) " error";
    else if (c == 0 || c == 1)
        p = (char_u *) "";
    else {
        cc[0] = ' ';
        cc[1] = c;
        cc[2] = NUL;
        p = cc;
    }
    if (nr <= 0)
        return p;
    sprintf ((char *) buf, "%s %3d", (char *) p, nr);
    return buf;
}

static void qf_fmt_text (char_u *text, char_u *buf, int bufsize) {
    int i;
    char_u *p = text;
    for (i = 0; *p != NUL && i < bufsize - 1; ++i) {
        if (*p == '\n') {
            buf[i] = ' ';
            while (*++p != NUL)
                if (!VIM_ISWHITE (*p) && *p != '\n')
                    break;
        }
        else
            buf[i] = *p++;
    }
    buf[i] = NUL;
}

static int qf_win_pos_update (qf_info_T *qi, int old_qf_index) {
    win_T *win;
    int qf_index = qi->qf_lists[qi->qf_curlist].qf_index;
    win = qf_find_win (qi);
    if (win != NULL && qf_index <= win->w_buffer->b_ml.ml_line_count && old_qf_index != qf_index) {
        if (qf_index > old_qf_index) {
            win->w_redraw_top = old_qf_index;
            win->w_redraw_bot = qf_index;
        }
        else {
            win->w_redraw_top = qf_index;
            win->w_redraw_bot = old_qf_index;
        }
        qf_win_goto (win, qf_index);
    }
    return win != NULL;
}

static void qf_win_goto (win_T *win, linenr_T lnum) {
    win_T *old_curwin = curwin;
    curwin = win;
    curbuf = win->w_buffer;
    curwin->w_cursor.lnum = lnum;
    curwin->w_cursor.col = 0;
    curwin->w_cursor.coladd = 0;
    curwin->w_curswant = 0;
    update_topline ();
    redraw_later (VALID);
    curwin->w_redr_status = TRUE;
    curwin = old_curwin;
    curbuf = curwin->w_buffer;
}

static int qf_id2nr (qf_info_T *qi, int_u qfid) {
    int qf_idx;
    for (qf_idx = 0; qf_idx < qi->qf_listcount; qf_idx++)
        if (qi->qf_lists[qf_idx].qf_id == qfid)
            return qf_idx;
    return -1;
}

static int qf_winid (qf_info_T *qi) {
    win_T *win;
    if (qi == NULL)
        return 0;
    win = qf_find_win (qi);
    if (win != NULL)
        return win->w_id;
    return 0;
}

int set_errorlist (win_T *wp, list_T *list, int action, char_u *title, dict_T *what) {
    qf_info_T *qi = &ql_info;
    int retval = OK;
    if (wp != NULL) {
        qi = ll_get_or_alloc_list (wp);
        if (qi == NULL)
            return FAIL;
    }
    if (action == 'f') {
        qf_free_stack (wp, qi);
    }
    else if (what != NULL)
        retval = qf_set_properties (qi, what, action, title);
    else {
        retval = qf_add_entries (qi, qi->qf_curlist, list, title, action);
        if (retval == OK)
            qf_list_changed (qi, qi->qf_curlist);
    }
    return retval;
}

static qf_info_T *ll_get_or_alloc_list (win_T *wp) {
    if (IS_LL_WINDOW (wp))
        return wp->w_llist_ref;
    ll_free_all (& wp -> w_llist_ref);
    if (wp->w_llist == NULL)
        wp->w_llist = ll_new_list ();
    return wp->w_llist;
}

static void qf_free_stack (win_T *wp, qf_info_T *qi) {
    win_T *qfwin = qf_find_win (qi);
    win_T *llwin = NULL;
    win_T *orig_wp = wp;
    if (qfwin != NULL) {
        if (qi->qf_curlist < qi->qf_listcount)
            qf_free (qi, qi->qf_curlist);
        qf_update_buffer (qi, NULL);
    }
    if (wp != NULL && IS_LL_WINDOW (wp)) {
        llwin = find_win_with_ll (qi);
        if (llwin != NULL)
            wp = llwin;
    }
    qf_free_all (wp);
    if (wp == NULL) {
        qi->qf_curlist = 0;
        qi->qf_listcount = 0;
    }
    else if (IS_LL_WINDOW (orig_wp)) {
        qf_info_T *new_ll = ll_new_list ();
        ll_free_all (& orig_wp -> w_llist_ref);
        orig_wp->w_llist_ref = new_ll;
        if (llwin != NULL) {
            llwin->w_llist = new_ll;
            new_ll->qf_refcount++;
        }
    }
}

static win_T *find_win_with_ll (qf_info_T *qi) {
    win_T *wp = NULL;
    FOR_ALL_WINDOWS (wp)
        if ((wp->w_llist == qi) && !bt_quickfix (wp->w_buffer))
            return wp;
    return NULL;
}

static int qf_set_properties (qf_info_T *qi, dict_T *what, int action, char_u *title) {
    dictitem_T *di;
    int retval = FAIL;
    int qf_idx;
    int newlist = FALSE;
    char_u *errorformat = p_efm;
    if (action == ' ' || qi->qf_curlist == qi->qf_listcount)
        newlist = TRUE;
    qf_idx = qi->qf_curlist;
    if ((di = dict_find (what, (char_u *) "nr", -1)) != NULL) {
        if (di->di_tv.v_type == VAR_NUMBER) {
            if (di->di_tv.vval.v_number != 0)
                qf_idx = di->di_tv.vval.v_number - 1;
            if ((action == ' ' || action == 'a') && qf_idx == qi->qf_listcount) {
                newlist = TRUE;
                qf_idx = qi->qf_listcount - 1;
            }
            else if (qf_idx < 0 || qf_idx >= qi->qf_listcount)
                return FAIL;
            else if (action != ' ')
                newlist = FALSE;
        }
        else if (di->di_tv.v_type == VAR_STRING && di->di_tv.vval.v_string != NULL && STRCMP (di->di_tv.vval.v_string, "$") == 0) {
            if (qi->qf_listcount > 0)
                qf_idx = qi->qf_listcount - 1;
            else if (newlist)
                qf_idx = 0;
            else
                return FAIL;
        }
        else
            return FAIL;
    }
    if (!newlist && (di = dict_find (what, (char_u *) "id", -1)) != NULL) {
        if (di->di_tv.v_type == VAR_NUMBER) {
            qf_idx = qf_id2nr (qi, di->di_tv.vval.v_number);
            if (qf_idx == -1)
                return FAIL;
        }
        else
            return FAIL;
    }
    if (newlist) {
        qi->qf_curlist = qf_idx;
        qf_new_list (qi, title);
        qf_idx = qi->qf_curlist;
    }
    if ((di = dict_find (what, (char_u *) "title", -1)) != NULL) {
        if (di->di_tv.v_type == VAR_STRING) {
            vim_free (qi -> qf_lists [qf_idx].qf_title);
            qi->qf_lists[qf_idx].qf_title = get_dict_string (what, (char_u *) "title", TRUE);
            if (qf_idx == qi->qf_curlist)
                qf_update_win_titlevar (qi);
            retval = OK;
        }
    }
    if ((di = dict_find (what, (char_u *) "items", -1)) != NULL) {
        if (di->di_tv.v_type == VAR_LIST) {
            char_u *title_save = vim_strsave (qi->qf_lists[qf_idx].qf_title);
            retval = qf_add_entries (qi, qf_idx, di->di_tv.vval.v_list, title_save, action == ' ' ? 'a' : action);
            if (action == 'r') {
                vim_free (qi -> qf_lists [qf_idx].qf_title);
                qi->qf_lists[qf_idx].qf_title = vim_strsave (title_save);
            }
            vim_free (title_save);
        }
    }
    if ((di = dict_find (what, (char_u *) "efm", -1)) != NULL) {
        if (di->di_tv.v_type != VAR_STRING || di->di_tv.vval.v_string == NULL)
            return FAIL;
        errorformat = di->di_tv.vval.v_string;
    }
    if ((di = dict_find (what, (char_u *) "lines", -1)) != NULL) {
        if (di->di_tv.v_type == VAR_LIST && di->di_tv.vval.v_list != NULL) {
            if (action == 'r')
                qf_free_items (qi, qf_idx);
            if (qf_init_ext (qi, qf_idx, NULL, NULL, &di->di_tv, errorformat, FALSE, (linenr_T) 0, (linenr_T) 0, NULL, NULL) > 0)
                retval = OK;
        }
        else
            return FAIL;
    }
    if ((di = dict_find (what, (char_u *) "context", -1)) != NULL) {
        typval_T *ctx;
        free_tv (qi -> qf_lists [qf_idx].qf_ctx);
        ctx = alloc_tv ();
        if (ctx != NULL)
            copy_tv (&di->di_tv, ctx);
        qi->qf_lists[qf_idx].qf_ctx = ctx;
        retval = OK;
    }
    if (retval == OK)
        qf_list_changed (qi, qf_idx);
    return retval;
}

static int qf_add_entries (qf_info_T *qi, int qf_idx, list_T *list, char_u *title, int action) {
    listitem_T *li;
    dict_T *d;
    char_u *filename, *pattern, *text, *type;
    int bufnum;
    long  lnum;
    int col, nr;
    int vcol;
    qfline_T *old_last = NULL;
    int valid, status;
    int retval = OK;
    int did_bufnr_emsg = FALSE;
    if (action == ' ' || qf_idx == qi->qf_listcount) {
        qf_new_list (qi, title);
        qf_idx = qi->qf_curlist;
    }
    else if (action == 'a' && qi->qf_lists[qf_idx].qf_count > 0)
        old_last = qi->qf_lists[qf_idx].qf_last;
    else if (action == 'r') {
        qf_free_items (qi, qf_idx);
        qf_store_title (qi, qf_idx, title);
    }
    for (li = list->lv_first; li != NULL; li = li->li_next) {
        if (li->li_tv.v_type != VAR_DICT)
            continue;
        d = li->li_tv.vval.v_dict;
        if (d == NULL)
            continue;
        filename = get_dict_string (d, (char_u *) "filename", TRUE);
        bufnum = (int) get_dict_number (d, (char_u *) "bufnr");
        lnum = (int) get_dict_number (d, (char_u *) "lnum");
        col = (int) get_dict_number (d, (char_u *) "col");
        vcol = (int) get_dict_number (d, (char_u *) "vcol");
        nr = (int) get_dict_number (d, (char_u *) "nr");
        type = get_dict_string (d, (char_u *) "type", TRUE);
        pattern = get_dict_string (d, (char_u *) "pattern", TRUE);
        text = get_dict_string (d, (char_u *) "text", TRUE);
        if (text == NULL)
            text = vim_strsave ((char_u *) "");
        valid = TRUE;
        if ((filename == NULL && bufnum == 0) || (lnum == 0 && pattern == NULL))
            valid = FALSE;
        if (bufnum != 0 && (buflist_findnr (bufnum) == NULL)) {
            if (!did_bufnr_emsg) {
                did_bufnr_emsg = TRUE;
                EMSGN (_ ("E92: Buffer %ld not found"), bufnum);
            }
            valid = FALSE;
            bufnum = 0;
        }
        if ((dict_find (d, (char_u *) "valid", -1)) != NULL)
            valid = (int) get_dict_number (d, (char_u *) "valid");
        status = qf_add_entry (qi, qf_idx, NULL, filename, bufnum, text, lnum, col, vcol, pattern, nr, type == NULL ? NUL : *type, valid);
        vim_free (filename);
        vim_free (pattern);
        vim_free (text);
        vim_free (type);
        if (status == FAIL) {
            retval = FAIL;
            break;
        }
    }
    if (qi->qf_lists[qf_idx].qf_index == 0)
        qi->qf_lists[qf_idx].qf_nonevalid = TRUE;
    else
        qi->qf_lists[qf_idx].qf_nonevalid = FALSE;
    if (action != 'a') {
        qi->qf_lists[qf_idx].qf_ptr = qi->qf_lists[qf_idx].qf_start;
        if (qi->qf_lists[qf_idx].qf_count > 0)
            qi->qf_lists[qf_idx].qf_index = 1;
    }
    qf_update_buffer (qi, old_last);
    return retval;
}

static void qf_list_changed (qf_info_T *qi, int qf_idx) {
    qi->qf_lists[qf_idx].qf_changedtick++;
}

