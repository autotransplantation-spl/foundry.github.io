
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
struct vimoption {
    char *fullname;
    char *shortname;
    long_u flags;
    char_u *var;
    idopt_T indir;
    char_u *def_val [2];
    scid_T scriptID;

    # define SCRIPTID_INIT , 0
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
EXTERN long  p_wd;
EXTERN int p_wb;
EXTERN int p_wa;
EXTERN int p_write;
EXTERN int p_ws;
EXTERN int p_wmnu;
EXTERN char_u *p_wig;
EXTERN int p_warn;
EXTERN int p_vb;
EXTERN char_u *p_viminfofile;
EXTERN long  p_ur;
EXTERN char_u *p_udir;
EXTERN int p_tf;
EXTERN int p_tbi;
EXTERN char_u *p_tsr;
EXTERN char_u *p_titleold;
EXTERN int p_to;
EXTERN int p_tgst;
EXTERN int p_tr;
EXTERN long  p_tl;
EXTERN int p_tbs;
EXTERN char_u *p_sws;
EXTERN char_u *p_su;
EXTERN int p_sol;
EXTERN int p_spr;
EXTERN char_u *p_tal;
EXTERN long  p_tpm;
EXTERN int p_sb;
EXTERN int p_smd;
EXTERN int p_sft;
EXTERN int p_sr;
EXTERN char_u *p_srr;
EXTERN char_u *p_sxe;
EXTERN char_u *p_sxq;
EXTERN char_u *p_shq;
EXTERN char_u *p_sp;
EXTERN char_u *p_sh;
EXTERN int p_ari;
EXTERN long  p_pvh;
EXTERN int p_remap;
EXTERN long  p_rdt;
EXTERN char_u *p_pex;
EXTERN char_u *p_para;
EXTERN int p_more;
EXTERN long  p_mouset;
EXTERN int p_mh;
EXTERN int p_mousef;
EXTERN long  p_mls;
EXTERN long  p_mis;
EXTERN long  p_mmt;
EXTERN long  p_mmp;
EXTERN long  p_mm;
EXTERN long  p_mmd;
EXTERN long  p_mfd;
EXTERN long  p_mat;
EXTERN char_u *p_mp;
EXTERN char_u *p_mef;
EXTERN int p_lpl;
EXTERN int p_lz;
EXTERN char_u *p_lispwords;
EXTERN char_u *p_lm;
EXTERN int p_js;
EXTERN int p_is;
EXTERN int p_hkmapp;
EXTERN int p_prompt;
EXTERN char_u *p_header;
EXTERN char_u *p_pfn;
EXTERN char_u *p_pdev;
EXTERN int p_gd;
EXTERN char_u *p_fp;
EXTERN long  p_fdls;
EXTERN int p_ek;
EXTERN char_u *p_gp;
EXTERN char_u *p_gefm;
EXTERN char_u *p_efm;
EXTERN char_u *p_ef;
EXTERN int p_eb;
EXTERN int p_ed;
EXTERN int p_dg;
EXTERN char_u *p_dex;
EXTERN char_u *p_def;
EXTERN long  p_pw;
EXTERN long  p_ph;
EXTERN long  p_bdlay;
EXTERN char_u *p_bsk;
EXTERN int p_bk;
EXTERN int p_awa;
EXTERN int p_aw;
EXTERN int p_ar;
EXTERN long  p_aleph;
int p_ro;
int p_mod;
int p_eol;
int p_bl;
EXTERN char_u *p_ep;
EXTERN char_u *p_vdir;
EXTERN char_u *p_rtp;
EXTERN char_u *p_pp;
EXTERN char_u *p_path;
EXTERN char_u *p_tags;
EXTERN long  p_ss;
EXTERN long  p_ut;
EXTERN long  p_siso;
EXTERN long  p_so;
EXTERN long  p_sj;
EXTERN long  p_report;
EXTERN long  p_re;
EXTERN long  p_hi;
EXTERN long  p_wiw;
EXTERN long  p_wmw;
EXTERN long  p_wmh;
EXTERN long  p_wh;
EXTERN long  p_window;
EXTERN long  p_ul;
EXTERN long  p_blur;
EXTERN long  p_transp;
EXTERN long  p_stal;
EXTERN long  p_hh;
EXTERN int p_ri;
EXTERN int p_sta;
EXTERN int p_sm;
EXTERN int p_arshape;
EXTERN int modified_was_set;
EXTERN int p_fkmap;
EXTERN int p_hkmap;
EXTERN int p_wiv;
EXTERN int p_terse;
EXTERN int p_paste;
EXTERN int p_lnr;
EXTERN int p_im;
EXTERN int p_altkeymap;
EXTERN int p_ea;
EXTERN char_u *NameBuff;
EXTERN char_u *p_kp;
EXTERN char_u *p_dir;
EXTERN char_u *p_bdir;
EXTERN long  p_verbose;
EXTERN char_u e_trailing [] INIT (= N_ ("E488: Trailing characters"));
EXTERN int p_title;
EXTERN char_u *p_ttym;
EXTERN char_u *p_shm;
EXTERN char_u *p_ww;
EXTERN int p_ta;
EXTERN char_u e_modifiable [] INIT (= N_ ("E21: Cannot make changes, 'modifiable' is off"));
EXTERN char_u *p_mouse;
EXTERN char_u *p_wim;
EXTERN char_u *p_wop;
EXTERN char_u *p_ve;
EXTERN char_u *p_vop;
EXTERN char_u *p_tbis;
EXTERN char_u *p_toolbar;
EXTERN char_u *p_swb;
EXTERN char_u *p_sps;
EXTERN char_u *p_sbr;
EXTERN char_u *p_stl;
EXTERN char_u *p_ssop;
EXTERN char_u *p_slm;
EXTERN char_u *p_sel;
EXTERN char_u *p_sbo;
EXTERN char_u *p_ruf;
EXTERN char_u *p_pm;
EXTERN char_u *p_pt;
EXTERN char_u *p_mousem;
EXTERN char_u *p_msm;
EXTERN char_u *p_langmap;
EXTERN char_u *p_km;
EXTERN char_u *p_isp;
EXTERN char_u *p_isi;
EXTERN char_u *p_isf;
EXTERN char_u *p_hf;
EXTERN char_u *p_go;
EXTERN char_u *p_mouseshape;
EXTERN char_u *p_popt;
EXTERN char_u *p_fuoptions;
EXTERN char_u *p_fdo;
EXTERN char_u *p_ei;
EXTERN char_u *p_ead;
EXTERN char_u *p_dy;
EXTERN char_u *p_dip;
EXTERN char_u *p_debug;
EXTERN char_u *p_breakat;
EXTERN char_u *p_bo;
EXTERN char_u *p_bex;
EXTERN char_u *p_bg;
EXTERN char_u *p_bs;
char_u *p_syn;
char_u *p_ft;
char_u *p_bt;
char_u *p_bh;
EXTERN char_u e_intern2 [] INIT (= N_ ("E685: Internal error: %s"));
EXTERN char_u *p_viminfo;
EXTERN long  p_ls;
EXTERN int p_ru;
int p_ma;
long  p_ts;
char_u *p_isk;
char_u *p_ff;
EXTERN char_u *p_ffs;
int p_tx;
int p_udf;
char_u *p_qe;
char_u *p_inex;
long  p_iminsert;
int p_mmta;
char_u *p_keymap;
char_u *p_sua;
char_u *p_key;
char_u *p_fex;
char_u *p_indk;
char_u *p_inde;
char_u *p_spl;
char_u *p_spf;
int p_lisp;
int p_pi;
int p_si;
char_u *p_mps;
char_u *p_nf;
char_u *p_flp;
char_u *p_fo;
int p_sn;
long  p_sts_nopaste;
long  p_sts;
int p_swf;
int p_inf;
int p_ml_nobin;
int p_ml;
int p_et_nopaste;
int p_et_nobin;
int p_et;
int p_fixeol;
int p_bin;
long  p_wm_nobin;
long  p_wm_nopaste;
long  p_wm;
long  p_tw_nobin;
long  p_tw_nopaste;
long  p_tw;
long  p_sw;
int p_ai_nopaste;
int p_ai;
struct vimoption options [] = {{"aleph", "al", P_NUM | P_VI_DEF | P_CURSWANT, (char_u *) &p_aleph, PV_NONE, {(char_u *) 224L, (char_u *) 0L} SCRIPTID_INIT
    }, {"antialias", "anti", P_BOOL | P_VI_DEF | P_VIM | P_RCLR, (char_u *) NULL, PV_NONE, {(char_u *) TRUE, (char_u *) FALSE} SCRIPTID_INIT
    }, {"arabic", "arab", P_BOOL | P_VI_DEF | P_VIM | P_CURSWANT, (char_u *) VAR_WIN, PV_ARAB, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"arabicshape", "arshape", P_BOOL | P_VI_DEF | P_VIM | P_RCLR, (char_u *) &p_arshape, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"allowrevins", "ari", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_ari, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"altkeymap", "akm", P_BOOL | P_VI_DEF, (char_u *) &p_altkeymap, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"ambiwidth", "ambw", P_STRING | P_VI_DEF | P_RCLR, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"autochdir", "acd", P_BOOL | P_VI_DEF, (char_u *) &p_acd, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"autoindent", "ai", P_BOOL | P_VI_DEF, (char_u *) &p_ai, PV_AI, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"autoprint", "ap", P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"autoread", "ar", P_BOOL | P_VI_DEF, (char_u *) &p_ar, PV_AR, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"autowrite", "aw", P_BOOL | P_VI_DEF, (char_u *) &p_aw, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"autowriteall", "awa", P_BOOL | P_VI_DEF, (char_u *) &p_awa, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"background", "bg", P_STRING | P_VI_DEF | P_RCLR, (char_u *) &p_bg, PV_NONE, {(char_u *) "light", (char_u *) 0L} SCRIPTID_INIT
    }, {"backspace", "bs", P_STRING | P_VI_DEF | P_VIM | P_ONECOMMA | P_NODUP, (char_u *) &p_bs, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"backup", "bk", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_bk, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"backupcopy", "bkc", P_STRING | P_VIM | P_ONECOMMA | P_NODUP, (char_u *) &p_bkc, PV_BKC, {(char_u *) "yes", (char_u *) "auto"} SCRIPTID_INIT
    }, {"backupdir", "bdir", P_STRING | P_EXPAND | P_VI_DEF | P_ONECOMMA | P_NODUP | P_SECURE, (char_u *) &p_bdir, PV_NONE, {(char_u *) DFLT_BDIR, (char_u *) 0L} SCRIPTID_INIT
    }, {"backupext", "bex", P_STRING | P_VI_DEF | P_NFNAME, (char_u *) &p_bex, PV_NONE, {(char_u *) "~", (char_u *) 0L} SCRIPTID_INIT
    }, {"backupskip", "bsk", P_STRING | P_VI_DEF | P_ONECOMMA, (char_u *) &p_bsk, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"balloondelay", "bdlay", P_NUM | P_VI_DEF, (char_u *) &p_bdlay, PV_NONE, {(char_u *) 600L, (char_u *) 0L} SCRIPTID_INIT
    }, {"ballooneval", "beval", P_BOOL | P_VI_DEF | P_NO_MKRC, (char_u *) &p_beval, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"balloonevalterm", "bevalterm", P_BOOL | P_VI_DEF | P_NO_MKRC, (char_u *) &p_bevalterm, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"balloonexpr", "bexpr", P_STRING | P_ALLOCED | P_VI_DEF | P_VIM, (char_u *) &p_bexpr, PV_BEXPR, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"beautify", "bf", P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"belloff", "bo", P_STRING | P_VI_DEF | P_COMMA | P_NODUP, (char_u *) &p_bo, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"binary", "bin", P_BOOL | P_VI_DEF | P_RSTAT, (char_u *) &p_bin, PV_BIN, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"bioskey", "biosk", P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"blurradius", "blur", P_NUM | P_VIM, (char_u *) &p_blur, PV_NONE, {(char_u *) 0L, (char_u *) 0L}}, {"bomb", NULL, P_BOOL | P_NO_MKRC | P_VI_DEF | P_RSTAT, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"breakat", "brk", P_STRING | P_VI_DEF | P_RALL | P_FLAGLIST, (char_u *) &p_breakat, PV_NONE, {(char_u *) " \t!@*-+;:,./?", (char_u *) 0L} SCRIPTID_INIT
    }, {"breakindent", "bri", P_BOOL | P_VI_DEF | P_VIM | P_RWIN, (char_u *) VAR_WIN, PV_BRI, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"breakindentopt", "briopt", P_STRING | P_ALLOCED | P_VI_DEF | P_RBUF | P_ONECOMMA | P_NODUP, (char_u *) VAR_WIN, PV_BRIOPT, {(char_u *) "", (char_u *) NULL} SCRIPTID_INIT
    }, {"browsedir", "bsdir", P_STRING | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"bufhidden", "bh", P_STRING | P_ALLOCED | P_VI_DEF | P_NOGLOB, (char_u *) &p_bh, PV_BH, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"buflisted", "bl", P_BOOL | P_VI_DEF | P_NOGLOB, (char_u *) &p_bl, PV_BL, {(char_u *) 1L, (char_u *) 0L} SCRIPTID_INIT
    }, {"buftype", "bt", P_STRING | P_ALLOCED | P_VI_DEF | P_NOGLOB, (char_u *) &p_bt, PV_BT, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"casemap", "cmp", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"cdpath", "cd", P_STRING | P_EXPAND | P_VI_DEF | P_COMMA | P_NODUP, (char_u *) &p_cdpath, PV_NONE, {(char_u *) ",,", (char_u *) 0L} SCRIPTID_INIT
    }, {"cedit", NULL, P_STRING, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"charconvert", "ccv", P_STRING | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"cindent", "cin", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_cin, PV_CIN, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"cinkeys", "cink", P_STRING | P_ALLOCED | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_cink, PV_CINK, {(char_u *) "0{,0},0),:,0#,!^F,o,O,e", (char_u *) 0L} SCRIPTID_INIT
    }, {"cinoptions", "cino", P_STRING | P_ALLOCED | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_cino, PV_CINO, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"cinwords", "cinw", P_STRING | P_ALLOCED | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_cinw, PV_CINW, {(char_u *) "if,else,while,do,for,switch", (char_u *) 0L} SCRIPTID_INIT
    }, {"clipboard", "cb", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) NULL, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"cmdheight", "ch", P_NUM | P_VI_DEF | P_RALL, (char_u *) &p_ch, PV_NONE, {(char_u *) 1L, (char_u *) 0L} SCRIPTID_INIT
    }, {"cmdwinheight", "cwh", P_NUM | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) 7L, (char_u *) 0L} SCRIPTID_INIT
    }, {"colorcolumn", "cc", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP | P_RWIN, (char_u *) VAR_WIN, PV_CC, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"columns", "co", P_NUM | P_NODEFAULT | P_NO_MKRC | P_VI_DEF | P_RCLR, (char_u *) &Columns, PV_NONE, {(char_u *) 80L, (char_u *) 0L} SCRIPTID_INIT
    }, {"columnspace", "csp", P_NUM | P_VI_DEF | P_RCLR, (char_u *) &p_columnspace, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"comments", "com", P_STRING | P_ALLOCED | P_VI_DEF | P_ONECOMMA | P_NODUP | P_CURSWANT, (char_u *) &p_com, PV_COM, {(char_u *) "s1:/*,mb:*,ex:*/,://,b:#,:%,:XCOMM,n:>,fb:-", (char_u *) 0L} SCRIPTID_INIT
    }, {"commentstring", "cms", P_STRING | P_ALLOCED | P_VI_DEF | P_CURSWANT, (char_u *) &p_cms, PV_CMS, {(char_u *) "/*%s*/", (char_u *) 0L} SCRIPTID_INIT
    }, {"compatible", "cp", P_BOOL | P_RALL, (char_u *) &p_cp, PV_NONE, {(char_u *) TRUE, (char_u *) FALSE} SCRIPTID_INIT
    }, {"complete", "cpt", P_STRING | P_ALLOCED | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_cpt, PV_CPT, {(char_u *) ".,w,b,u,t,i", (char_u *) 0L} SCRIPTID_INIT
    }, {"concealcursor", "cocu", P_STRING | P_ALLOCED | P_RWIN | P_VI_DEF, (char_u *) VAR_WIN, PV_COCU, {(char_u *) "", (char_u *) NULL} SCRIPTID_INIT
    }, {"conceallevel", "cole", P_NUM | P_RWIN | P_VI_DEF, (char_u *) VAR_WIN, PV_COLE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"completefunc", "cfu", P_STRING | P_ALLOCED | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"completeopt", "cot", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_cot, PV_NONE, {(char_u *) "menu,preview", (char_u *) 0L} SCRIPTID_INIT
    }, {"confirm", "cf", P_BOOL | P_VI_DEF, (char_u *) &p_confirm, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"conskey", "consk", P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"copyindent", "ci", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_ci, PV_CI, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"cpoptions", "cpo", P_STRING | P_VIM | P_RALL | P_FLAGLIST, (char_u *) &p_cpo, PV_NONE, {(char_u *) CPO_VI, (char_u *) CPO_VIM} SCRIPTID_INIT
    }, {"cryptmethod", "cm", P_STRING | P_ALLOCED | P_VI_DEF, (char_u *) &p_cm, PV_CM, {(char_u *) "zip", (char_u *) 0L} SCRIPTID_INIT
    }, {"cscopepathcomp", "cspc", P_NUM | P_VI_DEF | P_VIM, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"cscopeprg", "csprg", P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"cscopequickfix", "csqf", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"cscoperelative", "csre", P_BOOL | P_VI_DEF | P_VIM, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"cscopetag", "cst", P_BOOL | P_VI_DEF | P_VIM, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"cscopetagorder", "csto", P_NUM | P_VI_DEF | P_VIM, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"cscopeverbose", "csverb", P_BOOL | P_VI_DEF | P_VIM, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"cursorbind", "crb", P_BOOL | P_VI_DEF, (char_u *) VAR_WIN, PV_CRBIND, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"cursorcolumn", "cuc", P_BOOL | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_CUC, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"cursorline", "cul", P_BOOL | P_VI_DEF | P_RWINONLY, (char_u *) VAR_WIN, PV_CUL, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"debug", NULL, P_STRING | P_VI_DEF, (char_u *) &p_debug, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"define", "def", P_STRING | P_ALLOCED | P_VI_DEF | P_CURSWANT, (char_u *) &p_def, PV_DEF, {(char_u *) "^\\s*#\\s*define", (char_u *) 0L} SCRIPTID_INIT
    }, {"delcombine", "deco", P_BOOL | P_VI_DEF | P_VIM, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"dictionary", "dict", P_STRING | P_EXPAND | P_VI_DEF | P_ONECOMMA | P_NODUP | P_NDNAME, (char_u *) &p_dict, PV_DICT, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"diff", NULL, P_BOOL | P_VI_DEF | P_RWIN | P_NOGLOB, (char_u *) VAR_WIN, PV_DIFF, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"diffexpr", "dex", P_STRING | P_VI_DEF | P_SECURE | P_CURSWANT, (char_u *) &p_dex, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"diffopt", "dip", P_STRING | P_ALLOCED | P_VI_DEF | P_RWIN | P_ONECOMMA | P_NODUP, (char_u *) &p_dip, PV_NONE, {(char_u *) "filler", (char_u *) NULL} SCRIPTID_INIT
    }, {"digraph", "dg", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_dg, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"directory", "dir", P_STRING | P_EXPAND | P_VI_DEF | P_ONECOMMA | P_NODUP | P_SECURE, (char_u *) &p_dir, PV_NONE, {(char_u *) DFLT_DIR, (char_u *) 0L} SCRIPTID_INIT
    }, {"display", "dy", P_STRING | P_VI_DEF | P_ONECOMMA | P_RALL | P_NODUP, (char_u *) &p_dy, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"eadirection", "ead", P_STRING | P_VI_DEF, (char_u *) &p_ead, PV_NONE, {(char_u *) "both", (char_u *) 0L} SCRIPTID_INIT
    }, {"edcompatible", "ed", P_BOOL | P_VI_DEF, (char_u *) &p_ed, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"emoji", "emo", P_BOOL | P_VI_DEF | P_RCLR, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"encoding", "enc", P_STRING | P_VI_DEF | P_RCLR | P_NO_ML, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"endofline", "eol", P_BOOL | P_NO_MKRC | P_VI_DEF | P_RSTAT, (char_u *) &p_eol, PV_EOL, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"equalalways", "ea", P_BOOL | P_VI_DEF | P_RALL, (char_u *) &p_ea, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"equalprg", "ep", P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) &p_ep, PV_EP, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"errorbells", "eb", P_BOOL | P_VI_DEF, (char_u *) &p_eb, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"errorfile", "ef", P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) &p_ef, PV_NONE, {(char_u *) DFLT_ERRORFILE, (char_u *) 0L} SCRIPTID_INIT
    }, {"errorformat", "efm", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_efm, PV_EFM, {(char_u *) DFLT_EFM, (char_u *) 0L} SCRIPTID_INIT
    }, {"esckeys", "ek", P_BOOL | P_VIM, (char_u *) &p_ek, PV_NONE, {(char_u *) FALSE, (char_u *) TRUE} SCRIPTID_INIT
    }, {"eventignore", "ei", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_ei, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"expandtab", "et", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_et, PV_ET, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"exrc", "ex", P_BOOL | P_VI_DEF | P_SECURE, (char_u *) &p_exrc, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"fileencoding", "fenc", P_STRING | P_ALLOCED | P_VI_DEF | P_RSTAT | P_RBUF | P_NO_MKRC, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"fileencodings", "fencs", P_STRING | P_VI_DEF | P_ONECOMMA, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"fileformat", "ff", P_STRING | P_ALLOCED | P_VI_DEF | P_RSTAT | P_NO_MKRC | P_CURSWANT, (char_u *) &p_ff, PV_FF, {(char_u *) DFLT_FF, (char_u *) 0L} SCRIPTID_INIT
    }, {"fileformats", "ffs", P_STRING | P_VIM | P_ONECOMMA | P_NODUP, (char_u *) &p_ffs, PV_NONE, {(char_u *) DFLT_FFS_VI, (char_u *) DFLT_FFS_VIM} SCRIPTID_INIT
    }, {"fileignorecase", "fic", P_BOOL | P_VI_DEF, (char_u *) &p_fic, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"filetype", "ft", P_STRING | P_ALLOCED | P_VI_DEF | P_NOGLOB | P_NFNAME, (char_u *) &p_ft, PV_FT, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"fillchars", "fcs", P_STRING | P_VI_DEF | P_RALL | P_ONECOMMA | P_NODUP, (char_u *) &p_fcs, PV_NONE, {(char_u *) "vert:|,fold:-", (char_u *) 0L} SCRIPTID_INIT
    }, {"fixendofline", "fixeol", P_BOOL | P_VI_DEF | P_RSTAT, (char_u *) &p_fixeol, PV_FIXEOL, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"fkmap", "fk", P_BOOL | P_VI_DEF, (char_u *) &p_fkmap, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"flash", "fl", P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"foldclose", "fcl", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP | P_RWIN, (char_u *) &p_fcl, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"foldcolumn", "fdc", P_NUM | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_FDC, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"foldenable", "fen", P_BOOL | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_FEN, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"foldexpr", "fde", P_STRING | P_ALLOCED | P_VIM | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_FDE, {(char_u *) "0", (char_u *) NULL} SCRIPTID_INIT
    }, {"foldignore", "fdi", P_STRING | P_ALLOCED | P_VIM | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_FDI, {(char_u *) "#", (char_u *) NULL} SCRIPTID_INIT
    }, {"foldlevel", "fdl", P_NUM | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_FDL, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"foldlevelstart", "fdls", P_NUM | P_VI_DEF | P_CURSWANT, (char_u *) &p_fdls, PV_NONE, {(char_u *) -1L, (char_u *) 0L} SCRIPTID_INIT
    }, {"foldmarker", "fmr", P_STRING | P_ALLOCED | P_VIM | P_VI_DEF | P_RWIN | P_ONECOMMA | P_NODUP, (char_u *) VAR_WIN, PV_FMR, {(char_u *) "{{{,}}}", (char_u *) NULL} SCRIPTID_INIT
    }, {"foldmethod", "fdm", P_STRING | P_ALLOCED | P_VIM | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_FDM, {(char_u *) "manual", (char_u *) NULL} SCRIPTID_INIT
    }, {"foldminlines", "fml", P_NUM | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_FML, {(char_u *) 1L, (char_u *) 0L} SCRIPTID_INIT
    }, {"foldnestmax", "fdn", P_NUM | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_FDN, {(char_u *) 20L, (char_u *) 0L} SCRIPTID_INIT
    }, {"foldopen", "fdo", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP | P_CURSWANT, (char_u *) &p_fdo, PV_NONE, {(char_u *) "block,hor,mark,percent,quickfix,search,tag,undo", (char_u *) 0L} SCRIPTID_INIT
    }, {"foldtext", "fdt", P_STRING | P_ALLOCED | P_VIM | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_FDT, {(char_u *) "foldtext()", (char_u *) NULL} SCRIPTID_INIT
    }, {"formatexpr", "fex", P_STRING | P_ALLOCED | P_VI_DEF | P_VIM, (char_u *) &p_fex, PV_FEX, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"formatoptions", "fo", P_STRING | P_ALLOCED | P_VIM | P_FLAGLIST, (char_u *) &p_fo, PV_FO, {(char_u *) DFLT_FO_VI, (char_u *) DFLT_FO_VIM} SCRIPTID_INIT
    }, {"formatlistpat", "flp", P_STRING | P_ALLOCED | P_VI_DEF, (char_u *) &p_flp, PV_FLP, {(char_u *) "^\\s*\\d\\+[\\]:.)}\\t ]\\s*", (char_u *) 0L} SCRIPTID_INIT
    }, {"formatprg", "fp", P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) &p_fp, PV_FP, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"fsync", "fs", P_BOOL | P_SECURE | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"fullscreen", "fu", P_BOOL | P_NO_MKRC, (char_u *) &p_fullscreen, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"fuoptions", "fuopt", P_STRING | P_COMMA | P_NODUP | P_VI_DEF, (char_u *) &p_fuoptions, PV_NONE, {(char_u *) "maxvert,maxhorz", (char_u *) 0L} SCRIPTID_INIT
    }, {"gdefault", "gd", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_gd, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"graphic", "gr", P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"grepformat", "gfm", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_gefm, PV_NONE, {(char_u *) DFLT_GREPFORMAT, (char_u *) 0L} SCRIPTID_INIT
    }, {"grepprg", "gp", P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) &p_gp, PV_GP, {(char_u *) "grep -n $* /dev/null", (char_u *) 0L} SCRIPTID_INIT
    }, {"guicursor", "gcr", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) NULL, PV_NONE, {(char_u *) NULL, (char_u *) 0L} SCRIPTID_INIT
    }, {"guifont", "gfn", P_STRING | P_VI_DEF | P_RCLR | P_ONECOMMA | P_NODUP, (char_u *) &p_guifont, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"guifontset", "gfs", P_STRING | P_VI_DEF | P_RCLR | P_ONECOMMA, (char_u *) NULL, PV_NONE, {(char_u *) NULL, (char_u *) 0L} SCRIPTID_INIT
    }, {"guifontwide", "gfw", P_STRING | P_VI_DEF | P_RCLR | P_ONECOMMA | P_NODUP, (char_u *) NULL, PV_NONE, {(char_u *) NULL, (char_u *) 0L} SCRIPTID_INIT
    }, {"guiheadroom", "ghr", P_NUM | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) 50L, (char_u *) 0L} SCRIPTID_INIT
    }, {"guioptions", "go", P_STRING | P_VI_DEF | P_RALL | P_FLAGLIST | P_RCLR, (char_u *) &p_go, PV_NONE, {(char_u *) "egmrL", (char_u *) 0L} SCRIPTID_INIT
    }, {"guipty", NULL, P_BOOL | P_VI_DEF, (char_u *) &p_guipty, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"guitablabel", "gtl", P_STRING | P_VI_DEF | P_RWIN, (char_u *) NULL, PV_NONE, {(char_u *) NULL, (char_u *) 0L} SCRIPTID_INIT
    }, {"guitabtooltip", "gtt", P_STRING | P_VI_DEF | P_RWIN, (char_u *) NULL, PV_NONE, {(char_u *) NULL, (char_u *) 0L} SCRIPTID_INIT
    }, {"hardtabs", "ht", P_NUM | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"helpfile", "hf", P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) &p_hf, PV_NONE, {(char_u *) DFLT_HELPFILE, (char_u *) 0L} SCRIPTID_INIT
    }, {"helpheight", "hh", P_NUM | P_VI_DEF, (char_u *) &p_hh, PV_NONE, {(char_u *) 20L, (char_u *) 0L} SCRIPTID_INIT
    }, {"helplang", "hlg", P_STRING | P_VI_DEF | P_ONECOMMA, (char_u *) &p_hlg, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"hidden", "hid", P_BOOL | P_VI_DEF, (char_u *) &p_hid, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"highlight", "hl", P_STRING | P_VI_DEF | P_RCLR | P_ONECOMMA | P_NODUP, (char_u *) &p_hl, PV_NONE, {(char_u *) HIGHLIGHT_INIT, (char_u *) 0L} SCRIPTID_INIT
    }, {"history", "hi", P_NUM | P_VIM, (char_u *) &p_hi, PV_NONE, {(char_u *) 0L, (char_u *) 50L} SCRIPTID_INIT
    }, {"hkmap", "hk", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_hkmap, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"hkmapp", "hkp", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_hkmapp, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"hlsearch", "hls", P_BOOL | P_VI_DEF | P_VIM | P_RALL, (char_u *) &p_hls, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"icon", NULL, P_BOOL | P_VI_DEF, (char_u *) &p_icon, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"iconstring", NULL, P_STRING | P_VI_DEF, (char_u *) &p_iconstring, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"ignorecase", "ic", P_BOOL | P_VI_DEF, (char_u *) &p_ic, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"imactivatefunc", "imaf", P_STRING | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) NULL, (char_u *) 0L} SCRIPTID_INIT
    }, {"imactivatekey", "imak", P_STRING | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"imcmdline", "imc", P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"imdisable", "imd", P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"iminsert", "imi", P_NUM | P_VI_DEF, (char_u *) &p_iminsert, PV_IMI, {(char_u *) B_IMODE_NONE, (char_u *) 0L} SCRIPTID_INIT
    }, {"imsearch", "ims", P_NUM | P_VI_DEF, (char_u *) &p_imsearch, PV_IMS, {(char_u *) B_IMODE_USE_INSERT, (char_u *) 0L} SCRIPTID_INIT
    }, {"imstatusfunc", "imsf", P_STRING | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) NULL, (char_u *) 0L} SCRIPTID_INIT
    }, {"imstyle", "imst", P_NUM | P_VI_DEF | P_SECURE, (char_u *) &p_imst, PV_NONE, {(char_u *) IM_ON_THE_SPOT, (char_u *) 0L} SCRIPTID_INIT
    }, {"include", "inc", P_STRING | P_ALLOCED | P_VI_DEF, (char_u *) &p_inc, PV_INC, {(char_u *) "^\\s*#\\s*include", (char_u *) 0L} SCRIPTID_INIT
    }, {"includeexpr", "inex", P_STRING | P_ALLOCED | P_VI_DEF, (char_u *) &p_inex, PV_INEX, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"incsearch", "is", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_is, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"indentexpr", "inde", P_STRING | P_ALLOCED | P_VI_DEF | P_VIM, (char_u *) &p_inde, PV_INDE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"indentkeys", "indk", P_STRING | P_ALLOCED | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_indk, PV_INDK, {(char_u *) "0{,0},:,0#,!^F,o,O,e", (char_u *) 0L} SCRIPTID_INIT
    }, {"infercase", "inf", P_BOOL | P_VI_DEF, (char_u *) &p_inf, PV_INF, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"insertmode", "im", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_im, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"isfname", "isf", P_STRING | P_VI_DEF | P_COMMA | P_NODUP, (char_u *) &p_isf, PV_NONE, {(char_u *) "@,48-57,/,.,-,_,+,,,#,$,%,~,=", (char_u *) 0L} SCRIPTID_INIT
    }, {"isident", "isi", P_STRING | P_VI_DEF | P_COMMA | P_NODUP, (char_u *) &p_isi, PV_NONE, {(char_u *) "@,48-57,_,192-255", (char_u *) 0L} SCRIPTID_INIT
    }, {"iskeyword", "isk", P_STRING | P_ALLOCED | P_VIM | P_COMMA | P_NODUP, (char_u *) &p_isk, PV_ISK, {(char_u *) "@,48-57,_", ISK_LATIN1} SCRIPTID_INIT
    }, {"isprint", "isp", P_STRING | P_VI_DEF | P_RALL | P_COMMA | P_NODUP, (char_u *) &p_isp, PV_NONE, {ISP_LATIN1, (char_u *) 0L} SCRIPTID_INIT
    }, {"joinspaces", "js", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_js, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"key", NULL, P_STRING | P_ALLOCED | P_VI_DEF | P_NO_MKRC, (char_u *) &p_key, PV_KEY, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"keymap", "kmp", P_STRING | P_ALLOCED | P_VI_DEF | P_RBUF | P_RSTAT | P_NFNAME | P_PRI_MKRC, (char_u *) &p_keymap, PV_KMAP, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"keymodel", "km", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_km, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"keywordprg", "kp", P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) &p_kp, PV_KP, {(char_u *) "man", (char_u *) 0L} SCRIPTID_INIT
    }, {"langmap", "lmap", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP | P_SECURE, (char_u *) &p_langmap, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"langmenu", "lm", P_STRING | P_VI_DEF | P_NFNAME, (char_u *) &p_lm, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"langnoremap", "lnr", P_BOOL | P_VI_DEF, (char_u *) &p_lnr, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"langremap", "lrm", P_BOOL | P_VI_DEF, (char_u *) &p_lrm, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"laststatus", "ls", P_NUM | P_VI_DEF | P_RALL, (char_u *) &p_ls, PV_NONE, {(char_u *) 1L, (char_u *) 0L} SCRIPTID_INIT
    }, {"lazyredraw", "lz", P_BOOL | P_VI_DEF, (char_u *) &p_lz, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"linebreak", "lbr", P_BOOL | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_LBR, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"lines", NULL, P_NUM | P_NODEFAULT | P_NO_MKRC | P_VI_DEF | P_RCLR, (char_u *) &Rows, PV_NONE, {(char_u *) 24L, (char_u *) 0L} SCRIPTID_INIT
    }, {"linespace", "lsp", P_NUM | P_VI_DEF | P_RCLR, (char_u *) &p_linespace, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"lisp", NULL, P_BOOL | P_VI_DEF, (char_u *) &p_lisp, PV_LISP, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"lispwords", "lw", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_lispwords, PV_LW, {(char_u *) LISPWORD_VALUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"list", NULL, P_BOOL | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_LIST, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"listchars", "lcs", P_STRING | P_VI_DEF | P_RALL | P_ONECOMMA | P_NODUP, (char_u *) &p_lcs, PV_NONE, {(char_u *) "eol:$", (char_u *) 0L} SCRIPTID_INIT
    }, {"loadplugins", "lpl", P_BOOL | P_VI_DEF, (char_u *) &p_lpl, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"luadll", NULL, P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"macatsui", NULL, P_BOOL | P_VI_DEF | P_RCLR, (char_u *) NULL, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"macligatures", NULL, P_BOOL | P_VI_DEF | P_RCLR, (char_u *) &p_macligatures, PV_NONE, {(char_u *) FALSE, (char_u *) 0L}}, {"macmeta", "mmta", P_BOOL | P_VI_DEF, (char_u *) &p_mmta, PV_MMTA, {(char_u *) FALSE, (char_u *) 0L}}, {"macthinstrokes", NULL, P_BOOL | P_VI_DEF | P_RCLR, (char_u *) &p_macthinstrokes, PV_NONE, {(char_u *) FALSE, (char_u *) 0L}}, {"magic", NULL, P_BOOL | P_VI_DEF, (char_u *) &p_magic, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"makeef", "mef", P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) &p_mef, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"makeencoding", "menc", P_STRING | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"makeprg", "mp", P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) &p_mp, PV_MP, {(char_u *) "make", (char_u *) 0L} SCRIPTID_INIT
    }, {"matchpairs", "mps", P_STRING | P_ALLOCED | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_mps, PV_MPS, {(char_u *) "(:),{:},[:]", (char_u *) 0L} SCRIPTID_INIT
    }, {"matchtime", "mat", P_NUM | P_VI_DEF, (char_u *) &p_mat, PV_NONE, {(char_u *) 5L, (char_u *) 0L} SCRIPTID_INIT
    }, {"maxcombine", "mco", P_NUM | P_VI_DEF | P_CURSWANT, (char_u *) NULL, PV_NONE, {(char_u *) 2, (char_u *) 0L} SCRIPTID_INIT
    }, {"maxfuncdepth", "mfd", P_NUM | P_VI_DEF, (char_u *) &p_mfd, PV_NONE, {(char_u *) 100L, (char_u *) 0L} SCRIPTID_INIT
    }, {"maxmapdepth", "mmd", P_NUM | P_VI_DEF, (char_u *) &p_mmd, PV_NONE, {(char_u *) 1000L, (char_u *) 0L} SCRIPTID_INIT
    }, {"maxmem", "mm", P_NUM | P_VI_DEF, (char_u *) &p_mm, PV_NONE, {(char_u *) DFLT_MAXMEM, (char_u *) 0L} SCRIPTID_INIT
    }, {"maxmempattern", "mmp", P_NUM | P_VI_DEF, (char_u *) &p_mmp, PV_NONE, {(char_u *) 1000L, (char_u *) 0L} SCRIPTID_INIT
    }, {"maxmemtot", "mmt", P_NUM | P_VI_DEF, (char_u *) &p_mmt, PV_NONE, {(char_u *) DFLT_MAXMEMTOT, (char_u *) 0L} SCRIPTID_INIT
    }, {"menuitems", "mis", P_NUM | P_VI_DEF, (char_u *) &p_mis, PV_NONE, {(char_u *) 25L, (char_u *) 0L} SCRIPTID_INIT
    }, {"mesg", NULL, P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"mkspellmem", "msm", P_STRING | P_VI_DEF | P_EXPAND | P_SECURE, (char_u *) &p_msm, PV_NONE, {(char_u *) "460000,2000,500", (char_u *) 0L} SCRIPTID_INIT
    }, {"modeline", "ml", P_BOOL | P_VIM, (char_u *) &p_ml, PV_ML, {(char_u *) FALSE, (char_u *) TRUE} SCRIPTID_INIT
    }, {"modelines", "mls", P_NUM | P_VI_DEF, (char_u *) &p_mls, PV_NONE, {(char_u *) 5L, (char_u *) 0L} SCRIPTID_INIT
    }, {"modifiable", "ma", P_BOOL | P_VI_DEF | P_NOGLOB, (char_u *) &p_ma, PV_MA, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"modified", "mod", P_BOOL | P_NO_MKRC | P_VI_DEF | P_RSTAT, (char_u *) &p_mod, PV_MOD, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"more", NULL, P_BOOL | P_VIM, (char_u *) &p_more, PV_NONE, {(char_u *) FALSE, (char_u *) TRUE} SCRIPTID_INIT
    }, {"mouse", NULL, P_STRING | P_VI_DEF | P_FLAGLIST, (char_u *) &p_mouse, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"mousefocus", "mousef", P_BOOL | P_VI_DEF, (char_u *) &p_mousef, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"mousehide", "mh", P_BOOL | P_VI_DEF, (char_u *) &p_mh, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"mousemodel", "mousem", P_STRING | P_VI_DEF, (char_u *) &p_mousem, PV_NONE, {(char_u *) "popup_setpos", (char_u *) 0L} SCRIPTID_INIT
    }, {"mouseshape", "mouses", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_mouseshape, PV_NONE, {(char_u *) "i-r:beam,s:updown,sd:udsizing,vs:leftright,vd:lrsizing,m:no,ml:up-arrow,v:rightup-arrow", (char_u *) 0L} SCRIPTID_INIT
    }, {"mousetime", "mouset", P_NUM | P_VI_DEF, (char_u *) &p_mouset, PV_NONE, {(char_u *) 500L, (char_u *) 0L} SCRIPTID_INIT
    }, {"mzschemedll", NULL, P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"mzschemegcdll", NULL, P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"mzquantum", "mzq", P_NUM, (char_u *) NULL, PV_NONE, {(char_u *) 100L, (char_u *) 100L} SCRIPTID_INIT
    }, {"novice", NULL, P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"nrformats", "nf", P_STRING | P_ALLOCED | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_nf, PV_NF, {(char_u *) "bin,octal,hex", (char_u *) 0L} SCRIPTID_INIT
    }, {"number", "nu", P_BOOL | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_NU, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"numberwidth", "nuw", P_NUM | P_RWIN | P_VIM, (char_u *) VAR_WIN, PV_NUW, {(char_u *) 8L, (char_u *) 4L} SCRIPTID_INIT
    }, {"omnifunc", "ofu", P_STRING | P_ALLOCED | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"open", NULL, P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"opendevice", "odev", P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) FALSE} SCRIPTID_INIT
    }, {"operatorfunc", "opfunc", P_STRING | P_VI_DEF | P_SECURE, (char_u *) &p_opfunc, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"optimize", "opt", P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"osfiletype", "oft", P_STRING | P_ALLOCED | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"packpath", "pp", P_STRING | P_VI_DEF | P_EXPAND | P_ONECOMMA | P_NODUP | P_SECURE, (char_u *) &p_pp, PV_NONE, {(char_u *) DFLT_RUNTIMEPATH, (char_u *) 0L} SCRIPTID_INIT
    }, {"paragraphs", "para", P_STRING | P_VI_DEF, (char_u *) &p_para, PV_NONE, {(char_u *) "IPLPPPQPP TPHPLIPpLpItpplpipbp", (char_u *) 0L} SCRIPTID_INIT
    }, {"paste", NULL, P_BOOL | P_VI_DEF | P_PRI_MKRC, (char_u *) &p_paste, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"pastetoggle", "pt", P_STRING | P_VI_DEF, (char_u *) &p_pt, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"patchexpr", "pex", P_STRING | P_VI_DEF | P_SECURE, (char_u *) &p_pex, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"patchmode", "pm", P_STRING | P_VI_DEF | P_NFNAME, (char_u *) &p_pm, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"path", "pa", P_STRING | P_EXPAND | P_VI_DEF | P_COMMA | P_NODUP, (char_u *) &p_path, PV_PATH, {(char_u *) ".,/usr/include,,", (char_u *) 0L} SCRIPTID_INIT
    }, {"perldll", NULL, P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"preserveindent", "pi", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_pi, PV_PI, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"previewheight", "pvh", P_NUM | P_VI_DEF, (char_u *) &p_pvh, PV_NONE, {(char_u *) 12L, (char_u *) 0L} SCRIPTID_INIT
    }, {"previewwindow", "pvw", P_BOOL | P_VI_DEF | P_RSTAT | P_NOGLOB, (char_u *) VAR_WIN, PV_PVW, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"printdevice", "pdev", P_STRING | P_VI_DEF | P_SECURE, (char_u *) &p_pdev, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"printencoding", "penc", P_STRING | P_VI_DEF, (char_u *) &p_penc, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"printexpr", "pexpr", P_STRING | P_VI_DEF | P_SECURE, (char_u *) &p_pexpr, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"printfont", "pfn", P_STRING | P_VI_DEF, (char_u *) &p_pfn, PV_NONE, {(char_u *) "courier", (char_u *) 0L} SCRIPTID_INIT
    }, {"printheader", "pheader", P_STRING | P_VI_DEF | P_GETTEXT, (char_u *) &p_header, PV_NONE, {(char_u *) "%<%f%h%m%=Page %N", (char_u *) 0L} SCRIPTID_INIT
    }, {"printmbcharset", "pmbcs", P_STRING | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) NULL, (char_u *) 0L} SCRIPTID_INIT
    }, {"printmbfont", "pmbfn", P_STRING | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) NULL, (char_u *) 0L} SCRIPTID_INIT
    }, {"printoptions", "popt", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_popt, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"prompt", NULL, P_BOOL | P_VI_DEF, (char_u *) &p_prompt, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"pumheight", "ph", P_NUM | P_VI_DEF, (char_u *) &p_ph, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"pumwidth", "pw", P_NUM | P_VI_DEF, (char_u *) &p_pw, PV_NONE, {(char_u *) 15L, (char_u *) 15L} SCRIPTID_INIT
    }, {"pythonthreedll", NULL, P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) NULL, (char_u *) 0L} SCRIPTID_INIT
    }, {"pythonthreehome", NULL, P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) NULL, (char_u *) 0L} SCRIPTID_INIT
    }, {"pythondll", NULL, P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) NULL, (char_u *) 0L} SCRIPTID_INIT
    }, {"pythonhome", NULL, P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) NULL, (char_u *) 0L} SCRIPTID_INIT
    }, {"pyxversion", "pyx", P_NUM | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) DEFAULT_PYTHON_VER, (char_u *) 0L} SCRIPTID_INIT
    }, {"quoteescape", "qe", P_STRING | P_ALLOCED | P_VI_DEF, (char_u *) &p_qe, PV_QE, {(char_u *) "\\", (char_u *) 0L} SCRIPTID_INIT
    }, {"readonly", "ro", P_BOOL | P_VI_DEF | P_RSTAT | P_NOGLOB, (char_u *) &p_ro, PV_RO, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"redraw", NULL, P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"redrawtime", "rdt", P_NUM | P_VI_DEF, (char_u *) &p_rdt, PV_NONE, {(char_u *) 2000L, (char_u *) 0L} SCRIPTID_INIT
    }, {"regexpengine", "re", P_NUM | P_VI_DEF, (char_u *) &p_re, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"relativenumber", "rnu", P_BOOL | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_RNU, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"remap", NULL, P_BOOL | P_VI_DEF, (char_u *) &p_remap, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"renderoptions", "rop", P_STRING | P_ONECOMMA | P_RCLR | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) NULL, (char_u *) 0L} SCRIPTID_INIT
    }, {"report", NULL, P_NUM | P_VI_DEF, (char_u *) &p_report, PV_NONE, {(char_u *) 2L, (char_u *) 0L} SCRIPTID_INIT
    }, {"restorescreen", "rs", P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"revins", "ri", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_ri, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"rightleft", "rl", P_BOOL | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_RL, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"rightleftcmd", "rlc", P_STRING | P_ALLOCED | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_RLC, {(char_u *) "search", (char_u *) NULL} SCRIPTID_INIT
    }, {"rubydll", NULL, P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) NULL, (char_u *) 0L} SCRIPTID_INIT
    }, {"ruler", "ru", P_BOOL | P_VI_DEF | P_VIM | P_RSTAT, (char_u *) &p_ru, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"rulerformat", "ruf", P_STRING | P_VI_DEF | P_ALLOCED | P_RSTAT, (char_u *) &p_ruf, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"runtimepath", "rtp", P_STRING | P_VI_DEF | P_EXPAND | P_ONECOMMA | P_NODUP | P_SECURE, (char_u *) &p_rtp, PV_NONE, {(char_u *) DFLT_RUNTIMEPATH, (char_u *) 0L} SCRIPTID_INIT
    }, {"scroll", "scr", P_NUM | P_NO_MKRC | P_VI_DEF, (char_u *) VAR_WIN, PV_SCROLL, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"scrollbind", "scb", P_BOOL | P_VI_DEF, (char_u *) VAR_WIN, PV_SCBIND, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"scrolljump", "sj", P_NUM | P_VI_DEF | P_VIM, (char_u *) &p_sj, PV_NONE, {(char_u *) 1L, (char_u *) 0L} SCRIPTID_INIT
    }, {"scrolloff", "so", P_NUM | P_VI_DEF | P_VIM | P_RALL, (char_u *) &p_so, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"scrollopt", "sbo", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_sbo, PV_NONE, {(char_u *) "ver,jump", (char_u *) 0L} SCRIPTID_INIT
    }, {"sections", "sect", P_STRING | P_VI_DEF, (char_u *) &p_sections, PV_NONE, {(char_u *) "SHNHH HUnhsh", (char_u *) 0L} SCRIPTID_INIT
    }, {"secure", NULL, P_BOOL | P_VI_DEF | P_SECURE, (char_u *) &p_secure, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"selection", "sel", P_STRING | P_VI_DEF, (char_u *) &p_sel, PV_NONE, {(char_u *) "inclusive", (char_u *) 0L} SCRIPTID_INIT
    }, {"selectmode", "slm", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_slm, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"sessionoptions", "ssop", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_ssop, PV_NONE, {(char_u *) "blank,buffers,curdir,folds,help,options,tabpages,winsize", (char_u *) 0L} SCRIPTID_INIT
    }, {"shell", "sh", P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) &p_sh, PV_NONE, {(char_u *) "sh", (char_u *) 0L} SCRIPTID_INIT
    }, {"shellcmdflag", "shcf", P_STRING | P_VI_DEF | P_SECURE, (char_u *) &p_shcf, PV_NONE, {(char_u *) "-c", (char_u *) 0L} SCRIPTID_INIT
    }, {"shellpipe", "sp", P_STRING | P_VI_DEF | P_SECURE, (char_u *) &p_sp, PV_NONE, {(char_u *) "| tee", (char_u *) 0L} SCRIPTID_INIT
    }, {"shellquote", "shq", P_STRING | P_VI_DEF | P_SECURE, (char_u *) &p_shq, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"shellredir", "srr", P_STRING | P_VI_DEF | P_SECURE, (char_u *) &p_srr, PV_NONE, {(char_u *) ">", (char_u *) 0L} SCRIPTID_INIT
    }, {"shellslash", "ssl", P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"shelltemp", "stmp", P_BOOL, (char_u *) &p_stmp, PV_NONE, {(char_u *) FALSE, (char_u *) TRUE} SCRIPTID_INIT
    }, {"shelltype", "st", P_NUM | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"shellxquote", "sxq", P_STRING | P_VI_DEF | P_SECURE, (char_u *) &p_sxq, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"shellxescape", "sxe", P_STRING | P_VI_DEF | P_SECURE, (char_u *) &p_sxe, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"shiftround", "sr", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_sr, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"shiftwidth", "sw", P_NUM | P_VI_DEF, (char_u *) &p_sw, PV_SW, {(char_u *) 8L, (char_u *) 0L} SCRIPTID_INIT
    }, {"shortmess", "shm", P_STRING | P_VIM | P_FLAGLIST, (char_u *) &p_shm, PV_NONE, {(char_u *) "", (char_u *) "filnxtToO"} SCRIPTID_INIT
    }, {"shortname", "sn", P_BOOL | P_VI_DEF, (char_u *) &p_sn, PV_SN, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"showbreak", "sbr", P_STRING | P_VI_DEF | P_RALL, (char_u *) &p_sbr, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"showcmd", "sc", P_BOOL | P_VIM, (char_u *) &p_sc, PV_NONE, {(char_u *) FALSE, (char_u *) FALSE} SCRIPTID_INIT
    }, {"showfulltag", "sft", P_BOOL | P_VI_DEF, (char_u *) &p_sft, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"showmatch", "sm", P_BOOL | P_VI_DEF, (char_u *) &p_sm, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"showmode", "smd", P_BOOL | P_VIM, (char_u *) &p_smd, PV_NONE, {(char_u *) FALSE, (char_u *) TRUE} SCRIPTID_INIT
    }, {"showtabline", "stal", P_NUM | P_VI_DEF | P_RALL, (char_u *) &p_stal, PV_NONE, {(char_u *) 1L, (char_u *) 0L} SCRIPTID_INIT
    }, {"sidescroll", "ss", P_NUM | P_VI_DEF, (char_u *) &p_ss, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"sidescrolloff", "siso", P_NUM | P_VI_DEF | P_VIM | P_RBUF, (char_u *) &p_siso, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"signcolumn", "scl", P_STRING | P_ALLOCED | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_SCL, {(char_u *) "auto", (char_u *) 0L} SCRIPTID_INIT
    }, {"slowopen", "slow", P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"smartcase", "scs", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_scs, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"smartindent", "si", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_si, PV_SI, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"smarttab", "sta", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_sta, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"softtabstop", "sts", P_NUM | P_VI_DEF | P_VIM, (char_u *) &p_sts, PV_STS, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"sourceany", NULL, P_BOOL | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"spell", NULL, P_BOOL | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_SPELL, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"spellcapcheck", "spc", P_STRING | P_ALLOCED | P_VI_DEF | P_RBUF, (char_u *) &p_spc, PV_SPC, {(char_u *) "[.?!]\\_[\\])'\"	 ]\\+", (char_u *) 0L} SCRIPTID_INIT
    }, {"spellfile", "spf", P_STRING | P_EXPAND | P_ALLOCED | P_VI_DEF | P_SECURE | P_ONECOMMA, (char_u *) &p_spf, PV_SPF, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"spelllang", "spl", P_STRING | P_ALLOCED | P_VI_DEF | P_ONECOMMA | P_RBUF | P_EXPAND, (char_u *) &p_spl, PV_SPL, {(char_u *) "en", (char_u *) 0L} SCRIPTID_INIT
    }, {"spellsuggest", "sps", P_STRING | P_VI_DEF | P_EXPAND | P_SECURE | P_ONECOMMA, (char_u *) &p_sps, PV_NONE, {(char_u *) "best", (char_u *) 0L} SCRIPTID_INIT
    }, {"splitbelow", "sb", P_BOOL | P_VI_DEF, (char_u *) &p_sb, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"splitright", "spr", P_BOOL | P_VI_DEF, (char_u *) &p_spr, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"startofline", "sol", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_sol, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"statusline", "stl", P_STRING | P_VI_DEF | P_ALLOCED | P_RSTAT, (char_u *) &p_stl, PV_STL, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"suffixes", "su", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_su, PV_NONE, {(char_u *) ".bak,~,.o,.h,.info,.swp,.obj", (char_u *) 0L} SCRIPTID_INIT
    }, {"suffixesadd", "sua", P_STRING | P_VI_DEF | P_ALLOCED | P_ONECOMMA | P_NODUP, (char_u *) &p_sua, PV_SUA, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"swapfile", "swf", P_BOOL | P_VI_DEF | P_RSTAT, (char_u *) &p_swf, PV_SWF, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"swapsync", "sws", P_STRING | P_VI_DEF, (char_u *) &p_sws, PV_NONE, {(char_u *) "fsync", (char_u *) 0L} SCRIPTID_INIT
    }, {"switchbuf", "swb", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_swb, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"synmaxcol", "smc", P_NUM | P_VI_DEF | P_RBUF, (char_u *) &p_smc, PV_SMC, {(char_u *) 3000L, (char_u *) 0L} SCRIPTID_INIT
    }, {"syntax", "syn", P_STRING | P_ALLOCED | P_VI_DEF | P_NOGLOB | P_NFNAME, (char_u *) &p_syn, PV_SYN, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"tabline", "tal", P_STRING | P_VI_DEF | P_RALL, (char_u *) &p_tal, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"tabpagemax", "tpm", P_NUM | P_VI_DEF, (char_u *) &p_tpm, PV_NONE, {(char_u *) 10L, (char_u *) 0L} SCRIPTID_INIT
    }, {"tabstop", "ts", P_NUM | P_VI_DEF | P_RBUF, (char_u *) &p_ts, PV_TS, {(char_u *) 8L, (char_u *) 0L} SCRIPTID_INIT
    }, {"tagbsearch", "tbs", P_BOOL | P_VI_DEF, (char_u *) &p_tbs, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"tagcase", "tc", P_STRING | P_VIM, (char_u *) &p_tc, PV_TC, {(char_u *) "followic", (char_u *) "followic"} SCRIPTID_INIT
    }, {"taglength", "tl", P_NUM | P_VI_DEF, (char_u *) &p_tl, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"tagrelative", "tr", P_BOOL | P_VIM, (char_u *) &p_tr, PV_NONE, {(char_u *) FALSE, (char_u *) TRUE} SCRIPTID_INIT
    }, {"tags", "tag", P_STRING | P_EXPAND | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_tags, PV_TAGS, {(char_u *) "./tags,tags", (char_u *) 0L} SCRIPTID_INIT
    }, {"tagstack", "tgst", P_BOOL | P_VI_DEF, (char_u *) &p_tgst, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"tcldll", NULL, P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"term", NULL, P_STRING | P_EXPAND | P_NODEFAULT | P_NO_MKRC | P_VI_DEF | P_RALL, (char_u *) &T_NAME, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"termbidi", "tbidi", P_BOOL | P_VI_DEF, (char_u *) &p_tbidi, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"termencoding", "tenc", P_STRING | P_VI_DEF | P_RCLR, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"termguicolors", "tgc", P_BOOL | P_VI_DEF | P_VIM | P_RCLR, (char_u *) &p_tgc, PV_NONE, {(char_u *) FALSE, (char_u *) FALSE} SCRIPTID_INIT
    }, {"termkey", "tk", P_STRING | P_ALLOCED | P_RWIN | P_VI_DEF, (char_u *) VAR_WIN, PV_TK, {(char_u *) "", (char_u *) NULL} SCRIPTID_INIT
    }, {"termsize", "tms", P_STRING | P_ALLOCED | P_RWIN | P_VI_DEF, (char_u *) VAR_WIN, PV_TMS, {(char_u *) "", (char_u *) NULL} SCRIPTID_INIT
    }, {"terse", NULL, P_BOOL | P_VI_DEF, (char_u *) &p_terse, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"textauto", "ta", P_BOOL | P_VIM, (char_u *) &p_ta, PV_NONE, {(char_u *) DFLT_TEXTAUTO, (char_u *) TRUE} SCRIPTID_INIT
    }, {"textmode", "tx", P_BOOL | P_VI_DEF | P_NO_MKRC, (char_u *) &p_tx, PV_TX, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"textwidth", "tw", P_NUM | P_VI_DEF | P_VIM | P_RBUF, (char_u *) &p_tw, PV_TW, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"thesaurus", "tsr", P_STRING | P_EXPAND | P_VI_DEF | P_ONECOMMA | P_NODUP | P_NDNAME, (char_u *) &p_tsr, PV_TSR, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"tildeop", "top", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_to, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"timeout", "to", P_BOOL | P_VI_DEF, (char_u *) &p_timeout, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"timeoutlen", "tm", P_NUM | P_VI_DEF, (char_u *) &p_tm, PV_NONE, {(char_u *) 1000L, (char_u *) 0L} SCRIPTID_INIT
    }, {"title", NULL, P_BOOL | P_VI_DEF, (char_u *) &p_title, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"titlelen", NULL, P_NUM | P_VI_DEF, (char_u *) &p_titlelen, PV_NONE, {(char_u *) 85L, (char_u *) 0L} SCRIPTID_INIT
    }, {"titleold", NULL, P_STRING | P_VI_DEF | P_GETTEXT | P_SECURE | P_NO_MKRC, (char_u *) &p_titleold, PV_NONE, {(char_u *) N_ ("Thanks for flying Vim"), (char_u *) 0L} SCRIPTID_INIT
    }, {"titlestring", NULL, P_STRING | P_VI_DEF, (char_u *) &p_titlestring, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"toolbar", "tb", P_STRING | P_ONECOMMA | P_VI_DEF | P_NODUP, (char_u *) &p_toolbar, PV_NONE, {(char_u *) "icons,tooltips", (char_u *) 0L} SCRIPTID_INIT
    }, {"toolbariconsize", "tbis", P_STRING | P_VI_DEF, (char_u *) &p_tbis, PV_NONE, {(char_u *) "small", (char_u *) 0L} SCRIPTID_INIT
    }, {"transparency", "transp", P_NUM | P_VIM | P_RCLR, (char_u *) &p_transp, PV_NONE, {(char_u *) 0L, (char_u *) 0L}}, {"ttimeout", NULL, P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_ttimeout, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"ttimeoutlen", "ttm", P_NUM | P_VI_DEF, (char_u *) &p_ttm, PV_NONE, {(char_u *) -1L, (char_u *) 0L} SCRIPTID_INIT
    }, {"ttybuiltin", "tbi", P_BOOL | P_VI_DEF, (char_u *) &p_tbi, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"ttyfast", "tf", P_BOOL | P_NO_MKRC | P_VI_DEF, (char_u *) &p_tf, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"ttymouse", "ttym", P_STRING | P_NODEFAULT | P_NO_MKRC | P_VI_DEF, (char_u *) &p_ttym, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"ttyscroll", "tsl", P_NUM | P_VI_DEF, (char_u *) &p_ttyscroll, PV_NONE, {(char_u *) 999L, (char_u *) 0L} SCRIPTID_INIT
    }, {"ttytype", "tty", P_STRING | P_EXPAND | P_NODEFAULT | P_NO_MKRC | P_VI_DEF | P_RALL, (char_u *) &T_NAME, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"undodir", "udir", P_STRING | P_EXPAND | P_ONECOMMA | P_NODUP | P_SECURE | P_VI_DEF, (char_u *) &p_udir, PV_NONE, {(char_u *) ".", (char_u *) 0L} SCRIPTID_INIT
    }, {"undofile", "udf", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_udf, PV_UDF, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"undolevels", "ul", P_NUM | P_VI_DEF, (char_u *) &p_ul, PV_UL, {(char_u *) 1000L, (char_u *) 0L} SCRIPTID_INIT
    }, {"undoreload", "ur", P_NUM | P_VI_DEF, (char_u *) &p_ur, PV_NONE, {(char_u *) 10000L, (char_u *) 0L} SCRIPTID_INIT
    }, {"updatecount", "uc", P_NUM | P_VI_DEF, (char_u *) &p_uc, PV_NONE, {(char_u *) 200L, (char_u *) 0L} SCRIPTID_INIT
    }, {"updatetime", "ut", P_NUM | P_VI_DEF, (char_u *) &p_ut, PV_NONE, {(char_u *) 4000L, (char_u *) 0L} SCRIPTID_INIT
    }, {"verbose", "vbs", P_NUM | P_VI_DEF, (char_u *) &p_verbose, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"verbosefile", "vfile", P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) &p_vfile, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"viewdir", "vdir", P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) &p_vdir, PV_NONE, {(char_u *) DFLT_VDIR, (char_u *) 0L} SCRIPTID_INIT
    }, {"viewoptions", "vop", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_vop, PV_NONE, {(char_u *) "folds,options,cursor,curdir", (char_u *) 0L} SCRIPTID_INIT
    }, {"viminfo", "vi", P_STRING | P_ONECOMMA | P_NODUP | P_SECURE, (char_u *) &p_viminfo, PV_NONE, {(char_u *) "", (char_u *) "'100,<50,s10,h"} SCRIPTID_INIT
    }, {"viminfofile", "vif", P_STRING | P_ONECOMMA | P_NODUP | P_SECURE | P_VI_DEF, (char_u *) &p_viminfofile, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"virtualedit", "ve", P_STRING | P_ONECOMMA | P_NODUP | P_VI_DEF | P_VIM | P_CURSWANT, (char_u *) &p_ve, PV_NONE, {(char_u *) "", (char_u *) ""} SCRIPTID_INIT
    }, {"visualbell", "vb", P_BOOL | P_VI_DEF, (char_u *) &p_vb, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"w300", NULL, P_NUM | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"w1200", NULL, P_NUM | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"w9600", NULL, P_NUM | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"warn", NULL, P_BOOL | P_VI_DEF, (char_u *) &p_warn, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"weirdinvert", "wiv", P_BOOL | P_VI_DEF | P_RCLR, (char_u *) &p_wiv, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"whichwrap", "ww", P_STRING | P_VIM | P_ONECOMMA | P_FLAGLIST, (char_u *) &p_ww, PV_NONE, {(char_u *) "", (char_u *) "b,s"} SCRIPTID_INIT
    }, {"wildchar", "wc", P_NUM | P_VIM, (char_u *) &p_wc, PV_NONE, {(char_u *) (long ) Ctrl_E, (char_u *) (long ) TAB} SCRIPTID_INIT
    }, {"wildcharm", "wcm", P_NUM | P_VI_DEF, (char_u *) &p_wcm, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"wildignore", "wig", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_wig, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"wildignorecase", "wic", P_BOOL | P_VI_DEF, (char_u *) &p_wic, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"wildmenu", "wmnu", P_BOOL | P_VI_DEF, (char_u *) &p_wmnu, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"wildmode", "wim", P_STRING | P_VI_DEF | P_ONECOMMA | P_NODUP, (char_u *) &p_wim, PV_NONE, {(char_u *) "full", (char_u *) 0L} SCRIPTID_INIT
    }, {"wildoptions", "wop", P_STRING | P_VI_DEF, (char_u *) &p_wop, PV_NONE, {(char_u *) "", (char_u *) 0L} SCRIPTID_INIT
    }, {"winaltkeys", "wak", P_STRING | P_VI_DEF, (char_u *) NULL, PV_NONE, {(char_u *) NULL, (char_u *) 0L} SCRIPTID_INIT
    }, {"window", "wi", P_NUM | P_VI_DEF, (char_u *) &p_window, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"winheight", "wh", P_NUM | P_VI_DEF, (char_u *) &p_wh, PV_NONE, {(char_u *) 1L, (char_u *) 0L} SCRIPTID_INIT
    }, {"winfixheight", "wfh", P_BOOL | P_VI_DEF | P_RSTAT, (char_u *) VAR_WIN, PV_WFH, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"winfixwidth", "wfw", P_BOOL | P_VI_DEF | P_RSTAT, (char_u *) VAR_WIN, PV_WFW, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"winminheight", "wmh", P_NUM | P_VI_DEF, (char_u *) &p_wmh, PV_NONE, {(char_u *) 1L, (char_u *) 0L} SCRIPTID_INIT
    }, {"winminwidth", "wmw", P_NUM | P_VI_DEF, (char_u *) &p_wmw, PV_NONE, {(char_u *) 1L, (char_u *) 0L} SCRIPTID_INIT
    }, {"winptydll", NULL, P_STRING | P_EXPAND | P_VI_DEF | P_SECURE, (char_u *) NULL, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"winwidth", "wiw", P_NUM | P_VI_DEF, (char_u *) &p_wiw, PV_NONE, {(char_u *) 20L, (char_u *) 0L} SCRIPTID_INIT
    }, {"wrap", NULL, P_BOOL | P_VI_DEF | P_RWIN, (char_u *) VAR_WIN, PV_WRAP, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"wrapmargin", "wm", P_NUM | P_VI_DEF, (char_u *) &p_wm, PV_WM, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, {"wrapscan", "ws", P_BOOL | P_VI_DEF, (char_u *) &p_ws, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"write", NULL, P_BOOL | P_VI_DEF, (char_u *) &p_write, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"writeany", "wa", P_BOOL | P_VI_DEF, (char_u *) &p_wa, PV_NONE, {(char_u *) FALSE, (char_u *) 0L} SCRIPTID_INIT
    }, {"writebackup", "wb", P_BOOL | P_VI_DEF | P_VIM, (char_u *) &p_wb, PV_NONE, {(char_u *) TRUE, (char_u *) 0L} SCRIPTID_INIT
    }, {"writedelay", "wd", P_NUM | P_VI_DEF, (char_u *) &p_wd, PV_NONE, {(char_u *) 0L, (char_u *) 0L} SCRIPTID_INIT
    }, 
    #define p_term(sss, vvv)   {sss, NULL, P_STRING|P_VI_DEF|P_RALL|P_SECURE, (char_u *)&vvv, PV_NONE, {(char_u *)"", (char_u *)0L} SCRIPTID_INIT},
    p_term ("t_AB", T_CAB) p_term ("t_AF", T_CAF) p_term ("t_AL", T_CAL) p_term ("t_al", T_AL) p_term ("t_bc", T_BC) p_term ("t_BE", T_BE) p_term ("t_BD", T_BD) p_term ("t_cd", T_CD) p_term ("t_ce", T_CE) p_term ("t_cl", T_CL) p_term ("t_cm", T_CM) p_term ("t_Ce", T_UCE) p_term ("t_Co", T_CCO) p_term ("t_CS", T_CCS) p_term ("t_Cs", T_UCS) p_term ("t_cs", T_CS) p_term ("t_CV", T_CSV) p_term ("t_da", T_DA) p_term ("t_db", T_DB) p_term ("t_DL", T_CDL) p_term ("t_dl", T_DL) p_term ("t_EC", T_CEC) p_term ("t_EI", T_CEI) p_term ("t_fs", T_FS) p_term ("t_GP", T_CGP) p_term ("t_IE", T_CIE) p_term ("t_IS", T_CIS) p_term ("t_ke", T_KE) p_term ("t_ks", T_KS) p_term ("t_le", T_LE) p_term ("t_mb", T_MB) p_term ("t_md", T_MD) p_term ("t_me", T_ME) p_term ("t_mr", T_MR) p_term ("t_ms", T_MS) p_term ("t_nd", T_ND) p_term ("t_op", T_OP) p_term ("t_RF", T_RFG) p_term ("t_RB", T_RBG) p_term ("t_RC", T_CRC) p_term ("t_RI", T_CRI) p_term ("t_RS", T_CRS) p_term ("t_RV", T_CRV) p_term ("t_Sb", T_CSB) p_term ("t_SC", T_CSC) p_term ("t_se", T_SE) p_term ("t_Sf", T_CSF) p_term ("t_SH", T_CSH) p_term ("t_SI", T_CSI) p_term ("t_so", T_SO) p_term ("t_SR", T_CSR) p_term ("t_sr", T_SR) p_term ("t_Te", T_STE) p_term ("t_te", T_TE) p_term ("t_ti", T_TI) p_term ("t_Ts", T_STS) p_term ("t_ts", T_TS) p_term ("t_u7", T_U7) p_term ("t_ue", T_UE) p_term ("t_us", T_US) p_term ("t_ut", T_UT) p_term ("t_vb", T_VB) p_term ("t_ve", T_VE) p_term ("t_vi", T_VI) p_term ("t_VS", T_CVS) p_term ("t_vs", T_VS) p_term ("t_WP", T_CWP) p_term ("t_WS", T_CWS) p_term ("t_xn", T_XN) p_term ("t_xs", T_XS) p_term ("t_ZH", T_CZH) p_term ("t_ZR", T_CZR) p_term ("t_8f", T_8F) p_term ("t_8b", T_8B) {NULL, NULL, 0, NULL, PV_NONE, {NULL, NULL} SCRIPTID_INIT
    }
};
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
EXTERN char_u *p_titlestring;
char_u expand_option_name [5] = {'t', '_', NUL, NUL, NUL};
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
EXTERN char_u e_noroom [] INIT (= N_ ("E36: Not enough room"));
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
EXTERN char_u e_readonlyvar [] INIT (= N_ ("E46: Cannot change read-only variable \"%s\""));
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
int expand_option_flags = 0;
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
char_u *p_spc;
long  p_smc;
long  p_imsearch;
char_u *p_cpt;
char_u *p_cms;
char_u *p_com;
char_u *p_cinw;
char_u *p_cino;
char_u *p_cink;
int p_cin;
int p_ci;
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
int expand_option_idx = -1;
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
char * (p_scl_values []) = {"yes", "no", "auto", NULL};
char * (p_cot_values []) = {"menu", "menuone", "longest", "preview", "noinsert", "noselect", NULL};
char * (p_fcl_values []) = {"all", NULL};
char * (p_fdm_values []) = {"manual", "expr", "marker", "indent", "syntax", "diff", NULL};
char * (p_bs_values []) = {"indent", "eol", "start", NULL};
char * (p_bufhidden_values []) = {"hide", "unload", "delete", "wipe", NULL};
char * (p_buftype_values []) = {"nofile", "nowrite", "quickfix", "help", "terminal", "acwrite", NULL};
char * (p_ead_values []) = {"both", "ver", "hor", NULL};
char * (p_debug_values []) = {"msg", "throw", "beep", NULL};
char * (p_scbopt_values []) = {"ver", "hor", "jump", NULL};
char * (p_km_values []) = {"startsel", "stopsel", NULL};
char * (p_slm_values []) = {"mouse", "key", "cmd", NULL};
char * (p_sel_values []) = {"inclusive", "exclusive", "old", NULL};
char * (p_mousem_values []) = {"extend", "popup", "popup_setpos", "mac", NULL};
char * (p_wop_values []) = {"tagfile", NULL};
char * (p_cm_values []) = {"zip", "blowfish", "blowfish2", NULL};
char * (p_ff_values []) = {FF_UNIX, FF_DOS, FF_MAC, NULL};
char * (p_nf_values []) = {"bin", "octal", "hex", "alpha", NULL};
char * (p_bg_values []) = {"light", "dark", NULL};
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

