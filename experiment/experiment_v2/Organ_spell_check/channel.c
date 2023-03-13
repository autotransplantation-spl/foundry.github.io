
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
EXTERN char_u e_modifiable [] INIT (= N_ ("E21: Cannot make changes, 'modifiable' is off"));
EXTERN long  p_verbose;
job_T *first_job = NULL;
EXTERN int ignored;
FILE *log_fd = NULL;
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
EXTERN char_u *p_titlestring;
char *part_names [] = {"sock", "out", "err", "in"};
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
char *e_cannot_connect = N_ ("E902: Cannot connect to port");
channel_T *first_channel = NULL;
int safe_to_invoke_callback = 0;
int channel_need_redraw = FALSE;
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
int next_ch_id = 0;
int did_log_msg = TRUE;
EXTERN int autocmd_fname_full;
EXTERN char_u *autocmd_fname INIT (= NULL);
EXTERN unsigned  swb_flags;
EXTERN pos_T where_paste_started;
proftime_T log_start;
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

void job_unref (job_T *job) {
    if (job != NULL && --job->jv_refcount <= 0) {
        if (!job_channel_still_useful (job)) {
            if (!job_need_end_check (job)) {
                job_free (job);
            }
            else if (job->jv_channel != NULL) {
                ch_log (job -> jv_channel, "detaching channel from job");
                job->jv_channel->ch_job = NULL;
                channel_unref (job -> jv_channel);
                job->jv_channel = NULL;
            }
        }
    }
}

static int job_channel_still_useful (job_T *job) {
    return job->jv_channel != NULL && channel_still_useful (job->jv_channel);
}

static int channel_still_useful (channel_T *channel) {
    int has_sock_msg;
    int has_out_msg;
    int has_err_msg;
    if (channel->ch_job_killed && channel->ch_job == NULL)
        return FALSE;
    if (channel->ch_close_cb != NULL)
        return TRUE;
    if (channel->ch_part[PART_IN].ch_bufref.br_buf != NULL)
        return TRUE;
    has_sock_msg = channel->ch_part[PART_SOCK].ch_fd != INVALID_FD || channel->ch_part[PART_SOCK].ch_head.rq_next != NULL || channel->ch_part[PART_SOCK].ch_json_head.jq_next != NULL;
    has_out_msg = channel->ch_part[PART_OUT].ch_fd != INVALID_FD || channel->ch_part[PART_OUT].ch_head.rq_next != NULL || channel->ch_part[PART_OUT].ch_json_head.jq_next != NULL;
    has_err_msg = channel->ch_part[PART_ERR].ch_fd != INVALID_FD || channel->ch_part[PART_ERR].ch_head.rq_next != NULL || channel->ch_part[PART_ERR].ch_json_head.jq_next != NULL;
    return (channel->ch_callback != NULL && (has_sock_msg || has_out_msg || has_err_msg)) || ((channel->ch_part[PART_OUT].ch_callback != NULL || channel->ch_part[PART_OUT].ch_bufref.br_buf != NULL) && has_out_msg) || ((channel->ch_part[PART_ERR].ch_callback != NULL || channel->ch_part[PART_ERR].ch_bufref.br_buf != NULL) && has_err_msg);
}

static int job_need_end_check (job_T *job) {
    return job->jv_status == JOB_STARTED && (job->jv_stoponexit != NULL || job->jv_exit_cb != NULL);
}

static void job_free (job_T *job) {
    if (!in_free_unref_items) {
        job_free_contents (job);
        job_free_job (job);
    }
}

static void job_free_contents (job_T *job) {
    ch_log (job -> jv_channel, "Freeing job");
    if (job->jv_channel != NULL) {
        job->jv_channel->ch_job = NULL;
        channel_unref (job -> jv_channel);
    }
    mch_clear_job (job);
    vim_free (job -> jv_tty_in);
    vim_free (job -> jv_tty_out);
    vim_free (job -> jv_stoponexit);
    free_callback (job -> jv_exit_cb, job -> jv_exit_partial);
}

void ch_log (channel_T *ch, const char *fmt, ... ) {
    if (log_fd != NULL) {
        va_list ap;
        ch_log_lead ("", ch);
        va_start (ap, fmt);
        vfprintf (log_fd, fmt, ap);
        va_end (ap);
        fputc ('\n', log_fd);
        fflush (log_fd);
        did_log_msg = TRUE;
    }
}

static void ch_log_lead (const char *what, channel_T *ch) {
    if (log_fd != NULL) {
        proftime_T log_now;
        profile_start (& log_now);
        profile_sub (& log_now, & log_start);
        fprintf (log_fd, "%s ", profile_msg (& log_now));
        if (ch != NULL)
            fprintf (log_fd, "%son %d: ", what, ch->ch_id);
        else
            fprintf (log_fd, "%s: ", what);
    }
}

int channel_unref (channel_T *channel) {
    if (channel != NULL && --channel->ch_refcount <= 0)
        return channel_may_free (channel);
    return FALSE;
}

static int channel_may_free (channel_T *channel) {
    if (!channel_still_useful (channel)) {
        channel_free (channel);
        return TRUE;
    }
    return FALSE;
}

static void channel_free (channel_T *channel) {
    if (!in_free_unref_items) {
        if (safe_to_invoke_callback == 0)
            channel->ch_to_be_freed = TRUE;
        else {
            channel_free_contents (channel);
            channel_free_channel (channel);
        }
    }
}

static void channel_free_contents (channel_T *channel) {
    channel_close (channel, TRUE);
    channel_clear (channel);
    ch_log (channel, "Freeing channel");
}

void channel_close (channel_T *channel, int invoke_close_cb) {
    ch_log (channel, "Closing channel");
    channel_gui_unregister (channel);
    ch_close_part (channel, PART_SOCK);
    ch_close_part (channel, PART_IN);
    ch_close_part (channel, PART_OUT);
    ch_close_part (channel, PART_ERR);
    if (invoke_close_cb) {
        ch_part_T part;
        if (channel->ch_close_cb != NULL)
            ch_log (channel, "Invoking callbacks and flushing buffers before closing");
        for (part = PART_SOCK; part < PART_IN; ++part) {
            if (channel->ch_close_cb != NULL || channel->ch_part[part].ch_bufref.br_buf != NULL) {
                ++channel->ch_refcount;
                if (channel->ch_close_cb == NULL)
                    ch_log (channel, "flushing %s buffers before closing", part_names[part]);
                while (may_invoke_callback (channel, part))
                    ;
                --channel->ch_refcount;
            }
        }
        if (channel->ch_close_cb != NULL) {
            typval_T argv [1];
            typval_T rettv;
            int dummy;
            ++channel->ch_refcount;
            ch_log (channel, "Invoking close callback %s", (char *) channel -> ch_close_cb);
            argv[0].v_type = VAR_CHANNEL;
            argv[0].vval.v_channel = channel;
            call_func (channel -> ch_close_cb, (int) STRLEN (channel -> ch_close_cb), & rettv, 1, argv, NULL, 0L, 0L, & dummy, TRUE, channel -> ch_close_partial, NULL);
            clear_tv (& rettv);
            channel_need_redraw = TRUE;
            free_callback (channel -> ch_close_cb, channel -> ch_close_partial);
            channel->ch_close_cb = NULL;
            channel->ch_close_partial = NULL;
            if (channel_need_redraw) {
                channel_need_redraw = FALSE;
                redraw_after_callback (TRUE);
            }
            if (!channel->ch_drop_never)
                for (part = PART_SOCK; part < PART_IN; ++part)
                    drop_messages (channel, part);
            --channel->ch_refcount;
        }
    }
    channel->ch_nb_close_cb = NULL;
    term_channel_closed (channel);
}

static void channel_gui_unregister (channel_T *channel) {
    ch_part_T part;
    for (part = PART_SOCK; part < PART_IN; ++part)
        channel_gui_unregister_one (channel, part);
}

static void channel_gui_unregister_one (channel_T *channel, ch_part_T part) {
    if (channel->ch_part[part].ch_inputHandler != 0) {
        gui_macvim_remove_channel (channel -> ch_part [part].ch_inputHandler);
        channel->ch_part[part].ch_inputHandler = 0;
    }
}

static void ch_close_part (channel_T *channel, ch_part_T part) {
    sock_T *fd = &channel->ch_part[part].ch_fd;
    if (*fd != INVALID_FD) {
        if (part == PART_SOCK)
            sock_close (*fd);
        else {
            if ((part == PART_IN || channel->CH_IN_FD != *fd) && (part == PART_OUT || channel->CH_OUT_FD != *fd) && (part == PART_ERR || channel->CH_ERR_FD != *fd)) {
                fd_close (*fd);
            }
        }
        *fd = INVALID_FD;
        channel->ch_to_be_closed &= ~(1 << part);
    }
}

static int may_invoke_callback (channel_T *channel, ch_part_T part) {
    char_u *msg = NULL;
    typval_T *listtv = NULL;
    typval_T argv [CH_JSON_MAX_ARGS];
    int seq_nr = -1;
    chanpart_T *ch_part = &channel->ch_part[part];
    ch_mode_T ch_mode = ch_part->ch_mode;
    cbq_T *cbhead = &ch_part->ch_cb_head;
    cbq_T *cbitem;
    char_u *callback = NULL;
    partial_T *partial = NULL;
    buf_T *buffer = NULL;
    char_u *p;
    if (channel->ch_nb_close_cb != NULL)
        return FALSE;
    for (cbitem = cbhead->cq_next; cbitem != NULL; cbitem = cbitem->cq_next)
        if (cbitem->cq_seq_nr == 0)
            break;
    if (cbitem != NULL) {
        callback = cbitem->cq_callback;
        partial = cbitem->cq_partial;
    }
    else if (ch_part->ch_callback != NULL) {
        callback = ch_part->ch_callback;
        partial = ch_part->ch_partial;
    }
    else {
        callback = channel->ch_callback;
        partial = channel->ch_partial;
    }
    buffer = ch_part->ch_bufref.br_buf;
    if (buffer != NULL && (!bufref_valid (&ch_part->ch_bufref) || buffer->b_ml.ml_mfp == NULL)) {
        ch_log (channel, "%s buffer has been wiped out", part_names [part]);
        ch_part->ch_bufref.br_buf = NULL;
        buffer = NULL;
    }
    if (ch_mode == MODE_JSON || ch_mode == MODE_JS) {
        listitem_T *item;
        int argc = 0;
        if (channel_get_json (channel, part, -1, FALSE, &listtv) == FAIL) {
            channel_parse_json (channel, part);
            if (channel_get_json (channel, part, -1, FALSE, &listtv) == FAIL)
                return FALSE;
        }
        for (item = listtv->vval.v_list->lv_first; item != NULL && argc < CH_JSON_MAX_ARGS; item = item->li_next)
            argv[argc++] = item->li_tv;
        while (argc < CH_JSON_MAX_ARGS)
            argv[argc++].v_type = VAR_UNKNOWN;
        if (argv[0].v_type == VAR_STRING) {
            channel_exe_cmd (channel, part, argv);
            free_tv (listtv);
            return TRUE;
        }
        if (argv[0].v_type != VAR_NUMBER) {
            ch_error (channel, "Dropping message with invalid sequence number type");
            free_tv (listtv);
            return FALSE;
        }
        seq_nr = argv[0].vval.v_number;
    }
    else if (channel_peek (channel, part) == NULL) {
        return FALSE;
    }
    else {
        if (callback == NULL && buffer == NULL) {
            if (channel->ch_close_cb == NULL && !channel->ch_drop_never)
                drop_messages (channel, part);
            return FALSE;
        }
        if (ch_mode == MODE_NL) {
            char_u *nl = NULL;
            char_u *buf;
            readq_T *node;
            while (TRUE) {
                node = channel_peek (channel, part);
                nl = channel_first_nl (node);
                if (nl != NULL)
                    break;
                if (channel_collapse (channel, part, TRUE) == FAIL) {
                    if (ch_part->ch_fd == INVALID_FD && node->rq_buflen > 0)
                        break;
                    return FALSE;
                }
            }
            buf = node->rq_buffer;
            if (nl == NULL) {
                char_u *new_buf;
                new_buf = vim_realloc (buf, node->rq_buflen + 1);
                if (new_buf == NULL)
                    return FALSE;
                buf = new_buf;
                node->rq_buffer = buf;
                nl = buf + node->rq_buflen++;
                *nl = NUL;
            }
            for (p = buf; p < nl && p < buf + node->rq_buflen; ++p)
                if (*p == NUL)
                    *p = NL;
            if (nl + 1 == buf + node->rq_buflen) {
                msg = channel_get (channel, part);
                *nl = NUL;
            }
            else {
                msg = vim_strnsave (buf, (int) (nl - buf));
                channel_consume (channel, part, (int) (nl - buf) + 1);
            }
        }
        else {
            msg = channel_get_all (channel, part);
        }
        if (msg == NULL)
            return FALSE;
        argv[1].v_type = VAR_STRING;
        argv[1].vval.v_string = msg;
    }
    if (seq_nr > 0) {
        int done = FALSE;
        for (cbitem = cbhead->cq_next; cbitem != NULL; cbitem = cbitem->cq_next)
            if (cbitem->cq_seq_nr == seq_nr) {
                invoke_one_time_callback (channel, cbhead, cbitem, argv);
                done = TRUE;
                break;
            }
        if (!done) {
            if (channel->ch_drop_never) {
                channel_push_json (channel, part, listtv);
                listtv = NULL;
            }
            else
                ch_log (channel, "Dropping message %d without callback", seq_nr);
        }
    }
    else if (callback != NULL || buffer != NULL) {
        if (buffer != NULL) {
            if (msg == NULL)
                msg = json_encode (listtv, ch_mode);
            if (msg != NULL) {
                if (buffer->b_term != NULL)
                    write_to_term (buffer, msg, channel);
                else
                    append_to_buffer (buffer, msg, channel, part);
            }
        }
        if (callback != NULL) {
            if (cbitem != NULL)
                invoke_one_time_callback (channel, cbhead, cbitem, argv);
            else {
                ch_log (channel, "Invoking channel callback %s", (char *) callback);
                invoke_callback (channel, callback, partial, argv);
            }
        }
    }
    else
        ch_log (channel, "Dropping message %d", seq_nr);
    if (listtv != NULL)
        free_tv (listtv);
    vim_free (msg);
    return TRUE;
}

