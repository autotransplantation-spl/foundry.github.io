
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
EXTERN int p_write;
EXTERN char_u e_trailing [] INIT (= N_ ("E488: Trailing characters"));
EXTERN long  p_report;
EXTERN int VIsual_reselect;
EXTERN int p_ru;
EXTERN char_u e_noalt [] INIT (= N_ ("E23: No alternate file"));
EXTERN int p_sol;
EXTERN long  p_fdls;
EXTERN long  p_mls;
char *e_auabort = N_ ("E855: Autocommands caused command to abort");
EXTERN linenr_T printer_page_num;
EXTERN char_u *NameBuff;
EXTERN char_u *serverName INIT (= NULL);
EXTERN int p_title;
char_u *lasttitle = NULL;
EXTERN int modified_was_set;
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
char *msg_qflist = N_ ("[Quickfix List]");
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
char_u *lasticon = NULL;
char *msg_loclist = N_ ("[Location List]");
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
hashtab_T buf_hashtab;
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
int buf_free_count = 0;
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
int top_file_num = 1;
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

buf_T *buflist_findnr (int nr) {
    char_u key [VIM_SIZEOF_INT * 2 + 1];
    hashitem_T *hi;
    if (nr == 0)
        nr = curwin->w_alt_fnum;
    sprintf ((char *) key, "%x", nr);
    hi = hash_find (&buf_hashtab, key);
    if (!HASHITEM_EMPTY (hi))
        return (buf_T *) (hi->hi_key - ((unsigned ) (curbuf->b_key - (char_u *) curbuf)));
    return NULL;
}

int buflist_findpat (char_u *pattern, char_u *pattern_end, int unlisted, int diffmode, int curtab_only) {
    buf_T *buf;
    int match = -1;
    int find_listed;
    char_u *pat;
    char_u *patend;
    int attempt;
    char_u *p;
    int toggledollar;
    if (pattern_end == pattern + 1 && (*pattern == '%' || *pattern == '#')) {
        if (*pattern == '%')
            match = curbuf->b_fnum;
        else
            match = curwin->w_alt_fnum;
        if (diffmode && !diff_mode_buf (buflist_findnr (match)))
            match = -1;
    }
    else {
        pat = file_pat_to_reg_pat (pattern, pattern_end, NULL, FALSE);
        if (pat == NULL)
            return -1;
        patend = pat + STRLEN (pat) - 1;
        toggledollar = (patend > pat && *patend == '$');
        find_listed = TRUE;
        for (;;) {
            for (attempt = 0; attempt <= 3; ++attempt) {
                regmatch_T regmatch;
                if (toggledollar)
                    *patend = (attempt < 2) ? NUL : '$';
                p = pat;
                if (*p == '^' && !(attempt & 1))
                    ++p;
                regmatch.regprog = vim_regcomp (p, p_magic ? RE_MAGIC : 0);
                if (regmatch.regprog == NULL) {
                    vim_free (pat);
                    return -1;
                }
                for (buf = lastbuf; buf != NULL; buf = buf->b_prev)
                    if (buf->b_p_bl == find_listed && (!diffmode || diff_mode_buf (buf)) && buflist_match (&regmatch, buf, FALSE) != NULL) {
                        if (curtab_only) {
                            win_T *wp;
                            FOR_ALL_WINDOWS (wp)
                                if (wp->w_buffer == buf)
                                    break;
                            if (wp == NULL)
                                continue;
                        }
                        if (match >= 0) {
                            match = -2;
                            break;
                        }
                        match = buf->b_fnum;
                    }
                vim_regfree (regmatch.regprog);
                if (match >= 0)
                    break;
            }
            if (!unlisted || !find_listed || match != -1)
                break;
            find_listed = FALSE;
        }
        vim_free (pat);
    }
    if (match == -2)
        EMSG2 (_ ("E93: More than one match for %s"), pattern);
    else if (match < 0)
        EMSG2 (_ ("E94: No matching buffer for %s"), pattern);
    return match;
}

int open_buffer (int read_stdin, exarg_T *eap, int flags) {
    int retval = OK;
    bufref_T old_curbuf;
    long  old_tw = curbuf->b_p_tw;
    int read_fifo = FALSE;
    if (readonlymode && curbuf->b_ffname != NULL && (curbuf->b_flags & BF_NEVERLOADED))
        curbuf->b_p_ro = TRUE;
    if (ml_open (curbuf) == FAIL) {
        close_buffer (NULL, curbuf, 0, FALSE);
        FOR_ALL_BUFFERS (curbuf)
            if (curbuf->b_ml.ml_mfp != NULL)
                break;
        if (curbuf == NULL) {
            EMSG (_ ("E82: Cannot allocate any buffer, exiting..."));
            getout (2);
        }
        EMSG (_ ("E83: Cannot allocate buffer, using other one..."));
        enter_buffer (curbuf);
        if (old_tw != curbuf->b_p_tw)
            check_colorcolumn (curwin);
        return FAIL;
    }
    set_bufref (& old_curbuf, curbuf);
    modified_was_set = FALSE;
    curwin->w_valid = 0;
    if (curbuf->b_ffname != NULL && netbeansReadFile) {
        int old_msg_silent = msg_silent;
        int save_bin = curbuf->b_p_bin;
        int perm;
        int oldFire = netbeansFireChanges;
        netbeansFireChanges = 0;
        perm = mch_getperm (curbuf->b_ffname);
        if (perm >= 0 && (0))
            read_fifo = TRUE;
        if (read_fifo)
            curbuf->b_p_bin = TRUE;
        if (shortmess (SHM_FILEINFO))
            msg_silent = 1;
        retval = readfile (curbuf->b_ffname, curbuf->b_fname, (linenr_T) 0, (linenr_T) 0, (linenr_T) MAXLNUM, eap, flags | READ_NEW | (read_fifo ? READ_FIFO : 0));
        if (read_fifo) {
            curbuf->b_p_bin = save_bin;
            if (retval == OK)
                retval = read_buffer (FALSE, eap, flags);
        }
        msg_silent = old_msg_silent;
        netbeansFireChanges = oldFire;
        if (bt_help (curbuf))
            fix_help_buffer ();
    }
    else if (read_stdin) {
        int save_bin = curbuf->b_p_bin;
        curbuf->b_p_bin = TRUE;
        retval = readfile (NULL, NULL, (linenr_T) 0, (linenr_T) 0, (linenr_T) MAXLNUM, NULL, flags | (READ_NEW + READ_STDIN));
        curbuf->b_p_bin = save_bin;
        if (retval == OK)
            retval = read_buffer (TRUE, eap, flags);
    }
    if (curbuf->b_flags & BF_NEVERLOADED) {
        (void) buf_init_chartab (curbuf, FALSE);
        parse_cino (curbuf);
    }
    if ((got_int && vim_strchr (p_cpo, CPO_INTMOD) != NULL) || modified_was_set || (aborting () && vim_strchr (p_cpo, CPO_INTMOD) != NULL))
        changed ();
    else if (retval == OK && !read_stdin && !read_fifo)
        unchanged (curbuf, FALSE);
    save_file_ff (curbuf);
    if (aborting ())
        curbuf->b_flags |= BF_READERR;
    foldUpdateAll (curwin);
    if (!(curwin->w_valid & VALID_TOPLINE)) {
        curwin->w_topline = 1;
        curwin->w_topfill = 0;
    }
    apply_autocmds_retval (EVENT_BUFENTER, NULL, NULL, FALSE, curbuf, & retval);
    if (retval == OK) {
        if (bufref_valid (&old_curbuf) && old_curbuf.br_buf->b_ml.ml_mfp != NULL) {
            aco_save_T aco;
            aucmd_prepbuf (& aco, old_curbuf.br_buf);
            do_modelines (0);
            curbuf->b_flags &= ~(BF_CHECK_RO | BF_NEVERLOADED);
            apply_autocmds_retval (EVENT_BUFWINENTER, NULL, NULL, FALSE, curbuf, & retval);
            aucmd_restbuf (& aco);
        }
    }
    return retval;
}

int bufref_valid (bufref_T *bufref) {
    return bufref->br_buf_free_count == buf_free_count ? TRUE : buf_valid (bufref->br_buf) && bufref->br_fnum == bufref->br_buf->b_fnum;
}

int buf_valid (buf_T *buf) {
    buf_T *bp;
    for (bp = lastbuf; bp != NULL; bp = bp->b_prev)
        if (bp == buf)
            return TRUE;
    return FALSE;
}

void maketitle (void) {
    char_u *p;
    char_u *t_str = NULL;
    char_u *i_name;
    char_u *i_str = NULL;
    int maxlen = 0;
    int len;
    int mustset;
    char_u buf [IOSIZE];
    int off;
    if (!redrawing ()) {
        need_maketitle = TRUE;
        return;
    }
    gui_macvim_update_modified_flag ();
    need_maketitle = FALSE;
    if (!p_title && !p_icon && lasttitle == NULL && lasticon == NULL)
        return;
    if (p_title) {
        if (p_titlelen > 0) {
            maxlen = p_titlelen * Columns / 100;
            if (maxlen < 10)
                maxlen = 10;
        }
        t_str = buf;
        if (*p_titlestring != NUL) {
            if (stl_syntax & STL_IN_TITLE) {
                int use_sandbox = FALSE;
                int save_called_emsg = called_emsg;
                use_sandbox = was_set_insecurely ((char_u *) "titlestring", 0);
                called_emsg = FALSE;
                build_stl_str_hl (curwin, t_str, sizeof (buf), p_titlestring, use_sandbox, 0, maxlen, NULL, NULL);
                if (called_emsg)
                    set_string_option_direct ((char_u *) "titlestring", -1, (char_u *) "", OPT_FREE, SID_ERROR);
                called_emsg |= save_called_emsg;
            }
            else
                t_str = p_titlestring;
        }
        else {

            #define SPACE_FOR_FNAME (IOSIZE - 100)

            #define SPACE_FOR_DIR   (IOSIZE - 20)

            #define SPACE_FOR_ARGNR (IOSIZE - 10)  /* at least room for " - VIM" */
            if (curbuf->b_fname == NULL)
                vim_strncpy (buf, (char_u *) _ ("[No Name]"), SPACE_FOR_FNAME);
            else if (curbuf->b_term != NULL) {
                vim_strncpy (buf, term_get_status_text (curbuf -> b_term), SPACE_FOR_FNAME);
            }
            else {
                p = transstr (gettail (curbuf->b_fname));
                vim_strncpy (buf, p, SPACE_FOR_FNAME);
                vim_free (p);
            }
            if (curbuf->b_term == NULL)
                switch (bufIsChanged (curbuf) + (curbuf->b_p_ro * 2) + (!curbuf->b_p_ma * 4)) {
                case 1 :
                    STRCAT (buf, " +");
                    break;
                case 2 :
                    STRCAT (buf, " =");
                    break;
                case 3 :
                    STRCAT (buf, " =+");
                    break;
                case 4 :
                case 6 :
                    STRCAT (buf, " -");
                    break;
                case 5 :
                case 7 :
                    STRCAT (buf, " -+");
                    break;
                }
            if (curbuf->b_fname != NULL && curbuf->b_term == NULL) {
                off = (int) STRLEN (buf);
                buf[off++] = ' ';
                buf[off++] = '(';
                home_replace (curbuf, curbuf -> b_ffname, buf + off, SPACE_FOR_DIR - off, TRUE);
                p = gettail_sep (buf +off);
                if (p == buf + off) {
                    vim_strncpy (buf + off, (char_u *) _ ("help"), (size_t) (SPACE_FOR_DIR - off - 1));
                }
                else
                    *p = NUL;
                if (off < SPACE_FOR_DIR) {
                    p = transstr (buf +off);
                    vim_strncpy (buf + off, p, (size_t) (SPACE_FOR_DIR - off));
                    vim_free (p);
                }
                else {
                    vim_strncpy (buf + off, (char_u *) "...", (size_t) (SPACE_FOR_ARGNR - off));
                }
                STRCAT (buf, ")");
            }
            if (serverName != NULL) {
                STRCAT (buf, " - ");
                vim_strcat (buf, serverName, IOSIZE);
            }
            else
                STRCAT (buf, " - VIM");
            if (maxlen > 0) {
                if (vim_strsize (buf) > maxlen)
                    trunc_string (buf, buf, maxlen, IOSIZE);
            }
        }
    }
    mustset = ti_change (t_str, &lasttitle);
    if (p_icon) {
        i_str = buf;
        if (*p_iconstring != NUL) {
            if (stl_syntax & STL_IN_ICON) {
                int use_sandbox = FALSE;
                int save_called_emsg = called_emsg;
                use_sandbox = was_set_insecurely ((char_u *) "iconstring", 0);
                called_emsg = FALSE;
                build_stl_str_hl (curwin, i_str, sizeof (buf), p_iconstring, use_sandbox, 0, 0, NULL, NULL);
                if (called_emsg)
                    set_string_option_direct ((char_u *) "iconstring", -1, (char_u *) "", OPT_FREE, SID_ERROR);
                called_emsg |= save_called_emsg;
            }
            else
                i_str = p_iconstring;
        }
        else {
            if (buf_spname (curbuf) != NULL)
                i_name = buf_spname (curbuf);
            else
                i_name = gettail (curbuf->b_ffname);
            *i_str = NUL;
            len = (int) STRLEN (i_name);
            if (len > 100) {
                len -= 100;
                i_name += len;
            }
            STRCPY (i_str, i_name);
            trans_characters (i_str, IOSIZE);
        }
    }
    mustset |= ti_change (i_str, &lasticon);
    if (mustset)
        resettitle ();
}

