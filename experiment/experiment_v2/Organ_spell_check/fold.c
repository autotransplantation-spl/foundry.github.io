
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
EXTERN int KeyTyped;
EXTERN char_u e_modifiable [] INIT (= N_ ("E21: Cannot make changes, 'modifiable' is off"));
EXTERN char_u *p_sel;
char *e_nofold = N_ ("E490: No fold found");
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
char_u *foldendmarker;
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
int fold_changed;
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
linenr_T invalid_bot = (linenr_T) 0;
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
linenr_T invalid_top = (linenr_T) 0;
EXTERN int searchcmdlen;
EXTERN long  p_titlelen;
int foldendmarkerlen;
int foldstartmarkerlen;
EXTERN int sc_col;
EXTERN int ru_col;
EXTERN int mouse_col;
EXTERN colnr_T search_match_endcol;
EXTERN int msg_col;
EXTERN int p_cc_cols [256];
EXTERN long  p_columnspace;
EXTERN int fuoptions_bgcolor;
int prev_lnum_lvl = -1;
linenr_T prev_lnum = 0;
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

int hasFolding (linenr_T lnum, linenr_T *firstp, linenr_T *lastp) {
    return hasFoldingWin (curwin, lnum, firstp, lastp, TRUE, NULL);
}

int hasFoldingWin (win_T *win, linenr_T lnum, linenr_T *firstp, linenr_T *lastp, int cache, foldinfo_T *infop) {
    int had_folded = FALSE;
    linenr_T first = 0;
    linenr_T last = 0;
    linenr_T lnum_rel = lnum;
    int x;
    fold_T *fp;
    int level = 0;
    int use_level = FALSE;
    int maybe_small = FALSE;
    garray_T *gap;
    int low_level = 0;
    checkupdate (win);
    if (!hasAnyFolding (win)) {
        if (infop != NULL)
            infop->fi_level = 0;
        return FALSE;
    }
    if (cache) {
        x = find_wl_entry (win, lnum);
        if (x >= 0) {
            first = win->w_lines[x].wl_lnum;
            last = win->w_lines[x].wl_lastlnum;
            had_folded = win->w_lines[x].wl_folded;
        }
    }
    if (first == 0) {
        gap = &win->w_folds;
        for (;;) {
            if (!foldFind (gap, lnum_rel, &fp))
                break;
            if (lnum_rel == fp->fd_top && low_level == 0)
                low_level = level + 1;
            first += fp->fd_top;
            last += fp->fd_top;
            had_folded = check_closed (win, fp, &use_level, level, &maybe_small, lnum -lnum_rel);
            if (had_folded) {
                last += fp->fd_len - 1;
                break;
            }
            gap = &fp->fd_nested;
            lnum_rel -= fp->fd_top;
            ++level;
        }
    }
    if (!had_folded) {
        if (infop != NULL) {
            infop->fi_level = level;
            infop->fi_lnum = lnum - lnum_rel;
            infop->fi_low_level = low_level == 0 ? level : low_level;
        }
        return FALSE;
    }
    if (last > win->w_buffer->b_ml.ml_line_count)
        last = win->w_buffer->b_ml.ml_line_count;
    if (lastp != NULL)
        *lastp = last;
    if (firstp != NULL)
        *firstp = first;
    if (infop != NULL) {
        infop->fi_level = level + 1;
        infop->fi_lnum = first;
        infop->fi_low_level = low_level == 0 ? level + 1 : low_level;
    }
    return TRUE;
}

static void checkupdate (win_T *wp) {
    if (wp->w_foldinvalid) {
        foldUpdate (wp, (linenr_T) 1, (linenr_T) MAXLNUM);
        wp->w_foldinvalid = FALSE;
    }
}

void foldUpdate (win_T *wp, linenr_T top, linenr_T bot) {
    fold_T *fp;
    if (disable_fold_update > 0)
        return;
    (void) foldFind (&wp->w_folds, top, &fp);
    while (fp < (fold_T *) wp->w_folds.ga_data + wp->w_folds.ga_len && fp->fd_top < bot) {
        fp->fd_small = MAYBE;
        ++fp;
    }
    if (foldmethodIsIndent (wp) || foldmethodIsExpr (wp) || foldmethodIsMarker (wp) || foldmethodIsDiff (wp) || foldmethodIsSyntax (wp)) {
        int save_got_int = got_int;
        got_int = FALSE;
        foldUpdateIEMS (wp, top, bot);
        got_int |= save_got_int;
    }
}

static int foldFind (garray_T *gap, linenr_T lnum, fold_T **fpp) {
    linenr_T low, high;
    fold_T *fp;
    int i;
    fp = (fold_T *) gap->ga_data;
    low = 0;
    high = gap->ga_len - 1;
    while (low <= high) {
        i = (low + high) / 2;
        if (fp[i].fd_top > lnum)
            high = i - 1;
        else if (fp[i].fd_top + fp[i].fd_len <= lnum)
            low = i + 1;
        else {
            *fpp = fp + i;
            return TRUE;
        }
    }
    *fpp = fp + low;
    return FALSE;
}

int foldmethodIsIndent (win_T *wp) {
    return (wp->w_p_fdm[0] == 'i');
}

int foldmethodIsExpr (win_T *wp) {
    return (wp->w_p_fdm[1] == 'x');
}

int foldmethodIsMarker (win_T *wp) {
    return (wp->w_p_fdm[2] == 'r');
}

int foldmethodIsDiff (win_T *wp) {
    return (wp->w_p_fdm[0] == 'd');
}

int foldmethodIsSyntax (win_T *wp) {
    return (wp->w_p_fdm[0] == 's');
}

