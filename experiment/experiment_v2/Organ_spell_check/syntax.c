
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
struct subcommand {
    char *name;
    void (*func) (exarg_T *, int);
};
struct name_list {
    int flag;
    char *name;
};
struct syn_cluster_S {
    char_u *scl_name;
    char_u *scl_name_u;
    short  *scl_list;
};
struct sp_syn {
    int inc_tag;
    short  id;
    short  *cont_in_list;
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
struct hl_group {
    char_u *sg_name;
    char_u *sg_name_u;
    int sg_cleared;
    int sg_term;
    char_u *sg_start;
    char_u *sg_stop;
    int sg_term_attr;
    int sg_cterm;
    int sg_cterm_bold;
    int sg_cterm_fg;
    int sg_cterm_bg;
    int sg_cterm_attr;
    guicolor_T sg_gui_fg;
    guicolor_T sg_gui_bg;
    guicolor_T sg_gui_sp;
    GuiFont sg_font;
    char_u *sg_font_name;
    int sg_gui_attr;
    int sg_gui;
    char_u *sg_gui_fg_name;
    char_u *sg_gui_bg_name;
    char_u *sg_gui_sp_name;
    int sg_link;
    int sg_set;
    scid_T sg_scriptID;
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
struct state_item {
    int si_idx;
    int si_id;
    int si_trans_id;
    int si_m_lnum;
    int si_m_startcol;
    lpos_T si_m_endpos;
    lpos_T si_h_startpos;
    lpos_T si_h_endpos;
    lpos_T si_eoe_pos;
    int si_end_idx;
    int si_ends;
    int si_attr;
    long  si_flags;
    int si_seqnr;
    int si_cchar;
    short  *si_cont_list;
    short  *si_next_list;
    reg_extmatch_T *si_extmatch;
};
struct syn_pattern {
    char sp_type;
    char sp_syncing;
    int sp_flags;
    int sp_cchar;
    struct sp_syn sp_syn;
    short  sp_syn_match_id;
    char_u *sp_pattern;
    regprog_T *sp_prog;
    syn_time_T sp_time;
    int sp_ic;
    short  sp_off_flags;
    int sp_offsets [SPO_COUNT];
    short  *sp_cont_list;
    short  *sp_next_list;
    int sp_sync_idx;
    int sp_line_id;
    int sp_startcol;
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
EXTERN long  p_verbose;
int syn_time_on = FALSE;
win_T *syn_win;
EXTERN char_u *p_bg;
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
int keepend_level = -1;
EXTERN win_T *au_pending_free_win INIT (= NULL);
EXTERN char need_key_msg [] INIT (= N_ ("Need encryption key for \"%s\""));
EXTERN char_u no_lines_msg [] INIT (= N_ ("--No lines in buffer--"));
EXTERN struct msglist **msg_list INIT (= NULL);
EXTERN char_u *keep_msg INIT (= NULL);
EXTERN int msg_row;
char msg_no_items [] = N_ ("No Syntax items defined for this buffer");
EXTERN char_u e_prev_dir [] INIT (= N_ ("E459: Cannot go back to previous directory"));
EXTERN char_u e_noprevre [] INIT (= N_ ("E35: No previous regular expression"));
EXTERN char_u e_noprev [] INIT (= N_ ("E34: No previous command"));
EXTERN win_T *prevwin INIT (= NULL);
EXTERN tabpage_T *first_tabpage;
SPELL_EXTERN spelltab_T spelltab;
EXTERN char_u e_umark [] INIT (= N_ ("E78: Unknown mark"));
EXTERN char_u e_marknotset [] INIT (= N_ ("E20: Mark not set"));
EXTERN char_u e_longname [] INIT (= N_ ("E75: Name too long"));
EXTERN char_u e_noname [] INIT (= N_ ("E32: No file name"));
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
struct subcommand subcommands [] = {{"case", syn_cmd_case}, {"clear", syn_cmd_clear}, {"cluster", syn_cmd_cluster}, {"conceal", syn_cmd_conceal}, {"enable", syn_cmd_enable}, {"include", syn_cmd_include}, {"iskeyword", syn_cmd_iskeyword}, {"keyword", syn_cmd_keyword}, {"list", syn_cmd_list}, {"manual", syn_cmd_manual}, {"match", syn_cmd_match}, {"on", syn_cmd_on}, {"off", syn_cmd_off}, {"region", syn_cmd_region}, {"reset", syn_cmd_reset}, {"spell", syn_cmd_spell}, {"sync", syn_cmd_sync}, {"", syn_cmd_list}, {NULL, NULL}};
synblock_T *syn_block;
int running_syn_inc_tag = 0;
char_u **syn_cmdlinep;
int include_link = 0;
int include_default = 0;
int include_none = 0;
char * (spo_name_tab [SPO_COUNT]) = {"ms=", "me=", "hs=", "he=", "rs=", "re=", "lc="};
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
int current_finished = 0;
int current_syn_inc_tag = 0;
int current_sub_char = 0;
int current_seqnr = 0;
int current_flags = 0;
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
garray_T gui_attr_table = {0, 0, 0, 0, NULL};
garray_T cterm_attr_table = {0, 0, 0, 0, NULL};
garray_T term_attr_table = {0, 0, 0, 0, NULL};
proftime_T *syn_tm;
buf_T *syn_buf;
int current_attr = 0;
EXTERN char_u e_positive [] INIT (= N_ ("E487: Argument must be positive"));
EXTERN hlf_T edit_submode_highl;
EXTERN int highlight_attr [HLF_COUNT];
EXTERN int p_hls;
EXTERN char_u *p_hl;
EXTERN char_u *p_hlg;
char * (highlight_init_dark []) = {CENT ("Directory term=bold ctermfg=LightCyan", "Directory term=bold ctermfg=LightCyan guifg=Cyan"), CENT ("LineNr term=underline ctermfg=Yellow", "LineNr term=underline ctermfg=Yellow guifg=Yellow"), CENT ("CursorLineNr term=bold ctermfg=Yellow", "CursorLineNr term=bold ctermfg=Yellow gui=bold guifg=Yellow"), CENT ("MoreMsg term=bold ctermfg=LightGreen", "MoreMsg term=bold ctermfg=LightGreen gui=bold guifg=SeaGreen"), CENT ("Question term=standout ctermfg=LightGreen", "Question term=standout ctermfg=LightGreen gui=bold guifg=Green"), CENT ("Search term=reverse ctermbg=Yellow ctermfg=Black", "Search term=reverse ctermbg=Yellow ctermfg=Black guibg=Yellow guifg=Black"), CENT ("SpecialKey term=bold ctermfg=LightBlue", "SpecialKey term=bold ctermfg=LightBlue guifg=Cyan"), CENT ("SpellBad term=reverse ctermbg=Red", "SpellBad term=reverse ctermbg=Red guisp=Red gui=undercurl"), CENT ("SpellCap term=reverse ctermbg=Blue", "SpellCap term=reverse ctermbg=Blue guisp=Blue gui=undercurl"), CENT ("SpellRare term=reverse ctermbg=Magenta", "SpellRare term=reverse ctermbg=Magenta guisp=Magenta gui=undercurl"), CENT ("SpellLocal term=underline ctermbg=Cyan", "SpellLocal term=underline ctermbg=Cyan guisp=Cyan gui=undercurl"), CENT ("PmenuThumb ctermbg=White", "PmenuThumb ctermbg=White guibg=White"), CENT ("Pmenu ctermbg=Magenta ctermfg=Black", "Pmenu ctermbg=Magenta ctermfg=Black guibg=Magenta"), CENT ("PmenuSel ctermbg=Black ctermfg=DarkGrey", "PmenuSel ctermbg=Black ctermfg=DarkGrey guibg=DarkGrey"), CENT ("Title term=bold ctermfg=LightMagenta", "Title term=bold ctermfg=LightMagenta gui=bold guifg=Magenta"), CENT ("WarningMsg term=standout ctermfg=LightRed", "WarningMsg term=standout ctermfg=LightRed guifg=Red"), CENT ("WildMenu term=standout ctermbg=Yellow ctermfg=Black", "WildMenu term=standout ctermbg=Yellow ctermfg=Black guibg=Yellow guifg=Black"), CENT ("Folded term=standout ctermbg=DarkGrey ctermfg=Cyan", "Folded term=standout ctermbg=DarkGrey ctermfg=Cyan guibg=DarkGrey guifg=Cyan"), CENT ("FoldColumn term=standout ctermbg=DarkGrey ctermfg=Cyan", "FoldColumn term=standout ctermbg=DarkGrey ctermfg=Cyan guibg=Grey guifg=Cyan"), CENT ("SignColumn term=standout ctermbg=DarkGrey ctermfg=Cyan", "SignColumn term=standout ctermbg=DarkGrey ctermfg=Cyan guibg=Grey guifg=Cyan"), CENT ("Visual term=reverse", "Visual term=reverse guibg=DarkGrey"), CENT ("DiffAdd term=bold ctermbg=DarkBlue", "DiffAdd term=bold ctermbg=DarkBlue guibg=DarkBlue"), CENT ("DiffChange term=bold ctermbg=DarkMagenta", "DiffChange term=bold ctermbg=DarkMagenta guibg=DarkMagenta"), CENT ("DiffDelete term=bold ctermfg=Blue ctermbg=DarkCyan", "DiffDelete term=bold ctermfg=Blue ctermbg=DarkCyan gui=bold guifg=Blue guibg=DarkCyan"), CENT ("TabLine term=underline cterm=underline ctermfg=white ctermbg=DarkGrey", "TabLine term=underline cterm=underline ctermfg=white ctermbg=DarkGrey gui=underline guibg=DarkGrey"), CENT ("CursorColumn term=reverse ctermbg=DarkGrey", "CursorColumn term=reverse ctermbg=DarkGrey guibg=Grey40"), CENT ("CursorLine term=underline cterm=underline", "CursorLine term=underline cterm=underline guibg=Grey40"), CENT ("ColorColumn term=reverse ctermbg=DarkRed", "ColorColumn term=reverse ctermbg=DarkRed guibg=DarkRed"), CENT ("MatchParen term=reverse ctermbg=DarkCyan", "MatchParen term=reverse ctermbg=DarkCyan guibg=DarkCyan"), CENT ("Conceal ctermbg=DarkGrey ctermfg=LightGrey", "Conceal ctermbg=DarkGrey ctermfg=LightGrey guibg=DarkGrey guifg=LightGrey"), "Normal gui=NONE", CENT ("StatusLineTerm term=reverse,bold cterm=bold ctermfg=Black ctermbg=LightGreen", "StatusLineTerm term=reverse,bold cterm=bold ctermfg=Black ctermbg=LightGreen gui=bold guifg=bg guibg=LightGreen"), CENT ("StatusLineTermNC term=reverse ctermfg=Black ctermbg=LightGreen", "StatusLineTermNC term=reverse ctermfg=Black ctermbg=LightGreen guifg=bg guibg=LightGreen"), CENT ("ToolbarLine term=underline ctermbg=DarkGrey", "ToolbarLine term=underline ctermbg=DarkGrey guibg=Grey50"), CENT ("ToolbarButton cterm=bold ctermfg=Black ctermbg=LightGrey",
  "ToolbarButton cterm=bold ctermfg=Black ctermbg=LightGrey gui=bold guifg=Black guibg=LightGrey"), NULL};
char * (highlight_init_light []) = {CENT ("Directory term=bold ctermfg=DarkBlue", "Directory term=bold ctermfg=DarkBlue guifg=Blue"), CENT ("LineNr term=underline ctermfg=Brown", "LineNr term=underline ctermfg=Brown guifg=Brown"), CENT ("CursorLineNr term=bold ctermfg=Brown", "CursorLineNr term=bold ctermfg=Brown gui=bold guifg=Brown"), CENT ("MoreMsg term=bold ctermfg=DarkGreen", "MoreMsg term=bold ctermfg=DarkGreen gui=bold guifg=SeaGreen"), CENT ("Question term=standout ctermfg=DarkGreen", "Question term=standout ctermfg=DarkGreen gui=bold guifg=SeaGreen"), CENT ("Search term=reverse ctermbg=Yellow ctermfg=NONE", "Search term=reverse ctermbg=Yellow ctermfg=NONE guibg=Yellow guifg=NONE"), CENT ("SpellBad term=reverse ctermbg=LightRed", "SpellBad term=reverse ctermbg=LightRed guisp=Red gui=undercurl"), CENT ("SpellCap term=reverse ctermbg=LightBlue", "SpellCap term=reverse ctermbg=LightBlue guisp=Blue gui=undercurl"), CENT ("SpellRare term=reverse ctermbg=LightMagenta", "SpellRare term=reverse ctermbg=LightMagenta guisp=Magenta gui=undercurl"), CENT ("SpellLocal term=underline ctermbg=Cyan", "SpellLocal term=underline ctermbg=Cyan guisp=DarkCyan gui=undercurl"), CENT ("PmenuThumb ctermbg=Black", "PmenuThumb ctermbg=Black guibg=Black"), CENT ("Pmenu ctermbg=LightMagenta ctermfg=Black", "Pmenu ctermbg=LightMagenta ctermfg=Black guibg=LightMagenta"), CENT ("PmenuSel ctermbg=LightGrey ctermfg=Black", "PmenuSel ctermbg=LightGrey ctermfg=Black guibg=Grey"), CENT ("SpecialKey term=bold ctermfg=DarkBlue", "SpecialKey term=bold ctermfg=DarkBlue guifg=Blue"), CENT ("Title term=bold ctermfg=DarkMagenta", "Title term=bold ctermfg=DarkMagenta gui=bold guifg=Magenta"), CENT ("WarningMsg term=standout ctermfg=DarkRed", "WarningMsg term=standout ctermfg=DarkRed guifg=Red"), CENT ("WildMenu term=standout ctermbg=Yellow ctermfg=Black", "WildMenu term=standout ctermbg=Yellow ctermfg=Black guibg=Yellow guifg=Black"), CENT ("Folded term=standout ctermbg=Grey ctermfg=DarkBlue", "Folded term=standout ctermbg=Grey ctermfg=DarkBlue guibg=LightGrey guifg=DarkBlue"), CENT ("FoldColumn term=standout ctermbg=Grey ctermfg=DarkBlue", "FoldColumn term=standout ctermbg=Grey ctermfg=DarkBlue guibg=Grey guifg=DarkBlue"), CENT ("SignColumn term=standout ctermbg=Grey ctermfg=DarkBlue", "SignColumn term=standout ctermbg=Grey ctermfg=DarkBlue guibg=Grey guifg=DarkBlue"), CENT ("Visual term=reverse", "Visual term=reverse guibg=LightGrey"), CENT ("DiffAdd term=bold ctermbg=LightBlue", "DiffAdd term=bold ctermbg=LightBlue guibg=LightBlue"), CENT ("DiffChange term=bold ctermbg=LightMagenta", "DiffChange term=bold ctermbg=LightMagenta guibg=LightMagenta"), CENT ("DiffDelete term=bold ctermfg=Blue ctermbg=LightCyan", "DiffDelete term=bold ctermfg=Blue ctermbg=LightCyan gui=bold guifg=Blue guibg=LightCyan"), CENT ("TabLine term=underline cterm=underline ctermfg=black ctermbg=LightGrey", "TabLine term=underline cterm=underline ctermfg=black ctermbg=LightGrey gui=underline guibg=LightGrey"), CENT ("CursorColumn term=reverse ctermbg=LightGrey", "CursorColumn term=reverse ctermbg=LightGrey guibg=Grey90"), CENT ("CursorLine term=underline cterm=underline", "CursorLine term=underline cterm=underline guibg=Grey90"), CENT ("ColorColumn term=reverse ctermbg=LightRed", "ColorColumn term=reverse ctermbg=LightRed guibg=LightRed"), CENT ("Conceal ctermbg=DarkGrey ctermfg=LightGrey", "Conceal ctermbg=DarkGrey ctermfg=LightGrey guibg=DarkGrey guifg=LightGrey"), CENT ("MatchParen term=reverse ctermbg=Cyan", "MatchParen term=reverse ctermbg=Cyan guibg=Cyan"), "Normal gui=NONE", CENT ("StatusLineTerm term=reverse,bold cterm=bold ctermfg=White ctermbg=DarkGreen", "StatusLineTerm term=reverse,bold cterm=bold ctermfg=White ctermbg=DarkGreen gui=bold guifg=bg guibg=DarkGreen"), CENT ("StatusLineTermNC term=reverse ctermfg=White ctermbg=DarkGreen", "StatusLineTermNC term=reverse ctermfg=White ctermbg=DarkGreen guifg=bg guibg=DarkGreen"), CENT ("ToolbarLine term=underline ctermbg=LightGrey", "ToolbarLine term=underline ctermbg=LightGrey guibg=LightGrey"), CENT (
  "ToolbarButton cterm=bold ctermfg=White ctermbg=DarkGrey", "ToolbarButton cterm=bold ctermfg=White ctermbg=DarkGrey gui=bold guifg=White guibg=Grey40"), NULL};
char * (highlight_init_both []) = {CENT ("ErrorMsg term=standout ctermbg=DarkRed ctermfg=White", "ErrorMsg term=standout ctermbg=DarkRed ctermfg=White guibg=Red guifg=White"), CENT ("IncSearch term=reverse cterm=reverse", "IncSearch term=reverse cterm=reverse gui=reverse"), CENT ("ModeMsg term=bold cterm=bold", "ModeMsg term=bold cterm=bold gui=bold"), CENT ("NonText term=bold ctermfg=Blue", "NonText term=bold ctermfg=Blue gui=bold guifg=Blue"), CENT ("StatusLine term=reverse,bold cterm=reverse,bold", "StatusLine term=reverse,bold cterm=reverse,bold gui=reverse,bold"), CENT ("StatusLineNC term=reverse cterm=reverse", "StatusLineNC term=reverse cterm=reverse gui=reverse"), "default link EndOfBuffer NonText", CENT ("VertSplit term=reverse cterm=reverse", "VertSplit term=reverse cterm=reverse gui=reverse"), CENT ("DiffText term=reverse cterm=bold ctermbg=Red", "DiffText term=reverse cterm=bold ctermbg=Red gui=bold guibg=Red"), CENT ("PmenuSbar ctermbg=Grey", "PmenuSbar ctermbg=Grey guibg=Grey"), CENT ("TabLineSel term=bold cterm=bold", "TabLineSel term=bold cterm=bold gui=bold"), CENT ("TabLineFill term=reverse cterm=reverse", "TabLineFill term=reverse cterm=reverse gui=reverse"), "Cursor guibg=fg guifg=bg", "lCursor guibg=fg guifg=bg", "default link QuickFixLine Search", NULL};
int current_next_flags = 0;
short  *current_next_list = NULL;
int next_seqnr = 1;
int hl_attr_table [] = {HL_BOLD, HL_STANDOUT, HL_UNDERLINE, HL_UNDERCURL, HL_ITALIC, HL_INVERSE, HL_INVERSE, HL_NOCOMBINE, HL_STRIKETHROUGH, 0};
char * (hl_name_table []) = {"bold", "standout", "underline", "undercurl", "italic", "reverse", "inverse", "nocombine", "strikethrough", "NONE"};
garray_T highlight_ga;
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
int current_line_id = 0;
int current_trans_id = 0;
int current_id = 0;
EXTERN int autocmd_fname_full;
EXTERN char_u *autocmd_fname INIT (= NULL);
EXTERN unsigned  swb_flags;
EXTERN pos_T where_paste_started;
garray_T current_state = {0, 0, 0, 0, NULL};
int current_state_stored = 0;
EXTERN char_u e_zerocount [] INIT (= N_ ("E939: Positive count required"));
EXTERN char_u e_nomatch2 [] INIT (= N_ ("E480: No match: %s"));
EXTERN char_u e_nomatch [] INIT (= N_ ("E479: No match"));
EXTERN char_u *autocmd_match INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_out INIT (= NULL);
EXTERN reg_extmatch_T *re_extmatch_in INIT (= NULL);
EXTERN linenr_T search_match_lines;
int last_matchgroup;
reg_extmatch_T *next_match_extmatch = NULL;
int next_match_end_idx;
lpos_T next_match_eoe_pos;
lpos_T next_match_eos_pos;
long  next_match_flags;
int next_match_idx;
lpos_T next_match_h_endpos;
lpos_T next_match_h_startpos;
lpos_T next_match_m_endpos;
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
int color_numbers_8 [28] = {0, 4, 2, 6, 1, 5, 3, 3, 7, 7, 7, 7, 0 + 8, 0 + 8, 4 + 8, 4 + 8, 2 + 8, 2 + 8, 6 + 8, 6 + 8, 1 + 8, 1 + 8, 5 + 8, 5 + 8, 3 + 8, 3 + 8, 7 + 8, -1};
int color_numbers_256 [28] = {0, 4, 2, 6, 1, 5, 130, 130, 248, 248, 7, 7, 242, 242, 12, 81, 10, 121, 14, 159, 9, 224, 13, 225, 11, 229, 15, -1};
int color_numbers_88 [28] = {0, 4, 2, 6, 1, 5, 32, 72, 84, 84, 7, 7, 82, 82, 12, 43, 10, 61, 14, 63, 9, 74, 13, 75, 11, 78, 15, -1};
int color_numbers_16 [28] = {0, 1, 2, 3, 4, 5, 6, 6, 7, 7, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, -1};
char * (color_names [28]) = {"Black", "DarkBlue", "DarkGreen", "DarkCyan", "DarkRed", "DarkMagenta", "Brown", "DarkYellow", "Gray", "Grey", "LightGray", "LightGrey", "DarkGray", "DarkGrey", "Blue", "LightBlue", "Green", "LightGreen", "Cyan", "LightCyan", "Red", "LightRed", "Magenta", "LightMagenta", "Yellow", "LightYellow", "White", "NONE"};
colnr_T current_col = 0;
linenr_T current_lnum = 0;
int next_match_col;
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

attrentry_T *syn_cterm_attr2entry (int attr) {
    attr -= ATTR_OFF;
    if (attr >= cterm_attr_table.ga_len)
        return NULL;
    return &(CTERM_ATTR_ENTRY (attr));
}

#define LIST_ATTR   1

#define LIST_STRING 2

#define LIST_INT    3

attrentry_T *syn_term_attr2entry (int attr) {
    attr -= ATTR_OFF;
    if (attr >= term_attr_table.ga_len)
        return NULL;
    return &(TERM_ATTR_ENTRY (attr));
}

attrentry_T *syn_gui_attr2entry (int attr) {
    attr -= ATTR_OFF;
    if (attr >= gui_attr_table.ga_len)
        return NULL;
    return &(GUI_ATTR_ENTRY (attr));
}

guicolor_T color_name2handle (char_u *name) {
    if (STRCMP (name, "NONE") == 0)
        return INVALCOLOR;
    if (STRICMP (name, "fg") == 0 || STRICMP (name, "foreground") == 0) {
        if (gui.in_use)
            return gui.norm_pixel;
        if (cterm_normal_fg_gui_color != INVALCOLOR)
            return cterm_normal_fg_gui_color;
        return GUI_GET_COLOR ((char_u *) (*p_bg == 'l' ? "black" : "white"));
    }
    if (STRICMP (name, "bg") == 0 || STRICMP (name, "background") == 0) {
        if (gui.in_use)
            return gui.back_pixel;
        if (cterm_normal_bg_gui_color != INVALCOLOR)
            return cterm_normal_bg_gui_color;
        return GUI_GET_COLOR ((char_u *) (*p_bg == 'l' ? "white" : "black"));
    }
    return GUI_GET_COLOR (name);
}

int syn_id2colors (int hl_id, guicolor_T *fgp, guicolor_T *bgp) {
    struct hl_group *sgp;
    hl_id = syn_get_final_id (hl_id);
    sgp = &HL_TABLE ()[hl_id - 1];
    *fgp = sgp->sg_gui_fg;
    *bgp = sgp->sg_gui_bg;
    return sgp->sg_gui;
}

int syn_get_final_id (int hl_id) {
    int count;
    struct hl_group *sgp;
    if (hl_id > highlight_ga.ga_len || hl_id < 1)
        return 0;
    for (count = 100; --count >= 0;) {
        sgp = &HL_TABLE ()[hl_id - 1];
        if (sgp->sg_link == 0 || sgp->sg_link > highlight_ga.ga_len)
            break;
        hl_id = sgp->sg_link;
    }
    return hl_id;
}

int syn_name2id (char_u *name) {
    int i;
    char_u name_u [200];
    vim_strncpy (name_u, name, 199);
    vim_strup (name_u);
    for (i = highlight_ga.ga_len; --i >= 0;)
        if (HL_TABLE ()[i].sg_name_u != NULL && STRCMP (name_u, HL_TABLE ()[i].sg_name_u) == 0)
            break;
    return i + 1;
}

int highlight_changed (void) {
    int hlf;
    int i;
    char_u *p;
    int attr;
    char_u *end;
    int id;
    static int hl_flags [HLF_COUNT] = HL_FLAGS;
    need_highlight_changed = FALSE;
    for (hlf = 0; hlf < (int) HLF_COUNT; ++hlf)
        highlight_attr[hlf] = 0;
    for (i = 0; i < 2; ++i) {
        if (i)
            p = p_hl;
        else
            p = get_highlight_default ();
        if (p == NULL)
            continue;
        while (*p) {
            for (hlf = 0; hlf < (int) HLF_COUNT; ++hlf)
                if (hl_flags[hlf] == *p)
                    break;
            ++p;
            if (hlf == (int) HLF_COUNT || *p == NUL)
                return FAIL;
            attr = 0;
            for (; *p && *p != ','; ++p) {
                if (VIM_ISWHITE (*p))
                    continue;
                if (attr > HL_ALL)
                    return FAIL;
                switch (*p) {
                case 'b' :
                    attr |= HL_BOLD;
                    break;
                case 'i' :
                    attr |= HL_ITALIC;
                    break;
                case '-' :
                case 'n' :
                    break;
                case 'r' :
                    attr |= HL_INVERSE;
                    break;
                case 's' :
                    attr |= HL_STANDOUT;
                    break;
                case 'u' :
                    attr |= HL_UNDERLINE;
                    break;
                case 'c' :
                    attr |= HL_UNDERCURL;
                    break;
                case 't' :
                    attr |= HL_STRIKETHROUGH;
                    break;
                case ':' :
                    ++p;
                    if (attr || *p == NUL)
                        return FAIL;
                    end = vim_strchr (p, ',');
                    if (end == NULL)
                        end = p + STRLEN (p);
                    id = syn_check_group (p, (int) (end - p));
                    if (id == 0)
                        return FAIL;
                    attr = syn_id2attr (id);
                    p = end - 1;
                    break;
                default :
                    return FAIL;
                }
            }
            highlight_attr[hlf] = attr;
            p = skip_to_option_part (p);
        }
    }
    return OK;
}

int syn_check_group (char_u *pp, int len) {
    int id;
    char_u *name;
    name = vim_strnsave (pp, len);
    if (name == NULL)
        return 0;
    id = syn_name2id (name);
    if (id == 0)
        id = syn_add_group (name);
    else
        vim_free (name);
    return id;
}

static int syn_add_group (char_u *name) {
    char_u *p;
    for (p = name; *p != NUL; ++p) {
        if (!vim_isprintc (*p)) {
            EMSG (_ ("E669: Unprintable character in group name"));
            vim_free (name);
            return 0;
        }
        else if (!ASCII_ISALNUM (*p) && *p != '_') {
            msg_source (HL_ATTR (HLF_W));
            MSG (_ ("W18: Invalid character in group name"));
            break;
        }
    }
    if (highlight_ga.ga_data == NULL) {
        highlight_ga.ga_itemsize = sizeof (struct hl_group);
        highlight_ga.ga_growsize = 10;
    }
    if (highlight_ga.ga_len >= MAX_HL_ID) {
        EMSG (_ ("E849: Too many highlight and syntax groups"));
        vim_free (name);
        return 0;
    }
    if (ga_grow (&highlight_ga, 1) == FAIL) {
        vim_free (name);
        return 0;
    }
    vim_memset (& (HL_TABLE () [highlight_ga.ga_len]), 0, sizeof (struct hl_group));
    HL_TABLE ()[highlight_ga.ga_len].sg_name = name;
    HL_TABLE ()[highlight_ga.ga_len].sg_name_u = vim_strsave_up (name);
    HL_TABLE ()[highlight_ga.ga_len].sg_gui_bg = INVALCOLOR;
    HL_TABLE ()[highlight_ga.ga_len].sg_gui_fg = INVALCOLOR;
    HL_TABLE ()[highlight_ga.ga_len].sg_gui_sp = INVALCOLOR;
    ++highlight_ga.ga_len;
    return highlight_ga.ga_len;
}

int syn_id2attr (int hl_id) {
    int attr;
    struct hl_group *sgp;
    hl_id = syn_get_final_id (hl_id);
    sgp = &HL_TABLE ()[hl_id - 1];
    if (gui.in_use)
        attr = sgp->sg_gui_attr;
    else if (IS_CTERM)
        attr = sgp->sg_cterm_attr;
    else
        attr = sgp->sg_term_attr;
    return attr;
}

static void set_hl_attr (int idx) {
    attrentry_T at_en;
    struct hl_group *sgp = HL_TABLE () + idx;
    if (sgp->sg_name_u != NULL && STRCMP (sgp->sg_name_u, "NORMAL") == 0)
        return;
    if (sgp->sg_gui_fg == INVALCOLOR && sgp->sg_gui_bg == INVALCOLOR && sgp->sg_gui_sp == INVALCOLOR && sgp->sg_font == NOFONT) {
        sgp->sg_gui_attr = sgp->sg_gui;
    }
    else {
        at_en.ae_attr = sgp->sg_gui;
        at_en.ae_u.gui.fg_color = sgp->sg_gui_fg;
        at_en.ae_u.gui.bg_color = sgp->sg_gui_bg;
        at_en.ae_u.gui.sp_color = sgp->sg_gui_sp;
        at_en.ae_u.gui.font = sgp->sg_font;
        sgp->sg_gui_attr = get_attr_entry (&gui_attr_table, &at_en);
    }
    if (sgp->sg_start == NULL && sgp->sg_stop == NULL)
        sgp->sg_term_attr = sgp->sg_term;
    else {
        at_en.ae_attr = sgp->sg_term;
        at_en.ae_u.term.start = sgp->sg_start;
        at_en.ae_u.term.stop = sgp->sg_stop;
        sgp->sg_term_attr = get_attr_entry (&term_attr_table, &at_en);
    }
    if (sgp->sg_cterm_fg == 0 && sgp->sg_cterm_bg == 0 && sgp->sg_gui_fg == INVALCOLOR && sgp->sg_gui_bg == INVALCOLOR)
        sgp->sg_cterm_attr = sgp->sg_cterm;
    else {
        at_en.ae_attr = sgp->sg_cterm;
        at_en.ae_u.cterm.fg_color = sgp->sg_cterm_fg;
        at_en.ae_u.cterm.bg_color = sgp->sg_cterm_bg;
        at_en.ae_u.cterm.fg_rgb = GUI_MCH_GET_RGB2 (sgp->sg_gui_fg);
        at_en.ae_u.cterm.bg_rgb = GUI_MCH_GET_RGB2 (sgp->sg_gui_bg);
        sgp->sg_cterm_attr = get_attr_entry (&cterm_attr_table, &at_en);
    }
}

static int get_attr_entry (garray_T *table, attrentry_T *aep) {
    int i;
    attrentry_T *taep;
    static int recursive = FALSE;
    table->ga_itemsize = sizeof (attrentry_T);
    table->ga_growsize = 7;
    for (i = 0; i < table->ga_len; ++i) {
        taep = &(((attrentry_T *) table->ga_data)[i]);
        if (aep->ae_attr == taep->ae_attr && ((table == &gui_attr_table && (aep->ae_u.gui.fg_color == taep->ae_u.gui.fg_color && aep->ae_u.gui.bg_color == taep->ae_u.gui.bg_color && aep->ae_u.gui.sp_color == taep->ae_u.gui.sp_color && aep->ae_u.gui.font == taep->ae_u.gui.font)) || (table == &term_attr_table && (aep->ae_u.term.start == NULL) == (taep->ae_u.term.start == NULL) && (aep->ae_u.term.start == NULL || STRCMP (aep->ae_u.term.start, taep->ae_u.term.start) == 0) && (aep->ae_u.term.stop == NULL) == (taep->ae_u.term.stop == NULL) && (aep->ae_u.term.stop == NULL || STRCMP (aep->ae_u.term.stop, taep->ae_u.term.stop) == 0)) || (table == &cterm_attr_table && aep->ae_u.cterm.fg_color == taep->ae_u.cterm.fg_color && aep->ae_u.cterm.bg_color == taep->ae_u.cterm.bg_color && aep->ae_u.cterm.fg_rgb == taep->ae_u.cterm.fg_rgb && aep->ae_u.cterm.bg_rgb == taep->ae_u.cterm.bg_rgb)))
            return i + ATTR_OFF;
    }
    if (table->ga_len + ATTR_OFF > MAX_TYPENR) {
        if (recursive) {
            EMSG (_ ("E424: Too many different highlighting attributes in use"));
            return 0;
        }
        recursive = TRUE;
        clear_hl_tables ();
        must_redraw = CLEAR;
        for (i = 0; i < highlight_ga.ga_len; ++i)
            set_hl_attr (i);
        recursive = FALSE;
    }
    if (ga_grow (table, 1) == FAIL)
        return 0;
    taep = &(((attrentry_T *) table->ga_data)[table->ga_len]);
    vim_memset (taep, 0, sizeof (attrentry_T));
    taep->ae_attr = aep->ae_attr;
    if (table == &gui_attr_table) {
        taep->ae_u.gui.fg_color = aep->ae_u.gui.fg_color;
        taep->ae_u.gui.bg_color = aep->ae_u.gui.bg_color;
        taep->ae_u.gui.sp_color = aep->ae_u.gui.sp_color;
        taep->ae_u.gui.font = aep->ae_u.gui.font;
    }
    if (table == &term_attr_table) {
        if (aep->ae_u.term.start == NULL)
            taep->ae_u.term.start = NULL;
        else
            taep->ae_u.term.start = vim_strsave (aep->ae_u.term.start);
        if (aep->ae_u.term.stop == NULL)
            taep->ae_u.term.stop = NULL;
        else
            taep->ae_u.term.stop = vim_strsave (aep->ae_u.term.stop);
    }
    else if (table == &cterm_attr_table) {
        taep->ae_u.cterm.fg_color = aep->ae_u.cterm.fg_color;
        taep->ae_u.cterm.bg_color = aep->ae_u.cterm.bg_color;
        taep->ae_u.cterm.fg_rgb = aep->ae_u.cterm.fg_rgb;
        taep->ae_u.cterm.bg_rgb = aep->ae_u.cterm.bg_rgb;
    }
    ++table->ga_len;
    return (table->ga_len - 1 + ATTR_OFF);
}

void clear_hl_tables (void) {
    int i;
    attrentry_T *taep;
    ga_clear (& gui_attr_table);
    for (i = 0; i < term_attr_table.ga_len; ++i) {
        taep = &(((attrentry_T *) term_attr_table.ga_data)[i]);
        vim_free (taep -> ae_u.term.start);
        vim_free (taep -> ae_u.term.stop);
    }
    ga_clear (& term_attr_table);
    ga_clear (& cterm_attr_table);
}

int syn_attr2attr (int attr) {
    attrentry_T *aep;
    if (gui.in_use)
        aep = syn_gui_attr2entry (attr);
    else if (IS_CTERM)
        aep = syn_cterm_attr2entry (attr);
    else
        aep = syn_term_attr2entry (attr);
    if (aep == NULL)
        return 0;
    return aep->ae_attr;
}

void reset_synblock (win_T *wp) {
    if (wp->w_s != &wp->w_buffer->b_s) {
        syntax_clear (wp -> w_s);
        vim_free (wp -> w_s);
        wp->w_s = &wp->w_buffer->b_s;
    }
}

void syntax_clear (synblock_T *block) {
    int i;
    block->b_syn_error = FALSE;
    block->b_syn_slow = FALSE;
    block->b_syn_ic = FALSE;
    block->b_syn_spell = SYNSPL_DEFAULT;
    block->b_syn_containedin = FALSE;
    block->b_syn_conceal = FALSE;
    clear_keywtab (& block -> b_keywtab);
    clear_keywtab (& block -> b_keywtab_ic);
    for (i = block->b_syn_patterns.ga_len; --i >= 0;)
        syn_clear_pattern (block, i);
    ga_clear (& block -> b_syn_patterns);
    for (i = block->b_syn_clusters.ga_len; --i >= 0;)
        syn_clear_cluster (block, i);
    ga_clear (& block -> b_syn_clusters);
    block->b_spell_cluster_id = 0;
    block->b_nospell_cluster_id = 0;
    block->b_syn_sync_flags = 0;
    block->b_syn_sync_minlines = 0;
    block->b_syn_sync_maxlines = 0;
    block->b_syn_sync_linebreaks = 0;
    vim_regfree (block -> b_syn_linecont_prog);
    block->b_syn_linecont_prog = NULL;
    VIM_CLEAR (block -> b_syn_linecont_pat);
    block->b_syn_folditems = 0;
    clear_string_option (& block -> b_syn_isk);
    syn_stack_free_all (block);
    invalidate_current_state ();
    running_syn_inc_tag = 0;
}

static void clear_keywtab (hashtab_T *ht) {
    hashitem_T *hi;
    int todo;
    keyentry_T *kp;
    keyentry_T *kp_next;
    todo = (int) ht->ht_used;
    for (hi = ht->ht_array; todo > 0; ++hi) {
        if (!HASHITEM_EMPTY (hi)) {
            --todo;
            for (kp = HI2KE (hi); kp != NULL; kp = kp_next) {
                kp_next = kp->ke_next;
                vim_free (kp -> next_list);
                vim_free (kp -> k_syn.cont_in_list);
                vim_free (kp);
            }
        }
    }
    hash_clear (ht);
    hash_init (ht);
}

static void syn_clear_pattern (synblock_T *block, int i) {
    vim_free (SYN_ITEMS (block) [i].sp_pattern);
    vim_regfree (SYN_ITEMS (block) [i].sp_prog);
    if (i == 0 || SYN_ITEMS (block)[i - 1].sp_type != SPTYPE_START) {
        vim_free (SYN_ITEMS (block) [i].sp_cont_list);
        vim_free (SYN_ITEMS (block) [i].sp_next_list);
        vim_free (SYN_ITEMS (block) [i].sp_syn.cont_in_list);
    }
}

static void syn_clear_cluster (synblock_T *block, int i) {
    vim_free (SYN_CLSTR (block) [i].scl_name);
    vim_free (SYN_CLSTR (block) [i].scl_name_u);
    vim_free (SYN_CLSTR (block) [i].scl_list);
}

void syn_stack_free_all (synblock_T *block) {
    win_T *wp;
    syn_stack_free_block (block);
    FOR_ALL_WINDOWS (wp) {
        if (wp->w_s == block && foldmethodIsSyntax (wp))
            foldUpdateAll (wp);
    }
}

static void syn_stack_free_block (synblock_T *block) {
    synstate_T *p;
    if (block->b_sst_array != NULL) {
        for (p = block->b_sst_first; p != NULL; p = p->sst_next)
            clear_syn_state (p);
        VIM_CLEAR (block -> b_sst_array);
        block->b_sst_len = 0;
    }
}

static void clear_syn_state (synstate_T *p) {
    int i;
    garray_T *gap;
    if (p->sst_stacksize > SST_FIX_STATES) {
        gap = &(p->sst_union.sst_ga);
        for (i = 0; i < gap->ga_len; i++)
            unref_extmatch (SYN_STATE_P (gap)[i].bs_extmatch);
        ga_clear (gap);
    }
    else {
        for (i = 0; i < p->sst_stacksize; i++)
            unref_extmatch (p->sst_union.sst_stack[i].bs_extmatch);
    }
}

static void invalidate_current_state (void) {
    clear_current_state ();
    current_state.ga_itemsize = 0;
    current_next_list = NULL;
    keepend_level = -1;
}

static void clear_current_state (void) {
    int i;
    stateitem_T *sip;
    sip = (stateitem_T *) (current_state.ga_data);
    for (i = 0; i < current_state.ga_len; i++)
        unref_extmatch (sip[i].si_extmatch);
    ga_clear (& current_state);
}

void highlight_gui_started (void) {
    int idx;
    if (USE_24BIT)
        set_normal_colors ();
    for (idx = 0; idx < highlight_ga.ga_len; ++idx)
        gui_do_one_color (idx, FALSE, FALSE);
    highlight_changed ();
}

void set_normal_colors (void) {
    if (gui.in_use) {
        if (set_group_colors ((char_u *) "Normal", &gui.norm_pixel, &gui.back_pixel, FALSE, TRUE, FALSE)) {
            gui_mch_new_colors ();
            must_redraw = CLEAR;
        }
    }
    else {
        int idx;
        idx = syn_name2id ((char_u *) "Normal") - 1;
        if (idx >= 0) {
            gui_do_one_color (idx, FALSE, FALSE);
            if (HL_TABLE ()[idx].sg_gui_fg != INVALCOLOR) {
                cterm_normal_fg_gui_color = HL_TABLE ()[idx].sg_gui_fg;
                must_redraw = CLEAR;
            }
            if (HL_TABLE ()[idx].sg_gui_bg != INVALCOLOR) {
                cterm_normal_bg_gui_color = HL_TABLE ()[idx].sg_gui_bg;
                must_redraw = CLEAR;
            }
        }
    }
}

static int set_group_colors (char_u *name, guicolor_T *fgp, guicolor_T *bgp, int do_menu, int use_norm, int do_tooltip) {
    int idx;
    idx = syn_name2id (name) - 1;
    if (idx >= 0) {
        gui_do_one_color (idx, do_menu, do_tooltip);
        if (HL_TABLE ()[idx].sg_gui_fg != INVALCOLOR)
            *fgp = HL_TABLE ()[idx].sg_gui_fg;
        else if (use_norm)
            *fgp = gui.def_norm_pixel;
        if (HL_TABLE ()[idx].sg_gui_bg != INVALCOLOR)
            *bgp = HL_TABLE ()[idx].sg_gui_bg;
        else if (use_norm)
            *bgp = gui.def_back_pixel;
        return TRUE;
    }
    return FALSE;
}

static void gui_do_one_color (int idx, int do_menu, int do_tooltip) {
    int didit = FALSE;
    if (gui.in_use)
        if (HL_TABLE ()[idx].sg_font_name != NULL) {
            hl_do_font (idx, HL_TABLE () [idx].sg_font_name, FALSE, do_menu, do_tooltip, TRUE);
            didit = TRUE;
        }
    if (HL_TABLE ()[idx].sg_gui_fg_name != NULL) {
        HL_TABLE ()[idx].sg_gui_fg = color_name2handle (HL_TABLE ()[idx].sg_gui_fg_name);
        didit = TRUE;
    }
    if (HL_TABLE ()[idx].sg_gui_bg_name != NULL) {
        HL_TABLE ()[idx].sg_gui_bg = color_name2handle (HL_TABLE ()[idx].sg_gui_bg_name);
        didit = TRUE;
    }
    if (HL_TABLE ()[idx].sg_gui_sp_name != NULL) {
        HL_TABLE ()[idx].sg_gui_sp = color_name2handle (HL_TABLE ()[idx].sg_gui_sp_name);
        didit = TRUE;
    }
    if (didit)
        set_hl_attr (idx);
}

static void hl_do_font (int idx, char_u *arg, int do_normal, int do_menu, int do_tooltip, int free_font) {
    {
        if (free_font)
            gui_mch_free_font (HL_TABLE ()[idx].sg_font);
        HL_TABLE ()[idx].sg_font = font_name2handle (arg);
        if (HL_TABLE ()[idx].sg_font != NOFONT) {
            if (do_normal)
                gui_init_font (arg, FALSE);
        }
    }
}

static GuiFont font_name2handle (char_u *name) {
    if (STRCMP (name, "NONE") == 0)
        return NOFONT;
    return gui_mch_get_font (name, TRUE);
}

void hl_set_font_name (char_u *font_name) {
    int id;
    id = syn_name2id ((char_u *) "Normal");
    if (id > 0) {
        vim_free (HL_TABLE () [id - 1].sg_font_name);
        HL_TABLE ()[id - 1].sg_font_name = vim_strsave (font_name);
    }
}

void syn_set_timeout (proftime_T *tm) {
    syn_tm = tm;
}

int syntax_present (win_T *win) {
    return (win->w_s->b_syn_patterns.ga_len != 0 || win->w_s->b_syn_clusters.ga_len != 0 || win->w_s->b_keywtab.ht_used > 0 || win->w_s->b_keywtab_ic.ht_used > 0);
}

void syntax_start (win_T *wp, linenr_T lnum) {
    synstate_T *p;
    synstate_T *last_valid = NULL;
    synstate_T *last_min_valid = NULL;
    synstate_T *sp, *prev = NULL;
    linenr_T parsed_lnum;
    linenr_T first_stored;
    int dist;
    static varnumber_T changedtick = 0;
    current_sub_char = NUL;
    if (syn_block != wp->w_s || syn_buf != wp->w_buffer || changedtick != CHANGEDTICK (syn_buf)) {
        invalidate_current_state ();
        syn_buf = wp->w_buffer;
        syn_block = wp->w_s;
    }
    changedtick = CHANGEDTICK (syn_buf);
    syn_win = wp;
    syn_stack_alloc ();
    if (syn_block->b_sst_array == NULL)
        return;
    syn_block->b_sst_lasttick = display_tick;
    if (VALID_STATE (&current_state) && current_lnum < lnum && current_lnum < syn_buf->b_ml.ml_line_count) {
        (void) syn_finish_line (FALSE);
        if (!current_state_stored) {
            ++current_lnum;
            (void) store_current_state ();
        }
        if (current_lnum != lnum)
            invalidate_current_state ();
    }
    else
        invalidate_current_state ();
    if (INVALID_STATE (&current_state) && syn_block->b_sst_array != NULL) {
        for (p = syn_block->b_sst_first; p != NULL; p = p->sst_next) {
            if (p->sst_lnum > lnum)
                break;
            if (p->sst_lnum <= lnum && p->sst_change_lnum == 0) {
                last_valid = p;
                if (p->sst_lnum >= lnum - syn_block->b_syn_sync_minlines)
                    last_min_valid = p;
            }
        }
        if (last_min_valid != NULL)
            load_current_state (last_min_valid);
    }
    if (INVALID_STATE (&current_state)) {
        syn_sync (wp, lnum, last_valid);
        if (current_lnum == 1)
            first_stored = 1;
        else
            first_stored = current_lnum + syn_block->b_syn_sync_minlines;
    }
    else
        first_stored = current_lnum;
    if (syn_block->b_sst_len <= Rows)
        dist = 999999;
    else
        dist = syn_buf->b_ml.ml_line_count / (syn_block->b_sst_len - Rows) + 1;
    while (current_lnum < lnum) {
        syn_start_line ();
        (void) syn_finish_line (FALSE);
        ++current_lnum;
        if (current_lnum >= first_stored) {
            if (prev == NULL)
                prev = syn_stack_find_entry (current_lnum -1);
            if (prev == NULL)
                sp = syn_block->b_sst_first;
            else
                sp = prev;
            while (sp != NULL && sp->sst_lnum < current_lnum)
                sp = sp->sst_next;
            if (sp != NULL && sp->sst_lnum == current_lnum && syn_stack_equal (sp)) {
                parsed_lnum = current_lnum;
                prev = sp;
                while (sp != NULL && sp->sst_change_lnum <= parsed_lnum) {
                    if (sp->sst_lnum <= lnum)
                        prev = sp;
                    else if (sp->sst_change_lnum == 0)
                        break;
                    sp->sst_change_lnum = 0;
                    sp = sp->sst_next;
                }
                load_current_state (prev);
            }
            else if (prev == NULL || current_lnum == lnum || current_lnum >= prev->sst_lnum + dist)
                prev = store_current_state ();
        }
        line_breakcheck ();
        if (got_int) {
            current_lnum = lnum;
            break;
        }
    }
    syn_start_line ();
}

static void syn_stack_alloc (void) {
    long  len;
    synstate_T *to, *from;
    synstate_T *sstp;
    len = syn_buf->b_ml.ml_line_count / SST_DIST + Rows * 2;
    if (len < SST_MIN_ENTRIES)
        len = SST_MIN_ENTRIES;
    else if (len > SST_MAX_ENTRIES)
        len = SST_MAX_ENTRIES;
    if (syn_block->b_sst_len > len * 2 || syn_block->b_sst_len < len) {
        len = syn_buf->b_ml.ml_line_count;
        len = (len + len / 2) / SST_DIST + Rows * 2;
        if (len < SST_MIN_ENTRIES)
            len = SST_MIN_ENTRIES;
        else if (len > SST_MAX_ENTRIES)
            len = SST_MAX_ENTRIES;
        if (syn_block->b_sst_array != NULL) {
            while (syn_block->b_sst_len - syn_block->b_sst_freecount + 2 > len && syn_stack_cleanup ())
                ;
            if (len < syn_block->b_sst_len - syn_block->b_sst_freecount + 2)
                len = syn_block->b_sst_len - syn_block->b_sst_freecount + 2;
        }
        sstp = (synstate_T *) alloc_clear ((unsigned ) (len * sizeof (synstate_T)));
        if (sstp == NULL)
            return;
        to = sstp - 1;
        if (syn_block->b_sst_array != NULL) {
            for (from = syn_block->b_sst_first; from != NULL; from = from->sst_next) {
                ++to;
                *to = *from;
                to->sst_next = to + 1;
            }
        }
        if (to != sstp - 1) {
            to->sst_next = NULL;
            syn_block->b_sst_first = sstp;
            syn_block->b_sst_freecount = len - (int) (to - sstp) - 1;
        }
        else {
            syn_block->b_sst_first = NULL;
            syn_block->b_sst_freecount = len;
        }
        syn_block->b_sst_firstfree = to + 1;
        while (++to < sstp + len)
            to->sst_next = to + 1;
        (sstp + len - 1)->sst_next = NULL;
        vim_free (syn_block -> b_sst_array);
        syn_block->b_sst_array = sstp;
        syn_block->b_sst_len = len;
    }
}

static int syn_stack_cleanup (void) {
    synstate_T *p, *prev;
    disptick_T tick;
    int above;
    int dist;
    int retval = FALSE;
    if (syn_block->b_sst_array == NULL || syn_block->b_sst_first == NULL)
        return retval;
    if (syn_block->b_sst_len <= Rows)
        dist = 999999;
    else
        dist = syn_buf->b_ml.ml_line_count / (syn_block->b_sst_len - Rows) + 1;
    tick = syn_block->b_sst_lasttick;
    above = FALSE;
    prev = syn_block->b_sst_first;
    for (p = prev->sst_next; p != NULL; prev = p, p = p->sst_next) {
        if (prev->sst_lnum + dist > p->sst_lnum) {
            if (p->sst_tick > syn_block->b_sst_lasttick) {
                if (!above || p->sst_tick < tick)
                    tick = p->sst_tick;
                above = TRUE;
            }
            else if (!above && p->sst_tick < tick)
                tick = p->sst_tick;
        }
    }
    prev = syn_block->b_sst_first;
    for (p = prev->sst_next; p != NULL; prev = p, p = p->sst_next) {
        if (p->sst_tick == tick && prev->sst_lnum + dist > p->sst_lnum) {
            prev->sst_next = p->sst_next;
            syn_stack_free_entry (syn_block, p);
            p = prev;
            retval = TRUE;
        }
    }
    return retval;
}

static void syn_stack_free_entry (synblock_T *block, synstate_T *p) {
    clear_syn_state (p);
    p->sst_next = block->b_sst_firstfree;
    block->b_sst_firstfree = p;
    ++block->b_sst_freecount;
}

static int syn_finish_line (int syncing) {
    stateitem_T *cur_si;
    colnr_T prev_current_col;
    while (!current_finished) {
        (void) syn_current_attr (syncing, FALSE, NULL, FALSE);
        if (syncing && current_state.ga_len) {
            cur_si = &CUR_STATE (current_state.ga_len - 1);
            if (cur_si->si_idx >= 0 && (SYN_ITEMS (syn_block)[cur_si->si_idx].sp_flags & (HL_SYNC_HERE | HL_SYNC_THERE)))
                return TRUE;
            prev_current_col = current_col;
            if (syn_getcurline ()[current_col] != NUL)
                ++current_col;
            check_state_ends ();
            current_col = prev_current_col;
        }
        ++current_col;
    }
    return FALSE;
}

static int syn_current_attr (int syncing, int displaying, int *can_spell, int keep_state) {
    int syn_id;
    lpos_T endpos;
    lpos_T hl_startpos;
    lpos_T hl_endpos;
    lpos_T eos_pos;
    lpos_T eoe_pos;
    int end_idx;
    int idx;
    synpat_T *spp;
    stateitem_T *cur_si, *sip = NULL;
    int startcol;
    int endcol;
    long  flags;
    int cchar;
    short  *next_list;
    int found_match;
    static int try_next_column = FALSE;
    int do_keywords;
    regmmatch_T regmatch;
    lpos_T pos;
    int lc_col;
    reg_extmatch_T *cur_extmatch = NULL;
    char_u buf_chartab [32];
    char_u *line;
    int keep_next_list;
    int zero_width_next_list = FALSE;
    garray_T zero_width_next_ga;
    line = syn_getcurline ();
    if (line[current_col] == NUL && current_col != 0) {
        if (next_match_idx >= 0 && next_match_col >= (int) current_col && next_match_col != MAXCOL)
            (void) push_next_match (NULL);
        current_finished = TRUE;
        current_state_stored = FALSE;
        return 0;
    }
    if (line[current_col] == NUL || line[current_col + 1] == NUL) {
        current_finished = TRUE;
        current_state_stored = FALSE;
    }
    if (try_next_column) {
        next_match_idx = -1;
        try_next_column = FALSE;
    }
    do_keywords = !syncing && (syn_block->b_keywtab.ht_used > 0 || syn_block->b_keywtab_ic.ht_used > 0);
    ga_init2 (& zero_width_next_ga, (int) sizeof (int), 10);
    save_chartab (buf_chartab);
    do {
        found_match = FALSE;
        keep_next_list = FALSE;
        syn_id = 0;
        if (current_state.ga_len)
            cur_si = &CUR_STATE (current_state.ga_len - 1);
        else
            cur_si = NULL;
        if (syn_block->b_syn_containedin || cur_si == NULL || cur_si->si_cont_list != NULL) {
            if (do_keywords) {
                line = syn_getcurline ();
                if (vim_iswordp_buf (line +current_col, syn_buf) && (current_col == 0 || !vim_iswordp_buf (line +current_col - 1, syn_buf))) {
                    syn_id = check_keyword_id (line, (int) current_col, &endcol, &flags, &next_list, cur_si, &cchar);
                    if (syn_id != 0) {
                        if (push_current_state (KEYWORD_IDX) == OK) {
                            cur_si = &CUR_STATE (current_state.ga_len - 1);
                            cur_si->si_m_startcol = current_col;
                            cur_si->si_h_startpos.lnum = current_lnum;
                            cur_si->si_h_startpos.col = 0;
                            cur_si->si_m_endpos.lnum = current_lnum;
                            cur_si->si_m_endpos.col = endcol;
                            cur_si->si_h_endpos.lnum = current_lnum;
                            cur_si->si_h_endpos.col = endcol;
                            cur_si->si_ends = TRUE;
                            cur_si->si_end_idx = 0;
                            cur_si->si_flags = flags;
                            cur_si->si_seqnr = next_seqnr++;
                            cur_si->si_cchar = cchar;
                            if (current_state.ga_len > 1)
                                cur_si->si_flags |= CUR_STATE (current_state.ga_len - 2).si_flags & HL_CONCEAL;
                            cur_si->si_id = syn_id;
                            cur_si->si_trans_id = syn_id;
                            if (flags & HL_TRANSP) {
                                if (current_state.ga_len < 2) {
                                    cur_si->si_attr = 0;
                                    cur_si->si_trans_id = 0;
                                }
                                else {
                                    cur_si->si_attr = CUR_STATE (current_state.ga_len - 2).si_attr;
                                    cur_si->si_trans_id = CUR_STATE (current_state.ga_len - 2).si_trans_id;
                                }
                            }
                            else
                                cur_si->si_attr = syn_id2attr (syn_id);
                            cur_si->si_cont_list = NULL;
                            cur_si->si_next_list = next_list;
                            check_keepend ();
                        }
                        else
                            vim_free (next_list);
                    }
                }
            }
            if (syn_id == 0 && syn_block->b_syn_patterns.ga_len) {
                if (next_match_idx < 0 || next_match_col < (int) current_col) {
                    next_match_idx = 0;
                    next_match_col = MAXCOL;
                    for (idx = syn_block->b_syn_patterns.ga_len; --idx >= 0;) {
                        spp = &(SYN_ITEMS (syn_block)[idx]);
                        if (spp->sp_syncing == syncing && (displaying || !(spp->sp_flags & HL_DISPLAY)) && (spp->sp_type == SPTYPE_MATCH || spp->sp_type == SPTYPE_START) && (current_next_list != NULL ? in_id_list (NULL, current_next_list, &spp->sp_syn, 0) : (cur_si == NULL ? !(spp->sp_flags & HL_CONTAINED) : in_id_list (cur_si, cur_si->si_cont_list, &spp->sp_syn, spp->sp_flags & HL_CONTAINED)))) {
                            int r;
                            if (spp->sp_line_id == current_line_id && spp->sp_startcol >= next_match_col)
                                continue;
                            spp->sp_line_id = current_line_id;
                            lc_col = current_col - spp->sp_offsets[SPO_LC_OFF];
                            if (lc_col < 0)
                                lc_col = 0;
                            regmatch.rmm_ic = spp->sp_ic;
                            regmatch.regprog = spp->sp_prog;
                            r = syn_regexec (&regmatch, current_lnum, (colnr_T) lc_col, IF_SYN_TIME (&spp->sp_time));
                            spp->sp_prog = regmatch.regprog;
                            if (!r) {
                                spp->sp_startcol = MAXCOL;
                                continue;
                            }
                            syn_add_start_off (& pos, & regmatch, spp, SPO_MS_OFF, - 1);
                            if (pos.lnum > current_lnum) {
                                spp->sp_startcol = MAXCOL;
                                continue;
                            }
                            startcol = pos.col;
                            spp->sp_startcol = startcol;
                            if (startcol >= next_match_col)
                                continue;
                            if (did_match_already (idx, &zero_width_next_ga)) {
                                try_next_column = TRUE;
                                continue;
                            }
                            endpos.lnum = regmatch.endpos[0].lnum;
                            endpos.col = regmatch.endpos[0].col;
                            syn_add_start_off (& hl_startpos, & regmatch, spp, SPO_HS_OFF, - 1);
                            syn_add_end_off (& eos_pos, & regmatch, spp, SPO_RS_OFF, 0);
                            unref_extmatch (cur_extmatch);
                            cur_extmatch = re_extmatch_out;
                            re_extmatch_out = NULL;
                            flags = 0;
                            eoe_pos.lnum = 0;
                            eoe_pos.col = 0;
                            end_idx = 0;
                            hl_endpos.lnum = 0;
                            if (spp->sp_type == SPTYPE_START && (spp->sp_flags & HL_ONELINE)) {
                                lpos_T startpos;
                                startpos = endpos;
                                find_endpos (idx, & startpos, & endpos, & hl_endpos, & flags, & eoe_pos, & end_idx, cur_extmatch);
                                if (endpos.lnum == 0)
                                    continue;
                            }
                            else if (spp->sp_type == SPTYPE_MATCH) {
                                syn_add_end_off (& hl_endpos, & regmatch, spp, SPO_HE_OFF, 0);
                                syn_add_end_off (& endpos, & regmatch, spp, SPO_ME_OFF, 0);
                                if (endpos.lnum == current_lnum && (int) endpos.col + syncing < startcol) {
                                    if (regmatch.startpos[0].col == regmatch.endpos[0].col)
                                        try_next_column = TRUE;
                                    continue;
                                }
                            }
                            if (hl_startpos.lnum == current_lnum && (int) hl_startpos.col < startcol)
                                hl_startpos.col = startcol;
                            limit_pos_zero (& hl_endpos, & endpos);
                            next_match_idx = idx;
                            next_match_col = startcol;
                            next_match_m_endpos = endpos;
                            next_match_h_endpos = hl_endpos;
                            next_match_h_startpos = hl_startpos;
                            next_match_flags = flags;
                            next_match_eos_pos = eos_pos;
                            next_match_eoe_pos = eoe_pos;
                            next_match_end_idx = end_idx;
                            unref_extmatch (next_match_extmatch);
                            next_match_extmatch = cur_extmatch;
                            cur_extmatch = NULL;
                        }
                    }
                }
                if (next_match_idx >= 0 && next_match_col == (int) current_col) {
                    synpat_T *lspp;
                    lspp = &(SYN_ITEMS (syn_block)[next_match_idx]);
                    if (next_match_m_endpos.lnum == current_lnum && next_match_m_endpos.col == current_col && lspp->sp_next_list != NULL) {
                        current_next_list = lspp->sp_next_list;
                        current_next_flags = lspp->sp_flags;
                        keep_next_list = TRUE;
                        zero_width_next_list = TRUE;
                        if (ga_grow (&zero_width_next_ga, 1) == OK) {
                            ((int *) (zero_width_next_ga.ga_data))[zero_width_next_ga.ga_len++] = next_match_idx;
                        }
                        next_match_idx = -1;
                    }
                    else
                        cur_si = push_next_match (cur_si);
                    found_match = TRUE;
                }
            }
        }
        if (current_next_list != NULL && !keep_next_list) {
            if (!found_match) {
                line = syn_getcurline ();
                if (((current_next_flags & HL_SKIPWHITE) && VIM_ISWHITE (line[current_col])) || ((current_next_flags & HL_SKIPEMPTY) && *line == NUL))
                    break;
            }
            current_next_list = NULL;
            next_match_idx = -1;
            if (!zero_width_next_list)
                found_match = TRUE;
        }
    }
    while (found_match);
    restore_chartab (buf_chartab);
    current_attr = 0;
    current_id = 0;
    current_trans_id = 0;
    current_flags = 0;
    current_seqnr = 0;
    if (cur_si != NULL) {
        for (idx = current_state.ga_len - 1; idx >= 0; --idx) {
            sip = &CUR_STATE (idx);
            if ((current_lnum > sip->si_h_startpos.lnum || (current_lnum == sip->si_h_startpos.lnum && current_col >= sip->si_h_startpos.col)) && (sip->si_h_endpos.lnum == 0 || current_lnum < sip->si_h_endpos.lnum || (current_lnum == sip->si_h_endpos.lnum && current_col < sip->si_h_endpos.col))) {
                current_attr = sip->si_attr;
                current_id = sip->si_id;
                current_trans_id = sip->si_trans_id;
                current_flags = sip->si_flags;
                current_seqnr = sip->si_seqnr;
                current_sub_char = sip->si_cchar;
                break;
            }
        }
        if (can_spell != NULL) {
            struct sp_syn sps;
            if (syn_block->b_spell_cluster_id == 0) {
                if (syn_block->b_nospell_cluster_id == 0 || current_trans_id == 0)
                    *can_spell = (syn_block->b_syn_spell != SYNSPL_NOTOP);
                else {
                    sps.inc_tag = 0;
                    sps.id = syn_block->b_nospell_cluster_id;
                    sps.cont_in_list = NULL;
                    *can_spell = !in_id_list (sip, sip->si_cont_list, &sps, 0);
                }
            }
            else {
                if (current_trans_id == 0)
                    *can_spell = (syn_block->b_syn_spell == SYNSPL_TOP);
                else {
                    sps.inc_tag = 0;
                    sps.id = syn_block->b_spell_cluster_id;
                    sps.cont_in_list = NULL;
                    *can_spell = in_id_list (sip, sip->si_cont_list, &sps, 0);
                    if (syn_block->b_nospell_cluster_id != 0) {
                        sps.id = syn_block->b_nospell_cluster_id;
                        if (in_id_list (sip, sip->si_cont_list, &sps, 0))
                            *can_spell = FALSE;
                    }
                }
            }
        }
        if (!syncing && !keep_state) {
            check_state_ends ();
            if (current_state.ga_len > 0 && syn_getcurline ()[current_col] != NUL) {
                ++current_col;
                check_state_ends ();
                --current_col;
            }
        }
    }
    else if (can_spell != NULL)
        *can_spell = syn_block->b_syn_spell == SYNSPL_DEFAULT ? (syn_block->b_spell_cluster_id == 0) : (syn_block->b_syn_spell == SYNSPL_TOP);
    if (current_next_list != NULL && syn_getcurline ()[current_col + 1] == NUL && !(current_next_flags & (HL_SKIPNL | HL_SKIPEMPTY)))
        current_next_list = NULL;
    if (zero_width_next_ga.ga_len > 0)
        ga_clear (&zero_width_next_ga);
    unref_extmatch (re_extmatch_out);
    re_extmatch_out = NULL;
    unref_extmatch (cur_extmatch);
    return current_attr;
}

static char_u *syn_getcurline (void) {
    return ml_get_buf (syn_buf, current_lnum, FALSE);
}

static stateitem_T *push_next_match (stateitem_T *cur_si) {
    synpat_T *spp;
    int save_flags;
    spp = &(SYN_ITEMS (syn_block)[next_match_idx]);
    if (push_current_state (next_match_idx) == OK) {
        cur_si = &CUR_STATE (current_state.ga_len - 1);
        cur_si->si_h_startpos = next_match_h_startpos;
        cur_si->si_m_startcol = current_col;
        cur_si->si_m_lnum = current_lnum;
        cur_si->si_flags = spp->sp_flags;
        cur_si->si_seqnr = next_seqnr++;
        cur_si->si_cchar = spp->sp_cchar;
        if (current_state.ga_len > 1)
            cur_si->si_flags |= CUR_STATE (current_state.ga_len - 2).si_flags & HL_CONCEAL;
        cur_si->si_next_list = spp->sp_next_list;
        cur_si->si_extmatch = ref_extmatch (next_match_extmatch);
        if (spp->sp_type == SPTYPE_START && !(spp->sp_flags & HL_ONELINE)) {
            update_si_end (cur_si, (int) (next_match_m_endpos.col), TRUE);
            check_keepend ();
        }
        else {
            cur_si->si_m_endpos = next_match_m_endpos;
            cur_si->si_h_endpos = next_match_h_endpos;
            cur_si->si_ends = TRUE;
            cur_si->si_flags |= next_match_flags;
            cur_si->si_eoe_pos = next_match_eoe_pos;
            cur_si->si_end_idx = next_match_end_idx;
        }
        if (keepend_level < 0 && (cur_si->si_flags & HL_KEEPEND))
            keepend_level = current_state.ga_len - 1;
        check_keepend ();
        update_si_attr (current_state.ga_len - 1);
        save_flags = cur_si->si_flags & (HL_CONCEAL | HL_CONCEALENDS);
        if (spp->sp_type == SPTYPE_START && spp->sp_syn_match_id != 0 && push_current_state (next_match_idx) == OK) {
            cur_si = &CUR_STATE (current_state.ga_len - 1);
            cur_si->si_h_startpos = next_match_h_startpos;
            cur_si->si_m_startcol = current_col;
            cur_si->si_m_lnum = current_lnum;
            cur_si->si_m_endpos = next_match_eos_pos;
            cur_si->si_h_endpos = next_match_eos_pos;
            cur_si->si_ends = TRUE;
            cur_si->si_end_idx = 0;
            cur_si->si_flags = HL_MATCH;
            cur_si->si_seqnr = next_seqnr++;
            cur_si->si_flags |= save_flags;
            if (cur_si->si_flags & HL_CONCEALENDS)
                cur_si->si_flags |= HL_CONCEAL;
            cur_si->si_next_list = NULL;
            check_keepend ();
            update_si_attr (current_state.ga_len - 1);
        }
    }
    next_match_idx = -1;
    return cur_si;
}

static int push_current_state (int idx) {
    if (ga_grow (&current_state, 1) == FAIL)
        return FAIL;
    vim_memset (& CUR_STATE (current_state.ga_len), 0, sizeof (stateitem_T));
    CUR_STATE (current_state.ga_len).si_idx = idx;
    ++current_state.ga_len;
    return OK;
}

static void update_si_end (stateitem_T *sip, int startcol, int force) {
    lpos_T startpos;
    lpos_T endpos;
    lpos_T hl_endpos;
    lpos_T end_endpos;
    int end_idx;
    if (sip->si_idx < 0)
        return;
    if (!force && sip->si_m_endpos.lnum >= current_lnum)
        return;
    end_idx = 0;
    startpos.lnum = current_lnum;
    startpos.col = startcol;
    find_endpos (sip -> si_idx, & startpos, & endpos, & hl_endpos, & (sip -> si_flags), & end_endpos, & end_idx, sip -> si_extmatch);
    if (endpos.lnum == 0) {
        if (SYN_ITEMS (syn_block)[sip->si_idx].sp_flags & HL_ONELINE) {
            sip->si_ends = TRUE;
            sip->si_m_endpos.lnum = current_lnum;
            sip->si_m_endpos.col = (colnr_T) STRLEN (syn_getcurline ());
        }
        else {
            sip->si_ends = FALSE;
            sip->si_m_endpos.lnum = 0;
        }
        sip->si_h_endpos = sip->si_m_endpos;
    }
    else {
        sip->si_m_endpos = endpos;
        sip->si_h_endpos = hl_endpos;
        sip->si_eoe_pos = end_endpos;
        sip->si_ends = TRUE;
        sip->si_end_idx = end_idx;
    }
}

static void find_endpos (int idx, lpos_T *startpos, lpos_T *m_endpos, lpos_T *hl_endpos, long  *flagsp, lpos_T *end_endpos, int *end_idx, reg_extmatch_T *start_ext) {
    colnr_T matchcol;
    synpat_T *spp, *spp_skip;
    int start_idx;
    int best_idx;
    regmmatch_T regmatch;
    regmmatch_T best_regmatch;
    lpos_T pos;
    char_u *line;
    int had_match = FALSE;
    char_u buf_chartab [32];
    if (idx < 0)
        return;
    spp = &(SYN_ITEMS (syn_block)[idx]);
    if (spp->sp_type != SPTYPE_START) {
        *hl_endpos = *startpos;
        return;
    }
    for (;;) {
        spp = &(SYN_ITEMS (syn_block)[idx]);
        if (spp->sp_type != SPTYPE_START)
            break;
        ++idx;
    }
    if (spp->sp_type == SPTYPE_SKIP) {
        spp_skip = spp;
        ++idx;
    }
    else
        spp_skip = NULL;
    unref_extmatch (re_extmatch_in);
    re_extmatch_in = ref_extmatch (start_ext);
    matchcol = startpos->col;
    start_idx = idx;
    best_regmatch.startpos[0].col = 0;
    save_chartab (buf_chartab);
    for (;;) {
        best_idx = -1;
        for (idx = start_idx; idx < syn_block->b_syn_patterns.ga_len; ++idx) {
            int lc_col = matchcol;
            int r;
            spp = &(SYN_ITEMS (syn_block)[idx]);
            if (spp->sp_type != SPTYPE_END)
                break;
            lc_col -= spp->sp_offsets[SPO_LC_OFF];
            if (lc_col < 0)
                lc_col = 0;
            regmatch.rmm_ic = spp->sp_ic;
            regmatch.regprog = spp->sp_prog;
            r = syn_regexec (&regmatch, startpos->lnum, lc_col, IF_SYN_TIME (&spp->sp_time));
            spp->sp_prog = regmatch.regprog;
            if (r) {
                if (best_idx == -1 || regmatch.startpos[0].col < best_regmatch.startpos[0].col) {
                    best_idx = idx;
                    best_regmatch.startpos[0] = regmatch.startpos[0];
                    best_regmatch.endpos[0] = regmatch.endpos[0];
                }
            }
        }
        if (best_idx == -1)
            break;
        if (spp_skip != NULL) {
            int lc_col = matchcol - spp_skip->sp_offsets[SPO_LC_OFF];
            int r;
            if (lc_col < 0)
                lc_col = 0;
            regmatch.rmm_ic = spp_skip->sp_ic;
            regmatch.regprog = spp_skip->sp_prog;
            r = syn_regexec (&regmatch, startpos->lnum, lc_col, IF_SYN_TIME (&spp_skip->sp_time));
            spp_skip->sp_prog = regmatch.regprog;
            if (r && regmatch.startpos[0].col <= best_regmatch.startpos[0].col) {
                int line_len;
                syn_add_end_off (& pos, & regmatch, spp_skip, SPO_ME_OFF, 1);
                if (pos.lnum > startpos->lnum)
                    break;
                line = ml_get_buf (syn_buf, startpos->lnum, FALSE);
                line_len = (int) STRLEN (line);
                if (pos.col <= matchcol)
                    ++matchcol;
                else if (pos.col <= regmatch.endpos[0].col)
                    matchcol = pos.col;
                else
                    for (matchcol = regmatch.endpos[0].col; matchcol < line_len && matchcol < pos.col; ++matchcol)
                        ;
                if (matchcol >= line_len)
                    break;
                continue;
            }
        }
        spp = &(SYN_ITEMS (syn_block)[best_idx]);
        syn_add_end_off (m_endpos, & best_regmatch, spp, SPO_ME_OFF, 1);
        if (m_endpos->lnum == startpos->lnum && m_endpos->col < startpos->col)
            m_endpos->col = startpos->col;
        syn_add_end_off (end_endpos, & best_regmatch, spp, SPO_HE_OFF, 1);
        if (end_endpos->lnum == startpos->lnum && end_endpos->col < startpos->col)
            end_endpos->col = startpos->col;
        limit_pos (end_endpos, m_endpos);
        if (spp->sp_syn_match_id != spp->sp_syn.id && spp->sp_syn_match_id != 0) {
            *end_idx = best_idx;
            if (spp->sp_off_flags & (1 << (SPO_RE_OFF + SPO_COUNT))) {
                hl_endpos->lnum = best_regmatch.endpos[0].lnum;
                hl_endpos->col = best_regmatch.endpos[0].col;
            }
            else {
                hl_endpos->lnum = best_regmatch.startpos[0].lnum;
                hl_endpos->col = best_regmatch.startpos[0].col;
            }
            hl_endpos->col += spp->sp_offsets[SPO_RE_OFF];
            if (hl_endpos->lnum == startpos->lnum && hl_endpos->col < startpos->col)
                hl_endpos->col = startpos->col;
            limit_pos (hl_endpos, m_endpos);
            *m_endpos = *hl_endpos;
        }
        else {
            *end_idx = 0;
            *hl_endpos = *end_endpos;
        }
        *flagsp = spp->sp_flags;
        had_match = TRUE;
        break;
    }
    if (!had_match)
        m_endpos->lnum = 0;
    restore_chartab (buf_chartab);
    unref_extmatch (re_extmatch_in);
    re_extmatch_in = NULL;
}

static void save_chartab (char_u *chartab) {
    if (syn_block->b_syn_isk != empty_option) {
        mch_memmove (chartab, syn_buf -> b_chartab, (size_t) 32);
        mch_memmove (syn_buf -> b_chartab, syn_win -> w_s -> b_syn_chartab, (size_t) 32);
    }
}

static int syn_regexec (regmmatch_T *rmp, linenr_T lnum, colnr_T col, syn_time_T *st) {
    int r;
    int timed_out = FALSE;
    proftime_T pt;
    if (syn_time_on)
        profile_start (&pt);
    rmp->rmm_maxcol = syn_buf->b_p_smc;
    r = vim_regexec_multi (rmp, syn_win, syn_buf, lnum, col, syn_tm, &timed_out);
    if (syn_time_on) {
        profile_end (& pt);
        profile_add (& st -> total, & pt);
        if (profile_cmp (&pt, &st->slowest) < 0)
            st->slowest = pt;
        ++st->count;
        if (r > 0)
            ++st->match;
    }
    if (timed_out)
        syn_win->w_s->b_syn_slow = TRUE;
    if (r > 0) {
        rmp->startpos[0].lnum += lnum;
        rmp->endpos[0].lnum += lnum;
        return TRUE;
    }
    return FALSE;
}

static void syn_add_end_off (lpos_T *result, regmmatch_T *regmatch, synpat_T *spp, int idx, int extra) {
    int col;
    int off;
    char_u *base;
    char_u *p;
    if (spp->sp_off_flags & (1 << idx)) {
        result->lnum = regmatch->startpos[0].lnum;
        col = regmatch->startpos[0].col;
        off = spp->sp_offsets[idx] + extra;
    }
    else {
        result->lnum = regmatch->endpos[0].lnum;
        col = regmatch->endpos[0].col;
        off = spp->sp_offsets[idx];
    }
    if (result->lnum > syn_buf->b_ml.ml_line_count)
        col = 0;
    else if (off != 0) {
        base = ml_get_buf (syn_buf, result->lnum, FALSE);
        p = base + col;
        if (off > 0) {
            while (off-- > 0 && *p != NUL)
                MB_PTR_ADV (p);
        }
        else if (off < 0) {
            while (off++ < 0 && base < p)
                MB_PTR_BACK (base, p);
        }
        col = (int) (p - base);
    }
    result->col = col;
}

static void limit_pos (lpos_T *pos, lpos_T *limit) {
    if (pos->lnum > limit->lnum)
        *pos = *limit;
    else if (pos->lnum == limit->lnum && pos->col > limit->col)
        pos->col = limit->col;
}

static void restore_chartab (char_u *chartab) {
    if (syn_win->w_s->b_syn_isk != empty_option)
        mch_memmove (syn_buf->b_chartab, chartab, (size_t) 32);
}

static void check_keepend (void) {
    int i;
    lpos_T maxpos;
    lpos_T maxpos_h;
    stateitem_T *sip;
    if (keepend_level < 0)
        return;
    for (i = current_state.ga_len - 1; i > keepend_level; --i)
        if (CUR_STATE (i).si_flags & HL_EXTEND)
            break;
    maxpos.lnum = 0;
    maxpos.col = 0;
    maxpos_h.lnum = 0;
    maxpos_h.col = 0;
    for (; i < current_state.ga_len; ++i) {
        sip = &CUR_STATE (i);
        if (maxpos.lnum != 0) {
            limit_pos_zero (& sip -> si_m_endpos, & maxpos);
            limit_pos_zero (& sip -> si_h_endpos, & maxpos_h);
            limit_pos_zero (& sip -> si_eoe_pos, & maxpos);
            sip->si_ends = TRUE;
        }
        if (sip->si_ends && (sip->si_flags & HL_KEEPEND)) {
            if (maxpos.lnum == 0 || maxpos.lnum > sip->si_m_endpos.lnum || (maxpos.lnum == sip->si_m_endpos.lnum && maxpos.col > sip->si_m_endpos.col))
                maxpos = sip->si_m_endpos;
            if (maxpos_h.lnum == 0 || maxpos_h.lnum > sip->si_h_endpos.lnum || (maxpos_h.lnum == sip->si_h_endpos.lnum && maxpos_h.col > sip->si_h_endpos.col))
                maxpos_h = sip->si_h_endpos;
        }
    }
}

static void limit_pos_zero (lpos_T *pos, lpos_T *limit) {
    if (pos->lnum == 0)
        *pos = *limit;
    else
        limit_pos (pos, limit);
}

static void update_si_attr (int idx) {
    stateitem_T *sip = &CUR_STATE (idx);
    synpat_T *spp;
    if (sip->si_idx < 0)
        return;
    spp = &(SYN_ITEMS (syn_block)[sip->si_idx]);
    if (sip->si_flags & HL_MATCH)
        sip->si_id = spp->sp_syn_match_id;
    else
        sip->si_id = spp->sp_syn.id;
    sip->si_attr = syn_id2attr (sip->si_id);
    sip->si_trans_id = sip->si_id;
    if (sip->si_flags & HL_MATCH)
        sip->si_cont_list = NULL;
    else
        sip->si_cont_list = spp->sp_cont_list;
    if ((spp->sp_flags & HL_TRANSP) && !(sip->si_flags & HL_MATCH)) {
        if (idx == 0) {
            sip->si_attr = 0;
            sip->si_trans_id = 0;
            if (sip->si_cont_list == NULL)
                sip->si_cont_list = ID_LIST_ALL;
        }
        else {
            sip->si_attr = CUR_STATE (idx -1).si_attr;
            sip->si_trans_id = CUR_STATE (idx -1).si_trans_id;
            sip->si_h_startpos = CUR_STATE (idx -1).si_h_startpos;
            sip->si_h_endpos = CUR_STATE (idx -1).si_h_endpos;
            if (sip->si_cont_list == NULL) {
                sip->si_flags |= HL_TRANS_CONT;
                sip->si_cont_list = CUR_STATE (idx -1).si_cont_list;
            }
        }
    }
}

static int check_keyword_id (char_u *line, int startcol, int *endcolp, long  *flagsp, short  **next_listp, stateitem_T *cur_si, int *ccharp) {
    keyentry_T *kp;
    char_u *kwp;
    int round;
    int kwlen;
    char_u keyword [MAXKEYWLEN + 1];
    hashtab_T *ht;
    hashitem_T *hi;
    kwp = line + startcol;
    kwlen = 0;
    do {
        ++kwlen;
    }
    while (vim_iswordp_buf (kwp +kwlen, syn_buf));
    if (kwlen > MAXKEYWLEN)
        return 0;
    vim_strncpy (keyword, kwp, kwlen);
    for (round = 1; round <= 2; ++round) {
        ht = round == 1 ? &syn_block->b_keywtab : &syn_block->b_keywtab_ic;
        if (ht->ht_used == 0)
            continue;
        if (round == 2)
            (void) str_foldcase (kwp, kwlen, keyword, MAXKEYWLEN +1);
        hi = hash_find (ht, keyword);
        if (!HASHITEM_EMPTY (hi))
            for (kp = HI2KE (hi); kp != NULL; kp = kp->ke_next) {
                if (current_next_list != 0 ? in_id_list (NULL, current_next_list, &kp->k_syn, 0) : (cur_si == NULL ? !(kp->flags & HL_CONTAINED) : in_id_list (cur_si, cur_si->si_cont_list, &kp->k_syn, kp->flags & HL_CONTAINED))) {
                    *endcolp = startcol + kwlen;
                    *flagsp = kp->flags;
                    *next_listp = kp->next_list;
                    *ccharp = kp->k_char;
                    return kp->k_syn.id;
                }
            }
    }
    return 0;
}

static int in_id_list (stateitem_T *cur_si, short  *list, struct sp_syn *ssp, int contained) {
    int retval;
    short  *scl_list;
    short  item;
    short  id = ssp->id;
    static int depth = 0;
    int r;
    if (cur_si != NULL && ssp->cont_in_list != NULL && !(cur_si->si_flags & HL_MATCH)) {
        while ((cur_si->si_flags & HL_TRANS_CONT) && cur_si > (stateitem_T *) (current_state.ga_data))
            --cur_si;
        if (cur_si->si_idx >= 0 && in_id_list (NULL, ssp->cont_in_list, &(SYN_ITEMS (syn_block)[cur_si->si_idx].sp_syn), SYN_ITEMS (syn_block)[cur_si->si_idx].sp_flags & HL_CONTAINED))
            return TRUE;
    }
    if (list == NULL)
        return FALSE;
    if (list == ID_LIST_ALL)
        return !contained;
    item = *list;
    if (item >= SYNID_ALLBUT && item < SYNID_CLUSTER) {
        if (item < SYNID_TOP) {
            if (item - SYNID_ALLBUT != ssp->inc_tag)
                return FALSE;
        }
        else if (item < SYNID_CONTAINED) {
            if (item - SYNID_TOP != ssp->inc_tag || contained)
                return FALSE;
        }
        else {
            if (item - SYNID_CONTAINED != ssp->inc_tag || !contained)
                return FALSE;
        }
        item = *++list;
        retval = FALSE;
    }
    else
        retval = TRUE;
    while (item != 0) {
        if (item == id)
            return retval;
        if (item >= SYNID_CLUSTER) {
            scl_list = SYN_CLSTR (syn_block)[item - SYNID_CLUSTER].scl_list;
            if (scl_list != NULL && depth < 30) {
                ++depth;
                r = in_id_list (NULL, scl_list, ssp, contained);
                --depth;
                if (r)
                    return retval;
            }
        }
        item = *++list;
    }
    return !retval;
}

static void syn_add_start_off (lpos_T *result, regmmatch_T *regmatch, synpat_T *spp, int idx, int extra) {
    int col;
    int off;
    char_u *base;
    char_u *p;
    if (spp->sp_off_flags & (1 << (idx + SPO_COUNT))) {
        result->lnum = regmatch->endpos[0].lnum;
        col = regmatch->endpos[0].col;
        off = spp->sp_offsets[idx] + extra;
    }
    else {
        result->lnum = regmatch->startpos[0].lnum;
        col = regmatch->startpos[0].col;
        off = spp->sp_offsets[idx];
    }
    if (result->lnum > syn_buf->b_ml.ml_line_count) {
        result->lnum = syn_buf->b_ml.ml_line_count;
        col = (int) STRLEN (ml_get_buf (syn_buf, result->lnum, FALSE));
    }
    if (off != 0) {
        base = ml_get_buf (syn_buf, result->lnum, FALSE);
        p = base + col;
        if (off > 0) {
            while (off-- && *p != NUL)
                MB_PTR_ADV (p);
        }
        else if (off < 0) {
            while (off++ && base < p)
                MB_PTR_BACK (base, p);
        }
        col = (int) (p - base);
    }
    result->col = col;
}

static int did_match_already (int idx, garray_T *gap) {
    int i;
    for (i = current_state.ga_len; --i >= 0;)
        if (CUR_STATE (i).si_m_startcol == (int) current_col && CUR_STATE (i).si_m_lnum == (int) current_lnum && CUR_STATE (i).si_idx == idx)
            return TRUE;
    for (i = gap->ga_len; --i >= 0;)
        if (((int *) (gap->ga_data))[i] == idx)
            return TRUE;
    return FALSE;
}

static void check_state_ends (void) {
    stateitem_T *cur_si;
    int had_extend;
    cur_si = &CUR_STATE (current_state.ga_len - 1);
    for (;;) {
        if (cur_si->si_ends && (cur_si->si_m_endpos.lnum < current_lnum || (cur_si->si_m_endpos.lnum == current_lnum && cur_si->si_m_endpos.col <= current_col))) {
            if (cur_si->si_end_idx && (cur_si->si_eoe_pos.lnum > current_lnum || (cur_si->si_eoe_pos.lnum == current_lnum && cur_si->si_eoe_pos.col > current_col))) {
                cur_si->si_idx = cur_si->si_end_idx;
                cur_si->si_end_idx = 0;
                cur_si->si_m_endpos = cur_si->si_eoe_pos;
                cur_si->si_h_endpos = cur_si->si_eoe_pos;
                cur_si->si_flags |= HL_MATCH;
                cur_si->si_seqnr = next_seqnr++;
                if (cur_si->si_flags & HL_CONCEALENDS)
                    cur_si->si_flags |= HL_CONCEAL;
                update_si_attr (current_state.ga_len - 1);
                current_next_list = NULL;
                next_match_idx = 0;
                next_match_col = MAXCOL;
                break;
            }
            else {
                current_next_list = cur_si->si_next_list;
                current_next_flags = cur_si->si_flags;
                if (!(current_next_flags & (HL_SKIPNL | HL_SKIPEMPTY)) && syn_getcurline ()[current_col] == NUL)
                    current_next_list = NULL;
                had_extend = (cur_si->si_flags & HL_EXTEND);
                pop_current_state ();
                if (current_state.ga_len == 0)
                    break;
                if (had_extend && keepend_level >= 0) {
                    syn_update_ends (FALSE);
                    if (current_state.ga_len == 0)
                        break;
                }
                cur_si = &CUR_STATE (current_state.ga_len - 1);
                if (cur_si->si_idx >= 0 && SYN_ITEMS (syn_block)[cur_si->si_idx].sp_type == SPTYPE_START && !(cur_si->si_flags & (HL_MATCH | HL_KEEPEND))) {
                    update_si_end (cur_si, (int) current_col, TRUE);
                    check_keepend ();
                    if ((current_next_flags & HL_HAS_EOL) && keepend_level < 0 && syn_getcurline ()[current_col] == NUL)
                        break;
                }
            }
        }
        else
            break;
    }
}

static void pop_current_state (void) {
    if (current_state.ga_len) {
        unref_extmatch (CUR_STATE (current_state.ga_len - 1).si_extmatch);
        --current_state.ga_len;
    }
    next_match_idx = -1;
    if (keepend_level >= current_state.ga_len)
        keepend_level = -1;
}

static void syn_update_ends (int startofline) {
    stateitem_T *cur_si;
    int i;
    int seen_keepend;
    if (startofline) {
        for (i = 0; i < current_state.ga_len; ++i) {
            cur_si = &CUR_STATE (i);
            if (cur_si->si_idx >= 0 && (SYN_ITEMS (syn_block)[cur_si->si_idx]).sp_type == SPTYPE_MATCH && cur_si->si_m_endpos.lnum < current_lnum) {
                cur_si->si_flags |= HL_MATCHCONT;
                cur_si->si_m_endpos.lnum = 0;
                cur_si->si_m_endpos.col = 0;
                cur_si->si_h_endpos = cur_si->si_m_endpos;
                cur_si->si_ends = TRUE;
            }
        }
    }
    i = current_state.ga_len - 1;
    if (keepend_level >= 0)
        for (; i > keepend_level; --i)
            if (CUR_STATE (i).si_flags & HL_EXTEND)
                break;
    seen_keepend = FALSE;
    for (; i < current_state.ga_len; ++i) {
        cur_si = &CUR_STATE (i);
        if ((cur_si->si_flags & HL_KEEPEND) || (seen_keepend && !startofline) || (i == current_state.ga_len - 1 && startofline)) {
            cur_si->si_h_startpos.col = 0;
            cur_si->si_h_startpos.lnum = current_lnum;
            if (!(cur_si->si_flags & HL_MATCHCONT))
                update_si_end (cur_si, (int) current_col, !startofline);
            if (!startofline && (cur_si->si_flags & HL_KEEPEND))
                seen_keepend = TRUE;
        }
    }
    check_keepend ();
}

static synstate_T *store_current_state (void) {
    int i;
    synstate_T *p;
    bufstate_T *bp;
    stateitem_T *cur_si;
    synstate_T *sp = syn_stack_find_entry (current_lnum);
    for (i = current_state.ga_len - 1; i >= 0; --i) {
        cur_si = &CUR_STATE (i);
        if (cur_si->si_h_startpos.lnum >= current_lnum || cur_si->si_m_endpos.lnum >= current_lnum || cur_si->si_h_endpos.lnum >= current_lnum || (cur_si->si_end_idx && cur_si->si_eoe_pos.lnum >= current_lnum))
            break;
    }
    if (i >= 0) {
        if (sp != NULL) {
            if (syn_block->b_sst_first == sp)
                syn_block->b_sst_first = sp->sst_next;
            else {
                for (p = syn_block->b_sst_first; p != NULL; p = p->sst_next)
                    if (p->sst_next == sp)
                        break;
                if (p != NULL)
                    p->sst_next = sp->sst_next;
            }
            syn_stack_free_entry (syn_block, sp);
            sp = NULL;
        }
    }
    else if (sp == NULL || sp->sst_lnum != current_lnum) {
        if (syn_block->b_sst_freecount == 0) {
            (void) syn_stack_cleanup ();
            sp = syn_stack_find_entry (current_lnum);
        }
        if (syn_block->b_sst_freecount == 0)
            sp = NULL;
        else {
            p = syn_block->b_sst_firstfree;
            syn_block->b_sst_firstfree = p->sst_next;
            --syn_block->b_sst_freecount;
            if (sp == NULL) {
                p->sst_next = syn_block->b_sst_first;
                syn_block->b_sst_first = p;
            }
            else {
                p->sst_next = sp->sst_next;
                sp->sst_next = p;
            }
            sp = p;
            sp->sst_stacksize = 0;
            sp->sst_lnum = current_lnum;
        }
    }
    if (sp != NULL) {
        clear_syn_state (sp);
        sp->sst_stacksize = current_state.ga_len;
        if (current_state.ga_len > SST_FIX_STATES) {
            ga_init2 (& sp -> sst_union.sst_ga, (int) sizeof (bufstate_T), 1);
            if (ga_grow (&sp->sst_union.sst_ga, current_state.ga_len) == FAIL)
                sp->sst_stacksize = 0;
            else
                sp->sst_union.sst_ga.ga_len = current_state.ga_len;
            bp = SYN_STATE_P (&(sp->sst_union.sst_ga));
        }
        else
            bp = sp->sst_union.sst_stack;
        for (i = 0; i < sp->sst_stacksize; ++i) {
            bp[i].bs_idx = CUR_STATE (i).si_idx;
            bp[i].bs_flags = CUR_STATE (i).si_flags;
            bp[i].bs_seqnr = CUR_STATE (i).si_seqnr;
            bp[i].bs_cchar = CUR_STATE (i).si_cchar;
            bp[i].bs_extmatch = ref_extmatch (CUR_STATE (i).si_extmatch);
        }
        sp->sst_next_flags = current_next_flags;
        sp->sst_next_list = current_next_list;
        sp->sst_tick = display_tick;
        sp->sst_change_lnum = 0;
    }
    current_state_stored = TRUE;
    return sp;
}

static synstate_T *syn_stack_find_entry (linenr_T lnum) {
    synstate_T *p, *prev;
    prev = NULL;
    for (p = syn_block->b_sst_first; p != NULL; prev = p, p = p->sst_next) {
        if (p->sst_lnum == lnum)
            return p;
        if (p->sst_lnum > lnum)
            break;
    }
    return prev;
}

static void load_current_state (synstate_T *from) {
    int i;
    bufstate_T *bp;
    clear_current_state ();
    validate_current_state ();
    keepend_level = -1;
    if (from->sst_stacksize && ga_grow (&current_state, from->sst_stacksize) != FAIL) {
        if (from->sst_stacksize > SST_FIX_STATES)
            bp = SYN_STATE_P (&(from->sst_union.sst_ga));
        else
            bp = from->sst_union.sst_stack;
        for (i = 0; i < from->sst_stacksize; ++i) {
            CUR_STATE (i).si_idx = bp[i].bs_idx;
            CUR_STATE (i).si_flags = bp[i].bs_flags;
            CUR_STATE (i).si_seqnr = bp[i].bs_seqnr;
            CUR_STATE (i).si_cchar = bp[i].bs_cchar;
            CUR_STATE (i).si_extmatch = ref_extmatch (bp[i].bs_extmatch);
            if (keepend_level < 0 && (CUR_STATE (i).si_flags & HL_KEEPEND))
                keepend_level = i;
            CUR_STATE (i).si_ends = FALSE;
            CUR_STATE (i).si_m_lnum = 0;
            if (CUR_STATE (i).si_idx >= 0)
                CUR_STATE (i).si_next_list = (SYN_ITEMS (syn_block)[CUR_STATE (i).si_idx]).sp_next_list;
            else
                CUR_STATE (i).si_next_list = NULL;
            update_si_attr (i);
        }
        current_state.ga_len = from->sst_stacksize;
    }
    current_next_list = from->sst_next_list;
    current_next_flags = from->sst_next_flags;
    current_lnum = from->sst_lnum;
}

static void validate_current_state (void) {
    current_state.ga_itemsize = sizeof (stateitem_T);
    current_state.ga_growsize = 3;
}

static void syn_sync (win_T *wp, linenr_T start_lnum, synstate_T *last_valid) {
    buf_T *curbuf_save;
    win_T *curwin_save;
    pos_T cursor_save;
    int idx;
    linenr_T lnum;
    linenr_T end_lnum;
    linenr_T break_lnum;
    int had_sync_point;
    stateitem_T *cur_si;
    synpat_T *spp;
    char_u *line;
    int found_flags = 0;
    int found_match_idx = 0;
    linenr_T found_current_lnum = 0;
    int found_current_col = 0;
    lpos_T found_m_endpos;
    colnr_T prev_current_col;
    invalidate_current_state ();
    if (syn_block->b_syn_sync_minlines > start_lnum)
        start_lnum = 1;
    else {
        if (syn_block->b_syn_sync_minlines == 1)
            lnum = 1;
        else if (syn_block->b_syn_sync_minlines < 10)
            lnum = syn_block->b_syn_sync_minlines * 2;
        else
            lnum = syn_block->b_syn_sync_minlines * 3 / 2;
        if (syn_block->b_syn_sync_maxlines != 0 && lnum > syn_block->b_syn_sync_maxlines)
            lnum = syn_block->b_syn_sync_maxlines;
        if (lnum >= start_lnum)
            start_lnum = 1;
        else
            start_lnum -= lnum;
    }
    current_lnum = start_lnum;
    if (syn_block->b_syn_sync_flags & SF_CCOMMENT) {
        curwin_save = curwin;
        curwin = wp;
        curbuf_save = curbuf;
        curbuf = syn_buf;
        for (; start_lnum > 1; --start_lnum) {
            line = ml_get (start_lnum -1);
            if (*line == NUL || *(line + STRLEN (line) - 1) != '\\')
                break;
        }
        current_lnum = start_lnum;
        cursor_save = wp->w_cursor;
        wp->w_cursor.lnum = start_lnum;
        wp->w_cursor.col = 0;
        if (find_start_comment ((int) syn_block->b_syn_sync_maxlines) != NULL) {
            for (idx = syn_block->b_syn_patterns.ga_len; --idx >= 0;)
                if (SYN_ITEMS (syn_block)[idx].sp_syn.id == syn_block->b_syn_sync_id && SYN_ITEMS (syn_block)[idx].sp_type == SPTYPE_START) {
                    validate_current_state ();
                    if (push_current_state (idx) == OK)
                        update_si_attr (current_state.ga_len - 1);
                    break;
                }
        }
        wp->w_cursor = cursor_save;
        curwin = curwin_save;
        curbuf = curbuf_save;
    }
    else if (syn_block->b_syn_sync_flags & SF_MATCH) {
        if (syn_block->b_syn_sync_maxlines != 0 && start_lnum > syn_block->b_syn_sync_maxlines)
            break_lnum = start_lnum - syn_block->b_syn_sync_maxlines;
        else
            break_lnum = 0;
        found_m_endpos.lnum = 0;
        found_m_endpos.col = 0;
        end_lnum = start_lnum;
        lnum = start_lnum;
        while (--lnum > break_lnum) {
            line_breakcheck ();
            if (got_int) {
                invalidate_current_state ();
                current_lnum = start_lnum;
                break;
            }
            if (last_valid != NULL && lnum == last_valid->sst_lnum) {
                load_current_state (last_valid);
                break;
            }
            if (lnum > 1 && syn_match_linecont (lnum -1))
                continue;
            validate_current_state ();
            for (current_lnum = lnum; current_lnum < end_lnum; ++current_lnum) {
                syn_start_line ();
                for (;;) {
                    had_sync_point = syn_finish_line (TRUE);
                    if (had_sync_point && current_state.ga_len) {
                        cur_si = &CUR_STATE (current_state.ga_len - 1);
                        if (cur_si->si_m_endpos.lnum > start_lnum) {
                            current_lnum = end_lnum;
                            break;
                        }
                        if (cur_si->si_idx < 0) {
                            found_flags = 0;
                            found_match_idx = KEYWORD_IDX;
                        }
                        else {
                            spp = &(SYN_ITEMS (syn_block)[cur_si->si_idx]);
                            found_flags = spp->sp_flags;
                            found_match_idx = spp->sp_sync_idx;
                        }
                        found_current_lnum = current_lnum;
                        found_current_col = current_col;
                        found_m_endpos = cur_si->si_m_endpos;
                        if (found_m_endpos.lnum > current_lnum) {
                            current_lnum = found_m_endpos.lnum;
                            current_col = found_m_endpos.col;
                            if (current_lnum >= end_lnum)
                                break;
                        }
                        else if (found_m_endpos.col > current_col)
                            current_col = found_m_endpos.col;
                        else
                            ++current_col;
                        prev_current_col = current_col;
                        if (syn_getcurline ()[current_col] != NUL)
                            ++current_col;
                        check_state_ends ();
                        current_col = prev_current_col;
                    }
                    else
                        break;
                }
            }
            if (found_flags) {
                clear_current_state ();
                if (found_match_idx >= 0 && push_current_state (found_match_idx) == OK)
                    update_si_attr (current_state.ga_len - 1);
                if (found_flags & HL_SYNC_HERE) {
                    if (current_state.ga_len) {
                        cur_si = &CUR_STATE (current_state.ga_len - 1);
                        cur_si->si_h_startpos.lnum = found_current_lnum;
                        cur_si->si_h_startpos.col = found_current_col;
                        update_si_end (cur_si, (int) current_col, TRUE);
                        check_keepend ();
                    }
                    current_col = found_m_endpos.col;
                    current_lnum = found_m_endpos.lnum;
                    (void) syn_finish_line (FALSE);
                    ++current_lnum;
                }
                else
                    current_lnum = start_lnum;
                break;
            }
            end_lnum = lnum;
            invalidate_current_state ();
        }
        if (lnum <= break_lnum) {
            invalidate_current_state ();
            current_lnum = break_lnum + 1;
        }
    }
    validate_current_state ();
}

static int syn_match_linecont (linenr_T lnum) {
    regmmatch_T regmatch;
    int r;
    char_u buf_chartab [32];
    if (syn_block->b_syn_linecont_prog != NULL) {
        save_chartab (buf_chartab);
        regmatch.rmm_ic = syn_block->b_syn_linecont_ic;
        regmatch.regprog = syn_block->b_syn_linecont_prog;
        r = syn_regexec (&regmatch, lnum, (colnr_T) 0, IF_SYN_TIME (&syn_block->b_syn_linecont_time));
        syn_block->b_syn_linecont_prog = regmatch.regprog;
        restore_chartab (buf_chartab);
        return r;
    }
    return FALSE;
}

static void syn_start_line (void) {
    current_finished = FALSE;
    current_col = 0;
    if (current_state.ga_len > 0) {
        syn_update_ends (TRUE);
        check_state_ends ();
    }
    next_match_idx = -1;
    ++current_line_id;
    next_seqnr = 1;
}

static int syn_stack_equal (synstate_T *sp) {
    int i, j;
    bufstate_T *bp;
    reg_extmatch_T *six, *bsx;
    if (sp->sst_stacksize == current_state.ga_len && sp->sst_next_list == current_next_list) {
        if (sp->sst_stacksize > SST_FIX_STATES)
            bp = SYN_STATE_P (&(sp->sst_union.sst_ga));
        else
            bp = sp->sst_union.sst_stack;
        for (i = current_state.ga_len; --i >= 0;) {
            if (bp[i].bs_idx != CUR_STATE (i).si_idx)
                break;
            if (bp[i].bs_extmatch != CUR_STATE (i).si_extmatch) {
                bsx = bp[i].bs_extmatch;
                six = CUR_STATE (i).si_extmatch;
                if (bsx == NULL || six == NULL)
                    break;
                for (j = 0; j < NSUBEXP; ++j) {
                    if (bsx->matches[j] != six->matches[j]) {
                        if (bsx->matches[j] == NULL || six->matches[j] == NULL)
                            break;
                        if ((SYN_ITEMS (syn_block)[CUR_STATE (i).si_idx]).sp_ic ? MB_STRICMP (bsx->matches[j], six->matches[j]) != 0 : STRCMP (bsx->matches[j], six->matches[j]) != 0)
                            break;
                    }
                }
                if (j != NSUBEXP)
                    break;
            }
        }
        if (i < 0)
            return TRUE;
    }
    return FALSE;
}

int get_gui_attr_idx (int attr, guicolor_T fg, guicolor_T bg) {
    attrentry_T at_en;
    vim_memset (& at_en, 0, sizeof (attrentry_T));
    at_en.ae_attr = attr;
    at_en.ae_u.gui.fg_color = fg;
    at_en.ae_u.gui.bg_color = bg;
    return get_attr_entry (&gui_attr_table, &at_en);
}

int get_tgc_attr_idx (int attr, guicolor_T fg, guicolor_T bg) {
    attrentry_T at_en;
    vim_memset (& at_en, 0, sizeof (attrentry_T));
    at_en.ae_attr = attr;
    at_en.ae_u.cterm.fg_rgb = fg;
    at_en.ae_u.cterm.bg_rgb = bg;
    return get_attr_entry (&cterm_attr_table, &at_en);
}

int lookup_color (int idx, int foreground, int *boldp) {
    int color = color_numbers_16[idx];
    char_u *p;
    if (color < 0)
        return -1;
    if (t_colors == 8) {
        color = color_numbers_8[idx];
        if (foreground) {
            if (color & 8)
                *boldp = TRUE;
            else
                *boldp = FALSE;
        }
        color &= 7;
    }
    else if (t_colors == 16 || t_colors == 88 || t_colors >= 256) {
        if (*T_CAF != NUL)
            p = T_CAF;
        else
            p = T_CSF;
        if (*p != NUL && (t_colors > 256 || *(p + STRLEN (p) - 1) == 'm')) {
            if (t_colors == 88)
                color = color_numbers_88[idx];
            else if (t_colors >= 256)
                color = color_numbers_256[idx];
            else
                color = color_numbers_8[idx];
        }
        if (t_colors >= 256 && color == 15 && is_mac_terminal)
            color = 231;
    }
    return color;
}

int get_cterm_attr_idx (int attr, int fg, int bg) {
    attrentry_T at_en;
    vim_memset (& at_en, 0, sizeof (attrentry_T));
    at_en.ae_attr = attr;
    at_en.ae_u.cterm.fg_color = fg;
    at_en.ae_u.cterm.bg_color = bg;
    return get_attr_entry (&cterm_attr_table, &at_en);
}

int syn_get_id (win_T *wp, long  lnum, colnr_T col, int trans, int *spellp, int keep_state) {
    if (wp->w_buffer != syn_buf || lnum != current_lnum || col < current_col)
        syntax_start (wp, lnum);
    else if (wp->w_buffer == syn_buf && lnum == current_lnum && col > current_col)
        next_match_idx = -1;
    (void) get_syntax_attr (col, spellp, keep_state);
    return (trans ? current_trans_id : current_id);
}

int get_syntax_attr (colnr_T col, int *can_spell, int keep_state) {
    int attr = 0;
    if (can_spell != NULL)
        *can_spell = syn_block->b_syn_spell == SYNSPL_DEFAULT ? (syn_block->b_spell_cluster_id == 0) : (syn_block->b_syn_spell == SYNSPL_TOP);
    if (syn_block->b_sst_array == NULL)
        return 0;
    if (syn_buf->b_p_smc > 0 && col >= (colnr_T) syn_buf->b_p_smc) {
        clear_current_state ();
        current_id = 0;
        current_trans_id = 0;
        current_flags = 0;
        current_seqnr = 0;
        return 0;
    }
    if (INVALID_STATE (&current_state))
        validate_current_state ();
    while (current_col <= col) {
        attr = syn_current_attr (FALSE, TRUE, can_spell, current_col == col ? keep_state : FALSE);
        ++current_col;
    }
    return attr;
}

int hl_combine_attr (int char_attr, int prim_attr) {
    attrentry_T *char_aep = NULL;
    attrentry_T *spell_aep;
    attrentry_T new_en;
    if (char_attr == 0)
        return prim_attr;
    if (char_attr <= HL_ALL && prim_attr <= HL_ALL)
        return ATTR_COMBINE (char_attr, prim_attr);
    if (gui.in_use) {
        if (char_attr > HL_ALL)
            char_aep = syn_gui_attr2entry (char_attr);
        if (char_aep != NULL)
            new_en = *char_aep;
        else {
            vim_memset (& new_en, 0, sizeof (new_en));
            new_en.ae_u.gui.fg_color = INVALCOLOR;
            new_en.ae_u.gui.bg_color = INVALCOLOR;
            new_en.ae_u.gui.sp_color = INVALCOLOR;
            if (char_attr <= HL_ALL)
                new_en.ae_attr = char_attr;
        }
        if (prim_attr <= HL_ALL)
            new_en.ae_attr = ATTR_COMBINE (new_en.ae_attr, prim_attr);
        else {
            spell_aep = syn_gui_attr2entry (prim_attr);
            if (spell_aep != NULL) {
                new_en.ae_attr = ATTR_COMBINE (new_en.ae_attr, spell_aep->ae_attr);
                if (spell_aep->ae_u.gui.fg_color != INVALCOLOR)
                    new_en.ae_u.gui.fg_color = spell_aep->ae_u.gui.fg_color;
                if (spell_aep->ae_u.gui.bg_color != INVALCOLOR)
                    new_en.ae_u.gui.bg_color = spell_aep->ae_u.gui.bg_color;
                if (spell_aep->ae_u.gui.sp_color != INVALCOLOR)
                    new_en.ae_u.gui.sp_color = spell_aep->ae_u.gui.sp_color;
                if (spell_aep->ae_u.gui.font != NOFONT)
                    new_en.ae_u.gui.font = spell_aep->ae_u.gui.font;
            }
        }
        return get_attr_entry (&gui_attr_table, &new_en);
    }
    if (IS_CTERM) {
        if (char_attr > HL_ALL)
            char_aep = syn_cterm_attr2entry (char_attr);
        if (char_aep != NULL)
            new_en = *char_aep;
        else {
            vim_memset (& new_en, 0, sizeof (new_en));
            new_en.ae_u.cterm.bg_rgb = INVALCOLOR;
            new_en.ae_u.cterm.fg_rgb = INVALCOLOR;
            if (char_attr <= HL_ALL)
                new_en.ae_attr = char_attr;
        }
        if (prim_attr <= HL_ALL)
            new_en.ae_attr = ATTR_COMBINE (new_en.ae_attr, prim_attr);
        else {
            spell_aep = syn_cterm_attr2entry (prim_attr);
            if (spell_aep != NULL) {
                new_en.ae_attr = ATTR_COMBINE (new_en.ae_attr, spell_aep->ae_attr);
                if (spell_aep->ae_u.cterm.fg_color > 0)
                    new_en.ae_u.cterm.fg_color = spell_aep->ae_u.cterm.fg_color;
                if (spell_aep->ae_u.cterm.bg_color > 0)
                    new_en.ae_u.cterm.bg_color = spell_aep->ae_u.cterm.bg_color;
                if (spell_aep->ae_u.cterm.fg_rgb != INVALCOLOR)
                    new_en.ae_u.cterm.fg_rgb = spell_aep->ae_u.cterm.fg_rgb;
                if (spell_aep->ae_u.cterm.bg_rgb != INVALCOLOR)
                    new_en.ae_u.cterm.bg_rgb = spell_aep->ae_u.cterm.bg_rgb;
            }
        }
        return get_attr_entry (&cterm_attr_table, &new_en);
    }
    if (char_attr > HL_ALL)
        char_aep = syn_term_attr2entry (char_attr);
    if (char_aep != NULL)
        new_en = *char_aep;
    else {
        vim_memset (& new_en, 0, sizeof (new_en));
        if (char_attr <= HL_ALL)
            new_en.ae_attr = char_attr;
    }
    if (prim_attr <= HL_ALL)
        new_en.ae_attr = ATTR_COMBINE (new_en.ae_attr, prim_attr);
    else {
        spell_aep = syn_term_attr2entry (prim_attr);
        if (spell_aep != NULL) {
            new_en.ae_attr = ATTR_COMBINE (new_en.ae_attr, spell_aep->ae_attr);
            if (spell_aep->ae_u.term.start != NULL) {
                new_en.ae_u.term.start = spell_aep->ae_u.term.start;
                new_en.ae_u.term.stop = spell_aep->ae_u.term.stop;
            }
        }
    }
    return get_attr_entry (&term_attr_table, &new_en);
}

int get_syntax_info (int *seqnrp) {
    *seqnrp = current_seqnr;
    return current_flags;
}

int syn_get_sub_char (void) {
    return current_sub_char;
}

char_u *get_syntax_name (expand_T *xp, int idx) {
    switch (expand_what) {
    case EXP_SUBCMD :
        return (char_u *) subcommands[idx].name;
    case EXP_CASE :
        {
            static char *case_args [] = {"match", "ignore", NULL};
            return (char_u *) case_args[idx];
        }
    case EXP_SPELL :
        {
            static char *spell_args [] = {"toplevel", "notoplevel", "default", NULL};
            return (char_u *) spell_args[idx];
        }
    case EXP_SYNC :
        {
            static char *sync_args [] = {"ccomment", "clear", "fromstart", "linebreaks=", "linecont", "lines=", "match", "maxlines=", "minlines=", "region", NULL};
            return (char_u *) sync_args[idx];
        }
    }
    return NULL;
}

char_u *get_syntime_arg (expand_T *xp, int idx) {
    switch (idx) {
    case 0 :
        return (char_u *) "on";
    case 1 :
        return (char_u *) "off";
    case 2 :
        return (char_u *) "clear";
    case 3 :
        return (char_u *) "report";
    }
    return NULL;
}

char_u *get_highlight_name (expand_T *xp, int idx) {
    return get_highlight_name_ext (xp, idx, TRUE);
}

char_u *get_highlight_name_ext (expand_T *xp, int idx, int skip_cleared) {
    if (idx < 0)
        return NULL;
    if (skip_cleared && idx < highlight_ga.ga_len && HL_TABLE ()[idx].sg_cleared)
        return (char_u *) "";
    if (idx == highlight_ga.ga_len && include_none != 0)
        return (char_u *) "none";
    if (idx == highlight_ga.ga_len + include_none && include_default != 0)
        return (char_u *) "default";
    if (idx == highlight_ga.ga_len + include_none + include_default && include_link != 0)
        return (char_u *) "link";
    if (idx == highlight_ga.ga_len + include_none + include_default + 1 && include_link != 0)
        return (char_u *) "clear";
    if (idx >= highlight_ga.ga_len)
        return NULL;
    return HL_TABLE ()[idx].sg_name;
}

void reset_expand_highlight (void) {
    include_link = include_default = include_none = 0;
}

void set_context_in_echohl_cmd (expand_T *xp, char_u *arg) {
    xp->xp_context = EXPAND_HIGHLIGHT;
    xp->xp_pattern = arg;
    include_none = 1;
}

void set_context_in_syntax_cmd (expand_T *xp, char_u *arg) {
    char_u *p;
    xp->xp_context = EXPAND_SYNTAX;
    expand_what = EXP_SUBCMD;
    xp->xp_pattern = arg;
    include_link = 0;
    include_default = 0;
    if (*arg != NUL) {
        p = skiptowhite (arg);
        if (*p != NUL) {
            xp->xp_pattern = skipwhite (p);
            if (*skiptowhite (xp->xp_pattern) != NUL)
                xp->xp_context = EXPAND_NOTHING;
            else if (STRNICMP (arg, "case", p -arg) == 0)
                expand_what = EXP_CASE;
            else if (STRNICMP (arg, "spell", p -arg) == 0)
                expand_what = EXP_SPELL;
            else if (STRNICMP (arg, "sync", p -arg) == 0)
                expand_what = EXP_SYNC;
            else if (STRNICMP (arg, "keyword", p -arg) == 0 || STRNICMP (arg, "region", p -arg) == 0 || STRNICMP (arg, "match", p -arg) == 0 || STRNICMP (arg, "list", p -arg) == 0)
                xp->xp_context = EXPAND_HIGHLIGHT;
            else
                xp->xp_context = EXPAND_NOTHING;
        }
    }
}

void set_context_in_highlight_cmd (expand_T *xp, char_u *arg) {
    char_u *p;
    xp->xp_context = EXPAND_HIGHLIGHT;
    xp->xp_pattern = arg;
    include_link = 2;
    include_default = 1;
    if (*arg != NUL) {
        p = skiptowhite (arg);
        if (*p != NUL) {
            include_default = 0;
            if (STRNCMP ("default", arg, p -arg) == 0) {
                arg = skipwhite (p);
                xp->xp_pattern = arg;
                p = skiptowhite (arg);
            }
            if (*p != NUL) {
                include_link = 0;
                if (arg[1] == 'i' && arg[0] == 'N')
                    highlight_list ();
                if (STRNCMP ("link", arg, p -arg) == 0 || STRNCMP ("clear", arg, p -arg) == 0) {
                    xp->xp_pattern = skipwhite (p);
                    p = skiptowhite (xp->xp_pattern);
                    if (*p != NUL) {
                        xp->xp_pattern = skipwhite (p);
                        p = skiptowhite (xp->xp_pattern);
                    }
                }
                if (*p != NUL)
                    xp->xp_context = EXPAND_NOTHING;
            }
        }
    }
}

static void highlight_list (void) {
    int i;
    for (i = 10; --i >= 0;)
        highlight_list_two (i, HL_ATTR (HLF_D));
    for (i = 40; --i >= 0;)
        highlight_list_two (99, 0);
}

static void highlight_list_two (int cnt, int attr) {
    msg_puts_attr ((char_u *) & ("N \bI \b!  \b" [cnt / 11]), attr);
    msg_clr_eos ();
    out_flush ();
    ui_delay (cnt == 99 ? 40L : (long) cnt * 50L, FALSE);
}

void hl_set_bg_color_name (char_u *name) {
    int id;
    if (name != NULL) {
        id = syn_name2id ((char_u *) "Normal");
        if (id > 0) {
            vim_free (HL_TABLE () [id - 1].sg_gui_bg_name);
            HL_TABLE ()[id - 1].sg_gui_bg_name = name;
        }
    }
}

void hl_set_fg_color_name (char_u *name) {
    int id;
    if (name != NULL) {
        id = syn_name2id ((char_u *) "Normal");
        if (id > 0) {
            vim_free (HL_TABLE () [id - 1].sg_gui_fg_name);
            HL_TABLE ()[id - 1].sg_gui_fg_name = name;
        }
    }
}

char_u *hl_get_font_name (void) {
    int id;
    char_u *s;
    id = syn_name2id ((char_u *) "Normal");
    if (id > 0) {
        s = HL_TABLE ()[id - 1].sg_font_name;
        if (s != NULL)
            return s;
    }
    return (char_u *) "";
}

int syn_name2attr (char_u *name) {
    int id = syn_name2id (name);
    if (id != 0)
        return syn_id2attr (id);
    return 0;
}

int syntax_check_changed (linenr_T lnum) {
    int retval = TRUE;
    synstate_T *sp;
    if (VALID_STATE (&current_state) && lnum == current_lnum + 1) {
        sp = syn_stack_find_entry (lnum);
        if (sp != NULL && sp->sst_lnum == lnum) {
            (void) syn_finish_line (FALSE);
            if (syn_stack_equal (sp))
                retval = FALSE;
            ++current_lnum;
            (void) store_current_state ();
        }
    }
    return retval;
}

void syntax_end_parsing (linenr_T lnum) {
    synstate_T *sp;
    sp = syn_stack_find_entry (lnum);
    if (sp != NULL && sp->sst_lnum < lnum)
        sp = sp->sst_next;
    if (sp != NULL && sp->sst_change_lnum != 0)
        sp->sst_change_lnum = lnum;
}

void init_highlight (int both, int reset) {
    int i;
    char **pp;
    static int had_both = FALSE;
    char_u *p;
    p = get_var_value ((char_u *) "g:colors_name");
    if (p != NULL) {
        char_u *copy_p = vim_strsave (p);
        int r;
        if (copy_p != NULL) {
            r = load_colors (copy_p);
            vim_free (copy_p);
            if (r == OK)
                return;
        }
    }
    if (both) {
        had_both = TRUE;
        pp = highlight_init_both;
        for (i = 0; pp[i] != NULL; ++i)
            do_highlight ((char_u *) pp[i], reset, TRUE);
    }
    else if (!had_both)
        return;
    if (*p_bg == 'l')
        pp = highlight_init_light;
    else
        pp = highlight_init_dark;
    for (i = 0; pp[i] != NULL; ++i)
        do_highlight ((char_u *) pp[i], reset, TRUE);
    if (t_colors > 8)
        do_highlight ((char_u *) (*p_bg == 'l' ? "Visual cterm=NONE ctermbg=LightGrey" : "Visual cterm=NONE ctermbg=DarkGrey"), FALSE, TRUE);
    else {
        do_highlight ((char_u *) "Visual cterm=reverse ctermbg=NONE", FALSE, TRUE);
        if (*p_bg == 'l')
            do_highlight ((char_u *) "Search ctermfg=black", FALSE, TRUE);
    }
    if (get_var_value ((char_u *) "g:syntax_on") != NULL) {
        static int recursive = 0;
        if (recursive >= 5)
            EMSG (_ ("E679: recursive loop loading syncolor.vim"));
        else {
            ++recursive;
            (void) source_runtime ((char_u *) "syntax/syncolor.vim", DIP_ALL);
            --recursive;
        }
    }
}

int load_colors (char_u *name) {
    char_u *buf;
    int retval = FAIL;
    static int recursive = FALSE;
    if (recursive)
        return OK;
    recursive = TRUE;
    buf = alloc ((unsigned ) (STRLEN (name) + 12));
    if (buf != NULL) {
        sprintf ((char *) buf, "colors/%s.vim", name);
        retval = source_runtime (buf, DIP_START +DIP_OPT);
        vim_free (buf);
        apply_autocmds (EVENT_COLORSCHEME, name, curbuf -> b_fname, FALSE, curbuf);
    }
    recursive = FALSE;
    return retval;
}

void do_highlight (char_u *line, int forceit, int init) {
    char_u *name_end;
    char_u *p;
    char_u *linep;
    char_u *key_start;
    char_u *arg_start;
    char_u *key = NULL, *arg = NULL;
    long  i;
    int off;
    int len;
    int attr;
    int id;
    int idx;
    struct hl_group item_before;
    int did_change = FALSE;
    int dodefault = FALSE;
    int doclear = FALSE;
    int dolink = FALSE;
    int error = FALSE;
    int color;
    int is_normal_group = FALSE;
    int is_terminal_group = FALSE;

    # define is_menu_group 0

    # define is_tooltip_group 0
    int did_highlight_changed = FALSE;
    if (ends_excmd (*line)) {
        for (i = 1; i <= highlight_ga.ga_len && !got_int; ++i)
            highlight_list_one ((int) i);
        return;
    }
    name_end = skiptowhite (line);
    linep = skipwhite (name_end);
    if (STRNCMP (line, "default", name_end -line) == 0) {
        dodefault = TRUE;
        line = linep;
        name_end = skiptowhite (line);
        linep = skipwhite (name_end);
    }
    if (STRNCMP (line, "clear", name_end -line) == 0)
        doclear = TRUE;
    if (STRNCMP (line, "link", name_end -line) == 0)
        dolink = TRUE;
    if (!doclear && !dolink && ends_excmd (*linep)) {
        id = syn_namen2id (line, (int) (name_end - line));
        if (id == 0)
            EMSG2 (_ ("E411: highlight group not found: %s"), line);
        else
            highlight_list_one (id);
        return;
    }
    if (dolink) {
        char_u *from_start = linep;
        char_u *from_end;
        char_u *to_start;
        char_u *to_end;
        int from_id;
        int to_id;
        from_end = skiptowhite (from_start);
        to_start = skipwhite (from_end);
        to_end = skiptowhite (to_start);
        if (ends_excmd (*from_start) || ends_excmd (*to_start)) {
            EMSG2 (_ ("E412: Not enough arguments: \":highlight link %s\""), from_start);
            return;
        }
        if (!ends_excmd (*skipwhite (to_end))) {
            EMSG2 (_ ("E413: Too many arguments: \":highlight link %s\""), from_start);
            return;
        }
        from_id = syn_check_group (from_start, (int) (from_end - from_start));
        if (STRNCMP (to_start, "NONE", 4) == 0)
            to_id = 0;
        else
            to_id = syn_check_group (to_start, (int) (to_end - to_start));
        if (from_id > 0 && (!init || HL_TABLE ()[from_id - 1].sg_set == 0)) {
            if (to_id > 0 && !forceit && !init && hl_has_settings (from_id -1, dodefault)) {
                if (sourcing_name == NULL && !dodefault)
                    EMSG (_ ("E414: group has settings, highlight link ignored"));
            }
            else if (HL_TABLE ()[from_id - 1].sg_link != to_id || HL_TABLE ()[from_id - 1].sg_scriptID != current_SID || HL_TABLE ()[from_id - 1].sg_cleared) {
                if (!init)
                    HL_TABLE ()[from_id - 1].sg_set |= SG_LINK;
                HL_TABLE ()[from_id - 1].sg_link = to_id;
                HL_TABLE ()[from_id - 1].sg_scriptID = current_SID;
                HL_TABLE ()[from_id - 1].sg_cleared = FALSE;
                redraw_all_later (SOME_VALID);
                need_highlight_changed = TRUE;
            }
        }
        return;
    }
    if (doclear) {
        line = linep;
        if (ends_excmd (*line)) {
            if (gui.in_use) {
            }
            gui_mch_def_colors ();
            do_unlet ((char_u *) "colors_name", TRUE);
            restore_cterm_colors ();
            for (idx = 0; idx < highlight_ga.ga_len; ++idx)
                highlight_clear (idx);
            init_highlight (TRUE, TRUE);
            if (USE_24BIT)
                highlight_gui_started ();
            else
                highlight_changed ();
            redraw_later_clear ();
            return;
        }
        name_end = skiptowhite (line);
        linep = skipwhite (name_end);
    }
    id = syn_check_group (line, (int) (name_end - line));
    if (id == 0)
        return;
    idx = id - 1;
    if (dodefault && hl_has_settings (idx, TRUE))
        return;
    item_before = HL_TABLE ()[idx];
    if (STRCMP (HL_TABLE ()[idx].sg_name_u, "NORMAL") == 0)
        is_normal_group = TRUE;
    else if (STRCMP (HL_TABLE ()[idx].sg_name_u, "TERMINAL") == 0)
        is_terminal_group = TRUE;
    if (doclear || (forceit && init)) {
        highlight_clear (idx);
        if (!doclear)
            HL_TABLE ()[idx].sg_set = 0;
    }
    if (!doclear)
        while (!ends_excmd (*linep)) {
            key_start = linep;
            if (*linep == '=') {
                EMSG2 (_ ("E415: unexpected equal sign: %s"), key_start);
                error = TRUE;
                break;
            }
            while (*linep && !VIM_ISWHITE (*linep) && *linep != '=')
                ++linep;
            vim_free (key);
            key = vim_strnsave_up (key_start, (int) (linep - key_start));
            if (key == NULL) {
                error = TRUE;
                break;
            }
            linep = skipwhite (linep);
            if (STRCMP (key, "NONE") == 0) {
                if (!init || HL_TABLE ()[idx].sg_set == 0) {
                    if (!init)
                        HL_TABLE ()[idx].sg_set |= SG_TERM + SG_CTERM + SG_GUI;
                    highlight_clear (idx);
                }
                continue;
            }
            if (*linep != '=') {
                EMSG2 (_ ("E416: missing equal sign: %s"), key_start);
                error = TRUE;
                break;
            }
            ++linep;
            linep = skipwhite (linep);
            if (*linep == '\'') {
                arg_start = ++linep;
                linep = vim_strchr (linep, '\'');
                if (linep == NULL) {
                    EMSG2 (_ (e_invarg2), key_start);
                    error = TRUE;
                    break;
                }
            }
            else {
                arg_start = linep;
                linep = skiptowhite (linep);
            }
            if (linep == arg_start) {
                EMSG2 (_ ("E417: missing argument: %s"), key_start);
                error = TRUE;
                break;
            }
            vim_free (arg);
            arg = vim_strnsave (arg_start, (int) (linep - arg_start));
            if (arg == NULL) {
                error = TRUE;
                break;
            }
            if (*linep == '\'')
                ++linep;
            if (STRCMP (key, "TERM") == 0 || STRCMP (key, "CTERM") == 0 || STRCMP (key, "GUI") == 0) {
                attr = 0;
                off = 0;
                while (arg[off] != NUL) {
                    for (i = sizeof (hl_attr_table) / sizeof (int); --i >= 0;) {
                        len = (int) STRLEN (hl_name_table[i]);
                        if (STRNICMP (arg +off, hl_name_table[i], len) == 0) {
                            attr |= hl_attr_table[i];
                            off += len;
                            break;
                        }
                    }
                    if (i < 0) {
                        EMSG2 (_ ("E418: Illegal value: %s"), arg);
                        error = TRUE;
                        break;
                    }
                    if (arg[off] == ',')
                        ++off;
                }
                if (error)
                    break;
                if (*key == 'T') {
                    if (!init || !(HL_TABLE ()[idx].sg_set & SG_TERM)) {
                        if (!init)
                            HL_TABLE ()[idx].sg_set |= SG_TERM;
                        HL_TABLE ()[idx].sg_term = attr;
                    }
                }
                else if (*key == 'C') {
                    if (!init || !(HL_TABLE ()[idx].sg_set & SG_CTERM)) {
                        if (!init)
                            HL_TABLE ()[idx].sg_set |= SG_CTERM;
                        HL_TABLE ()[idx].sg_cterm = attr;
                        HL_TABLE ()[idx].sg_cterm_bold = FALSE;
                    }
                }
                else {
                    if (!init || !(HL_TABLE ()[idx].sg_set & SG_GUI)) {
                        if (!init)
                            HL_TABLE ()[idx].sg_set |= SG_GUI;
                        HL_TABLE ()[idx].sg_gui = attr;
                    }
                }
            }
            else if (STRCMP (key, "FONT") == 0) {
                if (HL_TABLE ()[idx].sg_font_name != NULL && STRCMP (HL_TABLE ()[idx].sg_font_name, arg) == 0) {
                }
                else if (!gui.shell_created) {
                    vim_free (HL_TABLE () [idx].sg_font_name);
                    HL_TABLE ()[idx].sg_font_name = vim_strsave (arg);
                    did_change = TRUE;
                }
                else {
                    GuiFont temp_sg_font = HL_TABLE ()[idx].sg_font;
                    HL_TABLE ()[idx].sg_font = NOFONT;
                    hl_do_font (idx, arg, is_normal_group, is_menu_group, is_tooltip_group, FALSE);
                    if (HL_TABLE ()[idx].sg_font != NOFONT) {
                        gui_mch_free_font (temp_sg_font);
                        vim_free (HL_TABLE () [idx].sg_font_name);
                        HL_TABLE ()[idx].sg_font_name = vim_strsave (arg);
                        did_change = TRUE;
                    }
                    else
                        HL_TABLE ()[idx].sg_font = temp_sg_font;
                }
            }
            else if (STRCMP (key, "CTERMFG") == 0 || STRCMP (key, "CTERMBG") == 0) {
                if (!init || !(HL_TABLE ()[idx].sg_set & SG_CTERM)) {
                    if (!init)
                        HL_TABLE ()[idx].sg_set |= SG_CTERM;
                    if (key[5] == 'F' && HL_TABLE ()[idx].sg_cterm_bold) {
                        HL_TABLE ()[idx].sg_cterm &= ~HL_BOLD;
                        HL_TABLE ()[idx].sg_cterm_bold = FALSE;
                    }
                    if (VIM_ISDIGIT (*arg))
                        color = atoi ((char *) arg);
                    else if (STRICMP (arg, "fg") == 0) {
                        if (cterm_normal_fg_color)
                            color = cterm_normal_fg_color - 1;
                        else {
                            EMSG (_ ("E419: FG color unknown"));
                            error = TRUE;
                            break;
                        }
                    }
                    else if (STRICMP (arg, "bg") == 0) {
                        if (cterm_normal_bg_color > 0)
                            color = cterm_normal_bg_color - 1;
                        else {
                            EMSG (_ ("E420: BG color unknown"));
                            error = TRUE;
                            break;
                        }
                    }
                    else {
                        int bold = MAYBE;
                        off = TOUPPER_ASC (*arg);
                        for (i = (sizeof (color_names) / sizeof (char *)); --i >= 0;)
                            if (off == color_names[i][0] && STRICMP (arg +1, color_names[i] + 1) == 0)
                                break;
                        if (i < 0) {
                            EMSG2 (_ ("E421: Color name or number not recognized: %s"), key_start);
                            error = TRUE;
                            break;
                        }
                        color = lookup_color (i, key[5] == 'F', &bold);
                        if (bold == TRUE) {
                            HL_TABLE ()[idx].sg_cterm |= HL_BOLD;
                            HL_TABLE ()[idx].sg_cterm_bold = TRUE;
                        }
                        else if (bold == FALSE)
                            HL_TABLE ()[idx].sg_cterm &= ~HL_BOLD;
                    }
                    if (key[5] == 'F') {
                        HL_TABLE ()[idx].sg_cterm_fg = color + 1;
                        if (is_normal_group) {
                            cterm_normal_fg_color = color + 1;
                            cterm_normal_fg_bold = (HL_TABLE ()[idx].sg_cterm & HL_BOLD);
                            if (!gui.in_use && !gui.starting) {
                                must_redraw = CLEAR;
                                if (termcap_active && color >= 0)
                                    term_fg_color (color);
                            }
                        }
                    }
                    else {
                        HL_TABLE ()[idx].sg_cterm_bg = color + 1;
                        if (is_normal_group) {
                            cterm_normal_bg_color = color + 1;
                            if (!gui.in_use && !gui.starting) {
                                must_redraw = CLEAR;
                                if (color >= 0) {
                                    int dark = -1;
                                    if (termcap_active)
                                        term_bg_color (color);
                                    if (t_colors < 16)
                                        dark = (color == 0 || color == 4);
                                    else if (color < 16)
                                        dark = (color < 7 || color == 8);
                                    if (dark != -1 && dark != (*p_bg == 'd') && !option_was_set ((char_u *) "bg")) {
                                        set_option_value ((char_u *) "bg", 0L, (char_u *) (dark ? "dark" : "light"), 0);
                                        reset_option_was_set ((char_u *) "bg");
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else if (STRCMP (key, "GUIFG") == 0) {
                char_u **namep = &HL_TABLE ()[idx].sg_gui_fg_name;
                if (!init || !(HL_TABLE ()[idx].sg_set & SG_GUI)) {
                    if (!init)
                        HL_TABLE ()[idx].sg_set |= SG_GUI;
                    i = color_name2handle (arg);
                    if (i != INVALCOLOR || STRCMP (arg, "NONE") == 0 || !USE_24BIT) {
                        HL_TABLE ()[idx].sg_gui_fg = i;
                        if (*namep == NULL || STRCMP (*namep, arg) != 0) {
                            vim_free (*namep);
                            if (STRCMP (arg, "NONE") != 0)
                                *namep = vim_strsave (arg);
                            else
                                *namep = NULL;
                            did_change = TRUE;
                        }
                    }
                }
            }
            else if (STRCMP (key, "GUIBG") == 0) {
                char_u **namep = &HL_TABLE ()[idx].sg_gui_bg_name;
                if (!init || !(HL_TABLE ()[idx].sg_set & SG_GUI)) {
                    if (!init)
                        HL_TABLE ()[idx].sg_set |= SG_GUI;
                    i = color_name2handle (arg);
                    if (i != INVALCOLOR || STRCMP (arg, "NONE") == 0 || !USE_24BIT) {
                        HL_TABLE ()[idx].sg_gui_bg = i;
                        if (*namep == NULL || STRCMP (*namep, arg) != 0) {
                            vim_free (*namep);
                            if (STRCMP (arg, "NONE") != 0)
                                *namep = vim_strsave (arg);
                            else
                                *namep = NULL;
                            did_change = TRUE;
                        }
                    }
                }
            }
            else if (STRCMP (key, "GUISP") == 0) {
                char_u **namep = &HL_TABLE ()[idx].sg_gui_sp_name;
                if (!init || !(HL_TABLE ()[idx].sg_set & SG_GUI)) {
                    if (!init)
                        HL_TABLE ()[idx].sg_set |= SG_GUI;
                    i = color_name2handle (arg);
                    if (i != INVALCOLOR || STRCMP (arg, "NONE") == 0 || !gui.in_use) {
                        HL_TABLE ()[idx].sg_gui_sp = i;
                        if (*namep == NULL || STRCMP (*namep, arg) != 0) {
                            vim_free (*namep);
                            if (STRCMP (arg, "NONE") != 0)
                                *namep = vim_strsave (arg);
                            else
                                *namep = NULL;
                            did_change = TRUE;
                        }
                    }
                }
            }
            else if (STRCMP (key, "START") == 0 || STRCMP (key, "STOP") == 0) {
                char_u buf [100];
                char_u *tname;
                if (!init)
                    HL_TABLE ()[idx].sg_set |= SG_TERM;
                if (STRNCMP (arg, "t_", 2) == 0) {
                    off = 0;
                    buf[0] = 0;
                    while (arg[off] != NUL) {
                        for (len = 0; arg[off + len] && arg[off + len] != ','; ++len)
                            ;
                        tname = vim_strnsave (arg +off, len);
                        if (tname == NULL) {
                            error = TRUE;
                            break;
                        }
                        p = get_term_code (tname);
                        vim_free (tname);
                        if (p == NULL)
                            p = (char_u *) "";
                        if ((int) (STRLEN (buf) + STRLEN (p)) >= 99) {
                            EMSG2 (_ ("E422: terminal code too long: %s"), arg);
                            error = TRUE;
                            break;
                        }
                        STRCAT (buf, p);
                        off += len;
                        if (arg[off] == ',')
                            ++off;
                    }
                }
                else {
                    for (p = arg, off = 0; off < 100 - 6 && *p;) {
                        len = trans_special (&p, buf +off, FALSE, FALSE);
                        if (len > 0)
                            off += len;
                        else
                            buf[off++] = *p++;
                    }
                    buf[off] = NUL;
                }
                if (error)
                    break;
                if (STRCMP (buf, "NONE") == 0)
                    p = NULL;
                else
                    p = vim_strsave (buf);
                if (key[2] == 'A') {
                    vim_free (HL_TABLE () [idx].sg_start);
                    HL_TABLE ()[idx].sg_start = p;
                }
                else {
                    vim_free (HL_TABLE () [idx].sg_stop);
                    HL_TABLE ()[idx].sg_stop = p;
                }
            }
            else {
                EMSG2 (_ ("E423: Illegal argument: %s"), key_start);
                error = TRUE;
                break;
            }
            HL_TABLE ()[idx].sg_cleared = FALSE;
            if (!init || !(HL_TABLE ()[idx].sg_set & SG_LINK))
                HL_TABLE ()[idx].sg_link = 0;
            linep = skipwhite (linep);
        }
    if (error && idx == highlight_ga.ga_len)
        syn_unadd_group ();
    else {
        if (is_normal_group) {
            HL_TABLE ()[idx].sg_term_attr = 0;
            HL_TABLE ()[idx].sg_cterm_attr = 0;
            HL_TABLE ()[idx].sg_gui_attr = 0;
            if (USE_24BIT) {
                highlight_gui_started ();
                did_highlight_changed = TRUE;
                redraw_all_later (NOT_VALID);
            }
        }
        else if (is_terminal_group)
            set_terminal_default_colors (HL_TABLE ()[idx].sg_cterm_fg, HL_TABLE ()[idx].sg_cterm_bg);
        else
            set_hl_attr (idx);
        HL_TABLE ()[idx].sg_scriptID = current_SID;
    }
    vim_free (key);
    vim_free (arg);
    if ((did_change || memcmp (&HL_TABLE ()[idx], &item_before, sizeof (item_before)) != 0) && !did_highlight_changed) {
        if (!updating_screen)
            redraw_all_later (NOT_VALID);
        need_highlight_changed = TRUE;
    }
}

static void highlight_list_one (int id) {
    struct hl_group *sgp;
    int didh = FALSE;
    sgp = &HL_TABLE ()[id - 1];
    didh = highlight_list_arg (id, didh, LIST_ATTR, sgp->sg_term, NULL, "term");
    didh = highlight_list_arg (id, didh, LIST_STRING, 0, sgp->sg_start, "start");
    didh = highlight_list_arg (id, didh, LIST_STRING, 0, sgp->sg_stop, "stop");
    didh = highlight_list_arg (id, didh, LIST_ATTR, sgp->sg_cterm, NULL, "cterm");
    didh = highlight_list_arg (id, didh, LIST_INT, sgp->sg_cterm_fg, NULL, "ctermfg");
    didh = highlight_list_arg (id, didh, LIST_INT, sgp->sg_cterm_bg, NULL, "ctermbg");
    didh = highlight_list_arg (id, didh, LIST_ATTR, sgp->sg_gui, NULL, "gui");
    didh = highlight_list_arg (id, didh, LIST_STRING, 0, sgp->sg_gui_fg_name, "guifg");
    didh = highlight_list_arg (id, didh, LIST_STRING, 0, sgp->sg_gui_bg_name, "guibg");
    didh = highlight_list_arg (id, didh, LIST_STRING, 0, sgp->sg_gui_sp_name, "guisp");
    didh = highlight_list_arg (id, didh, LIST_STRING, 0, sgp->sg_font_name, "font");
    if (sgp->sg_link && !got_int) {
        (void) syn_list_header (didh, 9999, id);
        didh = TRUE;
        msg_puts_attr ((char_u *) "links to", HL_ATTR (HLF_D));
        msg_putchar (' ');
        msg_outtrans (HL_TABLE () [HL_TABLE () [id - 1].sg_link - 1].sg_name);
    }
    if (!didh)
        highlight_list_arg (id, didh, LIST_STRING, 0, (char_u *) "cleared", "");
    if (p_verbose > 0)
        last_set_msg (sgp->sg_scriptID);
}

static int highlight_list_arg (int id, int didh, int type, int iarg, char_u *sarg, char *name) {
    char_u buf [100];
    char_u *ts;
    int i;
    if (got_int)
        return FALSE;
    if (type == LIST_STRING ? (sarg != NULL) : (iarg != 0)) {
        ts = buf;
        if (type == LIST_INT)
            sprintf ((char *) buf, "%d", iarg -1);
        else if (type == LIST_STRING)
            ts = sarg;
        else {
            buf[0] = NUL;
            for (i = 0; hl_attr_table[i] != 0; ++i) {
                if (iarg & hl_attr_table[i]) {
                    if (buf[0] != NUL)
                        vim_strcat (buf, (char_u *) ",", 100);
                    vim_strcat (buf, (char_u *) hl_name_table [i], 100);
                    iarg &= ~hl_attr_table[i];
                }
            }
        }
        (void) syn_list_header (didh, (int) (vim_strsize (ts) + STRLEN (name) + 1), id);
        didh = TRUE;
        if (!got_int) {
            if (*name != NUL) {
                MSG_PUTS_ATTR (name, HL_ATTR (HLF_D));
                MSG_PUTS_ATTR ("=", HL_ATTR (HLF_D));
            }
            msg_outtrans (ts);
        }
    }
    return didh;
}

static int syn_list_header (int did_header, int outlen, int id) {
    int endcol = 19;
    int newline = TRUE;
    if (!did_header) {
        msg_putchar ('\n');
        if (got_int)
            return TRUE;
        msg_outtrans (HL_TABLE () [id - 1].sg_name);
        endcol = 15;
    }
    else if (msg_col + outlen + 1 >= Columns) {
        msg_putchar ('\n');
        if (got_int)
            return TRUE;
    }
    else {
        if (msg_col >= endcol)
            newline = FALSE;
    }
    if (msg_col >= endcol)
        endcol = msg_col + 1;
    if (Columns <= endcol)
        endcol = Columns - 1;
    msg_advance (endcol);
    if (!did_header) {
        msg_puts_attr ((char_u *) "xxx", syn_id2attr (id));
        msg_putchar (' ');
    }
    return newline;
}

int syn_namen2id (char_u *linep, int len) {
    char_u *name;
    int id = 0;
    name = vim_strnsave (linep, len);
    if (name != NULL) {
        id = syn_name2id (name);
        vim_free (name);
    }
    return id;
}

static int hl_has_settings (int idx, int check_link) {
    return (HL_TABLE ()[idx].sg_term_attr != 0 || HL_TABLE ()[idx].sg_cterm_attr != 0 || HL_TABLE ()[idx].sg_cterm_fg != 0 || HL_TABLE ()[idx].sg_cterm_bg != 0 || HL_TABLE ()[idx].sg_gui_attr != 0 || HL_TABLE ()[idx].sg_gui_fg_name != NULL || HL_TABLE ()[idx].sg_gui_bg_name != NULL || HL_TABLE ()[idx].sg_gui_sp_name != NULL || HL_TABLE ()[idx].sg_font_name != NULL || (check_link && (HL_TABLE ()[idx].sg_set & SG_LINK)));
}

void restore_cterm_colors (void) {
    cterm_normal_fg_color = 0;
    cterm_normal_fg_bold = 0;
    cterm_normal_bg_color = 0;
    cterm_normal_fg_gui_color = INVALCOLOR;
    cterm_normal_bg_gui_color = INVALCOLOR;
}

static void highlight_clear (int idx) {
    HL_TABLE ()[idx].sg_cleared = TRUE;
    HL_TABLE ()[idx].sg_term = 0;
    VIM_CLEAR (HL_TABLE () [idx].sg_start);
    VIM_CLEAR (HL_TABLE () [idx].sg_stop);
    HL_TABLE ()[idx].sg_term_attr = 0;
    HL_TABLE ()[idx].sg_cterm = 0;
    HL_TABLE ()[idx].sg_cterm_bold = FALSE;
    HL_TABLE ()[idx].sg_cterm_fg = 0;
    HL_TABLE ()[idx].sg_cterm_bg = 0;
    HL_TABLE ()[idx].sg_cterm_attr = 0;
    HL_TABLE ()[idx].sg_gui = 0;
    VIM_CLEAR (HL_TABLE () [idx].sg_gui_fg_name);
    VIM_CLEAR (HL_TABLE () [idx].sg_gui_bg_name);
    VIM_CLEAR (HL_TABLE () [idx].sg_gui_sp_name);
    HL_TABLE ()[idx].sg_gui_fg = INVALCOLOR;
    HL_TABLE ()[idx].sg_gui_bg = INVALCOLOR;
    HL_TABLE ()[idx].sg_gui_sp = INVALCOLOR;
    gui_mch_free_font (HL_TABLE () [idx].sg_font);
    HL_TABLE ()[idx].sg_font = NOFONT;
    VIM_CLEAR (HL_TABLE () [idx].sg_font_name);
    HL_TABLE ()[idx].sg_gui_attr = 0;
    if (HL_TABLE ()[idx].sg_link == 0)
        HL_TABLE ()[idx].sg_scriptID = 0;
}

static void syn_unadd_group (void) {
    --highlight_ga.ga_len;
    vim_free (HL_TABLE () [highlight_ga.ga_len].sg_name);
    vim_free (HL_TABLE () [highlight_ga.ga_len].sg_name_u);
}

void syn_stack_apply_changes (buf_T *buf) {
    win_T *wp;
    syn_stack_apply_changes_block (& buf -> b_s, buf);
    FOR_ALL_WINDOWS (wp) {
        if ((wp->w_buffer == buf) && (wp->w_s != &buf->b_s))
            syn_stack_apply_changes_block (wp->w_s, buf);
    }
}

static void syn_stack_apply_changes_block (synblock_T *block, buf_T *buf) {
    synstate_T *p, *prev, *np;
    linenr_T n;
    if (block->b_sst_array == NULL)
        return;
    prev = NULL;
    for (p = block->b_sst_first; p != NULL;) {
        if (p->sst_lnum + block->b_syn_sync_linebreaks > buf->b_mod_top) {
            n = p->sst_lnum + buf->b_mod_xlines;
            if (n <= buf->b_mod_bot) {
                np = p->sst_next;
                if (prev == NULL)
                    block->b_sst_first = np;
                else
                    prev->sst_next = np;
                syn_stack_free_entry (block, p);
                p = np;
                continue;
            }
            if (p->sst_change_lnum != 0 && p->sst_change_lnum > buf->b_mod_top) {
                if (p->sst_change_lnum + buf->b_mod_xlines > buf->b_mod_top)
                    p->sst_change_lnum += buf->b_mod_xlines;
                else
                    p->sst_change_lnum = buf->b_mod_top;
            }
            if (p->sst_change_lnum == 0 || p->sst_change_lnum < buf->b_mod_bot)
                p->sst_change_lnum = buf->b_mod_bot;
            p->sst_lnum = n;
        }
        prev = p;
        p = p->sst_next;
    }
}

int syn_get_foldlevel (win_T *wp, long  lnum) {
    int level = 0;
    int i;
    if (wp->w_s->b_syn_folditems != 0 && !wp->w_s->b_syn_error) {
        syntax_start (wp, lnum);
        for (i = 0; i < current_state.ga_len; ++i)
            if (CUR_STATE (i).si_flags & HL_FOLD)
                ++level;
    }
    if (level > wp->w_p_fdn) {
        level = wp->w_p_fdn;
        if (level < 0)
            level = 0;
    }
    return level;
}

static void syn_cmd_conceal (exarg_T *eap, int syncing) {
    char_u *arg = eap->arg;
    char_u *next;
    eap->nextcmd = find_nextcmd (arg);
    if (eap->skip)
        return;
    next = skiptowhite (arg);
    if (*arg == NUL) {
        if (curwin->w_s->b_syn_conceal)
            MSG (_ ("syntax conceal on"));
        else
            MSG (_ ("syntax conceal off"));
    }
    else if (STRNICMP (arg, "on", 2) == 0 && next - arg == 2)
        curwin->w_s->b_syn_conceal = TRUE;
    else if (STRNICMP (arg, "off", 3) == 0 && next - arg == 3)
        curwin->w_s->b_syn_conceal = FALSE;
    else
        EMSG2 (_ ("E390: Illegal argument: %s"), arg);
}

static void syn_cmd_case (exarg_T *eap, int syncing) {
    char_u *arg = eap->arg;
    char_u *next;
    eap->nextcmd = find_nextcmd (arg);
    if (eap->skip)
        return;
    next = skiptowhite (arg);
    if (*arg == NUL) {
        if (curwin->w_s->b_syn_ic)
            MSG (_ ("syntax case ignore"));
        else
            MSG (_ ("syntax case match"));
    }
    else if (STRNICMP (arg, "match", 5) == 0 && next - arg == 5)
        curwin->w_s->b_syn_ic = FALSE;
    else if (STRNICMP (arg, "ignore", 6) == 0 && next - arg == 6)
        curwin->w_s->b_syn_ic = TRUE;
    else
        EMSG2 (_ ("E390: Illegal argument: %s"), arg);
}

static void syn_cmd_spell (exarg_T *eap, int syncing) {
    char_u *arg = eap->arg;
    char_u *next;
    eap->nextcmd = find_nextcmd (arg);
    if (eap->skip)
        return;
    next = skiptowhite (arg);
    if (*arg == NUL) {
        if (curwin->w_s->b_syn_spell == SYNSPL_TOP)
            MSG (_ ("syntax spell toplevel"));
        else if (curwin->w_s->b_syn_spell == SYNSPL_NOTOP)
            MSG (_ ("syntax spell notoplevel"));
        else
            MSG (_ ("syntax spell default"));
    }
    else if (STRNICMP (arg, "toplevel", 8) == 0 && next - arg == 8)
        curwin->w_s->b_syn_spell = SYNSPL_TOP;
    else if (STRNICMP (arg, "notoplevel", 10) == 0 && next - arg == 10)
        curwin->w_s->b_syn_spell = SYNSPL_NOTOP;
    else if (STRNICMP (arg, "default", 7) == 0 && next - arg == 7)
        curwin->w_s->b_syn_spell = SYNSPL_DEFAULT;
    else {
        EMSG2 (_ ("E390: Illegal argument: %s"), arg);
        return;
    }
    redraw_win_later (curwin, NOT_VALID);
}

static void syn_cmd_iskeyword (exarg_T *eap, int syncing) {
    char_u *arg = eap->arg;
    char_u save_chartab [32];
    char_u *save_isk;
    if (eap->skip)
        return;
    arg = skipwhite (arg);
    if (*arg == NUL) {
        MSG_PUTS ("\n");
        MSG_PUTS (_ ("syntax iskeyword "));
        if (curwin->w_s->b_syn_isk != empty_option)
            msg_outtrans (curwin->w_s->b_syn_isk);
        else
            msg_outtrans ((char_u *) "not set");
    }
    else {
        if (STRNICMP (arg, "clear", 5) == 0) {
            mch_memmove (curwin -> w_s -> b_syn_chartab, curbuf -> b_chartab, (size_t) 32);
            clear_string_option (& curwin -> w_s -> b_syn_isk);
        }
        else {
            mch_memmove (save_chartab, curbuf -> b_chartab, (size_t) 32);
            save_isk = curbuf->b_p_isk;
            curbuf->b_p_isk = vim_strsave (arg);
            buf_init_chartab (curbuf, FALSE);
            mch_memmove (curwin -> w_s -> b_syn_chartab, curbuf -> b_chartab, (size_t) 32);
            mch_memmove (curbuf -> b_chartab, save_chartab, (size_t) 32);
            clear_string_option (& curwin -> w_s -> b_syn_isk);
            curwin->w_s->b_syn_isk = curbuf->b_p_isk;
            curbuf->b_p_isk = save_isk;
        }
    }
    redraw_win_later (curwin, NOT_VALID);
}

static void syn_cmd_clear (exarg_T *eap, int syncing) {
    char_u *arg = eap->arg;
    char_u *arg_end;
    int id;
    eap->nextcmd = find_nextcmd (arg);
    if (eap->skip)
        return;
    if (curwin->w_s->b_syn_topgrp != 0)
        return;
    if (ends_excmd (*arg)) {
        if (syncing)
            syntax_sync_clear ();
        else {
            syntax_clear (curwin -> w_s);
            if (curwin->w_s == &curwin->w_buffer->b_s)
                do_unlet ((char_u *) "b:current_syntax", TRUE);
            do_unlet ((char_u *) "w:current_syntax", TRUE);
        }
    }
    else {
        while (!ends_excmd (*arg)) {
            arg_end = skiptowhite (arg);
            if (*arg == '@') {
                id = syn_scl_namen2id (arg +1, (int) (arg_end - arg - 1));
                if (id == 0) {
                    EMSG2 (_ ("E391: No such syntax cluster: %s"), arg);
                    break;
                }
                else {
                    short  scl_id = id - SYNID_CLUSTER;
                    VIM_CLEAR (SYN_CLSTR (curwin -> w_s) [scl_id].scl_list);
                }
            }
            else {
                id = syn_namen2id (arg, (int) (arg_end - arg));
                if (id == 0) {
                    EMSG2 (_ (e_nogroup), arg);
                    break;
                }
                else
                    syn_clear_one (id, syncing);
            }
            arg = skipwhite (arg_end);
        }
    }
    redraw_curbuf_later (SOME_VALID);
    syn_stack_free_all (curwin -> w_s);
}

static void syntax_sync_clear (void) {
    int i;
    for (i = curwin->w_s->b_syn_patterns.ga_len; --i >= 0;)
        if (SYN_ITEMS (curwin->w_s)[i].sp_syncing)
            syn_remove_pattern (curwin->w_s, i);
    curwin->w_s->b_syn_sync_flags = 0;
    curwin->w_s->b_syn_sync_minlines = 0;
    curwin->w_s->b_syn_sync_maxlines = 0;
    curwin->w_s->b_syn_sync_linebreaks = 0;
    vim_regfree (curwin -> w_s -> b_syn_linecont_prog);
    curwin->w_s->b_syn_linecont_prog = NULL;
    VIM_CLEAR (curwin -> w_s -> b_syn_linecont_pat);
    clear_string_option (& curwin -> w_s -> b_syn_isk);
    syn_stack_free_all (curwin -> w_s);
}

static void syn_remove_pattern (synblock_T *block, int idx) {
    synpat_T *spp;
    spp = &(SYN_ITEMS (block)[idx]);
    if (spp->sp_flags & HL_FOLD)
        --block->b_syn_folditems;
    syn_clear_pattern (block, idx);
    mch_memmove (spp, spp + 1, sizeof (synpat_T) * (block -> b_syn_patterns.ga_len - idx - 1));
    --block->b_syn_patterns.ga_len;
}

static int syn_scl_namen2id (char_u *linep, int len) {
    char_u *name;
    int id = 0;
    name = vim_strnsave (linep, len);
    if (name != NULL) {
        id = syn_scl_name2id (name);
        vim_free (name);
    }
    return id;
}

static int syn_scl_name2id (char_u *name) {
    int i;
    char_u *name_u;
    name_u = vim_strsave_up (name);
    if (name_u == NULL)
        return 0;
    for (i = curwin->w_s->b_syn_clusters.ga_len; --i >= 0;)
        if (SYN_CLSTR (curwin->w_s)[i].scl_name_u != NULL && STRCMP (name_u, SYN_CLSTR (curwin->w_s)[i].scl_name_u) == 0)
            break;
    vim_free (name_u);
    return (i < 0 ? 0 : i + SYNID_CLUSTER);
}

static void syn_clear_one (int id, int syncing) {
    synpat_T *spp;
    int idx;
    if (!syncing) {
        (void) syn_clear_keyword (id, &curwin->w_s->b_keywtab);
        (void) syn_clear_keyword (id, &curwin->w_s->b_keywtab_ic);
    }
    for (idx = curwin->w_s->b_syn_patterns.ga_len; --idx >= 0;) {
        spp = &(SYN_ITEMS (curwin->w_s)[idx]);
        if (spp->sp_syn.id != id || spp->sp_syncing != syncing)
            continue;
        syn_remove_pattern (curwin -> w_s, idx);
    }
}

static void syn_clear_keyword (int id, hashtab_T *ht) {
    hashitem_T *hi;
    keyentry_T *kp;
    keyentry_T *kp_prev;
    keyentry_T *kp_next;
    int todo;
    hash_lock (ht);
    todo = (int) ht->ht_used;
    for (hi = ht->ht_array; todo > 0; ++hi) {
        if (!HASHITEM_EMPTY (hi)) {
            --todo;
            kp_prev = NULL;
            for (kp = HI2KE (hi); kp != NULL;) {
                if (kp->k_syn.id == id) {
                    kp_next = kp->ke_next;
                    if (kp_prev == NULL) {
                        if (kp_next == NULL)
                            hash_remove (ht, hi);
                        else
                            hi->hi_key = KE2HIKEY (kp_next);
                    }
                    else
                        kp_prev->ke_next = kp_next;
                    vim_free (kp -> next_list);
                    vim_free (kp -> k_syn.cont_in_list);
                    vim_free (kp);
                    kp = kp_next;
                }
                else {
                    kp_prev = kp;
                    kp = kp->ke_next;
                }
            }
        }
    }
    hash_unlock (ht);
}

static void syn_cmd_on (exarg_T *eap, int syncing) {
    syn_cmd_onoff (eap, "syntax");
}

static void syn_cmd_onoff (exarg_T *eap, char *name) {
    char_u buf [100];
    eap->nextcmd = check_nextcmd (eap->arg);
    if (!eap->skip) {
        STRCPY (buf, "so ");
        vim_snprintf ((char *) buf + 3, sizeof (buf) - 3, SYNTAX_FNAME, name);
        do_cmdline_cmd (buf);
    }
}

static void syn_cmd_enable (exarg_T *eap, int syncing) {
    set_internal_string_var ((char_u *) "syntax_cmd", (char_u *) "enable");
    syn_cmd_onoff (eap, "syntax");
    do_unlet ((char_u *) "g:syntax_cmd", TRUE);
}

static void syn_cmd_reset (exarg_T *eap, int syncing) {
    eap->nextcmd = check_nextcmd (eap->arg);
    if (!eap->skip) {
        set_internal_string_var ((char_u *) "syntax_cmd", (char_u *) "reset");
        do_cmdline_cmd ((char_u *) "runtime! syntax/syncolor.vim");
        do_unlet ((char_u *) "g:syntax_cmd", TRUE);
    }
}

static void syn_cmd_manual (exarg_T *eap, int syncing) {
    syn_cmd_onoff (eap, "manual");
}

static void syn_cmd_off (exarg_T *eap, int syncing) {
    syn_cmd_onoff (eap, "nosyntax");
}

static void syn_cmd_list (exarg_T *eap, int syncing) {
    char_u *arg = eap->arg;
    int id;
    char_u *arg_end;
    eap->nextcmd = find_nextcmd (arg);
    if (eap->skip)
        return;
    if (!syntax_present (curwin)) {
        MSG (_ (msg_no_items));
        return;
    }
    if (syncing) {
        if (curwin->w_s->b_syn_sync_flags & SF_CCOMMENT) {
            MSG_PUTS (_ ("syncing on C-style comments"));
            syn_lines_msg ();
            syn_match_msg ();
            return;
        }
        else if (!(curwin->w_s->b_syn_sync_flags & SF_MATCH)) {
            if (curwin->w_s->b_syn_sync_minlines == 0)
                MSG_PUTS (_ ("no syncing"));
            else {
                MSG_PUTS (_ ("syncing starts "));
                msg_outnum (curwin -> w_s -> b_syn_sync_minlines);
                MSG_PUTS (_ (" lines before top line"));
                syn_match_msg ();
            }
            return;
        }
        MSG_PUTS_TITLE (_ ("\n--- Syntax sync items ---"));
        if (curwin->w_s->b_syn_sync_minlines > 0 || curwin->w_s->b_syn_sync_maxlines > 0 || curwin->w_s->b_syn_sync_linebreaks > 0) {
            MSG_PUTS (_ ("\nsyncing on items"));
            syn_lines_msg ();
            syn_match_msg ();
        }
    }
    else
        MSG_PUTS_TITLE (_ ("\n--- Syntax items ---"));
    if (ends_excmd (*arg)) {
        for (id = 1; id <= highlight_ga.ga_len && !got_int; ++id)
            syn_list_one (id, syncing, FALSE);
        for (id = 0; id < curwin->w_s->b_syn_clusters.ga_len && !got_int; ++id)
            syn_list_cluster (id);
    }
    else {
        while (!ends_excmd (*arg) && !got_int) {
            arg_end = skiptowhite (arg);
            if (*arg == '@') {
                id = syn_scl_namen2id (arg +1, (int) (arg_end - arg - 1));
                if (id == 0)
                    EMSG2 (_ ("E392: No such syntax cluster: %s"), arg);
                else
                    syn_list_cluster (id -SYNID_CLUSTER);
            }
            else {
                id = syn_namen2id (arg, (int) (arg_end - arg));
                if (id == 0)
                    EMSG2 (_ (e_nogroup), arg);
                else
                    syn_list_one (id, syncing, TRUE);
            }
            arg = skipwhite (arg_end);
        }
    }
    eap->nextcmd = check_nextcmd (arg);
}

static void syn_lines_msg (void) {
    if (curwin->w_s->b_syn_sync_maxlines > 0 || curwin->w_s->b_syn_sync_minlines > 0) {
        MSG_PUTS ("; ");
        if (curwin->w_s->b_syn_sync_minlines > 0) {
            MSG_PUTS (_ ("minimal "));
            msg_outnum (curwin -> w_s -> b_syn_sync_minlines);
            if (curwin->w_s->b_syn_sync_maxlines)
                MSG_PUTS (", ");
        }
        if (curwin->w_s->b_syn_sync_maxlines > 0) {
            MSG_PUTS (_ ("maximal "));
            msg_outnum (curwin -> w_s -> b_syn_sync_maxlines);
        }
        MSG_PUTS (_ (" lines before top line"));
    }
}

static void syn_match_msg (void) {
    if (curwin->w_s->b_syn_sync_linebreaks > 0) {
        MSG_PUTS (_ ("; match "));
        msg_outnum (curwin -> w_s -> b_syn_sync_linebreaks);
        MSG_PUTS (_ (" line breaks"));
    }
}

static void syn_list_one (int id, int syncing, int link_only) {
    int attr;
    int idx;
    int did_header = FALSE;
    synpat_T *spp;
    static struct name_list namelist1 [] = {{HL_DISPLAY, "display"}, {HL_CONTAINED, "contained"}, {HL_ONELINE, "oneline"}, {HL_KEEPEND, "keepend"}, {HL_EXTEND, "extend"}, {HL_EXCLUDENL, "excludenl"}, {HL_TRANSP, "transparent"}, {HL_FOLD, "fold"}, {HL_CONCEAL, "conceal"}, {HL_CONCEALENDS, "concealends"}, {0, NULL}};
    static struct name_list namelist2 [] = {{HL_SKIPWHITE, "skipwhite"}, {HL_SKIPNL, "skipnl"}, {HL_SKIPEMPTY, "skipempty"}, {0, NULL}};
    attr = HL_ATTR (HLF_D);
    if (!syncing) {
        did_header = syn_list_keywords (id, &curwin->w_s->b_keywtab, FALSE, attr);
        did_header = syn_list_keywords (id, &curwin->w_s->b_keywtab_ic, did_header, attr);
    }
    for (idx = 0; idx < curwin->w_s->b_syn_patterns.ga_len && !got_int; ++idx) {
        spp = &(SYN_ITEMS (curwin->w_s)[idx]);
        if (spp->sp_syn.id != id || spp->sp_syncing != syncing)
            continue;
        (void) syn_list_header (did_header, 999, id);
        did_header = TRUE;
        last_matchgroup = 0;
        if (spp->sp_type == SPTYPE_MATCH) {
            put_pattern ("match", ' ', spp, attr);
            msg_putchar (' ');
        }
        else if (spp->sp_type == SPTYPE_START) {
            while (SYN_ITEMS (curwin->w_s)[idx].sp_type == SPTYPE_START)
                put_pattern ("start", '=', &SYN_ITEMS (curwin->w_s)[idx++], attr);
            if (SYN_ITEMS (curwin->w_s)[idx].sp_type == SPTYPE_SKIP)
                put_pattern ("skip", '=', &SYN_ITEMS (curwin->w_s)[idx++], attr);
            while (idx < curwin->w_s->b_syn_patterns.ga_len && SYN_ITEMS (curwin->w_s)[idx].sp_type == SPTYPE_END)
                put_pattern ("end", '=', &SYN_ITEMS (curwin->w_s)[idx++], attr);
            --idx;
            msg_putchar (' ');
        }
        syn_list_flags (namelist1, spp -> sp_flags, attr);
        if (spp->sp_cont_list != NULL)
            put_id_list ((char_u *) "contains", spp->sp_cont_list, attr);
        if (spp->sp_syn.cont_in_list != NULL)
            put_id_list ((char_u *) "containedin", spp->sp_syn.cont_in_list, attr);
        if (spp->sp_next_list != NULL) {
            put_id_list ((char_u *) "nextgroup", spp -> sp_next_list, attr);
            syn_list_flags (namelist2, spp -> sp_flags, attr);
        }
        if (spp->sp_flags & (HL_SYNC_HERE | HL_SYNC_THERE)) {
            if (spp->sp_flags & HL_SYNC_HERE)
                msg_puts_attr ((char_u *) "grouphere", attr);
            else
                msg_puts_attr ((char_u *) "groupthere", attr);
            msg_putchar (' ');
            if (spp->sp_sync_idx >= 0)
                msg_outtrans (HL_TABLE ()[SYN_ITEMS (curwin->w_s)[spp->sp_sync_idx].sp_syn.id - 1].sg_name);
            else
                MSG_PUTS ("NONE");
            msg_putchar (' ');
        }
    }
    if (HL_TABLE ()[id - 1].sg_link && (did_header || link_only) && !got_int) {
        (void) syn_list_header (did_header, 999, id);
        msg_puts_attr ((char_u *) "links to", attr);
        msg_putchar (' ');
        msg_outtrans (HL_TABLE () [HL_TABLE () [id - 1].sg_link - 1].sg_name);
    }
}

static int syn_list_keywords (int id, hashtab_T *ht, int did_header, int attr) {
    int outlen;
    hashitem_T *hi;
    keyentry_T *kp;
    int todo;
    int prev_contained = 0;
    short  *prev_next_list = NULL;
    short  *prev_cont_in_list = NULL;
    int prev_skipnl = 0;
    int prev_skipwhite = 0;
    int prev_skipempty = 0;
    todo = (int) ht->ht_used;
    for (hi = ht->ht_array; todo > 0 && !got_int; ++hi) {
        if (!HASHITEM_EMPTY (hi)) {
            --todo;
            for (kp = HI2KE (hi); kp != NULL && !got_int; kp = kp->ke_next) {
                if (kp->k_syn.id == id) {
                    if (prev_contained != (kp->flags & HL_CONTAINED) || prev_skipnl != (kp->flags & HL_SKIPNL) || prev_skipwhite != (kp->flags & HL_SKIPWHITE) || prev_skipempty != (kp->flags & HL_SKIPEMPTY) || prev_cont_in_list != kp->k_syn.cont_in_list || prev_next_list != kp->next_list)
                        outlen = 9999;
                    else
                        outlen = (int) STRLEN (kp->keyword);
                    if (syn_list_header (did_header, outlen, id)) {
                        prev_contained = 0;
                        prev_next_list = NULL;
                        prev_cont_in_list = NULL;
                        prev_skipnl = 0;
                        prev_skipwhite = 0;
                        prev_skipempty = 0;
                    }
                    did_header = TRUE;
                    if (prev_contained != (kp->flags & HL_CONTAINED)) {
                        msg_puts_attr ((char_u *) "contained", attr);
                        msg_putchar (' ');
                        prev_contained = (kp->flags & HL_CONTAINED);
                    }
                    if (kp->k_syn.cont_in_list != prev_cont_in_list) {
                        put_id_list ((char_u *) "containedin", kp -> k_syn.cont_in_list, attr);
                        msg_putchar (' ');
                        prev_cont_in_list = kp->k_syn.cont_in_list;
                    }
                    if (kp->next_list != prev_next_list) {
                        put_id_list ((char_u *) "nextgroup", kp -> next_list, attr);
                        msg_putchar (' ');
                        prev_next_list = kp->next_list;
                        if (kp->flags & HL_SKIPNL) {
                            msg_puts_attr ((char_u *) "skipnl", attr);
                            msg_putchar (' ');
                            prev_skipnl = (kp->flags & HL_SKIPNL);
                        }
                        if (kp->flags & HL_SKIPWHITE) {
                            msg_puts_attr ((char_u *) "skipwhite", attr);
                            msg_putchar (' ');
                            prev_skipwhite = (kp->flags & HL_SKIPWHITE);
                        }
                        if (kp->flags & HL_SKIPEMPTY) {
                            msg_puts_attr ((char_u *) "skipempty", attr);
                            msg_putchar (' ');
                            prev_skipempty = (kp->flags & HL_SKIPEMPTY);
                        }
                    }
                    msg_outtrans (kp -> keyword);
                }
            }
        }
    }
    return did_header;
}

static void put_id_list (char_u *name, short  *list, int attr) {
    short  *p;
    msg_puts_attr (name, attr);
    msg_putchar ('=');
    for (p = list; *p; ++p) {
        if (*p >= SYNID_ALLBUT && *p < SYNID_TOP) {
            if (p[1])
                MSG_PUTS ("ALLBUT");
            else
                MSG_PUTS ("ALL");
        }
        else if (*p >= SYNID_TOP && *p < SYNID_CONTAINED) {
            MSG_PUTS ("TOP");
        }
        else if (*p >= SYNID_CONTAINED && *p < SYNID_CLUSTER) {
            MSG_PUTS ("CONTAINED");
        }
        else if (*p >= SYNID_CLUSTER) {
            short  scl_id = *p - SYNID_CLUSTER;
            msg_putchar ('@');
            msg_outtrans (SYN_CLSTR (curwin -> w_s) [scl_id].scl_name);
        }
        else
            msg_outtrans (HL_TABLE ()[*p - 1].sg_name);
        if (p[1])
            msg_putchar (',');
    }
    msg_putchar (' ');
}

static void put_pattern (char *s, int c, synpat_T *spp, int attr) {
    long  n;
    int mask;
    int first;
    static char *sepchars = "/+=-#@\"|'^&";
    int i;
    if (last_matchgroup != spp->sp_syn_match_id) {
        last_matchgroup = spp->sp_syn_match_id;
        msg_puts_attr ((char_u *) "matchgroup", attr);
        msg_putchar ('=');
        if (last_matchgroup == 0)
            msg_outtrans ((char_u *) "NONE");
        else
            msg_outtrans (HL_TABLE ()[last_matchgroup - 1].sg_name);
        msg_putchar (' ');
    }
    msg_puts_attr ((char_u *) s, attr);
    msg_putchar (c);
    for (i = 0; vim_strchr (spp->sp_pattern, sepchars[i]) != NULL;)
        if (sepchars[++i] == NUL) {
            i = 0;
            break;
        }
    msg_putchar (sepchars [i]);
    msg_outtrans (spp -> sp_pattern);
    msg_putchar (sepchars [i]);
    first = TRUE;
    for (i = 0; i < SPO_COUNT; ++i) {
        mask = (1 << i);
        if (spp->sp_off_flags & (mask + (mask << SPO_COUNT))) {
            if (!first)
                msg_putchar (',');
            msg_puts ((char_u *) spo_name_tab [i]);
            n = spp->sp_offsets[i];
            if (i != SPO_LC_OFF) {
                if (spp->sp_off_flags & mask)
                    msg_putchar ('s');
                else
                    msg_putchar ('e');
                if (n > 0)
                    msg_putchar ('+');
            }
            if (n || i == SPO_LC_OFF)
                msg_outnum (n);
            first = FALSE;
        }
    }
    msg_putchar (' ');
}

static void syn_list_flags (struct name_list *nlist, int flags, int attr) {
    int i;
    for (i = 0; nlist[i].flag != 0; ++i)
        if (flags & nlist[i].flag) {
            msg_puts_attr ((char_u *) nlist [i].name, attr);
            msg_putchar (' ');
        }
}

static void syn_list_cluster (int id) {
    int endcol = 15;
    msg_putchar ('\n');
    msg_outtrans (SYN_CLSTR (curwin -> w_s) [id].scl_name);
    if (msg_col >= endcol)
        endcol = msg_col + 1;
    if (Columns <= endcol)
        endcol = Columns - 1;
    msg_advance (endcol);
    if (SYN_CLSTR (curwin->w_s)[id].scl_list != NULL) {
        put_id_list ((char_u *) "cluster", SYN_CLSTR (curwin -> w_s) [id].scl_list, HL_ATTR (HLF_D));
    }
    else {
        msg_puts_attr ((char_u *) "cluster", HL_ATTR (HLF_D));
        msg_puts ((char_u *) "=NONE");
    }
}

static void syn_cmd_include (exarg_T *eap, int syncing) {
    char_u *arg = eap->arg;
    int sgl_id = 1;
    char_u *group_name_end;
    char_u *rest;
    char_u *errormsg = NULL;
    int prev_toplvl_grp;
    int prev_syn_inc_tag;
    int source = FALSE;
    eap->nextcmd = find_nextcmd (arg);
    if (eap->skip)
        return;
    if (arg[0] == '@') {
        ++arg;
        rest = get_group_name (arg, &group_name_end);
        if (rest == NULL) {
            EMSG ((char_u *) _ ("E397: Filename required"));
            return;
        }
        sgl_id = syn_check_cluster (arg, (int) (group_name_end - arg));
        if (sgl_id == 0)
            return;
        eap->arg = rest;
    }
    eap->argt |= (XFILE | NOSPC);
    separate_nextcmd (eap);
    if (*eap->arg == '<' || *eap->arg == '$' || mch_isFullName (eap->arg)) {
        source = TRUE;
        if (expand_filename (eap, syn_cmdlinep, &errormsg) == FAIL) {
            if (errormsg != NULL)
                EMSG (errormsg);
            return;
        }
    }
    if (running_syn_inc_tag >= MAX_SYN_INC_TAG) {
        EMSG ((char_u *) _ ("E847: Too many syntax includes"));
        return;
    }
    prev_syn_inc_tag = current_syn_inc_tag;
    current_syn_inc_tag = ++running_syn_inc_tag;
    prev_toplvl_grp = curwin->w_s->b_syn_topgrp;
    curwin->w_s->b_syn_topgrp = sgl_id;
    if (source ? do_source (eap->arg, FALSE, DOSO_NONE) == FAIL : source_runtime (eap->arg, DIP_ALL) == FAIL)
        EMSG2 (_ (e_notopen), eap->arg);
    curwin->w_s->b_syn_topgrp = prev_toplvl_grp;
    current_syn_inc_tag = prev_syn_inc_tag;
}

static char_u *get_group_name (char_u *arg, char_u **name_end) {
    char_u *rest;
    *name_end = skiptowhite (arg);
    rest = skipwhite (*name_end);
    if (ends_excmd (*arg) || *rest == NUL)
        return NULL;
    return rest;
}

static int syn_check_cluster (char_u *pp, int len) {
    int id;
    char_u *name;
    name = vim_strnsave (pp, len);
    if (name == NULL)
        return 0;
    id = syn_scl_name2id (name);
    if (id == 0)
        id = syn_add_cluster (name);
    else
        vim_free (name);
    return id;
}

static int syn_add_cluster (char_u *name) {
    int len;
    if (curwin->w_s->b_syn_clusters.ga_data == NULL) {
        curwin->w_s->b_syn_clusters.ga_itemsize = sizeof (syn_cluster_T);
        curwin->w_s->b_syn_clusters.ga_growsize = 10;
    }
    len = curwin->w_s->b_syn_clusters.ga_len;
    if (len >= MAX_CLUSTER_ID) {
        EMSG ((char_u *) _ ("E848: Too many syntax clusters"));
        vim_free (name);
        return 0;
    }
    if (ga_grow (&curwin->w_s->b_syn_clusters, 1) == FAIL) {
        vim_free (name);
        return 0;
    }
    vim_memset (& (SYN_CLSTR (curwin -> w_s) [len]), 0, sizeof (syn_cluster_T));
    SYN_CLSTR (curwin->w_s)[len].scl_name = name;
    SYN_CLSTR (curwin->w_s)[len].scl_name_u = vim_strsave_up (name);
    SYN_CLSTR (curwin->w_s)[len].scl_list = NULL;
    ++curwin->w_s->b_syn_clusters.ga_len;
    if (STRICMP (name, "Spell") == 0)
        curwin->w_s->b_spell_cluster_id = len + SYNID_CLUSTER;
    if (STRICMP (name, "NoSpell") == 0)
        curwin->w_s->b_nospell_cluster_id = len + SYNID_CLUSTER;
    return len + SYNID_CLUSTER;
}

static void syn_cmd_keyword (exarg_T *eap, int syncing) {
    char_u *arg = eap->arg;
    char_u *group_name_end;
    int syn_id;
    char_u *rest;
    char_u *keyword_copy = NULL;
    char_u *p;
    char_u *kw;
    syn_opt_arg_T syn_opt_arg;
    int cnt;
    int conceal_char = NUL;
    rest = get_group_name (arg, &group_name_end);
    if (rest != NULL) {
        if (eap->skip)
            syn_id = -1;
        else
            syn_id = syn_check_group (arg, (int) (group_name_end - arg));
        if (syn_id != 0)
            keyword_copy = alloc ((unsigned ) STRLEN (rest) + 1);
        if (keyword_copy != NULL) {
            syn_opt_arg.flags = 0;
            syn_opt_arg.keyword = TRUE;
            syn_opt_arg.sync_idx = NULL;
            syn_opt_arg.has_cont_list = FALSE;
            syn_opt_arg.cont_in_list = NULL;
            syn_opt_arg.next_list = NULL;
            cnt = 0;
            p = keyword_copy;
            for (; rest != NULL && !ends_excmd (*rest); rest = skipwhite (rest)) {
                rest = get_syn_options (rest, &syn_opt_arg, &conceal_char, eap->skip);
                if (rest == NULL || ends_excmd (*rest))
                    break;
                while (*rest != NUL && !VIM_ISWHITE (*rest)) {
                    if (*rest == '\\' && rest[1] != NUL)
                        ++rest;
                    *p++ = *rest++;
                }
                *p++ = NUL;
                ++cnt;
            }
            if (!eap->skip) {
                syn_incl_toplevel (syn_id, & syn_opt_arg.flags);
                for (kw = keyword_copy; --cnt >= 0; kw += STRLEN (kw) + 1) {
                    for (p = vim_strchr (kw, '[');;) {
                        if (p != NULL)
                            *p = NUL;
                        add_keyword (kw, syn_id, syn_opt_arg.flags, syn_opt_arg.cont_in_list, syn_opt_arg.next_list, conceal_char);
                        if (p == NULL)
                            break;
                        if (p[1] == NUL) {
                            EMSG2 (_ ("E789: Missing ']': %s"), kw);
                            goto error;
                        }
                        if (p[1] == ']') {
                            if (p[2] != NUL) {
                                EMSG3 (_ ("E890: trailing char after ']': %s]%s"), kw, & p [2]);
                                goto error;
                            }
                            kw = p + 1;
                            break;
                        }
                        {
                            p[0] = p[1];
                            ++p;
                        }
                    }
                }
            }
        error :
            vim_free (keyword_copy);
            vim_free (syn_opt_arg.cont_in_list);
            vim_free (syn_opt_arg.next_list);
        }
    }
    if (rest != NULL)
        eap->nextcmd = check_nextcmd (rest);
    else
        EMSG2 (_ (e_invarg2), arg);
    redraw_curbuf_later (SOME_VALID);
    syn_stack_free_all (curwin -> w_s);
}

static char_u *get_syn_options (char_u *arg, syn_opt_arg_T *opt, int *conceal_char, int skip) {
    char_u *gname_start, *gname;
    int syn_id;
    int len;
    char *p;
    int i;
    int fidx;
    static struct flag {
        char *name;
        int argtype;
        int flags;
    } flagtab [] = {{"cCoOnNtTaAiInNeEdD", 0, HL_CONTAINED}, {"oOnNeElLiInNeE", 0, HL_ONELINE}, {"kKeEeEpPeEnNdD", 0, HL_KEEPEND}, {"eExXtTeEnNdD", 0, HL_EXTEND}, {"eExXcClLuUdDeEnNlL", 0, HL_EXCLUDENL}, {"tTrRaAnNsSpPaArReEnNtT", 0, HL_TRANSP}, {"sSkKiIpPnNlL", 0, HL_SKIPNL}, {"sSkKiIpPwWhHiItTeE", 0, HL_SKIPWHITE}, {"sSkKiIpPeEmMpPtTyY", 0, HL_SKIPEMPTY}, {"gGrRoOuUpPhHeErReE", 0, HL_SYNC_HERE}, {"gGrRoOuUpPtThHeErReE", 0, HL_SYNC_THERE}, {"dDiIsSpPlLaAyY", 0, HL_DISPLAY}, {"fFoOlLdD", 0, HL_FOLD}, {"cCoOnNcCeEaAlL", 0, HL_CONCEAL}, {"cCoOnNcCeEaAlLeEnNdDsS", 0, HL_CONCEALENDS}, {"cCcChHaArR", 11, 0}, {"cCoOnNtTaAiInNsS", 1, 0}, {"cCoOnNtTaAiInNeEdDiInN", 2, 0}, {"nNeExXtTgGrRoOuUpP", 3, 0},};
    static char *first_letters = "cCoOkKeEtTsSgGdDfFnN";
    if (arg == NULL)
        return NULL;
    if (curwin->w_s->b_syn_conceal)
        opt->flags |= HL_CONCEAL;
    for (;;) {
        if (strchr (first_letters, *arg) == NULL)
            break;
        for (fidx = sizeof (flagtab) / sizeof (struct flag); --fidx >= 0;) {
            p = flagtab[fidx].name;
            for (i = 0, len = 0; p[i] != NUL; i += 2, ++len)
                if (arg[len] != p[i] && arg[len] != p[i + 1])
                    break;
            if (p[i] == NUL && (VIM_ISWHITE (arg[len]) || (flagtab[fidx].argtype > 0 ? arg[len] == '=' : ends_excmd (arg[len])))) {
                if (opt->keyword && (flagtab[fidx].flags == HL_DISPLAY || flagtab[fidx].flags == HL_FOLD || flagtab[fidx].flags == HL_EXTEND))
                    fidx = -1;
                break;
            }
        }
        if (fidx < 0)
            break;
        if (flagtab[fidx].argtype == 1) {
            if (!opt->has_cont_list) {
                EMSG (_ ("E395: contains argument not accepted here"));
                return NULL;
            }
            if (get_id_list (&arg, 8, &opt->cont_list, skip) == FAIL)
                return NULL;
        }
        else if (flagtab[fidx].argtype == 2) {
            if (get_id_list (&arg, 11, &opt->cont_in_list, skip) == FAIL)
                return NULL;
        }
        else if (flagtab[fidx].argtype == 3) {
            if (get_id_list (&arg, 9, &opt->next_list, skip) == FAIL)
                return NULL;
        }
        else if (flagtab[fidx].argtype == 11 && arg[5] == '=') {
            {
                *conceal_char = arg[6];
            }
            if (!vim_isprintc_strict (*conceal_char)) {
                EMSG (_ ("E844: invalid cchar value"));
                return NULL;
            }
            arg = skipwhite (arg +7);
        }
        else {
            opt->flags |= flagtab[fidx].flags;
            arg = skipwhite (arg +len);
            if (flagtab[fidx].flags == HL_SYNC_HERE || flagtab[fidx].flags == HL_SYNC_THERE) {
                if (opt->sync_idx == NULL) {
                    EMSG (_ ("E393: group[t]here not accepted here"));
                    return NULL;
                }
                gname_start = arg;
                arg = skiptowhite (arg);
                if (gname_start == arg)
                    return NULL;
                gname = vim_strnsave (gname_start, (int) (arg - gname_start));
                if (gname == NULL)
                    return NULL;
                if (STRCMP (gname, "NONE") == 0)
                    *opt->sync_idx = NONE_IDX;
                else {
                    syn_id = syn_name2id (gname);
                    for (i = curwin->w_s->b_syn_patterns.ga_len; --i >= 0;)
                        if (SYN_ITEMS (curwin->w_s)[i].sp_syn.id == syn_id && SYN_ITEMS (curwin->w_s)[i].sp_type == SPTYPE_START) {
                            *opt->sync_idx = i;
                            break;
                        }
                    if (i < 0) {
                        EMSG2 (_ ("E394: Didn't find region item for %s"), gname);
                        vim_free (gname);
                        return NULL;
                    }
                }
                vim_free (gname);
                arg = skipwhite (arg);
            }
            else if (flagtab[fidx].flags == HL_FOLD && foldmethodIsSyntax (curwin))
                foldUpdateAll (curwin);
        }
    }
    return arg;
}

static int get_id_list (char_u **arg, int keylen, short  **list, int skip) {
    char_u *p = NULL;
    char_u *end;
    int round;
    int count;
    int total_count = 0;
    short  *retval = NULL;
    char_u *name;
    regmatch_T regmatch;
    int id;
    int i;
    int failed = FALSE;
    for (round = 1; round <= 2; ++round) {
        p = skipwhite (*arg + keylen);
        if (*p != '=') {
            EMSG2 (_ ("E405: Missing equal sign: %s"), * arg);
            break;
        }
        p = skipwhite (p +1);
        if (ends_excmd (*p)) {
            EMSG2 (_ ("E406: Empty argument: %s"), * arg);
            break;
        }
        count = 0;
        while (!ends_excmd (*p)) {
            for (end = p; *end && !VIM_ISWHITE (*end) && *end != ','; ++end)
                ;
            name = alloc ((int) (end - p + 3));
            if (name == NULL) {
                failed = TRUE;
                break;
            }
            vim_strncpy (name + 1, p, end - p);
            if (STRCMP (name +1, "ALLBUT") == 0 || STRCMP (name +1, "ALL") == 0 || STRCMP (name +1, "TOP") == 0 || STRCMP (name +1, "CONTAINED") == 0) {
                if (TOUPPER_ASC (**arg) != 'C') {
                    EMSG2 (_ ("E407: %s not allowed here"), name + 1);
                    failed = TRUE;
                    vim_free (name);
                    break;
                }
                if (count != 0) {
                    EMSG2 (_ ("E408: %s must be first in contains list"), name + 1);
                    failed = TRUE;
                    vim_free (name);
                    break;
                }
                if (name[1] == 'A')
                    id = SYNID_ALLBUT;
                else if (name[1] == 'T')
                    id = SYNID_TOP;
                else
                    id = SYNID_CONTAINED;
                id += current_syn_inc_tag;
            }
            else if (name[1] == '@') {
                if (skip)
                    id = -1;
                else
                    id = syn_check_cluster (name +2, (int) (end - p - 1));
            }
            else {
                if (vim_strpbrk (name +1, (char_u *) "\\.*^$~[") == NULL)
                    id = syn_check_group (name +1, (int) (end - p));
                else {
                    *name = '^';
                    STRCAT (name, "$");
                    regmatch.regprog = vim_regcomp (name, RE_MAGIC);
                    if (regmatch.regprog == NULL) {
                        failed = TRUE;
                        vim_free (name);
                        break;
                    }
                    regmatch.rm_ic = TRUE;
                    id = 0;
                    for (i = highlight_ga.ga_len; --i >= 0;) {
                        if (vim_regexec (&regmatch, HL_TABLE ()[i].sg_name, (colnr_T) 0)) {
                            if (round == 2) {
                                if (count >= total_count) {
                                    vim_free (retval);
                                    round = 1;
                                }
                                else
                                    retval[count] = i + 1;
                            }
                            ++count;
                            id = -1;
                        }
                    }
                    vim_regfree (regmatch.regprog);
                }
            }
            vim_free (name);
            if (id == 0) {
                EMSG2 (_ ("E409: Unknown group name: %s"), p);
                failed = TRUE;
                break;
            }
            if (id > 0) {
                if (round == 2) {
                    if (count >= total_count) {
                        vim_free (retval);
                        round = 1;
                    }
                    else
                        retval[count] = id;
                }
                ++count;
            }
            p = skipwhite (end);
            if (*p != ',')
                break;
            p = skipwhite (p +1);
        }
        if (failed)
            break;
        if (round == 1) {
            retval = (short  *) alloc ((unsigned ) ((count + 1) * sizeof (short )));
            if (retval == NULL)
                break;
            retval[count] = 0;
            total_count = count;
        }
    }
    *arg = p;
    if (failed || retval == NULL) {
        vim_free (retval);
        return FAIL;
    }
    if (*list == NULL)
        *list = retval;
    else
        vim_free (retval);
    return OK;
}

static void syn_incl_toplevel (int id, int *flagsp) {
    if ((*flagsp & HL_CONTAINED) || curwin->w_s->b_syn_topgrp == 0)
        return;
    *flagsp |= HL_CONTAINED;
    if (curwin->w_s->b_syn_topgrp >= SYNID_CLUSTER) {
        short  *grp_list = (short  *) alloc ((unsigned ) (2 * sizeof (short )));
        int tlg_id = curwin->w_s->b_syn_topgrp - SYNID_CLUSTER;
        if (grp_list != NULL) {
            grp_list[0] = id;
            grp_list[1] = 0;
            syn_combine_list (& SYN_CLSTR (curwin -> w_s) [tlg_id].scl_list, & grp_list, CLUSTER_ADD);
        }
    }
}

static void syn_combine_list (short  **clstr1, short  **clstr2, int list_op) {
    int count1 = 0;
    int count2 = 0;
    short  *g1;
    short  *g2;
    short  *clstr = NULL;
    int count;
    int round;
    if (*clstr2 == NULL)
        return;
    if (*clstr1 == NULL || list_op == CLUSTER_REPLACE) {
        if (list_op == CLUSTER_REPLACE)
            vim_free (*clstr1);
        if (list_op == CLUSTER_REPLACE || list_op == CLUSTER_ADD)
            *clstr1 = *clstr2;
        else
            vim_free (*clstr2);
        return;
    }
    for (g1 = *clstr1; *g1; g1++)
        ++count1;
    for (g2 = *clstr2; *g2; g2++)
        ++count2;
    qsort (* clstr1, (size_t) count1, sizeof (short), syn_compare_stub);
    qsort (* clstr2, (size_t) count2, sizeof (short), syn_compare_stub);
    for (round = 1; round <= 2; round++) {
        g1 = *clstr1;
        g2 = *clstr2;
        count = 0;
        while (*g1 && *g2) {
            if (*g1 < *g2) {
                if (round == 2)
                    clstr[count] = *g1;
                count++;
                g1++;
                continue;
            }
            if (list_op == CLUSTER_ADD) {
                if (round == 2)
                    clstr[count] = *g2;
                count++;
            }
            if (*g1 == *g2)
                g1++;
            g2++;
        }
        for (; *g1; g1++, count++)
            if (round == 2)
                clstr[count] = *g1;
        if (list_op == CLUSTER_ADD)
            for (; *g2; g2++, count++)
                if (round == 2)
                    clstr[count] = *g2;
        if (round == 1) {
            if (count == 0) {
                clstr = NULL;
                break;
            }
            clstr = (short  *) alloc ((unsigned ) ((count + 1) * sizeof (short )));
            if (clstr == NULL)
                break;
            clstr[count] = 0;
        }
    }
    vim_free (*clstr1);
    vim_free (*clstr2);
    *clstr1 = clstr;
}

static int syn_compare_stub (const void *v1, const void *v2) {
    const short  *s1 = v1;
    const short  *s2 = v2;
    return (*s1 > *s2 ? 1 : *s1 < *s2 ? -1 : 0);
}

static void add_keyword (char_u *name, int id, int flags, short  *cont_in_list, short  *next_list, int conceal_char) {
    keyentry_T *kp;
    hashtab_T *ht;
    hashitem_T *hi;
    char_u *name_ic;
    long_u hash;
    char_u name_folded [MAXKEYWLEN + 1];
    if (curwin->w_s->b_syn_ic)
        name_ic = str_foldcase (name, (int) STRLEN (name), name_folded, MAXKEYWLEN +1);
    else
        name_ic = name;
    kp = (keyentry_T *) alloc ((int) (sizeof (keyentry_T) + STRLEN (name_ic)));
    if (kp == NULL)
        return;
    STRCPY (kp -> keyword, name_ic);
    kp->k_syn.id = id;
    kp->k_syn.inc_tag = current_syn_inc_tag;
    kp->flags = flags;
    kp->k_char = conceal_char;
    kp->k_syn.cont_in_list = copy_id_list (cont_in_list);
    if (cont_in_list != NULL)
        curwin->w_s->b_syn_containedin = TRUE;
    kp->next_list = copy_id_list (next_list);
    if (curwin->w_s->b_syn_ic)
        ht = &curwin->w_s->b_keywtab_ic;
    else
        ht = &curwin->w_s->b_keywtab;
    hash = hash_hash (kp->keyword);
    hi = hash_lookup (ht, kp->keyword, hash);
    if (HASHITEM_EMPTY (hi)) {
        kp->ke_next = NULL;
        hash_add_item (ht, hi, kp -> keyword, hash);
    }
    else {
        kp->ke_next = HI2KE (hi);
        hi->hi_key = KE2HIKEY (kp);
    }
}

static short  *copy_id_list (short  *list) {
    int len;
    int count;
    short  *retval;
    if (list == NULL)
        return NULL;
    for (count = 0; list[count]; ++count)
        ;
    len = (count + 1) * sizeof (short );
    retval = (short  *) alloc ((unsigned ) len);
    if (retval != NULL)
        mch_memmove (retval, list, (size_t) len);
    return retval;
}

static void syn_cmd_match (exarg_T *eap, int syncing) {
    char_u *arg = eap->arg;
    char_u *group_name_end;
    char_u *rest;
    synpat_T item;
    int syn_id;
    int idx;
    syn_opt_arg_T syn_opt_arg;
    int sync_idx = 0;
    int conceal_char = NUL;
    rest = get_group_name (arg, &group_name_end);
    syn_opt_arg.flags = 0;
    syn_opt_arg.keyword = FALSE;
    syn_opt_arg.sync_idx = syncing ? &sync_idx : NULL;
    syn_opt_arg.has_cont_list = TRUE;
    syn_opt_arg.cont_list = NULL;
    syn_opt_arg.cont_in_list = NULL;
    syn_opt_arg.next_list = NULL;
    rest = get_syn_options (rest, &syn_opt_arg, &conceal_char, eap->skip);
    init_syn_patterns ();
    vim_memset (& item, 0, sizeof (item));
    rest = get_syn_pattern (rest, &item);
    if (vim_regcomp_had_eol () && !(syn_opt_arg.flags & HL_EXCLUDENL))
        syn_opt_arg.flags |= HL_HAS_EOL;
    rest = get_syn_options (rest, &syn_opt_arg, &conceal_char, eap->skip);
    if (rest != NULL) {
        eap->nextcmd = check_nextcmd (rest);
        if (!ends_excmd (*rest) || eap->skip)
            rest = NULL;
        else if (ga_grow (&curwin->w_s->b_syn_patterns, 1) != FAIL && (syn_id = syn_check_group (arg, (int) (group_name_end - arg))) != 0) {
            syn_incl_toplevel (syn_id, & syn_opt_arg.flags);
            idx = curwin->w_s->b_syn_patterns.ga_len;
            SYN_ITEMS (curwin->w_s)[idx] = item;
            SYN_ITEMS (curwin->w_s)[idx].sp_syncing = syncing;
            SYN_ITEMS (curwin->w_s)[idx].sp_type = SPTYPE_MATCH;
            SYN_ITEMS (curwin->w_s)[idx].sp_syn.id = syn_id;
            SYN_ITEMS (curwin->w_s)[idx].sp_syn.inc_tag = current_syn_inc_tag;
            SYN_ITEMS (curwin->w_s)[idx].sp_flags = syn_opt_arg.flags;
            SYN_ITEMS (curwin->w_s)[idx].sp_sync_idx = sync_idx;
            SYN_ITEMS (curwin->w_s)[idx].sp_cont_list = syn_opt_arg.cont_list;
            SYN_ITEMS (curwin->w_s)[idx].sp_syn.cont_in_list = syn_opt_arg.cont_in_list;
            SYN_ITEMS (curwin->w_s)[idx].sp_cchar = conceal_char;
            if (syn_opt_arg.cont_in_list != NULL)
                curwin->w_s->b_syn_containedin = TRUE;
            SYN_ITEMS (curwin->w_s)[idx].sp_next_list = syn_opt_arg.next_list;
            ++curwin->w_s->b_syn_patterns.ga_len;
            if (syn_opt_arg.flags & (HL_SYNC_HERE | HL_SYNC_THERE))
                curwin->w_s->b_syn_sync_flags |= SF_MATCH;
            if (syn_opt_arg.flags & HL_FOLD)
                ++curwin->w_s->b_syn_folditems;
            redraw_curbuf_later (SOME_VALID);
            syn_stack_free_all (curwin -> w_s);
            return;
        }
    }
    vim_regfree (item.sp_prog);
    vim_free (item.sp_pattern);
    vim_free (syn_opt_arg.cont_list);
    vim_free (syn_opt_arg.cont_in_list);
    vim_free (syn_opt_arg.next_list);
    if (rest == NULL)
        EMSG2 (_ (e_invarg2), arg);
}

static void init_syn_patterns (void) {
    curwin->w_s->b_syn_patterns.ga_itemsize = sizeof (synpat_T);
    curwin->w_s->b_syn_patterns.ga_growsize = 10;
}

static char_u *get_syn_pattern (char_u *arg, synpat_T *ci) {
    char_u *end;
    int *p;
    int idx;
    char_u *cpo_save;
    if (arg == NULL || arg[0] == NUL || arg[1] == NUL || arg[2] == NUL)
        return NULL;
    end = skip_regexp (arg +1, *arg, TRUE, NULL);
    if (*end != *arg) {
        EMSG2 (_ ("E401: Pattern delimiter not found: %s"), arg);
        return NULL;
    }
    if ((ci->sp_pattern = vim_strnsave (arg +1, (int) (end - arg - 1))) == NULL)
        return NULL;
    cpo_save = p_cpo;
    p_cpo = (char_u *) "";
    ci->sp_prog = vim_regcomp (ci->sp_pattern, RE_MAGIC);
    p_cpo = cpo_save;
    if (ci->sp_prog == NULL)
        return NULL;
    ci->sp_ic = curwin->w_s->b_syn_ic;
    syn_clear_time (& ci -> sp_time);
    ++end;
    do {
        for (idx = SPO_COUNT; --idx >= 0;)
            if (STRNCMP (end, spo_name_tab[idx], 3) == 0)
                break;
        if (idx >= 0) {
            p = &(ci->sp_offsets[idx]);
            if (idx != SPO_LC_OFF)
                switch (end[3]) {
                case 's' :
                    break;
                case 'b' :
                    break;
                case 'e' :
                    idx += SPO_COUNT;
                    break;
                default :
                    idx = -1;
                    break;
                }
            if (idx >= 0) {
                ci->sp_off_flags |= (1 << idx);
                if (idx == SPO_LC_OFF) {
                    end += 3;
                    *p = getdigits (&end);
                    if (!(ci->sp_off_flags & (1 << SPO_MS_OFF))) {
                        ci->sp_off_flags |= (1 << SPO_MS_OFF);
                        ci->sp_offsets[SPO_MS_OFF] = *p;
                    }
                }
                else {
                    end += 4;
                    if (*end == '+') {
                        ++end;
                        *p = getdigits (&end);
                    }
                    else if (*end == '-') {
                        ++end;
                        *p = -getdigits (&end);
                    }
                }
                if (*end != ',')
                    break;
                ++end;
            }
        }
    }
    while (idx >= 0);
    if (!ends_excmd (*end) && !VIM_ISWHITE (*end)) {
        EMSG2 (_ ("E402: Garbage after pattern: %s"), arg);
        return NULL;
    }
    return skipwhite (end);
}

static void syn_clear_time (syn_time_T *st) {
    profile_zero (& st -> total);
    profile_zero (& st -> slowest);
    st->count = 0;
    st->match = 0;
}

static void syn_cmd_region (exarg_T *eap, int syncing) {
    char_u *arg = eap->arg;
    char_u *group_name_end;
    char_u *rest;
    char_u *key_end;
    char_u *key = NULL;
    char_u *p;
    int item;

    #define ITEM_START	    0

    #define ITEM_SKIP	    1

    #define ITEM_END	    2

    #define ITEM_MATCHGROUP	    3
    struct pat_ptr {
        synpat_T *pp_synp;
        int pp_matchgroup_id;
        struct pat_ptr *pp_next;
    } * (pat_ptrs [3]);
    struct pat_ptr *ppp;
    struct pat_ptr *ppp_next;
    int pat_count = 0;
    int syn_id;
    int matchgroup_id = 0;
    int not_enough = FALSE;
    int illegal = FALSE;
    int success = FALSE;
    int idx;
    syn_opt_arg_T syn_opt_arg;
    int conceal_char = NUL;
    rest = get_group_name (arg, &group_name_end);
    pat_ptrs[0] = NULL;
    pat_ptrs[1] = NULL;
    pat_ptrs[2] = NULL;
    init_syn_patterns ();
    syn_opt_arg.flags = 0;
    syn_opt_arg.keyword = FALSE;
    syn_opt_arg.sync_idx = NULL;
    syn_opt_arg.has_cont_list = TRUE;
    syn_opt_arg.cont_list = NULL;
    syn_opt_arg.cont_in_list = NULL;
    syn_opt_arg.next_list = NULL;
    while (rest != NULL && !ends_excmd (*rest)) {
        rest = get_syn_options (rest, &syn_opt_arg, &conceal_char, eap->skip);
        if (rest == NULL || ends_excmd (*rest))
            break;
        key_end = rest;
        while (*key_end && !VIM_ISWHITE (*key_end) && *key_end != '=')
            ++key_end;
        vim_free (key);
        key = vim_strnsave_up (rest, (int) (key_end - rest));
        if (key == NULL) {
            rest = NULL;
            break;
        }
        if (STRCMP (key, "MATCHGROUP") == 0)
            item = ITEM_MATCHGROUP;
        else if (STRCMP (key, "START") == 0)
            item = ITEM_START;
        else if (STRCMP (key, "END") == 0)
            item = ITEM_END;
        else if (STRCMP (key, "SKIP") == 0) {
            if (pat_ptrs[ITEM_SKIP] != NULL) {
                illegal = TRUE;
                break;
            }
            item = ITEM_SKIP;
        }
        else
            break;
        rest = skipwhite (key_end);
        if (*rest != '=') {
            rest = NULL;
            EMSG2 (_ ("E398: Missing '=': %s"), arg);
            break;
        }
        rest = skipwhite (rest +1);
        if (*rest == NUL) {
            not_enough = TRUE;
            break;
        }
        if (item == ITEM_MATCHGROUP) {
            p = skiptowhite (rest);
            if ((p - rest == 4 && STRNCMP (rest, "NONE", 4) == 0) || eap->skip)
                matchgroup_id = 0;
            else {
                matchgroup_id = syn_check_group (rest, (int) (p - rest));
                if (matchgroup_id == 0) {
                    illegal = TRUE;
                    break;
                }
            }
            rest = skipwhite (p);
        }
        else {
            ppp = (struct pat_ptr *) alloc ((unsigned ) sizeof (struct pat_ptr));
            if (ppp == NULL) {
                rest = NULL;
                break;
            }
            ppp->pp_next = pat_ptrs[item];
            pat_ptrs[item] = ppp;
            ppp->pp_synp = (synpat_T *) alloc_clear ((unsigned ) sizeof (synpat_T));
            if (ppp->pp_synp == NULL) {
                rest = NULL;
                break;
            }
            if (item == ITEM_START)
                reg_do_extmatch = REX_SET;
            else if (item == ITEM_SKIP || item == ITEM_END)
                reg_do_extmatch = REX_USE;
            rest = get_syn_pattern (rest, ppp->pp_synp);
            reg_do_extmatch = 0;
            if (item == ITEM_END && vim_regcomp_had_eol () && !(syn_opt_arg.flags & HL_EXCLUDENL))
                ppp->pp_synp->sp_flags |= HL_HAS_EOL;
            ppp->pp_matchgroup_id = matchgroup_id;
            ++pat_count;
        }
    }
    vim_free (key);
    if (illegal || not_enough)
        rest = NULL;
    if (rest != NULL && (pat_ptrs[ITEM_START] == NULL || pat_ptrs[ITEM_END] == NULL)) {
        not_enough = TRUE;
        rest = NULL;
    }
    if (rest != NULL) {
        eap->nextcmd = check_nextcmd (rest);
        if (!ends_excmd (*rest) || eap->skip)
            rest = NULL;
        else if (ga_grow (&(curwin->w_s->b_syn_patterns), pat_count) != FAIL && (syn_id = syn_check_group (arg, (int) (group_name_end - arg))) != 0) {
            syn_incl_toplevel (syn_id, & syn_opt_arg.flags);
            idx = curwin->w_s->b_syn_patterns.ga_len;
            for (item = ITEM_START; item <= ITEM_END; ++item) {
                for (ppp = pat_ptrs[item]; ppp != NULL; ppp = ppp->pp_next) {
                    SYN_ITEMS (curwin->w_s)[idx] = *(ppp->pp_synp);
                    SYN_ITEMS (curwin->w_s)[idx].sp_syncing = syncing;
                    SYN_ITEMS (curwin->w_s)[idx].sp_type = (item == ITEM_START) ? SPTYPE_START : (item == ITEM_SKIP) ? SPTYPE_SKIP : SPTYPE_END;
                    SYN_ITEMS (curwin->w_s)[idx].sp_flags |= syn_opt_arg.flags;
                    SYN_ITEMS (curwin->w_s)[idx].sp_syn.id = syn_id;
                    SYN_ITEMS (curwin->w_s)[idx].sp_syn.inc_tag = current_syn_inc_tag;
                    SYN_ITEMS (curwin->w_s)[idx].sp_syn_match_id = ppp->pp_matchgroup_id;
                    SYN_ITEMS (curwin->w_s)[idx].sp_cchar = conceal_char;
                    if (item == ITEM_START) {
                        SYN_ITEMS (curwin->w_s)[idx].sp_cont_list = syn_opt_arg.cont_list;
                        SYN_ITEMS (curwin->w_s)[idx].sp_syn.cont_in_list = syn_opt_arg.cont_in_list;
                        if (syn_opt_arg.cont_in_list != NULL)
                            curwin->w_s->b_syn_containedin = TRUE;
                        SYN_ITEMS (curwin->w_s)[idx].sp_next_list = syn_opt_arg.next_list;
                    }
                    ++curwin->w_s->b_syn_patterns.ga_len;
                    ++idx;
                    if (syn_opt_arg.flags & HL_FOLD)
                        ++curwin->w_s->b_syn_folditems;
                }
            }
            redraw_curbuf_later (SOME_VALID);
            syn_stack_free_all (curwin -> w_s);
            success = TRUE;
        }
    }
    for (item = ITEM_START; item <= ITEM_END; ++item)
        for (ppp = pat_ptrs[item]; ppp != NULL; ppp = ppp_next) {
            if (!success) {
                vim_regfree (ppp -> pp_synp -> sp_prog);
                vim_free (ppp -> pp_synp -> sp_pattern);
            }
            vim_free (ppp -> pp_synp);
            ppp_next = ppp->pp_next;
            vim_free (ppp);
        }
    if (!success) {
        vim_free (syn_opt_arg.cont_list);
        vim_free (syn_opt_arg.cont_in_list);
        vim_free (syn_opt_arg.next_list);
        if (not_enough)
            EMSG2 (_ ("E399: Not enough arguments: syntax region %s"), arg);
        else if (illegal || rest == NULL)
            EMSG2 (_ (e_invarg2), arg);
    }
}

static void syn_cmd_cluster (exarg_T *eap, int syncing) {
    char_u *arg = eap->arg;
    char_u *group_name_end;
    char_u *rest;
    int scl_id;
    short  *clstr_list;
    int got_clstr = FALSE;
    int opt_len;
    int list_op;
    eap->nextcmd = find_nextcmd (arg);
    if (eap->skip)
        return;
    rest = get_group_name (arg, &group_name_end);
    if (rest != NULL) {
        scl_id = syn_check_cluster (arg, (int) (group_name_end - arg));
        if (scl_id == 0)
            return;
        scl_id -= SYNID_CLUSTER;
        for (;;) {
            if (STRNICMP (rest, "add", 3) == 0 && (VIM_ISWHITE (rest[3]) || rest[3] == '=')) {
                opt_len = 3;
                list_op = CLUSTER_ADD;
            }
            else if (STRNICMP (rest, "remove", 6) == 0 && (VIM_ISWHITE (rest[6]) || rest[6] == '=')) {
                opt_len = 6;
                list_op = CLUSTER_SUBTRACT;
            }
            else if (STRNICMP (rest, "contains", 8) == 0 && (VIM_ISWHITE (rest[8]) || rest[8] == '=')) {
                opt_len = 8;
                list_op = CLUSTER_REPLACE;
            }
            else
                break;
            clstr_list = NULL;
            if (get_id_list (&rest, opt_len, &clstr_list, eap->skip) == FAIL) {
                EMSG2 (_ (e_invarg2), rest);
                break;
            }
            if (scl_id >= 0)
                syn_combine_list (&SYN_CLSTR (curwin->w_s)[scl_id].scl_list, &clstr_list, list_op);
            else
                vim_free (clstr_list);
            got_clstr = TRUE;
        }
        if (got_clstr) {
            redraw_curbuf_later (SOME_VALID);
            syn_stack_free_all (curwin -> w_s);
        }
    }
    if (!got_clstr)
        EMSG (_ ("E400: No cluster specified"));
    if (rest == NULL || !ends_excmd (*rest))
        EMSG2 (_ (e_invarg2), arg);
}

static void syn_cmd_sync (exarg_T *eap, int syncing) {
    char_u *arg_start = eap->arg;
    char_u *arg_end;
    char_u *key = NULL;
    char_u *next_arg;
    int illegal = FALSE;
    int finished = FALSE;
    long  n;
    char_u *cpo_save;
    if (ends_excmd (*arg_start)) {
        syn_cmd_list (eap, TRUE);
        return;
    }
    while (!ends_excmd (*arg_start)) {
        arg_end = skiptowhite (arg_start);
        next_arg = skipwhite (arg_end);
        vim_free (key);
        key = vim_strnsave_up (arg_start, (int) (arg_end - arg_start));
        if (STRCMP (key, "CCOMMENT") == 0) {
            if (!eap->skip)
                curwin->w_s->b_syn_sync_flags |= SF_CCOMMENT;
            if (!ends_excmd (*next_arg)) {
                arg_end = skiptowhite (next_arg);
                if (!eap->skip)
                    curwin->w_s->b_syn_sync_id = syn_check_group (next_arg, (int) (arg_end - next_arg));
                next_arg = skipwhite (arg_end);
            }
            else if (!eap->skip)
                curwin->w_s->b_syn_sync_id = syn_name2id ((char_u *) "Comment");
        }
        else if (STRNCMP (key, "LINES", 5) == 0 || STRNCMP (key, "MINLINES", 8) == 0 || STRNCMP (key, "MAXLINES", 8) == 0 || STRNCMP (key, "LINEBREAKS", 10) == 0) {
            if (key[4] == 'S')
                arg_end = key + 6;
            else if (key[0] == 'L')
                arg_end = key + 11;
            else
                arg_end = key + 9;
            if (arg_end[-1] != '=' || !VIM_ISDIGIT (*arg_end)) {
                illegal = TRUE;
                break;
            }
            n = getdigits (&arg_end);
            if (!eap->skip) {
                if (key[4] == 'B')
                    curwin->w_s->b_syn_sync_linebreaks = n;
                else if (key[1] == 'A')
                    curwin->w_s->b_syn_sync_maxlines = n;
                else
                    curwin->w_s->b_syn_sync_minlines = n;
            }
        }
        else if (STRCMP (key, "FROMSTART") == 0) {
            if (!eap->skip) {
                curwin->w_s->b_syn_sync_minlines = MAXLNUM;
                curwin->w_s->b_syn_sync_maxlines = 0;
            }
        }
        else if (STRCMP (key, "LINECONT") == 0) {
            if (*next_arg == NUL) {
                illegal = TRUE;
                break;
            }
            if (curwin->w_s->b_syn_linecont_pat != NULL) {
                EMSG (_ ("E403: syntax sync: line continuations pattern specified twice"));
                finished = TRUE;
                break;
            }
            arg_end = skip_regexp (next_arg +1, *next_arg, TRUE, NULL);
            if (*arg_end != *next_arg) {
                illegal = TRUE;
                break;
            }
            if (!eap->skip) {
                if ((curwin->w_s->b_syn_linecont_pat = vim_strnsave (next_arg +1, (int) (arg_end - next_arg - 1))) == NULL) {
                    finished = TRUE;
                    break;
                }
                curwin->w_s->b_syn_linecont_ic = curwin->w_s->b_syn_ic;
                cpo_save = p_cpo;
                p_cpo = (char_u *) "";
                curwin->w_s->b_syn_linecont_prog = vim_regcomp (curwin->w_s->b_syn_linecont_pat, RE_MAGIC);
                p_cpo = cpo_save;
                syn_clear_time (& curwin -> w_s -> b_syn_linecont_time);
                if (curwin->w_s->b_syn_linecont_prog == NULL) {
                    VIM_CLEAR (curwin -> w_s -> b_syn_linecont_pat);
                    finished = TRUE;
                    break;
                }
            }
            next_arg = skipwhite (arg_end +1);
        }
        else {
            eap->arg = next_arg;
            if (STRCMP (key, "MATCH") == 0)
                syn_cmd_match (eap, TRUE);
            else if (STRCMP (key, "REGION") == 0)
                syn_cmd_region (eap, TRUE);
            else if (STRCMP (key, "CLEAR") == 0)
                syn_cmd_clear (eap, TRUE);
            else
                illegal = TRUE;
            finished = TRUE;
            break;
        }
        arg_start = next_arg;
    }
    vim_free (key);
    if (illegal)
        EMSG2 (_ ("E404: Illegal arguments: %s"), arg_start);
    else if (!finished) {
        eap->nextcmd = check_nextcmd (arg_start);
        redraw_curbuf_later (SOME_VALID);
        syn_stack_free_all (curwin -> w_s);
    }
}

char_u *syn_id2name (int id) {
    if (id <= 0 || id > highlight_ga.ga_len)
        return (char_u *) "";
    return HL_TABLE ()[id - 1].sg_name;
}

int highlight_exists (char_u *name) {
    return (syn_name2id (name) > 0);
}

char_u *highlight_color (int id, char_u *what, int modec) {
    static char_u name [20];
    int n;
    int fg = FALSE;
    int sp = FALSE;
    int font = FALSE;
    if (id <= 0 || id > highlight_ga.ga_len)
        return NULL;
    if (TOLOWER_ASC (what[0]) == 'f' && TOLOWER_ASC (what[1]) == 'g')
        fg = TRUE;
    else if (TOLOWER_ASC (what[0]) == 'f' && TOLOWER_ASC (what[1]) == 'o' && TOLOWER_ASC (what[2]) == 'n' && TOLOWER_ASC (what[3]) == 't')
        font = TRUE;
    else if (TOLOWER_ASC (what[0]) == 's' && TOLOWER_ASC (what[1]) == 'p')
        sp = TRUE;
    else if (!(TOLOWER_ASC (what[0]) == 'b' && TOLOWER_ASC (what[1]) == 'g'))
        return NULL;
    if (modec == 'g') {
        if (font)
            return HL_TABLE ()[id - 1].sg_font_name;
        if ((USE_24BIT) &&what[2] == '#') {
            guicolor_T color;
            long_u rgb;
            static char_u buf [10];
            if (fg)
                color = HL_TABLE ()[id - 1].sg_gui_fg;
            else if (sp)
                color = HL_TABLE ()[id - 1].sg_gui_sp;
            else
                color = HL_TABLE ()[id - 1].sg_gui_bg;
            if (color == INVALCOLOR)
                return NULL;
            rgb = (long_u) GUI_MCH_GET_RGB (color);
            sprintf ((char *) buf, "#%02x%02x%02x", (unsigned) (rgb >> 16), (unsigned) (rgb >> 8) & 255, (unsigned) rgb & 255);
            return buf;
        }
        if (fg)
            return (HL_TABLE ()[id - 1].sg_gui_fg_name);
        if (sp)
            return (HL_TABLE ()[id - 1].sg_gui_sp_name);
        return (HL_TABLE ()[id - 1].sg_gui_bg_name);
    }
    if (font || sp)
        return NULL;
    if (modec == 'c') {
        if (fg)
            n = HL_TABLE ()[id - 1].sg_cterm_fg - 1;
        else
            n = HL_TABLE ()[id - 1].sg_cterm_bg - 1;
        if (n < 0)
            return NULL;
        sprintf ((char *) name, "%d", n);
        return name;
    }
    return NULL;
}

char_u *highlight_has_attr (int id, int flag, int modec) {
    int attr;
    if (id <= 0 || id > highlight_ga.ga_len)
        return NULL;
    if (modec == 'g')
        attr = HL_TABLE ()[id - 1].sg_gui;
    else if (modec == 'c')
        attr = HL_TABLE ()[id - 1].sg_cterm;
    else
        attr = HL_TABLE ()[id - 1].sg_term;
    if (attr & flag)
        return (char_u *) "1";
    return NULL;
}

int syn_get_stack_item (int i) {
    if (i >= current_state.ga_len) {
        invalidate_current_state ();
        current_col = MAXCOL;
        return -1;
    }
    return CUR_STATE (i).si_id;
}