int build_stl_str_hl (win_T *wp, char_u *out, size_t outlen, char_u *fmt, int use_sandbox, int fillchar, int maxwidth, struct stl_hlrec *hltab, struct stl_hlrec *tabtab) {
    char_u *p;
    char_u *s;
    char_u *t;
    int byteval;
    win_T *save_curwin;
    buf_T *save_curbuf;
    int empty_line;
    colnr_T virtcol;
    long  l;
    long  n;
    int prevchar_isflag;
    int prevchar_isitem;
    int itemisflag;
    int fillable;
    char_u *str;
    long  num;
    int width;
    int itemcnt;
    int curitem;
    int group_end_userhl;
    int group_start_userhl;
    int groupitem [STL_MAX_ITEM];
    int groupdepth;
    struct stl_item {
        char_u *start;
        int minwid;
        int maxwid;
        enum {Normal, Empty, Group, Middle, Highlight, TabPage, Trunc} type;
    } item [STL_MAX_ITEM];
    int minwid;
    int maxwid;
    int zeropad;
    char_u base;
    char_u opt;

    #define TMPLEN 70
    char_u tmp [TMPLEN];
    char_u *usefmt = fmt;
    struct stl_hlrec *sp;
    int save_must_redraw = must_redraw;
    int save_redr_type = curwin->w_redr_type;
    if (fmt[0] == '%' && fmt[1] == '!') {
        usefmt = eval_to_string_safe (fmt +2, NULL, use_sandbox);
        if (usefmt == NULL)
            usefmt = fmt;
    }
    if (fillchar == 0)
        fillchar = ' ';
    p = ml_get_buf (wp->w_buffer, wp->w_cursor.lnum, FALSE);
    empty_line = (*p == NUL);
    if (wp->w_cursor.col > (colnr_T) STRLEN (p))
        byteval = 0;
    else
        byteval = p[wp->w_cursor.col];
    groupdepth = 0;
    p = out;
    curitem = 0;
    prevchar_isflag = TRUE;
    prevchar_isitem = FALSE;
    for (s = usefmt; *s;) {
        if (curitem == STL_MAX_ITEM) {
            if (p + 6 < out + outlen) {
                mch_memmove (p, " E541", (size_t) 5);
                p += 5;
            }
            break;
        }
        if (*s != NUL && *s != '%')
            prevchar_isflag = prevchar_isitem = FALSE;
        while (*s != NUL && *s != '%' && p + 1 < out + outlen)
            *p++ = *s++;
        if (*s == NUL || p + 1 >= out + outlen)
            break;
        s++;
        if (*s == NUL)
            break;
        if (*s == '%') {
            if (p + 1 >= out + outlen)
                break;
            *p++ = *s++;
            prevchar_isflag = prevchar_isitem = FALSE;
            continue;
        }
        if (*s == STL_MIDDLEMARK) {
            s++;
            if (groupdepth > 0)
                continue;
            item[curitem].type = Middle;
            item[curitem++].start = p;
            continue;
        }
        if (*s == STL_TRUNCMARK) {
            s++;
            item[curitem].type = Trunc;
            item[curitem++].start = p;
            continue;
        }
        if (*s == ')') {
            s++;
            if (groupdepth < 1)
                continue;
            groupdepth--;
            t = item[groupitem[groupdepth]].start;
            *p = NUL;
            l = vim_strsize (t);
            if (curitem > groupitem[groupdepth] + 1 && item[groupitem[groupdepth]].minwid == 0) {
                group_start_userhl = group_end_userhl = 0;
                for (n = groupitem[groupdepth] - 1; n >= 0; n--) {
                    if (item[n].type == Highlight) {
                        group_start_userhl = group_end_userhl = item[n].minwid;
                        break;
                    }
                }
                for (n = groupitem[groupdepth] + 1; n < curitem; n++) {
                    if (item[n].type == Normal)
                        break;
                    if (item[n].type == Highlight)
                        group_end_userhl = item[n].minwid;
                }
                if (n == curitem && group_start_userhl == group_end_userhl) {
                    p = t;
                    l = 0;
                }
            }
            if (l > item[groupitem[groupdepth]].maxwid) {
                n = (long ) (p - t) - item[groupitem[groupdepth]].maxwid + 1;
                *t = '<';
                mch_memmove (t + 1, t + n, (size_t) (p - (t + n)));
                p = p - n + 1;
                for (l = groupitem[groupdepth] + 1; l < curitem; l++) {
                    item[l].start -= n;
                    if (item[l].start < t)
                        item[l].start = t;
                }
            }
            else if (abs (item[groupitem[groupdepth]].minwid) > l) {
                n = item[groupitem[groupdepth]].minwid;
                if (n < 0) {
                    n = 0 - n;
                    while (l++ < n && p + 1 < out + outlen)
                        *p++ = fillchar;
                }
                else {
                    mch_memmove (t + n - l, t, (size_t) (p - t));
                    l = n - l;
                    if (p + l >= out + outlen)
                        l = (long ) ((out + outlen) - p - 1);
                    p += l;
                    for (n = groupitem[groupdepth] + 1; n < curitem; n++)
                        item[n].start += l;
                    for (; l > 0; l--)
                        *t++ = fillchar;
                }
            }
            continue;
        }
        minwid = 0;
        maxwid = 9999;
        zeropad = FALSE;
        l = 1;
        if (*s == '0') {
            s++;
            zeropad = TRUE;
        }
        if (*s == '-') {
            s++;
            l = -1;
        }
        if (VIM_ISDIGIT (*s)) {
            minwid = (int) getdigits (&s);
            if (minwid < 0)
                minwid = 0;
        }
        if (*s == STL_USER_HL) {
            item[curitem].type = Highlight;
            item[curitem].start = p;
            item[curitem].minwid = minwid > 9 ? 1 : minwid;
            s++;
            curitem++;
            continue;
        }
        if (*s == STL_TABPAGENR || *s == STL_TABCLOSENR) {
            if (*s == STL_TABCLOSENR) {
                if (minwid == 0) {
                    for (n = curitem - 1; n >= 0; --n)
                        if (item[n].type == TabPage && item[n].minwid >= 0) {
                            minwid = item[n].minwid;
                            break;
                        }
                }
                else
                    minwid = -minwid;
            }
            item[curitem].type = TabPage;
            item[curitem].start = p;
            item[curitem].minwid = minwid;
            s++;
            curitem++;
            continue;
        }
        if (*s == '.') {
            s++;
            if (VIM_ISDIGIT (*s)) {
                maxwid = (int) getdigits (&s);
                if (maxwid <= 0)
                    maxwid = 50;
            }
        }
        minwid = (minwid > 50 ? 50 : minwid) * l;
        if (*s == '(') {
            groupitem[groupdepth++] = curitem;
            item[curitem].type = Group;
            item[curitem].start = p;
            item[curitem].minwid = minwid;
            item[curitem].maxwid = maxwid;
            s++;
            curitem++;
            continue;
        }
        if (vim_strchr (STL_ALL, *s) == NULL) {
            s++;
            continue;
        }
        opt = *s++;
        base = 'D';
        itemisflag = FALSE;
        fillable = TRUE;
        num = -1;
        str = NULL;
        switch (opt) {
        case STL_FILEPATH :
        case STL_FULLPATH :
        case STL_FILENAME :
            fillable = FALSE;
            if (buf_spname (wp->w_buffer) != NULL)
                vim_strncpy (NameBuff, buf_spname (wp->w_buffer), MAXPATHL -1);
            else {
                t = (opt == STL_FULLPATH) ? wp->w_buffer->b_ffname : wp->w_buffer->b_fname;
                home_replace (wp -> w_buffer, t, NameBuff, MAXPATHL, TRUE);
            }
            trans_characters (NameBuff, MAXPATHL);
            if (opt != STL_FILENAME)
                str = NameBuff;
            else
                str = gettail (NameBuff);
            break;
        case STL_VIM_EXPR :
            itemisflag = TRUE;
            t = p;
            while (*s != '}' && *s != NUL && p + 1 < out + outlen)
                *p++ = *s++;
            if (*s != '}')
                break;
            s++;
            *p = 0;
            p = t;
            vim_snprintf ((char *) tmp, sizeof (tmp), "%d", curbuf -> b_fnum);
            set_internal_string_var ((char_u *) "actual_curbuf", tmp);
            save_curbuf = curbuf;
            save_curwin = curwin;
            curwin = wp;
            curbuf = wp->w_buffer;
            str = eval_to_string_safe (p, &t, use_sandbox);
            curwin = save_curwin;
            curbuf = save_curbuf;
            do_unlet ((char_u *) "g:actual_curbuf", TRUE);
            if (str != NULL && *str != 0) {
                if (*skipdigits (str) == NUL) {
                    num = atoi ((char *) str);
                    VIM_CLEAR (str);
                    itemisflag = FALSE;
                }
            }
            break;
        case STL_LINE :
            num = (wp->w_buffer->b_ml.ml_flags & ML_EMPTY) ? 0L : (long ) (wp->w_cursor.lnum);
            break;
        case STL_NUMLINES :
            num = wp->w_buffer->b_ml.ml_line_count;
            break;
        case STL_COLUMN :
            num = !(State & INSERT) && empty_line ? 0 : (int) wp->w_cursor.col + 1;
            break;
        case STL_VIRTCOL :
        case STL_VIRTCOL_ALT :
            virtcol = wp->w_virtcol;
            if (wp->w_p_list && lcs_tab1 == NUL) {
                wp->w_p_list = FALSE;
                getvcol (wp, & wp -> w_cursor, NULL, & virtcol, NULL);
                wp->w_p_list = TRUE;
            }
            ++virtcol;
            if (opt == STL_VIRTCOL_ALT && (virtcol == (colnr_T) (!(State & INSERT) && empty_line ? 0 : (int) wp->w_cursor.col + 1)))
                break;
            num = (long ) virtcol;
            break;
        case STL_PERCENTAGE :
            num = (int) (((long ) wp->w_cursor.lnum * 100L) / (long ) wp->w_buffer->b_ml.ml_line_count);
            break;
        case STL_ALTPERCENT :
            str = tmp;
            get_rel_pos (wp, str, TMPLEN);
            break;
        case STL_ARGLISTSTAT :
            fillable = FALSE;
            tmp[0] = 0;
            if (append_arg_number (wp, tmp, (int) sizeof (tmp), FALSE))
                str = tmp;
            break;
        case STL_KEYMAP :
            fillable = FALSE;
            if (get_keymap_str (wp, (char_u *) "<%s>", tmp, TMPLEN))
                str = tmp;
            break;
        case STL_PAGENUM :
            num = printer_page_num;
            break;
        case STL_BUFNO :
            num = wp->w_buffer->b_fnum;
            break;
        case STL_OFFSET_X :
            base = 'X';
        case STL_OFFSET :
            l = ml_find_line_or_offset (wp->w_buffer, wp->w_cursor.lnum, NULL);
            num = (wp->w_buffer->b_ml.ml_flags & ML_EMPTY) || l < 0 ? 0L : l + 1 + (!(State & INSERT) && empty_line ? 0 : (int) wp->w_cursor.col);
            break;
        case STL_BYTEVAL_X :
            base = 'X';
        case STL_BYTEVAL :
            num = byteval;
            if (num == NL)
                num = 0;
            else if (num == CAR && get_fileformat (wp->w_buffer) == EOL_MAC)
                num = NL;
            break;
        case STL_ROFLAG :
        case STL_ROFLAG_ALT :
            itemisflag = TRUE;
            if (wp->w_buffer->b_p_ro)
                str = (char_u *) ((opt == STL_ROFLAG_ALT) ? ",RO" : _ ("[RO]"));
            break;
        case STL_HELPFLAG :
        case STL_HELPFLAG_ALT :
            itemisflag = TRUE;
            if (wp->w_buffer->b_help)
                str = (char_u *) ((opt == STL_HELPFLAG_ALT) ? ",HLP" : _ ("[Help]"));
            break;
        case STL_FILETYPE :
            if (*wp->w_buffer->b_p_ft != NUL && STRLEN (wp->w_buffer->b_p_ft) < TMPLEN - 3) {
                vim_snprintf ((char *) tmp, sizeof (tmp), "[%s]", wp -> w_buffer -> b_p_ft);
                str = tmp;
            }
            break;
        case STL_FILETYPE_ALT :
            itemisflag = TRUE;
            if (*wp->w_buffer->b_p_ft != NUL && STRLEN (wp->w_buffer->b_p_ft) < TMPLEN - 2) {
                vim_snprintf ((char *) tmp, sizeof (tmp), ",%s", wp -> w_buffer -> b_p_ft);
                for (t = tmp; *t != 0; t++)
                    *t = TOUPPER_LOC (*t);
                str = tmp;
            }
            break;
        case STL_PREVIEWFLAG :
        case STL_PREVIEWFLAG_ALT :
            itemisflag = TRUE;
            if (wp->w_p_pvw)
                str = (char_u *) ((opt == STL_PREVIEWFLAG_ALT) ? ",PRV" : _ ("[Preview]"));
            break;
        case STL_QUICKFIX :
            if (bt_quickfix (wp->w_buffer))
                str = (char_u *) (wp->w_llist_ref ? _ (msg_loclist) : _ (msg_qflist));
            break;
        case STL_MODIFIED :
        case STL_MODIFIED_ALT :
            itemisflag = TRUE;
            switch ((opt == STL_MODIFIED_ALT) + bufIsChanged (wp->w_buffer) * 2 + (!wp->w_buffer->b_p_ma) * 4) {
            case 2 :
                str = (char_u *) "[+]";
                break;
            case 3 :
                str = (char_u *) ",+";
                break;
            case 4 :
                str = (char_u *) "[-]";
                break;
            case 5 :
                str = (char_u *) ",-";
                break;
            case 6 :
                str = (char_u *) "[+-]";
                break;
            case 7 :
                str = (char_u *) ",+-";
                break;
            }
            break;
        case STL_HIGHLIGHT :
            t = s;
            while (*s != '#' && *s != NUL)
                ++s;
            if (*s == '#') {
                item[curitem].type = Highlight;
                item[curitem].start = p;
                item[curitem].minwid = -syn_namen2id (t, (int) (s - t));
                curitem++;
            }
            if (*s != NUL)
                ++s;
            continue;
        }
        item[curitem].start = p;
        item[curitem].type = Normal;
        if (str != NULL && *str) {
            t = str;
            if (itemisflag) {
                if ((t[0] && t[1]) && ((!prevchar_isitem && *t == ',') || (prevchar_isflag && *t == ' ')))
                    t++;
                prevchar_isflag = TRUE;
            }
            l = vim_strsize (t);
            if (l > 0)
                prevchar_isitem = TRUE;
            if (l > maxwid) {
                while (l >= maxwid)
                    l -= byte2cells (*t++);
                if (p + 1 >= out + outlen)
                    break;
                *p++ = '<';
            }
            if (minwid > 0) {
                for (; l < minwid && p + 1 < out + outlen; l++) {
                    if (l + 1 == minwid && fillchar == '-' && VIM_ISDIGIT (*t))
                        *p++ = ' ';
                    else
                        *p++ = fillchar;
                }
                minwid = 0;
            }
            else
                minwid *= -1;
            while (*t && p + 1 < out + outlen) {
                *p++ = *t++;
                if (fillable && p[-1] == ' ' && (!VIM_ISDIGIT (*t) || fillchar != '-'))
                    p[-1] = fillchar;
            }
            for (; l < minwid && p + 1 < out + outlen; l++)
                *p++ = fillchar;
        }
        else if (num >= 0) {
            int nbase = (base == 'D' ? 10 : (base == 'O' ? 8 : 16));
            char_u nstr [20];
            if (p + 20 >= out + outlen)
                break;
            prevchar_isitem = TRUE;
            t = nstr;
            if (opt == STL_VIRTCOL_ALT) {
                *t++ = '-';
                minwid--;
            }
            *t++ = '%';
            if (zeropad)
                *t++ = '0';
            *t++ = '*';
            *t++ = nbase == 16 ? base : (char_u) (nbase == 8 ? 'o' : 'd');
            *t = 0;
            for (n = num, l = 1; n >= nbase; n /= nbase)
                l++;
            if (opt == STL_VIRTCOL_ALT)
                l++;
            if (l > maxwid) {
                l += 2;
                n = l - maxwid;
                while (l-- > maxwid)
                    num /= nbase;
                *t++ = '>';
                *t++ = '%';
                *t = t[-3];
                *++t = 0;
                vim_snprintf ((char *) p, outlen - (p - out), (char *) nstr, 0, num, n);
            }
            else
                vim_snprintf ((char *) p, outlen -(p - out), (char *) nstr, minwid, num);
            p += STRLEN (p);
        }
        else
            item[curitem].type = Empty;
        if (opt == STL_VIM_EXPR)
            vim_free (str);
        if (num >= 0 || (!itemisflag && str && *str))
            prevchar_isflag = FALSE;
        curitem++;
    }
    *p = NUL;
    itemcnt = curitem;
    if (usefmt != fmt)
        vim_free (usefmt);
    width = vim_strsize (out);
    if (maxwidth > 0 && width > maxwidth) {
        l = 0;
        if (itemcnt == 0)
            s = out;
        else {
            for (; l < itemcnt; l++)
                if (item[l].type == Trunc) {
                    s = item[l].start;
                    break;
                }
            if (l == itemcnt) {
                s = item[0].start;
                l = 0;
            }
        }
        if (width - vim_strsize (s) >= maxwidth) {
            s = out + maxwidth - 1;
            for (l = 0; l < itemcnt; l++)
                if (item[l].start > s)
                    break;
            itemcnt = l;
            *s++ = '>';
            *s = 0;
        }
        else {
            n = width - maxwidth + 1;
            p = s + n;
            STRMOVE (s + 1, p);
            *s = '<';
            while (++width < maxwidth) {
                s = s + STRLEN (s);
                *s++ = fillchar;
                *s = NUL;
            }
            --n;
            for (; l < itemcnt; l++) {
                if (item[l].start - n >= s)
                    item[l].start -= n;
                else
                    item[l].start = s;
            }
        }
        width = maxwidth;
    }
    else if (width < maxwidth && STRLEN (out) + maxwidth - width + 1 < outlen) {
        for (l = 0; l < itemcnt; l++)
            if (item[l].type == Middle)
                break;
        if (l < itemcnt) {
            p = item[l].start + maxwidth - width;
            STRMOVE (p, item [l].start);
            for (s = item[l].start; s < p; s++)
                *s = fillchar;
            for (l++; l < itemcnt; l++)
                item[l].start += maxwidth - width;
            width = maxwidth;
        }
    }
    if (hltab != NULL) {
        sp = hltab;
        for (l = 0; l < itemcnt; l++) {
            if (item[l].type == Highlight) {
                sp->start = item[l].start;
                sp->userhl = item[l].minwid;
                sp++;
            }
        }
        sp->start = NULL;
        sp->userhl = 0;
    }
    if (tabtab != NULL) {
        sp = tabtab;
        for (l = 0; l < itemcnt; l++) {
            if (item[l].type == TabPage) {
                sp->start = item[l].start;
                sp->userhl = item[l].minwid;
                sp++;
            }
        }
        sp->start = NULL;
        sp->userhl = 0;
    }
    if (updating_screen) {
        must_redraw = save_must_redraw;
        curwin->w_redr_type = save_redr_type;
    }
    return width;
}

