
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
struct fst {
    char *f_name;
    char f_min_argc;
    char f_max_argc;
    void (*f_func) (typval_T *args, typval_T *rvar);
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
EXTERN long  p_verbose;
garray_T ga_userinput = {0, 0, sizeof (tasave_T), 4, NULL};
EXTERN win_T *firstwin;
EXTERN char_u *p_path;
EXTERN char_u e_trailing [] INIT (= N_ ("E488: Trailing characters"));
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
EXTERN char_u *p_titlestring;
char *e_stringreq = N_ ("E928: String required");
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
char *e_listarg = N_ ("E686: Argument of %s must be a List");
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
int inputsecret_flag = 0;
garray_T redir_execute_ga;
struct fst functions [] = {{"abs", 1, 1, f_abs}, {"acos", 1, 1, f_acos}, {"add", 2, 2, f_add}, {"and", 2, 2, f_and}, {"append", 2, 2, f_append}, {"argc", 0, 0, f_argc}, {"argidx", 0, 0, f_argidx}, {"arglistid", 0, 2, f_arglistid}, {"argv", 0, 1, f_argv}, {"asin", 1, 1, f_asin}, {"assert_beeps", 1, 2, f_assert_beeps}, {"assert_equal", 2, 3, f_assert_equal}, {"assert_exception", 1, 2, f_assert_exception}, {"assert_fails", 1, 2, f_assert_fails}, {"assert_false", 1, 2, f_assert_false}, {"assert_inrange", 3, 4, f_assert_inrange}, {"assert_match", 2, 3, f_assert_match}, {"assert_notequal", 2, 3, f_assert_notequal}, {"assert_notmatch", 2, 3, f_assert_notmatch}, {"assert_report", 1, 1, f_assert_report}, {"assert_true", 1, 2, f_assert_true}, {"atan", 1, 1, f_atan}, {"atan2", 2, 2, f_atan2}, {"balloon_show", 1, 1, f_balloon_show}, {"balloon_split", 1, 1, f_balloon_split}, {"browse", 4, 4, f_browse}, {"browsedir", 2, 2, f_browsedir}, {"bufexists", 1, 1, f_bufexists}, {"buffer_exists", 1, 1, f_bufexists}, {"buffer_name", 1, 1, f_bufname}, {"buffer_number", 1, 1, f_bufnr}, {"buflisted", 1, 1, f_buflisted}, {"bufloaded", 1, 1, f_bufloaded}, {"bufname", 1, 1, f_bufname}, {"bufnr", 1, 2, f_bufnr}, {"bufwinid", 1, 1, f_bufwinid}, {"bufwinnr", 1, 1, f_bufwinnr}, {"byte2line", 1, 1, f_byte2line}, {"byteidx", 2, 2, f_byteidx}, {"byteidxcomp", 2, 2, f_byteidxcomp}, {"call", 2, 3, f_call}, {"ceil", 1, 1, f_ceil}, {"ch_canread", 1, 1, f_ch_canread}, {"ch_close", 1, 1, f_ch_close}, {"ch_close_in", 1, 1, f_ch_close_in}, {"ch_evalexpr", 2, 3, f_ch_evalexpr}, {"ch_evalraw", 2, 3, f_ch_evalraw}, {"ch_getbufnr", 2, 2, f_ch_getbufnr}, {"ch_getjob", 1, 1, f_ch_getjob}, {"ch_info", 1, 1, f_ch_info}, {"ch_log", 1, 2, f_ch_log}, {"ch_logfile", 1, 2, f_ch_logfile}, {"ch_open", 1, 2, f_ch_open}, {"ch_read", 1, 2, f_ch_read}, {"ch_readraw", 1, 2, f_ch_readraw}, {"ch_sendexpr", 2, 3, f_ch_sendexpr}, {"ch_sendraw", 2, 3, f_ch_sendraw}, {"ch_setoptions", 2, 2, f_ch_setoptions}, {"ch_status", 1, 2, f_ch_status}, {"changenr", 0, 0, f_changenr}, {"char2nr", 1, 2, f_char2nr}, {"cindent", 1, 1, f_cindent}, {"clearmatches", 0, 0, f_clearmatches}, {"col", 1, 1, f_col}, {"complete", 2, 2, f_complete}, {"complete_add", 1, 1, f_complete_add}, {"complete_check", 0, 0, f_complete_check}, {"confirm", 1, 4, f_confirm}, {"copy", 1, 1, f_copy}, {"cos", 1, 1, f_cos}, {"cosh", 1, 1, f_cosh}, {"count", 2, 4, f_count}, {"cscope_connection", 0, 3, f_cscope_connection}, {"cursor", 1, 3, f_cursor}, {"deepcopy", 1, 2, f_deepcopy}, {"delete", 1, 2, f_delete}, {"did_filetype", 0, 0, f_did_filetype}, {"diff_filler", 1, 1, f_diff_filler}, {"diff_hlID", 2, 2, f_diff_hlID}, {"empty", 1, 1, f_empty}, {"escape", 2, 2, f_escape}, {"eval", 1, 1, f_eval}, {"eventhandler", 0, 0, f_eventhandler}, {"executable", 1, 1, f_executable}, {"execute", 1, 2, f_execute}, {"exepath", 1, 1, f_exepath}, {"exists", 1, 1, f_exists}, {"exp", 1, 1, f_exp}, {"expand", 1, 3, f_expand}, {"extend", 2, 3, f_extend}, {"feedkeys", 1, 2, f_feedkeys}, {"file_readable", 1, 1, f_filereadable}, {"filereadable", 1, 1, f_filereadable}, {"filewritable", 1, 1, f_filewritable}, {"filter", 2, 2, f_filter}, {"finddir", 1, 3, f_finddir}, {"findfile", 1, 3, f_findfile}, {"float2nr", 1, 1, f_float2nr}, {"floor", 1, 1, f_floor}, {"fmod", 2, 2, f_fmod}, {"fnameescape", 1, 1, f_fnameescape}, {"fnamemodify", 2, 2, f_fnamemodify}, {"foldclosed", 1, 1, f_foldclosed}, {"foldclosedend", 1, 1, f_foldclosedend}, {"foldlevel", 1, 1, f_foldlevel}, {"foldtext", 0, 0, f_foldtext}, {"foldtextresult", 1, 1, f_foldtextresult}, {"foreground", 0, 0, f_foreground}, {"funcref", 1, 3, f_funcref}, {"function", 1, 3, f_function}, {"garbagecollect", 0, 1, f_garbagecollect}, {"get", 2, 3, f_get}, {"getbufinfo", 0, 1, f_getbufinfo}, {"getbufline", 2, 3, f_getbufline}, {"getbufvar", 2, 3, f_getbufvar}, {"getchangelist", 1, 1, f_getchangelist}, {"getchar", 0, 1, f_getchar}, {"getcharmod", 0, 0, f_getcharmod}, {"getcharsearch", 0, 0, f_getcharsearch}, {"getcmdline", 0, 0, f_getcmdline}, {"getcmdpos", 0, 0, f_getcmdpos}, {"getcmdtype", 0, 0, f_getcmdtype}, {
  "getcmdwintype", 0, 0, f_getcmdwintype}, {"getcompletion", 2, 3, f_getcompletion}, {"getcurpos", 0, 0, f_getcurpos}, {"getcwd", 0, 2, f_getcwd}, {"getfontname", 0, 1, f_getfontname}, {"getfperm", 1, 1, f_getfperm}, {"getfsize", 1, 1, f_getfsize}, {"getftime", 1, 1, f_getftime}, {"getftype", 1, 1, f_getftype}, {"getjumplist", 0, 2, f_getjumplist}, {"getline", 1, 2, f_getline}, {"getloclist", 1, 2, f_getloclist}, {"getmatches", 0, 0, f_getmatches}, {"getpid", 0, 0, f_getpid}, {"getpos", 1, 1, f_getpos}, {"getqflist", 0, 1, f_getqflist}, {"getreg", 0, 3, f_getreg}, {"getregtype", 0, 1, f_getregtype}, {"gettabinfo", 0, 1, f_gettabinfo}, {"gettabvar", 2, 3, f_gettabvar}, {"gettabwinvar", 3, 4, f_gettabwinvar}, {"getwininfo", 0, 1, f_getwininfo}, {"getwinposx", 0, 0, f_getwinposx}, {"getwinposy", 0, 0, f_getwinposy}, {"getwinvar", 2, 3, f_getwinvar}, {"glob", 1, 4, f_glob}, {"glob2regpat", 1, 1, f_glob2regpat}, {"globpath", 2, 5, f_globpath}, {"has", 1, 1, f_has}, {"has_key", 2, 2, f_has_key}, {"haslocaldir", 0, 2, f_haslocaldir}, {"hasmapto", 1, 3, f_hasmapto}, {"highlightID", 1, 1, f_hlID}, {"highlight_exists", 1, 1, f_hlexists}, {"histadd", 2, 2, f_histadd}, {"histdel", 1, 2, f_histdel}, {"histget", 1, 2, f_histget}, {"histnr", 1, 1, f_histnr}, {"hlID", 1, 1, f_hlID}, {"hlexists", 1, 1, f_hlexists}, {"hostname", 0, 0, f_hostname}, {"iconv", 3, 3, f_iconv}, {"indent", 1, 1, f_indent}, {"index", 2, 4, f_index}, {"input", 1, 3, f_input}, {"inputdialog", 1, 3, f_inputdialog}, {"inputlist", 1, 1, f_inputlist}, {"inputrestore", 0, 0, f_inputrestore}, {"inputsave", 0, 0, f_inputsave}, {"inputsecret", 1, 2, f_inputsecret}, {"insert", 2, 3, f_insert}, {"invert", 1, 1, f_invert}, {"isdirectory", 1, 1, f_isdirectory}, {"islocked", 1, 1, f_islocked}, {"items", 1, 1, f_items}, {"job_getchannel", 1, 1, f_job_getchannel}, {"job_info", 1, 1, f_job_info}, {"job_setoptions", 2, 2, f_job_setoptions}, {"job_start", 1, 2, f_job_start}, {"job_status", 1, 1, f_job_status}, {"job_stop", 1, 2, f_job_stop}, {"join", 1, 2, f_join}, {"js_decode", 1, 1, f_js_decode}, {"js_encode", 1, 1, f_js_encode}, {"json_decode", 1, 1, f_json_decode}, {"json_encode", 1, 1, f_json_encode}, {"keys", 1, 1, f_keys}, {"last_buffer_nr", 0, 0, f_last_buffer_nr}, {"len", 1, 1, f_len}, {"libcall", 3, 3, f_libcall}, {"libcallnr", 3, 3, f_libcallnr}, {"line", 1, 1, f_line}, {"line2byte", 1, 1, f_line2byte}, {"lispindent", 1, 1, f_lispindent}, {"localtime", 0, 0, f_localtime}, {"log", 1, 1, f_log}, {"log10", 1, 1, f_log10}, {"map", 2, 2, f_map}, {"maparg", 1, 4, f_maparg}, {"mapcheck", 1, 3, f_mapcheck}, {"match", 2, 4, f_match}, {"matchadd", 2, 5, f_matchadd}, {"matchaddpos", 2, 5, f_matchaddpos}, {"matcharg", 1, 1, f_matcharg}, {"matchdelete", 1, 1, f_matchdelete}, {"matchend", 2, 4, f_matchend}, {"matchlist", 2, 4, f_matchlist}, {"matchstr", 2, 4, f_matchstr}, {"matchstrpos", 2, 4, f_matchstrpos}, {"max", 1, 1, f_max}, {"min", 1, 1, f_min}, {"mode", 0, 1, f_mode}, {"nextnonblank", 1, 1, f_nextnonblank}, {"nr2char", 1, 2, f_nr2char}, {"or", 2, 2, f_or}, {"pathshorten", 1, 1, f_pathshorten}, {"pow", 2, 2, f_pow}, {"prevnonblank", 1, 1, f_prevnonblank}, {"printf", 2, 19, f_printf}, {"pumvisible", 0, 0, f_pumvisible}, {"range", 1, 3, f_range}, {"readfile", 1, 3, f_readfile}, {"reltime", 0, 2, f_reltime}, {"reltimefloat", 1, 1, f_reltimefloat}, {"reltimestr", 1, 1, f_reltimestr}, {"remote_expr", 2, 4, f_remote_expr}, {"remote_foreground", 1, 1, f_remote_foreground}, {"remote_peek", 1, 2, f_remote_peek}, {"remote_read", 1, 2, f_remote_read}, {"remote_send", 2, 3, f_remote_send}, {"remote_startserver", 1, 1, f_remote_startserver}, {"remove", 2, 3, f_remove}, {"rename", 2, 2, f_rename}, {"repeat", 2, 2, f_repeat}, {"resolve", 1, 1, f_resolve}, {"reverse", 1, 1, f_reverse}, {"round", 1, 1, f_round}, {"screenattr", 2, 2, f_screenattr}, {"screenchar", 2, 2, f_screenchar}, {"screencol", 0, 0, f_screencol}, {"screenrow", 0, 0, f_screenrow}, {"search", 1, 4, f_search}, {"searchdecl", 1, 3, f_searchdecl}, {"searchpair", 3, 7, f_searchpair}, {"searchpairpos", 3, 7, f_searchpairpos}, {
  "searchpos", 1, 4, f_searchpos}, {"server2client", 2, 2, f_server2client}, {"serverlist", 0, 0, f_serverlist}, {"setbufline", 3, 3, f_setbufline}, {"setbufvar", 3, 3, f_setbufvar}, {"setcharsearch", 1, 1, f_setcharsearch}, {"setcmdpos", 1, 1, f_setcmdpos}, {"setfperm", 2, 2, f_setfperm}, {"setline", 2, 2, f_setline}, {"setloclist", 2, 4, f_setloclist}, {"setmatches", 1, 1, f_setmatches}, {"setpos", 2, 2, f_setpos}, {"setqflist", 1, 3, f_setqflist}, {"setreg", 2, 3, f_setreg}, {"settabvar", 3, 3, f_settabvar}, {"settabwinvar", 4, 4, f_settabwinvar}, {"setwinvar", 3, 3, f_setwinvar}, {"sha256", 1, 1, f_sha256}, {"shellescape", 1, 2, f_shellescape}, {"shiftwidth", 0, 0, f_shiftwidth}, {"simplify", 1, 1, f_simplify}, {"sin", 1, 1, f_sin}, {"sinh", 1, 1, f_sinh}, {"sort", 1, 3, f_sort}, {"soundfold", 1, 1, f_soundfold}, {"spellbadword", 0, 1, f_spellbadword}, {"spellsuggest", 1, 3, f_spellsuggest}, {"split", 1, 3, f_split}, {"sqrt", 1, 1, f_sqrt}, {"str2float", 1, 1, f_str2float}, {"str2nr", 1, 2, f_str2nr}, {"strcharpart", 2, 3, f_strcharpart}, {"strchars", 1, 2, f_strchars}, {"strdisplaywidth", 1, 2, f_strdisplaywidth}, {"strgetchar", 2, 2, f_strgetchar}, {"stridx", 2, 3, f_stridx}, {"string", 1, 1, f_string}, {"strlen", 1, 1, f_strlen}, {"strpart", 2, 3, f_strpart}, {"strridx", 2, 3, f_strridx}, {"strtrans", 1, 1, f_strtrans}, {"strwidth", 1, 1, f_strwidth}, {"submatch", 1, 2, f_submatch}, {"substitute", 4, 4, f_substitute}, {"synID", 3, 3, f_synID}, {"synIDattr", 2, 3, f_synIDattr}, {"synIDtrans", 1, 1, f_synIDtrans}, {"synconcealed", 2, 2, f_synconcealed}, {"synstack", 2, 2, f_synstack}, {"system", 1, 2, f_system}, {"systemlist", 1, 2, f_systemlist}, {"tabpagebuflist", 0, 1, f_tabpagebuflist}, {"tabpagenr", 0, 1, f_tabpagenr}, {"tabpagewinnr", 1, 2, f_tabpagewinnr}, {"tagfiles", 0, 0, f_tagfiles}, {"taglist", 1, 2, f_taglist}, {"tan", 1, 1, f_tan}, {"tanh", 1, 1, f_tanh}, {"tempname", 0, 0, f_tempname}, {"term_getaltscreen", 1, 1, f_term_getaltscreen}, {"term_getattr", 2, 2, f_term_getattr}, {"term_getcursor", 1, 1, f_term_getcursor}, {"term_getjob", 1, 1, f_term_getjob}, {"term_getline", 2, 2, f_term_getline}, {"term_getscrolled", 1, 1, f_term_getscrolled}, {"term_getsize", 1, 1, f_term_getsize}, {"term_getstatus", 1, 1, f_term_getstatus}, {"term_gettitle", 1, 1, f_term_gettitle}, {"term_gettty", 1, 2, f_term_gettty}, {"term_list", 0, 0, f_term_list}, {"term_scrape", 2, 2, f_term_scrape}, {"term_sendkeys", 2, 2, f_term_sendkeys}, {"term_start", 1, 2, f_term_start}, {"term_wait", 1, 2, f_term_wait}, {"test_alloc_fail", 3, 3, f_test_alloc_fail}, {"test_autochdir", 0, 0, f_test_autochdir}, {"test_feedinput", 1, 1, f_test_feedinput}, {"test_garbagecollect_now", 0, 0, f_test_garbagecollect_now}, {"test_ignore_error", 1, 1, f_test_ignore_error}, {"test_null_channel", 0, 0, f_test_null_channel}, {"test_null_dict", 0, 0, f_test_null_dict}, {"test_null_job", 0, 0, f_test_null_job}, {"test_null_list", 0, 0, f_test_null_list}, {"test_null_partial", 0, 0, f_test_null_partial}, {"test_null_string", 0, 0, f_test_null_string}, {"test_override", 2, 2, f_test_override}, {"test_settime", 1, 1, f_test_settime}, {"timer_info", 0, 1, f_timer_info}, {"timer_pause", 2, 2, f_timer_pause}, {"timer_start", 2, 3, f_timer_start}, {"timer_stop", 1, 1, f_timer_stop}, {"timer_stopall", 0, 0, f_timer_stopall}, {"tolower", 1, 1, f_tolower}, {"toupper", 1, 1, f_toupper}, {"tr", 3, 3, f_tr}, {"trunc", 1, 1, f_trunc}, {"type", 1, 1, f_type}, {"undofile", 1, 1, f_undofile}, {"undotree", 0, 0, f_undotree}, {"uniq", 1, 3, f_uniq}, {"values", 1, 1, f_values}, {"virtcol", 1, 1, f_virtcol}, {"visualmode", 0, 1, f_visualmode}, {"wildmenumode", 0, 0, f_wildmenumode}, {"win_findbuf", 1, 1, f_win_findbuf}, {"win_getid", 0, 2, f_win_getid}, {"win_gotoid", 1, 1, f_win_gotoid}, {"win_id2tabwin", 1, 1, f_win_id2tabwin}, {"win_id2win", 1, 1, f_win_id2win}, {"win_screenpos", 1, 1, f_win_screenpos}, {"winbufnr", 1, 1, f_winbufnr}, {"wincol", 0, 0, f_wincol}, {"winheight", 1, 1, f_winheight}, {"winline", 0, 0, f_winline}, {"winnr", 0, 1, f_winnr}, {"winrestcmd", 0, 0,
  f_winrestcmd}, {"winrestview", 1, 1, f_winrestview}, {"winsaveview", 0, 0, f_winsaveview}, {"winwidth", 1, 1, f_winwidth}, {"wordcount", 0, 0, f_wordcount}, {"writefile", 2, 3, f_writefile}, {"xor", 2, 2, f_xor},};
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
EXTERN int autocmd_fname_full;
EXTERN char_u *autocmd_fname INIT (= NULL);
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

void execute_redir_str (char_u *value, int value_len) {
    int len;
    if (value_len == -1)
        len = (int) STRLEN (value);
    else
        len = value_len;
    if (ga_grow (&redir_execute_ga, len) == OK) {
        mch_memmove ((char *) redir_execute_ga.ga_data + redir_execute_ga.ga_len, value, len);
        redir_execute_ga.ga_len += len;
    }
}

void free_callback (char_u *callback, partial_T *partial) {
    if (partial != NULL)
        partial_unref (partial);
    else if (callback != NULL) {
        func_unref (callback);
        vim_free (callback);
    }
}

char_u *get_function_name (expand_T *xp, int idx) {
    static int intidx = -1;
    char_u *name;
    if (idx == 0)
        intidx = -1;
    if (intidx < 0) {
        name = get_user_func_name (xp, idx);
        if (name != NULL)
            return name;
    }
    if (++intidx < (int) (sizeof (functions) / sizeof (struct fst))) {
        STRCPY (IObuff, functions [intidx].f_name);
        STRCAT (IObuff, "(");
        if (functions[intidx].f_max_argc == 0)
            STRCAT (IObuff, ")");
        return IObuff;
    }
    return NULL;
}

char_u *get_expr_name (expand_T *xp, int idx) {
    static int intidx = -1;
    char_u *name;
    if (idx == 0)
        intidx = -1;
    if (intidx < 0) {
        name = get_function_name (xp, idx);
        if (name != NULL)
            return name;
    }
    return get_user_var_name (xp, ++intidx);
}

int find_internal_func (char_u *name) {
    int first = 0;
    int last = (int) (sizeof (functions) / sizeof (struct fst)) - 1;
    int cmp;
    int x;
    while (first <= last) {
        x = first + ((unsigned ) (last - first) >> 1);
        cmp = STRCMP (name, functions[x].f_name);
        if (cmp < 0)
            last = x - 1;
        else if (cmp > 0)
            first = x + 1;
        else
            return x;
    }
    return -1;
}

int call_internal_func (char_u *name, int argcount, typval_T *argvars, typval_T *rettv) {
    int i;
    i = find_internal_func (name);
    if (i < 0)
        return ERROR_UNKNOWN;
    if (argcount < functions[i].f_min_argc)
        return ERROR_TOOFEW;
    if (argcount > functions[i].f_max_argc)
        return ERROR_TOOMANY;
    argvars[argcount].v_type = VAR_UNKNOWN;
    functions[i].f_func (argvars, rettv);
    return ERROR_NONE;
}

buf_T *get_buf_tv (typval_T *tv, int curtab_only) {
    char_u *name = tv->vval.v_string;
    buf_T *buf;
    if (tv->v_type == VAR_NUMBER)
        return buflist_findnr ((int) tv->vval.v_number);
    if (tv->v_type != VAR_STRING)
        return NULL;
    if (name == NULL || *name == NUL)
        return curbuf;
    if (name[0] == '$' && name[1] == NUL)
        return lastbuf;
    buf = buflist_find_by_name (name, curtab_only);
    if (buf == NULL)
        buf = find_buffer (tv);
    return buf;
}

buf_T *buflist_find_by_name (char_u *name, int curtab_only) {
    int save_magic;
    char_u *save_cpo;
    buf_T *buf;
    save_magic = p_magic;
    p_magic = TRUE;
    save_cpo = p_cpo;
    p_cpo = (char_u *) "";
    buf = buflist_findnr (buflist_findpat (name, name + STRLEN (name), TRUE, FALSE, curtab_only));
    p_magic = save_magic;
    p_cpo = save_cpo;
    return buf;
}

static buf_T *find_buffer (typval_T *avar) {
    buf_T *buf = NULL;
    if (avar->v_type == VAR_NUMBER)
        buf = buflist_findnr ((int) avar->vval.v_number);
    else if (avar->v_type == VAR_STRING && avar->vval.v_string != NULL) {
        buf = buflist_findname_exp (avar->vval.v_string);
        if (buf == NULL) {
            FOR_ALL_BUFFERS (buf)
                if (buf->b_fname != NULL && (path_with_url (buf->b_fname) || bt_nofile (buf)) && STRCMP (buf->b_fname, avar->vval.v_string) == 0)
                    break;
        }
    }
    return buf;
}

char_u *get_callback (typval_T *arg, partial_T **pp) {
    if (arg->v_type == VAR_PARTIAL && arg->vval.v_partial != NULL) {
        *pp = arg->vval.v_partial;
        ++(*pp)->pt_refcount;
        return partial_name (*pp);
    }
    *pp = NULL;
    if (arg->v_type == VAR_FUNC || arg->v_type == VAR_STRING) {
        func_ref (arg -> vval.v_string);
        return arg->vval.v_string;
    }
    if (arg->v_type == VAR_NUMBER && arg->vval.v_number == 0)
        return (char_u *) "";
    EMSG (_ ("E921: Invalid callback argument"));
    return NULL;
}

static void f_abs (typval_T *argvars, typval_T *rettv) {
    if (argvars[0].v_type == VAR_FLOAT) {
        rettv->v_type = VAR_FLOAT;
        rettv->vval.v_float = fabs (argvars[0].vval.v_float);
    }
    else {
        varnumber_T n;
        int error = FALSE;
        n = get_tv_number_chk (&argvars[0], &error);
        if (error)
            rettv->vval.v_number = -1;
        else if (n > 0)
            rettv->vval.v_number = n;
        else
            rettv->vval.v_number = -n;
    }
}

static void f_acos (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &f) == OK)
        rettv->vval.v_float = acos (f);
    else
        rettv->vval.v_float = 0.0;
}

static int get_float_arg (typval_T *argvars, float_T *f) {
    if (argvars[0].v_type == VAR_FLOAT) {
        *f = argvars[0].vval.v_float;
        return OK;
    }
    if (argvars[0].v_type == VAR_NUMBER) {
        *f = (float_T) argvars[0].vval.v_number;
        return OK;
    }
    EMSG (_ ("E808: Number or Float required"));
    return FAIL;
}

static void f_add (typval_T *argvars, typval_T *rettv) {
    list_T *l;
    rettv->vval.v_number = 1;
    if (argvars[0].v_type == VAR_LIST) {
        if ((l = argvars[0].vval.v_list) != NULL && !tv_check_lock (l->lv_lock, (char_u *) N_ ("add() argument"), TRUE) && list_append_tv (l, &argvars[1]) == OK)
            copy_tv (&argvars[0], rettv);
    }
    else
        EMSG (_ (e_listreq));
}

static void f_and (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = get_tv_number_chk (&argvars[0], NULL) & get_tv_number_chk (&argvars[1], NULL);
}

static void f_append (typval_T *argvars, typval_T *rettv) {
    long  lnum;
    char_u *line;
    list_T *l = NULL;
    listitem_T *li = NULL;
    typval_T *tv;
    long  added = 0;
    if (u_sync_once == 2) {
        u_sync_once = 1;
        u_sync (TRUE);
    }
    lnum = get_tv_lnum (argvars);
    if (lnum >= 0 && lnum <= curbuf->b_ml.ml_line_count && u_save (lnum, lnum +1) == OK) {
        if (argvars[1].v_type == VAR_LIST) {
            l = argvars[1].vval.v_list;
            if (l == NULL)
                return;
            li = l->lv_first;
        }
        for (;;) {
            if (l == NULL)
                tv = &argvars[1];
            else if (li == NULL)
                break;
            else
                tv = &li->li_tv;
            line = get_tv_string_chk (tv);
            if (line == NULL) {
                rettv->vval.v_number = 1;
                break;
            }
            ml_append (lnum + added, line, (colnr_T) 0, FALSE);
            ++added;
            if (l == NULL)
                break;
            li = li->li_next;
        }
        appended_lines_mark (lnum, added);
        if (curwin->w_cursor.lnum > lnum)
            curwin->w_cursor.lnum += added;
    }
    else
        rettv->vval.v_number = 1;
}

static linenr_T get_tv_lnum (typval_T *argvars) {
    typval_T rettv;
    linenr_T lnum;
    lnum = (linenr_T) get_tv_number_chk (&argvars[0], NULL);
    if (lnum == 0) {
        rettv.v_type = VAR_NUMBER;
        f_line (argvars, & rettv);
        lnum = (linenr_T) rettv.vval.v_number;
        clear_tv (& rettv);
    }
    return lnum;
}

static void f_line (typval_T *argvars, typval_T *rettv) {
    linenr_T lnum = 0;
    pos_T *fp;
    int fnum;
    fp = var2fpos (&argvars[0], TRUE, &fnum);
    if (fp != NULL)
        lnum = fp->lnum;
    rettv->vval.v_number = lnum;
}

static void f_argc (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = ARGCOUNT;
}

static void f_argidx (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = curwin->w_arg_idx;
}

static void f_arglistid (typval_T *argvars, typval_T *rettv) {
    win_T *wp;
    rettv->vval.v_number = -1;
    wp = find_tabwin (&argvars[0], &argvars[1]);
    if (wp != NULL)
        rettv->vval.v_number = wp->w_alist->id;
}

static void f_argv (typval_T *argvars, typval_T *rettv) {
    int idx;
    if (argvars[0].v_type != VAR_UNKNOWN) {
        idx = (int) get_tv_number_chk (&argvars[0], NULL);
        if (idx >= 0 && idx < ARGCOUNT)
            rettv->vval.v_string = vim_strsave (alist_name (&ARGLIST[idx]));
        else
            rettv->vval.v_string = NULL;
        rettv->v_type = VAR_STRING;
    }
    else if (rettv_list_alloc (rettv) == OK)
        for (idx = 0; idx < ARGCOUNT; ++idx)
            list_append_string (rettv->vval.v_list, alist_name (&ARGLIST[idx]), -1);
}

static void f_assert_beeps (typval_T *argvars, typval_T *rettv) {
    assert_beeps (argvars);
}

static void f_assert_equal (typval_T *argvars, typval_T *rettv) {
    assert_equal_common (argvars, ASSERT_EQUAL);
}

static void f_assert_notequal (typval_T *argvars, typval_T *rettv) {
    assert_equal_common (argvars, ASSERT_NOTEQUAL);
}

static void f_assert_exception (typval_T *argvars, typval_T *rettv) {
    assert_exception (argvars);
}

static void f_assert_fails (typval_T *argvars, typval_T *rettv) {
    assert_fails (argvars);
}

static void f_assert_false (typval_T *argvars, typval_T *rettv) {
    assert_bool (argvars, FALSE);
}

static void f_assert_inrange (typval_T *argvars, typval_T *rettv) {
    assert_inrange (argvars);
}

static void f_assert_match (typval_T *argvars, typval_T *rettv) {
    assert_match_common (argvars, ASSERT_MATCH);
}

static void f_assert_notmatch (typval_T *argvars, typval_T *rettv) {
    assert_match_common (argvars, ASSERT_NOTMATCH);
}

static void f_assert_report (typval_T *argvars, typval_T *rettv) {
    assert_report (argvars);
}

static void f_assert_true (typval_T *argvars, typval_T *rettv) {
    assert_bool (argvars, TRUE);
}

static void f_asin (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &f) == OK)
        rettv->vval.v_float = asin (f);
    else
        rettv->vval.v_float = 0.0;
}

static void f_atan (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &f) == OK)
        rettv->vval.v_float = atan (f);
    else
        rettv->vval.v_float = 0.0;
}

static void f_atan2 (typval_T *argvars, typval_T *rettv) {
    float_T fx = 0.0, fy = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &fx) == OK && get_float_arg (&argvars[1], &fy) == OK)
        rettv->vval.v_float = atan2 (fx, fy);
    else
        rettv->vval.v_float = 0.0;
}

static void f_balloon_show (typval_T *argvars, typval_T *rettv) {
    if (balloonEval != NULL) {
        if (argvars[0].v_type == VAR_LIST && !gui.in_use)
            post_balloon (balloonEval, NULL, argvars[0].vval.v_list);
        else
            post_balloon (balloonEval, get_tv_string_chk (&argvars[0]), NULL);
    }
}

static void f_balloon_split (typval_T *argvars, typval_T *rettv) {
    if (rettv_list_alloc (rettv) == OK) {
        char_u *msg = get_tv_string_chk (&argvars[0]);
        if (msg != NULL) {
            pumitem_T *array;
            int size = split_message (msg, &array);
            int i;
            for (i = 1; i < size - 1; ++i)
                list_append_string (rettv->vval.v_list, array[i].pum_text, -1);
            while (size > 0)
                vim_free (array[--size].pum_text);
            vim_free (array);
        }
    }
}