static void foldUpdateIEMS (win_T *wp, linenr_T top, linenr_T bot) {
    linenr_T start;
    linenr_T end;
    fline_T fline;
    void (*getlevel) (fline_T *);
    int level;
    fold_T *fp;
    if (invalid_top != (linenr_T) 0)
        return;
    if (wp->w_foldinvalid) {
        top = 1;
        bot = wp->w_buffer->b_ml.ml_line_count;
        wp->w_foldinvalid = FALSE;
        setSmallMaybe (& wp -> w_folds);
    }
    if (foldmethodIsDiff (wp)) {
        if (top > diff_context)
            top -= diff_context;
        else
            top = 1;
        bot += diff_context;
    }
    if (top > wp->w_buffer->b_ml.ml_line_count)
        top = wp->w_buffer->b_ml.ml_line_count;
    fold_changed = FALSE;
    fline.wp = wp;
    fline.off = 0;
    fline.lvl = 0;
    fline.lvl_next = -1;
    fline.start = 0;
    fline.end = MAX_LEVEL + 1;
    fline.had_end = MAX_LEVEL + 1;
    invalid_top = top;
    invalid_bot = bot;
    if (foldmethodIsMarker (wp)) {
        getlevel = foldlevelMarker;
        parseMarker (wp);
        if (top > 1) {
            level = foldLevelWin (wp, top -1);
            fline.lnum = top - 1;
            fline.lvl = level;
            getlevel (& fline);
            if (fline.lvl > level)
                fline.lvl = level - (fline.lvl - fline.lvl_next);
            else
                fline.lvl = fline.lvl_next;
        }
        fline.lnum = top;
        getlevel (& fline);
    }
    else {
        fline.lnum = top;
        if (foldmethodIsExpr (wp)) {
            getlevel = foldlevelExpr;
            if (top > 1)
                --fline.lnum;
        }
        else if (foldmethodIsSyntax (wp))
            getlevel = foldlevelSyntax;
        else if (foldmethodIsDiff (wp))
            getlevel = foldlevelDiff;
        else
            getlevel = foldlevelIndent;
        fline.lvl = -1;
        for (; !got_int; --fline.lnum) {
            fline.lvl_next = -1;
            getlevel (& fline);
            if (fline.lvl >= 0)
                break;
        }
    }
    if (foldlevelSyntax == getlevel) {
        garray_T *gap = &wp->w_folds;
        fold_T *fpn = NULL;
        int current_fdl = 0;
        linenr_T fold_start_lnum = 0;
        linenr_T lnum_rel = fline.lnum;
        while (current_fdl < fline.lvl) {
            if (!foldFind (gap, lnum_rel, &fpn))
                break;
            ++current_fdl;
            fold_start_lnum += fpn->fd_top;
            gap = &fpn->fd_nested;
            lnum_rel -= fpn->fd_top;
        }
        if (fpn != NULL && current_fdl == fline.lvl) {
            linenr_T fold_end_lnum = fold_start_lnum + fpn->fd_len;
            if (fold_end_lnum > bot)
                bot = fold_end_lnum;
        }
    }
    start = fline.lnum;
    end = bot;
    if (start > end && end < wp->w_buffer->b_ml.ml_line_count)
        end = start;
    while (!got_int) {
        if (fline.lnum > wp->w_buffer->b_ml.ml_line_count)
            break;
        if (fline.lnum > end) {
            if (getlevel != foldlevelMarker && getlevel != foldlevelSyntax && getlevel != foldlevelExpr)
                break;
            if ((start <= end && foldFind (&wp->w_folds, end, &fp) && fp->fd_top + fp->fd_len - 1 > end) || (fline.lvl == 0 && foldFind (&wp->w_folds, fline.lnum, &fp) && fp->fd_top < fline.lnum))
                end = fp->fd_top + fp->fd_len - 1;
            else if (getlevel == foldlevelSyntax && foldLevelWin (wp, fline.lnum) != fline.lvl)
                end = fline.lnum;
            else
                break;
        }
        if (fline.lvl > 0) {
            invalid_top = fline.lnum;
            invalid_bot = end;
            end = foldUpdateIEMSRecurse (&wp->w_folds, 1, start, &fline, getlevel, end, FD_LEVEL);
            start = fline.lnum;
        }
        else {
            if (fline.lnum == wp->w_buffer->b_ml.ml_line_count)
                break;
            ++fline.lnum;
            fline.lvl = fline.lvl_next;
            getlevel (& fline);
        }
    }
    foldRemove (& wp -> w_folds, start, end);
    if (fold_changed && wp->w_p_fen)
        changed_window_setting_win (wp);
    if (end != bot) {
        if (wp->w_redraw_top == 0 || wp->w_redraw_top > top)
            wp->w_redraw_top = top;
        if (wp->w_redraw_bot < end)
            wp->w_redraw_bot = end;
    }
    invalid_top = (linenr_T) 0;
}

static void setSmallMaybe (garray_T *gap) {
    int i;
    fold_T *fp;
    fp = (fold_T *) gap->ga_data;
    for (i = 0; i < gap->ga_len; ++i)
        fp[i].fd_small = MAYBE;
}

static void foldlevelMarker (fline_T *flp) {
    char_u *startmarker;
    int cstart;
    int cend;
    int start_lvl = flp->lvl;
    char_u *s;
    int n;
    startmarker = flp->wp->w_p_fmr;
    cstart = *startmarker;
    ++startmarker;
    cend = *foldendmarker;
    flp->start = 0;
    flp->lvl_next = flp->lvl;
    s = ml_get_buf (flp->wp->w_buffer, flp->lnum + flp->off, FALSE);
    while (*s) {
        if (*s == cstart && STRNCMP (s +1, startmarker, foldstartmarkerlen -1) == 0) {
            s += foldstartmarkerlen;
            if (VIM_ISDIGIT (*s)) {
                n = atoi ((char *) s);
                if (n > 0) {
                    flp->lvl = n;
                    flp->lvl_next = n;
                    if (n <= start_lvl)
                        flp->start = 1;
                    else
                        flp->start = n - start_lvl;
                }
            }
            else {
                ++flp->lvl;
                ++flp->lvl_next;
                ++flp->start;
            }
        }
        else if (*s == cend && STRNCMP (s +1, foldendmarker +1, foldendmarkerlen -1) == 0) {
            s += foldendmarkerlen;
            if (VIM_ISDIGIT (*s)) {
                n = atoi ((char *) s);
                if (n > 0) {
                    flp->lvl = n;
                    flp->lvl_next = n - 1;
                    if (flp->lvl_next > start_lvl)
                        flp->lvl_next = start_lvl;
                }
            }
            else
                --flp->lvl_next;
        }
        else
            MB_PTR_ADV (s);
    }
    if (flp->lvl_next < 0)
        flp->lvl_next = 0;
}

int hasAnyFolding (win_T *win) {
    return (win->w_p_fen && (!foldmethodIsManual (win) || win->w_folds.ga_len > 0));
}

int foldmethodIsManual (win_T *wp) {
    return (wp->w_p_fdm[3] == 'u');
}

void deleteFoldRecurse (garray_T *gap) {
    int i;
    for (i = 0; i < gap->ga_len; ++i)
        deleteFoldRecurse (&(((fold_T *) (gap->ga_data))[i].fd_nested));
    ga_clear (gap);
}

void cloneFoldGrowArray (garray_T *from, garray_T *to) {
    int i;
    fold_T *from_p;
    fold_T *to_p;
    ga_init2 (to, from -> ga_itemsize, from -> ga_growsize);
    if (from->ga_len == 0 || ga_grow (to, from->ga_len) == FAIL)
        return;
    from_p = (fold_T *) from->ga_data;
    to_p = (fold_T *) to->ga_data;
    for (i = 0; i < from->ga_len; i++) {
        to_p->fd_top = from_p->fd_top;
        to_p->fd_len = from_p->fd_len;
        to_p->fd_flags = from_p->fd_flags;
        to_p->fd_small = from_p->fd_small;
        cloneFoldGrowArray (& from_p -> fd_nested, & to_p -> fd_nested);
        ++to->ga_len;
        ++from_p;
        ++to_p;
    }
}

void foldUpdateAll (win_T *win) {
    win->w_foldinvalid = TRUE;
    redraw_win_later (win, NOT_VALID);
}

int lineFolded (win_T *win, linenr_T lnum) {
    return foldedCount (win, lnum, NULL) != 0;
}

long  foldedCount (win_T *win, linenr_T lnum, foldinfo_T *infop) {
    linenr_T last;
    if (hasFoldingWin (win, lnum, NULL, &last, FALSE, infop))
        return (long ) (last - lnum + 1);
    return 0;
}

void clearFolding (win_T *win) {
    deleteFoldRecurse (& win -> w_folds);
    win->w_foldinvalid = FALSE;
}

void foldInitWin (win_T *new_win) {
    ga_init2 (& new_win -> w_folds, (int) sizeof (fold_T), 10);
}

void copyFoldingState (win_T *wp_from, win_T *wp_to) {
    wp_to->w_fold_manual = wp_from->w_fold_manual;
    wp_to->w_foldinvalid = wp_from->w_foldinvalid;
    cloneFoldGrowArray (& wp_from -> w_folds, & wp_to -> w_folds);
}

void newFoldLevel (void) {
    newFoldLevelWin (curwin);
    if (foldmethodIsDiff (curwin) && curwin->w_p_scb) {
        win_T *wp;
        FOR_ALL_WINDOWS (wp) {
            if (wp != curwin && foldmethodIsDiff (wp) && wp->w_p_scb) {
                wp->w_p_fdl = curwin->w_p_fdl;
                newFoldLevelWin (wp);
            }
        }
    }
}

static void newFoldLevelWin (win_T *wp) {
    fold_T *fp;
    int i;
    checkupdate (wp);
    if (wp->w_fold_manual) {
        fp = (fold_T *) wp->w_folds.ga_data;
        for (i = 0; i < wp->w_folds.ga_len; ++i)
            fp[i].fd_flags = FD_LEVEL;
        wp->w_fold_manual = FALSE;
    }
    changed_window_setting_win (wp);
}

void foldOpenCursor (void) {
    int done;
    checkupdate (curwin);
    if (hasAnyFolding (curwin))
        for (;;) {
            done = DONE_NOTHING;
            (void) setManualFold (curwin->w_cursor.lnum, TRUE, FALSE, &done);
            if (!(done & DONE_ACTION))
                break;
        }
}

