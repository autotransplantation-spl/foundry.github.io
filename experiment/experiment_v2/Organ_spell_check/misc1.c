
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
EXTERN long  p_report;
EXTERN int p_im;
garray_T ga_users;
EXTERN char_u *p_sh;
EXTERN char_u e_notread [] INIT (= N_ ("E485: Can't read file %s"));
EXTERN char_u *p_su;
EXTERN char_u *p_wig;
EXTERN char_u *p_lispwords;
EXTERN int p_ri;
EXTERN int p_sm;
EXTERN int p_sr;
EXTERN int p_paste;
EXTERN char_u *p_hf;
EXTERN int p_vb;
EXTERN char_u *p_debug;
EXTERN char_u *p_sbr;
char_u *homedir = NULL;
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
int breakcheck_count = 0;
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

void fast_breakcheck (void) {
    if (++breakcheck_count >= BREAKCHECK_SKIP * 10) {
        breakcheck_count = 0;
        ui_breakcheck ();
    }
}

void expand_env (char_u *src, char_u *dst, int dstlen) {
    expand_env_esc (src, dst, dstlen, FALSE, FALSE, NULL);
}

void expand_env_esc (char_u *srcp, char_u *dst, int dstlen, int esc, int one, char_u *startstr) {
    char_u *src;
    char_u *tail;
    int c;
    char_u *var;
    int copy_char;
    int mustfree;
    int at_start = TRUE;
    int startstr_len = 0;
    if (startstr != NULL)
        startstr_len = (int) STRLEN (startstr);
    src = skipwhite (srcp);
    --dstlen;
    while (*src && dstlen > 0) {
        if (src[0] == '`' && src[1] == '=') {
            size_t len;
            var = src;
            src += 2;
            (void) skip_expr (&src);
            if (*src == '`')
                ++src;
            len = src - var;
            if (len > (size_t) dstlen)
                len = dstlen;
            vim_strncpy (dst, var, len);
            dst += len;
            dstlen -= (int) len;
            continue;
        }
        copy_char = TRUE;
        if ((*src == '$') || (*src == '~' && at_start)) {
            mustfree = FALSE;
            if (*src != '~') {
                tail = src + 1;
                var = dst;
                c = dstlen - 1;
                if (*tail == '{' && !vim_isIDc ('{')) {
                    tail++;
                    while (c-- > 0 && *tail && *tail != '}')
                        *var++ = *tail++;
                }
                else {
                    while (c-- > 0 && *tail != NUL && ((vim_isIDc (*tail)))) {
                        *var++ = *tail++;
                    }
                }
                if (src[1] == '{' && *tail != '}')
                    var = NULL;
                else {
                    if (src[1] == '{')
                        ++tail;
                    *var = NUL;
                    var = vim_getenv (dst, &mustfree);
                }
            }
            else if (src[1] == NUL || vim_ispathsep (src[1]) || vim_strchr ((char_u *) " ,\t\n", src[1]) != NULL) {
                var = homedir;
                tail = src + 1;
            }
            else {
                tail = src;
                var = dst;
                c = dstlen - 1;
                while (c-- > 0 && *tail && vim_isfilec (*tail) && !vim_ispathsep (*tail))
                    *var++ = *tail++;
                *var = NUL;
                {
                    expand_T xpc;
                    ExpandInit (& xpc);
                    xpc.xp_context = EXPAND_FILES;
                    var = ExpandOne (&xpc, dst, NULL, WILD_ADD_SLASH | WILD_SILENT, WILD_EXPAND_FREE);
                    mustfree = TRUE;
                }
            }
            if (esc && var != NULL && vim_strpbrk (var, (char_u *) " \t") != NULL) {
                char_u *p = vim_strsave_escaped (var, (char_u *) " \t");
                if (p != NULL) {
                    if (mustfree)
                        vim_free (var);
                    var = p;
                    mustfree = TRUE;
                }
            }
            if (var != NULL && *var != NUL && (STRLEN (var) + STRLEN (tail) + 1 < (unsigned ) dstlen)) {
                STRCPY (dst, var);
                dstlen -= (int) STRLEN (var);
                c = (int) STRLEN (var);
                if (*var != NUL && after_pathsep (dst, dst +c) && vim_ispathsep (*tail))
                    ++tail;
                dst += c;
                src = tail;
                copy_char = FALSE;
            }
            if (mustfree)
                vim_free (var);
        }
        if (copy_char) {
            at_start = FALSE;
            if (src[0] == '\\' && src[1] != NUL) {
                *dst++ = *src++;
                --dstlen;
            }
            else if ((src[0] == ' ' || src[0] == ',') && !one)
                at_start = TRUE;
            if (dstlen > 0) {
                *dst++ = *src++;
                --dstlen;
                if (startstr != NULL && src - startstr_len >= srcp && STRNCMP (src -startstr_len, startstr, startstr_len) == 0)
                    at_start = TRUE;
            }
        }
    }
    *dst = NUL;
}

void line_breakcheck (void) {
    if (++breakcheck_count >= BREAKCHECK_SKIP) {
        breakcheck_count = 0;
        ui_breakcheck ();
    }
}

void vim_setenv (char_u *name, char_u *val) {
    char_u *envbuf;
    envbuf = alloc ((unsigned ) (STRLEN (name) + STRLEN (val) + 2));
    if (envbuf != NULL) {
        sprintf ((char *) envbuf, "%s=%s", name, val);
        putenv ((char *) envbuf);
    }
}

char_u *FullName_save (char_u *fname, int force) {
    char_u *buf;
    char_u *new_fname = NULL;
    if (fname == NULL)
        return NULL;
    buf = alloc ((unsigned ) MAXPATHL);
    if (buf != NULL) {
        if (vim_FullName (fname, buf, MAXPATHL, force) != FAIL)
            new_fname = vim_strsave (buf);
        else
            new_fname = vim_strsave (fname);
        vim_free (buf);
    }
    return new_fname;
}

char_u *gettail (char_u *fname) {
    char_u *p1, *p2;
    if (fname == NULL)
        return (char_u *) "";
    for (p1 = p2 = get_past_head (fname); *p2;) {
        if (vim_ispathsep_nocolon (*p2))
            p1 = p2 + 1;
        MB_PTR_ADV (p2);
    }
    return p1;
}

char_u *get_past_head (char_u *path) {
    char_u *retval;
    retval = path;
    while (vim_ispathsep (*retval))
        ++retval;
    return retval;
}

int vim_ispathsep (int c) {
    return (c == '/');
}

int vim_ispathsep_nocolon (int c) {
    return vim_ispathsep (c);
}

char_u *home_replace_save (buf_T *buf, char_u *src) {
    char_u *dst;
    unsigned  len;
    len = 3;
    if (src != NULL)
        len += (unsigned ) STRLEN (src);
    dst = alloc (len);
    if (dst != NULL)
        home_replace (buf, src, dst, len, TRUE);
    return dst;
}

void home_replace (buf_T *buf, char_u *src, char_u *dst, int dstlen, int one) {
    size_t dirlen = 0, envlen = 0;
    size_t len;
    char_u *homedir_env, *homedir_env_orig;
    char_u *p;
    if (src == NULL) {
        *dst = NUL;
        return;
    }
    if (buf != NULL && buf->b_help) {
        vim_snprintf ((char *) dst, dstlen, "%s", gettail (src));
        return;
    }
    if (homedir != NULL)
        dirlen = STRLEN (homedir);
    homedir_env_orig = homedir_env = mch_getenv ((char_u *) "HOME");
    if (homedir_env != NULL && *homedir_env == NUL)
        homedir_env = NULL;
    if (homedir_env != NULL && vim_strchr (homedir_env, '~') != NULL) {
        int usedlen = 0;
        int flen;
        char_u *fbuf = NULL;
        flen = (int) STRLEN (homedir_env);
        (void) modify_fname ((char_u *) ":p", &usedlen, &homedir_env, &fbuf, &flen);
        flen = (int) STRLEN (homedir_env);
        if (flen > 0 && vim_ispathsep (homedir_env[flen - 1]))
            homedir_env[flen - 1] = NUL;
    }
    if (homedir_env != NULL)
        envlen = STRLEN (homedir_env);
    if (!one)
        src = skipwhite (src);
    while (*src && dstlen > 0) {
        p = homedir;
        len = dirlen;
        for (;;) {
            if (len && fnamencmp (src, p, len) == 0 && (vim_ispathsep (src[len]) || (!one && (src[len] == ',' || src[len] == ' ')) || src[len] == NUL)) {
                src += len;
                if (--dstlen > 0)
                    *dst++ = '~';
                if (!vim_ispathsep (src[0]) && --dstlen > 0)
                    *dst++ = '/';
                break;
            }
            if (p == homedir_env)
                break;
            p = homedir_env;
            len = envlen;
        }
        while (*src && (one || (*src != ',' && *src != ' ')) && --dstlen > 0)
            *dst++ = *src++;
        while ((*src == ' ' || *src == ',') && --dstlen > 0)
            *dst++ = *src++;
    }
    *dst = NUL;
    if (homedir_env != homedir_env_orig)
        vim_free (homedir_env);
}

char_u *expand_env_save (char_u *src) {
    return expand_env_save_opt (src, FALSE);
}

char_u *expand_env_save_opt (char_u *src, int one) {
    char_u *p;
    p = alloc (MAXPATHL);
    if (p != NULL)
        expand_env_esc (src, p, MAXPATHL, FALSE, one, NULL);
    return p;
}

char_u *concat_str (char_u *str1, char_u *str2) {
    char_u *dest;
    size_t l = STRLEN (str1);
    dest = alloc ((unsigned ) (l + STRLEN (str2) + 1L));
    if (dest != NULL) {
        STRCPY (dest, str1);
        STRCPY (dest + l, str2);
    }
    return dest;
}

int get_breakindent_win (win_T *wp, char_u *line) {
    static int prev_indent = 0;
    static long  prev_ts = 0L;
    static char_u *prev_line = NULL;
    static varnumber_T prev_tick = 0;
    int bri = 0;
    const int eff_wwidth = wp->w_width - ((wp->w_p_nu || wp->w_p_rnu) && (vim_strchr (p_cpo, CPO_NUMCOL) == NULL) ? number_width (wp) + 1 : 0);
    if (prev_line != line || prev_ts != wp->w_buffer->b_p_ts || prev_tick != CHANGEDTICK (wp->w_buffer)) {
        prev_line = line;
        prev_ts = wp->w_buffer->b_p_ts;
        prev_tick = CHANGEDTICK (wp->w_buffer);
        prev_indent = get_indent_str (line, (int) wp->w_buffer->b_p_ts, wp->w_p_list);
    }
    bri = prev_indent + wp->w_p_brishift;
    if (wp->w_p_brisbr)
        bri -= vim_strsize (p_sbr);
    bri += win_col_off2 (wp);
    if (bri < 0)
        bri = 0;
    else if (bri > eff_wwidth - wp->w_p_brimin)
        bri = (eff_wwidth - wp->w_p_brimin < 0) ? 0 : eff_wwidth - wp->w_p_brimin;
    return bri;
}

int get_indent_str (char_u *ptr, int ts, int list) {
    int count = 0;
    for (; *ptr; ++ptr) {
        if (*ptr == TAB) {
            if (!list || lcs_tab1)
                count += ts - (count % ts);
            else
                count += ptr2cells (ptr);
        }
        else if (*ptr == ' ')
            ++count;
        else
            break;
    }
    return count;
}

int gchar_cursor (void) {
    return (int) *ml_get_cursor ();
}

char_u *skip_to_option_part (char_u *p) {
    if (*p == ',')
        ++p;
    while (*p == ' ')
        ++p;
    return p;
}

void parse_cino (buf_T *buf) {
    char_u *p;
    char_u *l;
    char_u *digits;
    int n;
    int divider;
    int fraction = 0;
    int sw = (int) get_sw_value (buf);
    buf->b_ind_level = sw;
    buf->b_ind_open_imag = 0;
    buf->b_ind_no_brace = 0;
    buf->b_ind_first_open = 0;
    buf->b_ind_open_extra = 0;
    buf->b_ind_close_extra = 0;
    buf->b_ind_open_left_imag = 0;
    buf->b_ind_jump_label = -1;
    buf->b_ind_case = sw;
    buf->b_ind_case_code = sw;
    buf->b_ind_case_break = 0;
    buf->b_ind_scopedecl = sw;
    buf->b_ind_scopedecl_code = sw;
    buf->b_ind_param = sw;
    buf->b_ind_func_type = sw;
    buf->b_ind_cpp_baseclass = sw;
    buf->b_ind_continuation = sw;
    buf->b_ind_unclosed = sw * 2;
    buf->b_ind_unclosed2 = sw;
    buf->b_ind_unclosed_noignore = 0;
    buf->b_ind_unclosed_wrapped = 0;
    buf->b_ind_unclosed_whiteok = 0;
    buf->b_ind_matching_paren = 0;
    buf->b_ind_paren_prev = 0;
    buf->b_ind_comment = 0;
    buf->b_ind_in_comment = 3;
    buf->b_ind_in_comment2 = 0;
    buf->b_ind_maxparen = 20;
    buf->b_ind_maxcomment = 70;
    buf->b_ind_java = 0;
    buf->b_ind_js = 0;
    buf->b_ind_keep_case_label = 0;
    buf->b_ind_cpp_namespace = 0;
    buf->b_ind_if_for_while = 0;
    buf->b_ind_hash_comment = 0;
    buf->b_ind_cpp_extern_c = 0;
    for (p = buf->b_p_cino; *p;) {
        l = p++;
        if (*p == '-')
            ++p;
        digits = p;
        n = getdigits (&p);
        divider = 0;
        if (*p == '.') {
            fraction = atol ((char *) ++p);
            while (VIM_ISDIGIT (*p)) {
                ++p;
                if (divider)
                    divider *= 10;
                else
                    divider = 10;
            }
        }
        if (*p == 's') {
            if (p == digits)
                n = sw;
            else {
                n *= sw;
                if (divider)
                    n += (sw * fraction + divider / 2) / divider;
            }
            ++p;
        }
        if (l[1] == '-')
            n = -n;
        switch (*l) {
        case '>' :
            buf->b_ind_level = n;
            break;
        case 'e' :
            buf->b_ind_open_imag = n;
            break;
        case 'n' :
            buf->b_ind_no_brace = n;
            break;
        case 'f' :
            buf->b_ind_first_open = n;
            break;
        case '{' :
            buf->b_ind_open_extra = n;
            break;
        case '}' :
            buf->b_ind_close_extra = n;
            break;
        case '^' :
            buf->b_ind_open_left_imag = n;
            break;
        case 'L' :
            buf->b_ind_jump_label = n;
            break;
        case ':' :
            buf->b_ind_case = n;
            break;
        case '=' :
            buf->b_ind_case_code = n;
            break;
        case 'b' :
            buf->b_ind_case_break = n;
            break;
        case 'p' :
            buf->b_ind_param = n;
            break;
        case 't' :
            buf->b_ind_func_type = n;
            break;
        case '/' :
            buf->b_ind_comment = n;
            break;
        case 'c' :
            buf->b_ind_in_comment = n;
            break;
        case 'C' :
            buf->b_ind_in_comment2 = n;
            break;
        case 'i' :
            buf->b_ind_cpp_baseclass = n;
            break;
        case '+' :
            buf->b_ind_continuation = n;
            break;
        case '(' :
            buf->b_ind_unclosed = n;
            break;
        case 'u' :
            buf->b_ind_unclosed2 = n;
            break;
        case 'U' :
            buf->b_ind_unclosed_noignore = n;
            break;
        case 'W' :
            buf->b_ind_unclosed_wrapped = n;
            break;
        case 'w' :
            buf->b_ind_unclosed_whiteok = n;
            break;
        case 'm' :
            buf->b_ind_matching_paren = n;
            break;
        case 'M' :
            buf->b_ind_paren_prev = n;
            break;
        case ')' :
            buf->b_ind_maxparen = n;
            break;
        case '*' :
            buf->b_ind_maxcomment = n;
            break;
        case 'g' :
            buf->b_ind_scopedecl = n;
            break;
        case 'h' :
            buf->b_ind_scopedecl_code = n;
            break;
        case 'j' :
            buf->b_ind_java = n;
            break;
        case 'J' :
            buf->b_ind_js = n;
            break;
        case 'l' :
            buf->b_ind_keep_case_label = n;
            break;
        case '#' :
            buf->b_ind_hash_comment = n;
            break;
        case 'N' :
            buf->b_ind_cpp_namespace = n;
            break;
        case 'k' :
            buf->b_ind_if_for_while = n;
            break;
        case 'E' :
            buf->b_ind_cpp_extern_c = n;
            break;
        }
        if (*p == ',')
            ++p;
    }
}

int plines_win_nofill (win_T *wp, linenr_T lnum, int winheight) {
    int lines;
    if (!wp->w_p_wrap)
        return 1;
    if (wp->w_width == 0)
        return 1;
    if (lineFolded (wp, lnum) == TRUE)
        return 1;
    lines = plines_win_nofold (wp, lnum);
    if (winheight > 0 && lines > wp->w_height)
        return (int) wp->w_height;
    return lines;
}

int plines_win_nofold (win_T *wp, linenr_T lnum) {
    char_u *s;
    long  col;
    int width;
    s = ml_get_buf (wp->w_buffer, lnum, FALSE);
    if (*s == NUL)
        return 1;
    col = win_linetabsize (wp, s, (colnr_T) MAXCOL);
    if (wp->w_p_list && lcs_eol != NUL)
        col += 1;
    width = wp->w_width - win_col_off (wp);
    if (width <= 0)
        return 32000;
    if (col <= width)
        return 1;
    col -= width;
    width += win_col_off2 (wp);
    return (col + (width - 1)) / width + 1;
}

void unchanged (buf_T *buf, int ff) {
    if (buf->b_changed || (ff && file_ff_differs (buf, FALSE))) {
        buf->b_changed = 0;
        ml_setflags (buf);
        if (ff)
            save_file_ff (buf);
        check_status (buf);
        redraw_tabline = TRUE;
        need_maketitle = TRUE;
    }
    ++CHANGEDTICK (buf);
    netbeans_unmodified (buf);
}

void check_status (buf_T *buf) {
    win_T *wp;
    FOR_ALL_WINDOWS (wp)
        if (wp->w_buffer == buf && wp->w_status_height) {
            wp->w_redr_status = TRUE;
            if (must_redraw < VALID)
                must_redraw = VALID;
        }
}

char_u *concat_fnames (char_u *fname1, char_u *fname2, int sep) {
    char_u *dest;
    dest = alloc ((unsigned ) (STRLEN (fname1) + STRLEN (fname2) + 3));
    if (dest != NULL) {
        STRCPY (dest, fname1);
        if (sep)
            add_pathsep (dest);
        STRCAT (dest, fname2);
    }
    return dest;
}

void add_pathsep (char_u *p) {
    if (*p != NUL && !after_pathsep (p, p +STRLEN (p)))
        STRCAT (p, PATHSEPSTR);
}

void beep_flush (void) {
    if (emsg_silent == 0) {
        flush_buffers (FALSE);
        vim_beep (BO_ERROR);
    }
}

void vim_beep (unsigned  val) {
    called_vim_beep = TRUE;
    if (emsg_silent == 0) {
        if (!((bo_flags & val) || (bo_flags & BO_ALL))) {
            if (p_vb && !(gui.in_use && gui.starting))
                out_str_cf (T_VB);
            else
                out_char (BELL);
        }
        if (vim_strchr (p_debug, 'e') != NULL) {
            msg_source (HL_ATTR (HLF_W));
            msg_attr ((char_u *) _ ("Beep!"), HL_ATTR (HLF_W));
        }
    }
}

