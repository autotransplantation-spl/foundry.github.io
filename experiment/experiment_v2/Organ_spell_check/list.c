
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
struct join_S {
    char_u *s;
    char_u *tofree;
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
EXTERN char_u e_write [] INIT (= N_ ("E80: Error while writing"));
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u *globaldir INIT (= NULL);
EXTERN char_u e_toomanyarg [] INIT (= N_ ("E118: Too many arguments for function: %s"));
EXTERN char_u e_argreq [] INIT (= N_ ("E471: Argument required"));
EXTERN char_u e_emptykey [] INIT (= N_ ("E713: Cannot use empty key for Dictionary"));
EXTERN char_u e_endfor [] INIT (= N_ ("E170: Missing :endfor"));
EXTERN char_u e_endwhile [] INIT (= N_ ("E170: Missing :endwhile"));
EXTERN char_u e_endtry [] INIT (= N_ ("E600: Missing :endtry"));
EXTERN char_u e_endif [] INIT (= N_ ("E171: Missing :endif"));
EXTERN char_u *empty_option INIT (= (char_u *) "");
EXTERN char_u e_readonlyvar [] INIT (= N_ ("E46: Cannot change read-only variable \"%s\""));
EXTERN char_u e_noroom [] INIT (= N_ ("E36: Not enough room"));
EXTERN char_u e_invarg2 [] INIT (= N_ ("E475: Invalid argument: %s"));
EXTERN char_u e_invarg [] INIT (= N_ ("E474: Invalid argument"));
EXTERN win_T *au_pending_free_win INIT (= NULL);
EXTERN char_u e_prev_dir [] INIT (= N_ ("E459: Cannot go back to previous directory"));
EXTERN char_u e_noprevre [] INIT (= N_ ("E35: No previous regular expression"));
EXTERN char_u e_noprev [] INIT (= N_ ("E34: No previous command"));
EXTERN win_T *prevwin INIT (= NULL);
EXTERN char_u e_umark [] INIT (= N_ ("E78: Unknown mark"));
EXTERN char_u farsi_text_5 [];
EXTERN char_u farsi_text_3 [];
EXTERN char_u farsi_text_2 [];
EXTERN char_u farsi_text_1 [];
EXTERN char need_key_msg [] INIT (= N_ ("Need encryption key for \"%s\""));
EXTERN char_u e_toomsbra [] INIT (= N_ ("E76: Too many ["));
EXTERN char_u e_shellempty [] INIT (= N_ ("E91: 'shell' option is empty"));
EXTERN char_u e_listreq [] INIT (= N_ ("E714: List required"));
EXTERN char_u e_readonlysbx [] INIT (= N_ ("E794: Cannot set variable in the sandbox: \"%s\""));
EXTERN char_u e_noserver [] INIT (= N_ ("E247: no registered server named \"%s\""));
EXTERN char_u e_nopresub [] INIT (= N_ ("E33: No previous substitute regular expression"));
EXTERN char_u e_noinstext [] INIT (= N_ ("E29: No inserted text yet"));
EXTERN char_u e_nesting [] INIT (= N_ ("E22: Scripts nested too deep"));
EXTERN char_u e_marknotset [] INIT (= N_ ("E20: Mark not set"));
EXTERN char_u e_isadir2 [] INIT (= N_ ("E17: \"%s\" is a directory"));
EXTERN char_u e_exists [] INIT (= N_ ("E13: File exists (add ! to override)"));
EXTERN char *netbeansArg INIT (= NULL);
EXTERN char_u *serverName INIT (= NULL);
EXTERN option_table_T printer_opts [OPT_PRINT_NUM_OPTIONS];
EXTERN char_u wim_flags [4];
EXTERN linenr_T sub_nlines;
EXTERN long  sub_nsubs;
EXTERN char_u no_lines_msg [] INIT (= N_ ("--No lines in buffer--"));
EXTERN char breakat_flags [256];
EXTERN char_u *edit_submode_extra INIT (= NULL);
EXTERN char_u *edit_submode_pre INIT (= NULL);
EXTERN char_u *edit_submode INIT (= NULL);
EXTERN int arrow_used;
EXTERN alist_T global_alist;
EXTERN tabpage_T *first_tabpage;
EXTERN win_T *lastwin;
EXTERN win_T *firstwin;
EXTERN int mouse_row;
EXTERN int modified_was_set;
EXTERN char_u hash_removed;
EXTERN struct msglist **msg_list INIT (= NULL);
EXTERN char_u *keep_msg INIT (= NULL);
EXTERN int msg_row;
EXTERN short  *TabPageIdxs INIT (= NULL);
EXTERN char_u *LineWraps INIT (= NULL);
EXTERN unsigned  *LineOffset INIT (= NULL);
SPELL_EXTERN spelltab_T spelltab;
SPELL_EXTERN char_u *int_wordlist SPELL_INIT (= NULL);
SPELL_EXTERN slang_T *first_lang SPELL_INIT (= NULL);
EXTERN int p_ws;
EXTERN long  p_verbose;
EXTERN unsigned  ve_flags;
EXTERN unsigned  vop_flags;
EXTERN unsigned  ttym_flags;
EXTERN unsigned  tbis_flags;
EXTERN char_u *p_tbis;
EXTERN unsigned  toolbar_flags;
EXTERN long  p_transp;
EXTERN char_u *p_tsr;
EXTERN char_u *p_titlestring;
EXTERN int p_terse;
EXTERN int p_tgst;
EXTERN char_u *p_tags;
EXTERN int p_tbs;
EXTERN char_u *p_swb;
EXTERN char_u *p_sws;
EXTERN char_u *p_su;
EXTERN int p_sol;
EXTERN int p_spr;
EXTERN char_u *p_sps;
EXTERN int p_sb;
EXTERN int p_sta;
EXTERN long  p_siso;
EXTERN long  p_ss;
EXTERN int p_smd;
EXTERN int p_sm;
EXTERN int p_sft;
EXTERN char_u *p_sbr;
EXTERN char_u *p_shm;
EXTERN int p_sr;
EXTERN char_u *p_stl;
EXTERN char_u *p_srr;
EXTERN char_u *p_sxe;
EXTERN char_u *p_sxq;
EXTERN char_u *p_shq;
EXTERN char_u *p_sp;
EXTERN char_u *p_sh;
EXTERN unsigned  ssop_flags;
EXTERN char_u *p_ssop;
EXTERN char_u *p_slm;
EXTERN char_u *p_sel;
EXTERN char_u *p_sbo;
EXTERN long  p_so;
EXTERN long  p_sj;
EXTERN int p_paste;
EXTERN long  p_mouset;
EXTERN char_u *p_mousem;
EXTERN int p_mousef;
EXTERN char_u *p_mouse;
EXTERN long  p_mls;
EXTERN char_u *p_msm;
EXTERN long  p_mis;
EXTERN long  p_stal;
EXTERN long  p_ls;
EXTERN char_u *p_lispwords;
EXTERN int p_js;
EXTERN char_u *p_isp;
EXTERN char_u *p_isi;
EXTERN char_u *p_isf;
EXTERN int p_is;
EXTERN int p_arshape;
EXTERN char_u *p_mouseshape;
EXTERN unsigned  fuoptions_flags;
EXTERN char_u *p_fuoptions;
EXTERN unsigned  fdo_flags;
EXTERN long  p_fdls;
EXTERN char_u *p_ffs;
EXTERN unsigned  dy_flags;
EXTERN char_u *p_bsk;
EXTERN unsigned  bo_flags;
EXTERN char_u *p_bs;
list_T *first_list = NULL;
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

int get_list_tv (char_u **arg, typval_T *rettv, int evaluate) {
    list_T *l = NULL;
    typval_T tv;
    listitem_T *item;
    if (evaluate) {
        l = list_alloc ();
        if (l == NULL)
            return FAIL;
    }
    *arg = skipwhite (*arg + 1);
    while (**arg != ']' && **arg != NUL) {
        if (eval1 (arg, &tv, evaluate) == FAIL)
            goto failret;
        if (evaluate) {
            item = listitem_alloc ();
            if (item != NULL) {
                item->li_tv = tv;
                item->li_tv.v_lock = 0;
                list_append (l, item);
            }
            else
                clear_tv (&tv);
        }
        if (**arg == ']')
            break;
        if (**arg != ',') {
            EMSG2 (_ ("E696: Missing comma in List: %s"), * arg);
            goto failret;
        }
        *arg = skipwhite (*arg + 1);
    }
    if (**arg != ']') {
        EMSG2 (_ ("E697: Missing end of List ']': %s"), * arg);
    failret :
        if (evaluate)
            list_free (l);
        return FAIL;
    }
    *arg = skipwhite (*arg + 1);
    if (evaluate)
        rettv_list_set (rettv, l);
    return OK;
}

list_T *list_alloc (void) {
    list_T *l;
    l = (list_T *) alloc_clear (sizeof (list_T));
    if (l != NULL) {
        if (first_list != NULL)
            first_list->lv_used_prev = l;
        l->lv_used_prev = NULL;
        l->lv_used_next = first_list;
        first_list = l;
    }
    return l;
}

listitem_T *listitem_alloc (void) {
    return (listitem_T *) alloc (sizeof (listitem_T));
}

void list_append (list_T *l, listitem_T *item) {
    if (l->lv_last == NULL) {
        l->lv_first = item;
        l->lv_last = item;
        item->li_prev = NULL;
    }
    else {
        l->lv_last->li_next = item;
        item->li_prev = l->lv_last;
        l->lv_last = item;
    }
    ++l->lv_len;
    item->li_next = NULL;
}

void list_unref (list_T *l) {
    if (l != NULL && --l->lv_refcount <= 0)
        list_free (l);
}

void list_free (list_T *l) {
    if (!in_free_unref_items) {
        list_free_contents (l);
        list_free_list (l);
    }
}

static void list_free_contents (list_T *l) {
    listitem_T *item;
    for (item = l->lv_first; item != NULL; item = l->lv_first) {
        l->lv_first = item->li_next;
        clear_tv (& item -> li_tv);
        vim_free (item);
    }
}

static void list_free_list (list_T *l) {
    if (l->lv_used_prev == NULL)
        first_list = l->lv_used_next;
    else
        l->lv_used_prev->lv_used_next = l->lv_used_next;
    if (l->lv_used_next != NULL)
        l->lv_used_next->lv_used_prev = l->lv_used_prev;
    vim_free (l);
}

char_u *list2string (typval_T *tv, int copyID, int restore_copyID) {
    garray_T ga;
    if (tv->vval.v_list == NULL)
        return NULL;
    ga_init2 (& ga, (int) sizeof (char), 80);
    ga_append (& ga, '[');
    if (list_join (&ga, tv->vval.v_list, (char_u *) ", ", FALSE, restore_copyID, copyID) == FAIL) {
        vim_free (ga.ga_data);
        return NULL;
    }
    ga_append (& ga, ']');
    ga_append (& ga, NUL);
    return (char_u *) ga.ga_data;
}

int list_join (garray_T *gap, list_T *l, char_u *sep, int echo_style, int restore_copyID, int copyID) {
    garray_T join_ga;
    int retval;
    join_T *p;
    int i;
    if (l->lv_len < 1)
        return OK;
    ga_init2 (& join_ga, (int) sizeof (join_T), l -> lv_len);
    retval = list_join_inner (gap, l, sep, echo_style, restore_copyID, copyID, &join_ga);
    if (join_ga.ga_data != NULL) {
        p = (join_T *) join_ga.ga_data;
        for (i = 0; i < join_ga.ga_len; ++i) {
            vim_free (p -> tofree);
            ++p;
        }
        ga_clear (& join_ga);
    }
    return retval;
}

static int list_join_inner (garray_T *gap, list_T *l, char_u *sep, int echo_style, int restore_copyID, int copyID, garray_T *join_gap) {
    int i;
    join_T *p;
    int len;
    int sumlen = 0;
    int first = TRUE;
    char_u *tofree;
    char_u numbuf [NUMBUFLEN];
    listitem_T *item;
    char_u *s;
    for (item = l->lv_first; item != NULL && !got_int; item = item->li_next) {
        s = echo_string_core (&item->li_tv, &tofree, numbuf, copyID, echo_style, restore_copyID, !echo_style);
        if (s == NULL)
            return FAIL;
        len = (int) STRLEN (s);
        sumlen += len;
        (void) ga_grow (join_gap, 1);
        p = ((join_T *) join_gap->ga_data) + (join_gap->ga_len++);
        if (tofree != NULL || s != numbuf) {
            p->s = s;
            p->tofree = tofree;
        }
        else {
            p->s = vim_strnsave (s, len);
            p->tofree = p->s;
        }
        line_breakcheck ();
        if (did_echo_string_emsg)
            break;
    }
    if (join_gap->ga_len >= 2)
        sumlen += (int) STRLEN (sep) * (join_gap->ga_len - 1);
    if (ga_grow (gap, sumlen +2) == FAIL)
        return FAIL;
    for (i = 0; i < join_gap->ga_len && !got_int; ++i) {
        if (first)
            first = FALSE;
        else
            ga_concat (gap, sep);
        p = ((join_T *) join_gap->ga_data) + i;
        if (p->s != NULL)
            ga_concat (gap, p->s);
        line_breakcheck ();
    }
    return OK;
}

void init_static_list (staticList10_T *sl) {
    list_T *l = &sl->sl_list;
    int i;
    memset (sl, 0, sizeof (staticList10_T));
    l->lv_first = &sl->sl_items[0];
    l->lv_last = &sl->sl_items[9];
    l->lv_refcount = DO_NOT_FREE_CNT;
    l->lv_lock = VAR_FIXED;
    sl->sl_list.lv_len = 10;
    for (i = 0; i < 10; ++i) {
        listitem_T *li = &sl->sl_items[i];
        if (i == 0)
            li->li_prev = NULL;
        else
            li->li_prev = li - 1;
        if (i == 9)
            li->li_next = NULL;
        else
            li->li_next = li + 1;
    }
}

int list_free_nonref (int copyID) {
    list_T *ll;
    int did_free = FALSE;
    for (ll = first_list; ll != NULL; ll = ll->lv_used_next)
        if ((ll->lv_copyID & COPYID_MASK) != (copyID & COPYID_MASK) && ll->lv_watch == NULL) {
            list_free_contents (ll);
            did_free = TRUE;
        }
    return did_free;
}

void list_free_items (int copyID) {
    list_T *ll, *ll_next;
    for (ll = first_list; ll != NULL; ll = ll_next) {
        ll_next = ll->lv_used_next;
        if ((ll->lv_copyID & COPYID_MASK) != (copyID & COPYID_MASK) && ll->lv_watch == NULL) {
            list_free_list (ll);
        }
    }
}

int list_append_string (list_T *l, char_u *str, int len) {
    listitem_T *li = listitem_alloc ();
    if (li == NULL)
        return FAIL;
    list_append (l, li);
    li->li_tv.v_type = VAR_STRING;
    li->li_tv.v_lock = 0;
    if (str == NULL)
        li->li_tv.vval.v_string = NULL;
    else if ((li->li_tv.vval.v_string = (len >= 0 ? vim_strnsave (str, len) : vim_strsave (str))) == NULL)
        return FAIL;
    return OK;
}

int list_equal (list_T *l1, list_T *l2, int ic, int recursive) {
    listitem_T *item1, *item2;
    if (l1 == NULL || l2 == NULL)
        return FALSE;
    if (l1 == l2)
        return TRUE;
    if (list_len (l1) != list_len (l2))
        return FALSE;
    for (item1 = l1->lv_first, item2 = l2->lv_first; item1 != NULL && item2 != NULL; item1 = item1->li_next, item2 = item2->li_next)
        if (!tv_equal (&item1->li_tv, &item2->li_tv, ic, recursive))
            return FALSE;
    return item1 == NULL && item2 == NULL;
}

long  list_len (list_T *l) {
    if (l == NULL)
        return 0L;
    return l->lv_len;
}

char_u *list_find_str (list_T *l, long  idx) {
    listitem_T *li;
    li = list_find (l, idx -1);
    if (li == NULL) {
        EMSGN (_ (e_listidx), idx);
        return NULL;
    }
    return get_tv_string (&li->li_tv);
}

listitem_T *list_find (list_T *l, long  n) {
    listitem_T *item;
    long  idx;
    if (l == NULL)
        return NULL;
    if (n < 0)
        n = l->lv_len + n;
    if (n < 0 || n >= l->lv_len)
        return NULL;
    if (l->lv_idx_item != NULL) {
        if (n < l->lv_idx / 2) {
            item = l->lv_first;
            idx = 0;
        }
        else if (n > (l->lv_idx + l->lv_len) / 2) {
            item = l->lv_last;
            idx = l->lv_len - 1;
        }
        else {
            item = l->lv_idx_item;
            idx = l->lv_idx;
        }
    }
    else {
        if (n < l->lv_len / 2) {
            item = l->lv_first;
            idx = 0;
        }
        else {
            item = l->lv_last;
            idx = l->lv_len - 1;
        }
    }
    while (n > idx) {
        item = item->li_next;
        ++idx;
    }
    while (n < idx) {
        item = item->li_prev;
        --idx;
    }
    l->lv_idx = idx;
    l->lv_idx_item = item;
    return item;
}

long  list_idx_of_item (list_T *l, listitem_T *item) {
    long  idx = 0;
    listitem_T *li;
    if (l == NULL)
        return -1;
    idx = 0;
    for (li = l->lv_first; li != NULL && li != item; li = li->li_next)
        ++idx;
    if (li == NULL)
        return -1;
    return idx;
}

int list_extend (list_T *l1, list_T *l2, listitem_T *bef) {
    listitem_T *item;
    int todo = l2->lv_len;
    for (item = l2->lv_first; item != NULL && --todo >= 0; item = item->li_next)
        if (list_insert_tv (l1, &item->li_tv, bef) == FAIL)
            return FAIL;
    return OK;
}

int list_insert_tv (list_T *l, typval_T *tv, listitem_T *item) {
    listitem_T *ni = listitem_alloc ();
    if (ni == NULL)
        return FAIL;
    copy_tv (tv, & ni -> li_tv);
    list_insert (l, ni, item);
    return OK;
}

void list_insert (list_T *l, listitem_T *ni, listitem_T *item) {
    if (item == NULL)
        list_append (l, ni);
    else {
        ni->li_prev = item->li_prev;
        ni->li_next = item;
        if (item->li_prev == NULL) {
            l->lv_first = ni;
            ++l->lv_idx;
        }
        else {
            item->li_prev->li_next = ni;
            l->lv_idx_item = NULL;
        }
        item->li_prev = ni;
        ++l->lv_len;
    }
}

int list_append_number (list_T *l, varnumber_T n) {
    listitem_T *li;
    li = listitem_alloc ();
    if (li == NULL)
        return FAIL;
    li->li_tv.v_type = VAR_NUMBER;
    li->li_tv.v_lock = 0;
    li->li_tv.vval.v_number = n;
    list_append (l, li);
    return OK;
}

void list_rem_watch (list_T *l, listwatch_T *lwrem) {
    listwatch_T *lw, **lwp;
    lwp = &l->lv_watch;
    for (lw = l->lv_watch; lw != NULL; lw = lw->lw_next) {
        if (lw == lwrem) {
            *lwp = lw->lw_next;
            break;
        }
        lwp = &lw->lw_next;
    }
}

int rettv_list_alloc (typval_T *rettv) {
    list_T *l = list_alloc ();
    if (l == NULL)
        return FAIL;
    rettv->v_lock = 0;
    rettv_list_set (rettv, l);
    return OK;
}

void rettv_list_set (typval_T *rettv, list_T *l) {
    rettv->v_type = VAR_LIST;
    rettv->vval.v_list = l;
    if (l != NULL)
        ++l->lv_refcount;
}

int list_append_tv (list_T *l, typval_T *tv) {
    listitem_T *li = listitem_alloc ();
    if (li == NULL)
        return FAIL;
    copy_tv (tv, & li -> li_tv);
    list_append (l, li);
    return OK;
}

int list_concat (list_T *l1, list_T *l2, typval_T *tv) {
    list_T *l;
    if (l1 == NULL || l2 == NULL)
        return FAIL;
    l = list_copy (l1, FALSE, 0);
    if (l == NULL)
        return FAIL;
    tv->v_type = VAR_LIST;
    tv->vval.v_list = l;
    return list_extend (l, l2, NULL);
}

list_T *list_copy (list_T *orig, int deep, int copyID) {
    list_T *copy;
    listitem_T *item;
    listitem_T *ni;
    if (orig == NULL)
        return NULL;
    copy = list_alloc ();
    if (copy != NULL) {
        if (copyID != 0) {
            orig->lv_copyID = copyID;
            orig->lv_copylist = copy;
        }
        for (item = orig->lv_first; item != NULL && !got_int; item = item->li_next) {
            ni = listitem_alloc ();
            if (ni == NULL)
                break;
            if (deep) {
                if (item_copy (&item->li_tv, &ni->li_tv, deep, copyID) == FAIL) {
                    vim_free (ni);
                    break;
                }
            }
            else
                copy_tv (&item->li_tv, &ni->li_tv);
            list_append (copy, ni);
        }
        ++copy->lv_refcount;
        if (item != NULL) {
            list_unref (copy);
            copy = NULL;
        }
    }
    return copy;
}

int list_append_dict (list_T *list, dict_T *dict) {
    listitem_T *li = listitem_alloc ();
    if (li == NULL)
        return FAIL;
    li->li_tv.v_type = VAR_DICT;
    li->li_tv.v_lock = 0;
    li->li_tv.vval.v_dict = dict;
    list_append (list, li);
    ++dict->dv_refcount;
    return OK;
}

long  list_find_nr (list_T *l, long  idx, int *errorp) {
    listitem_T *li;
    li = list_find (l, idx);
    if (li == NULL) {
        if (errorp != NULL)
            *errorp = TRUE;
        return -1L;
    }
    return (long ) get_tv_number_chk (&li->li_tv, errorp);
}

void listitem_remove (list_T *l, listitem_T *item) {
    vimlist_remove (l, item, item);
    listitem_free (item);
}

void vimlist_remove (list_T *l, listitem_T *item, listitem_T *item2) {
    listitem_T *ip;
    for (ip = item; ip != NULL; ip = ip->li_next) {
        --l->lv_len;
        list_fix_watch (l, ip);
        if (ip == item2)
            break;
    }
    if (item2->li_next == NULL)
        l->lv_last = item->li_prev;
    else
        item2->li_next->li_prev = item->li_prev;
    if (item->li_prev == NULL)
        l->lv_first = item2->li_next;
    else
        item->li_prev->li_next = item2->li_next;
    l->lv_idx_item = NULL;
}

void list_fix_watch (list_T *l, listitem_T *item) {
    listwatch_T *lw;
    for (lw = l->lv_watch; lw != NULL; lw = lw->lw_next)
        if (lw->lw_item == item)
            lw->lw_item = item->li_next;
}

void listitem_free (listitem_T *item) {
    clear_tv (& item -> li_tv);
    vim_free (item);
}

int list_append_list (list1, list2)
    list_T *list1;
    list_T *list2;
{
    listitem_T *li = listitem_alloc ();
    if (li == NULL)
        return FAIL;
    li->li_tv.v_type = VAR_LIST;
    li->li_tv.v_lock = 0;
    li->li_tv.vval.v_list = list2;
    list_append (list1, li);
    ++list2->lv_refcount;
    return OK;
}

int write_list (FILE *fd, list_T *list, int binary) {
    listitem_T *li;
    int c;
    int ret = OK;
    char_u *s;
    for (li = list->lv_first; li != NULL; li = li->li_next) {
        for (s = get_tv_string (&li->li_tv); *s != NUL; ++s) {
            if (*s == '\n')
                c = putc (NUL, fd);
            else
                c = putc (*s, fd);
            if (c == EOF) {
                ret = FAIL;
                break;
            }
        }
        if (!binary || li->li_next != NULL)
            if (putc ('\n', fd) == EOF) {
                ret = FAIL;
                break;
            }
        if (ret == FAIL) {
            EMSG (_ (e_write));
            break;
        }
    }
    return ret;
}