char *channel_status (channel_T *channel, int req_part) {
    ch_part_T part;
    int has_readahead = FALSE;
    if (channel == NULL)
        return "fail";
    if (req_part == PART_OUT) {
        if (channel->CH_OUT_FD != INVALID_FD)
            return "open";
        if (channel_has_readahead (channel, PART_OUT))
            has_readahead = TRUE;
    }
    else if (req_part == PART_ERR) {
        if (channel->CH_ERR_FD != INVALID_FD)
            return "open";
        if (channel_has_readahead (channel, PART_ERR))
            has_readahead = TRUE;
    }
    else {
        if (channel_is_open (channel))
            return "open";
        for (part = PART_SOCK; part < PART_IN; ++part)
            if (channel_has_readahead (channel, part)) {
                has_readahead = TRUE;
                break;
            }
    }
    if (has_readahead)
        return "buffered";
    return "closed";
}

int channel_has_readahead (channel_T *channel, ch_part_T part) {
    ch_mode_T ch_mode = channel->ch_part[part].ch_mode;
    if (ch_mode == MODE_JSON || ch_mode == MODE_JS) {
        jsonq_T *head = &channel->ch_part[part].ch_json_head;
        jsonq_T *item = head->jq_next;
        return item != NULL;
    }
    return channel_peek (channel, part) != NULL;
}

readq_T *channel_peek (channel_T *channel, ch_part_T part) {
    readq_T *head = &channel->ch_part[part].ch_head;
    return head->rq_next;
}

int channel_is_open (channel_T *channel) {
    return channel != NULL && (channel->CH_SOCK_FD != INVALID_FD || channel->CH_IN_FD != INVALID_FD || channel->CH_OUT_FD != INVALID_FD || channel->CH_ERR_FD != INVALID_FD);
}

static int channel_fill_poll_write (int nfd_in, struct pollfd *fds) {
    int nfd = nfd_in;
    channel_T *ch;
    for (ch = first_channel; ch != NULL; ch = ch->ch_next) {
        chanpart_T *in_part = &ch->ch_part[PART_IN];
        if (in_part->ch_fd != INVALID_FD && (in_part->ch_bufref.br_buf != NULL || in_part->ch_writeque.wq_next != NULL)) {
            in_part->ch_poll_idx = nfd;
            fds[nfd].fd = in_part->ch_fd;
            fds[nfd].events = POLLOUT;
            ++nfd;
        }
        else
            in_part->ch_poll_idx = -1;
    }
    return nfd;
}

static void channel_read (channel_T *channel, ch_part_T part, char *func) {
    static char_u *buf = NULL;
    int len = 0;
    int readlen = 0;
    sock_T fd;
    int use_socket = FALSE;
    fd = channel->ch_part[part].ch_fd;
    if (fd == INVALID_FD) {
        ch_error (channel, "channel_read() called while %s part is closed", part_names [part]);
        return;
    }
    use_socket = fd == channel->CH_SOCK_FD;
    if (buf == NULL) {
        buf = alloc (MAXMSGSIZE);
        if (buf == NULL)
            return;
    }
    for (;;) {
        if (channel_wait (channel, fd, 0) != CW_READY)
            break;
        if (use_socket)
            len = sock_read (fd, (char *) buf, MAXMSGSIZE);
        else
            len = fd_read (fd, (char *) buf, MAXMSGSIZE);
        if (len <= 0)
            break;
        channel_save (channel, part, buf, len, FALSE, "RECV ");
        readlen += len;
        if (len < MAXMSGSIZE)
            break;
    }
    if (readlen <= 0) {
        if (!channel->ch_keep_open)
            ch_close_part_on_error (channel, part, (len < 0), func);
    }
}

static void ch_error (channel_T *ch, const char *fmt, ... ) {
    if (log_fd != NULL) {
        va_list ap;
        ch_log_lead ("ERR ", ch);
        va_start (ap, fmt);
        vfprintf (log_fd, fmt, ap);
        va_end (ap);
        fputc ('\n', log_fd);
        fflush (log_fd);
        did_log_msg = TRUE;
    }
}

static channel_wait_result channel_wait (channel_T *channel, sock_T fd, int timeout) {
    if (timeout > 0)
        ch_log (channel, "Waiting for up to %d msec", timeout);
    {
        for (;;) {
            struct pollfd fds [MAX_OPEN_CHANNELS + 1];
            int nfd = 1;
            fds[0].fd = fd;
            fds[0].events = POLLIN;
            nfd = channel_fill_poll_write (nfd, fds);
            if (poll (fds, nfd, timeout) > 0) {
                if (fds[0].revents & POLLIN)
                    return CW_READY;
                channel_write_any_lines ();
                continue;
            }
            break;
        }
    }
    return CW_NOT_READY;
}

void channel_write_any_lines (void) {
    channel_T *channel;
    for (channel = first_channel; channel != NULL; channel = channel->ch_next)
        channel_write_input (channel);
}

static void channel_write_input (channel_T *channel) {
    chanpart_T *in_part = &channel->ch_part[PART_IN];
    if (in_part->ch_writeque.wq_next != NULL)
        channel_send (channel, PART_IN, (char_u *) "", 0, "channel_write_input");
    else if (in_part->ch_bufref.br_buf != NULL) {
        if (in_part->ch_buf_append)
            channel_write_new_lines (in_part->ch_bufref.br_buf);
        else
            channel_write_in (channel);
    }
}

int channel_send (channel_T *channel, ch_part_T part, char_u *buf_arg, int len_arg, char *fun) {
    int res;
    sock_T fd;
    chanpart_T *ch_part = &channel->ch_part[part];
    int did_use_queue = FALSE;
    fd = ch_part->ch_fd;
    if (fd == INVALID_FD) {
        if (!channel->ch_error && fun != NULL) {
            ch_error (channel, "%s(): write while not connected", fun);
            EMSG2 (_ ("E630: %s(): write while not connected"), fun);
        }
        channel->ch_error = TRUE;
        return FAIL;
    }
    if (ch_log_active ()) {
        ch_log_lead ("SEND ", channel);
        fprintf (log_fd, "'");
        ignored = (int) fwrite (buf_arg, len_arg, 1, log_fd);
        fprintf (log_fd, "'\n");
        fflush (log_fd);
        did_log_msg = TRUE;
    }
    for (;;) {
        writeq_T *wq = &ch_part->ch_writeque;
        char_u *buf;
        int len;
        if (wq->wq_next != NULL) {
            buf = wq->wq_next->wq_ga.ga_data;
            len = wq->wq_next->wq_ga.ga_len;
            did_use_queue = TRUE;
        }
        else {
            if (len_arg == 0)
                return OK;
            buf = buf_arg;
            len = len_arg;
        }
        if (part == PART_SOCK)
            res = sock_write (fd, (char *) buf, len);
        else {
            res = fd_write (fd, (char *) buf, len);
        }
        if (res < 0 && (errno == EWOULDBLOCK))
            res = 0;
        if (res >= 0 && ch_part->ch_nonblocking) {
            writeq_T *entry = wq->wq_next;
            if (did_use_queue)
                ch_log (channel, "Sent %d bytes now", res);
            if (res == len) {
                if (entry != NULL) {
                    remove_from_writeque (wq, entry);
                    continue;
                }
                if (did_use_queue)
                    ch_log (channel, "Write queue empty");
            }
            else {
                if (entry != NULL) {
                    if (res > 0) {
                        mch_memmove (entry -> wq_ga.ga_data, (char *) entry -> wq_ga.ga_data + res, len - res);
                        entry->wq_ga.ga_len -= res;
                    }
                    buf = buf_arg;
                    len = len_arg;
                }
                else {
                    buf += res;
                    len -= res;
                }
                ch_log (channel, "Adding %d bytes to the write queue", len);
                if (wq->wq_prev != NULL && wq->wq_prev->wq_ga.ga_len + len < 4000) {
                    writeq_T *last = wq->wq_prev;
                    if (ga_grow (&last->wq_ga, len) == OK) {
                        mch_memmove ((char *) last -> wq_ga.ga_data + last -> wq_ga.ga_len, buf, len);
                        last->wq_ga.ga_len += len;
                    }
                }
                else {
                    writeq_T *last = (writeq_T *) alloc ((int) sizeof (writeq_T));
                    if (last != NULL) {
                        last->wq_prev = wq->wq_prev;
                        last->wq_next = NULL;
                        if (wq->wq_prev == NULL)
                            wq->wq_next = last;
                        else
                            wq->wq_prev->wq_next = last;
                        wq->wq_prev = last;
                        ga_init2 (& last -> wq_ga, 1, 1000);
                        if (ga_grow (&last->wq_ga, len) == OK) {
                            mch_memmove (last -> wq_ga.ga_data, buf, len);
                            last->wq_ga.ga_len = len;
                        }
                    }
                }
            }
        }
        else if (res != len) {
            if (!channel->ch_error && fun != NULL) {
                ch_error (channel, "%s(): write failed", fun);
                EMSG2 (_ ("E631: %s(): write failed"), fun);
            }
            channel->ch_error = TRUE;
            return FAIL;
        }
        channel->ch_error = FALSE;
        return OK;
    }
}

int ch_log_active (void) {
    return log_fd != NULL;
}

static void remove_from_writeque (writeq_T *wq, writeq_T *entry) {
    ga_clear (& entry -> wq_ga);
    wq->wq_next = entry->wq_next;
    if (wq->wq_next == NULL)
        wq->wq_prev = NULL;
    else
        wq->wq_next->wq_prev = NULL;
    vim_free (entry);
}

void channel_write_new_lines (buf_T *buf) {
    channel_T *channel;
    int found_one = FALSE;
    for (channel = first_channel; channel != NULL; channel = channel->ch_next) {
        chanpart_T *in_part = &channel->ch_part[PART_IN];
        linenr_T lnum;
        int written = 0;
        if (in_part->ch_bufref.br_buf == buf && in_part->ch_buf_append) {
            if (in_part->ch_fd == INVALID_FD)
                continue;
            found_one = TRUE;
            for (lnum = in_part->ch_buf_bot; lnum < buf->b_ml.ml_line_count; ++lnum) {
                if (!can_write_buf_line (channel))
                    break;
                write_buf_line (buf, lnum, channel);
                ++written;
            }
            if (written == 1)
                ch_log (channel, "written line %d to channel", (int) lnum - 1);
            else if (written > 1)
                ch_log (channel, "written %d lines to channel", written);
            if (lnum < buf->b_ml.ml_line_count)
                ch_log (channel, "Still %d more lines to write", buf->b_ml.ml_line_count - lnum);
            in_part->ch_buf_bot = lnum;
        }
    }
    if (!found_one)
        buf->b_write_to_channel = FALSE;
}

static int can_write_buf_line (channel_T *channel) {
    chanpart_T *in_part = &channel->ch_part[PART_IN];
    if (in_part->ch_fd == INVALID_FD)
        return FALSE;
    if (in_part->ch_block_write == 1)
        in_part->ch_block_write = -1;
    else if (in_part->ch_block_write == -1)
        in_part->ch_block_write = 1;
    {
        struct pollfd fds;
        fds.fd = in_part->ch_fd;
        fds.events = POLLOUT;
        if (poll (&fds, 1, 0) <= 0) {
            ch_log (channel, "Input not ready for writing");
            return FALSE;
        }
        if (in_part->ch_block_write == 1) {
            ch_log (channel, "FAKED Input not ready for writing");
            return FALSE;
        }
    }
    return TRUE;
}

static void write_buf_line (buf_T *buf, linenr_T lnum, channel_T *channel) {
    char_u *line = ml_get_buf (buf, lnum, FALSE);
    int len = (int) STRLEN (line);
    char_u *p;
    int i;
    if ((p = alloc (len +2)) == NULL)
        return;
    memcpy ((char *) p, (char *) line, len);
    if (channel->ch_write_text_mode)
        p[len] = CAR;
    else {
        for (i = 0; i < len; ++i)
            if (p[i] == NL)
                p[i] = NUL;
        p[len] = NL;
    }
    p[len + 1] = NUL;
    channel_send (channel, PART_IN, p, len + 1, "write_buf_line");
    vim_free (p);
}

static void channel_write_in (channel_T *channel) {
    chanpart_T *in_part = &channel->ch_part[PART_IN];
    linenr_T lnum;
    buf_T *buf = in_part->ch_bufref.br_buf;
    int written = 0;
    if (buf == NULL || in_part->ch_buf_append)
        return;
    if (!bufref_valid (&in_part->ch_bufref) || buf->b_ml.ml_mfp == NULL) {
        ch_log (channel, "input buffer has been wiped out");
        in_part->ch_bufref.br_buf = NULL;
        return;
    }
    for (lnum = in_part->ch_buf_top; lnum <= in_part->ch_buf_bot && lnum <= buf->b_ml.ml_line_count; ++lnum) {
        if (!can_write_buf_line (channel))
            break;
        write_buf_line (buf, lnum, channel);
        ++written;
    }
    if (written == 1)
        ch_log (channel, "written line %d to channel", (int) lnum - 1);
    else if (written > 1)
        ch_log (channel, "written %d lines to channel", written);
    in_part->ch_buf_top = lnum;
    if (lnum > buf->b_ml.ml_line_count || lnum > in_part->ch_buf_bot) {
        if (channel->ch_job != NULL)
            term_send_eof (channel);
        in_part->ch_bufref.br_buf = NULL;
        ch_log (channel, "Finished writing all lines to channel");
        ch_close_part (channel, PART_IN);
    }
    else
        ch_log (channel, "Still %d more lines to write", buf->b_ml.ml_line_count - lnum + 1);
}