int get_keystroke (void) {
    char_u *buf = NULL;
    int buflen = 150;
    int maxlen;
    int len = 0;
    int n;
    int save_mapped_ctrl_c = mapped_ctrl_c;
    int waited = 0;
    mapped_ctrl_c = FALSE;
    for (;;) {
        cursor_on ();
        out_flush ();
        maxlen = (buflen - 6 - len) / 3;
        if (buf == NULL)
            buf = alloc (buflen);
        else if (maxlen < 10) {
            char_u *t_buf = buf;
            buflen += 100;
            buf = vim_realloc (buf, buflen);
            if (buf == NULL)
                vim_free (t_buf);
            maxlen = (buflen - 6 - len) / 3;
        }
        if (buf == NULL) {
            do_outofmem_msg ((long_u) buflen);
            return ESC;
        }
        n = ui_inchar (buf +len, maxlen, len == 0 ? -1L : 100L, 0);
        if (n > 0) {
            n = fix_input_buffer (buf +len, n);
            len += n;
            waited = 0;
        }
        else if (len > 0)
            ++waited;
        if ((n = check_termcode (1, buf, buflen, &len)) < 0 && (!p_ttimeout || waited * 100L < (p_ttm < 0 ? p_tm : p_ttm)))
            continue;
        if (n == KEYLEN_REMOVED) {
            if (must_redraw != 0 && !need_wait_return && (State & CMDLINE) == 0) {
                update_screen (0);
                setcursor ();
            }
            continue;
        }
        if (n > 0)
            len = n;
        if (len == 0)
            continue;
        n = buf[0];
        if (n == K_SPECIAL) {
            n = TO_SPECIAL (buf[1], buf[2]);
            if (buf[1] == KS_MODIFIER || n == K_IGNORE || (is_mouse_key (n) && n != K_LEFTMOUSE) || n == K_VER_SCROLLBAR || n == K_HOR_SCROLLBAR || n == K_SWIPELEFT || n == K_SWIPERIGHT || n == K_SWIPEUP || n == K_SWIPEDOWN) {
                if (buf[1] == KS_MODIFIER)
                    mod_mask = buf[2];
                len -= 3;
                if (len > 0)
                    mch_memmove (buf, buf +3, (size_t) len);
                continue;
            }
            break;
        }
        if (n == intr_char)
            n = ESC;
        break;
    }
    vim_free (buf);
    mapped_ctrl_c = save_mapped_ctrl_c;
    return n;
}

void preserve_exit (void) {
    buf_T *buf;
    prepare_to_exit ();
    really_exiting = TRUE;
    out_str (IObuff);
    screen_start ();
    out_flush ();
    ml_close_notmod ();
    FOR_ALL_BUFFERS (buf) {
        if (buf->b_ml.ml_mfp != NULL && buf->b_ml.ml_mfp->mf_fname != NULL) {
            OUT_STR ("Vim: preserving files...\n");
            screen_start ();
            out_flush ();
            ml_sync_all (FALSE, FALSE);
            break;
        }
    }
    ml_close_all (FALSE);
    OUT_STR ("Vim: Finished.\n");
    getout (1);
}

void prepare_to_exit (void) {
    if (gui.in_use) {
        gui.dying = TRUE;
        out_trash ();
    }
    else {
        windgoto ((int) Rows - 1, 0);
        settmode (TMODE_COOK);
        stoptermcap ();
        out_flush ();
    }
}

void FreeWild (int count, char_u **files) {
    if (count <= 0 || files == NULL)
        return;
    while (count--)
        vim_free (files[count]);
    vim_free (files);
}

int fullpathcmp (char_u *s1, char_u *s2, int checkname) {
    char_u exp1 [MAXPATHL];
    char_u full1 [MAXPATHL];
    char_u full2 [MAXPATHL];
    stat_T st1, st2;
    int r1, r2;
    expand_env (s1, exp1, MAXPATHL);
    r1 = mch_stat ((char *) exp1, &st1);
    r2 = mch_stat ((char *) s2, &st2);
    if (r1 != 0 && r2 != 0) {
        if (checkname) {
            if (fnamecmp (exp1, s2) == 0)
                return FPC_SAMEX;
            r1 = vim_FullName (exp1, full1, MAXPATHL, FALSE);
            r2 = vim_FullName (s2, full2, MAXPATHL, FALSE);
            if (r1 == OK && r2 == OK && fnamecmp (full1, full2) == 0)
                return FPC_SAMEX;
        }
        return FPC_NOTX;
    }
    if (r1 != 0 || r2 != 0)
        return FPC_DIFFX;
    if (st1.st_dev == st2.st_dev && st1.st_ino == st2.st_ino)
        return FPC_SAME;
    return FPC_DIFF;
}

char_u *vim_getenv (char_u *name, int *mustfree) {
    char_u *p;
    char_u *pend;
    int vimruntime;
    p = mch_getenv (name);
    if (p != NULL && *p == NUL)
        p = NULL;
    if (p != NULL) {
        return p;
    }
    vimruntime = (STRCMP (name, "VIMRUNTIME") == 0);
    if (!vimruntime && STRCMP (name, "VIM") != 0)
        return NULL;
    if (vimruntime) {
        p = mch_getenv ((char_u *) "VIM");
        if (p != NULL && *p == NUL)
            p = NULL;
        if (p != NULL) {
            p = vim_version_dir (p);
            if (p != NULL)
                *mustfree = TRUE;
            else
                p = mch_getenv ((char_u *) "VIM");
        }
    }
    if (p == NULL) {
        if (p_hf != NULL && vim_strchr (p_hf, '$') == NULL)
            p = p_hf;
        if (p != NULL) {
            pend = gettail (p);
            if (p == p_hf)
                pend = remove_tail (p, pend, (char_u *) "doc");
            if (!vimruntime) {
                pend = remove_tail (p, pend, (char_u *) RUNTIME_DIRNAME);
                pend = remove_tail (p, pend, (char_u *) VIM_VERSION_NODOT);
            }
            if (pend > p && after_pathsep (p, pend))
                --pend;
            if (p == exe_name || p == p_hf)
                p = vim_strnsave (p, (int) (pend - p));
            if (p != NULL && !mch_isdir (p))
                VIM_CLEAR (p);
            else {
                *mustfree = TRUE;
            }
        }
    }
    if (p != NULL) {
        if (vimruntime) {
            vim_setenv ((char_u *) "VIMRUNTIME", p);
            didset_vimruntime = TRUE;
        }
        else {
            vim_setenv ((char_u *) "VIM", p);
            didset_vim = TRUE;
        }
    }
    return p;
}

static char_u *vim_version_dir (char_u *vimdir) {
    char_u *p;
    if (vimdir == NULL || *vimdir == NUL)
        return NULL;
    p = concat_fnames (vimdir, (char_u *) VIM_VERSION_NODOT, TRUE);
    if (p != NULL && mch_isdir (p))
        return p;
    vim_free (p);
    p = concat_fnames (vimdir, (char_u *) RUNTIME_DIRNAME, TRUE);
    if (p != NULL && mch_isdir (p))
        return p;
    vim_free (p);
    return NULL;
}

static char_u *remove_tail (char_u *p, char_u *pend, char_u *name) {
    int len = (int) STRLEN (name) + 1;
    char_u *newend = pend - len;
    if (newend >= p && fnamencmp (newend, name, len -1) == 0 && (newend == p || after_pathsep (p, newend)))
        return newend;
    return pend;
}

char_u *gettail_sep (char_u *fname) {
    char_u *p;
    char_u *t;
    p = get_past_head (fname);
    t = gettail (fname);
    while (t > p && after_pathsep (fname, t))
        --t;
    return t;
}

int plines_win (win_T *wp, linenr_T lnum, int winheight) {
    return plines_win_nofill (wp, lnum, winheight) + diff_check_fill (wp, lnum);
}

int plines (linenr_T lnum) {
    return plines_win (curwin, lnum, TRUE);
}

void changed (void) {
    if (!curbuf->b_changed) {
        int save_msg_scroll = msg_scroll;
        change_warning (0);
        if (curbuf->b_may_swap && !bt_dontwrite (curbuf)) {
            int save_need_wait_return = need_wait_return;
            need_wait_return = FALSE;
            ml_open_file (curbuf);
            if (need_wait_return && emsg_silent == 0) {
                out_flush ();
                ui_delay (2000L, TRUE);
                wait_return (TRUE);
                msg_scroll = save_msg_scroll;
            }
            else
                need_wait_return = save_need_wait_return;
        }
        changed_int ();
    }
    ++CHANGEDTICK (curbuf);
}

void change_warning (int col) {
    static char *w_readonly = N_ ("W10: Warning: Changing a readonly file");
    if (curbuf->b_did_warn == FALSE && curbufIsChanged () == 0 && !autocmd_busy && curbuf->b_p_ro) {
        ++curbuf_lock;
        apply_autocmds (EVENT_FILECHANGEDRO, NULL, NULL, FALSE, curbuf);
        --curbuf_lock;
        if (!curbuf->b_p_ro)
            return;
        msg_start ();
        if (msg_row == Rows - 1)
            msg_col = col;
        msg_source (HL_ATTR (HLF_W));
        MSG_PUTS_ATTR (_ (w_readonly), HL_ATTR (HLF_W) | MSG_HIST);
        set_vim_var_string (VV_WARNINGMSG, (char_u *) _ (w_readonly), - 1);
        msg_clr_eos ();
        (void) msg_end ();
        if (msg_silent == 0 && !silent_mode && time_for_testing != 1) {
            out_flush ();
            ui_delay (1000L, TRUE);
        }
        curbuf->b_did_warn = TRUE;
        redraw_cmdline = FALSE;
        if (msg_row < Rows - 1)
            showmode ();
    }
}

void changed_int (void) {
    curbuf->b_changed = TRUE;
    ml_setflags (curbuf);
    check_status (curbuf);
    redraw_tabline = TRUE;
    need_maketitle = TRUE;
}

pos_T *find_start_comment (int ind_maxcomment) {
    pos_T *pos;
    char_u *line;
    char_u *p;
    int cur_maxcomment = ind_maxcomment;
    for (;;) {
        pos = findmatchlimit (NULL, '*', FM_BACKWARD, cur_maxcomment);
        if (pos == NULL)
            break;
        line = ml_get (pos->lnum);
        for (p = line; *p && (colnr_T) (p - line) < pos->col; ++p)
            p = skip_string (p);
        if ((colnr_T) (p - line) <= pos->col)
            break;
        cur_maxcomment = curwin->w_cursor.lnum - pos->lnum - 1;
        if (cur_maxcomment <= 0) {
            pos = NULL;
            break;
        }
    }
    return pos;
}

static char_u *skip_string (char_u *p) {
    int i;
    for (;; ++p) {
        if (p[0] == '\'') {
            if (!p[1])
                break;
            i = 2;
            if (p[1] == '\\') {
                ++i;
                while (vim_isdigit (p[i - 1]))
                    ++i;
            }
            if (p[i] == '\'') {
                p += i;
                continue;
            }
        }
        else if (p[0] == '"') {
            for (++p; p[0]; ++p) {
                if (p[0] == '\\' && p[1] != NUL)
                    ++p;
                else if (p[0] == '"')
                    break;
            }
            if (p[0] == '"')
                continue;
        }
        else if (p[0] == 'R' && p[1] == '"') {
            char_u *delim = p + 2;
            char_u *paren = vim_strchr (delim, '(');
            if (paren != NULL) {
                size_t delim_len = paren - delim;
                for (p += 3; *p; ++p)
                    if (p[0] == ')' && STRNCMP (p +1, delim, delim_len) == 0 && p[delim_len + 1] == '"') {
                        p += delim_len + 1;
                        break;
                    }
                if (p[0] == '"')
                    continue;
            }
        }
        break;
    }
    if (!*p)
        --p;
    return p;
}

int gchar_pos (pos_T *pos) {
    char_u *ptr;
    if (pos->col == MAXCOL)
        return NUL;
    ptr = ml_get_pos (pos);
    return (int) *ptr;
}

int ask_yesno (char_u *str, int direct) {
    int r = ' ';
    int save_State = State;
    if (exiting)
        settmode (TMODE_RAW);
    ++no_wait_return;
    State = CONFIRM;
    setmouse ();
    ++no_mapping;
    ++allow_keys;
    while (r != 'y' && r != 'n') {
        smsg_attr (HL_ATTR (HLF_R), (char_u *) "%s (y/n)?", str);
        if (direct)
            r = get_keystroke ();
        else
            r = plain_vgetc ();
        if (r == Ctrl_C || r == ESC)
            r = 'n';
        msg_putchar (r);
        out_flush ();
    }
    --no_wait_return;
    State = save_State;
    setmouse ();
    --no_mapping;
    --allow_keys;
    return r;
}

void pchar_cursor (int c) {
    *(ml_get_buf (curbuf, curwin->w_cursor.lnum, TRUE) + curwin->w_cursor.col) = c;
}

int del_char (int fixpos) {
    return del_bytes (1L, fixpos, TRUE);
}

int del_bytes (long  count, int fixpos_arg, int use_delcombine) {
    char_u *oldp, *newp;
    colnr_T oldlen;
    linenr_T lnum = curwin->w_cursor.lnum;
    colnr_T col = curwin->w_cursor.col;
    int was_alloced;
    long  movelen;
    int fixpos = fixpos_arg;
    oldp = ml_get (lnum);
    oldlen = (int) STRLEN (oldp);
    if (col >= oldlen)
        return FAIL;
    if (count == 0)
        return OK;
    if (count < 1) {
        IEMSGN ("E950: Invalid count for del_bytes(): %ld", count);
        return FAIL;
    }
    movelen = (long ) oldlen - (long ) col - count + 1;
    if (movelen <= 1) {
        if (col > 0 && fixpos && restart_edit == 0 && (ve_flags & VE_ONEMORE) == 0) {
            --curwin->w_cursor.col;
            curwin->w_cursor.coladd = 0;
        }
        count = oldlen - col;
        movelen = 1;
    }
    if (netbeans_active ())
        was_alloced = FALSE;
    else
        was_alloced = ml_line_alloced ();
    if (was_alloced)
        newp = oldp;
    else {
        newp = alloc ((unsigned ) (oldlen + 1 - count));
        if (newp == NULL)
            return FAIL;
        mch_memmove (newp, oldp, (size_t) col);
    }
    mch_memmove (newp + col, oldp + col + count, (size_t) movelen);
    if (!was_alloced)
        ml_replace (lnum, newp, FALSE);
    changed_bytes (lnum, curwin -> w_cursor.col);
    return OK;
}

void changed_bytes (linenr_T lnum, colnr_T col) {
    changedOneline (curbuf, lnum);
    changed_common (lnum, col, lnum + 1, 0L);
    if (curwin->w_p_diff) {
        win_T *wp;
        linenr_T wlnum;
        FOR_ALL_WINDOWS (wp)
            if (wp->w_p_diff && wp != curwin) {
                redraw_win_later (wp, VALID);
                wlnum = diff_lnum_win (lnum, wp);
                if (wlnum > 0)
                    changedOneline (wp->w_buffer, wlnum);
            }
    }
}

static void changedOneline (buf_T *buf, linenr_T lnum) {
    if (buf->b_mod_set) {
        if (lnum < buf->b_mod_top)
            buf->b_mod_top = lnum;
        else if (lnum >= buf->b_mod_bot)
            buf->b_mod_bot = lnum + 1;
    }
    else {
        buf->b_mod_set = TRUE;
        buf->b_mod_top = lnum;
        buf->b_mod_bot = lnum + 1;
        buf->b_mod_xlines = 0;
    }
}

static void changed_common (linenr_T lnum, colnr_T col, linenr_T lnume, long  xtra) {
    win_T *wp;
    tabpage_T *tp;
    int i;
    int cols;
    pos_T *p;
    int add;
    changed ();
    if (!cmdmod.keepjumps) {
        curbuf->b_last_change.lnum = lnum;
        curbuf->b_last_change.col = col;
        if (curbuf->b_new_change || curbuf->b_changelistlen == 0) {
            if (curbuf->b_changelistlen == 0)
                add = TRUE;
            else {
                p = &curbuf->b_changelist[curbuf->b_changelistlen - 1];
                if (p->lnum != lnum)
                    add = TRUE;
                else {
                    cols = comp_textwidth (FALSE);
                    if (cols == 0)
                        cols = 79;
                    add = (p->col + cols < col || col + cols < p->col);
                }
            }
            if (add) {
                curbuf->b_new_change = FALSE;
                if (curbuf->b_changelistlen == JUMPLISTSIZE) {
                    curbuf->b_changelistlen = JUMPLISTSIZE - 1;
                    mch_memmove (curbuf -> b_changelist, curbuf -> b_changelist + 1, sizeof (pos_T) * (JUMPLISTSIZE - 1));
                    FOR_ALL_TAB_WINDOWS (tp, wp) {
                        if (wp->w_buffer == curbuf && wp->w_changelistidx > 0)
                            --wp->w_changelistidx;
                    }
                }
                FOR_ALL_TAB_WINDOWS (tp, wp) {
                    if (wp->w_buffer == curbuf && wp->w_changelistidx == curbuf->b_changelistlen)
                        ++wp->w_changelistidx;
                }
                ++curbuf->b_changelistlen;
            }
        }
        curbuf->b_changelist[curbuf->b_changelistlen - 1] = curbuf->b_last_change;
        curwin->w_changelistidx = curbuf->b_changelistlen;
    }
    FOR_ALL_TAB_WINDOWS (tp, wp) {
        if (wp->w_buffer == curbuf) {
            if (wp->w_redr_type < VALID)
                wp->w_redr_type = VALID;
            foldUpdate (wp, lnum, lnume + xtra - 1);
            i = hasFoldingWin (wp, lnum, &lnum, NULL, FALSE, NULL);
            if (wp->w_cursor.lnum == lnum)
                wp->w_cline_folded = i;
            i = hasFoldingWin (wp, lnume, NULL, &lnume, FALSE, NULL);
            if (wp->w_cursor.lnum == lnume)
                wp->w_cline_folded = i;
            if (wp->w_cursor.lnum <= lnum) {
                i = find_wl_entry (wp, lnum);
                if (i >= 0 && wp->w_cursor.lnum > wp->w_lines[i].wl_lnum)
                    changed_line_abv_curs_win (wp);
            }
            if (wp->w_cursor.lnum > lnum)
                changed_line_abv_curs_win (wp);
            else if (wp->w_cursor.lnum == lnum && wp->w_cursor.col >= col)
                changed_cline_bef_curs_win (wp);
            if (wp->w_botline >= lnum) {
                approximate_botline_win (wp);
            }
            for (i = 0; i < wp->w_lines_valid; ++i)
                if (wp->w_lines[i].wl_valid) {
                    if (wp->w_lines[i].wl_lnum >= lnum) {
                        if (wp->w_lines[i].wl_lnum < lnume) {
                            wp->w_lines[i].wl_valid = FALSE;
                        }
                        else if (xtra != 0) {
                            wp->w_lines[i].wl_lnum += xtra;
                            wp->w_lines[i].wl_lastlnum += xtra;
                        }
                    }
                    else if (wp->w_lines[i].wl_lastlnum >= lnum) {
                        wp->w_lines[i].wl_valid = FALSE;
                    }
                }
            if (hasAnyFolding (wp))
                set_topline (wp, wp->w_topline);
            if (wp->w_p_rnu)
                redraw_win_later (wp, SOME_VALID);
        }
    }
    if (must_redraw < VALID)
        must_redraw = VALID;
    if (lnum <= curwin->w_cursor.lnum && lnume + (xtra < 0 ? -xtra : xtra) > curwin->w_cursor.lnum)
        last_cursormoved.lnum = 0;
}