char_u *buf_spname (buf_T *buf) {
    if (bt_quickfix (buf)) {
        win_T *win;
        tabpage_T *tp;
        if (find_win_for_buf (buf, &win, &tp) == OK && win->w_llist_ref != NULL)
            return (char_u *) _ (msg_loclist);
        else
            return (char_u *) _ (msg_qflist);
    }
    if (bt_nofile (buf)) {
        if (buf->b_term != NULL)
            return term_get_status_text (buf->b_term);
        if (buf->b_fname != NULL)
            return buf->b_fname;
        return (char_u *) _ ("[Scratch]");
    }
    if (buf->b_fname == NULL)
        return (char_u *) _ ("[No Name]");
    return NULL;
}

# define SWITCH_TO_WIN

int bt_quickfix (buf_T *buf) {
    return buf != NULL && buf->b_p_bt[0] == 'q';
}

int find_win_for_buf (buf_T *buf, win_T **wp, tabpage_T **tp) {
    FOR_ALL_TAB_WINDOWS (*tp, *wp)
        if ((*wp)->w_buffer == buf)
            goto win_found;
    return FAIL;
win_found :
    return OK;
}

int bt_nofile (buf_T *buf) {
    return buf != NULL && ((buf->b_p_bt[0] == 'n' && buf->b_p_bt[2] == 'f') || buf->b_p_bt[0] == 'a' || buf->b_p_bt[0] == 't');
}

void set_bufref (bufref_T *bufref, buf_T *buf) {
    bufref->br_buf = buf;
    bufref->br_fnum = buf == NULL ? 0 : buf->b_fnum;
    bufref->br_buf_free_count = buf_free_count;
}

int bt_dontwrite (buf_T *buf) {
    return buf != NULL && (buf->b_p_bt[0] == 'n' || buf->b_p_bt[0] == 't');
}

int buf_contents_changed (buf_T *buf) {
    buf_T *newbuf;
    int differ = TRUE;
    linenr_T lnum;
    aco_save_T aco;
    exarg_T ea;
    newbuf = buflist_new (NULL, NULL, (linenr_T) 1, BLN_DUMMY);
    if (newbuf == NULL)
        return TRUE;
    if (prep_exarg (&ea, buf) == FAIL) {
        wipe_buffer (newbuf, FALSE);
        return TRUE;
    }
    aucmd_prepbuf (& aco, newbuf);
    if (ml_open (curbuf) == OK && readfile (buf->b_ffname, buf->b_fname, (linenr_T) 0, (linenr_T) 0, (linenr_T) MAXLNUM, &ea, READ_NEW | READ_DUMMY) == OK) {
        if (buf->b_ml.ml_line_count == curbuf->b_ml.ml_line_count) {
            differ = FALSE;
            for (lnum = 1; lnum <= curbuf->b_ml.ml_line_count; ++lnum)
                if (STRCMP (ml_get_buf (buf, lnum, FALSE), ml_get (lnum)) != 0) {
                    differ = TRUE;
                    break;
                }
        }
    }
    vim_free (ea.cmd);
    aucmd_restbuf (& aco);
    if (curbuf != newbuf)
        wipe_buffer (newbuf, FALSE);
    return differ;
}

