
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
struct sb_line_S {
    int sb_cols;
    cellattr_T *sb_cells;
    cellattr_T sb_fill_attr;
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
struct terminal_S {
    term_T *tl_next;
    VTerm *tl_vterm;
    job_T *tl_job;
    buf_T *tl_buffer;
    int tl_vterm_size_changed;
    int tl_tty_fd;
    char_u *tl_tty_in;
    char_u *tl_tty_out;
    int tl_normal_mode;
    int tl_channel_closed;
    int tl_finish;
    char_u *tl_opencmd;
    char_u *tl_eof_chars;
    int tl_rows;
    int tl_cols;
    int tl_rows_fixed;
    int tl_cols_fixed;
    char_u *tl_title;
    char_u *tl_status_text;
    int tl_dirty_row_start;
    int tl_dirty_row_end;
    garray_T tl_scrollback;
    int tl_scrollback_scrolled;
    cellattr_T tl_default_color;
    VTermPos tl_cursor_pos;
    int tl_cursor_visible;
    int tl_cursor_blink;
    int tl_cursor_shape;
    char_u *tl_cursor_color;
    int tl_using_altscreen;
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
int grey_ramp [] = {0x08, 0x12, 0x1C, 0x26, 0x30, 0x3A, 0x44, 0x4E, 0x58, 0x62, 0x6C, 0x76, 0x80, 0x8A, 0x94, 0x9E, 0xA8, 0xB2, 0xBC, 0xC6, 0xD0, 0xDA, 0xE4, 0xEE};
EXTERN char_u *p_bg;
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
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
EXTERN char need_key_msg [] INIT (= N_ ("Need encryption key for \"%s\""));
EXTERN char_u no_lines_msg [] INIT (= N_ ("--No lines in buffer--"));
EXTERN struct msglist **msg_list INIT (= NULL);
EXTERN char_u *keep_msg INIT (= NULL);
EXTERN char_u e_prev_dir [] INIT (= N_ ("E459: Cannot go back to previous directory"));
EXTERN char_u e_noprevre [] INIT (= N_ ("E35: No previous regular expression"));
EXTERN char_u e_noprev [] INIT (= N_ ("E34: No previous command"));
EXTERN win_T *prevwin INIT (= NULL);
EXTERN tabpage_T *first_tabpage;
SPELL_EXTERN spelltab_T spelltab;
VTermColor ansi_table [16] = {{0, 0, 0, 1}, {224, 0, 0, 2}, {0, 224, 0, 3}, {224, 224, 0, 4}, {0, 0, 224, 5}, {224, 0, 224, 6}, {0, 224, 224, 7}, {224, 224, 224, 8}, {128, 128, 128, 9}, {255, 64, 64, 10}, {64, 255, 64, 11}, {255, 255, 64, 12}, {64, 64, 255, 13}, {255, 64, 255, 14}, {64, 255, 255, 15}, {255, 255, 255, 16},};
EXTERN char_u e_umark [] INIT (= N_ ("E78: Unknown mark"));
EXTERN char_u e_marknotset [] INIT (= N_ ("E20: Mark not set"));
EXTERN char_u *p_viminfofile;
EXTERN char_u *p_viminfo;
EXTERN char_u farsi_text_5 [];
EXTERN char_u farsi_text_3 [];
EXTERN char_u farsi_text_2 [];
EXTERN char_u farsi_text_1 [];
EXTERN char_u e_noinstext [] INIT (= N_ ("E29: No inserted text yet"));
EXTERN win_T *au_pending_free_win INIT (= NULL);
EXTERN char_u e_number_exp [] INIT (= N_ ("E39: Number expected"));
EXTERN char_u *p_titlestring;
EXTERN char *ignoredp;
EXTERN int ignored;
EXTERN FILE *redir_fd INIT (= NULL);
EXTERN int arrow_used;
EXTERN int mouse_row;
EXTERN int msg_row;
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
VTermScreenCallbacks screen_callbacks = {handle_damage, handle_moverect, handle_movecursor, handle_settermprop, NULL, handle_resize, handle_pushline, NULL};
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
int desired_cursor_blink = -1;
int last_set_cursor_blink = -1;
int desired_cursor_shape = -1;
int last_set_cursor_shape = -1;
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
int term_default_cterm_bg = -1;
int term_default_cterm_fg = -1;
int term_backspace_char = BS;
term_T *in_terminal_loop = NULL;
term_T *first_term = NULL;
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
int cube_value [] = {0x00, 0x5F, 0x87, 0xAF, 0xD7, 0xFF};
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
char_u *desired_cursor_color = (char_u *) "";
char_u *last_set_cursor_color = (char_u *) "";
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

int terminal_is_active () {
    return in_terminal_loop != NULL;
}

cursorentry_T *term_get_cursor_shape (guicolor_T *fg, guicolor_T *bg) {
    term_T *term = in_terminal_loop;
    static cursorentry_T entry;
    vim_memset (& entry, 0, sizeof (entry));
    entry.shape = entry.mshape = term->tl_cursor_shape == VTERM_PROP_CURSORSHAPE_UNDERLINE ? SHAPE_HOR : term->tl_cursor_shape == VTERM_PROP_CURSORSHAPE_BAR_LEFT ? SHAPE_VER : SHAPE_BLOCK;
    entry.percentage = 20;
    if (term->tl_cursor_blink) {
        entry.blinkwait = 700;
        entry.blinkon = 400;
        entry.blinkoff = 250;
    }
    *fg = gui.back_pixel;
    if (term->tl_cursor_color == NULL)
        *bg = gui.norm_pixel;
    else
        *bg = color_name2handle (term->tl_cursor_color);
    entry.name = "n";
    entry.used_for = SHAPE_CURSOR;
    return &entry;
}

void term_send_eof (channel_T *ch) {
    term_T *term;
    for (term = first_term; term != NULL; term = term->tl_next)
        if (term->tl_job == ch->ch_job) {
            if (term->tl_eof_chars != NULL) {
                channel_send (ch, PART_IN, term -> tl_eof_chars, (int) STRLEN (term -> tl_eof_chars), NULL);
                channel_send (ch, PART_IN, (char_u *) "\r", 1, NULL);
            }
        }
}

char_u *term_get_status_text (term_T *term) {
    if (term->tl_status_text == NULL) {
        char_u *txt;
        size_t len;
        if (term->tl_normal_mode) {
            if (term_job_running (term))
                txt = (char_u *) _ ("Terminal");
            else
                txt = (char_u *) _ ("Terminal-finished");
        }
        else if (term->tl_title != NULL)
            txt = term->tl_title;
        else if (term_none_open (term))
            txt = (char_u *) _ ("active");
        else if (term_job_running (term))
            txt = (char_u *) _ ("running");
        else
            txt = (char_u *) _ ("finished");
        len = 9 + STRLEN (term->tl_buffer->b_fname) + STRLEN (txt);
        term->tl_status_text = alloc ((int) len);
        if (term->tl_status_text != NULL)
            vim_snprintf ((char *) term->tl_status_text, len, "%s [%s]", term->tl_buffer->b_fname, txt);
    }
    return term->tl_status_text;
}

int term_job_running (term_T *term) {
    return term != NULL && term->tl_job != NULL && channel_is_open (term->tl_job->jv_channel) && (term->tl_job->jv_status == JOB_STARTED || term->tl_job->jv_channel->ch_keep_open);
}

int term_none_open (term_T *term) {
    return term != NULL && term->tl_job != NULL && channel_is_open (term->tl_job->jv_channel) && term->tl_job->jv_channel->ch_keep_open;
}

int set_ref_in_term (int copyID) {
    int abort = FALSE;
    term_T *term;
    typval_T tv;
    for (term = first_term; term != NULL; term = term->tl_next)
        if (term->tl_job != NULL) {
            tv.v_type = VAR_JOB;
            tv.vval.v_job = term->tl_job;
            abort = abort || set_ref_in_item (&tv, copyID, NULL, NULL);
        }
    return abort;
}

void free_terminal (buf_T *buf) {
    term_T *term = buf->b_term;
    term_T *tp;
    if (term == NULL)
        return;
    if (first_term == term)
        first_term = term->tl_next;
    else
        for (tp = first_term; tp->tl_next != NULL; tp = tp->tl_next)
            if (tp->tl_next == term) {
                tp->tl_next = term->tl_next;
                break;
            }
    if (term->tl_job != NULL) {
        if (term->tl_job->jv_status != JOB_ENDED && term->tl_job->jv_status != JOB_FINISHED && term->tl_job->jv_status != JOB_FAILED)
            job_stop (term->tl_job, NULL, "kill");
        job_unref (term -> tl_job);
    }
    free_scrollback (term);
    term_free_vterm (term);
    vim_free (term -> tl_title);
    vim_free (term -> tl_status_text);
    vim_free (term -> tl_opencmd);
    vim_free (term -> tl_eof_chars);
    if (desired_cursor_color == term->tl_cursor_color)
        desired_cursor_color = (char_u *) "";
    vim_free (term -> tl_cursor_color);
    vim_free (term);
    buf->b_term = NULL;
    if (in_terminal_loop == term)
        in_terminal_loop = NULL;
}

static void free_scrollback (term_T *term) {
    int i;
    for (i = 0; i < term->tl_scrollback.ga_len; ++i)
        vim_free (((sb_line_T *) term->tl_scrollback.ga_data + i)->sb_cells);
    ga_clear (& term -> tl_scrollback);
}

static void term_free_vterm (term_T *term) {
    if (term->tl_vterm != NULL)
        vterm_free (term->tl_vterm);
    term->tl_vterm = NULL;
}

int term_in_normal_mode (void) {
    term_T *term = curbuf->b_term;
    return term != NULL && term->tl_normal_mode;
}

int term_is_finished (buf_T *buf) {
    return buf->b_term != NULL && buf->b_term->tl_vterm == NULL;
}

int term_show_buffer (buf_T *buf) {
    term_T *term = buf->b_term;
    return term != NULL && (term->tl_vterm == NULL || term->tl_normal_mode);
}

int term_get_attr (buf_T *buf, linenr_T lnum, int col) {
    term_T *term = buf->b_term;
    sb_line_T *line;
    cellattr_T *cellattr;
    if (lnum > term->tl_scrollback.ga_len)
        cellattr = &term->tl_default_color;
    else {
        line = (sb_line_T *) term->tl_scrollback.ga_data + lnum - 1;
        if (col < 0 || col >= line->sb_cols)
            cellattr = &line->sb_fill_attr;
        else
            cellattr = line->sb_cells + col;
    }
    return cell2attr (cellattr->attrs, cellattr->fg, cellattr->bg);
}

static int cell2attr (VTermScreenCellAttrs cellattrs, VTermColor cellfg, VTermColor cellbg) {
    int attr = 0;
    if (cellattrs.bold)
        attr |= HL_BOLD;
    if (cellattrs.underline)
        attr |= HL_UNDERLINE;
    if (cellattrs.italic)
        attr |= HL_ITALIC;
    if (cellattrs.strike)
        attr |= HL_STRIKETHROUGH;
    if (cellattrs.reverse)
        attr |= HL_INVERSE;
    if (gui.in_use) {
        guicolor_T fg, bg;
        fg = gui_mch_get_rgb_color (cellfg.red, cellfg.green, cellfg.blue);
        bg = gui_mch_get_rgb_color (cellbg.red, cellbg.green, cellbg.blue);
        return get_gui_attr_idx (attr, fg, bg);
    }
    else if (p_tgc) {
        guicolor_T fg, bg;
        fg = gui_get_rgb_color_cmn (cellfg.red, cellfg.green, cellfg.blue);
        bg = gui_get_rgb_color_cmn (cellbg.red, cellbg.green, cellbg.blue);
        return get_tgc_attr_idx (attr, fg, bg);
    }
    else {
        int bold = MAYBE;
        int fg = color2index (&cellfg, TRUE, &bold);
        int bg = color2index (&cellbg, FALSE, &bold);
        if ((fg == 0 || bg == 0) && t_colors >= 16) {
            if (fg == 0 && term_default_cterm_fg >= 0)
                fg = term_default_cterm_fg + 1;
            if (bg == 0 && term_default_cterm_bg >= 0)
                bg = term_default_cterm_bg + 1;
        }
        if (bold == TRUE)
            attr |= HL_BOLD;
        return get_cterm_attr_idx (attr, fg, bg);
    }
    return 0;
}

static int color2index (VTermColor *color, int fg, int *boldp) {
    int red = color->red;
    int blue = color->blue;
    int green = color->green;
    if (color->ansi_index != VTERM_ANSI_INDEX_NONE) {
        if (t_colors >= 16)
            return color->ansi_index;
        switch (color->ansi_index) {
        case 0 :
            return 0;
        case 1 :
            return lookup_color (0, fg, boldp) + 1;
        case 2 :
            return lookup_color (4, fg, boldp) + 1;
        case 3 :
            return lookup_color (2, fg, boldp) + 1;
        case 4 :
            return lookup_color (6, fg, boldp) + 1;
        case 5 :
            return lookup_color (1, fg, boldp) + 1;
        case 6 :
            return lookup_color (5, fg, boldp) + 1;
        case 7 :
            return lookup_color (3, fg, boldp) + 1;
        case 8 :
            return lookup_color (8, fg, boldp) + 1;
        case 9 :
            return lookup_color (12, fg, boldp) + 1;
        case 10 :
            return lookup_color (20, fg, boldp) + 1;
        case 11 :
            return lookup_color (16, fg, boldp) + 1;
        case 12 :
            return lookup_color (24, fg, boldp) + 1;
        case 13 :
            return lookup_color (14, fg, boldp) + 1;
        case 14 :
            return lookup_color (22, fg, boldp) + 1;
        case 15 :
            return lookup_color (18, fg, boldp) + 1;
        case 16 :
            return lookup_color (26, fg, boldp) + 1;
        }
    }
    if (t_colors >= 256) {
        if (red == blue && red == green) {
            static int cutoff [23] = {0x0D, 0x17, 0x21, 0x2B, 0x35, 0x3F, 0x49, 0x53, 0x5D, 0x67, 0x71, 0x7B, 0x85, 0x8F, 0x99, 0xA3, 0xAD, 0xB7, 0xC1, 0xCB, 0xD5, 0xDF, 0xE9};
            int i;
            if (red < 5)
                return 17;
            if (red > 245)
                return 232;
            for (i = 0; i < 23; ++i)
                if (red < cutoff[i])
                    return i + 233;
            return 256;
        }
        {
            static int cutoff [5] = {0x2F, 0x73, 0x9B, 0xC3, 0xEB};
            int ri, gi, bi;
            for (ri = 0; ri < 5; ++ri)
                if (red < cutoff[ri])
                    break;
            for (gi = 0; gi < 5; ++gi)
                if (green < cutoff[gi])
                    break;
            for (bi = 0; bi < 5; ++bi)
                if (blue < cutoff[bi])
                    break;
            return 17 + ri * 36 + gi * 6 + bi;
        }
    }
    return 0;
}

void term_change_in_curbuf (void) {
    term_T *term = curbuf->b_term;
    if (term_is_finished (curbuf) && term->tl_scrollback.ga_len > 0) {
        free_scrollback (term);
        redraw_buf_later (term -> tl_buffer, NOT_VALID);
        set_string_option_direct ((char_u *) "buftype", - 1, (char_u *) "", OPT_FREE | OPT_LOCAL, 0);
    }
}

int term_update_window (win_T *wp) {
    term_T *term = wp->w_buffer->b_term;
    VTerm *vterm;
    VTermScreen *screen;
    VTermState *state;
    VTermPos pos;
    if (term == NULL || term->tl_vterm == NULL || term->tl_normal_mode)
        return FAIL;
    vterm = term->tl_vterm;
    screen = vterm_obtain_screen (vterm);
    state = vterm_obtain_state (vterm);
    if (wp->w_redr_type >= SOME_VALID) {
        term->tl_dirty_row_start = 0;
        term->tl_dirty_row_end = MAX_ROW;
    }
    if ((!term->tl_rows_fixed && term->tl_rows != wp->w_height) || (!term->tl_cols_fixed && term->tl_cols != wp->w_width)) {
        int rows = term->tl_rows_fixed ? term->tl_rows : wp->w_height;
        int cols = term->tl_cols_fixed ? term->tl_cols : wp->w_width;
        win_T *twp;
        FOR_ALL_WINDOWS (twp) {
            if (twp->w_buffer == term->tl_buffer) {
                if (!term->tl_rows_fixed && rows > twp->w_height)
                    rows = twp->w_height;
                if (!term->tl_cols_fixed && cols > twp->w_width)
                    cols = twp->w_width;
            }
        }
        term->tl_vterm_size_changed = TRUE;
        vterm_set_size (vterm, rows, cols);
        ch_log (term -> tl_job -> jv_channel, "Resizing terminal to %d lines", rows);
        term_report_winsize (term, rows, cols);
    }
    vterm_state_get_cursorpos (state, & pos);
    position_cursor (wp, & pos);
    for (pos.row = term->tl_dirty_row_start; pos.row < term->tl_dirty_row_end && pos.row < wp->w_height; ++pos.row) {
        int off = screen_get_current_line_off ();
        int max_col = MIN (wp->w_width, term->tl_cols);
        if (pos.row < term->tl_rows) {
            for (pos.col = 0; pos.col < max_col;) {
                VTermScreenCell cell;
                int c;
                if (vterm_screen_get_cell (screen, pos, &cell) == 0)
                    vim_memset (&cell, 0, sizeof (cell));
                c = cell.chars[0];
                if (c == NUL) {
                    ScreenLines[off] = ' ';
                    if (enc_utf8)
                        ScreenLinesUC[off] = NUL;
                }
                else {
                    if (enc_utf8) {
                        int i;
                        for (i = 0; i < Screen_mco && i + 1 < VTERM_MAX_CHARS_PER_CELL; ++i) {
                            ScreenLinesC[i][off] = cell.chars[i + 1];
                            if (cell.chars[i + 1] == 0)
                                break;
                        }
                        if (c >= 0x80 || (Screen_mco > 0 && ScreenLinesC[0][off] != 0)) {
                            ScreenLines[off] = ' ';
                            ScreenLinesUC[off] = c;
                        }
                        else {
                            ScreenLines[off] = c;
                            ScreenLinesUC[off] = NUL;
                        }
                    }
                    else
                        ScreenLines[off] = c;
                }
                ScreenAttrs[off] = cell2attr (cell.attrs, cell.fg, cell.bg);
                ++pos.col;
                ++off;
                if (cell.width == 2) {
                    if (enc_utf8)
                        ScreenLinesUC[off] = NUL;
                    if (enc_utf8 || !has_mbyte)
                        ScreenLines[off] = NUL;
                    ++pos.col;
                    ++off;
                }
            }
        }
        else
            pos.col = 0;
        screen_line (wp -> w_winrow + pos.row + winbar_height (wp), wp -> w_wincol, pos.col, wp -> w_width, FALSE);
    }
    term->tl_dirty_row_start = MAX_ROW;
    term->tl_dirty_row_end = 0;
    return OK;
}

static void term_report_winsize (term_T *term, int rows, int cols) {
    if (term->tl_job != NULL && term->tl_job->jv_channel != NULL) {
        int fd = -1;
        int part;
        for (part = PART_OUT; part < PART_COUNT; ++part) {
            fd = term->tl_job->jv_channel->ch_part[part].ch_fd;
            if (isatty (fd))
                break;
        }
        if (part < PART_COUNT && mch_report_winsize (fd, rows, cols) == OK)
            mch_signal_job (term->tl_job, (char_u *) "winch");
    }
}

static void position_cursor (win_T *wp, VTermPos *pos) {
    wp->w_wrow = MIN (pos->row, MAX (0, wp->w_height - 1));
    wp->w_wcol = MIN (pos->col, MAX (0, wp->w_width - 1));
    wp->w_valid |= (VALID_WCOL | VALID_WROW);
}

void set_terminal_default_colors (int cterm_fg, int cterm_bg) {
    term_default_cterm_fg = cterm_fg - 1;
    term_default_cterm_bg = cterm_bg - 1;
}

int term_use_loop (void) {
    term_T *term = curbuf->b_term;
    return term != NULL && !term->tl_normal_mode && term->tl_vterm != NULL && term_job_running (term);
}

int terminal_loop (int blocking) {
    int c;
    int termkey = 0;
    int ret;
    int tty_fd = curbuf->b_term->tl_job->jv_channel->ch_part[get_tty_part (curbuf->b_term)].ch_fd;
    int restore_cursor;
    in_terminal_loop = curbuf->b_term;
    if (*curwin->w_p_tk != NUL)
        termkey = string_to_key (curwin->w_p_tk, TRUE);
    position_cursor (curwin, & curbuf -> b_term -> tl_cursor_pos);
    may_set_cursor_props (curbuf -> b_term);
    while (blocking || vpeekc () != NUL) {
        while (must_redraw != 0)
            if (update_screen (0) == FAIL)
                break;
        update_cursor (curbuf -> b_term, FALSE);
        restore_cursor = TRUE;
        c = term_vgetc ();
        if (!term_use_loop ()) {
            if (c != K_IGNORE)
                vungetc (c);
            break;
        }
        if (c == K_IGNORE)
            continue;
        if (isatty (tty_fd)) {
            ttyinfo_T info;
            if (get_tty_info (tty_fd, &info) == OK)
                term_backspace_char = info.backspace;
        }
        if (c == (termkey == 0 ? Ctrl_W : termkey) || c == Ctrl_BSL) {
            int prev_c = c;
            if (add_to_showcmd (c))
                out_flush ();
            c = term_vgetc ();
            clear_showcmd ();
            if (!term_use_loop ())
                break;
            if (prev_c == Ctrl_BSL) {
                if (c == Ctrl_N) {
                    term_enter_normal_mode ();
                    ret = FAIL;
                    goto theend;
                }
                send_keys_to_term (curbuf -> b_term, prev_c, TRUE);
            }
            else if (c == Ctrl_C) {
                mch_signal_job (curbuf -> b_term -> tl_job, (char_u *) "kill");
            }
            else if (termkey == 0 && c == '.') {
                c = Ctrl_W;
            }
            else if (c == 'N') {
                term_enter_normal_mode ();
                ret = FAIL;
                goto theend;
            }
            else if (c == '"') {
                term_paste_register (prev_c);
                continue;
            }
            else if (termkey == 0 || c != termkey) {
                stuffcharReadbuff (Ctrl_W);
                stuffcharReadbuff (c);
                ret = OK;
                goto theend;
            }
        }
        if (send_keys_to_term (curbuf->b_term, c, TRUE) != OK) {
            if (c == K_MOUSEMOVE)
                restore_cursor = FALSE;
            ret = OK;
            goto theend;
        }
    }
    ret = FAIL;
theend :
    in_terminal_loop = NULL;
    if (restore_cursor)
        prepare_restore_cursor_props ();
    return ret;
}

static ch_part_T get_tty_part (term_T *term) {
    ch_part_T parts [3] = {PART_IN, PART_OUT, PART_ERR};
    int i;
    for (i = 0; i < 3; ++i) {
        int fd = term->tl_job->jv_channel->ch_part[parts[i]].ch_fd;
        if (isatty (fd))
            return parts[i];
    }
    return PART_IN;
}

static void may_set_cursor_props (term_T *term) {
    if (gui.in_use)
        return;
    if (in_terminal_loop == term) {
        if (term->tl_cursor_color != NULL)
            desired_cursor_color = term->tl_cursor_color;
        else
            desired_cursor_color = (char_u *) "";
        desired_cursor_shape = term->tl_cursor_shape;
        desired_cursor_blink = term->tl_cursor_blink;
        may_output_cursor_props ();
    }
}

static void may_output_cursor_props (void) {
    if (STRCMP (last_set_cursor_color, desired_cursor_color) != 0 || last_set_cursor_shape != desired_cursor_shape || last_set_cursor_blink != desired_cursor_blink) {
        last_set_cursor_color = desired_cursor_color;
        last_set_cursor_shape = desired_cursor_shape;
        last_set_cursor_blink = desired_cursor_blink;
        term_cursor_color (desired_cursor_color);
        if (desired_cursor_shape == -1 || desired_cursor_blink == -1)
            ui_cursor_shape_forced (TRUE);
        else
            term_cursor_shape (desired_cursor_shape, desired_cursor_blink);
    }
}

static void update_cursor (term_T *term, int redraw) {
    if (term->tl_normal_mode)
        return;
    setcursor ();
    if (redraw) {
        if (term->tl_buffer == curbuf && term->tl_cursor_visible)
            cursor_on ();
        out_flush ();
        if (gui.in_use) {
            gui_update_cursor (FALSE, FALSE);
            gui_mch_flush ();
        }
    }
}

static int term_vgetc () {
    int c;
    int save_State = State;
    State = TERMINAL;
    got_int = FALSE;
    c = vgetc ();
    got_int = FALSE;
    State = save_State;
    return c;
}

static void term_enter_normal_mode (void) {
    term_T *term = curbuf->b_term;
    move_terminal_to_buffer (term);
    set_terminal_mode (term, TRUE);
    curwin->w_cursor.lnum = term->tl_scrollback_scrolled + term->tl_cursor_pos.row + 1;
    check_cursor ();
    coladvance (term -> tl_cursor_pos.col);
    curwin->w_topline = term->tl_scrollback_scrolled + 1;
}

static void move_terminal_to_buffer (term_T *term) {
    win_T *wp;
    int len;
    int lines_skipped = 0;
    VTermPos pos;
    VTermScreenCell cell;
    cellattr_T fill_attr, new_fill_attr;
    cellattr_T *p;
    VTermScreen *screen;
    if (term->tl_vterm == NULL)
        return;
    screen = vterm_obtain_screen (term->tl_vterm);
    fill_attr = new_fill_attr = term->tl_default_color;
    for (pos.row = 0; pos.row < term->tl_rows; ++pos.row) {
        len = 0;
        for (pos.col = 0; pos.col < term->tl_cols; ++pos.col)
            if (vterm_screen_get_cell (screen, pos, &cell) != 0 && cell.chars[0] != NUL) {
                len = pos.col + 1;
                new_fill_attr = term->tl_default_color;
            }
            else
                cell2cellattr (&cell, &new_fill_attr);
        if (len == 0 && equal_celattr (&new_fill_attr, &fill_attr))
            ++lines_skipped;
        else {
            while (lines_skipped > 0) {
                --lines_skipped;
                if (ga_grow (&term->tl_scrollback, 1) == OK) {
                    sb_line_T *line = (sb_line_T *) term->tl_scrollback.ga_data + term->tl_scrollback.ga_len;
                    line->sb_cols = 0;
                    line->sb_cells = NULL;
                    line->sb_fill_attr = fill_attr;
                    ++term->tl_scrollback.ga_len;
                    add_scrollback_line_to_buffer (term, (char_u *) "", 0);
                }
            }
            if (len == 0)
                p = NULL;
            else
                p = (cellattr_T *) alloc ((int) sizeof (cellattr_T) * len);
            if ((p != NULL || len == 0) && ga_grow (&term->tl_scrollback, 1) == OK) {
                garray_T ga;
                int width;
                sb_line_T *line = (sb_line_T *) term->tl_scrollback.ga_data + term->tl_scrollback.ga_len;
                ga_init2 (& ga, 1, 100);
                for (pos.col = 0; pos.col < len; pos.col += width) {
                    if (vterm_screen_get_cell (screen, pos, &cell) == 0) {
                        width = 1;
                        vim_memset (p + pos.col, 0, sizeof (cellattr_T));
                        if (ga_grow (&ga, 1) == OK)
                            ga.ga_len += utf_char2bytes (' ', (char_u *) ga.ga_data + ga.ga_len);
                    }
                    else {
                        width = cell.width;
                        cell2cellattr (& cell, & p [pos.col]);
                        if (ga_grow (&ga, MB_MAXBYTES) == OK) {
                            int i;
                            int c;
                            for (i = 0; (c = cell.chars[i]) > 0 || i == 0; ++i)
                                ga.ga_len += utf_char2bytes (c == NUL ? ' ' : c, (char_u *) ga.ga_data + ga.ga_len);
                        }
                    }
                }
                line->sb_cols = len;
                line->sb_cells = p;
                line->sb_fill_attr = new_fill_attr;
                fill_attr = new_fill_attr;
                ++term->tl_scrollback.ga_len;
                if (ga_grow (&ga, 1) == FAIL)
                    add_scrollback_line_to_buffer (term, (char_u *) "", 0);
                else {
                    *((char_u *) ga.ga_data + ga.ga_len) = NUL;
                    add_scrollback_line_to_buffer (term, ga.ga_data, ga.ga_len);
                }
                ga_clear (& ga);
            }
            else
                vim_free (p);
        }
    }
    vterm_state_get_default_colors (vterm_obtain_state (term -> tl_vterm), & term -> tl_default_color.fg, & term -> tl_default_color.bg);
    FOR_ALL_WINDOWS (wp) {
        if (wp->w_buffer == term->tl_buffer) {
            wp->w_cursor.lnum = term->tl_buffer->b_ml.ml_line_count;
            wp->w_cursor.col = 0;
            wp->w_valid = 0;
            if (wp->w_cursor.lnum >= wp->w_height) {
                linenr_T min_topline = wp->w_cursor.lnum - wp->w_height + 1;
                if (wp->w_topline < min_topline)
                    wp->w_topline = min_topline;
            }
            redraw_win_later (wp, NOT_VALID);
        }
    }
}

static void cell2cellattr (const VTermScreenCell *cell, cellattr_T *attr) {
    attr->width = cell->width;
    attr->attrs = cell->attrs;
    attr->fg = cell->fg;
    attr->bg = cell->bg;
}

static int equal_celattr (cellattr_T *a, cellattr_T *b) {
    return a->fg.red == b->fg.red && a->fg.green == b->fg.green && a->fg.blue == b->fg.blue && a->bg.red == b->bg.red && a->bg.green == b->bg.green && a->bg.blue == b->bg.blue;
}

static void add_scrollback_line_to_buffer (term_T *term, char_u *text, int len) {
    buf_T *buf = term->tl_buffer;
    int empty = (buf->b_ml.ml_flags & ML_EMPTY);
    linenr_T lnum = buf->b_ml.ml_line_count;
    ml_append_buf (term -> tl_buffer, lnum, text, len + 1, FALSE);
    if (empty) {
        curbuf = buf;
        ml_delete (1, FALSE);
        curbuf = curwin->w_buffer;
    }
}

static void set_terminal_mode (term_T *term, int normal_mode) {
    term->tl_normal_mode = normal_mode;
    VIM_CLEAR (term -> tl_status_text);
    if (term->tl_buffer == curbuf)
        maketitle ();
}

int send_keys_to_term (term_T *term, int c, int typed) {
    char msg [KEY_BUF_LEN];
    size_t len;
    static int mouse_was_outside = FALSE;
    int dragging_outside = FALSE;
    switch (c) {
    case NUL :
    case K_ZERO :
        if (typed)
            stuffcharReadbuff (c);
        return FAIL;
    case K_IGNORE :
        return FAIL;
    case K_LEFTDRAG :
    case K_MIDDLEDRAG :
    case K_RIGHTDRAG :
    case K_X1DRAG :
    case K_X2DRAG :
        dragging_outside = mouse_was_outside;
    case K_LEFTMOUSE :
    case K_LEFTMOUSE_NM :
    case K_LEFTRELEASE :
    case K_LEFTRELEASE_NM :
    case K_MOUSEMOVE :
    case K_MIDDLEMOUSE :
    case K_MIDDLERELEASE :
    case K_RIGHTMOUSE :
    case K_RIGHTRELEASE :
    case K_X1MOUSE :
    case K_X1RELEASE :
    case K_X2MOUSE :
    case K_X2RELEASE :
    case K_MOUSEUP :
    case K_MOUSEDOWN :
    case K_MOUSELEFT :
    case K_MOUSERIGHT :
        if (mouse_row < W_WINROW (curwin) || mouse_row >= (W_WINROW (curwin) + curwin->w_height) || mouse_col < curwin->w_wincol || mouse_col >= W_ENDCOL (curwin) || dragging_outside) {
            if (typed) {
                stuffcharReadbuff (c);
                mouse_was_outside = TRUE;
            }
            return FAIL;
        }
    }
    if (typed)
        mouse_was_outside = FALSE;
    len = term_convert_key (term, c, msg);
    if (len > 0)
        channel_send (term->tl_job->jv_channel, get_tty_part (term), (char_u *) msg, (int) len, NULL);
    return OK;
}

static int term_convert_key (term_T *term, int c, char *buf) {
    VTerm *vterm = term->tl_vterm;
    VTermKey key = VTERM_KEY_NONE;
    VTermModifier mod = VTERM_MOD_NONE;
    int other = FALSE;
    switch (c) {
    case K_BS :
        c = term_backspace_char;
        break;
    case ESC :
        key = VTERM_KEY_ESCAPE;
        break;
    case K_DEL :
        key = VTERM_KEY_DEL;
        break;
    case K_DOWN :
        key = VTERM_KEY_DOWN;
        break;
    case K_S_DOWN :
        mod = VTERM_MOD_SHIFT;
        key = VTERM_KEY_DOWN;
        break;
    case K_END :
        key = VTERM_KEY_END;
        break;
    case K_S_END :
        mod = VTERM_MOD_SHIFT;
        key = VTERM_KEY_END;
        break;
    case K_C_END :
        mod = VTERM_MOD_CTRL;
        key = VTERM_KEY_END;
        break;
    case K_F10 :
        key = VTERM_KEY_FUNCTION (10);
        break;
    case K_F11 :
        key = VTERM_KEY_FUNCTION (11);
        break;
    case K_F12 :
        key = VTERM_KEY_FUNCTION (12);
        break;
    case K_F1 :
        key = VTERM_KEY_FUNCTION (1);
        break;
    case K_F2 :
        key = VTERM_KEY_FUNCTION (2);
        break;
    case K_F3 :
        key = VTERM_KEY_FUNCTION (3);
        break;
    case K_F4 :
        key = VTERM_KEY_FUNCTION (4);
        break;
    case K_F5 :
        key = VTERM_KEY_FUNCTION (5);
        break;
    case K_F6 :
        key = VTERM_KEY_FUNCTION (6);
        break;
    case K_F7 :
        key = VTERM_KEY_FUNCTION (7);
        break;
    case K_F8 :
        key = VTERM_KEY_FUNCTION (8);
        break;
    case K_F9 :
        key = VTERM_KEY_FUNCTION (9);
        break;
    case K_HOME :
        key = VTERM_KEY_HOME;
        break;
    case K_S_HOME :
        mod = VTERM_MOD_SHIFT;
        key = VTERM_KEY_HOME;
        break;
    case K_C_HOME :
        mod = VTERM_MOD_CTRL;
        key = VTERM_KEY_HOME;
        break;
    case K_INS :
        key = VTERM_KEY_INS;
        break;
    case K_K0 :
        key = VTERM_KEY_KP_0;
        break;
    case K_K1 :
        key = VTERM_KEY_KP_1;
        break;
    case K_K2 :
        key = VTERM_KEY_KP_2;
        break;
    case K_K3 :
        key = VTERM_KEY_KP_3;
        break;
    case K_K4 :
        key = VTERM_KEY_KP_4;
        break;
    case K_K5 :
        key = VTERM_KEY_KP_5;
        break;
    case K_K6 :
        key = VTERM_KEY_KP_6;
        break;
    case K_K7 :
        key = VTERM_KEY_KP_7;
        break;
    case K_K8 :
        key = VTERM_KEY_KP_8;
        break;
    case K_K9 :
        key = VTERM_KEY_KP_9;
        break;
    case K_KDEL :
        key = VTERM_KEY_DEL;
        break;
    case K_KDIVIDE :
        key = VTERM_KEY_KP_DIVIDE;
        break;
    case K_KEND :
        key = VTERM_KEY_KP_1;
        break;
    case K_KENTER :
        key = VTERM_KEY_KP_ENTER;
        break;
    case K_KHOME :
        key = VTERM_KEY_KP_7;
        break;
    case K_KINS :
        key = VTERM_KEY_KP_0;
        break;
    case K_KMINUS :
        key = VTERM_KEY_KP_MINUS;
        break;
    case K_KMULTIPLY :
        key = VTERM_KEY_KP_MULT;
        break;
    case K_KPAGEDOWN :
        key = VTERM_KEY_KP_3;
        break;
    case K_KPAGEUP :
        key = VTERM_KEY_KP_9;
        break;
    case K_KPLUS :
        key = VTERM_KEY_KP_PLUS;
        break;
    case K_KPOINT :
        key = VTERM_KEY_KP_PERIOD;
        break;
    case K_LEFT :
        key = VTERM_KEY_LEFT;
        break;
    case K_S_LEFT :
        mod = VTERM_MOD_SHIFT;
        key = VTERM_KEY_LEFT;
        break;
    case K_C_LEFT :
        mod = VTERM_MOD_CTRL;
        key = VTERM_KEY_LEFT;
        break;
    case K_PAGEDOWN :
        key = VTERM_KEY_PAGEDOWN;
        break;
    case K_PAGEUP :
        key = VTERM_KEY_PAGEUP;
        break;
    case K_RIGHT :
        key = VTERM_KEY_RIGHT;
        break;
    case K_S_RIGHT :
        mod = VTERM_MOD_SHIFT;
        key = VTERM_KEY_RIGHT;
        break;
    case K_C_RIGHT :
        mod = VTERM_MOD_CTRL;
        key = VTERM_KEY_RIGHT;
        break;
    case K_UP :
        key = VTERM_KEY_UP;
        break;
    case K_S_UP :
        mod = VTERM_MOD_SHIFT;
        key = VTERM_KEY_UP;
        break;
    case TAB :
        key = VTERM_KEY_TAB;
        break;
    case K_MOUSEUP :
        other = term_send_mouse (vterm, 5, 1);
        break;
    case K_MOUSEDOWN :
        other = term_send_mouse (vterm, 4, 1);
        break;
    case K_MOUSELEFT :
        return 0;
    case K_MOUSERIGHT :
        return 0;
    case K_LEFTMOUSE :
    case K_LEFTMOUSE_NM :
        other = term_send_mouse (vterm, 1, 1);
        break;
    case K_LEFTDRAG :
        other = term_send_mouse (vterm, 1, 1);
        break;
    case K_LEFTRELEASE :
    case K_LEFTRELEASE_NM :
        other = term_send_mouse (vterm, 1, 0);
        break;
    case K_MOUSEMOVE :
        other = term_send_mouse (vterm, 0, 0);
        break;
    case K_MIDDLEMOUSE :
        other = term_send_mouse (vterm, 2, 1);
        break;
    case K_MIDDLEDRAG :
        other = term_send_mouse (vterm, 2, 1);
        break;
    case K_MIDDLERELEASE :
        other = term_send_mouse (vterm, 2, 0);
        break;
    case K_RIGHTMOUSE :
        other = term_send_mouse (vterm, 3, 1);
        break;
    case K_RIGHTDRAG :
        other = term_send_mouse (vterm, 3, 1);
        break;
    case K_RIGHTRELEASE :
        other = term_send_mouse (vterm, 3, 0);
        break;
    case K_X1MOUSE :
        return 0;
    case K_X1DRAG :
        return 0;
    case K_X1RELEASE :
        return 0;
    case K_X2MOUSE :
        return 0;
    case K_X2DRAG :
        return 0;
    case K_X2RELEASE :
        return 0;
    case K_IGNORE :
        return 0;
    case K_NOP :
        return 0;
    case K_UNDO :
        return 0;
    case K_HELP :
        return 0;
    case K_XF1 :
        key = VTERM_KEY_FUNCTION (1);
        break;
    case K_XF2 :
        key = VTERM_KEY_FUNCTION (2);
        break;
    case K_XF3 :
        key = VTERM_KEY_FUNCTION (3);
        break;
    case K_XF4 :
        key = VTERM_KEY_FUNCTION (4);
        break;
    case K_SELECT :
        return 0;
    case K_VER_SCROLLBAR :
        return 0;
    case K_HOR_SCROLLBAR :
        return 0;
    case K_F21 :
        key = VTERM_KEY_FUNCTION (21);
        break;
    case K_CURSORHOLD :
        return 0;
    case K_PS :
        vterm_keyboard_start_paste (vterm);
        other = TRUE;
        break;
    case K_PE :
        vterm_keyboard_end_paste (vterm);
        other = TRUE;
        break;
    }
    if (key != VTERM_KEY_NONE)
        vterm_keyboard_key (vterm, key, mod);
    else if (!other)
        vterm_keyboard_unichar (vterm, c, mod);
    return (int) vterm_output_read (vterm, buf, KEY_BUF_LEN);
}

static int term_send_mouse (VTerm *vterm, int button, int pressed) {
    VTermModifier mod = VTERM_MOD_NONE;
    vterm_mouse_move (vterm, mouse_row - W_WINROW (curwin), mouse_col - curwin -> w_wincol, mod);
    if (button != 0)
        vterm_mouse_button (vterm, button, pressed, mod);
    return TRUE;
}

static void term_paste_register (int prev_c) {
    int c;
    list_T *l;
    listitem_T *item;
    long  reglen = 0;
    int type;
    if (add_to_showcmd (prev_c))
        if (add_to_showcmd ('"'))
            out_flush ();
    c = term_vgetc ();
    clear_showcmd ();
    if (!term_use_loop ())
        return;
    if (c == '=' && get_expr_register () != '=')
        return;
    if (!term_use_loop ())
        return;
    l = (list_T *) get_reg_contents (c, GREG_LIST);
    if (l != NULL) {
        type = get_reg_type (c, &reglen);
        for (item = l->lv_first; item != NULL; item = item->li_next) {
            char_u *s = get_tv_string (&item->li_tv);
            channel_send (curbuf -> b_term -> tl_job -> jv_channel, PART_IN, s, (int) STRLEN (s), NULL);
            if (item->li_next != NULL || type == MLINE)
                channel_send (curbuf->b_term->tl_job->jv_channel, PART_IN, (char_u *) "\r", 1, NULL);
        }
        list_free (l);
    }
}

static void prepare_restore_cursor_props (void) {
    if (gui.in_use)
        return;
    desired_cursor_color = (char_u *) "";
    desired_cursor_shape = -1;
    desired_cursor_blink = -1;
    may_output_cursor_props ();
}

void write_to_term (buf_T *buffer, char_u *msg, channel_T *channel) {
    size_t len = STRLEN (msg);
    term_T *term = buffer->b_term;
    if (term->tl_vterm == NULL) {
        ch_log (channel, "NOT writing %d bytes to terminal", (int) len);
        return;
    }
    ch_log (channel, "writing %d bytes to terminal", (int) len);
    term_write_job_output (term, msg, len);
    if (!term->tl_normal_mode) {
        ch_log (term -> tl_job -> jv_channel, "updating screen");
        if (buffer == curbuf) {
            update_screen (0);
            update_cursor (term, TRUE);
            if (gui.in_use)
                gui_macvim_force_flush ();
        }
        else
            redraw_after_callback (TRUE);
    }
}

static void term_write_job_output (term_T *term, char_u *msg, size_t len) {
    VTerm *vterm = term->tl_vterm;
    size_t prevlen = vterm_output_get_buffer_current (vterm);
    vterm_input_write (vterm, (char *) msg, len);
    if (prevlen != vterm_output_get_buffer_current (vterm)) {
        char buf [KEY_BUF_LEN];
        size_t curlen = vterm_output_read (vterm, buf, KEY_BUF_LEN);
        if (curlen > 0)
            channel_send (term->tl_job->jv_channel, get_tty_part (term), (char_u *) buf, (int) curlen, NULL);
    }
    vterm_screen_flush_damage (vterm_obtain_screen (vterm));
}

void term_channel_closed (channel_T *ch) {
    term_T *term;
    int did_one = FALSE;
    for (term = first_term; term != NULL; term = term->tl_next)
        if (term->tl_job == ch->ch_job) {
            term->tl_channel_closed = TRUE;
            did_one = TRUE;
            VIM_CLEAR (term -> tl_title);
            VIM_CLEAR (term -> tl_status_text);
            if (!term->tl_normal_mode) {
                int fnum = term->tl_buffer->b_fnum;
                cleanup_vterm (term);
                if (term->tl_finish == 'c') {
                    aco_save_T aco;
                    ch_log (NULL, "terminal job finished, closing window");
                    aucmd_prepbuf (& aco, term -> tl_buffer);
                    do_bufdel (DOBUF_WIPE, (char_u *) "", 1, fnum, fnum, FALSE);
                    aucmd_restbuf (& aco);
                    break;
                }
                if (term->tl_finish == 'o' && term->tl_buffer->b_nwindows == 0) {
                    char buf [50];
                    ch_log (NULL, "terminal job finished, opening window");
                    vim_snprintf (buf, sizeof (buf), term -> tl_opencmd == NULL ? "botright sbuf %d" : (char *) term -> tl_opencmd, fnum);
                    do_cmdline_cmd ((char_u *) buf);
                }
                else
                    ch_log (NULL, "terminal job finished");
            }
            redraw_buf_and_status_later (term -> tl_buffer, NOT_VALID);
        }
    if (did_one) {
        redraw_statuslines ();
        ins_char_typebuf (K_IGNORE);
        typebuf_was_filled = TRUE;
        term = curbuf->b_term;
        if (term != NULL) {
            if (term->tl_job == ch->ch_job)
                maketitle ();
            update_cursor (term, term -> tl_cursor_visible);
        }
    }
}

static void cleanup_vterm (term_T *term) {
    if (term->tl_finish != 'c')
        move_terminal_to_buffer (term);
    term_free_vterm (term);
    set_terminal_mode (term, FALSE);
}

static int handle_damage (VTermRect rect, void *user) {
    term_T *term = (term_T *) user;
    term->tl_dirty_row_start = MIN (term->tl_dirty_row_start, rect.start_row);
    term->tl_dirty_row_end = MAX (term->tl_dirty_row_end, rect.end_row);
    redraw_buf_later (term -> tl_buffer, NOT_VALID);
    return 1;
}

static int handle_moverect (VTermRect dest, VTermRect src, void *user) {
    term_T *term = (term_T *) user;
    if (dest.start_col == src.start_col && dest.end_col == src.end_col && dest.start_row < src.start_row) {
        win_T *wp;
        VTermColor fg, bg;
        VTermScreenCellAttrs attr;
        int clear_attr;
        vterm_state_get_default_colors (vterm_obtain_state (term -> tl_vterm), & fg, & bg);
        vim_memset (& attr, 0, sizeof (attr));
        clear_attr = cell2attr (attr, fg, bg);
        FOR_ALL_WINDOWS (wp) {
            if (wp->w_buffer == term->tl_buffer)
                win_del_lines (wp, dest.start_row, src.start_row - dest.start_row, FALSE, FALSE, clear_attr);
        }
    }
    term->tl_dirty_row_start = MIN (term->tl_dirty_row_start, dest.start_row);
    term->tl_dirty_row_end = MIN (term->tl_dirty_row_end, dest.end_row);
    redraw_buf_later (term -> tl_buffer, NOT_VALID);
    return 1;
}

static int handle_movecursor (VTermPos pos, VTermPos oldpos, int visible, void *user) {
    term_T *term = (term_T *) user;
    win_T *wp;
    term->tl_cursor_pos = pos;
    term->tl_cursor_visible = visible;
    FOR_ALL_WINDOWS (wp) {
        if (wp->w_buffer == term->tl_buffer)
            position_cursor (wp, &pos);
    }
    if (term->tl_buffer == curbuf && !term->tl_normal_mode) {
        may_toggle_cursor (term);
        update_cursor (term, term -> tl_cursor_visible);
    }
    return 1;
}

static void may_toggle_cursor (term_T *term) {
    if (in_terminal_loop == term) {
        if (term->tl_cursor_visible)
            cursor_on ();
        else
            cursor_off ();
    }
}

static int handle_settermprop (VTermProp prop, VTermValue *value, void *user) {
    term_T *term = (term_T *) user;
    switch (prop) {
    case VTERM_PROP_TITLE :
        vim_free (term->tl_title);
        if (*skipwhite ((char_u *) value->string) == NUL)
            term->tl_title = NULL;
        else
            term->tl_title = vim_strsave ((char_u *) value->string);
        VIM_CLEAR (term -> tl_status_text);
        if (term == curbuf->b_term)
            maketitle ();
        break;
    case VTERM_PROP_CURSORVISIBLE :
        term->tl_cursor_visible = value->boolean;
        may_toggle_cursor (term);
        out_flush ();
        break;
    case VTERM_PROP_CURSORBLINK :
        term->tl_cursor_blink = value->boolean;
        may_set_cursor_props (term);
        break;
    case VTERM_PROP_CURSORSHAPE :
        term->tl_cursor_shape = value->number;
        may_set_cursor_props (term);
        break;
    case VTERM_PROP_CURSORCOLOR :
        if (desired_cursor_color == term->tl_cursor_color)
            desired_cursor_color = (char_u *) "";
        vim_free (term -> tl_cursor_color);
        if (*value->string == NUL)
            term->tl_cursor_color = NULL;
        else
            term->tl_cursor_color = vim_strsave ((char_u *) value->string);
        may_set_cursor_props (term);
        break;
    case VTERM_PROP_ALTSCREEN :
        term->tl_using_altscreen = value->boolean;
        break;
    default :
        break;
    }
    return 1;
}

static int handle_resize (int rows, int cols, void *user) {
    term_T *term = (term_T *) user;
    win_T *wp;
    term->tl_rows = rows;
    term->tl_cols = cols;
    if (term->tl_vterm_size_changed)
        term->tl_vterm_size_changed = FALSE;
    else {
        FOR_ALL_WINDOWS (wp) {
            if (wp->w_buffer == term->tl_buffer) {
                win_setheight_win (rows, wp);
                win_setwidth_win (cols, wp);
            }
        }
        redraw_buf_later (term -> tl_buffer, NOT_VALID);
    }
    return 1;
}

static int handle_pushline (int cols, const VTermScreenCell *cells, void *user) {
    term_T *term = (term_T *) user;
    if (ga_grow (&term->tl_scrollback, 1) == OK) {
        cellattr_T *p = NULL;
        int len = 0;
        int i;
        int c;
        int col;
        sb_line_T *line;
        garray_T ga;
        cellattr_T fill_attr = term->tl_default_color;
        for (i = 0; i < cols; ++i)
            if (cells[i].chars[0] != 0)
                len = i + 1;
            else
                cell2cellattr (&cells[i], &fill_attr);
        ga_init2 (& ga, 1, 100);
        if (len > 0)
            p = (cellattr_T *) alloc ((int) sizeof (cellattr_T) * len);
        if (p != NULL) {
            for (col = 0; col < len; col += cells[col].width) {
                if (ga_grow (&ga, MB_MAXBYTES) == FAIL) {
                    ga.ga_len = 0;
                    break;
                }
                for (i = 0; (c = cells[col].chars[i]) > 0 || i == 0; ++i)
                    ga.ga_len += utf_char2bytes (c == NUL ? ' ' : c, (char_u *) ga.ga_data + ga.ga_len);
                cell2cellattr (& cells [col], & p [col]);
            }
        }
        if (ga_grow (&ga, 1) == FAIL)
            add_scrollback_line_to_buffer (term, (char_u *) "", 0);
        else {
            *((char_u *) ga.ga_data + ga.ga_len) = NUL;
            add_scrollback_line_to_buffer (term, ga.ga_data, ga.ga_len);
        }
        ga_clear (& ga);
        line = (sb_line_T *) term->tl_scrollback.ga_data + term->tl_scrollback.ga_len;
        line->sb_cols = len;
        line->sb_cells = p;
        line->sb_fill_attr = fill_attr;
        ++term->tl_scrollback.ga_len;
        ++term->tl_scrollback_scrolled;
    }
    return 0;
}

void f_term_getaltscreen (typval_T *argvars, typval_T *rettv) {
    buf_T *buf = term_get_buf (argvars);
    if (buf == NULL)
        return;
    rettv->vval.v_number = buf->b_term->tl_using_altscreen;
}

static buf_T *term_get_buf (typval_T *argvars) {
    buf_T *buf;
    (void) get_tv_number (&argvars[0]);
    ++emsg_off;
    buf = get_buf_tv (&argvars[0], FALSE);
    --emsg_off;
    if (buf == NULL || buf->b_term == NULL)
        return NULL;
    return buf;
}

void f_term_getattr (typval_T *argvars, typval_T *rettv) {
    int attr;
    size_t i;
    char_u *name;
    static struct {
        char *name;
        int attr;
    } attrs [] = {{"bold", HL_BOLD}, {"italic", HL_ITALIC}, {"underline", HL_UNDERLINE}, {"strike", HL_STRIKETHROUGH}, {"reverse", HL_INVERSE},};
    attr = get_tv_number (&argvars[0]);
    name = get_tv_string_chk (&argvars[1]);
    if (name == NULL)
        return;
    for (i = 0; i < sizeof (attrs) / sizeof (attrs[0]); ++i)
        if (STRCMP (name, attrs[i].name) == 0) {
            rettv->vval.v_number = (attr & attrs[i].attr) != 0 ? 1 : 0;
            break;
        }
}

void f_term_getcursor (typval_T *argvars, typval_T *rettv) {
    buf_T *buf = term_get_buf (argvars);
    term_T *term;
    list_T *l;
    dict_T *d;
    if (rettv_list_alloc (rettv) == FAIL)
        return;
    if (buf == NULL)
        return;
    term = buf->b_term;
    l = rettv->vval.v_list;
    list_append_number (l, term -> tl_cursor_pos.row + 1);
    list_append_number (l, term -> tl_cursor_pos.col + 1);
    d = dict_alloc ();
    if (d != NULL) {
        dict_add_nr_str (d, "visible", term -> tl_cursor_visible, NULL);
        dict_add_nr_str (d, "blink", blink_state_is_inverted () ? ! term -> tl_cursor_blink : term -> tl_cursor_blink, NULL);
        dict_add_nr_str (d, "shape", term -> tl_cursor_shape, NULL);
        dict_add_nr_str (d, "color", 0L, term -> tl_cursor_color == NULL ? (char_u *) "" : term -> tl_cursor_color);
        list_append_dict (l, d);
    }
}

void f_term_getjob (typval_T *argvars, typval_T *rettv) {
    buf_T *buf = term_get_buf (argvars);
    rettv->v_type = VAR_JOB;
    rettv->vval.v_job = NULL;
    if (buf == NULL)
        return;
    rettv->vval.v_job = buf->b_term->tl_job;
    if (rettv->vval.v_job != NULL)
        ++rettv->vval.v_job->jv_refcount;
}

void f_term_getline (typval_T *argvars, typval_T *rettv) {
    buf_T *buf = term_get_buf (argvars);
    term_T *term;
    int row;
    rettv->v_type = VAR_STRING;
    if (buf == NULL)
        return;
    term = buf->b_term;
    row = get_row_number (&argvars[1], term);
    if (term->tl_vterm == NULL) {
        linenr_T lnum = row + term->tl_scrollback_scrolled + 1;
        if (lnum > 0 && lnum <= buf->b_ml.ml_line_count)
            rettv->vval.v_string = vim_strsave (ml_get_buf (buf, lnum, FALSE));
    }
    else {
        VTermScreen *screen = vterm_obtain_screen (term->tl_vterm);
        VTermRect rect;
        int len;
        char_u *p;
        if (row < 0 || row >= term->tl_rows)
            return;
        len = term->tl_cols * MB_MAXBYTES + 1;
        p = alloc (len);
        if (p == NULL)
            return;
        rettv->vval.v_string = p;
        rect.start_col = 0;
        rect.end_col = term->tl_cols;
        rect.start_row = row;
        rect.end_row = row + 1;
        p[vterm_screen_get_text (screen, (char *) p, len, rect)] = NUL;
    }
}

static int get_row_number (typval_T *tv, term_T *term) {
    if (tv->v_type == VAR_STRING && tv->vval.v_string != NULL && STRCMP (tv->vval.v_string, ".") == 0)
        return term->tl_cursor_pos.row;
    return (int) get_tv_number (tv) - 1;
}

void f_term_getscrolled (typval_T *argvars, typval_T *rettv) {
    buf_T *buf = term_get_buf (argvars);
    if (buf == NULL)
        return;
    rettv->vval.v_number = buf->b_term->tl_scrollback_scrolled;
}

void f_term_getsize (typval_T *argvars, typval_T *rettv) {
    buf_T *buf = term_get_buf (argvars);
    list_T *l;
    if (rettv_list_alloc (rettv) == FAIL)
        return;
    if (buf == NULL)
        return;
    l = rettv->vval.v_list;
    list_append_number (l, buf -> b_term -> tl_rows);
    list_append_number (l, buf -> b_term -> tl_cols);
}

void f_term_getstatus (typval_T *argvars, typval_T *rettv) {
    buf_T *buf = term_get_buf (argvars);
    term_T *term;
    char_u val [100];
    rettv->v_type = VAR_STRING;
    if (buf == NULL)
        return;
    term = buf->b_term;
    if (term_job_running (term))
        STRCPY (val, "running");
    else
        STRCPY (val, "finished");
    if (term->tl_normal_mode)
        STRCAT (val, ",normal");
    rettv->vval.v_string = vim_strsave (val);
}

void f_term_gettitle (typval_T *argvars, typval_T *rettv) {
    buf_T *buf = term_get_buf (argvars);
    rettv->v_type = VAR_STRING;
    if (buf == NULL)
        return;
    if (buf->b_term->tl_title != NULL)
        rettv->vval.v_string = vim_strsave (buf->b_term->tl_title);
}

void f_term_gettty (typval_T *argvars, typval_T *rettv) {
    buf_T *buf = term_get_buf (argvars);
    char_u *p;
    int num = 0;
    rettv->v_type = VAR_STRING;
    if (buf == NULL)
        return;
    if (argvars[1].v_type != VAR_UNKNOWN)
        num = get_tv_number (&argvars[1]);
    switch (num) {
    case 0 :
        if (buf->b_term->tl_job != NULL)
            p = buf->b_term->tl_job->jv_tty_out;
        else
            p = buf->b_term->tl_tty_out;
        break;
    case 1 :
        if (buf->b_term->tl_job != NULL)
            p = buf->b_term->tl_job->jv_tty_in;
        else
            p = buf->b_term->tl_tty_in;
        break;
    default :
        EMSG2 (_ (e_invarg2), get_tv_string (&argvars[1]));
        return;
    }
    if (p != NULL)
        rettv->vval.v_string = vim_strsave (p);
}

void f_term_list (typval_T *argvars, typval_T *rettv) {
    term_T *tp;
    list_T *l;
    if (rettv_list_alloc (rettv) == FAIL || first_term == NULL)
        return;
    l = rettv->vval.v_list;
    for (tp = first_term; tp != NULL; tp = tp->tl_next)
        if (tp != NULL && tp->tl_buffer != NULL)
            if (list_append_number (l, (varnumber_T) tp->tl_buffer->b_fnum) == FAIL)
                return;
}

void f_term_scrape (typval_T *argvars, typval_T *rettv) {
    buf_T *buf = term_get_buf (argvars);
    VTermScreen *screen = NULL;
    VTermPos pos;
    list_T *l;
    term_T *term;
    char_u *p;
    sb_line_T *line;
    if (rettv_list_alloc (rettv) == FAIL)
        return;
    if (buf == NULL)
        return;
    term = buf->b_term;
    l = rettv->vval.v_list;
    pos.row = get_row_number (&argvars[1], term);
    if (term->tl_vterm != NULL) {
        screen = vterm_obtain_screen (term->tl_vterm);
        p = NULL;
        line = NULL;
    }
    else {
        linenr_T lnum = pos.row + term->tl_scrollback_scrolled;
        if (lnum < 0 || lnum >= term->tl_scrollback.ga_len)
            return;
        p = ml_get_buf (buf, lnum +1, FALSE);
        line = (sb_line_T *) term->tl_scrollback.ga_data + lnum;
    }
    for (pos.col = 0; pos.col < term->tl_cols;) {
        dict_T *dcell;
        int width;
        VTermScreenCellAttrs attrs;
        VTermColor fg, bg;
        char_u rgb [8];
        char_u mbs [MB_MAXBYTES * VTERM_MAX_CHARS_PER_CELL + 1];
        int off = 0;
        int i;
        if (screen == NULL) {
            cellattr_T *cellattr;
            int len;
            if (pos.col >= line->sb_cols)
                break;
            cellattr = line->sb_cells + pos.col;
            width = cellattr->width;
            attrs = cellattr->attrs;
            fg = cellattr->fg;
            bg = cellattr->bg;
            len = MB_PTR2LEN (p);
            mch_memmove (mbs, p, len);
            mbs[len] = NUL;
            p += len;
        }
        else {
            VTermScreenCell cell;
            if (vterm_screen_get_cell (screen, pos, &cell) == 0)
                break;
            for (i = 0; i < VTERM_MAX_CHARS_PER_CELL; ++i) {
                if (cell.chars[i] == 0)
                    break;
                off += (*utf_char2bytes) ((int) cell.chars[i], mbs +off);
            }
            mbs[off] = NUL;
            width = cell.width;
            attrs = cell.attrs;
            fg = cell.fg;
            bg = cell.bg;
        }
        dcell = dict_alloc ();
        if (dcell == NULL)
            break;
        list_append_dict (l, dcell);
        dict_add_nr_str (dcell, "chars", 0, mbs);
        vim_snprintf ((char *) rgb, 8, "#%02x%02x%02x", fg.red, fg.green, fg.blue);
        dict_add_nr_str (dcell, "fg", 0, rgb);
        vim_snprintf ((char *) rgb, 8, "#%02x%02x%02x", bg.red, bg.green, bg.blue);
        dict_add_nr_str (dcell, "bg", 0, rgb);
        dict_add_nr_str (dcell, "attr", cell2attr (attrs, fg, bg), NULL);
        dict_add_nr_str (dcell, "width", width, NULL);
        ++pos.col;
        if (width == 2)
            ++pos.col;
    }
}

void f_term_sendkeys (typval_T *argvars, typval_T *rettv) {
    buf_T *buf = term_get_buf (argvars);
    char_u *msg;
    term_T *term;
    rettv->v_type = VAR_UNKNOWN;
    if (buf == NULL)
        return;
    msg = get_tv_string_chk (&argvars[1]);
    if (msg == NULL)
        return;
    term = buf->b_term;
    if (term->tl_vterm == NULL)
        return;
    while (*msg != NUL) {
        send_keys_to_term (term, PTR2CHAR (msg), FALSE);
        msg += MB_CPTR2LEN (msg);
    }
}

void f_term_start (typval_T *argvars, typval_T *rettv) {
    jobopt_T opt;
    buf_T *buf;
    init_job_options (& opt);
    if (argvars[1].v_type != VAR_UNKNOWN && get_job_options (&argvars[1], &opt, JO_TIMEOUT_ALL +JO_STOPONEXIT + JO_CALLBACK + JO_OUT_CALLBACK + JO_ERR_CALLBACK + JO_EXIT_CB + JO_CLOSE_CALLBACK + JO_OUT_IO, JO2_TERM_NAME +JO2_TERM_FINISH + JO2_HIDDEN + JO2_TERM_OPENCMD + JO2_TERM_COLS + JO2_TERM_ROWS + JO2_VERTICAL + JO2_CURWIN + JO2_CWD + JO2_ENV + JO2_EOF_CHARS) == FAIL)
        return;
    if (opt.jo_vertical)
        cmdmod.split = WSP_VERT;
    buf = term_start (&argvars[0], &opt, FALSE);
    if (buf != NULL && buf->b_term != NULL)
        rettv->vval.v_number = buf->b_fnum;
}

static void init_job_options (jobopt_T *opt) {
    clear_job_options (opt);
    opt->jo_mode = MODE_RAW;
    opt->jo_out_mode = MODE_RAW;
    opt->jo_err_mode = MODE_RAW;
    opt->jo_set = JO_MODE | JO_OUT_MODE | JO_ERR_MODE;
}

static buf_T *term_start (typval_T *argvar, jobopt_T *opt, int forceit) {
    exarg_T split_ea;
    win_T *old_curwin = curwin;
    term_T *term;
    buf_T *old_curbuf = NULL;
    int res;
    buf_T *newbuf;
    if (check_restricted () || check_secure ())
        return NULL;
    if ((opt->jo_set & (JO_IN_IO + JO_OUT_IO + JO_ERR_IO)) == (JO_IN_IO + JO_OUT_IO + JO_ERR_IO) || (!(opt->jo_set & JO_OUT_IO) && (opt->jo_set & JO_OUT_BUF)) || (!(opt->jo_set & JO_ERR_IO) && (opt->jo_set & JO_ERR_BUF))) {
        EMSG (_ (e_invarg));
        return NULL;
    }
    term = (term_T *) alloc_clear (sizeof (term_T));
    if (term == NULL)
        return NULL;
    term->tl_dirty_row_end = MAX_ROW;
    term->tl_cursor_visible = TRUE;
    term->tl_cursor_shape = VTERM_PROP_CURSORSHAPE_BLOCK;
    term->tl_finish = opt->jo_term_finish;
    ga_init2 (& term -> tl_scrollback, sizeof (sb_line_T), 300);
    vim_memset (& split_ea, 0, sizeof (split_ea));
    if (opt->jo_curwin) {
        if (!can_abandon (curbuf, forceit)) {
            no_write_message ();
            vim_free (term);
            return NULL;
        }
        if (do_ecmd (0, NULL, NULL, &split_ea, ECMD_ONE, ECMD_HIDE +(forceit ? ECMD_FORCEIT : 0), curwin) == FAIL) {
            vim_free (term);
            return NULL;
        }
    }
    else if (opt->jo_hidden) {
        buf_T *buf;
        buf = buflist_new ((char_u *) "", NULL, (linenr_T) 0, BLN_NEW | BLN_LISTED);
        if (buf == NULL || ml_open (buf) == FAIL) {
            vim_free (term);
            return NULL;
        }
        old_curbuf = curbuf;
        --curbuf->b_nwindows;
        curbuf = buf;
        curwin->w_buffer = buf;
        ++curbuf->b_nwindows;
    }
    else {
        split_ea.cmdidx = CMD_new;
        split_ea.cmd = (char_u *) "new";
        split_ea.arg = (char_u *) "";
        if (opt->jo_term_rows > 0 && !(cmdmod.split & WSP_VERT)) {
            split_ea.line2 = opt->jo_term_rows;
            split_ea.addr_count = 1;
        }
        if (opt->jo_term_cols > 0 && (cmdmod.split & WSP_VERT)) {
            split_ea.line2 = opt->jo_term_cols;
            split_ea.addr_count = 1;
        }
        ex_splitview (& split_ea);
        if (curwin == old_curwin) {
            vim_free (term);
            return NULL;
        }
    }
    term->tl_buffer = curbuf;
    curbuf->b_term = term;
    if (!opt->jo_hidden) {
        if (opt->jo_term_rows > 0 && (cmdmod.split & WSP_VERT))
            win_setheight (opt->jo_term_rows);
        if (opt->jo_term_cols > 0 && !(cmdmod.split & WSP_VERT))
            win_setwidth (opt->jo_term_cols);
    }
    term->tl_next = first_term;
    first_term = term;
    if (opt->jo_term_name != NULL)
        curbuf->b_ffname = vim_strsave (opt->jo_term_name);
    else {
        int i;
        size_t len;
        char_u *cmd, *p;
        if (argvar->v_type == VAR_STRING) {
            cmd = argvar->vval.v_string;
            if (cmd == NULL)
                cmd = (char_u *) "";
            else if (STRCMP (cmd, "NONE") == 0)
                cmd = (char_u *) "pty";
        }
        else if (argvar->v_type != VAR_LIST || argvar->vval.v_list == NULL || argvar->vval.v_list->lv_len < 1 || (cmd = get_tv_string_chk (&argvar->vval.v_list->lv_first->li_tv)) == NULL)
            cmd = (char_u *) "";
        len = STRLEN (cmd) + 10;
        p = alloc ((int) len);
        for (i = 0; p != NULL; ++i) {
            if (i == 0)
                vim_snprintf ((char *) p, len, "!%s", cmd);
            else
                vim_snprintf ((char *) p, len, "!%s (%d)", cmd, i);
            if (buflist_findname (p) == NULL) {
                vim_free (curbuf -> b_ffname);
                curbuf->b_ffname = p;
                break;
            }
        }
    }
    curbuf->b_fname = curbuf->b_ffname;
    if (opt->jo_term_opencmd != NULL)
        term->tl_opencmd = vim_strsave (opt->jo_term_opencmd);
    if (opt->jo_eof_chars != NULL)
        term->tl_eof_chars = vim_strsave (opt->jo_eof_chars);
    set_string_option_direct ((char_u *) "buftype", - 1, (char_u *) "terminal", OPT_FREE | OPT_LOCAL, 0);
    curbuf->b_p_ma = FALSE;
    set_term_and_win_size (term);
    setup_job_options (opt, term -> tl_rows, term -> tl_cols);
    if (argvar->v_type == VAR_STRING && argvar->vval.v_string != NULL && STRCMP (argvar->vval.v_string, "NONE") == 0)
        res = create_pty_only (term, opt);
    else
        res = term_and_job_init (term, argvar, opt);
    newbuf = curbuf;
    if (res == OK) {
        vterm_get_size (term -> tl_vterm, & term -> tl_rows, & term -> tl_cols);
        term_report_winsize (term, term -> tl_rows, term -> tl_cols);
        channel_set_nonblock (term -> tl_job -> jv_channel, PART_IN);
        if (!opt->jo_hidden) {
            ++curbuf->b_locked;
            apply_autocmds (EVENT_BUFWINENTER, NULL, NULL, FALSE, curbuf);
            --curbuf->b_locked;
        }
        if (old_curbuf != NULL) {
            --curbuf->b_nwindows;
            curbuf = old_curbuf;
            curwin->w_buffer = curbuf;
            ++curbuf->b_nwindows;
        }
    }
    else {
        buf_T *buf = curbuf;
        free_terminal (curbuf);
        if (old_curbuf != NULL) {
            --curbuf->b_nwindows;
            curbuf = old_curbuf;
            curwin->w_buffer = curbuf;
            ++curbuf->b_nwindows;
        }
        do_buffer (DOBUF_WIPE, DOBUF_FIRST, FORWARD, buf -> b_fnum, TRUE);
        return NULL;
    }
    return newbuf;
}

static void set_term_and_win_size (term_T *term) {
    if (*curwin->w_p_tms != NUL) {
        char_u *p = vim_strchr (curwin->w_p_tms, 'x') + 1;
        term->tl_rows = atoi ((char *) curwin->w_p_tms);
        term->tl_cols = atoi ((char *) p);
    }
    if (term->tl_rows == 0)
        term->tl_rows = curwin->w_height;
    else {
        win_setheight_win (term -> tl_rows, curwin);
        term->tl_rows_fixed = TRUE;
    }
    if (term->tl_cols == 0)
        term->tl_cols = curwin->w_width;
    else {
        win_setwidth_win (term -> tl_cols, curwin);
        term->tl_cols_fixed = TRUE;
    }
}

static void setup_job_options (jobopt_T *opt, int rows, int cols) {
    if (!(opt->jo_set & JO_OUT_IO)) {
        opt->jo_io[PART_OUT] = JIO_BUFFER;
        opt->jo_io_buf[PART_OUT] = curbuf->b_fnum;
        opt->jo_modifiable[PART_OUT] = 0;
        opt->jo_set |= JO_OUT_IO + JO_OUT_BUF + JO_OUT_MODIFIABLE;
    }
    if (!(opt->jo_set & JO_ERR_IO)) {
        opt->jo_io[PART_ERR] = JIO_BUFFER;
        opt->jo_io_buf[PART_ERR] = curbuf->b_fnum;
        opt->jo_modifiable[PART_ERR] = 0;
        opt->jo_set |= JO_ERR_IO + JO_ERR_BUF + JO_ERR_MODIFIABLE;
    }
    opt->jo_pty = TRUE;
    if ((opt->jo_set2 & JO2_TERM_ROWS) == 0)
        opt->jo_term_rows = rows;
    if ((opt->jo_set2 & JO2_TERM_COLS) == 0)
        opt->jo_term_cols = cols;
}

static int create_pty_only (term_T *term, jobopt_T *opt) {
    create_vterm (term, term -> tl_rows, term -> tl_cols);
    term->tl_job = job_alloc ();
    if (term->tl_job == NULL)
        return FAIL;
    ++term->tl_job->jv_refcount;
    term->tl_job->jv_status = JOB_FINISHED;
    return mch_create_pty_channel (term->tl_job, opt);
}

static void create_vterm (term_T *term, int rows, int cols) {
    VTerm *vterm;
    VTermScreen *screen;
    VTermValue value;
    VTermColor *fg, *bg;
    int fgval, bgval;
    int id;
    vterm = vterm_new (rows, cols);
    term->tl_vterm = vterm;
    screen = vterm_obtain_screen (vterm);
    vterm_screen_set_callbacks (screen, & screen_callbacks, term);
    vterm_set_utf8 (vterm, 1);
    vim_memset (& term -> tl_default_color.attrs, 0, sizeof (VTermScreenCellAttrs));
    term->tl_default_color.width = 1;
    fg = &term->tl_default_color.fg;
    bg = &term->tl_default_color.bg;
    if (*p_bg == 'l') {
        fgval = 0;
        bgval = 255;
    }
    else {
        fgval = 255;
        bgval = 0;
    }
    fg->red = fg->green = fg->blue = fgval;
    bg->red = bg->green = bg->blue = bgval;
    fg->ansi_index = bg->ansi_index = VTERM_ANSI_INDEX_DEFAULT;
    id = syn_name2id ((char_u *) "Terminal");
    if (0 || gui.in_use)
        if (0 || p_tgc) {
            guicolor_T fg_rgb = INVALCOLOR;
            guicolor_T bg_rgb = INVALCOLOR;
            if (id != 0)
                syn_id2colors (id, &fg_rgb, &bg_rgb);
            if (gui.in_use) {
                if (fg_rgb == INVALCOLOR)
                    fg_rgb = gui.norm_pixel;
                if (bg_rgb == INVALCOLOR)
                    bg_rgb = gui.back_pixel;
            }
            else {
                if (fg_rgb == INVALCOLOR)
                    fg_rgb = cterm_normal_fg_gui_color;
                if (bg_rgb == INVALCOLOR)
                    bg_rgb = cterm_normal_bg_gui_color;
            }
            if (fg_rgb != INVALCOLOR) {
                long_u rgb = GUI_MCH_GET_RGB (fg_rgb);
                fg->red = (unsigned ) (rgb >> 16);
                fg->green = (unsigned ) (rgb >> 8) & 255;
                fg->blue = (unsigned ) rgb & 255;
            }
            if (bg_rgb != INVALCOLOR) {
                long_u rgb = GUI_MCH_GET_RGB (bg_rgb);
                bg->red = (unsigned ) (rgb >> 16);
                bg->green = (unsigned ) (rgb >> 8) & 255;
                bg->blue = (unsigned ) rgb & 255;
            }
        }
        else if (id != 0 && t_colors >= 16) {
            if (term_default_cterm_fg >= 0)
                cterm_color2rgb (term_default_cterm_fg, fg);
            if (term_default_cterm_bg >= 0)
                cterm_color2rgb (term_default_cterm_bg, bg);
        }
        else {
            if (cterm_normal_fg_color > 0) {
                cterm_color2rgb (cterm_normal_fg_color - 1, fg);
            }
            else
                term_get_fg_color (&fg->red, &fg->green, &fg->blue);
            if (cterm_normal_bg_color > 0) {
                cterm_color2rgb (cterm_normal_bg_color - 1, bg);
            }
            else
                term_get_bg_color (&bg->red, &bg->green, &bg->blue);
        }
    vterm_state_set_default_colors (vterm_obtain_state (vterm), fg, bg);
    vterm_screen_reset (screen, 1);
    vterm_screen_enable_altscreen (screen, 1);
    value.boolean = 0;
    vterm_state_set_termprop (vterm_obtain_state (vterm), VTERM_PROP_CURSORBLINK, & value);
}

static void cterm_color2rgb (int nr, VTermColor *rgb) {
    int idx;
    if (nr < 16) {
        *rgb = ansi_table[nr];
    }
    else if (nr < 232) {
        idx = nr - 16;
        rgb->blue = cube_value[idx % 6];
        rgb->green = cube_value[idx / 6 % 6];
        rgb->red = cube_value[idx / 36 % 6];
        rgb->ansi_index = VTERM_ANSI_INDEX_NONE;
    }
    else if (nr < 256) {
        idx = nr - 232;
        rgb->blue = grey_ramp[idx];
        rgb->green = grey_ramp[idx];
        rgb->red = grey_ramp[idx];
        rgb->ansi_index = VTERM_ANSI_INDEX_NONE;
    }
}

static int term_and_job_init (term_T *term, typval_T *argvar, jobopt_T *opt) {
    create_vterm (term, term -> tl_rows, term -> tl_cols);
    term->tl_job = job_start (argvar, opt);
    if (term->tl_job != NULL)
        ++term->tl_job->jv_refcount;
    return term->tl_job != NULL && term->tl_job->jv_channel != NULL && term->tl_job->jv_status != JOB_FAILED ? OK : FAIL;
}

void f_term_wait (typval_T *argvars, typval_T *rettv) {
    buf_T *buf = term_get_buf (argvars);
    if (buf == NULL) {
        ch_log (NULL, "term_wait(): invalid argument");
        return;
    }
    if (buf->b_term->tl_job == NULL) {
        ch_log (NULL, "term_wait(): no job to wait for");
        return;
    }
    if (buf->b_term->tl_job->jv_channel == NULL)
        return;
    if (!buf->b_term->tl_job->jv_channel->ch_keep_open && STRCMP (job_status (buf->b_term->tl_job), "dead") == 0) {
        ch_log (NULL, "term_wait(): waiting for channel to close");
        while (buf->b_term != NULL && !buf->b_term->tl_channel_closed) {
            mch_check_messages ();
            parse_queued_messages ();
            if (!buf_valid (buf))
                break;
            ui_delay (10L, FALSE);
        }
        mch_check_messages ();
        parse_queued_messages ();
    }
    else {
        long  wait = 10L;
        mch_check_messages ();
        parse_queued_messages ();
        if (argvars[1].v_type != VAR_UNKNOWN)
            wait = get_tv_number (&argvars[1]);
        ui_delay (wait, TRUE);
        mch_check_messages ();
        parse_queued_messages ();
    }
}

void term_enter_job_mode () {
    term_T *term = curbuf->b_term;
    sb_line_T *line;
    garray_T *gap;
    gap = &term->tl_scrollback;
    while (curbuf->b_ml.ml_line_count > term->tl_scrollback_scrolled && gap->ga_len > 0) {
        ml_delete (curbuf -> b_ml.ml_line_count, FALSE);
        line = (sb_line_T *) gap->ga_data + gap->ga_len - 1;
        vim_free (line -> sb_cells);
        --gap->ga_len;
    }
    check_cursor ();
    set_terminal_mode (term, FALSE);
    if (term->tl_channel_closed)
        cleanup_vterm (term);
    redraw_buf_and_status_later (curbuf, NOT_VALID);
}

