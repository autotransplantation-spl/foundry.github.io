
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
EXTERN char_u e_nogroup [] INIT (= N_ ("E28: No such highlight group name: %s"));
EXTERN long  p_so;
EXTERN int p_write;
char *m_onlyone = N_ ("Already only one window");
EXTERN int p_ea;
EXTERN int p_spr;
EXTERN int p_sb;
EXTERN char_u *p_ead;
EXTERN long  p_ls;
EXTERN long  p_wmw;
EXTERN int ignored;
EXTERN long  p_wiw;
EXTERN win_T *lastwin;
EXTERN long  p_stal;
EXTERN long  p_wmh;
EXTERN long  p_wh;
EXTERN win_T *firstwin;
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
int last_win_id = LOWEST_WIN_ID - 1;
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

void shell_new_rows (void) {
    int h = (int) ROWS_AVAIL;
    if (firstwin == NULL)
        return;
    if (h < frame_minheight (topframe, NULL))
        h = frame_minheight (topframe, NULL);
    frame_new_height (topframe, h, FALSE, TRUE);
    if (!frame_check_height (topframe, h))
        frame_new_height (topframe, h, FALSE, FALSE);
    (void) win_comp_pos ();
    compute_cmdrow ();
    curtab->tp_ch_used = p_ch;
}

static int frame_minheight (frame_T *topfrp, win_T *next_curwin) {
    frame_T *frp;
    int m;
    int n;
    if (topfrp->fr_win != NULL) {
        if (topfrp->fr_win == next_curwin)
            m = p_wh + topfrp->fr_win->w_status_height;
        else {
            m = p_wmh + topfrp->fr_win->w_status_height;
            if (topfrp->fr_win == curwin && next_curwin == NULL) {
                if (p_wmh == 0)
                    ++m;
                m += WINBAR_HEIGHT (curwin);
            }
        }
    }
    else if (topfrp->fr_layout == FR_ROW) {
        m = 0;
        for (frp = topfrp->fr_child; frp != NULL; frp = frp->fr_next) {
            n = frame_minheight (frp, next_curwin);
            if (n > m)
                m = n;
        }
    }
    else {
        m = 0;
        for (frp = topfrp->fr_child; frp != NULL; frp = frp->fr_next)
            m += frame_minheight (frp, next_curwin);
    }
    return m;
}

static void frame_new_height (frame_T *topfrp, int height, int topfirst, int wfh) {
    frame_T *frp;
    int extra_lines;
    int h;
    if (topfrp->fr_win != NULL) {
        win_new_height (topfrp -> fr_win, height - topfrp -> fr_win -> w_status_height - WINBAR_HEIGHT (topfrp -> fr_win));
    }
    else if (topfrp->fr_layout == FR_ROW) {
        do {
            for (frp = topfrp->fr_child; frp != NULL; frp = frp->fr_next) {
                frame_new_height (frp, height, topfirst, wfh);
                if (frp->fr_height > height) {
                    height = frp->fr_height;
                    break;
                }
            }
        }
        while (frp != NULL);
    }
    else {
        frp = topfrp->fr_child;
        if (wfh)
            while (frame_fixed_height (frp)) {
                frp = frp->fr_next;
                if (frp == NULL)
                    return;
            }
        if (!topfirst) {
            while (frp->fr_next != NULL)
                frp = frp->fr_next;
            if (wfh)
                while (frame_fixed_height (frp))
                    frp = frp->fr_prev;
        }
        extra_lines = height - topfrp->fr_height;
        if (extra_lines < 0) {
            while (frp != NULL) {
                h = frame_minheight (frp, NULL);
                if (frp->fr_height + extra_lines < h) {
                    extra_lines += frp->fr_height - h;
                    frame_new_height (frp, h, topfirst, wfh);
                }
                else {
                    frame_new_height (frp, frp -> fr_height + extra_lines, topfirst, wfh);
                    break;
                }
                if (topfirst) {
                    do
                        frp = frp->fr_next;
                    while (wfh && frp != NULL && frame_fixed_height (frp));
                }
                else {
                    do
                        frp = frp->fr_prev;
                    while (wfh && frp != NULL && frame_fixed_height (frp));
                }
                if (frp == NULL)
                    height -= extra_lines;
            }
        }
        else if (extra_lines > 0) {
            frame_new_height (frp, frp -> fr_height + extra_lines, topfirst, wfh);
        }
    }
    topfrp->fr_height = height;
}

void win_new_height (win_T *wp, int height) {
    int prev_height = wp->w_height;
    if (height < 0)
        height = 0;
    if (wp->w_height == height)
        return;
    if (wp->w_height > 0) {
        if (wp == curwin)
            validate_cursor ();
        if (wp->w_height != prev_height)
            return;
        if (wp->w_wrow != wp->w_prev_fraction_row)
            set_fraction (wp);
    }
    wp->w_height = height;
    wp->w_skipcol = 0;
    if (!exiting)
        scroll_to_fraction (wp, prev_height);
}

int vim_FullName (char_u *fname, char_u *buf, int len, int force) {
    int retval = OK;
    int url;
    *buf = NUL;
    if (fname == NULL)
        return FAIL;
    url = path_with_url (fname);
    if (!url)
        retval = mch_FullName (fname, buf, len, force);
    if (url || retval == FAIL) {
        vim_strncpy (buf, fname, len - 1);
    }
    return retval;
}

int path_with_url (char_u *fname) {
    char_u *p;
    for (p = fname; isalpha (*p); ++p)
        ;
    return path_is_url (p);
}

static int path_is_url (char_u *p) {
    if (STRNCMP (p, "://", (size_t) 3) == 0)
        return URL_SLASH;
    else if (STRNCMP (p, ":\\\\", (size_t) 3) == 0)
        return URL_BACKSLASH;
    return 0;
}

void check_lnums (int do_curwin) {
    win_T *wp;
    tabpage_T *tp;
    FOR_ALL_TAB_WINDOWS (tp, wp)
        if ((do_curwin || wp != curwin) && wp->w_buffer == curbuf) {
            if (wp->w_cursor.lnum > curbuf->b_ml.ml_line_count)
                wp->w_cursor.lnum = curbuf->b_ml.ml_line_count;
            if (wp->w_topline > curbuf->b_ml.ml_line_count)
                wp->w_topline = curbuf->b_ml.ml_line_count;
        }
}

int vim_isAbsName (char_u *name) {
    return (path_with_url (name) != 0 || mch_isFullName (name));
}

int min_rows (void) {
    int total;
    tabpage_T *tp;
    int n;
    if (firstwin == NULL)
        return MIN_LINES;
    total = 0;
    FOR_ALL_TABPAGES (tp) {
        n = frame_minheight (tp->tp_topframe, NULL);
        if (total < n)
            total = n;
    }
    total += tabline_height ();
    total += 1;
    return total;
}

int tabline_height (void) {
    switch (p_stal) {
    case 0 :
        return 0;
    case 1 :
        return (first_tabpage->tp_next == NULL) ? 0 : 1;
    }
    return 1;
}

int tabpage_index (tabpage_T *ftp) {
    int i = 1;
    tabpage_T *tp;
    for (tp = first_tabpage; tp != NULL && tp != ftp; tp = tp->tp_next)
        ++i;
    return i;
}

int win_valid_any_tab (win_T *win) {
    win_T *wp;
    tabpage_T *tp;
    if (win == NULL)
        return FALSE;
    FOR_ALL_TABPAGES (tp) {
        FOR_ALL_WINDOWS_IN_TAB (tp, wp) {
            if (wp == win)
                return TRUE;
        }
    }
    return FALSE;
}

void goto_tabpage_win (tabpage_T *tp, win_T *wp) {
    goto_tabpage_tp (tp, TRUE, TRUE);
    if (curtab == tp && win_valid (wp)) {
        win_enter (wp, TRUE);
    }
}

void goto_tabpage_tp (tabpage_T *tp, int trigger_enter_autocmds, int trigger_leave_autocmds) {
    set_keep_msg (NULL, 0);
    if (tp != curtab && leave_tabpage (tp->tp_curwin->w_buffer, trigger_leave_autocmds) == OK) {
        if (valid_tabpage (tp))
            enter_tabpage (tp, curbuf, trigger_enter_autocmds, trigger_leave_autocmds);
        else
            enter_tabpage (curtab, curbuf, trigger_enter_autocmds, trigger_leave_autocmds);
    }
}

static int leave_tabpage (buf_T *new_curbuf, int trigger_leave_autocmds) {
    tabpage_T *tp = curtab;
    reset_VIsual_and_resel ();
    if (trigger_leave_autocmds) {
        if (new_curbuf != curbuf) {
            apply_autocmds (EVENT_BUFLEAVE, NULL, NULL, FALSE, curbuf);
            if (curtab != tp)
                return FAIL;
        }
        apply_autocmds (EVENT_WINLEAVE, NULL, NULL, FALSE, curbuf);
        if (curtab != tp)
            return FAIL;
        apply_autocmds (EVENT_TABLEAVE, NULL, NULL, FALSE, curbuf);
        if (curtab != tp)
            return FAIL;
    }
    if (gui.in_use)
        gui_remove_scrollbars ();
    tp->tp_curwin = curwin;
    tp->tp_prevwin = prevwin;
    tp->tp_firstwin = firstwin;
    tp->tp_lastwin = lastwin;
    tp->tp_old_Rows = Rows;
    tp->tp_old_Columns = Columns;
    firstwin = NULL;
    lastwin = NULL;
    return OK;
}

int valid_tabpage (tabpage_T *tpc) {
    tabpage_T *tp;
    FOR_ALL_TABPAGES (tp)
        if (tp == tpc)
            return TRUE;
    return FALSE;
}

static void enter_tabpage (tabpage_T *tp, buf_T *old_curbuf, int trigger_enter_autocmds, int trigger_leave_autocmds) {
    int old_off = tp->tp_firstwin->w_winrow;
    win_T *next_prevwin = tp->tp_prevwin;
    curtab = tp;
    firstwin = tp->tp_firstwin;
    lastwin = tp->tp_lastwin;
    topframe = tp->tp_topframe;
    win_enter_ext (tp -> tp_curwin, FALSE, TRUE, FALSE, trigger_enter_autocmds, trigger_leave_autocmds);
    prevwin = next_prevwin;
    last_status (FALSE);
    (void) win_comp_pos ();
    must_redraw = CLEAR;
    diff_need_scrollbind = TRUE;
    p_ch = curtab->tp_ch_used;
    if (curtab->tp_old_Rows != Rows || (old_off != firstwin->w_winrow))
        shell_new_rows ();
    if (curtab->tp_old_Columns != Columns && starting == 0)
        shell_new_columns ();
    gui_may_update_scrollbars ();
    if (trigger_enter_autocmds) {
        apply_autocmds (EVENT_TABENTER, NULL, NULL, FALSE, curbuf);
        if (old_curbuf != curbuf)
            apply_autocmds (EVENT_BUFENTER, NULL, NULL, FALSE, curbuf);
    }
    redraw_all_later (CLEAR);
}

static void win_enter_ext (win_T *wp, int undo_sync, int curwin_invalid, int trigger_new_autocmds, int trigger_enter_autocmds, int trigger_leave_autocmds) {
    int other_buffer = FALSE;
    if (wp == curwin && !curwin_invalid)
        return;
    if (!curwin_invalid && trigger_leave_autocmds) {
        if (wp->w_buffer != curbuf) {
            apply_autocmds (EVENT_BUFLEAVE, NULL, NULL, FALSE, curbuf);
            other_buffer = TRUE;
            if (!win_valid (wp))
                return;
        }
        apply_autocmds (EVENT_WINLEAVE, NULL, NULL, FALSE, curbuf);
        if (!win_valid (wp))
            return;
        if (aborting ())
            return;
    }
    if (undo_sync && curbuf != wp->w_buffer)
        u_sync (FALSE);
    update_topline ();
    if (wp->w_buffer != curbuf)
        buf_copy_options (wp->w_buffer, BCO_ENTER | BCO_NOHELP);
    if (!curwin_invalid) {
        prevwin = curwin;
        curwin->w_redr_status = TRUE;
    }
    curwin = wp;
    curbuf = wp->w_buffer;
    check_cursor ();
    if (!virtual_active ())
        curwin->w_cursor.coladd = 0;
    changed_line_abv_curs ();
    if (curwin->w_localdir != NULL) {
        if (globaldir == NULL) {
            char_u cwd [MAXPATHL];
            if (mch_dirname (cwd, MAXPATHL) == OK)
                globaldir = vim_strsave (cwd);
        }
        if (mch_chdir ((char *) curwin->w_localdir) == 0)
            shorten_fnames (TRUE);
    }
    else if (globaldir != NULL) {
        ignored = mch_chdir ((char *) globaldir);
        VIM_CLEAR (globaldir);
        shorten_fnames (TRUE);
    }
    if (trigger_new_autocmds)
        apply_autocmds (EVENT_WINNEW, NULL, NULL, FALSE, curbuf);
    if (trigger_enter_autocmds) {
        apply_autocmds (EVENT_WINENTER, NULL, NULL, FALSE, curbuf);
        if (other_buffer)
            apply_autocmds (EVENT_BUFENTER, NULL, NULL, FALSE, curbuf);
    }
    maketitle ();
    curwin->w_redr_status = TRUE;
    redraw_tabline = TRUE;
    if (restart_edit)
        redraw_later (VALID);
    if (curwin->w_height < p_wh && !curwin->w_p_wfh)
        win_setheight ((int) p_wh);
    else if (curwin->w_height == 0)
        win_setheight (1);
    if (curwin->w_width < p_wiw && !curwin->w_p_wfw)
        win_setwidth ((int) p_wiw);
    setmouse ();
    DO_AUTOCHDIR
}

int win_valid (win_T *win) {
    win_T *wp;
    if (win == NULL)
        return FALSE;
    FOR_ALL_WINDOWS (wp)
        if (wp == win)
            return TRUE;
    return FALSE;
}

void win_setheight (int height) {
    win_setheight_win (height, curwin);
}

void win_setheight_win (int height, win_T *win) {
    int row;
    if (win == curwin) {
        if (height < p_wmh)
            height = p_wmh;
        if (height == 0)
            height = 1;
        height += WINBAR_HEIGHT (curwin);
    }
    frame_setheight (win -> w_frame, height + win -> w_status_height);
    row = win_comp_pos ();
    if (full_screen && msg_scrolled == 0 && row < cmdline_row)
        screen_fill (row, cmdline_row, 0, (int) Columns, ' ', ' ', 0);
    cmdline_row = row;
    msg_row = row;
    msg_col = 0;
    redraw_all_later (NOT_VALID);
}

static void frame_setheight (frame_T *curfrp, int height) {
    int room;
    int take;
    int room_cmdline;
    int run;
    frame_T *frp;
    int h;
    int room_reserved;
    if (curfrp->fr_height == height)
        return;
    if (curfrp->fr_parent == NULL) {
        if (height > ROWS_AVAIL)
            height = ROWS_AVAIL;
        if (height > 0)
            frame_new_height (curfrp, height, FALSE, FALSE);
    }
    else if (curfrp->fr_parent->fr_layout == FR_ROW) {
        h = frame_minheight (curfrp->fr_parent, NULL);
        if (height < h)
            height = h;
        frame_setheight (curfrp -> fr_parent, height);
    }
    else {
        for (run = 1; run <= 2; ++run) {
            room = 0;
            room_reserved = 0;
            for (frp = curfrp->fr_parent->fr_child; frp != NULL; frp = frp->fr_next) {
                if (frp != curfrp && frp->fr_win != NULL && frp->fr_win->w_p_wfh)
                    room_reserved += frp->fr_height;
                room += frp->fr_height;
                if (frp != curfrp)
                    room -= frame_minheight (frp, NULL);
            }
            if (curfrp->fr_width != Columns)
                room_cmdline = 0;
            else {
                room_cmdline = Rows - p_ch - (lastwin->w_winrow + VISIBLE_HEIGHT (lastwin) + lastwin->w_status_height);
                if (room_cmdline < 0)
                    room_cmdline = 0;
            }
            if (height <= room + room_cmdline)
                break;
            if (run == 2 || curfrp->fr_width == Columns) {
                if (height > room + room_cmdline)
                    height = room + room_cmdline;
                break;
            }
            frame_setheight (curfrp -> fr_parent, height + frame_minheight (curfrp -> fr_parent, NOWIN) - (int) p_wmh - 1);
        }
        take = height - curfrp->fr_height;
        if (height > room + room_cmdline - room_reserved)
            room_reserved = room + room_cmdline - height;
        if (take < 0 && room - curfrp->fr_height < room_reserved)
            room_reserved = 0;
        if (take > 0 && room_cmdline > 0) {
            if (take < room_cmdline)
                room_cmdline = take;
            take -= room_cmdline;
            topframe->fr_height += room_cmdline;
        }
        frame_new_height (curfrp, height, FALSE, FALSE);
        for (run = 0; run < 2; ++run) {
            if (run == 0)
                frp = curfrp->fr_next;
            else
                frp = curfrp->fr_prev;
            while (frp != NULL && take != 0) {
                h = frame_minheight (frp, NULL);
                if (room_reserved > 0 && frp->fr_win != NULL && frp->fr_win->w_p_wfh) {
                    if (room_reserved >= frp->fr_height)
                        room_reserved -= frp->fr_height;
                    else {
                        if (frp->fr_height - room_reserved > take)
                            room_reserved = frp->fr_height - take;
                        take -= frp->fr_height - room_reserved;
                        frame_new_height (frp, room_reserved, FALSE, FALSE);
                        room_reserved = 0;
                    }
                }
                else {
                    if (frp->fr_height - take < h) {
                        take -= frp->fr_height - h;
                        frame_new_height (frp, h, FALSE, FALSE);
                    }
                    else {
                        frame_new_height (frp, frp -> fr_height - take, FALSE, FALSE);
                        take = 0;
                    }
                }
                if (run == 0)
                    frp = frp->fr_next;
                else
                    frp = frp->fr_prev;
            }
        }
    }
}

