
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
struct initmap {
    char_u *arg;
    int mode;
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
int expand_isabbrev = 0;
EXTERN long  p_verbose;
EXTERN int p_altkeymap;
mapblock_T *first_abbr = NULL;
EXTERN int p_im;
EXTERN long  p_mmd;
int KeyNoremap = 0;
EXTERN int KeyTyped;
mapblock_T * (maphash [256]);
EXTERN char_u *p_pt;
EXTERN int p_remap;
EXTERN int p_paste;
EXTERN int p_lz;
EXTERN int p_smd;
EXTERN int KeyStuffed;
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
EXTERN char_u *p_titlestring;
EXTERN int arrow_used;
EXTERN int mouse_row;
int old_mouse_row;
EXTERN char_u *globaldir INIT (= NULL);
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
int old_mod_mask;
EXTERN int p_guipty;
EXTERN char_u e_toomanyarg [] INIT (= N_ ("E118: Too many arguments for function: %s"));
EXTERN char_u e_invarg2 [] INIT (= N_ ("E475: Invalid argument: %s"));
EXTERN char_u e_invarg [] INIT (= N_ ("E474: Invalid argument"));
EXTERN char_u e_argreq [] INIT (= N_ ("E471: Argument required"));
EXTERN char_u *edit_submode_extra INIT (= NULL);
EXTERN char_u *edit_submode_pre INIT (= NULL);
EXTERN char_u *edit_submode INIT (= NULL);
int expand_mapmodes = 0;
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
int old_char = -1;
int block_redo = FALSE;
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
struct initmap initmappings [] = {{(char_u *) "<Backspace> \"-d", VIS_SEL},};
int expand_buffer = FALSE;
buffheader_T readbuf2 = {{NULL, {NUL}}, NULL, 0, 0};
buffheader_T readbuf1 = {{NULL, {NUL}}, NULL, 0, 0};
char_u noremapbuf_init [TYPELEN_INIT];
buffheader_T recordbuff = {{NULL, {NUL}}, NULL, 0, 0};
buffheader_T old_redobuff = {{NULL, {NUL}}, NULL, 0, 0};
buffheader_T redobuff = {{NULL, {NUL}}, NULL, 0, 0};
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
int maphash_valid = FALSE;
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
typebuf_T saved_typebuf [NSCRIPT];
char_u typebuf_init [TYPELEN_INIT];
int typeahead_char = 0;
EXTERN int searchcmdlen;
EXTERN long  p_titlelen;
int last_recorded_len = 0;
EXTERN int sc_col;
EXTERN int ru_col;
EXTERN int mouse_col;
EXTERN colnr_T search_match_endcol;
EXTERN int msg_col;
EXTERN int p_cc_cols [256];
EXTERN long  p_columnspace;
EXTERN int fuoptions_bgcolor;
int old_mouse_col;
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

void saveRedobuff (save_redo_T *save_redo) {
    char_u *s;
    save_redo->sr_redobuff = redobuff;
    redobuff.bh_first.b_next = NULL;
    save_redo->sr_old_redobuff = old_redobuff;
    old_redobuff.bh_first.b_next = NULL;
    s = get_buffcont (&save_redo->sr_redobuff, FALSE);
    if (s != NULL) {
        add_buff (& redobuff, s, - 1L);
        vim_free (s);
    }
}

static char_u *get_buffcont (buffheader_T *buffer, int dozero) {
    long_u count = 0;
    char_u *p = NULL;
    char_u *p2;
    char_u *str;
    buffblock_T *bp;
    for (bp = buffer->bh_first.b_next; bp != NULL; bp = bp->b_next)
        count += (long_u) STRLEN (bp->b_str);
    if ((count || dozero) && (p = lalloc (count +1, TRUE)) != NULL) {
        p2 = p;
        for (bp = buffer->bh_first.b_next; bp != NULL; bp = bp->b_next)
            for (str = bp->b_str; *str;)
                *p2++ = *str++;
        *p2 = NUL;
    }
    return (p);
}

static void add_buff (buffheader_T *buf, char_u *s, long  slen) {
    buffblock_T *p;
    long_u len;
    if (slen < 0)
        slen = (long ) STRLEN (s);
    if (slen == 0)
        return;
    if (buf->bh_first.b_next == NULL) {
        buf->bh_space = 0;
        buf->bh_curr = &(buf->bh_first);
    }
    else if (buf->bh_curr == NULL) {
        IEMSG (_ ("E222: Add to read buffer"));
        return;
    }
    else if (buf->bh_index != 0)
        mch_memmove (buf->bh_first.b_next->b_str, buf->bh_first.b_next->b_str + buf->bh_index, STRLEN (buf->bh_first.b_next->b_str + buf->bh_index) + 1);
    buf->bh_index = 0;
    if (buf->bh_space >= (int) slen) {
        len = (long_u) STRLEN (buf->bh_curr->b_str);
        vim_strncpy (buf -> bh_curr -> b_str + len, s, (size_t) slen);
        buf->bh_space -= slen;
    }
    else {
        if (slen < MINIMAL_SIZE)
            len = MINIMAL_SIZE;
        else
            len = slen;
        p = (buffblock_T *) lalloc ((long_u) (sizeof (buffblock_T) + len), TRUE);
        if (p == NULL)
            return;
        buf->bh_space = (int) (len - slen);
        vim_strncpy (p -> b_str, s, (size_t) slen);
        p->b_next = buf->bh_curr->b_next;
        buf->bh_curr->b_next = p;
        buf->bh_curr = p;
    }
    return;
}

void ResetRedobuff (void) {
    if (!block_redo) {
        free_buff (& old_redobuff);
        old_redobuff = redobuff;
        redobuff.bh_first.b_next = NULL;
    }
}

void free_buff (buffheader_T *buf) {
    buffblock_T *p, *np;
    for (p = buf->bh_first.b_next; p != NULL; p = np) {
        np = p->b_next;
        vim_free (p);
    }
    buf->bh_first.b_next = NULL;
}

void AppendCharToRedobuff (int c) {
    if (!block_redo)
        add_char_buff (&redobuff, c);
}

static void add_char_buff (buffheader_T *buf, int c) {
    char_u temp [4];
    if (IS_SPECIAL (c) || c == K_SPECIAL || c == NUL) {
        temp[0] = K_SPECIAL;
        temp[1] = K_SECOND (c);
        temp[2] = K_THIRD (c);
        temp[3] = NUL;
    }
    else if (c == CSI) {
        temp[0] = CSI;
        temp[1] = KS_EXTRA;
        temp[2] = (int) KE_CSI;
        temp[3] = NUL;
    }
    else {
        temp[0] = c;
        temp[1] = NUL;
    }
    add_buff (buf, temp, - 1L);
}

void AppendNumberToRedobuff (long  n) {
    if (!block_redo)
        add_num_buff (&redobuff, n);
}

static void add_num_buff (buffheader_T *buf, long  n) {
    char_u number [32];
    sprintf ((char *) number, "%ld", n);
    add_buff (buf, number, - 1L);
}

void AppendToRedobuffLit (char_u *str, int len) {
    char_u *s = str;
    int c;
    char_u *start;
    if (block_redo)
        return;
    while (len < 0 ? *s != NUL : s - str < len) {
        start = s;
        while (*s >= ' ' && *s < DEL && (len < 0 || s - str < len))
            ++s;
        if (*s == NUL && (s[-1] == '0' || s[-1] == '^'))
            --s;
        if (s > start)
            add_buff (&redobuff, start, (long ) (s - start));
        if (*s == NUL || (len >= 0 && s - str >= len))
            break;
        c = *s++;
        if (c < ' ' || c == DEL || (*s == NUL && (c == '0' || c == '^')))
            add_char_buff (&redobuff, Ctrl_V);
        if (*s == NUL && c == '0')
            add_buff (&redobuff, (char_u *) "048", 3L);
        else
            add_char_buff (&redobuff, c);
    }
}

void AppendToRedobuff (char_u *s) {
    if (!block_redo)
        add_buff (&redobuff, s, -1L);
}

int char_avail (void) {
    int retval;
    if (disable_char_avail_for_testing)
        return FALSE;
    ++no_mapping;
    retval = vpeekc ();
    --no_mapping;
    return (retval != NUL);
}

int vpeekc (void) {
    if (old_char != -1)
        return old_char;
    return vgetorpeek (FALSE);
}

static int vgetorpeek (int advance) {
    int c, c1;
    int keylen;
    char_u *s;
    mapblock_T *mp;
    mapblock_T *mp2;
    mapblock_T *mp_match;
    int mp_match_len = 0;
    int timedout = FALSE;
    int mapdepth = 0;
    int mode_deleted = FALSE;
    int local_State;
    int mlen;
    int max_mlen;
    int i;
    int new_wcol, new_wrow;
    int idx;
    int shape_changed = FALSE;
    int n;
    int nolmaplen;
    int old_wcol, old_wrow;
    int wait_tb_len;
    if (vgetc_busy > 0 && ex_normal_busy == 0)
        return NUL;
    local_State = get_real_state ();
    ++vgetc_busy;
    if (advance)
        KeyStuffed = FALSE;
    init_typebuf ();
    start_stuff ();
    if (advance && typebuf.tb_maplen == 0)
        Exec_reg = FALSE;
    do {
        if (typeahead_char != 0) {
            c = typeahead_char;
            if (advance)
                typeahead_char = 0;
        }
        else
            c = read_readbuffers (advance);
        if (c != NUL && !got_int) {
            if (advance) {
                KeyStuffed = TRUE;
            }
            if (typebuf.tb_no_abbr_cnt == 0)
                typebuf.tb_no_abbr_cnt = 1;
        }
        else {
            for (;;) {
                if (typebuf.tb_maplen)
                    line_breakcheck ();
                else
                    ui_breakcheck ();
                keylen = 0;
                if (got_int) {
                    c = inchar (typebuf.tb_buf, typebuf.tb_buflen - 1, 0L);
                    if ((c || typebuf.tb_maplen) && (State & (INSERT + CMDLINE)))
                        c = ESC;
                    else
                        c = Ctrl_C;
                    flush_buffers (TRUE);
                    if (advance) {
                        *typebuf.tb_buf = c;
                        gotchars (typebuf.tb_buf, 1);
                    }
                    cmd_silent = FALSE;
                    break;
                }
                else if (typebuf.tb_len > 0) {
                    mp = NULL;
                    max_mlen = 0;
                    c1 = typebuf.tb_buf[typebuf.tb_off];
                    if (no_mapping == 0 && maphash_valid && (no_zero_mapping == 0 || c1 != '0') && (typebuf.tb_maplen == 0 || (p_remap && (typebuf.tb_noremap[typebuf.tb_off] & (RM_NONE | RM_ABBR)) == 0)) && !(p_paste && (State & (INSERT + CMDLINE))) && !(State == HITRETURN && (c1 == CAR || c1 == ' ')) && State != ASKMORE && State != CONFIRM && !((ctrl_x_mode_not_default () && vim_is_ctrl_x_key (c1)) || ((compl_cont_status & CONT_LOCAL) && (c1 == Ctrl_N || c1 == Ctrl_P)))) {
                        if (c1 == K_SPECIAL)
                            nolmaplen = 2;
                        else {
                            LANGMAP_ADJUST (c1, (State & (CMDLINE | INSERT)) == 0 && get_real_state () != SELECTMODE);
                            nolmaplen = 0;
                        }
                        mp = curbuf->b_maphash[MAP_HASH (local_State, c1)];
                        mp2 = maphash[MAP_HASH (local_State, c1)];
                        if (mp == NULL) {
                            mp = mp2;
                            mp2 = NULL;
                        }
                        mp_match = NULL;
                        mp_match_len = 0;
                        for (; mp != NULL; mp->m_next == NULL ? (mp = mp2, mp2 = NULL) : (mp = mp->m_next)) {
                            if (mp->m_keys[0] == c1 && (mp->m_mode & local_State) && ((mp->m_mode & LANGMAP) == 0 || typebuf.tb_maplen == 0)) {
                                int nomap = nolmaplen;
                                int c2;
                                for (mlen = 1; mlen < typebuf.tb_len; ++mlen) {
                                    c2 = typebuf.tb_buf[typebuf.tb_off + mlen];
                                    if (nomap > 0)
                                        --nomap;
                                    else if (c2 == K_SPECIAL)
                                        nomap = 2;
                                    else
                                        LANGMAP_ADJUST (c2, TRUE);
                                    if (mp->m_keys[mlen] != c2)
                                        break;
                                }
                                keylen = mp->m_keylen;
                                if (mlen == keylen || (mlen == typebuf.tb_len && typebuf.tb_len < keylen)) {
                                    s = typebuf.tb_noremap + typebuf.tb_off;
                                    if (*s == RM_SCRIPT && (mp->m_keys[0] != K_SPECIAL || mp->m_keys[1] != KS_EXTRA || mp->m_keys[2] != (int) KE_SNR))
                                        continue;
                                    for (n = mlen; --n >= 0;)
                                        if (*s++ & (RM_NONE | RM_ABBR))
                                            break;
                                    if (n >= 0)
                                        continue;
                                    if (keylen > typebuf.tb_len) {
                                        if (!timedout && !(mp_match != NULL && mp_match->m_nowait)) {
                                            keylen = KEYLEN_PART_MAP;
                                            break;
                                        }
                                    }
                                    else if (keylen > mp_match_len) {
                                        mp_match = mp;
                                        mp_match_len = keylen;
                                    }
                                }
                                else if (max_mlen < mlen)
                                    max_mlen = mlen;
                            }
                        }
                        if (keylen != KEYLEN_PART_MAP) {
                            mp = mp_match;
                            keylen = mp_match_len;
                        }
                    }
                    if (*p_pt != NUL && mp == NULL && (State & (INSERT | NORMAL))) {
                        for (mlen = 0; mlen < typebuf.tb_len && p_pt[mlen]; ++mlen)
                            if (p_pt[mlen] != typebuf.tb_buf[typebuf.tb_off + mlen])
                                break;
                        if (p_pt[mlen] == NUL) {
                            if (mlen > typebuf.tb_maplen)
                                gotchars (typebuf.tb_buf + typebuf.tb_off + typebuf.tb_maplen, mlen -typebuf.tb_maplen);
                            del_typebuf (mlen, 0);
                            set_option_value ((char_u *) "paste", (long) ! p_paste, NULL, 0);
                            if (!(State & INSERT)) {
                                msg_col = 0;
                                msg_row = Rows - 1;
                                msg_clr_eos ();
                            }
                            status_redraw_all ();
                            redraw_statuslines ();
                            showmode ();
                            setcursor ();
                            continue;
                        }
                        if (mlen == typebuf.tb_len)
                            keylen = KEYLEN_PART_KEY;
                        else if (max_mlen < mlen)
                            max_mlen = mlen + 1;
                    }
                    if ((mp == NULL || max_mlen >= mp_match_len) && keylen != KEYLEN_PART_MAP) {
                        int save_keylen = keylen;
                        if ((no_mapping == 0 || allow_keys != 0) && (typebuf.tb_maplen == 0 || (p_remap && typebuf.tb_noremap[typebuf.tb_off] == RM_YES)) && !timedout) {
                            keylen = check_termcode (max_mlen +1, NULL, 0, NULL);
                            if (keylen == 0 && save_keylen == KEYLEN_PART_KEY)
                                keylen = KEYLEN_PART_KEY;
                            if (keylen < 0 && typebuf.tb_len == typebuf.tb_maplen)
                                keylen = 0;
                        }
                        else
                            keylen = 0;
                        if (keylen == 0) {
                            if (mp == NULL) {
                                c = typebuf.tb_buf[typebuf.tb_off] & 255;
                                if (advance) {
                                    cmd_silent = (typebuf.tb_silent > 0);
                                    if (typebuf.tb_maplen > 0)
                                        KeyTyped = FALSE;
                                    else {
                                        KeyTyped = TRUE;
                                        gotchars (typebuf.tb_buf + typebuf.tb_off, 1);
                                    }
                                    KeyNoremap = typebuf.tb_noremap[typebuf.tb_off];
                                    del_typebuf (1, 0);
                                }
                                break;
                            }
                        }
                        if (keylen > 0) {
                            if (typebuf.tb_len >= 2 && typebuf.tb_buf[typebuf.tb_off] == K_SPECIAL && typebuf.tb_buf[typebuf.tb_off + 1] == KS_MENU) {
                                may_sync_undo ();
                                del_typebuf (3, 0);
                                idx = get_menu_index (current_menu, local_State);
                                if (idx != MENU_INDEX_INVALID) {
                                    if (VIsual_active && VIsual_select && (current_menu->modes & VISUAL)) {
                                        VIsual_select = FALSE;
                                        (void) ins_typebuf (K_SELECT_STRING, REMAP_NONE, 0, TRUE, FALSE);
                                    }
                                    ins_typebuf (current_menu -> strings [idx], current_menu -> noremap [idx], 0, TRUE, current_menu -> silent [idx]);
                                }
                            }
                            continue;
                        }
                        if (mp == NULL || keylen < 0)
                            keylen = KEYLEN_PART_KEY;
                        else
                            keylen = mp_match_len;
                    }
                    if (keylen >= 0 && keylen <= typebuf.tb_len) {
                        int save_m_expr;
                        int save_m_noremap;
                        int save_m_silent;
                        char_u *save_m_keys;
                        char_u *save_m_str;
                        if (keylen > typebuf.tb_maplen)
                            gotchars (typebuf.tb_buf + typebuf.tb_off + typebuf.tb_maplen, keylen -typebuf.tb_maplen);
                        cmd_silent = (typebuf.tb_silent > 0);
                        del_typebuf (keylen, 0);
                        if (++mapdepth >= p_mmd) {
                            EMSG (_ ("E223: recursive mapping"));
                            if (State & CMDLINE)
                                redrawcmdline ();
                            else
                                setcursor ();
                            flush_buffers (FALSE);
                            mapdepth = 0;
                            c = -1;
                            break;
                        }
                        if (VIsual_active && VIsual_select && (mp->m_mode & VISUAL)) {
                            VIsual_select = FALSE;
                            (void) ins_typebuf (K_SELECT_STRING, REMAP_NONE, 0, TRUE, FALSE);
                        }
                        save_m_expr = mp->m_expr;
                        save_m_noremap = mp->m_noremap;
                        save_m_silent = mp->m_silent;
                        save_m_keys = NULL;
                        save_m_str = NULL;
                        if (mp->m_expr) {
                            int save_vgetc_busy = vgetc_busy;
                            vgetc_busy = 0;
                            save_m_keys = vim_strsave (mp->m_keys);
                            save_m_str = vim_strsave (mp->m_str);
                            s = eval_map_expr (save_m_str, NUL);
                            vgetc_busy = save_vgetc_busy;
                        }
                        else
                            s = mp->m_str;
                        if (s == NULL)
                            i = FAIL;
                        else {
                            int noremap;
                            if (save_m_noremap != REMAP_YES)
                                noremap = save_m_noremap;
                            else if (STRNCMP (s, save_m_keys != NULL ? save_m_keys : mp->m_keys, (size_t) keylen) != 0)
                                noremap = REMAP_YES;
                            else
                                noremap = REMAP_SKIP;
                            i = ins_typebuf (s, noremap, 0, TRUE, cmd_silent || save_m_silent);
                            if (save_m_expr)
                                vim_free (s);
                        }
                        vim_free (save_m_keys);
                        vim_free (save_m_str);
                        if (i == FAIL) {
                            c = -1;
                            break;
                        }
                        continue;
                    }
                }
                c = 0;
                new_wcol = curwin->w_wcol;
                new_wrow = curwin->w_wrow;
                if (advance && typebuf.tb_len == 1 && typebuf.tb_buf[typebuf.tb_off] == ESC && !no_mapping && ex_normal_busy == 0 && typebuf.tb_maplen == 0 && (State & INSERT) && (p_timeout || (keylen == KEYLEN_PART_KEY && p_ttimeout)) && (c = inchar (typebuf.tb_buf + typebuf.tb_off + typebuf.tb_len, 3, 25L)) == 0) {
                    colnr_T col = 0, vcol;
                    char_u *ptr;
                    if (mode_displayed) {
                        unshowmode (TRUE);
                        mode_deleted = TRUE;
                    }
                    if (gui.in_use && State != NORMAL && !cmd_silent) {
                        int save_State;
                        save_State = State;
                        State = NORMAL;
                        gui_update_cursor (TRUE, FALSE);
                        State = save_State;
                        shape_changed = TRUE;
                    }
                    validate_cursor ();
                    old_wcol = curwin->w_wcol;
                    old_wrow = curwin->w_wrow;
                    if (curwin->w_cursor.col != 0) {
                        if (curwin->w_wcol > 0) {
                            if (did_ai) {
                                col = vcol = curwin->w_wcol = 0;
                                ptr = ml_get_curline ();
                                while (col < curwin->w_cursor.col) {
                                    if (!VIM_ISWHITE (ptr[col]))
                                        curwin->w_wcol = vcol;
                                    vcol += lbr_chartabsize (ptr, ptr +col, (colnr_T) vcol);
                                    ++col;
                                }
                                curwin->w_wrow = curwin->w_cline_row + curwin->w_wcol / curwin->w_width;
                                curwin->w_wcol %= curwin->w_width;
                                curwin->w_wcol += curwin_col_off ();
                            }
                            else {
                                --curwin->w_wcol;
                            }
                        }
                        else if (curwin->w_p_wrap && curwin->w_wrow) {
                            --curwin->w_wrow;
                            curwin->w_wcol = curwin->w_width - 1;
                        }
                    }
                    setcursor ();
                    out_flush ();
                    new_wcol = curwin->w_wcol;
                    new_wrow = curwin->w_wrow;
                    curwin->w_wcol = old_wcol;
                    curwin->w_wrow = old_wrow;
                }
                if (c < 0)
                    continue;
                for (n = 1; n <= c; ++n)
                    typebuf.tb_noremap[typebuf.tb_off + n] = RM_YES;
                typebuf.tb_len += c;
                if (typebuf.tb_len >= typebuf.tb_maplen + MAXMAPLEN) {
                    timedout = TRUE;
                    continue;
                }
                if (ex_normal_busy > 0) {
                    if (typebuf.tb_len > 0) {
                        timedout = TRUE;
                        continue;
                    }
                    if (p_im && (State & INSERT))
                        c = Ctrl_L;
                    else if ((State & CMDLINE))
                        c = Ctrl_C;
                    else
                        c = ESC;
                    break;
                }
                if (((State & INSERT) != 0 || p_lz) && (State & CMDLINE) == 0 && advance && must_redraw != 0 && !need_wait_return) {
                    update_screen (0);
                    setcursor ();
                }
                i = 0;
                c1 = 0;
                if (typebuf.tb_len > 0 && advance && !exmode_active) {
                    if (((State & (NORMAL | INSERT)) || State == LANGMAP) && State != HITRETURN) {
                        if (State & INSERT && ptr2cells (typebuf.tb_buf + typebuf.tb_off + typebuf.tb_len - 1) == 1) {
                            edit_putchar (typebuf.tb_buf [typebuf.tb_off + typebuf.tb_len - 1], FALSE);
                            setcursor ();
                            c1 = 1;
                        }
                        old_wcol = curwin->w_wcol;
                        old_wrow = curwin->w_wrow;
                        curwin->w_wcol = new_wcol;
                        curwin->w_wrow = new_wrow;
                        push_showcmd ();
                        if (typebuf.tb_len > SHOWCMD_COLS)
                            i = typebuf.tb_len - SHOWCMD_COLS;
                        while (i < typebuf.tb_len)
                            (void) add_to_showcmd (typebuf.tb_buf[typebuf.tb_off + i++]);
                        curwin->w_wcol = old_wcol;
                        curwin->w_wrow = old_wrow;
                    }
                    if ((State & CMDLINE) && cmdline_star == 0 && ptr2cells (typebuf.tb_buf + typebuf.tb_off + typebuf.tb_len - 1) == 1) {
                        putcmdline (typebuf.tb_buf [typebuf.tb_off + typebuf.tb_len - 1], FALSE);
                        c1 = 1;
                    }
                }
                wait_tb_len = typebuf.tb_len;
                c = inchar (typebuf.tb_buf + typebuf.tb_off + typebuf.tb_len, typebuf.tb_buflen - typebuf.tb_off - typebuf.tb_len - 1, !advance ? 0 : ((typebuf.tb_len == 0 || !(p_timeout || (p_ttimeout && keylen == KEYLEN_PART_KEY))) ? -1L : ((keylen == KEYLEN_PART_KEY && p_ttm >= 0) ? p_ttm : p_tm)));
                if (i != 0)
                    pop_showcmd ();
                if (c1 == 1) {
                    if (State & INSERT)
                        edit_unputchar ();
                    if (State & CMDLINE)
                        unputcmdline ();
                    else
                        setcursor ();
                }
                if (c < 0)
                    continue;
                if (c == NUL) {
                    if (!advance)
                        break;
                    if (wait_tb_len > 0) {
                        timedout = TRUE;
                        continue;
                    }
                }
                else {
                    while (typebuf.tb_buf[typebuf.tb_off + typebuf.tb_len] != NUL)
                        typebuf.tb_noremap[typebuf.tb_off + typebuf.tb_len++] = RM_YES;
                }
            }
        }
    }
    while (c < 0 || (advance && c == NUL));
    if (advance && p_smd && msg_silent == 0 && (State & INSERT)) {
        if (c == ESC && !mode_deleted && !no_mapping && mode_displayed) {
            if (typebuf.tb_len && !KeyTyped)
                redraw_cmdline = TRUE;
            else
                unshowmode (FALSE);
        }
        else if (c != ESC && mode_deleted) {
            if (typebuf.tb_len && !KeyTyped)
                redraw_cmdline = TRUE;
            else
                showmode ();
        }
    }
    if (gui.in_use && shape_changed)
        gui_update_cursor (TRUE, FALSE);
    --vgetc_busy;
    return c;
}

static void init_typebuf (void) {
    if (typebuf.tb_buf == NULL) {
        typebuf.tb_buf = typebuf_init;
        typebuf.tb_noremap = noremapbuf_init;
        typebuf.tb_buflen = TYPELEN_INIT;
        typebuf.tb_len = 0;
        typebuf.tb_off = MAXMAPLEN + 4;
        typebuf.tb_change_cnt = 1;
    }
}

static void start_stuff (void) {
    if (readbuf1.bh_first.b_next != NULL) {
        readbuf1.bh_curr = &(readbuf1.bh_first);
        readbuf1.bh_space = 0;
    }
    if (readbuf2.bh_first.b_next != NULL) {
        readbuf2.bh_curr = &(readbuf2.bh_first);
        readbuf2.bh_space = 0;
    }
}

static int read_readbuffers (int advance) {
    int c;
    c = read_readbuf (&readbuf1, advance);
    if (c == NUL)
        c = read_readbuf (&readbuf2, advance);
    return c;
}

static int read_readbuf (buffheader_T *buf, int advance) {
    char_u c;
    buffblock_T *curr;
    if (buf->bh_first.b_next == NULL)
        return NUL;
    curr = buf->bh_first.b_next;
    c = curr->b_str[buf->bh_index];
    if (advance) {
        if (curr->b_str[++buf->bh_index] == NUL) {
            buf->bh_first.b_next = curr->b_next;
            vim_free (curr);
            buf->bh_index = 0;
        }
    }
    return c;
}

static int inchar (char_u *buf, int maxlen, long  wait_time) {
    int len = 0;
    int retesc = FALSE;
    int script_char;
    int tb_change_cnt = typebuf.tb_change_cnt;
    if (wait_time == -1L || wait_time > 100L) {
        cursor_on ();
        out_flush_cursor (FALSE, FALSE);
        if (gui.in_use && postponed_mouseshape)
            update_mouseshape (-1);
    }
    if (State != HITRETURN) {
        did_outofmem_msg = FALSE;
        did_swapwrite_msg = FALSE;
    }
    undo_off = FALSE;
    script_char = -1;
    while (scriptin[curscript] != NULL && script_char < 0 && !ignore_script) {
        if (got_int || (script_char = getc (scriptin[curscript])) < 0) {
            closescript ();
            if (got_int)
                retesc = TRUE;
            else
                return -1;
        }
        else {
            buf[0] = script_char;
            len = 1;
        }
    }
    if (script_char < 0) {
        if (got_int) {

            #define DUM_LEN MAXMAPLEN * 3 + 3
            char_u dum [DUM_LEN + 1];
            for (;;) {
                len = ui_inchar (dum, DUM_LEN, 0L, 0);
                if (len == 0 || (len == 1 && dum[0] == 3))
                    break;
            }
            return retesc;
        }
        out_flush ();
        len = ui_inchar (buf, maxlen / 3, wait_time, tb_change_cnt);
    }
    if (typebuf_changed (tb_change_cnt))
        return 0;
    if (len > 0 && ++typebuf.tb_change_cnt == 0)
        typebuf.tb_change_cnt = 1;
    return fix_input_buffer (buf, len);
}

int vpeekc_nomap (void) {
    int c;
    ++no_mapping;
    ++allow_keys;
    c = vpeekc ();
    --no_mapping;
    --allow_keys;
    return c;
}

int vgetc (void) {
    int c, c2;
    if (may_garbage_collect && want_garbage_collect)
        garbage_collect (FALSE);
    if (old_char != -1) {
        c = old_char;
        old_char = -1;
        mod_mask = old_mod_mask;
        mouse_row = old_mouse_row;
        mouse_col = old_mouse_col;
    }
    else {
        mod_mask = 0x0;
        last_recorded_len = 0;
        for (;;) {
            int did_inc = FALSE;
            if (mod_mask) {
                ++no_mapping;
                ++allow_keys;
                did_inc = TRUE;
            }
            c = vgetorpeek (TRUE);
            if (did_inc) {
                --no_mapping;
                --allow_keys;
            }
            if (c == K_SPECIAL || c == CSI) {
                int save_allow_keys = allow_keys;
                ++no_mapping;
                allow_keys = 0;
                c2 = vgetorpeek (TRUE);
                c = vgetorpeek (TRUE);
                --no_mapping;
                allow_keys = save_allow_keys;
                if (c2 == KS_MODIFIER) {
                    mod_mask = c;
                    continue;
                }
                c = TO_SPECIAL (c2, c);
                if (c == K_FOCUSGAINED || c == K_FOCUSLOST) {
                    ui_focus_change (c == K_FOCUSGAINED);
                    c = K_IGNORE;
                }
                if (c == K_CSI)
                    c = CSI;
            }
            switch (c) {
            case K_KPLUS :
                c = '+';
                break;
            case K_KMINUS :
                c = '-';
                break;
            case K_KDIVIDE :
                c = '/';
                break;
            case K_KMULTIPLY :
                c = '*';
                break;
            case K_KENTER :
                c = CAR;
                break;
            case K_KPOINT :
                c = '.';
                break;
            case K_K0 :
                c = '0';
                break;
            case K_K1 :
                c = '1';
                break;
            case K_K2 :
                c = '2';
                break;
            case K_K3 :
                c = '3';
                break;
            case K_K4 :
                c = '4';
                break;
            case K_K5 :
                c = '5';
                break;
            case K_K6 :
                c = '6';
                break;
            case K_K7 :
                c = '7';
                break;
            case K_K8 :
                c = '8';
                break;
            case K_K9 :
                c = '9';
                break;
            case K_XHOME :
            case K_ZHOME :
                if (mod_mask == MOD_MASK_SHIFT) {
                    c = K_S_HOME;
                    mod_mask = 0;
                }
                else if (mod_mask == MOD_MASK_CTRL) {
                    c = K_C_HOME;
                    mod_mask = 0;
                }
                else
                    c = K_HOME;
                break;
            case K_XEND :
            case K_ZEND :
                if (mod_mask == MOD_MASK_SHIFT) {
                    c = K_S_END;
                    mod_mask = 0;
                }
                else if (mod_mask == MOD_MASK_CTRL) {
                    c = K_C_END;
                    mod_mask = 0;
                }
                else
                    c = K_END;
                break;
            case K_XUP :
                c = K_UP;
                break;
            case K_XDOWN :
                c = K_DOWN;
                break;
            case K_XLEFT :
                c = K_LEFT;
                break;
            case K_XRIGHT :
                c = K_RIGHT;
                break;
            }
            break;
        }
    }
    may_garbage_collect = FALSE;
    if (c != K_MOUSEMOVE && c != K_IGNORE) {
        bevalexpr_due_set = FALSE;
        ui_remove_balloon ();
    }
    return c;
}

int stuff_empty (void) {
    return (readbuf1.bh_first.b_next == NULL && readbuf2.bh_first.b_next == NULL);
}

int typebuf_typed (void) {
    return typebuf.tb_maplen == 0;
}

void map_clear_int (buf_T *buf, int mode, int local, int abbr) {
    mapblock_T *mp, **mpp;
    int hash;
    int new_hash;
    validate_maphash ();
    for (hash = 0; hash < 256; ++hash) {
        if (abbr) {
            if (hash > 0)
                break;
            if (local)
                mpp = &buf->b_first_abbr;
            else
                mpp = &first_abbr;
        }
        else {
            if (local)
                mpp = &buf->b_maphash[hash];
            else
                mpp = &maphash[hash];
        }
        while (*mpp != NULL) {
            mp = *mpp;
            if (mp->m_mode & mode) {
                mp->m_mode &= ~mode;
                if (mp->m_mode == 0) {
                    map_free (mpp);
                    continue;
                }
                new_hash = MAP_HASH (mp->m_mode, mp->m_keys[0]);
                if (!abbr && new_hash != hash) {
                    *mpp = mp->m_next;
                    if (local) {
                        mp->m_next = buf->b_maphash[new_hash];
                        buf->b_maphash[new_hash] = mp;
                    }
                    else {
                        mp->m_next = maphash[new_hash];
                        maphash[new_hash] = mp;
                    }
                    continue;
                }
            }
            mpp = &(mp->m_next);
        }
    }
}

static void validate_maphash (void) {
    if (!maphash_valid) {
        vim_memset (maphash, 0, sizeof (maphash));
        maphash_valid = TRUE;
    }
}

static void map_free (mapblock_T **mpp) {
    mapblock_T *mp;
    mp = *mpp;
    vim_free (mp -> m_keys);
    vim_free (mp -> m_str);
    vim_free (mp -> m_orig_str);
    *mpp = mp->m_next;
    vim_free (mp);
}

void flush_buffers (int flush_typeahead) {
    init_typebuf ();
    start_stuff ();
    while (read_readbuffers (TRUE) != NUL)
        ;
    if (flush_typeahead) {
        while (inchar (typebuf.tb_buf, typebuf.tb_buflen - 1, 10L) != 0)
            ;
        typebuf.tb_off = MAXMAPLEN;
        typebuf.tb_len = 0;
        typebuf_was_filled = FALSE;
    }
    else {
        typebuf.tb_off += typebuf.tb_maplen;
        typebuf.tb_len -= typebuf.tb_maplen;
    }
    typebuf.tb_maplen = 0;
    typebuf.tb_silent = 0;
    cmd_silent = FALSE;
    typebuf.tb_no_abbr_cnt = 0;
}

int safe_vgetc (void) {
    int c;
    c = vgetc ();
    if (c == NUL)
        c = get_keystroke ();
    return c;
}

void before_blocking (void) {
    updatescript (0);
    if (may_garbage_collect)
        garbage_collect (FALSE);
}

void updatescript (int c) {
    static int count = 0;
    if (c && scriptout)
        putc (c, scriptout);
    if (c == 0 || (p_uc > 0 && ++count >= p_uc)) {
        ml_sync_all (c == 0, TRUE);
        count = 0;
    }
}

int typebuf_changed (int tb_change_cnt) {
    return (tb_change_cnt != 0 && (typebuf.tb_change_cnt != tb_change_cnt || typebuf_was_filled));
}

int fix_input_buffer (char_u *buf, int len) {
    int i;
    char_u *p = buf;
    for (i = len; --i >= 0; ++p) {
        if (gui.in_use && p[0] == CSI && i >= 2) {
            p += 2;
            i -= 2;
        }
        else if (!gui.in_use && p[0] == CSI) {
            mch_memmove (p + 3, p + 1, (size_t) i);
            *p++ = K_SPECIAL;
            *p++ = KS_EXTRA;
            *p = (int) KE_CSI;
            len += 2;
        }
        else if (p[0] == NUL || (p[0] == K_SPECIAL && (i < 2 || p[1] != KS_EXTRA || p[2] != (int) KE_CURSORHOLD))) {
            mch_memmove (p + 3, p + 1, (size_t) i);
            p[2] = K_THIRD (p[0]);
            p[1] = K_SECOND (p[0]);
            p[0] = K_SPECIAL;
            p += 2;
            len += 2;
        }
    }
    *p = NUL;
    return len;
}

void ins_char_typebuf (int c) {
    char_u buf [4];
    if (IS_SPECIAL (c)) {
        buf[0] = K_SPECIAL;
        buf[1] = K_SECOND (c);
        buf[2] = K_THIRD (c);
        buf[3] = NUL;
    }
    else {
        buf[0] = c;
        buf[1] = NUL;
    }
    (void) ins_typebuf (buf, KeyNoremap, 0, !KeyTyped, cmd_silent);
}

int ins_typebuf (char_u *str, int noremap, int offset, int nottyped, int silent) {
    char_u *s1, *s2;
    int newlen;
    int addlen;
    int i;
    int newoff;
    int val;
    int nrm;
    init_typebuf ();
    if (++typebuf.tb_change_cnt == 0)
        typebuf.tb_change_cnt = 1;
    addlen = (int) STRLEN (str);
    if (offset == 0 && addlen <= typebuf.tb_off) {
        typebuf.tb_off -= addlen;
        mch_memmove (typebuf.tb_buf + typebuf.tb_off, str, (size_t) addlen);
    }
    else if (typebuf.tb_len == 0 && typebuf.tb_buflen >= addlen + 3 * (MAXMAPLEN + 4)) {
        typebuf.tb_off = (typebuf.tb_buflen - addlen - 3 * (MAXMAPLEN + 4)) / 2;
        mch_memmove (typebuf.tb_buf + typebuf.tb_off, str, (size_t) addlen);
    }
    else {
        newoff = MAXMAPLEN + 4;
        newlen = typebuf.tb_len + addlen + newoff + 4 * (MAXMAPLEN + 4);
        if (newlen < 0) {
            EMSG (_ (e_toocompl));
            setcursor ();
            return FAIL;
        }
        s1 = alloc (newlen);
        if (s1 == NULL)
            return FAIL;
        s2 = alloc (newlen);
        if (s2 == NULL) {
            vim_free (s1);
            return FAIL;
        }
        typebuf.tb_buflen = newlen;
        mch_memmove (s1 + newoff, typebuf.tb_buf + typebuf.tb_off, (size_t) offset);
        mch_memmove (s1 + newoff + offset, str, (size_t) addlen);
        mch_memmove (s1 + newoff + offset + addlen, typebuf.tb_buf + typebuf.tb_off + offset, (size_t) (typebuf.tb_len - offset + 1));
        if (typebuf.tb_buf != typebuf_init)
            vim_free (typebuf.tb_buf);
        typebuf.tb_buf = s1;
        mch_memmove (s2 + newoff, typebuf.tb_noremap + typebuf.tb_off, (size_t) offset);
        mch_memmove (s2 + newoff + offset + addlen, typebuf.tb_noremap + typebuf.tb_off + offset, (size_t) (typebuf.tb_len - offset));
        if (typebuf.tb_noremap != noremapbuf_init)
            vim_free (typebuf.tb_noremap);
        typebuf.tb_noremap = s2;
        typebuf.tb_off = newoff;
    }
    typebuf.tb_len += addlen;
    if (noremap == REMAP_SCRIPT)
        val = RM_SCRIPT;
    else if (noremap == REMAP_SKIP)
        val = RM_ABBR;
    else
        val = RM_NONE;
    if (noremap == REMAP_SKIP)
        nrm = 1;
    else if (noremap < 0)
        nrm = addlen;
    else
        nrm = noremap;
    for (i = 0; i < addlen; ++i)
        typebuf.tb_noremap[typebuf.tb_off + i + offset] = (--nrm >= 0) ? val : RM_YES;
    if (nottyped || typebuf.tb_maplen > offset)
        typebuf.tb_maplen += addlen;
    if (silent || typebuf.tb_silent > offset) {
        typebuf.tb_silent += addlen;
        cmd_silent = TRUE;
    }
    if (typebuf.tb_no_abbr_cnt && offset == 0)
        typebuf.tb_no_abbr_cnt += addlen;
    return OK;
}

int plain_vgetc (void) {
    int c;
    do {
        c = safe_vgetc ();
    }
    while (c == K_IGNORE || c == K_VER_SCROLLBAR || c == K_HOR_SCROLLBAR);
    if (c == K_PS)
        c = bracketed_paste (PASTE_ONE_CHAR, FALSE, NULL);
    return c;
}

int check_abbr (int c, char_u *ptr, int col, int mincol) {
    int len;
    int scol;
    int j;
    char_u *s;
    char_u tb [MB_MAXBYTES + 4];
    mapblock_T *mp;
    mapblock_T *mp2;
    int is_id = TRUE;
    int vim_abbr;
    if (typebuf.tb_no_abbr_cnt)
        return FALSE;
    if ((KeyNoremap & (RM_NONE | RM_SCRIPT)) != 0 && c != Ctrl_RSB)
        return FALSE;
    if (col == 0)
        return FALSE;
    {
        if (!vim_iswordc (ptr[col - 1]))
            vim_abbr = TRUE;
        else {
            vim_abbr = FALSE;
            if (col > 1)
                is_id = vim_iswordc (ptr[col - 2]);
        }
        for (scol = col - 1; scol > 0 && !vim_isspace (ptr[scol - 1]) && (vim_abbr || is_id == vim_iswordc (ptr[scol - 1])); --scol)
            ;
    }
    if (scol < mincol)
        scol = mincol;
    if (scol < col) {
        ptr += scol;
        len = col - scol;
        mp = curbuf->b_first_abbr;
        mp2 = first_abbr;
        if (mp == NULL) {
            mp = mp2;
            mp2 = NULL;
        }
        for (; mp; mp->m_next == NULL ? (mp = mp2, mp2 = NULL) : (mp = mp->m_next)) {
            int qlen = mp->m_keylen;
            char_u *q = mp->m_keys;
            int match;
            if (vim_strbyte (mp->m_keys, K_SPECIAL) != NULL) {
                q = vim_strsave (mp->m_keys);
                if (q != NULL) {
                    vim_unescape_csi (q);
                    qlen = (int) STRLEN (q);
                }
            }
            match = (mp->m_mode & State) && qlen == len && !STRNCMP (q, ptr, (size_t) len);
            if (q != mp->m_keys)
                vim_free (q);
            if (match)
                break;
        }
        if (mp != NULL) {
            j = 0;
            if (c != Ctrl_RSB) {
                if (IS_SPECIAL (c) || c == K_SPECIAL) {
                    tb[j++] = K_SPECIAL;
                    tb[j++] = K_SECOND (c);
                    tb[j++] = K_THIRD (c);
                }
                else {
                    if (c < ABBR_OFF && (c < ' ' || c > '~'))
                        tb[j++] = Ctrl_V;
                    tb[j++] = c;
                }
                tb[j] = NUL;
                (void) ins_typebuf (tb, 1, 0, TRUE, mp->m_silent);
            }
            if (mp->m_expr)
                s = eval_map_expr (mp->m_str, c);
            else
                s = mp->m_str;
            if (s != NULL) {
                (void) ins_typebuf (s, mp->m_noremap, 0, TRUE, mp->m_silent);
                typebuf.tb_no_abbr_cnt += (int) STRLEN (s) + j + 1;
                if (mp->m_expr)
                    vim_free (s);
            }
            tb[0] = Ctrl_H;
            tb[1] = NUL;
            while (len-- > 0)
                (void) ins_typebuf (tb, 1, 0, TRUE, mp->m_silent);
            return TRUE;
        }
    }
    return FALSE;
}

void vim_unescape_csi (char_u *p) {
    char_u *s = p, *d = p;
    while (*s != NUL) {
        if (s[0] == K_SPECIAL && s[1] == KS_SPECIAL && s[2] == KE_FILLER) {
            *d++ = K_SPECIAL;
            s += 3;
        }
        else if ((s[0] == K_SPECIAL || s[0] == CSI) && s[1] == KS_EXTRA && s[2] == (int) KE_CSI) {
            *d++ = CSI;
            s += 3;
        }
        else
            *d++ = *s++;
    }
    *d = NUL;
}

static char_u *eval_map_expr (char_u *str, int c) {
    char_u *res;
    char_u *p;
    char_u *expr;
    char_u *save_cmd;
    pos_T save_cursor;
    int save_msg_col;
    int save_msg_row;
    expr = vim_strsave (str);
    if (expr == NULL)
        return NULL;
    vim_unescape_csi (expr);
    save_cmd = save_cmdline_alloc ();
    if (save_cmd == NULL) {
        vim_free (expr);
        return NULL;
    }
    ++textlock;
    ++ex_normal_lock;
    set_vim_var_char (c);
    save_cursor = curwin->w_cursor;
    save_msg_col = msg_col;
    save_msg_row = msg_row;
    p = eval_to_string (expr, NULL, FALSE);
    --textlock;
    --ex_normal_lock;
    curwin->w_cursor = save_cursor;
    msg_col = save_msg_col;
    msg_row = save_msg_row;
    restore_cmdline_alloc (save_cmd);
    vim_free (expr);
    if (p == NULL)
        return NULL;
    res = vim_strsave_escape_csi (p);
    vim_free (p);
    return res;
}

char_u *vim_strsave_escape_csi (char_u *p) {
    char_u *res;
    char_u *s, *d;
    res = alloc ((unsigned ) (STRLEN (p) * 3) + 1);
    if (res != NULL) {
        d = res;
        for (s = p; *s != NUL;) {
            if (s[0] == K_SPECIAL && s[1] != NUL && s[2] != NUL) {
                *d++ = *s++;
                *d++ = *s++;
                *d++ = *s++;
            }
            else {
                d = add_char2buf (PTR2CHAR (s), d);
                s += MB_CPTR2LEN (s);
            }
        }
        *d = NUL;
    }
    return res;
}

int do_map (int maptype, char_u *arg, int mode, int abbrev) {
    char_u *keys;
    mapblock_T *mp, **mpp;
    char_u *rhs;
    char_u *p;
    int n;
    int len = 0;
    char_u *newstr;
    int hasarg;
    int haskey;
    int did_it = FALSE;
    int did_local = FALSE;
    int round;
    char_u *keys_buf = NULL;
    char_u *arg_buf = NULL;
    int retval = 0;
    int do_backslash;
    int hash;
    int new_hash;
    mapblock_T **abbr_table;
    mapblock_T **map_table;
    int unique = FALSE;
    int nowait = FALSE;
    int silent = FALSE;
    int special = FALSE;
    int expr = FALSE;
    int noremap;
    char_u *orig_rhs;
    keys = arg;
    map_table = maphash;
    abbr_table = &first_abbr;
    if (maptype == 2)
        noremap = REMAP_NONE;
    else
        noremap = REMAP_YES;
    for (;;) {
        if (STRNCMP (keys, "<buffer>", 8) == 0) {
            keys = skipwhite (keys +8);
            map_table = curbuf->b_maphash;
            abbr_table = &curbuf->b_first_abbr;
            continue;
        }
        if (STRNCMP (keys, "<nowait>", 8) == 0) {
            keys = skipwhite (keys +8);
            nowait = TRUE;
            continue;
        }
        if (STRNCMP (keys, "<silent>", 8) == 0) {
            keys = skipwhite (keys +8);
            silent = TRUE;
            continue;
        }
        if (STRNCMP (keys, "<special>", 9) == 0) {
            keys = skipwhite (keys +9);
            special = TRUE;
            continue;
        }
        if (STRNCMP (keys, "<script>", 8) == 0) {
            keys = skipwhite (keys +8);
            noremap = REMAP_SCRIPT;
            continue;
        }
        if (STRNCMP (keys, "<expr>", 6) == 0) {
            keys = skipwhite (keys +6);
            expr = TRUE;
            continue;
        }
        if (STRNCMP (keys, "<unique>", 8) == 0) {
            keys = skipwhite (keys +8);
            unique = TRUE;
            continue;
        }
        break;
    }
    validate_maphash ();
    p = keys;
    do_backslash = (vim_strchr (p_cpo, CPO_BSLASH) == NULL);
    while (*p && (maptype == 1 || !VIM_ISWHITE (*p))) {
        if ((p[0] == Ctrl_V || (do_backslash && p[0] == '\\')) && p[1] != NUL)
            ++p;
        ++p;
    }
    if (*p != NUL)
        *p++ = NUL;
    p = skipwhite (p);
    rhs = p;
    hasarg = (*rhs != NUL);
    haskey = (*keys != NUL);
    if (maptype == 1 && !haskey) {
        retval = 1;
        goto theend;
    }
    if (haskey)
        keys = replace_termcodes (keys, &keys_buf, TRUE, TRUE, special);
    orig_rhs = rhs;
    if (hasarg) {
        if (STRICMP (rhs, "<nop>") == 0)
            rhs = (char_u *) "";
        else
            rhs = replace_termcodes (rhs, &arg_buf, FALSE, TRUE, special);
    }
    if (p_altkeymap && curwin->w_p_rl)
        lrswap (rhs);
    if (haskey) {
        len = (int) STRLEN (keys);
        if (len > MAXMAPLEN) {
            retval = 1;
            goto theend;
        }
        if (abbrev && maptype != 1) {
            if (vim_iswordc (keys[len - 1]))
                for (n = 0; n < len - 2; ++n)
                    if (vim_iswordc (keys[n]) != vim_iswordc (keys[len - 2])) {
                        retval = 1;
                        goto theend;
                    }
            for (n = 0; n < len; ++n)
                if (VIM_ISWHITE (keys[n])) {
                    retval = 1;
                    goto theend;
                }
        }
    }
    if (haskey && hasarg && abbrev)
        no_abbr = FALSE;
    if (!haskey || (maptype != 1 && !hasarg))
        msg_start ();
    if (map_table == curbuf->b_maphash && haskey && hasarg && maptype != 1) {
        for (hash = 0; hash < 256 && !got_int; ++hash) {
            if (abbrev) {
                if (hash != 0)
                    break;
                mp = first_abbr;
            }
            else
                mp = maphash[hash];
            for (; mp != NULL && !got_int; mp = mp->m_next) {
                if ((mp->m_mode & mode) != 0 && mp->m_keylen == len && unique && STRNCMP (mp->m_keys, keys, (size_t) len) == 0) {
                    if (abbrev)
                        EMSG2 (_ ("E224: global abbreviation already exists for %s"), mp->m_keys);
                    else
                        EMSG2 (_ ("E225: global mapping already exists for %s"), mp->m_keys);
                    retval = 5;
                    goto theend;
                }
            }
        }
    }
    if (map_table != curbuf->b_maphash && !hasarg && maptype != 1) {
        for (hash = 0; hash < 256 && !got_int; ++hash) {
            if (abbrev) {
                if (hash != 0)
                    break;
                mp = curbuf->b_first_abbr;
            }
            else
                mp = curbuf->b_maphash[hash];
            for (; mp != NULL && !got_int; mp = mp->m_next) {
                if ((mp->m_mode & mode) != 0) {
                    if (!haskey) {
                        showmap (mp, TRUE);
                        did_local = TRUE;
                    }
                    else {
                        n = mp->m_keylen;
                        if (STRNCMP (mp->m_keys, keys, (size_t) (n < len ? n : len)) == 0) {
                            showmap (mp, TRUE);
                            did_local = TRUE;
                        }
                    }
                }
            }
        }
    }
    for (round = 0; (round == 0 || maptype == 1) && round <= 1 && !did_it && !got_int; ++round) {
        for (hash = 0; hash < 256 && !got_int; ++hash) {
            if (abbrev) {
                if (hash > 0)
                    break;
                mpp = abbr_table;
            }
            else
                mpp = &(map_table[hash]);
            for (mp = *mpp; mp != NULL && !got_int; mp = *mpp) {
                if (!(mp->m_mode & mode)) {
                    mpp = &(mp->m_next);
                    continue;
                }
                if (!haskey) {
                    showmap (mp, map_table != maphash);
                    did_it = TRUE;
                }
                else {
                    if (round) {
                        n = (int) STRLEN (mp->m_str);
                        p = mp->m_str;
                    }
                    else {
                        n = mp->m_keylen;
                        p = mp->m_keys;
                    }
                    if (STRNCMP (p, keys, (size_t) (n < len ? n : len)) == 0) {
                        if (maptype == 1) {
                            if (n != len && (!abbrev || round || n > len || *skipwhite (keys +n) != NUL)) {
                                mpp = &(mp->m_next);
                                continue;
                            }
                            mp->m_mode &= ~mode;
                            did_it = TRUE;
                        }
                        else if (!hasarg) {
                            showmap (mp, map_table != maphash);
                            did_it = TRUE;
                        }
                        else if (n != len) {
                            mpp = &(mp->m_next);
                            continue;
                        }
                        else if (unique) {
                            if (abbrev)
                                EMSG2 (_ ("E226: abbreviation already exists for %s"), p);
                            else
                                EMSG2 (_ ("E227: mapping already exists for %s"), p);
                            retval = 5;
                            goto theend;
                        }
                        else {
                            mp->m_mode &= ~mode;
                            if (mp->m_mode == 0 && !did_it) {
                                newstr = vim_strsave (rhs);
                                if (newstr == NULL) {
                                    retval = 4;
                                    goto theend;
                                }
                                vim_free (mp -> m_str);
                                mp->m_str = newstr;
                                vim_free (mp -> m_orig_str);
                                mp->m_orig_str = vim_strsave (orig_rhs);
                                mp->m_noremap = noremap;
                                mp->m_nowait = nowait;
                                mp->m_silent = silent;
                                mp->m_mode = mode;
                                mp->m_expr = expr;
                                mp->m_script_ID = current_SID;
                                did_it = TRUE;
                            }
                        }
                        if (mp->m_mode == 0) {
                            map_free (mpp);
                            continue;
                        }
                        new_hash = MAP_HASH (mp->m_mode, mp->m_keys[0]);
                        if (!abbrev && new_hash != hash) {
                            *mpp = mp->m_next;
                            mp->m_next = map_table[new_hash];
                            map_table[new_hash] = mp;
                            continue;
                        }
                    }
                }
                mpp = &(mp->m_next);
            }
        }
    }
    if (maptype == 1) {
        if (!did_it)
            retval = 2;
        else if (*keys == Ctrl_C) {
            if (map_table == curbuf->b_maphash)
                curbuf->b_mapped_ctrl_c &= ~mode;
            else
                mapped_ctrl_c &= ~mode;
        }
        goto theend;
    }
    if (!haskey || !hasarg) {
        if (!did_it && !did_local) {
            if (abbrev)
                MSG (_ ("No abbreviation found"));
            else
                MSG (_ ("No mapping found"));
        }
        goto theend;
    }
    if (did_it)
        goto theend;
    mp = (mapblock_T *) alloc ((unsigned ) sizeof (mapblock_T));
    if (mp == NULL) {
        retval = 4;
        goto theend;
    }
    if (*keys == Ctrl_C) {
        if (map_table == curbuf->b_maphash)
            curbuf->b_mapped_ctrl_c |= mode;
        else
            mapped_ctrl_c |= mode;
    }
    mp->m_keys = vim_strsave (keys);
    mp->m_str = vim_strsave (rhs);
    mp->m_orig_str = vim_strsave (orig_rhs);
    if (mp->m_keys == NULL || mp->m_str == NULL) {
        vim_free (mp -> m_keys);
        vim_free (mp -> m_str);
        vim_free (mp -> m_orig_str);
        vim_free (mp);
        retval = 4;
        goto theend;
    }
    mp->m_keylen = (int) STRLEN (mp->m_keys);
    mp->m_noremap = noremap;
    mp->m_nowait = nowait;
    mp->m_silent = silent;
    mp->m_mode = mode;
    mp->m_expr = expr;
    mp->m_script_ID = current_SID;
    if (abbrev) {
        mp->m_next = *abbr_table;
        *abbr_table = mp;
    }
    else {
        n = MAP_HASH (mp->m_mode, mp->m_keys[0]);
        mp->m_next = map_table[n];
        map_table[n] = mp;
    }
theend :
    vim_free (keys_buf);
    vim_free (arg_buf);
    return retval;
}

static void showmap (mapblock_T *mp, int local) {
    int len = 1;
    char_u *mapchars;
    if (message_filtered (mp->m_keys) && message_filtered (mp->m_str))
        return;
    if (msg_didout || msg_silent != 0) {
        msg_putchar ('\n');
        if (got_int)
            return;
    }
    mapchars = map_mode_to_chars (mp->m_mode);
    if (mapchars != NULL) {
        msg_puts (mapchars);
        len = (int) STRLEN (mapchars);
        vim_free (mapchars);
    }
    while (++len <= 3)
        msg_putchar (' ');
    len = msg_outtrans_special (mp->m_keys, TRUE);
    do {
        msg_putchar (' ');
        ++len;
    }
    while (len < 12);
    if (mp->m_noremap == REMAP_NONE)
        msg_puts_attr ((char_u *) "*", HL_ATTR (HLF_8));
    else if (mp->m_noremap == REMAP_SCRIPT)
        msg_puts_attr ((char_u *) "&", HL_ATTR (HLF_8));
    else
        msg_putchar (' ');
    if (local)
        msg_putchar ('@');
    else
        msg_putchar (' ');
    if (*mp->m_str == NUL)
        msg_puts_attr ((char_u *) "<Nop>", HL_ATTR (HLF_8));
    else {
        char_u *s = vim_strsave (mp->m_str);
        if (s != NULL) {
            vim_unescape_csi (s);
            msg_outtrans_special (s, FALSE);
            vim_free (s);
        }
    }
    if (p_verbose > 0)
        last_set_msg (mp->m_script_ID);
    out_flush ();
}

char_u *map_mode_to_chars (int mode) {
    garray_T mapmode;
    ga_init2 (& mapmode, 1, 7);
    if ((mode & (INSERT + CMDLINE)) == INSERT + CMDLINE)
        ga_append (&mapmode, '!');
    else if (mode & INSERT)
        ga_append (&mapmode, 'i');
    else if (mode & LANGMAP)
        ga_append (&mapmode, 'l');
    else if (mode & CMDLINE)
        ga_append (&mapmode, 'c');
    else if ((mode & (NORMAL + VISUAL + SELECTMODE + OP_PENDING)) == NORMAL + VISUAL + SELECTMODE + OP_PENDING)
        ga_append (&mapmode, ' ');
    else {
        if (mode & NORMAL)
            ga_append (&mapmode, 'n');
        if (mode & OP_PENDING)
            ga_append (&mapmode, 'o');
        if ((mode & (VISUAL + SELECTMODE)) == VISUAL + SELECTMODE)
            ga_append (&mapmode, 'v');
        else {
            if (mode & VISUAL)
                ga_append (&mapmode, 'x');
            if (mode & SELECTMODE)
                ga_append (&mapmode, 's');
        }
    }
    ga_append (& mapmode, NUL);
    return (char_u *) mapmode.ga_data;
}

void stuffcharReadbuff (int c) {
    add_char_buff (& readbuf1, c);
}

int using_script (void) {
    return scriptin[curscript] != NULL;
}

int vpeekc_any (void) {
    int c;
    c = vpeekc ();
    if (c == NUL && typebuf.tb_len > 0)
        c = ESC;
    return c;
}

void vungetc (int c) {
    old_char = c;
    old_mod_mask = mod_mask;
    old_mouse_row = mouse_row;
    old_mouse_col = mouse_col;
}

int ExpandMappings (regmatch_T *regmatch, int *num_file, char_u ***file) {
    mapblock_T *mp;
    int hash;
    int count;
    int round;
    char_u *p;
    int i;
    validate_maphash ();
    *num_file = 0;
    *file = NULL;
    for (round = 1; round <= 2; ++round) {
        count = 0;
        for (i = 0; i < 7; ++i) {
            if (i == 0)
                p = (char_u *) "<silent>";
            else if (i == 1)
                p = (char_u *) "<unique>";
            else if (i == 2)
                p = (char_u *) "<script>";
            else if (i == 3)
                p = (char_u *) "<expr>";
            else if (i == 4 && !expand_buffer)
                p = (char_u *) "<buffer>";
            else if (i == 5)
                p = (char_u *) "<nowait>";
            else if (i == 6)
                p = (char_u *) "<special>";
            else
                continue;
            if (vim_regexec (regmatch, p, (colnr_T) 0)) {
                if (round == 1)
                    ++count;
                else
                    (*file)[count++] = vim_strsave (p);
            }
        }
        for (hash = 0; hash < 256; ++hash) {
            if (expand_isabbrev) {
                if (hash > 0)
                    break;
                mp = first_abbr;
            }
            else if (expand_buffer)
                mp = curbuf->b_maphash[hash];
            else
                mp = maphash[hash];
            for (; mp; mp = mp->m_next) {
                if (mp->m_mode & expand_mapmodes) {
                    p = translate_mapping (mp->m_keys, TRUE);
                    if (p != NULL && vim_regexec (regmatch, p, (colnr_T) 0)) {
                        if (round == 1)
                            ++count;
                        else {
                            (*file)[count++] = p;
                            p = NULL;
                        }
                    }
                    vim_free (p);
                }
            }
        }
        if (count == 0)
            break;
        if (round == 1) {
            *file = (char_u **) alloc ((unsigned ) (count * sizeof (char_u *)));
            if (*file == NULL)
                return FAIL;
        }
    }
    if (count > 1) {
        char_u **ptr1;
        char_u **ptr2;
        char_u **ptr3;
        sort_strings (* file, count);
        ptr1 = *file;
        ptr2 = ptr1 + 1;
        ptr3 = ptr1 + count;
        while (ptr2 < ptr3) {
            if (STRCMP (*ptr1, *ptr2))
                *++ptr1 = *ptr2++;
            else {
                vim_free (* ptr2 ++);
                count--;
            }
        }
    }
    *num_file = count;
    return (count == 0 ? FAIL : OK);
}

char_u *set_context_in_map_cmd (expand_T *xp, char_u *cmd, char_u *arg, int forceit, int isabbrev, int isunmap, cmdidx_T cmdidx) {
    if (forceit && cmdidx != CMD_map && cmdidx != CMD_unmap)
        xp->xp_context = EXPAND_NOTHING;
    else {
        if (isunmap)
            expand_mapmodes = get_map_mode (&cmd, forceit || isabbrev);
        else {
            expand_mapmodes = INSERT + CMDLINE;
            if (!isabbrev)
                expand_mapmodes += VISUAL + SELECTMODE + NORMAL + OP_PENDING;
        }
        expand_isabbrev = isabbrev;
        xp->xp_context = EXPAND_MAPPINGS;
        expand_buffer = FALSE;
        for (;;) {
            if (STRNCMP (arg, "<buffer>", 8) == 0) {
                expand_buffer = TRUE;
                arg = skipwhite (arg +8);
                continue;
            }
            if (STRNCMP (arg, "<unique>", 8) == 0) {
                arg = skipwhite (arg +8);
                continue;
            }
            if (STRNCMP (arg, "<nowait>", 8) == 0) {
                arg = skipwhite (arg +8);
                continue;
            }
            if (STRNCMP (arg, "<silent>", 8) == 0) {
                arg = skipwhite (arg +8);
                continue;
            }
            if (STRNCMP (arg, "<special>", 9) == 0) {
                arg = skipwhite (arg +9);
                continue;
            }
            if (STRNCMP (arg, "<script>", 8) == 0) {
                arg = skipwhite (arg +8);
                continue;
            }
            if (STRNCMP (arg, "<expr>", 6) == 0) {
                arg = skipwhite (arg +6);
                continue;
            }
            break;
        }
        xp->xp_pattern = arg;
    }
    return NULL;
}

int get_map_mode (char_u **cmdp, int forceit) {
    char_u *p;
    int modec;
    int mode;
    p = *cmdp;
    modec = *p++;
    if (modec == 'i')
        mode = INSERT;
    else if (modec == 'l')
        mode = LANGMAP;
    else if (modec == 'c')
        mode = CMDLINE;
    else if (modec == 'n' && *p != 'o')
        mode = NORMAL;
    else if (modec == 'v')
        mode = VISUAL + SELECTMODE;
    else if (modec == 'x')
        mode = VISUAL;
    else if (modec == 's')
        mode = SELECTMODE;
    else if (modec == 'o')
        mode = OP_PENDING;
    else if (modec == 't')
        mode = TERMINAL;
    else {
        --p;
        if (forceit)
            mode = INSERT + CMDLINE;
        else
            mode = VISUAL + SELECTMODE + NORMAL + OP_PENDING;
    }
    *cmdp = p;
    return mode;
}

int map_to_exists_mode (char_u *rhs, int mode, int abbr) {
    mapblock_T *mp;
    int hash;
    int expand_buffer = FALSE;
    validate_maphash ();
    for (;;) {
        for (hash = 0; hash < 256; ++hash) {
            if (abbr) {
                if (hash > 0)
                    break;
                if (expand_buffer)
                    mp = curbuf->b_first_abbr;
                else
                    mp = first_abbr;
            }
            else if (expand_buffer)
                mp = curbuf->b_maphash[hash];
            else
                mp = maphash[hash];
            for (; mp; mp = mp->m_next) {
                if ((mp->m_mode & mode) && strstr ((char *) mp->m_str, (char *) rhs) != NULL)
                    return TRUE;
            }
        }
        if (expand_buffer)
            break;
        expand_buffer = TRUE;
    }
    return FALSE;
}

void check_map_keycodes (void) {
    mapblock_T *mp;
    char_u *p;
    int i;
    char_u buf [3];
    char_u *save_name;
    int abbr;
    int hash;
    buf_T *bp;
    validate_maphash ();
    save_name = sourcing_name;
    sourcing_name = (char_u *) "mappings";
    for (bp = firstbuf;; bp = bp->b_next) {
        for (abbr = 0; abbr <= 1; ++abbr)
            for (hash = 0; hash < 256; ++hash) {
                if (abbr) {
                    if (hash)
                        break;
                    if (bp != NULL)
                        mp = bp->b_first_abbr;
                    else
                        mp = first_abbr;
                }
                else {
                    if (bp != NULL)
                        mp = bp->b_maphash[hash];
                    else
                        mp = maphash[hash];
                }
                for (; mp != NULL; mp = mp->m_next) {
                    for (i = 0; i <= 1; ++i) {
                        if (i == 0)
                            p = mp->m_keys;
                        else
                            p = mp->m_str;
                        while (*p) {
                            if (*p == K_SPECIAL) {
                                ++p;
                                if (*p < 128) {
                                    buf[0] = p[0];
                                    buf[1] = p[1];
                                    buf[2] = NUL;
                                    (void) add_termcap_entry (buf, FALSE);
                                }
                                ++p;
                            }
                            ++p;
                        }
                    }
                }
            }
        if (bp == NULL)
            break;
    }
    sourcing_name = save_name;
}

void del_typebuf (int len, int offset) {
    int i;
    if (len == 0)
        return;
    typebuf.tb_len -= len;
    if (offset == 0 && typebuf.tb_buflen - (typebuf.tb_off + len) >= 3 * MAXMAPLEN + 3)
        typebuf.tb_off += len;
    else {
        i = typebuf.tb_off + offset;
        if (typebuf.tb_off > MAXMAPLEN) {
            mch_memmove (typebuf.tb_buf + MAXMAPLEN, typebuf.tb_buf + typebuf.tb_off, (size_t) offset);
            mch_memmove (typebuf.tb_noremap + MAXMAPLEN, typebuf.tb_noremap + typebuf.tb_off, (size_t) offset);
            typebuf.tb_off = MAXMAPLEN;
        }
        mch_memmove (typebuf.tb_buf + typebuf.tb_off + offset, typebuf.tb_buf + i + len, (size_t) (typebuf.tb_len - offset + 1));
        mch_memmove (typebuf.tb_noremap + typebuf.tb_off + offset, typebuf.tb_noremap + i + len, (size_t) (typebuf.tb_len - offset));
    }
    if (typebuf.tb_maplen > offset) {
        if (typebuf.tb_maplen < offset + len)
            typebuf.tb_maplen = offset;
        else
            typebuf.tb_maplen -= len;
    }
    if (typebuf.tb_silent > offset) {
        if (typebuf.tb_silent < offset + len)
            typebuf.tb_silent = offset;
        else
            typebuf.tb_silent -= len;
    }
    if (typebuf.tb_no_abbr_cnt > offset) {
        if (typebuf.tb_no_abbr_cnt < offset + len)
            typebuf.tb_no_abbr_cnt = offset;
        else
            typebuf.tb_no_abbr_cnt -= len;
    }
    typebuf_was_filled = FALSE;
    if (++typebuf.tb_change_cnt == 0)
        typebuf.tb_change_cnt = 1;
}

void typeahead_noflush (int c) {
    typeahead_char = c;
}

void save_typeahead (tasave_T *tp) {
    tp->save_typebuf = typebuf;
    tp->typebuf_valid = (alloc_typebuf () == OK);
    if (!tp->typebuf_valid)
        typebuf = tp->save_typebuf;
    tp->old_char = old_char;
    tp->old_mod_mask = old_mod_mask;
    old_char = -1;
    tp->save_readbuf1 = readbuf1;
    readbuf1.bh_first.b_next = NULL;
    tp->save_readbuf2 = readbuf2;
    readbuf2.bh_first.b_next = NULL;
}

int alloc_typebuf (void) {
    typebuf.tb_buf = alloc (TYPELEN_INIT);
    typebuf.tb_noremap = alloc (TYPELEN_INIT);
    if (typebuf.tb_buf == NULL || typebuf.tb_noremap == NULL) {
        free_typebuf ();
        return FAIL;
    }
    typebuf.tb_buflen = TYPELEN_INIT;
    typebuf.tb_off = MAXMAPLEN + 4;
    typebuf.tb_len = 0;
    typebuf.tb_maplen = 0;
    typebuf.tb_silent = 0;
    typebuf.tb_no_abbr_cnt = 0;
    if (++typebuf.tb_change_cnt == 0)
        typebuf.tb_change_cnt = 1;
    return OK;
}

void free_typebuf (void) {
    if (typebuf.tb_buf == typebuf_init)
        internal_error ("Free typebuf 1");
    else
        vim_free (typebuf.tb_buf);
    if (typebuf.tb_noremap == noremapbuf_init)
        internal_error ("Free typebuf 2");
    else
        vim_free (typebuf.tb_noremap);
}

int typebuf_maplen (void) {
    return typebuf.tb_maplen;
}

int readbuf1_empty (void) {
    return (readbuf1.bh_first.b_next == NULL);
}

char_u *get_inserted (void) {
    return get_buffcont (&redobuff, FALSE);
}

void stop_redo_ins (void) {
    block_redo = FALSE;
}

void stuffReadbuff (char_u *s) {
    add_buff (& readbuf1, s, - 1L);
}

int start_redo_ins (void) {
    int c;
    if (read_redo (TRUE, FALSE) == FAIL)
        return FAIL;
    start_stuff ();
    while ((c = read_redo (FALSE, FALSE)) != NUL) {
        if (vim_strchr ((char_u *) "AaIiRrOo", c) != NULL) {
            if (c == 'O' || c == 'o')
                add_buff (&readbuf2, NL_STR, -1L);
            break;
        }
    }
    copy_redo (FALSE);
    block_redo = TRUE;
    return OK;
}

static int read_redo (int init, int old_redo) {
    static buffblock_T *bp;
    static char_u *p;
    int c;
    if (init) {
        if (old_redo)
            bp = old_redobuff.bh_first.b_next;
        else
            bp = redobuff.bh_first.b_next;
        if (bp == NULL)
            return FAIL;
        p = bp->b_str;
        return OK;
    }
    if ((c = *p) != NUL) {
        {
            if (c == K_SPECIAL) {
                c = TO_SPECIAL (p[1], p[2]);
                p += 2;
            }
            if (c == CSI)
                p += 2;
            if (*++p == NUL && bp->b_next != NULL) {
                bp = bp->b_next;
                p = bp->b_str;
            }
        }
    }
    return c;
}

static void copy_redo (int old_redo) {
    int c;
    while ((c = read_redo (FALSE, old_redo)) != NUL)
        add_char_buff (&readbuf2, c);
}

void stuffRedoReadbuff (char_u *s) {
    add_buff (& readbuf2, s, - 1L);
}

void stuffReadbuffLen (char_u *s, long  len) {
    add_buff (& readbuf1, s, len);
}

void stuffnumReadbuff (long  n) {
    add_num_buff (& readbuf1, n);
}

void restore_typeahead (tasave_T *tp) {
    if (tp->typebuf_valid) {
        free_typebuf ();
        typebuf = tp->save_typebuf;
    }
    old_char = tp->old_char;
    old_mod_mask = tp->old_mod_mask;
    free_buff (& readbuf1);
    readbuf1 = tp->save_readbuf1;
    free_buff (& readbuf2);
    readbuf2 = tp->save_readbuf2;
}

static void closescript (void) {
    free_typebuf ();
    typebuf = saved_typebuf[curscript];
    fclose (scriptin [curscript]);
    scriptin[curscript] = NULL;
    if (curscript > 0)
        --curscript;
}

static void gotchars (char_u *chars, int len) {
    char_u *s = chars;
    int c;
    char_u buf [2];
    int todo = len;
    if (Recording)
        last_recorded_len += len;
    buf[1] = NUL;
    while (todo--) {
        c = *s++;
        updatescript (c);
        if (Recording) {
            buf[0] = c;
            add_buff (& recordbuff, buf, 1L);
        }
    }
    may_sync_undo ();
    debug_did_msg = FALSE;
    ++maptick;
}

static void may_sync_undo (void) {
    if ((!(State & (INSERT + CMDLINE)) || arrow_used) && scriptin[curscript] == NULL)
        u_sync (FALSE);
}

void CancelRedo (void) {
    if (!block_redo) {
        free_buff (& redobuff);
        redobuff = old_redobuff;
        old_redobuff.bh_first.b_next = NULL;
        start_stuff ();
        while (read_readbuffers (TRUE) != NUL)
            ;
    }
}

void restoreRedobuff (save_redo_T *save_redo) {
    free_buff (& redobuff);
    redobuff = save_redo->sr_redobuff;
    free_buff (& old_redobuff);
    old_redobuff = save_redo->sr_old_redobuff;
}

int save_typebuf (void) {
    init_typebuf ();
    saved_typebuf[curscript] = typebuf;
    if (alloc_typebuf () == FAIL) {
        closescript ();
        return FAIL;
    }
    return OK;
}

int map_to_exists (char_u *str, char_u *modechars, int abbr) {
    int mode = 0;
    char_u *rhs;
    char_u *buf;
    int retval;
    rhs = replace_termcodes (str, &buf, FALSE, TRUE, FALSE);
    if (vim_strchr (modechars, 'n') != NULL)
        mode |= NORMAL;
    if (vim_strchr (modechars, 'v') != NULL)
        mode |= VISUAL + SELECTMODE;
    if (vim_strchr (modechars, 'x') != NULL)
        mode |= VISUAL;
    if (vim_strchr (modechars, 's') != NULL)
        mode |= SELECTMODE;
    if (vim_strchr (modechars, 'o') != NULL)
        mode |= OP_PENDING;
    if (vim_strchr (modechars, 'i') != NULL)
        mode |= INSERT;
    if (vim_strchr (modechars, 'l') != NULL)
        mode |= LANGMAP;
    if (vim_strchr (modechars, 'c') != NULL)
        mode |= CMDLINE;
    retval = map_to_exists_mode (rhs, mode, abbr);
    vim_free (buf);
    return retval;
}

void stuffReadbuffSpec (char_u *s) {
    int c;
    while (*s != NUL) {
        if (*s == K_SPECIAL && s[1] != NUL && s[2] != NUL) {
            stuffReadbuffLen (s, 3L);
            s += 3;
        }
        else {
            c = *s++;
            if (c == CAR || c == NL || c == ESC)
                c = ' ';
            stuffcharReadbuff (c);
        }
    }
}

char_u *check_map (char_u *keys, int mode, int exact, int ign_mod, int abbr, mapblock_T **mp_ptr, int *local_ptr) {
    int hash;
    int len, minlen;
    mapblock_T *mp;
    char_u *s;
    int local;
    validate_maphash ();
    len = (int) STRLEN (keys);
    for (local = 1; local >= 0; --local)
        for (hash = 0; hash < 256; ++hash) {
            if (abbr) {
                if (hash > 0)
                    break;
                if (local)
                    mp = curbuf->b_first_abbr;
                else
                    mp = first_abbr;
            }
            else if (local)
                mp = curbuf->b_maphash[hash];
            else
                mp = maphash[hash];
            for (; mp != NULL; mp = mp->m_next) {
                if ((mp->m_mode & mode) && (!exact || mp->m_keylen == len)) {
                    if (len > mp->m_keylen)
                        minlen = mp->m_keylen;
                    else
                        minlen = len;
                    s = mp->m_keys;
                    if (ign_mod && s[0] == K_SPECIAL && s[1] == KS_MODIFIER && s[2] != NUL) {
                        s += 3;
                        if (len > mp->m_keylen - 3)
                            minlen = mp->m_keylen - 3;
                    }
                    if (STRNCMP (s, keys, minlen) == 0) {
                        if (mp_ptr != NULL)
                            *mp_ptr = mp;
                        if (local_ptr != NULL)
                            *local_ptr = local;
                        return mp->m_str;
                    }
                }
            }
        }
    return NULL;
}

#define VIS_SEL	(VISUAL+SELECTMODE)	/* abbreviation */

int start_redo (long  count, int old_redo) {
    int c;
    if (read_redo (TRUE, old_redo) == FAIL)
        return FAIL;
    c = read_redo (FALSE, old_redo);
    if (c == '"') {
        add_buff (& readbuf2, (char_u *) "\"", 1L);
        c = read_redo (FALSE, old_redo);
        if (c >= '1' && c < '9')
            ++c;
        add_char_buff (& readbuf2, c);
        c = read_redo (FALSE, old_redo);
    }
    if (c == 'v') {
        VIsual = curwin->w_cursor;
        VIsual_active = TRUE;
        VIsual_select = FALSE;
        VIsual_reselect = TRUE;
        redo_VIsual_busy = TRUE;
        c = read_redo (FALSE, old_redo);
    }
    if (count) {
        while (VIM_ISDIGIT (c))
            c = read_redo (FALSE, old_redo);
        add_num_buff (& readbuf2, count);
    }
    add_char_buff (& readbuf2, c);
    copy_redo (old_redo);
    return OK;
}

char_u *get_recorded (void) {
    char_u *p;
    size_t len;
    p = get_buffcont (&recordbuff, TRUE);
    free_buff (& recordbuff);
    len = STRLEN (p);
    if ((int) len >= last_recorded_len) {
        len -= last_recorded_len;
        p[len] = NUL;
    }
    if (len > 0 && restart_edit != 0 && p[len - 1] == Ctrl_O)
        p[len - 1] = NUL;
    return (p);
}