void free_string_option (char_u *p) {
    if (p != empty_option)
        vim_free (p);
}

int signcolumn_on (win_T *wp) {
    if (*wp->w_p_scl == 'n')
        return FALSE;
    if (*wp->w_p_scl == 'y')
        return TRUE;
    return (wp->w_buffer->b_signlist != NULL || wp->w_buffer->b_has_sign_column);
}

void set_number_default (char *name, long  val) {
    int opt_idx;
    opt_idx = findoption ((char_u *) name);
    if (opt_idx >= 0)
        options[opt_idx].def_val[VI_DEFAULT] = (char_u *) (long_i) val;
}

static int findoption (char_u *arg) {
    int opt_idx;
    char *s, *p;
    static short  quick_tab [27] = {0, 0};
    int is_term_opt;
    if (quick_tab[1] == 0) {
        p = options[0].fullname;
        for (opt_idx = 1; (s = options[opt_idx].fullname) != NULL; opt_idx++) {
            if (s[0] != p[0]) {
                if (s[0] == 't' && s[1] == '_')
                    quick_tab[26] = opt_idx;
                else
                    quick_tab[CharOrdLow (s[0])] = opt_idx;
            }
            p = s;
        }
    }
    if (arg[0] < 'a' || arg[0] > 'z')
        return -1;
    is_term_opt = (arg[0] == 't' && arg[1] == '_');
    if (is_term_opt)
        opt_idx = quick_tab[26];
    else
        opt_idx = quick_tab[CharOrdLow (arg[0])];
    for (; (s = options[opt_idx].fullname) != NULL; opt_idx++) {
        if (STRCMP (arg, s) == 0)
            break;
    }
    if (s == NULL && !is_term_opt) {
        opt_idx = quick_tab[CharOrdLow (arg[0])];
        for (; options[opt_idx].fullname != NULL; opt_idx++) {
            s = options[opt_idx].shortname;
            if (s != NULL && STRCMP (arg, s) == 0)
                break;
            s = NULL;
        }
    }
    if (s == NULL)
        opt_idx = -1;
    return opt_idx;
}