int win_comp_pos (void) {
    int row = tabline_height ();
    int col = 0;
    frame_comp_pos (topframe, & row, & col);
    return row;
}

static void frame_comp_pos (frame_T *topfrp, int *row, int *col) {
    win_T *wp;
    frame_T *frp;
    int startcol;
    int startrow;
    int h;
    wp = topfrp->fr_win;
    if (wp != NULL) {
        if (wp->w_winrow != *row || wp->w_wincol != *col) {
            wp->w_winrow = *row;
            wp->w_wincol = *col;
            redraw_win_later (wp, NOT_VALID);
            wp->w_redr_status = TRUE;
        }
        h = VISIBLE_HEIGHT (wp) + wp->w_status_height;
        *row += h > topfrp->fr_height ? topfrp->fr_height : h;
        *col += wp->w_width + wp->w_vsep_width;
    }
    else {
        startrow = *row;
        startcol = *col;
        for (frp = topfrp->fr_child; frp != NULL; frp = frp->fr_next) {
            if (topfrp->fr_layout == FR_ROW)
                *row = startrow;
            else
                *col = startcol;
            frame_comp_pos (frp, row, col);
        }
    }
}

void win_setwidth (int width) {
    win_setwidth_win (width, curwin);
}

void win_setwidth_win (int width, win_T *wp) {
    if (wp == curwin) {
        if (width < p_wmw)
            width = p_wmw;
        if (width == 0)
            width = 1;
    }
    frame_setwidth (wp -> w_frame, width + wp -> w_vsep_width);
    (void) win_comp_pos ();
    redraw_all_later (NOT_VALID);
}

static void frame_setwidth (frame_T *curfrp, int width) {
    int room;
    int take;
    int run;
    frame_T *frp;
    int w;
    int room_reserved;
    if (curfrp->fr_width == width)
        return;
    if (curfrp->fr_parent == NULL)
        return;
    if (curfrp->fr_parent->fr_layout == FR_COL) {
        w = frame_minwidth (curfrp->fr_parent, NULL);
        if (width < w)
            width = w;
        frame_setwidth (curfrp -> fr_parent, width);
    }
    else {
        for (run = 1; run <= 2; ++run) {
            room = 0;
            room_reserved = 0;
            for (frp = curfrp->fr_parent->fr_child; frp != NULL; frp = frp->fr_next) {
                if (frp != curfrp && frp->fr_win != NULL && frp->fr_win->w_p_wfw)
                    room_reserved += frp->fr_width;
                room += frp->fr_width;
                if (frp != curfrp)
                    room -= frame_minwidth (frp, NULL);
            }
            if (width <= room)
                break;
            if (run == 2 || curfrp->fr_height >= ROWS_AVAIL) {
                if (width > room)
                    width = room;
                break;
            }
            frame_setwidth (curfrp -> fr_parent, width + frame_minwidth (curfrp -> fr_parent, NOWIN) - (int) p_wmw - 1);
        }
        take = width - curfrp->fr_width;
        if (width > room - room_reserved)
            room_reserved = room - width;
        if (take < 0 && room - curfrp->fr_width < room_reserved)
            room_reserved = 0;
        frame_new_width (curfrp, width, FALSE, FALSE);
        for (run = 0; run < 2; ++run) {
            if (run == 0)
                frp = curfrp->fr_next;
            else
                frp = curfrp->fr_prev;
            while (frp != NULL && take != 0) {
                w = frame_minwidth (frp, NULL);
                if (room_reserved > 0 && frp->fr_win != NULL && frp->fr_win->w_p_wfw) {
                    if (room_reserved >= frp->fr_width)
                        room_reserved -= frp->fr_width;
                    else {
                        if (frp->fr_width - room_reserved > take)
                            room_reserved = frp->fr_width - take;
                        take -= frp->fr_width - room_reserved;
                        frame_new_width (frp, room_reserved, FALSE, FALSE);
                        room_reserved = 0;
                    }
                }
                else {
                    if (frp->fr_width - take < w) {
                        take -= frp->fr_width - w;
                        frame_new_width (frp, w, FALSE, FALSE);
                    }
                    else {
                        frame_new_width (frp, frp -> fr_width - take, FALSE, FALSE);
                        take = 0;
                    }
                }
                if (run == 0)
                    frp = frp->fr_next;
                else
                    frp = frp->fr_prev;
            }
        }
    }
}

static int frame_minwidth (frame_T *topfrp, win_T *next_curwin) {
    frame_T *frp;
    int m, n;
    if (topfrp->fr_win != NULL) {
        if (topfrp->fr_win == next_curwin)
            m = p_wiw + topfrp->fr_win->w_vsep_width;
        else {
            m = p_wmw + topfrp->fr_win->w_vsep_width;
            if (p_wmw == 0 && topfrp->fr_win == curwin && next_curwin == NULL)
                ++m;
        }
    }
    else if (topfrp->fr_layout == FR_COL) {
        m = 0;
        for (frp = topfrp->fr_child; frp != NULL; frp = frp->fr_next) {
            n = frame_minwidth (frp, next_curwin);
            if (n > m)
                m = n;
        }
    }
    else {
        m = 0;
        for (frp = topfrp->fr_child; frp != NULL; frp = frp->fr_next)
            m += frame_minwidth (frp, next_curwin);
    }
    return m;
}

static void frame_new_width (frame_T *topfrp, int width, int leftfirst, int wfw) {
    frame_T *frp;
    int extra_cols;
    int w;
    win_T *wp;
    if (topfrp->fr_layout == FR_LEAF) {
        wp = topfrp->fr_win;
        for (frp = topfrp; frp->fr_parent != NULL; frp = frp->fr_parent)
            if (frp->fr_parent->fr_layout == FR_ROW && frp->fr_next != NULL)
                break;
        if (frp->fr_parent == NULL)
            wp->w_vsep_width = 0;
        win_new_width (wp, width - wp -> w_vsep_width);
    }
    else if (topfrp->fr_layout == FR_COL) {
        do {
            for (frp = topfrp->fr_child; frp != NULL; frp = frp->fr_next) {
                frame_new_width (frp, width, leftfirst, wfw);
                if (frp->fr_width > width) {
                    width = frp->fr_width;
                    break;
                }
            }
        }
        while (frp != NULL);
    }
    else {
        frp = topfrp->fr_child;
        if (wfw)
            while (frame_fixed_width (frp)) {
                frp = frp->fr_next;
                if (frp == NULL)
                    return;
            }
        if (!leftfirst) {
            while (frp->fr_next != NULL)
                frp = frp->fr_next;
            if (wfw)
                while (frame_fixed_width (frp))
                    frp = frp->fr_prev;
        }
        extra_cols = width - topfrp->fr_width;
        if (extra_cols < 0) {
            while (frp != NULL) {
                w = frame_minwidth (frp, NULL);
                if (frp->fr_width + extra_cols < w) {
                    extra_cols += frp->fr_width - w;
                    frame_new_width (frp, w, leftfirst, wfw);
                }
                else {
                    frame_new_width (frp, frp -> fr_width + extra_cols, leftfirst, wfw);
                    break;
                }
                if (leftfirst) {
                    do
                        frp = frp->fr_next;
                    while (wfw && frp != NULL && frame_fixed_width (frp));
                }
                else {
                    do
                        frp = frp->fr_prev;
                    while (wfw && frp != NULL && frame_fixed_width (frp));
                }
                if (frp == NULL)
                    width -= extra_cols;
            }
        }
        else if (extra_cols > 0) {
            frame_new_width (frp, frp -> fr_width + extra_cols, leftfirst, wfw);
        }
    }
    topfrp->fr_width = width;
}

void win_new_width (win_T *wp, int width) {
    int resized = wp->w_width != width;
    wp->w_width = width;
    wp->w_lines_valid = 0;
    changed_line_abv_curs_win (wp);
    invalidate_botline_win (wp);
    if (wp == curwin) {
        update_topline ();
        curs_columns (TRUE);
    }
    redraw_win_later (wp, resized && gui.in_use ? CLEAR : NOT_VALID);
    wp->w_redr_status = TRUE;
}

static int frame_fixed_width (frame_T *frp) {
    if (frp->fr_win != NULL)
        return frp->fr_win->w_p_wfw;
    if (frp->fr_layout == FR_COL) {
        for (frp = frp->fr_child; frp != NULL; frp = frp->fr_next)
            if (frame_fixed_width (frp))
                return TRUE;
        return FALSE;
    }
    for (frp = frp->fr_child; frp != NULL; frp = frp->fr_next)
        if (!frame_fixed_width (frp))
            return FALSE;
    return TRUE;
}

void last_status (int morewin) {
    last_status_rec (topframe, (p_ls == 2 || (p_ls == 1 && (morewin || ! ONE_WINDOW))));
}

static void last_status_rec (frame_T *fr, int statusline) {
    frame_T *fp;
    win_T *wp;
    if (fr->fr_layout == FR_LEAF) {
        wp = fr->fr_win;
        if (wp->w_status_height != 0 && !statusline) {
            win_new_height (wp, wp -> w_height + 1);
            wp->w_status_height = 0;
            comp_col ();
        }
        else if (wp->w_status_height == 0 && statusline) {
            fp = fr;
            while (fp->fr_height <= frame_minheight (fp, NULL)) {
                if (fp == topframe) {
                    EMSG (_ (e_noroom));
                    return;
                }
                if (fp->fr_parent->fr_layout == FR_COL && fp->fr_prev != NULL)
                    fp = fp->fr_prev;
                else
                    fp = fp->fr_parent;
            }
            wp->w_status_height = 1;
            if (fp != fr) {
                frame_new_height (fp, fp -> fr_height - 1, FALSE, FALSE);
                frame_fix_height (wp);
                (void) win_comp_pos ();
            }
            else
                win_new_height (wp, wp->w_height - 1);
            comp_col ();
            redraw_all_later (SOME_VALID);
        }
    }
    else if (fr->fr_layout == FR_ROW) {
        for (fp = fr->fr_child; fp != NULL; fp = fp->fr_next)
            last_status_rec (fp, statusline);
    }
    else {
        for (fp = fr->fr_child; fp->fr_next != NULL; fp = fp->fr_next)
            ;
        last_status_rec (fp, statusline);
    }
}

static void frame_fix_height (win_T *wp) {
    wp->w_frame->fr_height = VISIBLE_HEIGHT (wp) + wp->w_status_height;
}

void shell_new_columns (void) {
    if (firstwin == NULL)
        return;
    frame_new_width (topframe, (int) Columns, FALSE, TRUE);
    if (!frame_check_width (topframe, Columns))
        frame_new_width (topframe, (int) Columns, FALSE, FALSE);
    (void) win_comp_pos ();
}

static int frame_check_width (frame_T *topfrp, int width) {
    frame_T *frp;
    if (topfrp->fr_width != width)
        return FALSE;
    if (topfrp->fr_layout == FR_COL)
        for (frp = topfrp->fr_child; frp != NULL; frp = frp->fr_next)
            if (frp->fr_width != width)
                return FALSE;
    return TRUE;
}

void win_equal (win_T *next_curwin, int current, int dir) {
    if (dir == 0)
        dir = *p_ead;
    win_equal_rec (next_curwin == NULL ? curwin : next_curwin, current, topframe, dir, 0, tabline_height (), (int) Columns, topframe -> fr_height);
}

static void win_equal_rec (win_T *next_curwin, int current, frame_T *topfr, int dir, int col, int row, int width, int height) {
    int n, m;
    int extra_sep = 0;
    int wincount, totwincount = 0;
    frame_T *fr;
    int next_curwin_size = 0;
    int room = 0;
    int new_size;
    int has_next_curwin = 0;
    int hnc;
    if (topfr->fr_layout == FR_LEAF) {
        if (topfr->fr_height != height || topfr->fr_win->w_winrow != row || topfr->fr_width != width || topfr->fr_win->w_wincol != col) {
            topfr->fr_win->w_winrow = row;
            frame_new_height (topfr, height, FALSE, FALSE);
            topfr->fr_win->w_wincol = col;
            frame_new_width (topfr, width, FALSE, FALSE);
            redraw_all_later (CLEAR);
        }
    }
    else if (topfr->fr_layout == FR_ROW) {
        topfr->fr_width = width;
        topfr->fr_height = height;
        if (dir != 'v') {
            n = frame_minwidth (topfr, NOWIN);
            if (col + width == Columns)
                extra_sep = 1;
            else
                extra_sep = 0;
            totwincount = (n + extra_sep) / (p_wmw + 1);
            has_next_curwin = frame_has_win (topfr, next_curwin);
            m = frame_minwidth (topfr, next_curwin);
            room = width - m;
            if (room < 0) {
                next_curwin_size = p_wiw + room;
                room = 0;
            }
            else {
                next_curwin_size = -1;
                for (fr = topfr->fr_child; fr != NULL; fr = fr->fr_next) {
                    if (frame_fixed_width (fr)) {
                        n = frame_minwidth (fr, NOWIN);
                        new_size = fr->fr_width;
                        if (frame_has_win (fr, next_curwin)) {
                            room += p_wiw - p_wmw;
                            next_curwin_size = 0;
                            if (new_size < p_wiw)
                                new_size = p_wiw;
                        }
                        else
                            totwincount -= (n + (fr->fr_next == NULL ? extra_sep : 0)) / (p_wmw + 1);
                        room -= new_size - n;
                        if (room < 0) {
                            new_size += room;
                            room = 0;
                        }
                        fr->fr_newwidth = new_size;
                    }
                }
                if (next_curwin_size == -1) {
                    if (!has_next_curwin)
                        next_curwin_size = 0;
                    else if (totwincount > 1 && (room + (totwincount - 2)) / (totwincount - 1) > p_wiw) {
                        next_curwin_size = (room + p_wiw + (totwincount - 1) * p_wmw + (totwincount - 1)) / totwincount;
                        room -= next_curwin_size - p_wiw;
                    }
                    else
                        next_curwin_size = p_wiw;
                }
            }
            if (has_next_curwin)
                --totwincount;
        }
        for (fr = topfr->fr_child; fr != NULL; fr = fr->fr_next) {
            n = m = 0;
            wincount = 1;
            if (fr->fr_next == NULL)
                new_size = width;
            else if (dir == 'v')
                new_size = fr->fr_width;
            else if (frame_fixed_width (fr)) {
                new_size = fr->fr_newwidth;
                wincount = 0;
            }
            else {
                n = frame_minwidth (fr, NOWIN);
                wincount = (n + (fr->fr_next == NULL ? extra_sep : 0)) / (p_wmw + 1);
                m = frame_minwidth (fr, next_curwin);
                if (has_next_curwin)
                    hnc = frame_has_win (fr, next_curwin);
                else
                    hnc = FALSE;
                if (hnc)
                    --wincount;
                if (totwincount == 0)
                    new_size = room;
                else
                    new_size = (wincount * room + ((unsigned ) totwincount >> 1)) / totwincount;
                if (hnc) {
                    next_curwin_size -= p_wiw - (m - n);
                    new_size += next_curwin_size;
                    room -= new_size - next_curwin_size;
                }
                else
                    room -= new_size;
                new_size += n;
            }
            if (!current || dir != 'v' || topfr->fr_parent != NULL || (new_size != fr->fr_width) || frame_has_win (fr, next_curwin))
                win_equal_rec (next_curwin, current, fr, dir, col, row, new_size, height);
            col += new_size;
            width -= new_size;
            totwincount -= wincount;
        }
    }
    else {
        topfr->fr_width = width;
        topfr->fr_height = height;
        if (dir != 'h') {
            n = frame_minheight (topfr, NOWIN);
            if (row + height == cmdline_row && p_ls == 0)
                extra_sep = 1;
            else
                extra_sep = 0;
            totwincount = (n + extra_sep) / (p_wmh + 1);
            has_next_curwin = frame_has_win (topfr, next_curwin);
            m = frame_minheight (topfr, next_curwin);
            room = height - m;
            if (room < 0) {
                next_curwin_size = p_wh + room;
                room = 0;
            }
            else {
                next_curwin_size = -1;
                for (fr = topfr->fr_child; fr != NULL; fr = fr->fr_next) {
                    if (frame_fixed_height (fr)) {
                        n = frame_minheight (fr, NOWIN);
                        new_size = fr->fr_height;
                        if (frame_has_win (fr, next_curwin)) {
                            room += p_wh - p_wmh;
                            next_curwin_size = 0;
                            if (new_size < p_wh)
                                new_size = p_wh;
                        }
                        else
                            totwincount -= (n + (fr->fr_next == NULL ? extra_sep : 0)) / (p_wmh + 1);
                        room -= new_size - n;
                        if (room < 0) {
                            new_size += room;
                            room = 0;
                        }
                        fr->fr_newheight = new_size;
                    }
                }
                if (next_curwin_size == -1) {
                    if (!has_next_curwin)
                        next_curwin_size = 0;
                    else if (totwincount > 1 && (room + (totwincount - 2)) / (totwincount - 1) > p_wh) {
                        next_curwin_size = (room + p_wh + (totwincount - 1) * p_wmh + (totwincount - 1)) / totwincount;
                        room -= next_curwin_size - p_wh;
                    }
                    else
                        next_curwin_size = p_wh;
                }
            }
            if (has_next_curwin)
                --totwincount;
        }
        for (fr = topfr->fr_child; fr != NULL; fr = fr->fr_next) {
            n = m = 0;
            wincount = 1;
            if (fr->fr_next == NULL)
                new_size = height;
            else if (dir == 'h')
                new_size = fr->fr_height;
            else if (frame_fixed_height (fr)) {
                new_size = fr->fr_newheight;
                wincount = 0;
            }
            else {
                n = frame_minheight (fr, NOWIN);
                wincount = (n + (fr->fr_next == NULL ? extra_sep : 0)) / (p_wmh + 1);
                m = frame_minheight (fr, next_curwin);
                if (has_next_curwin)
                    hnc = frame_has_win (fr, next_curwin);
                else
                    hnc = FALSE;
                if (hnc)
                    --wincount;
                if (totwincount == 0)
                    new_size = room;
                else
                    new_size = (wincount * room + ((unsigned ) totwincount >> 1)) / totwincount;
                if (hnc) {
                    next_curwin_size -= p_wh - (m - n);
                    new_size += next_curwin_size;
                    room -= new_size - next_curwin_size;
                }
                else
                    room -= new_size;
                new_size += n;
            }
            if (!current || dir != 'h' || topfr->fr_parent != NULL || (new_size != fr->fr_height) || frame_has_win (fr, next_curwin))
                win_equal_rec (next_curwin, current, fr, dir, col, row, width, new_size);
            row += new_size;
            height -= new_size;
            totwincount -= wincount;
        }
    }
}