int open_line (int dir, int flags, int second_line_indent) {
    char_u *saved_line;
    char_u *next_line = NULL;
    char_u *p_extra = NULL;
    int less_cols = 0;
    int less_cols_off = 0;
    pos_T old_cursor;
    int newcol = 0;
    int newindent = 0;
    int n;
    int trunc_line = FALSE;
    int retval = FALSE;
    int extra_len = 0;
    int lead_len;
    char_u *lead_flags;
    char_u *leader = NULL;
    char_u *allocated = NULL;
    char_u *p;
    int saved_char = NUL;
    pos_T *pos;
    int do_si = (!p_paste && curbuf->b_p_si && !curbuf->b_p_cin && *curbuf->b_p_inde == NUL);
    int no_si = FALSE;
    int first_char = NUL;
    int vreplace_mode;
    int did_append;
    int saved_pi = curbuf->b_p_pi;
    saved_line = vim_strsave (ml_get_curline ());
    if (saved_line == NULL)
        return FALSE;
    if (State & VREPLACE_FLAG) {
        if (curwin->w_cursor.lnum < orig_line_count)
            next_line = vim_strsave (ml_get (curwin->w_cursor.lnum + 1));
        else
            next_line = vim_strsave ((char_u *) "");
        if (next_line == NULL)
            goto theend;
        replace_push (NUL);
        replace_push (NUL);
        p = saved_line + curwin->w_cursor.col;
        while (*p != NUL) {
            replace_push (* p ++);
        }
        saved_line[curwin->w_cursor.col] = NUL;
    }
    if ((State & INSERT) && !(State & VREPLACE_FLAG)) {
        p_extra = saved_line + curwin->w_cursor.col;
        if (do_si) {
            p = skipwhite (p_extra);
            first_char = *p;
        }
        extra_len = (int) STRLEN (p_extra);
        saved_char = *p_extra;
        *p_extra = NUL;
    }
    u_clearline ();
    did_si = FALSE;
    ai_col = 0;
    if (dir == FORWARD && did_ai)
        trunc_line = TRUE;
    if (curbuf->b_p_ai || do_si) {
        newindent = get_indent_str (saved_line, (int) curbuf->b_p_ts, FALSE);
        if (newindent == 0 && !(flags & OPENLINE_COM_LIST))
            newindent = second_line_indent;
        if (!trunc_line && do_si && *saved_line != NUL && (p_extra == NULL || first_char != '{')) {
            char_u *ptr;
            char_u last_char;
            old_cursor = curwin->w_cursor;
            ptr = saved_line;
            if (flags & OPENLINE_DO_COM)
                lead_len = get_leader_len (ptr, NULL, FALSE, TRUE);
            else
                lead_len = 0;
            if (dir == FORWARD) {
                if (lead_len == 0 && ptr[0] == '#') {
                    while (ptr[0] == '#' && curwin->w_cursor.lnum > 1)
                        ptr = ml_get (--curwin->w_cursor.lnum);
                    newindent = get_indent ();
                }
                if (flags & OPENLINE_DO_COM)
                    lead_len = get_leader_len (ptr, NULL, FALSE, TRUE);
                else
                    lead_len = 0;
                if (lead_len > 0) {
                    p = skipwhite (ptr);
                    if (p[0] == '/' && p[1] == '*')
                        p++;
                    if (p[0] == '*') {
                        for (p++; *p; p++) {
                            if (p[0] == '/' && p[-1] == '*') {
                                curwin->w_cursor.col = (colnr_T) (p - ptr);
                                if ((pos = findmatch (NULL, NUL)) != NULL) {
                                    curwin->w_cursor.lnum = pos->lnum;
                                    newindent = get_indent ();
                                }
                            }
                        }
                    }
                }
                else {
                    p = ptr + STRLEN (ptr) - 1;
                    while (p > ptr && VIM_ISWHITE (*p))
                        --p;
                    last_char = *p;
                    if (last_char == '{' || last_char == ';') {
                        if (p > ptr)
                            --p;
                        while (p > ptr && VIM_ISWHITE (*p))
                            --p;
                    }
                    if (*p == ')') {
                        curwin->w_cursor.col = (colnr_T) (p - ptr);
                        if ((pos = findmatch (NULL, '(')) != NULL) {
                            curwin->w_cursor.lnum = pos->lnum;
                            newindent = get_indent ();
                            ptr = ml_get_curline ();
                        }
                    }
                    if (last_char == '{') {
                        did_si = TRUE;
                        no_si = TRUE;
                    }
                    else if (last_char != ';' && last_char != '}' && cin_is_cinword (ptr))
                        did_si = TRUE;
                }
            }
            else {
                if (lead_len == 0 && ptr[0] == '#') {
                    int was_backslashed = FALSE;
                    while ((ptr[0] == '#' || was_backslashed) && curwin->w_cursor.lnum < curbuf->b_ml.ml_line_count) {
                        if (*ptr && ptr[STRLEN (ptr) - 1] == '\\')
                            was_backslashed = TRUE;
                        else
                            was_backslashed = FALSE;
                        ptr = ml_get (++curwin->w_cursor.lnum);
                    }
                    if (was_backslashed)
                        newindent = 0;
                    else
                        newindent = get_indent ();
                }
                p = skipwhite (ptr);
                if (*p == '}')
                    did_si = TRUE;
                else
                    can_si_back = TRUE;
            }
            curwin->w_cursor = old_cursor;
        }
        if (do_si)
            can_si = TRUE;
        did_ai = TRUE;
    }
    end_comment_pending = NUL;
    if (flags & OPENLINE_DO_COM)
        lead_len = get_leader_len (saved_line, &lead_flags, dir == BACKWARD, TRUE);
    else
        lead_len = 0;
    if (lead_len > 0) {
        char_u *lead_repl = NULL;
        int lead_repl_len = 0;
        char_u lead_middle [COM_MAX_LEN];
        char_u lead_end [COM_MAX_LEN];
        char_u *comment_end = NULL;
        int extra_space = FALSE;
        int current_flag;
        int require_blank = FALSE;
        char_u *p2;
        for (p = lead_flags; *p && *p != ':'; ++p) {
            if (*p == COM_BLANK) {
                require_blank = TRUE;
                continue;
            }
            if (*p == COM_START || *p == COM_MIDDLE) {
                current_flag = *p;
                if (*p == COM_START) {
                    if (dir == BACKWARD) {
                        lead_len = 0;
                        break;
                    }
                    (void) copy_option_part (&p, lead_middle, COM_MAX_LEN, ",");
                    require_blank = FALSE;
                }
                while (*p && p[-1] != ':') {
                    if (*p == COM_BLANK)
                        require_blank = TRUE;
                    ++p;
                }
                (void) copy_option_part (&p, lead_middle, COM_MAX_LEN, ",");
                while (*p && p[-1] != ':') {
                    if (*p == COM_AUTO_END)
                        end_comment_pending = -1;
                    ++p;
                }
                n = copy_option_part (&p, lead_end, COM_MAX_LEN, ",");
                if (end_comment_pending == -1)
                    end_comment_pending = lead_end[n - 1];
                if (dir == FORWARD) {
                    for (p = saved_line + lead_len; *p; ++p)
                        if (STRNCMP (p, lead_end, n) == 0) {
                            comment_end = p;
                            lead_len = 0;
                            break;
                        }
                }
                if (lead_len > 0) {
                    if (current_flag == COM_START) {
                        lead_repl = lead_middle;
                        lead_repl_len = (int) STRLEN (lead_middle);
                    }
                    if (!VIM_ISWHITE (saved_line[lead_len - 1]) && ((p_extra != NULL && (int) curwin->w_cursor.col == lead_len) || (p_extra == NULL && saved_line[lead_len] == NUL) || require_blank))
                        extra_space = TRUE;
                }
                break;
            }
            if (*p == COM_END) {
                if (dir == FORWARD) {
                    comment_end = skipwhite (saved_line);
                    lead_len = 0;
                    break;
                }
                while (p > curbuf->b_p_com && *p != ',')
                    --p;
                for (lead_repl = p; lead_repl > curbuf->b_p_com && lead_repl[-1] != ':'; --lead_repl)
                    ;
                lead_repl_len = (int) (p - lead_repl);
                extra_space = TRUE;
                for (p2 = p; *p2 && *p2 != ':'; p2++) {
                    if (*p2 == COM_AUTO_END)
                        end_comment_pending = -1;
                }
                if (end_comment_pending == -1) {
                    while (*p2 && *p2 != ',')
                        p2++;
                    end_comment_pending = p2[-1];
                }
                break;
            }
            if (*p == COM_FIRST) {
                if (dir == BACKWARD)
                    lead_len = 0;
                else {
                    lead_repl = (char_u *) "";
                    lead_repl_len = 0;
                }
                break;
            }
        }
        if (lead_len) {
            leader = alloc (lead_len +lead_repl_len + extra_space + extra_len + (second_line_indent > 0 ? second_line_indent : 0) + 1);
            allocated = leader;
            if (leader == NULL)
                lead_len = 0;
            else {
                vim_strncpy (leader, saved_line, lead_len);
                if (lead_repl != NULL) {
                    int c = 0;
                    int off = 0;
                    for (p = lead_flags; *p != NUL && *p != ':';) {
                        if (*p == COM_RIGHT || *p == COM_LEFT)
                            c = *p++;
                        else if (VIM_ISDIGIT (*p) || *p == '-')
                            off = getdigits (&p);
                        else
                            ++p;
                    }
                    if (c == COM_RIGHT) {
                        for (p = leader + lead_len - 1; p > leader && VIM_ISWHITE (*p); --p)
                            ;
                        ++p;
                        if (p < leader + lead_repl_len)
                            p = leader;
                        else
                            p -= lead_repl_len;
                        mch_memmove (p, lead_repl, (size_t) lead_repl_len);
                        if (p + lead_repl_len > leader + lead_len)
                            p[lead_repl_len] = NUL;
                        while (--p >= leader) {
                            if (!VIM_ISWHITE (*p))
                                *p = ' ';
                        }
                    }
                    else {
                        p = skipwhite (leader);
                        mch_memmove (p, lead_repl, (size_t) lead_repl_len);
                        for (p += lead_repl_len; p < leader + lead_len; ++p)
                            if (!VIM_ISWHITE (*p)) {
                                if (p + 1 < leader + lead_len && p[1] == TAB) {
                                    --lead_len;
                                    mch_memmove (p, p + 1, (leader + lead_len) - p);
                                }
                                else {
                                    *p = ' ';
                                }
                            }
                        *p = NUL;
                    }
                    if (curbuf->b_p_ai || do_si)
                        newindent = get_indent_str (leader, (int) curbuf->b_p_ts, FALSE);
                    if (newindent + off < 0) {
                        off = -newindent;
                        newindent = 0;
                    }
                    else
                        newindent += off;
                    while (off > 0 && lead_len > 0 && leader[lead_len - 1] == ' ') {
                        if (vim_strchr (skipwhite (leader), '\t') != NULL)
                            break;
                        --lead_len;
                        --off;
                    }
                    if (lead_len > 0 && VIM_ISWHITE (leader[lead_len - 1]))
                        extra_space = FALSE;
                    leader[lead_len] = NUL;
                }
                if (extra_space) {
                    leader[lead_len++] = ' ';
                    leader[lead_len] = NUL;
                }
                newcol = lead_len;
                if (newindent || did_si) {
                    while (lead_len && VIM_ISWHITE (*leader)) {
                        --lead_len;
                        --newcol;
                        ++leader;
                    }
                }
            }
            did_si = can_si = FALSE;
        }
        else if (comment_end != NULL) {
            if (comment_end[0] == '*' && comment_end[1] == '/' && (curbuf->b_p_ai || do_si)) {
                old_cursor = curwin->w_cursor;
                curwin->w_cursor.col = (colnr_T) (comment_end - saved_line);
                if ((pos = findmatch (NULL, NUL)) != NULL) {
                    curwin->w_cursor.lnum = pos->lnum;
                    newindent = get_indent ();
                }
                curwin->w_cursor = old_cursor;
            }
        }
    }
    if (p_extra != NULL) {
        *p_extra = saved_char;
        if (REPLACE_NORMAL (State))
            replace_push (NUL);
        if (curbuf->b_p_ai || (flags & OPENLINE_DELSPACES)) {
            while ((*p_extra == ' ' || *p_extra == '\t')) {
                if (REPLACE_NORMAL (State))
                    replace_push (*p_extra);
                ++p_extra;
                ++less_cols_off;
            }
        }
        if (*p_extra != NUL)
            did_ai = FALSE;
        less_cols = (int) (p_extra - saved_line);
    }
    if (p_extra == NULL)
        p_extra = (char_u *) "";
    if (lead_len) {
        if (flags & OPENLINE_COM_LIST && second_line_indent > 0) {
            int i;
            int padding = second_line_indent - (newindent + (int) STRLEN (leader));
            for (i = 0; i < padding; i++) {
                STRCAT (leader, " ");
                less_cols--;
                newcol++;
            }
        }
        STRCAT (leader, p_extra);
        p_extra = leader;
        did_ai = TRUE;
        less_cols -= lead_len;
    }
    else
        end_comment_pending = NUL;
    old_cursor = curwin->w_cursor;
    if (dir == BACKWARD)
        --curwin->w_cursor.lnum;
    if (!(State & VREPLACE_FLAG) || old_cursor.lnum >= orig_line_count) {
        if (ml_append (curwin->w_cursor.lnum, p_extra, (colnr_T) 0, FALSE) == FAIL)
            goto theend;
        if (curwin->w_cursor.lnum + 1 < curbuf->b_ml.ml_line_count || curwin->w_p_diff)
            mark_adjust (curwin->w_cursor.lnum + 1, (linenr_T) MAXLNUM, 1L, 0L);
        did_append = TRUE;
    }
    else {
        curwin->w_cursor.lnum++;
        if (curwin->w_cursor.lnum >= Insstart.lnum + vr_lines_changed) {
            (void) u_save_cursor ();
            vr_lines_changed++;
        }
        ml_replace (curwin -> w_cursor.lnum, p_extra, TRUE);
        changed_bytes (curwin -> w_cursor.lnum, 0);
        curwin->w_cursor.lnum--;
        did_append = FALSE;
    }
    if (newindent || did_si) {
        ++curwin->w_cursor.lnum;
        if (did_si) {
            int sw = (int) get_sw_value (curbuf);
            if (p_sr)
                newindent -= newindent % sw;
            newindent += sw;
        }
        if (curbuf->b_p_ci) {
            (void) copy_indent (newindent, saved_line);
            curbuf->b_p_pi = TRUE;
        }
        else
            (void) set_indent (newindent, SIN_INSERT);
        less_cols -= curwin->w_cursor.col;
        ai_col = curwin->w_cursor.col;
        if (REPLACE_NORMAL (State))
            for (n = 0; n < (int) curwin->w_cursor.col; ++n)
                replace_push (NUL);
        newcol += curwin->w_cursor.col;
        if (no_si)
            did_si = FALSE;
    }
    if (REPLACE_NORMAL (State))
        while (lead_len-- > 0)
            replace_push (NUL);
    curwin->w_cursor = old_cursor;
    if (dir == FORWARD) {
        if (trunc_line || (State & INSERT)) {
            saved_line[curwin->w_cursor.col] = NUL;
            if (trunc_line && !(flags & OPENLINE_KEEPTRAIL))
                truncate_spaces (saved_line);
            ml_replace (curwin -> w_cursor.lnum, saved_line, FALSE);
            saved_line = NULL;
            if (did_append) {
                changed_lines (curwin -> w_cursor.lnum, curwin -> w_cursor.col, curwin -> w_cursor.lnum + 1, 1L);
                did_append = FALSE;
                if (flags & OPENLINE_MARKFIX)
                    mark_col_adjust (curwin->w_cursor.lnum, curwin->w_cursor.col + less_cols_off, 1L, (long ) -less_cols);
            }
            else
                changed_bytes (curwin->w_cursor.lnum, curwin->w_cursor.col);
        }
        curwin->w_cursor.lnum = old_cursor.lnum + 1;
    }
    if (did_append)
        changed_lines (curwin->w_cursor.lnum, 0, curwin->w_cursor.lnum, 1L);
    curwin->w_cursor.col = newcol;
    curwin->w_cursor.coladd = 0;
    if (State & VREPLACE_FLAG) {
        vreplace_mode = State;
        State = INSERT;
    }
    else
        vreplace_mode = 0;
    if (!p_paste && leader == NULL && curbuf->b_p_lisp && curbuf->b_p_ai) {
        fixthisline (get_lisp_indent);
        ai_col = (colnr_T) getwhitecols_curline ();
    }
    if (!p_paste && (curbuf->b_p_cin || *curbuf->b_p_inde != NUL) && in_cinkeys (dir == FORWARD ? KEY_OPEN_FORW : KEY_OPEN_BACK, ' ', linewhite (curwin->w_cursor.lnum))) {
        do_c_expr_indent ();
        ai_col = (colnr_T) getwhitecols_curline ();
    }
    if (vreplace_mode != 0)
        State = vreplace_mode;
    if (State & VREPLACE_FLAG) {
        p_extra = vim_strsave (ml_get_curline ());
        if (p_extra == NULL)
            goto theend;
        ml_replace (curwin -> w_cursor.lnum, next_line, FALSE);
        curwin->w_cursor.col = 0;
        curwin->w_cursor.coladd = 0;
        ins_bytes (p_extra);
        vim_free (p_extra);
        next_line = NULL;
    }
    retval = TRUE;
theend :
    curbuf->b_p_pi = saved_pi;
    vim_free (saved_line);
    vim_free (next_line);
    vim_free (allocated);
    return retval;
}

int get_leader_len (char_u *line, char_u **flags, int backward, int include_space) {
    int i, j;
    int result;
    int got_com = FALSE;
    int found_one;
    char_u part_buf [COM_MAX_LEN];
    char_u *string;
    char_u *list;
    int middle_match_len = 0;
    char_u *prev_list;
    char_u *saved_flags = NULL;
    result = i = 0;
    while (VIM_ISWHITE (line[i]))
        ++i;
    while (line[i] != NUL) {
        found_one = FALSE;
        for (list = curbuf->b_p_com; *list;) {
            if (!got_com && flags != NULL)
                *flags = list;
            prev_list = list;
            (void) copy_option_part (&list, part_buf, COM_MAX_LEN, ",");
            string = vim_strchr (part_buf, ':');
            if (string == NULL)
                continue;
            *string++ = NUL;
            if (middle_match_len != 0 && vim_strchr (part_buf, COM_MIDDLE) == NULL && vim_strchr (part_buf, COM_END) == NULL)
                break;
            if (got_com && vim_strchr (part_buf, COM_NEST) == NULL)
                continue;
            if (backward && vim_strchr (part_buf, COM_NOBACK) != NULL)
                continue;
            if (VIM_ISWHITE (string[0])) {
                if (i == 0 || !VIM_ISWHITE (line[i - 1]))
                    continue;
                while (VIM_ISWHITE (string[0]))
                    ++string;
            }
            for (j = 0; string[j] != NUL && string[j] == line[i + j]; ++j)
                ;
            if (string[j] != NUL)
                continue;
            if (vim_strchr (part_buf, COM_BLANK) != NULL && !VIM_ISWHITE (line[i + j]) && line[i + j] != NUL)
                continue;
            if (vim_strchr (part_buf, COM_MIDDLE) != NULL) {
                if (middle_match_len == 0) {
                    middle_match_len = j;
                    saved_flags = prev_list;
                }
                continue;
            }
            if (middle_match_len != 0 && j > middle_match_len)
                middle_match_len = 0;
            if (middle_match_len == 0)
                i += j;
            found_one = TRUE;
            break;
        }
        if (middle_match_len != 0) {
            if (!got_com && flags != NULL)
                *flags = saved_flags;
            i += middle_match_len;
            found_one = TRUE;
        }
        if (!found_one)
            break;
        result = i;
        while (VIM_ISWHITE (line[i]))
            ++i;
        if (include_space)
            result = i;
        got_com = TRUE;
        if (vim_strchr (part_buf, COM_NEST) == NULL)
            break;
    }
    return result;
}

int get_indent (void) {
    return get_indent_str (ml_get_curline (), (int) curbuf->b_p_ts, FALSE);
}

static int cin_is_cinword (char_u *line) {
    char_u *cinw;
    char_u *cinw_buf;
    int cinw_len;
    int retval = FALSE;
    int len;
    cinw_len = (int) STRLEN (curbuf->b_p_cinw) + 1;
    cinw_buf = alloc ((unsigned ) cinw_len);
    if (cinw_buf != NULL) {
        line = skipwhite (line);
        for (cinw = curbuf->b_p_cinw; *cinw;) {
            len = copy_option_part (&cinw, cinw_buf, cinw_len, ",");
            if (STRNCMP (line, cinw_buf, len) == 0 && (!vim_iswordc (line[len]) || !vim_iswordc (line[len - 1]))) {
                retval = TRUE;
                break;
            }
        }
        vim_free (cinw_buf);
    }
    return retval;
}

static int copy_indent (int size, char_u *src) {
    char_u *p = NULL;
    char_u *line = NULL;
    char_u *s;
    int todo;
    int ind_len;
    int line_len = 0;
    int tab_pad;
    int ind_done;
    int round;
    for (round = 1; round <= 2; ++round) {
        todo = size;
        ind_len = 0;
        ind_done = 0;
        s = src;
        while (todo > 0 && VIM_ISWHITE (*s)) {
            if (*s == TAB) {
                tab_pad = (int) curbuf->b_p_ts - (ind_done % (int) curbuf->b_p_ts);
                if (todo < tab_pad)
                    break;
                todo -= tab_pad;
                ind_done += tab_pad;
            }
            else {
                --todo;
                ++ind_done;
            }
            ++ind_len;
            if (p != NULL)
                *p++ = *s;
            ++s;
        }
        tab_pad = (int) curbuf->b_p_ts - (ind_done % (int) curbuf->b_p_ts);
        if (todo >= tab_pad && !curbuf->b_p_et) {
            todo -= tab_pad;
            ++ind_len;
            if (p != NULL)
                *p++ = TAB;
        }
        while (todo >= (int) curbuf->b_p_ts && !curbuf->b_p_et) {
            todo -= (int) curbuf->b_p_ts;
            ++ind_len;
            if (p != NULL)
                *p++ = TAB;
        }
        while (todo > 0) {
            --todo;
            ++ind_len;
            if (p != NULL)
                *p++ = ' ';
        }
        if (p == NULL) {
            line_len = (int) STRLEN (ml_get_curline ()) + 1;
            line = alloc (ind_len +line_len);
            if (line == NULL)
                return FALSE;
            p = line;
        }
    }
    mch_memmove (p, ml_get_curline (), (size_t) line_len);
    ml_replace (curwin -> w_cursor.lnum, line, FALSE);
    curwin->w_cursor.col = ind_len;
    return TRUE;
}