static void f_browse (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_string = NULL;
    rettv->v_type = VAR_STRING;
}

static void f_browsedir (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_string = NULL;
    rettv->v_type = VAR_STRING;
}

static void f_bufexists (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = (find_buffer (&argvars[0]) != NULL);
}

static void f_buflisted (typval_T *argvars, typval_T *rettv) {
    buf_T *buf;
    buf = find_buffer (&argvars[0]);
    rettv->vval.v_number = (buf != NULL && buf->b_p_bl);
}

static void f_bufloaded (typval_T *argvars, typval_T *rettv) {
    buf_T *buf;
    buf = find_buffer (&argvars[0]);
    rettv->vval.v_number = (buf != NULL && buf->b_ml.ml_mfp != NULL);
}

static void f_bufname (typval_T *argvars, typval_T *rettv) {
    buf_T *buf;
    (void) get_tv_number (&argvars[0]);
    ++emsg_off;
    buf = get_buf_tv (&argvars[0], FALSE);
    rettv->v_type = VAR_STRING;
    if (buf != NULL && buf->b_fname != NULL)
        rettv->vval.v_string = vim_strsave (buf->b_fname);
    else
        rettv->vval.v_string = NULL;
    --emsg_off;
}

static void f_bufnr (typval_T *argvars, typval_T *rettv) {
    buf_T *buf;
    int error = FALSE;
    char_u *name;
    (void) get_tv_number (&argvars[0]);
    ++emsg_off;
    buf = get_buf_tv (&argvars[0], FALSE);
    --emsg_off;
    if (buf == NULL && argvars[1].v_type != VAR_UNKNOWN && get_tv_number_chk (&argvars[1], &error) != 0 && !error && (name = get_tv_string_chk (&argvars[0])) != NULL && !error)
        buf = buflist_new (name, NULL, (linenr_T) 1, 0);
    if (buf != NULL)
        rettv->vval.v_number = buf->b_fnum;
    else
        rettv->vval.v_number = -1;
}

static void f_bufwinid (typval_T *argvars, typval_T *rettv) {
    buf_win_common (argvars, rettv, FALSE);
}

static void buf_win_common (typval_T *argvars, typval_T *rettv, int get_nr) {
    win_T *wp;
    int winnr = 0;
    buf_T *buf;
    (void) get_tv_number (&argvars[0]);
    ++emsg_off;
    buf = get_buf_tv (&argvars[0], TRUE);
    FOR_ALL_WINDOWS (wp) {
        ++winnr;
        if (wp->w_buffer == buf)
            break;
    }
    rettv->vval.v_number = (wp != NULL ? (get_nr ? winnr : wp->w_id) : -1);
    --emsg_off;
}

static void f_bufwinnr (typval_T *argvars, typval_T *rettv) {
    buf_win_common (argvars, rettv, TRUE);
}

static void f_byte2line (typval_T *argvars, typval_T *rettv) {
    long  boff = 0;
    boff = get_tv_number (&argvars[0]) - 1;
    if (boff < 0)
        rettv->vval.v_number = -1;
    else
        rettv->vval.v_number = ml_find_line_or_offset (curbuf, (linenr_T) 0, &boff);
}

static void f_byteidx (typval_T *argvars, typval_T *rettv) {
    byteidx (argvars, rettv, FALSE);
}

static void byteidx (typval_T *argvars, typval_T *rettv, int comp) {
    char_u *str;
    varnumber_T idx;
    str = get_tv_string_chk (&argvars[0]);
    idx = get_tv_number_chk (&argvars[1], NULL);
    rettv->vval.v_number = -1;
    if (str == NULL || idx < 0)
        return;
    if ((size_t) idx <= STRLEN (str))
        rettv->vval.v_number = idx;
}

static void f_byteidxcomp (typval_T *argvars, typval_T *rettv) {
    byteidx (argvars, rettv, TRUE);
}

static void f_call (typval_T *argvars, typval_T *rettv) {
    char_u *func;
    partial_T *partial = NULL;
    dict_T *selfdict = NULL;
    if (argvars[1].v_type != VAR_LIST) {
        EMSG (_ (e_listreq));
        return;
    }
    if (argvars[1].vval.v_list == NULL)
        return;
    if (argvars[0].v_type == VAR_FUNC)
        func = argvars[0].vval.v_string;
    else if (argvars[0].v_type == VAR_PARTIAL) {
        partial = argvars[0].vval.v_partial;
        func = partial_name (partial);
    }
    else
        func = get_tv_string (&argvars[0]);
    if (*func == NUL)
        return;
    if (argvars[2].v_type != VAR_UNKNOWN) {
        if (argvars[2].v_type != VAR_DICT) {
            EMSG (_ (e_dictreq));
            return;
        }
        selfdict = argvars[2].vval.v_dict;
    }
    (void) func_call (func, &argvars[1], partial, selfdict, rettv);
}

static void f_ceil (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &f) == OK)
        rettv->vval.v_float = ceil (f);
    else
        rettv->vval.v_float = 0.0;
}

static void f_ch_canread (typval_T *argvars, typval_T *rettv) {
    channel_T *channel = get_channel_arg (&argvars[0], FALSE, FALSE, 0);
    rettv->vval.v_number = 0;
    if (channel != NULL)
        rettv->vval.v_number = channel_has_readahead (channel, PART_SOCK) || channel_has_readahead (channel, PART_OUT) || channel_has_readahead (channel, PART_ERR);
}

static void f_ch_close (typval_T *argvars, typval_T *rettv) {
    channel_T *channel = get_channel_arg (&argvars[0], TRUE, FALSE, 0);
    if (channel != NULL) {
        channel_close (channel, FALSE);
        channel_clear (channel);
    }
}

static void f_ch_close_in (typval_T *argvars, typval_T *rettv) {
    channel_T *channel = get_channel_arg (&argvars[0], TRUE, FALSE, 0);
    if (channel != NULL)
        channel_close_in (channel);
}

static void f_ch_getbufnr (typval_T *argvars, typval_T *rettv) {
    channel_T *channel = get_channel_arg (&argvars[0], FALSE, FALSE, 0);
    rettv->vval.v_number = -1;
    if (channel != NULL) {
        char_u *what = get_tv_string (&argvars[1]);
        int part;
        if (STRCMP (what, "err") == 0)
            part = PART_ERR;
        else if (STRCMP (what, "out") == 0)
            part = PART_OUT;
        else if (STRCMP (what, "in") == 0)
            part = PART_IN;
        else
            part = PART_SOCK;
        if (channel->ch_part[part].ch_bufref.br_buf != NULL)
            rettv->vval.v_number = channel->ch_part[part].ch_bufref.br_buf->b_fnum;
    }
}

static void f_ch_getjob (typval_T *argvars, typval_T *rettv) {
    channel_T *channel = get_channel_arg (&argvars[0], FALSE, FALSE, 0);
    if (channel != NULL) {
        rettv->v_type = VAR_JOB;
        rettv->vval.v_job = channel->ch_job;
        if (channel->ch_job != NULL)
            ++channel->ch_job->jv_refcount;
    }
}

static void f_ch_info (typval_T *argvars, typval_T *rettv) {
    channel_T *channel = get_channel_arg (&argvars[0], FALSE, FALSE, 0);
    if (channel != NULL && rettv_dict_alloc (rettv) != FAIL)
        channel_info (channel, rettv->vval.v_dict);
}

static void f_ch_log (typval_T *argvars, typval_T *rettv) {
    char_u *msg = get_tv_string (&argvars[0]);
    channel_T *channel = NULL;
    if (argvars[1].v_type != VAR_UNKNOWN)
        channel = get_channel_arg (&argvars[1], FALSE, FALSE, 0);
    ch_log (channel, (char *) msg);
}

static void f_ch_logfile (typval_T *argvars, typval_T *rettv) {
    char_u *fname;
    char_u *opt = (char_u *) "";
    char_u buf [NUMBUFLEN];
    if (check_restricted () || check_secure ())
        return;
    fname = get_tv_string (&argvars[0]);
    if (argvars[1].v_type == VAR_STRING)
        opt = get_tv_string_buf (&argvars[1], buf);
    ch_logfile (fname, opt);
}

static void f_ch_open (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_CHANNEL;
    if (check_restricted () || check_secure ())
        return;
    rettv->vval.v_channel = channel_open_func (argvars);
}

static void f_ch_read (typval_T *argvars, typval_T *rettv) {
    common_channel_read (argvars, rettv, FALSE);
}

static void f_ch_readraw (typval_T *argvars, typval_T *rettv) {
    common_channel_read (argvars, rettv, TRUE);
}

static void f_ch_evalexpr (typval_T *argvars, typval_T *rettv) {
    ch_expr_common (argvars, rettv, TRUE);
}

static void f_ch_sendexpr (typval_T *argvars, typval_T *rettv) {
    ch_expr_common (argvars, rettv, FALSE);
}

static void f_ch_evalraw (typval_T *argvars, typval_T *rettv) {
    ch_raw_common (argvars, rettv, TRUE);
}

static void f_ch_sendraw (typval_T *argvars, typval_T *rettv) {
    ch_raw_common (argvars, rettv, FALSE);
}

static void f_ch_setoptions (typval_T *argvars, typval_T *rettv) {
    channel_T *channel;
    jobopt_T opt;
    channel = get_channel_arg (&argvars[0], FALSE, FALSE, 0);
    if (channel == NULL)
        return;
    clear_job_options (& opt);
    if (get_job_options (&argvars[1], &opt, JO_CB_ALL +JO_TIMEOUT_ALL + JO_MODE_ALL, 0) == OK)
        channel_set_options (channel, &opt);
    free_job_options (& opt);
}

static void f_ch_status (typval_T *argvars, typval_T *rettv) {
    channel_T *channel;
    jobopt_T opt;
    int part = -1;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    channel = get_channel_arg (&argvars[0], FALSE, FALSE, 0);
    if (argvars[1].v_type != VAR_UNKNOWN) {
        clear_job_options (& opt);
        if (get_job_options (&argvars[1], &opt, JO_PART, 0) == OK && (opt.jo_set & JO_PART))
            part = opt.jo_part;
    }
    rettv->vval.v_string = vim_strsave ((char_u *) channel_status (channel, part));
}

static void f_changenr (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = curbuf->b_u_seq_cur;
}

static void f_char2nr (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = get_tv_string (&argvars[0])[0];
}

static void f_cindent (typval_T *argvars, typval_T *rettv) {
    pos_T pos;
    linenr_T lnum;
    pos = curwin->w_cursor;
    lnum = get_tv_lnum (argvars);
    if (lnum >= 1 && lnum <= curbuf->b_ml.ml_line_count) {
        curwin->w_cursor.lnum = lnum;
        rettv->vval.v_number = get_c_indent ();
        curwin->w_cursor = pos;
    }
    else
        rettv->vval.v_number = -1;
}

static void f_clearmatches (typval_T *argvars, typval_T *rettv) {
    clear_matches (curwin);
}

static void f_col (typval_T *argvars, typval_T *rettv) {
    colnr_T col = 0;
    pos_T *fp;
    int fnum = curbuf->b_fnum;
    fp = var2fpos (&argvars[0], FALSE, &fnum);
    if (fp != NULL && fnum == curbuf->b_fnum) {
        if (fp->col == MAXCOL) {
            if (fp->lnum <= curbuf->b_ml.ml_line_count)
                col = (colnr_T) STRLEN (ml_get (fp->lnum)) + 1;
            else
                col = MAXCOL;
        }
        else {
            col = fp->col + 1;
            if (virtual_active () && fp == &curwin->w_cursor) {
                char_u *p = ml_get_cursor ();
                if (curwin->w_cursor.coladd >= (colnr_T) chartabsize (p, curwin->w_virtcol - curwin->w_cursor.coladd)) {
                    if (*p != NUL && p[1] == NUL)
                        ++col;
                }
            }
        }
    }
    rettv->vval.v_number = col;
}

static void f_complete (typval_T *argvars, typval_T *rettv) {
    int startcol;
    if ((State & INSERT) == 0) {
        EMSG (_ ("E785: complete() can only be used in Insert mode"));
        return;
    }
    if (!undo_allowed ())
        return;
    if (argvars[1].v_type != VAR_LIST || argvars[1].vval.v_list == NULL) {
        EMSG (_ (e_invarg));
        return;
    }
    startcol = (int) get_tv_number_chk (&argvars[0], NULL);
    if (startcol <= 0)
        return;
    set_completion (startcol - 1, argvars [1].vval.v_list);
}

static void f_complete_add (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = ins_compl_add_tv (&argvars[0], 0);
}

static void f_complete_check (typval_T *argvars, typval_T *rettv) {
    int saved = RedrawingDisabled;
    RedrawingDisabled = 0;
    ins_compl_check_keys (0, TRUE);
    rettv->vval.v_number = compl_interrupted;
    RedrawingDisabled = saved;
}

static void f_confirm (typval_T *argvars, typval_T *rettv) {
    char_u *message;
    char_u *buttons = NULL;
    char_u buf [NUMBUFLEN];
    char_u buf2 [NUMBUFLEN];
    int def = 1;
    int type = VIM_GENERIC;
    char_u *typestr;
    int error = FALSE;
    message = get_tv_string_chk (&argvars[0]);
    if (message == NULL)
        error = TRUE;
    if (argvars[1].v_type != VAR_UNKNOWN) {
        buttons = get_tv_string_buf_chk (&argvars[1], buf);
        if (buttons == NULL)
            error = TRUE;
        if (argvars[2].v_type != VAR_UNKNOWN) {
            def = (int) get_tv_number_chk (&argvars[2], &error);
            if (argvars[3].v_type != VAR_UNKNOWN) {
                typestr = get_tv_string_buf_chk (&argvars[3], buf2);
                if (typestr == NULL)
                    error = TRUE;
                else {
                    switch (TOUPPER_ASC (*typestr)) {
                    case 'E' :
                        type = VIM_ERROR;
                        break;
                    case 'Q' :
                        type = VIM_QUESTION;
                        break;
                    case 'I' :
                        type = VIM_INFO;
                        break;
                    case 'W' :
                        type = VIM_WARNING;
                        break;
                    case 'G' :
                        type = VIM_GENERIC;
                        break;
                    }
                }
            }
        }
    }
    if (buttons == NULL || *buttons == NUL)
        buttons = (char_u *) _ ("&Ok");
    if (!error)
        rettv->vval.v_number = do_dialog (type, NULL, message, buttons, def, NULL, FALSE);
}

static void f_copy (typval_T *argvars, typval_T *rettv) {
    item_copy (& argvars [0], rettv, FALSE, 0);
}

static void f_cos (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &f) == OK)
        rettv->vval.v_float = cos (f);
    else
        rettv->vval.v_float = 0.0;
}

static void f_cosh (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &f) == OK)
        rettv->vval.v_float = cosh (f);
    else
        rettv->vval.v_float = 0.0;
}

static void f_count (typval_T *argvars, typval_T *rettv) {
    long  n = 0;
    int ic = FALSE;
    int error = FALSE;
    if (argvars[2].v_type != VAR_UNKNOWN)
        ic = (int) get_tv_number_chk (&argvars[2], &error);
    if (argvars[0].v_type == VAR_STRING) {
        char_u *expr = get_tv_string_chk (&argvars[1]);
        char_u *p = argvars[0].vval.v_string;
        char_u *next;
        if (!error && expr != NULL && *expr != NUL && p != NULL) {
            if (ic) {
                size_t len = STRLEN (expr);
                while (*p != NUL) {
                    if (MB_STRNICMP (p, expr, len) == 0) {
                        ++n;
                        p += len;
                    }
                    else
                        MB_PTR_ADV (p);
                }
            }
            else
                while ((next = (char_u *) strstr ((char *) p, (char *) expr)) != NULL) {
                    ++n;
                    p = next + STRLEN (expr);
                }
        }
    }
    else if (argvars[0].v_type == VAR_LIST) {
        listitem_T *li;
        list_T *l;
        long  idx;
        if ((l = argvars[0].vval.v_list) != NULL) {
            li = l->lv_first;
            if (argvars[2].v_type != VAR_UNKNOWN) {
                if (argvars[3].v_type != VAR_UNKNOWN) {
                    idx = (long ) get_tv_number_chk (&argvars[3], &error);
                    if (!error) {
                        li = list_find (l, idx);
                        if (li == NULL)
                            EMSGN (_ (e_listidx), idx);
                    }
                }
                if (error)
                    li = NULL;
            }
            for (; li != NULL; li = li->li_next)
                if (tv_equal (&li->li_tv, &argvars[1], ic, FALSE))
                    ++n;
        }
    }
    else if (argvars[0].v_type == VAR_DICT) {
        int todo;
        dict_T *d;
        hashitem_T *hi;
        if ((d = argvars[0].vval.v_dict) != NULL) {
            if (argvars[2].v_type != VAR_UNKNOWN) {
                if (argvars[3].v_type != VAR_UNKNOWN)
                    EMSG (_ (e_invarg));
            }
            todo = error ? 0 : (int) d->dv_hashtab.ht_used;
            for (hi = d->dv_hashtab.ht_array; todo > 0; ++hi) {
                if (!HASHITEM_EMPTY (hi)) {
                    --todo;
                    if (tv_equal (&HI2DI (hi)->di_tv, &argvars[1], ic, FALSE))
                        ++n;
                }
            }
        }
    }
    else
        EMSG2 (_ (e_listdictarg), "count()");
    rettv->vval.v_number = n;
}

static void f_cscope_connection (typval_T *argvars, typval_T *rettv) {
}

static void f_cursor (typval_T *argvars, typval_T *rettv) {
    long  line, col;
    long  coladd = 0;
    int set_curswant = TRUE;
    rettv->vval.v_number = -1;
    if (argvars[1].v_type == VAR_UNKNOWN) {
        pos_T pos;
        colnr_T curswant = -1;
        if (list2fpos (argvars, &pos, NULL, &curswant) == FAIL) {
            EMSG (_ (e_invarg));
            return;
        }
        line = pos.lnum;
        col = pos.col;
        coladd = pos.coladd;
        if (curswant >= 0) {
            curwin->w_curswant = curswant - 1;
            set_curswant = FALSE;
        }
    }
    else {
        line = get_tv_lnum (argvars);
        col = (long ) get_tv_number_chk (&argvars[1], NULL);
        if (argvars[2].v_type != VAR_UNKNOWN)
            coladd = (long ) get_tv_number_chk (&argvars[2], NULL);
    }
    if (line < 0 || col < 0 || coladd < 0)
        return;
    if (line > 0)
        curwin->w_cursor.lnum = line;
    if (col > 0)
        curwin->w_cursor.col = col - 1;
    curwin->w_cursor.coladd = coladd;
    check_cursor ();
    curwin->w_set_curswant = set_curswant;
    rettv->vval.v_number = 0;
}

static void f_deepcopy (typval_T *argvars, typval_T *rettv) {
    int noref = 0;
    int copyID;
    if (argvars[1].v_type != VAR_UNKNOWN)
        noref = (int) get_tv_number_chk (&argvars[1], NULL);
    if (noref < 0 || noref > 1)
        EMSG (_ (e_invarg));
    else {
        copyID = get_copyID ();
        item_copy (& argvars [0], rettv, TRUE, noref == 0 ? copyID : 0);
    }
}

static void f_delete (typval_T *argvars, typval_T *rettv) {
    char_u nbuf [NUMBUFLEN];
    char_u *name;
    char_u *flags;
    rettv->vval.v_number = -1;
    if (check_restricted () || check_secure ())
        return;
    name = get_tv_string (&argvars[0]);
    if (name == NULL || *name == NUL) {
        EMSG (_ (e_invarg));
        return;
    }
    if (argvars[1].v_type != VAR_UNKNOWN)
        flags = get_tv_string_buf (&argvars[1], nbuf);
    else
        flags = (char_u *) "";
    if (*flags == NUL)
        rettv->vval.v_number = mch_remove (name) == 0 ? 0 : -1;
    else if (STRCMP (flags, "d") == 0)
        rettv->vval.v_number = mch_rmdir (name) == 0 ? 0 : -1;
    else if (STRCMP (flags, "rf") == 0)
        rettv->vval.v_number = delete_recursive (name);
    else
        EMSG2 (_ (e_invexpr2), flags);
}

static void f_did_filetype (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = did_filetype;
}

static void f_diff_filler (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = diff_check_fill (curwin, get_tv_lnum (argvars));
}

static void f_diff_hlID (typval_T *argvars, typval_T *rettv) {
    linenr_T lnum = get_tv_lnum (argvars);
    static linenr_T prev_lnum = 0;
    static varnumber_T changedtick = 0;
    static int fnum = 0;
    static int change_start = 0;
    static int change_end = 0;
    static hlf_T hlID = (hlf_T) 0;
    int filler_lines;
    int col;
    if (lnum < 0)
        lnum = 0;
    if (lnum != prev_lnum || changedtick != CHANGEDTICK (curbuf) || fnum != curbuf->b_fnum) {
        filler_lines = diff_check (curwin, lnum);
        if (filler_lines < 0) {
            if (filler_lines == -1) {
                change_start = MAXCOL;
                change_end = -1;
                if (diff_find_change (curwin, lnum, &change_start, &change_end))
                    hlID = HLF_ADD;
                else
                    hlID = HLF_CHD;
            }
            else
                hlID = HLF_ADD;
        }
        else
            hlID = (hlf_T) 0;
        prev_lnum = lnum;
        changedtick = CHANGEDTICK (curbuf);
        fnum = curbuf->b_fnum;
    }
    if (hlID == HLF_CHD || hlID == HLF_TXD) {
        col = get_tv_number (&argvars[1]) - 1;
        if (col >= change_start && col <= change_end)
            hlID = HLF_TXD;
        else
            hlID = HLF_CHD;
    }
    rettv->vval.v_number = hlID == (hlf_T) 0 ? 0 : (int) hlID;
}

static void f_empty (typval_T *argvars, typval_T *rettv) {
    int n = FALSE;
    switch (argvars[0].v_type) {
    case VAR_STRING :
    case VAR_FUNC :
        n = argvars[0].vval.v_string == NULL || *argvars[0].vval.v_string == NUL;
        break;
    case VAR_PARTIAL :
        n = FALSE;
        break;
    case VAR_NUMBER :
        n = argvars[0].vval.v_number == 0;
        break;
    case VAR_FLOAT :
        n = argvars[0].vval.v_float == 0.0;
        break;
    case VAR_LIST :
        n = argvars[0].vval.v_list == NULL || argvars[0].vval.v_list->lv_first == NULL;
        break;
    case VAR_DICT :
        n = argvars[0].vval.v_dict == NULL || argvars[0].vval.v_dict->dv_hashtab.ht_used == 0;
        break;
    case VAR_SPECIAL :
        n = argvars[0].vval.v_number != VVAL_TRUE;
        break;
    case VAR_JOB :
        n = argvars[0].vval.v_job == NULL || argvars[0].vval.v_job->jv_status != JOB_STARTED;
        break;
    case VAR_CHANNEL :
        n = argvars[0].vval.v_channel == NULL || !channel_is_open (argvars[0].vval.v_channel);
        break;
    case VAR_UNKNOWN :
        internal_error ("f_empty(UNKNOWN)");
        n = TRUE;
        break;
    }
    rettv->vval.v_number = n;
}

static void f_escape (typval_T *argvars, typval_T *rettv) {
    char_u buf [NUMBUFLEN];
    rettv->vval.v_string = vim_strsave_escaped (get_tv_string (&argvars[0]), get_tv_string_buf (&argvars[1], buf));
    rettv->v_type = VAR_STRING;
}

static void f_eval (typval_T *argvars, typval_T *rettv) {
    char_u *s, *p;
    s = get_tv_string_chk (&argvars[0]);
    if (s != NULL)
        s = skipwhite (s);
    p = s;
    if (s == NULL || eval1 (&s, rettv, TRUE) == FAIL) {
        if (p != NULL && !aborting ())
            EMSG2 (_ (e_invexpr2), p);
        need_clr_eos = FALSE;
        rettv->v_type = VAR_NUMBER;
        rettv->vval.v_number = 0;
    }
    else if (*s != NUL)
        EMSG (_ (e_trailing));
}

static void f_eventhandler (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = vgetc_busy;
}

static void f_executable (typval_T *argvars, typval_T *rettv) {
    char_u *name = get_tv_string (&argvars[0]);
    rettv->vval.v_number = mch_can_exe (name, NULL, TRUE) || (gettail (name) != name && mch_can_exe (name, NULL, FALSE));
}

static void f_execute (typval_T *argvars, typval_T *rettv) {
    char_u *cmd = NULL;
    list_T *list = NULL;
    int save_msg_silent = msg_silent;
    int save_emsg_silent = emsg_silent;
    int save_emsg_noredir = emsg_noredir;
    int save_redir_execute = redir_execute;
    int save_redir_off = redir_off;
    garray_T save_ga;
    rettv->vval.v_string = NULL;
    rettv->v_type = VAR_STRING;
    if (argvars[0].v_type == VAR_LIST) {
        list = argvars[0].vval.v_list;
        if (list == NULL || list->lv_first == NULL)
            return;
        ++list->lv_refcount;
    }
    else {
        cmd = get_tv_string_chk (&argvars[0]);
        if (cmd == NULL)
            return;
    }
    if (argvars[1].v_type != VAR_UNKNOWN) {
        char_u buf [NUMBUFLEN];
        char_u *s = get_tv_string_buf_chk (&argvars[1], buf);
        if (s == NULL)
            return;
        if (STRNCMP (s, "silent", 6) == 0)
            ++msg_silent;
        if (STRCMP (s, "silent!") == 0) {
            emsg_silent = TRUE;
            emsg_noredir = TRUE;
        }
    }
    else
        ++msg_silent;
    if (redir_execute)
        save_ga = redir_execute_ga;
    ga_init2 (& redir_execute_ga, (int) sizeof (char), 500);
    redir_execute = TRUE;
    redir_off = FALSE;
    if (cmd != NULL)
        do_cmdline_cmd (cmd);
    else {
        listitem_T *item = list->lv_first;
        do_cmdline (NULL, get_list_line, (void *) & item, DOCMD_NOWAIT | DOCMD_VERBOSE | DOCMD_REPEAT | DOCMD_KEYTYPED);
        --list->lv_refcount;
    }
    if (ga_grow (&redir_execute_ga, 1) == OK) {
        ((char *) redir_execute_ga.ga_data)[redir_execute_ga.ga_len] = NUL;
        rettv->vval.v_string = redir_execute_ga.ga_data;
    }
    else {
        ga_clear (& redir_execute_ga);
        rettv->vval.v_string = NULL;
    }
    msg_silent = save_msg_silent;
    emsg_silent = save_emsg_silent;
    emsg_noredir = save_emsg_noredir;
    redir_execute = save_redir_execute;
    if (redir_execute)
        redir_execute_ga = save_ga;
    redir_off = save_redir_off;
    msg_col = 0;
}

static char_u *get_list_line (int c, void *cookie, int indent) {
    listitem_T **p = (listitem_T **) cookie;
    listitem_T *item = *p;
    char_u buf [NUMBUFLEN];
    char_u *s;
    if (item == NULL)
        return NULL;
    s = get_tv_string_buf_chk (&item->li_tv, buf);
    *p = item->li_next;
    return s == NULL ? NULL : vim_strsave (s);
}

static void f_exepath (typval_T *argvars, typval_T *rettv) {
    char_u *p = NULL;
    (void) mch_can_exe (get_tv_string (&argvars[0]), &p, TRUE);
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = p;
}

static void f_exists (typval_T *argvars, typval_T *rettv) {
    char_u *p;
    int n = FALSE;
    p = get_tv_string (&argvars[0]);
    if (*p == '$') {
        if (mch_getenv (p +1) != NULL)
            n = TRUE;
        else {
            p = expand_env_save (p);
            if (p != NULL && *p != '$')
                n = TRUE;
            vim_free (p);
        }
    }
    else if (*p == '&' || *p == '+') {
        n = (get_option_tv (&p, NULL, TRUE) == OK);
        if (*skipwhite (p) != NUL)
            n = FALSE;
    }
    else if (*p == '*') {
        n = function_exists (p +1, FALSE);
    }
    else if (*p == ':') {
        n = cmd_exists (p +1);
    }
    else if (*p == '#') {
        if (p[1] == '#')
            n = autocmd_supported (p +2);
        else
            n = au_exists (p +1);
    }
    else {
        n = var_exists (p);
    }
    rettv->vval.v_number = n;
}

static void f_exp (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &f) == OK)
        rettv->vval.v_float = exp (f);
    else
        rettv->vval.v_float = 0.0;
}

static void f_expand (typval_T *argvars, typval_T *rettv) {
    char_u *s;
    int len;
    char_u *errormsg;
    int options = WILD_SILENT | WILD_USE_NL | WILD_LIST_NOTFOUND;
    expand_T xpc;
    int error = FALSE;
    char_u *result;
    rettv->v_type = VAR_STRING;
    if (argvars[1].v_type != VAR_UNKNOWN && argvars[2].v_type != VAR_UNKNOWN && get_tv_number_chk (&argvars[2], &error) && !error) {
        rettv_list_set (rettv, NULL);
    }
    s = get_tv_string (&argvars[0]);
    if (*s == '%' || *s == '#' || *s == '<') {
        ++emsg_off;
        result = eval_vars (s, s, &len, NULL, &errormsg, NULL);
        --emsg_off;
        if (rettv->v_type == VAR_LIST) {
            if (rettv_list_alloc (rettv) != FAIL && result != NULL)
                list_append_string (rettv->vval.v_list, result, -1);
            else
                vim_free (result);
        }
        else
            rettv->vval.v_string = result;
    }
    else {
        if (argvars[1].v_type != VAR_UNKNOWN && get_tv_number_chk (&argvars[1], &error))
            options |= WILD_KEEP_ALL;
        if (!error) {
            ExpandInit (& xpc);
            xpc.xp_context = EXPAND_FILES;
            if (p_wic)
                options += WILD_ICASE;
            if (rettv->v_type == VAR_STRING)
                rettv->vval.v_string = ExpandOne (&xpc, s, NULL, options, WILD_ALL);
            else if (rettv_list_alloc (rettv) != FAIL) {
                int i;
                ExpandOne (& xpc, s, NULL, options, WILD_ALL_KEEP);
                for (i = 0; i < xpc.xp_numfiles; i++)
                    list_append_string (rettv->vval.v_list, xpc.xp_files[i], -1);
                ExpandCleanup (& xpc);
            }
        }
        else
            rettv->vval.v_string = NULL;
    }
}

static void f_extend (typval_T *argvars, typval_T *rettv) {
    char_u *arg_errmsg = (char_u *) N_ ("extend() argument");
    if (argvars[0].v_type == VAR_LIST && argvars[1].v_type == VAR_LIST) {
        list_T *l1, *l2;
        listitem_T *item;
        long  before;
        int error = FALSE;
        l1 = argvars[0].vval.v_list;
        l2 = argvars[1].vval.v_list;
        if (l1 != NULL && !tv_check_lock (l1->lv_lock, arg_errmsg, TRUE) && l2 != NULL) {
            if (argvars[2].v_type != VAR_UNKNOWN) {
                before = (long ) get_tv_number_chk (&argvars[2], &error);
                if (error)
                    return;
                if (before == l1->lv_len)
                    item = NULL;
                else {
                    item = list_find (l1, before);
                    if (item == NULL) {
                        EMSGN (_ (e_listidx), before);
                        return;
                    }
                }
            }
            else
                item = NULL;
            list_extend (l1, l2, item);
            copy_tv (& argvars [0], rettv);
        }
    }
    else if (argvars[0].v_type == VAR_DICT && argvars[1].v_type == VAR_DICT) {
        dict_T *d1, *d2;
        char_u *action;
        int i;
        d1 = argvars[0].vval.v_dict;
        d2 = argvars[1].vval.v_dict;
        if (d1 != NULL && !tv_check_lock (d1->dv_lock, arg_errmsg, TRUE) && d2 != NULL) {
            if (argvars[2].v_type != VAR_UNKNOWN) {
                static char * (av []) = {"keep", "force", "error"};
                action = get_tv_string_chk (&argvars[2]);
                if (action == NULL)
                    return;
                for (i = 0; i < 3; ++i)
                    if (STRCMP (action, av[i]) == 0)
                        break;
                if (i == 3) {
                    EMSG2 (_ (e_invarg2), action);
                    return;
                }
            }
            else
                action = (char_u *) "force";
            dict_extend (d1, d2, action);
            copy_tv (& argvars [0], rettv);
        }
    }
    else
        EMSG2 (_ (e_listdictarg), "extend()");
}

