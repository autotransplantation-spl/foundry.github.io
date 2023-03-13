
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
pumitem_T *balloon_array = NULL;
EXTERN long  p_pvh;
int pum_first = 0;
EXTERN long  p_ph;
EXTERN long  p_pw;
int pum_do_redraw = FALSE;
pumitem_T *pum_array = NULL;
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
EXTERN char_u *p_titlestring;
EXTERN int arrow_used;
EXTERN int mouse_row;
int balloon_mouse_row = 0;
int pum_row;
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
int pum_scrollbar;
int pum_selected;
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
int balloon_arraysize;
int pum_extra_width;
int pum_kind_width;
int pum_base_width;
int pum_width;
int pum_height;
int pum_size;
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
int balloon_mouse_col = 0;
int pum_col;
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

int pum_visible (void) {
    return !pum_do_redraw && pum_array != NULL;
}

void pum_undisplay (void) {
    pum_array = NULL;
    redraw_all_later (SOME_VALID);
    redraw_tabline = TRUE;
    status_redraw_all ();
}

void pum_display (pumitem_T *array, int size, int selected) {
    int def_width;
    int max_width;
    int row;
    int context_lines;
    int col;
    int above_row;
    int below_row;
    int redo_count = 0;
    win_T *pvwin;
    do {
        def_width = p_pw;
        above_row = 0;
        below_row = cmdline_row;
        pum_array = (pumitem_T *) 1;
        validate_cursor_col ();
        pum_array = NULL;
        row = curwin->w_wrow + W_WINROW (curwin);
        FOR_ALL_WINDOWS (pvwin)
            if (pvwin->w_p_pvw)
                break;
        if (pvwin != NULL) {
            if (W_WINROW (pvwin) < W_WINROW (curwin))
                above_row = W_WINROW (pvwin) + pvwin->w_height;
            else if (W_WINROW (pvwin) > W_WINROW (curwin) + curwin->w_height)
                below_row = W_WINROW (pvwin);
        }
        if (size < PUM_DEF_HEIGHT)
            pum_height = size;
        else
            pum_height = PUM_DEF_HEIGHT;
        if (p_ph > 0 && pum_height > p_ph)
            pum_height = p_ph;
        if (row + 2 >= below_row - pum_height && row - above_row > (below_row - above_row) / 2) {
            if (curwin->w_wrow - curwin->w_cline_row >= 2)
                context_lines = 2;
            else
                context_lines = curwin->w_wrow - curwin->w_cline_row;
            if (row >= size + context_lines) {
                pum_row = row - size - context_lines;
                pum_height = size;
            }
            else {
                pum_row = 0;
                pum_height = row - context_lines;
            }
            if (p_ph > 0 && pum_height > p_ph) {
                pum_row += pum_height - p_ph;
                pum_height = p_ph;
            }
        }
        else {
            if (curwin->w_cline_row + curwin->w_cline_height - curwin->w_wrow >= 3)
                context_lines = 3;
            else
                context_lines = curwin->w_cline_row + curwin->w_cline_height - curwin->w_wrow;
            pum_row = row + context_lines;
            if (size > below_row - pum_row)
                pum_height = below_row - pum_row;
            else
                pum_height = size;
            if (p_ph > 0 && pum_height > p_ph)
                pum_height = p_ph;
        }
        if (pum_height < 1 || (pum_height == 1 && size > 1))
            return;
        if (pvwin != NULL && pum_row < above_row && pum_height > above_row) {
            pum_row += above_row;
            pum_height -= above_row;
        }
        pum_array = array;
        pum_size = size;
        pum_compute_size ();
        max_width = pum_base_width;
        if (curwin->w_p_rl)
            col = curwin->w_wincol + curwin->w_width - curwin->w_wcol - 1;
        else
            col = curwin->w_wincol + curwin->w_wcol;
        if (pum_height < size) {
            pum_scrollbar = 1;
            ++max_width;
        }
        else
            pum_scrollbar = 0;
        if (def_width < max_width)
            def_width = max_width;
        if (((col < Columns - p_pw || col < Columns - max_width) && !curwin->w_p_rl) || (curwin->w_p_rl && (col > p_pw || col > max_width))) {
            pum_col = col;
            if (curwin->w_p_rl)
                pum_width = pum_col - pum_scrollbar + 1;
            else
                pum_width = Columns - pum_col - pum_scrollbar;
            if (pum_width > max_width + pum_kind_width + pum_extra_width + 1 && pum_width > p_pw) {
                pum_width = max_width + pum_kind_width + pum_extra_width + 1;
                if (pum_width < p_pw)
                    pum_width = p_pw;
            }
            else if (((col > p_pw || col > max_width) && !curwin->w_p_rl) || (curwin->w_p_rl && (col < Columns - p_pw || col < Columns - max_width))) {
                if (curwin->w_p_rl) {
                    pum_col = col + max_width + pum_scrollbar + 1;
                    if (pum_col >= Columns)
                        pum_col = Columns - 1;
                }
                else {
                    pum_col = col - max_width - pum_scrollbar;
                    if (pum_col < 0)
                        pum_col = 0;
                }
                if (curwin->w_p_rl)
                    pum_width = W_ENDCOL (curwin) - pum_col - pum_scrollbar + 1;
                else
                    pum_width = pum_col - pum_scrollbar;
                if (pum_width < p_pw) {
                    pum_width = p_pw;
                    if (curwin->w_p_rl) {
                        if (pum_width > pum_col)
                            pum_width = pum_col;
                    }
                    else {
                        if (pum_width >= Columns - pum_col)
                            pum_width = Columns - pum_col - 1;
                    }
                }
                else if (pum_width > max_width + pum_kind_width + pum_extra_width + 1 && pum_width > p_pw) {
                    pum_width = max_width + pum_kind_width + pum_extra_width + 1;
                    if (pum_width < p_pw)
                        pum_width = p_pw;
                }
            }
        }
        else if (Columns < def_width) {
            if (curwin->w_p_rl)
                pum_col = Columns - 1;
            else
                pum_col = 0;
            pum_width = Columns - 1;
        }
        else {
            if (max_width > p_pw)
                max_width = p_pw;
            if (curwin->w_p_rl)
                pum_col = max_width - 1;
            else
                pum_col = Columns - max_width;
            pum_width = max_width - pum_scrollbar;
        }
    }
    while (pum_set_selected (selected, redo_count) && ++redo_count <= 2);
}