int set_indent (int size, int flags) {
    char_u *p;
    char_u *newline;
    char_u *oldline;
    char_u *s;
    int todo;
    int ind_len;
    int line_len;
    int doit = FALSE;
    int ind_done = 0;
    int tab_pad;
    int retval = FALSE;
    int orig_char_len = -1;
    todo = size;
    ind_len = 0;
    p = oldline = ml_get_curline ();
    if (!curbuf->b_p_et || (!(flags & SIN_INSERT) && curbuf->b_p_pi)) {
        if (!(flags & SIN_INSERT) && curbuf->b_p_pi) {
            ind_done = 0;
            while (todo > 0 && VIM_ISWHITE (*p)) {
                if (*p == TAB) {
                    tab_pad = (int) curbuf->b_p_ts - (ind_done % (int) curbuf->b_p_ts);
                    if (todo < tab_pad)
                        break;
                    todo -= tab_pad;
                    ++ind_len;
                    ind_done += tab_pad;
                }
                else {
                    --todo;
                    ++ind_len;
                    ++ind_done;
                }
                ++p;
            }
            if (curbuf->b_p_et)
                orig_char_len = ind_len;
            tab_pad = (int) curbuf->b_p_ts - (ind_done % (int) curbuf->b_p_ts);
            if (todo >= tab_pad && orig_char_len == -1) {
                doit = TRUE;
                todo -= tab_pad;
                ++ind_len;
            }
        }
        while (todo >= (int) curbuf->b_p_ts) {
            if (*p != TAB)
                doit = TRUE;
            else
                ++p;
            todo -= (int) curbuf->b_p_ts;
            ++ind_len;
        }
    }
    while (todo > 0) {
        if (*p != ' ')
            doit = TRUE;
        else
            ++p;
        --todo;
        ++ind_len;
    }
    if (!doit && !VIM_ISWHITE (*p) && !(flags & SIN_INSERT))
        return FALSE;
    if (flags & SIN_INSERT)
        p = oldline;
    else
        p = skipwhite (p);
    line_len = (int) STRLEN (p) + 1;
    if (orig_char_len != -1) {
        newline = alloc (orig_char_len +size - ind_done + line_len);
        if (newline == NULL)
            return FALSE;
        todo = size - ind_done;
        ind_len = orig_char_len + todo;
        p = oldline;
        s = newline;
        while (orig_char_len > 0) {
            *s++ = *p++;
            orig_char_len--;
        }
        while (VIM_ISWHITE (*p))
            ++p;
    }
    else {
        todo = size;
        newline = alloc (ind_len +line_len);
        if (newline == NULL)
            return FALSE;
        s = newline;
    }
    if (!curbuf->b_p_et) {
        if (!(flags & SIN_INSERT) && curbuf->b_p_pi) {
            p = oldline;
            ind_done = 0;
            while (todo > 0 && VIM_ISWHITE (*p)) {
                if (*p == TAB) {
                    tab_pad = (int) curbuf->b_p_ts - (ind_done % (int) curbuf->b_p_ts);
                    if (todo < tab_pad)
                        break;
                    todo -= tab_pad;
                    ind_done += tab_pad;
                }
                else {
                    --todo;
                    ++ind_done;
                }
                *s++ = *p++;
            }
            tab_pad = (int) curbuf->b_p_ts - (ind_done % (int) curbuf->b_p_ts);
            if (todo >= tab_pad) {
                *s++ = TAB;
                todo -= tab_pad;
            }
            p = skipwhite (p);
        }
        while (todo >= (int) curbuf->b_p_ts) {
            *s++ = TAB;
            todo -= (int) curbuf->b_p_ts;
        }
    }
    while (todo > 0) {
        *s++ = ' ';
        --todo;
    }
    mch_memmove (s, p, (size_t) line_len);
    if (!(flags & SIN_UNDO) || u_savesub (curwin->w_cursor.lnum) == OK) {
        ml_replace (curwin -> w_cursor.lnum, newline, FALSE);
        if (flags & SIN_CHANGED)
            changed_bytes (curwin->w_cursor.lnum, 0);
        if (saved_cursor.lnum == curwin->w_cursor.lnum) {
            if (saved_cursor.col >= (colnr_T) (p - oldline))
                saved_cursor.col += ind_len - (colnr_T) (p - oldline);
            else if (saved_cursor.col >= (colnr_T) (s - newline))
                saved_cursor.col = (colnr_T) (s - newline);
        }
        retval = TRUE;
    }
    else
        vim_free (newline);
    curwin->w_cursor.col = ind_len;
    return retval;
}

void changed_lines (linenr_T lnum, colnr_T col, linenr_T lnume, long  xtra) {
    changed_lines_buf (curbuf, lnum, lnume, xtra);
    if (xtra == 0 && curwin->w_p_diff) {
        win_T *wp;
        linenr_T wlnum;
        FOR_ALL_WINDOWS (wp)
            if (wp->w_p_diff && wp != curwin) {
                redraw_win_later (wp, VALID);
                wlnum = diff_lnum_win (lnum, wp);
                if (wlnum > 0)
                    changed_lines_buf (wp->w_buffer, wlnum, lnume -lnum + wlnum, 0L);
            }
    }
    changed_common (lnum, col, lnume, xtra);
}

static void changed_lines_buf (buf_T *buf, linenr_T lnum, linenr_T lnume, long  xtra) {
    if (buf->b_mod_set) {
        if (lnum < buf->b_mod_top)
            buf->b_mod_top = lnum;
        if (lnum < buf->b_mod_bot) {
            buf->b_mod_bot += xtra;
            if (buf->b_mod_bot < lnum)
                buf->b_mod_bot = lnum;
        }
        if (lnume + xtra > buf->b_mod_bot)
            buf->b_mod_bot = lnume + xtra;
        buf->b_mod_xlines += xtra;
    }
    else {
        buf->b_mod_set = TRUE;
        buf->b_mod_top = lnum;
        buf->b_mod_bot = lnume + xtra;
        buf->b_mod_xlines = xtra;
    }
}

void ins_str (char_u *s) {
    char_u *oldp, *newp;
    int newlen = (int) STRLEN (s);
    int oldlen;
    colnr_T col;
    linenr_T lnum = curwin->w_cursor.lnum;
    if (virtual_active () && curwin->w_cursor.coladd > 0)
        coladvance_force (getviscol ());
    col = curwin->w_cursor.col;
    oldp = ml_get (lnum);
    oldlen = (int) STRLEN (oldp);
    newp = alloc_check ((unsigned ) (oldlen + newlen + 1));
    if (newp == NULL)
        return;
    if (col > 0)
        mch_memmove (newp, oldp, (size_t) col);
    mch_memmove (newp + col, s, (size_t) newlen);
    mch_memmove (newp + col + newlen, oldp + col, (size_t) (oldlen - col + 1));
    ml_replace (lnum, newp, FALSE);
    changed_bytes (lnum, col);
    curwin->w_cursor.col += newlen;
}

void ins_bytes_len (char_u *p, int len) {
    int i;
    for (i = 0; i < len; ++i)
        ins_char (p[i]);
}

void ins_char_bytes (char_u *buf, int charlen) {
    int c = buf[0];
    int newlen;
    int oldlen;
    char_u *p;
    char_u *newp;
    char_u *oldp;
    int linelen;
    colnr_T col;
    linenr_T lnum = curwin->w_cursor.lnum;
    int i;
    if (virtual_active () && curwin->w_cursor.coladd > 0)
        coladvance_force (getviscol ());
    col = curwin->w_cursor.col;
    oldp = ml_get (lnum);
    linelen = (int) STRLEN (oldp) + 1;
    oldlen = 0;
    newlen = charlen;
    if (State & REPLACE_FLAG) {
        if (State & VREPLACE_FLAG) {
            colnr_T new_vcol = 0;
            colnr_T vcol;
            int old_list;
            char_u buf [2];
            old_list = curwin->w_p_list;
            if (old_list && vim_strchr (p_cpo, CPO_LISTWM) == NULL)
                curwin->w_p_list = FALSE;
            getvcol (curwin, & curwin -> w_cursor, NULL, & vcol, NULL);
            buf[0] = c;
            buf[1] = NUL;
            new_vcol = vcol + chartabsize (buf, vcol);
            while (oldp[col + oldlen] != NUL && vcol < new_vcol) {
                vcol += chartabsize (oldp +col + oldlen, vcol);
                if (vcol > new_vcol && oldp[col + oldlen] == TAB)
                    break;
                ++oldlen;
                if (vcol > new_vcol)
                    newlen += vcol - new_vcol;
            }
            curwin->w_p_list = old_list;
        }
        else if (oldp[col] != NUL) {
            oldlen = 1;
        }
        replace_push (NUL);
        for (i = 0; i < oldlen; ++i) {
            replace_push (oldp [col + i]);
        }
    }
    newp = alloc_check ((unsigned ) (linelen + newlen - oldlen));
    if (newp == NULL)
        return;
    if (col > 0)
        mch_memmove (newp, oldp, (size_t) col);
    p = newp + col;
    if (linelen > col + oldlen)
        mch_memmove (p +newlen, oldp +col + oldlen, (size_t) (linelen - col - oldlen));
    *p = c;
    i = 1;
    while (i < newlen)
        p[i++] = ' ';
    ml_replace (lnum, newp, FALSE);
    changed_bytes (lnum, col);
    if (p_sm && (State & INSERT) && msg_silent == 0 && !ins_compl_active ()) {
        showmatch (c);
    }
    if (!p_ri || (State & REPLACE_FLAG)) {
        ++curwin->w_cursor.col;
    }
}

void ins_char (int c) {
    char_u buf [MB_MAXBYTES + 1];
    int n = 1;
    buf[0] = c;
    ins_char_bytes (buf, n);
}

void ins_bytes (char_u *p) {
    ins_bytes_len (p, (int) STRLEN (p));
}

int get_lisp_indent (void) {
    pos_T *pos, realpos, paren;
    int amount;
    char_u *that;
    colnr_T col;
    colnr_T firsttry;
    int parencount, quotecount;
    int vi_lisp;
    vi_lisp = (vim_strchr (p_cpo, CPO_LISP) != NULL);
    realpos = curwin->w_cursor;
    curwin->w_cursor.col = 0;
    if ((pos = findmatch (NULL, '(')) == NULL)
        pos = findmatch (NULL, '[');
    else {
        paren = *pos;
        pos = findmatch (NULL, '[');
        if (pos == NULL || LT_POSP (pos, &paren))
            pos = &paren;
    }
    if (pos != NULL) {
        amount = -1;
        parencount = 0;
        while (--curwin->w_cursor.lnum >= pos->lnum) {
            if (linewhite (curwin->w_cursor.lnum))
                continue;
            for (that = ml_get_curline (); *that != NUL; ++that) {
                if (*that == ';') {
                    while (*(that + 1) != NUL)
                        ++that;
                    continue;
                }
                if (*that == '\\') {
                    if (*(that + 1) != NUL)
                        ++that;
                    continue;
                }
                if (*that == '"' && *(that + 1) != NUL) {
                    while (*++that && *that != '"') {
                        if (*that == '\\') {
                            if (*++that == NUL)
                                break;
                            if (that[1] == NUL) {
                                ++that;
                                break;
                            }
                        }
                    }
                }
                if (*that == '(' || *that == '[')
                    ++parencount;
                else if (*that == ')' || *that == ']')
                    --parencount;
            }
            if (parencount == 0) {
                amount = get_indent ();
                break;
            }
        }
        if (amount == -1) {
            curwin->w_cursor.lnum = pos->lnum;
            curwin->w_cursor.col = pos->col;
            col = pos->col;
            that = ml_get_curline ();
            if (vi_lisp && get_indent () == 0)
                amount = 2;
            else {
                char_u *line = that;
                amount = 0;
                while (*that && col) {
                    amount += lbr_chartabsize_adv (line, &that, (colnr_T) amount);
                    col--;
                }
                if (!vi_lisp && (*that == '(' || *that == '[') && lisp_match (that +1))
                    amount += 2;
                else {
                    that++;
                    amount++;
                    firsttry = amount;
                    while (VIM_ISWHITE (*that)) {
                        amount += lbr_chartabsize (line, that, (colnr_T) amount);
                        ++that;
                    }
                    if (*that && *that != ';') {
                        if (!vi_lisp && *that != '(' && *that != '[')
                            firsttry++;
                        parencount = 0;
                        quotecount = 0;
                        if (vi_lisp || (*that != '"' && *that != '\'' && *that != '#' && (*that < '0' || *that > '9'))) {
                            while (*that && (!VIM_ISWHITE (*that) || quotecount || parencount) && (!((*that == '(' || *that == '[') && !quotecount && !parencount && vi_lisp))) {
                                if (*that == '"')
                                    quotecount = !quotecount;
                                if ((*that == '(' || *that == '[') && !quotecount)
                                    ++parencount;
                                if ((*that == ')' || *that == ']') && !quotecount)
                                    --parencount;
                                if (*that == '\\' && *(that + 1) != NUL)
                                    amount += lbr_chartabsize_adv (line, &that, (colnr_T) amount);
                                amount += lbr_chartabsize_adv (line, &that, (colnr_T) amount);
                            }
                        }
                        while (VIM_ISWHITE (*that)) {
                            amount += lbr_chartabsize (line, that, (colnr_T) amount);
                            that++;
                        }
                        if (!*that || *that == ';')
                            amount = firsttry;
                    }
                }
            }
        }
    }
    else
        amount = 0;
    curwin->w_cursor = realpos;
    return amount;
}

static int lisp_match (char_u *p) {
    char_u buf [LSIZE];
    int len;
    char_u *word = *curbuf->b_p_lw != NUL ? curbuf->b_p_lw : p_lispwords;
    while (*word != NUL) {
        (void) copy_option_part (&word, buf, LSIZE, ",");
        len = (int) STRLEN (buf);
        if (STRNCMP (buf, p, len) == 0 && p[len] == ' ')
            return TRUE;
    }
    return FALSE;
}

int cin_iscase (char_u *s, int strict) {
    s = cin_skipcomment (s);
    if (cin_starts_with (s, "case")) {
        for (s += 4; *s; ++s) {
            s = cin_skipcomment (s);
            if (*s == ':') {
                if (s[1] == ':')
                    ++s;
                else
                    return TRUE;
            }
            if (*s == '\'' && s[1] && s[2] == '\'')
                s += 2;
            else if (*s == '/' && (s[1] == '*' || s[1] == '/'))
                return FALSE;
            else if (*s == '"') {
                if (strict)
                    return FALSE;
                else
                    return TRUE;
            }
        }
        return FALSE;
    }
    if (cin_isdefault (s))
        return TRUE;
    return FALSE;
}

static char_u *cin_skipcomment (char_u *s) {
    while (*s) {
        char_u *prev_s = s;
        s = skipwhite (s);
        if (curbuf->b_ind_hash_comment != 0 && s != prev_s && *s == '#') {
            s += STRLEN (s);
            break;
        }
        if (*s != '/')
            break;
        ++s;
        if (*s == '/') {
            s += STRLEN (s);
            break;
        }
        if (*s != '*')
            break;
        for (++s; *s; ++s)
            if (s[0] == '*' && s[1] == '/') {
                s += 2;
                break;
            }
    }
    return s;
}

static int cin_starts_with (char_u *s, char *word) {
    int l = (int) STRLEN (word);
    return (STRNCMP (s, word, l) == 0 && !vim_isIDc (s[l]));
}

static int cin_isdefault (char_u *s) {
    return (STRNCMP (s, "default", 7) == 0 && *(s = cin_skipcomment (s +7)) == ':' && s[1] != ':');
}

int cin_isscopedecl (char_u *s) {
    int i;
    s = cin_skipcomment (s);
    if (STRNCMP (s, "public", 6) == 0)
        i = 6;
    else if (STRNCMP (s, "protected", 9) == 0)
        i = 9;
    else if (STRNCMP (s, "private", 7) == 0)
        i = 7;
    else
        return FALSE;
    return (*(s = cin_skipcomment (s +i)) == ':' && s[1] != ':');
}

#define FIND_NAMESPACE_LIM 20

int cin_islabel (void) {
    char_u *s;
    s = cin_skipcomment (ml_get_curline ());
    if (cin_isdefault (s))
        return FALSE;
    if (cin_isscopedecl (s))
        return FALSE;
    if (cin_islabel_skip (&s)) {
        pos_T cursor_save;
        pos_T *trypos;
        char_u *line;
        cursor_save = curwin->w_cursor;
        while (curwin->w_cursor.lnum > 1) {
            --curwin->w_cursor.lnum;
            curwin->w_cursor.col = 0;
            if ((trypos = ind_find_start_CORS (NULL)) != NULL)
                curwin->w_cursor = *trypos;
            line = ml_get_curline ();
            if (cin_ispreproc (line))
                continue;
            if (*(line = cin_skipcomment (line)) == NUL)
                continue;
            curwin->w_cursor = cursor_save;
            if (cin_isterminated (line, TRUE, FALSE) || cin_isscopedecl (line) || cin_iscase (line, TRUE) || (cin_islabel_skip (&line) && cin_nocode (line)))
                return TRUE;
            return FALSE;
        }
        curwin->w_cursor = cursor_save;
        return TRUE;
    }
    return FALSE;
}

static int cin_islabel_skip (char_u **s) {
    if (!vim_isIDc (**s))
        return FALSE;
    while (vim_isIDc (**s))
        (*s)++;
    *s = cin_skipcomment (*s);
    return (**s == ':' && *++*s != ':');
}

static pos_T *ind_find_start_CORS (linenr_T *is_raw) {
    static pos_T comment_pos_copy;
    pos_T *comment_pos;
    pos_T *rs_pos;
    comment_pos = find_start_comment (curbuf->b_ind_maxcomment);
    if (comment_pos != NULL) {
        comment_pos_copy = *comment_pos;
        comment_pos = &comment_pos_copy;
    }
    rs_pos = find_start_rawstring (curbuf->b_ind_maxcomment);
    if (comment_pos == NULL || (rs_pos != NULL && LT_POS (*rs_pos, *comment_pos))) {
        if (is_raw != NULL && rs_pos != NULL)
            *is_raw = rs_pos->lnum;
        return rs_pos;
    }
    return comment_pos;
}

static pos_T *find_start_rawstring (int ind_maxcomment) {
    pos_T *pos;
    char_u *line;
    char_u *p;
    int cur_maxcomment = ind_maxcomment;
    for (;;) {
        pos = findmatchlimit (NULL, 'R', FM_BACKWARD, cur_maxcomment);
        if (pos == NULL)
            break;
        line = ml_get (pos->lnum);
        for (p = line; *p && (colnr_T) (p - line) < pos->col; ++p)
            p = skip_string (p);
        if ((colnr_T) (p - line) <= pos->col)
            break;
        cur_maxcomment = curwin->w_cursor.lnum - pos->lnum - 1;
        if (cur_maxcomment <= 0) {
            pos = NULL;
            break;
        }
    }
    return pos;
}

static int cin_ispreproc (char_u *s) {
    if (*skipwhite (s) == '#')
        return TRUE;
    return FALSE;
}

static int cin_isterminated (char_u *s, int incl_open, int incl_comma) {
    char_u found_start = 0;
    unsigned  n_open = 0;
    int is_else = FALSE;
    s = cin_skipcomment (s);
    if (*s == '{' || (*s == '}' && !cin_iselse (s)))
        found_start = *s;
    if (!found_start)
        is_else = cin_iselse (s);
    while (*s) {
        s = skip_string (cin_skipcomment (s));
        if (*s == '}' && n_open > 0)
            --n_open;
        if ((!is_else || n_open == 0) && (*s == ';' || *s == '}' || (incl_comma && *s == ',')) && cin_nocode (s +1))
            return *s;
        else if (*s == '{') {
            if (incl_open && cin_nocode (s +1))
                return *s;
            else
                ++n_open;
        }
        if (*s)
            s++;
    }
    return found_start;
}

static int cin_iselse (char_u *p) {
    if (*p == '}')
        p = cin_skipcomment (p +1);
    return (STRNCMP (p, "else", 4) == 0 && !vim_isIDc (p[4]));
}

static int cin_nocode (char_u *s) {
    return *cin_skipcomment (s) == NUL;
}

void do_c_expr_indent (void) {
    if (*curbuf->b_p_inde != NUL)
        fixthisline (get_expr_indent);
    else
        fixthisline (get_c_indent);
}

