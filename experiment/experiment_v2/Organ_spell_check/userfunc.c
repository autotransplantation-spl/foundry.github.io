
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
EXTERN long  p_verbose;
EXTERN long  p_mfd;
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
char *e_nofunc = N_ ("E130: Unknown function: %s");
char *e_funcref = N_ ("E718: Funcref required");
char *e_funcdict = N_ ("E717: Dictionary entry already exists");
char *e_funcexts = N_ ("E122: Function %s already exists, add ! to replace it");
funccall_T *previous_funccal = NULL;
garray_T funcargs = GA_EMPTY;
hashtab_T func_hashtab;
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
funccall_T *current_funccal = NULL;
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

void func_unref (char_u *name) {
    ufunc_T *fp = NULL;
    if (name == NULL || !func_name_refcount (name))
        return;
    fp = find_func (name);
    if (fp == NULL && isdigit (*name)) {
        internal_error ("func_unref()");
    }
    if (fp != NULL && --fp->uf_refcount <= 0) {
        if (fp->uf_calls == 0)
            func_clear_free (fp, FALSE);
    }
}

static int func_name_refcount (char_u *name) {
    return isdigit (*name) || *name == '<';
}

ufunc_T *find_func (char_u *name) {
    hashitem_T *hi;
    hi = hash_find (&func_hashtab, name);
    if (!HASHITEM_EMPTY (hi))
        return HI2UF (hi);
    return NULL;
}

static void func_clear_free (ufunc_T *fp, int force) {
    func_clear (fp, force);
    func_free (fp);
}

static void func_clear (ufunc_T *fp, int force) {
    if (fp->uf_cleared)
        return;
    fp->uf_cleared = TRUE;
    ga_clear_strings (& (fp -> uf_args));
    ga_clear_strings (& (fp -> uf_lines));
    vim_free (fp -> uf_tml_count);
    vim_free (fp -> uf_tml_total);
    vim_free (fp -> uf_tml_self);
    funccal_unref (fp -> uf_scoped, fp, force);
}

static void funccal_unref (funccall_T *fc, ufunc_T *fp, int force) {
    funccall_T **pfc;
    int i;
    if (fc == NULL)
        return;
    if (--fc->fc_refcount <= 0 && (force || (fc->l_varlist.lv_refcount == DO_NOT_FREE_CNT && fc->l_vars.dv_refcount == DO_NOT_FREE_CNT && fc->l_avars.dv_refcount == DO_NOT_FREE_CNT)))
        for (pfc = &previous_funccal; *pfc != NULL; pfc = &(*pfc)->caller) {
            if (fc == *pfc) {
                *pfc = fc->caller;
                free_funccal (fc, TRUE);
                return;
            }
        }
    for (i = 0; i < fc->fc_funcs.ga_len; ++i)
        if (((ufunc_T **) (fc->fc_funcs.ga_data))[i] == fp)
            ((ufunc_T **) (fc->fc_funcs.ga_data))[i] = NULL;
}

static void free_funccal (funccall_T *fc, int free_val) {
    listitem_T *li;
    int i;
    for (i = 0; i < fc->fc_funcs.ga_len; ++i) {
        ufunc_T *fp = ((ufunc_T **) (fc->fc_funcs.ga_data))[i];
        if (fp != NULL && fp->uf_scoped == fc)
            fp->uf_scoped = NULL;
    }
    ga_clear (& fc -> fc_funcs);
    vars_clear_ext (& fc -> l_avars.dv_hashtab, free_val);
    vars_clear (& fc -> l_vars.dv_hashtab);
    if (free_val)
        for (li = fc->l_varlist.lv_first; li != NULL; li = li->li_next)
            clear_tv (&li->li_tv);
    func_ptr_unref (fc -> func);
    vim_free (fc);
}

void func_ptr_unref (ufunc_T *fp) {
    if (fp != NULL && --fp->uf_refcount <= 0) {
        if (fp->uf_calls == 0)
            func_clear_free (fp, FALSE);
    }
}

static void func_free (ufunc_T *fp) {
    if ((fp->uf_flags & (FC_DELETED | FC_REMOVED)) == 0)
        func_remove (fp);
    vim_free (fp);
}

static int func_remove (ufunc_T *fp) {
    hashitem_T *hi = hash_find (&func_hashtab, UF2HIKEY (fp));
    if (!HASHITEM_EMPTY (hi)) {
        hash_remove (& func_hashtab, hi);
        return TRUE;
    }
    return FALSE;
}

int call_func (char_u *funcname, int len, typval_T *rettv, int argcount_in, typval_T *argvars_in, int (*argv_func) (int, typval_T *, int), linenr_T firstline, linenr_T lastline, int *doesrange, int evaluate, partial_T *partial, dict_T *selfdict_in) {
    int ret = FAIL;
    int error = ERROR_NONE;
    int i;
    ufunc_T *fp;
    char_u fname_buf [FLEN_FIXED + 1];
    char_u *tofree = NULL;
    char_u *fname;
    char_u *name;
    int argcount = argcount_in;
    typval_T *argvars = argvars_in;
    dict_T *selfdict = selfdict_in;
    typval_T argv [MAX_FUNC_ARGS + 1];
    int argv_clear = 0;
    name = vim_strnsave (funcname, len);
    if (name == NULL)
        return ret;
    fname = fname_trans_sid (name, fname_buf, &tofree, &error);
    *doesrange = FALSE;
    if (partial != NULL) {
        if (partial->pt_dict != NULL && (selfdict_in == NULL || !partial->pt_auto))
            selfdict = partial->pt_dict;
        if (error == ERROR_NONE && partial->pt_argc > 0) {
            for (argv_clear = 0; argv_clear < partial->pt_argc; ++argv_clear)
                copy_tv (&partial->pt_argv[argv_clear], &argv[argv_clear]);
            for (i = 0; i < argcount_in; ++i)
                argv[i + argv_clear] = argvars_in[i];
            argvars = argv;
            argcount = partial->pt_argc + argcount_in;
        }
    }
    if (evaluate && error == ERROR_NONE) {
        char_u *rfname = fname;
        if (fname[0] == 'g' && fname[1] == ':')
            rfname = fname + 2;
        rettv->v_type = VAR_NUMBER;
        rettv->vval.v_number = 0;
        error = ERROR_UNKNOWN;
        if (!builtin_function (rfname, -1)) {
            if (partial != NULL && partial->pt_func != NULL)
                fp = partial->pt_func;
            else
                fp = find_func (rfname);
            if (fp == NULL && apply_autocmds (EVENT_FUNCUNDEFINED, rfname, rfname, TRUE, NULL) && !aborting ()) {
                fp = find_func (rfname);
            }
            if (fp == NULL && script_autoload (rfname, TRUE) && !aborting ()) {
                fp = find_func (rfname);
            }
            if (fp != NULL && (fp->uf_flags & FC_DELETED))
                error = ERROR_DELETED;
            else if (fp != NULL) {
                if (argv_func != NULL)
                    argcount = argv_func (argcount, argvars, fp->uf_args.ga_len);
                if (fp->uf_flags & FC_RANGE)
                    *doesrange = TRUE;
                if (argcount < fp->uf_args.ga_len)
                    error = ERROR_TOOFEW;
                else if (!fp->uf_varargs && argcount > fp->uf_args.ga_len)
                    error = ERROR_TOOMANY;
                else if ((fp->uf_flags & FC_DICT) && selfdict == NULL)
                    error = ERROR_DICT;
                else {
                    int did_save_redo = FALSE;
                    save_redo_T save_redo;
                    save_search_patterns ();
                    if (!ins_compl_active ()) {
                        saveRedobuff (& save_redo);
                        did_save_redo = TRUE;
                    }
                    ++fp->uf_calls;
                    call_user_func (fp, argcount, argvars, rettv, firstline, lastline, (fp -> uf_flags & FC_DICT) ? selfdict : NULL);
                    if (--fp->uf_calls <= 0 && fp->uf_refcount <= 0)
                        func_clear_free (fp, FALSE);
                    if (did_save_redo)
                        restoreRedobuff (&save_redo);
                    restore_search_patterns ();
                    error = ERROR_NONE;
                }
            }
        }
        else {
            error = call_internal_func (fname, argcount, argvars, rettv);
        }
        update_force_abort ();
    }
    if (error == ERROR_NONE)
        ret = OK;
    if (!aborting ()) {
        switch (error) {
        case ERROR_UNKNOWN :
            emsg_funcname (N_ ("E117: Unknown function: %s"), name);
            break;
        case ERROR_DELETED :
            emsg_funcname (N_ ("E933: Function was deleted: %s"), name);
            break;
        case ERROR_TOOMANY :
            emsg_funcname ((char *) e_toomanyarg, name);
            break;
        case ERROR_TOOFEW :
            emsg_funcname (N_ ("E119: Not enough arguments for function: %s"), name);
            break;
        case ERROR_SCRIPT :
            emsg_funcname (N_ ("E120: Using <SID> not in a script context: %s"), name);
            break;
        case ERROR_DICT :
            emsg_funcname (N_ ("E725: Calling dict function without Dictionary: %s"), name);
            break;
        }
    }
    while (argv_clear > 0)
        clear_tv (&argv[--argv_clear]);
    vim_free (tofree);
    vim_free (name);
    return ret;
}