static int frame_has_win (frame_T *frp, win_T *wp) {
    frame_T *p;
    if (frp->fr_layout == FR_LEAF)
        return frp->fr_win == wp;
    for (p = frp->fr_child; p != NULL; p = p->fr_next)
        if (frame_has_win (p, wp))
            return TRUE;
    return FALSE;
}

static int frame_fixed_height (frame_T *frp) {
    if (frp->fr_win != NULL)
        return frp->fr_win->w_p_wfh;
    if (frp->fr_layout == FR_ROW) {
        for (frp = frp->fr_child; frp != NULL; frp = frp->fr_next)
            if (frame_fixed_height (frp))
                return TRUE;
        return FALSE;
    }
    for (frp = frp->fr_child; frp != NULL; frp = frp->fr_next)
        if (!frame_fixed_height (frp))
            return FALSE;
    return TRUE;
}

int win_hasvertsplit (void) {
    frame_T *fr;
    if (topframe->fr_layout == FR_ROW)
        return TRUE;
    if (topframe->fr_layout == FR_COL)
        for (fr = topframe->fr_child; fr != NULL; fr = fr->fr_next)
            if (fr->fr_layout == FR_ROW)
                return TRUE;
    return FALSE;
}

void win_enter (win_T *wp, int undo_sync) {
    win_enter_ext (wp, undo_sync, FALSE, FALSE, TRUE, TRUE);
}

int one_window (void) {
    win_T *wp;
    int seen_one = FALSE;
    FOR_ALL_WINDOWS (wp) {
        if (wp != aucmd_win) {
            if (seen_one)
                return FALSE;
            seen_one = TRUE;
        }
    }
    return TRUE;
}

void win_alloc_aucmd_win (void) {
    aucmd_win = win_alloc (NULL, TRUE);
    if (aucmd_win != NULL) {
        win_init_some (aucmd_win, curwin);
        RESET_BINDING (aucmd_win);
        new_frame (aucmd_win);
    }
}

static win_T *win_alloc (win_T *after, int hidden) {
    win_T *new_wp;
    new_wp = (win_T *) alloc_clear ((unsigned ) sizeof (win_T));
    if (new_wp == NULL)
        return NULL;
    if (win_alloc_lines (new_wp) == FAIL) {
        vim_free (new_wp);
        return NULL;
    }
    new_wp->w_id = ++last_win_id;
    new_wp->w_vars = dict_alloc ();
    if (new_wp->w_vars == NULL) {
        win_free_lsize (new_wp);
        vim_free (new_wp);
        return NULL;
    }
    init_var_dict (new_wp -> w_vars, & new_wp -> w_winvar, VAR_SCOPE);
    block_autocmds ();
    if (!hidden)
        win_append (after, new_wp);
    new_wp->w_wincol = 0;
    new_wp->w_width = Columns;
    new_wp->w_topline = 1;
    new_wp->w_topfill = 0;
    new_wp->w_botline = 2;
    new_wp->w_cursor.lnum = 1;
    new_wp->w_scbind_pos = 1;
    new_wp->w_fraction = 0;
    new_wp->w_prev_fraction_row = -1;
    if (gui.in_use) {
        gui_create_scrollbar (& new_wp -> w_scrollbars [SBAR_LEFT], SBAR_LEFT, new_wp);
        gui_create_scrollbar (& new_wp -> w_scrollbars [SBAR_RIGHT], SBAR_RIGHT, new_wp);
    }
    foldInitWin (new_wp);
    unblock_autocmds ();
    new_wp->w_match_head = NULL;
    new_wp->w_next_match_id = 4;
    return new_wp;
}

int win_alloc_lines (win_T *wp) {
    wp->w_lines_valid = 0;
    wp->w_lines = (wline_T *) alloc_clear ((unsigned ) (Rows * sizeof (wline_T)));
    if (wp->w_lines == NULL)
        return FAIL;
    return OK;
}

void win_free_lsize (win_T *wp) {
    if (wp != NULL)
        VIM_CLEAR (wp->w_lines);
}

void win_append (win_T *after, win_T *wp) {
    win_T *before;
    if (after == NULL)
        before = firstwin;
    else
        before = after->w_next;
    wp->w_next = before;
    wp->w_prev = after;
    if (after == NULL)
        firstwin = wp;
    else
        after->w_next = wp;
    if (before == NULL)
        lastwin = wp;
    else
        before->w_prev = wp;
}

static void win_init_some (win_T *newp, win_T *oldp) {
    newp->w_alist = oldp->w_alist;
    ++newp->w_alist->al_refcount;
    newp->w_arg_idx = oldp->w_arg_idx;
    win_copy_options (oldp, newp);
}

static void new_frame (win_T *wp) {
    frame_T *frp = (frame_T *) alloc_clear ((unsigned ) sizeof (frame_T));
    wp->w_frame = frp;
    if (frp != NULL) {
        frp->fr_layout = FR_LEAF;
        frp->fr_win = wp;
    }
}

void win_init_empty (win_T *wp) {
    redraw_win_later (wp, NOT_VALID);
    wp->w_lines_valid = 0;
    wp->w_cursor.lnum = 1;
    wp->w_curswant = wp->w_cursor.col = 0;
    wp->w_cursor.coladd = 0;
    wp->w_pcmark.lnum = 1;
    wp->w_pcmark.col = 0;
    wp->w_prev_pcmark.lnum = 0;
    wp->w_prev_pcmark.col = 0;
    wp->w_topline = 1;
    wp->w_topfill = 0;
    wp->w_botline = 2;
    if (wp->w_p_rl)
        wp->w_farsi = W_CONV + W_R_L;
    else
        wp->w_farsi = W_CONV;
    wp->w_s = &wp->w_buffer->b_s;
}

void make_snapshot (int idx) {
    clear_snapshot (curtab, idx);
    make_snapshot_rec (topframe, & curtab -> tp_snapshot [idx]);
}

static void clear_snapshot (tabpage_T *tp, int idx) {
    clear_snapshot_rec (tp -> tp_snapshot [idx]);
    tp->tp_snapshot[idx] = NULL;
}

static void clear_snapshot_rec (frame_T *fr) {
    if (fr != NULL) {
        clear_snapshot_rec (fr -> fr_next);
        clear_snapshot_rec (fr -> fr_child);
        vim_free (fr);
    }
}

static void make_snapshot_rec (frame_T *fr, frame_T **frp) {
    *frp = (frame_T *) alloc_clear ((unsigned ) sizeof (frame_T));
    if (*frp == NULL)
        return;
    (*frp)->fr_layout = fr->fr_layout;
    (*frp)->fr_width = fr->fr_width;
    (*frp)->fr_height = fr->fr_height;
    if (fr->fr_next != NULL)
        make_snapshot_rec (fr->fr_next, &((*frp)->fr_next));
    if (fr->fr_child != NULL)
        make_snapshot_rec (fr->fr_child, &((*frp)->fr_child));
    if (fr->fr_layout == FR_LEAF && fr->fr_win == curwin)
        (*frp)->fr_win = curwin;
}

int win_split_ins (int size, int flags, win_T *new_wp, int dir) {
    win_T *wp = new_wp;
    win_T *oldwin;
    int new_size = size;
    int i;
    int need_status = 0;
    int do_equal = FALSE;
    int needed;
    int available;
    int oldwin_height = 0;
    int layout;
    frame_T *frp, *curfrp, *frp2, *prevfrp;
    int before;
    int minheight;
    int wmh1;
    if (flags & WSP_TOP)
        oldwin = firstwin;
    else if (flags & WSP_BOT)
        oldwin = lastwin;
    else
        oldwin = curwin;
    if (ONE_WINDOW && p_ls == 1 && oldwin->w_status_height == 0) {
        if (VISIBLE_HEIGHT (oldwin) <= p_wmh && new_wp == NULL) {
            EMSG (_ (e_noroom));
            return FAIL;
        }
        need_status = STATUS_HEIGHT;
    }
    if (gui.in_use)
        out_flush ();
    if (flags & WSP_VERT) {
        int wmw1;
        int minwidth;
        layout = FR_ROW;
        wmw1 = (p_wmw == 0 ? 1 : p_wmw);
        needed = wmw1 + 1;
        if (flags & WSP_ROOM)
            needed += p_wiw - wmw1;
        if (flags & (WSP_BOT | WSP_TOP)) {
            minwidth = frame_minwidth (topframe, NOWIN);
            available = topframe->fr_width;
            needed += minwidth;
        }
        else if (p_ea) {
            minwidth = frame_minwidth (oldwin->w_frame, NOWIN);
            prevfrp = oldwin->w_frame;
            for (frp = oldwin->w_frame->fr_parent; frp != NULL; frp = frp->fr_parent) {
                if (frp->fr_layout == FR_ROW)
                    for (frp2 = frp->fr_child; frp2 != NULL; frp2 = frp2->fr_next)
                        if (frp2 != prevfrp)
                            minwidth += frame_minwidth (frp2, NOWIN);
                prevfrp = frp;
            }
            available = topframe->fr_width;
            needed += minwidth;
        }
        else {
            minwidth = frame_minwidth (oldwin->w_frame, NOWIN);
            available = oldwin->w_frame->fr_width;
            needed += minwidth;
        }
        if (available < needed && new_wp == NULL) {
            EMSG (_ (e_noroom));
            return FAIL;
        }
        if (new_size == 0)
            new_size = oldwin->w_width / 2;
        if (new_size > available - minwidth - 1)
            new_size = available - minwidth - 1;
        if (new_size < wmw1)
            new_size = wmw1;
        if (oldwin->w_width - new_size - 1 < p_wmw)
            do_equal = TRUE;
        if (oldwin->w_p_wfw)
            win_setwidth_win (oldwin->w_width + new_size + 1, oldwin);
        if (!do_equal && p_ea && size == 0 && *p_ead != 'v' && oldwin->w_frame->fr_parent != NULL) {
            frp = oldwin->w_frame->fr_parent->fr_child;
            while (frp != NULL) {
                if (frp->fr_win != oldwin && frp->fr_win != NULL && (frp->fr_win->w_width > new_size || frp->fr_win->w_width > oldwin->w_width - new_size - 1)) {
                    do_equal = TRUE;
                    break;
                }
                frp = frp->fr_next;
            }
        }
    }
    else {
        layout = FR_COL;
        wmh1 = (p_wmh == 0 ? 1 : p_wmh) + WINBAR_HEIGHT (curwin);
        needed = wmh1 + STATUS_HEIGHT;
        if (flags & WSP_ROOM)
            needed += p_wh - wmh1;
        if (flags & (WSP_BOT | WSP_TOP)) {
            minheight = frame_minheight (topframe, NOWIN) + need_status;
            available = topframe->fr_height;
            needed += minheight;
        }
        else if (p_ea) {
            minheight = frame_minheight (oldwin->w_frame, NOWIN) + need_status;
            prevfrp = oldwin->w_frame;
            for (frp = oldwin->w_frame->fr_parent; frp != NULL; frp = frp->fr_parent) {
                if (frp->fr_layout == FR_COL)
                    for (frp2 = frp->fr_child; frp2 != NULL; frp2 = frp2->fr_next)
                        if (frp2 != prevfrp)
                            minheight += frame_minheight (frp2, NOWIN);
                prevfrp = frp;
            }
            available = topframe->fr_height;
            needed += minheight;
        }
        else {
            minheight = frame_minheight (oldwin->w_frame, NOWIN) + need_status;
            available = oldwin->w_frame->fr_height;
            needed += minheight;
        }
        if (available < needed && new_wp == NULL) {
            EMSG (_ (e_noroom));
            return FAIL;
        }
        oldwin_height = oldwin->w_height;
        if (need_status) {
            oldwin->w_status_height = STATUS_HEIGHT;
            oldwin_height -= STATUS_HEIGHT;
        }
        if (new_size == 0)
            new_size = oldwin_height / 2;
        if (new_size > available - minheight - STATUS_HEIGHT)
            new_size = available - minheight - STATUS_HEIGHT;
        if (new_size < wmh1)
            new_size = wmh1;
        if (oldwin_height - new_size - STATUS_HEIGHT < p_wmh)
            do_equal = TRUE;
        if (oldwin->w_p_wfh) {
            win_setheight_win (oldwin -> w_height + new_size + STATUS_HEIGHT, oldwin);
            oldwin_height = oldwin->w_height;
            if (need_status)
                oldwin_height -= STATUS_HEIGHT;
        }
        if (!do_equal && p_ea && size == 0 && *p_ead != 'h' && oldwin->w_frame->fr_parent != NULL) {
            frp = oldwin->w_frame->fr_parent->fr_child;
            while (frp != NULL) {
                if (frp->fr_win != oldwin && frp->fr_win != NULL && (frp->fr_win->w_height > new_size || frp->fr_win->w_height > oldwin_height - new_size - STATUS_HEIGHT)) {
                    do_equal = TRUE;
                    break;
                }
                frp = frp->fr_next;
            }
        }
    }
    if ((flags & WSP_TOP) == 0 && ((flags & WSP_BOT) || (flags & WSP_BELOW) || (!(flags & WSP_ABOVE) && ((flags & WSP_VERT) ? p_spr : p_sb)))) {
        if (new_wp == NULL)
            wp = win_alloc (oldwin, FALSE);
        else
            win_append (oldwin, wp);
    }
    else {
        if (new_wp == NULL)
            wp = win_alloc (oldwin->w_prev, FALSE);
        else
            win_append (oldwin->w_prev, wp);
    }
    if (new_wp == NULL) {
        if (wp == NULL)
            return FAIL;
        new_frame (wp);
        if (wp->w_frame == NULL) {
            win_free (wp, NULL);
            return FAIL;
        }
        win_init (wp, curwin, flags);
    }
    if (flags & (WSP_TOP | WSP_BOT)) {
        if ((topframe->fr_layout == FR_COL && (flags & WSP_VERT) == 0) || (topframe->fr_layout == FR_ROW && (flags & WSP_VERT) != 0)) {
            curfrp = topframe->fr_child;
            if (flags & WSP_BOT)
                while (curfrp->fr_next != NULL)
                    curfrp = curfrp->fr_next;
        }
        else
            curfrp = topframe;
        before = (flags & WSP_TOP);
    }
    else {
        curfrp = oldwin->w_frame;
        if (flags & WSP_BELOW)
            before = FALSE;
        else if (flags & WSP_ABOVE)
            before = TRUE;
        else if (flags & WSP_VERT)
            before = !p_spr;
        else
            before = !p_sb;
    }
    if (curfrp->fr_parent == NULL || curfrp->fr_parent->fr_layout != layout) {
        frp = (frame_T *) alloc_clear ((unsigned ) sizeof (frame_T));
        *frp = *curfrp;
        curfrp->fr_layout = layout;
        frp->fr_parent = curfrp;
        frp->fr_next = NULL;
        frp->fr_prev = NULL;
        curfrp->fr_child = frp;
        curfrp->fr_win = NULL;
        curfrp = frp;
        if (frp->fr_win != NULL)
            oldwin->w_frame = frp;
        else
            for (frp = frp->fr_child; frp != NULL; frp = frp->fr_next)
                frp->fr_parent = curfrp;
    }
    if (new_wp == NULL)
        frp = wp->w_frame;
    else
        frp = new_wp->w_frame;
    frp->fr_parent = curfrp->fr_parent;
    if (before)
        frame_insert (curfrp, frp);
    else
        frame_append (curfrp, frp);
    set_fraction (oldwin);
    wp->w_fraction = oldwin->w_fraction;
    if (flags & WSP_VERT) {
        wp->w_p_scr = curwin->w_p_scr;
        if (need_status) {
            win_new_height (oldwin, oldwin -> w_height - 1);
            oldwin->w_status_height = need_status;
        }
        if (flags & (WSP_TOP | WSP_BOT)) {
            wp->w_winrow = tabline_height ();
            win_new_height (wp, curfrp -> fr_height - (p_ls > 0) - WINBAR_HEIGHT (wp));
            wp->w_status_height = (p_ls > 0);
        }
        else {
            wp->w_winrow = oldwin->w_winrow;
            win_new_height (wp, VISIBLE_HEIGHT (oldwin));
            wp->w_status_height = oldwin->w_status_height;
        }
        frp->fr_height = curfrp->fr_height;
        win_new_width (wp, new_size);
        if (before)
            wp->w_vsep_width = 1;
        else {
            wp->w_vsep_width = oldwin->w_vsep_width;
            oldwin->w_vsep_width = 1;
        }
        if (flags & (WSP_TOP | WSP_BOT)) {
            if (flags & WSP_BOT)
                frame_add_vsep (curfrp);
            frame_new_width (curfrp, curfrp -> fr_width - (new_size + ((flags & WSP_TOP) != 0)), flags & WSP_TOP, FALSE);
        }
        else
            win_new_width (oldwin, oldwin->w_width - (new_size + 1));
        if (before) {
            wp->w_wincol = oldwin->w_wincol;
            oldwin->w_wincol += new_size + 1;
        }
        else
            wp->w_wincol = oldwin->w_wincol + oldwin->w_width + 1;
        frame_fix_width (oldwin);
        frame_fix_width (wp);
    }
    else {
        if (flags & (WSP_TOP | WSP_BOT)) {
            wp->w_wincol = 0;
            win_new_width (wp, Columns);
            wp->w_vsep_width = 0;
        }
        else {
            wp->w_wincol = oldwin->w_wincol;
            win_new_width (wp, oldwin -> w_width);
            wp->w_vsep_width = oldwin->w_vsep_width;
        }
        frp->fr_width = curfrp->fr_width;
        win_new_height (wp, new_size);
        if (flags & (WSP_TOP | WSP_BOT)) {
            int new_fr_height = curfrp->fr_height - new_size + WINBAR_HEIGHT (wp);
            if (!((flags & WSP_BOT) && p_ls == 0))
                new_fr_height -= STATUS_HEIGHT;
            frame_new_height (curfrp, new_fr_height, flags & WSP_TOP, FALSE);
        }
        else
            win_new_height (oldwin, oldwin_height -(new_size + STATUS_HEIGHT));
        if (before) {
            wp->w_winrow = oldwin->w_winrow;
            wp->w_status_height = STATUS_HEIGHT;
            oldwin->w_winrow += wp->w_height + STATUS_HEIGHT;
        }
        else {
            wp->w_winrow = oldwin->w_winrow + VISIBLE_HEIGHT (oldwin) + STATUS_HEIGHT;
            wp->w_status_height = oldwin->w_status_height;
            if (!(flags & WSP_BOT))
                oldwin->w_status_height = STATUS_HEIGHT;
        }
        if (flags & WSP_BOT)
            frame_add_statusline (curfrp);
        frame_fix_height (wp);
        frame_fix_height (oldwin);
    }
    if (flags & (WSP_TOP | WSP_BOT))
        (void) win_comp_pos ();
    redraw_win_later (wp, NOT_VALID);
    wp->w_redr_status = TRUE;
    redraw_win_later (oldwin, gui.in_use ? CLEAR : NOT_VALID);
    oldwin->w_redr_status = TRUE;
    if (need_status) {
        msg_row = Rows - 1;
        msg_col = sc_col;
        msg_clr_eos_force ();
        comp_col ();
        msg_row = Rows - 1;
        msg_col = 0;
    }
    if (do_equal || dir != 0)
        win_equal (wp, TRUE, (flags & WSP_VERT) ? (dir == 'v' ? 'b' : 'h') : dir == 'h' ? 'b' : 'v');
    if (flags & WSP_VERT) {
        i = p_wiw;
        if (size != 0)
            p_wiw = size;
        if (gui.in_use)
            gui_init_which_components (NULL);
    }
    else {
        i = p_wh;
        if (size != 0)
            p_wh = size;
    }
    wp->w_changelistidx = oldwin->w_changelistidx;
    win_enter_ext (wp, FALSE, FALSE, TRUE, TRUE, TRUE);
    if (flags & WSP_VERT)
        p_wiw = i;
    else
        p_wh = i;
    return OK;
}