static linenr_T setManualFold (linenr_T lnum, int opening, int recurse, int *donep) {
    if (foldmethodIsDiff (curwin) && curwin->w_p_scb) {
        win_T *wp;
        linenr_T dlnum;
        FOR_ALL_WINDOWS (wp) {
            if (wp != curwin && foldmethodIsDiff (wp) && wp->w_p_scb) {
                dlnum = diff_lnum_win (curwin->w_cursor.lnum, wp);
                if (dlnum != 0)
                    (void) setManualFoldWin (wp, dlnum, opening, recurse, NULL);
            }
        }
    }
    return setManualFoldWin (curwin, lnum, opening, recurse, donep);
}

static linenr_T setManualFoldWin (win_T *wp, linenr_T lnum, int opening, int recurse, int *donep) {
    fold_T *fp;
    fold_T *fp2;
    fold_T *found = NULL;
    int j;
    int level = 0;
    int use_level = FALSE;
    int found_fold = FALSE;
    garray_T *gap;
    linenr_T next = MAXLNUM;
    linenr_T off = 0;
    int done = 0;
    checkupdate (wp);
    gap = &wp->w_folds;
    for (;;) {
        if (!foldFind (gap, lnum, &fp)) {
            if (fp < (fold_T *) gap->ga_data + gap->ga_len)
                next = fp->fd_top + off;
            break;
        }
        found_fold = TRUE;
        if (fp + 1 < (fold_T *) gap->ga_data + gap->ga_len)
            next = fp[1].fd_top + off;
        if (use_level || fp->fd_flags == FD_LEVEL) {
            use_level = TRUE;
            if (level >= wp->w_p_fdl)
                fp->fd_flags = FD_CLOSED;
            else
                fp->fd_flags = FD_OPEN;
            fp2 = (fold_T *) fp->fd_nested.ga_data;
            for (j = 0; j < fp->fd_nested.ga_len; ++j)
                fp2[j].fd_flags = FD_LEVEL;
        }
        if (!opening && recurse) {
            if (fp->fd_flags != FD_CLOSED) {
                done |= DONE_ACTION;
                fp->fd_flags = FD_CLOSED;
            }
        }
        else if (fp->fd_flags == FD_CLOSED) {
            if (opening) {
                fp->fd_flags = FD_OPEN;
                done |= DONE_ACTION;
                if (recurse)
                    foldOpenNested (fp);
            }
            break;
        }
        found = fp;
        gap = &fp->fd_nested;
        lnum -= fp->fd_top;
        off += fp->fd_top;
        ++level;
    }
    if (found_fold) {
        if (!opening && found != NULL) {
            found->fd_flags = FD_CLOSED;
            done |= DONE_ACTION;
        }
        wp->w_fold_manual = TRUE;
        if (done & DONE_ACTION)
            changed_window_setting_win (wp);
        done |= DONE_FOLD;
    }
    else if (donep == NULL && wp == curwin)
        EMSG (_ (e_nofold));
    if (donep != NULL)
        *donep |= done;
    return next;
}

static void foldOpenNested (fold_T *fpr) {
    int i;
    fold_T *fp;
    fp = (fold_T *) fpr->fd_nested.ga_data;
    for (i = 0; i < fpr->fd_nested.ga_len; ++i) {
        foldOpenNested (& fp [i]);
        fp[i].fd_flags = FD_OPEN;
    }
}

int find_wl_entry (win_T *win, linenr_T lnum) {
    int i;
    for (i = 0; i < win->w_lines_valid; ++i)
        if (win->w_lines[i].wl_valid) {
            if (lnum < win->w_lines[i].wl_lnum)
                return -1;
            if (lnum <= win->w_lines[i].wl_lastlnum)
                return i;
        }
    return -1;
}

void foldMarkAdjust (win_T *wp, linenr_T line1, linenr_T line2, long  amount, long  amount_after) {
    if (amount == MAXLNUM && line2 >= line1 && line2 - line1 >= -amount_after)
        line2 = line1 - amount_after - 1;
    if ((State & INSERT) && amount == (linenr_T) 1 && line2 == MAXLNUM)
        --line1;
    foldMarkAdjustRecurse (& wp -> w_folds, line1, line2, amount, amount_after);
}

static void foldMarkAdjustRecurse (garray_T *gap, linenr_T line1, linenr_T line2, long  amount, long  amount_after) {
    fold_T *fp;
    int i;
    linenr_T last;
    linenr_T top;
    if ((State & INSERT) && amount == (linenr_T) 1 && line2 == MAXLNUM)
        top = line1 + 1;
    else
        top = line1;
    (void) foldFind (gap, line1, &fp);
    for (i = (int) (fp - (fold_T *) gap->ga_data); i < gap->ga_len; ++i, ++fp) {
        last = fp->fd_top + fp->fd_len - 1;
        if (last < line1)
            continue;
        if (fp->fd_top > line2) {
            if (amount_after == 0)
                break;
            fp->fd_top += amount_after;
        }
        else {
            if (fp->fd_top >= top && last <= line2) {
                if (amount == MAXLNUM) {
                    deleteFoldEntry (gap, i, TRUE);
                    --i;
                    --fp;
                }
                else
                    fp->fd_top += amount;
            }
            else {
                if (fp->fd_top < top) {
                    foldMarkAdjustRecurse (& fp -> fd_nested, line1 - fp -> fd_top, line2 - fp -> fd_top, amount, amount_after);
                    if (last <= line2) {
                        if (amount == MAXLNUM)
                            fp->fd_len = line1 - fp->fd_top;
                        else
                            fp->fd_len += amount;
                    }
                    else {
                        fp->fd_len += amount_after;
                    }
                }
                else {
                    if (amount == MAXLNUM) {
                        foldMarkAdjustRecurse (& fp -> fd_nested, line1 - fp -> fd_top, line2 - fp -> fd_top, amount, amount_after + (fp -> fd_top - top));
                        fp->fd_len -= line2 - fp->fd_top + 1;
                        fp->fd_top = line1;
                    }
                    else {
                        foldMarkAdjustRecurse (& fp -> fd_nested, line1 - fp -> fd_top, line2 - fp -> fd_top, amount, amount_after - amount);
                        fp->fd_len += amount_after - amount;
                        fp->fd_top += amount;
                    }
                }
            }
        }
    }
}

static void deleteFoldEntry (garray_T *gap, int idx, int recursive) {
    fold_T *fp;
    int i;
    long  moved;
    fold_T *nfp;
    fp = (fold_T *) gap->ga_data + idx;
    if (recursive || fp->fd_nested.ga_len == 0) {
        deleteFoldRecurse (& fp -> fd_nested);
        --gap->ga_len;
        if (idx < gap->ga_len)
            mch_memmove (fp, fp +1, sizeof (fold_T) * (gap->ga_len - idx));
    }
    else {
        moved = fp->fd_nested.ga_len;
        if (ga_grow (gap, (int) (moved - 1)) == OK) {
            fp = (fold_T *) gap->ga_data + idx;
            nfp = (fold_T *) fp->fd_nested.ga_data;
            for (i = 0; i < moved; ++i) {
                nfp[i].fd_top += fp->fd_top;
                if (fp->fd_flags == FD_LEVEL)
                    nfp[i].fd_flags = FD_LEVEL;
                if (fp->fd_small == MAYBE)
                    nfp[i].fd_small = MAYBE;
            }
            if (idx + 1 < gap->ga_len)
                mch_memmove (fp +moved, fp +1, sizeof (fold_T) * (gap->ga_len - (idx + 1)));
            mch_memmove (fp, nfp, (size_t) (sizeof (fold_T) * moved));
            vim_free (nfp);
            gap->ga_len += moved - 1;
        }
    }
}

