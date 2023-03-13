
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
struct cmdline_info {
    char_u *cmdbuff;
    int cmdbufflen;
    int cmdlen;
    int cmdpos;
    int cmdspos;
    int cmdfirstc;
    int cmdindent;
    char_u *cmdprompt;
    int cmdattr;
    int overstrike;
    expand_T *xpc;
    int xp_context;
    char_u *xp_arg;
    int input_fn;
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
EXTERN int p_prompt;
EXTERN char_u *NameBuff;
EXTERN int p_paste;
EXTERN char_u *p_pp;
EXTERN char_u *p_rtp;
EXTERN char_u e_toomany [] INIT (= N_ ("E77: Too many file names"));
EXTERN int p_ru;
EXTERN int p_altkeymap;
EXTERN int p_ari;
EXTERN int p_im;
EXTERN long  p_wmh;
EXTERN long  p_ls;
EXTERN int KeyStuffed;
EXTERN int p_is;
EXTERN int p_wmnu;
EXTERN int p_arshape;
EXTERN int KeyTyped;
EXTERN win_T *lastwin;
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
int prev_ccline_used = FALSE;
struct cmdline_info prev_ccline;
int cmd_fkmap = 0;
int cmd_hkmap = 0;
int extra_char_shift;
int extra_char = NUL;
int cmd_showtail;
struct cmdline_info ccline;
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
char_u *arshape_buf = NULL;
EXTERN char_u e_positive [] INIT (= N_ ("E487: Argument must be positive"));
EXTERN hlf_T edit_submode_highl;
EXTERN int highlight_attr [HLF_COUNT];
EXTERN int p_hls;
EXTERN char_u *p_hl;
EXTERN char_u *p_hlg;
int new_cmdpos;
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

int cmdline_at_end (void) {
    return (ccline.cmdpos >= ccline.cmdlen);
}

int cmdline_overstrike (void) {
    return ccline.overstrike;
}

void compute_cmdrow (void) {
    if (exmode_active || msg_scrolled != 0)
        cmdline_row = Rows - 1;
    else
        cmdline_row = W_WINROW (lastwin) + lastwin->w_height + lastwin->w_status_height;
}

int text_locked (void) {
    return textlock != 0;
}

int curbuf_locked (void) {
    if (curbuf_lock > 0) {
        EMSG (_ ("E788: Not allowed to edit another buffer now"));
        return TRUE;
    }
    return allbuf_locked ();
}

int allbuf_locked (void) {
    if (allbuf_lock > 0) {
        EMSG (_ ("E811: Not allowed to change buffer information now"));
        return TRUE;
    }
    return FALSE;
}

void gotocmdline (int clr) {
    msg_start ();
    if (cmdmsg_rl)
        msg_col = Columns - 1;
    else
        msg_col = 0;
    if (clr)
        msg_clr_eos ();
    windgoto (cmdline_row, 0);
}

void text_locked_msg (void) {
    EMSG (_ (get_text_locked_msg ()));
}

char_u *get_text_locked_msg (void) {
    return e_secure;
}

int put_on_cmdline (char_u *str, int len, int redraw) {
    int retval;
    int i;
    int m;
    int c;
    if (len < 0)
        len = (int) STRLEN (str);
    if (ccline.cmdlen + len + 1 >= ccline.cmdbufflen)
        retval = realloc_cmdbuff (ccline.cmdlen + len + 1);
    else
        retval = OK;
    if (retval == OK) {
        if (!ccline.overstrike) {
            mch_memmove (ccline.cmdbuff + ccline.cmdpos + len, ccline.cmdbuff + ccline.cmdpos, (size_t) (ccline.cmdlen - ccline.cmdpos));
            ccline.cmdlen += len;
        }
        else {
            if (ccline.cmdpos + len > ccline.cmdlen)
                ccline.cmdlen = ccline.cmdpos + len;
        }
        mch_memmove (ccline.cmdbuff + ccline.cmdpos, str, (size_t) len);
        ccline.cmdbuff[ccline.cmdlen] = NUL;
        if (redraw && !cmd_silent) {
            msg_no_more = TRUE;
            i = cmdline_row;
            cursorcmd ();
            draw_cmdline (ccline.cmdpos, ccline.cmdlen - ccline.cmdpos);
            if (cmdline_row != i || ccline.overstrike)
                msg_clr_eos ();
            msg_no_more = FALSE;
        }
        if (!cmd_fkmap) {
            if (KeyTyped) {
                m = Columns * Rows;
                if (m < 0)
                    m = MAXCOL;
            }
            else
                m = MAXCOL;
            for (i = 0; i < len; ++i) {
                c = cmdline_charsize (ccline.cmdpos);
                if (ccline.cmdspos + c < m)
                    ccline.cmdspos += c;
                ++ccline.cmdpos;
            }
        }
    }
    if (redraw)
        msg_check ();
    return retval;
}

static int realloc_cmdbuff (int len) {
    char_u *p;
    if (len < ccline.cmdbufflen)
        return OK;
    p = ccline.cmdbuff;
    alloc_cmdbuff (len);
    if (ccline.cmdbuff == NULL) {
        ccline.cmdbuff = p;
        return FAIL;
    }
    mch_memmove (ccline.cmdbuff, p, (size_t) ccline.cmdlen);
    ccline.cmdbuff[ccline.cmdlen] = NUL;
    vim_free (p);
    if (ccline.xpc != NULL && ccline.xpc->xp_pattern != NULL && ccline.xpc->xp_context != EXPAND_NOTHING && ccline.xpc->xp_context != EXPAND_UNSUCCESSFUL) {
        int i = (int) (ccline.xpc->xp_pattern - p);
        if (i >= 0 && i <= ccline.cmdlen)
            ccline.xpc->xp_pattern = ccline.cmdbuff + i;
    }
    return OK;
}

static void alloc_cmdbuff (int len) {
    if (len < 80)
        len = 100;
    else
        len += 20;
    ccline.cmdbuff = alloc (len);
    ccline.cmdbufflen = len;
}

static void cursorcmd (void) {
    if (cmd_silent)
        return;
    if (cmdmsg_rl) {
        msg_row = cmdline_row + (ccline.cmdspos / (int) (Columns - 1));
        msg_col = (int) Columns - (ccline.cmdspos % (int) (Columns - 1)) - 1;
        if (msg_row <= 0)
            msg_row = Rows - 1;
    }
    else {
        msg_row = cmdline_row + (ccline.cmdspos / (int) Columns);
        msg_col = ccline.cmdspos % (int) Columns;
        if (msg_row >= Rows)
            msg_row = Rows - 1;
    }
    windgoto (msg_row, msg_col);
}

static void draw_cmdline (int start, int len) {
    int i;
    if (cmdline_star > 0)
        for (i = 0; i < len; ++i) {
            msg_putchar ('*');
        }
    else if (p_arshape && !p_tbidi && enc_utf8 && len > 0) {
        static int buflen = 0;
        char_u *p;
        int j;
        int newlen = 0;
        int mb_l;
        int pc, pc1 = 0;
        int prev_c = 0;
        int prev_c1 = 0;
        int u8c;
        int u8cc [MAX_MCO];
        int nc = 0;
        if (len * 2 + 2 > buflen) {
            vim_free (arshape_buf);
            buflen = len * 2 + 2;
            arshape_buf = alloc (buflen);
            if (arshape_buf == NULL)
                return;
        }
        if (utf_iscomposing (utf_ptr2char (ccline.cmdbuff + start))) {
            arshape_buf[0] = ' ';
            newlen = 1;
        }
        for (j = start; j < start + len; j += mb_l) {
            p = ccline.cmdbuff + j;
            u8c = utfc_ptr2char_len (p, u8cc, start +len - j);
            mb_l = utfc_ptr2len_len (p, start +len - j);
            if (ARABIC_CHAR (u8c)) {
                if (cmdmsg_rl) {
                    pc = prev_c;
                    pc1 = prev_c1;
                    prev_c1 = u8cc[0];
                    if (j + mb_l >= start + len)
                        nc = NUL;
                    else
                        nc = utf_ptr2char (p +mb_l);
                }
                else {
                    if (j + mb_l >= start + len)
                        pc = NUL;
                    else {
                        int pcc [MAX_MCO];
                        pc = utfc_ptr2char_len (p +mb_l, pcc, start +len - j - mb_l);
                        pc1 = pcc[0];
                    }
                    nc = prev_c;
                }
                prev_c = u8c;
                u8c = arabic_shape (u8c, NULL, &u8cc[0], pc, pc1, nc);
                newlen += (*mb_char2bytes) (u8c, arshape_buf +newlen);
                if (u8cc[0] != 0) {
                    newlen += (*mb_char2bytes) (u8cc[0], arshape_buf +newlen);
                    if (u8cc[1] != 0)
                        newlen += (*mb_char2bytes) (u8cc[1], arshape_buf +newlen);
                }
            }
            else {
                prev_c = u8c;
                mch_memmove (arshape_buf + newlen, p, mb_l);
                newlen += mb_l;
            }
        }
        msg_outtrans_len (arshape_buf, newlen);
    }
    else
        msg_outtrans_len (ccline.cmdbuff + start, len);
}

static int cmdline_charsize (int idx) {
    if (cmdline_star > 0)
        return 1;
    return ptr2cells (ccline.cmdbuff + idx);
}

char_u *save_cmdline_alloc (void) {
    struct cmdline_info *p;
    p = (struct cmdline_info *) alloc ((unsigned ) sizeof (struct cmdline_info));
    if (p != NULL)
        save_cmdline (p);
    return (char_u *) p;
}

static void save_cmdline (struct cmdline_info *ccp) {
    if (!prev_ccline_used) {
        vim_memset (& prev_ccline, 0, sizeof (struct cmdline_info));
        prev_ccline_used = TRUE;
    }
    *ccp = prev_ccline;
    prev_ccline = ccline;
    ccline.cmdbuff = NULL;
    ccline.cmdprompt = NULL;
    ccline.xpc = NULL;
}

void restore_cmdline_alloc (char_u *p) {
    if (p != NULL) {
        restore_cmdline ((struct cmdline_info *) p);
        vim_free (p);
    }
}

static void restore_cmdline (struct cmdline_info *ccp) {
    ccline = prev_ccline;
    prev_ccline = *ccp;
}

int cmd_gchar (int offset) {
    if (ccline.cmdpos + offset >= ccline.cmdlen || ccline.cmdpos + offset < 0) {
        return NUL;
    }
    return (int) ccline.cmdbuff[ccline.cmdpos + offset];
}

char_u *getcmdline_prompt (int firstc, char_u *prompt, int attr, int xp_context, char_u *xp_arg) {
    char_u *s;
    struct cmdline_info save_ccline;
    int msg_col_save = msg_col;
    int msg_silent_save = msg_silent;
    save_cmdline (& save_ccline);
    ccline.cmdprompt = prompt;
    ccline.cmdattr = attr;
    ccline.xp_context = xp_context;
    ccline.xp_arg = xp_arg;
    ccline.input_fn = (firstc == '@');
    msg_silent = 0;
    s = getcmdline (firstc, 1L, 0);
    restore_cmdline (& save_ccline);
    msg_silent = msg_silent_save;
    if (ccline.cmdbuff != NULL)
        msg_col = msg_col_save;
    return s;
}

char_u *getcmdline (int firstc, long  count, int indent) {
    int c;
    int i;
    int j;
    int gotesc = FALSE;
    int do_abbr;
    pos_T search_start;
    pos_T save_cursor;
    colnr_T old_curswant;
    colnr_T init_curswant = curwin->w_curswant;
    colnr_T old_leftcol;
    colnr_T init_leftcol = curwin->w_leftcol;
    linenr_T old_topline;
    linenr_T init_topline = curwin->w_topline;
    pos_T match_start = curwin->w_cursor;
    pos_T match_end;
    int old_topfill;
    int init_topfill = curwin->w_topfill;
    linenr_T old_botline;
    linenr_T init_botline = curwin->w_botline;
    int did_incsearch = FALSE;
    int incsearch_postponed = FALSE;
    int did_wild_list = FALSE;
    int wim_index = 0;
    int res;
    int save_msg_scroll = msg_scroll;
    int save_State = State;
    int some_key_typed = FALSE;
    int ignore_drag_release = TRUE;
    int break_ctrl_c = FALSE;
    expand_T xpc;
    long  *b_im_ptr = NULL;
    struct cmdline_info save_ccline;
    int cmdline_type;
    if (firstc == -1) {
        firstc = NUL;
        break_ctrl_c = TRUE;
    }
    if (firstc == ':' || firstc == '=' || firstc == '>')
        cmd_hkmap = 0;
    ccline.overstrike = FALSE;
    CLEAR_POS (& match_end);
    save_cursor = curwin->w_cursor;
    search_start = curwin->w_cursor;
    old_curswant = curwin->w_curswant;
    old_leftcol = curwin->w_leftcol;
    old_topline = curwin->w_topline;
    old_topfill = curwin->w_topfill;
    old_botline = curwin->w_botline;
    ccline.cmdfirstc = (firstc == '@' ? 0 : firstc);
    ccline.cmdindent = (firstc > 0 ? indent : 0);
    alloc_cmdbuff (exmode_active ? 250 : indent + 1);
    if (ccline.cmdbuff == NULL)
        return NULL;
    ccline.cmdlen = ccline.cmdpos = 0;
    ccline.cmdbuff[0] = NUL;
    sb_text_start_cmdline ();
    if (firstc <= 0) {
        vim_memset (ccline.cmdbuff, ' ', indent);
        ccline.cmdbuff[indent] = NUL;
        ccline.cmdpos = indent;
        ccline.cmdspos = indent;
        ccline.cmdlen = indent;
    }
    ExpandInit (& xpc);
    ccline.xpc = &xpc;
    if (curwin->w_p_rl && *curwin->w_p_rlc == 's' && (firstc == '/' || firstc == '?'))
        cmdmsg_rl = TRUE;
    else
        cmdmsg_rl = FALSE;
    redir_off = TRUE;
    if (!cmd_silent) {
        i = msg_scrolled;
        msg_scrolled = 0;
        gotocmdline (TRUE);
        msg_scrolled += i;
        redrawcmdprompt ();
        set_cmdspos ();
    }
    xpc.xp_context = EXPAND_NOTHING;
    xpc.xp_backslash = XP_BS_NONE;
    xpc.xp_shell = FALSE;
    if (ccline.input_fn) {
        xpc.xp_context = ccline.xp_context;
        xpc.xp_pattern = ccline.cmdbuff;
        xpc.xp_arg = ccline.xp_arg;
    }
    msg_scroll = FALSE;
    State = CMDLINE;
    if (firstc == '/' || firstc == '?' || firstc == '@') {
        if (curbuf->b_p_imsearch == B_IMODE_USE_INSERT)
            b_im_ptr = &curbuf->b_p_iminsert;
        else
            b_im_ptr = &curbuf->b_p_imsearch;
        if (*b_im_ptr == B_IMODE_LMAP)
            State |= LANGMAP;
    }
    setmouse ();
    settmode (TMODE_RAW);
    cmdline_type = firstc == NUL ? '-' : firstc;
    trigger_cmd_autocmd (cmdline_type, EVENT_CMDLINEENTER);
    do_digraph (- 1);
    if (did_emsg)
        redrawcmd ();
    did_emsg = FALSE;
    got_int = FALSE;
    for (;;) {
        redir_off = TRUE;
        quit_more = FALSE;
        cursorcmd ();
        do {
            c = safe_vgetc ();
        }
        while (c == K_IGNORE || c == K_NOP);
        if (KeyTyped) {
            some_key_typed = TRUE;
            if (cmd_hkmap)
                c = hkmap (c);
            if (cmd_fkmap)
                c = cmdl_fkmap (c);
            if (cmdmsg_rl && !KeyStuffed) {
                switch (c) {
                case K_RIGHT :
                    c = K_LEFT;
                    break;
                case K_S_RIGHT :
                    c = K_S_LEFT;
                    break;
                case K_C_RIGHT :
                    c = K_C_LEFT;
                    break;
                case K_LEFT :
                    c = K_RIGHT;
                    break;
                case K_S_LEFT :
                    c = K_S_RIGHT;
                    break;
                case K_C_LEFT :
                    c = K_C_RIGHT;
                    break;
                }
            }
        }
        if ((c == Ctrl_C || c == intr_char) && firstc != '@' && !break_ctrl_c && !global_busy)
            got_int = FALSE;
        if (c != p_wc && c == K_S_TAB && xpc.xp_numfiles > 0)
            c = Ctrl_P;
        if (did_wild_list && p_wmnu) {
            if (c == K_LEFT)
                c = Ctrl_P;
            else if (c == K_RIGHT)
                c = Ctrl_N;
        }
        if (xpc.xp_context == EXPAND_MENUNAMES && p_wmnu && ccline.cmdpos > 1 && ccline.cmdbuff[ccline.cmdpos - 1] == '.' && ccline.cmdbuff[ccline.cmdpos - 2] != '\\' && (c == '\n' || c == '\r' || c == K_KENTER))
            c = K_DOWN;
        if (xpc.xp_numfiles != -1 && !(c == p_wc && KeyTyped) && c != p_wcm && c != Ctrl_N && c != Ctrl_P && c != Ctrl_A && c != Ctrl_L) {
            (void) ExpandOne (&xpc, NULL, NULL, 0, WILD_FREE);
            did_wild_list = FALSE;
            if (!p_wmnu || (c != K_UP && c != K_DOWN))
                xpc.xp_context = EXPAND_NOTHING;
            wim_index = 0;
            if (p_wmnu && wild_menu_showing != 0) {
                int skt = KeyTyped;
                int old_RedrawingDisabled = RedrawingDisabled;
                if (ccline.input_fn)
                    RedrawingDisabled = 0;
                if (wild_menu_showing == WM_SCROLLED) {
                    cmdline_row--;
                    redrawcmd ();
                }
                else if (save_p_ls != -1) {
                    p_ls = save_p_ls;
                    p_wmh = save_p_wmh;
                    last_status (FALSE);
                    save_cmdline (& save_ccline);
                    update_screen (VALID);
                    restore_cmdline (& save_ccline);
                    redrawcmd ();
                    save_p_ls = -1;
                }
                else {
                    win_redraw_last_status (topframe);
                    redraw_statuslines ();
                }
                KeyTyped = skt;
                wild_menu_showing = 0;
                if (ccline.input_fn)
                    RedrawingDisabled = old_RedrawingDisabled;
            }
        }
        if (xpc.xp_context == EXPAND_MENUNAMES && p_wmnu) {
            if (c == K_DOWN && ccline.cmdpos > 0 && ccline.cmdbuff[ccline.cmdpos - 1] == '.')
                c = p_wc;
            else if (c == K_UP) {
                int found = FALSE;
                j = (int) (xpc.xp_pattern - ccline.cmdbuff);
                i = 0;
                while (--j > 0) {
                    if (ccline.cmdbuff[j] == ' ' && ccline.cmdbuff[j - 1] != '\\') {
                        i = j + 1;
                        break;
                    }
                    if (ccline.cmdbuff[j] == '.' && ccline.cmdbuff[j - 1] != '\\') {
                        if (found) {
                            i = j + 1;
                            break;
                        }
                        else
                            found = TRUE;
                    }
                }
                if (i > 0)
                    cmdline_del (i);
                c = p_wc;
                xpc.xp_context = EXPAND_NOTHING;
            }
        }
        if ((xpc.xp_context == EXPAND_FILES || xpc.xp_context == EXPAND_DIRECTORIES || xpc.xp_context == EXPAND_SHELLCMD) && p_wmnu) {
            char_u upseg [5];
            upseg[0] = PATHSEP;
            upseg[1] = '.';
            upseg[2] = '.';
            upseg[3] = PATHSEP;
            upseg[4] = NUL;
            if (c == K_DOWN && ccline.cmdpos > 0 && ccline.cmdbuff[ccline.cmdpos - 1] == PATHSEP && (ccline.cmdpos < 3 || ccline.cmdbuff[ccline.cmdpos - 2] != '.' || ccline.cmdbuff[ccline.cmdpos - 3] != '.')) {
                c = p_wc;
            }
            else if (STRNCMP (xpc.xp_pattern, upseg +1, 3) == 0 && c == K_DOWN) {
                int found = FALSE;
                j = ccline.cmdpos;
                i = (int) (xpc.xp_pattern - ccline.cmdbuff);
                while (--j > i) {
                    if (vim_ispathsep (ccline.cmdbuff[j])) {
                        found = TRUE;
                        break;
                    }
                }
                if (found && ccline.cmdbuff[j - 1] == '.' && ccline.cmdbuff[j - 2] == '.' && (vim_ispathsep (ccline.cmdbuff[j - 3]) || j == i + 2)) {
                    cmdline_del (j - 2);
                    c = p_wc;
                }
            }
            else if (c == K_UP) {
                int found = FALSE;
                j = ccline.cmdpos - 1;
                i = (int) (xpc.xp_pattern - ccline.cmdbuff);
                while (--j > i) {
                    if (vim_ispathsep (ccline.cmdbuff[j])) {
                        if (found) {
                            i = j + 1;
                            break;
                        }
                        else
                            found = TRUE;
                    }
                }
                if (!found)
                    j = i;
                else if (STRNCMP (ccline.cmdbuff + j, upseg, 4) == 0)
                    j += 4;
                else if (STRNCMP (ccline.cmdbuff + j, upseg +1, 3) == 0 && j == i)
                    j += 3;
                else
                    j = 0;
                if (j > 0) {
                    cmdline_del (j);
                    put_on_cmdline (upseg + 1, 3, FALSE);
                }
                else if (ccline.cmdpos > i)
                    cmdline_del (i);
                c = p_wc;
                KeyTyped = TRUE;
            }
        }
        if (c == Ctrl_BSL) {
            ++no_mapping;
            ++allow_keys;
            c = plain_vgetc ();
            --no_mapping;
            --allow_keys;
            if (c != Ctrl_N && c != Ctrl_G && (c != 'e' || (ccline.cmdfirstc == '=' && KeyTyped))) {
                vungetc (c);
                c = Ctrl_BSL;
            }
            else if (c == 'e') {
                char_u *p = NULL;
                int len;
                if (ccline.cmdpos == ccline.cmdlen)
                    new_cmdpos = 99999;
                else
                    new_cmdpos = ccline.cmdpos;
                save_cmdline (& save_ccline);
                c = get_expr_register ();
                restore_cmdline (& save_ccline);
                if (c == '=') {
                    save_cmdline (& save_ccline);
                    ++textlock;
                    p = get_expr_line ();
                    --textlock;
                    restore_cmdline (& save_ccline);
                    if (p != NULL) {
                        len = (int) STRLEN (p);
                        if (realloc_cmdbuff (len +1) == OK) {
                            ccline.cmdlen = len;
                            STRCPY (ccline.cmdbuff, p);
                            vim_free (p);
                            if (new_cmdpos > ccline.cmdlen)
                                ccline.cmdpos = ccline.cmdlen;
                            else
                                ccline.cmdpos = new_cmdpos;
                            KeyTyped = FALSE;
                            redrawcmd ();
                            goto cmdline_changed;
                        }
                    }
                }
                beep_flush ();
                got_int = FALSE;
                did_emsg = FALSE;
                emsg_on_display = FALSE;
                redrawcmd ();
                goto cmdline_not_changed;
            }
            else {
                if (c == Ctrl_G && p_im && restart_edit == 0)
                    restart_edit = 'a';
                gotesc = TRUE;
                goto returncmd;
            }
        }
        c = do_digraph (c);
        if (c == '\n' || c == '\r' || c == K_KENTER || (c == ESC && (!KeyTyped || vim_strchr (p_cpo, CPO_ESC) != NULL))) {
            if (exmode_active && c != ESC && ccline.cmdpos == ccline.cmdlen && ccline.cmdpos > 0 && ccline.cmdbuff[ccline.cmdpos - 1] == '\\') {
                if (c == K_KENTER)
                    c = '\n';
            }
            else {
                gotesc = FALSE;
                if (ccheck_abbr (c +ABBR_OFF))
                    goto cmdline_changed;
                if (!cmd_silent) {
                    windgoto (msg_row, 0);
                    out_flush ();
                }
                break;
            }
        }
        if ((c == p_wc && !gotesc && KeyTyped) || c == p_wcm) {
            if (xpc.xp_numfiles > 0) {
                if (xpc.xp_numfiles > 1 && !did_wild_list && (wim_flags[wim_index] & WIM_LIST)) {
                    (void) showmatches (&xpc, FALSE);
                    redrawcmd ();
                    did_wild_list = TRUE;
                }
                if (wim_flags[wim_index] & WIM_LONGEST)
                    res = nextwild (&xpc, WILD_LONGEST, WILD_NO_BEEP, firstc != '@');
                else if (wim_flags[wim_index] & WIM_FULL)
                    res = nextwild (&xpc, WILD_NEXT, WILD_NO_BEEP, firstc != '@');
                else
                    res = OK;
            }
            else {
                wim_index = 0;
                j = ccline.cmdpos;
                if (wim_flags[0] & WIM_LONGEST)
                    res = nextwild (&xpc, WILD_LONGEST, WILD_NO_BEEP, firstc != '@');
                else
                    res = nextwild (&xpc, WILD_EXPAND_KEEP, WILD_NO_BEEP, firstc != '@');
                if (got_int) {
                    (void) vpeekc ();
                    got_int = FALSE;
                    (void) ExpandOne (&xpc, NULL, NULL, 0, WILD_FREE);
                    xpc.xp_context = EXPAND_NOTHING;
                    goto cmdline_changed;
                }
                if (res == OK && xpc.xp_numfiles > 1) {
                    if (wim_flags[0] == WIM_LONGEST && ccline.cmdpos == j)
                        wim_index = 1;
                    if ((wim_flags[wim_index] & WIM_LIST) || (p_wmnu && (wim_flags[wim_index] & WIM_FULL) != 0)) {
                        if (!(wim_flags[0] & WIM_LONGEST)) {
                            int p_wmnu_save = p_wmnu;
                            p_wmnu = 0;
                            nextwild (& xpc, WILD_PREV, 0, firstc != '@');
                            p_wmnu = p_wmnu_save;
                        }
                        (void) showmatches (&xpc, p_wmnu &&((wim_flags[wim_index] & WIM_LIST) == 0));
                        redrawcmd ();
                        did_wild_list = TRUE;
                        if (wim_flags[wim_index] & WIM_LONGEST)
                            nextwild (&xpc, WILD_LONGEST, WILD_NO_BEEP, firstc != '@');
                        else if (wim_flags[wim_index] & WIM_FULL)
                            nextwild (&xpc, WILD_NEXT, WILD_NO_BEEP, firstc != '@');
                    }
                    else
                        vim_beep (BO_WILD);
                }
                else if (xpc.xp_numfiles == -1)
                    xpc.xp_context = EXPAND_NOTHING;
            }
            if (wim_index < 3)
                ++wim_index;
            if (c == ESC)
                gotesc = TRUE;
            if (res == OK)
                goto cmdline_changed;
        }
        gotesc = FALSE;
        if (c == K_S_TAB && KeyTyped) {
            if (nextwild (&xpc, WILD_EXPAND_KEEP, 0, firstc != '@') == OK && nextwild (&xpc, WILD_PREV, 0, firstc != '@') == OK && nextwild (&xpc, WILD_PREV, 0, firstc != '@') == OK)
                goto cmdline_changed;
        }
        if (c == NUL || c == K_ZERO)
            c = NL;
        do_abbr = TRUE;
        switch (c) {
        case K_BS :
        case Ctrl_H :
        case K_DEL :
        case K_KDEL :
        case Ctrl_W :
            if (cmd_fkmap && c == K_BS)
                c = K_DEL;
            if (c == K_KDEL)
                c = K_DEL;
            if (c == K_DEL && ccline.cmdpos != ccline.cmdlen)
                ++ccline.cmdpos;
            if (ccline.cmdpos > 0) {
                char_u *p;
                j = ccline.cmdpos;
                p = ccline.cmdbuff + j;
                if (c == Ctrl_W) {
                    while (p > ccline.cmdbuff && vim_isspace (p[-1]))
                        --p;
                    i = vim_iswordc (p[-1]);
                    while (p > ccline.cmdbuff && !vim_isspace (p[-1]) && vim_iswordc (p[-1]) == i)
                        --p;
                }
                else
                    --p;
                ccline.cmdpos = (int) (p - ccline.cmdbuff);
                ccline.cmdlen -= j - ccline.cmdpos;
                i = ccline.cmdpos;
                while (i < ccline.cmdlen)
                    ccline.cmdbuff[i++] = ccline.cmdbuff[j++];
                ccline.cmdbuff[ccline.cmdlen] = NUL;
                if (ccline.cmdlen == 0) {
                    search_start = save_cursor;
                    old_curswant = init_curswant;
                    old_leftcol = init_leftcol;
                    old_topline = init_topline;
                    old_topfill = init_topfill;
                    old_botline = init_botline;
                }
                redrawcmd ();
            }
            else if (ccline.cmdlen == 0 && c != Ctrl_W && ccline.cmdprompt == NULL && indent == 0) {
                if (exmode_active || ccline.cmdfirstc == '>')
                    goto cmdline_not_changed;
                VIM_CLEAR (ccline.cmdbuff);
                if (!cmd_silent) {
                    if (cmdmsg_rl)
                        msg_col = Columns;
                    else
                        msg_col = 0;
                    msg_putchar (' ');
                }
                if (ccline.cmdlen == 0)
                    search_start = save_cursor;
                redraw_cmdline = TRUE;
                goto returncmd;
            }
            goto cmdline_changed;
        case K_INS :
        case K_KINS :
            if (cmd_fkmap)
                beep_flush ();
            else
                ccline.overstrike = !ccline.overstrike;
            goto cmdline_not_changed;
        case Ctrl_HAT :
            if (map_to_exists_mode ((char_u *) "", LANGMAP, FALSE)) {
                State ^= LANGMAP;
                if (b_im_ptr != NULL) {
                    if (State & LANGMAP)
                        *b_im_ptr = B_IMODE_LMAP;
                    else
                        *b_im_ptr = B_IMODE_NONE;
                }
            }
            if (b_im_ptr != NULL) {
                if (b_im_ptr == &curbuf->b_p_iminsert)
                    set_iminsert_global ();
                else
                    set_imsearch_global ();
            }
            status_redraw_curbuf ();
            goto cmdline_not_changed;
        case Ctrl_U :
            j = ccline.cmdpos;
            ccline.cmdlen -= j;
            i = ccline.cmdpos = 0;
            while (i < ccline.cmdlen)
                ccline.cmdbuff[i++] = ccline.cmdbuff[j++];
            ccline.cmdbuff[ccline.cmdlen] = NUL;
            if (ccline.cmdlen == 0)
                search_start = save_cursor;
            redrawcmd ();
            goto cmdline_changed;
        case ESC :
        case Ctrl_C :
            if (exmode_active && (ex_normal_busy == 0 || typebuf.tb_len > 0))
                goto cmdline_not_changed;
            gotesc = TRUE;
            goto returncmd;
        case Ctrl_R :
            putcmdline ('"', TRUE);
            ++no_mapping;
            i = c = plain_vgetc ();
            if (i == Ctrl_O)
                i = Ctrl_R;
            if (i == Ctrl_R)
                c = plain_vgetc ();
            extra_char = NUL;
            --no_mapping;
            new_cmdpos = -1;
            if (c == '=') {
                if (ccline.cmdfirstc == '=') {
                    beep_flush ();
                    c = ESC;
                }
                else {
                    save_cmdline (& save_ccline);
                    c = get_expr_register ();
                    restore_cmdline (& save_ccline);
                }
            }
            if (c != ESC) {
                cmdline_paste (c, i == Ctrl_R, FALSE);
                if (aborting ()) {
                    gotesc = TRUE;
                    goto returncmd;
                }
                KeyTyped = FALSE;
                if (new_cmdpos >= 0) {
                    if (new_cmdpos > ccline.cmdlen)
                        ccline.cmdpos = ccline.cmdlen;
                    else
                        ccline.cmdpos = new_cmdpos;
                }
            }
            redrawcmd ();
            goto cmdline_changed;
        case Ctrl_D :
            if (showmatches (&xpc, FALSE) == EXPAND_NOTHING)
                break;
            redrawcmd ();
            continue;
        case K_RIGHT :
        case K_S_RIGHT :
        case K_C_RIGHT :
            do {
                if (ccline.cmdpos >= ccline.cmdlen)
                    break;
                i = cmdline_charsize (ccline.cmdpos);
                if (KeyTyped && ccline.cmdspos + i >= Columns * Rows)
                    break;
                ccline.cmdspos += i;
                ++ccline.cmdpos;
            }
            while ((c == K_S_RIGHT || c == K_C_RIGHT || (mod_mask & (MOD_MASK_SHIFT | MOD_MASK_CTRL))) && ccline.cmdbuff[ccline.cmdpos] != ' ');
            goto cmdline_not_changed;
        case K_LEFT :
        case K_S_LEFT :
        case K_C_LEFT :
            if (ccline.cmdpos == 0)
                goto cmdline_not_changed;
            do {
                --ccline.cmdpos;
                ccline.cmdspos -= cmdline_charsize (ccline.cmdpos);
            }
            while (ccline.cmdpos > 0 && (c == K_S_LEFT || c == K_C_LEFT || (mod_mask & (MOD_MASK_SHIFT | MOD_MASK_CTRL))) && ccline.cmdbuff[ccline.cmdpos - 1] != ' ');
            goto cmdline_not_changed;
        case K_IGNORE :
            goto cmdline_not_changed;
        case K_MIDDLEDRAG :
        case K_MIDDLERELEASE :
            goto cmdline_not_changed;
        case K_MIDDLEMOUSE :
            if (!gui.in_use)
                if (!mouse_has (MOUSE_COMMAND))
                    goto cmdline_not_changed;
            cmdline_paste (0, TRUE, TRUE);
            redrawcmd ();
            goto cmdline_changed;
        case K_LEFTDRAG :
        case K_LEFTRELEASE :
        case K_RIGHTDRAG :
        case K_RIGHTRELEASE :
            if (ignore_drag_release)
                goto cmdline_not_changed;
        case K_LEFTMOUSE :
        case K_RIGHTMOUSE :
            if (c == K_LEFTRELEASE || c == K_RIGHTRELEASE)
                ignore_drag_release = TRUE;
            else
                ignore_drag_release = FALSE;
            if (!gui.in_use)
                if (!mouse_has (MOUSE_COMMAND))
                    goto cmdline_not_changed;
            set_cmdspos ();
            for (ccline.cmdpos = 0; ccline.cmdpos < ccline.cmdlen; ++ccline.cmdpos) {
                i = cmdline_charsize (ccline.cmdpos);
                if (mouse_row <= cmdline_row + ccline.cmdspos / Columns && mouse_col < ccline.cmdspos % Columns + i)
                    break;
                ccline.cmdspos += i;
            }
            goto cmdline_not_changed;
        case K_MOUSEDOWN :
        case K_MOUSEUP :
        case K_MOUSELEFT :
        case K_MOUSERIGHT :
        case K_X1MOUSE :
        case K_X1DRAG :
        case K_X1RELEASE :
        case K_X2MOUSE :
        case K_X2DRAG :
        case K_X2RELEASE :
        case K_MOUSEMOVE :
            goto cmdline_not_changed;
        case K_SWIPELEFT :
        case K_SWIPERIGHT :
        case K_SWIPEUP :
        case K_SWIPEDOWN :
            goto cmdline_not_changed;
        case K_LEFTMOUSE_NM :
        case K_LEFTRELEASE_NM :
            goto cmdline_not_changed;
        case K_VER_SCROLLBAR :
            if (msg_scrolled == 0) {
                gui_do_scroll ();
                redrawcmd ();
            }
            goto cmdline_not_changed;
        case K_HOR_SCROLLBAR :
            if (msg_scrolled == 0) {
                gui_do_horiz_scroll (scrollbar_value, FALSE);
                redrawcmd ();
            }
            goto cmdline_not_changed;
        case K_SELECT :
            goto cmdline_not_changed;
        case Ctrl_B :
        case K_HOME :
        case K_KHOME :
        case K_S_HOME :
        case K_C_HOME :
            ccline.cmdpos = 0;
            set_cmdspos ();
            goto cmdline_not_changed;
        case Ctrl_E :
        case K_END :
        case K_KEND :
        case K_S_END :
        case K_C_END :
            ccline.cmdpos = ccline.cmdlen;
            set_cmdspos_cursor ();
            goto cmdline_not_changed;
        case Ctrl_A :
            if (nextwild (&xpc, WILD_ALL, 0, firstc != '@') == FAIL)
                break;
            goto cmdline_changed;
        case Ctrl_L :
            if (p_is && !cmd_silent && (firstc == '/' || firstc == '?')) {
                if (did_incsearch) {
                    curwin->w_cursor = match_end;
                    if (!EQUAL_POS (curwin->w_cursor, search_start)) {
                        c = gchar_cursor ();
                        if (p_ic && p_scs && !pat_has_uppercase (ccline.cmdbuff))
                            c = MB_TOLOWER (c);
                        if (c != NUL) {
                            if (c == firstc || vim_strchr ((char_u *) (p_magic ? "\\~^$.*[" : "\\^$"), c) != NULL) {
                                stuffcharReadbuff (c);
                                c = '\\';
                            }
                            break;
                        }
                    }
                }
                goto cmdline_not_changed;
            }
            if (nextwild (&xpc, WILD_LONGEST, 0, firstc != '@') == FAIL)
                break;
            goto cmdline_changed;
        case Ctrl_N :
        case Ctrl_P :
            if (xpc.xp_numfiles > 0) {
                if (nextwild (&xpc, (c == Ctrl_P) ? WILD_PREV : WILD_NEXT, 0, firstc != '@') == FAIL)
                    break;
                goto cmdline_not_changed;
            }
            goto cmdline_not_changed;
        case Ctrl_G :
        case Ctrl_T :
            if (p_is && !cmd_silent && (firstc == '/' || firstc == '?')) {
                pos_T t;
                char_u *pat;
                int search_flags = SEARCH_NOOF;
                if (ccline.cmdlen == 0)
                    goto cmdline_not_changed;
                if (firstc == ccline.cmdbuff[0])
                    pat = last_search_pattern ();
                else
                    pat = ccline.cmdbuff;
                save_last_search_pattern ();
                cursor_off ();
                out_flush ();
                if (c == Ctrl_G) {
                    t = match_end;
                    if (LT_POS (match_start, match_end))
                        (void) decl (&t);
                    search_flags += SEARCH_COL;
                }
                else
                    t = match_start;
                if (!p_hls)
                    search_flags += SEARCH_KEEP;
                ++emsg_off;
                i = searchit (curwin, curbuf, &t, c == Ctrl_G ? FORWARD : BACKWARD, pat, count, search_flags, RE_SEARCH, 0, NULL, NULL);
                --emsg_off;
                if (i) {
                    search_start = match_start;
                    match_end = t;
                    match_start = t;
                    if (c == Ctrl_T && firstc == '/') {
                        search_start = t;
                        (void) decl (&search_start);
                    }
                    else if (c == Ctrl_G && firstc == '?') {
                        search_start = t;
                        (void) incl (&search_start);
                    }
                    if (LT_POS (t, search_start) && c == Ctrl_G) {
                        search_start = t;
                        if (firstc == '?')
                            (void) incl (&search_start);
                        else
                            (void) decl (&search_start);
                    }
                    set_search_match (& match_end);
                    curwin->w_cursor = match_start;
                    changed_cline_bef_curs ();
                    update_topline ();
                    validate_cursor ();
                    highlight_match = TRUE;
                    old_curswant = curwin->w_curswant;
                    old_leftcol = curwin->w_leftcol;
                    old_topline = curwin->w_topline;
                    old_topfill = curwin->w_topfill;
                    old_botline = curwin->w_botline;
                    update_screen (NOT_VALID);
                    redrawcmdline ();
                }
                else
                    vim_beep (BO_ERROR);
                restore_last_search_pattern ();
                goto cmdline_not_changed;
            }
            break;
        case Ctrl_V :
        case Ctrl_Q :
            ignore_drag_release = TRUE;
            putcmdline ('^', TRUE);
            c = get_literal ();
            do_abbr = FALSE;
            extra_char = NUL;
            break;
        case Ctrl_K :
            ignore_drag_release = TRUE;
            putcmdline ('?', TRUE);
            c = get_digraph (TRUE);
            extra_char = NUL;
            if (c != NUL)
                break;
            redrawcmd ();
            goto cmdline_not_changed;
        case Ctrl__ :
            if (!p_ari)
                break;
            if (p_altkeymap) {
                cmd_fkmap = !cmd_fkmap;
                if (cmd_fkmap)
                    ccline.overstrike = FALSE;
            }
            else
                cmd_hkmap = !cmd_hkmap;
            goto cmdline_not_changed;
        case K_PS :
            bracketed_paste (PASTE_CMDLINE, FALSE, NULL);
            goto cmdline_changed;
        default :
            if (c == intr_char) {
                gotesc = TRUE;
                goto returncmd;
            }
            if (!IS_SPECIAL (c))
                mod_mask = 0x0;
            break;
        }
        if (do_abbr && (IS_SPECIAL (c) || !vim_iswordc (c)) && (ccheck_abbr (c) || c == Ctrl_RSB))
            goto cmdline_changed;
        if (IS_SPECIAL (c) || mod_mask != 0)
            put_on_cmdline (get_special_key_name (c, mod_mask), -1, TRUE);
        else {
            {
                IObuff[0] = c;
                put_on_cmdline (IObuff, 1, TRUE);
            }
        }
        goto cmdline_changed;
    cmdline_not_changed :
        if (!incsearch_postponed)
            continue;
    cmdline_changed :
        trigger_cmd_autocmd (cmdline_type, EVENT_CMDLINECHANGED);
        if (p_is && !cmd_silent && (firstc == '/' || firstc == '?')) {
            pos_T end_pos;
            proftime_T tm;
            if (char_avail ()) {
                incsearch_postponed = TRUE;
                continue;
            }
            incsearch_postponed = FALSE;
            curwin->w_cursor = search_start;
            save_last_search_pattern ();
            if (ccline.cmdlen == 0) {
                i = 0;
                SET_NO_HLSEARCH (TRUE);
                redraw_all_later (SOME_VALID);
            }
            else {
                int search_flags = SEARCH_OPT + SEARCH_NOOF + SEARCH_PEEK;
                cursor_off ();
                out_flush ();
                ++emsg_off;
                profile_setlimit (500L, & tm);
                if (!p_hls)
                    search_flags += SEARCH_KEEP;
                i = do_search (NULL, firstc, ccline.cmdbuff, count, search_flags, &tm, NULL);
                --emsg_off;
                if (got_int) {
                    (void) vpeekc ();
                    got_int = FALSE;
                    i = 0;
                }
                else if (char_avail ())
                    incsearch_postponed = TRUE;
            }
            if (i != 0)
                highlight_match = TRUE;
            else
                highlight_match = FALSE;
            curwin->w_leftcol = old_leftcol;
            curwin->w_topline = old_topline;
            curwin->w_topfill = old_topfill;
            curwin->w_botline = old_botline;
            changed_cline_bef_curs ();
            update_topline ();
            if (i != 0) {
                pos_T save_pos = curwin->w_cursor;
                match_start = curwin->w_cursor;
                set_search_match (& curwin -> w_cursor);
                validate_cursor ();
                end_pos = curwin->w_cursor;
                match_end = end_pos;
                curwin->w_cursor = save_pos;
            }
            else
                end_pos = curwin->w_cursor;
            if (empty_pattern (ccline.cmdbuff))
                SET_NO_HLSEARCH (TRUE);
            validate_cursor ();
            if (p_ru && curwin->w_status_height > 0)
                curwin->w_redr_status = TRUE;
            save_cmdline (& save_ccline);
            update_screen (SOME_VALID);
            restore_cmdline (& save_ccline);
            restore_last_search_pattern ();
            if (i != 0)
                curwin->w_cursor = end_pos;
            msg_starthere ();
            redrawcmdline ();
            did_incsearch = TRUE;
        }
        if (cmdmsg_rl || (p_arshape && !p_tbidi && enc_utf8))
            if (vpeekc () == NUL)
                redrawcmd ();
    }
returncmd :
    cmdmsg_rl = FALSE;
    cmd_fkmap = 0;
    ExpandCleanup (& xpc);
    ccline.xpc = NULL;
    if (did_incsearch) {
        if (gotesc)
            curwin->w_cursor = save_cursor;
        else {
            if (!EQUAL_POS (save_cursor, search_start)) {
                curwin->w_cursor = save_cursor;
                setpcmark ();
            }
            curwin->w_cursor = search_start;
        }
        curwin->w_curswant = old_curswant;
        curwin->w_leftcol = old_leftcol;
        curwin->w_topline = old_topline;
        curwin->w_topfill = old_topfill;
        curwin->w_botline = old_botline;
        highlight_match = FALSE;
        validate_cursor ();
        redraw_all_later (SOME_VALID);
    }
    if (ccline.cmdbuff != NULL) {
        if (gotesc)
            abandon_cmdline ();
    }
    msg_check ();
    msg_scroll = save_msg_scroll;
    redir_off = FALSE;
    if (some_key_typed)
        need_wait_return = FALSE;
    trigger_cmd_autocmd (cmdline_type, EVENT_CMDLINELEAVE);
    State = save_State;
    setmouse ();
    sb_text_end_cmdline ();
    {
        char_u *p = ccline.cmdbuff;
        ccline.cmdbuff = NULL;
        return p;
    }
}

void ExpandInit (expand_T *xp) {
    xp->xp_pattern = NULL;
    xp->xp_pattern_len = 0;
    xp->xp_backslash = XP_BS_NONE;
    xp->xp_shell = FALSE;
    xp->xp_numfiles = -1;
    xp->xp_files = NULL;
    xp->xp_arg = NULL;
    xp->xp_line = NULL;
}

static void redrawcmdprompt (void) {
    int i;
    if (cmd_silent)
        return;
    if (ccline.cmdfirstc != NUL)
        msg_putchar (ccline.cmdfirstc);
    if (ccline.cmdprompt != NULL) {
        msg_puts_attr (ccline.cmdprompt, ccline.cmdattr);
        ccline.cmdindent = msg_col + (msg_row - cmdline_row) * Columns;
        if (ccline.cmdfirstc != NUL)
            --ccline.cmdindent;
    }
    else
        for (i = ccline.cmdindent; i > 0; --i)
            msg_putchar (' ');
}

static void set_cmdspos (void) {
    if (ccline.cmdfirstc != NUL)
        ccline.cmdspos = 1 + ccline.cmdindent;
    else
        ccline.cmdspos = 0 + ccline.cmdindent;
}

static void trigger_cmd_autocmd (int typechar, int evt) {
    char_u typestr [2];
    typestr[0] = typechar;
    typestr[1] = NUL;
    apply_autocmds (evt, typestr, typestr, FALSE, curbuf);
}

void redrawcmd (void) {
    if (cmd_silent)
        return;
    if (ccline.cmdbuff == NULL) {
        windgoto (cmdline_row, 0);
        msg_clr_eos ();
        return;
    }
    msg_start ();
    redrawcmdprompt ();
    msg_no_more = TRUE;
    draw_cmdline (0, ccline.cmdlen);
    msg_clr_eos ();
    msg_no_more = FALSE;
    set_cmdspos_cursor ();
    if (extra_char != NUL)
        putcmdline (extra_char, extra_char_shift);
    msg_scroll = FALSE;
    skip_redraw = FALSE;
}

static void set_cmdspos_cursor (void) {
    int i, m, c;
    set_cmdspos ();
    if (KeyTyped) {
        m = Columns * Rows;
        if (m < 0)
            m = MAXCOL;
    }
    else
        m = MAXCOL;
    for (i = 0; i < ccline.cmdlen && i < ccline.cmdpos; ++i) {
        c = cmdline_charsize (i);
        if ((ccline.cmdspos += c) >= m) {
            ccline.cmdspos -= c;
            break;
        }
    }
}

void putcmdline (int c, int shift) {
    if (cmd_silent)
        return;
    msg_no_more = TRUE;
    msg_putchar (c);
    if (shift)
        draw_cmdline (ccline.cmdpos, ccline.cmdlen - ccline.cmdpos);
    msg_no_more = FALSE;
    cursorcmd ();
    extra_char = c;
    extra_char_shift = shift;
}

void cmd_pchar (int c, int offset) {
    if (ccline.cmdpos + offset >= ccline.cmdlen || ccline.cmdpos + offset < 0) {
        EMSG (_ ("E198: cmd_pchar beyond the command length"));
        return;
    }
    ccline.cmdbuff[ccline.cmdpos + offset] = (char_u) c;
    ccline.cmdbuff[ccline.cmdlen] = NUL;
}

void redrawcmdline (void) {
    redrawcmdline_ex (TRUE);
}

void redrawcmdline_ex (int do_compute_cmdrow) {
    if (cmd_silent)
        return;
    need_wait_return = FALSE;
    if (do_compute_cmdrow)
        compute_cmdrow ();
    redrawcmd ();
    cursorcmd ();
}

char_u *ExpandOne (expand_T *xp, char_u *str, char_u *orig, int options, int mode) {
    char_u *ss = NULL;
    static int findex;
    static char_u *orig_save = NULL;
    int orig_saved = FALSE;
    int i;
    long_u len;
    int non_suf_match;
    if (mode == WILD_NEXT || mode == WILD_PREV) {
        if (xp->xp_numfiles > 0) {
            if (mode == WILD_PREV) {
                if (findex == -1)
                    findex = xp->xp_numfiles;
                --findex;
            }
            else
                ++findex;
            if (findex < 0) {
                if (orig_save == NULL)
                    findex = xp->xp_numfiles - 1;
                else
                    findex = -1;
            }
            if (findex >= xp->xp_numfiles) {
                if (orig_save == NULL)
                    findex = 0;
                else
                    findex = -1;
            }
            if (p_wmnu)
                win_redr_status_matches (xp, xp->xp_numfiles, xp->xp_files, findex, cmd_showtail);
            if (findex == -1)
                return vim_strsave (orig_save);
            return vim_strsave (xp->xp_files[findex]);
        }
        else
            return NULL;
    }
    if (xp->xp_numfiles != -1 && mode != WILD_ALL && mode != WILD_LONGEST) {
        FreeWild (xp -> xp_numfiles, xp -> xp_files);
        xp->xp_numfiles = -1;
        VIM_CLEAR (orig_save);
    }
    findex = 0;
    if (mode == WILD_FREE)
        return NULL;
    if (xp->xp_numfiles == -1) {
        vim_free (orig_save);
        orig_save = orig;
        orig_saved = TRUE;
        if (ExpandFromContext (xp, str, &xp->xp_numfiles, &xp->xp_files, options) == FAIL) {
        }
        else if (xp->xp_numfiles == 0) {
            if (!(options & WILD_SILENT))
                EMSG2 (_ (e_nomatch2), str);
        }
        else {
            ExpandEscape (xp, str, xp -> xp_numfiles, xp -> xp_files, options);
            if (mode != WILD_ALL && mode != WILD_ALL_KEEP && mode != WILD_LONGEST) {
                if (xp->xp_numfiles)
                    non_suf_match = xp->xp_numfiles;
                else
                    non_suf_match = 1;
                if ((xp->xp_context == EXPAND_FILES || xp->xp_context == EXPAND_DIRECTORIES) && xp->xp_numfiles > 1) {
                    non_suf_match = 0;
                    for (i = 0; i < 2; ++i)
                        if (match_suffix (xp->xp_files[i]))
                            ++non_suf_match;
                }
                if (non_suf_match != 1) {
                    if (!(options & WILD_SILENT))
                        EMSG (_ (e_toomany));
                    else if (!(options & WILD_NO_BEEP))
                        beep_flush ();
                }
                if (!(non_suf_match != 1 && mode == WILD_EXPAND_FREE))
                    ss = vim_strsave (xp->xp_files[0]);
            }
        }
    }
    if (mode == WILD_LONGEST && xp->xp_numfiles > 0) {
        int mb_len = 1;
        int c0, ci;
        for (len = 0; xp->xp_files[0][len]; len += mb_len) {
            c0 = xp->xp_files[0][len];
            for (i = 1; i < xp->xp_numfiles; ++i) {
                ci = xp->xp_files[i][len];
                if (p_fic && (xp->xp_context == EXPAND_DIRECTORIES || xp->xp_context == EXPAND_FILES || xp->xp_context == EXPAND_SHELLCMD || xp->xp_context == EXPAND_BUFFERS)) {
                    if (MB_TOLOWER (c0) != MB_TOLOWER (ci))
                        break;
                }
                else if (c0 != ci)
                    break;
            }
            if (i < xp->xp_numfiles) {
                if (!(options & WILD_NO_BEEP))
                    vim_beep (BO_WILD);
                break;
            }
        }
        ss = alloc ((unsigned ) len + 1);
        if (ss)
            vim_strncpy (ss, xp->xp_files[0], (size_t) len);
        findex = -1;
    }
    if (mode == WILD_ALL && xp->xp_numfiles > 0) {
        len = 0;
        for (i = 0; i < xp->xp_numfiles; ++i)
            len += (long_u) STRLEN (xp->xp_files[i]) + 1;
        ss = lalloc (len, TRUE);
        if (ss != NULL) {
            *ss = NUL;
            for (i = 0; i < xp->xp_numfiles; ++i) {
                STRCAT (ss, xp -> xp_files [i]);
                if (i != xp->xp_numfiles - 1)
                    STRCAT (ss, (options & WILD_USE_NL) ? "\n" : " ");
            }
        }
    }
    if (mode == WILD_EXPAND_FREE || mode == WILD_ALL)
        ExpandCleanup (xp);
    if (!orig_saved)
        vim_free (orig);
    return ss;
}

static int ExpandFromContext (expand_T *xp, char_u *pat, int *num_file, char_u ***file, int options) {
    regmatch_T regmatch;
    int ret;
    int flags;
    flags = EW_DIR;
    if (options & WILD_LIST_NOTFOUND)
        flags |= EW_NOTFOUND;
    if (options & WILD_ADD_SLASH)
        flags |= EW_ADDSLASH;
    if (options & WILD_KEEP_ALL)
        flags |= EW_KEEPALL;
    if (options & WILD_SILENT)
        flags |= EW_SILENT;
    if (options & WILD_ALLLINKS)
        flags |= EW_ALLLINKS;
    if (xp->xp_context == EXPAND_FILES || xp->xp_context == EXPAND_DIRECTORIES || xp->xp_context == EXPAND_FILES_IN_PATH) {
        int free_pat = FALSE;
        int i;
        if (xp->xp_backslash != XP_BS_NONE) {
            free_pat = TRUE;
            pat = vim_strsave (pat);
            for (i = 0; pat[i]; ++i)
                if (pat[i] == '\\') {
                    if (xp->xp_backslash == XP_BS_THREE && pat[i + 1] == '\\' && pat[i + 2] == '\\' && pat[i + 3] == ' ')
                        STRMOVE (pat +i, pat +i + 3);
                    if (xp->xp_backslash == XP_BS_ONE && pat[i + 1] == ' ')
                        STRMOVE (pat +i, pat +i + 1);
                }
        }
        if (xp->xp_context == EXPAND_FILES)
            flags |= EW_FILE;
        else if (xp->xp_context == EXPAND_FILES_IN_PATH)
            flags |= (EW_FILE | EW_PATH);
        else
            flags = (flags | EW_DIR) & ~EW_FILE;
        if (options & WILD_ICASE)
            flags |= EW_ICASE;
        ret = expand_wildcards_eval (&pat, num_file, file, flags);
        if (free_pat)
            vim_free (pat);
        return ret;
    }
    *file = (char_u **) "";
    *num_file = 0;
    if (xp->xp_context == EXPAND_HELP) {
        if (find_help_tags (*pat == NUL ? (char_u *) "help" : pat, num_file, file, FALSE) == OK) {
            cleanup_help_tags (* num_file, * file);
            return OK;
        }
        return FAIL;
    }
    if (xp->xp_context == EXPAND_SHELLCMD)
        return expand_shellcmd (pat, num_file, file, flags);
    if (xp->xp_context == EXPAND_OLD_SETTING)
        return ExpandOldSetting (num_file, file);
    if (xp->xp_context == EXPAND_BUFFERS)
        return ExpandBufnames (pat, num_file, file, options);
    if (xp->xp_context == EXPAND_TAGS || xp->xp_context == EXPAND_TAGS_LISTFILES)
        return expand_tags (xp->xp_context == EXPAND_TAGS, pat, num_file, file);
    if (xp->xp_context == EXPAND_COLORS) {
        char *directories [] = {"colors", NULL};
        return ExpandRTDir (pat, DIP_START +DIP_OPT, num_file, file, directories);
    }
    if (xp->xp_context == EXPAND_COMPILER) {
        char *directories [] = {"compiler", NULL};
        return ExpandRTDir (pat, 0, num_file, file, directories);
    }
    if (xp->xp_context == EXPAND_OWNSYNTAX) {
        char *directories [] = {"syntax", NULL};
        return ExpandRTDir (pat, 0, num_file, file, directories);
    }
    if (xp->xp_context == EXPAND_FILETYPE) {
        char *directories [] = {"syntax", "indent", "ftplugin", NULL};
        return ExpandRTDir (pat, 0, num_file, file, directories);
    }
    if (xp->xp_context == EXPAND_USER_LIST)
        return ExpandUserList (xp, num_file, file);
    if (xp->xp_context == EXPAND_PACKADD)
        return ExpandPackAddDir (pat, num_file, file);
    regmatch.regprog = vim_regcomp (pat, p_magic ? RE_MAGIC : 0);
    if (regmatch.regprog == NULL)
        return FAIL;
    regmatch.rm_ic = ignorecase (pat);
    if (xp->xp_context == EXPAND_SETTINGS || xp->xp_context == EXPAND_BOOL_SETTINGS)
        ret = ExpandSettings (xp, &regmatch, num_file, file);
    else if (xp->xp_context == EXPAND_MAPPINGS)
        ret = ExpandMappings (&regmatch, num_file, file);
    else if (xp->xp_context == EXPAND_USER_DEFINED)
        ret = ExpandUserDefined (xp, &regmatch, num_file, file);
    else {
        static struct expgen {
            int context;
            char_u * ((*func) (expand_T *, int));
            int ic;
            int escaped;
        } tab [] = {{EXPAND_COMMANDS, get_command_name, FALSE, TRUE}, {EXPAND_BEHAVE, get_behave_arg, TRUE, TRUE}, {EXPAND_MAPCLEAR, get_mapclear_arg, TRUE, TRUE}, {EXPAND_MESSAGES, get_messages_arg, TRUE, TRUE}, {EXPAND_USER_COMMANDS, get_user_commands, FALSE, TRUE}, {EXPAND_USER_ADDR_TYPE, get_user_cmd_addr_type, FALSE, TRUE}, {EXPAND_USER_CMD_FLAGS, get_user_cmd_flags, FALSE, TRUE}, {EXPAND_USER_NARGS, get_user_cmd_nargs, FALSE, TRUE}, {EXPAND_USER_COMPLETE, get_user_cmd_complete, FALSE, TRUE}, {EXPAND_USER_VARS, get_user_var_name, FALSE, TRUE}, {EXPAND_FUNCTIONS, get_function_name, FALSE, TRUE}, {EXPAND_USER_FUNC, get_user_func_name, FALSE, TRUE}, {EXPAND_EXPRESSION, get_expr_name, FALSE, TRUE}, {EXPAND_MENUS, get_menu_name, FALSE, TRUE}, {EXPAND_MENUNAMES, get_menu_names, FALSE, TRUE}, {EXPAND_SYNTAX, get_syntax_name, TRUE, TRUE}, {EXPAND_SYNTIME, get_syntime_arg, TRUE, TRUE}, {EXPAND_HIGHLIGHT, get_highlight_name, TRUE, TRUE}, {EXPAND_EVENTS, get_event_name, TRUE, TRUE}, {EXPAND_AUGROUP, get_augroup_name, TRUE, TRUE}, {EXPAND_SIGN, get_sign_name, TRUE, TRUE}, {EXPAND_PROFILE, get_profile_name, TRUE, TRUE}, {EXPAND_ENV_VARS, get_env_name, TRUE, TRUE}, {EXPAND_USER, get_users, TRUE, FALSE}, {EXPAND_MACACTION, get_macaction_name, FALSE, FALSE},};
        int i;
        ret = FAIL;
        for (i = 0; i < (int) (sizeof (tab) / sizeof (struct expgen)); ++i)
            if (xp->xp_context == tab[i].context) {
                if (tab[i].ic)
                    regmatch.rm_ic = TRUE;
                ret = ExpandGeneric (xp, &regmatch, num_file, file, tab[i].func, tab[i].escaped);
                break;
            }
    }
    vim_regfree (regmatch.regprog);
    return ret;
}

void tilde_replace (char_u *orig_pat, int num_files, char_u **files) {
    int i;
    char_u *p;
    if (orig_pat[0] == '~' && vim_ispathsep (orig_pat[1])) {
        for (i = 0; i < num_files; ++i) {
            p = home_replace_save (NULL, files[i]);
            if (p != NULL) {
                vim_free (files [i]);
                files[i] = p;
            }
        }
    }
}

int expand_cmdline (expand_T *xp, char_u *str, int col, int *matchcount, char_u ***matches) {
    char_u *file_str = NULL;
    int options = WILD_ADD_SLASH | WILD_SILENT;
    if (xp->xp_context == EXPAND_UNSUCCESSFUL) {
        beep_flush ();
        return EXPAND_UNSUCCESSFUL;
    }
    if (xp->xp_context == EXPAND_NOTHING) {
        return EXPAND_NOTHING;
    }
    xp->xp_pattern_len = (int) (str + col - xp->xp_pattern);
    file_str = addstar (xp->xp_pattern, xp->xp_pattern_len, xp->xp_context);
    if (file_str == NULL)
        return EXPAND_UNSUCCESSFUL;
    if (p_wic)
        options += WILD_ICASE;
    if (ExpandFromContext (xp, file_str, matchcount, matches, options) == FAIL) {
        *matchcount = 0;
        *matches = NULL;
    }
    vim_free (file_str);
    return EXPAND_OK;
}

char_u *addstar (char_u *fname, int len, int context) {
    char_u *retval;
    int i, j;
    int new_len;
    char_u *tail;
    int ends_in_star;
    if (context != EXPAND_FILES && context != EXPAND_FILES_IN_PATH && context != EXPAND_SHELLCMD && context != EXPAND_DIRECTORIES) {
        if (context == EXPAND_HELP || context == EXPAND_COLORS || context == EXPAND_COMPILER || context == EXPAND_OWNSYNTAX || context == EXPAND_FILETYPE || context == EXPAND_PACKADD || ((context == EXPAND_TAGS_LISTFILES || context == EXPAND_TAGS) && fname[0] == '/'))
            retval = vim_strnsave (fname, len);
        else {
            new_len = len + 2;
            for (i = 0; i < len; i++) {
                if (fname[i] == '*' || fname[i] == '~')
                    new_len++;
                if (context == EXPAND_BUFFERS && fname[i] == '.')
                    new_len++;
                if ((context == EXPAND_USER_DEFINED || context == EXPAND_USER_LIST) && fname[i] == '\\')
                    new_len++;
            }
            retval = alloc (new_len);
            if (retval != NULL) {
                retval[0] = '^';
                j = 1;
                for (i = 0; i < len; i++, j++) {
                    if (context != EXPAND_USER_DEFINED && context != EXPAND_USER_LIST && fname[i] == '\\' && ++i == len)
                        break;
                    switch (fname[i]) {
                    case '*' :
                        retval[j++] = '.';
                        break;
                    case '~' :
                        retval[j++] = '\\';
                        break;
                    case '?' :
                        retval[j] = '.';
                        continue;
                    case '.' :
                        if (context == EXPAND_BUFFERS)
                            retval[j++] = '\\';
                        break;
                    case '\\' :
                        if (context == EXPAND_USER_DEFINED || context == EXPAND_USER_LIST)
                            retval[j++] = '\\';
                        break;
                    }
                    retval[j] = fname[i];
                }
                retval[j] = NUL;
            }
        }
    }
    else {
        retval = alloc (len +4);
        if (retval != NULL) {
            vim_strncpy (retval, fname, len);
            tail = gettail (retval);
            ends_in_star = (len > 0 && retval[len - 1] == '*');
            for (i = len - 2; i >= 0; --i) {
                if (retval[i] != '\\')
                    break;
                ends_in_star = !ends_in_star;
            }
            if ((*retval != '~' || tail != retval) && !ends_in_star && vim_strchr (tail, '$') == NULL && vim_strchr (retval, '`') == NULL)
                retval[len++] = '*';
            else if (len > 0 && retval[len - 1] == '$')
                --len;
            retval[len] = NUL;
        }
    }
    return retval;
}

static void cleanup_help_tags (int num_file, char_u **file) {
    int i, j;
    int len;
    char_u buf [4];
    char_u *p = buf;
    if (p_hlg[0] != NUL && (p_hlg[0] != 'e' || p_hlg[1] != 'n')) {
        *p++ = '@';
        *p++ = p_hlg[0];
        *p++ = p_hlg[1];
    }
    *p = NUL;
    for (i = 0; i < num_file; ++i) {
        len = (int) STRLEN (file[i]) - 3;
        if (len <= 0)
            continue;
        if (STRCMP (file[i] + len, "@en") == 0) {
            for (j = 0; j < num_file; ++j)
                if (j != i && (int) STRLEN (file[j]) == len + 3 && STRNCMP (file[i], file[j], len +1) == 0)
                    break;
            if (j == num_file)
                file[i][len] = NUL;
        }
    }
    if (*buf != NUL)
        for (i = 0; i < num_file; ++i) {
            len = (int) STRLEN (file[i]) - 3;
            if (len <= 0)
                continue;
            if (STRCMP (file[i] + len, buf) == 0) {
                file[i][len] = NUL;
            }
        }
}

static int expand_shellcmd (char_u *filepat, int *num_file, char_u ***file, int flagsarg) {
    char_u *pat;
    int i;
    char_u *path;
    int mustfree = FALSE;
    garray_T ga;
    char_u *buf = alloc (MAXPATHL);
    size_t l;
    char_u *s, *e;
    int flags = flagsarg;
    int ret;
    int did_curdir = FALSE;
    if (buf == NULL)
        return FAIL;
    pat = vim_strsave (filepat);
    for (i = 0; pat[i]; ++i)
        if (pat[i] == '\\' && pat[i + 1] == ' ')
            STRMOVE (pat +i, pat +i + 1);
    flags |= EW_FILE | EW_EXEC | EW_SHELLCMD;
    if (mch_isFullName (pat))
        path = (char_u *) " ";
    else if ((pat[0] == '.' && (vim_ispathsep (pat[1]) || (pat[1] == '.' && vim_ispathsep (pat[2])))))
        path = (char_u *) ".";
    else {
        path = vim_getenv ((char_u *) "PATH", &mustfree);
        if (path == NULL)
            path = (char_u *) "";
    }
    ga_init2 (& ga, (int) sizeof (char *), 10);
    for (s = path;; s = e) {
        if (*s == NUL) {
            if (did_curdir)
                break;
            did_curdir = TRUE;
        }
        else if (*s == '.')
            did_curdir = TRUE;
        if (*s == ' ')
            ++s;
        e = vim_strchr (s, ':');
        if (e == NULL)
            e = s + STRLEN (s);
        l = e - s;
        if (l > MAXPATHL - 5)
            break;
        vim_strncpy (buf, s, l);
        add_pathsep (buf);
        l = STRLEN (buf);
        vim_strncpy (buf + l, pat, MAXPATHL - 1 - l);
        ret = expand_wildcards (1, &buf, num_file, file, flags);
        if (ret == OK) {
            if (ga_grow (&ga, *num_file) == FAIL)
                FreeWild (*num_file, *file);
            else {
                for (i = 0; i < *num_file; ++i) {
                    s = (*file)[i];
                    if (STRLEN (s) > l) {
                        STRMOVE (s, s + l);
                        ((char_u **) ga.ga_data)[ga.ga_len++] = s;
                    }
                    else
                        vim_free (s);
                }
                vim_free (*file);
            }
        }
        if (*e != NUL)
            ++e;
    }
    *file = ga.ga_data;
    *num_file = ga.ga_len;
    vim_free (buf);
    vim_free (pat);
    if (mustfree)
        vim_free (path);
    return OK;
}

static int ExpandRTDir (char_u *pat, int flags, int *num_file, char_u ***file, char *dirnames []) {
    char_u *s;
    char_u *e;
    char_u *match;
    garray_T ga;
    int i;
    int pat_len;
    *num_file = 0;
    *file = NULL;
    pat_len = (int) STRLEN (pat);
    ga_init2 (& ga, (int) sizeof (char *), 10);
    for (i = 0; dirnames[i] != NULL; ++i) {
        s = alloc ((unsigned ) (STRLEN (dirnames[i]) + pat_len + 7));
        if (s == NULL) {
            ga_clear_strings (& ga);
            return FAIL;
        }
        sprintf ((char *) s, "%s/%s*.vim", dirnames [i], pat);
        globpath (p_rtp, s, & ga, 0);
        vim_free (s);
    }
    if (flags & DIP_START) {
        for (i = 0; dirnames[i] != NULL; ++i) {
            s = alloc ((unsigned ) (STRLEN (dirnames[i]) + pat_len + 22));
            if (s == NULL) {
                ga_clear_strings (& ga);
                return FAIL;
            }
            sprintf ((char *) s, "pack/*/start/*/%s/%s*.vim", dirnames [i], pat);
            globpath (p_pp, s, & ga, 0);
            vim_free (s);
        }
    }
    if (flags & DIP_OPT) {
        for (i = 0; dirnames[i] != NULL; ++i) {
            s = alloc ((unsigned ) (STRLEN (dirnames[i]) + pat_len + 20));
            if (s == NULL) {
                ga_clear_strings (& ga);
                return FAIL;
            }
            sprintf ((char *) s, "pack/*/opt/*/%s/%s*.vim", dirnames [i], pat);
            globpath (p_pp, s, & ga, 0);
            vim_free (s);
        }
    }
    for (i = 0; i < ga.ga_len; ++i) {
        match = ((char_u **) ga.ga_data)[i];
        s = match;
        e = s + STRLEN (s);
        if (e - 4 > s && STRNICMP (e -4, ".vim", 4) == 0) {
            e -= 4;
            for (s = e; s > match; MB_PTR_BACK (match, s))
                if (s < match || vim_ispathsep (*s))
                    break;
            ++s;
            *e = NUL;
            mch_memmove (match, s, e - s + 1);
        }
    }
    if (ga.ga_len == 0)
        return FAIL;
    remove_duplicates (& ga);
    *file = ga.ga_data;
    *num_file = ga.ga_len;
    return OK;
}

void globpath (char_u *path, char_u *file, garray_T *ga, int expand_options) {
    expand_T xpc;
    char_u *buf;
    int i;
    int num_p;
    char_u **p;
    buf = alloc (MAXPATHL);
    if (buf == NULL)
        return;
    ExpandInit (& xpc);
    xpc.xp_context = EXPAND_FILES;
    while (*path != NUL) {
        copy_option_part (& path, buf, MAXPATHL, ",");
        if (STRLEN (buf) + STRLEN (file) + 2 < MAXPATHL) {
            add_pathsep (buf);
            STRCAT (buf, file);
            if (ExpandFromContext (&xpc, buf, &num_p, &p, WILD_SILENT | expand_options) != FAIL && num_p > 0) {
                ExpandEscape (& xpc, buf, num_p, p, WILD_SILENT | expand_options);
                if (ga_grow (ga, num_p) == OK) {
                    for (i = 0; i < num_p; ++i) {
                        ((char_u **) ga->ga_data)[ga->ga_len] = vim_strnsave (p[i], (int) STRLEN (p[i]));
                        ++ga->ga_len;
                    }
                }
                FreeWild (num_p, p);
            }
        }
    }
    vim_free (buf);
}

void ExpandEscape (expand_T *xp, char_u *str, int numfiles, char_u **files, int options) {
    int i;
    char_u *p;
    if (options & WILD_HOME_REPLACE)
        tilde_replace (str, numfiles, files);
    if (options & WILD_ESCAPE) {
        if (xp->xp_context == EXPAND_FILES || xp->xp_context == EXPAND_FILES_IN_PATH || xp->xp_context == EXPAND_SHELLCMD || xp->xp_context == EXPAND_BUFFERS || xp->xp_context == EXPAND_DIRECTORIES) {
            for (i = 0; i < numfiles; ++i) {
                if (xp->xp_backslash == XP_BS_THREE) {
                    p = vim_strsave_escaped (files[i], (char_u *) " ");
                    if (p != NULL) {
                        vim_free (files [i]);
                        files[i] = p;
                    }
                }
                p = vim_strsave_fnameescape (files[i], xp->xp_shell);
                if (p != NULL) {
                    vim_free (files [i]);
                    files[i] = p;
                }
                if (str[0] == '\\' && str[1] == '~' && files[i][0] == '~')
                    escape_fname (&files[i]);
            }
            xp->xp_backslash = XP_BS_NONE;
            if (*files[0] == '+')
                escape_fname (&files[0]);
        }
        else if (xp->xp_context == EXPAND_TAGS) {
            for (i = 0; i < numfiles; ++i) {
                p = vim_strsave_escaped (files[i], (char_u *) "\\|\"");
                if (p != NULL) {
                    vim_free (files [i]);
                    files[i] = p;
                }
            }
        }
    }
}

char_u *vim_strsave_fnameescape (char_u *fname, int shell) {
    char_u *p;
    p = vim_strsave_escaped (fname, shell ? SHELL_ESC_CHARS : PATH_ESC_CHARS);
    if (shell && csh_like_shell () && p != NULL) {
        char_u *s;
        s = vim_strsave_escaped (p, (char_u *) "!");
        vim_free (p);
        p = s;
    }
    if (p != NULL && (*p == '>' || *p == '+' || (*p == '-' && p[1] == NUL)))
        escape_fname (&p);
    return p;
}

static void escape_fname (char_u **pp) {
    char_u *p;
    p = alloc ((unsigned ) (STRLEN (*pp) + 2));
    if (p != NULL) {
        p[0] = '\\';
        STRCPY (p + 1, * pp);
        vim_free (*pp);
        *pp = p;
    }
}

static int ExpandUserList (expand_T *xp, int *num_file, char_u ***file) {
    list_T *retlist;
    listitem_T *li;
    garray_T ga;
    retlist = call_user_expand_func (call_func_retlist, xp, num_file, file);
    if (retlist == NULL)
        return FAIL;
    ga_init2 (& ga, (int) sizeof (char *), 3);
    for (li = retlist->lv_first; li != NULL; li = li->li_next) {
        if (li->li_tv.v_type != VAR_STRING || li->li_tv.vval.v_string == NULL)
            continue;
        if (ga_grow (&ga, 1) == FAIL)
            break;
        ((char_u **) ga.ga_data)[ga.ga_len] = vim_strsave (li->li_tv.vval.v_string);
        ++ga.ga_len;
    }
    list_unref (retlist);
    *file = ga.ga_data;
    *num_file = ga.ga_len;
    return OK;
}

static void *call_user_expand_func (void * (*user_expand_func) (char_u *, int, char_u **, int), expand_T *xp, int *num_file, char_u ***file) {
    int keep = 0;
    char_u num [50];
    char_u *args [3];
    int save_current_SID = current_SID;
    void *ret;
    struct cmdline_info save_ccline;
    if (xp->xp_arg == NULL || xp->xp_arg[0] == '\0' || xp->xp_line == NULL)
        return NULL;
    *num_file = 0;
    *file = NULL;
    if (ccline.cmdbuff != NULL) {
        keep = ccline.cmdbuff[ccline.cmdlen];
        ccline.cmdbuff[ccline.cmdlen] = 0;
    }
    args[0] = vim_strnsave (xp->xp_pattern, xp->xp_pattern_len);
    args[1] = xp->xp_line;
    sprintf ((char *) num, "%d", xp -> xp_col);
    args[2] = num;
    save_ccline = ccline;
    ccline.cmdbuff = NULL;
    ccline.cmdprompt = NULL;
    current_SID = xp->xp_scriptID;
    ret = user_expand_func (xp->xp_arg, 3, args, FALSE);
    ccline = save_ccline;
    current_SID = save_current_SID;
    if (ccline.cmdbuff != NULL)
        ccline.cmdbuff[ccline.cmdlen] = keep;
    vim_free (args [0]);
    return ret;
}

static int ExpandPackAddDir (char_u *pat, int *num_file, char_u ***file) {
    char_u *s;
    char_u *e;
    char_u *match;
    garray_T ga;
    int i;
    int pat_len;
    *num_file = 0;
    *file = NULL;
    pat_len = (int) STRLEN (pat);
    ga_init2 (& ga, (int) sizeof (char *), 10);
    s = alloc ((unsigned ) (pat_len + 26));
    if (s == NULL) {
        ga_clear_strings (& ga);
        return FAIL;
    }
    sprintf ((char *) s, "pack/*/opt/%s*", pat);
    globpath (p_pp, s, & ga, 0);
    vim_free (s);
    for (i = 0; i < ga.ga_len; ++i) {
        match = ((char_u **) ga.ga_data)[i];
        s = gettail (match);
        e = s + STRLEN (s);
        mch_memmove (match, s, e - s + 1);
    }
    if (ga.ga_len == 0)
        return FAIL;
    remove_duplicates (& ga);
    *file = ga.ga_data;
    *num_file = ga.ga_len;
    return OK;
}

static int ExpandUserDefined (expand_T *xp, regmatch_T *regmatch, int *num_file, char_u ***file) {
    char_u *retstr;
    char_u *s;
    char_u *e;
    int keep;
    garray_T ga;
    int skip;
    retstr = call_user_expand_func (call_func_retstr, xp, num_file, file);
    if (retstr == NULL)
        return FAIL;
    ga_init2 (& ga, (int) sizeof (char *), 3);
    for (s = retstr; *s != NUL; s = e) {
        e = vim_strchr (s, '\n');
        if (e == NULL)
            e = s + STRLEN (s);
        keep = *e;
        *e = NUL;
        skip = xp->xp_pattern[0] && vim_regexec (regmatch, s, (colnr_T) 0) == 0;
        *e = keep;
        if (!skip) {
            if (ga_grow (&ga, 1) == FAIL)
                break;
            ((char_u **) ga.ga_data)[ga.ga_len] = vim_strnsave (s, (int) (e - s));
            ++ga.ga_len;
        }
        if (*e != NUL)
            ++e;
    }
    vim_free (retstr);
    *file = ga.ga_data;
    *num_file = ga.ga_len;
    return OK;
}

int ExpandGeneric (expand_T *xp, regmatch_T *regmatch, int *num_file, char_u ***file, char_u * ((*func) (expand_T *, int)), int escaped) {
    int i;
    int count = 0;
    int round;
    char_u *str;
    for (round = 0; round <= 1; ++round) {
        for (i = 0;; ++i) {
            str = (*func) (xp, i);
            if (str == NULL)
                break;
            if (*str == NUL)
                continue;
            if (vim_regexec (regmatch, str, (colnr_T) 0)) {
                if (round) {
                    if (escaped)
                        str = vim_strsave_escaped (str, (char_u *) " \t\\.");
                    else
                        str = vim_strsave (str);
                    (*file)[count] = str;
                    if (func == get_menu_names && str != NULL) {
                        str += STRLEN (str) - 1;
                        if (*str == '\001')
                            *str = '.';
                    }
                }
                ++count;
            }
        }
        if (round == 0) {
            if (count == 0)
                return OK;
            *num_file = count;
            *file = (char_u **) alloc ((unsigned ) (count * sizeof (char_u *)));
            if (*file == NULL) {
                *file = (char_u **) "";
                return FAIL;
            }
            count = 0;
        }
    }
    if (xp->xp_context != EXPAND_MENUNAMES && xp->xp_context != EXPAND_MENUS) {
        if (xp->xp_context == EXPAND_EXPRESSION || xp->xp_context == EXPAND_FUNCTIONS || xp->xp_context == EXPAND_USER_FUNC)
            qsort ((void *) *file, (size_t) *num_file, sizeof (char_u *), sort_func_compare);
        else
            sort_strings (*file, *num_file);
    }
    reset_expand_highlight ();
    return OK;
}

static int sort_func_compare (const void *s1, const void *s2) {
    char_u *p1 = *(char_u**) s1;
    char_u *p2 = *(char_u**) s2;
    if (*p1 != '<' && *p2 == '<')
        return -1;
    if (*p1 == '<' && *p2 != '<')
        return 1;
    return STRCMP (p1, p2);
}

void ExpandCleanup (expand_T *xp) {
    if (xp->xp_numfiles >= 0) {
        FreeWild (xp -> xp_numfiles, xp -> xp_files);
        xp->xp_numfiles = -1;
    }
}

static void cmdline_del (int from) {
    mch_memmove (ccline.cmdbuff + from, ccline.cmdbuff + ccline.cmdpos, (size_t) (ccline.cmdlen - ccline.cmdpos + 1));
    ccline.cmdlen -= ccline.cmdpos - from;
    ccline.cmdpos = from;
}

static int ccheck_abbr (int c) {
    if (p_paste || no_abbr)
        return FALSE;
    return check_abbr (c, ccline.cmdbuff, ccline.cmdpos, 0);
}

static int showmatches (expand_T *xp, int wildmenu) {

    #define L_SHOWFILE(m) (showtail ? sm_gettail(files_found[m]) : files_found[m])
    int num_files;
    char_u **files_found;
    int i, j, k;
    int maxlen;
    int lines;
    int columns;
    char_u *p;
    int lastlen;
    int attr;
    int showtail;
    if (xp->xp_numfiles == -1) {
        set_expand_context (xp);
        i = expand_cmdline (xp, ccline.cmdbuff, ccline.cmdpos, &num_files, &files_found);
        showtail = expand_showtail (xp);
        if (i != EXPAND_OK)
            return i;
    }
    else {
        num_files = xp->xp_numfiles;
        files_found = xp->xp_files;
        showtail = cmd_showtail;
    }
    if (!wildmenu) {
        msg_didany = FALSE;
        msg_start ();
        msg_putchar ('\n');
        out_flush ();
        cmdline_row = msg_row;
        msg_didany = FALSE;
        msg_start ();
    }
    if (got_int)
        got_int = FALSE;
    else if (wildmenu)
        win_redr_status_matches (xp, num_files, files_found, -1, showtail);
    else {
        maxlen = 0;
        for (i = 0; i < num_files; ++i) {
            if (!showtail && (xp->xp_context == EXPAND_FILES || xp->xp_context == EXPAND_SHELLCMD || xp->xp_context == EXPAND_BUFFERS)) {
                home_replace (NULL, files_found [i], NameBuff, MAXPATHL, TRUE);
                j = vim_strsize (NameBuff);
            }
            else
                j = vim_strsize (L_SHOWFILE (i));
            if (j > maxlen)
                maxlen = j;
        }
        if (xp->xp_context == EXPAND_TAGS_LISTFILES)
            lines = num_files;
        else {
            maxlen += 2;
            columns = ((int) Columns + 2) / maxlen;
            if (columns < 1)
                columns = 1;
            lines = (num_files + columns - 1) / columns;
        }
        attr = HL_ATTR (HLF_D);
        if (xp->xp_context == EXPAND_TAGS_LISTFILES) {
            MSG_PUTS_ATTR (_ ("tagname"), HL_ATTR (HLF_T));
            msg_clr_eos ();
            msg_advance (maxlen - 3);
            MSG_PUTS_ATTR (_ (" kind file\n"), HL_ATTR (HLF_T));
        }
        for (i = 0; i < lines; ++i) {
            lastlen = 999;
            for (k = i; k < num_files; k += lines) {
                if (xp->xp_context == EXPAND_TAGS_LISTFILES) {
                    msg_outtrans_attr (files_found [k], HL_ATTR (HLF_D));
                    p = files_found[k] + STRLEN (files_found[k]) + 1;
                    msg_advance (maxlen + 1);
                    msg_puts (p);
                    msg_advance (maxlen + 3);
                    msg_puts_long_attr (p + 2, HL_ATTR (HLF_D));
                    break;
                }
                for (j = maxlen - lastlen; --j >= 0;)
                    msg_putchar (' ');
                if (xp->xp_context == EXPAND_FILES || xp->xp_context == EXPAND_SHELLCMD || xp->xp_context == EXPAND_BUFFERS) {
                    if (xp->xp_numfiles != -1) {
                        char_u *halved_slash;
                        char_u *exp_path;
                        exp_path = expand_env_save_opt (files_found[k], TRUE);
                        halved_slash = backslash_halve_save (exp_path != NULL ? exp_path : files_found[k]);
                        j = mch_isdir (halved_slash != NULL ? halved_slash : files_found[k]);
                        vim_free (exp_path);
                        vim_free (halved_slash);
                    }
                    else
                        j = mch_isdir (files_found[k]);
                    if (showtail)
                        p = L_SHOWFILE (k);
                    else {
                        home_replace (NULL, files_found [k], NameBuff, MAXPATHL, TRUE);
                        p = NameBuff;
                    }
                }
                else {
                    j = FALSE;
                    p = L_SHOWFILE (k);
                }
                lastlen = msg_outtrans_attr (p, j ? attr : 0);
            }
            if (msg_col > 0) {
                msg_clr_eos ();
                msg_putchar ('\n');
            }
            out_flush ();
            if (got_int) {
                got_int = FALSE;
                break;
            }
        }
        cmdline_row = msg_row;
    }
    if (xp->xp_numfiles == -1)
        FreeWild (num_files, files_found);
    return EXPAND_OK;
}

static void set_expand_context (expand_T *xp) {
    if (ccline.cmdfirstc != ':' && ccline.cmdfirstc != '>' && ccline.cmdfirstc != '=' && !ccline.input_fn) {
        xp->xp_context = EXPAND_NOTHING;
        return;
    }
    set_cmd_context (xp, ccline.cmdbuff, ccline.cmdlen, ccline.cmdpos, TRUE);
}

void set_cmd_context (expand_T *xp, char_u *str, int len, int col, int use_ccline) {
    int old_char = NUL;
    char_u *nextcomm;
    if (col < len)
        old_char = str[col];
    str[col] = NUL;
    nextcomm = str;
    if (use_ccline && ccline.cmdfirstc == '=') {
        set_context_for_expression (xp, str, CMD_SIZE);
    }
    else if (use_ccline && ccline.input_fn) {
        xp->xp_context = ccline.xp_context;
        xp->xp_pattern = ccline.cmdbuff;
        xp->xp_arg = ccline.xp_arg;
    }
    else
        while (nextcomm != NULL)
            nextcomm = set_one_cmd_context (xp, nextcomm);
    xp->xp_line = str;
    xp->xp_col = col;
    str[col] = old_char;
}

static int expand_showtail (expand_T *xp) {
    char_u *s;
    char_u *end;
    if (xp->xp_context != EXPAND_FILES && xp->xp_context != EXPAND_SHELLCMD && xp->xp_context != EXPAND_DIRECTORIES)
        return FALSE;
    end = gettail (xp->xp_pattern);
    if (end == xp->xp_pattern)
        return FALSE;
    for (s = xp->xp_pattern; s < end; s++) {
        if (rem_backslash (s))
            ++s;
        else if (vim_strchr ((char_u *) "*?[", *s) != NULL)
            return FALSE;
    }
    return TRUE;
}

static int nextwild (expand_T *xp, int type, int options, int escape) {
    int i, j;
    char_u *p1;
    char_u *p2;
    int difflen;
    int v;
    if (xp->xp_numfiles == -1) {
        set_expand_context (xp);
        cmd_showtail = expand_showtail (xp);
    }
    if (xp->xp_context == EXPAND_UNSUCCESSFUL) {
        beep_flush ();
        return OK;
    }
    if (xp->xp_context == EXPAND_NOTHING) {
        return FAIL;
    }
    MSG_PUTS ("...");
    out_flush ();
    i = (int) (xp->xp_pattern - ccline.cmdbuff);
    xp->xp_pattern_len = ccline.cmdpos - i;
    if (type == WILD_NEXT || type == WILD_PREV) {
        p2 = ExpandOne (xp, NULL, NULL, 0, type);
    }
    else {
        if ((p1 = addstar (xp->xp_pattern, xp->xp_pattern_len, xp->xp_context)) == NULL)
            p2 = NULL;
        else {
            int use_options = options | WILD_HOME_REPLACE | WILD_ADD_SLASH | WILD_SILENT;
            if (escape)
                use_options |= WILD_ESCAPE;
            if (p_wic)
                use_options += WILD_ICASE;
            p2 = ExpandOne (xp, p1, vim_strnsave (&ccline.cmdbuff[i], xp->xp_pattern_len), use_options, type);
            vim_free (p1);
            if (p2 != NULL && type == WILD_LONGEST) {
                for (j = 0; j < xp->xp_pattern_len; ++j)
                    if (ccline.cmdbuff[i + j] == '*' || ccline.cmdbuff[i + j] == '?')
                        break;
                if ((int) STRLEN (p2) < j)
                    VIM_CLEAR (p2);
            }
        }
    }
    if (p2 != NULL && !got_int) {
        difflen = (int) STRLEN (p2) - xp->xp_pattern_len;
        if (ccline.cmdlen + difflen + 4 > ccline.cmdbufflen) {
            v = realloc_cmdbuff (ccline.cmdlen + difflen + 4);
            xp->xp_pattern = ccline.cmdbuff + i;
        }
        else
            v = OK;
        if (v == OK) {
            mch_memmove (& ccline.cmdbuff [ccline.cmdpos + difflen], & ccline.cmdbuff [ccline.cmdpos], (size_t) (ccline.cmdlen - ccline.cmdpos + 1));
            mch_memmove (& ccline.cmdbuff [i], p2, STRLEN (p2));
            ccline.cmdlen += difflen;
            ccline.cmdpos += difflen;
        }
    }
    vim_free (p2);
    redrawcmd ();
    cursorcmd ();
    if (xp->xp_context == EXPAND_MAPPINGS && p2 == NULL)
        return FAIL;
    if (xp->xp_numfiles <= 0 && p2 == NULL)
        beep_flush ();
    else if (xp->xp_numfiles == 1)
        (void) ExpandOne (xp, NULL, NULL, 0, WILD_FREE);
    return OK;
}

static int cmdline_paste (int regname, int literally, int remcr) {
    long  i;
    char_u *arg;
    char_u *p;
    int allocated;
    struct cmdline_info save_ccline;
    if (regname != Ctrl_F && regname != Ctrl_P && regname != Ctrl_W && regname != Ctrl_A && !valid_yank_reg (regname, FALSE))
        return FAIL;
    line_breakcheck ();
    if (got_int)
        return FAIL;
    save_cmdline (& save_ccline);
    ++textlock;
    i = get_spec_reg (regname, &arg, &allocated, TRUE);
    --textlock;
    restore_cmdline (& save_ccline);
    if (i) {
        if (arg == NULL)
            return FAIL;
        p = arg;
        if (p_is && regname == Ctrl_W) {
            char_u *w;
            int len;
            for (w = ccline.cmdbuff + ccline.cmdpos; w > ccline.cmdbuff;) {
                {
                    if (!vim_iswordc (w[-1]))
                        break;
                    --w;
                }
            }
            len = (int) ((ccline.cmdbuff + ccline.cmdpos) - w);
            if (p_ic ? STRNICMP (w, arg, len) == 0 : STRNCMP (w, arg, len) == 0)
                p += len;
        }
        cmdline_paste_str (p, literally);
        if (allocated)
            vim_free (arg);
        return OK;
    }
    return cmdline_paste_reg (regname, literally, remcr);
}

void cmdline_paste_str (char_u *s, int literally) {
    int c, cv;
    if (literally)
        put_on_cmdline (s, -1, TRUE);
    else
        while (*s != NUL) {
            cv = *s;
            if (cv == Ctrl_V && s[1])
                ++s;
            c = *s++;
            if (cv == Ctrl_V || c == ESC || c == Ctrl_C || c == CAR || c == NL || c == Ctrl_L || c == intr_char || (c == Ctrl_BSL && *s == Ctrl_N))
                stuffcharReadbuff (Ctrl_V);
            stuffcharReadbuff (c);
        }
}

static void set_search_match (pos_T *t) {
    t->lnum += search_match_lines;
    t->col = search_match_endcol;
    if (t->lnum > curbuf->b_ml.ml_line_count) {
        t->lnum = curbuf->b_ml.ml_line_count;
        coladvance ((colnr_T) MAXCOL);
    }
}

static int empty_pattern (char_u *p) {
    size_t n = STRLEN (p);
    while (n >= 2 && p[n - 2] == '\\' && vim_strchr ((char_u *) "mMvVcCZ", p[n - 1]) != NULL)
        n -= 2;
    return n == 0 || (n >= 2 && p[n - 2] == '\\' && p[n - 1] == '|');
}

static void abandon_cmdline (void) {
    VIM_CLEAR (ccline.cmdbuff);
    if (msg_scrolled == 0)
        compute_cmdrow ();
    MSG ("");
    redraw_cmdline = TRUE;
}

char_u *getexline (int c, void *cookie, int indent) {
    if (exec_from_reg && vpeekc () == ':')
        (void) vgetc ();
    return getcmdline (c, 1L, indent);
}

char_u *getexmodeline (int promptc, void *cookie, int indent) {
    garray_T line_ga;
    char_u *pend;
    int startcol = 0;
    int c1 = 0;
    int escaped = FALSE;
    int vcol = 0;
    char_u *p;
    int prev_char;
    int len;
    cursor_on ();
    compute_cmdrow ();
    if ((msg_col || msg_didout) && promptc != '?')
        msg_putchar ('\n');
    if (promptc == ':') {
        if (p_prompt)
            msg_putchar (':');
        while (indent-- > 0)
            msg_putchar (' ');
        startcol = msg_col;
    }
    ga_init2 (& line_ga, 1, 30);
    if (promptc <= 0) {
        vcol = indent;
        while (indent >= 8) {
            ga_append (& line_ga, TAB);
            msg_puts ((char_u *) "        ");
            indent -= 8;
        }
        while (indent-- > 0) {
            ga_append (& line_ga, ' ');
            msg_putchar (' ');
        }
    }
    ++no_mapping;
    ++allow_keys;
    got_int = FALSE;
    while (!got_int) {
        long  sw;
        char_u *s;
        if (ga_grow (&line_ga, 40) == FAIL)
            break;
        prev_char = c1;
        if (ex_normal_busy > 0 && typebuf.tb_len == 0)
            c1 = '\n';
        else
            c1 = vgetc ();
        if (got_int) {
            msg_putchar ('\n');
            break;
        }
        if (c1 == K_PS) {
            bracketed_paste (PASTE_EX, FALSE, & line_ga);
            goto redraw;
        }
        if (!escaped) {
            if (c1 == '\r')
                c1 = '\n';
            if (c1 == BS || c1 == K_BS || c1 == DEL || c1 == K_DEL || c1 == K_KDEL) {
                if (line_ga.ga_len > 0) {
                    --line_ga.ga_len;
                    goto redraw;
                }
                continue;
            }
            if (c1 == Ctrl_U) {
                msg_col = startcol;
                msg_clr_eos ();
                line_ga.ga_len = 0;
                goto redraw;
            }
            if (c1 == Ctrl_T) {
                sw = get_sw_value (curbuf);
                p = (char_u *) line_ga.ga_data;
                p[line_ga.ga_len] = NUL;
                indent = get_indent_str (p, 8, FALSE);
                indent += sw - indent % sw;
            add_indent :
                while (get_indent_str (p, 8, FALSE) < indent) {
                    (void) ga_grow (&line_ga, 2);
                    p = (char_u *) line_ga.ga_data;
                    s = skipwhite (p);
                    mch_memmove (s + 1, s, line_ga.ga_len - (s - p) + 1);
                    *s = ' ';
                    ++line_ga.ga_len;
                }
            redraw :
                msg_col = startcol;
                vcol = 0;
                p = (char_u *) line_ga.ga_data;
                p[line_ga.ga_len] = NUL;
                while (p < (char_u *) line_ga.ga_data + line_ga.ga_len) {
                    if (*p == TAB) {
                        do {
                            msg_putchar (' ');
                        }
                        while (++vcol % 8);
                        ++p;
                    }
                    else {
                        len = MB_PTR2LEN (p);
                        msg_outtrans_len (p, len);
                        vcol += ptr2cells (p);
                        p += len;
                    }
                }
                msg_clr_eos ();
                windgoto (msg_row, msg_col);
                continue;
            }
            if (c1 == Ctrl_D) {
                p = (char_u *) line_ga.ga_data;
                if (prev_char == '0' || prev_char == '^') {
                    if (prev_char == '^')
                        ex_keep_indent = TRUE;
                    indent = 0;
                    p[--line_ga.ga_len] = NUL;
                }
                else {
                    p[line_ga.ga_len] = NUL;
                    indent = get_indent_str (p, 8, FALSE);
                    if (indent > 0) {
                        --indent;
                        indent -= indent % get_sw_value (curbuf);
                    }
                }
                while (get_indent_str (p, 8, FALSE) > indent) {
                    s = skipwhite (p);
                    mch_memmove (s - 1, s, line_ga.ga_len - (s - p) + 1);
                    --line_ga.ga_len;
                }
                goto add_indent;
            }
            if (c1 == Ctrl_V || c1 == Ctrl_Q) {
                escaped = TRUE;
                continue;
            }
            if (IS_SPECIAL (c1))
                continue;
        }
        if (IS_SPECIAL (c1))
            c1 = '?';
        {
            len = 1;
            ((char_u *) line_ga.ga_data)[line_ga.ga_len] = c1;
        }
        if (c1 == '\n')
            msg_putchar ('\n');
        else if (c1 == TAB) {
            do {
                msg_putchar (' ');
            }
            while (++vcol % 8);
        }
        else {
            msg_outtrans_len (((char_u *) line_ga.ga_data) + line_ga.ga_len, len);
            vcol += char2cells (c1);
        }
        line_ga.ga_len += len;
        escaped = FALSE;
        windgoto (msg_row, msg_col);
        pend = (char_u *) (line_ga.ga_data) + line_ga.ga_len;
        if (line_ga.ga_len > 0 && pend[-1] == '\n') {
            int bcount = 0;
            while (line_ga.ga_len - 2 >= bcount && pend[-2 - bcount] == '\\')
                ++bcount;
            if (bcount > 0) {
                line_ga.ga_len -= (bcount + 1) / 2;
                pend -= (bcount + 1) / 2;
                pend[-1] = '\n';
            }
            if ((bcount & 1) == 0) {
                --line_ga.ga_len;
                --pend;
                *pend = NUL;
                break;
            }
        }
    }
    --no_mapping;
    --allow_keys;
    msg_didout = FALSE;
    msg_col = 0;
    if (msg_row < Rows - 1)
        ++msg_row;
    emsg_on_display = FALSE;
    if (got_int)
        ga_clear (&line_ga);
    return (char_u *) line_ga.ga_data;
}

void unputcmdline (void) {
    if (cmd_silent)
        return;
    msg_no_more = TRUE;
    if (ccline.cmdlen == ccline.cmdpos)
        msg_putchar (' ');
    else
        draw_cmdline (ccline.cmdpos, 1);
    msg_no_more = FALSE;
    cursorcmd ();
    extra_char = NUL;
}

char_u *script_get (exarg_T *eap, char_u *cmd) {
    char_u *theline;
    char *end_pattern = NULL;
    char dot [] = ".";
    garray_T ga;
    if (cmd[0] != '<' || cmd[1] != '<' || eap->getline == NULL)
        return NULL;
    ga_init2 (& ga, 1, 0x400);
    if (cmd[2] != NUL)
        end_pattern = (char *) skipwhite (cmd +2);
    else
        end_pattern = dot;
    for (;;) {
        theline = eap->getline (eap->cstack->cs_looplevel > 0 ? -1 : NUL, eap->cookie, 0);
        if (theline == NULL || STRCMP (end_pattern, theline) == 0) {
            vim_free (theline);
            break;
        }
        ga_concat (& ga, theline);
        ga_append (& ga, '\n');
        vim_free (theline);
    }
    ga_append (& ga, NUL);
    return (char_u *) ga.ga_data;
}

char_u *get_cmdline_str (void) {
    struct cmdline_info *p = get_ccline_ptr ();
    if (p == NULL)
        return NULL;
    return vim_strnsave (p->cmdbuff, p->cmdlen);
}

static struct cmdline_info *get_ccline_ptr (void) {
    if ((State & CMDLINE) == 0)
        return NULL;
    if (ccline.cmdbuff != NULL)
        return &ccline;
    if (prev_ccline_used && prev_ccline.cmdbuff != NULL)
        return &prev_ccline;
    return NULL;
}

int get_cmdline_pos (void) {
    struct cmdline_info *p = get_ccline_ptr ();
    if (p == NULL)
        return -1;
    return p->cmdpos;
}

int get_cmdline_type (void) {
    struct cmdline_info *p = get_ccline_ptr ();
    if (p == NULL)
        return NUL;
    if (p->cmdfirstc == NUL)
        return (p->input_fn) ? '@' : '-';
    return p->cmdfirstc;
}

int set_cmdline_pos (int pos) {
    struct cmdline_info *p = get_ccline_ptr ();
    if (p == NULL)
        return 1;
    if (pos < 0)
        new_cmdpos = 0;
    else
        new_cmdpos = pos;
    return 0;
}

