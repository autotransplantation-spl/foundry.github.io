
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
struct source_cookie {
    FILE *fp;
    char_u *nextline;
    int finished;
    linenr_T breakpoint;
    char_u *fname;
    int dbg_tick;
    int level;
};
struct debuggy {
    int dbg_nr;
    int dbg_type;
    char_u *dbg_name;
    regprog_T *dbg_prog;
    linenr_T dbg_lnum;
    int dbg_forceit;
    typval_T *dbg_val;
    int dbg_level;
};
struct sn_prl_S {
    int snp_count;
    proftime_T sn_prl_total;
    proftime_T sn_prl_self;
};
struct scriptitem_S {
    char_u *sn_name;
    int sn_dev_valid;
    dev_t sn_dev;
    ino_t sn_ino;
    int sn_prof_on;
    int sn_pr_force;
    proftime_T sn_pr_child;
    int sn_pr_nest;
    int sn_pr_count;
    proftime_T sn_pr_total;
    proftime_T sn_pr_self;
    proftime_T sn_pr_start;
    proftime_T sn_pr_children;
    garray_T sn_prl_ga;
    proftime_T sn_prl_start;
    proftime_T sn_prl_children;
    proftime_T sn_prl_wait;
    int sn_prl_idx;
    int sn_prl_execed;
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
int debug_greedy = FALSE;
EXTERN char_u *p_go;
EXTERN int p_awa;
EXTERN int p_aw;
EXTERN int p_write;
garray_T prof_ga = {0, 0, sizeof (struct debuggy), 4, NULL};
garray_T dbg_breakp = {0, 0, sizeof (struct debuggy), 4, NULL};
EXTERN char_u e_interr [] INIT (= N_ ("Interrupted"));
EXTERN char_u e_dirnotf [] INIT (= N_ ("E919: Directory not found in '%s': \"%s\""));
EXTERN long  p_verbose;
EXTERN char_u *p_pp;
EXTERN char_u *p_rtp;
proftime_T prof_wait_time;
timer_T *first_timer = NULL;
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
EXTERN char_u *p_titlestring;
EXTERN int arrow_used;
EXTERN int mouse_row;
char_u *debug_skipped_name;
int debug_skipped;
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
char_u *debug_breakpoint_name = NULL;
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
EXTERN long  p_linespace;
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
proftime_T inchar_time;
char *pexpand_cmds [] = {"start", 
    #define PROFCMD_START	0
    "pause", 
    #define PROFCMD_PAUSE	1
    "continue", 
    #define PROFCMD_CONTINUE 2
    "func", 
    #define PROFCMD_FUNC	3
    "file", 
    #define PROFCMD_FILE	4
    NULL 
    #define PROFCMD_LAST	5

};
char_u *debug_newval = NULL;
char_u *debug_oldval = NULL;
garray_T script_items = {0, 0, sizeof (scriptitem_T), 4, NULL};
EXTERN proftime_T bevalexpr_due;
EXTERN char_u e_invexpr2 [] INIT (= N_ ("E15: Invalid expression: %s"));
EXTERN char_u *p_pexpr;
EXTERN char_u *p_bexpr;
int debug_expr = 0;
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
long  last_timer_id = 0;
EXTERN int autocmd_fname_full;
EXTERN char_u *autocmd_fname INIT (= NULL);
char_u *profile_fname = NULL;
EXTERN unsigned  swb_flags;
EXTERN pos_T where_paste_started;
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
linenr_T debug_breakpoint_lnum;
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

void profile_start (proftime_T *tm) {
    gettimeofday (tm, NULL);
}

void profile_sub (proftime_T *tm, proftime_T *tm2) {
    tm->tv_usec -= tm2->tv_usec;
    tm->tv_sec -= tm2->tv_sec;
    if (tm->tv_usec < 0) {
        tm->tv_usec += 1000000;
        --tm->tv_sec;
    }
}

char *profile_msg (proftime_T *tm) {
    static char buf [50];
    sprintf (buf, "%3ld.%06ld", (long) tm -> tv_sec, (long) tm -> tv_usec);
    return buf;
}

long  check_due_timer (void) {
    timer_T *timer;
    timer_T *timer_next;
    long  this_due;
    long  next_due = -1;
    proftime_T now;
    int did_one = FALSE;
    int need_update_screen = FALSE;
    long  current_id = last_timer_id;
    if (exiting || aborting ())
        return next_due;
    profile_start (& now);
    for (timer = first_timer; timer != NULL && !got_int; timer = timer_next) {
        timer_next = timer->tr_next;
        if (timer->tr_id == -1 || timer->tr_firing || timer->tr_paused)
            continue;
        this_due = proftime_time_left (&timer->tr_due, &now);
        if (this_due <= 1) {
            int save_timer_busy = timer_busy;
            int save_vgetc_busy = vgetc_busy;
            int save_did_emsg = did_emsg;
            int save_called_emsg = called_emsg;
            int save_must_redraw = must_redraw;
            int save_trylevel = trylevel;
            int save_did_throw = did_throw;
            int save_ex_pressedreturn = get_pressedreturn ();
            except_T *save_current_exception = current_exception;
            timer_busy = timer_busy > 0 || vgetc_busy > 0;
            vgetc_busy = 0;
            called_emsg = FALSE;
            did_emsg = FALSE;
            did_uncaught_emsg = FALSE;
            must_redraw = 0;
            trylevel = 0;
            did_throw = FALSE;
            current_exception = NULL;
            timer->tr_firing = TRUE;
            timer_callback (timer);
            timer->tr_firing = FALSE;
            timer_next = timer->tr_next;
            did_one = TRUE;
            timer_busy = save_timer_busy;
            vgetc_busy = save_vgetc_busy;
            if (did_uncaught_emsg)
                ++timer->tr_emsg_count;
            did_emsg = save_did_emsg;
            called_emsg = save_called_emsg;
            trylevel = save_trylevel;
            did_throw = save_did_throw;
            current_exception = save_current_exception;
            if (must_redraw != 0)
                need_update_screen = TRUE;
            must_redraw = must_redraw > save_must_redraw ? must_redraw : save_must_redraw;
            set_pressedreturn (save_ex_pressedreturn);
            if (timer->tr_repeat != 0 && timer->tr_id != -1 && timer->tr_emsg_count < 3) {
                profile_setlimit (timer -> tr_interval, & timer -> tr_due);
                this_due = proftime_time_left (&timer->tr_due, &now);
                if (this_due < 1)
                    this_due = 1;
                if (timer->tr_repeat > 0)
                    --timer->tr_repeat;
            }
            else {
                this_due = -1;
                remove_timer (timer);
                free_timer (timer);
            }
        }
        if (this_due > 0 && (next_due == -1 || next_due > this_due))
            next_due = this_due;
    }
    if (did_one)
        redraw_after_callback (need_update_screen);
    if (bevalexpr_due_set) {
        this_due = proftime_time_left (&bevalexpr_due, &now);
        if (this_due <= 1) {
            bevalexpr_due_set = FALSE;
            if (balloonEval == NULL) {
                balloonEval = (BalloonEval *) alloc (sizeof (BalloonEval));
                balloonEvalForTerm = TRUE;
            }
            if (balloonEval != NULL)
                general_beval_cb (balloonEval, 0);
        }
        else if (this_due > 0 && (next_due == -1 || next_due > this_due))
            next_due = this_due;
    }
    return current_id != last_timer_id ? 1 : next_due;
}

static long  proftime_time_left (proftime_T *due, proftime_T *now) {
    if (now->tv_sec > due->tv_sec)
        return 0;
    return (due->tv_sec - now->tv_sec) * 1000 + (due->tv_usec - now->tv_usec) / 1000;
}

static void timer_callback (timer_T *timer) {
    typval_T rettv;
    int dummy;
    typval_T argv [2];
    argv[0].v_type = VAR_NUMBER;
    argv[0].vval.v_number = (varnumber_T) timer->tr_id;
    argv[1].v_type = VAR_UNKNOWN;
    call_func (timer -> tr_callback, (int) STRLEN (timer -> tr_callback), & rettv, 1, argv, NULL, 0L, 0L, & dummy, TRUE, timer -> tr_partial, NULL);
    clear_tv (& rettv);
}

void script_prof_save (proftime_T *tm) {
    scriptitem_T *si;
    if (current_SID > 0 && current_SID <= script_items.ga_len) {
        si = &SCRIPT_ITEM (current_SID);
        if (si->sn_prof_on && si->sn_pr_nest++ == 0)
            profile_start (&si->sn_pr_child);
    }
    profile_get_wait (tm);
}

void profile_get_wait (proftime_T *tm) {
    *tm = prof_wait_time;
}

int source_runtime (char_u *name, int flags) {
    return source_in_path (p_rtp, name, flags);
}

int source_in_path (char_u *path, char_u *name, int flags) {
    return do_in_path_and_pp (path, name, flags, source_callback, NULL);
}

static int do_in_path_and_pp (char_u *path, char_u *name, int flags, void (*callback) (char_u *fname, void *ck), void *cookie) {
    int done = FAIL;
    char_u *s;
    int len;
    char *start_dir = "pack/*/start/*/%s";
    char *opt_dir = "pack/*/opt/*/%s";
    if ((flags & DIP_NORTP) == 0)
        done = do_in_path (path, name, flags, callback, cookie);
    if ((done == FAIL || (flags & DIP_ALL)) && (flags & DIP_START)) {
        len = (int) (STRLEN (start_dir) + STRLEN (name));
        s = alloc (len);
        if (s == NULL)
            return FAIL;
        vim_snprintf ((char *) s, len, start_dir, name);
        done = do_in_path (p_pp, s, flags, callback, cookie);
        vim_free (s);
    }
    if ((done == FAIL || (flags & DIP_ALL)) && (flags & DIP_OPT)) {
        len = (int) (STRLEN (opt_dir) + STRLEN (name));
        s = alloc (len);
        if (s == NULL)
            return FAIL;
        vim_snprintf ((char *) s, len, opt_dir, name);
        done = do_in_path (p_pp, s, flags, callback, cookie);
        vim_free (s);
    }
    return done;
}

int do_in_path (char_u *path, char_u *name, int flags, void (*callback) (char_u *fname, void *ck), void *cookie) {
    char_u *rtp;
    char_u *np;
    char_u *buf;
    char_u *rtp_copy;
    char_u *tail;
    int num_files;
    char_u **files;
    int i;
    int did_one = FALSE;
    rtp_copy = vim_strsave (path);
    buf = alloc (MAXPATHL);
    if (buf != NULL && rtp_copy != NULL) {
        if (p_verbose > 1 && name != NULL) {
            verbose_enter ();
            smsg ((char_u *) _ ("Searching for \"%s\" in \"%s\""), (char *) name, (char *) path);
            verbose_leave ();
        }
        rtp = rtp_copy;
        while (*rtp != NUL && ((flags & DIP_ALL) || !did_one)) {
            size_t buflen;
            copy_option_part (& rtp, buf, MAXPATHL, ",");
            buflen = STRLEN (buf);
            if (flags & (DIP_NOAFTER | DIP_AFTER)) {
                int is_after = buflen >= 5 && STRCMP (buf +buflen - 5, "after") == 0;
                if ((is_after && (flags & DIP_NOAFTER)) || (!is_after && (flags & DIP_AFTER)))
                    continue;
            }
            if (name == NULL) {
                (*callback) (buf, (void *) &cookie);
                if (!did_one)
                    did_one = (cookie == NULL);
            }
            else if (buflen + STRLEN (name) + 2 < MAXPATHL) {
                add_pathsep (buf);
                tail = buf + STRLEN (buf);
                np = name;
                while (*np != NUL && ((flags & DIP_ALL) || !did_one)) {
                    copy_option_part (& np, tail, (int) (MAXPATHL - (tail - buf)), "\t ");
                    if (p_verbose > 2) {
                        verbose_enter ();
                        smsg ((char_u *) _ ("Searching for \"%s\""), buf);
                        verbose_leave ();
                    }
                    if (gen_expand_wildcards (1, &buf, &num_files, &files, (flags & DIP_DIR) ? EW_DIR : EW_FILE) == OK) {
                        for (i = 0; i < num_files; ++i) {
                            (*callback) (files[i], cookie);
                            did_one = TRUE;
                            if (!(flags & DIP_ALL))
                                break;
                        }
                        FreeWild (num_files, files);
                    }
                }
            }
        }
    }
    vim_free (buf);
    vim_free (rtp_copy);
    if (!did_one && name != NULL) {
        char *basepath = path == p_rtp ? "runtimepath" : "packpath";
        if (flags & DIP_ERR)
            EMSG3 (_ (e_dirnotf), basepath, name);
        else if (p_verbose > 0) {
            verbose_enter ();
            smsg ((char_u *) _ ("not found in '%s': \"%s\""), basepath, name);
            verbose_leave ();
        }
    }
    return did_one ? OK : FAIL;
}

int set_ref_in_timer (int copyID) {
    int abort = FALSE;
    timer_T *timer;
    typval_T tv;
    for (timer = first_timer; timer != NULL; timer = timer->tr_next) {
        if (timer->tr_partial != NULL) {
            tv.v_type = VAR_PARTIAL;
            tv.vval.v_partial = timer->tr_partial;
        }
        else {
            tv.v_type = VAR_FUNC;
            tv.vval.v_string = timer->tr_callback;
        }
        abort = abort || set_ref_in_item (&tv, copyID, NULL, NULL);
    }
    return abort;
}

void profile_dump (void) {
    FILE *fd;
    if (profile_fname != NULL) {
        fd = mch_fopen ((char *) profile_fname, "w");
        if (fd == NULL)
            EMSG2 (_ (e_notopen), profile_fname);
        else {
            script_dump_profile (fd);
            func_dump_profile (fd);
            fclose (fd);
        }
    }
}

static void script_dump_profile (FILE *fd) {
    int id;
    scriptitem_T *si;
    int i;
    FILE *sfd;
    sn_prl_T *pp;
    for (id = 1; id <= script_items.ga_len; ++id) {
        si = &SCRIPT_ITEM (id);
        if (si->sn_prof_on) {
            fprintf (fd, "SCRIPT  %s\n", si -> sn_name);
            if (si->sn_pr_count == 1)
                fprintf (fd, "Sourced 1 time\n");
            else
                fprintf (fd, "Sourced %d times\n", si->sn_pr_count);
            fprintf (fd, "Total time: %s\n", profile_msg (& si -> sn_pr_total));
            fprintf (fd, " Self time: %s\n", profile_msg (& si -> sn_pr_self));
            fprintf (fd, "\n");
            fprintf (fd, "count  total (s)   self (s)\n");
            sfd = mch_fopen ((char *) si->sn_name, "r");
            if (sfd == NULL)
                fprintf (fd, "Cannot open file!\n");
            else {
                for (i = 0;; ++i) {
                    if (vim_fgets (IObuff, IOSIZE, sfd))
                        break;
                    if (IObuff[IOSIZE - 2] != NUL && IObuff[IOSIZE - 2] != NL) {
                        int n = IOSIZE - 2;
                        IObuff[n] = NL;
                        IObuff[n + 1] = NUL;
                    }
                    if (i < si->sn_prl_ga.ga_len && (pp = &PRL_ITEM (si, i))->snp_count > 0) {
                        fprintf (fd, "%5d ", pp -> snp_count);
                        if (profile_equal (&pp->sn_prl_total, &pp->sn_prl_self))
                            fprintf (fd, "           ");
                        else
                            fprintf (fd, "%s ", profile_msg (&pp->sn_prl_total));
                        fprintf (fd, "%s ", profile_msg (& pp -> sn_prl_self));
                    }
                    else
                        fprintf (fd, "                            ");
                    fprintf (fd, "%s", IObuff);
                }
                fclose (sfd);
            }
            fprintf (fd, "\n");
        }
    }
}

int profile_equal (proftime_T *tm1, proftime_T *tm2) {
    return (tm1->tv_usec == tm2->tv_usec && tm1->tv_sec == tm2->tv_sec);
}

int profile_cmp (const proftime_T *tm1, const proftime_T *tm2) {
    if (tm1->tv_sec == tm2->tv_sec)
        return tm2->tv_usec - tm1->tv_usec;
    return tm2->tv_sec - tm1->tv_sec;
}

void prof_inchar_enter (void) {
    profile_start (& inchar_time);
}

void prof_inchar_exit (void) {
    profile_end (& inchar_time);
    profile_add (& prof_wait_time, & inchar_time);
}

void profile_end (proftime_T *tm) {
    proftime_T now;
    gettimeofday (& now, NULL);
    tm->tv_usec = now.tv_usec - tm->tv_usec;
    tm->tv_sec = now.tv_sec - tm->tv_sec;
    if (tm->tv_usec < 0) {
        tm->tv_usec += 1000000;
        --tm->tv_sec;
    }
}

void profile_add (proftime_T *tm, proftime_T *tm2) {
    tm->tv_usec += tm2->tv_usec;
    tm->tv_sec += tm2->tv_sec;
    if (tm->tv_usec >= 1000000) {
        tm->tv_usec -= 1000000;
        ++tm->tv_sec;
    }
}

int do_source (char_u *fname, int check_other, int is_vimrc) {
    struct source_cookie cookie;
    char_u *save_sourcing_name;
    linenr_T save_sourcing_lnum;
    char_u *p;
    char_u *fname_exp;
    char_u *firstline = NULL;
    int retval = FAIL;
    scid_T save_current_SID;
    static scid_T last_current_SID = 0;
    void *save_funccalp;
    int save_debug_break_level = debug_break_level;
    scriptitem_T *si = NULL;
    stat_T st;
    int stat_ok;
    struct timeval tv_rel;
    struct timeval tv_start;
    proftime_T wait_start;
    p = expand_env_save (fname);
    if (p == NULL)
        return retval;
    fname_exp = fix_fname (p);
    vim_free (p);
    if (fname_exp == NULL)
        return retval;
    if (mch_isdir (fname_exp)) {
        smsg ((char_u *) _ ("Cannot source a directory: \"%s\""), fname);
        goto theend;
    }
    if (has_autocmd (EVENT_SOURCECMD, fname_exp, NULL) && apply_autocmds (EVENT_SOURCECMD, fname_exp, fname_exp, FALSE, curbuf)) {
        retval = aborting () ? FAIL : OK;
        goto theend;
    }
    apply_autocmds (EVENT_SOURCEPRE, fname_exp, fname_exp, FALSE, curbuf);
    cookie.fp = mch_fopen ((char *) fname_exp, READBIN);
    if (cookie.fp == NULL && check_other) {
        p = gettail (fname_exp);
        if ((*p == '.' || *p == '_') && (STRICMP (p +1, "vimrc") == 0 || STRICMP (p +1, "gvimrc") == 0 || STRICMP (p +1, "exrc") == 0)) {
            if (*p == '_')
                *p = '.';
            else
                *p = '_';
            cookie.fp = mch_fopen ((char *) fname_exp, READBIN);
        }
    }
    if (cookie.fp == NULL) {
        if (p_verbose > 0) {
            verbose_enter ();
            if (sourcing_name == NULL)
                smsg ((char_u *) _ ("could not source \"%s\""), fname);
            else
                smsg ((char_u *) _ ("line %ld: could not source \"%s\""), sourcing_lnum, fname);
            verbose_leave ();
        }
        goto theend;
    }
    if (p_verbose > 1) {
        verbose_enter ();
        if (sourcing_name == NULL)
            smsg ((char_u *) _ ("sourcing \"%s\""), fname);
        else
            smsg ((char_u *) _ ("line %ld: sourcing \"%s\""), sourcing_lnum, fname);
        verbose_leave ();
    }
    if (is_vimrc == DOSO_VIMRC)
        vimrc_found (fname_exp, (char_u *) "MYVIMRC");
    else if (is_vimrc == DOSO_GVIMRC)
        vimrc_found (fname_exp, (char_u *) "MYGVIMRC");
    cookie.nextline = NULL;
    cookie.finished = FALSE;
    cookie.breakpoint = dbg_find_breakpoint (TRUE, fname_exp, (linenr_T) 0);
    cookie.fname = fname_exp;
    cookie.dbg_tick = debug_tick;
    cookie.level = ex_nesting_level;
    save_sourcing_name = sourcing_name;
    sourcing_name = fname_exp;
    save_sourcing_lnum = sourcing_lnum;
    sourcing_lnum = 0;
    if (time_fd != NULL)
        time_push (&tv_rel, &tv_start);
    if (do_profiling == PROF_YES)
        prof_child_enter (&wait_start);
    save_funccalp = save_funccal ();
    save_current_SID = current_SID;
    stat_ok = (mch_stat ((char *) fname_exp, &st) >= 0);
    for (current_SID = script_items.ga_len; current_SID > 0; --current_SID) {
        si = &SCRIPT_ITEM (current_SID);
        if (si->sn_name != NULL && (((stat_ok && si->sn_dev_valid) && (si->sn_dev == st.st_dev && si->sn_ino == st.st_ino)) || fnamecmp (si->sn_name, fname_exp) == 0))
            break;
    }
    if (current_SID == 0) {
        current_SID = ++last_current_SID;
        if (ga_grow (&script_items, (int) (current_SID - script_items.ga_len)) == FAIL)
            goto almosttheend;
        while (script_items.ga_len < current_SID) {
            ++script_items.ga_len;
            SCRIPT_ITEM (script_items.ga_len).sn_name = NULL;
            SCRIPT_ITEM (script_items.ga_len).sn_prof_on = FALSE;
        }
        si = &SCRIPT_ITEM (current_SID);
        si->sn_name = fname_exp;
        fname_exp = NULL;
        if (stat_ok) {
            si->sn_dev_valid = TRUE;
            si->sn_dev = st.st_dev;
            si->sn_ino = st.st_ino;
        }
        else
            si->sn_dev_valid = FALSE;
        new_script_vars (current_SID);
    }
    if (do_profiling == PROF_YES) {
        int forceit;
        if (!si->sn_prof_on && has_profiling (TRUE, si->sn_name, &forceit)) {
            script_do_profile (si);
            si->sn_pr_force = forceit;
        }
        if (si->sn_prof_on) {
            ++si->sn_pr_count;
            profile_start (& si -> sn_pr_start);
            profile_zero (& si -> sn_pr_children);
        }
    }
    do_cmdline (firstline, getsourceline, (void *) & cookie, DOCMD_VERBOSE | DOCMD_NOWAIT | DOCMD_REPEAT);
    retval = OK;
    if (do_profiling == PROF_YES) {
        si = &SCRIPT_ITEM (current_SID);
        if (si->sn_prof_on) {
            profile_end (& si -> sn_pr_start);
            profile_sub_wait (& wait_start, & si -> sn_pr_start);
            profile_add (& si -> sn_pr_total, & si -> sn_pr_start);
            profile_self (& si -> sn_pr_self, & si -> sn_pr_start, & si -> sn_pr_children);
        }
    }
    if (got_int)
        EMSG (_ (e_interr));
    sourcing_name = save_sourcing_name;
    sourcing_lnum = save_sourcing_lnum;
    if (p_verbose > 1) {
        verbose_enter ();
        smsg ((char_u *) _ ("finished sourcing %s"), fname);
        if (sourcing_name != NULL)
            smsg ((char_u *) _ ("continuing in %s"), sourcing_name);
        verbose_leave ();
    }
    if (time_fd != NULL) {
        vim_snprintf ((char *) IObuff, IOSIZE, "sourcing %s", fname);
        time_msg ((char *) IObuff, & tv_start);
        time_pop (& tv_rel);
    }
    if (save_debug_break_level > ex_nesting_level && debug_break_level == ex_nesting_level)
        ++debug_break_level;
almosttheend :
    current_SID = save_current_SID;
    restore_funccal (save_funccalp);
    if (do_profiling == PROF_YES)
        prof_child_exit (&wait_start);
    fclose (cookie.fp);
    vim_free (cookie.nextline);
    vim_free (firstline);
theend :
    vim_free (fname_exp);
    return retval;
}

int do_in_runtimepath (char_u *name, int flags, void (*callback) (char_u *fname, void *ck), void *cookie) {
    return do_in_path_and_pp (p_rtp, name, flags, callback, cookie);
}

linenr_T dbg_find_breakpoint (int file, char_u *fname, linenr_T after) {
    return debuggy_find (file, fname, after, &dbg_breakp, NULL);
}

static linenr_T debuggy_find (int file, char_u *fname, linenr_T after, garray_T *gap, int *fp) {
    struct debuggy *bp;
    int i;
    linenr_T lnum = 0;
    char_u *name = fname;
    int prev_got_int;
    if (gap->ga_len == 0)
        return (linenr_T) 0;
    if (!file && fname[0] == K_SPECIAL) {
        name = alloc ((unsigned ) STRLEN (fname) + 3);
        if (name == NULL)
            name = fname;
        else {
            STRCPY (name, "<SNR>");
            STRCPY (name + 5, fname + 3);
        }
    }
    for (i = 0; i < gap->ga_len; ++i) {
        bp = &DEBUGGY (gap, i);
        if (((bp->dbg_type == DBG_FILE) == file && bp->dbg_type != DBG_EXPR && (gap == &prof_ga || (bp->dbg_lnum > after && (lnum == 0 || bp->dbg_lnum < lnum))))) {
            prev_got_int = got_int;
            got_int = FALSE;
            if (vim_regexec_prog (&bp->dbg_prog, FALSE, name, (colnr_T) 0)) {
                lnum = bp->dbg_lnum;
                if (fp != NULL)
                    *fp = bp->dbg_forceit;
            }
            got_int |= prev_got_int;
        }
        else if (bp->dbg_type == DBG_EXPR) {
            typval_T *tv;
            int line = FALSE;
            prev_got_int = got_int;
            got_int = FALSE;
            tv = eval_expr (bp->dbg_name, NULL);
            if (tv != NULL) {
                if (bp->dbg_val == NULL) {
                    debug_oldval = typval_tostring (NULL);
                    bp->dbg_val = tv;
                    debug_newval = typval_tostring (bp->dbg_val);
                    line = TRUE;
                }
                else {
                    if (typval_compare (tv, bp->dbg_val, TYPE_EQUAL, TRUE, FALSE) == OK && tv->vval.v_number == FALSE) {
                        typval_T *v;
                        line = TRUE;
                        debug_oldval = typval_tostring (bp->dbg_val);
                        v = eval_expr (bp->dbg_name, NULL);
                        debug_newval = typval_tostring (v);
                        free_tv (bp -> dbg_val);
                        bp->dbg_val = v;
                    }
                    free_tv (tv);
                }
            }
            else if (bp->dbg_val != NULL) {
                debug_oldval = typval_tostring (bp->dbg_val);
                debug_newval = typval_tostring (NULL);
                free_tv (bp -> dbg_val);
                bp->dbg_val = NULL;
                line = TRUE;
            }
            if (line) {
                lnum = after > 0 ? after : 1;
                break;
            }
            got_int |= prev_got_int;
        }
    }
    if (name != fname)
        vim_free (name);
    return lnum;
}

int has_profiling (int file, char_u *fname, int *fp) {
    return (debuggy_find (file, fname, (linenr_T) 0, &prof_ga, fp) != (linenr_T) 0);
}

static void script_do_profile (scriptitem_T *si) {
    si->sn_pr_count = 0;
    profile_zero (& si -> sn_pr_total);
    profile_zero (& si -> sn_pr_self);
    ga_init2 (& si -> sn_prl_ga, sizeof (sn_prl_T), 100);
    si->sn_prl_idx = -1;
    si->sn_prof_on = TRUE;
    si->sn_pr_nest = 0;
}

void profile_zero (proftime_T *tm) {
    tm->tv_usec = 0;
    tm->tv_sec = 0;
}

char_u *getsourceline (int c, void *cookie, int indent) {
    struct source_cookie *sp = (struct source_cookie *) cookie;
    char_u *line;
    char_u *p;
    if (sp->dbg_tick < debug_tick) {
        sp->breakpoint = dbg_find_breakpoint (TRUE, sp->fname, sourcing_lnum);
        sp->dbg_tick = debug_tick;
    }
    if (do_profiling == PROF_YES)
        script_line_end ();
    if (sp->finished)
        line = NULL;
    else if (sp->nextline == NULL)
        line = get_one_sourceline (sp);
    else {
        line = sp->nextline;
        sp->nextline = NULL;
        ++sourcing_lnum;
    }
    if (line != NULL && do_profiling == PROF_YES)
        script_line_start ();
    if (line != NULL && (vim_strchr (p_cpo, CPO_CONCAT) == NULL)) {
        --sourcing_lnum;
        sp->nextline = get_one_sourceline (sp);
        if (sp->nextline != NULL && *(p = skipwhite (sp->nextline)) == '\\') {
            garray_T ga;
            ga_init2 (& ga, (int) sizeof (char_u), 400);
            ga_concat (& ga, line);
            ga_concat (& ga, p + 1);
            for (;;) {
                vim_free (sp -> nextline);
                sp->nextline = get_one_sourceline (sp);
                if (sp->nextline == NULL)
                    break;
                p = skipwhite (sp->nextline);
                if (*p != '\\')
                    break;
                if (ga.ga_len > 400) {
                    if (ga.ga_len > 8000)
                        ga.ga_growsize = 8000;
                    else
                        ga.ga_growsize = ga.ga_len;
                }
                ga_concat (& ga, p + 1);
            }
            ga_append (& ga, NUL);
            vim_free (line);
            line = ga.ga_data;
        }
    }
    if (sp->breakpoint != 0 && sp->breakpoint <= sourcing_lnum) {
        dbg_breakpoint (sp -> fname, sourcing_lnum);
        sp->breakpoint = dbg_find_breakpoint (TRUE, sp->fname, sourcing_lnum);
        sp->dbg_tick = debug_tick;
    }
    return line;
}

void script_line_end (void) {
    scriptitem_T *si;
    sn_prl_T *pp;
    if (current_SID <= 0 || current_SID > script_items.ga_len)
        return;
    si = &SCRIPT_ITEM (current_SID);
    if (si->sn_prof_on && si->sn_prl_idx >= 0 && si->sn_prl_idx < si->sn_prl_ga.ga_len) {
        if (si->sn_prl_execed) {
            pp = &PRL_ITEM (si, si->sn_prl_idx);
            ++pp->snp_count;
            profile_end (& si -> sn_prl_start);
            profile_sub_wait (& si -> sn_prl_wait, & si -> sn_prl_start);
            profile_add (& pp -> sn_prl_total, & si -> sn_prl_start);
            profile_self (& pp -> sn_prl_self, & si -> sn_prl_start, & si -> sn_prl_children);
        }
        si->sn_prl_idx = -1;
    }
}

void profile_sub_wait (proftime_T *tm, proftime_T *tma) {
    proftime_T tm3 = prof_wait_time;
    profile_sub (& tm3, tm);
    profile_sub (tma, & tm3);
}

void profile_self (proftime_T *self, proftime_T *total, proftime_T *children) {
    if (total->tv_sec < children->tv_sec || (total->tv_sec == children->tv_sec && total->tv_usec <= children->tv_usec))
        return;
    profile_add (self, total);
    profile_sub (self, children);
}

static char_u *get_one_sourceline (struct source_cookie *sp) {
    garray_T ga;
    int len;
    int c;
    char_u *buf;
    int have_read = FALSE;
    ga_init2 (& ga, 1, 250);
    sourcing_lnum++;
    for (;;) {
        if (ga_grow (&ga, 120) == FAIL)
            break;
        buf = (char_u *) ga.ga_data;
        if (fgets ((char *) buf + ga.ga_len, ga.ga_maxlen - ga.ga_len, sp->fp) == NULL)
            break;
        len = ga.ga_len + (int) STRLEN (buf +ga.ga_len);
        have_read = TRUE;
        ga.ga_len = len;
        if (ga.ga_maxlen - ga.ga_len == 1 && buf[len - 1] != '\n')
            continue;
        if (len >= 1 && buf[len - 1] == '\n') {
            for (c = len - 2; c >= 0 && buf[c] == Ctrl_V; c--)
                ;
            if ((len & 1) != (c & 1)) {
                sourcing_lnum++;
                continue;
            }
            buf[len - 1] = NUL;
        }
        line_breakcheck ();
        break;
    }
    if (have_read)
        return (char_u *) ga.ga_data;
    vim_free (ga.ga_data);
    return NULL;
}

void script_line_start (void) {
    scriptitem_T *si;
    sn_prl_T *pp;
    if (current_SID <= 0 || current_SID > script_items.ga_len)
        return;
    si = &SCRIPT_ITEM (current_SID);
    if (si->sn_prof_on && sourcing_lnum >= 1) {
        (void) ga_grow (&si->sn_prl_ga, (int) (sourcing_lnum - si->sn_prl_ga.ga_len));
        si->sn_prl_idx = sourcing_lnum - 1;
        while (si->sn_prl_ga.ga_len <= si->sn_prl_idx && si->sn_prl_ga.ga_len < si->sn_prl_ga.ga_maxlen) {
            pp = &PRL_ITEM (si, si->sn_prl_ga.ga_len);
            pp->snp_count = 0;
            profile_zero (& pp -> sn_prl_total);
            profile_zero (& pp -> sn_prl_self);
            ++si->sn_prl_ga.ga_len;
        }
        si->sn_prl_execed = FALSE;
        profile_start (& si -> sn_prl_start);
        profile_zero (& si -> sn_prl_children);
        profile_get_wait (& si -> sn_prl_wait);
    }
}

void dbg_breakpoint (char_u *name, linenr_T lnum) {
    debug_breakpoint_name = name;
    debug_breakpoint_lnum = lnum;
}

void script_prof_restore (proftime_T *tm) {
    scriptitem_T *si;
    if (current_SID > 0 && current_SID <= script_items.ga_len) {
        si = &SCRIPT_ITEM (current_SID);
        if (si->sn_prof_on && --si->sn_pr_nest == 0) {
            profile_end (& si -> sn_pr_child);
            profile_sub_wait (tm, & si -> sn_pr_child);
            profile_add (& si -> sn_pr_children, & si -> sn_pr_child);
            profile_add (& si -> sn_prl_children, & si -> sn_pr_child);
        }
    }
}

int check_changed (buf_T *buf, int flags) {
    int forceit = (flags & CCGD_FORCEIT);
    bufref_T bufref;
    set_bufref (& bufref, buf);
    if (!forceit && bufIsChanged (buf) && ((flags & CCGD_MULTWIN) || buf->b_nwindows <= 1) && (!(flags & CCGD_AW) || autowrite (buf, forceit) == FAIL)) {
        if ((p_confirm || cmdmod.confirm) && p_write) {
            buf_T *buf2;
            int count = 0;
            if (flags & CCGD_ALLBUF)
                FOR_ALL_BUFFERS (buf2)
                    if (bufIsChanged (buf2) && (buf2->b_ffname != NULL))
                        ++count;
            if (!bufref_valid (&bufref))
                return FALSE;
            dialog_changed (buf, count > 1);
            if (!bufref_valid (&bufref))
                return FALSE;
            return bufIsChanged (buf);
        }
        if (flags & CCGD_EXCMD)
            no_write_message ();
        else
            no_write_message_nobang ();
        return TRUE;
    }
    return FALSE;
}

int autowrite (buf_T *buf, int forceit) {
    int r;
    bufref_T bufref;
    if (!(p_aw || p_awa) || !p_write || bt_dontwrite (buf) || (!forceit && buf->b_p_ro) || buf->b_ffname == NULL)
        return FAIL;
    set_bufref (& bufref, buf);
    r = buf_write_all (buf, forceit);
    if (bufref_valid (&bufref) && bufIsChanged (buf))
        r = FAIL;
    return r;
}

int buf_write_all (buf_T *buf, int forceit) {
    int retval;
    buf_T *old_curbuf = curbuf;
    retval = (buf_write (buf, buf->b_ffname, buf->b_fname, (linenr_T) 1, buf->b_ml.ml_line_count, NULL, FALSE, forceit, TRUE, FALSE));
    if (curbuf != old_curbuf) {
        msg_source (HL_ATTR (HLF_W));
        MSG (_ ("Warning: Entered other buffer unexpectedly (check autocommands)"));
    }
    return retval;
}

void check_arg_idx (win_T *win) {
    if (WARGCOUNT (win) > 1 && !editing_arg_idx (win)) {
        win->w_arg_idx_invalid = TRUE;
        if (win->w_arg_idx != WARGCOUNT (win) - 1 && arg_had_last == FALSE && ALIST (win) == &global_alist && GARGCOUNT > 0 && win->w_arg_idx < GARGCOUNT && (win->w_buffer->b_fnum == GARGLIST[GARGCOUNT - 1].ae_fnum || (win->w_buffer->b_ffname != NULL && (fullpathcmp (alist_name (&GARGLIST[GARGCOUNT - 1]), win->w_buffer->b_ffname, TRUE) & FPC_SAME))))
            arg_had_last = TRUE;
    }
    else {
        win->w_arg_idx_invalid = FALSE;
        if (win->w_arg_idx == WARGCOUNT (win) - 1 && win->w_alist == &global_alist)
            arg_had_last = TRUE;
    }
}

static int editing_arg_idx (win_T *win) {
    return !(win->w_arg_idx >= WARGCOUNT (win) || (win->w_buffer->b_fnum != WARGLIST (win)[win->w_arg_idx].ae_fnum && (win->w_buffer->b_ffname == NULL || !(fullpathcmp (alist_name (&WARGLIST (win)[win->w_arg_idx]), win->w_buffer->b_ffname, TRUE) & FPC_SAME))));
}

char_u *get_scriptname (scid_T id) {
    if (id == SID_MODELINE)
        return (char_u *) _ ("modeline");
    if (id == SID_CMDARG)
        return (char_u *) _ ("--cmd argument");
    if (id == SID_CARG)
        return (char_u *) _ ("-c argument");
    if (id == SID_ENV)
        return (char_u *) _ ("environment variable");
    if (id == SID_ERROR)
        return (char_u *) _ ("error handler");
    return SCRIPT_ITEM (id).sn_name;
}

void profile_setlimit (long  msec, proftime_T *tm) {
    if (msec <= 0)
        profile_zero (tm);
    else {
        long  usec;
        gettimeofday (tm, NULL);
        usec = (long ) tm->tv_usec + (long ) msec * 1000;
        tm->tv_usec = usec % 1000000L;
        tm->tv_sec += usec / 1000000L;
    }
}

int profile_passed_limit (proftime_T *tm) {
    proftime_T now;
    if (tm->tv_sec == 0)
        return FALSE;
    gettimeofday (& now, NULL);
    return (now.tv_sec > tm->tv_sec || (now.tv_sec == tm->tv_sec && now.tv_usec > tm->tv_usec));
}

void dialog_changed (buf_T *buf, int checkall) {
    char_u buff [DIALOG_MSG_SIZE];
    int ret;
    buf_T *buf2;
    exarg_T ea;
    if (gui.in_use && vim_strchr (p_go, GO_CONDIALOG) == NULL) {
        if (checkall)
            ret = vim_dialog_save_all_changes (buf);
        else
            ret = vim_dialog_save_changes (buf);
    }
    else {
        dialog_msg (buff, _ ("Save changes to \"%s\"?"), buf -> b_fname);
        if (checkall)
            ret = vim_dialog_yesnoallcancel (VIM_QUESTION, NULL, buff, 1);
        else
            ret = vim_dialog_yesnocancel (VIM_QUESTION, NULL, buff, 1);
    }
    ea.append = ea.forceit = FALSE;
    if (ret == VIM_YES) {
        if (buf->b_fname != NULL && check_overwrite (&ea, buf, buf->b_fname, buf->b_ffname, FALSE) == OK)
            (void) buf_write_all (buf, FALSE);
    }
    else if (ret == VIM_NO) {
        unchanged (buf, TRUE);
    }
    else if (ret == VIM_ALL) {
        FOR_ALL_BUFFERS (buf2) {
            if (bufIsChanged (buf2) && (buf2->b_ffname != NULL) && !buf2->b_p_ro) {
                bufref_T bufref;
                set_bufref (& bufref, buf2);
                if (buf2->b_fname != NULL && check_overwrite (&ea, buf2, buf2->b_fname, buf2->b_ffname, FALSE) == OK)
                    (void) buf_write_all (buf2, FALSE);
                if (!bufref_valid (&bufref))
                    buf2 = firstbuf;
            }
        }
    }
    else if (ret == VIM_DISCARDALL) {
        FOR_ALL_BUFFERS (buf2)
            unchanged (buf2, TRUE);
    }
}

int vim_dialog_save_all_changes (buf)
    buf_T *buf;
{
    char_u buff [IOSIZE];
    dialog_msg (buff, _ ("There are several documents with unsaved changes. " "Do you want to save the changes you made in the " "document \"%s\"?"), buf -> b_fname);
    switch (do_dialog (VIM_QUESTION, buff, (char_u *) _ ("Your changes will be lost if you don't save " "them."), (char_u *) _ ("&Save\n&Don't Save\nS&ave All\nD&iscard All\n" "&Cancel"), 1, NULL, FALSE)) {
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

int vim_dialog_save_changes (buf)
    buf_T *buf;
{
    char_u buff [IOSIZE];
    dialog_msg (buff, _ ("Do you want to save the changes you made in the " "document \"%s\"?"), buf -> b_fname);
    switch (do_dialog (VIM_QUESTION, buff, (char_u *) _ ("Your changes will be lost if you don't save " "them."), (buf->b_fname != NULL) ? (char_u *) _ ("&Save\n&Cancel\n&Don't Save") : (char_u *) _ ("&Save...\n&Cancel\n&Don't Save"), 1, NULL, FALSE)) {
    case 1 :
        return VIM_YES;
    case 3 :
        return VIM_NO;
    }
    return VIM_CANCEL;
}

void do_argfile (exarg_T *eap, int argn) {
    int other;
    char_u *p;
    int old_arg_idx = curwin->w_arg_idx;
    if (argn < 0 || argn >= ARGCOUNT) {
        if (ARGCOUNT <= 1)
            EMSG (_ ("E163: There is only one file to edit"));
        else if (argn < 0)
            EMSG (_ ("E164: Cannot go before first file"));
        else
            EMSG (_ ("E165: Cannot go beyond last file"));
    }
    else {
        setpcmark ();
        need_mouse_correct = TRUE;
        if (*eap->cmd == 's' || cmdmod.tab != 0) {
            if (win_split (0, 0) == FAIL)
                return;
            RESET_BINDING (curwin);
        }
        else {
            other = TRUE;
            if (buf_hide (curbuf)) {
                p = fix_fname (alist_name (&ARGLIST[argn]));
                other = otherfile (p);
                vim_free (p);
            }
            if ((!buf_hide (curbuf) || !other) && check_changed (curbuf, CCGD_AW | (other ? 0 : CCGD_MULTWIN) | (eap->forceit ? CCGD_FORCEIT : 0) | CCGD_EXCMD))
                return;
        }
        curwin->w_arg_idx = argn;
        if (argn == ARGCOUNT - 1 && curwin->w_alist == &global_alist)
            arg_had_last = TRUE;
        if (do_ecmd (0, alist_name (&ARGLIST[curwin->w_arg_idx]), NULL, eap, ECMD_LAST, (buf_hide (curwin->w_buffer) ? ECMD_HIDE : 0) + (eap->forceit ? ECMD_FORCEIT : 0), curwin) == FAIL)
            curwin->w_arg_idx = old_arg_idx;
        else if (eap->cmdidx != CMD_argdo)
            setmark ('\'');
    }
}

int check_fname (void) {
    if (curbuf->b_ffname == NULL) {
        EMSG (_ (e_noname));
        return FAIL;
    }
    return OK;
}

char_u *get_profile_name (expand_T *xp, int idx) {
    switch (pexpand_what) {
    case PEXP_SUBCMD :
        return (char_u *) pexpand_cmds[idx];
    default :
        return NULL;
    }
}

void set_context_in_profile_cmd (expand_T *xp, char_u *arg) {
    char_u *end_subcmd;
    xp->xp_context = EXPAND_PROFILE;
    pexpand_what = PEXP_SUBCMD;
    xp->xp_pattern = arg;
    end_subcmd = skiptowhite (arg);
    if (*end_subcmd == NUL)
        return;
    if (end_subcmd - arg == 5 && STRNCMP (arg, "start", 5) == 0) {
        xp->xp_context = EXPAND_FILES;
        xp->xp_pattern = skipwhite (end_subcmd);
        return;
    }
    xp->xp_context = EXPAND_NOTHING;
}

int can_abandon (buf_T *buf, int forceit) {
    return (buf_hide (buf) || !bufIsChanged (buf) || buf->b_nwindows > 1 || autowrite (buf, forceit) == OK || forceit);
}

static void source_callback (char_u *fname, void *cookie) {
    (void) do_source (fname, FALSE, DOSO_NONE);
}

linenr_T *source_breakpoint (void *cookie) {
    return &((struct source_cookie *) cookie)->breakpoint;
}

int *source_dbg_tick (void *cookie) {
    return &((struct source_cookie *) cookie)->dbg_tick;
}

int source_finished (char_u * (*fgetline) (int, void *, int), void *cookie) {
    return (getline_equal (fgetline, cookie, getsourceline) && ((struct source_cookie *) getline_cookie (fgetline, cookie))->finished);
}

void script_line_exec (void) {
    scriptitem_T *si;
    if (current_SID <= 0 || current_SID > script_items.ga_len)
        return;
    si = &SCRIPT_ITEM (current_SID);
    if (si->sn_prof_on && si->sn_prl_idx >= 0)
        si->sn_prl_execed = TRUE;
}

void dbg_check_breakpoint (exarg_T *eap) {
    char_u *p;
    debug_skipped = FALSE;
    if (debug_breakpoint_name != NULL) {
        if (!eap->skip) {
            if (debug_breakpoint_name[0] == K_SPECIAL && debug_breakpoint_name[1] == KS_EXTRA && debug_breakpoint_name[2] == (int) KE_SNR)
                p = (char_u *) "<SNR>";
            else
                p = (char_u *) "";
            smsg ((char_u *) _ ("Breakpoint in \"%s%s\" line %ld"), p, debug_breakpoint_name + (* p == NUL ? 0 : 3), (long) debug_breakpoint_lnum);
            debug_breakpoint_name = NULL;
            do_debug (eap -> cmd);
        }
        else {
            debug_skipped = TRUE;
            debug_skipped_name = debug_breakpoint_name;
            debug_breakpoint_name = NULL;
        }
    }
    else if (ex_nesting_level <= debug_break_level) {
        if (!eap->skip)
            do_debug (eap->cmd);
        else {
            debug_skipped = TRUE;
            debug_skipped_name = NULL;
        }
    }
}

void do_debug (char_u *cmd) {
    int save_msg_scroll = msg_scroll;
    int save_State = State;
    int save_did_emsg = did_emsg;
    int save_cmd_silent = cmd_silent;
    int save_msg_silent = msg_silent;
    int save_emsg_silent = emsg_silent;
    int save_redir_off = redir_off;
    tasave_T typeaheadbuf;
    int typeahead_saved = FALSE;
    int save_ignore_script = 0;
    int save_ex_normal_busy;
    int n;
    char_u *cmdline = NULL;
    char_u *p;
    char *tail = NULL;
    static int last_cmd = 0;

    #define CMD_CONT	1

    #define CMD_NEXT	2

    #define CMD_STEP	3

    #define CMD_FINISH	4

    #define CMD_QUIT	5

    #define CMD_INTERRUPT	6

    #define CMD_BACKTRACE	7

    #define CMD_FRAME	8

    #define CMD_UP		9

    #define CMD_DOWN	10
    settmode (TMODE_RAW);
    starttermcap ();
    ++RedrawingDisabled;
    ++no_wait_return;
    did_emsg = FALSE;
    cmd_silent = FALSE;
    msg_silent = FALSE;
    emsg_silent = FALSE;
    redir_off = TRUE;
    State = NORMAL;
    debug_mode = TRUE;
    if (!debug_did_msg)
        MSG (_ ("Entering Debug mode.  Type \"cont\" to continue."));
    if (debug_oldval != NULL) {
        smsg ((char_u *) _ ("Oldval = \"%s\""), debug_oldval);
        vim_free (debug_oldval);
        debug_oldval = NULL;
    }
    if (debug_newval != NULL) {
        smsg ((char_u *) _ ("Newval = \"%s\""), debug_newval);
        vim_free (debug_newval);
        debug_newval = NULL;
    }
    if (sourcing_name != NULL)
        msg (sourcing_name);
    if (sourcing_lnum != 0)
        smsg ((char_u *) _ ("line %ld: %s"), (long ) sourcing_lnum, cmd);
    else
        smsg ((char_u *) _ ("cmd: %s"), cmd);
    for (;;) {
        msg_scroll = TRUE;
        need_wait_return = FALSE;
        save_ex_normal_busy = ex_normal_busy;
        ex_normal_busy = 0;
        if (!debug_greedy) {
            save_typeahead (& typeaheadbuf);
            typeahead_saved = TRUE;
            save_ignore_script = ignore_script;
            ignore_script = TRUE;
        }
        vim_free (cmdline);
        cmdline = getcmdline_prompt ('>', NULL, 0, EXPAND_NOTHING, NULL);
        if (typeahead_saved) {
            restore_typeahead (& typeaheadbuf);
            ignore_script = save_ignore_script;
        }
        ex_normal_busy = save_ex_normal_busy;
        cmdline_row = msg_row;
        msg_starthere ();
        if (cmdline != NULL) {
            p = skipwhite (cmdline);
            if (*p != NUL) {
                switch (*p) {
                case 'c' :
                    last_cmd = CMD_CONT;
                    tail = "ont";
                    break;
                case 'n' :
                    last_cmd = CMD_NEXT;
                    tail = "ext";
                    break;
                case 's' :
                    last_cmd = CMD_STEP;
                    tail = "tep";
                    break;
                case 'f' :
                    last_cmd = 0;
                    if (p[1] == 'r') {
                        last_cmd = CMD_FRAME;
                        tail = "rame";
                    }
                    else {
                        last_cmd = CMD_FINISH;
                        tail = "inish";
                    }
                    break;
                case 'q' :
                    last_cmd = CMD_QUIT;
                    tail = "uit";
                    break;
                case 'i' :
                    last_cmd = CMD_INTERRUPT;
                    tail = "nterrupt";
                    break;
                case 'b' :
                    last_cmd = CMD_BACKTRACE;
                    if (p[1] == 't')
                        tail = "t";
                    else
                        tail = "acktrace";
                    break;
                case 'w' :
                    last_cmd = CMD_BACKTRACE;
                    tail = "here";
                    break;
                case 'u' :
                    last_cmd = CMD_UP;
                    tail = "p";
                    break;
                case 'd' :
                    last_cmd = CMD_DOWN;
                    tail = "own";
                    break;
                default :
                    last_cmd = 0;
                }
                if (last_cmd != 0) {
                    ++p;
                    while (*p != NUL && *p == *tail) {
                        ++p;
                        ++tail;
                    }
                    if (ASCII_ISALPHA (*p) && last_cmd != CMD_FRAME)
                        last_cmd = 0;
                }
            }
            if (last_cmd != 0) {
                switch (last_cmd) {
                case CMD_CONT :
                    debug_break_level = -1;
                    break;
                case CMD_NEXT :
                    debug_break_level = ex_nesting_level;
                    break;
                case CMD_STEP :
                    debug_break_level = 9999;
                    break;
                case CMD_FINISH :
                    debug_break_level = ex_nesting_level - 1;
                    break;
                case CMD_QUIT :
                    got_int = TRUE;
                    debug_break_level = -1;
                    break;
                case CMD_INTERRUPT :
                    got_int = TRUE;
                    debug_break_level = 9999;
                    last_cmd = CMD_STEP;
                    break;
                case CMD_BACKTRACE :
                    do_showbacktrace (cmd);
                    continue;
                case CMD_FRAME :
                    if (*p == NUL) {
                        do_showbacktrace (cmd);
                    }
                    else {
                        p = skipwhite (p);
                        do_setdebugtracelevel (p);
                    }
                    continue;
                case CMD_UP :
                    debug_backtrace_level++;
                    do_checkbacktracelevel ();
                    continue;
                case CMD_DOWN :
                    debug_backtrace_level--;
                    do_checkbacktracelevel ();
                    continue;
                }
                debug_backtrace_level = 0;
                break;
            }
            n = debug_break_level;
            debug_break_level = -1;
            (void) do_cmdline (cmdline, getexline, NULL, DOCMD_VERBOSE | DOCMD_EXCRESET);
            debug_break_level = n;
        }
        lines_left = Rows - 1;
    }
    vim_free (cmdline);
    --RedrawingDisabled;
    --no_wait_return;
    redraw_all_later (NOT_VALID);
    need_wait_return = FALSE;
    msg_scroll = save_msg_scroll;
    lines_left = Rows - 1;
    State = save_State;
    debug_mode = FALSE;
    did_emsg = save_did_emsg;
    cmd_silent = save_cmd_silent;
    msg_silent = save_msg_silent;
    emsg_silent = save_emsg_silent;
    redir_off = save_redir_off;
    debug_did_msg = TRUE;
}

static void do_showbacktrace (char_u *cmd) {
    char *cur;
    char *next;
    int i = 0;
    int max = get_maxbacktrace_level ();
    if (sourcing_name != NULL) {
        cur = (char *) sourcing_name;
        while (!got_int) {
            next = strstr (cur, "..");
            if (next != NULL)
                *next = NUL;
            if (i == max - debug_backtrace_level)
                smsg ((char_u *) "->%d %s", max -i, cur);
            else
                smsg ((char_u *) "  %d %s", max -i, cur);
            ++i;
            if (next == NULL)
                break;
            *next = '.';
            cur = next + 2;
        }
    }
    if (sourcing_lnum != 0)
        smsg ((char_u *) _ ("line %ld: %s"), (long ) sourcing_lnum, cmd);
    else
        smsg ((char_u *) _ ("cmd: %s"), cmd);
}

static int get_maxbacktrace_level (void) {
    char *p, *q;
    int maxbacktrace = 0;
    if (sourcing_name != NULL) {
        p = (char *) sourcing_name;
        while ((q = strstr (p, "..")) != NULL) {
            p = q + 2;
            maxbacktrace++;
        }
    }
    return maxbacktrace;
}

static void do_setdebugtracelevel (char_u *arg) {
    int level;
    level = atoi ((char *) arg);
    if (*arg == '+' || level < 0)
        debug_backtrace_level += level;
    else
        debug_backtrace_level = level;
    do_checkbacktracelevel ();
}

static void do_checkbacktracelevel (void) {
    if (debug_backtrace_level < 0) {
        debug_backtrace_level = 0;
        MSG (_ ("frame is zero"));
    }
    else {
        int max = get_maxbacktrace_level ();
        if (debug_backtrace_level > max) {
            debug_backtrace_level = max;
            smsg ((char_u *) _ ("frame at highest level: %d"), max);
        }
    }
}

void do_finish (exarg_T *eap, int reanimate) {
    int idx;
    if (reanimate)
        ((struct source_cookie *) getline_cookie (eap->getline, eap->cookie))->finished = FALSE;
    idx = cleanup_conditionals (eap->cstack, 0, TRUE);
    if (idx >= 0) {
        eap->cstack->cs_pending[idx] = CSTP_FINISH;
        report_make_pending (CSTP_FINISH, NULL);
    }
    else
        ((struct source_cookie *) getline_cookie (eap->getline, eap->cookie))->finished = TRUE;
}

int has_watchexpr (void) {
    return debug_expr;
}

int source_level (void *cookie) {
    return ((struct source_cookie *) cookie)->level;
}

static void remove_timer (timer_T *timer) {
    if (timer->tr_prev == NULL)
        first_timer = timer->tr_next;
    else
        timer->tr_prev->tr_next = timer->tr_next;
    if (timer->tr_next != NULL)
        timer->tr_next->tr_prev = timer->tr_prev;
}

static void free_timer (timer_T *timer) {
    free_callback (timer -> tr_callback, timer -> tr_partial);
    vim_free (timer);
}

int prof_def_func (void) {
    if (current_SID > 0)
        return SCRIPT_ITEM (current_SID).sn_pr_force;
    return FALSE;
}

int check_changed_any (int hidden, int unload) {
    int ret = FALSE;
    buf_T *buf;
    int save;
    int i;
    int bufnum = 0;
    int bufcount = 0;
    int *bufnrs;
    tabpage_T *tp;
    win_T *wp;
    FOR_ALL_BUFFERS (buf)
        ++bufcount;
    if (bufcount == 0)
        return FALSE;
    bufnrs = (int *) alloc (sizeof (int) * bufcount);
    if (bufnrs == NULL)
        return FALSE;
    bufnrs[bufnum++] = curbuf->b_fnum;
    FOR_ALL_WINDOWS (wp)
        if (wp->w_buffer != curbuf)
            add_bufnum (bufnrs, &bufnum, wp->w_buffer->b_fnum);
    FOR_ALL_TABPAGES (tp)
        if (tp != curtab)
            for (wp = tp->tp_firstwin; wp != NULL; wp = wp->w_next)
                add_bufnum (bufnrs, &bufnum, wp->w_buffer->b_fnum);
    FOR_ALL_BUFFERS (buf)
        add_bufnum (bufnrs, &bufnum, buf->b_fnum);
    for (i = 0; i < bufnum; ++i) {
        buf = buflist_findnr (bufnrs[i]);
        if (buf == NULL)
            continue;
        if ((!hidden || buf->b_nwindows == 0) && bufIsChanged (buf)) {
            bufref_T bufref;
            set_bufref (& bufref, buf);
            if (check_changed (buf, (p_awa ? CCGD_AW : 0) | CCGD_MULTWIN | CCGD_ALLBUF) && bufref_valid (&bufref))
                break;
        }
    }
    if (i >= bufnum)
        goto theend;
    ret = TRUE;
    exiting = FALSE;
    if (!(p_confirm || cmdmod.confirm)) {
        if (vgetc_busy > 0) {
            msg_row = cmdline_row;
            msg_col = 0;
            msg_didout = FALSE;
        }
        if (term_job_running (buf->b_term) ? EMSG2 (_ ("E947: Job still running in buffer \"%s\""), buf->b_fname) : EMSG2 (_ ("E162: No write since last change for buffer \"%s\""), buf_spname (buf) != NULL ? buf_spname (buf) : buf->b_fname)) {
            save = no_wait_return;
            no_wait_return = FALSE;
            wait_return (FALSE);
            no_wait_return = save;
        }
    }
    if (buf != curbuf)
        FOR_ALL_TAB_WINDOWS (tp, wp)
            if (wp->w_buffer == buf) {
                bufref_T bufref;
                set_bufref (& bufref, buf);
                goto_tabpage_win (tp, wp);
                if (!bufref_valid (&bufref)) {
                    goto theend;
                }
                goto buf_found;
            }
buf_found :
    if (buf != curbuf)
        set_curbuf (buf, unload ? DOBUF_UNLOAD : DOBUF_GOTO);
theend :
    vim_free (bufnrs);
    return ret;
}

static void add_bufnum (int *bufnrs, int *bufnump, int nr) {
    int i;
    for (i = 0; i < *bufnump; ++i)
        if (bufnrs[i] == nr)
            return;
    bufnrs[*bufnump] = nr;
    *bufnump = *bufnump + 1;
}

float_T profile_float (proftime_T *tm) {
    return (float_T) tm->tv_sec + (float_T) tm->tv_usec / 1000000.0;
}

timer_T *find_timer (long  id) {
    timer_T *timer;
    if (id >= 0) {
        for (timer = first_timer; timer != NULL; timer = timer->tr_next)
            if (timer->tr_id == id)
                return timer;
    }
    return NULL;
}

void add_timer_info (typval_T *rettv, timer_T *timer) {
    list_T *list = rettv->vval.v_list;
    dict_T *dict = dict_alloc ();
    dictitem_T *di;
    long  remaining;
    proftime_T now;
    if (dict == NULL)
        return;
    list_append_dict (list, dict);
    dict_add_nr_str (dict, "id", timer -> tr_id, NULL);
    dict_add_nr_str (dict, "time", (long) timer -> tr_interval, NULL);
    profile_start (& now);
    remaining = proftime_time_left (&timer->tr_due, &now);
    dict_add_nr_str (dict, "remaining", (long) remaining, NULL);
    dict_add_nr_str (dict, "repeat", (long) (timer -> tr_repeat < 0 ? - 1 : timer -> tr_repeat + 1), NULL);
    dict_add_nr_str (dict, "paused", (long) (timer -> tr_paused), NULL);
    di = dictitem_alloc ((char_u *) "callback");
    if (di != NULL) {
        if (dict_add (dict, di) == FAIL)
            vim_free (di);
        else if (timer->tr_partial != NULL) {
            di->di_tv.v_type = VAR_PARTIAL;
            di->di_tv.vval.v_partial = timer->tr_partial;
            ++timer->tr_partial->pt_refcount;
        }
        else {
            di->di_tv.v_type = VAR_FUNC;
            di->di_tv.vval.v_string = vim_strsave (timer->tr_callback);
        }
        di->di_tv.v_lock = 0;
    }
}

void add_timer_info_all (typval_T *rettv) {
    timer_T *timer;
    for (timer = first_timer; timer != NULL; timer = timer->tr_next)
        if (timer->tr_id != -1)
            add_timer_info (rettv, timer);
}

timer_T *create_timer (long  msec, int repeat) {
    timer_T *timer = (timer_T *) alloc_clear (sizeof (timer_T));
    long  prev_id = last_timer_id;
    if (timer == NULL)
        return NULL;
    if (++last_timer_id <= prev_id)
        last_timer_id = 0;
    timer->tr_id = last_timer_id;
    insert_timer (timer);
    if (repeat != 0)
        timer->tr_repeat = repeat - 1;
    timer->tr_interval = msec;
    profile_setlimit (msec, & timer -> tr_due);
    return timer;
}

static void insert_timer (timer_T *timer) {
    timer->tr_next = first_timer;
    timer->tr_prev = NULL;
    if (first_timer != NULL)
        first_timer->tr_prev = timer;
    first_timer = timer;
    did_add_timer = TRUE;
}

void stop_timer (timer_T *timer) {
    if (timer->tr_firing)
        timer->tr_id = -1;
    else {
        remove_timer (timer);
        free_timer (timer);
    }
}

void stop_all_timers (void) {
    timer_T *timer;
    timer_T *timer_next;
    for (timer = first_timer; timer != NULL; timer = timer_next) {
        timer_next = timer->tr_next;
        stop_timer (timer);
    }
}