static char_u *fname_trans_sid (char_u *name, char_u *fname_buf, char_u **tofree, int *error) {
    int llen;
    char_u *fname;
    int i;
    llen = eval_fname_script (name);
    if (llen > 0) {
        fname_buf[0] = K_SPECIAL;
        fname_buf[1] = KS_EXTRA;
        fname_buf[2] = (int) KE_SNR;
        i = 3;
        if (eval_fname_sid (name)) {
            if (current_SID <= 0)
                *error = ERROR_SCRIPT;
            else {
                sprintf ((char *) fname_buf + 3, "%ld_", (long) current_SID);
                i = (int) STRLEN (fname_buf);
            }
        }
        if (i + STRLEN (name +llen) < FLEN_FIXED) {
            STRCPY (fname_buf + i, name + llen);
            fname = fname_buf;
        }
        else {
            fname = alloc ((unsigned ) (i + STRLEN (name +llen) + 1));
            if (fname == NULL)
                *error = ERROR_OTHER;
            else {
                *tofree = fname;
                mch_memmove (fname, fname_buf, (size_t) i);
                STRCPY (fname + i, name + llen);
            }
        }
    }
    else
        fname = name;
    return fname;
}

int eval_fname_script (char_u *p) {
    if (p[0] == '<' && (MB_STRNICMP (p +1, "SID>", 4) == 0 || MB_STRNICMP (p +1, "SNR>", 4) == 0))
        return 5;
    if (p[0] == 's' && p[1] == ':')
        return 2;
    return 0;
}

static int eval_fname_sid (char_u *p) {
    return (*p == 's' || TOUPPER_ASC (p[2]) == 'I');
}

void func_ref (char_u *name) {
    ufunc_T *fp;
    if (name == NULL || !func_name_refcount (name))
        return;
    fp = find_func (name);
    if (fp != NULL)
        ++fp->uf_refcount;
    else if (isdigit (*name))
        internal_error ("func_ref()");
}

static int builtin_function (char_u *name, int len) {
    char_u *p;
    if (!ASCII_ISLOWER (name[0]))
        return FALSE;
    p = vim_strchr (name, AUTOLOAD_CHAR);
    return p == NULL || (len > 0 && p > name + len);
}

void prof_child_enter (proftime_T *tm) {
    funccall_T *fc = current_funccal;
    if (fc != NULL && fc->func->uf_profiling)
        profile_start (&fc->prof_child);
    script_prof_save (tm);
}

void *save_funccal (void) {
    funccall_T *fc = current_funccal;
    current_funccal = NULL;
    return (void *) fc;
}

void restore_funccal (void *vfc) {
    funccall_T *fc = (funccall_T *) vfc;
    current_funccal = fc;
}

hashtab_T *get_funccal_local_ht () {
    if (current_funccal == NULL)
        return NULL;
    return &get_funccal ()->l_vars.dv_hashtab;
}

static funccall_T *get_funccal (void) {
    int i;
    funccall_T *funccal;
    funccall_T *temp_funccal;
    funccal = current_funccal;
    if (debug_backtrace_level > 0) {
        for (i = 0; i < debug_backtrace_level; i++) {
            temp_funccal = funccal->caller;
            if (temp_funccal)
                funccal = temp_funccal;
            else
                debug_backtrace_level = i;
        }
    }
    return funccal;
}

hashtab_T *get_funccal_args_ht () {
    if (current_funccal == NULL)
        return NULL;
    return &get_funccal ()->l_avars.dv_hashtab;
}

dictitem_T *get_funccal_local_var () {
    if (current_funccal == NULL)
        return NULL;
    return &get_funccal ()->l_vars_var;
}

dictitem_T *get_funccal_args_var () {
    if (current_funccal == NULL)
        return NULL;
    return &get_funccal ()->l_avars_var;
}

int set_ref_in_previous_funccal (int copyID) {
    int abort = FALSE;
    funccall_T *fc;
    for (fc = previous_funccal; fc != NULL; fc = fc->caller) {
        fc->fc_copyID = copyID + 1;
        abort = abort || set_ref_in_ht (&fc->l_vars.dv_hashtab, copyID +1, NULL);
        abort = abort || set_ref_in_ht (&fc->l_avars.dv_hashtab, copyID +1, NULL);
    }
    return abort;
}

int set_ref_in_func (char_u *name, ufunc_T *fp_in, int copyID) {
    ufunc_T *fp = fp_in;
    funccall_T *fc;
    int error = ERROR_NONE;
    char_u fname_buf [FLEN_FIXED + 1];
    char_u *tofree = NULL;
    char_u *fname;
    int abort = FALSE;
    if (name == NULL && fp_in == NULL)
        return FALSE;
    if (fp_in == NULL) {
        fname = fname_trans_sid (name, fname_buf, &tofree, &error);
        fp = find_func (fname);
    }
    if (fp != NULL) {
        for (fc = fp->uf_scoped; fc != NULL; fc = fc->func->uf_scoped)
            abort = abort || set_ref_in_funccal (fc, copyID);
    }
    vim_free (tofree);
    return abort;
}

static int set_ref_in_funccal (funccall_T *fc, int copyID) {
    int abort = FALSE;
    if (fc->fc_copyID != copyID) {
        fc->fc_copyID = copyID;
        abort = abort || set_ref_in_ht (&fc->l_vars.dv_hashtab, copyID, NULL);
        abort = abort || set_ref_in_ht (&fc->l_avars.dv_hashtab, copyID, NULL);
        abort = abort || set_ref_in_func (NULL, fc->func, copyID);
    }
    return abort;
}

int set_ref_in_call_stack (int copyID) {
    int abort = FALSE;
    funccall_T *fc;
    for (fc = current_funccal; fc != NULL; fc = fc->caller)
        abort = abort || set_ref_in_funccal (fc, copyID);
    return abort;
}

int set_ref_in_functions (int copyID) {
    int todo;
    hashitem_T *hi = NULL;
    int abort = FALSE;
    ufunc_T *fp;
    todo = (int) func_hashtab.ht_used;
    for (hi = func_hashtab.ht_array; todo > 0 && !got_int; ++hi) {
        if (!HASHITEM_EMPTY (hi)) {
            --todo;
            fp = HI2UF (hi);
            if (!func_name_refcount (fp->uf_name))
                abort = abort || set_ref_in_func (NULL, fp, copyID);
        }
    }
    return abort;
}

int set_ref_in_func_args (int copyID) {
    int i;
    int abort = FALSE;
    for (i = 0; i < funcargs.ga_len; ++i)
        abort = abort || set_ref_in_item (((typval_T **) funcargs.ga_data)[i], copyID, NULL, NULL);
    return abort;
}