char_u *get_foldtext (win_T *wp, linenr_T lnum, linenr_T lnume, foldinfo_T *foldinfo, char_u *buf) {
    char_u *text = NULL;
    static int got_fdt_error = FALSE;
    int save_did_emsg = did_emsg;
    static win_T *last_wp = NULL;
    static linenr_T last_lnum = 0;
    if (last_wp != wp || last_wp == NULL || last_lnum > lnum || last_lnum == 0)
        got_fdt_error = FALSE;
    if (!got_fdt_error)
        did_emsg = FALSE;
    if (*wp->w_p_fdt != NUL) {
        char_u dashes [MAX_LEVEL + 2];
        win_T *save_curwin;
        int level;
        char_u *p;
        set_vim_var_nr (VV_FOLDSTART, lnum);
        set_vim_var_nr (VV_FOLDEND, lnume);
        level = foldinfo->fi_level;
        if (level > (int) sizeof (dashes) - 1)
            level = (int) sizeof (dashes) - 1;
        vim_memset (dashes, '-', (size_t) level);
        dashes[level] = NUL;
        set_vim_var_string (VV_FOLDDASHES, dashes, - 1);
        set_vim_var_nr (VV_FOLDLEVEL, (long) level);
        if (!got_fdt_error) {
            save_curwin = curwin;
            curwin = wp;
            curbuf = wp->w_buffer;
            ++emsg_silent;
            text = eval_to_string_safe (wp->w_p_fdt, NULL, was_set_insecurely ((char_u *) "foldtext", OPT_LOCAL));
            --emsg_silent;
            if (text == NULL || did_emsg)
                got_fdt_error = TRUE;
            curwin = save_curwin;
            curbuf = curwin->w_buffer;
        }
        last_lnum = lnum;
        last_wp = wp;
        set_vim_var_string (VV_FOLDDASHES, NULL, - 1);
        if (!did_emsg && save_did_emsg)
            did_emsg = save_did_emsg;
        if (text != NULL) {
            for (p = text; *p != NUL; ++p) {
                if (*p == TAB)
                    *p = ' ';
                else if (ptr2cells (p) > 1)
                    break;
            }
            if (*p != NUL) {
                p = transstr (text);
                vim_free (text);
                text = p;
            }
        }
    }
    if (text == NULL) {
        long  count = (long ) (lnume - lnum + 1);
        vim_snprintf ((char *) buf, FOLD_TEXT_LEN, NGETTEXT ("+--%3ld line folded ", "+--%3ld lines folded ", count), count);
        text = buf;
    }
    return text;
}

void foldAdjustVisual (void) {
    pos_T *start, *end;
    char_u *ptr;
    if (!VIsual_active || !hasAnyFolding (curwin))
        return;
    if (LTOREQ_POS (VIsual, curwin->w_cursor)) {
        start = &VIsual;
        end = &curwin->w_cursor;
    }
    else {
        start = &curwin->w_cursor;
        end = &VIsual;
    }
    if (hasFolding (start->lnum, &start->lnum, NULL))
        start->col = 0;
    if (hasFolding (end->lnum, NULL, &end->lnum)) {
        ptr = ml_get (end->lnum);
        end->col = (colnr_T) STRLEN (ptr);
        if (end->col > 0 && *p_sel == 'o')
            --end->col;
    }
}

void foldCheckClose (void) {
    if (*p_fcl != NUL) {
        checkupdate (curwin);
        if (checkCloseRec (&curwin->w_folds, curwin->w_cursor.lnum, (int) curwin->w_p_fdl))
            changed_window_setting ();
    }
}

static int checkCloseRec (garray_T *gap, linenr_T lnum, int level) {
    fold_T *fp;
    int retval = FALSE;
    int i;
    fp = (fold_T *) gap->ga_data;
    for (i = 0; i < gap->ga_len; ++i) {
        if (fp[i].fd_flags == FD_OPEN) {
            if (level <= 0 && (lnum < fp[i].fd_top || lnum >= fp[i].fd_top + fp[i].fd_len)) {
                fp[i].fd_flags = FD_LEVEL;
                retval = TRUE;
            }
            else
                retval |= checkCloseRec (&fp[i].fd_nested, lnum -fp[i].fd_top, level -1);
        }
    }
    return retval;
}

void openFold (linenr_T lnum, long  count) {
    setFoldRepeat (lnum, count, TRUE);
}

static void setFoldRepeat (linenr_T lnum, long  count, int do_open) {
    int done;
    long  n;
    for (n = 0; n < count; ++n) {
        done = DONE_NOTHING;
        (void) setManualFold (lnum, do_open, FALSE, &done);
        if (!(done & DONE_ACTION)) {
            if (n == 0 && !(done & DONE_FOLD))
                EMSG (_ (e_nofold));
            break;
        }
    }
}

void closeFold (linenr_T lnum, long  count) {
    setFoldRepeat (lnum, count, FALSE);
}

void foldAdjustCursor (void) {
    (void) hasFolding (curwin->w_cursor.lnum, &curwin->w_cursor.lnum, NULL);
}

void foldCreate (linenr_T start, linenr_T end) {
    fold_T *fp;
    garray_T *gap;
    garray_T fold_ga;
    int i, j;
    int cont;
    int use_level = FALSE;
    int closed = FALSE;
    int level = 0;
    linenr_T start_rel = start;
    linenr_T end_rel = end;
    if (start > end) {
        end = start_rel;
        start = end_rel;
        start_rel = start;
        end_rel = end;
    }
    if (foldmethodIsMarker (curwin)) {
        foldCreateMarkers (start, end);
        return;
    }
    checkupdate (curwin);
    gap = &curwin->w_folds;
    for (;;) {
        if (!foldFind (gap, start_rel, &fp))
            break;
        if (fp->fd_top + fp->fd_len > end_rel) {
            gap = &fp->fd_nested;
            start_rel -= fp->fd_top;
            end_rel -= fp->fd_top;
            if (use_level || fp->fd_flags == FD_LEVEL) {
                use_level = TRUE;
                if (level >= curwin->w_p_fdl)
                    closed = TRUE;
            }
            else if (fp->fd_flags == FD_CLOSED)
                closed = TRUE;
            ++level;
        }
        else {
            break;
        }
    }
    i = (int) (fp - (fold_T *) gap->ga_data);
    if (ga_grow (gap, 1) == OK) {
        fp = (fold_T *) gap->ga_data + i;
        ga_init2 (& fold_ga, (int) sizeof (fold_T), 10);
        for (cont = 0; i + cont < gap->ga_len; ++cont)
            if (fp[cont].fd_top > end_rel)
                break;
        if (cont > 0 && ga_grow (&fold_ga, cont) == OK) {
            if (start_rel > fp->fd_top)
                start_rel = fp->fd_top;
            if (end_rel < fp[cont - 1].fd_top + fp[cont - 1].fd_len - 1)
                end_rel = fp[cont - 1].fd_top + fp[cont - 1].fd_len - 1;
            mch_memmove (fold_ga.ga_data, fp, sizeof (fold_T) * cont);
            fold_ga.ga_len += cont;
            i += cont;
            for (j = 0; j < cont; ++j)
                ((fold_T *) fold_ga.ga_data)[j].fd_top -= start_rel;
        }
        if (i < gap->ga_len)
            mch_memmove (fp +1, (fold_T *) gap->ga_data + i, sizeof (fold_T) * (gap->ga_len - i));
        gap->ga_len = gap->ga_len + 1 - cont;
        fp->fd_nested = fold_ga;
        fp->fd_top = start_rel;
        fp->fd_len = end_rel - start_rel + 1;
        if (use_level && !closed && level < curwin->w_p_fdl)
            closeFold (start, 1L);
        if (!use_level)
            curwin->w_fold_manual = TRUE;
        fp->fd_flags = FD_CLOSED;
        fp->fd_small = MAYBE;
        changed_window_setting ();
    }
}

static void foldCreateMarkers (linenr_T start, linenr_T end) {
    if (!curbuf->b_p_ma) {
        EMSG (_ (e_modifiable));
        return;
    }
    parseMarker (curwin);
    foldAddMarker (start, curwin -> w_p_fmr, foldstartmarkerlen);
    foldAddMarker (end, foldendmarker, foldendmarkerlen);
    changed_lines (start, (colnr_T) 0, end, 0L);
}