static void f_feedkeys (typval_T *argvars, typval_T *rettv) {
    int remap = TRUE;
    int insert = FALSE;
    char_u *keys, *flags;
    char_u nbuf [NUMBUFLEN];
    int typed = FALSE;
    int execute = FALSE;
    int dangerous = FALSE;
    char_u *keys_esc;
    if (check_secure ())
        return;
    keys = get_tv_string (&argvars[0]);
    if (argvars[1].v_type != VAR_UNKNOWN) {
        flags = get_tv_string_buf (&argvars[1], nbuf);
        for (; *flags != NUL; ++flags) {
            switch (*flags) {
            case 'n' :
                remap = FALSE;
                break;
            case 'm' :
                remap = TRUE;
                break;
            case 't' :
                typed = TRUE;
                break;
            case 'i' :
                insert = TRUE;
                break;
            case 'x' :
                execute = TRUE;
                break;
            case '!' :
                dangerous = TRUE;
                break;
            }
        }
    }
    if (*keys != NUL || execute) {
        keys_esc = vim_strsave_escape_csi (keys);
        if (keys_esc != NULL) {
            ins_typebuf (keys_esc, (remap ? REMAP_YES : REMAP_NONE), insert ? 0 : typebuf.tb_len, ! typed, FALSE);
            vim_free (keys_esc);
            if (vgetc_busy || timer_busy)
                typebuf_was_filled = TRUE;
            if (execute) {
                int save_msg_scroll = msg_scroll;
                msg_scroll = FALSE;
                if (term_use_loop ())
                    terminal_loop (FALSE);
                else {
                    if (!dangerous)
                        ++ex_normal_busy;
                    exec_normal (TRUE);
                    if (!dangerous)
                        --ex_normal_busy;
                }
                msg_scroll |= save_msg_scroll;
            }
        }
    }
}

static void f_filereadable (typval_T *argvars, typval_T *rettv) {
    int fd;
    char_u *p;
    int n;

    # define O_NONBLOCK 0
    p = get_tv_string (&argvars[0]);
    if (*p && !mch_isdir (p) && (fd = mch_open ((char *) p, O_RDONLY | O_NONBLOCK, 0)) >= 0) {
        n = TRUE;
        close (fd);
    }
    else
        n = FALSE;
    rettv->vval.v_number = n;
}

static void f_filewritable (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = filewritable (get_tv_string (&argvars[0]));
}

static void f_filter (typval_T *argvars, typval_T *rettv) {
    filter_map (argvars, rettv, FALSE);
}

static void f_finddir (typval_T *argvars, typval_T *rettv) {
    findfilendir (argvars, rettv, FINDFILE_DIR);
}

static void findfilendir (typval_T *argvars, typval_T *rettv, int find_what) {
    char_u *fname;
    char_u *fresult = NULL;
    char_u *path = *curbuf->b_p_path == NUL ? p_path : curbuf->b_p_path;
    char_u *p;
    char_u pathbuf [NUMBUFLEN];
    int count = 1;
    int first = TRUE;
    int error = FALSE;
    rettv->vval.v_string = NULL;
    rettv->v_type = VAR_STRING;
    fname = get_tv_string (&argvars[0]);
    if (argvars[1].v_type != VAR_UNKNOWN) {
        p = get_tv_string_buf_chk (&argvars[1], pathbuf);
        if (p == NULL)
            error = TRUE;
        else {
            if (*p != NUL)
                path = p;
            if (argvars[2].v_type != VAR_UNKNOWN)
                count = (int) get_tv_number_chk (&argvars[2], &error);
        }
    }
    if (count < 0 && rettv_list_alloc (rettv) == FAIL)
        error = TRUE;
    if (*fname != NUL && !error) {
        do {
            if (rettv->v_type == VAR_STRING || rettv->v_type == VAR_LIST)
                vim_free (fresult);
            fresult = find_file_in_path_option (first ? fname : NULL, first ? (int) STRLEN (fname) : 0, 0, first, path, find_what, curbuf->b_ffname, find_what == FINDFILE_DIR ? (char_u *) "" : curbuf->b_p_sua);
            first = FALSE;
            if (fresult != NULL && rettv->v_type == VAR_LIST)
                list_append_string (rettv->vval.v_list, fresult, -1);
        }
        while ((rettv->v_type == VAR_LIST || --count > 0) && fresult != NULL);
    }
    if (rettv->v_type == VAR_STRING)
        rettv->vval.v_string = fresult;
}

static void f_findfile (typval_T *argvars, typval_T *rettv) {
    findfilendir (argvars, rettv, FINDFILE_FILE);
}

static void f_float2nr (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    if (get_float_arg (argvars, &f) == OK) {
        if (f <= -VARNUM_MAX + DBL_EPSILON)
            rettv->vval.v_number = -VARNUM_MAX;
        else if (f >= VARNUM_MAX - DBL_EPSILON)
            rettv->vval.v_number = VARNUM_MAX;
        else
            rettv->vval.v_number = (varnumber_T) f;
    }
}

static void f_floor (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &f) == OK)
        rettv->vval.v_float = floor (f);
    else
        rettv->vval.v_float = 0.0;
}

static void f_fmod (typval_T *argvars, typval_T *rettv) {
    float_T fx = 0.0, fy = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &fx) == OK && get_float_arg (&argvars[1], &fy) == OK)
        rettv->vval.v_float = fmod (fx, fy);
    else
        rettv->vval.v_float = 0.0;
}

static void f_fnameescape (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_string = vim_strsave_fnameescape (get_tv_string (&argvars[0]), FALSE);
    rettv->v_type = VAR_STRING;
}

static void f_fnamemodify (typval_T *argvars, typval_T *rettv) {
    char_u *fname;
    char_u *mods;
    int usedlen = 0;
    int len;
    char_u *fbuf = NULL;
    char_u buf [NUMBUFLEN];
    fname = get_tv_string_chk (&argvars[0]);
    mods = get_tv_string_buf_chk (&argvars[1], buf);
    if (fname == NULL || mods == NULL)
        fname = NULL;
    else {
        len = (int) STRLEN (fname);
        (void) modify_fname (mods, &usedlen, &fname, &fbuf, &len);
    }
    rettv->v_type = VAR_STRING;
    if (fname == NULL)
        rettv->vval.v_string = NULL;
    else
        rettv->vval.v_string = vim_strnsave (fname, len);
    vim_free (fbuf);
}

static void f_foldclosed (typval_T *argvars, typval_T *rettv) {
    foldclosed_both (argvars, rettv, FALSE);
}

static void foldclosed_both (typval_T *argvars, typval_T *rettv, int end) {
    linenr_T lnum;
    linenr_T first, last;
    lnum = get_tv_lnum (argvars);
    if (lnum >= 1 && lnum <= curbuf->b_ml.ml_line_count) {
        if (hasFoldingWin (curwin, lnum, &first, &last, FALSE, NULL)) {
            if (end)
                rettv->vval.v_number = (varnumber_T) last;
            else
                rettv->vval.v_number = (varnumber_T) first;
            return;
        }
    }
    rettv->vval.v_number = -1;
}

static void f_foldclosedend (typval_T *argvars, typval_T *rettv) {
    foldclosed_both (argvars, rettv, TRUE);
}

static void f_foldlevel (typval_T *argvars, typval_T *rettv) {
    linenr_T lnum;
    lnum = get_tv_lnum (argvars);
    if (lnum >= 1 && lnum <= curbuf->b_ml.ml_line_count)
        rettv->vval.v_number = foldLevel (lnum);
}

static void f_foldtext (typval_T *argvars, typval_T *rettv) {
    linenr_T foldstart;
    linenr_T foldend;
    char_u *dashes;
    linenr_T lnum;
    char_u *s;
    char_u *r;
    int len;
    char *txt;
    long  count;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    foldstart = (linenr_T) get_vim_var_nr (VV_FOLDSTART);
    foldend = (linenr_T) get_vim_var_nr (VV_FOLDEND);
    dashes = get_vim_var_str (VV_FOLDDASHES);
    if (foldstart > 0 && foldend <= curbuf->b_ml.ml_line_count && dashes != NULL) {
        for (lnum = foldstart; lnum < foldend; ++lnum)
            if (!linewhite (lnum))
                break;
        s = skipwhite (ml_get (lnum));
        if (s[0] == '/' && (s[1] == '*' || s[1] == '/')) {
            s = skipwhite (s +2);
            if (*skipwhite (s) == NUL && lnum + 1 < (linenr_T) get_vim_var_nr (VV_FOLDEND)) {
                s = skipwhite (ml_get (lnum + 1));
                if (*s == '*')
                    s = skipwhite (s +1);
            }
        }
        count = (long ) (foldend - foldstart + 1);
        txt = NGETTEXT ("+-%s%3ld line: ", "+-%s%3ld lines: ", count);
        r = alloc ((unsigned ) (STRLEN (txt) + STRLEN (dashes) + 20 + STRLEN (s)));
        if (r != NULL) {
            sprintf ((char *) r, txt, dashes, count);
            len = (int) STRLEN (r);
            STRCAT (r, s);
            foldtext_cleanup (r + len);
            rettv->vval.v_string = r;
        }
    }
}

static void f_foldtextresult (typval_T *argvars, typval_T *rettv) {
    linenr_T lnum;
    char_u *text;
    char_u buf [FOLD_TEXT_LEN];
    foldinfo_T foldinfo;
    int fold_count;
    static int entered = FALSE;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    if (entered)
        return;
    entered = TRUE;
    lnum = get_tv_lnum (argvars);
    if (lnum < 0)
        lnum = 0;
    fold_count = foldedCount (curwin, lnum, &foldinfo);
    if (fold_count > 0) {
        text = get_foldtext (curwin, lnum, lnum +fold_count - 1, &foldinfo, buf);
        if (text == buf)
            text = vim_strsave (text);
        rettv->vval.v_string = text;
    }
    entered = FALSE;
}

static void f_foreground (typval_T *argvars, typval_T *rettv) {
    if (gui.in_use)
        gui_mch_set_foreground ();
}

static void f_funcref (typval_T *argvars, typval_T *rettv) {
    common_function (argvars, rettv, TRUE);
}

static void common_function (typval_T *argvars, typval_T *rettv, int is_funcref) {
    char_u *s;
    char_u *name;
    int use_string = FALSE;
    partial_T *arg_pt = NULL;
    char_u *trans_name = NULL;
    if (argvars[0].v_type == VAR_FUNC) {
        s = argvars[0].vval.v_string;
    }
    else if (argvars[0].v_type == VAR_PARTIAL && argvars[0].vval.v_partial != NULL) {
        arg_pt = argvars[0].vval.v_partial;
        s = partial_name (arg_pt);
    }
    else {
        s = get_tv_string (&argvars[0]);
        use_string = TRUE;
    }
    if ((use_string && vim_strchr (s, AUTOLOAD_CHAR) == NULL) || is_funcref) {
        name = s;
        trans_name = trans_function_name (&name, FALSE, TFN_INT | TFN_QUIET | TFN_NO_AUTOLOAD | TFN_NO_DEREF, NULL, NULL);
        if (*name != NUL)
            s = NULL;
    }
    if (s == NULL || *s == NUL || (use_string && VIM_ISDIGIT (*s)) || (is_funcref && trans_name == NULL))
        EMSG2 (_ (e_invarg2), use_string ? get_tv_string (&argvars[0]) : s);
    else if (trans_name != NULL && (is_funcref ? find_func (trans_name) == NULL : !translated_function_exists (trans_name)))
        EMSG2 (_ ("E700: Unknown function: %s"), s);
    else {
        int dict_idx = 0;
        int arg_idx = 0;
        list_T *list = NULL;
        if (STRNCMP (s, "s:", 2) == 0 || STRNCMP (s, "<SID>", 5) == 0) {
            char sid_buf [25];
            int off = *s == 's' ? 2 : 5;
            sprintf (sid_buf, "<SNR>%ld_", (long) current_SID);
            name = alloc ((int) (STRLEN (sid_buf) + STRLEN (s +off) + 1));
            if (name != NULL) {
                STRCPY (name, sid_buf);
                STRCAT (name, s + off);
            }
        }
        else
            name = vim_strsave (s);
        if (argvars[1].v_type != VAR_UNKNOWN) {
            if (argvars[2].v_type != VAR_UNKNOWN) {
                arg_idx = 1;
                dict_idx = 2;
            }
            else if (argvars[1].v_type == VAR_DICT)
                dict_idx = 1;
            else
                arg_idx = 1;
            if (dict_idx > 0) {
                if (argvars[dict_idx].v_type != VAR_DICT) {
                    EMSG (_ ("E922: expected a dict"));
                    vim_free (name);
                    goto theend;
                }
                if (argvars[dict_idx].vval.v_dict == NULL)
                    dict_idx = 0;
            }
            if (arg_idx > 0) {
                if (argvars[arg_idx].v_type != VAR_LIST) {
                    EMSG (_ ("E923: Second argument of function() must be a list or a dict"));
                    vim_free (name);
                    goto theend;
                }
                list = argvars[arg_idx].vval.v_list;
                if (list == NULL || list->lv_len == 0)
                    arg_idx = 0;
            }
        }
        if (dict_idx > 0 || arg_idx > 0 || arg_pt != NULL || is_funcref) {
            partial_T *pt = (partial_T *) alloc_clear (sizeof (partial_T));
            if (pt == NULL)
                vim_free (name);
            else {
                if (arg_idx > 0 || (arg_pt != NULL && arg_pt->pt_argc > 0)) {
                    listitem_T *li;
                    int i = 0;
                    int arg_len = 0;
                    int lv_len = 0;
                    if (arg_pt != NULL)
                        arg_len = arg_pt->pt_argc;
                    if (list != NULL)
                        lv_len = list->lv_len;
                    pt->pt_argc = arg_len + lv_len;
                    pt->pt_argv = (typval_T *) alloc (sizeof (typval_T) * pt->pt_argc);
                    if (pt->pt_argv == NULL) {
                        vim_free (pt);
                        vim_free (name);
                        goto theend;
                    }
                    for (i = 0; i < arg_len; i++)
                        copy_tv (&arg_pt->pt_argv[i], &pt->pt_argv[i]);
                    if (lv_len > 0)
                        for (li = list->lv_first; li != NULL; li = li->li_next)
                            copy_tv (&li->li_tv, &pt->pt_argv[i++]);
                }
                if (dict_idx > 0) {
                    pt->pt_dict = argvars[dict_idx].vval.v_dict;
                    ++pt->pt_dict->dv_refcount;
                }
                else if (arg_pt != NULL) {
                    pt->pt_dict = arg_pt->pt_dict;
                    pt->pt_auto = arg_pt->pt_auto;
                    if (pt->pt_dict != NULL)
                        ++pt->pt_dict->dv_refcount;
                }
                pt->pt_refcount = 1;
                if (arg_pt != NULL && arg_pt->pt_func != NULL) {
                    pt->pt_func = arg_pt->pt_func;
                    func_ptr_ref (pt -> pt_func);
                    vim_free (name);
                }
                else if (is_funcref) {
                    pt->pt_func = find_func (trans_name);
                    func_ptr_ref (pt -> pt_func);
                    vim_free (name);
                }
                else {
                    pt->pt_name = name;
                    func_ref (name);
                }
            }
            rettv->v_type = VAR_PARTIAL;
            rettv->vval.v_partial = pt;
        }
        else {
            rettv->v_type = VAR_FUNC;
            rettv->vval.v_string = name;
            func_ref (name);
        }
    }
theend :
    vim_free (trans_name);
}

static void f_function (typval_T *argvars, typval_T *rettv) {
    common_function (argvars, rettv, FALSE);
}

static void f_garbagecollect (typval_T *argvars, typval_T *rettv) {
    want_garbage_collect = TRUE;
    if (argvars[0].v_type != VAR_UNKNOWN && get_tv_number (&argvars[0]) == 1)
        garbage_collect_at_exit = TRUE;
}

static void f_get (typval_T *argvars, typval_T *rettv) {
    listitem_T *li;
    list_T *l;
    dictitem_T *di;
    dict_T *d;
    typval_T *tv = NULL;
    if (argvars[0].v_type == VAR_LIST) {
        if ((l = argvars[0].vval.v_list) != NULL) {
            int error = FALSE;
            li = list_find (l, (long ) get_tv_number_chk (&argvars[1], &error));
            if (!error && li != NULL)
                tv = &li->li_tv;
        }
    }
    else if (argvars[0].v_type == VAR_DICT) {
        if ((d = argvars[0].vval.v_dict) != NULL) {
            di = dict_find (d, get_tv_string (&argvars[1]), -1);
            if (di != NULL)
                tv = &di->di_tv;
        }
    }
    else if (argvars[0].v_type == VAR_PARTIAL || argvars[0].v_type == VAR_FUNC) {
        partial_T *pt;
        partial_T fref_pt;
        if (argvars[0].v_type == VAR_PARTIAL)
            pt = argvars[0].vval.v_partial;
        else {
            vim_memset (& fref_pt, 0, sizeof (fref_pt));
            fref_pt.pt_name = argvars[0].vval.v_string;
            pt = &fref_pt;
        }
        if (pt != NULL) {
            char_u *what = get_tv_string (&argvars[1]);
            char_u *n;
            if (STRCMP (what, "func") == 0 || STRCMP (what, "name") == 0) {
                rettv->v_type = (*what == 'f' ? VAR_FUNC : VAR_STRING);
                n = partial_name (pt);
                if (n == NULL)
                    rettv->vval.v_string = NULL;
                else {
                    rettv->vval.v_string = vim_strsave (n);
                    if (rettv->v_type == VAR_FUNC)
                        func_ref (rettv->vval.v_string);
                }
            }
            else if (STRCMP (what, "dict") == 0)
                rettv_dict_set (rettv, pt->pt_dict);
            else if (STRCMP (what, "args") == 0) {
                rettv->v_type = VAR_LIST;
                if (rettv_list_alloc (rettv) == OK) {
                    int i;
                    for (i = 0; i < pt->pt_argc; ++i)
                        list_append_tv (rettv->vval.v_list, &pt->pt_argv[i]);
                }
            }
            else
                EMSG2 (_ (e_invarg2), what);
            return;
        }
    }
    else
        EMSG2 (_ (e_listdictarg), "get()");
    if (tv == NULL) {
        if (argvars[2].v_type != VAR_UNKNOWN)
            copy_tv (&argvars[2], rettv);
    }
    else
        copy_tv (tv, rettv);
}

static void f_getbufinfo (typval_T *argvars, typval_T *rettv) {
    buf_T *buf = NULL;
    buf_T *argbuf = NULL;
    dict_T *d;
    int filtered = FALSE;
    int sel_buflisted = FALSE;
    int sel_bufloaded = FALSE;
    int sel_bufmodified = FALSE;
    if (rettv_list_alloc (rettv) != OK)
        return;
    if (argvars[0].v_type == VAR_DICT) {
        dict_T *sel_d = argvars[0].vval.v_dict;
        if (sel_d != NULL) {
            dictitem_T *di;
            filtered = TRUE;
            di = dict_find (sel_d, (char_u *) "buflisted", -1);
            if (di != NULL && get_tv_number (&di->di_tv))
                sel_buflisted = TRUE;
            di = dict_find (sel_d, (char_u *) "bufloaded", -1);
            if (di != NULL && get_tv_number (&di->di_tv))
                sel_bufloaded = TRUE;
            di = dict_find (sel_d, (char_u *) "bufmodified", -1);
            if (di != NULL && get_tv_number (&di->di_tv))
                sel_bufmodified = TRUE;
        }
    }
    else if (argvars[0].v_type != VAR_UNKNOWN) {
        (void) get_tv_number (&argvars[0]);
        ++emsg_off;
        argbuf = get_buf_tv (&argvars[0], FALSE);
        --emsg_off;
        if (argbuf == NULL)
            return;
    }
    FOR_ALL_BUFFERS (buf) {
        if (argbuf != NULL && argbuf != buf)
            continue;
        if (filtered && ((sel_bufloaded && buf->b_ml.ml_mfp == NULL) || (sel_buflisted && !buf->b_p_bl) || (sel_bufmodified && !buf->b_changed)))
            continue;
        d = get_buffer_info (buf);
        if (d != NULL)
            list_append_dict (rettv->vval.v_list, d);
        if (argbuf != NULL)
            return;
    }
}

static dict_T *get_buffer_info (buf_T *buf) {
    dict_T *dict;
    tabpage_T *tp;
    win_T *wp;
    list_T *windows;
    dict = dict_alloc ();
    if (dict == NULL)
        return NULL;
    dict_add_nr_str (dict, "bufnr", buf -> b_fnum, NULL);
    dict_add_nr_str (dict, "name", 0L, buf -> b_ffname != NULL ? buf -> b_ffname : (char_u *) "");
    dict_add_nr_str (dict, "lnum", buf == curbuf ? curwin -> w_cursor.lnum : buflist_findlnum (buf), NULL);
    dict_add_nr_str (dict, "loaded", buf -> b_ml.ml_mfp != NULL, NULL);
    dict_add_nr_str (dict, "listed", buf -> b_p_bl, NULL);
    dict_add_nr_str (dict, "changed", bufIsChanged (buf), NULL);
    dict_add_nr_str (dict, "changedtick", CHANGEDTICK (buf), NULL);
    dict_add_nr_str (dict, "hidden", buf -> b_ml.ml_mfp != NULL && buf -> b_nwindows == 0, NULL);
    dict_add_dict (dict, "variables", buf -> b_vars);
    windows = list_alloc ();
    if (windows != NULL) {
        FOR_ALL_TAB_WINDOWS (tp, wp)
            if (wp->w_buffer == buf)
                list_append_number (windows, (varnumber_T) wp->w_id);
        dict_add_list (dict, "windows", windows);
    }
    if (buf->b_signlist != NULL) {
        list_T *signs = list_alloc ();
        if (signs != NULL) {
            get_buffer_signs (buf, signs);
            dict_add_list (dict, "signs", signs);
        }
    }
    return dict;
}

static void get_buffer_signs (buf_T *buf, list_T *l) {
    signlist_T *sign;
    for (sign = buf->b_signlist; sign; sign = sign->next) {
        dict_T *d = dict_alloc ();
        if (d != NULL) {
            dict_add_nr_str (d, "id", sign -> id, NULL);
            dict_add_nr_str (d, "lnum", sign -> lnum, NULL);
            dict_add_nr_str (d, "name", 0L, sign_typenr2name (sign -> typenr));
            list_append_dict (l, d);
        }
    }
}

static void f_getbufline (typval_T *argvars, typval_T *rettv) {
    linenr_T lnum;
    linenr_T end;
    buf_T *buf;
    (void) get_tv_number (&argvars[0]);
    ++emsg_off;
    buf = get_buf_tv (&argvars[0], FALSE);
    --emsg_off;
    lnum = get_tv_lnum_buf (&argvars[1], buf);
    if (argvars[2].v_type == VAR_UNKNOWN)
        end = lnum;
    else
        end = get_tv_lnum_buf (&argvars[2], buf);
    get_buffer_lines (buf, lnum, end, TRUE, rettv);
}

static linenr_T get_tv_lnum_buf (typval_T *argvars, buf_T *buf) {
    if (argvars[0].v_type == VAR_STRING && argvars[0].vval.v_string != NULL && argvars[0].vval.v_string[0] == '$' && buf != NULL)
        return buf->b_ml.ml_line_count;
    return (linenr_T) get_tv_number_chk (&argvars[0], NULL);
}

static void get_buffer_lines (buf_T *buf, linenr_T start, linenr_T end, int retlist, typval_T *rettv) {
    char_u *p;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    if (retlist && rettv_list_alloc (rettv) == FAIL)
        return;
    if (buf == NULL || buf->b_ml.ml_mfp == NULL || start < 0)
        return;
    if (!retlist) {
        if (start >= 1 && start <= buf->b_ml.ml_line_count)
            p = ml_get_buf (buf, start, FALSE);
        else
            p = (char_u *) "";
        rettv->vval.v_string = vim_strsave (p);
    }
    else {
        if (end < start)
            return;
        if (start < 1)
            start = 1;
        if (end > buf->b_ml.ml_line_count)
            end = buf->b_ml.ml_line_count;
        while (start <= end)
            if (list_append_string (rettv->vval.v_list, ml_get_buf (buf, start++, FALSE), -1) == FAIL)
                break;
    }
}

static void f_getbufvar (typval_T *argvars, typval_T *rettv) {
    buf_T *buf;
    buf_T *save_curbuf;
    char_u *varname;
    dictitem_T *v;
    int done = FALSE;
    (void) get_tv_number (&argvars[0]);
    varname = get_tv_string_chk (&argvars[1]);
    ++emsg_off;
    buf = get_buf_tv (&argvars[0], FALSE);
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    if (buf != NULL && varname != NULL) {
        save_curbuf = curbuf;
        curbuf = buf;
        if (*varname == '&') {
            if (varname[1] == NUL) {
                dict_T *opts = get_winbuf_options (TRUE);
                if (opts != NULL) {
                    rettv_dict_set (rettv, opts);
                    done = TRUE;
                }
            }
            else if (get_option_tv (&varname, rettv, TRUE) == OK)
                done = TRUE;
        }
        else {
            v = find_var_in_ht (&curbuf->b_vars->dv_hashtab, 'b', varname, FALSE);
            if (v != NULL) {
                copy_tv (& v -> di_tv, rettv);
                done = TRUE;
            }
        }
        curbuf = save_curbuf;
    }
    if (!done && argvars[2].v_type != VAR_UNKNOWN)
        copy_tv (&argvars[2], rettv);
    --emsg_off;
}

static void f_getchangelist (typval_T *argvars, typval_T *rettv) {
    buf_T *buf;
    int i;
    list_T *l;
    dict_T *d;
    if (rettv_list_alloc (rettv) != OK)
        return;
    (void) get_tv_number (&argvars[0]);
    ++emsg_off;
    buf = get_buf_tv (&argvars[0], FALSE);
    --emsg_off;
    if (buf == NULL)
        return;
    l = list_alloc ();
    if (l == NULL)
        return;
    if (list_append_list (rettv->vval.v_list, l) == FAIL)
        return;
    list_append_number (rettv -> vval.v_list, (varnumber_T) ((buf == curwin -> w_buffer) ? curwin -> w_changelistidx : buf -> b_changelistlen));
    for (i = 0; i < buf->b_changelistlen; ++i) {
        if (buf->b_changelist[i].lnum == 0)
            continue;
        if ((d = dict_alloc ()) == NULL)
            return;
        if (list_append_dict (l, d) == FAIL)
            return;
        dict_add_nr_str (d, "lnum", (long) buf -> b_changelist [i].lnum, NULL);
        dict_add_nr_str (d, "col", (long) buf -> b_changelist [i].col, NULL);
        dict_add_nr_str (d, "coladd", (long) buf -> b_changelist [i].coladd, NULL);
    }
}

static void f_getchar (typval_T *argvars, typval_T *rettv) {
    varnumber_T n;
    int error = FALSE;
    windgoto (msg_row, msg_col);
    ++no_mapping;
    ++allow_keys;
    for (;;) {
        if (argvars[0].v_type == VAR_UNKNOWN)
            n = plain_vgetc ();
        else if (get_tv_number_chk (&argvars[0], &error) == 1)
            n = vpeekc_any ();
        else if (error || vpeekc_any () == NUL)
            n = 0;
        else
            n = plain_vgetc ();
        if (n == K_IGNORE)
            continue;
        break;
    }
    --no_mapping;
    --allow_keys;
    set_vim_var_nr (VV_MOUSE_WIN, 0);
    set_vim_var_nr (VV_MOUSE_WINID, 0);
    set_vim_var_nr (VV_MOUSE_LNUM, 0);
    set_vim_var_nr (VV_MOUSE_COL, 0);
    rettv->vval.v_number = n;
    if (IS_SPECIAL (n) || mod_mask != 0) {
        char_u temp [10];
        int i = 0;
        if (mod_mask != 0) {
            temp[i++] = K_SPECIAL;
            temp[i++] = KS_MODIFIER;
            temp[i++] = mod_mask;
        }
        if (IS_SPECIAL (n)) {
            temp[i++] = K_SPECIAL;
            temp[i++] = K_SECOND (n);
            temp[i++] = K_THIRD (n);
        }
        else
            temp[i++] = n;
        temp[i++] = NUL;
        rettv->v_type = VAR_STRING;
        rettv->vval.v_string = vim_strsave (temp);
        if (is_mouse_key (n) || n == K_SWIPELEFT || n == K_SWIPERIGHT || n == K_SWIPEUP || n == K_SWIPEDOWN) {
            int row = mouse_row;
            int col = mouse_col;
            win_T *win;
            linenr_T lnum;
            win_T *wp;
            int winnr = 1;
            if (row >= 0 && col >= 0) {
                win = mouse_find_win (&row, &col);
                if (win == NULL)
                    return;
                (void) mouse_comp_pos (win, &row, &col, &lnum);
                for (wp = firstwin; wp != win; wp = wp->w_next)
                    ++winnr;
                set_vim_var_nr (VV_MOUSE_WIN, winnr);
                set_vim_var_nr (VV_MOUSE_WINID, win -> w_id);
                set_vim_var_nr (VV_MOUSE_LNUM, lnum);
                set_vim_var_nr (VV_MOUSE_COL, col + 1);
            }
        }
    }
}

static void f_getcharmod (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = mod_mask;
}

static void f_getcharsearch (typval_T *argvars, typval_T *rettv) {
    if (rettv_dict_alloc (rettv) != FAIL) {
        dict_T *dict = rettv->vval.v_dict;
        dict_add_nr_str (dict, "char", 0L, last_csearch ());
        dict_add_nr_str (dict, "forward", last_csearch_forward (), NULL);
        dict_add_nr_str (dict, "until", last_csearch_until (), NULL);
    }
}

static void f_getcmdline (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = get_cmdline_str ();
}

static void f_getcmdpos (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = get_cmdline_pos () + 1;
}

static void f_getcmdtype (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = alloc (2);
    if (rettv->vval.v_string != NULL) {
        rettv->vval.v_string[0] = get_cmdline_type ();
        rettv->vval.v_string[1] = NUL;
    }
}

static void f_getcmdwintype (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
}

static void f_getcompletion (typval_T *argvars, typval_T *rettv) {
    char_u *pat;
    expand_T xpc;
    int filtered = FALSE;
    int options = WILD_SILENT | WILD_USE_NL | WILD_ADD_SLASH | WILD_NO_BEEP;
    if (argvars[2].v_type != VAR_UNKNOWN)
        filtered = get_tv_number_chk (&argvars[2], NULL);
    if (p_wic)
        options |= WILD_ICASE;
    if (!filtered)
        options |= WILD_KEEP_ALL;
    ExpandInit (& xpc);
    xpc.xp_pattern = get_tv_string (&argvars[0]);
    xpc.xp_pattern_len = (int) STRLEN (xpc.xp_pattern);
    xpc.xp_context = cmdcomplete_str_to_type (get_tv_string (&argvars[1]));
    if (xpc.xp_context == EXPAND_NOTHING) {
        if (argvars[1].v_type == VAR_STRING)
            EMSG2 (_ (e_invarg2), argvars[1].vval.v_string);
        else
            EMSG (_ (e_invarg));
        return;
    }
    if (xpc.xp_context == EXPAND_MENUS) {
        set_context_in_menu_cmd (& xpc, (char_u *) "menu", xpc.xp_pattern, FALSE);
        xpc.xp_pattern_len = (int) STRLEN (xpc.xp_pattern);
    }
    if (xpc.xp_context == EXPAND_SIGN) {
        set_context_in_sign_cmd (& xpc, xpc.xp_pattern);
        xpc.xp_pattern_len = (int) STRLEN (xpc.xp_pattern);
    }
    pat = addstar (xpc.xp_pattern, xpc.xp_pattern_len, xpc.xp_context);
    if ((rettv_list_alloc (rettv) != FAIL) && (pat != NULL)) {
        int i;
        ExpandOne (& xpc, pat, NULL, options, WILD_ALL_KEEP);
        for (i = 0; i < xpc.xp_numfiles; i++)
            list_append_string (rettv->vval.v_list, xpc.xp_files[i], -1);
    }
    vim_free (pat);
    ExpandCleanup (& xpc);
}