int free_unref_funccal (int copyID, int testing) {
    int did_free = FALSE;
    int did_free_funccal = FALSE;
    funccall_T *fc, **pfc;
    for (pfc = &previous_funccal; *pfc != NULL;) {
        if (can_free_funccal (*pfc, copyID)) {
            fc = *pfc;
            *pfc = fc->caller;
            free_funccal (fc, TRUE);
            did_free = TRUE;
            did_free_funccal = TRUE;
        }
        else
            pfc = &(*pfc)->caller;
    }
    if (did_free_funccal)
        (void) garbage_collect (testing);
    return did_free;
}

static int can_free_funccal (funccall_T *fc, int copyID) {
    return (fc->l_varlist.lv_copyID != copyID && fc->l_vars.dv_copyID != copyID && fc->l_avars.dv_copyID != copyID && fc->fc_copyID != copyID);
}

void *clear_current_funccal () {
    funccall_T *f = current_funccal;
    current_funccal = NULL;
    return f;
}

void restore_current_funccal (void *f) {
    current_funccal = f;
}

void func_dump_profile (FILE *fd) {
    hashitem_T *hi;
    int todo;
    ufunc_T *fp;
    int i;
    ufunc_T **sorttab;
    int st_len = 0;
    todo = (int) func_hashtab.ht_used;
    if (todo == 0)
        return;
    sorttab = (ufunc_T **) alloc ((unsigned ) (sizeof (ufunc_T *) * todo));
    for (hi = func_hashtab.ht_array; todo > 0; ++hi) {
        if (!HASHITEM_EMPTY (hi)) {
            --todo;
            fp = HI2UF (hi);
            if (fp->uf_profiling) {
                if (sorttab != NULL)
                    sorttab[st_len++] = fp;
                if (fp->uf_name[0] == K_SPECIAL)
                    fprintf (fd, "FUNCTION  <SNR>%s()\n", fp->uf_name + 3);
                else
                    fprintf (fd, "FUNCTION  %s()\n", fp->uf_name);
                if (fp->uf_tm_count == 1)
                    fprintf (fd, "Called 1 time\n");
                else
                    fprintf (fd, "Called %d times\n", fp->uf_tm_count);
                fprintf (fd, "Total time: %s\n", profile_msg (& fp -> uf_tm_total));
                fprintf (fd, " Self time: %s\n", profile_msg (& fp -> uf_tm_self));
                fprintf (fd, "\n");
                fprintf (fd, "count  total (s)   self (s)\n");
                for (i = 0; i < fp->uf_lines.ga_len; ++i) {
                    if (FUNCLINE (fp, i) == NULL)
                        continue;
                    prof_func_line (fd, fp -> uf_tml_count [i], & fp -> uf_tml_total [i], & fp -> uf_tml_self [i], TRUE);
                    fprintf (fd, "%s\n", FUNCLINE (fp, i));
                }
                fprintf (fd, "\n");
            }
        }
    }
    if (sorttab != NULL && st_len > 0) {
        qsort ((void *) sorttab, (size_t) st_len, sizeof (ufunc_T *), prof_total_cmp);
        prof_sort_list (fd, sorttab, st_len, "TOTAL", FALSE);
        qsort ((void *) sorttab, (size_t) st_len, sizeof (ufunc_T *), prof_self_cmp);
        prof_sort_list (fd, sorttab, st_len, "SELF", TRUE);
    }
    vim_free (sorttab);
}

static void prof_func_line (FILE *fd, int count, proftime_T *total, proftime_T *self, int prefer_self) {
    if (count > 0) {
        fprintf (fd, "%5d ", count);
        if (prefer_self && profile_equal (total, self))
            fprintf (fd, "           ");
        else
            fprintf (fd, "%s ", profile_msg (total));
        if (!prefer_self && profile_equal (total, self))
            fprintf (fd, "           ");
        else
            fprintf (fd, "%s ", profile_msg (self));
    }
    else
        fprintf (fd, "                            ");
}

static int prof_total_cmp (const void *s1, const void *s2) {
    ufunc_T *p1, *p2;
    p1 = *(ufunc_T**) s1;
    p2 = *(ufunc_T**) s2;
    return profile_cmp (&p1->uf_tm_total, &p2->uf_tm_total);
}

static void prof_sort_list (FILE *fd, ufunc_T **sorttab, int st_len, char *title, int prefer_self) {
    int i;
    ufunc_T *fp;
    fprintf (fd, "FUNCTIONS SORTED ON %s TIME\n", title);
    fprintf (fd, "count  total (s)   self (s)  function\n");
    for (i = 0; i < 20 && i < st_len; ++i) {
        fp = sorttab[i];
        prof_func_line (fd, fp -> uf_tm_count, & fp -> uf_tm_total, & fp -> uf_tm_self, prefer_self);
        if (fp->uf_name[0] == K_SPECIAL)
            fprintf (fd, " <SNR>%s()\n", fp->uf_name + 3);
        else
            fprintf (fd, " %s()\n", fp->uf_name);
    }
    fprintf (fd, "\n");
}

static int prof_self_cmp (const void *s1, const void *s2) {
    ufunc_T *p1, *p2;
    p1 = *(ufunc_T**) s1;
    p2 = *(ufunc_T**) s2;
    return profile_cmp (&p1->uf_tm_self, &p2->uf_tm_self);
}

void prof_child_exit (proftime_T *tm) {
    funccall_T *fc = current_funccal;
    if (fc != NULL && fc->func->uf_profiling) {
        profile_end (& fc -> prof_child);
        profile_sub_wait (tm, & fc -> prof_child);
        profile_add (& fc -> func -> uf_tm_children, & fc -> prof_child);
        profile_add (& fc -> func -> uf_tml_children, & fc -> prof_child);
    }
    script_prof_restore (tm);
}

char_u *get_return_cmd (void *rettv) {
    char_u *s = NULL;
    char_u *tofree = NULL;
    char_u numbuf [NUMBUFLEN];
    if (rettv != NULL)
        s = echo_string ((typval_T *) rettv, &tofree, numbuf, 0);
    if (s == NULL)
        s = (char_u *) "";
    STRCPY (IObuff, ":return ");
    STRNCPY (IObuff + 8, s, IOSIZE - 8);
    if (STRLEN (s) + 8 >= IOSIZE)
        STRCPY (IObuff +IOSIZE - 4, "...");
    vim_free (tofree);
    return vim_strsave (IObuff);
}

dictitem_T *find_var_in_scoped_ht (char_u *name, int no_autoload) {
    dictitem_T *v = NULL;
    funccall_T *old_current_funccal = current_funccal;
    hashtab_T *ht;
    char_u *varname;
    if (current_funccal == NULL || current_funccal->func->uf_scoped == NULL)
        return NULL;
    current_funccal = current_funccal->func->uf_scoped;
    while (current_funccal) {
        ht = find_var_ht (name, &varname);
        if (ht != NULL && *varname != NUL) {
            v = find_var_in_ht (ht, *name, varname, no_autoload);
            if (v != NULL)
                break;
        }
        if (current_funccal == current_funccal->func->uf_scoped)
            break;
        current_funccal = current_funccal->func->uf_scoped;
    }
    current_funccal = old_current_funccal;
    return v;
}

char_u *get_user_func_name (expand_T *xp, int idx) {
    static long_u done;
    static hashitem_T *hi;
    ufunc_T *fp;
    if (idx == 0) {
        done = 0;
        hi = func_hashtab.ht_array;
    }
    if (done < func_hashtab.ht_used) {
        if (done++ > 0)
            ++hi;
        while (HASHITEM_EMPTY (hi))
            ++hi;
        fp = HI2UF (hi);
        if ((fp->uf_flags & FC_DICT) || STRNCMP (fp->uf_name, "<lambda>", 8) == 0)
            return (char_u *) "";
        if (STRLEN (fp->uf_name) + 4 >= IOSIZE)
            return fp->uf_name;
        cat_func_name (IObuff, fp);
        if (xp->xp_context != EXPAND_USER_FUNC) {
            STRCAT (IObuff, "(");
            if (!fp->uf_varargs && fp->uf_args.ga_len == 0)
                STRCAT (IObuff, ")");
        }
        return IObuff;
    }
    return NULL;
}