buf_T *buflist_new (char_u *ffname, char_u *sfname, linenr_T lnum, int flags) {
    buf_T *buf;
    stat_T st;
    if (top_file_num == 1)
        hash_init (&buf_hashtab);
    fname_expand (curbuf, & ffname, & sfname);
    if (sfname == NULL || mch_stat ((char *) sfname, &st) < 0)
        st.st_dev = (dev_T) -1;
    if (ffname != NULL && !(flags & (BLN_DUMMY | BLN_NEW)) && (buf = buflist_findname_stat (ffname, &st)) != NULL) {
        vim_free (ffname);
        if (lnum != 0)
            buflist_setfpos (buf, curwin, lnum, (colnr_T) 0, FALSE);
        if ((flags & BLN_NOOPT) == 0)
            buf_copy_options (buf, 0);
        if ((flags & BLN_LISTED) && !buf->b_p_bl) {
            bufref_T bufref;
            buf->b_p_bl = TRUE;
            set_bufref (& bufref, buf);
            if (!(flags & BLN_DUMMY)) {
                if (apply_autocmds (EVENT_BUFADD, NULL, NULL, FALSE, buf) && !bufref_valid (&bufref))
                    return NULL;
            }
        }
        return buf;
    }
    buf = NULL;
    if ((flags & BLN_CURBUF) && curbuf != NULL && curbuf->b_ffname == NULL && curbuf->b_nwindows <= 1 && (curbuf->b_ml.ml_mfp == NULL || BUFEMPTY ())) {
        buf = curbuf;
        if (curbuf->b_p_bl)
            apply_autocmds (EVENT_BUFDELETE, NULL, NULL, FALSE, curbuf);
        if (buf == curbuf)
            apply_autocmds (EVENT_BUFWIPEOUT, NULL, NULL, FALSE, curbuf);
        if (aborting ())
            return NULL;
        if (buf == curbuf) {
            clear_string_option (& buf -> b_p_bh);
            clear_string_option (& buf -> b_p_bt);
        }
    }
    if (buf != curbuf || curbuf == NULL) {
        buf = (buf_T *) alloc_clear ((unsigned ) sizeof (buf_T));
        if (buf == NULL) {
            vim_free (ffname);
            return NULL;
        }
        buf->b_vars = dict_alloc ();
        if (buf->b_vars == NULL) {
            vim_free (ffname);
            vim_free (buf);
            return NULL;
        }
        init_var_dict (buf -> b_vars, & buf -> b_bufvar, VAR_SCOPE);
        init_changedtick (buf);
    }
    if (ffname != NULL) {
        buf->b_ffname = ffname;
        buf->b_sfname = vim_strsave (sfname);
    }
    clear_wininfo (buf);
    buf->b_wininfo = (wininfo_T *) alloc_clear ((unsigned ) sizeof (wininfo_T));
    if ((ffname != NULL && (buf->b_ffname == NULL || buf->b_sfname == NULL)) || buf->b_wininfo == NULL) {
        VIM_CLEAR (buf -> b_ffname);
        VIM_CLEAR (buf -> b_sfname);
        if (buf != curbuf)
            free_buffer (buf);
        return NULL;
    }
    if (buf == curbuf) {
        buf_freeall (buf, 0);
        if (buf != curbuf)
            return NULL;
        if (aborting ())
            return NULL;
        free_buffer_stuff (buf, FALSE);
        buf->b_p_initialized = FALSE;
        buf_copy_options (buf, BCO_ENTER);
        curbuf->b_kmap_state |= KEYMAP_INIT;
    }
    else {
        buf->b_next = NULL;
        if (firstbuf == NULL) {
            buf->b_prev = NULL;
            firstbuf = buf;
        }
        else {
            lastbuf->b_next = buf;
            buf->b_prev = lastbuf;
        }
        lastbuf = buf;
        buf->b_fnum = top_file_num++;
        if (top_file_num < 0) {
            EMSG (_ ("W14: Warning: List of file names overflow"));
            if (emsg_silent == 0) {
                out_flush ();
                ui_delay (3000L, TRUE);
            }
            top_file_num = 1;
        }
        buf_hashtab_add (buf);
        buf_copy_options (buf, BCO_ALWAYS);
    }
    buf->b_wininfo->wi_fpos.lnum = lnum;
    buf->b_wininfo->wi_win = curwin;
    hash_init (& buf -> b_s.b_keywtab);
    hash_init (& buf -> b_s.b_keywtab_ic);
    buf->b_fname = buf->b_sfname;
    if (st.st_dev == (dev_T) -1)
        buf->b_dev_valid = FALSE;
    else {
        buf->b_dev_valid = TRUE;
        buf->b_dev = st.st_dev;
        buf->b_ino = st.st_ino;
    }
    buf->b_u_synced = TRUE;
    buf->b_flags = BF_CHECK_RO | BF_NEVERLOADED;
    if (flags & BLN_DUMMY)
        buf->b_flags |= BF_DUMMY;
    buf_clear_file (buf);
    clrallmarks (buf);
    fmarks_check_names (buf);
    buf->b_p_bl = (flags & BLN_LISTED) ? TRUE : FALSE;
    if (!(flags & BLN_DUMMY)) {
        bufref_T bufref;
        set_bufref (& bufref, buf);
        if (apply_autocmds (EVENT_BUFNEW, NULL, NULL, FALSE, buf) && !bufref_valid (&bufref))
            return NULL;
        if (flags & BLN_LISTED) {
            if (apply_autocmds (EVENT_BUFADD, NULL, NULL, FALSE, buf) && !bufref_valid (&bufref))
                return NULL;
        }
        if (aborting ())
            return NULL;
    }
    return buf;
}

void fname_expand (buf_T *buf, char_u **ffname, char_u **sfname) {
    if (*ffname == NULL)
        return;
    if (*sfname == NULL)
        *sfname = *ffname;
    *ffname = fix_fname (*ffname);
}

char_u *fix_fname (char_u *fname) {
    return FullName_save (fname, TRUE);
}

static buf_T *buflist_findname_stat (char_u *ffname, stat_T *stp) {
    buf_T *buf;
    for (buf = lastbuf; buf != NULL; buf = buf->b_prev)
        if ((buf->b_flags & BF_DUMMY) == 0 && !otherfile_buf (buf, ffname, stp))
            return buf;
    return NULL;
}

static int otherfile_buf (buf_T *buf, char_u *ffname, stat_T *stp) {
    if (ffname == NULL || *ffname == NUL || buf->b_ffname == NULL)
        return TRUE;
    if (fnamecmp (ffname, buf->b_ffname) == 0)
        return FALSE;
    {
        stat_T st;
        if (stp == NULL) {
            if (!buf->b_dev_valid || mch_stat ((char *) ffname, &st) < 0)
                st.st_dev = (dev_T) -1;
            stp = &st;
        }
        if (buf_same_ino (buf, stp)) {
            buf_setino (buf);
            if (buf_same_ino (buf, stp))
                return FALSE;
        }
    }
    return TRUE;
}

static int buf_same_ino (buf_T *buf, stat_T *stp) {
    return (buf->b_dev_valid && stp->st_dev == buf->b_dev && stp->st_ino == buf->b_ino);
}

void buf_setino (buf_T *buf) {
    stat_T st;
    if (buf->b_fname != NULL && mch_stat ((char *) buf->b_fname, &st) >= 0) {
        buf->b_dev_valid = TRUE;
        buf->b_dev = st.st_dev;
        buf->b_ino = st.st_ino;
    }
    else
        buf->b_dev_valid = FALSE;
}

static void buflist_setfpos (buf_T *buf, win_T *win, linenr_T lnum, colnr_T col, int copy_options) {
    wininfo_T *wip;
    for (wip = buf->b_wininfo; wip != NULL; wip = wip->wi_next)
        if (wip->wi_win == win)
            break;
    if (wip == NULL) {
        wip = (wininfo_T *) alloc_clear ((unsigned ) sizeof (wininfo_T));
        if (wip == NULL)
            return;
        wip->wi_win = win;
        if (lnum == 0)
            lnum = 1;
    }
    else {
        if (wip->wi_prev)
            wip->wi_prev->wi_next = wip->wi_next;
        else
            buf->b_wininfo = wip->wi_next;
        if (wip->wi_next)
            wip->wi_next->wi_prev = wip->wi_prev;
        if (copy_options && wip->wi_optset) {
            clear_winopt (& wip -> wi_opt);
            deleteFoldRecurse (& wip -> wi_folds);
        }
    }
    if (lnum != 0) {
        wip->wi_fpos.lnum = lnum;
        wip->wi_fpos.col = col;
    }
    if (copy_options) {
        copy_winopt (& win -> w_onebuf_opt, & wip -> wi_opt);
        wip->wi_fold_manual = win->w_fold_manual;
        cloneFoldGrowArray (& win -> w_folds, & wip -> wi_folds);
        wip->wi_optset = TRUE;
    }
    wip->wi_next = buf->b_wininfo;
    buf->b_wininfo = wip;
    wip->wi_prev = NULL;
    if (wip->wi_next)
        wip->wi_next->wi_prev = wip;
    return;
}

void free_buf_options (buf_T *buf, int free_p_ff) {
    if (free_p_ff) {
        clear_string_option (& buf -> b_p_ff);
        clear_string_option (& buf -> b_p_bh);
        clear_string_option (& buf -> b_p_bt);
    }
    clear_string_option (& buf -> b_p_def);
    clear_string_option (& buf -> b_p_inc);
    clear_string_option (& buf -> b_p_inex);
    clear_string_option (& buf -> b_p_inde);
    clear_string_option (& buf -> b_p_indk);
    clear_string_option (& buf -> b_p_bexpr);
    clear_string_option (& buf -> b_p_cm);
    clear_string_option (& buf -> b_p_fp);
    clear_string_option (& buf -> b_p_fex);
    clear_string_option (& buf -> b_p_key);
    clear_string_option (& buf -> b_p_kp);
    clear_string_option (& buf -> b_p_mps);
    clear_string_option (& buf -> b_p_fo);
    clear_string_option (& buf -> b_p_flp);
    clear_string_option (& buf -> b_p_isk);
    clear_string_option (& buf -> b_p_keymap);
    keymap_clear (& buf -> b_kmap_ga);
    ga_clear (& buf -> b_kmap_ga);
    clear_string_option (& buf -> b_p_com);
    clear_string_option (& buf -> b_p_cms);
    clear_string_option (& buf -> b_p_nf);
    clear_string_option (& buf -> b_p_syn);
    clear_string_option (& buf -> b_s.b_syn_isk);
    clear_string_option (& buf -> b_s.b_p_spc);
    clear_string_option (& buf -> b_s.b_p_spf);
    vim_regfree (buf -> b_s.b_cap_prog);
    buf->b_s.b_cap_prog = NULL;
    clear_string_option (& buf -> b_s.b_p_spl);
    clear_string_option (& buf -> b_p_sua);
    clear_string_option (& buf -> b_p_ft);
    clear_string_option (& buf -> b_p_cink);
    clear_string_option (& buf -> b_p_cino);
    clear_string_option (& buf -> b_p_cinw);
    clear_string_option (& buf -> b_p_cpt);
    clear_string_option (& buf -> b_p_gp);
    clear_string_option (& buf -> b_p_mp);
    clear_string_option (& buf -> b_p_efm);
    clear_string_option (& buf -> b_p_ep);
    clear_string_option (& buf -> b_p_path);
    clear_string_option (& buf -> b_p_tags);
    clear_string_option (& buf -> b_p_tc);
    clear_string_option (& buf -> b_p_dict);
    clear_string_option (& buf -> b_p_tsr);
    clear_string_option (& buf -> b_p_qe);
    buf->b_p_ar = -1;
    buf->b_p_ul = NO_LOCAL_UNDOLEVEL;
    clear_string_option (& buf -> b_p_lw);
    clear_string_option (& buf -> b_p_bkc);
}

static void init_changedtick (buf_T *buf) {
    dictitem_T *di = (dictitem_T *) &buf->b_ct_di;
    di->di_flags = DI_FLAGS_FIX | DI_FLAGS_RO;
    di->di_tv.v_type = VAR_NUMBER;
    di->di_tv.v_lock = VAR_FIXED;
    di->di_tv.vval.v_number = 0;
    STRCPY (buf -> b_ct_di.di_key, "changedtick");
    (void) dict_add (buf->b_vars, di);
}

static void clear_wininfo (buf_T *buf) {
    wininfo_T *wip;
    while (buf->b_wininfo != NULL) {
        wip = buf->b_wininfo;
        buf->b_wininfo = wip->wi_next;
        if (wip->wi_optset) {
            clear_winopt (& wip -> wi_opt);
            deleteFoldRecurse (& wip -> wi_folds);
        }
        vim_free (wip);
    }
}

static void free_buffer (buf_T *buf) {
    ++buf_free_count;
    free_buffer_stuff (buf, TRUE);
    dictitem_remove (buf -> b_vars, (dictitem_T *) & buf -> b_ct_di);
    unref_var_dict (buf -> b_vars);
    channel_buffer_free (buf);
    free_terminal (buf);
    buf_hashtab_remove (buf);
    aubuflocal_remove (buf);
    if (autocmd_busy) {
        buf->b_next = au_pending_free_buf;
        au_pending_free_buf = buf;
    }
    else
        vim_free (buf);
}

static void free_buffer_stuff (buf_T *buf, int free_options) {
    if (free_options) {
        clear_wininfo (buf);
        free_buf_options (buf, TRUE);
        ga_clear (& buf -> b_s.b_langp);
    }
    {
        varnumber_T tick = CHANGEDTICK (buf);
        vars_clear (& buf -> b_vars -> dv_hashtab);
        hash_init (& buf -> b_vars -> dv_hashtab);
        init_changedtick (buf);
        CHANGEDTICK (buf) = tick;
    }
    uc_clear (& buf -> b_ucmds);
    buf_delete_signs (buf);
    netbeans_file_killed (buf);
    map_clear_int (buf, MAP_ALL_MODES, TRUE, FALSE);
    map_clear_int (buf, MAP_ALL_MODES, TRUE, TRUE);
}

void buf_delete_signs (buf_T *buf) {
    signlist_T *next;
    if (buf->b_signlist != NULL && curwin != NULL) {
        redraw_buf_later (buf, NOT_VALID);
        changed_cline_bef_curs ();
    }
    while (buf->b_signlist != NULL) {
        next = buf->b_signlist->next;
        vim_free (buf -> b_signlist);
        buf->b_signlist = next;
    }
}