char_u *get_highlight_default (void) {
    int i;
    i = findoption ((char_u *) "hl");
    if (i >= 0)
        return options[i].def_val[VI_DEFAULT];
    return (char_u *) NULL;
}

int was_set_insecurely (char_u *opt, int opt_flags) {
    int idx = findoption (opt);
    long_u *flagp;
    if (idx >= 0) {
        flagp = insecure_flag (idx, opt_flags);
        return (*flagp & P_INSECURE) != 0;
    }
    internal_error ("was_set_insecurely()");
    return -1;
}

static long_u *insecure_flag (int opt_idx, int opt_flags) {
    if (opt_flags & OPT_LOCAL)
        switch ((int) options[opt_idx].indir) {
        case PV_STL :
            return &curwin->w_p_stl_flags;
        case PV_FDE :
            return &curwin->w_p_fde_flags;
        case PV_FDT :
            return &curwin->w_p_fdt_flags;
        case PV_BEXPR :
            return &curbuf->b_p_bexpr_flags;
        case PV_INDE :
            return &curbuf->b_p_inde_flags;
        case PV_FEX :
            return &curbuf->b_p_fex_flags;
        case PV_INEX :
            return &curbuf->b_p_inex_flags;
        }
    return &options[opt_idx].flags;
}

int file_ff_differs (buf_T *buf, int ignore_empty) {
    if (buf->b_flags & BF_NEVERLOADED)
        return FALSE;
    if (ignore_empty && (buf->b_flags & BF_NEW) && buf->b_ml.ml_line_count == 1 && *ml_get_buf (buf, (linenr_T) 1, FALSE) == NUL)
        return FALSE;
    if (buf->b_start_ffc != *buf->b_p_ff)
        return TRUE;
    if ((buf->b_p_bin || !buf->b_p_fixeol) && buf->b_start_eol != buf->b_p_eol)
        return TRUE;
    return FALSE;
}

void clear_winopt (winopt_T *wop) {
    clear_string_option (& wop -> wo_fdi);
    clear_string_option (& wop -> wo_fdm);
    clear_string_option (& wop -> wo_fdm_save);
    clear_string_option (& wop -> wo_fde);
    clear_string_option (& wop -> wo_fdt);
    clear_string_option (& wop -> wo_fmr);
    clear_string_option (& wop -> wo_scl);
    clear_string_option (& wop -> wo_briopt);
    clear_string_option (& wop -> wo_rlc);
    clear_string_option (& wop -> wo_stl);
    clear_string_option (& wop -> wo_cc);
    clear_string_option (& wop -> wo_cocu);
    clear_string_option (& wop -> wo_tk);
    clear_string_option (& wop -> wo_tms);
}

void clear_string_option (char_u **pp) {
    if (*pp != empty_option)
        vim_free (*pp);
    *pp = empty_option;
}

void copy_winopt (winopt_T *from, winopt_T *to) {
    to->wo_arab = from->wo_arab;
    to->wo_list = from->wo_list;
    to->wo_nu = from->wo_nu;
    to->wo_rnu = from->wo_rnu;
    to->wo_nuw = from->wo_nuw;
    to->wo_rl = from->wo_rl;
    to->wo_rlc = vim_strsave (from->wo_rlc);
    to->wo_stl = vim_strsave (from->wo_stl);
    to->wo_wrap = from->wo_wrap;
    to->wo_wrap_save = from->wo_wrap_save;
    to->wo_lbr = from->wo_lbr;
    to->wo_bri = from->wo_bri;
    to->wo_briopt = vim_strsave (from->wo_briopt);
    to->wo_scb = from->wo_scb;
    to->wo_scb_save = from->wo_scb_save;
    to->wo_crb = from->wo_crb;
    to->wo_crb_save = from->wo_crb_save;
    to->wo_spell = from->wo_spell;
    to->wo_cuc = from->wo_cuc;
    to->wo_cul = from->wo_cul;
    to->wo_cc = vim_strsave (from->wo_cc);
    to->wo_diff = from->wo_diff;
    to->wo_diff_saved = from->wo_diff_saved;
    to->wo_cocu = vim_strsave (from->wo_cocu);
    to->wo_cole = from->wo_cole;
    to->wo_tk = vim_strsave (from->wo_tk);
    to->wo_tms = vim_strsave (from->wo_tms);
    to->wo_fdc = from->wo_fdc;
    to->wo_fdc_save = from->wo_fdc_save;
    to->wo_fen = from->wo_fen;
    to->wo_fen_save = from->wo_fen_save;
    to->wo_fdi = vim_strsave (from->wo_fdi);
    to->wo_fml = from->wo_fml;
    to->wo_fdl = from->wo_fdl;
    to->wo_fdl_save = from->wo_fdl_save;
    to->wo_fdm = vim_strsave (from->wo_fdm);
    to->wo_fdm_save = from->wo_diff_saved ? vim_strsave (from->wo_fdm_save) : empty_option;
    to->wo_fdn = from->wo_fdn;
    to->wo_fde = vim_strsave (from->wo_fde);
    to->wo_fdt = vim_strsave (from->wo_fdt);
    to->wo_fmr = vim_strsave (from->wo_fmr);
    to->wo_scl = vim_strsave (from->wo_scl);
    check_winopt (to);
}

static void check_winopt (winopt_T *wop) {
    check_string_option (& wop -> wo_fdi);
    check_string_option (& wop -> wo_fdm);
    check_string_option (& wop -> wo_fdm_save);
    check_string_option (& wop -> wo_fde);
    check_string_option (& wop -> wo_fdt);
    check_string_option (& wop -> wo_fmr);
    check_string_option (& wop -> wo_scl);
    check_string_option (& wop -> wo_rlc);
    check_string_option (& wop -> wo_stl);
    check_string_option (& wop -> wo_cc);
    check_string_option (& wop -> wo_cocu);
    check_string_option (& wop -> wo_tk);
    check_string_option (& wop -> wo_tms);
    check_string_option (& wop -> wo_briopt);
}

static void check_string_option (char_u **pp) {
    if (*pp == NULL)
        *pp = empty_option;
}

void buf_copy_options (buf_T *buf, int flags) {
    int should_copy = TRUE;
    char_u *save_p_isk = NULL;
    int dont_do_help;
    int did_isk = FALSE;
    if (p_cpo != NULL) {
        if ((vim_strchr (p_cpo, CPO_BUFOPTGLOB) == NULL || !(flags & BCO_ENTER)) && (buf->b_p_initialized || (!(flags & BCO_ENTER) && vim_strchr (p_cpo, CPO_BUFOPT) != NULL)))
            should_copy = FALSE;
        if (should_copy || (flags & BCO_ALWAYS)) {
            dont_do_help = ((flags & BCO_NOHELP) && buf->b_help) || buf->b_p_initialized;
            if (dont_do_help) {
                save_p_isk = buf->b_p_isk;
                buf->b_p_isk = NULL;
            }
            if (!buf->b_p_initialized) {
                free_buf_options (buf, TRUE);
                buf->b_p_ro = FALSE;
                buf->b_p_tx = p_tx;
                switch (*p_ffs) {
                case 'm' :
                    buf->b_p_ff = vim_strsave ((char_u *) FF_MAC);
                    break;
                case 'd' :
                    buf->b_p_ff = vim_strsave ((char_u *) FF_DOS);
                    break;
                case 'u' :
                    buf->b_p_ff = vim_strsave ((char_u *) FF_UNIX);
                    break;
                default :
                    buf->b_p_ff = vim_strsave (p_ff);
                }
                if (buf->b_p_ff != NULL)
                    buf->b_start_ffc = *buf->b_p_ff;
                buf->b_p_bh = empty_option;
                buf->b_p_bt = empty_option;
            }
            else
                free_buf_options (buf, FALSE);
            buf->b_p_ai = p_ai;
            buf->b_p_ai_nopaste = p_ai_nopaste;
            buf->b_p_sw = p_sw;
            buf->b_p_tw = p_tw;
            buf->b_p_tw_nopaste = p_tw_nopaste;
            buf->b_p_tw_nobin = p_tw_nobin;
            buf->b_p_wm = p_wm;
            buf->b_p_wm_nopaste = p_wm_nopaste;
            buf->b_p_wm_nobin = p_wm_nobin;
            buf->b_p_bin = p_bin;
            buf->b_p_fixeol = p_fixeol;
            buf->b_p_et = p_et;
            buf->b_p_et_nobin = p_et_nobin;
            buf->b_p_et_nopaste = p_et_nopaste;
            buf->b_p_ml = p_ml;
            buf->b_p_ml_nobin = p_ml_nobin;
            buf->b_p_inf = p_inf;
            buf->b_p_swf = cmdmod.noswapfile ? FALSE : p_swf;
            buf->b_p_cpt = vim_strsave (p_cpt);
            buf->b_p_sts = p_sts;
            buf->b_p_sts_nopaste = p_sts_nopaste;
            buf->b_p_sn = p_sn;
            buf->b_p_com = vim_strsave (p_com);
            buf->b_p_cms = vim_strsave (p_cms);
            buf->b_p_fo = vim_strsave (p_fo);
            buf->b_p_flp = vim_strsave (p_flp);
            buf->b_p_nf = vim_strsave (p_nf);
            buf->b_p_mps = vim_strsave (p_mps);
            buf->b_p_si = p_si;
            buf->b_p_ci = p_ci;
            buf->b_p_cin = p_cin;
            buf->b_p_cink = vim_strsave (p_cink);
            buf->b_p_cino = vim_strsave (p_cino);
            buf->b_p_ft = empty_option;
            buf->b_p_pi = p_pi;
            buf->b_p_cinw = vim_strsave (p_cinw);
            buf->b_p_lisp = p_lisp;
            buf->b_p_syn = empty_option;
            buf->b_p_smc = p_smc;
            buf->b_s.b_syn_isk = empty_option;
            buf->b_s.b_p_spc = vim_strsave (p_spc);
            (void) compile_cap_prog (&buf->b_s);
            buf->b_s.b_p_spf = vim_strsave (p_spf);
            buf->b_s.b_p_spl = vim_strsave (p_spl);
            buf->b_p_inde = vim_strsave (p_inde);
            buf->b_p_indk = vim_strsave (p_indk);
            buf->b_p_fp = empty_option;
            buf->b_p_fex = vim_strsave (p_fex);
            buf->b_p_key = vim_strsave (p_key);
            buf->b_p_sua = vim_strsave (p_sua);
            buf->b_p_keymap = vim_strsave (p_keymap);
            buf->b_kmap_state |= KEYMAP_INIT;
            buf->b_p_mmta = p_mmta;
            buf->b_p_iminsert = p_iminsert;
            buf->b_p_imsearch = p_imsearch;
            buf->b_p_ar = -1;
            buf->b_p_ul = NO_LOCAL_UNDOLEVEL;
            buf->b_p_bkc = empty_option;
            buf->b_bkc_flags = 0;
            buf->b_p_gp = empty_option;
            buf->b_p_mp = empty_option;
            buf->b_p_efm = empty_option;
            buf->b_p_ep = empty_option;
            buf->b_p_kp = empty_option;
            buf->b_p_path = empty_option;
            buf->b_p_tags = empty_option;
            buf->b_p_tc = empty_option;
            buf->b_tc_flags = 0;
            buf->b_p_def = empty_option;
            buf->b_p_inc = empty_option;
            buf->b_p_inex = vim_strsave (p_inex);
            buf->b_p_dict = empty_option;
            buf->b_p_tsr = empty_option;
            buf->b_p_qe = vim_strsave (p_qe);
            buf->b_p_bexpr = empty_option;
            buf->b_p_cm = empty_option;
            buf->b_p_udf = p_udf;
            buf->b_p_lw = empty_option;
            if (dont_do_help)
                buf->b_p_isk = save_p_isk;
            else {
                buf->b_p_isk = vim_strsave (p_isk);
                did_isk = TRUE;
                buf->b_p_ts = p_ts;
                buf->b_help = FALSE;
                if (buf->b_p_bt[0] == 'h')
                    clear_string_option (&buf->b_p_bt);
                buf->b_p_ma = p_ma;
            }
        }
        if (should_copy)
            buf->b_p_initialized = TRUE;
    }
    check_buf_options (buf);
    if (did_isk)
        (void) buf_init_chartab (buf, FALSE);
}

