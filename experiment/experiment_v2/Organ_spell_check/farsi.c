
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
EXTERN int p_ri;
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

int F_ischar (int c) {
    return (c >= TEE_ && c <= YE_);
}

int F_isalpha (int c) {
    return ((c >= TEE_ && c <= _YE) || (c >= ALEF_A && c <= YE) || (c >= _IE && c <= YE_));
}

int F_isdigit (int c) {
    return (c >= FARSI_0 && c <= FARSI_9);
}

int fkmap (int c) {
    int tempc;
    int insert_mode = (State & INSERT);
    static int revins = 0;
    if (IS_SPECIAL (c))
        return c;
    if (insert_mode) {
        if (VIM_ISDIGIT (c) || ((c == '.' || c == '+' || c == '-' || c == '^' || c == '%' || c == '#' || c == '=') && revins)) {
            if (!revins) {
                if (curwin->w_cursor.col) {
                    if (!p_ri)
                        dec_cursor ();
                    chg_c_toX_orX ();
                    chg_l_toXor_X ();
                    if (!p_ri)
                        inc_cursor ();
                }
            }
            arrow_used = TRUE;
            (void) stop_arrow ();
            if (!curwin->w_p_rl && revins)
                inc_cursor ();
            ++revins;
            p_ri = 1;
        }
        else if (revins) {
            arrow_used = TRUE;
            (void) stop_arrow ();
            revins = 0;
            if (curwin->w_p_rl) {
                while ((F_isdigit (gchar_cursor ()) || (gchar_cursor () == F_PERIOD || gchar_cursor () == F_PLUS || gchar_cursor () == F_MINUS || gchar_cursor () == F_MUL || gchar_cursor () == F_DIVIDE || gchar_cursor () == F_PERCENT || gchar_cursor () == F_EQUALS)) && gchar_cursor () != NUL)
                    ++curwin->w_cursor.col;
            }
            else {
                if (curwin->w_cursor.col)
                    while ((F_isdigit (gchar_cursor ()) || (gchar_cursor () == F_PERIOD || gchar_cursor () == F_PLUS || gchar_cursor () == F_MINUS || gchar_cursor () == F_MUL || gchar_cursor () == F_DIVIDE || gchar_cursor () == F_PERCENT || gchar_cursor () == F_EQUALS)) && --curwin->w_cursor.col)
                        ;
                if (!F_isdigit (gchar_cursor ()))
                    ++curwin->w_cursor.col;
            }
        }
    }
    if (!revins) {
        if (curwin->w_p_rl)
            p_ri = 0;
        if (!curwin->w_p_rl)
            p_ri = 1;
    }
    if ((c < 0x100) && (isalpha (c) || c == '&' || c == '^' || c == ';' || c == '\'' || c == ',' || c == '[' || c == ']' || c == '{' || c == '}'))
        chg_r_to_Xor_X_ ();
    tempc = 0;
    switch (c) {
    case '`' :
    case ' ' :
    case '.' :
    case '!' :
    case '"' :
    case '$' :
    case '%' :
    case '^' :
    case '&' :
    case '/' :
    case '(' :
    case ')' :
    case '=' :
    case '\\' :
    case '?' :
    case '+' :
    case '-' :
    case '_' :
    case '*' :
    case ':' :
    case '#' :
    case '~' :
    case '@' :
    case '<' :
    case '>' :
    case '{' :
    case '}' :
    case '|' :
    case '0' :
    case '1' :
    case '2' :
    case '3' :
    case '4' :
    case '5' :
    case '6' :
    case '7' :
    case '8' :
    case '9' :
    case 'B' :
    case 'E' :
    case 'F' :
    case 'H' :
    case 'I' :
    case 'K' :
    case 'L' :
    case 'M' :
    case 'O' :
    case 'P' :
    case 'Q' :
    case 'R' :
    case 'T' :
    case 'U' :
    case 'W' :
    case 'Y' :
    case NL :
    case TAB :
        if (p_ri && c == NL && curwin->w_cursor.col && insert_mode) {
            dec_cursor ();
            if (F_isalpha (gchar_cursor ())) {
                inc_cursor ();
                return NL;
            }
            inc_cursor ();
        }
        if (!p_ri && !curwin->w_cursor.col) {
            switch (c) {
            case '0' :
                return FARSI_0;
            case '1' :
                return FARSI_1;
            case '2' :
                return FARSI_2;
            case '3' :
                return FARSI_3;
            case '4' :
                return FARSI_4;
            case '5' :
                return FARSI_5;
            case '6' :
                return FARSI_6;
            case '7' :
                return FARSI_7;
            case '8' :
                return FARSI_8;
            case '9' :
                return FARSI_9;
            case 'B' :
                return F_PSP;
            case 'E' :
                return JAZR_N;
            case 'F' :
                return ALEF_D_H;
            case 'H' :
                return ALEF_A;
            case 'I' :
                return TASH;
            case 'K' :
                return F_LQUOT;
            case 'L' :
                return F_RQUOT;
            case 'M' :
                return HAMZE;
            case 'O' :
                return '[';
            case 'P' :
                return ']';
            case 'Q' :
                return OO;
            case 'R' :
                return MAD_N;
            case 'T' :
                return OW;
            case 'U' :
                return MAD;
            case 'W' :
                return OW_OW;
            case 'Y' :
                return JAZR;
            case '`' :
                return F_PCN;
            case '!' :
                return F_EXCL;
            case '@' :
                return F_COMMA;
            case '#' :
                return F_DIVIDE;
            case '$' :
                return F_CURRENCY;
            case '%' :
                return F_PERCENT;
            case '^' :
                return F_MUL;
            case '&' :
                return F_BCOMMA;
            case '*' :
                return F_STAR;
            case '(' :
                return F_LPARENT;
            case ')' :
                return F_RPARENT;
            case '-' :
                return F_MINUS;
            case '_' :
                return F_UNDERLINE;
            case '=' :
                return F_EQUALS;
            case '+' :
                return F_PLUS;
            case '\\' :
                return F_BSLASH;
            case '|' :
                return F_PIPE;
            case ':' :
                return F_DCOLON;
            case '"' :
                return F_SEMICOLON;
            case '.' :
                return F_PERIOD;
            case '/' :
                return F_SLASH;
            case '<' :
                return F_LESS;
            case '>' :
                return F_GREATER;
            case '?' :
                return F_QUESTION;
            case ' ' :
                return F_BLANK;
            }
            break;
        }
        if (insert_mode) {
            if (!p_ri)
                dec_cursor ();
            switch ((tempc = gchar_cursor ())) {
            case _BE :
            case _PE :
            case _TE :
            case _SE :
            case _JIM :
            case _CHE :
            case _HE_J :
            case _XE :
            case _SIN :
            case _SHIN :
            case _SAD :
            case _ZAD :
            case _FE :
            case _GHAF :
            case _KAF :
            case _KAF_H :
            case _GAF :
            case _LAM :
            case _MIM :
            case _NOON :
            case _HE :
            case _HE_ :
            case _TA :
            case _ZA :
                put_curr_and_l_to_X (toF_TyA (tempc));
                break;
            case _AYN :
            case _AYN_ :
                if (!p_ri)
                    if (!curwin->w_cursor.col) {
                        put_curr_and_l_to_X (AYN);
                        break;
                    }
                if (p_ri)
                    inc_cursor ();
                else
                    dec_cursor ();
                if (F_is_TyB_TyC_TyD (SRC_EDT, AT_CURSOR))
                    tempc = AYN_;
                else
                    tempc = AYN;
                if (p_ri)
                    dec_cursor ();
                else
                    inc_cursor ();
                put_curr_and_l_to_X (tempc);
                break;
            case _GHAYN :
            case _GHAYN_ :
                if (!p_ri)
                    if (!curwin->w_cursor.col) {
                        put_curr_and_l_to_X (GHAYN);
                        break;
                    }
                if (p_ri)
                    inc_cursor ();
                else
                    dec_cursor ();
                if (F_is_TyB_TyC_TyD (SRC_EDT, AT_CURSOR))
                    tempc = GHAYN_;
                else
                    tempc = GHAYN;
                if (p_ri)
                    dec_cursor ();
                else
                    inc_cursor ();
                put_curr_and_l_to_X (tempc);
                break;
            case _YE :
            case _IE :
            case _YEE :
                if (!p_ri)
                    if (!curwin->w_cursor.col) {
                        put_curr_and_l_to_X ((tempc == _YE ? YE : (tempc == _IE ? IE : YEE)));
                        break;
                    }
                if (p_ri)
                    inc_cursor ();
                else
                    dec_cursor ();
                if (F_is_TyB_TyC_TyD (SRC_EDT, AT_CURSOR))
                    tempc = (tempc == _YE ? YE_ : (tempc == _IE ? IE_ : YEE_));
                else
                    tempc = (tempc == _YE ? YE : (tempc == _IE ? IE : YEE));
                if (p_ri)
                    dec_cursor ();
                else
                    inc_cursor ();
                put_curr_and_l_to_X (tempc);
                break;
            }
            if (!p_ri)
                inc_cursor ();
        }
        tempc = 0;
        switch (c) {
        case '0' :
            return FARSI_0;
        case '1' :
            return FARSI_1;
        case '2' :
            return FARSI_2;
        case '3' :
            return FARSI_3;
        case '4' :
            return FARSI_4;
        case '5' :
            return FARSI_5;
        case '6' :
            return FARSI_6;
        case '7' :
            return FARSI_7;
        case '8' :
            return FARSI_8;
        case '9' :
            return FARSI_9;
        case 'B' :
            return F_PSP;
        case 'E' :
            return JAZR_N;
        case 'F' :
            return ALEF_D_H;
        case 'H' :
            return ALEF_A;
        case 'I' :
            return TASH;
        case 'K' :
            return F_LQUOT;
        case 'L' :
            return F_RQUOT;
        case 'M' :
            return HAMZE;
        case 'O' :
            return '[';
        case 'P' :
            return ']';
        case 'Q' :
            return OO;
        case 'R' :
            return MAD_N;
        case 'T' :
            return OW;
        case 'U' :
            return MAD;
        case 'W' :
            return OW_OW;
        case 'Y' :
            return JAZR;
        case '`' :
            return F_PCN;
        case '!' :
            return F_EXCL;
        case '@' :
            return F_COMMA;
        case '#' :
            return F_DIVIDE;
        case '$' :
            return F_CURRENCY;
        case '%' :
            return F_PERCENT;
        case '^' :
            return F_MUL;
        case '&' :
            return F_BCOMMA;
        case '*' :
            return F_STAR;
        case '(' :
            return F_LPARENT;
        case ')' :
            return F_RPARENT;
        case '-' :
            return F_MINUS;
        case '_' :
            return F_UNDERLINE;
        case '=' :
            return F_EQUALS;
        case '+' :
            return F_PLUS;
        case '\\' :
            return F_BSLASH;
        case '|' :
            return F_PIPE;
        case ':' :
            return F_DCOLON;
        case '"' :
            return F_SEMICOLON;
        case '.' :
            return F_PERIOD;
        case '/' :
            return F_SLASH;
        case '<' :
            return F_LESS;
        case '>' :
            return F_GREATER;
        case '?' :
            return F_QUESTION;
        case ' ' :
            return F_BLANK;
        }
        break;
    case 'a' :
        tempc = _SHIN;
        break;
    case 'A' :
        tempc = WAW_H;
        break;
    case 'b' :
        tempc = ZAL;
        break;
    case 'c' :
        tempc = ZE;
        break;
    case 'C' :
        tempc = JE;
        break;
    case 'd' :
        tempc = _YE;
        break;
    case 'D' :
        tempc = _YEE;
        break;
    case 'e' :
        tempc = _SE;
        break;
    case 'f' :
        tempc = _BE;
        break;
    case 'g' :
        tempc = _LAM;
        break;
    case 'G' :
        if (!curwin->w_cursor.col && STRLEN (ml_get_curline ())) {
            if (gchar_cursor () == _LAM)
                chg_c_toX_orX ();
            else if (p_ri)
                chg_c_to_X_or_X ();
        }
        if (!p_ri)
            if (!curwin->w_cursor.col)
                return ALEF_U_H;
        if (!p_ri)
            dec_cursor ();
        if (gchar_cursor () == _LAM) {
            chg_c_toX_orX ();
            chg_l_toXor_X ();
            tempc = ALEF_U_H;
        }
        else if (F_is_TyB_TyC_TyD (SRC_EDT, AT_CURSOR)) {
            tempc = ALEF_U_H_;
            chg_l_toXor_X ();
        }
        else
            tempc = ALEF_U_H;
        if (!p_ri)
            inc_cursor ();
        return tempc;
    case 'h' :
        if (!curwin->w_cursor.col && STRLEN (ml_get_curline ())) {
            if (p_ri)
                chg_c_to_X_or_X ();
        }
        if (!p_ri)
            if (!curwin->w_cursor.col)
                return ALEF;
        if (!p_ri)
            dec_cursor ();
        if (gchar_cursor () == _LAM) {
            chg_l_toXor_X ();
            del_char (FALSE);
            AppendCharToRedobuff (K_BS);
            if (!p_ri)
                dec_cursor ();
            tempc = LA;
        }
        else {
            if (F_is_TyB_TyC_TyD (SRC_EDT, AT_CURSOR)) {
                tempc = ALEF_;
                chg_l_toXor_X ();
            }
            else
                tempc = ALEF;
        }
        if (!p_ri)
            inc_cursor ();
        return tempc;
    case 'i' :
        if (!curwin->w_cursor.col && STRLEN (ml_get_curline ())) {
            if (!p_ri && !F_is_TyE (tempc))
                chg_c_to_X_orX_ ();
            if (p_ri)
                chg_c_to_X_or_X ();
        }
        if (!p_ri && !curwin->w_cursor.col)
            return _HE;
        if (!p_ri)
            dec_cursor ();
        if (F_is_TyB_TyC_TyD (SRC_EDT, AT_CURSOR))
            tempc = _HE_;
        else
            tempc = _HE;
        if (!p_ri)
            inc_cursor ();
        break;
    case 'j' :
        tempc = _TE;
        break;
    case 'J' :
        if (!curwin->w_cursor.col && STRLEN (ml_get_curline ())) {
            if (p_ri)
                chg_c_to_X_or_X ();
        }
        if (!p_ri)
            if (!curwin->w_cursor.col)
                return TEE;
        if (!p_ri)
            dec_cursor ();
        if (F_is_TyB_TyC_TyD (SRC_EDT, AT_CURSOR)) {
            tempc = TEE_;
            chg_l_toXor_X ();
        }
        else
            tempc = TEE;
        if (!p_ri)
            inc_cursor ();
        return tempc;
    case 'k' :
        tempc = _NOON;
        break;
    case 'l' :
        tempc = _MIM;
        break;
    case 'm' :
        tempc = _PE;
        break;
    case 'n' :
    case 'N' :
        tempc = DAL;
        break;
    case 'o' :
        tempc = _XE;
        break;
    case 'p' :
        tempc = _HE_J;
        break;
    case 'q' :
        tempc = _ZAD;
        break;
    case 'r' :
        tempc = _GHAF;
        break;
    case 's' :
        tempc = _SIN;
        break;
    case 'S' :
        tempc = _IE;
        break;
    case 't' :
        tempc = _FE;
        break;
    case 'u' :
        if (!curwin->w_cursor.col && STRLEN (ml_get_curline ())) {
            if (!p_ri && !F_is_TyE (tempc))
                chg_c_to_X_orX_ ();
            if (p_ri)
                chg_c_to_X_or_X ();
        }
        if (!p_ri && !curwin->w_cursor.col)
            return _AYN;
        if (!p_ri)
            dec_cursor ();
        if (F_is_TyB_TyC_TyD (SRC_EDT, AT_CURSOR))
            tempc = _AYN_;
        else
            tempc = _AYN;
        if (!p_ri)
            inc_cursor ();
        break;
    case 'v' :
    case 'V' :
        tempc = RE;
        break;
    case 'w' :
        tempc = _SAD;
        break;
    case 'x' :
    case 'X' :
        tempc = _TA;
        break;
    case 'y' :
        if (!curwin->w_cursor.col && STRLEN (ml_get_curline ())) {
            if (!p_ri && !F_is_TyE (tempc))
                chg_c_to_X_orX_ ();
            if (p_ri)
                chg_c_to_X_or_X ();
        }
        if (!p_ri && !curwin->w_cursor.col)
            return _GHAYN;
        if (!p_ri)
            dec_cursor ();
        if (F_is_TyB_TyC_TyD (SRC_EDT, AT_CURSOR))
            tempc = _GHAYN_;
        else
            tempc = _GHAYN;
        if (!p_ri)
            inc_cursor ();
        break;
    case 'z' :
        tempc = _ZA;
        break;
    case 'Z' :
        tempc = _KAF_H;
        break;
    case ';' :
        tempc = _KAF;
        break;
    case '\'' :
        tempc = _GAF;
        break;
    case ',' :
        tempc = WAW;
        break;
    case '[' :
        tempc = _JIM;
        break;
    case ']' :
        tempc = _CHE;
        break;
    }
    if (F_isalpha (tempc) || F_isdigit (tempc)) {
        if (!curwin->w_cursor.col && STRLEN (ml_get_curline ())) {
            if (!p_ri && !F_is_TyE (tempc))
                chg_c_to_X_orX_ ();
            if (p_ri)
                chg_c_to_X_or_X ();
        }
        if (curwin->w_cursor.col) {
            if (!p_ri)
                dec_cursor ();
            if (F_is_TyE (tempc))
                chg_l_toXor_X ();
            else
                chg_l_to_X_orX_ ();
            if (!p_ri)
                inc_cursor ();
        }
    }
    if (tempc)
        return tempc;
    return c;
}