int get_expr_indent (void) {
    int indent = -1;
    char_u *inde_copy;
    pos_T save_pos;
    colnr_T save_curswant;
    int save_set_curswant;
    int save_State;
    int use_sandbox = was_set_insecurely ((char_u *) "indentexpr", OPT_LOCAL);
    save_pos = curwin->w_cursor;
    save_curswant = curwin->w_curswant;
    save_set_curswant = curwin->w_set_curswant;
    set_vim_var_nr (VV_LNUM, curwin -> w_cursor.lnum);
    if (use_sandbox)
        ++sandbox;
    ++textlock;
    inde_copy = vim_strsave (curbuf->b_p_inde);
    if (inde_copy != NULL) {
        indent = (int) eval_to_number (inde_copy);
        vim_free (inde_copy);
    }
    if (use_sandbox)
        --sandbox;
    --textlock;
    save_State = State;
    State = INSERT;
    curwin->w_cursor = save_pos;
    curwin->w_curswant = save_curswant;
    curwin->w_set_curswant = save_set_curswant;
    check_cursor ();
    State = save_State;
    if (indent < 0)
        indent = get_indent ();
    return indent;
}

int get_c_indent (void) {
    pos_T cur_curpos;
    int amount;
    int scope_amount;
    int cur_amount = MAXCOL;
    colnr_T col;
    char_u *theline;
    char_u *linecopy;
    pos_T *trypos;
    pos_T *comment_pos;
    pos_T *tryposBrace = NULL;
    pos_T tryposCopy;
    pos_T our_paren_pos;
    char_u *start;
    int start_brace;

    #define BRACE_IN_COL0		1	    /* '{' is in column 0 */

    #define BRACE_AT_START		2	    /* '{' is at start of line */

    #define BRACE_AT_END		3	    /* '{' is at end of line */
    linenr_T ourscope;
    char_u *l;
    char_u *look;
    char_u terminated;
    int lookfor;

    #define LOOKFOR_INITIAL		0

    #define LOOKFOR_IF		1

    #define LOOKFOR_DO		2

    #define LOOKFOR_CASE		3

    #define LOOKFOR_ANY		4

    #define LOOKFOR_TERM		5

    #define LOOKFOR_UNTERM		6

    #define LOOKFOR_SCOPEDECL	7

    #define LOOKFOR_NOBREAK		8

    #define LOOKFOR_CPP_BASECLASS	9

    #define LOOKFOR_ENUM_OR_INIT	10

    #define LOOKFOR_JS_KEY		11

    #define LOOKFOR_COMMA		12
    int whilelevel;
    linenr_T lnum;
    int n;
    int iscase;
    int lookfor_break;
    int lookfor_cpp_namespace = FALSE;
    int cont_amount = 0;
    int original_line_islabel;
    int added_to_amount = 0;
    int js_cur_has_key = 0;
    linenr_T raw_string_start = 0;
    cpp_baseclass_cache_T cache_cpp_baseclass = {FALSE, {MAXLNUM, 0}};
    int ind_continuation = curbuf->b_ind_continuation;
    cur_curpos = curwin->w_cursor;
    if (cur_curpos.lnum == 1)
        return 0;
    linecopy = vim_strsave (ml_get (cur_curpos.lnum));
    if (linecopy == NULL)
        return 0;
    if ((State & INSERT) && curwin->w_cursor.col < (colnr_T) STRLEN (linecopy) && linecopy[curwin->w_cursor.col] == ')')
        linecopy[curwin->w_cursor.col] = NUL;
    theline = skipwhite (linecopy);
    curwin->w_cursor.col = 0;
    original_line_islabel = cin_islabel ();
    comment_pos = ind_find_start_comment ();
    if (comment_pos != NULL) {
        tryposCopy = *comment_pos;
        comment_pos = &tryposCopy;
    }
    trypos = find_start_rawstring (curbuf->b_ind_maxcomment);
    if (trypos != NULL && (comment_pos == NULL || LT_POS (*trypos, *comment_pos))) {
        amount = -1;
        goto laterend;
    }
    if (*theline == '#' && (*linecopy == '#' || in_cinkeys ('#', ' ', TRUE))) {
        amount = curbuf->b_ind_hash_comment;
        goto theend;
    }
    if (original_line_islabel && !curbuf->b_ind_js && curbuf->b_ind_jump_label < 0) {
        amount = 0;
        goto theend;
    }
    if (cin_islinecomment (theline) && (trypos = find_line_comment ()) != NULL) {
        getvcol (curwin, trypos, & col, NULL, NULL);
        amount = col;
        goto theend;
    }
    if (!cin_iscomment (theline) && comment_pos != NULL) {
        int lead_start_len = 2;
        int lead_middle_len = 1;
        char_u lead_start [COM_MAX_LEN];
        char_u lead_middle [COM_MAX_LEN];
        char_u lead_end [COM_MAX_LEN];
        char_u *p;
        int start_align = 0;
        int start_off = 0;
        int done = FALSE;
        getvcol (curwin, comment_pos, & col, NULL, NULL);
        amount = col;
        *lead_start = NUL;
        *lead_middle = NUL;
        p = curbuf->b_p_com;
        while (*p != NUL) {
            int align = 0;
            int off = 0;
            int what = 0;
            while (*p != NUL && *p != ':') {
                if (*p == COM_START || *p == COM_END || *p == COM_MIDDLE)
                    what = *p++;
                else if (*p == COM_LEFT || *p == COM_RIGHT)
                    align = *p++;
                else if (VIM_ISDIGIT (*p) || *p == '-')
                    off = getdigits (&p);
                else
                    ++p;
            }
            if (*p == ':')
                ++p;
            (void) copy_option_part (&p, lead_end, COM_MAX_LEN, ",");
            if (what == COM_START) {
                STRCPY (lead_start, lead_end);
                lead_start_len = (int) STRLEN (lead_start);
                start_off = off;
                start_align = align;
            }
            else if (what == COM_MIDDLE) {
                STRCPY (lead_middle, lead_end);
                lead_middle_len = (int) STRLEN (lead_middle);
            }
            else if (what == COM_END) {
                if (STRNCMP (theline, lead_middle, lead_middle_len) == 0 && STRNCMP (theline, lead_end, STRLEN (lead_end)) != 0) {
                    done = TRUE;
                    if (curwin->w_cursor.lnum > 1) {
                        look = skipwhite (ml_get (curwin->w_cursor.lnum - 1));
                        if (STRNCMP (look, lead_start, lead_start_len) == 0)
                            amount = get_indent_lnum (curwin->w_cursor.lnum - 1);
                        else if (STRNCMP (look, lead_middle, lead_middle_len) == 0) {
                            amount = get_indent_lnum (curwin->w_cursor.lnum - 1);
                            break;
                        }
                        else if (STRNCMP (ml_get (comment_pos->lnum) + comment_pos->col, lead_start, lead_start_len) != 0)
                            continue;
                    }
                    if (start_off != 0)
                        amount += start_off;
                    else if (start_align == COM_RIGHT)
                        amount += vim_strsize (lead_start) - vim_strsize (lead_middle);
                    break;
                }
                if (STRNCMP (theline, lead_middle, lead_middle_len) != 0 && STRNCMP (theline, lead_end, STRLEN (lead_end)) == 0) {
                    amount = get_indent_lnum (curwin->w_cursor.lnum - 1);
                    if (off != 0)
                        amount += off;
                    else if (align == COM_RIGHT)
                        amount += vim_strsize (lead_start) - vim_strsize (lead_middle);
                    done = TRUE;
                    break;
                }
            }
        }
        if (done)
            ;
        else if (theline[0] == '*')
            amount += 1;
        else {
            amount = -1;
            for (lnum = cur_curpos.lnum - 1; lnum > comment_pos->lnum; --lnum) {
                if (linewhite (lnum))
                    continue;
                amount = get_indent_lnum (lnum);
                break;
            }
            if (amount == -1) {
                if (!curbuf->b_ind_in_comment2) {
                    start = ml_get (comment_pos->lnum);
                    look = start + comment_pos->col + 2;
                    if (*look != NUL)
                        comment_pos->col = (colnr_T) (skipwhite (look) - start);
                }
                getvcol (curwin, comment_pos, & col, NULL, NULL);
                amount = col;
                if (curbuf->b_ind_in_comment2 || *look == NUL)
                    amount += curbuf->b_ind_in_comment;
            }
        }
        goto theend;
    }
    if (*skipwhite (theline) == ']' && (trypos = find_match_char ('[', curbuf->b_ind_maxparen)) != NULL) {
        amount = get_indent_lnum (trypos->lnum);
        goto theend;
    }
    if (((trypos = find_match_paren (curbuf->b_ind_maxparen)) != NULL && curbuf->b_ind_java == 0) || (tryposBrace = find_start_brace ()) != NULL || trypos != NULL) {
        if (trypos != NULL && tryposBrace != NULL) {
            if (trypos->lnum != tryposBrace->lnum ? trypos->lnum < tryposBrace->lnum : trypos->col < tryposBrace->col)
                trypos = NULL;
            else
                tryposBrace = NULL;
        }
        if (trypos != NULL) {
            if (theline[0] == ')' && curbuf->b_ind_paren_prev) {
                amount = get_indent_lnum (curwin->w_cursor.lnum - 1);
            }
            else {
                amount = -1;
                our_paren_pos = *trypos;
                for (lnum = cur_curpos.lnum - 1; lnum > our_paren_pos.lnum; --lnum) {
                    l = skipwhite (ml_get (lnum));
                    if (cin_nocode (l))
                        continue;
                    if (cin_ispreproc_cont (&l, &lnum, &amount))
                        continue;
                    curwin->w_cursor.lnum = lnum;
                    if ((trypos = ind_find_start_CORS (NULL)) != NULL) {
                        lnum = trypos->lnum + 1;
                        continue;
                    }
                    if ((trypos = find_match_paren (corr_ind_maxparen (&cur_curpos))) != NULL && trypos->lnum == our_paren_pos.lnum && trypos->col == our_paren_pos.col) {
                        amount = get_indent_lnum (lnum);
                        if (theline[0] == ')') {
                            if (our_paren_pos.lnum != lnum && cur_amount > amount)
                                cur_amount = amount;
                            amount = -1;
                        }
                        break;
                    }
                }
            }
            if (amount == -1) {
                int ignore_paren_col = 0;
                int is_if_for_while = 0;
                if (curbuf->b_ind_if_for_while) {
                    pos_T cursor_save = curwin->w_cursor;
                    pos_T outermost;
                    char_u *line;
                    trypos = &our_paren_pos;
                    do {
                        outermost = *trypos;
                        curwin->w_cursor.lnum = outermost.lnum;
                        curwin->w_cursor.col = outermost.col;
                        trypos = find_match_paren (curbuf->b_ind_maxparen);
                    }
                    while (trypos && trypos->lnum == outermost.lnum);
                    curwin->w_cursor = cursor_save;
                    line = ml_get (outermost.lnum);
                    is_if_for_while = cin_is_if_for_while_before_offset (line, &outermost.col);
                }
                amount = skip_label (our_paren_pos.lnum, &look);
                look = skipwhite (look);
                if (*look == '(') {
                    linenr_T save_lnum = curwin->w_cursor.lnum;
                    char_u *line;
                    int look_col;
                    curwin->w_cursor.lnum = our_paren_pos.lnum;
                    line = ml_get_curline ();
                    look_col = (int) (look - line);
                    curwin->w_cursor.col = look_col + 1;
                    if ((trypos = findmatchlimit (NULL, ')', 0, curbuf->b_ind_maxparen)) != NULL && trypos->lnum == our_paren_pos.lnum && trypos->col < our_paren_pos.col)
                        ignore_paren_col = trypos->col + 1;
                    curwin->w_cursor.lnum = save_lnum;
                    look = ml_get (our_paren_pos.lnum) + look_col;
                }
                if (theline[0] == ')' || (curbuf->b_ind_unclosed == 0 && is_if_for_while == 0) || (!curbuf->b_ind_unclosed_noignore && *look == '(' && ignore_paren_col == 0)) {
                    if (theline[0] != ')') {
                        cur_amount = MAXCOL;
                        l = ml_get (our_paren_pos.lnum);
                        if (curbuf->b_ind_unclosed_wrapped && cin_ends_in (l, (char_u *) "(", NULL)) {
                            n = 1;
                            for (col = 0; col < our_paren_pos.col; ++col) {
                                switch (l[col]) {
                                case '(' :
                                case '{' :
                                    ++n;
                                    break;
                                case ')' :
                                case '}' :
                                    if (n > 1)
                                        --n;
                                    break;
                                }
                            }
                            our_paren_pos.col = 0;
                            amount += n * curbuf->b_ind_unclosed_wrapped;
                        }
                        else if (curbuf->b_ind_unclosed_whiteok)
                            our_paren_pos.col++;
                        else {
                            col = our_paren_pos.col + 1;
                            while (VIM_ISWHITE (l[col]))
                                col++;
                            if (l[col] != NUL)
                                our_paren_pos.col = col;
                            else
                                our_paren_pos.col++;
                        }
                    }
                    if (our_paren_pos.col > 0) {
                        getvcol (curwin, & our_paren_pos, & col, NULL, NULL);
                        if (cur_amount > (int) col)
                            cur_amount = col;
                    }
                }
                if (theline[0] == ')' && curbuf->b_ind_matching_paren) {
                }
                else if ((curbuf->b_ind_unclosed == 0 && is_if_for_while == 0) || (!curbuf->b_ind_unclosed_noignore && *look == '(' && ignore_paren_col == 0)) {
                    if (cur_amount != MAXCOL)
                        amount = cur_amount;
                }
                else {
                    col = our_paren_pos.col;
                    while ((int) our_paren_pos.col > ignore_paren_col) {
                        --our_paren_pos.col;
                        switch (*ml_get_pos (&our_paren_pos)) {
                        case '(' :
                            amount += curbuf->b_ind_unclosed2;
                            col = our_paren_pos.col;
                            break;
                        case ')' :
                            amount -= curbuf->b_ind_unclosed2;
                            col = MAXCOL;
                            break;
                        }
                    }
                    if (col == MAXCOL)
                        amount += curbuf->b_ind_unclosed;
                    else {
                        curwin->w_cursor.lnum = our_paren_pos.lnum;
                        curwin->w_cursor.col = col;
                        if (find_match_paren_after_brace (curbuf->b_ind_maxparen) != NULL)
                            amount += curbuf->b_ind_unclosed2;
                        else {
                            if (is_if_for_while)
                                amount += curbuf->b_ind_if_for_while;
                            else
                                amount += curbuf->b_ind_unclosed;
                        }
                    }
                    if (cur_amount < amount)
                        amount = cur_amount;
                }
            }
            if (cin_iscomment (theline))
                amount += curbuf->b_ind_comment;
        }
        else {
            tryposCopy = *tryposBrace;
            tryposBrace = &tryposCopy;
            trypos = tryposBrace;
            ourscope = trypos->lnum;
            start = ml_get (ourscope);
            look = skipwhite (start);
            if (*look == '{') {
                getvcol (curwin, trypos, & col, NULL, NULL);
                amount = col;
                if (*start == '{')
                    start_brace = BRACE_IN_COL0;
                else
                    start_brace = BRACE_AT_START;
            }
            else {
                curwin->w_cursor.lnum = ourscope;
                lnum = ourscope;
                if (find_last_paren (start, '(', ')') && (trypos = find_match_paren (curbuf->b_ind_maxparen)) != NULL)
                    lnum = trypos->lnum;
                if ((curbuf->b_ind_js || curbuf->b_ind_keep_case_label) && cin_iscase (skipwhite (ml_get_curline ()), FALSE))
                    amount = get_indent ();
                else if (curbuf->b_ind_js)
                    amount = get_indent_lnum (lnum);
                else
                    amount = skip_label (lnum, &l);
                start_brace = BRACE_AT_END;
            }
            if (curbuf->b_ind_js)
                js_cur_has_key = cin_has_js_key (theline);
            if (theline[0] == '}') {
                amount += curbuf->b_ind_close_extra;
            }
            else {
                lookfor = LOOKFOR_INITIAL;
                if (cin_iselse (theline))
                    lookfor = LOOKFOR_IF;
                else if (cin_iswhileofdo (theline, cur_curpos.lnum))
                    lookfor = LOOKFOR_DO;
                if (lookfor != LOOKFOR_INITIAL) {
                    curwin->w_cursor.lnum = cur_curpos.lnum;
                    if (find_match (lookfor, ourscope) == OK) {
                        amount = get_indent ();
                        goto theend;
                    }
                }
                if (start_brace == BRACE_IN_COL0) {
                    amount = curbuf->b_ind_open_left_imag;
                    lookfor_cpp_namespace = TRUE;
                }
                else if (start_brace == BRACE_AT_START && lookfor_cpp_namespace) {
                    lookfor_cpp_namespace = TRUE;
                }
                else {
                    if (start_brace == BRACE_AT_END) {
                        amount += curbuf->b_ind_open_imag;
                        l = skipwhite (ml_get_curline ());
                        if (cin_is_cpp_namespace (l))
                            amount += curbuf->b_ind_cpp_namespace;
                        else if (cin_is_cpp_extern_c (l))
                            amount += curbuf->b_ind_cpp_extern_c;
                    }
                    else {
                        amount -= curbuf->b_ind_open_extra;
                        if (amount < 0)
                            amount = 0;
                    }
                }
                lookfor_break = FALSE;
                if (cin_iscase (theline, FALSE)) {
                    lookfor = LOOKFOR_CASE;
                    amount += curbuf->b_ind_case;
                }
                else if (cin_isscopedecl (theline)) {
                    lookfor = LOOKFOR_SCOPEDECL;
                    amount += curbuf->b_ind_scopedecl;
                }
                else {
                    if (curbuf->b_ind_case_break && cin_isbreak (theline))
                        lookfor_break = TRUE;
                    lookfor = LOOKFOR_INITIAL;
                    amount += curbuf->b_ind_level;
                }
                scope_amount = amount;
                whilelevel = 0;
                curwin->w_cursor = cur_curpos;
                for (;;) {
                    curwin->w_cursor.lnum--;
                    curwin->w_cursor.col = 0;
                    if (curwin->w_cursor.lnum <= ourscope) {
                        if (lookfor == LOOKFOR_ENUM_OR_INIT) {
                            if (curwin->w_cursor.lnum == 0 || curwin->w_cursor.lnum < ourscope - curbuf->b_ind_maxparen) {
                                if (cont_amount > 0)
                                    amount = cont_amount;
                                else if (!curbuf->b_ind_js)
                                    amount += ind_continuation;
                                break;
                            }
                            l = ml_get_curline ();
                            trypos = ind_find_start_CORS (NULL);
                            if (trypos != NULL) {
                                curwin->w_cursor.lnum = trypos->lnum + 1;
                                curwin->w_cursor.col = 0;
                                continue;
                            }
                            if (cin_ispreproc_cont (&l, &curwin->w_cursor.lnum, &amount))
                                continue;
                            if (cin_nocode (l))
                                continue;
                            terminated = cin_isterminated (l, FALSE, TRUE);
                            if (start_brace != BRACE_IN_COL0 || !cin_isfuncdecl (&l, curwin->w_cursor.lnum, 0)) {
                                if (terminated == ',')
                                    break;
                                if (terminated != ';' && cin_isinit ())
                                    break;
                                if (terminated == 0 || terminated == '{')
                                    continue;
                            }
                            if (terminated != ';') {
                                trypos = NULL;
                                if (find_last_paren (l, '(', ')'))
                                    trypos = find_match_paren (curbuf->b_ind_maxparen);
                                if (trypos == NULL && find_last_paren (l, '{', '}'))
                                    trypos = find_start_brace ();
                                if (trypos != NULL) {
                                    curwin->w_cursor.lnum = trypos->lnum + 1;
                                    curwin->w_cursor.col = 0;
                                    continue;
                                }
                            }
                            if (cont_amount > 0)
                                amount = cont_amount;
                            else
                                amount += ind_continuation;
                        }
                        else if (lookfor == LOOKFOR_UNTERM) {
                            if (cont_amount > 0)
                                amount = cont_amount;
                            else
                                amount += ind_continuation;
                        }
                        else {
                            if (lookfor != LOOKFOR_TERM && lookfor != LOOKFOR_CPP_BASECLASS && lookfor != LOOKFOR_COMMA) {
                                amount = scope_amount;
                                if (theline[0] == '{') {
                                    amount += curbuf->b_ind_open_extra;
                                    added_to_amount = curbuf->b_ind_open_extra;
                                }
                            }
                            if (lookfor_cpp_namespace) {
                                if (curwin->w_cursor.lnum == ourscope)
                                    continue;
                                if (curwin->w_cursor.lnum == 0 || curwin->w_cursor.lnum < ourscope - FIND_NAMESPACE_LIM)
                                    break;
                                l = ml_get_curline ();
                                trypos = ind_find_start_CORS (NULL);
                                if (trypos != NULL) {
                                    curwin->w_cursor.lnum = trypos->lnum + 1;
                                    curwin->w_cursor.col = 0;
                                    continue;
                                }
                                if (cin_ispreproc_cont (&l, &curwin->w_cursor.lnum, &amount))
                                    continue;
                                if (cin_is_cpp_namespace (l)) {
                                    amount += curbuf->b_ind_cpp_namespace - added_to_amount;
                                    break;
                                }
                                else if (cin_is_cpp_extern_c (l)) {
                                    amount += curbuf->b_ind_cpp_extern_c - added_to_amount;
                                    break;
                                }
                                if (cin_nocode (l))
                                    continue;
                            }
                        }
                        break;
                    }
                    if ((trypos = ind_find_start_CORS (&raw_string_start)) != NULL) {
                        curwin->w_cursor.lnum = trypos->lnum + 1;
                        curwin->w_cursor.col = 0;
                        continue;
                    }
                    l = ml_get_curline ();
                    iscase = cin_iscase (l, FALSE);
                    if (iscase || cin_isscopedecl (l)) {
                        if (lookfor == LOOKFOR_CPP_BASECLASS)
                            break;
                        if (whilelevel > 0)
                            continue;
                        if (lookfor == LOOKFOR_UNTERM || lookfor == LOOKFOR_ENUM_OR_INIT) {
                            if (cont_amount > 0)
                                amount = cont_amount;
                            else
                                amount += ind_continuation;
                            break;
                        }
                        if ((iscase && lookfor == LOOKFOR_CASE) || (iscase && lookfor_break) || (!iscase && lookfor == LOOKFOR_SCOPEDECL)) {
                            if ((trypos = find_start_brace ()) == NULL || trypos->lnum == ourscope) {
                                amount = get_indent ();
                                break;
                            }
                            continue;
                        }
                        n = get_indent_nolabel (curwin->w_cursor.lnum);
                        if (lookfor == LOOKFOR_TERM) {
                            if (n)
                                amount = n;
                            if (!lookfor_break)
                                break;
                        }
                        if (n) {
                            amount = n;
                            l = after_label (ml_get_curline ());
                            if (l != NULL && cin_is_cinword (l)) {
                                if (theline[0] == '{')
                                    amount += curbuf->b_ind_open_extra;
                                else
                                    amount += curbuf->b_ind_level + curbuf->b_ind_no_brace;
                            }
                            break;
                        }
                        scope_amount = get_indent () + (iscase ? curbuf->b_ind_case_code : curbuf->b_ind_scopedecl_code);
                        lookfor = curbuf->b_ind_case_break ? LOOKFOR_NOBREAK : LOOKFOR_ANY;
                        continue;
                    }
                    if (lookfor == LOOKFOR_CASE || lookfor == LOOKFOR_SCOPEDECL) {
                        if (find_last_paren (l, '{', '}') && (trypos = find_start_brace ()) != NULL) {
                            curwin->w_cursor.lnum = trypos->lnum + 1;
                            curwin->w_cursor.col = 0;
                        }
                        continue;
                    }
                    if (!curbuf->b_ind_js && cin_islabel ()) {
                        l = after_label (ml_get_curline ());
                        if (l == NULL || cin_nocode (l))
                            continue;
                    }
                    l = ml_get_curline ();
                    if (cin_ispreproc_cont (&l, &curwin->w_cursor.lnum, &amount) || cin_nocode (l))
                        continue;
                    n = FALSE;
                    if (lookfor != LOOKFOR_TERM && curbuf->b_ind_cpp_baseclass > 0) {
                        n = cin_is_cpp_baseclass (&cache_cpp_baseclass);
                        l = ml_get_curline ();
                    }
                    if (n) {
                        if (lookfor == LOOKFOR_UNTERM) {
                            if (cont_amount > 0)
                                amount = cont_amount;
                            else
                                amount += ind_continuation;
                        }
                        else if (theline[0] == '{') {
                            lookfor = LOOKFOR_UNTERM;
                            ind_continuation = 0;
                            continue;
                        }
                        else
                            amount = get_baseclass_amount (cache_cpp_baseclass.lpos.col);
                        break;
                    }
                    else if (lookfor == LOOKFOR_CPP_BASECLASS) {
                        if (cin_isterminated (l, TRUE, FALSE))
                            break;
                        else
                            continue;
                    }
                    terminated = cin_isterminated (l, FALSE, TRUE);
                    if (js_cur_has_key) {
                        js_cur_has_key = 0;
                        if (curbuf->b_ind_js && terminated == ',') {
                            lookfor = LOOKFOR_JS_KEY;
                        }
                    }
                    if (lookfor == LOOKFOR_JS_KEY && cin_has_js_key (l)) {
                        amount = get_indent ();
                        break;
                    }
                    if (lookfor == LOOKFOR_COMMA) {
                        if (tryposBrace != NULL && tryposBrace->lnum >= curwin->w_cursor.lnum)
                            break;
                        if (terminated == ',')
                            break;
                        else {
                            amount = get_indent ();
                            if (curwin->w_cursor.lnum - 1 == ourscope)
                                break;
                        }
                    }
                    if (terminated == 0 || (lookfor != LOOKFOR_UNTERM && terminated == ',')) {
                        if (lookfor != LOOKFOR_ENUM_OR_INIT && (*skipwhite (l) == '[' || l[STRLEN (l) - 1] == '['))
                            amount += ind_continuation;
                        (void) find_last_paren (l, '(', ')');
                        trypos = find_match_paren (corr_ind_maxparen (&cur_curpos));
                        if (trypos != NULL && (trypos->lnum < tryposBrace->lnum || (trypos->lnum == tryposBrace->lnum && trypos->col < tryposBrace->col)))
                            trypos = NULL;
                        if (trypos == NULL && terminated == ',' && find_last_paren (l, '{', '}'))
                            trypos = find_start_brace ();
                        if (trypos != NULL) {
                            curwin->w_cursor = *trypos;
                            l = ml_get_curline ();
                            if (cin_iscase (l, FALSE) || cin_isscopedecl (l)) {
                                ++curwin->w_cursor.lnum;
                                curwin->w_cursor.col = 0;
                                continue;
                            }
                        }
                        if (terminated == ',') {
                            while (curwin->w_cursor.lnum > 1) {
                                l = ml_get (curwin->w_cursor.lnum - 1);
                                if (*l == NUL || l[STRLEN (l) - 1] != '\\')
                                    break;
                                --curwin->w_cursor.lnum;
                                curwin->w_cursor.col = 0;
                            }
                        }
                        if (curbuf->b_ind_js)
                            cur_amount = get_indent ();
                        else
                            cur_amount = skip_label (curwin->w_cursor.lnum, &l);
                        if (terminated != ',' && lookfor != LOOKFOR_TERM && theline[0] == '{') {
                            amount = cur_amount;
                            if (*skipwhite (l) != '{')
                                amount += curbuf->b_ind_open_extra;
                            if (curbuf->b_ind_cpp_baseclass && !curbuf->b_ind_js) {
                                lookfor = LOOKFOR_CPP_BASECLASS;
                                continue;
                            }
                            break;
                        }
                        if (cin_is_cinword (l) || cin_iselse (skipwhite (l))) {
                            if (lookfor == LOOKFOR_UNTERM || lookfor == LOOKFOR_ENUM_OR_INIT) {
                                if (cont_amount > 0)
                                    amount = cont_amount;
                                else
                                    amount += ind_continuation;
                                break;
                            }
                            amount = cur_amount;
                            if (theline[0] == '{')
                                amount += curbuf->b_ind_open_extra;
                            if (lookfor != LOOKFOR_TERM) {
                                amount += curbuf->b_ind_level + curbuf->b_ind_no_brace;
                                break;
                            }
                            l = skipwhite (ml_get_curline ());
                            if (cin_isdo (l)) {
                                if (whilelevel == 0)
                                    break;
                                --whilelevel;
                            }
                            if (cin_iselse (l) && whilelevel == 0) {
                                if (*l == '}')
                                    curwin->w_cursor.col = (colnr_T) (l - ml_get_curline ()) + 1;
                                if ((trypos = find_start_brace ()) == NULL || find_match (LOOKFOR_IF, trypos->lnum) == FAIL)
                                    break;
                            }
                        }
                        else {
                            if (lookfor == LOOKFOR_UNTERM) {
                                if (terminated == ',')
                                    amount += ind_continuation;
                                break;
                            }
                            if (lookfor == LOOKFOR_ENUM_OR_INIT) {
                                if (terminated == ',') {
                                    if (curbuf->b_ind_cpp_baseclass == 0)
                                        break;
                                    lookfor = LOOKFOR_CPP_BASECLASS;
                                    continue;
                                }
                                if (amount > cur_amount)
                                    amount = cur_amount;
                            }
                            else {
                                l = ml_get_curline ();
                                amount = cur_amount;
                                n = (int) STRLEN (l);
                                if (terminated == ',' && (*skipwhite (l) == ']' || (n >= 2 && l[n - 2] == ']')))
                                    break;
                                if (lookfor == LOOKFOR_INITIAL && terminated == ',') {
                                    if (curbuf->b_ind_js) {
                                        if (cin_iscomment (skipwhite (l)))
                                            break;
                                        lookfor = LOOKFOR_COMMA;
                                        trypos = find_match_char ('[', curbuf->b_ind_maxparen);
                                        if (trypos != NULL) {
                                            if (trypos->lnum == curwin->w_cursor.lnum - 1) {
                                                break;
                                            }
                                            ourscope = trypos->lnum;
                                        }
                                    }
                                    else {
                                        lookfor = LOOKFOR_ENUM_OR_INIT;
                                        cont_amount = cin_first_id_amount ();
                                    }
                                }
                                else {
                                    if (lookfor == LOOKFOR_INITIAL && *l != NUL && l[STRLEN (l) - 1] == '\\')
                                        cont_amount = cin_get_equal_amount (curwin->w_cursor.lnum);
                                    if (lookfor != LOOKFOR_TERM && lookfor != LOOKFOR_JS_KEY && lookfor != LOOKFOR_COMMA && raw_string_start != curwin->w_cursor.lnum)
                                        lookfor = LOOKFOR_UNTERM;
                                }
                            }
                        }
                    }
                    else if (cin_iswhileofdo_end (terminated)) {
                        if (lookfor == LOOKFOR_UNTERM || lookfor == LOOKFOR_ENUM_OR_INIT) {
                            if (cont_amount > 0)
                                amount = cont_amount;
                            else
                                amount += ind_continuation;
                            break;
                        }
                        if (whilelevel == 0) {
                            lookfor = LOOKFOR_TERM;
                            amount = get_indent ();
                            if (theline[0] == '{')
                                amount += curbuf->b_ind_open_extra;
                        }
                        ++whilelevel;
                    }
                    else {
                        if (lookfor == LOOKFOR_NOBREAK && cin_isbreak (skipwhite (ml_get_curline ()))) {
                            lookfor = LOOKFOR_ANY;
                            continue;
                        }
                        if (whilelevel > 0) {
                            l = cin_skipcomment (ml_get_curline ());
                            if (cin_isdo (l)) {
                                amount = get_indent ();
                                --whilelevel;
                                continue;
                            }
                        }
                        if (lookfor == LOOKFOR_UNTERM || lookfor == LOOKFOR_ENUM_OR_INIT) {
                            if (cont_amount > 0)
                                amount = cont_amount;
                            else
                                amount += ind_continuation;
                            break;
                        }
                        if (lookfor == LOOKFOR_TERM) {
                            if (!lookfor_break && whilelevel == 0)
                                break;
                        }
                        else {
                        term_again :
                            l = ml_get_curline ();
                            if (find_last_paren (l, '(', ')') && (trypos = find_match_paren (curbuf->b_ind_maxparen)) != NULL) {
                                curwin->w_cursor = *trypos;
                                l = ml_get_curline ();
                                if (cin_iscase (l, FALSE) || cin_isscopedecl (l)) {
                                    ++curwin->w_cursor.lnum;
                                    curwin->w_cursor.col = 0;
                                    continue;
                                }
                            }
                            iscase = (curbuf->b_ind_keep_case_label && cin_iscase (l, FALSE));
                            amount = skip_label (curwin->w_cursor.lnum, &l);
                            if (theline[0] == '{')
                                amount += curbuf->b_ind_open_extra;
                            l = skipwhite (l);
                            if (*l == '{')
                                amount -= curbuf->b_ind_open_extra;
                            lookfor = iscase ? LOOKFOR_ANY : LOOKFOR_TERM;
                            if (lookfor == LOOKFOR_TERM && *l != '}' && cin_iselse (l) && whilelevel == 0) {
                                if ((trypos = find_start_brace ()) == NULL || find_match (LOOKFOR_IF, trypos->lnum) == FAIL)
                                    break;
                                continue;
                            }
                            l = ml_get_curline ();
                            if (find_last_paren (l, '{', '}') && (trypos = find_start_brace ()) != NULL) {
                                curwin->w_cursor = *trypos;
                                l = cin_skipcomment (ml_get_curline ());
                                if (*l == '}' || !cin_iselse (l))
                                    goto term_again;
                                ++curwin->w_cursor.lnum;
                                curwin->w_cursor.col = 0;
                            }
                        }
                    }
                }
            }
        }
        if (cin_iscomment (theline))
            amount += curbuf->b_ind_comment;
        if (curbuf->b_ind_jump_label > 0 && original_line_islabel)
            amount -= curbuf->b_ind_jump_label;
        goto theend;
    }
    if (theline[0] == '{') {
        amount = curbuf->b_ind_first_open;
        goto theend;
    }
    if (cur_curpos.lnum < curbuf->b_ml.ml_line_count && !cin_nocode (theline) && vim_strchr (theline, '{') == NULL && vim_strchr (theline, '}') == NULL && !cin_ends_in (theline, (char_u *) ":", NULL) && !cin_ends_in (theline, (char_u *) ",", NULL) && cin_isfuncdecl (NULL, cur_curpos.lnum + 1, cur_curpos.lnum + 1) && !cin_isterminated (theline, FALSE, TRUE)) {
        amount = curbuf->b_ind_func_type;
        goto theend;
    }
    amount = 0;
    curwin->w_cursor = cur_curpos;
    while (curwin->w_cursor.lnum > 1) {
        curwin->w_cursor.lnum--;
        curwin->w_cursor.col = 0;
        l = ml_get_curline ();
        if ((trypos = ind_find_start_CORS (NULL)) != NULL) {
            curwin->w_cursor.lnum = trypos->lnum + 1;
            curwin->w_cursor.col = 0;
            continue;
        }
        n = FALSE;
        if (curbuf->b_ind_cpp_baseclass != 0 && theline[0] != '{') {
            n = cin_is_cpp_baseclass (&cache_cpp_baseclass);
            l = ml_get_curline ();
        }
        if (n) {
            amount = get_baseclass_amount (cache_cpp_baseclass.lpos.col);
            break;
        }
        if (cin_ispreproc_cont (&l, &curwin->w_cursor.lnum, &amount))
            continue;
        if (cin_nocode (l))
            continue;
        n = 0;
        if (cin_ends_in (l, (char_u *) ",", NULL) || (*l != NUL && (n = l[STRLEN (l) - 1]) == '\\')) {
            if (find_last_paren (l, '(', ')') && (trypos = find_match_paren (curbuf->b_ind_maxparen)) != NULL)
                curwin->w_cursor = *trypos;
            while (n == 0 && curwin->w_cursor.lnum > 1) {
                l = ml_get (curwin->w_cursor.lnum - 1);
                if (*l == NUL || l[STRLEN (l) - 1] != '\\')
                    break;
                --curwin->w_cursor.lnum;
                curwin->w_cursor.col = 0;
            }
            amount = get_indent ();
            if (amount == 0)
                amount = cin_first_id_amount ();
            if (amount == 0)
                amount = ind_continuation;
            break;
        }
        if (cin_isfuncdecl (NULL, cur_curpos.lnum, 0))
            break;
        l = ml_get_curline ();
        if (*skipwhite (l) == '}')
            break;
        if (cin_ends_in (l, (char_u *) "};", NULL))
            break;
        if (cin_ends_in (l, (char_u *) "[", NULL)) {
            amount = get_indent () + ind_continuation;
            break;
        }
        if (*(look = skipwhite (l)) == ';' && cin_nocode (look +1)) {
            pos_T curpos_save = curwin->w_cursor;
            while (curwin->w_cursor.lnum > 1) {
                look = ml_get (--curwin->w_cursor.lnum);
                if (!(cin_nocode (look) || cin_ispreproc_cont (&look, &curwin->w_cursor.lnum, &amount)))
                    break;
            }
            if (curwin->w_cursor.lnum > 0 && cin_ends_in (look, (char_u *) "}", NULL))
                break;
            curwin->w_cursor = curpos_save;
        }
        if (cin_isfuncdecl (&l, curwin->w_cursor.lnum, 0)) {
            amount = curbuf->b_ind_param;
            break;
        }
        if (cin_ends_in (l, (char_u *) ";", NULL)) {
            l = ml_get (curwin->w_cursor.lnum - 1);
            if (cin_ends_in (l, (char_u *) ",", NULL) || (*l != NUL && l[STRLEN (l) - 1] == '\\'))
                break;
            l = ml_get_curline ();
        }
        find_last_paren (l, '(', ')');
        if ((trypos = find_match_paren (curbuf->b_ind_maxparen)) != NULL)
            curwin->w_cursor = *trypos;
        amount = get_indent ();
        break;
    }
    if (cin_iscomment (theline))
        amount += curbuf->b_ind_comment;
    if (cur_curpos.lnum > 1) {
        l = ml_get (cur_curpos.lnum - 1);
        if (*l != NUL && l[STRLEN (l) - 1] == '\\') {
            cur_amount = cin_get_equal_amount (cur_curpos.lnum - 1);
            if (cur_amount > 0)
                amount = cur_amount;
            else if (cur_amount == 0)
                amount += ind_continuation;
        }
    }
theend :
    if (amount < 0)
        amount = 0;
laterend :
    curwin->w_cursor = cur_curpos;
    vim_free (linecopy);
    return amount;
}