static void win_free (win_T *wp, tabpage_T *tp) {
    int i;
    buf_T *buf;
    wininfo_T *wip;
    clearFolding (wp);
    alist_unlink (wp -> w_alist);
    block_autocmds ();
    clear_winopt (& wp -> w_onebuf_opt);
    clear_winopt (& wp -> w_allbuf_opt);
    vars_clear (& wp -> w_vars -> dv_hashtab);
    hash_init (& wp -> w_vars -> dv_hashtab);
    unref_var_dict (wp -> w_vars);
    {
        tabpage_T *ttp;
        if (prevwin == wp)
            prevwin = NULL;
        FOR_ALL_TABPAGES (ttp)
            if (ttp->tp_prevwin == wp)
                ttp->tp_prevwin = NULL;
    }
    win_free_lsize (wp);
    for (i = 0; i < wp->w_tagstacklen; ++i)
        vim_free (wp->w_tagstack[i].tagname);
    vim_free (wp -> w_localdir);
    FOR_ALL_BUFFERS (buf)
        for (wip = buf->b_wininfo; wip != NULL; wip = wip->wi_next)
            if (wip->wi_win == wp)
                wip->wi_win = NULL;
    clear_matches (wp);
    free_jumplist (wp);
    qf_free_all (wp);
    if (gui.in_use) {
        gui_mch_destroy_scrollbar (& wp -> w_scrollbars [SBAR_LEFT]);
        gui_mch_destroy_scrollbar (& wp -> w_scrollbars [SBAR_RIGHT]);
    }
    remove_winbar (wp);
    vim_free (wp -> w_p_cc_cols);
    if (wp != aucmd_win)
        win_remove (wp, tp);
    if (autocmd_busy) {
        wp->w_next = au_pending_free_win;
        au_pending_free_win = wp;
    }
    else
        vim_free (wp);
    unblock_autocmds ();
}

void clear_matches (win_T *wp) {
    matchitem_T *m;
    while (wp->w_match_head != NULL) {
        m = wp->w_match_head->next;
        vim_regfree (wp -> w_match_head -> match.regprog);
        vim_free (wp -> w_match_head -> pattern);
        vim_free (wp -> w_match_head);
        wp->w_match_head = m;
    }
    redraw_later (SOME_VALID);
}

void win_remove (win_T *wp, tabpage_T *tp) {
    if (wp->w_prev != NULL)
        wp->w_prev->w_next = wp->w_next;
    else if (tp == NULL)
        firstwin = curtab->tp_firstwin = wp->w_next;
    else
        tp->tp_firstwin = wp->w_next;
    if (wp->w_next != NULL)
        wp->w_next->w_prev = wp->w_prev;
    else if (tp == NULL)
        lastwin = curtab->tp_lastwin = wp->w_prev;
    else
        tp->tp_lastwin = wp->w_prev;
}

static void win_init (win_T *newp, win_T *oldp, int flags) {
    int i;
    newp->w_buffer = oldp->w_buffer;
    newp->w_s = &(oldp->w_buffer->b_s);
    oldp->w_buffer->b_nwindows++;
    newp->w_cursor = oldp->w_cursor;
    newp->w_valid = 0;
    newp->w_curswant = oldp->w_curswant;
    newp->w_set_curswant = oldp->w_set_curswant;
    newp->w_topline = oldp->w_topline;
    newp->w_topfill = oldp->w_topfill;
    newp->w_leftcol = oldp->w_leftcol;
    newp->w_pcmark = oldp->w_pcmark;
    newp->w_prev_pcmark = oldp->w_prev_pcmark;
    newp->w_alt_fnum = oldp->w_alt_fnum;
    newp->w_wrow = oldp->w_wrow;
    newp->w_fraction = oldp->w_fraction;
    newp->w_prev_fraction_row = oldp->w_prev_fraction_row;
    copy_jumplist (oldp, newp);
    if (flags & WSP_NEWLOC) {
        newp->w_llist = NULL;
        newp->w_llist_ref = NULL;
    }
    else
        copy_loclist (oldp, newp);
    newp->w_localdir = (oldp->w_localdir == NULL) ? NULL : vim_strsave (oldp->w_localdir);
    for (i = 0; i < oldp->w_tagstacklen; i++) {
        newp->w_tagstack[i] = oldp->w_tagstack[i];
        if (newp->w_tagstack[i].tagname != NULL)
            newp->w_tagstack[i].tagname = vim_strsave (newp->w_tagstack[i].tagname);
    }
    newp->w_tagstackidx = oldp->w_tagstackidx;
    newp->w_tagstacklen = oldp->w_tagstacklen;
    copyFoldingState (oldp, newp);
    win_init_some (newp, oldp);
    check_colorcolumn (newp);
}

static void frame_insert (frame_T *before, frame_T *frp) {
    frp->fr_next = before;
    frp->fr_prev = before->fr_prev;
    before->fr_prev = frp;
    if (frp->fr_prev != NULL)
        frp->fr_prev->fr_next = frp;
    else
        frp->fr_parent->fr_child = frp;
}

static void frame_append (frame_T *after, frame_T *frp) {
    frp->fr_next = after->fr_next;
    after->fr_next = frp;
    if (frp->fr_next != NULL)
        frp->fr_next->fr_prev = frp;
    frp->fr_prev = after;
}

void set_fraction (win_T *wp) {
    if (wp->w_height > 1)
        wp->w_fraction = ((long ) wp->w_wrow * FRACTION_MULT + wp->w_height / 2) / (long ) wp->w_height;
}

static void frame_add_vsep (frame_T *frp) {
    win_T *wp;
    if (frp->fr_layout == FR_LEAF) {
        wp = frp->fr_win;
        if (wp->w_vsep_width == 0) {
            if (wp->w_width > 0)
                --wp->w_width;
            wp->w_vsep_width = 1;
        }
    }
    else if (frp->fr_layout == FR_COL) {
        for (frp = frp->fr_child; frp != NULL; frp = frp->fr_next)
            frame_add_vsep (frp);
    }
    else {
        frp = frp->fr_child;
        while (frp->fr_next != NULL)
            frp = frp->fr_next;
        frame_add_vsep (frp);
    }
}

static void frame_fix_width (win_T *wp) {
    wp->w_frame->fr_width = wp->w_width + wp->w_vsep_width;
}

static void frame_add_statusline (frame_T *frp) {
    win_T *wp;
    if (frp->fr_layout == FR_LEAF) {
        wp = frp->fr_win;
        if (wp->w_status_height == 0) {
            if (wp->w_height > 0)
                --wp->w_height;
            wp->w_status_height = STATUS_HEIGHT;
        }
    }
    else if (frp->fr_layout == FR_ROW) {
        for (frp = frp->fr_child; frp != NULL; frp = frp->fr_next)
            frame_add_statusline (frp);
    }
    else {
        for (frp = frp->fr_child; frp->fr_next != NULL; frp = frp->fr_next)
            ;
        frame_add_statusline (frp);
    }
}

void win_comp_scroll (win_T *wp) {
    wp->w_p_scr = ((unsigned ) wp->w_height >> 1);
    if (wp->w_p_scr == 0)
        wp->w_p_scr = 1;
}

void win_setminheight (void) {
    int room;
    int first = TRUE;
    win_T *wp;
    while (p_wmh > 0) {
        room = -p_wh;
        FOR_ALL_WINDOWS (wp)
            room += VISIBLE_HEIGHT (wp) - p_wmh;
        if (room >= 0)
            break;
        --p_wmh;
        if (first) {
            EMSG (_ (e_noroom));
            first = FALSE;
        }
    }
}

void command_height (void) {
    int h;
    frame_T *frp;
    int old_p_ch = curtab->tp_ch_used;
    curtab->tp_ch_used = p_ch;
    frp = lastwin->w_frame;
    while (frp->fr_width != Columns && frp->fr_parent != NULL)
        frp = frp->fr_parent;
    while (frp->fr_prev != NULL && frp->fr_layout == FR_LEAF && frp->fr_win->w_p_wfh)
        frp = frp->fr_prev;
    if (starting != NO_SCREEN) {
        cmdline_row = Rows - p_ch;
        if (p_ch > old_p_ch) {
            while (p_ch > old_p_ch) {
                if (frp == NULL) {
                    EMSG (_ (e_noroom));
                    p_ch = old_p_ch;
                    curtab->tp_ch_used = p_ch;
                    cmdline_row = Rows - p_ch;
                    break;
                }
                h = frp->fr_height - frame_minheight (frp, NULL);
                if (h > p_ch - old_p_ch)
                    h = p_ch - old_p_ch;
                old_p_ch += h;
                frame_add_height (frp, - h);
                frp = frp->fr_prev;
            }
            (void) win_comp_pos ();
            if (full_screen)
                screen_fill ((int) (cmdline_row), (int) Rows, 0, (int) Columns, ' ', ' ', 0);
            msg_row = cmdline_row;
            redraw_cmdline = TRUE;
            return;
        }
        if (msg_row < cmdline_row)
            msg_row = cmdline_row;
        redraw_cmdline = TRUE;
    }
    frame_add_height (frp, (int) (old_p_ch - p_ch));
    if (frp != lastwin->w_frame)
        (void) win_comp_pos ();
}

static void frame_add_height (frame_T *frp, int n) {
    frame_new_height (frp, frp -> fr_height + n, FALSE, FALSE);
    for (;;) {
        frp = frp->fr_parent;
        if (frp == NULL)
            break;
        frp->fr_height += n;
    }
}

void win_goto (win_T *wp) {
    win_T *owp = curwin;
    if (text_locked ()) {
        beep_flush ();
        text_locked_msg ();
        return;
    }
    if (curbuf_locked ())
        return;
    if (wp->w_buffer != curbuf)
        reset_VIsual_and_resel ();
    else if (VIsual_active)
        wp->w_cursor = curwin->w_cursor;
    need_mouse_correct = TRUE;
    win_enter (wp, TRUE);
    if (win_valid (owp) && owp->w_p_cole > 0 && !msg_scrolled)
        update_single_line (owp, owp->w_cursor.lnum);
    if (curwin->w_p_cole > 0 && !msg_scrolled)
        need_cursor_line_redraw = TRUE;
}