static void chg_c_toX_orX (void) {
    int tempc, curc;
    switch ((curc = gchar_cursor ())) {
    case _BE :
        tempc = BE;
        break;
    case _PE :
        tempc = PE;
        break;
    case _TE :
        tempc = TE;
        break;
    case _SE :
        tempc = SE;
        break;
    case _JIM :
        tempc = JIM;
        break;
    case _CHE :
        tempc = CHE;
        break;
    case _HE_J :
        tempc = HE_J;
        break;
    case _XE :
        tempc = XE;
        break;
    case _SIN :
        tempc = SIN;
        break;
    case _SHIN :
        tempc = SHIN;
        break;
    case _SAD :
        tempc = SAD;
        break;
    case _ZAD :
        tempc = ZAD;
        break;
    case _FE :
        tempc = FE;
        break;
    case _GHAF :
        tempc = GHAF;
        break;
    case _KAF_H :
    case _KAF :
        tempc = KAF;
        break;
    case _GAF :
        tempc = GAF;
        break;
    case _AYN :
        tempc = AYN;
        break;
    case _AYN_ :
        tempc = AYN_;
        break;
    case _GHAYN :
        tempc = GHAYN;
        break;
    case _GHAYN_ :
        tempc = GHAYN_;
        break;
    case _LAM :
        tempc = LAM;
        break;
    case _MIM :
        tempc = MIM;
        break;
    case _NOON :
        tempc = NOON;
        break;
    case _HE :
    case _HE_ :
        tempc = F_HE;
        break;
    case _YE :
    case _IE :
    case _YEE :
        if (p_ri) {
            inc_cursor ();
            if (F_is_TyB_TyC_TyD (SRC_EDT, AT_CURSOR))
                tempc = (curc == _YE ? YE_ : (curc == _IE ? IE_ : YEE_));
            else
                tempc = (curc == _YE ? YE : (curc == _IE ? IE : YEE));
            dec_cursor ();
        }
        else {
            if (curwin->w_cursor.col) {
                dec_cursor ();
                if (F_is_TyB_TyC_TyD (SRC_EDT, AT_CURSOR))
                    tempc = (curc == _YE ? YE_ : (curc == _IE ? IE_ : YEE_));
                else
                    tempc = (curc == _YE ? YE : (curc == _IE ? IE : YEE));
                inc_cursor ();
            }
            else
                tempc = (curc == _YE ? YE : (curc == _IE ? IE : YEE));
        }
        break;
    default :
        tempc = 0;
    }
    if (tempc)
        put_and_redo (tempc);
}