static void buf_hashtab_remove (buf_T *buf) {
    hashitem_T *hi = hash_find (&buf_hashtab, buf->b_key);
    if (!HASHITEM_EMPTY (hi))
        hash_remove (&buf_hashtab, hi);
}

void buf_freeall (buf_T *buf, int flags) {
    int is_curbuf = (buf == curbuf);
    bufref_T bufref;
    int is_curwin = (curwin != NULL && curwin->w_buffer == buf);
    win_T *the_curwin = curwin;
    tabpage_T *the_curtab = curtab;
    ++buf->b_locked;
    set_bufref (& bufref, buf);
    if (buf->b_ml.ml_mfp != NULL) {
        if (apply_autocmds (EVENT_BUFUNLOAD, buf->b_fname, buf->b_fname, FALSE, buf) && !bufref_valid (&bufref))
            return;
    }
    if ((flags & BFA_DEL) && buf->b_p_bl) {
        if (apply_autocmds (EVENT_BUFDELETE, buf->b_fname, buf->b_fname, FALSE, buf) && !bufref_valid (&bufref))
            return;
    }
    if (flags & BFA_WIPE) {
        if (apply_autocmds (EVENT_BUFWIPEOUT, buf->b_fname, buf->b_fname, FALSE, buf) && !bufref_valid (&bufref))
            return;
    }
    --buf->b_locked;
    if (is_curwin && curwin != the_curwin && win_valid_any_tab (the_curwin)) {
        block_autocmds ();
        goto_tabpage_win (the_curtab, the_curwin);
        unblock_autocmds ();
    }
    if (aborting ())
        return;
    if (buf == curbuf && !is_curbuf)
        return;
    diff_buf_delete (buf);
    if (curwin != NULL && curwin->w_buffer == buf)
        reset_synblock (curwin);
    {
        win_T *win;
        tabpage_T *tp;
        FOR_ALL_TAB_WINDOWS (tp, win)
            if (win->w_buffer == buf)
                clearFolding (win);
    }
    ml_close (buf, TRUE);
    buf->b_ml.ml_line_count = 0;
    if ((flags & BFA_KEEP_UNDO) == 0) {
        u_blockfree (buf);
        u_clearall (buf);
    }
    syntax_clear (& buf -> b_s);
    buf->b_flags &= ~BF_READERR;
}

static void buf_hashtab_add (buf_T *buf) {
    sprintf ((char *) buf -> b_key, "%x", buf -> b_fnum);
    if (hash_add (&buf_hashtab, buf->b_key) == FAIL)
        EMSG (_ ("E931: Buffer cannot be registered"));
}

void buf_clear_file (buf_T *buf) {
    buf->b_ml.ml_line_count = 1;
    unchanged (buf, TRUE);
    buf->b_shortname = FALSE;
    buf->b_p_eol = TRUE;
    buf->b_start_eol = TRUE;
    buf->b_ml.ml_mfp = NULL;
    buf->b_ml.ml_flags = ML_EMPTY;
    netbeans_deleted_all_lines (buf);
}

void wipe_buffer (buf_T *buf, int aucmd) {
    if (buf->b_fnum == top_file_num - 1)
        --top_file_num;
    if (!aucmd)
        block_autocmds ();
    close_buffer (NULL, buf, DOBUF_WIPE, FALSE);
    if (!aucmd)
        unblock_autocmds ();
}

void close_buffer (win_T *win, buf_T *buf, int action, int abort_if_last) {
    int is_curbuf;
    int nwindows;
    bufref_T bufref;
    int is_curwin = (curwin != NULL && curwin->w_buffer == buf);
    win_T *the_curwin = curwin;
    tabpage_T *the_curtab = curtab;
    int unload_buf = (action != 0);
    int del_buf = (action == DOBUF_DEL || action == DOBUF_WIPE);
    int wipe_buf = (action == DOBUF_WIPE);
    if (buf->b_p_bh[0] == 'd') {
        del_buf = TRUE;
        unload_buf = TRUE;
    }
    else if (buf->b_p_bh[0] == 'w') {
        del_buf = TRUE;
        unload_buf = TRUE;
        wipe_buf = TRUE;
    }
    else if (buf->b_p_bh[0] == 'u')
        unload_buf = TRUE;
    if (bt_terminal (buf) && (buf->b_nwindows == 1 || del_buf)) {
        if (term_job_running (buf->b_term)) {
            if (wipe_buf || unload_buf)
                free_terminal (buf);
            else {
                del_buf = FALSE;
                unload_buf = FALSE;
            }
        }
        else {
            del_buf = TRUE;
            unload_buf = TRUE;
            wipe_buf = TRUE;
        }
    }
    if (buf->b_locked > 0 && (del_buf || wipe_buf)) {
        EMSG (_ ("E937: Attempt to delete a buffer that is in use"));
        return;
    }
    if (win != NULL && win_valid_any_tab (win)) {
        if (buf->b_nwindows == 1)
            set_last_cursor (win);
        buflist_setfpos (buf, win, win -> w_cursor.lnum == 1 ? 0 : win -> w_cursor.lnum, win -> w_cursor.col, TRUE);
    }
    set_bufref (& bufref, buf);
    if (buf->b_nwindows == 1) {
        ++buf->b_locked;
        if (apply_autocmds (EVENT_BUFWINLEAVE, buf->b_fname, buf->b_fname, FALSE, buf) && !bufref_valid (&bufref)) {
        aucmd_abort :
            EMSG (_ (e_auabort));
            return;
        }
        --buf->b_locked;
        if (abort_if_last && one_window ())
            goto aucmd_abort;
        if (!unload_buf) {
            ++buf->b_locked;
            if (apply_autocmds (EVENT_BUFHIDDEN, buf->b_fname, buf->b_fname, FALSE, buf) && !bufref_valid (&bufref))
                goto aucmd_abort;
            --buf->b_locked;
            if (abort_if_last && one_window ())
                goto aucmd_abort;
        }
        if (aborting ())
            return;
    }
    if (is_curwin && curwin != the_curwin && win_valid_any_tab (the_curwin)) {
        block_autocmds ();
        goto_tabpage_win (the_curtab, the_curwin);
        unblock_autocmds ();
    }
    nwindows = buf->b_nwindows;
    if (buf->b_nwindows > 0)
        --buf->b_nwindows;
    if (diffopt_hiddenoff () && !unload_buf && buf->b_nwindows == 0)
        diff_buf_delete (buf);
    if (buf->b_nwindows > 0 || !unload_buf)
        return;
    if (buf->b_ffname == NULL)
        del_buf = TRUE;
    if (buf == curbuf && VIsual_active)
        end_visual_mode ();
    is_curbuf = (buf == curbuf);
    buf->b_nwindows = nwindows;
    buf_freeall (buf, (del_buf ? BFA_DEL : 0) + (wipe_buf ? BFA_WIPE : 0));
    if (!bufref_valid (&bufref))
        return;
    if (aborting ())
        return;
    if (buf == curbuf && !is_curbuf)
        return;
    if (win_valid_any_tab (win) && win->w_buffer == buf)
        win->w_buffer = NULL;
    if (buf->b_nwindows > 0)
        --buf->b_nwindows;
    if (wipe_buf) {
        vim_free (buf -> b_ffname);
        vim_free (buf -> b_sfname);
        if (buf->b_prev == NULL)
            firstbuf = buf->b_next;
        else
            buf->b_prev->b_next = buf->b_next;
        if (buf->b_next == NULL)
            lastbuf = buf->b_prev;
        else
            buf->b_next->b_prev = buf->b_prev;
        free_buffer (buf);
    }
    else {
        if (del_buf) {
            free_buffer_stuff (buf, TRUE);
            buf->b_flags = BF_CHECK_RO | BF_NEVERLOADED;
            buf->b_p_initialized = FALSE;
        }
        buf_clear_file (buf);
        if (del_buf)
            buf->b_p_bl = FALSE;
    }
}

int bt_terminal (buf_T *buf) {
    return buf != NULL && buf->b_p_bt[0] == 't';
}

int read_viminfo_bufferlist (vir_T *virp, int writing) {
    char_u *tab;
    linenr_T lnum;
    colnr_T col;
    buf_T *buf;
    char_u *sfname;
    char_u *xline;
    xline = viminfo_readstring (virp, 1, FALSE);
    if (xline != NULL && !writing && ARGCOUNT == 0 && find_viminfo_parameter ('%') != NULL) {
        lnum = 0;
        col = 0;
        tab = vim_strrchr (xline, '\t');
        if (tab != NULL) {
            *tab++ = '\0';
            col = (colnr_T) atoi ((char *) tab);
            tab = vim_strrchr (xline, '\t');
            if (tab != NULL) {
                *tab++ = '\0';
                lnum = atol ((char *) tab);
            }
        }
        expand_env (xline, NameBuff, MAXPATHL);
        sfname = shorten_fname1 (NameBuff);
        buf = buflist_new (NameBuff, sfname, (linenr_T) 0, BLN_LISTED);
        if (buf != NULL) {
            buf->b_last_cursor.lnum = lnum;
            buf->b_last_cursor.col = col;
            buflist_setfpos (buf, curwin, lnum, col, FALSE);
        }
    }
    vim_free (xline);
    return viminfo_readline (virp);
}

char_u *buflist_nr2name (int n, int fullname, int helptail) {
    buf_T *buf;
    buf = buflist_findnr (n);
    if (buf == NULL)
        return NULL;
    return home_replace_save (helptail ? buf : NULL, fullname ? buf->b_ffname : buf->b_fname);
}

void write_viminfo_bufferlist (FILE *fp) {
    buf_T *buf;
    win_T *win;
    tabpage_T *tp;
    char_u *line;
    int max_buffers;
    if (find_viminfo_parameter ('%') == NULL)
        return;
    max_buffers = get_viminfo_parameter ('%');

    #define LINE_BUF_LEN (MAXPATHL + 40)
    line = alloc (LINE_BUF_LEN);
    if (line == NULL)
        return;
    FOR_ALL_TAB_WINDOWS (tp, win)
        set_last_cursor (win);
    fputs (_ ("\n# Buffer list:\n"), fp);
    FOR_ALL_BUFFERS (buf) {
        if (buf->b_fname == NULL || !buf->b_p_bl || bt_quickfix (buf) || bt_terminal (buf) || removable (buf->b_ffname))
            continue;
        if (max_buffers-- == 0)
            break;
        putc ('%', fp);
        home_replace (NULL, buf -> b_ffname, line, MAXPATHL, TRUE);
        vim_snprintf_add ((char *) line, LINE_BUF_LEN, "\t%ld\t%d", (long) buf -> b_last_cursor.lnum, buf -> b_last_cursor.col);
        viminfo_writestring (fp, line);
    }
    vim_free (line);
}

int buflist_add (char_u *fname, int flags) {
    buf_T *buf;
    buf = buflist_new (fname, NULL, (linenr_T) 0, flags);
    if (buf != NULL)
        return buf->b_fnum;
    return 0;
}

char_u *alist_name (aentry_T *aep) {
    buf_T *bp;
    bp = buflist_findnr (aep->ae_fnum);
    if (bp == NULL || bp->b_fname == NULL)
        return aep->ae_fname;
    return bp->b_fname;
}

int buf_hide (buf_T *buf) {
    switch (buf->b_p_bh[0]) {
    case 'u' :
    case 'w' :
    case 'd' :
        return FALSE;
    case 'h' :
        return TRUE;
    }
    return (p_hid || cmdmod.hide);
}

int setfname (buf_T *buf, char_u *ffname, char_u *sfname, int message) {
    buf_T *obuf = NULL;
    stat_T st;
    if (ffname == NULL || *ffname == NUL) {
        VIM_CLEAR (buf -> b_ffname);
        VIM_CLEAR (buf -> b_sfname);
        st.st_dev = (dev_T) -1;
    }
    else {
        fname_expand (buf, & ffname, & sfname);
        if (ffname == NULL)
            return FAIL;
        if (mch_stat ((char *) ffname, &st) < 0)
            st.st_dev = (dev_T) -1;
        if (!(buf->b_flags & BF_DUMMY))
            obuf = buflist_findname_stat (ffname, &st);
        if (obuf != NULL && obuf != buf) {
            if (obuf->b_ml.ml_mfp != NULL) {
                if (message)
                    EMSG (_ ("E95: Buffer with this name already exists"));
                vim_free (ffname);
                return FAIL;
            }
            close_buffer (NULL, obuf, DOBUF_WIPE, FALSE);
        }
        sfname = vim_strsave (sfname);
        if (ffname == NULL || sfname == NULL) {
            vim_free (sfname);
            vim_free (ffname);
            return FAIL;
        }
        vim_free (buf -> b_ffname);
        vim_free (buf -> b_sfname);
        buf->b_ffname = ffname;
        buf->b_sfname = sfname;
    }
    buf->b_fname = buf->b_sfname;
    if (st.st_dev == (dev_T) -1)
        buf->b_dev_valid = FALSE;
    else {
        buf->b_dev_valid = TRUE;
        buf->b_dev = st.st_dev;
        buf->b_ino = st.st_ino;
    }
    buf->b_shortname = FALSE;
    buf_name_changed (buf);
    return OK;
}