static int channel_save (channel_T *channel, ch_part_T part, char_u *buf, int len, int prepend, char *lead) {
    readq_T *node;
    readq_T *head = &channel->ch_part[part].ch_head;
    char_u *p;
    int i;
    node = (readq_T *) alloc (sizeof (readq_T));
    if (node == NULL)
        return FAIL;
    node->rq_buffer = alloc (len +1);
    if (node->rq_buffer == NULL) {
        vim_free (node);
        return FAIL;
    }
    if (channel->ch_part[part].ch_mode == MODE_NL) {
        p = node->rq_buffer;
        for (i = 0; i < len; ++i)
            if (buf[i] != CAR || i + 1 >= len || buf[i + 1] != NL)
                *p++ = buf[i];
        *p = NUL;
        node->rq_buflen = (long_u) (p - node->rq_buffer);
    }
    else {
        mch_memmove (node -> rq_buffer, buf, len);
        node->rq_buffer[len] = NUL;
        node->rq_buflen = (long_u) len;
    }
    if (prepend) {
        node->rq_next = head->rq_next;
        node->rq_prev = NULL;
        if (head->rq_next == NULL)
            head->rq_prev = node;
        else
            head->rq_next->rq_prev = node;
        head->rq_next = node;
    }
    else {
        node->rq_next = NULL;
        node->rq_prev = head->rq_prev;
        if (head->rq_prev == NULL)
            head->rq_next = node;
        else
            head->rq_prev->rq_next = node;
        head->rq_prev = node;
    }
    if (ch_log_active () && lead != NULL) {
        ch_log_lead (lead, channel);
        fprintf (log_fd, "'");
        ignored = (int) fwrite (buf, len, 1, log_fd);
        fprintf (log_fd, "'\n");
    }
    return OK;
}

static void ch_close_part_on_error (channel_T *channel, ch_part_T part, int is_err, char *func) {
    char msg [] = "%s(): Read %s from ch_part[%d], closing";
    if (is_err)
        ch_error (channel, msg, func, "error", part);
    else
        ch_log (channel, msg, func, "EOF", part);
    if (channel->ch_nb_close_cb != NULL)
        channel_save (channel, PART_SOCK, (char_u *) DETACH_MSG_RAW, (int) STRLEN (DETACH_MSG_RAW), FALSE, "PUT ");
    ch_close_part (channel, part);
    channel_gui_unregister_one (channel, part);
}

void channel_handle_events (int only_keep_open) {
    channel_T *channel;
    ch_part_T part;
    sock_T fd;
    for (channel = first_channel; channel != NULL; channel = channel->ch_next) {
        if (only_keep_open && !channel->ch_keep_open)
            continue;
        for (part = PART_SOCK; part < PART_IN; ++part) {
            fd = channel->ch_part[part].ch_fd;
            if (fd != INVALID_FD) {
                int r = channel_wait (channel, fd, 0);
                if (r == CW_READY)
                    channel_read (channel, part, "channel_handle_events");
                else if (r == CW_ERROR)
                    ch_close_part_on_error (channel, part, TRUE, "channel_handle_events");
            }
        }
    }
}

char_u *channel_first_nl (readq_T *node) {
    char_u *buffer = node->rq_buffer;
    long_u i;
    for (i = 0; i < node->rq_buflen; ++i)
        if (buffer[i] == NL)
            return buffer + i;
    return NULL;
}

int channel_collapse (channel_T *channel, ch_part_T part, int want_nl) {
    readq_T *head = &channel->ch_part[part].ch_head;
    readq_T *node = head->rq_next;
    readq_T *last_node;
    readq_T *n;
    char_u *newbuf;
    char_u *p;
    long_u len;
    if (node == NULL || node->rq_next == NULL)
        return FAIL;
    last_node = node->rq_next;
    len = node->rq_buflen + last_node->rq_buflen + 1;
    if (want_nl)
        while (last_node->rq_next != NULL && channel_first_nl (last_node) == NULL) {
            last_node = last_node->rq_next;
            len += last_node->rq_buflen;
        }
    p = newbuf = alloc (len);
    if (newbuf == NULL)
        return FAIL;
    mch_memmove (p, node -> rq_buffer, node -> rq_buflen);
    p += node->rq_buflen;
    vim_free (node -> rq_buffer);
    node->rq_buffer = newbuf;
    for (n = node; n != last_node;) {
        n = n->rq_next;
        mch_memmove (p, n -> rq_buffer, n -> rq_buflen);
        p += n->rq_buflen;
        vim_free (n -> rq_buffer);
    }
    node->rq_buflen = (long_u) (p - newbuf);
    for (n = node->rq_next; n != last_node;) {
        n = n->rq_next;
        vim_free (n -> rq_prev);
    }
    node->rq_next = last_node->rq_next;
    if (last_node->rq_next == NULL)
        head->rq_prev = node;
    else
        last_node->rq_next->rq_prev = node;
    vim_free (last_node);
    return OK;
}

char_u *channel_get (channel_T *channel, ch_part_T part) {
    readq_T *head = &channel->ch_part[part].ch_head;
    readq_T *node = head->rq_next;
    char_u *p;
    if (node == NULL)
        return NULL;
    p = node->rq_buffer;
    head->rq_next = node->rq_next;
    if (node->rq_next == NULL)
        head->rq_prev = NULL;
    else
        node->rq_next->rq_prev = NULL;
    vim_free (node);
    return p;
}

void channel_clear (channel_T *channel) {
    ch_log (channel, "Clearing channel");
    VIM_CLEAR (channel -> ch_hostname);
    channel_clear_one (channel, PART_SOCK);
    channel_clear_one (channel, PART_OUT);
    channel_clear_one (channel, PART_ERR);
    channel_clear_one (channel, PART_IN);
    free_callback (channel -> ch_callback, channel -> ch_partial);
    channel->ch_callback = NULL;
    channel->ch_partial = NULL;
    free_callback (channel -> ch_close_cb, channel -> ch_close_partial);
    channel->ch_close_cb = NULL;
    channel->ch_close_partial = NULL;
}

#define DETACH_MSG_RAW "DETACH\n"

#define MAXMSGSIZE 4096

static void channel_clear_one (channel_T *channel, ch_part_T part) {
    chanpart_T *ch_part = &channel->ch_part[part];
    jsonq_T *json_head = &ch_part->ch_json_head;
    cbq_T *cb_head = &ch_part->ch_cb_head;
    while (channel_peek (channel, part) != NULL)
        vim_free (channel_get (channel, part));
    while (cb_head->cq_next != NULL) {
        cbq_T *node = cb_head->cq_next;
        remove_cb_node (cb_head, node);
        free_callback (node -> cq_callback, node -> cq_partial);
        vim_free (node);
    }
    while (json_head->jq_next != NULL) {
        free_tv (json_head -> jq_next -> jq_value);
        remove_json_node (json_head, json_head -> jq_next);
    }
    free_callback (ch_part -> ch_callback, ch_part -> ch_partial);
    ch_part->ch_callback = NULL;
    ch_part->ch_partial = NULL;
    while (ch_part->ch_writeque.wq_next != NULL)
        remove_from_writeque (&ch_part->ch_writeque, ch_part->ch_writeque.wq_next);
}

static void remove_cb_node (cbq_T *head, cbq_T *node) {
    if (node->cq_prev == NULL)
        head->cq_next = node->cq_next;
    else
        node->cq_prev->cq_next = node->cq_next;
    if (node->cq_next == NULL)
        head->cq_prev = node->cq_prev;
    else
        node->cq_next->cq_prev = node->cq_prev;
}

static void remove_json_node (jsonq_T *head, jsonq_T *node) {
    if (node->jq_prev == NULL)
        head->jq_next = node->jq_next;
    else
        node->jq_prev->jq_next = node->jq_next;
    if (node->jq_next == NULL)
        head->jq_prev = node->jq_prev;
    else
        node->jq_next->jq_prev = node->jq_prev;
    vim_free (node);
}

int set_ref_in_channel (int copyID) {
    int abort = FALSE;
    channel_T *channel;
    typval_T tv;
    for (channel = first_channel; channel != NULL; channel = channel->ch_next)
        if (channel_still_useful (channel)) {
            tv.v_type = VAR_CHANNEL;
            tv.vval.v_channel = channel;
            abort = abort || set_ref_in_item (&tv, copyID, NULL, NULL);
        }
    return abort;
}

int set_ref_in_job (int copyID) {
    int abort = FALSE;
    job_T *job;
    typval_T tv;
    for (job = first_job; job != NULL; job = job->jv_next)
        if (job_still_useful (job)) {
            tv.v_type = VAR_JOB;
            tv.vval.v_job = job;
            abort = abort || set_ref_in_item (&tv, copyID, NULL, NULL);
        }
    return abort;
}

static int job_still_useful (job_T *job) {
    return job_need_end_check (job) || job_channel_still_useful (job);
}

int free_unused_jobs_contents (int copyID, int mask) {
    int did_free = FALSE;
    job_T *job;
    for (job = first_job; job != NULL; job = job->jv_next)
        if ((job->jv_copyID & mask) != (copyID & mask) && !job_still_useful (job)) {
            job_free_contents (job);
            did_free = TRUE;
        }
    return did_free;
}

int free_unused_channels_contents (int copyID, int mask) {
    int did_free = FALSE;
    channel_T *ch;
    ++safe_to_invoke_callback;
    for (ch = first_channel; ch != NULL; ch = ch->ch_next)
        if (!channel_still_useful (ch) && (ch->ch_copyID & mask) != (copyID & mask)) {
            channel_free_contents (ch);
            did_free = TRUE;
        }
    --safe_to_invoke_callback;
    return did_free;
}

void free_unused_jobs (int copyID, int mask) {
    job_T *job;
    job_T *job_next;
    for (job = first_job; job != NULL; job = job_next) {
        job_next = job->jv_next;
        if ((job->jv_copyID & mask) != (copyID & mask) && !job_still_useful (job)) {
            job_free_job (job);
        }
    }
}

static void job_free_job (job_T *job) {
    if (job->jv_next != NULL)
        job->jv_next->jv_prev = job->jv_prev;
    if (job->jv_prev == NULL)
        first_job = job->jv_next;
    else
        job->jv_prev->jv_next = job->jv_next;
    vim_free (job);
}

void free_unused_channels (int copyID, int mask) {
    channel_T *ch;
    channel_T *ch_next;
    for (ch = first_channel; ch != NULL; ch = ch_next) {
        ch_next = ch->ch_next;
        if (!channel_still_useful (ch) && (ch->ch_copyID & mask) != (copyID & mask)) {
            channel_free_channel (ch);
        }
    }
}

static void channel_free_channel (channel_T *channel) {
    if (channel->ch_next != NULL)
        channel->ch_next->ch_prev = channel->ch_prev;
    if (channel->ch_prev == NULL)
        first_channel = channel->ch_next;
    else
        channel->ch_prev->ch_next = channel->ch_next;
    vim_free (channel);
}

void channel_buffer_free (buf_T *buf) {
    channel_T *channel;
    ch_part_T part;
    for (channel = first_channel; channel != NULL; channel = channel->ch_next)
        for (part = PART_SOCK; part < PART_COUNT; ++part) {
            chanpart_T *ch_part = &channel->ch_part[part];
            if (ch_part->ch_bufref.br_buf == buf) {
                ch_log (channel, "%s buffer has been wiped out", part_names [part]);
                ch_part->ch_bufref.br_buf = NULL;
            }
        }
}

int job_stop (job_T *job, typval_T *argvars, char *type) {
    char_u *arg;
    if (type != NULL)
        arg = (char_u *) type;
    else if (argvars[1].v_type == VAR_UNKNOWN)
        arg = (char_u *) "";
    else {
        arg = get_tv_string_chk (&argvars[1]);
        if (arg == NULL) {
            EMSG (_ (e_invarg));
            return 0;
        }
    }
    if (job->jv_status == JOB_FAILED) {
        ch_log (job -> jv_channel, "Job failed to start, job_stop() skipped");
        return 0;
    }
    if (job->jv_status == JOB_ENDED) {
        ch_log (job -> jv_channel, "Job has already ended, job_stop() skipped");
        return 0;
    }
    ch_log (job -> jv_channel, "Stopping job with '%s'", (char *) arg);
    if (mch_signal_job (job, arg) == FAIL)
        return 0;
    if (job->jv_channel != NULL && STRCMP (arg, "kill") == 0)
        job->jv_channel->ch_job_killed = TRUE;
    return 1;
}

int has_any_channel (void) {
    return first_channel != NULL;
}

void job_stop_on_exit (void) {
    job_T *job;
    for (job = first_job; job != NULL; job = job->jv_next)
        if (job->jv_status == JOB_STARTED && job->jv_stoponexit != NULL)
            mch_signal_job (job, job->jv_stoponexit);
}

void channel_consume (channel_T *channel, ch_part_T part, int len) {
    readq_T *head = &channel->ch_part[part].ch_head;
    readq_T *node = head->rq_next;
    char_u *buf = node->rq_buffer;
    mch_memmove (buf, buf + len, node -> rq_buflen - len);
    node->rq_buflen -= len;
}

int channel_parse_messages (void) {
    channel_T *channel = first_channel;
    int ret = FALSE;
    int r;
    ch_part_T part = PART_SOCK;
    ++safe_to_invoke_callback;
    if (did_log_msg) {
        ch_log (NULL, "looking for messages on channels");
        did_log_msg = FALSE;
    }
    while (channel != NULL) {
        if (channel->ch_to_be_closed == 0) {
            channel->ch_to_be_closed = (1 << PART_COUNT);
            channel_close_now (channel);
            channel = first_channel;
            continue;
        }
        if (channel->ch_to_be_freed) {
            channel_free (channel);
            channel = first_channel;
            continue;
        }
        if (channel->ch_refcount == 0 && !channel_still_useful (channel)) {
            channel_free (channel);
            channel = first_channel;
            part = PART_SOCK;
            continue;
        }
        if (channel->ch_part[part].ch_fd != INVALID_FD || channel_has_readahead (channel, part)) {
            ++channel->ch_refcount;
            r = may_invoke_callback (channel, part);
            if (r == OK)
                ret = TRUE;
            if (channel_unref (channel) || (r == OK)) {
                channel = first_channel;
                part = PART_SOCK;
                continue;
            }
        }
        if (part < PART_ERR)
            ++part;
        else {
            channel = channel->ch_next;
            part = PART_SOCK;
        }
    }
    if (channel_need_redraw) {
        channel_need_redraw = FALSE;
        redraw_after_callback (TRUE);
    }
    --safe_to_invoke_callback;
    return ret;
}

static void channel_close_now (channel_T *channel) {
    ch_log (channel, "Closing channel because all readable fds are closed");
    if (channel->ch_nb_close_cb != NULL)
        (*channel->ch_nb_close_cb) ();
    channel_close (channel, TRUE);
}

void job_check_ended (void) {
    int i;
    if (first_job == NULL)
        return;
    for (i = 0; i < MAX_CHECK_ENDED; ++i) {
        job_T *job = mch_detect_ended_job (first_job);
        if (job == NULL)
            break;
        job_cleanup (job);
    }
    if (channel_need_redraw) {
        channel_need_redraw = FALSE;
        redraw_after_callback (TRUE);
    }
}