static char_u *compile_cap_prog (synblock_T *synblock) {
    regprog_T *rp = synblock->b_cap_prog;
    char_u *re;
    if (*synblock->b_p_spc == NUL)
        synblock->b_cap_prog = NULL;
    else {
        re = concat_str ((char_u *) "^", synblock->b_p_spc);
        if (re != NULL) {
            synblock->b_cap_prog = vim_regcomp (re, RE_MAGIC);
            vim_free (re);
            if (synblock->b_cap_prog == NULL) {
                synblock->b_cap_prog = rp;
                return e_invarg;
            }
        }
    }
    vim_regfree (rp);
    return NULL;
}

void check_buf_options (buf_T *buf) {
    check_string_option (& buf -> b_p_bh);
    check_string_option (& buf -> b_p_bt);
    check_string_option (& buf -> b_p_ff);
    check_string_option (& buf -> b_p_def);
    check_string_option (& buf -> b_p_inc);
    check_string_option (& buf -> b_p_inex);
    check_string_option (& buf -> b_p_inde);
    check_string_option (& buf -> b_p_indk);
    check_string_option (& buf -> b_p_bexpr);
    check_string_option (& buf -> b_p_cm);
    check_string_option (& buf -> b_p_fp);
    check_string_option (& buf -> b_p_fex);
    check_string_option (& buf -> b_p_key);
    check_string_option (& buf -> b_p_kp);
    check_string_option (& buf -> b_p_mps);
    check_string_option (& buf -> b_p_fo);
    check_string_option (& buf -> b_p_flp);
    check_string_option (& buf -> b_p_isk);
    check_string_option (& buf -> b_p_com);
    check_string_option (& buf -> b_p_cms);
    check_string_option (& buf -> b_p_nf);
    check_string_option (& buf -> b_p_qe);
    check_string_option (& buf -> b_p_syn);
    check_string_option (& buf -> b_s.b_syn_isk);
    check_string_option (& buf -> b_s.b_p_spc);
    check_string_option (& buf -> b_s.b_p_spf);
    check_string_option (& buf -> b_s.b_p_spl);
    check_string_option (& buf -> b_p_sua);
    check_string_option (& buf -> b_p_cink);
    check_string_option (& buf -> b_p_cino);
    parse_cino (buf);
    check_string_option (& buf -> b_p_ft);
    check_string_option (& buf -> b_p_cinw);
    check_string_option (& buf -> b_p_cpt);
    check_string_option (& buf -> b_p_keymap);
    check_string_option (& buf -> b_p_gp);
    check_string_option (& buf -> b_p_mp);
    check_string_option (& buf -> b_p_efm);
    check_string_option (& buf -> b_p_ep);
    check_string_option (& buf -> b_p_path);
    check_string_option (& buf -> b_p_tags);
    check_string_option (& buf -> b_p_tc);
    check_string_option (& buf -> b_p_dict);
    check_string_option (& buf -> b_p_tsr);
    check_string_option (& buf -> b_p_lw);
    check_string_option (& buf -> b_p_bkc);
}

long  get_sw_value (buf_T *buf) {
    return buf->b_p_sw ? buf->b_p_sw : buf->b_p_ts;
}

void comp_col (void) {
    int last_has_status = (p_ls == 2 || (p_ls == 1 && !ONE_WINDOW));
    sc_col = 0;
    ru_col = 0;
    if (p_ru) {
        ru_col = (ru_wid ? ru_wid : COL_RULER) + 1;
        if (!last_has_status)
            sc_col = ru_col;
    }
    if (p_sc) {
        sc_col += SHOWCMD_COLS;
        if (!p_ru || last_has_status)
            ++sc_col;
    }
    sc_col = Columns - sc_col;
    ru_col = Columns - ru_col;
    if (sc_col <= 0)
        sc_col = 1;
    if (ru_col <= 0)
        ru_col = 1;
}

void save_file_ff (buf_T *buf) {
    buf->b_start_ffc = *buf->b_p_ff;
    buf->b_start_eol = buf->b_p_eol;
}

void win_copy_options (win_T *wp_from, win_T *wp_to) {
    copy_winopt (& wp_from -> w_onebuf_opt, & wp_to -> w_onebuf_opt);
    copy_winopt (& wp_from -> w_allbuf_opt, & wp_to -> w_allbuf_opt);
    wp_to->w_farsi = wp_from->w_farsi;
    briopt_check (wp_to);
}

static int briopt_check (win_T *wp) {
    char_u *p;
    int bri_shift = 0;
    long  bri_min = 20;
    int bri_sbr = FALSE;
    p = wp->w_p_briopt;
    while (*p != NUL) {
        if (STRNCMP (p, "shift:", 6) == 0 && ((p[6] == '-' && VIM_ISDIGIT (p[7])) || VIM_ISDIGIT (p[6]))) {
            p += 6;
            bri_shift = getdigits (&p);
        }
        else if (STRNCMP (p, "min:", 4) == 0 && VIM_ISDIGIT (p[4])) {
            p += 4;
            bri_min = getdigits (&p);
        }
        else if (STRNCMP (p, "sbr", 3) == 0) {
            p += 3;
            bri_sbr = TRUE;
        }
        if (*p != ',' && *p != NUL)
            return FAIL;
        if (*p == ',')
            ++p;
    }
    wp->w_p_brishift = bri_shift;
    wp->w_p_brimin = bri_min;
    wp->w_p_brisbr = bri_sbr;
    return OK;
}

char_u *check_colorcolumn (win_T *wp) {
    char_u *s;
    int col;
    int count = 0;
    int color_cols [256];
    int i;
    int j = 0;
    if (wp->w_buffer == NULL)
        return NULL;
    for (s = wp->w_p_cc; *s != NUL && count < 255;) {
        if (*s == '-' || *s == '+') {
            col = (*s == '-') ? -1 : 1;
            ++s;
            if (!VIM_ISDIGIT (*s))
                return e_invarg;
            col = col * getdigits (&s);
            if (wp->w_buffer->b_p_tw == 0)
                goto skip;
            col += wp->w_buffer->b_p_tw;
            if (col < 0)
                goto skip;
        }
        else if (VIM_ISDIGIT (*s))
            col = getdigits (&s);
        else
            return e_invarg;
        color_cols[count++] = col - 1;
    skip :
        if (*s == NUL)
            break;
        if (*s != ',')
            return e_invarg;
        if (*++s == NUL)
            return e_invarg;
    }
    vim_free (wp -> w_p_cc_cols);
    if (count == 0)
        wp->w_p_cc_cols = NULL;
    else {
        wp->w_p_cc_cols = (int *) alloc ((unsigned ) sizeof (int) * (count + 1));
        if (wp->w_p_cc_cols != NULL) {
            qsort (color_cols, count, sizeof (int), int_cmp);
            for (i = 0; i < count; ++i)
                if (j == 0 || wp->w_p_cc_cols[j - 1] != color_cols[i])
                    wp->w_p_cc_cols[j++] = color_cols[i];
            wp->w_p_cc_cols[j] = -1;
        }
    }
    return NULL;
}

static int int_cmp (const void *a, const void *b) {
    return *(constint*) a - *(constint*) b;
}

char_u *find_viminfo_parameter (int type) {
    char_u *p;
    for (p = p_viminfo; *p; ++p) {
        if (*p == type)
            return p + 1;
        if (*p == 'n')
            break;
        p = vim_strchr (p, ',');
        if (p == NULL)
            break;
    }
    return NULL;
}

int get_viminfo_parameter (int type) {
    char_u *p;
    p = find_viminfo_parameter (type);
    if (p != NULL && VIM_ISDIGIT (*p))
        return atoi ((char *) p);
    return -1;
}

char_u *set_option_value (char_u *name, long  number, char_u *string, int opt_flags) {
    int opt_idx;
    char_u *varp;
    long_u flags;
    opt_idx = findoption (name);
    if (opt_idx < 0) {
        int key;
        if (STRLEN (name) == 4 && name[0] == 't' && name[1] == '_' && (key = find_key_option (name)) != 0) {
            char_u key_name [2];
            if (key < 0) {
                key_name[0] = KEY2TERMCAP0 (key);
                key_name[1] = KEY2TERMCAP1 (key);
            }
            else {
                key_name[0] = KS_KEY;
                key_name[1] = (key & 0xff);
            }
            add_termcode (key_name, string, FALSE);
            if (full_screen)
                ttest (FALSE);
            redraw_all_later (CLEAR);
            return NULL;
        }
        EMSG2 (_ ("E355: Unknown option: %s"), name);
    }
    else {
        flags = options[opt_idx].flags;
        if (flags & P_STRING)
            return set_string_option (opt_idx, string, opt_flags);
        else {
            varp = get_varp_scope (&(options[opt_idx]), opt_flags);
            if (varp != NULL) {
                if (number == 0 && string != NULL) {
                    int idx;
                    for (idx = 0; string[idx] == '0'; ++idx)
                        ;
                    if (string[idx] != NUL || idx == 0) {
                        EMSG3 (_ ("E521: Number required: &%s = '%s'"), name, string);
                        return NULL;
                    }
                }
                if (flags & P_NUM)
                    return set_num_option (opt_idx, varp, number, NULL, 0, opt_flags);
                else
                    return set_bool_option (opt_idx, varp, (int) number, opt_flags);
            }
        }
    }
    return NULL;
}

static int find_key_option (char_u *arg) {
    int key;
    int modifiers;
    if (arg[0] == 't' && arg[1] == '_' && arg[2] && arg[3])
        key = TERMCAP2KEY (arg[2], arg[3]);
    else {
        --arg;
        modifiers = 0;
        key = find_special_key (&arg, &modifiers, TRUE, TRUE, FALSE);
        if (modifiers)
            key = 0;
    }
    return key;
}

void check_options (void) {
    int opt_idx;
    for (opt_idx = 0; options[opt_idx].fullname != NULL; opt_idx++)
        if ((options[opt_idx].flags & P_STRING) && options[opt_idx].var != NULL)
            check_string_option ((char_u **) get_varp (&(options[opt_idx])));
}

static char_u *get_varp (struct vimoption *p) {
    if (p->var == NULL)
        return NULL;
    switch ((int) p->indir) {
    case PV_NONE :
        return p->var;
    case PV_EP :
        return *curbuf->b_p_ep != NUL ? (char_u *) &curbuf->b_p_ep : p->var;
    case PV_KP :
        return *curbuf->b_p_kp != NUL ? (char_u *) &curbuf->b_p_kp : p->var;
    case PV_PATH :
        return *curbuf->b_p_path != NUL ? (char_u *) &(curbuf->b_p_path) : p->var;
    case PV_AR :
        return curbuf->b_p_ar >= 0 ? (char_u *) &(curbuf->b_p_ar) : p->var;
    case PV_TAGS :
        return *curbuf->b_p_tags != NUL ? (char_u *) &(curbuf->b_p_tags) : p->var;
    case PV_TC :
        return *curbuf->b_p_tc != NUL ? (char_u *) &(curbuf->b_p_tc) : p->var;
    case PV_BKC :
        return *curbuf->b_p_bkc != NUL ? (char_u *) &(curbuf->b_p_bkc) : p->var;
    case PV_DEF :
        return *curbuf->b_p_def != NUL ? (char_u *) &(curbuf->b_p_def) : p->var;
    case PV_INC :
        return *curbuf->b_p_inc != NUL ? (char_u *) &(curbuf->b_p_inc) : p->var;
    case PV_DICT :
        return *curbuf->b_p_dict != NUL ? (char_u *) &(curbuf->b_p_dict) : p->var;
    case PV_TSR :
        return *curbuf->b_p_tsr != NUL ? (char_u *) &(curbuf->b_p_tsr) : p->var;
    case PV_FP :
        return *curbuf->b_p_fp != NUL ? (char_u *) &(curbuf->b_p_fp) : p->var;
    case PV_EFM :
        return *curbuf->b_p_efm != NUL ? (char_u *) &(curbuf->b_p_efm) : p->var;
    case PV_GP :
        return *curbuf->b_p_gp != NUL ? (char_u *) &(curbuf->b_p_gp) : p->var;
    case PV_MP :
        return *curbuf->b_p_mp != NUL ? (char_u *) &(curbuf->b_p_mp) : p->var;
    case PV_BEXPR :
        return *curbuf->b_p_bexpr != NUL ? (char_u *) &(curbuf->b_p_bexpr) : p->var;
    case PV_CM :
        return *curbuf->b_p_cm != NUL ? (char_u *) &(curbuf->b_p_cm) : p->var;
    case PV_STL :
        return *curwin->w_p_stl != NUL ? (char_u *) &(curwin->w_p_stl) : p->var;
    case PV_UL :
        return curbuf->b_p_ul != NO_LOCAL_UNDOLEVEL ? (char_u *) &(curbuf->b_p_ul) : p->var;
    case PV_LW :
        return *curbuf->b_p_lw != NUL ? (char_u *) &(curbuf->b_p_lw) : p->var;
    case PV_ARAB :
        return (char_u *) &(curwin->w_p_arab);
    case PV_LIST :
        return (char_u *) &(curwin->w_p_list);
    case PV_SPELL :
        return (char_u *) &(curwin->w_p_spell);
    case PV_CUC :
        return (char_u *) &(curwin->w_p_cuc);
    case PV_CUL :
        return (char_u *) &(curwin->w_p_cul);
    case PV_CC :
        return (char_u *) &(curwin->w_p_cc);
    case PV_DIFF :
        return (char_u *) &(curwin->w_p_diff);
    case PV_FDC :
        return (char_u *) &(curwin->w_p_fdc);
    case PV_FEN :
        return (char_u *) &(curwin->w_p_fen);
    case PV_FDI :
        return (char_u *) &(curwin->w_p_fdi);
    case PV_FDL :
        return (char_u *) &(curwin->w_p_fdl);
    case PV_FDM :
        return (char_u *) &(curwin->w_p_fdm);
    case PV_FML :
        return (char_u *) &(curwin->w_p_fml);
    case PV_FDN :
        return (char_u *) &(curwin->w_p_fdn);
    case PV_FDE :
        return (char_u *) &(curwin->w_p_fde);
    case PV_FDT :
        return (char_u *) &(curwin->w_p_fdt);
    case PV_FMR :
        return (char_u *) &(curwin->w_p_fmr);
    case PV_NU :
        return (char_u *) &(curwin->w_p_nu);
    case PV_RNU :
        return (char_u *) &(curwin->w_p_rnu);
    case PV_NUW :
        return (char_u *) &(curwin->w_p_nuw);
    case PV_WFH :
        return (char_u *) &(curwin->w_p_wfh);
    case PV_WFW :
        return (char_u *) &(curwin->w_p_wfw);
    case PV_PVW :
        return (char_u *) &(curwin->w_p_pvw);
    case PV_RL :
        return (char_u *) &(curwin->w_p_rl);
    case PV_RLC :
        return (char_u *) &(curwin->w_p_rlc);
    case PV_SCROLL :
        return (char_u *) &(curwin->w_p_scr);
    case PV_WRAP :
        return (char_u *) &(curwin->w_p_wrap);
    case PV_LBR :
        return (char_u *) &(curwin->w_p_lbr);
    case PV_BRI :
        return (char_u *) &(curwin->w_p_bri);
    case PV_BRIOPT :
        return (char_u *) &(curwin->w_p_briopt);
    case PV_SCBIND :
        return (char_u *) &(curwin->w_p_scb);
    case PV_CRBIND :
        return (char_u *) &(curwin->w_p_crb);
    case PV_COCU :
        return (char_u *) &(curwin->w_p_cocu);
    case PV_COLE :
        return (char_u *) &(curwin->w_p_cole);
    case PV_TK :
        return (char_u *) &(curwin->w_p_tk);
    case PV_TMS :
        return (char_u *) &(curwin->w_p_tms);
    case PV_AI :
        return (char_u *) &(curbuf->b_p_ai);
    case PV_BIN :
        return (char_u *) &(curbuf->b_p_bin);
    case PV_BH :
        return (char_u *) &(curbuf->b_p_bh);
    case PV_BT :
        return (char_u *) &(curbuf->b_p_bt);
    case PV_BL :
        return (char_u *) &(curbuf->b_p_bl);
    case PV_CI :
        return (char_u *) &(curbuf->b_p_ci);
    case PV_CIN :
        return (char_u *) &(curbuf->b_p_cin);
    case PV_CINK :
        return (char_u *) &(curbuf->b_p_cink);
    case PV_CINO :
        return (char_u *) &(curbuf->b_p_cino);
    case PV_CINW :
        return (char_u *) &(curbuf->b_p_cinw);
    case PV_COM :
        return (char_u *) &(curbuf->b_p_com);
    case PV_CMS :
        return (char_u *) &(curbuf->b_p_cms);
    case PV_CPT :
        return (char_u *) &(curbuf->b_p_cpt);
    case PV_EOL :
        return (char_u *) &(curbuf->b_p_eol);
    case PV_FIXEOL :
        return (char_u *) &(curbuf->b_p_fixeol);
    case PV_ET :
        return (char_u *) &(curbuf->b_p_et);
    case PV_FF :
        return (char_u *) &(curbuf->b_p_ff);
    case PV_FT :
        return (char_u *) &(curbuf->b_p_ft);
    case PV_FO :
        return (char_u *) &(curbuf->b_p_fo);
    case PV_FLP :
        return (char_u *) &(curbuf->b_p_flp);
    case PV_IMI :
        return (char_u *) &(curbuf->b_p_iminsert);
    case PV_IMS :
        return (char_u *) &(curbuf->b_p_imsearch);
    case PV_INF :
        return (char_u *) &(curbuf->b_p_inf);
    case PV_ISK :
        return (char_u *) &(curbuf->b_p_isk);
    case PV_INEX :
        return (char_u *) &(curbuf->b_p_inex);
    case PV_INDE :
        return (char_u *) &(curbuf->b_p_inde);
    case PV_INDK :
        return (char_u *) &(curbuf->b_p_indk);
    case PV_FEX :
        return (char_u *) &(curbuf->b_p_fex);
    case PV_KEY :
        return (char_u *) &(curbuf->b_p_key);
    case PV_LISP :
        return (char_u *) &(curbuf->b_p_lisp);
    case PV_ML :
        return (char_u *) &(curbuf->b_p_ml);
    case PV_MPS :
        return (char_u *) &(curbuf->b_p_mps);
    case PV_MMTA :
        return (char_u *) &(curbuf->b_p_mmta);
    case PV_MA :
        return (char_u *) &(curbuf->b_p_ma);
    case PV_MOD :
        return (char_u *) &(curbuf->b_changed);
    case PV_NF :
        return (char_u *) &(curbuf->b_p_nf);
    case PV_PI :
        return (char_u *) &(curbuf->b_p_pi);
    case PV_QE :
        return (char_u *) &(curbuf->b_p_qe);
    case PV_RO :
        return (char_u *) &(curbuf->b_p_ro);
    case PV_SI :
        return (char_u *) &(curbuf->b_p_si);
    case PV_SN :
        return (char_u *) &(curbuf->b_p_sn);
    case PV_STS :
        return (char_u *) &(curbuf->b_p_sts);
    case PV_SUA :
        return (char_u *) &(curbuf->b_p_sua);
    case PV_SWF :
        return (char_u *) &(curbuf->b_p_swf);
    case PV_SMC :
        return (char_u *) &(curbuf->b_p_smc);
    case PV_SYN :
        return (char_u *) &(curbuf->b_p_syn);
    case PV_SPC :
        return (char_u *) &(curwin->w_s->b_p_spc);
    case PV_SPF :
        return (char_u *) &(curwin->w_s->b_p_spf);
    case PV_SPL :
        return (char_u *) &(curwin->w_s->b_p_spl);
    case PV_SW :
        return (char_u *) &(curbuf->b_p_sw);
    case PV_TS :
        return (char_u *) &(curbuf->b_p_ts);
    case PV_TW :
        return (char_u *) &(curbuf->b_p_tw);
    case PV_TX :
        return (char_u *) &(curbuf->b_p_tx);
    case PV_UDF :
        return (char_u *) &(curbuf->b_p_udf);
    case PV_WM :
        return (char_u *) &(curbuf->b_p_wm);
    case PV_KMAP :
        return (char_u *) &(curbuf->b_p_keymap);
    case PV_SCL :
        return (char_u *) &(curwin->w_p_scl);
    default :
        IEMSG (_ ("E356: get_varp ERROR"));
    }
    return (char_u *) &(curbuf->b_p_wm);
}

void free_one_termoption (char_u *var) {
    struct vimoption *p;
    for (p = &options[0]; p->fullname != NULL; p++)
        if (p->var == var) {
            if (p->flags & P_ALLOCED)
                free_string_option (*(char_u**) (p->var));
            *(char_u**) (p->var) = empty_option;
            p->flags &= ~P_ALLOCED;
            break;
        }
}

void set_string_option_direct (char_u *name, int opt_idx, char_u *val, int opt_flags, int set_sid) {
    char_u *s;
    char_u **varp;
    int both = (opt_flags & (OPT_LOCAL | OPT_GLOBAL)) == 0;
    int idx = opt_idx;
    if (idx == -1) {
        idx = findoption (name);
        if (idx < 0) {
            EMSG2 (_ (e_intern2), "set_string_option_direct()");
            IEMSG2 (_ ("For option %s"), name);
            return;
        }
    }
    if (options[idx].var == NULL)
        return;
    s = vim_strsave (val);
    if (s != NULL) {
        varp = (char_u **) get_varp_scope (&(options[idx]), both ? OPT_LOCAL : opt_flags);
        if ((opt_flags & OPT_FREE) && (options[idx].flags & P_ALLOCED))
            free_string_option (*varp);
        *varp = s;
        if (both)
            set_string_option_global (idx, varp);
        options[idx].flags |= P_ALLOCED;
        if (((int) options[idx].indir & PV_BOTH) && both) {
            free_string_option (*varp);
            *varp = empty_option;
        }
        if (set_sid != SID_NONE)
            set_option_scriptID_idx (idx, opt_flags, set_sid == 0 ? current_SID : set_sid);
    }
}

static char_u *get_varp_scope (struct vimoption *p, int opt_flags) {
    if ((opt_flags & OPT_GLOBAL) && p->indir != PV_NONE) {
        if (p->var == VAR_WIN)
            return (char_u *) GLOBAL_WO (get_varp (p));
        return p->var;
    }
    if ((opt_flags & OPT_LOCAL) && ((int) p->indir & PV_BOTH)) {
        switch ((int) p->indir) {
        case PV_FP :
            return (char_u *) &(curbuf->b_p_fp);
        case PV_EFM :
            return (char_u *) &(curbuf->b_p_efm);
        case PV_GP :
            return (char_u *) &(curbuf->b_p_gp);
        case PV_MP :
            return (char_u *) &(curbuf->b_p_mp);
        case PV_EP :
            return (char_u *) &(curbuf->b_p_ep);
        case PV_KP :
            return (char_u *) &(curbuf->b_p_kp);
        case PV_PATH :
            return (char_u *) &(curbuf->b_p_path);
        case PV_AR :
            return (char_u *) &(curbuf->b_p_ar);
        case PV_TAGS :
            return (char_u *) &(curbuf->b_p_tags);
        case PV_TC :
            return (char_u *) &(curbuf->b_p_tc);
        case PV_DEF :
            return (char_u *) &(curbuf->b_p_def);
        case PV_INC :
            return (char_u *) &(curbuf->b_p_inc);
        case PV_DICT :
            return (char_u *) &(curbuf->b_p_dict);
        case PV_TSR :
            return (char_u *) &(curbuf->b_p_tsr);
        case PV_BEXPR :
            return (char_u *) &(curbuf->b_p_bexpr);
        case PV_CM :
            return (char_u *) &(curbuf->b_p_cm);
        case PV_STL :
            return (char_u *) &(curwin->w_p_stl);
        case PV_UL :
            return (char_u *) &(curbuf->b_p_ul);
        case PV_LW :
            return (char_u *) &(curbuf->b_p_lw);
        case PV_BKC :
            return (char_u *) &(curbuf->b_p_bkc);
        }
        return NULL;
    }
    return get_varp (p);
}

static void set_string_option_global (int opt_idx, char_u **varp) {
    char_u **p, *s;
    if (options[opt_idx].var == VAR_WIN)
        p = (char_u **) GLOBAL_WO (varp);
    else
        p = (char_u **) options[opt_idx].var;
    if (options[opt_idx].indir != PV_NONE && p != varp && (s = vim_strsave (*varp)) != NULL) {
        free_string_option (*p);
        *p = s;
    }
}

static void set_option_scriptID_idx (int opt_idx, int opt_flags, int id) {
    int both = (opt_flags & (OPT_LOCAL | OPT_GLOBAL)) == 0;
    int indir = (int) options[opt_idx].indir;
    if (both || (opt_flags & OPT_GLOBAL) || (indir & (PV_BUF | PV_WIN)) == 0)
        options[opt_idx].scriptID = id;
    if (both || (opt_flags & OPT_LOCAL)) {
        if (indir & PV_BUF)
            curbuf->b_p_scriptID[indir & PV_MASK] = id;
        else if (indir & PV_WIN)
            curwin->w_p_scriptID[indir & PV_MASK] = id;
    }
}

static char_u *set_string_option (int opt_idx, char_u *value, int opt_flags) {
    char_u *s;
    char_u **varp;
    char_u *oldval;
    char_u *saved_oldval = NULL;
    char_u *saved_newval = NULL;
    char_u *r = NULL;
    if (options[opt_idx].var == NULL)
        return NULL;
    s = vim_strsave (value);
    if (s != NULL) {
        varp = (char_u **) get_varp_scope (&(options[opt_idx]), (opt_flags & (OPT_LOCAL | OPT_GLOBAL)) == 0 ? (((int) options[opt_idx].indir & PV_BOTH) ? OPT_GLOBAL : OPT_LOCAL) : opt_flags);
        oldval = *varp;
        *varp = s;
        if (!starting && options[opt_idx].indir != PV_KEY) {
            saved_oldval = vim_strsave (oldval);
            saved_newval = vim_strsave (s);
        }
        if ((r = did_set_string_option (opt_idx, varp, TRUE, oldval, NULL, opt_flags)) == NULL)
            did_set_option (opt_idx, opt_flags, TRUE);
        if (r == NULL)
            trigger_optionsset_string (opt_idx, opt_flags, saved_oldval, saved_newval);
        vim_free (saved_oldval);
        vim_free (saved_newval);
    }
    return r;
}