void buf_name_changed (buf_T *buf) {
    if (buf->b_ml.ml_mfp != NULL)
        ml_setname (buf);
    if (curwin->w_buffer == buf)
        check_arg_idx (curwin);
    maketitle ();
    status_redraw_all ();
    fmarks_check_names (buf);
    ml_timestamp (buf);
}

void do_modelines (int flags) {
    linenr_T lnum;
    int nmlines;
    static int entered = 0;
    if (!curbuf->b_p_ml || (nmlines = (int) p_mls) == 0)
        return;
    if (entered)
        return;
    ++entered;
    for (lnum = 1; lnum <= curbuf->b_ml.ml_line_count && lnum <= nmlines; ++lnum)
        if (chk_modeline (lnum, flags) == FAIL)
            nmlines = 0;
    for (lnum = curbuf->b_ml.ml_line_count; lnum > 0 && lnum > nmlines && lnum > curbuf->b_ml.ml_line_count - nmlines; --lnum)
        if (chk_modeline (lnum, flags) == FAIL)
            nmlines = 0;
    --entered;
}

#include "version.h"		/* for version number */

static int chk_modeline (linenr_T lnum, int flags) {
    char_u *s;
    char_u *e;
    char_u *linecopy;
    int prev;
    int vers;
    int end;
    int retval = OK;
    char_u *save_sourcing_name;
    linenr_T save_sourcing_lnum;
    scid_T save_SID;
    prev = -1;
    for (s = ml_get (lnum); *s != NUL; ++s) {
        if (prev == -1 || vim_isspace (prev)) {
            if ((prev != -1 && STRNCMP (s, "ex:", (size_t) 3) == 0) || STRNCMP (s, "vi:", (size_t) 3) == 0)
                break;
            if ((s[0] == 'v' || s[0] == 'V') && s[1] == 'i' && s[2] == 'm') {
                if (s[3] == '<' || s[3] == '=' || s[3] == '>')
                    e = s + 4;
                else
                    e = s + 3;
                vers = getdigits (&e);
                if (*e == ':' && (s[0] != 'V' || STRNCMP (skipwhite (e + 1), "set", 3) == 0) && (s[3] == ':' || (VIM_VERSION_100 >= vers && isdigit (s[3])) || (VIM_VERSION_100 < vers && s[3] == '<') || (VIM_VERSION_100 > vers && s[3] == '>') || (VIM_VERSION_100 == vers && s[3] == '=')))
                    break;
            }
        }
        prev = *s;
    }
    if (*s) {
        do
            ++s;
        while (s[-1] != ':');
        s = linecopy = vim_strsave (s);
        if (linecopy == NULL)
            return FAIL;
        save_sourcing_lnum = sourcing_lnum;
        save_sourcing_name = sourcing_name;
        sourcing_lnum = lnum;
        sourcing_name = (char_u *) "modelines";
        end = FALSE;
        while (end == FALSE) {
            s = skipwhite (s);
            if (*s == NUL)
                break;
            for (e = s; *e != ':' && *e != NUL; ++e)
                if (e[0] == '\\' && e[1] == ':')
                    STRMOVE (e, e +1);
            if (*e == NUL)
                end = TRUE;
            if (STRNCMP (s, "set ", (size_t) 4) == 0 || STRNCMP (s, "se ", (size_t) 3) == 0) {
                if (*e != ':')
                    break;
                end = TRUE;
                s = vim_strchr (s, ' ') + 1;
            }
            *e = NUL;
            if (*s != NUL) {
                save_SID = current_SID;
                current_SID = SID_MODELINE;
                retval = do_set (s, OPT_MODELINE | OPT_LOCAL | flags);
                current_SID = save_SID;
                if (retval == FAIL)
                    break;
            }
            s = e + 1;
        }
        sourcing_lnum = save_sourcing_lnum;
        sourcing_name = save_sourcing_name;
        vim_free (linecopy);
    }
    return retval;
}

void col_print (char_u *buf, size_t buflen, int col, int vcol) {
    if (col == vcol)
        vim_snprintf ((char *) buf, buflen, "%d", col);
    else
        vim_snprintf ((char *) buf, buflen, "%d-%d", col, vcol);
}

void get_rel_pos (win_T *wp, char_u *buf, int buflen) {
    long  above;
    long  below;
    if (buflen < 3)
        return;
    above = wp->w_topline - 1;
    above += diff_check_fill (wp, wp->w_topline) - wp->w_topfill;
    if (wp->w_topline == 1 && wp->w_topfill >= 1)
        above = 0;
    below = wp->w_buffer->b_ml.ml_line_count - wp->w_botline + 1;
    if (below <= 0)
        vim_strncpy (buf, (char_u *) (above == 0 ? _ ("All") : _ ("Bot")), (size_t) (buflen - 1));
    else if (above <= 0)
        vim_strncpy (buf, (char_u *) _ ("Top"), (size_t) (buflen - 1));
    else
        vim_snprintf ((char *) buf, (size_t) buflen, "%2d%%", above > 1000000L ? (int) (above / ((above + below) / 100L)) : (int) (above * 100L / (above + below)));
}

int buf_getsigntype (buf_T *buf, linenr_T lnum, int type) {
    signlist_T *sign;
    for (sign = buf->b_signlist; sign != NULL; sign = sign->next)
        if (sign->lnum == lnum && (type == SIGN_ANY || (type == SIGN_TEXT && sign_get_text (sign->typenr) != NULL) || (type == SIGN_LINEHL && sign_get_attr (sign->typenr, TRUE) != 0)))
            return sign->typenr;
    return 0;
}

void sign_mark_adjust (linenr_T line1, linenr_T line2, long  amount, long  amount_after) {
    signlist_T *sign;
    for (sign = curbuf->b_signlist; sign != NULL; sign = sign->next) {
        if (sign->lnum >= line1 && sign->lnum <= line2) {
            if (amount == MAXLNUM)
                sign->lnum = line1;
            else
                sign->lnum += amount;
        }
        else if (sign->lnum > line2)
            sign->lnum += amount_after;
    }
}

void no_write_message (void) {
    if (term_job_running (curbuf->b_term))
        EMSG (_ ("E948: Job still running (add ! to end the job)"));
    else
        EMSG (_ ("E37: No write since last change (add ! to override)"));
}

void no_write_message_nobang (void) {
    if (term_job_running (curbuf->b_term))
        EMSG (_ ("E948: Job still running"));
    else
        EMSG (_ ("E37: No write since last change"));
}

void buf_set_name (int fnum, char_u *name) {
    buf_T *buf;
    buf = buflist_findnr (fnum);
    if (buf != NULL) {
        vim_free (buf -> b_sfname);
        vim_free (buf -> b_ffname);
        buf->b_ffname = vim_strsave (name);
        buf->b_sfname = NULL;
        fname_expand (buf, & buf -> b_ffname, & buf -> b_sfname);
        buf->b_fname = buf->b_sfname;
    }
}

int otherfile (char_u *ffname) {
    return otherfile_buf (curbuf, ffname, NULL);
}

buf_T *setaltfname (char_u *ffname, char_u *sfname, linenr_T lnum) {
    buf_T *buf;
    buf = buflist_new (ffname, sfname, lnum, 0);
    if (buf != NULL && !cmdmod.keepalt)
        curwin->w_alt_fnum = buf->b_fnum;
    return buf;
}

void buflist_altfpos (win_T *win) {
    buflist_setfpos (curbuf, win, win -> w_cursor.lnum, win -> w_cursor.col, TRUE);
}

pos_T *buflist_findfpos (buf_T *buf) {
    wininfo_T *wip;
    static pos_T no_position = INIT_POS_T (1, 0, 0);
    wip = find_wininfo (buf, FALSE);
    if (wip != NULL)
        return &(wip->wi_fpos);
    else
        return &no_position;
}

static wininfo_T *find_wininfo (buf_T *buf, int skip_diff_buffer) {
    wininfo_T *wip;
    for (wip = buf->b_wininfo; wip != NULL; wip = wip->wi_next)
        if (wip->wi_win == curwin && (!skip_diff_buffer || !wininfo_other_tab_diff (wip)))
            break;
    if (wip == NULL) {
        if (skip_diff_buffer) {
            for (wip = buf->b_wininfo; wip != NULL; wip = wip->wi_next)
                if (!wininfo_other_tab_diff (wip))
                    break;
        }
        else
            wip = buf->b_wininfo;
    }
    return wip;
}

static int wininfo_other_tab_diff (wininfo_T *wip) {
    win_T *wp;
    if (wip->wi_opt.wo_diff) {
        FOR_ALL_WINDOWS (wp)
            if (wip->wi_win == wp)
                return FALSE;
        return TRUE;
    }
    return FALSE;
}

void get_winopts (buf_T *buf) {
    wininfo_T *wip;
    clear_winopt (& curwin -> w_onebuf_opt);
    clearFolding (curwin);
    wip = find_wininfo (buf, TRUE);
    if (wip != NULL && wip->wi_optset) {
        copy_winopt (& wip -> wi_opt, & curwin -> w_onebuf_opt);
        curwin->w_fold_manual = wip->wi_fold_manual;
        curwin->w_foldinvalid = TRUE;
        cloneFoldGrowArray (& wip -> wi_folds, & curwin -> w_folds);
    }
    else
        copy_winopt (&curwin->w_allbuf_opt, &curwin->w_onebuf_opt);
    if (p_fdls >= 0)
        curwin->w_p_fdl = p_fdls;
    check_colorcolumn (curwin);
}

void set_buflisted (int on) {
    if (on != curbuf->b_p_bl) {
        curbuf->b_p_bl = on;
        if (on)
            apply_autocmds (EVENT_BUFADD, NULL, NULL, FALSE, curbuf);
        else
            apply_autocmds (EVENT_BUFDELETE, NULL, NULL, FALSE, curbuf);
    }
}

void enter_buffer (buf_T *buf) {
    buf_copy_options (buf, BCO_ENTER | BCO_NOHELP);
    if (!buf->b_help)
        get_winopts (buf);
    else
        clearFolding (curwin);
    foldUpdateAll (curwin);
    curwin->w_buffer = buf;
    curbuf = buf;
    ++curbuf->b_nwindows;
    if (curwin->w_p_diff)
        diff_buf_add (curbuf);
    curwin->w_s = &(curbuf->b_s);
    curwin->w_cursor.lnum = 1;
    curwin->w_cursor.col = 0;
    curwin->w_cursor.coladd = 0;
    curwin->w_set_curswant = TRUE;
    curwin->w_topline_was_set = FALSE;
    curwin->w_valid = 0;
    if (curbuf->b_ml.ml_mfp == NULL) {
        if (*curbuf->b_p_ft == NUL)
            did_filetype = FALSE;
        open_buffer (FALSE, NULL, 0);
    }
    else {
        if (!msg_silent)
            need_fileinfo = TRUE;
        (void) buf_check_timestamp (curbuf, FALSE);
        curwin->w_topline = 1;
        curwin->w_topfill = 0;
        apply_autocmds (EVENT_BUFENTER, NULL, NULL, FALSE, curbuf);
        apply_autocmds (EVENT_BUFWINENTER, NULL, NULL, FALSE, curbuf);
    }
    if (curwin->w_cursor.lnum == 1 && inindent (0))
        buflist_getfpos ();
    check_arg_idx (curwin);
    maketitle ();
    if (curwin->w_topline == 1 && !curwin->w_topline_was_set)
        scroll_cursor_halfway (FALSE);
    netbeans_file_activated (curbuf);
    DO_AUTOCHDIR
    if (curbuf->b_kmap_state & KEYMAP_INIT)
        (void) keymap_init ();
    if (!curbuf->b_help && curwin->w_p_spell && *curwin->w_s->b_p_spl != NUL)
        (void) did_set_spelllang (curwin);
    curbuf->b_last_used = vim_time ();
    redraw_later (NOT_VALID);
}

void buflist_getfpos (void) {
    pos_T *fpos;
    fpos = buflist_findfpos (curbuf);
    curwin->w_cursor.lnum = fpos->lnum;
    check_cursor_lnum ();
    if (p_sol)
        curwin->w_cursor.col = 0;
    else {
        curwin->w_cursor.col = fpos->col;
        check_cursor_col ();
        curwin->w_cursor.coladd = 0;
        curwin->w_set_curswant = TRUE;
    }
}