static void cat_func_name (char_u *buf, ufunc_T *fp) {
    if (fp->uf_name[0] == K_SPECIAL) {
        STRCPY (buf, "<SNR>");
        STRCAT (buf, fp -> uf_name + 3);
    }
    else
        STRCPY (buf, fp->uf_name);
}

dict_T *get_current_funccal_dict (hashtab_T *ht) {
    if (current_funccal != NULL && ht == &current_funccal->l_vars.dv_hashtab)
        return &current_funccal->l_vars;
    return NULL;
}

hashitem_T *find_hi_in_scoped_ht (char_u *name, hashtab_T **pht) {
    funccall_T *old_current_funccal = current_funccal;
    hashtab_T *ht;
    hashitem_T *hi = NULL;
    char_u *varname;
    if (current_funccal == NULL || current_funccal->func->uf_scoped == NULL)
        return NULL;
    current_funccal = current_funccal->func->uf_scoped;
    while (current_funccal != NULL) {
        ht = find_var_ht (name, &varname);
        if (ht != NULL && *varname != NUL) {
            hi = hash_find (ht, varname);
            if (!HASHITEM_EMPTY (hi)) {
                *pht = ht;
                break;
            }
        }
        if (current_funccal == current_funccal->func->uf_scoped)
            break;
        current_funccal = current_funccal->func->uf_scoped;
    }
    current_funccal = old_current_funccal;
    return hi;
}

int function_exists (char_u *name, int no_deref) {
    char_u *nm = name;
    char_u *p;
    int n = FALSE;
    int flag;
    flag = TFN_INT | TFN_QUIET | TFN_NO_AUTOLOAD;
    if (no_deref)
        flag |= TFN_NO_DEREF;
    p = trans_function_name (&nm, FALSE, flag, NULL, NULL);
    nm = skipwhite (nm);
    if (p != NULL && (*nm == NUL || *nm == '('))
        n = translated_function_exists (p);
    vim_free (p);
    return n;
}

char_u *trans_function_name (char_u **pp, int skip, int flags, funcdict_T *fdp, partial_T **partial) {
    char_u *name = NULL;
    char_u *start;
    char_u *end;
    int lead;
    char_u sid_buf [20];
    int len;
    lval_T lv;
    if (fdp != NULL)
        vim_memset (fdp, 0, sizeof (funcdict_T));
    start = *pp;
    if ((*pp)[0] == K_SPECIAL && (*pp)[1] == KS_EXTRA && (*pp)[2] == (int) KE_SNR) {
        *pp += 3;
        len = get_id_len (pp) + 3;
        return vim_strnsave (start, len);
    }
    lead = eval_fname_script (start);
    if (lead > 2)
        start += lead;
    end = get_lval (start, NULL, &lv, FALSE, skip, flags | GLV_READ_ONLY, lead > 2 ? 0 : FNE_CHECK_START);
    if (end == start) {
        if (!skip)
            EMSG (_ ("E129: Function name required"));
        goto theend;
    }
    if (end == NULL || (lv.ll_tv != NULL && (lead > 2 || lv.ll_range))) {
        if (!aborting ()) {
            if (end != NULL)
                EMSG2 (_ (e_invarg2), start);
        }
        else
            *pp = find_name_end (start, NULL, NULL, FNE_INCL_BR);
        goto theend;
    }
    if (lv.ll_tv != NULL) {
        if (fdp != NULL) {
            fdp->fd_dict = lv.ll_dict;
            fdp->fd_newkey = lv.ll_newkey;
            lv.ll_newkey = NULL;
            fdp->fd_di = lv.ll_di;
        }
        if (lv.ll_tv->v_type == VAR_FUNC && lv.ll_tv->vval.v_string != NULL) {
            name = vim_strsave (lv.ll_tv->vval.v_string);
            *pp = end;
        }
        else if (lv.ll_tv->v_type == VAR_PARTIAL && lv.ll_tv->vval.v_partial != NULL) {
            name = vim_strsave (partial_name (lv.ll_tv->vval.v_partial));
            *pp = end;
            if (partial != NULL)
                *partial = lv.ll_tv->vval.v_partial;
        }
        else {
            if (!skip && !(flags & TFN_QUIET) && (fdp == NULL || lv.ll_dict == NULL || fdp->fd_newkey == NULL))
                EMSG (_ (e_funcref));
            else
                *pp = end;
            name = NULL;
        }
        goto theend;
    }
    if (lv.ll_name == NULL) {
        *pp = end;
        goto theend;
    }
    if (lv.ll_exp_name != NULL) {
        len = (int) STRLEN (lv.ll_exp_name);
        name = deref_func_name (lv.ll_exp_name, &len, partial, flags &TFN_NO_AUTOLOAD);
        if (name == lv.ll_exp_name)
            name = NULL;
    }
    else if (!(flags & TFN_NO_DEREF)) {
        len = (int) (end - *pp);
        name = deref_func_name (*pp, &len, partial, flags &TFN_NO_AUTOLOAD);
        if (name == *pp)
            name = NULL;
    }
    if (name != NULL) {
        name = vim_strsave (name);
        *pp = end;
        if (STRNCMP (name, "<SNR>", 5) == 0) {
            name[0] = K_SPECIAL;
            name[1] = KS_EXTRA;
            name[2] = (int) KE_SNR;
            mch_memmove (name + 3, name + 5, STRLEN (name + 5) + 1);
        }
        goto theend;
    }
    if (lv.ll_exp_name != NULL) {
        len = (int) STRLEN (lv.ll_exp_name);
        if (lead <= 2 && lv.ll_name == lv.ll_exp_name && STRNCMP (lv.ll_name, "s:", 2) == 0) {
            lv.ll_name += 2;
            len -= 2;
            lead = 2;
        }
    }
    else {
        if (lead == 2 || (lv.ll_name[0] == 'g' && lv.ll_name[1] == ':'))
            lv.ll_name += 2;
        len = (int) (end - lv.ll_name);
    }
    if (skip)
        lead = 0;
    else if (lead > 0) {
        lead = 3;
        if ((lv.ll_exp_name != NULL && eval_fname_sid (lv.ll_exp_name)) || eval_fname_sid (*pp)) {
            if (current_SID <= 0) {
                EMSG (_ (e_usingsid));
                goto theend;
            }
            sprintf ((char *) sid_buf, "%ld_", (long) current_SID);
            lead += (int) STRLEN (sid_buf);
        }
    }
    else if (!(flags & TFN_INT) && builtin_function (lv.ll_name, len)) {
        EMSG2 (_ ("E128: Function name must start with a capital or \"s:\": %s"), start);
        goto theend;
    }
    if (!skip && !(flags & TFN_QUIET) && !(flags & TFN_NO_DEREF)) {
        char_u *cp = vim_strchr (lv.ll_name, ':');
        if (cp != NULL && cp < end) {
            EMSG2 (_ ("E884: Function name cannot contain a colon: %s"), start);
            goto theend;
        }
    }
    name = alloc ((unsigned ) (len + lead + 1));
    if (name != NULL) {
        if (lead > 0) {
            name[0] = K_SPECIAL;
            name[1] = KS_EXTRA;
            name[2] = (int) KE_SNR;
            if (lead > 3)
                STRCPY (name +3, sid_buf);
        }
        mch_memmove (name + lead, lv.ll_name, (size_t) len);
        name[lead + len] = NUL;
    }
    *pp = end;
theend :
    clear_lval (&lv);
    return name;
}