static int F_is_TyB_TyC_TyD (int src, int offset) {
    int c;
    if (src == SRC_EDT)
        c = gchar_cursor ();
    else
        c = cmd_gchar (AT_CURSOR +offset);
    switch (c) {
    case _LAM :
    case _BE :
    case _PE :
    case _TE :
    case _SE :
    case _JIM :
    case _CHE :
    case _HE_J :
    case _XE :
    case _SIN :
    case _SHIN :
    case _SAD :
    case _ZAD :
    case _TA :
    case _ZA :
    case _AYN :
    case _AYN_ :
    case _GHAYN :
    case _GHAYN_ :
    case _FE :
    case _GHAF :
    case _KAF :
    case _KAF_H :
    case _GAF :
    case _MIM :
    case _NOON :
    case _YE :
    case _YEE :
    case _IE :
    case _HE_ :
    case _HE :
        return TRUE;
    }
    return FALSE;
}

static void put_and_redo (int c) {
    pchar_cursor (c);
    AppendCharToRedobuff (K_BS);
    AppendCharToRedobuff (c);
}

static void chg_l_toXor_X (void) {
    int tempc;
    if (curwin->w_cursor.col != 0 && (curwin->w_cursor.col + 1 == (colnr_T) STRLEN (ml_get_curline ())))
        return;
    if (!curwin->w_cursor.col && p_ri)
        return;
    if (p_ri)
        dec_cursor ();
    else
        inc_cursor ();
    switch (gchar_cursor ()) {
    case ALEF_ :
        tempc = ALEF;
        break;
    case ALEF_U_H_ :
        tempc = ALEF_U_H;
        break;
    case _AYN_ :
        tempc = _AYN;
        break;
    case AYN_ :
        tempc = AYN;
        break;
    case _GHAYN_ :
        tempc = _GHAYN;
        break;
    case GHAYN_ :
        tempc = GHAYN;
        break;
    case _HE_ :
        tempc = _HE;
        break;
    case YE_ :
        tempc = YE;
        break;
    case IE_ :
        tempc = IE;
        break;
    case TEE_ :
        tempc = TEE;
        break;
    case YEE_ :
        tempc = YEE;
        break;
    default :
        tempc = 0;
    }
    if (tempc)
        put_and_redo (tempc);
    if (p_ri)
        inc_cursor ();
    else
        dec_cursor ();
}