static void parseMarker (win_T *wp) {
    foldendmarker = vim_strchr (wp->w_p_fmr, ',');
    foldstartmarkerlen = (int) (foldendmarker++ - wp->w_p_fmr);
    foldendmarkerlen = (int) STRLEN (foldendmarker);
}

static void foldAddMarker (linenr_T lnum, char_u *marker, int markerlen) {
    char_u *cms = curbuf->b_p_cms;
    char_u *line;
    int line_len;
    char_u *newline;
    char_u *p = (char_u *) strstr ((char *) curbuf->b_p_cms, "%s");
    int line_is_comment = FALSE;
    line = ml_get (lnum);
    line_len = (int) STRLEN (line);
    if (u_save (lnum -1, lnum +1) == OK) {
        (void) skip_comment (line, FALSE, FALSE, &line_is_comment);
        newline = alloc ((unsigned ) (line_len + markerlen + STRLEN (cms) + 1));
        if (newline == NULL)
            return;
        STRCPY (newline, line);
        if (p == NULL || line_is_comment)
            vim_strncpy (newline +line_len, marker, markerlen);
        else {
            STRCPY (newline + line_len, cms);
            STRNCPY (newline + line_len + (p - cms), marker, markerlen);
            STRCPY (newline + line_len + (p - cms) + markerlen, p + 2);
        }
        ml_replace (lnum, newline, FALSE);
    }
}

void opFoldRange (linenr_T first, linenr_T last, int opening, int recurse, int had_visual) {
    int done = DONE_NOTHING;
    linenr_T lnum;
    linenr_T lnum_next;
    for (lnum = first; lnum <= last; lnum = lnum_next + 1) {
        lnum_next = lnum;
        if (opening && !recurse)
            (void) hasFolding (lnum, NULL, &lnum_next);
        (void) setManualFold (lnum, opening, recurse, &done);
        if (!opening && !recurse)
            (void) hasFolding (lnum, NULL, &lnum_next);
    }
    if (done == DONE_NOTHING)
        EMSG (_ (e_nofold));
    if (had_visual)
        redraw_curbuf_later (INVERTED);
}

void deleteFold (linenr_T start, linenr_T end, int recursive, int had_visual) {
    garray_T *gap;
    fold_T *fp;
    garray_T *found_ga;
    fold_T *found_fp = NULL;
    linenr_T found_off = 0;
    int use_level;
    int maybe_small = FALSE;
    int level = 0;
    linenr_T lnum = start;
    linenr_T lnum_off;
    int did_one = FALSE;
    linenr_T first_lnum = MAXLNUM;
    linenr_T last_lnum = 0;
    checkupdate (curwin);
    while (lnum <= end) {
        gap = &curwin->w_folds;
        found_ga = NULL;
        lnum_off = 0;
        use_level = FALSE;
        for (;;) {
            if (!foldFind (gap, lnum -lnum_off, &fp))
                break;
            found_ga = gap;
            found_fp = fp;
            found_off = lnum_off;
            if (check_closed (curwin, fp, &use_level, level, &maybe_small, lnum_off))
                break;
            gap = &fp->fd_nested;
            lnum_off += fp->fd_top;
            ++level;
        }
        if (found_ga == NULL) {
            ++lnum;
        }
        else {
            lnum = found_fp->fd_top + found_fp->fd_len + found_off;
            if (foldmethodIsManual (curwin))
                deleteFoldEntry (found_ga, (int) (found_fp - (fold_T *) found_ga->ga_data), recursive);
            else {
                if (first_lnum > found_fp->fd_top + found_off)
                    first_lnum = found_fp->fd_top + found_off;
                if (last_lnum < lnum)
                    last_lnum = lnum;
                if (!did_one)
                    parseMarker (curwin);
                deleteFoldMarkers (found_fp, recursive, found_off);
            }
            did_one = TRUE;
            changed_window_setting ();
        }
    }
    if (!did_one) {
        EMSG (_ (e_nofold));
        if (had_visual)
            redraw_curbuf_later (INVERTED);
    }
    else
        check_cursor_col ();
    if (last_lnum > 0)
        changed_lines (first_lnum, (colnr_T) 0, last_lnum, 0L);
}

static int check_closed (win_T *win, fold_T *fp, int *use_levelp, int level, int *maybe_smallp, linenr_T lnum_off) {
    int closed = FALSE;
    if (*use_levelp || fp->fd_flags == FD_LEVEL) {
        *use_levelp = TRUE;
        if (level >= win->w_p_fdl)
            closed = TRUE;
    }
    else if (fp->fd_flags == FD_CLOSED)
        closed = TRUE;
    if (fp->fd_small == MAYBE)
        *maybe_smallp = TRUE;
    if (closed) {
        if (*maybe_smallp)
            fp->fd_small = MAYBE;
        checkSmall (win, fp, lnum_off);
        if (fp->fd_small == TRUE)
            closed = FALSE;
    }
    return closed;
}

static void checkSmall (win_T *wp, fold_T *fp, linenr_T lnum_off) {
    int count;
    int n;
    if (fp->fd_small == MAYBE) {
        setSmallMaybe (& fp -> fd_nested);
        if (fp->fd_len > curwin->w_p_fml)
            fp->fd_small = FALSE;
        else {
            count = 0;
            for (n = 0; n < fp->fd_len; ++n) {
                count += plines_win_nofold (wp, fp->fd_top + lnum_off + n);
                if (count > curwin->w_p_fml) {
                    fp->fd_small = FALSE;
                    return;
                }
            }
            fp->fd_small = TRUE;
        }
    }
}

static void deleteFoldMarkers (fold_T *fp, int recursive, linenr_T lnum_off) {
    int i;
    if (recursive)
        for (i = 0; i < fp->fd_nested.ga_len; ++i)
            deleteFoldMarkers ((fold_T *) fp->fd_nested.ga_data + i, TRUE, lnum_off +fp->fd_top);
    foldDelMarker (fp -> fd_top + lnum_off, curwin -> w_p_fmr, foldstartmarkerlen);
    foldDelMarker (fp -> fd_top + lnum_off + fp -> fd_len - 1, foldendmarker, foldendmarkerlen);
}

static void foldDelMarker (linenr_T lnum, char_u *marker, int markerlen) {
    char_u *line;
    char_u *newline;
    char_u *p;
    int len;
    char_u *cms = curbuf->b_p_cms;
    char_u *cms2;
    line = ml_get (lnum);
    for (p = line; *p != NUL; ++p)
        if (STRNCMP (p, marker, markerlen) == 0) {
            len = markerlen;
            if (VIM_ISDIGIT (p[len]))
                ++len;
            if (*cms != NUL) {
                cms2 = (char_u *) strstr ((char *) cms, "%s");
                if (p - line >= cms2 - cms && STRNCMP (p -(cms2 - cms), cms, cms2 -cms) == 0 && STRNCMP (p +len, cms2 +2, STRLEN (cms2 + 2)) == 0) {
                    p -= cms2 - cms;
                    len += (int) STRLEN (cms) - 2;
                }
            }
            if (u_save (lnum -1, lnum +1) == OK) {
                newline = alloc ((unsigned ) (STRLEN (line) - len + 1));
                if (newline != NULL) {
                    STRNCPY (newline, line, p - line);
                    STRCPY (newline + (p - line), p + len);
                    ml_replace (lnum, newline, FALSE);
                }
            }
            break;
        }
}

static int foldLevelWin (win_T *wp, linenr_T lnum) {
    fold_T *fp;
    linenr_T lnum_rel = lnum;
    int level = 0;
    garray_T *gap;
    gap = &wp->w_folds;
    for (;;) {
        if (!foldFind (gap, lnum_rel, &fp))
            break;
        gap = &fp->fd_nested;
        lnum_rel -= fp->fd_top;
        ++level;
    }
    return level;
}