void job_cleanup (job_T *job) {
    if (job->jv_status != JOB_ENDED)
        return;
    job->jv_status = JOB_FINISHED;
    if (job->jv_exit_cb != NULL) {
        typval_T argv [3];
        typval_T rettv;
        int dummy;
        ch_log (job -> jv_channel, "Invoking exit callback %s", job -> jv_exit_cb);
        ++job->jv_refcount;
        argv[0].v_type = VAR_JOB;
        argv[0].vval.v_job = job;
        argv[1].v_type = VAR_NUMBER;
        argv[1].vval.v_number = job->jv_exitval;
        call_func (job -> jv_exit_cb, (int) STRLEN (job -> jv_exit_cb), & rettv, 2, argv, NULL, 0L, 0L, & dummy, TRUE, job -> jv_exit_partial, NULL);
        clear_tv (& rettv);
        --job->jv_refcount;
        channel_need_redraw = TRUE;
    }
    if (job->jv_refcount == 0 && !job_channel_still_useful (job)) {
        job_free (job);
    }
}

static int channel_get_json (channel_T *channel, ch_part_T part, int id, int without_callback, typval_T **rettv) {
    jsonq_T *head = &channel->ch_part[part].ch_json_head;
    jsonq_T *item = head->jq_next;
    while (item != NULL) {
        list_T *l = item->jq_value->vval.v_list;
        typval_T *tv = &l->lv_first->li_tv;
        if ((without_callback || !item->jq_no_callback) && ((id > 0 && tv->v_type == VAR_NUMBER && tv->vval.v_number == id) || (id <= 0 && (tv->v_type != VAR_NUMBER || tv->vval.v_number == 0 || tv->vval.v_number != channel->ch_part[part].ch_block_id)))) {
            *rettv = item->jq_value;
            if (tv->v_type == VAR_NUMBER)
                ch_log (channel, "Getting JSON message %d", tv->vval.v_number);
            remove_json_node (head, item);
            return OK;
        }
        item = item->jq_next;
    }
    return FAIL;
}

static int channel_parse_json (channel_T *channel, ch_part_T part) {
    js_read_T reader;
    typval_T listtv;
    jsonq_T *item;
    chanpart_T *chanpart = &channel->ch_part[part];
    jsonq_T *head = &chanpart->ch_json_head;
    int status;
    int ret;
    if (channel_peek (channel, part) == NULL)
        return FALSE;
    reader.js_buf = channel_get (channel, part);
    reader.js_used = 0;
    reader.js_fill = channel_fill;
    reader.js_cookie = channel;
    reader.js_cookie_arg = part;
    ++emsg_silent;
    status = json_decode (&reader, &listtv, chanpart->ch_mode == MODE_JS ? JSON_JS : 0);
    --emsg_silent;
    if (status == OK) {
        if (listtv.v_type != VAR_LIST || listtv.vval.v_list->lv_len < 2) {
            if (listtv.v_type != VAR_LIST)
                ch_error (channel, "Did not receive a list, discarding");
            else
                ch_error (channel, "Expected list with two items, got %d", listtv.vval.v_list->lv_len);
            clear_tv (& listtv);
        }
        else {
            item = (jsonq_T *) alloc ((unsigned ) sizeof (jsonq_T));
            if (item == NULL)
                clear_tv (&listtv);
            else {
                item->jq_no_callback = FALSE;
                item->jq_value = alloc_tv ();
                if (item->jq_value == NULL) {
                    vim_free (item);
                    clear_tv (& listtv);
                }
                else {
                    *item->jq_value = listtv;
                    item->jq_prev = head->jq_prev;
                    head->jq_prev = item;
                    item->jq_next = NULL;
                    if (item->jq_prev == NULL)
                        head->jq_next = item;
                    else
                        item->jq_prev->jq_next = item;
                }
            }
        }
    }
    if (status == OK)
        chanpart->ch_wait_len = 0;
    else if (status == MAYBE) {
        size_t buflen = STRLEN (reader.js_buf);
        if (chanpart->ch_wait_len < buflen) {
            ch_log (channel, "Incomplete message (%d bytes) - wait 100 msec for more", (int) buflen);
            reader.js_used = 0;
            chanpart->ch_wait_len = buflen;
            gettimeofday (& chanpart -> ch_deadline, NULL);
            chanpart->ch_deadline.tv_usec += 100 * 1000;
            if (chanpart->ch_deadline.tv_usec > 1000 * 1000) {
                chanpart->ch_deadline.tv_usec -= 1000 * 1000;
                ++chanpart->ch_deadline.tv_sec;
            }
        }
        else {
            int timeout;
            {
                struct timeval now_tv;
                gettimeofday (& now_tv, NULL);
                timeout = now_tv.tv_sec > chanpart->ch_deadline.tv_sec || (now_tv.tv_sec == chanpart->ch_deadline.tv_sec && now_tv.tv_usec > chanpart->ch_deadline.tv_usec);
            }
            if (timeout) {
                status = FAIL;
                chanpart->ch_wait_len = 0;
                ch_log (channel, "timed out");
            }
            else {
                reader.js_used = 0;
                ch_log (channel, "still waiting on incomplete message");
            }
        }
    }
    if (status == FAIL) {
        ch_error (channel, "Decoding failed - discarding input");
        ret = FALSE;
        chanpart->ch_wait_len = 0;
    }
    else if (reader.js_buf[reader.js_used] != NUL) {
        channel_save (channel, part, reader.js_buf + reader.js_used, (int) (reader.js_end - reader.js_buf) - reader.js_used, TRUE, NULL);
        ret = status == MAYBE ? FALSE : TRUE;
    }
    else
        ret = FALSE;
    vim_free (reader.js_buf);
    return ret;
}

static int channel_fill (js_read_T *reader) {
    channel_T *channel = (channel_T *) reader->js_cookie;
    ch_part_T part = reader->js_cookie_arg;
    char_u *next = channel_get (channel, part);
    int keeplen;
    int addlen;
    char_u *p;
    if (next == NULL)
        return FALSE;
    keeplen = reader->js_end - reader->js_buf;
    if (keeplen > 0) {
        addlen = (int) STRLEN (next);
        p = alloc (keeplen +addlen + 1);
        if (p == NULL) {
            vim_free (next);
            return FALSE;
        }
        mch_memmove (p, reader -> js_buf, keeplen);
        mch_memmove (p + keeplen, next, addlen + 1);
        vim_free (next);
        next = p;
    }
    vim_free (reader -> js_buf);
    reader->js_buf = next;
    return TRUE;
}

static void channel_exe_cmd (channel_T *channel, ch_part_T part, typval_T *argv) {
    char_u *cmd = argv[0].vval.v_string;
    char_u *arg;
    int options = channel->ch_part[part].ch_mode == MODE_JS ? JSON_JS : 0;
    if (argv[1].v_type != VAR_STRING) {
        ch_error (channel, "received command with non-string argument");
        if (p_verbose > 2)
            EMSG (_ ("E903: received command with non-string argument"));
        return;
    }
    arg = argv[1].vval.v_string;
    if (arg == NULL)
        arg = (char_u *) "";
    if (STRCMP (cmd, "ex") == 0) {
        int save_called_emsg = called_emsg;
        called_emsg = FALSE;
        ch_log (channel, "Executing ex command '%s'", (char *) arg);
        ++emsg_silent;
        do_cmdline_cmd (arg);
        --emsg_silent;
        if (called_emsg)
            ch_log (channel, "Ex command error: '%s'", (char *) get_vim_var_str (VV_ERRMSG));
        called_emsg = save_called_emsg;
    }
    else if (STRCMP (cmd, "normal") == 0) {
        exarg_T ea;
        ch_log (channel, "Executing normal command '%s'", (char *) arg);
        ea.arg = arg;
        ea.addr_count = 0;
        ea.forceit = TRUE;
        ex_normal (& ea);
    }
    else if (STRCMP (cmd, "redraw") == 0) {
        exarg_T ea;
        ch_log (channel, "redraw");
        ea.forceit = *arg != NUL;
        ex_redraw (& ea);
        showruler (FALSE);
        setcursor ();
        out_flush_cursor (TRUE, FALSE);
    }
    else if (STRCMP (cmd, "expr") == 0 || STRCMP (cmd, "call") == 0) {
        int is_call = cmd[0] == 'c';
        int id_idx = is_call ? 3 : 2;
        if (argv[id_idx].v_type != VAR_UNKNOWN && argv[id_idx].v_type != VAR_NUMBER) {
            ch_error (channel, "last argument for expr/call must be a number");
            if (p_verbose > 2)
                EMSG (_ ("E904: last argument for expr/call must be a number"));
        }
        else if (is_call && argv[2].v_type != VAR_LIST) {
            ch_error (channel, "third argument for call must be a list");
            if (p_verbose > 2)
                EMSG (_ ("E904: third argument for call must be a list"));
        }
        else {
            typval_T *tv = NULL;
            typval_T res_tv;
            typval_T err_tv;
            char_u *json = NULL;
            ++emsg_skip;
            if (!is_call) {
                ch_log (channel, "Evaluating expression '%s'", (char *) arg);
                tv = eval_expr (arg, NULL);
            }
            else {
                ch_log (channel, "Calling '%s'", (char *) arg);
                if (func_call (arg, &argv[2], NULL, NULL, &res_tv) == OK)
                    tv = &res_tv;
            }
            if (argv[id_idx].v_type == VAR_NUMBER) {
                int id = argv[id_idx].vval.v_number;
                if (tv != NULL)
                    json = json_encode_nr_expr (id, tv, options | JSON_NL);
                if (tv == NULL || (json != NULL && *json == NUL)) {
                    vim_free (json);
                    err_tv.v_type = VAR_STRING;
                    err_tv.vval.v_string = (char_u *) "ERROR";
                    json = json_encode_nr_expr (id, &err_tv, options | JSON_NL);
                }
                if (json != NULL) {
                    channel_send (channel, part == PART_SOCK ? PART_SOCK : PART_IN, json, (int) STRLEN (json), (char *) cmd);
                    vim_free (json);
                }
            }
            --emsg_skip;
            if (tv == &res_tv)
                clear_tv (tv);
            else
                free_tv (tv);
        }
    }
    else if (p_verbose > 2) {
        ch_error (channel, "Received unknown command: %s", (char *) cmd);
        EMSG2 (_ ("E905: received unknown command: %s"), cmd);
    }
}

static void drop_messages (channel_T *channel, ch_part_T part) {
    char_u *msg;
    while ((msg = channel_get (channel, part)) != NULL) {
        ch_log (channel, "Dropping message '%s'", (char *) msg);
        vim_free (msg);
    }
}

static char_u *channel_get_all (channel_T *channel, ch_part_T part) {
    readq_T *head = &channel->ch_part[part].ch_head;
    readq_T *node = head->rq_next;
    long_u len = 0;
    char_u *res;
    char_u *p;
    if (head->rq_next == NULL || head->rq_next->rq_next == NULL)
        return channel_get (channel, part);
    for (node = head->rq_next; node != NULL; node = node->rq_next)
        len += node->rq_buflen;
    res = lalloc (len +1, TRUE);
    if (res == NULL)
        return NULL;
    p = res;
    for (node = head->rq_next; node != NULL; node = node->rq_next) {
        mch_memmove (p, node -> rq_buffer, node -> rq_buflen);
        p += node->rq_buflen;
    }
    *p = NUL;
    do {
        p = channel_get (channel, part);
        vim_free (p);
    }
    while (p != NULL);
    while (len > 0) {
        --len;
        if (res[len] == NUL)
            res[len] = NL;
    }
    return res;
}

static void invoke_one_time_callback (channel_T *channel, cbq_T *cbhead, cbq_T *item, typval_T *argv) {
    ch_log (channel, "Invoking one-time callback %s", (char *) item -> cq_callback);
    remove_cb_node (cbhead, item);
    invoke_callback (channel, item -> cq_callback, item -> cq_partial, argv);
    free_callback (item -> cq_callback, item -> cq_partial);
    vim_free (item);
}

static void invoke_callback (channel_T *channel, char_u *callback, partial_T *partial, typval_T *argv) {
    typval_T rettv;
    int dummy;
    if (safe_to_invoke_callback == 0)
        IEMSG ("INTERNAL: Invoking callback when it is not safe");
    argv[0].v_type = VAR_CHANNEL;
    argv[0].vval.v_channel = channel;
    call_func (callback, (int) STRLEN (callback), & rettv, 2, argv, NULL, 0L, 0L, & dummy, TRUE, partial, NULL);
    clear_tv (& rettv);
    channel_need_redraw = TRUE;
}

static void channel_push_json (channel_T *channel, ch_part_T part, typval_T *rettv) {
    jsonq_T *head = &channel->ch_part[part].ch_json_head;
    jsonq_T *item = head->jq_next;
    jsonq_T *newitem;
    if (head->jq_prev != NULL && head->jq_prev->jq_no_callback)
        item = NULL;
    else
        while (item != NULL && item->jq_no_callback)
            item = item->jq_next;
    newitem = (jsonq_T *) alloc ((unsigned ) sizeof (jsonq_T));
    if (newitem == NULL)
        clear_tv (rettv);
    else {
        newitem->jq_value = alloc_tv ();
        if (newitem->jq_value == NULL) {
            vim_free (newitem);
            clear_tv (rettv);
        }
        else {
            newitem->jq_no_callback = FALSE;
            *newitem->jq_value = *rettv;
            if (item == NULL) {
                newitem->jq_prev = head->jq_prev;
                head->jq_prev = newitem;
                newitem->jq_next = NULL;
                if (newitem->jq_prev == NULL)
                    head->jq_next = newitem;
                else
                    newitem->jq_prev->jq_next = newitem;
            }
            else {
                newitem->jq_prev = item;
                newitem->jq_next = item->jq_next;
                item->jq_next = newitem;
                if (newitem->jq_next == NULL)
                    head->jq_prev = newitem;
                else
                    newitem->jq_next->jq_prev = newitem;
            }
        }
    }
}

#define CH_JSON_MAX_ARGS 4