static void chg_r_to_Xor_X_ (void) {
    int tempc, c;
    if (curwin->w_cursor.col) {
        if (!p_ri)
            dec_cursor ();
        tempc = gchar_cursor ();
        if ((c = toF_Xor_X_ (tempc)) != 0)
            put_and_redo (c);
        if (!p_ri)
            inc_cursor ();
    }
}

static int toF_Xor_X_ (int c) {
    int tempc;
    switch (c) {
    case BE :
        return _BE;
    case PE :
        return _PE;
    case TE :
        return _TE;
    case SE :
        return _SE;
    case JIM :
        return _JIM;
    case CHE :
        return _CHE;
    case HE_J :
        return _HE_J;
    case XE :
        return _XE;
    case SIN :
        return _SIN;
    case SHIN :
        return _SHIN;
    case SAD :
        return _SAD;
    case ZAD :
        return _ZAD;
    case AYN :
        return _AYN;
    case AYN_ :
        return _AYN_;
    case GHAYN :
        return _GHAYN;
    case GHAYN_ :
        return _GHAYN_;
    case FE :
        return _FE;
    case GHAF :
        return _GHAF;
    case KAF :
        return _KAF;
    case GAF :
        return _GAF;
    case LAM :
        return _LAM;
    case MIM :
        return _MIM;
    case NOON :
        return _NOON;
    case YE :
    case YE_ :
        return _YE;
    case YEE :
    case YEE_ :
        return _YEE;
    case IE :
    case IE_ :
        return _IE;
    case F_HE :
        tempc = _HE;
        if (p_ri && (curwin->w_cursor.col + 1 < (colnr_T) STRLEN (ml_get_curline ()))) {
            inc_cursor ();
            if (F_is_TyB_TyC_TyD (SRC_EDT, AT_CURSOR))
                tempc = _HE_;
            dec_cursor ();
        }
        if (!p_ri && STRLEN (ml_get_curline ())) {
            dec_cursor ();
            if (F_is_TyB_TyC_TyD (SRC_EDT, AT_CURSOR))
                tempc = _HE_;
            inc_cursor ();
        }
        return tempc;
    }
    return 0;
}