static void f_getcwd (typval_T *argvars, typval_T *rettv) {
    win_T *wp = NULL;
    char_u *cwd;
    int global = FALSE;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    if (argvars[0].v_type == VAR_NUMBER && argvars[0].vval.v_number == -1)
        global = TRUE;
    else
        wp = find_tabwin (&argvars[0], &argvars[1]);
    if (wp != NULL && wp->w_localdir != NULL)
        rettv->vval.v_string = vim_strsave (wp->w_localdir);
    else if (wp != NULL || global) {
        if (globaldir != NULL)
            rettv->vval.v_string = vim_strsave (globaldir);
        else {
            cwd = alloc (MAXPATHL);
            if (cwd != NULL) {
                if (mch_dirname (cwd, MAXPATHL) != FAIL)
                    rettv->vval.v_string = vim_strsave (cwd);
                vim_free (cwd);
            }
        }
    }
}

static void f_getfontname (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    if (gui.in_use) {
        GuiFont font;
        char_u *name = NULL;
        if (argvars[0].v_type == VAR_UNKNOWN) {
            font = gui.norm_font;
            name = hl_get_font_name ();
        }
        else {
            name = get_tv_string (&argvars[0]);
            if (STRCMP (name, "*") == 0)
                return;
            font = gui_mch_get_font (name, FALSE);
            if (font == NOFONT)
                return;
        }
        rettv->vval.v_string = gui_mch_get_fontname (font, name);
        if (argvars[0].v_type != VAR_UNKNOWN)
            gui_mch_free_font (font);
    }
}

static void f_getfperm (typval_T *argvars, typval_T *rettv) {
    char_u *fname;
    stat_T st;
    char_u *perm = NULL;
    char_u flags [] = "rwx";
    int i;
    fname = get_tv_string (&argvars[0]);
    rettv->v_type = VAR_STRING;
    if (mch_stat ((char *) fname, &st) >= 0) {
        perm = vim_strsave ((char_u *) "---------");
        if (perm != NULL) {
            for (i = 0; i < 9; i++) {
                if (st.st_mode & (1 << (8 - i)))
                    perm[i] = flags[i % 3];
            }
        }
    }
    rettv->vval.v_string = perm;
}

static void f_getfsize (typval_T *argvars, typval_T *rettv) {
    char_u *fname;
    stat_T st;
    fname = get_tv_string (&argvars[0]);
    rettv->v_type = VAR_NUMBER;
    if (mch_stat ((char *) fname, &st) >= 0) {
        if (mch_isdir (fname))
            rettv->vval.v_number = 0;
        else {
            rettv->vval.v_number = (varnumber_T) st.st_size;
            if ((off_T) rettv->vval.v_number != (off_T) st.st_size)
                rettv->vval.v_number = -2;
        }
    }
    else
        rettv->vval.v_number = -1;
}

static void f_getftime (typval_T *argvars, typval_T *rettv) {
    char_u *fname;
    stat_T st;
    fname = get_tv_string (&argvars[0]);
    if (mch_stat ((char *) fname, &st) >= 0)
        rettv->vval.v_number = (varnumber_T) st.st_mtime;
    else
        rettv->vval.v_number = -1;
}

static void f_getftype (typval_T *argvars, typval_T *rettv) {
    char_u *fname;
    stat_T st;
    char_u *type = NULL;
    char *t;
    fname = get_tv_string (&argvars[0]);
    rettv->v_type = VAR_STRING;
    if (mch_lstat ((char *) fname, &st) >= 0) {
        if (mch_isdir (fname))
            t = "dir";
        else
            t = "file";
        type = vim_strsave ((char_u *) t);
    }
    rettv->vval.v_string = type;
}

static void f_getjumplist (typval_T *argvars, typval_T *rettv) {
    win_T *wp;
    int i;
    list_T *l;
    dict_T *d;
    if (rettv_list_alloc (rettv) != OK)
        return;
    wp = find_tabwin (&argvars[0], &argvars[1]);
    if (wp == NULL)
        return;
    l = list_alloc ();
    if (l == NULL)
        return;
    if (list_append_list (rettv->vval.v_list, l) == FAIL)
        return;
    list_append_number (rettv -> vval.v_list, (varnumber_T) wp -> w_jumplistidx);
    cleanup_jumplist (wp, TRUE);
    for (i = 0; i < wp->w_jumplistlen; ++i) {
        if (wp->w_jumplist[i].fmark.mark.lnum == 0)
            continue;
        if ((d = dict_alloc ()) == NULL)
            return;
        if (list_append_dict (l, d) == FAIL)
            return;
        dict_add_nr_str (d, "lnum", (long) wp -> w_jumplist [i].fmark.mark.lnum, NULL);
        dict_add_nr_str (d, "col", (long) wp -> w_jumplist [i].fmark.mark.col, NULL);
        dict_add_nr_str (d, "coladd", (long) wp -> w_jumplist [i].fmark.mark.coladd, NULL);
        dict_add_nr_str (d, "bufnr", (long) wp -> w_jumplist [i].fmark.fnum, NULL);
        if (wp->w_jumplist[i].fname != NULL)
            dict_add_nr_str (d, "filename", 0L, wp->w_jumplist[i].fname);
    }
}

static void f_getline (typval_T *argvars, typval_T *rettv) {
    linenr_T lnum;
    linenr_T end;
    int retlist;
    lnum = get_tv_lnum (argvars);
    if (argvars[1].v_type == VAR_UNKNOWN) {
        end = 0;
        retlist = FALSE;
    }
    else {
        end = get_tv_lnum (&argvars[1]);
        retlist = TRUE;
    }
    get_buffer_lines (curbuf, lnum, end, retlist, rettv);
}

static void f_getloclist (typval_T *argvars, typval_T *rettv) {
    win_T *wp;
    wp = find_win_by_nr (&argvars[0], NULL);
    get_qf_loc_list (FALSE, wp, & argvars [1], rettv);
}

static void get_qf_loc_list (int is_qf, win_T *wp, typval_T *what_arg, typval_T *rettv) {
    if (what_arg->v_type == VAR_UNKNOWN) {
        if (rettv_list_alloc (rettv) == OK)
            if (is_qf || wp != NULL)
                (void) get_errorlist (NULL, wp, -1, rettv->vval.v_list);
    }
    else {
        if (rettv_dict_alloc (rettv) == OK)
            if (is_qf || (wp != NULL)) {
                if (what_arg->v_type == VAR_DICT) {
                    dict_T *d = what_arg->vval.v_dict;
                    if (d != NULL)
                        qf_get_properties (wp, d, rettv->vval.v_dict);
                }
                else
                    EMSG (_ (e_dictreq));
            }
    }
}

static void f_getmatches (typval_T *argvars, typval_T *rettv) {
    dict_T *dict;
    matchitem_T *cur = curwin->w_match_head;
    int i;
    if (rettv_list_alloc (rettv) == OK) {
        while (cur != NULL) {
            dict = dict_alloc ();
            if (dict == NULL)
                return;
            if (cur->match.regprog == NULL) {
                for (i = 0; i < MAXPOSMATCH; ++i) {
                    llpos_T *llpos;
                    char buf [6];
                    list_T *l;
                    llpos = &cur->pos.pos[i];
                    if (llpos->lnum == 0)
                        break;
                    l = list_alloc ();
                    if (l == NULL)
                        break;
                    list_append_number (l, (varnumber_T) llpos -> lnum);
                    if (llpos->col > 0) {
                        list_append_number (l, (varnumber_T) llpos -> col);
                        list_append_number (l, (varnumber_T) llpos -> len);
                    }
                    sprintf (buf, "pos%d", i + 1);
                    dict_add_list (dict, buf, l);
                }
            }
            else {
                dict_add_nr_str (dict, "pattern", 0L, cur -> pattern);
            }
            dict_add_nr_str (dict, "group", 0L, syn_id2name (cur -> hlg_id));
            dict_add_nr_str (dict, "priority", (long) cur -> priority, NULL);
            dict_add_nr_str (dict, "id", (long) cur -> id, NULL);
            list_append_dict (rettv -> vval.v_list, dict);
            cur = cur->next;
        }
    }
}

static void f_getpid (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = mch_get_pid ();
}

static void f_getcurpos (typval_T *argvars, typval_T *rettv) {
    getpos_both (argvars, rettv, TRUE);
}

static void getpos_both (typval_T *argvars, typval_T *rettv, int getcurpos) {
    pos_T *fp;
    list_T *l;
    int fnum = -1;
    if (rettv_list_alloc (rettv) == OK) {
        l = rettv->vval.v_list;
        if (getcurpos)
            fp = &curwin->w_cursor;
        else
            fp = var2fpos (&argvars[0], TRUE, &fnum);
        if (fnum != -1)
            list_append_number (l, (varnumber_T) fnum);
        else
            list_append_number (l, (varnumber_T) 0);
        list_append_number (l, (fp != NULL) ? (varnumber_T) fp -> lnum : (varnumber_T) 0);
        list_append_number (l, (fp != NULL) ? (varnumber_T) (fp -> col == MAXCOL ? MAXCOL : fp -> col + 1) : (varnumber_T) 0);
        list_append_number (l, (fp != NULL) ? (varnumber_T) fp -> coladd : (varnumber_T) 0);
        if (getcurpos) {
            update_curswant ();
            list_append_number (l, curwin -> w_curswant == MAXCOL ? (varnumber_T) MAXCOL : (varnumber_T) curwin -> w_curswant + 1);
        }
    }
    else
        rettv->vval.v_number = FALSE;
}

static void f_getpos (typval_T *argvars, typval_T *rettv) {
    getpos_both (argvars, rettv, FALSE);
}

static void f_getqflist (typval_T *argvars, typval_T *rettv) {
    get_qf_loc_list (TRUE, NULL, & argvars [0], rettv);
}

static void f_getreg (typval_T *argvars, typval_T *rettv) {
    char_u *strregname;
    int regname;
    int arg2 = FALSE;
    int return_list = FALSE;
    int error = FALSE;
    if (argvars[0].v_type != VAR_UNKNOWN) {
        strregname = get_tv_string_chk (&argvars[0]);
        error = strregname == NULL;
        if (argvars[1].v_type != VAR_UNKNOWN) {
            arg2 = (int) get_tv_number_chk (&argvars[1], &error);
            if (!error && argvars[2].v_type != VAR_UNKNOWN)
                return_list = (int) get_tv_number_chk (&argvars[2], &error);
        }
    }
    else
        strregname = get_vim_var_str (VV_REG);
    if (error)
        return;
    regname = (strregname == NULL ? '"' : *strregname);
    if (regname == 0)
        regname = '"';
    if (return_list) {
        rettv->v_type = VAR_LIST;
        rettv->vval.v_list = (list_T *) get_reg_contents (regname, (arg2 ? GREG_EXPR_SRC : 0) | GREG_LIST);
        if (rettv->vval.v_list == NULL)
            (void) rettv_list_alloc (rettv);
        else
            ++rettv->vval.v_list->lv_refcount;
    }
    else {
        rettv->v_type = VAR_STRING;
        rettv->vval.v_string = get_reg_contents (regname, arg2 ? GREG_EXPR_SRC : 0);
    }
}

static void f_getregtype (typval_T *argvars, typval_T *rettv) {
    char_u *strregname;
    int regname;
    char_u buf [NUMBUFLEN + 2];
    long  reglen = 0;
    if (argvars[0].v_type != VAR_UNKNOWN) {
        strregname = get_tv_string_chk (&argvars[0]);
        if (strregname == NULL) {
            rettv->v_type = VAR_STRING;
            rettv->vval.v_string = NULL;
            return;
        }
    }
    else
        strregname = get_vim_var_str (VV_REG);
    regname = (strregname == NULL ? '"' : *strregname);
    if (regname == 0)
        regname = '"';
    buf[0] = NUL;
    buf[1] = NUL;
    switch (get_reg_type (regname, &reglen)) {
    case MLINE :
        buf[0] = 'V';
        break;
    case MCHAR :
        buf[0] = 'v';
        break;
    case MBLOCK :
        buf[0] = Ctrl_V;
        sprintf ((char *) buf + 1, "%ld", reglen + 1);
        break;
    }
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = vim_strsave (buf);
}

static void f_gettabinfo (typval_T *argvars, typval_T *rettv) {
    tabpage_T *tp, *tparg = NULL;
    dict_T *d;
    int tpnr = 0;
    if (rettv_list_alloc (rettv) != OK)
        return;
    if (argvars[0].v_type != VAR_UNKNOWN) {
        tparg = find_tabpage ((int) get_tv_number_chk (&argvars[0], NULL));
        if (tparg == NULL)
            return;
    }
    FOR_ALL_TABPAGES (tp) {
        tpnr++;
        if (tparg != NULL && tp != tparg)
            continue;
        d = get_tabpage_info (tp, tpnr);
        if (d != NULL)
            list_append_dict (rettv->vval.v_list, d);
        if (tparg != NULL)
            return;
    }
}

static dict_T *get_tabpage_info (tabpage_T *tp, int tp_idx) {
    win_T *wp;
    dict_T *dict;
    list_T *l;
    dict = dict_alloc ();
    if (dict == NULL)
        return NULL;
    dict_add_nr_str (dict, "tabnr", tp_idx, NULL);
    l = list_alloc ();
    if (l != NULL) {
        for (wp = (tp == curtab) ? firstwin : tp->tp_firstwin; wp; wp = wp->w_next)
            list_append_number (l, (varnumber_T) wp->w_id);
        dict_add_list (dict, "windows", l);
    }
    dict_add_dict (dict, "variables", tp -> tp_vars);
    return dict;
}

static void f_gettabvar (typval_T *argvars, typval_T *rettv) {
    win_T *oldcurwin;
    tabpage_T *tp, *oldtabpage;
    dictitem_T *v;
    char_u *varname;
    int done = FALSE;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    varname = get_tv_string_chk (&argvars[1]);
    tp = find_tabpage ((int) get_tv_number_chk (&argvars[0], NULL));
    if (tp != NULL && varname != NULL) {
        if (switch_win (&oldcurwin, &oldtabpage, tp == curtab || tp->tp_firstwin == NULL ? firstwin : tp->tp_firstwin, tp, TRUE) == OK) {
            v = find_var_in_ht (&tp->tp_vars->dv_hashtab, 't', varname, FALSE);
            if (v != NULL) {
                copy_tv (& v -> di_tv, rettv);
                done = TRUE;
            }
        }
        restore_win (oldcurwin, oldtabpage, TRUE);
    }
    if (!done && argvars[2].v_type != VAR_UNKNOWN)
        copy_tv (&argvars[2], rettv);
}

static void f_gettabwinvar (typval_T *argvars, typval_T *rettv) {
    getwinvar (argvars, rettv, 1);
}

static void f_getwininfo (typval_T *argvars, typval_T *rettv) {
    tabpage_T *tp;
    win_T *wp = NULL, *wparg = NULL;
    dict_T *d;
    short  tabnr = 0, winnr;
    if (rettv_list_alloc (rettv) != OK)
        return;
    if (argvars[0].v_type != VAR_UNKNOWN) {
        wparg = win_id2wp (argvars);
        if (wparg == NULL)
            return;
    }
    FOR_ALL_TABPAGES (tp) {
        tabnr++;
        winnr = 0;
        FOR_ALL_WINDOWS_IN_TAB (tp, wp) {
            winnr++;
            if (wparg != NULL && wp != wparg)
                continue;
            d = get_win_info (wp, tabnr, winnr);
            if (d != NULL)
                list_append_dict (rettv->vval.v_list, d);
            if (wparg != NULL)
                return;
        }
    }
}

static dict_T *get_win_info (win_T *wp, short  tpnr, short  winnr) {
    dict_T *dict;
    dict = dict_alloc ();
    if (dict == NULL)
        return NULL;
    dict_add_nr_str (dict, "tabnr", tpnr, NULL);
    dict_add_nr_str (dict, "winnr", winnr, NULL);
    dict_add_nr_str (dict, "winid", wp -> w_id, NULL);
    dict_add_nr_str (dict, "height", wp -> w_height, NULL);
    dict_add_nr_str (dict, "winbar", wp -> w_winbar_height, NULL);
    dict_add_nr_str (dict, "width", wp -> w_width, NULL);
    dict_add_nr_str (dict, "bufnr", wp -> w_buffer -> b_fnum, NULL);
    dict_add_nr_str (dict, "terminal", bt_terminal (wp -> w_buffer), NULL);
    dict_add_nr_str (dict, "quickfix", bt_quickfix (wp -> w_buffer), NULL);
    dict_add_nr_str (dict, "loclist", (bt_quickfix (wp -> w_buffer) && wp -> w_llist_ref != NULL), NULL);
    dict_add_dict (dict, "variables", wp -> w_vars);
    return dict;
}

static void f_win_findbuf (typval_T *argvars, typval_T *rettv) {
    if (rettv_list_alloc (rettv) != FAIL)
        win_findbuf (argvars, rettv->vval.v_list);
}

static void f_win_getid (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = win_getid (argvars);
}

static void f_win_gotoid (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = win_gotoid (argvars);
}

static void f_win_id2tabwin (typval_T *argvars, typval_T *rettv) {
    if (rettv_list_alloc (rettv) != FAIL)
        win_id2tabwin (argvars, rettv->vval.v_list);
}

static void f_win_id2win (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = win_id2win (argvars);
}

static void f_win_screenpos (typval_T *argvars, typval_T *rettv) {
    win_T *wp;
    if (rettv_list_alloc (rettv) == FAIL)
        return;
    wp = find_win_by_nr (&argvars[0], NULL);
    list_append_number (rettv -> vval.v_list, wp == NULL ? 0 : wp -> w_winrow + 1);
    list_append_number (rettv -> vval.v_list, wp == NULL ? 0 : wp -> w_wincol + 1);
}

static void f_getwinposx (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = -1;
    if (gui.in_use) {
        int x, y;
        if (gui_mch_get_winpos (&x, &y) == OK)
            rettv->vval.v_number = x;
        return;
    }
}

static void f_getwinposy (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = -1;
    if (gui.in_use) {
        int x, y;
        if (gui_mch_get_winpos (&x, &y) == OK)
            rettv->vval.v_number = y;
        return;
    }
}

static void f_getwinvar (typval_T *argvars, typval_T *rettv) {
    getwinvar (argvars, rettv, 0);
}

static void f_glob (typval_T *argvars, typval_T *rettv) {
    int options = WILD_SILENT | WILD_USE_NL;
    expand_T xpc;
    int error = FALSE;
    rettv->v_type = VAR_STRING;
    if (argvars[1].v_type != VAR_UNKNOWN) {
        if (get_tv_number_chk (&argvars[1], &error))
            options |= WILD_KEEP_ALL;
        if (argvars[2].v_type != VAR_UNKNOWN) {
            if (get_tv_number_chk (&argvars[2], &error)) {
                rettv_list_set (rettv, NULL);
            }
            if (argvars[3].v_type != VAR_UNKNOWN && get_tv_number_chk (&argvars[3], &error))
                options |= WILD_ALLLINKS;
        }
    }
    if (!error) {
        ExpandInit (& xpc);
        xpc.xp_context = EXPAND_FILES;
        if (p_wic)
            options += WILD_ICASE;
        if (rettv->v_type == VAR_STRING)
            rettv->vval.v_string = ExpandOne (&xpc, get_tv_string (&argvars[0]), NULL, options, WILD_ALL);
        else if (rettv_list_alloc (rettv) != FAIL) {
            int i;
            ExpandOne (& xpc, get_tv_string (& argvars [0]), NULL, options, WILD_ALL_KEEP);
            for (i = 0; i < xpc.xp_numfiles; i++)
                list_append_string (rettv->vval.v_list, xpc.xp_files[i], -1);
            ExpandCleanup (& xpc);
        }
    }
    else
        rettv->vval.v_string = NULL;
}

static void f_globpath (typval_T *argvars, typval_T *rettv) {
    int flags = 0;
    char_u buf1 [NUMBUFLEN];
    char_u *file = get_tv_string_buf_chk (&argvars[1], buf1);
    int error = FALSE;
    garray_T ga;
    int i;
    rettv->v_type = VAR_STRING;
    if (argvars[2].v_type != VAR_UNKNOWN) {
        if (get_tv_number_chk (&argvars[2], &error))
            flags |= WILD_KEEP_ALL;
        if (argvars[3].v_type != VAR_UNKNOWN) {
            if (get_tv_number_chk (&argvars[3], &error)) {
                rettv_list_set (rettv, NULL);
            }
            if (argvars[4].v_type != VAR_UNKNOWN && get_tv_number_chk (&argvars[4], &error))
                flags |= WILD_ALLLINKS;
        }
    }
    if (file != NULL && !error) {
        ga_init2 (& ga, (int) sizeof (char_u *), 10);
        globpath (get_tv_string (& argvars [0]), file, & ga, flags);
        if (rettv->v_type == VAR_STRING)
            rettv->vval.v_string = ga_concat_strings (&ga, "\n");
        else if (rettv_list_alloc (rettv) != FAIL)
            for (i = 0; i < ga.ga_len; ++i)
                list_append_string (rettv->vval.v_list, ((char_u **) (ga.ga_data))[i], -1);
        ga_clear_strings (& ga);
    }
    else
        rettv->vval.v_string = NULL;
}

static void f_glob2regpat (typval_T *argvars, typval_T *rettv) {
    char_u *pat = get_tv_string_chk (&argvars[0]);
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = (pat == NULL) ? NULL : file_pat_to_reg_pat (pat, NULL, NULL, FALSE);
}

#include "version.h"

static void f_has (typval_T *argvars, typval_T *rettv) {
    int i;
    char_u *name;
    int n = FALSE;
    static char * (has_list []) = {"mac", "osx", "unix", "fname_case", "arabic", "autocmd", "balloon_eval", "balloon_multiline", "balloon_eval_term", "builtin_terms", "byte_offset", "channel", "cindent", "clientserver", "cmdline_compl", "comments", "conceal", "cryptv", "crypt-blowfish", "crypt-blowfish2", "cursorbind", "dialog_con", "dialog_gui", "diff", "digraphs", "emacs_tags", "eval", "ex_extra", "extra_search", "farsi", "file_in_path", "find_in_path", "float", "folding", "fork", "fullscreen", "gui", "gui_macvim", "insert_expand", "job", "jumplist", "keymap", "lambda", "langmap", "linebreak", "lispindent", "listcmds", "localmap", "menu", "mksession", "modify_fname", "mouse", "mouseshape", "mouse_dec", "mouse_netterm", "mouse_sgr", "mouse_urxvt", "mouse_xterm", "multi_byte_ime", "multi_lang", "num64", "packages", "path_extra", "persistent_undo", "postscript", "printer", "profile", "reltime", "quickfix", "rightleft", "scrollbind", "showcmd", "cmdline_info", "signs", "smartindent", "startuptime", "statusline", "netbeans_intg", "spell", "syntax", "tag_binary", "tag_old_static", "termguicolors", "terminal", "terminfo", "termresponse", "textobjects", "timers", "title", "toolbar", "transparency", "user-commands", "user_commands", "viminfo", "vertsplit", "virtualedit", "visual", "visualextra", "vreplace", "wildignore", "wildmenu", "windows", "writebackup", NULL};
    name = get_tv_string (&argvars[0]);
    for (i = 0; has_list[i] != NULL; ++i)
        if (STRICMP (name, has_list[i]) == 0) {
            n = TRUE;
            break;
        }
    if (n == FALSE) {
        if (STRNICMP (name, "patch", 5) == 0) {
            if (name[5] == '-' && STRLEN (name) >= 11 && vim_isdigit (name[6]) && vim_isdigit (name[8]) && vim_isdigit (name[10])) {
                int major = atoi ((char *) name + 6);
                int minor = atoi ((char *) name + 8);
                n = (major < VIM_VERSION_MAJOR || (major == VIM_VERSION_MAJOR && (minor < VIM_VERSION_MINOR || (minor == VIM_VERSION_MINOR && has_patch (atoi ((char *) name + 10))))));
            }
            else
                n = has_patch (atoi ((char *) name + 5));
        }
        else if (STRICMP (name, "vim_starting") == 0)
            n = (starting != 0);
        else if (STRICMP (name, "ttyin") == 0)
            n = mch_input_isatty ();
        else if (STRICMP (name, "ttyout") == 0)
            n = stdout_isatty;
        else if (STRICMP (name, "gui_running") == 0)
            n = (gui.in_use || gui.starting);
        else if (STRICMP (name, "syntax_items") == 0)
            n = syntax_present (curwin);
        else if (STRICMP (name, "netbeans_enabled") == 0)
            n = netbeans_active ();
    }
    rettv->vval.v_number = n;
}

static void f_has_key (typval_T *argvars, typval_T *rettv) {
    if (argvars[0].v_type != VAR_DICT) {
        EMSG (_ (e_dictreq));
        return;
    }
    if (argvars[0].vval.v_dict == NULL)
        return;
    rettv->vval.v_number = dict_find (argvars[0].vval.v_dict, get_tv_string (&argvars[1]), -1) != NULL;
}

static void f_haslocaldir (typval_T *argvars, typval_T *rettv) {
    win_T *wp = NULL;
    wp = find_tabwin (&argvars[0], &argvars[1]);
    rettv->vval.v_number = (wp != NULL && wp->w_localdir != NULL);
}

static void f_hasmapto (typval_T *argvars, typval_T *rettv) {
    char_u *name;
    char_u *mode;
    char_u buf [NUMBUFLEN];
    int abbr = FALSE;
    name = get_tv_string (&argvars[0]);
    if (argvars[1].v_type == VAR_UNKNOWN)
        mode = (char_u *) "nvo";
    else {
        mode = get_tv_string_buf (&argvars[1], buf);
        if (argvars[2].v_type != VAR_UNKNOWN)
            abbr = (int) get_tv_number (&argvars[2]);
    }
    if (map_to_exists (name, mode, abbr))
        rettv->vval.v_number = TRUE;
    else
        rettv->vval.v_number = FALSE;
}

static void f_histadd (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = FALSE;
    if (check_restricted () || check_secure ())
        return;
}

static void f_histdel (typval_T *argvars, typval_T *rettv) {
}

static void f_histget (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_string = NULL;
    rettv->v_type = VAR_STRING;
}

static void f_histnr (typval_T *argvars, typval_T *rettv) {
    int i;
    i = -1;
    rettv->vval.v_number = i;
}

static void f_hlID (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = syn_name2id (get_tv_string (&argvars[0]));
}

static void f_hlexists (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = highlight_exists (get_tv_string (&argvars[0]));
}

static void f_hostname (typval_T *argvars, typval_T *rettv) {
    char_u hostname [256];
    mch_get_host_name (hostname, 256);
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = vim_strsave (hostname);
}

static void f_iconv (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
}

static void f_indent (typval_T *argvars, typval_T *rettv) {
    linenr_T lnum;
    lnum = get_tv_lnum (argvars);
    if (lnum >= 1 && lnum <= curbuf->b_ml.ml_line_count)
        rettv->vval.v_number = get_indent_lnum (lnum);
    else
        rettv->vval.v_number = -1;
}

static void f_index (typval_T *argvars, typval_T *rettv) {
    list_T *l;
    listitem_T *item;
    long  idx = 0;
    int ic = FALSE;
    rettv->vval.v_number = -1;
    if (argvars[0].v_type != VAR_LIST) {
        EMSG (_ (e_listreq));
        return;
    }
    l = argvars[0].vval.v_list;
    if (l != NULL) {
        item = l->lv_first;
        if (argvars[2].v_type != VAR_UNKNOWN) {
            int error = FALSE;
            item = list_find (l, (long ) get_tv_number_chk (&argvars[2], &error));
            idx = l->lv_idx;
            if (argvars[3].v_type != VAR_UNKNOWN)
                ic = (int) get_tv_number_chk (&argvars[3], &error);
            if (error)
                item = NULL;
        }
        for (; item != NULL; item = item->li_next, ++idx)
            if (tv_equal (&item->li_tv, &argvars[1], ic, FALSE)) {
                rettv->vval.v_number = idx;
                break;
            }
    }
}

static void f_input (typval_T *argvars, typval_T *rettv) {
    get_user_input (argvars, rettv, FALSE, inputsecret_flag);
}

static void f_inputdialog (typval_T *argvars, typval_T *rettv) {
    get_user_input (argvars, rettv, TRUE, inputsecret_flag);
}

static void f_inputlist (typval_T *argvars, typval_T *rettv) {
    listitem_T *li;
    int selected;
    int mouse_used;
    if (argvars[0].v_type != VAR_LIST || argvars[0].vval.v_list == NULL) {
        EMSG2 (_ (e_listarg), "inputlist()");
        return;
    }
    msg_start ();
    msg_row = Rows - 1;
    lines_left = Rows;
    msg_scroll = TRUE;
    msg_clr_eos ();
    for (li = argvars[0].vval.v_list->lv_first; li != NULL; li = li->li_next) {
        msg_puts (get_tv_string (& li -> li_tv));
        msg_putchar ('\n');
    }
    selected = prompt_for_number (&mouse_used);
    if (mouse_used)
        selected -= lines_left;
    rettv->vval.v_number = selected;
}

static void f_inputrestore (typval_T *argvars, typval_T *rettv) {
    if (ga_userinput.ga_len > 0) {
        --ga_userinput.ga_len;
        restore_typeahead ((tasave_T *) (ga_userinput.ga_data) + ga_userinput.ga_len);
    }
    else if (p_verbose > 1) {
        verb_msg ((char_u *) _ ("called inputrestore() more often than inputsave()"));
        rettv->vval.v_number = 1;
    }
}

static void f_inputsave (typval_T *argvars, typval_T *rettv) {
    if (ga_grow (&ga_userinput, 1) == OK) {
        save_typeahead ((tasave_T *) (ga_userinput.ga_data) + ga_userinput.ga_len);
        ++ga_userinput.ga_len;
    }
    else
        rettv->vval.v_number = 1;
}

static void f_inputsecret (typval_T *argvars, typval_T *rettv) {
    ++cmdline_star;
    ++inputsecret_flag;
    f_input (argvars, rettv);
    --cmdline_star;
    --inputsecret_flag;
}

static void f_insert (typval_T *argvars, typval_T *rettv) {
    long  before = 0;
    listitem_T *item;
    list_T *l;
    int error = FALSE;
    if (argvars[0].v_type != VAR_LIST)
        EMSG2 (_ (e_listarg), "insert()");
    else if ((l = argvars[0].vval.v_list) != NULL && !tv_check_lock (l->lv_lock, (char_u *) N_ ("insert() argument"), TRUE)) {
        if (argvars[2].v_type != VAR_UNKNOWN)
            before = (long ) get_tv_number_chk (&argvars[2], &error);
        if (error)
            return;
        if (before == l->lv_len)
            item = NULL;
        else {
            item = list_find (l, before);
            if (item == NULL) {
                EMSGN (_ (e_listidx), before);
                l = NULL;
            }
        }
        if (l != NULL) {
            list_insert_tv (l, & argvars [1], item);
            copy_tv (& argvars [0], rettv);
        }
    }
}

static void f_invert (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = ~get_tv_number_chk (&argvars[0], NULL);
}

static void f_isdirectory (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = mch_isdir (get_tv_string (&argvars[0]));
}

