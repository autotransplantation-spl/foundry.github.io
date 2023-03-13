
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
struct termcode {
    char_u name [2];
    char_u *code;
    int len;
    int modlen;
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
struct builtin_term {
    int bt_entry;
    char *bt_string;
};
EXTERN char *ignoredp;
EXTERN long  p_verbose;
EXTERN char_u *p_mousem;
EXTERN int p_tf;
EXTERN int p_wiv;
EXTERN char_u *p_bg;
EXTERN int p_ek;
EXTERN char_u *p_mouse;
int xt_index_in = 0;
EXTERN long  p_wd;
EXTERN long  p_window;
int need_gather = FALSE;
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
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
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
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
int xt_index_out = 0;
int check_for_codes = FALSE;
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
int cursor_is_off = FALSE;
int initial_cursor_blink = FALSE;
int initial_cursor_shape_blink = FALSE;
int initial_cursor_shape = 0;
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
struct termcode *termcodes = NULL;
char_u out_buf [OUT_SIZE + 1];
int is_not_xterm = FALSE;
char_u termleader [256 + 1];
char_u * (term_strings [(int) KS_LAST + 1]);
EXTERN char_u e_positive [] INIT (= N_ ("E487: Argument must be positive"));
EXTERN hlf_T edit_submode_highl;
EXTERN int highlight_attr [HLF_COUNT];
EXTERN int p_hls;
EXTERN char_u *p_hl;
EXTERN char_u *p_hlg;
int out_pos = 0;
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
int tc_len = 0;
int tc_max_len = 0;
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
struct builtin_term builtin_termcaps [] = {{(int) KS_NAME, "gui"}, {(int) KS_CE, IF_EB ("\033|$", ESC_STR "|$")}, {(int) KS_AL, IF_EB ("\033|i", ESC_STR "|i")}, {(int) KS_CAL, IF_EB ("\033|%p1%dI", ESC_STR "|%p1%dI")}, {(int) KS_DL, IF_EB ("\033|d", ESC_STR "|d")}, {(int) KS_CDL, IF_EB ("\033|%p1%dD", ESC_STR "|%p1%dD")}, {(int) KS_CS, IF_EB ("\033|%p1%d;%p2%dR", ESC_STR "|%p1%d;%p2%dR")}, {(int) KS_CSV, IF_EB ("\033|%p1%d;%p2%dV", ESC_STR "|%p1%d;%p2%dV")}, {(int) KS_CL, IF_EB ("\033|C", ESC_STR "|C")}, {(int) KS_ME, IF_EB ("\033|31H", ESC_STR "|31H")}, {(int) KS_MR, IF_EB ("\033|1h", ESC_STR "|1h")}, {(int) KS_MD, IF_EB ("\033|2h", ESC_STR "|2h")}, {(int) KS_SE, IF_EB ("\033|16H", ESC_STR "|16H")}, {(int) KS_SO, IF_EB ("\033|16h", ESC_STR "|16h")}, {(int) KS_UE, IF_EB ("\033|8H", ESC_STR "|8H")}, {(int) KS_US, IF_EB ("\033|8h", ESC_STR "|8h")}, {(int) KS_UCE, IF_EB ("\033|8C", ESC_STR "|8C")}, {(int) KS_UCS, IF_EB ("\033|8c", ESC_STR "|8c")}, {(int) KS_STE, IF_EB ("\033|4C", ESC_STR "|4C")}, {(int) KS_STS, IF_EB ("\033|4c", ESC_STR "|4c")}, {(int) KS_CZR, IF_EB ("\033|4H", ESC_STR "|4H")}, {(int) KS_CZH, IF_EB ("\033|4h", ESC_STR "|4h")}, {(int) KS_VB, IF_EB ("\033|f", ESC_STR "|f")}, {(int) KS_MS, "y"}, {(int) KS_UT, "y"}, {(int) KS_XN, "y"}, {(int) KS_LE, "\b"}, {(int) KS_ND, "\014"}, {(int) KS_CM, IF_EB ("\033|%p1%d;%p2%dM", ESC_STR "|%p1%d;%p2%dM")}, {(int) KS_NAME, "ansi"}, {(int) KS_CE, IF_EB ("\033[K", ESC_STR "[K")}, {(int) KS_AL, IF_EB ("\033[L", ESC_STR "[L")}, {(int) KS_CAL, IF_EB ("\033[%p1%dL", ESC_STR "[%p1%dL")}, {(int) KS_DL, IF_EB ("\033[M", ESC_STR "[M")}, {(int) KS_CDL, IF_EB ("\033[%p1%dM", ESC_STR "[%p1%dM")}, {(int) KS_CL, IF_EB ("\033[H\033[2J", ESC_STR "[H" ESC_STR_nc "[2J")}, {(int) KS_ME, IF_EB ("\033[0m", ESC_STR "[0m")}, {(int) KS_MR, IF_EB ("\033[7m", ESC_STR "[7m")}, {(int) KS_MS, "y"}, {(int) KS_UT, "y"}, {(int) KS_LE, "\b"}, {(int) KS_CM, IF_EB ("\033[%i%p1%d;%p2%dH", ESC_STR "[%i%p1%d;%p2%dH")}, {(int) KS_CRI, IF_EB ("\033[%p1%dC", ESC_STR "[%p1%dC")}, {(int) KS_NAME, "xterm"}, {(int) KS_CE, IF_EB ("\033[K", ESC_STR "[K")}, {(int) KS_AL, IF_EB ("\033[L", ESC_STR "[L")}, {(int) KS_CAL, IF_EB ("\033[%p1%dL", ESC_STR "[%p1%dL")}, {(int) KS_DL, IF_EB ("\033[M", ESC_STR "[M")}, {(int) KS_CDL, IF_EB ("\033[%p1%dM", ESC_STR "[%p1%dM")}, {(int) KS_CS, IF_EB ("\033[%i%p1%d;%p2%dr", ESC_STR "[%i%p1%d;%p2%dr")}, {(int) KS_CL, IF_EB ("\033[H\033[2J", ESC_STR "[H" ESC_STR_nc "[2J")}, {(int) KS_CD, IF_EB ("\033[J", ESC_STR "[J")}, {(int) KS_ME, IF_EB ("\033[m", ESC_STR "[m")}, {(int) KS_MR, IF_EB ("\033[7m", ESC_STR "[7m")}, {(int) KS_MD, IF_EB ("\033[1m", ESC_STR "[1m")}, {(int) KS_UE, IF_EB ("\033[m", ESC_STR "[m")}, {(int) KS_US, IF_EB ("\033[4m", ESC_STR "[4m")}, {(int) KS_STE, IF_EB ("\033[29m", ESC_STR "[29m")}, {(int) KS_STS, IF_EB ("\033[9m", ESC_STR "[9m")}, {(int) KS_MS, "y"}, {(int) KS_UT, "y"}, {(int) KS_LE, "\b"}, {(int) KS_VI, IF_EB ("\033[?25l", ESC_STR "[?25l")}, {(int) KS_VE, IF_EB ("\033[?25h", ESC_STR "[?25h")}, {(int) KS_VS, IF_EB ("\033[?12h", ESC_STR "[?12h")}, {(int) KS_CVS, IF_EB ("\033[?12l", ESC_STR "[?12l")}, {(int) KS_CSH, IF_EB ("\033[%p1%d q", ESC_STR "[%p1%d q")}, {(int) KS_CRC, IF_EB ("\033[?12$p", ESC_STR "[?12$p")}, {(int) KS_CRS, IF_EB ("\033P$q q\033\\", ESC_STR "P$q q" ESC_STR "\\")}, {(int) KS_CM, IF_EB ("\033[%i%p1%d;%p2%dH", ESC_STR "[%i%p1%d;%p2%dH")}, {(int) KS_SR, IF_EB ("\033M", ESC_STR "M")}, {(int) KS_CRI, IF_EB ("\033[%p1%dC", ESC_STR "[%p1%dC")}, {(int) KS_KS, IF_EB ("\033[?1h\033=", ESC_STR "[?1h" ESC_STR_nc "=")}, {(int) KS_KE, IF_EB ("\033[?1l\033>", ESC_STR "[?1l" ESC_STR_nc ">")}, {(int) KS_CIS, IF_EB ("\033]1;", ESC_STR "]1;")}, {(int) KS_CIE, "\007"}, {(int) KS_TS, IF_EB ("\033]2;", ESC_STR "]2;")}, {(int) KS_FS, "\007"}, {(int) KS_CSC, IF_EB ("\033]12;", ESC_STR "]12;")}, {(int) KS_CEC, "\007"}, {(int) KS_CWS, IF_EB ("\033[8;%p1%d;%p2%dt", ESC_STR "[8;%p1%d;%p2%dt")}, {(int) KS_CWP, IF_EB ("\033[3;%p1%d;%p2%dt", ESC_STR "[3;%p1%d;%p2%dt")}, {(int) KS_CGP, IF_EB ("\033[13t", ESC_STR "[13t")}, {(int) KS_CRV, IF_EB ("\033[>c", ESC_STR "[>c")}, {(
  int) KS_RFG, IF_EB ("\033]10;?\007", ESC_STR "]10;?\007")}, {(int) KS_RBG, IF_EB ("\033]11;?\007", ESC_STR "]11;?\007")}, {(int) KS_U7, IF_EB ("\033[6n", ESC_STR "[6n")}, {(int) KS_8F, IF_EB ("\033[38;2;%lu;%lu;%lum", ESC_STR "[38;2;%lu;%lu;%lum")}, {(int) KS_8B, IF_EB ("\033[48;2;%lu;%lu;%lum", ESC_STR "[48;2;%lu;%lu;%lum")}, {(int) KS_CBE, IF_EB ("\033[?2004h", ESC_STR "[?2004h")}, {(int) KS_CBD, IF_EB ("\033[?2004l", ESC_STR "[?2004l")}, {K_UP, IF_EB ("\033O*A", ESC_STR "O*A")}, {K_DOWN, IF_EB ("\033O*B", ESC_STR "O*B")}, {K_RIGHT, IF_EB ("\033O*C", ESC_STR "O*C")}, {K_LEFT, IF_EB ("\033O*D", ESC_STR "O*D")}, {K_XUP, IF_EB ("\033[1;*A", ESC_STR "[1;*A")}, {K_XDOWN, IF_EB ("\033[1;*B", ESC_STR "[1;*B")}, {K_XRIGHT, IF_EB ("\033[1;*C", ESC_STR "[1;*C")}, {K_XLEFT, IF_EB ("\033[1;*D", ESC_STR "[1;*D")}, {K_XF1, IF_EB ("\033O*P", ESC_STR "O*P")}, {K_XF2, IF_EB ("\033O*Q", ESC_STR "O*Q")}, {K_XF3, IF_EB ("\033O*R", ESC_STR "O*R")}, {K_XF4, IF_EB ("\033O*S", ESC_STR "O*S")}, {K_F1, IF_EB ("\033[11;*~", ESC_STR "[11;*~")}, {K_F2, IF_EB ("\033[12;*~", ESC_STR "[12;*~")}, {K_F3, IF_EB ("\033[13;*~", ESC_STR "[13;*~")}, {K_F4, IF_EB ("\033[14;*~", ESC_STR "[14;*~")}, {K_F5, IF_EB ("\033[15;*~", ESC_STR "[15;*~")}, {K_F6, IF_EB ("\033[17;*~", ESC_STR "[17;*~")}, {K_F7, IF_EB ("\033[18;*~", ESC_STR "[18;*~")}, {K_F8, IF_EB ("\033[19;*~", ESC_STR "[19;*~")}, {K_F9, IF_EB ("\033[20;*~", ESC_STR "[20;*~")}, {K_F10, IF_EB ("\033[21;*~", ESC_STR "[21;*~")}, {K_F11, IF_EB ("\033[23;*~", ESC_STR "[23;*~")}, {K_F12, IF_EB ("\033[24;*~", ESC_STR "[24;*~")}, {K_S_TAB, IF_EB ("\033[Z", ESC_STR "[Z")}, {K_HELP, IF_EB ("\033[28;*~", ESC_STR "[28;*~")}, {K_UNDO, IF_EB ("\033[26;*~", ESC_STR "[26;*~")}, {K_INS, IF_EB ("\033[2;*~", ESC_STR "[2;*~")}, {K_HOME, IF_EB ("\033[1;*H", ESC_STR "[1;*H")}, {K_KHOME, IF_EB ("\033[1;*~", ESC_STR "[1;*~")}, {K_XHOME, IF_EB ("\033O*H", ESC_STR "O*H")}, {K_ZHOME, IF_EB ("\033[7;*~", ESC_STR "[7;*~")}, {K_END, IF_EB ("\033[1;*F", ESC_STR "[1;*F")}, {K_KEND, IF_EB ("\033[4;*~", ESC_STR "[4;*~")}, {K_XEND, IF_EB ("\033O*F", ESC_STR "O*F")}, {K_ZEND, IF_EB ("\033[8;*~", ESC_STR "[8;*~")}, {K_PAGEUP, IF_EB ("\033[5;*~", ESC_STR "[5;*~")}, {K_PAGEDOWN, IF_EB ("\033[6;*~", ESC_STR "[6;*~")}, {K_KPLUS, IF_EB ("\033O*k", ESC_STR "O*k")}, {K_KMINUS, IF_EB ("\033O*m", ESC_STR "O*m")}, {K_KDIVIDE, IF_EB ("\033O*o", ESC_STR "O*o")}, {K_KMULTIPLY, IF_EB ("\033O*j", ESC_STR "O*j")}, {K_KENTER, IF_EB ("\033O*M", ESC_STR "O*M")}, {K_KPOINT, IF_EB ("\033O*n", ESC_STR "O*n")}, {K_KDEL, IF_EB ("\033[3;*~", ESC_STR "[3;*~")}, {K_PS, IF_EB ("\033[200~", ESC_STR "[200~")}, {K_PE, IF_EB ("\033[201~", ESC_STR "[201~")}, {BT_EXTRA_KEYS, ""}, {TERMCAP2KEY ('k', '0'), IF_EB ("\033[10;*~", ESC_STR "[10;*~")}, {TERMCAP2KEY ('F', '3'), IF_EB ("\033[25;*~", ESC_STR "[25;*~")}, {TERMCAP2KEY ('F', '6'), IF_EB ("\033[29;*~", ESC_STR "[29;*~")}, {TERMCAP2KEY ('F', '7'), IF_EB ("\033[31;*~", ESC_STR "[31;*~")}, {TERMCAP2KEY ('F', '8'), IF_EB ("\033[32;*~", ESC_STR "[32;*~")}, {TERMCAP2KEY ('F', '9'), IF_EB ("\033[33;*~", ESC_STR "[33;*~")}, {TERMCAP2KEY ('F', 'A'), IF_EB ("\033[34;*~", ESC_STR "[34;*~")}, {TERMCAP2KEY ('F', 'B'), IF_EB ("\033[42;*~", ESC_STR "[42;*~")}, {TERMCAP2KEY ('F', 'C'), IF_EB ("\033[43;*~", ESC_STR "[43;*~")}, {TERMCAP2KEY ('F', 'D'), IF_EB ("\033[44;*~", ESC_STR "[44;*~")}, {TERMCAP2KEY ('F', 'E'), IF_EB ("\033[45;*~", ESC_STR "[45;*~")}, {TERMCAP2KEY ('F', 'F'), IF_EB ("\033[46;*~", ESC_STR "[46;*~")}, {TERMCAP2KEY ('F', 'G'), IF_EB ("\033[47;*~", ESC_STR "[47;*~")}, {TERMCAP2KEY ('F', 'H'), IF_EB ("\033[48;*~", ESC_STR "[48;*~")}, {TERMCAP2KEY ('F', 'I'), IF_EB ("\033[49;*~", ESC_STR "[49;*~")}, {TERMCAP2KEY ('F', 'J'), IF_EB ("\033[50;*~", ESC_STR "[50;*~")}, {TERMCAP2KEY ('F', 'K'), IF_EB ("\033[51;*~", ESC_STR "[51;*~")}, {TERMCAP2KEY ('F', 'L'), IF_EB ("\033[52;*~", ESC_STR "[52;*~")}, {TERMCAP2KEY ('F', 'M'), IF_EB ("\033[53;*~", ESC_STR "[53;*~")}, {TERMCAP2KEY ('F', 'N'), IF_EB ("\033[54;*~", ESC_STR "[54;*~")}, {TERMCAP2KEY ('F', 'O'), IF_EB ("\033[55;*~", ESC_STR "[55;*~")}, {TERMCAP2KEY ('F', 'P'), IF_EB 
  ("\033[56;*~", ESC_STR "[56;*~")}, {TERMCAP2KEY ('F', 'Q'), IF_EB ("\033[57;*~", ESC_STR "[57;*~")}, {TERMCAP2KEY ('F', 'R'), IF_EB ("\033[58;*~", ESC_STR "[58;*~")}, {(int) KS_NAME, "iris-ansi"}, {(int) KS_CE, "\033[K"}, {(int) KS_CD, "\033[J"}, {(int) KS_AL, "\033[L"}, {(int) KS_CAL, "\033[%p1%dL"}, {(int) KS_DL, "\033[M"}, {(int) KS_CDL, "\033[%p1%dM"}, {(int) KS_CL, "\033[H\033[2J"}, {(int) KS_VE, "\033[9/y\033[12/y"}, {(int) KS_VS, "\033[10/y\033[=1h\033[=2l"}, {(int) KS_TI, "\033[=6h"}, {(int) KS_TE, "\033[=6l"}, {(int) KS_SE, "\033[21;27m"}, {(int) KS_SO, "\033[1;7m"}, {(int) KS_ME, "\033[m"}, {(int) KS_MR, "\033[7m"}, {(int) KS_MD, "\033[1m"}, {(int) KS_CCO, "8"}, {(int) KS_CZH, "\033[3m"}, {(int) KS_CZR, "\033[23m"}, {(int) KS_US, "\033[4m"}, {(int) KS_UE, "\033[24m"}, {(int) KS_CAB, "\033[4%p1%dm"}, {(int) KS_CAF, "\033[3%p1%dm"}, {(int) KS_CSB, "\033[102;%p1%dm"}, {(int) KS_CSF, "\033[101;%p1%dm"}, {(int) KS_MS, "y"}, {(int) KS_UT, "y"}, {(int) KS_LE, "\b"}, {(int) KS_CM, "\033[%i%p1%d;%p2%dH"}, {(int) KS_SR, "\033M"}, {(int) KS_CRI, "\033[%p1%dC"}, {(int) KS_CIS, "\033P3.y"}, {(int) KS_CIE, "\234"}, {(int) KS_TS, "\033P1.y"}, {(int) KS_FS, "\234"}, {(int) KS_CWS, "\033[203;%p1%d;%p2%d/y"}, {(int) KS_CWP, "\033[205;%p1%d;%p2%d/y"}, {K_UP, "\033[A"}, {K_DOWN, "\033[B"}, {K_LEFT, "\033[D"}, {K_RIGHT, "\033[C"}, {K_S_UP, "\033[161q"}, {K_S_DOWN, "\033[164q"}, {K_S_LEFT, "\033[158q"}, {K_S_RIGHT, "\033[167q"}, {K_F1, "\033[001q"}, {K_F2, "\033[002q"}, {K_F3, "\033[003q"}, {K_F4, "\033[004q"}, {K_F5, "\033[005q"}, {K_F6, "\033[006q"}, {K_F7, "\033[007q"}, {K_F8, "\033[008q"}, {K_F9, "\033[009q"}, {K_F10, "\033[010q"}, {K_F11, "\033[011q"}, {K_F12, "\033[012q"}, {K_S_F1, "\033[013q"}, {K_S_F2, "\033[014q"}, {K_S_F3, "\033[015q"}, {K_S_F4, "\033[016q"}, {K_S_F5, "\033[017q"}, {K_S_F6, "\033[018q"}, {K_S_F7, "\033[019q"}, {K_S_F8, "\033[020q"}, {K_S_F9, "\033[021q"}, {K_S_F10, "\033[022q"}, {K_S_F11, "\033[023q"}, {K_S_F12, "\033[024q"}, {K_INS, "\033[139q"}, {K_HOME, "\033[H"}, {K_END, "\033[146q"}, {K_PAGEUP, "\033[150q"}, {K_PAGEDOWN, "\033[154q"}, {(int) KS_NAME, "dumb"}, {(int) KS_CL, "\014"}, {(int) KS_CM, IF_EB ("\033[%i%p1%d;%p2%dH", ESC_STR "[%i%p1%d;%p2%dH")}, {(int) KS_NAME, NULL}};
int detected_8bit = FALSE;
EXTERN time_T starttime;
EXTERN FILE *time_fd INIT (= NULL);

void add_long_to_buf (long_u val, char_u *dst) {
    int i;
    int shift;
    for (i = 1; i <= (int) sizeof (long_u); i++) {
        shift = 8 * (sizeof (long_u) - i);
        dst[i - 1] = (char_u) ((val >> shift) & 0xff);
    }
}

int add_termcap_entry (char_u *name, int force) {
    char_u *term;
    int key;
    struct builtin_term *termp;
    if (gui.in_use || gui.starting)
        return gui_mch_haskey (name);
    if (!force && find_termcode (name) != NULL)
        return OK;
    term = T_NAME;
    if (term == NULL || *term == NUL)
        return FAIL;
    if (term_is_builtin (term)) {
        term += 8;
    }
    {
        termp = find_builtin_term (term);
        if (termp->bt_string != NULL) {
            key = TERMCAP2KEY (name[0], name[1]);
            while (termp->bt_entry != (int) KS_NAME) {
                if ((int) termp->bt_entry == key) {
                    add_termcode (name, (char_u *) termp -> bt_string, term_is_8bit (term));
                    return OK;
                }
                ++termp;
            }
        }
    }
    if (sourcing_name == NULL) {
        EMSG2 (_ ("E436: No \"%s\" entry in termcap"), name);
    }
    return FAIL;
}

char_u *find_termcode (char_u *name) {
    int i;
    for (i = 0; i < tc_len; ++i)
        if (termcodes[i].name[0] == name[0] && termcodes[i].name[1] == name[1])
            return termcodes[i].code;
    return NULL;
}

static int term_is_builtin (char_u *name) {
    return (STRNCMP (name, "builtin_", (size_t) 8) == 0);
}

static struct builtin_term *find_builtin_term (char_u *term) {
    struct builtin_term *p;
    p = builtin_termcaps;
    while (p->bt_string != NULL) {
        if (p->bt_entry == (int) KS_NAME) {
            if (STRCMP (p->bt_string, "iris-ansi") == 0 && vim_is_iris (term))
                return p;
            else if (STRCMP (p->bt_string, "xterm") == 0 && vim_is_xterm (term))
                return p;
            else if (STRCMP (term, p->bt_string) == 0)
                return p;
        }
        ++p;
    }
    return p;
}

void add_termcode (char_u *name, char_u *string, int flags) {
    struct termcode *new_tc;
    int i, j;
    char_u *s;
    int len;
    if (string == NULL || *string == NUL) {
        del_termcode (name);
        return;
    }
    s = vim_strsave (string);
    if (s == NULL)
        return;
    if (flags != 0 && flags != ATC_FROM_TERM && term_7to8bit (string) != 0) {
        STRMOVE (s, s + 1);
        s[0] = term_7to8bit (string);
    }
    len = (int) STRLEN (s);
    need_gather = TRUE;
    if (tc_len == tc_max_len) {
        tc_max_len += 20;
        new_tc = (struct termcode *) alloc ((unsigned ) (tc_max_len * sizeof (struct termcode)));
        if (new_tc == NULL) {
            tc_max_len -= 20;
            return;
        }
        for (i = 0; i < tc_len; ++i)
            new_tc[i] = termcodes[i];
        vim_free (termcodes);
        termcodes = new_tc;
    }
    for (i = 0; i < tc_len; ++i) {
        if (termcodes[i].name[0] < name[0])
            continue;
        if (termcodes[i].name[0] == name[0]) {
            if (termcodes[i].name[1] < name[1])
                continue;
            if (termcodes[i].name[1] == name[1]) {
                if (flags == ATC_FROM_TERM && (j = termcode_star (termcodes[i].code, termcodes[i].len)) > 0) {
                    if (len == termcodes[i].len - j && STRNCMP (s, termcodes[i].code, len -1) == 0 && s[len - 1] == termcodes[i].code[termcodes[i].len - 1]) {
                        vim_free (s);
                        return;
                    }
                }
                else {
                    vim_free (termcodes [i].code);
                    --tc_len;
                    break;
                }
            }
        }
        for (j = tc_len; j > i; --j)
            termcodes[j] = termcodes[j - 1];
        break;
    }
    termcodes[i].name[0] = name[0];
    termcodes[i].name[1] = name[1];
    termcodes[i].code = s;
    termcodes[i].len = len;
    termcodes[i].modlen = 0;
    j = termcode_star (s, len);
    if (j > 0)
        termcodes[i].modlen = len - 1 - j;
    ++tc_len;
}

void del_termcode (char_u *name) {
    int i;
    if (termcodes == NULL)
        return;
    need_gather = TRUE;
    for (i = 0; i < tc_len; ++i)
        if (termcodes[i].name[0] == name[0] && termcodes[i].name[1] == name[1]) {
            del_termcode_idx (i);
            return;
        }
}

static void del_termcode_idx (int idx) {
    int i;
    vim_free (termcodes [idx].code);
    --tc_len;
    for (i = idx; i < tc_len; ++i)
        termcodes[i] = termcodes[i + 1];
}

static int term_7to8bit (char_u *p) {
    if (*p == ESC) {
        if (p[1] == '[')
            return CSI;
        if (p[1] == ']')
            return OSC;
        if (p[1] == 'O')
            return 0x8f;
    }
    return 0;
}

static int termcode_star (char_u *code, int len) {
    if (len >= 3 && code[len - 2] == '*') {
        if (len >= 5 && code[len - 3] == ';')
            return 2;
        else
            return 1;
    }
    return 0;
}

int term_is_8bit (char_u *name) {
    return (detected_8bit || strstr ((char *) name, "8bit") != NULL);
}

void win_new_shellsize (void) {
    static int old_Rows = 0;
    static int old_Columns = 0;
    if (old_Rows != Rows || old_Columns != Columns)
        ui_new_shellsize ();
    if (old_Rows != Rows) {
        if (p_window == old_Rows - 1 || old_Rows == 0)
            p_window = Rows - 1;
        old_Rows = Rows;
        shell_new_rows ();
    }
    if (old_Columns != Columns) {
        old_Columns = Columns;
        shell_new_columns ();
    }
}

void out_char (unsigned  c) {
    if (c == '\n')
        out_char ('\r');
    out_buf[out_pos++] = c;
    if (out_pos >= OUT_SIZE || p_wd)
        out_flush ();
}

void out_flush (void) {
    int len;
    if (out_pos != 0) {
        len = out_pos;
        out_pos = 0;
        ui_write (out_buf, len);
    }
}

void out_str (char_u *s) {
    if (s != NULL && *s) {
        if (gui.in_use) {
            out_str_nf (s);
            return;
        }
        if (out_pos > OUT_SIZE - 20)
            out_flush ();
        while (*s)
            out_char_nf (*s++);
        if (p_wd)
            out_flush ();
    }
}

void out_str_nf (char_u *s) {
    if (out_pos > OUT_SIZE - 20)
        out_flush ();
    while (*s)
        out_char_nf (*s++);
    if (p_wd)
        out_flush ();
}

static void out_char_nf (unsigned  c) {
    if (c == '\n')
        out_char_nf ('\r');
    out_buf[out_pos++] = c;
    if (out_pos >= OUT_SIZE)
        out_flush ();
}

void term_fg_rgb_color (guicolor_T rgb) {
    term_rgb_color (T_8F, rgb);
}

static void term_rgb_color (char_u *s, guicolor_T rgb) {

    #define MAX_COLOR_STR_LEN 100
    char buf [MAX_COLOR_STR_LEN];
    vim_snprintf (buf, MAX_COLOR_STR_LEN, (char *) s, RED (rgb), GREEN (rgb), BLUE (rgb));
    OUT_STR (buf);
}

void term_bg_rgb_color (guicolor_T rgb) {
    term_rgb_color (T_8B, rgb);
}

void term_fg_color (int n) {
    if (*T_CAF)
        term_color (T_CAF, n);
    else if (*T_CSF)
        term_color (T_CSF, n);
}

static void term_color (char_u *s, int n) {
    char buf [20];
    int i = 2;
    if (n >= 8 && t_colors >= 16 && ((s[0] == ESC && s[1] == '[') || (s[0] == CSI && (i = 1) == 1)) && s[i] != NUL && (STRCMP (s +i + 1, "%p1%dm") == 0 || STRCMP (s +i + 1, "%dm") == 0) && (s[i] == '3' || s[i] == '4')) {
        char *format = "%s%s%%p1%%dm";
        sprintf (buf, format, i == 2 ? IF_EB ("\033[", ESC_STR "[") : "\233", s [i] == '3' ? (n >= 16 ? "38;5;" : "9") : (n >= 16 ? "48;5;" : "10"));
        OUT_STR (tgoto (buf, 0, n >= 16 ? n : n - 8));
    }
    else
        OUT_STR (tgoto ((char *) s, 0, n));
}

#define RED(rgb)   (((long_u)(rgb) >> 16) & 0xFF)

#define GREEN(rgb) (((long_u)(rgb) >>  8) & 0xFF)

#define BLUE(rgb)  (((long_u)(rgb)      ) & 0xFF)

static char *tgoto (char *cm, int x, int y) {
    static char buf [30];
    char *p, *s, *e;
    if (!cm)
        return "OOPS";
    e = buf + 29;
    for (s = buf; s < e && *cm; cm++) {
        if (*cm != '%') {
            *s++ = *cm;
            continue;
        }
        switch (*++cm) {
        case 'd' :
            p = (char *) tltoa ((unsigned  long ) y);
            y = x;
            while (*p)
                *s++ = *p++;
            break;
        case 'i' :
            x++;
            y++;
            break;
        case '+' :
            *s++ = (char) (*++cm + y);
            y = x;
            break;
        case '%' :
            *s++ = *cm;
            break;
        default :
            return "OOPS";
        }
    }
    *s = '\0';
    return buf;
}

void term_bg_color (int n) {
    if (*T_CAB)
        term_color (T_CAB, n);
    else if (*T_CSB)
        term_color (T_CSB, n);
}

void term_cursor_right (int i) {
    OUT_STR (tgoto ((char *) T_CRI, 0, i));
}

void term_windgoto (int row, int col) {
    OUT_STR (tgoto ((char *) T_CM, col, row));
}

void shell_resized (void) {
    set_shellsize (0, 0, FALSE);
}

void set_shellsize (int width, int height, int mustset) {
    static int busy = FALSE;
    if (busy)
        return;
    if (width < 0 || height < 0)
        return;
    if (State == HITRETURN || State == SETWSIZE) {
        State = SETWSIZE;
        return;
    }
    if (curwin->w_buffer == NULL)
        return;
    ++busy;
    if (mustset || (ui_get_shellsize () == FAIL && height != 0)) {
        Rows = height;
        Columns = width;
        check_shellsize ();
        ui_set_shellsize (mustset);
    }
    else
        check_shellsize ();
    if (State != ASKMORE && State != EXTERNCMD && State != CONFIRM)
        screenclear ();
    else
        screen_start ();
    if (starting != NO_SCREEN) {
        maketitle ();
        changed_line_abv_curs ();
        invalidate_botline ();
        if (State == ASKMORE || State == EXTERNCMD || State == CONFIRM || exmode_active) {
            screenalloc (FALSE);
            repeat_message ();
        }
        else {
            if (curwin->w_p_scb)
                do_check_scrollbind (TRUE);
            if (State & CMDLINE) {
                update_screen (NOT_VALID);
                redrawcmdline ();
            }
            else {
                update_topline ();
                if (pum_visible ()) {
                    redraw_later (NOT_VALID);
                    ins_compl_show_pum ();
                }
                update_screen (NOT_VALID);
                if (redrawing ())
                    setcursor ();
            }
        }
        cursor_on ();
    }
    out_flush ();
    --busy;
}

void check_shellsize (void) {
    if (Rows < min_rows ())
        Rows = min_rows ();
    limit_screen_size ();
}

void limit_screen_size (void) {
    if (Columns < MIN_COLUMNS)
        Columns = MIN_COLUMNS;
    else if (Columns > 10000)
        Columns = 10000;
    if (Rows > 1000)
        Rows = 1000;
}

void cursor_on (void) {
    if (cursor_is_off) {
        out_str (T_VE);
        cursor_is_off = FALSE;
    }
}

void out_flush_cursor (int force UNUSED, int clear_selection UNUSED) {
    mch_disable_flush ();
    out_flush ();
    mch_enable_flush ();
    if (gui.in_use) {
        gui_update_cursor (force, clear_selection);
        gui_may_flush ();
    }
}

void term_delete_lines (int line_count) {
    OUT_STR (tgoto ((char *) T_CDL, 0, line_count));
}

void term_append_lines (int line_count) {
    OUT_STR (tgoto ((char *) T_CAL, 0, line_count));
}

void settmode (int tmode) {
    if (gui.in_use)
        return;
    if (full_screen) {
        if (tmode != TMODE_COOK || cur_tmode != TMODE_COOK) {
            if (!gui.in_use && !gui.starting) {
                if (tmode != TMODE_RAW && (crv_status == STATUS_SENT || u7_status == STATUS_SENT || rfg_status == STATUS_SENT || rbg_status == STATUS_SENT || rbm_status == STATUS_SENT || rcs_status == STATUS_SENT))
                    (void) vpeekc_nomap ();
                check_for_codes_from_term ();
            }
            if (tmode != TMODE_RAW)
                out_str (T_BD);
            out_flush ();
            mch_settmode (tmode);
            cur_tmode = tmode;
            if (tmode == TMODE_RAW)
                setmouse ();
            if (tmode == TMODE_RAW)
                out_str (T_BE);
            out_flush ();
        }
        may_req_termresponse ();
    }
}

static void check_for_codes_from_term (void) {
    int c;
    if (xt_index_out == 0 || xt_index_out == xt_index_in)
        return;
    ++no_mapping;
    ++allow_keys;
    for (;;) {
        c = vpeekc ();
        if (c == NUL)
            break;
        if (c != K_SPECIAL && c != K_IGNORE)
            break;
        c = vgetc ();
        if (c != K_IGNORE) {
            vungetc (c);
            break;
        }
    }
    --no_mapping;
    --allow_keys;
}

void setmouse (void) {
    update_mouseshape (- 1);
}

int mouse_has (int c) {
    char_u *p;
    for (p = p_mouse; *p; ++p)
        switch (*p) {
        case 'a' :
            if (vim_strchr ((char_u *) MOUSE_A, c) != NULL)
                return TRUE;
            break;
        case MOUSE_HELP :
            if (c != MOUSE_RETURN && curbuf->b_help)
                return TRUE;
            break;
        default :
            if (c == *p)
                return TRUE;
            break;
        }
    return FALSE;
}

void cursor_off (void) {
    if (full_screen && !cursor_is_off) {
        out_str (T_VI);
        cursor_is_off = TRUE;
    }
}

void out_str_cf (char_u *s) {
    if (s != NULL && *s) {
        if (gui.in_use) {
            out_str_nf (s);
            return;
        }
        if (out_pos > OUT_SIZE - 20)
            out_flush ();
        while (*s)
            out_char_nf (*s++);
        if (p_wd)
            out_flush ();
    }
}

void out_trash (void) {
    out_pos = 0;
}

void stoptermcap (void) {
    screen_stop_highlight ();
    reset_cterm_colors ();
    if (termcap_active) {
        if (!gui.in_use && !gui.starting) {
            if (crv_status == STATUS_SENT || u7_status == STATUS_SENT || rfg_status == STATUS_SENT || rbg_status == STATUS_SENT || rbm_status == STATUS_SENT || rcs_status == STATUS_SENT) {
                mch_delay (100L, FALSE);
            }
            check_for_codes_from_term ();
        }
        out_str (T_BD);
        out_str (T_KE);
        out_flush ();
        termcap_active = FALSE;
        cursor_on ();
        out_str (T_TE);
        screen_start ();
        out_flush ();
    }
}

int check_termcode (int max_offset, char_u *buf, int bufsize, int *buflen) {
    char_u *tp;
    char_u *p;
    int slen = 0;
    int modslen;
    int len;
    int retval = 0;
    int offset;
    char_u key_name [2];
    int modifiers;
    char_u *modifiers_start = NULL;
    int key;
    int new_slen;
    int extra;
    char_u string [MAX_KEY_CODE_LEN + 1];
    int i, j;
    int idx = 0;
    char_u bytes [6];
    int num_bytes;
    int mouse_code = 0;
    int is_click, is_drag;
    int wheel_code = 0;
    int current_button;
    static int held_button = MOUSE_RELEASE;
    static int orig_num_clicks = 1;
    static int orig_mouse_code = 0x0;
    int cpo_koffset;
    cpo_koffset = (vim_strchr (p_cpo, CPO_KOFFSET) != NULL);
    if (need_gather)
        gather_termleader ();
    for (offset = 0; offset < max_offset; ++offset) {
        if (buf == NULL) {
            if (offset >= typebuf.tb_len)
                break;
            tp = typebuf.tb_buf + typebuf.tb_off + offset;
            len = typebuf.tb_len - offset;
        }
        else {
            if (offset >= *buflen)
                break;
            tp = buf + offset;
            len = *buflen - offset;
        }
        if (*tp == K_SPECIAL) {
            offset += 2;
            continue;
        }
        i = *tp;
        for (p = termleader; *p && *p != i; ++p)
            ;
        if (*p == NUL)
            continue;
        if (*tp == ESC && !p_ek && (State & INSERT))
            continue;
        key_name[0] = NUL;
        key_name[1] = NUL;
        modifiers = 0;
        if (gui.in_use) {
            if (*tp == CSI) {
                if (len < 3)
                    return -1;
                slen = 3;
                key_name[0] = tp[1];
                key_name[1] = tp[2];
            }
        }
        else {
            for (idx = 0; idx < tc_len; ++idx) {
                slen = termcodes[idx].len;
                modifiers_start = NULL;
                if (cpo_koffset && offset && len < slen)
                    continue;
                if (STRNCMP (termcodes[idx].code, tp, (size_t) (slen > len ? len : slen)) == 0) {
                    if (len < slen)
                        return -1;
                    if (termcodes[idx].name[0] == 'K' && VIM_ISDIGIT (termcodes[idx].name[1])) {
                        for (j = idx + 1; j < tc_len; ++j)
                            if (termcodes[j].len == slen && STRNCMP (termcodes[idx].code, termcodes[j].code, slen) == 0) {
                                idx = j;
                                break;
                            }
                    }
                    key_name[0] = termcodes[idx].name[0];
                    key_name[1] = termcodes[idx].name[1];
                    break;
                }
                if (termcodes[idx].modlen > 0) {
                    modslen = termcodes[idx].modlen;
                    if (cpo_koffset && offset && len < modslen)
                        continue;
                    if (STRNCMP (termcodes[idx].code, tp, (size_t) (modslen > len ? len : modslen)) == 0) {
                        int n;
                        if (len <= modslen)
                            return -1;
                        if (tp[modslen] == termcodes[idx].code[slen - 1])
                            slen = modslen + 1;
                        else if (tp[modslen] != ';' && modslen == slen - 3)
                            continue;
                        else {
                            for (j = slen - 2; j < len && (isdigit (tp[j]) || tp[j] == ';'); ++j)
                                ;
                            ++j;
                            if (len < j)
                                return -1;
                            if (tp[j - 1] != termcodes[idx].code[slen - 1])
                                continue;
                            modifiers_start = tp + slen - 2;
                            n = atoi ((char *) modifiers_start) - 1;
                            if (n & 1)
                                modifiers |= MOD_MASK_SHIFT;
                            if (n & 2)
                                modifiers |= MOD_MASK_ALT;
                            if (n & 4)
                                modifiers |= MOD_MASK_CTRL;
                            if (n & 8)
                                modifiers |= MOD_MASK_META;
                            slen = j;
                        }
                        key_name[0] = termcodes[idx].name[0];
                        key_name[1] = termcodes[idx].name[1];
                        break;
                    }
                }
            }
        }
        if (key_name[0] == NUL || key_name[0] == KS_DEC_MOUSE) {
            char_u *argp = tp[0] == ESC ? tp + 2 : tp + 1;
            if ((*T_CRV != NUL || *T_U7 != NUL || waiting_for_winpos) && ((tp[0] == ESC && len >= 3 && tp[1] == '[') || (tp[0] == CSI && len >= 2)) && (VIM_ISDIGIT (*argp) || *argp == '>' || *argp == '?')) {
                int col = 0;
                int semicols = 0;
                extra = 0;
                for (i = 2 + (tp[0] != CSI); i < len && !(tp[i] >= '{' && tp[i] <= '~') && !ASCII_ISALPHA (tp[i]); ++i)
                    if (tp[i] == ';' && ++semicols == 1) {
                        extra = i + 1;
                    }
                if (i == len) {
                    LOG_TR ("Not enough characters for CRV");
                    return -1;
                }
                if (extra > 0)
                    col = atoi ((char *) tp + extra);
                if (*T_CRV != NUL && i > 2 + (tp[0] != CSI) && tp[i] == 'c') {
                    int version = col;
                    LOG_TR ("Received CRV response");
                    crv_status = STATUS_GOT;
                    did_cursorhold = TRUE;
                    if (tp[0] == CSI)
                        switch_to_8bit ();
                    if (version > 20000)
                        version = 0;
                    if (tp[1 + (tp[0] != CSI)] == '>' && semicols == 2) {
                        int need_flush = FALSE;
                        int is_iterm2 = FALSE;
                        if (version >= 141) {
                            LOG_TR ("Enable checking for XT codes");
                            check_for_codes = TRUE;
                            need_gather = TRUE;
                            req_codes_from_term ();
                        }
                        if (version == 100 && STRNCMP (tp +extra - 2, "0;100;0c", 8) == 0) {
                            if (mch_getenv ((char_u *) "COLORS") == NULL)
                                may_adjust_color_count (256);
                            if (!option_was_set ((char_u *) "ttym"))
                                set_option_value ((char_u *) "ttym", 0L, (char_u *) "sgr", 0);
                        }
                        if (version == 95) {
                            if (STRNCMP (tp +extra - 2, "1;95;0c", 7) == 0) {
                                is_not_xterm = TRUE;
                                is_mac_terminal = TRUE;
                            }
                            if (STRNCMP (tp +extra - 2, "0;95;0c", 7) == 0)
                                is_iterm2 = TRUE;
                        }
                        if (!option_was_set ((char_u *) "ttym")) {
                            if (version >= 277 || is_iterm2 || is_mac_terminal)
                                set_option_value ((char_u *) "ttym", 0L, (char_u *) "sgr", 0);
                            else if (version >= 95)
                                set_option_value ((char_u *) "ttym", 0L, (char_u *) "xterm2", 0);
                        }
                        if (col >= 2500)
                            is_not_xterm = TRUE;
                        if (version == 136 && STRNCMP (tp +extra - 1, ";136;0c", 7) == 0)
                            is_not_xterm = TRUE;
                        if (version == 115 && STRNCMP (tp +extra - 2, "0;115;0c", 8) == 0)
                            is_not_xterm = TRUE;
                        if (rcs_status == STATUS_GET && version >= 279 && !is_not_xterm && *T_CSH != NUL && *T_CRS != NUL) {
                            LOG_TR ("Sending cursor style request");
                            out_str (T_CRS);
                            rcs_status = STATUS_SENT;
                            need_flush = TRUE;
                        }
                        if (rbm_status == STATUS_GET && !is_not_xterm && *T_CRC != NUL) {
                            LOG_TR ("Sending cursor blink mode request");
                            out_str (T_CRC);
                            rbm_status = STATUS_SENT;
                            need_flush = TRUE;
                        }
                        if (need_flush)
                            out_flush ();
                    }
                    slen = i + 1;
                    set_vim_var_string (VV_TERMRESPONSE, tp, slen);
                    apply_autocmds (EVENT_TERMRESPONSE, NULL, NULL, FALSE, curbuf);
                    key_name[0] = (int) KS_EXTRA;
                    key_name[1] = (int) KE_IGNORE;
                }
                else if (rbm_status == STATUS_SENT && tp[(j = 1 + (tp[0] == ESC))] == '?' && i == j + 6 && tp[j + 1] == '1' && tp[j + 2] == '2' && tp[j + 3] == ';' && tp[i - 1] == '$' && tp[i] == 'y') {
                    initial_cursor_blink = (tp[j + 4] == '1');
                    rbm_status = STATUS_GOT;
                    LOG_TR ("Received cursor blinking mode response");
                    key_name[0] = (int) KS_EXTRA;
                    key_name[1] = (int) KE_IGNORE;
                    slen = i + 1;
                    set_vim_var_string (VV_TERMBLINKRESP, tp, slen);
                }
                else if (waiting_for_winpos && ((len >= 4 && tp[0] == ESC && tp[1] == '[') || (len >= 3 && tp[0] == CSI)) && tp[(j = 1 + (tp[0] == ESC))] == '3' && tp[j + 1] == ';') {
                    j += 2;
                    for (i = j; i < len && vim_isdigit (tp[i]); ++i)
                        ;
                    if (i < len && tp[i] == ';') {
                        winpos_x = atoi ((char *) tp + j);
                        j = i + 1;
                        for (i = j; i < len && vim_isdigit (tp[i]); ++i)
                            ;
                        if (i < len && tp[i] == 't') {
                            winpos_y = atoi ((char *) tp + j);
                            key_name[0] = (int) KS_EXTRA;
                            key_name[1] = (int) KE_IGNORE;
                            slen = i + 1;
                        }
                    }
                    if (i == len) {
                        LOG_TR ("not enough characters for winpos");
                        return -1;
                    }
                }
            }
            else if ((*T_RBG != NUL || *T_RFG != NUL) && ((tp[0] == ESC && len >= 2 && tp[1] == ']') || tp[0] == OSC)) {
                j = 1 + (tp[0] == ESC);
                if (len >= j + 3 && (argp[0] != '1' || (argp[1] != '1' && argp[1] != '0') || argp[2] != ';'))
                    i = 0;
                else
                    for (i = j; i < len; ++i)
                        if (tp[i] == '\007' || (tp[0] == OSC ? tp[i] == STERM : (tp[i] == ESC && i + 1 < len && tp[i + 1] == '\\'))) {
                            int is_bg = argp[1] == '1';
                            if (i - j >= 21 && STRNCMP (tp +j + 3, "rgb:", 4) == 0 && tp[j + 11] == '/' && tp[j + 16] == '/') {
                                int rval = hexhex2nr (tp +j + 7);
                                int gval = hexhex2nr (tp +j + 12);
                                int bval = hexhex2nr (tp +j + 17);
                                if (is_bg) {
                                    char *newval = (3 * '6' < tp[j + 7] + tp[j + 12] + tp[j + 17]) ? "light" : "dark";
                                    LOG_TR ("Received RBG response");
                                    rbg_status = STATUS_GOT;
                                    bg_r = rval;
                                    bg_g = gval;
                                    bg_b = bval;
                                    if (!option_was_set ((char_u *) "bg") && STRCMP (p_bg, newval) != 0) {
                                        set_option_value ((char_u *) "bg", 0L, (char_u *) newval, 0);
                                        reset_option_was_set ((char_u *) "bg");
                                        redraw_asap (CLEAR);
                                    }
                                }
                                else {
                                    LOG_TR ("Received RFG response");
                                    rfg_status = STATUS_GOT;
                                    fg_r = rval;
                                    fg_g = gval;
                                    fg_b = bval;
                                }
                            }
                            key_name[0] = (int) KS_EXTRA;
                            key_name[1] = (int) KE_IGNORE;
                            slen = i + 1 + (tp[i] == ESC);
                            set_vim_var_string (is_bg ? VV_TERMRBGRESP : VV_TERMRFGRESP, tp, slen);
                            break;
                        }
                if (i == len) {
                    LOG_TR ("not enough characters for RB");
                    return -1;
                }
            }
            else if ((check_for_codes || rcs_status == STATUS_SENT) && ((tp[0] == ESC && len >= 2 && tp[1] == 'P') || tp[0] == DCS)) {
                j = 1 + (tp[0] == ESC);
                if (len < j + 3)
                    i = len;
                else if ((argp[1] != '+' && argp[1] != '$') || argp[2] != 'r')
                    i = 0;
                else if (argp[1] == '+')
                    for (i = j; i < len; ++i) {
                        if ((tp[i] == ESC && i + 1 < len && tp[i + 1] == '\\') || tp[i] == STERM) {
                            if (i - j >= 3)
                                got_code_from_term (tp +j, i);
                            key_name[0] = (int) KS_EXTRA;
                            key_name[1] = (int) KE_IGNORE;
                            slen = i + 1 + (tp[i] == ESC);
                            break;
                        }
                    }
                else if ((len >= j + 6 && isdigit (argp[3])) && argp[4] == ' ' && argp[5] == 'q') {
                    i = j + 6;
                    if ((tp[i] == ESC && i + 1 < len && tp[i + 1] == '\\') || tp[i] == STERM) {
                        int number = argp[3] - '0';
                        number = number == 0 ? 1 : number;
                        initial_cursor_shape = (number + 1) / 2;
                        initial_cursor_shape_blink = (number & 1) ? FALSE : TRUE;
                        rcs_status = STATUS_GOT;
                        LOG_TR ("Received cursor shape response");
                        key_name[0] = (int) KS_EXTRA;
                        key_name[1] = (int) KE_IGNORE;
                        slen = i + 1 + (tp[i] == ESC);
                        set_vim_var_string (VV_TERMSTYLERESP, tp, slen);
                    }
                }
                if (i == len) {
                    LOG_TR ("not enough characters for XT");
                    return -1;
                }
            }
        }
        if (key_name[0] == NUL)
            continue;
        if (gui.in_use && key_name[0] == (int) KS_EXTRA && (key_name[1] == (int) KE_X1MOUSE || key_name[1] == (int) KE_X2MOUSE || key_name[1] == (int) KE_MOUSELEFT || key_name[1] == (int) KE_MOUSERIGHT || key_name[1] == (int) KE_MOUSEDOWN || key_name[1] == (int) KE_MOUSEUP)) {
            num_bytes = get_bytes_from_buf (tp +slen, bytes, 4);
            if (num_bytes == -1)
                return -1;
            mouse_col = 128 * (bytes[0] - ' ' - 1) + bytes[1] - ' ' - 1;
            mouse_row = 128 * (bytes[2] - ' ' - 1) + bytes[3] - ' ' - 1;
            slen += num_bytes;
        }
        else if (key_name[0] == KS_MOUSE || key_name[0] == KS_NETTERM_MOUSE || key_name[0] == KS_DEC_MOUSE || key_name[0] == KS_URXVT_MOUSE || key_name[0] == KS_SGR_MOUSE || key_name[0] == KS_SGR_MOUSE_RELEASE) {
            is_click = is_drag = FALSE;
            if (key_name[0] == (int) KS_MOUSE) {
                for (;;) {
                    if (gui.in_use) {
                        num_bytes = get_bytes_from_buf (tp +slen, bytes, 5);
                        if (num_bytes == -1)
                            return -1;
                        mouse_code = bytes[0];
                        mouse_col = 128 * (bytes[1] - ' ' - 1) + bytes[2] - ' ' - 1;
                        mouse_row = 128 * (bytes[3] - ' ' - 1) + bytes[4] - ' ' - 1;
                    }
                    else {
                        num_bytes = get_bytes_from_buf (tp +slen, bytes, 3);
                        if (num_bytes == -1)
                            return -1;
                        mouse_code = bytes[0];
                        mouse_col = bytes[1] - ' ' - 1;
                        mouse_row = bytes[2] - ' ' - 1;
                    }
                    slen += num_bytes;
                    if (gui.in_use)
                        j = 3;
                    else
                        j = termcodes[idx].len;
                    if (STRNCMP (tp, tp +slen, (size_t) j) == 0 && tp[slen + j] == mouse_code && tp[slen + j + 1] != NUL && tp[slen + j + 2] != NUL && (!gui.in_use || (tp[slen + j + 3] != NUL && tp[slen + j + 4] != NUL)))
                        slen += j;
                    else
                        break;
                }
            }
            if (key_name[0] == KS_URXVT_MOUSE || key_name[0] == KS_SGR_MOUSE || key_name[0] == KS_SGR_MOUSE_RELEASE) {
                p = modifiers_start;
                if (p == NULL)
                    return -1;
                mouse_code = getdigits (&p);
                if (*p++ != ';')
                    return -1;
                if (key_name[0] == KS_SGR_MOUSE || key_name[0] == KS_SGR_MOUSE_RELEASE)
                    mouse_code += 32;
                if (key_name[0] == KS_SGR_MOUSE_RELEASE)
                    mouse_code |= MOUSE_RELEASE;
                mouse_col = getdigits (&p) - 1;
                if (*p++ != ';')
                    return -1;
                mouse_row = getdigits (&p) - 1;
                modifiers = 0;
            }
            if (key_name[0] == (int) KS_MOUSE || key_name[0] == (int) KS_URXVT_MOUSE || key_name[0] == KS_SGR_MOUSE || key_name[0] == KS_SGR_MOUSE_RELEASE) {
                if (mouse_code >= MOUSEWHEEL_LOW && !gui.in_use) {
                    wheel_code = mouse_code;
                }
                else if (held_button == MOUSE_RELEASE && !gui.in_use && (mouse_code == 0x23 || mouse_code == 0x24)) {
                    wheel_code = mouse_code - 0x23 + MOUSEWHEEL_LOW;
                }
            }
            if (key_name[0] == (int) KS_NETTERM_MOUSE) {
                int mc, mr;
                p = tp + slen;
                mr = getdigits (&p);
                if (*p++ != ',')
                    return -1;
                mc = getdigits (&p);
                if (*p++ != '\r')
                    return -1;
                mouse_col = mc - 1;
                mouse_row = mr - 1;
                mouse_code = MOUSE_LEFT;
                slen += (int) (p - (tp + slen));
            }
            if (key_name[0] == (int) KS_DEC_MOUSE) {
                int Pe, Pb, Pr, Pc;
                p = tp + slen;
                Pe = getdigits (&p);
                if (*p++ != ';')
                    return -1;
                Pb = getdigits (&p);
                if (*p++ != ';')
                    return -1;
                Pr = getdigits (&p);
                if (*p++ != ';')
                    return -1;
                Pc = getdigits (&p);
                if (*p == ';') {
                    p++;
                    (void) getdigits (&p);
                }
                if (*p++ != '&')
                    return -1;
                if (*p++ != 'w')
                    return -1;
                mouse_code = 0;
                switch (Pe) {
                case 0 :
                    return -1;
                case 1 :
                    Pb &= 7;
                    if (Pb & 4)
                        mouse_code = MOUSE_LEFT;
                    if (Pb & 2)
                        mouse_code = MOUSE_MIDDLE;
                    if (Pb & 1)
                        mouse_code = MOUSE_RIGHT;
                    if (Pb) {
                        held_button = mouse_code;
                        mouse_code |= MOUSE_DRAG;
                        WantQueryMouse = TRUE;
                    }
                    is_drag = TRUE;
                    showmode ();
                    break;
                case 2 :
                    mouse_code = MOUSE_LEFT;
                    WantQueryMouse = TRUE;
                    break;
                case 3 :
                    mouse_code = MOUSE_RELEASE | MOUSE_LEFT;
                    break;
                case 4 :
                    mouse_code = MOUSE_MIDDLE;
                    WantQueryMouse = TRUE;
                    break;
                case 5 :
                    mouse_code = MOUSE_RELEASE | MOUSE_MIDDLE;
                    break;
                case 6 :
                    mouse_code = MOUSE_RIGHT;
                    WantQueryMouse = TRUE;
                    break;
                case 7 :
                    mouse_code = MOUSE_RELEASE | MOUSE_RIGHT;
                    break;
                case 8 :
                    return -1;
                case 9 :
                    return -1;
                case 10 :
                    return -1;
                default :
                    return -1;
                }
                mouse_col = Pc - 1;
                mouse_row = Pr - 1;
                slen += (int) (p - (tp + slen));
            }
            current_button = (mouse_code & MOUSE_CLICK_MASK);
            if (current_button == MOUSE_RELEASE && wheel_code == 0) {
                if ((mouse_code & MOUSE_DRAG) == MOUSE_DRAG)
                    is_drag = TRUE;
                current_button = held_button;
            }
            else if (wheel_code == 0) {
                orig_num_clicks = NUM_MOUSE_CLICKS (mouse_code);
                is_click = TRUE;
                orig_mouse_code = mouse_code;
            }
            if (!is_drag)
                held_button = mouse_code & MOUSE_CLICK_MASK;
            if (orig_mouse_code & MOUSE_SHIFT)
                modifiers |= MOD_MASK_SHIFT;
            if (orig_mouse_code & MOUSE_CTRL)
                modifiers |= MOD_MASK_CTRL;
            if (orig_mouse_code & MOUSE_ALT)
                modifiers |= MOD_MASK_ALT;
            if (orig_num_clicks == 2)
                modifiers |= MOD_MASK_2CLICK;
            else if (orig_num_clicks == 3)
                modifiers |= MOD_MASK_3CLICK;
            else if (orig_num_clicks == 4)
                modifiers |= MOD_MASK_4CLICK;
            key_name[0] = (int) KS_EXTRA;
            if (wheel_code != 0 && (wheel_code & MOUSE_RELEASE) != MOUSE_RELEASE) {
                if (wheel_code & MOUSE_CTRL)
                    modifiers |= MOD_MASK_CTRL;
                if (wheel_code & MOUSE_ALT)
                    modifiers |= MOD_MASK_ALT;
                key_name[1] = (wheel_code & 1) ? (int) KE_MOUSEUP : (int) KE_MOUSEDOWN;
                held_button = MOUSE_RELEASE;
            }
            else
                key_name[1] = get_pseudo_mouse_code (current_button, is_click, is_drag);
            if (mouse_col >= Columns)
                mouse_col = Columns - 1;
            if (mouse_row >= Rows)
                mouse_row = Rows - 1;
        }
        else if (key_name[0] == (int) KS_MENU) {
            long_u val;
            num_bytes = get_long_from_buf (tp +slen, &val);
            if (num_bytes == -1)
                return -1;
            current_menu = (vimmenu_T *) val;
            slen += num_bytes;
            if (check_menu_pointer (root_menu, current_menu) == FAIL) {
                key_name[0] = KS_EXTRA;
                key_name[1] = (int) KE_IGNORE;
            }
        }
        else if (key_name[0] == (int) KS_VER_SCROLLBAR) {
            long_u val;
            j = 0;
            for (i = 0; tp[j] == CSI && tp[j + 1] == KS_VER_SCROLLBAR && tp[j + 2] != NUL; ++i) {
                j += 3;
                num_bytes = get_bytes_from_buf (tp +j, bytes, 1);
                if (num_bytes == -1)
                    break;
                if (i == 0)
                    current_scrollbar = (int) bytes[0];
                else if (current_scrollbar != (int) bytes[0])
                    break;
                j += num_bytes;
                num_bytes = get_long_from_buf (tp +j, &val);
                if (num_bytes == -1)
                    break;
                scrollbar_value = val;
                j += num_bytes;
                slen = j;
            }
            if (i == 0)
                return -1;
        }
        else if (key_name[0] == (int) KS_HOR_SCROLLBAR) {
            long_u val;
            j = 0;
            for (i = 0; tp[j] == CSI && tp[j + 1] == KS_HOR_SCROLLBAR && tp[j + 2] != NUL; ++i) {
                j += 3;
                num_bytes = get_long_from_buf (tp +j, &val);
                if (num_bytes == -1)
                    break;
                scrollbar_value = val;
                j += num_bytes;
                slen = j;
            }
            if (i == 0)
                return -1;
        }
        key = handle_x_keys (TERMCAP2KEY (key_name[0], key_name[1]));
        new_slen = 0;
        if (modifiers != 0) {
            key = simplify_key (key, &modifiers);
            if (modifiers != 0) {
                string[new_slen++] = K_SPECIAL;
                string[new_slen++] = (int) KS_MODIFIER;
                string[new_slen++] = modifiers;
            }
        }
        key_name[0] = KEY2TERMCAP0 (key);
        key_name[1] = KEY2TERMCAP1 (key);
        if (key_name[0] == KS_KEY) {
            string[new_slen++] = key_name[1];
        }
        else if (new_slen == 0 && key_name[0] == KS_EXTRA && key_name[1] == KE_IGNORE) {
            retval = KEYLEN_REMOVED;
        }
        else {
            string[new_slen++] = K_SPECIAL;
            string[new_slen++] = key_name[0];
            string[new_slen++] = key_name[1];
        }
        string[new_slen] = NUL;
        extra = new_slen - slen;
        if (buf == NULL) {
            if (extra < 0)
                del_typebuf (-extra, offset);
            else if (extra > 0)
                ins_typebuf (string +slen, REMAP_YES, offset, FALSE, FALSE);
            mch_memmove (typebuf.tb_buf + typebuf.tb_off + offset, string, (size_t) new_slen);
        }
        else {
            if (extra < 0)
                mch_memmove (buf +offset, buf +offset - extra, (size_t) (*buflen + offset + extra));
            else if (extra > 0) {
                if (*buflen + extra + new_slen >= bufsize)
                    return -1;
                mch_memmove (buf + offset + extra, buf + offset, (size_t) (* buflen - offset));
            }
            mch_memmove (buf + offset, string, (size_t) new_slen);
            *buflen = *buflen + extra + new_slen;
        }
        return retval == 0 ? (len + extra + offset) : retval;
    }
    LOG_TR ("normal character");
    return 0;
}

static void gather_termleader (void) {
    int i;
    int len = 0;
    if (gui.in_use)
        termleader[len++] = CSI;
    if (check_for_codes || *T_CRS != NUL)
        termleader[len++] = DCS;
    termleader[len] = NUL;
    for (i = 0; i < tc_len; ++i)
        if (vim_strchr (termleader, termcodes[i].code[0]) == NULL) {
            termleader[len++] = termcodes[i].code[0];
            termleader[len] = NUL;
        }
    need_gather = FALSE;
}

void ttest (int pairs) {
    char_u *env_colors;
    check_options ();
    if (*T_CM == NUL)
        EMSG (_ ("E437: terminal capability \"cm\" required"));
    if (*T_CS != NUL)
        scroll_region = TRUE;
    else
        scroll_region = FALSE;
    if (pairs) {
        if (*T_ME == NUL)
            T_ME = T_MR = T_MD = T_MB = empty_option;
        if (*T_SO == NUL || *T_SE == NUL)
            T_SO = T_SE = empty_option;
        if (*T_US == NUL || *T_UE == NUL)
            T_US = T_UE = empty_option;
        if (*T_CZH == NUL || *T_CZR == NUL)
            T_CZH = T_CZR = empty_option;
        if (*T_VE == NUL)
            T_VI = empty_option;
        if (*T_ME == NUL) {
            T_ME = T_SE;
            T_MR = T_SO;
            T_MD = T_SO;
        }
        if (*T_SO == NUL) {
            T_SE = T_ME;
            if (*T_MR == NUL)
                T_SO = T_MD;
            else
                T_SO = T_MR;
        }
        if (*T_CZH == NUL) {
            T_CZR = T_ME;
            if (*T_MR == NUL)
                T_CZH = T_MD;
            else
                T_CZH = T_MR;
        }
        if (*T_CSB == NUL || *T_CSF == NUL) {
            T_CSB = empty_option;
            T_CSF = empty_option;
        }
        if (*T_CAB == NUL || *T_CAF == NUL) {
            T_CAB = empty_option;
            T_CAF = empty_option;
        }
        if (*T_CSB == NUL && *T_CAB == NUL)
            free_one_termoption (T_CCO);
        p_wiv = (*T_XS != NUL);
    }
    need_gather = TRUE;
    t_colors = atoi ((char *) T_CCO);
    env_colors = mch_getenv ((char_u *) "COLORS");
    if (env_colors != NULL && isdigit (*env_colors)) {
        int colors = atoi ((char *) env_colors);
        if (colors != t_colors)
            set_color_count (colors);
    }
}

static void set_color_count (int nr) {
    char_u nr_colors [20];
    t_colors = nr;
    if (t_colors > 1)
        sprintf ((char *) nr_colors, "%d", t_colors);
    else
        *nr_colors = NUL;
    set_string_option_direct ((char_u *) "t_Co", - 1, nr_colors, OPT_FREE, 0);
}

int term_is_gui (char_u *name) {
    return (STRCMP (name, "builtin_gui") == 0 || STRCMP (name, "gui") == 0);
}

int set_termname (char_u *term) {
    struct builtin_term *termp;
    int width = 0, height = 0;
    char_u *error_msg = NULL;
    char_u *bs_p, *del_p;
    if (silent_mode)
        return OK;
    detected_8bit = FALSE;
    if (term_is_builtin (term)) {
        term += 8;
    }
    {
        termp = find_builtin_term (term);
        if (termp->bt_string == NULL) {
            mch_errmsg ("\r\n");
            if (error_msg != NULL) {
                mch_errmsg ((char *) error_msg);
                mch_errmsg ("\r\n");
            }
            mch_errmsg ("'");
            mch_errmsg ((char *) term);
            mch_errmsg (_ ("' not known. Available builtin terminals are:"));
            mch_errmsg ("\r\n");
            for (termp = &(builtin_termcaps[0]); termp->bt_string != NULL; ++termp) {
                if (termp->bt_entry == (int) KS_NAME) {
                    mch_errmsg ("    ");
                    mch_errmsg (termp -> bt_string);
                    mch_errmsg ("\r\n");
                }
            }
            if (starting != NO_SCREEN) {
                screen_start ();
                wait_return (TRUE);
                return FAIL;
            }
            term = DEFAULT_TERM;
            mch_errmsg (_ ("defaulting to '"));
            mch_errmsg ((char *) term);
            mch_errmsg ("'\r\n");
            if (emsg_silent == 0) {
                screen_start ();
                out_flush ();
                if (!is_not_a_term ())
                    ui_delay (2000L, TRUE);
            }
            set_string_option_direct ((char_u *) "term", - 1, term, OPT_FREE, 0);
            display_errors ();
        }
        out_flush ();
        clear_termoptions ();
        parse_builtin_tcap (term);
        if (term_is_gui (term)) {
            out_flush ();
            gui_init ();
            if (!gui.in_use)
                return FAIL;
        }
    }
    if (STRCMP (term, "pcterm") == 0)
        T_CCS = (char_u *) "yes";
    else
        T_CCS = empty_option;
    if (!gui.in_use)
        get_stty ();
    if (!gui.in_use) {
        bs_p = find_termcode ((char_u *) "kb");
        del_p = find_termcode ((char_u *) "kD");
        if (bs_p == NULL || *bs_p == NUL)
            add_termcode ((char_u *) "kb", (bs_p = (char_u *) CTRL_H_STR), FALSE);
        if ((del_p == NULL || *del_p == NUL) && (bs_p == NULL || *bs_p != DEL))
            add_termcode ((char_u *) "kD", (char_u *) DEL_STR, FALSE);
    }
    term_is_xterm = vim_is_xterm (term);
    if (vim_is_fastterm (term))
        p_tf = TRUE;
    ttest (TRUE);
    full_screen = TRUE;
    set_term_defaults ();
    LOG_TR ("setting crv_status to STATUS_GET");
    crv_status = STATUS_GET;
    if (starting != NO_SCREEN) {
        starttermcap ();
        setmouse ();
        maketitle ();
    }
    if (width <= 0 || height <= 0) {
        width = 80;
        height = 24;
    }
    set_shellsize (width, height, FALSE);
    if (starting != NO_SCREEN) {
        if (scroll_region)
            scroll_region_reset ();
        check_map_keycodes ();
        {
            bufref_T old_curbuf;
            set_bufref (& old_curbuf, curbuf);
            FOR_ALL_BUFFERS (curbuf) {
                if (curbuf->b_ml.ml_mfp != NULL)
                    apply_autocmds (EVENT_TERMCHANGED, NULL, NULL, FALSE, curbuf);
            }
            if (bufref_valid (&old_curbuf))
                curbuf = old_curbuf.br_buf;
        }
    }
    may_req_termresponse ();
    return OK;
}

void clear_termcodes (void) {
    while (tc_len > 0)
        vim_free (termcodes[--tc_len].code);
    VIM_CLEAR (termcodes);
    tc_max_len = 0;
    need_gather = TRUE;
}

#define ATC_FROM_TERM 55

static void parse_builtin_tcap (char_u *term) {
    struct builtin_term *p;
    char_u name [2];
    int term_8bit;
    p = find_builtin_term (term);
    term_8bit = term_is_8bit (term);
    if (p->bt_string == NULL)
        return;
    for (++p; p->bt_entry != (int) KS_NAME && p->bt_entry != BT_EXTRA_KEYS; ++p) {
        if ((int) p->bt_entry >= 0) {
            if (term_strings[p->bt_entry] == NULL || term_strings[p->bt_entry] == empty_option) {
                if (term_8bit && term_7to8bit ((char_u *) p->bt_string) != 0) {
                    char_u *s, *t;
                    s = vim_strsave ((char_u *) p->bt_string);
                    if (s != NULL) {
                        for (t = s; *t; ++t)
                            if (term_7to8bit (t)) {
                                *t = term_7to8bit (t);
                                STRCPY (t + 1, t + 2);
                            }
                        term_strings[p->bt_entry] = s;
                        set_term_option_alloced (& term_strings [p -> bt_entry]);
                    }
                }
                else
                    term_strings[p->bt_entry] = (char_u *) p->bt_string;
            }
        }
        else {
            name[0] = KEY2TERMCAP0 ((int) p->bt_entry);
            name[1] = KEY2TERMCAP1 ((int) p->bt_entry);
            if (find_termcode (name) == NULL)
                add_termcode (name, (char_u *) p->bt_string, term_8bit);
        }
    }
}

void termcapinit (char_u *name) {
    char_u *term;
    if (name != NULL && *name == NUL)
        name = NULL;
    term = name;
    if (term == NULL)
        term = mch_getenv ((char_u *) "TERM");
    if (term == NULL || *term == NUL)
        term = DEFAULT_TERM;
    set_string_option_direct ((char_u *) "term", - 1, term, OPT_FREE, 0);
    set_string_default ("term", term);
    set_string_default ("ttytype", term);
    char_u *term_cap = T_NAME != NULL ? T_NAME : term;
    set_termname (term_cap);
}

#define OUT_SIZE	2047

void show_termcodes (void) {
    int col;
    int *items;
    int item_count;
    int run;
    int row, rows;
    int cols;
    int i;
    int len;

    #define INC3 27	    /* try to make three columns */

    #define INC2 40	    /* try to make two columns */

    #define GAP 2	    /* spaces between columns */
    if (tc_len == 0)
        return;
    items = (int *) alloc ((unsigned ) (sizeof (int) * tc_len));
    if (items == NULL)
        return;
    MSG_PUTS_TITLE (_ ("\n--- Terminal keys ---"));
    for (run = 1; run <= 3 && !got_int; ++run) {
        item_count = 0;
        for (i = 0; i < tc_len; i++) {
            len = show_one_termcode (termcodes[i].name, termcodes[i].code, FALSE);
            if (len <= INC3 - GAP ? run == 1 : len <= INC2 - GAP ? run == 2 : run == 3)
                items[item_count++] = i;
        }
        if (run <= 2) {
            cols = (Columns + GAP) / (run == 1 ? INC3 : INC2);
            if (cols == 0)
                cols = 1;
            rows = (item_count + cols - 1) / cols;
        }
        else
            rows = item_count;
        for (row = 0; row < rows && !got_int; ++row) {
            msg_putchar ('\n');
            if (got_int)
                break;
            col = 0;
            for (i = row; i < item_count; i += rows) {
                msg_col = col;
                show_one_termcode (termcodes [items [i]].name, termcodes [items [i]].code, TRUE);
                if (run == 2)
                    col += INC2;
                else
                    col += INC3;
            }
            out_flush ();
            ui_breakcheck ();
        }
    }
    vim_free (items);
}

int show_one_termcode (char_u *name, char_u *code, int printit) {
    char_u *p;
    int len;
    if (name[0] > '~') {
        IObuff[0] = ' ';
        IObuff[1] = ' ';
        IObuff[2] = ' ';
        IObuff[3] = ' ';
    }
    else {
        IObuff[0] = 't';
        IObuff[1] = '_';
        IObuff[2] = name[0];
        IObuff[3] = name[1];
    }
    IObuff[4] = ' ';
    p = get_special_key_name (TERMCAP2KEY (name[0], name[1]), 0);
    if (p[1] != 't')
        STRCPY (IObuff +5, p);
    else
        IObuff[5] = NUL;
    len = (int) STRLEN (IObuff);
    do
        IObuff[len++] = ' ';
    while (len < 17);
    IObuff[len] = NUL;
    if (code == NULL)
        len += 4;
    else
        len += vim_strsize (code);
    if (printit) {
        msg_puts (IObuff);
        if (code == NULL)
            msg_puts ((char_u *) "NULL");
        else
            msg_outtrans (code);
    }
    return len;
}

guicolor_T gui_get_rgb_color_cmn (int r, int g, int b) {
    guicolor_T color = RGB (r, g, b);
    if (color > 0xffffff)
        return INVALCOLOR;
    return color;
}

char_u *replace_termcodes (char_u *from, char_u **bufp, int from_part, int do_lt, int special) {
    int i;
    int slen;
    int key;
    int dlen = 0;
    char_u *src;
    int do_backslash;
    int do_special;
    int do_key_code;
    char_u *result;
    do_backslash = (vim_strchr (p_cpo, CPO_BSLASH) == NULL);
    do_special = (vim_strchr (p_cpo, CPO_SPECI) == NULL) || special;
    do_key_code = (vim_strchr (p_cpo, CPO_KEYCODE) == NULL);
    result = alloc ((unsigned ) STRLEN (from) * 6 + 1);
    if (result == NULL) {
        *bufp = NULL;
        return from;
    }
    src = from;
    if (from_part && src[0] == '#' && VIM_ISDIGIT (src[1])) {
        result[dlen++] = K_SPECIAL;
        result[dlen++] = 'k';
        if (src[1] == '0')
            result[dlen++] = ';';
        else
            result[dlen++] = src[1];
        src += 2;
    }
    while (*src != NUL) {
        if (do_special && (do_lt || STRNCMP (src, "<lt>", 4) != 0)) {
            if (STRNICMP (src, "<SID>", 5) == 0) {
                if (current_SID <= 0)
                    EMSG (_ (e_usingsid));
                else {
                    src += 5;
                    result[dlen++] = K_SPECIAL;
                    result[dlen++] = (int) KS_EXTRA;
                    result[dlen++] = (int) KE_SNR;
                    sprintf ((char *) result + dlen, "%ld", (long) current_SID);
                    dlen += (int) STRLEN (result +dlen);
                    result[dlen++] = '_';
                    continue;
                }
            }
            slen = trans_special (&src, result +dlen, TRUE, FALSE);
            if (slen) {
                dlen += slen;
                continue;
            }
        }
        if (do_key_code) {
            i = find_term_bykeys (src);
            if (i >= 0) {
                result[dlen++] = K_SPECIAL;
                result[dlen++] = termcodes[i].name[0];
                result[dlen++] = termcodes[i].name[1];
                src += termcodes[i].len;
                continue;
            }
        }
        if (do_special) {
            char_u *p, *s, len;
            if (STRNICMP (src, "<Leader>", 8) == 0) {
                len = 8;
                p = get_var_value ((char_u *) "g:mapleader");
            }
            else if (STRNICMP (src, "<LocalLeader>", 13) == 0) {
                len = 13;
                p = get_var_value ((char_u *) "g:maplocalleader");
            }
            else {
                len = 0;
                p = NULL;
            }
            if (len != 0) {
                if (p == NULL || *p == NUL || STRLEN (p) > 8 * 6)
                    s = (char_u *) "\\";
                else
                    s = p;
                while (*s != NUL)
                    result[dlen++] = *s++;
                src += len;
                continue;
            }
        }
        key = *src;
        if (key == Ctrl_V || (do_backslash && key == '\\')) {
            ++src;
            if (*src == NUL) {
                if (from_part)
                    result[dlen++] = key;
                break;
            }
        }
        {
            if (*src == K_SPECIAL) {
                result[dlen++] = K_SPECIAL;
                result[dlen++] = KS_SPECIAL;
                result[dlen++] = KE_FILLER;
            }
            else if (*src == CSI) {
                result[dlen++] = K_SPECIAL;
                result[dlen++] = KS_EXTRA;
                result[dlen++] = (int) KE_CSI;
            }
            else
                result[dlen++] = *src;
            ++src;
        }
    }
    result[dlen] = NUL;
    if ((*bufp = vim_strsave (result)) != NULL)
        from = *bufp;
    vim_free (result);
    return from;
}

int find_term_bykeys (char_u *src) {
    int i;
    int slen = (int) STRLEN (src);
    for (i = 0; i < tc_len; ++i) {
        if (slen == termcodes[i].len && STRNCMP (termcodes[i].code, src, (size_t) slen) == 0)
            return i;
    }
    return -1;
}

char_u *get_termcode (int i) {
    if (i >= tc_len)
        return NULL;
    return &termcodes[i].name[0];
}

char_u *translate_mapping (char_u *str, int expmap) {
    garray_T ga;
    int c;
    int modifiers;
    int cpo_bslash;
    int cpo_special;
    int cpo_keycode;
    ga_init (& ga);
    ga.ga_itemsize = 1;
    ga.ga_growsize = 40;
    cpo_bslash = (vim_strchr (p_cpo, CPO_BSLASH) != NULL);
    cpo_special = (vim_strchr (p_cpo, CPO_SPECI) != NULL);
    cpo_keycode = (vim_strchr (p_cpo, CPO_KEYCODE) == NULL);
    for (; *str; ++str) {
        c = *str;
        if (c == K_SPECIAL && str[1] != NUL && str[2] != NUL) {
            modifiers = 0;
            if (str[1] == KS_MODIFIER) {
                str++;
                modifiers = *++str;
                c = *++str;
            }
            if (cpo_special && cpo_keycode && c == K_SPECIAL && !modifiers) {
                int i;
                for (i = 0; i < tc_len; ++i)
                    if (termcodes[i].name[0] == str[1] && termcodes[i].name[1] == str[2])
                        break;
                if (i < tc_len) {
                    ga_concat (& ga, termcodes [i].code);
                    str += 2;
                    continue;
                }
            }
            if (c == K_SPECIAL && str[1] != NUL && str[2] != NUL) {
                if (expmap && cpo_special) {
                    ga_clear (& ga);
                    return NULL;
                }
                c = TO_SPECIAL (str[1], str[2]);
                if (c == K_ZERO)
                    c = NUL;
                str += 2;
            }
            if (IS_SPECIAL (c) || modifiers) {
                if (expmap && cpo_special) {
                    ga_clear (& ga);
                    return NULL;
                }
                ga_concat (& ga, get_special_key_name (c, modifiers));
                continue;
            }
        }
        if (c == ' ' || c == '\t' || c == Ctrl_J || c == Ctrl_V || (c == '<' && !cpo_special) || (c == '\\' && !cpo_bslash))
            ga_append (&ga, cpo_bslash ? Ctrl_V : '\\');
        if (c)
            ga_append (&ga, c);
    }
    ga_append (& ga, NUL);
    return (char_u *) (ga.ga_data);
}

int mouse_model_popup (void) {
    return (p_mousem[0] == 'p');
}

guicolor_T gui_get_color_cmn (char_u *name) {

    #  define RGB(r, g, b)	((r<<16) | (g<<8) | (b))

    # define LINE_LEN 100
    FILE *fd;
    char line [LINE_LEN];
    char_u *fname;
    int r, g, b, i;
    guicolor_T color;
    struct rgbcolor_table_S {
        char_u *color_name;
        guicolor_T color;
    };
    static struct rgbcolor_table_S rgb_table [] = {{(char_u *) "black", RGB (0x00, 0x00, 0x00)}, {(char_u *) "blue", RGB (0x00, 0x00, 0xFF)}, {(char_u *) "brown", RGB (0xA5, 0x2A, 0x2A)}, {(char_u *) "cyan", RGB (0x00, 0xFF, 0xFF)}, {(char_u *) "darkblue", RGB (0x00, 0x00, 0x8B)}, {(char_u *) "darkcyan", RGB (0x00, 0x8B, 0x8B)}, {(char_u *) "darkgray", RGB (0xA9, 0xA9, 0xA9)}, {(char_u *) "darkgreen", RGB (0x00, 0x64, 0x00)}, {(char_u *) "darkgrey", RGB (0xA9, 0xA9, 0xA9)}, {(char_u *) "darkmagenta", RGB (0x8B, 0x00, 0x8B)}, {(char_u *) "darkred", RGB (0x8B, 0x00, 0x00)}, {(char_u *) "darkyellow", RGB (0x8B, 0x8B, 0x00)}, {(char_u *) "gray", RGB (0xBE, 0xBE, 0xBE)}, {(char_u *) "green", RGB (0x00, 0xFF, 0x00)}, {(char_u *) "grey", RGB (0xBE, 0xBE, 0xBE)}, {(char_u *) "grey40", RGB (0x66, 0x66, 0x66)}, {(char_u *) "grey90", RGB (0xE5, 0xE5, 0xE5)}, {(char_u *) "lightblue", RGB (0xAD, 0xD8, 0xE6)}, {(char_u *) "lightcyan", RGB (0xE0, 0xFF, 0xFF)}, {(char_u *) "lightgray", RGB (0xD3, 0xD3, 0xD3)}, {(char_u *) "lightgreen", RGB (0x90, 0xEE, 0x90)}, {(char_u *) "lightgrey", RGB (0xD3, 0xD3, 0xD3)}, {(char_u *) "lightmagenta", RGB (0xFF, 0x8B, 0xFF)}, {(char_u *) "lightred", RGB (0xFF, 0x8B, 0x8B)}, {(char_u *) "lightyellow", RGB (0xFF, 0xFF, 0xE0)}, {(char_u *) "magenta", RGB (0xFF, 0x00, 0xFF)}, {(char_u *) "red", RGB (0xFF, 0x00, 0x00)}, {(char_u *) "seagreen", RGB (0x2E, 0x8B, 0x57)}, {(char_u *) "white", RGB (0xFF, 0xFF, 0xFF)}, {(char_u *) "yellow", RGB (0xFF, 0xFF, 0x00)},};
    static struct rgbcolor_table_S *colornames_table;
    static int size = 0;
    if (name[0] == '#' && STRLEN (name) == 7) {
        color = RGB (((hex_digit (name[1]) << 4) + hex_digit (name[2])), ((hex_digit (name[3]) << 4) + hex_digit (name[4])), ((hex_digit (name[5]) << 4) + hex_digit (name[6])));
        if (color > 0xffffff)
            return INVALCOLOR;
        return color;
    }
    for (i = 0; i < (int) (sizeof (rgb_table) / sizeof (rgb_table[0])); i++)
        if (STRICMP (name, rgb_table[i].color_name) == 0)
            return rgb_table[i].color;
    if (size == 0) {
        int counting;
        fname = expand_env_save ((char_u *) "$VIMRUNTIME/rgb.txt");
        if (fname == NULL)
            return INVALCOLOR;
        fd = fopen ((char *) fname, "rt");
        vim_free (fname);
        if (fd == NULL) {
            if (p_verbose > 1)
                verb_msg ((char_u *) _ ("Cannot open $VIMRUNTIME/rgb.txt"));
            return INVALCOLOR;
        }
        for (counting = 1; counting >= 0; --counting) {
            if (!counting) {
                colornames_table = (struct rgbcolor_table_S *) alloc ((unsigned ) (sizeof (struct rgbcolor_table_S) * size));
                if (colornames_table == NULL) {
                    fclose (fd);
                    return INVALCOLOR;
                }
                rewind (fd);
            }
            size = 0;
            while (!feof (fd)) {
                size_t len;
                int pos;
                ignoredp = fgets (line, LINE_LEN, fd);
                len = strlen (line);
                if (len <= 1 || line[len - 1] != '\n')
                    continue;
                line[len - 1] = '\0';
                i = sscanf (line, "%d %d %d %n", &r, &g, &b, &pos);
                if (i != 3)
                    continue;
                if (!counting) {
                    char_u *s = vim_strsave ((char_u *) line + pos);
                    if (s == NULL) {
                        fclose (fd);
                        return INVALCOLOR;
                    }
                    colornames_table[size].color_name = s;
                    colornames_table[size].color = (guicolor_T) RGB (r, g, b);
                }
                size++;
            }
        }
        fclose (fd);
    }
    for (i = 0; i < size; i++)
        if (STRICMP (name, colornames_table[i].color_name) == 0)
            return colornames_table[i].color;
    return INVALCOLOR;
}

static int hex_digit (int c) {
    if (isdigit (c))
        return c - '0';
    c = TOLOWER_ASC (c);
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    return 0x1ffffff;
}

void scroll_region_set (win_T *wp, int off) {
    OUT_STR (tgoto ((char *) T_CS, W_WINROW (wp) + wp -> w_height - 1, W_WINROW (wp) + off));
    if (*T_CSV != NUL && wp->w_width != Columns)
        OUT_STR (tgoto ((char *) T_CSV, wp->w_wincol + wp->w_width - 1, wp->w_wincol));
    screen_start ();
}

void scroll_region_reset (void) {
    OUT_STR (tgoto ((char *) T_CS, (int) Rows - 1, 0));
    if (*T_CSV != NUL)
        OUT_STR (tgoto ((char *) T_CSV, (int) Columns - 1, 0));
    screen_start ();
}

void starttermcap (void) {
    if (full_screen && !termcap_active) {
        out_str (T_TI);
        out_str (T_KS);
        out_str (T_BE);
        out_flush ();
        termcap_active = TRUE;
        screen_start ();
        if (!gui.in_use && !gui.starting) {
            may_req_termresponse ();
            if (crv_status == STATUS_SENT)
                check_for_codes_from_term ();
        }
    }
}

void may_req_termresponse (void) {
    if (crv_status == STATUS_GET && can_get_termresponse () && starting == 0 && *T_CRV != NUL) {
        LOG_TR ("Sending CRV request");
        out_str (T_CRV);
        crv_status = STATUS_SENT;
        out_flush ();
        (void) vpeekc_nomap ();
    }
}

static void switch_to_8bit (void) {
    int i;
    int c;
    if (!term_is_8bit (T_NAME)) {
        for (i = 0; i < tc_len; ++i) {
            c = term_7to8bit (termcodes[i].code);
            if (c != 0) {
                STRMOVE (termcodes [i].code + 1, termcodes [i].code + 2);
                termcodes[i].code[0] = c;
            }
        }
        need_gather = TRUE;
    }
    detected_8bit = TRUE;
    LOG_TR ("Switching to 8 bit");
}

static void req_codes_from_term (void) {
    xt_index_out = 0;
    xt_index_in = 0;
    req_more_codes_from_term ();
}

static void req_more_codes_from_term (void) {
    char buf [11];
    int old_idx = xt_index_out;
    if (exiting)
        return;
    while (xt_index_out < xt_index_in + 10 && key_names[xt_index_out] != NULL) {
        sprintf (buf, "\033P+q%02x%02x\033\\", key_names [xt_index_out] [0], key_names [xt_index_out] [1]);
        out_str_nf ((char_u *) buf);
        ++xt_index_out;
    }
    if (xt_index_out != old_idx)
        out_flush ();
}

static void may_adjust_color_count (int val) {
    if (val != t_colors) {
        set_keep_msg_from_hist ();
        set_color_count (val);
        init_highlight (TRUE, FALSE);
        redraw_asap (CLEAR);
    }
}

static void got_code_from_term (char_u *code, int len) {

    #define XT_LEN 100
    char_u name [3];
    char_u str [XT_LEN];
    int i;
    int j = 0;
    int c;
    if (code[0] == '1' && code[7] == '=' && len / 2 < XT_LEN) {
        name[0] = hexhex2nr (code +3);
        name[1] = hexhex2nr (code +5);
        name[2] = NUL;
        for (i = 0; key_names[i] != NULL; ++i) {
            if (STRCMP (key_names[i], name) == 0) {
                xt_index_in = i;
                break;
            }
        }
        if (key_names[i] != NULL) {
            for (i = 8; (c = hexhex2nr (code +i)) >= 0; i += 2)
                str[j++] = c;
            str[j] = NUL;
            if (name[0] == 'C' && name[1] == 'o') {
                i = atoi ((char *) str);
                may_adjust_color_count (i);
            }
            else {
                i = find_term_bykeys (str);
                if (i >= 0)
                    del_termcode_idx (i);
                add_termcode (name, str, ATC_FROM_TERM);
            }
        }
    }
    ++xt_index_in;
    req_more_codes_from_term ();
}

static int get_bytes_from_buf (char_u *buf, char_u *bytes, int num_bytes) {
    int len = 0;
    int i;
    char_u c;
    for (i = 0; i < num_bytes; i++) {
        if ((c = buf[len++]) == NUL)
            return -1;
        if (c == K_SPECIAL) {
            if (buf[len] == NUL || buf[len + 1] == NUL)
                return -1;
            if (buf[len++] == (int) KS_ZERO)
                c = NUL;
            if (buf[len++] == (int) KE_CSI)
                c = CSI;
        }
        else if (c == CSI && buf[len] == KS_EXTRA && buf[len + 1] == (int) KE_CSI)
            len += 2;
        bytes[i] = c;
    }
    return len;
}

static int get_long_from_buf (char_u *buf, long_u *val) {
    int len;
    char_u bytes [sizeof (long_u)];
    int i;
    int shift;
    *val = 0;
    len = get_bytes_from_buf (buf, bytes, (int) sizeof (long_u));
    if (len != -1) {
        for (i = 0; i < (int) sizeof (long_u); i++) {
            shift = 8 * (sizeof (long_u) - 1 - i);
            *val += (long_u) bytes[i] << shift;
        }
    }
    return len;
}

int swapping_screen (void) {
    return (full_screen && *T_TI != NUL);
}

void shell_resized_check (void) {
    int old_Rows = Rows;
    int old_Columns = Columns;
    if (!exiting && !gui.starting) {
        (void) ui_get_shellsize ();
        check_shellsize ();
        if (old_Rows != Rows || old_Columns != Columns)
            shell_resized ();
    }
}

void term_get_fg_color (char_u *r, char_u *g, char_u *b) {
    if (rfg_status == STATUS_GOT) {
        *r = fg_r;
        *g = fg_g;
        *b = fg_b;
    }
}

void term_get_bg_color (char_u *r, char_u *g, char_u *b) {
    if (rbg_status == STATUS_GOT) {
        *r = bg_r;
        *g = bg_g;
        *b = bg_b;
    }
}