static char_u *did_set_string_option (int opt_idx, char_u **varp, int new_value_alloced, char_u *oldval, char_u *errbuf, int opt_flags) {
    char_u *errmsg = NULL;
    char_u *s, *p;
    int did_chartab = FALSE;
    char_u **gvarp;
    long_u free_oldval = (options[opt_idx].flags & P_ALLOCED);
    int redraw_gui_only = FALSE;
    int ft_changed = FALSE;
    gvarp = (char_u **) get_varp_scope (&(options[opt_idx]), OPT_GLOBAL);
    if ((secure) &&(options[opt_idx].flags & P_SECURE)) {
        errmsg = e_secure;
    }
    else if (((options[opt_idx].flags & P_NFNAME) && vim_strpbrk (*varp, (char_u *) (secure ? "/\\*?[|;&<>\r\n" : "/\\*?[<>\r\n")) != NULL) || ((options[opt_idx].flags & P_NDNAME) && vim_strpbrk (*varp, (char_u *) "*?[|;&<>\r\n") != NULL)) {
        errmsg = e_invarg;
    }
    else if (varp == &T_NAME) {
        if (T_NAME[0] == NUL)
            errmsg = (char_u *) N_ ("E529: Cannot set 'term' to empty string");
        if (gui.in_use)
            errmsg = (char_u *) N_ ("E530: Cannot change term in GUI");
        else if (term_is_gui (T_NAME))
            errmsg = (char_u *) N_ ("E531: Use \":gui\" to start the GUI");
        else if (set_termname (T_NAME) == FAIL)
            errmsg = (char_u *) N_ ("E522: Not found in termcap");
        else {
            redraw_later_clear ();
            opt_idx = findoption ((char_u *) "term");
            free_oldval = (options[opt_idx].flags & P_ALLOCED);
        }
    }
    else if (gvarp == &p_bkc) {
        char_u *bkc = p_bkc;
        unsigned  int *flags = &bkc_flags;
        if (opt_flags & OPT_LOCAL) {
            bkc = curbuf->b_p_bkc;
            flags = &curbuf->b_bkc_flags;
        }
        if ((opt_flags & OPT_LOCAL) && *bkc == NUL)
            *flags = 0;
        else {
            if (opt_strings_flags (bkc, p_bkc_values, flags, TRUE) != OK)
                errmsg = e_invarg;
            if ((((int) *flags & BKC_AUTO) != 0) + (((int) *flags & BKC_YES) != 0) + (((int) *flags & BKC_NO) != 0) != 1) {
                (void) opt_strings_flags (oldval, p_bkc_values, flags, TRUE);
                errmsg = e_invarg;
            }
        }
    }
    else if (varp == &p_bex || varp == &p_pm) {
        if (STRCMP (*p_bex == '.' ? p_bex + 1 : p_bex, *p_pm == '.' ? p_pm + 1 : p_pm) == 0)
            errmsg = (char_u *) N_ ("E589: 'backupext' and 'patchmode' are equal");
    }
    else if (varp == &curwin->w_p_briopt) {
        if (briopt_check (curwin) == FAIL)
            errmsg = e_invarg;
    }
    else if (varp == &p_isi || varp == &(curbuf->b_p_isk) || varp == &p_isp || varp == &p_isf) {
        if (init_chartab () == FAIL) {
            did_chartab = TRUE;
            errmsg = e_invarg;
        }
    }
    else if (varp == &p_hf) {
        if (didset_vim) {
            vim_setenv ((char_u *) "VIM", (char_u *) "");
            didset_vim = FALSE;
        }
        if (didset_vimruntime) {
            vim_setenv ((char_u *) "VIMRUNTIME", (char_u *) "");
            didset_vimruntime = FALSE;
        }
    }
    else if (varp == &curwin->w_p_cc)
        errmsg = check_colorcolumn (curwin);
    else if (varp == &p_hlg) {
        for (s = p_hlg; *s != NUL; s += 3) {
            if (s[1] == NUL || ((s[2] != ',' || s[3] == NUL) && s[2] != NUL)) {
                errmsg = e_invarg;
                break;
            }
            if (s[2] == NUL)
                break;
        }
    }
    else if (varp == &p_hl) {
        if (highlight_changed () == FAIL)
            errmsg = e_invarg;
    }
    else if (gvarp == &p_nf) {
        if (check_opt_strings (*varp, p_nf_values, TRUE) != OK)
            errmsg = e_invarg;
    }
    else if (varp == &p_ssop) {
        if (opt_strings_flags (p_ssop, p_ssop_values, &ssop_flags, TRUE) != OK)
            errmsg = e_invarg;
        if ((ssop_flags & SSOP_CURDIR) && (ssop_flags & SSOP_SESDIR)) {
            (void) opt_strings_flags (oldval, p_ssop_values, &ssop_flags, TRUE);
            errmsg = e_invarg;
        }
    }
    else if (varp == &p_vop) {
        if (opt_strings_flags (p_vop, p_ssop_values, &vop_flags, TRUE) != OK)
            errmsg = e_invarg;
    }
    else if (varp == &p_sbo) {
        if (check_opt_strings (p_sbo, p_scbopt_values, TRUE) != OK)
            errmsg = e_invarg;
    }
    else if (varp == &p_bg) {
        if (check_opt_strings (p_bg, p_bg_values, FALSE) == OK) {
            int dark = (*p_bg == 'd');
            init_highlight (FALSE, FALSE);
            if (dark != (*p_bg == 'd') && get_var_value ((char_u *) "g:colors_name") != NULL) {
                do_unlet ((char_u *) "g:colors_name", TRUE);
                free_string_option (p_bg);
                p_bg = vim_strsave ((char_u *) (dark ? "dark" : "light"));
                check_string_option (& p_bg);
                init_highlight (FALSE, FALSE);
            }
        }
        else
            errmsg = e_invarg;
    }
    else if (varp == &p_wim) {
        if (check_opt_wim () == FAIL)
            errmsg = e_invarg;
    }
    else if (varp == &p_wop) {
        if (check_opt_strings (p_wop, p_wop_values, TRUE) != OK)
            errmsg = e_invarg;
    }
    else if (varp == &p_ei) {
        if (check_ei () == FAIL)
            errmsg = e_invarg;
    }
    else if (varp == &p_penc) {
        p = enc_canonize (p_penc);
        if (p != NULL) {
            vim_free (p_penc);
            p_penc = p;
        }
        else {
            for (s = p_penc; *s != NUL; s++) {
                if (*s == '_')
                    *s = '-';
                else
                    *s = TOLOWER_ASC (*s);
            }
        }
    }
    else if (varp == &curbuf->b_p_keymap) {
        if (!valid_filetype (*varp))
            errmsg = e_invarg;
        else
            errmsg = keymap_init ();
        if (errmsg == NULL) {
            if (*curbuf->b_p_keymap != NUL) {
                curbuf->b_p_iminsert = B_IMODE_LMAP;
                if (curbuf->b_p_imsearch != B_IMODE_USE_INSERT)
                    curbuf->b_p_imsearch = B_IMODE_LMAP;
            }
            else {
                if (curbuf->b_p_iminsert == B_IMODE_LMAP)
                    curbuf->b_p_iminsert = B_IMODE_NONE;
                if (curbuf->b_p_imsearch == B_IMODE_LMAP)
                    curbuf->b_p_imsearch = B_IMODE_USE_INSERT;
            }
            if ((opt_flags & OPT_LOCAL) == 0) {
                set_iminsert_global ();
                set_imsearch_global ();
            }
            status_redraw_curbuf ();
        }
    }
    else if (gvarp == &p_ff) {
        if (!curbuf->b_p_ma && !(opt_flags & OPT_GLOBAL))
            errmsg = e_modifiable;
        else if (check_opt_strings (*varp, p_ff_values, FALSE) != OK)
            errmsg = e_invarg;
        else {
            if (get_fileformat (curbuf) == EOL_DOS)
                curbuf->b_p_tx = TRUE;
            else
                curbuf->b_p_tx = FALSE;
            redraw_titles ();
            ml_setflags (curbuf);
            if (get_fileformat (curbuf) == EOL_MAC || *oldval == 'm')
                redraw_curbuf_later (NOT_VALID);
        }
    }
    else if (varp == &p_ffs) {
        if (check_opt_strings (p_ffs, p_ff_values, TRUE) != OK)
            errmsg = e_invarg;
        else {
            if (*p_ffs == NUL)
                p_ta = FALSE;
            else
                p_ta = TRUE;
        }
    }
    else if (gvarp == &p_key) {
        if (STRCMP (curbuf->b_p_key, oldval) != 0)
            ml_set_crypt_key (curbuf, oldval, *curbuf->b_p_cm == NUL ? p_cm : curbuf->b_p_cm);
    }
    else if (gvarp == &p_cm) {
        if (opt_flags & OPT_LOCAL)
            p = curbuf->b_p_cm;
        else
            p = p_cm;
        if (check_opt_strings (p, p_cm_values, TRUE) != OK)
            errmsg = e_invarg;
        else if (crypt_self_test () == FAIL)
            errmsg = e_invarg;
        else {
            if (*p_cm == NUL) {
                if (new_value_alloced)
                    free_string_option (p_cm);
                p_cm = vim_strsave ((char_u *) "zip");
                new_value_alloced = TRUE;
            }
            if ((opt_flags & (OPT_LOCAL | OPT_GLOBAL)) == 0) {
                free_string_option (curbuf -> b_p_cm);
                curbuf->b_p_cm = empty_option;
            }
            if ((opt_flags & OPT_LOCAL) && *oldval == NUL)
                s = p_cm;
            else
                s = oldval;
            if (*curbuf->b_p_cm == NUL)
                p = p_cm;
            else
                p = curbuf->b_p_cm;
            if (STRCMP (s, p) != 0)
                ml_set_crypt_key (curbuf, curbuf->b_p_key, s);
            if ((opt_flags & OPT_GLOBAL) && STRCMP (p_cm, oldval) != 0) {
                buf_T *buf;
                FOR_ALL_BUFFERS (buf)
                    if (buf != curbuf && *buf->b_p_cm == NUL)
                        ml_set_crypt_key (buf, buf->b_p_key, oldval);
            }
        }
    }
    else if (gvarp == &p_mps) {
        {
            for (p = *varp; *p != NUL; p += 4) {
                if (p[1] != ':' || p[2] == NUL || (p[3] != NUL && p[3] != ',')) {
                    errmsg = e_invarg;
                    break;
                }
                if (p[3] == NUL)
                    break;
            }
        }
    }
    else if (gvarp == &p_com) {
        for (s = *varp; *s;) {
            while (*s && *s != ':') {
                if (vim_strchr ((char_u *) COM_ALL, *s) == NULL && !VIM_ISDIGIT (*s) && *s != '-') {
                    errmsg = illegal_char (errbuf, *s);
                    break;
                }
                ++s;
            }
            if (*s++ == NUL)
                errmsg = (char_u *) N_ ("E524: Missing colon");
            else if (*s == ',' || *s == NUL)
                errmsg = (char_u *) N_ ("E525: Zero length string");
            if (errmsg != NULL)
                break;
            while (*s && *s != ',') {
                if (*s == '\\' && s[1] != NUL)
                    ++s;
                ++s;
            }
            s = skip_to_option_part (s);
        }
    }
    else if (varp == &p_lcs) {
        errmsg = set_chars_option (varp);
    }
    else if (varp == &p_fcs) {
        errmsg = set_chars_option (varp);
    }
    else if (varp == &p_vfile) {
        verbose_stop ();
        if (*p_vfile != NUL && verbose_open () == FAIL)
            errmsg = e_invarg;
    }
    else if (varp == &p_viminfo) {
        for (s = p_viminfo; *s;) {
            if (vim_strchr ((char_u *) "!\"%'/:<@cfhnrs", *s) == NULL) {
                errmsg = illegal_char (errbuf, *s);
                break;
            }
            if (*s == 'n') {
                break;
            }
            else if (*s == 'r') {
                while (*++s && *s != ',')
                    ;
            }
            else if (*s == '%') {
                while (vim_isdigit (*++s))
                    ;
            }
            else if (*s == '!' || *s == 'h' || *s == 'c')
                ++s;
            else {
                while (vim_isdigit (*++s))
                    ;
                if (!VIM_ISDIGIT (*(s - 1))) {
                    if (errbuf != NULL) {
                        sprintf ((char *) errbuf, _ ("E526: Missing number after <%s>"), transchar_byte (* (s - 1)));
                        errmsg = errbuf;
                    }
                    else
                        errmsg = (char_u *) "";
                    break;
                }
            }
            if (*s == ',')
                ++s;
            else if (*s) {
                if (errbuf != NULL)
                    errmsg = (char_u *) N_ ("E527: Missing comma");
                else
                    errmsg = (char_u *) "";
                break;
            }
        }
        if (*p_viminfo && errmsg == NULL && get_viminfo_parameter ('\'') < 0)
            errmsg = (char_u *) N_ ("E528: Must specify a ' value");
    }
    else if (istermoption (&options[opt_idx]) && full_screen) {
        if (varp == &T_CCO) {
            int colors = atoi ((char *) T_CCO);
            if (colors != t_colors) {
                t_colors = colors;
                if (t_colors <= 1) {
                    if (new_value_alloced)
                        vim_free (T_CCO);
                    T_CCO = empty_option;
                }
                init_highlight (TRUE, FALSE);
            }
        }
        ttest (FALSE);
        if (varp == &T_ME) {
            out_str (T_ME);
            redraw_later (CLEAR);
        }
        if (varp == &T_BE && termcap_active) {
            if (*T_BE == NUL)
                out_str (T_BD);
            else
                out_str (T_BE);
        }
    }
    else if (varp == &p_sbr) {
        for (s = p_sbr; *s;) {
            if (ptr2cells (s) != 1)
                errmsg = (char_u *) N_ ("E595: contains unprintable or wide character");
            MB_PTR_ADV (s);
        }
    }
    else if (varp == &p_guifont) {
        if (gui.in_use) {
            p = p_guifont;
            if (p != NULL && gui_init_font (p_guifont, FALSE) != OK) {
                if (STRCMP (p_guifont, "*") == 0) {
                    if (new_value_alloced)
                        free_string_option (p_guifont);
                    p_guifont = vim_strsave (oldval);
                    new_value_alloced = TRUE;
                }
                else
                    errmsg = (char_u *) N_ ("E596: Invalid font(s)");
            }
        }
        redraw_gui_only = TRUE;
    }
    else if (varp == &p_mouseshape) {
        errmsg = parse_shape_opt (SHAPE_MOUSE);
        update_mouseshape (- 1);
    }
    else if (varp == &p_popt)
        errmsg = parse_printoptions ();
    else if (varp == &p_langmap)
        langmap_set ();
    else if (varp == &p_breakat)
        fill_breakat_flags ();
    else if (varp == &p_titlestring || varp == &p_iconstring) {
        int flagval = (varp == &p_titlestring) ? STL_IN_TITLE : STL_IN_ICON;
        if (vim_strchr (*varp, '%') && check_stl_option (*varp) == NULL)
            stl_syntax |= flagval;
        else
            stl_syntax &= ~flagval;
        did_set_title (varp == & p_iconstring);
    }
    else if (varp == &p_go) {
        gui_init_which_components (oldval);
        redraw_gui_only = TRUE;
    }
    else if (varp == &p_sel) {
        if (*p_sel == NUL || check_opt_strings (p_sel, p_sel_values, FALSE) != OK)
            errmsg = e_invarg;
    }
    else if (varp == &p_slm) {
        if (check_opt_strings (p_slm, p_slm_values, TRUE) != OK)
            errmsg = e_invarg;
    }
    else if (varp == &p_km) {
        if (check_opt_strings (p_km, p_km_values, TRUE) != OK)
            errmsg = e_invarg;
        else {
            km_stopsel = (vim_strchr (p_km, 'o') != NULL);
            km_startsel = (vim_strchr (p_km, 'a') != NULL);
        }
    }
    else if (varp == &p_mousem) {
        if (check_opt_strings (p_mousem, p_mousem_values, FALSE) != OK)
            errmsg = e_invarg;
    }
    else if (varp == &p_swb) {
        if (opt_strings_flags (p_swb, p_swb_values, &swb_flags, TRUE) != OK)
            errmsg = e_invarg;
    }
    else if (varp == &p_debug) {
        if (check_opt_strings (p_debug, p_debug_values, TRUE) != OK)
            errmsg = e_invarg;
    }
    else if (varp == &p_dy) {
        if (opt_strings_flags (p_dy, p_dy_values, &dy_flags, TRUE) != OK)
            errmsg = e_invarg;
        else
            (void) init_chartab ();
    }
    else if (varp == &p_ead) {
        if (check_opt_strings (p_ead, p_ead_values, FALSE) != OK)
            errmsg = e_invarg;
    }
    else if (varp == &(curwin->w_s->b_p_spl) || varp == &(curwin->w_s->b_p_spf)) {
        errmsg = did_set_spell_option (varp == &(curwin->w_s->b_p_spf));
    }
    else if (varp == &(curwin->w_s->b_p_spc)) {
        errmsg = compile_cap_prog (curwin->w_s);
    }
    else if (varp == &p_sps) {
        if (spell_check_sps () != OK)
            errmsg = e_invarg;
    }
    else if (varp == &p_msm) {
        if (spell_check_msm () != OK)
            errmsg = e_invarg;
    }
    else if (gvarp == &p_bh) {
        if (check_opt_strings (curbuf->b_p_bh, p_bufhidden_values, FALSE) != OK)
            errmsg = e_invarg;
    }
    else if (gvarp == &p_bt) {
        if (check_opt_strings (curbuf->b_p_bt, p_buftype_values, FALSE) != OK)
            errmsg = e_invarg;
        else {
            if (curwin->w_status_height) {
                curwin->w_redr_status = TRUE;
                redraw_later (VALID);
            }
            curbuf->b_help = (curbuf->b_p_bt[0] == 'h');
            redraw_titles ();
        }
    }
    else if (gvarp == &p_stl || varp == &p_ruf) {
        int wid;
        if (varp == &p_ruf)
            ru_wid = 0;
        s = *varp;
        if (varp == &p_ruf && *s == '%') {
            if (*++s == '-')
                s++;
            wid = getdigits (&s);
            if (wid && *s == '(' && (errmsg = check_stl_option (p_ruf)) == NULL)
                ru_wid = wid;
            else
                errmsg = check_stl_option (p_ruf);
        }
        else if (varp == &p_ruf || s[0] != '%' || s[1] != '!')
            errmsg = check_stl_option (s);
        if (varp == &p_ruf && errmsg == NULL)
            comp_col ();
    }
    else if (gvarp == &p_cpt) {
        for (s = *varp; *s;) {
            while (*s == ',' || *s == ' ')
                s++;
            if (!*s)
                break;
            if (vim_strchr ((char_u *) ".wbuksid]tU", *s) == NULL) {
                errmsg = illegal_char (errbuf, *s);
                break;
            }
            if (*++s != NUL && *s != ',' && *s != ' ') {
                if (s[-1] == 'k' || s[-1] == 's') {
                    while (*s && *s != ',' && *s != ' ') {
                        if (*s == '\\' && s[1] != NUL)
                            ++s;
                        ++s;
                    }
                }
                else {
                    if (errbuf != NULL) {
                        sprintf ((char *) errbuf, _ ("E535: Illegal character after <%c>"), * -- s);
                        errmsg = errbuf;
                    }
                    else
                        errmsg = (char_u *) "";
                    break;
                }
            }
        }
    }
    else if (varp == &p_cot) {
        if (check_opt_strings (p_cot, p_cot_values, TRUE) != OK)
            errmsg = e_invarg;
        else
            completeopt_was_set ();
    }
    else if (varp == &curwin->w_p_scl) {
        if (check_opt_strings (*varp, p_scl_values, FALSE) != OK)
            errmsg = e_invarg;
    }
    else if (varp == &p_toolbar) {
        if (opt_strings_flags (p_toolbar, p_toolbar_values, &toolbar_flags, TRUE) != OK)
            errmsg = e_invarg;
        else {
            out_flush ();
            gui_mch_show_toolbar ((toolbar_flags & (TOOLBAR_TEXT | TOOLBAR_ICONS)) != 0);
        }
    }
    else if (varp == &p_tbis) {
        if (opt_strings_flags (p_tbis, p_tbis_values, &tbis_flags, FALSE) != OK)
            errmsg = e_invarg;
        else {
            out_flush ();
            gui_mch_show_toolbar ((toolbar_flags & (TOOLBAR_TEXT | TOOLBAR_ICONS)) != 0);
        }
    }
    else if (varp == &p_pt) {
        if (*p_pt) {
            (void) replace_termcodes (p_pt, &p, TRUE, TRUE, FALSE);
            if (p != NULL) {
                if (new_value_alloced)
                    free_string_option (p_pt);
                p_pt = p;
                new_value_alloced = TRUE;
            }
        }
    }
    else if (varp == &p_bs) {
        if (VIM_ISDIGIT (*p_bs)) {
            if (*p_bs > '2' || p_bs[1] != NUL)
                errmsg = e_invarg;
        }
        else if (check_opt_strings (p_bs, p_bs_values, TRUE) != OK)
            errmsg = e_invarg;
    }
    else if (varp == &p_bo) {
        if (opt_strings_flags (p_bo, p_bo_values, &bo_flags, TRUE) != OK)
            errmsg = e_invarg;
    }
    else if (gvarp == &p_tc) {
        unsigned  int *flags;
        if (opt_flags & OPT_LOCAL) {
            p = curbuf->b_p_tc;
            flags = &curbuf->b_tc_flags;
        }
        else {
            p = p_tc;
            flags = &tc_flags;
        }
        if ((opt_flags & OPT_LOCAL) && *p == NUL)
            *flags = 0;
        else if (*p == NUL || opt_strings_flags (p, p_tc_values, flags, FALSE) != OK)
            errmsg = e_invarg;
    }
    else if (varp == &p_dip) {
        if (diffopt_changed () == FAIL)
            errmsg = e_invarg;
    }
    else if (gvarp == &curwin->w_allbuf_opt.wo_fdm) {
        if (check_opt_strings (*varp, p_fdm_values, FALSE) != OK || *curwin->w_p_fdm == NUL)
            errmsg = e_invarg;
        else {
            foldUpdateAll (curwin);
            if (foldmethodIsDiff (curwin))
                newFoldLevel ();
        }
    }
    else if (varp == &curwin->w_p_fde) {
        if (foldmethodIsExpr (curwin))
            foldUpdateAll (curwin);
    }
    else if (gvarp == &curwin->w_allbuf_opt.wo_fmr) {
        p = vim_strchr (*varp, ',');
        if (p == NULL)
            errmsg = (char_u *) N_ ("E536: comma required");
        else if (p == *varp || p[1] == NUL)
            errmsg = e_invarg;
        else if (foldmethodIsMarker (curwin))
            foldUpdateAll (curwin);
    }
    else if (gvarp == &p_cms) {
        if (**varp != NUL && strstr ((char *) *varp, "%s") == NULL)
            errmsg = (char_u *) N_ ("E537: 'commentstring' must be empty or contain %s");
    }
    else if (varp == &p_fdo) {
        if (opt_strings_flags (p_fdo, p_fdo_values, &fdo_flags, TRUE) != OK)
            errmsg = e_invarg;
    }
    else if (varp == &p_fcl) {
        if (check_opt_strings (p_fcl, p_fcl_values, TRUE) != OK)
            errmsg = e_invarg;
    }
    else if (gvarp == &curwin->w_allbuf_opt.wo_fdi) {
        if (foldmethodIsIndent (curwin))
            foldUpdateAll (curwin);
    }
    else if (varp == &p_fuoptions) {
        if (check_fuoptions (p_fuoptions, &fuoptions_flags, &fuoptions_bgcolor) != OK)
            errmsg = e_invarg;
    }
    else if (varp == &p_ve) {
        if (opt_strings_flags (p_ve, p_ve_values, &ve_flags, TRUE) != OK)
            errmsg = e_invarg;
        else if (STRCMP (p_ve, oldval) != 0) {
            validate_virtcol ();
            coladvance (curwin -> w_virtcol);
        }
    }
    else if (gvarp == &p_cino) {
        parse_cino (curbuf);
    }
    else if (gvarp == &p_ft) {
        if (!valid_filetype (*varp))
            errmsg = e_invarg;
        else
            ft_changed = STRCMP (oldval, *varp) != 0;
    }
    else if (gvarp == &p_syn) {
        if (!valid_filetype (*varp))
            errmsg = e_invarg;
    }
    else if (varp == &curwin->w_p_tk) {
        if (*curwin->w_p_tk != NUL && string_to_key (curwin->w_p_tk, TRUE) == 0)
            errmsg = e_invarg;
    }
    else if (varp == &curwin->w_p_tms) {
        if (*curwin->w_p_tms != NUL) {
            p = skipdigits (curwin->w_p_tms);
            if (p == curwin->w_p_tms || *p != 'x' || *skipdigits (p +1) != NUL)
                errmsg = e_invarg;
        }
    }
    else {
        p = NULL;
        if (varp == &p_ww)
            p = (char_u *) WW_ALL;
        if (varp == &p_shm)
            p = (char_u *) SHM_ALL;
        else if (varp == &(p_cpo))
            p = (char_u *) CPO_ALL;
        else if (varp == &(curbuf->b_p_fo))
            p = (char_u *) FO_ALL;
        else if (varp == &curwin->w_p_cocu)
            p = (char_u *) COCU_ALL;
        else if (varp == &p_mouse) {
            p = (char_u *) MOUSE_ALL;
        }
        else if (varp == &p_go)
            p = (char_u *) GO_ALL;
        if (p != NULL) {
            for (s = *varp; *s; ++s)
                if (vim_strchr (p, *s) == NULL) {
                    errmsg = illegal_char (errbuf, *s);
                    break;
                }
        }
    }
    if (errmsg != NULL) {
        if (new_value_alloced)
            free_string_option (*varp);
        *varp = oldval;
        if (did_chartab)
            (void) init_chartab ();
        if (varp == &p_hl)
            (void) highlight_changed ();
    }
    else {
        set_option_scriptID_idx (opt_idx, opt_flags, current_SID);
        if (free_oldval)
            free_string_option (oldval);
        if (new_value_alloced)
            options[opt_idx].flags |= P_ALLOCED;
        else
            options[opt_idx].flags &= ~P_ALLOCED;
        if ((opt_flags & (OPT_LOCAL | OPT_GLOBAL)) == 0 && ((int) options[opt_idx].indir & PV_BOTH)) {
            p = get_varp_scope (&(options[opt_idx]), OPT_LOCAL);
            free_string_option (* (char_u * *) p);
            *(char_u**) p = empty_option;
        }
        else if (!(opt_flags & OPT_LOCAL) && opt_flags != OPT_GLOBAL)
            set_string_option_global (opt_idx, varp);
        if (varp == &(curbuf->b_p_syn)) {
            apply_autocmds (EVENT_SYNTAX, curbuf -> b_p_syn, curbuf -> b_fname, TRUE, curbuf);
        }
        else if (varp == &(curbuf->b_p_ft)) {
            if (!(opt_flags & OPT_MODELINE) || ft_changed) {
                did_filetype = TRUE;
                apply_autocmds (EVENT_FILETYPE, curbuf -> b_p_ft, curbuf -> b_fname, TRUE, curbuf);
                if (varp != &(curbuf->b_p_ft))
                    varp = NULL;
            }
        }
        if (varp == &(curwin->w_s->b_p_spl)) {
            char_u fname [200];
            char_u *q = curwin->w_s->b_p_spl;
            if (STRNCMP (q, "cjk,", 4) == 0)
                q += 4;
            for (p = q; *p != NUL; ++p)
                if (vim_strchr ((char_u *) "_.,", *p) != NULL)
                    break;
            vim_snprintf ((char *) fname, 200, "spell/%.*s.vim", (int) (p - q), q);
            source_runtime (fname, DIP_ALL);
        }
    }
    if (varp == &p_mouse) {
        setmouse ();
    }
    if (curwin->w_curswant != MAXCOL && (options[opt_idx].flags & (P_CURSWANT | P_RALL)) != 0)
        curwin->w_set_curswant = TRUE;
    if (!redraw_gui_only || gui.in_use)
        check_redraw (options[opt_idx].flags);
    return errmsg;
}

void clear_termoptions (void) {
    mch_restore_title (3);
    stoptermcap ();
    free_termoptions ();
}

void free_termoptions (void) {
    struct vimoption *p;
    for (p = &options[0]; p->fullname != NULL; p++)
        if (istermoption (p)) {
            if (p->flags & P_ALLOCED)
                free_string_option (*(char_u**) (p->var));
            if (p->flags & P_DEF_ALLOCED)
                free_string_option (p->def_val[VI_DEFAULT]);
            *(char_u**) (p->var) = empty_option;
            p->def_val[VI_DEFAULT] = empty_option;
            p->flags &= ~(P_ALLOCED | P_DEF_ALLOCED);
        }
    clear_termcodes ();
}

static int istermoption (struct vimoption *p) {
    return (p->fullname[0] == 't' && p->fullname[1] == '_');
}

#define COL_RULER 17	    /* columns needed by standard ruler */

void set_term_option_alloced (char_u **p) {
    int opt_idx;
    for (opt_idx = 1; options[opt_idx].fullname != NULL; opt_idx++)
        if (options[opt_idx].var == (char_u *) p) {
            options[opt_idx].flags |= P_ALLOCED;
            return;
        }
    return;
}

void vimrc_found (char_u *fname, char_u *envname) {
    int opt_idx;
    int dofree = FALSE;
    char_u *p;
    if (!option_was_set ((char_u *) "cp")) {
        p_cp = FALSE;
        for (opt_idx = 0; !istermoption (&options[opt_idx]); opt_idx++)
            if (!(options[opt_idx].flags & (P_WAS_SET | P_VI_DEF)))
                set_option_default (opt_idx, OPT_FREE, FALSE);
        didset_options ();
        didset_options2 ();
    }
    if (fname != NULL) {
        p = vim_getenv (envname, &dofree);
        if (p == NULL) {
            p = FullName_save (fname, FALSE);
            if (p != NULL) {
                vim_setenv (envname, p);
                vim_free (p);
            }
        }
        else if (dofree)
            vim_free (p);
    }
}

int option_was_set (char_u *name) {
    int idx;
    idx = findoption (name);
    if (idx < 0)
        return FALSE;
    if (options[idx].flags & P_WAS_SET)
        return TRUE;
    return FALSE;
}

static void set_option_default (int opt_idx, int opt_flags, int compatible) {
    char_u *varp;
    int dvi;
    long_u flags;
    long_u *flagsp;
    int both = (opt_flags & (OPT_LOCAL | OPT_GLOBAL)) == 0;
    varp = get_varp_scope (&(options[opt_idx]), both ? OPT_LOCAL : opt_flags);
    flags = options[opt_idx].flags;
    if (varp != NULL) {
        dvi = ((flags & P_VI_DEF) || compatible) ? VI_DEFAULT : VIM_DEFAULT;
        if (flags & P_STRING) {
            if (options[opt_idx].indir != PV_NONE)
                set_string_option_direct (NULL, opt_idx, options[opt_idx].def_val[dvi], opt_flags, 0);
            else {
                if ((opt_flags & OPT_FREE) && (flags & P_ALLOCED))
                    free_string_option (*(char_u**) (varp));
                *(char_u**) varp = options[opt_idx].def_val[dvi];
                options[opt_idx].flags &= ~P_ALLOCED;
            }
        }
        else if (flags & P_NUM) {
            if (options[opt_idx].indir == PV_SCROLL)
                win_comp_scroll (curwin);
            else {
                *(long *) varp = (long ) (long_i) options[opt_idx].def_val[dvi];
                if (both)
                    *(long *) get_varp_scope (&(options[opt_idx]), OPT_GLOBAL) = *(long *) varp;
            }
        }
        else {
            *(int*) varp = (int) (long ) (long_i) options[opt_idx].def_val[dvi];
            if (options[opt_idx].indir == PV_ML && getuid () == ROOT_UID)
                *(int*) varp = FALSE;
            if (both)
                *(int*) get_varp_scope (&(options[opt_idx]), OPT_GLOBAL) = *(int*) varp;
        }
        flagsp = insecure_flag (opt_idx, opt_flags);
        *flagsp = *flagsp & ~P_INSECURE;
    }
    set_option_scriptID_idx (opt_idx, opt_flags, current_SID);
}

