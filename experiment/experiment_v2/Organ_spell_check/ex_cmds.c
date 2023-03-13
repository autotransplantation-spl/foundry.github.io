
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
struct sign {
    sign_T *sn_next;
    int sn_typenr;
    char_u *sn_name;
    char_u *sn_icon;
    char_u *sn_text;
    int sn_line_hl;
    int sn_text_hl;
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
EXTERN char_u *p_rtp;
EXTERN char_u *p_srr;
EXTERN int p_write;
EXTERN long  p_so;
EXTERN int p_sol;
EXTERN long  p_ur;
EXTERN int p_im;
EXTERN int p_awa;
EXTERN char_u *p_dir;
EXTERN char_u e_exists [] INIT (= N_ ("E13: File exists (add ! to override)"));
EXTERN char_u e_isadir2 [] INIT (= N_ ("E17: \"%s\" is a directory"));
EXTERN int p_wa;
sign_T *first_sign = NULL;
char_u *old_sub = NULL;
EXTERN char_u *NameBuff;
EXTERN char_u *p_viminfofile;
EXTERN long  p_verbose;
EXTERN char_u e_readonly [] INIT (= N_ ("E45: 'readonly' option is set (add ! to override)"));
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
int append_indent = 0;
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
char *cmds [] = {"define", 
    # define SIGNCMD_DEFINE	0
    "undefine", 
    # define SIGNCMD_UNDEFINE 1
    "list", 
    # define SIGNCMD_LIST	2
    "place", 
    # define SIGNCMD_PLACE	3
    "unplace", 
    # define SIGNCMD_UNPLACE 4
    "jump", 
    # define SIGNCMD_JUMP	5
    NULL 
    # define SIGNCMD_LAST	6

};
int viminfo_errcnt;
char_u *prevcmd = NULL;
int sort_ic;
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
char_u *sortbuf2;
char_u *sortbuf1;
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
int next_sign_typenr = 1;
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

void append_redir (char_u *buf, int buflen, char_u *opt, char_u *fname) {
    char_u *p;
    char_u *end;
    end = buf + STRLEN (buf);
    for (p = opt; (p = vim_strchr (p, '%')) != NULL; ++p) {
        if (p[1] == 's')
            break;
        if (p[1] == '%')
            ++p;
    }
    if (p != NULL) {
        *end = ' ';
        vim_snprintf ((char *) end + 1, (size_t) (buflen - (end + 1 - buf)), (char *) opt, (char *) fname);
    }
    else
        vim_snprintf ((char *) end, (size_t) (buflen - (end - buf)), " %s %s", (char *) opt, (char *) fname);
}

time_T vim_time (void) {
    return time_for_testing == 0 ? time (NULL) : time_for_testing;
}

int check_restricted (void) {
    if (restricted) {
        EMSG (_ ("E145: Shell commands not allowed in rvim"));
        return TRUE;
    }
    return FALSE;
}

int check_secure (void) {
    if (secure) {
        secure = 2;
        EMSG (_ (e_curdir));
        return TRUE;
    }
    return FALSE;
}

static int check_readonly (int *forceit, buf_T *buf) {
    stat_T st;
    if (!*forceit && (buf->b_p_ro || (mch_stat ((char *) buf->b_ffname, &st) >= 0 && check_file_readonly (buf->b_ffname, 0777)))) {
        if ((p_confirm || cmdmod.confirm) && buf->b_fname != NULL) {
            char_u buff [DIALOG_MSG_SIZE];
            if (buf->b_p_ro)
                dialog_msg (buff, _ ("'readonly' option is set for \"%s\".\nDo you wish to write anyway?"), buf->b_fname);
            else
                dialog_msg (buff, _ ("File permissions of \"%s\" are read-only.\nIt may still be possible to write it.\nDo you wish to try?"), buf->b_fname);
            if (vim_dialog_yesno (VIM_QUESTION, NULL, buff, 2) == VIM_YES) {
                *forceit = TRUE;
                return FALSE;
            }
            else
                return TRUE;
        }
        else if (buf->b_p_ro)
            EMSG (_ (e_readonly));
        else
            EMSG2 (_ ("E505: \"%s\" is read-only (add ! to override)"), buf->b_fname);
        return TRUE;
    }
    return FALSE;
}

void write_viminfo (char_u *file, int forceit) {
    char_u *fname;
    FILE *fp_in = NULL;
    FILE *fp_out = NULL;
    char_u *tempname = NULL;
    stat_T st_new;
    mode_t umask_save;
    int shortname = FALSE;
    stat_T st_old;
    if (no_viminfo ())
        return;
    fname = viminfo_filename (file);
    if (fname == NULL)
        return;
    fp_in = mch_fopen ((char *) fname, READBIN);
    if (fp_in == NULL) {
        int fd;
        if (mch_stat ((char *) fname, &st_new) == 0)
            goto end;
        fd = mch_open ((char *) fname, O_CREAT | O_EXTRA | O_EXCL | O_WRONLY | O_NOFOLLOW, 0600);
        if (fd < 0)
            goto end;
        fp_out = fdopen (fd, WRITEBIN);
    }
    else {
        st_old.st_dev = (dev_t) 0;
        st_old.st_ino = 0;
        st_old.st_mode = 0600;
        if (mch_stat ((char *) fname, &st_old) == 0 && getuid () != ROOT_UID && !(st_old.st_uid == getuid () ? (st_old.st_mode & 0200) : (st_old.st_gid == getgid () ? (st_old.st_mode & 0020) : (st_old.st_mode & 0002)))) {
            int tt = msg_didany;
            EMSG2 (_ ("E137: Viminfo file is not writable: %s"), fname);
            msg_didany = tt;
            fclose (fp_in);
            goto end;
        }
        for (;;) {
            int next_char = 'z';
            char_u *wp;
            tempname = buf_modname (shortname, fname, (char_u *) ".tmp", FALSE);
            if (tempname == NULL)
                break;
            wp = tempname + STRLEN (tempname) - 5;
            if (wp < gettail (tempname))
                wp = gettail (tempname);
            for (;;) {
                if (mch_stat ((char *) tempname, &st_new) == 0) {
                    if (!shortname && st_new.st_dev == st_old.st_dev && st_new.st_ino == st_old.st_ino) {
                        VIM_CLEAR (tempname);
                        shortname = TRUE;
                        break;
                    }
                }
                else {
                    int fd;
                    umask_save = umask (0);
                    fd = mch_open ((char *) tempname, O_CREAT | O_EXTRA | O_EXCL | O_WRONLY | O_NOFOLLOW, (int) ((st_old.st_mode & 0777) | 0600));
                    (void) umask (umask_save);
                    if (fd < 0) {
                        fp_out = NULL;
                    }
                    else
                        fp_out = fdopen (fd, WRITEBIN);
                    if (fp_out != NULL)
                        break;
                }
                if (next_char == 'a' - 1) {
                    EMSG2 (_ ("E929: Too many viminfo temp files, like %s!"), tempname);
                    break;
                }
                *wp = next_char;
                --next_char;
            }
            if (tempname != NULL)
                break;
        }
    }
    if (fp_out == NULL) {
        EMSG2 (_ ("E138: Can't write viminfo file %s!"), (fp_in == NULL || tempname == NULL) ? fname : tempname);
        if (fp_in != NULL)
            fclose (fp_in);
        goto end;
    }
    if (p_verbose > 0) {
        verbose_enter ();
        smsg ((char_u *) _ ("Writing viminfo file \"%s\""), fname);
        verbose_leave ();
    }
    viminfo_errcnt = 0;
    do_viminfo (fp_in, fp_out, forceit ? 0 : (VIF_WANT_INFO | VIF_WANT_MARKS));
    if (fclose (fp_out) == EOF)
        ++viminfo_errcnt;
    if (fp_in != NULL) {
        fclose (fp_in);
        if (viminfo_errcnt == 0) {
            if (vim_rename (tempname, fname) == -1) {
                ++viminfo_errcnt;
                EMSG2 (_ ("E886: Can't rename viminfo file to %s!"), fname);
            }
        }
        if (viminfo_errcnt > 0)
            mch_remove (tempname);
    }
end :
    vim_free (fname);
    vim_free (tempname);
}

static int no_viminfo (void) {
    return STRCMP (p_viminfofile, "NONE") == 0;
}

static char_u *viminfo_filename (char_u *file) {
    if (file == NULL || *file == NUL) {
        if (*p_viminfofile != NUL)
            file = p_viminfofile;
        else if ((file = find_viminfo_parameter ('n')) == NULL || *file == NUL) {
            file = (char_u *) VIMINFO_FILE;
        }
        expand_env (file, NameBuff, MAXPATHL);
        file = NameBuff;
    }
    return vim_strsave (file);
}

static void do_viminfo (FILE *fp_in, FILE *fp_out, int flags) {
    int eof = FALSE;
    vir_T vir;
    int merge = FALSE;
    int do_copy_marks = FALSE;
    garray_T buflist;
    if ((vir.vir_line = alloc (LSIZE)) == NULL)
        return;
    vir.vir_fd = fp_in;
    ga_init2 (& vir.vir_barlines, (int) sizeof (char_u *), 100);
    vir.vir_version = -1;
    if (fp_in != NULL) {
        if (flags & VIF_WANT_INFO) {
            if (fp_out != NULL) {
                prepare_viminfo_registers ();
                prepare_viminfo_marks ();
            }
            eof = read_viminfo_up_to_marks (&vir, flags &VIF_FORCEIT, fp_out != NULL);
            merge = TRUE;
        }
        else if (flags != 0)
            while (!(eof = viminfo_readline (&vir)) && vir.vir_line[0] != '>')
                ;
        do_copy_marks = (flags & (VIF_WANT_MARKS | VIF_GET_OLDFILES | VIF_FORCEIT));
    }
    if (fp_out != NULL) {
        fprintf (fp_out, _ ("# This viminfo file was generated by Vim %s.\n"), VIM_VERSION_MEDIUM);
        fputs (_ ("# You may edit it if you're careful!\n\n"), fp_out);
        write_viminfo_version (fp_out);
        write_viminfo_search_pattern (fp_out);
        write_viminfo_sub_string (fp_out);
        write_viminfo_registers (fp_out);
        finish_viminfo_registers ();
        write_viminfo_varlist (fp_out);
        write_viminfo_filemarks (fp_out);
        finish_viminfo_marks ();
        write_viminfo_bufferlist (fp_out);
        write_viminfo_barlines (& vir, fp_out);
        if (do_copy_marks)
            ga_init2 (&buflist, sizeof (buf_T *), 50);
        write_viminfo_marks (fp_out, do_copy_marks ? & buflist : NULL);
    }
    if (do_copy_marks) {
        copy_viminfo_marks (& vir, fp_out, & buflist, eof, flags);
        if (fp_out != NULL)
            ga_clear (&buflist);
    }
    vim_free (vir.vir_line);
    ga_clear_strings (& vir.vir_barlines);
}

static int read_viminfo_up_to_marks (vir_T *virp, int forceit, int writing) {
    int eof;
    buf_T *buf;
    int got_encoding = FALSE;
    eof = viminfo_readline (virp);
    while (!eof && virp->vir_line[0] != '>') {
        switch (virp->vir_line[0]) {
        case '+' :
        case '^' :
        case '<' :
        case NUL :
        case '\r' :
        case '\n' :
        case '#' :
            eof = viminfo_readline (virp);
            break;
        case '|' :
            eof = read_viminfo_barline (virp, got_encoding, forceit, writing);
            break;
        case '*' :
            got_encoding = TRUE;
            eof = viminfo_encoding (virp);
            break;
        case '!' :
            eof = read_viminfo_varlist (virp, writing);
            break;
        case '%' :
            eof = read_viminfo_bufferlist (virp, writing);
            break;
        case '"' :
            if (virp->vir_version < VIMINFO_VERSION_WITH_REGISTERS)
                eof = read_viminfo_register (virp, forceit);
            else
                do {
                    eof = viminfo_readline (virp);
                }
                while (!eof && (virp->vir_line[0] == TAB || virp->vir_line[0] == '<'));
            break;
        case '/' :
        case '&' :
        case '~' :
            eof = read_viminfo_search_pattern (virp, forceit);
            break;
        case '$' :
            eof = read_viminfo_sub_string (virp, forceit);
            break;
        case ':' :
        case '?' :
        case '=' :
        case '@' :
            eof = viminfo_readline (virp);
            break;
        case '-' :
        case '\'' :
            if (virp->vir_version < VIMINFO_VERSION_WITH_MARKS)
                eof = read_viminfo_filemark (virp, forceit);
            else
                eof = viminfo_readline (virp);
            break;
        default :
            if (viminfo_error ("E575: ", _ ("Illegal starting char"), virp->vir_line))
                eof = TRUE;
            else
                eof = viminfo_readline (virp);
            break;
        }
    }
    FOR_ALL_BUFFERS (buf)
        fmarks_check_names (buf);
    return eof;
}

int viminfo_readline (vir_T *virp) {
    return vim_fgets (virp->vir_line, LSIZE, virp->vir_fd);
}

static int read_viminfo_barline (vir_T *virp, int got_encoding, int force, int writing) {
    char_u *p = virp->vir_line + 1;
    int bartype;
    garray_T values;
    bval_T *vp;
    int i;
    int read_next = TRUE;
    if (*p == '<') {
        if (writing)
            ga_add_string (&virp->vir_barlines, virp->vir_line);
    }
    else {
        ga_init2 (& values, sizeof (bval_T), 20);
        bartype = getdigits (&p);
        switch (bartype) {
        case BARTYPE_VERSION :
            if (!got_encoding) {
                read_next = barline_parse (virp, p, &values);
                vp = (bval_T *) values.ga_data;
                if (values.ga_len > 0 && vp->bv_type == BVAL_NR)
                    virp->vir_version = vp->bv_nr;
            }
            break;
        case BARTYPE_HISTORY :
            read_next = barline_parse (virp, p, &values);
            handle_viminfo_history (& values, writing);
            break;
        case BARTYPE_REGISTER :
            read_next = barline_parse (virp, p, &values);
            handle_viminfo_register (& values, force);
            break;
        case BARTYPE_MARK :
            read_next = barline_parse (virp, p, &values);
            handle_viminfo_mark (& values, force);
            break;
        default :
            if (writing)
                ga_add_string (&virp->vir_barlines, virp->vir_line);
        }
        for (i = 0; i < values.ga_len; ++i) {
            vp = (bval_T *) values.ga_data + i;
            if (vp->bv_type == BVAL_STRING && vp->bv_allocated)
                vim_free (vp->bv_string);
        }
        ga_clear (& values);
    }
    if (read_next)
        return viminfo_readline (virp);
    return FALSE;
}

static int barline_parse (vir_T *virp, char_u *text, garray_T *values) {
    char_u *p = text;
    char_u *nextp = NULL;
    char_u *buf = NULL;
    bval_T *value;
    int i;
    int allocated = FALSE;
    int eof;
    while (*p == ',') {
        ++p;
        if (ga_grow (values, 1) == FAIL)
            break;
        value = (bval_T *) (values->ga_data) + values->ga_len;
        if (*p == '>') {
            if (!allocated) {
                for (i = 0; i < values->ga_len; ++i) {
                    bval_T *vp = (bval_T *) (values->ga_data) + i;
                    if (vp->bv_type == BVAL_STRING && !vp->bv_allocated) {
                        vp->bv_string = vim_strnsave (vp->bv_string, vp->bv_len);
                        vp->bv_allocated = TRUE;
                    }
                }
                allocated = TRUE;
            }
            if (vim_isdigit (p[1])) {
                size_t len;
                size_t todo;
                size_t n;
                ++p;
                len = getdigits (&p);
                buf = alloc ((int) (len + 1));
                if (buf == NULL)
                    return TRUE;
                p = buf;
                for (todo = len; todo > 0; todo -= n) {
                    eof = viminfo_readline (virp);
                    if (eof || virp->vir_line[0] != '|' || virp->vir_line[1] != '<') {
                        vim_free (buf);
                        return eof || virp->vir_line[0] == '|';
                    }
                    n = STRLEN (virp->vir_line);
                    while (n > 0 && (virp->vir_line[n - 1] == NL || virp->vir_line[n - 1] == CAR))
                        --n;
                    n -= 2;
                    if (n > todo) {
                        nextp = virp->vir_line + 2 + todo;
                        n = todo;
                    }
                    mch_memmove (p, virp -> vir_line + 2, n);
                    p += n;
                }
                *p = NUL;
                p = buf;
            }
            else {
                eof = viminfo_readline (virp);
                if (eof || virp->vir_line[0] != '|' || virp->vir_line[1] != '<')
                    return eof || virp->vir_line[0] == '|';
                p = virp->vir_line + 2;
            }
        }
        if (isdigit (*p)) {
            value->bv_type = BVAL_NR;
            value->bv_nr = getdigits (&p);
            ++values->ga_len;
        }
        else if (*p == '"') {
            int len = 0;
            char_u *s = p;
            ++p;
            while (*p != '"') {
                if (*p == NL || *p == NUL)
                    return TRUE;
                if (*p == '\\') {
                    ++p;
                    if (*p == 'n')
                        s[len++] = '\n';
                    else
                        s[len++] = *p;
                    ++p;
                }
                else
                    s[len++] = *p++;
            }
            ++p;
            s[len] = NUL;
            if (s != buf && allocated)
                s = vim_strsave (s);
            value->bv_string = s;
            value->bv_type = BVAL_STRING;
            value->bv_len = len;
            value->bv_allocated = allocated;
            ++values->ga_len;
            if (nextp != NULL) {
                p = nextp;
                nextp = NULL;
            }
        }
        else if (*p == ',') {
            value->bv_type = BVAL_EMPTY;
            ++values->ga_len;
        }
        else
            break;
    }
    return TRUE;
}

static int viminfo_encoding (vir_T *virp) {
    return viminfo_readline (virp);
}

char_u *viminfo_readstring (vir_T *virp, int off, int convert) {
    char_u *retval;
    char_u *s, *d;
    long  len;
    if (virp->vir_line[off] == Ctrl_V && vim_isdigit (virp->vir_line[off + 1])) {
        len = atol ((char *) virp->vir_line + off + 1);
        retval = lalloc (len, TRUE);
        if (retval == NULL) {
            (void) vim_fgets (virp->vir_line, 10, virp->vir_fd);
            return NULL;
        }
        (void) vim_fgets (retval, (int) len, virp->vir_fd);
        s = retval + 1;
    }
    else {
        retval = vim_strsave (virp->vir_line + off);
        if (retval == NULL)
            return NULL;
        s = retval;
    }
    d = retval;
    while (*s != NUL && *s != '\n') {
        if (s[0] == Ctrl_V && s[1] != NUL) {
            if (s[1] == 'n')
                *d++ = '\n';
            else
                *d++ = Ctrl_V;
            s += 2;
        }
        else
            *d++ = *s++;
    }
    *d = NUL;
    return retval;
}

int viminfo_error (char *errnum, char *message, char_u *line) {
    vim_snprintf ((char *) IObuff, IOSIZE, _ ("%sviminfo: %s in line: "), errnum, message);
    STRNCAT (IObuff, line, IOSIZE - STRLEN (IObuff) - 1);
    if (IObuff[STRLEN (IObuff) - 1] == '\n')
        IObuff[STRLEN (IObuff) - 1] = NUL;
    emsg (IObuff);
    if (++viminfo_errcnt >= 10) {
        EMSG (_ ("E136: viminfo: Too many errors, skipping rest of file"));
        return TRUE;
    }
    return FALSE;
}

int read_viminfo_sub_string (vir_T *virp, int force) {
    if (force)
        vim_free (old_sub);
    if (force || old_sub == NULL)
        old_sub = viminfo_readstring (virp, 1, TRUE);
    return viminfo_readline (virp);
}

static void write_viminfo_version (FILE *fp_out) {
    fprintf (fp_out, "# Viminfo version\n|%d,%d\n\n", BARTYPE_VERSION, VIMINFO_VERSION);
}

void viminfo_writestring (FILE *fd, char_u *p) {
    int c;
    char_u *s;
    int len = 0;
    for (s = p; *s != NUL; ++s) {
        if (*s == Ctrl_V || *s == '\n')
            ++len;
        ++len;
    }
    if (len > LSIZE / 2)
        fprintf (fd, IF_EB ("\026%d\n<", CTRL_V_STR "%d\n<"), len +3);
    while ((c = *p++) != NUL) {
        if (c == Ctrl_V || c == '\n') {
            putc (Ctrl_V, fd);
            if (c == '\n')
                c = 'n';
        }
        putc (c, fd);
    }
    putc ('\n', fd);
}

void write_viminfo_sub_string (FILE *fp) {
    if (get_viminfo_parameter ('/') != 0 && old_sub != NULL) {
        fputs (_ ("\n# Last Substitute String:\n$"), fp);
        viminfo_writestring (fp, old_sub);
    }
}

int barline_writestring (FILE *fd, char_u *s, int remaining_start) {
    char_u *p;
    int remaining = remaining_start;
    int len = 2;
    for (p = s; *p != NUL; ++p) {
        if (*p == NL)
            len += 2;
        else if (*p == '"' || *p == '\\')
            len += 2;
        else
            ++len;
    }
    if (len > remaining - 2) {
        fprintf (fd, ">%d\n|<", len);
        remaining = LSIZE - 20;
    }
    putc ('"', fd);
    for (p = s; *p != NUL; ++p) {
        if (*p == NL) {
            putc ('\\', fd);
            putc ('n', fd);
            --remaining;
        }
        else if (*p == '"' || *p == '\\') {
            putc ('\\', fd);
            putc (* p, fd);
            --remaining;
        }
        else
            putc (*p, fd);
        --remaining;
        if (remaining < 3) {
            putc ('\n', fd);
            putc ('|', fd);
            putc ('<', fd);
            remaining = LSIZE - 20;
        }
    }
    putc ('"', fd);
    return remaining - 2;
}

static void write_viminfo_barlines (vir_T *virp, FILE *fp_out) {
    int i;
    garray_T *gap = &virp->vir_barlines;
    int seen_useful = FALSE;
    char *line;
    if (gap->ga_len > 0) {
        fputs (_ ("\n# Bar lines, copied verbatim:\n"), fp_out);
        for (i = 0; i < gap->ga_len; ++i) {
            line = ((char **) (gap->ga_data))[i];
            if (seen_useful || line[1] != '<') {
                fputs (line, fp_out);
                seen_useful = TRUE;
            }
        }
    }
}

char_u *sign_get_text (int typenr) {
    sign_T *sp;
    for (sp = first_sign; sp != NULL; sp = sp->sn_next)
        if (sp->sn_typenr == typenr)
            return sp->sn_text;
    return NULL;
}

int sign_get_attr (int typenr, int line) {
    sign_T *sp;
    for (sp = first_sign; sp != NULL; sp = sp->sn_next)
        if (sp->sn_typenr == typenr) {
            if (line) {
                if (sp->sn_line_hl > 0)
                    return syn_id2attr (sp->sn_line_hl);
            }
            else {
                if (sp->sn_text_hl > 0)
                    return syn_id2attr (sp->sn_text_hl);
            }
            break;
        }
    return 0;
}

static int linelen (int *has_tab) {
    char_u *line;
    char_u *first;
    char_u *last;
    int save;
    int len;
    line = ml_get_curline ();
    first = skipwhite (line);
    for (last = first + STRLEN (first); last > first && VIM_ISWHITE (last[-1]); --last)
        ;
    save = *last;
    *last = NUL;
    len = linetabsize (line);
    if (has_tab != NULL)
        *has_tab = (vim_strrchr (first, TAB) != NULL);
    *last = save;
    return len;
}

int check_overwrite (exarg_T *eap, buf_T *buf, char_u *fname, char_u *ffname, int other) {
    if ((other || (buf->b_flags & BF_NOTEDITED) || ((buf->b_flags & BF_NEW) && vim_strchr (p_cpo, CPO_OVERNEW) == NULL) || (buf->b_flags & BF_READERR)) && !p_wa && !bt_nofile (buf) && vim_fexists (ffname)) {
        if (!eap->forceit && !eap->append) {
            if (mch_isdir (ffname)) {
                EMSG2 (_ (e_isadir2), ffname);
                return FAIL;
            }
            if (p_confirm || cmdmod.confirm) {
                char_u buff [DIALOG_MSG_SIZE];
                dialog_msg (buff, _ ("Overwrite existing file \"%s\"?"), fname);
                if (vim_dialog_yesno (VIM_QUESTION, NULL, buff, 2) != VIM_YES)
                    return FAIL;
                eap->forceit = TRUE;
            }
            else {
                EMSG (_ (e_exists));
                return FAIL;
            }
        }
        if (other && !emsg_silent) {
            char_u *dir;
            char_u *p;
            int r;
            char_u *swapname;
            if (*p_dir == NUL) {
                dir = alloc (5);
                if (dir == NULL)
                    return FAIL;
                STRCPY (dir, ".");
            }
            else {
                dir = alloc (MAXPATHL);
                if (dir == NULL)
                    return FAIL;
                p = p_dir;
                copy_option_part (& p, dir, MAXPATHL, ",");
            }
            swapname = makeswapname (fname, ffname, curbuf, dir);
            vim_free (dir);
            r = vim_fexists (swapname);
            if (r) {
                if (p_confirm || cmdmod.confirm) {
                    char_u buff [DIALOG_MSG_SIZE];
                    dialog_msg (buff, _ ("Swap file \"%s\" exists, overwrite anyway?"), swapname);
                    if (vim_dialog_yesno (VIM_QUESTION, NULL, buff, 2) != VIM_YES) {
                        vim_free (swapname);
                        return FAIL;
                    }
                    eap->forceit = TRUE;
                }
                else {
                    EMSG2 (_ ("E768: Swap file exists: %s (:silent! overrides)"), swapname);
                    vim_free (swapname);
                    return FAIL;
                }
            }
            vim_free (swapname);
        }
    }
    return OK;
}

int do_ecmd (int fnum, char_u *ffname, char_u *sfname, exarg_T *eap, linenr_T newlnum, int flags, win_T *oldwin) {
    int other_file;
    int oldbuf;
    int auto_buf = FALSE;
    char_u *new_name = NULL;
    int did_set_swapcommand = FALSE;
    buf_T *buf;
    bufref_T bufref;
    bufref_T old_curbuf;
    char_u *free_fname = NULL;
    int retval = FAIL;
    long  n;
    pos_T orig_pos;
    linenr_T topline = 0;
    int newcol = -1;
    int solcol = -1;
    pos_T *pos;
    char_u *command = NULL;
    int did_get_winopts = FALSE;
    int readfile_flags = 0;
    int did_inc_redrawing_disabled = FALSE;
    if (eap != NULL)
        command = eap->do_ecmd_cmd;
    set_bufref (& old_curbuf, curbuf);
    if (fnum != 0) {
        if (fnum == curbuf->b_fnum)
            return OK;
        other_file = TRUE;
    }
    else {
        if (sfname == NULL)
            sfname = ffname;
        if ((flags & ECMD_ADDBUF) && (ffname == NULL || *ffname == NUL))
            goto theend;
        if (ffname == NULL)
            other_file = TRUE;
        else if (*ffname == NUL && curbuf->b_ffname == NULL)
            other_file = FALSE;
        else {
            if (*ffname == NUL) {
                ffname = curbuf->b_ffname;
                sfname = curbuf->b_fname;
            }
            free_fname = fix_fname (ffname);
            if (free_fname != NULL)
                ffname = free_fname;
            other_file = otherfile (ffname);
        }
    }
    if (((!other_file && !(flags & ECMD_OLDBUF)) || (curbuf->b_nwindows == 1 && !(flags & (ECMD_HIDE | ECMD_ADDBUF)))) && check_changed (curbuf, (p_awa ? CCGD_AW : 0) | (other_file ? 0 : CCGD_MULTWIN) | ((flags & ECMD_FORCEIT) ? CCGD_FORCEIT : 0) | (eap == NULL ? 0 : CCGD_EXCMD))) {
        if (fnum == 0 && other_file && ffname != NULL)
            (void) setaltfname (ffname, sfname, newlnum < 0 ? 0 : newlnum);
        goto theend;
    }
    reset_VIsual ();
    if ((command != NULL || newlnum > (linenr_T) 0) && *get_vim_var_str (VV_SWAPCOMMAND) == NUL) {
        int len;
        char_u *p;
        if (command != NULL)
            len = (int) STRLEN (command) + 3;
        else
            len = 30;
        p = alloc ((unsigned ) len);
        if (p != NULL) {
            if (command != NULL)
                vim_snprintf ((char *) p, len, ":%s\r", command);
            else
                vim_snprintf ((char *) p, len, "%ldG", (long ) newlnum);
            set_vim_var_string (VV_SWAPCOMMAND, p, - 1);
            did_set_swapcommand = TRUE;
            vim_free (p);
        }
    }
    if (other_file) {
        if (!(flags & ECMD_ADDBUF)) {
            if (!cmdmod.keepalt)
                curwin->w_alt_fnum = curbuf->b_fnum;
            if (oldwin != NULL)
                buflist_altfpos (oldwin);
        }
        if (fnum)
            buf = buflist_findnr (fnum);
        else {
            if (flags & ECMD_ADDBUF) {
                linenr_T tlnum = 1L;
                if (command != NULL) {
                    tlnum = atol ((char *) command);
                    if (tlnum <= 0)
                        tlnum = 1L;
                }
                (void) buflist_new (ffname, sfname, tlnum, BLN_LISTED);
                goto theend;
            }
            buf = buflist_new (ffname, sfname, 0L, BLN_CURBUF | ((flags & ECMD_SET_HELP) ? 0 : BLN_LISTED));
            if (oldwin != NULL)
                oldwin = curwin;
            set_bufref (& old_curbuf, curbuf);
        }
        if (buf == NULL)
            goto theend;
        if (buf->b_ml.ml_mfp == NULL) {
            oldbuf = FALSE;
        }
        else {
            oldbuf = TRUE;
            set_bufref (& bufref, buf);
            (void) buf_check_timestamp (buf, FALSE);
            if (!bufref_valid (&bufref) || curbuf != old_curbuf.br_buf)
                goto theend;
            if (aborting ())
                goto theend;
        }
        if ((oldbuf && newlnum == ECMD_LASTL) || newlnum == ECMD_LAST) {
            pos = buflist_findfpos (buf);
            newlnum = pos->lnum;
            solcol = pos->col;
        }
        if (buf != curbuf) {
            if (buf->b_fname != NULL)
                new_name = vim_strsave (buf->b_fname);
            set_bufref (& au_new_curbuf, buf);
            apply_autocmds (EVENT_BUFLEAVE, NULL, NULL, FALSE, curbuf);
            if (!bufref_valid (&au_new_curbuf)) {
                delbuf_msg (new_name);
                goto theend;
            }
            if (aborting ()) {
                vim_free (new_name);
                goto theend;
            }
            if (buf == curbuf)
                auto_buf = TRUE;
            else {
                win_T *the_curwin = curwin;
                the_curwin->w_closing = TRUE;
                ++buf->b_locked;
                if (curbuf == old_curbuf.br_buf)
                    buf_copy_options (buf, BCO_ENTER);
                u_sync (FALSE);
                close_buffer (oldwin, curbuf, (flags & ECMD_HIDE) ? 0 : DOBUF_UNLOAD, FALSE);
                the_curwin->w_closing = FALSE;
                --buf->b_locked;
                if (aborting () && curwin->w_buffer != NULL) {
                    vim_free (new_name);
                    goto theend;
                }
                if (!bufref_valid (&au_new_curbuf)) {
                    delbuf_msg (new_name);
                    goto theend;
                }
                if (buf == curbuf)
                    auto_buf = TRUE;
                else {
                    if (curwin->w_buffer == NULL || curwin->w_s == &(curwin->w_buffer->b_s))
                        curwin->w_s = &(buf->b_s);
                    curwin->w_buffer = buf;
                    curbuf = buf;
                    ++curbuf->b_nwindows;
                    if (!oldbuf && eap != NULL) {
                        set_file_options (TRUE, eap);
                    }
                }
                get_winopts (curbuf);
                did_get_winopts = TRUE;
            }
            vim_free (new_name);
            au_new_curbuf.br_buf = NULL;
            au_new_curbuf.br_buf_free_count = 0;
        }
        curwin->w_pcmark.lnum = 1;
        curwin->w_pcmark.col = 0;
    }
    else {
        if ((flags & ECMD_ADDBUF) || check_fname () == FAIL)
            goto theend;
        oldbuf = (flags & ECMD_OLDBUF);
    }
    ++RedrawingDisabled;
    did_inc_redrawing_disabled = TRUE;
    buf = curbuf;
    if ((flags & ECMD_SET_HELP) || keep_help_flag) {
        prepare_help_buffer ();
    }
    else {
        if (!curbuf->b_help)
            set_buflisted (TRUE);
    }
    if (buf != curbuf)
        goto theend;
    if (aborting ())
        goto theend;
    did_filetype = FALSE;
    if (!other_file && !oldbuf) {
        set_last_cursor (curwin);
        if (newlnum == ECMD_LAST || newlnum == ECMD_LASTL) {
            newlnum = curwin->w_cursor.lnum;
            solcol = curwin->w_cursor.col;
        }
        buf = curbuf;
        if (buf->b_fname != NULL)
            new_name = vim_strsave (buf->b_fname);
        else
            new_name = NULL;
        set_bufref (& bufref, buf);
        if (p_ur < 0 || curbuf->b_ml.ml_line_count <= p_ur) {
            u_sync (FALSE);
            if (u_savecommon (0, curbuf->b_ml.ml_line_count + 1, 0, TRUE) == FAIL) {
                vim_free (new_name);
                goto theend;
            }
            u_unchanged (curbuf);
            buf_freeall (curbuf, BFA_KEEP_UNDO);
            readfile_flags = READ_KEEP_UNDO;
        }
        else
            buf_freeall (curbuf, 0);
        if (!bufref_valid (&bufref)) {
            delbuf_msg (new_name);
            goto theend;
        }
        vim_free (new_name);
        if (buf != curbuf)
            goto theend;
        if (aborting ())
            goto theend;
        buf_clear_file (curbuf);
        curbuf->b_op_start.lnum = 0;
        curbuf->b_op_end.lnum = 0;
    }
    retval = OK;
    check_arg_idx (curwin);
    if (!auto_buf) {
        curwin_init ();
        {
            win_T *win;
            tabpage_T *tp;
            FOR_ALL_TAB_WINDOWS (tp, win)
                if (win->w_buffer == curbuf)
                    foldUpdateAll (win);
        }
        DO_AUTOCHDIR orig_pos = curwin->w_cursor;
        topline = curwin->w_topline;
        if (!oldbuf) {
            curbuf->b_flags |= BF_CHECK_RO;
            if (should_abort (open_buffer (FALSE, eap, readfile_flags)))
                retval = FAIL;
        }
        else {
            do_modelines (OPT_WINONLY);
            apply_autocmds_retval (EVENT_BUFENTER, NULL, NULL, FALSE, curbuf, & retval);
            apply_autocmds_retval (EVENT_BUFWINENTER, NULL, NULL, FALSE, curbuf, & retval);
        }
        check_arg_idx (curwin);
        if (!EQUAL_POS (curwin->w_cursor, orig_pos)) {
            newlnum = curwin->w_cursor.lnum;
            newcol = curwin->w_cursor.col;
        }
        if (curwin->w_topline == topline)
            topline = 0;
        changed_line_abv_curs ();
        maketitle ();
    }
    if (curwin->w_p_diff) {
        diff_buf_add (curbuf);
        diff_invalidate (curbuf);
    }
    if (did_get_winopts && curwin->w_p_spell && *curwin->w_s->b_p_spl != NUL)
        (void) did_set_spelllang (curwin);
    if (command == NULL) {
        if (newcol >= 0) {
            curwin->w_cursor.lnum = newlnum;
            curwin->w_cursor.col = newcol;
            check_cursor ();
        }
        else if (newlnum > 0) {
            curwin->w_cursor.lnum = newlnum;
            check_cursor_lnum ();
            if (solcol >= 0 && !p_sol) {
                curwin->w_cursor.col = solcol;
                check_cursor_col ();
                curwin->w_cursor.coladd = 0;
                curwin->w_set_curswant = TRUE;
            }
            else
                beginline (BL_SOL | BL_FIX);
        }
        else {
            if (exmode_active)
                curwin->w_cursor.lnum = curbuf->b_ml.ml_line_count;
            beginline (BL_WHITE | BL_FIX);
        }
    }
    check_lnums (FALSE);
    if (oldbuf && !auto_buf) {
        int msg_scroll_save = msg_scroll;
        if (shortmess (SHM_OVERALL) && !exiting && p_verbose == 0)
            msg_scroll = FALSE;
        if (!msg_scroll)
            check_for_delay (FALSE);
        msg_start ();
        msg_scroll = msg_scroll_save;
        msg_scrolled_ign = TRUE;
        if (!shortmess (SHM_FILEINFO))
            fileinfo (FALSE, TRUE, FALSE);
        msg_scrolled_ign = FALSE;
    }
    curbuf->b_last_used = vim_time ();
    if (command != NULL)
        do_cmdline (command, NULL, NULL, DOCMD_VERBOSE);
    if (curbuf->b_kmap_state & KEYMAP_INIT)
        (void) keymap_init ();
    --RedrawingDisabled;
    did_inc_redrawing_disabled = FALSE;
    if (!skip_redraw) {
        n = p_so;
        if (topline == 0 && command == NULL)
            p_so = 999;
        update_topline ();
        curwin->w_scbind_pos = curwin->w_topline;
        p_so = n;
        redraw_curbuf_later (NOT_VALID);
    }
    if (p_im)
        need_start_insertmode = TRUE;
    if (p_acd && curbuf->b_ffname != NULL) {
        char_u curdir [MAXPATHL];
        char_u filedir [MAXPATHL];
        vim_strncpy (filedir, curbuf -> b_ffname, MAXPATHL - 1);
        *gettail_sep (filedir) = NUL;
        if (mch_dirname (curdir, MAXPATHL) != FAIL && vim_fnamecmp (curdir, filedir) != 0)
            do_autochdir ();
    }
    if (curbuf->b_ffname != NULL) {
        if ((flags & ECMD_SET_HELP) != ECMD_SET_HELP)
            netbeans_file_opened (curbuf);
    }
theend :
    if (did_inc_redrawing_disabled)
        --RedrawingDisabled;
    if (did_set_swapcommand)
        set_vim_var_string (VV_SWAPCOMMAND, NULL, -1);
    vim_free (free_fname);
    return retval;
}

static void delbuf_msg (char_u *name) {
    EMSG2 (_ ("E143: Autocommands unexpectedly deleted new buffer %s"), name == NULL ? (char_u *) "" : name);
    vim_free (name);
    au_new_curbuf.br_buf = NULL;
    au_new_curbuf.br_buf_free_count = 0;
}

static void prepare_help_buffer (void) {
    char_u *p;
    curbuf->b_help = TRUE;
    set_string_option_direct ((char_u *) "buftype", - 1, (char_u *) "help", OPT_FREE | OPT_LOCAL, 0);
    p = (char_u *) "!-~,^*,^|,^\",192-255";
    if (STRCMP (curbuf->b_p_isk, p) != 0) {
        set_string_option_direct ((char_u *) "isk", - 1, p, OPT_FREE | OPT_LOCAL, 0);
        check_buf_options (curbuf);
        (void) buf_init_chartab (curbuf, FALSE);
    }
    set_string_option_direct ((char_u *) "fdm", - 1, (char_u *) "manual", OPT_FREE | OPT_LOCAL, 0);
    curbuf->b_p_ts = 8;
    curwin->w_p_list = FALSE;
    curbuf->b_p_ma = FALSE;
    curbuf->b_p_bin = FALSE;
    curwin->w_p_nu = 0;
    curwin->w_p_rnu = 0;
    RESET_BINDING (curwin);
    curwin->w_p_arab = FALSE;
    curwin->w_p_rl = FALSE;
    curwin->w_p_fen = FALSE;
    curwin->w_p_diff = FALSE;
    curwin->w_p_spell = FALSE;
    set_buflisted (FALSE);
}

int find_help_tags (char_u *arg, int *num_matches, char_u ***matches, int keep_lang) {
    char_u *s, *d;
    int i;
    static char * (mtable []) = {"*", "g*", "[*", "]*", ":*", "/*", "/\\*", "\"*", "**", "cpo-*", "/\\(\\)", "/\\%(\\)", "?", ":?", "?<CR>", "g?", "g?g?", "g??", "/\\?", "/\\z(\\)", "\\=", ":s\\=", "[count]", "[quotex]", "[range]", ":[range]", "[pattern]", "\\|", "\\%$", "s/\\~", "s/\\U", "s/\\L", "s/\\1", "s/\\2", "s/\\3", "s/\\9"};
    static char * (rtable []) = {"star", "gstar", "[star", "]star", ":star", "/star", "/\\\\star", "quotestar", "starstar", "cpo-star", "/\\\\(\\\\)", "/\\\\%(\\\\)", "?", ":?", "?<CR>", "g?", "g?g?", "g??", "/\\\\?", "/\\\\z(\\\\)", "\\\\=", ":s\\\\=", "\\[count]", "\\[quotex]", "\\[range]", ":\\[range]", "\\[pattern]", "\\\\bar", "/\\\\%\\$", "s/\\\\\\~", "s/\\\\U", "s/\\\\L", "s/\\\\1", "s/\\\\2", "s/\\\\3", "s/\\\\9"};
    int flags;
    d = IObuff;
    for (i = (int) (sizeof (mtable) / sizeof (char *)); --i >= 0;)
        if (STRCMP (arg, mtable[i]) == 0) {
            STRCPY (d, rtable [i]);
            break;
        }
    if (i < 0) {
        if (arg[0] == '\\' && ((arg[1] != NUL && arg[2] == NUL) || (vim_strchr ((char_u *) "%_z@", arg[1]) != NULL && arg[2] != NUL))) {
            STRCPY (d, "/\\\\");
            STRCPY (d + 3, arg + 1);
            if (d[3] == '_' && d[4] == '$')
                STRCPY (d +4, "\\$");
        }
        else {
            if ((arg[0] == '[' && (arg[1] == ':' || (arg[1] == '+' && arg[2] == '+'))) || (arg[0] == '\\' && arg[1] == '{'))
                *d++ = '\\';
            if (*arg == '(' && arg[1] == '\'')
                arg++;
            for (s = arg; *s; ++s) {
                if (d - IObuff > IOSIZE - 10)
                    break;
                switch (*s) {
                case '|' :
                    STRCPY (d, "bar");
                    d += 3;
                    continue;
                case '"' :
                    STRCPY (d, "quote");
                    d += 5;
                    continue;
                case '*' :
                    *d++ = '.';
                    break;
                case '?' :
                    *d++ = '.';
                    continue;
                case '$' :
                case '.' :
                case '~' :
                    *d++ = '\\';
                    break;
                }
                if (*s < ' ' || (*s == '^' && s[1] && (ASCII_ISALPHA (s[1]) || vim_strchr ((char_u *) "?@[\\]^", s[1]) != NULL))) {
                    if (d > IObuff && d[-1] != '_' && d[-1] != '\\')
                        *d++ = '_';
                    STRCPY (d, "CTRL-");
                    d += 5;
                    if (*s < ' ') {
                        *d++ = *s + '@';
                        if (d[-1] == '\\')
                            *d++ = '\\';
                    }
                    else
                        *d++ = *++s;
                    if (s[1] != NUL && s[1] != '_')
                        *d++ = '_';
                    continue;
                }
                else if (*s == '^')
                    *d++ = '\\';
                else if (s[0] == '\\' && s[1] != '\\' && *arg == '/' && s == arg + 1)
                    *d++ = '\\';
                if (STRNICMP (s, "CTRL-\\_", 7) == 0) {
                    STRCPY (d, "CTRL-\\\\");
                    d += 7;
                    s += 6;
                }
                *d++ = *s;
                if (*s == '(' && (s[1] == '{' || s[1] == '['))
                    break;
                if (*s == '\'' && s > arg && *arg == '\'')
                    break;
                if (*s == '}' && s > arg && *arg == '{')
                    break;
            }
            *d = NUL;
            if (*IObuff == '`') {
                if (d > IObuff + 2 && d[-1] == '`') {
                    mch_memmove (IObuff, IObuff + 1, STRLEN (IObuff));
                    d[-2] = NUL;
                }
                else if (d > IObuff + 3 && d[-2] == '`' && d[-1] == ',') {
                    mch_memmove (IObuff, IObuff + 1, STRLEN (IObuff));
                    d[-3] = NUL;
                }
                else if (d > IObuff + 4 && d[-3] == '`' && d[-2] == '\\' && d[-1] == '.') {
                    mch_memmove (IObuff, IObuff + 1, STRLEN (IObuff));
                    d[-4] = NUL;
                }
            }
        }
    }
    *matches = (char_u **) "";
    *num_matches = 0;
    flags = TAG_HELP | TAG_REGEXP | TAG_NAMES | TAG_VERBOSE;
    if (keep_lang)
        flags |= TAG_KEEP_LANG;
    if (find_tags (IObuff, num_matches, matches, flags, (int) MAXCOL, NULL) == OK && *num_matches > 0) {
        qsort ((void *) * matches, (size_t) * num_matches, sizeof (char_u *), help_compare);
        while (*num_matches > TAG_MANY)
            vim_free ((*matches)[--*num_matches]);
    }
    return OK;
}

int prepare_tagpreview (int undo_sync) {
    win_T *wp;
    need_mouse_correct = TRUE;
    if (!curwin->w_p_pvw) {
        FOR_ALL_WINDOWS (wp)
            if (wp->w_p_pvw)
                break;
        if (wp != NULL)
            win_enter (wp, undo_sync);
        else {
            if (win_split (g_do_tagpreview > 0 ? g_do_tagpreview : 0, 0) == FAIL)
                return FALSE;
            curwin->w_p_pvw = TRUE;
            curwin->w_p_wfh = TRUE;
            RESET_BINDING (curwin);
            curwin->w_p_diff = FALSE;
            curwin->w_p_fdc = 0;
            return TRUE;
        }
    }
    return FALSE;
}

int getfile (int fnum, char_u *ffname, char_u *sfname, int setpm, linenr_T lnum, int forceit) {
    int other;
    int retval;
    char_u *free_me = NULL;
    if (text_locked ())
        return GETFILE_ERROR;
    if (curbuf_locked ())
        return GETFILE_ERROR;
    if (fnum == 0) {
        fname_expand (curbuf, & ffname, & sfname);
        other = otherfile (ffname);
        free_me = ffname;
    }
    else
        other = (fnum != curbuf->b_fnum);
    if (other)
        ++no_wait_return;
    if (other && !forceit && curbuf->b_nwindows == 1 && !buf_hide (curbuf) && curbufIsChanged () && autowrite (curbuf, forceit) == FAIL) {
        if (p_confirm && p_write)
            dialog_changed (curbuf, FALSE);
        if (curbufIsChanged ()) {
            if (other)
                --no_wait_return;
            no_write_message ();
            retval = GETFILE_NOT_WRITTEN;
            goto theend;
        }
    }
    if (other)
        --no_wait_return;
    if (setpm)
        setpcmark ();
    if (!other) {
        if (lnum != 0)
            curwin->w_cursor.lnum = lnum;
        check_cursor_lnum ();
        beginline (BL_SOL | BL_FIX);
        retval = GETFILE_SAME_FILE;
    }
    else if (do_ecmd (fnum, ffname, sfname, NULL, lnum, (buf_hide (curbuf) ? ECMD_HIDE : 0) + (forceit ? ECMD_FORCEIT : 0), curwin) == OK)
        retval = GETFILE_OPEN_OTHER;
    else
        retval = GETFILE_ERROR;
theend :
    vim_free (free_me);
    return retval;
}

int help_heuristic (char_u *matched_string, int offset, int wrong_case) {
    int num_letters;
    char_u *p;
    num_letters = 0;
    for (p = matched_string; *p; p++)
        if (ASCII_ISALNUM (*p))
            num_letters++;
    if (ASCII_ISALNUM (matched_string[offset]) && offset > 0 && ASCII_ISALNUM (matched_string[offset - 1]))
        offset += 10000;
    else if (offset > 2)
        offset *= 200;
    if (wrong_case)
        offset += 5000;
    if (matched_string[0] == '+' && matched_string[1] != NUL)
        offset += 100;
    return (int) (100 * num_letters + STRLEN (matched_string) + offset);
}

static int help_compare (const void *s1, const void *s2) {
    char *p1;
    char *p2;
    p1 = *(char**) s1 + strlen (*(char**) s1) + 1;
    p2 = *(char**) s2 + strlen (*(char**) s2) + 1;
    return strcmp (p1, p2);
}

char_u *get_sign_name (expand_T *xp, int idx) {
    sign_T *sp;
    int current_idx;
    switch (expand_what) {
    case EXP_SUBCMD :
        return (char_u *) cmds[idx];
    case EXP_DEFINE :
        {
            char *define_arg [] = {"icon=", "linehl=", "text=", "texthl=", NULL};
            return (char_u *) define_arg[idx];
        }
    case EXP_PLACE :
        {
            char *place_arg [] = {"line=", "name=", "file=", "buffer=", NULL};
            return (char_u *) place_arg[idx];
        }
    case EXP_UNPLACE :
        {
            char *unplace_arg [] = {"file=", "buffer=", NULL};
            return (char_u *) unplace_arg[idx];
        }
    case EXP_SIGN_NAMES :
        current_idx = 0;
        for (sp = first_sign; sp != NULL; sp = sp->sn_next)
            if (current_idx++ == idx)
                return sp->sn_name;
        return NULL;
    default :
        return NULL;
    }
}

char_u *make_filter_cmd (char_u *cmd, char_u *itmp, char_u *otmp) {
    char_u *buf;
    long_u len;
    int is_fish_shell;
    char_u *shell_name = get_isolated_shell_name ();
    is_fish_shell = (fnamecmp (shell_name, "fish") == 0);
    vim_free (shell_name);
    if (is_fish_shell)
        len = (long_u) STRLEN (cmd) + 13;
    else
        len = (long_u) STRLEN (cmd) + 3;
    if (itmp != NULL)
        len += (long_u) STRLEN (itmp) + 9;
    if (otmp != NULL)
        len += (long_u) STRLEN (otmp) + (long_u) STRLEN (p_srr) + 2;
    buf = lalloc (len, TRUE);
    if (buf == NULL)
        return NULL;
    if (itmp != NULL || otmp != NULL) {
        if (is_fish_shell)
            vim_snprintf ((char *) buf, len, "begin; %s; end", (char *) cmd);
        else
            vim_snprintf ((char *) buf, len, "(%s)", (char *) cmd);
    }
    else
        STRCPY (buf, cmd);
    if (itmp != NULL) {
        STRCAT (buf, " < ");
        STRCAT (buf, itmp);
    }
    if (otmp != NULL)
        append_redir (buf, (int) len, p_srr, otmp);
    return buf;
}

char_u *skip_vimgrep_pat (char_u *p, char_u **s, int *flags) {
    int c;
    if (vim_isIDc (*p)) {
        if (s != NULL)
            *s = p;
        p = skiptowhite (p);
        if (s != NULL && *p != NUL)
            *p++ = NUL;
    }
    else {
        if (s != NULL)
            *s = p + 1;
        c = *p;
        p = skip_regexp (p +1, c, TRUE, NULL);
        if (*p != c)
            return NULL;
        if (s != NULL)
            *p = NUL;
        ++p;
        while (*p == 'g' || *p == 'j') {
            if (flags != NULL) {
                if (*p == 'g')
                    *flags |= VGR_GLOBAL;
                else
                    *flags |= VGR_NOJUMP;
            }
            ++p;
        }
    }
    return p;
}

void set_context_in_sign_cmd (expand_T *xp, char_u *arg) {
    char_u *p;
    char_u *end_subcmd;
    char_u *last;
    int cmd_idx;
    char_u *begin_subcmd_args;
    xp->xp_context = EXPAND_SIGN;
    expand_what = EXP_SUBCMD;
    xp->xp_pattern = arg;
    end_subcmd = skiptowhite (arg);
    if (*end_subcmd == NUL)
        return;
    cmd_idx = sign_cmd_idx (arg, end_subcmd);
    begin_subcmd_args = skipwhite (end_subcmd);
    p = skiptowhite (begin_subcmd_args);
    if (*p == NUL) {
        xp->xp_pattern = begin_subcmd_args;
        switch (cmd_idx) {
        case SIGNCMD_LIST :
        case SIGNCMD_UNDEFINE :
            expand_what = EXP_SIGN_NAMES;
            break;
        default :
            xp->xp_context = EXPAND_NOTHING;
        }
        return;
    }
    do {
        p = skipwhite (p);
        last = p;
        p = skiptowhite (p);
    }
    while (*p != NUL);
    p = vim_strchr (last, '=');
    if (p == NULL) {
        xp->xp_pattern = last;
        switch (cmd_idx) {
        case SIGNCMD_DEFINE :
            expand_what = EXP_DEFINE;
            break;
        case SIGNCMD_PLACE :
            expand_what = EXP_PLACE;
            break;
        case SIGNCMD_JUMP :
        case SIGNCMD_UNPLACE :
            expand_what = EXP_UNPLACE;
            break;
        default :
            xp->xp_context = EXPAND_NOTHING;
        }
    }
    else {
        xp->xp_pattern = p + 1;
        switch (cmd_idx) {
        case SIGNCMD_DEFINE :
            if (STRNCMP (last, "texthl", p -last) == 0 || STRNCMP (last, "linehl", p -last) == 0)
                xp->xp_context = EXPAND_HIGHLIGHT;
            else if (STRNCMP (last, "icon", p -last) == 0)
                xp->xp_context = EXPAND_FILES;
            else
                xp->xp_context = EXPAND_NOTHING;
            break;
        case SIGNCMD_PLACE :
            if (STRNCMP (last, "name", p -last) == 0)
                expand_what = EXP_SIGN_NAMES;
            else
                xp->xp_context = EXPAND_NOTHING;
            break;
        default :
            xp->xp_context = EXPAND_NOTHING;
        }
    }
}

static int sign_cmd_idx (char_u *begin_cmd, char_u *end_cmd) {
    int idx;
    char save = *end_cmd;
    *end_cmd = NUL;
    for (idx = 0;; ++idx)
        if (cmds[idx] == NULL || STRCMP (begin_cmd, cmds[idx]) == 0)
            break;
    *end_cmd = save;
    return idx;
}

void do_fixdel (exarg_T *eap) {
    char_u *p;
    p = find_termcode ((char_u *) "kb");
    add_termcode ((char_u *) "kD", p != NULL && * p == DEL ? (char_u *) CTRL_H_STR : DEL_STR, FALSE);
}

void print_line_no_prefix (linenr_T lnum, int use_number, int list) {
    char_u numbuf [30];
    if (curwin->w_p_nu || use_number) {
        vim_snprintf ((char *) numbuf, sizeof (numbuf), "%*ld ", number_width (curwin), (long) lnum);
        msg_puts_attr (numbuf, HL_ATTR (HLF_N));
    }
    msg_prt_line (ml_get (lnum), list);
}

int read_viminfo (char_u *file, int flags) {
    FILE *fp;
    char_u *fname;
    if (no_viminfo ())
        return FAIL;
    fname = viminfo_filename (file);
    if (fname == NULL)
        return FAIL;
    fp = mch_fopen ((char *) fname, READBIN);
    if (p_verbose > 0) {
        verbose_enter ();
        smsg ((char_u *) _ ("Reading viminfo file \"%s\"%s%s%s"), fname, (flags & VIF_WANT_INFO) ? _ (" info") : "", (flags & VIF_WANT_MARKS) ? _ (" marks") : "", (flags & VIF_GET_OLDFILES) ? _ (" oldfiles") : "", fp == NULL ? _ (" FAILED") : "");
        verbose_leave ();
    }
    vim_free (fname);
    if (fp == NULL)
        return FAIL;
    viminfo_errcnt = 0;
    do_viminfo (fp, NULL, flags);
    fclose (fp);
    return OK;
}

void fix_help_buffer (void) {
    linenr_T lnum;
    char_u *line;
    int in_example = FALSE;
    int len;
    char_u *fname;
    char_u *p;
    char_u *rt;
    int mustfree;
    if (STRCMP (curbuf->b_p_ft, "help") != 0) {
        ++curbuf_lock;
        set_option_value ((char_u *) "ft", 0L, (char_u *) "help", OPT_LOCAL);
        --curbuf_lock;
    }
    if (!syntax_present (curwin)) {
        for (lnum = 1; lnum <= curbuf->b_ml.ml_line_count; ++lnum) {
            line = ml_get_buf (curbuf, lnum, FALSE);
            len = (int) STRLEN (line);
            if (in_example && len > 0 && !VIM_ISWHITE (line[0])) {
                if (line[0] == '<') {
                    line = ml_get_buf (curbuf, lnum, TRUE);
                    line[0] = ' ';
                }
                in_example = FALSE;
            }
            if (!in_example && len > 0) {
                if (line[len - 1] == '>' && (len == 1 || line[len - 2] == ' ')) {
                    line = ml_get_buf (curbuf, lnum, TRUE);
                    line[len - 1] = ' ';
                    in_example = TRUE;
                }
                else if (line[len - 1] == '~') {
                    line = ml_get_buf (curbuf, lnum, TRUE);
                    line[len - 1] = ' ';
                }
            }
        }
    }
    fname = gettail (curbuf->b_fname);
    if (fnamecmp (fname, "help.txt") == 0 || (fnamencmp (fname, "help.", 5) == 0 && ASCII_ISALPHA (fname[5]) && ASCII_ISALPHA (fname[6]) && TOLOWER_ASC (fname[7]) == 'x' && fname[8] == NUL)) {
        for (lnum = 1; lnum < curbuf->b_ml.ml_line_count; ++lnum) {
            line = ml_get_buf (curbuf, lnum, FALSE);
            if (strstr ((char *) line, "*local-additions*") == NULL)
                continue;
            p = p_rtp;
            while (*p != NUL) {
                copy_option_part (& p, NameBuff, MAXPATHL, ",");
                mustfree = FALSE;
                rt = vim_getenv ((char_u *) "VIMRUNTIME", &mustfree);
                if (rt != NULL && fullpathcmp (rt, NameBuff, FALSE) != FPC_SAME) {
                    int fcount;
                    char_u **fnames;
                    FILE *fd;
                    char_u *s;
                    int fi;
                    add_pathsep (NameBuff);
                    STRCAT (NameBuff, "doc/*.??[tx]");
                    if (gen_expand_wildcards (1, &NameBuff, &fcount, &fnames, EW_FILE | EW_SILENT) == OK && fcount > 0) {
                        int i1, i2;
                        char_u *f1, *f2;
                        char_u *t1, *t2;
                        char_u *e1, *e2;
                        for (i1 = 0; i1 < fcount; ++i1) {
                            for (i2 = 0; i2 < fcount; ++i2) {
                                if (i1 == i2)
                                    continue;
                                if (fnames[i1] == NULL || fnames[i2] == NULL)
                                    continue;
                                f1 = fnames[i1];
                                f2 = fnames[i2];
                                t1 = gettail (f1);
                                t2 = gettail (f2);
                                e1 = vim_strrchr (t1, '.');
                                e2 = vim_strrchr (t2, '.');
                                if (e1 == NULL || e2 == NULL)
                                    continue;
                                if (fnamecmp (e1, ".txt") != 0 && fnamecmp (e1, fname +4) != 0) {
                                    VIM_CLEAR (fnames [i1]);
                                    continue;
                                }
                                if (e1 - f1 != e2 - f2 || fnamencmp (f1, f2, e1 -f1) != 0)
                                    continue;
                                if (fnamecmp (e1, ".txt") == 0 && fnamecmp (e2, fname +4) == 0)
                                    VIM_CLEAR (fnames[i1]);
                            }
                        }
                        for (fi = 0; fi < fcount; ++fi) {
                            if (fnames[fi] == NULL)
                                continue;
                            fd = mch_fopen ((char *) fnames[fi], "r");
                            if (fd != NULL) {
                                vim_fgets (IObuff, IOSIZE, fd);
                                if (IObuff[0] == '*' && (s = vim_strchr (IObuff +1, '*')) != NULL) {
                                    IObuff[0] = '|';
                                    *s = '|';
                                    while (*s != NUL) {
                                        if (*s == '\r' || *s == '\n')
                                            *s = NUL;
                                        ++s;
                                    }
                                    ml_append (lnum, IObuff, (colnr_T) 0, FALSE);
                                    ++lnum;
                                }
                                fclose (fd);
                            }
                        }
                        FreeWild (fcount, fnames);
                    }
                }
                if (mustfree)
                    vim_free (rt);
            }
            break;
        }
    }
}

void print_line (linenr_T lnum, int use_number, int list) {
    int save_silent = silent_mode;
    if (message_filtered (ml_get (lnum)))
        return;
    msg_start ();
    silent_mode = FALSE;
    info_message = TRUE;
    print_line_no_prefix (lnum, use_number, list);
    if (save_silent) {
        msg_putchar ('\n');
        cursor_on ();
        out_flush ();
        silent_mode = save_silent;
    }
    info_message = FALSE;
}

char_u *sign_typenr2name (int typenr) {
    sign_T *sp;
    for (sp = first_sign; sp != NULL; sp = sp->sn_next)
        if (sp->sn_typenr == typenr)
            return sp->sn_name;
    return (char_u *) _ ("[Deleted]");
}

void ex_help (exarg_T *eap) {
    char_u *arg;
    char_u *tag;
    FILE *helpfd;
    int n;
    int i;
    win_T *wp;
    int num_matches;
    char_u **matches;
    char_u *p;
    int empty_fnum = 0;
    int alt_fnum = 0;
    buf_T *buf;
    int len;
    char_u *lang;
    int old_KeyTyped = KeyTyped;
    if (eap != NULL) {
        for (arg = eap->arg; *arg; ++arg) {
            if (*arg == '\n' || *arg == '\r' || (*arg == '|' && arg[1] != NUL && arg[1] != '|')) {
                *arg++ = NUL;
                eap->nextcmd = arg;
                break;
            }
        }
        arg = eap->arg;
        if (eap->forceit && *arg == NUL && !curbuf->b_help) {
            EMSG (_ ("E478: Don't panic!"));
            return;
        }
        if (eap->skip)
            return;
    }
    else
        arg = (char_u *) "";
    p = arg + STRLEN (arg) - 1;
    while (p > arg && VIM_ISWHITE (*p) && p[-1] != '\\')
        *p-- = NUL;
    lang = check_help_lang (arg);
    if (*arg == NUL)
        arg = (char_u *) "help.txt";
    n = find_help_tags (arg, &num_matches, &matches, eap != NULL && eap->forceit);
    i = 0;
    if (n != FAIL && lang != NULL)
        for (i = 0; i < num_matches; ++i) {
            len = (int) STRLEN (matches[i]);
            if (len > 3 && matches[i][len - 3] == '@' && STRICMP (matches[i] + len - 2, lang) == 0)
                break;
        }
    if (i >= num_matches || n == FAIL) {
        if (lang != NULL)
            EMSG3 (_ ("E661: Sorry, no '%s' help for %s"), lang, arg);
        else
            EMSG2 (_ ("E149: Sorry, no help for %s"), arg);
        if (n != FAIL)
            FreeWild (num_matches, matches);
        return;
    }
    tag = vim_strsave (matches[i]);
    FreeWild (num_matches, matches);
    need_mouse_correct = TRUE;
    if (!bt_help (curwin->w_buffer) || cmdmod.tab != 0) {
        if (cmdmod.tab != 0)
            wp = NULL;
        else
            FOR_ALL_WINDOWS (wp)
                if (bt_help (wp->w_buffer))
                    break;
        if (wp != NULL && wp->w_buffer->b_nwindows > 0)
            win_enter (wp, TRUE);
        else {
            if ((helpfd = mch_fopen ((char *) p_hf, READBIN)) == NULL) {
                smsg ((char_u *) _ ("Sorry, help file \"%s\" not found"), p_hf);
                goto erret;
            }
            fclose (helpfd);
            n = WSP_HELP;
            if (cmdmod.split == 0 && curwin->w_width != Columns && curwin->w_width < 80)
                n |= WSP_TOP;
            if (win_split (0, n) == FAIL)
                goto erret;
            if (curwin->w_height < p_hh)
                win_setheight ((int) p_hh);
            alt_fnum = curbuf->b_fnum;
            (void) do_ecmd (0, NULL, NULL, NULL, ECMD_LASTL, ECMD_HIDE +ECMD_SET_HELP, NULL);
            if (!cmdmod.keepalt)
                curwin->w_alt_fnum = alt_fnum;
            empty_fnum = curbuf->b_fnum;
        }
    }
    if (!p_im)
        restart_edit = 0;
    KeyTyped = old_KeyTyped;
    if (tag != NULL)
        do_tag (tag, DT_HELP, 1, FALSE, TRUE);
    if (empty_fnum != 0 && curbuf->b_fnum != empty_fnum) {
        buf = buflist_findnr (empty_fnum);
        if (buf != NULL && buf->b_nwindows == 0)
            wipe_buffer (buf, TRUE);
    }
    if (alt_fnum != 0 && curwin->w_alt_fnum == empty_fnum && !cmdmod.keepalt)
        curwin->w_alt_fnum = alt_fnum;
erret :
    vim_free (tag);
}

char_u *check_help_lang (char_u *arg) {
    int len = (int) STRLEN (arg);
    if (len >= 3 && arg[len - 3] == '@' && ASCII_ISALPHA (arg[len - 2]) && ASCII_ISALPHA (arg[len - 1])) {
        arg[len - 3] = NUL;
        return arg + len - 2;
    }
    return NULL;
}

void do_ascii (exarg_T *eap) {
    int c;
    int cval;
    char buf1 [20];
    char buf2 [20];
    char_u buf3 [7];
    c = gchar_cursor ();
    if (c == NUL) {
        MSG ("NUL");
        return;
    }
    {
        if (c == NL)
            c = NUL;
        if (c == CAR && get_fileformat (curbuf) == EOL_MAC)
            cval = NL;
        else
            cval = c;
        if (vim_isprintc_strict (c) && (c < ' ' || c > '~')) {
            transchar_nonprint (buf3, c);
            vim_snprintf (buf1, sizeof (buf1), "  <%s>", (char *) buf3);
        }
        else
            buf1[0] = NUL;
        if (c >= 0x80)
            vim_snprintf (buf2, sizeof (buf2), "  <M-%s>", (char *) transchar (c &0x7f));
        else
            buf2[0] = NUL;
        vim_snprintf ((char *) IObuff, IOSIZE, _ ("<%s>%s%s  %d,  Hex %02x,  Octal %03o"), transchar (c), buf1, buf2, cval, cval, cval);
    }
    msg (IObuff);
}