char_u *deref_func_name (char_u *name, int *lenp, partial_T **partialp, int no_autoload) {
    dictitem_T *v;
    int cc;
    char_u *s;
    if (partialp != NULL)
        *partialp = NULL;
    cc = name[*lenp];
    name[*lenp] = NUL;
    v = find_var (name, NULL, no_autoload);
    name[*lenp] = cc;
    if (v != NULL && v->di_tv.v_type == VAR_FUNC) {
        if (v->di_tv.vval.v_string == NULL) {
            *lenp = 0;
            return (char_u *) "";
        }
        s = v->di_tv.vval.v_string;
        *lenp = (int) STRLEN (s);
        return s;
    }
    if (v != NULL && v->di_tv.v_type == VAR_PARTIAL) {
        partial_T *pt = v->di_tv.vval.v_partial;
        if (pt == NULL) {
            *lenp = 0;
            return (char_u *) "";
        }
        if (partialp != NULL)
            *partialp = pt;
        s = partial_name (pt);
        *lenp = (int) STRLEN (s);
        return s;
    }
    return name;
}

int translated_function_exists (char_u *name) {
    if (builtin_function (name, -1))
        return find_internal_func (name) >= 0;
    return find_func (name) != NULL;
}

void discard_pending_return (void *rettv) {
    free_tv ((typval_T *) rettv);
}

char_u *get_func_line (int c, void *cookie, int indent) {
    funccall_T *fcp = (funccall_T *) cookie;
    ufunc_T *fp = fcp->func;
    char_u *retval;
    garray_T *gap;
    if (fcp->dbg_tick != debug_tick) {
        fcp->breakpoint = dbg_find_breakpoint (FALSE, fp->uf_name, sourcing_lnum);
        fcp->dbg_tick = debug_tick;
    }
    if (do_profiling == PROF_YES)
        func_line_end (cookie);
    gap = &fp->uf_lines;
    if (((fp->uf_flags & FC_ABORT) && did_emsg && !aborted_in_try ()) || fcp->returned)
        retval = NULL;
    else {
        while (fcp->linenr < gap->ga_len && ((char_u **) (gap->ga_data))[fcp->linenr] == NULL)
            ++fcp->linenr;
        if (fcp->linenr >= gap->ga_len)
            retval = NULL;
        else {
            retval = vim_strsave (((char_u **) (gap->ga_data))[fcp->linenr++]);
            sourcing_lnum = fcp->linenr;
            if (do_profiling == PROF_YES)
                func_line_start (cookie);
        }
    }
    if (fcp->breakpoint != 0 && fcp->breakpoint <= sourcing_lnum) {
        dbg_breakpoint (fp -> uf_name, sourcing_lnum);
        fcp->breakpoint = dbg_find_breakpoint (FALSE, fp->uf_name, sourcing_lnum);
        fcp->dbg_tick = debug_tick;
    }
    return retval;
}

void func_line_end (void *cookie) {
    funccall_T *fcp = (funccall_T *) cookie;
    ufunc_T *fp = fcp->func;
    if (fp->uf_profiling && fp->uf_tml_idx >= 0) {
        if (fp->uf_tml_execed) {
            ++fp->uf_tml_count[fp->uf_tml_idx];
            profile_end (& fp -> uf_tml_start);
            profile_sub_wait (& fp -> uf_tml_wait, & fp -> uf_tml_start);
            profile_add (& fp -> uf_tml_total [fp -> uf_tml_idx], & fp -> uf_tml_start);
            profile_self (& fp -> uf_tml_self [fp -> uf_tml_idx], & fp -> uf_tml_start, & fp -> uf_tml_children);
        }
        fp->uf_tml_idx = -1;
    }
}

void func_line_start (void *cookie) {
    funccall_T *fcp = (funccall_T *) cookie;
    ufunc_T *fp = fcp->func;
    if (fp->uf_profiling && sourcing_lnum >= 1 && sourcing_lnum <= fp->uf_lines.ga_len) {
        fp->uf_tml_idx = sourcing_lnum - 1;
        while (fp->uf_tml_idx > 0 && FUNCLINE (fp, fp->uf_tml_idx) == NULL)
            --fp->uf_tml_idx;
        fp->uf_tml_execed = FALSE;
        profile_start (& fp -> uf_tml_start);
        profile_zero (& fp -> uf_tml_children);
        profile_get_wait (& fp -> uf_tml_wait);
    }
}

int func_level (void *cookie) {
    return ((funccall_T *) cookie)->level;
}

char_u *func_name (void *cookie) {
    return ((funccall_T *) cookie)->func->uf_name;
}

linenr_T *func_breakpoint (void *cookie) {
    return &((funccall_T *) cookie)->breakpoint;
}

int *func_dbg_tick (void *cookie) {
    return &((funccall_T *) cookie)->dbg_tick;
}

int func_has_abort (void *cookie) {
    return ((funccall_T *) cookie)->func->uf_flags & FC_ABORT;
}

int func_has_ended (void *cookie) {
    funccall_T *fcp = (funccall_T *) cookie;
    return (((fcp->func->uf_flags & FC_ABORT) && did_emsg && !aborted_in_try ()) || fcp->returned);
}

void func_line_exec (void *cookie) {
    funccall_T *fcp = (funccall_T *) cookie;
    ufunc_T *fp = fcp->func;
    if (fp->uf_profiling && fp->uf_tml_idx >= 0)
        fp->uf_tml_execed = TRUE;
}

int current_func_returned (void) {
    return current_funccal->returned;
}

int do_return (exarg_T *eap, int reanimate, int is_cmd, void *rettv) {
    int idx;
    struct condstack *cstack = eap->cstack;
    if (reanimate)
        current_funccal->returned = FALSE;
    idx = cleanup_conditionals (eap->cstack, 0, TRUE);
    if (idx >= 0) {
        cstack->cs_pending[idx] = CSTP_RETURN;
        if (!is_cmd && !reanimate)
            cstack->cs_rettv[idx] = rettv;
        else {
            if (reanimate)
                rettv = current_funccal->rettv;
            if (rettv != NULL) {
                if ((cstack->cs_rettv[idx] = alloc_tv ()) != NULL)
                    *(typval_T*) cstack->cs_rettv[idx] = *(typval_T*) rettv;
                else
                    EMSG (_ (e_outofmem));
            }
            else
                cstack->cs_rettv[idx] = NULL;
            if (reanimate) {
                current_funccal->rettv->v_type = VAR_NUMBER;
                current_funccal->rettv->vval.v_number = 0;
            }
        }
        report_make_pending (CSTP_RETURN, rettv);
    }
    else {
        current_funccal->returned = TRUE;
        if (!reanimate && rettv != NULL) {
            clear_tv (current_funccal -> rettv);
            *current_funccal->rettv = *(typval_T*) rettv;
            if (!is_cmd)
                vim_free (rettv);
        }
    }
    return idx < 0;
}