static void didset_options (void) {
    (void) init_chartab ();
    (void) opt_strings_flags (p_bkc, p_bkc_values, &bkc_flags, TRUE);
    (void) opt_strings_flags (p_bo, p_bo_values, &bo_flags, TRUE);
    (void) opt_strings_flags (p_ssop, p_ssop_values, &ssop_flags, TRUE);
    (void) opt_strings_flags (p_vop, p_ssop_values, &vop_flags, TRUE);
    (void) opt_strings_flags (p_fdo, p_fdo_values, &fdo_flags, TRUE);
    (void) check_fuoptions (p_fuoptions, &fuoptions_flags, &fuoptions_bgcolor);
    (void) opt_strings_flags (p_dy, p_dy_values, &dy_flags, TRUE);
    (void) opt_strings_flags (p_tc, p_tc_values, &tc_flags, FALSE);
    (void) opt_strings_flags (p_ve, p_ve_values, &ve_flags, TRUE);
    (void) opt_strings_flags (p_ttym, p_ttym_values, &ttym_flags, FALSE);
    (void) spell_check_msm ();
    (void) spell_check_sps ();
    (void) compile_cap_prog (curwin->w_s);
    (void) did_set_spell_option (TRUE);
    (void) opt_strings_flags (p_toolbar, p_toolbar_values, &toolbar_flags, TRUE);
    (void) opt_strings_flags (p_tbis, p_tbis_values, &tbis_flags, FALSE);
    briopt_check (curwin);
    fill_breakat_flags ();
}

static int opt_strings_flags (char_u *val, char **values, unsigned  *flagp, int list) {
    int i;
    int len;
    unsigned  new_flags = 0;
    while (*val) {
        for (i = 0;; ++i) {
            if (values[i] == NULL)
                return FAIL;
            len = (int) STRLEN (values[i]);
            if (STRNCMP (values[i], val, len) == 0 && ((list && val[len] == ',') || val[len] == NUL)) {
                val += len + (val[len] == ',');
                new_flags |= (1 << i);
                break;
            }
        }
    }
    if (flagp != NULL)
        *flagp = new_flags;
    return OK;
}

static int check_fuoptions (p_fuoptions, flags, bgcolor)
    char_u *p_fuoptions;
    unsigned  *flags;
    int *bgcolor;
{
    unsigned  new_fuoptions_flags;
    int new_fuoptions_bgcolor;
    char_u *p;
    char_u hg_term;
    int i, j, k;
    new_fuoptions_flags = 0;
    new_fuoptions_bgcolor = 0xFF000000;
    for (p = p_fuoptions; *p; ++p) {
        for (i = 0; ASCII_ISALPHA (p[i]); ++i)
            ;
        if (p[i] != NUL && p[i] != ',' && p[i] != ':')
            return FAIL;
        if (i == 10 && STRNCMP (p, "background", 10) == 0) {
            if (p[i] != ':')
                return FAIL;
            i++;
            if (p[i] == NUL)
                return FAIL;
            if (p[i] == '#') {
                i++;
                for (j = i; j < i + 8 && vim_isxdigit (p[j]); ++j)
                    ;
                if (j < i + 8)
                    return FAIL;
                if (p[j] != NUL && p[j] != ',')
                    return FAIL;
                new_fuoptions_bgcolor = 0;
                for (k = 0; k < 8; k++)
                    new_fuoptions_bgcolor = new_fuoptions_bgcolor * 16 + hex2nr (p[i + k]);
                i = j;
                new_fuoptions_flags &= ~FUOPT_BGCOLOR_HLGROUP;
            }
            else {
                for (j = i; ASCII_ISALPHA (p[j]); ++j)
                    ;
                if (p[j] != NUL && p[j] != ',')
                    return FAIL;
                hg_term = p[j];
                p[j] = NUL;
                new_fuoptions_bgcolor = syn_name2id ((char_u *) (p + i));
                p[j] = hg_term;
                if (!new_fuoptions_bgcolor)
                    return FAIL;
                i = j;
                new_fuoptions_flags |= FUOPT_BGCOLOR_HLGROUP;
            }
        }
        else if (i == 7 && STRNCMP (p, "maxhorz", 7) == 0)
            new_fuoptions_flags |= FUOPT_MAXHORZ;
        else if (i == 7 && STRNCMP (p, "maxvert", 7) == 0)
            new_fuoptions_flags |= FUOPT_MAXVERT;
        else
            return FAIL;
        p += i;
        if (*p == NUL)
            break;
        if (*p == ':')
            return FAIL;
    }
    *flags = new_fuoptions_flags;
    *bgcolor = new_fuoptions_bgcolor;
    gui_mch_fuopt_update ();
    return OK;
}

static char_u *did_set_spell_option (int is_spellfile) {
    char_u *errmsg = NULL;
    win_T *wp;
    int l;
    if (is_spellfile) {
        l = (int) STRLEN (curwin->w_s->b_p_spf);
        if (l > 0 && (l < 4 || STRCMP (curwin->w_s->b_p_spf + l - 4, ".add") != 0))
            errmsg = e_invarg;
    }
    if (errmsg == NULL) {
        FOR_ALL_WINDOWS (wp)
            if (wp->w_buffer == curbuf && wp->w_p_spell) {
                errmsg = did_set_spelllang (wp);
                break;
            }
    }
    return errmsg;
}

static void fill_breakat_flags (void) {
    char_u *p;
    int i;
    for (i = 0; i < 256; i++)
        breakat_flags[i] = FALSE;
    if (p_breakat != NULL)
        for (p = p_breakat; *p; p++)
            breakat_flags[*p] = TRUE;
}

static void didset_options2 (void) {
    (void) highlight_changed ();
    check_opt_wim ();
    (void) set_chars_option (&p_lcs);
    (void) set_chars_option (&p_fcs);
}

static int check_opt_wim (void) {
    char_u new_wim_flags [4];
    char_u *p;
    int i;
    int idx = 0;
    for (i = 0; i < 4; ++i)
        new_wim_flags[i] = 0;
    for (p = p_wim; *p; ++p) {
        for (i = 0; ASCII_ISALPHA (p[i]); ++i)
            ;
        if (p[i] != NUL && p[i] != ',' && p[i] != ':')
            return FAIL;
        if (i == 7 && STRNCMP (p, "longest", 7) == 0)
            new_wim_flags[idx] |= WIM_LONGEST;
        else if (i == 4 && STRNCMP (p, "full", 4) == 0)
            new_wim_flags[idx] |= WIM_FULL;
        else if (i == 4 && STRNCMP (p, "list", 4) == 0)
            new_wim_flags[idx] |= WIM_LIST;
        else
            return FAIL;
        p += i;
        if (*p == NUL)
            break;
        if (*p == ',') {
            if (idx == 3)
                return FAIL;
            ++idx;
        }
    }
    while (idx < 3) {
        new_wim_flags[idx + 1] = new_wim_flags[idx];
        ++idx;
    }
    for (i = 0; i < 4; ++i)
        wim_flags[i] = new_wim_flags[i];
    return OK;
}

static char_u *set_chars_option (char_u **varp) {
    int round, i, len, entries;
    char_u *p, *s;
    int c1, c2 = 0;
    struct charstab {
        int *cp;
        char *name;
    };
    static struct charstab filltab [] = {{&fill_stl, "stl"}, {&fill_stlnc, "stlnc"}, {&fill_vert, "vert"}, {&fill_fold, "fold"}, {&fill_diff, "diff"},};
    static struct charstab lcstab [] = {{&lcs_eol, "eol"}, {&lcs_ext, "extends"}, {&lcs_nbsp, "nbsp"}, {&lcs_prec, "precedes"}, {&lcs_space, "space"}, {&lcs_tab2, "tab"}, {&lcs_trail, "trail"}, {&lcs_conceal, "conceal"},};
    struct charstab *tab;
    if (varp == &p_lcs) {
        tab = lcstab;
        entries = sizeof (lcstab) / sizeof (struct charstab);
    }
    else {
        tab = filltab;
        entries = sizeof (filltab) / sizeof (struct charstab);
    }
    for (round = 0; round <= 1; ++round) {
        if (round > 0) {
            for (i = 0; i < entries; ++i)
                if (tab[i].cp != NULL)
                    *(tab[i].cp) = (varp == &p_lcs ? NUL : ' ');
            if (varp == &p_lcs)
                lcs_tab1 = NUL;
            else
                fill_diff = '-';
        }
        p = *varp;
        while (*p) {
            for (i = 0; i < entries; ++i) {
                len = (int) STRLEN (tab[i].name);
                if (STRNCMP (p, tab[i].name, len) == 0 && p[len] == ':' && p[len + 1] != NUL) {
                    s = p + len + 1;
                    c1 = *s++;
                    if (tab[i].cp == &lcs_tab2) {
                        if (*s == NUL)
                            continue;
                        c2 = *s++;
                    }
                    if (*s == ',' || *s == NUL) {
                        if (round) {
                            if (tab[i].cp == &lcs_tab2) {
                                lcs_tab1 = c1;
                                lcs_tab2 = c2;
                            }
                            else if (tab[i].cp != NULL)
                                *(tab[i].cp) = c1;
                        }
                        p = s;
                        break;
                    }
                }
            }
            if (i == entries)
                return e_invarg;
            if (*p == ',')
                ++p;
        }
    }
    return NULL;
}

unsigned  int get_bkc_value (buf_T *buf) {
    return buf->b_bkc_flags ? buf->b_bkc_flags : bkc_flags;
}

void set_string_default (char *name, char_u *val) {
    set_string_default_esc (name, val, FALSE);
}

static void set_string_default_esc (char *name, char_u *val, int escape) {
    char_u *p;
    int opt_idx;
    if (escape && vim_strchr (val, ' ') != NULL)
        p = vim_strsave_escaped (val, (char_u *) " ");
    else
        p = vim_strsave (val);
    if (p != NULL) {
        opt_idx = findoption ((char_u *) name);
        if (opt_idx >= 0) {
            if (options[opt_idx].flags & P_DEF_ALLOCED)
                vim_free (options[opt_idx].def_val[VI_DEFAULT]);
            options[opt_idx].def_val[VI_DEFAULT] = p;
            options[opt_idx].flags |= P_DEF_ALLOCED;
        }
    }
}

void set_title_defaults (void) {
    int idx1;
    long  val;
    idx1 = findoption ((char_u *) "title");
    if (idx1 >= 0 && !(options[idx1].flags & P_WAS_SET)) {
        if (gui.starting || gui.in_use)
            val = TRUE;
        else
            val = mch_can_restore_title ();
        options[idx1].def_val[VI_DEFAULT] = (char_u *) (long_i) val;
        p_title = val;
    }
    idx1 = findoption ((char_u *) "icon");
    if (idx1 >= 0 && !(options[idx1].flags & P_WAS_SET)) {
        if (gui.starting || gui.in_use)
            val = TRUE;
        else
            val = mch_can_restore_icon ();
        options[idx1].def_val[VI_DEFAULT] = (char_u *) (long_i) val;
        p_icon = val;
    }
}

int do_set (char_u *arg, int opt_flags) {
    int opt_idx;
    char_u *errmsg;
    char_u errbuf [80];
    char_u *startarg;
    int prefix;
    int nextchar;
    int afterchar;
    int len;
    int i;
    varnumber_T value;
    int key;
    long_u flags;
    char_u *varp = NULL;
    int did_show = FALSE;
    int adding;
    int prepending;
    int removing;
    int cp_val = 0;
    char_u key_name [2];
    if (*arg == NUL) {
        showoptions (0, opt_flags);
        did_show = TRUE;
        goto theend;
    }
    while (*arg != NUL) {
        errmsg = NULL;
        startarg = arg;
        if (STRNCMP (arg, "all", 3) == 0 && !isalpha (arg[3]) && !(opt_flags & OPT_MODELINE)) {
            arg += 3;
            if (*arg == '&') {
                ++arg;
                set_options_default (OPT_FREE | opt_flags);
                didset_options ();
                didset_options2 ();
                redraw_all_later (CLEAR);
            }
            else {
                showoptions (1, opt_flags);
                did_show = TRUE;
            }
        }
        else if (STRNCMP (arg, "termcap", 7) == 0 && !(opt_flags & OPT_MODELINE)) {
            showoptions (2, opt_flags);
            show_termcodes ();
            did_show = TRUE;
            arg += 7;
        }
        else {
            prefix = 1;
            if (STRNCMP (arg, "no", 2) == 0 && STRNCMP (arg, "novice", 6) != 0) {
                prefix = 0;
                arg += 2;
            }
            else if (STRNCMP (arg, "inv", 3) == 0) {
                prefix = 2;
                arg += 3;
            }
            key = 0;
            if (*arg == '<') {
                nextchar = 0;
                opt_idx = -1;
                if (arg[1] == 't' && arg[2] == '_' && arg[3] && arg[4])
                    len = 5;
                else {
                    len = 1;
                    while (arg[len] != NUL && arg[len] != '>')
                        ++len;
                }
                if (arg[len] != '>') {
                    errmsg = e_invarg;
                    goto skip;
                }
                arg[len] = NUL;
                if (arg[1] == 't' && arg[2] == '_')
                    opt_idx = findoption (arg +1);
                arg[len++] = '>';
                if (opt_idx == -1)
                    key = find_key_option (arg +1);
            }
            else {
                len = 0;
                if (arg[0] == 't' && arg[1] == '_' && arg[2] && arg[3])
                    len = 4;
                else
                    while (ASCII_ISALNUM (arg[len]) || arg[len] == '_')
                        ++len;
                nextchar = arg[len];
                arg[len] = NUL;
                opt_idx = findoption (arg);
                arg[len] = nextchar;
                if (opt_idx == -1)
                    key = find_key_option (arg);
            }
            afterchar = arg[len];
            while (VIM_ISWHITE (arg[len]))
                ++len;
            adding = FALSE;
            prepending = FALSE;
            removing = FALSE;
            if (arg[len] != NUL && arg[len + 1] == '=') {
                if (arg[len] == '+') {
                    adding = TRUE;
                    ++len;
                }
                else if (arg[len] == '^') {
                    prepending = TRUE;
                    ++len;
                }
                else if (arg[len] == '-') {
                    removing = TRUE;
                    ++len;
                }
            }
            nextchar = arg[len];
            if (opt_idx == -1 && key == 0) {
                errmsg = (char_u *) N_ ("E518: Unknown option");
                goto skip;
            }
            if (opt_idx >= 0) {
                if (options[opt_idx].var == NULL) {
                    if (vim_strchr ((char_u *) "=:!&<", nextchar) == NULL && (!(options[opt_idx].flags & P_BOOL) || nextchar == '?'))
                        errmsg = (char_u *) N_ ("E519: Option not supported");
                    goto skip;
                }
                flags = options[opt_idx].flags;
                varp = get_varp_scope (&(options[opt_idx]), opt_flags);
            }
            else {
                flags = P_STRING;
                if (key < 0) {
                    key_name[0] = KEY2TERMCAP0 (key);
                    key_name[1] = KEY2TERMCAP1 (key);
                }
                else {
                    key_name[0] = KS_KEY;
                    key_name[1] = (key & 0xff);
                }
            }
            if ((opt_flags & OPT_WINONLY) && (opt_idx < 0 || options[opt_idx].var != VAR_WIN))
                goto skip;
            if ((opt_flags & OPT_NOWIN) && opt_idx >= 0 && options[opt_idx].var == VAR_WIN)
                goto skip;
            if (opt_flags & OPT_MODELINE) {
                if (flags & (P_SECURE | P_NO_ML)) {
                    errmsg = (char_u *) _ ("E520: Not allowed in a modeline");
                    goto skip;
                }
                if (curwin->w_p_diff && opt_idx >= 0 && (options[opt_idx].indir == PV_FDM || options[opt_idx].indir == PV_WRAP))
                    goto skip;
            }
            if (vim_strchr ((char_u *) "?=:!&<", nextchar) != NULL) {
                arg += len;
                cp_val = p_cp;
                if (nextchar == '&' && arg[1] == 'v' && arg[2] == 'i') {
                    if (arg[3] == 'm') {
                        cp_val = FALSE;
                        arg += 3;
                    }
                    else {
                        cp_val = TRUE;
                        arg += 2;
                    }
                }
                if (vim_strchr ((char_u *) "?!&<", nextchar) != NULL && arg[1] != NUL && !VIM_ISWHITE (arg[1])) {
                    errmsg = e_trailing;
                    goto skip;
                }
            }
            if (nextchar == '?' || (prefix == 1 && vim_strchr ((char_u *) "=:&<", nextchar) == NULL && !(flags & P_BOOL))) {
                if (did_show)
                    msg_putchar ('\n');
                else {
                    gotocmdline (TRUE);
                    did_show = TRUE;
                }
                if (opt_idx >= 0) {
                    showoneopt (& options [opt_idx], opt_flags);
                    if (p_verbose > 0) {
                        if (varp == options[opt_idx].var)
                            last_set_msg (options[opt_idx].scriptID);
                        else if ((int) options[opt_idx].indir & PV_WIN)
                            last_set_msg (curwin->w_p_scriptID[(int) options[opt_idx].indir & PV_MASK]);
                        else if ((int) options[opt_idx].indir & PV_BUF)
                            last_set_msg (curbuf->b_p_scriptID[(int) options[opt_idx].indir & PV_MASK]);
                    }
                }
                else {
                    char_u *p;
                    p = find_termcode (key_name);
                    if (p == NULL) {
                        errmsg = (char_u *) N_ ("E846: Key code not set");
                        goto skip;
                    }
                    else
                        (void) show_one_termcode (key_name, p, TRUE);
                }
                if (nextchar != '?' && nextchar != NUL && !VIM_ISWHITE (afterchar))
                    errmsg = e_trailing;
            }
            else {
                if (flags & P_BOOL) {
                    if (nextchar == '=' || nextchar == ':') {
                        errmsg = e_invarg;
                        goto skip;
                    }
                    if (nextchar == '!')
                        value = *(int*) (varp) ^ 1;
                    else if (nextchar == '&')
                        value = (int) (long ) (long_i) options[opt_idx].def_val[((flags & P_VI_DEF) || cp_val) ? VI_DEFAULT : VIM_DEFAULT];
                    else if (nextchar == '<') {
                        if ((int *) varp == &curbuf->b_p_ar && opt_flags == OPT_LOCAL)
                            value = -1;
                        else
                            value = *(int*) get_varp_scope (&(options[opt_idx]), OPT_GLOBAL);
                    }
                    else {
                        if (nextchar != NUL && !VIM_ISWHITE (afterchar)) {
                            errmsg = e_trailing;
                            goto skip;
                        }
                        if (prefix == 2)
                            value = *(int*) (varp) ^ 1;
                        else
                            value = prefix;
                    }
                    errmsg = set_bool_option (opt_idx, varp, (int) value, opt_flags);
                }
                else {
                    if (vim_strchr ((char_u *) "=:&<", nextchar) == NULL || prefix != 1) {
                        errmsg = e_invarg;
                        goto skip;
                    }
                    if (flags & P_NUM) {
                        ++arg;
                        if (nextchar == '&')
                            value = (long ) (long_i) options[opt_idx].def_val[((flags & P_VI_DEF) || cp_val) ? VI_DEFAULT : VIM_DEFAULT];
                        else if (nextchar == '<') {
                            if ((long  *) varp == &curbuf->b_p_ul && opt_flags == OPT_LOCAL)
                                value = NO_LOCAL_UNDOLEVEL;
                            else
                                value = *(long *) get_varp_scope (&(options[opt_idx]), OPT_GLOBAL);
                        }
                        else if (((long  *) varp == &p_wc || (long  *) varp == &p_wcm) && (*arg == '<' || *arg == '^' || (*arg != NUL && (!arg[1] || VIM_ISWHITE (arg[1])) && !VIM_ISDIGIT (*arg)))) {
                            value = string_to_key (arg, FALSE);
                            if (value == 0 && (long  *) varp != &p_wcm) {
                                errmsg = e_invarg;
                                goto skip;
                            }
                        }
                        else if (*arg == '-' || VIM_ISDIGIT (*arg)) {
                            vim_str2nr (arg, NULL, & i, STR2NR_ALL, & value, NULL, 0);
                            if (arg[i] != NUL && !VIM_ISWHITE (arg[i])) {
                                errmsg = e_invarg;
                                goto skip;
                            }
                        }
                        else {
                            errmsg = (char_u *) N_ ("E521: Number required after =");
                            goto skip;
                        }
                        if (adding)
                            value = *(long *) varp + value;
                        if (prepending)
                            value = *(long *) varp * value;
                        if (removing)
                            value = *(long *) varp - value;
                        errmsg = set_num_option (opt_idx, varp, value, errbuf, sizeof (errbuf), opt_flags);
                    }
                    else if (opt_idx >= 0) {
                        char_u *save_arg = NULL;
                        char_u *s = NULL;
                        char_u *oldval = NULL;
                        char_u *newval;
                        char_u *origval = NULL;
                        char_u *saved_origval = NULL;
                        char_u *saved_newval = NULL;
                        unsigned  newlen;
                        int comma;
                        int bs;
                        int new_value_alloced;
                        if ((opt_flags & (OPT_LOCAL | OPT_GLOBAL)) == 0 && ((int) options[opt_idx].indir & PV_BOTH))
                            varp = options[opt_idx].var;
                        oldval = *(char_u**) varp;
                        if (((int) options[opt_idx].indir & PV_BOTH) && (opt_flags & OPT_LOCAL))
                            origval = *(char_u**) get_varp (&options[opt_idx]);
                        else
                            origval = oldval;
                        if (nextchar == '&') {
                            newval = options[opt_idx].def_val[((flags & P_VI_DEF) || cp_val) ? VI_DEFAULT : VIM_DEFAULT];
                            if ((char_u **) varp == &p_bg) {
                                if (gui.in_use)
                                    newval = gui_bg_default ();
                                else
                                    newval = term_bg_default ();
                            }
                            if (newval == NULL)
                                newval = empty_option;
                            else {
                                s = option_expand (opt_idx, newval);
                                if (s == NULL)
                                    s = newval;
                                newval = vim_strsave (s);
                            }
                            new_value_alloced = TRUE;
                        }
                        else if (nextchar == '<') {
                            newval = vim_strsave (*(char_u**) get_varp_scope (&(options[opt_idx]), OPT_GLOBAL));
                            new_value_alloced = TRUE;
                        }
                        else {
                            ++arg;
                            if (varp == (char_u *) &p_kp && (*arg == NUL || *arg == ' ')) {
                                STRCPY (errbuf, ":help");
                                save_arg = arg;
                                arg = errbuf;
                            }
                            else if (varp == (char_u *) &p_bs && VIM_ISDIGIT (**(char_u**) varp)) {
                                i = getdigits ((char_u **) varp);
                                switch (i) {
                                case 0 :
                                    *(char_u**) varp = empty_option;
                                    break;
                                case 1 :
                                    *(char_u**) varp = vim_strsave ((char_u *) "indent,eol");
                                    break;
                                case 2 :
                                    *(char_u**) varp = vim_strsave ((char_u *) "indent,eol,start");
                                    break;
                                }
                                vim_free (oldval);
                                if (origval == oldval)
                                    origval = *(char_u**) varp;
                                oldval = *(char_u**) varp;
                            }
                            else if (varp == (char_u *) &p_ww && VIM_ISDIGIT (*arg)) {
                                *errbuf = NUL;
                                i = getdigits (&arg);
                                if (i & 1)
                                    STRCAT (errbuf, "b,");
                                if (i & 2)
                                    STRCAT (errbuf, "s,");
                                if (i & 4)
                                    STRCAT (errbuf, "h,l,");
                                if (i & 8)
                                    STRCAT (errbuf, "<,>,");
                                if (i & 16)
                                    STRCAT (errbuf, "[,],");
                                if (*errbuf != NUL)
                                    errbuf[STRLEN (errbuf) - 1] = NUL;
                                save_arg = arg;
                                arg = errbuf;
                            }
                            else if (*arg == '>' && (varp == (char_u *) &p_dir || varp == (char_u *) &p_bdir)) {
                                ++arg;
                            }
                            newlen = (unsigned ) STRLEN (arg) + 1;
                            if (adding || prepending || removing)
                                newlen += (unsigned ) STRLEN (origval) + 1;
                            newval = alloc (newlen);
                            if (newval == NULL)
                                break;
                            s = newval;
                            while (*arg && !VIM_ISWHITE (*arg)) {
                                if (*arg == '\\' && arg[1] != NUL)
                                    ++arg;
                                *s++ = *arg++;
                            }
                            *s = NUL;
                            if (!(adding || prepending || removing) || (flags & P_COMMA)) {
                                s = option_expand (opt_idx, newval);
                                if (s != NULL) {
                                    vim_free (newval);
                                    newlen = (unsigned ) STRLEN (s) + 1;
                                    if (adding || prepending || removing)
                                        newlen += (unsigned ) STRLEN (origval) + 1;
                                    newval = alloc (newlen);
                                    if (newval == NULL)
                                        break;
                                    STRCPY (newval, s);
                                }
                            }
                            i = 0;
                            if (removing || (flags & P_NODUP)) {
                                i = (int) STRLEN (newval);
                                bs = 0;
                                for (s = origval; *s; ++s) {
                                    if ((!(flags & P_COMMA) || s == origval || (s[-1] == ',' && !(bs & 1))) && STRNCMP (s, newval, i) == 0 && (!(flags & P_COMMA) || s[i] == ',' || s[i] == NUL))
                                        break;
                                    if ((s > origval + 1 && s[-1] == '\\' && s[-2] != ',') || (s == origval + 1 && s[-1] == '\\'))
                                        ++bs;
                                    else
                                        bs = 0;
                                }
                                if ((adding || prepending) && *s) {
                                    prepending = FALSE;
                                    adding = FALSE;
                                    STRCPY (newval, origval);
                                }
                            }
                            if (adding || prepending) {
                                comma = ((flags & P_COMMA) && *origval != NUL && *newval != NUL);
                                if (adding) {
                                    i = (int) STRLEN (origval);
                                    if (comma && i > 1 && (flags & P_ONECOMMA) == P_ONECOMMA && origval[i - 1] == ',' && origval[i - 2] != '\\')
                                        i--;
                                    mch_memmove (newval + i + comma, newval, STRLEN (newval) + 1);
                                    mch_memmove (newval, origval, (size_t) i);
                                }
                                else {
                                    i = (int) STRLEN (newval);
                                    STRMOVE (newval + i + comma, origval);
                                }
                                if (comma)
                                    newval[i] = ',';
                            }
                            if (removing) {
                                STRCPY (newval, origval);
                                if (*s) {
                                    if (flags & P_COMMA) {
                                        if (s == origval) {
                                            if (s[i] == ',')
                                                ++i;
                                        }
                                        else {
                                            --s;
                                            ++i;
                                        }
                                    }
                                    STRMOVE (newval + (s - origval), s + i);
                                }
                            }
                            if (flags & P_FLAGLIST) {
                                for (s = newval; *s;) {
                                    if (flags & P_ONECOMMA) {
                                        if (*s != ',' && *(s + 1) == ',' && vim_strchr (s +2, *s) != NULL) {
                                            STRMOVE (s, s + 2);
                                            continue;
                                        }
                                    }
                                    else {
                                        if ((!(flags & P_COMMA) || *s != ',') && vim_strchr (s +1, *s) != NULL) {
                                            STRMOVE (s, s + 1);
                                            continue;
                                        }
                                    }
                                    ++s;
                                }
                            }
                            if (save_arg != NULL)
                                arg = save_arg;
                            new_value_alloced = TRUE;
                        }
                        *(char_u**) (varp) = newval;
                        if (!starting && options[opt_idx].indir != PV_KEY && origval != NULL && newval != NULL) {
                            saved_origval = vim_strsave (origval);
                            saved_newval = vim_strsave (newval);
                        }
                        errmsg = did_set_string_option (opt_idx, (char_u **) varp, new_value_alloced, oldval, errbuf, opt_flags);
                        if (errmsg == NULL)
                            trigger_optionsset_string (opt_idx, opt_flags, saved_origval, saved_newval);
                        vim_free (saved_origval);
                        vim_free (saved_newval);
                        if (errmsg != NULL)
                            goto skip;
                    }
                    else {
                        char_u *p;
                        if (nextchar == '&') {
                            if (add_termcap_entry (key_name, TRUE) == FAIL)
                                errmsg = (char_u *) N_ ("E522: Not found in termcap");
                        }
                        else {
                            ++arg;
                            for (p = arg; *p && !VIM_ISWHITE (*p); ++p)
                                if (*p == '\\' && p[1] != NUL)
                                    ++p;
                            nextchar = *p;
                            *p = NUL;
                            add_termcode (key_name, arg, FALSE);
                            *p = nextchar;
                        }
                        if (full_screen)
                            ttest (FALSE);
                        redraw_all_later (CLEAR);
                    }
                }
                if (opt_idx >= 0)
                    did_set_option (opt_idx, opt_flags, !prepending && !adding && !removing);
            }
        skip :
            for (i = 0; i < 2; ++i) {
                while (*arg != NUL && !VIM_ISWHITE (*arg))
                    if (*arg++ == '\\' && *arg != NUL)
                        ++arg;
                arg = skipwhite (arg);
                if (*arg != '=')
                    break;
            }
        }
        if (errmsg != NULL) {
            vim_strncpy (IObuff, (char_u *) _ (errmsg), IOSIZE - 1);
            i = (int) STRLEN (IObuff) + 2;
            if (i + (arg - startarg) < IOSIZE) {
                STRCAT (IObuff, ": ");
                mch_memmove (IObuff + i, startarg, (arg - startarg));
                IObuff[i + (arg - startarg)] = NUL;
            }
            trans_characters (IObuff, IOSIZE);
            ++no_wait_return;
            emsg (IObuff);
            --no_wait_return;
            return FAIL;
        }
        arg = skipwhite (arg);
    }
theend :
    if (silent_mode && did_show) {
        silent_mode = FALSE;
        info_message = TRUE;
        msg_putchar ('\n');
        cursor_on ();
        out_flush ();
        silent_mode = TRUE;
        info_message = FALSE;
    }
    return OK;
}

