
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
struct signalinfo {
    int sig;
    char *name;
    char deadly;
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
EXTERN char_u *serverName INIT (= NULL);
EXTERN char_u e_notread [] INIT (= N_ ("E485: Can't read file %s"));
EXTERN char_u e_wildexpand [] INIT (= N_ ("E79: Cannot expand wildcards"));
EXTERN char_u *p_sh;
EXTERN long  p_wd;
EXTERN int ignored;
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u *p_titlestring;
EXTERN int arrow_used;
EXTERN int mouse_row;
EXTERN char_u *globaldir INIT (= NULL);
EXTERN char_u e_toomanyarg [] INIT (= N_ ("E118: Too many arguments for function: %s"));
EXTERN char_u e_argreq [] INIT (= N_ ("E471: Argument required"));
char_u *extra_shell_arg = NULL;
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
RETSIGTYPE deathtrap SIGPROTOARG;
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
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
struct signalinfo signal_info [] = {{-1, "Unknown!", FALSE}};
volatile int deadly_signal = 0;
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
int dont_check_job_ended = 0;
volatile int in_mch_delay = FALSE;
char_u *oldicon = NULL;
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
int curr_tmode = TMODE_COOK;
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
int did_set_icon = FALSE;
int did_set_title = FALSE;
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
volatile int do_resize = FALSE;
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
int show_shell_mess = TRUE;
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

int vim_is_iris (char_u *name) {
    if (name == NULL)
        return FALSE;
    return (STRNICMP (name, "iris-ansi", 9) == 0 || STRCMP (name, "builtin_iris-ansi") == 0);
}

int vim_is_xterm (char_u *name) {
    if (name == NULL)
        return FALSE;
    return (STRNICMP (name, "xterm", 5) == 0 || STRNICMP (name, "nxterm", 6) == 0 || STRNICMP (name, "kterm", 5) == 0 || STRNICMP (name, "mlterm", 6) == 0 || STRNICMP (name, "rxvt", 4) == 0 || STRNICMP (name, "screen.xterm", 12) == 0 || STRCMP (name, "builtin_xterm") == 0);
}

static int WaitForChar (long  msec, int *interrupted, int ignore_input) {
    return ui_wait_for_chars_or_timer (msec, WaitForCharOrMouse, interrupted, ignore_input) == OK;
}

static int WaitForCharOrMouse (long  msec, int *interrupted, int ignore_input) {
    int avail;
    if (!ignore_input && input_available ())
        return 1;
    if (WantQueryMouse) {
        WantQueryMouse = FALSE;
        mch_write ((char_u *) IF_EB ("\033[1'|", ESC_STR "[1'|"), 5);
    }
    avail = RealWaitForChar (read_cmd_fd, msec, NULL, interrupted);
    return avail;
}

void mch_write (char_u *s, int len) {
    ignored = (int) write (1, (char *) s, len);
    if (p_wd)
        RealWaitForChar (read_cmd_fd, p_wd, NULL, NULL);
}

static int RealWaitForChar (int fd, long  msec, int *check_for_gpm, int *interrupted) {
    int ret;
    int result;
    {
        struct pollfd fds [6 + 3 * MAX_OPEN_CHANNELS];
        int nfd;
        int towait = (int) msec;
        fds[0].fd = fd;
        fds[0].events = POLLIN;
        nfd = 1;
        nfd = channel_poll_setup (nfd, &fds, &towait);
        if (interrupted != NULL)
            *interrupted = FALSE;
        ret = poll (fds, nfd, towait);
        result = ret > 0 && (fds[0].revents & POLLIN);
        if (result == 0 && interrupted != NULL && ret > 0)
            *interrupted = TRUE;
        if (ret >= 0)
            ret = channel_poll_check (ret, &fds);
    }
    return result;
}

static void handle_resize (void) {
    do_resize = FALSE;
    shell_resized ();
}

int mch_expand_wildcards (int num_pat, char_u **pat, int *num_file, char_u ***file, int flags) {
    int i;
    size_t len;
    long  llen;
    char_u *p;
    int dir;
    int j;
    char_u *tempname;
    char_u *command;
    FILE *fd;
    char_u *buffer;

    #define STYLE_ECHO	0	/* use "echo", the default */

    #define STYLE_GLOB	1	/* use "glob", for csh */

    #define STYLE_VIMGLOB	2	/* use "vimglob", for Posix sh */

    #define STYLE_PRINT	3	/* use "print -N", for zsh */

    #define STYLE_BT	4	/* `cmd` expansion, execute the pattern
				 * directly */
    int shell_style = STYLE_ECHO;
    int check_spaces;
    static int did_find_nul = FALSE;
    int ampersent = FALSE;
    static char *sh_vimglob_func = "vimglob() { while [ $# -ge 1 ]; do echo \"$1\"; shift; done }; vimglob >";
    *num_file = 0;
    *file = NULL;
    if (!have_wildcard (num_pat, pat))
        return save_patterns (num_pat, pat, num_file, file);
    if (secure || restricted)
        for (i = 0; i < num_pat; ++i)
            if (vim_strchr (pat[i], '`') != NULL && (check_restricted () || check_secure ()))
                return FAIL;
    if ((tempname = vim_tempname ('o', FALSE)) == NULL) {
        EMSG (_ (e_notmp));
        return FAIL;
    }
    if (num_pat == 1 && *pat[0] == '`' && (len = STRLEN (pat[0])) > 2 && *(pat[0] + len - 1) == '`')
        shell_style = STYLE_BT;
    else if ((len = STRLEN (p_sh)) >= 3) {
        if (STRCMP (p_sh +len - 3, "csh") == 0)
            shell_style = STYLE_GLOB;
        else if (STRCMP (p_sh +len - 3, "zsh") == 0)
            shell_style = STYLE_PRINT;
    }
    if (shell_style == STYLE_ECHO && strstr ((char *) gettail (p_sh), "sh") != NULL)
        shell_style = STYLE_VIMGLOB;
    len = STRLEN (tempname) + 29;
    if (shell_style == STYLE_VIMGLOB)
        len += STRLEN (sh_vimglob_func);
    for (i = 0; i < num_pat; ++i) {
        ++len;
        for (j = 0; pat[i][j] != NUL; ++j) {
            if (vim_strchr (SHELL_SPECIAL, pat[i][j]) != NULL)
                ++len;
            ++len;
        }
    }
    command = alloc (len);
    if (command == NULL) {
        vim_free (tempname);
        return FAIL;
    }
    if (shell_style == STYLE_BT) {
        STRCPY (command, "(");
        STRCAT (command, pat [0] + 1);
        p = command + STRLEN (command) - 1;
        *p-- = ')';
        while (p > command && VIM_ISWHITE (*p))
            --p;
        if (*p == '&') {
            ampersent = TRUE;
            *p = ' ';
        }
        STRCAT (command, ">");
    }
    else {
        if (flags & EW_NOTFOUND)
            STRCPY (command, "set nonomatch; ");
        else
            STRCPY (command, "unset nonomatch; ");
        if (shell_style == STYLE_GLOB)
            STRCAT (command, "glob >");
        else if (shell_style == STYLE_PRINT)
            STRCAT (command, "print -N >");
        else if (shell_style == STYLE_VIMGLOB)
            STRCAT (command, sh_vimglob_func);
        else
            STRCAT (command, "echo >");
    }
    STRCAT (command, tempname);
    if (shell_style != STYLE_BT)
        for (i = 0; i < num_pat; ++i) {
            int intick = FALSE;
            p = command + STRLEN (command);
            *p++ = ' ';
            for (j = 0; pat[i][j] != NUL; ++j) {
                if (pat[i][j] == '`')
                    intick = !intick;
                else if (pat[i][j] == '\\' && pat[i][j + 1] != NUL) {
                    if (intick || vim_strchr (SHELL_SPECIAL, pat[i][j + 1]) != NULL || pat[i][j + 1] == '`')
                        *p++ = '\\';
                    ++j;
                }
                else if (!intick && ((flags & EW_KEEPDOLLAR) == 0 || pat[i][j] != '$') && vim_strchr (SHELL_SPECIAL, pat[i][j]) != NULL)
                    *p++ = '\\';
                *p++ = pat[i][j];
            }
            *p = NUL;
        }
    if (flags & EW_SILENT)
        show_shell_mess = FALSE;
    if (ampersent)
        STRCAT (command, "&");
    if (shell_style == STYLE_PRINT)
        extra_shell_arg = (char_u *) "-G";
    else if (shell_style == STYLE_GLOB && !have_dollars (num_pat, pat))
        extra_shell_arg = (char_u *) "-f";
    i = call_shell (command, SHELL_EXPAND | SHELL_SILENT);
    if (ampersent)
        mch_delay (10L, TRUE);
    extra_shell_arg = NULL;
    show_shell_mess = TRUE;
    vim_free (command);
    if (i != 0) {
        mch_remove (tempname);
        vim_free (tempname);
        if (!(flags & EW_SILENT)) {
            redraw_later_clear ();
            msg_putchar ('\n');
            cmdline_row = Rows - 1;
            {
                MSG (_ (e_wildexpand));
                msg_start ();
            }
        }
        if (shell_style == STYLE_BT)
            return FAIL;
        goto notfound;
    }
    fd = fopen ((char *) tempname, READBIN);
    if (fd == NULL) {
        if (!(flags & EW_SILENT)) {
            MSG (_ (e_wildexpand));
            msg_start ();
        }
        vim_free (tempname);
        goto notfound;
    }
    fseek (fd, 0L, SEEK_END);
    llen = ftell (fd);
    fseek (fd, 0L, SEEK_SET);
    if (llen < 0)
        buffer = NULL;
    else
        buffer = alloc (llen +1);
    if (buffer == NULL) {
        mch_remove (tempname);
        vim_free (tempname);
        fclose (fd);
        return FAIL;
    }
    len = llen;
    i = fread ((char *) buffer, 1, len, fd);
    fclose (fd);
    mch_remove (tempname);
    if (i != (int) len) {
        EMSG2 (_ (e_notread), tempname);
        vim_free (tempname);
        vim_free (buffer);
        return FAIL;
    }
    vim_free (tempname);
    if (shell_style == STYLE_ECHO) {
        buffer[len] = '\n';
        p = buffer;
        for (i = 0; *p != '\n'; ++i) {
            while (*p != ' ' && *p != '\n')
                ++p;
            p = skipwhite (p);
        }
    }
    else if (shell_style == STYLE_BT || shell_style == STYLE_VIMGLOB) {
        buffer[len] = NUL;
        p = buffer;
        for (i = 0; *p != NUL; ++i) {
            while (*p != '\n' && *p != NUL)
                ++p;
            if (*p != NUL)
                ++p;
            p = skipwhite (p);
        }
    }
    else {
        check_spaces = FALSE;
        if (shell_style == STYLE_PRINT && !did_find_nul) {
            buffer[len] = NUL;
            if (len && (int) STRLEN (buffer) < (int) len)
                did_find_nul = TRUE;
            else
                check_spaces = TRUE;
        }
        if (len && buffer[len - 1] == NUL)
            --len;
        else
            buffer[len] = NUL;
        i = 0;
        for (p = buffer; p < buffer + len; ++p)
            if (*p == NUL || (*p == ' ' && check_spaces)) {
                ++i;
                *p = NUL;
            }
        if (len)
            ++i;
    }
    if (i == 0) {
        vim_free (buffer);
        goto notfound;
    }
    *num_file = i;
    *file = (char_u **) alloc (sizeof (char_u *) * i);
    if (*file == NULL) {
        vim_free (buffer);
        return FAIL;
    }
    p = buffer;
    for (i = 0; i < *num_file; ++i) {
        (*file)[i] = p;
        if (shell_style == STYLE_ECHO || shell_style == STYLE_BT || shell_style == STYLE_VIMGLOB) {
            while (!(shell_style == STYLE_ECHO && *p == ' ') && *p != '\n' && *p != NUL)
                ++p;
            if (p == buffer + len)
                *p = NUL;
            else {
                *p++ = NUL;
                p = skipwhite (p);
            }
        }
        else {
            while (*p && p < buffer + len)
                ++p;
            ++p;
        }
    }
    for (j = 0, i = 0; i < *num_file; ++i) {
        if (!(flags & EW_NOTFOUND) && mch_getperm ((*file)[i]) < 0)
            continue;
        dir = (mch_isdir ((*file)[i]));
        if ((dir && !(flags & EW_DIR)) || (!dir && !(flags & EW_FILE)))
            continue;
        if (!dir && (flags & EW_EXEC) && !mch_can_exe ((*file)[i], NULL, !(flags & EW_SHELLCMD)))
            continue;
        p = alloc ((unsigned ) (STRLEN ((*file)[i]) + 1 + dir));
        if (p) {
            STRCPY (p, (* file) [i]);
            if (dir)
                add_pathsep (p);
            (*file)[j++] = p;
        }
    }
    vim_free (buffer);
    *num_file = j;
    if (*num_file == 0) {
        VIM_CLEAR (*file);
        goto notfound;
    }
    return OK;
notfound :
    if (flags & EW_NOTFOUND)
        return save_patterns (num_pat, pat, num_file, file);
    return FAIL;
}

static int have_wildcard (int num, char_u **file) {
    int i;
    for (i = 0; i < num; i++)
        if (mch_has_wildcard (file[i]))
            return 1;
    return 0;
}

int mch_has_wildcard (char_u *p) {
    for (; *p; MB_PTR_ADV (p)) {
        if (*p == '\\' && p[1] != NUL)
            ++p;
        else if (vim_strchr ((char_u *) "*?[{`'$", *p) != NULL || (*p == '~' && p[1] != NUL))
            return TRUE;
    }
    return FALSE;
}

static int save_patterns (int num_pat, char_u **pat, int *num_file, char_u ***file) {
    int i;
    char_u *s;
    *file = (char_u **) alloc (num_pat * sizeof (char_u *));
    if (*file == NULL)
        return FAIL;
    for (i = 0; i < num_pat; i++) {
        s = vim_strsave (pat[i]);
        if (s != NULL)
            backslash_halve (s);
        (*file)[i] = s;
    }
    *num_file = num_pat;
    return OK;
}

static int have_dollars (int num, char_u **file) {
    int i;
    for (i = 0; i < num; i++)
        if (vim_strchr (file[i], '$') != NULL)
            return TRUE;
    return FALSE;
}

void mch_delay (long  msec, int ignoreinput) {
    int old_tmode;
    if (ignoreinput) {
        in_mch_delay = TRUE;
        old_tmode = curr_tmode;
        if (curr_tmode == TMODE_RAW)
            settmode (TMODE_SLEEP);
        poll (NULL, 0, (int) msec);
        settmode (old_tmode);
        in_mch_delay = FALSE;
    }
    else
        WaitForChar (msec, NULL, FALSE);
}

int mch_signal_job (job_T *job, char_u *how) {
    int sig = -1;
    pid_t job_pid;
    if (*how == NUL || STRCMP (how, "term") == 0)
        sig = SIGTERM;
    else if (STRCMP (how, "hup") == 0)
        sig = SIGHUP;
    else if (STRCMP (how, "quit") == 0)
        sig = SIGQUIT;
    else if (STRCMP (how, "int") == 0)
        sig = SIGINT;
    else if (STRCMP (how, "kill") == 0)
        sig = SIGKILL;
    else if (isdigit (*how))
        sig = atoi ((char *) how);
    else
        return FAIL;
    job_pid = job->jv_pid;
    if (job_pid != 0)
        kill (job_pid, sig);
    return OK;
}

int mch_isrealdir (char_u *name) {
    struct stat statb;
    if (*name == NUL)
        return FALSE;
    if (mch_lstat ((char *) name, &statb))
        return FALSE;
    return ((statb.st_mode & S_IFMT) == S_IFDIR ? TRUE : FALSE);
}

int vim_handle_signal (int sig) {
    static int got_signal = 0;
    static int blocked = TRUE;
    switch (sig) {
    case SIGNAL_BLOCK :
        blocked = TRUE;
        break;
    case SIGNAL_UNBLOCK :
        blocked = FALSE;
        if (got_signal != 0) {
            kill (getpid (), got_signal);
            got_signal = 0;
        }
        break;
    default :
        if (!blocked)
            return TRUE;
        got_signal = sig;
        got_int = TRUE;
        break;
    }
    return FALSE;
}

int mch_get_uname (uid_t uid, char_u *s, int len) {
    sprintf ((char *) s, "%d", (int) uid);
    return FAIL;
}

int mch_report_winsize (int fd, int rows, int cols) {
    return FAIL;
}

void get_stty (void) {
    ttyinfo_T info;
    char_u buf [2];
    char_u *p;
    if (get_tty_info (read_cmd_fd, &info) == OK) {
        intr_char = info.interrupt;
        buf[0] = info.backspace;
        buf[1] = NUL;
        add_termcode ((char_u *) "kb", buf, FALSE);
        p = find_termcode ((char_u *) "kD");
        if (p != NULL && p[0] == buf[0] && p[1] == buf[1])
            do_fixdel (NULL);
    }
}

int get_tty_info (int fd, ttyinfo_T *info) {
    struct sgttyb keys;
    if (ioctl (fd, TIOCGETP, &keys) != -1) {
        info->backspace = keys.sg_erase;
        info->interrupt = keys.sg_kill;
        info->enter = CAR;
        info->nl_does_cr = TRUE;
        return OK;
    }
    return FAIL;
}

int use_xterm_like_mouse (char_u *name) {
    return (name != NULL && (term_is_xterm || STRNICMP (name, "screen", 6) == 0 || STRNICMP (name, "tmux", 4) == 0 || STRICMP (name, "st") == 0 || STRNICMP (name, "st-", 3) == 0 || STRNICMP (name, "stterm", 6) == 0));
}

int vim_is_fastterm (char_u *name) {
    if (name == NULL)
        return FALSE;
    if (vim_is_xterm (name) || vim_is_vt300 (name) || vim_is_iris (name))
        return TRUE;
    return (STRNICMP (name, "hpterm", 6) == 0 || STRNICMP (name, "sun-cmd", 7) == 0 || STRNICMP (name, "screen", 6) == 0 || STRNICMP (name, "tmux", 4) == 0 || STRNICMP (name, "dtterm", 6) == 0);
}

int vim_is_vt300 (char_u *name) {
    if (name == NULL)
        return FALSE;
    return ((STRNICMP (name, "vt", 2) == 0 && vim_strchr ((char_u *) "12345", name[2]) != NULL) || STRCMP (name, "builtin_vt320") == 0);
}

long  mch_getperm (char_u *name) {
    struct stat statb;
    if (stat ((char *) name, &statb))
        return -1;
    return statb.st_mode;
}

int mch_isdir (char_u *name) {
    struct stat statb;
    if (*name == NUL)
        return FALSE;
    if (stat ((char *) name, &statb))
        return FALSE;
    return ((statb.st_mode & S_IFMT) == S_IFDIR ? TRUE : FALSE);
}

int mch_can_exe (char_u *name, char_u **path, int use_path) {
    char_u *buf;
    char_u *p, *e;
    int retval;
    if (!use_path || mch_isFullName (name) || (name[0] == '.' && (name[1] == '/' || (name[1] == '.' && name[2] == '/')))) {
        if (gettail (name) != name && executable_file (name)) {
            if (path != NULL) {
                if (name[0] != '/')
                    *path = FullName_save (name, TRUE);
                else
                    *path = vim_strsave (name);
            }
            return TRUE;
        }
        return FALSE;
    }
    p = (char_u *) getenv ("PATH");
    if (p == NULL || *p == NUL)
        return -1;
    buf = alloc ((unsigned ) (STRLEN (name) + STRLEN (p) + 2));
    if (buf == NULL)
        return -1;
    for (;;) {
        e = (char_u *) strchr ((char *) p, ':');
        if (e == NULL)
            e = p + STRLEN (p);
        if (e - p <= 1)
            STRCPY (buf, "./");
        else {
            vim_strncpy (buf, p, e - p);
            add_pathsep (buf);
        }
        STRCAT (buf, name);
        retval = executable_file (buf);
        if (retval == 1) {
            if (path != NULL) {
                if (buf[0] != '/')
                    *path = FullName_save (buf, TRUE);
                else
                    *path = vim_strsave (buf);
            }
            break;
        }
        if (*e != ':')
            break;
        p = e + 1;
    }
    vim_free (buf);
    return retval;
}

int mch_isFullName (char_u *fname) {
    return (*fname == '/' || *fname == '~');
}

static int executable_file (char_u *name) {
    struct stat st;
    if (stat ((char *) name, &st))
        return 0;
    return S_ISREG (st.st_mode) && mch_access ((char *) name, X_OK) == 0;
}

job_T *mch_detect_ended_job (job_T *job_list) {
    int status = -1;
    pid_t wait_pid = 0;
    job_T *job;
    if (dont_check_job_ended > 0)
        return NULL;
    wait_pid = waitpid (-1, &status, WNOHANG);
    if (wait_pid <= 0)
        return NULL;
    for (job = job_list; job != NULL; job = job->jv_next) {
        if (job->jv_pid == wait_pid) {
            if (WIFEXITED (status))
                job->jv_exitval = WEXITSTATUS (status);
            else if (WIFSIGNALED (status))
                job->jv_exitval = -1;
            if (job->jv_status < JOB_ENDED) {
                ch_log (job -> jv_channel, "Job ended");
                job->jv_status = JOB_ENDED;
            }
            return job;
        }
    }
    return NULL;
}

void mch_clear_job (job_T *job) {
    (void) waitpid (job->jv_pid, NULL, WNOHANG);
}

int mch_create_pty_channel (job_T *job, jobopt_T *options) {
    int pty_master_fd = -1;
    int pty_slave_fd = -1;
    channel_T *channel;
    open_pty (& pty_master_fd, & pty_slave_fd, & job -> jv_tty_out);
    if (job->jv_tty_out != NULL)
        job->jv_tty_in = vim_strsave (job->jv_tty_out);
    close (pty_slave_fd);
    channel = add_channel ();
    if (channel == NULL) {
        close (pty_master_fd);
        return FAIL;
    }
    if (job->jv_tty_out != NULL)
        ch_log (channel, "using pty %s on fd %d", job->jv_tty_out, pty_master_fd);
    job->jv_channel = channel;
    channel->ch_keep_open = TRUE;
    channel_set_pipes (channel, pty_master_fd, pty_master_fd, pty_master_fd);
    channel_set_job (channel, job, options);
    return OK;
}

static void open_pty (int *pty_master_fd, int *pty_slave_fd, char_u **namep) {
    char *tty_name;
    *pty_master_fd = OpenPTY (&tty_name);
    if (*pty_master_fd >= 0) {
        *pty_slave_fd = open (tty_name, O_RDWR | O_EXTRA, 0);
        if (*pty_slave_fd < 0) {
            close (*pty_master_fd);
            *pty_master_fd = -1;
        }
        else if (namep != NULL)
            *namep = vim_strsave ((char_u *) tty_name);
    }
}

int mch_parse_cmd (char_u *cmd, int use_shcf, char ***argv, int *argc) {
    int i;
    char_u *p, *d;
    int inquote;
    for (i = 0; i < 2; ++i) {
        p = skipwhite (cmd);
        inquote = FALSE;
        *argc = 0;
        for (;;) {
            if (i == 1)
                (*argv)[*argc] = (char *) p;
            ++*argc;
            d = p;
            while (*p != NUL && (inquote || (*p != ' ' && *p != TAB))) {
                if (p[0] == '"')
                    inquote = !inquote;
                else {
                    if (p[0] == '\\' && p[1] != NUL) {
                        ++p;
                    }
                    if (i == 1)
                        *d++ = *p;
                }
                ++p;
            }
            if (*p == NUL) {
                if (i == 1)
                    *d++ = NUL;
                break;
            }
            if (i == 1)
                *d++ = NUL;
            p = skipwhite (p +1);
        }
        if (*argv == NULL) {
            if (use_shcf) {
                p = p_shcf;
                for (;;) {
                    p = skiptowhite (p);
                    if (*p == NUL)
                        break;
                    ++*argc;
                    p = skipwhite (p);
                }
            }
            *argv = (char **) alloc ((unsigned ) ((*argc + 4) * sizeof (char *)));
            if (*argv == NULL)
                return FAIL;
        }
    }
    return OK;
}

void mch_job_start (char **argv, job_T *job, jobopt_T *options) {
    pid_t pid;
    int fd_in [2] = {-1, -1};
    int fd_out [2] = {-1, -1};
    int fd_err [2] = {-1, -1};
    int pty_master_fd = -1;
    int pty_slave_fd = -1;
    channel_T *channel = NULL;
    int use_null_for_in = options->jo_io[PART_IN] == JIO_NULL;
    int use_null_for_out = options->jo_io[PART_OUT] == JIO_NULL;
    int use_null_for_err = options->jo_io[PART_ERR] == JIO_NULL;
    int use_file_for_in = options->jo_io[PART_IN] == JIO_FILE;
    int use_file_for_out = options->jo_io[PART_OUT] == JIO_FILE;
    int use_file_for_err = options->jo_io[PART_ERR] == JIO_FILE;
    int use_buffer_for_in = options->jo_io[PART_IN] == JIO_BUFFER;
    int use_out_for_err = options->jo_io[PART_ERR] == JIO_OUT;
    SIGSET_DECL (curset)
    if (use_out_for_err && use_null_for_out)
        use_null_for_err = TRUE;
    job->jv_status = JOB_FAILED;
    if (options->jo_pty && (!(use_file_for_in || use_null_for_in) || !(use_file_for_in || use_null_for_out) || !(use_out_for_err || use_file_for_err || use_null_for_err))) {
        open_pty (& pty_master_fd, & pty_slave_fd, & job -> jv_tty_out);
        if (job->jv_tty_out != NULL)
            job->jv_tty_in = vim_strsave (job->jv_tty_out);
    }
    if (use_file_for_in) {
        char_u *fname = options->jo_io_name[PART_IN];
        fd_in[0] = mch_open ((char *) fname, O_RDONLY, 0);
        if (fd_in[0] < 0) {
            EMSG2 (_ (e_notopen), fname);
            goto failed;
        }
    }
    else if (!use_null_for_in && (pty_master_fd < 0 || use_buffer_for_in) && pipe (fd_in) < 0)
        goto failed;
    if (use_file_for_out) {
        char_u *fname = options->jo_io_name[PART_OUT];
        fd_out[1] = mch_open ((char *) fname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd_out[1] < 0) {
            EMSG2 (_ (e_notopen), fname);
            goto failed;
        }
    }
    else if (!use_null_for_out && pty_master_fd < 0 && pipe (fd_out) < 0)
        goto failed;
    if (use_file_for_err) {
        char_u *fname = options->jo_io_name[PART_ERR];
        fd_err[1] = mch_open ((char *) fname, O_WRONLY | O_CREAT | O_TRUNC, 0600);
        if (fd_err[1] < 0) {
            EMSG2 (_ (e_notopen), fname);
            goto failed;
        }
    }
    else if (!use_out_for_err && !use_null_for_err && pty_master_fd < 0 && pipe (fd_err) < 0)
        goto failed;
    if (!use_null_for_in || !use_null_for_out || !use_null_for_err) {
        if (options->jo_set & JO_CHANNEL) {
            channel = options->jo_channel;
            if (channel != NULL)
                ++channel->ch_refcount;
        }
        else
            channel = add_channel ();
        if (channel == NULL)
            goto failed;
        if (job->jv_tty_out != NULL)
            ch_log (channel, "using pty %s on fd %d", job->jv_tty_out, pty_master_fd);
    }
    BLOCK_SIGNALS (& curset);
    pid = fork ();
    if (pid == -1) {
        UNBLOCK_SIGNALS (& curset);
        goto failed;
    }
    if (pid == 0) {
        int null_fd = -1;
        int stderr_works = TRUE;
        reset_signals ();
        UNBLOCK_SIGNALS (& curset);
        if (options->jo_term_rows > 0)
            set_child_environment ((long ) options->jo_term_rows, (long ) options->jo_term_cols, STRNCMP (T_NAME, "xterm", 5) == 0 ? (char *) T_NAME : "xterm");
        else
            set_default_child_environment ();
        if (options->jo_env != NULL) {
            dict_T *dict = options->jo_env;
            hashitem_T *hi;
            int todo = (int) dict->dv_hashtab.ht_used;
            for (hi = dict->dv_hashtab.ht_array; todo > 0; ++hi)
                if (!HASHITEM_EMPTY (hi)) {
                    typval_T *item = &dict_lookup (hi)->di_tv;
                    vim_setenv ((char_u *) hi -> hi_key, get_tv_string (item));
                    --todo;
                }
        }
        if (use_null_for_in || use_null_for_out || use_null_for_err) {
            null_fd = open ("/dev/null", O_RDWR | O_EXTRA, 0);
            if (null_fd < 0) {
                perror ("opening /dev/null failed");
                _exit (OPEN_NULL_FAILED);
            }
        }
        if (pty_slave_fd >= 0) {
            SetupSlavePTY (pty_slave_fd);
        }
        close (0);
        if (use_null_for_in && null_fd >= 0)
            ignored = dup (null_fd);
        else if (fd_in[0] < 0)
            ignored = dup (pty_slave_fd);
        else
            ignored = dup (fd_in[0]);
        close (2);
        if (use_null_for_err && null_fd >= 0) {
            ignored = dup (null_fd);
            stderr_works = FALSE;
        }
        else if (use_out_for_err)
            ignored = dup (fd_out[1]);
        else if (fd_err[1] < 0)
            ignored = dup (pty_slave_fd);
        else
            ignored = dup (fd_err[1]);
        close (1);
        if (use_null_for_out && null_fd >= 0)
            ignored = dup (null_fd);
        else if (fd_out[1] < 0)
            ignored = dup (pty_slave_fd);
        else
            ignored = dup (fd_out[1]);
        if (fd_in[0] >= 0)
            close (fd_in[0]);
        if (fd_in[1] >= 0)
            close (fd_in[1]);
        if (fd_out[0] >= 0)
            close (fd_out[0]);
        if (fd_out[1] >= 0)
            close (fd_out[1]);
        if (fd_err[0] >= 0)
            close (fd_err[0]);
        if (fd_err[1] >= 0)
            close (fd_err[1]);
        if (pty_master_fd >= 0) {
            close (pty_master_fd);
            close (pty_slave_fd);
        }
        if (null_fd >= 0)
            close (null_fd);
        if (options->jo_cwd != NULL && mch_chdir ((char *) options->jo_cwd) != 0)
            _exit (EXEC_FAILED);
        execvp (argv [0], argv);
        if (stderr_works)
            perror ("executing job failed");
        _exit (EXEC_FAILED);
    }
    UNBLOCK_SIGNALS (& curset);
    job->jv_pid = pid;
    job->jv_status = JOB_STARTED;
    job->jv_channel = channel;
    if (pty_master_fd >= 0)
        close (pty_slave_fd);
    if (!use_file_for_in && fd_in[0] >= 0)
        close (fd_in[0]);
    if (!use_file_for_out && fd_out[1] >= 0)
        close (fd_out[1]);
    if (!use_out_for_err && !use_file_for_err && fd_err[1] >= 0)
        close (fd_err[1]);
    if (channel != NULL) {
        channel_set_pipes (channel, use_file_for_in || use_null_for_in ? INVALID_FD : fd_in [1] < 0 ? pty_master_fd : fd_in [1], use_file_for_out || use_null_for_out ? INVALID_FD : fd_out [0] < 0 ? pty_master_fd : fd_out [0], use_out_for_err || use_file_for_err || use_null_for_err ? INVALID_FD : fd_err [0] < 0 ? pty_master_fd : fd_err [0]);
        channel_set_job (channel, job, options);
    }
    else {
        if (fd_in[1] >= 0)
            close (fd_in[1]);
        if (fd_out[0] >= 0)
            close (fd_out[0]);
        if (fd_err[0] >= 0)
            close (fd_err[0]);
        if (pty_master_fd >= 0)
            close (pty_master_fd);
    }
    return;
failed :
    channel_unref (channel);
    if (fd_in[0] >= 0)
        close (fd_in[0]);
    if (fd_in[1] >= 0)
        close (fd_in[1]);
    if (fd_out[0] >= 0)
        close (fd_out[0]);
    if (fd_out[1] >= 0)
        close (fd_out[1]);
    if (fd_err[0] >= 0)
        close (fd_err[0]);
    if (fd_err[1] >= 0)
        close (fd_err[1]);
    if (pty_master_fd >= 0)
        close (pty_master_fd);
    if (pty_slave_fd >= 0)
        close (pty_slave_fd);
}

void reset_signals (void) {
    catch_signals (SIG_DFL, SIG_DFL);
}

static void catch_signals (RETSIGTYPE (*func_deadly) (), RETSIGTYPE (*func_other) ()) {
    int i;
    for (i = 0; signal_info[i].sig != -1; i++)
        if (signal_info[i].deadly) {
            signal (signal_info [i].sig, func_deadly);
        }
        else if (func_other != SIG_ERR)
            signal (signal_info[i].sig, func_other);
}

static void set_child_environment (long  rows, long  columns, char *term) {
    static char envbuf_Term [30];
    static char envbuf_Rows [20];
    static char envbuf_Lines [20];
    static char envbuf_Columns [20];
    static char envbuf_Colors [20];
    static char envbuf_Servername [60];
    long  colors = gui.in_use ? 256 * 256 * 256 : t_colors;
    vim_snprintf (envbuf_Term, sizeof (envbuf_Term), "TERM=%s", term);
    putenv (envbuf_Term);
    vim_snprintf (envbuf_Rows, sizeof (envbuf_Rows), "ROWS=%ld", rows);
    putenv (envbuf_Rows);
    vim_snprintf (envbuf_Lines, sizeof (envbuf_Lines), "LINES=%ld", rows);
    putenv (envbuf_Lines);
    vim_snprintf (envbuf_Columns, sizeof (envbuf_Columns), "COLUMNS=%ld", columns);
    putenv (envbuf_Columns);
    vim_snprintf (envbuf_Colors, sizeof (envbuf_Colors), "COLORS=%ld", colors);
    putenv (envbuf_Colors);
    vim_snprintf (envbuf_Servername, sizeof (envbuf_Servername), "VIM_SERVERNAME=%s", serverName == NULL ? "" : (char *) serverName);
    putenv (envbuf_Servername);
}

static void set_default_child_environment (void) {
    set_child_environment (Rows, Columns, "dumb");
}

int mch_chdir (char *path) {
    if (p_verbose >= 5) {
        verbose_enter ();
        smsg ((char_u *) "chdir(%s)", path);
        verbose_leave ();
    }
    return chdir (path);
}

char *mch_job_status (job_T *job) {
    int status = -1;
    pid_t wait_pid = 0;
    wait_pid = waitpid (job->jv_pid, &status, WNOHANG);
    if (wait_pid == -1) {
        goto return_dead;
    }
    if (wait_pid == 0)
        return "run";
    if (WIFEXITED (status)) {
        job->jv_exitval = WEXITSTATUS (status);
        goto return_dead;
    }
    if (WIFSIGNALED (status)) {
        job->jv_exitval = -1;
        goto return_dead;
    }
    return "run";
return_dead :
    if (job->jv_status < JOB_ENDED) {
        ch_log (job -> jv_channel, "Job ended");
        job->jv_status = JOB_ENDED;
    }
    return "dead";
}

int mch_check_messages (void) {
    return WaitForChar (0L, NULL, TRUE);
}