win_T *winframe_remove (win_T *win, int *dirp, tabpage_T *tp) {
    frame_T *frp, *frp2, *frp3;
    frame_T *frp_close = win->w_frame;
    win_T *wp;
    if (tp == NULL ? ONE_WINDOW : tp->tp_firstwin == tp->tp_lastwin)
        return NULL;
    frp2 = win_altframe (win, tp);
    wp = frame2win (frp2);
    frame_remove (frp_close);
    if (frp_close->fr_parent->fr_layout == FR_COL) {
        if (frp2->fr_win != NULL && frp2->fr_win->w_p_wfh) {
            frp = frp_close->fr_prev;
            frp3 = frp_close->fr_next;
            while (frp != NULL || frp3 != NULL) {
                if (frp != NULL) {
                    if (frp->fr_win != NULL && !frp->fr_win->w_p_wfh) {
                        frp2 = frp;
                        wp = frp->fr_win;
                        break;
                    }
                    frp = frp->fr_prev;
                }
                if (frp3 != NULL) {
                    if (frp3->fr_win != NULL && !frp3->fr_win->w_p_wfh) {
                        frp2 = frp3;
                        wp = frp3->fr_win;
                        break;
                    }
                    frp3 = frp3->fr_next;
                }
            }
        }
        frame_new_height (frp2, frp2 -> fr_height + frp_close -> fr_height, frp2 == frp_close -> fr_next ? TRUE : FALSE, FALSE);
        *dirp = 'v';
    }
    else {
        if (frp2->fr_win != NULL && frp2->fr_win->w_p_wfw) {
            frp = frp_close->fr_prev;
            frp3 = frp_close->fr_next;
            while (frp != NULL || frp3 != NULL) {
                if (frp != NULL) {
                    if (frp->fr_win != NULL && !frp->fr_win->w_p_wfw) {
                        frp2 = frp;
                        wp = frp->fr_win;
                        break;
                    }
                    frp = frp->fr_prev;
                }
                if (frp3 != NULL) {
                    if (frp3->fr_win != NULL && !frp3->fr_win->w_p_wfw) {
                        frp2 = frp3;
                        wp = frp3->fr_win;
                        break;
                    }
                    frp3 = frp3->fr_next;
                }
            }
        }
        frame_new_width (frp2, frp2 -> fr_width + frp_close -> fr_width, frp2 == frp_close -> fr_next ? TRUE : FALSE, FALSE);
        *dirp = 'h';
    }
    if (frp2 == frp_close->fr_next) {
        int row = win->w_winrow;
        int col = win->w_wincol;
        frame_comp_pos (frp2, & row, & col);
    }
    if (frp2->fr_next == NULL && frp2->fr_prev == NULL) {
        frp2->fr_parent->fr_layout = frp2->fr_layout;
        frp2->fr_parent->fr_child = frp2->fr_child;
        for (frp = frp2->fr_child; frp != NULL; frp = frp->fr_next)
            frp->fr_parent = frp2->fr_parent;
        frp2->fr_parent->fr_win = frp2->fr_win;
        if (frp2->fr_win != NULL)
            frp2->fr_win->w_frame = frp2->fr_parent;
        frp = frp2->fr_parent;
        if (topframe->fr_child == frp2)
            topframe->fr_child = frp;
        vim_free (frp2);
        frp2 = frp->fr_parent;
        if (frp2 != NULL && frp2->fr_layout == frp->fr_layout) {
            if (frp2->fr_child == frp)
                frp2->fr_child = frp->fr_child;
            frp->fr_child->fr_prev = frp->fr_prev;
            if (frp->fr_prev != NULL)
                frp->fr_prev->fr_next = frp->fr_child;
            for (frp3 = frp->fr_child;; frp3 = frp3->fr_next) {
                frp3->fr_parent = frp2;
                if (frp3->fr_next == NULL) {
                    frp3->fr_next = frp->fr_next;
                    if (frp->fr_next != NULL)
                        frp->fr_next->fr_prev = frp3;
                    break;
                }
            }
            if (topframe->fr_child == frp)
                topframe->fr_child = frp2;
            vim_free (frp);
        }
    }
    return wp;
}

static frame_T *win_altframe (win_T *win, tabpage_T *tp) {
    frame_T *frp;
    int b;
    if (tp == NULL ? ONE_WINDOW : tp->tp_firstwin == tp->tp_lastwin)
        return alt_tabpage ()->tp_curwin->w_frame;
    frp = win->w_frame;
    if (frp->fr_parent != NULL && frp->fr_parent->fr_layout == FR_ROW)
        b = p_spr;
    else
        b = p_sb;
    if ((!b && frp->fr_next != NULL) || frp->fr_prev == NULL)
        return frp->fr_next;
    return frp->fr_prev;
}

static tabpage_T *alt_tabpage (void) {
    tabpage_T *tp;
    if (curtab->tp_next != NULL)
        return curtab->tp_next;
    for (tp = first_tabpage; tp->tp_next != curtab; tp = tp->tp_next)
        ;
    return tp;
}

static win_T *frame2win (frame_T *frp) {
    while (frp->fr_win == NULL)
        frp = frp->fr_child;
    return frp->fr_win;
}

static void frame_remove (frame_T *frp) {
    if (frp->fr_prev != NULL)
        frp->fr_prev->fr_next = frp->fr_next;
    else {
        frp->fr_parent->fr_child = frp->fr_next;
        if (topframe->fr_child == frp)
            topframe->fr_child = frp->fr_next;
    }
    if (frp->fr_next != NULL)
        frp->fr_next->fr_prev = frp->fr_prev;
}

int valid_tabpage_win (tabpage_T *tpc) {
    tabpage_T *tp;
    win_T *wp;
    FOR_ALL_TABPAGES (tp) {
        if (tp == tpc) {
            FOR_ALL_WINDOWS_IN_TAB (tp, wp) {
                if (win_valid_any_tab (wp))
                    return TRUE;
            }
            return FALSE;
        }
    }
    return FALSE;
}

void close_tabpage (tabpage_T *tab) {
    tabpage_T *ptp;
    if (tab == first_tabpage) {
        first_tabpage = tab->tp_next;
        ptp = first_tabpage;
    }
    else {
        for (ptp = first_tabpage; ptp != NULL && ptp->tp_next != tab; ptp = ptp->tp_next)
            ;
        assert (ptp != NULL);
        ptp->tp_next = tab->tp_next;
    }
    goto_tabpage_tp (ptp, FALSE, FALSE);
    free_tabpage (tab);
}

void free_tabpage (tabpage_T *tp) {
    int idx;
    diff_clear (tp);
    for (idx = 0; idx < SNAP_COUNT; ++idx)
        clear_snapshot (tp, idx);
    vars_clear (& tp -> tp_vars -> dv_hashtab);
    hash_init (& tp -> tp_vars -> dv_hashtab);
    unref_var_dict (tp -> tp_vars);
    vim_free (tp);
}

void restore_snapshot (int idx, int close_curwin) {
    win_T *wp;
    if (curtab->tp_snapshot[idx] != NULL && curtab->tp_snapshot[idx]->fr_width == topframe->fr_width && curtab->tp_snapshot[idx]->fr_height == topframe->fr_height && check_snapshot_rec (curtab->tp_snapshot[idx], topframe) == OK) {
        wp = restore_snapshot_rec (curtab->tp_snapshot[idx], topframe);
        win_comp_pos ();
        if (wp != NULL && close_curwin)
            win_goto (wp);
        redraw_all_later (CLEAR);
    }
    clear_snapshot (curtab, idx);
}

static int check_snapshot_rec (frame_T *sn, frame_T *fr) {
    if (sn->fr_layout != fr->fr_layout || (sn->fr_next == NULL) != (fr->fr_next == NULL) || (sn->fr_child == NULL) != (fr->fr_child == NULL) || (sn->fr_next != NULL && check_snapshot_rec (sn->fr_next, fr->fr_next) == FAIL) || (sn->fr_child != NULL && check_snapshot_rec (sn->fr_child, fr->fr_child) == FAIL) || (sn->fr_win != NULL && !win_valid (sn->fr_win)))
        return FAIL;
    return OK;
}

static win_T *restore_snapshot_rec (frame_T *sn, frame_T *fr) {
    win_T *wp = NULL;
    win_T *wp2;
    fr->fr_height = sn->fr_height;
    fr->fr_width = sn->fr_width;
    if (fr->fr_layout == FR_LEAF) {
        frame_new_height (fr, fr -> fr_height, FALSE, FALSE);
        frame_new_width (fr, fr -> fr_width, FALSE, FALSE);
        wp = sn->fr_win;
    }
    if (sn->fr_next != NULL) {
        wp2 = restore_snapshot_rec (sn->fr_next, fr->fr_next);
        if (wp2 != NULL)
            wp = wp2;
    }
    if (sn->fr_child != NULL) {
        wp2 = restore_snapshot_rec (sn->fr_child, fr->fr_child);
        if (wp2 != NULL)
            wp = wp2;
    }
    return wp;
}

int win_split (int size, int flags) {
    if (may_open_tabpage () == OK)
        return OK;
    flags |= cmdmod.split;
    if ((flags & WSP_TOP) && (flags & WSP_BOT)) {
        EMSG (_ ("E442: Can't split topleft and botright at the same time"));
        return FAIL;
    }
    if (flags & WSP_HELP)
        make_snapshot (SNAP_HELP_IDX);
    else
        clear_snapshot (curtab, SNAP_HELP_IDX);
    return win_split_ins (size, flags, NULL, 0);
}

int may_open_tabpage (void) {
    int n = (cmdmod.tab == 0) ? postponed_split_tab : cmdmod.tab;
    if (n != 0) {
        cmdmod.tab = 0;
        postponed_split_tab = 0;
        return win_new_tabpage (n);
    }
    return FAIL;
}

int win_new_tabpage (int after) {
    tabpage_T *tp = curtab;
    tabpage_T *newtp;
    int n;
    newtp = alloc_tabpage ();
    if (newtp == NULL)
        return FAIL;
    if (leave_tabpage (curbuf, TRUE) == FAIL) {
        vim_free (newtp);
        return FAIL;
    }
    curtab = newtp;
    if (win_alloc_firstwin (tp->tp_curwin) == OK) {
        if (after == 1) {
            newtp->tp_next = first_tabpage;
            first_tabpage = newtp;
        }
        else {
            if (after > 0) {
                n = 2;
                for (tp = first_tabpage; tp->tp_next != NULL && n < after; tp = tp->tp_next)
                    ++n;
            }
            newtp->tp_next = tp->tp_next;
            tp->tp_next = newtp;
        }
        win_init_size ();
        firstwin->w_winrow = tabline_height ();
        win_comp_scroll (curwin);
        newtp->tp_topframe = topframe;
        last_status (FALSE);
        gui_may_update_scrollbars ();
        redraw_all_later (CLEAR);
        apply_autocmds (EVENT_WINNEW, NULL, NULL, FALSE, curbuf);
        apply_autocmds (EVENT_WINENTER, NULL, NULL, FALSE, curbuf);
        apply_autocmds (EVENT_TABNEW, NULL, NULL, FALSE, curbuf);
        apply_autocmds (EVENT_TABENTER, NULL, NULL, FALSE, curbuf);
        return OK;
    }
    enter_tabpage (curtab, curbuf, TRUE, TRUE);
    return FAIL;
}

static tabpage_T *alloc_tabpage (void) {
    tabpage_T *tp;
    int i;
    tp = (tabpage_T *) alloc_clear ((unsigned ) sizeof (tabpage_T));
    if (tp == NULL)
        return NULL;
    tp->tp_vars = dict_alloc ();
    if (tp->tp_vars == NULL) {
        vim_free (tp);
        return NULL;
    }
    init_var_dict (tp -> tp_vars, & tp -> tp_winvar, VAR_SCOPE);
    for (i = 0; i < 3; i++)
        tp->tp_prev_which_scrollbars[i] = -1;
    tp->tp_diff_invalid = TRUE;
    tp->tp_ch_used = p_ch;
    return tp;
}

static int win_alloc_firstwin (win_T *oldwin) {
    curwin = win_alloc (NULL, FALSE);
    if (oldwin == NULL) {
        curbuf = buflist_new (NULL, NULL, 1L, BLN_LISTED);
        if (curwin == NULL || curbuf == NULL)
            return FAIL;
        curwin->w_buffer = curbuf;
        curwin->w_s = &(curbuf->b_s);
        curbuf->b_nwindows = 1;
        curwin->w_alist = &global_alist;
        curwin_init ();
    }
    else {
        win_init (curwin, oldwin, 0);
        RESET_BINDING (curwin);
    }
    new_frame (curwin);
    if (curwin->w_frame == NULL)
        return FAIL;
    topframe = curwin->w_frame;
    topframe->fr_width = Columns;
    topframe->fr_height = Rows - p_ch;
    return OK;
}

void curwin_init (void) {
    win_init_empty (curwin);
}

void win_init_size (void) {
    firstwin->w_height = ROWS_AVAIL;
    topframe->fr_height = ROWS_AVAIL;
    firstwin->w_width = Columns;
    topframe->fr_width = Columns;
}

char_u *file_name_at_cursor (int options, long  count, linenr_T *file_lnum) {
    return file_name_in_line (ml_get_curline (), curwin->w_cursor.col, options, count, curbuf->b_ffname, file_lnum);
}

char_u *file_name_in_line (char_u *line, int col, int options, long  count, char_u *rel_fname, linenr_T *file_lnum) {
    char_u *ptr;
    int len;
    int in_type = TRUE;
    int is_url = FALSE;
    ptr = line + col;
    while (*ptr != NUL && !vim_isfilec (*ptr))
        MB_PTR_ADV (ptr);
    if (*ptr == NUL) {
        if (options & FNAME_MESS)
            EMSG (_ ("E446: No file name under cursor"));
        return NULL;
    }
    while (ptr > line) {
        if (vim_isfilec (ptr[-1]) || ((options & FNAME_HYP) && path_is_url (ptr -1)))
            --ptr;
        else
            break;
    }
    len = 0;
    while (vim_isfilec (ptr[len]) || (ptr[len] == '\\' && ptr[len + 1] == ' ') || ((options & FNAME_HYP) && path_is_url (ptr +len)) || (is_url && vim_strchr ((char_u *) "?&=", ptr[len]) != NULL)) {
        if ((ptr[len] >= 'A' && ptr[len] <= 'Z') || (ptr[len] >= 'a' && ptr[len] <= 'z')) {
            if (in_type && path_is_url (ptr +len + 1))
                is_url = TRUE;
        }
        else
            in_type = FALSE;
        if (ptr[len] == '\\')
            ++len;
        ++len;
    }
    if (len > 2 && vim_strchr ((char_u *) ".,:;!", ptr[len - 1]) != NULL && ptr[len - 2] != '.')
        --len;
    if (file_lnum != NULL) {
        char_u *p;
        p = ptr + len;
        p = skipwhite (p);
        if (*p != NUL) {
            if (!isdigit (*p))
                ++p;
            p = skipwhite (p);
            if (isdigit (*p))
                *file_lnum = (int) getdigits (&p);
        }
    }
    return find_file_name_in_path (ptr, len, options, count, rel_fname);
}

char_u *find_file_name_in_path (char_u *ptr, int len, int options, long  count, char_u *rel_fname) {
    char_u *file_name;
    int c;
    char_u *tofree = NULL;
    if ((options & FNAME_INCL) && *curbuf->b_p_inex != NUL) {
        tofree = eval_includeexpr (ptr, len);
        if (tofree != NULL) {
            ptr = tofree;
            len = (int) STRLEN (ptr);
        }
    }
    if (options & FNAME_EXP) {
        file_name = find_file_in_path (ptr, len, options &~FNAME_MESS, TRUE, rel_fname);
        if (file_name == NULL && !(options & FNAME_INCL) && *curbuf->b_p_inex != NUL) {
            tofree = eval_includeexpr (ptr, len);
            if (tofree != NULL) {
                ptr = tofree;
                len = (int) STRLEN (ptr);
                file_name = find_file_in_path (ptr, len, options &~FNAME_MESS, TRUE, rel_fname);
            }
        }
        if (file_name == NULL && (options & FNAME_MESS)) {
            c = ptr[len];
            ptr[len] = NUL;
            EMSG2 (_ ("E447: Can't find file \"%s\" in path"), ptr);
            ptr[len] = c;
        }
        while (file_name != NULL && --count > 0) {
            vim_free (file_name);
            file_name = find_file_in_path (ptr, len, options, FALSE, rel_fname);
        }
    }
    else
        file_name = vim_strnsave (ptr, len);
    vim_free (tofree);
    return file_name;
}

static char_u *eval_includeexpr (char_u *ptr, int len) {
    char_u *res;
    set_vim_var_string (VV_FNAME, ptr, len);
    res = eval_to_string_safe (curbuf->b_p_inex, NULL, was_set_insecurely ((char_u *) "includeexpr", OPT_LOCAL));
    set_vim_var_string (VV_FNAME, NULL, 0);
    return res;
}