static void call_user_func (ufunc_T *fp, int argcount, typval_T *argvars, typval_T *rettv, linenr_T firstline, linenr_T lastline, dict_T *selfdict) {
    char_u *save_sourcing_name;
    linenr_T save_sourcing_lnum;
    scid_T save_current_SID;
    funccall_T *fc;
    int save_did_emsg;
    static int depth = 0;
    dictitem_T *v;
    int fixvar_idx = 0;
    int i;
    int ai;
    int islambda = FALSE;
    char_u numbuf [NUMBUFLEN];
    char_u *name;
    size_t len;
    proftime_T wait_start;
    proftime_T call_start;
    if (depth >= p_mfd) {
        EMSG (_ ("E132: Function call depth is higher than 'maxfuncdepth'"));
        rettv->v_type = VAR_NUMBER;
        rettv->vval.v_number = -1;
        return;
    }
    ++depth;
    line_breakcheck ();
    fc = (funccall_T *) alloc (sizeof (funccall_T));
    fc->caller = current_funccal;
    current_funccal = fc;
    fc->func = fp;
    fc->rettv = rettv;
    rettv->vval.v_number = 0;
    fc->linenr = 0;
    fc->returned = FALSE;
    fc->level = ex_nesting_level;
    fc->breakpoint = dbg_find_breakpoint (FALSE, fp->uf_name, (linenr_T) 0);
    fc->dbg_tick = debug_tick;
    fc->fc_refcount = 0;
    fc->fc_copyID = 0;
    ga_init2 (& fc -> fc_funcs, sizeof (ufunc_T *), 1);
    func_ptr_ref (fp);
    if (STRNCMP (fp->uf_name, "<lambda>", 8) == 0)
        islambda = TRUE;
    init_var_dict (& fc -> l_vars, & fc -> l_vars_var, VAR_DEF_SCOPE);
    if (selfdict != NULL) {
        v = &fc->fixvar[fixvar_idx++].var;
        name = v->di_key;
        STRCPY (name, "self");
        v->di_flags = DI_FLAGS_RO + DI_FLAGS_FIX;
        hash_add (& fc -> l_vars.dv_hashtab, DI2HIKEY (v));
        v->di_tv.v_type = VAR_DICT;
        v->di_tv.v_lock = 0;
        v->di_tv.vval.v_dict = selfdict;
        ++selfdict->dv_refcount;
    }
    init_var_dict (& fc -> l_avars, & fc -> l_avars_var, VAR_SCOPE);
    add_nr_var (& fc -> l_avars, & fc -> fixvar [fixvar_idx ++].var, "0", (varnumber_T) (argcount - fp -> uf_args.ga_len));
    v = &fc->fixvar[fixvar_idx++].var;
    name = v->di_key;
    STRCPY (name, "000");
    v->di_flags = DI_FLAGS_RO | DI_FLAGS_FIX;
    hash_add (& fc -> l_avars.dv_hashtab, DI2HIKEY (v));
    v->di_tv.v_type = VAR_LIST;
    v->di_tv.v_lock = VAR_FIXED;
    v->di_tv.vval.v_list = &fc->l_varlist;
    vim_memset (& fc -> l_varlist, 0, sizeof (list_T));
    fc->l_varlist.lv_refcount = DO_NOT_FREE_CNT;
    fc->l_varlist.lv_lock = VAR_FIXED;
    add_nr_var (& fc -> l_avars, & fc -> fixvar [fixvar_idx ++].var, "firstline", (varnumber_T) firstline);
    add_nr_var (& fc -> l_avars, & fc -> fixvar [fixvar_idx ++].var, "lastline", (varnumber_T) lastline);
    for (i = 0; i < argcount; ++i) {
        int addlocal = FALSE;
        ai = i - fp->uf_args.ga_len;
        if (ai < 0) {
            name = FUNCARG (fp, i);
            if (islambda)
                addlocal = TRUE;
        }
        else {
            sprintf ((char *) numbuf, "%d", ai + 1);
            name = numbuf;
        }
        if (fixvar_idx < FIXVAR_CNT && STRLEN (name) <= VAR_SHORT_LEN) {
            v = &fc->fixvar[fixvar_idx++].var;
            v->di_flags = DI_FLAGS_RO | DI_FLAGS_FIX;
        }
        else {
            v = (dictitem_T *) alloc ((unsigned ) (sizeof (dictitem_T) + STRLEN (name)));
            if (v == NULL)
                break;
            v->di_flags = DI_FLAGS_RO | DI_FLAGS_FIX | DI_FLAGS_ALLOC;
        }
        STRCPY (v -> di_key, name);
        v->di_tv = argvars[i];
        v->di_tv.v_lock = VAR_FIXED;
        if (addlocal) {
            copy_tv (& v -> di_tv, & v -> di_tv);
            hash_add (& fc -> l_vars.dv_hashtab, DI2HIKEY (v));
        }
        else
            hash_add (&fc->l_avars.dv_hashtab, DI2HIKEY (v));
        if (ai >= 0 && ai < MAX_FUNC_ARGS) {
            list_append (& fc -> l_varlist, & fc -> l_listitems [ai]);
            fc->l_listitems[ai].li_tv = argvars[i];
            fc->l_listitems[ai].li_tv.v_lock = VAR_FIXED;
        }
    }
    ++RedrawingDisabled;
    save_sourcing_name = sourcing_name;
    save_sourcing_lnum = sourcing_lnum;
    sourcing_lnum = 1;
    len = (save_sourcing_name == NULL ? 0 : STRLEN (save_sourcing_name)) + STRLEN (fp->uf_name) + 20;
    sourcing_name = alloc ((unsigned ) len);
    if (sourcing_name != NULL) {
        if (save_sourcing_name != NULL && STRNCMP (save_sourcing_name, "function ", 9) == 0)
            sprintf ((char *) sourcing_name, "%s[%d]..", save_sourcing_name, (int) save_sourcing_lnum);
        else
            STRCPY (sourcing_name, "function ");
        cat_func_name (sourcing_name + STRLEN (sourcing_name), fp);
        if (p_verbose >= 12) {
            ++no_wait_return;
            verbose_enter_scroll ();
            smsg ((char_u *) _ ("calling %s"), sourcing_name);
            if (p_verbose >= 14) {
                char_u buf [MSG_BUF_LEN];
                char_u numbuf2 [NUMBUFLEN];
                char_u *tofree;
                char_u *s;
                msg_puts ((char_u *) "(");
                for (i = 0; i < argcount; ++i) {
                    if (i > 0)
                        msg_puts ((char_u *) ", ");
                    if (argvars[i].v_type == VAR_NUMBER)
                        msg_outnum ((long ) argvars[i].vval.v_number);
                    else {
                        ++emsg_off;
                        s = tv2string (&argvars[i], &tofree, numbuf2, 0);
                        --emsg_off;
                        if (s != NULL) {
                            if (vim_strsize (s) > MSG_BUF_CLEN) {
                                trunc_string (s, buf, MSG_BUF_CLEN, MSG_BUF_LEN);
                                s = buf;
                            }
                            msg_puts (s);
                            vim_free (tofree);
                        }
                    }
                }
                msg_puts ((char_u *) ")");
            }
            msg_puts ((char_u *) "\n");
            verbose_leave_scroll ();
            --no_wait_return;
        }
    }
    if (do_profiling == PROF_YES) {
        if (!fp->uf_profiling && has_profiling (FALSE, fp->uf_name, NULL))
            func_do_profile (fp);
        if (fp->uf_profiling || (fc->caller != NULL && fc->caller->func->uf_profiling)) {
            ++fp->uf_tm_count;
            profile_start (& call_start);
            profile_zero (& fp -> uf_tm_children);
        }
        script_prof_save (& wait_start);
    }
    save_current_SID = current_SID;
    current_SID = fp->uf_script_ID;
    save_did_emsg = did_emsg;
    did_emsg = FALSE;
    do_cmdline (NULL, get_func_line, (void *) fc, DOCMD_NOWAIT | DOCMD_VERBOSE | DOCMD_REPEAT);
    --RedrawingDisabled;
    if ((did_emsg && (fp->uf_flags & FC_ABORT)) || rettv->v_type == VAR_UNKNOWN) {
        clear_tv (rettv);
        rettv->v_type = VAR_NUMBER;
        rettv->vval.v_number = -1;
    }
    if (do_profiling == PROF_YES && (fp->uf_profiling || (fc->caller != NULL && fc->caller->func->uf_profiling))) {
        profile_end (& call_start);
        profile_sub_wait (& wait_start, & call_start);
        profile_add (& fp -> uf_tm_total, & call_start);
        profile_self (& fp -> uf_tm_self, & call_start, & fp -> uf_tm_children);
        if (fc->caller != NULL && fc->caller->func->uf_profiling) {
            profile_add (& fc -> caller -> func -> uf_tm_children, & call_start);
            profile_add (& fc -> caller -> func -> uf_tml_children, & call_start);
        }
    }
    if (p_verbose >= 12) {
        ++no_wait_return;
        verbose_enter_scroll ();
        if (aborting ())
            smsg ((char_u *) _ ("%s aborted"), sourcing_name);
        else if (fc->rettv->v_type == VAR_NUMBER)
            smsg ((char_u *) _ ("%s returning #%ld"), sourcing_name, (long ) fc->rettv->vval.v_number);
        else {
            char_u buf [MSG_BUF_LEN];
            char_u numbuf2 [NUMBUFLEN];
            char_u *tofree;
            char_u *s;
            ++emsg_off;
            s = tv2string (fc->rettv, &tofree, numbuf2, 0);
            --emsg_off;
            if (s != NULL) {
                if (vim_strsize (s) > MSG_BUF_CLEN) {
                    trunc_string (s, buf, MSG_BUF_CLEN, MSG_BUF_LEN);
                    s = buf;
                }
                smsg ((char_u *) _ ("%s returning %s"), sourcing_name, s);
                vim_free (tofree);
            }
        }
        msg_puts ((char_u *) "\n");
        verbose_leave_scroll ();
        --no_wait_return;
    }
    vim_free (sourcing_name);
    sourcing_name = save_sourcing_name;
    sourcing_lnum = save_sourcing_lnum;
    current_SID = save_current_SID;
    if (do_profiling == PROF_YES)
        script_prof_restore (&wait_start);
    if (p_verbose >= 12 && sourcing_name != NULL) {
        ++no_wait_return;
        verbose_enter_scroll ();
        smsg ((char_u *) _ ("continuing in %s"), sourcing_name);
        msg_puts ((char_u *) "\n");
        verbose_leave_scroll ();
        --no_wait_return;
    }
    did_emsg |= save_did_emsg;
    --depth;
    cleanup_function_call (fc);
}