static void foldlevelExpr (fline_T *flp) {
    win_T *win;
    int n;
    int c;
    linenr_T lnum = flp->lnum + flp->off;
    int save_keytyped;
    win = curwin;
    curwin = flp->wp;
    curbuf = flp->wp->w_buffer;
    set_vim_var_nr (VV_LNUM, lnum);
    flp->start = 0;
    flp->had_end = flp->end;
    flp->end = MAX_LEVEL + 1;
    if (lnum <= 1)
        flp->lvl = 0;
    save_keytyped = KeyTyped;
    n = (int) eval_foldexpr (flp->wp->w_p_fde, &c);
    KeyTyped = save_keytyped;
    switch (c) {
    case 'a' :
        if (flp->lvl >= 0) {
            flp->lvl += n;
            flp->lvl_next = flp->lvl;
        }
        flp->start = n;
        break;
    case 's' :
        if (flp->lvl >= 0) {
            if (n > flp->lvl)
                flp->lvl_next = 0;
            else
                flp->lvl_next = flp->lvl - n;
            flp->end = flp->lvl_next + 1;
        }
        break;
    case '>' :
        flp->lvl = n;
        flp->lvl_next = n;
        flp->start = 1;
        break;
    case '<' :
        flp->lvl_next = n - 1;
        flp->end = n;
        break;
    case '=' :
        flp->lvl_next = flp->lvl;
        break;
    default :
        if (n < 0)
            flp->lvl_next = flp->lvl;
        else
            flp->lvl_next = n;
        flp->lvl = n;
        break;
    }
    if (flp->lvl < 0) {
        if (lnum <= 1) {
            flp->lvl = 0;
            flp->lvl_next = 0;
        }
        if (lnum == curbuf->b_ml.ml_line_count)
            flp->lvl_next = 0;
    }
    curwin = win;
    curbuf = curwin->w_buffer;
}

static void foldlevelSyntax (fline_T *flp) {
    linenr_T lnum = flp->lnum + flp->off;
    int n;
    flp->lvl = syn_get_foldlevel (flp->wp, lnum);
    flp->start = 0;
    if (lnum < flp->wp->w_buffer->b_ml.ml_line_count) {
        n = syn_get_foldlevel (flp->wp, lnum +1);
        if (n > flp->lvl) {
            flp->start = n - flp->lvl;
            flp->lvl = n;
        }
    }
}

static void foldlevelDiff (fline_T *flp) {
    if (diff_infold (flp->wp, flp->lnum + flp->off))
        flp->lvl = 1;
    else
        flp->lvl = 0;
}

static void foldlevelIndent (fline_T *flp) {
    char_u *s;
    buf_T *buf;
    linenr_T lnum = flp->lnum + flp->off;
    buf = flp->wp->w_buffer;
    s = skipwhite (ml_get_buf (buf, lnum, FALSE));
    if (*s == NUL || vim_strchr (flp->wp->w_p_fdi, *s) != NULL) {
        if (lnum == 1 || lnum == buf->b_ml.ml_line_count)
            flp->lvl = 0;
        else
            flp->lvl = -1;
    }
    else
        flp->lvl = get_indent_buf (buf, lnum) / get_sw_value (curbuf);
    if (flp->lvl > flp->wp->w_p_fdn) {
        flp->lvl = flp->wp->w_p_fdn;
        if (flp->lvl < 0)
            flp->lvl = 0;
    }
}