static pos_T *ind_find_start_comment (void) {
    return find_start_comment (curbuf->b_ind_maxcomment);
}

static int cin_islinecomment (char_u *p) {
    return (p[0] == '/' && p[1] == '/');
}

static pos_T *find_line_comment (void) {
    static pos_T pos;
    char_u *line;
    char_u *p;
    pos = curwin->w_cursor;
    while (--pos.lnum > 0) {
        line = ml_get (pos.lnum);
        p = skipwhite (line);
        if (cin_islinecomment (p)) {
            pos.col = (int) (p - line);
            return &pos;
        }
        if (*p != NUL)
            break;
    }
    return NULL;
}

static int cin_iscomment (char_u *p) {
    return (p[0] == '/' && (p[1] == '*' || p[1] == '/'));
}

int get_indent_lnum (linenr_T lnum) {
    return get_indent_str (ml_get (lnum), (int) curbuf->b_p_ts, FALSE);
}

static pos_T *find_match_char (int c, int ind_maxparen) {
    pos_T cursor_save;
    pos_T *trypos;
    static pos_T pos_copy;
    int ind_maxp_wk;
    cursor_save = curwin->w_cursor;
    ind_maxp_wk = ind_maxparen;
retry :
    if ((trypos = findmatchlimit (NULL, c, 0, ind_maxp_wk)) != NULL) {
        if ((colnr_T) cin_skip2pos (trypos) > trypos->col) {
            ind_maxp_wk = ind_maxparen - (int) (cursor_save.lnum - trypos->lnum);
            if (ind_maxp_wk > 0) {
                curwin->w_cursor = *trypos;
                curwin->w_cursor.col = 0;
                goto retry;
            }
            trypos = NULL;
        }
        else {
            pos_T *trypos_wk;
            pos_copy = *trypos;
            trypos = &pos_copy;
            curwin->w_cursor = *trypos;
            if ((trypos_wk = ind_find_start_CORS (NULL)) != NULL) {
                ind_maxp_wk = ind_maxparen - (int) (cursor_save.lnum - trypos_wk->lnum);
                if (ind_maxp_wk > 0) {
                    curwin->w_cursor = *trypos_wk;
                    goto retry;
                }
                trypos = NULL;
            }
        }
    }
    curwin->w_cursor = cursor_save;
    return trypos;
}

static int cin_skip2pos (pos_T *trypos) {
    char_u *line;
    char_u *p;
    char_u *new_p;
    p = line = ml_get (trypos->lnum);
    while (*p && (colnr_T) (p - line) < trypos->col) {
        if (cin_iscomment (p))
            p = cin_skipcomment (p);
        else {
            new_p = skip_string (p);
            if (new_p == p)
                ++p;
            else
                p = new_p;
        }
    }
    return (int) (p - line);
}

static pos_T *find_match_paren (int ind_maxparen) {
    return find_match_char ('(', ind_maxparen);
}