void func_ptr_ref (ufunc_T *fp) {
    if (fp != NULL)
        ++fp->uf_refcount;
}

static void add_nr_var (dict_T *dp, dictitem_T *v, char *name, varnumber_T nr) {
    STRCPY (v -> di_key, name);
    v->di_flags = DI_FLAGS_RO | DI_FLAGS_FIX;
    hash_add (& dp -> dv_hashtab, DI2HIKEY (v));
    v->di_tv.v_type = VAR_NUMBER;
    v->di_tv.v_lock = VAR_FIXED;
    v->di_tv.vval.v_number = nr;
}

static void func_do_profile (ufunc_T *fp) {
    int len = fp->uf_lines.ga_len;
    if (len == 0)
        len = 1;
    fp->uf_tm_count = 0;
    profile_zero (& fp -> uf_tm_self);
    profile_zero (& fp -> uf_tm_total);
    if (fp->uf_tml_count == NULL)
        fp->uf_tml_count = (int *) alloc_clear ((unsigned ) (sizeof (int) * len));
    if (fp->uf_tml_total == NULL)
        fp->uf_tml_total = (proftime_T *) alloc_clear ((unsigned ) (sizeof (proftime_T) * len));
    if (fp->uf_tml_self == NULL)
        fp->uf_tml_self = (proftime_T *) alloc_clear ((unsigned ) (sizeof (proftime_T) * len));
    fp->uf_tml_idx = -1;
    if (fp->uf_tml_count == NULL || fp->uf_tml_total == NULL || fp->uf_tml_self == NULL)
        return;
    fp->uf_profiling = TRUE;
}

static void cleanup_function_call (funccall_T *fc) {
    current_funccal = fc->caller;
    if (fc->l_varlist.lv_refcount == DO_NOT_FREE_CNT && fc->l_vars.dv_refcount == DO_NOT_FREE_CNT && fc->l_avars.dv_refcount == DO_NOT_FREE_CNT && fc->fc_refcount <= 0) {
        free_funccal (fc, FALSE);
    }
    else {
        hashitem_T *hi;
        listitem_T *li;
        int todo;
        dictitem_T *v;
        fc->caller = previous_funccal;
        previous_funccal = fc;
        todo = (int) fc->l_avars.dv_hashtab.ht_used;
        for (hi = fc->l_avars.dv_hashtab.ht_array; todo > 0; ++hi) {
            if (!HASHITEM_EMPTY (hi)) {
                --todo;
                v = HI2DI (hi);
                copy_tv (& v -> di_tv, & v -> di_tv);
            }
        }
        for (li = fc->l_varlist.lv_first; li != NULL; li = li->li_next)
            copy_tv (&li->li_tv, &li->li_tv);
    }
}

static void emsg_funcname (char *ermsg, char_u *name) {
    char_u *p;
    if (*name == K_SPECIAL)
        p = concat_str ((char_u *) "<SNR>", name +3);
    else
        p = name;
    EMSG2 (_ (ermsg), p);
    if (p != name)
        vim_free (p);
}

int func_call (char_u *name, typval_T *args, partial_T *partial, dict_T *selfdict, typval_T *rettv) {
    listitem_T *item;
    typval_T argv [MAX_FUNC_ARGS + 1];
    int argc = 0;
    int dummy;
    int r = 0;
    for (item = args->vval.v_list->lv_first; item != NULL; item = item->li_next) {
        if (argc == MAX_FUNC_ARGS - (partial == NULL ? 0 : partial->pt_argc)) {
            EMSG (_ ("E699: Too many arguments"));
            break;
        }
        copy_tv (& item -> li_tv, & argv [argc ++]);
    }
    if (item == NULL)
        r = call_func (name, (int) STRLEN (name), rettv, argc, argv, NULL, curwin->w_cursor.lnum, curwin->w_cursor.lnum, &dummy, TRUE, partial, selfdict);
    while (argc > 0)
        clear_tv (&argv[--argc]);
    return r;
}

int get_lambda_tv (char_u **arg, typval_T *rettv, int evaluate) {
    garray_T newargs;
    garray_T newlines;
    garray_T *pnewargs;
    ufunc_T *fp = NULL;
    int varargs;
    int ret;
    char_u *start = skipwhite (*arg + 1);
    char_u *s, *e;
    static int lambda_no = 0;
    int *old_eval_lavars = eval_lavars_used;
    int eval_lavars = FALSE;
    ga_init (& newargs);
    ga_init (& newlines);
    ret = get_function_args (&start, '-', NULL, NULL, TRUE);
    if (ret == FAIL || *start != '>')
        return NOTDONE;
    if (evaluate)
        pnewargs = &newargs;
    else
        pnewargs = NULL;
    *arg = skipwhite (*arg + 1);
    ret = get_function_args (arg, '-', pnewargs, &varargs, FALSE);
    if (ret == FAIL || **arg != '>')
        goto errret;
    if (evaluate)
        eval_lavars_used = &eval_lavars;
    *arg = skipwhite (*arg + 1);
    s = *arg;
    ret = skip_expr (arg);
    if (ret == FAIL)
        goto errret;
    e = *arg;
    *arg = skipwhite (*arg);
    if (**arg != '}')
        goto errret;
    ++*arg;
    if (evaluate) {
        int len, flags = 0;
        char_u *p;
        char_u name [20];
        partial_T *pt;
        sprintf ((char *) name, "<lambda>%d", ++ lambda_no);
        fp = (ufunc_T *) alloc_clear ((unsigned ) (sizeof (ufunc_T) + STRLEN (name)));
        if (fp == NULL)
            goto errret;
        pt = (partial_T *) alloc_clear ((unsigned ) sizeof (partial_T));
        if (pt == NULL) {
            vim_free (fp);
            goto errret;
        }
        ga_init2 (& newlines, (int) sizeof (char_u *), 1);
        if (ga_grow (&newlines, 1) == FAIL)
            goto errret;
        len = 7 + e - s + 1;
        p = (char_u *) alloc (len);
        if (p == NULL)
            goto errret;
        ((char_u **) (newlines.ga_data))[newlines.ga_len++] = p;
        STRCPY (p, "return ");
        vim_strncpy (p + 7, s, e - s);
        fp->uf_refcount = 1;
        STRCPY (fp -> uf_name, name);
        hash_add (& func_hashtab, UF2HIKEY (fp));
        fp->uf_args = newargs;
        fp->uf_lines = newlines;
        if (current_funccal != NULL && eval_lavars) {
            flags |= FC_CLOSURE;
            if (register_closure (fp) == FAIL)
                goto errret;
        }
        else
            fp->uf_scoped = NULL;
        fp->uf_tml_count = NULL;
        fp->uf_tml_total = NULL;
        fp->uf_tml_self = NULL;
        fp->uf_profiling = FALSE;
        if (prof_def_func ())
            func_do_profile (fp);
        fp->uf_varargs = TRUE;
        fp->uf_flags = flags;
        fp->uf_calls = 0;
        fp->uf_script_ID = current_SID;
        pt->pt_func = fp;
        pt->pt_refcount = 1;
        rettv->vval.v_partial = pt;
        rettv->v_type = VAR_PARTIAL;
    }
    eval_lavars_used = old_eval_lavars;
    return OK;
errret :
    ga_clear_strings (&newargs);
    ga_clear_strings (& newlines);
    vim_free (fp);
    eval_lavars_used = old_eval_lavars;
    return FAIL;
}

