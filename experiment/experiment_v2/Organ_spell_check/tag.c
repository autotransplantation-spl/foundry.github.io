
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
struct tag_pointers {
    char_u *tagname;
    char_u *tagname_end;
    char_u *fname;
    char_u *fname_end;
    char_u *command;
    char_u *command_end;
    char_u *tag_fname;
    int is_etag;
    char_u *tagkind;
    char_u *tagkind_end;
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
EXTERN char_u e_patnotf2 [] INIT (= N_ ("E486: Pattern not found: %s"));
EXTERN char_u e_patnotf [] INIT (= N_ ("Pattern not found"));
EXTERN char_u *p_path;
EXTERN char_u *p_header;
EXTERN int p_ws;
EXTERN int KeyTyped;
taggy_T ptag_entry = {NULL, {INIT_POS_T (0, 0, 0), 0}, 0, 0};
EXTERN int p_tgst;
EXTERN int p_tr;
EXTERN char_u *p_tags;
EXTERN char_u *p_hf;
EXTERN int p_sft;
EXTERN long  p_verbose;
EXTERN int p_tbs;
EXTERN long  p_tl;
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
EXTERN char_u *p_titlestring;
char *mt_names [MT_COUNT / 2] = {"FSC", "F C", "F  ", "FS ", " SC", "  C", "   ", " S "};
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
char_u *bottommsg = (char_u *) N_ ("E555: at bottom of tag stack");
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
garray_T tag_fnames = GA_EMPTY;
char_u *nofile_fname = NULL;
EXTERN unsigned  swb_flags;
EXTERN pos_T where_paste_started;
EXTERN char_u e_zerocount [] INIT (= N_ ("E939: Positive count required"));
EXTERN char_u e_nomatch2 [] INIT (= N_ ("E480: No match: %s"));
EXTERN char_u e_nomatch [] INIT (= N_ ("E479: No match"));
EXTERN char_u *autocmd_match INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_out INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_in INIT (= NULL);
EXTERN linenr_T search_match_lines;
char_u *tagmatchname = NULL;
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
char_u *topmsg = (char_u *) N_ ("E556: at top of tag stack");
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

void simplify_filename (char_u *filename) {
    int components = 0;
    char_u *p, *tail, *start;
    int stripping_disabled = FALSE;
    int relative = TRUE;
    p = filename;
    if (vim_ispathsep (*p)) {
        relative = FALSE;
        do
            ++p;
        while (vim_ispathsep (*p));
    }
    start = p;
    do {
        if (vim_ispathsep (*p))
            STRMOVE (p, p +1);
        else if (p[0] == '.' && (vim_ispathsep (p[1]) || p[1] == NUL)) {
            if (p == start && relative)
                p += 1 + (p[1] != NUL);
            else {
                tail = p + 1;
                if (p[1] != NUL)
                    while (vim_ispathsep (*tail))
                        MB_PTR_ADV (tail);
                    else if (p > start)
                        --p;
                STRMOVE (p, tail);
            }
        }
        else if (p[0] == '.' && p[1] == '.' && (vim_ispathsep (p[2]) || p[2] == NUL)) {
            tail = p + 2;
            while (vim_ispathsep (*tail))
                MB_PTR_ADV (tail);
            if (components > 0) {
                int do_strip = FALSE;
                char_u saved_char;
                stat_T st;
                if (!stripping_disabled) {
                    saved_char = p[-1];
                    p[-1] = NUL;
                    if (mch_lstat ((char *) filename, &st) < 0)
                        do_strip = TRUE;
                    p[-1] = saved_char;
                    --p;
                    while (p > start && !after_pathsep (start, p))
                        MB_PTR_BACK (start, p);
                    if (!do_strip) {
                        saved_char = *tail;
                        *tail = NUL;
                        if (mch_stat ((char *) filename, &st) >= 0)
                            do_strip = TRUE;
                        else
                            stripping_disabled = TRUE;
                        *tail = saved_char;
                        if (do_strip) {
                            stat_T new_st;
                            if (p == start && relative)
                                (void) mch_stat (".", &new_st);
                            else {
                                saved_char = *p;
                                *p = NUL;
                                (void) mch_stat ((char *) filename, &new_st);
                                *p = saved_char;
                            }
                            if (new_st.st_ino != st.st_ino || new_st.st_dev != st.st_dev) {
                                do_strip = FALSE;
                            }
                        }
                    }
                }
                if (!do_strip) {
                    p = tail;
                    components = 0;
                }
                else {
                    if (p == start && relative && tail[-1] == '.') {
                        *p++ = '.';
                        *p = NUL;
                    }
                    else {
                        if (p > start && tail[-1] == '.')
                            --p;
                        STRMOVE (p, tail);
                    }
                    --components;
                }
            }
            else if (p == start && !relative)
                STRMOVE (p, tail);
            else {
                if (p == start + 2 && p[-2] == '.') {
                    STRMOVE (p - 2, p);
                    tail -= 2;
                }
                p = tail;
            }
        }
        else {
            ++components;
            p = getnextcomp (p);
        }
    }
    while (*p != NUL);
}

int find_tags (char_u *pat, int *num_matches, char_u ***matchesp, int flags, int mincount, char_u *buf_ffname) {
    FILE *fp;
    char_u *lbuf;
    int lbuf_size = LSIZE;
    char_u *tag_fname;
    tagname_T tn;
    int first_file;
    tagptrs_T tagp;
    int did_open = FALSE;
    int stop_searching = FALSE;
    int retval = FAIL;
    int is_static;
    int is_current;
    int eof = FALSE;
    char_u *p;
    char_u *s;
    int i;
    int tag_file_sorted = NUL;
    struct tag_search_info {
        off_T low_offset;
        off_T high_offset;
        off_T curr_offset;
        off_T curr_offset_used;
        off_T match_offset;
        int low_char;
        int high_char;
    } search_info;
    off_T filesize;
    int tagcmp;
    off_T offset;
    int round;
    enum {TS_START, TS_LINEAR, TS_BINARY, TS_SKIP_BACK, TS_STEP_FORWARD} state;
    int cmplen;
    int match;
    int match_no_ic = 0;
    int match_re;
    int matchoff = 0;
    int save_emsg_off;

    # define INCSTACK_SIZE 42
    struct {
        FILE *fp;
        char_u *etag_fname;
    } incstack [INCSTACK_SIZE];
    int incstack_idx = 0;
    char_u *ebuf;
    int is_etag;
    char_u *mfp;
    garray_T ga_match [MT_COUNT];
    hashtab_T ht_match [MT_COUNT];
    hash_T hash = 0;
    int match_count = 0;
    char_u **matches;
    int mtt;
    int help_save;
    int help_pri = 0;
    char_u *help_lang_find = NULL;
    char_u help_lang [3];
    char_u *saved_pat = NULL;
    int is_txt = FALSE;
    pat_T orgpat;
    int findall = (mincount == MAXCOL || mincount == TAG_MANY);
    int sort_error = FALSE;
    int linear;
    int sortic = FALSE;
    int line_error = FALSE;
    int has_re = (flags & TAG_REGEXP);
    int help_only = (flags & TAG_HELP);
    int name_only = (flags & TAG_NAMES);
    int noic = (flags & TAG_NOIC);
    int get_it_again = FALSE;
    int verbose = (flags & TAG_VERBOSE);
    int save_p_ic = p_ic;
    switch (curbuf->b_tc_flags ? curbuf->b_tc_flags : tc_flags) {
    case TC_FOLLOWIC :
        break;
    case TC_IGNORE :
        p_ic = TRUE;
        break;
    case TC_MATCH :
        p_ic = FALSE;
        break;
    case TC_FOLLOWSCS :
        p_ic = ignorecase (pat);
        break;
    case TC_SMART :
        p_ic = ignorecase_opt (pat, TRUE, TRUE);
        break;
    }
    help_save = curbuf->b_help;
    orgpat.pat = pat;
    lbuf = alloc (lbuf_size);
    tag_fname = alloc (MAXPATHL +1);
    ebuf = alloc (LSIZE);
    for (mtt = 0; mtt < MT_COUNT; ++mtt) {
        ga_init2 (& ga_match [mtt], (int) sizeof (char_u *), 100);
        hash_init (& ht_match [mtt]);
    }
    if (lbuf == NULL || tag_fname == NULL || ebuf == NULL)
        goto findtag_end;
    if (help_only)
        curbuf->b_help = TRUE;
    orgpat.len = (int) STRLEN (pat);
    if (curbuf->b_help) {
        if (orgpat.len > 3 && pat[orgpat.len - 3] == '@' && ASCII_ISALPHA (pat[orgpat.len - 2]) && ASCII_ISALPHA (pat[orgpat.len - 1])) {
            saved_pat = vim_strnsave (pat, orgpat.len - 3);
            if (saved_pat != NULL) {
                help_lang_find = &pat[orgpat.len - 2];
                orgpat.pat = saved_pat;
                orgpat.len -= 3;
            }
        }
    }
    if (p_tl != 0 && orgpat.len > p_tl)
        orgpat.len = p_tl;
    save_emsg_off = emsg_off;
    emsg_off = TRUE;
    prepare_pats (& orgpat, has_re);
    emsg_off = save_emsg_off;
    if (has_re && orgpat.regmatch.regprog == NULL)
        goto findtag_end;
    vim_memset (& search_info, 0, (size_t) 1);
    if ((flags & TAG_KEEP_LANG) && help_lang_find == NULL && curbuf->b_fname != NULL && (i = (int) STRLEN (curbuf->b_fname)) > 4 && STRICMP (curbuf->b_fname + i - 4, ".txt") == 0)
        is_txt = TRUE;
    orgpat.regmatch.rm_ic = ((p_ic || !noic) && (findall || orgpat.headlen == 0 || !p_tbs));
    for (round = 1; round <= 2; ++round) {
        linear = (orgpat.headlen == 0 || !p_tbs || round == 2);
        for (first_file = TRUE; get_tagfname (&tn, first_file, tag_fname) == OK; first_file = FALSE) {
            {
                if (curbuf->b_help) {
                    if (is_txt)
                        STRCPY (help_lang, "en");
                    else {
                        i = (int) STRLEN (tag_fname);
                        if (i > 3 && tag_fname[i - 3] == '-')
                            STRCPY (help_lang, tag_fname +i - 2);
                        else
                            STRCPY (help_lang, "en");
                    }
                    if (help_lang_find != NULL && STRICMP (help_lang, help_lang_find) != 0)
                        continue;
                    if ((flags & TAG_KEEP_LANG) && help_lang_find == NULL && curbuf->b_fname != NULL && (i = (int) STRLEN (curbuf->b_fname)) > 4 && curbuf->b_fname[i - 1] == 'x' && curbuf->b_fname[i - 4] == '.' && STRNICMP (curbuf->b_fname + i - 3, help_lang, 2) == 0)
                        help_pri = 0;
                    else {
                        help_pri = 1;
                        for (s = p_hlg; *s != NUL; ++s) {
                            if (STRNICMP (s, help_lang, 2) == 0)
                                break;
                            ++help_pri;
                            if ((s = vim_strchr (s, ',')) == NULL)
                                break;
                        }
                        if (s == NULL || *s == NUL) {
                            ++help_pri;
                            if (STRICMP (help_lang, "en") != 0)
                                ++help_pri;
                        }
                    }
                }
                if ((fp = mch_fopen ((char *) tag_fname, "r")) == NULL)
                    continue;
                if (p_verbose >= 5) {
                    verbose_enter ();
                    smsg ((char_u *) _ ("Searching tags file %s"), tag_fname);
                    verbose_leave ();
                }
            }
            did_open = TRUE;
            state = TS_START;
            is_etag = 0;
            for (;;) {
                if (state == TS_BINARY || state == TS_SKIP_BACK)
                    line_breakcheck ();
                else
                    fast_breakcheck ();
                if ((flags & TAG_INS_COMP))
                    ins_compl_check_keys (30, FALSE);
                if (got_int || compl_interrupted) {
                    stop_searching = TRUE;
                    break;
                }
                if (mincount == TAG_MANY && match_count >= TAG_MANY) {
                    stop_searching = TRUE;
                    retval = OK;
                    break;
                }
                if (get_it_again)
                    goto line_read_in;
                if (state == TS_BINARY) {
                    offset = search_info.low_offset + ((search_info.high_offset - search_info.low_offset) / 2);
                    if (offset == search_info.curr_offset)
                        break;
                    else
                        search_info.curr_offset = offset;
                }
                else if (state == TS_SKIP_BACK) {
                    search_info.curr_offset -= LSIZE * 2;
                    if (search_info.curr_offset < 0) {
                        search_info.curr_offset = 0;
                        rewind (fp);
                        state = TS_STEP_FORWARD;
                    }
                }
                if (state == TS_BINARY || state == TS_SKIP_BACK) {
                    search_info.curr_offset_used = search_info.curr_offset;
                    vim_fseek (fp, search_info.curr_offset, SEEK_SET);
                    eof = tag_fgets (lbuf, LSIZE, fp);
                    if (!eof && search_info.curr_offset != 0) {
                        search_info.curr_offset = vim_ftell (fp);
                        if (search_info.curr_offset == search_info.high_offset) {
                            vim_fseek (fp, search_info.low_offset, SEEK_SET);
                            search_info.curr_offset = search_info.low_offset;
                        }
                        eof = tag_fgets (lbuf, LSIZE, fp);
                    }
                    while (!eof && vim_isblankline (lbuf)) {
                        search_info.curr_offset = vim_ftell (fp);
                        eof = tag_fgets (lbuf, LSIZE, fp);
                    }
                    if (eof) {
                        state = TS_SKIP_BACK;
                        search_info.match_offset = vim_ftell (fp);
                        search_info.curr_offset = search_info.curr_offset_used;
                        continue;
                    }
                }
                else {
                    do {
                        eof = tag_fgets (lbuf, LSIZE, fp);
                    }
                    while (!eof && vim_isblankline (lbuf));
                    if (eof) {
                        if (incstack_idx) {
                            --incstack_idx;
                            fclose (fp);
                            fp = incstack[incstack_idx].fp;
                            STRCPY (tag_fname, incstack [incstack_idx].etag_fname);
                            vim_free (incstack [incstack_idx].etag_fname);
                            is_etag = 1;
                            continue;
                        }
                        else
                            break;
                    }
                }
            line_read_in :
                if (*lbuf == Ctrl_L) {
                    is_etag = 1;
                    state = TS_LINEAR;
                    if (!tag_fgets (ebuf, LSIZE, fp)) {
                        for (p = ebuf; *p && *p != ','; p++)
                            ;
                        *p = NUL;
                        if (STRNCMP (p +1, "include", 7) == 0 && incstack_idx < INCSTACK_SIZE) {
                            if ((incstack[incstack_idx].etag_fname = vim_strsave (tag_fname)) != NULL) {
                                char_u *fullpath_ebuf;
                                incstack[incstack_idx].fp = fp;
                                fp = NULL;
                                fullpath_ebuf = expand_tag_fname (ebuf, tag_fname, FALSE);
                                if (fullpath_ebuf != NULL) {
                                    fp = mch_fopen ((char *) fullpath_ebuf, "r");
                                    if (fp != NULL) {
                                        if (STRLEN (fullpath_ebuf) > LSIZE)
                                            EMSG2 (_ ("E430: Tag file path truncated for %s\n"), ebuf);
                                        vim_strncpy (tag_fname, fullpath_ebuf, MAXPATHL);
                                        ++incstack_idx;
                                        is_etag = 0;
                                    }
                                    vim_free (fullpath_ebuf);
                                }
                                if (fp == NULL) {
                                    fp = incstack[incstack_idx].fp;
                                    vim_free (incstack [incstack_idx].etag_fname);
                                }
                            }
                        }
                    }
                    continue;
                }
                if (state == TS_START) {
                    if (STRNCMP (lbuf, "!_TAG_", 6) <= 0 || (lbuf[0] == '!' && ASCII_ISLOWER (lbuf[1]))) {
                        if (STRNCMP (lbuf, "!_TAG_", 6) != 0)
                            goto parse_line;
                        if (STRNCMP (lbuf, "!_TAG_FILE_SORTED\t", 18) == 0)
                            tag_file_sorted = lbuf[18];
                        continue;
                    }
                    if (linear)
                        state = TS_LINEAR;
                    else if (tag_file_sorted == NUL)
                        state = TS_BINARY;
                    else if (tag_file_sorted == '1')
                        state = TS_BINARY;
                    else if (tag_file_sorted == '2') {
                        state = TS_BINARY;
                        sortic = TRUE;
                        orgpat.regmatch.rm_ic = (p_ic || !noic);
                    }
                    else
                        state = TS_LINEAR;
                    if (state == TS_BINARY && orgpat.regmatch.rm_ic && !sortic) {
                        linear = TRUE;
                        state = TS_LINEAR;
                    }
                    if (state == TS_BINARY) {
                        if ((filesize = vim_lseek (fileno (fp), (off_T) 0L, SEEK_END)) <= 0)
                            state = TS_LINEAR;
                        else {
                            vim_lseek (fileno (fp), (off_T) 0L, SEEK_SET);
                            search_info.low_offset = 0;
                            search_info.low_char = 0;
                            search_info.high_offset = filesize;
                            search_info.curr_offset = 0;
                            search_info.high_char = 0xff;
                        }
                        continue;
                    }
                }
            parse_line :
                if (orgpat.headlen && !is_etag) {
                    vim_memset (& tagp, 0, sizeof (tagp));
                    tagp.tagname = lbuf;
                    tagp.tagname_end = vim_strchr (lbuf, TAB);
                    if (tagp.tagname_end == NULL) {
                        if (vim_strchr (lbuf, NL) == NULL) {
                            if (p_verbose >= 5) {
                                verbose_enter ();
                                MSG (_ ("Ignoring long line in tags file"));
                                verbose_leave ();
                            }
                            if (state != TS_LINEAR) {
                                linear = TRUE;
                                state = TS_LINEAR;
                                vim_fseek (fp, search_info.low_offset, SEEK_SET);
                            }
                            continue;
                        }
                        line_error = TRUE;
                        break;
                    }
                    tagp.fname = NULL;
                    for (p = lbuf; p < tagp.tagname_end; ++p) {
                        if (*p == ':') {
                            if (tagp.fname == NULL)
                                tagp.fname = tagp.tagname_end + 1;
                            if (fnamencmp (lbuf, tagp.fname, p -lbuf) == 0 && tagp.fname[p - lbuf] == TAB) {
                                tagp.tagname = p + 1;
                                break;
                            }
                        }
                    }
                    cmplen = (int) (tagp.tagname_end - tagp.tagname);
                    if (p_tl != 0 && cmplen > p_tl)
                        cmplen = p_tl;
                    if (has_re && orgpat.headlen < cmplen)
                        cmplen = orgpat.headlen;
                    else if (state == TS_LINEAR && orgpat.headlen != cmplen)
                        continue;
                    if (state == TS_BINARY) {
                        i = (int) tagp.tagname[0];
                        if (sortic)
                            i = (int) TOUPPER_ASC (tagp.tagname[0]);
                        if (i < search_info.low_char || i > search_info.high_char)
                            sort_error = TRUE;
                        if (sortic)
                            tagcmp = tag_strnicmp (tagp.tagname, orgpat.head, (size_t) cmplen);
                        else
                            tagcmp = STRNCMP (tagp.tagname, orgpat.head, cmplen);
                        if (tagcmp == 0) {
                            if (cmplen < orgpat.headlen)
                                tagcmp = -1;
                            else if (cmplen > orgpat.headlen)
                                tagcmp = 1;
                        }
                        if (tagcmp == 0) {
                            state = TS_SKIP_BACK;
                            search_info.match_offset = search_info.curr_offset;
                            continue;
                        }
                        if (tagcmp < 0) {
                            search_info.curr_offset = vim_ftell (fp);
                            if (search_info.curr_offset < search_info.high_offset) {
                                search_info.low_offset = search_info.curr_offset;
                                if (sortic)
                                    search_info.low_char = TOUPPER_ASC (tagp.tagname[0]);
                                else
                                    search_info.low_char = tagp.tagname[0];
                                continue;
                            }
                        }
                        if (tagcmp > 0 && search_info.curr_offset != search_info.high_offset) {
                            search_info.high_offset = search_info.curr_offset;
                            if (sortic)
                                search_info.high_char = TOUPPER_ASC (tagp.tagname[0]);
                            else
                                search_info.high_char = tagp.tagname[0];
                            continue;
                        }
                        break;
                    }
                    else if (state == TS_SKIP_BACK) {
                        if (MB_STRNICMP (tagp.tagname, orgpat.head, cmplen) != 0)
                            state = TS_STEP_FORWARD;
                        else
                            search_info.curr_offset = search_info.curr_offset_used;
                        continue;
                    }
                    else if (state == TS_STEP_FORWARD) {
                        if (MB_STRNICMP (tagp.tagname, orgpat.head, cmplen) != 0) {
                            if ((off_T) vim_ftell (fp) > search_info.match_offset)
                                break;
                            else
                                continue;
                        }
                    }
                    else if (MB_STRNICMP (tagp.tagname, orgpat.head, cmplen) != 0)
                        continue;
                    if (tagp.fname == NULL)
                        tagp.fname = tagp.tagname_end + 1;
                    tagp.fname_end = vim_strchr (tagp.fname, TAB);
                    tagp.command = tagp.fname_end + 1;
                    if (tagp.fname_end == NULL)
                        i = FAIL;
                    else
                        i = OK;
                }
                else
                    i = parse_tag_line (lbuf, is_etag, &tagp);
                if (i == FAIL) {
                    line_error = TRUE;
                    break;
                }
                if (is_etag)
                    tagp.fname = ebuf;
                cmplen = (int) (tagp.tagname_end - tagp.tagname);
                if (p_tl != 0 && cmplen > p_tl)
                    cmplen = p_tl;
                if (orgpat.len != cmplen)
                    match = FALSE;
                else {
                    if (orgpat.regmatch.rm_ic) {
                        match = (MB_STRNICMP (tagp.tagname, orgpat.pat, cmplen) == 0);
                        if (match)
                            match_no_ic = (STRNCMP (tagp.tagname, orgpat.pat, cmplen) == 0);
                    }
                    else
                        match = (STRNCMP (tagp.tagname, orgpat.pat, cmplen) == 0);
                }
                match_re = FALSE;
                if (!match && orgpat.regmatch.regprog != NULL) {
                    int cc;
                    cc = *tagp.tagname_end;
                    *tagp.tagname_end = NUL;
                    match = vim_regexec (&orgpat.regmatch, tagp.tagname, (colnr_T) 0);
                    if (match) {
                        matchoff = (int) (orgpat.regmatch.startp[0] - tagp.tagname);
                        if (orgpat.regmatch.rm_ic) {
                            orgpat.regmatch.rm_ic = FALSE;
                            match_no_ic = vim_regexec (&orgpat.regmatch, tagp.tagname, (colnr_T) 0);
                            orgpat.regmatch.rm_ic = TRUE;
                        }
                    }
                    *tagp.tagname_end = cc;
                    match_re = TRUE;
                }
                if (match) {
                    int len = 0;
                    {
                        is_current = test_for_current (is_etag, tagp.fname, tagp.fname_end, tag_fname, buf_ffname);
                        is_static = FALSE;
                        if (!is_etag) {
                            if (tagp.tagname != lbuf)
                                is_static = TRUE;
                            else
                                is_static = test_for_static (&tagp);
                        }
                        if (is_static) {
                            if (is_current)
                                mtt = MT_ST_CUR;
                            else
                                mtt = MT_ST_OTH;
                        }
                        else {
                            if (is_current)
                                mtt = MT_GL_CUR;
                            else
                                mtt = MT_GL_OTH;
                        }
                        if (orgpat.regmatch.rm_ic && !match_no_ic)
                            mtt += MT_IC_OFF;
                        if (match_re)
                            mtt += MT_RE_OFF;
                    }
                    if (help_only) {

                        # define ML_EXTRA 3
                        *tagp.tagname_end = NUL;
                        len = (int) (tagp.tagname_end - tagp.tagname);
                        mfp = (char_u *) alloc ((int) sizeof (char_u) + len + 10 + ML_EXTRA + 1);
                        if (mfp != NULL) {
                            int heuristic;
                            p = mfp;
                            STRCPY (p, tagp.tagname);
                            p[len] = '@';
                            STRCPY (p + len + 1, help_lang);
                            heuristic = help_heuristic (tagp.tagname, match_re ? matchoff : 0, !match_no_ic);
                            heuristic += help_pri;
                            sprintf ((char *) p + len + 1 + ML_EXTRA, "%06d", heuristic);
                        }
                        *tagp.tagname_end = TAB;
                    }
                    else if (name_only) {
                        if (get_it_again) {
                            char_u *temp_end = tagp.command;
                            if (*temp_end == '/')
                                while (*temp_end && *temp_end != '\r' && *temp_end != '\n' && *temp_end != '$')
                                    temp_end++;
                            if (tagp.command + 2 < temp_end) {
                                len = (int) (temp_end - tagp.command - 2);
                                mfp = (char_u *) alloc (len +2);
                                if (mfp != NULL)
                                    vim_strncpy (mfp, tagp.command + 2, len);
                            }
                            else
                                mfp = NULL;
                            get_it_again = FALSE;
                        }
                        else {
                            len = (int) (tagp.tagname_end - tagp.tagname);
                            mfp = (char_u *) alloc ((int) sizeof (char_u) + len + 1);
                            if (mfp != NULL)
                                vim_strncpy (mfp, tagp.tagname, len);
                            if (State & INSERT)
                                get_it_again = p_sft;
                        }
                    }
                    else {

                        #define TAG_SEP 0x02
                        size_t tag_fname_len = STRLEN (tag_fname);
                        size_t ebuf_len = 0;
                        len = (int) tag_fname_len + (int) STRLEN (lbuf) + 3;
                        if (is_etag) {
                            ebuf_len = STRLEN (ebuf);
                            len += (int) ebuf_len + 1;
                        }
                        else
                            ++len;
                        mfp = (char_u *) alloc ((int) sizeof (char_u) + len + 1);
                        if (mfp != NULL) {
                            p = mfp;
                            p[0] = mtt + 1;
                            STRCPY (p + 1, tag_fname);
                            p[tag_fname_len + 1] = TAG_SEP;
                            s = p + 1 + tag_fname_len + 1;
                            if (is_etag) {
                                STRCPY (s, ebuf);
                                s[ebuf_len] = TAG_SEP;
                                s += ebuf_len + 1;
                            }
                            else
                                *s++ = TAG_SEP;
                            STRCPY (s, lbuf);
                        }
                    }
                    if (mfp != NULL) {
                        hashitem_T *hi;
                        hash = hash_hash (mfp);
                        hi = hash_lookup (&ht_match[mtt], mfp, hash);
                        if (HASHITEM_EMPTY (hi)) {
                            if (hash_add_item (&ht_match[mtt], hi, mfp, hash) == FAIL || ga_grow (&ga_match[mtt], 1) != OK) {
                                retval = OK;
                                stop_searching = TRUE;
                                break;
                            }
                            else {
                                ((char_u **) (ga_match[mtt].ga_data))[ga_match[mtt].ga_len++] = mfp;
                                ++match_count;
                            }
                        }
                        else
                            vim_free (mfp);
                    }
                }
            }
            if (line_error) {
                EMSG2 (_ ("E431: Format error in tags file \"%s\""), tag_fname);
                EMSGN (_ ("Before byte %ld"), (long) vim_ftell (fp));
                stop_searching = TRUE;
                line_error = FALSE;
            }
            fclose (fp);
            while (incstack_idx) {
                --incstack_idx;
                fclose (incstack [incstack_idx].fp);
                vim_free (incstack [incstack_idx].etag_fname);
            }
            tag_file_sorted = NUL;
            if (sort_error) {
                EMSG2 (_ ("E432: Tags file not sorted: %s"), tag_fname);
                sort_error = FALSE;
            }
            if (match_count >= mincount) {
                retval = OK;
                stop_searching = TRUE;
            }
            if (stop_searching)
                break;
        }
        tagname_free (& tn);
        if (stop_searching || linear || (!p_ic && noic) || orgpat.regmatch.rm_ic)
            break;
        orgpat.regmatch.rm_ic = TRUE;
    }
    if (!stop_searching) {
        if (!did_open && verbose)
            EMSG (_ ("E433: No tags file"));
        retval = OK;
    }
findtag_end :
    vim_free (lbuf);
    vim_regfree (orgpat.regmatch.regprog);
    vim_free (tag_fname);
    vim_free (ebuf);
    if (retval == FAIL)
        match_count = 0;
    if (match_count > 0)
        matches = (char_u **) lalloc ((long_u) (match_count * sizeof (char_u *)), TRUE);
    else
        matches = NULL;
    match_count = 0;
    for (mtt = 0; mtt < MT_COUNT; ++mtt) {
        for (i = 0; i < ga_match[mtt].ga_len; ++i) {
            mfp = ((char_u **) (ga_match[mtt].ga_data))[i];
            if (matches == NULL)
                vim_free (mfp);
            else {
                if (!name_only) {
                    *mfp = *mfp - 1;
                    for (p = mfp + 1; *p != NUL; ++p)
                        if (*p == TAG_SEP)
                            *p = NUL;
                }
                matches[match_count++] = (char_u *) mfp;
            }
        }
        ga_clear (& ga_match [mtt]);
        hash_clear (& ht_match [mtt]);
    }
    *matchesp = matches;
    *num_matches = match_count;
    curbuf->b_help = help_save;
    vim_free (saved_pat);
    p_ic = save_p_ic;
    return retval;
}

static void prepare_pats (pat_T *pats, int has_re) {
    pats->head = pats->pat;
    pats->headlen = pats->len;
    if (has_re) {
        if (pats->pat[0] == '^')
            pats->head = pats->pat + 1;
        else if (pats->pat[0] == '\\' && pats->pat[1] == '<')
            pats->head = pats->pat + 2;
        if (pats->head == pats->pat)
            pats->headlen = 0;
        else
            for (pats->headlen = 0; pats->head[pats->headlen] != NUL; ++pats->headlen)
                if (vim_strchr ((char_u *) (p_magic ? ".[~*\\$" : "\\$"), pats->head[pats->headlen]) != NULL)
                    break;
        if (p_tl != 0 && pats->headlen > p_tl)
            pats->headlen = p_tl;
    }
    if (has_re)
        pats->regmatch.regprog = vim_regcomp (pats->pat, p_magic ? RE_MAGIC : 0);
    else
        pats->regmatch.regprog = NULL;
}

int get_tagfname (tagname_T *tnp, int first, char_u *buf) {
    char_u *fname = NULL;
    char_u *r_ptr;
    if (first)
        vim_memset (tnp, 0, sizeof (tagname_T));
    if (curbuf->b_help) {
        if (first) {
            ga_clear_strings (& tag_fnames);
            ga_init2 (& tag_fnames, (int) sizeof (char_u *), 10);
            do_in_runtimepath ((char_u *) "doc/tags doc/tags-??", DIP_ALL, found_tagfile_cb, NULL);
        }
        if (tnp->tn_hf_idx >= tag_fnames.ga_len) {
            if (tnp->tn_hf_idx > tag_fnames.ga_len || *p_hf == NUL)
                return FAIL;
            ++tnp->tn_hf_idx;
            STRCPY (buf, p_hf);
            STRCPY (gettail (buf), "tags");
        }
        else
            vim_strncpy (buf, ((char_u **) (tag_fnames.ga_data))[tnp->tn_hf_idx++], MAXPATHL -1);
        return OK;
    }
    if (first) {
        tnp->tn_tags = vim_strsave ((*curbuf->b_p_tags != NUL) ? curbuf->b_p_tags : p_tags);
        if (tnp->tn_tags == NULL)
            return FAIL;
        tnp->tn_np = tnp->tn_tags;
    }
    for (;;) {
        if (tnp->tn_did_filefind_init) {
            fname = vim_findfile (tnp->tn_search_ctx);
            if (fname != NULL)
                break;
            tnp->tn_did_filefind_init = FALSE;
        }
        else {
            char_u *filename = NULL;
            if (*tnp->tn_np == NUL) {
                vim_findfile_cleanup (tnp -> tn_search_ctx);
                tnp->tn_search_ctx = NULL;
                return FAIL;
            }
            buf[0] = NUL;
            (void) copy_option_part (&tnp->tn_np, buf, MAXPATHL -1, " ,");
            r_ptr = vim_findfile_stopdir (buf);
            filename = gettail (buf);
            STRMOVE (filename + 1, filename);
            *filename++ = NUL;
            tnp->tn_search_ctx = vim_findfile_init (buf, filename, r_ptr, 100, FALSE, FINDFILE_FILE, tnp->tn_search_ctx, TRUE, curbuf->b_ffname);
            if (tnp->tn_search_ctx != NULL)
                tnp->tn_did_filefind_init = TRUE;
        }
    }
    STRCPY (buf, fname);
    vim_free (fname);
    return OK;
}

static void found_tagfile_cb (char_u *fname, void *cookie) {
    if (ga_grow (&tag_fnames, 1) == OK)
        ((char_u **) (tag_fnames.ga_data))[tag_fnames.ga_len++] = vim_strsave (fname);
}

static char_u *expand_tag_fname (char_u *fname, char_u *tag_fname, int expand) {
    char_u *p;
    char_u *retval;
    char_u *expanded_fname = NULL;
    expand_T xpc;
    if (expand && mch_has_wildcard (fname)) {
        ExpandInit (& xpc);
        xpc.xp_context = EXPAND_FILES;
        expanded_fname = ExpandOne (&xpc, (char_u *) fname, NULL, WILD_LIST_NOTFOUND | WILD_SILENT, WILD_EXPAND_FREE);
        if (expanded_fname != NULL)
            fname = expanded_fname;
    }
    if ((p_tr || curbuf->b_help) && !vim_isAbsName (fname) && (p = gettail (tag_fname)) != tag_fname) {
        retval = alloc (MAXPATHL);
        if (retval != NULL) {
            STRCPY (retval, tag_fname);
            vim_strncpy (retval + (p - tag_fname), fname, MAXPATHL - (p - tag_fname) - 1);
            simplify_filename (retval);
        }
    }
    else
        retval = vim_strsave (fname);
    vim_free (expanded_fname);
    return retval;
}

static int tag_strnicmp (char_u *s1, char_u *s2, size_t len) {
    int i;
    while (len > 0) {
        i = (int) TOUPPER_ASC (*s1) - (int) TOUPPER_ASC (*s2);
        if (i != 0)
            return i;
        if (*s1 == NUL)
            break;
        ++s1;
        ++s2;
        --len;
    }
    return 0;
}

static int parse_tag_line (char_u *lbuf, int is_etag, tagptrs_T *tagp) {
    char_u *p;
    char_u *p_7f;
    if (is_etag) {
        p_7f = vim_strchr (lbuf, 0x7f);
        if (p_7f == NULL) {
        etag_fail :
            if (vim_strchr (lbuf, '\n') == NULL) {
                if (p_verbose >= 5) {
                    verbose_enter ();
                    MSG (_ ("Ignoring long line in tags file"));
                    verbose_leave ();
                }
                tagp->command = lbuf;
                tagp->tagname = lbuf;
                tagp->tagname_end = lbuf;
                return OK;
            }
            return FAIL;
        }
        p = vim_strchr (p_7f, Ctrl_A);
        if (p == NULL)
            p = p_7f + 1;
        else
            ++p;
        if (!VIM_ISDIGIT (*p))
            goto etag_fail;
        tagp->command = p;
        if (p[-1] == Ctrl_A) {
            tagp->tagname = p_7f + 1;
            tagp->tagname_end = p - 1;
        }
        else {
            for (p = p_7f - 1; !vim_iswordc (*p); --p)
                if (p == lbuf)
                    goto etag_fail;
            tagp->tagname_end = p + 1;
            while (p >= lbuf && vim_iswordc (*p))
                --p;
            tagp->tagname = p + 1;
        }
    }
    else {
        tagp->tagname = lbuf;
        p = vim_strchr (lbuf, TAB);
        if (p == NULL)
            return FAIL;
        tagp->tagname_end = p;
        if (*p != NUL)
            ++p;
        tagp->fname = p;
        p = vim_strchr (p, TAB);
        if (p == NULL)
            return FAIL;
        tagp->fname_end = p;
        if (*p != NUL)
            ++p;
        if (*p == NUL)
            return FAIL;
        tagp->command = p;
    }
    return OK;
}

static int test_for_current (int is_etag, char_u *fname, char_u *fname_end, char_u *tag_fname, char_u *buf_ffname) {
    int c;
    int retval = FALSE;
    char_u *fullname;
    if (buf_ffname != NULL) {
        if (is_etag)
            c = 0;
        else {
            c = *fname_end;
            *fname_end = NUL;
        }
        fullname = expand_tag_fname (fname, tag_fname, TRUE);
        if (fullname != NULL) {
            retval = (fullpathcmp (fullname, buf_ffname, TRUE) & FPC_SAME);
            vim_free (fullname);
        }
        if (!is_etag)
            *fname_end = c;
    }
    return retval;
}

static int test_for_static (tagptrs_T *tagp) {
    char_u *p;
    int len;
    len = (int) (tagp->fname_end - tagp->fname);
    p = tagp->tagname + len;
    if (p < tagp->tagname_end && *p == ':' && fnamencmp (tagp->tagname, tagp->fname, len) == 0) {
        tagp->tagname = p + 1;
        return TRUE;
    }
    p = tagp->command;
    while ((p = vim_strchr (p, '\t')) != NULL) {
        ++p;
        if (STRNCMP (p, "file:", 5) == 0)
            return TRUE;
    }
    return FALSE;
}

void tagname_free (tagname_T *tnp) {
    vim_free (tnp -> tn_tags);
    vim_findfile_cleanup (tnp -> tn_search_ctx);
    tnp->tn_search_ctx = NULL;
    ga_clear_strings (& tag_fnames);
}

int expand_tags (int tagnames, char_u *pat, int *num_file, char_u ***file) {
    int i;
    int c;
    int tagnmflag;
    char_u tagnm [100];
    tagptrs_T t_p;
    int ret;
    if (tagnames)
        tagnmflag = TAG_NAMES;
    else
        tagnmflag = 0;
    if (pat[0] == '/')
        ret = find_tags (pat +1, num_file, file, TAG_REGEXP | tagnmflag | TAG_VERBOSE, TAG_MANY, curbuf->b_ffname);
    else
        ret = find_tags (pat, num_file, file, TAG_REGEXP | tagnmflag | TAG_VERBOSE | TAG_NOIC, TAG_MANY, curbuf->b_ffname);
    if (ret == OK && !tagnames) {
        for (i = 0; i < *num_file; i++) {
            parse_match ((* file) [i], & t_p);
            c = (int) (t_p.tagname_end - t_p.tagname);
            mch_memmove (tagnm, t_p.tagname, (size_t) c);
            tagnm[c++] = 0;
            tagnm[c++] = (t_p.tagkind != NULL && *t_p.tagkind) ? *t_p.tagkind : 'f';
            tagnm[c++] = 0;
            mch_memmove ((* file) [i] + c, t_p.fname, t_p.fname_end - t_p.fname);
            (*file)[i][c + (t_p.fname_end - t_p.fname)] = 0;
            mch_memmove ((* file) [i], tagnm, (size_t) c);
        }
    }
    return ret;
}

static int parse_match (char_u *lbuf, tagptrs_T *tagp) {
    int retval;
    char_u *p;
    char_u *pc, *pt;
    tagp->tag_fname = lbuf + 1;
    lbuf += STRLEN (tagp->tag_fname) + 2;
    if (*lbuf) {
        tagp->is_etag = TRUE;
        tagp->fname = lbuf;
        lbuf += STRLEN (lbuf);
        tagp->fname_end = lbuf++;
    }
    else {
        tagp->is_etag = FALSE;
        ++lbuf;
    }
    retval = parse_tag_line (lbuf, tagp->is_etag, tagp);
    tagp->tagkind = NULL;
    tagp->command_end = NULL;
    if (retval == OK) {
        p = tagp->command;
        if (find_extra (&p) == OK) {
            tagp->command_end = p;
            p += 2;
            if (*p++ == TAB)
                while (ASCII_ISALPHA (*p)) {
                    if (STRNCMP (p, "kind:", 5) == 0) {
                        tagp->tagkind = p + 5;
                        break;
                    }
                    pc = vim_strchr (p, ':');
                    pt = vim_strchr (p, '\t');
                    if (pc == NULL || (pt != NULL && pc > pt)) {
                        tagp->tagkind = p;
                        break;
                    }
                    if (pt == NULL)
                        break;
                    p = pt + 1;
                }
        }
        if (tagp->tagkind != NULL) {
            for (p = tagp->tagkind; *p && *p != '\t' && *p != '\r' && *p != '\n'; ++p)
                ;
            tagp->tagkind_end = p;
        }
    }
    return retval;
}

static int find_extra (char_u **pp) {
    char_u *str = *pp;
    for (;;) {
        if (VIM_ISDIGIT (*str))
            str = skipdigits (str);
        else if (*str == '/' || *str == '?') {
            str = skip_regexp (str +1, *str, FALSE, NULL);
            if (*str != **pp)
                str = NULL;
            else
                ++str;
        }
        else
            str = NULL;
        if (str == NULL || *str != ';' || !(VIM_ISDIGIT (str[1]) || str[1] == '/' || str[1] == '?'))
            break;
        ++str;
    }
    if (str != NULL && STRNCMP (str, ";\"", 2) == 0) {
        *pp = str;
        return OK;
    }
    return FAIL;
}

void tag_freematch (void) {
    VIM_CLEAR (tagmatchname);
}

int get_tags (list_T *list, char_u *pat, char_u *buf_fname) {
    int num_matches, i, ret;
    char_u **matches, *p;
    char_u *full_fname;
    dict_T *dict;
    tagptrs_T tp;
    long  is_static;
    ret = find_tags (pat, &num_matches, &matches, TAG_REGEXP | TAG_NOIC, (int) MAXCOL, buf_fname);
    if (ret == OK && num_matches > 0) {
        for (i = 0; i < num_matches; ++i) {
            parse_match (matches [i], & tp);
            is_static = test_for_static (&tp);
            if (STRNCMP (tp.tagname, "!_TAG_", 6) == 0)
                continue;
            if ((dict = dict_alloc ()) == NULL)
                ret = FAIL;
            if (list_append_dict (list, dict) == FAIL)
                ret = FAIL;
            full_fname = tag_full_fname (&tp);
            if (add_tag_field (dict, "name", tp.tagname, tp.tagname_end) == FAIL || add_tag_field (dict, "filename", full_fname, NULL) == FAIL || add_tag_field (dict, "cmd", tp.command, tp.command_end) == FAIL || add_tag_field (dict, "kind", tp.tagkind, tp.tagkind_end) == FAIL || dict_add_nr_str (dict, "static", is_static, NULL) == FAIL)
                ret = FAIL;
            vim_free (full_fname);
            if (tp.command_end != NULL) {
                for (p = tp.command_end + 3; *p != NUL && *p != '\n' && *p != '\r'; ++p) {
                    if (p == tp.tagkind || (p + 5 == tp.tagkind && STRNCMP (p, "kind:", 5) == 0))
                        p = tp.tagkind_end - 1;
                    else if (STRNCMP (p, "file:", 5) == 0)
                        p += 4;
                    else if (!VIM_ISWHITE (*p)) {
                        char_u *s, *n;
                        int len;
                        n = p;
                        while (*p != NUL && *p >= ' ' && *p < 127 && *p != ':')
                            ++p;
                        len = (int) (p - n);
                        if (*p == ':' && len > 0) {
                            s = ++p;
                            while (*p != NUL && *p >= ' ')
                                ++p;
                            n[len] = NUL;
                            if (add_tag_field (dict, (char *) n, s, p) == FAIL)
                                ret = FAIL;
                            n[len] = ':';
                        }
                        else
                            while (*p != NUL && *p >= ' ')
                                ++p;
                        if (*p == NUL)
                            break;
                    }
                }
            }
            vim_free (matches [i]);
        }
        vim_free (matches);
    }
    return ret;
}

static char_u *tag_full_fname (tagptrs_T *tagp) {
    char_u *fullname;
    int c;
    if (tagp->is_etag)
        c = 0;
    else {
        c = *tagp->fname_end;
        *tagp->fname_end = NUL;
    }
    fullname = expand_tag_fname (tagp->fname, tagp->tag_fname, FALSE);
    if (!tagp->is_etag)
        *tagp->fname_end = c;
    return fullname;
}

static int add_tag_field (dict_T *dict, char *field_name, char_u *start, char_u *end) {
    char_u *buf;
    int len = 0;
    int retval;
    if (dict_find (dict, (char_u *) field_name, -1) != NULL) {
        if (p_verbose > 0) {
            verbose_enter ();
            smsg ((char_u *) _ ("Duplicate field name: %s"), field_name);
            verbose_leave ();
        }
        return FAIL;
    }
    buf = alloc (MAXPATHL);
    if (buf == NULL)
        return FAIL;
    if (start != NULL) {
        if (end == NULL) {
            end = start + STRLEN (start);
            while (end > start && (end[-1] == '\r' || end[-1] == '\n'))
                --end;
        }
        len = (int) (end - start);
        if (len > MAXPATHL - 1)
            len = MAXPATHL - 1;
        vim_strncpy (buf, start, len);
    }
    buf[len] = NUL;
    retval = dict_add_nr_str (dict, field_name, 0L, buf);
    vim_free (buf);
    return retval;
}

int do_tag (char_u *tag, int type, int count, int forceit, int verbose) {
    taggy_T *tagstack = curwin->w_tagstack;
    int tagstackidx = curwin->w_tagstackidx;
    int tagstacklen = curwin->w_tagstacklen;
    int cur_match = 0;
    int cur_fnum = curbuf->b_fnum;
    int oldtagstackidx = tagstackidx;
    int prevtagstackidx = tagstackidx;
    int prev_num_matches;
    int new_tag = FALSE;
    int other_name;
    int i, j, k;
    int idx;
    int ic;
    char_u *p;
    char_u *name;
    int no_regexp = FALSE;
    int error_cur_match = 0;
    char_u *command_end;
    int save_pos = FALSE;
    fmark_T saved_fmark;
    int taglen;
    tagptrs_T tagp, tagp2;
    int new_num_matches;
    char_u **new_matches;
    int attr;
    int use_tagstack;
    int skip_msg = FALSE;
    char_u *buf_ffname = curbuf->b_ffname;
    static int num_matches = 0;
    static int max_num_matches = 0;
    static char_u **matches = NULL;
    static int flags;
    if (type == DT_HELP) {
        type = DT_TAG;
        no_regexp = TRUE;
    }
    prev_num_matches = num_matches;
    free_string_option (nofile_fname);
    nofile_fname = NULL;
    CLEAR_POS (& saved_fmark.mark);
    saved_fmark.fnum = 0;
    if ((!p_tgst && *tag != NUL)) {
        use_tagstack = FALSE;
        new_tag = TRUE;
        if (g_do_tagpreview != 0) {
            vim_free (ptag_entry.tagname);
            if ((ptag_entry.tagname = vim_strsave (tag)) == NULL)
                goto end_do_tag;
        }
    }
    else {
        if (g_do_tagpreview != 0)
            use_tagstack = FALSE;
        else
            use_tagstack = TRUE;
        if (*tag != NUL && (type == DT_TAG || type == DT_SELECT || type == DT_JUMP || type == DT_LTAG)) {
            if (g_do_tagpreview != 0) {
                if (ptag_entry.tagname != NULL && STRCMP (ptag_entry.tagname, tag) == 0) {
                    cur_match = ptag_entry.cur_match;
                    cur_fnum = ptag_entry.cur_fnum;
                }
                else {
                    vim_free (ptag_entry.tagname);
                    if ((ptag_entry.tagname = vim_strsave (tag)) == NULL)
                        goto end_do_tag;
                }
            }
            else {
                while (tagstackidx < tagstacklen)
                    vim_free (tagstack[--tagstacklen].tagname);
                if (++tagstacklen > TAGSTACKSIZE) {
                    tagstacklen = TAGSTACKSIZE;
                    vim_free (tagstack [0].tagname);
                    for (i = 1; i < tagstacklen; ++i)
                        tagstack[i - 1] = tagstack[i];
                    --tagstackidx;
                }
                if ((tagstack[tagstackidx].tagname = vim_strsave (tag)) == NULL) {
                    curwin->w_tagstacklen = tagstacklen - 1;
                    goto end_do_tag;
                }
                curwin->w_tagstacklen = tagstacklen;
                save_pos = TRUE;
            }
            new_tag = TRUE;
        }
        else {
            if (g_do_tagpreview != 0 ? ptag_entry.tagname == NULL : tagstacklen == 0) {
                EMSG (_ (e_tagstack));
                goto end_do_tag;
            }
            if (type == DT_POP) {
                int old_KeyTyped = KeyTyped;
                if ((tagstackidx -= count) < 0) {
                    EMSG (_ (bottommsg));
                    if (tagstackidx + count == 0) {
                        tagstackidx = 0;
                        goto end_do_tag;
                    }
                    tagstackidx = 0;
                }
                else if (tagstackidx >= tagstacklen) {
                    EMSG (_ (topmsg));
                    goto end_do_tag;
                }
                saved_fmark = tagstack[tagstackidx].fmark;
                if (saved_fmark.fnum != curbuf->b_fnum) {
                    if (buflist_getfile (saved_fmark.fnum, saved_fmark.mark.lnum, GETF_SETMARK, forceit) == FAIL) {
                        tagstackidx = oldtagstackidx;
                        goto end_do_tag;
                    }
                    curwin->w_cursor.lnum = saved_fmark.mark.lnum;
                }
                else {
                    setpcmark ();
                    curwin->w_cursor.lnum = saved_fmark.mark.lnum;
                }
                curwin->w_cursor.col = saved_fmark.mark.col;
                curwin->w_set_curswant = TRUE;
                check_cursor ();
                if ((fdo_flags & FDO_TAG) && old_KeyTyped)
                    foldOpenCursor ();
                FreeWild (num_matches, matches);
                num_matches = 0;
                tag_freematch ();
                goto end_do_tag;
            }
            if (type == DT_TAG || type == DT_LTAG) {
                if (g_do_tagpreview != 0) {
                    cur_match = ptag_entry.cur_match;
                    cur_fnum = ptag_entry.cur_fnum;
                }
                else {
                    save_pos = TRUE;
                    if ((tagstackidx += count - 1) >= tagstacklen) {
                        tagstackidx = tagstacklen - 1;
                        EMSG (_ (topmsg));
                        save_pos = FALSE;
                    }
                    else if (tagstackidx < 0) {
                        EMSG (_ (bottommsg));
                        tagstackidx = 0;
                        goto end_do_tag;
                    }
                    cur_match = tagstack[tagstackidx].cur_match;
                    cur_fnum = tagstack[tagstackidx].cur_fnum;
                }
                new_tag = TRUE;
            }
            else {
                prevtagstackidx = tagstackidx;
                if (g_do_tagpreview != 0) {
                    cur_match = ptag_entry.cur_match;
                    cur_fnum = ptag_entry.cur_fnum;
                }
                else {
                    if (--tagstackidx < 0)
                        tagstackidx = 0;
                    cur_match = tagstack[tagstackidx].cur_match;
                    cur_fnum = tagstack[tagstackidx].cur_fnum;
                }
                switch (type) {
                case DT_FIRST :
                    cur_match = count - 1;
                    break;
                case DT_SELECT :
                case DT_JUMP :
                case DT_LAST :
                    cur_match = MAXCOL - 1;
                    break;
                case DT_NEXT :
                    cur_match += count;
                    break;
                case DT_PREV :
                    cur_match -= count;
                    break;
                }
                if (cur_match >= MAXCOL)
                    cur_match = MAXCOL - 1;
                else if (cur_match < 0) {
                    EMSG (_ ("E425: Cannot go before first matching tag"));
                    skip_msg = TRUE;
                    cur_match = 0;
                    cur_fnum = curbuf->b_fnum;
                }
            }
        }
        if (g_do_tagpreview != 0) {
            if (type != DT_SELECT && type != DT_JUMP) {
                ptag_entry.cur_match = cur_match;
                ptag_entry.cur_fnum = cur_fnum;
            }
        }
        else {
            saved_fmark = tagstack[tagstackidx].fmark;
            if (save_pos) {
                tagstack[tagstackidx].fmark.mark = curwin->w_cursor;
                tagstack[tagstackidx].fmark.fnum = curbuf->b_fnum;
            }
            curwin->w_tagstackidx = tagstackidx;
            if (type != DT_SELECT && type != DT_JUMP) {
                curwin->w_tagstack[tagstackidx].cur_match = cur_match;
                curwin->w_tagstack[tagstackidx].cur_fnum = cur_fnum;
            }
        }
    }
    if (cur_fnum != curbuf->b_fnum) {
        buf_T *buf = buflist_findnr (cur_fnum);
        if (buf != NULL)
            buf_ffname = buf->b_ffname;
    }
    for (;;) {
        if (use_tagstack)
            name = tagstack[tagstackidx].tagname;
        else if (g_do_tagpreview != 0)
            name = ptag_entry.tagname;
        else
            name = tag;
        other_name = (tagmatchname == NULL || STRCMP (tagmatchname, name) != 0);
        if (new_tag || (cur_match >= num_matches && max_num_matches != MAXCOL) || other_name) {
            if (other_name) {
                vim_free (tagmatchname);
                tagmatchname = vim_strsave (name);
            }
            if (type == DT_TAG || type == DT_SELECT || type == DT_JUMP || type == DT_LTAG)
                cur_match = MAXCOL - 1;
            max_num_matches = cur_match + 1;
            if (!no_regexp && *name == '/') {
                flags = TAG_REGEXP;
                ++name;
            }
            else
                flags = TAG_NOIC;
            if (verbose)
                flags |= TAG_VERBOSE;
            if (find_tags (name, &new_num_matches, &new_matches, flags, max_num_matches, buf_ffname) == OK && new_num_matches < max_num_matches)
                max_num_matches = MAXCOL;
            if (!new_tag && !other_name) {
                idx = 0;
                for (j = 0; j < num_matches; ++j) {
                    parse_match (matches [j], & tagp);
                    for (i = idx; i < new_num_matches; ++i) {
                        parse_match (new_matches [i], & tagp2);
                        if (STRCMP (tagp.tagname, tagp2.tagname) == 0) {
                            p = new_matches[i];
                            for (k = i; k > idx; --k)
                                new_matches[k] = new_matches[k - 1];
                            new_matches[idx++] = p;
                            break;
                        }
                    }
                }
            }
            FreeWild (num_matches, matches);
            num_matches = new_num_matches;
            matches = new_matches;
        }
        if (num_matches <= 0) {
            if (verbose)
                EMSG2 (_ ("E426: tag not found: %s"), name);
            g_do_tagpreview = 0;
        }
        else {
            int ask_for_selection = FALSE;
            if (type == DT_TAG)
                cur_match = count > 0 ? count - 1 : 0;
            else if (type == DT_SELECT || (type == DT_JUMP && num_matches > 1)) {
                parse_match (matches [0], & tagp);
                taglen = (int) (tagp.tagname_end - tagp.tagname + 2);
                if (taglen < 18)
                    taglen = 18;
                if (taglen > Columns - 25)
                    taglen = MAXCOL;
                if (msg_col == 0)
                    msg_didout = FALSE;
                msg_start ();
                MSG_PUTS_ATTR (_ ("  # pri kind tag"), HL_ATTR (HLF_T));
                msg_clr_eos ();
                taglen_advance (taglen);
                MSG_PUTS_ATTR (_ ("file\n"), HL_ATTR (HLF_T));
                for (i = 0; i < num_matches && !got_int; ++i) {
                    parse_match (matches [i], & tagp);
                    if (!new_tag && ((g_do_tagpreview != 0 && i == ptag_entry.cur_match) || (use_tagstack && i == tagstack[tagstackidx].cur_match)))
                        *IObuff = '>';
                    else
                        *IObuff = ' ';
                    vim_snprintf ((char *) IObuff + 1, IOSIZE - 1, "%2d %s ", i + 1, mt_names [matches [i] [0] & MT_MASK]);
                    msg_puts (IObuff);
                    if (tagp.tagkind != NULL)
                        msg_outtrans_len (tagp.tagkind, (int) (tagp.tagkind_end - tagp.tagkind));
                    msg_advance (13);
                    msg_outtrans_len_attr (tagp.tagname, (int) (tagp.tagname_end - tagp.tagname), HL_ATTR (HLF_T));
                    msg_putchar (' ');
                    taglen_advance (taglen);
                    p = tag_full_fname (&tagp);
                    if (p != NULL) {
                        msg_puts_long_attr (p, HL_ATTR (HLF_D));
                        vim_free (p);
                    }
                    if (msg_col > 0)
                        msg_putchar ('\n');
                    if (got_int)
                        break;
                    msg_advance (15);
                    command_end = tagp.command_end;
                    if (command_end != NULL) {
                        p = command_end + 3;
                        while (*p && *p != '\r' && *p != '\n') {
                            while (*p == TAB)
                                ++p;
                            if (STRNCMP (p, "file:", 5) == 0 && vim_isspace (p[5])) {
                                p += 5;
                                continue;
                            }
                            if (p == tagp.tagkind || (p + 5 == tagp.tagkind && STRNCMP (p, "kind:", 5) == 0)) {
                                p = tagp.tagkind_end;
                                continue;
                            }
                            attr = HL_ATTR (HLF_CM);
                            while (*p && *p != '\r' && *p != '\n') {
                                if (msg_col + ptr2cells (p) >= Columns) {
                                    msg_putchar ('\n');
                                    if (got_int)
                                        break;
                                    msg_advance (15);
                                }
                                p = msg_outtrans_one (p, attr);
                                if (*p == TAB) {
                                    msg_puts_attr ((char_u *) " ", attr);
                                    break;
                                }
                                if (*p == ':')
                                    attr = 0;
                            }
                        }
                        if (msg_col > 15) {
                            msg_putchar ('\n');
                            if (got_int)
                                break;
                            msg_advance (15);
                        }
                    }
                    else {
                        for (p = tagp.command; *p && *p != '\r' && *p != '\n'; ++p)
                            ;
                        command_end = p;
                    }
                    p = tagp.command;
                    if (*p == '/' || *p == '?') {
                        ++p;
                        if (*p == '^')
                            ++p;
                    }
                    while (p != command_end && vim_isspace (*p))
                        ++p;
                    while (p != command_end) {
                        if (msg_col + (*p == TAB ? 1 : ptr2cells (p)) > Columns)
                            msg_putchar ('\n');
                        if (got_int)
                            break;
                        msg_advance (15);
                        if (*p == '\\' && (*(p + 1) == *tagp.command || *(p + 1) == '\\'))
                            ++p;
                        if (*p == TAB) {
                            msg_putchar (' ');
                            ++p;
                        }
                        else
                            p = msg_outtrans_one (p, 0);
                        if (p == command_end - 2 && *p == '$' && *(p + 1) == *tagp.command)
                            break;
                        if (p == command_end - 1 && *p == *tagp.command && (*p == '/' || *p == '?'))
                            break;
                    }
                    if (msg_col)
                        msg_putchar ('\n');
                    ui_breakcheck ();
                }
                if (got_int)
                    got_int = FALSE;
                ask_for_selection = TRUE;
            }
            else if (type == DT_LTAG) {
                list_T *list;
                char_u tag_name [128 + 1];
                char_u *fname;
                char_u *cmd;
                fname = alloc (MAXPATHL +1);
                cmd = alloc (CMDBUFFSIZE +1);
                list = list_alloc ();
                if (list == NULL || fname == NULL || cmd == NULL) {
                    vim_free (cmd);
                    vim_free (fname);
                    if (list != NULL)
                        list_free (list);
                    goto end_do_tag;
                }
                for (i = 0; i < num_matches; ++i) {
                    int len, cmd_len;
                    long  lnum;
                    dict_T *dict;
                    parse_match (matches [i], & tagp);
                    len = (int) (tagp.tagname_end - tagp.tagname);
                    if (len > 128)
                        len = 128;
                    vim_strncpy (tag_name, tagp.tagname, len);
                    tag_name[len] = NUL;
                    p = tag_full_fname (&tagp);
                    if (p == NULL)
                        continue;
                    vim_strncpy (fname, p, MAXPATHL);
                    vim_free (p);
                    lnum = 0;
                    if (isdigit (*tagp.command))
                        lnum = atol ((char *) tagp.command);
                    else {
                        char_u *cmd_start, *cmd_end;
                        cmd_start = tagp.command;
                        cmd_end = tagp.command_end;
                        if (cmd_end == NULL) {
                            for (p = tagp.command; *p && *p != '\r' && *p != '\n'; ++p)
                                ;
                            cmd_end = p;
                        }
                        cmd_end--;
                        if (*cmd_start == '/' || *cmd_start == '?')
                            cmd_start++;
                        if (*cmd_end == '/' || *cmd_end == '?')
                            cmd_end--;
                        len = 0;
                        cmd[0] = NUL;
                        if (*cmd_start == '^') {
                            STRCPY (cmd, "^");
                            cmd_start++;
                            len++;
                        }
                        STRCAT (cmd, "\\V");
                        len += 2;
                        cmd_len = (int) (cmd_end - cmd_start + 1);
                        if (cmd_len > (CMDBUFFSIZE - 5))
                            cmd_len = CMDBUFFSIZE - 5;
                        STRNCAT (cmd, cmd_start, cmd_len);
                        len += cmd_len;
                        if (cmd[len - 1] == '$') {
                            cmd[len - 1] = '\\';
                            cmd[len] = '$';
                            len++;
                        }
                        cmd[len] = NUL;
                    }
                    if ((dict = dict_alloc ()) == NULL)
                        continue;
                    if (list_append_dict (list, dict) == FAIL) {
                        vim_free (dict);
                        continue;
                    }
                    dict_add_nr_str (dict, "text", 0L, tag_name);
                    dict_add_nr_str (dict, "filename", 0L, fname);
                    dict_add_nr_str (dict, "lnum", lnum, NULL);
                    if (lnum == 0)
                        dict_add_nr_str (dict, "pattern", 0L, cmd);
                }
                vim_snprintf ((char *) IObuff, IOSIZE, "ltag %s", tag);
                set_errorlist (curwin, list, ' ', IObuff, NULL);
                list_free (list);
                vim_free (fname);
                vim_free (cmd);
                cur_match = 0;
            }
            if (ask_for_selection == TRUE) {
                i = prompt_for_number (NULL);
                if (i <= 0 || i > num_matches || got_int) {
                    if (use_tagstack) {
                        tagstack[tagstackidx].fmark = saved_fmark;
                        tagstackidx = prevtagstackidx;
                    }
                    break;
                }
                cur_match = i - 1;
            }
            if (cur_match >= num_matches) {
                if ((type == DT_NEXT || type == DT_FIRST) && nofile_fname == NULL) {
                    if (num_matches == 1)
                        EMSG (_ ("E427: There is only one matching tag"));
                    else
                        EMSG (_ ("E428: Cannot go beyond last matching tag"));
                    skip_msg = TRUE;
                }
                cur_match = num_matches - 1;
            }
            if (use_tagstack) {
                tagstack[tagstackidx].cur_match = cur_match;
                tagstack[tagstackidx].cur_fnum = cur_fnum;
                ++tagstackidx;
            }
            else if (g_do_tagpreview != 0) {
                ptag_entry.cur_match = cur_match;
                ptag_entry.cur_fnum = cur_fnum;
            }
            if (nofile_fname != NULL && error_cur_match != cur_match)
                smsg ((char_u *) _ ("File \"%s\" does not exist"), nofile_fname);
            ic = (matches[cur_match][0] & MT_IC_OFF);
            if (type != DT_TAG && type != DT_SELECT && type != DT_JUMP && (num_matches > 1 || ic) && !skip_msg) {
                sprintf ((char *) IObuff, _ ("tag %d of %d%s"), cur_match + 1, num_matches, max_num_matches != MAXCOL ? _ (" or more") : "");
                if (ic)
                    STRCAT (IObuff, _ ("  Using tag with different case!"));
                if ((num_matches > prev_num_matches || new_tag) && num_matches > 1) {
                    if (ic)
                        msg_attr (IObuff, HL_ATTR (HLF_W));
                    else
                        msg (IObuff);
                    msg_scroll = TRUE;
                }
                else
                    give_warning (IObuff, ic);
                if (ic && !msg_scrolled && msg_silent == 0) {
                    out_flush ();
                    ui_delay (1000L, TRUE);
                }
            }
            vim_snprintf ((char *) IObuff, IOSIZE, ":ta %s\r", name);
            set_vim_var_string (VV_SWAPCOMMAND, IObuff, - 1);
            i = jumpto_tag (matches[cur_match], forceit, type != DT_CSCOPE);
            set_vim_var_string (VV_SWAPCOMMAND, NULL, - 1);
            if (i == NOTAGFILE) {
                if ((type == DT_PREV && cur_match > 0) || ((type == DT_TAG || type == DT_NEXT || type == DT_FIRST) && (max_num_matches != MAXCOL || cur_match < num_matches - 1))) {
                    error_cur_match = cur_match;
                    if (use_tagstack)
                        --tagstackidx;
                    if (type == DT_PREV)
                        --cur_match;
                    else {
                        type = DT_NEXT;
                        ++cur_match;
                    }
                    continue;
                }
                EMSG2 (_ ("E429: File \"%s\" does not exist"), nofile_fname);
            }
            else {
                if (use_tagstack && tagstackidx > curwin->w_tagstacklen)
                    tagstackidx = curwin->w_tagstackidx;
            }
        }
        break;
    }
end_do_tag :
    if (use_tagstack && tagstackidx <= curwin->w_tagstacklen)
        curwin->w_tagstackidx = tagstackidx;
    postponed_split = 0;
    g_do_tagpreview = 0;
    return FALSE;
}

static void taglen_advance (int l) {
    if (l == MAXCOL) {
        msg_putchar ('\n');
        msg_advance (24);
    }
    else
        msg_advance (13 + l);
}

static int jumpto_tag (char_u *lbuf_arg, int forceit, int keep_help) {
    int save_secure;
    int save_magic;
    int save_p_ws, save_p_scs, save_p_ic;
    linenr_T save_lnum;
    char_u *str;
    char_u *pbuf;
    char_u *pbuf_end;
    char_u *tofree_fname = NULL;
    char_u *fname;
    tagptrs_T tagp;
    int retval = FAIL;
    int getfile_result = GETFILE_UNUSED;
    int search_options;
    int save_no_hlsearch;
    win_T *curwin_save = NULL;
    char_u *full_fname = NULL;
    int old_KeyTyped = KeyTyped;
    size_t len;
    char_u *lbuf;
    len = matching_line_len (lbuf_arg) + 1;
    lbuf = alloc ((int) len);
    if (lbuf != NULL)
        mch_memmove (lbuf, lbuf_arg, len);
    pbuf = alloc (LSIZE);
    if (pbuf == NULL || lbuf == NULL || parse_match (lbuf, &tagp) == FAIL) {
        tagp.fname_end = NULL;
        goto erret;
    }
    *tagp.fname_end = NUL;
    fname = tagp.fname;
    str = tagp.command;
    for (pbuf_end = pbuf; *str && *str != '\n' && *str != '\r';) {
        if (tagp.is_etag && *str == ',')
            break;
        *pbuf_end++ = *str++;
    }
    *pbuf_end = NUL;
    if (!tagp.is_etag) {
        str = pbuf;
        if (find_extra (&str) == OK) {
            pbuf_end = str;
            *pbuf_end = NUL;
        }
    }
    fname = expand_tag_fname (fname, tagp.tag_fname, TRUE);
    if (fname == NULL)
        goto erret;
    tofree_fname = fname;
    if (mch_getperm (fname) < 0 && !has_autocmd (EVENT_BUFREADCMD, fname, NULL)) {
        retval = NOTAGFILE;
        vim_free (nofile_fname);
        nofile_fname = vim_strsave (fname);
        if (nofile_fname == NULL)
            nofile_fname = empty_option;
        goto erret;
    }
    ++RedrawingDisabled;
    need_mouse_correct = TRUE;
    if (g_do_tagpreview != 0) {
        postponed_split = 0;
        curwin_save = curwin;
        if (!curwin->w_p_pvw) {
            full_fname = FullName_save (fname, FALSE);
            fname = full_fname;
            prepare_tagpreview (TRUE);
        }
    }
    if (postponed_split && (swb_flags & (SWB_USEOPEN | SWB_USETAB))) {
        buf_T *existing_buf = buflist_findname_exp (fname);
        if (existing_buf != NULL) {
            win_T *wp = NULL;
            if (swb_flags & SWB_USEOPEN)
                wp = buf_jump_open_win (existing_buf);
            if (wp == NULL && (swb_flags & SWB_USETAB))
                wp = buf_jump_open_tab (existing_buf);
            if (wp != NULL)
                getfile_result = GETFILE_SAME_FILE;
        }
    }
    if (getfile_result == GETFILE_UNUSED && (postponed_split || cmdmod.tab != 0)) {
        if (win_split (postponed_split > 0 ? postponed_split : 0, postponed_split_flags) == FAIL) {
            --RedrawingDisabled;
            goto erret;
        }
        RESET_BINDING (curwin);
    }
    if (keep_help) {
        if (g_do_tagpreview != 0)
            keep_help_flag = bt_help (curwin_save->w_buffer);
        else
            keep_help_flag = curbuf->b_help;
    }
    if (getfile_result == GETFILE_UNUSED)
        getfile_result = getfile (0, fname, NULL, TRUE, (linenr_T) 0, forceit);
    keep_help_flag = FALSE;
    if (GETFILE_SUCCESS (getfile_result)) {
        curwin->w_set_curswant = TRUE;
        postponed_split = 0;
        save_secure = secure;
        secure = 1;
        save_magic = p_magic;
        p_magic = FALSE;
        save_no_hlsearch = no_hlsearch;
        if (vim_strchr (p_cpo, CPO_TAGPAT) != NULL)
            search_options = 0;
        else
            search_options = SEARCH_KEEP;
        str = pbuf;
        if (pbuf[0] == '/' || pbuf[0] == '?')
            str = skip_regexp (pbuf +1, pbuf[0], FALSE, NULL) + 1;
        if (str > pbuf_end - 1) {
            save_p_ws = p_ws;
            save_p_ic = p_ic;
            save_p_scs = p_scs;
            p_ws = TRUE;
            p_ic = FALSE;
            p_scs = FALSE;
            save_lnum = curwin->w_cursor.lnum;
            curwin->w_cursor.lnum = 0;
            if (do_search (NULL, pbuf[0], pbuf +1, (long ) 1, search_options, NULL, NULL))
                retval = OK;
            else {
                int found = 1;
                int cc;
                p_ic = TRUE;
                if (!do_search (NULL, pbuf[0], pbuf +1, (long ) 1, search_options, NULL, NULL)) {
                    found = 2;
                    (void) test_for_static (&tagp);
                    cc = *tagp.tagname_end;
                    *tagp.tagname_end = NUL;
                    sprintf ((char *) pbuf, "^%s\\s\\*(", tagp.tagname);
                    if (!do_search (NULL, '/', pbuf, (long ) 1, search_options, NULL, NULL)) {
                        sprintf ((char *) pbuf, "^\\[#a-zA-Z_]\\.\\*\\<%s\\s\\*(", tagp.tagname);
                        if (!do_search (NULL, '/', pbuf, (long ) 1, search_options, NULL, NULL))
                            found = 0;
                    }
                    *tagp.tagname_end = cc;
                }
                if (found == 0) {
                    EMSG (_ ("E434: Can't find tag pattern"));
                    curwin->w_cursor.lnum = save_lnum;
                }
                else {
                    if (found == 2 || !save_p_ic) {
                        MSG (_ ("E435: Couldn't find tag, just guessing!"));
                        if (!msg_scrolled && msg_silent == 0) {
                            out_flush ();
                            ui_delay (1000L, TRUE);
                        }
                    }
                    retval = OK;
                }
            }
            p_ws = save_p_ws;
            p_ic = save_p_ic;
            p_scs = save_p_scs;
            check_cursor ();
        }
        else {
            curwin->w_cursor.lnum = 1;
            do_cmdline_cmd (pbuf);
            retval = OK;
        }
        if (secure == 2)
            wait_return (TRUE);
        secure = save_secure;
        p_magic = save_magic;
        if (search_options) {
            SET_NO_HLSEARCH (save_no_hlsearch);
        }
        if (getfile_result == GETFILE_OPEN_OTHER)
            retval = OK;
        if (retval == OK) {
            if (curbuf->b_help)
                set_topline (curwin, curwin->w_cursor.lnum);
            if ((fdo_flags & FDO_TAG) && old_KeyTyped)
                foldOpenCursor ();
        }
        if (g_do_tagpreview != 0 && curwin != curwin_save && win_valid (curwin_save)) {
            validate_cursor ();
            redraw_later (VALID);
            win_enter (curwin_save, TRUE);
        }
        --RedrawingDisabled;
    }
    else {
        --RedrawingDisabled;
        if (postponed_split) {
            win_close (curwin, FALSE);
            postponed_split = 0;
        }
    }
erret :
    g_do_tagpreview = 0;
    vim_free (lbuf);
    vim_free (pbuf);
    vim_free (tofree_fname);
    vim_free (full_fname);
    return retval;
}

static size_t matching_line_len (char_u *lbuf) {
    char_u *p = lbuf + 1;
    p += STRLEN (p) + 1;
    p += STRLEN (p) + 1;
    return (p - lbuf) + STRLEN (p);
}