static void pum_compute_size (void) {
    int i;
    int w;
    pum_base_width = 0;
    pum_kind_width = 0;
    pum_extra_width = 0;
    for (i = 0; i < pum_size; ++i) {
        w = vim_strsize (pum_array[i].pum_text);
        if (pum_base_width < w)
            pum_base_width = w;
        if (pum_array[i].pum_kind != NULL) {
            w = vim_strsize (pum_array[i].pum_kind) + 1;
            if (pum_kind_width < w)
                pum_kind_width = w;
        }
        if (pum_array[i].pum_extra != NULL) {
            w = vim_strsize (pum_array[i].pum_extra) + 1;
            if (pum_extra_width < w)
                pum_extra_width = w;
        }
    }
}

static int pum_set_selected (int n, int repeat) {
    int resized = FALSE;
    int context = pum_height / 2;
    pum_selected = n;
    if (pum_selected >= 0 && pum_selected < pum_size) {
        if (pum_first > pum_selected - 4) {
            if (pum_first > pum_selected - 2) {
                pum_first -= pum_height - 2;
                if (pum_first < 0)
                    pum_first = 0;
                else if (pum_first > pum_selected)
                    pum_first = pum_selected;
            }
            else
                pum_first = pum_selected;
        }
        else if (pum_first < pum_selected - pum_height + 5) {
            if (pum_first < pum_selected - pum_height + 1 + 2) {
                pum_first += pum_height - 2;
                if (pum_first < pum_selected - pum_height + 1)
                    pum_first = pum_selected - pum_height + 1;
            }
            else
                pum_first = pum_selected - pum_height + 1;
        }
        if (context > 3)
            context = 3;
        if (pum_height > 2) {
            if (pum_first > pum_selected - context) {
                pum_first = pum_selected - context;
                if (pum_first < 0)
                    pum_first = 0;
            }
            else if (pum_first < pum_selected + context - pum_height + 1) {
                pum_first = pum_selected + context - pum_height + 1;
            }
        }
        if (pum_array[pum_selected].pum_info != NULL && Rows > 10 && repeat <= 1 && vim_strchr (p_cot, 'p') != NULL) {
            win_T *curwin_save = curwin;
            tabpage_T *curtab_save = curtab;
            int res = OK;
            g_do_tagpreview = 3;
            if (p_pvh > 0 && p_pvh < g_do_tagpreview)
                g_do_tagpreview = p_pvh;
            ++RedrawingDisabled;
            ++no_u_sync;
            resized = prepare_tagpreview (FALSE);
            --no_u_sync;
            --RedrawingDisabled;
            g_do_tagpreview = 0;
            if (curwin->w_p_pvw) {
                if (!resized && curbuf->b_nwindows == 1 && curbuf->b_fname == NULL && curbuf->b_p_bt[0] == 'n' && curbuf->b_p_bt[2] == 'f' && curbuf->b_p_bh[0] == 'w') {
                    while (!BUFEMPTY ())
                        ml_delete ((linenr_T) 1, FALSE);
                }
                else {
                    ++no_u_sync;
                    res = do_ecmd (0, NULL, NULL, NULL, ECMD_ONE, 0, NULL);
                    --no_u_sync;
                    if (res == OK) {
                        set_option_value ((char_u *) "swf", 0L, NULL, OPT_LOCAL);
                        set_option_value ((char_u *) "bt", 0L, (char_u *) "nofile", OPT_LOCAL);
                        set_option_value ((char_u *) "bh", 0L, (char_u *) "wipe", OPT_LOCAL);
                        set_option_value ((char_u *) "diff", 0L, NULL, OPT_LOCAL);
                    }
                }
                if (res == OK) {
                    char_u *p, *e;
                    linenr_T lnum = 0;
                    for (p = pum_array[pum_selected].pum_info; *p != NUL;) {
                        e = vim_strchr (p, '\n');
                        if (e == NULL) {
                            ml_append (lnum ++, p, 0, FALSE);
                            break;
                        }
                        else {
                            *e = NUL;
                            ml_append (lnum ++, p, (int) (e - p + 1), FALSE);
                            *e = '\n';
                            p = e + 1;
                        }
                    }
                    if (repeat == 0) {
                        if (lnum > p_pvh)
                            lnum = p_pvh;
                        if (curwin->w_height < lnum) {
                            win_setheight ((int) lnum);
                            resized = TRUE;
                        }
                    }
                    curbuf->b_changed = 0;
                    curbuf->b_p_ma = FALSE;
                    curwin->w_cursor.lnum = 1;
                    curwin->w_cursor.col = 0;
                    if ((curwin != curwin_save && win_valid (curwin_save)) || (curtab != curtab_save && valid_tabpage (curtab_save))) {
                        if (curtab != curtab_save && valid_tabpage (curtab_save))
                            goto_tabpage_tp (curtab_save, FALSE, FALSE);
                        if (ins_compl_active () && !resized)
                            curwin->w_redr_status = FALSE;
                        validate_cursor ();
                        redraw_later (SOME_VALID);
                        if (resized) {
                            ++no_u_sync;
                            win_enter (curwin_save, TRUE);
                            --no_u_sync;
                            update_topline ();
                        }
                        pum_do_redraw = TRUE;
                        update_screen (0);
                        pum_do_redraw = FALSE;
                        if (!resized && win_valid (curwin_save)) {
                            ++no_u_sync;
                            win_enter (curwin_save, TRUE);
                            --no_u_sync;
                        }
                        pum_do_redraw = TRUE;
                        update_screen (0);
                        pum_do_redraw = FALSE;
                    }
                }
            }
        }
    }
    if (!resized)
        pum_redraw ();
    return resized;
}