void tabpage_move (int nr) {
    int n = 1;
    tabpage_T *tp, *tp_dst;
    if (first_tabpage->tp_next == NULL)
        return;
    for (tp = first_tabpage; tp->tp_next != NULL && n < nr; tp = tp->tp_next)
        ++n;
    if (tp == curtab || (nr > 0 && tp->tp_next != NULL && tp->tp_next == curtab))
        return;
    tp_dst = tp;
    if (curtab == first_tabpage)
        first_tabpage = curtab->tp_next;
    else {
        FOR_ALL_TABPAGES (tp)
            if (tp->tp_next == curtab)
                break;
        if (tp == NULL)
            return;
        tp->tp_next = curtab->tp_next;
    }
    if (nr <= 0) {
        curtab->tp_next = first_tabpage;
        first_tabpage = curtab;
    }
    else {
        curtab->tp_next = tp_dst->tp_next;
        tp_dst->tp_next = curtab;
    }
    redraw_tabline = TRUE;
}

int win_close (win_T *win, int free_buf) {
    win_T *wp;
    int other_buffer = FALSE;
    int close_curwin = FALSE;
    int dir;
    int help_window = FALSE;
    tabpage_T *prev_curtab = curtab;
    frame_T *win_frame = win->w_frame->fr_parent;
    if (last_window ()) {
        EMSG (_ ("E444: Cannot close last window"));
        return FAIL;
    }
    if (win->w_closing || (win->w_buffer != NULL && win->w_buffer->b_locked > 0))
        return FAIL;
    if (win == aucmd_win) {
        EMSG (_ ("E813: Cannot close autocmd window"));
        return FAIL;
    }
    if ((firstwin == aucmd_win || lastwin == aucmd_win) && one_window ()) {
        EMSG (_ ("E814: Cannot close window, only autocmd window would remain"));
        return FAIL;
    }
    if (close_last_window_tabpage (win, free_buf, prev_curtab))
        return FAIL;
    if (bt_help (win->w_buffer))
        help_window = TRUE;
    else
        clear_snapshot (curtab, SNAP_HELP_IDX);
    if (win == curwin) {
        wp = frame2win (win_altframe (win, NULL));
        if (wp->w_buffer != curbuf) {
            other_buffer = TRUE;
            win->w_closing = TRUE;
            apply_autocmds (EVENT_BUFLEAVE, NULL, NULL, FALSE, curbuf);
            if (!win_valid (win))
                return FAIL;
            win->w_closing = FALSE;
            if (last_window ())
                return FAIL;
        }
        win->w_closing = TRUE;
        apply_autocmds (EVENT_WINLEAVE, NULL, NULL, FALSE, curbuf);
        if (!win_valid (win))
            return FAIL;
        win->w_closing = FALSE;
        if (last_window ())
            return FAIL;
        if (aborting ())
            return FAIL;
    }
    if (gui.in_use)
        out_flush ();
    if (win->w_buffer != NULL)
        reset_synblock (win);
    if (win->w_buffer != NULL) {
        bufref_T bufref;
        set_bufref (& bufref, curbuf);
        win->w_closing = TRUE;
        close_buffer (win, win -> w_buffer, free_buf ? DOBUF_UNLOAD : 0, TRUE);
        if (win_valid_any_tab (win))
            win->w_closing = FALSE;
        if (!bufref_valid (&bufref))
            curbuf = firstbuf;
    }
    if (only_one_window () && win_valid (win) && win->w_buffer == NULL && (last_window () || curtab != prev_curtab || close_last_window_tabpage (win, free_buf, prev_curtab))) {
        if (curwin->w_buffer == NULL)
            curwin->w_buffer = curbuf;
        getout (0);
    }
    if (curtab != prev_curtab && win_valid_any_tab (win) && win->w_buffer == NULL) {
        win_close_othertab (win, FALSE, prev_curtab);
        return FAIL;
    }
    if (!win_valid (win) || last_window () || close_last_window_tabpage (win, free_buf, prev_curtab))
        return FAIL;
    wp = win_free_mem (win, &dir, NULL);
    if (win == curwin) {
        curwin = wp;
        if (wp->w_p_pvw || bt_quickfix (wp->w_buffer)) {
            for (;;) {
                if (wp->w_next == NULL)
                    wp = firstwin;
                else
                    wp = wp->w_next;
                if (wp == curwin)
                    break;
                if (!wp->w_p_pvw && !bt_quickfix (wp->w_buffer)) {
                    curwin = wp;
                    break;
                }
            }
        }
        curbuf = curwin->w_buffer;
        close_curwin = TRUE;
        check_cursor ();
    }
    if (p_ea && (*p_ead == 'b' || *p_ead == dir))
        win_equal (curwin, curwin->w_frame->fr_parent == win_frame, dir);
    else
        win_comp_pos ();
    if (close_curwin) {
        win_enter_ext (wp, FALSE, TRUE, FALSE, TRUE, TRUE);
        if (other_buffer)
            apply_autocmds (EVENT_BUFENTER, NULL, NULL, FALSE, curbuf);
    }
    last_status (FALSE);
    if (help_window)
        restore_snapshot (SNAP_HELP_IDX, close_curwin);
    if (gui.in_use && !win_hasvertsplit ())
        gui_init_which_components (NULL);
    redraw_all_later (NOT_VALID);
    return OK;
}

static int last_window (void) {
    return (one_window () && first_tabpage->tp_next == NULL);
}

static int close_last_window_tabpage (win_T *win, int free_buf, tabpage_T *prev_curtab) {
    if (ONE_WINDOW) {
        buf_T *old_curbuf = curbuf;
        goto_tabpage_tp (alt_tabpage (), FALSE, TRUE);
        redraw_tabline = TRUE;
        if (valid_tabpage (prev_curtab) && prev_curtab->tp_firstwin == win) {
            int h = tabline_height ();
            win_close_othertab (win, free_buf, prev_curtab);
            if (h != tabline_height ())
                shell_new_rows ();
        }
        apply_autocmds (EVENT_TABCLOSED, NULL, NULL, FALSE, curbuf);
        apply_autocmds (EVENT_WINENTER, NULL, NULL, FALSE, curbuf);
        apply_autocmds (EVENT_TABENTER, NULL, NULL, FALSE, curbuf);
        if (old_curbuf != curbuf)
            apply_autocmds (EVENT_BUFENTER, NULL, NULL, FALSE, curbuf);
        return TRUE;
    }
    return FALSE;
}

void win_close_othertab (win_T *win, int free_buf, tabpage_T *tp) {
    win_T *wp;
    int dir;
    tabpage_T *ptp = NULL;
    int free_tp = FALSE;
    if (win->w_closing || (win->w_buffer != NULL && win->w_buffer->b_locked > 0))
        return;
    if (win->w_buffer != NULL)
        close_buffer (win, win->w_buffer, free_buf ? DOBUF_UNLOAD : 0, FALSE);
    for (ptp = first_tabpage; ptp != NULL && ptp != tp; ptp = ptp->tp_next)
        ;
    if (ptp == NULL || tp == curtab)
        return;
    for (wp = tp->tp_firstwin; wp != NULL && wp != win; wp = wp->w_next)
        ;
    if (wp == NULL)
        return;
    if (tp->tp_firstwin == tp->tp_lastwin) {
        if (tp == first_tabpage)
            first_tabpage = tp->tp_next;
        else {
            for (ptp = first_tabpage; ptp != NULL && ptp->tp_next != tp; ptp = ptp->tp_next)
                ;
            if (ptp == NULL) {
                internal_error ("win_close_othertab()");
                return;
            }
            ptp->tp_next = tp->tp_next;
        }
        free_tp = TRUE;
    }
    win_free_mem (win, & dir, tp);
    if (free_tp)
        free_tabpage (tp);
}

static win_T *win_free_mem (win_T *win, int *dirp, tabpage_T *tp) {
    frame_T *frp;
    win_T *wp;
    frp = win->w_frame;
    wp = winframe_remove (win, dirp, tp);
    vim_free (frp);
    win_free (win, tp);
    if (tp != NULL && win == tp->tp_curwin)
        tp->tp_curwin = wp;
    return wp;
}

int only_one_window (void) {
    int count = 0;
    win_T *wp;
    if (first_tabpage->tp_next != NULL)
        return FALSE;
    FOR_ALL_WINDOWS (wp)
        if (wp->w_buffer != NULL && (!((bt_help (wp->w_buffer) && !bt_help (curbuf)) || wp->w_p_pvw) || wp == curwin) && wp != aucmd_win)
            ++count;
    return (count <= 1);
}

void goto_tabpage (int n) {
    tabpage_T *tp;
    tabpage_T *ttp;
    int i;
    if (text_locked ()) {
        text_locked_msg ();
        return;
    }
    if (first_tabpage->tp_next == NULL) {
        if (n > 1)
            beep_flush ();
        return;
    }
    if (n == 0) {
        if (curtab->tp_next == NULL)
            tp = first_tabpage;
        else
            tp = curtab->tp_next;
    }
    else if (n < 0) {
        ttp = curtab;
        for (i = n; i < 0; ++i) {
            for (tp = first_tabpage; tp->tp_next != ttp && tp->tp_next != NULL; tp = tp->tp_next)
                ;
            ttp = tp;
        }
    }
    else if (n == 9999) {
        for (tp = first_tabpage; tp->tp_next != NULL; tp = tp->tp_next)
            ;
    }
    else {
        tp = find_tabpage (n);
        if (tp == NULL) {
            beep_flush ();
            return;
        }
    }
    goto_tabpage_tp (tp, TRUE, TRUE);
}

tabpage_T *find_tabpage (int n) {
    tabpage_T *tp;
    int i = 1;
    for (tp = first_tabpage; tp != NULL && i != n; tp = tp->tp_next)
        ++i;
    return tp;
}

void close_others (int message, int forceit) {
    win_T *wp;
    win_T *nextwp;
    int r;
    if (one_window ()) {
        if (message && !autocmd_busy)
            MSG (_ (m_onlyone));
        return;
    }
    for (wp = firstwin; win_valid (wp); wp = nextwp) {
        nextwp = wp->w_next;
        if (wp != curwin) {
            r = can_abandon (wp->w_buffer, forceit);
            if (!win_valid (wp)) {
                nextwp = firstwin;
                continue;
            }
            if (!r) {
                if (message && (p_confirm || cmdmod.confirm) && p_write) {
                    dialog_changed (wp -> w_buffer, FALSE);
                    if (!win_valid (wp)) {
                        nextwp = firstwin;
                        continue;
                    }
                }
                if (bufIsChanged (wp->w_buffer))
                    continue;
            }
            win_close (wp, ! buf_hide (wp -> w_buffer) && ! bufIsChanged (wp -> w_buffer));
        }
    }
    if (message && !ONE_WINDOW)
        EMSG (_ ("E445: Other window contains changes"));
}

void win_drag_status_line (win_T *dragwin, int offset) {
    frame_T *curfr;
    frame_T *fr;
    int room;
    int row;
    int up;
    int n;
    fr = dragwin->w_frame;
    curfr = fr;
    if (fr != topframe) {
        fr = fr->fr_parent;
        if (fr->fr_layout != FR_COL) {
            curfr = fr;
            if (fr != topframe)
                fr = fr->fr_parent;
        }
    }
    while (curfr != topframe && curfr->fr_next == NULL) {
        if (fr != topframe)
            fr = fr->fr_parent;
        curfr = fr;
        if (fr != topframe)
            fr = fr->fr_parent;
    }
    if (offset < 0) {
        up = TRUE;
        offset = -offset;
        if (fr == curfr) {
            room = fr->fr_height - frame_minheight (fr, NULL);
        }
        else {
            room = 0;
            for (fr = fr->fr_child;; fr = fr->fr_next) {
                room += fr->fr_height - frame_minheight (fr, NULL);
                if (fr == curfr)
                    break;
            }
        }
        fr = curfr->fr_next;
    }
    else {
        up = FALSE;
        room = Rows - cmdline_row;
        if (curfr->fr_next == NULL)
            room -= 1;
        else
            room -= p_ch;
        if (room < 0)
            room = 0;
        for (fr = curfr->fr_next; fr != NULL; fr = fr->fr_next)
            room += fr->fr_height - frame_minheight (fr, NULL);
        fr = curfr;
    }
    if (room < offset)
        offset = room;
    if (offset <= 0)
        return;
    if (fr != NULL)
        frame_new_height (fr, fr->fr_height + offset, up, FALSE);
    if (up)
        fr = curfr;
    else
        fr = curfr->fr_next;
    while (fr != NULL && offset > 0) {
        n = frame_minheight (fr, NULL);
        if (fr->fr_height - offset <= n) {
            offset -= fr->fr_height - n;
            frame_new_height (fr, n, ! up, FALSE);
        }
        else {
            frame_new_height (fr, fr -> fr_height - offset, ! up, FALSE);
            break;
        }
        if (up)
            fr = fr->fr_prev;
        else
            fr = fr->fr_next;
    }
    row = win_comp_pos ();
    screen_fill (row, cmdline_row, 0, (int) Columns, ' ', ' ', 0);
    cmdline_row = row;
    p_ch = Rows - cmdline_row;
    if (p_ch < 1)
        p_ch = 1;
    curtab->tp_ch_used = p_ch;
    redraw_all_later (SOME_VALID);
    showmode ();
}

void win_drag_vsep_line (win_T *dragwin, int offset) {
    frame_T *curfr;
    frame_T *fr;
    int room;
    int left;
    int n;
    fr = dragwin->w_frame;
    if (fr == topframe)
        return;
    curfr = fr;
    fr = fr->fr_parent;
    if (fr->fr_layout != FR_ROW) {
        if (fr == topframe)
            return;
        curfr = fr;
        fr = fr->fr_parent;
    }
    while (curfr->fr_next == NULL) {
        if (fr == topframe)
            break;
        curfr = fr;
        fr = fr->fr_parent;
        if (fr != topframe) {
            curfr = fr;
            fr = fr->fr_parent;
        }
    }
    if (offset < 0) {
        left = TRUE;
        offset = -offset;
        room = 0;
        for (fr = fr->fr_child;; fr = fr->fr_next) {
            room += fr->fr_width - frame_minwidth (fr, NULL);
            if (fr == curfr)
                break;
        }
        fr = curfr->fr_next;
    }
    else {
        left = FALSE;
        room = 0;
        for (fr = curfr->fr_next; fr != NULL; fr = fr->fr_next)
            room += fr->fr_width - frame_minwidth (fr, NULL);
        fr = curfr;
    }
    if (room < offset)
        offset = room;
    if (offset <= 0)
        return;
    if (fr == NULL)
        return;
    frame_new_width (fr, fr -> fr_width + offset, left, FALSE);
    if (left)
        fr = curfr;
    else
        fr = curfr->fr_next;
    while (fr != NULL && offset > 0) {
        n = frame_minwidth (fr, NULL);
        if (fr->fr_width - offset <= n) {
            offset -= fr->fr_width - n;
            frame_new_width (fr, n, ! left, FALSE);
        }
        else {
            frame_new_width (fr, fr -> fr_width - offset, ! left, FALSE);
            break;
        }
        if (left)
            fr = fr->fr_prev;
        else
            fr = fr->fr_next;
    }
    (void) win_comp_pos ();
    redraw_all_later (NOT_VALID);
}

#define FRACTION_MULT	16384L

win_T *buf_jump_open_win (buf_T *buf) {
    win_T *wp = NULL;
    if (curwin->w_buffer == buf)
        wp = curwin;
    else
        FOR_ALL_WINDOWS (wp)
            if (wp->w_buffer == buf)
                break;
    if (wp != NULL)
        win_enter (wp, FALSE);
    return wp;
}

win_T *buf_jump_open_tab (buf_T *buf) {
    win_T *wp = buf_jump_open_win (buf);
    tabpage_T *tp;
    if (wp != NULL)
        return wp;
    FOR_ALL_TABPAGES (tp)
        if (tp != curtab) {
            for (wp = tp->tp_firstwin; wp != NULL; wp = wp->w_next)
                if (wp->w_buffer == buf)
                    break;
            if (wp != NULL) {
                goto_tabpage_win (tp, wp);
                if (curwin != wp)
                    wp = NULL;
                break;
            }
        }
    return wp;
}

void close_windows (buf_T *buf, int keep_curwin) {
    win_T *wp;
    tabpage_T *tp, *nexttp;
    int h = tabline_height ();
    int count = tabpage_index (NULL);
    ++RedrawingDisabled;
    for (wp = firstwin; wp != NULL && !ONE_WINDOW;) {
        if (wp->w_buffer == buf && (!keep_curwin || wp != curwin) && !(wp->w_closing || wp->w_buffer->b_locked > 0)) {
            if (win_close (wp, FALSE) == FAIL)
                break;
            wp = firstwin;
        }
        else
            wp = wp->w_next;
    }
    for (tp = first_tabpage; tp != NULL; tp = nexttp) {
        nexttp = tp->tp_next;
        if (tp != curtab)
            for (wp = tp->tp_firstwin; wp != NULL; wp = wp->w_next)
                if (wp->w_buffer == buf && !(wp->w_closing || wp->w_buffer->b_locked > 0)) {
                    win_close_othertab (wp, FALSE, tp);
                    nexttp = first_tabpage;
                    break;
                }
    }
    --RedrawingDisabled;
    if (count != tabpage_index (NULL))
        apply_autocmds (EVENT_TABCLOSED, NULL, NULL, FALSE, curbuf);
    redraw_tabline = TRUE;
    if (h != tabline_height ())
        shell_new_rows ();
}