static void f_islocked (typval_T *argvars, typval_T *rettv) {
    lval_T lv;
    char_u *end;
    dictitem_T *di;
    rettv->vval.v_number = -1;
    end = get_lval (get_tv_string (&argvars[0]), NULL, &lv, FALSE, FALSE, GLV_NO_AUTOLOAD | GLV_READ_ONLY, FNE_CHECK_START);
    if (end != NULL && lv.ll_name != NULL) {
        if (*end != NUL)
            EMSG (_ (e_trailing));
        else {
            if (lv.ll_tv == NULL) {
                di = find_var (lv.ll_name, NULL, TRUE);
                if (di != NULL) {
                    rettv->vval.v_number = ((di->di_flags & DI_FLAGS_LOCK) || tv_islocked (&di->di_tv));
                }
            }
            else if (lv.ll_range)
                EMSG (_ ("E786: Range not allowed"));
            else if (lv.ll_newkey != NULL)
                EMSG2 (_ (e_dictkey), lv.ll_newkey);
            else if (lv.ll_list != NULL)
                rettv->vval.v_number = tv_islocked (&lv.ll_li->li_tv);
            else
                rettv->vval.v_number = tv_islocked (&lv.ll_di->di_tv);
        }
    }
    clear_lval (& lv);
}

static int tv_islocked (typval_T *tv) {
    return (tv->v_lock & VAR_LOCKED) || (tv->v_type == VAR_LIST && tv->vval.v_list != NULL && (tv->vval.v_list->lv_lock & VAR_LOCKED)) || (tv->v_type == VAR_DICT && tv->vval.v_dict != NULL && (tv->vval.v_dict->dv_lock & VAR_LOCKED));
}

static void f_items (typval_T *argvars, typval_T *rettv) {
    dict_list (argvars, rettv, 2);
}

static void f_job_getchannel (typval_T *argvars, typval_T *rettv) {
    job_T *job = get_job_arg (&argvars[0]);
    if (job != NULL) {
        rettv->v_type = VAR_CHANNEL;
        rettv->vval.v_channel = job->jv_channel;
        if (job->jv_channel != NULL)
            ++job->jv_channel->ch_refcount;
    }
}

static job_T *get_job_arg (typval_T *tv) {
    job_T *job;
    if (tv->v_type != VAR_JOB) {
        EMSG2 (_ (e_invarg2), get_tv_string (tv));
        return NULL;
    }
    job = tv->vval.v_job;
    if (job == NULL)
        EMSG (_ ("E916: not a valid job"));
    return job;
}

static void f_job_info (typval_T *argvars, typval_T *rettv) {
    job_T *job = get_job_arg (&argvars[0]);
    if (job != NULL && rettv_dict_alloc (rettv) != FAIL)
        job_info (job, rettv->vval.v_dict);
}

static void f_job_setoptions (typval_T *argvars, typval_T *rettv) {
    job_T *job = get_job_arg (&argvars[0]);
    jobopt_T opt;
    if (job == NULL)
        return;
    clear_job_options (& opt);
    if (get_job_options (&argvars[1], &opt, JO_STOPONEXIT +JO_EXIT_CB, 0) == OK)
        job_set_options (job, &opt);
    free_job_options (& opt);
}

static void f_job_start (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_JOB;
    if (check_restricted () || check_secure ())
        return;
    rettv->vval.v_job = job_start (argvars, NULL);
}

static void f_job_status (typval_T *argvars, typval_T *rettv) {
    job_T *job = get_job_arg (&argvars[0]);
    if (job != NULL) {
        rettv->v_type = VAR_STRING;
        rettv->vval.v_string = vim_strsave ((char_u *) job_status (job));
    }
}

static void f_job_stop (typval_T *argvars, typval_T *rettv) {
    job_T *job = get_job_arg (&argvars[0]);
    if (job != NULL)
        rettv->vval.v_number = job_stop (job, argvars, NULL);
}

static void f_join (typval_T *argvars, typval_T *rettv) {
    garray_T ga;
    char_u *sep;
    if (argvars[0].v_type != VAR_LIST) {
        EMSG (_ (e_listreq));
        return;
    }
    if (argvars[0].vval.v_list == NULL)
        return;
    if (argvars[1].v_type == VAR_UNKNOWN)
        sep = (char_u *) " ";
    else
        sep = get_tv_string_chk (&argvars[1]);
    rettv->v_type = VAR_STRING;
    if (sep != NULL) {
        ga_init2 (& ga, (int) sizeof (char), 80);
        list_join (& ga, argvars [0].vval.v_list, sep, TRUE, FALSE, 0);
        ga_append (& ga, NUL);
        rettv->vval.v_string = (char_u *) ga.ga_data;
    }
    else
        rettv->vval.v_string = NULL;
}

static void f_js_decode (typval_T *argvars, typval_T *rettv) {
    js_read_T reader;
    reader.js_buf = get_tv_string (&argvars[0]);
    reader.js_fill = NULL;
    reader.js_used = 0;
    if (json_decode_all (&reader, rettv, JSON_JS) != OK)
        EMSG (_ (e_invarg));
}

static void f_js_encode (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = json_encode (&argvars[0], JSON_JS);
}

static void f_json_decode (typval_T *argvars, typval_T *rettv) {
    js_read_T reader;
    reader.js_buf = get_tv_string (&argvars[0]);
    reader.js_fill = NULL;
    reader.js_used = 0;
    json_decode_all (& reader, rettv, 0);
}

static void f_json_encode (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = json_encode (&argvars[0], 0);
}

static void f_keys (typval_T *argvars, typval_T *rettv) {
    dict_list (argvars, rettv, 0);
}

static void f_last_buffer_nr (typval_T *argvars, typval_T *rettv) {
    int n = 0;
    buf_T *buf;
    FOR_ALL_BUFFERS (buf)
        if (n < buf->b_fnum)
            n = buf->b_fnum;
    rettv->vval.v_number = n;
}

static void f_len (typval_T *argvars, typval_T *rettv) {
    switch (argvars[0].v_type) {
    case VAR_STRING :
    case VAR_NUMBER :
        rettv->vval.v_number = (varnumber_T) STRLEN (get_tv_string (&argvars[0]));
        break;
    case VAR_LIST :
        rettv->vval.v_number = list_len (argvars[0].vval.v_list);
        break;
    case VAR_DICT :
        rettv->vval.v_number = dict_len (argvars[0].vval.v_dict);
        break;
    case VAR_UNKNOWN :
    case VAR_SPECIAL :
    case VAR_FLOAT :
    case VAR_FUNC :
    case VAR_PARTIAL :
    case VAR_JOB :
    case VAR_CHANNEL :
        EMSG (_ ("E701: Invalid type for len()"));
        break;
    }
}

static void f_libcall (typval_T *argvars, typval_T *rettv) {
    libcall_common (argvars, rettv, VAR_STRING);
}

static void libcall_common (typval_T *argvars, typval_T *rettv, int type) {
    rettv->v_type = type;
    if (type != VAR_NUMBER)
        rettv->vval.v_string = NULL;
    if (check_restricted () || check_secure ())
        return;
}

static void f_libcallnr (typval_T *argvars, typval_T *rettv) {
    libcall_common (argvars, rettv, VAR_NUMBER);
}

static void f_line2byte (typval_T *argvars, typval_T *rettv) {
    linenr_T lnum;
    lnum = get_tv_lnum (argvars);
    if (lnum < 1 || lnum > curbuf->b_ml.ml_line_count + 1)
        rettv->vval.v_number = -1;
    else
        rettv->vval.v_number = ml_find_line_or_offset (curbuf, lnum, NULL);
    if (rettv->vval.v_number >= 0)
        ++rettv->vval.v_number;
}

static void f_lispindent (typval_T *argvars, typval_T *rettv) {
    pos_T pos;
    linenr_T lnum;
    pos = curwin->w_cursor;
    lnum = get_tv_lnum (argvars);
    if (lnum >= 1 && lnum <= curbuf->b_ml.ml_line_count) {
        curwin->w_cursor.lnum = lnum;
        rettv->vval.v_number = get_lisp_indent ();
        curwin->w_cursor = pos;
    }
    else
        rettv->vval.v_number = -1;
}

static void f_localtime (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = (varnumber_T) time (NULL);
}

static void f_log (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &f) == OK)
        rettv->vval.v_float = log (f);
    else
        rettv->vval.v_float = 0.0;
}

static void f_log10 (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &f) == OK)
        rettv->vval.v_float = log10 (f);
    else
        rettv->vval.v_float = 0.0;
}

static void f_map (typval_T *argvars, typval_T *rettv) {
    filter_map (argvars, rettv, TRUE);
}

static void f_maparg (typval_T *argvars, typval_T *rettv) {
    get_maparg (argvars, rettv, TRUE);
}

static void get_maparg (typval_T *argvars, typval_T *rettv, int exact) {
    char_u *keys;
    char_u *which;
    char_u buf [NUMBUFLEN];
    char_u *keys_buf = NULL;
    char_u *rhs;
    int mode;
    int abbr = FALSE;
    int get_dict = FALSE;
    mapblock_T *mp;
    int buffer_local;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    keys = get_tv_string (&argvars[0]);
    if (*keys == NUL)
        return;
    if (argvars[1].v_type != VAR_UNKNOWN) {
        which = get_tv_string_buf_chk (&argvars[1], buf);
        if (argvars[2].v_type != VAR_UNKNOWN) {
            abbr = (int) get_tv_number (&argvars[2]);
            if (argvars[3].v_type != VAR_UNKNOWN)
                get_dict = (int) get_tv_number (&argvars[3]);
        }
    }
    else
        which = (char_u *) "";
    if (which == NULL)
        return;
    mode = get_map_mode (&which, 0);
    keys = replace_termcodes (keys, &keys_buf, TRUE, TRUE, FALSE);
    rhs = check_map (keys, mode, exact, FALSE, abbr, &mp, &buffer_local);
    vim_free (keys_buf);
    if (!get_dict) {
        if (rhs != NULL)
            rettv->vval.v_string = str2special_save (rhs, FALSE);
    }
    else if (rettv_dict_alloc (rettv) != FAIL && rhs != NULL) {
        char_u *lhs = str2special_save (mp->m_keys, TRUE);
        char_u *mapmode = map_mode_to_chars (mp->m_mode);
        dict_T *dict = rettv->vval.v_dict;
        dict_add_nr_str (dict, "lhs", 0L, lhs);
        dict_add_nr_str (dict, "rhs", 0L, mp -> m_orig_str);
        dict_add_nr_str (dict, "noremap", mp -> m_noremap ? 1L : 0L, NULL);
        dict_add_nr_str (dict, "expr", mp -> m_expr ? 1L : 0L, NULL);
        dict_add_nr_str (dict, "silent", mp -> m_silent ? 1L : 0L, NULL);
        dict_add_nr_str (dict, "sid", (long) mp -> m_script_ID, NULL);
        dict_add_nr_str (dict, "buffer", (long) buffer_local, NULL);
        dict_add_nr_str (dict, "nowait", mp -> m_nowait ? 1L : 0L, NULL);
        dict_add_nr_str (dict, "mode", 0L, mapmode);
        vim_free (lhs);
        vim_free (mapmode);
    }
}

static void f_mapcheck (typval_T *argvars, typval_T *rettv) {
    get_maparg (argvars, rettv, FALSE);
}

static void f_match (typval_T *argvars, typval_T *rettv) {
    find_some_match (argvars, rettv, MATCH_MATCH);
}

static void find_some_match (typval_T *argvars, typval_T *rettv, matchtype_T type) {
    char_u *str = NULL;
    long  len = 0;
    char_u *expr = NULL;
    char_u *pat;
    regmatch_T regmatch;
    char_u patbuf [NUMBUFLEN];
    char_u strbuf [NUMBUFLEN];
    char_u *save_cpo;
    long  start = 0;
    long  nth = 1;
    colnr_T startcol = 0;
    int match = 0;
    list_T *l = NULL;
    listitem_T *li = NULL;
    long  idx = 0;
    char_u *tofree = NULL;
    save_cpo = p_cpo;
    p_cpo = (char_u *) "";
    rettv->vval.v_number = -1;
    if (type == MATCH_LIST || type == MATCH_POS) {
        if (rettv_list_alloc (rettv) == FAIL)
            goto theend;
        if (type == MATCH_POS && (list_append_string (rettv->vval.v_list, (char_u *) "", 0) == FAIL || list_append_number (rettv->vval.v_list, (varnumber_T) -1) == FAIL || list_append_number (rettv->vval.v_list, (varnumber_T) -1) == FAIL || list_append_number (rettv->vval.v_list, (varnumber_T) -1) == FAIL)) {
            list_free (rettv -> vval.v_list);
            rettv->vval.v_list = NULL;
            goto theend;
        }
    }
    else if (type == MATCH_STR) {
        rettv->v_type = VAR_STRING;
        rettv->vval.v_string = NULL;
    }
    if (argvars[0].v_type == VAR_LIST) {
        if ((l = argvars[0].vval.v_list) == NULL)
            goto theend;
        li = l->lv_first;
    }
    else {
        expr = str = get_tv_string (&argvars[0]);
        len = (long ) STRLEN (str);
    }
    pat = get_tv_string_buf_chk (&argvars[1], patbuf);
    if (pat == NULL)
        goto theend;
    if (argvars[2].v_type != VAR_UNKNOWN) {
        int error = FALSE;
        start = (long ) get_tv_number_chk (&argvars[2], &error);
        if (error)
            goto theend;
        if (l != NULL) {
            li = list_find (l, start);
            if (li == NULL)
                goto theend;
            idx = l->lv_idx;
        }
        else {
            if (start < 0)
                start = 0;
            if (start > len)
                goto theend;
            if (argvars[3].v_type != VAR_UNKNOWN)
                startcol = start;
            else {
                str += start;
                len -= start;
            }
        }
        if (argvars[3].v_type != VAR_UNKNOWN)
            nth = (long ) get_tv_number_chk (&argvars[3], &error);
        if (error)
            goto theend;
    }
    regmatch.regprog = vim_regcomp (pat, RE_MAGIC +RE_STRING);
    if (regmatch.regprog != NULL) {
        regmatch.rm_ic = p_ic;
        for (;;) {
            if (l != NULL) {
                if (li == NULL) {
                    match = FALSE;
                    break;
                }
                vim_free (tofree);
                expr = str = echo_string (&li->li_tv, &tofree, strbuf, 0);
                if (str == NULL)
                    break;
            }
            match = vim_regexec_nl (&regmatch, str, (colnr_T) startcol);
            if (match && --nth <= 0)
                break;
            if (l == NULL && !match)
                break;
            if (l != NULL) {
                li = li->li_next;
                ++idx;
            }
            else {
                startcol = (colnr_T) (regmatch.startp[0] + 1 - str);
                if (startcol > (colnr_T) len || str + startcol <= regmatch.startp[0]) {
                    match = FALSE;
                    break;
                }
            }
        }
        if (match) {
            if (type == MATCH_POS) {
                listitem_T *li1 = rettv->vval.v_list->lv_first;
                listitem_T *li2 = li1->li_next;
                listitem_T *li3 = li2->li_next;
                listitem_T *li4 = li3->li_next;
                vim_free (li1 -> li_tv.vval.v_string);
                li1->li_tv.vval.v_string = vim_strnsave (regmatch.startp[0], (int) (regmatch.endp[0] - regmatch.startp[0]));
                li3->li_tv.vval.v_number = (varnumber_T) (regmatch.startp[0] - expr);
                li4->li_tv.vval.v_number = (varnumber_T) (regmatch.endp[0] - expr);
                if (l != NULL)
                    li2->li_tv.vval.v_number = (varnumber_T) idx;
            }
            else if (type == MATCH_LIST) {
                int i;
                for (i = 0; i < NSUBEXP; ++i) {
                    if (regmatch.endp[i] == NULL) {
                        if (list_append_string (rettv->vval.v_list, (char_u *) "", 0) == FAIL)
                            break;
                    }
                    else if (list_append_string (rettv->vval.v_list, regmatch.startp[i], (int) (regmatch.endp[i] - regmatch.startp[i])) == FAIL)
                        break;
                }
            }
            else if (type == MATCH_STR) {
                if (l != NULL)
                    copy_tv (&li->li_tv, rettv);
                else
                    rettv->vval.v_string = vim_strnsave (regmatch.startp[0], (int) (regmatch.endp[0] - regmatch.startp[0]));
            }
            else if (l != NULL)
                rettv->vval.v_number = idx;
            else {
                if (type != MATCH_END)
                    rettv->vval.v_number = (varnumber_T) (regmatch.startp[0] - str);
                else
                    rettv->vval.v_number = (varnumber_T) (regmatch.endp[0] - str);
                rettv->vval.v_number += (varnumber_T) (str - expr);
            }
        }
        vim_regfree (regmatch.regprog);
    }
theend :
    if (type == MATCH_POS && l == NULL && rettv->vval.v_list != NULL)
        listitem_remove (rettv->vval.v_list, rettv->vval.v_list->lv_first->li_next);
    vim_free (tofree);
    p_cpo = save_cpo;
}

static void f_matchadd (typval_T *argvars, typval_T *rettv) {
    char_u buf [NUMBUFLEN];
    char_u *grp = get_tv_string_buf_chk (&argvars[0], buf);
    char_u *pat = get_tv_string_buf_chk (&argvars[1], buf);
    int prio = 10;
    int id = -1;
    int error = FALSE;
    char_u *conceal_char = NULL;
    rettv->vval.v_number = -1;
    if (grp == NULL || pat == NULL)
        return;
    if (argvars[2].v_type != VAR_UNKNOWN) {
        prio = (int) get_tv_number_chk (&argvars[2], &error);
        if (argvars[3].v_type != VAR_UNKNOWN) {
            id = (int) get_tv_number_chk (&argvars[3], &error);
            if (argvars[4].v_type != VAR_UNKNOWN) {
                if (argvars[4].v_type != VAR_DICT) {
                    EMSG (_ (e_dictreq));
                    return;
                }
                if (dict_find (argvars[4].vval.v_dict, (char_u *) "conceal", -1) != NULL)
                    conceal_char = get_dict_string (argvars[4].vval.v_dict, (char_u *) "conceal", FALSE);
            }
        }
    }
    if (error == TRUE)
        return;
    if (id >= 1 && id <= 3) {
        EMSGN (_ ("E798: ID is reserved for \":match\": %ld"), id);
        return;
    }
    rettv->vval.v_number = match_add (curwin, grp, pat, prio, id, NULL, conceal_char);
}

static void f_matchaddpos (typval_T *argvars, typval_T *rettv) {
    char_u buf [NUMBUFLEN];
    char_u *group;
    int prio = 10;
    int id = -1;
    int error = FALSE;
    list_T *l;
    char_u *conceal_char = NULL;
    rettv->vval.v_number = -1;
    group = get_tv_string_buf_chk (&argvars[0], buf);
    if (group == NULL)
        return;
    if (argvars[1].v_type != VAR_LIST) {
        EMSG2 (_ (e_listarg), "matchaddpos()");
        return;
    }
    l = argvars[1].vval.v_list;
    if (l == NULL)
        return;
    if (argvars[2].v_type != VAR_UNKNOWN) {
        prio = (int) get_tv_number_chk (&argvars[2], &error);
        if (argvars[3].v_type != VAR_UNKNOWN) {
            id = (int) get_tv_number_chk (&argvars[3], &error);
            if (argvars[4].v_type != VAR_UNKNOWN) {
                if (argvars[4].v_type != VAR_DICT) {
                    EMSG (_ (e_dictreq));
                    return;
                }
                if (dict_find (argvars[4].vval.v_dict, (char_u *) "conceal", -1) != NULL)
                    conceal_char = get_dict_string (argvars[4].vval.v_dict, (char_u *) "conceal", FALSE);
            }
        }
    }
    if (error == TRUE)
        return;
    if (id == 1 || id == 2) {
        EMSGN (_ ("E798: ID is reserved for \":match\": %ld"), id);
        return;
    }
    rettv->vval.v_number = match_add (curwin, group, NULL, prio, id, l, conceal_char);
}

static void f_matcharg (typval_T *argvars, typval_T *rettv) {
    if (rettv_list_alloc (rettv) == OK) {
        int id = (int) get_tv_number (&argvars[0]);
        matchitem_T *m;
        if (id >= 1 && id <= 3) {
            if ((m = (matchitem_T *) get_match (curwin, id)) != NULL) {
                list_append_string (rettv -> vval.v_list, syn_id2name (m -> hlg_id), - 1);
                list_append_string (rettv -> vval.v_list, m -> pattern, - 1);
            }
            else {
                list_append_string (rettv -> vval.v_list, NULL, - 1);
                list_append_string (rettv -> vval.v_list, NULL, - 1);
            }
        }
    }
}

static void f_matchdelete (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = match_delete (curwin, (int) get_tv_number (&argvars[0]), TRUE);
}

static void f_matchend (typval_T *argvars, typval_T *rettv) {
    find_some_match (argvars, rettv, MATCH_END);
}

static void f_matchlist (typval_T *argvars, typval_T *rettv) {
    find_some_match (argvars, rettv, MATCH_LIST);
}

static void f_matchstr (typval_T *argvars, typval_T *rettv) {
    find_some_match (argvars, rettv, MATCH_STR);
}

static void f_matchstrpos (typval_T *argvars, typval_T *rettv) {
    find_some_match (argvars, rettv, MATCH_POS);
}

static void f_max (typval_T *argvars, typval_T *rettv) {
    max_min (argvars, rettv, TRUE);
}

static void max_min (typval_T *argvars, typval_T *rettv, int domax) {
    varnumber_T n = 0;
    varnumber_T i;
    int error = FALSE;
    if (argvars[0].v_type == VAR_LIST) {
        list_T *l;
        listitem_T *li;
        l = argvars[0].vval.v_list;
        if (l != NULL) {
            li = l->lv_first;
            if (li != NULL) {
                n = get_tv_number_chk (&li->li_tv, &error);
                for (;;) {
                    li = li->li_next;
                    if (li == NULL)
                        break;
                    i = get_tv_number_chk (&li->li_tv, &error);
                    if (domax ? i > n : i < n)
                        n = i;
                }
            }
        }
    }
    else if (argvars[0].v_type == VAR_DICT) {
        dict_T *d;
        int first = TRUE;
        hashitem_T *hi;
        int todo;
        d = argvars[0].vval.v_dict;
        if (d != NULL) {
            todo = (int) d->dv_hashtab.ht_used;
            for (hi = d->dv_hashtab.ht_array; todo > 0; ++hi) {
                if (!HASHITEM_EMPTY (hi)) {
                    --todo;
                    i = get_tv_number_chk (&HI2DI (hi)->di_tv, &error);
                    if (first) {
                        n = i;
                        first = FALSE;
                    }
                    else if (domax ? i > n : i < n)
                        n = i;
                }
            }
        }
    }
    else
        EMSG2 (_ (e_listdictarg), domax ? "max()" : "min()");
    rettv->vval.v_number = error ? 0 : n;
}

static void f_min (typval_T *argvars, typval_T *rettv) {
    max_min (argvars, rettv, FALSE);
}

static void f_mode (typval_T *argvars, typval_T *rettv) {
    char_u buf [3];
    buf[1] = NUL;
    buf[2] = NUL;
    if (time_for_testing == 93784) {
        buf[0] = 'x';
        buf[1] = '!';
    }
    else if (term_use_loop ())
        buf[0] = 't';
    else if (VIsual_active) {
        if (VIsual_select)
            buf[0] = VIsual_mode + 's' - 'v';
        else
            buf[0] = VIsual_mode;
    }
    else if (State == HITRETURN || State == ASKMORE || State == SETWSIZE || State == CONFIRM) {
        buf[0] = 'r';
        if (State == ASKMORE)
            buf[1] = 'm';
        else if (State == CONFIRM)
            buf[1] = '?';
    }
    else if (State == EXTERNCMD)
        buf[0] = '!';
    else if (State & INSERT) {
        if (State & VREPLACE_FLAG) {
            buf[0] = 'R';
            buf[1] = 'v';
        }
        else {
            if (State & REPLACE_FLAG)
                buf[0] = 'R';
            else
                buf[0] = 'i';
            if (ins_compl_active ())
                buf[1] = 'c';
            else if (ctrl_x_mode_not_defined_yet ())
                buf[1] = 'x';
        }
    }
    else if ((State & CMDLINE) || exmode_active) {
        buf[0] = 'c';
        if (exmode_active == EXMODE_VIM)
            buf[1] = 'v';
        else if (exmode_active == EXMODE_NORMAL)
            buf[1] = 'e';
    }
    else {
        buf[0] = 'n';
        if (finish_op)
            buf[1] = 'o';
    }
    if (!non_zero_arg (&argvars[0]))
        buf[1] = NUL;
    rettv->vval.v_string = vim_strsave (buf);
    rettv->v_type = VAR_STRING;
}

static int non_zero_arg (typval_T *argvars) {
    return ((argvars[0].v_type == VAR_NUMBER && argvars[0].vval.v_number != 0) || (argvars[0].v_type == VAR_SPECIAL && argvars[0].vval.v_number == VVAL_TRUE) || (argvars[0].v_type == VAR_STRING && argvars[0].vval.v_string != NULL && *argvars[0].vval.v_string != NUL));
}

static void f_nextnonblank (typval_T *argvars, typval_T *rettv) {
    linenr_T lnum;
    for (lnum = get_tv_lnum (argvars);; ++lnum) {
        if (lnum < 0 || lnum > curbuf->b_ml.ml_line_count) {
            lnum = 0;
            break;
        }
        if (*skipwhite (ml_get (lnum)) != NUL)
            break;
    }
    rettv->vval.v_number = lnum;
}

static void f_nr2char (typval_T *argvars, typval_T *rettv) {
    char_u buf [NUMBUFLEN];
    {
        buf[0] = (char_u) get_tv_number (&argvars[0]);
        buf[1] = NUL;
    }
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = vim_strsave (buf);
}

static void f_or (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = get_tv_number_chk (&argvars[0], NULL) | get_tv_number_chk (&argvars[1], NULL);
}

static void f_pathshorten (typval_T *argvars, typval_T *rettv) {
    char_u *p;
    rettv->v_type = VAR_STRING;
    p = get_tv_string_chk (&argvars[0]);
    if (p == NULL)
        rettv->vval.v_string = NULL;
    else {
        p = vim_strsave (p);
        rettv->vval.v_string = p;
        if (p != NULL)
            shorten_dir (p);
    }
}

static void f_pow (typval_T *argvars, typval_T *rettv) {
    float_T fx = 0.0, fy = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &fx) == OK && get_float_arg (&argvars[1], &fy) == OK)
        rettv->vval.v_float = pow (fx, fy);
    else
        rettv->vval.v_float = 0.0;
}

static void f_prevnonblank (typval_T *argvars, typval_T *rettv) {
    linenr_T lnum;
    lnum = get_tv_lnum (argvars);
    if (lnum < 1 || lnum > curbuf->b_ml.ml_line_count)
        lnum = 0;
    else
        while (lnum >= 1 && *skipwhite (ml_get (lnum)) == NUL)
            --lnum;
    rettv->vval.v_number = lnum;
}

static void f_printf (typval_T *argvars, typval_T *rettv) {
    char_u buf [NUMBUFLEN];
    int len;
    char_u *s;
    int saved_did_emsg = did_emsg;
    char *fmt;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    did_emsg = FALSE;
    fmt = (char *) get_tv_string_buf (&argvars[0], buf);
    len = vim_vsnprintf_typval (NULL, 0, fmt, ap, argvars +1);
    if (!did_emsg) {
        s = alloc (len +1);
        if (s != NULL) {
            rettv->vval.v_string = s;
            (void) vim_vsnprintf_typval ((char *) s, len +1, fmt, ap, argvars +1);
        }
    }
    did_emsg |= saved_did_emsg;
}

static void f_pumvisible (typval_T *argvars, typval_T *rettv) {
    if (pum_visible ())
        rettv->vval.v_number = 1;
}

static void f_range (typval_T *argvars, typval_T *rettv) {
    varnumber_T start;
    varnumber_T end;
    varnumber_T stride = 1;
    varnumber_T i;
    int error = FALSE;
    start = get_tv_number_chk (&argvars[0], &error);
    if (argvars[1].v_type == VAR_UNKNOWN) {
        end = start - 1;
        start = 0;
    }
    else {
        end = get_tv_number_chk (&argvars[1], &error);
        if (argvars[2].v_type != VAR_UNKNOWN)
            stride = get_tv_number_chk (&argvars[2], &error);
    }
    if (error)
        return;
    if (stride == 0)
        EMSG (_ ("E726: Stride is zero"));
    else if (stride > 0 ? end + 1 < start : end - 1 > start)
        EMSG (_ ("E727: Start past end"));
    else {
        if (rettv_list_alloc (rettv) == OK)
            for (i = start; stride > 0 ? i <= end : i >= end; i += stride)
                if (list_append_number (rettv->vval.v_list, (varnumber_T) i) == FAIL)
                    break;
    }
}

static void f_readfile (typval_T *argvars, typval_T *rettv) {
    int binary = FALSE;
    int failed = FALSE;
    char_u *fname;
    FILE *fd;
    char_u buf [(IOSIZE / 256) * 256];
    int io_size = sizeof (buf);
    int readlen;
    char_u *prev = NULL;
    long  prevlen = 0;
    long  prevsize = 0;
    long  maxline = MAXLNUM;
    long  cnt = 0;
    char_u *p;
    char_u *start;
    if (argvars[1].v_type != VAR_UNKNOWN) {
        if (STRCMP (get_tv_string (&argvars[1]), "b") == 0)
            binary = TRUE;
        if (argvars[2].v_type != VAR_UNKNOWN)
            maxline = (long ) get_tv_number (&argvars[2]);
    }
    if (rettv_list_alloc (rettv) == FAIL)
        return;
    fname = get_tv_string (&argvars[0]);
    if (*fname == NUL || (fd = mch_fopen ((char *) fname, READBIN)) == NULL) {
        EMSG2 (_ (e_notopen), * fname == NUL ? (char_u *) _ ("<empty>") : fname);
        return;
    }
    while (cnt < maxline || maxline < 0) {
        readlen = (int) fread (buf, 1, io_size, fd);
        for (p = buf, start = buf; p < buf + readlen || (readlen <= 0 && (prevlen > 0 || binary)); ++p) {
            if (*p == '\n' || readlen <= 0) {
                listitem_T *li;
                char_u *s = NULL;
                long_u len = p - start;
                if (readlen > 0 && !binary) {
                    while (len > 0 && start[len - 1] == '\r')
                        --len;
                    if (len == 0)
                        while (prevlen > 0 && prev[prevlen - 1] == '\r')
                            --prevlen;
                }
                if (prevlen == 0)
                    s = vim_strnsave (start, (int) len);
                else {
                    if ((s = vim_realloc (prev, prevlen +len + 1)) != NULL) {
                        mch_memmove (s + prevlen, start, len);
                        s[prevlen + len] = NUL;
                        prev = NULL;
                        prevlen = prevsize = 0;
                    }
                }
                if (s == NULL) {
                    do_outofmem_msg ((long_u) prevlen + len + 1);
                    failed = TRUE;
                    break;
                }
                if ((li = listitem_alloc ()) == NULL) {
                    vim_free (s);
                    failed = TRUE;
                    break;
                }
                li->li_tv.v_type = VAR_STRING;
                li->li_tv.v_lock = 0;
                li->li_tv.vval.v_string = s;
                list_append (rettv -> vval.v_list, li);
                start = p + 1;
                if ((++cnt >= maxline && maxline >= 0) || readlen <= 0)
                    break;
            }
            else if (*p == NUL)
                *p = '\n';
        }
        if (failed || (cnt >= maxline && maxline >= 0) || readlen <= 0)
            break;
        if (start < p) {
            if (p - start + prevlen >= prevsize) {
                char_u *newprev;
                if (prevsize == 0)
                    prevsize = (long ) (p - start);
                else {
                    long  grow50pc = (prevsize * 3) / 2;
                    long  growmin = (long ) ((p - start) * 2 + prevlen);
                    prevsize = grow50pc > growmin ? grow50pc : growmin;
                }
                newprev = prev == NULL ? alloc (prevsize) : vim_realloc (prev, prevsize);
                if (newprev == NULL) {
                    do_outofmem_msg ((long_u) prevsize);
                    failed = TRUE;
                    break;
                }
                prev = newprev;
            }
            mch_memmove (prev + prevlen, start, p - start);
            prevlen += (long ) (p - start);
        }
    }
    if (!failed && maxline < 0)
        while (cnt > -maxline) {
            listitem_remove (rettv -> vval.v_list, rettv -> vval.v_list -> lv_first);
            --cnt;
        }
    if (failed) {
        list_free (rettv -> vval.v_list);
        rettv->vval.v_list = list_alloc ();
    }
    vim_free (prev);
    fclose (fd);
}