static linenr_T foldUpdateIEMSRecurse (garray_T *gap, int level, linenr_T startlnum, fline_T *flp, void (*getlevel) (fline_T *), linenr_T bot, int topflags) {
    linenr_T ll;
    fold_T *fp = NULL;
    fold_T *fp2;
    int lvl = level;
    linenr_T startlnum2 = startlnum;
    linenr_T firstlnum = flp->lnum;
    int i;
    int finish = FALSE;
    linenr_T linecount = flp->wp->w_buffer->b_ml.ml_line_count - flp->off;
    int concat;
    if (getlevel == foldlevelMarker && flp->start <= flp->lvl - level && flp->lvl > 0) {
        (void) foldFind (gap, startlnum -1, &fp);
        if (fp >= ((fold_T *) gap->ga_data) + gap->ga_len || fp->fd_top >= startlnum)
            fp = NULL;
    }
    flp->lnum_save = flp->lnum;
    while (!got_int) {
        line_breakcheck ();
        lvl = flp->lvl;
        if (lvl > MAX_LEVEL)
            lvl = MAX_LEVEL;
        if (flp->lnum > firstlnum && (level > lvl - flp->start || level >= flp->had_end))
            lvl = 0;
        if (flp->lnum > bot && !finish && fp != NULL) {
            if (getlevel != foldlevelMarker && getlevel != foldlevelExpr && getlevel != foldlevelSyntax)
                break;
            i = 0;
            fp2 = fp;
            if (lvl >= level) {
                ll = flp->lnum - fp->fd_top;
                while (foldFind (&fp2->fd_nested, ll, &fp2)) {
                    ++i;
                    ll -= fp2->fd_top;
                }
            }
            if (lvl < level + i) {
                (void) foldFind (&fp->fd_nested, flp->lnum - fp->fd_top, &fp2);
                if (fp2 != NULL)
                    bot = fp2->fd_top + fp2->fd_len - 1 + fp->fd_top;
            }
            else if (fp->fd_top + fp->fd_len <= flp->lnum && lvl >= level)
                finish = TRUE;
            else
                break;
        }
        if (fp == NULL && (lvl != level || flp->lnum_save >= bot || flp->start != 0 || flp->had_end <= MAX_LEVEL || flp->lnum == linecount)) {
            while (!got_int) {
                if (flp->start != 0 || flp->had_end <= MAX_LEVEL)
                    concat = 0;
                else
                    concat = 1;
                if (foldFind (gap, startlnum, &fp) || (fp < ((fold_T *) gap->ga_data) + gap->ga_len && fp->fd_top <= firstlnum) || foldFind (gap, firstlnum -concat, &fp) || (fp < ((fold_T *) gap->ga_data) + gap->ga_len && ((lvl < level && fp->fd_top < flp->lnum) || (lvl >= level && fp->fd_top <= flp->lnum_save)))) {
                    if (fp->fd_top + fp->fd_len + concat > firstlnum) {
                        if (fp->fd_top == firstlnum) {
                        }
                        else if (fp->fd_top >= startlnum) {
                            if (fp->fd_top > firstlnum)
                                foldMarkAdjustRecurse (&fp->fd_nested, (linenr_T) 0, (linenr_T) MAXLNUM, (long ) (fp->fd_top - firstlnum), 0L);
                            else
                                foldMarkAdjustRecurse (&fp->fd_nested, (linenr_T) 0, (long ) (firstlnum - fp->fd_top - 1), (linenr_T) MAXLNUM, (long ) (fp->fd_top - firstlnum));
                            fp->fd_len += fp->fd_top - firstlnum;
                            fp->fd_top = firstlnum;
                            fold_changed = TRUE;
                        }
                        else if ((flp->start != 0 && lvl == level) || firstlnum != startlnum) {
                            linenr_T breakstart;
                            linenr_T breakend;
                            if (firstlnum != startlnum) {
                                breakstart = startlnum;
                                breakend = firstlnum;
                            }
                            else {
                                breakstart = flp->lnum;
                                breakend = flp->lnum;
                            }
                            foldRemove (& fp -> fd_nested, breakstart - fp -> fd_top, breakend - fp -> fd_top);
                            i = (int) (fp - (fold_T *) gap->ga_data);
                            foldSplit (gap, i, breakstart, breakend - 1);
                            fp = (fold_T *) gap->ga_data + i + 1;
                            if (getlevel == foldlevelMarker || getlevel == foldlevelExpr || getlevel == foldlevelSyntax)
                                finish = TRUE;
                        }
                        if (fp->fd_top == startlnum && concat) {
                            i = (int) (fp - (fold_T *) gap->ga_data);
                            if (i != 0) {
                                fp2 = fp - 1;
                                if (fp2->fd_top + fp2->fd_len == fp->fd_top) {
                                    foldMerge (fp2, gap, fp);
                                    fp = fp2;
                                }
                            }
                        }
                        break;
                    }
                    if (fp->fd_top >= startlnum) {
                        deleteFoldEntry (gap, (int) (fp - (fold_T *) gap -> ga_data), TRUE);
                    }
                    else {
                        fp->fd_len = startlnum - fp->fd_top;
                        foldMarkAdjustRecurse (& fp -> fd_nested, (linenr_T) fp -> fd_len, (linenr_T) MAXLNUM, (linenr_T) MAXLNUM, 0L);
                        fold_changed = TRUE;
                    }
                }
                else {
                    i = (int) (fp - (fold_T *) gap->ga_data);
                    if (foldInsert (gap, i) != OK)
                        return bot;
                    fp = (fold_T *) gap->ga_data + i;
                    fp->fd_top = firstlnum;
                    fp->fd_len = bot - firstlnum + 1;
                    if (topflags == FD_OPEN) {
                        flp->wp->w_fold_manual = TRUE;
                        fp->fd_flags = FD_OPEN;
                    }
                    else if (i <= 0) {
                        fp->fd_flags = topflags;
                        if (topflags != FD_LEVEL)
                            flp->wp->w_fold_manual = TRUE;
                    }
                    else
                        fp->fd_flags = (fp - 1)->fd_flags;
                    fp->fd_small = MAYBE;
                    if (getlevel == foldlevelMarker || getlevel == foldlevelExpr || getlevel == foldlevelSyntax)
                        finish = TRUE;
                    fold_changed = TRUE;
                    break;
                }
            }
        }
        if (lvl < level || flp->lnum > linecount) {
            break;
        }
        if (lvl > level && fp != NULL) {
            if (bot < flp->lnum)
                bot = flp->lnum;
            flp->lnum = flp->lnum_save - fp->fd_top;
            flp->off += fp->fd_top;
            i = (int) (fp - (fold_T *) gap->ga_data);
            bot = foldUpdateIEMSRecurse (&fp->fd_nested, level +1, startlnum2 -fp->fd_top, flp, getlevel, bot -fp->fd_top, fp->fd_flags);
            fp = (fold_T *) gap->ga_data + i;
            flp->lnum += fp->fd_top;
            flp->lnum_save += fp->fd_top;
            flp->off -= fp->fd_top;
            bot += fp->fd_top;
            startlnum2 = flp->lnum;
        }
        else {
            flp->lnum = flp->lnum_save;
            ll = flp->lnum + 1;
            while (!got_int) {
                prev_lnum = flp->lnum;
                prev_lnum_lvl = flp->lvl;
                if (++flp->lnum > linecount)
                    break;
                flp->lvl = flp->lvl_next;
                getlevel (flp);
                if (flp->lvl >= 0 || flp->had_end <= MAX_LEVEL)
                    break;
            }
            prev_lnum = 0;
            if (flp->lnum > linecount)
                break;
            flp->lnum_save = flp->lnum;
            flp->lnum = ll;
        }
    }
    if (fp == NULL)
        return bot;
    if (fp->fd_len < flp->lnum - fp->fd_top) {
        fp->fd_len = flp->lnum - fp->fd_top;
        fp->fd_small = MAYBE;
        fold_changed = TRUE;
    }
    foldRemove (& fp -> fd_nested, startlnum2 - fp -> fd_top, flp -> lnum - 1 - fp -> fd_top);
    if (lvl < level) {
        if (fp->fd_len != flp->lnum - fp->fd_top) {
            if (fp->fd_top + fp->fd_len - 1 > bot) {
                if (getlevel == foldlevelMarker || getlevel == foldlevelExpr || getlevel == foldlevelSyntax) {
                    bot = fp->fd_top + fp->fd_len - 1;
                    fp->fd_len = flp->lnum - fp->fd_top;
                }
                else {
                    i = (int) (fp - (fold_T *) gap->ga_data);
                    foldSplit (gap, i, flp -> lnum, bot);
                    fp = (fold_T *) gap->ga_data + i;
                }
            }
            else
                fp->fd_len = flp->lnum - fp->fd_top;
            fold_changed = TRUE;
        }
    }
    for (;;) {
        fp2 = fp + 1;
        if (fp2 >= (fold_T *) gap->ga_data + gap->ga_len || fp2->fd_top > flp->lnum)
            break;
        if (fp2->fd_top + fp2->fd_len > flp->lnum) {
            if (fp2->fd_top < flp->lnum) {
                foldMarkAdjustRecurse (& fp2 -> fd_nested, (linenr_T) 0, (long) (flp -> lnum - fp2 -> fd_top - 1), (linenr_T) MAXLNUM, (long) (fp2 -> fd_top - flp -> lnum));
                fp2->fd_len -= flp->lnum - fp2->fd_top;
                fp2->fd_top = flp->lnum;
                fold_changed = TRUE;
            }
            if (lvl >= level) {
                foldMerge (fp, gap, fp2);
            }
            break;
        }
        fold_changed = TRUE;
        deleteFoldEntry (gap, (int) (fp2 - (fold_T *) gap -> ga_data), TRUE);
    }
    if (bot < flp->lnum - 1)
        bot = flp->lnum - 1;
    return bot;
}

static void foldRemove (garray_T *gap, linenr_T top, linenr_T bot) {
    fold_T *fp = NULL;
    if (bot < top)
        return;
    for (;;) {
        if (foldFind (gap, top, &fp) && fp->fd_top < top) {
            foldRemove (& fp -> fd_nested, top - fp -> fd_top, bot - fp -> fd_top);
            if (fp->fd_top + fp->fd_len - 1 > bot) {
                foldSplit (gap, (int) (fp - (fold_T *) gap -> ga_data), top, bot);
            }
            else {
                fp->fd_len = top - fp->fd_top;
            }
            fold_changed = TRUE;
            continue;
        }
        if (fp >= (fold_T *) (gap->ga_data) + gap->ga_len || fp->fd_top > bot) {
            break;
        }
        if (fp->fd_top >= top) {
            fold_changed = TRUE;
            if (fp->fd_top + fp->fd_len - 1 > bot) {
                foldMarkAdjustRecurse (& fp -> fd_nested, (linenr_T) 0, (long) (bot - fp -> fd_top), (linenr_T) MAXLNUM, (long) (fp -> fd_top - bot - 1));
                fp->fd_len -= bot - fp->fd_top + 1;
                fp->fd_top = bot + 1;
                break;
            }
            deleteFoldEntry (gap, (int) (fp - (fold_T *) gap -> ga_data), TRUE);
        }
    }
}

static void foldSplit (garray_T *gap, int i, linenr_T top, linenr_T bot) {
    fold_T *fp;
    fold_T *fp2;
    garray_T *gap1;
    garray_T *gap2;
    int idx;
    int len;
    if (foldInsert (gap, i +1) == FAIL)
        return;
    fp = (fold_T *) gap->ga_data + i;
    fp[1].fd_top = bot + 1;
    fp[1].fd_len = fp->fd_len - (fp[1].fd_top - fp->fd_top);
    fp[1].fd_flags = fp->fd_flags;
    fp[1].fd_small = MAYBE;
    fp->fd_small = MAYBE;
    gap1 = &fp->fd_nested;
    gap2 = &fp[1].fd_nested;
    (void) (foldFind (gap1, bot +1 - fp->fd_top, &fp2));
    len = (int) ((fold_T *) gap1->ga_data + gap1->ga_len - fp2);
    if (len > 0 && ga_grow (gap2, len) == OK) {
        for (idx = 0; idx < len; ++idx) {
            ((fold_T *) gap2->ga_data)[idx] = fp2[idx];
            ((fold_T *) gap2->ga_data)[idx].fd_top -= fp[1].fd_top - fp->fd_top;
        }
        gap2->ga_len = len;
        gap1->ga_len -= len;
    }
    fp->fd_len = top - fp->fd_top;
    fold_changed = TRUE;
}