void get_wincmd_addr_type (char_u *arg, exarg_T *eap) {
    switch (*arg) {
    case 'S' :
    case Ctrl_S :
    case 's' :
    case Ctrl_N :
    case 'n' :
    case 'j' :
    case Ctrl_J :
    case 'k' :
    case Ctrl_K :
    case 'T' :
    case Ctrl_R :
    case 'r' :
    case 'R' :
    case 'K' :
    case 'J' :
    case '+' :
    case '-' :
    case Ctrl__ :
    case '_' :
    case '|' :
    case ']' :
    case Ctrl_RSB :
    case 'g' :
    case Ctrl_G :
    case Ctrl_V :
    case 'v' :
    case 'h' :
    case Ctrl_H :
    case 'l' :
    case Ctrl_L :
    case 'H' :
    case 'L' :
    case '>' :
    case '<' :
    case '}' :
    case 'f' :
    case 'F' :
    case Ctrl_F :
    case 'i' :
    case Ctrl_I :
    case 'd' :
    case Ctrl_D :
        eap->addr_type = ADDR_LINES;
        break;
    case Ctrl_HAT :
    case '^' :
        eap->addr_type = ADDR_BUFFERS;
        break;
    case Ctrl_Q :
    case 'q' :
    case Ctrl_C :
    case 'c' :
    case Ctrl_O :
    case 'o' :
    case Ctrl_W :
    case 'w' :
    case 'W' :
    case 'x' :
    case Ctrl_X :
        eap->addr_type = ADDR_WINDOWS;
        break;
    case Ctrl_Z :
    case 'z' :
    case 'P' :
    case 't' :
    case Ctrl_T :
    case 'b' :
    case Ctrl_B :
    case 'p' :
    case Ctrl_P :
    case '=' :
    case CAR :
        eap->addr_type = 0;
        break;
    }
}

void scroll_to_fraction (win_T *wp, int prev_height) {
    linenr_T lnum;
    int sline, line_size;
    int height = wp->w_height;
    if (height > 0 && (!wp->w_p_scb || wp == curwin)) {
        lnum = wp->w_cursor.lnum;
        if (lnum < 1)
            lnum = 1;
        wp->w_wrow = ((long ) wp->w_fraction * (long ) height - 1L + FRACTION_MULT / 2) / FRACTION_MULT;
        line_size = plines_win_col (wp, lnum, (long ) (wp->w_cursor.col)) - 1;
        sline = wp->w_wrow - line_size;
        if (sline >= 0) {
            int rows = plines_win (wp, lnum, FALSE);
            if (sline > wp->w_height - rows) {
                sline = wp->w_height - rows;
                wp->w_wrow -= rows - line_size;
            }
        }
        if (sline < 0) {
            wp->w_wrow = line_size;
            if (wp->w_wrow >= wp->w_height && (wp->w_width - win_col_off (wp)) > 0) {
                wp->w_skipcol += wp->w_width - win_col_off (wp);
                --wp->w_wrow;
                while (wp->w_wrow >= wp->w_height) {
                    wp->w_skipcol += wp->w_width - win_col_off (wp) + win_col_off2 (wp);
                    --wp->w_wrow;
                }
            }
            set_topline (wp, lnum);
        }
        else if (sline > 0) {
            while (sline > 0 && lnum > 1) {
                hasFoldingWin (wp, lnum, & lnum, NULL, TRUE, NULL);
                if (lnum == 1) {
                    line_size = 1;
                    --sline;
                    break;
                }
                --lnum;
                if (lnum == wp->w_topline)
                    line_size = plines_win_nofill (wp, lnum, TRUE) + wp->w_topfill;
                else
                    line_size = plines_win (wp, lnum, TRUE);
                sline -= line_size;
            }
            if (sline < 0) {
                hasFoldingWin (wp, lnum, NULL, & lnum, TRUE, NULL);
                lnum++;
                wp->w_wrow -= line_size + sline;
            }
            else if (sline > 0) {
                lnum = 1;
                wp->w_wrow -= sline;
            }
            set_topline (wp, lnum);
        }
    }
    if (wp == curwin) {
        if (p_so)
            update_topline ();
        curs_columns (FALSE);
    }
    if (prev_height > 0)
        wp->w_prev_fraction_row = wp->w_wrow;
    win_comp_scroll (wp);
    redraw_win_later (wp, SOME_VALID);
    wp->w_redr_status = TRUE;
    invalidate_botline_win (wp);
}

static int frame_check_height (frame_T *topfrp, int height) {
    frame_T *frp;
    if (topfrp->fr_height != height)
        return FALSE;
    if (topfrp->fr_layout == FR_ROW)
        for (frp = topfrp->fr_child; frp != NULL; frp = frp->fr_next)
            if (frp->fr_height != height)
                return FALSE;
    return TRUE;
}

void switch_buffer (bufref_T *save_curbuf, buf_T *buf) {
    block_autocmds ();
    set_bufref (save_curbuf, curbuf);
    --curbuf->b_nwindows;
    curbuf = buf;
    curwin->w_buffer = buf;
    ++curbuf->b_nwindows;
}

int switch_win (win_T **save_curwin, tabpage_T **save_curtab, win_T *win, tabpage_T *tp, int no_display) {
    block_autocmds ();
    *save_curwin = curwin;
    if (tp != NULL) {
        *save_curtab = curtab;
        if (no_display) {
            curtab->tp_firstwin = firstwin;
            curtab->tp_lastwin = lastwin;
            curtab = tp;
            firstwin = curtab->tp_firstwin;
            lastwin = curtab->tp_lastwin;
        }
        else
            goto_tabpage_tp (tp, FALSE, FALSE);
    }
    if (!win_valid (win))
        return FAIL;
    curwin = win;
    curbuf = curwin->w_buffer;
    return OK;
}

void restore_win (win_T *save_curwin, tabpage_T *save_curtab, int no_display) {
    if (save_curtab != NULL && valid_tabpage (save_curtab)) {
        if (no_display) {
            curtab->tp_firstwin = firstwin;
            curtab->tp_lastwin = lastwin;
            curtab = save_curtab;
            firstwin = curtab->tp_firstwin;
            lastwin = curtab->tp_lastwin;
        }
        else
            goto_tabpage_tp (save_curtab, FALSE, FALSE);
    }
    if (win_valid (save_curwin)) {
        curwin = save_curwin;
        curbuf = curwin->w_buffer;
    }
    unblock_autocmds ();
}

void restore_buffer (bufref_T *save_curbuf) {
    unblock_autocmds ();
    if (bufref_valid (save_curbuf)) {
        --curbuf->b_nwindows;
        curwin->w_buffer = save_curbuf->br_buf;
        curbuf = save_curbuf->br_buf;
        ++curbuf->b_nwindows;
    }
}

win_T *win_id2wp (typval_T *argvars) {
    win_T *wp;
    tabpage_T *tp;
    int id = get_tv_number (&argvars[0]);
    FOR_ALL_TAB_WINDOWS (tp, wp)
        if (wp->w_id == id)
            return wp;
    return NULL;
}

void win_findbuf (typval_T *argvars, list_T *list) {
    win_T *wp;
    tabpage_T *tp;
    int bufnr = get_tv_number (&argvars[0]);
    FOR_ALL_TAB_WINDOWS (tp, wp)
        if (wp->w_buffer->b_fnum == bufnr)
            list_append_number (list, wp->w_id);
}

int win_getid (typval_T *argvars) {
    int winnr;
    win_T *wp;
    if (argvars[0].v_type == VAR_UNKNOWN)
        return curwin->w_id;
    winnr = get_tv_number (&argvars[0]);
    if (winnr > 0) {
        if (argvars[1].v_type == VAR_UNKNOWN)
            wp = firstwin;
        else {
            tabpage_T *tp;
            int tabnr = get_tv_number (&argvars[1]);
            FOR_ALL_TABPAGES (tp)
                if (--tabnr == 0)
                    break;
            if (tp == NULL)
                return -1;
            if (tp == curtab)
                wp = firstwin;
            else
                wp = tp->tp_firstwin;
        }
        for (; wp != NULL; wp = wp->w_next)
            if (--winnr == 0)
                return wp->w_id;
    }
    return 0;
}

int win_gotoid (typval_T *argvars) {
    win_T *wp;
    tabpage_T *tp;
    int id = get_tv_number (&argvars[0]);
    FOR_ALL_TAB_WINDOWS (tp, wp)
        if (wp->w_id == id) {
            goto_tabpage_win (tp, wp);
            return 1;
        }
    return 0;
}

void win_id2tabwin (typval_T *argvars, list_T *list) {
    win_T *wp;
    tabpage_T *tp;
    int winnr = 1;
    int tabnr = 1;
    int id = get_tv_number (&argvars[0]);
    FOR_ALL_TABPAGES (tp) {
        FOR_ALL_WINDOWS_IN_TAB (tp, wp) {
            if (wp->w_id == id) {
                list_append_number (list, tabnr);
                list_append_number (list, winnr);
                return;
            }
            ++winnr;
        }
        ++tabnr;
        winnr = 1;
    }
    list_append_number (list, 0);
    list_append_number (list, 0);
}

int win_id2win (typval_T *argvars) {
    win_T *wp;
    int nr = 1;
    int id = get_tv_number (&argvars[0]);
    FOR_ALL_WINDOWS (wp) {
        if (wp->w_id == id)
            return nr;
        ++nr;
    }
    return 0;
}

int match_add (win_T *wp, char_u *grp, char_u *pat, int prio, int id, list_T *pos_list, char_u *conceal_char) {
    matchitem_T *cur;
    matchitem_T *prev;
    matchitem_T *m;
    int hlg_id;
    regprog_T *regprog = NULL;
    int rtype = SOME_VALID;
    if (*grp == NUL || (pat != NULL && *pat == NUL))
        return -1;
    if (id < -1 || id == 0) {
        EMSGN (_ ("E799: Invalid ID: %ld (must be greater than or equal to 1)"), id);
        return -1;
    }
    if (id != -1) {
        cur = wp->w_match_head;
        while (cur != NULL) {
            if (cur->id == id) {
                EMSGN (_ ("E801: ID already taken: %ld"), id);
                return -1;
            }
            cur = cur->next;
        }
    }
    if ((hlg_id = syn_namen2id (grp, (int) STRLEN (grp))) == 0) {
        EMSG2 (_ (e_nogroup), grp);
        return -1;
    }
    if (pat != NULL && (regprog = vim_regcomp (pat, RE_MAGIC)) == NULL) {
        EMSG2 (_ (e_invarg2), pat);
        return -1;
    }
    while (id == -1) {
        cur = wp->w_match_head;
        while (cur != NULL && cur->id != wp->w_next_match_id)
            cur = cur->next;
        if (cur == NULL)
            id = wp->w_next_match_id;
        wp->w_next_match_id++;
    }
    m = (matchitem_T *) alloc_clear (sizeof (matchitem_T));
    m->id = id;
    m->priority = prio;
    m->pattern = pat == NULL ? NULL : vim_strsave (pat);
    m->hlg_id = hlg_id;
    m->match.regprog = regprog;
    m->match.rmm_ic = FALSE;
    m->match.rmm_maxcol = 0;
    if (pos_list != NULL) {
        linenr_T toplnum = 0;
        linenr_T botlnum = 0;
        listitem_T *li;
        int i;
        for (i = 0, li = pos_list->lv_first; li != NULL && i < MAXPOSMATCH; i++, li = li->li_next) {
            linenr_T lnum = 0;
            colnr_T col = 0;
            int len = 1;
            list_T *subl;
            listitem_T *subli;
            int error = FALSE;
            if (li->li_tv.v_type == VAR_LIST) {
                subl = li->li_tv.vval.v_list;
                if (subl == NULL)
                    goto fail;
                subli = subl->lv_first;
                if (subli == NULL)
                    goto fail;
                lnum = get_tv_number_chk (&subli->li_tv, &error);
                if (error == TRUE)
                    goto fail;
                if (lnum == 0) {
                    --i;
                    continue;
                }
                m->pos.pos[i].lnum = lnum;
                subli = subli->li_next;
                if (subli != NULL) {
                    col = get_tv_number_chk (&subli->li_tv, &error);
                    if (error == TRUE)
                        goto fail;
                    subli = subli->li_next;
                    if (subli != NULL) {
                        len = get_tv_number_chk (&subli->li_tv, &error);
                        if (error == TRUE)
                            goto fail;
                    }
                }
                m->pos.pos[i].col = col;
                m->pos.pos[i].len = len;
            }
            else if (li->li_tv.v_type == VAR_NUMBER) {
                if (li->li_tv.vval.v_number == 0) {
                    --i;
                    continue;
                }
                m->pos.pos[i].lnum = li->li_tv.vval.v_number;
                m->pos.pos[i].col = 0;
                m->pos.pos[i].len = 0;
            }
            else {
                EMSG (_ ("List or number required"));
                goto fail;
            }
            if (toplnum == 0 || lnum < toplnum)
                toplnum = lnum;
            if (botlnum == 0 || lnum >= botlnum)
                botlnum = lnum + 1;
        }
        if (toplnum != 0) {
            if (wp->w_buffer->b_mod_set) {
                if (wp->w_buffer->b_mod_top > toplnum)
                    wp->w_buffer->b_mod_top = toplnum;
                if (wp->w_buffer->b_mod_bot < botlnum)
                    wp->w_buffer->b_mod_bot = botlnum;
            }
            else {
                wp->w_buffer->b_mod_set = TRUE;
                wp->w_buffer->b_mod_top = toplnum;
                wp->w_buffer->b_mod_bot = botlnum;
                wp->w_buffer->b_mod_xlines = 0;
            }
            m->pos.toplnum = toplnum;
            m->pos.botlnum = botlnum;
            rtype = VALID;
        }
    }
    cur = wp->w_match_head;
    prev = cur;
    while (cur != NULL && prio >= cur->priority) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == prev)
        wp->w_match_head = m;
    else
        prev->next = m;
    m->next = cur;
    redraw_later (rtype);
    return id;
fail :
    vim_free (m);
    return -1;
}

matchitem_T *get_match (win_T *wp, int id) {
    matchitem_T *cur = wp->w_match_head;
    while (cur != NULL && cur->id != id)
        cur = cur->next;
    return cur;
}

int match_delete (win_T *wp, int id, int perr) {
    matchitem_T *cur = wp->w_match_head;
    matchitem_T *prev = cur;
    int rtype = SOME_VALID;
    if (id < 1) {
        if (perr == TRUE)
            EMSGN (_ ("E802: Invalid ID: %ld (must be greater than or equal to 1)"), id);
        return -1;
    }
    while (cur != NULL && cur->id != id) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL) {
        if (perr == TRUE)
            EMSGN (_ ("E803: ID not found: %ld"), id);
        return -1;
    }
    if (cur == prev)
        wp->w_match_head = cur->next;
    else
        prev->next = cur->next;
    vim_regfree (cur -> match.regprog);
    vim_free (cur -> pattern);
    if (cur->pos.toplnum != 0) {
        if (wp->w_buffer->b_mod_set) {
            if (wp->w_buffer->b_mod_top > cur->pos.toplnum)
                wp->w_buffer->b_mod_top = cur->pos.toplnum;
            if (wp->w_buffer->b_mod_bot < cur->pos.botlnum)
                wp->w_buffer->b_mod_bot = cur->pos.botlnum;
        }
        else {
            wp->w_buffer->b_mod_set = TRUE;
            wp->w_buffer->b_mod_top = cur->pos.toplnum;
            wp->w_buffer->b_mod_bot = cur->pos.botlnum;
            wp->w_buffer->b_mod_xlines = 0;
        }
        rtype = VALID;
    }
    vim_free (cur);
    redraw_later (rtype);
    return 0;
}

char_u *grab_file_name (long  count, linenr_T *file_lnum) {
    int options = FNAME_MESS | FNAME_EXP | FNAME_REL | FNAME_UNESC;
    if (VIsual_active) {
        int len;
        char_u *ptr;
        if (get_visual_text (NULL, &ptr, &len) == FAIL)
            return NULL;
        return find_file_name_in_path (ptr, len, options, count, curbuf->b_ffname);
    }
    return file_name_at_cursor (options | FNAME_HYP, count, file_lnum);
}