static pos_T *find_start_brace (void) {
    pos_T cursor_save;
    pos_T *trypos;
    pos_T *pos;
    static pos_T pos_copy;
    cursor_save = curwin->w_cursor;
    while ((trypos = findmatchlimit (NULL, '{', FM_BLOCKSTOP, 0)) != NULL) {
        pos_copy = *trypos;
        trypos = &pos_copy;
        curwin->w_cursor = *trypos;
        pos = NULL;
        if ((colnr_T) cin_skip2pos (trypos) == trypos->col && (pos = ind_find_start_CORS (NULL)) == NULL)
            break;
        if (pos != NULL)
            curwin->w_cursor.lnum = pos->lnum;
    }
    curwin->w_cursor = cursor_save;
    return trypos;
}

static int cin_ispreproc_cont (char_u **pp, linenr_T *lnump, int *amount) {
    char_u *line = *pp;
    linenr_T lnum = *lnump;
    int retval = FALSE;
    int candidate_amount = *amount;
    if (*line != NUL && line[STRLEN (line) - 1] == '\\')
        candidate_amount = get_indent_lnum (lnum);
    for (;;) {
        if (cin_ispreproc (line)) {
            retval = TRUE;
            *lnump = lnum;
            break;
        }
        if (lnum == 1)
            break;
        line = ml_get (--lnum);
        if (*line == NUL || line[STRLEN (line) - 1] != '\\')
            break;
    }
    if (lnum != *lnump)
        *pp = ml_get (*lnump);
    if (retval)
        *amount = candidate_amount;
    return retval;
}

static int corr_ind_maxparen (pos_T *startpos) {
    long  n = (long ) startpos->lnum - (long ) curwin->w_cursor.lnum;
    if (n > 0 && n < curbuf->b_ind_maxparen / 2)
        return curbuf->b_ind_maxparen - (int) n;
    return curbuf->b_ind_maxparen;
}

static int cin_is_if_for_while_before_offset (char_u *line, int *poffset) {
    int offset = *poffset;
    if (offset-- < 2)
        return 0;
    while (offset > 2 && VIM_ISWHITE (line[offset]))
        --offset;
    offset -= 1;
    if (!STRNCMP (line +offset, "if", 2))
        goto probablyFound;
    if (offset >= 1) {
        offset -= 1;
        if (!STRNCMP (line +offset, "for", 3))
            goto probablyFound;
        if (offset >= 2) {
            offset -= 2;
            if (!STRNCMP (line +offset, "while", 5))
                goto probablyFound;
        }
    }
    return 0;
probablyFound :
    if (!offset || !vim_isIDc (line[offset - 1])) {
        *poffset = offset;
        return 1;
    }
    return 0;
}

static int skip_label (linenr_T lnum, char_u **pp) {
    char_u *l;
    int amount;
    pos_T cursor_save;
    cursor_save = curwin->w_cursor;
    curwin->w_cursor.lnum = lnum;
    l = ml_get_curline ();
    if (cin_iscase (l, FALSE) || cin_isscopedecl (l) || cin_islabel ()) {
        amount = get_indent_nolabel (lnum);
        l = after_label (ml_get_curline ());
        if (l == NULL)
            l = ml_get_curline ();
    }
    else {
        amount = get_indent ();
        l = ml_get_curline ();
    }
    *pp = l;
    curwin->w_cursor = cursor_save;
    return amount;
}

static int get_indent_nolabel (linenr_T lnum) {
    char_u *l;
    pos_T fp;
    colnr_T col;
    char_u *p;
    l = ml_get (lnum);
    p = after_label (l);
    if (p == NULL)
        return 0;
    fp.col = (colnr_T) (p - l);
    fp.lnum = lnum;
    getvcol (curwin, & fp, & col, NULL, NULL);
    return (int) col;
}

static char_u *after_label (char_u *l) {
    for (; *l; ++l) {
        if (*l == ':') {
            if (l[1] == ':')
                ++l;
            else if (!cin_iscase (l +1, FALSE))
                break;
        }
        else if (*l == '\'' && l[1] && l[2] == '\'')
            l += 2;
    }
    if (*l == NUL)
        return NULL;
    l = cin_skipcomment (l +1);
    if (*l == NUL)
        return NULL;
    return l;
}

static int cin_ends_in (char_u *s, char_u *find, char_u *ignore) {
    char_u *p = s;
    char_u *r;
    int len = (int) STRLEN (find);
    while (*p != NUL) {
        p = cin_skipcomment (p);
        if (STRNCMP (p, find, len) == 0) {
            r = skipwhite (p +len);
            if (ignore != NULL && STRNCMP (r, ignore, STRLEN (ignore)) == 0)
                r = skipwhite (r +STRLEN (ignore));
            if (cin_nocode (r))
                return TRUE;
        }
        if (*p != NUL)
            ++p;
    }
    return FALSE;
}

static pos_T *find_match_paren_after_brace (int ind_maxparen) {
    pos_T *trypos = find_match_paren (ind_maxparen);
    if (trypos != NULL) {
        pos_T *tryposBrace = find_start_brace ();
        if (tryposBrace != NULL && (trypos->lnum != tryposBrace->lnum ? trypos->lnum < tryposBrace->lnum : trypos->col < tryposBrace->col))
            trypos = NULL;
    }
    return trypos;
}

static int find_last_paren (char_u *l, int start, int end) {
    int i;
    int retval = FALSE;
    int open_count = 0;
    curwin->w_cursor.col = 0;
    for (i = 0; l[i] != NUL; i++) {
        i = (int) (cin_skipcomment (l +i) - l);
        i = (int) (skip_string (l +i) - l);
        if (l[i] == start)
            ++open_count;
        else if (l[i] == end) {
            if (open_count > 0)
                --open_count;
            else {
                curwin->w_cursor.col = i;
                retval = TRUE;
            }
        }
    }
    return retval;
}

static int cin_has_js_key (char_u *text) {
    char_u *s = skipwhite (text);
    int quote = -1;
    if (*s == '\'' || *s == '"') {
        quote = *s;
        ++s;
    }
    if (!vim_isIDc (*s))
        return FALSE;
    while (vim_isIDc (*s))
        ++s;
    if (*s == quote)
        ++s;
    s = cin_skipcomment (s);
    return (*s == ':' && s[1] != ':');
}

static int cin_iswhileofdo (char_u *p, linenr_T lnum) {
    pos_T cursor_save;
    pos_T *trypos;
    int retval = FALSE;
    p = cin_skipcomment (p);
    if (*p == '}')
        p = cin_skipcomment (p +1);
    if (cin_starts_with (p, "while")) {
        cursor_save = curwin->w_cursor;
        curwin->w_cursor.lnum = lnum;
        curwin->w_cursor.col = 0;
        p = ml_get_curline ();
        while (*p && *p != 'w') {
            ++p;
            ++curwin->w_cursor.col;
        }
        if ((trypos = findmatchlimit (NULL, 0, 0, curbuf->b_ind_maxparen)) != NULL && *cin_skipcomment (ml_get_pos (trypos) +1) == ';')
            retval = TRUE;
        curwin->w_cursor = cursor_save;
    }
    return retval;
}

static int find_match (int lookfor, linenr_T ourscope) {
    char_u *look;
    pos_T *theirscope;
    char_u *mightbeif;
    int elselevel;
    int whilelevel;
    if (lookfor == LOOKFOR_IF) {
        elselevel = 1;
        whilelevel = 0;
    }
    else {
        elselevel = 0;
        whilelevel = 1;
    }
    curwin->w_cursor.col = 0;
    while (curwin->w_cursor.lnum > ourscope + 1) {
        curwin->w_cursor.lnum--;
        curwin->w_cursor.col = 0;
        look = cin_skipcomment (ml_get_curline ());
        if (cin_iselse (look) || cin_isif (look) || cin_isdo (look) || cin_iswhileofdo (look, curwin->w_cursor.lnum)) {
            theirscope = find_start_brace ();
            if (theirscope == NULL)
                break;
            if (theirscope->lnum < ourscope)
                break;
            if (theirscope->lnum > ourscope)
                continue;
            look = cin_skipcomment (ml_get_curline ());
            if (cin_iselse (look)) {
                mightbeif = cin_skipcomment (look +4);
                if (!cin_isif (mightbeif))
                    ++elselevel;
                continue;
            }
            if (cin_iswhileofdo (look, curwin->w_cursor.lnum)) {
                ++whilelevel;
                continue;
            }
            look = cin_skipcomment (ml_get_curline ());
            if (cin_isif (look)) {
                elselevel--;
                if (elselevel == 0 && lookfor == LOOKFOR_IF)
                    whilelevel = 0;
            }
            if (cin_isdo (look))
                whilelevel--;
            if (elselevel <= 0 && whilelevel <= 0) {
                return OK;
            }
        }
    }
    return FAIL;
}

static int cin_isif (char_u *p) {
    return (STRNCMP (p, "if", 2) == 0 && !vim_isIDc (p[2]));
}

static int cin_isdo (char_u *p) {
    return (STRNCMP (p, "do", 2) == 0 && !vim_isIDc (p[2]));
}

static int cin_is_cpp_namespace (char_u *s) {
    char_u *p;
    int has_name = FALSE;
    int has_name_start = FALSE;
    s = cin_skipcomment (s);
    if (STRNCMP (s, "namespace", 9) == 0 && (s[9] == NUL || !vim_iswordc (s[9]))) {
        p = cin_skipcomment (skipwhite (s + 9));
        while (*p != NUL) {
            if (VIM_ISWHITE (*p)) {
                has_name = TRUE;
                p = cin_skipcomment (skipwhite (p));
            }
            else if (*p == '{') {
                break;
            }
            else if (vim_iswordc (*p)) {
                has_name_start = TRUE;
                if (has_name)
                    return FALSE;
                ++p;
            }
            else if (p[0] == ':' && p[1] == ':' && vim_iswordc (p[2])) {
                if (!has_name_start || has_name)
                    return FALSE;
                p += 3;
            }
            else {
                return FALSE;
            }
        }
        return TRUE;
    }
    return FALSE;
}

static int cin_is_cpp_extern_c (char_u *s) {
    char_u *p;
    int has_string_literal = FALSE;
    s = cin_skipcomment (s);
    if (STRNCMP (s, "extern", 6) == 0 && (s[6] == NUL || !vim_iswordc (s[6]))) {
        p = cin_skipcomment (skipwhite (s + 6));
        while (*p != NUL) {
            if (VIM_ISWHITE (*p)) {
                p = cin_skipcomment (skipwhite (p));
            }
            else if (*p == '{') {
                break;
            }
            else if (p[0] == '"' && p[1] == 'C' && p[2] == '"') {
                if (has_string_literal)
                    return FALSE;
                has_string_literal = TRUE;
                p += 3;
            }
            else if (p[0] == '"' && p[1] == 'C' && p[2] == '+' && p[3] == '+' && p[4] == '"') {
                if (has_string_literal)
                    return FALSE;
                has_string_literal = TRUE;
                p += 5;
            }
            else {
                return FALSE;
            }
        }
        return has_string_literal ? TRUE : FALSE;
    }
    return FALSE;
}

static int cin_isbreak (char_u *p) {
    return (STRNCMP (p, "break", 5) == 0 && !vim_isIDc (p[5]));
}

static int cin_isfuncdecl (char_u **sp, linenr_T first_lnum, linenr_T min_lnum) {
    char_u *s;
    linenr_T lnum = first_lnum;
    linenr_T save_lnum = curwin->w_cursor.lnum;
    int retval = FALSE;
    pos_T *trypos;
    int just_started = TRUE;
    if (sp == NULL)
        s = ml_get (lnum);
    else
        s = *sp;
    curwin->w_cursor.lnum = lnum;
    if (find_last_paren (s, '(', ')') && (trypos = find_match_paren (curbuf->b_ind_maxparen)) != NULL) {
        lnum = trypos->lnum;
        if (lnum < min_lnum) {
            curwin->w_cursor.lnum = save_lnum;
            return FALSE;
        }
        s = ml_get (lnum);
    }
    curwin->w_cursor.lnum = save_lnum;
    if (cin_ispreproc (s))
        return FALSE;
    while (*s && *s != '(' && *s != ';' && *s != '\'' && *s != '"') {
        if (cin_iscomment (s))
            s = cin_skipcomment (s);
        else if (*s == ':') {
            if (*(s + 1) == ':')
                s += 2;
            else
                return FALSE;
        }
        else
            ++s;
    }
    if (*s != '(')
        return FALSE;
    while (*s && *s != ';' && *s != '\'' && *s != '"') {
        if (*s == ')' && cin_nocode (s +1)) {
            lnum = first_lnum - 1;
            s = ml_get (lnum);
            if (*s == NUL || s[STRLEN (s) - 1] != '\\')
                retval = TRUE;
            goto done;
        }
        if ((*s == ',' && cin_nocode (s +1)) || s[1] == NUL || cin_nocode (s)) {
            int comma = (*s == ',');
            for (;;) {
                if (lnum >= curbuf->b_ml.ml_line_count)
                    break;
                s = ml_get (++lnum);
                if (!cin_ispreproc (s))
                    break;
            }
            if (lnum >= curbuf->b_ml.ml_line_count)
                break;
            s = skipwhite (s);
            if (!just_started && (!comma && *s != ',' && *s != ')'))
                break;
            just_started = FALSE;
        }
        else if (cin_iscomment (s))
            s = cin_skipcomment (s);
        else {
            ++s;
            just_started = FALSE;
        }
    }
done :
    if (lnum != first_lnum && sp != NULL)
        *sp = ml_get (first_lnum);
    return retval;
}

static int cin_isinit (void) {
    char_u *s;
    static char *skip [] = {"static", "public", "protected", "private"};
    s = cin_skipcomment (ml_get_curline ());
    if (cin_starts_with (s, "typedef"))
        s = cin_skipcomment (s +7);
    for (;;) {
        int i, l;
        for (i = 0; i < (int) (sizeof (skip) / sizeof (char *)); ++i) {
            l = (int) strlen (skip[i]);
            if (cin_starts_with (s, skip[i])) {
                s = cin_skipcomment (s +l);
                l = 0;
                break;
            }
        }
        if (l != 0)
            break;
    }
    if (cin_starts_with (s, "enum"))
        return TRUE;
    if (cin_ends_in (s, (char_u *) "=", (char_u *) "{"))
        return TRUE;
    return FALSE;
}

static int cin_is_cpp_baseclass (cpp_baseclass_cache_T *cached) {
    lpos_T *pos = &cached->lpos;
    char_u *s;
    int class_or_struct, lookfor_ctor_init, cpp_base_class;
    linenr_T lnum = curwin->w_cursor.lnum;
    char_u *line = ml_get_curline ();
    if (pos->lnum <= lnum)
        return cached->found;
    pos->col = 0;
    s = skipwhite (line);
    if (*s == '#')
        return FALSE;
    s = cin_skipcomment (s);
    if (*s == NUL)
        return FALSE;
    cpp_base_class = lookfor_ctor_init = class_or_struct = FALSE;
    while (lnum > 1) {
        line = ml_get (lnum -1);
        s = skipwhite (line);
        if (*s == '#' || *s == NUL)
            break;
        while (*s != NUL) {
            s = cin_skipcomment (s);
            if (*s == '{' || *s == '}' || (*s == ';' && cin_nocode (s +1)))
                break;
            if (*s != NUL)
                ++s;
        }
        if (*s != NUL)
            break;
        --lnum;
    }
    pos->lnum = lnum;
    line = ml_get (lnum);
    s = line;
    for (;;) {
        if (*s == NUL) {
            if (lnum == curwin->w_cursor.lnum)
                break;
            line = ml_get (++lnum);
            s = line;
        }
        if (s == line) {
            if (cin_iscase (s, FALSE))
                break;
            s = cin_skipcomment (line);
            if (*s == NUL)
                continue;
        }
        if (s[0] == '"' || (s[0] == 'R' && s[1] == '"'))
            s = skip_string (s) + 1;
        else if (s[0] == ':') {
            if (s[1] == ':') {
                lookfor_ctor_init = FALSE;
                s = cin_skipcomment (s +2);
            }
            else if (lookfor_ctor_init || class_or_struct) {
                cpp_base_class = TRUE;
                lookfor_ctor_init = class_or_struct = FALSE;
                pos->col = 0;
                s = cin_skipcomment (s +1);
            }
            else
                s = cin_skipcomment (s +1);
        }
        else if ((STRNCMP (s, "class", 5) == 0 && !vim_isIDc (s[5])) || (STRNCMP (s, "struct", 6) == 0 && !vim_isIDc (s[6]))) {
            class_or_struct = TRUE;
            lookfor_ctor_init = FALSE;
            if (*s == 'c')
                s = cin_skipcomment (s +5);
            else
                s = cin_skipcomment (s +6);
        }
        else {
            if (s[0] == '{' || s[0] == '}' || s[0] == ';') {
                cpp_base_class = lookfor_ctor_init = class_or_struct = FALSE;
            }
            else if (s[0] == ')') {
                class_or_struct = FALSE;
                lookfor_ctor_init = TRUE;
            }
            else if (s[0] == '?') {
                return FALSE;
            }
            else if (!vim_isIDc (s[0])) {
                class_or_struct = FALSE;
                lookfor_ctor_init = FALSE;
            }
            else if (pos->col == 0) {
                lookfor_ctor_init = FALSE;
                if (cpp_base_class)
                    pos->col = (colnr_T) (s - line);
            }
            if (lnum == curwin->w_cursor.lnum && *s == ',' && cin_nocode (s +1))
                pos->col = 0;
            s = cin_skipcomment (s +1);
        }
    }
    cached->found = cpp_base_class;
    if (cpp_base_class)
        pos->lnum = lnum;
    return cpp_base_class;
}

static int get_baseclass_amount (int col) {
    int amount;
    colnr_T vcol;
    pos_T *trypos;
    if (col == 0) {
        amount = get_indent ();
        if (find_last_paren (ml_get_curline (), '(', ')') && (trypos = find_match_paren (curbuf->b_ind_maxparen)) != NULL)
            amount = get_indent_lnum (trypos->lnum);
        if (!cin_ends_in (ml_get_curline (), (char_u *) ",", NULL))
            amount += curbuf->b_ind_cpp_baseclass;
    }
    else {
        curwin->w_cursor.col = col;
        getvcol (curwin, & curwin -> w_cursor, & vcol, NULL, NULL);
        amount = (int) vcol;
    }
    if (amount < curbuf->b_ind_cpp_baseclass)
        amount = curbuf->b_ind_cpp_baseclass;
    return amount;
}

static int cin_first_id_amount (void) {
    char_u *line, *p, *s;
    int len;
    pos_T fp;
    colnr_T col;
    line = ml_get_curline ();
    p = skipwhite (line);
    len = (int) (skiptowhite (p) - p);
    if (len == 6 && STRNCMP (p, "static", 6) == 0) {
        p = skipwhite (p +6);
        len = (int) (skiptowhite (p) - p);
    }
    if (len == 6 && STRNCMP (p, "struct", 6) == 0)
        p = skipwhite (p +6);
    else if (len == 4 && STRNCMP (p, "enum", 4) == 0)
        p = skipwhite (p +4);
    else if ((len == 8 && STRNCMP (p, "unsigned", 8) == 0) || (len == 6 && STRNCMP (p, "signed", 6) == 0)) {
        s = skipwhite (p +len);
        if ((STRNCMP (s, "int", 3) == 0 && VIM_ISWHITE (s[3])) || (STRNCMP (s, "long", 4) == 0 && VIM_ISWHITE (s[4])) || (STRNCMP (s, "short", 5) == 0 && VIM_ISWHITE (s[5])) || (STRNCMP (s, "char", 4) == 0 && VIM_ISWHITE (s[4])))
            p = s;
    }
    for (len = 0; vim_isIDc (p[len]); ++len)
        ;
    if (len == 0 || !VIM_ISWHITE (p[len]) || cin_nocode (p))
        return 0;
    p = skipwhite (p +len);
    fp.lnum = curwin->w_cursor.lnum;
    fp.col = (colnr_T) (p - line);
    getvcol (curwin, & fp, & col, NULL, NULL);
    return (int) col;
}

static int cin_get_equal_amount (linenr_T lnum) {
    char_u *line;
    char_u *s;
    colnr_T col;
    pos_T fp;
    if (lnum > 1) {
        line = ml_get (lnum -1);
        if (*line != NUL && line[STRLEN (line) - 1] == '\\')
            return -1;
    }
    line = s = ml_get (lnum);
    while (*s != NUL && vim_strchr ((char_u *) "=;{}\"'", *s) == NULL) {
        if (cin_iscomment (s))
            s = cin_skipcomment (s);
        else
            ++s;
    }
    if (*s != '=')
        return 0;
    s = skipwhite (s +1);
    if (cin_nocode (s))
        return 0;
    if (*s == '"')
        ++s;
    fp.lnum = lnum;
    fp.col = (colnr_T) (s - line);
    getvcol (curwin, & fp, & col, NULL, NULL);
    return (int) col;
}