void pum_redraw (void) {
    int row = pum_row;
    int col;
    int attr_norm = highlight_attr[HLF_PNI];
    int attr_select = highlight_attr[HLF_PSI];
    int attr_scroll = highlight_attr[HLF_PSB];
    int attr_thumb = highlight_attr[HLF_PST];
    int attr;
    int i;
    int idx;
    char_u *s;
    char_u *p = NULL;
    int totwidth, width, w;
    int thumb_pos = 0;
    int thumb_heigth = 1;
    int round;
    int n;
    if (pum_first > pum_size - pum_height)
        pum_first = pum_size - pum_height;
    if (pum_scrollbar) {
        thumb_heigth = pum_height * pum_height / pum_size;
        if (thumb_heigth == 0)
            thumb_heigth = 1;
        thumb_pos = (pum_first * (pum_height - thumb_heigth) + (pum_size - pum_height) / 2) / (pum_size - pum_height);
    }
    for (i = 0; i < pum_height; ++i) {
        idx = i + pum_first;
        attr = (idx == pum_selected) ? attr_select : attr_norm;
        if (curwin->w_p_rl) {
            if (pum_col < curwin->w_wincol + curwin->w_width - 1)
                screen_putchar (' ', row, pum_col +1, attr);
        }
        else if (pum_col > 0)
            screen_putchar (' ', row, pum_col -1, attr);
        col = pum_col;
        totwidth = 0;
        for (round = 1; round <= 3; ++round) {
            width = 0;
            s = NULL;
            switch (round) {
            case 1 :
                p = pum_array[idx].pum_text;
                break;
            case 2 :
                p = pum_array[idx].pum_kind;
                break;
            case 3 :
                p = pum_array[idx].pum_extra;
                break;
            }
            if (p != NULL)
                for (;; MB_PTR_ADV (p)) {
                    if (s == NULL)
                        s = p;
                    w = ptr2cells (p);
                    if (*p == NUL || *p == TAB || totwidth + w > pum_width) {
                        char_u *st;
                        int saved = *p;
                        *p = NUL;
                        st = transstr (s);
                        *p = saved;
                        if (curwin->w_p_rl) {
                            if (st != NULL) {
                                char_u *rt = reverse_text (st);
                                if (rt != NULL) {
                                    char_u *rt_start = rt;
                                    int size;
                                    size = vim_strsize (rt);
                                    if (size > pum_width) {
                                        do {
                                            size -= has_mbyte ? (*mb_ptr2cells) (rt) : 1;
                                            MB_PTR_ADV (rt);
                                        }
                                        while (size > pum_width);
                                        if (size < pum_width) {
                                            *(--rt) = '<';
                                            size++;
                                        }
                                    }
                                    screen_puts_len (rt, (int) STRLEN (rt), row, col - size + 1, attr);
                                    vim_free (rt_start);
                                }
                                vim_free (st);
                            }
                            col -= width;
                        }
                        else {
                            if (st != NULL) {
                                screen_puts_len (st, (int) STRLEN (st), row, col, attr);
                                vim_free (st);
                            }
                            col += width;
                        }
                        if (*p != TAB)
                            break;
                        if (curwin->w_p_rl) {
                            screen_puts_len ((char_u *) "  ", 2, row, col - 1, attr);
                            col -= 2;
                        }
                        else {
                            screen_puts_len ((char_u *) "  ", 2, row, col, attr);
                            col += 2;
                        }
                        totwidth += 2;
                        s = NULL;
                        width = 0;
                    }
                    else
                        width += w;
                }
            if (round > 1)
                n = pum_kind_width + 1;
            else
                n = 1;
            if (round == 3 || (round == 2 && pum_array[idx].pum_extra == NULL) || (round == 1 && pum_array[idx].pum_kind == NULL && pum_array[idx].pum_extra == NULL) || pum_base_width + n >= pum_width)
                break;
            if (curwin->w_p_rl) {
                screen_fill (row, row + 1, pum_col - pum_base_width - n + 1, col + 1, ' ', ' ', attr);
                col = pum_col - pum_base_width - n + 1;
            }
            else {
                screen_fill (row, row + 1, col, pum_col + pum_base_width + n, ' ', ' ', attr);
                col = pum_col + pum_base_width + n;
            }
            totwidth = pum_base_width + n;
        }
        if (curwin->w_p_rl)
            screen_fill (row, row +1, pum_col -pum_width + 1, col +1, ' ', ' ', attr);
        else
            screen_fill (row, row +1, col, pum_col +pum_width, ' ', ' ', attr);
        if (pum_scrollbar > 0) {
            if (curwin->w_p_rl)
                screen_putchar (' ', row, pum_col -pum_width, i >= thumb_pos && i < thumb_pos + thumb_heigth ? attr_thumb : attr_scroll);
            else
                screen_putchar (' ', row, pum_col +pum_width, i >= thumb_pos && i < thumb_pos + thumb_heigth ? attr_thumb : attr_scroll);
        }
        ++row;
    }
}