static void showoptions (int all, int opt_flags) {
    struct vimoption *p;
    int col;
    int isterm;
    char_u *varp;
    struct vimoption **items;
    int item_count;
    int run;
    int row, rows;
    int cols;
    int i;
    int len;

    #define INC 20

    #define GAP 3
    items = (struct vimoption **) alloc ((unsigned ) (sizeof (struct vimoption *) * PARAM_COUNT));
    if (items == NULL)
        return;
    if (all == 2)
        MSG_PUTS_TITLE (_ ("\n--- Terminal codes ---"));
    else if (opt_flags & OPT_GLOBAL)
        MSG_PUTS_TITLE (_ ("\n--- Global option values ---"));
    else if (opt_flags & OPT_LOCAL)
        MSG_PUTS_TITLE (_ ("\n--- Local option values ---"));
    else
        MSG_PUTS_TITLE (_ ("\n--- Options ---"));
    for (run = 1; run <= 2 && !got_int; ++run) {
        item_count = 0;
        for (p = &options[0]; p->fullname != NULL; p++) {
            varp = NULL;
            isterm = istermoption (p);
            if (opt_flags != 0) {
                if (p->indir != PV_NONE && !isterm)
                    varp = get_varp_scope (p, opt_flags);
            }
            else
                varp = get_varp (p);
            if (varp != NULL && ((all == 2 && isterm) || (all == 1 && !isterm) || (all == 0 && !optval_default (p, varp)))) {
                if (p->flags & P_BOOL)
                    len = 1;
                else {
                    option_value2string (p, opt_flags);
                    len = (int) STRLEN (p->fullname) + vim_strsize (NameBuff) + 1;
                }
                if ((len <= INC - GAP && run == 1) || (len > INC - GAP && run == 2))
                    items[item_count++] = p;
            }
        }
        if (run == 1) {
            cols = (Columns + GAP - 3) / INC;
            if (cols == 0)
                cols = 1;
            rows = (item_count + cols - 1) / cols;
        }
        else
            rows = item_count;
        for (row = 0; row < rows && !got_int; ++row) {
            msg_putchar ('\n');
            if (got_int)
                break;
            col = 0;
            for (i = row; i < item_count; i += rows) {
                msg_col = col;
                showoneopt (items [i], opt_flags);
                col += INC;
            }
            out_flush ();
            ui_breakcheck ();
        }
    }
    vim_free (items);
}

static int optval_default (struct vimoption *p, char_u *varp) {
    int dvi;
    if (varp == NULL)
        return TRUE;
    dvi = ((p->flags & P_VI_DEF) || p_cp) ? VI_DEFAULT : VIM_DEFAULT;
    if (p->flags & P_NUM)
        return (*(long *) varp == (long ) (long_i) p->def_val[dvi]);
    if (p->flags & P_BOOL)
        return (*(int*) varp == (int) (long ) (long_i) p->def_val[dvi]);
    return (STRCMP (*(char_u**) varp, p->def_val[dvi]) == 0);
}

static void option_value2string (struct vimoption *opp, int opt_flags) {
    char_u *varp;
    varp = get_varp_scope (opp, opt_flags);
    if (opp->flags & P_NUM) {
        long  wc = 0;
        if (wc_use_keyname (varp, &wc))
            STRCPY (NameBuff, get_special_key_name ((int) wc, 0));
        else if (wc != 0)
            STRCPY (NameBuff, transchar ((int) wc));
        else
            sprintf ((char *) NameBuff, "%ld", *(long *) varp);
    }
    else {
        varp = *(char_u**) (varp);
        if (varp == NULL)
            NameBuff[0] = NUL;
        else if (opp->var == (char_u *) &p_key && *varp)
            STRCPY (NameBuff, "*****");
        else if (opp->flags & P_EXPAND)
            home_replace (NULL, varp, NameBuff, MAXPATHL, FALSE);
        else if ((char_u **) opp->var == &p_pt)
            str2specialbuf (p_pt, NameBuff, MAXPATHL);
        else
            vim_strncpy (NameBuff, varp, MAXPATHL -1);
    }
}

static int wc_use_keyname (char_u *varp, long  *wcp) {
    if (((long  *) varp == &p_wc) || ((long  *) varp == &p_wcm)) {
        *wcp = *(long *) varp;
        if (IS_SPECIAL (*wcp) || find_special_key_in_table ((int) *wcp) >= 0)
            return TRUE;
    }
    return FALSE;
}

static void showoneopt (struct vimoption *p, int opt_flags) {
    char_u *varp;
    int save_silent = silent_mode;
    silent_mode = FALSE;
    info_message = TRUE;
    varp = get_varp_scope (p, opt_flags);
    if ((p->flags & P_BOOL) && ((int *) varp == &curbuf->b_changed ? !curbufIsChanged () : !*(int*) varp))
        MSG_PUTS ("no");
    else if ((p->flags & P_BOOL) && *(int*) varp < 0)
        MSG_PUTS ("--");
    else
        MSG_PUTS ("  ");
    MSG_PUTS (p -> fullname);
    if (!(p->flags & P_BOOL)) {
        msg_putchar ('=');
        option_value2string (p, opt_flags);
        msg_outtrans (NameBuff);
    }
    silent_mode = save_silent;
    info_message = FALSE;
}

static void set_options_default (int opt_flags) {
    int i;
    win_T *wp;
    tabpage_T *tp;
    for (i = 0; !istermoption (&options[i]); i++)
        if (!(options[i].flags & P_NODEFAULT) && (opt_flags == 0 || (TRUE && options[i].var != (char_u *) &p_enc && options[i].var != (char_u *) &p_cm && options[i].var != (char_u *) &p_key)))
            set_option_default (i, opt_flags, p_cp);
    FOR_ALL_TAB_WINDOWS (tp, wp)
        win_comp_scroll (wp);
    parse_cino (curbuf);
}

static char_u *set_bool_option (int opt_idx, char_u *varp, int value, int opt_flags) {
    int old_value = *(int*) varp;
    if ((secure) &&(options[opt_idx].flags & P_SECURE))
        return e_secure;
    *(int*) varp = value;
    set_option_scriptID_idx (opt_idx, opt_flags, current_SID);
    need_mouse_correct = TRUE;
    if ((opt_flags & (OPT_LOCAL | OPT_GLOBAL)) == 0)
        *(int*) get_varp_scope (&(options[opt_idx]), OPT_GLOBAL) = value;
    if ((int *) varp == &p_cp) {
        compatible_set ();
    }
    if ((int *) varp == &p_lrm)
        p_lnr = !p_lrm;
    else if ((int *) varp == &p_lnr)
        p_lrm = !p_lnr;
    else if ((int *) varp == &curbuf->b_p_udf || (int *) varp == &p_udf) {
        if (curbuf->b_p_udf || p_udf) {
            char_u hash [UNDO_HASH_SIZE];
            buf_T *save_curbuf = curbuf;
            FOR_ALL_BUFFERS (curbuf) {
                if ((curbuf == save_curbuf || (opt_flags & OPT_GLOBAL) || opt_flags == 0) && !curbufIsChanged () && curbuf->b_ml.ml_mfp != NULL) {
                    u_compute_hash (hash);
                    u_read_undo (NULL, hash, curbuf -> b_fname);
                }
            }
            curbuf = save_curbuf;
        }
    }
    else if ((int *) varp == &curbuf->b_p_ro) {
        if (!curbuf->b_p_ro && (opt_flags & OPT_LOCAL) == 0)
            readonlymode = FALSE;
        if (curbuf->b_p_ro)
            curbuf->b_did_warn = FALSE;
        redraw_titles ();
    }
    else if ((int *) varp == &curbuf->b_p_ma) {
        if (term_in_normal_mode () || (bt_terminal (curbuf) && !term_is_finished (curbuf))) {
            curbuf->b_p_ma = FALSE;
            return (char_u *) N_ ("E946: Cannot make a terminal with running job modifiable");
        }
        redraw_titles ();
    }
    else if ((int *) varp == &curbuf->b_p_eol) {
        redraw_titles ();
    }
    else if ((int *) varp == &curbuf->b_p_fixeol) {
        redraw_titles ();
    }
    else if ((int *) varp == &curbuf->b_p_bin) {
        set_options_bin (old_value, curbuf -> b_p_bin, opt_flags);
        redraw_titles ();
    }
    else if ((int *) varp == &curbuf->b_p_bl && old_value != curbuf->b_p_bl) {
        apply_autocmds (curbuf -> b_p_bl ? EVENT_BUFADD : EVENT_BUFDELETE, NULL, NULL, TRUE, curbuf);
    }
    else if ((int *) varp == &curbuf->b_p_swf) {
        if (curbuf->b_p_swf && p_uc)
            ml_open_file (curbuf);
        else
            mf_close_file (curbuf, TRUE);
    }
    else if ((int *) varp == &p_terse) {
        char_u *p;
        p = vim_strchr (p_shm, SHM_SEARCH);
        if (p_terse && p == NULL) {
            STRCPY (IObuff, p_shm);
            STRCAT (IObuff, "s");
            set_string_option_direct ((char_u *) "shm", - 1, IObuff, OPT_FREE, 0);
        }
        else if (!p_terse && p != NULL)
            STRMOVE (p, p +1);
    }
    else if ((int *) varp == &p_paste) {
        paste_option_changed ();
    }
    else if ((int *) varp == &p_im) {
        if (p_im) {
            if ((State & INSERT) == 0)
                need_start_insertmode = TRUE;
            stop_insert_mode = FALSE;
        }
        else if (old_value) {
            need_start_insertmode = FALSE;
            stop_insert_mode = TRUE;
            if (restart_edit != 0 && mode_displayed)
                clear_cmdline = TRUE;
            restart_edit = 0;
        }
    }
    else if ((int *) varp == &p_ic && p_hls) {
        redraw_all_later (SOME_VALID);
    }
    else if ((int *) varp == &p_hls) {
        SET_NO_HLSEARCH (FALSE);
    }
    else if ((int *) varp == &curwin->w_p_scb) {
        if (curwin->w_p_scb) {
            do_check_scrollbind (FALSE);
            curwin->w_scbind_pos = curwin->w_topline;
        }
    }
    else if ((int *) varp == &curwin->w_p_pvw) {
        if (curwin->w_p_pvw) {
            win_T *win;
            FOR_ALL_WINDOWS (win)
                if (win->w_p_pvw && win != curwin) {
                    curwin->w_p_pvw = FALSE;
                    return (char_u *) N_ ("E590: A preview window already exists");
                }
        }
    }
    else if ((int *) varp == &curbuf->b_p_tx) {
        set_fileformat (curbuf -> b_p_tx ? EOL_DOS : EOL_UNIX, opt_flags);
    }
    else if ((int *) varp == &p_fullscreen && (gui.in_use || gui.starting)) {
        if (p_fullscreen && !old_value) {
            guicolor_T fg, bg;
            if (fuoptions_flags & FUOPT_BGCOLOR_HLGROUP) {
                syn_id2colors (fuoptions_bgcolor, & fg, & bg);
            }
            else {
                bg = fuoptions_bgcolor;
            }
            gui_mch_enter_fullscreen (fuoptions_flags, bg);
        }
        else if (!p_fullscreen && old_value) {
            gui_mch_leave_fullscreen ();
        }
    }
    else if ((int *) varp == &p_macligatures) {
        gui_macvim_set_ligatures (p_macligatures);
    }
    else if ((int *) varp == &p_macthinstrokes) {
        gui_macvim_set_thinstrokes (p_macthinstrokes);
    }
    else if ((int *) varp == &p_ta)
        set_string_option_direct ((char_u *) "ffs", -1, p_ta ? (char_u *) DFLT_FFS_VIM : (char_u *) "", OPT_FREE | opt_flags, 0);
    else if (varp == (char_u *) &(curbuf->b_p_lisp)) {
        (void) buf_init_chartab (curbuf, FALSE);
    }
    else if ((int *) varp == &p_title) {
        did_set_title (FALSE);
    }
    else if ((int *) varp == &p_icon) {
        did_set_title (TRUE);
    }
    else if ((int *) varp == &curbuf->b_changed) {
        if (!value)
            save_file_ff (curbuf);
        redraw_titles ();
        modified_was_set = value;
    }
    else if ((int *) varp == &curwin->w_p_wrap) {
        if (curwin->w_p_wrap)
            curwin->w_leftcol = 0;
    }
    else if ((int *) varp == &p_ea) {
        if (p_ea && !old_value)
            win_equal (curwin, FALSE, 0);
    }
    else if ((int *) varp == &p_wiv) {
        if (p_wiv && !old_value)
            T_XS = (char_u *) "y";
        else if (!p_wiv && old_value)
            T_XS = empty_option;
        p_wiv = (*T_XS != NUL);
    }
    else if ((int *) varp == &p_beval) {
        if (!balloonEvalForTerm) {
            if (p_beval && !old_value)
                gui_mch_enable_beval_area (balloonEval);
            else if (!p_beval && old_value)
                gui_mch_disable_beval_area (balloonEval);
        }
    }
    else if ((int *) varp == &p_bevalterm) {
        mch_bevalterm_changed ();
    }
    else if ((int *) varp == &p_acd) {
        DO_AUTOCHDIR
    }
    else if ((int *) varp == &curwin->w_p_diff) {
        diff_buf_adjust (curwin);
        if (foldmethodIsDiff (curwin))
            foldUpdateAll (curwin);
    }
    else if ((int *) varp == &curwin->w_p_spell) {
        if (curwin->w_p_spell) {
            char_u *errmsg = did_set_spelllang (curwin);
            if (errmsg != NULL)
                EMSG (_ (errmsg));
        }
    }
    else if ((int *) varp == &p_altkeymap) {
        if (old_value != p_altkeymap) {
            if (!p_altkeymap) {
                p_hkmap = p_fkmap;
                p_fkmap = 0;
            }
            else {
                p_fkmap = p_hkmap;
                p_hkmap = 0;
            }
            (void) init_chartab ();
        }
    }
    if ((p_hkmap || p_fkmap) && p_altkeymap) {
        p_altkeymap = p_fkmap;
        curwin->w_p_arab = FALSE;
        (void) init_chartab ();
    }
    if (p_hkmap && p_altkeymap) {
        p_altkeymap = 0;
        p_fkmap = 0;
        curwin->w_p_arab = FALSE;
        (void) init_chartab ();
    }
    if (p_fkmap && !p_altkeymap) {
        p_altkeymap = 1;
        p_hkmap = 0;
        curwin->w_p_arab = FALSE;
        (void) init_chartab ();
    }
    if ((int *) varp == &curwin->w_p_arab) {
        if (curwin->w_p_arab) {
            if (!p_tbidi) {
                if (!curwin->w_p_rl) {
                    curwin->w_p_rl = TRUE;
                    changed_window_setting ();
                }
                if (!p_arshape) {
                    p_arshape = TRUE;
                    redraw_later_clear ();
                }
            }
            if (STRCMP (p_enc, "utf-8") != 0) {
                static char *w_arabic = N_ ("W17: Arabic requires UTF-8, do ':set encoding=utf-8'");
                msg_source (HL_ATTR (HLF_W));
                MSG_ATTR (_ (w_arabic), HL_ATTR (HLF_W));
                set_vim_var_string (VV_WARNINGMSG, (char_u *) _ (w_arabic), - 1);
            }
            set_option_value ((char_u *) "keymap", 0L, (char_u *) "arabic", OPT_LOCAL);
            p_altkeymap = 0;
            p_hkmap = 0;
            p_fkmap = 0;
            (void) init_chartab ();
        }
        else {
            if (!p_tbidi) {
                if (curwin->w_p_rl) {
                    curwin->w_p_rl = FALSE;
                    changed_window_setting ();
                }
            }
            curbuf->b_p_iminsert = B_IMODE_NONE;
            curbuf->b_p_imsearch = B_IMODE_USE_INSERT;
        }
    }
    else if ((int *) varp == &p_tgc) {
        if (!gui.in_use && !gui.starting)
            highlight_gui_started ();
    }
    options[opt_idx].flags |= P_WAS_SET;
    if (!starting) {
        char_u buf_old [2], buf_new [2], buf_type [7];
        vim_snprintf ((char *) buf_old, 2, "%d", old_value ? TRUE : FALSE);
        vim_snprintf ((char *) buf_new, 2, "%d", value ? TRUE : FALSE);
        vim_snprintf ((char *) buf_type, 7, "%s", (opt_flags & OPT_LOCAL) ? "local" : "global");
        set_vim_var_string (VV_OPTION_NEW, buf_new, - 1);
        set_vim_var_string (VV_OPTION_OLD, buf_old, - 1);
        set_vim_var_string (VV_OPTION_TYPE, buf_type, - 1);
        apply_autocmds (EVENT_OPTIONSET, (char_u *) options [opt_idx].fullname, NULL, FALSE, NULL);
        reset_v_option_vars ();
    }
    comp_col ();
    if (curwin->w_curswant != MAXCOL && (options[opt_idx].flags & (P_CURSWANT | P_RALL)) != 0)
        curwin->w_set_curswant = TRUE;
    check_redraw (options [opt_idx].flags);
    return NULL;
}

static void compatible_set (void) {
    int opt_idx;
    for (opt_idx = 0; !istermoption (&options[opt_idx]); opt_idx++)
        if (((options[opt_idx].flags & P_VIM) && p_cp) || (!(options[opt_idx].flags & P_VI_DEF) && !p_cp))
            set_option_default (opt_idx, OPT_FREE, p_cp);
    didset_options ();
    didset_options2 ();
}

static void redraw_titles (void) {
    need_maketitle = TRUE;
    redraw_tabline = TRUE;
}

void set_options_bin (int oldval, int newval, int opt_flags) {
    if (newval) {
        if (!oldval) {
            if (!(opt_flags & OPT_GLOBAL)) {
                curbuf->b_p_tw_nobin = curbuf->b_p_tw;
                curbuf->b_p_wm_nobin = curbuf->b_p_wm;
                curbuf->b_p_ml_nobin = curbuf->b_p_ml;
                curbuf->b_p_et_nobin = curbuf->b_p_et;
            }
            if (!(opt_flags & OPT_LOCAL)) {
                p_tw_nobin = p_tw;
                p_wm_nobin = p_wm;
                p_ml_nobin = p_ml;
                p_et_nobin = p_et;
            }
        }
        if (!(opt_flags & OPT_GLOBAL)) {
            curbuf->b_p_tw = 0;
            curbuf->b_p_wm = 0;
            curbuf->b_p_ml = 0;
            curbuf->b_p_et = 0;
        }
        if (!(opt_flags & OPT_LOCAL)) {
            p_tw = 0;
            p_wm = 0;
            p_ml = FALSE;
            p_et = FALSE;
            p_bin = TRUE;
        }
    }
    else if (oldval) {
        if (!(opt_flags & OPT_GLOBAL)) {
            curbuf->b_p_tw = curbuf->b_p_tw_nobin;
            curbuf->b_p_wm = curbuf->b_p_wm_nobin;
            curbuf->b_p_ml = curbuf->b_p_ml_nobin;
            curbuf->b_p_et = curbuf->b_p_et_nobin;
        }
        if (!(opt_flags & OPT_LOCAL)) {
            p_tw = p_tw_nobin;
            p_wm = p_wm_nobin;
            p_ml = p_ml_nobin;
            p_et = p_et_nobin;
        }
    }
}

static void paste_option_changed (void) {
    static int old_p_paste = FALSE;
    static int save_sm = 0;
    static int save_sta = 0;
    static int save_ru = 0;
    static int save_ri = 0;
    static int save_hkmap = 0;
    buf_T *buf;
    if (p_paste) {
        if (!old_p_paste) {
            FOR_ALL_BUFFERS (buf) {
                buf->b_p_tw_nopaste = buf->b_p_tw;
                buf->b_p_wm_nopaste = buf->b_p_wm;
                buf->b_p_sts_nopaste = buf->b_p_sts;
                buf->b_p_ai_nopaste = buf->b_p_ai;
                buf->b_p_et_nopaste = buf->b_p_et;
            }
            save_sm = p_sm;
            save_sta = p_sta;
            save_ru = p_ru;
            save_ri = p_ri;
            save_hkmap = p_hkmap;
            p_ai_nopaste = p_ai;
            p_et_nopaste = p_et;
            p_sts_nopaste = p_sts;
            p_tw_nopaste = p_tw;
            p_wm_nopaste = p_wm;
        }
        FOR_ALL_BUFFERS (buf) {
            buf->b_p_tw = 0;
            buf->b_p_wm = 0;
            buf->b_p_sts = 0;
            buf->b_p_ai = 0;
            buf->b_p_et = 0;
        }
        p_sm = 0;
        p_sta = 0;
        if (p_ru)
            status_redraw_all ();
        p_ru = 0;
        p_ri = 0;
        p_hkmap = 0;
        p_tw = 0;
        p_wm = 0;
        p_sts = 0;
        p_ai = 0;
    }
    else if (old_p_paste) {
        FOR_ALL_BUFFERS (buf) {
            buf->b_p_tw = buf->b_p_tw_nopaste;
            buf->b_p_wm = buf->b_p_wm_nopaste;
            buf->b_p_sts = buf->b_p_sts_nopaste;
            buf->b_p_ai = buf->b_p_ai_nopaste;
            buf->b_p_et = buf->b_p_et_nopaste;
        }
        p_sm = save_sm;
        p_sta = save_sta;
        if (p_ru != save_ru)
            status_redraw_all ();
        p_ru = save_ru;
        p_ri = save_ri;
        p_hkmap = save_hkmap;
        p_ai = p_ai_nopaste;
        p_et = p_et_nopaste;
        p_sts = p_sts_nopaste;
        p_tw = p_tw_nopaste;
        p_wm = p_wm_nopaste;
    }
    old_p_paste = p_paste;
}

static void did_set_title (int icon) {
    if (starting != NO_SCREEN && !gui.starting) {
        maketitle ();
        if (icon) {
            if (!p_icon)
                mch_restore_title (2);
        }
        else {
            if (!p_title)
                mch_restore_title (1);
        }
    }
}

int shortmess (int x) {
    return p_shm != NULL && (vim_strchr (p_shm, x) != NULL || (vim_strchr (p_shm, 'a') != NULL && vim_strchr ((char_u *) SHM_A, x) != NULL));
}

static void check_redraw (long_u flags) {
    int doclear = (flags & P_RCLR) == P_RCLR;
    int all = ((flags & P_RALL) == P_RALL || doclear);
    if ((flags & P_RSTAT) || all)
        status_redraw_all ();
    if ((flags & P_RBUF) || (flags & P_RWIN) || all)
        changed_window_setting ();
    if (flags & P_RBUF)
        redraw_curbuf_later (NOT_VALID);
    if (flags & P_RWINONLY)
        redraw_later (NOT_VALID);
    if (doclear)
        redraw_all_later (CLEAR);
    else if (all)
        redraw_all_later (NOT_VALID);
}

int string_to_key (char_u *arg, int multi_byte) {
    if (*arg == '<')
        return find_key_option (arg +1);
    if (*arg == '^')
        return Ctrl_chr (arg[1]);
    if (multi_byte)
        return PTR2CHAR (arg);
    return *arg;
}