static void f_reltime (typval_T *argvars, typval_T *rettv) {
    proftime_T res;
    proftime_T start;
    if (argvars[0].v_type == VAR_UNKNOWN) {
        profile_start (& res);
    }
    else if (argvars[1].v_type == VAR_UNKNOWN) {
        if (list2proftime (&argvars[0], &res) == FAIL)
            return;
        profile_end (& res);
    }
    else {
        if (list2proftime (&argvars[0], &start) == FAIL || list2proftime (&argvars[1], &res) == FAIL)
            return;
        profile_sub (& res, & start);
    }
    if (rettv_list_alloc (rettv) == OK) {
        long  n1, n2;
        n1 = res.tv_sec;
        n2 = res.tv_usec;
        list_append_number (rettv -> vval.v_list, (varnumber_T) n1);
        list_append_number (rettv -> vval.v_list, (varnumber_T) n2);
    }
}

static int list2proftime (typval_T *arg, proftime_T *tm) {
    long  n1, n2;
    int error = FALSE;
    if (arg->v_type != VAR_LIST || arg->vval.v_list == NULL || arg->vval.v_list->lv_len != 2)
        return FAIL;
    n1 = list_find_nr (arg->vval.v_list, 0L, &error);
    n2 = list_find_nr (arg->vval.v_list, 1L, &error);
    tm->tv_sec = n1;
    tm->tv_usec = n2;
    return error ? FAIL : OK;
}

static void f_reltimefloat (typval_T *argvars, typval_T *rettv) {
    proftime_T tm;
    rettv->v_type = VAR_FLOAT;
    rettv->vval.v_float = 0;
    if (list2proftime (&argvars[0], &tm) == OK)
        rettv->vval.v_float = profile_float (&tm);
}

static void f_reltimestr (typval_T *argvars, typval_T *rettv) {
    proftime_T tm;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    if (list2proftime (&argvars[0], &tm) == OK)
        rettv->vval.v_string = vim_strsave ((char_u *) profile_msg (&tm));
}

static void f_remote_expr (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    remote_common (argvars, rettv, TRUE);
}

static void remote_common (typval_T *argvars, typval_T *rettv, int expr) {
    char_u *server_name;
    char_u *keys;
    char_u *r = NULL;
    char_u buf [NUMBUFLEN];
    int timeout = 0;
    if (check_restricted () || check_secure ())
        return;
    if (argvars[2].v_type != VAR_UNKNOWN && argvars[3].v_type != VAR_UNKNOWN)
        timeout = get_tv_number (&argvars[3]);
    server_name = get_tv_string_chk (&argvars[0]);
    if (server_name == NULL)
        return;
    keys = get_tv_string_buf (&argvars[1], buf);
    if (serverSendToVim (X_DISPLAY, server_name, keys, &r, &w, expr, timeout, 0, TRUE) < 0) {
        if (r != NULL) {
            EMSG (r);
            vim_free (r);
        }
        else
            EMSG2 (_ ("E241: Unable to send to %s"), server_name);
        return;
    }
    rettv->vval.v_string = r;
    if (argvars[2].v_type != VAR_UNKNOWN) {
        dictitem_T v;
        char_u str [30];
        char_u *idvar;
        idvar = get_tv_string_chk (&argvars[2]);
        if (idvar != NULL && *idvar != NUL) {
            sprintf ((char *) str, PRINTF_HEX_LONG_U, (long_u) w);
            v.di_tv.v_type = VAR_STRING;
            v.di_tv.vval.v_string = vim_strsave (str);
            set_var (idvar, & v.di_tv, FALSE);
            vim_free (v.di_tv.vval.v_string);
        }
    }
}

static void f_remote_foreground (typval_T *argvars, typval_T *rettv) {
}

static void f_remote_peek (typval_T *argvars, typval_T *rettv) {
    dictitem_T v;
    char_u *s = NULL;
    char_u *serverid;
    if (check_restricted () || check_secure ()) {
        rettv->vval.v_number = -1;
        return;
    }
    serverid = get_tv_string_chk (&argvars[0]);
    if (serverid == NULL) {
        rettv->vval.v_number = -1;
        return;
    }
    if (argvars[1].v_type != VAR_UNKNOWN && rettv->vval.v_number > 0) {
        char_u *retvar;
        v.di_tv.v_type = VAR_STRING;
        v.di_tv.vval.v_string = vim_strsave (s);
        retvar = get_tv_string_chk (&argvars[1]);
        if (retvar != NULL)
            set_var (retvar, &v.di_tv, FALSE);
        vim_free (v.di_tv.vval.v_string);
    }
}

static void f_remote_read (typval_T *argvars, typval_T *rettv) {
    char_u *r = NULL;
    char_u *serverid = get_tv_string_chk (&argvars[0]);
    if (serverid != NULL && !check_restricted () && !check_secure ()) {
        int timeout = 0;
        if (argvars[1].v_type != VAR_UNKNOWN)
            timeout = get_tv_number (&argvars[1]);
        if (check_connection () == FAIL || serverReadReply (X_DISPLAY, serverStrToWin (serverid), &r, FALSE, timeout) < 0)
            EMSG (_ ("E277: Unable to read a server reply"));
    }
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = r;
}

static void f_remote_send (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    remote_common (argvars, rettv, FALSE);
}

static void f_remote_startserver (typval_T *argvars, typval_T *rettv) {
    char_u *server = get_tv_string_chk (&argvars[0]);
    if (server == NULL)
        return;
    if (serverName != NULL)
        EMSG (_ ("E941: already started a server"));
    else {
        serverSetName (server);
    }
}

static void f_remove (typval_T *argvars, typval_T *rettv) {
    list_T *l;
    listitem_T *item, *item2;
    listitem_T *li;
    long  idx;
    long  end;
    char_u *key;
    dict_T *d;
    dictitem_T *di;
    char_u *arg_errmsg = (char_u *) N_ ("remove() argument");
    if (argvars[0].v_type == VAR_DICT) {
        if (argvars[2].v_type != VAR_UNKNOWN)
            EMSG2 (_ (e_toomanyarg), "remove()");
        else if ((d = argvars[0].vval.v_dict) != NULL && !tv_check_lock (d->dv_lock, arg_errmsg, TRUE)) {
            key = get_tv_string_chk (&argvars[1]);
            if (key != NULL) {
                di = dict_find (d, key, -1);
                if (di == NULL)
                    EMSG2 (_ (e_dictkey), key);
                else if (!var_check_fixed (di->di_flags, arg_errmsg, TRUE) && !var_check_ro (di->di_flags, arg_errmsg, TRUE)) {
                    *rettv = di->di_tv;
                    init_tv (& di -> di_tv);
                    dictitem_remove (d, di);
                }
            }
        }
    }
    else if (argvars[0].v_type != VAR_LIST)
        EMSG2 (_ (e_listdictarg), "remove()");
    else if ((l = argvars[0].vval.v_list) != NULL && !tv_check_lock (l->lv_lock, arg_errmsg, TRUE)) {
        int error = FALSE;
        idx = (long ) get_tv_number_chk (&argvars[1], &error);
        if (error)
            ;
        else if ((item = list_find (l, idx)) == NULL)
            EMSGN (_ (e_listidx), idx);
        else {
            if (argvars[2].v_type == VAR_UNKNOWN) {
                vimlist_remove (l, item, item);
                *rettv = item->li_tv;
                vim_free (item);
            }
            else {
                end = (long ) get_tv_number_chk (&argvars[2], &error);
                if (error)
                    ;
                else if ((item2 = list_find (l, end)) == NULL)
                    EMSGN (_ (e_listidx), end);
                else {
                    int cnt = 0;
                    for (li = item; li != NULL; li = li->li_next) {
                        ++cnt;
                        if (li == item2)
                            break;
                    }
                    if (li == NULL)
                        EMSG (_ (e_invrange));
                    else {
                        vimlist_remove (l, item, item2);
                        if (rettv_list_alloc (rettv) == OK) {
                            l = rettv->vval.v_list;
                            l->lv_first = item;
                            l->lv_last = item2;
                            item->li_prev = NULL;
                            item2->li_next = NULL;
                            l->lv_len = cnt;
                        }
                    }
                }
            }
        }
    }
}

static void f_rename (typval_T *argvars, typval_T *rettv) {
    char_u buf [NUMBUFLEN];
    if (check_restricted () || check_secure ())
        rettv->vval.v_number = -1;
    else
        rettv->vval.v_number = vim_rename (get_tv_string (&argvars[0]), get_tv_string_buf (&argvars[1], buf));
}

static void f_repeat (typval_T *argvars, typval_T *rettv) {
    char_u *p;
    int n;
    int slen;
    int len;
    char_u *r;
    int i;
    n = (int) get_tv_number (&argvars[1]);
    if (argvars[0].v_type == VAR_LIST) {
        if (rettv_list_alloc (rettv) == OK && argvars[0].vval.v_list != NULL)
            while (n-- > 0)
                if (list_extend (rettv->vval.v_list, argvars[0].vval.v_list, NULL) == FAIL)
                    break;
    }
    else {
        p = get_tv_string (&argvars[0]);
        rettv->v_type = VAR_STRING;
        rettv->vval.v_string = NULL;
        slen = (int) STRLEN (p);
        len = slen * n;
        if (len <= 0)
            return;
        r = alloc (len +1);
        if (r != NULL) {
            for (i = 0; i < n; i++)
                mch_memmove (r +i * slen, p, (size_t) slen);
            r[len] = NUL;
        }
        rettv->vval.v_string = r;
    }
}

static void f_resolve (typval_T *argvars, typval_T *rettv) {
    char_u *p;
    p = get_tv_string (&argvars[0]);
    rettv->vval.v_string = vim_strsave (p);
    simplify_filename (rettv -> vval.v_string);
    rettv->v_type = VAR_STRING;
}

static void f_reverse (typval_T *argvars, typval_T *rettv) {
    list_T *l;
    listitem_T *li, *ni;
    if (argvars[0].v_type != VAR_LIST)
        EMSG2 (_ (e_listarg), "reverse()");
    else if ((l = argvars[0].vval.v_list) != NULL && !tv_check_lock (l->lv_lock, (char_u *) N_ ("reverse() argument"), TRUE)) {
        li = l->lv_last;
        l->lv_first = l->lv_last = NULL;
        l->lv_len = 0;
        while (li != NULL) {
            ni = li->li_prev;
            list_append (l, li);
            li = ni;
        }
        rettv_list_set (rettv, l);
        l->lv_idx = l->lv_len - l->lv_idx - 1;
    }
}

#define SP_NOMOVE	0x01	    /* don't move cursor */

#define SP_REPEAT	0x02	    /* repeat to find outer pair */

#define SP_RETCOUNT	0x04	    /* return matchcount */

#define SP_SETPCMARK	0x08	    /* set previous context mark */

#define SP_START	0x10	    /* accept match at start position */

#define SP_SUBPAT	0x20	    /* return nr of matching sub-pattern */

#define SP_END		0x40	    /* leave cursor at end of match */

#define SP_COLUMN	0x80	    /* start at cursor column */

static void f_round (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &f) == OK)
        rettv->vval.v_float = vim_round (f);
    else
        rettv->vval.v_float = 0.0;
}

float_T vim_round (float_T f) {
    return f > 0 ? floor (f +0.5) : ceil (f -0.5);
}

static void f_screenattr (typval_T *argvars, typval_T *rettv) {
    int row;
    int col;
    int c;
    row = (int) get_tv_number_chk (&argvars[0], NULL) - 1;
    col = (int) get_tv_number_chk (&argvars[1], NULL) - 1;
    if (row < 0 || row >= screen_Rows || col < 0 || col >= screen_Columns)
        c = -1;
    else
        c = ScreenAttrs[LineOffset[row] + col];
    rettv->vval.v_number = c;
}

static void f_screenchar (typval_T *argvars, typval_T *rettv) {
    int row;
    int col;
    int off;
    int c;
    row = (int) get_tv_number_chk (&argvars[0], NULL) - 1;
    col = (int) get_tv_number_chk (&argvars[1], NULL) - 1;
    if (row < 0 || row >= screen_Rows || col < 0 || col >= screen_Columns)
        c = -1;
    else {
        off = LineOffset[row] + col;
        c = ScreenLines[off];
    }
    rettv->vval.v_number = c;
}

static void f_screencol (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = screen_screencol () + 1;
}

static void f_screenrow (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = screen_screenrow () + 1;
}

static void f_search (typval_T *argvars, typval_T *rettv) {
    int flags = 0;
    rettv->vval.v_number = search_cmn (argvars, NULL, &flags);
}

static int search_cmn (typval_T *argvars, pos_T *match_pos, int *flagsp) {
    int flags;
    char_u *pat;
    pos_T pos;
    pos_T save_cursor;
    int save_p_ws = p_ws;
    int dir;
    int retval = 0;
    long  lnum_stop = 0;
    proftime_T tm;
    long  time_limit = 0;
    int options = SEARCH_KEEP;
    int subpatnum;
    pat = get_tv_string (&argvars[0]);
    dir = get_search_arg (&argvars[1], flagsp);
    if (dir == 0)
        goto theend;
    flags = *flagsp;
    if (flags & SP_START)
        options |= SEARCH_START;
    if (flags & SP_END)
        options |= SEARCH_END;
    if (flags & SP_COLUMN)
        options |= SEARCH_COL;
    if (argvars[1].v_type != VAR_UNKNOWN && argvars[2].v_type != VAR_UNKNOWN) {
        lnum_stop = (long ) get_tv_number_chk (&argvars[2], NULL);
        if (lnum_stop < 0)
            goto theend;
        if (argvars[3].v_type != VAR_UNKNOWN) {
            time_limit = (long ) get_tv_number_chk (&argvars[3], NULL);
            if (time_limit < 0)
                goto theend;
        }
    }
    profile_setlimit (time_limit, & tm);
    if (((flags & (SP_REPEAT | SP_RETCOUNT)) != 0) || ((flags & SP_NOMOVE) && (flags & SP_SETPCMARK))) {
        EMSG2 (_ (e_invarg2), get_tv_string (& argvars [1]));
        goto theend;
    }
    pos = save_cursor = curwin->w_cursor;
    subpatnum = searchit (curwin, curbuf, &pos, dir, pat, 1L, options, RE_SEARCH, (linenr_T) lnum_stop, &tm, NULL);
    if (subpatnum != FAIL) {
        if (flags & SP_SUBPAT)
            retval = subpatnum;
        else
            retval = pos.lnum;
        if (flags & SP_SETPCMARK)
            setpcmark ();
        curwin->w_cursor = pos;
        if (match_pos != NULL) {
            match_pos->lnum = pos.lnum;
            match_pos->col = pos.col + 1;
        }
        check_cursor ();
    }
    if (flags & SP_NOMOVE)
        curwin->w_cursor = save_cursor;
    else
        curwin->w_set_curswant = TRUE;
theend :
    p_ws = save_p_ws;
    return retval;
}

static int get_search_arg (typval_T *varp, int *flagsp) {
    int dir = FORWARD;
    char_u *flags;
    char_u nbuf [NUMBUFLEN];
    int mask;
    if (varp->v_type != VAR_UNKNOWN) {
        flags = get_tv_string_buf_chk (varp, nbuf);
        if (flags == NULL)
            return 0;
        while (*flags != NUL) {
            switch (*flags) {
            case 'b' :
                dir = BACKWARD;
                break;
            case 'w' :
                p_ws = TRUE;
                break;
            case 'W' :
                p_ws = FALSE;
                break;
            default :
                mask = 0;
                if (flagsp != NULL)
                    switch (*flags) {
                    case 'c' :
                        mask = SP_START;
                        break;
                    case 'e' :
                        mask = SP_END;
                        break;
                    case 'm' :
                        mask = SP_RETCOUNT;
                        break;
                    case 'n' :
                        mask = SP_NOMOVE;
                        break;
                    case 'p' :
                        mask = SP_SUBPAT;
                        break;
                    case 'r' :
                        mask = SP_REPEAT;
                        break;
                    case 's' :
                        mask = SP_SETPCMARK;
                        break;
                    case 'z' :
                        mask = SP_COLUMN;
                        break;
                    }
                if (mask == 0) {
                    EMSG2 (_ (e_invarg2), flags);
                    dir = 0;
                }
                else
                    *flagsp |= mask;
            }
            if (dir == 0)
                break;
            ++flags;
        }
    }
    return dir;
}

static void f_searchdecl (typval_T *argvars, typval_T *rettv) {
    int locally = 1;
    int thisblock = 0;
    int error = FALSE;
    char_u *name;
    rettv->vval.v_number = 1;
    name = get_tv_string_chk (&argvars[0]);
    if (argvars[1].v_type != VAR_UNKNOWN) {
        locally = (int) get_tv_number_chk (&argvars[1], &error) == 0;
        if (!error && argvars[2].v_type != VAR_UNKNOWN)
            thisblock = (int) get_tv_number_chk (&argvars[2], &error) != 0;
    }
    if (!error && name != NULL)
        rettv->vval.v_number = find_decl (name, (int) STRLEN (name), locally, thisblock, SEARCH_KEEP) == FAIL;
}

static void f_searchpair (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = searchpair_cmn (argvars, NULL);
}

static int searchpair_cmn (typval_T *argvars, pos_T *match_pos) {
    char_u *spat, *mpat, *epat;
    typval_T *skip;
    int save_p_ws = p_ws;
    int dir;
    int flags = 0;
    char_u nbuf1 [NUMBUFLEN];
    char_u nbuf2 [NUMBUFLEN];
    int retval = 0;
    long  lnum_stop = 0;
    long  time_limit = 0;
    spat = get_tv_string_chk (&argvars[0]);
    mpat = get_tv_string_buf_chk (&argvars[1], nbuf1);
    epat = get_tv_string_buf_chk (&argvars[2], nbuf2);
    if (spat == NULL || mpat == NULL || epat == NULL)
        goto theend;
    dir = get_search_arg (&argvars[3], &flags);
    if (dir == 0)
        goto theend;
    if ((flags & (SP_END | SP_SUBPAT)) != 0 || ((flags & SP_NOMOVE) && (flags & SP_SETPCMARK))) {
        EMSG2 (_ (e_invarg2), get_tv_string (& argvars [3]));
        goto theend;
    }
    if (flags & SP_REPEAT)
        p_ws = FALSE;
    if (argvars[3].v_type == VAR_UNKNOWN || argvars[4].v_type == VAR_UNKNOWN)
        skip = NULL;
    else {
        skip = &argvars[4];
        if (skip->v_type != VAR_FUNC && skip->v_type != VAR_PARTIAL && skip->v_type != VAR_STRING) {
            goto theend;
        }
        if (argvars[5].v_type != VAR_UNKNOWN) {
            lnum_stop = (long ) get_tv_number_chk (&argvars[5], NULL);
            if (lnum_stop < 0)
                goto theend;
            if (argvars[6].v_type != VAR_UNKNOWN) {
                time_limit = (long ) get_tv_number_chk (&argvars[6], NULL);
                if (time_limit < 0)
                    goto theend;
            }
        }
    }
    retval = do_searchpair (spat, mpat, epat, dir, skip, flags, match_pos, lnum_stop, time_limit);
theend :
    p_ws = save_p_ws;
    return retval;
}

long  do_searchpair (char_u *spat, char_u *mpat, char_u *epat, int dir, typval_T *skip, int flags, pos_T *match_pos, linenr_T lnum_stop, long  time_limit) {
    char_u *save_cpo;
    char_u *pat, *pat2 = NULL, *pat3 = NULL;
    long  retval = 0;
    pos_T pos;
    pos_T firstpos;
    pos_T foundpos;
    pos_T save_cursor;
    pos_T save_pos;
    int n;
    int r;
    int nest = 1;
    int use_skip = FALSE;
    int err;
    int options = SEARCH_KEEP;
    proftime_T tm;
    save_cpo = p_cpo;
    p_cpo = empty_option;
    profile_setlimit (time_limit, & tm);
    pat2 = alloc ((unsigned ) (STRLEN (spat) + STRLEN (epat) + 17));
    pat3 = alloc ((unsigned ) (STRLEN (spat) + STRLEN (mpat) + STRLEN (epat) + 25));
    if (pat2 == NULL || pat3 == NULL)
        goto theend;
    sprintf ((char *) pat2, "\\m\\(%s\\m\\)\\|\\(%s\\m\\)", spat, epat);
    if (*mpat == NUL)
        STRCPY (pat3, pat2);
    else
        sprintf ((char *) pat3, "\\m\\(%s\\m\\)\\|\\(%s\\m\\)\\|\\(%s\\m\\)", spat, epat, mpat);
    if (flags & SP_START)
        options |= SEARCH_START;
    if (skip != NULL) {
        if (skip->v_type == VAR_STRING || skip->v_type == VAR_FUNC)
            use_skip = skip->vval.v_string != NULL && *skip->vval.v_string != NUL;
    }
    save_cursor = curwin->w_cursor;
    pos = curwin->w_cursor;
    CLEAR_POS (& firstpos);
    CLEAR_POS (& foundpos);
    pat = pat3;
    for (;;) {
        n = searchit (curwin, curbuf, &pos, dir, pat, 1L, options, RE_SEARCH, lnum_stop, &tm, NULL);
        if (n == FAIL || (firstpos.lnum != 0 && EQUAL_POS (pos, firstpos)))
            break;
        if (firstpos.lnum == 0)
            firstpos = pos;
        if (EQUAL_POS (pos, foundpos)) {
            if (dir == BACKWARD)
                decl (&pos);
            else
                incl (&pos);
        }
        foundpos = pos;
        options &= ~SEARCH_START;
        if (use_skip) {
            save_pos = curwin->w_cursor;
            curwin->w_cursor = pos;
            err = FALSE;
            r = eval_expr_to_bool (skip, &err);
            curwin->w_cursor = save_pos;
            if (err) {
                curwin->w_cursor = save_cursor;
                retval = -1;
                break;
            }
            if (r)
                continue;
        }
        if ((dir == BACKWARD && n == 3) || (dir == FORWARD && n == 2)) {
            ++nest;
            pat = pat2;
        }
        else {
            if (--nest == 1)
                pat = pat3;
        }
        if (nest == 0) {
            if (flags & SP_RETCOUNT)
                ++retval;
            else
                retval = pos.lnum;
            if (flags & SP_SETPCMARK)
                setpcmark ();
            curwin->w_cursor = pos;
            if (!(flags & SP_REPEAT))
                break;
            nest = 1;
        }
    }
    if (match_pos != NULL) {
        match_pos->lnum = curwin->w_cursor.lnum;
        match_pos->col = curwin->w_cursor.col + 1;
    }
    if ((flags & SP_NOMOVE) || retval == 0)
        curwin->w_cursor = save_cursor;
theend :
    vim_free (pat2);
    vim_free (pat3);
    if (p_cpo == empty_option)
        p_cpo = save_cpo;
    else
        free_string_option (save_cpo);
    return retval;
}

static void f_searchpairpos (typval_T *argvars, typval_T *rettv) {
    pos_T match_pos;
    int lnum = 0;
    int col = 0;
    if (rettv_list_alloc (rettv) == FAIL)
        return;
    if (searchpair_cmn (argvars, &match_pos) > 0) {
        lnum = match_pos.lnum;
        col = match_pos.col;
    }
    list_append_number (rettv -> vval.v_list, (varnumber_T) lnum);
    list_append_number (rettv -> vval.v_list, (varnumber_T) col);
}

static void f_searchpos (typval_T *argvars, typval_T *rettv) {
    pos_T match_pos;
    int lnum = 0;
    int col = 0;
    int n;
    int flags = 0;
    if (rettv_list_alloc (rettv) == FAIL)
        return;
    n = search_cmn (argvars, &match_pos, &flags);
    if (n > 0) {
        lnum = match_pos.lnum;
        col = match_pos.col;
    }
    list_append_number (rettv -> vval.v_list, (varnumber_T) lnum);
    list_append_number (rettv -> vval.v_list, (varnumber_T) col);
    if (flags & SP_SUBPAT)
        list_append_number (rettv->vval.v_list, (varnumber_T) n);
}

static void f_server2client (typval_T *argvars, typval_T *rettv) {
    char_u buf [NUMBUFLEN];
    char_u *server = get_tv_string_chk (&argvars[0]);
    char_u *reply = get_tv_string_buf_chk (&argvars[1], buf);
    rettv->vval.v_number = -1;
    if (server == NULL || reply == NULL)
        return;
    if (check_restricted () || check_secure ())
        return;
    if (serverSendReply (server, reply) < 0) {
        EMSG (_ ("E258: Unable to send to client"));
        return;
    }
    rettv->vval.v_number = 0;
}

static void f_serverlist (typval_T *argvars, typval_T *rettv) {
    char_u *r = NULL;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = r;
}

static void f_setbufline (argvars, rettv)
    typval_T *argvars;
    typval_T *rettv;
{
    linenr_T lnum;
    buf_T *buf;
    buf = get_buf_tv (&argvars[0], FALSE);
    if (buf == NULL)
        rettv->vval.v_number = 1;
    else {
        lnum = get_tv_lnum_buf (&argvars[1], buf);
        set_buffer_lines (buf, lnum, & argvars [2], rettv);
    }
}

static void set_buffer_lines (buf_T *buf, linenr_T lnum, typval_T *lines, typval_T *rettv) {
    char_u *line = NULL;
    list_T *l = NULL;
    listitem_T *li = NULL;
    long  added = 0;
    linenr_T lcount;
    buf_T *curbuf_save = NULL;
    win_T *curwin_save = NULL;
    int is_curbuf = buf == curbuf;
    if (buf == NULL || (!is_curbuf && buf->b_ml.ml_mfp == NULL) || lnum < 1) {
        rettv->vval.v_number = 1;
        return;
    }
    if (!is_curbuf) {
        wininfo_T *wip;
        curbuf_save = curbuf;
        curwin_save = curwin;
        curbuf = buf;
        for (wip = buf->b_wininfo; wip != NULL; wip = wip->wi_next) {
            if (wip->wi_win != NULL) {
                curwin = wip->wi_win;
                break;
            }
        }
    }
    lcount = curbuf->b_ml.ml_line_count;
    if (lines->v_type == VAR_LIST) {
        l = lines->vval.v_list;
        li = l->lv_first;
    }
    else
        line = get_tv_string_chk (lines);
    for (;;) {
        if (l != NULL) {
            if (li == NULL)
                break;
            line = get_tv_string_chk (&li->li_tv);
            li = li->li_next;
        }
        rettv->vval.v_number = 1;
        if (line == NULL || lnum < 1 || lnum > curbuf->b_ml.ml_line_count + 1)
            break;
        if (u_sync_once == 2) {
            u_sync_once = 1;
            u_sync (TRUE);
        }
        if (lnum <= curbuf->b_ml.ml_line_count) {
            if (u_savesub (lnum) == OK && ml_replace (lnum, line, TRUE) == OK) {
                changed_bytes (lnum, 0);
                if (is_curbuf && lnum == curwin->w_cursor.lnum)
                    check_cursor_col ();
                rettv->vval.v_number = 0;
            }
        }
        else if (added > 0 || u_save (lnum -1, lnum) == OK) {
            ++added;
            if (ml_append (lnum -1, line, (colnr_T) 0, FALSE) == OK)
                rettv->vval.v_number = 0;
        }
        if (l == NULL)
            break;
        ++lnum;
    }
    if (added > 0)
        appended_lines_mark (lcount, added);
    if (!is_curbuf) {
        curbuf = curbuf_save;
        curwin = curwin_save;
    }
}

static void f_setbufvar (typval_T *argvars, typval_T *rettv) {
    buf_T *buf;
    char_u *varname, *bufvarname;
    typval_T *varp;
    char_u nbuf [NUMBUFLEN];
    if (check_restricted () || check_secure ())
        return;
    (void) get_tv_number (&argvars[0]);
    varname = get_tv_string_chk (&argvars[1]);
    buf = get_buf_tv (&argvars[0], FALSE);
    varp = &argvars[2];
    if (buf != NULL && varname != NULL && varp != NULL) {
        if (*varname == '&') {
            long  numval;
            char_u *strval;
            int error = FALSE;
            aco_save_T aco;
            aucmd_prepbuf (& aco, buf);
            ++varname;
            numval = (long ) get_tv_number_chk (varp, &error);
            strval = get_tv_string_buf_chk (varp, nbuf);
            if (!error && strval != NULL)
                set_option_value (varname, numval, strval, OPT_LOCAL);
            aucmd_restbuf (& aco);
        }
        else {
            buf_T *save_curbuf = curbuf;
            bufvarname = alloc ((unsigned ) STRLEN (varname) + 3);
            if (bufvarname != NULL) {
                curbuf = buf;
                STRCPY (bufvarname, "b:");
                STRCPY (bufvarname + 2, varname);
                set_var (bufvarname, varp, TRUE);
                vim_free (bufvarname);
                curbuf = save_curbuf;
            }
        }
    }
}

static void f_setcharsearch (typval_T *argvars, typval_T *rettv) {
    dict_T *d;
    dictitem_T *di;
    char_u *csearch;
    if (argvars[0].v_type != VAR_DICT) {
        EMSG (_ (e_dictreq));
        return;
    }
    if ((d = argvars[0].vval.v_dict) != NULL) {
        csearch = get_dict_string (d, (char_u *) "char", FALSE);
        if (csearch != NULL) {
            set_last_csearch (PTR2CHAR (csearch), csearch, MB_PTR2LEN (csearch));
        }
        di = dict_find (d, (char_u *) "forward", -1);
        if (di != NULL)
            set_csearch_direction ((int) get_tv_number (&di->di_tv) ? FORWARD : BACKWARD);
        di = dict_find (d, (char_u *) "until", -1);
        if (di != NULL)
            set_csearch_until (!!get_tv_number (&di->di_tv));
    }
}

static void f_setcmdpos (typval_T *argvars, typval_T *rettv) {
    int pos = (int) get_tv_number (&argvars[0]) - 1;
    if (pos >= 0)
        rettv->vval.v_number = set_cmdline_pos (pos);
}

static void f_setfperm (typval_T *argvars, typval_T *rettv) {
    char_u *fname;
    char_u modebuf [NUMBUFLEN];
    char_u *mode_str;
    int i;
    int mask;
    int mode = 0;
    rettv->vval.v_number = 0;
    fname = get_tv_string_chk (&argvars[0]);
    if (fname == NULL)
        return;
    mode_str = get_tv_string_buf_chk (&argvars[1], modebuf);
    if (mode_str == NULL)
        return;
    if (STRLEN (mode_str) != 9) {
        EMSG2 (_ (e_invarg2), mode_str);
        return;
    }
    mask = 1;
    for (i = 8; i >= 0; --i) {
        if (mode_str[i] != '-')
            mode |= mask;
        mask = mask << 1;
    }
    rettv->vval.v_number = mch_setperm (fname, mode) == OK;
}

static void f_setline (typval_T *argvars, typval_T *rettv) {
    linenr_T lnum = get_tv_lnum (&argvars[0]);
    set_buffer_lines (curbuf, lnum, & argvars [1], rettv);
}

static void f_setloclist (typval_T *argvars, typval_T *rettv) {
    win_T *win;
    rettv->vval.v_number = -1;
    win = find_win_by_nr (&argvars[0], NULL);
    if (win != NULL)
        set_qf_ll_list (win, &argvars[1], &argvars[2], &argvars[3], rettv);
}

