
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
struct syl_item_S {
    char_u sy_chars [SY_MAXLEN];
    int sy_len;
};
struct spelload_S {
    char_u sl_lang [MAXWLEN + 1];
    slang_T *sl_slang;
    int sl_nobreak;
};
struct suggest_S {
    char_u *st_word;
    int st_wordlen;
    int st_orglen;
    int st_score;
    int st_altscore;
    int st_salscore;
    int st_had_bonus;
    slang_T *st_slang;
};
struct suginfo_S {
    garray_T su_ga;
    int su_maxcount;
    int su_maxscore;
    int su_sfmaxscore;
    garray_T su_sga;
    char_u *su_badptr;
    int su_badlen;
    int su_badflags;
    char_u su_badword [MAXWLEN];
    char_u su_fbadword [MAXWLEN];
    char_u su_sal_badword [MAXWLEN];
    hashtab_T su_banned;
    slang_T *su_sallang;
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
struct trystate_S {
    state_T ts_state;
    int ts_score;
    idx_T ts_arridx;
    short  ts_curi;
    char_u ts_fidx;
    char_u ts_fidxtry;
    char_u ts_twordlen;
    char_u ts_prefixdepth;
    char_u ts_flags;
    char_u ts_prewordlen;
    char_u ts_splitoff;
    char_u ts_splitfidx;
    char_u ts_complen;
    char_u ts_compsplit;
    char_u ts_save_badflags;
    char_u ts_delidx;
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
struct matchinf_S {
    langp_T *mi_lp;
    char_u *mi_word;
    char_u *mi_end;
    char_u *mi_fend;
    char_u *mi_cend;
    char_u mi_fword [MAXWLEN + 1];
    int mi_fwordlen;
    int mi_prefarridx;
    int mi_prefcnt;
    int mi_prefixlen;