static void append_to_buffer (buf_T *buffer, char_u *msg, channel_T *channel, ch_part_T part) {
    bufref_T save_curbuf = {NULL, 0, 0};
    win_T *save_curwin = NULL;
    tabpage_T *save_curtab = NULL;
    linenr_T lnum = buffer->b_ml.ml_line_count;
    int save_write_to = buffer->b_write_to_channel;
    chanpart_T *ch_part = &channel->ch_part[part];
    int save_p_ma = buffer->b_p_ma;
    int empty = (buffer->b_ml.ml_flags & ML_EMPTY) ? 1 : 0;
    if (!buffer->b_p_ma && !ch_part->ch_nomodifiable) {
        if (!ch_part->ch_nomod_error) {
            ch_error (channel, "Buffer is not modifiable, cannot append");
            ch_part->ch_nomod_error = TRUE;
        }
        return;
    }
    if (save_write_to) {
        --lnum;
        buffer->b_write_to_channel = FALSE;
    }
    ch_log (channel, "appending line %d to buffer", (int) lnum + 1 - empty);
    buffer->b_p_ma = TRUE;
    switch_to_win_for_buf (buffer, & save_curwin, & save_curtab, & save_curbuf);
    u_sync (TRUE);
    ignored = u_save (lnum -empty, lnum +1);
    if (empty) {
        ml_replace (lnum, msg, TRUE);
        lnum = 0;
    }
    else
        ml_append (lnum, msg, 0, FALSE);
    appended_lines_mark (lnum, 1L);
    restore_win_for_buf (save_curwin, save_curtab, & save_curbuf);
    if (ch_part->ch_nomodifiable)
        buffer->b_p_ma = FALSE;
    else
        buffer->b_p_ma = save_p_ma;
    if (buffer->b_nwindows > 0) {
        win_T *wp;
        FOR_ALL_WINDOWS (wp) {
            if (wp->w_buffer == buffer && (save_write_to ? wp->w_cursor.lnum == lnum + 1 : (wp->w_cursor.lnum == lnum && wp->w_cursor.col == 0))) {
                ++wp->w_cursor.lnum;
                save_curwin = curwin;
                curwin = wp;
                curbuf = curwin->w_buffer;
                scroll_cursor_bot (0, FALSE);
                curwin = save_curwin;
                curbuf = curwin->w_buffer;
            }
        }
        redraw_buf_and_status_later (buffer, VALID);
        channel_need_redraw = TRUE;
    }
    if (save_write_to) {
        channel_T *ch;
        buffer->b_write_to_channel = TRUE;
        for (ch = first_channel; ch != NULL; ch = ch->ch_next) {
            chanpart_T *in_part = &ch->ch_part[PART_IN];
            if (in_part->ch_bufref.br_buf == buffer)
                in_part->ch_buf_bot = buffer->b_ml.ml_line_count;
        }
    }
}

void clear_job_options (jobopt_T *opt) {
    vim_memset (opt, 0, sizeof (jobopt_T));
}

int get_job_options (typval_T *tv, jobopt_T *opt, int supported, int supported2) {
    typval_T *item;
    char_u *val;
    dict_T *dict;
    int todo;
    hashitem_T *hi;
    ch_part_T part;
    if (tv->v_type == VAR_UNKNOWN)
        return OK;
    if (tv->v_type != VAR_DICT) {
        EMSG (_ (e_dictreq));
        return FAIL;
    }
    dict = tv->vval.v_dict;
    if (dict == NULL)
        return OK;
    todo = (int) dict->dv_hashtab.ht_used;
    for (hi = dict->dv_hashtab.ht_array; todo > 0; ++hi)
        if (!HASHITEM_EMPTY (hi)) {
            item = &dict_lookup (hi)->di_tv;
            if (STRCMP (hi->hi_key, "mode") == 0) {
                if (!(supported & JO_MODE))
                    break;
                if (handle_mode (item, opt, &opt->jo_mode, JO_MODE) == FAIL)
                    return FAIL;
            }
            else if (STRCMP (hi->hi_key, "in_mode") == 0) {
                if (!(supported & JO_IN_MODE))
                    break;
                if (handle_mode (item, opt, &opt->jo_in_mode, JO_IN_MODE) == FAIL)
                    return FAIL;
            }
            else if (STRCMP (hi->hi_key, "out_mode") == 0) {
                if (!(supported & JO_OUT_MODE))
                    break;
                if (handle_mode (item, opt, &opt->jo_out_mode, JO_OUT_MODE) == FAIL)
                    return FAIL;
            }
            else if (STRCMP (hi->hi_key, "err_mode") == 0) {
                if (!(supported & JO_ERR_MODE))
                    break;
                if (handle_mode (item, opt, &opt->jo_err_mode, JO_ERR_MODE) == FAIL)
                    return FAIL;
            }
            else if (STRCMP (hi->hi_key, "in_io") == 0 || STRCMP (hi->hi_key, "out_io") == 0 || STRCMP (hi->hi_key, "err_io") == 0) {
                if (!(supported & JO_OUT_IO))
                    break;
                if (handle_io (item, part_from_char (*hi->hi_key), opt) == FAIL)
                    return FAIL;
            }
            else if (STRCMP (hi->hi_key, "in_name") == 0 || STRCMP (hi->hi_key, "out_name") == 0 || STRCMP (hi->hi_key, "err_name") == 0) {
                part = part_from_char (*hi->hi_key);
                if (!(supported & JO_OUT_IO))
                    break;
                opt->jo_set |= JO_OUT_NAME << (part - PART_OUT);
                opt->jo_io_name[part] = get_tv_string_buf_chk (item, opt->jo_io_name_buf[part]);
            }
            else if (STRCMP (hi->hi_key, "pty") == 0) {
                if (!(supported & JO_MODE))
                    break;
                opt->jo_pty = get_tv_number (item);
            }
            else if (STRCMP (hi->hi_key, "in_buf") == 0 || STRCMP (hi->hi_key, "out_buf") == 0 || STRCMP (hi->hi_key, "err_buf") == 0) {
                part = part_from_char (*hi->hi_key);
                if (!(supported & JO_OUT_IO))
                    break;
                opt->jo_set |= JO_OUT_BUF << (part - PART_OUT);
                opt->jo_io_buf[part] = get_tv_number (item);
                if (opt->jo_io_buf[part] <= 0) {
                    EMSG3 (_ (e_invargNval), hi -> hi_key, get_tv_string (item));
                    return FAIL;
                }
                if (buflist_findnr (opt->jo_io_buf[part]) == NULL) {
                    EMSGN (_ (e_nobufnr), (long) opt -> jo_io_buf [part]);
                    return FAIL;
                }
            }
            else if (STRCMP (hi->hi_key, "out_modifiable") == 0 || STRCMP (hi->hi_key, "err_modifiable") == 0) {
                part = part_from_char (*hi->hi_key);
                if (!(supported & JO_OUT_IO))
                    break;
                opt->jo_set |= JO_OUT_MODIFIABLE << (part - PART_OUT);
                opt->jo_modifiable[part] = get_tv_number (item);
            }
            else if (STRCMP (hi->hi_key, "out_msg") == 0 || STRCMP (hi->hi_key, "err_msg") == 0) {
                part = part_from_char (*hi->hi_key);
                if (!(supported & JO_OUT_IO))
                    break;
                opt->jo_set2 |= JO2_OUT_MSG << (part - PART_OUT);
                opt->jo_message[part] = get_tv_number (item);
            }
            else if (STRCMP (hi->hi_key, "in_top") == 0 || STRCMP (hi->hi_key, "in_bot") == 0) {
                linenr_T *lp;
                if (!(supported & JO_OUT_IO))
                    break;
                if (hi->hi_key[3] == 't') {
                    lp = &opt->jo_in_top;
                    opt->jo_set |= JO_IN_TOP;
                }
                else {
                    lp = &opt->jo_in_bot;
                    opt->jo_set |= JO_IN_BOT;
                }
                *lp = get_tv_number (item);
                if (*lp < 0) {
                    EMSG3 (_ (e_invargNval), hi -> hi_key, get_tv_string (item));
                    return FAIL;
                }
            }
            else if (STRCMP (hi->hi_key, "channel") == 0) {
                if (!(supported & JO_OUT_IO))
                    break;
                opt->jo_set |= JO_CHANNEL;
                if (item->v_type != VAR_CHANNEL) {
                    EMSG2 (_ (e_invargval), "channel");
                    return FAIL;
                }
                opt->jo_channel = item->vval.v_channel;
            }
            else if (STRCMP (hi->hi_key, "callback") == 0) {
                if (!(supported & JO_CALLBACK))
                    break;
                opt->jo_set |= JO_CALLBACK;
                opt->jo_callback = get_callback (item, &opt->jo_partial);
                if (opt->jo_callback == NULL) {
                    EMSG2 (_ (e_invargval), "callback");
                    return FAIL;
                }
            }
            else if (STRCMP (hi->hi_key, "out_cb") == 0) {
                if (!(supported & JO_OUT_CALLBACK))
                    break;
                opt->jo_set |= JO_OUT_CALLBACK;
                opt->jo_out_cb = get_callback (item, &opt->jo_out_partial);
                if (opt->jo_out_cb == NULL) {
                    EMSG2 (_ (e_invargval), "out_cb");
                    return FAIL;
                }
            }
            else if (STRCMP (hi->hi_key, "err_cb") == 0) {
                if (!(supported & JO_ERR_CALLBACK))
                    break;
                opt->jo_set |= JO_ERR_CALLBACK;
                opt->jo_err_cb = get_callback (item, &opt->jo_err_partial);
                if (opt->jo_err_cb == NULL) {
                    EMSG2 (_ (e_invargval), "err_cb");
                    return FAIL;
                }
            }
            else if (STRCMP (hi->hi_key, "close_cb") == 0) {
                if (!(supported & JO_CLOSE_CALLBACK))
                    break;
                opt->jo_set |= JO_CLOSE_CALLBACK;
                opt->jo_close_cb = get_callback (item, &opt->jo_close_partial);
                if (opt->jo_close_cb == NULL) {
                    EMSG2 (_ (e_invargval), "close_cb");
                    return FAIL;
                }
            }
            else if (STRCMP (hi->hi_key, "drop") == 0) {
                int never = FALSE;
                val = get_tv_string (item);
                if (STRCMP (val, "never") == 0)
                    never = TRUE;
                else if (STRCMP (val, "auto") != 0) {
                    EMSG3 (_ (e_invargNval), "drop", val);
                    return FAIL;
                }
                opt->jo_drop_never = never;
            }
            else if (STRCMP (hi->hi_key, "exit_cb") == 0) {
                if (!(supported & JO_EXIT_CB))
                    break;
                opt->jo_set |= JO_EXIT_CB;
                opt->jo_exit_cb = get_callback (item, &opt->jo_exit_partial);
                if (opt->jo_exit_cb == NULL) {
                    EMSG2 (_ (e_invargval), "exit_cb");
                    return FAIL;
                }
            }
            else if (STRCMP (hi->hi_key, "term_name") == 0) {
                if (!(supported2 & JO2_TERM_NAME))
                    break;
                opt->jo_set2 |= JO2_TERM_NAME;
                opt->jo_term_name = get_tv_string_chk (item);
                if (opt->jo_term_name == NULL) {
                    EMSG2 (_ (e_invargval), "term_name");
                    return FAIL;
                }
            }
            else if (STRCMP (hi->hi_key, "term_finish") == 0) {
                if (!(supported2 & JO2_TERM_FINISH))
                    break;
                val = get_tv_string (item);
                if (STRCMP (val, "open") != 0 && STRCMP (val, "close") != 0) {
                    EMSG3 (_ (e_invargNval), "term_finish", val);
                    return FAIL;
                }
                opt->jo_set2 |= JO2_TERM_FINISH;
                opt->jo_term_finish = *val;
            }
            else if (STRCMP (hi->hi_key, "term_opencmd") == 0) {
                char_u *p;
                if (!(supported2 & JO2_TERM_OPENCMD))
                    break;
                opt->jo_set2 |= JO2_TERM_OPENCMD;
                p = opt->jo_term_opencmd = get_tv_string_chk (item);
                if (p != NULL) {
                    p = vim_strchr (p, '%');
                    if (p != NULL && (p[1] != 'd' || vim_strchr (p +2, '%') != NULL))
                        p = NULL;
                }
                if (p == NULL) {
                    EMSG2 (_ (e_invargval), "term_opencmd");
                    return FAIL;
                }
            }
            else if (STRCMP (hi->hi_key, "eof_chars") == 0) {
                char_u *p;
                if (!(supported2 & JO2_EOF_CHARS))
                    break;
                opt->jo_set2 |= JO2_EOF_CHARS;
                p = opt->jo_eof_chars = get_tv_string_chk (item);
                if (p == NULL) {
                    EMSG2 (_ (e_invargval), "eof_chars");
                    return FAIL;
                }
            }
            else if (STRCMP (hi->hi_key, "term_rows") == 0) {
                if (!(supported2 & JO2_TERM_ROWS))
                    break;
                opt->jo_set |= JO2_TERM_ROWS;
                opt->jo_term_rows = get_tv_number (item);
            }
            else if (STRCMP (hi->hi_key, "term_cols") == 0) {
                if (!(supported2 & JO2_TERM_COLS))
                    break;
                opt->jo_set |= JO2_TERM_COLS;
                opt->jo_term_cols = get_tv_number (item);
            }
            else if (STRCMP (hi->hi_key, "vertical") == 0) {
                if (!(supported2 & JO2_VERTICAL))
                    break;
                opt->jo_set |= JO2_VERTICAL;
                opt->jo_vertical = get_tv_number (item);
            }
            else if (STRCMP (hi->hi_key, "curwin") == 0) {
                if (!(supported2 & JO2_CURWIN))
                    break;
                opt->jo_set |= JO2_CURWIN;
                opt->jo_curwin = get_tv_number (item);
            }
            else if (STRCMP (hi->hi_key, "hidden") == 0) {
                if (!(supported2 & JO2_HIDDEN))
                    break;
                opt->jo_set |= JO2_HIDDEN;
                opt->jo_hidden = get_tv_number (item);
            }
            else if (STRCMP (hi->hi_key, "env") == 0) {
                if (!(supported2 & JO2_ENV))
                    break;
                opt->jo_set |= JO2_ENV;
                opt->jo_env = item->vval.v_dict;
                ++item->vval.v_dict->dv_refcount;
            }
            else if (STRCMP (hi->hi_key, "cwd") == 0) {
                if (!(supported2 & JO2_CWD))
                    break;
                opt->jo_cwd = get_tv_string_buf_chk (item, opt->jo_cwd_buf);
                if (opt->jo_cwd == NULL || !mch_isdir (opt->jo_cwd)) {
                    EMSG2 (_ (e_invargval), "cwd");
                    return FAIL;
                }
                opt->jo_set |= JO2_CWD;
            }
            else if (STRCMP (hi->hi_key, "waittime") == 0) {
                if (!(supported & JO_WAITTIME))
                    break;
                opt->jo_set |= JO_WAITTIME;
                opt->jo_waittime = get_tv_number (item);
            }
            else if (STRCMP (hi->hi_key, "timeout") == 0) {
                if (!(supported & JO_TIMEOUT))
                    break;
                opt->jo_set |= JO_TIMEOUT;
                opt->jo_timeout = get_tv_number (item);
            }
            else if (STRCMP (hi->hi_key, "out_timeout") == 0) {
                if (!(supported & JO_OUT_TIMEOUT))
                    break;
                opt->jo_set |= JO_OUT_TIMEOUT;
                opt->jo_out_timeout = get_tv_number (item);
            }
            else if (STRCMP (hi->hi_key, "err_timeout") == 0) {
                if (!(supported & JO_ERR_TIMEOUT))
                    break;
                opt->jo_set |= JO_ERR_TIMEOUT;
                opt->jo_err_timeout = get_tv_number (item);
            }
            else if (STRCMP (hi->hi_key, "part") == 0) {
                if (!(supported & JO_PART))
                    break;
                opt->jo_set |= JO_PART;
                val = get_tv_string (item);
                if (STRCMP (val, "err") == 0)
                    opt->jo_part = PART_ERR;
                else if (STRCMP (val, "out") == 0)
                    opt->jo_part = PART_OUT;
                else {
                    EMSG3 (_ (e_invargNval), "part", val);
                    return FAIL;
                }
            }
            else if (STRCMP (hi->hi_key, "id") == 0) {
                if (!(supported & JO_ID))
                    break;
                opt->jo_set |= JO_ID;
                opt->jo_id = get_tv_number (item);
            }
            else if (STRCMP (hi->hi_key, "stoponexit") == 0) {
                if (!(supported & JO_STOPONEXIT))
                    break;
                opt->jo_set |= JO_STOPONEXIT;
                opt->jo_stoponexit = get_tv_string_buf_chk (item, opt->jo_soe_buf);
                if (opt->jo_stoponexit == NULL) {
                    EMSG2 (_ (e_invargval), "stoponexit");
                    return FAIL;
                }
            }
            else if (STRCMP (hi->hi_key, "block_write") == 0) {
                if (!(supported & JO_BLOCK_WRITE))
                    break;
                opt->jo_set |= JO_BLOCK_WRITE;
                opt->jo_block_write = get_tv_number (item);
            }
            else
                break;
            --todo;
        }
    if (todo > 0) {
        EMSG2 (_ (e_invarg2), hi -> hi_key);
        return FAIL;
    }
    return OK;
}

