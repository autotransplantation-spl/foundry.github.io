
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
struct spat {
    char_u *pat;
    int magic;
    int no_scs;
    struct soffset off;
};
struct soffset {
    int dir;
    int line;
    int end;
    long  off;
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
EXTERN char_u *p_para;
EXTERN int p_altkeymap;
EXTERN int p_ws;
EXTERN char_u e_interr [] INIT (= N_ ("Interrupted"));
EXTERN int p_js;
EXTERN long  p_verbose;
EXTERN char_u *p_def;
EXTERN long  p_mat;
EXTERN long  p_siso;
EXTERN long  p_so;
EXTERN int p_ri;
EXTERN char_u e_nopresub [] INIT (= N_ ("E33: No previous substitute regular expression"));
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u *p_titlestring;
EXTERN int arrow_used;
EXTERN int mouse_row;
EXTERN char_u e_toomanyarg [] INIT (= N_ ("E118: Too many arguments for function: %s"));
EXTERN char_u e_argreq [] INIT (= N_ ("E471: Argument required"));
EXTERN char_u e_shellempty [] INIT (= N_ ("E91: 'shell' option is empty"));
EXTERN char_u e_emptykey [] INIT (= N_ ("E713: Cannot use empty key for Dictionary"));
EXTERN char_u *empty_option INIT (= (char_u *) "");
EXTERN char_u e_listreq [] INIT (= N_ ("E714: List required"));
EXTERN alist_T global_alist;
SPELL_EXTERN char_u *int_wordlist SPELL_INIT (= NULL);
EXTERN char_u e_readonlyvar [] INIT (= N_ ("E46: Cannot change read-only variable \"%s\""));
EXTERN char_u e_noroom [] INIT (= N_ ("E36: Not enough room"));
EXTERN char_u e_invarg2 [] INIT (= N_ ("E475: Invalid argument: %s"));
EXTERN char_u e_invarg [] INIT (= N_ ("E474: Invalid argument"));
int save_level = 0;
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
EXTERN char need_key_msg [] INIT (= N_ ("Need encryption key for \"%s\""));
EXTERN struct msglist **msg_list INIT (= NULL);
EXTERN char_u *keep_msg INIT (= NULL);
EXTERN int msg_row;
EXTERN char_u e_noprevre [] INIT (= N_ ("E35: No previous regular expression"));
EXTERN char_u e_noprev [] INIT (= N_ ("E34: No previous command"));
EXTERN win_T *prevwin INIT (= NULL);
EXTERN tabpage_T *first_tabpage;
SPELL_EXTERN spelltab_T spelltab;
EXTERN char_u e_umark [] INIT (= N_ ("E78: Unknown mark"));
EXTERN char_u e_marknotset [] INIT (= N_ ("E20: Mark not set"));
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
EXTERN char_u e_patnotf2 [] INIT (= N_ ("E486: Pattern not found: %s"));
EXTERN char_u e_patnotf [] INIT (= N_ ("Pattern not found"));
EXTERN char_u *p_path;
struct spat saved_spats [2];
struct spat spats [2] = {{NULL, TRUE, FALSE, {'/', 0, 0, 0L}}, {NULL, TRUE, FALSE, {'/', 0, 0, 0L}}};
EXTERN char_u e_dirnotf [] INIT (= N_ ("E919: Directory not found in '%s': \"%s\""));
EXTERN char_u e_prev_dir [] INIT (= N_ ("E459: Cannot go back to previous directory"));
EXTERN char_u e_isadir2 [] INIT (= N_ ("E17: \"%s\" is a directory"));
EXTERN char_u e_endfor [] INIT (= N_ ("E170: Missing :endfor"));
EXTERN char_u e_endwhile [] INIT (= N_ ("E170: Missing :endwhile"));
EXTERN char_u e_endtry [] INIT (= N_ ("E600: Missing :endtry"));
EXTERN char_u e_endif [] INIT (= N_ ("E171: Missing :endif"));
EXTERN linenr_T sub_nlines;
EXTERN char_u no_lines_msg [] INIT (= N_ ("--No lines in buffer--"));
EXTERN char_u *globaldir INIT (= NULL);
EXTERN FILE *redir_fd INIT (= NULL);
EXTERN char_u *vim_tempdir INIT (= NULL);
EXTERN win_T *au_pending_free_win INIT (= NULL);
EXTERN char_u *p_vdir;
EXTERN char_u *p_udir;
EXTERN char_u *p_dir;
EXTERN char_u *p_bdir;
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
int cls_bigword;
struct spat saved_last_search_spat;
int last_t_cmd = TRUE;
int lastcdir = FORWARD;
char_u lastc [2] = {NUL, NUL};
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
int saved_no_hlsearch = 0;
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
int saved_last_idx = 0;
int last_idx = 0;
EXTERN int autocmd_fname_full;
EXTERN char_u *autocmd_fname INIT (= NULL);
EXTERN unsigned  swb_flags;
EXTERN pos_T where_paste_started;
int mr_pattern_alloced = FALSE;
char_u *mr_pattern = NULL;
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

void save_search_patterns (void) {
    if (save_level++ == 0) {
        saved_spats[0] = spats[0];
        if (spats[0].pat != NULL)
            saved_spats[0].pat = vim_strsave (spats[0].pat);
        saved_spats[1] = spats[1];
        if (spats[1].pat != NULL)
            saved_spats[1].pat = vim_strsave (spats[1].pat);
        saved_last_idx = last_idx;
        saved_no_hlsearch = no_hlsearch;
    }
}

void set_last_search_pat (char_u *s, int idx, int magic, int setlast) {
    if (RE_SEARCH == idx)
        gui_macvim_add_to_find_pboard (s);
    vim_free (spats [idx].pat);
    if (*s == NUL)
        spats[idx].pat = NULL;
    else
        spats[idx].pat = vim_strsave (s);
    spats[idx].magic = magic;
    spats[idx].no_scs = FALSE;
    spats[idx].off.dir = '/';
    set_vv_searchforward ();
    spats[idx].off.line = FALSE;
    spats[idx].off.end = FALSE;
    spats[idx].off.off = 0;
    if (setlast)
        last_idx = idx;
    if (save_level) {
        vim_free (saved_spats [idx].pat);
        saved_spats[idx] = spats[0];
        if (spats[idx].pat == NULL)
            saved_spats[idx].pat = NULL;
        else
            saved_spats[idx].pat = vim_strsave (spats[idx].pat);
        saved_last_idx = last_idx;
    }
    if (p_hls && idx == last_idx && !no_hlsearch)
        redraw_all_later (SOME_VALID);
}

static void set_vv_searchforward (void) {
    set_vim_var_nr (VV_SEARCHFORWARD, (long) (spats [0].off.dir == '/'));
}

int read_viminfo_search_pattern (vir_T *virp, int force) {
    char_u *lp;
    int idx = -1;
    int magic = FALSE;
    int no_scs = FALSE;
    int off_line = FALSE;
    int off_end = 0;
    long  off = 0;
    int setlast = FALSE;
    static int hlsearch_on = FALSE;
    char_u *val;
    lp = virp->vir_line;
    if (lp[0] == '~' && (lp[1] == 'm' || lp[1] == 'M')) {
        if (lp[1] == 'M')
            magic = TRUE;
        if (lp[2] == 's')
            no_scs = TRUE;
        if (lp[3] == 'L')
            off_line = TRUE;
        if (lp[4] == 'E')
            off_end = SEARCH_END;
        lp += 5;
        off = getdigits (&lp);
    }
    if (lp[0] == '~') {
        setlast = TRUE;
        lp++;
    }
    if (lp[0] == '/')
        idx = RE_SEARCH;
    else if (lp[0] == '&')
        idx = RE_SUBST;
    else if (lp[0] == 'h')
        hlsearch_on = FALSE;
    else if (lp[0] == 'H')
        hlsearch_on = TRUE;
    if (idx >= 0) {
        if (force || spats[idx].pat == NULL) {
            val = viminfo_readstring (virp, (int) (lp - virp->vir_line + 1), TRUE);
            if (val != NULL) {
                set_last_search_pat (val, idx, magic, setlast);
                vim_free (val);
                spats[idx].no_scs = no_scs;
                spats[idx].off.line = off_line;
                spats[idx].off.end = off_end;
                spats[idx].off.off = off;
                if (setlast) {
                    SET_NO_HLSEARCH (! hlsearch_on);
                }
            }
        }
    }
    return viminfo_readline (virp);
}

void write_viminfo_search_pattern (FILE *fp) {
    if (get_viminfo_parameter ('/') != 0) {
        fprintf (fp, "\n# hlsearch on (H) or off (h):\n~%c", (no_hlsearch || find_viminfo_parameter ('h') != NULL) ? 'h' : 'H');
        wvsp_one (fp, RE_SEARCH, "", '/');
        wvsp_one (fp, RE_SUBST, _ ("Substitute "), '&');
    }
}

static void wvsp_one (FILE *fp, int idx, char *s, int sc) {
    if (spats[idx].pat != NULL) {
        fprintf (fp, _ ("\n# Last %sSearch Pattern:\n~"), s);
        fprintf (fp, "%c%c%c%c%ld%s%c", spats [idx].magic ? 'M' : 'm', spats [idx].no_scs ? 's' : 'S', spats [idx].off.line ? 'L' : 'l', spats [idx].off.end ? 'E' : 'e', spats [idx].off.off, last_idx == idx ? "~" : "", sc);
        viminfo_writestring (fp, spats [idx].pat);
    }
}

void last_pat_prog (regmmatch_T *regmatch) {
    if (spats[last_idx].pat == NULL) {
        regmatch->regprog = NULL;
        return;
    }
    ++emsg_off;
    (void) search_regcomp ((char_u *) "", 0, last_idx, SEARCH_KEEP, regmatch);
    --emsg_off;
}

int search_regcomp (char_u *pat, int pat_save, int pat_use, int options, regmmatch_T *regmatch) {
    int magic;
    int i;
    rc_did_emsg = FALSE;
    magic = p_magic;
    if (pat == NULL || *pat == NUL) {
        if (pat_use == RE_LAST)
            i = last_idx;
        else
            i = pat_use;
        if (spats[i].pat == NULL) {
            if (pat_use == RE_SUBST)
                EMSG (_ (e_nopresub));
            else
                EMSG (_ (e_noprevre));
            rc_did_emsg = TRUE;
            return FAIL;
        }
        pat = spats[i].pat;
        magic = spats[i].magic;
        no_smartcase = spats[i].no_scs;
    }
    if (mr_pattern_alloced) {
        vim_free (mr_pattern);
        mr_pattern_alloced = FALSE;
    }
    if (curwin->w_p_rl && *curwin->w_p_rlc == 's') {
        char_u *rev_pattern;
        rev_pattern = reverse_text (pat);
        if (rev_pattern == NULL)
            mr_pattern = pat;
        else {
            mr_pattern = rev_pattern;
            mr_pattern_alloced = TRUE;
        }
    }
    else
        mr_pattern = pat;
    if (!(options & SEARCH_KEEP) && !cmdmod.keeppatterns) {
        if (pat_save == RE_SEARCH || pat_save == RE_BOTH)
            save_re_pat (RE_SEARCH, pat, magic);
        if (pat_save == RE_SUBST || pat_save == RE_BOTH)
            save_re_pat (RE_SUBST, pat, magic);
    }
    regmatch->rmm_ic = ignorecase (pat);
    regmatch->rmm_maxcol = 0;
    regmatch->regprog = vim_regcomp (pat, magic ? RE_MAGIC : 0);
    if (regmatch->regprog == NULL)
        return FAIL;
    return OK;
}

char_u *reverse_text (char_u *s) {
    unsigned  len;
    unsigned  s_i, rev_i;
    char_u *rev;
    len = (unsigned ) STRLEN (s);
    rev = alloc (len +1);
    if (rev != NULL) {
        rev_i = len;
        for (s_i = 0; s_i < len; ++s_i) {
            rev[--rev_i] = s[s_i];
        }
        rev[len] = NUL;
    }
    return rev;
}

void save_re_pat (int idx, char_u *pat, int magic) {
    if (spats[idx].pat != pat) {
        if (RE_SEARCH == idx)
            gui_macvim_add_to_find_pboard (pat);
        vim_free (spats [idx].pat);
        spats[idx].pat = vim_strsave (pat);
        spats[idx].magic = magic;
        spats[idx].no_scs = no_smartcase;
        last_idx = idx;
        if (p_hls)
            redraw_all_later (SOME_VALID);
        SET_NO_HLSEARCH (FALSE);
    }
}

int ignorecase (char_u *pat) {
    return ignorecase_opt (pat, p_ic, p_scs);
}

int ignorecase_opt (char_u *pat, int ic_in, int scs) {
    int ic = ic_in;
    if (ic && !no_smartcase && scs && !(ctrl_x_mode_not_default () && curbuf->b_p_inf))
        ic = !pat_has_uppercase (pat);
    no_smartcase = FALSE;
    return ic;
}

int pat_has_uppercase (char_u *pat) {
    char_u *p = pat;
    while (*p != NUL) {
        if (*p == '\\') {
            if (p[1] == '_' && p[2] != NUL)
                p += 3;
            else if (p[1] == '%' && p[2] != NUL)
                p += 3;
            else if (p[1] != NUL)
                p += 2;
            else
                p += 1;
        }
        else if (MB_ISUPPER (*p))
            return TRUE;
        else
            ++p;
    }
    return FALSE;
}

pos_T *findmatchlimit (oparg_T *oap, int initc, int flags, int maxtravel) {
    static pos_T pos;
    int findc = 0;
    int c;
    int count = 0;
    int backwards = FALSE;
    int raw_string = FALSE;
    int inquote = FALSE;
    char_u *linep;
    char_u *ptr;
    int do_quotes;
    int at_start;
    int hash_dir = 0;
    int comment_dir = 0;
    pos_T match_pos;
    int start_in_quotes;
    int traveled = 0;
    int ignore_cend = FALSE;
    int cpo_match;
    int cpo_bsl;
    int match_escaped = 0;
    int dir;
    int comment_col = MAXCOL;
    int lispcomm = FALSE;
    int lisp = curbuf->b_p_lisp;
    pos = curwin->w_cursor;
    pos.coladd = 0;
    linep = ml_get (pos.lnum);
    cpo_match = (vim_strchr (p_cpo, CPO_MATCH) != NULL);
    cpo_bsl = (vim_strchr (p_cpo, CPO_MATCHBSL) != NULL);
    if (flags & FM_BACKWARD)
        dir = BACKWARD;
    else if (flags & FM_FORWARD)
        dir = FORWARD;
    else
        dir = 0;
    if (initc == '/' || initc == '*' || initc == 'R') {
        comment_dir = dir;
        if (initc == '/')
            ignore_cend = TRUE;
        backwards = (dir == FORWARD) ? FALSE : TRUE;
        raw_string = (initc == 'R');
        initc = NUL;
    }
    else if (initc != '#' && initc != NUL) {
        find_mps_values (& initc, & findc, & backwards, TRUE);
        if (findc == NUL)
            return NULL;
    }
    else {
        if (initc == '#') {
            hash_dir = dir;
        }
        else {
            if (!cpo_match) {
                ptr = skipwhite (linep);
                if (*ptr == '#' && pos.col <= (colnr_T) (ptr - linep)) {
                    ptr = skipwhite (ptr +1);
                    if (STRNCMP (ptr, "if", 2) == 0 || STRNCMP (ptr, "endif", 5) == 0 || STRNCMP (ptr, "el", 2) == 0)
                        hash_dir = 1;
                }
                else if (linep[pos.col] == '/') {
                    if (linep[pos.col + 1] == '*') {
                        comment_dir = FORWARD;
                        backwards = FALSE;
                        pos.col++;
                    }
                    else if (pos.col > 0 && linep[pos.col - 1] == '*') {
                        comment_dir = BACKWARD;
                        backwards = TRUE;
                        pos.col--;
                    }
                }
                else if (linep[pos.col] == '*') {
                    if (linep[pos.col + 1] == '/') {
                        comment_dir = BACKWARD;
                        backwards = TRUE;
                    }
                    else if (pos.col > 0 && linep[pos.col - 1] == '/') {
                        comment_dir = FORWARD;
                        backwards = FALSE;
                    }
                }
            }
            if (!hash_dir && !comment_dir) {
                if (linep[pos.col] == NUL && pos.col)
                    --pos.col;
                for (;;) {
                    initc = PTR2CHAR (linep +pos.col);
                    if (initc == NUL)
                        break;
                    find_mps_values (& initc, & findc, & backwards, FALSE);
                    if (findc)
                        break;
                    pos.col += MB_PTR2LEN (linep +pos.col);
                }
                if (!findc) {
                    if (!cpo_match && *skipwhite (linep) == '#')
                        hash_dir = 1;
                    else
                        return NULL;
                }
                else if (!cpo_bsl) {
                    int col, bslcnt = 0;
                    for (col = pos.col; check_prevcol (linep, col, '\\', &col);)
                        bslcnt++;
                    match_escaped = (bslcnt & 1);
                }
            }
        }
        if (hash_dir) {
            if (oap != NULL)
                oap->motion_type = MLINE;
            if (initc != '#') {
                ptr = skipwhite (skipwhite (linep) +1);
                if (STRNCMP (ptr, "if", 2) == 0 || STRNCMP (ptr, "el", 2) == 0)
                    hash_dir = 1;
                else if (STRNCMP (ptr, "endif", 5) == 0)
                    hash_dir = -1;
                else
                    return NULL;
            }
            pos.col = 0;
            while (!got_int) {
                if (hash_dir > 0) {
                    if (pos.lnum == curbuf->b_ml.ml_line_count)
                        break;
                }
                else if (pos.lnum == 1)
                    break;
                pos.lnum += hash_dir;
                linep = ml_get (pos.lnum);
                line_breakcheck ();
                ptr = skipwhite (linep);
                if (*ptr != '#')
                    continue;
                pos.col = (colnr_T) (ptr - linep);
                ptr = skipwhite (ptr +1);
                if (hash_dir > 0) {
                    if (STRNCMP (ptr, "if", 2) == 0)
                        count++;
                    else if (STRNCMP (ptr, "el", 2) == 0) {
                        if (count == 0)
                            return &pos;
                    }
                    else if (STRNCMP (ptr, "endif", 5) == 0) {
                        if (count == 0)
                            return &pos;
                        count--;
                    }
                }
                else {
                    if (STRNCMP (ptr, "if", 2) == 0) {
                        if (count == 0)
                            return &pos;
                        count--;
                    }
                    else if (initc == '#' && STRNCMP (ptr, "el", 2) == 0) {
                        if (count == 0)
                            return &pos;
                    }
                    else if (STRNCMP (ptr, "endif", 5) == 0)
                        count++;
                }
            }
            return NULL;
        }
    }
    if (curwin->w_p_rl && vim_strchr ((char_u *) "()[]{}<>", initc) != NULL)
        backwards = !backwards;
    do_quotes = -1;
    start_in_quotes = MAYBE;
    CLEAR_POS (& match_pos);
    if ((backwards && comment_dir) || lisp)
        comment_col = check_linecomment (linep);
    if (lisp && comment_col != MAXCOL && pos.col > (colnr_T) comment_col)
        lispcomm = TRUE;
    while (!got_int) {
        if (backwards) {
            if (lispcomm && pos.col < (colnr_T) comment_col)
                break;
            if (pos.col == 0) {
                if (pos.lnum == 1)
                    break;
                --pos.lnum;
                if (maxtravel > 0 && ++traveled > maxtravel)
                    break;
                linep = ml_get (pos.lnum);
                pos.col = (colnr_T) STRLEN (linep);
                do_quotes = -1;
                line_breakcheck ();
                if (comment_dir || lisp)
                    comment_col = check_linecomment (linep);
                if (lisp && comment_col != MAXCOL)
                    pos.col = comment_col;
            }
            else {
                --pos.col;
            }
        }
        else {
            if (linep[pos.col] == NUL || (lisp && comment_col != MAXCOL && pos.col == (colnr_T) comment_col)) {
                if (pos.lnum == curbuf->b_ml.ml_line_count || lispcomm)
                    break;
                ++pos.lnum;
                if (maxtravel && traveled++ > maxtravel)
                    break;
                linep = ml_get (pos.lnum);
                pos.col = 0;
                do_quotes = -1;
                line_breakcheck ();
                if (lisp)
                    comment_col = check_linecomment (linep);
            }
            else {
                ++pos.col;
            }
        }
        if (pos.col == 0 && (flags & FM_BLOCKSTOP) && (linep[0] == '{' || linep[0] == '}')) {
            if (linep[0] == findc && count == 0)
                return &pos;
            break;
        }
        if (comment_dir) {
            if (comment_dir == FORWARD) {
                if (linep[pos.col] == '*' && linep[pos.col + 1] == '/') {
                    pos.col++;
                    return &pos;
                }
            }
            else {
                if (pos.col == 0)
                    continue;
                else if (raw_string) {
                    if (linep[pos.col - 1] == 'R' && linep[pos.col] == '"' && vim_strchr (linep +pos.col + 1, '(') != NULL) {
                        if (!find_rawstring_end (linep, &pos, count > 0 ? &match_pos : &curwin->w_cursor)) {
                            count++;
                            match_pos = pos;
                            match_pos.col--;
                        }
                        linep = ml_get (pos.lnum);
                    }
                }
                else if (linep[pos.col - 1] == '/' && linep[pos.col] == '*' && (pos.col == 1 || linep[pos.col - 2] != '*') && (int) pos.col < comment_col) {
                    count++;
                    match_pos = pos;
                    match_pos.col--;
                }
                else if (linep[pos.col - 1] == '*' && linep[pos.col] == '/') {
                    if (count > 0)
                        pos = match_pos;
                    else if (pos.col > 1 && linep[pos.col - 2] == '/' && (int) pos.col <= comment_col)
                        pos.col -= 2;
                    else if (ignore_cend)
                        continue;
                    else
                        return NULL;
                    return &pos;
                }
            }
            continue;
        }
        if (cpo_match)
            do_quotes = 0;
        else if (do_quotes == -1) {
            at_start = do_quotes;
            for (ptr = linep; *ptr; ++ptr) {
                if (ptr == linep + pos.col + backwards)
                    at_start = (do_quotes & 1);
                if (*ptr == '"' && (ptr == linep || ptr[-1] != '\'' || ptr[1] != '\''))
                    ++do_quotes;
                if (*ptr == '\\' && ptr[1] != NUL)
                    ++ptr;
            }
            do_quotes &= 1;
            if (!do_quotes) {
                inquote = FALSE;
                if (ptr[-1] == '\\') {
                    do_quotes = 1;
                    if (start_in_quotes == MAYBE) {
                        inquote = TRUE;
                        start_in_quotes = TRUE;
                    }
                    else if (backwards)
                        inquote = TRUE;
                }
                if (pos.lnum > 1) {
                    ptr = ml_get (pos.lnum - 1);
                    if (*ptr && *(ptr + STRLEN (ptr) - 1) == '\\') {
                        do_quotes = 1;
                        if (start_in_quotes == MAYBE) {
                            inquote = at_start;
                            if (inquote)
                                start_in_quotes = TRUE;
                        }
                        else if (!backwards)
                            inquote = TRUE;
                    }
                    linep = ml_get (pos.lnum);
                }
            }
        }
        if (start_in_quotes == MAYBE)
            start_in_quotes = FALSE;
        c = PTR2CHAR (linep +pos.col);
        switch (c) {
        case NUL :
            if (pos.col == 0 || linep[pos.col - 1] != '\\') {
                inquote = FALSE;
                start_in_quotes = FALSE;
            }
            break;
        case '"' :
            if (do_quotes) {
                int col;
                for (col = pos.col - 1; col >= 0; --col)
                    if (linep[col] != '\\')
                        break;
                if ((((int) pos.col - 1 - col) & 1) == 0) {
                    inquote = !inquote;
                    start_in_quotes = FALSE;
                }
            }
            break;
        case '\'' :
            if (!cpo_match && initc != '\'' && findc != '\'') {
                if (backwards) {
                    if (pos.col > 1) {
                        if (linep[pos.col - 2] == '\'') {
                            pos.col -= 2;
                            break;
                        }
                        else if (linep[pos.col - 2] == '\\' && pos.col > 2 && linep[pos.col - 3] == '\'') {
                            pos.col -= 3;
                            break;
                        }
                    }
                }
                else if (linep[pos.col + 1]) {
                    if (linep[pos.col + 1] == '\\' && linep[pos.col + 2] && linep[pos.col + 3] == '\'') {
                        pos.col += 3;
                        break;
                    }
                    else if (linep[pos.col + 2] == '\'') {
                        pos.col += 2;
                        break;
                    }
                }
            }
        default :
            if (curbuf->b_p_lisp && vim_strchr ((char_u *) "(){}[]", c) != NULL && pos.col > 1 && check_prevcol (linep, pos.col, '\\', NULL) && check_prevcol (linep, pos.col - 1, '#', NULL))
                break;
            if ((!inquote || start_in_quotes == TRUE) && (c == initc || c == findc)) {
                int col, bslcnt = 0;
                if (!cpo_bsl) {
                    for (col = pos.col; check_prevcol (linep, col, '\\', &col);)
                        bslcnt++;
                }
                if (cpo_bsl || (bslcnt & 1) == match_escaped) {
                    if (c == initc)
                        count++;
                    else {
                        if (count == 0)
                            return &pos;
                        count--;
                    }
                }
            }
        }
    }
    if (comment_dir == BACKWARD && count > 0) {
        pos = match_pos;
        return &pos;
    }
    return (pos_T *) NULL;
}

static int check_prevcol (char_u *linep, int col, int ch, int *prevcol) {
    --col;
    if (prevcol)
        *prevcol = col;
    return (col >= 0 && linep[col] == ch) ? TRUE : FALSE;
}

static int check_linecomment (char_u *line) {
    char_u *p;
    p = line;
    if (curbuf->b_p_lisp) {
        if (vim_strchr (p, ';') != NULL) {
            int in_str = FALSE;
            p = line;
            while ((p = vim_strpbrk (p, (char_u *) "\";")) != NULL) {
                if (*p == '"') {
                    if (in_str) {
                        if (*(p - 1) != '\\')
                            in_str = FALSE;
                    }
                    else if (p == line || ((p - line) >= 2 && *(p - 1) != '\\' && *(p - 2) != '#'))
                        in_str = TRUE;
                }
                else if (!in_str && ((p - line) < 2 || (*(p - 1) != '\\' && *(p - 2) != '#')))
                    break;
                ++p;
            }
        }
        else
            p = NULL;
    }
    else
        while ((p = vim_strchr (p, '/')) != NULL) {
            if (p[1] == '/' && (p == line || p[-1] != '*' || p[2] != '*'))
                break;
            ++p;
        }
    if (p == NULL)
        return MAXCOL;
    return (int) (p - line);
}

static int find_rawstring_end (char_u *linep, pos_T *startpos, pos_T *endpos) {
    char_u *p;
    char_u *delim_copy;
    size_t delim_len;
    linenr_T lnum;
    int found = FALSE;
    for (p = linep + startpos->col + 1; *p && *p != '('; ++p)
        ;
    delim_len = (p - linep) - startpos->col - 1;
    delim_copy = vim_strnsave (linep +startpos->col + 1, (int) delim_len);
    if (delim_copy == NULL)
        return FALSE;
    for (lnum = startpos->lnum; lnum <= endpos->lnum; ++lnum) {
        char_u *line = ml_get (lnum);
        for (p = line + (lnum == startpos->lnum ? startpos->col + 1 : 0); *p; ++p) {
            if (lnum == endpos->lnum && (colnr_T) (p - line) >= endpos->col)
                break;
            if (*p == ')' && p[delim_len + 1] == '"' && STRNCMP (delim_copy, p +1, delim_len) == 0) {
                found = TRUE;
                break;
            }
        }
        if (found)
            break;
    }
    vim_free (delim_copy);
    return found;
}

pos_T *findmatch (oparg_T *oap, int initc) {
    return findmatchlimit (oap, initc, 0, 0);
}

void showmatch (int c) {
    pos_T *lpos, save_cursor;
    pos_T mpos;
    colnr_T vcol;
    long  save_so;
    long  save_siso;
    colnr_T save_dollar_vcol;
    char_u *p;
    for (p = curbuf->b_p_mps; *p != NUL; ++p) {
        if (PTR2CHAR (p) == c && (curwin->w_p_rl ^ p_ri))
            break;
        p += MB_PTR2LEN (p) + 1;
        if (PTR2CHAR (p) == c && !(curwin->w_p_rl ^ p_ri))
            break;
        p += MB_PTR2LEN (p);
        if (*p == NUL)
            return;
    }
    if ((lpos = findmatch (NULL, NUL)) == NULL)
        vim_beep (BO_MATCH);
    else if (lpos->lnum >= curwin->w_topline && lpos->lnum < curwin->w_botline) {
        if (!curwin->w_p_wrap)
            getvcol (curwin, lpos, NULL, &vcol, NULL);
        if (curwin->w_p_wrap || (vcol >= curwin->w_leftcol && vcol < curwin->w_leftcol + curwin->w_width)) {
            mpos = *lpos;
            save_cursor = curwin->w_cursor;
            save_so = p_so;
            save_siso = p_siso;
            if (dollar_vcol >= 0 && dollar_vcol == curwin->w_virtcol)
                dollar_vcol = -1;
            ++curwin->w_virtcol;
            update_screen (VALID);
            save_dollar_vcol = dollar_vcol;
            curwin->w_cursor = mpos;
            p_so = 0;
            p_siso = 0;
            showruler (FALSE);
            setcursor ();
            cursor_on ();
            out_flush_cursor (TRUE, FALSE);
            dollar_vcol = save_dollar_vcol;
            if (vim_strchr (p_cpo, CPO_SHOWMATCH) != NULL)
                ui_delay (p_mat *100L, TRUE);
            else if (!char_avail ())
                ui_delay (p_mat *100L, FALSE);
            curwin->w_cursor = save_cursor;
            p_so = save_so;
            p_siso = save_siso;
        }
    }
}

int linewhite (linenr_T lnum) {
    char_u *p;
    p = skipwhite (ml_get (lnum));
    return (*p == NUL);
}

void find_pattern_in_path (char_u *ptr, int dir, int len, int whole, int skip_comments, int type, long  count, int action, linenr_T start_lnum, linenr_T end_lnum) {
    SearchedFile *files;
    SearchedFile *bigger;
    int max_path_depth = 50;
    long  match_count = 1;
    char_u *pat;
    char_u *new_fname;
    char_u *curr_fname = curbuf->b_fname;
    char_u *prev_fname = NULL;
    linenr_T lnum;
    int depth;
    int depth_displayed;
    int old_files;
    int already_searched;
    char_u *file_line;
    char_u *line;
    char_u *p;
    char_u save_char;
    int define_matched;
    regmatch_T regmatch;
    regmatch_T incl_regmatch;
    regmatch_T def_regmatch;
    int matched = FALSE;
    int did_show = FALSE;
    int found = FALSE;
    int i;
    char_u *already = NULL;
    char_u *startp = NULL;
    char_u *inc_opt = NULL;
    win_T *curwin_save = NULL;
    regmatch.regprog = NULL;
    incl_regmatch.regprog = NULL;
    def_regmatch.regprog = NULL;
    file_line = alloc (LSIZE);
    if (file_line == NULL)
        return;
    if (type != CHECK_PATH && type != FIND_DEFINE && !(compl_cont_status & CONT_SOL)) {
        pat = alloc (len +5);
        if (pat == NULL)
            goto fpip_end;
        sprintf ((char *) pat, whole ? "\\<%.*s\\>" : "%.*s", len, ptr);
        regmatch.rm_ic = ignorecase (pat);
        regmatch.regprog = vim_regcomp (pat, p_magic ? RE_MAGIC : 0);
        vim_free (pat);
        if (regmatch.regprog == NULL)
            goto fpip_end;
    }
    inc_opt = (*curbuf->b_p_inc == NUL) ? p_inc : curbuf->b_p_inc;
    if (*inc_opt != NUL) {
        incl_regmatch.regprog = vim_regcomp (inc_opt, p_magic ? RE_MAGIC : 0);
        if (incl_regmatch.regprog == NULL)
            goto fpip_end;
        incl_regmatch.rm_ic = FALSE;
    }
    if (type == FIND_DEFINE && (*curbuf->b_p_def != NUL || *p_def != NUL)) {
        def_regmatch.regprog = vim_regcomp (*curbuf->b_p_def == NUL ? p_def : curbuf->b_p_def, p_magic ? RE_MAGIC : 0);
        if (def_regmatch.regprog == NULL)
            goto fpip_end;
        def_regmatch.rm_ic = FALSE;
    }
    files = (SearchedFile *) lalloc_clear ((long_u) (max_path_depth * sizeof (SearchedFile)), TRUE);
    if (files == NULL)
        goto fpip_end;
    old_files = max_path_depth;
    depth = depth_displayed = -1;
    lnum = start_lnum;
    if (end_lnum > curbuf->b_ml.ml_line_count)
        end_lnum = curbuf->b_ml.ml_line_count;
    if (lnum > end_lnum)
        lnum = end_lnum;
    line = ml_get (lnum);
    for (;;) {
        if (incl_regmatch.regprog != NULL && vim_regexec (&incl_regmatch, line, (colnr_T) 0)) {
            char_u *p_fname = (curr_fname == curbuf->b_fname) ? curbuf->b_ffname : curr_fname;
            if (inc_opt != NULL && strstr ((char *) inc_opt, "\\zs") != NULL)
                new_fname = find_file_name_in_path (incl_regmatch.startp[0], (int) (incl_regmatch.endp[0] - incl_regmatch.startp[0]), FNAME_EXP | FNAME_INCL | FNAME_REL, 1L, p_fname);
            else
                new_fname = file_name_in_line (incl_regmatch.endp[0], 0, FNAME_EXP | FNAME_INCL | FNAME_REL, 1L, p_fname, NULL);
            already_searched = FALSE;
            if (new_fname != NULL) {
                for (i = 0;; i++) {
                    if (i == depth + 1)
                        i = old_files;
                    if (i == max_path_depth)
                        break;
                    if (fullpathcmp (new_fname, files[i].name, TRUE) & FPC_SAME) {
                        if (type != CHECK_PATH && action == ACTION_SHOW_ALL && files[i].matched) {
                            msg_putchar ('\n');
                            if (!got_int) {
                                msg_home_replace_hl (new_fname);
                                MSG_PUTS (_ (" (includes previously listed match)"));
                                prev_fname = NULL;
                            }
                        }
                        VIM_CLEAR (new_fname);
                        already_searched = TRUE;
                        break;
                    }
                }
            }
            if (type == CHECK_PATH && (action == ACTION_SHOW_ALL || (new_fname == NULL && !already_searched))) {
                if (did_show)
                    msg_putchar ('\n');
                else {
                    gotocmdline (TRUE);
                    MSG_PUTS_TITLE (_ ("--- Included files "));
                    if (action != ACTION_SHOW_ALL)
                        MSG_PUTS_TITLE (_ ("not found "));
                    MSG_PUTS_TITLE (_ ("in path ---\n"));
                }
                did_show = TRUE;
                while (depth_displayed < depth && !got_int) {
                    ++depth_displayed;
                    for (i = 0; i < depth_displayed; i++)
                        MSG_PUTS ("  ");
                    msg_home_replace (files [depth_displayed].name);
                    MSG_PUTS (" -->\n");
                }
                if (!got_int) {
                    for (i = 0; i <= depth_displayed; i++)
                        MSG_PUTS ("  ");
                    if (new_fname != NULL) {
                        msg_outtrans_attr (new_fname, HL_ATTR (HLF_D));
                    }
                    else {
                        if (inc_opt != NULL && strstr ((char *) inc_opt, "\\zs") != NULL) {
                            p = incl_regmatch.startp[0];
                            i = (int) (incl_regmatch.endp[0] - incl_regmatch.startp[0]);
                        }
                        else {
                            for (p = incl_regmatch.endp[0]; *p && !vim_isfilec (*p); p++)
                                ;
                            for (i = 0; vim_isfilec (p[i]); i++)
                                ;
                        }
                        if (i == 0) {
                            p = incl_regmatch.endp[0];
                            i = (int) STRLEN (p);
                        }
                        else if (p > line) {
                            if (p[-1] == '"' || p[-1] == '<') {
                                --p;
                                ++i;
                            }
                            if (p[i] == '"' || p[i] == '>')
                                ++i;
                        }
                        save_char = p[i];
                        p[i] = NUL;
                        msg_outtrans_attr (p, HL_ATTR (HLF_D));
                        p[i] = save_char;
                    }
                    if (new_fname == NULL && action == ACTION_SHOW_ALL) {
                        if (already_searched)
                            MSG_PUTS (_ ("  (Already listed)"));
                        else
                            MSG_PUTS (_ ("  NOT FOUND"));
                    }
                }
                out_flush ();
            }
            if (new_fname != NULL) {
                if (depth + 1 == old_files) {
                    bigger = (SearchedFile *) lalloc ((long_u) (max_path_depth * 2 * sizeof (SearchedFile)), TRUE);
                    if (bigger != NULL) {
                        for (i = 0; i <= depth; i++)
                            bigger[i] = files[i];
                        for (i = depth + 1; i < old_files + max_path_depth; i++) {
                            bigger[i].fp = NULL;
                            bigger[i].name = NULL;
                            bigger[i].lnum = 0;
                            bigger[i].matched = FALSE;
                        }
                        for (i = old_files; i < max_path_depth; i++)
                            bigger[i + max_path_depth] = files[i];
                        old_files += max_path_depth;
                        max_path_depth *= 2;
                        vim_free (files);
                        files = bigger;
                    }
                }
                if ((files[depth + 1].fp = mch_fopen ((char *) new_fname, "r")) == NULL)
                    vim_free (new_fname);
                else {
                    if (++depth == old_files) {
                        vim_free (files [old_files].name);
                        ++old_files;
                    }
                    files[depth].name = curr_fname = new_fname;
                    files[depth].lnum = 0;
                    files[depth].matched = FALSE;
                    if (action == ACTION_EXPAND) {
                        msg_hist_off = TRUE;
                        vim_snprintf ((char *) IObuff, IOSIZE, _ ("Scanning included file: %s"), (char *) new_fname);
                        msg_trunc_attr (IObuff, TRUE, HL_ATTR (HLF_R));
                    }
                    else if (p_verbose >= 5) {
                        verbose_enter ();
                        smsg ((char_u *) _ ("Searching included file %s"), (char *) new_fname);
                        verbose_leave ();
                    }
                }
            }
        }
        else {
            p = line;
        search_line :
            define_matched = FALSE;
            if (def_regmatch.regprog != NULL && vim_regexec (&def_regmatch, line, (colnr_T) 0)) {
                p = def_regmatch.endp[0];
                while (*p && !vim_iswordc (*p))
                    p++;
                define_matched = TRUE;
            }
            if (def_regmatch.regprog == NULL || define_matched) {
                if (define_matched || (compl_cont_status & CONT_SOL)) {
                    startp = skipwhite (p);
                    if (p_ic)
                        matched = !MB_STRNICMP (startp, ptr, len);
                    else
                        matched = !STRNCMP (startp, ptr, len);
                    if (matched && define_matched && whole && vim_iswordc (startp[len]))
                        matched = FALSE;
                }
                else if (regmatch.regprog != NULL && vim_regexec (&regmatch, line, (colnr_T) (p - line))) {
                    matched = TRUE;
                    startp = regmatch.startp[0];
                    if (!define_matched && skip_comments) {
                        if ((*line != '#' || STRNCMP (skipwhite (line + 1), "define", 6) != 0) && get_leader_len (line, NULL, FALSE, TRUE))
                            matched = FALSE;
                        p = skipwhite (line);
                        if (matched || (p[0] == '/' && p[1] == '*') || p[0] == '*')
                            for (p = line; *p && p < startp; ++p) {
                                if (matched && p[0] == '/' && (p[1] == '*' || p[1] == '/')) {
                                    matched = FALSE;
                                    if (p[1] == '/')
                                        break;
                                    ++p;
                                }
                                else if (!matched && p[0] == '*' && p[1] == '/') {
                                    matched = TRUE;
                                    ++p;
                                }
                            }
                    }
                }
            }
        }
        if (matched) {
            if (action == ACTION_EXPAND) {
                int reuse = 0;
                int add_r;
                char_u *aux;
                if (depth == -1 && lnum == curwin->w_cursor.lnum)
                    break;
                found = TRUE;
                aux = p = startp;
                if (compl_cont_status & CONT_ADDING) {
                    p += compl_length;
                    if (vim_iswordp (p))
                        goto exit_matched;
                    p = find_word_start (p);
                }
                p = find_word_end (p);
                i = (int) (p - aux);
                if ((compl_cont_status & CONT_ADDING) && i == compl_length) {
                    STRNCPY (IObuff, aux, i);
                    if (depth < 0) {
                        if (lnum >= end_lnum)
                            goto exit_matched;
                        line = ml_get (++lnum);
                    }
                    else if (vim_fgets (line = file_line, LSIZE, files[depth].fp))
                        goto exit_matched;
                    already = aux = p = skipwhite (line);
                    p = find_word_start (p);
                    p = find_word_end (p);
                    if (p > aux) {
                        if (*aux != ')' && IObuff[i - 1] != TAB) {
                            if (IObuff[i - 1] != ' ')
                                IObuff[i++] = ' ';
                            if (p_js && (IObuff[i - 2] == '.' || (vim_strchr (p_cpo, CPO_JOINSP) == NULL && (IObuff[i - 2] == '?' || IObuff[i - 2] == '!'))))
                                IObuff[i++] = ' ';
                        }
                        if (p - aux >= IOSIZE - i)
                            p = aux + IOSIZE - i - 1;
                        STRNCPY (IObuff + i, aux, p - aux);
                        i += (int) (p - aux);
                        reuse |= CONT_S_IPOS;
                    }
                    IObuff[i] = NUL;
                    aux = IObuff;
                    if (i == compl_length)
                        goto exit_matched;
                }
                add_r = ins_compl_add_infercase (aux, i, p_ic, curr_fname == curbuf->b_fname ? NULL : curr_fname, dir, reuse);
                if (add_r == OK)
                    dir = FORWARD;
                else if (add_r == FAIL)
                    break;
            }
            else if (action == ACTION_SHOW_ALL) {
                found = TRUE;
                if (!did_show)
                    gotocmdline (TRUE);
                if (curr_fname != prev_fname) {
                    if (did_show)
                        msg_putchar ('\n');
                    if (!got_int)
                        msg_home_replace_hl (curr_fname);
                    prev_fname = curr_fname;
                }
                did_show = TRUE;
                if (!got_int)
                    show_pat_in_path (line, type, TRUE, action, (depth == -1) ? NULL : files[depth].fp, (depth == -1) ? &lnum : &files[depth].lnum, match_count++);
                for (i = 0; i <= depth; ++i)
                    files[i].matched = TRUE;
            }
            else if (--count <= 0) {
                found = TRUE;
                if (depth == -1 && lnum == curwin->w_cursor.lnum && g_do_tagpreview == 0)
                    EMSG (_ ("E387: Match is on current line"));
                else if (action == ACTION_SHOW) {
                    show_pat_in_path (line, type, did_show, action, (depth == - 1) ? NULL : files [depth].fp, (depth == - 1) ? & lnum : & files [depth].lnum, 1L);
                    did_show = TRUE;
                }
                else {
                    need_mouse_correct = TRUE;
                    if (g_do_tagpreview != 0) {
                        curwin_save = curwin;
                        prepare_tagpreview (TRUE);
                    }
                    if (action == ACTION_SPLIT) {
                        if (win_split (0, 0) == FAIL)
                            break;
                        RESET_BINDING (curwin);
                    }
                    if (depth == -1) {
                        if (g_do_tagpreview != 0) {
                            if (!GETFILE_SUCCESS (getfile (curwin_save->w_buffer->b_fnum, NULL, NULL, TRUE, lnum, FALSE)))
                                break;
                        }
                        else
                            setpcmark ();
                        curwin->w_cursor.lnum = lnum;
                        check_cursor ();
                    }
                    else {
                        if (!GETFILE_SUCCESS (getfile (0, files[depth].name, NULL, TRUE, files[depth].lnum, FALSE)))
                            break;
                        curwin->w_cursor.lnum = files[depth].lnum;
                    }
                }
                if (action != ACTION_SHOW) {
                    curwin->w_cursor.col = (colnr_T) (startp - line);
                    curwin->w_set_curswant = TRUE;
                }
                if (g_do_tagpreview != 0 && curwin != curwin_save && win_valid (curwin_save)) {
                    validate_cursor ();
                    redraw_later (VALID);
                    win_enter (curwin_save, TRUE);
                }
                break;
            }
        exit_matched :
            matched = FALSE;
            if (def_regmatch.regprog == NULL && action == ACTION_EXPAND && !(compl_cont_status & CONT_SOL) && *startp != NUL && *(p = startp + MB_PTR2LEN (startp)) != NUL)
                goto search_line;
        }
        line_breakcheck ();
        if (gui.in_use)
            gui_macvim_flush ();
        if (action == ACTION_EXPAND)
            ins_compl_check_keys (30, FALSE);
        if (got_int || compl_interrupted)
            break;
        while (depth >= 0 && !already && vim_fgets (line = file_line, LSIZE, files[depth].fp)) {
            fclose (files [depth].fp);
            --old_files;
            files[old_files].name = files[depth].name;
            files[old_files].matched = files[depth].matched;
            --depth;
            curr_fname = (depth == -1) ? curbuf->b_fname : files[depth].name;
            if (depth < depth_displayed)
                depth_displayed = depth;
        }
        if (depth >= 0) {
            files[depth].lnum++;
            i = (int) STRLEN (line);
            if (i > 0 && line[i - 1] == '\n')
                line[--i] = NUL;
            if (i > 0 && line[i - 1] == '\r')
                line[--i] = NUL;
        }
        else if (!already) {
            if (++lnum > end_lnum)
                break;
            line = ml_get (lnum);
        }
        already = NULL;
    }
    for (i = 0; i <= depth; i++) {
        fclose (files [i].fp);
        vim_free (files [i].name);
    }
    for (i = old_files; i < max_path_depth; i++)
        vim_free (files[i].name);
    vim_free (files);
    if (type == CHECK_PATH) {
        if (!did_show) {
            if (action != ACTION_SHOW_ALL)
                MSG (_ ("All included files were found"));
            else
                MSG (_ ("No included files"));
        }
    }
    else if (!found && action != ACTION_EXPAND) {
        if (got_int || compl_interrupted)
            EMSG (_ (e_interr));
        else if (type == FIND_DEFINE)
            EMSG (_ ("E388: Couldn't find definition"));
        else
            EMSG (_ ("E389: Couldn't find pattern"));
    }
    if (action == ACTION_SHOW || action == ACTION_SHOW_ALL)
        msg_end ();
fpip_end :
    vim_free (file_line);
    vim_regfree (regmatch.regprog);
    vim_regfree (incl_regmatch.regprog);
    vim_regfree (def_regmatch.regprog);
}

static void show_pat_in_path (char_u *line, int type, int did_show, int action, FILE *fp, linenr_T *lnum, long  count) {
    char_u *p;
    if (did_show)
        msg_putchar ('\n');
    else if (!msg_silent)
        gotocmdline (TRUE);
    if (got_int)
        return;
    for (;;) {
        p = line + STRLEN (line) - 1;
        if (fp != NULL) {
            if (p >= line && *p == '\n')
                --p;
            if (p >= line && *p == '\r')
                --p;
            *(p + 1) = NUL;
        }
        if (action == ACTION_SHOW_ALL) {
            sprintf ((char *) IObuff, "%3ld: ", count);
            msg_puts (IObuff);
            sprintf ((char *) IObuff, "%4ld", * lnum);
            msg_puts_attr (IObuff, HL_ATTR (HLF_N));
            MSG_PUTS (" ");
        }
        msg_prt_line (line, FALSE);
        out_flush ();
        if (got_int || type != FIND_DEFINE || p < line || *p != '\\')
            break;
        if (fp != NULL) {
            if (vim_fgets (line, LSIZE, fp))
                break;
            ++*lnum;
        }
        else {
            if (++*lnum > curbuf->b_ml.ml_line_count)
                break;
            line = ml_get (*lnum);
        }
        msg_putchar ('\n');
    }
}

int search_for_exact_line (buf_T *buf, pos_T *pos, int dir, char_u *pat) {
    linenr_T start = 0;
    char_u *ptr;
    char_u *p;
    if (buf->b_ml.ml_line_count == 0)
        return FAIL;
    for (;;) {
        pos->lnum += dir;
        if (pos->lnum < 1) {
            if (p_ws) {
                pos->lnum = buf->b_ml.ml_line_count;
                if (!shortmess (SHM_SEARCH))
                    give_warning ((char_u *) _ (top_bot_msg), TRUE);
            }
            else {
                pos->lnum = 1;
                break;
            }
        }
        else if (pos->lnum > buf->b_ml.ml_line_count) {
            if (p_ws) {
                pos->lnum = 1;
                if (!shortmess (SHM_SEARCH))
                    give_warning ((char_u *) _ (bot_top_msg), TRUE);
            }
            else {
                pos->lnum = 1;
                break;
            }
        }
        if (pos->lnum == start)
            break;
        if (start == 0)
            start = pos->lnum;
        ptr = ml_get_buf (buf, pos->lnum, FALSE);
        p = skipwhite (ptr);
        pos->col = (colnr_T) (p - ptr);
        if ((compl_cont_status & CONT_ADDING) && !(compl_cont_status & CONT_SOL)) {
            if ((p_ic ? MB_STRICMP (p, pat) : STRCMP (p, pat)) == 0)
                return OK;
        }
        else if (*p != NUL) {
            if ((p_ic ? MB_STRNICMP (p, pat, compl_length) : STRNCMP (p, pat, compl_length)) == 0)
                return OK;
        }
    }
    return FAIL;
}

int searchit (win_T *win, buf_T *buf, pos_T *pos, int dir, char_u *pat, long  count, int options, int pat_use, linenr_T stop_lnum, proftime_T *tm, int *timed_out) {
    int found;
    linenr_T lnum;
    colnr_T col;
    regmmatch_T regmatch;
    char_u *ptr;
    colnr_T matchcol;
    lpos_T endpos;
    lpos_T matchpos;
    int loop;
    pos_T start_pos;
    int at_first_line;
    int extra_col;
    int start_char_len;
    int match_ok;
    long  nmatched;
    int submatch = 0;
    int first_match = TRUE;
    int save_called_emsg = called_emsg;
    int break_loop = FALSE;
    if (search_regcomp (pat, RE_SEARCH, pat_use, (options & (SEARCH_HIS + SEARCH_KEEP)), &regmatch) == FAIL) {
        if ((options & SEARCH_MSG) && !rc_did_emsg)
            EMSG2 (_ ("E383: Invalid search string: %s"), mr_pattern);
        return FAIL;
    }
    called_emsg = FALSE;
    do {
        if (pos->col == MAXCOL)
            start_char_len = 0;
        else
            start_char_len = 1;
        if (dir == FORWARD) {
            if (options & SEARCH_START)
                extra_col = 0;
            else
                extra_col = start_char_len;
        }
        else {
            if (options & SEARCH_START)
                extra_col = start_char_len;
            else
                extra_col = 0;
        }
        start_pos = *pos;
        found = 0;
        at_first_line = TRUE;
        if (pos->lnum == 0) {
            pos->lnum = 1;
            pos->col = 0;
            at_first_line = FALSE;
        }
        if (dir == BACKWARD && start_pos.col == 0 && (options & SEARCH_START) == 0) {
            lnum = pos->lnum - 1;
            at_first_line = FALSE;
        }
        else
            lnum = pos->lnum;
        for (loop = 0; loop <= 1; ++loop) {
            for (; lnum > 0 && lnum <= buf->b_ml.ml_line_count; lnum += dir, at_first_line = FALSE) {
                if (stop_lnum != 0 && (dir == FORWARD ? lnum > stop_lnum : lnum < stop_lnum))
                    break;
                if (tm != NULL && profile_passed_limit (tm))
                    break;
                col = at_first_line && (options & SEARCH_COL) ? pos->col : (colnr_T) 0;
                nmatched = vim_regexec_multi (&regmatch, win, buf, lnum, col, tm, timed_out);
                if (called_emsg || (timed_out != NULL && *timed_out))
                    break;
                if (nmatched > 0) {
                    matchpos = regmatch.startpos[0];
                    endpos = regmatch.endpos[0];
                    submatch = first_submatch (&regmatch);
                    if (lnum + matchpos.lnum > buf->b_ml.ml_line_count)
                        ptr = (char_u *) "";
                    else
                        ptr = ml_get_buf (buf, lnum +matchpos.lnum, FALSE);
                    if (dir == FORWARD && at_first_line) {
                        match_ok = TRUE;
                        while (matchpos.lnum == 0 && ((options & SEARCH_END) && first_match ? (nmatched == 1 && (int) endpos.col - 1 < (int) start_pos.col + extra_col) : ((int) matchpos.col - (ptr[matchpos.col] == NUL) < (int) start_pos.col + extra_col))) {
                            if (vim_strchr (p_cpo, CPO_SEARCH) != NULL) {
                                if (nmatched > 1) {
                                    match_ok = FALSE;
                                    break;
                                }
                                matchcol = endpos.col;
                                if (matchcol == matchpos.col && ptr[matchcol] != NUL) {
                                    ++matchcol;
                                }
                            }
                            else {
                                matchcol = matchpos.col;
                                if (ptr[matchcol] != NUL) {
                                    ++matchcol;
                                }
                            }
                            if (matchcol == 0 && (options & SEARCH_START))
                                break;
                            if (ptr[matchcol] == NUL || (nmatched = vim_regexec_multi (&regmatch, win, buf, lnum +matchpos.lnum, matchcol, tm, timed_out)) == 0) {
                                match_ok = FALSE;
                                break;
                            }
                            matchpos = regmatch.startpos[0];
                            endpos = regmatch.endpos[0];
                            submatch = first_submatch (&regmatch);
                            ptr = ml_get_buf (buf, lnum +matchpos.lnum, FALSE);
                        }
                        if (!match_ok)
                            continue;
                    }
                    if (dir == BACKWARD) {
                        match_ok = FALSE;
                        for (;;) {
                            if (loop || ((options & SEARCH_END) ? (lnum + regmatch.endpos[0].lnum < start_pos.lnum || (lnum + regmatch.endpos[0].lnum == start_pos.lnum && (int) regmatch.endpos[0].col - 1 < (int) start_pos.col + extra_col)) : (lnum + regmatch.startpos[0].lnum < start_pos.lnum || (lnum + regmatch.startpos[0].lnum == start_pos.lnum && (int) regmatch.startpos[0].col < (int) start_pos.col + extra_col)))) {
                                match_ok = TRUE;
                                matchpos = regmatch.startpos[0];
                                endpos = regmatch.endpos[0];
                                submatch = first_submatch (&regmatch);
                            }
                            else
                                break;
                            if (vim_strchr (p_cpo, CPO_SEARCH) != NULL) {
                                if (nmatched > 1)
                                    break;
                                matchcol = endpos.col;
                                if (matchcol == matchpos.col && ptr[matchcol] != NUL) {
                                    ++matchcol;
                                }
                            }
                            else {
                                if (matchpos.lnum > 0)
                                    break;
                                matchcol = matchpos.col;
                                if (ptr[matchcol] != NUL) {
                                    ++matchcol;
                                }
                            }
                            if (ptr[matchcol] == NUL || (nmatched = vim_regexec_multi (&regmatch, win, buf, lnum +matchpos.lnum, matchcol, tm, timed_out)) == 0) {
                                if (timed_out != NULL && *timed_out)
                                    match_ok = FALSE;
                                break;
                            }
                            ptr = ml_get_buf (buf, lnum +matchpos.lnum, FALSE);
                        }
                        if (!match_ok)
                            continue;
                    }
                    if ((options & SEARCH_END) && !(options & SEARCH_NOOF) && !(matchpos.lnum == endpos.lnum && matchpos.col == endpos.col)) {
                        pos->lnum = lnum + endpos.lnum;
                        pos->col = endpos.col;
                        if (endpos.col == 0) {
                            if (pos->lnum > 1) {
                                --pos->lnum;
                                pos->col = (colnr_T) STRLEN (ml_get_buf (buf, pos->lnum, FALSE));
                            }
                        }
                        else {
                            --pos->col;
                        }
                    }
                    else {
                        pos->lnum = lnum + matchpos.lnum;
                        pos->col = matchpos.col;
                    }
                    pos->coladd = 0;
                    found = 1;
                    first_match = FALSE;
                    search_match_lines = endpos.lnum - matchpos.lnum;
                    search_match_endcol = endpos.col;
                    break;
                }
                line_breakcheck ();
                if (got_int)
                    break;
                if ((options & SEARCH_PEEK) && ((lnum - pos->lnum) & 0x3f) == 0 && char_avail ()) {
                    break_loop = TRUE;
                    break;
                }
                if (loop && lnum == start_pos.lnum)
                    break;
            }
            at_first_line = FALSE;
            if (!p_ws || stop_lnum != 0 || got_int || called_emsg || (timed_out != NULL && *timed_out) || break_loop || found || loop)
                break;
            if (dir == BACKWARD)
                lnum = buf->b_ml.ml_line_count;
            else
                lnum = 1;
            if (!shortmess (SHM_SEARCH) && (options & SEARCH_MSG))
                give_warning ((char_u *) _ (dir == BACKWARD ? top_bot_msg : bot_top_msg), TRUE);
        }
        if (got_int || called_emsg || (timed_out != NULL && *timed_out) || break_loop)
            break;
    }
    while (--count > 0 && found);
    vim_regfree (regmatch.regprog);
    called_emsg |= save_called_emsg;
    if (!found) {
        if (got_int)
            EMSG (_ (e_interr));
        else if ((options & SEARCH_MSG) == SEARCH_MSG) {
            if (p_ws)
                EMSG2 (_ (e_patnotf2), mr_pattern);
            else if (lnum == 0)
                EMSG2 (_ ("E384: search hit TOP without match for: %s"), mr_pattern);
            else
                EMSG2 (_ ("E385: search hit BOTTOM without match for: %s"), mr_pattern);
        }
        return FAIL;
    }
    if (pos->lnum > buf->b_ml.ml_line_count) {
        pos->lnum = buf->b_ml.ml_line_count;
        pos->col = (int) STRLEN (ml_get_buf (buf, pos->lnum, FALSE));
        if (pos->col > 0)
            --pos->col;
    }
    return submatch + 1;
}

static int first_submatch (regmmatch_T *rp) {
    int submatch;
    for (submatch = 1;; ++submatch) {
        if (rp->startpos[submatch].lnum >= 0)
            break;
        if (submatch == 9) {
            submatch = 0;
            break;
        }
    }
    return submatch;
}

char_u *last_search_pat (void) {
    return spats[last_idx].pat;
}

char_u *last_search_pattern (void) {
    return spats[RE_SEARCH].pat;
}

void save_last_search_pattern (void) {
    saved_last_search_spat = spats[RE_SEARCH];
    if (spats[RE_SEARCH].pat != NULL)
        saved_last_search_spat.pat = vim_strsave (spats[RE_SEARCH].pat);
    saved_last_idx = last_idx;
    saved_no_hlsearch = no_hlsearch;
}

void restore_last_search_pattern (void) {
    vim_free (spats [RE_SEARCH].pat);
    spats[RE_SEARCH] = saved_last_search_spat;
    set_vv_searchforward ();
    last_idx = saved_last_idx;
    SET_NO_HLSEARCH (saved_no_hlsearch);
}

int do_search (oparg_T *oap, int dirc, char_u *pat, long  count, int options, proftime_T *tm, int *timed_out) {
    pos_T pos;
    char_u *searchstr;
    struct soffset old_off;
    int retval;
    char_u *p;
    long  c;
    char_u *dircp;
    char_u *strcopy = NULL;
    char_u *ps;
    if (spats[0].off.line && vim_strchr (p_cpo, CPO_LINEOFF) != NULL) {
        spats[0].off.line = FALSE;
        spats[0].off.off = 0;
    }
    old_off = spats[0].off;
    pos = curwin->w_cursor;
    if (dirc == 0)
        dirc = spats[0].off.dir;
    else {
        spats[0].off.dir = dirc;
        set_vv_searchforward ();
    }
    if (options & SEARCH_REV) {
        if (dirc == '/')
            dirc = '?';
        else
            dirc = '/';
    }
    if (dirc == '/') {
        if (hasFolding (pos.lnum, NULL, &pos.lnum))
            pos.col = MAXCOL - 2;
    }
    else {
        if (hasFolding (pos.lnum, &pos.lnum, NULL))
            pos.col = 0;
    }
    if (no_hlsearch && !(options & SEARCH_KEEP)) {
        redraw_all_later (SOME_VALID);
        SET_NO_HLSEARCH (FALSE);
    }
    for (;;) {
        searchstr = pat;
        dircp = NULL;
        if (pat == NULL || *pat == NUL || *pat == dirc) {
            if (spats[RE_SEARCH].pat == NULL) {
                searchstr = spats[RE_SUBST].pat;
                if (searchstr == NULL) {
                    EMSG (_ (e_noprevre));
                    retval = 0;
                    goto end_do_search;
                }
            }
            else {
                searchstr = (char_u *) "";
            }
        }
        if (pat != NULL && *pat != NUL) {
            ps = strcopy;
            p = skip_regexp (pat, dirc, (int) p_magic, &strcopy);
            if (strcopy != ps) {
                searchcmdlen += (int) (STRLEN (pat) - STRLEN (strcopy));
                pat = strcopy;
                searchstr = strcopy;
            }
            if (*p == dirc) {
                dircp = p;
                *p++ = NUL;
            }
            spats[0].off.line = FALSE;
            spats[0].off.end = FALSE;
            spats[0].off.off = 0;
            if (*p == '+' || *p == '-' || VIM_ISDIGIT (*p))
                spats[0].off.line = TRUE;
            else if ((options & SEARCH_OPT) && (*p == 'e' || *p == 's' || *p == 'b')) {
                if (*p == 'e')
                    spats[0].off.end = SEARCH_END;
                ++p;
            }
            if (VIM_ISDIGIT (*p) || *p == '+' || *p == '-') {
                if (VIM_ISDIGIT (*p) || VIM_ISDIGIT (*(p + 1)))
                    spats[0].off.off = atol ((char *) p);
                else if (*p == '-')
                    spats[0].off.off = -1;
                else
                    spats[0].off.off = 1;
                ++p;
                while (VIM_ISDIGIT (*p))
                    ++p;
            }
            searchcmdlen += (int) (p - pat);
            pat = p;
        }
        if ((options & SEARCH_ECHO) && messaging () && !cmd_silent && msg_silent == 0) {
            char_u *msgbuf;
            char_u *trunc;
            if (*searchstr == NUL)
                p = spats[last_idx].pat;
            else
                p = searchstr;
            msgbuf = alloc ((unsigned ) (STRLEN (p) + 40));
            if (msgbuf != NULL) {
                msgbuf[0] = dirc;
                STRCPY (msgbuf + 1, p);
                if (spats[0].off.line || spats[0].off.end || spats[0].off.off) {
                    p = msgbuf + STRLEN (msgbuf);
                    *p++ = dirc;
                    if (spats[0].off.end)
                        *p++ = 'e';
                    else if (!spats[0].off.line)
                        *p++ = 's';
                    if (spats[0].off.off > 0 || spats[0].off.line)
                        *p++ = '+';
                    if (spats[0].off.off != 0 || spats[0].off.line)
                        sprintf ((char *) p, "%ld", spats[0].off.off);
                    else
                        *p = NUL;
                }
                msg_start ();
                trunc = msg_strtrunc (msgbuf, FALSE);
                if (curwin->w_p_rl && *curwin->w_p_rlc == 's') {
                    char_u *r;
                    r = reverse_text (trunc != NULL ? trunc : msgbuf);
                    if (r != NULL) {
                        vim_free (trunc);
                        trunc = r;
                    }
                }
                if (trunc != NULL) {
                    msg_outtrans (trunc);
                    vim_free (trunc);
                }
                else
                    msg_outtrans (msgbuf);
                msg_clr_eos ();
                msg_check ();
                vim_free (msgbuf);
                gotocmdline (FALSE);
                out_flush ();
                msg_nowait = TRUE;
            }
        }
        if (!spats[0].off.line && spats[0].off.off && pos.col < MAXCOL - 2) {
            if (spats[0].off.off > 0) {
                for (c = spats[0].off.off; c; --c)
                    if (decl (&pos) == -1)
                        break;
                if (c) {
                    pos.lnum = 0;
                    pos.col = MAXCOL;
                }
            }
            else {
                for (c = spats[0].off.off; c; ++c)
                    if (incl (&pos) == -1)
                        break;
                if (c) {
                    pos.lnum = curbuf->b_ml.ml_line_count + 1;
                    pos.col = 0;
                }
            }
        }
        if (p_altkeymap && curwin->w_p_rl)
            lrFswap (searchstr, 0);
        c = searchit (curwin, curbuf, &pos, dirc == '/' ? FORWARD : BACKWARD, searchstr, count, spats[0].off.end + (options & (SEARCH_KEEP + SEARCH_PEEK + SEARCH_HIS + SEARCH_MSG + SEARCH_START + ((pat != NULL && *pat == ';') ? 0 : SEARCH_NOOF))), RE_LAST, (linenr_T) 0, tm, timed_out);
        if (dircp != NULL)
            *dircp = dirc;
        if (c == FAIL) {
            retval = 0;
            goto end_do_search;
        }
        if (spats[0].off.end && oap != NULL)
            oap->inclusive = TRUE;
        retval = 1;
        if (!(options & SEARCH_NOOF) || (pat != NULL && *pat == ';')) {
            if (spats[0].off.line) {
                c = pos.lnum + spats[0].off.off;
                if (c < 1)
                    pos.lnum = 1;
                else if (c > curbuf->b_ml.ml_line_count)
                    pos.lnum = curbuf->b_ml.ml_line_count;
                else
                    pos.lnum = c;
                pos.col = 0;
                retval = 2;
            }
            else if (pos.col < MAXCOL - 2) {
                c = spats[0].off.off;
                if (c > 0) {
                    while (c-- > 0)
                        if (incl (&pos) == -1)
                            break;
                }
                else {
                    while (c++ < 0)
                        if (decl (&pos) == -1)
                            break;
                }
            }
        }
        if (!(options & SEARCH_OPT) || pat == NULL || *pat != ';')
            break;
        dirc = *++pat;
        if (dirc != '?' && dirc != '/') {
            retval = 0;
            EMSG (_ ("E386: Expected '?' or '/'  after ';'"));
            goto end_do_search;
        }
        ++pat;
    }
    if (options & SEARCH_MARK)
        setpcmark ();
    curwin->w_cursor = pos;
    curwin->w_set_curswant = TRUE;
end_do_search :
    if ((options & SEARCH_KEEP) || cmdmod.keeppatterns)
        spats[0].off = old_off;
    vim_free (strcopy);
    return retval;
}

int startPS (linenr_T lnum, int para, int both) {
    char_u *s;
    s = ml_get (lnum);
    if (*s == para || *s == '\f' || (both && *s == '}'))
        return TRUE;
    if (*s == '.' && (inmacro (p_sections, s +1) || (!para && inmacro (p_para, s +1))))
        return TRUE;
    return FALSE;
}

static int inmacro (char_u *opt, char_u *s) {
    char_u *macro;
    for (macro = opt; macro[0]; ++macro) {
        if ((macro[0] == s[0] || (macro[0] == ' ' && (s[0] == NUL || s[0] == ' '))) && (macro[1] == s[1] || ((macro[1] == NUL || macro[1] == ' ') && (s[0] == NUL || s[1] == NUL || s[1] == ' '))))
            break;
        ++macro;
        if (macro[0] == NUL)
            break;
    }
    return (macro[0] != NUL);
}

int bck_word (long  count, int bigword, int stop) {
    int sclass;
    curwin->w_cursor.coladd = 0;
    cls_bigword = bigword;
    while (--count >= 0) {
        if (hasFolding (curwin->w_cursor.lnum, &curwin->w_cursor.lnum, NULL))
            curwin->w_cursor.col = 0;
        sclass = cls ();
        if (dec_cursor () == -1)
            return FAIL;
        if (!stop || sclass == cls () || sclass == 0) {
            while (cls () == 0) {
                if (curwin->w_cursor.col == 0 && LINEEMPTY (curwin->w_cursor.lnum))
                    goto finished;
                if (dec_cursor () == -1)
                    return OK;
            }
            if (skip_chars (cls (), BACKWARD))
                return OK;
        }
        inc_cursor ();
    finished :
        stop = FALSE;
    }
    return OK;
}

static int cls (void) {
    int c;
    c = gchar_cursor ();
    if (p_altkeymap && c == F_BLANK)
        return 0;
    if (c == ' ' || c == '\t' || c == NUL)
        return 0;
    if (cls_bigword)
        return 1;
    if (vim_iswordc (c))
        return 2;
    return 1;
}

static int skip_chars (int cclass, int dir) {
    while (cls () == cclass)
        if ((dir == FORWARD ? inc_cursor () : dec_cursor ()) == -1)
            return TRUE;
    return FALSE;
}

int fwd_word (long  count, int bigword, int eol) {
    int sclass;
    int i;
    int last_line;
    curwin->w_cursor.coladd = 0;
    cls_bigword = bigword;
    while (--count >= 0) {
        if (hasFolding (curwin->w_cursor.lnum, NULL, &curwin->w_cursor.lnum))
            coladvance ((colnr_T) MAXCOL);
        sclass = cls ();
        last_line = (curwin->w_cursor.lnum == curbuf->b_ml.ml_line_count);
        i = inc_cursor ();
        if (i == -1 || (i >= 1 && last_line))
            return FAIL;
        if (i >= 1 && eol && count == 0)
            return OK;
        if (sclass != 0)
            while (cls () == sclass) {
                i = inc_cursor ();
                if (i == -1 || (i >= 1 && eol && count == 0))
                    return OK;
            }
        while (cls () == 0) {
            if (curwin->w_cursor.col == 0 && *ml_get_curline () == NUL)
                break;
            i = inc_cursor ();
            if (i == -1 || (i >= 1 && eol && count == 0))
                return OK;
        }
    }
    return OK;
}

void set_search_direction (int cdir) {
    spats[0].off.dir = cdir;
}

int findpar (int *pincl, int dir, long  count, int what, int both) {
    linenr_T curr;
    int did_skip;
    int first;
    int posix = (vim_strchr (p_cpo, CPO_PARA) != NULL);
    linenr_T fold_first;
    linenr_T fold_last;
    int fold_skipped;
    curr = curwin->w_cursor.lnum;
    while (count--) {
        did_skip = FALSE;
        for (first = TRUE;; first = FALSE) {
            if (*ml_get (curr) != NUL)
                did_skip = TRUE;
            fold_skipped = FALSE;
            if (first && hasFolding (curr, &fold_first, &fold_last)) {
                curr = ((dir > 0) ? fold_last : fold_first) + dir;
                fold_skipped = TRUE;
            }
            if (!first && did_skip && (startPS (curr, what, both) || (posix && what == NUL && *ml_get (curr) == '{')))
                break;
            if (fold_skipped)
                curr -= dir;
            if ((curr += dir) < 1 || curr > curbuf->b_ml.ml_line_count) {
                if (count)
                    return FALSE;
                curr -= dir;
                break;
            }
        }
    }
    setpcmark ();
    if (both && *ml_get (curr) == '}')
        ++curr;
    curwin->w_cursor.lnum = curr;
    if (curr == curbuf->b_ml.ml_line_count && what != '}') {
        char_u *line = ml_get (curr);
        if ((curwin->w_cursor.col = (colnr_T) STRLEN (line)) != 0) {
            --curwin->w_cursor.col;
            *pincl = TRUE;
        }
    }
    else
        curwin->w_cursor.col = 0;
    return TRUE;
}

int findsent (int dir, long  count) {
    pos_T pos, tpos;
    int c;
    int (*func) (pos_T *);
    int startlnum;
    int noskip = FALSE;
    int cpo_J;
    int found_dot;
    pos = curwin->w_cursor;
    if (dir == FORWARD)
        func = incl;
    else
        func = decl;
    while (count--) {
        if (gchar_pos (&pos) == NUL) {
            do
                if ((*func) (&pos) == -1)
                    break;
            while (gchar_pos (&pos) == NUL);
            if (dir == FORWARD)
                goto found;
        }
        else if (dir == FORWARD && pos.col == 0 && startPS (pos.lnum, NUL, FALSE)) {
            if (pos.lnum == curbuf->b_ml.ml_line_count)
                return FAIL;
            ++pos.lnum;
            goto found;
        }
        else if (dir == BACKWARD)
            decl (&pos);
        found_dot = FALSE;
        while ((c = gchar_pos (&pos)) == ' ' || c == '\t' || (dir == BACKWARD && vim_strchr ((char_u *) ".!?)]\"'", c) != NULL)) {
            if (vim_strchr ((char_u *) ".!?", c) != NULL) {
                if (found_dot)
                    break;
                found_dot = TRUE;
            }
            if (decl (&pos) == -1)
                break;
            if (LINEEMPTY (pos.lnum) && dir == FORWARD) {
                incl (& pos);
                goto found;
            }
        }
        startlnum = pos.lnum;
        cpo_J = vim_strchr (p_cpo, CPO_ENDOFSENT) != NULL;
        for (;;) {
            c = gchar_pos (&pos);
            if (c == NUL || (pos.col == 0 && startPS (pos.lnum, NUL, FALSE))) {
                if (dir == BACKWARD && pos.lnum != startlnum)
                    ++pos.lnum;
                break;
            }
            if (c == '.' || c == '!' || c == '?') {
                tpos = pos;
                do
                    if ((c = inc (&tpos)) == -1)
                        break;
                while (vim_strchr ((char_u *) ")]\"'", c = gchar_pos (&tpos)) != NULL);
                if (c == -1 || (!cpo_J && (c == ' ' || c == '\t')) || c == NUL || (cpo_J && (c == ' ' && inc (&tpos) >= 0 && gchar_pos (&tpos) == ' '))) {
                    pos = tpos;
                    if (gchar_pos (&pos) == NUL)
                        inc (&pos);
                    break;
                }
            }
            if ((*func) (&pos) == -1) {
                if (count)
                    return FAIL;
                noskip = TRUE;
                break;
            }
        }
    found :
        while (!noskip && ((c = gchar_pos (&pos)) == ' ' || c == '\t'))
            if (incl (&pos) == -1)
                break;
    }
    setpcmark ();
    curwin->w_cursor = pos;
    return OK;
}

void restore_search_patterns (void) {
    if (--save_level == 0) {
        vim_free (spats [0].pat);
        spats[0] = saved_spats[0];
        set_vv_searchforward ();
        vim_free (spats [1].pat);
        spats[1] = saved_spats[1];
        last_idx = saved_last_idx;
        SET_NO_HLSEARCH (saved_no_hlsearch);
    }
}

char_u *last_csearch (void) {
    return lastc;
}

int last_csearch_forward (void) {
    return lastcdir == FORWARD;
}

int last_csearch_until (void) {
    return last_t_cmd == TRUE;
}

void reset_search_dir (void) {
    spats[0].off.dir = '/';
    set_vv_searchforward ();
}

void set_last_csearch (int c, char_u *s, int len) {
    *lastc = c;
}

void set_csearch_direction (int cdir) {
    lastcdir = cdir;
}

void set_csearch_until (int t_cmd) {
    last_t_cmd = t_cmd;
}

int end_word (long  count, int bigword, int stop, int empty) {
    int sclass;
    curwin->w_cursor.coladd = 0;
    cls_bigword = bigword;
    while (--count >= 0) {
        if (hasFolding (curwin->w_cursor.lnum, NULL, &curwin->w_cursor.lnum))
            coladvance ((colnr_T) MAXCOL);
        sclass = cls ();
        if (inc_cursor () == -1)
            return FAIL;
        if (cls () == sclass && sclass != 0) {
            if (skip_chars (sclass, FORWARD))
                return FAIL;
        }
        else if (!stop || sclass == 0) {
            while (cls () == 0) {
                if (empty && curwin->w_cursor.col == 0 && LINEEMPTY (curwin->w_cursor.lnum))
                    goto finished;
                if (inc_cursor () == -1)
                    return FAIL;
            }
            if (skip_chars (cls (), FORWARD))
                return FAIL;
        }
        dec_cursor ();
    finished :
        stop = FALSE;
    }
    return OK;
}

int searchc (cmdarg_T *cap, int t_cmd) {
    int c = cap->nchar;
    int dir = cap->arg;
    long  count = cap->count1;
    int col;
    char_u *p;
    int len;
    int stop = TRUE;
    if (c != NUL) {
        if (!KeyStuffed) {
            *lastc = c;
            set_csearch_direction (dir);
            set_csearch_until (t_cmd);
        }
    }
    else {
        if (*lastc == NUL)
            return FAIL;
        if (dir)
            dir = -lastcdir;
        else
            dir = lastcdir;
        t_cmd = last_t_cmd;
        c = *lastc;
        if (vim_strchr (p_cpo, CPO_SCOLON) == NULL && count == 1 && t_cmd)
            stop = FALSE;
    }
    if (dir == BACKWARD)
        cap->oap->inclusive = FALSE;
    else
        cap->oap->inclusive = TRUE;
    p = ml_get_curline ();
    col = curwin->w_cursor.col;
    len = (int) STRLEN (p);
    while (count--) {
        {
            for (;;) {
                if ((col += dir) < 0 || col >= len)
                    return FAIL;
                if (p[col] == c && stop)
                    break;
                stop = TRUE;
            }
        }
    }
    if (t_cmd) {
        col -= dir;
    }
    curwin->w_cursor.col = col;
    return OK;
}

int current_search (long  count, int forward) {
    pos_T start_pos;
    pos_T orig_pos;
    pos_T pos;
    int i;
    int dir;
    int result;
    char_u old_p_ws = p_ws;
    int flags = 0;
    pos_T save_VIsual = VIsual;
    int one_char;
    int direction = forward ? FORWARD : BACKWARD;
    p_ws = FALSE;
    if (VIsual_active && *p_sel == 'e' && LT_POS (VIsual, curwin->w_cursor))
        dec_cursor ();
    if (VIsual_active) {
        orig_pos = curwin->w_cursor;
        pos = curwin->w_cursor;
        if (VIsual_active) {
            if (forward)
                incl (&pos);
            else
                decl (&pos);
        }
    }
    else
        orig_pos = pos = curwin->w_cursor;
    one_char = is_one_char (spats[last_idx].pat, TRUE, &curwin->w_cursor, FORWARD);
    if (one_char == -1) {
        p_ws = old_p_ws;
        return FAIL;
    }
    for (i = 0; i < 2; i++) {
        if (forward)
            dir = i;
        else
            dir = !i;
        flags = 0;
        if (!dir && !one_char)
            flags = SEARCH_END;
        result = searchit (curwin, curbuf, &pos, (dir ? FORWARD : BACKWARD), spats[last_idx].pat, (long ) (i ? count : 1), SEARCH_KEEP | flags, RE_SEARCH, 0, NULL, NULL);
        if (!result && i) {
            curwin->w_cursor = orig_pos;
            if (VIsual_active)
                VIsual = save_VIsual;
            p_ws = old_p_ws;
            return FAIL;
        }
        else if (!i && !result) {
            if (forward) {
                CLEAR_POS (& pos);
            }
            else {
                pos.lnum = curwin->w_buffer->b_ml.ml_line_count;
                pos.col = (colnr_T) STRLEN (ml_get (curwin->w_buffer->b_ml.ml_line_count));
            }
        }
        p_ws = old_p_ws;
    }
    start_pos = pos;
    flags = forward ? SEARCH_END : SEARCH_START;
    one_char = is_one_char (spats[last_idx].pat, FALSE, &pos, direction);
    if (one_char < 0)
        return FAIL;
    if (!one_char)
        result = searchit (curwin, curbuf, &pos, direction, spats[last_idx].pat, 0L, flags | SEARCH_KEEP, RE_SEARCH, 0, NULL, NULL);
    if (!VIsual_active)
        VIsual = start_pos;
    curwin->w_cursor = pos;
    VIsual_active = TRUE;
    VIsual_mode = 'v';
    if (VIsual_active) {
        redraw_curbuf_later (INVERTED);
        if (*p_sel == 'e') {
            if (forward && LTOREQ_POS (VIsual, curwin->w_cursor))
                inc_cursor ();
            else if (!forward && LTOREQ_POS (curwin->w_cursor, VIsual))
                inc (&VIsual);
        }
    }
    if (fdo_flags & FDO_SEARCH && KeyTyped)
        foldOpenCursor ();
    may_start_select ('c');
    setmouse ();
    redraw_curbuf_later (INVERTED);
    showmode ();
    return OK;
}

static int is_one_char (char_u *pattern, int move, pos_T *cur, int direction) {
    regmmatch_T regmatch;
    int nmatched = 0;
    int result = -1;
    pos_T pos;
    int save_called_emsg = called_emsg;
    int flag = 0;
    if (pattern == NULL)
        pattern = spats[last_idx].pat;
    if (search_regcomp (pattern, RE_SEARCH, RE_SEARCH, SEARCH_KEEP, &regmatch) == FAIL)
        return -1;
    regmatch.startpos[0].col = -1;
    if (move) {
        CLEAR_POS (& pos);
    }
    else {
        pos = *cur;
        flag = SEARCH_START;
    }
    if (searchit (curwin, curbuf, &pos, direction, pattern, 1, SEARCH_KEEP +flag, RE_SEARCH, 0, NULL, NULL) != FAIL) {
        called_emsg = FALSE;
        do {
            regmatch.startpos[0].col++;
            nmatched = vim_regexec_multi (&regmatch, curwin, curbuf, pos.lnum, regmatch.startpos[0].col, NULL, NULL);
            if (!nmatched)
                break;
        }
        while (direction == FORWARD ? regmatch.startpos[0].col < pos.col : regmatch.startpos[0].col > pos.col);
        if (!called_emsg) {
            result = (nmatched != 0 && regmatch.startpos[0].lnum == regmatch.endpos[0].lnum && regmatch.startpos[0].col == regmatch.endpos[0].col);
            if (!result && inc (&pos) >= 0 && pos.col == regmatch.endpos[0].col)
                result = TRUE;
        }
    }
    called_emsg |= save_called_emsg;
    vim_regfree (regmatch.regprog);
    return result;
}

int bckend_word (long  count, int bigword, int eol) {
    int sclass;
    int i;
    curwin->w_cursor.coladd = 0;
    cls_bigword = bigword;
    while (--count >= 0) {
        sclass = cls ();
        if ((i = dec_cursor ()) == -1)
            return FAIL;
        if (eol && i == 1)
            return OK;
        if (sclass != 0) {
            while (cls () == sclass)
                if ((i = dec_cursor ()) == -1 || (eol && i == 1))
                    return OK;
        }
        while (cls () == 0) {
            if (curwin->w_cursor.col == 0 && LINEEMPTY (curwin->w_cursor.lnum))
                break;
            if ((i = dec_cursor ()) == -1 || (eol && i == 1))
                return OK;
        }
    }
    return OK;
}

int current_word (oparg_T *oap, long  count, int include, int bigword) {
    pos_T start_pos;
    pos_T pos;
    int inclusive = TRUE;
    int include_white = FALSE;
    cls_bigword = bigword;
    CLEAR_POS (& start_pos);
    if (VIsual_active && *p_sel == 'e' && LT_POS (VIsual, curwin->w_cursor))
        dec_cursor ();
    if (!VIsual_active || EQUAL_POS (curwin->w_cursor, VIsual)) {
        back_in_line ();
        start_pos = curwin->w_cursor;
        if ((cls () == 0) == include) {
            if (end_word (1L, bigword, TRUE, TRUE) == FAIL)
                return FAIL;
        }
        else {
            fwd_word (1L, bigword, TRUE);
            if (curwin->w_cursor.col == 0)
                decl (&curwin->w_cursor);
            else
                oneleft ();
            if (include)
                include_white = TRUE;
        }
        if (VIsual_active) {
            VIsual = start_pos;
            redraw_curbuf_later (INVERTED);
        }
        else {
            oap->start = start_pos;
            oap->motion_type = MCHAR;
        }
        --count;
    }
    while (count > 0) {
        inclusive = TRUE;
        if (VIsual_active && LT_POS (curwin->w_cursor, VIsual)) {
            if (decl (&curwin->w_cursor) == -1)
                return FAIL;
            if (include != (cls () != 0)) {
                if (bck_word (1L, bigword, TRUE) == FAIL)
                    return FAIL;
            }
            else {
                if (bckend_word (1L, bigword, TRUE) == FAIL)
                    return FAIL;
                (void) incl (&curwin->w_cursor);
            }
        }
        else {
            if (incl (&curwin->w_cursor) == -1)
                return FAIL;
            if (include != (cls () == 0)) {
                if (fwd_word (1L, bigword, TRUE) == FAIL && count > 1)
                    return FAIL;
                if (oneleft () == FAIL)
                    inclusive = FALSE;
            }
            else {
                if (end_word (1L, bigword, TRUE, TRUE) == FAIL)
                    return FAIL;
            }
        }
        --count;
    }
    if (include_white && (cls () != 0 || (curwin->w_cursor.col == 0 && !inclusive))) {
        pos = curwin->w_cursor;
        curwin->w_cursor = start_pos;
        if (oneleft () == OK) {
            back_in_line ();
            if (cls () == 0 && curwin->w_cursor.col > 0) {
                if (VIsual_active)
                    VIsual = curwin->w_cursor;
                else
                    oap->start = curwin->w_cursor;
            }
        }
        curwin->w_cursor = pos;
    }
    if (VIsual_active) {
        if (*p_sel == 'e' && inclusive && LTOREQ_POS (VIsual, curwin->w_cursor))
            inc_cursor ();
        if (VIsual_mode == 'V') {
            VIsual_mode = 'v';
            redraw_cmdline = TRUE;
        }
    }
    else
        oap->inclusive = inclusive;
    return OK;
}

static void back_in_line (void) {
    int sclass;
    sclass = cls ();
    for (;;) {
        if (curwin->w_cursor.col == 0)
            break;
        dec_cursor ();
        if (cls () != sclass) {
            inc_cursor ();
            break;
        }
    }
}

int current_block (oparg_T *oap, long  count, int include, int what, int other) {
    pos_T old_pos;
    pos_T *pos = NULL;
    pos_T start_pos;
    pos_T *end_pos;
    pos_T old_start, old_end;
    char_u *save_cpo;
    int sol = FALSE;
    old_pos = curwin->w_cursor;
    old_end = curwin->w_cursor;
    old_start = old_end;
    if (!VIsual_active || EQUAL_POS (VIsual, curwin->w_cursor)) {
        setpcmark ();
        if (what == '{')
            while (inindent (1))
                if (inc_cursor () != 0)
                    break;
        if (gchar_cursor () == what)
            ++curwin->w_cursor.col;
    }
    else if (LT_POS (VIsual, curwin->w_cursor)) {
        old_start = VIsual;
        curwin->w_cursor = VIsual;
    }
    else
        old_end = VIsual;
    save_cpo = p_cpo;
    p_cpo = (char_u *) (vim_strchr (p_cpo, CPO_MATCHBSL) != NULL ? "%M" : "%");
    while (count-- > 0) {
        if ((pos = findmatch (NULL, what)) == NULL)
            break;
        curwin->w_cursor = *pos;
        start_pos = *pos;
    }
    p_cpo = save_cpo;
    if (pos == NULL || (end_pos = findmatch (NULL, other)) == NULL) {
        curwin->w_cursor = old_pos;
        return FAIL;
    }
    curwin->w_cursor = *end_pos;
    while (!include) {
        incl (& start_pos);
        sol = (curwin->w_cursor.col == 0);
        decl (& curwin -> w_cursor);
        while (inindent (1)) {
            sol = TRUE;
            if (decl (&curwin->w_cursor) != 0)
                break;
        }
        if (!LT_POS (start_pos, old_start) && !LT_POS (old_end, curwin->w_cursor) && VIsual_active) {
            curwin->w_cursor = old_start;
            decl (& curwin -> w_cursor);
            if ((pos = findmatch (NULL, what)) == NULL) {
                curwin->w_cursor = old_pos;
                return FAIL;
            }
            start_pos = *pos;
            curwin->w_cursor = *pos;
            if ((end_pos = findmatch (NULL, other)) == NULL) {
                curwin->w_cursor = old_pos;
                return FAIL;
            }
            curwin->w_cursor = *end_pos;
        }
        else
            break;
    }
    if (VIsual_active) {
        if (*p_sel == 'e')
            inc (&curwin->w_cursor);
        if (sol && gchar_cursor () != NUL)
            inc (&curwin->w_cursor);
        VIsual = start_pos;
        VIsual_mode = 'v';
        redraw_curbuf_later (INVERTED);
        showmode ();
    }
    else {
        oap->start = start_pos;
        oap->motion_type = MCHAR;
        oap->inclusive = FALSE;
        if (sol)
            incl (&curwin->w_cursor);
        else if (LTOREQ_POS (start_pos, curwin->w_cursor))
            oap->inclusive = TRUE;
        else
            curwin->w_cursor = start_pos;
    }
    return OK;
}

int current_tagblock (oparg_T *oap, long  count_arg, int include) {
    long  count = count_arg;
    long  n;
    pos_T old_pos;
    pos_T start_pos;
    pos_T end_pos;
    pos_T old_start, old_end;
    char_u *spat, *epat;
    char_u *p;
    char_u *cp;
    int len;
    int r;
    int do_include = include;
    int save_p_ws = p_ws;
    int retval = FAIL;
    int is_inclusive = TRUE;
    p_ws = FALSE;
    old_pos = curwin->w_cursor;
    old_end = curwin->w_cursor;
    old_start = old_end;
    if (!VIsual_active || *p_sel == 'e')
        decl (&old_end);
    if (!VIsual_active || EQUAL_POS (VIsual, curwin->w_cursor)) {
        setpcmark ();
        while (inindent (1))
            if (inc_cursor () != 0)
                break;
        if (in_html_tag (FALSE)) {
            while (*ml_get_cursor () != '>')
                if (inc_cursor () < 0)
                    break;
        }
        else if (in_html_tag (TRUE)) {
            while (*ml_get_cursor () != '<')
                if (dec_cursor () < 0)
                    break;
            dec_cursor ();
            old_end = curwin->w_cursor;
        }
    }
    else if (LT_POS (VIsual, curwin->w_cursor)) {
        old_start = VIsual;
        curwin->w_cursor = VIsual;
    }
    else
        old_end = VIsual;
again :
    for (n = 0; n < count; ++n) {
        if (do_searchpair ((char_u *) "<[^ \t>/!]\\+\\%(\\_s\\_[^>]\\{-}[^/]>\\|$\\|\\_s\\=>\\)", (char_u *) "", (char_u *) "</[^>]*>", BACKWARD, NULL, 0, NULL, (linenr_T) 0, 0L) <= 0) {
            curwin->w_cursor = old_pos;
            goto theend;
        }
    }
    start_pos = curwin->w_cursor;
    inc_cursor ();
    p = ml_get_cursor ();
    for (cp = p; *cp != NUL && *cp != '>' && !VIM_ISWHITE (*cp); MB_PTR_ADV (cp))
        ;
    len = (int) (cp - p);
    if (len == 0) {
        curwin->w_cursor = old_pos;
        goto theend;
    }
    spat = alloc (len +31);
    epat = alloc (len +9);
    if (spat == NULL || epat == NULL) {
        vim_free (spat);
        vim_free (epat);
        curwin->w_cursor = old_pos;
        goto theend;
    }
    sprintf ((char *) spat, "<%.*s\\>\\%%(\\s\\_[^>]\\{-}[^/]>\\|>\\)\\c", len, p);
    sprintf ((char *) epat, "</%.*s>\\c", len, p);
    r = do_searchpair (spat, (char_u *) "", epat, FORWARD, NULL, 0, NULL, (linenr_T) 0, 0L);
    vim_free (spat);
    vim_free (epat);
    if (r < 1 || LT_POS (curwin->w_cursor, old_end)) {
        count = 1;
        curwin->w_cursor = start_pos;
        goto again;
    }
    if (do_include || r < 1) {
        while (*ml_get_cursor () != '>')
            if (inc_cursor () < 0)
                break;
    }
    else {
        char_u *c = ml_get_cursor ();
        if (*c == '<' && !VIsual_active && curwin->w_cursor.col == 0)
            is_inclusive = FALSE;
        else if (*c == '<')
            dec_cursor ();
    }
    end_pos = curwin->w_cursor;
    if (!do_include) {
        curwin->w_cursor = start_pos;
        while (inc_cursor () >= 0)
            if (*ml_get_cursor () == '>') {
                inc_cursor ();
                start_pos = curwin->w_cursor;
                break;
            }
        curwin->w_cursor = end_pos;
        if (EQUAL_POS (start_pos, old_start) && EQUAL_POS (end_pos, old_end)) {
            do_include = TRUE;
            curwin->w_cursor = old_start;
            count = count_arg;
            goto again;
        }
    }
    if (VIsual_active) {
        if (LT_POS (end_pos, start_pos))
            curwin->w_cursor = start_pos;
        else if (*p_sel == 'e')
            inc_cursor ();
        VIsual = start_pos;
        VIsual_mode = 'v';
        redraw_curbuf_later (INVERTED);
        showmode ();
    }
    else {
        oap->start = start_pos;
        oap->motion_type = MCHAR;
        if (LT_POS (end_pos, start_pos)) {
            curwin->w_cursor = start_pos;
            oap->inclusive = FALSE;
        }
        else
            oap->inclusive = is_inclusive;
    }
    retval = OK;
theend :
    p_ws = save_p_ws;
    return retval;
}

static int in_html_tag (int end_tag) {
    char_u *line = ml_get_curline ();
    char_u *p;
    int c;
    int lc = NUL;
    pos_T pos;
    {
        for (p = line + curwin->w_cursor.col; p > line;) {
            if (*p == '<')
                break;
            MB_PTR_BACK (line, p);
            if (*p == '>')
                break;
        }
        if (*p != '<')
            return FALSE;
    }
    pos.lnum = curwin->w_cursor.lnum;
    pos.col = (colnr_T) (p - line);
    MB_PTR_ADV (p);
    if (end_tag)
        return *p == '/';
    if (*p == '/')
        return FALSE;
    for (;;) {
        if (inc (&pos) < 0)
            return FALSE;
        c = *ml_get_pos (&pos);
        if (c == '>')
            break;
        lc = c;
    }
    return lc != '/';
}

int current_par (oparg_T *oap, long  count, int include, int type) {
    linenr_T start_lnum;
    linenr_T end_lnum;
    int white_in_front;
    int dir;
    int start_is_white;
    int prev_start_is_white;
    int retval = OK;
    int do_white = FALSE;
    int t;
    int i;
    if (type == 'S')
        return FAIL;
    start_lnum = curwin->w_cursor.lnum;
    if (VIsual_active && start_lnum != VIsual.lnum) {
    extend :
        if (start_lnum < VIsual.lnum)
            dir = BACKWARD;
        else
            dir = FORWARD;
        for (i = count; --i >= 0;) {
            if (start_lnum == (dir == BACKWARD ? 1 : curbuf->b_ml.ml_line_count)) {
                retval = FAIL;
                break;
            }
            prev_start_is_white = -1;
            for (t = 0; t < 2; ++t) {
                start_lnum += dir;
                start_is_white = linewhite (start_lnum);
                if (prev_start_is_white == start_is_white) {
                    start_lnum -= dir;
                    break;
                }
                for (;;) {
                    if (start_lnum == (dir == BACKWARD ? 1 : curbuf->b_ml.ml_line_count))
                        break;
                    if (start_is_white != linewhite (start_lnum +dir) || (!start_is_white && startPS (start_lnum +(dir > 0 ? 1 : 0), 0, 0)))
                        break;
                    start_lnum += dir;
                }
                if (!include)
                    break;
                if (start_lnum == (dir == BACKWARD ? 1 : curbuf->b_ml.ml_line_count))
                    break;
                prev_start_is_white = start_is_white;
            }
        }
        curwin->w_cursor.lnum = start_lnum;
        curwin->w_cursor.col = 0;
        return retval;
    }
    white_in_front = linewhite (start_lnum);
    while (start_lnum > 1) {
        if (white_in_front) {
            if (!linewhite (start_lnum -1))
                break;
        }
        else {
            if (linewhite (start_lnum -1) || startPS (start_lnum, 0, 0))
                break;
        }
        --start_lnum;
    }
    end_lnum = start_lnum;
    while (end_lnum <= curbuf->b_ml.ml_line_count && linewhite (end_lnum))
        ++end_lnum;
    --end_lnum;
    i = count;
    if (!include && white_in_front)
        --i;
    while (i--) {
        if (end_lnum == curbuf->b_ml.ml_line_count)
            return FAIL;
        if (!include)
            do_white = linewhite (end_lnum +1);
        if (include || !do_white) {
            ++end_lnum;
            while (end_lnum < curbuf->b_ml.ml_line_count && !linewhite (end_lnum +1) && !startPS (end_lnum +1, 0, 0))
                ++end_lnum;
        }
        if (i == 0 && white_in_front && include)
            break;
        if (include || do_white)
            while (end_lnum < curbuf->b_ml.ml_line_count && linewhite (end_lnum +1))
                ++end_lnum;
    }
    if (!white_in_front && !linewhite (end_lnum) && include)
        while (start_lnum > 1 && linewhite (start_lnum -1))
            --start_lnum;
    if (VIsual_active) {
        if (VIsual_mode == 'V' && start_lnum == curwin->w_cursor.lnum)
            goto extend;
        if (VIsual.lnum != start_lnum) {
            VIsual.lnum = start_lnum;
            VIsual.col = 0;
        }
        VIsual_mode = 'V';
        redraw_curbuf_later (INVERTED);
        showmode ();
    }
    else {
        oap->start.lnum = start_lnum;
        oap->start.col = 0;
        oap->motion_type = MLINE;
    }
    curwin->w_cursor.lnum = end_lnum;
    curwin->w_cursor.col = 0;
    return OK;
}

int current_sent (oparg_T *oap, long  count, int include) {
    pos_T start_pos;
    pos_T pos;
    int start_blank;
    int c;
    int at_start_sent;
    long  ncount;
    start_pos = curwin->w_cursor;
    pos = start_pos;
    findsent (FORWARD, 1L);
    if (VIsual_active && !EQUAL_POS (start_pos, VIsual)) {
    extend :
        if (LT_POS (start_pos, VIsual)) {
            at_start_sent = TRUE;
            decl (& pos);
            while (LT_POS (pos, curwin->w_cursor)) {
                c = gchar_pos (&pos);
                if (!VIM_ISWHITE (c)) {
                    at_start_sent = FALSE;
                    break;
                }
                incl (& pos);
            }
            if (!at_start_sent) {
                findsent (BACKWARD, 1L);
                if (EQUAL_POS (curwin->w_cursor, start_pos))
                    at_start_sent = TRUE;
                else
                    findsent (FORWARD, 1L);
            }
            if (include)
                count *= 2;
            while (count--) {
                if (at_start_sent)
                    find_first_blank (&curwin->w_cursor);
                c = gchar_cursor ();
                if (!at_start_sent || (!include && !VIM_ISWHITE (c)))
                    findsent (BACKWARD, 1L);
                at_start_sent = !at_start_sent;
            }
        }
        else {
            incl (& pos);
            at_start_sent = TRUE;
            if (!EQUAL_POS (pos, curwin->w_cursor)) {
                at_start_sent = FALSE;
                while (LT_POS (pos, curwin->w_cursor)) {
                    c = gchar_pos (&pos);
                    if (!VIM_ISWHITE (c)) {
                        at_start_sent = TRUE;
                        break;
                    }
                    incl (& pos);
                }
                if (at_start_sent)
                    findsent (BACKWARD, 1L);
                else
                    curwin->w_cursor = start_pos;
            }
            if (include)
                count *= 2;
            findsent_forward (count, at_start_sent);
            if (*p_sel == 'e')
                ++curwin->w_cursor.col;
        }
        return OK;
    }
    while (c = gchar_pos (&pos), VIM_ISWHITE (c))
        incl (&pos);
    if (EQUAL_POS (pos, curwin->w_cursor)) {
        start_blank = TRUE;
        find_first_blank (& start_pos);
    }
    else {
        start_blank = FALSE;
        findsent (BACKWARD, 1L);
        start_pos = curwin->w_cursor;
    }
    if (include)
        ncount = count * 2;
    else {
        ncount = count;
        if (start_blank)
            --ncount;
    }
    if (ncount > 0)
        findsent_forward (ncount, TRUE);
    else
        decl (&curwin->w_cursor);
    if (include) {
        if (start_blank) {
            find_first_blank (& curwin -> w_cursor);
            c = gchar_pos (&curwin->w_cursor);
            if (VIM_ISWHITE (c))
                decl (&curwin->w_cursor);
        }
        else if (c = gchar_cursor (), !VIM_ISWHITE (c))
            find_first_blank (&start_pos);
    }
    if (VIsual_active) {
        if (EQUAL_POS (start_pos, curwin->w_cursor))
            goto extend;
        if (*p_sel == 'e')
            ++curwin->w_cursor.col;
        VIsual = start_pos;
        VIsual_mode = 'v';
        redraw_cmdline = TRUE;
        redraw_curbuf_later (INVERTED);
    }
    else {
        if (incl (&curwin->w_cursor) == -1)
            oap->inclusive = TRUE;
        else
            oap->inclusive = FALSE;
        oap->start = start_pos;
        oap->motion_type = MCHAR;
    }
    return OK;
}

static void find_first_blank (pos_T *posp) {
    int c;
    while (decl (posp) != -1) {
        c = gchar_pos (posp);
        if (!VIM_ISWHITE (c)) {
            incl (posp);
            break;
        }
    }
}

static void findsent_forward (long  count, int at_start_sent) {
    while (count--) {
        findsent (FORWARD, 1L);
        if (at_start_sent)
            find_first_blank (&curwin->w_cursor);
        if (count == 0 || at_start_sent)
            decl (&curwin->w_cursor);
        at_start_sent = !at_start_sent;
    }
}

int current_quote (oparg_T *oap, long  count, int include, int quotechar) {
    char_u *line = ml_get_curline ();
    int col_end;
    int col_start = curwin->w_cursor.col;
    int inclusive = FALSE;
    int vis_empty = TRUE;
    int vis_bef_curs = FALSE;
    int inside_quotes = FALSE;
    int selected_quote = FALSE;
    int i;
    if (VIsual_active) {
        if (VIsual.lnum != curwin->w_cursor.lnum)
            return FALSE;
        vis_bef_curs = LT_POS (VIsual, curwin->w_cursor);
        if (*p_sel == 'e') {
            if (!vis_bef_curs) {
                pos_T t = curwin->w_cursor;
                curwin->w_cursor = VIsual;
                VIsual = t;
                vis_bef_curs = TRUE;
            }
            dec_cursor ();
        }
        vis_empty = EQUAL_POS (VIsual, curwin->w_cursor);
    }
    if (!vis_empty) {
        if (vis_bef_curs) {
            inside_quotes = VIsual.col > 0 && line[VIsual.col - 1] == quotechar && line[curwin->w_cursor.col] != NUL && line[curwin->w_cursor.col + 1] == quotechar;
            i = VIsual.col;
            col_end = curwin->w_cursor.col;
        }
        else {
            inside_quotes = curwin->w_cursor.col > 0 && line[curwin->w_cursor.col - 1] == quotechar && line[VIsual.col] != NUL && line[VIsual.col + 1] == quotechar;
            i = curwin->w_cursor.col;
            col_end = VIsual.col;
        }
        while (i <= col_end)
            if (line[i++] == quotechar) {
                selected_quote = TRUE;
                break;
            }
    }
    if (!vis_empty && line[col_start] == quotechar) {
        if (vis_bef_curs) {
            col_start = find_next_quote (line, col_start +1, quotechar, NULL);
            if (col_start < 0)
                return FALSE;
            col_end = find_next_quote (line, col_start +1, quotechar, curbuf->b_p_qe);
            if (col_end < 0) {
                col_end = col_start;
                col_start = curwin->w_cursor.col;
            }
        }
        else {
            col_end = find_prev_quote (line, col_start, quotechar, NULL);
            if (line[col_end] != quotechar)
                return FALSE;
            col_start = find_prev_quote (line, col_end, quotechar, curbuf->b_p_qe);
            if (line[col_start] != quotechar) {
                col_start = col_end;
                col_end = curwin->w_cursor.col;
            }
        }
    }
    else if (line[col_start] == quotechar || !vis_empty) {
        int first_col = col_start;
        if (!vis_empty) {
            if (vis_bef_curs)
                first_col = find_next_quote (line, col_start, quotechar, NULL);
            else
                first_col = find_prev_quote (line, col_start, quotechar, NULL);
        }
        col_start = 0;
        for (;;) {
            col_start = find_next_quote (line, col_start, quotechar, NULL);
            if (col_start < 0 || col_start > first_col)
                return FALSE;
            col_end = find_next_quote (line, col_start +1, quotechar, curbuf->b_p_qe);
            if (col_end < 0)
                return FALSE;
            if (col_start <= first_col && first_col <= col_end)
                break;
            col_start = col_end + 1;
        }
    }
    else {
        col_start = find_prev_quote (line, col_start, quotechar, curbuf->b_p_qe);
        if (line[col_start] != quotechar) {
            col_start = find_next_quote (line, col_start, quotechar, NULL);
            if (col_start < 0)
                return FALSE;
        }
        col_end = find_next_quote (line, col_start +1, quotechar, curbuf->b_p_qe);
        if (col_end < 0)
            return FALSE;
    }
    if (include) {
        if (VIM_ISWHITE (line[col_end + 1]))
            while (VIM_ISWHITE (line[col_end + 1]))
                ++col_end;
            else
                while (col_start > 0 && VIM_ISWHITE (line[col_start - 1]))
                    --col_start;
    }
    if (!include && count < 2 && (vis_empty || !inside_quotes))
        ++col_start;
    curwin->w_cursor.col = col_start;
    if (VIsual_active) {
        if (vis_empty || (vis_bef_curs && !selected_quote && (inside_quotes || (line[VIsual.col] != quotechar && (VIsual.col == 0 || line[VIsual.col - 1] != quotechar))))) {
            VIsual = curwin->w_cursor;
            redraw_curbuf_later (INVERTED);
        }
    }
    else {
        oap->start = curwin->w_cursor;
        oap->motion_type = MCHAR;
    }
    curwin->w_cursor.col = col_end;
    if ((include || count > 1 || (!vis_empty && inside_quotes)) && inc_cursor () == 2)
        inclusive = TRUE;
    if (VIsual_active) {
        if (vis_empty || vis_bef_curs) {
            if (*p_sel != 'e')
                dec_cursor ();
        }
        else {
            if (inside_quotes || (!selected_quote && line[VIsual.col] != quotechar && (line[VIsual.col] == NUL || line[VIsual.col + 1] != quotechar))) {
                dec_cursor ();
                VIsual = curwin->w_cursor;
            }
            curwin->w_cursor.col = col_start;
        }
        if (VIsual_mode == 'V') {
            VIsual_mode = 'v';
            redraw_cmdline = TRUE;
        }
    }
    else {
        oap->inclusive = inclusive;
    }
    return OK;
}

static int find_next_quote (char_u *line, int col, int quotechar, char_u *escape) {
    int c;
    for (;;) {
        c = line[col];
        if (c == NUL)
            return -1;
        else if (escape != NULL && vim_strchr (escape, c))
            ++col;
        else if (c == quotechar)
            break;
        ++col;
    }
    return col;
}

static int find_prev_quote (char_u *line, int col_start, int quotechar, char_u *escape) {
    int n;
    while (col_start > 0) {
        --col_start;
        n = 0;
        if (escape != NULL)
            while (col_start - n > 0 && vim_strchr (escape, line[col_start - n - 1]) != NULL)
                ++n;
        if (n & 1)
            col_start -= n;
        else if (line[col_start] == quotechar)
            break;
    }
    return col_start;
}

