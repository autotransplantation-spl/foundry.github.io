
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
struct vimvar {
    char *vv_name;
    dictitem16_T vv_di;
    char vv_flags;
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
char *e_letwrong = N_ ("E734: Wrong variable type for %s=");
garray_T redir_ga;
EXTERN char_u e_trailing [] INIT (= N_ ("E488: Trailing characters"));
EXTERN char_u e_readonlysbx [] INIT (= N_ ("E794: Cannot set variable in the sandbox: \"%s\""));
EXTERN long  p_verbose;
garray_T ga_loaded = {0, 0, sizeof (char_u *), 4, NULL};
EXTERN char_u *p_dex;
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
EXTERN char_u *p_titlestring;
char *e_float_as_string = N_ ("E806: using Float as a String");
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
char_u *redir_varname = NULL;
dictitem_T vimvars_var;
struct vimvar vimvars [VV_LEN] = {{VV_NAME ("count", VAR_NUMBER), VV_COMPAT + VV_RO}, {VV_NAME ("count1", VAR_NUMBER), VV_RO}, {VV_NAME ("prevcount", VAR_NUMBER), VV_RO}, {VV_NAME ("errmsg", VAR_STRING), VV_COMPAT}, {VV_NAME ("warningmsg", VAR_STRING), 0}, {VV_NAME ("statusmsg", VAR_STRING), 0}, {VV_NAME ("shell_error", VAR_NUMBER), VV_COMPAT + VV_RO}, {VV_NAME ("this_session", VAR_STRING), VV_COMPAT}, {VV_NAME ("version", VAR_NUMBER), VV_COMPAT + VV_RO}, {VV_NAME ("lnum", VAR_NUMBER), VV_RO_SBX}, {VV_NAME ("termresponse", VAR_STRING), VV_RO}, {VV_NAME ("fname", VAR_STRING), VV_RO}, {VV_NAME ("lang", VAR_STRING), VV_RO}, {VV_NAME ("lc_time", VAR_STRING), VV_RO}, {VV_NAME ("ctype", VAR_STRING), VV_RO}, {VV_NAME ("charconvert_from", VAR_STRING), VV_RO}, {VV_NAME ("charconvert_to", VAR_STRING), VV_RO}, {VV_NAME ("fname_in", VAR_STRING), VV_RO}, {VV_NAME ("fname_out", VAR_STRING), VV_RO}, {VV_NAME ("fname_new", VAR_STRING), VV_RO}, {VV_NAME ("fname_diff", VAR_STRING), VV_RO}, {VV_NAME ("cmdarg", VAR_STRING), VV_RO}, {VV_NAME ("foldstart", VAR_NUMBER), VV_RO_SBX}, {VV_NAME ("foldend", VAR_NUMBER), VV_RO_SBX}, {VV_NAME ("folddashes", VAR_STRING), VV_RO_SBX}, {VV_NAME ("foldlevel", VAR_NUMBER), VV_RO_SBX}, {VV_NAME ("progname", VAR_STRING), VV_RO}, {VV_NAME ("servername", VAR_STRING), VV_RO}, {VV_NAME ("dying", VAR_NUMBER), VV_RO}, {VV_NAME ("exception", VAR_STRING), VV_RO}, {VV_NAME ("throwpoint", VAR_STRING), VV_RO}, {VV_NAME ("register", VAR_STRING), VV_RO}, {VV_NAME ("cmdbang", VAR_NUMBER), VV_RO}, {VV_NAME ("insertmode", VAR_STRING), VV_RO}, {VV_NAME ("val", VAR_UNKNOWN), VV_RO}, {VV_NAME ("key", VAR_UNKNOWN), VV_RO}, {VV_NAME ("profiling", VAR_NUMBER), VV_RO}, {VV_NAME ("fcs_reason", VAR_STRING), VV_RO}, {VV_NAME ("fcs_choice", VAR_STRING), 0}, {VV_NAME ("beval_bufnr", VAR_NUMBER), VV_RO}, {VV_NAME ("beval_winnr", VAR_NUMBER), VV_RO}, {VV_NAME ("beval_winid", VAR_NUMBER), VV_RO}, {VV_NAME ("beval_lnum", VAR_NUMBER), VV_RO}, {VV_NAME ("beval_col", VAR_NUMBER), VV_RO}, {VV_NAME ("beval_text", VAR_STRING), VV_RO}, {VV_NAME ("scrollstart", VAR_STRING), 0}, {VV_NAME ("swapname", VAR_STRING), VV_RO}, {VV_NAME ("swapchoice", VAR_STRING), 0}, {VV_NAME ("swapcommand", VAR_STRING), VV_RO}, {VV_NAME ("char", VAR_STRING), 0}, {VV_NAME ("mouse_win", VAR_NUMBER), 0}, {VV_NAME ("mouse_winid", VAR_NUMBER), 0}, {VV_NAME ("mouse_lnum", VAR_NUMBER), 0}, {VV_NAME ("mouse_col", VAR_NUMBER), 0}, {VV_NAME ("operator", VAR_STRING), VV_RO}, {VV_NAME ("searchforward", VAR_NUMBER), 0}, {VV_NAME ("hlsearch", VAR_NUMBER), 0}, {VV_NAME ("oldfiles", VAR_LIST), 0}, {VV_NAME ("windowid", VAR_NUMBER), VV_RO}, {VV_NAME ("progpath", VAR_STRING), VV_RO}, {VV_NAME ("completed_item", VAR_DICT), VV_RO}, {VV_NAME ("option_new", VAR_STRING), VV_RO}, {VV_NAME ("option_old", VAR_STRING), VV_RO}, {VV_NAME ("option_type", VAR_STRING), VV_RO}, {VV_NAME ("errors", VAR_LIST), 0}, {VV_NAME ("false", VAR_SPECIAL), VV_RO}, {VV_NAME ("true", VAR_SPECIAL), VV_RO}, {VV_NAME ("null", VAR_SPECIAL), VV_RO}, {VV_NAME ("none", VAR_SPECIAL), VV_RO}, {VV_NAME ("vim_did_enter", VAR_NUMBER), VV_RO}, {VV_NAME ("testing", VAR_NUMBER), 0}, {VV_NAME ("t_number", VAR_NUMBER), VV_RO}, {VV_NAME ("t_string", VAR_NUMBER), VV_RO}, {VV_NAME ("t_func", VAR_NUMBER), VV_RO}, {VV_NAME ("t_list", VAR_NUMBER), VV_RO}, {VV_NAME ("t_dict", VAR_NUMBER), VV_RO}, {VV_NAME ("t_float", VAR_NUMBER), VV_RO}, {VV_NAME ("t_bool", VAR_NUMBER), VV_RO}, {VV_NAME ("t_none", VAR_NUMBER), VV_RO}, {VV_NAME ("t_job", VAR_NUMBER), VV_RO}, {VV_NAME ("t_channel", VAR_NUMBER), VV_RO}, {VV_NAME ("termrfgresp", VAR_STRING), VV_RO}, {VV_NAME ("termrbgresp", VAR_STRING), VV_RO}, {VV_NAME ("termu7resp", VAR_STRING), VV_RO}, {VV_NAME ("termstyleresp", VAR_STRING), VV_RO}, {VV_NAME ("termblinkresp", VAR_STRING), VV_RO}, {VV_NAME ("event", VAR_DICT), VV_RO},};
dictitem_T globvars_var;
char *e_illvar = N_ ("E461: Illegal variable name: %s");
char *e_undefvar = N_ ("E121: Undefined variable: %s");
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
lval_T *redir_lval = NULL;
garray_T ga_scripts = {0, 0, sizeof (scriptvar_T *), 4, NULL};
hashtab_T compat_hashtab;
char *e_dictrange = N_ ("E719: Cannot use [:] with a Dictionary");
char *e_missbrac = N_ ("E111: Missing ']'");
EXTERN proftime_T bevalexpr_due;
EXTERN char_u e_invexpr2 [] INIT (= N_ ("E15: Invalid expression: %s"));
EXTERN char_u *p_pexpr;
EXTERN char_u *p_bexpr;
char_u *redir_endp = NULL;
EXTERN char_u e_au_recursive [] INIT (= N_ ("E952: Autocommand caused recursive behavior"));
EXTERN char_u e_secure [] INIT (= N_ ("E523: Not allowed here"));
EXTERN char_u e_curdir [] INIT (= N_ ("E12: Command not allowed from exrc/vimrc in current dir or tag search"));
EXTERN pos_T saved_cursor;
EXTERN tabpage_T *curtab;
EXTERN win_T *curwin;
EXTERN int current_scrollbar;
EXTERN vimmenu_T *current_menu;
EXTERN except_T *current_exception;
int tv_equal_recurse_limit;
int current_copyID = 0;
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
char_u *varnamebuf = NULL;
int echo_attr = 0;
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
int varnamebuflen = 0;
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

int skip_expr (char_u **pp) {
    typval_T rettv;
    *pp = skipwhite (*pp);
    return eval1 (pp, &rettv, FALSE);
}

int eval1 (char_u **arg, typval_T *rettv, int evaluate) {
    int result;
    typval_T var2;
    if (eval2 (arg, rettv, evaluate) == FAIL)
        return FAIL;
    if ((*arg)[0] == '?') {
        result = FALSE;
        if (evaluate) {
            int error = FALSE;
            if (get_tv_number_chk (rettv, &error) != 0)
                result = TRUE;
            clear_tv (rettv);
            if (error)
                return FAIL;
        }
        *arg = skipwhite (*arg + 1);
        if (eval1 (arg, rettv, evaluate &&result) == FAIL)
            return FAIL;
        if ((*arg)[0] != ':') {
            EMSG (_ ("E109: Missing ':' after '?'"));
            if (evaluate && result)
                clear_tv (rettv);
            return FAIL;
        }
        *arg = skipwhite (*arg + 1);
        if (eval1 (arg, &var2, evaluate &&!result) == FAIL) {
            if (evaluate && result)
                clear_tv (rettv);
            return FAIL;
        }
        if (evaluate && !result)
            *rettv = var2;
    }
    return OK;
}

static int eval2 (char_u **arg, typval_T *rettv, int evaluate) {
    typval_T var2;
    long  result;
    int first;
    int error = FALSE;
    if (eval3 (arg, rettv, evaluate) == FAIL)
        return FAIL;
    first = TRUE;
    result = FALSE;
    while ((*arg)[0] == '|' && (*arg)[1] == '|') {
        if (evaluate && first) {
            if (get_tv_number_chk (rettv, &error) != 0)
                result = TRUE;
            clear_tv (rettv);
            if (error)
                return FAIL;
            first = FALSE;
        }
        *arg = skipwhite (*arg + 2);
        if (eval3 (arg, &var2, evaluate &&!result) == FAIL)
            return FAIL;
        if (evaluate && !result) {
            if (get_tv_number_chk (&var2, &error) != 0)
                result = TRUE;
            clear_tv (& var2);
            if (error)
                return FAIL;
        }
        if (evaluate) {
            rettv->v_type = VAR_NUMBER;
            rettv->vval.v_number = result;
        }
    }
    return OK;
}

static int eval3 (char_u **arg, typval_T *rettv, int evaluate) {
    typval_T var2;
    long  result;
    int first;
    int error = FALSE;
    if (eval4 (arg, rettv, evaluate) == FAIL)
        return FAIL;
    first = TRUE;
    result = TRUE;
    while ((*arg)[0] == '&' && (*arg)[1] == '&') {
        if (evaluate && first) {
            if (get_tv_number_chk (rettv, &error) == 0)
                result = FALSE;
            clear_tv (rettv);
            if (error)
                return FAIL;
            first = FALSE;
        }
        *arg = skipwhite (*arg + 2);
        if (eval4 (arg, &var2, evaluate &&result) == FAIL)
            return FAIL;
        if (evaluate && result) {
            if (get_tv_number_chk (&var2, &error) == 0)
                result = FALSE;
            clear_tv (& var2);
            if (error)
                return FAIL;
        }
        if (evaluate) {
            rettv->v_type = VAR_NUMBER;
            rettv->vval.v_number = result;
        }
    }
    return OK;
}

static int eval4 (char_u **arg, typval_T *rettv, int evaluate) {
    typval_T var2;
    char_u *p;
    int i;
    exptype_T type = TYPE_UNKNOWN;
    int type_is = FALSE;
    int len = 2;
    int ic;
    if (eval5 (arg, rettv, evaluate) == FAIL)
        return FAIL;
    p = *arg;
    switch (p[0]) {
    case '=' :
        if (p[1] == '=')
            type = TYPE_EQUAL;
        else if (p[1] == '~')
            type = TYPE_MATCH;
        break;
    case '!' :
        if (p[1] == '=')
            type = TYPE_NEQUAL;
        else if (p[1] == '~')
            type = TYPE_NOMATCH;
        break;
    case '>' :
        if (p[1] != '=') {
            type = TYPE_GREATER;
            len = 1;
        }
        else
            type = TYPE_GEQUAL;
        break;
    case '<' :
        if (p[1] != '=') {
            type = TYPE_SMALLER;
            len = 1;
        }
        else
            type = TYPE_SEQUAL;
        break;
    case 'i' :
        if (p[1] == 's') {
            if (p[2] == 'n' && p[3] == 'o' && p[4] == 't')
                len = 5;
            i = p[len];
            if (!isalnum (i) && i != '_') {
                type = len == 2 ? TYPE_EQUAL : TYPE_NEQUAL;
                type_is = TRUE;
            }
        }
        break;
    }
    if (type != TYPE_UNKNOWN) {
        if (p[len] == '?') {
            ic = TRUE;
            ++len;
        }
        else if (p[len] == '#') {
            ic = FALSE;
            ++len;
        }
        else
            ic = p_ic;
        *arg = skipwhite (p +len);
        if (eval5 (arg, &var2, evaluate) == FAIL) {
            clear_tv (rettv);
            return FAIL;
        }
        if (evaluate) {
            int ret = typval_compare (rettv, &var2, type, type_is, ic);
            clear_tv (& var2);
            return ret;
        }
    }
    return OK;
}

static int eval5 (char_u **arg, typval_T *rettv, int evaluate) {
    typval_T var2;
    typval_T var3;
    int op;
    varnumber_T n1, n2;
    float_T f1 = 0, f2 = 0;
    char_u *s1, *s2;
    char_u buf1 [NUMBUFLEN], buf2 [NUMBUFLEN];
    char_u *p;
    if (eval6 (arg, rettv, evaluate, FALSE) == FAIL)
        return FAIL;
    for (;;) {
        op = **arg;
        if (op != '+' && op != '-' && op != '.')
            break;
        if ((op != '+' || rettv->v_type != VAR_LIST) && (op == '.' || rettv->v_type != VAR_FLOAT)) {
            if (evaluate && get_tv_string_chk (rettv) == NULL) {
                clear_tv (rettv);
                return FAIL;
            }
        }
        *arg = skipwhite (*arg + 1);
        if (eval6 (arg, &var2, evaluate, op == '.') == FAIL) {
            clear_tv (rettv);
            return FAIL;
        }
        if (evaluate) {
            if (op == '.') {
                s1 = get_tv_string_buf (rettv, buf1);
                s2 = get_tv_string_buf_chk (&var2, buf2);
                if (s2 == NULL) {
                    clear_tv (rettv);
                    clear_tv (& var2);
                    return FAIL;
                }
                p = concat_str (s1, s2);
                clear_tv (rettv);
                rettv->v_type = VAR_STRING;
                rettv->vval.v_string = p;
            }
            else if (op == '+' && rettv->v_type == VAR_LIST && var2.v_type == VAR_LIST) {
                if (list_concat (rettv->vval.v_list, var2.vval.v_list, &var3) == FAIL) {
                    clear_tv (rettv);
                    clear_tv (& var2);
                    return FAIL;
                }
                clear_tv (rettv);
                *rettv = var3;
            }
            else {
                int error = FALSE;
                if (rettv->v_type == VAR_FLOAT) {
                    f1 = rettv->vval.v_float;
                    n1 = 0;
                }
                else {
                    n1 = get_tv_number_chk (rettv, &error);
                    if (error) {
                        clear_tv (rettv);
                        return FAIL;
                    }
                    if (var2.v_type == VAR_FLOAT)
                        f1 = n1;
                }
                if (var2.v_type == VAR_FLOAT) {
                    f2 = var2.vval.v_float;
                    n2 = 0;
                }
                else {
                    n2 = get_tv_number_chk (&var2, &error);
                    if (error) {
                        clear_tv (rettv);
                        clear_tv (& var2);
                        return FAIL;
                    }
                    if (rettv->v_type == VAR_FLOAT)
                        f2 = n2;
                }
                clear_tv (rettv);
                if (rettv->v_type == VAR_FLOAT || var2.v_type == VAR_FLOAT) {
                    if (op == '+')
                        f1 = f1 + f2;
                    else
                        f1 = f1 - f2;
                    rettv->v_type = VAR_FLOAT;
                    rettv->vval.v_float = f1;
                }
                else {
                    if (op == '+')
                        n1 = n1 + n2;
                    else
                        n1 = n1 - n2;
                    rettv->v_type = VAR_NUMBER;
                    rettv->vval.v_number = n1;
                }
            }
            clear_tv (& var2);
        }
    }
    return OK;
}

static int eval6 (char_u **arg, typval_T *rettv, int evaluate, int want_string) {
    typval_T var2;
    int op;
    varnumber_T n1, n2;
    int use_float = FALSE;
    float_T f1 = 0, f2;
    int error = FALSE;
    if (eval7 (arg, rettv, evaluate, want_string) == FAIL)
        return FAIL;
    for (;;) {
        op = **arg;
        if (op != '*' && op != '/' && op != '%')
            break;
        if (evaluate) {
            if (rettv->v_type == VAR_FLOAT) {
                f1 = rettv->vval.v_float;
                use_float = TRUE;
                n1 = 0;
            }
            else
                n1 = get_tv_number_chk (rettv, &error);
            clear_tv (rettv);
            if (error)
                return FAIL;
        }
        else
            n1 = 0;
        *arg = skipwhite (*arg + 1);
        if (eval7 (arg, &var2, evaluate, FALSE) == FAIL)
            return FAIL;
        if (evaluate) {
            if (var2.v_type == VAR_FLOAT) {
                if (!use_float) {
                    f1 = n1;
                    use_float = TRUE;
                }
                f2 = var2.vval.v_float;
                n2 = 0;
            }
            else {
                n2 = get_tv_number_chk (&var2, &error);
                clear_tv (& var2);
                if (error)
                    return FAIL;
                if (use_float)
                    f2 = n2;
            }
            if (use_float) {
                if (op == '*')
                    f1 = f1 * f2;
                else if (op == '/') {
                    f1 = f1 / f2;
                }
                else {
                    EMSG (_ ("E804: Cannot use '%' with Float"));
                    return FAIL;
                }
                rettv->v_type = VAR_FLOAT;
                rettv->vval.v_float = f1;
            }
            else {
                if (op == '*')
                    n1 = n1 * n2;
                else if (op == '/') {
                    if (n2 == 0) {
                        if (n1 == 0)
                            n1 = VARNUM_MIN;
                        else if (n1 < 0)
                            n1 = -VARNUM_MAX;
                        else
                            n1 = VARNUM_MAX;
                    }
                    else
                        n1 = n1 / n2;
                }
                else {
                    if (n2 == 0)
                        n1 = 0;
                    else
                        n1 = n1 % n2;
                }
                rettv->v_type = VAR_NUMBER;
                rettv->vval.v_number = n1;
            }
        }
    }
    return OK;
}

static int eval7 (char_u **arg, typval_T *rettv, int evaluate, int want_string) {
    varnumber_T n;
    int len;
    char_u *s;
    char_u *start_leader, *end_leader;
    int ret = OK;
    char_u *alias;
    rettv->v_type = VAR_UNKNOWN;
    start_leader = *arg;
    while (**arg == '!' || **arg == '-' || **arg == '+')
        *arg = skipwhite (*arg + 1);
    end_leader = *arg;
    switch (**arg) {
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
        {
            char_u *p = skipdigits (*arg + 1);
            int get_float = FALSE;
            if (!want_string && p[0] == '.' && vim_isdigit (p[1])) {
                get_float = TRUE;
                p = skipdigits (p +2);
                if (*p == 'e' || *p == 'E') {
                    ++p;
                    if (*p == '-' || *p == '+')
                        ++p;
                    if (!vim_isdigit (*p))
                        get_float = FALSE;
                    else
                        p = skipdigits (p +1);
                }
                if (ASCII_ISALPHA (*p) || *p == '.')
                    get_float = FALSE;
            }
            if (get_float) {
                float_T f;
                *arg += string2float (*arg, &f);
                if (evaluate) {
                    rettv->v_type = VAR_FLOAT;
                    rettv->vval.v_float = f;
                }
            }
            else {
                vim_str2nr (* arg, NULL, & len, STR2NR_ALL, & n, NULL, 0);
                *arg += len;
                if (evaluate) {
                    rettv->v_type = VAR_NUMBER;
                    rettv->vval.v_number = n;
                }
            }
            break;
        }
    case '"' :
        ret = get_string_tv (arg, rettv, evaluate);
        break;
    case '\'' :
        ret = get_lit_string_tv (arg, rettv, evaluate);
        break;
    case '[' :
        ret = get_list_tv (arg, rettv, evaluate);
        break;
    case '{' :
        ret = get_lambda_tv (arg, rettv, evaluate);
        if (ret == NOTDONE)
            ret = get_dict_tv (arg, rettv, evaluate);
        break;
    case '&' :
        ret = get_option_tv (arg, rettv, evaluate);
        break;
    case '$' :
        ret = get_env_tv (arg, rettv, evaluate);
        break;
    case '@' :
        ++*arg;
        if (evaluate) {
            rettv->v_type = VAR_STRING;
            rettv->vval.v_string = get_reg_contents (**arg, GREG_EXPR_SRC);
        }
        if (**arg != NUL)
            ++*arg;
        break;
    case '(' :
        *arg = skipwhite (*arg + 1);
        ret = eval1 (arg, rettv, evaluate);
        if (**arg == ')')
            ++*arg;
        else if (ret == OK) {
            EMSG (_ ("E110: Missing ')'"));
            clear_tv (rettv);
            ret = FAIL;
        }
        break;
    default :
        ret = NOTDONE;
        break;
    }
    if (ret == NOTDONE) {
        s = *arg;
        len = get_name_len (arg, &alias, evaluate, TRUE);
        if (alias != NULL)
            s = alias;
        if (len <= 0)
            ret = FAIL;
        else {
            if (**arg == '(') {
                partial_T *partial;
                if (!evaluate)
                    check_vars (s, len);
                s = deref_func_name (s, &len, &partial, !evaluate);
                s = vim_strsave (s);
                if (s == NULL)
                    ret = FAIL;
                else
                    ret = get_func_tv (s, len, rettv, arg, curwin->w_cursor.lnum, curwin->w_cursor.lnum, &len, evaluate, partial, NULL);
                vim_free (s);
                if (rettv->v_type == VAR_UNKNOWN && !evaluate && **arg == '(') {
                    rettv->vval.v_string = NULL;
                    rettv->v_type = VAR_FUNC;
                }
                if (aborting ()) {
                    if (ret == OK)
                        clear_tv (rettv);
                    ret = FAIL;
                }
            }
            else if (evaluate)
                ret = get_var_tv (s, len, rettv, NULL, TRUE, FALSE);
            else {
                check_vars (s, len);
                ret = OK;
            }
        }
        vim_free (alias);
    }
    *arg = skipwhite (*arg);
    if (ret == OK)
        ret = handle_subscript (arg, rettv, evaluate, TRUE);
    if (ret == OK && evaluate && end_leader > start_leader) {
        int error = FALSE;
        varnumber_T val = 0;
        float_T f = 0.0;
        if (rettv->v_type == VAR_FLOAT)
            f = rettv->vval.v_float;
        else
            val = get_tv_number_chk (rettv, &error);
        if (error) {
            clear_tv (rettv);
            ret = FAIL;
        }
        else {
            while (end_leader > start_leader) {
                --end_leader;
                if (*end_leader == '!') {
                    if (rettv->v_type == VAR_FLOAT)
                        f = !f;
                    else
                        val = !val;
                }
                else if (*end_leader == '-') {
                    if (rettv->v_type == VAR_FLOAT)
                        f = -f;
                    else
                        val = -val;
                }
            }
            if (rettv->v_type == VAR_FLOAT) {
                clear_tv (rettv);
                rettv->vval.v_float = f;
            }
            else {
                clear_tv (rettv);
                rettv->v_type = VAR_NUMBER;
                rettv->vval.v_number = val;
            }
        }
    }
    return ret;
}

int string2float (char_u *text, float_T *value) {
    char *s = (char *) text;
    float_T f;
    if (STRNICMP (text, "inf", 3) == 0) {
        *value = INFINITY;
        return 3;
    }
    if (STRNICMP (text, "-inf", 3) == 0) {
        *value = -INFINITY;
        return 4;
    }
    if (STRNICMP (text, "nan", 3) == 0) {
        *value = NAN;
        return 3;
    }
    f = strtod (s, &s);
    *value = f;
    return (int) ((char_u *) s - text);
}

static int get_string_tv (char_u **arg, typval_T *rettv, int evaluate) {
    char_u *p;
    char_u *name;
    int extra = 0;
    for (p = *arg + 1; *p != NUL && *p != '"'; MB_PTR_ADV (p)) {
        if (*p == '\\' && p[1] != NUL) {
            ++p;
            if (*p == '<')
                extra += 2;
        }
    }
    if (*p != '"') {
        EMSG2 (_ ("E114: Missing quote: %s"), * arg);
        return FAIL;
    }
    if (!evaluate) {
        *arg = p + 1;
        return OK;
    }
    name = alloc ((unsigned ) (p - *arg + extra));
    if (name == NULL)
        return FAIL;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = name;
    for (p = *arg + 1; *p != NUL && *p != '"';) {
        if (*p == '\\') {
            switch (*++p) {
            case 'b' :
                *name++ = BS;
                ++p;
                break;
            case 'e' :
                *name++ = ESC;
                ++p;
                break;
            case 'f' :
                *name++ = FF;
                ++p;
                break;
            case 'n' :
                *name++ = NL;
                ++p;
                break;
            case 'r' :
                *name++ = CAR;
                ++p;
                break;
            case 't' :
                *name++ = TAB;
                ++p;
                break;
            case 'X' :
            case 'x' :
            case 'u' :
            case 'U' :
                if (vim_isxdigit (p[1])) {
                    int n, nr;
                    int c = toupper (*p);
                    if (c == 'X')
                        n = 2;
                    else if (*p == 'u')
                        n = 4;
                    else
                        n = 8;
                    nr = 0;
                    while (--n >= 0 && vim_isxdigit (p[1])) {
                        ++p;
                        nr = (nr << 4) + hex2nr (*p);
                    }
                    ++p;
                    *name++ = nr;
                }
                break;
            case '0' :
            case '1' :
            case '2' :
            case '3' :
            case '4' :
            case '5' :
            case '6' :
            case '7' :
                *name = *p++ - '0';
                if (*p >= '0' && *p <= '7') {
                    *name = (*name << 3) + *p++ - '0';
                    if (*p >= '0' && *p <= '7')
                        *name = (*name << 3) + *p++ - '0';
                }
                ++name;
                break;
            case '<' :
                extra = trans_special (&p, name, TRUE, TRUE);
                if (extra != 0) {
                    name += extra;
                    break;
                }
            default :
                MB_COPY_CHAR (p, name);
                break;
            }
        }
        else
            MB_COPY_CHAR (p, name);
    }
    *name = NUL;
    if (*p != NUL)
        ++p;
    *arg = p;
    return OK;
}

static int get_lit_string_tv (char_u **arg, typval_T *rettv, int evaluate) {
    char_u *p;
    char_u *str;
    int reduce = 0;
    for (p = *arg + 1; *p != NUL; MB_PTR_ADV (p)) {
        if (*p == '\'') {
            if (p[1] != '\'')
                break;
            ++reduce;
            ++p;
        }
    }
    if (*p != '\'') {
        EMSG2 (_ ("E115: Missing quote: %s"), * arg);
        return FAIL;
    }
    if (!evaluate) {
        *arg = p + 1;
        return OK;
    }
    str = alloc ((unsigned ) ((p - *arg) - reduce));
    if (str == NULL)
        return FAIL;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = str;
    for (p = *arg + 1; *p != NUL;) {
        if (*p == '\'') {
            if (p[1] != '\'')
                break;
            ++p;
        }
        MB_COPY_CHAR (p, str);
    }
    *str = NUL;
    *arg = p + 1;
    return OK;
}

void clear_tv (typval_T *varp) {
    if (varp != NULL) {
        switch (varp->v_type) {
        case VAR_FUNC :
            func_unref (varp->vval.v_string);
        case VAR_STRING :
            VIM_CLEAR (varp->vval.v_string);
            break;
        case VAR_PARTIAL :
            partial_unref (varp->vval.v_partial);
            varp->vval.v_partial = NULL;
            break;
        case VAR_LIST :
            list_unref (varp->vval.v_list);
            varp->vval.v_list = NULL;
            break;
        case VAR_DICT :
            dict_unref (varp->vval.v_dict);
            varp->vval.v_dict = NULL;
            break;
        case VAR_NUMBER :
        case VAR_SPECIAL :
            varp->vval.v_number = 0;
            break;
        case VAR_FLOAT :
            varp->vval.v_float = 0.0;
            break;
        case VAR_JOB :
            job_unref (varp->vval.v_job);
            varp->vval.v_job = NULL;
            break;
        case VAR_CHANNEL :
            channel_unref (varp->vval.v_channel);
            varp->vval.v_channel = NULL;
        case VAR_UNKNOWN :
            break;
        }
        varp->v_lock = 0;
    }
}

void vars_clear_ext (hashtab_T *ht, int free_val) {
    int todo;
    hashitem_T *hi;
    dictitem_T *v;
    hash_lock (ht);
    todo = (int) ht->ht_used;
    for (hi = ht->ht_array; todo > 0; ++hi) {
        if (!HASHITEM_EMPTY (hi)) {
            --todo;
            v = HI2DI (hi);
            if (free_val)
                clear_tv (&v->di_tv);
            if (v->di_flags & DI_FLAGS_ALLOC)
                vim_free (v);
        }
    }
    hash_clear (ht);
    ht->ht_used = 0;
}

void vars_clear (hashtab_T *ht) {
    vars_clear_ext (ht, TRUE);
}

void partial_unref (partial_T *pt) {
    if (pt != NULL && --pt->pt_refcount <= 0)
        partial_free (pt);
}

static void partial_free (partial_T *pt) {
    int i;
    for (i = 0; i < pt->pt_argc; ++i)
        clear_tv (&pt->pt_argv[i]);
    vim_free (pt -> pt_argv);
    dict_unref (pt -> pt_dict);
    if (pt->pt_name != NULL) {
        func_unref (pt -> pt_name);
        vim_free (pt -> pt_name);
    }
    else
        func_ptr_unref (pt->pt_func);
    vim_free (pt);
}

varnumber_T get_tv_number_chk (typval_T *varp, int *denote) {
    varnumber_T n = 0L;
    switch (varp->v_type) {
    case VAR_NUMBER :
        return varp->vval.v_number;
    case VAR_FLOAT :
        EMSG (_ ("E805: Using a Float as a Number"));
        break;
    case VAR_FUNC :
    case VAR_PARTIAL :
        EMSG (_ ("E703: Using a Funcref as a Number"));
        break;
    case VAR_STRING :
        if (varp->vval.v_string != NULL)
            vim_str2nr (varp->vval.v_string, NULL, NULL, STR2NR_ALL, &n, NULL, 0);
        return n;
    case VAR_LIST :
        EMSG (_ ("E745: Using a List as a Number"));
        break;
    case VAR_DICT :
        EMSG (_ ("E728: Using a Dictionary as a Number"));
        break;
    case VAR_SPECIAL :
        return varp->vval.v_number == VVAL_TRUE ? 1 : 0;
        break;
    case VAR_JOB :
        EMSG (_ ("E910: Using a Job as a Number"));
        break;
    case VAR_CHANNEL :
        EMSG (_ ("E913: Using a Channel as a Number"));
        break;
    case VAR_UNKNOWN :
        internal_error ("get_tv_number(UNKNOWN)");
        break;
    }
    if (denote == NULL)
        n = -1;
    else
        *denote = TRUE;
    return n;
}

char_u *echo_string (typval_T *tv, char_u **tofree, char_u *numbuf, int copyID) {
    return echo_string_core (tv, tofree, numbuf, copyID, TRUE, FALSE, FALSE);
}

char_u *echo_string_core (typval_T *tv, char_u **tofree, char_u *numbuf, int copyID, int echo_style, int restore_copyID, int composite_val) {
    static int recurse = 0;
    char_u *r = NULL;
    if (recurse >= DICT_MAXNEST) {
        if (!did_echo_string_emsg) {
            did_echo_string_emsg = TRUE;
            EMSG (_ ("E724: variable nested too deep for displaying"));
        }
        *tofree = NULL;
        return (char_u *) "{E724}";
    }
    ++recurse;
    switch (tv->v_type) {
    case VAR_STRING :
        if (echo_style && !composite_val) {
            *tofree = NULL;
            r = tv->vval.v_string;
            if (r == NULL)
                r = (char_u *) "";
        }
        else {
            *tofree = string_quote (tv->vval.v_string, FALSE);
            r = *tofree;
        }
        break;
    case VAR_FUNC :
        if (echo_style) {
            *tofree = NULL;
            r = tv->vval.v_string;
        }
        else {
            *tofree = string_quote (tv->vval.v_string, TRUE);
            r = *tofree;
        }
        break;
    case VAR_PARTIAL :
        {
            partial_T *pt = tv->vval.v_partial;
            char_u *fname = string_quote (pt == NULL ? NULL : partial_name (pt), FALSE);
            garray_T ga;
            int i;
            char_u *tf;
            ga_init2 (& ga, 1, 100);
            ga_concat (& ga, (char_u *) "function(");
            if (fname != NULL) {
                ga_concat (& ga, fname);
                vim_free (fname);
            }
            if (pt != NULL && pt->pt_argc > 0) {
                ga_concat (& ga, (char_u *) ", [");
                for (i = 0; i < pt->pt_argc; ++i) {
                    if (i > 0)
                        ga_concat (&ga, (char_u *) ", ");
                    ga_concat (& ga, tv2string (& pt -> pt_argv [i], & tf, numbuf, copyID));
                    vim_free (tf);
                }
                ga_concat (& ga, (char_u *) "]");
            }
            if (pt != NULL && pt->pt_dict != NULL) {
                typval_T dtv;
                ga_concat (& ga, (char_u *) ", ");
                dtv.v_type = VAR_DICT;
                dtv.vval.v_dict = pt->pt_dict;
                ga_concat (& ga, tv2string (& dtv, & tf, numbuf, copyID));
                vim_free (tf);
            }
            ga_concat (& ga, (char_u *) ")");
            *tofree = ga.ga_data;
            r = *tofree;
            break;
        }
    case VAR_LIST :
        if (tv->vval.v_list == NULL) {
            *tofree = NULL;
            r = NULL;
        }
        else if (copyID != 0 && tv->vval.v_list->lv_copyID == copyID && tv->vval.v_list->lv_len > 0) {
            *tofree = NULL;
            r = (char_u *) "[...]";
        }
        else {
            int old_copyID = tv->vval.v_list->lv_copyID;
            tv->vval.v_list->lv_copyID = copyID;
            *tofree = list2string (tv, copyID, restore_copyID);
            if (restore_copyID)
                tv->vval.v_list->lv_copyID = old_copyID;
            r = *tofree;
        }
        break;
    case VAR_DICT :
        if (tv->vval.v_dict == NULL) {
            *tofree = NULL;
            r = NULL;
        }
        else if (copyID != 0 && tv->vval.v_dict->dv_copyID == copyID && tv->vval.v_dict->dv_hashtab.ht_used != 0) {
            *tofree = NULL;
            r = (char_u *) "{...}";
        }
        else {
            int old_copyID = tv->vval.v_dict->dv_copyID;
            tv->vval.v_dict->dv_copyID = copyID;
            *tofree = dict2string (tv, copyID, restore_copyID);
            if (restore_copyID)
                tv->vval.v_dict->dv_copyID = old_copyID;
            r = *tofree;
        }
        break;
    case VAR_NUMBER :
    case VAR_UNKNOWN :
        *tofree = NULL;
        r = get_tv_string_buf (tv, numbuf);
        break;
    case VAR_JOB :
    case VAR_CHANNEL :
        *tofree = NULL;
        r = get_tv_string_buf (tv, numbuf);
        if (composite_val) {
            *tofree = string_quote (r, FALSE);
            r = *tofree;
        }
        break;
    case VAR_FLOAT :
        *tofree = NULL;
        vim_snprintf ((char *) numbuf, NUMBUFLEN, "%g", tv -> vval.v_float);
        r = numbuf;
        break;
    case VAR_SPECIAL :
        *tofree = NULL;
        r = (char_u *) get_var_special_name (tv->vval.v_number);
        break;
    }
    if (--recurse == 0)
        did_echo_string_emsg = FALSE;
    return r;
}

char_u *string_quote (char_u *str, int function) {
    unsigned  len;
    char_u *p, *r, *s;
    len = (function ? 13 : 3);
    if (str != NULL) {
        len += (unsigned ) STRLEN (str);
        for (p = str; *p != NUL; MB_PTR_ADV (p))
            if (*p == '\'')
                ++len;
    }
    s = r = alloc (len);
    if (r != NULL) {
        if (function) {
            STRCPY (r, "function('");
            r += 10;
        }
        else
            *r++ = '\'';
        if (str != NULL)
            for (p = str; *p != NUL;) {
                if (*p == '\'')
                    *r++ = '\'';
                MB_COPY_CHAR (p, r);
            }
        *r++ = '\'';
        if (function)
            *r++ = ')';
        *r++ = NUL;
    }
    return s;
}

char_u *partial_name (partial_T *pt) {
    if (pt->pt_name != NULL)
        return pt->pt_name;
    return pt->pt_func->uf_name;
}

char_u *tv2string (typval_T *tv, char_u **tofree, char_u *numbuf, int copyID) {
    return echo_string_core (tv, tofree, numbuf, copyID, FALSE, TRUE, FALSE);
}

char_u *get_tv_string_buf (typval_T *varp, char_u *buf) {
    char_u *res = get_tv_string_buf_chk (varp, buf);
    return res != NULL ? res : (char_u *) "";
}

char_u *get_tv_string_buf_chk (typval_T *varp, char_u *buf) {
    switch (varp->v_type) {
    case VAR_NUMBER :
        vim_snprintf ((char *) buf, NUMBUFLEN, "%lld", (varnumber_T) varp->vval.v_number);
        return buf;
    case VAR_FUNC :
    case VAR_PARTIAL :
        EMSG (_ ("E729: using Funcref as a String"));
        break;
    case VAR_LIST :
        EMSG (_ ("E730: using List as a String"));
        break;
    case VAR_DICT :
        EMSG (_ ("E731: using Dictionary as a String"));
        break;
    case VAR_FLOAT :
        EMSG (_ (e_float_as_string));
        break;
    case VAR_STRING :
        if (varp->vval.v_string != NULL)
            return varp->vval.v_string;
        return (char_u *) "";
    case VAR_SPECIAL :
        STRCPY (buf, get_var_special_name (varp->vval.v_number));
        return buf;
    case VAR_JOB :
        {
            job_T *job = varp->vval.v_job;
            char *status;
            if (job == NULL)
                return (char_u *) "no process";
            status = job->jv_status == JOB_FAILED ? "fail" : job->jv_status >= JOB_ENDED ? "dead" : "run";
            vim_snprintf ((char *) buf, NUMBUFLEN, "process %ld %s", (long) job -> jv_pid, status);
            return buf;
        }
        break;
    case VAR_CHANNEL :
        {
            channel_T *channel = varp->vval.v_channel;
            char *status = channel_status (channel, -1);
            if (channel == NULL)
                vim_snprintf ((char *) buf, NUMBUFLEN, "channel %s", status);
            else
                vim_snprintf ((char *) buf, NUMBUFLEN, "channel %d %s", channel->ch_id, status);
            return buf;
        }
        break;
    case VAR_UNKNOWN :
        EMSG (_ ("E908: using an invalid value as a String"));
        break;
    }
    return NULL;
}

static char *get_var_special_name (int nr) {
    switch (nr) {
    case VVAL_FALSE :
        return "v:false";
    case VVAL_TRUE :
        return "v:true";
    case VVAL_NONE :
        return "v:none";
    case VVAL_NULL :
        return "v:null";
    }
    internal_error ("get_var_special_name()");
    return "42";
}

int get_copyID (void) {
    current_copyID += COPYID_INC;
    return current_copyID;
}

char_u *get_tv_string_chk (typval_T *varp) {
    static char_u mybuf [NUMBUFLEN];
    return get_tv_string_buf_chk (varp, mybuf);
}

void set_vim_var_string (int idx, char_u *val, int len) {
    clear_tv (& vimvars [idx].vv_di.di_tv);
    vimvars[idx].vv_type = VAR_STRING;
    if (val == NULL)
        vimvars[idx].vv_str = NULL;
    else if (len == -1)
        vimvars[idx].vv_str = vim_strsave (val);
    else
        vimvars[idx].vv_str = vim_strnsave (val, len);
}

void eval_diff (char_u *origfile, char_u *newfile, char_u *outfile) {
    int err = FALSE;
    set_vim_var_string (VV_FNAME_IN, origfile, - 1);
    set_vim_var_string (VV_FNAME_NEW, newfile, - 1);
    set_vim_var_string (VV_FNAME_OUT, outfile, - 1);
    (void) eval_to_bool (p_dex, &err, NULL, FALSE);
    set_vim_var_string (VV_FNAME_IN, NULL, - 1);
    set_vim_var_string (VV_FNAME_NEW, NULL, - 1);
    set_vim_var_string (VV_FNAME_OUT, NULL, - 1);
}

int eval_to_bool (char_u *arg, int *error, char_u **nextcmd, int skip) {
    typval_T tv;
    varnumber_T retval = FALSE;
    if (skip)
        ++emsg_skip;
    if (eval0 (arg, &tv, nextcmd, !skip) == FAIL)
        *error = TRUE;
    else {
        *error = FALSE;
        if (!skip) {
            retval = (get_tv_number_chk (&tv, error) != 0);
            clear_tv (& tv);
        }
    }
    if (skip)
        --emsg_skip;
    return (int) retval;
}

int eval0 (char_u *arg, typval_T *rettv, char_u **nextcmd, int evaluate) {
    int ret;
    char_u *p;
    p = skipwhite (arg);
    ret = eval1 (&p, rettv, evaluate);
    if (ret == FAIL || !ends_excmd (*p)) {
        if (ret != FAIL)
            clear_tv (rettv);
        if (!aborting ())
            EMSG2 (_ (e_invexpr2), arg);
        ret = FAIL;
    }
    if (nextcmd != NULL)
        *nextcmd = check_nextcmd (p);
    return ret;
}

char_u *get_vim_var_str (int idx) {
    return get_tv_string (&vimvars[idx].vv_tv);
}

char_u *get_tv_string (typval_T *varp) {
    static char_u mybuf [NUMBUFLEN];
    return get_tv_string_buf (varp, mybuf);
}

void copy_tv (typval_T *from, typval_T *to) {
    to->v_type = from->v_type;
    to->v_lock = 0;
    switch (from->v_type) {
    case VAR_NUMBER :
    case VAR_SPECIAL :
        to->vval.v_number = from->vval.v_number;
        break;
    case VAR_FLOAT :
        to->vval.v_float = from->vval.v_float;
        break;
    case VAR_JOB :
        to->vval.v_job = from->vval.v_job;
        if (to->vval.v_job != NULL)
            ++to->vval.v_job->jv_refcount;
        break;
    case VAR_CHANNEL :
        to->vval.v_channel = from->vval.v_channel;
        if (to->vval.v_channel != NULL)
            ++to->vval.v_channel->ch_refcount;
        break;
    case VAR_STRING :
    case VAR_FUNC :
        if (from->vval.v_string == NULL)
            to->vval.v_string = NULL;
        else {
            to->vval.v_string = vim_strsave (from->vval.v_string);
            if (from->v_type == VAR_FUNC)
                func_ref (to->vval.v_string);
        }
        break;
    case VAR_PARTIAL :
        if (from->vval.v_partial == NULL)
            to->vval.v_partial = NULL;
        else {
            to->vval.v_partial = from->vval.v_partial;
            ++to->vval.v_partial->pt_refcount;
        }
        break;
    case VAR_LIST :
        if (from->vval.v_list == NULL)
            to->vval.v_list = NULL;
        else {
            to->vval.v_list = from->vval.v_list;
            ++to->vval.v_list->lv_refcount;
        }
        break;
    case VAR_DICT :
        if (from->vval.v_dict == NULL)
            to->vval.v_dict = NULL;
        else {
            to->vval.v_dict = from->vval.v_dict;
            ++to->vval.v_dict->dv_refcount;
        }
        break;
    case VAR_UNKNOWN :
        internal_error ("copy_tv(UNKNOWN)");
        break;
    }
}

varnumber_T get_vim_var_nr (int idx) {
    return vimvars[idx].vv_nr;
}

char_u *set_cmdarg (exarg_T *eap, char_u *oldarg) {
    char_u *oldval;
    char_u *newval;
    unsigned  len;
    oldval = vimvars[VV_CMDARG].vv_str;
    if (eap == NULL) {
        vim_free (oldval);
        vimvars[VV_CMDARG].vv_str = oldarg;
        return NULL;
    }
    if (eap->force_bin == FORCE_BIN)
        len = 6;
    else if (eap->force_bin == FORCE_NOBIN)
        len = 8;
    else
        len = 0;
    if (eap->read_edit)
        len += 7;
    if (eap->force_ff != 0)
        len += (unsigned ) STRLEN (eap->cmd + eap->force_ff) + 6;
    newval = alloc (len +1);
    if (newval == NULL)
        return NULL;
    if (eap->force_bin == FORCE_BIN)
        sprintf ((char *) newval, " ++bin");
    else if (eap->force_bin == FORCE_NOBIN)
        sprintf ((char *) newval, " ++nobin");
    else
        *newval = NUL;
    if (eap->read_edit)
        STRCAT (newval, " ++edit");
    if (eap->force_ff != 0)
        sprintf ((char *) newval + STRLEN (newval), " ++ff=%s", eap->cmd + eap->force_ff);
    vimvars[VV_CMDARG].vv_str = newval;
    return oldval;
}

void set_vim_var_nr (int idx, varnumber_T val) {
    vimvars[idx].vv_nr = val;
}

int modify_fname (char_u *src, int *usedlen, char_u **fnamep, char_u **bufp, int *fnamelen) {
    int valid = 0;
    char_u *tail;
    char_u *s, *p, *pbuf;
    char_u dirname [MAXPATHL];
    int c;
    int has_fullname = 0;
repeat :
    if (src[*usedlen] == ':' && src[*usedlen + 1] == 'p') {
        has_fullname = 1;
        valid |= VALID_PATH;
        *usedlen += 2;
        if ((*fnamep)[0] == '~') {
            *fnamep = expand_env_save (*fnamep);
            vim_free (*bufp);
            *bufp = *fnamep;
            if (*fnamep == NULL)
                return -1;
        }
        for (p = *fnamep; *p != NUL; MB_PTR_ADV (p)) {
            if (vim_ispathsep (*p) && p[1] == '.' && (p[2] == NUL || vim_ispathsep (p[2]) || (p[2] == '.' && (p[3] == NUL || vim_ispathsep (p[3])))))
                break;
        }
        if (*p != NUL || !vim_isAbsName (*fnamep)) {
            *fnamep = FullName_save (*fnamep, *p != NUL);
            vim_free (*bufp);
            *bufp = *fnamep;
            if (*fnamep == NULL)
                return -1;
        }
        if (mch_isdir (*fnamep)) {
            *fnamep = vim_strnsave (*fnamep, (int) STRLEN (*fnamep) + 2);
            vim_free (*bufp);
            *bufp = *fnamep;
            if (*fnamep == NULL)
                return -1;
            add_pathsep (*fnamep);
        }
    }
    while (src[*usedlen] == ':' && ((c = src[*usedlen + 1]) == '.' || c == '~' || c == '8')) {
        *usedlen += 2;
        if (c == '8') {
            continue;
        }
        pbuf = NULL;
        if (!has_fullname) {
            if (c == '.' && **fnamep == '~')
                p = pbuf = expand_env_save (*fnamep);
            else
                p = pbuf = FullName_save (*fnamep, FALSE);
        }
        else
            p = *fnamep;
        has_fullname = 0;
        if (p != NULL) {
            if (c == '.') {
                mch_dirname (dirname, MAXPATHL);
                s = shorten_fname (p, dirname);
                if (s != NULL) {
                    *fnamep = s;
                    if (pbuf != NULL) {
                        vim_free (*bufp);
                        *bufp = pbuf;
                        pbuf = NULL;
                    }
                }
            }
            else {
                home_replace (NULL, p, dirname, MAXPATHL, TRUE);
                if (*dirname == '~') {
                    s = vim_strsave (dirname);
                    if (s != NULL) {
                        *fnamep = s;
                        vim_free (*bufp);
                        *bufp = s;
                    }
                }
            }
            vim_free (pbuf);
        }
    }
    tail = gettail (*fnamep);
    *fnamelen = (int) STRLEN (*fnamep);
    while (src[*usedlen] == ':' && src[*usedlen + 1] == 'h') {
        valid |= VALID_HEAD;
        *usedlen += 2;
        s = get_past_head (*fnamep);
        while (tail > s && after_pathsep (s, tail))
            MB_PTR_BACK (*fnamep, tail);
        *fnamelen = (int) (tail - *fnamep);
        if (*fnamelen == 0) {
            p = vim_strsave ((char_u *) ".");
            if (p == NULL)
                return -1;
            vim_free (*bufp);
            *bufp = *fnamep = tail = p;
            *fnamelen = 1;
        }
        else {
            while (tail > s && !after_pathsep (s, tail))
                MB_PTR_BACK (*fnamep, tail);
        }
    }
    if (src[*usedlen] == ':' && src[*usedlen + 1] == '8') {
        *usedlen += 2;
    }
    if (src[*usedlen] == ':' && src[*usedlen + 1] == 't') {
        *usedlen += 2;
        *fnamelen -= (int) (tail - *fnamep);
        *fnamep = tail;
    }
    while (src[*usedlen] == ':' && (src[*usedlen + 1] == 'e' || src[*usedlen + 1] == 'r')) {
        if (src[*usedlen + 1] == 'e' && *fnamep > tail)
            s = *fnamep - 2;
        else
            s = *fnamep + *fnamelen - 1;
        for (; s > tail; --s)
            if (s[0] == '.')
                break;
        if (src[*usedlen + 1] == 'e') {
            if (s > tail) {
                *fnamelen += (int) (*fnamep - (s + 1));
                *fnamep = s + 1;
            }
            else if (*fnamep <= tail)
                *fnamelen = 0;
        }
        else {
            if (s > tail)
                *fnamelen = (int) (s - *fnamep);
        }
        *usedlen += 2;
    }
    if (src[*usedlen] == ':' && (src[*usedlen + 1] == 's' || (src[*usedlen + 1] == 'g' && src[*usedlen + 2] == 's'))) {
        char_u *str;
        char_u *pat;
        char_u *sub;
        int sep;
        char_u *flags;
        int didit = FALSE;
        flags = (char_u *) "";
        s = src + *usedlen + 2;
        if (src[*usedlen + 1] == 'g') {
            flags = (char_u *) "g";
            ++s;
        }
        sep = *s++;
        if (sep) {
            p = vim_strchr (s, sep);
            if (p != NULL) {
                pat = vim_strnsave (s, (int) (p - s));
                if (pat != NULL) {
                    s = p + 1;
                    p = vim_strchr (s, sep);
                    if (p != NULL) {
                        sub = vim_strnsave (s, (int) (p - s));
                        str = vim_strnsave (*fnamep, *fnamelen);
                        if (sub != NULL && str != NULL) {
                            *usedlen = (int) (p + 1 - src);
                            s = do_string_sub (str, pat, sub, NULL, flags);
                            if (s != NULL) {
                                *fnamep = s;
                                *fnamelen = (int) STRLEN (s);
                                vim_free (*bufp);
                                *bufp = s;
                                didit = TRUE;
                            }
                        }
                        vim_free (sub);
                        vim_free (str);
                    }
                    vim_free (pat);
                }
            }
            if (didit)
                goto repeat;
        }
    }
    if (src[*usedlen] == ':' && src[*usedlen + 1] == 'S') {
        c = (*fnamep)[*fnamelen];
        if (c != NUL)
            (*fnamep)[*fnamelen] = NUL;
        p = vim_strsave_shellescape (*fnamep, FALSE, FALSE);
        if (c != NUL)
            (*fnamep)[*fnamelen] = c;
        if (p == NULL)
            return -1;
        vim_free (*bufp);
        *bufp = *fnamep = p;
        *fnamelen = (int) STRLEN (p);
        *usedlen += 2;
    }
    return valid;
}

char_u *do_string_sub (char_u *str, char_u *pat, char_u *sub, typval_T *expr, char_u *flags) {
    int sublen;
    regmatch_T regmatch;
    int i;
    int do_all;
    char_u *tail;
    char_u *end;
    garray_T ga;
    char_u *ret;
    char_u *save_cpo;
    char_u *zero_width = NULL;
    save_cpo = p_cpo;
    p_cpo = empty_option;
    ga_init2 (& ga, 1, 200);
    do_all = (flags[0] == 'g');
    regmatch.rm_ic = p_ic;
    regmatch.regprog = vim_regcomp (pat, RE_MAGIC +RE_STRING);
    if (regmatch.regprog != NULL) {
        tail = str;
        end = str + STRLEN (str);
        while (vim_regexec_nl (&regmatch, str, (colnr_T) (tail - str))) {
            if (regmatch.startp[0] == regmatch.endp[0]) {
                if (zero_width == regmatch.startp[0]) {
                    i = MB_PTR2LEN (tail);
                    mch_memmove ((char_u *) ga.ga_data + ga.ga_len, tail, (size_t) i);
                    ga.ga_len += i;
                    tail += i;
                    continue;
                }
                zero_width = regmatch.startp[0];
            }
            sublen = vim_regsub (&regmatch, sub, expr, tail, FALSE, TRUE, FALSE);
            if (ga_grow (&ga, (int) ((end - tail) + sublen - (regmatch.endp[0] - regmatch.startp[0]))) == FAIL) {
                ga_clear (& ga);
                break;
            }
            i = (int) (regmatch.startp[0] - tail);
            mch_memmove ((char_u *) ga.ga_data + ga.ga_len, tail, (size_t) i);
            (void) vim_regsub (&regmatch, sub, expr, (char_u *) ga.ga_data + ga.ga_len + i, TRUE, TRUE, FALSE);
            ga.ga_len += i + sublen - 1;
            tail = regmatch.endp[0];
            if (*tail == NUL)
                break;
            if (!do_all)
                break;
        }
        if (ga.ga_data != NULL)
            STRCPY ((char *) ga.ga_data + ga.ga_len, tail);
        vim_regfree (regmatch.regprog);
    }
    ret = vim_strsave (ga.ga_data == NULL ? str : (char_u *) ga.ga_data);
    ga_clear (& ga);
    if (p_cpo == empty_option)
        p_cpo = save_cpo;
    else
        free_string_option (save_cpo);
    return ret;
}

char_u *eval_to_string (char_u *arg, char_u **nextcmd, int convert) {
    typval_T tv;
    char_u *retval;
    garray_T ga;
    char_u numbuf [NUMBUFLEN];
    if (eval0 (arg, &tv, nextcmd, TRUE) == FAIL)
        retval = NULL;
    else {
        if (convert && tv.v_type == VAR_LIST) {
            ga_init2 (& ga, (int) sizeof (char), 80);
            if (tv.vval.v_list != NULL) {
                list_join (& ga, tv.vval.v_list, (char_u *) "\n", TRUE, FALSE, 0);
                if (tv.vval.v_list->lv_len > 0)
                    ga_append (&ga, NL);
            }
            ga_append (& ga, NUL);
            retval = (char_u *) ga.ga_data;
        }
        else if (convert && tv.v_type == VAR_FLOAT) {
            vim_snprintf ((char *) numbuf, NUMBUFLEN, "%g", tv.vval.v_float);
            retval = vim_strsave (numbuf);
        }
        else
            retval = vim_strsave (get_tv_string (&tv));
        clear_tv (& tv);
    }
    return retval;
}

void free_tv (typval_T *varp) {
    if (varp != NULL) {
        switch (varp->v_type) {
        case VAR_FUNC :
            func_unref (varp->vval.v_string);
        case VAR_STRING :
            vim_free (varp->vval.v_string);
            break;
        case VAR_PARTIAL :
            partial_unref (varp->vval.v_partial);
            break;
        case VAR_LIST :
            list_unref (varp->vval.v_list);
            break;
        case VAR_DICT :
            dict_unref (varp->vval.v_dict);
            break;
        case VAR_JOB :
            job_unref (varp->vval.v_job);
            break;
        case VAR_CHANNEL :
            channel_unref (varp->vval.v_channel);
            break;
        case VAR_NUMBER :
        case VAR_FLOAT :
        case VAR_UNKNOWN :
        case VAR_SPECIAL :
            break;
        }
        vim_free (varp);
    }
}

char_u *eval_to_string_safe (char_u *arg, char_u **nextcmd, int use_sandbox) {
    char_u *retval;
    void *save_funccalp;
    save_funccalp = save_funccal ();
    if (use_sandbox)
        ++sandbox;
    ++textlock;
    retval = eval_to_string (arg, nextcmd, FALSE);
    if (use_sandbox)
        --sandbox;
    --textlock;
    restore_funccal (save_funccalp);
    return retval;
}

void set_internal_string_var (char_u *name, char_u *value) {
    char_u *val;
    typval_T *tvp;
    val = vim_strsave (value);
    if (val != NULL) {
        tvp = alloc_string_tv (val);
        if (tvp != NULL) {
            set_var (name, tvp, FALSE);
            free_tv (tvp);
        }
    }
}

static typval_T *alloc_string_tv (char_u *s) {
    typval_T *rettv;
    rettv = alloc_tv ();
    if (rettv != NULL) {
        rettv->v_type = VAR_STRING;
        rettv->vval.v_string = s;
    }
    else
        vim_free (s);
    return rettv;
}

typval_T *alloc_tv (void) {
    return (typval_T *) alloc_clear ((unsigned ) sizeof (typval_T));
}

void set_var (char_u *name, typval_T *tv, int copy) {
    dictitem_T *v;
    char_u *varname;
    hashtab_T *ht;
    ht = find_var_ht (name, &varname);
    if (ht == NULL || *varname == NUL) {
        EMSG2 (_ (e_illvar), name);
        return;
    }
    v = find_var_in_ht (ht, 0, varname, TRUE);
    if (v == NULL)
        v = find_var_in_scoped_ht (name, TRUE);
    if ((tv->v_type == VAR_FUNC || tv->v_type == VAR_PARTIAL) && var_check_func_name (name, v == NULL))
        return;
    if (v != NULL) {
        if (var_check_ro (v->di_flags, name, FALSE) || tv_check_lock (v->di_tv.v_lock, name, FALSE))
            return;
        if (ht == &vimvarht) {
            if (v->di_tv.v_type == VAR_STRING) {
                vim_free (v -> di_tv.vval.v_string);
                if (copy || tv->v_type != VAR_STRING)
                    v->di_tv.vval.v_string = vim_strsave (get_tv_string (tv));
                else {
                    v->di_tv.vval.v_string = tv->vval.v_string;
                    tv->vval.v_string = NULL;
                }
                return;
            }
            else if (v->di_tv.v_type == VAR_NUMBER) {
                v->di_tv.vval.v_number = get_tv_number (tv);
                if (STRCMP (varname, "searchforward") == 0)
                    set_search_direction (v->di_tv.vval.v_number ? '/' : '?');
                else if (STRCMP (varname, "hlsearch") == 0) {
                    no_hlsearch = !v->di_tv.vval.v_number;
                    redraw_all_later (SOME_VALID);
                }
                return;
            }
            else if (v->di_tv.v_type != tv->v_type)
                internal_error ("set_var()");
        }
        clear_tv (& v -> di_tv);
    }
    else {
        if (ht == &vimvarht) {
            EMSG2 (_ (e_illvar), name);
            return;
        }
        if (!valid_varname (varname))
            return;
        v = (dictitem_T *) alloc ((unsigned ) (sizeof (dictitem_T) + STRLEN (varname)));
        if (v == NULL)
            return;
        STRCPY (v -> di_key, varname);
        if (hash_add (ht, DI2HIKEY (v)) == FAIL) {
            vim_free (v);
            return;
        }
        v->di_flags = DI_FLAGS_ALLOC;
    }
    if (copy || tv->v_type == VAR_NUMBER || tv->v_type == VAR_FLOAT)
        copy_tv (tv, &v->di_tv);
    else {
        v->di_tv = *tv;
        v->di_tv.v_lock = 0;
        init_tv (tv);
    }
}

hashtab_T *find_var_ht (char_u *name, char_u **varname) {
    hashitem_T *hi;
    hashtab_T *ht;
    if (name[0] == NUL)
        return NULL;
    if (name[1] != ':') {
        if (name[0] == ':' || name[0] == AUTOLOAD_CHAR)
            return NULL;
        *varname = name;
        hi = hash_find (&compat_hashtab, name);
        if (!HASHITEM_EMPTY (hi))
            return &compat_hashtab;
        ht = get_funccal_local_ht ();
        if (ht == NULL)
            return &globvarht;
        return ht;
    }
    *varname = name + 2;
    if (*name == 'g')
        return &globvarht;
    if (vim_strchr (name +2, ':') != NULL || vim_strchr (name +2, AUTOLOAD_CHAR) != NULL)
        return NULL;
    if (*name == 'b')
        return &curbuf->b_vars->dv_hashtab;
    if (*name == 'w')
        return &curwin->w_vars->dv_hashtab;
    if (*name == 't')
        return &curtab->tp_vars->dv_hashtab;
    if (*name == 'v')
        return &vimvarht;
    if (*name == 'a')
        return get_funccal_args_ht ();
    if (*name == 'l')
        return get_funccal_local_ht ();
    if (*name == 's' && current_SID > 0 && current_SID <= ga_scripts.ga_len)
        return &SCRIPT_VARS (current_SID);
    return NULL;
}

dictitem_T *find_var_in_ht (hashtab_T *ht, int htname, char_u *varname, int no_autoload) {
    hashitem_T *hi;
    if (*varname == NUL) {
        switch (htname) {
        case 's' :
            return &SCRIPT_SV (current_SID)->sv_var;
        case 'g' :
            return &globvars_var;
        case 'v' :
            return &vimvars_var;
        case 'b' :
            return &curbuf->b_bufvar;
        case 'w' :
            return &curwin->w_winvar;
        case 't' :
            return &curtab->tp_winvar;
        case 'l' :
            return get_funccal_local_var ();
        case 'a' :
            return get_funccal_args_var ();
        }
        return NULL;
    }
    hi = hash_find (ht, varname);
    if (HASHITEM_EMPTY (hi)) {
        if (ht == &globvarht && !no_autoload) {
            if (!script_autoload (varname, FALSE) || aborting ())
                return NULL;
            hi = hash_find (ht, varname);
        }
        if (HASHITEM_EMPTY (hi))
            return NULL;
    }
    return HI2DI (hi);
}

int script_autoload (char_u *name, int reload) {
    char_u *p;
    char_u *scriptname, *tofree;
    int ret = FALSE;
    int i;
    p = vim_strchr (name, AUTOLOAD_CHAR);
    if (p == NULL || p == name)
        return FALSE;
    tofree = scriptname = autoload_name (name);
    for (i = 0; i < ga_loaded.ga_len; ++i)
        if (STRCMP (((char_u **) ga_loaded.ga_data)[i] + 9, scriptname +9) == 0)
            break;
    if (!reload && i < ga_loaded.ga_len)
        ret = FALSE;
    else {
        if (i == ga_loaded.ga_len && ga_grow (&ga_loaded, 1) == OK) {
            ((char_u **) ga_loaded.ga_data)[ga_loaded.ga_len++] = scriptname;
            tofree = NULL;
        }
        if (source_runtime (scriptname, 0) == OK)
            ret = TRUE;
    }
    vim_free (tofree);
    return ret;
}

char_u *autoload_name (char_u *name) {
    char_u *p;
    char_u *scriptname;
    scriptname = alloc ((unsigned ) (STRLEN (name) + 14));
    if (scriptname == NULL)
        return FALSE;
    STRCPY (scriptname, "autoload/");
    STRCAT (scriptname, name);
    *vim_strrchr (scriptname, AUTOLOAD_CHAR) = NUL;
    STRCAT (scriptname, ".vim");
    while ((p = vim_strchr (scriptname, AUTOLOAD_CHAR)) != NULL)
        *p = '/';
    return scriptname;
}

int garbage_collect (int testing) {
    int copyID;
    int abort = FALSE;
    buf_T *buf;
    win_T *wp;
    int i;
    int did_free = FALSE;
    tabpage_T *tp;
    if (!testing) {
        want_garbage_collect = FALSE;
        may_garbage_collect = FALSE;
        garbage_collect_at_exit = FALSE;
    }
    copyID = get_copyID ();
    abort = abort || set_ref_in_previous_funccal (copyID);
    for (i = 1; i <= ga_scripts.ga_len; ++i)
        abort = abort || set_ref_in_ht (&SCRIPT_VARS (i), copyID, NULL);
    FOR_ALL_BUFFERS (buf)
        abort = abort || set_ref_in_item (&buf->b_bufvar.di_tv, copyID, NULL, NULL);
    FOR_ALL_TAB_WINDOWS (tp, wp)
        abort = abort || set_ref_in_item (&wp->w_winvar.di_tv, copyID, NULL, NULL);
    if (aucmd_win != NULL)
        abort = abort || set_ref_in_item (&aucmd_win->w_winvar.di_tv, copyID, NULL, NULL);
    FOR_ALL_TABPAGES (tp)
        abort = abort || set_ref_in_item (&tp->tp_winvar.di_tv, copyID, NULL, NULL);
    abort = abort || set_ref_in_ht (&globvarht, copyID, NULL);
    abort = abort || set_ref_in_call_stack (copyID);
    abort = abort || set_ref_in_functions (copyID);
    abort = abort || set_ref_in_func_args (copyID);
    abort = abort || set_ref_in_ht (&vimvarht, copyID, NULL);
    abort = abort || set_ref_in_channel (copyID);
    abort = abort || set_ref_in_job (copyID);
    abort = abort || set_ref_in_nb_channel (copyID);
    abort = abort || set_ref_in_timer (copyID);
    abort = abort || set_ref_in_quickfix (copyID);
    abort = abort || set_ref_in_term (copyID);
    if (!abort) {
        did_free = free_unref_items (copyID);
        free_unref_funccal (copyID, testing);
    }
    else if (p_verbose > 0) {
        verb_msg ((char_u *) _ ("Not enough memory to set references, garbage collection aborted!"));
    }
    return did_free;
}

int set_ref_in_ht (hashtab_T *ht, int copyID, list_stack_T **list_stack) {
    int todo;
    int abort = FALSE;
    hashitem_T *hi;
    hashtab_T *cur_ht;
    ht_stack_T *ht_stack = NULL;
    ht_stack_T *tempitem;
    cur_ht = ht;
    for (;;) {
        if (!abort) {
            todo = (int) cur_ht->ht_used;
            for (hi = cur_ht->ht_array; todo > 0; ++hi)
                if (!HASHITEM_EMPTY (hi)) {
                    --todo;
                    abort = abort || set_ref_in_item (&HI2DI (hi)->di_tv, copyID, &ht_stack, list_stack);
                }
        }
        if (ht_stack == NULL)
            break;
        cur_ht = ht_stack->ht;
        tempitem = ht_stack;
        ht_stack = ht_stack->prev;
        free (tempitem);
    }
    return abort;
}

int set_ref_in_item (typval_T *tv, int copyID, ht_stack_T **ht_stack, list_stack_T **list_stack) {
    int abort = FALSE;
    if (tv->v_type == VAR_DICT) {
        dict_T *dd = tv->vval.v_dict;
        if (dd != NULL && dd->dv_copyID != copyID) {
            dd->dv_copyID = copyID;
            if (ht_stack == NULL) {
                abort = set_ref_in_ht (&dd->dv_hashtab, copyID, list_stack);
            }
            else {
                ht_stack_T *newitem = (ht_stack_T *) malloc (sizeof (ht_stack_T));
                if (newitem == NULL)
                    abort = TRUE;
                else {
                    newitem->ht = &dd->dv_hashtab;
                    newitem->prev = *ht_stack;
                    *ht_stack = newitem;
                }
            }
        }
    }
    else if (tv->v_type == VAR_LIST) {
        list_T *ll = tv->vval.v_list;
        if (ll != NULL && ll->lv_copyID != copyID) {
            ll->lv_copyID = copyID;
            if (list_stack == NULL) {
                abort = set_ref_in_list (ll, copyID, ht_stack);
            }
            else {
                list_stack_T *newitem = (list_stack_T *) malloc (sizeof (list_stack_T));
                if (newitem == NULL)
                    abort = TRUE;
                else {
                    newitem->list = ll;
                    newitem->prev = *list_stack;
                    *list_stack = newitem;
                }
            }
        }
    }
    else if (tv->v_type == VAR_FUNC) {
        abort = set_ref_in_func (tv->vval.v_string, NULL, copyID);
    }
    else if (tv->v_type == VAR_PARTIAL) {
        partial_T *pt = tv->vval.v_partial;
        int i;
        if (pt != NULL) {
            abort = set_ref_in_func (pt->pt_name, pt->pt_func, copyID);
            if (pt->pt_dict != NULL) {
                typval_T dtv;
                dtv.v_type = VAR_DICT;
                dtv.vval.v_dict = pt->pt_dict;
                set_ref_in_item (& dtv, copyID, ht_stack, list_stack);
            }
            for (i = 0; i < pt->pt_argc; ++i)
                abort = abort || set_ref_in_item (&pt->pt_argv[i], copyID, ht_stack, list_stack);
        }
    }
    else if (tv->v_type == VAR_JOB) {
        job_T *job = tv->vval.v_job;
        typval_T dtv;
        if (job != NULL && job->jv_copyID != copyID) {
            job->jv_copyID = copyID;
            if (job->jv_channel != NULL) {
                dtv.v_type = VAR_CHANNEL;
                dtv.vval.v_channel = job->jv_channel;
                set_ref_in_item (& dtv, copyID, ht_stack, list_stack);
            }
            if (job->jv_exit_partial != NULL) {
                dtv.v_type = VAR_PARTIAL;
                dtv.vval.v_partial = job->jv_exit_partial;
                set_ref_in_item (& dtv, copyID, ht_stack, list_stack);
            }
        }
    }
    else if (tv->v_type == VAR_CHANNEL) {
        channel_T *ch = tv->vval.v_channel;
        ch_part_T part;
        typval_T dtv;
        jsonq_T *jq;
        cbq_T *cq;
        if (ch != NULL && ch->ch_copyID != copyID) {
            ch->ch_copyID = copyID;
            for (part = PART_SOCK; part < PART_COUNT; ++part) {
                for (jq = ch->ch_part[part].ch_json_head.jq_next; jq != NULL; jq = jq->jq_next)
                    set_ref_in_item (jq->jq_value, copyID, ht_stack, list_stack);
                for (cq = ch->ch_part[part].ch_cb_head.cq_next; cq != NULL; cq = cq->cq_next)
                    if (cq->cq_partial != NULL) {
                        dtv.v_type = VAR_PARTIAL;
                        dtv.vval.v_partial = cq->cq_partial;
                        set_ref_in_item (& dtv, copyID, ht_stack, list_stack);
                    }
                if (ch->ch_part[part].ch_partial != NULL) {
                    dtv.v_type = VAR_PARTIAL;
                    dtv.vval.v_partial = ch->ch_part[part].ch_partial;
                    set_ref_in_item (& dtv, copyID, ht_stack, list_stack);
                }
            }
            if (ch->ch_partial != NULL) {
                dtv.v_type = VAR_PARTIAL;
                dtv.vval.v_partial = ch->ch_partial;
                set_ref_in_item (& dtv, copyID, ht_stack, list_stack);
            }
            if (ch->ch_close_partial != NULL) {
                dtv.v_type = VAR_PARTIAL;
                dtv.vval.v_partial = ch->ch_close_partial;
                set_ref_in_item (& dtv, copyID, ht_stack, list_stack);
            }
        }
    }
    return abort;
}

int set_ref_in_list (list_T *l, int copyID, ht_stack_T **ht_stack) {
    listitem_T *li;
    int abort = FALSE;
    list_T *cur_l;
    list_stack_T *list_stack = NULL;
    list_stack_T *tempitem;
    cur_l = l;
    for (;;) {
        if (!abort)
            for (li = cur_l->lv_first; !abort && li != NULL; li = li->li_next)
                abort = abort || set_ref_in_item (&li->li_tv, copyID, ht_stack, &list_stack);
        if (list_stack == NULL)
            break;
        cur_l = list_stack->list;
        tempitem = list_stack;
        list_stack = list_stack->prev;
        free (tempitem);
    }
    return abort;
}

static int free_unref_items (int copyID) {
    int did_free = FALSE;
    in_free_unref_items = TRUE;
    did_free |= dict_free_nonref (copyID);
    did_free |= list_free_nonref (copyID);
    did_free |= free_unused_jobs_contents (copyID, COPYID_MASK);
    did_free |= free_unused_channels_contents (copyID, COPYID_MASK);
    dict_free_items (copyID);
    list_free_items (copyID);
    free_unused_jobs (copyID, COPYID_MASK);
    free_unused_channels (copyID, COPYID_MASK);
    in_free_unref_items = FALSE;
    return did_free;
}

void init_var_dict (dict_T *dict, dictitem_T *dict_var, int scope) {
    hash_init (& dict -> dv_hashtab);
    dict->dv_lock = 0;
    dict->dv_scope = scope;
    dict->dv_refcount = DO_NOT_FREE_CNT;
    dict->dv_copyID = 0;
    dict_var->di_tv.vval.v_dict = dict;
    dict_var->di_tv.v_type = VAR_DICT;
    dict_var->di_tv.v_lock = VAR_FIXED;
    dict_var->di_flags = DI_FLAGS_RO | DI_FLAGS_FIX;
    dict_var->di_key[0] = NUL;
}

void unref_var_dict (dict_T *dict) {
    dict->dv_refcount -= DO_NOT_FREE_CNT - 1;
    dict_unref (dict);
}

int read_viminfo_varlist (vir_T *virp, int writing) {
    char_u *tab;
    int type = VAR_NUMBER;
    typval_T tv;
    void *save_funccal;
    if (!writing && (find_viminfo_parameter ('!') != NULL)) {
        tab = vim_strchr (virp->vir_line + 1, '\t');
        if (tab != NULL) {
            *tab++ = '\0';
            switch (*tab) {
            case 'S' :
                type = VAR_STRING;
                break;
            case 'F' :
                type = VAR_FLOAT;
                break;
            case 'D' :
                type = VAR_DICT;
                break;
            case 'L' :
                type = VAR_LIST;
                break;
            case 'X' :
                type = VAR_SPECIAL;
                break;
            }
            tab = vim_strchr (tab, '\t');
            if (tab != NULL) {
                tv.v_type = type;
                if (type == VAR_STRING || type == VAR_DICT || type == VAR_LIST)
                    tv.vval.v_string = viminfo_readstring (virp, (int) (tab - virp->vir_line + 1), TRUE);
                else if (type == VAR_FLOAT)
                    (void) string2float (tab +1, &tv.vval.v_float);
                else
                    tv.vval.v_number = atol ((char *) tab + 1);
                if (type == VAR_DICT || type == VAR_LIST) {
                    typval_T *etv = eval_expr (tv.vval.v_string, NULL);
                    if (etv == NULL)
                        tv.v_type = VAR_STRING;
                    else {
                        vim_free (tv.vval.v_string);
                        tv = *etv;
                        vim_free (etv);
                    }
                }
                save_funccal = clear_current_funccal ();
                set_var (virp -> vir_line + 1, & tv, FALSE);
                restore_current_funccal (save_funccal);
                if (tv.v_type == VAR_STRING)
                    vim_free (tv.vval.v_string);
                else if (tv.v_type == VAR_DICT || tv.v_type == VAR_LIST)
                    clear_tv (&tv);
            }
        }
    }
    return viminfo_readline (virp);
}

typval_T *eval_expr (char_u *arg, char_u **nextcmd) {
    typval_T *tv;
    tv = (typval_T *) alloc (sizeof (typval_T));
    if (tv != NULL && eval0 (arg, tv, nextcmd, TRUE) == FAIL)
        VIM_CLEAR (tv);
    return tv;
}

void write_viminfo_varlist (FILE *fp) {
    hashitem_T *hi;
    dictitem_T *this_var;
    int todo;
    char *s = "";
    char_u *p;
    char_u *tofree;
    char_u numbuf [NUMBUFLEN];
    if (find_viminfo_parameter ('!') == NULL)
        return;
    fputs (_ ("\n# global variables:\n"), fp);
    todo = (int) globvarht.ht_used;
    for (hi = globvarht.ht_array; todo > 0; ++hi) {
        if (!HASHITEM_EMPTY (hi)) {
            --todo;
            this_var = HI2DI (hi);
            if (var_flavour (this_var->di_key) == VAR_FLAVOUR_VIMINFO) {
                switch (this_var->di_tv.v_type) {
                case VAR_STRING :
                    s = "STR";
                    break;
                case VAR_NUMBER :
                    s = "NUM";
                    break;
                case VAR_FLOAT :
                    s = "FLO";
                    break;
                case VAR_DICT :
                    s = "DIC";
                    break;
                case VAR_LIST :
                    s = "LIS";
                    break;
                case VAR_SPECIAL :
                    s = "XPL";
                    break;
                case VAR_UNKNOWN :
                case VAR_FUNC :
                case VAR_PARTIAL :
                case VAR_JOB :
                case VAR_CHANNEL :
                    continue;
                }
                fprintf (fp, "!%s\t%s\t", this_var -> di_key, s);
                p = echo_string (&this_var->di_tv, &tofree, numbuf, 0);
                if (p != NULL)
                    viminfo_writestring (fp, p);
                vim_free (tofree);
            }
        }
    }
}

static var_flavour_T var_flavour (char_u *varname) {
    char_u *p = varname;
    if (ASCII_ISUPPER (*p)) {
        while (*(++p))
            if (ASCII_ISLOWER (*p))
                return VAR_FLAVOUR_SESSION;
        return VAR_FLAVOUR_VIMINFO;
    }
    else
        return VAR_FLAVOUR_DEFAULT;
}

void set_vim_var_list (int idx, list_T *val) {
    clear_tv (& vimvars [idx].vv_di.di_tv);
    vimvars[idx].vv_type = VAR_LIST;
    vimvars[idx].vv_list = val;
    if (val != NULL)
        ++val->lv_refcount;
}

char_u *typval_tostring (arg)
    typval_T *arg;
{
    char_u *tofree;
    char_u numbuf [NUMBUFLEN];
    char_u *ret = NULL;
    if (arg == NULL)
        return vim_strsave ((char_u *) "(does not exist)");
    ret = tv2string (arg, &tofree, numbuf, 0);
    if (ret != NULL && tofree == NULL)
        ret = vim_strsave (ret);
    return ret;
}

int typval_compare (typval_T *typ1, typval_T *typ2, exptype_T type, int type_is, int ic) {
    int i;
    varnumber_T n1, n2;
    char_u *s1, *s2;
    char_u buf1 [NUMBUFLEN], buf2 [NUMBUFLEN];
    if (type_is && typ1->v_type != typ2->v_type) {
        n1 = (type == TYPE_NEQUAL);
    }
    else if (typ1->v_type == VAR_LIST || typ2->v_type == VAR_LIST) {
        if (type_is) {
            n1 = (typ1->v_type == typ2->v_type && typ1->vval.v_list == typ2->vval.v_list);
            if (type == TYPE_NEQUAL)
                n1 = !n1;
        }
        else if (typ1->v_type != typ2->v_type || (type != TYPE_EQUAL && type != TYPE_NEQUAL)) {
            if (typ1->v_type != typ2->v_type)
                EMSG (_ ("E691: Can only compare List with List"));
            else
                EMSG (_ ("E692: Invalid operation for List"));
            clear_tv (typ1);
            return FAIL;
        }
        else {
            n1 = list_equal (typ1->vval.v_list, typ2->vval.v_list, ic, FALSE);
            if (type == TYPE_NEQUAL)
                n1 = !n1;
        }
    }
    else if (typ1->v_type == VAR_DICT || typ2->v_type == VAR_DICT) {
        if (type_is) {
            n1 = (typ1->v_type == typ2->v_type && typ1->vval.v_dict == typ2->vval.v_dict);
            if (type == TYPE_NEQUAL)
                n1 = !n1;
        }
        else if (typ1->v_type != typ2->v_type || (type != TYPE_EQUAL && type != TYPE_NEQUAL)) {
            if (typ1->v_type != typ2->v_type)
                EMSG (_ ("E735: Can only compare Dictionary with Dictionary"));
            else
                EMSG (_ ("E736: Invalid operation for Dictionary"));
            clear_tv (typ1);
            return FAIL;
        }
        else {
            n1 = dict_equal (typ1->vval.v_dict, typ2->vval.v_dict, ic, FALSE);
            if (type == TYPE_NEQUAL)
                n1 = !n1;
        }
    }
    else if (typ1->v_type == VAR_FUNC || typ2->v_type == VAR_FUNC || typ1->v_type == VAR_PARTIAL || typ2->v_type == VAR_PARTIAL) {
        if (type != TYPE_EQUAL && type != TYPE_NEQUAL) {
            EMSG (_ ("E694: Invalid operation for Funcrefs"));
            clear_tv (typ1);
            return FAIL;
        }
        if ((typ1->v_type == VAR_PARTIAL && typ1->vval.v_partial == NULL) || (typ2->v_type == VAR_PARTIAL && typ2->vval.v_partial == NULL))
            n1 = FALSE;
        else if (type_is) {
            if (typ1->v_type == VAR_FUNC && typ2->v_type == VAR_FUNC)
                n1 = tv_equal (typ1, typ2, ic, FALSE);
            else if (typ1->v_type == VAR_PARTIAL && typ2->v_type == VAR_PARTIAL)
                n1 = (typ1->vval.v_partial == typ2->vval.v_partial);
            else
                n1 = FALSE;
        }
        else
            n1 = tv_equal (typ1, typ2, ic, FALSE);
        if (type == TYPE_NEQUAL)
            n1 = !n1;
    }
    else if ((typ1->v_type == VAR_FLOAT || typ2->v_type == VAR_FLOAT) && type != TYPE_MATCH && type != TYPE_NOMATCH) {
        float_T f1, f2;
        if (typ1->v_type == VAR_FLOAT)
            f1 = typ1->vval.v_float;
        else
            f1 = get_tv_number (typ1);
        if (typ2->v_type == VAR_FLOAT)
            f2 = typ2->vval.v_float;
        else
            f2 = get_tv_number (typ2);
        n1 = FALSE;
        switch (type) {
        case TYPE_EQUAL :
            n1 = (f1 == f2);
            break;
        case TYPE_NEQUAL :
            n1 = (f1 != f2);
            break;
        case TYPE_GREATER :
            n1 = (f1 > f2);
            break;
        case TYPE_GEQUAL :
            n1 = (f1 >= f2);
            break;
        case TYPE_SMALLER :
            n1 = (f1 < f2);
            break;
        case TYPE_SEQUAL :
            n1 = (f1 <= f2);
            break;
        case TYPE_UNKNOWN :
        case TYPE_MATCH :
        case TYPE_NOMATCH :
            break;
        }
    }
    else if ((typ1->v_type == VAR_NUMBER || typ2->v_type == VAR_NUMBER) && type != TYPE_MATCH && type != TYPE_NOMATCH) {
        n1 = get_tv_number (typ1);
        n2 = get_tv_number (typ2);
        switch (type) {
        case TYPE_EQUAL :
            n1 = (n1 == n2);
            break;
        case TYPE_NEQUAL :
            n1 = (n1 != n2);
            break;
        case TYPE_GREATER :
            n1 = (n1 > n2);
            break;
        case TYPE_GEQUAL :
            n1 = (n1 >= n2);
            break;
        case TYPE_SMALLER :
            n1 = (n1 < n2);
            break;
        case TYPE_SEQUAL :
            n1 = (n1 <= n2);
            break;
        case TYPE_UNKNOWN :
        case TYPE_MATCH :
        case TYPE_NOMATCH :
            break;
        }
    }
    else {
        s1 = get_tv_string_buf (typ1, buf1);
        s2 = get_tv_string_buf (typ2, buf2);
        if (type != TYPE_MATCH && type != TYPE_NOMATCH)
            i = ic ? MB_STRICMP (s1, s2) : STRCMP (s1, s2);
        else
            i = 0;
        n1 = FALSE;
        switch (type) {
        case TYPE_EQUAL :
            n1 = (i == 0);
            break;
        case TYPE_NEQUAL :
            n1 = (i != 0);
            break;
        case TYPE_GREATER :
            n1 = (i > 0);
            break;
        case TYPE_GEQUAL :
            n1 = (i >= 0);
            break;
        case TYPE_SMALLER :
            n1 = (i < 0);
            break;
        case TYPE_SEQUAL :
            n1 = (i <= 0);
            break;
        case TYPE_MATCH :
        case TYPE_NOMATCH :
            n1 = pattern_match (s2, s1, ic);
            if (type == TYPE_NOMATCH)
                n1 = !n1;
            break;
        case TYPE_UNKNOWN :
            break;
        }
    }
    clear_tv (typ1);
    typ1->v_type = VAR_NUMBER;
    typ1->vval.v_number = n1;
    return OK;
}

int tv_equal (typval_T *tv1, typval_T *tv2, int ic, int recursive) {
    char_u buf1 [NUMBUFLEN], buf2 [NUMBUFLEN];
    char_u *s1, *s2;
    static int recursive_cnt = 0;
    int r;
    if (!recursive)
        tv_equal_recurse_limit = 1000;
    if (recursive_cnt >= tv_equal_recurse_limit) {
        --tv_equal_recurse_limit;
        return TRUE;
    }
    if ((tv1->v_type == VAR_FUNC || (tv1->v_type == VAR_PARTIAL && tv1->vval.v_partial != NULL)) && (tv2->v_type == VAR_FUNC || (tv2->v_type == VAR_PARTIAL && tv2->vval.v_partial != NULL))) {
        ++recursive_cnt;
        r = func_equal (tv1, tv2, ic);
        --recursive_cnt;
        return r;
    }
    if (tv1->v_type != tv2->v_type)
        return FALSE;
    switch (tv1->v_type) {
    case VAR_LIST :
        ++recursive_cnt;
        r = list_equal (tv1->vval.v_list, tv2->vval.v_list, ic, TRUE);
        --recursive_cnt;
        return r;
    case VAR_DICT :
        ++recursive_cnt;
        r = dict_equal (tv1->vval.v_dict, tv2->vval.v_dict, ic, TRUE);
        --recursive_cnt;
        return r;
    case VAR_NUMBER :
        return tv1->vval.v_number == tv2->vval.v_number;
    case VAR_STRING :
        s1 = get_tv_string_buf (tv1, buf1);
        s2 = get_tv_string_buf (tv2, buf2);
        return ((ic ? MB_STRICMP (s1, s2) : STRCMP (s1, s2)) == 0);
    case VAR_SPECIAL :
        return tv1->vval.v_number == tv2->vval.v_number;
    case VAR_FLOAT :
        return tv1->vval.v_float == tv2->vval.v_float;
    case VAR_JOB :
        return tv1->vval.v_job == tv2->vval.v_job;
    case VAR_CHANNEL :
        return tv1->vval.v_channel == tv2->vval.v_channel;
    case VAR_FUNC :
    case VAR_PARTIAL :
    case VAR_UNKNOWN :
        break;
    }
    return FALSE;
}

static int func_equal (typval_T *tv1, typval_T *tv2, int ic) {
    char_u *s1, *s2;
    dict_T *d1, *d2;
    int a1, a2;
    int i;
    s1 = tv1->v_type == VAR_FUNC ? tv1->vval.v_string : partial_name (tv1->vval.v_partial);
    if (s1 != NULL && *s1 == NUL)
        s1 = NULL;
    s2 = tv2->v_type == VAR_FUNC ? tv2->vval.v_string : partial_name (tv2->vval.v_partial);
    if (s2 != NULL && *s2 == NUL)
        s2 = NULL;
    if (s1 == NULL || s2 == NULL) {
        if (s1 != s2)
            return FALSE;
    }
    else if (STRCMP (s1, s2) != 0)
        return FALSE;
    d1 = tv1->v_type == VAR_FUNC ? NULL : tv1->vval.v_partial->pt_dict;
    d2 = tv2->v_type == VAR_FUNC ? NULL : tv2->vval.v_partial->pt_dict;
    if (d1 == NULL || d2 == NULL) {
        if (d1 != d2)
            return FALSE;
    }
    else if (!dict_equal (d1, d2, ic, TRUE))
        return FALSE;
    a1 = tv1->v_type == VAR_FUNC ? 0 : tv1->vval.v_partial->pt_argc;
    a2 = tv2->v_type == VAR_FUNC ? 0 : tv2->vval.v_partial->pt_argc;
    if (a1 != a2)
        return FALSE;
    for (i = 0; i < a1; ++i)
        if (!tv_equal (tv1->vval.v_partial->pt_argv + i, tv2->vval.v_partial->pt_argv + i, ic, TRUE))
            return FALSE;
    return TRUE;
}

varnumber_T get_tv_number (typval_T *varp) {
    int error = FALSE;
    return get_tv_number_chk (varp, &error);
}

static int pattern_match (char_u *pat, char_u *text, int ic) {
    int matches = FALSE;
    char_u *save_cpo;
    regmatch_T regmatch;
    save_cpo = p_cpo;
    p_cpo = (char_u *) "";
    regmatch.regprog = vim_regcomp (pat, RE_MAGIC +RE_STRING);
    if (regmatch.regprog != NULL) {
        regmatch.rm_ic = ic;
        matches = vim_regexec_nl (&regmatch, text, (colnr_T) 0);
        vim_regfree (regmatch.regprog);
    }
    p_cpo = save_cpo;
    return matches;
}

void new_script_vars (scid_T id) {
    int i;
    hashtab_T *ht;
    scriptvar_T *sv;
    if (ga_grow (&ga_scripts, (int) (id - ga_scripts.ga_len)) == OK) {
        for (i = 1; i <= ga_scripts.ga_len; ++i) {
            ht = &SCRIPT_VARS (i);
            if (ht->ht_mask == HT_INIT_SIZE - 1)
                ht->ht_array = ht->ht_smallarray;
            sv = SCRIPT_SV (i);
            sv->sv_var.di_tv.vval.v_dict = &sv->sv_dict;
        }
        while (ga_scripts.ga_len < id) {
            sv = SCRIPT_SV (ga_scripts.ga_len + 1) = (scriptvar_T *) alloc_clear (sizeof (scriptvar_T));
            init_var_dict (& sv -> sv_dict, & sv -> sv_var, VAR_SCOPE);
            ++ga_scripts.ga_len;
        }
    }
}

void last_set_msg (scid_T scriptID) {
    char_u *p;
    if (scriptID != 0) {
        p = home_replace_save (NULL, get_scriptname (scriptID));
        if (p != NULL) {
            verbose_enter ();
            MSG_PUTS (_ ("\n\tLast set from "));
            MSG_PUTS (p);
            vim_free (p);
            verbose_leave ();
        }
    }
}

void reset_v_option_vars (void) {
    set_vim_var_string (VV_OPTION_NEW, NULL, - 1);
    set_vim_var_string (VV_OPTION_OLD, NULL, - 1);
    set_vim_var_string (VV_OPTION_TYPE, NULL, - 1);
}

void set_vim_var_char (int c) {
    char_u buf [MB_MAXBYTES + 1];
    {
        buf[0] = c;
        buf[1] = NUL;
    }
    set_vim_var_string (VV_CHAR, buf, - 1);
}

varnumber_T eval_to_number (char_u *expr) {
    typval_T rettv;
    varnumber_T retval;
    char_u *p = skipwhite (expr);
    ++emsg_off;
    if (eval1 (&p, &rettv, TRUE) == FAIL)
        retval = -1;
    else {
        retval = get_tv_number_chk (&rettv, NULL);
        clear_tv (& rettv);
    }
    --emsg_off;
    return retval;
}

char_u *get_var_value (char_u *name) {
    dictitem_T *v;
    v = find_var (name, NULL, FALSE);
    if (v == NULL)
        return NULL;
    return get_tv_string (&v->di_tv);
}

dictitem_T *find_var (char_u *name, hashtab_T **htp, int no_autoload) {
    char_u *varname;
    hashtab_T *ht;
    dictitem_T *ret = NULL;
    ht = find_var_ht (name, &varname);
    if (htp != NULL)
        *htp = ht;
    if (ht == NULL)
        return NULL;
    ret = find_var_in_ht (ht, *name, varname, no_autoload || htp != NULL);
    if (ret != NULL)
        return ret;
    return find_var_in_scoped_ht (name, no_autoload || htp != NULL);
}

list_T *get_vim_var_list (int idx) {
    return vimvars[idx].vv_list;
}

void set_vim_var_dict (int idx, dict_T *val) {
    clear_tv (& vimvars [idx].vv_di.di_tv);
    vimvars[idx].vv_type = VAR_DICT;
    vimvars[idx].vv_dict = val;
    if (val != NULL) {
        ++val->dv_refcount;
        dict_set_items_ro (val);
    }
}

list_T *eval_spell_expr (char_u *badword, char_u *expr) {
    typval_T save_val;
    typval_T rettv;
    list_T *list = NULL;
    char_u *p = skipwhite (expr);
    prepare_vimvar (VV_VAL, & save_val);
    vimvars[VV_VAL].vv_type = VAR_STRING;
    vimvars[VV_VAL].vv_str = badword;
    if (p_verbose == 0)
        ++emsg_off;
    if (eval1 (&p, &rettv, TRUE) == OK) {
        if (rettv.v_type != VAR_LIST)
            clear_tv (&rettv);
        else
            list = rettv.vval.v_list;
    }
    if (p_verbose == 0)
        --emsg_off;
    restore_vimvar (VV_VAL, & save_val);
    return list;
}

static void prepare_vimvar (int idx, typval_T *save_tv) {
    *save_tv = vimvars[idx].vv_tv;
    if (vimvars[idx].vv_type == VAR_UNKNOWN)
        hash_add (&vimvarht, vimvars[idx].vv_di.di_key);
}

static void restore_vimvar (int idx, typval_T *save_tv) {
    hashitem_T *hi;
    vimvars[idx].vv_tv = *save_tv;
    if (vimvars[idx].vv_type == VAR_UNKNOWN) {
        hi = hash_find (&vimvarht, vimvars[idx].vv_di.di_key);
        if (HASHITEM_EMPTY (hi))
            internal_error ("restore_vimvar()");
        else
            hash_remove (&vimvarht, hi);
    }
}

int get_spellword (list_T *list, char_u **pp) {
    listitem_T *li;
    li = list->lv_first;
    if (li == NULL)
        return -1;
    *pp = get_tv_string (&li->li_tv);
    li = li->li_next;
    if (li == NULL)
        return -1;
    return (int) get_tv_number (&li->li_tv);
}

void *call_func_retlist (char_u *func, int argc, char_u **argv, int safe) {
    typval_T rettv;
    if (call_vim_function (func, argc, argv, safe, TRUE, &rettv) == FAIL)
        return NULL;
    if (rettv.v_type != VAR_LIST) {
        clear_tv (& rettv);
        return NULL;
    }
    return rettv.vval.v_list;
}

int call_vim_function (char_u *func, int argc, char_u **argv, int safe, int str_arg_only, typval_T *rettv) {
    typval_T *argvars;
    varnumber_T n;
    int len;
    int i;
    int doesrange;
    void *save_funccalp = NULL;
    int ret;
    argvars = (typval_T *) alloc ((unsigned ) ((argc + 1) * sizeof (typval_T)));
    if (argvars == NULL)
        return FAIL;
    for (i = 0; i < argc; i++) {
        if (argv[i] == NULL || *argv[i] == NUL) {
            argvars[i].v_type = VAR_STRING;
            argvars[i].vval.v_string = (char_u *) "";
            continue;
        }
        if (str_arg_only)
            len = 0;
        else {
            vim_str2nr (argv [i], NULL, & len, STR2NR_ALL, & n, NULL, 0);
            if (len == 1 && *argv[i] == '-')
                len = 0;
        }
        if (len != 0 && len == (int) STRLEN (argv[i])) {
            argvars[i].v_type = VAR_NUMBER;
            argvars[i].vval.v_number = n;
        }
        else {
            argvars[i].v_type = VAR_STRING;
            argvars[i].vval.v_string = argv[i];
        }
    }
    if (safe) {
        save_funccalp = save_funccal ();
        ++sandbox;
    }
    rettv->v_type = VAR_UNKNOWN;
    ret = call_func (func, (int) STRLEN (func), rettv, argc, argvars, NULL, curwin->w_cursor.lnum, curwin->w_cursor.lnum, &doesrange, TRUE, NULL, NULL);
    if (safe) {
        --sandbox;
        restore_funccal (save_funccalp);
    }
    vim_free (argvars);
    if (ret == FAIL)
        clear_tv (rettv);
    return ret;
}

void *call_func_retstr (char_u *func, int argc, char_u **argv, int safe) {
    typval_T rettv;
    char_u *retval;
    if (call_vim_function (func, argc, argv, safe, TRUE, &rettv) == FAIL)
        return NULL;
    retval = vim_strsave (get_tv_string (&rettv));
    clear_tv (& rettv);
    return retval;
}

char_u *get_user_var_name (expand_T *xp, int idx) {
    static long_u gdone;
    static long_u bdone;
    static long_u wdone;
    static long_u tdone;
    static int vidx;
    static hashitem_T *hi;
    hashtab_T *ht;
    if (idx == 0) {
        gdone = bdone = wdone = vidx = 0;
        tdone = 0;
    }
    if (gdone < globvarht.ht_used) {
        if (gdone++ == 0)
            hi = globvarht.ht_array;
        else
            ++hi;
        while (HASHITEM_EMPTY (hi))
            ++hi;
        if (STRNCMP ("g:", xp->xp_pattern, 2) == 0)
            return cat_prefix_varname ('g', hi->hi_key);
        return hi->hi_key;
    }
    ht = &curbuf->b_vars->dv_hashtab;
    if (bdone < ht->ht_used) {
        if (bdone++ == 0)
            hi = ht->ht_array;
        else
            ++hi;
        while (HASHITEM_EMPTY (hi))
            ++hi;
        return cat_prefix_varname ('b', hi->hi_key);
    }
    ht = &curwin->w_vars->dv_hashtab;
    if (wdone < ht->ht_used) {
        if (wdone++ == 0)
            hi = ht->ht_array;
        else
            ++hi;
        while (HASHITEM_EMPTY (hi))
            ++hi;
        return cat_prefix_varname ('w', hi->hi_key);
    }
    ht = &curtab->tp_vars->dv_hashtab;
    if (tdone < ht->ht_used) {
        if (tdone++ == 0)
            hi = ht->ht_array;
        else
            ++hi;
        while (HASHITEM_EMPTY (hi))
            ++hi;
        return cat_prefix_varname ('t', hi->hi_key);
    }
    if (vidx < VV_LEN)
        return cat_prefix_varname ('v', (char_u *) vimvars[vidx++].vv_name);
    VIM_CLEAR (varnamebuf);
    varnamebuflen = 0;
    return NULL;
}

static char_u *cat_prefix_varname (int prefix, char_u *name) {
    int len;
    len = (int) STRLEN (name) + 3;
    if (len > varnamebuflen) {
        vim_free (varnamebuf);
        len += 10;
        varnamebuf = alloc (len);
        if (varnamebuf == NULL) {
            varnamebuflen = 0;
            return NULL;
        }
        varnamebuflen = len;
    }
    *varnamebuf = prefix;
    varnamebuf[1] = ':';
    STRCPY (varnamebuf + 2, name);
    return varnamebuf;
}

void set_context_for_expression (expand_T *xp, char_u *arg, cmdidx_T cmdidx) {
    int got_eq = FALSE;
    int c;
    char_u *p;
    if (cmdidx == CMD_let) {
        xp->xp_context = EXPAND_USER_VARS;
        if (vim_strpbrk (arg, (char_u *) "\"'+-*/%.=!?~|&$([<>,#") == NULL) {
            for (p = arg + STRLEN (arg); p >= arg;) {
                xp->xp_pattern = p;
                MB_PTR_BACK (arg, p);
                if (VIM_ISWHITE (*p))
                    break;
            }
            return;
        }
    }
    else
        xp->xp_context = cmdidx == CMD_call ? EXPAND_FUNCTIONS : EXPAND_EXPRESSION;
    while ((xp->xp_pattern = vim_strpbrk (arg, (char_u *) "\"'+-*/%.=!?~|&$([<>,#")) != NULL) {
        c = *xp->xp_pattern;
        if (c == '&') {
            c = xp->xp_pattern[1];
            if (c == '&') {
                ++xp->xp_pattern;
                xp->xp_context = cmdidx != CMD_let || got_eq ? EXPAND_EXPRESSION : EXPAND_NOTHING;
            }
            else if (c != ' ') {
                xp->xp_context = EXPAND_SETTINGS;
                if ((c == 'l' || c == 'g') && xp->xp_pattern[2] == ':')
                    xp->xp_pattern += 2;
            }
        }
        else if (c == '$') {
            xp->xp_context = EXPAND_ENV_VARS;
        }
        else if (c == '=') {
            got_eq = TRUE;
            xp->xp_context = EXPAND_EXPRESSION;
        }
        else if (c == '#' && xp->xp_context == EXPAND_EXPRESSION) {
            break;
        }
        else if ((c == '<' || c == '#') && xp->xp_context == EXPAND_FUNCTIONS && vim_strchr (xp->xp_pattern, '(') == NULL) {
            break;
        }
        else if (cmdidx != CMD_let || got_eq) {
            if (c == '"') {
                while ((c = *++xp->xp_pattern) != NUL && c != '"')
                    if (c == '\\' && xp->xp_pattern[1] != NUL)
                        ++xp->xp_pattern;
                xp->xp_context = EXPAND_NOTHING;
            }
            else if (c == '\'') {
                while ((c = *++xp->xp_pattern) != NUL && c != '\'')
                    ;
                xp->xp_context = EXPAND_NOTHING;
            }
            else if (c == '|') {
                if (xp->xp_pattern[1] == '|') {
                    ++xp->xp_pattern;
                    xp->xp_context = EXPAND_EXPRESSION;
                }
                else
                    xp->xp_context = EXPAND_COMMANDS;
            }
            else
                xp->xp_context = EXPAND_EXPRESSION;
        }
        else
            xp->xp_context = EXPAND_EXPRESSION;
        arg = xp->xp_pattern;
        if (*arg != NUL)
            while ((c = *++arg) != NUL && (c == ' ' || c == '\t'))
                ;
    }
    xp->xp_pattern = arg;
}

int do_unlet (char_u *name, int forceit) {
    hashtab_T *ht;
    hashitem_T *hi;
    char_u *varname;
    dict_T *d;
    dictitem_T *di;
    ht = find_var_ht (name, &varname);
    if (ht != NULL && *varname != NUL) {
        d = get_current_funccal_dict (ht);
        if (d == NULL) {
            if (ht == &globvarht)
                d = &globvardict;
            else if (ht == &compat_hashtab)
                d = &vimvardict;
            else {
                di = find_var_in_ht (ht, *name, (char_u *) "", FALSE);
                d = di == NULL ? NULL : di->di_tv.vval.v_dict;
            }
            if (d == NULL) {
                internal_error ("do_unlet()");
                return FAIL;
            }
        }
        hi = hash_find (ht, varname);
        if (HASHITEM_EMPTY (hi))
            hi = find_hi_in_scoped_ht (name, &ht);
        if (hi != NULL && !HASHITEM_EMPTY (hi)) {
            di = HI2DI (hi);
            if (var_check_fixed (di->di_flags, name, FALSE) || var_check_ro (di->di_flags, name, FALSE) || tv_check_lock (d->dv_lock, name, FALSE))
                return FAIL;
            delete_var (ht, hi);
            return OK;
        }
    }
    if (forceit)
        return OK;
    EMSG2 (_ ("E108: No such variable: \"%s\""), name);
    return FAIL;
}

int var_check_fixed (int flags, char_u *name, int use_gettext) {
    if (flags & DI_FLAGS_FIX) {
        EMSG2 (_ ("E795: Cannot delete variable %s"), use_gettext ? (char_u *) _ (name) : name);
        return TRUE;
    }
    return FALSE;
}

int var_check_ro (int flags, char_u *name, int use_gettext) {
    if (flags & DI_FLAGS_RO) {
        EMSG2 (_ (e_readonlyvar), use_gettext ? (char_u *) _ (name) : name);
        return TRUE;
    }
    if ((flags & DI_FLAGS_RO_SBX) && sandbox) {
        EMSG2 (_ (e_readonlysbx), use_gettext ? (char_u *) _ (name) : name);
        return TRUE;
    }
    return FALSE;
}

int tv_check_lock (int lock, char_u *name, int use_gettext) {
    if (lock & VAR_LOCKED) {
        EMSG2 (_ ("E741: Value is locked: %s"), name == NULL ? (char_u *) _ ("Unknown") : use_gettext ? (char_u *) _ (name) : name);
        return TRUE;
    }
    if (lock & VAR_FIXED) {
        EMSG2 (_ ("E742: Cannot change value of %s"), name == NULL ? (char_u *) _ ("Unknown") : use_gettext ? (char_u *) _ (name) : name);
        return TRUE;
    }
    return FALSE;
}

static void delete_var (hashtab_T *ht, hashitem_T *hi) {
    dictitem_T *di = HI2DI (hi);
    hash_remove (ht, hi);
    clear_tv (& di -> di_tv);
    vim_free (di);
}

void set_vcount (long  count, long  count1, int set_prevcount) {
    if (set_prevcount)
        vimvars[VV_PREVCOUNT].vv_nr = vimvars[VV_COUNT].vv_nr;
    vimvars[VV_COUNT].vv_nr = count;
    vimvars[VV_COUNT1].vv_nr = count1;
}

void set_reg_var (int c) {
    char_u regname;
    if (c == 0 || c == ' ')
        regname = '"';
    else
        regname = c;
    if (vimvars[VV_REG].vv_str == NULL || vimvars[VV_REG].vv_str[0] != c)
        set_vim_var_string (VV_REG, &regname, 1);
}

int var_check_func_name (char_u *name, int new_var) {
    if (!(vim_strchr ((char_u *) "wbst", name[0]) != NULL && name[1] == ':') && !ASCII_ISUPPER ((name[0] != NUL && name[1] == ':') ? name[2] : name[0])) {
        EMSG2 (_ ("E704: Funcref variable name must start with a capital: %s"), name);
        return TRUE;
    }
    if (new_var && function_exists (name, FALSE)) {
        EMSG2 (_ ("E705: Variable name conflicts with existing function: %s"), name);
        return TRUE;
    }
    return FALSE;
}

int get_id_len (char_u **arg) {
    char_u *p;
    int len;
    for (p = *arg; eval_isnamec (*p); ++p) {
        if (*p == ':') {
            len = (int) (p - *arg);
            if ((len == 1 && vim_strchr (NAMESPACE_CHAR, **arg) == NULL) || len > 1)
                break;
        }
    }
    if (p == *arg)
        return 0;
    len = (int) (p - *arg);
    *arg = skipwhite (p);
    return len;
}

int eval_isnamec (int c) {
    return (ASCII_ISALNUM (c) || c == '_' || c == ':' || c == AUTOLOAD_CHAR);
}

char_u *get_lval (char_u *name, typval_T *rettv, lval_T *lp, int unlet, int skip, int flags, int fne_flags) {
    char_u *p;
    char_u *expr_start, *expr_end;
    int cc;
    dictitem_T *v;
    typval_T var1;
    typval_T var2;
    int empty1 = FALSE;
    listitem_T *ni;
    char_u *key = NULL;
    int len;
    hashtab_T *ht;
    int quiet = flags & GLV_QUIET;
    vim_memset (lp, 0, sizeof (lval_T));
    if (skip) {
        lp->ll_name = name;
        return find_name_end (name, NULL, NULL, FNE_INCL_BR | fne_flags);
    }
    p = find_name_end (name, &expr_start, &expr_end, fne_flags);
    if (expr_start != NULL) {
        if (unlet && !VIM_ISWHITE (*p) && !ends_excmd (*p) && *p != '[' && *p != '.') {
            EMSG (_ (e_trailing));
            return NULL;
        }
        lp->ll_exp_name = make_expanded_name (name, expr_start, expr_end, p);
        if (lp->ll_exp_name == NULL) {
            if (!aborting () && !quiet) {
                emsg_severe = TRUE;
                EMSG2 (_ (e_invarg2), name);
                return NULL;
            }
        }
        lp->ll_name = lp->ll_exp_name;
    }
    else
        lp->ll_name = name;
    if ((*p != '[' && *p != '.') || lp->ll_name == NULL)
        return p;
    cc = *p;
    *p = NUL;
    v = find_var (lp->ll_name, (flags & GLV_READ_ONLY) ? NULL : &ht, flags &GLV_NO_AUTOLOAD);
    if (v == NULL && !quiet)
        EMSG2 (_ (e_undefvar), lp->ll_name);
    *p = cc;
    if (v == NULL)
        return NULL;
    lp->ll_tv = &v->di_tv;
    var1.v_type = VAR_UNKNOWN;
    var2.v_type = VAR_UNKNOWN;
    while (*p == '[' || (*p == '.' && lp->ll_tv->v_type == VAR_DICT)) {
        if (!(lp->ll_tv->v_type == VAR_LIST && lp->ll_tv->vval.v_list != NULL) && !(lp->ll_tv->v_type == VAR_DICT && lp->ll_tv->vval.v_dict != NULL)) {
            if (!quiet)
                EMSG (_ ("E689: Can only index a List or Dictionary"));
            return NULL;
        }
        if (lp->ll_range) {
            if (!quiet)
                EMSG (_ ("E708: [:] must come last"));
            return NULL;
        }
        len = -1;
        if (*p == '.') {
            key = p + 1;
            for (len = 0; ASCII_ISALNUM (key[len]) || key[len] == '_'; ++len)
                ;
            if (len == 0) {
                if (!quiet)
                    EMSG (_ (e_emptykey));
                return NULL;
            }
            p = key + len;
        }
        else {
            p = skipwhite (p +1);
            if (*p == ':')
                empty1 = TRUE;
            else {
                empty1 = FALSE;
                if (eval1 (&p, &var1, TRUE) == FAIL)
                    return NULL;
                if (get_tv_string_chk (&var1) == NULL) {
                    clear_tv (& var1);
                    return NULL;
                }
            }
            if (*p == ':') {
                if (lp->ll_tv->v_type == VAR_DICT) {
                    if (!quiet)
                        EMSG (_ (e_dictrange));
                    clear_tv (& var1);
                    return NULL;
                }
                if (rettv != NULL && (rettv->v_type != VAR_LIST || rettv->vval.v_list == NULL)) {
                    if (!quiet)
                        EMSG (_ ("E709: [:] requires a List value"));
                    clear_tv (& var1);
                    return NULL;
                }
                p = skipwhite (p +1);
                if (*p == ']')
                    lp->ll_empty2 = TRUE;
                else {
                    lp->ll_empty2 = FALSE;
                    if (eval1 (&p, &var2, TRUE) == FAIL) {
                        clear_tv (& var1);
                        return NULL;
                    }
                    if (get_tv_string_chk (&var2) == NULL) {
                        clear_tv (& var1);
                        clear_tv (& var2);
                        return NULL;
                    }
                }
                lp->ll_range = TRUE;
            }
            else
                lp->ll_range = FALSE;
            if (*p != ']') {
                if (!quiet)
                    EMSG (_ (e_missbrac));
                clear_tv (& var1);
                clear_tv (& var2);
                return NULL;
            }
            ++p;
        }
        if (lp->ll_tv->v_type == VAR_DICT) {
            if (len == -1) {
                key = get_tv_string_chk (&var1);
                if (key == NULL) {
                    clear_tv (& var1);
                    return NULL;
                }
            }
            lp->ll_list = NULL;
            lp->ll_dict = lp->ll_tv->vval.v_dict;
            lp->ll_di = dict_find (lp->ll_dict, key, len);
            if (rettv != NULL && lp->ll_dict->dv_scope != 0) {
                int prevval;
                int wrong;
                if (len != -1) {
                    prevval = key[len];
                    key[len] = NUL;
                }
                else
                    prevval = 0;
                wrong = (lp->ll_dict->dv_scope == VAR_DEF_SCOPE && rettv->v_type == VAR_FUNC && var_check_func_name (key, lp->ll_di == NULL)) || !valid_varname (key);
                if (len != -1)
                    key[len] = prevval;
                if (wrong)
                    return NULL;
            }
            if (lp->ll_di == NULL) {
                if (lp->ll_dict == &vimvardict) {
                    EMSG2 (_ (e_illvar), name);
                    return NULL;
                }
                if (*p == '[' || *p == '.' || unlet) {
                    if (!quiet)
                        EMSG2 (_ (e_dictkey), key);
                    clear_tv (& var1);
                    return NULL;
                }
                if (len == -1)
                    lp->ll_newkey = vim_strsave (key);
                else
                    lp->ll_newkey = vim_strnsave (key, len);
                clear_tv (& var1);
                if (lp->ll_newkey == NULL)
                    p = NULL;
                break;
            }
            else if ((flags & GLV_READ_ONLY) == 0 && var_check_ro (lp->ll_di->di_flags, name, FALSE)) {
                clear_tv (& var1);
                return NULL;
            }
            clear_tv (& var1);
            lp->ll_tv = &lp->ll_di->di_tv;
        }
        else {
            if (empty1)
                lp->ll_n1 = 0;
            else
                lp->ll_n1 = (long ) get_tv_number (&var1);
            clear_tv (& var1);
            lp->ll_dict = NULL;
            lp->ll_list = lp->ll_tv->vval.v_list;
            lp->ll_li = list_find (lp->ll_list, lp->ll_n1);
            if (lp->ll_li == NULL) {
                if (lp->ll_n1 < 0) {
                    lp->ll_n1 = 0;
                    lp->ll_li = list_find (lp->ll_list, lp->ll_n1);
                }
            }
            if (lp->ll_li == NULL) {
                clear_tv (& var2);
                if (!quiet)
                    EMSGN (_ (e_listidx), lp->ll_n1);
                return NULL;
            }
            if (lp->ll_range && !lp->ll_empty2) {
                lp->ll_n2 = (long ) get_tv_number (&var2);
                clear_tv (& var2);
                if (lp->ll_n2 < 0) {
                    ni = list_find (lp->ll_list, lp->ll_n2);
                    if (ni == NULL) {
                        if (!quiet)
                            EMSGN (_ (e_listidx), lp->ll_n2);
                        return NULL;
                    }
                    lp->ll_n2 = list_idx_of_item (lp->ll_list, ni);
                }
                if (lp->ll_n1 < 0)
                    lp->ll_n1 = list_idx_of_item (lp->ll_list, lp->ll_li);
                if (lp->ll_n2 < lp->ll_n1) {
                    if (!quiet)
                        EMSGN (_ (e_listidx), lp->ll_n2);
                    return NULL;
                }
            }
            lp->ll_tv = &lp->ll_li->li_tv;
        }
    }
    clear_tv (& var1);
    return p;
}

char_u *find_name_end (char_u *arg, char_u **expr_start, char_u **expr_end, int flags) {
    int mb_nest = 0;
    int br_nest = 0;
    char_u *p;
    int len;
    if (expr_start != NULL) {
        *expr_start = NULL;
        *expr_end = NULL;
    }
    if ((flags & FNE_CHECK_START) && !eval_isnamec1 (*arg) && *arg != '{')
        return arg;
    for (p = arg; *p != NUL && (eval_isnamec (*p) || *p == '{' || ((flags & FNE_INCL_BR) && (*p == '[' || *p == '.')) || mb_nest != 0 || br_nest != 0); MB_PTR_ADV (p)) {
        if (*p == '\'') {
            for (p = p + 1; *p != NUL && *p != '\''; MB_PTR_ADV (p))
                ;
            if (*p == NUL)
                break;
        }
        else if (*p == '"') {
            for (p = p + 1; *p != NUL && *p != '"'; MB_PTR_ADV (p))
                if (*p == '\\' && p[1] != NUL)
                    ++p;
            if (*p == NUL)
                break;
        }
        else if (br_nest == 0 && mb_nest == 0 && *p == ':') {
            len = (int) (p - arg);
            if ((len == 1 && vim_strchr (NAMESPACE_CHAR, *arg) == NULL) || (len > 1 && p[-1] != '}'))
                break;
        }
        if (mb_nest == 0) {
            if (*p == '[')
                ++br_nest;
            else if (*p == ']')
                --br_nest;
        }
        if (br_nest == 0) {
            if (*p == '{') {
                mb_nest++;
                if (expr_start != NULL && *expr_start == NULL)
                    *expr_start = p;
            }
            else if (*p == '}') {
                mb_nest--;
                if (expr_start != NULL && mb_nest == 0 && *expr_end == NULL)
                    *expr_end = p;
            }
        }
    }
    return p;
}

int eval_isnamec1 (int c) {
    return (ASCII_ISALPHA (c) || c == '_');
}

static char_u *make_expanded_name (char_u *in_start, char_u *expr_start, char_u *expr_end, char_u *in_end) {
    char_u c1;
    char_u *retval = NULL;
    char_u *temp_result;
    char_u *nextcmd = NULL;
    if (expr_end == NULL || in_end == NULL)
        return NULL;
    *expr_start = NUL;
    *expr_end = NUL;
    c1 = *in_end;
    *in_end = NUL;
    temp_result = eval_to_string (expr_start +1, &nextcmd, FALSE);
    if (temp_result != NULL && nextcmd == NULL) {
        retval = alloc ((unsigned ) (STRLEN (temp_result) + (expr_start - in_start) + (in_end - expr_end) + 1));
        if (retval != NULL) {
            STRCPY (retval, in_start);
            STRCAT (retval, temp_result);
            STRCAT (retval, expr_end + 1);
        }
    }
    vim_free (temp_result);
    *in_end = c1;
    *expr_start = '{';
    *expr_end = '}';
    if (retval != NULL) {
        temp_result = find_name_end (retval, &expr_start, &expr_end, 0);
        if (expr_start != NULL) {
            temp_result = make_expanded_name (retval, expr_start, expr_end, temp_result);
            vim_free (retval);
            retval = temp_result;
        }
    }
    return retval;
}

int valid_varname (char_u *varname) {
    char_u *p;
    for (p = varname; *p != NUL; ++p)
        if (!eval_isnamec1 (*p) && (p == varname || !VIM_ISDIGIT (*p)) && *p != AUTOLOAD_CHAR) {
            EMSG2 (_ (e_illvar), varname);
            return FALSE;
        }
    return TRUE;
}

void clear_lval (lval_T *lp) {
    vim_free (lp -> ll_exp_name);
    vim_free (lp -> ll_newkey);
}

void init_tv (typval_T *varp) {
    if (varp != NULL)
        vim_memset (varp, 0, sizeof (typval_T));
}

dict_T *get_vim_var_dict (int idx) {
    return vimvars[idx].vv_dict;
}

varnumber_T call_func_retnr (char_u *func, int argc, char_u **argv, int safe) {
    typval_T rettv;
    varnumber_T retval;
    if (call_vim_function (func, argc, argv, safe, TRUE, &rettv) == FAIL)
        return -1;
    retval = get_tv_number_chk (&rettv, NULL);
    clear_tv (& rettv);
    return retval;
}

void var_redir_str (char_u *value, int value_len) {
    int len;
    if (redir_lval == NULL)
        return;
    if (value_len == -1)
        len = (int) STRLEN (value);
    else
        len = value_len;
    if (ga_grow (&redir_ga, len) == OK) {
        mch_memmove ((char *) redir_ga.ga_data + redir_ga.ga_len, value, len);
        redir_ga.ga_len += len;
    }
    else
        var_redir_stop ();
}

void var_redir_stop (void) {
    typval_T tv;
    if (EVALCMD_BUSY) {
        redir_lval = NULL;
        return;
    }
    if (redir_lval != NULL) {
        if (redir_endp != NULL) {
            ga_append (& redir_ga, NUL);
            tv.v_type = VAR_STRING;
            tv.vval.v_string = redir_ga.ga_data;
            redir_endp = get_lval (redir_varname, NULL, redir_lval, FALSE, FALSE, 0, FNE_CHECK_START);
            if (redir_endp != NULL && redir_lval->ll_name != NULL)
                set_var_lval (redir_lval, redir_endp, &tv, FALSE, (char_u *) ".");
            clear_lval (redir_lval);
        }
        VIM_CLEAR (redir_ga.ga_data);
        VIM_CLEAR (redir_lval);
    }
    VIM_CLEAR (redir_varname);
}

static void set_var_lval (lval_T *lp, char_u *endp, typval_T *rettv, int copy, char_u *op) {
    int cc;
    listitem_T *ri;
    dictitem_T *di;
    if (lp->ll_tv == NULL) {
        cc = *endp;
        *endp = NUL;
        if (op != NULL && *op != '=') {
            typval_T tv;
            di = NULL;
            if (get_var_tv (lp->ll_name, (int) STRLEN (lp->ll_name), &tv, &di, TRUE, FALSE) == OK) {
                if ((di == NULL || (!var_check_ro (di->di_flags, lp->ll_name, FALSE) && !tv_check_lock (di->di_tv.v_lock, lp->ll_name, FALSE))) && tv_op (&tv, rettv, op) == OK)
                    set_var (lp->ll_name, &tv, FALSE);
                clear_tv (& tv);
            }
        }
        else
            set_var (lp->ll_name, rettv, copy);
        *endp = cc;
    }
    else if (tv_check_lock (lp->ll_newkey == NULL ? lp->ll_tv->v_lock : lp->ll_tv->vval.v_dict->dv_lock, lp->ll_name, FALSE))
        ;
    else if (lp->ll_range) {
        listitem_T *ll_li = lp->ll_li;
        int ll_n1 = lp->ll_n1;
        for (ri = rettv->vval.v_list->lv_first; ri != NULL && ll_li != NULL;) {
            if (tv_check_lock (ll_li->li_tv.v_lock, lp->ll_name, FALSE))
                return;
            ri = ri->li_next;
            if (ri == NULL || (!lp->ll_empty2 && lp->ll_n2 == ll_n1))
                break;
            ll_li = ll_li->li_next;
            ++ll_n1;
        }
        for (ri = rettv->vval.v_list->lv_first; ri != NULL;) {
            if (op != NULL && *op != '=')
                tv_op (&lp->ll_li->li_tv, &ri->li_tv, op);
            else {
                clear_tv (& lp -> ll_li -> li_tv);
                copy_tv (& ri -> li_tv, & lp -> ll_li -> li_tv);
            }
            ri = ri->li_next;
            if (ri == NULL || (!lp->ll_empty2 && lp->ll_n2 == lp->ll_n1))
                break;
            if (lp->ll_li->li_next == NULL) {
                if (list_append_number (lp->ll_list, 0) == FAIL) {
                    ri = NULL;
                    break;
                }
            }
            lp->ll_li = lp->ll_li->li_next;
            ++lp->ll_n1;
        }
        if (ri != NULL)
            EMSG (_ ("E710: List value has more items than target"));
        else if (lp->ll_empty2 ? (lp->ll_li != NULL && lp->ll_li->li_next != NULL) : lp->ll_n1 != lp->ll_n2)
            EMSG (_ ("E711: List value has not enough items"));
    }
    else {
        if (lp->ll_newkey != NULL) {
            if (op != NULL && *op != '=') {
                EMSG2 (_ (e_letwrong), op);
                return;
            }
            di = dictitem_alloc (lp->ll_newkey);
            if (di == NULL)
                return;
            if (dict_add (lp->ll_tv->vval.v_dict, di) == FAIL) {
                vim_free (di);
                return;
            }
            lp->ll_tv = &di->di_tv;
        }
        else if (op != NULL && *op != '=') {
            tv_op (lp -> ll_tv, rettv, op);
            return;
        }
        else
            clear_tv (lp->ll_tv);
        if (copy)
            copy_tv (rettv, lp->ll_tv);
        else {
            *lp->ll_tv = *rettv;
            lp->ll_tv->v_lock = 0;
            init_tv (rettv);
        }
    }
}

int get_var_tv (char_u *name, int len, typval_T *rettv, dictitem_T **dip, int verbose, int no_autoload) {
    int ret = OK;
    typval_T *tv = NULL;
    dictitem_T *v;
    int cc;
    cc = name[len];
    name[len] = NUL;
    v = find_var (name, NULL, no_autoload);
    if (v != NULL) {
        tv = &v->di_tv;
        if (dip != NULL)
            *dip = v;
    }
    if (tv == NULL) {
        if (rettv != NULL && verbose)
            EMSG2 (_ (e_undefvar), name);
        ret = FAIL;
    }
    else if (rettv != NULL)
        copy_tv (tv, rettv);
    name[len] = cc;
    return ret;
}

static int tv_op (typval_T *tv1, typval_T *tv2, char_u *op) {
    varnumber_T n;
    char_u numbuf [NUMBUFLEN];
    char_u *s;
    if (tv2->v_type != VAR_FUNC && tv2->v_type != VAR_DICT && tv2->v_type != VAR_SPECIAL) {
        switch (tv1->v_type) {
        case VAR_UNKNOWN :
        case VAR_DICT :
        case VAR_FUNC :
        case VAR_PARTIAL :
        case VAR_SPECIAL :
        case VAR_JOB :
        case VAR_CHANNEL :
            break;
        case VAR_LIST :
            if (*op != '+' || tv2->v_type != VAR_LIST)
                break;
            if (tv1->vval.v_list != NULL && tv2->vval.v_list != NULL)
                list_extend (tv1->vval.v_list, tv2->vval.v_list, NULL);
            return OK;
        case VAR_NUMBER :
        case VAR_STRING :
            if (tv2->v_type == VAR_LIST)
                break;
            if (*op == '+' || *op == '-') {
                n = get_tv_number (tv1);
                if (tv2->v_type == VAR_FLOAT) {
                    float_T f = n;
                    if (*op == '+')
                        f += tv2->vval.v_float;
                    else
                        f -= tv2->vval.v_float;
                    clear_tv (tv1);
                    tv1->v_type = VAR_FLOAT;
                    tv1->vval.v_float = f;
                }
                else {
                    if (*op == '+')
                        n += get_tv_number (tv2);
                    else
                        n -= get_tv_number (tv2);
                    clear_tv (tv1);
                    tv1->v_type = VAR_NUMBER;
                    tv1->vval.v_number = n;
                }
            }
            else {
                if (tv2->v_type == VAR_FLOAT)
                    break;
                s = get_tv_string (tv1);
                s = concat_str (s, get_tv_string_buf (tv2, numbuf));
                clear_tv (tv1);
                tv1->v_type = VAR_STRING;
                tv1->vval.v_string = s;
            }
            return OK;
        case VAR_FLOAT :
            {
                float_T f;
                if (*op == '.' || (tv2->v_type != VAR_FLOAT && tv2->v_type != VAR_NUMBER && tv2->v_type != VAR_STRING))
                    break;
                if (tv2->v_type == VAR_FLOAT)
                    f = tv2->vval.v_float;
                else
                    f = get_tv_number (tv2);
                if (*op == '+')
                    tv1->vval.v_float += f;
                else
                    tv1->vval.v_float -= f;
            }
            return OK;
        }
    }
    EMSG2 (_ (e_letwrong), op);
    return FAIL;
}

char_u *v_exception (char_u *oldval) {
    if (oldval == NULL)
        return vimvars[VV_EXCEPTION].vv_str;
    vimvars[VV_EXCEPTION].vv_str = oldval;
    return NULL;
}

char_u *v_throwpoint (char_u *oldval) {
    if (oldval == NULL)
        return vimvars[VV_THROWPOINT].vv_str;
    vimvars[VV_THROWPOINT].vv_str = oldval;
    return NULL;
}

void free_for_info (void *fi_void) {
    forinfo_T *fi = (forinfo_T *) fi_void;
    if (fi != NULL && fi->fi_list != NULL) {
        list_rem_watch (fi -> fi_list, & fi -> fi_lw);
        list_unref (fi -> fi_list);
    }
    vim_free (fi);
}

int get_option_tv (char_u **arg, typval_T *rettv, int evaluate) {
    char_u *option_end;
    long  numval;
    char_u *stringval;
    int opt_type;
    int c;
    int working = (**arg == '+');
    int ret = OK;
    int opt_flags;
    option_end = find_option_end (arg, &opt_flags);
    if (option_end == NULL) {
        if (rettv != NULL)
            EMSG2 (_ ("E112: Option name missing: %s"), *arg);
        return FAIL;
    }
    if (!evaluate) {
        *arg = option_end;
        return OK;
    }
    c = *option_end;
    *option_end = NUL;
    opt_type = get_option_value (*arg, &numval, rettv == NULL ? NULL : &stringval, opt_flags);
    if (opt_type == -3) {
        if (rettv != NULL)
            EMSG2 (_ ("E113: Unknown option: %s"), *arg);
        ret = FAIL;
    }
    else if (rettv != NULL) {
        if (opt_type == -2) {
            rettv->v_type = VAR_STRING;
            rettv->vval.v_string = NULL;
        }
        else if (opt_type == -1) {
            rettv->v_type = VAR_NUMBER;
            rettv->vval.v_number = 0;
        }
        else if (opt_type == 1) {
            rettv->v_type = VAR_NUMBER;
            rettv->vval.v_number = numval;
        }
        else {
            rettv->v_type = VAR_STRING;
            rettv->vval.v_string = stringval;
        }
    }
    else if (working && (opt_type == -2 || opt_type == -1))
        ret = FAIL;
    *option_end = c;
    *arg = option_end;
    return ret;
}

static char_u *find_option_end (char_u **arg, int *opt_flags) {
    char_u *p = *arg;
    ++p;
    if (*p == 'g' && p[1] == ':') {
        *opt_flags = OPT_GLOBAL;
        p += 2;
    }
    else if (*p == 'l' && p[1] == ':') {
        *opt_flags = OPT_LOCAL;
        p += 2;
    }
    else
        *opt_flags = 0;
    if (!ASCII_ISALPHA (*p))
        return NULL;
    *arg = p;
    if (p[0] == 't' && p[1] == '_' && p[2] != NUL && p[3] != NUL)
        p += 4;
    else
        while (ASCII_ISALPHA (*p))
            ++p;
    return p;
}

static int get_env_tv (char_u **arg, typval_T *rettv, int evaluate) {
    char_u *string = NULL;
    int len;
    int cc;
    char_u *name;
    int mustfree = FALSE;
    ++*arg;
    name = *arg;
    len = get_env_len (arg);
    if (evaluate) {
        if (len == 0)
            return FAIL;
        cc = name[len];
        name[len] = NUL;
        string = vim_getenv (name, &mustfree);
        if (string != NULL && *string != NUL) {
            if (!mustfree)
                string = vim_strsave (string);
        }
        else {
            if (mustfree)
                vim_free (string);
            string = expand_env_save (name -1);
            if (string != NULL && *string == '$')
                VIM_CLEAR (string);
        }
        name[len] = cc;
        rettv->v_type = VAR_STRING;
        rettv->vval.v_string = string;
    }
    return OK;
}

static int get_env_len (char_u **arg) {
    char_u *p;
    int len;
    for (p = *arg; vim_isIDc (*p); ++p)
        ;
    if (p == *arg)
        return 0;
    len = (int) (p - *arg);
    *arg = p;
    return len;
}

int get_name_len (char_u **arg, char_u **alias, int evaluate, int verbose) {
    int len;
    char_u *p;
    char_u *expr_start;
    char_u *expr_end;
    *alias = NULL;
    if ((*arg)[0] == K_SPECIAL && (*arg)[1] == KS_EXTRA && (*arg)[2] == (int) KE_SNR) {
        *arg += 3;
        return get_id_len (arg) + 3;
    }
    len = eval_fname_script (*arg);
    if (len > 0) {
        *arg += len;
    }
    p = find_name_end (*arg, &expr_start, &expr_end, len > 0 ? 0 : FNE_CHECK_START);
    if (expr_start != NULL) {
        char_u *temp_string;
        if (!evaluate) {
            len += (int) (p - *arg);
            *arg = skipwhite (p);
            return len;
        }
        temp_string = make_expanded_name (*arg - len, expr_start, expr_end, p);
        if (temp_string == NULL)
            return -1;
        *alias = temp_string;
        *arg = skipwhite (p);
        return (int) STRLEN (temp_string);
    }
    len += get_id_len (arg);
    if (len == 0 && verbose)
        EMSG2 (_ (e_invexpr2), *arg);
    return len;
}

static void check_vars (char_u *name, int len) {
    int cc;
    char_u *varname;
    hashtab_T *ht;
    if (eval_lavars_used == NULL)
        return;
    cc = name[len];
    name[len] = NUL;
    ht = find_var_ht (name, &varname);
    if (ht == get_funccal_local_ht () || ht == get_funccal_args_ht ()) {
        if (find_var (name, NULL, TRUE) != NULL)
            *eval_lavars_used = TRUE;
    }
    name[len] = cc;
}

int handle_subscript (char_u **arg, typval_T *rettv, int evaluate, int verbose) {
    int ret = OK;
    dict_T *selfdict = NULL;
    char_u *s;
    int len;
    typval_T functv;
    while (ret == OK && (**arg == '[' || (**arg == '.' && rettv->v_type == VAR_DICT) || (**arg == '(' && (!evaluate || rettv->v_type == VAR_FUNC || rettv->v_type == VAR_PARTIAL))) && !VIM_ISWHITE (*(*arg - 1))) {
        if (**arg == '(') {
            partial_T *pt = NULL;
            if (evaluate) {
                functv = *rettv;
                rettv->v_type = VAR_UNKNOWN;
                if (functv.v_type == VAR_PARTIAL) {
                    pt = functv.vval.v_partial;
                    s = partial_name (pt);
                }
                else
                    s = functv.vval.v_string;
            }
            else
                s = (char_u *) "";
            ret = get_func_tv (s, (int) STRLEN (s), rettv, arg, curwin->w_cursor.lnum, curwin->w_cursor.lnum, &len, evaluate, pt, selfdict);
            if (evaluate)
                clear_tv (&functv);
            if (aborting ()) {
                if (ret == OK)
                    clear_tv (rettv);
                ret = FAIL;
            }
            dict_unref (selfdict);
            selfdict = NULL;
        }
        else {
            dict_unref (selfdict);
            if (rettv->v_type == VAR_DICT) {
                selfdict = rettv->vval.v_dict;
                if (selfdict != NULL)
                    ++selfdict->dv_refcount;
            }
            else
                selfdict = NULL;
            if (eval_index (arg, rettv, evaluate, verbose) == FAIL) {
                clear_tv (rettv);
                ret = FAIL;
            }
        }
    }
    if (selfdict != NULL && (rettv->v_type == VAR_FUNC || (rettv->v_type == VAR_PARTIAL && (rettv->vval.v_partial->pt_auto || rettv->vval.v_partial->pt_dict == NULL))))
        selfdict = make_partial (selfdict, rettv);
    dict_unref (selfdict);
    return ret;
}

static int eval_index (char_u **arg, typval_T *rettv, int evaluate, int verbose) {
    int empty1 = FALSE, empty2 = FALSE;
    typval_T var1, var2;
    long  n1, n2 = 0;
    long  len = -1;
    int range = FALSE;
    char_u *s;
    char_u *key = NULL;
    switch (rettv->v_type) {
    case VAR_FUNC :
    case VAR_PARTIAL :
        if (verbose)
            EMSG (_ ("E695: Cannot index a Funcref"));
        return FAIL;
    case VAR_FLOAT :
        if (verbose)
            EMSG (_ (e_float_as_string));
        return FAIL;
    case VAR_SPECIAL :
    case VAR_JOB :
    case VAR_CHANNEL :
        if (verbose)
            EMSG (_ ("E909: Cannot index a special variable"));
        return FAIL;
    case VAR_UNKNOWN :
        if (evaluate)
            return FAIL;
    case VAR_STRING :
    case VAR_NUMBER :
    case VAR_LIST :
    case VAR_DICT :
        break;
    }
    init_tv (& var1);
    init_tv (& var2);
    if (**arg == '.') {
        key = *arg + 1;
        for (len = 0; ASCII_ISALNUM (key[len]) || key[len] == '_'; ++len)
            ;
        if (len == 0)
            return FAIL;
        *arg = skipwhite (key +len);
    }
    else {
        *arg = skipwhite (*arg + 1);
        if (**arg == ':')
            empty1 = TRUE;
        else if (eval1 (arg, &var1, evaluate) == FAIL)
            return FAIL;
        else if (evaluate && get_tv_string_chk (&var1) == NULL) {
            clear_tv (& var1);
            return FAIL;
        }
        if (**arg == ':') {
            range = TRUE;
            *arg = skipwhite (*arg + 1);
            if (**arg == ']')
                empty2 = TRUE;
            else if (eval1 (arg, &var2, evaluate) == FAIL) {
                if (!empty1)
                    clear_tv (&var1);
                return FAIL;
            }
            else if (evaluate && get_tv_string_chk (&var2) == NULL) {
                if (!empty1)
                    clear_tv (&var1);
                clear_tv (& var2);
                return FAIL;
            }
        }
        if (**arg != ']') {
            if (verbose)
                EMSG (_ (e_missbrac));
            clear_tv (& var1);
            if (range)
                clear_tv (&var2);
            return FAIL;
        }
        *arg = skipwhite (*arg + 1);
    }
    if (evaluate) {
        n1 = 0;
        if (!empty1 && rettv->v_type != VAR_DICT) {
            n1 = get_tv_number (&var1);
            clear_tv (& var1);
        }
        if (range) {
            if (empty2)
                n2 = -1;
            else {
                n2 = get_tv_number (&var2);
                clear_tv (& var2);
            }
        }
        switch (rettv->v_type) {
        case VAR_UNKNOWN :
        case VAR_FUNC :
        case VAR_PARTIAL :
        case VAR_FLOAT :
        case VAR_SPECIAL :
        case VAR_JOB :
        case VAR_CHANNEL :
            break;
        case VAR_NUMBER :
        case VAR_STRING :
            s = get_tv_string (rettv);
            len = (long ) STRLEN (s);
            if (range) {
                if (n1 < 0) {
                    n1 = len + n1;
                    if (n1 < 0)
                        n1 = 0;
                }
                if (n2 < 0)
                    n2 = len + n2;
                else if (n2 >= len)
                    n2 = len;
                if (n1 >= len || n2 < 0 || n1 > n2)
                    s = NULL;
                else
                    s = vim_strnsave (s +n1, (int) (n2 - n1 + 1));
            }
            else {
                if (n1 >= len || n1 < 0)
                    s = NULL;
                else
                    s = vim_strnsave (s +n1, 1);
            }
            clear_tv (rettv);
            rettv->v_type = VAR_STRING;
            rettv->vval.v_string = s;
            break;
        case VAR_LIST :
            len = list_len (rettv->vval.v_list);
            if (n1 < 0)
                n1 = len + n1;
            if (!empty1 && (n1 < 0 || n1 >= len)) {
                if (!range) {
                    if (verbose)
                        EMSGN (_ (e_listidx), n1);
                    return FAIL;
                }
                n1 = len;
            }
            if (range) {
                list_T *l;
                listitem_T *item;
                if (n2 < 0)
                    n2 = len + n2;
                else if (n2 >= len)
                    n2 = len - 1;
                if (!empty2 && (n2 < 0 || n2 + 1 < n1))
                    n2 = -1;
                l = list_alloc ();
                if (l == NULL)
                    return FAIL;
                for (item = list_find (rettv->vval.v_list, n1); n1 <= n2; ++n1) {
                    if (list_append_tv (l, &item->li_tv) == FAIL) {
                        list_free (l);
                        return FAIL;
                    }
                    item = item->li_next;
                }
                clear_tv (rettv);
                rettv_list_set (rettv, l);
            }
            else {
                copy_tv (& list_find (rettv -> vval.v_list, n1) -> li_tv, & var1);
                clear_tv (rettv);
                *rettv = var1;
            }
            break;
        case VAR_DICT :
            if (range) {
                if (verbose)
                    EMSG (_ (e_dictrange));
                if (len == -1)
                    clear_tv (&var1);
                return FAIL;
            }
            {
                dictitem_T *item;
                if (len == -1) {
                    key = get_tv_string_chk (&var1);
                    if (key == NULL) {
                        clear_tv (& var1);
                        return FAIL;
                    }
                }
                item = dict_find (rettv->vval.v_dict, key, (int) len);
                if (item == NULL && verbose)
                    EMSG2 (_ (e_dictkey), key);
                if (len == -1)
                    clear_tv (&var1);
                if (item == NULL)
                    return FAIL;
                copy_tv (& item -> di_tv, & var1);
                clear_tv (rettv);
                *rettv = var1;
            }
            break;
        }
    }
    return OK;
}

int item_copy (typval_T *from, typval_T *to, int deep, int copyID) {
    static int recurse = 0;
    int ret = OK;
    if (recurse >= DICT_MAXNEST) {
        EMSG (_ ("E698: variable nested too deep for making a copy"));
        return FAIL;
    }
    ++recurse;
    switch (from->v_type) {
    case VAR_NUMBER :
    case VAR_FLOAT :
    case VAR_STRING :
    case VAR_FUNC :
    case VAR_PARTIAL :
    case VAR_SPECIAL :
    case VAR_JOB :
    case VAR_CHANNEL :
        copy_tv (from, to);
        break;
    case VAR_LIST :
        to->v_type = VAR_LIST;
        to->v_lock = 0;
        if (from->vval.v_list == NULL)
            to->vval.v_list = NULL;
        else if (copyID != 0 && from->vval.v_list->lv_copyID == copyID) {
            to->vval.v_list = from->vval.v_list->lv_copylist;
            ++to->vval.v_list->lv_refcount;
        }
        else
            to->vval.v_list = list_copy (from->vval.v_list, deep, copyID);
        if (to->vval.v_list == NULL)
            ret = FAIL;
        break;
    case VAR_DICT :
        to->v_type = VAR_DICT;
        to->v_lock = 0;
        if (from->vval.v_dict == NULL)
            to->vval.v_dict = NULL;
        else if (copyID != 0 && from->vval.v_dict->dv_copyID == copyID) {
            to->vval.v_dict = from->vval.v_dict->dv_copydict;
            ++to->vval.v_dict->dv_refcount;
        }
        else
            to->vval.v_dict = dict_copy (from->vval.v_dict, deep, copyID);
        if (to->vval.v_dict == NULL)
            ret = FAIL;
        break;
    case VAR_UNKNOWN :
        internal_error ("item_copy(UNKNOWN)");
        ret = FAIL;
    }
    --recurse;
    return ret;
}

int eval_foldexpr (char_u *arg, int *cp) {
    typval_T tv;
    varnumber_T retval;
    char_u *s;
    int use_sandbox = was_set_insecurely ((char_u *) "foldexpr", OPT_LOCAL);
    ++emsg_off;
    if (use_sandbox)
        ++sandbox;
    ++textlock;
    *cp = NUL;
    if (eval0 (arg, &tv, NULL, TRUE) == FAIL)
        retval = 0;
    else {
        if (tv.v_type == VAR_NUMBER)
            retval = tv.vval.v_number;
        else if (tv.v_type != VAR_STRING || tv.vval.v_string == NULL)
            retval = 0;
        else {
            s = tv.vval.v_string;
            if (!VIM_ISDIGIT (*s) && *s != '-')
                *cp = *s++;
            retval = atol ((char *) s);
        }
        clear_tv (& tv);
    }
    --emsg_off;
    if (use_sandbox)
        --sandbox;
    --textlock;
    return (int) retval;
}

pos_T *var2fpos (typval_T *varp, int dollar_lnum, int *fnum) {
    char_u *name;
    static pos_T pos;
    pos_T *pp;
    if (varp->v_type == VAR_LIST) {
        list_T *l;
        int len;
        int error = FALSE;
        listitem_T *li;
        l = varp->vval.v_list;
        if (l == NULL)
            return NULL;
        pos.lnum = list_find_nr (l, 0L, &error);
        if (error || pos.lnum <= 0 || pos.lnum > curbuf->b_ml.ml_line_count)
            return NULL;
        pos.col = list_find_nr (l, 1L, &error);
        if (error)
            return NULL;
        len = (long ) STRLEN (ml_get (pos.lnum));
        li = list_find (l, 1L);
        if (li != NULL && li->li_tv.v_type == VAR_STRING && li->li_tv.vval.v_string != NULL && STRCMP (li->li_tv.vval.v_string, "$") == 0)
            pos.col = len + 1;
        if (pos.col == 0 || (int) pos.col > len + 1)
            return NULL;
        --pos.col;
        pos.coladd = list_find_nr (l, 2L, &error);
        if (error)
            pos.coladd = 0;
        return &pos;
    }
    name = get_tv_string_chk (varp);
    if (name == NULL)
        return NULL;
    if (name[0] == '.')
        return &curwin->w_cursor;
    if (name[0] == 'v' && name[1] == NUL) {
        if (VIsual_active)
            return &VIsual;
        return &curwin->w_cursor;
    }
    if (name[0] == '\'') {
        pp = getmark_buf_fnum (curbuf, name[1], FALSE, fnum);
        if (pp == NULL || pp == (pos_T *) -1 || pp->lnum <= 0)
            return NULL;
        return pp;
    }
    pos.coladd = 0;
    if (name[0] == 'w' && dollar_lnum) {
        pos.col = 0;
        if (name[1] == '0') {
            update_topline ();
            pos.lnum = curwin->w_topline > 0 ? curwin->w_topline : 1;
            return &pos;
        }
        else if (name[1] == '$') {
            validate_botline ();
            pos.lnum = curwin->w_botline > 0 ? curwin->w_botline - 1 : 0;
            return &pos;
        }
    }
    else if (name[0] == '$') {
        if (dollar_lnum) {
            pos.lnum = curbuf->b_ml.ml_line_count;
            pos.col = 0;
        }
        else {
            pos.lnum = curwin->w_cursor.lnum;
            pos.col = (colnr_T) STRLEN (ml_get_curline ());
        }
        return &pos;
    }
    return NULL;
}

win_T *find_tabwin (typval_T *wvp, typval_T *tvp) {
    win_T *wp = NULL;
    tabpage_T *tp = NULL;
    long  n;
    if (wvp->v_type != VAR_UNKNOWN) {
        if (tvp->v_type != VAR_UNKNOWN) {
            n = (long ) get_tv_number (tvp);
            if (n >= 0)
                tp = find_tabpage (n);
        }
        else
            tp = curtab;
        if (tp != NULL)
            wp = find_win_by_nr (wvp, tp);
    }
    else
        wp = curwin;
    return wp;
}

win_T *find_win_by_nr (typval_T *vp, tabpage_T *tp) {
    win_T *wp;
    int nr;
    nr = (int) get_tv_number_chk (vp, NULL);
    if (nr < 0)
        return NULL;
    if (nr == 0)
        return curwin;
    FOR_ALL_WINDOWS_IN_TAB (tp, wp) {
        if (nr >= LOWEST_WIN_ID) {
            if (wp->w_id == nr)
                return wp;
        }
        else if (--nr <= 0)
            break;
    }
    if (nr >= LOWEST_WIN_ID)
        return NULL;
    return wp;
}

void assert_beeps (typval_T *argvars) {
    char_u *cmd = get_tv_string_chk (&argvars[0]);
    garray_T ga;
    called_vim_beep = FALSE;
    suppress_errthrow = TRUE;
    emsg_silent = FALSE;
    do_cmdline_cmd (cmd);
    if (!called_vim_beep) {
        prepare_assert_error (& ga);
        ga_concat (& ga, (char_u *) "command did not beep: ");
        ga_concat (& ga, cmd);
        assert_error (& ga);
        ga_clear (& ga);
    }
    suppress_errthrow = FALSE;
    emsg_on_display = FALSE;
}

void prepare_assert_error (garray_T *gap) {
    char buf [NUMBUFLEN];
    ga_init2 (gap, 1, 100);
    if (sourcing_name != NULL) {
        ga_concat (gap, sourcing_name);
        if (sourcing_lnum > 0)
            ga_concat (gap, (char_u *) " ");
    }
    if (sourcing_lnum > 0) {
        sprintf (buf, "line %ld", (long) sourcing_lnum);
        ga_concat (gap, (char_u *) buf);
    }
    if (sourcing_name != NULL || sourcing_lnum > 0)
        ga_concat (gap, (char_u *) ": ");
}

void assert_error (garray_T *gap) {
    struct vimvar *vp = &vimvars[VV_ERRORS];
    if (vp->vv_type != VAR_LIST || vimvars[VV_ERRORS].vv_list == NULL)
        set_vim_var_list (VV_ERRORS, list_alloc ());
    list_append_string (vimvars [VV_ERRORS].vv_list, gap -> ga_data, gap -> ga_len);
}

void assert_equal_common (typval_T *argvars, assert_type_T atype) {
    garray_T ga;
    if (tv_equal (&argvars[0], &argvars[1], FALSE, FALSE) != (atype == ASSERT_EQUAL)) {
        prepare_assert_error (& ga);
        fill_assert_error (& ga, & argvars [2], NULL, & argvars [0], & argvars [1], atype);
        assert_error (& ga);
        ga_clear (& ga);
    }
}

void fill_assert_error (garray_T *gap, typval_T *opt_msg_tv, char_u *exp_str, typval_T *exp_tv, typval_T *got_tv, assert_type_T atype) {
    char_u numbuf [NUMBUFLEN];
    char_u *tofree;
    if (opt_msg_tv->v_type != VAR_UNKNOWN) {
        ga_concat (gap, echo_string (opt_msg_tv, & tofree, numbuf, 0));
        vim_free (tofree);
        ga_concat (gap, (char_u *) ": ");
    }
    if (atype == ASSERT_MATCH || atype == ASSERT_NOTMATCH)
        ga_concat (gap, (char_u *) "Pattern ");
    else if (atype == ASSERT_NOTEQUAL)
        ga_concat (gap, (char_u *) "Expected not equal to ");
    else
        ga_concat (gap, (char_u *) "Expected ");
    if (exp_str == NULL) {
        ga_concat_esc (gap, tv2string (exp_tv, & tofree, numbuf, 0));
        vim_free (tofree);
    }
    else
        ga_concat_esc (gap, exp_str);
    if (atype != ASSERT_NOTEQUAL) {
        if (atype == ASSERT_MATCH)
            ga_concat (gap, (char_u *) " does not match ");
        else if (atype == ASSERT_NOTMATCH)
            ga_concat (gap, (char_u *) " does match ");
        else
            ga_concat (gap, (char_u *) " but got ");
        ga_concat_esc (gap, tv2string (got_tv, & tofree, numbuf, 0));
        vim_free (tofree);
    }
}

static void ga_concat_esc (garray_T *gap, char_u *str) {
    char_u *p;
    char_u buf [NUMBUFLEN];
    if (str == NULL) {
        ga_concat (gap, (char_u *) "NULL");
        return;
    }
    for (p = str; *p != NUL; ++p)
        switch (*p) {
        case BS :
            ga_concat (gap, (char_u *) "\\b");
            break;
        case ESC :
            ga_concat (gap, (char_u *) "\\e");
            break;
        case FF :
            ga_concat (gap, (char_u *) "\\f");
            break;
        case NL :
            ga_concat (gap, (char_u *) "\\n");
            break;
        case TAB :
            ga_concat (gap, (char_u *) "\\t");
            break;
        case CAR :
            ga_concat (gap, (char_u *) "\\r");
            break;
        case '\\' :
            ga_concat (gap, (char_u *) "\\\\");
            break;
        default :
            if (*p < ' ') {
                vim_snprintf ((char *) buf, NUMBUFLEN, "\\x%02x", * p);
                ga_concat (gap, buf);
            }
            else
                ga_append (gap, *p);
            break;
        }
}

void assert_exception (typval_T *argvars) {
    garray_T ga;
    char_u *error = get_tv_string_chk (&argvars[0]);
    if (vimvars[VV_EXCEPTION].vv_str == NULL) {
        prepare_assert_error (& ga);
        ga_concat (& ga, (char_u *) "v:exception is not set");
        assert_error (& ga);
        ga_clear (& ga);
    }
    else if (error != NULL && strstr ((char *) vimvars[VV_EXCEPTION].vv_str, (char *) error) == NULL) {
        prepare_assert_error (& ga);
        fill_assert_error (& ga, & argvars [1], NULL, & argvars [0], & vimvars [VV_EXCEPTION].vv_tv, ASSERT_OTHER);
        assert_error (& ga);
        ga_clear (& ga);
    }
}

void assert_fails (typval_T *argvars) {
    char_u *cmd = get_tv_string_chk (&argvars[0]);
    garray_T ga;
    called_emsg = FALSE;
    suppress_errthrow = TRUE;
    emsg_silent = TRUE;
    do_cmdline_cmd (cmd);
    if (!called_emsg) {
        prepare_assert_error (& ga);
        ga_concat (& ga, (char_u *) "command did not fail: ");
        ga_concat (& ga, cmd);
        assert_error (& ga);
        ga_clear (& ga);
    }
    else if (argvars[1].v_type != VAR_UNKNOWN) {
        char_u buf [NUMBUFLEN];
        char *error = (char *) get_tv_string_buf_chk (&argvars[1], buf);
        if (error == NULL || strstr ((char *) vimvars[VV_ERRMSG].vv_str, error) == NULL) {
            prepare_assert_error (& ga);
            fill_assert_error (& ga, & argvars [2], NULL, & argvars [1], & vimvars [VV_ERRMSG].vv_tv, ASSERT_OTHER);
            assert_error (& ga);
            ga_clear (& ga);
        }
    }
    called_emsg = FALSE;
    suppress_errthrow = FALSE;
    emsg_silent = FALSE;
    emsg_on_display = FALSE;
    set_vim_var_string (VV_ERRMSG, NULL, 0);
}

void assert_bool (typval_T *argvars, int isTrue) {
    int error = FALSE;
    garray_T ga;
    if (argvars[0].v_type == VAR_SPECIAL && argvars[0].vval.v_number == (isTrue ? VVAL_TRUE : VVAL_FALSE))
        return;
    if (argvars[0].v_type != VAR_NUMBER || (get_tv_number_chk (&argvars[0], &error) == 0) == isTrue || error) {
        prepare_assert_error (& ga);
        fill_assert_error (& ga, & argvars [1], (char_u *) (isTrue ? "True" : "False"), NULL, & argvars [0], ASSERT_OTHER);
        assert_error (& ga);
        ga_clear (& ga);
    }
}

void assert_inrange (typval_T *argvars) {
    garray_T ga;
    int error = FALSE;
    varnumber_T lower = get_tv_number_chk (&argvars[0], &error);
    varnumber_T upper = get_tv_number_chk (&argvars[1], &error);
    varnumber_T actual = get_tv_number_chk (&argvars[2], &error);
    char_u *tofree;
    char msg [200];
    char_u numbuf [NUMBUFLEN];
    if (error)
        return;
    if (actual < lower || actual > upper) {
        prepare_assert_error (& ga);
        if (argvars[3].v_type != VAR_UNKNOWN) {
            ga_concat (& ga, tv2string (& argvars [3], & tofree, numbuf, 0));
            vim_free (tofree);
        }
        else {
            vim_snprintf (msg, 200, "Expected range %ld - %ld, but got %ld", (long) lower, (long) upper, (long) actual);
            ga_concat (& ga, (char_u *) msg);
        }
        assert_error (& ga);
        ga_clear (& ga);
    }
}

void assert_match_common (typval_T *argvars, assert_type_T atype) {
    garray_T ga;
    char_u buf1 [NUMBUFLEN];
    char_u buf2 [NUMBUFLEN];
    char_u *pat = get_tv_string_buf_chk (&argvars[0], buf1);
    char_u *text = get_tv_string_buf_chk (&argvars[1], buf2);
    if (pat == NULL || text == NULL)
        EMSG (_ (e_invarg));
    else if (pattern_match (pat, text, FALSE) != (atype == ASSERT_MATCH)) {
        prepare_assert_error (& ga);
        fill_assert_error (& ga, & argvars [2], NULL, & argvars [0], & argvars [1], atype);
        assert_error (& ga);
        ga_clear (& ga);
    }
}

void assert_report (typval_T *argvars) {
    garray_T ga;
    prepare_assert_error (& ga);
    ga_concat (& ga, get_tv_string (& argvars [0]));
    assert_error (& ga);
    ga_clear (& ga);
}

int list2fpos (typval_T *arg, pos_T *posp, int *fnump, colnr_T *curswantp) {
    list_T *l = arg->vval.v_list;
    long  i = 0;
    long  n;
    if (arg->v_type != VAR_LIST || l == NULL || l->lv_len < (fnump == NULL ? 2 : 3) || l->lv_len > (fnump == NULL ? 4 : 5))
        return FAIL;
    if (fnump != NULL) {
        n = list_find_nr (l, i++, NULL);
        if (n < 0)
            return FAIL;
        if (n == 0)
            n = curbuf->b_fnum;
        *fnump = n;
    }
    n = list_find_nr (l, i++, NULL);
    if (n < 0)
        return FAIL;
    posp->lnum = n;
    n = list_find_nr (l, i++, NULL);
    if (n < 0)
        return FAIL;
    posp->col = n;
    n = list_find_nr (l, i, NULL);
    if (n < 0)
        posp->coladd = 0;
    else
        posp->coladd = n;
    if (curswantp != NULL)
        *curswantp = list_find_nr (l, i +1, NULL);
    return OK;
}

int var_exists (char_u *var) {
    char_u *name;
    char_u *tofree;
    typval_T tv;
    int len = 0;
    int n = FALSE;
    name = var;
    len = get_name_len (&var, &tofree, TRUE, FALSE);
    if (len > 0) {
        if (tofree != NULL)
            name = tofree;
        n = (get_var_tv (name, len, &tv, NULL, FALSE, TRUE) == OK);
        if (n) {
            n = (handle_subscript (&var, &tv, TRUE, FALSE) == OK);
            if (n)
                clear_tv (&tv);
        }
    }
    if (*var != NUL)
        n = FALSE;
    vim_free (tofree);
    return n;
}

void filter_map (typval_T *argvars, typval_T *rettv, int map) {
    typval_T *expr;
    listitem_T *li, *nli;
    list_T *l = NULL;
    dictitem_T *di;
    hashtab_T *ht;
    hashitem_T *hi;
    dict_T *d = NULL;
    typval_T save_val;
    typval_T save_key;
    int rem;
    int todo;
    char_u *ermsg = (char_u *) (map ? "map()" : "filter()");
    char_u *arg_errmsg = (char_u *) (map ? N_ ("map() argument") : N_ ("filter() argument"));
    int save_did_emsg;
    int idx = 0;
    if (argvars[0].v_type == VAR_LIST) {
        if ((l = argvars[0].vval.v_list) == NULL || (!map && tv_check_lock (l->lv_lock, arg_errmsg, TRUE)))
            return;
    }
    else if (argvars[0].v_type == VAR_DICT) {
        if ((d = argvars[0].vval.v_dict) == NULL || (!map && tv_check_lock (d->dv_lock, arg_errmsg, TRUE)))
            return;
    }
    else {
        EMSG2 (_ (e_listdictarg), ermsg);
        return;
    }
    expr = &argvars[1];
    if (expr->v_type != VAR_UNKNOWN) {
        prepare_vimvar (VV_VAL, & save_val);
        save_did_emsg = did_emsg;
        did_emsg = FALSE;
        prepare_vimvar (VV_KEY, & save_key);
        if (argvars[0].v_type == VAR_DICT) {
            vimvars[VV_KEY].vv_type = VAR_STRING;
            ht = &d->dv_hashtab;
            hash_lock (ht);
            todo = (int) ht->ht_used;
            for (hi = ht->ht_array; todo > 0; ++hi) {
                if (!HASHITEM_EMPTY (hi)) {
                    int r;
                    --todo;
                    di = HI2DI (hi);
                    if (map && (tv_check_lock (di->di_tv.v_lock, arg_errmsg, TRUE) || var_check_ro (di->di_flags, arg_errmsg, TRUE)))
                        break;
                    vimvars[VV_KEY].vv_str = vim_strsave (di->di_key);
                    r = filter_map_one (&di->di_tv, expr, map, &rem);
                    clear_tv (& vimvars [VV_KEY].vv_tv);
                    if (r == FAIL || did_emsg)
                        break;
                    if (!map && rem) {
                        if (var_check_fixed (di->di_flags, arg_errmsg, TRUE) || var_check_ro (di->di_flags, arg_errmsg, TRUE))
                            break;
                        dictitem_remove (d, di);
                    }
                }
            }
            hash_unlock (ht);
        }
        else {
            vimvars[VV_KEY].vv_type = VAR_NUMBER;
            for (li = l->lv_first; li != NULL; li = nli) {
                if (map && tv_check_lock (li->li_tv.v_lock, arg_errmsg, TRUE))
                    break;
                nli = li->li_next;
                vimvars[VV_KEY].vv_nr = idx;
                if (filter_map_one (&li->li_tv, expr, map, &rem) == FAIL || did_emsg)
                    break;
                if (!map && rem)
                    listitem_remove (l, li);
                ++idx;
            }
        }
        restore_vimvar (VV_KEY, & save_key);
        restore_vimvar (VV_VAL, & save_val);
        did_emsg |= save_did_emsg;
    }
    copy_tv (& argvars [0], rettv);
}

static int filter_map_one (typval_T *tv, typval_T *expr, int map, int *remp) {
    typval_T rettv;
    typval_T argv [3];
    int retval = FAIL;
    copy_tv (tv, & vimvars [VV_VAL].vv_tv);
    argv[0] = vimvars[VV_KEY].vv_tv;
    argv[1] = vimvars[VV_VAL].vv_tv;
    if (eval_expr_typval (expr, argv, 2, &rettv) == FAIL)
        goto theend;
    if (map) {
        clear_tv (tv);
        rettv.v_lock = 0;
        *tv = rettv;
    }
    else {
        int error = FALSE;
        *remp = (get_tv_number_chk (&rettv, &error) == 0);
        clear_tv (& rettv);
        if (error)
            goto theend;
    }
    retval = OK;
theend :
    clear_tv (&vimvars[VV_VAL].vv_tv);
    return retval;
}

static int eval_expr_typval (typval_T *expr, typval_T *argv, int argc, typval_T *rettv) {
    char_u *s;
    int dummy;
    char_u buf [NUMBUFLEN];
    if (expr->v_type == VAR_FUNC) {
        s = expr->vval.v_string;
        if (s == NULL || *s == NUL)
            return FAIL;
        if (call_func (s, (int) STRLEN (s), rettv, argc, argv, NULL, 0L, 0L, &dummy, TRUE, NULL, NULL) == FAIL)
            return FAIL;
    }
    else if (expr->v_type == VAR_PARTIAL) {
        partial_T *partial = expr->vval.v_partial;
        s = partial_name (partial);
        if (s == NULL || *s == NUL)
            return FAIL;
        if (call_func (s, (int) STRLEN (s), rettv, argc, argv, NULL, 0L, 0L, &dummy, TRUE, partial, NULL) == FAIL)
            return FAIL;
    }
    else {
        s = get_tv_string_buf_chk (expr, buf);
        if (s == NULL)
            return FAIL;
        s = skipwhite (s);
        if (eval1 (&s, rettv, TRUE) == FAIL)
            return FAIL;
        if (*s != NUL) {
            EMSG2 (_ (e_invexpr2), s);
            return FAIL;
        }
    }
    return OK;
}

void getwinvar (typval_T *argvars, typval_T *rettv, int off) {
    win_T *win;
    char_u *varname;
    dictitem_T *v;
    tabpage_T *tp = NULL;
    int done = FALSE;
    win_T *oldcurwin;
    tabpage_T *oldtabpage;
    int need_switch_win;
    if (off == 1)
        tp = find_tabpage ((int) get_tv_number_chk (&argvars[0], NULL));
    else
        tp = curtab;
    win = find_win_by_nr (&argvars[off], tp);
    varname = get_tv_string_chk (&argvars[off + 1]);
    ++emsg_off;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    if (win != NULL && varname != NULL) {
        need_switch_win = !(tp == curtab && win == curwin);
        if (!need_switch_win || switch_win (&oldcurwin, &oldtabpage, win, tp, TRUE) == OK) {
            if (*varname == '&') {
                if (varname[1] == NUL) {
                    dict_T *opts = get_winbuf_options (FALSE);
                    if (opts != NULL) {
                        rettv_dict_set (rettv, opts);
                        done = TRUE;
                    }
                }
                else if (get_option_tv (&varname, rettv, 1) == OK)
                    done = TRUE;
            }
            else {
                v = find_var_in_ht (&win->w_vars->dv_hashtab, 'w', varname, FALSE);
                if (v != NULL) {
                    copy_tv (& v -> di_tv, rettv);
                    done = TRUE;
                }
            }
        }
        if (need_switch_win)
            restore_win (oldcurwin, oldtabpage, TRUE);
    }
    if (!done && argvars[off + 2].v_type != VAR_UNKNOWN)
        copy_tv (&argvars[off + 2], rettv);
    --emsg_off;
}

void get_user_input (typval_T *argvars, typval_T *rettv, int inputdialog, int secret) {
    char_u *prompt = get_tv_string_chk (&argvars[0]);
    char_u *p = NULL;
    int c;
    char_u buf [NUMBUFLEN];
    int cmd_silent_save = cmd_silent;
    char_u *defstr = (char_u *) "";
    int xp_type = EXPAND_NOTHING;
    char_u *xp_arg = NULL;
    rettv->v_type = VAR_STRING;
    rettv->vval.v_string = NULL;
    cmd_silent = FALSE;
    if (prompt != NULL) {
        p = vim_strrchr (prompt, '\n');
        if (p == NULL)
            p = prompt;
        else {
            ++p;
            c = *p;
            *p = NUL;
            msg_start ();
            msg_clr_eos ();
            msg_puts_attr (prompt, echo_attr);
            msg_didout = FALSE;
            msg_starthere ();
            *p = c;
        }
        cmdline_row = msg_row;
        if (argvars[1].v_type != VAR_UNKNOWN) {
            defstr = get_tv_string_buf_chk (&argvars[1], buf);
            if (defstr != NULL)
                stuffReadbuffSpec (defstr);
            if (!inputdialog && argvars[2].v_type != VAR_UNKNOWN) {
                char_u *xp_name;
                int xp_namelen;
                long  argt;
                rettv->vval.v_string = NULL;
                xp_name = get_tv_string_buf_chk (&argvars[2], buf);
                if (xp_name == NULL)
                    return;
                xp_namelen = (int) STRLEN (xp_name);
                if (parse_compl_arg (xp_name, xp_namelen, &xp_type, &argt, &xp_arg) == FAIL)
                    return;
            }
        }
        if (defstr != NULL) {
            int save_ex_normal_busy = ex_normal_busy;
            ex_normal_busy = 0;
            rettv->vval.v_string = getcmdline_prompt (secret ? NUL : '@', p, echo_attr, xp_type, xp_arg);
            ex_normal_busy = save_ex_normal_busy;
        }
        if (inputdialog && rettv->vval.v_string == NULL && argvars[1].v_type != VAR_UNKNOWN && argvars[2].v_type != VAR_UNKNOWN)
            rettv->vval.v_string = vim_strsave (get_tv_string_buf (&argvars[2], buf));
        vim_free (xp_arg);
        need_wait_return = FALSE;
        msg_didout = FALSE;
    }
    cmd_silent = cmd_silent_save;
}

int eval_expr_to_bool (typval_T *expr, int *error) {
    typval_T rettv;
    int res;
    if (eval_expr_typval (expr, NULL, 0, &rettv) == FAIL) {
        *error = TRUE;
        return FALSE;
    }
    res = (get_tv_number_chk (&rettv, error) != 0);
    clear_tv (& rettv);
    return res;
}

void setwinvar (typval_T *argvars, typval_T *rettv, int off) {
    win_T *win;
    win_T *save_curwin;
    tabpage_T *save_curtab;
    int need_switch_win;
    char_u *varname, *winvarname;
    typval_T *varp;
    char_u nbuf [NUMBUFLEN];
    tabpage_T *tp = NULL;
    if (check_restricted () || check_secure ())
        return;
    if (off == 1)
        tp = find_tabpage ((int) get_tv_number_chk (&argvars[0], NULL));
    else
        tp = curtab;
    win = find_win_by_nr (&argvars[off], tp);
    varname = get_tv_string_chk (&argvars[off + 1]);
    varp = &argvars[off + 2];
    if (win != NULL && varname != NULL && varp != NULL) {
        need_switch_win = !(tp == curtab && win == curwin);
        if (!need_switch_win || switch_win (&save_curwin, &save_curtab, win, tp, TRUE) == OK) {
            if (*varname == '&') {
                long  numval;
                char_u *strval;
                int error = FALSE;
                ++varname;
                numval = (long ) get_tv_number_chk (varp, &error);
                strval = get_tv_string_buf_chk (varp, nbuf);
                if (!error && strval != NULL)
                    set_option_value (varname, numval, strval, OPT_LOCAL);
            }
            else {
                winvarname = alloc ((unsigned ) STRLEN (varname) + 3);
                if (winvarname != NULL) {
                    STRCPY (winvarname, "w:");
                    STRCPY (winvarname + 2, varname);
                    set_var (winvarname, varp, TRUE);
                    vim_free (winvarname);
                }
            }
        }
        if (need_switch_win)
            restore_win (save_curwin, save_curtab, TRUE);
    }
}

float_T get_tv_float (typval_T *varp) {
    switch (varp->v_type) {
    case VAR_NUMBER :
        return (float_T) (varp->vval.v_number);
    case VAR_FLOAT :
        return varp->vval.v_float;
    case VAR_FUNC :
    case VAR_PARTIAL :
        EMSG (_ ("E891: Using a Funcref as a Float"));
        break;
    case VAR_STRING :
        EMSG (_ ("E892: Using a String as a Float"));
        break;
    case VAR_LIST :
        EMSG (_ ("E893: Using a List as a Float"));
        break;
    case VAR_DICT :
        EMSG (_ ("E894: Using a Dictionary as a Float"));
        break;
    case VAR_SPECIAL :
        EMSG (_ ("E907: Using a special value as a Float"));
        break;
    case VAR_JOB :
        EMSG (_ ("E911: Using a Job as a Float"));
        break;
    case VAR_CHANNEL :
        EMSG (_ ("E914: Using a Channel as a Float"));
        break;
    case VAR_UNKNOWN :
        internal_error ("get_tv_float(UNKNOWN)");
        break;
    }
    return 0;
}