int ExpandBufnames (char_u *pat, int *num_file, char_u ***file, int options) {
    int count = 0;
    buf_T *buf;
    int round;
    char_u *p;
    int attempt;
    char_u *patc;
    *num_file = 0;
    *file = NULL;
    if (*pat == '^') {
        patc = alloc ((unsigned ) STRLEN (pat) + 11);
        if (patc == NULL)
            return FAIL;
        STRCPY (patc, "\\(^\\|[\\/]\\)");
        STRCPY (patc + 11, pat + 1);
    }
    else
        patc = pat;
    for (attempt = 0; attempt <= 1; ++attempt) {
        regmatch_T regmatch;
        if (attempt > 0 && patc == pat)
            break;
        regmatch.regprog = vim_regcomp (patc +attempt * 11, RE_MAGIC);
        if (regmatch.regprog == NULL) {
            if (patc != pat)
                vim_free (patc);
            return FAIL;
        }
        for (round = 1; round <= 2; ++round) {
            count = 0;
            FOR_ALL_BUFFERS (buf) {
                if (!buf->b_p_bl)
                    continue;
                p = buflist_match (&regmatch, buf, p_wic);
                if (p != NULL) {
                    if (round == 1)
                        ++count;
                    else {
                        if (options & WILD_HOME_REPLACE)
                            p = home_replace_save (buf, p);
                        else
                            p = vim_strsave (p);
                        (*file)[count++] = p;
                    }
                }
            }
            if (count == 0)
                break;
            if (round == 1) {
                *file = (char_u **) alloc ((unsigned ) (count * sizeof (char_u *)));
                if (*file == NULL) {
                    vim_regfree (regmatch.regprog);
                    if (patc != pat)
                        vim_free (patc);
                    return FAIL;
                }
            }
        }
        vim_regfree (regmatch.regprog);
        if (count)
            break;
    }
    if (patc != pat)
        vim_free (patc);
    *num_file = count;
    return (count == 0 ? FAIL : OK);
}

int bt_help (buf_T *buf) {
    return buf != NULL && buf->b_help;
}

char_u *getaltfname (int errmsg) {
    char_u *fname;
    linenr_T dummy;
    if (buflist_name_nr (0, &fname, &dummy) == FAIL) {
        if (errmsg)
            EMSG (_ (e_noalt));
        return NULL;
    }
    return fname;
}

int buflist_name_nr (int fnum, char_u **fname, linenr_T *lnum) {
    buf_T *buf;
    buf = buflist_findnr (fnum);
    if (buf == NULL || buf->b_fname == NULL)
        return FAIL;
    *fname = buf->b_fname;
    *lnum = buflist_findlnum (buf);
    return OK;
}

linenr_T buflist_findlnum (buf_T *buf) {
    return buflist_findfpos (buf)->lnum;
}

void fileinfo (int fullname, int shorthelp, int dont_truncate) {
    char_u *name;
    int n;
    char_u *p;
    char_u *buffer;
    size_t len;
    buffer = alloc (IOSIZE);
    if (buffer == NULL)
        return;
    if (fullname > 1) {
        vim_snprintf ((char *) buffer, IOSIZE, "buf %d: ", curbuf -> b_fnum);
        p = buffer + STRLEN (buffer);
    }
    else
        p = buffer;
    *p++ = '"';
    if (buf_spname (curbuf) != NULL)
        vim_strncpy (p, buf_spname (curbuf), IOSIZE -(p - buffer) - 1);
    else {
        if (!fullname && curbuf->b_fname != NULL)
            name = curbuf->b_fname;
        else
            name = curbuf->b_ffname;
        home_replace (shorthelp ? curbuf : NULL, name, p, (int) (IOSIZE - (p - buffer)), TRUE);
    }
    vim_snprintf_add ((char *) buffer, IOSIZE, "\"%s%s%s%s%s%s", curbufIsChanged () ? (shortmess (SHM_MOD) ? " [+]" : _ (" [Modified]")) : " ", (curbuf -> b_flags & BF_NOTEDITED) && ! bt_dontwrite (curbuf) ? _ ("[Not edited]") : "", (curbuf -> b_flags & BF_NEW) && ! bt_dontwrite (curbuf) ? _ ("[New file]") : "", (curbuf -> b_flags & BF_READERR) ? _ ("[Read errors]") : "", curbuf -> b_p_ro ? (shortmess (SHM_RO) ? _ ("[RO]") : _ ("[readonly]")) : "", (curbufIsChanged () || (curbuf -> b_flags & BF_WRITE_MASK) || curbuf -> b_p_ro) ? " " : "");
    if (curwin->w_cursor.lnum > 1000000L)
        n = (int) (((long ) curwin->w_cursor.lnum) / ((long ) curbuf->b_ml.ml_line_count / 100L));
    else
        n = (int) (((long ) curwin->w_cursor.lnum * 100L) / (long ) curbuf->b_ml.ml_line_count);
    if (curbuf->b_ml.ml_flags & ML_EMPTY) {
        vim_snprintf_add ((char *) buffer, IOSIZE, "%s", _ (no_lines_msg));
    }
    else if (p_ru) {
        if (curbuf->b_ml.ml_line_count == 1)
            vim_snprintf_add ((char *) buffer, IOSIZE, _ ("1 line --%d%%--"), n);
        else
            vim_snprintf_add ((char *) buffer, IOSIZE, _ ("%ld lines --%d%%--"), (long ) curbuf->b_ml.ml_line_count, n);
    }
    else {
        vim_snprintf_add ((char *) buffer, IOSIZE, _ ("line %ld of %ld --%d%%-- col "), (long) curwin -> w_cursor.lnum, (long) curbuf -> b_ml.ml_line_count, n);
        validate_virtcol ();
        len = STRLEN (buffer);
        col_print (buffer + len, IOSIZE - len, (int) curwin -> w_cursor.col + 1, (int) curwin -> w_virtcol + 1);
    }
    (void) append_arg_number (curwin, buffer, IOSIZE, !shortmess (SHM_FILE));
    if (dont_truncate) {
        msg_start ();
        n = msg_scroll;
        msg_scroll = TRUE;
        msg (buffer);
        msg_scroll = n;
    }
    else {
        p = msg_trunc_attr (buffer, FALSE, 0);
        if (restart_edit != 0 || (msg_scrolled && !need_wait_return))
            set_keep_msg (p, 0);
    }
    vim_free (buffer);
}

static int append_arg_number (win_T *wp, char_u *buf, int buflen, int add_file) {
    char_u *p;
    if (ARGCOUNT <= 1)
        return FALSE;
    p = buf + STRLEN (buf);
    if (p - buf + 35 >= buflen)
        return FALSE;
    *p++ = ' ';
    *p++ = '(';
    if (add_file) {
        STRCPY (p, "file ");
        p += 5;
    }
    vim_snprintf ((char *) p, (size_t) (buflen - (p - buf)), wp -> w_arg_idx_invalid ? "(%d) of %d)" : "%d of %d)", wp -> w_arg_idx + 1, ARGCOUNT);
    return TRUE;
}

void do_autochdir (void) {
    if ((starting == 0 || test_autochdir) && curbuf->b_ffname != NULL && vim_chdirfile (curbuf->b_ffname, "auto") == OK)
        shorten_fnames (TRUE);
}

void resettitle (void) {
    mch_settitle (lasttitle, lasticon);
}

static int read_buffer (int read_stdin, exarg_T *eap, int flags) {
    int retval = OK;
    linenr_T line_count;
    line_count = curbuf->b_ml.ml_line_count;
    retval = readfile (read_stdin ? NULL : curbuf->b_ffname, read_stdin ? NULL : curbuf->b_fname, (linenr_T) line_count, (linenr_T) 0, (linenr_T) MAXLNUM, eap, flags | READ_BUFFER);
    if (retval == OK) {
        while (--line_count >= 0)
            ml_delete ((linenr_T) 1, FALSE);
    }
    else {
        while (curbuf->b_ml.ml_line_count > line_count)
            ml_delete (line_count, FALSE);
    }
    curwin->w_cursor.lnum = 1;
    curwin->w_cursor.col = 0;
    if (read_stdin) {
        if (!readonlymode && !BUFEMPTY ())
            changed ();
        else if (retval == OK)
            unchanged (curbuf, FALSE);
        if (retval == OK) {
            apply_autocmds_retval (EVENT_STDINREADPOST, NULL, NULL, FALSE, curbuf, & retval);
        }
    }
    return retval;
}

int buf_findsign (buf_T *buf, int id) {
    signlist_T *sign;
    for (sign = buf->b_signlist; sign != NULL; sign = sign->next)
        if (sign->id == id)
            return sign->lnum;
    return 0;
}

void set_curbuf (buf_T *buf, int action) {
    buf_T *prevbuf;
    int unload = (action == DOBUF_UNLOAD || action == DOBUF_DEL || action == DOBUF_WIPE);
    long  old_tw = curbuf->b_p_tw;
    bufref_T newbufref;
    bufref_T prevbufref;
    setpcmark ();
    if (!cmdmod.keepalt)
        curwin->w_alt_fnum = curbuf->b_fnum;
    buflist_altfpos (curwin);
    VIsual_reselect = FALSE;
    prevbuf = curbuf;
    set_bufref (& prevbufref, prevbuf);
    set_bufref (& newbufref, buf);
    if (!apply_autocmds (EVENT_BUFLEAVE, NULL, NULL, FALSE, curbuf) || (bufref_valid (&prevbufref) && bufref_valid (&newbufref) && !aborting ())) {
        if (prevbuf == curwin->w_buffer)
            reset_synblock (curwin);
        if (unload)
            close_windows (prevbuf, FALSE);
        if (bufref_valid (&prevbufref) && !aborting ()) {
            win_T *previouswin = curwin;
            if (prevbuf == curbuf)
                u_sync (FALSE);
            close_buffer (prevbuf == curwin -> w_buffer ? curwin : NULL, prevbuf, unload ? action : (action == DOBUF_GOTO && ! buf_hide (prevbuf) && ! bufIsChanged (prevbuf)) ? DOBUF_UNLOAD : 0, FALSE);
            if (curwin != previouswin && win_valid (previouswin))
                curwin = previouswin;
        }
    }
    if ((buf_valid (buf) && buf != curbuf && !aborting ()) || curwin->w_buffer == NULL) {
        enter_buffer (buf);
        if (old_tw != curbuf->b_p_tw)
            check_colorcolumn (curwin);
    }
}

int buf_findsign_id (buf_T *buf, linenr_T lnum) {
    signlist_T *sign;
    for (sign = buf->b_signlist; sign != NULL; sign = sign->next)
        if (sign->lnum == lnum)
            return sign->id;
    return 0;
}

linenr_T buf_delsign (buf_T *buf, int id) {
    signlist_T **lastp;
    signlist_T *sign;
    signlist_T *next;
    linenr_T lnum;
    lastp = &buf->b_signlist;
    lnum = 0;
    for (sign = buf->b_signlist; sign != NULL; sign = next) {
        next = sign->next;
        if (sign->id == id) {
            *lastp = next;
            if (next != NULL)
                next->prev = sign->prev;
            lnum = sign->lnum;
            vim_free (sign);
            break;
        }
        else
            lastp = &sign->next;
    }
    if (buf->b_signlist == NULL) {
        redraw_buf_later (buf, NOT_VALID);
        changed_cline_bef_curs ();
    }
    return lnum;
}

char_u *do_bufdel (int command, char_u *arg, int addr_count, int start_bnr, int end_bnr, int forceit) {
    int do_current = 0;
    int deleted = 0;
    char_u *errormsg = NULL;
    int bnr;
    char_u *p;
    if (addr_count == 0) {
        (void) do_buffer (command, DOBUF_CURRENT, FORWARD, 0, forceit);
    }
    else {
        if (addr_count == 2) {
            if (*arg)
                return (char_u *) _ (e_trailing);
            bnr = start_bnr;
        }
        else
            bnr = end_bnr;
        for (; !got_int; ui_breakcheck ()) {
            if (bnr == curbuf->b_fnum)
                do_current = bnr;
            else if (do_buffer (command, DOBUF_FIRST, FORWARD, (int) bnr, forceit) == OK)
                ++deleted;
            if (addr_count == 2) {
                if (++bnr > end_bnr)
                    break;
            }
            else {
                arg = skipwhite (arg);
                if (*arg == NUL)
                    break;
                if (!VIM_ISDIGIT (*arg)) {
                    p = skiptowhite_esc (arg);
                    bnr = buflist_findpat (arg, p, command == DOBUF_WIPE, FALSE, FALSE);
                    if (bnr < 0)
                        break;
                    arg = p;
                }
                else
                    bnr = getdigits (&arg);
            }
        }
        if (!got_int && do_current && do_buffer (command, DOBUF_FIRST, FORWARD, do_current, forceit) == OK)
            ++deleted;
        if (deleted == 0) {
            if (command == DOBUF_UNLOAD)
                STRCPY (IObuff, _ ("E515: No buffers were unloaded"));
            else if (command == DOBUF_DEL)
                STRCPY (IObuff, _ ("E516: No buffers were deleted"));
            else
                STRCPY (IObuff, _ ("E517: No buffers were wiped out"));
            errormsg = IObuff;
        }
        else if (deleted >= p_report) {
            if (command == DOBUF_UNLOAD) {
                if (deleted == 1)
                    MSG (_ ("1 buffer unloaded"));
                else
                    smsg ((char_u *) _ ("%d buffers unloaded"), deleted);
            }
            else if (command == DOBUF_DEL) {
                if (deleted == 1)
                    MSG (_ ("1 buffer deleted"));
                else
                    smsg ((char_u *) _ ("%d buffers deleted"), deleted);
            }
            else {
                if (deleted == 1)
                    MSG (_ ("1 buffer wiped out"));
                else
                    smsg ((char_u *) _ ("%d buffers wiped out"), deleted);
            }
        }
    }
    return errormsg;
}

