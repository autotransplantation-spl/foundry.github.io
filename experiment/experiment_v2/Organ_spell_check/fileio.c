
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
struct event_name {
    char *name;
    event_T event;
};
struct bw_info {
    int bw_fd;
    char_u *bw_buf;
    int bw_len;
    buf_T *bw_buffer;
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
EXTERN long  p_ur;
EXTERN win_T *firstwin;
EXTERN char_u *p_bdir;
EXTERN char_u *p_bex;
EXTERN char_u *p_bsk;
EXTERN int p_wb;
EXTERN char_u *p_pm;
EXTERN int p_bk;
EXTERN char_u *NameBuff;
EXTERN char *ignoredp;
EXTERN char_u e_interr [] INIT (= N_ ("Interrupted"));
EXTERN char_u *p_ffs;
EXTERN int p_ea;
EXTERN int p_ar;
int already_warned = FALSE;
EXTERN long  p_verbose;
EXTERN char_u *p_ei;
EXTERN int KeyTyped;
EXTERN char_u *vim_tempdir INIT (= NULL);
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
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
struct event_name event_names [] = {{"BufAdd", EVENT_BUFADD}, {"BufCreate", EVENT_BUFADD}, {"BufDelete", EVENT_BUFDELETE}, {"BufEnter", EVENT_BUFENTER}, {"BufFilePost", EVENT_BUFFILEPOST}, {"BufFilePre", EVENT_BUFFILEPRE}, {"BufHidden", EVENT_BUFHIDDEN}, {"BufLeave", EVENT_BUFLEAVE}, {"BufNew", EVENT_BUFNEW}, {"BufNewFile", EVENT_BUFNEWFILE}, {"BufRead", EVENT_BUFREADPOST}, {"BufReadCmd", EVENT_BUFREADCMD}, {"BufReadPost", EVENT_BUFREADPOST}, {"BufReadPre", EVENT_BUFREADPRE}, {"BufUnload", EVENT_BUFUNLOAD}, {"BufWinEnter", EVENT_BUFWINENTER}, {"BufWinLeave", EVENT_BUFWINLEAVE}, {"BufWipeout", EVENT_BUFWIPEOUT}, {"BufWrite", EVENT_BUFWRITEPRE}, {"BufWritePost", EVENT_BUFWRITEPOST}, {"BufWritePre", EVENT_BUFWRITEPRE}, {"BufWriteCmd", EVENT_BUFWRITECMD}, {"CmdlineChanged", EVENT_CMDLINECHANGED}, {"CmdlineEnter", EVENT_CMDLINEENTER}, {"CmdlineLeave", EVENT_CMDLINELEAVE}, {"CmdwinEnter", EVENT_CMDWINENTER}, {"CmdwinLeave", EVENT_CMDWINLEAVE}, {"CmdUndefined", EVENT_CMDUNDEFINED}, {"ColorScheme", EVENT_COLORSCHEME}, {"CompleteDone", EVENT_COMPLETEDONE}, {"CursorHold", EVENT_CURSORHOLD}, {"CursorHoldI", EVENT_CURSORHOLDI}, {"CursorMoved", EVENT_CURSORMOVED}, {"CursorMovedI", EVENT_CURSORMOVEDI}, {"DirChanged", EVENT_DIRCHANGED}, {"EncodingChanged", EVENT_ENCODINGCHANGED}, {"FileEncoding", EVENT_ENCODINGCHANGED}, {"FileAppendPost", EVENT_FILEAPPENDPOST}, {"FileAppendPre", EVENT_FILEAPPENDPRE}, {"FileAppendCmd", EVENT_FILEAPPENDCMD}, {"FileChangedShell", EVENT_FILECHANGEDSHELL}, {"FileChangedShellPost", EVENT_FILECHANGEDSHELLPOST}, {"FileChangedRO", EVENT_FILECHANGEDRO}, {"FileReadPost", EVENT_FILEREADPOST}, {"FileReadPre", EVENT_FILEREADPRE}, {"FileReadCmd", EVENT_FILEREADCMD}, {"FileType", EVENT_FILETYPE}, {"FileWritePost", EVENT_FILEWRITEPOST}, {"FileWritePre", EVENT_FILEWRITEPRE}, {"FileWriteCmd", EVENT_FILEWRITECMD}, {"FilterReadPost", EVENT_FILTERREADPOST}, {"FilterReadPre", EVENT_FILTERREADPRE}, {"FilterWritePost", EVENT_FILTERWRITEPOST}, {"FilterWritePre", EVENT_FILTERWRITEPRE}, {"FocusGained", EVENT_FOCUSGAINED}, {"FocusLost", EVENT_FOCUSLOST}, {"FuncUndefined", EVENT_FUNCUNDEFINED}, {"GUIEnter", EVENT_GUIENTER}, {"GUIFailed", EVENT_GUIFAILED}, {"InsertChange", EVENT_INSERTCHANGE}, {"InsertEnter", EVENT_INSERTENTER}, {"InsertLeave", EVENT_INSERTLEAVE}, {"InsertCharPre", EVENT_INSERTCHARPRE}, {"MenuPopup", EVENT_MENUPOPUP}, {"OptionSet", EVENT_OPTIONSET}, {"QuickFixCmdPost", EVENT_QUICKFIXCMDPOST}, {"QuickFixCmdPre", EVENT_QUICKFIXCMDPRE}, {"QuitPre", EVENT_QUITPRE}, {"RemoteReply", EVENT_REMOTEREPLY}, {"SessionLoadPost", EVENT_SESSIONLOADPOST}, {"ShellCmdPost", EVENT_SHELLCMDPOST}, {"ShellFilterPost", EVENT_SHELLFILTERPOST}, {"SourcePre", EVENT_SOURCEPRE}, {"SourceCmd", EVENT_SOURCECMD}, {"SpellFileMissing", EVENT_SPELLFILEMISSING}, {"StdinReadPost", EVENT_STDINREADPOST}, {"StdinReadPre", EVENT_STDINREADPRE}, {"SwapExists", EVENT_SWAPEXISTS}, {"Syntax", EVENT_SYNTAX}, {"TabNew", EVENT_TABNEW}, {"TabClosed", EVENT_TABCLOSED}, {"TabEnter", EVENT_TABENTER}, {"TabLeave", EVENT_TABLEAVE}, {"TermChanged", EVENT_TERMCHANGED}, {"TermResponse", EVENT_TERMRESPONSE}, {"TextChanged", EVENT_TEXTCHANGED}, {"TextChangedI", EVENT_TEXTCHANGEDI}, {"TextChangedP", EVENT_TEXTCHANGEDP}, {"User", EVENT_USER}, {"VimEnter", EVENT_VIMENTER}, {"VimLeave", EVENT_VIMLEAVE}, {"VimLeavePre", EVENT_VIMLEAVEPRE}, {"WinNew", EVENT_WINNEW}, {"WinEnter", EVENT_WINENTER}, {"WinLeave", EVENT_WINLEAVE}, {"VimResized", EVENT_VIMRESIZED}, {"TextYankPost", EVENT_TEXTYANKPOST}, {NULL, (event_T) 0}};
EXTERN int p_guipty;
EXTERN char_u e_patnotf2 [] INIT (= N_ ("E486: Pattern not found: %s"));
EXTERN char_u e_patnotf [] INIT (= N_ ("Pattern not found"));
EXTERN char_u e_nogroup [] INIT (= N_ ("E28: No such highlight group name: %s"));
EXTERN win_T *lastwin;
EXTERN char_u *p_path;
int last_group;
event_T last_event;
char_u *deleted_augroup = NULL;
garray_T augroups = {0, 0, sizeof (char_u *), 10, NULL};
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
int include_groups = FALSE;
int autocmd_nested = FALSE;
int autocmd_blocked = 0;
int au_need_clean = FALSE;
AutoPatCmd *active_apc_list = NULL;
int default_reload_choice = 0;
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
int current_augroup = AUGROUP_DEFAULT;
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
char_u *old_termresponse = NULL;
char *e_auchangedbuf = N_ ("E812: Autocommands changed buffer or buffer name");
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
long  temp_count = 0;
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
AutoPat *last_autopat [NUM_EVENTS] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
AutoPat *first_autopat [NUM_EVENTS] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
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

char_u *vim_tempname (int extra_char, int keep) {
    char_u itmp [TEMPNAMELEN];
    static char * (tempdirs []) = {TEMPDIRNAMES};
    int i;
    stat_T st;
    if (vim_tempdir == NULL) {
        for (i = 0; i < (int) (sizeof (tempdirs) / sizeof (char *)); ++i) {
            size_t itmplen;
            long  nr;
            long  off;
            expand_env ((char_u *) tempdirs [i], itmp, TEMPNAMELEN - 20);
            if (itmp[0] != '$' && mch_isdir (itmp)) {
                add_pathsep (itmp);
                nr = (mch_get_pid () + (long ) time (NULL)) % 1000000L;
                itmplen = STRLEN (itmp);
                for (off = 0; off < 10000L; ++off) {
                    int r;
                    mode_t umask_save;
                    sprintf ((char *) itmp + itmplen, "v%ld", nr + off);
                    if (mch_stat ((char *) itmp, &st) >= 0)
                        continue;
                    umask_save = umask (077);
                    r = vim_mkdir (itmp, 0700);
                    (void) umask (umask_save);
                    if (r == 0) {
                        vim_settempdir (itmp);
                        break;
                    }
                    break;
                }
                if (vim_tempdir != NULL)
                    break;
            }
        }
    }
    if (vim_tempdir != NULL) {
        sprintf ((char *) itmp, "%s%ld", vim_tempdir, temp_count ++);
        return vim_strsave (itmp);
    }
    return NULL;
}

void block_autocmds (void) {
    if (autocmd_blocked == 0)
        old_termresponse = get_vim_var_str (VV_TERMRESPONSE);
    ++autocmd_blocked;
}

int apply_autocmds (event_T event, char_u *fname, char_u *fname_io, int force, buf_T *buf) {
    return apply_autocmds_group (event, fname, fname_io, force, AUGROUP_ALL, buf, NULL);
}

static int apply_autocmds_group (event_T event, char_u *fname, char_u *fname_io, int force, int group, buf_T *buf, exarg_T *eap) {
    char_u *sfname = NULL;
    char_u *tail;
    int save_changed;
    buf_T *old_curbuf;
    int retval = FALSE;
    char_u *save_sourcing_name;
    linenr_T save_sourcing_lnum;
    char_u *save_autocmd_fname;
    int save_autocmd_fname_full;
    int save_autocmd_bufnr;
    char_u *save_autocmd_match;
    int save_autocmd_busy;
    int save_autocmd_nested;
    static int nesting = 0;
    AutoPatCmd patcmd;
    AutoPat *ap;
    scid_T save_current_SID;
    void *save_funccalp;
    char_u *save_cmdarg;
    long  save_cmdbang;
    static int filechangeshell_busy = FALSE;
    proftime_T wait_time;
    int did_save_redobuff = FALSE;
    save_redo_T save_redo;
    int save_KeyTyped = KeyTyped;
    if (event == NUM_EVENTS || first_autopat[(int) event] == NULL || autocmd_blocked > 0)
        goto BYPASS_AU;
    if (autocmd_busy && !(force || autocmd_nested))
        goto BYPASS_AU;
    if (aborting ())
        goto BYPASS_AU;
    if (filechangeshell_busy && (event == EVENT_FILECHANGEDSHELL || event == EVENT_FILECHANGEDSHELLPOST))
        goto BYPASS_AU;
    if (event_ignored (event))
        goto BYPASS_AU;
    if (nesting == 10) {
        EMSG (_ ("E218: autocommand nesting too deep"));
        goto BYPASS_AU;
    }
    if ((autocmd_no_enter && (event == EVENT_WINENTER || event == EVENT_BUFENTER)) || (autocmd_no_leave && (event == EVENT_WINLEAVE || event == EVENT_BUFLEAVE)))
        goto BYPASS_AU;
    save_autocmd_fname = autocmd_fname;
    save_autocmd_fname_full = autocmd_fname_full;
    save_autocmd_bufnr = autocmd_bufnr;
    save_autocmd_match = autocmd_match;
    save_autocmd_busy = autocmd_busy;
    save_autocmd_nested = autocmd_nested;
    save_changed = curbuf->b_changed;
    old_curbuf = curbuf;
    if (fname_io == NULL) {
        if (event == EVENT_COLORSCHEME || event == EVENT_OPTIONSET)
            autocmd_fname = NULL;
        else if (fname != NULL && !ends_excmd (*fname))
            autocmd_fname = fname;
        else if (buf != NULL)
            autocmd_fname = buf->b_ffname;
        else
            autocmd_fname = NULL;
    }
    else
        autocmd_fname = fname_io;
    if (autocmd_fname != NULL)
        autocmd_fname = vim_strsave (autocmd_fname);
    autocmd_fname_full = FALSE;
    if (buf == NULL)
        autocmd_bufnr = 0;
    else
        autocmd_bufnr = buf->b_fnum;
    if (fname == NULL || *fname == NUL) {
        if (buf == NULL)
            fname = NULL;
        else {
            if (event == EVENT_SYNTAX)
                fname = buf->b_p_syn;
            else if (event == EVENT_FILETYPE)
                fname = buf->b_p_ft;
            else {
                if (buf->b_sfname != NULL)
                    sfname = vim_strsave (buf->b_sfname);
                fname = buf->b_ffname;
            }
        }
        if (fname == NULL)
            fname = (char_u *) "";
        fname = vim_strsave (fname);
    }
    else {
        sfname = vim_strsave (fname);
        if (event == EVENT_FILETYPE || event == EVENT_SYNTAX || event == EVENT_FUNCUNDEFINED || event == EVENT_REMOTEREPLY || event == EVENT_SPELLFILEMISSING || event == EVENT_QUICKFIXCMDPRE || event == EVENT_COLORSCHEME || event == EVENT_OPTIONSET || event == EVENT_QUICKFIXCMDPOST || event == EVENT_DIRCHANGED)
            fname = vim_strsave (fname);
        else
            fname = FullName_save (fname, FALSE);
    }
    if (fname == NULL) {
        vim_free (sfname);
        retval = FALSE;
        goto BYPASS_AU;
    }
    autocmd_match = fname;
    ++RedrawingDisabled;
    save_sourcing_name = sourcing_name;
    sourcing_name = NULL;
    save_sourcing_lnum = sourcing_lnum;
    sourcing_lnum = 0;
    save_current_SID = current_SID;
    if (do_profiling == PROF_YES)
        prof_child_enter (&wait_time);
    save_funccalp = save_funccal ();
    if (!autocmd_busy) {
        save_search_patterns ();
        if (!ins_compl_active ()) {
            saveRedobuff (& save_redo);
            did_save_redobuff = TRUE;
        }
        did_filetype = keep_filetype;
    }
    autocmd_busy = TRUE;
    filechangeshell_busy = (event == EVENT_FILECHANGEDSHELL);
    ++nesting;
    if (event == EVENT_FILETYPE)
        did_filetype = TRUE;
    tail = gettail (fname);
    patcmd.curpat = first_autopat[(int) event];
    patcmd.nextcmd = NULL;
    patcmd.group = group;
    patcmd.fname = fname;
    patcmd.sfname = sfname;
    patcmd.tail = tail;
    patcmd.event = event;
    patcmd.arg_bufnr = autocmd_bufnr;
    patcmd.next = NULL;
    auto_next_pat (& patcmd, FALSE);
    if (patcmd.curpat != NULL) {
        patcmd.next = active_apc_list;
        active_apc_list = &patcmd;
        save_cmdbang = (long ) get_vim_var_nr (VV_CMDBANG);
        if (eap != NULL) {
            save_cmdarg = set_cmdarg (eap, NULL);
            set_vim_var_nr (VV_CMDBANG, (long) eap -> forceit);
        }
        else
            save_cmdarg = NULL;
        retval = TRUE;
        for (ap = patcmd.curpat; ap->next != NULL; ap = ap->next)
            ap->last = FALSE;
        ap->last = TRUE;
        check_lnums (TRUE);
        do_cmdline (NULL, getnextac, (void *) & patcmd, DOCMD_NOWAIT | DOCMD_VERBOSE | DOCMD_REPEAT);
        if (eap != NULL) {
            (void) set_cmdarg (NULL, save_cmdarg);
            set_vim_var_nr (VV_CMDBANG, save_cmdbang);
        }
        if (active_apc_list == &patcmd)
            active_apc_list = patcmd.next;
    }
    --RedrawingDisabled;
    autocmd_busy = save_autocmd_busy;
    filechangeshell_busy = FALSE;
    autocmd_nested = save_autocmd_nested;
    vim_free (sourcing_name);
    sourcing_name = save_sourcing_name;
    sourcing_lnum = save_sourcing_lnum;
    vim_free (autocmd_fname);
    autocmd_fname = save_autocmd_fname;
    autocmd_fname_full = save_autocmd_fname_full;
    autocmd_bufnr = save_autocmd_bufnr;
    autocmd_match = save_autocmd_match;
    current_SID = save_current_SID;
    restore_funccal (save_funccalp);
    if (do_profiling == PROF_YES)
        prof_child_exit (&wait_time);
    KeyTyped = save_KeyTyped;
    vim_free (fname);
    vim_free (sfname);
    --nesting;
    if (!autocmd_busy) {
        restore_search_patterns ();
        if (did_save_redobuff)
            restoreRedobuff (&save_redo);
        did_filetype = FALSE;
        while (au_pending_free_buf != NULL) {
            buf_T *b = au_pending_free_buf->b_next;
            vim_free (au_pending_free_buf);
            au_pending_free_buf = b;
        }
        while (au_pending_free_win != NULL) {
            win_T *w = au_pending_free_win->w_next;
            vim_free (au_pending_free_win);
            au_pending_free_win = w;
        }
    }
    if (curbuf == old_curbuf && (event == EVENT_BUFREADPOST || event == EVENT_BUFWRITEPOST || event == EVENT_FILEAPPENDPOST || event == EVENT_VIMLEAVE || event == EVENT_VIMLEAVEPRE)) {
        if (curbuf->b_changed != save_changed)
            need_maketitle = TRUE;
        curbuf->b_changed = save_changed;
    }
    au_cleanup ();
BYPASS_AU :
    if (event == EVENT_BUFWIPEOUT && buf != NULL)
        aubuflocal_remove (buf);
    if (retval == OK && event == EVENT_FILETYPE)
        au_did_filetype = TRUE;
    return retval;
}

static int event_ignored (event_T event) {
    char_u *p = p_ei;
    while (*p != NUL) {
        if (STRNICMP (p, "all", 3) == 0 && (p[3] == NUL || p[3] == ','))
            return TRUE;
        if (event_name2nr (p, &p) == event)
            return TRUE;
    }
    return FALSE;
}

static event_T event_name2nr (char_u *start, char_u **end) {
    char_u *p;
    int i;
    int len;
    for (p = start; *p && !VIM_ISWHITE (*p) && *p != ',' && *p != '|'; ++p)
        ;
    for (i = 0; event_names[i].name != NULL; ++i) {
        len = (int) STRLEN (event_names[i].name);
        if (len == p - start && STRNICMP (event_names[i].name, start, len) == 0)
            break;
    }
    if (*p == ',')
        ++p;
    *end = p;
    if (event_names[i].name == NULL)
        return NUM_EVENTS;
    return event_names[i].event;
}

static void auto_next_pat (AutoPatCmd *apc, int stop_at_last) {
    AutoPat *ap;
    AutoCmd *cp;
    char_u *name;
    char *s;
    VIM_CLEAR (sourcing_name);
    for (ap = apc->curpat; ap != NULL && !got_int; ap = ap->next) {
        apc->curpat = NULL;
        if (ap->pat != NULL && ap->cmds != NULL && (apc->group == AUGROUP_ALL || apc->group == ap->group)) {
            if (ap->buflocal_nr == 0 ? (match_file_pat (NULL, &ap->reg_prog, apc->fname, apc->sfname, apc->tail, ap->allow_dirs)) : ap->buflocal_nr == apc->arg_bufnr) {
                name = event_nr2name (apc->event);
                s = _ ("%s Auto commands for \"%s\"");
                sourcing_name = alloc ((unsigned ) (STRLEN (s) + STRLEN (name) + ap->patlen + 1));
                if (sourcing_name != NULL) {
                    sprintf ((char *) sourcing_name, s, (char *) name, (char *) ap -> pat);
                    if (p_verbose >= 8) {
                        verbose_enter ();
                        smsg ((char_u *) _ ("Executing %s"), sourcing_name);
                        verbose_leave ();
                    }
                }
                apc->curpat = ap;
                apc->nextcmd = ap->cmds;
                for (cp = ap->cmds; cp->next != NULL; cp = cp->next)
                    cp->last = FALSE;
                cp->last = TRUE;
            }
            line_breakcheck ();
            if (apc->curpat != NULL)
                break;
        }
        if (stop_at_last && ap->last)
            break;
    }
}

static int match_file_pat (char_u *pattern, regprog_T **prog, char_u *fname, char_u *sfname, char_u *tail, int allow_dirs) {
    regmatch_T regmatch;
    int result = FALSE;
    regmatch.rm_ic = p_fic;
    if (prog != NULL)
        regmatch.regprog = *prog;
    else
        regmatch.regprog = vim_regcomp (pattern, RE_MAGIC);
    if (regmatch.regprog != NULL && ((allow_dirs && (vim_regexec (&regmatch, fname, (colnr_T) 0) || (sfname != NULL && vim_regexec (&regmatch, sfname, (colnr_T) 0)))) || (!allow_dirs && vim_regexec (&regmatch, tail, (colnr_T) 0))))
        result = TRUE;
    if (prog != NULL)
        *prog = regmatch.regprog;
    else
        vim_regfree (regmatch.regprog);
    return result;
}

static char_u *event_nr2name (event_T event) {
    int i;
    for (i = 0; event_names[i].name != NULL; ++i)
        if (event_names[i].event == event)
            return (char_u *) event_names[i].name;
    return (char_u *) "Unknown";
}

char_u *file_pat_to_reg_pat (char_u *pat, char_u *pat_end, char *allow_dirs, int no_bslash) {
    int size = 2;
    char_u *endp;
    char_u *reg_pat;
    char_u *p;
    int i;
    int nested = 0;
    int add_dollar = TRUE;
    if (allow_dirs != NULL)
        *allow_dirs = FALSE;
    if (pat_end == NULL)
        pat_end = pat + STRLEN (pat);
    for (p = pat; p < pat_end; p++) {
        switch (*p) {
        case '*' :
        case '.' :
        case ',' :
        case '{' :
        case '}' :
        case '~' :
            size += 2;
            break;
        default :
            size++;
            break;
        }
    }
    reg_pat = alloc (size +1);
    if (reg_pat == NULL)
        return NULL;
    i = 0;
    if (pat[0] == '*')
        while (pat[0] == '*' && pat < pat_end - 1)
            pat++;
        else
            reg_pat[i++] = '^';
    endp = pat_end - 1;
    if (endp >= pat && *endp == '*') {
        while (endp - pat > 0 && *endp == '*')
            endp--;
        add_dollar = FALSE;
    }
    for (p = pat; *p && nested >= 0 && p <= endp; p++) {
        switch (*p) {
        case '*' :
            reg_pat[i++] = '.';
            reg_pat[i++] = '*';
            while (p[1] == '*')
                ++p;
            break;
        case '.' :
        case '~' :
            reg_pat[i++] = '\\';
            reg_pat[i++] = *p;
            break;
        case '?' :
            reg_pat[i++] = '.';
            break;
        case '\\' :
            if (p[1] == NUL)
                break;
            if (*++p == '?')
                reg_pat[i++] = '?';
            else if (*p == ',' || *p == '%' || *p == '#' || vim_isspace (*p) || *p == '{' || *p == '}')
                reg_pat[i++] = *p;
            else if (*p == '\\' && p[1] == '\\' && p[2] == '{') {
                reg_pat[i++] = '\\';
                reg_pat[i++] = '{';
                p += 2;
            }
            else {
                if (allow_dirs != NULL && vim_ispathsep (*p))
                    *allow_dirs = TRUE;
                reg_pat[i++] = '\\';
                reg_pat[i++] = *p;
            }
            break;
        case '{' :
            reg_pat[i++] = '\\';
            reg_pat[i++] = '(';
            nested++;
            break;
        case '}' :
            reg_pat[i++] = '\\';
            reg_pat[i++] = ')';
            --nested;
            break;
        case ',' :
            if (nested) {
                reg_pat[i++] = '\\';
                reg_pat[i++] = '|';
            }
            else
                reg_pat[i++] = ',';
            break;
        default :
            if (allow_dirs != NULL && vim_ispathsep (*p))
                *allow_dirs = TRUE;
            reg_pat[i++] = *p;
            break;
        }
    }
    if (add_dollar)
        reg_pat[i++] = '$';
    reg_pat[i] = NUL;
    if (nested != 0) {
        if (nested < 0)
            EMSG (_ ("E219: Missing {."));
        else
            EMSG (_ ("E220: Missing }."));
        VIM_CLEAR (reg_pat);
    }
    return reg_pat;
}

char_u *shorten_fname (char_u *full_path, char_u *dir_name) {
    int len;
    char_u *p;
    if (full_path == NULL)
        return NULL;
    len = (int) STRLEN (dir_name);
    if (fnamencmp (dir_name, full_path, len) == 0) {
        p = full_path + len;
        {
            if (vim_ispathsep (*p))
                ++p;
            else
                p = NULL;
        }
    }
    else
        p = NULL;
    return p;
}

void buf_store_time (buf_T *buf, stat_T *st, char_u *fname) {
    buf->b_mtime = (long ) st->st_mtime;
    buf->b_orig_size = st->st_size;
    buf->b_orig_mode = mch_getperm (fname);
}

int check_timestamps (int focus) {
    buf_T *buf;
    int didit = 0;
    int n;
    if (no_check_timestamps > 0)
        return FALSE;
    if (focus && did_check_timestamps) {
        need_check_timestamps = TRUE;
        return FALSE;
    }
    if (!stuff_empty () || global_busy || !typebuf_typed () || autocmd_busy || curbuf_lock > 0 || allbuf_lock > 0)
        need_check_timestamps = TRUE;
    else {
        ++no_wait_return;
        did_check_timestamps = TRUE;
        already_warned = FALSE;
        default_reload_choice = 0;
        FOR_ALL_BUFFERS (buf) {
            if (buf->b_nwindows > 0) {
                bufref_T bufref;
                set_bufref (& bufref, buf);
                n = buf_check_timestamp (buf, focus);
                if (didit < n)
                    didit = n;
                if (n > 0 && !bufref_valid (&bufref)) {
                    buf = firstbuf;
                    continue;
                }
            }
        }
        default_reload_choice = 0;
        --no_wait_return;
        need_check_timestamps = FALSE;
        if (need_wait_return && didit == 2) {
            msg_puts ((char_u *) "\n");
            out_flush ();
        }
    }
    return didit;
}

int buf_check_timestamp (buf_T *buf, int focus) {
    stat_T st;
    int stat_res;
    int retval = 0;
    char_u *path;
    char_u *tbuf;
    char *mesg = NULL;
    char *mesg2 = "";
    int helpmesg = FALSE;
    int reload = FALSE;
    char *reason;
    int can_reload = FALSE;
    off_T orig_size = buf->b_orig_size;
    int orig_mode = buf->b_orig_mode;
    int save_mouse_correct = need_mouse_correct;
    static int busy = FALSE;
    int n;
    char_u *s;
    bufref_T bufref;
    set_bufref (& bufref, buf);
    if (buf->b_ffname == NULL || buf->b_ml.ml_mfp == NULL || *buf->b_p_bt != NUL || buf->b_saving || busy || isNetbeansBuffer (buf) || buf->b_term != NULL)
        return 0;
    if (!(buf->b_flags & BF_NOTEDITED) && buf->b_mtime != 0 && ((stat_res = mch_stat ((char *) buf->b_ffname, &st)) < 0 || time_differs ((long ) st.st_mtime, buf->b_mtime) || st.st_size != buf->b_orig_size || mch_getperm (buf->b_ffname) != buf->b_orig_mode)) {
        retval = 1;
        if (stat_res < 0) {
            buf->b_mtime = 0;
            buf->b_orig_size = 0;
            buf->b_orig_mode = 0;
        }
        else
            buf_store_time (buf, &st, buf->b_ffname);
        if (mch_isdir (buf->b_fname))
            ;
        else if ((buf->b_p_ar >= 0 ? buf->b_p_ar : p_ar) && !bufIsChanged (buf) && stat_res >= 0)
            reload = TRUE;
        else {
            if (stat_res < 0)
                reason = "deleted";
            else if (bufIsChanged (buf))
                reason = "conflict";
            else if (orig_size != buf->b_orig_size || buf_contents_changed (buf))
                reason = "changed";
            else if (orig_mode != buf->b_orig_mode)
                reason = "mode";
            else
                reason = "time";
            busy = TRUE;
            set_vim_var_string (VV_FCS_REASON, (char_u *) reason, - 1);
            set_vim_var_string (VV_FCS_CHOICE, (char_u *) "", - 1);
            ++allbuf_lock;
            n = apply_autocmds (EVENT_FILECHANGEDSHELL, buf->b_fname, buf->b_fname, FALSE, buf);
            --allbuf_lock;
            busy = FALSE;
            if (n) {
                if (!bufref_valid (&bufref))
                    EMSG (_ ("E246: FileChangedShell autocommand deleted buffer"));
                s = get_vim_var_str (VV_FCS_CHOICE);
                if (STRCMP (s, "reload") == 0 && *reason != 'd')
                    reload = TRUE;
                else if (STRCMP (s, "ask") == 0)
                    n = FALSE;
                else
                    return 2;
            }
            if (!n) {
                if (*reason == 'd')
                    mesg = _ ("E211: File \"%s\" no longer available");
                else {
                    helpmesg = TRUE;
                    can_reload = TRUE;
                    if (reason[2] == 'n') {
                        mesg = _ ("W12: Warning: File \"%s\" has changed and the buffer was changed in Vim as well");
                        mesg2 = _ ("See \":help W12\" for more info.");
                    }
                    else if (reason[1] == 'h') {
                        mesg = _ ("W11: Warning: File \"%s\" has changed since editing started");
                        mesg2 = _ ("See \":help W11\" for more info.");
                    }
                    else if (*reason == 'm') {
                        mesg = _ ("W16: Warning: Mode of file \"%s\" has changed since editing started");
                        mesg2 = _ ("See \":help W16\" for more info.");
                    }
                    else
                        buf->b_mtime_read = buf->b_mtime;
                }
            }
        }
    }
    else if ((buf->b_flags & BF_NEW) && !(buf->b_flags & BF_NEW_W) && vim_fexists (buf->b_ffname)) {
        retval = 1;
        mesg = _ ("W13: Warning: File \"%s\" has been created after editing started");
        buf->b_flags |= BF_NEW_W;
        can_reload = TRUE;
    }
    if (mesg != NULL) {
        path = home_replace_save (buf, buf->b_fname);
        if (path != NULL) {
            if (!helpmesg)
                mesg2 = "";
            tbuf = alloc ((unsigned ) (STRLEN (path) + STRLEN (mesg) + STRLEN (mesg2) + 2));
            sprintf ((char *) tbuf, mesg, path);
            set_vim_var_string (VV_WARNINGMSG, tbuf, - 1);
            if (can_reload) {
                if (*mesg2 != NUL) {
                    STRCAT (tbuf, "\n");
                    STRCAT (tbuf, mesg2);
                }
                if (default_reload_choice > 0) {
                    if (default_reload_choice == 2)
                        reload = TRUE;
                }
                else {
                    switch (do_dialog (VIM_WARNING, (char_u *) _ ("Warning"), tbuf, (char_u *) _ ("&OK\n&Load File\nLoad &All\n&Ignore All"), 1, NULL, TRUE)) {
                    case 3 :
                        default_reload_choice = 2;
                    case 2 :
                        reload = TRUE;
                        break;
                    case 4 :
                        default_reload_choice = 1;
                        break;
                    }
                }
            }
            else if (State > NORMAL_BUSY || (State & CMDLINE) || already_warned) {
                if (*mesg2 != NUL) {
                    STRCAT (tbuf, "; ");
                    STRCAT (tbuf, mesg2);
                }
                EMSG (tbuf);
                retval = 2;
            }
            else {
                if (!autocmd_busy) {
                    msg_start ();
                    msg_puts_attr (tbuf, HL_ATTR (HLF_E) + MSG_HIST);
                    if (*mesg2 != NUL)
                        msg_puts_attr ((char_u *) mesg2, HL_ATTR (HLF_W) +MSG_HIST);
                    msg_clr_eos ();
                    (void) msg_end ();
                    if (emsg_silent == 0) {
                        out_flush ();
                        if (!focus)
                            ui_delay (1000L, TRUE);
                        redraw_cmdline = FALSE;
                    }
                }
                already_warned = TRUE;
            }
            vim_free (path);
            vim_free (tbuf);
        }
    }
    if (reload) {
        buf_reload (buf, orig_mode);
        if (buf->b_p_udf && buf->b_ffname != NULL) {
            char_u hash [UNDO_HASH_SIZE];
            buf_T *save_curbuf = curbuf;
            curbuf = buf;
            u_compute_hash (hash);
            u_write_undo (NULL, FALSE, buf, hash);
            curbuf = save_curbuf;
        }
    }
    if (bufref_valid (&bufref) && retval != 0)
        (void) apply_autocmds (EVENT_FILECHANGEDSHELLPOST, buf->b_fname, buf->b_fname, FALSE, buf);
    need_mouse_correct = save_mouse_correct;
    return retval;
}

static int time_differs (long  t1, long  t2) {
    return (t1 != t2);
}

void aubuflocal_remove (buf_T *buf) {
    AutoPat *ap;
    event_T event;
    AutoPatCmd *apc;
    for (apc = active_apc_list; apc; apc = apc->next)
        if (buf->b_fnum == apc->arg_bufnr)
            apc->arg_bufnr = 0;
    for (event = (event_T) 0; (int) event < (int) NUM_EVENTS; event = (event_T) ((int) event + 1))
        for (ap = first_autopat[(int) event]; ap != NULL; ap = ap->next)
            if (ap->buflocal_nr == buf->b_fnum) {
                au_remove_pat (ap);
                if (p_verbose >= 6) {
                    verbose_enter ();
                    smsg ((char_u *) _ ("auto-removing autocommand: %s <buffer=%d>"), event_nr2name (event), buf -> b_fnum);
                    verbose_leave ();
                }
            }
    au_cleanup ();
}

static void au_remove_pat (AutoPat *ap) {
    VIM_CLEAR (ap -> pat);
    ap->buflocal_nr = -1;
    au_need_clean = TRUE;
}

static void au_cleanup (void) {
    AutoPat *ap, **prev_ap;
    AutoCmd *ac, **prev_ac;
    event_T event;
    if (autocmd_busy || !au_need_clean)
        return;
    for (event = (event_T) 0; (int) event < (int) NUM_EVENTS; event = (event_T) ((int) event + 1)) {
        prev_ap = &(first_autopat[(int) event]);
        for (ap = *prev_ap; ap != NULL; ap = *prev_ap) {
            prev_ac = &(ap->cmds);
            for (ac = *prev_ac; ac != NULL; ac = *prev_ac) {
                if (ap->pat == NULL || ac->cmd == NULL) {
                    *prev_ac = ac->next;
                    vim_free (ac -> cmd);
                    vim_free (ac);
                }
                else
                    prev_ac = &(ac->next);
            }
            if (ap->pat == NULL) {
                if (ap->next == NULL) {
                    if (prev_ap == &(first_autopat[(int) event]))
                        last_autopat[(int) event] = NULL;
                    else
                        last_autopat[(int) event] = (AutoPat *) prev_ap;
                }
                *prev_ap = ap->next;
                vim_regfree (ap -> reg_prog);
                vim_free (ap);
            }
            else
                prev_ap = &(ap->next);
        }
    }
    au_need_clean = FALSE;
}

void shorten_fnames (int force) {
    char_u dirname [MAXPATHL];
    buf_T *buf;
    char_u *p;
    mch_dirname (dirname, MAXPATHL);
    FOR_ALL_BUFFERS (buf) {
        if (buf->b_fname != NULL && !bt_nofile (buf) && !path_with_url (buf->b_fname) && (force || buf->b_sfname == NULL || mch_isFullName (buf->b_sfname))) {
            VIM_CLEAR (buf -> b_sfname);
            p = shorten_fname (buf->b_ffname, dirname);
            if (p != NULL) {
                buf->b_sfname = vim_strsave (p);
                buf->b_fname = buf->b_sfname;
            }
            if (p == NULL || buf->b_fname == NULL)
                buf->b_fname = buf->b_ffname;
        }
        mf_fullname (buf -> b_ml.ml_mfp);
    }
    status_redraw_all ();
    redraw_tabline = TRUE;
}

void unblock_autocmds (void) {
    --autocmd_blocked;
    if (autocmd_blocked == 0 && get_vim_var_str (VV_TERMRESPONSE) != old_termresponse)
        apply_autocmds (EVENT_TERMRESPONSE, NULL, NULL, FALSE, curbuf);
}

int prep_exarg (exarg_T *eap, buf_T *buf) {
    eap->cmd = alloc ((unsigned ) (STRLEN (buf->b_p_ff) + 15));
    if (eap->cmd == NULL)
        return FAIL;
    sprintf ((char *) eap -> cmd, "e ++ff=%s", buf -> b_p_ff);
    eap->force_ff = 7;
    eap->force_bin = buf->b_p_bin ? FORCE_BIN : FORCE_NOBIN;
    eap->read_edit = FALSE;
    eap->forceit = FALSE;
    return OK;
}

void aucmd_prepbuf (aco_save_T *aco, buf_T *buf) {
    win_T *win;
    int save_ea;
    int save_acd;
    if (buf == curbuf)
        win = curwin;
    else
        FOR_ALL_WINDOWS (win)
            if (win->w_buffer == buf)
                break;
    if (win == NULL && aucmd_win == NULL) {
        win_alloc_aucmd_win ();
        if (aucmd_win == NULL)
            win = curwin;
    }
    if (win == NULL && aucmd_win_used)
        win = curwin;
    aco->save_curwin = curwin;
    aco->save_curbuf = curbuf;
    if (win != NULL) {
        aco->use_aucmd_win = FALSE;
        curwin = win;
    }
    else {
        aco->use_aucmd_win = TRUE;
        aucmd_win_used = TRUE;
        aucmd_win->w_buffer = buf;
        aucmd_win->w_s = &buf->b_s;
        ++buf->b_nwindows;
        win_init_empty (aucmd_win);
        VIM_CLEAR (aucmd_win -> w_localdir);
        aco->globaldir = globaldir;
        globaldir = NULL;
        block_autocmds ();
        make_snapshot (SNAP_AUCMD_IDX);
        save_ea = p_ea;
        p_ea = FALSE;
        save_acd = p_acd;
        p_acd = FALSE;
        (void) win_split_ins (0, WSP_TOP, aucmd_win, 0);
        (void) win_comp_pos ();
        p_ea = save_ea;
        p_acd = save_acd;
        unblock_autocmds ();
        curwin = aucmd_win;
    }
    curbuf = buf;
    aco->new_curwin = curwin;
    set_bufref (& aco -> new_curbuf, curbuf);
}

int readfile (char_u *fname, char_u *sfname, linenr_T from, linenr_T lines_to_skip, linenr_T lines_to_read, exarg_T *eap, int flags) {
    int fd = 0;
    int newfile = (flags & READ_NEW);
    int check_readonly;
    int filtering = (flags & READ_FILTER);
    int read_stdin = (flags & READ_STDIN);
    int read_buffer = (flags & READ_BUFFER);
    int read_fifo = (flags & READ_FIFO);
    int set_options = newfile || read_buffer || (eap != NULL && eap->read_edit);
    linenr_T read_buf_lnum = 1;
    colnr_T read_buf_col = 0;
    char_u c;
    linenr_T lnum = from;
    char_u *ptr = NULL;
    char_u *buffer = NULL;
    char_u *new_buffer = NULL;
    char_u *line_start = NULL;
    int wasempty;
    colnr_T len;
    long  size = 0;
    char_u *p;
    off_T filesize = 0;
    int skip_read = FALSE;
    char_u *cryptkey = NULL;
    int did_ask_for_key = FALSE;
    context_sha256_T sha_ctx;
    int read_undo_file = FALSE;
    int split = 0;

    #define UNKNOWN	 0x0fffffff		/* file size is unknown */
    linenr_T linecnt;
    int error = FALSE;
    int ff_error = EOL_UNKNOWN;
    long  linerest = 0;
    int perm = 0;
    int swap_mode = -1;
    int fileformat = 0;
    int keep_fileformat = FALSE;
    stat_T st;
    int file_readonly;
    linenr_T skip_count = 0;
    linenr_T read_count = 0;
    int msg_save = msg_scroll;
    linenr_T read_no_eol_lnum = 0;
    int try_mac;
    int try_dos;
    int try_unix;
    int file_rewind = FALSE;
    buf_T *old_curbuf;
    char_u *old_b_ffname;
    char_u *old_b_fname;
    int using_b_ffname;
    int using_b_fname;
    au_did_filetype = FALSE;
    curbuf->b_no_eol_lnum = 0;
    if (curbuf->b_ffname == NULL && !filtering && fname != NULL && vim_strchr (p_cpo, CPO_FNAMER) != NULL && !(flags & READ_DUMMY)) {
        if (set_rw_fname (fname, sfname) == FAIL)
            return FAIL;
    }
    old_curbuf = curbuf;
    old_b_ffname = curbuf->b_ffname;
    old_b_fname = curbuf->b_fname;
    using_b_ffname = (fname == curbuf->b_ffname) || (sfname == curbuf->b_ffname);
    using_b_fname = (fname == curbuf->b_fname) || (sfname == curbuf->b_fname);
    ex_no_reprint = TRUE;
    need_fileinfo = FALSE;
    if (sfname == NULL)
        sfname = fname;
    fname = sfname;
    if (!filtering && !read_stdin && !read_buffer) {
        pos_T pos;
        pos = curbuf->b_op_start;
        curbuf->b_op_start.lnum = ((from == 0) ? 1 : from);
        curbuf->b_op_start.col = 0;
        if (newfile) {
            if (apply_autocmds_exarg (EVENT_BUFREADCMD, NULL, sfname, FALSE, curbuf, eap))
                return aborting () ? FAIL : OK;
        }
        else if (apply_autocmds_exarg (EVENT_FILEREADCMD, sfname, sfname, FALSE, NULL, eap))
            return aborting () ? FAIL : OK;
        curbuf->b_op_start = pos;
    }
    if ((shortmess (SHM_OVER) || curbuf->b_help) && p_verbose == 0)
        msg_scroll = FALSE;
    else
        msg_scroll = TRUE;
    if (fname != NULL && *fname != NUL) {
        p = fname + STRLEN (fname);
        if (after_pathsep (fname, p) || STRLEN (fname) >= MAXPATHL) {
            filemess (curbuf, fname, (char_u *) _ ("Illegal file name"), 0);
            msg_end ();
            msg_scroll = msg_save;
            return FAIL;
        }
    }
    if (!read_stdin && !read_buffer && !read_fifo) {
        perm = mch_getperm (fname);
        if (perm >= 0 && !S_ISREG (perm)) {
            int retval = FAIL;
            if (S_ISDIR (perm)) {
                filemess (curbuf, fname, (char_u *) _ ("is a directory"), 0);
                retval = NOTDONE;
            }
            else
                filemess (curbuf, fname, (char_u *) _ ("is not a file"), 0);
            msg_end ();
            msg_scroll = msg_save;
            return retval;
        }
    }
    set_file_options (set_options, eap);
    check_readonly = (newfile && (curbuf->b_flags & BF_CHECK_RO));
    if (check_readonly && !readonlymode)
        curbuf->b_p_ro = FALSE;
    if (newfile && !read_stdin && !read_buffer && !read_fifo) {
        if (mch_stat ((char *) fname, &st) >= 0) {
            buf_store_time (curbuf, & st, fname);
            curbuf->b_mtime_read = curbuf->b_mtime;
            swap_mode = (st.st_mode & 0644) | 0600;
        }
        else {
            curbuf->b_mtime = 0;
            curbuf->b_mtime_read = 0;
            curbuf->b_orig_size = 0;
            curbuf->b_orig_mode = 0;
        }
        curbuf->b_flags &= ~(BF_NEW | BF_NEW_W);
    }
    file_readonly = FALSE;
    if (read_stdin) {
    }
    else if (!read_buffer) {
        if (!newfile || readonlymode || (fd = mch_open ((char *) fname, O_RDWR | O_EXTRA, 0)) < 0) {
            file_readonly = TRUE;
            fd = mch_open ((char *) fname, O_RDONLY | O_EXTRA, 0);
        }
    }
    if (fd < 0) {
        msg_scroll = msg_save;
        if (newfile) {
            if (perm < 0) {
                curbuf->b_flags |= BF_NEW;
                if (!bt_dontwrite (curbuf)) {
                    check_need_swap (newfile);
                    if (curbuf != old_curbuf || (using_b_ffname && (old_b_ffname != curbuf->b_ffname)) || (using_b_fname && (old_b_fname != curbuf->b_fname))) {
                        EMSG (_ (e_auchangedbuf));
                        return FAIL;
                    }
                }
                if (dir_of_file_exists (fname))
                    filemess (curbuf, sfname, (char_u *) _ ("[New File]"), 0);
                else
                    filemess (curbuf, sfname, (char_u *) _ ("[New DIRECTORY]"), 0);
                check_marks_read ();
                apply_autocmds_exarg (EVENT_BUFNEWFILE, sfname, sfname, FALSE, curbuf, eap);
                save_file_ff (curbuf);
                if (aborting ())
                    return FAIL;
                return OK;
            }
            else {
                filemess (curbuf, sfname, (char_u *) (_ ("[Permission Denied]")), 0);
                curbuf->b_p_ro = TRUE;
            }
        }
        return FAIL;
    }
    if ((check_readonly && file_readonly) || curbuf->b_help)
        curbuf->b_p_ro = TRUE;
    if (set_options) {
        if (!read_buffer) {
            curbuf->b_p_eol = TRUE;
            curbuf->b_start_eol = TRUE;
        }
    }
    if (!bt_dontwrite (curbuf)) {
        check_need_swap (newfile);
        if (!read_stdin && (curbuf != old_curbuf || (using_b_ffname && (old_b_ffname != curbuf->b_ffname)) || (using_b_fname && (old_b_fname != curbuf->b_fname)))) {
            EMSG (_ (e_auchangedbuf));
            if (!read_buffer)
                close (fd);
            return FAIL;
        }
        if (swap_mode > 0 && curbuf->b_ml.ml_mfp != NULL && curbuf->b_ml.ml_mfp->mf_fname != NULL) {
            char_u *swap_fname = curbuf->b_ml.ml_mfp->mf_fname;
            if ((swap_mode & 044) == 040) {
                stat_T swap_st;
                if (mch_stat ((char *) swap_fname, &swap_st) >= 0 && st.st_gid != swap_st.st_gid && fchown (curbuf->b_ml.ml_mfp->mf_fd, -1, st.st_gid) == -1)
                    swap_mode &= 0600;
            }
            (void) mch_setperm (swap_fname, (long ) swap_mode);
        }
    }
    ++no_wait_return;
    curbuf->b_op_start.lnum = ((from == 0) ? 1 : from);
    curbuf->b_op_start.col = 0;
    try_mac = (vim_strchr (p_ffs, 'm') != NULL);
    try_dos = (vim_strchr (p_ffs, 'd') != NULL);
    try_unix = (vim_strchr (p_ffs, 'x') != NULL);
    if (!read_buffer) {
        int m = msg_scroll;
        int n = msg_scrolled;
        if (!read_stdin)
            close (fd);
        msg_scroll = TRUE;
        if (filtering)
            apply_autocmds_exarg (EVENT_FILTERREADPRE, NULL, sfname, FALSE, curbuf, eap);
        else if (read_stdin)
            apply_autocmds_exarg (EVENT_STDINREADPRE, NULL, sfname, FALSE, curbuf, eap);
        else if (newfile)
            apply_autocmds_exarg (EVENT_BUFREADPRE, NULL, sfname, FALSE, curbuf, eap);
        else
            apply_autocmds_exarg (EVENT_FILEREADPRE, sfname, sfname, FALSE, NULL, eap);
        try_mac = (vim_strchr (p_ffs, 'm') != NULL);
        try_dos = (vim_strchr (p_ffs, 'd') != NULL);
        try_unix = (vim_strchr (p_ffs, 'x') != NULL);
        if (msg_scrolled == n)
            msg_scroll = m;
        if (aborting ()) {
            --no_wait_return;
            msg_scroll = msg_save;
            curbuf->b_p_ro = TRUE;
            return FAIL;
        }
        if (!read_stdin && (curbuf != old_curbuf || (using_b_ffname && (old_b_ffname != curbuf->b_ffname)) || (using_b_fname && (old_b_fname != curbuf->b_fname)) || (fd = mch_open ((char *) fname, O_RDONLY | O_EXTRA, 0)) < 0)) {
            --no_wait_return;
            msg_scroll = msg_save;
            if (fd < 0)
                EMSG (_ ("E200: *ReadPre autocommands made the file unreadable"));
            else
                EMSG (_ ("E201: *ReadPre autocommands must not change current buffer"));
            curbuf->b_p_ro = TRUE;
            return FAIL;
        }
    }
    wasempty = (curbuf->b_ml.ml_flags & ML_EMPTY);
    if (!recoverymode && !filtering && !(flags & READ_DUMMY)) {
        if (read_stdin) {
            if (!is_not_a_term ()) {
                mch_msg (_ ("Vim: Reading from stdin...\n"));
                if (gui.in_use && !gui.dying && !gui.starting) {
                    p = (char_u *) _ ("Reading from stdin...");
                    gui_write (p, (int) STRLEN (p));
                }
            }
        }
        else if (!read_buffer)
            filemess (curbuf, sfname, (char_u *) "", 0);
    }
    msg_scroll = FALSE;
    linecnt = curbuf->b_ml.ml_line_count;
retry :
    if (file_rewind) {
        if (read_buffer) {
            read_buf_lnum = 1;
            read_buf_col = 0;
        }
        else if (read_stdin || vim_lseek (fd, (off_T) 0L, SEEK_SET) != 0) {
            error = TRUE;
            goto failed;
        }
        while (lnum > from)
            ml_delete (lnum--, FALSE);
        file_rewind = FALSE;
    }
    if (keep_fileformat)
        keep_fileformat = FALSE;
    else {
        if (eap != NULL && eap->force_ff != 0) {
            fileformat = get_fileformat_force (curbuf, eap);
            try_unix = try_dos = try_mac = FALSE;
        }
        else if (curbuf->b_p_bin)
            fileformat = EOL_UNIX;
        else if (*p_ffs == NUL)
            fileformat = get_fileformat (curbuf);
        else
            fileformat = EOL_UNKNOWN;
    }
    if (!skip_read) {
        linerest = 0;
        filesize = 0;
        skip_count = lines_to_skip;
        read_count = lines_to_read;
        read_undo_file = (newfile && (flags & READ_KEEP_UNDO) == 0 && curbuf->b_ffname != NULL && curbuf->b_p_udf && !filtering && !read_fifo && !read_stdin && !read_buffer);
        if (read_undo_file)
            sha256_start (&sha_ctx);
        if (curbuf->b_cryptstate != NULL) {
            crypt_free_state (curbuf -> b_cryptstate);
            curbuf->b_cryptstate = NULL;
        }
    }
    while (!error && !got_int) {
        {
            if (!skip_read) {
                size = 0x7ff0L - linerest;
                for (; size >= 10; size = (long ) ((long_u) size >> 1)) {
                    if ((new_buffer = lalloc ((long_u) (size + linerest + 1), FALSE)) != NULL)
                        break;
                }
                if (new_buffer == NULL) {
                    do_outofmem_msg ((long_u) (size * 2 + linerest + 1));
                    error = TRUE;
                    break;
                }
                if (linerest)
                    mch_memmove (new_buffer, ptr -linerest, (size_t) linerest);
                vim_free (buffer);
                buffer = new_buffer;
                ptr = buffer + linerest;
                line_start = buffer;
                if (read_buffer) {
                    if (read_buf_lnum > from)
                        size = 0;
                    else {
                        int n, ni;
                        long  tlen;
                        tlen = 0;
                        for (;;) {
                            p = ml_get (read_buf_lnum) + read_buf_col;
                            n = (int) STRLEN (p);
                            if ((int) tlen + n + 1 > size) {
                                n = (int) (size - tlen);
                                for (ni = 0; ni < n; ++ni) {
                                    if (p[ni] == NL)
                                        ptr[tlen++] = NUL;
                                    else
                                        ptr[tlen++] = p[ni];
                                }
                                read_buf_col += n;
                                break;
                            }
                            else {
                                for (ni = 0; ni < n; ++ni) {
                                    if (p[ni] == NL)
                                        ptr[tlen++] = NUL;
                                    else
                                        ptr[tlen++] = p[ni];
                                }
                                ptr[tlen++] = NL;
                                read_buf_col = 0;
                                if (++read_buf_lnum > from) {
                                    if (!curbuf->b_p_eol)
                                        --tlen;
                                    size = tlen;
                                    break;
                                }
                            }
                        }
                    }
                }
                else {
                    size = read_eintr (fd, ptr, size);
                }
                if (filesize == 0 && size > 0)
                    cryptkey = check_for_cryptkey (cryptkey, ptr, &size, &filesize, newfile, sfname, &did_ask_for_key);
                if (cryptkey != NULL && curbuf->b_cryptstate != NULL && size > 0) {
                    if (crypt_works_inplace (curbuf->b_cryptstate)) {
                        crypt_decode_inplace (curbuf -> b_cryptstate, ptr, size);
                    }
                    else {
                        char_u *newptr = NULL;
                        int decrypted_size;
                        decrypted_size = crypt_decode_alloc (curbuf->b_cryptstate, ptr, size, &newptr);
                        if (size > 0 && decrypted_size == 0)
                            continue;
                        if (linerest == 0) {
                            new_buffer = newptr;
                        }
                        else {
                            long_u new_size;
                            new_size = (long_u) (decrypted_size + linerest + 1);
                            new_buffer = lalloc (new_size, FALSE);
                            if (new_buffer == NULL) {
                                do_outofmem_msg (new_size);
                                error = TRUE;
                                break;
                            }
                            mch_memmove (new_buffer, buffer, linerest);
                            if (newptr != NULL)
                                mch_memmove (new_buffer +linerest, newptr, decrypted_size);
                        }
                        if (new_buffer != NULL) {
                            vim_free (buffer);
                            buffer = new_buffer;
                            new_buffer = NULL;
                            line_start = buffer;
                            ptr = buffer + linerest;
                        }
                        size = decrypted_size;
                    }
                }
                if (size <= 0) {
                    if (size < 0)
                        error = TRUE;
                }
            }
            skip_read = FALSE;
            if (size <= 0)
                break;
            filesize += size;
            if (fileformat == EOL_UNKNOWN) {
                if (try_dos || try_unix) {
                    if (try_mac)
                        try_mac = 1;
                    for (p = ptr; p < ptr + size; ++p) {
                        if (*p == NL) {
                            if (!try_unix || (try_dos && p > ptr && p[-1] == CAR))
                                fileformat = EOL_DOS;
                            else
                                fileformat = EOL_UNIX;
                            break;
                        }
                        else if (*p == CAR && try_mac)
                            try_mac++;
                    }
                    if (fileformat == EOL_UNIX && try_mac) {
                        try_mac = 1;
                        try_unix = 1;
                        for (; p >= ptr && *p != CAR; p--)
                            ;
                        if (p >= ptr) {
                            for (p = ptr; p < ptr + size; ++p) {
                                if (*p == NL)
                                    try_unix++;
                                else if (*p == CAR)
                                    try_mac++;
                            }
                            if (try_mac > try_unix)
                                fileformat = EOL_MAC;
                        }
                    }
                    else if (fileformat == EOL_UNKNOWN && try_mac == 1)
                        fileformat = default_fileformat ();
                }
                if (fileformat == EOL_UNKNOWN && try_mac)
                    fileformat = EOL_MAC;
                if (fileformat == EOL_UNKNOWN)
                    fileformat = default_fileformat ();
                if (set_options)
                    set_fileformat (fileformat, OPT_LOCAL);
            }
        }
        if (fileformat == EOL_MAC) {
            --ptr;
            while (++ptr, --size >= 0) {
                if ((c = *ptr) != NUL && c != CAR && c != NL)
                    continue;
                if (c == NUL)
                    *ptr = NL;
                else if (c == NL)
                    *ptr = CAR;
                else {
                    if (skip_count == 0) {
                        *ptr = NUL;
                        len = (colnr_T) (ptr - line_start + 1);
                        if (ml_append (lnum, line_start, len, newfile) == FAIL) {
                            error = TRUE;
                            break;
                        }
                        if (read_undo_file)
                            sha256_update (&sha_ctx, line_start, len);
                        ++lnum;
                        if (--read_count == 0) {
                            error = TRUE;
                            line_start = ptr;
                            break;
                        }
                    }
                    else
                        --skip_count;
                    line_start = ptr + 1;
                }
            }
        }
        else {
            --ptr;
            while (++ptr, --size >= 0) {
                if ((c = *ptr) != NUL && c != NL)
                    continue;
                if (c == NUL)
                    *ptr = NL;
                else {
                    if (skip_count == 0) {
                        *ptr = NUL;
                        len = (colnr_T) (ptr - line_start + 1);
                        if (fileformat == EOL_DOS) {
                            if (ptr > line_start && ptr[-1] == CAR) {
                                ptr[-1] = NUL;
                                --len;
                            }
                            else if (ff_error != EOL_DOS) {
                                if (try_unix && !read_stdin && (read_buffer || vim_lseek (fd, (off_T) 0L, SEEK_SET) == 0)) {
                                    fileformat = EOL_UNIX;
                                    if (set_options)
                                        set_fileformat (EOL_UNIX, OPT_LOCAL);
                                    file_rewind = TRUE;
                                    keep_fileformat = TRUE;
                                    goto retry;
                                }
                                ff_error = EOL_DOS;
                            }
                        }
                        if (ml_append (lnum, line_start, len, newfile) == FAIL) {
                            error = TRUE;
                            break;
                        }
                        if (read_undo_file)
                            sha256_update (&sha_ctx, line_start, len);
                        ++lnum;
                        if (--read_count == 0) {
                            error = TRUE;
                            line_start = ptr;
                            break;
                        }
                    }
                    else
                        --skip_count;
                    line_start = ptr + 1;
                }
            }
        }
        linerest = (long ) (ptr - line_start);
        ui_breakcheck ();
    }
failed :
    if (error && read_count == 0)
        error = FALSE;
    if (!error && !got_int && linerest != 0 && !(!curbuf->b_p_bin && fileformat == EOL_DOS && *line_start == Ctrl_Z && ptr == line_start + 1)) {
        if (set_options)
            curbuf->b_p_eol = FALSE;
        *ptr = NUL;
        len = (colnr_T) (ptr - line_start + 1);
        if (ml_append (lnum, line_start, len, newfile) == FAIL)
            error = TRUE;
        else {
            if (read_undo_file)
                sha256_update (&sha_ctx, line_start, len);
            read_no_eol_lnum = ++lnum;
        }
    }
    if (set_options)
        save_file_ff (curbuf);
    if (curbuf->b_cryptstate != NULL) {
        crypt_free_state (curbuf -> b_cryptstate);
        curbuf->b_cryptstate = NULL;
    }
    if (cryptkey != NULL && cryptkey != curbuf->b_p_key)
        crypt_free_key (cryptkey);
    if (!read_buffer && !read_stdin)
        close (fd);
    vim_free (buffer);
    --no_wait_return;
    if (!recoverymode) {
        if (newfile && wasempty && !(curbuf->b_ml.ml_flags & ML_EMPTY)) {
            netbeansFireChanges = 0;
            ml_delete (curbuf -> b_ml.ml_line_count, FALSE);
            netbeansFireChanges = 1;
            --linecnt;
        }
        linecnt = curbuf->b_ml.ml_line_count - linecnt;
        if (filesize == 0)
            linecnt = 0;
        if (newfile || read_buffer) {
            redraw_curbuf_later (NOT_VALID);
            diff_invalidate (curbuf);
            foldUpdateAll (curwin);
        }
        else if (linecnt)
            appended_lines_mark (from, linecnt);
        if (read_stdin) {
            settmode (TMODE_RAW);
            starttermcap ();
            screenclear ();
        }
        if (got_int) {
            if (!(flags & READ_DUMMY)) {
                filemess (curbuf, sfname, (char_u *) _ (e_interr), 0);
                if (newfile)
                    curbuf->b_p_ro = TRUE;
            }
            msg_scroll = msg_save;
            check_marks_read ();
            return OK;
        }
        if (!filtering && !(flags & READ_DUMMY)) {
            msg_add_fname (curbuf, sfname);
            c = FALSE;
            if (curbuf->b_p_ro) {
                STRCAT (IObuff, shortmess (SHM_RO) ? _ ("[RO]") : _ ("[readonly]"));
                c = TRUE;
            }
            if (read_no_eol_lnum) {
                msg_add_eol ();
                c = TRUE;
            }
            if (ff_error == EOL_DOS) {
                STRCAT (IObuff, _ ("[CR missing]"));
                c = TRUE;
            }
            if (split) {
                STRCAT (IObuff, _ ("[long lines split]"));
                c = TRUE;
            }
            if (cryptkey != NULL) {
                crypt_append_msg (curbuf);
                c = TRUE;
            }
            if (error) {
                STRCAT (IObuff, _ ("[READ ERRORS]"));
                c = TRUE;
            }
            if (msg_add_fileformat (fileformat))
                c = TRUE;
            if (cryptkey != NULL)
                msg_add_lines (c, (long ) linecnt, filesize -crypt_get_header_len (crypt_get_method_nr (curbuf)));
            else
                msg_add_lines (c, (long ) linecnt, filesize);
            VIM_CLEAR (keep_msg);
            msg_scrolled_ign = TRUE;
            p = msg_trunc_attr (IObuff, FALSE, 0);
            if (read_stdin || read_buffer || restart_edit != 0 || (msg_scrolled != 0 && !need_wait_return))
                set_keep_msg (p, 0);
            msg_scrolled_ign = FALSE;
        }
        if (newfile && (error))
            curbuf->b_p_ro = TRUE;
        u_clearline ();
        if (exmode_active)
            curwin->w_cursor.lnum = from + linecnt;
        else
            curwin->w_cursor.lnum = from + 1;
        check_cursor_lnum ();
        beginline (BL_WHITE | BL_FIX);
        curbuf->b_op_start.lnum = from + 1;
        curbuf->b_op_start.col = 0;
        curbuf->b_op_end.lnum = from + linecnt;
        curbuf->b_op_end.col = 0;
    }
    msg_scroll = msg_save;
    check_marks_read ();
    curbuf->b_no_eol_lnum = read_no_eol_lnum;
    if (flags & READ_KEEP_UNDO)
        u_find_first_changed ();
    if (read_undo_file) {
        char_u hash [UNDO_HASH_SIZE];
        sha256_finish (& sha_ctx, hash);
        u_read_undo (NULL, hash, fname);
    }
    if (!read_stdin && !read_fifo && (!read_buffer || sfname != NULL)) {
        int m = msg_scroll;
        int n = msg_scrolled;
        if (set_options)
            save_file_ff (curbuf);
        msg_scroll = TRUE;
        if (filtering)
            apply_autocmds_exarg (EVENT_FILTERREADPOST, NULL, sfname, FALSE, curbuf, eap);
        else if (newfile || (read_buffer && sfname != NULL)) {
            apply_autocmds_exarg (EVENT_BUFREADPOST, NULL, sfname, FALSE, curbuf, eap);
            if (!au_did_filetype && *curbuf->b_p_ft != NUL)
                apply_autocmds (EVENT_FILETYPE, curbuf->b_p_ft, curbuf->b_fname, TRUE, curbuf);
        }
        else
            apply_autocmds_exarg (EVENT_FILEREADPOST, sfname, sfname, FALSE, NULL, eap);
        if (msg_scrolled == n)
            msg_scroll = m;
        if (aborting ())
            return FAIL;
    }
    if (recoverymode && error)
        return FAIL;
    return OK;
}

int check_file_readonly (char_u *fname, int perm) {
    int fd = 0;
    return ((fd = mch_open ((char *) fname, O_RDWR | O_EXTRA, 0)) < 0 ? TRUE : (close (fd), FALSE));
}

char_u *buf_modname (int shortname, char_u *fname, char_u *ext, int prepend_dot) {
    char_u *retval;
    char_u *s;
    char_u *e;
    char_u *ptr;
    int fnamelen, extlen;
    extlen = (int) STRLEN (ext);
    if (fname == NULL || *fname == NUL) {
        retval = alloc ((unsigned ) (MAXPATHL + extlen + 3));
        if (retval == NULL)
            return NULL;
        if (mch_dirname (retval, MAXPATHL) == FAIL || (fnamelen = (int) STRLEN (retval)) == 0) {
            vim_free (retval);
            return NULL;
        }
        if (!after_pathsep (retval, retval +fnamelen)) {
            retval[fnamelen++] = PATHSEP;
            retval[fnamelen] = NUL;
        }
        prepend_dot = FALSE;
    }
    else {
        fnamelen = (int) STRLEN (fname);
        retval = alloc ((unsigned ) (fnamelen + extlen + 3));
        if (retval == NULL)
            return NULL;
        STRCPY (retval, fname);
    }
    for (ptr = retval + fnamelen; ptr > retval; MB_PTR_BACK (retval, ptr)) {
        if (*ext == '.' && shortname)
            if (*ptr == '.')
                *ptr = '_';
        if (vim_ispathsep (*ptr)) {
            ++ptr;
            break;
        }
    }
    if (STRLEN (ptr) > (unsigned ) BASENAMELEN)
        ptr[BASENAMELEN] = '\0';
    s = ptr + STRLEN (ptr);
    if (shortname) {
        if (fname == NULL || *fname == NUL || vim_ispathsep (fname[STRLEN (fname) - 1])) {
            if (*ext == '.')
                *s++ = '_';
        }
        else if (*ext == '.') {
            if ((size_t) (s - ptr) > (size_t) 8) {
                s = ptr + 8;
                *s = '\0';
            }
        }
        else if ((e = vim_strchr (ptr, '.')) == NULL)
            *s++ = '.';
        else if ((int) STRLEN (e) + extlen > 4)
            s = e + 4 - extlen;
    }
    STRCPY (s, ext);
    if (prepend_dot && !shortname && *(e = gettail (retval)) != '.') {
        STRMOVE (e + 1, e);
        *e = '.';
    }
    if (fname != NULL && STRCMP (fname, retval) == 0) {
        while (--s >= ptr) {
            if (*s != '_') {
                *s = '_';
                break;
            }
        }
        if (s < ptr)
            *ptr = 'v';
    }
    return retval;
}

int vim_fgets (char_u *buf, int size, FILE *fp) {
    char *eof;

    #define FGETS_SIZE 200
    char tbuf [FGETS_SIZE];
    buf[size - 2] = NUL;
    eof = fgets ((char *) buf, size, fp);
    if (buf[size - 2] != NUL && buf[size - 2] != '\n') {
        buf[size - 1] = NUL;
        do {
            tbuf[FGETS_SIZE - 2] = NUL;
            ignoredp = fgets ((char *) tbuf, FGETS_SIZE, fp);
        }
        while (tbuf[FGETS_SIZE - 2] != NUL && tbuf[FGETS_SIZE - 2] != '\n');
    }
    return (eof == NULL);
}

int vim_rename (char_u *from, char_u *to) {
    int fd_in;
    int fd_out;
    int n;
    char *errmsg = NULL;
    char *buffer;
    stat_T st;
    long  perm;
    int use_tmp_file = FALSE;
    if (fnamecmp (from, to) == 0) {
        if (p_fic && STRCMP (gettail (from), gettail (to)) != 0)
            use_tmp_file = TRUE;
        else
            return 0;
    }
    if (mch_stat ((char *) from, &st) < 0)
        return -1;
    {
        stat_T st_to;
        if (mch_stat ((char *) to, &st_to) >= 0 && st.st_dev == st_to.st_dev && st.st_ino == st_to.st_ino)
            use_tmp_file = TRUE;
    }
    if (use_tmp_file) {
        char tempname [MAXPATHL + 1];
        if (STRLEN (from) >= MAXPATHL - 5)
            return -1;
        STRCPY (tempname, from);
        for (n = 123; n < 99999; ++n) {
            sprintf ((char *) gettail ((char_u *) tempname), "%d", n);
            if (mch_stat (tempname, &st) < 0) {
                if (mch_rename ((char *) from, tempname) == 0) {
                    if (mch_rename (tempname, (char *) to) == 0)
                        return 0;
                    mch_rename (tempname, (char *) from);
                    return -1;
                }
                return -1;
            }
        }
        return -1;
    }
    mch_remove (to);
    if (mch_rename ((char *) from, (char *) to) == 0)
        return 0;
    perm = mch_getperm (from);
    fd_in = mch_open ((char *) from, O_RDONLY | O_EXTRA, 0);
    if (fd_in == -1) {
        return -1;
    }
    fd_out = mch_open ((char *) to, O_CREAT | O_EXCL | O_WRONLY | O_EXTRA | O_NOFOLLOW, (int) perm);
    if (fd_out == -1) {
        close (fd_in);
        return -1;
    }
    buffer = (char *) alloc (BUFSIZE);
    if (buffer == NULL) {
        close (fd_out);
        close (fd_in);
        return -1;
    }
    while ((n = read_eintr (fd_in, buffer, BUFSIZE)) > 0)
        if (write_eintr (fd_out, buffer, n) != n) {
            errmsg = _ ("E208: Error writing to \"%s\"");
            break;
        }
    vim_free (buffer);
    close (fd_in);
    if (close (fd_out) < 0)
        errmsg = _ ("E209: Error closing \"%s\"");
    if (n < 0) {
        errmsg = _ ("E210: Error reading \"%s\"");
        to = from;
    }
    if (errmsg != NULL) {
        EMSG2 (errmsg, to);
        return -1;
    }
    mch_remove (from);
    return 0;
}

int trigger_cursorhold (void) {
    int state;
    if (!did_cursorhold && has_cursorhold () && !Recording && typebuf.tb_len == 0 && !ins_compl_active ()) {
        state = get_real_state ();
        if (state == NORMAL_BUSY || (state & INSERT) != 0)
            return TRUE;
    }
    return FALSE;
}

int has_cursorhold (void) {
    return (first_autopat[(int) (get_real_state () == NORMAL_BUSY ? EVENT_CURSORHOLD : EVENT_CURSORHOLDI)] != NULL);
}

void vim_deltempdir (void) {
    if (vim_tempdir != NULL) {
        gettail (vim_tempdir)[-1] = NUL;
        delete_recursive (vim_tempdir);
        VIM_CLEAR (vim_tempdir);
    }
}

int delete_recursive (char_u *name) {
    int result = 0;
    char_u **files;
    int file_count;
    int i;
    char_u *exp;
    if (mch_isrealdir (name)) {
        vim_snprintf ((char *) NameBuff, MAXPATHL, "%s/*", name);
        exp = vim_strsave (NameBuff);
        if (exp == NULL)
            return -1;
        if (gen_expand_wildcards (1, &exp, &file_count, &files, EW_DIR | EW_FILE | EW_SILENT | EW_ALLLINKS | EW_DODOT | EW_EMPTYOK) == OK) {
            for (i = 0; i < file_count; ++i)
                if (delete_recursive (files[i]) != 0)
                    result = -1;
            FreeWild (file_count, files);
        }
        else
            result = -1;
        vim_free (exp);
        (void) mch_rmdir (name);
    }
    else
        result = mch_remove (name) == 0 ? 0 : -1;
    return result;
}

int has_autocmd (event_T event, char_u *sfname, buf_T *buf) {
    AutoPat *ap;
    char_u *fname;
    char_u *tail = gettail (sfname);
    int retval = FALSE;
    fname = FullName_save (sfname, FALSE);
    if (fname == NULL)
        return FALSE;
    for (ap = first_autopat[(int) event]; ap != NULL; ap = ap->next)
        if (ap->pat != NULL && ap->cmds != NULL && (ap->buflocal_nr == 0 ? match_file_pat (NULL, &ap->reg_prog, fname, sfname, tail, ap->allow_dirs) : buf != NULL && ap->buflocal_nr == buf->b_fnum)) {
            retval = TRUE;
            break;
        }
    vim_free (fname);
    return retval;
}

int buf_write (buf_T *buf, char_u *fname, char_u *sfname, linenr_T start, linenr_T end, exarg_T *eap, int append, int forceit, int reset_changed, int filtering) {
    int fd;
    char_u *backup = NULL;
    int backup_copy = FALSE;
    int dobackup;
    char_u *ffname;
    char_u *wfname = NULL;
    char_u *s;
    char_u *ptr;
    char_u c;
    int len;
    linenr_T lnum;
    long  nchars;
    char_u *errmsg = NULL;
    int errmsg_allocated = FALSE;
    char_u *errnum = NULL;
    char_u *buffer;
    char_u smallbuf [SMBUFSIZE];
    char_u *backup_ext;
    int bufsize;
    long  perm;
    int retval = OK;
    int newfile = FALSE;
    int msg_save = msg_scroll;
    int overwriting;
    int no_eol = FALSE;
    int device = FALSE;
    stat_T st_old;
    int prev_got_int = got_int;
    int checking_conversion;
    int file_readonly = FALSE;
    static char *err_readonly = "is read-only (cannot override: \"W\" in 'cpoptions')";
    int made_writable = FALSE;
    int whole = (start == 1 && end == buf->b_ml.ml_line_count);
    linenr_T old_line_count = buf->b_ml.ml_line_count;
    int attr;
    int fileformat;
    int write_bin;
    struct bw_info write_info;
    int write_undo_file = FALSE;
    context_sha256_T sha_ctx;
    unsigned  int bkc = get_bkc_value (buf);
    if (fname == NULL || *fname == NUL)
        return FAIL;
    if (buf->b_ml.ml_mfp == NULL) {
        EMSG (_ (e_emptybuf));
        return FAIL;
    }
    if (check_secure ())
        return FAIL;
    if (STRLEN (fname) >= MAXPATHL) {
        EMSG (_ (e_longname));
        return FAIL;
    }
    write_info.bw_buffer = buf;
    ex_no_reprint = TRUE;
    if (buf->b_ffname == NULL && reset_changed && whole && buf == curbuf && !bt_nofile (buf) && !filtering && (!append || vim_strchr (p_cpo, CPO_FNAMEAPP) != NULL) && vim_strchr (p_cpo, CPO_FNAMEW) != NULL) {
        if (set_rw_fname (fname, sfname) == FAIL)
            return FAIL;
        buf = curbuf;
    }
    if (sfname == NULL)
        sfname = fname;
    ffname = fname;
    fname = sfname;
    if (buf->b_ffname != NULL && fnamecmp (ffname, buf->b_ffname) == 0)
        overwriting = TRUE;
    else
        overwriting = FALSE;
    if (exiting)
        settmode (TMODE_COOK);
    ++no_wait_return;
    buf->b_op_start.lnum = start;
    buf->b_op_start.col = 0;
    buf->b_op_end.lnum = end;
    buf->b_op_end.col = 0;
    {
        aco_save_T aco;
        int buf_ffname = FALSE;
        int buf_sfname = FALSE;
        int buf_fname_f = FALSE;
        int buf_fname_s = FALSE;
        int did_cmd = FALSE;
        int nofile_err = FALSE;
        int empty_memline = (buf->b_ml.ml_mfp == NULL);
        bufref_T bufref;
        if (ffname == buf->b_ffname)
            buf_ffname = TRUE;
        if (sfname == buf->b_sfname)
            buf_sfname = TRUE;
        if (fname == buf->b_ffname)
            buf_fname_f = TRUE;
        if (fname == buf->b_sfname)
            buf_fname_s = TRUE;
        aucmd_prepbuf (& aco, buf);
        set_bufref (& bufref, buf);
        if (append) {
            if (!(did_cmd = apply_autocmds_exarg (EVENT_FILEAPPENDCMD, sfname, sfname, FALSE, curbuf, eap))) {
                if (overwriting && bt_nofile (curbuf))
                    nofile_err = TRUE;
                else
                    apply_autocmds_exarg (EVENT_FILEAPPENDPRE, sfname, sfname, FALSE, curbuf, eap);
            }
        }
        else if (filtering) {
            apply_autocmds_exarg (EVENT_FILTERWRITEPRE, NULL, sfname, FALSE, curbuf, eap);
        }
        else if (reset_changed && whole) {
            int was_changed = curbufIsChanged ();
            did_cmd = apply_autocmds_exarg (EVENT_BUFWRITECMD, sfname, sfname, FALSE, curbuf, eap);
            if (did_cmd) {
                if (was_changed && !curbufIsChanged ()) {
                    u_unchanged (curbuf);
                    u_update_save_nr (curbuf);
                }
            }
            else {
                if (overwriting && bt_nofile (curbuf))
                    nofile_err = TRUE;
                else
                    apply_autocmds_exarg (EVENT_BUFWRITEPRE, sfname, sfname, FALSE, curbuf, eap);
            }
        }
        else {
            if (!(did_cmd = apply_autocmds_exarg (EVENT_FILEWRITECMD, sfname, sfname, FALSE, curbuf, eap))) {
                if (overwriting && bt_nofile (curbuf))
                    nofile_err = TRUE;
                else
                    apply_autocmds_exarg (EVENT_FILEWRITEPRE, sfname, sfname, FALSE, curbuf, eap);
            }
        }
        aucmd_restbuf (& aco);
        if (!bufref_valid (&bufref))
            buf = NULL;
        if (buf == NULL || (buf->b_ml.ml_mfp == NULL && !empty_memline) || did_cmd || nofile_err || aborting ()) {
            --no_wait_return;
            msg_scroll = msg_save;
            if (nofile_err)
                EMSG (_ ("E676: No matching autocommands for acwrite buffer"));
            if (nofile_err || aborting ())
                return FAIL;
            if (did_cmd) {
                if (buf == NULL)
                    return OK;
                if (overwriting) {
                    ml_timestamp (buf);
                    if (append)
                        buf->b_flags &= ~BF_NEW;
                    else
                        buf->b_flags &= ~BF_WRITE_MASK;
                }
                if (reset_changed && buf->b_changed && !append && (overwriting || vim_strchr (p_cpo, CPO_PLUS) != NULL))
                    return FAIL;
                return OK;
            }
            if (!aborting ())
                EMSG (_ ("E203: Autocommands deleted or unloaded buffer to be written"));
            return FAIL;
        }
        if (buf->b_ml.ml_line_count != old_line_count) {
            if (whole)
                end = buf->b_ml.ml_line_count;
            else if (buf->b_ml.ml_line_count > old_line_count)
                end += buf->b_ml.ml_line_count - old_line_count;
            else {
                end -= old_line_count - buf->b_ml.ml_line_count;
                if (end < start) {
                    --no_wait_return;
                    msg_scroll = msg_save;
                    EMSG (_ ("E204: Autocommand changed number of lines in unexpected way"));
                    return FAIL;
                }
            }
        }
        if (buf_ffname)
            ffname = buf->b_ffname;
        if (buf_sfname)
            sfname = buf->b_sfname;
        if (buf_fname_f)
            fname = buf->b_ffname;
        if (buf_fname_s)
            fname = buf->b_sfname;
    }
    if (netbeans_active () && isNetbeansBuffer (buf)) {
        if (whole) {
            if (buf->b_changed || isNetbeansModified (buf)) {
                --no_wait_return;
                msg_scroll = msg_save;
                netbeans_save_buffer (buf);
                return retval;
            }
            else {
                errnum = (char_u *) "E656: ";
                errmsg = (char_u *) _ ("NetBeans disallows writes of unmodified buffers");
                buffer = NULL;
                goto fail;
            }
        }
        else {
            errnum = (char_u *) "E657: ";
            errmsg = (char_u *) _ ("Partial writes disallowed for NetBeans buffers");
            buffer = NULL;
            goto fail;
        }
    }
    if (shortmess (SHM_OVER) && !exiting)
        msg_scroll = FALSE;
    else
        msg_scroll = TRUE;
    if (!filtering)
        filemess (buf, fname, (char_u *) "", 0);
    msg_scroll = FALSE;
    buffer = alloc (BUFSIZE);
    if (buffer == NULL) {
        buffer = smallbuf;
        bufsize = SMBUFSIZE;
    }
    else
        bufsize = BUFSIZE;
    st_old.st_dev = 0;
    st_old.st_ino = 0;
    perm = -1;
    if (mch_stat ((char *) fname, &st_old) < 0)
        newfile = TRUE;
    else {
        perm = st_old.st_mode;
        if (!S_ISREG (st_old.st_mode)) {
            if (S_ISDIR (st_old.st_mode)) {
                errnum = (char_u *) "E502: ";
                errmsg = (char_u *) _ ("is a directory");
                goto fail;
            }
            if (mch_nodetype (fname) != NODE_WRITABLE) {
                errnum = (char_u *) "E503: ";
                errmsg = (char_u *) _ ("is not a file or writable device");
                goto fail;
            }
            device = TRUE;
            newfile = TRUE;
            perm = -1;
        }
    }
    if (!device && !newfile) {
        file_readonly = check_file_readonly (fname, (int) perm);
        if (!forceit && file_readonly) {
            if (vim_strchr (p_cpo, CPO_FWRITE) != NULL) {
                errnum = (char_u *) "E504: ";
                errmsg = (char_u *) _ (err_readonly);
            }
            else {
                errnum = (char_u *) "E505: ";
                errmsg = (char_u *) _ ("is read-only (add ! to override)");
            }
            goto fail;
        }
        if (overwriting) {
            retval = check_mtime (buf, &st_old);
            if (retval == FAIL)
                goto fail;
        }
    }
    dobackup = (p_wb || p_bk || *p_pm != NUL);
    if (dobackup && *p_bsk != NUL && match_file_list (p_bsk, sfname, ffname))
        dobackup = FALSE;
    prev_got_int = got_int;
    got_int = FALSE;
    buf->b_saving = TRUE;
    if (!(append && *p_pm == NUL) && !filtering && perm >= 0 && dobackup) {
        stat_T st;
        if ((bkc & BKC_YES) || append)
            backup_copy = TRUE;
        else if ((bkc & BKC_AUTO)) {
            int i;
            if (st_old.st_nlink > 1 || mch_lstat ((char *) fname, &st) < 0 || st.st_dev != st_old.st_dev || st.st_ino != st_old.st_ino || st.st_uid != st_old.st_uid || st.st_gid != st_old.st_gid)
                backup_copy = TRUE;
            else {
                STRCPY (IObuff, fname);
                for (i = 4913;; i += 123) {
                    sprintf ((char *) gettail (IObuff), "%d", i);
                    if (mch_lstat ((char *) IObuff, &st) < 0)
                        break;
                }
                fd = mch_open ((char *) IObuff, O_CREAT | O_WRONLY | O_EXCL | O_NOFOLLOW, perm);
                if (fd < 0)
                    backup_copy = TRUE;
                else {
                    if (mch_stat ((char *) IObuff, &st) < 0 || st.st_uid != st_old.st_uid || st.st_gid != st_old.st_gid || (long ) st.st_mode != perm)
                        backup_copy = TRUE;
                    close (fd);
                    mch_remove (IObuff);
                }
            }
        }
        if ((bkc & BKC_BREAKSYMLINK) || (bkc & BKC_BREAKHARDLINK)) {
            int lstat_res;
            lstat_res = mch_lstat ((char *) fname, &st);
            if ((bkc & BKC_BREAKSYMLINK) && lstat_res == 0 && st.st_ino != st_old.st_ino)
                backup_copy = FALSE;
            if ((bkc & BKC_BREAKHARDLINK) && st_old.st_nlink > 1 && (lstat_res != 0 || st.st_ino == st_old.st_ino))
                backup_copy = FALSE;
        }
        if (*p_bex == NUL)
            backup_ext = (char_u *) ".bak";
        else
            backup_ext = p_bex;
        if (backup_copy && (fd = mch_open ((char *) fname, O_RDONLY | O_EXTRA, 0)) >= 0) {
            int bfd;
            char_u *copybuf, *wp;
            int some_error = FALSE;
            stat_T st_new;
            char_u *dirp;
            char_u *rootname;
            int did_set_shortname;
            mode_t umask_save;
            copybuf = alloc (BUFSIZE +1);
            if (copybuf == NULL) {
                some_error = TRUE;
                goto nobackup;
            }
            dirp = p_bdir;
            while (*dirp) {
                st_new.st_ino = 0;
                st_new.st_dev = 0;
                st_new.st_gid = 0;
                (void) copy_option_part (&dirp, copybuf, BUFSIZE, ",");
                rootname = get_file_in_dir (fname, copybuf);
                if (rootname == NULL) {
                    some_error = TRUE;
                    goto nobackup;
                }
                did_set_shortname = FALSE;
                for (;;) {
                    backup = buf_modname ((buf->b_p_sn || buf->b_shortname), rootname, backup_ext, FALSE);
                    if (backup == NULL) {
                        vim_free (rootname);
                        some_error = TRUE;
                        goto nobackup;
                    }
                    if (mch_stat ((char *) backup, &st_new) >= 0) {
                        if (st_new.st_dev == st_old.st_dev && st_new.st_ino == st_old.st_ino) {
                            VIM_CLEAR (backup);
                            if (!(buf->b_shortname || buf->b_p_sn)) {
                                buf->b_shortname = TRUE;
                                did_set_shortname = TRUE;
                                continue;
                            }
                            if (did_set_shortname)
                                buf->b_shortname = FALSE;
                            break;
                        }
                        if (!p_bk) {
                            wp = backup + STRLEN (backup) - 1 - STRLEN (backup_ext);
                            if (wp < backup)
                                wp = backup;
                            *wp = 'z';
                            while (*wp > 'a' && mch_stat ((char *) backup, &st_new) >= 0)
                                --*wp;
                            if (*wp == 'a')
                                VIM_CLEAR (backup);
                        }
                    }
                    break;
                }
                vim_free (rootname);
                if (backup != NULL) {
                    mch_remove (backup);
                    umask_save = umask (0);
                    bfd = mch_open ((char *) backup, O_WRONLY | O_CREAT | O_EXTRA | O_EXCL | O_NOFOLLOW, perm &0777);
                    (void) umask (umask_save);
                    if (bfd < 0)
                        VIM_CLEAR (backup);
                    else {
                        if (st_new.st_gid != st_old.st_gid)
                            mch_setperm (backup, (perm & 0707) | ((perm & 07) << 3));
                        write_info.bw_fd = bfd;
                        write_info.bw_buf = copybuf;
                        while ((write_info.bw_len = read_eintr (fd, copybuf, BUFSIZE)) > 0) {
                            if (buf_write_bytes (&write_info) == FAIL) {
                                errmsg = (char_u *) _ ("E506: Can't write to backup file (add ! to override)");
                                break;
                            }
                            ui_breakcheck ();
                            if (got_int) {
                                errmsg = (char_u *) _ (e_interr);
                                break;
                            }
                        }
                        if (close (bfd) < 0 && errmsg == NULL)
                            errmsg = (char_u *) _ ("E507: Close error for backup file (add ! to override)");
                        if (write_info.bw_len < 0)
                            errmsg = (char_u *) _ ("E508: Can't read file for backup (add ! to override)");
                        set_file_time (backup, st_old.st_atime, st_old.st_mtime);
                        break;
                    }
                }
            }
        nobackup :
            close (fd);
            vim_free (copybuf);
            if (backup == NULL && errmsg == NULL)
                errmsg = (char_u *) _ ("E509: Cannot create backup file (add ! to override)");
            if ((some_error || errmsg != NULL) && !forceit) {
                retval = FAIL;
                goto fail;
            }
            errmsg = NULL;
        }
        else {
            char_u *dirp;
            char_u *p;
            char_u *rootname;
            if (file_readonly && vim_strchr (p_cpo, CPO_FWRITE) != NULL) {
                errnum = (char_u *) "E504: ";
                errmsg = (char_u *) _ (err_readonly);
                goto fail;
            }
            dirp = p_bdir;
            while (*dirp) {
                (void) copy_option_part (&dirp, IObuff, IOSIZE, ",");
                rootname = get_file_in_dir (fname, IObuff);
                if (rootname == NULL)
                    backup = NULL;
                else {
                    backup = buf_modname ((buf->b_p_sn || buf->b_shortname), rootname, backup_ext, FALSE);
                    vim_free (rootname);
                }
                if (backup != NULL) {
                    if (!p_bk && mch_getperm (backup) >= 0) {
                        p = backup + STRLEN (backup) - 1 - STRLEN (backup_ext);
                        if (p < backup)
                            p = backup;
                        *p = 'z';
                        while (*p > 'a' && mch_getperm (backup) >= 0)
                            --*p;
                        if (*p == 'a')
                            VIM_CLEAR (backup);
                    }
                }
                if (backup != NULL) {
                    if (vim_rename (fname, backup) == 0)
                        break;
                    VIM_CLEAR (backup);
                }
            }
            if (backup == NULL && !forceit) {
                errmsg = (char_u *) _ ("E510: Can't make backup file (add ! to override)");
                goto fail;
            }
        }
    }
    if (forceit && perm >= 0 && !(perm & 0200) && st_old.st_uid == getuid () && vim_strchr (p_cpo, CPO_FWRITE) == NULL) {
        perm |= 0200;
        (void) mch_setperm (fname, perm);
        made_writable = TRUE;
    }
    if (forceit && overwriting && vim_strchr (p_cpo, CPO_KEEPRO) == NULL) {
        buf->b_p_ro = FALSE;
        need_maketitle = TRUE;
        status_redraw_all ();
    }
    if (end > buf->b_ml.ml_line_count)
        end = buf->b_ml.ml_line_count;
    if (buf->b_ml.ml_flags & ML_EMPTY)
        start = end + 1;
    if (reset_changed && !newfile && overwriting && !(exiting && backup != NULL)) {
        ml_preserve (buf, FALSE);
        if (got_int) {
            errmsg = (char_u *) _ (e_interr);
            goto restore_backup;
        }
    }
    wfname = fname;
    for (checking_conversion = TRUE;; checking_conversion = FALSE) {
        checking_conversion = FALSE;
        if (checking_conversion) {
            fd = -1;
            write_info.bw_fd = fd;
        }
        else {

            # define TRUNC_ON_OPEN O_TRUNC
            while ((fd = mch_open ((char *) wfname, O_WRONLY | O_EXTRA | (append ? (forceit ? (O_APPEND | O_CREAT) : O_APPEND) : (O_CREAT | TRUNC_ON_OPEN)), perm < 0 ? 0666 : (perm & 0777))) < 0) {
                if (errmsg == NULL) {
                    stat_T st;
                    if ((!newfile && st_old.st_nlink > 1) || (mch_lstat ((char *) fname, &st) == 0 && (st.st_dev != st_old.st_dev || st.st_ino != st_old.st_ino)))
                        errmsg = (char_u *) _ ("E166: Can't open linked file for writing");
                    else {
                        errmsg = (char_u *) _ ("E212: Can't open file for writing");
                        if (forceit && vim_strchr (p_cpo, CPO_FWRITE) == NULL && perm >= 0) {
                            if (!(perm & 0200))
                                made_writable = TRUE;
                            perm |= 0200;
                            if (st_old.st_uid != getuid () || st_old.st_gid != getgid ())
                                perm &= 0777;
                            if (!append)
                                mch_remove (wfname);
                            continue;
                        }
                    }
                }
            restore_backup :
                {
                    stat_T st;
                    if (backup != NULL && wfname == fname) {
                        if (backup_copy) {
                            if (mch_stat ((char *) fname, &st) < 0)
                                vim_rename (backup, fname);
                            if (mch_stat ((char *) fname, &st) >= 0)
                                mch_remove (backup);
                        }
                        else {
                            vim_rename (backup, fname);
                        }
                    }
                    if (!newfile && mch_stat ((char *) fname, &st) < 0)
                        end = 0;
                }
                goto fail;
            }
            write_info.bw_fd = fd;
            {
                stat_T st;
                if (overwriting && (!dobackup || backup_copy) && fname == wfname && perm >= 0 && mch_fstat (fd, &st) == 0 && st.st_ino != st_old.st_ino) {
                    close (fd);
                    errmsg = (char_u *) _ ("E949: File changed while writing");
                    goto fail;
                }
            }
            if (*buf->b_p_key != NUL && !filtering) {
                char_u *header;
                int header_len;
                buf->b_cryptstate = crypt_create_for_writing (crypt_get_method_nr (buf), buf->b_p_key, &header, &header_len);
                if (buf->b_cryptstate == NULL || header == NULL)
                    end = 0;
                else {
                    write_info.bw_buf = header;
                    write_info.bw_len = header_len;
                    write_info.bw_flags = FIO_NOCONVERT;
                    if (buf_write_bytes (&write_info) == FAIL)
                        end = 0;
                    wb_flags |= FIO_ENCRYPTED;
                    vim_free (header);
                }
            }
        }
        errmsg = NULL;
        write_info.bw_buf = buffer;
        nchars = 0;
        if (eap != NULL && eap->force_bin != 0)
            write_bin = (eap->force_bin == FORCE_BIN);
        else
            write_bin = buf->b_p_bin;
        write_undo_file = (buf->b_p_udf && overwriting && !append && !filtering && reset_changed && !checking_conversion);
        if (write_undo_file)
            sha256_start (&sha_ctx);
        write_info.bw_len = bufsize;
        fileformat = get_fileformat_force (buf, eap);
        s = buffer;
        len = 0;
        for (lnum = start; lnum <= end; ++lnum) {
            ptr = ml_get_buf (buf, lnum, FALSE) - 1;
            if (write_undo_file)
                sha256_update (&sha_ctx, ptr +1, (UINT32_T) (STRLEN (ptr +1) + 1));
            while ((c = *++ptr) != NUL) {
                if (c == NL)
                    *s = NUL;
                else if (c == CAR && fileformat == EOL_MAC)
                    *s = NL;
                else
                    *s = c;
                ++s;
                if (++len != bufsize)
                    continue;
                if (buf_write_bytes (&write_info) == FAIL) {
                    end = 0;
                    break;
                }
                nchars += bufsize;
                s = buffer;
                len = 0;
            }
            if (end == 0 || (lnum == end && (write_bin || !buf->b_p_fixeol) && (lnum == buf->b_no_eol_lnum || (lnum == buf->b_ml.ml_line_count && !buf->b_p_eol)))) {
                ++lnum;
                no_eol = TRUE;
                break;
            }
            if (fileformat == EOL_UNIX)
                *s++ = NL;
            else {
                *s++ = CAR;
                if (fileformat == EOL_DOS) {
                    if (++len == bufsize) {
                        if (buf_write_bytes (&write_info) == FAIL) {
                            end = 0;
                            break;
                        }
                        nchars += bufsize;
                        s = buffer;
                        len = 0;
                    }
                    *s++ = NL;
                }
            }
            if (++len == bufsize && end) {
                if (buf_write_bytes (&write_info) == FAIL) {
                    end = 0;
                    break;
                }
                nchars += bufsize;
                s = buffer;
                len = 0;
                ui_breakcheck ();
                if (got_int) {
                    end = 0;
                    break;
                }
            }
        }
        if (len > 0 && end > 0) {
            write_info.bw_len = len;
            if (buf_write_bytes (&write_info) == FAIL)
                end = 0;
            nchars += len;
        }
        if (!checking_conversion || end == 0)
            break;
    }
    if (!checking_conversion) {
        if (backup != NULL && !backup_copy) {
            buf_setino (buf);
        }
        else if (!buf->b_dev_valid)
            buf_setino (buf);
        if (made_writable)
            perm &= ~0200;
        if (close (fd) != 0) {
            errmsg = (char_u *) _ ("E512: Close failed");
            end = 0;
        }
        if (perm >= 0)
            (void) mch_setperm (wfname, perm);
        if (buf->b_cryptstate != NULL) {
            crypt_free_state (buf -> b_cryptstate);
            buf->b_cryptstate = NULL;
        }
    }
    if (end == 0) {
        if (errmsg == NULL) {
            if (got_int)
                errmsg = (char_u *) _ (e_interr);
            else
                errmsg = (char_u *) _ ("E514: write error (file system full?)");
        }
        if (backup != NULL) {
            if (backup_copy) {
                if (got_int) {
                    MSG (_ (e_interr));
                    out_flush ();
                }
                if ((fd = mch_open ((char *) backup, O_RDONLY | O_EXTRA, 0)) >= 0) {
                    if ((write_info.bw_fd = mch_open ((char *) fname, O_WRONLY | O_CREAT | O_TRUNC | O_EXTRA, perm &0777)) >= 0) {
                        write_info.bw_buf = smallbuf;
                        while ((write_info.bw_len = read_eintr (fd, smallbuf, SMBUFSIZE)) > 0)
                            if (buf_write_bytes (&write_info) == FAIL)
                                break;
                        if (close (write_info.bw_fd) >= 0 && write_info.bw_len == 0)
                            end = 1;
                    }
                    close (fd);
                }
            }
            else {
                if (vim_rename (backup, fname) == 0)
                    end = 1;
            }
        }
        goto fail;
    }
    lnum -= start;
    --no_wait_return;
    if (!filtering) {
        msg_add_fname (buf, fname);
        c = FALSE;
        if (device) {
            STRCAT (IObuff, _ ("[Device]"));
            c = TRUE;
        }
        else if (newfile) {
            STRCAT (IObuff, shortmess (SHM_NEW) ? _ ("[New]") : _ ("[New File]"));
            c = TRUE;
        }
        if (no_eol) {
            msg_add_eol ();
            c = TRUE;
        }
        if (msg_add_fileformat (fileformat))
            c = TRUE;
        if (wb_flags & FIO_ENCRYPTED) {
            crypt_append_msg (buf);
            c = TRUE;
        }
        msg_add_lines (c, (long) lnum, nchars);
        if (!shortmess (SHM_WRITE)) {
            if (append)
                STRCAT (IObuff, shortmess (SHM_WRI) ? _ (" [a]") : _ (" appended"));
            else
                STRCAT (IObuff, shortmess (SHM_WRI) ? _ (" [w]") : _ (" written"));
        }
        set_keep_msg (msg_trunc_attr (IObuff, FALSE, 0), 0);
    }
    if (reset_changed && whole && !append && (overwriting || vim_strchr (p_cpo, CPO_PLUS) != NULL)) {
        unchanged (buf, TRUE);
        if (buf->b_last_changedtick + 1 == CHANGEDTICK (buf))
            buf->b_last_changedtick = CHANGEDTICK (buf);
        u_unchanged (buf);
        u_update_save_nr (buf);
    }
    if (overwriting) {
        ml_timestamp (buf);
        if (append)
            buf->b_flags &= ~BF_NEW;
        else
            buf->b_flags &= ~BF_WRITE_MASK;
    }
    if (*p_pm && dobackup) {
        char *org = (char *) buf_modname ((buf->b_p_sn || buf->b_shortname), fname, p_pm, FALSE);
        if (backup != NULL) {
            stat_T st;
            if (org == NULL)
                EMSG (_ ("E205: Patchmode: can't save original file"));
            else if (mch_stat (org, &st) < 0) {
                vim_rename (backup, (char_u *) org);
                VIM_CLEAR (backup);
                set_file_time ((char_u *) org, st_old.st_atime, st_old.st_mtime);
            }
        }
        else {
            int empty_fd;
            if (org == NULL || (empty_fd = mch_open (org, O_CREAT | O_EXTRA | O_EXCL | O_NOFOLLOW, perm < 0 ? 0666 : (perm & 0777))) < 0)
                EMSG (_ ("E206: patchmode: can't touch empty original file"));
            else
                close (empty_fd);
        }
        if (org != NULL) {
            mch_setperm ((char_u *) org, mch_getperm (fname) & 0777);
            vim_free (org);
        }
    }
    if (!p_bk && backup != NULL && mch_remove (backup) != 0)
        EMSG (_ ("E207: Can't delete backup file"));
    goto nofail;
fail :
    --no_wait_return;
nofail :
    buf->b_saving = FALSE;
    vim_free (backup);
    if (buffer != smallbuf)
        vim_free (buffer);
    if (errmsg != NULL) {
        int numlen = errnum != NULL ? (int) STRLEN (errnum) : 0;
        attr = HL_ATTR (HLF_E);
        msg_add_fname (buf, fname);
        if (STRLEN (IObuff) + STRLEN (errmsg) + numlen >= IOSIZE)
            IObuff[IOSIZE - STRLEN (errmsg) - numlen - 1] = NUL;
        if (errnum != NULL) {
            STRMOVE (IObuff + numlen, IObuff);
            mch_memmove (IObuff, errnum, (size_t) numlen);
        }
        STRCAT (IObuff, errmsg);
        emsg (IObuff);
        if (errmsg_allocated)
            vim_free (errmsg);
        retval = FAIL;
        if (end == 0) {
            MSG_PUTS_ATTR (_ ("\nWARNING: Original file may be lost or damaged\n"), attr | MSG_HIST);
            MSG_PUTS_ATTR (_ ("don't quit the editor until the file is successfully written!"), attr | MSG_HIST);
            if (mch_stat ((char *) fname, &st_old) >= 0) {
                buf_store_time (buf, & st_old, fname);
                buf->b_mtime_read = buf->b_mtime;
            }
        }
    }
    msg_scroll = msg_save;
    if (retval == OK && write_undo_file) {
        char_u hash [UNDO_HASH_SIZE];
        sha256_finish (& sha_ctx, hash);
        u_write_undo (NULL, FALSE, buf, hash);
    }
    if (!should_abort (retval)) {
        aco_save_T aco;
        curbuf->b_no_eol_lnum = 0;
        aucmd_prepbuf (& aco, buf);
        if (append)
            apply_autocmds_exarg (EVENT_FILEAPPENDPOST, fname, fname, FALSE, curbuf, eap);
        else if (filtering)
            apply_autocmds_exarg (EVENT_FILTERWRITEPOST, NULL, fname, FALSE, curbuf, eap);
        else if (reset_changed && whole)
            apply_autocmds_exarg (EVENT_BUFWRITEPOST, fname, fname, FALSE, curbuf, eap);
        else
            apply_autocmds_exarg (EVENT_FILEWRITEPOST, fname, fname, FALSE, curbuf, eap);
        aucmd_restbuf (& aco);
        if (aborting ())
            retval = FALSE;
    }
    got_int |= prev_got_int;
    return retval;
}

static int set_rw_fname (char_u *fname, char_u *sfname) {
    buf_T *buf = curbuf;
    if (curbuf->b_p_bl)
        apply_autocmds (EVENT_BUFDELETE, NULL, NULL, FALSE, curbuf);
    apply_autocmds (EVENT_BUFWIPEOUT, NULL, NULL, FALSE, curbuf);
    if (aborting ())
        return FAIL;
    if (curbuf != buf) {
        EMSG (_ (e_auchangedbuf));
        return FAIL;
    }
    if (setfname (curbuf, fname, sfname, FALSE) == OK)
        curbuf->b_flags |= BF_NOTEDITED;
    apply_autocmds (EVENT_BUFNEW, NULL, NULL, FALSE, curbuf);
    if (curbuf->b_p_bl)
        apply_autocmds (EVENT_BUFADD, NULL, NULL, FALSE, curbuf);
    if (aborting ())
        return FAIL;
    if (*curbuf->b_p_ft == NUL) {
        if (au_has_group ((char_u *) "filetypedetect"))
            (void) do_doautocmd ((char_u *) "filetypedetect BufRead", FALSE, NULL);
        do_modelines (0);
    }
    return OK;
}

char_u *modname (char_u *fname, char_u *ext, int prepend_dot) {
    return buf_modname ((curbuf->b_p_sn || curbuf->b_shortname), fname, ext, prepend_dot);
}

int au_has_group (char_u *name) {
    return au_find_group (name) != AUGROUP_ERROR;
}

static int au_find_group (char_u *name) {
    int i;
    for (i = 0; i < augroups.ga_len; ++i)
        if (AUGROUP_NAME (i) != NULL && AUGROUP_NAME (i) != get_deleted_augroup () && STRCMP (AUGROUP_NAME (i), name) == 0)
            return i;
    return AUGROUP_ERROR;
}

static char_u *get_deleted_augroup (void) {
    if (deleted_augroup == NULL)
        deleted_augroup = (char_u *) _ ("--Deleted--");
    return deleted_augroup;
}

int do_doautocmd (char_u *arg, int do_msg, int *did_something) {
    char_u *fname;
    int nothing_done = TRUE;
    int group;
    if (did_something != NULL)
        *did_something = FALSE;
    group = au_get_grouparg (&arg);
    if (arg == NULL)
        return FAIL;
    if (*arg == '*') {
        EMSG (_ ("E217: Can't execute autocommands for ALL events"));
        return FAIL;
    }
    fname = find_end_event (arg, group != AUGROUP_ALL);
    if (fname == NULL)
        return FAIL;
    fname = skipwhite (fname);
    while (*arg && !ends_excmd (*arg) && !VIM_ISWHITE (*arg))
        if (apply_autocmds_group (event_name2nr (arg, &arg), fname, NULL, TRUE, group, curbuf, NULL))
            nothing_done = FALSE;
    if (nothing_done && do_msg)
        MSG (_ ("No matching autocommands"));
    if (did_something != NULL)
        *did_something = !nothing_done;
    return aborting () ? FAIL : OK;
}

static int au_get_grouparg (char_u **argp) {
    char_u *group_name;
    char_u *p;
    char_u *arg = *argp;
    int group = AUGROUP_ALL;
    for (p = arg; *p && !VIM_ISWHITE (*p) && *p != '|'; ++p)
        ;
    if (p > arg) {
        group_name = vim_strnsave (arg, (int) (p - arg));
        if (group_name == NULL)
            return AUGROUP_ERROR;
        group = au_find_group (group_name);
        if (group == AUGROUP_ERROR)
            group = AUGROUP_ALL;
        else
            *argp = skipwhite (p);
        vim_free (group_name);
    }
    return group;
}

static char_u *find_end_event (char_u *arg, int have_group) {
    char_u *pat;
    char_u *p;
    if (*arg == '*') {
        if (arg[1] && !VIM_ISWHITE (arg[1])) {
            EMSG2 (_ ("E215: Illegal character after *: %s"), arg);
            return NULL;
        }
        pat = arg + 1;
    }
    else {
        for (pat = arg; *pat && *pat != '|' && !VIM_ISWHITE (*pat); pat = p) {
            if ((int) event_name2nr (pat, &p) >= (int) NUM_EVENTS) {
                if (have_group)
                    EMSG2 (_ ("E216: No such event: %s"), pat);
                else
                    EMSG2 (_ ("E216: No such group or event: %s"), pat);
                return NULL;
            }
        }
    }
    return pat;
}

static int apply_autocmds_exarg (event_T event, char_u *fname, char_u *fname_io, int force, buf_T *buf, exarg_T *eap) {
    return apply_autocmds_group (event, fname, fname_io, force, AUGROUP_ALL, buf, eap);
}

void aucmd_restbuf (aco_save_T *aco) {
    int dummy;
    if (aco->use_aucmd_win) {
        --curbuf->b_nwindows;
        block_autocmds ();
        if (curwin != aucmd_win) {
            tabpage_T *tp;
            win_T *wp;
            FOR_ALL_TAB_WINDOWS (tp, wp) {
                if (wp == aucmd_win) {
                    if (tp != curtab)
                        goto_tabpage_tp (tp, TRUE, TRUE);
                    win_goto (aucmd_win);
                    goto win_found;
                }
            }
        }
    win_found :
        (void) winframe_remove (curwin, &dummy, NULL);
        win_remove (curwin, NULL);
        aucmd_win_used = FALSE;
        last_status (FALSE);
        if (!valid_tabpage_win (curtab))
            close_tabpage (curtab);
        restore_snapshot (SNAP_AUCMD_IDX, FALSE);
        (void) win_comp_pos ();
        unblock_autocmds ();
        if (win_valid (aco->save_curwin))
            curwin = aco->save_curwin;
        else
            curwin = firstwin;
        vars_clear (& aucmd_win -> w_vars -> dv_hashtab);
        hash_init (& aucmd_win -> w_vars -> dv_hashtab);
        curbuf = curwin->w_buffer;
        vim_free (globaldir);
        globaldir = aco->globaldir;
        check_cursor ();
        if (curwin->w_topline > curbuf->b_ml.ml_line_count) {
            curwin->w_topline = curbuf->b_ml.ml_line_count;
            curwin->w_topfill = 0;
        }
        gui_mch_enable_scrollbar (& aucmd_win -> w_scrollbars [SBAR_LEFT], FALSE);
        gui_mch_enable_scrollbar (& aucmd_win -> w_scrollbars [SBAR_RIGHT], FALSE);
        gui_may_update_scrollbars ();
    }
    else {
        if (win_valid (aco->save_curwin)) {
            if (curwin == aco->new_curwin && curbuf != aco->new_curbuf.br_buf && bufref_valid (&aco->new_curbuf) && aco->new_curbuf.br_buf->b_ml.ml_mfp != NULL) {
                if (curwin->w_s == &curbuf->b_s)
                    curwin->w_s = &aco->new_curbuf.br_buf->b_s;
                --curbuf->b_nwindows;
                curbuf = aco->new_curbuf.br_buf;
                curwin->w_buffer = curbuf;
                ++curbuf->b_nwindows;
            }
            curwin = aco->save_curwin;
            curbuf = curwin->w_buffer;
            check_cursor ();
        }
    }
}

void filemess (buf_T *buf, char_u *name, char_u *s, int attr) {
    int msg_scroll_save;
    if (msg_silent != 0)
        return;
    msg_add_fname (buf, name);
    if (STRLEN (IObuff) > IOSIZE - 80)
        IObuff[IOSIZE - 80] = NUL;
    STRCAT (IObuff, s);
    msg_scroll_save = msg_scroll;
    if (shortmess (SHM_OVERALL) && !exiting && p_verbose == 0)
        msg_scroll = FALSE;
    if (!msg_scroll)
        check_for_delay (FALSE);
    msg_start ();
    msg_scroll = msg_scroll_save;
    msg_scrolled_ign = TRUE;
    msg_outtrans_attr (msg_may_trunc (FALSE, IObuff), attr);
    msg_clr_eos ();
    out_flush ();
    msg_scrolled_ign = FALSE;
}

void msg_add_fname (buf_T *buf, char_u *fname) {
    if (fname == NULL)
        fname = (char_u *) "-stdin-";
    home_replace (buf, fname, IObuff + 1, IOSIZE - 4, TRUE);
    IObuff[0] = '"';
    STRCAT (IObuff, "\" ");
}

static int check_mtime (buf_T *buf, stat_T *st) {
    if (buf->b_mtime_read != 0 && time_differs ((long ) st->st_mtime, buf->b_mtime_read)) {
        msg_scroll = TRUE;
        msg_silent = 0;
        MSG_ATTR (_ ("WARNING: The file has been changed since reading it!!!"), HL_ATTR (HLF_E));
        if (ask_yesno ((char_u *) _ ("Do you really want to write to it"), TRUE) == 'n')
            return FAIL;
        msg_scroll = FALSE;
    }
    return OK;
}

int match_file_list (char_u *list, char_u *sfname, char_u *ffname) {
    char_u buf [100];
    char_u *tail;
    char_u *regpat;
    char allow_dirs;
    int match;
    char_u *p;
    tail = gettail (sfname);
    p = list;
    while (*p) {
        copy_option_part (& p, buf, 100, ",");
        regpat = file_pat_to_reg_pat (buf, NULL, &allow_dirs, FALSE);
        if (regpat == NULL)
            break;
        match = match_file_pat (regpat, NULL, ffname, sfname, tail, (int) allow_dirs);
        vim_free (regpat);
        if (match)
            return TRUE;
    }
    return FALSE;
}

static int buf_write_bytes (struct bw_info *ip) {
    int wlen;
    char_u *buf = ip->bw_buf;
    int len = ip->bw_len;
    if (ip->bw_fd < 0)
        return OK;
    if (flags & FIO_ENCRYPTED) {
        if (crypt_works_inplace (ip->bw_buffer->b_cryptstate)) {
            crypt_encode_inplace (ip -> bw_buffer -> b_cryptstate, buf, len);
        }
        else {
            char_u *outbuf;
            len = crypt_encode_alloc (curbuf->b_cryptstate, buf, len, &outbuf);
            if (len == 0)
                return OK;
            wlen = write_eintr (ip->bw_fd, outbuf, len);
            vim_free (outbuf);
            return (wlen < len) ? FAIL : OK;
        }
    }
    wlen = write_eintr (ip->bw_fd, buf, len);
    return (wlen < len) ? FAIL : OK;
}

static void set_file_time (char_u *fname, time_t atime, time_t mtime) {
}

static void msg_add_eol (void) {
    STRCAT (IObuff, shortmess (SHM_LAST) ? _ ("[noeol]") : _ ("[Incomplete last line]"));
}

static int msg_add_fileformat (int eol_type) {
    if (eol_type == EOL_DOS) {
        STRCAT (IObuff, shortmess (SHM_TEXT) ? _ ("[dos]") : _ ("[dos format]"));
        return TRUE;
    }
    if (eol_type == EOL_MAC) {
        STRCAT (IObuff, shortmess (SHM_TEXT) ? _ ("[mac]") : _ ("[mac format]"));
        return TRUE;
    }
    return FALSE;
}

void msg_add_lines (int insert_space, long  lnum, off_T nchars) {
    char_u *p;
    p = IObuff + STRLEN (IObuff);
    if (insert_space)
        *p++ = ' ';
    if (shortmess (SHM_LINES))
        vim_snprintf ((char *) p, IOSIZE -(p - IObuff), "%ldL, %lldC", lnum, (varnumber_T) nchars);
    else {
        if (lnum == 1)
            STRCPY (p, _ ("1 line, "));
        else
            sprintf ((char *) p, _ ("%ld lines, "), lnum);
        p += STRLEN (p);
        if (nchars == 1)
            STRCPY (p, _ ("1 character"));
        else
            vim_snprintf ((char *) p, IOSIZE -(p - IObuff), _ ("%lld characters"), (varnumber_T) nchars);
    }
}

void set_file_options (int set_options, exarg_T *eap) {
    if (set_options) {
        if (eap != NULL && eap->force_ff != 0)
            set_fileformat (get_fileformat_force (curbuf, eap), OPT_LOCAL);
        else if (*p_ffs != NUL)
            set_fileformat (default_fileformat (), OPT_LOCAL);
    }
    if (eap != NULL && eap->force_bin != 0) {
        int oldval = curbuf->b_p_bin;
        curbuf->b_p_bin = (eap->force_bin == FORCE_BIN);
        set_options_bin (oldval, curbuf -> b_p_bin, OPT_LOCAL);
    }
}

int has_cursormovedI (void) {
    return (first_autopat[(int) EVENT_CURSORMOVEDI] != NULL);
}

int has_textchangedI (void) {
    return (first_autopat[(int) EVENT_TEXTCHANGEDI] != NULL);
}

int has_textchangedP (void) {
    return (first_autopat[(int) EVENT_TEXTCHANGEDP] != NULL);
}

char_u *get_event_name (expand_T *xp, int idx) {
    if (idx < augroups.ga_len) {
        if (!include_groups || AUGROUP_NAME (idx) == NULL || AUGROUP_NAME (idx) == get_deleted_augroup ())
            return (char_u *) "";
        return AUGROUP_NAME (idx);
    }
    return (char_u *) event_names[idx - augroups.ga_len].name;
}

char_u *get_augroup_name (expand_T *xp, int idx) {
    if (idx == augroups.ga_len)
        return (char_u *) "END";
    if (idx >= augroups.ga_len)
        return NULL;
    if (AUGROUP_NAME (idx) == NULL || AUGROUP_NAME (idx) == get_deleted_augroup ())
        return (char_u *) "";
    return AUGROUP_NAME (idx);
}

char_u *set_context_in_autocmd (expand_T *xp, char_u *arg, int doautocmd) {
    char_u *p;
    int group;
    include_groups = FALSE;
    p = arg;
    group = au_get_grouparg (&arg);
    if (group == AUGROUP_ERROR)
        return NULL;
    if (*arg == NUL && group != AUGROUP_ALL && !VIM_ISWHITE (arg[-1])) {
        arg = p;
        group = AUGROUP_ALL;
    }
    for (p = arg; *p != NUL && !VIM_ISWHITE (*p); ++p)
        if (*p == ',')
            arg = p + 1;
    if (*p == NUL) {
        if (group == AUGROUP_ALL)
            include_groups = TRUE;
        xp->xp_context = EXPAND_EVENTS;
        xp->xp_pattern = arg;
        return NULL;
    }
    arg = skipwhite (p);
    while (*arg && (!VIM_ISWHITE (*arg) || arg[-1] == '\\'))
        arg++;
    if (*arg)
        return arg;
    if (doautocmd)
        xp->xp_context = EXPAND_FILES;
    else
        xp->xp_context = EXPAND_NOTHING;
    return NULL;
}

int apply_autocmds_retval (event_T event, char_u *fname, char_u *fname_io, int force, buf_T *buf, int *retval) {
    int did_cmd;
    if (should_abort (*retval))
        return FALSE;
    did_cmd = apply_autocmds_group (event, fname, fname_io, force, AUGROUP_ALL, buf, NULL);
    if (did_cmd && aborting ())
        *retval = FAIL;
    return did_cmd;
}

int check_ei (void) {
    char_u *p = p_ei;
    while (*p) {
        if (STRNICMP (p, "all", 3) == 0 && (p[3] == NUL || p[3] == ',')) {
            p += 3;
            if (*p == ',')
                ++p;
        }
        else if (event_name2nr (p, &p) == NUM_EVENTS)
            return FAIL;
    }
    return OK;
}

int has_insertcharpre (void) {
    return (first_autopat[(int) EVENT_INSERTCHARPRE] != NULL);
}

int has_cursormoved (void) {
    return (first_autopat[(int) EVENT_CURSORMOVED] != NULL);
}

int has_textchanged (void) {
    return (first_autopat[(int) EVENT_TEXTCHANGED] != NULL);
}

static void check_marks_read (void) {
    if (!curbuf->b_marks_read && get_viminfo_parameter ('\'') > 0 && curbuf->b_ffname != NULL)
        read_viminfo (NULL, VIF_WANT_MARKS);
    curbuf->b_marks_read = TRUE;
}

static char_u *check_for_cryptkey (char_u *cryptkey, char_u *ptr, long  *sizep, off_T *filesizep, int newfile, char_u *fname, int *did_ask) {
    int method = crypt_method_nr_from_magic ((char *) ptr, *sizep);
    int b_p_ro = curbuf->b_p_ro;
    if (method >= 0) {
        curbuf->b_p_ro = TRUE;
        crypt_set_cm_option (curbuf, method);
        if (cryptkey == NULL && !*did_ask) {
            if (*curbuf->b_p_key)
                cryptkey = curbuf->b_p_key;
            else {
                smsg ((char_u *) _ (need_key_msg), fname);
                msg_scroll = TRUE;
                crypt_check_method (method);
                cryptkey = crypt_get_key (newfile, FALSE);
                *did_ask = TRUE;
                if (cryptkey != NULL && *cryptkey == NUL) {
                    if (cryptkey != curbuf->b_p_key)
                        vim_free (cryptkey);
                    cryptkey = NULL;
                }
            }
        }
        if (cryptkey != NULL) {
            int header_len;
            curbuf->b_cryptstate = crypt_create_from_header (method, cryptkey, ptr);
            crypt_set_cm_option (curbuf, method);
            header_len = crypt_get_header_len (method);
            if (*sizep <= header_len)
                return NULL;
            *filesizep += header_len;
            *sizep -= header_len;
            mch_memmove (ptr, ptr + header_len, (size_t) * sizep);
            curbuf->b_p_ro = b_p_ro;
        }
    }
    else if (newfile && *curbuf->b_p_key != NUL && !starting)
        set_option_value ((char_u *) "key", 0L, (char_u *) "", OPT_LOCAL);
    return cryptkey;
}

void buf_reload (buf_T *buf, int orig_mode) {
    exarg_T ea;
    pos_T old_cursor;
    linenr_T old_topline;
    int old_ro = buf->b_p_ro;
    buf_T *savebuf;
    bufref_T bufref;
    int saved = OK;
    aco_save_T aco;
    int flags = READ_NEW;
    aucmd_prepbuf (& aco, buf);
    if (prep_exarg (&ea, buf) == OK) {
        old_cursor = curwin->w_cursor;
        old_topline = curwin->w_topline;
        if (p_ur < 0 || curbuf->b_ml.ml_line_count <= p_ur) {
            u_sync (FALSE);
            saved = u_savecommon (0, curbuf->b_ml.ml_line_count + 1, 0, TRUE);
            flags |= READ_KEEP_UNDO;
        }
        if (BUFEMPTY () || saved == FAIL)
            savebuf = NULL;
        else {
            savebuf = buflist_new (NULL, NULL, (linenr_T) 1, BLN_DUMMY);
            set_bufref (& bufref, savebuf);
            if (savebuf != NULL && buf == curbuf) {
                curbuf = savebuf;
                curwin->w_buffer = savebuf;
                saved = ml_open (curbuf);
                curbuf = buf;
                curwin->w_buffer = buf;
            }
            if (savebuf == NULL || saved == FAIL || buf != curbuf || move_lines (buf, savebuf) == FAIL) {
                EMSG2 (_ ("E462: Could not prepare for reloading \"%s\""), buf -> b_fname);
                saved = FAIL;
            }
        }
        if (saved == OK) {
            curbuf->b_flags |= BF_CHECK_RO;
            keep_filetype = TRUE;
            if (readfile (buf->b_ffname, buf->b_fname, (linenr_T) 0, (linenr_T) 0, (linenr_T) MAXLNUM, &ea, flags) != OK) {
                if (!aborting ())
                    EMSG2 (_ ("E321: Could not reload \"%s\""), buf->b_fname);
                if (savebuf != NULL && bufref_valid (&bufref) && buf == curbuf) {
                    while (!BUFEMPTY ())
                        if (ml_delete (buf->b_ml.ml_line_count, FALSE) == FAIL)
                            break;
                    (void) move_lines (savebuf, buf);
                }
            }
            else if (buf == curbuf) {
                unchanged (buf, TRUE);
                if ((flags & READ_KEEP_UNDO) == 0) {
                    u_blockfree (buf);
                    u_clearall (buf);
                }
                else {
                    u_unchanged (curbuf);
                }
            }
        }
        vim_free (ea.cmd);
        if (savebuf != NULL && bufref_valid (&bufref))
            wipe_buffer (savebuf, FALSE);
        diff_invalidate (curbuf);
        if (old_topline > curbuf->b_ml.ml_line_count)
            curwin->w_topline = curbuf->b_ml.ml_line_count;
        else
            curwin->w_topline = old_topline;
        curwin->w_cursor = old_cursor;
        check_cursor ();
        update_topline ();
        keep_filetype = FALSE;
        {
            win_T *wp;
            tabpage_T *tp;
            FOR_ALL_TAB_WINDOWS (tp, wp)
                if (wp->w_buffer == curwin->w_buffer && !foldmethodIsManual (wp))
                    foldUpdateAll (wp);
        }
        if (orig_mode == curbuf->b_orig_mode)
            curbuf->b_p_ro |= old_ro;
        do_modelines (0);
    }
    aucmd_restbuf (& aco);
}

static int move_lines (buf_T *frombuf, buf_T *tobuf) {
    buf_T *tbuf = curbuf;
    int retval = OK;
    linenr_T lnum;
    char_u *p;
    curbuf = tobuf;
    for (lnum = 1; lnum <= frombuf->b_ml.ml_line_count; ++lnum) {
        p = vim_strsave (ml_get_buf (frombuf, lnum, FALSE));
        if (p == NULL || ml_append (lnum -1, p, 0, FALSE) == FAIL) {
            vim_free (p);
            retval = FAIL;
            break;
        }
        vim_free (p);
    }
    if (retval != FAIL) {
        curbuf = frombuf;
        for (lnum = curbuf->b_ml.ml_line_count; lnum > 0; --lnum)
            if (ml_delete (lnum, FALSE) == FAIL) {
                retval = FAIL;
                break;
            }
    }
    curbuf = tbuf;
    return retval;
}

int has_textyankpost (void) {
    return (first_autopat[(int) EVENT_TEXTYANKPOST] != NULL);
}

char_u *getnextac (int c, void *cookie, int indent) {
    AutoPatCmd *acp = (AutoPatCmd *) cookie;
    char_u *retval;
    AutoCmd *ac;
    if (acp->curpat == NULL)
        return NULL;
    for (;;) {
        while (acp->nextcmd != NULL && acp->nextcmd->cmd == NULL)
            if (acp->nextcmd->last)
                acp->nextcmd = NULL;
            else
                acp->nextcmd = acp->nextcmd->next;
        if (acp->nextcmd != NULL)
            break;
        if (acp->curpat->last)
            acp->curpat = NULL;
        else
            acp->curpat = acp->curpat->next;
        if (acp->curpat != NULL)
            auto_next_pat (acp, TRUE);
        if (acp->curpat == NULL)
            return NULL;
    }
    ac = acp->nextcmd;
    if (p_verbose >= 9) {
        verbose_enter_scroll ();
        smsg ((char_u *) _ ("autocommand %s"), ac -> cmd);
        msg_puts ((char_u *) "\n");
        verbose_leave_scroll ();
    }
    retval = vim_strsave (ac->cmd);
    autocmd_nested = ac->nested;
    current_SID = ac->scriptID;
    if (ac->last)
        acp->nextcmd = NULL;
    else
        acp->nextcmd = ac->next;
    return retval;
}

int has_cmdundefined (void) {
    return (first_autopat[(int) EVENT_CMDUNDEFINED] != NULL);
}

static void vim_settempdir (char_u *tempdir) {
    char_u *buf;
    buf = alloc ((unsigned ) MAXPATHL + 2);
    if (buf != NULL) {
        if (vim_FullName (tempdir, buf, MAXPATHL, FALSE) == FAIL)
            STRCPY (buf, tempdir);
        add_pathsep (buf);
        vim_tempdir = vim_strsave (buf);
        vim_free (buf);
    }
}

int autocmd_supported (char_u *name) {
    char_u *p;
    return (event_name2nr (name, &p) != NUM_EVENTS);
}

int au_exists (char_u *arg) {
    char_u *arg_save;
    char_u *pattern = NULL;
    char_u *event_name;
    char_u *p;
    event_T event;
    AutoPat *ap;
    buf_T *buflocal_buf = NULL;
    int group;
    int retval = FALSE;
    arg_save = vim_strsave (arg);
    if (arg_save == NULL)
        return FALSE;
    p = vim_strchr (arg_save, '#');
    if (p != NULL)
        *p++ = NUL;
    group = au_find_group (arg_save);
    if (group == AUGROUP_ERROR) {
        group = AUGROUP_ALL;
        event_name = arg_save;
    }
    else {
        if (p == NULL) {
            retval = TRUE;
            goto theend;
        }
        event_name = p;
        p = vim_strchr (event_name, '#');
        if (p != NULL)
            *p++ = NUL;
    }
    pattern = p;
    event = event_name2nr (event_name, &p);
    if (event == NUM_EVENTS)
        goto theend;
    ap = first_autopat[(int) event];
    if (ap == NULL)
        goto theend;
    if (pattern != NULL && STRICMP (pattern, "<buffer>") == 0)
        buflocal_buf = curbuf;
    for (; ap != NULL; ap = ap->next)
        if (ap->pat != NULL && ap->cmds != NULL && (group == AUGROUP_ALL || ap->group == group) && (pattern == NULL || (buflocal_buf == NULL ? fnamecmp (ap->pat, pattern) == 0 : ap->buflocal_nr == buflocal_buf->b_fnum))) {
            retval = TRUE;
            break;
        }
theend :
    vim_free (arg_save);
    return retval;
}