static void put_curr_and_l_to_X (int c) {
    int tempc;
    if (curwin->w_p_rl && p_ri)
        return;
    if ((curwin->w_cursor.col < (colnr_T) STRLEN (ml_get_curline ()))) {
        if ((p_ri && curwin->w_cursor.col) || !p_ri) {
            if (p_ri)
                dec_cursor ();
            else
                inc_cursor ();
            if (F_is_TyC_TyD ((tempc = gchar_cursor ()))) {
                pchar_cursor (toF_TyB (tempc));
                AppendCharToRedobuff (K_BS);
                AppendCharToRedobuff (tempc);
            }
            if (p_ri)
                inc_cursor ();
            else
                dec_cursor ();
        }
    }
    put_and_redo (c);
}

static int F_is_TyC_TyD (int c) {
    switch (c) {
    case ALEF_ :
    case ALEF_U_H_ :
    case _AYN_ :
    case AYN_ :
    case _GHAYN_ :
    case GHAYN_ :
    case _HE_ :
    case YE_ :
    case IE_ :
    case TEE_ :
    case YEE_ :
        return TRUE;
    }
    return FALSE;
}

static int toF_TyB (int c) {
    switch (c) {
    case ALEF_ :
        return ALEF;
    case ALEF_U_H_ :
        return ALEF_U_H;
    case _AYN_ :
        return _AYN;
    case AYN_ :
        return AYN;
    case _GHAYN_ :
        return _GHAYN;
    case GHAYN_ :
        return GHAYN;
    case _HE_ :
        return _HE;
    case YE_ :
        return YE;
    case IE_ :
        return IE;
    case TEE_ :
        return TEE;
    case YEE_ :
        return YEE;
    }
    return c;
}

static int toF_TyA (int c) {
    switch (c) {
    case ALEF_ :
        return ALEF;
    case ALEF_U_H_ :
        return ALEF_U_H;
    case _BE :
        return BE;
    case _PE :
        return PE;
    case _TE :
        return TE;
    case _SE :
        return SE;
    case _JIM :
        return JIM;
    case _CHE :
        return CHE;
    case _HE_J :
        return HE_J;
    case _XE :
        return XE;
    case _SIN :
        return SIN;
    case _SHIN :
        return SHIN;
    case _SAD :
        return SAD;
    case _ZAD :
        return ZAD;
    case _AYN :
    case AYN_ :
    case _AYN_ :
        return AYN;
    case _GHAYN :
    case GHAYN_ :
    case _GHAYN_ :
        return GHAYN;
    case _FE :
        return FE;
    case _GHAF :
        return GHAF;
    case _KAF :
        return KAF;
    case _GAF :
        return GAF;
    case _LAM :
        return LAM;
    case _MIM :
        return MIM;
    case _NOON :
        return NOON;
    case _YE :
    case YE_ :
        return YE;
    case _YEE :
    case YEE_ :
        return YEE;
    case TEE_ :
        return TEE;
    case _IE :
    case IE_ :
        return IE;
    case _HE :
    case _HE_ :
        return F_HE;
    }
    return c;
}

static void chg_c_to_X_or_X (void) {
    int tempc;
    tempc = gchar_cursor ();
    if (curwin->w_cursor.col + 1 < (colnr_T) STRLEN (ml_get_curline ())) {
        inc_cursor ();
        if ((tempc == F_HE) && (F_is_TyB_TyC_TyD (SRC_EDT, AT_CURSOR))) {
            tempc = _HE_;
            dec_cursor ();
            put_and_redo (tempc);
            return;
        }
        dec_cursor ();
    }
    if ((tempc = toF_Xor_X_ (tempc)) != 0)
        put_and_redo (tempc);
}

static int F_is_TyE (int c) {
    switch (c) {
    case ALEF_A :
    case ALEF_D_H :
    case DAL :
    case ZAL :
    case RE :
    case ZE :
    case JE :
    case WAW :
    case WAW_H :
    case HAMZE :
        return TRUE;
    }
    return FALSE;
}

static void chg_c_to_X_orX_ (void) {
    int tempc;
    switch (gchar_cursor ()) {
    case ALEF :
        tempc = ALEF_;
        break;
    case ALEF_U_H :
        tempc = ALEF_U_H_;
        break;
    case _AYN :
        tempc = _AYN_;
        break;
    case AYN :
        tempc = AYN_;
        break;
    case _GHAYN :
        tempc = _GHAYN_;
        break;
    case GHAYN :
        tempc = GHAYN_;
        break;
    case _HE :
        tempc = _HE_;
        break;
    case YE :
        tempc = YE_;
        break;
    case IE :
        tempc = IE_;
        break;
    case TEE :
        tempc = TEE_;
        break;
    case YEE :
        tempc = YEE_;
        break;
    default :
        tempc = 0;
    }
    if (tempc)
        put_and_redo (tempc);
}