static int foldInsert (garray_T *gap, int i) {
    fold_T *fp;
    if (ga_grow (gap, 1) != OK)
        return FAIL;
    fp = (fold_T *) gap->ga_data + i;
    if (i < gap->ga_len)
        mch_memmove (fp +1, fp, sizeof (fold_T) * (gap->ga_len - i));
    ++gap->ga_len;
    ga_init2 (& fp -> fd_nested, (int) sizeof (fold_T), 10);
    return OK;
}

static void foldMerge (fold_T *fp1, garray_T *gap, fold_T *fp2) {
    fold_T *fp3;
    fold_T *fp4;
    int idx;
    garray_T *gap1 = &fp1->fd_nested;
    garray_T *gap2 = &fp2->fd_nested;
    if (foldFind (gap1, fp1->fd_len - 1L, &fp3) && foldFind (gap2, 0L, &fp4))
        foldMerge (fp3, gap2, fp4);
    if (gap2->ga_len > 0 && ga_grow (gap1, gap2->ga_len) == OK) {
        for (idx = 0; idx < gap2->ga_len; ++idx) {
            ((fold_T *) gap1->ga_data)[gap1->ga_len] = ((fold_T *) gap2->ga_data)[idx];
            ((fold_T *) gap1->ga_data)[gap1->ga_len].fd_top += fp1->fd_len;
            ++gap1->ga_len;
        }
        gap2->ga_len = 0;
    }
    fp1->fd_len += fp2->fd_len;
    deleteFoldEntry (gap, (int) (fp2 - (fold_T *) gap -> ga_data), TRUE);
    fold_changed = TRUE;
}

int foldLevel (linenr_T lnum) {
    if (invalid_top == (linenr_T) 0)
        checkupdate (curwin);
    else if (lnum == prev_lnum && prev_lnum_lvl >= 0)
        return prev_lnum_lvl;
    else if (lnum >= invalid_top && lnum <= invalid_bot)
        return -1;
    if (!hasAnyFolding (curwin))
        return 0;
    return foldLevelWin (curwin, lnum);
}

void foldtext_cleanup (char_u *str) {
    char_u *cms_start;
    int cms_slen = 0;
    char_u *cms_end;
    int cms_elen = 0;
    char_u *s;
    char_u *p;
    int len;
    int did1 = FALSE;
    int did2 = FALSE;
    cms_start = skipwhite (curbuf->b_p_cms);
    cms_slen = (int) STRLEN (cms_start);
    while (cms_slen > 0 && VIM_ISWHITE (cms_start[cms_slen - 1]))
        --cms_slen;
    cms_end = (char_u *) strstr ((char *) cms_start, "%s");
    if (cms_end != NULL) {
        cms_elen = cms_slen - (int) (cms_end - cms_start);
        cms_slen = (int) (cms_end - cms_start);
        while (cms_slen > 0 && VIM_ISWHITE (cms_start[cms_slen - 1]))
            --cms_slen;
        s = skipwhite (cms_end +2);
        cms_elen -= (int) (s - cms_end);
        cms_end = s;
    }
    parseMarker (curwin);
    for (s = str; *s != NUL;) {
        len = 0;
        if (STRNCMP (s, curwin->w_p_fmr, foldstartmarkerlen) == 0)
            len = foldstartmarkerlen;
        else if (STRNCMP (s, foldendmarker, foldendmarkerlen) == 0)
            len = foldendmarkerlen;
        if (len > 0) {
            if (VIM_ISDIGIT (s[len]))
                ++len;
            for (p = s; p > str && VIM_ISWHITE (p[-1]); --p)
                ;
            if (p >= str + cms_slen && STRNCMP (p -cms_slen, cms_start, cms_slen) == 0) {
                len += (int) (s - p) + cms_slen;
                s = p - cms_slen;
            }
        }
        else if (cms_end != NULL) {
            if (!did1 && cms_slen > 0 && STRNCMP (s, cms_start, cms_slen) == 0) {
                len = cms_slen;
                did1 = TRUE;
            }
            else if (!did2 && cms_elen > 0 && STRNCMP (s, cms_end, cms_elen) == 0) {
                len = cms_elen;
                did2 = TRUE;
            }
        }
        if (len != 0) {
            while (VIM_ISWHITE (s[len]))
                ++len;
            STRMOVE (s, s + len);
        }
        else {
            MB_PTR_ADV (s);
        }
    }
}

int foldManualAllowed (int create) {
    if (foldmethodIsManual (curwin) || foldmethodIsMarker (curwin))
        return TRUE;
    if (create)
        EMSG (_ ("E350: Cannot create fold with current 'foldmethod'"));
    else
        EMSG (_ ("E351: Cannot delete fold with current 'foldmethod'"));
    return FALSE;
}

void openFoldRecurse (linenr_T lnum) {
    (void) setManualFold (lnum, TRUE, TRUE, NULL);
}

void closeFoldRecurse (linenr_T lnum) {
    (void) setManualFold (lnum, FALSE, TRUE, NULL);
}

int getDeepestNesting (void) {
    checkupdate (curwin);
    return getDeepestNestingRecurse (&curwin->w_folds);
}

static int getDeepestNestingRecurse (garray_T *gap) {
    int i;
    int level;
    int maxlevel = 0;
    fold_T *fp;
    fp = (fold_T *) gap->ga_data;
    for (i = 0; i < gap->ga_len; ++i) {
        level = getDeepestNestingRecurse (&fp[i].fd_nested) + 1;
        if (level > maxlevel)
            maxlevel = level;
    }
    return maxlevel;
}

int foldMoveTo (int updown, int dir, long  count) {
    long  n;
    int retval = FAIL;
    linenr_T lnum_off;
    linenr_T lnum_found;
    linenr_T lnum;
    int use_level;
    int maybe_small;
    garray_T *gap;
    fold_T *fp;
    int level;
    int last;
    checkupdate (curwin);
    for (n = 0; n < count; ++n) {
        lnum_off = 0;
        gap = &curwin->w_folds;
        use_level = FALSE;
        maybe_small = FALSE;
        lnum_found = curwin->w_cursor.lnum;
        level = 0;
        last = FALSE;
        for (;;) {
            if (!foldFind (gap, curwin->w_cursor.lnum - lnum_off, &fp)) {
                if (!updown)
                    break;
                if (dir == FORWARD) {
                    if (fp - (fold_T *) gap->ga_data >= gap->ga_len)
                        break;
                    --fp;
                }
                else {
                    if (fp == (fold_T *) gap->ga_data)
                        break;
                }
                last = TRUE;
            }
            if (!last) {
                if (check_closed (curwin, fp, &use_level, level, &maybe_small, lnum_off))
                    last = TRUE;
                if (last && !updown)
                    break;
            }
            if (updown) {
                if (dir == FORWARD) {
                    if (fp + 1 - (fold_T *) gap->ga_data < gap->ga_len) {
                        lnum = fp[1].fd_top + lnum_off;
                        if (lnum > curwin->w_cursor.lnum)
                            lnum_found = lnum;
                    }
                }
                else {
                    if (fp > (fold_T *) gap->ga_data) {
                        lnum = fp[-1].fd_top + lnum_off + fp[-1].fd_len - 1;
                        if (lnum < curwin->w_cursor.lnum)
                            lnum_found = lnum;
                    }
                }
            }
            else {
                if (dir == FORWARD) {
                    lnum = fp->fd_top + lnum_off + fp->fd_len - 1;
                    if (lnum > curwin->w_cursor.lnum)
                        lnum_found = lnum;
                }
                else {
                    lnum = fp->fd_top + lnum_off;
                    if (lnum < curwin->w_cursor.lnum)
                        lnum_found = lnum;
                }
            }
            if (last)
                break;
            gap = &fp->fd_nested;
            lnum_off += fp->fd_top;
            ++level;
        }
        if (lnum_found != curwin->w_cursor.lnum) {
            if (retval == FAIL)
                setpcmark ();
            curwin->w_cursor.lnum = lnum_found;
            curwin->w_cursor.col = 0;
            retval = OK;
        }
        else
            break;
    }
    return retval;
}