static void set_qf_ll_list (win_T *wp, typval_T *list_arg, typval_T *action_arg, typval_T *what_arg, typval_T *rettv) {
    static char *e_invact = N_ ("E927: Invalid action: '%s'");
    char_u *act;
    int action = 0;
    rettv->vval.v_number = -1;
    if (list_arg->v_type != VAR_LIST)
        EMSG (_ (e_listreq));
    else {
        list_T *l = list_arg->vval.v_list;
        dict_T *d = NULL;
        int valid_dict = TRUE;
        if (action_arg->v_type == VAR_STRING) {
            act = get_tv_string_chk (action_arg);
            if (act == NULL)
                return;
            if ((*act == 'a' || *act == 'r' || *act == ' ' || *act == 'f') && act[1] == NUL)
                action = *act;
            else
                EMSG2 (_ (e_invact), act);
        }
        else if (action_arg->v_type == VAR_UNKNOWN)
            action = ' ';
        else
            EMSG (_ (e_stringreq));
        if (action_arg->v_type != VAR_UNKNOWN && what_arg->v_type != VAR_UNKNOWN) {
            if (what_arg->v_type == VAR_DICT)
                d = what_arg->vval.v_dict;
            else {
                EMSG (_ (e_dictreq));
                valid_dict = FALSE;
            }
        }
        if (l != NULL && action && valid_dict && set_errorlist (wp, l, action, (char_u *) (wp == NULL ? "setqflist()" : "setloclist()"), d) == OK)
            rettv->vval.v_number = 0;
    }
}

static void f_setmatches (typval_T *argvars, typval_T *rettv) {
    list_T *l;
    listitem_T *li;
    dict_T *d;
    list_T *s = NULL;
    rettv->vval.v_number = -1;
    if (argvars[0].v_type != VAR_LIST) {
        EMSG (_ (e_listreq));
        return;
    }
    if ((l = argvars[0].vval.v_list) != NULL) {
        li = l->lv_first;
        while (li != NULL) {
            if (li->li_tv.v_type != VAR_DICT || (d = li->li_tv.vval.v_dict) == NULL) {
                EMSG (_ (e_invarg));
                return;
            }
            if (!(dict_find (d, (char_u *) "group", -1) != NULL && (dict_find (d, (char_u *) "pattern", -1) != NULL || dict_find (d, (char_u *) "pos1", -1) != NULL) && dict_find (d, (char_u *) "priority", -1) != NULL && dict_find (d, (char_u *) "id", -1) != NULL)) {
                EMSG (_ (e_invarg));
                return;
            }
            li = li->li_next;
        }
        clear_matches (curwin);
        li = l->lv_first;
        while (li != NULL) {
            int i = 0;
            char_u buf [5];
            dictitem_T *di;
            char_u *group;
            int priority;
            int id;
            char_u *conceal;
            d = li->li_tv.vval.v_dict;
            if (dict_find (d, (char_u *) "pattern", -1) == NULL) {
                if (s == NULL) {
                    s = list_alloc ();
                    if (s == NULL)
                        return;
                }
                for (i = 1; i < 9; i++) {
                    sprintf ((char *) buf, (char *) "pos%d", i);
                    if ((di = dict_find (d, (char_u *) buf, -1)) != NULL) {
                        if (di->di_tv.v_type != VAR_LIST)
                            return;
                        list_append_tv (s, & di -> di_tv);
                        s->lv_refcount++;
                    }
                    else
                        break;
                }
            }
            group = get_dict_string (d, (char_u *) "group", TRUE);
            priority = (int) get_dict_number (d, (char_u *) "priority");
            id = (int) get_dict_number (d, (char_u *) "id");
            conceal = dict_find (d, (char_u *) "conceal", -1) != NULL ? get_dict_string (d, (char_u *) "conceal", TRUE) : NULL;
            if (i == 0) {
                match_add (curwin, group, get_dict_string (d, (char_u *) "pattern", FALSE), priority, id, NULL, conceal);
            }
            else {
                match_add (curwin, group, NULL, priority, id, s, conceal);
                list_unref (s);
                s = NULL;
            }
            vim_free (group);
            vim_free (conceal);
            li = li->li_next;
        }
        rettv->vval.v_number = 0;
    }
}

static void f_setpos (typval_T *argvars, typval_T *rettv) {
    pos_T pos;
    int fnum;
    char_u *name;
    colnr_T curswant = -1;
    rettv->vval.v_number = -1;
    name = get_tv_string_chk (argvars);
    if (name != NULL) {
        if (list2fpos (&argvars[1], &pos, &fnum, &curswant) == OK) {
            if (--pos.col < 0)
                pos.col = 0;
            if (name[0] == '.' && name[1] == NUL) {
                curwin->w_cursor = pos;
                if (curswant >= 0) {
                    curwin->w_curswant = curswant - 1;
                    curwin->w_set_curswant = FALSE;
                }
                check_cursor ();
                rettv->vval.v_number = 0;
            }
            else if (name[0] == '\'' && name[1] != NUL && name[2] == NUL) {
                if (setmark_pos (name[1], &pos, fnum) == OK)
                    rettv->vval.v_number = 0;
            }
            else
                EMSG (_ (e_invarg));
        }
    }
}

static void f_setqflist (typval_T *argvars, typval_T *rettv) {
    set_qf_ll_list (NULL, & argvars [0], & argvars [1], & argvars [2], rettv);
}

static void f_setreg (typval_T *argvars, typval_T *rettv) {
    int regname;
    char_u *strregname;
    char_u *stropt;
    char_u *strval;
    int append;
    char_u yank_type;
    long  block_len;
    block_len = -1;
    yank_type = MAUTO;
    append = FALSE;
    strregname = get_tv_string_chk (argvars);
    rettv->vval.v_number = 1;
    if (strregname == NULL)
        return;
    regname = *strregname;
    if (regname == 0 || regname == '@')
        regname = '"';
    if (argvars[2].v_type != VAR_UNKNOWN) {
        stropt = get_tv_string_chk (&argvars[2]);
        if (stropt == NULL)
            return;
        for (; *stropt != NUL; ++stropt)
            switch (*stropt) {
            case 'a' :
            case 'A' :
                append = TRUE;
                break;
            case 'v' :
            case 'c' :
                yank_type = MCHAR;
                break;
            case 'V' :
            case 'l' :
                yank_type = MLINE;
                break;
            case 'b' :
            case Ctrl_V :
                yank_type = MBLOCK;
                if (VIM_ISDIGIT (stropt[1])) {
                    ++stropt;
                    block_len = getdigits (&stropt) - 1;
                    --stropt;
                }
                break;
            }
    }
    if (argvars[1].v_type == VAR_LIST) {
        char_u **lstval;
        char_u **allocval;
        char_u buf [NUMBUFLEN];
        char_u **curval;
        char_u **curallocval;
        list_T *ll = argvars[1].vval.v_list;
        listitem_T *li;
        int len;
        len = ll == NULL ? 0 : ll->lv_len;
        lstval = (char_u **) alloc (sizeof (char_u *) * ((len + 1) * 2));
        if (lstval == NULL)
            return;
        curval = lstval;
        allocval = lstval + len + 2;
        curallocval = allocval;
        for (li = ll == NULL ? NULL : ll->lv_first; li != NULL; li = li->li_next) {
            strval = get_tv_string_buf_chk (&li->li_tv, buf);
            if (strval == NULL)
                goto free_lstval;
            if (strval == buf) {
                strval = vim_strsave (buf);
                if (strval == NULL)
                    goto free_lstval;
                *curallocval++ = strval;
            }
            *curval++ = strval;
        }
        *curval++ = NULL;
        write_reg_contents_lst (regname, lstval, - 1, append, yank_type, block_len);
    free_lstval :
        while (curallocval > allocval)
            vim_free (*--curallocval);
        vim_free (lstval);
    }
    else {
        strval = get_tv_string_chk (&argvars[1]);
        if (strval == NULL)
            return;
        write_reg_contents_ex (regname, strval, - 1, append, yank_type, block_len);
    }
    rettv->vval.v_number = 0;
}

static void f_settabvar (typval_T *argvars, typval_T *rettv) {
    tabpage_T *save_curtab;
    tabpage_T *tp;
    char_u *varname, *tabvarname;
    typval_T *varp;
    rettv->vval.v_number = 0;
    if (check_restricted () || check_secure ())
        return;
    tp = find_tabpage ((int) get_tv_number_chk (&argvars[0], NULL));
    varname = get_tv_string_chk (&argvars[1]);
    varp = &argvars[2];
    if (varname != NULL && varp != NULL && tp != NULL) {
        save_curtab = curtab;
        goto_tabpage_tp (tp, FALSE, FALSE);
        tabvarname = alloc ((unsigned ) STRLEN (varname) + 3);
        if (tabvarname != NULL) {
            STRCPY (tabvarname, "t:");
            STRCPY (tabvarname + 2, varname);
            set_var (tabvarname, varp, TRUE);
            vim_free (tabvarname);
        }
        if (valid_tabpage (save_curtab))
            goto_tabpage_tp (save_curtab, FALSE, FALSE);
    }
}

static void f_settabwinvar (typval_T *argvars, typval_T *rettv) {
    setwinvar (argvars, rettv, 1);
}

static void f_setwinvar (typval_T *argvars, typval_T *rettv) {
    setwinvar (argvars, rettv, 0);
}

static void f_sha256 (typval_T *argvars, typval_T *rettv) {
    char_u *p;
    p = get_tv_string (&argvars[0]);
    rettv->vval.v_string = vim_strsave (sha256_bytes (p, (int) STRLEN (p), NULL, 0));
    rettv->v_type = VAR_STRING;
}

static void f_shellescape (typval_T *argvars, typval_T *rettv) {
    int do_special = non_zero_arg (&argvars[1]);
    rettv->vval.v_string = vim_strsave_shellescape (get_tv_string (&argvars[0]), do_special, do_special);
    rettv->v_type = VAR_STRING;
}

static void f_shiftwidth (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = get_sw_value (curbuf);
}

static void f_simplify (typval_T *argvars, typval_T *rettv) {
    char_u *p;
    p = get_tv_string (&argvars[0]);
    rettv->vval.v_string = vim_strsave (p);
    simplify_filename (rettv -> vval.v_string);
    rettv->v_type = VAR_STRING;
}

static void f_sin (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &f) == OK)
        rettv->vval.v_float = sin (f);
    else
        rettv->vval.v_float = 0.0;
}

static void f_sinh (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &f) == OK)
        rettv->vval.v_float = sinh (f);
    else
        rettv->vval.v_float = 0.0;
}

static void f_sort (typval_T *argvars, typval_T *rettv) {
    do_sort_uniq (argvars, rettv, TRUE);
}

static void do_sort_uniq (typval_T *argvars, typval_T *rettv, int sort) {
    list_T *l;
    listitem_T *li;
    sortItem_T *ptrs;
    sortinfo_T *old_sortinfo;
    sortinfo_T info;
    long  len;
    long  i;
    old_sortinfo = sortinfo;
    sortinfo = &info;
    if (argvars[0].v_type != VAR_LIST)
        EMSG2 (_ (e_listarg), sort ? "sort()" : "uniq()");
    else {
        l = argvars[0].vval.v_list;
        if (l == NULL || tv_check_lock (l->lv_lock, (char_u *) (sort ? N_ ("sort() argument") : N_ ("uniq() argument")), TRUE))
            goto theend;
        rettv_list_set (rettv, l);
        len = list_len (l);
        if (len <= 1)
            goto theend;
        info.item_compare_ic = FALSE;
        info.item_compare_numeric = FALSE;
        info.item_compare_numbers = FALSE;
        info.item_compare_float = FALSE;
        info.item_compare_func = NULL;
        info.item_compare_partial = NULL;
        info.item_compare_selfdict = NULL;
        if (argvars[1].v_type != VAR_UNKNOWN) {
            if (argvars[1].v_type == VAR_FUNC)
                info.item_compare_func = argvars[1].vval.v_string;
            else if (argvars[1].v_type == VAR_PARTIAL)
                info.item_compare_partial = argvars[1].vval.v_partial;
            else {
                int error = FALSE;
                i = (long ) get_tv_number_chk (&argvars[1], &error);
                if (error)
                    goto theend;
                if (i == 1)
                    info.item_compare_ic = TRUE;
                else if (argvars[1].v_type != VAR_NUMBER)
                    info.item_compare_func = get_tv_string (&argvars[1]);
                else if (i != 0) {
                    EMSG (_ (e_invarg));
                    goto theend;
                }
                if (info.item_compare_func != NULL) {
                    if (*info.item_compare_func == NUL) {
                        info.item_compare_func = NULL;
                    }
                    else if (STRCMP (info.item_compare_func, "n") == 0) {
                        info.item_compare_func = NULL;
                        info.item_compare_numeric = TRUE;
                    }
                    else if (STRCMP (info.item_compare_func, "N") == 0) {
                        info.item_compare_func = NULL;
                        info.item_compare_numbers = TRUE;
                    }
                    else if (STRCMP (info.item_compare_func, "f") == 0) {
                        info.item_compare_func = NULL;
                        info.item_compare_float = TRUE;
                    }
                    else if (STRCMP (info.item_compare_func, "i") == 0) {
                        info.item_compare_func = NULL;
                        info.item_compare_ic = TRUE;
                    }
                }
            }
            if (argvars[2].v_type != VAR_UNKNOWN) {
                if (argvars[2].v_type != VAR_DICT) {
                    EMSG (_ (e_dictreq));
                    goto theend;
                }
                info.item_compare_selfdict = argvars[2].vval.v_dict;
            }
        }
        ptrs = (sortItem_T *) alloc ((int) (len * sizeof (sortItem_T)));
        if (ptrs == NULL)
            goto theend;
        i = 0;
        if (sort) {
            for (li = l->lv_first; li != NULL; li = li->li_next) {
                ptrs[i].item = li;
                ptrs[i].idx = i;
                ++i;
            }
            info.item_compare_func_err = FALSE;
            info.item_compare_keep_zero = FALSE;
            if ((info.item_compare_func != NULL || info.item_compare_partial != NULL) && item_compare2 ((void *) &ptrs[0], (void *) &ptrs[1]) == ITEM_COMPARE_FAIL)
                EMSG (_ ("E702: Sort compare function failed"));
            else {
                qsort ((void *) ptrs, (size_t) len, sizeof (sortItem_T), info.item_compare_func == NULL && info.item_compare_partial == NULL ? item_compare : item_compare2);
                if (!info.item_compare_func_err) {
                    l->lv_first = l->lv_last = l->lv_idx_item = NULL;
                    l->lv_len = 0;
                    for (i = 0; i < len; ++i)
                        list_append (l, ptrs[i].item);
                }
            }
        }
        else {
            int (*item_compare_func_ptr) (const void *, const void *);
            info.item_compare_func_err = FALSE;
            info.item_compare_keep_zero = TRUE;
            item_compare_func_ptr = info.item_compare_func != NULL || info.item_compare_partial != NULL ? item_compare2 : item_compare;
            for (li = l->lv_first; li != NULL && li->li_next != NULL; li = li->li_next) {
                if (item_compare_func_ptr ((void *) &li, (void *) &li->li_next) == 0)
                    ptrs[i++].item = li;
                if (info.item_compare_func_err) {
                    EMSG (_ ("E882: Uniq compare function failed"));
                    break;
                }
            }
            if (!info.item_compare_func_err) {
                while (--i >= 0) {
                    li = ptrs[i].item->li_next;
                    ptrs[i].item->li_next = li->li_next;
                    if (li->li_next != NULL)
                        li->li_next->li_prev = ptrs[i].item;
                    else
                        l->lv_last = ptrs[i].item;
                    list_fix_watch (l, li);
                    listitem_free (li);
                    l->lv_len--;
                }
            }
        }
        vim_free (ptrs);
    }
theend :
    sortinfo = old_sortinfo;
}

static int item_compare2 (const void *s1, const void *s2) {
    sortItem_T *si1, *si2;
    int res;
    typval_T rettv;
    typval_T argv [3];
    int dummy;
    char_u *func_name;
    partial_T *partial = sortinfo->item_compare_partial;
    if (sortinfo->item_compare_func_err)
        return 0;
    si1 = (sortItem_T *) s1;
    si2 = (sortItem_T *) s2;
    if (partial == NULL)
        func_name = sortinfo->item_compare_func;
    else
        func_name = partial_name (partial);
    copy_tv (& si1 -> item -> li_tv, & argv [0]);
    copy_tv (& si2 -> item -> li_tv, & argv [1]);
    rettv.v_type = VAR_UNKNOWN;
    res = call_func (func_name, (int) STRLEN (func_name), &rettv, 2, argv, NULL, 0L, 0L, &dummy, TRUE, partial, sortinfo->item_compare_selfdict);
    clear_tv (& argv [0]);
    clear_tv (& argv [1]);
    if (res == FAIL)
        res = ITEM_COMPARE_FAIL;
    else
        res = (int) get_tv_number_chk (&rettv, &sortinfo->item_compare_func_err);
    if (sortinfo->item_compare_func_err)
        res = ITEM_COMPARE_FAIL;
    clear_tv (& rettv);
    if (res == 0 && !sortinfo->item_compare_keep_zero)
        res = si1->idx > si2->idx ? 1 : -1;
    return res;
}

static int item_compare (const void *s1, const void *s2) {
    sortItem_T *si1, *si2;
    typval_T *tv1, *tv2;
    char_u *p1, *p2;
    char_u *tofree1 = NULL, *tofree2 = NULL;
    int res;
    char_u numbuf1 [NUMBUFLEN];
    char_u numbuf2 [NUMBUFLEN];
    si1 = (sortItem_T *) s1;
    si2 = (sortItem_T *) s2;
    tv1 = &si1->item->li_tv;
    tv2 = &si2->item->li_tv;
    if (sortinfo->item_compare_numbers) {
        varnumber_T v1 = get_tv_number (tv1);
        varnumber_T v2 = get_tv_number (tv2);
        return v1 == v2 ? 0 : v1 > v2 ? 1 : -1;
    }
    if (sortinfo->item_compare_float) {
        float_T v1 = get_tv_float (tv1);
        float_T v2 = get_tv_float (tv2);
        return v1 == v2 ? 0 : v1 > v2 ? 1 : -1;
    }
    if (tv1->v_type == VAR_STRING) {
        if (tv2->v_type != VAR_STRING || sortinfo->item_compare_numeric)
            p1 = (char_u *) "'";
        else
            p1 = tv1->vval.v_string;
    }
    else
        p1 = tv2string (tv1, &tofree1, numbuf1, 0);
    if (tv2->v_type == VAR_STRING) {
        if (tv1->v_type != VAR_STRING || sortinfo->item_compare_numeric)
            p2 = (char_u *) "'";
        else
            p2 = tv2->vval.v_string;
    }
    else
        p2 = tv2string (tv2, &tofree2, numbuf2, 0);
    if (p1 == NULL)
        p1 = (char_u *) "";
    if (p2 == NULL)
        p2 = (char_u *) "";
    if (!sortinfo->item_compare_numeric) {
        if (sortinfo->item_compare_ic)
            res = STRICMP (p1, p2);
        else
            res = STRCMP (p1, p2);
    }
    else {
        double n1, n2;
        n1 = strtod ((char *) p1, (char **) &p1);
        n2 = strtod ((char *) p2, (char **) &p2);
        res = n1 == n2 ? 0 : n1 > n2 ? 1 : -1;
    }
    if (res == 0 && !sortinfo->item_compare_keep_zero)
        res = si1->idx > si2->idx ? 1 : -1;
    vim_free (tofree1);
    vim_free (tofree2);
    return res;
}

static void f_uniq (typval_T *argvars, typval_T *rettv) {
    do_sort_uniq (argvars, rettv, FALSE);
}

static void f_soundfold (typval_T *argvars, typval_T *rettv) {
    char_u *s;
    rettv->v_type = VAR_STRING;
    s = get_tv_string (&argvars[0]);
    rettv->vval.v_string = eval_soundfold (s);
}

static void f_spellbadword (typval_T *argvars, typval_T *rettv) {
    char_u *word = (char_u *) "";
    hlf_T attr = HLF_COUNT;
    int len = 0;
    if (rettv_list_alloc (rettv) == FAIL)
        return;
    if (argvars[0].v_type == VAR_UNKNOWN) {
        len = spell_move_to (curwin, FORWARD, TRUE, TRUE, &attr);
        if (len != 0) {
            word = ml_get_cursor ();
            curwin->w_set_curswant = TRUE;
        }
    }
    else if (curwin->w_p_spell && *curbuf->b_s.b_p_spl != NUL) {
        char_u *str = get_tv_string_chk (&argvars[0]);
        int capcol = -1;
        if (str != NULL) {
            while (*str != NUL) {
                len = spell_check (curwin, str, &attr, &capcol, FALSE);
                if (attr != HLF_COUNT) {
                    word = str;
                    break;
                }
                str += len;
            }
        }
    }
    list_append_string (rettv -> vval.v_list, word, len);
    list_append_string (rettv -> vval.v_list, (char_u *) (attr == HLF_SPB ? "bad" : attr == HLF_SPR ? "rare" : attr == HLF_SPL ? "local" : attr == HLF_SPC ? "caps" : ""), - 1);
}

static void f_spellsuggest (typval_T *argvars, typval_T *rettv) {
    char_u *str;
    int typeerr = FALSE;
    int maxcount;
    garray_T ga;
    int i;
    listitem_T *li;
    int need_capital = FALSE;
    if (rettv_list_alloc (rettv) == FAIL)
        return;
    if (curwin->w_p_spell && *curwin->w_s->b_p_spl != NUL) {
        str = get_tv_string (&argvars[0]);
        if (argvars[1].v_type != VAR_UNKNOWN) {
            maxcount = (int) get_tv_number_chk (&argvars[1], &typeerr);
            if (maxcount <= 0)
                return;
            if (argvars[2].v_type != VAR_UNKNOWN) {
                need_capital = (int) get_tv_number_chk (&argvars[2], &typeerr);
                if (typeerr)
                    return;
            }
        }
        else
            maxcount = 25;
        spell_suggest_list (& ga, str, maxcount, need_capital, FALSE);
        for (i = 0; i < ga.ga_len; ++i) {
            str = ((char_u **) ga.ga_data)[i];
            li = listitem_alloc ();
            if (li == NULL)
                vim_free (str);
            else {
                li->li_tv.v_type = VAR_STRING;
                li->li_tv.v_lock = 0;
                li->li_tv.vval.v_string = str;
                list_append (rettv -> vval.v_list, li);
            }
        }
        ga_clear (& ga);
    }
}

static void f_split (typval_T *argvars, typval_T *rettv) {
    char_u *str;
    char_u *end;
    char_u *pat = NULL;
    regmatch_T regmatch;
    char_u patbuf [NUMBUFLEN];
    char_u *save_cpo;
    int match;
    colnr_T col = 0;
    int keepempty = FALSE;
    int typeerr = FALSE;
    save_cpo = p_cpo;
    p_cpo = (char_u *) "";
    str = get_tv_string (&argvars[0]);
    if (argvars[1].v_type != VAR_UNKNOWN) {
        pat = get_tv_string_buf_chk (&argvars[1], patbuf);
        if (pat == NULL)
            typeerr = TRUE;
        if (argvars[2].v_type != VAR_UNKNOWN)
            keepempty = (int) get_tv_number_chk (&argvars[2], &typeerr);
    }
    if (pat == NULL || *pat == NUL)
        pat = (char_u *) "[\\x01- ]\\+";
    if (rettv_list_alloc (rettv) == FAIL)
        return;
    if (typeerr)
        return;
    regmatch.regprog = vim_regcomp (pat, RE_MAGIC +RE_STRING);
    if (regmatch.regprog != NULL) {
        regmatch.rm_ic = FALSE;
        while (*str != NUL || keepempty) {
            if (*str == NUL)
                match = FALSE;
            else
                match = vim_regexec_nl (&regmatch, str, col);
            if (match)
                end = regmatch.startp[0];
            else
                end = str + STRLEN (str);
            if (keepempty || end > str || (rettv->vval.v_list->lv_len > 0 && *str != NUL && match && end < regmatch.endp[0])) {
                if (list_append_string (rettv->vval.v_list, str, (int) (end - str)) == FAIL)
                    break;
            }
            if (!match)
                break;
            if (regmatch.endp[0] > str)
                col = 0;
            else {
                col = 1;
            }
            str = regmatch.endp[0];
        }
        vim_regfree (regmatch.regprog);
    }
    p_cpo = save_cpo;
}

static void f_sqrt (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &f) == OK)
        rettv->vval.v_float = sqrt (f);
    else
        rettv->vval.v_float = 0.0;
}

static void f_str2float (typval_T *argvars, typval_T *rettv) {
    char_u *p = skipwhite (get_tv_string (&argvars[0]));
    int isneg = (*p == '-');
    if (*p == '+' || *p == '-')
        p = skipwhite (p +1);
    (void) string2float (p, &rettv->vval.v_float);
    if (isneg)
        rettv->vval.v_float *= -1;
    rettv->v_type = VAR_FLOAT;
}

static void f_str2nr (typval_T *argvars, typval_T *rettv) {
    int base = 10;
    char_u *p;
    varnumber_T n;
    int what;
    int isneg;
    if (argvars[1].v_type != VAR_UNKNOWN) {
        base = (int) get_tv_number (&argvars[1]);
        if (base != 2 && base != 8 && base != 10 && base != 16) {
            EMSG (_ (e_invarg));
            return;
        }
    }
    p = skipwhite (get_tv_string (&argvars[0]));
    isneg = (*p == '-');
    if (*p == '+' || *p == '-')
        p = skipwhite (p +1);
    switch (base) {
    case 2 :
        what = STR2NR_BIN + STR2NR_FORCE;
        break;
    case 8 :
        what = STR2NR_OCT + STR2NR_FORCE;
        break;
    case 16 :
        what = STR2NR_HEX + STR2NR_FORCE;
        break;
    default :
        what = 0;
    }
    vim_str2nr (p, NULL, NULL, what, & n, NULL, 0);
    if (isneg)
        rettv->vval.v_number = -n;
    else
        rettv->vval.v_number = n;
}

static void f_strgetchar (typval_T *argvars, typval_T *rettv) {
    char_u *str;
    int len;
    int error = FALSE;
    int charidx;
    rettv->vval.v_number = -1;
    str = get_tv_string_chk (&argvars[0]);
    if (str == NULL)
        return;
    len = (int) STRLEN (str);
    charidx = (int) get_tv_number_chk (&argvars[1], &error);
    if (error)
        return;
    if (charidx < len)
        rettv->vval.v_number = str[charidx];
}

static void f_stridx (typval_T *argvars, typval_T *rettv) {
    char_u buf [NUMBUFLEN];
    char_u *needle;
    char_u *haystack;
    char_u *save_haystack;
    char_u *pos;
    int start_idx;
    needle = get_tv_string_chk (&argvars[1]);
    save_haystack = haystack = get_tv_string_buf_chk (&argvars[0], buf);
    rettv->vval.v_number = -1;
    if (needle == NULL || haystack == NULL)
        return;
    if (argvars[2].v_type != VAR_UNKNOWN) {
        int error = FALSE;
        start_idx = (int) get_tv_number_chk (&argvars[2], &error);
        if (error || start_idx >= (int) STRLEN (haystack))
            return;
        if (start_idx >= 0)
            haystack += start_idx;
    }
    pos = (char_u *) strstr ((char *) haystack, (char *) needle);
    if (pos != NULL)
        rettv->vval.v_number = (varnumber_T) (pos - save_haystack);
}

static void f_string (typval_T *argvars, typval_T *rettv) {
    char_u *tofree;
    char_u numbuf [NUMBUFLEN];
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = tv2string (&argvars[0], &tofree, numbuf, get_copyID ());
    if (rettv->vval.v_string != NULL && tofree == NULL)
        rettv->vval.v_string = vim_strsave (rettv->vval.v_string);
}

static void f_strlen (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = (varnumber_T) (STRLEN (get_tv_string (&argvars[0])));
}

static void f_strchars (typval_T *argvars, typval_T *rettv) {
    char_u *s = get_tv_string (&argvars[0]);
    int skipcc = 0;
    if (argvars[1].v_type != VAR_UNKNOWN)
        skipcc = (int) get_tv_number_chk (&argvars[1], NULL);
    if (skipcc < 0 || skipcc > 1)
        EMSG (_ (e_invarg));
    else {
        rettv->vval.v_number = (varnumber_T) (STRLEN (s));
    }
}

static void f_strdisplaywidth (typval_T *argvars, typval_T *rettv) {
    char_u *s = get_tv_string (&argvars[0]);
    int col = 0;
    if (argvars[1].v_type != VAR_UNKNOWN)
        col = (int) get_tv_number (&argvars[1]);
    rettv->vval.v_number = (varnumber_T) (linetabsize_col (col, s) - col);
}

static void f_strwidth (typval_T *argvars, typval_T *rettv) {
    char_u *s = get_tv_string (&argvars[0]);
    rettv->vval.v_number = (varnumber_T) (STRLEN (s));
}

static void f_strcharpart (typval_T *argvars, typval_T *rettv) {
    f_strpart (argvars, rettv);
}

static void f_strpart (typval_T *argvars, typval_T *rettv) {
    char_u *p;
    int n;
    int len;
    int slen;
    int error = FALSE;
    p = get_tv_string (&argvars[0]);
    slen = (int) STRLEN (p);
    n = (int) get_tv_number_chk (&argvars[1], &error);
    if (error)
        len = 0;
    else if (argvars[2].v_type != VAR_UNKNOWN)
        len = (int) get_tv_number (&argvars[2]);
    else
        len = slen - n;
    if (n < 0) {
        len += n;
        n = 0;
    }
    else if (n > slen)
        n = slen;
    if (len < 0)
        len = 0;
    else if (n + len > slen)
        len = slen - n;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = vim_strnsave (p +n, len);
}

static void f_strridx (typval_T *argvars, typval_T *rettv) {
    char_u buf [NUMBUFLEN];
    char_u *needle;
    char_u *haystack;
    char_u *rest;
    char_u *lastmatch = NULL;
    int haystack_len, end_idx;
    needle = get_tv_string_chk (&argvars[1]);
    haystack = get_tv_string_buf_chk (&argvars[0], buf);
    rettv->vval.v_number = -1;
    if (needle == NULL || haystack == NULL)
        return;
    haystack_len = (int) STRLEN (haystack);
    if (argvars[2].v_type != VAR_UNKNOWN) {
        end_idx = (int) get_tv_number_chk (&argvars[2], NULL);
        if (end_idx < 0)
            return;
    }
    else
        end_idx = haystack_len;
    if (*needle == NUL) {
        lastmatch = haystack + end_idx;
    }
    else {
        for (rest = haystack; *rest != '\0'; ++rest) {
            rest = (char_u *) strstr ((char *) rest, (char *) needle);
            if (rest == NULL || rest > haystack + end_idx)
                break;
            lastmatch = rest;
        }
    }
    if (lastmatch == NULL)
        rettv->vval.v_number = -1;
    else
        rettv->vval.v_number = (varnumber_T) (lastmatch - haystack);
}

static void f_strtrans (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = transstr (get_tv_string (&argvars[0]));
}

static void f_submatch (typval_T *argvars, typval_T *rettv) {
    int error = FALSE;
    int no;
    int retList = 0;
    no = (int) get_tv_number_chk (&argvars[0], &error);
    if (error)
        return;
    if (no < 0 || no >= NSUBEXP) {
        EMSGN (_ ("E935: invalid submatch number: %d"), no);
        return;
    }
    if (argvars[1].v_type != VAR_UNKNOWN)
        retList = (int) get_tv_number_chk (&argvars[1], &error);
    if (error)
        return;
    if (retList == 0) {
        rettv->v_type = VAR_STRING;
        rettv->vval.v_string = reg_submatch (no);
    }
    else {
        rettv->v_type = VAR_LIST;
        rettv->vval.v_list = reg_submatch_list (no);
    }
}

static void f_substitute (typval_T *argvars, typval_T *rettv) {
    char_u patbuf [NUMBUFLEN];
    char_u subbuf [NUMBUFLEN];
    char_u flagsbuf [NUMBUFLEN];
    char_u *str = get_tv_string_chk (&argvars[0]);
    char_u *pat = get_tv_string_buf_chk (&argvars[1], patbuf);
    char_u *sub = NULL;
    typval_T *expr = NULL;
    char_u *flg = get_tv_string_buf_chk (&argvars[3], flagsbuf);
    if (argvars[2].v_type == VAR_FUNC || argvars[2].v_type == VAR_PARTIAL)
        expr = &argvars[2];
    else
        sub = get_tv_string_buf_chk (&argvars[2], subbuf);
    rettv->v_type = VAR_STRING;
    if (str == NULL || pat == NULL || (sub == NULL && expr == NULL) || flg == NULL)
        rettv->vval.v_string = NULL;
    else
        rettv->vval.v_string = do_string_sub (str, pat, sub, expr, flg);
}