static void chg_l_to_X_orX_ (void) {
    int tempc;
    if (curwin->w_cursor.col != 0 && (curwin->w_cursor.col + 1 == (colnr_T) STRLEN (ml_get_curline ())))
        return;
    if (!curwin->w_cursor.col && p_ri)
        return;
    if (p_ri)
        dec_cursor ();
    else
        inc_cursor ();
    switch (gchar_cursor ()) {
    case ALEF :
        tempc = ALEF_;
        break;
    case ALEF_U_H :
        tempc = ALEF_U_H_;
        break;
    case _AYN :
        tempc = _AYN_;
        break;
    case AYN :
        tempc = AYN_;
        break;
    case _GHAYN :
        tempc = _GHAYN_;
        break;
    case GHAYN :
        tempc = GHAYN_;
        break;
    case _HE :
        tempc = _HE_;
        break;
    case YE :
        tempc = YE_;
        break;
    case IE :
        tempc = IE_;
        break;
    case TEE :
        tempc = TEE_;
        break;
    case YEE :
        tempc = YEE_;
        break;
    default :
        tempc = 0;
    }
    if (tempc)
        put_and_redo (tempc);
    if (p_ri)
        inc_cursor ();
    else
        dec_cursor ();
}

char_u *lrswap (char_u *ibuf) {
    if (ibuf != NULL && *ibuf != NUL)
        lrswapbuf (ibuf, (int) STRLEN (ibuf));
    return ibuf;
}

static void lrswapbuf (char_u *buf, int len) {
    char_u *s, *e;
    int c;
    s = buf;
    e = buf + len - 1;
    while (e > s) {
        c = *s;
        *s = *e;
        *e = c;
        ++s;
        --e;
    }
}

int cmdl_fkmap (int c) {
    int tempc;
    switch (c) {
    case '0' :
    case '1' :
    case '2' :
    case '3' :
    case '4' :
    case '5' :
    case '6' :
    case '7' :
    case '8' :
    case '9' :
    case '`' :
    case ' ' :
    case '.' :
    case '!' :
    case '"' :
    case '$' :
    case '%' :
    case '^' :
    case '&' :
    case '/' :
    case '(' :
    case ')' :
    case '=' :
    case '\\' :
    case '?' :
    case '+' :
    case '-' :
    case '_' :
    case '*' :
    case ':' :
    case '#' :
    case '~' :
    case '@' :
    case '<' :
    case '>' :
    case '{' :
    case '}' :
    case '|' :
    case 'B' :
    case 'E' :
    case 'F' :
    case 'H' :
    case 'I' :
    case 'K' :
    case 'L' :
    case 'M' :
    case 'O' :
    case 'P' :
    case 'Q' :
    case 'R' :
    case 'T' :
    case 'U' :
    case 'W' :
    case 'Y' :
    case NL :
    case TAB :
        switch ((tempc = cmd_gchar (AT_CURSOR))) {
        case _BE :
        case _PE :
        case _TE :
        case _SE :
        case _JIM :
        case _CHE :
        case _HE_J :
        case _XE :
        case _SIN :
        case _SHIN :
        case _SAD :
        case _ZAD :
        case _AYN :
        case _GHAYN :
        case _FE :
        case _GHAF :
        case _KAF :
        case _GAF :
        case _LAM :
        case _MIM :
        case _NOON :
        case _HE :
        case _HE_ :
            cmd_pchar (toF_TyA (tempc), AT_CURSOR);
            break;
        case _AYN_ :
            cmd_pchar (AYN_, AT_CURSOR);
            break;
        case _GHAYN_ :
            cmd_pchar (GHAYN_, AT_CURSOR);
            break;
        case _IE :
            if (F_is_TyB_TyC_TyD (SRC_CMD, AT_CURSOR +1))
                cmd_pchar (IE_, AT_CURSOR);
            else
                cmd_pchar (IE, AT_CURSOR);
            break;
        case _YEE :
            if (F_is_TyB_TyC_TyD (SRC_CMD, AT_CURSOR +1))
                cmd_pchar (YEE_, AT_CURSOR);
            else
                cmd_pchar (YEE, AT_CURSOR);
            break;
        case _YE :
            if (F_is_TyB_TyC_TyD (SRC_CMD, AT_CURSOR +1))
                cmd_pchar (YE_, AT_CURSOR);
            else
                cmd_pchar (YE, AT_CURSOR);
        }
        switch (c) {
        case '0' :
            return FARSI_0;
        case '1' :
            return FARSI_1;
        case '2' :
            return FARSI_2;
        case '3' :
            return FARSI_3;
        case '4' :
            return FARSI_4;
        case '5' :
            return FARSI_5;
        case '6' :
            return FARSI_6;
        case '7' :
            return FARSI_7;
        case '8' :
            return FARSI_8;
        case '9' :
            return FARSI_9;
        case 'B' :
            return F_PSP;
        case 'E' :
            return JAZR_N;
        case 'F' :
            return ALEF_D_H;
        case 'H' :
            return ALEF_A;
        case 'I' :
            return TASH;
        case 'K' :
            return F_LQUOT;
        case 'L' :
            return F_RQUOT;
        case 'M' :
            return HAMZE;
        case 'O' :
            return '[';
        case 'P' :
            return ']';
        case 'Q' :
            return OO;
        case 'R' :
            return MAD_N;
        case 'T' :
            return OW;
        case 'U' :
            return MAD;
        case 'W' :
            return OW_OW;
        case 'Y' :
            return JAZR;
        case '`' :
            return F_PCN;
        case '!' :
            return F_EXCL;
        case '@' :
            return F_COMMA;
        case '#' :
            return F_DIVIDE;
        case '$' :
            return F_CURRENCY;
        case '%' :
            return F_PERCENT;
        case '^' :
            return F_MUL;
        case '&' :
            return F_BCOMMA;
        case '*' :
            return F_STAR;
        case '(' :
            return F_LPARENT;
        case ')' :
            return F_RPARENT;
        case '-' :
            return F_MINUS;
        case '_' :
            return F_UNDERLINE;
        case '=' :
            return F_EQUALS;
        case '+' :
            return F_PLUS;
        case '\\' :
            return F_BSLASH;
        case '|' :
            return F_PIPE;
        case ':' :
            return F_DCOLON;
        case '"' :
            return F_SEMICOLON;
        case '.' :
            return F_PERIOD;
        case '/' :
            return F_SLASH;
        case '<' :
            return F_LESS;
        case '>' :
            return F_GREATER;
        case '?' :
            return F_QUESTION;
        case ' ' :
            return F_BLANK;
        }
        break;
    case 'a' :
        return _SHIN;
    case 'A' :
        return WAW_H;
    case 'b' :
        return ZAL;
    case 'c' :
        return ZE;
    case 'C' :
        return JE;
    case 'd' :
        return _YE;
    case 'D' :
        return _YEE;
    case 'e' :
        return _SE;
    case 'f' :
        return _BE;
    case 'g' :
        return _LAM;
    case 'G' :
        if (cmd_gchar (AT_CURSOR) == _LAM) {
            cmd_pchar (LAM, AT_CURSOR);
            return ALEF_U_H;
        }
        if (F_is_TyB_TyC_TyD (SRC_CMD, AT_CURSOR))
            return ALEF_U_H_;
        else
            return ALEF_U_H;
    case 'h' :
        if (cmd_gchar (AT_CURSOR) == _LAM) {
            cmd_pchar (LA, AT_CURSOR);
            redrawcmdline ();
            return K_IGNORE;
        }
        if (F_is_TyB_TyC_TyD (SRC_CMD, AT_CURSOR))
            return ALEF_;
        else
            return ALEF;
    case 'i' :
        if (F_is_TyB_TyC_TyD (SRC_CMD, AT_CURSOR))
            return _HE_;
        else
            return _HE;
    case 'j' :
        return _TE;
    case 'J' :
        if (F_is_TyB_TyC_TyD (SRC_CMD, AT_CURSOR))
            return TEE_;
        else
            return TEE;
    case 'k' :
        return _NOON;
    case 'l' :
        return _MIM;
    case 'm' :
        return _PE;
    case 'n' :
    case 'N' :
        return DAL;
    case 'o' :
        return _XE;
    case 'p' :
        return _HE_J;
    case 'q' :
        return _ZAD;
    case 'r' :
        return _GHAF;
    case 's' :
        return _SIN;
    case 'S' :
        return _IE;
    case 't' :
        return _FE;
    case 'u' :
        if (F_is_TyB_TyC_TyD (SRC_CMD, AT_CURSOR))
            return _AYN_;
        else
            return _AYN;
    case 'v' :
    case 'V' :
        return RE;
    case 'w' :
        return _SAD;
    case 'x' :
    case 'X' :
        return _TA;
    case 'y' :
        if (F_is_TyB_TyC_TyD (SRC_CMD, AT_CURSOR))
            return _GHAYN_;
        else
            return _GHAYN;
    case 'z' :
    case 'Z' :
        return _ZA;
    case ';' :
        return _KAF;
    case '\'' :
        return _GAF;
    case ',' :
        return WAW;
    case '[' :
        return _JIM;
    case ']' :
        return _CHE;
    }
    return c;
}