    # define mi_cprefixlen mi_prefixlen	/* it's the same value */
    int mi_compoff;
    char_u mi_compflags [MAXWLEN];
    int mi_complen;
    int mi_compextra;
    int mi_result;
    int mi_capflags;
    win_T *mi_win;
    int mi_result2;
    char_u *mi_end2;
};
struct wordcount_S {
    short_u wc_count;
    char_u wc_word [1];
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
EXTERN int p_ws;
SPELL_EXTERN slang_T *first_lang SPELL_INIT (= NULL);
EXTERN char_u *p_sps;
int sps_limit = 9999;
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
int sps_flags = SPS_BEST;
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
int spell_expand_need_cap;
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

int spell_check (win_T *wp, char_u *ptr, hlf_T *attrp, int *capcol, int docount) {
    matchinf_T mi;
    int nrlen = 0;
    int c;
    int wrongcaplen = 0;
    int lpi;
    int count_word = docount;
    if (*ptr <= ' ')
        return 1;
    if (wp->w_s->b_langp.ga_len == 0)
        return 1;
    vim_memset (& mi, 0, sizeof (matchinf_T));
    if (*ptr >= '0' && *ptr <= '9') {
        if (*ptr == '0' && (ptr[1] == 'b' || ptr[1] == 'B'))
            mi.mi_end = skipbin (ptr +2);
        else if (*ptr == '0' && (ptr[1] == 'x' || ptr[1] == 'X'))
            mi.mi_end = skiphex (ptr +2);
        else
            mi.mi_end = skipdigits (ptr);
        nrlen = (int) (mi.mi_end - ptr);
    }
    mi.mi_word = ptr;
    mi.mi_fend = ptr;
    if (spell_iswordp (mi.mi_fend, wp)) {
        do {
            MB_PTR_ADV (mi.mi_fend);
        }
        while (*mi.mi_fend != NUL && spell_iswordp (mi.mi_fend, wp));
        if (capcol != NULL && *capcol == 0 && wp->w_s->b_cap_prog != NULL) {
            c = PTR2CHAR (ptr);
            if (!SPELL_ISUPPER (c))
                wrongcaplen = (int) (mi.mi_fend - ptr);
        }
    }
    if (capcol != NULL)
        *capcol = -1;
    mi.mi_end = mi.mi_fend;
    mi.mi_capflags = 0;
    mi.mi_cend = NULL;
    mi.mi_win = wp;
    if (*mi.mi_fend != NUL)
        MB_PTR_ADV (mi.mi_fend);
    (void) spell_casefold (ptr, (int) (mi.mi_fend - ptr), mi.mi_fword, MAXWLEN +1);
    mi.mi_fwordlen = (int) STRLEN (mi.mi_fword);
    mi.mi_result = SP_BAD;
    mi.mi_result2 = SP_BAD;
    for (lpi = 0; lpi < wp->w_s->b_langp.ga_len; ++lpi) {
        mi.mi_lp = LANGP_ENTRY (wp->w_s->b_langp, lpi);
        if (mi.mi_lp->lp_slang->sl_fidxs == NULL)
            continue;
        find_word (& mi, FIND_FOLDWORD);
        find_word (& mi, FIND_KEEPWORD);
        find_prefix (& mi, FIND_FOLDWORD);
        if (mi.mi_lp->lp_slang->sl_nobreak && mi.mi_result == SP_BAD && mi.mi_result2 != SP_BAD) {
            mi.mi_result = mi.mi_result2;
            mi.mi_end = mi.mi_end2;
        }
        if (count_word && mi.mi_result == SP_OK) {
            count_common_word (mi.mi_lp -> lp_slang, ptr, (int) (mi.mi_end - ptr), 1);
            count_word = FALSE;
        }
    }
    if (mi.mi_result != SP_OK) {
        if (nrlen > 0) {
            if (mi.mi_result == SP_BAD || mi.mi_result == SP_BANNED)
                return nrlen;
        }
        else if (!spell_iswordp_nmw (ptr, wp)) {
            if (capcol != NULL && wp->w_s->b_cap_prog != NULL) {
                regmatch_T regmatch;
                int r;
                regmatch.regprog = wp->w_s->b_cap_prog;
                regmatch.rm_ic = FALSE;
                r = vim_regexec (&regmatch, ptr, 0);
                wp->w_s->b_cap_prog = regmatch.regprog;
                if (r)
                    *capcol = (int) (regmatch.endp[0] - ptr);
            }
            return 1;
        }
        else if (mi.mi_end == ptr)
            MB_PTR_ADV (mi.mi_end);
        else if (mi.mi_result == SP_BAD && LANGP_ENTRY (wp->w_s->b_langp, 0)->lp_slang->sl_nobreak) {
            char_u *p, *fp;
            int save_result = mi.mi_result;
            mi.mi_lp = LANGP_ENTRY (wp->w_s->b_langp, 0);
            if (mi.mi_lp->lp_slang->sl_fidxs != NULL) {
                p = mi.mi_word;
                fp = mi.mi_fword;
                for (;;) {
                    MB_PTR_ADV (p);
                    MB_PTR_ADV (fp);
                    if (p >= mi.mi_end)
                        break;
                    mi.mi_compoff = (int) (fp - mi.mi_fword);
                    find_word (& mi, FIND_COMPOUND);
                    if (mi.mi_result != SP_BAD) {
                        mi.mi_end = p;
                        break;
                    }
                }
                mi.mi_result = save_result;
            }
        }
        if (mi.mi_result == SP_BAD || mi.mi_result == SP_BANNED)
            *attrp = HLF_SPB;
        else if (mi.mi_result == SP_RARE)
            *attrp = HLF_SPR;
        else
            *attrp = HLF_SPL;
    }
    if (wrongcaplen > 0 && (mi.mi_result == SP_OK || mi.mi_result == SP_RARE)) {
        *attrp = HLF_SPC;
        return wrongcaplen;
    }
    return (int) (mi.mi_end - ptr);
}

static int spell_iswordp (char_u *p, win_T *wp) {
    return spelltab.st_isw[wp->w_s->b_spell_ismw[*p] ? p[1] : p[0]];
}

int spell_casefold (char_u *str, int len, char_u *buf, int buflen) {
    int i;
    if (len >= buflen) {
        buf[0] = NUL;
        return FAIL;
    }
    {
        for (i = 0; i < len; ++i)
            buf[i] = spelltab.st_fold[str[i]];
        buf[i] = NUL;
    }
    return OK;
}

#define SPS_BEST    1

#define SPS_FAST    2

#define SPS_DOUBLE  4

static void find_word (matchinf_T *mip, int mode) {
    idx_T arridx = 0;
    int endlen [MAXWLEN];
    idx_T endidx [MAXWLEN];
    int endidxcnt = 0;
    int len;
    int wlen = 0;
    int flen;
    int c;
    char_u *ptr;
    idx_T lo, hi, m;
    char_u *p;
    int res = SP_BAD;
    slang_T *slang = mip->mi_lp->lp_slang;
    unsigned  flags;
    char_u *byts;
    idx_T *idxs;
    int word_ends;
    int prefix_found;
    int nobreak_result;
    if (mode == FIND_KEEPWORD || mode == FIND_KEEPCOMPOUND) {
        ptr = mip->mi_word;
        flen = 9999;
        byts = slang->sl_kbyts;
        idxs = slang->sl_kidxs;
        if (mode == FIND_KEEPCOMPOUND)
            wlen += mip->mi_compoff;
    }
    else {
        ptr = mip->mi_fword;
        flen = mip->mi_fwordlen;
        byts = slang->sl_fbyts;
        idxs = slang->sl_fidxs;
        if (mode == FIND_PREFIX) {
            wlen = mip->mi_prefixlen;
            flen -= mip->mi_prefixlen;
        }
        else if (mode == FIND_COMPOUND) {
            wlen = mip->mi_compoff;
            flen -= mip->mi_compoff;
        }
    }
    if (byts == NULL)
        return;
    for (;;) {
        if (flen <= 0 && *mip->mi_fend != NUL)
            flen = fold_more (mip);
        len = byts[arridx++];
        if (byts[arridx] == 0) {
            if (endidxcnt == MAXWLEN) {
                EMSG (_ (e_format));
                return;
            }
            endlen[endidxcnt] = wlen;
            endidx[endidxcnt++] = arridx++;
            --len;
            while (len > 0 && byts[arridx] == 0) {
                ++arridx;
                --len;
            }
            if (len == 0)
                break;
        }
        if (ptr[wlen] == NUL)
            break;
        c = ptr[wlen];
        if (c == TAB)
            c = ' ';
        lo = arridx;
        hi = arridx + len - 1;
        while (lo < hi) {
            m = (lo + hi) / 2;
            if (byts[m] > c)
                hi = m - 1;
            else if (byts[m] < c)
                lo = m + 1;
            else {
                lo = hi = m;
                break;
            }
        }
        if (hi < lo || byts[lo] != c)
            break;
        arridx = idxs[lo];
        ++wlen;
        --flen;
        if (c == ' ') {
            for (;;) {
                if (flen <= 0 && *mip->mi_fend != NUL)
                    flen = fold_more (mip);
                if (ptr[wlen] != ' ' && ptr[wlen] != TAB)
                    break;
                ++wlen;
                --flen;
            }
        }
    }
    while (endidxcnt > 0) {
        --endidxcnt;
        arridx = endidx[endidxcnt];
        wlen = endlen[endidxcnt];
        if (spell_iswordp (ptr +wlen, mip->mi_win)) {
            if (slang->sl_compprog == NULL && !slang->sl_nobreak)
                continue;
            word_ends = FALSE;
        }
        else
            word_ends = TRUE;
        prefix_found = FALSE;
        res = SP_BAD;
        for (len = byts[arridx - 1]; len > 0 && byts[arridx] == 0; --len, ++arridx) {
            flags = idxs[arridx];
            if (mode == FIND_FOLDWORD) {
                if (mip->mi_cend != mip->mi_word + wlen) {
                    mip->mi_cend = mip->mi_word + wlen;
                    mip->mi_capflags = captype (mip->mi_word, mip->mi_cend);
                }
                if (mip->mi_capflags == WF_KEEPCAP || !spell_valid_case (mip->mi_capflags, flags))
                    continue;
            }
            else if (mode == FIND_PREFIX && !prefix_found) {
                c = valid_word_prefix (mip->mi_prefcnt, mip->mi_prefarridx, flags, mip->mi_word + mip->mi_cprefixlen, slang, FALSE);
                if (c == 0)
                    continue;
                if (c & WF_RAREPFX)
                    flags |= WF_RARE;
                prefix_found = TRUE;
            }
            if (slang->sl_nobreak) {
                if ((mode == FIND_COMPOUND || mode == FIND_KEEPCOMPOUND) && (flags & WF_BANNED) == 0) {
                    mip->mi_result = SP_OK;
                    break;
                }
            }
            else if ((mode == FIND_COMPOUND || mode == FIND_KEEPCOMPOUND || !word_ends)) {
                if (((unsigned ) flags >> 24) == 0 || wlen - mip->mi_compoff < slang->sl_compminlen)
                    continue;
                if (!word_ends && mip->mi_complen + mip->mi_compextra + 2 > slang->sl_compmax && slang->sl_compsylmax == MAXWLEN)
                    continue;
                if (mip->mi_complen > 0 && (flags & WF_NOCOMPBEF))
                    continue;
                if (!word_ends && (flags & WF_NOCOMPAFT))
                    continue;
                if (!byte_in_str (mip->mi_complen == 0 ? slang->sl_compstartflags : slang->sl_compallflags, ((unsigned ) flags >> 24)))
                    continue;
                if (match_checkcompoundpattern (ptr, wlen, &slang->sl_comppat))
                    continue;
                if (mode == FIND_COMPOUND) {
                    int capflags;
                    p = mip->mi_word + mip->mi_compoff;
                    capflags = captype (p, mip->mi_word + wlen);
                    if (capflags == WF_KEEPCAP || (capflags == WF_ALLCAP && (flags & WF_FIXCAP) != 0))
                        continue;
                    if (capflags != WF_ALLCAP) {
                        MB_PTR_BACK (mip -> mi_word, p);
                        if (spell_iswordp_nmw (p, mip->mi_win) ? capflags == WF_ONECAP : (flags & WF_ONECAP) != 0 && capflags != WF_ONECAP)
                            continue;
                    }
                }
                mip->mi_compflags[mip->mi_complen] = ((unsigned ) flags >> 24);
                mip->mi_compflags[mip->mi_complen + 1] = NUL;
                if (word_ends) {
                    char_u fword [MAXWLEN];
                    if (slang->sl_compsylmax < MAXWLEN) {
                        if (ptr == mip->mi_word)
                            (void) spell_casefold (ptr, wlen, fword, MAXWLEN);
                        else
                            vim_strncpy (fword, ptr, endlen[endidxcnt]);
                    }
                    if (!can_compound (slang, fword, mip->mi_compflags))
                        continue;
                }
                else if (slang->sl_comprules != NULL && !match_compoundrule (slang, mip->mi_compflags))
                    continue;
            }
            else if (flags & WF_NEEDCOMP)
                continue;
            nobreak_result = SP_OK;
            if (!word_ends) {
                int save_result = mip->mi_result;
                char_u *save_end = mip->mi_end;
                langp_T *save_lp = mip->mi_lp;
                int lpi;
                if (slang->sl_nobreak)
                    mip->mi_result = SP_BAD;
                mip->mi_compoff = endlen[endidxcnt];
                ++mip->mi_complen;
                if (flags & WF_COMPROOT)
                    ++mip->mi_compextra;
                for (lpi = 0; lpi < mip->mi_win->w_s->b_langp.ga_len; ++lpi) {
                    if (slang->sl_nobreak) {
                        mip->mi_lp = LANGP_ENTRY (mip->mi_win->w_s->b_langp, lpi);
                        if (mip->mi_lp->lp_slang->sl_fidxs == NULL || !mip->mi_lp->lp_slang->sl_nobreak)
                            continue;
                    }
                    find_word (mip, FIND_COMPOUND);
                    if (!slang->sl_nobreak || mip->mi_result == SP_BAD) {
                        mip->mi_compoff = wlen;
                        find_word (mip, FIND_KEEPCOMPOUND);
                    }
                    if (!slang->sl_nobreak)
                        break;
                }
                --mip->mi_complen;
                if (flags & WF_COMPROOT)
                    --mip->mi_compextra;
                mip->mi_lp = save_lp;
                if (slang->sl_nobreak) {
                    nobreak_result = mip->mi_result;
                    mip->mi_result = save_result;
                    mip->mi_end = save_end;
                }
                else {
                    if (mip->mi_result == SP_OK)
                        break;
                    continue;
                }
            }
            if (flags & WF_BANNED)
                res = SP_BANNED;
            else if (flags & WF_REGION) {
                if ((mip->mi_lp->lp_region & (flags >> 16)) != 0)
                    res = SP_OK;
                else
                    res = SP_LOCAL;
            }
            else if (flags & WF_RARE)
                res = SP_RARE;
            else
                res = SP_OK;
            if (nobreak_result == SP_BAD) {
                if (mip->mi_result2 > res) {
                    mip->mi_result2 = res;
                    mip->mi_end2 = mip->mi_word + wlen;
                }
                else if (mip->mi_result2 == res && mip->mi_end2 < mip->mi_word + wlen)
                    mip->mi_end2 = mip->mi_word + wlen;
            }
            else if (mip->mi_result > res) {
                mip->mi_result = res;
                mip->mi_end = mip->mi_word + wlen;
            }
            else if (mip->mi_result == res && mip->mi_end < mip->mi_word + wlen)
                mip->mi_end = mip->mi_word + wlen;
            if (mip->mi_result == SP_OK)
                break;
        }
        if (mip->mi_result == SP_OK)
            break;
    }
}

static int fold_more (matchinf_T *mip) {
    int flen;
    char_u *p;
    p = mip->mi_fend;
    do {
        MB_PTR_ADV (mip -> mi_fend);
    }
    while (*mip->mi_fend != NUL && spell_iswordp (mip->mi_fend, mip->mi_win));
    if (*mip->mi_fend != NUL)
        MB_PTR_ADV (mip->mi_fend);
    (void) spell_casefold (p, (int) (mip->mi_fend - p), mip->mi_fword + mip->mi_fwordlen, MAXWLEN -mip->mi_fwordlen);
    flen = (int) STRLEN (mip->mi_fword + mip->mi_fwordlen);
    mip->mi_fwordlen += flen;
    return flen;
}

int captype (char_u *word, char_u *end) {
    char_u *p;
    int c;
    int firstcap;
    int allcap;
    int past_second = FALSE;
    for (p = word; !spell_iswordp_nmw (p, curwin); MB_PTR_ADV (p))
        if (end == NULL ? *p == NUL : p >= end)
            return 0;
    c = *p++;
    firstcap = allcap = SPELL_ISUPPER (c);
    for (; end == NULL ? *p != NUL : p < end; MB_PTR_ADV (p))
        if (spell_iswordp_nmw (p, curwin)) {
            c = PTR2CHAR (p);
            if (!SPELL_ISUPPER (c)) {
                if (past_second && allcap)
                    return WF_KEEPCAP;
                allcap = FALSE;
            }
            else if (!allcap)
                return WF_KEEPCAP;
            past_second = TRUE;
        }
    if (allcap)
        return WF_ALLCAP;
    if (firstcap)
        return WF_ONECAP;
    return 0;
}

int spell_iswordp_nmw (char_u *p, win_T *wp) {
    return spelltab.st_isw[*p];
}

static int spell_valid_case (int wordflags, int treeflags) {
    return ((wordflags == WF_ALLCAP && (treeflags & WF_FIXCAP) == 0) || ((treeflags & (WF_ALLCAP | WF_KEEPCAP)) == 0 && ((treeflags & WF_ONECAP) == 0 || (wordflags & WF_ONECAP) != 0)));
}

static int valid_word_prefix (int totprefcnt, int arridx, int flags, char_u *word, slang_T *slang, int cond_req) {
    int prefcnt;
    int pidx;
    regprog_T **rp;
    int prefid;
    prefid = (unsigned ) flags >> 24;
    for (prefcnt = totprefcnt - 1; prefcnt >= 0; --prefcnt) {
        pidx = slang->sl_pidxs[arridx + prefcnt];
        if (prefid != (pidx & 0xff))
            continue;
        if ((flags & WF_HAS_AFF) && (pidx & WF_PFX_NC))
            continue;
        rp = &slang->sl_prefprog[((unsigned ) pidx >> 8) & 0xffff];
        if (*rp != NULL) {
            if (!vim_regexec_prog (rp, FALSE, word, 0))
                continue;
        }
        else if (cond_req)
            continue;
        return pidx;
    }
    return 0;
}

void spell_delete_wordlist (void) {
    char_u fname [MAXPATHL];
    if (int_wordlist != NULL) {
        mch_remove (int_wordlist);
        int_wordlist_spl (fname);
        mch_remove (fname);
        VIM_CLEAR (int_wordlist);
    }
}

static void int_wordlist_spl (char_u *fname) {
    vim_snprintf ((char *) fname, MAXPATHL, SPL_FNAME_TMPL, int_wordlist, spell_enc ());
}

char_u *spell_enc (void) {
    return (char_u *) "latin1";
}

int spell_check_sps (void) {
    char_u *p;
    char_u *s;
    char_u buf [MAXPATHL];
    int f;
    sps_flags = 0;
    sps_limit = 9999;
    for (p = p_sps; *p != NUL;) {
        copy_option_part (& p, buf, MAXPATHL, ",");
        f = 0;
        if (VIM_ISDIGIT (*buf)) {
            s = buf;
            sps_limit = getdigits (&s);
            if (*s != NUL && !VIM_ISDIGIT (*s))
                f = -1;
        }
        else if (STRCMP (buf, "best") == 0)
            f = SPS_BEST;
        else if (STRCMP (buf, "fast") == 0)
            f = SPS_FAST;
        else if (STRCMP (buf, "double") == 0)
            f = SPS_DOUBLE;
        else if (STRNCMP (buf, "expr:", 5) != 0 && STRNCMP (buf, "file:", 5) != 0)
            f = -1;
        if (f == -1 || (sps_flags != 0 && f != 0)) {
            sps_flags = SPS_BEST;
            sps_limit = 9999;
            return FAIL;
        }
        if (f != 0)
            sps_flags = f;
    }
    if (sps_flags == 0)
        sps_flags = SPS_BEST;
    return OK;
}

char_u *did_set_spelllang (win_T *wp) {
    garray_T ga;
    char_u *splp;
    char_u *region;
    char_u region_cp [3];
    int filename;
    int region_mask;
    slang_T *slang;
    int c;
    char_u lang [MAXWLEN + 1];
    char_u spf_name [MAXPATHL];
    int len;
    char_u *p;
    int round;
    char_u *spf;
    char_u *use_region = NULL;
    int dont_use_region = FALSE;
    int nobreak = FALSE;
    int i, j;
    langp_T *lp, *lp2;
    static int recursive = FALSE;
    char_u *ret_msg = NULL;
    char_u *spl_copy;
    bufref_T bufref;
    set_bufref (& bufref, wp -> w_buffer);
    if (recursive)
        return NULL;
    recursive = TRUE;
    ga_init2 (& ga, sizeof (langp_T), 2);
    clear_midword (wp);
    spl_copy = vim_strsave (wp->w_s->b_p_spl);
    if (spl_copy == NULL)
        goto theend;
    for (splp = spl_copy; *splp != NUL;) {
        copy_option_part (& splp, lang, MAXWLEN, ",");
        region = NULL;
        len = (int) STRLEN (lang);
        if (STRCMP (lang, "cjk") == 0) {
            continue;
        }
        if (len > 4 && fnamecmp (lang +len - 4, ".spl") == 0) {
            filename = TRUE;
            p = vim_strchr (gettail (lang), '_');
            if (p != NULL && ASCII_ISALPHA (p[1]) && ASCII_ISALPHA (p[2]) && !ASCII_ISALPHA (p[3])) {
                vim_strncpy (region_cp, p + 1, 2);
                mch_memmove (p, p + 3, len - (p - lang) - 2);
                len -= 3;
                region = region_cp;
            }
            else
                dont_use_region = TRUE;
            for (slang = first_lang; slang != NULL; slang = slang->sl_next)
                if (fullpathcmp (lang, slang->sl_fname, FALSE) == FPC_SAME)
                    break;
        }
        else {
            filename = FALSE;
            if (len > 3 && lang[len - 3] == '_') {
                region = lang + len - 2;
                len -= 3;
                lang[len] = NUL;
            }
            else
                dont_use_region = TRUE;
            for (slang = first_lang; slang != NULL; slang = slang->sl_next)
                if (STRICMP (lang, slang->sl_name) == 0)
                    break;
        }
        if (region != NULL) {
            if (use_region != NULL && STRCMP (region, use_region) != 0)
                dont_use_region = TRUE;
            use_region = region;
        }
        if (slang == NULL) {
            if (filename)
                (void) spell_load_file (lang, lang, NULL, FALSE);
            else {
                spell_load_lang (lang);
                if (!bufref_valid (&bufref)) {
                    ret_msg = (char_u *) N_ ("E797: SpellFileMissing autocommand deleted buffer");
                    goto theend;
                }
            }
        }
        for (slang = first_lang; slang != NULL; slang = slang->sl_next)
            if (filename ? fullpathcmp (lang, slang->sl_fname, FALSE) == FPC_SAME : STRICMP (lang, slang->sl_name) == 0) {
                region_mask = REGION_ALL;
                if (!filename && region != NULL) {
                    c = find_region (slang->sl_regions, region);
                    if (c == REGION_ALL) {
                        if (slang->sl_add) {
                            if (*slang->sl_regions != NUL)
                                region_mask = 0;
                        }
                        else
                            smsg ((char_u *) _ ("Warning: region %s not supported"), region);
                    }
                    else
                        region_mask = 1 << c;
                }
                if (region_mask != 0) {
                    if (ga_grow (&ga, 1) == FAIL) {
                        ga_clear (& ga);
                        ret_msg = e_outofmem;
                        goto theend;
                    }
                    LANGP_ENTRY (ga, ga.ga_len)->lp_slang = slang;
                    LANGP_ENTRY (ga, ga.ga_len)->lp_region = region_mask;
                    ++ga.ga_len;
                    use_midword (slang, wp);
                    if (slang->sl_nobreak)
                        nobreak = TRUE;
                }
            }
    }
    spf = curwin->w_s->b_p_spf;
    for (round = 0; round == 0 || *spf != NUL; ++round) {
        if (round == 0) {
            if (int_wordlist == NULL)
                continue;
            int_wordlist_spl (spf_name);
        }
        else {
            copy_option_part (& spf, spf_name, MAXPATHL - 5, ",");
            STRCAT (spf_name, ".spl");
            for (c = 0; c < ga.ga_len; ++c) {
                p = LANGP_ENTRY (ga, c)->lp_slang->sl_fname;
                if (p != NULL && fullpathcmp (spf_name, p, FALSE) == FPC_SAME)
                    break;
            }
            if (c < ga.ga_len)
                continue;
        }
        for (slang = first_lang; slang != NULL; slang = slang->sl_next)
            if (fullpathcmp (spf_name, slang->sl_fname, FALSE) == FPC_SAME)
                break;
        if (slang == NULL) {
            if (round == 0)
                STRCPY (lang, "internal wordlist");
            else {
                vim_strncpy (lang, gettail (spf_name), MAXWLEN);
                p = vim_strchr (lang, '.');
                if (p != NULL)
                    *p = NUL;
            }
            slang = spell_load_file (spf_name, lang, NULL, TRUE);
            if (slang != NULL && nobreak)
                slang->sl_nobreak = TRUE;
        }
        if (slang != NULL && ga_grow (&ga, 1) == OK) {
            region_mask = REGION_ALL;
            if (use_region != NULL && !dont_use_region) {
                c = find_region (slang->sl_regions, use_region);
                if (c != REGION_ALL)
                    region_mask = 1 << c;
                else if (*slang->sl_regions != NUL)
                    region_mask = 0;
            }
            if (region_mask != 0) {
                LANGP_ENTRY (ga, ga.ga_len)->lp_slang = slang;
                LANGP_ENTRY (ga, ga.ga_len)->lp_sallang = NULL;
                LANGP_ENTRY (ga, ga.ga_len)->lp_replang = NULL;
                LANGP_ENTRY (ga, ga.ga_len)->lp_region = region_mask;
                ++ga.ga_len;
                use_midword (slang, wp);
            }
        }
    }
    ga_clear (& wp -> w_s -> b_langp);
    wp->w_s->b_langp = ga;
    for (i = 0; i < ga.ga_len; ++i) {
        lp = LANGP_ENTRY (ga, i);
        if (lp->lp_slang->sl_sal.ga_len > 0)
            lp->lp_sallang = lp->lp_slang;
        else
            for (j = 0; j < ga.ga_len; ++j) {
                lp2 = LANGP_ENTRY (ga, j);
                if (lp2->lp_slang->sl_sal.ga_len > 0 && STRNCMP (lp->lp_slang->sl_name, lp2->lp_slang->sl_name, 2) == 0) {
                    lp->lp_sallang = lp2->lp_slang;
                    break;
                }
            }
        if (lp->lp_slang->sl_rep.ga_len > 0)
            lp->lp_replang = lp->lp_slang;
        else
            for (j = 0; j < ga.ga_len; ++j) {
                lp2 = LANGP_ENTRY (ga, j);
                if (lp2->lp_slang->sl_rep.ga_len > 0 && STRNCMP (lp->lp_slang->sl_name, lp2->lp_slang->sl_name, 2) == 0) {
                    lp->lp_replang = lp2->lp_slang;
                    break;
                }
            }
    }
theend :
    vim_free (spl_copy);
    recursive = FALSE;
    redraw_win_later (wp, NOT_VALID);
    return ret_msg;
}

static void clear_midword (win_T *wp) {
    vim_memset (wp -> w_s -> b_spell_ismw, 0, 256);
}

slang_T *slang_alloc (char_u *lang) {
    slang_T *lp;
    lp = (slang_T *) alloc_clear (sizeof (slang_T));
    if (lp != NULL) {
        if (lang != NULL)
            lp->sl_name = vim_strsave (lang);
        ga_init2 (& lp -> sl_rep, sizeof (fromto_T), 10);
        ga_init2 (& lp -> sl_repsal, sizeof (fromto_T), 10);
        lp->sl_compmax = MAXWLEN;
        lp->sl_compsylmax = MAXWLEN;
        hash_init (& lp -> sl_wordcount);
    }
    return lp;
}

void clear_spell_chartab (spelltab_T *sp) {
    int i;
    vim_memset (sp -> st_isw, FALSE, sizeof (sp -> st_isw));
    vim_memset (sp -> st_isu, FALSE, sizeof (sp -> st_isu));
    for (i = 0; i < 256; ++i) {
        sp->st_fold[i] = i;
        sp->st_upper[i] = i;
    }
    for (i = '0'; i <= '9'; ++i)
        sp->st_isw[i] = TRUE;
    for (i = 'A'; i <= 'Z'; ++i) {
        sp->st_isw[i] = TRUE;
        sp->st_isu[i] = TRUE;
        sp->st_fold[i] = i + 0x20;
    }
    for (i = 'a'; i <= 'z'; ++i) {
        sp->st_isw[i] = TRUE;
        sp->st_upper[i] = i - 0x20;
    }
}

void count_common_word (slang_T *lp, char_u *word, int len, int count) {
    hash_T hash;
    hashitem_T *hi;
    wordcount_T *wc;
    char_u buf [MAXWLEN];
    char_u *p;
    if (len == -1)
        p = word;
    else {
        vim_strncpy (buf, word, len);
        p = buf;
    }
    hash = hash_hash (p);
    hi = hash_lookup (&lp->sl_wordcount, p, hash);
    if (HASHITEM_EMPTY (hi)) {
        wc = (wordcount_T *) alloc ((unsigned ) (sizeof (wordcount_T) + STRLEN (p)));
        if (wc == NULL)
            return;
        STRCPY (wc -> wc_word, p);
        wc->wc_count = count;
        hash_add_item (& lp -> sl_wordcount, hi, wc -> wc_word, hash);
    }
    else {
        wc = HI2WC (hi);
        if ((wc->wc_count += count) < (unsigned ) count)
            wc->wc_count = MAXWORDCOUNT;
    }
}

int byte_in_str (char_u *str, int n) {
    char_u *p;
    for (p = str; *p != NUL; ++p)
        if (*p == n)
            return TRUE;
    return FALSE;
}

#define SY_MAXLEN   30

int init_syl_tab (slang_T *slang) {
    char_u *p;
    char_u *s;
    int l;
    syl_item_T *syl;
    ga_init2 (& slang -> sl_syl_items, sizeof (syl_item_T), 4);
    p = vim_strchr (slang->sl_syllable, '/');
    while (p != NULL) {
        *p++ = NUL;
        if (*p == NUL)
            break;
        s = p;
        p = vim_strchr (p, '/');
        if (p == NULL)
            l = (int) STRLEN (s);
        else
            l = (int) (p - s);
        if (l >= SY_MAXLEN)
            return SP_FORMERROR;
        if (ga_grow (&slang->sl_syl_items, 1) == FAIL)
            return SP_OTHERERROR;
        syl = ((syl_item_T *) slang->sl_syl_items.ga_data) + slang->sl_syl_items.ga_len++;
        vim_strncpy (syl -> sy_chars, s, l);
        syl->sy_len = l;
    }
    return OK;
}

void slang_free (slang_T *lp) {
    vim_free (lp -> sl_name);
    vim_free (lp -> sl_fname);
    slang_clear (lp);
    vim_free (lp);
}

void slang_clear (slang_T *lp) {
    garray_T *gap;
    fromto_T *ftp;
    salitem_T *smp;
    int i;
    int round;
    VIM_CLEAR (lp -> sl_fbyts);
    VIM_CLEAR (lp -> sl_kbyts);
    VIM_CLEAR (lp -> sl_pbyts);
    VIM_CLEAR (lp -> sl_fidxs);
    VIM_CLEAR (lp -> sl_kidxs);
    VIM_CLEAR (lp -> sl_pidxs);
    for (round = 1; round <= 2; ++round) {
        gap = round == 1 ? &lp->sl_rep : &lp->sl_repsal;
        while (gap->ga_len > 0) {
            ftp = &((fromto_T *) gap->ga_data)[--gap->ga_len];
            vim_free (ftp -> ft_from);
            vim_free (ftp -> ft_to);
        }
        ga_clear (gap);
    }
    gap = &lp->sl_sal;
    if (lp->sl_sofo) {
        if (gap->ga_data != NULL)
            for (i = 0; i < gap->ga_len; ++i)
                vim_free (((int **) gap->ga_data)[i]);
    }
    else
        while (gap->ga_len > 0) {
            smp = &((salitem_T *) gap->ga_data)[--gap->ga_len];
            vim_free (smp -> sm_lead);
            vim_free (smp -> sm_to);
        }
    ga_clear (gap);
    for (i = 0; i < lp->sl_prefixcnt; ++i)
        vim_regfree (lp->sl_prefprog[i]);
    lp->sl_prefixcnt = 0;
    VIM_CLEAR (lp -> sl_prefprog);
    VIM_CLEAR (lp -> sl_info);
    VIM_CLEAR (lp -> sl_midword);
    vim_regfree (lp -> sl_compprog);
    lp->sl_compprog = NULL;
    VIM_CLEAR (lp -> sl_comprules);
    VIM_CLEAR (lp -> sl_compstartflags);
    VIM_CLEAR (lp -> sl_compallflags);
    VIM_CLEAR (lp -> sl_syllable);
    ga_clear (& lp -> sl_syl_items);
    ga_clear_strings (& lp -> sl_comppat);
    hash_clear_all (& lp -> sl_wordcount, WC_KEY_OFF);
    hash_init (& lp -> sl_wordcount);
    slang_clear_sug (lp);
    lp->sl_compmax = MAXWLEN;
    lp->sl_compminlen = 0;
    lp->sl_compsylmax = MAXWLEN;
    lp->sl_regions[0] = NUL;
}

void slang_clear_sug (slang_T *lp) {
    VIM_CLEAR (lp -> sl_sbyts);
    VIM_CLEAR (lp -> sl_sidxs);
    close_spellbuf (lp -> sl_sugbuf);
    lp->sl_sugbuf = NULL;
    lp->sl_sugloaded = FALSE;
    lp->sl_sugtime = 0;
}

void close_spellbuf (buf_T *buf) {
    if (buf != NULL) {
        ml_close (buf, TRUE);
        vim_free (buf);
    }
}

static void spell_load_lang (char_u *lang) {
    char_u fname_enc [85];
    int r;
    spelload_T sl;
    int round;
    STRCPY (sl.sl_lang, lang);
    sl.sl_slang = NULL;
    sl.sl_nobreak = FALSE;
    for (round = 1; round <= 2; ++round) {
        vim_snprintf ((char *) fname_enc, sizeof (fname_enc) - 5, "spell/%s.%s.spl", lang, spell_enc ());
        r = do_in_runtimepath (fname_enc, 0, spell_load_cb, &sl);
        if (r == FAIL && *sl.sl_lang != NUL) {
            vim_snprintf ((char *) fname_enc, sizeof (fname_enc) - 5, "spell/%s.ascii.spl", lang);
            r = do_in_runtimepath (fname_enc, 0, spell_load_cb, &sl);
            if (r == FAIL && *sl.sl_lang != NUL && round == 1 && apply_autocmds (EVENT_SPELLFILEMISSING, lang, curbuf->b_fname, FALSE, curbuf))
                continue;
            break;
        }
        break;
    }
    if (r == FAIL) {
        smsg ((char_u *) _ ("Warning: Cannot find word list \"%s.%s.spl\" or \"%s.ascii.spl\""), lang, spell_enc (), lang);
    }
    else if (sl.sl_slang != NULL) {
        STRCPY (fname_enc + STRLEN (fname_enc) - 3, "add.spl");
        do_in_runtimepath (fname_enc, DIP_ALL, spell_load_cb, & sl);
    }
}

static void spell_load_cb (char_u *fname, void *cookie) {
    spelload_T *slp = (spelload_T *) cookie;
    slang_T *slang;
    slang = spell_load_file (fname, slp->sl_lang, NULL, FALSE);
    if (slang != NULL) {
        if (slp->sl_nobreak && slang->sl_add)
            slang->sl_nobreak = TRUE;
        else if (slang->sl_nobreak)
            slp->sl_nobreak = TRUE;
        slp->sl_slang = slang;
    }
}

static int find_region (char_u *rp, char_u *region) {
    int i;
    for (i = 0;; i += 2) {
        if (rp[i] == NUL)
            return REGION_ALL;
        if (rp[i] == region[0] && rp[i + 1] == region[1])
            break;
    }
    return i / 2;
}

static void use_midword (slang_T *lp, win_T *wp) {
    char_u *p;
    if (lp->sl_midword == NULL)
        return;
    for (p = lp->sl_midword; *p != NUL;)
        wp->w_s->b_spell_ismw[*p++] = TRUE;
}

void spell_cat_line (char_u *buf, char_u *line, int maxlen) {
    char_u *p;
    int n;
    p = skipwhite (line);
    while (vim_strchr ((char_u *) "*#/\"\t", *p) != NULL)
        p = skipwhite (p +1);
    if (*p != NUL) {
        n = (int) (p - line) + 1;
        if (n < maxlen - 1) {
            vim_memset (buf, ' ', n);
            vim_strncpy (buf + n, p, maxlen - 1 - n);
        }
    }
}

int spell_move_to (win_T *wp, int dir, int allwords, int curline, hlf_T *attrp) {
    linenr_T lnum;
    pos_T found_pos;
    int found_len = 0;
    char_u *line;
    char_u *p;
    char_u *endp;
    hlf_T attr;
    int len;
    int has_syntax = syntax_present (wp);
    int col;
    int can_spell;
    char_u *buf = NULL;
    int buflen = 0;
    int skip = 0;
    int capcol = -1;
    int found_one = FALSE;
    int wrapped = FALSE;
    if (no_spell_checking (wp))
        return 0;
    lnum = wp->w_cursor.lnum;
    CLEAR_POS (& found_pos);
    while (!got_int) {
        line = ml_get_buf (wp->w_buffer, lnum, FALSE);
        len = (int) STRLEN (line);
        if (buflen < len + MAXWLEN + 2) {
            vim_free (buf);
            buflen = len + MAXWLEN + 2;
            buf = alloc (buflen);
            if (buf == NULL)
                break;
        }
        if (lnum == 1)
            capcol = 0;
        if (capcol == 0)
            capcol = getwhitecols (line);
        else if (curline && wp == curwin) {
            col = getwhitecols (line);
            if (check_need_cap (lnum, col))
                capcol = col;
            line = ml_get_buf (wp->w_buffer, lnum, FALSE);
        }
        STRCPY (buf, line);
        if (lnum < wp->w_buffer->b_ml.ml_line_count)
            spell_cat_line (buf +STRLEN (buf), ml_get_buf (wp->w_buffer, lnum + 1, FALSE), MAXWLEN);
        p = buf + skip;
        endp = buf + len;
        while (p < endp) {
            if (dir == BACKWARD && lnum == wp->w_cursor.lnum && !wrapped && (colnr_T) (p - buf) >= wp->w_cursor.col)
                break;
            attr = HLF_COUNT;
            len = spell_check (wp, p, &attr, &capcol, FALSE);
            if (attr != HLF_COUNT) {
                if (allwords || attr == HLF_SPB) {
                    if (dir == BACKWARD || lnum != wp->w_cursor.lnum || (lnum == wp->w_cursor.lnum && (wrapped || (colnr_T) (curline ? p - buf + len : p - buf) > wp->w_cursor.col))) {
                        if (has_syntax) {
                            col = (int) (p - buf);
                            (void) syn_get_id (wp, lnum, (colnr_T) col, FALSE, &can_spell, FALSE);
                            if (!can_spell)
                                attr = HLF_COUNT;
                        }
                        else
                            can_spell = TRUE;
                        if (can_spell) {
                            found_one = TRUE;
                            found_pos.lnum = lnum;
                            found_pos.col = (int) (p - buf);
                            found_pos.coladd = 0;
                            if (dir == FORWARD) {
                                wp->w_cursor = found_pos;
                                vim_free (buf);
                                if (attrp != NULL)
                                    *attrp = attr;
                                return len;
                            }
                            else if (curline)
                                found_pos.col += len;
                            found_len = len;
                        }
                    }
                    else
                        found_one = TRUE;
                }
            }
            p += len;
            capcol -= len;
        }
        if (dir == BACKWARD && found_pos.lnum != 0) {
            wp->w_cursor = found_pos;
            vim_free (buf);
            return found_len;
        }
        if (curline)
            break;
        if (lnum == wp->w_cursor.lnum && wrapped)
            break;
        if (dir == BACKWARD) {
            if (lnum > 1)
                --lnum;
            else if (!p_ws)
                break;
            else {
                lnum = wp->w_buffer->b_ml.ml_line_count;
                wrapped = TRUE;
                if (!shortmess (SHM_SEARCH))
                    give_warning ((char_u *) _ (top_bot_msg), TRUE);
            }
            capcol = -1;
        }
        else {
            if (lnum < wp->w_buffer->b_ml.ml_line_count)
                ++lnum;
            else if (!p_ws)
                break;
            else {
                lnum = 1;
                wrapped = TRUE;
                if (!shortmess (SHM_SEARCH))
                    give_warning ((char_u *) _ (bot_top_msg), TRUE);
            }
            if (lnum == wp->w_cursor.lnum && !found_one)
                break;
            if (attr == HLF_COUNT)
                skip = (int) (p - endp);
            else
                skip = 0;
            --capcol;
            if (*skipwhite (line) == NUL)
                capcol = 0;
        }
        line_breakcheck ();
    }
    vim_free (buf);
    return 0;
}

static int no_spell_checking (win_T *wp) {
    if (!wp->w_p_spell || *wp->w_s->b_p_spl == NUL || wp->w_s->b_langp.ga_len == 0) {
        EMSG (_ ("E756: Spell checking is not enabled"));
        return TRUE;
    }
    return FALSE;
}

static int check_need_cap (linenr_T lnum, colnr_T col) {
    int need_cap = FALSE;
    char_u *line;
    char_u *line_copy = NULL;
    char_u *p;
    colnr_T endcol;
    regmatch_T regmatch;
    if (curwin->w_s->b_cap_prog == NULL)
        return FALSE;
    line = ml_get_curline ();
    endcol = 0;
    if (getwhitecols (line) >= (int) col) {
        if (lnum == 1)
            need_cap = TRUE;
        else {
            line = ml_get (lnum -1);
            if (*skipwhite (line) == NUL)
                need_cap = TRUE;
            else {
                line_copy = concat_str (line, (char_u *) " ");
                line = line_copy;
                endcol = (colnr_T) STRLEN (line);
            }
        }
    }
    else
        endcol = col;
    if (endcol > 0) {
        regmatch.regprog = curwin->w_s->b_cap_prog;
        regmatch.rm_ic = FALSE;
        p = line + endcol;
        for (;;) {
            MB_PTR_BACK (line, p);
            if (p == line || spell_iswordp_nmw (p, curwin))
                break;
            if (vim_regexec (&regmatch, p, 0) && regmatch.endp[0] == line + endcol) {
                need_cap = TRUE;
                break;
            }
        }
        curwin->w_s->b_cap_prog = regmatch.regprog;
    }
    vim_free (line_copy);
    return need_cap;
}

char_u *spell_to_word_end (char_u *start, win_T *win) {
    char_u *p = start;
    while (*p != NUL && spell_iswordp (p, win))
        MB_PTR_ADV (p);
    return p;
}

void spell_dump_compl (char_u *pat, int ic, int *dir, int dumpflags_arg) {
    langp_T *lp;
    slang_T *slang;
    idx_T arridx [MAXWLEN];
    int curi [MAXWLEN];
    char_u word [MAXWLEN];
    int c;
    char_u *byts;
    idx_T *idxs;
    linenr_T lnum = 0;
    int round;
    int depth;
    int n;
    int flags;
    char_u *region_names = NULL;
    int do_region = TRUE;
    char_u *p;
    int lpi;
    int dumpflags = dumpflags_arg;
    int patlen;
    if (pat != NULL) {
        if (ic)
            dumpflags |= DUMPFLAG_ICASE;
        else {
            n = captype (pat, NULL);
            if (n == WF_ONECAP)
                dumpflags |= DUMPFLAG_ONECAP;
            else if (n == WF_ALLCAP && (int) STRLEN (pat) > 1)
                dumpflags |= DUMPFLAG_ALLCAP;
        }
    }
    for (lpi = 0; lpi < curwin->w_s->b_langp.ga_len; ++lpi) {
        lp = LANGP_ENTRY (curwin->w_s->b_langp, lpi);
        p = lp->lp_slang->sl_regions;
        if (p[0] != 0) {
            if (region_names == NULL)
                region_names = p;
            else if (STRCMP (region_names, p) != 0) {
                do_region = FALSE;
                break;
            }
        }
    }
    if (do_region && region_names != NULL) {
        if (pat == NULL) {
            vim_snprintf ((char *) IObuff, IOSIZE, "/regions=%s", region_names);
            ml_append (lnum ++, IObuff, (colnr_T) 0, FALSE);
        }
    }
    else
        do_region = FALSE;
    for (lpi = 0; lpi < curwin->w_s->b_langp.ga_len; ++lpi) {
        lp = LANGP_ENTRY (curwin->w_s->b_langp, lpi);
        slang = lp->lp_slang;
        if (slang->sl_fbyts == NULL)
            continue;
        if (pat == NULL) {
            vim_snprintf ((char *) IObuff, IOSIZE, "# file: %s", slang -> sl_fname);
            ml_append (lnum ++, IObuff, (colnr_T) 0, FALSE);
        }
        if (pat != NULL && slang->sl_pbyts == NULL)
            patlen = (int) STRLEN (pat);
        else
            patlen = -1;
        for (round = 1; round <= 2; ++round) {
            if (round == 1) {
                dumpflags &= ~DUMPFLAG_KEEPCASE;
                byts = slang->sl_fbyts;
                idxs = slang->sl_fidxs;
            }
            else {
                dumpflags |= DUMPFLAG_KEEPCASE;
                byts = slang->sl_kbyts;
                idxs = slang->sl_kidxs;
            }
            if (byts == NULL)
                continue;
            depth = 0;
            arridx[0] = 0;
            curi[0] = 1;
            while (depth >= 0 && !got_int && (pat == NULL || !compl_interrupted)) {
                if (curi[depth] > byts[arridx[depth]]) {
                    --depth;
                    line_breakcheck ();
                    ins_compl_check_keys (50, FALSE);
                }
                else {
                    n = arridx[depth] + curi[depth];
                    ++curi[depth];
                    c = byts[n];
                    if (c == 0) {
                        flags = (int) idxs[n];
                        if ((round == 2 || (flags & WF_KEEPCAP) == 0) && (flags & WF_NEEDCOMP) == 0 && (do_region || (flags & WF_REGION) == 0 || (((unsigned ) flags >> 16) & lp->lp_region) != 0)) {
                            word[depth] = NUL;
                            if (!do_region)
                                flags &= ~WF_REGION;
                            c = (unsigned ) flags >> 24;
                            if (c == 0 || curi[depth] == 2) {
                                dump_word (slang, word, pat, dir, dumpflags, flags, lnum);
                                if (pat == NULL)
                                    ++lnum;
                            }
                            if (c != 0)
                                lnum = dump_prefixes (slang, word, pat, dir, dumpflags, flags, lnum);
                        }
                    }
                    else {
                        word[depth++] = c;
                        arridx[depth] = idxs[n];
                        curi[depth] = 1;
                        if (depth <= patlen && MB_STRNICMP (word, pat, depth) != 0)
                            --depth;
                    }
                }
            }
        }
    }
}

static void dump_word (slang_T *slang, char_u *word, char_u *pat, int *dir, int dumpflags, int wordflags, linenr_T lnum) {
    int keepcap = FALSE;
    char_u *p;
    char_u *tw;
    char_u cword [MAXWLEN];
    char_u badword [MAXWLEN + 10];
    int i;
    int flags = wordflags;
    if (dumpflags & DUMPFLAG_ONECAP)
        flags |= WF_ONECAP;
    if (dumpflags & DUMPFLAG_ALLCAP)
        flags |= WF_ALLCAP;
    if ((dumpflags & DUMPFLAG_KEEPCASE) == 0 && (flags & WF_CAPMASK) != 0) {
        make_case_word (word, cword, flags);
        p = cword;
    }
    else {
        p = word;
        if ((dumpflags & DUMPFLAG_KEEPCASE) && ((captype (word, NULL) & WF_KEEPCAP) == 0 || (flags & WF_FIXCAP) != 0))
            keepcap = TRUE;
    }
    tw = p;
    if (pat == NULL) {
        if ((flags & (WF_BANNED | WF_RARE | WF_REGION)) || keepcap) {
            STRCPY (badword, p);
            STRCAT (badword, "/");
            if (keepcap)
                STRCAT (badword, "=");
            if (flags & WF_BANNED)
                STRCAT (badword, "!");
            else if (flags & WF_RARE)
                STRCAT (badword, "?");
            if (flags & WF_REGION)
                for (i = 0; i < 7; ++i)
                    if (flags & (0x10000 << i))
                        sprintf ((char *) badword + STRLEN (badword), "%d", i +1);
            p = badword;
        }
        if (dumpflags & DUMPFLAG_COUNT) {
            hashitem_T *hi;
            hi = hash_find (&slang->sl_wordcount, tw);
            if (!HASHITEM_EMPTY (hi)) {
                vim_snprintf ((char *) IObuff, IOSIZE, "%s\t%d", tw, HI2WC (hi) -> wc_count);
                p = IObuff;
            }
        }
        ml_append (lnum, p, (colnr_T) 0, FALSE);
    }
    else if (((dumpflags & DUMPFLAG_ICASE) ? MB_STRNICMP (p, pat, STRLEN (pat)) == 0 : STRNCMP (p, pat, STRLEN (pat)) == 0) && ins_compl_add_infercase (p, (int) STRLEN (p), p_ic, NULL, *dir, 0) == OK)
        *dir = FORWARD;
}

static void make_case_word (char_u *fword, char_u *cword, int flags) {
    if (flags & WF_ALLCAP)
        allcap_copy (fword, cword);
    else if (flags & WF_ONECAP)
        onecap_copy (fword, cword, TRUE);
    else
        STRCPY (cword, fword);
}

static void allcap_copy (char_u *word, char_u *wcopy) {
    char_u *s;
    char_u *d;
    int c;
    d = wcopy;
    for (s = word; *s != NUL;) {
        c = *s++;
        c = SPELL_TOUPPER (c);
        {
            if (d - wcopy >= MAXWLEN - 1)
                break;
            *d++ = c;
        }
    }
    *d = NUL;
}

void onecap_copy (char_u *word, char_u *wcopy, int upper) {
    char_u *p;
    int c;
    int l;
    p = word;
    c = *p++;
    if (upper)
        c = SPELL_TOUPPER (c);
    else
        c = SPELL_TOFOLD (c);
    {
        l = 1;
        wcopy[0] = c;
    }
    vim_strncpy (wcopy + l, p, MAXWLEN - l - 1);
}

static linenr_T dump_prefixes (slang_T *slang, char_u *word, char_u *pat, int *dir, int dumpflags, int flags, linenr_T startlnum) {
    idx_T arridx [MAXWLEN];
    int curi [MAXWLEN];
    char_u prefix [MAXWLEN];
    char_u word_up [MAXWLEN];
    int has_word_up = FALSE;
    int c;
    char_u *byts;
    idx_T *idxs;
    linenr_T lnum = startlnum;
    int depth;
    int n;
    int len;
    int i;
    c = PTR2CHAR (word);
    if (SPELL_TOUPPER (c) != c) {
        onecap_copy (word, word_up, TRUE);
        has_word_up = TRUE;
    }
    byts = slang->sl_pbyts;
    idxs = slang->sl_pidxs;
    if (byts != NULL) {
        depth = 0;
        arridx[0] = 0;
        curi[0] = 1;
        while (depth >= 0 && !got_int) {
            n = arridx[depth];
            len = byts[n];
            if (curi[depth] > len) {
                --depth;
                line_breakcheck ();
            }
            else {
                n += curi[depth];
                ++curi[depth];
                c = byts[n];
                if (c == 0) {
                    for (i = 1; i < len; ++i)
                        if (byts[n + i] != 0)
                            break;
                    curi[depth] += i - 1;
                    c = valid_word_prefix (i, n, flags, word, slang, FALSE);
                    if (c != 0) {
                        vim_strncpy (prefix + depth, word, MAXWLEN - depth - 1);
                        dump_word (slang, prefix, pat, dir, dumpflags, (c & WF_RAREPFX) ? (flags | WF_RARE) : flags, lnum);
                        if (lnum != 0)
                            ++lnum;
                    }
                    if (has_word_up) {
                        c = valid_word_prefix (i, n, flags, word_up, slang, TRUE);
                        if (c != 0) {
                            vim_strncpy (prefix + depth, word_up, MAXWLEN - depth - 1);
                            dump_word (slang, prefix, pat, dir, dumpflags, (c & WF_RAREPFX) ? (flags | WF_RARE) : flags, lnum);
                            if (lnum != 0)
                                ++lnum;
                        }
                    }
                }
                else {
                    prefix[depth++] = c;
                    arridx[depth] = idxs[n];
                    curi[depth] = 1;
                }
            }
        }
    }
    return lnum;
}

int expand_spelling (linenr_T lnum, char_u *pat, char_u ***matchp) {
    garray_T ga;
    spell_suggest_list (& ga, pat, 100, spell_expand_need_cap, TRUE);
    *matchp = ga.ga_data;
    return ga.ga_len;
}

void spell_suggest_list (garray_T *gap, char_u *word, int maxcount, int need_cap, int interactive) {
    suginfo_T sug;
    int i;
    suggest_T *stp;
    char_u *wcopy;
    spell_find_suggest (word, 0, & sug, maxcount, FALSE, need_cap, interactive);
    ga_init2 (gap, sizeof (char_u *), sug.su_ga.ga_len + 1);
    if (ga_grow (gap, sug.su_ga.ga_len) == OK) {
        for (i = 0; i < sug.su_ga.ga_len; ++i) {
            stp = &SUG (sug.su_ga, i);
            wcopy = alloc (stp->st_wordlen + (unsigned ) STRLEN (sug.su_badptr + stp->st_orglen) + 1);
            if (wcopy == NULL)
                break;
            STRCPY (wcopy, stp -> st_word);
            STRCPY (wcopy + stp -> st_wordlen, sug.su_badptr + stp -> st_orglen);
            ((char_u **) gap->ga_data)[gap->ga_len++] = wcopy;
        }
    }
    spell_find_cleanup (& sug);
}

static void spell_find_suggest (char_u *badptr, int badlen, suginfo_T *su, int maxcount, int banbadword, int need_cap, int interactive) {
    hlf_T attr = HLF_COUNT;
    char_u buf [MAXPATHL];
    char_u *p;
    int do_combine = FALSE;
    char_u *sps_copy;
    static int expr_busy = FALSE;
    int c;
    int i;
    langp_T *lp;
    vim_memset (su, 0, sizeof (suginfo_T));
    ga_init2 (& su -> su_ga, (int) sizeof (suggest_T), 10);
    ga_init2 (& su -> su_sga, (int) sizeof (suggest_T), 10);
    if (*badptr == NUL)
        return;
    hash_init (& su -> su_banned);
    su->su_badptr = badptr;
    if (badlen != 0)
        su->su_badlen = badlen;
    else
        su->su_badlen = spell_check (curwin, su->su_badptr, &attr, NULL, FALSE);
    su->su_maxcount = maxcount;
    su->su_maxscore = SCORE_MAXINIT;
    if (su->su_badlen >= MAXWLEN)
        su->su_badlen = MAXWLEN - 1;
    vim_strncpy (su -> su_badword, su -> su_badptr, su -> su_badlen);
    (void) spell_casefold (su->su_badptr, su->su_badlen, su->su_fbadword, MAXWLEN);
    su->su_fbadword[su->su_badlen] = NUL;
    su->su_badflags = badword_captype (su->su_badptr, su->su_badptr + su->su_badlen);
    if (need_cap)
        su->su_badflags |= WF_ONECAP;
    for (i = 0; i < curbuf->b_s.b_langp.ga_len; ++i) {
        lp = LANGP_ENTRY (curbuf->b_s.b_langp, i);
        if (lp->lp_sallang != NULL) {
            su->su_sallang = lp->lp_sallang;
            break;
        }
    }
    if (su->su_sallang != NULL)
        spell_soundfold (su->su_sallang, su->su_fbadword, TRUE, su->su_sal_badword);
    c = PTR2CHAR (su->su_badptr);
    if (!SPELL_ISUPPER (c) && attr == HLF_COUNT) {
        make_case_word (su -> su_badword, buf, WF_ONECAP);
        add_suggestion (su, & su -> su_ga, buf, su -> su_badlen, SCORE_ICASE, 0, TRUE, su -> su_sallang, FALSE);
    }
    if (banbadword)
        add_banned (su, su->su_badword);
    sps_copy = vim_strsave (p_sps);
    if (sps_copy == NULL)
        return;
    for (p = sps_copy; *p != NUL;) {
        copy_option_part (& p, buf, MAXPATHL, ",");
        if (STRNCMP (buf, "expr:", 5) == 0) {
            if (!expr_busy) {
                expr_busy = TRUE;
                spell_suggest_expr (su, buf + 5);
                expr_busy = FALSE;
            }
        }
        else if (STRNCMP (buf, "file:", 5) == 0)
            spell_suggest_file (su, buf +5);
        else {
            spell_suggest_intern (su, interactive);
            if (sps_flags & SPS_DOUBLE)
                do_combine = TRUE;
        }
    }
    vim_free (sps_copy);
    if (do_combine)
        score_combine (su);
}

static int badword_captype (char_u *word, char_u *end) {
    int flags = captype (word, end);
    int c;
    int l, u;
    int first;
    char_u *p;
    if (flags & WF_KEEPCAP) {
        l = u = 0;
        first = FALSE;
        for (p = word; p < end; MB_PTR_ADV (p)) {
            c = PTR2CHAR (p);
            if (SPELL_ISUPPER (c)) {
                ++u;
                if (p == word)
                    first = TRUE;
            }
            else
                ++l;
        }
        if (u > l && u > 2)
            flags |= WF_ALLCAP;
        else if (first)
            flags |= WF_ONECAP;
        if (u >= 2 && l >= 2)
            flags |= WF_MIXCAP;
    }
    return flags;
}

void spell_soundfold (slang_T *slang, char_u *inword, int folded, char_u *res) {
    char_u fword [MAXWLEN];
    char_u *word;
    if (slang->sl_sofo)
        spell_soundfold_sofo (slang, inword, res);
    else {
        if (folded)
            word = inword;
        else {
            (void) spell_casefold (inword, (int) STRLEN (inword), fword, MAXWLEN);
            word = fword;
        }
        spell_soundfold_sal (slang, word, res);
    }
}

static void spell_soundfold_sofo (slang_T *slang, char_u *inword, char_u *res) {
    char_u *s;
    int ri = 0;
    int c;
    {
        for (s = inword; (c = *s) != NUL; ++s) {
            if (VIM_ISWHITE (c))
                c = ' ';
            else
                c = slang->sl_sal_first[c];
            if (c != NUL && (ri == 0 || res[ri - 1] != c))
                res[ri++] = c;
        }
    }
    res[ri] = NUL;
}

static void spell_soundfold_sal (slang_T *slang, char_u *inword, char_u *res) {
    salitem_T *smp;
    char_u word [MAXWLEN];
    char_u *s = inword;
    char_u *t;
    char_u *pf;
    int i, j, z;
    int reslen;
    int n, k = 0;
    int z0;
    int k0;
    int n0;
    int c;
    int pri;
    int p0 = -333;
    int c0;
    if (slang->sl_rem_accents) {
        t = word;
        while (*s != NUL) {
            if (VIM_ISWHITE (*s)) {
                *t++ = ' ';
                s = skipwhite (s);
            }
            else {
                if (spell_iswordp_nmw (s, curwin))
                    *t++ = *s;
                ++s;
            }
        }
        *t = NUL;
    }
    else
        vim_strncpy (word, s, MAXWLEN -1);
    smp = (salitem_T *) slang->sl_sal.ga_data;
    i = reslen = z = 0;
    while ((c = word[i]) != NUL) {
        n = slang->sl_sal_first[c];
        z0 = 0;
        if (n >= 0) {
            for (; (s = smp[n].sm_lead)[0] == c; ++n) {
                k = smp[n].sm_leadlen;
                if (k > 1) {
                    if (word[i + 1] != s[1])
                        continue;
                    if (k > 2) {
                        for (j = 2; j < k; ++j)
                            if (word[i + j] != s[j])
                                break;
                        if (j < k)
                            continue;
                    }
                }
                if ((pf = smp[n].sm_oneof) != NULL) {
                    while (*pf != NUL && *pf != word[i + k])
                        ++pf;
                    if (*pf == NUL)
                        continue;
                    ++k;
                }
                s = smp[n].sm_rules;
                pri = 5;
                p0 = *s;
                k0 = k;
                while (*s == '-' && k > 1) {
                    k--;
                    s++;
                }
                if (*s == '<')
                    s++;
                if (VIM_ISDIGIT (*s)) {
                    pri = *s - '0';
                    s++;
                }
                if (*s == '^' && *(s + 1) == '^')
                    s++;
                if (*s == NUL || (*s == '^' && (i == 0 || !(word[i - 1] == ' ' || spell_iswordp (word +i - 1, curwin))) && (*(s + 1) != '$' || (!spell_iswordp (word +i + k0, curwin)))) || (*s == '$' && i > 0 && spell_iswordp (word +i - 1, curwin) && (!spell_iswordp (word +i + k0, curwin)))) {
                    c0 = word[i + k - 1];
                    n0 = slang->sl_sal_first[c0];
                    if (slang->sl_followup && k > 1 && n0 >= 0 && p0 != '-' && word[i + k] != NUL) {
                        for (; (s = smp[n0].sm_lead)[0] == c0; ++n0) {
                            k0 = smp[n0].sm_leadlen;
                            if (k0 > 1) {
                                if (word[i + k] != s[1])
                                    continue;
                                if (k0 > 2) {
                                    pf = word + i + k + 1;
                                    for (j = 2; j < k0; ++j)
                                        if (*pf++ != s[j])
                                            break;
                                    if (j < k0)
                                        continue;
                                }
                            }
                            k0 += k - 1;
                            if ((pf = smp[n0].sm_oneof) != NULL) {
                                while (*pf != NUL && *pf != word[i + k0])
                                    ++pf;
                                if (*pf == NUL)
                                    continue;
                                ++k0;
                            }
                            p0 = 5;
                            s = smp[n0].sm_rules;
                            while (*s == '-') {
                                s++;
                            }
                            if (*s == '<')
                                s++;
                            if (VIM_ISDIGIT (*s)) {
                                p0 = *s - '0';
                                s++;
                            }
                            if (*s == NUL || (*s == '$' && !spell_iswordp (word +i + k0, curwin))) {
                                if (k0 == k)
                                    continue;
                                if (p0 < pri)
                                    continue;
                                break;
                            }
                        }
                        if (p0 >= pri && smp[n0].sm_lead[0] == c0)
                            continue;
                    }
                    s = smp[n].sm_to;
                    if (s == NULL)
                        s = (char_u *) "";
                    pf = smp[n].sm_rules;
                    p0 = (vim_strchr (pf, '<') != NULL) ? 1 : 0;
                    if (p0 == 1 && z == 0) {
                        if (reslen > 0 && *s != NUL && (res[reslen - 1] == c || res[reslen - 1] == *s))
                            reslen--;
                        z0 = 1;
                        z = 1;
                        k0 = 0;
                        while (*s != NUL && word[i + k0] != NUL) {
                            word[i + k0] = *s;
                            k0++;
                            s++;
                        }
                        if (k > k0)
                            STRMOVE (word +i + k0, word +i + k);
                        c = word[i];
                    }
                    else {
                        i += k - 1;
                        z = 0;
                        while (*s != NUL && s[1] != NUL && reslen < MAXWLEN) {
                            if (reslen == 0 || res[reslen - 1] != *s)
                                res[reslen++] = *s;
                            s++;
                        }
                        c = *s;
                        if (strstr ((char *) pf, "^^") != NULL) {
                            if (c != NUL)
                                res[reslen++] = c;
                            STRMOVE (word, word + i + 1);
                            i = 0;
                            z0 = 1;
                        }
                    }
                    break;
                }
            }
        }
        else if (VIM_ISWHITE (c)) {
            c = ' ';
            k = 1;
        }
        if (z0 == 0) {
            if (k && !p0 && reslen < MAXWLEN && c != NUL && (!slang->sl_collapse || reslen == 0 || res[reslen - 1] != c))
                res[reslen++] = c;
            i++;
            z = 0;
            k = 0;
        }
    }
    res[reslen] = NUL;
}

static void add_suggestion (suginfo_T *su, garray_T *gap, char_u *goodword, int badlenarg, int score, int altscore, int had_bonus, slang_T *slang, int maxsf) {
    int goodlen;
    int badlen;
    suggest_T *stp;
    suggest_T new_sug;
    int i;
    char_u *pgood, *pbad;
    pgood = goodword + STRLEN (goodword);
    pbad = su->su_badptr + badlenarg;
    for (;;) {
        goodlen = (int) (pgood - goodword);
        badlen = (int) (pbad - su->su_badptr);
        if (goodlen <= 0 || badlen <= 0)
            break;
        MB_PTR_BACK (goodword, pgood);
        MB_PTR_BACK (su -> su_badptr, pbad);
        if (*pgood != *pbad)
            break;
    }
    if (badlen == 0 && goodlen == 0)
        return;
    if (gap->ga_len == 0)
        i = -1;
    else {
        stp = &SUG (*gap, 0);
        for (i = gap->ga_len; --i >= 0; ++stp)
            if (stp->st_wordlen == goodlen && stp->st_orglen == badlen && STRNCMP (stp->st_word, goodword, goodlen) == 0) {
                if (stp->st_slang == NULL)
                    stp->st_slang = slang;
                new_sug.st_score = score;
                new_sug.st_altscore = altscore;
                new_sug.st_had_bonus = had_bonus;
                if (stp->st_had_bonus != had_bonus) {
                    if (had_bonus)
                        rescore_one (su, stp);
                    else {
                        new_sug.st_word = stp->st_word;
                        new_sug.st_wordlen = stp->st_wordlen;
                        new_sug.st_slang = stp->st_slang;
                        new_sug.st_orglen = badlen;
                        rescore_one (su, & new_sug);
                    }
                }
                if (stp->st_score > new_sug.st_score) {
                    stp->st_score = new_sug.st_score;
                    stp->st_altscore = new_sug.st_altscore;
                    stp->st_had_bonus = new_sug.st_had_bonus;
                }
                break;
            }
    }
    if (i < 0 && ga_grow (gap, 1) == OK) {
        stp = &SUG (*gap, gap->ga_len);
        stp->st_word = vim_strnsave (goodword, goodlen);
        if (stp->st_word != NULL) {
            stp->st_wordlen = goodlen;
            stp->st_score = score;
            stp->st_altscore = altscore;
            stp->st_had_bonus = had_bonus;
            stp->st_orglen = badlen;
            stp->st_slang = slang;
            ++gap->ga_len;
            if (gap->ga_len > SUG_MAX_COUNT (su)) {
                if (maxsf)
                    su->su_sfmaxscore = cleanup_suggestions (gap, su->su_sfmaxscore, SUG_CLEAN_COUNT (su));
                else
                    su->su_maxscore = cleanup_suggestions (gap, su->su_maxscore, SUG_CLEAN_COUNT (su));
            }
        }
    }
}

static void rescore_one (suginfo_T *su, suggest_T *stp) {
    slang_T *slang = stp->st_slang;
    char_u sal_badword [MAXWLEN];
    char_u *p;
    if (slang != NULL && slang->sl_sal.ga_len > 0 && !stp->st_had_bonus) {
        if (slang == su->su_sallang)
            p = su->su_sal_badword;
        else {
            spell_soundfold (slang, su -> su_fbadword, TRUE, sal_badword);
            p = sal_badword;
        }
        stp->st_altscore = stp_sal_score (stp, su, slang, p);
        if (stp->st_altscore == SCORE_MAXMAX)
            stp->st_altscore = SCORE_BIG;
        stp->st_score = RESCORE (stp->st_score, stp->st_altscore);
        stp->st_had_bonus = TRUE;
    }
}

static int stp_sal_score (suggest_T *stp, suginfo_T *su, slang_T *slang, char_u *badsound) {
    char_u *p;
    char_u *pbad;
    char_u *pgood;
    char_u badsound2 [MAXWLEN];
    char_u fword [MAXWLEN];
    char_u goodsound [MAXWLEN];
    char_u goodword [MAXWLEN];
    int lendiff;
    lendiff = (int) (su->su_badlen - stp->st_orglen);
    if (lendiff >= 0)
        pbad = badsound;
    else {
        (void) spell_casefold (su->su_badptr, stp->st_orglen, fword, MAXWLEN);
        if (VIM_ISWHITE (su->su_badptr[su->su_badlen]) && *skiptowhite (stp->st_word) == NUL)
            for (p = fword; *(p = skiptowhite (p)) != NUL;)
                STRMOVE (p, p +1);
        spell_soundfold (slang, fword, TRUE, badsound2);
        pbad = badsound2;
    }
    if (lendiff > 0 && stp->st_wordlen + lendiff < MAXWLEN) {
        STRCPY (goodword, stp -> st_word);
        vim_strncpy (goodword + stp -> st_wordlen, su -> su_badptr + su -> su_badlen - lendiff, lendiff);
        pgood = goodword;
    }
    else
        pgood = stp->st_word;
    spell_soundfold (slang, pgood, FALSE, goodsound);
    return soundalike_score (goodsound, pbad);
}

static int soundalike_score (char_u *goodstart, char_u *badstart) {
    char_u *goodsound = goodstart;
    char_u *badsound = badstart;
    int goodlen;
    int badlen;
    int n;
    char_u *pl, *ps;
    char_u *pl2, *ps2;
    int score = 0;
    if ((*badsound == '*' || *goodsound == '*') && *badsound != *goodsound) {
        if ((badsound[0] == NUL && goodsound[1] == NUL) || (goodsound[0] == NUL && badsound[1] == NUL))
            return SCORE_DEL;
        if (badsound[0] == NUL || goodsound[0] == NUL)
            return SCORE_MAXMAX;
        if (badsound[1] == goodsound[1] || (badsound[1] != NUL && goodsound[1] != NUL && badsound[2] == goodsound[2])) {
        }
        else {
            score = 2 * SCORE_DEL / 3;
            if (*badsound == '*')
                ++badsound;
            else
                ++goodsound;
        }
    }
    goodlen = (int) STRLEN (goodsound);
    badlen = (int) STRLEN (badsound);
    n = goodlen - badlen;
    if (n < -2 || n > 2)
        return SCORE_MAXMAX;
    if (n > 0) {
        pl = goodsound;
        ps = badsound;
    }
    else {
        pl = badsound;
        ps = goodsound;
    }
    while (*pl == *ps && *pl != NUL) {
        ++pl;
        ++ps;
    }
    switch (n) {
    case -2 :
    case 2 :
        ++pl;
        while (*pl == *ps) {
            ++pl;
            ++ps;
        }
        if (STRCMP (pl +1, ps) == 0)
            return score + SCORE_DEL * 2;
        break;
    case -1 :
    case 1 :
        pl2 = pl + 1;
        ps2 = ps;
        while (*pl2 == *ps2) {
            if (*pl2 == NUL)
                return score + SCORE_DEL;
            ++pl2;
            ++ps2;
        }
        if (pl2[0] == ps2[1] && pl2[1] == ps2[0] && STRCMP (pl2 +2, ps2 +2) == 0)
            return score + SCORE_DEL + SCORE_SWAP;
        if (STRCMP (pl2 +1, ps2 +1) == 0)
            return score + SCORE_DEL + SCORE_SUBST;
        if (pl[0] == ps[1] && pl[1] == ps[0]) {
            pl2 = pl + 2;
            ps2 = ps + 2;
            while (*pl2 == *ps2) {
                ++pl2;
                ++ps2;
            }
            if (STRCMP (pl2 +1, ps2) == 0)
                return score + SCORE_SWAP + SCORE_DEL;
        }
        pl2 = pl + 1;
        ps2 = ps + 1;
        while (*pl2 == *ps2) {
            ++pl2;
            ++ps2;
        }
        if (STRCMP (pl2 +1, ps2) == 0)
            return score + SCORE_SUBST + SCORE_DEL;
        break;
    case 0 :
        if (*pl == NUL)
            return score;
        if (pl[0] == ps[1] && pl[1] == ps[0]) {
            pl2 = pl + 2;
            ps2 = ps + 2;
            while (*pl2 == *ps2) {
                if (*pl2 == NUL)
                    return score + SCORE_SWAP;
                ++pl2;
                ++ps2;
            }
            if (pl2[0] == ps2[1] && pl2[1] == ps2[0] && STRCMP (pl2 +2, ps2 +2) == 0)
                return score + SCORE_SWAP + SCORE_SWAP;
            if (STRCMP (pl2 +1, ps2 +1) == 0)
                return score + SCORE_SWAP + SCORE_SUBST;
        }
        pl2 = pl + 1;
        ps2 = ps + 1;
        while (*pl2 == *ps2) {
            if (*pl2 == NUL)
                return score + SCORE_SUBST;
            ++pl2;
            ++ps2;
        }
        if (pl2[0] == ps2[1] && pl2[1] == ps2[0] && STRCMP (pl2 +2, ps2 +2) == 0)
            return score + SCORE_SUBST + SCORE_SWAP;
        if (STRCMP (pl2 +1, ps2 +1) == 0)
            return score + SCORE_SUBST + SCORE_SUBST;
        pl2 = pl;
        ps2 = ps + 1;
        while (*pl2 == *ps2) {
            ++pl2;
            ++ps2;
        }
        if (STRCMP (pl2 +1, ps2) == 0)
            return score + SCORE_INS + SCORE_DEL;
        pl2 = pl + 1;
        ps2 = ps;
        while (*pl2 == *ps2) {
            ++pl2;
            ++ps2;
        }
        if (STRCMP (pl2, ps2 +1) == 0)
            return score + SCORE_INS + SCORE_DEL;
        break;
    }
    return SCORE_MAXMAX;
}

static int cleanup_suggestions (garray_T *gap, int maxscore, int keep) {
    suggest_T *stp = &SUG (*gap, 0);
    int i;
    qsort (gap -> ga_data, (size_t) gap -> ga_len, sizeof (suggest_T), sug_compare);
    if (gap->ga_len > keep) {
        for (i = keep; i < gap->ga_len; ++i)
            vim_free (stp[i].st_word);
        gap->ga_len = keep;
        return stp[keep - 1].st_score;
    }
    return maxscore;
}

static int sug_compare (const void *s1, const void *s2) {
    suggest_T *p1 = (suggest_T *) s1;
    suggest_T *p2 = (suggest_T *) s2;
    int n = p1->st_score - p2->st_score;
    if (n == 0) {
        n = p1->st_altscore - p2->st_altscore;
        if (n == 0)
            n = STRICMP (p1->st_word, p2->st_word);
    }
    return n;
}

static void add_banned (suginfo_T *su, char_u *word) {
    char_u *s;
    hash_T hash;
    hashitem_T *hi;
    hash = hash_hash (word);
    hi = hash_lookup (&su->su_banned, word, hash);
    if (HASHITEM_EMPTY (hi)) {
        s = vim_strsave (word);
        if (s != NULL)
            hash_add_item (&su->su_banned, hi, s, hash);
    }
}

static void spell_suggest_expr (suginfo_T *su, char_u *expr) {
    list_T *list;
    listitem_T *li;
    int score;
    char_u *p;
    list = eval_spell_expr (su->su_badword, expr);
    if (list != NULL) {
        for (li = list->lv_first; li != NULL; li = li->li_next)
            if (li->li_tv.v_type == VAR_LIST) {
                score = get_spellword (li->li_tv.vval.v_list, &p);
                if (score >= 0 && score <= su->su_maxscore)
                    add_suggestion (su, &su->su_ga, p, su->su_badlen, score, 0, TRUE, su->su_sallang, FALSE);
            }
        list_unref (list);
    }
    check_suggestions (su, & su -> su_ga);
    (void) cleanup_suggestions (&su->su_ga, su->su_maxscore, su->su_maxcount);
}

static void check_suggestions (suginfo_T *su, garray_T *gap) {
    suggest_T *stp;
    int i;
    char_u longword [MAXWLEN + 1];
    int len;
    hlf_T attr;
    stp = &SUG (*gap, 0);
    for (i = gap->ga_len - 1; i >= 0; --i) {
        vim_strncpy (longword, stp [i].st_word, MAXWLEN);
        len = stp[i].st_wordlen;
        vim_strncpy (longword + len, su -> su_badptr + stp [i].st_orglen, MAXWLEN - len);
        attr = HLF_COUNT;
        (void) spell_check (curwin, longword, &attr, NULL, FALSE);
        if (attr != HLF_COUNT) {
            vim_free (stp [i].st_word);
            --gap->ga_len;
            if (i < gap->ga_len)
                mch_memmove (stp +i, stp +i + 1, sizeof (suggest_T) * (gap->ga_len - i));
        }
    }
}

static void spell_suggest_file (suginfo_T *su, char_u *fname) {
    FILE *fd;
    char_u line [MAXWLEN * 2];
    char_u *p;
    int len;
    char_u cword [MAXWLEN];
    fd = mch_fopen ((char *) fname, "r");
    if (fd == NULL) {
        EMSG2 (_ (e_notopen), fname);
        return;
    }
    while (!vim_fgets (line, MAXWLEN *2, fd) && !got_int) {
        line_breakcheck ();
        p = vim_strchr (line, '/');
        if (p == NULL)
            continue;
        *p++ = NUL;
        if (STRICMP (su->su_badword, line) == 0) {
            for (len = 0; p[len] >= ' '; ++len)
                ;
            p[len] = NUL;
            if (captype (p, NULL) == 0) {
                make_case_word (p, cword, su -> su_badflags);
                p = cword;
            }
            add_suggestion (su, & su -> su_ga, p, su -> su_badlen, SCORE_FILE, 0, TRUE, su -> su_sallang, FALSE);
        }
    }
    fclose (fd);
    check_suggestions (su, & su -> su_ga);
    (void) cleanup_suggestions (&su->su_ga, su->su_maxscore, su->su_maxcount);
}

static void spell_suggest_intern (suginfo_T *su, int interactive) {
    suggest_load_files ();
    suggest_try_special (su);
    suggest_try_change (su);
    if (sps_flags & SPS_DOUBLE)
        score_comp_sal (su);
    if ((sps_flags & SPS_FAST) == 0) {
        if (sps_flags & SPS_BEST)
            rescore_suggestions (su);
        suggest_try_soundalike_prep ();
        su->su_maxscore = SCORE_SFMAX1;
        su->su_sfmaxscore = SCORE_MAXINIT * 3;
        suggest_try_soundalike (su);
        if (su->su_ga.ga_len < SUG_CLEAN_COUNT (su)) {
            su->su_maxscore = SCORE_SFMAX2;
            suggest_try_soundalike (su);
            if (su->su_ga.ga_len < SUG_CLEAN_COUNT (su)) {
                su->su_maxscore = SCORE_SFMAX3;
                suggest_try_soundalike (su);
            }
        }
        su->su_maxscore = su->su_sfmaxscore;
        suggest_try_soundalike_finish ();
    }
    ui_breakcheck ();
    if (interactive && got_int) {
        (void) vgetc ();
        got_int = FALSE;
    }
    if ((sps_flags & SPS_DOUBLE) == 0 && su->su_ga.ga_len != 0) {
        if (sps_flags & SPS_BEST)
            rescore_suggestions (su);
        check_suggestions (su, & su -> su_ga);
        (void) cleanup_suggestions (&su->su_ga, su->su_maxscore, su->su_maxcount);
    }
}

buf_T *open_spellbuf (void) {
    buf_T *buf;
    buf = (buf_T *) alloc_clear (sizeof (buf_T));
    if (buf != NULL) {
        buf->b_spell = TRUE;
        buf->b_p_swf = TRUE;
        buf->b_p_key = empty_option;
        ml_open (buf);
        ml_open_file (buf);
    }
    return buf;
}

static void suggest_try_special (suginfo_T *su) {
    char_u *p;
    size_t len;
    int c;
    char_u word [MAXWLEN];
    p = skiptowhite (su->su_fbadword);
    len = p - su->su_fbadword;
    p = skipwhite (p);
    if (STRLEN (p) == len && STRNCMP (su->su_fbadword, p, len) == 0) {
        c = su->su_fbadword[len];
        su->su_fbadword[len] = NUL;
        make_case_word (su -> su_fbadword, word, su -> su_badflags);
        su->su_fbadword[len] = c;
        add_suggestion (su, & su -> su_ga, word, su -> su_badlen, RESCORE (SCORE_REP, 0), 0, TRUE, su -> su_sallang, FALSE);
    }
}

# define PROF_STORE(state)

static void suggest_try_change (suginfo_T *su) {
    char_u fword [MAXWLEN];
    int n;
    char_u *p;
    int lpi;
    langp_T *lp;
    STRCPY (fword, su -> su_fbadword);
    n = (int) STRLEN (fword);
    p = su->su_badptr + su->su_badlen;
    (void) spell_casefold (p, (int) STRLEN (p), fword +n, MAXWLEN -n);
    for (lpi = 0; lpi < curwin->w_s->b_langp.ga_len; ++lpi) {
        lp = LANGP_ENTRY (curwin->w_s->b_langp, lpi);
        if (lp->lp_slang->sl_fbyts == NULL)
            continue;
        suggest_trie_walk (su, lp, fword, FALSE);
    }
}

#define TRY_DEEPER(su, stack, depth, add) \
		(stack[depth].ts_score + (add) < su->su_maxscore)

static void suggest_trie_walk (suginfo_T *su, langp_T *lp, char_u *fword, int soundfold) {
    char_u tword [MAXWLEN];
    trystate_T stack [MAXWLEN];
    char_u preword [MAXWLEN * 3];
    char_u compflags [MAXWLEN];
    trystate_T *sp;
    int newscore;
    int score;
    char_u *byts, *fbyts, *pbyts;
    idx_T *idxs, *fidxs, *pidxs;
    int depth;
    int c, c2, c3;
    int n = 0;
    int flags;
    garray_T *gap;
    idx_T arridx;
    int len;
    char_u *p;
    fromto_T *ftp;
    int fl = 0, tl;
    int repextra = 0;
    slang_T *slang = lp->lp_slang;
    int fword_ends;
    int goodword_ends;
    int breakcheckcount = 1000;
    int compound_ok;
    depth = 0;
    sp = &stack[0];
    vim_memset (sp, 0, sizeof (trystate_T));
    sp->ts_curi = 1;
    if (soundfold) {
        byts = fbyts = slang->sl_sbyts;
        idxs = fidxs = slang->sl_sidxs;
        pbyts = NULL;
        pidxs = NULL;
        sp->ts_prefixdepth = PFD_NOPREFIX;
        sp->ts_state = STATE_START;
    }
    else {
        fbyts = slang->sl_fbyts;
        fidxs = slang->sl_fidxs;
        pbyts = slang->sl_pbyts;
        pidxs = slang->sl_pidxs;
        if (pbyts != NULL) {
            byts = pbyts;
            idxs = pidxs;
            sp->ts_prefixdepth = PFD_PREFIXTREE;
            sp->ts_state = STATE_NOPREFIX;
        }
        else {
            byts = fbyts;
            idxs = fidxs;
            sp->ts_prefixdepth = PFD_NOPREFIX;
            sp->ts_state = STATE_START;
        }
    }
    while (depth >= 0 && !got_int) {
        sp = &stack[depth];
        switch (sp->ts_state) {
        case STATE_START :
        case STATE_NOPREFIX :
            arridx = sp->ts_arridx;
            len = byts[arridx];
            arridx += sp->ts_curi;
            if (sp->ts_prefixdepth == PFD_PREFIXTREE) {
                for (n = 0; n < len && byts[arridx + n] == 0; ++n)
                    ;
                sp->ts_curi += n;
                n = (int) sp->ts_state;
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_ENDNUL;
                sp->ts_save_badflags = su->su_badflags;
                if (byts[arridx] == 0 || n == (int) STATE_NOPREFIX) {
                    n = sp->ts_fidx;
                    flags = badword_captype (su->su_badptr, su->su_badptr + n);
                    su->su_badflags = badword_captype (su->su_badptr + n, su->su_badptr + su->su_badlen);
                    go_deeper (stack, depth, 0);
                    ++depth;
                    sp = &stack[depth];
                    sp->ts_prefixdepth = depth - 1;
                    byts = fbyts;
                    idxs = fidxs;
                    sp->ts_arridx = 0;
                    tword[sp->ts_twordlen] = NUL;
                    make_case_word (tword + sp -> ts_splitoff, preword + sp -> ts_prewordlen, flags);
                    sp->ts_prewordlen = (char_u) STRLEN (preword);
                    sp->ts_splitoff = sp->ts_twordlen;
                }
                break;
            }
            if (sp->ts_curi > len || byts[arridx] != 0) {
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_ENDNUL;
                sp->ts_save_badflags = su->su_badflags;
                break;
            }
            ++sp->ts_curi;
            flags = (int) idxs[arridx];
            if (flags & WF_NOSUGGEST)
                break;
            fword_ends = (fword[sp->ts_fidx] == NUL || (soundfold ? VIM_ISWHITE (fword[sp->ts_fidx]) : !spell_iswordp (fword +sp->ts_fidx, curwin)));
            tword[sp->ts_twordlen] = NUL;
            if (sp->ts_prefixdepth <= PFD_NOTSPECIAL && (sp->ts_flags & TSF_PREFIXOK) == 0) {
                n = stack[sp->ts_prefixdepth].ts_arridx;
                len = pbyts[n++];
                for (c = 0; c < len && pbyts[n + c] == 0; ++c)
                    ;
                if (c > 0) {
                    c = valid_word_prefix (c, n, flags, tword +sp->ts_splitoff, slang, FALSE);
                    if (c == 0)
                        break;
                    if (c & WF_RAREPFX)
                        flags |= WF_RARE;
                    sp->ts_flags |= TSF_PREFIXOK;
                }
            }
            if (sp->ts_complen == sp->ts_compsplit && fword_ends && (flags & WF_NEEDCOMP))
                goodword_ends = FALSE;
            else
                goodword_ends = TRUE;
            p = NULL;
            compound_ok = TRUE;
            if (sp->ts_complen > sp->ts_compsplit) {
                if (slang->sl_nobreak) {
                    if (sp->ts_fidx - sp->ts_splitfidx == sp->ts_twordlen - sp->ts_splitoff && STRNCMP (fword +sp->ts_splitfidx, tword +sp->ts_splitoff, sp->ts_fidx - sp->ts_splitfidx) == 0) {
                        preword[sp->ts_prewordlen] = NUL;
                        newscore = score_wordcount_adj (slang, sp->ts_score, preword +sp->ts_prewordlen, sp->ts_prewordlen > 0);
                        if (newscore <= su->su_maxscore)
                            add_suggestion (su, &su->su_ga, preword, sp->ts_splitfidx - repextra, newscore, 0, FALSE, lp->lp_sallang, FALSE);
                        break;
                    }
                }
                else {
                    if (((unsigned ) flags >> 24) == 0 || sp->ts_twordlen - sp->ts_splitoff < slang->sl_compminlen)
                        break;
                    compflags[sp->ts_complen] = ((unsigned ) flags >> 24);
                    compflags[sp->ts_complen + 1] = NUL;
                    vim_strncpy (preword + sp -> ts_prewordlen, tword + sp -> ts_splitoff, sp -> ts_twordlen - sp -> ts_splitoff);
                    if (match_checkcompoundpattern (preword, sp->ts_prewordlen, &slang->sl_comppat))
                        compound_ok = FALSE;
                    if (compound_ok) {
                        p = preword;
                        while (*skiptowhite (p) != NUL)
                            p = skipwhite (skiptowhite (p));
                        if (fword_ends && !can_compound (slang, p, compflags +sp->ts_compsplit))
                            compound_ok = FALSE;
                    }
                    p = preword + sp->ts_prewordlen;
                    MB_PTR_BACK (preword, p);
                }
            }
            if (soundfold)
                STRCPY (preword +sp->ts_prewordlen, tword +sp->ts_splitoff);
            else if (flags & WF_KEEPCAP)
                find_keepcap_word (slang, tword +sp->ts_splitoff, preword +sp->ts_prewordlen);
            else {
                c = su->su_badflags;
                if ((c & WF_ALLCAP) && su->su_badlen == 1)
                    c = WF_ONECAP;
                c |= flags;
                if (p != NULL && spell_iswordp_nmw (p, curwin))
                    c &= ~WF_ONECAP;
                make_case_word (tword + sp -> ts_splitoff, preword + sp -> ts_prewordlen, c);
            }
            if (!soundfold) {
                if (flags & WF_BANNED) {
                    add_banned (su, preword + sp -> ts_prewordlen);
                    break;
                }
                if ((sp->ts_complen == sp->ts_compsplit && WAS_BANNED (su, preword +sp->ts_prewordlen)) || WAS_BANNED (su, preword)) {
                    if (slang->sl_compprog == NULL)
                        break;
                    goodword_ends = FALSE;
                }
            }
            newscore = 0;
            if (!soundfold) {
                if ((flags & WF_REGION) && (((unsigned ) flags >> 16) & lp->lp_region) == 0)
                    newscore += SCORE_REGION;
                if (flags & WF_RARE)
                    newscore += SCORE_RARE;
                if (!spell_valid_case (su->su_badflags, captype (preword + sp->ts_prewordlen, NULL)))
                    newscore += SCORE_ICASE;
            }
            if (fword_ends && goodword_ends && sp->ts_fidx >= sp->ts_fidxtry && compound_ok) {
                if (soundfold) {
                    add_sound_suggest (su, preword, sp -> ts_score, lp);
                }
                else if (sp->ts_fidx > 0) {
                    p = fword + sp->ts_fidx;
                    MB_PTR_BACK (fword, p);
                    if (!spell_iswordp (p, curwin)) {
                        p = preword + STRLEN (preword);
                        MB_PTR_BACK (preword, p);
                        if (spell_iswordp (p, curwin))
                            newscore += SCORE_NONWORD;
                    }
                    score = score_wordcount_adj (slang, sp->ts_score + newscore, preword +sp->ts_prewordlen, sp->ts_prewordlen > 0);
                    if (score <= su->su_maxscore) {
                        add_suggestion (su, & su -> su_ga, preword, sp -> ts_fidx - repextra, score, 0, FALSE, lp -> lp_sallang, FALSE);
                        if (su->su_badflags & WF_MIXCAP) {
                            c = captype (preword, NULL);
                            if (c == 0 || c == WF_ALLCAP) {
                                make_case_word (tword + sp -> ts_splitoff, preword + sp -> ts_prewordlen, c == 0 ? WF_ALLCAP : 0);
                                add_suggestion (su, & su -> su_ga, preword, sp -> ts_fidx - repextra, score + SCORE_ICASE, 0, FALSE, lp -> lp_sallang, FALSE);
                            }
                        }
                    }
                }
            }
            if ((sp->ts_fidx >= sp->ts_fidxtry || fword_ends)) {
                int try_compound;
                int try_split;
                try_split = (sp->ts_fidx - repextra < su->su_badlen) && !soundfold;
                try_compound = FALSE;
                if (!soundfold && !slang->sl_nocompoundsugs && slang->sl_compprog != NULL && ((unsigned ) flags >> 24) != 0 && sp->ts_twordlen - sp->ts_splitoff >= slang->sl_compminlen && (slang->sl_compsylmax < MAXWLEN || sp->ts_complen + 1 - sp->ts_compsplit < slang->sl_compmax) && (can_be_compound (sp, slang, compflags, ((unsigned ) flags >> 24)))) {
                    try_compound = TRUE;
                    compflags[sp->ts_complen] = ((unsigned ) flags >> 24);
                    compflags[sp->ts_complen + 1] = NUL;
                }
                if (slang->sl_nobreak && !slang->sl_nocompoundsugs)
                    try_compound = TRUE;
                else if (!fword_ends && try_compound && (sp->ts_flags & TSF_DIDSPLIT) == 0) {
                    try_compound = FALSE;
                    sp->ts_flags |= TSF_DIDSPLIT;
                    --sp->ts_curi;
                    compflags[sp->ts_complen] = NUL;
                }
                else
                    sp->ts_flags &= ~TSF_DIDSPLIT;
                if (try_split || try_compound) {
                    if (!try_compound && (!fword_ends || !goodword_ends)) {
                        if (sp->ts_complen == sp->ts_compsplit && (flags & WF_NEEDCOMP))
                            break;
                        p = preword;
                        while (*skiptowhite (p) != NUL)
                            p = skipwhite (skiptowhite (p));
                        if (sp->ts_complen > sp->ts_compsplit && !can_compound (slang, p, compflags +sp->ts_compsplit))
                            break;
                        if (slang->sl_nosplitsugs)
                            newscore += SCORE_SPLIT_NO;
                        else
                            newscore += SCORE_SPLIT;
                        newscore = score_wordcount_adj (slang, newscore, preword +sp->ts_prewordlen, TRUE);
                    }
                    if (TRY_DEEPER (su, stack, depth, newscore)) {
                        go_deeper (stack, depth, newscore);
                        sp->ts_save_badflags = su->su_badflags;
                        PROF_STORE (sp -> ts_state)
                        sp->ts_state = STATE_SPLITUNDO;
                        ++depth;
                        sp = &stack[depth];
                        if (!try_compound && !fword_ends)
                            STRCAT (preword, " ");
                        sp->ts_prewordlen = (char_u) STRLEN (preword);
                        sp->ts_splitoff = sp->ts_twordlen;
                        sp->ts_splitfidx = sp->ts_fidx;
                        if (((!try_compound && !spell_iswordp_nmw (fword +sp->ts_fidx, curwin)) || fword_ends) && fword[sp->ts_fidx] != NUL && goodword_ends) {
                            int l;
                            l = MB_PTR2LEN (fword +sp->ts_fidx);
                            if (fword_ends) {
                                mch_memmove (preword + sp -> ts_prewordlen, fword + sp -> ts_fidx, l);
                                sp->ts_prewordlen += l;
                                preword[sp->ts_prewordlen] = NUL;
                            }
                            else
                                sp->ts_score -= SCORE_SPLIT - SCORE_SUBST;
                            sp->ts_fidx += l;
                        }
                        if (try_compound)
                            ++sp->ts_complen;
                        else
                            sp->ts_compsplit = sp->ts_complen;
                        sp->ts_prefixdepth = PFD_NOPREFIX;
                        n = sp->ts_fidx;
                        su->su_badflags = badword_captype (su->su_badptr + n, su->su_badptr + su->su_badlen);
                        sp->ts_arridx = 0;
                        if (pbyts != NULL) {
                            byts = pbyts;
                            idxs = pidxs;
                            sp->ts_prefixdepth = PFD_PREFIXTREE;
                            PROF_STORE (sp -> ts_state)
                            sp->ts_state = STATE_NOPREFIX;
                        }
                    }
                }
            }
            break;
        case STATE_SPLITUNDO :
            su->su_badflags = sp->ts_save_badflags;
            PROF_STORE (sp -> ts_state)
            sp->ts_state = STATE_START;
            byts = fbyts;
            idxs = fidxs;
            break;
        case STATE_ENDNUL :
            su->su_badflags = sp->ts_save_badflags;
            if (fword[sp->ts_fidx] == NUL) {
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_DEL;
                break;
            }
            PROF_STORE (sp -> ts_state)
            sp->ts_state = STATE_PLAIN;
        case STATE_PLAIN :
            arridx = sp->ts_arridx;
            if (sp->ts_curi > byts[arridx]) {
                PROF_STORE (sp -> ts_state)
                if (sp->ts_fidx >= sp->ts_fidxtry)
                    sp->ts_state = STATE_DEL;
                else
                    sp->ts_state = STATE_FINAL;
            }
            else {
                arridx += sp->ts_curi++;
                c = byts[arridx];
                if (c == fword[sp->ts_fidx])
                    newscore = 0;
                else
                    newscore = SCORE_SUBST;
                if ((newscore == 0 || (sp->ts_fidx >= sp->ts_fidxtry && ((sp->ts_flags & TSF_DIDDEL) == 0 || c != fword[sp->ts_delidx]))) && TRY_DEEPER (su, stack, depth, newscore)) {
                    go_deeper (stack, depth, newscore);
                    ++depth;
                    sp = &stack[depth];
                    ++sp->ts_fidx;
                    tword[sp->ts_twordlen++] = c;
                    sp->ts_arridx = idxs[arridx];
                    {
                        if (newscore != 0 && !soundfold && slang->sl_has_map && similar_chars (slang, c, fword[sp->ts_fidx - 1]))
                            sp->ts_score -= SCORE_SUBST - SCORE_SIMILAR;
                    }
                }
            }
            break;
        case STATE_DEL :
            PROF_STORE (sp -> ts_state)
            sp->ts_state = STATE_INS_PREP;
            sp->ts_curi = 1;
            if (soundfold && sp->ts_fidx == 0 && fword[sp->ts_fidx] == '*')
                newscore = 2 * SCORE_DEL / 3;
            else
                newscore = SCORE_DEL;
            if (fword[sp->ts_fidx] != NUL && TRY_DEEPER (su, stack, depth, newscore)) {
                go_deeper (stack, depth, newscore);
                ++depth;
                stack[depth].ts_flags |= TSF_DIDDEL;
                stack[depth].ts_delidx = sp->ts_fidx;
                {
                    ++stack[depth].ts_fidx;
                    if (fword[sp->ts_fidx] == fword[sp->ts_fidx + 1])
                        stack[depth].ts_score -= SCORE_DEL - SCORE_DELDUP;
                }
                break;
            }
        case STATE_INS_PREP :
            if (sp->ts_flags & TSF_DIDDEL) {
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_SWAP;
                break;
            }
            n = sp->ts_arridx;
            for (;;) {
                if (sp->ts_curi > byts[n]) {
                    PROF_STORE (sp -> ts_state)
                    sp->ts_state = STATE_SWAP;
                    break;
                }
                if (byts[n + sp->ts_curi] != NUL) {
                    PROF_STORE (sp -> ts_state)
                    sp->ts_state = STATE_INS;
                    break;
                }
                ++sp->ts_curi;
            }
            break;
        case STATE_INS :
            n = sp->ts_arridx;
            if (sp->ts_curi > byts[n]) {
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_SWAP;
                break;
            }
            n += sp->ts_curi++;
            c = byts[n];
            if (soundfold && sp->ts_twordlen == 0 && c == '*')
                newscore = 2 * SCORE_INS / 3;
            else
                newscore = SCORE_INS;
            if (c != fword[sp->ts_fidx] && TRY_DEEPER (su, stack, depth, newscore)) {
                go_deeper (stack, depth, newscore);
                ++depth;
                sp = &stack[depth];
                tword[sp->ts_twordlen++] = c;
                sp->ts_arridx = idxs[n];
                {
                    if (sp->ts_twordlen >= 2 && tword[sp->ts_twordlen - 2] == c)
                        sp->ts_score -= SCORE_INS - SCORE_INSDUP;
                }
            }
            break;
        case STATE_SWAP :
            p = fword + sp->ts_fidx;
            c = *p;
            if (c == NUL) {
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_FINAL;
                break;
            }
            if (!soundfold && !spell_iswordp (p, curwin)) {
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_REP_INI;
                break;
            }
            {
                if (p[1] == NUL)
                    c2 = NUL;
                else if (!soundfold && !spell_iswordp (p +1, curwin))
                    c2 = c;
                else
                    c2 = p[1];
            }
            if (c2 == NUL) {
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_REP_INI;
                break;
            }
            if (c == c2) {
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_SWAP3;
                break;
            }
            if (c2 != NUL && TRY_DEEPER (su, stack, depth, SCORE_SWAP)) {
                go_deeper (stack, depth, SCORE_SWAP);
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_UNSWAP;
                ++depth;
                {
                    p[0] = c2;
                    p[1] = c;
                    stack[depth].ts_fidxtry = sp->ts_fidx + 2;
                }
            }
            else {
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_REP_INI;
            }
            break;
        case STATE_UNSWAP :
            p = fword + sp->ts_fidx;
            {
                c = *p;
                *p = p[1];
                p[1] = c;
            }
        case STATE_SWAP3 :
            p = fword + sp->ts_fidx;
            {
                c = *p;
                c2 = p[1];
                if (!soundfold && !spell_iswordp (p +2, curwin))
                    c3 = c;
                else
                    c3 = p[2];
            }
            if (c == c3 || c3 == NUL) {
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_REP_INI;
                break;
            }
            if (TRY_DEEPER (su, stack, depth, SCORE_SWAP3)) {
                go_deeper (stack, depth, SCORE_SWAP3);
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_UNSWAP3;
                ++depth;
                {
                    p[0] = p[2];
                    p[2] = c;
                    stack[depth].ts_fidxtry = sp->ts_fidx + 3;
                }
            }
            else {
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_REP_INI;
            }
            break;
        case STATE_UNSWAP3 :
            p = fword + sp->ts_fidx;
            {
                c = *p;
                *p = p[2];
                p[2] = c;
                ++p;
            }
            if (!soundfold && !spell_iswordp (p, curwin)) {
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_REP_INI;
                break;
            }
            if (TRY_DEEPER (su, stack, depth, SCORE_SWAP3)) {
                go_deeper (stack, depth, SCORE_SWAP3);
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_UNROT3L;
                ++depth;
                p = fword + sp->ts_fidx;
                {
                    c = *p;
                    *p = p[1];
                    p[1] = p[2];
                    p[2] = c;
                    stack[depth].ts_fidxtry = sp->ts_fidx + 3;
                }
            }
            else {
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_REP_INI;
            }
            break;
        case STATE_UNROT3L :
            p = fword + sp->ts_fidx;
            {
                c = p[2];
                p[2] = p[1];
                p[1] = *p;
                *p = c;
            }
            if (TRY_DEEPER (su, stack, depth, SCORE_SWAP3)) {
                go_deeper (stack, depth, SCORE_SWAP3);
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_UNROT3R;
                ++depth;
                p = fword + sp->ts_fidx;
                {
                    c = p[2];
                    p[2] = p[1];
                    p[1] = *p;
                    *p = c;
                    stack[depth].ts_fidxtry = sp->ts_fidx + 3;
                }
            }
            else {
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_REP_INI;
            }
            break;
        case STATE_UNROT3R :
            p = fword + sp->ts_fidx;
            {
                c = *p;
                *p = p[1];
                p[1] = p[2];
                p[2] = c;
            }
        case STATE_REP_INI :
            if ((lp->lp_replang == NULL && !soundfold) || sp->ts_score + SCORE_REP >= su->su_maxscore || sp->ts_fidx < sp->ts_fidxtry) {
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_FINAL;
                break;
            }
            if (soundfold)
                sp->ts_curi = slang->sl_repsal_first[fword[sp->ts_fidx]];
            else
                sp->ts_curi = lp->lp_replang->sl_rep_first[fword[sp->ts_fidx]];
            if (sp->ts_curi < 0) {
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_FINAL;
                break;
            }
            PROF_STORE (sp -> ts_state)
            sp->ts_state = STATE_REP;
        case STATE_REP :
            p = fword + sp->ts_fidx;
            if (soundfold)
                gap = &slang->sl_repsal;
            else
                gap = &lp->lp_replang->sl_rep;
            while (sp->ts_curi < gap->ga_len) {
                ftp = (fromto_T *) gap->ga_data + sp->ts_curi++;
                if (*ftp->ft_from != *p) {
                    sp->ts_curi = gap->ga_len;
                    break;
                }
                if (STRNCMP (ftp->ft_from, p, STRLEN (ftp->ft_from)) == 0 && TRY_DEEPER (su, stack, depth, SCORE_REP)) {
                    go_deeper (stack, depth, SCORE_REP);
                    PROF_STORE (sp -> ts_state)
                    sp->ts_state = STATE_REP_UNDO;
                    ++depth;
                    fl = (int) STRLEN (ftp->ft_from);
                    tl = (int) STRLEN (ftp->ft_to);
                    if (fl != tl) {
                        STRMOVE (p + tl, p + fl);
                        repextra += tl - fl;
                    }
                    mch_memmove (p, ftp -> ft_to, tl);
                    stack[depth].ts_fidxtry = sp->ts_fidx + tl;
                    break;
                }
            }
            if (sp->ts_curi >= gap->ga_len && sp->ts_state == STATE_REP) {
                PROF_STORE (sp -> ts_state)
                sp->ts_state = STATE_FINAL;
            }
            break;
        case STATE_REP_UNDO :
            if (soundfold)
                gap = &slang->sl_repsal;
            else
                gap = &lp->lp_replang->sl_rep;
            ftp = (fromto_T *) gap->ga_data + sp->ts_curi - 1;
            fl = (int) STRLEN (ftp->ft_from);
            tl = (int) STRLEN (ftp->ft_to);
            p = fword + sp->ts_fidx;
            if (fl != tl) {
                STRMOVE (p + fl, p + tl);
                repextra -= tl - fl;
            }
            mch_memmove (p, ftp -> ft_from, fl);
            PROF_STORE (sp -> ts_state)
            sp->ts_state = STATE_REP;
            break;
        default :
            --depth;
            if (depth >= 0 && stack[depth].ts_prefixdepth == PFD_PREFIXTREE) {
                byts = pbyts;
                idxs = pidxs;
            }
            if (--breakcheckcount == 0) {
                ui_breakcheck ();
                breakcheckcount = 1000;
            }
        }
    }
}

static void go_deeper (trystate_T *stack, int depth, int score_add) {
    stack[depth + 1] = stack[depth];
    stack[depth + 1].ts_state = STATE_START;
    stack[depth + 1].ts_score = stack[depth].ts_score + score_add;
    stack[depth + 1].ts_curi = 1;
    stack[depth + 1].ts_flags = 0;
}

static int score_wordcount_adj (slang_T *slang, int score, char_u *word, int split) {
    hashitem_T *hi;
    wordcount_T *wc;
    int bonus;
    int newscore;
    hi = hash_find (&slang->sl_wordcount, word);
    if (!HASHITEM_EMPTY (hi)) {
        wc = HI2WC (hi);
        if (wc->wc_count < SCORE_THRES2)
            bonus = SCORE_COMMON1;
        else if (wc->wc_count < SCORE_THRES3)
            bonus = SCORE_COMMON2;
        else
            bonus = SCORE_COMMON3;
        if (split)
            newscore = score - bonus / 2;
        else
            newscore = score - bonus;
        if (newscore < 0)
            return 0;
        return newscore;
    }
    return score;
}

static int match_checkcompoundpattern (char_u *ptr, int wlen, garray_T *gap) {
    int i;
    char_u *p;
    int len;
    for (i = 0; i + 1 < gap->ga_len; i += 2) {
        p = ((char_u **) gap->ga_data)[i + 1];
        if (STRNCMP (ptr +wlen, p, STRLEN (p)) == 0) {
            p = ((char_u **) gap->ga_data)[i];
            len = (int) STRLEN (p);
            if (len <= wlen && STRNCMP (ptr +wlen - len, p, len) == 0)
                return TRUE;
        }
    }
    return FALSE;
}

static int can_compound (slang_T *slang, char_u *word, char_u *flags) {
    char_u *p;
    if (slang->sl_compprog == NULL)
        return FALSE;
    p = flags;
    if (!vim_regexec_prog (&slang->sl_compprog, FALSE, p, 0))
        return FALSE;
    if (slang->sl_compsylmax < MAXWLEN && count_syllables (slang, word) > slang->sl_compsylmax)
        return (int) STRLEN (flags) < slang->sl_compmax;
    return TRUE;
}

static int count_syllables (slang_T *slang, char_u *word) {
    int cnt = 0;
    int skip = FALSE;
    char_u *p;
    int len;
    int i;
    syl_item_T *syl;
    int c;
    if (slang->sl_syllable == NULL)
        return 0;
    for (p = word; *p != NUL; p += len) {
        if (*p == ' ') {
            len = 1;
            cnt = 0;
            continue;
        }
        len = 0;
        for (i = 0; i < slang->sl_syl_items.ga_len; ++i) {
            syl = ((syl_item_T *) slang->sl_syl_items.ga_data) + i;
            if (syl->sy_len > len && STRNCMP (p, syl->sy_chars, syl->sy_len) == 0)
                len = syl->sy_len;
        }
        if (len != 0) {
            ++cnt;
            skip = FALSE;
        }
        else {
            c = *p;
            len = 1;
            if (vim_strchr (slang->sl_syllable, c) == NULL)
                skip = FALSE;
            else if (!skip) {
                ++cnt;
                skip = TRUE;
            }
        }
    }
    return cnt;
}

static void find_keepcap_word (slang_T *slang, char_u *fword, char_u *kword) {
    char_u uword [MAXWLEN];
    int depth;
    idx_T tryidx;
    idx_T arridx [MAXWLEN];
    int round [MAXWLEN];
    int fwordidx [MAXWLEN];
    int uwordidx [MAXWLEN];
    int kwordlen [MAXWLEN];
    int flen, ulen;
    int l;
    int len;
    int c;
    idx_T lo, hi, m;
    char_u *p;
    char_u *byts = slang->sl_kbyts;
    idx_T *idxs = slang->sl_kidxs;
    if (byts == NULL) {
        *kword = NUL;
        return;
    }
    allcap_copy (fword, uword);
    depth = 0;
    arridx[0] = 0;
    round[0] = 0;
    fwordidx[0] = 0;
    uwordidx[0] = 0;
    kwordlen[0] = 0;
    while (depth >= 0) {
        if (fword[fwordidx[depth]] == NUL) {
            if (byts[arridx[depth] + 1] == 0) {
                kword[kwordlen[depth]] = NUL;
                return;
            }
            --depth;
        }
        else if (++round[depth] > 2) {
            --depth;
        }
        else {
            ulen = flen = 1;
            if (round[depth] == 1) {
                p = fword + fwordidx[depth];
                l = flen;
            }
            else {
                p = uword + uwordidx[depth];
                l = ulen;
            }
            for (tryidx = arridx[depth]; l > 0; --l) {
                len = byts[tryidx++];
                c = *p++;
                lo = tryidx;
                hi = tryidx + len - 1;
                while (lo < hi) {
                    m = (lo + hi) / 2;
                    if (byts[m] > c)
                        hi = m - 1;
                    else if (byts[m] < c)
                        lo = m + 1;
                    else {
                        lo = hi = m;
                        break;
                    }
                }
                if (hi < lo || byts[lo] != c)
                    break;
                tryidx = idxs[lo];
            }
            if (l == 0) {
                if (round[depth] == 1) {
                    STRNCPY (kword + kwordlen [depth], fword + fwordidx [depth], flen);
                    kwordlen[depth + 1] = kwordlen[depth] + flen;
                }
                else {
                    STRNCPY (kword + kwordlen [depth], uword + uwordidx [depth], ulen);
                    kwordlen[depth + 1] = kwordlen[depth] + ulen;
                }
                fwordidx[depth + 1] = fwordidx[depth] + flen;
                uwordidx[depth + 1] = uwordidx[depth] + ulen;
                ++depth;
                arridx[depth] = tryidx;
                round[depth] = 0;
            }
        }
    }
    *kword = NUL;
}

static void add_sound_suggest (suginfo_T *su, char_u *goodword, int score, langp_T *lp) {
    slang_T *slang = lp->lp_slang;
    int sfwordnr;
    char_u *nrline;
    int orgnr;
    char_u theword [MAXWLEN];
    int i;
    int wlen;
    char_u *byts;
    idx_T *idxs;
    int n;
    int wordcount;
    int wc;
    int goodscore;
    hash_T hash;
    hashitem_T *hi;
    sftword_T *sft;
    int bc, gc;
    int limit;
    hash = hash_hash (goodword);
    hi = hash_lookup (&slang->sl_sounddone, goodword, hash);
    if (HASHITEM_EMPTY (hi)) {
        sft = (sftword_T *) alloc ((unsigned ) (sizeof (sftword_T) + STRLEN (goodword)));
        if (sft != NULL) {
            sft->sft_score = score;
            STRCPY (sft -> sft_word, goodword);
            hash_add_item (& slang -> sl_sounddone, hi, sft -> sft_word, hash);
        }
    }
    else {
        sft = HI2SFT (hi);
        if (score >= sft->sft_score)
            return;
        sft->sft_score = score;
    }
    sfwordnr = soundfold_find (slang, goodword);
    if (sfwordnr < 0) {
        internal_error ("add_sound_suggest()");
        return;
    }
    nrline = ml_get_buf (slang->sl_sugbuf, (linenr_T) (sfwordnr + 1), FALSE);
    orgnr = 0;
    while (*nrline != NUL) {
        orgnr += bytes2offset (&nrline);
        byts = slang->sl_fbyts;
        idxs = slang->sl_fidxs;
        n = 0;
        wordcount = 0;
        for (wlen = 0; wlen < MAXWLEN - 3; ++wlen) {
            i = 1;
            if (wordcount == orgnr && byts[n + 1] == NUL)
                break;
            if (byts[n + 1] == NUL)
                ++wordcount;
            for (; byts[n + i] == NUL; ++i)
                if (i > byts[n]) {
                    STRCPY (theword + wlen, "BAD");
                    wlen += 3;
                    goto badword;
                }
            for (; i < byts[n]; ++i) {
                wc = idxs[idxs[n + i]];
                if (wordcount + wc > orgnr)
                    break;
                wordcount += wc;
            }
            theword[wlen] = byts[n + i];
            n = idxs[n + i];
        }
    badword :
        theword[wlen] = NUL;
        for (; i <= byts[n] && byts[n + i] == NUL; ++i) {
            char_u cword [MAXWLEN];
            char_u *p;
            int flags = (int) idxs[n + i];
            if (flags & WF_NOSUGGEST)
                continue;
            if (flags & WF_KEEPCAP) {
                find_keepcap_word (slang, theword, cword);
                p = cword;
            }
            else {
                flags |= su->su_badflags;
                if ((flags & WF_CAPMASK) != 0) {
                    make_case_word (theword, cword, flags);
                    p = cword;
                }
                else
                    p = theword;
            }
            if (sps_flags & SPS_DOUBLE) {
                if (score <= su->su_maxscore)
                    add_suggestion (su, &su->su_sga, p, su->su_badlen, score, 0, FALSE, slang, FALSE);
            }
            else {
                if ((flags & WF_REGION) && (((unsigned ) flags >> 16) & lp->lp_region) == 0)
                    goodscore = SCORE_REGION;
                else
                    goodscore = 0;
                gc = PTR2CHAR (p);
                if (SPELL_ISUPPER (gc)) {
                    bc = PTR2CHAR (su->su_badword);
                    if (!SPELL_ISUPPER (bc) && SPELL_TOFOLD (bc) != SPELL_TOFOLD (gc))
                        goodscore += SCORE_ICASE / 2;
                }
                limit = MAXSCORE (su->su_sfmaxscore - goodscore, score);
                if (limit > SCORE_LIMITMAX)
                    goodscore += spell_edit_score (slang, su->su_badword, p);
                else
                    goodscore += spell_edit_score_limit (slang, su->su_badword, p, limit);
                if (goodscore < SCORE_MAXMAX) {
                    goodscore = score_wordcount_adj (slang, goodscore, p, FALSE);
                    goodscore = RESCORE (goodscore, score);
                    if (goodscore <= su->su_sfmaxscore)
                        add_suggestion (su, &su->su_ga, p, su->su_badlen, goodscore, score, TRUE, slang, TRUE);
                }
            }
        }
    }
}

static int soundfold_find (slang_T *slang, char_u *word) {
    idx_T arridx = 0;
    int len;
    int wlen = 0;
    int c;
    char_u *ptr = word;
    char_u *byts;
    idx_T *idxs;
    int wordnr = 0;
    byts = slang->sl_sbyts;
    idxs = slang->sl_sidxs;
    for (;;) {
        len = byts[arridx++];
        c = ptr[wlen];
        if (byts[arridx] == NUL) {
            if (c == NUL)
                break;
            while (len > 0 && byts[arridx] == NUL) {
                ++arridx;
                --len;
            }
            if (len == 0)
                return -1;
            ++wordnr;
        }
        if (c == NUL)
            return -1;
        if (c == TAB)
            c = ' ';
        while (byts[arridx] < c) {
            wordnr += idxs[idxs[arridx]];
            ++arridx;
            if (--len == 0)
                return -1;
        }
        if (byts[arridx] != c)
            return -1;
        arridx = idxs[arridx];
        ++wlen;
        if (c == ' ')
            while (ptr[wlen] == ' ' || ptr[wlen] == TAB)
                ++wlen;
    }
    return wordnr;
}

static int bytes2offset (char_u **pp) {
    char_u *p = *pp;
    int nr;
    int c;
    c = *p++;
    if ((c & 0x80) == 0x00) {
        nr = c - 1;
    }
    else if ((c & 0xc0) == 0x80) {
        nr = (c & 0x3f) - 1;
        nr = nr * 255 + (*p++ - 1);
    }
    else if ((c & 0xe0) == 0xc0) {
        nr = (c & 0x1f) - 1;
        nr = nr * 255 + (*p++ - 1);
        nr = nr * 255 + (*p++ - 1);
    }
    else {
        nr = (c & 0x0f) - 1;
        nr = nr * 255 + (*p++ - 1);
        nr = nr * 255 + (*p++ - 1);
        nr = nr * 255 + (*p++ - 1);
    }
    *pp = p;
    return nr;
}

static int spell_edit_score (slang_T *slang, char_u *badword, char_u *goodword) {
    int *cnt;
    int badlen, goodlen;
    int j, i;
    int t;
    int bc, gc;
    int pbc, pgc;
    {
        badlen = (int) STRLEN (badword) + 1;
        goodlen = (int) STRLEN (goodword) + 1;
    }

    #define CNT(a, b)   cnt[(a) + (b) * (badlen + 1)]
    cnt = (int *) lalloc ((long_u) (sizeof (int) * (badlen + 1) * (goodlen + 1)), TRUE);
    if (cnt == NULL)
        return 0;
    CNT (0, 0) = 0;
    for (j = 1; j <= goodlen; ++j)
        CNT (0, j) = CNT (0, j -1) + SCORE_INS;
    for (i = 1; i <= badlen; ++i) {
        CNT (i, 0) = CNT (i -1, 0) + SCORE_DEL;
        for (j = 1; j <= goodlen; ++j) {
            {
                bc = badword[i - 1];
                gc = goodword[j - 1];
            }
            if (bc == gc)
                CNT (i, j) = CNT (i -1, j -1);
            else {
                if (SPELL_TOFOLD (bc) == SPELL_TOFOLD (gc))
                    CNT (i, j) = SCORE_ICASE + CNT (i -1, j -1);
                else {
                    if (slang != NULL && slang->sl_has_map && similar_chars (slang, gc, bc))
                        CNT (i, j) = SCORE_SIMILAR + CNT (i -1, j -1);
                    else
                        CNT (i, j) = SCORE_SUBST + CNT (i -1, j -1);
                }
                if (i > 1 && j > 1) {
                    {
                        pbc = badword[i - 2];
                        pgc = goodword[j - 2];
                    }
                    if (bc == pgc && pbc == gc) {
                        t = SCORE_SWAP + CNT (i -2, j -2);
                        if (t < CNT (i, j))
                            CNT (i, j) = t;
                    }
                }
                t = SCORE_DEL + CNT (i -1, j);
                if (t < CNT (i, j))
                    CNT (i, j) = t;
                t = SCORE_INS + CNT (i, j -1);
                if (t < CNT (i, j))
                    CNT (i, j) = t;
            }
        }
    }
    i = CNT (badlen -1, goodlen -1);
    vim_free (cnt);
    return i;
}

static int similar_chars (slang_T *slang, int c1, int c2) {
    int m1, m2;
    m1 = slang->sl_map_array[c1];
    if (m1 == 0)
        return FALSE;
    m2 = slang->sl_map_array[c2];
    return m1 == m2;
}

static int spell_edit_score_limit (slang_T *slang, char_u *badword, char_u *goodword, int limit) {
    limitscore_T stack [10];
    int stackidx;
    int bi, gi;
    int bi2, gi2;
    int bc, gc;
    int score;
    int score_off;
    int minscore;
    int round;
    stackidx = 0;
    bi = 0;
    gi = 0;
    score = 0;
    minscore = limit + 1;
    for (;;) {
        for (;;) {
            bc = badword[bi];
            gc = goodword[gi];
            if (bc != gc)
                break;
            if (bc == NUL) {
                if (score < minscore)
                    minscore = score;
                goto pop;
            }
            ++bi;
            ++gi;
        }
        if (gc == NUL) {
            do {
                if ((score += SCORE_DEL) >= minscore)
                    goto pop;
            }
            while (badword[++bi] != NUL);
            minscore = score;
        }
        else if (bc == NUL) {
            do {
                if ((score += SCORE_INS) >= minscore)
                    goto pop;
            }
            while (goodword[++gi] != NUL);
            minscore = score;
        }
        else {
            for (round = 0; round <= 1; ++round) {
                score_off = score + (round == 0 ? SCORE_DEL : SCORE_INS);
                if (score_off < minscore) {
                    if (score_off + SCORE_EDIT_MIN >= minscore) {
                        bi2 = bi + 1 - round;
                        gi2 = gi + round;
                        while (goodword[gi2] == badword[bi2]) {
                            if (goodword[gi2] == NUL) {
                                minscore = score_off;
                                break;
                            }
                            ++bi2;
                            ++gi2;
                        }
                    }
                    else {
                        stack[stackidx].badi = bi + 1 - round;
                        stack[stackidx].goodi = gi + round;
                        stack[stackidx].score = score_off;
                        ++stackidx;
                    }
                }
            }
            if (score + SCORE_SWAP < minscore) {
                if (gc == badword[bi + 1] && bc == goodword[gi + 1]) {
                    gi += 2;
                    bi += 2;
                    score += SCORE_SWAP;
                    continue;
                }
            }
            if (SPELL_TOFOLD (bc) == SPELL_TOFOLD (gc))
                score += SCORE_ICASE;
            else {
                if (slang != NULL && slang->sl_has_map && similar_chars (slang, gc, bc))
                    score += SCORE_SIMILAR;
                else
                    score += SCORE_SUBST;
            }
            if (score < minscore) {
                ++gi;
                ++bi;
                continue;
            }
        }
    pop :
        if (stackidx == 0)
            break;
        --stackidx;
        gi = stack[stackidx].goodi;
        bi = stack[stackidx].badi;
        score = stack[stackidx].score;
    }
    if (minscore > limit)
        return SCORE_MAXMAX;
    return minscore;
}

static int can_be_compound (trystate_T *sp, slang_T *slang, char_u *compflags, int flag) {
    if (!byte_in_str (sp->ts_complen == sp->ts_compsplit ? slang->sl_compstartflags : slang->sl_compallflags, flag))
        return FALSE;
    if (slang->sl_comprules != NULL && sp->ts_complen > sp->ts_compsplit) {
        int v;
        compflags[sp->ts_complen] = flag;
        compflags[sp->ts_complen + 1] = NUL;
        v = match_compoundrule (slang, compflags +sp->ts_compsplit);
        compflags[sp->ts_complen] = NUL;
        return v;
    }
    return TRUE;
}

static int match_compoundrule (slang_T *slang, char_u *compflags) {
    char_u *p;
    int i;
    int c;
    for (p = slang->sl_comprules; *p != NUL; ++p) {
        for (i = 0;; ++i) {
            c = compflags[i];
            if (c == NUL)
                return TRUE;
            if (*p == '/' || *p == NUL)
                break;
            if (*p == '[') {
                int match = FALSE;
                ++p;
                while (*p != ']' && *p != NUL)
                    if (*p++ == c)
                        match = TRUE;
                if (!match)
                    break;
            }
            else if (*p != c)
                break;
            ++p;
        }
        p = vim_strchr (p, '/');
        if (p == NULL)
            break;
    }
    return FALSE;
}

static void score_comp_sal (suginfo_T *su) {
    langp_T *lp;
    char_u badsound [MAXWLEN];
    int i;
    suggest_T *stp;
    suggest_T *sstp;
    int score;
    int lpi;
    if (ga_grow (&su->su_sga, su->su_ga.ga_len) == FAIL)
        return;
    for (lpi = 0; lpi < curwin->w_s->b_langp.ga_len; ++lpi) {
        lp = LANGP_ENTRY (curwin->w_s->b_langp, lpi);
        if (lp->lp_slang->sl_sal.ga_len > 0) {
            spell_soundfold (lp -> lp_slang, su -> su_fbadword, TRUE, badsound);
            for (i = 0; i < su->su_ga.ga_len; ++i) {
                stp = &SUG (su->su_ga, i);
                score = stp_sal_score (stp, su, lp->lp_slang, badsound);
                if (score < SCORE_MAXMAX) {
                    sstp = &SUG (su->su_sga, su->su_sga.ga_len);
                    sstp->st_word = vim_strsave (stp->st_word);
                    if (sstp->st_word != NULL) {
                        sstp->st_wordlen = stp->st_wordlen;
                        sstp->st_score = score;
                        sstp->st_altscore = 0;
                        sstp->st_orglen = stp->st_orglen;
                        ++su->su_sga.ga_len;
                    }
                }
            }
            break;
        }
    }
}

static void rescore_suggestions (suginfo_T *su) {
    int i;
    if (su->su_sallang != NULL)
        for (i = 0; i < su->su_ga.ga_len; ++i)
            rescore_one (su, &SUG (su->su_ga, i));
}

static void suggest_try_soundalike_prep (void) {
    langp_T *lp;
    int lpi;
    slang_T *slang;
    for (lpi = 0; lpi < curwin->w_s->b_langp.ga_len; ++lpi) {
        lp = LANGP_ENTRY (curwin->w_s->b_langp, lpi);
        slang = lp->lp_slang;
        if (slang->sl_sal.ga_len > 0 && slang->sl_sbyts != NULL)
            hash_init (&slang->sl_sounddone);
    }
}

static void suggest_try_soundalike (suginfo_T *su) {
    char_u salword [MAXWLEN];
    langp_T *lp;
    int lpi;
    slang_T *slang;
    for (lpi = 0; lpi < curwin->w_s->b_langp.ga_len; ++lpi) {
        lp = LANGP_ENTRY (curwin->w_s->b_langp, lpi);
        slang = lp->lp_slang;
        if (slang->sl_sal.ga_len > 0 && slang->sl_sbyts != NULL) {
            spell_soundfold (slang, su -> su_fbadword, TRUE, salword);
            suggest_trie_walk (su, lp, salword, TRUE);
        }
    }
}

static void suggest_try_soundalike_finish (void) {
    langp_T *lp;
    int lpi;
    slang_T *slang;
    int todo;
    hashitem_T *hi;
    for (lpi = 0; lpi < curwin->w_s->b_langp.ga_len; ++lpi) {
        lp = LANGP_ENTRY (curwin->w_s->b_langp, lpi);
        slang = lp->lp_slang;
        if (slang->sl_sal.ga_len > 0 && slang->sl_sbyts != NULL) {
            todo = (int) slang->sl_sounddone.ht_used;
            for (hi = slang->sl_sounddone.ht_array; todo > 0; ++hi)
                if (!HASHITEM_EMPTY (hi)) {
                    vim_free (HI2SFT (hi));
                    --todo;
                }
            hash_clear (& slang -> sl_sounddone);
            hash_init (& slang -> sl_sounddone);
        }
    }
}

static void score_combine (suginfo_T *su) {
    int i;
    int j;
    garray_T ga;
    garray_T *gap;
    langp_T *lp;
    suggest_T *stp;
    char_u *p;
    char_u badsound [MAXWLEN];
    int round;
    int lpi;
    slang_T *slang = NULL;
    for (lpi = 0; lpi < curwin->w_s->b_langp.ga_len; ++lpi) {
        lp = LANGP_ENTRY (curwin->w_s->b_langp, lpi);
        if (lp->lp_slang->sl_sal.ga_len > 0) {
            slang = lp->lp_slang;
            spell_soundfold (slang, su -> su_fbadword, TRUE, badsound);
            for (i = 0; i < su->su_ga.ga_len; ++i) {
                stp = &SUG (su->su_ga, i);
                stp->st_altscore = stp_sal_score (stp, su, slang, badsound);
                if (stp->st_altscore == SCORE_MAXMAX)
                    stp->st_score = (stp->st_score * 3 + SCORE_BIG) / 4;
                else
                    stp->st_score = (stp->st_score * 3 + stp->st_altscore) / 4;
                stp->st_salscore = FALSE;
            }
            break;
        }
    }
    if (slang == NULL) {
        (void) cleanup_suggestions (&su->su_ga, su->su_maxscore, su->su_maxcount);
        return;
    }
    for (i = 0; i < su->su_sga.ga_len; ++i) {
        stp = &SUG (su->su_sga, i);
        stp->st_altscore = spell_edit_score (slang, su->su_badword, stp->st_word);
        if (stp->st_score == SCORE_MAXMAX)
            stp->st_score = (SCORE_BIG * 7 + stp->st_altscore) / 8;
        else
            stp->st_score = (stp->st_score * 7 + stp->st_altscore) / 8;
        stp->st_salscore = TRUE;
    }
    check_suggestions (su, & su -> su_ga);
    (void) cleanup_suggestions (&su->su_ga, su->su_maxscore, su->su_maxcount);
    check_suggestions (su, & su -> su_sga);
    (void) cleanup_suggestions (&su->su_sga, su->su_maxscore, su->su_maxcount);
    ga_init2 (& ga, (int) sizeof (suginfo_T), 1);
    if (ga_grow (&ga, su->su_ga.ga_len + su->su_sga.ga_len) == FAIL)
        return;
    stp = &SUG (ga, 0);
    for (i = 0; i < su->su_ga.ga_len || i < su->su_sga.ga_len; ++i) {
        for (round = 1; round <= 2; ++round) {
            gap = round == 1 ? &su->su_ga : &su->su_sga;
            if (i < gap->ga_len) {
                p = SUG (*gap, i).st_word;
                for (j = 0; j < ga.ga_len; ++j)
                    if (STRCMP (stp[j].st_word, p) == 0)
                        break;
                if (j == ga.ga_len)
                    stp[ga.ga_len++] = SUG (*gap, i);
                else
                    vim_free (p);
            }
        }
    }
    ga_clear (& su -> su_ga);
    ga_clear (& su -> su_sga);
    if (ga.ga_len > su->su_maxcount) {
        for (i = su->su_maxcount; i < ga.ga_len; ++i)
            vim_free (stp[i].st_word);
        ga.ga_len = su->su_maxcount;
    }
    su->su_ga = ga;
}

static void spell_find_cleanup (suginfo_T *su) {
    int i;
    for (i = 0; i < su->su_ga.ga_len; ++i)
        vim_free (SUG (su->su_ga, i).st_word);
    ga_clear (& su -> su_ga);
    for (i = 0; i < su->su_sga.ga_len; ++i)
        vim_free (SUG (su->su_sga, i).st_word);
    ga_clear (& su -> su_sga);
    hash_clear_all (& su -> su_banned, 0);
}

void init_spell_chartab (void) {
    int i;
    did_set_spelltab = FALSE;
    clear_spell_chartab (& spelltab);
    {
        for (i = 128; i < 256; ++i) {
            if (MB_ISUPPER (i)) {
                spelltab.st_isw[i] = TRUE;
                spelltab.st_isu[i] = TRUE;
                spelltab.st_fold[i] = MB_TOLOWER (i);
            }
            else if (MB_ISLOWER (i)) {
                spelltab.st_isw[i] = TRUE;
                spelltab.st_upper[i] = MB_TOUPPER (i);
            }
        }
    }
}

int spell_word_start (int startcol) {
    char_u *line;
    char_u *p;
    int col = 0;
    if (no_spell_checking (curwin))
        return startcol;
    line = ml_get_curline ();
    for (p = line + startcol; p > line;) {
        MB_PTR_BACK (line, p);
        if (spell_iswordp_nmw (p, curwin))
            break;
    }
    while (p > line) {
        col = (int) (p - line);
        MB_PTR_BACK (line, p);
        if (!spell_iswordp (p, curwin))
            break;
        col = 0;
    }
    return col;
}

void spell_expand_check_cap (colnr_T col) {
    spell_expand_need_cap = check_need_cap (curwin->w_cursor.lnum, col);
}

static void find_prefix (matchinf_T *mip, int mode) {
    idx_T arridx = 0;
    int len;
    int wlen = 0;
    int flen;
    int c;
    char_u *ptr;
    idx_T lo, hi, m;
    slang_T *slang = mip->mi_lp->lp_slang;
    char_u *byts;
    idx_T *idxs;
    byts = slang->sl_pbyts;
    if (byts == NULL)
        return;
    ptr = mip->mi_fword;
    flen = mip->mi_fwordlen;
    if (mode == FIND_COMPOUND) {
        ptr += mip->mi_compoff;
        flen -= mip->mi_compoff;
    }
    idxs = slang->sl_pidxs;
    for (;;) {
        if (flen == 0 && *mip->mi_fend != NUL)
            flen = fold_more (mip);
        len = byts[arridx++];
        if (byts[arridx] == 0) {
            mip->mi_prefarridx = arridx;
            mip->mi_prefcnt = len;
            while (len > 0 && byts[arridx] == 0) {
                ++arridx;
                --len;
            }
            mip->mi_prefcnt -= len;
            mip->mi_prefixlen = wlen;
            if (mode == FIND_COMPOUND)
                mip->mi_prefixlen += mip->mi_compoff;
            find_word (mip, FIND_PREFIX);
            if (len == 0)
                break;
        }
        if (ptr[wlen] == NUL)
            break;
        c = ptr[wlen];
        lo = arridx;
        hi = arridx + len - 1;
        while (lo < hi) {
            m = (lo + hi) / 2;
            if (byts[m] > c)
                hi = m - 1;
            else if (byts[m] < c)
                lo = m + 1;
            else {
                lo = hi = m;
                break;
            }
        }
        if (hi < lo || byts[lo] != c)
            break;
        arridx = idxs[lo];
        ++wlen;
        --flen;
    }
}

char_u *eval_soundfold (char_u *word) {
    langp_T *lp;
    char_u sound [MAXWLEN];
    int lpi;
    if (curwin->w_p_spell && *curwin->w_s->b_p_spl != NUL)
        for (lpi = 0; lpi < curwin->w_s->b_langp.ga_len; ++lpi) {
            lp = LANGP_ENTRY (curwin->w_s->b_langp, lpi);
            if (lp->lp_slang->sl_sal.ga_len > 0) {
                spell_soundfold (lp -> lp_slang, word, FALSE, sound);
                return vim_strsave (sound);
            }
        }
    return vim_strsave (word);
}

void spell_suggest (int count) {
    char_u *line;
    pos_T prev_cursor = curwin->w_cursor;
    char_u wcopy [MAXWLEN + 2];
    char_u *p;
    int i;
    int c;
    suginfo_T sug;
    suggest_T *stp;
    int mouse_used;
    int need_cap;
    int limit;
    int selected = count;
    int badlen = 0;
    int msg_scroll_save = msg_scroll;
    if (no_spell_checking (curwin))
        return;
    if (VIsual_active) {
        if (curwin->w_cursor.lnum != VIsual.lnum) {
            vim_beep (BO_SPELL);
            return;
        }
        badlen = (int) curwin->w_cursor.col - (int) VIsual.col;
        if (badlen < 0)
            badlen = -badlen;
        else
            curwin->w_cursor.col = VIsual.col;
        ++badlen;
        end_visual_mode ();
    }
    else if (spell_move_to (curwin, FORWARD, TRUE, TRUE, NULL) == 0 || curwin->w_cursor.col > prev_cursor.col) {
        curwin->w_cursor = prev_cursor;
        line = ml_get_curline ();
        p = line + curwin->w_cursor.col;
        while (p > line && spell_iswordp_nmw (p, curwin))
            MB_PTR_BACK (line, p);
        while (*p != NUL && !spell_iswordp_nmw (p, curwin))
            MB_PTR_ADV (p);
        if (!spell_iswordp_nmw (p, curwin)) {
            beep_flush ();
            return;
        }
        curwin->w_cursor.col = (colnr_T) (p - line);
    }
    need_cap = check_need_cap (curwin->w_cursor.lnum, curwin->w_cursor.col);
    line = vim_strsave (ml_get_curline ());
    if (line == NULL)
        goto skip;
    if (sps_limit > (int) Rows - 2)
        limit = (int) Rows - 2;
    else
        limit = sps_limit;
    spell_find_suggest (line + curwin -> w_cursor.col, badlen, & sug, limit, TRUE, need_cap, TRUE);
    if (sug.su_ga.ga_len == 0)
        MSG (_ ("Sorry, no suggestions"));
    else if (count > 0) {
        if (count > sug.su_ga.ga_len)
            smsg ((char_u *) _ ("Sorry, only %ld suggestions"), (long ) sug.su_ga.ga_len);
    }
    else {
        VIM_CLEAR (repl_from);
        VIM_CLEAR (repl_to);
        cmdmsg_rl = curwin->w_p_rl;
        if (cmdmsg_rl)
            msg_col = Columns - 1;
        msg_start ();
        msg_row = Rows - 1;
        lines_left = Rows;
        vim_snprintf ((char *) IObuff, IOSIZE, _ ("Change \"%.*s\" to:"), sug.su_badlen, sug.su_badptr);
        if (cmdmsg_rl && STRNCMP (IObuff, "Change", 6) == 0) {
            vim_snprintf ((char *) IObuff, IOSIZE, ":ot \"%.*s\" egnahC", sug.su_badlen, sug.su_badptr);
        }
        msg_puts (IObuff);
        msg_clr_eos ();
        msg_putchar ('\n');
        msg_scroll = TRUE;
        for (i = 0; i < sug.su_ga.ga_len; ++i) {
            stp = &SUG (sug.su_ga, i);
            vim_strncpy (wcopy, stp -> st_word, MAXWLEN);
            if (sug.su_badlen > stp->st_orglen)
                vim_strncpy (wcopy +stp->st_wordlen, sug.su_badptr + stp->st_orglen, sug.su_badlen - stp->st_orglen);
            vim_snprintf ((char *) IObuff, IOSIZE, "%2d", i + 1);
            if (cmdmsg_rl)
                rl_mirror (IObuff);
            msg_puts (IObuff);
            vim_snprintf ((char *) IObuff, IOSIZE, " \"%s\"", wcopy);
            msg_puts (IObuff);
            if (sug.su_badlen < stp->st_orglen) {
                vim_snprintf ((char *) IObuff, IOSIZE, _ (" < \"%.*s\""), stp -> st_orglen, sug.su_badptr);
                msg_puts (IObuff);
            }
            if (p_verbose > 0) {
                if (sps_flags & (SPS_DOUBLE | SPS_BEST))
                    vim_snprintf ((char *) IObuff, IOSIZE, " (%s%d - %d)", stp->st_salscore ? "s " : "", stp->st_score, stp->st_altscore);
                else
                    vim_snprintf ((char *) IObuff, IOSIZE, " (%d)", stp->st_score);
                if (cmdmsg_rl)
                    rl_mirror (IObuff +1);
                msg_advance (30);
                msg_puts (IObuff);
            }
            msg_putchar ('\n');
        }
        cmdmsg_rl = FALSE;
        msg_col = 0;
        selected = prompt_for_number (&mouse_used);
        if (mouse_used)
            selected -= lines_left;
        lines_left = Rows;
        msg_scroll = msg_scroll_save;
    }
    if (selected > 0 && selected <= sug.su_ga.ga_len && u_save_cursor () == OK) {
        stp = &SUG (sug.su_ga, selected -1);
        if (sug.su_badlen > stp->st_orglen) {
            repl_from = vim_strnsave (sug.su_badptr, sug.su_badlen);
            vim_snprintf ((char *) IObuff, IOSIZE, "%s%.*s", stp -> st_word, sug.su_badlen - stp -> st_orglen, sug.su_badptr + stp -> st_orglen);
            repl_to = vim_strsave (IObuff);
        }
        else {
            repl_from = vim_strnsave (sug.su_badptr, stp->st_orglen);
            repl_to = vim_strsave (stp->st_word);
        }
        p = alloc ((unsigned ) STRLEN (line) - stp->st_orglen + stp->st_wordlen + 1);
        if (p != NULL) {
            c = (int) (sug.su_badptr - line);
            mch_memmove (p, line, c);
            STRCPY (p + c, stp -> st_word);
            STRCAT (p, sug.su_badptr + stp -> st_orglen);
            ml_replace (curwin -> w_cursor.lnum, p, FALSE);
            curwin->w_cursor.col = c;
            ResetRedobuff ();
            AppendToRedobuff ((char_u *) "ciw");
            AppendToRedobuffLit (p + c, stp -> st_wordlen + sug.su_badlen - stp -> st_orglen);
            AppendCharToRedobuff (ESC);
            changed_bytes (curwin -> w_cursor.lnum, c);
        }
    }
    else
        curwin->w_cursor = prev_cursor;
    spell_find_cleanup (& sug);
skip :
    vim_free (line);
}