int do_buffer (int action, int start, int dir, int count, int forceit) {
    buf_T *buf;
    buf_T *bp;
    int unload = (action == DOBUF_UNLOAD || action == DOBUF_DEL || action == DOBUF_WIPE);
    switch (start) {
    case DOBUF_FIRST :
        buf = firstbuf;
        break;
    case DOBUF_LAST :
        buf = lastbuf;
        break;
    default :
        buf = curbuf;
        break;
    }
    if (start == DOBUF_MOD) {
        while (count-- > 0) {
            do {
                buf = buf->b_next;
                if (buf == NULL)
                    buf = firstbuf;
            }
            while (buf != curbuf && !bufIsChanged (buf));
        }
        if (!bufIsChanged (buf)) {
            EMSG (_ ("E84: No modified buffer found"));
            return FAIL;
        }
    }
    else if (start == DOBUF_FIRST && count) {
        while (buf != NULL && buf->b_fnum != count)
            buf = buf->b_next;
    }
    else {
        bp = NULL;
        while (count > 0 || (!unload && !buf->b_p_bl && bp != buf)) {
            if (bp == NULL)
                bp = buf;
            if (dir == FORWARD) {
                buf = buf->b_next;
                if (buf == NULL)
                    buf = firstbuf;
            }
            else {
                buf = buf->b_prev;
                if (buf == NULL)
                    buf = lastbuf;
            }
            if (unload || buf->b_p_bl) {
                --count;
                bp = NULL;
            }
            if (bp == buf) {
                EMSG (_ ("E85: There is no listed buffer"));
                return FAIL;
            }
        }
    }
    if (buf == NULL) {
        if (start == DOBUF_FIRST) {
            if (!unload)
                EMSGN (_ (e_nobufnr), count);
        }
        else if (dir == FORWARD)
            EMSG (_ ("E87: Cannot go beyond last buffer"));
        else
            EMSG (_ ("E88: Cannot go before first buffer"));
        return FAIL;
    }
    need_mouse_correct = TRUE;
    if (unload) {
        int forward;
        bufref_T bufref;
        set_bufref (& bufref, buf);
        if (action != DOBUF_WIPE && buf->b_ml.ml_mfp == NULL && !buf->b_p_bl)
            return FAIL;
        if (!forceit && bufIsChanged (buf)) {
            if ((p_confirm || cmdmod.confirm) && p_write) {
                dialog_changed (buf, FALSE);
                if (!bufref_valid (&bufref))
                    return FAIL;
                if (bufIsChanged (buf))
                    return FAIL;
            }
            else {
                EMSGN (_ ("E89: No write since last change for buffer %ld (add ! to override)"), buf -> b_fnum);
                return FAIL;
            }
        }
        if (buf == curbuf && VIsual_active)
            end_visual_mode ();
        FOR_ALL_BUFFERS (bp)
            if (bp->b_p_bl && bp != buf)
                break;
        if (bp == NULL && buf == curbuf)
            return empty_curbuf (TRUE, forceit, action);
        while (buf == curbuf && !(curwin->w_closing || curwin->w_buffer->b_locked > 0) && (!ONE_WINDOW || first_tabpage->tp_next != NULL)) {
            if (win_close (curwin, FALSE) == FAIL)
                break;
        }
        if (buf != curbuf) {
            close_windows (buf, FALSE);
            if (buf != curbuf && bufref_valid (&bufref) && buf->b_nwindows <= 0)
                close_buffer (NULL, buf, action, FALSE);
            return OK;
        }
        buf = NULL;
        bp = NULL;
        if (au_new_curbuf.br_buf != NULL && bufref_valid (&au_new_curbuf))
            buf = au_new_curbuf.br_buf;
        else if (curwin->w_jumplistlen > 0) {
            int jumpidx;
            jumpidx = curwin->w_jumplistidx - 1;
            if (jumpidx < 0)
                jumpidx = curwin->w_jumplistlen - 1;
            forward = jumpidx;
            while (jumpidx != curwin->w_jumplistidx) {
                buf = buflist_findnr (curwin->w_jumplist[jumpidx].fmark.fnum);
                if (buf != NULL) {
                    if (buf == curbuf || !buf->b_p_bl)
                        buf = NULL;
                    else if (buf->b_ml.ml_mfp == NULL) {
                        if (bp == NULL)
                            bp = buf;
                        buf = NULL;
                    }
                }
                if (buf != NULL)
                    break;
                if (!jumpidx && curwin->w_jumplistidx == curwin->w_jumplistlen)
                    break;
                if (--jumpidx < 0)
                    jumpidx = curwin->w_jumplistlen - 1;
                if (jumpidx == forward)
                    break;
            }
        }
        if (buf == NULL) {
            forward = TRUE;
            buf = curbuf->b_next;
            for (;;) {
                if (buf == NULL) {
                    if (!forward)
                        break;
                    buf = curbuf->b_prev;
                    forward = FALSE;
                    continue;
                }
                if (buf->b_help == curbuf->b_help && buf->b_p_bl) {
                    if (buf->b_ml.ml_mfp != NULL)
                        break;
                    if (bp == NULL)
                        bp = buf;
                }
                if (forward)
                    buf = buf->b_next;
                else
                    buf = buf->b_prev;
            }
        }
        if (buf == NULL)
            buf = bp;
        if (buf == NULL) {
            FOR_ALL_BUFFERS (buf)
                if (buf->b_p_bl && buf != curbuf)
                    break;
        }
        if (buf == NULL) {
            if (curbuf->b_next != NULL)
                buf = curbuf->b_next;
            else
                buf = curbuf->b_prev;
        }
    }
    if (buf == NULL) {
        return empty_curbuf (FALSE, forceit, action);
    }
    if (action == DOBUF_SPLIT) {
        if ((swb_flags & SWB_USEOPEN) && buf_jump_open_win (buf))
            return OK;
        if ((swb_flags & SWB_USETAB) && buf_jump_open_tab (buf))
            return OK;
        if (win_split (0, 0) == FAIL)
            return FAIL;
    }
    if (buf == curbuf)
        return OK;
    if (action == DOBUF_GOTO && !can_abandon (curbuf, forceit)) {
        if ((p_confirm || cmdmod.confirm) && p_write) {
            bufref_T bufref;
            set_bufref (& bufref, buf);
            dialog_changed (curbuf, FALSE);
            if (!bufref_valid (&bufref))
                return FAIL;
        }
        if (bufIsChanged (curbuf)) {
            no_write_message ();
            return FAIL;
        }
    }
    set_curbuf (buf, action);
    if (action == DOBUF_SPLIT) {
        RESET_BINDING (curwin);
    }
    if (aborting ())
        return FAIL;
    return OK;
}

static int empty_curbuf (int close_others, int forceit, int action) {
    int retval;
    buf_T *buf = curbuf;
    bufref_T bufref;
    if (action == DOBUF_UNLOAD) {
        EMSG (_ ("E90: Cannot unload last buffer"));
        return FAIL;
    }
    set_bufref (& bufref, buf);
    if (close_others)
        close_windows (buf, TRUE);
    setpcmark ();
    retval = do_ecmd (0, NULL, NULL, NULL, ECMD_ONE, forceit ? ECMD_FORCEIT : 0, curwin);
    if (buf != curbuf && bufref_valid (&bufref) && buf->b_nwindows == 0)
        close_buffer (NULL, buf, action, FALSE);
    if (!close_others)
        need_fileinfo = FALSE;
    return retval;
}

buf_T *buflist_findname (char_u *ffname) {
    stat_T st;
    if (mch_stat ((char *) ffname, &st) < 0)
        st.st_dev = (dev_T) -1;
    return buflist_findname_stat (ffname, &st);
}

void goto_buffer (exarg_T *eap, int start, int dir, int count) {
    (void) do_buffer (*eap->cmd == 's' ? DOBUF_SPLIT : DOBUF_GOTO, start, dir, count, eap->forceit);
}

int buf_findsigntype_id (buf_T *buf, linenr_T lnum, int typenr) {
    signlist_T *sign;
    for (sign = buf->b_signlist; sign != NULL; sign = sign->next)
        if (sign->lnum == lnum && sign->typenr == typenr)
            return sign->id;
    return 0;
}

static int ti_change (char_u *str, char_u **last) {
    if ((str == NULL) != (*last == NULL) || (str != NULL && *last != NULL && STRCMP (str, *last) != 0)) {
        vim_free (*last);
        if (str == NULL)
            *last = NULL;
        else
            *last = vim_strsave (str);
        return TRUE;
    }
    return FALSE;
}

int buflist_getfile (int n, linenr_T lnum, int options, int forceit) {
    buf_T *buf;
    win_T *wp = NULL;
    pos_T *fpos;
    colnr_T col;
    buf = buflist_findnr (n);
    if (buf == NULL) {
        if ((options & GETF_ALT) && n == 0)
            EMSG (_ (e_noalt));
        else
            EMSGN (_ ("E92: Buffer %ld not found"), n);
        return FAIL;
    }
    if (buf == curbuf)
        return OK;
    if (text_locked ()) {
        text_locked_msg ();
        return FAIL;
    }
    if (curbuf_locked ())
        return FAIL;
    if (lnum == 0) {
        fpos = buflist_findfpos (buf);
        lnum = fpos->lnum;
        col = fpos->col;
    }
    else
        col = 0;
    if (options & GETF_SWITCH) {
        if (swb_flags & SWB_USEOPEN)
            wp = buf_jump_open_win (buf);
        if (wp == NULL && (swb_flags & SWB_USETAB))
            wp = buf_jump_open_tab (buf);
        if (wp == NULL && (swb_flags & (SWB_VSPLIT | SWB_SPLIT | SWB_NEWTAB)) && !BUFEMPTY ()) {
            if (swb_flags & SWB_NEWTAB)
                tabpage_new ();
            else if (win_split (0, (swb_flags & SWB_VSPLIT) ? WSP_VERT : 0) == FAIL)
                return FAIL;
            RESET_BINDING (curwin);
        }
    }
    ++RedrawingDisabled;
    if (GETFILE_SUCCESS (getfile (buf->b_fnum, NULL, NULL, (options & GETF_SETMARK), lnum, forceit))) {
        --RedrawingDisabled;
        if (!p_sol && col != 0) {
            curwin->w_cursor.col = col;
            check_cursor_col ();
            curwin->w_cursor.coladd = 0;
            curwin->w_set_curswant = TRUE;
        }
        return OK;
    }
    --RedrawingDisabled;
    return FAIL;
}

void switch_to_win_for_buf (buf_T *buf, win_T **save_curwinp, tabpage_T **save_curtabp, bufref_T *save_curbuf) {
    win_T *wp;
    tabpage_T *tp;
    if (find_win_for_buf (buf, &wp, &tp) == FAIL)
        switch_buffer (save_curbuf, buf);
    else if (switch_win (save_curwinp, save_curtabp, wp, tp, TRUE) == FAIL) {
        restore_win (* save_curwinp, * save_curtabp, TRUE);
        switch_buffer (save_curbuf, buf);
    }
}

void restore_win_for_buf (win_T *save_curwin, tabpage_T *save_curtab, bufref_T *save_curbuf) {
    if (save_curbuf->br_buf == NULL)
        restore_win (save_curwin, save_curtab, TRUE);
    else
        restore_buffer (save_curbuf);
}

buf_T *buflist_findname_exp (char_u *fname) {
    char_u *ffname;
    buf_T *buf = NULL;
    ffname = FullName_save (fname, TRUE);
    if (ffname != NULL) {
        buf = buflist_findname (ffname);
        vim_free (ffname);
    }
    return buf;
}