char_u *lrFswap (char_u *cmdbuf, int len) {
    int i, cnt;
    if (cmdbuf == NULL)
        return cmdbuf;
    if (len == 0 && (len = (int) STRLEN (cmdbuf)) == 0)
        return cmdbuf;
    for (i = 0; i < len; i++) {
        for (cnt = 0; i + cnt < len && (F_isalpha (cmdbuf[i + cnt]) || F_isdigit (cmdbuf[i + cnt]) || cmdbuf[i + cnt] == ' '); ++cnt)
            ;
        lrswapbuf (cmdbuf + i, cnt);
        i += cnt;
    }
    return cmdbuf;
}

void farsi_f8 (cmdarg_T *cap) {
    if (p_altkeymap) {
        if (curwin->w_farsi & W_R_L) {
            p_fkmap = 0;
            do_cmdline_cmd ((char_u *) "set norl");
            MSG ("");
        }
        else {
            p_fkmap = 1;
            do_cmdline_cmd ((char_u *) "set rl");
            MSG ("");
        }
        curwin->w_farsi = curwin->w_farsi ^ W_R_L;
    }
}

void farsi_f9 (cmdarg_T *cap) {
    if (p_altkeymap && curwin->w_p_rl) {
        curwin->w_farsi = curwin->w_farsi ^ W_CONV;
        if (curwin->w_farsi & W_CONV)
            conv_to_pvim ();
        else
            conv_to_pstd ();
    }
}

static void conv_to_pvim (void) {
    char_u *ptr;
    int lnum, llen, i;
    for (lnum = 1; lnum <= curbuf->b_ml.ml_line_count; ++lnum) {
        ptr = ml_get ((linenr_T) lnum);
        llen = (int) STRLEN (ptr);
        for (i = 0; i < llen - 1; i++) {
            if (canF_Ljoin (ptr[i]) && canF_Rjoin (ptr[i + 1])) {
                ptr[i] = toF_leading (ptr[i]);
                ++i;
                while (i < llen && canF_Rjoin (ptr[i])) {
                    ptr[i] = toF_Rjoin (ptr[i]);
                    if (F_isterm (ptr[i]) || !F_isalpha (ptr[i]))
                        break;
                    ++i;
                }
                if (!F_isalpha (ptr[i]) || !canF_Rjoin (ptr[i]))
                    ptr[i - 1] = toF_ending (ptr[i - 1]);
            }
            else
                ptr[i] = toF_TyA (ptr[i]);
        }
    }
    do_cmdline_cmd ((char_u *) "%s/\202\231/\232/ge");
    do_cmdline_cmd ((char_u *) "%s/\201\231/\370\334/ge");
    redraw_later (CLEAR);
    MSG_ATTR (farsi_text_1, HL_ATTR (HLF_S));
}