static int handle_mode (typval_T *item, jobopt_T *opt, ch_mode_T *modep, int jo) {
    char_u *val = get_tv_string (item);
    opt->jo_set |= jo;
    if (STRCMP (val, "nl") == 0)
        *modep = MODE_NL;
    else if (STRCMP (val, "raw") == 0)
        *modep = MODE_RAW;
    else if (STRCMP (val, "js") == 0)
        *modep = MODE_JS;
    else if (STRCMP (val, "json") == 0)
        *modep = MODE_JSON;
    else {
        EMSG2 (_ (e_invarg2), val);
        return FAIL;
    }
    return OK;
}

static int handle_io (typval_T *item, ch_part_T part, jobopt_T *opt) {
    char_u *val = get_tv_string (item);
    opt->jo_set |= JO_OUT_IO << (part - PART_OUT);
    if (STRCMP (val, "null") == 0)
        opt->jo_io[part] = JIO_NULL;
    else if (STRCMP (val, "pipe") == 0)
        opt->jo_io[part] = JIO_PIPE;
    else if (STRCMP (val, "file") == 0)
        opt->jo_io[part] = JIO_FILE;
    else if (STRCMP (val, "buffer") == 0)
        opt->jo_io[part] = JIO_BUFFER;
    else if (STRCMP (val, "out") == 0 && part == PART_ERR)
        opt->jo_io[part] = JIO_OUT;
    else {
        EMSG2 (_ (e_invarg2), val);
        return FAIL;
    }
    return OK;
}

static int part_from_char (int c) {
    return c == 'i' ? PART_IN : c == 'o' ? PART_OUT : PART_ERR;
}

job_T *job_alloc (void) {
    job_T *job;
    job = (job_T *) alloc_clear (sizeof (job_T));
    if (job != NULL) {
        job->jv_refcount = 1;
        job->jv_stoponexit = vim_strsave ((char_u *) "term");
        if (first_job != NULL) {
            first_job->jv_prev = job;
            job->jv_next = first_job;
        }
        first_job = job;
    }
    return job;
}

channel_T *add_channel (void) {
    ch_part_T part;
    channel_T *channel = (channel_T *) alloc_clear ((int) sizeof (channel_T));
    if (channel == NULL)
        return NULL;
    channel->ch_id = next_ch_id++;
    ch_log (channel, "Created channel");
    for (part = PART_SOCK; part < PART_COUNT; ++part) {
        channel->ch_part[part].ch_fd = INVALID_FD;
        channel->ch_part[part].ch_inputHandler = 0;
        channel->ch_part[part].ch_timeout = 2000;
    }
    if (first_channel != NULL) {
        first_channel->ch_prev = channel;
        channel->ch_next = first_channel;
    }
    first_channel = channel;
    channel->ch_refcount = 1;
    return channel;
}

void channel_set_pipes (channel_T *channel, sock_T in, sock_T out, sock_T err) {
    if (in != INVALID_FD) {
        ch_close_part (channel, PART_IN);
        channel->CH_IN_FD = in;
    }
    if (out != INVALID_FD) {
        channel_gui_unregister_one (channel, PART_OUT);
        ch_close_part (channel, PART_OUT);
        channel->CH_OUT_FD = out;
        channel->ch_to_be_closed |= (1 << PART_OUT);
        channel_gui_register_one (channel, PART_OUT);
    }
    if (err != INVALID_FD) {
        channel_gui_unregister_one (channel, PART_ERR);
        ch_close_part (channel, PART_ERR);
        channel->CH_ERR_FD = err;
        channel->ch_to_be_closed |= (1 << PART_ERR);
        channel_gui_register_one (channel, PART_ERR);
    }
}

static void channel_gui_register_one (channel_T *channel, ch_part_T part) {
    if (!CH_HAS_GUI)
        return;
    if (channel->ch_keep_open)
        return;
    if (channel->ch_part[part].ch_inputHandler == 0)
        channel->ch_part[part].ch_inputHandler = gui_macvim_add_channel (channel, part);
}

void channel_set_job (channel_T *channel, job_T *job, jobopt_T *options) {
    channel->ch_job = job;
    channel_set_options (channel, options);
    if (job->jv_in_buf != NULL) {
        chanpart_T *in_part = &channel->ch_part[PART_IN];
        set_bufref (& in_part -> ch_bufref, job -> jv_in_buf);
        ch_log (channel, "reading from buffer '%s'", (char *) in_part -> ch_bufref.br_buf -> b_ffname);
        if (options->jo_set & JO_IN_TOP) {
            if (options->jo_in_top == 0 && !(options->jo_set & JO_IN_BOT)) {
                in_part->ch_bufref.br_buf->b_write_to_channel = TRUE;
                in_part->ch_buf_append = TRUE;
                in_part->ch_buf_top = in_part->ch_bufref.br_buf->b_ml.ml_line_count + 1;
            }
            else
                in_part->ch_buf_top = options->jo_in_top;
        }
        else
            in_part->ch_buf_top = 1;
        if (options->jo_set & JO_IN_BOT)
            in_part->ch_buf_bot = options->jo_in_bot;
        else
            in_part->ch_buf_bot = in_part->ch_bufref.br_buf->b_ml.ml_line_count;
    }
}

void channel_set_options (channel_T *channel, jobopt_T *opt) {
    ch_part_T part;
    if (opt->jo_set & JO_MODE)
        for (part = PART_SOCK; part < PART_COUNT; ++part)
            channel->ch_part[part].ch_mode = opt->jo_mode;
    if (opt->jo_set & JO_IN_MODE)
        channel->ch_part[PART_IN].ch_mode = opt->jo_in_mode;
    if (opt->jo_set & JO_OUT_MODE)
        channel->ch_part[PART_OUT].ch_mode = opt->jo_out_mode;
    if (opt->jo_set & JO_ERR_MODE)
        channel->ch_part[PART_ERR].ch_mode = opt->jo_err_mode;
    if (opt->jo_set & JO_TIMEOUT)
        for (part = PART_SOCK; part < PART_COUNT; ++part)
            channel->ch_part[part].ch_timeout = opt->jo_timeout;
    if (opt->jo_set & JO_OUT_TIMEOUT)
        channel->ch_part[PART_OUT].ch_timeout = opt->jo_out_timeout;
    if (opt->jo_set & JO_ERR_TIMEOUT)
        channel->ch_part[PART_ERR].ch_timeout = opt->jo_err_timeout;
    if (opt->jo_set & JO_BLOCK_WRITE)
        channel->ch_part[PART_IN].ch_block_write = 1;
    if (opt->jo_set & JO_CALLBACK)
        set_callback (&channel->ch_callback, &channel->ch_partial, opt->jo_callback, opt->jo_partial);
    if (opt->jo_set & JO_OUT_CALLBACK)
        set_callback (&channel->ch_part[PART_OUT].ch_callback, &channel->ch_part[PART_OUT].ch_partial, opt->jo_out_cb, opt->jo_out_partial);
    if (opt->jo_set & JO_ERR_CALLBACK)
        set_callback (&channel->ch_part[PART_ERR].ch_callback, &channel->ch_part[PART_ERR].ch_partial, opt->jo_err_cb, opt->jo_err_partial);
    if (opt->jo_set & JO_CLOSE_CALLBACK)
        set_callback (&channel->ch_close_cb, &channel->ch_close_partial, opt->jo_close_cb, opt->jo_close_partial);
    channel->ch_drop_never = opt->jo_drop_never;
    if ((opt->jo_set & JO_OUT_IO) && opt->jo_io[PART_OUT] == JIO_BUFFER) {
        buf_T *buf;
        if (!(opt->jo_set & JO_OUT_MODE))
            channel->ch_part[PART_OUT].ch_mode = MODE_NL;
        if (opt->jo_set & JO_OUT_BUF) {
            buf = buflist_findnr (opt->jo_io_buf[PART_OUT]);
            if (buf == NULL)
                EMSGN (_ (e_nobufnr), (long ) opt->jo_io_buf[PART_OUT]);
        }
        else {
            int msg = TRUE;
            if (opt->jo_set2 & JO2_OUT_MSG)
                msg = opt->jo_message[PART_OUT];
            buf = find_buffer (opt->jo_io_name[PART_OUT], FALSE, msg);
        }
        if (buf != NULL) {
            if (opt->jo_set & JO_OUT_MODIFIABLE)
                channel->ch_part[PART_OUT].ch_nomodifiable = !opt->jo_modifiable[PART_OUT];
            if (!buf->b_p_ma && !channel->ch_part[PART_OUT].ch_nomodifiable) {
                EMSG (_ (e_modifiable));
            }
            else {
                ch_log (channel, "writing out to buffer '%s'", (char *) buf -> b_ffname);
                set_bufref (& channel -> ch_part [PART_OUT].ch_bufref, buf);
            }
        }
    }
    if ((opt->jo_set & JO_ERR_IO) && (opt->jo_io[PART_ERR] == JIO_BUFFER || (opt->jo_io[PART_ERR] == JIO_OUT && (opt->jo_set & JO_OUT_IO) && opt->jo_io[PART_OUT] == JIO_BUFFER))) {
        buf_T *buf;
        if (!(opt->jo_set & JO_ERR_MODE))
            channel->ch_part[PART_ERR].ch_mode = MODE_NL;
        if (opt->jo_io[PART_ERR] == JIO_OUT)
            buf = channel->ch_part[PART_OUT].ch_bufref.br_buf;
        else if (opt->jo_set & JO_ERR_BUF) {
            buf = buflist_findnr (opt->jo_io_buf[PART_ERR]);
            if (buf == NULL)
                EMSGN (_ (e_nobufnr), (long ) opt->jo_io_buf[PART_ERR]);
        }
        else {
            int msg = TRUE;
            if (opt->jo_set2 & JO2_ERR_MSG)
                msg = opt->jo_message[PART_ERR];
            buf = find_buffer (opt->jo_io_name[PART_ERR], TRUE, msg);
        }
        if (buf != NULL) {
            if (opt->jo_set & JO_ERR_MODIFIABLE)
                channel->ch_part[PART_ERR].ch_nomodifiable = !opt->jo_modifiable[PART_ERR];
            if (!buf->b_p_ma && !channel->ch_part[PART_ERR].ch_nomodifiable) {
                EMSG (_ (e_modifiable));
            }
            else {
                ch_log (channel, "writing err to buffer '%s'", (char *) buf -> b_ffname);
                set_bufref (& channel -> ch_part [PART_ERR].ch_bufref, buf);
            }
        }
    }
    channel->ch_part[PART_OUT].ch_io = opt->jo_io[PART_OUT];
    channel->ch_part[PART_ERR].ch_io = opt->jo_io[PART_ERR];
    channel->ch_part[PART_IN].ch_io = opt->jo_io[PART_IN];
}

static void set_callback (char_u **cbp, partial_T **pp, char_u *callback, partial_T *partial) {
    free_callback (* cbp, * pp);
    if (callback != NULL && *callback != NUL) {
        if (partial != NULL)
            *cbp = partial_name (partial);
        else {
            *cbp = vim_strsave (callback);
            func_ref (*cbp);
        }
    }
    else
        *cbp = NULL;
    *pp = partial;
    if (partial != NULL)
        ++partial->pt_refcount;
}