int pum_get_height (void) {
    return pum_height;
}

void ui_post_balloon (char_u *mesg, list_T *list) {
    ui_remove_balloon ();
    if (mesg == NULL && list == NULL)
        return;
    if (list != NULL) {
        listitem_T *li;
        int idx;
        balloon_arraysize = list->lv_len;
        balloon_array = (pumitem_T *) alloc_clear ((unsigned ) sizeof (pumitem_T) * list->lv_len);
        if (balloon_array == NULL)
            return;
        for (idx = 0, li = list->lv_first; li != NULL; li = li->li_next, ++idx) {
            char_u *text = get_tv_string_chk (&li->li_tv);
            balloon_array[idx].pum_text = vim_strsave (text == NULL ? (char_u *) "" : text);
        }
    }
    else
        balloon_arraysize = split_message (mesg, &balloon_array);
    if (balloon_arraysize > 0) {
        pum_array = balloon_array;
        pum_size = balloon_arraysize;
        pum_compute_size ();
        pum_scrollbar = 0;
        pum_height = balloon_arraysize;
        if (Rows - mouse_row > pum_size) {
            pum_row = mouse_row + 1;
            if (pum_height > Rows - pum_row)
                pum_height = Rows - pum_row;
        }
        else {
            pum_row = mouse_row - pum_size;
            if (pum_row < 0) {
                pum_height += pum_row;
                pum_row = 0;
            }
        }
        if (Columns - mouse_col >= pum_base_width || Columns - mouse_col > BALLOON_MIN_WIDTH)
            pum_col = mouse_col;
        else
            pum_col = Columns - (pum_base_width > BALLOON_MIN_WIDTH ? BALLOON_MIN_WIDTH : pum_base_width);
        pum_width = Columns - pum_col;
        if (pum_width > pum_base_width + 1)
            pum_width = pum_base_width + 1;
        pum_selected = -1;
        pum_first = 0;
        pum_redraw ();
    }
}