static int canF_Ljoin (int c) {
    switch (c) {
    case _BE :
    case BE :
    case PE :
    case _PE :
    case TE :
    case _TE :
    case SE :
    case _SE :
    case JIM :
    case _JIM :
    case CHE :
    case _CHE :
    case HE_J :
    case _HE_J :
    case XE :
    case _XE :
    case SIN :
    case _SIN :
    case SHIN :
    case _SHIN :
    case SAD :
    case _SAD :
    case ZAD :
    case _ZAD :
    case _TA :
    case _ZA :
    case AYN :
    case _AYN :
    case _AYN_ :
    case AYN_ :
    case GHAYN :
    case GHAYN_ :
    case _GHAYN_ :
    case _GHAYN :
    case FE :
    case _FE :
    case GHAF :
    case _GHAF :
    case _KAF_H :
    case KAF :
    case _KAF :
    case GAF :
    case _GAF :
    case LAM :
    case _LAM :
    case MIM :
    case _MIM :
    case NOON :
    case _NOON :
    case IE :
    case _IE :
    case IE_ :
    case YE :
    case _YE :
    case YE_ :
    case YEE :
    case _YEE :
    case YEE_ :
    case F_HE :
    case _HE :
    case _HE_ :
        return TRUE;
    }
    return FALSE;
}

static int canF_Rjoin (int c) {
    switch (c) {
    case ALEF :
    case ALEF_ :
    case ALEF_U_H :
    case ALEF_U_H_ :
    case DAL :
    case ZAL :
    case RE :
    case JE :
    case ZE :
    case TEE :
    case TEE_ :
    case WAW :
    case WAW_H :
        return TRUE;
    }
    return canF_Ljoin (c);
}

static int toF_leading (int c) {
    switch (c) {
    case ALEF_ :
        return ALEF;
    case ALEF_U_H_ :
        return ALEF_U_H;
    case BE :
        return _BE;
    case PE :
        return _PE;
    case TE :
        return _TE;
    case SE :
        return _SE;
    case JIM :
        return _JIM;
    case CHE :
        return _CHE;
    case HE_J :
        return _HE_J;
    case XE :
        return _XE;
    case SIN :
        return _SIN;
    case SHIN :
        return _SHIN;
    case SAD :
        return _SAD;
    case ZAD :
        return _ZAD;
    case AYN :
    case AYN_ :
    case _AYN_ :
        return _AYN;
    case GHAYN :
    case GHAYN_ :
    case _GHAYN_ :
        return _GHAYN;
    case FE :
        return _FE;
    case GHAF :
        return _GHAF;
    case KAF :
        return _KAF;
    case GAF :
        return _GAF;
    case LAM :
        return _LAM;
    case MIM :
        return _MIM;
    case NOON :
        return _NOON;
    case _HE_ :
    case F_HE :
        return _HE;
    case YE :
    case YE_ :
        return _YE;
    case IE_ :
    case IE :
        return _IE;
    case YEE :
    case YEE_ :
        return _YEE;
    }
    return c;
}

static int toF_Rjoin (int c) {
    switch (c) {
    case ALEF :
        return ALEF_;
    case ALEF_U_H :
        return ALEF_U_H_;
    case BE :
        return _BE;
    case PE :
        return _PE;
    case TE :
        return _TE;
    case SE :
        return _SE;
    case JIM :
        return _JIM;
    case CHE :
        return _CHE;
    case HE_J :
        return _HE_J;
    case XE :
        return _XE;
    case SIN :
        return _SIN;
    case SHIN :
        return _SHIN;
    case SAD :
        return _SAD;
    case ZAD :
        return _ZAD;
    case AYN :
    case AYN_ :
    case _AYN :
        return _AYN_;
    case GHAYN :
    case GHAYN_ :
    case _GHAYN_ :
        return _GHAYN_;
    case FE :
        return _FE;
    case GHAF :
        return _GHAF;
    case KAF :
        return _KAF;
    case GAF :
        return _GAF;
    case LAM :
        return _LAM;
    case MIM :
        return _MIM;
    case NOON :
        return _NOON;
    case _HE :
    case F_HE :
        return _HE_;
    case YE :
    case YE_ :
        return _YE;
    case IE_ :
    case IE :
        return _IE;
    case TEE :
        return TEE_;
    case YEE :
    case YEE_ :
        return _YEE;
    }
    return c;
}

static int F_isterm (int c) {
    switch (c) {
    case ALEF :
    case ALEF_ :
    case ALEF_U_H :
    case ALEF_U_H_ :
    case DAL :
    case ZAL :
    case RE :
    case JE :
    case ZE :
    case WAW :
    case WAW_H :
    case TEE :
    case TEE_ :
        return TRUE;
    }
    return FALSE;
}

static int toF_ending (int c) {
    switch (c) {
    case _BE :
        return BE;
    case _PE :
        return PE;
    case _TE :
        return TE;
    case _SE :
        return SE;
    case _JIM :
        return JIM;
    case _CHE :
        return CHE;
    case _HE_J :
        return HE_J;
    case _XE :
        return XE;
    case _SIN :
        return SIN;
    case _SHIN :
        return SHIN;
    case _SAD :
        return SAD;
    case _ZAD :
        return ZAD;
    case _AYN :
        return AYN;
    case _AYN_ :
        return AYN_;
    case _GHAYN :
        return GHAYN;
    case _GHAYN_ :
        return GHAYN_;
    case _FE :
        return FE;
    case _GHAF :
        return GHAF;
    case _KAF_H :
    case _KAF :
        return KAF;
    case _GAF :
        return GAF;
    case _LAM :
        return LAM;
    case _MIM :
        return MIM;
    case _NOON :
        return NOON;
    case _YE :
        return YE_;
    case YE_ :
        return YE;
    case _YEE :
        return YEE_;
    case YEE_ :
        return YEE;
    case TEE :
        return TEE_;
    case _IE :
        return IE_;
    case IE_ :
        return IE;
    case _HE :
    case _HE_ :
        return F_HE;
    }
    return c;
}

static void conv_to_pstd (void) {
    char_u *ptr;
    int lnum, llen, i;
    do_cmdline_cmd ((char_u *) "%s/\232/\202\231/ge");
    for (lnum = 1; lnum <= curbuf->b_ml.ml_line_count; ++lnum) {
        ptr = ml_get ((linenr_T) lnum);
        llen = (int) STRLEN (ptr);
        for (i = 0; i < llen; i++)
            ptr[i] = toF_TyA (ptr[i]);
    }
    redraw_later (CLEAR);
    MSG_ATTR (farsi_text_2, HL_ATTR (HLF_S));
}