static char_u *set_num_option (int opt_idx, char_u *varp, long  value, char_u *errbuf, size_t errbuflen, int opt_flags) {
    char_u *errmsg = NULL;
    long  old_value = *(long *) varp;
    long  old_Rows = Rows;
    long  old_Columns = Columns;
    long  *pp = (long  *) varp;
    if ((secure) &&(options[opt_idx].flags & P_SECURE))
        return e_secure;
    *pp = value;
    set_option_scriptID_idx (opt_idx, opt_flags, current_SID);
    need_mouse_correct = TRUE;
    if (curbuf->b_p_sw < 0) {
        errmsg = e_positive;
        curbuf->b_p_sw = curbuf->b_p_ts;
    }
    if (pp == &p_wh || pp == &p_hh) {
        if (p_wh < 1) {
            errmsg = e_positive;
            p_wh = 1;
        }
        if (p_wmh > p_wh) {
            errmsg = e_winheight;
            p_wh = p_wmh;
        }
        if (p_hh < 0) {
            errmsg = e_positive;
            p_hh = 0;
        }
        if (!ONE_WINDOW) {
            if (pp == &p_wh && curwin->w_height < p_wh)
                win_setheight ((int) p_wh);
            if (pp == &p_hh && curbuf->b_help && curwin->w_height < p_hh)
                win_setheight ((int) p_hh);
        }
    }
    else if (pp == &p_wmh) {
        if (p_wmh < 0) {
            errmsg = e_positive;
            p_wmh = 0;
        }
        if (p_wmh > p_wh) {
            errmsg = e_winheight;
            p_wmh = p_wh;
        }
        win_setminheight ();
    }
    else if (pp == &p_wiw) {
        if (p_wiw < 1) {
            errmsg = e_positive;
            p_wiw = 1;
        }
        if (p_wmw > p_wiw) {
            errmsg = e_winwidth;
            p_wiw = p_wmw;
        }
        if (!ONE_WINDOW && curwin->w_width < p_wiw)
            win_setwidth ((int) p_wiw);
    }
    else if (pp == &p_wmw) {
        if (p_wmw < 0) {
            errmsg = e_positive;
            p_wmw = 0;
        }
        if (p_wmw > p_wiw) {
            errmsg = e_winwidth;
            p_wmw = p_wiw;
        }
        win_setminheight ();
    }
    else if (pp == &p_ls) {
        last_status (FALSE);
    }
    else if (pp == &p_stal) {
        shell_new_rows ();
    }
    else if (pp == &p_linespace) {
        if (gui.in_use && gui_mch_adjust_charheight () == OK)
            gui_set_shellsize (FALSE, FALSE, RESIZE_VERT);
    }
    else if (pp == &p_columnspace) {
        if (gui.in_use && gui_mch_adjust_charwidth () == OK)
            gui_set_shellsize (FALSE, FALSE, RESIZE_HOR);
    }
    else if (pp == &curwin->w_p_fdl) {
        if (curwin->w_p_fdl < 0)
            curwin->w_p_fdl = 0;
        newFoldLevel ();
    }
    else if (pp == &curwin->w_p_fml) {
        foldUpdateAll (curwin);
    }
    else if (pp == &curwin->w_p_fdn) {
        if (foldmethodIsSyntax (curwin) || foldmethodIsIndent (curwin))
            foldUpdateAll (curwin);
    }
    else if (pp == &curwin->w_p_fdc) {
        if (curwin->w_p_fdc < 0) {
            errmsg = e_positive;
            curwin->w_p_fdc = 0;
        }
        else if (curwin->w_p_fdc > 12) {
            errmsg = e_invarg;
            curwin->w_p_fdc = 12;
        }
    }
    else if (pp == &curbuf->b_p_sw || pp == &curbuf->b_p_ts) {
        if (foldmethodIsIndent (curwin))
            foldUpdateAll (curwin);
        if (pp == &curbuf->b_p_sw || curbuf->b_p_sw == 0)
            parse_cino (curbuf);
    }
    else if (pp == &curbuf->b_p_iminsert) {
        if (curbuf->b_p_iminsert < 0 || curbuf->b_p_iminsert > B_IMODE_LAST) {
            errmsg = e_invarg;
            curbuf->b_p_iminsert = B_IMODE_NONE;
        }
        p_iminsert = curbuf->b_p_iminsert;
        if (termcap_active)
            showmode ();
        status_redraw_curbuf ();
    }
    else if (pp == &p_imst) {
        if (p_imst != IM_ON_THE_SPOT && p_imst != IM_OVER_THE_SPOT)
            errmsg = e_invarg;
    }
    else if (pp == &p_window) {
        if (p_window < 1)
            p_window = 1;
        else if (p_window >= Rows)
            p_window = Rows - 1;
    }
    else if (pp == &curbuf->b_p_imsearch) {
        if (curbuf->b_p_imsearch < -1 || curbuf->b_p_imsearch > B_IMODE_LAST) {
            errmsg = e_invarg;
            curbuf->b_p_imsearch = B_IMODE_NONE;
        }
        p_imsearch = curbuf->b_p_imsearch;
    }
    else if (pp == &p_titlelen) {
        if (p_titlelen < 0) {
            errmsg = e_positive;
            p_titlelen = 85;
        }
        if (starting != NO_SCREEN && old_value != p_titlelen)
            need_maketitle = TRUE;
    }
    else if (pp == &p_ch) {
        if (p_ch < 1) {
            errmsg = e_positive;
            p_ch = 1;
        }
        if (p_ch > Rows - min_rows () + 1)
            p_ch = Rows - min_rows () + 1;
        if (p_ch != old_value && full_screen && !gui.starting)
            command_height ();
    }
    else if (pp == &p_uc) {
        if (p_uc < 0) {
            errmsg = e_positive;
            p_uc = 100;
        }
        if (p_uc && !old_value)
            ml_open_files ();
    }
    else if (pp == &curwin->w_p_cole) {
        if (curwin->w_p_cole < 0) {
            errmsg = e_positive;
            curwin->w_p_cole = 0;
        }
        else if (curwin->w_p_cole > 3) {
            errmsg = e_invarg;
            curwin->w_p_cole = 3;
        }
    }
    else if (pp == &p_ul) {
        p_ul = old_value;
        u_sync (TRUE);
        p_ul = value;
    }
    else if (pp == &curbuf->b_p_ul) {
        curbuf->b_p_ul = old_value;
        u_sync (TRUE);
        curbuf->b_p_ul = value;
    }
    else if (pp == &curwin->w_p_nuw) {
        if (curwin->w_p_nuw < 1) {
            errmsg = e_positive;
            curwin->w_p_nuw = 1;
        }
        if (curwin->w_p_nuw > 10) {
            errmsg = e_invarg;
            curwin->w_p_nuw = 10;
        }
        curwin->w_nrwidth_line_count = 0;
    }
    else if (pp == &p_transp) {
        if (p_transp < 0 || p_transp > 100) {
            errmsg = e_invarg;
            p_transp = old_value;
        }
        else if (gui.in_use)
            gui_mch_new_colors ();
    }
    else if (pp == &p_blur) {
        if (p_blur < 0) {
            errmsg = e_invarg;
            p_blur = old_value;
        }
        else {
            gui_macvim_set_blur (p_blur);
        }
    }
    else if (pp == &curbuf->b_p_tw) {
        if (curbuf->b_p_tw < 0) {
            errmsg = e_positive;
            curbuf->b_p_tw = 0;
        }
        {
            win_T *wp;
            tabpage_T *tp;
            FOR_ALL_TAB_WINDOWS (tp, wp)
                check_colorcolumn (wp);
        }
    }
    if (Rows < min_rows () && full_screen) {
        if (errbuf != NULL) {
            vim_snprintf ((char *) errbuf, errbuflen, _ ("E593: Need at least %d lines"), min_rows ());
            errmsg = errbuf;
        }
        Rows = min_rows ();
    }
    if (Columns < MIN_COLUMNS && full_screen) {
        if (errbuf != NULL) {
            vim_snprintf ((char *) errbuf, errbuflen, _ ("E594: Need at least %d columns"), MIN_COLUMNS);
            errmsg = errbuf;
        }
        Columns = MIN_COLUMNS;
    }
    limit_screen_size ();
    if (old_Rows != Rows || old_Columns != Columns) {
        if (updating_screen)
            *pp = old_value;
        else if (full_screen && !gui.starting)
            set_shellsize ((int) Columns, (int) Rows, TRUE);
        else {
            check_shellsize ();
            if (cmdline_row > Rows - p_ch && Rows > p_ch)
                cmdline_row = Rows - p_ch;
        }
        if (p_window >= Rows || !option_was_set ((char_u *) "window"))
            p_window = Rows - 1;
    }
    if (curbuf->b_p_ts <= 0) {
        errmsg = e_positive;
        curbuf->b_p_ts = 8;
    }
    if (p_tm < 0) {
        errmsg = e_positive;
        p_tm = 0;
    }
    if ((curwin->w_p_scr <= 0 || (curwin->w_p_scr > curwin->w_height && curwin->w_height > 0)) && full_screen) {
        if (pp == &(curwin->w_p_scr)) {
            if (curwin->w_p_scr != 0)
                errmsg = e_scroll;
            win_comp_scroll (curwin);
        }
        else if (curwin->w_p_scr <= 0)
            curwin->w_p_scr = 1;
        else
            curwin->w_p_scr = curwin->w_height;
    }
    if (p_hi < 0) {
        errmsg = e_positive;
        p_hi = 0;
    }
    else if (p_hi > 10000) {
        errmsg = e_invarg;
        p_hi = 10000;
    }
    if (p_re < 0 || p_re > 2) {
        errmsg = e_invarg;
        p_re = 0;
    }
    if (p_report < 0) {
        errmsg = e_positive;
        p_report = 1;
    }
    if ((p_sj < -100 || p_sj >= Rows) && full_screen) {
        if (Rows != old_Rows)
            p_sj = Rows / 2;
        else {
            errmsg = e_scroll;
            p_sj = 1;
        }
    }
    if (p_so < 0 && full_screen) {
        errmsg = e_scroll;
        p_so = 0;
    }
    if (p_siso < 0 && full_screen) {
        errmsg = e_positive;
        p_siso = 0;
    }
    if (p_ut < 0) {
        errmsg = e_positive;
        p_ut = 2000;
    }
    if (p_ss < 0) {
        errmsg = e_positive;
        p_ss = 0;
    }
    if ((opt_flags & (OPT_LOCAL | OPT_GLOBAL)) == 0)
        *(long *) get_varp_scope (&(options[opt_idx]), OPT_GLOBAL) = *pp;
    options[opt_idx].flags |= P_WAS_SET;
    if (!starting && errmsg == NULL) {
        char_u buf_old [11], buf_new [11], buf_type [7];
        vim_snprintf ((char *) buf_old, 10, "%ld", old_value);
        vim_snprintf ((char *) buf_new, 10, "%ld", value);
        vim_snprintf ((char *) buf_type, 7, "%s", (opt_flags & OPT_LOCAL) ? "local" : "global");
        set_vim_var_string (VV_OPTION_NEW, buf_new, - 1);
        set_vim_var_string (VV_OPTION_OLD, buf_old, - 1);
        set_vim_var_string (VV_OPTION_TYPE, buf_type, - 1);
        apply_autocmds (EVENT_OPTIONSET, (char_u *) options [opt_idx].fullname, NULL, FALSE, NULL);
        reset_v_option_vars ();
    }
    comp_col ();
    if (curwin->w_curswant != MAXCOL && (options[opt_idx].flags & (P_CURSWANT | P_RALL)) != 0)
        curwin->w_set_curswant = TRUE;
    check_redraw (options [opt_idx].flags);
    return errmsg;
}

static char_u *gui_bg_default (void) {
    if (gui_get_lightness (gui.back_pixel) < 127)
        return (char_u *) "dark";
    return (char_u *) "light";
}

static char_u *term_bg_default (void) {
    char_u *p;
    if (STRCMP (T_NAME, "linux") == 0 || STRCMP (T_NAME, "screen.linux") == 0 || STRNCMP (T_NAME, "cygwin", 6) == 0 || STRNCMP (T_NAME, "putty", 5) == 0 || ((p = mch_getenv ((char_u *) "COLORFGBG")) != NULL && (p = vim_strrchr (p, ';')) != NULL && ((p[1] >= '0' && p[1] <= '6') || p[1] == '8') && p[2] == NUL))
        return (char_u *) "dark";
    return (char_u *) "light";
}

static char_u *option_expand (int opt_idx, char_u *val) {
    if (!(options[opt_idx].flags & P_EXPAND) || options[opt_idx].var == NULL)
        return NULL;
    if (val != NULL && STRLEN (val) > MAXPATHL)
        return NULL;
    if (val == NULL)
        val = *(char_u**) options[opt_idx].var;
    expand_env_esc (val, NameBuff, MAXPATHL, (char_u * *) options [opt_idx].var == & p_tags, FALSE, (char_u * *) options [opt_idx].var == & p_sps ? (char_u *) "file:" : NULL);
    if (STRCMP (NameBuff, val) == 0)
        return NULL;
    return NameBuff;
}

static void trigger_optionsset_string (int opt_idx, int opt_flags, char_u *oldval, char_u *newval) {
    if (oldval != NULL && newval != NULL) {
        char_u buf_type [7];
        sprintf ((char *) buf_type, "%s", (opt_flags & OPT_LOCAL) ? "local" : "global");
        set_vim_var_string (VV_OPTION_OLD, oldval, - 1);
        set_vim_var_string (VV_OPTION_NEW, newval, - 1);
        set_vim_var_string (VV_OPTION_TYPE, buf_type, - 1);
        apply_autocmds (EVENT_OPTIONSET, (char_u *) options [opt_idx].fullname, NULL, FALSE, NULL);
        reset_v_option_vars ();
    }
}

static void did_set_option (int opt_idx, int opt_flags, int new_value) {
    long_u *p;
    options[opt_idx].flags |= P_WAS_SET;
    p = insecure_flag (opt_idx, opt_flags);
    if (secure || (opt_flags & OPT_MODELINE))
        *p = *p | P_INSECURE;
    else if (new_value)
        *p = *p & ~P_INSECURE;
}

void find_mps_values (int *initc, int *findc, int *backwards, int switchit) {
    char_u *ptr;
    ptr = curbuf->b_p_mps;
    while (*ptr != NUL) {
        {
            if (*ptr == *initc) {
                if (switchit) {
                    *backwards = TRUE;
                    *findc = *initc;
                    *initc = ptr[2];
                }
                else {
                    *backwards = FALSE;
                    *findc = ptr[2];
                }
                return;
            }
            ptr += 2;
            if (*ptr == *initc) {
                if (switchit) {
                    *backwards = FALSE;
                    *findc = *initc;
                    *initc = ptr[-2];
                }
                else {
                    *backwards = TRUE;
                    *findc = ptr[-2];
                }
                return;
            }
            ++ptr;
        }
        if (*ptr == ',')
            ++ptr;
    }
}

int has_format_option (int x) {
    if (p_paste)
        return FALSE;
    return (vim_strchr (curbuf->b_p_fo, x) != NULL);
}

int ExpandOldSetting (int *num_file, char_u ***file) {
    char_u *var = NULL;
    char_u *buf;
    *num_file = 0;
    *file = (char_u **) alloc ((unsigned ) sizeof (char_u *));
    if (*file == NULL)
        return FAIL;
    if (expand_option_idx < 0) {
        var = find_termcode (expand_option_name +2);
        if (var == NULL)
            expand_option_idx = findoption (expand_option_name);
    }
    if (expand_option_idx >= 0) {
        option_value2string (& options [expand_option_idx], expand_option_flags);
        var = NameBuff;
    }
    else if (var == NULL)
        var = (char_u *) "";
    buf = vim_strsave_escaped (var, escape_chars);
    if (buf == NULL) {
        VIM_CLEAR (*file);
        return FAIL;
    }
    *file[0] = buf;
    *num_file = 1;
    return OK;
}

int ExpandSettings (expand_T *xp, regmatch_T *regmatch, int *num_file, char_u ***file) {
    int num_normal = 0;
    int num_term = 0;
    int opt_idx;
    int match;
    int count = 0;
    char_u *str;
    int loop;
    int is_term_opt;
    char_u name_buf [MAX_KEY_NAME_LEN];
    static char * (names []) = {"all", "termcap"};
    int ic = regmatch->rm_ic;
    for (loop = 0; loop <= 1; ++loop) {
        regmatch->rm_ic = ic;
        if (xp->xp_context != EXPAND_BOOL_SETTINGS) {
            for (match = 0; match < (int) (sizeof (names) / sizeof (char *)); ++match)
                if (vim_regexec (regmatch, (char_u *) names[match], (colnr_T) 0)) {
                    if (loop == 0)
                        num_normal++;
                    else
                        (*file)[count++] = vim_strsave ((char_u *) names[match]);
                }
        }
        for (opt_idx = 0; (str = (char_u *) options[opt_idx].fullname) != NULL; opt_idx++) {
            if (options[opt_idx].var == NULL)
                continue;
            if (xp->xp_context == EXPAND_BOOL_SETTINGS && !(options[opt_idx].flags & P_BOOL))
                continue;
            is_term_opt = istermoption (&options[opt_idx]);
            if (is_term_opt && num_normal > 0)
                continue;
            match = FALSE;
            if (vim_regexec (regmatch, str, (colnr_T) 0) || (options[opt_idx].shortname != NULL && vim_regexec (regmatch, (char_u *) options[opt_idx].shortname, (colnr_T) 0)))
                match = TRUE;
            else if (is_term_opt) {
                name_buf[0] = '<';
                name_buf[1] = 't';
                name_buf[2] = '_';
                name_buf[3] = str[2];
                name_buf[4] = str[3];
                name_buf[5] = '>';
                name_buf[6] = NUL;
                if (vim_regexec (regmatch, name_buf, (colnr_T) 0)) {
                    match = TRUE;
                    str = name_buf;
                }
            }
            if (match) {
                if (loop == 0) {
                    if (is_term_opt)
                        num_term++;
                    else
                        num_normal++;
                }
                else
                    (*file)[count++] = vim_strsave (str);
            }
        }
        if (xp->xp_context != EXPAND_BOOL_SETTINGS && num_normal == 0) {
            for (opt_idx = 0; (str = get_termcode (opt_idx)) != NULL; opt_idx++) {
                if (!isprint (str[0]) || !isprint (str[1]))
                    continue;
                name_buf[0] = 't';
                name_buf[1] = '_';
                name_buf[2] = str[0];
                name_buf[3] = str[1];
                name_buf[4] = NUL;
                match = FALSE;
                if (vim_regexec (regmatch, name_buf, (colnr_T) 0))
                    match = TRUE;
                else {
                    name_buf[0] = '<';
                    name_buf[1] = 't';
                    name_buf[2] = '_';
                    name_buf[3] = str[0];
                    name_buf[4] = str[1];
                    name_buf[5] = '>';
                    name_buf[6] = NUL;
                    if (vim_regexec (regmatch, name_buf, (colnr_T) 0))
                        match = TRUE;
                }
                if (match) {
                    if (loop == 0)
                        num_term++;
                    else
                        (*file)[count++] = vim_strsave (name_buf);
                }
            }
            regmatch->rm_ic = TRUE;
            for (opt_idx = 0; (str = get_key_name (opt_idx)) != NULL; opt_idx++) {
                name_buf[0] = '<';
                STRCPY (name_buf + 1, str);
                STRCAT (name_buf, ">");
                if (vim_regexec (regmatch, name_buf, (colnr_T) 0)) {
                    if (loop == 0)
                        num_term++;
                    else
                        (*file)[count++] = vim_strsave (name_buf);
                }
            }
        }
        if (loop == 0) {
            if (num_normal > 0)
                *num_file = num_normal;
            else if (num_term > 0)
                *num_file = num_term;
            else
                return OK;
            *file = (char_u **) alloc ((unsigned ) (*num_file * sizeof (char_u *)));
            if (*file == NULL) {
                *file = (char_u **) "";
                return FAIL;
            }
        }
    }
    return OK;
}

void set_context_in_set_cmd (expand_T *xp, char_u *arg, int opt_flags) {
    int nextchar;
    long_u flags = 0;
    int opt_idx = 0;
    char_u *p;
    char_u *s;
    int is_term_option = FALSE;
    int key;
    expand_option_flags = opt_flags;
    xp->xp_context = EXPAND_SETTINGS;
    if (*arg == NUL) {
        xp->xp_pattern = arg;
        return;
    }
    p = arg + STRLEN (arg) - 1;
    if (*p == ' ' && *(p - 1) != '\\') {
        xp->xp_pattern = p + 1;
        return;
    }
    while (p > arg) {
        s = p;
        if (*p == ' ' || *p == ',') {
            while (s > arg && *(s - 1) == '\\')
                --s;
        }
        if (*p == ' ' && ((p - s) & 1) == 0) {
            ++p;
            break;
        }
        --p;
    }
    if (STRNCMP (p, "no", 2) == 0 && STRNCMP (p, "novice", 6) != 0) {
        xp->xp_context = EXPAND_BOOL_SETTINGS;
        p += 2;
    }
    if (STRNCMP (p, "inv", 3) == 0) {
        xp->xp_context = EXPAND_BOOL_SETTINGS;
        p += 3;
    }
    xp->xp_pattern = arg = p;
    if (*arg == '<') {
        while (*p != '>')
            if (*p++ == NUL)
                return;
        key = get_special_key_code (arg +1);
        if (key == 0) {
            xp->xp_context = EXPAND_NOTHING;
            return;
        }
        nextchar = *++p;
        is_term_option = TRUE;
        expand_option_name[2] = KEY2TERMCAP0 (key);
        expand_option_name[3] = KEY2TERMCAP1 (key);
    }
    else {
        if (p[0] == 't' && p[1] == '_') {
            p += 2;
            if (*p != NUL)
                ++p;
            if (*p == NUL)
                return;
            nextchar = *++p;
            is_term_option = TRUE;
            expand_option_name[2] = p[-2];
            expand_option_name[3] = p[-1];
        }
        else {
            while (ASCII_ISALNUM (*p) || *p == '_' || *p == '*')
                p++;
            if (*p == NUL)
                return;
            nextchar = *p;
            *p = NUL;
            opt_idx = findoption (arg);
            *p = nextchar;
            if (opt_idx == -1 || options[opt_idx].var == NULL) {
                xp->xp_context = EXPAND_NOTHING;
                return;
            }
            flags = options[opt_idx].flags;
            if (flags & P_BOOL) {
                xp->xp_context = EXPAND_NOTHING;
                return;
            }
        }
    }
    if ((nextchar == '-' || nextchar == '+' || nextchar == '^') && p[1] == '=') {
        ++p;
        nextchar = '=';
    }
    if ((nextchar != '=' && nextchar != ':') || xp->xp_context == EXPAND_BOOL_SETTINGS) {
        xp->xp_context = EXPAND_UNSUCCESSFUL;
        return;
    }
    if (xp->xp_context != EXPAND_BOOL_SETTINGS && p[1] == NUL) {
        xp->xp_context = EXPAND_OLD_SETTING;
        if (is_term_option)
            expand_option_idx = -1;
        else
            expand_option_idx = opt_idx;
        xp->xp_pattern = p + 1;
        return;
    }
    xp->xp_context = EXPAND_NOTHING;
    if (is_term_option || (flags & P_NUM))
        return;
    xp->xp_pattern = p + 1;
    if (flags & P_EXPAND) {
        p = options[opt_idx].var;
        if (p == (char_u *) &p_bdir || p == (char_u *) &p_dir || p == (char_u *) &p_path || p == (char_u *) &p_pp || p == (char_u *) &p_rtp || p == (char_u *) &p_cdpath || p == (char_u *) &p_vdir) {
            xp->xp_context = EXPAND_DIRECTORIES;
            if (p == (char_u *) &p_path || p == (char_u *) &p_cdpath)
                xp->xp_backslash = XP_BS_THREE;
            else
                xp->xp_backslash = XP_BS_ONE;
        }
        else {
            xp->xp_context = EXPAND_FILES;
            if (p == (char_u *) &p_tags)
                xp->xp_backslash = XP_BS_THREE;
            else
                xp->xp_backslash = XP_BS_ONE;
        }
    }
    for (p = arg + STRLEN (arg) - 1; p > xp->xp_pattern; --p) {
        if (*p == ' ' || *p == ',') {
            s = p;
            while (s > xp->xp_pattern && *(s - 1) == '\\')
                --s;
            if ((*p == ' ' && (xp->xp_backslash == XP_BS_THREE && (p - s) < 3)) || (*p == ',' && (flags & P_COMMA) && ((p - s) & 1) == 0)) {
                xp->xp_pattern = p + 1;
                break;
            }
        }
        if (options[opt_idx].var == (char_u *) &p_sps && STRNCMP (p, "file:", 5) == 0) {
            xp->xp_pattern = p + 5;
            break;
        }
    }
    return;
}

void set_iminsert_global (void) {
    p_iminsert = curbuf->b_p_iminsert;
}

void set_imsearch_global (void) {
    p_imsearch = curbuf->b_p_imsearch;
}

void init_gui_options (void) {
    if (!option_was_set ((char_u *) "bg") && STRCMP (p_bg, gui_bg_default ()) != 0) {
        set_option_value ((char_u *) "bg", 0L, gui_bg_default (), 0);
        highlight_changed ();
    }
}

void reset_option_was_set (char_u *name) {
    int idx = findoption (name);
    if (idx >= 0)
        options[idx].flags &= ~P_WAS_SET;
}

void set_term_defaults (void) {
    struct vimoption *p;
    for (p = &options[0]; p->fullname != NULL; p++) {
        if (istermoption (p) && p->def_val[VI_DEFAULT] != *(char_u**) (p->var)) {
            if (p->flags & P_DEF_ALLOCED) {
                free_string_option (p -> def_val [VI_DEFAULT]);
                p->flags &= ~P_DEF_ALLOCED;
            }
            p->def_val[VI_DEFAULT] = *(char_u**) (p->var);
            if (p->flags & P_ALLOCED) {
                p->flags |= P_DEF_ALLOCED;
                p->flags &= ~P_ALLOCED;
            }
        }
    }
}

static int check_opt_strings (char_u *val, char **values, int list) {
    return opt_strings_flags (val, values, NULL, list);
}

char_u *get_term_code (char_u *tname) {
    int opt_idx;
    char_u *varp;
    if (tname[0] != 't' || tname[1] != '_' || tname[2] == NUL || tname[3] == NUL)
        return NULL;
    if ((opt_idx = findoption (tname)) >= 0) {
        varp = get_varp (&(options[opt_idx]));
        if (varp != NULL)
            varp = *(char_u**) (varp);
        return varp;
    }
    return find_termcode (tname +2);
}

static int valid_filetype (char_u *val) {
    char_u *s;
    for (s = val; *s != NUL; ++s)
        if (!ASCII_ISALNUM (*s) && vim_strchr ((char_u *) ".-_", *s) == NULL)
            return FALSE;
    return TRUE;
}

static char_u *illegal_char (char_u *errbuf, int c) {
    if (errbuf == NULL)
        return (char_u *) "";
    sprintf ((char *) errbuf, _ ("E539: Illegal character <%s>"), (char *) transchar (c));
    return errbuf;
}

static void langmap_set (void) {
    char_u *p;
    char_u *p2;
    int from, to;
    langmap_init ();
    for (p = p_langmap; p[0] != NUL;) {
        for (p2 = p; p2[0] != NUL && p2[0] != ',' && p2[0] != ';'; MB_PTR_ADV (p2)) {
            if (p2[0] == '\\' && p2[1] != NUL)
                ++p2;
        }
        if (p2[0] == ';')
            ++p2;
        else
            p2 = NULL;
        while (p[0]) {
            if (p[0] == ',') {
                ++p;
                break;
            }
            if (p[0] == '\\' && p[1] != NUL)
                ++p;
            from = p[0];
            to = NUL;
            if (p2 == NULL) {
                MB_PTR_ADV (p);
                if (p[0] != ',') {
                    if (p[0] == '\\')
                        ++p;
                    to = p[0];
                }
            }
            else {
                if (p2[0] != ',') {
                    if (p2[0] == '\\')
                        ++p2;
                    to = p2[0];
                }
            }
            if (to == NUL) {
                EMSG2 (_ ("E357: 'langmap': Matching character missing for %s"), transchar (from));
                return;
            }
            langmap_mapchar[from & 255] = to;
            MB_PTR_ADV (p);
            if (p2 != NULL) {
                MB_PTR_ADV (p2);
                if (*p == ';') {
                    p = p2;
                    if (p[0] != NUL) {
                        if (p[0] != ',') {
                            EMSG2 (_ ("E358: 'langmap': Extra characters after semicolon: %s"), p);
                            return;
                        }
                        ++p;
                    }
                    break;
                }
            }
        }
    }
}

static void langmap_init (void) {
    int i;
    for (i = 0; i < 256; i++)
        langmap_mapchar[i] = i;
}

char_u *check_stl_option (char_u *s) {
    int itemcnt = 0;
    int groupdepth = 0;
    static char_u errbuf [80];
    while (*s && itemcnt < STL_MAX_ITEM) {
        while (*s && *s != '%')
            s++;
        if (!*s)
            break;
        s++;
        if (*s != '%' && *s != ')')
            ++itemcnt;
        if (*s == '%' || *s == STL_TRUNCMARK || *s == STL_MIDDLEMARK) {
            s++;
            continue;
        }
        if (*s == ')') {
            s++;
            if (--groupdepth < 0)
                break;
            continue;
        }
        if (*s == '-')
            s++;
        while (VIM_ISDIGIT (*s))
            s++;
        if (*s == STL_USER_HL)
            continue;
        if (*s == '.') {
            s++;
            while (*s && VIM_ISDIGIT (*s))
                s++;
        }
        if (*s == '(') {
            groupdepth++;
            continue;
        }
        if (vim_strchr (STL_ALL, *s) == NULL) {
            return illegal_char (errbuf, *s);
        }
        if (*s == '{') {
            s++;
            while (*s != '}' && *s)
                s++;
            if (*s != '}')
                return (char_u *) N_ ("E540: Unclosed expression sequence");
        }
    }
    if (itemcnt >= STL_MAX_ITEM)
        return (char_u *) N_ ("E541: too many items");
    if (groupdepth != 0)
        return (char_u *) N_ ("E542: unbalanced groups");
    return NULL;
}

int can_bs (int what) {
    switch (*p_bs) {
    case '2' :
        return TRUE;
    case '1' :
        return (what != BS_START);
    case '0' :
        return FALSE;
    }
    return vim_strchr (p_bs, what) != NULL;
}

long  get_sts_value (void) {
    return curbuf->b_p_sts < 0 ? get_sw_value (curbuf) : curbuf->b_p_sts;
}

char_u *get_equalprg (void) {
    if (*curbuf->b_p_ep == NUL)
        return p_ep;
    return curbuf->b_p_ep;
}

int check_ff_value (char_u *p) {
    return check_opt_strings (p, p_ff_values, FALSE);
}

int get_option_value (char_u *name, long  *numval, char_u **stringval, int opt_flags) {
    int opt_idx;
    char_u *varp;
    opt_idx = findoption (name);
    if (opt_idx < 0) {
        int key;
        if (STRLEN (name) == 4 && name[0] == 't' && name[1] == '_' && (key = find_key_option (name)) != 0) {
            char_u key_name [2];
            char_u *p;
            if (key < 0) {
                key_name[0] = KEY2TERMCAP0 (key);
                key_name[1] = KEY2TERMCAP1 (key);
            }
            else {
                key_name[0] = KS_KEY;
                key_name[1] = (key & 0xff);
            }
            p = find_termcode (key_name);
            if (p != NULL) {
                if (stringval != NULL)
                    *stringval = vim_strsave (p);
                return 0;
            }
        }
        return -3;
    }
    varp = get_varp_scope (&(options[opt_idx]), opt_flags);
    if (options[opt_idx].flags & P_STRING) {
        if (varp == NULL)
            return -2;
        if (stringval != NULL) {
            if ((char_u **) varp == &curbuf->b_p_key && **(char_u**) (varp) != NUL)
                *stringval = vim_strsave ((char_u *) "*****");
            else
                *stringval = vim_strsave (*(char_u**) (varp));
        }
        return 0;
    }
    if (varp == NULL)
        return -1;
    if (options[opt_idx].flags & P_NUM)
        *numval = *(long *) varp;
    else {
        if ((int *) varp == &curbuf->b_changed)
            *numval = curbufIsChanged ();
        else
            *numval = (long ) *(int*) varp;
    }
    return 1;
}

dict_T *get_winbuf_options (int bufopt) {
    dict_T *d;
    int opt_idx;
    d = dict_alloc ();
    if (d == NULL)
        return NULL;
    for (opt_idx = 0; !istermoption (&options[opt_idx]); opt_idx++) {
        struct vimoption *opt = &options[opt_idx];
        if ((bufopt && (opt->indir & PV_BUF)) || (!bufopt && (opt->indir & PV_WIN))) {
            char_u *varp = get_varp (opt);
            if (varp != NULL) {
                if (opt->flags & P_STRING)
                    dict_add_nr_str (d, opt->fullname, 0L, *(char_u**) varp);
                else if (opt->flags & P_NUM)
                    dict_add_nr_str (d, opt->fullname, *(long *) varp, NULL);
                else
                    dict_add_nr_str (d, opt->fullname, *(int*) varp, NULL);
            }
        }
    }
    return d;
}