static int get_function_args (char_u **argp, char_u endchar, garray_T *newargs, int *varargs, int skip) {
    int mustend = FALSE;
    char_u *arg = *argp;
    char_u *p = arg;
    int c;
    int i;
    if (newargs != NULL)
        ga_init2 (newargs, (int) sizeof (char_u *), 3);
    if (varargs != NULL)
        *varargs = FALSE;
    while (*p != endchar) {
        if (p[0] == '.' && p[1] == '.' && p[2] == '.') {
            if (varargs != NULL)
                *varargs = TRUE;
            p += 3;
            mustend = TRUE;
        }
        else {
            arg = p;
            while (ASCII_ISALNUM (*p) || *p == '_')
                ++p;
            if (arg == p || isdigit (*arg) || (p - arg == 9 && STRNCMP (arg, "firstline", 9) == 0) || (p - arg == 8 && STRNCMP (arg, "lastline", 8) == 0)) {
                if (!skip)
                    EMSG2 (_ ("E125: Illegal argument: %s"), arg);
                break;
            }
            if (newargs != NULL && ga_grow (newargs, 1) == FAIL)
                goto err_ret;
            if (newargs != NULL) {
                c = *p;
                *p = NUL;
                arg = vim_strsave (arg);
                if (arg == NULL) {
                    *p = c;
                    goto err_ret;
                }
                for (i = 0; i < newargs->ga_len; ++i)
                    if (STRCMP (((char_u **) (newargs->ga_data))[i], arg) == 0) {
                        EMSG2 (_ ("E853: Duplicate argument name: %s"), arg);
                        vim_free (arg);
                        goto err_ret;
                    }
                ((char_u **) (newargs->ga_data))[newargs->ga_len] = arg;
                newargs->ga_len++;
                *p = c;
            }
            if (*p == ',')
                ++p;
            else
                mustend = TRUE;
        }
        p = skipwhite (p);
        if (mustend && *p != endchar) {
            if (!skip)
                EMSG2 (_ (e_invarg2), *argp);
            break;
        }
    }
    if (*p != endchar)
        goto err_ret;
    ++p;
    *argp = p;
    return OK;
err_ret :
    if (newargs != NULL)
        ga_clear_strings (newargs);
    return FAIL;
}

static int register_closure (ufunc_T *fp) {
    if (fp->uf_scoped == current_funccal)
        return OK;
    funccal_unref (fp -> uf_scoped, fp, FALSE);
    fp->uf_scoped = current_funccal;
    current_funccal->fc_refcount++;
    if (ga_grow (&current_funccal->fc_funcs, 1) == FAIL)
        return FAIL;
    ((ufunc_T **) current_funccal->fc_funcs.ga_data)[current_funccal->fc_funcs.ga_len++] = fp;
    return OK;
}

int get_func_tv (char_u *name, int len, typval_T *rettv, char_u **arg, linenr_T firstline, linenr_T lastline, int *doesrange, int evaluate, partial_T *partial, dict_T *selfdict) {
    char_u *argp;
    int ret = OK;
    typval_T argvars [MAX_FUNC_ARGS + 1];
    int argcount = 0;
    argp = *arg;
    while (argcount < MAX_FUNC_ARGS - (partial == NULL ? 0 : partial->pt_argc)) {
        argp = skipwhite (argp +1);
        if (*argp == ')' || *argp == ',' || *argp == NUL)
            break;
        if (eval1 (&argp, &argvars[argcount], evaluate) == FAIL) {
            ret = FAIL;
            break;
        }
        ++argcount;
        if (*argp != ',')
            break;
    }
    if (*argp == ')')
        ++argp;
    else
        ret = FAIL;
    if (ret == OK) {
        int i = 0;
        if (get_vim_var_nr (VV_TESTING)) {
            if (funcargs.ga_itemsize == 0)
                ga_init2 (&funcargs, (int) sizeof (typval_T *), 50);
            for (i = 0; i < argcount; ++i)
                if (ga_grow (&funcargs, 1) == OK)
                    ((typval_T **) funcargs.ga_data)[funcargs.ga_len++] = &argvars[i];
        }
        ret = call_func (name, len, rettv, argcount, argvars, NULL, firstline, lastline, doesrange, evaluate, partial, selfdict);
        funcargs.ga_len -= i;
    }
    else if (!aborting ()) {
        if (argcount == MAX_FUNC_ARGS)
            emsg_funcname (N_ ("E740: Too many arguments for function %s"), name);
        else
            emsg_funcname (N_ ("E116: Invalid arguments for function %s"), name);
    }
    while (--argcount >= 0)
        clear_tv (&argvars[argcount]);
    *arg = skipwhite (argp);
    return ret;
}

#define FLEN_FIXED 40

dict_T *make_partial (dict_T *selfdict_in, typval_T *rettv) {
    char_u *fname;
    char_u *tofree = NULL;
    ufunc_T *fp;
    char_u fname_buf [FLEN_FIXED + 1];
    int error;
    dict_T *selfdict = selfdict_in;
    if (rettv->v_type == VAR_PARTIAL && rettv->vval.v_partial->pt_func != NULL)
        fp = rettv->vval.v_partial->pt_func;
    else {
        fname = rettv->v_type == VAR_FUNC ? rettv->vval.v_string : rettv->vval.v_partial->pt_name;
        fname = fname_trans_sid (fname, fname_buf, &tofree, &error);
        fp = find_func (fname);
        vim_free (tofree);
    }
    if (fp != NULL && (fp->uf_flags & FC_DICT)) {
        partial_T *pt = (partial_T *) alloc_clear (sizeof (partial_T));
        if (pt != NULL) {
            pt->pt_refcount = 1;
            pt->pt_dict = selfdict;
            pt->pt_auto = TRUE;
            selfdict = NULL;
            if (rettv->v_type == VAR_FUNC) {
                pt->pt_name = rettv->vval.v_string;
            }
            else {
                partial_T *ret_pt = rettv->vval.v_partial;
                int i;
                if (ret_pt->pt_name != NULL) {
                    pt->pt_name = vim_strsave (ret_pt->pt_name);
                    func_ref (pt -> pt_name);
                }
                else {
                    pt->pt_func = ret_pt->pt_func;
                    func_ptr_ref (pt -> pt_func);
                }
                if (ret_pt->pt_argc > 0) {
                    pt->pt_argv = (typval_T *) alloc (sizeof (typval_T) * ret_pt->pt_argc);
                    if (pt->pt_argv == NULL)
                        pt->pt_argc = 0;
                    else {
                        pt->pt_argc = ret_pt->pt_argc;
                        for (i = 0; i < pt->pt_argc; i++)
                            copy_tv (&ret_pt->pt_argv[i], &pt->pt_argv[i]);
                    }
                }
                partial_unref (ret_pt);
            }
            rettv->v_type = VAR_PARTIAL;
            rettv->vval.v_partial = pt;
        }
    }
    return selfdict;
}