void do_window (int nchar, long  Prenum, int xchar) {
    long  Prenum1;
    win_T *wp;
    char_u *ptr;
    linenr_T lnum = -1;
    int type = FIND_DEFINE;
    int len;
    char_u cbuf [40];
    if (Prenum == 0)
        Prenum1 = 1;
    else
        Prenum1 = Prenum;

    # define CHECK_CMDWIN
    switch (nchar) {
    case 'S' :
    case Ctrl_S :
    case 's' :
        CHECK_CMDWIN reset_VIsual_and_resel ();
        if (bt_quickfix (curbuf))
            goto newwindow;
        need_mouse_correct = TRUE;
        (void) win_split ((int) Prenum, 0);
        break;
    case Ctrl_V :
    case 'v' :
        CHECK_CMDWIN reset_VIsual_and_resel ();
        if (bt_quickfix (curbuf))
            goto newwindow;
        need_mouse_correct = TRUE;
        (void) win_split ((int) Prenum, WSP_VERT);
        break;
    case Ctrl_HAT :
    case '^' :
        CHECK_CMDWIN reset_VIsual_and_resel ();
        cmd_with_count ("split #", cbuf, sizeof (cbuf), Prenum);
        do_cmdline_cmd (cbuf);
        break;
    case Ctrl_N :
    case 'n' :
        CHECK_CMDWIN reset_VIsual_and_resel ();
    newwindow :
        if (Prenum)
            vim_snprintf ((char *) cbuf, sizeof (cbuf) - 5, "%ld", Prenum);
        else
            cbuf[0] = NUL;
        if (nchar == 'v' || nchar == Ctrl_V)
            STRCAT (cbuf, "v");
        STRCAT (cbuf, "new");
        do_cmdline_cmd (cbuf);
        break;
    case Ctrl_Q :
    case 'q' :
        reset_VIsual_and_resel ();
        cmd_with_count ("quit", cbuf, sizeof (cbuf), Prenum);
        do_cmdline_cmd (cbuf);
        break;
    case Ctrl_C :
    case 'c' :
        reset_VIsual_and_resel ();
        cmd_with_count ("close", cbuf, sizeof (cbuf), Prenum);
        do_cmdline_cmd (cbuf);
        break;
    case Ctrl_Z :
    case 'z' :
        CHECK_CMDWIN reset_VIsual_and_resel ();
        do_cmdline_cmd ((char_u *) "pclose");
        break;
    case 'P' :
        FOR_ALL_WINDOWS (wp)
            if (wp->w_p_pvw)
                break;
        if (wp == NULL)
            EMSG (_ ("E441: There is no preview window"));
        else
            win_goto (wp);
        break;
    case Ctrl_O :
    case 'o' :
        CHECK_CMDWIN reset_VIsual_and_resel ();
        cmd_with_count ("only", cbuf, sizeof (cbuf), Prenum);
        do_cmdline_cmd (cbuf);
        break;
    case Ctrl_W :
    case 'w' :
    case 'W' :
        CHECK_CMDWIN
        if (ONE_WINDOW && Prenum != 1)
            beep_flush ();
        else {
            if (Prenum) {
                for (wp = firstwin; --Prenum > 0;) {
                    if (wp->w_next == NULL)
                        break;
                    else
                        wp = wp->w_next;
                }
            }
            else {
                if (nchar == 'W') {
                    wp = curwin->w_prev;
                    if (wp == NULL)
                        wp = lastwin;
                }
                else {
                    wp = curwin->w_next;
                    if (wp == NULL)
                        wp = firstwin;
                }
            }
            win_goto (wp);
        }
        break;
    case 'j' :
    case K_DOWN :
    case Ctrl_J :
        CHECK_CMDWIN win_goto_ver (FALSE, Prenum1);
        break;
    case 'k' :
    case K_UP :
    case Ctrl_K :
        CHECK_CMDWIN win_goto_ver (TRUE, Prenum1);
        break;
    case 'h' :
    case K_LEFT :
    case Ctrl_H :
    case K_BS :
        CHECK_CMDWIN win_goto_hor (TRUE, Prenum1);
        break;
    case 'l' :
    case K_RIGHT :
    case Ctrl_L :
        CHECK_CMDWIN win_goto_hor (FALSE, Prenum1);
        break;
    case 'T' :
        if (one_window ())
            MSG (_ (m_onlyone));
        else {
            tabpage_T *oldtab = curtab;
            tabpage_T *newtab;
            wp = curwin;
            if (win_new_tabpage ((int) Prenum) == OK && valid_tabpage (oldtab)) {
                newtab = curtab;
                goto_tabpage_tp (oldtab, TRUE, TRUE);
                if (curwin == wp)
                    win_close (curwin, FALSE);
                if (valid_tabpage (newtab))
                    goto_tabpage_tp (newtab, TRUE, TRUE);
            }
        }
        break;
    case 't' :
    case Ctrl_T :
        win_goto (firstwin);
        break;
    case 'b' :
    case Ctrl_B :
        win_goto (lastwin);
        break;
    case 'p' :
    case Ctrl_P :
        if (!win_valid (prevwin))
            beep_flush ();
        else
            win_goto (prevwin);
        break;
    case 'x' :
    case Ctrl_X :
        CHECK_CMDWIN win_exchange (Prenum);
        break;
    case Ctrl_R :
    case 'r' :
        CHECK_CMDWIN reset_VIsual_and_resel ();
        win_rotate (FALSE, (int) Prenum1);
        break;
    case 'R' :
        CHECK_CMDWIN reset_VIsual_and_resel ();
        win_rotate (TRUE, (int) Prenum1);
        break;
    case 'K' :
    case 'J' :
    case 'H' :
    case 'L' :
        CHECK_CMDWIN win_totop ((int) Prenum, ((nchar == 'H' || nchar == 'L') ? WSP_VERT : 0) | ((nchar == 'H' || nchar == 'K') ? WSP_TOP : WSP_BOT));
        break;
    case '=' :
        need_mouse_correct = TRUE;
        win_equal (NULL, FALSE, 'b');
        break;
    case '+' :
        need_mouse_correct = TRUE;
        win_setheight (curwin -> w_height + (int) Prenum1);
        break;
    case '-' :
        need_mouse_correct = TRUE;
        win_setheight (curwin -> w_height - (int) Prenum1);
        break;
    case Ctrl__ :
    case '_' :
        need_mouse_correct = TRUE;
        win_setheight (Prenum ? (int) Prenum : 9999);
        break;
    case '>' :
        need_mouse_correct = TRUE;
        win_setwidth (curwin -> w_width + (int) Prenum1);
        break;
    case '<' :
        need_mouse_correct = TRUE;
        win_setwidth (curwin -> w_width - (int) Prenum1);
        break;
    case '|' :
        need_mouse_correct = TRUE;
        win_setwidth (Prenum != 0 ? (int) Prenum : 9999);
        break;
    case '}' :
        CHECK_CMDWIN
        if (Prenum)
            g_do_tagpreview = Prenum;
        else
            g_do_tagpreview = p_pvh;
    case ']' :
    case Ctrl_RSB :
        CHECK_CMDWIN
        if (Prenum)
            postponed_split = Prenum;
        else
            postponed_split = -1;
        if (nchar != '}')
            g_do_tagpreview = 0;
        do_nv_ident (Ctrl_RSB, NUL);
        break;
    case 'f' :
    case 'F' :
    case Ctrl_F :
    wingotofile :
        CHECK_CMDWIN ptr = grab_file_name (Prenum1, &lnum);
        if (ptr != NULL) {
            tabpage_T *oldtab = curtab;
            win_T *oldwin = curwin;
            need_mouse_correct = TRUE;
            setpcmark ();
            if (win_split (0, 0) == OK) {
                RESET_BINDING (curwin);
                if (do_ecmd (0, ptr, NULL, NULL, ECMD_LASTL, ECMD_HIDE, NULL) == FAIL) {
                    win_close (curwin, FALSE);
                    goto_tabpage_win (oldtab, oldwin);
                }
                else if (nchar == 'F' && lnum >= 0) {
                    curwin->w_cursor.lnum = lnum;
                    check_cursor_lnum ();
                    beginline (BL_SOL | BL_FIX);
                }
            }
            vim_free (ptr);
        }
        break;
    case 'i' :
    case Ctrl_I :
        type = FIND_ANY;
    case 'd' :
    case Ctrl_D :
        CHECK_CMDWIN
        if ((len = find_ident_under_cursor (&ptr, FIND_IDENT)) == 0)
            break;
        find_pattern_in_path (ptr, 0, len, TRUE, Prenum == 0 ? TRUE : FALSE, type, Prenum1, ACTION_SPLIT, (linenr_T) 1, (linenr_T) MAXLNUM);
        curwin->w_set_curswant = TRUE;
        break;
    case K_KENTER :
    case CAR :
        if (bt_quickfix (curbuf)) {
            sprintf ((char *) cbuf, "split +%ld%s", (long) curwin -> w_cursor.lnum, (curwin -> w_llist_ref == NULL) ? "cc" : "ll");
            do_cmdline_cmd (cbuf);
        }
        break;
    case 'g' :
    case Ctrl_G :
        CHECK_CMDWIN
        ++no_mapping;
        ++allow_keys;
        if (xchar == NUL)
            xchar = plain_vgetc ();
        LANGMAP_ADJUST (xchar, TRUE);
        --no_mapping;
        --allow_keys;
        (void) add_to_showcmd (xchar);
        switch (xchar) {
        case '}' :
            xchar = Ctrl_RSB;
            if (Prenum)
                g_do_tagpreview = Prenum;
            else
                g_do_tagpreview = p_pvh;
        case ']' :
        case Ctrl_RSB :
            if (Prenum)
                postponed_split = Prenum;
            else
                postponed_split = -1;
            do_nv_ident ('g', xchar);
            break;
        case 'f' :
        case 'F' :
            cmdmod.tab = tabpage_index (curtab) + 1;
            nchar = xchar;
            goto wingotofile;
        default :
            beep_flush ();
            break;
        }
        break;
    default :
        beep_flush ();
        break;
    }
}

static void cmd_with_count (char *cmd, char_u *bufp, size_t bufsize, long  Prenum) {
    size_t len = STRLEN (cmd);
    STRCPY (bufp, cmd);
    if (Prenum > 0)
        vim_snprintf ((char *) bufp + len, bufsize -len, "%ld", Prenum);
}

static void win_goto_ver (int up, long  count) {
    frame_T *fr;
    frame_T *nfr;
    frame_T *foundfr;
    foundfr = curwin->w_frame;
    while (count--) {
        fr = foundfr;
        for (;;) {
            if (fr == topframe)
                goto end;
            if (up)
                nfr = fr->fr_prev;
            else
                nfr = fr->fr_next;
            if (fr->fr_parent->fr_layout == FR_COL && nfr != NULL)
                break;
            fr = fr->fr_parent;
        }
        for (;;) {
            if (nfr->fr_layout == FR_LEAF) {
                foundfr = nfr;
                break;
            }
            fr = nfr->fr_child;
            if (nfr->fr_layout == FR_ROW) {
                while (fr->fr_next != NULL && frame2win (fr)->w_wincol + fr->fr_width <= curwin->w_wincol + curwin->w_wcol)
                    fr = fr->fr_next;
            }
            if (nfr->fr_layout == FR_COL && up)
                while (fr->fr_next != NULL)
                    fr = fr->fr_next;
            nfr = fr;
        }
    }
end :
    if (foundfr != NULL)
        win_goto (foundfr->fr_win);
}

static void win_goto_hor (int left, long  count) {
    frame_T *fr;
    frame_T *nfr;
    frame_T *foundfr;
    foundfr = curwin->w_frame;
    while (count--) {
        fr = foundfr;
        for (;;) {
            if (fr == topframe)
                goto end;
            if (left)
                nfr = fr->fr_prev;
            else
                nfr = fr->fr_next;
            if (fr->fr_parent->fr_layout == FR_ROW && nfr != NULL)
                break;
            fr = fr->fr_parent;
        }
        for (;;) {
            if (nfr->fr_layout == FR_LEAF) {
                foundfr = nfr;
                break;
            }
            fr = nfr->fr_child;
            if (nfr->fr_layout == FR_COL) {
                while (fr->fr_next != NULL && frame2win (fr)->w_winrow + fr->fr_height <= curwin->w_winrow + curwin->w_wrow)
                    fr = fr->fr_next;
            }
            if (nfr->fr_layout == FR_ROW && left)
                while (fr->fr_next != NULL)
                    fr = fr->fr_next;
            nfr = fr;
        }
    }
end :
    if (foundfr != NULL)
        win_goto (foundfr->fr_win);
}

static void win_exchange (long  Prenum) {
    frame_T *frp;
    frame_T *frp2;
    win_T *wp;
    win_T *wp2;
    int temp;
    if (ONE_WINDOW) {
        beep_flush ();
        return;
    }
    need_mouse_correct = TRUE;
    if (Prenum) {
        frp = curwin->w_frame->fr_parent->fr_child;
        while (frp != NULL && --Prenum > 0)
            frp = frp->fr_next;
    }
    else if (curwin->w_frame->fr_next != NULL)
        frp = curwin->w_frame->fr_next;
    else
        frp = curwin->w_frame->fr_prev;
    if (frp == NULL || frp->fr_win == NULL || frp->fr_win == curwin)
        return;
    wp = frp->fr_win;
    wp2 = curwin->w_prev;
    frp2 = curwin->w_frame->fr_prev;
    if (wp->w_prev != curwin) {
        win_remove (curwin, NULL);
        frame_remove (curwin -> w_frame);
        win_append (wp -> w_prev, curwin);
        frame_insert (frp, curwin -> w_frame);
    }
    if (wp != wp2) {
        win_remove (wp, NULL);
        frame_remove (wp -> w_frame);
        win_append (wp2, wp);
        if (frp2 == NULL)
            frame_insert (wp->w_frame->fr_parent->fr_child, wp->w_frame);
        else
            frame_append (frp2, wp->w_frame);
    }
    temp = curwin->w_status_height;
    curwin->w_status_height = wp->w_status_height;
    wp->w_status_height = temp;
    temp = curwin->w_vsep_width;
    curwin->w_vsep_width = wp->w_vsep_width;
    wp->w_vsep_width = temp;
    if (curwin->w_frame->fr_parent != wp->w_frame->fr_parent) {
        temp = curwin->w_height;
        curwin->w_height = wp->w_height;
        wp->w_height = temp;
        temp = curwin->w_width;
        curwin->w_width = wp->w_width;
        wp->w_width = temp;
    }
    else {
        frame_fix_height (curwin);
        frame_fix_height (wp);
        frame_fix_width (curwin);
        frame_fix_width (wp);
    }
    (void) win_comp_pos ();
    win_enter (wp, TRUE);
    redraw_later (CLEAR);
}

static void win_rotate (int upwards, int count) {
    win_T *wp1;
    win_T *wp2;
    frame_T *frp;
    int n;
    if (ONE_WINDOW) {
        beep_flush ();
        return;
    }
    need_mouse_correct = TRUE;
    for (frp = curwin->w_frame->fr_parent->fr_child; frp != NULL; frp = frp->fr_next)
        if (frp->fr_win == NULL) {
            EMSG (_ ("E443: Cannot rotate when another window is split"));
            return;
        }
    while (count--) {
        if (upwards) {
            frp = curwin->w_frame->fr_parent->fr_child;
            wp1 = frp->fr_win;
            win_remove (wp1, NULL);
            frame_remove (frp);
            for (; frp->fr_next != NULL; frp = frp->fr_next)
                ;
            win_append (frp -> fr_win, wp1);
            frame_append (frp, wp1 -> w_frame);
            wp2 = frp->fr_win;
        }
        else {
            for (frp = curwin->w_frame; frp->fr_next != NULL; frp = frp->fr_next)
                ;
            wp1 = frp->fr_win;
            wp2 = wp1->w_prev;
            win_remove (wp1, NULL);
            frame_remove (frp);
            win_append (frp -> fr_parent -> fr_child -> fr_win -> w_prev, wp1);
            frame_insert (frp -> fr_parent -> fr_child, frp);
        }
        n = wp2->w_status_height;
        wp2->w_status_height = wp1->w_status_height;
        wp1->w_status_height = n;
        frame_fix_height (wp1);
        frame_fix_height (wp2);
        n = wp2->w_vsep_width;
        wp2->w_vsep_width = wp1->w_vsep_width;
        wp1->w_vsep_width = n;
        frame_fix_width (wp1);
        frame_fix_width (wp2);
        (void) win_comp_pos ();
    }
    redraw_later (CLEAR);
}

static void win_totop (int size, int flags) {
    int dir;
    int height = curwin->w_height;
    if (ONE_WINDOW) {
        beep_flush ();
        return;
    }
    (void) winframe_remove (curwin, &dir, NULL);
    win_remove (curwin, NULL);
    last_status (FALSE);
    (void) win_comp_pos ();
    (void) win_split_ins (size, flags, curwin, dir);
    if (!(flags & WSP_VERT)) {
        win_setheight (height);
        if (p_ea)
            win_equal (curwin, TRUE, 'v');
    }
    gui_may_update_scrollbars ();
}