static buf_T *find_buffer (char_u *name, int err, int msg) {
    buf_T *buf = NULL;
    buf_T *save_curbuf = curbuf;
    if (name != NULL && *name != NUL) {
        buf = buflist_findname (name);
        if (buf == NULL)
            buf = buflist_findname_exp (name);
    }
    if (buf == NULL) {
        buf = buflist_new (name == NULL || *name == NUL ? NULL : name, NULL, (linenr_T) 0, BLN_LISTED | BLN_NEW);
        if (buf == NULL)
            return NULL;
        buf_copy_options (buf, BCO_ENTER);
        curbuf = buf;
        set_option_value ((char_u *) "bt", 0L, (char_u *) "nofile", OPT_LOCAL);
        set_option_value ((char_u *) "bh", 0L, (char_u *) "hide", OPT_LOCAL);
        if (curbuf->b_ml.ml_mfp == NULL)
            ml_open (curbuf);
        if (msg)
            ml_replace (1, (char_u *) (err ? "Reading from channel error..." : "Reading from channel output..."), TRUE);
        changed_bytes (1, 0);
        curbuf = save_curbuf;
    }
    return buf;
}

job_T *job_start (typval_T *argvars, jobopt_T *opt_arg) {
    job_T *job;
    char_u *cmd = NULL;

    # define USE_ARGV
    char **argv = NULL;
    int argc = 0;
    jobopt_T opt;
    ch_part_T part;
    job = job_alloc ();
    if (job == NULL)
        return NULL;
    job->jv_status = JOB_FAILED;
    ga_init2 (& ga, (int) sizeof (char *), 20);
    if (opt_arg != NULL)
        opt = *opt_arg;
    else {
        clear_job_options (& opt);
        opt.jo_mode = MODE_NL;
        if (get_job_options (&argvars[1], &opt, JO_MODE_ALL +JO_CB_ALL + JO_TIMEOUT_ALL + JO_STOPONEXIT + JO_EXIT_CB + JO_OUT_IO + JO_BLOCK_WRITE, JO2_ENV +JO2_CWD) == FAIL)
            goto theend;
    }
    for (part = PART_OUT; part < PART_COUNT; ++part)
        if ((opt.jo_set & (JO_OUT_IO << (part - PART_OUT))) && opt.jo_io[part] == JIO_FILE && (!(opt.jo_set & (JO_OUT_NAME << (part - PART_OUT))) || *opt.jo_io_name[part] == NUL)) {
            EMSG (_ ("E920: _io file requires _name to be set"));
            goto theend;
        }
    if ((opt.jo_set & JO_IN_IO) && opt.jo_io[PART_IN] == JIO_BUFFER) {
        buf_T *buf = NULL;
        if (opt.jo_set & JO_IN_BUF) {
            buf = buflist_findnr (opt.jo_io_buf[PART_IN]);
            if (buf == NULL)
                EMSGN (_ (e_nobufnr), (long ) opt.jo_io_buf[PART_IN]);
        }
        else if (!(opt.jo_set & JO_IN_NAME)) {
            EMSG (_ ("E915: in_io buffer requires in_buf or in_name to be set"));
        }
        else
            buf = buflist_find_by_name (opt.jo_io_name[PART_IN], FALSE);
        if (buf == NULL)
            goto theend;
        if (buf->b_ml.ml_mfp == NULL) {
            char_u numbuf [NUMBUFLEN];
            char_u *s;
            if (opt.jo_set & JO_IN_BUF) {
                sprintf ((char *) numbuf, "%d", opt.jo_io_buf [PART_IN]);
                s = numbuf;
            }
            else
                s = opt.jo_io_name[PART_IN];
            EMSG2 (_ ("E918: buffer must be loaded: %s"), s);
            goto theend;
        }
        job->jv_in_buf = buf;
    }
    job_set_options (job, & opt);
    if (argvars[0].v_type == VAR_STRING) {
        cmd = argvars[0].vval.v_string;
        if (cmd == NULL || *cmd == NUL) {
            EMSG (_ (e_invarg));
            goto theend;
        }
    }
    else if (argvars[0].v_type != VAR_LIST || argvars[0].vval.v_list == NULL || argvars[0].vval.v_list->lv_len < 1) {
        EMSG (_ (e_invarg));
        goto theend;
    }
    else {
        list_T *l = argvars[0].vval.v_list;
        if (win32_build_cmd (l, &ga) == FAIL)
            goto theend;
        cmd = ga.ga_data;
    }
    ch_log (NULL, "Starting job: %s", (char *) cmd);
    mch_job_start ((char *) cmd, job, & opt);
    if (job->jv_channel != NULL)
        channel_write_in (job->jv_channel);
theend :
    vim_free (ga.ga_data);
    free_job_options (& opt);
    return job;
}

void job_set_options (job_T *job, jobopt_T *opt) {
    if (opt->jo_set & JO_STOPONEXIT) {
        vim_free (job -> jv_stoponexit);
        if (opt->jo_stoponexit == NULL || *opt->jo_stoponexit == NUL)
            job->jv_stoponexit = NULL;
        else
            job->jv_stoponexit = vim_strsave (opt->jo_stoponexit);
    }
    if (opt->jo_set & JO_EXIT_CB) {
        free_callback (job -> jv_exit_cb, job -> jv_exit_partial);
        if (opt->jo_exit_cb == NULL || *opt->jo_exit_cb == NUL) {
            job->jv_exit_cb = NULL;
            job->jv_exit_partial = NULL;
        }
        else {
            job->jv_exit_partial = opt->jo_exit_partial;
            if (job->jv_exit_partial != NULL) {
                job->jv_exit_cb = opt->jo_exit_cb;
                ++job->jv_exit_partial->pt_refcount;
            }
            else {
                job->jv_exit_cb = vim_strsave (opt->jo_exit_cb);
                func_ref (job -> jv_exit_cb);
            }
        }
    }
}

void free_job_options (jobopt_T *opt) {
    if (opt->jo_partial != NULL)
        partial_unref (opt->jo_partial);
    else if (opt->jo_callback != NULL)
        func_unref (opt->jo_callback);
    if (opt->jo_out_partial != NULL)
        partial_unref (opt->jo_out_partial);
    else if (opt->jo_out_cb != NULL)
        func_unref (opt->jo_out_cb);
    if (opt->jo_err_partial != NULL)
        partial_unref (opt->jo_err_partial);
    else if (opt->jo_err_cb != NULL)
        func_unref (opt->jo_err_cb);
    if (opt->jo_close_partial != NULL)
        partial_unref (opt->jo_close_partial);
    else if (opt->jo_close_cb != NULL)
        func_unref (opt->jo_close_cb);
    if (opt->jo_exit_partial != NULL)
        partial_unref (opt->jo_exit_partial);
    else if (opt->jo_exit_cb != NULL)
        func_unref (opt->jo_exit_cb);
    if (opt->jo_env != NULL)
        dict_unref (opt->jo_env);
}

void channel_set_nonblock (channel_T *channel, ch_part_T part) {
    chanpart_T *ch_part = &channel->ch_part[part];
    int fd = ch_part->ch_fd;
    if (fd != INVALID_FD) {
        (void) fcntl (fd, F_SETFL, O_NONBLOCK);
        ch_part->ch_nonblocking = TRUE;
    }
}

char *job_status (job_T *job) {
    char *result;
    if (job->jv_status >= JOB_ENDED)
        result = "dead";
    else if (job->jv_status == JOB_FAILED)
        result = "fail";
    else {
        result = mch_job_status (job);
        if (job->jv_status == JOB_ENDED)
            job_cleanup (job);
    }
    return result;
}

channel_T *get_channel_arg (typval_T *tv, int check_open, int reading, ch_part_T part) {
    channel_T *channel = NULL;
    int has_readahead = FALSE;
    if (tv->v_type == VAR_JOB) {
        if (tv->vval.v_job != NULL)
            channel = tv->vval.v_job->jv_channel;
    }
    else if (tv->v_type == VAR_CHANNEL) {
        channel = tv->vval.v_channel;
    }
    else {
        EMSG2 (_ (e_invarg2), get_tv_string (tv));
        return NULL;
    }
    if (channel != NULL && reading)
        has_readahead = channel_has_readahead (channel, part != PART_COUNT ? part : channel_part_read (channel));
    if (check_open && (channel == NULL || (!channel_is_open (channel) && !(reading && has_readahead)))) {
        EMSG (_ ("E906: not an open channel"));
        return NULL;
    }
    return channel;
}

ch_part_T channel_part_read (channel_T *channel) {
    if (channel->CH_SOCK_FD == INVALID_FD)
        return PART_OUT;
    return PART_SOCK;
}

void channel_close_in (channel_T *channel) {
    ch_close_part (channel, PART_IN);
}

void channel_info (channel_T *channel, dict_T *dict) {
    dict_add_nr_str (dict, "id", channel -> ch_id, NULL);
    dict_add_nr_str (dict, "status", 0, (char_u *) channel_status (channel, - 1));
    if (channel->ch_hostname != NULL) {
        dict_add_nr_str (dict, "hostname", 0, (char_u *) channel -> ch_hostname);
        dict_add_nr_str (dict, "port", channel -> ch_port, NULL);
        channel_part_info (channel, dict, "sock", PART_SOCK);
    }
    else {
        channel_part_info (channel, dict, "out", PART_OUT);
        channel_part_info (channel, dict, "err", PART_ERR);
        channel_part_info (channel, dict, "in", PART_IN);
    }
}

static void channel_part_info (channel_T *channel, dict_T *dict, char *name, ch_part_T part) {
    chanpart_T *chanpart = &channel->ch_part[part];
    char namebuf [20];
    size_t tail;
    char *status;
    char *s = "";
    vim_strncpy ((char_u *) namebuf, (char_u *) name, 4);
    STRCAT (namebuf, "_");
    tail = STRLEN (namebuf);
    STRCPY (namebuf + tail, "status");
    if (chanpart->ch_fd != INVALID_FD)
        status = "open";
    else if (channel_has_readahead (channel, part))
        status = "buffered";
    else
        status = "closed";
    dict_add_nr_str (dict, namebuf, 0, (char_u *) status);
    STRCPY (namebuf + tail, "mode");
    switch (chanpart->ch_mode) {
    case MODE_NL :
        s = "NL";
        break;
    case MODE_RAW :
        s = "RAW";
        break;
    case MODE_JSON :
        s = "JSON";
        break;
    case MODE_JS :
        s = "JS";
        break;
    }
    dict_add_nr_str (dict, namebuf, 0, (char_u *) s);
    STRCPY (namebuf + tail, "io");
    if (part == PART_SOCK)
        s = "socket";
    else
        switch (chanpart->ch_io) {
        case JIO_NULL :
            s = "null";
            break;
        case JIO_PIPE :
            s = "pipe";
            break;
        case JIO_FILE :
            s = "file";
            break;
        case JIO_BUFFER :
            s = "buffer";
            break;
        case JIO_OUT :
            s = "out";
            break;
        }
    dict_add_nr_str (dict, namebuf, 0, (char_u *) s);
    STRCPY (namebuf + tail, "timeout");
    dict_add_nr_str (dict, namebuf, chanpart -> ch_timeout, NULL);
}

void ch_logfile (char_u *fname, char_u *opt) {
    FILE *file = NULL;
    if (log_fd != NULL)
        fclose (log_fd);
    if (*fname != NUL) {
        file = fopen ((char *) fname, *opt == 'w' ? "w" : "a");
        if (file == NULL) {
            EMSG2 (_ (e_notopen), fname);
            return;
        }
    }
    log_fd = file;
    if (log_fd != NULL) {
        fprintf (log_fd, "==== start log session ====\n");
        profile_start (& log_start);
    }
}

channel_T *channel_open_func (typval_T *argvars) {
    char_u *address;
    char_u *p;
    char *rest;
    int port;
    jobopt_T opt;
    channel_T *channel = NULL;
    address = get_tv_string (&argvars[0]);
    if (argvars[1].v_type != VAR_UNKNOWN && (argvars[1].v_type != VAR_DICT || argvars[1].vval.v_dict == NULL)) {
        EMSG (_ (e_invarg));
        return NULL;
    }
    p = vim_strchr (address, ':');
    if (p == NULL) {
        EMSG2 (_ (e_invarg2), address);
        return NULL;
    }
    *p++ = NUL;
    port = strtol ((char *) p, &rest, 10);
    if (*address == NUL || port <= 0 || *rest != NUL) {
        p[-1] = ':';
        EMSG2 (_ (e_invarg2), address);
        return NULL;
    }
    clear_job_options (& opt);
    opt.jo_mode = MODE_JSON;
    opt.jo_timeout = 2000;
    if (get_job_options (&argvars[1], &opt, JO_MODE_ALL +JO_CB_ALL + JO_WAITTIME + JO_TIMEOUT_ALL, 0) == FAIL)
        goto theend;
    if (opt.jo_timeout < 0) {
        EMSG (_ (e_invarg));
        goto theend;
    }
    channel = channel_open ((char *) address, port, opt.jo_waittime, NULL);
    if (channel != NULL) {
        opt.jo_set = JO_ALL;
        channel_set_options (channel, & opt);
    }
theend :
    free_job_options (&opt);
    return channel;
}