static int cin_iswhileofdo_end (int terminated) {
    char_u *line;
    char_u *p;
    char_u *s;
    pos_T *trypos;
    int i;
    if (terminated != ';')
        return FALSE;
    p = line = ml_get_curline ();
    while (*p != NUL) {
        p = cin_skipcomment (p);
        if (*p == ')') {
            s = skipwhite (p +1);
            if (*s == ';' && cin_nocode (s +1)) {
                i = (int) (p - line);
                curwin->w_cursor.col = i;
                trypos = find_match_paren (curbuf->b_ind_maxparen);
                if (trypos != NULL) {
                    s = cin_skipcomment (ml_get (trypos->lnum));
                    if (*s == '}')
                        s = cin_skipcomment (s +1);
                    if (cin_starts_with (s, "while")) {
                        curwin->w_cursor.lnum = trypos->lnum;
                        return TRUE;
                    }
                }
                line = ml_get_curline ();
                p = line + i;
            }
        }
        if (*p != NUL)
            ++p;
    }
    return FALSE;
}

int vim_fexists (char_u *fname) {
    stat_T st;
    if (mch_stat ((char *) fname, &st))
        return FALSE;
    return TRUE;
}

#  define BREAKCHECK_SKIP 200

int inindent (int extra) {
    char_u *ptr;
    colnr_T col;
    for (col = 0, ptr = ml_get_curline (); VIM_ISWHITE (*ptr); ++col)
        ++ptr;
    if (col >= curwin->w_cursor.col + extra)
        return TRUE;
    else
        return FALSE;
}

int plines_nofill (linenr_T lnum) {
    return plines_win_nofill (curwin, lnum, TRUE);
}

int expand_wildcards (int num_pat, char_u **pat, int *num_files, char_u ***files, int flags) {
    int retval;
    int i, j;
    char_u *p;
    int non_suf_match;
    retval = gen_expand_wildcards (num_pat, pat, num_files, files, flags);
    if ((flags & EW_KEEPALL) || retval == FAIL)
        return retval;
    if (*p_wig) {
        char_u *ffname;
        for (i = 0; i < *num_files; ++i) {
            ffname = FullName_save ((*files)[i], FALSE);
            if (ffname == NULL)
                break;
            if (match_file_list (p_wig, (*files)[i], ffname)) {
                vim_free ((*files) [i]);
                for (j = i; j + 1 < *num_files; ++j)
                    (*files)[j] = (*files)[j + 1];
                --*num_files;
                --i;
            }
            vim_free (ffname);
        }
        if (*num_files == 0) {
            VIM_CLEAR (*files);
            return FAIL;
        }
    }
    if (*num_files > 1) {
        non_suf_match = 0;
        for (i = 0; i < *num_files; ++i) {
            if (!match_suffix ((*files)[i])) {
                p = (*files)[i];
                for (j = i; j > non_suf_match; --j)
                    (*files)[j] = (*files)[j - 1];
                (*files)[non_suf_match++] = p;
            }
        }
    }
    return retval;
}

int match_suffix (char_u *fname) {
    int fnamelen, setsuflen;
    char_u *setsuf;

    #define MAXSUFLEN 30	    /* maximum length of a file suffix */
    char_u suf_buf [MAXSUFLEN];
    fnamelen = (int) STRLEN (fname);
    setsuflen = 0;
    for (setsuf = p_su; *setsuf;) {
        setsuflen = copy_option_part (&setsuf, suf_buf, MAXSUFLEN, ".,");
        if (setsuflen == 0) {
            char_u *tail = gettail (fname);
            if (vim_strchr (tail, '.') == NULL) {
                setsuflen = 1;
                break;
            }
        }
        else {
            if (fnamelen >= setsuflen && fnamencmp (suf_buf, fname +fnamelen - setsuflen, (size_t) setsuflen) == 0)
                break;
            setsuflen = 0;
        }
    }
    return (setsuflen != 0);
}

# define SEEK_SET 0

# define SEEK_END 2

int get_number (int colon, int *mouse_used) {
    int n = 0;
    int c;
    int typed = 0;
    if (mouse_used != NULL)
        *mouse_used = FALSE;
    if (msg_silent != 0)
        return 0;
    ++no_mapping;
    ++allow_keys;
    for (;;) {
        windgoto (msg_row, msg_col);
        c = safe_vgetc ();
        if (VIM_ISDIGIT (c)) {
            n = n * 10 + c - '0';
            msg_putchar (c);
            ++typed;
        }
        else if (c == K_DEL || c == K_KDEL || c == K_BS || c == Ctrl_H) {
            if (typed > 0) {
                MSG_PUTS ("\b \b");
                --typed;
            }
            n /= 10;
        }
        else if (mouse_used != NULL && c == K_LEFTMOUSE) {
            *mouse_used = TRUE;
            n = mouse_row + 1;
            break;
        }
        else if (n == 0 && c == ':' && colon) {
            stuffcharReadbuff (':');
            if (!exmode_active)
                cmdline_row = msg_row;
            skip_redraw = TRUE;
            do_redraw = FALSE;
            break;
        }
        else if (c == CAR || c == NL || c == Ctrl_C || c == ESC)
            break;
    }
    --no_mapping;
    --allow_keys;
    return n;
}

int expand_wildcards_eval (char_u **pat, int *num_file, char_u ***file, int flags) {
    int ret = FAIL;
    char_u *eval_pat = NULL;
    char_u *exp_pat = *pat;
    char_u *ignored_msg;
    int usedlen;
    if (*exp_pat == '%' || *exp_pat == '#' || *exp_pat == '<') {
        ++emsg_off;
        eval_pat = eval_vars (exp_pat, exp_pat, &usedlen, NULL, &ignored_msg, NULL);
        --emsg_off;
        if (eval_pat != NULL)
            exp_pat = concat_str (eval_pat, exp_pat +usedlen);
    }
    if (exp_pat != NULL)
        ret = expand_wildcards (1, &exp_pat, num_file, file, flags);
    if (eval_pat != NULL) {
        vim_free (exp_pat);
        vim_free (eval_pat);
    }
    return ret;
}

char_u *getnextcomp (char_u *fname) {
    while (*fname && !vim_ispathsep (*fname))
        MB_PTR_ADV (fname);
    if (*fname)
        ++fname;
    return fname;
}

char_u *get_cmd_output (char_u *cmd, char_u *infile, int flags, int *ret_len) {
    char_u *tempname;
    char_u *command;
    char_u *buffer = NULL;
    int len;
    int i = 0;
    FILE *fd;
    if (check_restricted () || check_secure ())
        return NULL;
    if ((tempname = vim_tempname ('o', FALSE)) == NULL) {
        EMSG (_ (e_notmp));
        return NULL;
    }
    command = make_filter_cmd (cmd, infile, tempname);
    if (command == NULL)
        goto done;
    ++no_check_timestamps;
    call_shell (command, SHELL_DOOUT | SHELL_EXPAND | flags);
    --no_check_timestamps;
    vim_free (command);
    fd = mch_fopen ((char *) tempname, READBIN);
    if (fd == NULL) {
        EMSG2 (_ (e_notopen), tempname);
        goto done;
    }
    fseek (fd, 0L, SEEK_END);
    len = ftell (fd);
    fseek (fd, 0L, SEEK_SET);
    buffer = alloc (len +1);
    if (buffer != NULL)
        i = (int) fread ((char *) buffer, (size_t) 1, (size_t) len, fd);
    fclose (fd);
    mch_remove (tempname);
    if (buffer == NULL)
        goto done;
    if (i != len) {
        EMSG2 (_ (e_notread), tempname);
        VIM_CLEAR (buffer);
    }
    else if (ret_len == NULL) {
        for (i = 0; i < len; ++i)
            if (buffer[i] == NUL)
                buffer[i] = 1;
        buffer[len] = NUL;
    }
    else
        *ret_len = len;
done :
    vim_free (tempname);
    return buffer;
}

char_u *get_isolated_shell_name (void) {
    char_u *p;
    p = skiptowhite (p_sh);
    if (*p == NUL) {
        p = vim_strsave (gettail (p_sh));
    }
    else {
        char_u *p1, *p2;
        p1 = p_sh;
        for (p2 = p_sh; p2 < p; MB_PTR_ADV (p2))
            if (vim_ispathsep (*p2))
                p1 = p2 + 1;
        p = vim_strnsave (p1, (int) (p - p1));
    }
    return p;
}

char_u *get_env_name (expand_T *xp, int idx) {
    extern char **environ;

    # define ENVNAMELEN 100
    static char_u name [ENVNAMELEN];
    char_u *str;
    int n;
    str = (char_u *) environ[idx];
    if (str == NULL)
        return NULL;
    for (n = 0; n < ENVNAMELEN - 1; ++n) {
        if (str[n] == '=' || str[n] == NUL)
            break;
        name[n] = str[n];
    }
    name[n] = NUL;
    return name;
}

char_u *get_users (expand_T *xp, int idx) {
    init_users ();
    if (idx < ga_users.ga_len)
        return ((char_u **) ga_users.ga_data)[idx];
    return NULL;
}

static void init_users (void) {
    static int lazy_init_done = FALSE;
    if (lazy_init_done)
        return;
    lazy_init_done = TRUE;
    ga_init2 (& ga_users, sizeof (char_u *), 20);
}

int match_user (char_u *name) {
    int i;
    int n = (int) STRLEN (name);
    int result = 0;
    init_users ();
    for (i = 0; i < ga_users.ga_len; i++) {
        if (STRCMP (((char_u **) ga_users.ga_data)[i], name) == 0)
            return 2;
        if (STRNCMP (((char_u **) ga_users.ga_data)[i], name, n) == 0)
            result = 1;
    }
    return result;
}

int vim_fnamecmp (char_u *x, char_u *y) {
    if (p_fic)
        return MB_STRICMP (x, y);
    return STRCMP (x, y);
}

int plines_m_win (win_T *wp, linenr_T first, linenr_T last) {
    int count = 0;
    while (first <= last) {
        int x;
        x = foldedCount (wp, first, NULL);
        if (x > 0) {
            ++count;
            first += x;
        }
        else {
            if (first == wp->w_topline)
                count += plines_win_nofill (wp, first, TRUE) + wp->w_topfill;
            else
                count += plines_win (wp, first, TRUE);
            ++first;
        }
    }
    return (count);
}

int is_mouse_key (int c) {
    return c == K_LEFTMOUSE || c == K_LEFTMOUSE_NM || c == K_LEFTDRAG || c == K_LEFTRELEASE || c == K_LEFTRELEASE_NM || c == K_MOUSEMOVE || c == K_MIDDLEMOUSE || c == K_MIDDLEDRAG || c == K_MIDDLERELEASE || c == K_RIGHTMOUSE || c == K_RIGHTDRAG || c == K_RIGHTRELEASE || c == K_MOUSEDOWN || c == K_MOUSEUP || c == K_MOUSELEFT || c == K_MOUSERIGHT || c == K_X1MOUSE || c == K_X1DRAG || c == K_X1RELEASE || c == K_X2MOUSE || c == K_X2DRAG || c == K_X2RELEASE;
}

int goto_im (void) {
    return (p_im && stuff_empty () && typebuf_typed ());
}

int get_number_indent (linenr_T lnum) {
    colnr_T col;
    pos_T pos;
    regmatch_T regmatch;
    int lead_len = 0;
    if (lnum > curbuf->b_ml.ml_line_count)
        return -1;
    pos.lnum = 0;
    if ((State & INSERT) || has_format_option (FO_Q_COMS))
        lead_len = get_leader_len (ml_get (lnum), NULL, FALSE, TRUE);
    regmatch.regprog = vim_regcomp (curbuf->b_p_flp, RE_MAGIC);
    if (regmatch.regprog != NULL) {
        regmatch.rm_ic = FALSE;
        if (vim_regexec (&regmatch, ml_get (lnum) +lead_len, (colnr_T) 0)) {
            pos.lnum = lnum;
            pos.col = (colnr_T) (*regmatch.endp - ml_get (lnum));
            pos.coladd = 0;
        }
        vim_regfree (regmatch.regprog);
    }
    if (pos.lnum == 0 || *ml_get_pos (&pos) == NUL)
        return -1;
    getvcol (curwin, & pos, & col, NULL, NULL);
    return (int) col;
}

int get_last_leader_offset (char_u *line, char_u **flags) {
    int result = -1;
    int i, j;
    int lower_check_bound = 0;
    char_u *string;
    char_u *com_leader;
    char_u *com_flags;
    char_u *list;
    int found_one;
    char_u part_buf [COM_MAX_LEN];
    i = (int) STRLEN (line);
    while (--i >= lower_check_bound) {
        found_one = FALSE;
        for (list = curbuf->b_p_com; *list;) {
            char_u *flags_save = list;
            (void) copy_option_part (&list, part_buf, COM_MAX_LEN, ",");
            string = vim_strchr (part_buf, ':');
            if (string == NULL) {
                continue;
            }
            *string++ = NUL;
            com_leader = string;
            if (VIM_ISWHITE (string[0])) {
                if (i == 0 || !VIM_ISWHITE (line[i - 1]))
                    continue;
                while (VIM_ISWHITE (string[0]))
                    ++string;
            }
            for (j = 0; string[j] != NUL && string[j] == line[i + j]; ++j)
                ;
            if (string[j] != NUL)
                continue;
            if (vim_strchr (part_buf, COM_BLANK) != NULL && !VIM_ISWHITE (line[i + j]) && line[i + j] != NUL) {
                continue;
            }
            found_one = TRUE;
            if (flags)
                *flags = flags_save;
            com_flags = flags_save;
            break;
        }
        if (found_one) {
            char_u part_buf2 [COM_MAX_LEN];
            int len1, len2, off;
            result = i;
            if (vim_strchr (part_buf, COM_NEST) != NULL)
                continue;
            lower_check_bound = i;
            while (VIM_ISWHITE (*com_leader))
                ++com_leader;
            len1 = (int) STRLEN (com_leader);
            for (list = curbuf->b_p_com; *list;) {
                char_u *flags_save = list;
                (void) copy_option_part (&list, part_buf2, COM_MAX_LEN, ",");
                if (flags_save == com_flags)
                    continue;
                string = vim_strchr (part_buf2, ':');
                ++string;
                while (VIM_ISWHITE (*string))
                    ++string;
                len2 = (int) STRLEN (string);
                if (len2 == 0)
                    continue;
                for (off = (len2 > i ? i : len2); off > 0 && off + len1 > len2;) {
                    --off;
                    if (!STRNCMP (string +off, com_leader, len2 -off)) {
                        if (i - off < lower_check_bound)
                            lower_check_bound = i - off;
                    }
                }
            }
        }
    }
    return result;
}

void del_lines (long  nlines, int undo) {
    long  n;
    linenr_T first = curwin->w_cursor.lnum;
    if (nlines <= 0)
        return;
    if (undo && u_savedel (first, nlines) == FAIL)
        return;
    for (n = 0; n < nlines;) {
        if (curbuf->b_ml.ml_flags & ML_EMPTY)
            break;
        ml_delete (first, TRUE);
        ++n;
        if (first > curbuf->b_ml.ml_line_count)
            break;
    }
    curwin->w_cursor.col = 0;
    check_cursor_lnum ();
    deleted_lines_mark (first, n);
}

void deleted_lines_mark (linenr_T lnum, long  count) {
    mark_adjust (lnum, (linenr_T) (lnum + count - 1), (long) MAXLNUM, - count);
    changed_lines (lnum, 0, lnum + count, - count);
}

void msgmore (long  n) {
    long  pn;
    if (global_busy || !messaging ())
        return;
    if (keep_msg != NULL && !keep_msg_more)
        return;
    if (n > 0)
        pn = n;
    else
        pn = -n;
    if (pn > p_report) {
        if (pn == 1) {
            if (n > 0)
                vim_strncpy (msg_buf, (char_u *) _ ("1 more line"), MSG_BUF_LEN -1);
            else
                vim_strncpy (msg_buf, (char_u *) _ ("1 line less"), MSG_BUF_LEN -1);
        }
        else {
            if (n > 0)
                vim_snprintf ((char *) msg_buf, MSG_BUF_LEN, _ ("%ld more lines"), pn);
            else
                vim_snprintf ((char *) msg_buf, MSG_BUF_LEN, _ ("%ld fewer lines"), pn);
        }
        if (got_int)
            vim_strcat (msg_buf, (char_u *) _ (" (Interrupted)"), MSG_BUF_LEN);
        if (msg (msg_buf)) {
            set_keep_msg (msg_buf, 0);
            keep_msg_more = TRUE;
        }
    }
}

int dir_of_file_exists (char_u *fname) {
    char_u *p;
    int c;
    int retval;
    p = gettail_sep (fname);
    if (p == fname)
        return TRUE;
    c = *p;
    *p = NUL;
    retval = mch_isdir (fname);
    *p = c;
    return retval;
}

void appended_lines_mark (linenr_T lnum, long  count) {
    if (lnum + count < curbuf->b_ml.ml_line_count || curwin->w_p_diff)
        mark_adjust (lnum +1, (linenr_T) MAXLNUM, count, 0L);
    changed_lines (lnum + 1, 0, lnum + 1, count);
}

static char_u *gettail_dir (char_u *fname) {
    char_u *dir_end = fname;
    char_u *next_dir_end = fname;
    int look_for_sep = TRUE;
    char_u *p;
    for (p = fname; *p != NUL;) {
        if (vim_ispathsep (*p)) {
            if (look_for_sep) {
                next_dir_end = p;
                look_for_sep = FALSE;
            }
        }
        else {
            if (!look_for_sep)
                dir_end = next_dir_end;
            look_for_sep = TRUE;
        }
        MB_PTR_ADV (p);
    }
    return dir_end;
}

void shorten_dir (char_u *str) {
    char_u *tail, *s, *d;
    int skip = FALSE;
    tail = gettail (str);
    d = str;
    for (s = str;; ++s) {
        if (s >= tail) {
            *d++ = *s;
            if (*s == NUL)
                break;
        }
        else if (vim_ispathsep (*s)) {
            *d++ = *s;
            skip = FALSE;
        }
        else if (!skip) {
            *d++ = *s;
            if (*s != '~' && *s != '.')
                skip = TRUE;
        }
    }
}

int truncate_line (int fixpos) {
    char_u *newp;
    linenr_T lnum = curwin->w_cursor.lnum;
    colnr_T col = curwin->w_cursor.col;
    if (col == 0)
        newp = vim_strsave ((char_u *) "");
    else
        newp = vim_strnsave (ml_get (lnum), col);
    if (newp == NULL)
        return FAIL;
    ml_replace (lnum, newp, FALSE);
    changed_bytes (lnum, curwin -> w_cursor.col);
    if (fixpos && curwin->w_cursor.col > 0)
        --curwin->w_cursor.col;
    return OK;
}

int plines_win_col (win_T *wp, linenr_T lnum, long  column) {
    long  col;
    char_u *s;
    int lines = 0;
    int width;
    char_u *line;
    lines = diff_check_fill (wp, lnum);
    if (!wp->w_p_wrap)
        return lines + 1;
    if (wp->w_width == 0)
        return lines + 1;
    line = s = ml_get_buf (wp->w_buffer, lnum, FALSE);
    col = 0;
    while (*s != NUL && --column >= 0) {
        col += win_lbr_chartabsize (wp, line, s, (colnr_T) col, NULL);
        MB_PTR_ADV (s);
    }
    if (*s == TAB && (State & NORMAL) && (!wp->w_p_list || lcs_tab1))
        col += win_lbr_chartabsize (wp, line, s, (colnr_T) col, NULL) - 1;
    width = wp->w_width - win_col_off (wp);
    if (width <= 0)
        return 9999;
    lines += 1;
    if (col > width)
        lines += (col - width) / (width + win_col_off2 (wp)) + 1;
    return lines;
}

int get_indent_buf (buf_T *buf, linenr_T lnum) {
    return get_indent_str (ml_get_buf (buf, lnum, FALSE), (int) buf->b_p_ts, FALSE);
}

int prompt_for_number (int *mouse_used) {
    int i;
    int save_cmdline_row;
    int save_State;
    if (mouse_used != NULL)
        MSG_PUTS (_ ("Type number and <Enter> or click with mouse (empty cancels): "));
    else
        MSG_PUTS (_ ("Type number and <Enter> (empty cancels): "));
    save_cmdline_row = cmdline_row;
    cmdline_row = 0;
    save_State = State;
    State = ASKMORE;
    i = get_number (TRUE, mouse_used);
    if (KeyTyped) {
        cmdline_row = msg_row - 1;
        need_wait_return = FALSE;
        msg_didany = FALSE;
        msg_didout = FALSE;
    }
    else
        cmdline_row = save_cmdline_row;
    State = save_State;
    return i;
}