static void f_synID (typval_T *argvars, typval_T *rettv) {
    int id = 0;
    linenr_T lnum;
    colnr_T col;
    int trans;
    int transerr = FALSE;
    lnum = get_tv_lnum (argvars);
    col = (linenr_T) get_tv_number (&argvars[1]) - 1;
    trans = (int) get_tv_number_chk (&argvars[2], &transerr);
    if (!transerr && lnum >= 1 && lnum <= curbuf->b_ml.ml_line_count && col >= 0 && col < (long ) STRLEN (ml_get (lnum)))
        id = syn_get_id (curwin, lnum, (colnr_T) col, trans, NULL, FALSE);
    rettv->vval.v_number = id;
}

static void f_synIDattr (typval_T *argvars, typval_T *rettv) {
    char_u *p = NULL;
    int id;
    char_u *what;
    char_u *mode;
    char_u modebuf [NUMBUFLEN];
    int modec;
    id = (int) get_tv_number (&argvars[0]);
    what = get_tv_string (&argvars[1]);
    if (argvars[2].v_type != VAR_UNKNOWN) {
        mode = get_tv_string_buf (&argvars[2], modebuf);
        modec = TOLOWER_ASC (mode[0]);
        if (modec != 't' && modec != 'c' && modec != 'g')
            modec = 0;
    }
    else {
        if (USE_24BIT)
            modec = 'g';
        else if (t_colors > 1)
            modec = 'c';
        else
            modec = 't';
    }
    switch (TOLOWER_ASC (what[0])) {
    case 'b' :
        if (TOLOWER_ASC (what[1]) == 'g')
            p = highlight_color (id, what, modec);
        else
            p = highlight_has_attr (id, HL_BOLD, modec);
        break;
    case 'f' :
        p = highlight_color (id, what, modec);
        break;
    case 'i' :
        if (TOLOWER_ASC (what[1]) == 'n')
            p = highlight_has_attr (id, HL_INVERSE, modec);
        else
            p = highlight_has_attr (id, HL_ITALIC, modec);
        break;
    case 'n' :
        p = get_highlight_name_ext (NULL, id -1, FALSE);
        break;
    case 'r' :
        p = highlight_has_attr (id, HL_INVERSE, modec);
        break;
    case 's' :
        if (TOLOWER_ASC (what[1]) == 'p')
            p = highlight_color (id, what, modec);
        else if (TOLOWER_ASC (what[1]) == 't' && TOLOWER_ASC (what[2]) == 'r')
            p = highlight_has_attr (id, HL_STRIKETHROUGH, modec);
        else
            p = highlight_has_attr (id, HL_STANDOUT, modec);
        break;
    case 'u' :
        if (STRLEN (what) <= 5 || TOLOWER_ASC (what[5]) != 'c')
            p = highlight_has_attr (id, HL_UNDERLINE, modec);
        else
            p = highlight_has_attr (id, HL_UNDERCURL, modec);
        break;
    }
    if (p != NULL)
        p = vim_strsave (p);
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = p;
}

static void f_synIDtrans (typval_T *argvars, typval_T *rettv) {
    int id;
    id = (int) get_tv_number (&argvars[0]);
    if (id > 0)
        id = syn_get_final_id (id);
    else
        id = 0;
    rettv->vval.v_number = id;
}

static void f_synconcealed (typval_T *argvars, typval_T *rettv) {
    linenr_T lnum;
    colnr_T col;
    int syntax_flags = 0;
    int cchar;
    int matchid = 0;
    char_u str [NUMBUFLEN];
    rettv_list_set (rettv, NULL);
    lnum = get_tv_lnum (argvars);
    col = (colnr_T) get_tv_number (&argvars[1]) - 1;
    vim_memset (str, NUL, sizeof (str));
    if (rettv_list_alloc (rettv) != FAIL) {
        if (lnum >= 1 && lnum <= curbuf->b_ml.ml_line_count && col >= 0 && col <= (long ) STRLEN (ml_get (lnum)) && curwin->w_p_cole > 0) {
            (void) syn_get_id (curwin, lnum, col, FALSE, NULL, FALSE);
            syntax_flags = get_syntax_info (&matchid);
            if ((syntax_flags & HL_CONCEAL) && curwin->w_p_cole < 3) {
                cchar = syn_get_sub_char ();
                if (cchar == NUL && curwin->w_p_cole == 1)
                    cchar = (lcs_conceal == NUL) ? ' ' : lcs_conceal;
                if (cchar != NUL) {
                    str[0] = cchar;
                }
            }
        }
        list_append_number (rettv -> vval.v_list, (syntax_flags & HL_CONCEAL) != 0);
        list_append_string (rettv -> vval.v_list, str, - 1);
        list_append_number (rettv -> vval.v_list, matchid);
    }
}

static void f_synstack (typval_T *argvars, typval_T *rettv) {
    linenr_T lnum;
    colnr_T col;
    int i;
    int id;
    rettv_list_set (rettv, NULL);
    lnum = get_tv_lnum (argvars);
    col = (colnr_T) get_tv_number (&argvars[1]) - 1;
    if (lnum >= 1 && lnum <= curbuf->b_ml.ml_line_count && col >= 0 && col <= (long ) STRLEN (ml_get (lnum)) && rettv_list_alloc (rettv) != FAIL) {
        (void) syn_get_id (curwin, lnum, (colnr_T) col, FALSE, NULL, TRUE);
        for (i = 0;; ++i) {
            id = syn_get_stack_item (i);
            if (id < 0)
                break;
            if (list_append_number (rettv->vval.v_list, id) == FAIL)
                break;
        }
    }
}

static void f_system (typval_T *argvars, typval_T *rettv) {
    get_cmd_output_as_rettv (argvars, rettv, FALSE);
}

static void get_cmd_output_as_rettv (typval_T *argvars, typval_T *rettv, int retlist) {
    char_u *res = NULL;
    char_u *p;
    char_u *infile = NULL;
    int err = FALSE;
    FILE *fd;
    list_T *list = NULL;
    int flags = SHELL_SILENT;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    if (check_restricted () || check_secure ())
        goto errret;
    if (argvars[1].v_type != VAR_UNKNOWN) {
        if ((infile = vim_tempname ('i', TRUE)) == NULL) {
            EMSG (_ (e_notmp));
            goto errret;
        }
        fd = mch_fopen ((char *) infile, WRITEBIN);
        if (fd == NULL) {
            EMSG2 (_ (e_notopen), infile);
            goto errret;
        }
        if (argvars[1].v_type == VAR_NUMBER) {
            linenr_T lnum;
            buf_T *buf;
            buf = buflist_findnr (argvars[1].vval.v_number);
            if (buf == NULL) {
                EMSGN (_ (e_nobufnr), argvars [1].vval.v_number);
                fclose (fd);
                goto errret;
            }
            for (lnum = 1; lnum <= buf->b_ml.ml_line_count; lnum++) {
                for (p = ml_get_buf (buf, lnum, FALSE); *p != NUL; ++p)
                    if (putc (*p == '\n' ? NUL : *p, fd) == EOF) {
                        err = TRUE;
                        break;
                    }
                if (putc (NL, fd) == EOF) {
                    err = TRUE;
                    break;
                }
            }
        }
        else if (argvars[1].v_type == VAR_LIST) {
            if (write_list (fd, argvars[1].vval.v_list, TRUE) == FAIL)
                err = TRUE;
        }
        else {
            size_t len;
            char_u buf [NUMBUFLEN];
            p = get_tv_string_buf_chk (&argvars[1], buf);
            if (p == NULL) {
                fclose (fd);
                goto errret;
            }
            len = STRLEN (p);
            if (len > 0 && fwrite (p, len, 1, fd) != 1)
                err = TRUE;
        }
        if (fclose (fd) != 0)
            err = TRUE;
        if (err) {
            EMSG (_ ("E677: Error writing temp file"));
            goto errret;
        }
    }
    if (!msg_silent)
        flags += SHELL_COOKED;
    if (retlist) {
        int len;
        listitem_T *li;
        char_u *s = NULL;
        char_u *start;
        char_u *end;
        int i;
        res = get_cmd_output (get_tv_string (&argvars[0]), infile, flags, &len);
        if (res == NULL)
            goto errret;
        list = list_alloc ();
        if (list == NULL)
            goto errret;
        for (i = 0; i < len; ++i) {
            start = res + i;
            while (i < len && res[i] != NL)
                ++i;
            end = res + i;
            s = alloc ((unsigned ) (end - start + 1));
            if (s == NULL)
                goto errret;
            for (p = s; start < end; ++p, ++start)
                *p = *start == NUL ? NL : *start;
            *p = NUL;
            li = listitem_alloc ();
            if (li == NULL) {
                vim_free (s);
                goto errret;
            }
            li->li_tv.v_type = VAR_STRING;
            li->li_tv.v_lock = 0;
            li->li_tv.vval.v_string = s;
            list_append (list, li);
        }
        rettv_list_set (rettv, list);
        list = NULL;
    }
    else {
        res = get_cmd_output (get_tv_string (&argvars[0]), infile, flags, NULL);
        rettv->vval.v_string = res;
        res = NULL;
    }
errret :
    if (infile != NULL) {
        mch_remove (infile);
        vim_free (infile);
    }
    if (res != NULL)
        vim_free (res);
    if (list != NULL)
        list_free (list);
}

static void f_systemlist (typval_T *argvars, typval_T *rettv) {
    get_cmd_output_as_rettv (argvars, rettv, TRUE);
}

static void f_tabpagebuflist (typval_T *argvars, typval_T *rettv) {
    tabpage_T *tp;
    win_T *wp = NULL;
    if (argvars[0].v_type == VAR_UNKNOWN)
        wp = firstwin;
    else {
        tp = find_tabpage ((int) get_tv_number (&argvars[0]));
        if (tp != NULL)
            wp = (tp == curtab) ? firstwin : tp->tp_firstwin;
    }
    if (wp != NULL && rettv_list_alloc (rettv) != FAIL) {
        for (; wp != NULL; wp = wp->w_next)
            if (list_append_number (rettv->vval.v_list, wp->w_buffer->b_fnum) == FAIL)
                break;
    }
}

static void f_tabpagenr (typval_T *argvars, typval_T *rettv) {
    int nr = 1;
    char_u *arg;
    if (argvars[0].v_type != VAR_UNKNOWN) {
        arg = get_tv_string_chk (&argvars[0]);
        nr = 0;
        if (arg != NULL) {
            if (STRCMP (arg, "$") == 0)
                nr = tabpage_index (NULL) - 1;
            else
                EMSG2 (_ (e_invexpr2), arg);
        }
    }
    else
        nr = tabpage_index (curtab);
    rettv->vval.v_number = nr;
}

static void f_tabpagewinnr (typval_T *argvars, typval_T *rettv) {
    int nr = 1;
    tabpage_T *tp;
    tp = find_tabpage ((int) get_tv_number (&argvars[0]));
    if (tp == NULL)
        nr = 0;
    else
        nr = get_winnr (tp, &argvars[1]);
    rettv->vval.v_number = nr;
}

static int get_winnr (tabpage_T *tp, typval_T *argvar) {
    win_T *twin;
    int nr = 1;
    win_T *wp;
    char_u *arg;
    twin = (tp == curtab) ? curwin : tp->tp_curwin;
    if (argvar->v_type != VAR_UNKNOWN) {
        arg = get_tv_string_chk (argvar);
        if (arg == NULL)
            nr = 0;
        else if (STRCMP (arg, "$") == 0)
            twin = (tp == curtab) ? lastwin : tp->tp_lastwin;
        else if (STRCMP (arg, "#") == 0) {
            twin = (tp == curtab) ? prevwin : tp->tp_prevwin;
            if (twin == NULL)
                nr = 0;
        }
        else {
            EMSG2 (_ (e_invexpr2), arg);
            nr = 0;
        }
    }
    if (nr > 0)
        for (wp = (tp == curtab) ? firstwin : tp->tp_firstwin; wp != twin; wp = wp->w_next) {
            if (wp == NULL) {
                nr = 0;
                break;
            }
            ++nr;
        }
    return nr;
}

static void f_tagfiles (typval_T *argvars, typval_T *rettv) {
    char_u *fname;
    tagname_T tn;
    int first;
    if (rettv_list_alloc (rettv) == FAIL)
        return;
    fname = alloc (MAXPATHL);
    if (fname == NULL)
        return;
    for (first = TRUE;; first = FALSE)
        if (get_tagfname (&tn, first, fname) == FAIL || list_append_string (rettv->vval.v_list, fname, -1) == FAIL)
            break;
    tagname_free (& tn);
    vim_free (fname);
}

static void f_taglist (typval_T *argvars, typval_T *rettv) {
    char_u *fname = NULL;
    char_u *tag_pattern;
    tag_pattern = get_tv_string (&argvars[0]);
    rettv->vval.v_number = FALSE;
    if (*tag_pattern == NUL)
        return;
    if (argvars[1].v_type != VAR_UNKNOWN)
        fname = get_tv_string (&argvars[1]);
    if (rettv_list_alloc (rettv) == OK)
        (void) get_tags (rettv->vval.v_list, tag_pattern, fname);
}

static void f_tempname (typval_T *argvars, typval_T *rettv) {
    static int x = 'A';
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = vim_tempname (x, FALSE);
    do {
        if (x == 'Z')
            x = '0';
        else if (x == '9')
            x = 'A';
        else {
            ++x;
        }
    }
    while (x == 'I' || x == 'O');
}

static void f_tan (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &f) == OK)
        rettv->vval.v_float = tan (f);
    else
        rettv->vval.v_float = 0.0;
}

static void f_tanh (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &f) == OK)
        rettv->vval.v_float = tanh (f);
    else
        rettv->vval.v_float = 0.0;
}

static void f_test_alloc_fail (typval_T *argvars, typval_T *rettv) {
    if (argvars[0].v_type != VAR_NUMBER || argvars[0].vval.v_number <= 0 || argvars[1].v_type != VAR_NUMBER || argvars[1].vval.v_number < 0 || argvars[2].v_type != VAR_NUMBER)
        EMSG (_ (e_invarg));
    else {
        alloc_fail_id = argvars[0].vval.v_number;
        if (alloc_fail_id >= aid_last)
            EMSG (_ (e_invarg));
        alloc_fail_countdown = argvars[1].vval.v_number;
        alloc_fail_repeat = argvars[2].vval.v_number;
        did_outofmem_msg = FALSE;
    }
}

static void f_test_autochdir (typval_T *argvars, typval_T *rettv) {
    test_autochdir = TRUE;
}

static void f_test_feedinput (typval_T *argvars, typval_T *rettv) {
}

static void f_test_override (typval_T *argvars, typval_T *rettv) {
    char_u *name = (char_u *) "";
    int val;
    static int save_starting = -1;
    if (argvars[0].v_type != VAR_STRING || (argvars[1].v_type) != VAR_NUMBER)
        EMSG (_ (e_invarg));
    else {
        name = get_tv_string_chk (&argvars[0]);
        val = (int) get_tv_number (&argvars[1]);
        if (STRCMP (name, (char_u *) "redraw") == 0)
            disable_redraw_for_testing = val;
        else if (STRCMP (name, (char_u *) "char_avail") == 0)
            disable_char_avail_for_testing = val;
        else if (STRCMP (name, (char_u *) "starting") == 0) {
            if (val) {
                if (save_starting < 0)
                    save_starting = starting;
                starting = 0;
            }
            else {
                starting = save_starting;
                save_starting = -1;
            }
        }
        else if (STRCMP (name, (char_u *) "ALL") == 0) {
            disable_char_avail_for_testing = FALSE;
            disable_redraw_for_testing = FALSE;
            if (save_starting >= 0) {
                starting = save_starting;
                save_starting = -1;
            }
        }
        else
            EMSG2 (_ (e_invarg2), name);
    }
}

static void f_test_garbagecollect_now (typval_T *argvars, typval_T *rettv) {
    garbage_collect (TRUE);
}

static void f_test_ignore_error (typval_T *argvars, typval_T *rettv) {
    ignore_error_for_testing (get_tv_string (& argvars [0]));
}

static void f_test_null_channel (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_CHANNEL;
    rettv->vval.v_channel = NULL;
}

static void f_test_null_dict (typval_T *argvars, typval_T *rettv) {
    rettv_dict_set (rettv, NULL);
}

static void f_test_null_job (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_JOB;
    rettv->vval.v_job = NULL;
}

static void f_test_null_list (typval_T *argvars, typval_T *rettv) {
    rettv_list_set (rettv, NULL);
}

static void f_test_null_partial (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_PARTIAL;
    rettv->vval.v_partial = NULL;
}

static void f_test_null_string (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
}

static void f_test_settime (typval_T *argvars, typval_T *rettv) {
    time_for_testing = (time_t) get_tv_number (&argvars[0]);
}

static void f_timer_info (typval_T *argvars, typval_T *rettv) {
    timer_T *timer = NULL;
    if (rettv_list_alloc (rettv) != OK)
        return;
    if (argvars[0].v_type != VAR_UNKNOWN) {
        if (argvars[0].v_type != VAR_NUMBER)
            EMSG (_ (e_number_exp));
        else {
            timer = find_timer ((int) get_tv_number (&argvars[0]));
            if (timer != NULL)
                add_timer_info (rettv, timer);
        }
    }
    else
        add_timer_info_all (rettv);
}

static void f_timer_pause (typval_T *argvars, typval_T *rettv) {
    timer_T *timer = NULL;
    int paused = (int) get_tv_number (&argvars[1]);
    if (argvars[0].v_type != VAR_NUMBER)
        EMSG (_ (e_number_exp));
    else {
        timer = find_timer ((int) get_tv_number (&argvars[0]));
        if (timer != NULL)
            timer->tr_paused = paused;
    }
}

static void f_timer_start (typval_T *argvars, typval_T *rettv) {
    long  msec = (long ) get_tv_number (&argvars[0]);
    timer_T *timer;
    int repeat = 0;
    char_u *callback;
    dict_T *dict;
    partial_T *partial;
    rettv->vval.v_number = -1;
    if (check_secure ())
        return;
    if (argvars[2].v_type != VAR_UNKNOWN) {
        if (argvars[2].v_type != VAR_DICT || (dict = argvars[2].vval.v_dict) == NULL) {
            EMSG2 (_ (e_invarg2), get_tv_string (& argvars [2]));
            return;
        }
        if (dict_find (dict, (char_u *) "repeat", -1) != NULL)
            repeat = get_dict_number (dict, (char_u *) "repeat");
    }
    callback = get_callback (&argvars[1], &partial);
    if (callback == NULL)
        return;
    timer = create_timer (msec, repeat);
    if (timer == NULL)
        free_callback (callback, partial);
    else {
        if (partial == NULL)
            timer->tr_callback = vim_strsave (callback);
        else
            timer->tr_callback = callback;
        timer->tr_partial = partial;
        rettv->vval.v_number = (varnumber_T) timer->tr_id;
    }
}

static void f_timer_stop (typval_T *argvars, typval_T *rettv) {
    timer_T *timer;
    if (argvars[0].v_type != VAR_NUMBER) {
        EMSG (_ (e_number_exp));
        return;
    }
    timer = find_timer ((int) get_tv_number (&argvars[0]));
    if (timer != NULL)
        stop_timer (timer);
}

static void f_timer_stopall (typval_T *argvars, typval_T *rettv) {
    stop_all_timers ();
}

static void f_tolower (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = strlow_save (get_tv_string (&argvars[0]));
}

static void f_toupper (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = strup_save (get_tv_string (&argvars[0]));
}

static void f_tr (typval_T *argvars, typval_T *rettv) {
    char_u *in_str;
    char_u *fromstr;
    char_u *tostr;
    char_u *p;
    char_u buf [NUMBUFLEN];
    char_u buf2 [NUMBUFLEN];
    garray_T ga;
    in_str = get_tv_string (&argvars[0]);
    fromstr = get_tv_string_buf_chk (&argvars[1], buf);
    tostr = get_tv_string_buf_chk (&argvars[2], buf2);
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    if (fromstr == NULL || tostr == NULL)
        return;
    ga_init2 (& ga, (int) sizeof (char), 80);
    if (STRLEN (fromstr) != STRLEN (tostr)) {
        EMSG2 (_ (e_invarg2), fromstr);
        ga_clear (& ga);
        return;
    }
    while (*in_str != NUL) {
        {
            p = vim_strchr (fromstr, *in_str);
            if (p != NULL)
                ga_append (&ga, tostr[p - fromstr]);
            else
                ga_append (&ga, *in_str);
            ++in_str;
        }
    }
    (void) ga_grow (&ga, 1);
    ga_append (& ga, NUL);
    rettv->vval.v_string = ga.ga_data;
}

static void f_trunc (typval_T *argvars, typval_T *rettv) {
    float_T f = 0.0;
    rettv->v_type = VAR_FLOAT;
    if (get_float_arg (argvars, &f) == OK)
        rettv->vval.v_float = f > 0 ? floor (f) : ceil (f);
    else
        rettv->vval.v_float = 0.0;
}

static void f_type (typval_T *argvars, typval_T *rettv) {
    int n = -1;
    switch (argvars[0].v_type) {
    case VAR_NUMBER :
        n = VAR_TYPE_NUMBER;
        break;
    case VAR_STRING :
        n = VAR_TYPE_STRING;
        break;
    case VAR_PARTIAL :
    case VAR_FUNC :
        n = VAR_TYPE_FUNC;
        break;
    case VAR_LIST :
        n = VAR_TYPE_LIST;
        break;
    case VAR_DICT :
        n = VAR_TYPE_DICT;
        break;
    case VAR_FLOAT :
        n = VAR_TYPE_FLOAT;
        break;
    case VAR_SPECIAL :
        if (argvars[0].vval.v_number == VVAL_FALSE || argvars[0].vval.v_number == VVAL_TRUE)
            n = VAR_TYPE_BOOL;
        else
            n = VAR_TYPE_NONE;
        break;
    case VAR_JOB :
        n = VAR_TYPE_JOB;
        break;
    case VAR_CHANNEL :
        n = VAR_TYPE_CHANNEL;
        break;
    case VAR_UNKNOWN :
        internal_error ("f_type(UNKNOWN)");
        n = -1;
        break;
    }
    rettv->vval.v_number = n;
}

static void f_undofile (typval_T *argvars, typval_T *rettv) {
    rettv->v_type = VAR_STRING;
    {
        char_u *fname = get_tv_string (&argvars[0]);
        if (*fname == NUL) {
            rettv->vval.v_string = NULL;
        }
        else {
            char_u *ffname = FullName_save (fname, FALSE);
            if (ffname != NULL)
                rettv->vval.v_string = u_get_undo_file_name (ffname, FALSE);
            vim_free (ffname);
        }
    }
}

static void f_undotree (typval_T *argvars, typval_T *rettv) {
    if (rettv_dict_alloc (rettv) == OK) {
        dict_T *dict = rettv->vval.v_dict;
        list_T *list;
        dict_add_nr_str (dict, "synced", (long) curbuf -> b_u_synced, NULL);
        dict_add_nr_str (dict, "seq_last", curbuf -> b_u_seq_last, NULL);
        dict_add_nr_str (dict, "save_last", (long) curbuf -> b_u_save_nr_last, NULL);
        dict_add_nr_str (dict, "seq_cur", curbuf -> b_u_seq_cur, NULL);
        dict_add_nr_str (dict, "time_cur", (long) curbuf -> b_u_time_cur, NULL);
        dict_add_nr_str (dict, "save_cur", (long) curbuf -> b_u_save_nr_cur, NULL);
        list = list_alloc ();
        if (list != NULL) {
            u_eval_tree (curbuf -> b_u_oldhead, list);
            dict_add_list (dict, "entries", list);
        }
    }
}

static void f_values (typval_T *argvars, typval_T *rettv) {
    dict_list (argvars, rettv, 1);
}

static void f_virtcol (typval_T *argvars, typval_T *rettv) {
    colnr_T vcol = 0;
    pos_T *fp;
    int fnum = curbuf->b_fnum;
    fp = var2fpos (&argvars[0], FALSE, &fnum);
    if (fp != NULL && fp->lnum <= curbuf->b_ml.ml_line_count && fnum == curbuf->b_fnum) {
        getvvcol (curwin, fp, NULL, NULL, & vcol);
        ++vcol;
    }
    rettv->vval.v_number = vcol;
}

static void f_visualmode (typval_T *argvars, typval_T *rettv) {
    char_u str [2];
    rettv->v_type = VAR_STRING;
    str[0] = curbuf->b_visual_mode_eval;
    str[1] = NUL;
    rettv->vval.v_string = vim_strsave (str);
    if (non_zero_arg (&argvars[0]))
        curbuf->b_visual_mode_eval = NUL;
}

static void f_wildmenumode (typval_T *argvars, typval_T *rettv) {
    if (wild_menu_showing)
        rettv->vval.v_number = 1;
}

static void f_winbufnr (typval_T *argvars, typval_T *rettv) {
    win_T *wp;
    wp = find_win_by_nr (&argvars[0], NULL);
    if (wp == NULL)
        rettv->vval.v_number = -1;
    else
        rettv->vval.v_number = wp->w_buffer->b_fnum;
}

static void f_wincol (typval_T *argvars, typval_T *rettv) {
    validate_cursor ();
    rettv->vval.v_number = curwin->w_wcol + 1;
}

static void f_winheight (typval_T *argvars, typval_T *rettv) {
    win_T *wp;
    wp = find_win_by_nr (&argvars[0], NULL);
    if (wp == NULL)
        rettv->vval.v_number = -1;
    else
        rettv->vval.v_number = wp->w_height;
}

static void f_winline (typval_T *argvars, typval_T *rettv) {
    validate_cursor ();
    rettv->vval.v_number = curwin->w_wrow + 1;
}

static void f_winnr (typval_T *argvars, typval_T *rettv) {
    int nr = 1;
    nr = get_winnr (curtab, &argvars[0]);
    rettv->vval.v_number = nr;
}

static void f_winrestcmd (typval_T *argvars, typval_T *rettv) {
    win_T *wp;
    int winnr = 1;
    garray_T ga;
    char_u buf [50];
    ga_init2 (& ga, (int) sizeof (char), 70);
    FOR_ALL_WINDOWS (wp) {
        sprintf ((char *) buf, "%dresize %d|", winnr, wp -> w_height);
        ga_concat (& ga, buf);
        sprintf ((char *) buf, "vert %dresize %d|", winnr, wp -> w_width);
        ga_concat (& ga, buf);
        ++winnr;
    }
    ga_append (& ga, NUL);
    rettv->vval.v_string = ga.ga_data;
    rettv->v_type = VAR_STRING;
}

static void f_winrestview (typval_T *argvars, typval_T *rettv) {
    dict_T *dict;
    if (argvars[0].v_type != VAR_DICT || (dict = argvars[0].vval.v_dict) == NULL)
        EMSG (_ (e_invarg));
    else {
        if (dict_find (dict, (char_u *) "lnum", -1) != NULL)
            curwin->w_cursor.lnum = (linenr_T) get_dict_number (dict, (char_u *) "lnum");
        if (dict_find (dict, (char_u *) "col", -1) != NULL)
            curwin->w_cursor.col = (colnr_T) get_dict_number (dict, (char_u *) "col");
        if (dict_find (dict, (char_u *) "coladd", -1) != NULL)
            curwin->w_cursor.coladd = (colnr_T) get_dict_number (dict, (char_u *) "coladd");
        if (dict_find (dict, (char_u *) "curswant", -1) != NULL) {
            curwin->w_curswant = (colnr_T) get_dict_number (dict, (char_u *) "curswant");
            curwin->w_set_curswant = FALSE;
        }
        if (dict_find (dict, (char_u *) "topline", -1) != NULL)
            set_topline (curwin, (linenr_T) get_dict_number (dict, (char_u *) "topline"));
        if (dict_find (dict, (char_u *) "topfill", -1) != NULL)
            curwin->w_topfill = (int) get_dict_number (dict, (char_u *) "topfill");
        if (dict_find (dict, (char_u *) "leftcol", -1) != NULL)
            curwin->w_leftcol = (colnr_T) get_dict_number (dict, (char_u *) "leftcol");
        if (dict_find (dict, (char_u *) "skipcol", -1) != NULL)
            curwin->w_skipcol = (colnr_T) get_dict_number (dict, (char_u *) "skipcol");
        check_cursor ();
        win_new_height (curwin, curwin -> w_height);
        win_new_width (curwin, curwin -> w_width);
        changed_window_setting ();
        if (curwin->w_topline <= 0)
            curwin->w_topline = 1;
        if (curwin->w_topline > curbuf->b_ml.ml_line_count)
            curwin->w_topline = curbuf->b_ml.ml_line_count;
        check_topfill (curwin, TRUE);
    }
}

static void f_winsaveview (typval_T *argvars, typval_T *rettv) {
    dict_T *dict;
    if (rettv_dict_alloc (rettv) == FAIL)
        return;
    dict = rettv->vval.v_dict;
    dict_add_nr_str (dict, "lnum", (long) curwin -> w_cursor.lnum, NULL);
    dict_add_nr_str (dict, "col", (long) curwin -> w_cursor.col, NULL);
    dict_add_nr_str (dict, "coladd", (long) curwin -> w_cursor.coladd, NULL);
    update_curswant ();
    dict_add_nr_str (dict, "curswant", (long) curwin -> w_curswant, NULL);
    dict_add_nr_str (dict, "topline", (long) curwin -> w_topline, NULL);
    dict_add_nr_str (dict, "topfill", (long) curwin -> w_topfill, NULL);
    dict_add_nr_str (dict, "leftcol", (long) curwin -> w_leftcol, NULL);
    dict_add_nr_str (dict, "skipcol", (long) curwin -> w_skipcol, NULL);
}

static void f_winwidth (typval_T *argvars, typval_T *rettv) {
    win_T *wp;
    wp = find_win_by_nr (&argvars[0], NULL);
    if (wp == NULL)
        rettv->vval.v_number = -1;
    else
        rettv->vval.v_number = wp->w_width;
}

static void f_wordcount (typval_T *argvars, typval_T *rettv) {
    if (rettv_dict_alloc (rettv) == FAIL)
        return;
    cursor_pos_info (rettv -> vval.v_dict);
}

static void f_writefile (typval_T *argvars, typval_T *rettv) {
    int binary = FALSE;
    int append = FALSE;
    char_u *fname;
    FILE *fd;
    int ret = 0;
    listitem_T *li;
    list_T *list;
    rettv->vval.v_number = -1;
    if (check_restricted () || check_secure ())
        return;
    if (argvars[0].v_type != VAR_LIST) {
        EMSG2 (_ (e_listarg), "writefile()");
        return;
    }
    list = argvars[0].vval.v_list;
    if (list == NULL)
        return;
    for (li = list->lv_first; li != NULL; li = li->li_next)
        if (get_tv_string_chk (&li->li_tv) == NULL)
            return;
    if (argvars[2].v_type != VAR_UNKNOWN) {
        char_u *arg2 = get_tv_string_chk (&argvars[2]);
        if (arg2 == NULL)
            return;
        if (vim_strchr (arg2, 'b') != NULL)
            binary = TRUE;
        if (vim_strchr (arg2, 'a') != NULL)
            append = TRUE;
    }
    fname = get_tv_string_chk (&argvars[1]);
    if (fname == NULL)
        return;
    if (*fname == NUL || (fd = mch_fopen ((char *) fname, append ? APPENDBIN : WRITEBIN)) == NULL) {
        EMSG2 (_ (e_notcreate), * fname == NUL ? (char_u *) _ ("<empty>") : fname);
        ret = -1;
    }
    else {
        if (write_list (fd, list, binary) == FAIL)
            ret = -1;
        fclose (fd);
    }
    rettv->vval.v_number = ret;
}

static void f_xor (typval_T *argvars, typval_T *rettv) {
    rettv->vval.v_number = get_tv_number_chk (&argvars[0], NULL) ^ get_tv_number_chk (&argvars[1], NULL);
}