void ui_remove_balloon (void) {
    if (balloon_array != NULL) {
        pum_undisplay ();
        while (balloon_arraysize > 0)
            vim_free (balloon_array[--balloon_arraysize].pum_text);
        VIM_CLEAR (balloon_array);
    }
}

int split_message (char_u *mesg, pumitem_T **array) {
    garray_T ga;
    char_u *p;
    balpart_T *item;
    int quoted = FALSE;
    int height;
    int line;
    int item_idx;
    int indent = 0;
    int max_cells = 0;
    int max_height = Rows / 2 - 2;
    int long_item_count = 0;
    int split_long_items = FALSE;
    ga_init2 (& ga, sizeof (balpart_T), 20);
    p = mesg;
    while (*p != NUL) {
        if (ga_grow (&ga, 1) == FAIL)
            goto failed;
        item = ((balpart_T *) ga.ga_data) + ga.ga_len;
        item->start = p;
        item->indent = indent;
        item->cells = indent * 2;
        ++ga.ga_len;
        while (*p != NUL) {
            if (*p == '"')
                quoted = !quoted;
            else if (*p == '\\' && p[1] != NUL)
                ++p;
            else if (!quoted) {
                if ((*p == ',' && p[1] == ' ') || *p == '{' || *p == '}') {
                    if (*p == '{')
                        ++indent;
                    else if (*p == '}' && indent > 0)
                        --indent;
                    ++item->cells;
                    p = skipwhite (p +1);
                    break;
                }
            }
            item->cells += ptr2cells (p);
            p += MB_PTR2LEN (p);
        }
        item->bytelen = p - item->start;
        if (item->cells > max_cells)
            max_cells = item->cells;
        long_item_count += (item->cells - 1) / BALLOON_MIN_WIDTH;
    }
    height = 2 + ga.ga_len;
    if (long_item_count > 0 && height + long_item_count <= max_height) {
        split_long_items = TRUE;
        height += long_item_count;
    }
    if (height > max_height)
        height = max_height;
    *array = (pumitem_T *) alloc_clear ((unsigned ) sizeof (pumitem_T) * height);
    if (*array == NULL)
        goto failed;
    (*array)->pum_text = vim_strsave ((char_u *) "");
    (*array + height - 1)->pum_text = vim_strsave ((char_u *) "");
    for (line = 1, item_idx = 0; line < height - 1; ++item_idx) {
        int skip;
        int thislen;
        int copylen;
        int ind;
        int cells;
        item = ((balpart_T *) ga.ga_data) + item_idx;
        for (skip = 0; skip < item->bytelen; skip += thislen) {
            if (split_long_items && item->cells >= BALLOON_MIN_WIDTH) {
                cells = item->indent * 2;
                for (p = item->start + skip; p < item->start + item->bytelen; p += MB_PTR2LEN (p))
                    if ((cells += ptr2cells (p)) > BALLOON_MIN_WIDTH)
                        break;
                thislen = p - (item->start + skip);
            }
            else
                thislen = item->bytelen;
            p = alloc (thislen +item->indent * 2 + 1);
            for (ind = 0; ind < item->indent * 2; ++ind)
                p[ind] = ' ';
            for (copylen = thislen; copylen > 0; --copylen)
                if (item->start[skip + copylen - 1] != ' ')
                    break;
            vim_strncpy (p + ind, item -> start + skip, copylen);
            (*array)[line].pum_text = p;
            item->indent = 0;
            ++line;
        }
    }
    ga_clear (& ga);
    return height;
failed :
    ga_clear (&ga);
    return 0;
}

void pum_clear (void) {
    pum_first = 0;
}

void ui_may_remove_balloon (void) {
    if (mouse_row != balloon_mouse_row || mouse_col != balloon_mouse_col)
        ui_remove_balloon ();
}