channel_T *channel_open (char *hostname, int port_in, int waittime, void (*nb_close_cb) (void)) {
    int sd = -1;
    struct sockaddr_in server;
    struct hostent *host;
    int port = port_in;
    channel_T *channel;
    int ret;
    channel = add_channel ();
    if (channel == NULL) {
        ch_error (NULL, "Cannot allocate channel.");
        return NULL;
    }
    vim_memset ((char *) & server, 0, sizeof (server));
    server.sin_family = AF_INET;
    server.sin_port = htons (port);
    if ((host = gethostbyname (hostname)) == NULL) {
        ch_error (channel, "in gethostbyname() in channel_open()");
        PERROR (_ ("E901: gethostbyname() in channel_open()"));
        channel_free (channel);
        return NULL;
    }
    {
        char *p;
        memcpy (& p, & host -> h_addr, sizeof (p));
        memcpy ((char *) & server.sin_addr, p, host -> h_length);
    }
    if (waittime == 0)
        waittime = 1;
    while (TRUE) {
        long  elapsed_msec = 0;
        int waitnow;
        if (sd >= 0)
            sock_close (sd);
        sd = socket (AF_INET, SOCK_STREAM, 0);
        if (sd == -1) {
            ch_error (channel, "in socket() in channel_open().");
            PERROR (_ ("E898: socket() in channel_open()"));
            channel_free (channel);
            return NULL;
        }
        if (waittime >= 0) {
            if (fcntl (sd, F_SETFL, O_NONBLOCK) < 0) {
                SOCK_ERRNO;
                ch_error (channel, "channel_open: Connect failed with errno %d", errno);
                sock_close (sd);
                channel_free (channel);
                return NULL;
            }
        }
        ch_log (channel, "Connecting to %s port %d", hostname, port);
        ret = connect (sd, (struct sockaddr *) &server, sizeof (server));
        if (ret == 0)
            break;
        SOCK_ERRNO;
        if (waittime < 0 || (errno != EWOULDBLOCK && errno != ECONNREFUSED)) {
            ch_error (channel, "channel_open: Connect failed with errno %d", errno);
            PERROR (_ (e_cannot_connect));
            sock_close (sd);
            channel_free (channel);
            return NULL;
        }
        waitnow = waittime > 50 ? 50 : waittime;
        if (errno != ECONNREFUSED) {
            struct timeval tv;
            fd_set rfds;
            fd_set wfds;
            int so_error = 0;
            socklen_t so_error_len = sizeof (so_error);
            struct timeval start_tv;
            struct timeval end_tv;
            FD_ZERO (& rfds);
            FD_SET (sd, & rfds);
            FD_ZERO (& wfds);
            FD_SET (sd, & wfds);
            tv.tv_sec = waitnow / 1000;
            tv.tv_usec = (waitnow % 1000) * 1000;
            gettimeofday (& start_tv, NULL);
            ch_log (channel, "Waiting for connection (waiting %d msec)...", waitnow);
            ret = select ((int) sd + 1, &rfds, &wfds, NULL, &tv);
            if (ret < 0) {
                SOCK_ERRNO;
                ch_error (channel, "channel_open: Connect failed with errno %d", errno);
                PERROR (_ (e_cannot_connect));
                sock_close (sd);
                channel_free (channel);
                return NULL;
            }
            if (FD_ISSET (sd, &rfds) || FD_ISSET (sd, &wfds)) {
                ret = getsockopt (sd, SOL_SOCKET, SO_ERROR, &so_error, &so_error_len);
                if (ret < 0 || (so_error != 0 && so_error != EWOULDBLOCK && so_error != ECONNREFUSED)) {
                    ch_error (channel, "channel_open: Connect failed with errno %d", so_error);
                    PERROR (_ (e_cannot_connect));
                    sock_close (sd);
                    channel_free (channel);
                    return NULL;
                }
            }
            if (FD_ISSET (sd, &wfds) && so_error == 0)
                break;
            gettimeofday (& end_tv, NULL);
            elapsed_msec = (end_tv.tv_sec - start_tv.tv_sec) * 1000 + (end_tv.tv_usec - start_tv.tv_usec) / 1000;
        }
        if (waittime > 1 && elapsed_msec < waittime) {
            waitnow -= elapsed_msec;
            waittime -= elapsed_msec;
            if (waitnow > 0) {
                mch_delay ((long) waitnow, TRUE);
                ui_breakcheck ();
                waittime -= waitnow;
            }
            if (!got_int) {
                if (waittime <= 0)
                    waittime = 1;
                continue;
            }
        }
        ch_error (channel, "Connection timed out");
        sock_close (sd);
        channel_free (channel);
        return NULL;
    }
    ch_log (channel, "Connection made");
    if (waittime >= 0) {
        (void) fcntl (sd, F_SETFL, 0);
    }
    channel->CH_SOCK_FD = (sock_T) sd;
    channel->ch_nb_close_cb = nb_close_cb;
    channel->ch_hostname = (char *) vim_strsave ((char_u *) hostname);
    channel->ch_port = port_in;
    channel->ch_to_be_closed |= (1 << PART_SOCK);
    channel_gui_register_one (channel, PART_SOCK);
    return channel;
}

void common_channel_read (typval_T *argvars, typval_T *rettv, int raw) {
    channel_T *channel;
    ch_part_T part = PART_COUNT;
    jobopt_T opt;
    int mode;
    int timeout;
    int id = -1;
    typval_T *listtv = NULL;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    clear_job_options (& opt);
    if (get_job_options (&argvars[1], &opt, JO_TIMEOUT +JO_PART + JO_ID, 0) == FAIL)
        goto theend;
    if (opt.jo_set & JO_PART)
        part = opt.jo_part;
    channel = get_channel_arg (&argvars[0], TRUE, TRUE, part);
    if (channel != NULL) {
        if (part == PART_COUNT)
            part = channel_part_read (channel);
        mode = channel_get_mode (channel, part);
        timeout = channel_get_timeout (channel, part);
        if (opt.jo_set & JO_TIMEOUT)
            timeout = opt.jo_timeout;
        if (raw || mode == MODE_RAW || mode == MODE_NL)
            rettv->vval.v_string = channel_read_block (channel, part, timeout, raw);
        else {
            if (opt.jo_set & JO_ID)
                id = opt.jo_id;
            channel_read_json_block (channel, part, timeout, id, & listtv);
            if (listtv != NULL) {
                *rettv = *listtv;
                vim_free (listtv);
            }
            else {
                rettv->v_type = VAR_SPECIAL;
                rettv->vval.v_number = VVAL_NONE;
            }
        }
    }
theend :
    free_job_options (&opt);
}

ch_mode_T channel_get_mode (channel_T *channel, ch_part_T part) {
    if (channel == NULL)
        return MODE_JSON;
    return channel->ch_part[part].ch_mode;
}

int channel_get_timeout (channel_T *channel, ch_part_T part) {
    return channel->ch_part[part].ch_timeout;
}

static char_u *channel_read_block (channel_T *channel, ch_part_T part, int timeout, int raw) {
    char_u *buf;
    char_u *msg;
    ch_mode_T mode = channel->ch_part[part].ch_mode;
    sock_T fd = channel->ch_part[part].ch_fd;
    char_u *nl;
    readq_T *node;
    ch_log (channel, "Blocking %s read, timeout: %d msec", mode == MODE_RAW ? "RAW" : "NL", timeout);
    while (TRUE) {
        node = channel_peek (channel, part);
        if (node != NULL) {
            if (mode == MODE_RAW || (mode == MODE_NL && channel_first_nl (node) != NULL))
                break;
            if (channel_collapse (channel, part, mode == MODE_NL) == OK)
                continue;
            if (raw || fd == INVALID_FD)
                break;
        }
        if (fd == INVALID_FD)
            return NULL;
        if (channel_wait (channel, fd, timeout) != CW_READY) {
            ch_log (channel, "Timed out");
            return NULL;
        }
        channel_read (channel, part, "channel_read_block");
    }
    if (mode == MODE_RAW) {
        msg = channel_get_all (channel, part);
    }
    else {
        char_u *p;
        buf = node->rq_buffer;
        nl = channel_first_nl (node);
        for (p = buf; (nl == NULL || p < nl) && p < buf + node->rq_buflen; ++p)
            if (*p == NUL)
                *p = NL;
        if (nl == NULL) {
            msg = channel_get (channel, part);
        }
        else if (nl + 1 == buf + node->rq_buflen) {
            msg = channel_get (channel, part);
            *nl = NUL;
        }
        else {
            msg = vim_strnsave (buf, (int) (nl - buf));
            channel_consume (channel, part, (int) (nl - buf) + 1);
        }
    }
    if (ch_log_active ())
        ch_log (channel, "Returning %d bytes", (int) STRLEN (msg));
    return msg;
}

static int channel_read_json_block (channel_T *channel, ch_part_T part, int timeout_arg, int id, typval_T **rettv) {
    int more;
    sock_T fd;
    int timeout;
    chanpart_T *chanpart = &channel->ch_part[part];
    ch_log (channel, "Reading JSON");
    if (id != -1)
        chanpart->ch_block_id = id;
    for (;;) {
        more = channel_parse_json (channel, part);
        if (channel_get_json (channel, part, id, TRUE, rettv) == OK) {
            chanpart->ch_block_id = 0;
            return OK;
        }
        if (!more) {
            if (channel_parse_messages ())
                continue;
            timeout = timeout_arg;
            if (chanpart->ch_wait_len > 0) {
                {
                    struct timeval now_tv;
                    gettimeofday (& now_tv, NULL);
                    timeout = (chanpart->ch_deadline.tv_sec - now_tv.tv_sec) * 1000 + (chanpart->ch_deadline.tv_usec - now_tv.tv_usec) / 1000 + 1;
                }
                if (timeout < 0) {
                    chanpart->ch_wait_len = 0;
                    timeout = timeout_arg;
                }
                else if (timeout > timeout_arg)
                    timeout = timeout_arg;
            }
            fd = chanpart->ch_fd;
            if (fd == INVALID_FD || channel_wait (channel, fd, timeout) != CW_READY) {
                if (timeout == timeout_arg) {
                    if (fd != INVALID_FD)
                        ch_log (channel, "Timed out");
                    break;
                }
            }
            else
                channel_read (channel, part, "channel_read_json_block");
        }
    }
    chanpart->ch_block_id = 0;
    return FAIL;
}

void ch_expr_common (typval_T *argvars, typval_T *rettv, int eval) {
    char_u *text;
    typval_T *listtv;
    channel_T *channel;
    int id;
    ch_mode_T ch_mode;
    ch_part_T part_send;
    ch_part_T part_read;
    jobopt_T opt;
    int timeout;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    channel = get_channel_arg (&argvars[0], TRUE, FALSE, 0);
    if (channel == NULL)
        return;
    part_send = channel_part_send (channel);
    ch_mode = channel_get_mode (channel, part_send);
    if (ch_mode == MODE_RAW || ch_mode == MODE_NL) {
        EMSG (_ ("E912: cannot use ch_evalexpr()/ch_sendexpr() with a raw or nl channel"));
        return;
    }
    id = ++channel->ch_last_msg_id;
    text = json_encode_nr_expr (id, &argvars[1], (ch_mode == MODE_JS ? JSON_JS : 0) | JSON_NL);
    if (text == NULL)
        return;
    channel = send_common (argvars, text, id, eval, &opt, eval ? "ch_evalexpr" : "ch_sendexpr", &part_read);
    vim_free (text);
    if (channel != NULL && eval) {
        if (opt.jo_set & JO_TIMEOUT)
            timeout = opt.jo_timeout;
        else
            timeout = channel_get_timeout (channel, part_read);
        if (channel_read_json_block (channel, part_read, timeout, id, &listtv) == OK) {
            list_T *list = listtv->vval.v_list;
            *rettv = list->lv_last->li_tv;
            list->lv_last->li_tv.v_type = VAR_NUMBER;
            free_tv (listtv);
        }
    }
    free_job_options (& opt);
}

ch_part_T channel_part_send (channel_T *channel) {
    if (channel->CH_SOCK_FD == INVALID_FD)
        return PART_IN;
    return PART_SOCK;
}

static channel_T *send_common (typval_T *argvars, char_u *text, int id, int eval, jobopt_T *opt, char *fun, ch_part_T *part_read) {
    channel_T *channel;
    ch_part_T part_send;
    clear_job_options (opt);
    channel = get_channel_arg (&argvars[0], TRUE, FALSE, 0);
    if (channel == NULL)
        return NULL;
    part_send = channel_part_send (channel);
    *part_read = channel_part_read (channel);
    if (get_job_options (&argvars[2], opt, JO_CALLBACK +JO_TIMEOUT, 0) == FAIL)
        return NULL;
    if (opt->jo_callback != NULL && *opt->jo_callback != NUL) {
        if (eval) {
            EMSG2 (_ ("E917: Cannot use a callback with %s()"), fun);
            return NULL;
        }
        channel_set_req_callback (channel, * part_read, opt -> jo_callback, opt -> jo_partial, id);
    }
    if (channel_send (channel, part_send, text, (int) STRLEN (text), fun) == OK && opt->jo_callback == NULL)
        return channel;
    return NULL;
}

void channel_set_req_callback (channel_T *channel, ch_part_T part, char_u *callback, partial_T *partial, int id) {
    cbq_T *head = &channel->ch_part[part].ch_cb_head;
    cbq_T *item = (cbq_T *) alloc ((int) sizeof (cbq_T));
    if (item != NULL) {
        item->cq_partial = partial;
        if (partial != NULL) {
            ++partial->pt_refcount;
            item->cq_callback = callback;
        }
        else {
            item->cq_callback = vim_strsave (callback);
            func_ref (item -> cq_callback);
        }
        item->cq_seq_nr = id;
        item->cq_prev = head->cq_prev;
        head->cq_prev = item;
        item->cq_next = NULL;
        if (item->cq_prev == NULL)
            head->cq_next = item;
        else
            item->cq_prev->cq_next = item;
    }
}

void ch_raw_common (typval_T *argvars, typval_T *rettv, int eval) {
    char_u buf [NUMBUFLEN];
    char_u *text;
    channel_T *channel;
    ch_part_T part_read;
    jobopt_T opt;
    int timeout;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    text = get_tv_string_buf (&argvars[1], buf);
    channel = send_common (argvars, text, 0, eval, &opt, eval ? "ch_evalraw" : "ch_sendraw", &part_read);
    if (channel != NULL && eval) {
        if (opt.jo_set & JO_TIMEOUT)
            timeout = opt.jo_timeout;
        else
            timeout = channel_get_timeout (channel, part_read);
        rettv->vval.v_string = channel_read_block (channel, part_read, timeout, TRUE);
    }
    free_job_options (& opt);
}

# define KEEP_OPEN_TIME 20  /* msec */

void job_info (job_T *job, dict_T *dict) {
    dictitem_T *item;
    varnumber_T nr;
    dict_add_nr_str (dict, "status", 0L, (char_u *) job_status (job));
    item = dictitem_alloc ((char_u *) "channel");
    if (item == NULL)
        return;
    item->di_tv.v_lock = 0;
    item->di_tv.v_type = VAR_CHANNEL;
    item->di_tv.vval.v_channel = job->jv_channel;
    if (job->jv_channel != NULL)
        ++job->jv_channel->ch_refcount;
    if (dict_add (dict, item) == FAIL)
        dictitem_free (item);
    nr = job->jv_pid;
    dict_add_nr_str (dict, "process", nr, NULL);
    dict_add_nr_str (dict, "tty_in", 0L, job -> jv_tty_in != NULL ? job -> jv_tty_in : (char_u *) "");
    dict_add_nr_str (dict, "tty_out", 0L, job -> jv_tty_out != NULL ? job -> jv_tty_out : (char_u *) "");
    dict_add_nr_str (dict, "exitval", job -> jv_exitval, NULL);
    dict_add_nr_str (dict, "exit_cb", 0L, job -> jv_exit_cb);
    dict_add_nr_str (dict, "stoponexit", 0L, job -> jv_stoponexit);
}

