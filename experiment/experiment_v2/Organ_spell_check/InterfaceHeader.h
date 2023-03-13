
#include <sys/types.h>

#include <signal.h>

#include <limits.h>

#include <stdio.h>

#include <stdlib.h>

#include <sys/un.h>

#include <sys/socket.h>

#include <sys/param.h>

#include <unistd.h>

#include <string.h>

#include <stdarg.h>

#include <string.h>	/* for strncmp() */

#include <ctype.h>	/* for isalnum() */

#include <errno.h>

#include <time.h>

#include <dirent.h>

#include <assert.h>

#include <stddef.h>

#include <ctype.h>

#include <sys/stat.h>

#include <fcntl.h>

#define RESCORE(word_score, sound_score) ((3 * word_score + sound_score) / 4)

#define MAXSCORE(word_score, sound_score) ((4 * word_score - sound_score) / 3)

#define IN_SPELL_C

#define WF_MIXCAP   0x20	/* mix of upper and lower case: macaRONI */

#define WF_CAPMASK (WF_ONECAP | WF_ALLCAP | WF_KEEPCAP | WF_FIXCAP)

#define REGION_ALL 0xff		/* word valid in all regions */

#define VIMSUGMAGIC "VIMsug"	/* string at start of Vim .sug file */

#define VIMSUGMAGICL 6

#define VIMSUGVERSION 1

#define SP_BANNED	-1

#define SP_OK		0

#define SP_RARE		1

#define SP_LOCAL	2

#define SP_BAD		3

#define WC_KEY_OFF  offsetof(wordcount_T, wc_word)

#define HI2WC(hi)     ((wordcount_T *)((hi)->hi_key - WC_KEY_OFF))

#define MAXWORDCOUNT 0xffff

#define SUG(ga, i) (((suggest_T *)(ga).ga_data)[i])

#define WAS_BANNED(su, word) (!HASHITEM_EMPTY(hash_find(&su->su_banned, word)))

#define SUG_CLEAN_COUNT(su)    ((su)->su_maxcount < 130 ? 150 : (su)->su_maxcount + 20)

#define SUG_MAX_COUNT(su)	(SUG_CLEAN_COUNT(su) + 50)

#define SCORE_SPLIT	149	/* split bad word */

#define SCORE_SPLIT_NO	249	/* split bad word with NOSPLITSUGS */

#define SCORE_ICASE	52	/* slightly different case */

#define SCORE_REGION	200	/* word is for different region */

#define SCORE_RARE	180	/* rare word */

#define SCORE_SWAP	75	/* swap two characters */

#define SCORE_SWAP3	110	/* swap two characters in three */

#define SCORE_REP	65	/* REP replacement */

#define SCORE_SUBST	93	/* substitute a character */

#define SCORE_SIMILAR	33	/* substitute a similar character */

#define SCORE_SUBCOMP	33	/* substitute a composing character */

#define SCORE_DEL	94	/* delete a character */

#define SCORE_DELDUP	66	/* delete a duplicated character */

#define SCORE_DELCOMP	28	/* delete a composing character */

#define SCORE_INS	96	/* insert a character */

#define SCORE_INSDUP	67	/* insert a duplicate character */

#define SCORE_INSCOMP	30	/* insert a composing character */

#define SCORE_NONWORD	103	/* change non-word to word char */

#define SCORE_FILE	30	/* suggestion from a file */

#define SCORE_MAXINIT	350	/* Initial maximum score: higher == slower.
				 * 350 allows for about three changes. */

#define SCORE_COMMON1	30	/* subtracted for words seen before */

#define SCORE_COMMON2	40	/* subtracted for words often seen */

#define SCORE_COMMON3	50	/* subtracted for words very often seen */

#define SCORE_THRES2	10	/* word count threshold for COMMON2 */

#define SCORE_THRES3	100	/* word count threshold for COMMON3 */

#define SCORE_SFMAX1	200	/* maximum score for first try */

#define SCORE_SFMAX2	300	/* maximum score for second try */

#define SCORE_SFMAX3	400	/* maximum score for third try */

#define SCORE_BIG	SCORE_INS * 3	/* big difference */

#define SCORE_MAXMAX	999999		/* accept any score */

#define SCORE_LIMITMAX	350		/* for spell_edit_score_limit() */

#define SCORE_EDIT_MIN	SCORE_SIMILAR

#define DIFF_NONE	0	/* no different byte (yet) */

#define DIFF_YES	1	/* different byte found */

#define DIFF_INSERT	2	/* inserting character */

#define TSF_PREFIXOK	1	/* already checked that prefix is OK */

#define TSF_DIDSPLIT	2	/* tried split at this point */

#define TSF_DIDDEL	4	/* did a delete, "ts_delidx" has index */

#define PFD_NOPREFIX	0xff	/* not using prefixes */

#define PFD_PREFIXTREE	0xfe	/* walking through the prefix tree */

#define PFD_NOTSPECIAL	0xfd	/* highest value that's not special */

#define FIND_FOLDWORD	    0	/* find word case-folded */

#define FIND_KEEPWORD	    1	/* find keep-case word */

#define FIND_PREFIX	    2	/* find word after prefix */

#define FIND_COMPOUND	    3	/* find case-folded compound word */

#define FIND_KEEPCOMPOUND   4	/* find keep-case compound word */

#define HIKEY2SFT(p)  ((sftword_T *)(p - (dumsft.sft_word - (char_u *)&dumsft)))

#define HI2SFT(hi)     HIKEY2SFT((hi)->hi_key)

#define MOD_KEYS_ENTRY_SIZE 5

#define KEY_NAMES_TABLE_LEN (sizeof(key_names_table) / sizeof(struct key_name_entry))

#define FF_MAX_STAR_STAR_EXPAND ((char_u)30)

#define SET_CHARTAB(buf, c) (buf)->b_chartab[(unsigned)(c) >> 3] |= (1 << ((c) & 0x7))

#define RESET_CHARTAB(buf, c) (buf)->b_chartab[(unsigned)(c) >> 3] &= ~(1 << ((c) & 0x7))

#define GET_CHARTAB(buf, c) ((buf)->b_chartab[(unsigned)(c) >> 3] & (1 << ((c) & 0x7)))

#define CT_CELL_MASK	0x07	/* mask: nr of display cells (1, 2 or 4) */

#define CT_PRINT_CHAR	0x10	/* flag: set for printable chars */

#define CT_ID_CHAR	0x20	/* flag: set for ID chars */

#define CT_FNAME_CHAR	0x40	/* flag: set for file name chars */

#define END		0	/*	End of program or NOMATCH operand. */

#define BOL		1	/*	Match "" at beginning of line. */

#define EOL		2	/*	Match "" at end of line. */

#define BRANCH		3	/* node Match this alternative, or the
				 *	next... */

#define BACK		4	/*	Match "", "next" ptr points backward. */

#define EXACTLY		5	/* str	Match this string. */

#define NOTHING		6	/*	Match empty string. */

#define STAR		7	/* node Match this (simple) thing 0 or more
				 *	times. */

#define PLUS		8	/* node Match this (simple) thing 1 or more
				 *	times. */

#define MATCH		9	/* node match the operand zero-width */

#define NOMATCH		10	/* node check for no match with operand */

#define BEHIND		11	/* node look behind for a match with operand */

#define NOBEHIND	12	/* node look behind for no match with operand */

#define SUBPAT		13	/* node match the operand here */

#define BRACE_SIMPLE	14	/* node Match this (simple) thing between m and
				 *	n times (\{m,n\}). */

#define BOW		15	/*	Match "" after [^a-zA-Z0-9_] */

#define EOW		16	/*	Match "" at    [^a-zA-Z0-9_] */

#define BRACE_LIMITS	17	/* nr nr  define the min & max for BRACE_SIMPLE
				 *	and BRACE_COMPLEX. */

#define NEWL		18	/*	Match line-break */

#define BHPOS		19	/*	End position for BEHIND or NOBEHIND */

#define ADD_NL		30

#define FIRST_NL	ANY + ADD_NL

#define ANY		20	/*	Match any one character. */

#define ANYOF		21	/* str	Match any character in this string. */

#define ANYBUT		22	/* str	Match any character not in this
				 *	string. */

#define IDENT		23	/*	Match identifier char */

#define SIDENT		24	/*	Match identifier char but no digit */

#define KWORD		25	/*	Match keyword char */

#define SKWORD		26	/*	Match word char but no digit */

#define FNAME		27	/*	Match file name char */

#define SFNAME		28	/*	Match file name char but no digit */

#define PRINT		29	/*	Match printable char */

#define SPRINT		30	/*	Match printable char but no digit */

#define WHITE		31	/*	Match whitespace char */

#define NWHITE		32	/*	Match non-whitespace char */

#define DIGIT		33	/*	Match digit char */

#define NDIGIT		34	/*	Match non-digit char */

#define HEX		35	/*	Match hex char */

#define NHEX		36	/*	Match non-hex char */

#define OCTAL		37	/*	Match octal char */

#define NOCTAL		38	/*	Match non-octal char */

#define WORD		39	/*	Match word char */

#define NWORD		40	/*	Match non-word char */

#define HEAD		41	/*	Match head char */

#define NHEAD		42	/*	Match non-head char */

#define ALPHA		43	/*	Match alpha char */

#define NALPHA		44	/*	Match non-alpha char */

#define LOWER		45	/*	Match lowercase char */

#define NLOWER		46	/*	Match non-lowercase char */

#define UPPER		47	/*	Match uppercase char */

#define NUPPER		48	/*	Match non-uppercase char */

#define LAST_NL		NUPPER + ADD_NL

#define WITH_NL(op)	((op) >= FIRST_NL && (op) <= LAST_NL)

#define MOPEN		80  /* -89	 Mark this point in input as start of
				 *	 \( subexpr.  MOPEN + 0 marks start of
				 *	 match. */

#define MCLOSE		90  /* -99	 Analogous to MOPEN.  MCLOSE + 0 marks
				 *	 end of match. */

#define BACKREF		100 /* -109 node Match same string again \1-\9 */

#define BRACE_COMPLEX	140 /* -149 node Match nodes between m & n times */

#define NOPEN		150	/*	Mark this point in input as start of
					\%( subexpr. */

#define NCLOSE		151	/*	Analogous to NOPEN. */

#define MULTIBYTECODE	200	/* mbc	Match one multi-byte character */

#define RE_BOF		201	/*	Match "" at beginning of file. */

#define RE_EOF		202	/*	Match "" at end of file. */

#define CURSOR		203	/*	Match location of cursor. */

#define RE_LNUM		204	/* nr cmp  Match line number */

#define RE_COL		205	/* nr cmp  Match column number */

#define RE_VCOL		206	/* nr cmp  Match virtual column number */

#define RE_MARK		207	/* mark cmp  Match mark position */

#define RE_VISUAL	208	/*	Match Visual area */

#define RE_COMPOSING	209	/* any composing characters */

#define Magic(x)	((int)(x) - 256)

#define un_Magic(x)	((x) + 256)

#define is_Magic(x)	((x) < 0)

#define NOT_MULTI	0

#define MULTI_ONE	1

#define MULTI_MULT	2

#define	    RI_DIGIT	0x01

#define	    RI_HEX	0x02

#define	    RI_OCTAL	0x04

#define	    RI_WORD	0x08

#define	    RI_HEAD	0x10

#define	    RI_ALPHA	0x20

#define	    RI_LOWER	0x40

#define	    RI_UPPER	0x80

#define	    RI_WHITE	0x100

#define MAGIC_NONE	1	/* "\V" very unmagic */

#define MAGIC_OFF	2	/* "\M" or 'magic' off */

#define MAGIC_ON	3	/* "\m" or 'magic' */

#define MAGIC_ALL	4	/* "\v" very magic */

#define REG_NOPAREN	0	/* toplevel reg() */

#define REG_PAREN	1	/* \(\) */

#define REG_ZPAREN	2	/* \z(\) */

#define REG_NPAREN	3	/* \%(\) */

#define save_se(savep, posp, pp) \
    REG_MULTI ? save_se_multi((savep), (posp)) : save_se_one((savep), (pp))

#define restore_se(savep, posp, pp) { \
    if (REG_MULTI) \
	*(posp) = (savep)->se_u.pos; \
    else \
	*(pp) = (savep)->se_u.ptr; }

#define REGSTACK_INITIAL	2048

#define BACKPOS_INITIAL		64

#define REG_MULTI	(rex.reg_match == NULL)

#define USE_CARBONIZED

#define USE_AEVENT		/* Enable AEVENT */

#define VIMSCRAPFLAVOR 'VIM!'

#define NR_ELEMS(x)	(sizeof(x) / sizeof(x[0]))

#define kNothing 0

#define kCreateEmpty 2 /*1*/

#define kCreateRect 2

#define kDestroy 3

#define topLeft(r)	(((Point*)&(r))[0])

#define botRight(r)	(((Point*)&(r))[1])

#define RGB(r,g,b)	((r) << 16) + ((g) << 8) + (b)

#define Red(c)		((c & 0x00FF0000) >> 16)

#define Green(c)	((c & 0x0000FF00) >>  8)

#define Blue(c)		((c & 0x000000FF) >>  0)

#define vk_Esc		0x35	/* -> 1B */

#define vk_F1		0x7A	/* -> 10 */

#define vk_F2		0x78  /*0x63*/

#define vk_F3		0x63  /*0x76*/

#define vk_F4		0x76  /*0x60*/

#define vk_F5		0x60  /*0x61*/

#define vk_F6		0x61  /*0x62*/

#define vk_F7		0x62  /*0x63*/  /*?*/

#define vk_F8		0x64

#define vk_F9		0x65

#define vk_F10		0x6D

#define vk_F11		0x67

#define vk_F12		0x6F

#define vk_F13		0x69

#define vk_F14		0x6B

#define vk_F15		0x71

#define vk_Clr		0x47	/* -> 1B (ESC) */

#define vk_Enter	0x4C	/* -> 03 */

#define vk_Space	0x31	/* -> 20 */

#define vk_Tab		0x30	/* -> 09 */

#define vk_Return	0x24	/* -> 0D */

#define vk_Delete	0X08	/* -> 08 BackSpace */

#define vk_Help		0x72	/* -> 05 */

#define vk_Home		0x73	/* -> 01 */

#define	vk_PageUp	0x74	/* -> 0D */

#define vk_FwdDelete	0x75	/* -> 7F */

#define	vk_End		0x77	/* -> 04 */

#define vk_PageDown	0x79	/* -> 0C */

#define vk_Up		0x7E	/* -> 1E */

#define vk_Down		0x7D	/* -> 1F */

#define	vk_Left		0x7B	/* -> 1C */

#define vk_Right	0x7C	/* -> 1D */

#define vk_Undo		vk_F1

#define vk_Cut		vk_F2

#define	vk_Copy		vk_F3

#define	vk_Paste	vk_F4

#define vk_PrintScreen	vk_F13

#define vk_SCrollLock	vk_F14

#define	vk_Pause	vk_F15

#define	vk_NumLock	vk_Clr

#define vk_Insert	vk_Help

#define KeySym	char

#define MoveRectTo(r,x,y) OffsetRect(r,x-r->left,y-r->top)

#define tgetstr tgetstr_defined_wrong

#define BT_EXTRA_KEYS	0x101

#define PUM_DEF_HEIGHT 10

#define PUM_DEF_WIDTH  15

#define BALLOON_MIN_WIDTH 50

#define BALLOON_MIN_HEIGHT 10

#define FD_OPEN		0	/* fold is open (nested ones can be closed) */

#define FD_CLOSED	1	/* fold is closed */

#define FD_LEVEL	2	/* depends on 'foldlevel' (nested folds too) */

#define MAX_LEVEL	20	/* maximum fold depth */

#define DONE_NOTHING	0

#define DONE_ACTION	1	/* did close or open a fold */

#define DONE_FOLD	2	/* did find a fold */

#define CHECK(c, s)

#define DATA_ID	       (('d' << 8) + 'a')   /* data block id */

#define PTR_ID	       (('p' << 8) + 't')   /* pointer block id */

#define BLOCK0_ID0     'b'		    /* block 0 id 0 */

#define BLOCK0_ID1     '0'		    /* block 0 id 1 */

#define BLOCK0_ID1_C0  'c'		    /* block 0 id 1 'cm' 0 */

#define BLOCK0_ID1_C1  'C'		    /* block 0 id 1 'cm' 1 */

#define BLOCK0_ID1_C2  'd'		    /* block 0 id 1 'cm' 2 */

#define DB_MARKED	((unsigned)1 << ((sizeof(unsigned) * 8) - 1))

#define DB_INDEX_MASK	(~DB_MARKED)

#define INDEX_SIZE  (sizeof(unsigned))	    /* size of one db_index entry */

#define HEADER_SIZE (sizeof(DATA_BL) - INDEX_SIZE)  /* size of data block header */

#define B0_FNAME_SIZE_ORG	900	/* what it was in older versions */

#define B0_FNAME_SIZE_NOCRYPT	898	/* 2 bytes used for other things */

#define B0_FNAME_SIZE_CRYPT	890	/* 10 bytes used for other things */

#define B0_UNAME_SIZE		40

#define B0_HNAME_SIZE		40

#define B0_MAGIC_LONG	0x30313233L

#define B0_MAGIC_INT	0x20212223L

#define B0_MAGIC_SHORT	0x10111213L

#define B0_MAGIC_CHAR	0x55

#define B0_DIRTY	0x55

#define b0_dirty	b0_fname[B0_FNAME_SIZE_ORG - 1]

#define b0_flags	b0_fname[B0_FNAME_SIZE_ORG - 2]

#define b0_seed		b0_fname[B0_FNAME_SIZE_ORG - 2 - MF_SEED_LEN]

#define B0_FF_MASK	3

#define B0_SAME_DIR	4

#define B0_HAS_FENC	8

#define STACK_INCR	5	/* nr of entries added to ml_stack at a time */

#define ML_DELETE	0x11	    /* delete line */

#define ML_INSERT	0x12	    /* insert line */

#define ML_FIND		0x13	    /* just find the line */

#define ML_FLUSH	0x02	    /* flush locked block */

#define ML_SIMPLE(x)	(x & 0x10)  /* DEL, INS or FIND */

#define MEMFILE_PAGE_SIZE 4096		/* default page size */

#define TRUE (1)

#define FALSE (0)

#define MESSAGE_FILE		/* don't include prototype for smsg() */

#define USING_FLOAT_STUFF

#define BUFSIZE		8192	/* size of normal write buffer */

#define SMBUFSIZE	256	/* size of emergency write buffer */

#define USE_MCH_ACCESS

#define CONV_RESTLEN 30

#define ICONV_MULT 8

#define AUGROUP_NAME(i) (((char_u **)augroups.ga_data)[i])

#define DICT_MAXNEST 100	/* maximum nesting of lists and dicts */

#define NAMESPACE_CHAR	(char_u *)"abglstvw"

#define globvarht globvardict.dv_hashtab

#define SCRIPT_SV(id) (((scriptvar_T **)ga_scripts.ga_data)[(id) - 1])

#define SCRIPT_VARS(id) (SCRIPT_SV(id)->sv_dict.dv_hashtab)

#define VV_COMPAT	1	/* compatible, also used without "v:" */

#define VV_RO		2	/* read-only */

#define VV_RO_SBX	4	/* read-only in the sandbox */

#define VV_NAME(s, t)	s, {{t, 0, {0}}, 0, {0}}

#define vv_type		vv_di.di_tv.v_type

#define vv_nr		vv_di.di_tv.vval.v_number

#define vv_float	vv_di.di_tv.vval.v_float

#define vv_str		vv_di.di_tv.vval.v_string

#define vv_list		vv_di.di_tv.vval.v_list

#define vv_dict		vv_di.di_tv.vval.v_dict

#define vv_tv		vv_di.di_tv

#define vimvarht  vimvardict.dv_hashtab

#define EVALCMD_BUSY (redir_lval == (lval_T *)&redir_lval)

#define BACKSPACE_CHAR		    1

#define BACKSPACE_WORD		    2

#define BACKSPACE_WORD_NOT_SPACE    3

#define BACKSPACE_LINE		    4

#define PC_STATUS_UNSET	0	/* pc_bytes was not set */

#define PC_STATUS_RIGHT	1	/* right halve of double-wide char */

#define PC_STATUS_LEFT	2	/* left halve of double-wide char */

#define PC_STATUS_SET	3	/* pc_bytes was filled */

#define FC_ABORT    0x01	/* abort function on error */

#define FC_RANGE    0x02	/* function accepts range */

#define FC_DICT	    0x04	/* Dict function, uses "self" */

#define FC_CLOSURE  0x08	/* closure, uses outer scope variables */

#define FC_DELETED  0x10	/* :delfunction used while uf_refcount > 0 */

#define FC_REMOVED  0x20	/* function redefined while uf_refcount > 0 */

#define UF2HIKEY(fp) ((fp)->uf_name)

#define HIKEY2UF(p)  ((ufunc_T *)(p - offsetof(ufunc_T, uf_name)))

#define HI2UF(hi)     HIKEY2UF((hi)->hi_key)

#define FUNCARG(fp, j)	((char_u **)(fp->uf_args.ga_data))[j]

#define FUNCLINE(fp, j)	((char_u **)(fp->uf_lines.ga_data))[j]

#define PERTURB_SHIFT 5

#define SCRIPT_ITEM(id) (((scriptitem_T *)script_items.ga_data)[(id) - 1])

#define BREAKP(idx)		(((struct debuggy *)dbg_breakp.ga_data)[idx])

#define DEBUGGY(gap, idx)	(((struct debuggy *)gap->ga_data)[idx])

#define DBG_FUNC	1

#define DBG_FILE	2

#define DBG_EXPR	3

#define AL_SET	1

#define AL_ADD	2

#define AL_DEL	3

#define MB_FILLER_CHAR '<'  /* character used when a double-width character
			     * doesn't fit. */

#define URL_SLASH	1		/* path_is_url() has found "://" */

#define URL_BACKSLASH	2		/* path_is_url() has found ":\\" */

#define NOWIN		(win_T *)-1	/* non-existing window */

#define ROWS_AVAIL (Rows - p_ch - tabline_height())

#define DIFF_FILLER	1	/* display filler lines */

#define DIFF_ICASE	2	/* ignore case */

#define DIFF_IWHITE	4	/* ignore change in white space */

#define DIFF_HORIZONTAL	8	/* horizontal splits */

#define DIFF_VERTICAL	16	/* vertical splits */

#define DIFF_HIDDEN_OFF	32	/* diffoff when hidden */

#define LBUFLEN 50		/* length of line in diff file */

#define ICON_SMALL 0

#define ICON_BIG 1

#define NO_X11_INCLUDES

#define UC_BUFFER	1	/* -buffer: local to current buffer */

#define USER_CMD(i) (&((ucmd_T *)(ucmds.ga_data))[i])

#define USER_CMD_GA(gap, i) (&((ucmd_T *)((gap)->ga_data))[i])

#define DO_DECLARE_EXCMD

#define DLG_PADDING_X		10

#define DLG_PADDING_Y		10

#define DLG_OLD_STYLE_PADDING_X	5

#define DLG_OLD_STYLE_PADDING_Y	5

#define DLG_VERT_PADDING_X	4	/* For vertical buttons */

#define DLG_VERT_PADDING_Y	4

#define DLG_ICON_WIDTH		34

#define DLG_ICON_HEIGHT		34

#define DLG_MIN_WIDTH		150

#define DLG_FONT_NAME		"MS Sans Serif"

#define DLG_FONT_POINT_SIZE	8

#define DLG_MIN_MAX_WIDTH	400

#define DLG_MIN_MAX_HEIGHT	400

#define DLG_NONBUTTON_CONTROL	5000	/* First ID of non-button controls */

#define BLINK_OFF   1

#define BLINK_ON    2

#define USE_SYSMENU_FONT

#define VIM_NAME	"vim"

#define VIM_CLASS	"Vim"

#define VIM_CLASSW	L"Vim"

#define DLG_ALLOC_SIZE 16 * 1024

#define MENUDEPTH   10		/* maximum depth of menus */

#define MINIMAL_SIZE 20			/* minimal size for b_str */

#define MAP_HASH(mode, c1) (((mode) & (NORMAL + VISUAL + SELECTMODE + OP_PENDING + TERMINAL)) ? (c1) : ((c1) ^ 0x80))

#define RM_YES		0	/* tb_noremap: remap */

#define RM_NONE		1	/* tb_noremap: don't remap */

#define RM_SCRIPT	2	/* tb_noremap: remap local script mappings */

#define RM_ABBR		4	/* tb_noremap: don't remap, do abbrev. */

#define TYPELEN_INIT	(5 * (MAXMAPLEN + 3))

#define GUARDED		10000 /* typenr for "guarded" annotation */

#define GUARDEDOFFSET 1000000 /* base for "guarded" sign id's */

#define MAX_COLOR_LENGTH 32 /* max length of color name in defineAnnoType */

#define NETBEANS_OPEN (channel_can_write_to(nb_channel))

#define TMODE_ONCE 1	    /* CTRL-\ CTRL-N used */

#define TMODE_LOOP 2	    /* CTRL-W N used */

#define MAX_ROW 999999	    /* used for tl_dirty_row_end to update all rows */

#define KEY_BUF_LEN 200

#define ITEM_COMPARE_FAIL 999

#define DELETION_REGISTER	36

#define REG_PREVIOUS 1

#define REG_EXEC 2

#define NFA_ADD_NL		31

#define EMIT(c)	do {				\
		    if (post_ptr >= post_end && realloc_post_list() == FAIL) \
			return FAIL;		\
		    *post_ptr++ = c;		\
		} while (0)

#define NFA_PIM_UNUSED   0	/* pim not used */

#define NFA_PIM_TODO     1	/* pim not done yet */

#define NFA_PIM_MATCH    2	/* pim executed, matches */

#define NFA_PIM_NOMATCH  3	/* pim executed, no match */

#define NV_NCH	    0x01	  /* may need to get a second char */

#define NV_NCH_NOP  (0x02|NV_NCH) /* get second char when no operator pending */

#define NV_NCH_ALW  (0x04|NV_NCH) /* always get a second char */

#define NV_LANG	    0x08	/* second char needs language adjustment */

#define NV_SS	    0x10	/* may start selection */

#define NV_SSS	    0x20	/* may start selection with shift modifier */

#define NV_STS	    0x40	/* may stop selection without shift modif. */

#define NV_RL	    0x80	/* 'rightleft' modifies command */

#define NV_KEEPREG  0x100	/* don't clear regname */

#define NV_NCW	    0x200	/* not allowed in command-line window */

#define NV_CMDS_SIZE (sizeof(nv_cmds) / sizeof(struct nv_cmd))

#define CRYPT_MAGIC_LEN	12	/* cannot change */

#define GET_UINT32(n, b, i)		    \
{					    \
    (n) = ( (UINT32_T)(b)[(i)	 ] << 24)   \
	| ( (UINT32_T)(b)[(i) + 1] << 16)   \
	| ( (UINT32_T)(b)[(i) + 2] <<  8)   \
	| ( (UINT32_T)(b)[(i) + 3]	);  \
}

#define PUT_UINT32(n,b,i)		  \
{					  \
    (b)[(i)    ] = (char_u)((n) >> 24);   \
    (b)[(i) + 1] = (char_u)((n) >> 16);   \
    (b)[(i) + 2] = (char_u)((n) >>  8);   \
    (b)[(i) + 3] = (char_u)((n)      );   \
}

#define Offset(field) XtOffsetOf(ScrollbarRec, field)

#define NoButton -1

#define PICKLENGTH(widget, x, y) \
    ((widget->scrollbar.orientation == XtorientHorizontal) ? (x) : (y))

#define AT_MIN(x,y)    ((x) < (y) ? (x) : (y))

#define AT_MAX(x,y)    ((x) > (y) ? (x) : (y))

#define LINE_DELAY	300

#define PAGE_DELAY	300

#define LINE_REPEAT	 50

#define PAGE_REPEAT	250

#define CMDBUFSIZ	2048

#define HANDLE_ERRORS(cmd)

#define	PROTOCOL_VERSION	"4.0.0"

#define ARRAY_LENGTH(a) (sizeof(a) / sizeof(a[0]))

#define RGB(r, g, b) PgRGB(r, g, b)

#define EVENT_BUFFER_SIZE sizeof(PhEvent_t) + 1000

#define MOUSE_HIDE		TRUE

#define MOUSE_SHOW		FALSE

#define GUI_PH_MARGIN		4	/* Size of the bevel */

#define GUI_PH_MOUSE_TYPE		Ph_CURSOR_INSERT

#define LISTCOUNT   10

#define FMT_PATTERNS 10		/* maximum number of % recognized */

#define IS_QF_WINDOW(wp) (bt_quickfix(wp->w_buffer) && wp->w_llist_ref == NULL)

#define IS_LL_WINDOW(wp) (bt_quickfix(wp->w_buffer) && wp->w_llist_ref != NULL)

#define GET_LOC_LIST(wp) (IS_LL_WINDOW(wp) ? wp->w_llist_ref : wp->w_llist)

#define UH_MAGIC 0x18dade	/* value for uh_magic when in use */

#define UE_MAGIC 0xabc123	/* value for ue_magic when in use */

#define CRYPT_BUF_SIZE 8192

#define U_ALLOC_LINE(size) lalloc((long_u)(size), FALSE)

#define VIM_CLASSNAME      "VIM_MESSAGES"

#define VIM_CLASSNAME_LEN  (sizeof(VIM_CLASSNAME) - 1)

#define COPYDATA_KEYS		0

#define COPYDATA_REPLY		1

#define COPYDATA_EXPR		10

#define COPYDATA_RESULT		11

#define COPYDATA_ERROR_RESULT	12

#define COPYDATA_ENCODING	20

#define REPLY_ITEM(i) ((reply_T *)(reply_list.ga_data) + (i))

#define REPLY_COUNT (reply_list.ga_len)

#define KMAP_MAXLEN 20	    /* maximum length of "from" or "to" */

#define UNICODE_SPACE 0x20

#define UNICODE_LINEFEED 0x0a

#define DEFINE_INLINES

#define strneq(a,b,n) (strncmp(a,b,n)==0)

#define MOTIF_POPUP

#define EXTRA_MARKS 10					/* marks 0-9 */

#define EXTERN

#define EDIT_NONE   0	    /* no edit type yet */

#define EDIT_FILE   1	    /* file name argument[s] given, use argument list */

#define EDIT_STDIN  2	    /* read file from stdin */

#define EDIT_TAG    3	    /* tag name argument given, use tagname */

#define EDIT_QF	    4	    /* start in quickfix mode */

#define TRY_SEEK	/* attempt to use lseek, or skip forward by reading */

#define COLS 256	/* change here, if you ever need more columns */

#define LLEN (12 + (9*COLS-1) + COLS + 2)

#define HEX_NORMAL 0

#define HEX_POSTSCRIPT 1

#define HEX_CINCLUDE 2

#define HEX_BITS 3		/* not hex a dump, but bits: 01111001 */

#define HEX_LITTLEENDIAN 4

#define BY_NOFLAGS	0	/* end of word without flags or region; for
				 * postponed prefix: no <pflags> */

#define BY_INDEX	1	/* child is shared, index follows */

#define BY_FLAGS	2	/* end of word, <flags> byte follows; for
				 * postponed prefix: <pflags> follows */

#define BY_FLAGS2	3	/* end of word, <flags> and <flags2> bytes
				 * follow; never used in prefix tree */

#define BY_SPECIAL  BY_FLAGS2	/* highest special byte value */

#define SAL_F0LLOWUP		1

#define SAL_COLLAPSE		2

#define SAL_REM_ACCENTS		4

#define VIMSPELLMAGIC "VIMspell"  /* string at start of Vim spell file */

#define VIMSPELLMAGICL 8

#define VIMSPELLVERSION 50

#define SN_REGION	0	/* <regionname> section */

#define SN_CHARFLAGS	1	/* charflags section */

#define SN_MIDWORD	2	/* <midword> section */

#define SN_PREFCOND	3	/* <prefcond> section */

#define SN_REP		4	/* REP items section */

#define SN_SAL		5	/* SAL items section */

#define SN_SOFO		6	/* soundfolding section */

#define SN_MAP		7	/* MAP items section */

#define SN_COMPOUND	8	/* compound words section */

#define SN_SYLLABLE	9	/* syllable section */

#define SN_NOBREAK	10	/* NOBREAK section */

#define SN_SUGFILE	11	/* timestamp for .sug file */

#define SN_REPSAL	12	/* REPSAL items section */

#define SN_WORDS	13	/* common words */

#define SN_NOSPLITSUGS	14	/* don't split word for suggestions */

#define SN_INFO		15	/* info section */

#define SN_NOCOMPOUNDSUGS 16	/* don't compound for suggestions */

#define SN_END		255	/* end of sections */

#define SNF_REQUIRED	1	/* <sectionflags>: required section */

#define CF_WORD		0x01

#define CF_UPPER	0x02

#define AFT_CHAR	0	/* flags are one character */

#define AFT_LONG	1	/* flags are two characters */

#define AFT_CAPLONG	2	/* flags are one or two characters */

#define AFT_NUM		3	/* flags are numbers, comma separated */

#define HI2AH(hi)   ((affheader_T *)(hi)->hi_key)

#define HI2CI(hi)   ((compitem_T *)(hi)->hi_key)

#define  SBLOCKSIZE 16000	/* size of sb_data */

#define WN_MASK	 0xffff		/* mask relevant bits of "wn_flags" */

#define HI2WN(hi)    (wordnode_T *)((hi)->hi_key)

#define PFX_FLAGS	-256

#define CONDIT_COMB	1	/* affix must combine */

#define CONDIT_CFIX	2	/* affix must have CIRCUMFIX flag */

#define CONDIT_SUF	4	/* add a suffix for matching flags */

#define CONDIT_AFF	8	/* word already has an affix */

#define DFLT_FONT		"7x13"

#define DFLT_TOOLTIP_FONT	XtDefaultFontSet

#define DELETE_WINDOW_IDX 0	/* index in wm_atoms[] for WM_DELETE_WINDOW */

#define SAVE_YOURSELF_IDX 1	/* index in wm_atoms[] for WM_SAVE_YOURSELF */

#define XtNboldFont		"boldFont"

#define XtCBoldFont		"BoldFont"

#define XtNitalicFont		"italicFont"

#define XtCItalicFont		"ItalicFont"

#define XtNboldItalicFont	"boldItalicFont"

#define XtCBoldItalicFont	"BoldItalicFont"

#define XtNscrollbarWidth	"scrollbarWidth"

#define XtCScrollbarWidth	"ScrollbarWidth"

#define XtNmenuHeight		"menuHeight"

#define XtCMenuHeight		"MenuHeight"

#define XtNmenuFont		"menuFont"

#define XtCMenuFont		"MenuFont"

#define XtNmenuFontSet		"menuFontSet"

#define XtCMenuFontSet		"MenuFontSet"

#define XtNmenuBackground	"menuBackground"

#define XtCMenuBackground	"MenuBackground"

#define XtNmenuForeground	"menuForeground"

#define XtCMenuForeground	"MenuForeground"

#define XtNscrollBackground	"scrollBackground"

#define XtCScrollBackground	"ScrollBackground"

#define XtNscrollForeground	"scrollForeground"

#define XtCScrollForeground	"ScrollForeground"

#define XtNtooltipBackground	"tooltipBackground"

#define XtCTooltipBackground	"TooltipBackground"

#define XtNtooltipForeground	"tooltipForeground"

#define XtCTooltipForeground	"TooltipForeground"

#define XtNtooltipFont		"tooltipFont"

#define XtCTooltipFont		"TooltipFont"

#define MT_ST_CUR	0		/* static match in current file */

#define MT_GL_CUR	1		/* global match in current file */

#define MT_GL_OTH	2		/* global match in other file */

#define MT_ST_OTH	3		/* static match in other file */

#define MT_IC_OFF	4		/* add for icase match */

#define MT_RE_OFF	8		/* add for regexp match */

#define MT_MASK		7		/* mask for printing priority */

#define MT_COUNT	16

#define NOTAGFILE	99		/* return value for jumpto_tag */

#define UNICODE_INVALID 0xFFFD

#define PRCOLOR_BLACK	(long_u)0

#define PRCOLOR_WHITE	(long_u)0xFFFFFFL

#define PRT_MEDIASIZE_LEN  (sizeof(prt_mediasize) / sizeof(struct prt_mediasize_S))

#define PRT_PS_FONT_ROMAN	(0)

#define PRT_PS_FONT_BOLD	(1)

#define PRT_PS_FONT_OBLIQUE	(2)

#define PRT_PS_FONT_BOLDOBLIQUE (3)

#define PRT_RESOURCE_TYPE_PROCSET   (0)

#define PRT_RESOURCE_TYPE_ENCODING  (1)

#define PRT_RESOURCE_TYPE_CMAP      (2)

#define PRT_PROLOG_VERSION  ((char_u *)"1.4")

#define PRT_CID_PROLOG_VERSION  ((char_u *)"1.0")

#define PRT_RESOURCE_HEADER	    "%!PS-Adobe-"

#define PRT_RESOURCE_RESOURCE	    "Resource-"

#define PRT_RESOURCE_PROCSET	    "ProcSet"

#define PRT_RESOURCE_ENCODING	    "Encoding"

#define PRT_RESOURCE_CMAP	    "CMap"

#define PRT_DSC_MISC_TYPE	    (-1)

#define PRT_DSC_TITLE_TYPE	    (1)

#define PRT_DSC_VERSION_TYPE	    (2)

#define PRT_DSC_ENDCOMMENTS_TYPE    (3)

#define PRT_DSC_TITLE		    "%%Title:"

#define PRT_DSC_VERSION		    "%%Version:"

#define PRT_DSC_ENDCOMMENTS	    "%%EndComments:"

#define SIZEOF_CSTR(s)      (sizeof(s) - 1)

#define CSI_ARGS_MAX 16

#define CSI_LEADER_MAX 16

#define CSI_INTERMED_MAX 16

#define streq(a,b) (!strcmp(a,b))

#define strstartswith(a,b) (!strncmp(a,b,strlen(b)))

#define GUI_DWRITE_H

#define IDR_TOOLBAR1			101

#define VIM_VERSION_MAJOR		 8

#define VIM_VERSION_MAJOR_STR		"8"

#define VIM_VERSION_MINOR		 0

#define VIM_VERSION_MINOR_STR		"0"

#define VIM_VERSION_100	    (VIM_VERSION_MAJOR * 100 + VIM_VERSION_MINOR)

#define VIM_VERSION_BUILD		 281

#define VIM_VERSION_BUILD_BCD		0x119

#define VIM_VERSION_BUILD_STR		"281"

#define VIM_VERSION_PATCHLEVEL		 0

#define VIM_VERSION_PATCHLEVEL_STR	"0"

#define VIM_VERSION_RELEASE		final

#define VIM_VERSION_NODOT	"vim80"

#define VIM_VERSION_SHORT	"8.0"

#define VIM_VERSION_MEDIUM	"8.0"

#define VIM_VERSION_LONG	"VIM - Vi IMproved 8.0 (2016 Sep 12)"

#define VIM_VERSION_LONG_DATE	"VIM - Vi IMproved 8.0 (2016 Sep 12, compiled "

#define NBDEBUG_H

#define _Scrollbar_h

#define XtCMinimumThumb		"MinimumThumb"

#define XtCShown		"Shown"

#define XtCTopOfThumb		"TopOfThumb"

#define XtCMaxOfThumb		"MaxOfThumb"

#define XtCShadowWidth		"ShadowWidth"

#define XtCTopShadowPixel	"TopShadowPixel"

#define XtCBottomShadowPixel	"BottomShadowPixel"

#define XtCLimitThumb		"LimitThumb"

#define XtNminimumThumb		"minimumThumb"

#define XtNtopOfThumb		"topOfThumb"

#define XtNmaxOfThumb		"maxOfThumb"

#define XtNshadowWidth		"shadowWidth"

#define XtNtopShadowPixel	"topShadowPixel"

#define XtNbottomShadowPixel	"bottomShadowPixel"

#define XtNlimitThumb		"limitThumb"

#define SMODE_NONE		0

#define SMODE_CONT		1

#define SMODE_PAGE_UP		2

#define SMODE_PAGE_DOWN		3

#define SMODE_LINE_UP		4

#define SMODE_LINE_DOWN		5

#define ONE_LINE_DATA		1

#define ONE_PAGE_DATA		10

#define END_PAGE_DATA		9999

#define CASE_INSENSITIVE_FILENAME   /* ignore case when comparing file names */

#define SPACE_IN_FILENAME

#define USE_FNAME_CASE		    /* adjust case of file names */

#define USE_TERM_CONSOLE

#define HAVE_AVAIL_MEM

#define FNAME_ILLEGAL ";*?`#%" /* illegal characters in a file name */

#define mch_remove(x) remove((char *)(x))

#define mch_rename(src, dst) rename(src, dst)

#define mch_chdir(s) chdir(s)

#define vim_mkdir(x, y) mch_mkdir(x)

#define WSDEBUG_H

#define MAXWLEN 254		/* Assume max. word len is this many bytes.
				   Some places assume a word length fits in a
				   byte, thus it can't be above 255.
				   Must be >= PFD_NOTSPECIAL. */

#define MAXREGIONS 8		/* Number of regions supported. */

#define WF_REGION   0x01	/* region byte follows */

#define WF_ONECAP   0x02	/* word with one capital (or all capitals) */

#define WF_ALLCAP   0x04	/* word must be all capitals */

#define WF_RARE	    0x08	/* rare word */

#define WF_BANNED   0x10	/* bad word */

#define WF_AFX	    0x20	/* affix ID follows */

#define WF_FIXCAP   0x40	/* keep-case word, allcap not allowed */

#define WF_KEEPCAP  0x80	/* keep-case word */

#define WF_HAS_AFF  0x0100	/* word includes affix */

#define WF_NEEDCOMP 0x0200	/* word only valid in compound */

#define WF_NOSUGGEST 0x0400	/* word not to be suggested */

#define WF_COMPROOT 0x0800	/* already compounded word, COMPOUNDROOT */

#define WF_NOCOMPBEF 0x1000	/* no compounding before this word */

#define WF_NOCOMPAFT 0x2000	/* no compounding after this word */

#define WFP_RARE	    0x01	/* rare prefix */

#define WFP_NC		    0x02	/* prefix is not combining */

#define WFP_UP		    0x04	/* to-upper prefix */

#define WFP_COMPPERMIT	    0x08	/* prefix with COMPOUNDPERMITFLAG */

#define WFP_COMPFORBID	    0x10	/* prefix with COMPOUNDFORBIDFLAG */

#define WF_RAREPFX  (WFP_RARE << 24)	/* rare postponed prefix */

#define WF_PFX_NC   (WFP_NC << 24)	/* non-combining postponed prefix */

#define WF_PFX_UP   (WFP_UP << 24)	/* to-upper postponed prefix */

#define WF_PFX_COMPPERMIT (WFP_COMPPERMIT << 24) /* postponed prefix with
						  * COMPOUNDPERMITFLAG */

#define WF_PFX_COMPFORBID (WFP_COMPFORBID << 24) /* postponed prefix with
						  * COMPOUNDFORBIDFLAG */

#define COMP_CHECKDUP		1	/* CHECKCOMPOUNDDUP */

#define COMP_CHECKREP		2	/* CHECKCOMPOUNDREP */

#define COMP_CHECKCASE		4	/* CHECKCOMPOUNDCASE */

#define COMP_CHECKTRIPLE	8	/* CHECKCOMPOUNDTRIPLE */

#define	SP_TRUNCERROR	-1	/* spell file truncated error */

#define	SP_FORMERROR	-2	/* format error in spell file */

#define SP_OTHERERROR	-3	/* other error while reading spell file */

#define LANGP_ENTRY(ga, i)	(((langp_T *)(ga).ga_data) + (i))

#define SESSION_FILE	"Session.vim"

#define MAC_CLIENTSERVER

#define EnhancedB_H

#define XmIsEnhancedButton(w) XtIsSubclass(w, xmEnhancedButtonWidgetClass)

#define DFLT_ERRORFILE		"errors.err"

#define DFLT_RUNTIMEPATH	"$HOME/vimfiles,$VIM/vimfiles,$VIMRUNTIME,$VIM/vimfiles/after,$HOME/vimfiles/after"

#define BACKSLASH_IN_FILENAME

#define USE_CRNL		/* lines end in CR-NL instead of NL */

#define HAVE_DUP		/* have dup() */

#define HAVE_ST_MODE		/* have stat.st_mode */

#define CASE_INSENSITIVE_FILENAME   /* Open VMS is case insensitive */

#define SPACE_IN_FILENAME	    /* There could be space between user and passwd */

#define FNAME_ILLEGAL "|*#?%"       /* Illegal characters in a file name */

#define BINARY_FILE_IO		    /* Use binary fileio */

#define USE_GETCWD

#define USE_SYSTEM

#define HAVE_DATE_TIME

#define VIM_SIZEOF_INT 4

#define USEMEMMOVE

#define UINT32_T unsigned int

#define TIME_WITH_SYS_TIME

#define RETSIGTYPE void

#define SIGRETURN return

#define HAVE_SIGCONTEXT

#define TGETENT_ZERO_ERR

#define HAVE_GETCWD

#define HAVE_STRCSPN

#define HAVE_STRTOL

#define HAVE_TGETENT

#define HAVE_MEMSET

#define HAVE_STRERROR

#define HAVE_FCHOWN

#define HAVE_RENAME

#define HAVE_QSORT

#define HAVE_FSYNC

#define HAVE_GETPWUID

#define HAVE_GETPWNAM

#define	HAVE_STDLIB_H

#define	HAVE_STRING_H

#define	HAVE_ERRNO_H

#define HAVE_OPENDIR

#define HAVE_PUTENV

#define HAVE_SETENV

#define HAVE_SETJMP_H

#define HAVE_MATH_H

#define HAVE_FLOAT_FUNCS

#define HAVE_GETTIMEOFDAY

#define HAVE_USLEEP

#define HAVE_STRCASECMP

#define HAVE_STRINGS_H

#define HAVE_SIGSETJMP

#define HAVE_ISNAN

#define HAVE_SELECT

#define HAVE_FCNTL_H

#define HAVE_UNISTD_H 1

#define HAVE_SYS_TIME_H

#define HAVE_LOCALE_H

#define BROKEN_LOCALE

#define	HAVE_STRFTIME

#define TEE_		0x80

#define ALEF_U_H_	0x81

#define ALEF_		0x82

#define _BE		0x83

#define _PE		0x84

#define _TE		0x85

#define _SE		0x86

#define _JIM		0x87

#define _CHE		0x88

#define _HE_J		0x89

#define _XE		0x8a

#define _SIN		0x8b

#define _SHIN		0x8c

#define _SAD		0x8d

#define _ZAD		0x8e

#define _AYN		0x8f

#define _AYN_		0x90

#define AYN_		0x91

#define _GHAYN		0x92

#define _GHAYN_		0x93

#define GHAYN_		0x94

#define _FE		0x95

#define _GHAF		0x96

#define _KAF		0x97

#define _GAF		0x98

#define _LAM		0x99

#define LA		0x9a

#define _MIM		0x9b

#define _NOON		0x9c

#define _HE		0x9d

#define _HE_		0x9e

#define _YE		0x9f

#define _IE		0xec

#define IE_		0xed

#define IE		0xfb

#define _YEE		0xee

#define YEE_		0xef

#define YE_		0xff

#define F_BLANK		0xa0	/* Farsi ' ' (SP) character */

#define F_PSP		0xa1	/* PSP for capitalizing of a character */

#define F_PCN		0xa2	/* PCN for redefining of the hamye meaning */

#define F_EXCL		0xa3	/* Farsi ! character */

#define F_CURRENCY	0xa4	/* Farsi Rial character */

#define F_PERCENT	0xa5	/* Farsi % character */

#define F_PERIOD	0xa6	/* Farsi '.' character */

#define F_COMMA		0xa7	/* Farsi ',' character */

#define F_LPARENT	0xa8	/* Farsi '(' character */

#define F_RPARENT	0xa9	/* Farsi ')' character */

#define F_MUL		0xaa	/* Farsi 'x' character */

#define F_PLUS		0xab	/* Farsi '+' character */

#define F_BCOMMA	0xac	/* Farsi comma character */

#define F_MINUS		0xad	/* Farsi '-' character */

#define F_DIVIDE	0xae	/* Farsi divide (/) character */

#define F_SLASH		0xaf	/* Farsi '/' character */

#define FARSI_0		0xb0

#define FARSI_1		0xb1

#define FARSI_2		0xb2

#define FARSI_3		0xb3

#define FARSI_4		0xb4

#define FARSI_5		0xb5

#define FARSI_6		0xb6

#define FARSI_7		0xb7

#define FARSI_8		0xb8

#define FARSI_9		0xb9

#define F_DCOLON	0xba	/* Farsi ':' character */

#define F_SEMICOLON	0xbb	/* Farsi ';' character */

#define F_GREATER	0xbc	/* Farsi '>' character */

#define F_EQUALS	0xbd	/* Farsi '=' character */

#define F_LESS		0xbe	/* Farsi '<' character */

#define F_QUESTION	0xbf	/* Farsi ? character */

#define ALEF_A	0xc0

#define ALEF	0xc1

#define HAMZE	0xc2

#define BE	0xc3

#define PE	0xc4

#define TE	0xc5

#define SE	0xc6

#define JIM	0xc7

#define CHE	0xc8

#define HE_J	0xc9

#define XE	0xca

#define DAL	0xcb

#define ZAL	0xcc

#define RE	0xcd

#define ZE	0xce

#define JE	0xcf

#define SIN	0xd0

#define SHIN	0xd1

#define SAD	0xd2

#define ZAD	0xd3

#define _TA	0xd4

#define _ZA	0xd5

#define AYN	0xd6

#define GHAYN	0xd7

#define FE	0xd8

#define GHAF	0xd9

#define KAF	0xda

#define GAF	0xdb

#define LAM	0xdc

#define MIM	0xdd

#define NOON	0xde

#define WAW	0xdf

#define F_HE	0xe0		/* F_ added for name clash with Perl */

#define YE	0xe1

#define TEE	0xfc

#define _KAF_H	0xfd

#define YEE	0xfe

#define F_LBRACK	0xe2	/* Farsi '[' character */

#define F_RBRACK	0xe3	/* Farsi ']' character */

#define F_LBRACE	0xe4	/* Farsi '{' character */

#define F_RBRACE	0xe5	/* Farsi '}' character */

#define F_LQUOT		0xe6	/* Farsi left quotation character */

#define F_RQUOT		0xe7	/* Farsi right quotation character */

#define F_STAR		0xe8	/* Farsi '*' character */

#define F_UNDERLINE	0xe9	/* Farsi '_' character */

#define F_PIPE		0xea	/* Farsi '|' character */

#define F_BSLASH	0xeb	/* Farsi '\' character */

#define MAD		0xf0

#define JAZR		0xf1

#define OW		0xf2

#define MAD_N		0xf3

#define JAZR_N		0xf4

#define OW_OW		0xf5

#define TASH		0xf6

#define OO		0xf7

#define ALEF_U_H	0xf8

#define WAW_H		0xf9

#define ALEF_D_H	0xfa

#define SRC_EDT	0

#define SRC_CMD 1

#define AT_CURSOR 0

#define W_CONV 0x1

#define W_R_L  0x2

#define USE_CMD_KEY

#define USE_UNIXFILENAME

#define FEAT_SOURCE_FFS

#define FEAT_SOURCE_FF_MAC

#define USE_EXE_NAME		    /* to find  $VIM */

#define BREAKCHECK_SKIP	   32	    /* call mch_breakcheck() each time, it's
				       quite fast. Did I forgot to update the
				       comment */

#define USE_FNAME_CASE		/* make ":e os_Mac.c" open the file in its
				   original case, as "os_mac.c" */

#define BINARY_FILE_IO

#define EOL_DEFAULT EOL_MAC

#define CMDBUFFSIZE 1024	/* size of the command processing buffer */

#define WILDCHAR_LIST "*?[{`$"

#define mch_remove(x) unlink((char *)(x))

#define UNKNOWN_CREATOR '\?\?\?\?'

#define FOR_ALL_BUFFERS(buf) for (buf = firstbuf; buf != NULL; buf = buf->b_next)

#define NSCRIPT 15

#define KS_LAST	    KS_CPE

#define T_NAME	(TERM_STR(KS_NAME))	/* terminal name */

#define T_CE	(TERM_STR(KS_CE))	/* clear to end of line */

#define T_AL	(TERM_STR(KS_AL))	/* add new blank line */

#define T_CAL	(TERM_STR(KS_CAL))	/* add number of blank lines */

#define T_DL	(TERM_STR(KS_DL))	/* delete line */

#define T_CDL	(TERM_STR(KS_CDL))	/* delete number of lines */

#define T_CS	(TERM_STR(KS_CS))	/* scroll region */

#define T_CSV	(TERM_STR(KS_CSV))	/* scroll region vertical */

#define T_CL	(TERM_STR(KS_CL))	/* clear screen */

#define T_CD	(TERM_STR(KS_CD))	/* clear to end of display */

#define T_UT	(TERM_STR(KS_UT))	/* clearing uses background color */

#define T_DA	(TERM_STR(KS_DA))	/* text may be scrolled down from up */

#define T_DB	(TERM_STR(KS_DB))	/* text may be scrolled up from down */

#define T_VI	(TERM_STR(KS_VI))	/* cursor invisible */

#define T_VE	(TERM_STR(KS_VE))	/* cursor visible */

#define T_VS	(TERM_STR(KS_VS))	/* cursor very visible (blink) */

#define T_CVS	(TERM_STR(KS_CVS))	/* cursor normally visible (no blink) */

#define T_CSH	(TERM_STR(KS_CSH))	/* cursor shape */

#define T_CRC	(TERM_STR(KS_CRC))	/* request cursor blinking */

#define T_CRS	(TERM_STR(KS_CRS))	/* request cursor style */

#define T_ME	(TERM_STR(KS_ME))	/* normal mode */

#define T_MR	(TERM_STR(KS_MR))	/* reverse mode */

#define T_MD	(TERM_STR(KS_MD))	/* bold mode */

#define T_SE	(TERM_STR(KS_SE))	/* normal mode */

#define T_SO	(TERM_STR(KS_SO))	/* standout mode */

#define T_CZH	(TERM_STR(KS_CZH))	/* italic mode start */

#define T_CZR	(TERM_STR(KS_CZR))	/* italic mode end */

#define T_UE	(TERM_STR(KS_UE))	/* exit underscore (underline) mode */

#define T_US	(TERM_STR(KS_US))	/* underscore (underline) mode */

#define T_UCE	(TERM_STR(KS_UCE))	/* exit undercurl mode */

#define T_UCS	(TERM_STR(KS_UCS))	/* undercurl mode */

#define T_STE	(TERM_STR(KS_STE))	/* exit strikethrough mode */

#define T_STS	(TERM_STR(KS_STS))	/* strikethrough mode */

#define T_MS	(TERM_STR(KS_MS))	/* save to move cur in reverse mode */

#define T_CM	(TERM_STR(KS_CM))	/* cursor motion */

#define T_SR	(TERM_STR(KS_SR))	/* scroll reverse (backward) */

#define T_CRI	(TERM_STR(KS_CRI))	/* cursor number of chars right */

#define T_VB	(TERM_STR(KS_VB))	/* visual bell */

#define T_KS	(TERM_STR(KS_KS))	/* put term in "keypad transmit" mode */

#define T_KE	(TERM_STR(KS_KE))	/* out of "keypad transmit" mode */

#define T_TI	(TERM_STR(KS_TI))	/* put terminal in termcap mode */

#define T_TE	(TERM_STR(KS_TE))	/* out of termcap mode */

#define T_BC	(TERM_STR(KS_BC))	/* backspace character */

#define T_CCS	(TERM_STR(KS_CCS))	/* cur is relative to scroll region */

#define T_CCO	(TERM_STR(KS_CCO))	/* number of colors */

#define T_CSF	(TERM_STR(KS_CSF))	/* set foreground color */

#define T_CSB	(TERM_STR(KS_CSB))	/* set background color */

#define T_XS	(TERM_STR(KS_XS))	/* standout not erased by overwriting */

#define T_XN	(TERM_STR(KS_XN))	/* newline glitch */

#define T_MB	(TERM_STR(KS_MB))	/* blink mode */

#define T_CAF	(TERM_STR(KS_CAF))	/* set foreground color (ANSI) */

#define T_CAB	(TERM_STR(KS_CAB))	/* set background color (ANSI) */

#define T_LE	(TERM_STR(KS_LE))	/* cursor left */

#define T_ND	(TERM_STR(KS_ND))	/* cursor right */

#define T_CIS	(TERM_STR(KS_CIS))	/* set icon text start */

#define T_CIE	(TERM_STR(KS_CIE))	/* set icon text end */

#define T_TS	(TERM_STR(KS_TS))	/* set window title start */

#define T_FS	(TERM_STR(KS_FS))	/* set window title end */

#define T_CSC	(TERM_STR(KS_CSC))	/* set cursor color start */

#define T_CEC	(TERM_STR(KS_CEC))	/* set cursor color end */

#define T_CWP	(TERM_STR(KS_CWP))	/* set window position */

#define T_CGP	(TERM_STR(KS_CGP))	/* get window position */

#define T_CWS	(TERM_STR(KS_CWS))	/* window size */

#define T_CSI	(TERM_STR(KS_CSI))	/* start insert mode */

#define T_CEI	(TERM_STR(KS_CEI))	/* end insert mode */

#define T_CSR	(TERM_STR(KS_CSR))	/* start replace mode */

#define T_CRV	(TERM_STR(KS_CRV))	/* request version string */

#define T_RFG	(TERM_STR(KS_RFG))	/* request foreground RGB */

#define T_RBG	(TERM_STR(KS_RBG))	/* request background RGB */

#define T_OP	(TERM_STR(KS_OP))	/* original color pair */

#define T_U7	(TERM_STR(KS_U7))	/* request cursor position */

#define T_8F	(TERM_STR(KS_8F))	/* set foreground color (RGB) */

#define T_8B	(TERM_STR(KS_8B))	/* set background color (RGB) */

#define T_BE	(TERM_STR(KS_CBE))	/* enable bracketed paste mode */

#define T_BD	(TERM_STR(KS_CBD))	/* disable bracketed paste mode */

#define T_PS	(TERM_STR(KS_CPS))	/* start of bracketed paste */

#define T_PE	(TERM_STR(KS_CPE))	/* end of bracketed paste */

#define TMODE_COOK  0	/* terminal mode for external cmds and Ex mode */

#define TMODE_SLEEP 1	/* terminal mode for sleeping (cooked but no echo) */

#define TMODE_RAW   2	/* terminal mode for Normal and Insert mode */

#define IF_EB(a, b)	a

#define CharOrd(x)	((x) < 'a' ? (x) - 'A' : (x) - 'a')

#define CharOrdLow(x)	((x) - 'a')

#define CharOrdUp(x)	((x) - 'A')

#define ROT13(c, a)	(((((c) - (a)) + 13) % 26) + (a))

#define NUL		'\000'

#define BELL		'\007'

#define BS		'\010'

#define TAB		'\011'

#define NL		'\012'

#define NL_STR		(char_u *)"\012"

#define FF		'\014'

#define CAR		'\015'	/* CR is used by Mac OS X */

#define ESC		'\033'

#define ESC_STR		(char_u *)"\033"

#define ESC_STR_nc	"\033"

#define DEL		0x7f

#define DEL_STR		(char_u *)"\177"

#define POUND		0xA3

#define Ctrl_chr(x)	(TOUPPER_ASC(x) ^ 0x40) /* '?' -> DEL, '@' -> ^@, etc. */

#define Meta(x)		((x) | 0x80)

#define CTRL_F_STR	"\006"

#define CTRL_H_STR	"\010"

#define CTRL_V_STR	"\026"

#define Ctrl_AT		0   /* @ */

#define Ctrl_A		1

#define Ctrl_B		2

#define Ctrl_C		3

#define Ctrl_D		4

#define Ctrl_E		5

#define Ctrl_F		6

#define Ctrl_G		7

#define Ctrl_H		8

#define Ctrl_I		9

#define Ctrl_J		10

#define Ctrl_K		11

#define Ctrl_L		12

#define Ctrl_M		13

#define Ctrl_N		14

#define Ctrl_O		15

#define Ctrl_P		16

#define Ctrl_Q		17

#define Ctrl_R		18

#define Ctrl_S		19

#define Ctrl_T		20

#define Ctrl_U		21

#define Ctrl_V		22

#define Ctrl_W		23

#define Ctrl_X		24

#define Ctrl_Y		25

#define Ctrl_Z		26

#define Ctrl_BSL	28  /* \ BackSLash */

#define Ctrl_RSB	29  /* ] Right Square Bracket */

#define Ctrl_HAT	30  /* ^ */

#define Ctrl__		31

#define CSI		0x9b	/* Control Sequence Introducer */

#define CSI_STR		"\233"

#define DCS		0x90	/* Device Control String */

#define OSC		0x9d	/* Operating System Command */

#define STERM		0x9c	/* String Terminator */

#define SBAR_NONE	    -1

#define SBAR_LEFT	    0

#define SBAR_RIGHT	    1

#define SBAR_BOTTOM	    2

#define SBAR_VERT	    0

#define SBAR_HORIZ	    1

#define SB_DEFAULT_WIDTH    16

#define MENU_DEFAULT_HEIGHT 1		/* figure it out at runtime */

#define GUI_MON_WRAP_CURSOR	0x01	/* wrap cursor at end of line */

#define GUI_MON_INVERT		0x02	/* invert the characters */

#define GUI_MON_IS_CURSOR	0x04	/* drawing cursor */

#define GUI_MON_TRS_CURSOR	0x08	/* drawing transparent cursor */

#define GUI_MON_NOCLEAR		0x10	/* don't clear selection */

#define DRAW_TRANSP		0x01	/* draw with transparent bg */

#define DRAW_BOLD		0x02	/* draw bold text */

#define DRAW_UNDERL		0x04	/* draw underline text */

#define DRAW_UNDERC		0x08	/* draw undercurl text */

#define DRAW_CURSOR		0x20	/* drawing block cursor (win32) */

#define DRAW_STRIKE		0x40	/* strikethrough */

#define DRAW_WIDE		0x80	/* drawing wide char (MacVim) */

#define DRAW_COMP		0x100	/* drawing composing char (MacVim) */

#define TEAR_STRING		"-->Detach"

#define TEAR_LEN		(9)	/* length of above string */

#define TOOLBAR_BUTTON_HEIGHT	18

#define TOOLBAR_BUTTON_WIDTH	18

#define TOOLBAR_BORDER_HEIGHT	12  /* room above+below buttons for MSWindows */

#define INVALCOLOR (guicolor_T)-11111	/* number for invalid color; on 32 bit
				   displays there is a tiny chance this is an
				   actual color */

#define DFLT_EFM	"%*[^\"]\"%f\"%*\\D%l: %m,\"%f\"%*\\D%l: %m,%-G%f:%l: (Each undeclared identifier is reported only once,%-G%f:%l: for each function it appears in.),%-GIn file included from %f:%l:%c:,%-GIn file included from %f:%l:%c\\,,%-GIn file included from %f:%l:%c,%-GIn file included from %f:%l,%-G%*[ ]from %f:%l:%c,%-G%*[ ]from %f:%l:,%-G%*[ ]from %f:%l\\,,%-G%*[ ]from %f:%l,%f:%l:%c:%m,%f(%l):%m,%f:%l:%m,\"%f\"\\, line %l%*\\D%c%*[^ ] %m,%D%*\\a[%*\\d]: Entering directory %*[`']%f',%X%*\\a[%*\\d]: Leaving directory %*[`']%f',%D%*\\a: Entering directory %*[`']%f',%X%*\\a: Leaving directory %*[`']%f',%DMaking %*\\a in %f,%f|%l| %m"

#define DFLT_GREPFORMAT	"%f:%l:%m,%f:%l%m,%f  %l%m"

#define FF_DOS		"dos"

#define FF_MAC		"mac"

#define FF_UNIX		"unix"

#define EOL_UNKNOWN	-1	/* not defined yet */

#define EOL_UNIX	0	/* NL */

#define EOL_DOS		1	/* CR NL */

#define EOL_MAC		2	/* CR */

#define FO_WRAP		't'

#define FO_WRAP_COMS	'c'

#define FO_RET_COMS	'r'

#define FO_OPEN_COMS	'o'

#define FO_Q_COMS	'q'

#define FO_Q_NUMBER	'n'

#define FO_Q_SECOND	'2'

#define FO_INS_VI	'v'

#define FO_INS_LONG	'l'

#define FO_INS_BLANK	'b'

#define FO_MBYTE_BREAK	'm'	/* break before/after multi-byte char */

#define FO_MBYTE_JOIN	'M'	/* no space before/after multi-byte char */

#define FO_MBYTE_JOIN2	'B'	/* no space between multi-byte chars */

#define FO_ONE_LETTER	'1'

#define FO_WHITE_PAR	'w'	/* trailing white space continues paragr. */

#define FO_AUTO		'a'	/* automatic formatting */

#define FO_REMOVE_COMS	'j'	/* remove comment leaders when joining lines */

#define DFLT_FO_VI	"vt"

#define DFLT_FO_VIM	"tcq"

#define FO_ALL		"tcroq2vlb1mMBn,awj"	/* for do_set() */

#define CPO_ALTREAD	'a'	/* ":read" sets alternate file name */

#define CPO_ALTWRITE	'A'	/* ":write" sets alternate file name */

#define CPO_BAR		'b'	/* "\|" ends a mapping */

#define CPO_BSLASH	'B'	/* backslash in mapping is not special */

#define CPO_SEARCH	'c'

#define CPO_CONCAT	'C'	/* Don't concatenate sourced lines */

#define CPO_DOTTAG	'd'	/* "./tags" in 'tags' is in current dir */

#define CPO_DIGRAPH	'D'	/* No digraph after "r", "f", etc. */

#define CPO_EXECBUF	'e'

#define CPO_EMPTYREGION	'E'	/* operating on empty region is an error */

#define CPO_FNAMER	'f'	/* set file name for ":r file" */

#define CPO_FNAMEW	'F'	/* set file name for ":w file" */

#define CPO_GOTO1	'g'	/* goto line 1 for ":edit" */

#define CPO_INSEND	'H'	/* "I" inserts before last blank in line */

#define CPO_INTMOD	'i'	/* interrupt a read makes buffer modified */

#define CPO_INDENT	'I'	/* remove auto-indent more often */

#define CPO_JOINSP	'j'	/* only use two spaces for join after '.' */

#define CPO_ENDOFSENT	'J'	/* need two spaces to detect end of sentence */

#define CPO_KEYCODE	'k'	/* don't recognize raw key code in mappings */

#define CPO_KOFFSET	'K'	/* don't wait for key code in mappings */

#define CPO_LITERAL	'l'	/* take char after backslash in [] literal */

#define CPO_LISTWM	'L'	/* 'list' changes wrapmargin */

#define CPO_SHOWMATCH	'm'

#define CPO_MATCHBSL	'M'	/* "%" ignores use of backslashes */

#define CPO_NUMCOL	'n'	/* 'number' column also used for text */

#define CPO_LINEOFF	'o'

#define CPO_OVERNEW	'O'	/* silently overwrite new file */

#define CPO_LISP	'p'	/* 'lisp' indenting */

#define CPO_FNAMEAPP	'P'	/* set file name for ":w >>file" */

#define CPO_JOINCOL	'q'	/* with "3J" use column after first join */

#define CPO_REDO	'r'

#define CPO_REMMARK	'R'	/* remove marks when filtering */

#define CPO_BUFOPT	's'

#define CPO_BUFOPTGLOB	'S'

#define CPO_TAGPAT	't'

#define CPO_UNDO	'u'	/* "u" undoes itself */

#define CPO_BACKSPACE	'v'	/* "v" keep deleted text */

#define CPO_CW		'w'	/* "cw" only changes one blank */

#define CPO_FWRITE	'W'	/* "w!" doesn't overwrite readonly files */

#define CPO_ESC		'x'

#define CPO_REPLCNT	'X'	/* "R" with a count only deletes chars once */

#define CPO_YANK	'y'

#define CPO_KEEPRO	'Z'	/* don't reset 'readonly' on ":w!" */

#define CPO_DOLLAR	'$'

#define CPO_FILTER	'!'

#define CPO_MATCH	'%'

#define CPO_STAR	'*'	/* ":*" means ":@" */

#define CPO_PLUS	'+'	/* ":write file" resets 'modified' */

#define CPO_MINUS	'-'	/* "9-" fails at and before line 9 */

#define CPO_SPECI	'<'	/* don't recognize <> in mappings */

#define CPO_REGAPPEND	'>'	/* insert NL when appending to a register */

#define CPO_HASH	'#'	/* "D", "o" and "O" do not use a count */

#define CPO_PARA	'{'	/* "{" is also a paragraph boundary */

#define CPO_TSIZE	'|'	/* $LINES and $COLUMNS overrule term size */

#define CPO_PRESERVE	'&'	/* keep swap file after :preserve */

#define CPO_SUBPERCENT	'/'	/* % in :s string uses previous one */

#define CPO_BACKSL	'\\'	/* \ is not special in [] */

#define CPO_CHDIR	'.'	/* don't chdir if buffer is modified */

#define CPO_SCOLON	';'	/* using "," and ";" will skip over char if
				 * cursor would not move */

#define CPO_VIM		"aABceFs"

#define CPO_VI		"aAbBcCdDeEfFgHiIjJkKlLmMnoOpPqrRsStuvwWxXyZ$!%*-+<>;"

#define CPO_ALL		"aAbBcCdDeEfFgHiIjJkKlLmMnoOpPqrRsStuvwWxXyZ$!%*-+<>#{|&/\\.;"

#define WW_ALL		"bshl<>[],~"

#define MOUSE_NORMAL	'n'		/* use mouse in Normal mode */

#define MOUSE_VISUAL	'v'		/* use mouse in Visual/Select mode */

#define MOUSE_INSERT	'i'		/* use mouse in Insert mode */

#define MOUSE_COMMAND	'c'		/* use mouse in Command-line mode */

#define MOUSE_HELP	'h'		/* use mouse in help buffers */

#define MOUSE_RETURN	'r'		/* use mouse for hit-return message */

#define MOUSE_A		"nvich"		/* used for 'a' flag */

#define MOUSE_ALL	"anvichr"	/* all possible characters */

#define MOUSE_NONE	' '		/* don't use Visual selection */

#define MOUSE_NONEF	'x'		/* forced modeless selection */

#define COCU_ALL	"nvic"		/* flags for 'concealcursor' */

#define SHM_RO		'r'		/* readonly */

#define SHM_MOD		'm'		/* modified */

#define SHM_FILE	'f'		/* (file 1 of 2) */

#define SHM_LAST	'i'		/* last line incomplete */

#define SHM_TEXT	'x'		/* tx instead of textmode */

#define SHM_LINES	'l'		/* "L" instead of "lines" */

#define SHM_NEW		'n'		/* "[New]" instead of "[New file]" */

#define SHM_WRI		'w'		/* "[w]" instead of "written" */

#define SHM_A		"rmfixlnw"	/* represented by 'a' flag */

#define SHM_WRITE	'W'		/* don't use "written" at all */

#define SHM_TRUNC	't'		/* trunctate file messages */

#define SHM_TRUNCALL	'T'		/* trunctate all messages */

#define SHM_OVER	'o'		/* overwrite file messages */

#define SHM_OVERALL	'O'		/* overwrite more messages */

#define SHM_SEARCH	's'		/* no search hit bottom messages */

#define SHM_ATTENTION	'A'		/* no ATTENTION messages */

#define SHM_INTRO	'I'		/* intro messages */

#define SHM_COMPLETIONMENU  'c'		/* completion menu messages */

#define SHM_RECORDING	'q'		/* short recording message */

#define SHM_FILEINFO	'F'		/* no file info messages */

#define SHM_ALL		"rmfixlnwaWtToOsAIcqF" /* all possible flags for 'shm' */

#define GO_ASEL		'a'		/* autoselect */

#define GO_ASELML	'A'		/* autoselect modeless selection */

#define GO_BOT		'b'		/* use bottom scrollbar */

#define GO_CONDIALOG	'c'		/* use console dialog */

#define GO_TABLINE	'e'		/* may show tabline */

#define GO_FORG		'f'		/* start GUI in foreground */

#define GO_GREY		'g'		/* use grey menu items */

#define GO_HORSCROLL	'h'		/* flexible horizontal scrolling */

#define GO_ICON		'i'		/* use Vim icon */

#define GO_LEFT		'l'		/* use left scrollbar */

#define GO_VLEFT	'L'		/* left scrollbar with vert split */

#define GO_MENUS	'm'		/* use menu bar */

#define GO_NOSYSMENU	'M'		/* don't source system menu */

#define GO_POINTER	'p'		/* pointer enter/leave callbacks */

#define GO_ASELPLUS	'P'		/* autoselectPlus */

#define GO_RIGHT	'r'		/* use right scrollbar */

#define GO_VRIGHT	'R'		/* right scrollbar with vert split */

#define GO_TEAROFF	't'		/* add tear-off menu items */

#define GO_TOOLBAR	'T'		/* add toolbar */

#define GO_FOOTER	'F'		/* add footer */

#define GO_VERTICAL	'v'		/* arrange dialog buttons vertically */

#define GO_KEEPWINSIZE	'k'		/* keep GUI window size */

#define GO_ALL		"aAbcefFghilmMprtTvk" /* all possible flags for 'go' */

#define COM_NEST	'n'		/* comments strings nest */

#define COM_BLANK	'b'		/* needs blank after string */

#define COM_START	's'		/* start of comment */

#define COM_MIDDLE	'm'		/* middle of comment */

#define COM_END		'e'		/* end of comment */

#define COM_AUTO_END	'x'		/* last char of end closes comment */

#define COM_FIRST	'f'		/* first line comment only */

#define COM_LEFT	'l'		/* left adjusted */

#define COM_RIGHT	'r'		/* right adjusted */

#define COM_NOBACK	'O'		/* don't use for "O" command */

#define COM_ALL		"nbsmexflrO"	/* all flags for 'comments' option */

#define COM_MAX_LEN	50		/* maximum length of a part */

#define STL_FILEPATH	'f'		/* path of file in buffer */

#define STL_FULLPATH	'F'		/* full path of file in buffer */

#define STL_FILENAME	't'		/* last part (tail) of file path */

#define STL_COLUMN	'c'		/* column og cursor*/

#define STL_VIRTCOL	'v'		/* virtual column */

#define STL_VIRTCOL_ALT	'V'		/* - with 'if different' display */

#define STL_LINE	'l'		/* line number of cursor */

#define STL_NUMLINES	'L'		/* number of lines in buffer */

#define STL_BUFNO	'n'		/* current buffer number */

#define STL_KEYMAP	'k'		/* 'keymap' when active */

#define STL_OFFSET	'o'		/* offset of character under cursor*/

#define STL_OFFSET_X	'O'		/* - in hexadecimal */

#define STL_BYTEVAL	'b'		/* byte value of character */

#define STL_BYTEVAL_X	'B'		/* - in hexadecimal */

#define STL_ROFLAG	'r'		/* readonly flag */

#define STL_ROFLAG_ALT	'R'		/* - other display */

#define STL_HELPFLAG	'h'		/* window is showing a help file */

#define STL_HELPFLAG_ALT 'H'		/* - other display */

#define STL_FILETYPE	'y'		/* 'filetype' */

#define STL_FILETYPE_ALT 'Y'		/* - other display */

#define STL_PREVIEWFLAG	'w'		/* window is showing the preview buf */

#define STL_PREVIEWFLAG_ALT 'W'		/* - other display */

#define STL_MODIFIED	'm'		/* modified flag */

#define STL_MODIFIED_ALT 'M'		/* - other display */

#define STL_QUICKFIX	'q'		/* quickfix window description */

#define STL_PERCENTAGE	'p'		/* percentage through file */

#define STL_ALTPERCENT	'P'		/* percentage as TOP BOT ALL or NN% */

#define STL_ARGLISTSTAT	'a'		/* argument list status as (x of y) */

#define STL_PAGENUM	'N'		/* page number (when printing)*/

#define STL_VIM_EXPR	'{'		/* start of expression to substitute */

#define STL_MIDDLEMARK	'='		/* separation between left and right */

#define STL_TRUNCMARK	'<'		/* truncation mark if line is too long*/

#define STL_USER_HL	'*'		/* highlight from (User)1..9 or 0 */

#define STL_HIGHLIGHT	'#'		/* highlight name */

#define STL_TABPAGENR	'T'		/* tab page label nr */

#define STL_TABCLOSENR	'X'		/* tab page close nr */

#define STL_ALL		((char_u *) "fFtcvVlLknoObBrRhHmYyWwMqpPaN{#")

#define WIM_FULL	1

#define WIM_LONGEST	2

#define WIM_LIST	4

#define BS_INDENT	'i'	/* "Indent" */

#define BS_EOL		'o'	/* "eOl" */

#define BS_START	's'	/* "Start" */

#define LISPWORD_VALUE	"defun,define,defmacro,set!,lambda,if,case,let,flet,let*,letrec,do,do*,define-syntax,let-syntax,letrec-syntax,destructuring-bind,defpackage,defparameter,defstruct,deftype,defvar,do-all-symbols,do-external-symbols,do-symbols,dolist,dotimes,ecase,etypecase,eval-when,labels,macrolet,multiple-value-bind,multiple-value-call,multiple-value-prog1,multiple-value-setq,prog1,progv,typecase,unless,unwind-protect,when,with-input-from-string,with-open-file,with-open-stream,with-output-to-string,with-package-iterator,define-condition,handler-bind,handler-case,restart-bind,restart-case,with-simple-restart,store-value,use-value,muffle-warning,abort,continue,with-slots,with-slots*,with-accessors,with-accessors*,defclass,defmethod,print-unreadable-object"

#define BO_ALL		0x0001

#define BO_BS		0x0002

#define BO_CRSR		0x0004

#define BO_COMPL	0x0008

#define BO_COPY		0x0010

#define BO_CTRLG	0x0020

#define BO_ERROR	0x0040

#define BO_ESC		0x0080

#define BO_EX		0x0100

#define BO_HANGUL	0x0200

#define BO_IM		0x0400

#define BO_LANG		0x0800

#define BO_MESS		0x1000

#define BO_MATCH	0x2000

#define BO_OPER		0x4000

#define BO_REG		0x8000

#define BO_SH		0x10000

#define BO_SPELL	0x20000

#define BO_WILD		0x40000

#define DY_LASTLINE		0x001

#define DY_TRUNCATE		0x002

#define DY_UHEX			0x004

#define FUOPT_MAXVERT         0x001

#define FUOPT_MAXHORZ         0x002

#define FUOPT_BGCOLOR_HLGROUP 0x004    /* if set, fuoptions_bgcolor
                                          is a highlight group
                                          id. Else, it's an explicit 
                                          argb color. */

#define SWB_USEOPEN		0x001

#define SWB_USETAB		0x002

#define SWB_SPLIT		0x004

#define SWB_NEWTAB		0x008

#define SWB_VSPLIT		0x010

#define TC_FOLLOWIC		0x01

#define TC_IGNORE		0x02

#define TC_MATCH		0x04

#define TC_FOLLOWSCS		0x08

#define TC_SMART		0x10

#define NO_LOCAL_UNDOLEVEL -123456

#define _INTEGRATION_H

#define NOHANDS_SUPPORT_FUNCTIONS

#define BACKGROUND	0

#define FOREGROUND	1

#define BOTTOM_SHADOW	2

#define TOP_SHADOW	3

#define HIGHLIGHT	4

#define PCHAR(lp, c) (*(ml_get_buf(curbuf, (lp).lnum, TRUE) + (lp).col) = (c))

#define LTOREQ_POS(a, b) (LT_POS(a, b) || EQUAL_POS(a, b))

#define VIM_ISWHITE(x)	((x) == ' ' || (x) == '\t')

#define LINEEMPTY(p) (*ml_get(p) == NUL)

#define BUFEMPTY() (curbuf->b_ml.ml_line_count == 1 && *ml_get((linenr_T)1) == NUL)

#define VIM_ISDIGIT(c) ((unsigned)(c) - '0' < 10)

#define EMPTY_IF_NULL(x) ((x) ? (x) : (char_u *)"")

#define VIM_ISBREAK(c) ((c) < 256 && breakat_flags[(char_u)(c)])

#define DI2HIKEY(di) ((di)->di_key)

#define HIKEY2DI(p)  ((dictitem_T *)(p - offsetof(dictitem_T, di_key)))

#define HI2DI(hi)     HIKEY2DI((hi)->hi_key)

#define VIM_CLEAR(p) \
    do { \
	if ((p) != NULL) { \
	    vim_free(p); \
	    (p) = NULL; \
	} \
    } while (0)

#define NUMBUFLEN 65

#define STR2NR_BIN 1

#define STR2NR_OCT 2

#define STR2NR_HEX 4

#define STR2NR_ALL (STR2NR_BIN + STR2NR_OCT + STR2NR_HEX)

#define STR2NR_FORCE 8 /* only when ONE of the above is used */

#define PRINTF_DECIMAL_LONG_U SCANF_DECIMAL_LONG_U

#define MAX_TYPENR 65535

#define VALID_NO_UPDATE		 5  /* no new changes, keep the command line if
				       possible */

#define VALID			10  /* buffer not changed, or changes marked
				       with b_mod_* */

#define INVERTED		20  /* redisplay inverted part that changed */

#define INVERTED_ALL		25  /* redisplay whole inverted part */

#define REDRAW_TOP		30  /* display first w_upd_rows screen lines */

#define SOME_VALID		35  /* like NOT_VALID but may scroll */

#define NOT_VALID		40  /* buffer needs complete redraw */

#define CLEAR			50  /* screen messed up, clear it */

#define VALID_WROW	0x01	/* w_wrow (window row) is valid */

#define VALID_WCOL	0x02	/* w_wcol (window col) is valid */

#define VALID_VIRTCOL	0x04	/* w_virtcol (file col) is valid */

#define VALID_CHEIGHT	0x08	/* w_cline_height and w_cline_folded valid */

#define VALID_CROW	0x10	/* w_cline_row is valid */

#define VALID_BOTLINE	0x20	/* w_botine and w_empty_rows are valid */

#define VALID_BOTLINE_AP 0x40	/* w_botine is approximated */

#define VALID_TOPLINE	0x80	/* w_topline is valid (for cursor position) */

#define HL_NORMAL		0x00

#define HL_INVERSE		0x01

#define HL_BOLD			0x02

#define HL_ITALIC		0x04

#define HL_UNDERLINE		0x08

#define HL_UNDERCURL		0x10

#define HL_STANDOUT		0x20

#define HL_NOCOMBINE		0x40

#define HL_STRIKETHROUGH	0x80

#define HL_ALL			0xff

#define MSG_HIST		0x1000

#define NORMAL		0x01	/* Normal mode, command expected */

#define VISUAL		0x02	/* Visual mode - use get_real_state() */

#define OP_PENDING	0x04	/* Normal mode, operator is pending - use
				   get_real_state() */

#define CMDLINE		0x08	/* Editing command line */

#define INSERT		0x10	/* Insert mode */

#define LANGMAP		0x20	/* Language mapping, can be combined with
				   INSERT and CMDLINE */

#define REPLACE_FLAG	0x40	/* Replace mode flag */

#define REPLACE		(REPLACE_FLAG + INSERT)

#define LREPLACE	(REPLACE_FLAG + LANGMAP)

#define NORMAL_BUSY	(0x100 + NORMAL) /* Normal mode, busy with a command */

#define HITRETURN	(0x200 + NORMAL) /* waiting for return or command */

#define ASKMORE		0x300	/* Asking if you want --more-- */

#define SETWSIZE	0x400	/* window size has changed */

#define ABBREV		0x500	/* abbreviation instead of mapping */

#define EXTERNCMD	0x600	/* executing an external command */

#define SHOWMATCH	(0x700 + INSERT) /* show matching paren */

#define CONFIRM		0x800	/* ":confirm" prompt */

#define SELECTMODE	0x1000	/* Select mode, only for mappings */

#define TERMINAL        0x2000  /* Terminal mode */

#define MAP_ALL_MODES	(0x3f | SELECTMODE | TERMINAL)

#define FORWARD			1

#define BACKWARD		(-1)

#define FORWARD_FILE		3

#define BACKWARD_FILE		(-3)

#define FAIL			0

#define NOTDONE			2   /* not OK or FAIL but skipped */

#define BF_RECOVERED	0x01	/* buffer has been recovered */

#define BF_CHECK_RO	0x02	/* need to check readonly when loading file
				   into buffer (set by ":e", may be reset by
				   ":buf" */

#define BF_NEVERLOADED	0x04	/* file has never been loaded into buffer,
				   many variables still need to be set */

#define BF_NOTEDITED	0x08	/* Set when file name is changed after
				   starting to edit, reset when file is
				   written out. */

#define BF_NEW		0x10	/* file didn't exist when editing started */

#define BF_NEW_W	0x20	/* Warned for BF_NEW and file created */

#define BF_READERR	0x40	/* got errors while reading the file */

#define BF_DUMMY	0x80	/* dummy buffer, only used internally */

#define BF_PRESERVED	0x100	/* ":preserve" was used */

#define BF_WRITE_MASK	(BF_NOTEDITED + BF_NEW + BF_READERR)

#define EXPAND_UNSUCCESSFUL	(-2)

#define EXPAND_OK		(-1)

#define EXPAND_NOTHING		0

#define EXPAND_COMMANDS		1

#define EXPAND_FILES		2

#define EXPAND_DIRECTORIES	3

#define EXPAND_SETTINGS		4

#define EXPAND_BOOL_SETTINGS	5

#define EXPAND_TAGS		6

#define EXPAND_OLD_SETTING	7

#define EXPAND_HELP		8

#define EXPAND_BUFFERS		9

#define EXPAND_EVENTS		10

#define EXPAND_MENUS		11

#define EXPAND_SYNTAX		12

#define EXPAND_HIGHLIGHT	13

#define EXPAND_AUGROUP		14

#define EXPAND_USER_VARS	15

#define EXPAND_MAPPINGS		16

#define EXPAND_TAGS_LISTFILES	17

#define EXPAND_FUNCTIONS	18

#define EXPAND_USER_FUNC	19

#define EXPAND_EXPRESSION	20

#define EXPAND_MENUNAMES	21

#define EXPAND_USER_COMMANDS	22

#define EXPAND_USER_CMD_FLAGS	23

#define EXPAND_USER_NARGS	24

#define EXPAND_USER_COMPLETE	25

#define EXPAND_ENV_VARS		26

#define EXPAND_LANGUAGE		27

#define EXPAND_COLORS		28

#define EXPAND_COMPILER		29

#define EXPAND_USER_DEFINED	30

#define EXPAND_USER_LIST	31

#define EXPAND_SHELLCMD		32

#define EXPAND_CSCOPE		33

#define EXPAND_SIGN		34

#define EXPAND_PROFILE		35

#define EXPAND_BEHAVE		36

#define EXPAND_FILETYPE		37

#define EXPAND_FILES_IN_PATH	38

#define EXPAND_OWNSYNTAX	39

#define EXPAND_LOCALES		40

#define EXPAND_HISTORY		41

#define EXPAND_USER		42

#define EXPAND_SYNTIME		43

#define EXPAND_USER_ADDR_TYPE	44

#define EXPAND_PACKADD		45

#define EXPAND_MESSAGES		46

#define EXPAND_MAPCLEAR		47

#define EXPAND_MACACTION	48

#define EXMODE_NORMAL		1

#define EXMODE_VIM		2

#define WILD_FREE		1

#define WILD_EXPAND_FREE	2

#define WILD_EXPAND_KEEP	3

#define WILD_NEXT		4

#define WILD_PREV		5

#define WILD_ALL		6

#define WILD_LONGEST		7

#define WILD_ALL_KEEP		8

#define WILD_LIST_NOTFOUND	0x01

#define WILD_HOME_REPLACE	0x02

#define WILD_USE_NL		0x04

#define WILD_NO_BEEP		0x08

#define WILD_ADD_SLASH		0x10

#define WILD_KEEP_ALL		0x20

#define WILD_SILENT		0x40

#define WILD_ESCAPE		0x80

#define WILD_ICASE		0x100

#define WILD_ALLLINKS		0x200

#define EW_DIR		0x01	/* include directory names */

#define EW_FILE		0x02	/* include file names */

#define EW_NOTFOUND	0x04	/* include not found names */

#define EW_ADDSLASH	0x08	/* append slash to directory name */

#define EW_KEEPALL	0x10	/* keep all matches */

#define EW_SILENT	0x20	/* don't print "1 returned" from shell */

#define EW_EXEC		0x40	/* executable files */

#define EW_PATH		0x80	/* search in 'path' too */

#define EW_ICASE	0x100	/* ignore case */

#define EW_NOERROR	0x200	/* no error for bad regexp */

#define EW_NOTWILD	0x400	/* add match with literal name if exists */

#define EW_KEEPDOLLAR	0x800	/* do not escape $, $var is expanded */

#define EW_ALLLINKS	0x1000	/* also links not pointing to existing file */

#define EW_SHELLCMD	0x2000	/* called from expand_shellcmd(), don't check
				 * if executable is in $PATH */

#define EW_DODOT	0x4000	/* also files starting with a dot */

#define EW_EMPTYOK	0x8000	/* no matches is not an error */

#define FINDFILE_FILE	0	/* only files */

#define FINDFILE_DIR	1	/* only directories */

#define FINDFILE_BOTH	2	/* files and directories */

#define W_ENDCOL(wp)	(wp->w_wincol + wp->w_width)

#define FIND_ANY	1

#define FIND_DEFINE	2

#define CHECK_PATH	3

#define ACTION_SHOW	1

#define ACTION_GOTO	2

#define ACTION_SPLIT	3

#define ACTION_SHOW_ALL	4

#define SEARCH_REV    0x01  /* go in reverse of previous dir. */

#define SEARCH_ECHO   0x02  /* echo the search command and handle options */

#define SEARCH_MSG    0x0c  /* give messages (yes, it's not 0x04) */

#define SEARCH_NFMSG  0x08  /* give all messages except not found */

#define SEARCH_OPT    0x10  /* interpret optional flags */

#define SEARCH_HIS    0x20  /* put search pattern in history */

#define SEARCH_END    0x40  /* put cursor at end of match */

#define SEARCH_NOOF   0x80  /* don't add offset to position */

#define SEARCH_START 0x100  /* start search without col offset */

#define SEARCH_MARK  0x200  /* set previous context mark */

#define SEARCH_KEEP  0x400  /* keep previous search pattern */

#define SEARCH_PEEK  0x800  /* peek for typed char, cancel search */

#define SEARCH_COL  0x1000  /* start at specified column instead of zero */

#define FIND_IDENT	1	/* find identifier (word) */

#define FIND_STRING	2	/* find any string (WORD) */

#define FIND_EVAL	4	/* include "->", "[]" and "." */

#define FNAME_MESS	1	/* give error message */

#define FNAME_EXP	2	/* expand to path */

#define FNAME_HYP	4	/* check for hypertext link */

#define FNAME_INCL	8	/* apply 'includeexpr' */

#define FNAME_REL	16	/* ".." and "./" are relative to the (current)
				   file instead of the current directory */

#define FNAME_UNESC	32	/* remove backslashes used for escaping */

#define GETF_SETMARK	0x01	/* set pcmark before jumping */

#define GETF_ALT	0x02	/* jumping to alternate file (not buf num) */

#define GETF_SWITCH	0x04	/* respect 'switchbuf' settings when jumping */

#define GETFILE_ERROR	    1	/* normal error */

#define GETFILE_NOT_WRITTEN 2	/* "not written" error */

#define GETFILE_SAME_FILE   0	/* success, same file */

#define GETFILE_OPEN_OTHER -1	/* success, opened another file */

#define GETFILE_UNUSED	    8

#define GETFILE_SUCCESS(x)  ((x) <= 0)

#define BLN_CURBUF	1	/* may re-use curbuf for new buffer */

#define BLN_LISTED	2	/* put new buffer in buffer list */

#define BLN_DUMMY	4	/* allocating dummy buffer */

#define BLN_NEW		8	/* create a new buffer */

#define BLN_NOOPT	16	/* don't copy options to existing buffer */

#define BLN_DUMMY_OK	32	/* also find an existing dummy buffer */

#define KEY_OPEN_FORW	0x101

#define KEY_OPEN_BACK	0x102

#define KEY_COMPLETE	0x103	/* end of completion */

#define REMAP_YES	0	/* allow remapping */

#define REMAP_NONE	-1	/* no remapping */

#define REMAP_SCRIPT	-2	/* remap script-local mappings only */

#define REMAP_SKIP	-3	/* no remapping for first char */

#define SHELL_FILTER	1	/* filtering text */

#define SHELL_EXPAND	2	/* expanding wildcards */

#define SHELL_COOKED	4	/* set term to cooked mode */

#define SHELL_DOOUT	8	/* redirecting output */

#define SHELL_SILENT	16	/* don't print error returned by command */

#define SHELL_READ	32	/* read lines and insert into buffer */

#define SHELL_WRITE	64	/* write lines from buffer */

#define NODE_NORMAL	0	/* file or directory, check with mch_isdir()*/

#define NODE_WRITABLE	1	/* something we can write to (character
				   device, fifo, socket, ..) */

#define NODE_OTHER	2	/* non-writable thing (e.g., block device) */

#define READ_NEW	0x01	/* read a file into a new buffer */

#define READ_FILTER	0x02	/* read filter output */

#define READ_STDIN	0x04	/* read from stdin */

#define READ_BUFFER	0x08	/* read from curbuf (converting stdin) */

#define READ_DUMMY	0x10	/* reading into a dummy buffer */

#define READ_KEEP_UNDO	0x20	/* keep undo info */

#define READ_FIFO	0x40	/* read from fifo or socket */

#define INDENT_SET	1	/* set indent */

#define INDENT_INC	2	/* increase indent */

#define INDENT_DEC	3	/* decrease indent */

#define FM_BACKWARD	0x01	/* search backwards */

#define FM_FORWARD	0x02	/* search forwards */

#define FM_BLOCKSTOP	0x04	/* stop at start/end of block */

#define FM_SKIPCOMM	0x08	/* skip comments */

#define DOBUF_GOTO	0	/* go to specified buffer */

#define DOBUF_SPLIT	1	/* split window and go to specified buffer */

#define DOBUF_UNLOAD	2	/* unload specified buffer(s) */

#define DOBUF_DEL	3	/* delete specified buffer(s) from buflist */

#define DOBUF_WIPE	4	/* delete specified buffer(s) really */

#define DOBUF_CURRENT	0	/* "count" buffer from current buffer */

#define DOBUF_FIRST	1	/* "count" buffer from first buffer */

#define DOBUF_LAST	2	/* "count" buffer from last buffer */

#define DOBUF_MOD	3	/* "count" mod. buffer from current buffer */

#define RE_SEARCH	0	/* save/use pat in/from search_pattern */

#define RE_SUBST	1	/* save/use pat in/from subst_pattern */

#define RE_BOTH		2	/* save pat in both patterns */

#define RE_LAST		2	/* use last used pattern if "pat" is NULL */

#define RE_MAGIC	1	/* 'magic' option */

#define RE_STRING	2	/* match in string instead of buffer text */

#define RE_STRICT	4	/* don't allow [abc] without ] */

#define RE_AUTO		8	/* automatic engine selection */

#define FPC_SAME	1	/* both exist and are the same file. */

#define FPC_DIFF	2	/* both exist and are different files. */

#define FPC_NOTX	4	/* both don't exist. */

#define FPC_DIFFX	6	/* one of them doesn't exist. */

#define FPC_SAMEX	7	/* both don't exist and file names are same. */

#define ECMD_HIDE	0x01	/* don't free the current buffer */

#define ECMD_SET_HELP	0x02	/* set b_help flag of (new) buffer before
				   opening file */

#define ECMD_OLDBUF	0x04	/* use existing buffer if it exists */

#define ECMD_FORCEIT	0x08	/* ! used in Ex command */

#define ECMD_ADDBUF	0x10	/* don't edit, just add to buffer list */

#define ECMD_LASTL	(linenr_T)0	/* use last position in loaded file */

#define ECMD_LAST	(linenr_T)-1	/* use last position in all files */

#define ECMD_ONE	(linenr_T)1	/* use first line */

#define DOCMD_VERBOSE	0x01	/* included command in error message */

#define DOCMD_NOWAIT	0x02	/* don't call wait_return() and friends */

#define DOCMD_REPEAT	0x04	/* repeat exec. until getline() returns NULL */

#define DOCMD_KEYTYPED	0x08	/* don't reset KeyTyped */

#define DOCMD_EXCRESET	0x10	/* reset exception environment (for debugging)*/

#define DOCMD_KEEPLINE  0x20	/* keep typed line for repeating with "." */

#define BL_WHITE	1	/* cursor on first non-white in the line */

#define BL_SOL		2	/* use 'sol' option */

#define BL_FIX		4	/* don't leave cursor on a NUL */

#define MFS_ALL		1	/* also sync blocks with negative numbers */

#define MFS_STOP	2	/* stop syncing when a character is available */

#define MFS_FLUSH	4	/* flushed file to disk */

#define MFS_ZERO	8	/* only write block 0 */

#define BCO_ENTER	1	/* going to enter the buffer */

#define BCO_ALWAYS	2	/* always copy the options */

#define BCO_NOHELP	4	/* don't touch the help related options */

#define PUT_FIXINDENT	1	/* make indent look nice */

#define PUT_CURSEND	2	/* leave cursor after end of new text */

#define PUT_CURSLINE	4	/* leave cursor on last line of new text */

#define PUT_LINE	8	/* put register as lines */

#define PUT_LINE_SPLIT	16	/* split line for linewise register */

#define PUT_LINE_FORWARD 32	/* put linewise register below Visual sel. */

#define SIN_CHANGED	1	/* call changed_bytes() when line changed */

#define SIN_INSERT	2	/* insert indent before existing text */

#define SIN_UNDO	4	/* save line for undo before changing it */

#define INSCHAR_FORMAT	1	/* force formatting */

#define INSCHAR_DO_COM	2	/* format comments */

#define INSCHAR_CTRLV	4	/* char typed just after CTRL-V */

#define INSCHAR_NO_FEX	8	/* don't use 'formatexpr' */

#define INSCHAR_COM_LIST 16	/* format comments with list/2nd line indent */

#define OPENLINE_DELSPACES  1	/* delete spaces after cursor */

#define OPENLINE_DO_COM	    2	/* format comments */

#define OPENLINE_KEEPTRAIL  4	/* keep trailing spaces */

#define OPENLINE_MARKFIX    8	/* fix mark positions */

#define OPENLINE_COM_LIST  16	/* format comments with list/2nd line indent */

#define HIST_CMD	0	/* colon commands */

#define HIST_SEARCH	1	/* search commands */

#define HIST_EXPR	2	/* expressions (from entering = register) */

#define HIST_INPUT	3	/* input() lines */

#define HIST_DEBUG	4	/* debug commands */

#define HIST_COUNT	5	/* number of history tables */

#define BARTYPE_VERSION 1

#define BARTYPE_HISTORY 2

#define BARTYPE_REGISTER 3

#define BARTYPE_MARK 4

#define VIMINFO_VERSION 4

#define VIMINFO_VERSION_WITH_HISTORY 2

#define VIMINFO_VERSION_WITH_REGISTERS 3

#define VIMINFO_VERSION_WITH_MARKS 4

#define DT_TAG		1	/* jump to newer position or same tag again */

#define DT_POP		2	/* jump to older position */

#define DT_NEXT		3	/* jump to next match of same tag */

#define DT_PREV		4	/* jump to previous match of same tag */

#define DT_FIRST	5	/* jump to first match of same tag */

#define DT_LAST		6	/* jump to first match of same tag */

#define DT_SELECT	7	/* jump to selection from list */

#define DT_HELP		8	/* like DT_TAG, but no wildcards */

#define DT_JUMP		9	/* jump to new tag or selection from list */

#define DT_CSCOPE	10	/* cscope find command (like tjump) */

#define DT_LTAG		11	/* tag using location list */

#define DT_FREE		99	/* free cached matches */

#define TAG_HELP	1	/* only search for help tags */

#define TAG_NAMES	2	/* only return name of tag */

#define	TAG_REGEXP	4	/* use tag pattern as regexp */

#define	TAG_NOIC	8	/* don't always ignore case */

#define TAG_VERBOSE	32	/* message verbosity */

#define TAG_INS_COMP	64	/* Currently doing insert completion */

#define TAG_KEEP_LANG	128	/* keep current language */

#define TAG_MANY	300	/* When finding many tags (for completion),
				   find up to this many tags */

#define VIM_GENERIC	0

#define VIM_ERROR	1

#define VIM_WARNING	2

#define VIM_INFO	3

#define VIM_QUESTION	4

#define VIM_LAST_TYPE	4	/* sentinel value */

#define VIM_YES		2

#define VIM_NO		3

#define VIM_CANCEL	4

#define VIM_ALL		5

#define VIM_DISCARDALL  6

#define WSP_ROOM	1	/* require enough room */

#define WSP_VERT	2	/* split vertically */

#define WSP_TOP		4	/* window at top-left of shell */

#define WSP_BOT		8	/* window at bottom-right of shell */

#define WSP_HELP	16	/* creating the help window */

#define WSP_BELOW	32	/* put new window below/right */

#define WSP_ABOVE	64	/* put new window above/left */

#define WSP_NEWLOC	128	/* don't copy location list */

#define RESIZE_VERT	1	/* resize vertically */

#define RESIZE_HOR	2	/* resize horizontally */

#define RESIZE_BOTH	15	/* resize in both directions */

#define CCGD_AW		1	/* do autowrite if buffer was changed */

#define CCGD_MULTWIN	2	/* check also when several wins for the buf */

#define CCGD_FORCEIT	4	/* ! used */

#define CCGD_ALLBUF	8	/* may write all buffers */

#define CCGD_EXCMD	16	/* may suggest using ! */

#define OPT_FREE	1	/* free old value if it was allocated */

#define OPT_GLOBAL	2	/* use global value */

#define OPT_LOCAL	4	/* use local value */

#define OPT_MODELINE	8	/* option in modeline */

#define OPT_WINONLY	16	/* only set window-local options */

#define OPT_NOWIN	32	/* don't set window-local options */

#define DLG_BUTTON_SEP	'\n'

#define DLG_HOTKEY_CHAR	'&'

#define NO_SCREEN	2	/* no screen updating yet */

#define NO_BUFFERS	1	/* not all buffers loaded yet */

#define SEA_NONE	0	/* don't use dialog */

#define SEA_DIALOG	1	/* use dialog when possible */

#define SEA_QUIT	2	/* quit editing the file */

#define SEA_RECOVER	3	/* recover the file */

#define MIN_SWAP_PAGE_SIZE 1048

#define MAX_SWAP_PAGE_SIZE 50000

#define SID_MODELINE	-1	/* when using a modeline */

#define SID_CMDARG	-2	/* for "--cmd" argument */

#define SID_CARG	-3	/* for "-c" argument */

#define SID_ENV		-4	/* for sourcing environment variable */

#define SID_ERROR	-5	/* option was reset because of an error */

#define SID_NONE	-6	/* don't set scriptID */

#define HL_FLAGS {'8', '~', '@', 'd', 'e', 'h', 'i', 'l', 'm', 'M', \
		  'n', 'N', 'r', 's', 'S', 'c', 't', 'v', 'V', 'w', 'W', \
		  'f', 'F', 'A', 'C', 'D', 'T', '-', '>', \
		  'B', 'P', 'R', 'L', \
		  '+', '=', 'x', 'X', '*', '#', '_', '!', '.', 'o', 'q', \
		  'z', 'Z'}

#define MAYBE	2	    /* sometimes used for a variant on TRUE */

#define OP_NOP		0	/* no pending operation */

#define OP_DELETE	1	/* "d"  delete operator */

#define OP_YANK		2	/* "y"  yank operator */

#define OP_CHANGE	3	/* "c"  change operator */

#define OP_LSHIFT	4	/* "<"  left shift operator */

#define OP_RSHIFT	5	/* ">"  right shift operator */

#define OP_FILTER	6	/* "!"  filter operator */

#define OP_TILDE	7	/* "g~" switch case operator */

#define OP_INDENT	8	/* "="  indent operator */

#define OP_FORMAT	9	/* "gq" format operator */

#define OP_COLON	10	/* ":"  colon operator */

#define OP_UPPER	11	/* "gU" make upper case operator */

#define OP_LOWER	12	/* "gu" make lower case operator */

#define OP_JOIN		13	/* "J"  join operator, only for Visual mode */

#define OP_JOIN_NS	14	/* "gJ"  join operator, only for Visual mode */

#define OP_ROT13	15	/* "g?" rot-13 encoding */

#define OP_REPLACE	16	/* "r"  replace chars, only for Visual mode */

#define OP_INSERT	17	/* "I"  Insert column, only for Visual mode */

#define OP_APPEND	18	/* "A"  Append column, only for Visual mode */

#define OP_FOLD		19	/* "zf" define a fold */

#define OP_FOLDOPEN	20	/* "zo" open folds */

#define OP_FOLDOPENREC	21	/* "zO" open folds recursively */

#define OP_FOLDCLOSE	22	/* "zc" close folds */

#define OP_FOLDCLOSEREC	23	/* "zC" close folds recursively */

#define OP_FOLDDEL	24	/* "zd" delete folds */

#define OP_FOLDDELREC	25	/* "zD" delete folds recursively */

#define OP_FORMAT2	26	/* "gw" format operator, keeps cursor pos */

#define OP_FUNCTION	27	/* "g@" call 'operatorfunc' */

#define OP_NR_ADD	28	/* "<C-A>" Add to the number or alphabetic
				   character (OP_ADD conflicts with Perl) */

#define OP_NR_SUB	29	/* "<C-X>" Subtract from the number or
				   alphabetic character */

#define MCHAR	0		/* character-wise movement/register */

#define MLINE	1		/* line-wise movement/register */

#define MBLOCK	2		/* block-wise register */

#define MAUTO	0xff		/* Decide between MLINE/MCHAR */

#define MIN_COLUMNS	12	/* minimal columns for screen */

#define MIN_LINES	2	/* minimal lines for screen */

#define STATUS_HEIGHT	1	/* height of a status line under a window */

#define QF_WINHEIGHT	10	/* default height for quickfix window */

#define LSIZE	    512		/* max. size of a line in the tags file */

#define IOSIZE	   (1024+1)	/* file i/o and sprintf buffer size */

#define DIALOG_MSG_SIZE 1000	/* buffer size for dialog_msg() */

#define FOLD_TEXT_LEN  51	/* buffer size for get_foldtext() */

#define TBUFSZ 2048		/* buffer size for termcap entry */

#define MAXMAPLEN   50

#define UNDO_HASH_SIZE 32

#define STRLEN(s)	    strlen((char *)(s))

#define STRCPY(d, s)	    strcpy((char *)(d), (char *)(s))

#define STRNCPY(d, s, n)    strncpy((char *)(d), (char *)(s), (size_t)(n))

#define STRCMP(d, s)	    strcmp((char *)(d), (char *)(s))

#define STRNCMP(d, s, n)    strncmp((char *)(d), (char *)(s), (size_t)(n))

#define STRMOVE(d, s)	    mch_memmove((d), (s), STRLEN(s) + 1)

#define STRCAT(d, s)	    strcat((char *)(d), (char *)(s))

#define STRNCAT(d, s, n)    strncat((char *)(d), (char *)(s), (size_t)(n))

#define MSG(s)			    msg((char_u *)(s))

#define MSG_ATTR(s, attr)	    msg_attr((char_u *)(s), (attr))

#define EMSG(s)			    emsg((char_u *)(s))

#define EMSG2(s, p)		    emsg2((char_u *)(s), (char_u *)(p))

#define EMSG3(s, p, q)		    emsg3((char_u *)(s), (char_u *)(p), (char_u *)(q))

#define EMSGN(s, n)		    emsgn((char_u *)(s), (long)(n))

#define EMSGU(s, n)		    emsgu((char_u *)(s), (long_u)(n))

#define IEMSG(s)		    iemsg((char_u *)(s))

#define IEMSG2(s, p)		    iemsg2((char_u *)(s), (char_u *)(p))

#define IEMSGN(s, n)		    iemsgn((char_u *)(s), (long)(n))

#define OUT_STR(s)		    out_str((char_u *)(s))

#define OUT_STR_NF(s)		    out_str_nf((char_u *)(s))

#define MSG_PUTS(s)		    msg_puts((char_u *)(s))

#define MSG_PUTS_ATTR(s, a)	    msg_puts_attr((char_u *)(s), (a))

#define MSG_PUTS_TITLE(s)	    msg_puts_title((char_u *)(s))

#define MSG_PUTS_LONG(s)	    msg_puts_long_attr((char_u *)(s), 0)

#define MSG_PUTS_LONG_ATTR(s, a)    msg_puts_long_attr((char_u *)(s), (a))

#define MAXLNUM (0x7fffffffL)		/* maximum (invalid) line number */

#define SHOWCMD_COLS 10			/* columns needed by shown command */

#define STL_MAX_ITEM 80			/* max nr of %<flag> in statusline */

#define fnamecmp(x, y) vim_fnamecmp((char_u *)(x), (char_u *)(y))

#define fnamencmp(x, y, n) vim_fnamencmp((char_u *)(x), (char_u *)(y), (size_t)(n))

#define HL_ATTR(n)	highlight_attr[(int)(n)]

#define TERM_STR(n)	term_strings[(int)(n)]

#define PROF_NONE	0	/* profiling not started */

#define PROF_YES	1	/* profiling busy */

#define PROF_PAUSED	2	/* profiling paused */

#define VALID_PATH		1

#define VALID_HEAD		2

#define VV_COUNT	0

#define VV_COUNT1	1

#define VV_PREVCOUNT	2

#define VV_ERRMSG	3

#define VV_WARNINGMSG	4

#define VV_STATUSMSG	5

#define VV_SHELL_ERROR	6

#define VV_THIS_SESSION	7

#define VV_VERSION	8

#define VV_LNUM		9

#define VV_TERMRESPONSE	10

#define VV_FNAME	11

#define VV_LANG		12

#define VV_LC_TIME	13

#define VV_CTYPE	14

#define VV_CC_FROM	15

#define VV_CC_TO	16

#define VV_FNAME_IN	17

#define VV_FNAME_OUT	18

#define VV_FNAME_NEW	19

#define VV_FNAME_DIFF	20

#define VV_CMDARG	21

#define VV_FOLDSTART	22

#define VV_FOLDEND	23

#define VV_FOLDDASHES	24

#define VV_FOLDLEVEL	25

#define VV_PROGNAME	26

#define VV_SEND_SERVER	27

#define VV_DYING	28

#define VV_EXCEPTION	29

#define VV_THROWPOINT	30

#define VV_REG		31

#define VV_CMDBANG	32

#define VV_INSERTMODE	33

#define VV_VAL		34

#define VV_KEY		35

#define VV_PROFILING	36

#define VV_FCS_REASON	37

#define VV_FCS_CHOICE	38

#define VV_BEVAL_BUFNR	39

#define VV_BEVAL_WINNR	40

#define VV_BEVAL_WINID	41

#define VV_BEVAL_LNUM	42

#define VV_BEVAL_COL	43

#define VV_BEVAL_TEXT	44

#define VV_SCROLLSTART	45

#define VV_SWAPNAME	46

#define VV_SWAPCHOICE	47

#define VV_SWAPCOMMAND	48

#define VV_CHAR		49

#define VV_MOUSE_WIN	50

#define VV_MOUSE_WINID	51

#define VV_MOUSE_LNUM   52

#define VV_MOUSE_COL	53

#define VV_OP		54

#define VV_SEARCHFORWARD 55

#define VV_HLSEARCH	56

#define VV_OLDFILES	57

#define VV_WINDOWID	58

#define VV_PROGPATH	59

#define VV_COMPLETED_ITEM 60

#define VV_OPTION_NEW   61

#define VV_OPTION_OLD   62

#define VV_OPTION_TYPE  63

#define VV_ERRORS	64

#define VV_FALSE	65

#define VV_TRUE		66

#define VV_NULL		67

#define VV_NONE		68

#define VV_VIM_DID_ENTER 69

#define VV_TESTING	70

#define VV_TYPE_NUMBER	71

#define VV_TYPE_STRING	72

#define VV_TYPE_FUNC	73

#define VV_TYPE_LIST	74

#define VV_TYPE_DICT	75

#define VV_TYPE_FLOAT	76

#define VV_TYPE_BOOL	77

#define VV_TYPE_NONE	78

#define VV_TYPE_JOB	79

#define VV_TYPE_CHANNEL	80

#define VV_TERMRFGRESP	81

#define VV_TERMRBGRESP	82

#define VV_TERMU7RESP	83

#define VV_TERMSTYLERESP 84

#define VV_TERMBLINKRESP 85

#define VV_EVENT	86

#define VV_LEN		87	/* number of v: vars */

#define VVAL_FALSE	0L

#define VVAL_TRUE	1L

#define VVAL_NONE	2L

#define VVAL_NULL	3L

#define VAR_TYPE_NUMBER	    0

#define VAR_TYPE_STRING	    1

#define VAR_TYPE_FUNC	    2

#define VAR_TYPE_LIST	    3

#define VAR_TYPE_DICT	    4

#define VAR_TYPE_FLOAT	    5

#define VAR_TYPE_BOOL	    6

#define VAR_TYPE_NONE	    7

#define VAR_TYPE_JOB	    8

#define VAR_TYPE_CHANNEL    9

#define SIGN_BYTE 1	    /* byte value used where sign is displayed;
			       attribute value is sign type */

#define SIGNAL_BLOCK	-1

#define SIGNAL_UNBLOCK  -2

#define VGR_GLOBAL	1

#define VGR_NOJUMP	2

#define BAD_REPLACE	'?'	/* replace it with '?' (default) */

#define BAD_KEEP	-1	/* leave it */

#define BAD_DROP	-2	/* erase it */

#define DOSO_NONE	0

#define DOSO_VIMRC	1	/* loading vimrc file */

#define DOSO_GVIMRC	2	/* loading gvimrc file */

#define VIF_WANT_INFO		1	/* load non-mark info */

#define VIF_WANT_MARKS		2	/* load file marks */

#define VIF_FORCEIT		4	/* overwrite info already read */

#define VIF_GET_OLDFILES	8	/* load v:oldfiles */

#define BFA_DEL		1	/* buffer is going to be deleted */

#define BFA_WIPE	2	/* buffer is going to be wiped out */

#define BFA_KEEP_UNDO	4	/* do not free undo information */

#define MSCR_DOWN	0	/* DOWN must be FALSE */

#define MSCR_UP		1

#define MSCR_LEFT	-1

#define MSCR_RIGHT	-2

#define KEYLEN_PART_KEY -1	/* keylen value for incomplete key-code */

#define KEYLEN_PART_MAP -2	/* keylen value for incomplete mapping */

#define KEYLEN_REMOVED  9999	/* keylen value for removed sequence */

#define FILEINFO_OK	     0

#define FILEINFO_ENC_FAIL    1	/* enc_to_utf16() failed */

#define FILEINFO_READ_FAIL   2	/* CreateFile() failed */

#define FILEINFO_INFO_FAIL   3	/* GetFileInformationByHandle() failed */

#define SOPT_BOOL	0x01	/* Boolean option */

#define SOPT_NUM	0x02	/* Number option */

#define SOPT_STRING	0x04	/* String option */

#define SOPT_GLOBAL	0x08	/* Option has global value */

#define SOPT_WIN	0x10	/* Option has window-local value */

#define SOPT_BUF	0x20	/* Option has buffer-local value */

#define SOPT_UNSET	0x40	/* Option does not have local value set */

#define SREQ_GLOBAL	0	/* Request global option */

#define SREQ_WIN	1	/* Request window-local option */

#define SREQ_BUF	2	/* Request buffer-local option */

#define GREG_NO_EXPR	1	/* Do not allow expression register */

#define GREG_EXPR_SRC	2	/* Return expression itself for "=" register */

#define GREG_LIST	4	/* Return list */

#define AUTOLOAD_CHAR '#'

#define JSON_JS		1   /* use JS instead of JSON */

#define JSON_NO_NONE	2   /* v:none item not allowed */

#define JSON_NL		4   /* append a NL */

#define DIP_ALL	    0x01	/* all matches, not just the first one */

#define DIP_DIR	    0x02	/* find directories instead of files. */

#define DIP_ERR	    0x04	/* give an error message when none found. */

#define DIP_START   0x08	/* also use "start" directory in 'packpath' */

#define DIP_OPT	    0x10	/* also use "opt" directory in 'packpath' */

#define DIP_NORTP   0x20	/* do not use 'runtimepath' */

#define DIP_NOAFTER 0x40	/* skip "after" directories */

#define DIP_AFTER   0x80	/* only use "after" directories */

#define LOWEST_WIN_ID 1000

#define COPYID_INC 2

#define COPYID_MASK (~0x1)

#define TFN_INT		1	/* internal function name OK */

#define TFN_QUIET	2	/* no error messages */

#define TFN_NO_AUTOLOAD	4	/* do not use script autoloading */

#define TFN_NO_DEREF	8	/* do not dereference a Funcref */

#define TFN_READ_ONLY	16	/* will not change the var */

#define GLV_QUIET	TFN_QUIET	/* no error messages */

#define GLV_NO_AUTOLOAD	TFN_NO_AUTOLOAD	/* do not use script autoloading */

#define GLV_READ_ONLY	TFN_READ_ONLY	/* will not change the var */

#define DO_NOT_FREE_CNT 99999	/* refcount for dict or list that should not
				   be freed. */

#define ERROR_UNKNOWN	0

#define ERROR_TOOMANY	1

#define ERROR_TOOFEW	2

#define ERROR_SCRIPT	3

#define ERROR_DICT	4

#define ERROR_NONE	5

#define ERROR_OTHER	6

#define ERROR_DELETED	7

#define FNE_INCL_BR	1	/* include [] in name */

#define FNE_CHECK_START	2	/* check name starts with valid character */

#define REPLACE_CR_NCHAR    -1

#define REPLACE_NL_NCHAR    -2

#define USE_EXE_NAME		/* use argv[0] for $VIM */

#define SYNC_DUP_CLOSE		/* sync() a file with dup() and close() */

#define HAVE_STRICMP

#define HAVE_STRNICMP

#define FEAT_SHORTCUT		/* resolve shortcuts */

#define USE_FNAME_CASE		/* adjust case of file names */

#define HAVE_TOTAL_MEM

#define HAVE_PUTENV		/* at least Bcc 5.2 and MSC have it */

#define BROKEN_TOUPPER

#define FNAME_ILLEGAL "\"*?><|" /* illegal characters in a file name */

#define MAXPATHL	1024

#define TEMPNAMELEN	_MAX_PATH	/* length of temp file name path */

#define ASSERT_POINTER(p, type) \
    ASSERT(((p) != NULL)  &&  IsValidAddress((p), sizeof(type), FALSE))

#define ASSERT_NULL_OR_POINTER(p, type) \
    ASSERT(((p) == NULL)  ||  IsValidAddress((p), sizeof(type), FALSE))

#define mch_getenv(x) (char_u *)getenv((char *)(x))

#define	USE_TMPNAM

#define POSIX	    /* Used by pty.c */

#define EnhancedBP_H

#define DOPY_FUNC "_vim_pydo"

#define PyErr_SET_STRING(exc, str) PyErr_SetString(exc, _(str))

#define PyErr_SetVim(str) PyErr_SetString(VimError, str)

#define PyErr_SET_VIM(str) PyErr_SET_STRING(VimError, str)

#define PyErr_FORMAT(exc, str, arg) PyErr_Format(exc, _(str), arg)

#define PyErr_FORMAT2(exc, str, arg1, arg2) PyErr_Format(exc, _(str), arg1,arg2)

#define PyErr_VIM_FORMAT(str, arg) PyErr_FORMAT(VimError, str, arg)

#define Py_TYPE_NAME(obj) (obj->ob_type->tp_name == NULL \
	? "(NULL)" \
	: obj->ob_type->tp_name)

#define RAISE_NO_EMPTY_KEYS PyErr_SET_STRING(PyExc_ValueError, \
					    N_("empty keys are not allowed"))

#define RAISE_LOCKED_DICTIONARY PyErr_SET_VIM(N_("dictionary is locked"))

#define RAISE_LOCKED_LIST PyErr_SET_VIM(N_("list is locked"))

#define RAISE_UNDO_FAIL PyErr_SET_VIM(N_("cannot save undo information"))

#define RAISE_DELETE_LINE_FAIL PyErr_SET_VIM(N_("cannot delete line"))

#define RAISE_INSERT_LINE_FAIL PyErr_SET_VIM(N_("cannot insert line"))

#define RAISE_REPLACE_LINE_FAIL PyErr_SET_VIM(N_("cannot replace line"))

#define RAISE_KEY_ADD_FAIL(key) \
    PyErr_VIM_FORMAT(N_("failed to add key '%s' to dictionary"), key)

#define RAISE_INVALID_INDEX_TYPE(idx) \
    PyErr_FORMAT(PyExc_TypeError, N_("index must be int or slice, not %s"), \
	    Py_TYPE_NAME(idx));

#define INVALID_BUFFER_VALUE ((buf_T *)(-1))

#define INVALID_WINDOW_VALUE ((win_T *)(-1))

#define INVALID_TABPAGE_VALUE ((tabpage_T *)(-1))

#define NEW_DICTIONARY(dict) DictionaryNew(&DictionaryType, dict)

#define NEW_LIST(list) ListNew(&ListType, list)

#define NEW_FUNCTION(name, argc, argv, self, pt_auto) \
    FunctionNew(&FunctionType, (name), (argc), (argv), (self), (pt_auto))

#define ADD_OBJECT(m, name, obj) \
    if (PyModule_AddObject(m, name, obj)) \
	return -1;

#define ADD_CHECKED_OBJECT(m, name, obj) \
    { \
	PyObject	*valObject = obj; \
	if (!valObject) \
	    return -1; \
	ADD_OBJECT(m, name, valObject); \
    }

#define GA_EMPTY    {0, 0, 0, 0, NULL}

#define NMARKS		('z' - 'a' + 1)	/* max. # of named marks */

#define JUMPLISTSIZE	100		/* max. # of marks in jump list */

#define TAGSTACKSIZE	20		/* max. # of tags in tag stack */

#define UH_CHANGED  0x01	/* b_changed flag before undo/after redo */

#define UH_EMPTYBUF 0x02	/* buffer was empty */

#define ALIGN_MASK (ALIGN_SIZE - 1)

#define MHT_INIT_SIZE   64

#define XP_BS_NONE	0	/* nothing special for backslashes */

#define XP_BS_ONE	1	/* uses one backslash before a space */

#define XP_BS_THREE	2	/* uses three backslashes before a space */

#define MF_SEED_LEN	8

#define ML_CHNK_ADDLINE 1

#define ML_CHNK_DELLINE 2

#define ML_CHNK_UPDLINE 3

#define SIGN_ANY	0

#define SIGN_LINEHL	1

#define SIGN_ICON	2

#define SIGN_TEXT	3

#define ALIST(win)	(win)->w_alist

#define GARGLIST	((aentry_T *)global_alist.al_ga.ga_data)

#define ARGLIST		((aentry_T *)ALIST(curwin)->al_ga.ga_data)

#define WARGLIST(wp)	((aentry_T *)ALIST(wp)->al_ga.ga_data)

#define AARGLIST(al)	((aentry_T *)((al)->al_ga.ga_data))

#define GARGCOUNT	(global_alist.al_ga.ga_len)

#define ARGCOUNT	(ALIST(curwin)->al_ga.ga_len)

#define WARGCOUNT(wp)	(ALIST(wp)->al_ga.ga_len)

#define CSTACK_LEN	50

#define CONV_NONE		0

#define CONV_TO_UTF8		1

#define CONV_9_TO_UTF8		2

#define CONV_TO_LATIN1		3

#define CONV_TO_LATIN9		4

#define CONV_ICONV		5

#define HI_KEY_REMOVED &hash_removed

#define HASHITEM_EMPTY(hi) ((hi)->hi_key == NULL || (hi)->hi_key == &hash_removed)

#define HT_INIT_SIZE 16

#define VARNUM_MIN	    LONG_MIN

#define VARNUM_MAX	    LONG_MAX

#define UVARNUM_MAX	    ULONG_MAX

#define VAR_SCOPE     1	/* a:, v:, s:, etc. scope dictionaries */

#define VAR_DEF_SCOPE 2	/* l:, g: scope dictionaries: here funcrefs are not
			   allowed to mask existing functions */

#define VAR_LOCKED  1	/* locked with lock(), can use unlock() */

#define VAR_FIXED   2	/* locked forever */

#define DI_FLAGS_RO	1  /* "di_flags" value: read-only variable */

#define DI_FLAGS_RO_SBX 2  /* "di_flags" value: read-only in the sandbox */

#define DI_FLAGS_FIX	4  /* "di_flags" value: fixed: no :unlet or remove() */

#define DI_FLAGS_LOCK	8  /* "di_flags" value: locked variable */

#define DI_FLAGS_ALLOC	16 /* "di_flags" value: separately allocated */

#define MAX_FUNC_ARGS	20	/* maximum number of function arguments */

#define VAR_SHORT_LEN	20	/* short variable name length */

#define FIXVAR_CNT	12	/* number of fixed variables */

#define CH_PART_FD(part)	ch_part[part].ch_fd

#define INVALID_FD	(-1)

#define JO_MODE		    0x0001	/* channel mode */

#define JO_IN_MODE	    0x0002	/* stdin mode */

#define JO_OUT_MODE	    0x0004	/* stdout mode */

#define JO_ERR_MODE	    0x0008	/* stderr mode */

#define JO_CALLBACK	    0x0010	/* channel callback */

#define JO_OUT_CALLBACK	    0x0020	/* stdout callback */

#define JO_ERR_CALLBACK	    0x0040	/* stderr callback */

#define JO_CLOSE_CALLBACK   0x0080	/* "close_cb" */

#define JO_WAITTIME	    0x0100	/* only for ch_open() */

#define JO_TIMEOUT	    0x0200	/* all timeouts */

#define JO_OUT_TIMEOUT	    0x0400	/* stdout timeouts */

#define JO_ERR_TIMEOUT	    0x0800	/* stderr timeouts */

#define JO_PART		    0x1000	/* "part" */

#define JO_ID		    0x2000	/* "id" */

#define JO_STOPONEXIT	    0x4000	/* "stoponexit" */

#define JO_EXIT_CB	    0x8000	/* "exit_cb" */

#define JO_OUT_IO	    0x10000	/* "out_io" */

#define JO_ERR_IO	    0x20000	/* "err_io" (JO_OUT_IO << 1) */

#define JO_IN_IO	    0x40000	/* "in_io" (JO_OUT_IO << 2) */

#define JO_OUT_NAME	    0x80000	/* "out_name" */

#define JO_ERR_NAME	    0x100000	/* "err_name" (JO_OUT_NAME << 1) */

#define JO_IN_NAME	    0x200000	/* "in_name" (JO_OUT_NAME << 2) */

#define JO_IN_TOP	    0x400000	/* "in_top" */

#define JO_IN_BOT	    0x800000	/* "in_bot" */

#define JO_OUT_BUF	    0x1000000	/* "out_buf" */

#define JO_ERR_BUF	    0x2000000	/* "err_buf" (JO_OUT_BUF << 1) */

#define JO_IN_BUF	    0x4000000	/* "in_buf" (JO_OUT_BUF << 2) */

#define JO_CHANNEL	    0x8000000	/* "channel" */

#define JO_BLOCK_WRITE	    0x10000000	/* "block_write" */

#define JO_OUT_MODIFIABLE   0x20000000	/* "out_modifiable" */

#define JO_ERR_MODIFIABLE   0x40000000	/* "err_modifiable" (JO_OUT_ << 1) */

#define JO_ALL		    0x7fffffff

#define JO2_OUT_MSG	    0x0001	/* "out_msg" */

#define JO2_ERR_MSG	    0x0002	/* "err_msg" (JO_OUT_ << 1) */

#define JO2_TERM_NAME	    0x0004	/* "term_name" */

#define JO2_TERM_FINISH	    0x0008	/* "term_finish" */

#define JO2_ENV		    0x0010	/* "env" */

#define JO2_CWD		    0x0020	/* "cwd" */

#define JO2_TERM_ROWS	    0x0040	/* "term_rows" */

#define JO2_TERM_COLS	    0x0080	/* "term_cols" */

#define JO2_VERTICAL	    0x0100	/* "vertical" */

#define JO2_CURWIN	    0x0200	/* "curwin" */

#define JO2_HIDDEN	    0x0400	/* "hidden" */

#define JO2_TERM_OPENCMD    0x0800	/* "term_opencmd" */

#define JO2_EOF_CHARS	    0x1000	/* "eof_chars" */

#define JO2_ALL		    0x1FFF

#define JO_MODE_ALL	(JO_MODE + JO_IN_MODE + JO_OUT_MODE + JO_ERR_MODE)

#define JO_CB_ALL \
    (JO_CALLBACK + JO_OUT_CALLBACK + JO_ERR_CALLBACK + JO_CLOSE_CALLBACK)

#define JO_TIMEOUT_ALL	(JO_TIMEOUT + JO_OUT_TIMEOUT + JO_ERR_TIMEOUT)

#define SYNSPL_DEFAULT	0	/* spell check if @Spell not defined */

#define SYNSPL_TOP	1	/* spell check toplevel text */

#define SYNSPL_NOTOP	2	/* don't spell check toplevel text */

#define SNAP_HELP_IDX	0

#define FR_LEAF	0	/* frame is a leaf */

#define FR_ROW	1	/* frame with a row of windows */

#define FR_COL	2	/* frame with a column of windows */

#define MAXPOSMATCH 8

#define CA_COMMAND_BUSY	    1	/* skip restarting edit() once */

#define CA_NO_ADJ_OP_END    2	/* don't adjust operator end */

#define MENU_INDEX_INVALID	-1

#define MENU_INDEX_NORMAL	0

#define MENU_INDEX_VISUAL	1

#define MENU_INDEX_SELECT	2

#define MENU_INDEX_OP_PENDING	3

#define MENU_INDEX_INSERT	4

#define MENU_INDEX_CMDLINE	5

#define MENU_INDEX_TIP		6

#define MENU_MODES		7

#define MENU_NORMAL_MODE	(1 << MENU_INDEX_NORMAL)

#define MENU_VISUAL_MODE	(1 << MENU_INDEX_VISUAL)

#define MENU_SELECT_MODE	(1 << MENU_INDEX_SELECT)

#define MENU_OP_PENDING_MODE	(1 << MENU_INDEX_OP_PENDING)

#define MENU_INSERT_MODE	(1 << MENU_INDEX_INSERT)

#define MENU_CMDLINE_MODE	(1 << MENU_INDEX_CMDLINE)

#define MENU_TIP_MODE		(1 << MENU_INDEX_TIP)

#define MENU_ALL_MODES		((1 << MENU_INDEX_TIP) - 1)

#define MNU_HIDDEN_CHAR		']'

#define PRINT_NUMBER_WIDTH 8

#define CPT_ABBR	0	/* "abbr" */

#define CPT_MENU	1	/* "menu" */

#define CPT_KIND	2	/* "kind" */

#define CPT_INFO	3	/* "info" */

#define CPT_USER_DATA	4	/* "user data" */

#define CPT_COUNT	5	/* Number of entries */

#define MAX_ARG_CMDS 10

#define WIN_HOR	    1	    /* "-o" horizontally split windows */

#define	WIN_VER	    2	    /* "-O" vertically split windows */

#define	WIN_TABS    3	    /* "-p" windows on tab pages */

#define SIGHASARG

#define BASENAMELEN	(MAXNAMLEN - 5)

#define SPECIAL_WILDCHAR    "`'{"

#define CHECK_INODE		/* used when checking if a swap file already
				    exists for a file */

#define HAVE_ACL (HAVE_POSIX_ACL || HAVE_SOLARIS_ACL || HAVE_AIX_ACL)

#define sleep(n) Sleep((n) * 1000)

#define BUFSIZE 512		/* long enough to hold a file name path */

#define NUL 0

#define FAIL 0

#define OK 1

#define VIM_STARTMENU "Programs\\Vim " VIM_VERSION_SHORT

#define ICON_COUNT 3

#define _IF_MZSCH_H_

#define USE_THREAD_FOR_INPUT_WITH_TIMEOUT	1

#define HAVE_DROP_FILE

#define	BEOS_PR_OR_BETTER

#define RANGE		0x001	/* allow a linespecs */

#define BANG		0x002	/* allow a ! after the command name */

#define EXTRA		0x004	/* allow extra args after command name */

#define XFILE		0x008	/* expand wildcards in extra part */

#define NOSPC		0x010	/* no spaces allowed in the extra part */

#define	DFLALL		0x020	/* default file range is 1,$ */

#define WHOLEFOLD	0x040	/* extend range to include whole fold also
				   when less than two numbers given */

#define NEEDARG		0x080	/* argument required */

#define TRLBAR		0x100	/* check for trailing vertical bar */

#define REGSTR		0x200	/* allow "x for register designation */

#define COUNT		0x400	/* allow count in argument, after command */

#define NOTRLCOM	0x800	/* no trailing comment allowed */

#define ZEROR	       0x1000	/* zero line number allowed */

#define USECTRLV       0x2000	/* do not remove CTRL-V from argument */

#define NOTADR	       0x4000	/* number before command is not an address */

#define EDITCMD	       0x8000	/* allow "+command" argument */

#define BUFNAME	      0x10000L	/* accepts buffer name */

#define BUFUNL	      0x20000L	/* accepts unlisted buffer too */

#define ARGOPT	      0x40000L	/* allow "++opt=val" argument */

#define SBOXOK	      0x80000L	/* allowed in the sandbox */

#define CMDWIN	     0x100000L	/* allowed in cmdline window; when missing
				 * disallows editing another buffer when
				 * curbuf_lock is set */

#define MODIFY       0x200000L	/* forbidden in non-'modifiable' buffer */

#define EXFLAGS      0x400000L	/* allow flags after count in argument */

#define FILES	(XFILE | EXTRA)	/* multiple extra files allowed */

#define WORD1	(EXTRA | NOSPC)	/* one extra word allowed */

#define FILE1	(FILES | NOSPC)	/* 1 file allowed, defaults to current file */

#define ADDR_LINES		0

#define ADDR_WINDOWS		1

#define ADDR_ARGUMENTS		2

#define ADDR_LOADED_BUFFERS	3

#define ADDR_BUFFERS		4

#define ADDR_TABS		5

#define ADDR_TABS_RELATIVE	6   /* Tab page that only relative */

#define ADDR_QUICKFIX		7

#define ADDR_OTHER		99

#define FORCE_BIN 1		/* ":edit ++bin file" */

#define FORCE_NOBIN 2		/* ":edit ++nobin file" */

#define EXFLAG_LIST	0x01	/* 'l': list */

#define EXFLAG_NR	0x02	/* '#': number */

#define EXFLAG_PRINT	0x04	/* 'p': print */

#define _ISCYGPTY_H

#define is_cygpty(fd)		0

#define is_cygpty_used()	0

#define __GTK_FORM_H__

#define GTK_TYPE_FORM		       (gtk_form_get_type ())

#define GTK_FORM(obj)		       (GTK_CHECK_CAST ((obj), GTK_TYPE_FORM, GtkForm))

#define GTK_FORM_CLASS(klass)	       (GTK_CHECK_CLASS_CAST ((klass), GTK_TYPE_FORM, GtkFormClass))

#define GTK_IS_FORM(obj)	       (GTK_CHECK_TYPE ((obj), GTK_TYPE_FORM))

#define GTK_IS_FORM_CLASS(klass)       (GTK_CHECK_CLASS_TYPE ((klass), GTK_TYPE_FORM))

#define a_COMMA				0x060C

#define a_SEMICOLON			0x061B

#define a_QUESTION			0x061F

#define a_HAMZA				0x0621

#define a_ALEF_MADDA			0x0622

#define a_ALEF_HAMZA_ABOVE		0x0623

#define a_WAW_HAMZA			0x0624

#define a_ALEF_HAMZA_BELOW		0x0625

#define a_YEH_HAMZA			0x0626

#define a_ALEF				0x0627

#define a_BEH				0x0628

#define a_TEH_MARBUTA			0x0629

#define a_TEH				0x062a

#define a_THEH				0x062b

#define a_JEEM				0x062c

#define a_HAH				0x062d

#define a_KHAH				0x062e

#define a_DAL				0x062f

#define a_THAL				0x0630

#define a_REH				0x0631

#define a_ZAIN				0x0632

#define a_SEEN				0x0633

#define a_SHEEN				0x0634

#define a_SAD				0x0635

#define a_DAD				0x0636

#define a_TAH				0x0637

#define a_ZAH				0x0638

#define a_AIN				0x0639

#define a_GHAIN				0x063a

#define a_TATWEEL			0x0640

#define a_FEH				0x0641

#define a_QAF				0x0642

#define a_KAF				0x0643

#define a_LAM				0x0644

#define a_MEEM				0x0645

#define a_NOON				0x0646

#define a_HEH				0x0647

#define a_WAW				0x0648

#define a_ALEF_MAKSURA			0x0649

#define a_YEH				0x064a

#define a_FATHATAN			0x064b

#define a_DAMMATAN			0x064c

#define a_KASRATAN			0x064d

#define a_FATHA				0x064e

#define a_DAMMA				0x064f

#define a_KASRA				0x0650

#define a_SHADDA			0x0651

#define a_SUKUN				0x0652

#define a_MADDA_ABOVE			0x0653

#define a_HAMZA_ABOVE			0x0654

#define a_HAMZA_BELOW			0x0655

#define a_ZERO				0x0660

#define a_ONE				0x0661

#define a_TWO				0x0662

#define a_THREE				0x0663

#define a_FOUR				0x0664

#define a_FIVE				0x0665

#define a_SIX				0x0666

#define a_SEVEN				0x0667

#define a_EIGHT				0x0668

#define a_NINE				0x0669

#define a_PERCENT			0x066a

#define a_DECIMAL			0x066b

#define a_THOUSANDS			0x066c

#define a_STAR				0x066d

#define a_MINI_ALEF			0x0670

#define a_s_FATHATAN			0xfe70

#define a_m_TATWEEL_FATHATAN		0xfe71

#define a_s_DAMMATAN			0xfe72

#define a_s_KASRATAN			0xfe74

#define a_s_FATHA			0xfe76

#define a_m_FATHA			0xfe77

#define a_s_DAMMA			0xfe78

#define a_m_DAMMA			0xfe79

#define a_s_KASRA			0xfe7a

#define a_m_KASRA			0xfe7b

#define a_s_SHADDA			0xfe7c

#define a_m_SHADDA			0xfe7d

#define a_s_SUKUN			0xfe7e

#define a_m_SUKUN			0xfe7f

#define a_s_HAMZA			0xfe80

#define a_s_ALEF_MADDA			0xfe81

#define a_f_ALEF_MADDA			0xfe82

#define a_s_ALEF_HAMZA_ABOVE		0xfe83

#define a_f_ALEF_HAMZA_ABOVE		0xfe84

#define a_s_WAW_HAMZA			0xfe85

#define a_f_WAW_HAMZA			0xfe86

#define a_s_ALEF_HAMZA_BELOW		0xfe87

#define a_f_ALEF_HAMZA_BELOW		0xfe88

#define a_s_YEH_HAMZA			0xfe89

#define a_f_YEH_HAMZA			0xfe8a

#define a_i_YEH_HAMZA			0xfe8b

#define a_m_YEH_HAMZA			0xfe8c

#define a_s_ALEF			0xfe8d

#define a_f_ALEF			0xfe8e

#define a_s_BEH				0xfe8f

#define a_f_BEH				0xfe90

#define a_i_BEH				0xfe91

#define a_m_BEH				0xfe92

#define a_s_TEH_MARBUTA			0xfe93

#define a_f_TEH_MARBUTA			0xfe94

#define a_s_TEH				0xfe95

#define a_f_TEH				0xfe96

#define a_i_TEH				0xfe97

#define a_m_TEH				0xfe98

#define a_s_THEH			0xfe99

#define a_f_THEH			0xfe9a

#define a_i_THEH			0xfe9b

#define a_m_THEH			0xfe9c

#define a_s_JEEM			0xfe9d

#define a_f_JEEM			0xfe9e

#define a_i_JEEM			0xfe9f

#define a_m_JEEM			0xfea0

#define a_s_HAH				0xfea1

#define a_f_HAH				0xfea2

#define a_i_HAH				0xfea3

#define a_m_HAH				0xfea4

#define a_s_KHAH			0xfea5

#define a_f_KHAH			0xfea6

#define a_i_KHAH			0xfea7

#define a_m_KHAH			0xfea8

#define a_s_DAL				0xfea9

#define a_f_DAL				0xfeaa

#define a_s_THAL			0xfeab

#define a_f_THAL			0xfeac

#define a_s_REH				0xfead

#define a_f_REH				0xfeae

#define a_s_ZAIN			0xfeaf

#define a_f_ZAIN			0xfeb0

#define a_s_SEEN			0xfeb1

#define a_f_SEEN			0xfeb2

#define a_i_SEEN			0xfeb3

#define a_m_SEEN			0xfeb4

#define a_s_SHEEN			0xfeb5

#define a_f_SHEEN			0xfeb6

#define a_i_SHEEN			0xfeb7

#define a_m_SHEEN			0xfeb8

#define a_s_SAD				0xfeb9

#define a_f_SAD				0xfeba

#define a_i_SAD				0xfebb

#define a_m_SAD				0xfebc

#define a_s_DAD				0xfebd

#define a_f_DAD				0xfebe

#define a_i_DAD				0xfebf

#define a_m_DAD				0xfec0

#define a_s_TAH				0xfec1

#define a_f_TAH				0xfec2

#define a_i_TAH				0xfec3

#define a_m_TAH				0xfec4

#define a_s_ZAH				0xfec5

#define a_f_ZAH				0xfec6

#define a_i_ZAH				0xfec7

#define a_m_ZAH				0xfec8

#define a_s_AIN				0xfec9

#define a_f_AIN				0xfeca

#define a_i_AIN				0xfecb

#define a_m_AIN				0xfecc

#define a_s_GHAIN			0xfecd

#define a_f_GHAIN			0xfece

#define a_i_GHAIN			0xfecf

#define a_m_GHAIN			0xfed0

#define a_s_FEH				0xfed1

#define a_f_FEH				0xfed2

#define a_i_FEH				0xfed3

#define a_m_FEH				0xfed4

#define a_s_QAF				0xfed5

#define a_f_QAF				0xfed6

#define a_i_QAF				0xfed7

#define a_m_QAF				0xfed8

#define a_s_KAF				0xfed9

#define a_f_KAF				0xfeda

#define a_i_KAF				0xfedb

#define a_m_KAF				0xfedc

#define a_s_LAM				0xfedd

#define a_f_LAM				0xfede

#define a_i_LAM				0xfedf

#define a_m_LAM				0xfee0

#define a_s_MEEM			0xfee1

#define a_f_MEEM			0xfee2

#define a_i_MEEM			0xfee3

#define a_m_MEEM			0xfee4

#define a_s_NOON			0xfee5

#define a_f_NOON			0xfee6

#define a_i_NOON			0xfee7

#define a_m_NOON			0xfee8

#define a_s_HEH				0xfee9

#define a_f_HEH				0xfeea

#define a_i_HEH				0xfeeb

#define a_m_HEH				0xfeec

#define a_s_WAW				0xfeed

#define a_f_WAW				0xfeee

#define a_s_ALEF_MAKSURA		0xfeef

#define a_f_ALEF_MAKSURA		0xfef0

#define a_s_YEH				0xfef1

#define a_f_YEH				0xfef2

#define a_i_YEH				0xfef3

#define a_m_YEH				0xfef4

#define a_s_LAM_ALEF_MADDA_ABOVE	0xfef5

#define a_f_LAM_ALEF_MADDA_ABOVE	0xfef6

#define a_s_LAM_ALEF_HAMZA_ABOVE	0xfef7

#define a_f_LAM_ALEF_HAMZA_ABOVE	0xfef8

#define a_s_LAM_ALEF_HAMZA_BELOW	0xfef9

#define a_f_LAM_ALEF_HAMZA_BELOW	0xfefa

#define a_s_LAM_ALEF			0xfefb

#define a_f_LAM_ALEF			0xfefc

#define a_BYTE_ORDER_MARK		0xfeff

#define ARABIC_CHAR(c)		((c) >= a_HAMZA && (c) <= a_MINI_ALEF)

#define _XRegisterFilterByType _XREGISTERFILTERBYTYPE

#define XAllocClassHint XALLOCCLASSHINT

#define XAllocColor XALLOCCOLOR

#define XAllocColorCells XALLOCCOLORCELLS

#define XAllocSizeHints XALLOCSIZEHINTS

#define XAllocWMHints XALLOCWMHINTS

#define XAutoRepeatOff XAUTOREPEATOFF

#define XAutoRepeatOn XAUTOREPEATON

#define XBaseFontNameListOfFontSet XBASEFONTNAMELISTOFFONTSET

#define XBell XBELL

#define XBitmapPad XBITMAPPAD

#define XChangeActivePointerGrab XCHANGEACTIVEPOINTERGRAB

#define XChangeGC XCHANGEGC

#define XChangeProperty XCHANGEPROPERTY

#define XChangeWindowAttributes XCHANGEWINDOWATTRIBUTES

#define XCheckIfEvent XCHECKIFEVENT

#define XCheckMaskEvent XCHECKMASKEVENT

#define XCheckTypedEvent XCHECKTYPEDEVENT

#define XCheckTypedWindowEvent XCHECKTYPEDWINDOWEVENT

#define XCheckWindowEvent XCHECKWINDOWEVENT

#define XClearArea XCLEARAREA

#define XClearWindow XCLEARWINDOW

#define XClipBox XCLIPBOX

#define XCloseDisplay XCLOSEDISPLAY

#define XCloseIM XCLOSEIM

#define XConfigureWindow XCONFIGUREWINDOW

#define XConvertSelection XCONVERTSELECTION

#define XCopyArea XCOPYAREA

#define XCopyGC XCOPYGC

#define XCopyPlane XCOPYPLANE

#define XCreateBitmapFromData XCREATEBITMAPFROMDATA

#define XCreateColormap XCREATECOLORMAP

#define XCreateFontCursor XCREATEFONTCURSOR

#define XCreateFontSet XCREATEFONTSET

#define XCreateGC XCREATEGC

#define XCreateIC XCREATEIC

#define XCreateImage XCREATEIMAGE

#define XCreatePixmap XCREATEPIXMAP

#define XCreatePixmapCursor XCREATEPIXMAPCURSOR

#define XCreatePixmapFromBitmapData XCREATEPIXMAPFROMBITMAPDATA

#define XCreateRegion XCREATEREGION

#define XCreateSimpleWindow XCREATESIMPLEWINDOW

#define XCreateWindow XCREATEWINDOW

#define XDefaultRootWindow XDEFAULTROOTWINDOW

#define XDefaultScreenOfDisplay XDEFAULTSCREENOFDISPLAY

#define XDefineCursor XDEFINECURSOR

#define XDeleteProperty XDELETEPROPERTY

#define XDestroyIC XDESTROYIC

#define XDestroyRegion XDESTROYREGION

#define XDestroyWindow XDESTROYWINDOW

#define XDisplayName XDISPLAYNAME

#define XDisplayOfScreen XDISPLAYOFSCREEN

#define XDisplayString XDISPLAYSTRING

#define XDrawArc XDRAWARC

#define XDrawImageString XDRAWIMAGESTRING

#define XDrawImageString16 XDRAWIMAGESTRING16

#define XDrawLine XDRAWLINE

#define XDrawLines XDRAWLINES

#define XDrawPoint XDRAWPOINT

#define XDrawPoints XDRAWPOINTS

#define XDrawRectangle XDRAWRECTANGLE

#define XDrawSegments XDRAWSEGMENTS

#define XDrawString XDRAWSTRING

#define XDrawString16 XDRAWSTRING16

#define XEmptyRegion XEMPTYREGION

#define XEqualRegion XEQUALREGION

#define XEventsQueued XEVENTSQUEUED

#define XExtentsOfFontSet XEXTENTSOFFONTSET

#define XFetchBuffer XFETCHBUFFER

#define XFillArc XFILLARC

#define XFillPolygon XFILLPOLYGON

#define XFillRectangle XFILLRECTANGLE

#define XFillRectangles XFILLRECTANGLES

#define XFilterEvent XFILTEREVENT

#define XFlush XFLUSH

#define XFontsOfFontSet XFONTSOFFONTSET

#define XFree XFREE

#define XFreeColormap XFREECOLORMAP

#define XFreeColors XFREECOLORS

#define XFreeCursor XFREECURSOR

#define XFreeFont XFREEFONT

#define XFreeFontInfo XFREEFONTINFO

#define XFreeFontNames XFREEFONTNAMES

#define XFreeFontSet XFREEFONTSET

#define XFreeGC XFREEGC

#define XFreeModifiermap XFREEMODIFIERMAP

#define XFreePixmap XFREEPIXMAP

#define XFreeStringList XFREESTRINGLIST

#define XGetAtomName XGETATOMNAME

#define XGetDefault XGETDEFAULT

#define XGetErrorDatabaseText XGETERRORDATABASETEXT

#define XGetErrorText XGETERRORTEXT

#define XGetFontProperty XGETFONTPROPERTY

#define XGetGCValues XGETGCVALUES

#define XGetGeometry XGETGEOMETRY

#define XGetIconSizes XGETICONSIZES

#define XGetICValues XGETICVALUES

#define XGetIMValues XGETIMVALUES

#define XGetImage XGETIMAGE

#define XGetKeyboardControl XGETKEYBOARDCONTROL

#define XGetModifierMapping XGETMODIFIERMAPPING

#define XGetMotionEvents XGETMOTIONEVENTS

#define XGetNormalHints XGETNORMALHINTS

#define XGetSelectionOwner XGETSELECTIONOWNER

#define XGetSubImage XGETSUBIMAGE

#define XGetVisualInfo XGETVISUALINFO

#define XGetWMColormapWindows XGETWMCOLORMAPWINDOWS

#define XGetWMIconName XGETWMICONNAME

#define XGetWMProtocols XGETWMPROTOCOLS

#define XGetWMHints XGETWMHINTS

#define XGetWMName XGETWMNAME

#define XGetWMNormalHints XGETWMNORMALHINTS

#define XGetWindowAttributes XGETWINDOWATTRIBUTES

#define XGetWindowProperty XGETWINDOWPROPERTY

#define XGrabKeyboard XGRABKEYBOARD

#define XGrabPointer XGRABPOINTER

#define XGrabServer XGRABSERVER

#define XHeightOfScreen XHEIGHTOFSCREEN

#define XIconifyWindow XICONIFYWINDOW

#define XIfEvent XIFEVENT

#define XInternAtom XINTERNATOM

#define XIntersectRegion XINTERSECTREGION

#define XKeycodeToKeysym XKEYCODETOKEYSYM

#define XKeysymToKeycode XKEYSYMTOKEYCODE

#define XKeysymToString XKEYSYMTOSTRING

#define XListFonts XLISTFONTS

#define XListFontsWithInfo XLISTFONTSWITHINFO

#define XListPixmapFormats XLISTPIXMAPFORMATS

#define XListProperties XLISTPROPERTIES

#define XLoadQueryFont XLOADQUERYFONT

#define XLookupString XLOOKUPSTRING

#define XLowerWindow XLOWERWINDOW

#define XMapRaised XMAPRAISED

#define XMapWindow XMAPWINDOW

#define XMatchVisualInfo XMATCHVISUALINFO

#define XMoveResizeWindow XMOVERESIZEWINDOW

#define XMoveWindow XMOVEWINDOW

#define XNextEvent XNEXTEVENT

#define XOffsetRegion XOFFSETREGION

#define XOpenDisplay XOPENDISPLAY

#define XOpenIM XOPENIM

#define XParseColor XPARSECOLOR

#define XParseGeometry XPARSEGEOMETRY

#define XPeekEvent XPEEKEVENT

#define XPending XPENDING

#define XPointInRegion XPOINTINREGION

#define XPolygonRegion XPOLYGONREGION

#define XPutBackEvent XPUTBACKEVENT

#define XPutImage XPUTIMAGE

#define XRootWindow XROOTWINDOW

#define XQueryColor XQUERYCOLOR

#define XQueryColors XQUERYCOLORS

#define XQueryExtension XQUERYEXTENSION

#define XQueryPointer XQUERYPOINTER

#define XQueryTree XQUERYTREE

#define XRaiseWindow XRAISEWINDOW

#define XReconfigureWMWindow XRECONFIGUREWMWINDOW

#define XRectInRegion XRECTINREGION

#define XRefreshKeyboardMapping XREFRESHKEYBOARDMAPPING

#define XReparentWindow XREPARENTWINDOW

#define XResizeWindow XRESIZEWINDOW

#define XRestackWindows XRESTACKWINDOWS

#define XRootWindowOfScreen XROOTWINDOWOFSCREEN

#define XScreenNumberOfScreen XSCREENNUMBEROFSCREEN

#define XSelectAsyncEvent XSELECTASYNCEVENT

#define XSelectAsyncInput XSELECTASYNCINPUT

#define XSelectInput XSELECTINPUT

#define XSendEvent XSENDEVENT

#define XServerVendor XSERVERVENDOR

#define XSetBackground XSETBACKGROUND

#define XSetClassHint XSETCLASSHINT

#define XSetClipMask XSETCLIPMASK

#define XSetClipOrigin XSETCLIPORIGIN

#define XSetClipRectangles XSETCLIPRECTANGLES

#define XSetCloseDownMode XSETCLOSEDOWNMODE

#define XSetCommand XSETCOMMAND

#define XSetDashes XSETDASHES

#define XSetErrorHandler XSETERRORHANDLER

#define XSetFillStyle XSETFILLSTYLE

#define XSetFont XSETFONT

#define XSetForeground XSETFOREGROUND

#define XSetFunction XSETFUNCTION

#define XSetGraphicsExposures XSETGRAPHICSEXPOSURES

#define XSetICFocus XSETICFOCUS

#define XSetICValues XSETICVALUES

#define XSetIOErrorHandler XSETIOERRORHANDLER

#define XSetInputFocus XSETINPUTFOCUS

#define XSetLineAttributes XSETLINEATTRIBUTES

#define XSetLocaleModifiers XSETLOCALEMODIFIERS

#define XSetNormalHints XSETNORMALHINTS

#define XSetRegion XSETREGION

#define XSetSelectionOwner XSETSELECTIONOWNER

#define XSetStipple XSETSTIPPLE

#define XSetSubwindowMode XSETSUBWINDOWMODE

#define XSetTSOrigin XSETTSORIGIN

#define XSetTile XSETTILE

#define XSetTransientForHint XSETTRANSIENTFORHINT

#define XSetWMColormapWindows XSETWMCOLORMAPWINDOWS

#define XSetWMHints XSETWMHINTS

#define XSetWMIconName XSETWMICONNAME

#define XSetWMName XSETWMNAME

#define XSetWMNormalHints XSETWMNORMALHINTS

#define XSetWMProperties XSETWMPROPERTIES

#define XSetWMProtocols XSETWMPROTOCOLS

#define XSetWindowBackground XSETWINDOWBACKGROUND

#define XSetWindowBackgroundPixmap XSETWINDOWBACKGROUNDPIXMAP

#define XSetWindowColormap XSETWINDOWCOLORMAP

#define XShapeCombineMask XSHAPECOMBINEMASK

#define XShapeCombineRectangles XSHAPECOMBINERECTANGLES

#define XShapeGetRectangles XSHAPEGETRECTANGLES

#define XShrinkRegion XSHRINKREGION

#define XStoreBuffer XSTOREBUFFER

#define XStoreColor XSTORECOLOR

#define XStoreColors XSTORECOLORS

#define XStoreName XSTORENAME

#define XStringToKeysym XSTRINGTOKEYSYM

#define XSubtractRegion XSUBTRACTREGION

#define XSupportsLocale XSUPPORTSLOCALE

#define XSync XSYNC

#define XSynchronize XSYNCHRONIZE

#define XTextExtents XTEXTEXTENTS

#define XTextExtents16 XTEXTEXTENTS16

#define XTextWidth XTEXTWIDTH

#define XTextWidth16 XTEXTWIDTH16

#define XTranslateCoordinates XTRANSLATECOORDINATES

#define XUndefineCursor XUNDEFINECURSOR

#define XUngrabKeyboard XUNGRABKEYBOARD

#define XUngrabPointer XUNGRABPOINTER

#define XUngrabServer XUNGRABSERVER

#define XUnionRectWithRegion XUNIONRECTWITHREGION

#define XUnionRegion XUNIONREGION

#define XUnmapWindow XUNMAPWINDOW

#define _XUnregisterFilter _XUNREGISTERFILTER

#define XUnsetICFocus XUNSETICFOCUS

#define XVaCreateNestedList XVACREATENESTEDLIST

#define XVisualIDFromVisual XVISUALIDFROMVISUAL

#define XWarpPointer XWARPPOINTER

#define XWidthOfScreen XWIDTHOFSCREEN

#define XWindowEvent XWINDOWEVENT

#define XWithdrawWindow XWITHDRAWWINDOW

#define XXorRegion XXORREGION

#define XmAddProtocolCallback XMADDPROTOCOLCALLBACK

#define XmAddProtocols XMADDPROTOCOLS

#define XmChangeColor XMCHANGECOLOR

#define XmClipboardCopy XMCLIPBOARDCOPY

#define XmClipboardEndCopy XMCLIPBOARDENDCOPY

#define XmClipboardInquireLength XMCLIPBOARDINQUIRELENGTH

#define XmClipboardLock XMCLIPBOARDLOCK

#define XmClipboardRetrieve XMCLIPBOARDRETRIEVE

#define XmClipboardStartCopy XMCLIPBOARDSTARTCOPY

#define XmClipboardUnlock XMCLIPBOARDUNLOCK

#define XmCreateArrowButton XMCREATEARROWBUTTON

#define XmCreateArrowButtonGadget XMCREATEARROWBUTTONGADGET

#define XmCreateCascadeButton XMCREATECASCADEBUTTON

#define XmCreateDialogShell XMCREATEDIALOGSHELL

#define XmCreateDragIcon XMCREATEDRAGICON

#define XmCreateDrawingArea XMCREATEDRAWINGAREA

#define XmCreateDrawnButton XMCREATEDRAWNBUTTON

#define XmCreateFileSelectionBox XMCREATEFILESELECTIONBOX

#define XmCreateFileSelectionDialog XMCREATEFILESELECTIONDIALOG

#define XmCreateForm XMCREATEFORM

#define XmCreateFormDialog XMCREATEFORMDIALOG

#define XmCreateFrame XMCREATEFRAME

#define XmCreateInformationDialog XMCREATEINFORMATIONDIALOG

#define XmCreateLabelGadget XMCREATELABELGADGET

#define XmCreateMainWindow XMCREATEMAINWINDOW

#define XmCreateMenuBar XMCREATEMENUBAR

#define XmCreateMessageBox XMCREATEMESSAGEBOX

#define XmCreateMessageDialog XMCREATEMESSAGEDIALOG

#define XmCreateOptionMenu XMCREATEOPTIONMENU

#define XmCreatePanedWindow XMCREATEPANEDWINDOW

#define XmCreatePopupMenu XMCREATEPOPUPMENU

#define XmCreatePromptDialog XMCREATEPROMPTDIALOG

#define XmCreatePulldownMenu XMCREATEPULLDOWNMENU

#define XmCreatePushButton XMCREATEPUSHBUTTON

#define XmCreatePushButtonGadget XMCREATEPUSHBUTTONGADGET

#define XmCreateQuestionDialog XMCREATEQUESTIONDIALOG

#define XmCreateRadioBox XMCREATERADIOBOX

#define XmCreateRowColumn XMCREATEROWCOLUMN

#define XmCreateScale XMCREATESCALE

#define XmCreateScrollBar XMCREATESCROLLBAR

#define XmCreateScrolledList XMCREATESCROLLEDLIST

#define XmCreateScrolledText XMCREATESCROLLEDTEXT

#define XmCreateScrolledWindow XMCREATESCROLLEDWINDOW

#define XmCreateSelectionDialog XMCREATESELECTIONDIALOG

#define XmCreateSeparator XMCREATESEPARATOR

#define XmCreateSeparatorGadget XMCREATESEPARATORGADGET

#define XmCreateTemplateDialog XMCREATETEMPLATEDIALOG

#define XmCreateText XMCREATETEXT

#define XmCreateTextField XMCREATETEXTFIELD

#define XmCreateToggleButton XMCREATETOGGLEBUTTON

#define XmCreateToggleButtonGadget XMCREATETOGGLEBUTTONGADGET

#define XmDragStart XMDRAGSTART

#define XmDropSiteRegister XMDROPSITEREGISTER

#define XmDropSiteUnregister XMDROPSITEUNREGISTER

#define XmDropSiteUpdate XMDROPSITEUPDATE

#define XmDropTransferStart XMDROPTRANSFERSTART

#define XmFileSelectionBoxGetChild XMFILESELECTIONBOXGETCHILD

#define XmFileSelectionDoSearch XMFILESELECTIONDOSEARCH

#define XmFontListAppendEntry XMFONTLISTAPPENDENTRY

#define XmFontListCopy XMFONTLISTCOPY

#define XmFontListCreate XMFONTLISTCREATE

#define XmFontListEntryCreate XMFONTLISTENTRYCREATE

#define XmFontListEntryFree XMFONTLISTENTRYFREE

#define XmFontListEntryGetFont XMFONTLISTENTRYGETFONT

#define XmFontListEntryGetTag XMFONTLISTENTRYGETTAG

#define XmFontListEntryLoad XMFONTLISTENTRYLOAD

#define XmFontListFree XMFONTLISTFREE

#define XmFontListFreeFontContext XMFONTLISTFREEFONTCONTEXT

#define XmFontListGetNextFont XMFONTLISTGETNEXTFONT

#define XmFontListInitFontContext XMFONTLISTINITFONTCONTEXT

#define XmFontListNextEntry XMFONTLISTNEXTENTRY

#define XmGetColors XMGETCOLORS

#define XmGetFocusWidget XMGETFOCUSWIDGET

#define XmGetMenuCursor XMGETMENUCURSOR

#define XmGetPixmapByDepth XMGETPIXMAPBYDEPTH

#define XmGetTearOffControl XMGETTEAROFFCONTROL

#define XmGetXmDisplay XMGETXMDISPLAY

#define XmImMbLookupString XMIMMBLOOKUPSTRING

#define XmImRegister XMIMREGISTER

#define XmImSetFocusValues XMIMSETFOCUSVALUES

#define XmImSetValues XMIMSETVALUES

#define XmImUnregister XMIMUNREGISTER

#define XmImUnsetFocus XMIMUNSETFOCUS

#define XmInternAtom XMINTERNATOM

#define XmIsMotifWMRunning XMISMOTIFWMRUNNING

#define XmListAddItem XMLISTADDITEM

#define XmListAddItemUnselected XMLISTADDITEMUNSELECTED

#define XmListAddItemsUnselected XMLISTADDITEMSUNSELECTED

#define XmListDeleteAllItems XMLISTDELETEALLITEMS

#define XmListDeleteItemsPos XMLISTDELETEITEMSPOS

#define XmListDeletePos XMLISTDELETEPOS

#define XmListDeselectAllItems XMLISTDESELECTALLITEMS

#define XmListDeselectPos XMLISTDESELECTPOS

#define XmListGetKbdItemPos XMLISTGETKBDITEMPOS

#define XmListGetMatchPos XMLISTGETMATCHPOS

#define XmListGetSelectedPos XMLISTGETSELECTEDPOS

#define XmListPosSelected XMLISTPOSSELECTED

#define XmListSelectItem XMLISTSELECTITEM

#define XmListSelectPos XMLISTSELECTPOS

#define XmListSetBottomPos XMLISTSETBOTTOMPOS

#define XmListSetItem XMLISTSETITEM

#define XmListSetKbdItemPos XMLISTSETKBDITEMPOS

#define XmListSetPos XMLISTSETPOS

#define XmMainWindowSetAreas XMMAINWINDOWSETAREAS

#define XmMenuPosition XMMENUPOSITION

#define XmMessageBoxGetChild XMMESSAGEBOXGETCHILD

#define XmOptionButtonGadget XMOPTIONBUTTONGADGET

#define XmOptionLabelGadget XMOPTIONLABELGADGET

#define XmProcessTraversal XMPROCESSTRAVERSAL

#define XmQmotif XMQMOTIF

#define XmRemoveProtocolCallback XMREMOVEPROTOCOLCALLBACK

#define XmRepTypeGetId XMREPTYPEGETID

#define XmRepTypeGetRecord XMREPTYPEGETRECORD

#define XmRepTypeRegister XMREPTYPEREGISTER

#define XmRepTypeValidValue XMREPTYPEVALIDVALUE

#define XmScrollBarSetValues XMSCROLLBARSETVALUES

#define XmScrolledWindowSetAreas XMSCROLLEDWINDOWSETAREAS

#define XmSelectionBoxGetChild XMSELECTIONBOXGETCHILD

#define XmStringByteCompare XMSTRINGBYTECOMPARE

#define XmStringCompare XMSTRINGCOMPARE

#define XmStringConcat XMSTRINGCONCAT

#define XmStringCopy XMSTRINGCOPY

#define XmStringCreate XMSTRINGCREATE

#define XmStringCreateLocalized XMSTRINGCREATELOCALIZED

#define XmStringCreateLtoR XMSTRINGCREATELTOR

#define XmStringCreateSimple XMSTRINGCREATESIMPLE

#define XmStringDraw XMSTRINGDRAW

#define XmStringDrawUnderline XMSTRINGDRAWUNDERLINE

#define XmStringExtent XMSTRINGEXTENT

#define XmStringFree XMSTRINGFREE

#define XmStringFreeContext XMSTRINGFREECONTEXT

#define XmStringGetLtoR XMSTRINGGETLTOR

#define XmStringGetNextComponent XMSTRINGGETNEXTCOMPONENT

#define XmStringGetNextSegment XMSTRINGGETNEXTSEGMENT

#define XmStringInitContext XMSTRINGINITCONTEXT

#define XmStringLength XMSTRINGLENGTH

#define XmStringLtoRCreate XMSTRINGLTORCREATE

#define XmStringNConcat XMSTRINGNCONCAT

#define XmStringSegmentCreate XMSTRINGSEGMENTCREATE

#define XmStringWidth XMSTRINGWIDTH

#define XmTextClearSelection XMTEXTCLEARSELECTION

#define XmTextFieldGetEditable XMTEXTFIELDGETEDITABLE

#define XmTextFieldGetInsertionPosition XMTEXTFIELDGETINSERTIONPOSITION

#define XmTextFieldGetLastPosition XMTEXTFIELDGETLASTPOSITION

#define XmTextFieldGetSelection XMTEXTFIELDGETSELECTION

#define XmTextFieldGetString XMTEXTFIELDGETSTRING

#define XmTextFieldInsert XMTEXTFIELDINSERT

#define XmTextFieldRemove XMTEXTFIELDREMOVE

#define XmTextFieldSetSelection XMTEXTFIELDSETSELECTION

#define XmTextFieldSetString XMTEXTFIELDSETSTRING

#define XmTextGetCursorPosition XMTEXTGETCURSORPOSITION

#define XmTextGetInsertionPosition XMTEXTGETINSERTIONPOSITION

#define XmTextGetLastPosition XMTEXTGETLASTPOSITION

#define XmTextGetMaxLength XMTEXTGETMAXLENGTH

#define XmTextGetSelection XMTEXTGETSELECTION

#define XmTextGetSelectionPosition XMTEXTGETSELECTIONPOSITION

#define XmTextGetString XMTEXTGETSTRING

#define XmTextInsert XMTEXTINSERT

#define XmTextRemove XMTEXTREMOVE

#define XmTextReplace XMTEXTREPLACE

#define XmTextSetCursorPosition XMTEXTSETCURSORPOSITION

#define XmTextSetHighlight XMTEXTSETHIGHLIGHT

#define XmTextSetInsertionPosition XMTEXTSETINSERTIONPOSITION

#define XmTextSetSelection XMTEXTSETSELECTION

#define XmTextSetString XMTEXTSETSTRING

#define XmToggleButtonGadgetGetState XMTOGGLEBUTTONGADGETGETSTATE

#define XmToggleButtonGadgetSetState XMTOGGLEBUTTONGADGETSETSTATE

#define XmToggleButtonGetState XMTOGGLEBUTTONGETSTATE

#define XmToggleButtonSetState XMTOGGLEBUTTONSETSTATE

#define XmUpdateDisplay XMUPDATEDISPLAY

#define XmVaCreateSimpleRadioBox XMVACREATESIMPLERADIOBOX

#define XmbDrawString XMBDRAWSTRING

#define XmbLookupString XMBLOOKUPSTRING

#define XmbResetIC XMBRESETIC

#define XmbSetWMProperties XMBSETWMPROPERTIES

#define XmbTextEscapement XMBTEXTESCAPEMENT

#define XmbTextExtents XMBTEXTEXTENTS

#define XmbTextListToTextProperty XMBTEXTLISTTOTEXTPROPERTY

#define XmbTextPropertyToTextList XMBTEXTPROPERTYTOTEXTLIST

#define XmuClientWindow XMUCLIENTWINDOW

#define XmuPrintDefaultErrorMessage XMUPRINTDEFAULTERRORMESSAGE

#define XrmGetDatabase XRMGETDATABASE

#define XrmGetResource XRMGETRESOURCE

#define XrmPutStringResource XRMPUTSTRINGRESOURCE

#define XrmQuarkToString XRMQUARKTOSTRING

#define XrmStringToQuark XRMSTRINGTOQUARK

#define XtAddCallback XTADDCALLBACK

#define XtAddCallbacks XTADDCALLBACKS

#define XtAddEventHandler XTADDEVENTHANDLER

#define XtAddGrab XTADDGRAB

#define XtAllocateGC XTALLOCATEGC

#define XtAppAddActions XTAPPADDACTIONS

#define XtAppAddInput XTAPPADDINPUT

#define XtAppAddTimeOut XTAPPADDTIMEOUT

#define XtAppCreateShell XTAPPCREATESHELL

#define XtAppInitialize XTAPPINITIALIZE

#define XtAppNextEvent XTAPPNEXTEVENT

#define XtAppPeekEvent XTAPPPEEKEVENT

#define XtAppPending XTAPPPENDING

#define XtAppProcessEvent XTAPPPROCESSEVENT

#define XtAppSetErrorHandler XTAPPSETERRORHANDLER

#define XtAppSetFallbackResources XTAPPSETFALLBACKRESOURCES

#define XtAppSetWarningHandler XTAPPSETWARNINGHANDLER

#define XtAppSetWarningMsgHandler XTAPPSETWARNINGMSGHANDLER

#define XtAppWarning XTAPPWARNING

#define XtCallActionProc XTCALLACTIONPROC

#define XtCallCallbackList XTCALLCALLBACKLIST

#define XtCallCallbacks XTCALLCALLBACKS

#define XtConfigureWidget XTCONFIGUREWIDGET

#define XtConvertAndStore XTCONVERTANDSTORE

#define XtCreateApplicationContext XTCREATEAPPLICATIONCONTEXT

#define XtCreateManagedWidget XTCREATEMANAGEDWIDGET

#define XtCreatePopupShell XTCREATEPOPUPSHELL

#define XtCreateWidget XTCREATEWIDGET

#define XtDatabase XTDATABASE

#define XtDestroyWidget XTDESTROYWIDGET

#define XtDisownSelection XTDISOWNSELECTION

#define XtDispatchEvent XTDISPATCHEVENT

#define XtDisplayOfObject XTDISPLAYOFOBJECT

#define XtDisplayStringConvWarning XTDISPLAYSTRINGCONVWARNING

#define XtDisplayToApplicationContext XTDISPLAYTOAPPLICATIONCONTEXT

#define XtFree XTFREE

#define XtGetActionKeysym XTGETACTIONKEYSYM

#define XtGetActionList XTGETACTIONLIST

#define XtGetApplicationNameAndClass XTGETAPPLICATIONNAMEANDCLASS

#define XtGetApplicationResources XTGETAPPLICATIONRESOURCES

#define XtGetGC XTGETGC

#define XtGetMultiClickTime XTGETMULTICLICKTIME

#define XtGetSelectionValue XTGETSELECTIONVALUE

#define XtGetSelectionValues XTGETSELECTIONVALUES

#define XtGetSubresources XTGETSUBRESOURCES

#define XtGetValues XTGETVALUES

#define XtGrabKeyboard XTGRABKEYBOARD

#define XtGrabPointer XTGRABPOINTER

#define XtHasCallbacks XTHASCALLBACKS

#define XtInitializeWidgetClass XTINITIALIZEWIDGETCLASS

#define XtInsertEventHandler XTINSERTEVENTHANDLER

#define XtIsManaged XTISMANAGED

#define XtIsObject XTISOBJECT

#define XtIsSensitive XTISSENSITIVE

#define XtIsSubclass XTISSUBCLASS

#define XtLastTimestampProcessed XTLASTTIMESTAMPPROCESSED

#define XtMakeGeometryRequest XTMAKEGEOMETRYREQUEST

#define XtMakeResizeRequest XTMAKERESIZEREQUEST

#define XtMalloc XTMALLOC

#define XtManageChild XTMANAGECHILD

#define XtManageChildren XTMANAGECHILDREN

#define XtMergeArgLists XTMERGEARGLISTS

#define XtMoveWidget XTMOVEWIDGET

#define XtName XTNAME

#define XtNameToWidget XTNAMETOWIDGET

#define XtOpenDisplay XTOPENDISPLAY

#define XtOverrideTranslations XTOVERRIDETRANSLATIONS

#define XtOwnSelection XTOWNSELECTION

#define XtParent XTPARENT

#define XtParseTranslationTable XTPARSETRANSLATIONTABLE

#define XtPopdown XTPOPDOWN

#define XtPopup XTPOPUP

#define XtQueryGeometry XTQUERYGEOMETRY

#define XtRealizeWidget XTREALIZEWIDGET

#define XtRealloc XTREALLOC

#define XtReleaseGC XTRELEASEGC

#define XtRemoveAllCallbacks XTREMOVEALLCALLBACKS

#define XtRemoveCallback XTREMOVECALLBACK

#define XtRemoveEventHandler XTREMOVEEVENTHANDLER

#define XtRemoveGrab XTREMOVEGRAB

#define XtRemoveInput XTREMOVEINPUT

#define XtRemoveTimeOut XTREMOVETIMEOUT

#define XtResizeWidget XTRESIZEWIDGET

#define XtResolvePathname XTRESOLVEPATHNAME

#define XtSetKeyboardFocus XTSETKEYBOARDFOCUS

#define XtSetMappedWhenManaged XTSETMAPPEDWHENMANAGED

#define XtSetSensitive XTSETSENSITIVE

#define XtSetTypeConverter XTSETTYPECONVERTER

#define XtSetValues XTSETVALUES

#define XtShellStrings XTSHELLSTRINGS

#define XtStrings XTSTRINGS

#define XtToolkitInitialize XTTOOLKITINITIALIZE

#define XtTranslateCoords XTTRANSLATECOORDS

#define XtTranslateKeycode XTTRANSLATEKEYCODE

#define XtUngrabKeyboard XTUNGRABKEYBOARD

#define XtUngrabPointer XTUNGRABPOINTER

#define XtUnmanageChild XTUNMANAGECHILD

#define XtUnmanageChildren XTUNMANAGECHILDREN

#define XtUnrealizeWidget XTUNREALIZEWIDGET

#define XtVaAppCreateShell XTVAAPPCREATESHELL

#define XtVaCreateManagedWidget XTVACREATEMANAGEDWIDGET

#define XtVaCreatePopupShell XTVACREATEPOPUPSHELL

#define XtVaCreateWidget XTVACREATEWIDGET

#define XtVaGetValues XTVAGETVALUES

#define XtVaSetValues XTVASETVALUES

#define XtWarning XTWARNING

#define XtWidgetToApplicationContext XTWIDGETTOAPPLICATIONCONTEXT

#define XtWindow XTWINDOW

#define XtWindowOfObject XTWINDOWOFOBJECT

#define XtWindowToWidget XTWINDOWTOWIDGET

#define XwcDrawString XWCDRAWSTRING

#define XwcFreeStringList XWCFREESTRINGLIST

#define XwcTextEscapement XWCTEXTESCAPEMENT

#define XwcTextExtents XWCTEXTEXTENTS

#define XwcTextListToTextProperty XWCTEXTLISTTOTEXTPROPERTY

#define XwcTextPropertyToTextList XWCTEXTPROPERTYTOTEXTLIST

#define _XmBottomShadowColorDefault _XMBOTTOMSHADOWCOLORDEFAULT

#define _XmClearBorder _XMCLEARBORDER

#define _XmConfigureObject _XMCONFIGUREOBJECT

#define _XmDestroyParentCallback _XMDESTROYPARENTCALLBACK

#define _XmDrawArrow _XMDRAWARROW

#define _XmDrawShadows _XMDRAWSHADOWS

#define _XmFontListGetDefaultFont _XMFONTLISTGETDEFAULTFONT

#define _XmFromHorizontalPixels _XMFROMHORIZONTALPIXELS

#define _XmFromVerticalPixels _XMFROMVERTICALPIXELS

#define _XmGetClassExtensionPtr _XMGETCLASSEXTENSIONPTR

#define _XmGetDefaultFontList _XMGETDEFAULTFONTLIST

#define _XmGetTextualDragIcon _XMGETTEXTUALDRAGICON

#define _XmGetWidgetExtData _XMGETWIDGETEXTDATA

#define _XmGrabKeyboard _XMGRABKEYBOARD

#define _XmGrabPointer _XMGRABPOINTER

#define _XmInheritClass _XMINHERITCLASS

#define _XmInputInGadget _XMINPUTINGADGET

#define _XmMakeGeometryRequest _XMMAKEGEOMETRYREQUEST

#define _XmMenuPopDown _XMMENUPOPDOWN

#define _XmMoveObject _XMMOVEOBJECT

#define _XmNavigChangeManaged _XMNAVIGCHANGEMANAGED

#define _XmOSBuildFileList _XMOSBUILDFILELIST

#define _XmOSFileCompare _XMOSFILECOMPARE

#define _XmOSFindPatternPart _XMOSFINDPATTERNPART

#define _XmOSQualifyFileSpec _XMOSQUALIFYFILESPEC

#define _XmPostPopupMenu _XMPOSTPOPUPMENU

#define _XmPrimitiveEnter _XMPRIMITIVEENTER

#define _XmPrimitiveLeave _XMPRIMITIVELEAVE

#define _XmRedisplayGadgets _XMREDISPLAYGADGETS

#define _XmShellIsExclusive _XMSHELLISEXCLUSIVE

#define _XmStringDraw _XMSTRINGDRAW

#define _XmStringGetTextConcat _XMSTRINGGETTEXTCONCAT

#define _XmStrings _XMSTRINGS

#define _XmToHorizontalPixels _XMTOHORIZONTALPIXELS

#define _XmToVerticalPixels _XMTOVERTICALPIXELS

#define _XmTopShadowColorDefault _XMTOPSHADOWCOLORDEFAULT

#define _Xm_fastPtr _XM_FASTPTR

#define _XtCheckSubclassFlag _XTCHECKSUBCLASSFLAG

#define _XtInherit _XTINHERIT

#define _XtInheritTranslations _XTINHERITTRANSLATIONS

#define applicationShellWidgetClass APPLICATIONSHELLWIDGETCLASS

#define compositeWidgetClass COMPOSITEWIDGETCLASS

#define overrideShellWidgetClass OVERRIDESHELLWIDGETCLASS

#define shellWidgetClass SHELLWIDGETCLASS

#define topLevelShellClassRec TOPLEVELSHELLCLASSREC

#define topLevelShellWidgetClass TOPLEVELSHELLWIDGETCLASS

#define transientShellWidgetClass TRANSIENTSHELLWIDGETCLASS

#define vendorShellClassRec VENDORSHELLCLASSREC

#define vendorShellWidgetClass VENDORSHELLWIDGETCLASS

#define wmShellWidgetClass WMSHELLWIDGETCLASS

#define xmArrowButtonWidgetClass XMARROWBUTTONWIDGETCLASS

#define xmCascadeButtonClassRec XMCASCADEBUTTONCLASSREC

#define xmCascadeButtonGadgetClass XMCASCADEBUTTONGADGETCLASS

#define xmCascadeButtonWidgetClass XMCASCADEBUTTONWIDGETCLASS

#define xmDialogShellWidgetClass XMDIALOGSHELLWIDGETCLASS

#define xmDrawingAreaWidgetClass XMDRAWINGAREAWIDGETCLASS

#define xmDrawnButtonWidgetClass XMDRAWNBUTTONWIDGETCLASS

#define xmFileSelectionBoxWidgetClass XMFILESELECTIONBOXWIDGETCLASS

#define xmFormWidgetClass XMFORMWIDGETCLASS

#define xmFrameWidgetClass XMFRAMEWIDGETCLASS

#define xmGadgetClass XMGADGETCLASS

#define xmLabelGadgetClass XMLABELGADGETCLASS

#define xmLabelWidgetClass XMLABELWIDGETCLASS

#define xmListWidgetClass XMLISTWIDGETCLASS

#define xmMainWindowWidgetClass XMMAINWINDOWWIDGETCLASS

#define xmManagerClassRec XMMANAGERCLASSREC

#define xmManagerWidgetClass XMMANAGERWIDGETCLASS

#define xmMenuShellWidgetClass XMMENUSHELLWIDGETCLASS

#define xmMessageBoxWidgetClass XMMESSAGEBOXWIDGETCLASS

#define xmPrimitiveClassRec XMPRIMITIVECLASSREC

#define xmPrimitiveWidgetClass XMPRIMITIVEWIDGETCLASS

#define xmPushButtonClassRec XMPUSHBUTTONCLASSREC

#define xmPushButtonGadgetClass XMPUSHBUTTONGADGETCLASS

#define xmPushButtonWidgetClass XMPUSHBUTTONWIDGETCLASS

#define xmRowColumnWidgetClass XMROWCOLUMNWIDGETCLASS

#define xmSashWidgetClass XMSASHWIDGETCLASS

#define xmScrollBarWidgetClass XMSCROLLBARWIDGETCLASS

#define xmScrolledWindowClassRec XMSCROLLEDWINDOWCLASSREC

#define xmScrolledWindowWidgetClass XMSCROLLEDWINDOWWIDGETCLASS

#define xmSeparatorGadgetClass XMSEPARATORGADGETCLASS

#define xmSeparatorWidgetClass XMSEPARATORWIDGETCLASS

#define xmTextFieldWidgetClass XMTEXTFIELDWIDGETCLASS

#define xmTextWidgetClass XMTEXTWIDGETCLASS

#define xmToggleButtonGadgetClass XMTOGGLEBUTTONGADGETCLASS

#define xmToggleButtonWidgetClass XMTOGGLEBUTTONWIDGETCLASS

#define _XtRegisterWindow _XTREGISTERWINDOW

#define _XtUnregisterWindow _XTUNREGISTERWINDOW

#define _REGEXP_H

#define NSUBEXP  10

#define NFA_MAX_BRACES 20

#define NFA_MAX_STATES 100000

#define NFA_TOO_EXPENSIVE -1

#define	    AUTOMATIC_ENGINE	0

#define	    BACKTRACKING_ENGINE	1

#define	    NFA_ENGINE		2

#define K_NUL			(0xce)	/* for MSDOS: special key follows */

#define K_SPECIAL		(0x80)

#define IS_SPECIAL(c)		((c) < 0)

#define ABBR_OFF		0x100

#define KS_ZERO			255

#define KS_SPECIAL		254

#define KS_EXTRA		253

#define KS_MODIFIER		252

#define KS_MOUSE		251

#define KS_MENU			250

#define KS_VER_SCROLLBAR	249

#define KS_HOR_SCROLLBAR	248

#define KS_NETTERM_MOUSE	247

#define KS_DEC_MOUSE		246

#define KS_SELECT		245

#define K_SELECT_STRING		(char_u *)"\200\365X"

#define KS_TEAROFF		244

#define KS_JSBTERM_MOUSE	243

#define KS_KEY			242

#define KS_PTERM_MOUSE		241

#define KS_TABLINE		240

#define KS_TABMENU		239

#define KS_URXVT_MOUSE		238

#define KS_SGR_MOUSE		237

#define KS_SGR_MOUSE_RELEASE	236

#define KE_FILLER		('X')

#define TERMCAP2KEY(a, b)	(-((a) + ((int)(b) << 8)))

#define KEY2TERMCAP0(x)		((-(x)) & 0xff)

#define KEY2TERMCAP1(x)		(((unsigned)(-(x)) >> 8) & 0xff)

#define K_SECOND(c)	((c) == K_SPECIAL ? KS_SPECIAL : (c) == NUL ? KS_ZERO : KEY2TERMCAP0(c))

#define K_THIRD(c)	(((c) == K_SPECIAL || (c) == NUL) ? KE_FILLER : KEY2TERMCAP1(c))

#define TO_SPECIAL(a, b)    ((a) == KS_SPECIAL ? K_SPECIAL : (a) == KS_ZERO ? K_ZERO : TERMCAP2KEY(a, b))

#define K_ZERO		TERMCAP2KEY(KS_ZERO, KE_FILLER)

#define K_UP		TERMCAP2KEY('k', 'u')

#define K_DOWN		TERMCAP2KEY('k', 'd')

#define K_LEFT		TERMCAP2KEY('k', 'l')

#define K_RIGHT		TERMCAP2KEY('k', 'r')

#define K_S_UP		TERMCAP2KEY(KS_EXTRA, KE_S_UP)

#define K_S_DOWN	TERMCAP2KEY(KS_EXTRA, KE_S_DOWN)

#define K_S_LEFT	TERMCAP2KEY('#', '4')

#define K_C_LEFT	TERMCAP2KEY(KS_EXTRA, KE_C_LEFT)

#define K_S_RIGHT	TERMCAP2KEY('%', 'i')

#define K_C_RIGHT	TERMCAP2KEY(KS_EXTRA, KE_C_RIGHT)

#define K_S_HOME	TERMCAP2KEY('#', '2')

#define K_C_HOME	TERMCAP2KEY(KS_EXTRA, KE_C_HOME)

#define K_S_END		TERMCAP2KEY('*', '7')

#define K_C_END		TERMCAP2KEY(KS_EXTRA, KE_C_END)

#define K_TAB		TERMCAP2KEY(KS_EXTRA, KE_TAB)

#define K_S_TAB		TERMCAP2KEY('k', 'B')

#define K_XF1		TERMCAP2KEY(KS_EXTRA, KE_XF1)

#define K_XF2		TERMCAP2KEY(KS_EXTRA, KE_XF2)

#define K_XF3		TERMCAP2KEY(KS_EXTRA, KE_XF3)

#define K_XF4		TERMCAP2KEY(KS_EXTRA, KE_XF4)

#define K_XUP		TERMCAP2KEY(KS_EXTRA, KE_XUP)

#define K_XDOWN		TERMCAP2KEY(KS_EXTRA, KE_XDOWN)

#define K_XLEFT		TERMCAP2KEY(KS_EXTRA, KE_XLEFT)

#define K_XRIGHT	TERMCAP2KEY(KS_EXTRA, KE_XRIGHT)

#define K_F1		TERMCAP2KEY('k', '1')	/* function keys */

#define K_F2		TERMCAP2KEY('k', '2')

#define K_F3		TERMCAP2KEY('k', '3')

#define K_F4		TERMCAP2KEY('k', '4')

#define K_F5		TERMCAP2KEY('k', '5')

#define K_F6		TERMCAP2KEY('k', '6')

#define K_F7		TERMCAP2KEY('k', '7')

#define K_F8		TERMCAP2KEY('k', '8')

#define K_F9		TERMCAP2KEY('k', '9')

#define K_F10		TERMCAP2KEY('k', ';')

#define K_F11		TERMCAP2KEY('F', '1')

#define K_F12		TERMCAP2KEY('F', '2')

#define K_F13		TERMCAP2KEY('F', '3')

#define K_F14		TERMCAP2KEY('F', '4')

#define K_F15		TERMCAP2KEY('F', '5')

#define K_F16		TERMCAP2KEY('F', '6')

#define K_F17		TERMCAP2KEY('F', '7')

#define K_F18		TERMCAP2KEY('F', '8')

#define K_F19		TERMCAP2KEY('F', '9')

#define K_F20		TERMCAP2KEY('F', 'A')

#define K_F21		TERMCAP2KEY('F', 'B')

#define K_F22		TERMCAP2KEY('F', 'C')

#define K_F23		TERMCAP2KEY('F', 'D')

#define K_F24		TERMCAP2KEY('F', 'E')

#define K_F25		TERMCAP2KEY('F', 'F')

#define K_F26		TERMCAP2KEY('F', 'G')

#define K_F27		TERMCAP2KEY('F', 'H')

#define K_F28		TERMCAP2KEY('F', 'I')

#define K_F29		TERMCAP2KEY('F', 'J')

#define K_F30		TERMCAP2KEY('F', 'K')

#define K_F31		TERMCAP2KEY('F', 'L')

#define K_F32		TERMCAP2KEY('F', 'M')

#define K_F33		TERMCAP2KEY('F', 'N')

#define K_F34		TERMCAP2KEY('F', 'O')

#define K_F35		TERMCAP2KEY('F', 'P')

#define K_F36		TERMCAP2KEY('F', 'Q')

#define K_F37		TERMCAP2KEY('F', 'R')

#define K_S_XF1		TERMCAP2KEY(KS_EXTRA, KE_S_XF1)

#define K_S_XF2		TERMCAP2KEY(KS_EXTRA, KE_S_XF2)

#define K_S_XF3		TERMCAP2KEY(KS_EXTRA, KE_S_XF3)

#define K_S_XF4		TERMCAP2KEY(KS_EXTRA, KE_S_XF4)

#define K_S_F1		TERMCAP2KEY(KS_EXTRA, KE_S_F1)	/* shifted func. keys */

#define K_S_F2		TERMCAP2KEY(KS_EXTRA, KE_S_F2)

#define K_S_F3		TERMCAP2KEY(KS_EXTRA, KE_S_F3)

#define K_S_F4		TERMCAP2KEY(KS_EXTRA, KE_S_F4)

#define K_S_F5		TERMCAP2KEY(KS_EXTRA, KE_S_F5)

#define K_S_F6		TERMCAP2KEY(KS_EXTRA, KE_S_F6)

#define K_S_F7		TERMCAP2KEY(KS_EXTRA, KE_S_F7)

#define K_S_F8		TERMCAP2KEY(KS_EXTRA, KE_S_F8)

#define K_S_F9		TERMCAP2KEY(KS_EXTRA, KE_S_F9)

#define K_S_F10		TERMCAP2KEY(KS_EXTRA, KE_S_F10)

#define K_S_F11		TERMCAP2KEY(KS_EXTRA, KE_S_F11)

#define K_S_F12		TERMCAP2KEY(KS_EXTRA, KE_S_F12)

#define K_HELP		TERMCAP2KEY('%', '1')

#define K_UNDO		TERMCAP2KEY('&', '8')

#define K_BS		TERMCAP2KEY('k', 'b')

#define K_INS		TERMCAP2KEY('k', 'I')

#define K_KINS		TERMCAP2KEY(KS_EXTRA, KE_KINS)

#define K_DEL		TERMCAP2KEY('k', 'D')

#define K_KDEL		TERMCAP2KEY(KS_EXTRA, KE_KDEL)

#define K_HOME		TERMCAP2KEY('k', 'h')

#define K_KHOME		TERMCAP2KEY('K', '1')	/* keypad home (upper left) */

#define K_XHOME		TERMCAP2KEY(KS_EXTRA, KE_XHOME)

#define K_ZHOME		TERMCAP2KEY(KS_EXTRA, KE_ZHOME)

#define K_END		TERMCAP2KEY('@', '7')

#define K_KEND		TERMCAP2KEY('K', '4')	/* keypad end (lower left) */

#define K_XEND		TERMCAP2KEY(KS_EXTRA, KE_XEND)

#define K_ZEND		TERMCAP2KEY(KS_EXTRA, KE_ZEND)

#define K_PAGEUP	TERMCAP2KEY('k', 'P')

#define K_PAGEDOWN	TERMCAP2KEY('k', 'N')

#define K_KPAGEUP	TERMCAP2KEY('K', '3')	/* keypad pageup (upper R.) */

#define K_KPAGEDOWN	TERMCAP2KEY('K', '5')	/* keypad pagedown (lower R.) */

#define K_KPLUS		TERMCAP2KEY('K', '6')	/* keypad plus */

#define K_KMINUS	TERMCAP2KEY('K', '7')	/* keypad minus */

#define K_KDIVIDE	TERMCAP2KEY('K', '8')	/* keypad / */

#define K_KMULTIPLY	TERMCAP2KEY('K', '9')	/* keypad * */

#define K_KENTER	TERMCAP2KEY('K', 'A')	/* keypad Enter */

#define K_KPOINT	TERMCAP2KEY('K', 'B')	/* keypad . or ,*/

#define K_PS		TERMCAP2KEY('P', 'S')	/* paste start */

#define K_PE		TERMCAP2KEY('P', 'E')	/* paste end */

#define K_K0		TERMCAP2KEY('K', 'C')	/* keypad 0 */

#define K_K1		TERMCAP2KEY('K', 'D')	/* keypad 1 */

#define K_K2		TERMCAP2KEY('K', 'E')	/* keypad 2 */

#define K_K3		TERMCAP2KEY('K', 'F')	/* keypad 3 */

#define K_K4		TERMCAP2KEY('K', 'G')	/* keypad 4 */

#define K_K5		TERMCAP2KEY('K', 'H')	/* keypad 5 */

#define K_K6		TERMCAP2KEY('K', 'I')	/* keypad 6 */

#define K_K7		TERMCAP2KEY('K', 'J')	/* keypad 7 */

#define K_K8		TERMCAP2KEY('K', 'K')	/* keypad 8 */

#define K_K9		TERMCAP2KEY('K', 'L')	/* keypad 9 */

#define K_MOUSE		TERMCAP2KEY(KS_MOUSE, KE_FILLER)

#define K_MENU		TERMCAP2KEY(KS_MENU, KE_FILLER)

#define K_VER_SCROLLBAR	TERMCAP2KEY(KS_VER_SCROLLBAR, KE_FILLER)

#define K_HOR_SCROLLBAR   TERMCAP2KEY(KS_HOR_SCROLLBAR, KE_FILLER)

#define K_NETTERM_MOUSE	TERMCAP2KEY(KS_NETTERM_MOUSE, KE_FILLER)

#define K_DEC_MOUSE	TERMCAP2KEY(KS_DEC_MOUSE, KE_FILLER)

#define K_JSBTERM_MOUSE	TERMCAP2KEY(KS_JSBTERM_MOUSE, KE_FILLER)

#define K_PTERM_MOUSE	TERMCAP2KEY(KS_PTERM_MOUSE, KE_FILLER)

#define K_URXVT_MOUSE	TERMCAP2KEY(KS_URXVT_MOUSE, KE_FILLER)

#define K_SGR_MOUSE	TERMCAP2KEY(KS_SGR_MOUSE, KE_FILLER)

#define K_SGR_MOUSERELEASE TERMCAP2KEY(KS_SGR_MOUSE_RELEASE, KE_FILLER)

#define K_SELECT	TERMCAP2KEY(KS_SELECT, KE_FILLER)

#define K_TEAROFF	TERMCAP2KEY(KS_TEAROFF, KE_FILLER)

#define K_TABLINE	TERMCAP2KEY(KS_TABLINE, KE_FILLER)

#define K_TABMENU	TERMCAP2KEY(KS_TABMENU, KE_FILLER)

#define K_LEFTMOUSE	TERMCAP2KEY(KS_EXTRA, KE_LEFTMOUSE)

#define K_LEFTMOUSE_NM	TERMCAP2KEY(KS_EXTRA, KE_LEFTMOUSE_NM)

#define K_LEFTDRAG	TERMCAP2KEY(KS_EXTRA, KE_LEFTDRAG)

#define K_LEFTRELEASE	TERMCAP2KEY(KS_EXTRA, KE_LEFTRELEASE)

#define K_LEFTRELEASE_NM TERMCAP2KEY(KS_EXTRA, KE_LEFTRELEASE_NM)

#define K_MOUSEMOVE	TERMCAP2KEY(KS_EXTRA, KE_MOUSEMOVE)

#define K_MIDDLEMOUSE	TERMCAP2KEY(KS_EXTRA, KE_MIDDLEMOUSE)

#define K_MIDDLEDRAG	TERMCAP2KEY(KS_EXTRA, KE_MIDDLEDRAG)

#define K_MIDDLERELEASE	TERMCAP2KEY(KS_EXTRA, KE_MIDDLERELEASE)

#define K_RIGHTMOUSE	TERMCAP2KEY(KS_EXTRA, KE_RIGHTMOUSE)

#define K_RIGHTDRAG	TERMCAP2KEY(KS_EXTRA, KE_RIGHTDRAG)

#define K_RIGHTRELEASE	TERMCAP2KEY(KS_EXTRA, KE_RIGHTRELEASE)

#define K_X1MOUSE       TERMCAP2KEY(KS_EXTRA, KE_X1MOUSE)

#define K_X1DRAG	TERMCAP2KEY(KS_EXTRA, KE_X1DRAG)

#define K_X1RELEASE     TERMCAP2KEY(KS_EXTRA, KE_X1RELEASE)

#define K_X2MOUSE       TERMCAP2KEY(KS_EXTRA, KE_X2MOUSE)

#define K_X2DRAG	TERMCAP2KEY(KS_EXTRA, KE_X2DRAG)

#define K_X2RELEASE     TERMCAP2KEY(KS_EXTRA, KE_X2RELEASE)

#define K_IGNORE	TERMCAP2KEY(KS_EXTRA, KE_IGNORE)

#define K_NOP		TERMCAP2KEY(KS_EXTRA, KE_NOP)

#define K_MOUSEDOWN	TERMCAP2KEY(KS_EXTRA, KE_MOUSEDOWN)

#define K_MOUSEUP	TERMCAP2KEY(KS_EXTRA, KE_MOUSEUP)

#define K_MOUSELEFT	TERMCAP2KEY(KS_EXTRA, KE_MOUSELEFT)

#define K_MOUSERIGHT	TERMCAP2KEY(KS_EXTRA, KE_MOUSERIGHT)

#define K_CSI		TERMCAP2KEY(KS_EXTRA, KE_CSI)

#define K_SNR		TERMCAP2KEY(KS_EXTRA, KE_SNR)

#define K_PLUG		TERMCAP2KEY(KS_EXTRA, KE_PLUG)

#define K_CMDWIN	TERMCAP2KEY(KS_EXTRA, KE_CMDWIN)

#define K_DROP		TERMCAP2KEY(KS_EXTRA, KE_DROP)

#define K_FOCUSGAINED	TERMCAP2KEY(KS_EXTRA, KE_FOCUSGAINED)

#define K_FOCUSLOST	TERMCAP2KEY(KS_EXTRA, KE_FOCUSLOST)

#define K_CURSORHOLD	TERMCAP2KEY(KS_EXTRA, KE_CURSORHOLD)

#define MOD_MASK_SHIFT	    0x02

#define MOD_MASK_CTRL	    0x04

#define MOD_MASK_ALT	    0x08	/* aka META */

#define MOD_MASK_META	    0x10	/* META when it's different from ALT */

#define MOD_MASK_2CLICK	    0x20	/* use MOD_MASK_MULTI_CLICK */

#define MOD_MASK_3CLICK	    0x40	/* use MOD_MASK_MULTI_CLICK */

#define MOD_MASK_4CLICK	    0x60	/* use MOD_MASK_MULTI_CLICK */

#define MOD_MASK_MULTI_CLICK	(MOD_MASK_2CLICK|MOD_MASK_3CLICK|MOD_MASK_4CLICK)

#define MAX_KEY_NAME_LEN    32

#define MAX_KEY_CODE_LEN    6

# include <time.h>	/* for time_t */
enum {WV_LIST = 0, WV_ARAB, WV_COCU, WV_COLE, WV_TK, WV_TMS, WV_CRBIND, WV_BRI, WV_BRIOPT, WV_DIFF, WV_FDC, WV_FEN, WV_FDI, WV_FDL, WV_FDM, WV_FML, WV_FDN, WV_FDE, WV_FDT, WV_FMR, WV_LBR, WV_NU, WV_RNU, WV_NUW, WV_PVW, WV_RL, WV_RLC, WV_SCBIND, WV_SCROLL, WV_SPELL, WV_CUC, WV_CUL, WV_CC, WV_STL, WV_WFH, WV_WFW, WV_WRAP, WV_SCL, WV_COUNT};
enum {BV_AI = 0, BV_AR, BV_BH, BV_BKC, BV_BT, BV_EFM, BV_GP, BV_MP, BV_BIN, BV_BL, BV_CI, BV_CIN, BV_CINK, BV_CINO, BV_CINW, BV_CM, BV_CMS, BV_COM, BV_CPT, BV_DICT, BV_TSR, BV_DEF, BV_INC, BV_EOL, BV_FIXEOL, BV_EP, BV_ET, BV_FENC, BV_FP, BV_BEXPR, BV_FEX, BV_FF, BV_FLP, BV_FO, BV_FT, BV_IMI, BV_IMS, BV_INDE, BV_INDK, BV_INEX, BV_INF, BV_ISK, BV_KEY, BV_KMAP, BV_KP, BV_LISP, BV_LW, BV_MA, BV_ML, BV_MOD, BV_MPS, BV_MMTA, BV_NF, BV_PATH, BV_PI, BV_QE, BV_RO, BV_SI, BV_SN, BV_SMC, BV_SYN, BV_SPC, BV_SPF, BV_SPL, BV_STS, BV_SUA, BV_SW, BV_SWF, BV_TAGS, BV_TC, BV_TS, BV_TW, BV_TX, BV_UDF, BV_UL, BV_WM, BV_COUNT};
enum {QF_GETLIST_NONE = 0x0, QF_GETLIST_TITLE = 0x1, QF_GETLIST_ITEMS = 0x2, QF_GETLIST_NR = 0x4, QF_GETLIST_WINID = 0x8, QF_GETLIST_CONTEXT = 0x10, QF_GETLIST_ID = 0x20, QF_GETLIST_IDX = 0x40, QF_GETLIST_SIZE = 0x80, QF_GETLIST_TICK = 0x100, QF_GETLIST_ALL = 0x1FF};
enum {QF_FAIL = 0, QF_OK = 1, QF_END_OF_INPUT = 2, QF_NOMEM = 3, QF_IGNORE_LINE = 4};
enum {BLINK_NONE, BLINK_OFF, BLINK_ON} blink_state = BLINK_NONE;
enum {NFA_SPLIT = -1024, NFA_MATCH, NFA_EMPTY, NFA_START_COLL, NFA_END_COLL, NFA_START_NEG_COLL, NFA_END_NEG_COLL, NFA_RANGE, NFA_RANGE_MIN, NFA_RANGE_MAX, NFA_CONCAT, NFA_OR, NFA_STAR, NFA_STAR_NONGREEDY, NFA_QUEST, NFA_QUEST_NONGREEDY, NFA_BOL, NFA_EOL, NFA_BOW, NFA_EOW, NFA_BOF, NFA_EOF, NFA_NEWL, NFA_ZSTART, NFA_ZEND, NFA_NOPEN, NFA_NCLOSE, NFA_START_INVISIBLE, NFA_START_INVISIBLE_FIRST, NFA_START_INVISIBLE_NEG, NFA_START_INVISIBLE_NEG_FIRST, NFA_START_INVISIBLE_BEFORE, NFA_START_INVISIBLE_BEFORE_FIRST, NFA_START_INVISIBLE_BEFORE_NEG, NFA_START_INVISIBLE_BEFORE_NEG_FIRST, NFA_START_PATTERN, NFA_END_INVISIBLE, NFA_END_INVISIBLE_NEG, NFA_END_PATTERN, NFA_COMPOSING, NFA_END_COMPOSING, NFA_ANY_COMPOSING, NFA_OPT_CHARS, NFA_PREV_ATOM_NO_WIDTH, NFA_PREV_ATOM_NO_WIDTH_NEG, NFA_PREV_ATOM_JUST_BEFORE, NFA_PREV_ATOM_JUST_BEFORE_NEG, NFA_PREV_ATOM_LIKE_PATTERN, NFA_BACKREF1, NFA_BACKREF2, NFA_BACKREF3, NFA_BACKREF4, NFA_BACKREF5, NFA_BACKREF6, NFA_BACKREF7, NFA_BACKREF8, NFA_BACKREF9, NFA_ZREF1, NFA_ZREF2, NFA_ZREF3, NFA_ZREF4, NFA_ZREF5, NFA_ZREF6, NFA_ZREF7, NFA_ZREF8, NFA_ZREF9, NFA_SKIP, NFA_MOPEN, NFA_MOPEN1, NFA_MOPEN2, NFA_MOPEN3, NFA_MOPEN4, NFA_MOPEN5, NFA_MOPEN6, NFA_MOPEN7, NFA_MOPEN8, NFA_MOPEN9, NFA_MCLOSE, NFA_MCLOSE1, NFA_MCLOSE2, NFA_MCLOSE3, NFA_MCLOSE4, NFA_MCLOSE5, NFA_MCLOSE6, NFA_MCLOSE7, NFA_MCLOSE8, NFA_MCLOSE9, NFA_ZOPEN, NFA_ZOPEN1, NFA_ZOPEN2, NFA_ZOPEN3, NFA_ZOPEN4, NFA_ZOPEN5, NFA_ZOPEN6, NFA_ZOPEN7, NFA_ZOPEN8, NFA_ZOPEN9, NFA_ZCLOSE, NFA_ZCLOSE1, NFA_ZCLOSE2, NFA_ZCLOSE3, NFA_ZCLOSE4, NFA_ZCLOSE5, NFA_ZCLOSE6, NFA_ZCLOSE7, NFA_ZCLOSE8, NFA_ZCLOSE9, NFA_ANY, NFA_IDENT, NFA_SIDENT, NFA_KWORD, NFA_SKWORD, NFA_FNAME, NFA_SFNAME, NFA_PRINT, NFA_SPRINT, NFA_WHITE, NFA_NWHITE, NFA_DIGIT, NFA_NDIGIT, NFA_HEX, NFA_NHEX, NFA_OCTAL, NFA_NOCTAL, NFA_WORD, NFA_NWORD, NFA_HEAD, NFA_NHEAD, NFA_ALPHA, NFA_NALPHA, NFA_LOWER, NFA_NLOWER, NFA_UPPER, NFA_NUPPER, NFA_LOWER_IC, NFA_NLOWER_IC, NFA_UPPER_IC, NFA_NUPPER_IC, NFA_FIRST_NL = NFA_ANY + NFA_ADD_NL, NFA_LAST_NL = NFA_NUPPER_IC + NFA_ADD_NL, NFA_CURSOR, NFA_LNUM, NFA_LNUM_GT, NFA_LNUM_LT, NFA_COL, NFA_COL_GT, NFA_COL_LT, NFA_VCOL, NFA_VCOL_GT, NFA_VCOL_LT, NFA_MARK, NFA_MARK_GT, NFA_MARK_LT, NFA_VISUAL, NFA_CLASS_ALNUM, NFA_CLASS_ALPHA, NFA_CLASS_BLANK, NFA_CLASS_CNTRL, NFA_CLASS_DIGIT, NFA_CLASS_GRAPH, NFA_CLASS_LOWER, NFA_CLASS_PRINT, NFA_CLASS_PUNCT, NFA_CLASS_SPACE, NFA_CLASS_UPPER, NFA_CLASS_XDIGIT, NFA_CLASS_TAB, NFA_CLASS_RETURN, NFA_CLASS_BACKSPACE, NFA_CLASS_ESCAPE};
enum {EXP_SUBCMD, EXP_DEFINE, EXP_PLACE, EXP_UNPLACE, EXP_SIGN_NAMES} expand_what;
enum {PEXP_SUBCMD, PEXP_FUNC} pexpand_what;
enum SpecialKey {KS_NAME = 0, KS_CE, KS_AL, KS_CAL, KS_DL, KS_CDL, KS_CS, KS_CL, KS_CD, KS_UT, KS_DA, KS_DB, KS_VI, KS_VE, KS_VS, KS_CVS, KS_CSH, KS_CRC, KS_CRS, KS_ME, KS_MR, KS_MD, KS_SE, KS_SO, KS_CZH, KS_CZR, KS_UE, KS_US, KS_UCE, KS_UCS, KS_STE, KS_STS, KS_MS, KS_CM, KS_SR, KS_CRI, KS_VB, KS_KS, KS_KE, KS_TI, KS_TE, KS_BC, KS_CCS, KS_CCO, KS_CSF, KS_CSB, KS_XS, KS_XN, KS_MB, KS_CAF, KS_CAB, KS_LE, KS_ND, KS_CIS, KS_CIE, KS_CSC, KS_CEC, KS_TS, KS_FS, KS_CWP, KS_CGP, KS_CWS, KS_CRV, KS_RFG, KS_RBG, KS_CSI, KS_CEI, KS_CSR, KS_CSV, KS_OP, KS_U7, KS_8F, KS_8B, KS_CBE, KS_CBD, KS_CPS, KS_CPE};
enum ListSpecifier {ENCODING, NAME, STYLE, SIZE, NONE};
enum auto_event {EVENT_BUFADD = 0, EVENT_BUFNEW, EVENT_BUFDELETE, EVENT_BUFWIPEOUT, EVENT_BUFENTER, EVENT_BUFFILEPOST, EVENT_BUFFILEPRE, EVENT_BUFLEAVE, EVENT_BUFNEWFILE, EVENT_BUFREADPOST, EVENT_BUFREADPRE, EVENT_BUFREADCMD, EVENT_BUFUNLOAD, EVENT_BUFHIDDEN, EVENT_BUFWINENTER, EVENT_BUFWINLEAVE, EVENT_BUFWRITEPOST, EVENT_BUFWRITEPRE, EVENT_BUFWRITECMD, EVENT_CMDLINECHANGED, EVENT_CMDLINEENTER, EVENT_CMDLINELEAVE, EVENT_CMDWINENTER, EVENT_CMDWINLEAVE, EVENT_COLORSCHEME, EVENT_COMPLETEDONE, EVENT_DIRCHANGED, EVENT_FILEAPPENDPOST, EVENT_FILEAPPENDPRE, EVENT_FILEAPPENDCMD, EVENT_FILECHANGEDSHELL, EVENT_FILECHANGEDSHELLPOST, EVENT_FILECHANGEDRO, EVENT_FILEREADPOST, EVENT_FILEREADPRE, EVENT_FILEREADCMD, EVENT_FILETYPE, EVENT_FILEWRITEPOST, EVENT_FILEWRITEPRE, EVENT_FILEWRITECMD, EVENT_FILTERREADPOST, EVENT_FILTERREADPRE, EVENT_FILTERWRITEPOST, EVENT_FILTERWRITEPRE, EVENT_FOCUSGAINED, EVENT_FOCUSLOST, EVENT_GUIENTER, EVENT_GUIFAILED, EVENT_INSERTCHANGE, EVENT_INSERTENTER, EVENT_INSERTLEAVE, EVENT_MENUPOPUP, EVENT_QUICKFIXCMDPOST, EVENT_QUICKFIXCMDPRE, EVENT_QUITPRE, EVENT_SESSIONLOADPOST, EVENT_STDINREADPOST, EVENT_STDINREADPRE, EVENT_SYNTAX, EVENT_TERMCHANGED, EVENT_TERMRESPONSE, EVENT_USER, EVENT_VIMENTER, EVENT_VIMLEAVE, EVENT_VIMLEAVEPRE, EVENT_VIMRESIZED, EVENT_WINENTER, EVENT_WINLEAVE, EVENT_WINNEW, EVENT_ENCODINGCHANGED, EVENT_INSERTCHARPRE, EVENT_CURSORHOLD, EVENT_CURSORHOLDI, EVENT_FUNCUNDEFINED, EVENT_REMOTEREPLY, EVENT_SWAPEXISTS, EVENT_SOURCEPRE, EVENT_SOURCECMD, EVENT_SPELLFILEMISSING, EVENT_CURSORMOVED, EVENT_CURSORMOVEDI, EVENT_TABENTER, EVENT_TABLEAVE, EVENT_TABNEW, EVENT_TABCLOSED, EVENT_SHELLCMDPOST, EVENT_SHELLFILTERPOST, EVENT_TEXTCHANGED, EVENT_TEXTCHANGEDI, EVENT_TEXTCHANGEDP, EVENT_CMDUNDEFINED, EVENT_OPTIONSET, EVENT_TEXTYANKPOST, NUM_EVENTS};
enum key_extra {KE_NAME = 3, KE_S_UP = 4, KE_S_DOWN = 5, KE_S_F1 = 6, KE_S_F2 = 7, KE_S_F3 = 8, KE_S_F4 = 9, KE_S_F5 = 10, KE_S_F6 = 11, KE_S_F7 = 12, KE_S_F8 = 13, KE_S_F9 = 14, KE_S_F10 = 15, KE_S_F11 = 16, KE_S_F12 = 17, KE_S_F13 = 18, KE_S_F14 = 19, KE_S_F15 = 20, KE_S_F16 = 21, KE_S_F17 = 22, KE_S_F18 = 23, KE_S_F19 = 24, KE_S_F20 = 25, KE_S_F21 = 26, KE_S_F22 = 27, KE_S_F23 = 28, KE_S_F24 = 29, KE_S_F25 = 30, KE_S_F26 = 31, KE_S_F27 = 32, KE_S_F28 = 33, KE_S_F29 = 34, KE_S_F30 = 35, KE_S_F31 = 36, KE_S_F32 = 37, KE_S_F33 = 38, KE_S_F34 = 39, KE_S_F35 = 40, KE_S_F36 = 41, KE_S_F37 = 42, KE_MOUSE = 43, KE_LEFTMOUSE = 44, KE_LEFTDRAG = 45, KE_LEFTRELEASE = 46, KE_MIDDLEMOUSE = 47, KE_MIDDLEDRAG = 48, KE_MIDDLERELEASE = 49, KE_RIGHTMOUSE = 50, KE_RIGHTDRAG = 51, KE_RIGHTRELEASE = 52, KE_IGNORE = 53, KE_TAB = 54, KE_S_TAB_OLD = 55, KE_SNIFF_UNUSED = 56, KE_XF1 = 57, KE_XF2 = 58, KE_XF3 = 59, KE_XF4 = 60, KE_XEND = 61, KE_ZEND = 62, KE_XHOME = 63, KE_ZHOME = 64, KE_XUP = 65, KE_XDOWN = 66, KE_XLEFT = 67, KE_XRIGHT = 68, KE_LEFTMOUSE_NM = 69, KE_LEFTRELEASE_NM = 70, KE_S_XF1 = 71, KE_S_XF2 = 72, KE_S_XF3 = 73, KE_S_XF4 = 74, KE_MOUSEDOWN = 75, KE_MOUSEUP = 76, KE_MOUSELEFT = 77, KE_MOUSERIGHT = 78, KE_KINS = 79, KE_KDEL = 80, KE_CSI = 81, KE_SNR = 82, KE_PLUG = 83, KE_CMDWIN = 84, KE_C_LEFT = 85, KE_C_RIGHT = 86, KE_C_HOME = 87, KE_C_END = 88, KE_X1MOUSE = 89, KE_X1DRAG = 90, KE_X1RELEASE = 91, KE_X2MOUSE = 92, KE_X2DRAG = 93, KE_X2RELEASE = 94, KE_DROP = 95, KE_CURSORHOLD = 96, KE_NOP = 97, KE_FOCUSGAINED = 98, KE_FOCUSLOST = 99, KE_MOUSEMOVE = 100, KE_SWIPELEFT = 101, KE_SWIPERIGHT = 102, KE_SWIPEUP = 103, KE_SWIPEDOWN = 104};
typedef struct {
    HWND server;
    char_u *reply;
    int expr_result;
} reply_T;
typedef struct {
    int jo_set;
    int jo_set2;
    ch_mode_T jo_mode;
    ch_mode_T jo_in_mode;
    ch_mode_T jo_out_mode;
    ch_mode_T jo_err_mode;
    job_io_T jo_io [4];
    char_u jo_io_name_buf [4] [NUMBUFLEN];
    char_u *jo_io_name [4];
    int jo_io_buf [4];
    int jo_pty;
    int jo_modifiable [4];
    int jo_message [4];
    channel_T *jo_channel;
    linenr_T jo_in_top;
    linenr_T jo_in_bot;
    char_u *jo_callback;
    partial_T *jo_partial;
    char_u *jo_out_cb;
    partial_T *jo_out_partial;
    char_u *jo_err_cb;
    partial_T *jo_err_partial;
    char_u *jo_close_cb;
    partial_T *jo_close_partial;
    char_u *jo_exit_cb;
    partial_T *jo_exit_partial;
    int jo_drop_never;
    int jo_waittime;
    int jo_timeout;
    int jo_out_timeout;
    int jo_err_timeout;
    int jo_block_write;
    int jo_part;
    int jo_id;
    char_u jo_soe_buf [NUMBUFLEN];
    char_u *jo_stoponexit;
    dict_T *jo_env;
    char_u jo_cwd_buf [NUMBUFLEN];
    char_u *jo_cwd;
    int jo_term_rows;
    int jo_term_cols;
    int jo_vertical;
    int jo_curwin;
    int jo_hidden;
    char_u *jo_term_name;
    char_u *jo_term_opencmd;
    int jo_term_finish;
    char_u *jo_eof_chars;
} jobopt_T;
typedef struct {
    int backspace;
    int enter;
    int interrupt;
    int nl_does_cr;
} ttyinfo_T;
typedef struct {
    void *lastoption;
    int opt_type;
} optiterinfo_T;
typedef struct {
    PyObject *callable;
    PyObject *result;
} map_rtp_data;
typedef struct _DialogInfo {
    int ignore_enter;
    int noalt;
    GtkDialog *dialog;
} DialogInfo;
typedef struct {
    nfa_state_T *state;
    int count;
    nfa_pim_T pim;
    regsubs_T subs;
} nfa_thread_T;
typedef struct _SharedFontSelData {
    Widget dialog;
    Widget ok;
    Widget cancel;
    Widget encoding_pulldown;
    Widget encoding_menu;
    Widget list [NONE];
    Widget name;
    Widget sample;
    char **names;
    int num;
    String sel [NONE];
    Boolean in_pixels;
    char *font_name;
    XFontStruct *old;
    XmFontList old_list;
    Boolean exit;
} SharedFontSelData;
typedef struct {
    int fi_semicolon;
    int fi_varcount;
    listwatch_T fi_lw;
    list_T *fi_list;
} forinfo_T;
typedef struct {
    char_u *start;
    int bytelen;
    int cells;
    int indent;
} balpart_T;
typedef struct {
    const char *name;
    int hasnum;
    long  number;
    char_u *string;
    int strlen;
    int present;
} option_table_T;
typedef struct {
    int n_collated_copies;
    int n_uncollated_copies;
    int duplex;
    int chars_per_line;
    int lines_per_page;
    int has_color;
    prt_text_attr_T number;
    int modec;
    int do_syntax;
    int user_abort;
    char_u *jobname;
    char_u *outfile;
    char_u *arguments;
} prt_settings_T;
typedef struct {
    buffheader_T sr_redobuff;
    buffheader_T sr_old_redobuff;
} save_redo_T;
typedef struct {
    listwatch_T lw;
    list_T *list;
} listiterinfo_T;
typedef struct {
    char *verb;
    Boolean sense;
} VerbSense;
typedef struct {
    regsub_T norm;
    regsub_T synt;
} regsubs_T;
typedef struct {
    int in_use;
    union {
        struct multipos {
            linenr_T start_lnum;
            linenr_T end_lnum;
            colnr_T start_col;
            colnr_T end_col;
        } multi [NSUBEXP];
        struct linepos {
            char_u *start;
            char_u *end;
        } line [NSUBEXP];
    } list;
} regsub_T;
typedef struct {
    int item_compare_ic;
    int item_compare_numeric;
    int item_compare_numbers;
    int item_compare_float;
    char_u *item_compare_func;
    partial_T *item_compare_partial;
    dict_T *item_compare_selfdict;
    int item_compare_func_err;
    int item_compare_keep_zero;
} sortinfo_T;
typedef struct {
    listitem_T *item;
    int idx;
} sortItem_T;
typedef struct {
    char_u *from;
    char_u *from_noamp;
    char_u *to;
} menutrans_T;
typedef struct {
    linenr_T lnum;
    union {
        struct {
            varnumber_T start_col_nr;
            varnumber_T end_col_nr;
        } line;
        varnumber_T value;
        float_T value_flt;
    } st_u;
} sorti_T;
typedef struct _DllVersionInfo {
    DWORD cbSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformID;
} DLLVERSIONINFO;
typedef struct {
    short  sft_score;
    char_u sft_word [1];
} sftword_T;
typedef struct AutoCmd {
    char_u *cmd;
    char nested;
    char last;
    scid_T scriptID;
    struct AutoCmd *next;
} AutoCmd;
typedef struct {
    char_u **y_array;
    linenr_T y_size;
    char_u y_type;
    colnr_T y_width;
    time_t y_time_set;
} yankreg_T;
typedef struct {
    nfa_thread_T *t;
    int n;
    int len;
    int id;
    int has_pim;
} nfa_list_T;
struct exarg;
struct lval_S;
struct timer_S;
struct js_reader;
typedef struct {
    UINT32_T total [2];
    UINT32_T state [8];
    char_u buffer [64];
} context_sha256_T;
typedef struct {
    buf_T *save_curbuf;
    int use_aucmd_win;
    win_T *save_curwin;
    win_T *new_curwin;
    bufref_T new_curbuf;
    char_u *globaldir;
} aco_save_T;
struct cmdarg_S;
struct oparg_S;
struct tabpage_S;
struct list_stack_S;
struct ht_stack_S;
struct channel_S;
typedef struct {
    sock_T ch_fd;
    void *ch_inputHandler;
    ch_mode_T ch_mode;
    job_io_T ch_io;
    int ch_timeout;
    readq_T ch_head;
    jsonq_T ch_json_head;
    int ch_block_id;
    size_t ch_wait_len;
    struct timeval ch_deadline;
    int ch_block_write;
    int ch_nonblocking;
    writeq_T ch_writeque;
    cbq_T ch_cb_head;
    char_u *ch_callback;
    partial_T *ch_partial;
    bufref_T ch_bufref;
    int ch_nomodifiable;
    int ch_nomod_error;
    int ch_buf_append;
    linenr_T ch_buf_top;
    linenr_T ch_buf_bot;
} chanpart_T;
struct cbq_S;
struct jsonq_S;
struct writeq_S;
struct readq_S;
struct partial_S;
struct funccall_S;
typedef struct {
    int uf_varargs;
    int uf_flags;
    int uf_calls;
    int uf_cleared;
    garray_T uf_args;
    garray_T uf_lines;
    int uf_profiling;
    int uf_tm_count;
    proftime_T uf_tm_total;
    proftime_T uf_tm_self;
    proftime_T uf_tm_children;
    int *uf_tml_count;
    proftime_T *uf_tml_total;
    proftime_T *uf_tml_self;
    proftime_T uf_tml_start;
    proftime_T uf_tml_children;
    proftime_T uf_tml_wait;
    int uf_tml_idx;
    int uf_tml_execed;
    scid_T uf_script_ID;
    int uf_refcount;
    funccall_T *uf_scoped;
    char_u uf_name [1];
} ufunc_T;
typedef struct {
    list_T sl_list;
    listitem_T sl_items [10];
} staticList10_T;
struct listwatch_S;
struct listitem_S;
struct hashitem_S;
struct condstack;
struct eslist_elem;
struct argentry;
struct info_pointer;
struct memfile;
typedef struct {
    int hide;
    int split;
    int tab;
    int confirm;
    int keepalt;
    int keepmarks;
    int keepjumps;
    int lockmarks;
    int keeppatterns;
    int noswapfile;
    char_u *save_ei;
    regmatch_T filter_regmatch;
    int filter_force;
} cmdmod_T;
struct expand;
struct nr_trans;
struct block_hdr;
struct mf_hashitem_S;
struct m_info;
struct u_entry;
struct foldinfo;
struct filemark;
struct object_constant;
struct numeric_constant;
typedef struct {
    PyObject_HEAD BufferObject *buf;
    PyInt start;
    PyInt end;
} RangeObject;
typedef struct {
    PyObject_HEAD TabPageObject *tabObject;
} WinListObject;
typedef struct {
    PyObject_HEAD win_T *win;
    TabPageObject *tabObject;
} WindowObject;
typedef struct {
    PyObject_HEAD tabpage_T *tab;
} TabPageObject;
typedef struct {
    PyObject_HEAD int opt_type;
    void *from;
    checkfun Check;
    PyObject *fromObj;
} OptionsObject;
typedef struct {
    PyObject_HEAD char_u *name;
    int argc;
    typval_T *argv;
    dict_T *self;
    pylinkedlist_T ref;
    int auto_rebind;
} FunctionObject;
typedef struct {
    PyObject_HEAD list_T *list;
    pylinkedlist_T ref;
} ListObject;
typedef struct {
    hashitem_T *ht_array;
    long_u ht_used;
    hashtab_T *ht;
    hashitem_T *hi;
    long_u todo;
} dictiterinfo_T;
typedef struct {
    PyObject_HEAD dict_T *dict;
    pylinkedlist_T ref;
} DictionaryObject;
struct pylinkedlist_S;
typedef struct {
    PyObject_HEAD void *cur;
    nextfun next;
    destructorfun destruct;
    traversefun traverse;
    clearfun clear;
} IterObject;
typedef struct {
    PyObject_HEAD PyObject *module;
} LoaderObject;
typedef struct {
    PyObject_HEAD long  softspace;
    long  error;
} OutputObject;
typedef struct _XmEnhancedButtonRec {
    CorePart core;
    XmPrimitivePart primitive;
    XmLabelPart label;
    XmPushButtonPart pushbutton;
    XmEnhancedButtonPart enhancedbutton;
} XmEnhancedButtonRec;
typedef struct _XmEnhancedButtonPart {
    String pixmap_data;
    String pixmap_file;
    Dimension spacing;
    int label_location;
    int pixmap_depth;
    Dimension pixmap_width;
    Dimension pixmap_height;
    Pixmap normal_pixmap;
    Pixmap armed_pixmap;
    Pixmap insensitive_pixmap;
    Pixmap highlight_pixmap;
    int doing_setvalues;
    int doing_destroy;
} XmEnhancedButtonPart;
typedef struct {
    CoreClassPart core_class;
    XmPrimitiveClassPart primitive_class;
    XmLabelClassPart label_class;
    XmPushButtonClassPart pushbutton_class;
    XmEnhancedButtonClassPart enhancedbutton_class;
} XmEnhancedButtonClassRec;
typedef struct _XmEnhancedButtonClassPart {
    Pixmap stipple_bitmap;
} XmEnhancedButtonClassPart;
typedef struct {
    btype_T bv_type;
    long  bv_nr;
    char_u *bv_string;
    int bv_len;
    int bv_allocated;
} bval_T;
struct spelltab_S;
struct langp_S;
struct salitem_S;
struct fromto_S;
struct slang_S;
typedef struct _ScrollbarClassRec {
    CoreClassPart core_class;
    SimpleClassPart simple_class;
    ScrollbarClassPart scrollbar_class;
} ScrollbarClassRec;
typedef struct {
    int empty;
} ScrollbarClassPart;
typedef struct _ScrollbarRec {
    CorePart core;
    SimplePart simple;
    ScrollbarPart scrollbar;
} ScrollbarRec;
typedef struct {
    Pixel foreground;
    XtOrientation orientation;
    XtCallbackList scrollProc;
    XtCallbackList thumbProc;
    XtCallbackList jumpProc;
    Pixmap thumb;
    float top;
    float shown;
    float max;
    Dimension length;
    Dimension thickness;
    Dimension min_thumb;
    XtIntervalId timer_id;
    char scroll_mode;
    float scroll_off;
    GC gc;
    Position topLoc;
    Dimension shownLength;
    Dimension shadow_width;
    Pixel top_shadow_pixel;
    Pixel bot_shadow_pixel;
    Bool limit_thumb;
    int top_shadow_contrast;
    int bot_shadow_contrast;
    GC top_shadow_GC;
    GC bot_shadow_GC;
} ScrollbarPart;
typedef struct {
    json_decode_T jd_type;
    typval_T jd_tv;
    typval_T jd_key_tv;
    char_u *jd_key;
} json_dec_item_T;
struct prt_dsc_comment_S;
struct prt_ps_resource_S;
struct prt_ps_charset_S;
struct prt_ps_encoding_S;
struct prt_ps_font_S;
typedef struct _SharedFindReplace {
    GtkWidget *dialog;
    GtkWidget *wword;
    GtkWidget *mcase;
    GtkWidget *up;
    GtkWidget *down;
    GtkWidget *what;
    GtkWidget *with;
    GtkWidget *find;
    GtkWidget *replace;
    GtkWidget *all;
} SharedFindReplace;
struct tag_pointers;
struct spellinfo_S;
struct wordnode_S;
struct sblock_S;
struct compitem_S;
typedef struct _SharedFindReplace {
    Widget dialog;
    Widget wword;
    Widget mcase;
    Widget up;
    Widget down;
    Widget what;
    Widget with;
    Widget find;
    Widget replace;
    Widget all;
    Widget undo;
    Widget cancel;
} SharedFindReplace;
typedef struct {
    uint32_t chars [VTERM_MAX_CHARS_PER_CELL];
    ScreenPen pen;
} ScreenCell;
typedef struct {
    VTermColor fg, bg;
    unsigned  int bold : 1;
    unsigned  int underline : 2;
    unsigned  int italic : 1;
    unsigned  int blink : 1;
    unsigned  int reverse : 1;
    unsigned  int strike : 1;
    unsigned  int font : 4;
    unsigned  int protected_cell : 1;
    unsigned  int dwl : 1;
    unsigned  int dhl : 2;
} ScreenPen;
struct digraph;
struct quality_pair;
struct charset_pair;
struct efm_S;
struct qf_list_S;
struct nv_cmd;
struct nfa_pim_S;
struct block_def;
struct fst;
typedef struct SearchedFile {
    FILE *fp;
    char_u *name;
    linenr_T lnum;
    int matched;
} SearchedFile;
struct sign;
struct tagNMTTDISPINFO_NEW;
struct tagTOOLINFOA_NEW;
struct cmdmod;
struct loop_cookie;
typedef struct {
    char_u *line;
    linenr_T lnum;
} wcmd_T;
struct ucmd;
struct source_cookie;
struct debuggy;
struct sn_prl_S;
struct scriptitem_S;
struct join_S;
struct compl_S;
struct signalinfo;
struct vimvar;
struct bw_info;
struct msgchunk_S;
struct msg_hist;
struct block0;
struct data_block;
struct pointer_block;
struct pointer_entry;
typedef struct {
    int found;
    lpos_T lpos;
} cpp_baseclass_cache_T;
struct regstar_S;
struct regitem_S;
typedef struct {
    regmatch_T *reg_match;
    regmmatch_T *reg_mmatch;
    char_u **reg_startp;
    char_u **reg_endp;
    lpos_T *reg_startpos;
    lpos_T *reg_endpos;
    win_T *reg_win;
    buf_T *reg_buf;
    linenr_T reg_firstlnum;
    linenr_T reg_maxline;
    int reg_line_lbr;
    int reg_ic;
    colnr_T reg_maxcol;
} regexec_T;
struct regbehind_S;
struct mousetable;
struct modmasktable;
typedef struct {
    int badi;
    int goodi;
    int score;
} limitscore_T;
struct syl_item_S;
struct spelload_S;
struct suggest_S;
struct suginfo_S;
typedef struct {
    typebuf_T save_typebuf;
    int typebuf_valid;
    int old_char;
    int old_mod_mask;
    buffheader_T save_readbuf1;
    buffheader_T save_readbuf2;
} tasave_T;
struct listvar_S;
typedef struct {
    int vc_type;
    int vc_factor;
    int vc_fail;
} vimconv_T;
typedef struct {
    dictitem_T sv_var;
    dict_T sv_dict;
} scriptvar_T;
typedef struct {
    char_u *pum_text;
    char_u *pum_kind;
    char_u *pum_extra;
    char_u *pum_info;
} pumitem_T;
typedef struct {
    long_u fg_color;
    long_u bg_color;
    int bold;
    int italic;
    int underline;
    int undercurl;
} prt_text_attr_T;
struct attr_entry;
typedef struct {
    char *name;
    char *magic;
    int salt_len;
    int seed_len;
    int works_inplace;
    int whole_undofile;
    int (*self_test_fn) ();
    void (*init_fn) (cryptstate_T *state, char_u *key, char_u *salt, int salt_len, char_u *seed, int seed_len);
    void (*encode_fn) (cryptstate_T *state, char_u *from, size_t len, char_u *to);
    void (*decode_fn) (cryptstate_T *state, char_u *from, size_t len, char_u *to);
    long  (*encode_buffer_fn) (cryptstate_T *state, char_u *from, size_t len, char_u **newptr);
    long  (*decode_buffer_fn) (cryptstate_T *state, char_u *from, size_t len, char_u **newptr);
    void (*encode_inplace_fn) (cryptstate_T *state, char_u *p1, size_t len, char_u *p2);
    void (*decode_inplace_fn) (cryptstate_T *state, char_u *p1, size_t len, char_u *p2);
} cryptmethod_T;
struct initmap;
typedef struct {
    short  idx;
    short  width;
    Rect box;
} vgmDlgItm;
struct dictitem16_S;
struct mapblock;
struct signlist;
struct u_header;
struct wininfo_S;
struct msglist;
typedef struct {
    union {
        char_u *ptr;
        lpos_T pos;
    } se_u;
} save_se_T;
typedef struct {
    char_u *pat;
    int len;
    char_u *head;
    int headlen;
    regmatch_T regmatch;
} pat_T;
struct spat;
typedef struct AutoPatCmd {
    AutoPat *curpat;
    AutoCmd *nextcmd;
    int group;
    char_u *fname;
    char_u *sfname;
    char_u *tail;
    event_T event;
    int arg_bufnr;
    struct AutoPatCmd *next;
} AutoPatCmd;
struct sp_syn;
typedef struct {
    int do_all;
    int do_ask;
    int do_count;
    int do_error;
    int do_print;
    int do_list;
    int do_number;
    int do_ic;
} subflags_T;
struct stl_hlrec;
typedef struct {
    vartype_T v_type;
    char v_lock;
    union {
        varnumber_T v_number;
        float_T v_float;
        char_u *v_string;
        list_T *v_list;
        dict_T *v_dict;
        partial_T *v_partial;
        job_T *v_job;
        channel_T *v_channel;
    } vval;
} typval_T;
struct server_id;
typedef struct {
    union {
        char_u *ptr;
        lpos_T pos;
    } rs_u;
    int rs_len;
} regsave_T;
struct regprog;
struct hashtable_S;
struct mf_hashtab_S;
struct nfa_state;
typedef struct {
    int save_msg_scroll;
    int save_restart_edit;
    int save_msg_didout;
    int save_State;
    int save_insertmode;
    int save_finish_op;
    int save_opcount;
    tasave_T tabuf;
} save_state_T;
struct syn_state;
typedef struct {
    char_u *linebuf;
    int linelen;
    char_u *growbuf;
    int growbufsiz;
    FILE *fd;
    typval_T *tv;
    char_u *p_str;
    listitem_T *p_li;
    buf_T *buf;
    linenr_T buflnum;
    linenr_T lnumlast;
    vimconv_T vc;
} qfstate_T;
typedef struct {
    char_u *regparse;
    int prevchr_len;
    int curchr;
    int prevchr;
    int prevprevchr;
    int nextchr;
    int at_start;
    int prev_at_start;
    int regnpar;
} parse_state_T;
struct trystate_S;
struct regengine;
typedef struct {
    short  refcnt;
    char_u *matches [NSUBEXP];
} reg_extmatch_T;
typedef struct {
    regprog_T *regprog;
    lpos_T startpos [NSUBEXP];
    lpos_T endpos [NSUBEXP];
    int rmm_ic;
    colnr_T rmm_maxcol;
} regmmatch_T;
typedef struct {
    regprog_T *regprog;
    char_u *startp [NSUBEXP];
    char_u *endp [NSUBEXP];
    int rm_ic;
} regmatch_T;
struct posmatch;
typedef struct {
    regmmatch_T rm;
    buf_T *buf;
    linenr_T lnum;
    int attr;
    int attr_cur;
    linenr_T first_lnum;
    colnr_T startcol;
    colnr_T endcol;
    int is_addpos;
    proftime_T tm;
} match_T;
typedef struct {
    regmatch_T *sm_match;
    regmmatch_T *sm_mmatch;
    linenr_T sm_firstlnum;
    linenr_T sm_maxline;
    int sm_line_lbr;
} regsubmatch_T;
struct matchinf_S;
struct wordcount_S;
typedef struct {
    int method_nr;
    void *method_state;
} cryptstate_T;
typedef struct {
    pos_T vi_start;
    pos_T vi_end;
    int vi_mode;
    colnr_T vi_curswant;
} visualinfo_T;
struct vim_exception;
struct buf_state;
typedef struct {
    buf_T *br_buf;
    int br_fnum;
    int br_buf_free_count;
} bufref_T;
typedef struct {
    buf_T *bi_buf;
    FILE *bi_fp;
    cryptstate_T *bi_state;
    char_u *bi_buffer;
    size_t bi_used;
    size_t bi_avail;
} bufinfo_T;
struct fmtpattern;
struct memline;
typedef struct DWriteRenderingParams {
    float gamma;
    float enhancedContrast;
    float clearTypeLevel;
    int pixelGeometry;
    int renderingMode;
    int textAntialiasMode;
} DWriteRenderingParams;
struct prt_dsc_line_S;
struct qfline_S;
struct dir_stack_T;
struct cmdline_info;
struct sb_line_S;
typedef struct {
    win_T *wp;
    linenr_T lnum;
    linenr_T off;
    linenr_T lnum_save;
    int lvl;
    int lvl_next;
    int start;
    int end;
    int had_end;
} fline_T;
typedef struct AutoPat {
    struct AutoPat *next;
    char_u *pat;
    regprog_T *reg_prog;
    AutoCmd *cmds;
    int group;
    int patlen;
    int buflocal_nr;
    char allow_dirs;
    char last;
} AutoPat;
struct jobvar_S;
struct keyentry;
struct specialkey;
struct keyqueue;
struct matchitem;
struct w_line;
struct qf_info_S;
struct dictitem_S;
struct dictvar_S;
struct arglist;
struct taggy;
struct xfilemark;
struct frame_S;
struct nbbuf_struct;
struct backpos_S;
typedef struct {
    regengine_T *engine;
    unsigned  regflags;
    unsigned  re_engine;
    unsigned  re_flags;
    nfa_state_T *start;
    int reganch;
    int regstart;
    char_u *match_text;
    int has_zend;
    int has_backref;
    int reghasz;
    char_u *pattern;
    int nsubexp;
    int nstate;
    nfa_state_T state [1];
} nfa_regprog_T;
typedef struct {
    regengine_T *engine;
    unsigned  regflags;
    unsigned  re_engine;
    unsigned  re_flags;
    int regstart;
    char_u reganch;
    char_u *regmust;
    int regmlen;
    char_u reghasz;
    char_u program [1];
} bt_regprog_T;
typedef struct {
    proftime_T total;
    proftime_T slowest;
    long  count;
    long  match;
} syn_time_T;
struct diffblock_S;
struct file_buffer;
struct cleanup_stuff;
struct buffheader;
struct buffblock;
typedef struct {
    PyObject_HEAD buf_T *buf;
} BufferObject;
struct prt_resfile_buffer_S;
struct affheader_S;
struct affentry_S;
struct afffile_S;
typedef struct {
    char_u *namebuf;
    char_u *errmsg;
    int errmsglen;
    long  lnum;
    int col;
    char_u use_viscol;
    char_u *pattern;
    int enr;
    int type;
    int valid;
} qffields_T;
struct soffset;
struct dbg_stuff;
typedef struct ConsoleBufferStruct {
    BOOL IsValid;
    CONSOLE_SCREEN_BUFFER_INFO Info;
    PCHAR_INFO Buffer;
    COORD BufferSize;
    PSMALL_RECT Regions;
    int NumRegions;
} ConsoleBuffer;
typedef struct {
    linenr_T lnum;
    int fill;
    int height;
} lineoff_T;
struct ff_search_ctx_T;
struct ff_visited_list_hdr;
struct ff_visited;
struct ff_stack;
struct ml_chunksize;
struct prt_mediasize_S;
typedef struct {
    VTermScreenCellAttrs attrs;
    char width;
    VTermColor fg, bg;
} cellattr_T;
struct event_name;
struct key_name_entry;
typedef struct {
    int wb_startcol;
    int wb_endcol;
    vimmenu_T *wb_menu;
} winbar_item_T;
typedef struct {
    linenr_T lnum;
    colnr_T col;
    int len;
} llpos_T;
typedef struct {
    hashtab_T b_keywtab;
    hashtab_T b_keywtab_ic;
    int b_syn_error;
    int b_syn_slow;
    int b_syn_ic;
    int b_syn_spell;
    garray_T b_syn_patterns;
    garray_T b_syn_clusters;
    int b_spell_cluster_id;
    int b_nospell_cluster_id;
    int b_syn_containedin;
    int b_syn_sync_flags;
    short  b_syn_sync_id;
    long  b_syn_sync_minlines;
    long  b_syn_sync_maxlines;
    long  b_syn_sync_linebreaks;
    char_u *b_syn_linecont_pat;
    regprog_T *b_syn_linecont_prog;
    syn_time_T b_syn_linecont_time;
    int b_syn_linecont_ic;
    int b_syn_topgrp;
    int b_syn_conceal;
    int b_syn_folditems;
    synstate_T *b_sst_array;
    int b_sst_len;
    synstate_T *b_sst_first;
    synstate_T *b_sst_firstfree;
    int b_sst_freecount;
    linenr_T b_sst_check_lnum;
    short_u b_sst_lasttick;
    garray_T b_langp;
    char_u b_spell_ismw [256];
    char_u *b_p_spc;
    regprog_T *b_cap_prog;
    char_u *b_p_spf;
    char_u *b_p_spl;
    char_u b_syn_chartab [32];
    char_u *b_syn_isk;
} synblock_T;
typedef struct {
    dict_T *fd_dict;
    char_u *fd_newkey;
    dictitem_T *fd_di;
} funcdict_T;
typedef struct {
    int wo_arab;

    # define w_p_arab w_onebuf_opt.wo_arab	/* 'arabic' */
    int wo_bri;

    # define w_p_bri w_onebuf_opt.wo_bri	/* 'breakindent' */
    char_u *wo_briopt;

    # define w_p_briopt w_onebuf_opt.wo_briopt /* 'breakindentopt' */
    int wo_diff;

    # define w_p_diff w_onebuf_opt.wo_diff	/* 'diff' */
    long  wo_fdc;

    # define w_p_fdc w_onebuf_opt.wo_fdc	/* 'foldcolumn' */
    int wo_fdc_save;

    # define w_p_fdc_save w_onebuf_opt.wo_fdc_save	/* 'foldenable' saved for diff mode */
    int wo_fen;

    # define w_p_fen w_onebuf_opt.wo_fen	/* 'foldenable' */
    int wo_fen_save;

    # define w_p_fen_save w_onebuf_opt.wo_fen_save	/* 'foldenable' saved for diff mode */
    char_u *wo_fdi;

    # define w_p_fdi w_onebuf_opt.wo_fdi	/* 'foldignore' */
    long  wo_fdl;

    # define w_p_fdl w_onebuf_opt.wo_fdl	/* 'foldlevel' */
    int wo_fdl_save;

    # define w_p_fdl_save w_onebuf_opt.wo_fdl_save	/* 'foldlevel' state saved for diff mode */
    char_u *wo_fdm;

    # define w_p_fdm w_onebuf_opt.wo_fdm	/* 'foldmethod' */
    char_u *wo_fdm_save;

    # define w_p_fdm_save w_onebuf_opt.wo_fdm_save	/* 'fdm' saved for diff mode */
    long  wo_fml;

    # define w_p_fml w_onebuf_opt.wo_fml	/* 'foldminlines' */
    long  wo_fdn;

    # define w_p_fdn w_onebuf_opt.wo_fdn	/* 'foldnestmax' */
    char_u *wo_fde;

    # define w_p_fde w_onebuf_opt.wo_fde	/* 'foldexpr' */
    char_u *wo_fdt;

    #  define w_p_fdt w_onebuf_opt.wo_fdt	/* 'foldtext' */
    char_u *wo_fmr;

    # define w_p_fmr w_onebuf_opt.wo_fmr	/* 'foldmarker' */
    int wo_lbr;

    # define w_p_lbr w_onebuf_opt.wo_lbr	/* 'linebreak' */
    int wo_list;

    #define w_p_list w_onebuf_opt.wo_list	/* 'list' */
    int wo_nu;

    #define w_p_nu w_onebuf_opt.wo_nu	/* 'number' */
    int wo_rnu;

    #define w_p_rnu w_onebuf_opt.wo_rnu	/* 'relativenumber' */
    long  wo_nuw;

    # define w_p_nuw w_onebuf_opt.wo_nuw	/* 'numberwidth' */
    int wo_wfh;

    # define w_p_wfh w_onebuf_opt.wo_wfh	/* 'winfixheight' */
    int wo_wfw;

    # define w_p_wfw w_onebuf_opt.wo_wfw	/* 'winfixwidth' */
    int wo_pvw;

    # define w_p_pvw w_onebuf_opt.wo_pvw	/* 'previewwindow' */
    int wo_rl;

    # define w_p_rl w_onebuf_opt.wo_rl	/* 'rightleft' */
    char_u *wo_rlc;

    # define w_p_rlc w_onebuf_opt.wo_rlc	/* 'rightleftcmd' */
    long  wo_scr;

    #define w_p_scr w_onebuf_opt.wo_scr	/* 'scroll' */
    int wo_spell;

    # define w_p_spell w_onebuf_opt.wo_spell /* 'spell' */
    int wo_cuc;

    # define w_p_cuc w_onebuf_opt.wo_cuc	/* 'cursorcolumn' */
    int wo_cul;

    # define w_p_cul w_onebuf_opt.wo_cul	/* 'cursorline' */
    char_u *wo_cc;

    # define w_p_cc w_onebuf_opt.wo_cc	/* 'colorcolumn' */
    char_u *wo_stl;

    #define w_p_stl w_onebuf_opt.wo_stl	/* 'statusline' */
    int wo_scb;

    # define w_p_scb w_onebuf_opt.wo_scb	/* 'scrollbind' */
    int wo_diff_saved;

    # define w_p_diff_saved w_onebuf_opt.wo_diff_saved
    int wo_scb_save;

    # define w_p_scb_save w_onebuf_opt.wo_scb_save
    int wo_wrap;

    #define w_p_wrap w_onebuf_opt.wo_wrap	/* 'wrap' */
    int wo_wrap_save;

    # define w_p_wrap_save w_onebuf_opt.wo_wrap_save
    char_u *wo_cocu;

    # define w_p_cocu w_onebuf_opt.wo_cocu
    long  wo_cole;

    # define w_p_cole w_onebuf_opt.wo_cole
    int wo_crb;

    # define w_p_crb w_onebuf_opt.wo_crb	/* 'cursorbind' */
    int wo_crb_save;

    # define w_p_crb_save w_onebuf_opt.wo_crb_save
    char_u *wo_scl;

    # define w_p_scl w_onebuf_opt.wo_scl	/* 'signcolumn' */
    char_u *wo_tk;

    #define w_p_tk w_onebuf_opt.wo_tk	/* 'termkey' */
    char_u *wo_tms;

    #define w_p_tms w_onebuf_opt.wo_tms	/* 'termsize' */
    int wo_scriptID [WV_COUNT];

    # define w_p_scriptID w_onebuf_opt.wo_scriptID
} winopt_T;
typedef struct {
    linenr_T lnum;
    colnr_T col;
} lpos_T;
typedef struct {
    linenr_T lnum;
    colnr_T col;
    colnr_T coladd;
} pos_T;
typedef struct {
    int lead_spaces;
    int print_pos;
    colnr_T column;
    linenr_T file_line;
    long_u bytes_printed;
    int ff;
} prt_pos_T;
struct growarray;
typedef struct GuiScrollbar {
    long  ident;
    win_T *wp;
    int type;
    long  value;
    long  size;
    long  max;
    int top;
    int height;
    int width;
    int status_height;
} scrollbar_T;
typedef struct {
    char_u *tn_tags;
    char_u *tn_np;
    int tn_did_filefind_init;
    int tn_hf_idx;
    void *tn_search_ctx;
} tagname_T;
struct terminal_S;
struct termcode;
struct window_S;
typedef struct Gui {
    int in_focus;
    int in_use;
    int starting;
    int shell_created;
    int dying;
    int dofork;
    int dragged_sb;
    win_T *dragged_wp;
    int pointer_hidden;
    int col;
    int row;
    int cursor_col;
    int cursor_row;
    char cursor_is_valid;
    int num_cols;
    int num_rows;
    int scroll_region_top;
    int scroll_region_bot;
    int scroll_region_left;
    int scroll_region_right;
    int highlight_mask;
    int scrollbar_width;
    int scrollbar_height;
    int left_sbar_x;
    int right_sbar_x;
    char menu_is_active;
    scrollbar_T bottom_sbar;
    int which_scrollbars [3];
    int prev_wrap;
    int char_width;
    int char_height;
    int char_ascent;
    int border_width;
    int border_offset;
    GuiFont norm_font;
    GuiFont bold_font;
    GuiFont ital_font;
    GuiFont boldital_font;
    guicolor_T back_pixel;
    guicolor_T norm_pixel;
    guicolor_T def_back_pixel;
    guicolor_T def_norm_pixel;
    int toolbar_height;
} gui_T;
typedef struct {
    char_u *tb_buf;
    char_u *tb_noremap;
    int tb_buflen;
    int tb_off;
    int tb_len;
    int tb_maplen;
    int tb_silent;
    int tb_no_abbr_cnt;
    int tb_change_cnt;
} typebuf_T;
typedef struct {
    int argc;
    char **argv;
    char_u *fname;
    int evim_mode;
    char_u *use_vimrc;
    int n_commands;
    char_u *commands [MAX_ARG_CMDS];
    char_u cmds_tofree [MAX_ARG_CMDS];
    int n_pre_commands;
    char_u *pre_commands [MAX_ARG_CMDS];
    int edit_type;
    char_u *tagname;
    char_u *use_ef;
    int want_full_screen;
    int not_a_term;
    int tty_fail;
    char_u *term;
    int ask_for_key;
    int no_swap_file;
    int use_debug_break_level;
    int window_count;
    int window_layout;
    int serverArg;
    char_u *serverName_arg;
    char_u *serverStr;
    char_u *serverStrEnc;
    char_u *servername;
    int diff_mode;
} mparm_T;
struct builtin_term;
typedef struct digraph digr_T;
typedef struct argentry aentry_T;
typedef struct foldinfo foldinfo_T;
typedef struct VimMenu vimmenu_T;
typedef void (*runner) (const char *, void *);
typedef void (*rangeinitializer) (void *);
typedef void *GuiFont;
typedef struct nfa_pim_S nfa_pim_T;
typedef struct join_S join_T;
typedef struct regitem_S regitem_T;
typedef struct DWriteContext DWriteContext;
typedef struct timer_S timer_T;
typedef enum {JIO_PIPE, JIO_NULL, JIO_FILE, JIO_BUFFER, JIO_OUT} job_io_T;
typedef struct writeq_S writeq_T;
typedef struct readq_S readq_T;
typedef enum {VAR_FLAVOUR_DEFAULT, VAR_FLAVOUR_SESSION, VAR_FLAVOUR_VIMINFO} var_flavour_T;
typedef struct m_info minfo_T;
typedef struct regbehind_S regbehind_T;
typedef struct wordnode_S wordnode_T;
typedef struct js_reader js_read_T;
typedef struct jsonq_S jsonq_T;
typedef long_u hash_T;
typedef void *GuiFontset;
typedef struct spelltab_S spelltab_T;
typedef struct salitem_S salitem_T;
typedef short  salfirst_T;
typedef struct spellinfo_S spellinfo_T;
typedef char_u result_T;
typedef union Ptrlist Ptrlist;
typedef struct sn_prl_S sn_prl_T;
typedef int waitstatus;
typedef struct regstar_S regstar_T;
typedef struct syl_item_S syl_item_T;
typedef struct spelload_S spelload_T;
typedef struct suggest_S suggest_T;
typedef struct suginfo_S suginfo_T;
typedef struct sign sign_T;
typedef struct slang_S slang_T;
typedef struct tabpage_S tabpage_T;
typedef struct fromto_S fromto_T;
typedef struct exarg exarg_T;
typedef struct oparg_S oparg_T;
typedef enum {PASTE_INSERT, PASTE_CMDLINE, PASTE_EX, PASTE_ONE_CHAR} paste_mode_T;
typedef struct u_entry u_entry_T;
typedef struct listvar_S list_T;
typedef double float_T;
typedef struct eslist_elem eslist_T;
typedef struct pylinkedlist_S pylinkedlist_T;
typedef unsigned  int int_u;
typedef struct tag_pointers tagptrs_T;
typedef void (* (*fptr_T) (int *, int)) ();
typedef struct hashitem_S hashitem_T;
typedef struct mf_hashitem_S mf_hashitem_T;
typedef struct efm_S efm_T;
typedef struct cmdarg_S cmdarg_T;
typedef struct list_stack_S list_stack_T;
typedef struct ht_stack_S ht_stack_T;
typedef enum {PART_SOCK = 0, 
#define CH_SOCK_FD	CH_PART_FD(PART_SOCK)
PART_OUT, 
# define CH_OUT_FD	CH_PART_FD(PART_OUT)
PART_ERR, 
# define CH_ERR_FD	CH_PART_FD(PART_ERR)
PART_IN, 
# define CH_IN_FD	CH_PART_FD(PART_IN)
PART_COUNT} ch_part_T;
typedef enum {MODE_NL = 0, MODE_RAW, MODE_JSON, MODE_JS} ch_mode_T;
typedef struct funccall_S funccall_T;
typedef struct listwatch_S listwatch_T;
typedef struct cbq_S cbq_T;
typedef struct cleanup_stuff cleanup_T;
typedef long  blocknr_T;
typedef int (*checkfun) (void *);
typedef int (*clearfun) (void **);
typedef int (*traversefun) (void *, visitproc, void *);
typedef void (*destructorfun) (void *);
typedef int sock_T;
typedef void *vim_acl_T;
typedef char_u schar_T;
typedef struct sblock_S sblock_T;
typedef struct compitem_S compitem_T;
typedef void (*nv_func_T) (cmdarg_T *cap);
typedef struct ucmd ucmd_T;
typedef struct scriptitem_S scriptitem_T;
typedef enum {CW_READY, CW_NOT_READY, CW_ERROR} channel_wait_result;
typedef enum {SB_CLEAR_NONE = 0, SB_CLEAR_ALL, SB_CLEAR_CMDLINE_BUSY, SB_CLEAR_CMDLINE_DONE} sb_clear_T;
typedef struct msgchunk_S msgchunk_T;
typedef enum {UB_FNAME = 0, UB_SAME_DIR, UB_CRYPT} upd_block0_T;
typedef unsigned  short  disptick_T;
typedef struct listitem_S listitem_T;
typedef struct compl_S compl_T;
typedef struct _GtkFormClass GtkFormClass;
typedef struct _GtkForm GtkForm;
typedef struct attr_entry attrentry_T;
typedef unsigned  short  sattr_T;
typedef struct langp_S langp_T;
typedef PyObject * (*hi_to_py) (hashitem_T *);
typedef struct lval_S lval_T;
typedef struct info_pointer infoptr_T;
typedef struct memfile memfile_T;
typedef struct block_hdr bhdr_T;
typedef struct expand expand_T;
typedef enum {JOB_FAILED, JOB_STARTED, JOB_ENDED, JOB_FINISHED} jobstatus_T;
typedef struct channel_S channel_T;
typedef struct partial_S partial_T;
typedef PyObject * (*nextfun) (void **);
typedef enum {HLF_8 = 0, HLF_EOB, HLF_AT, HLF_D, HLF_E, HLF_H, HLF_I, HLF_L, HLF_M, HLF_CM, HLF_N, HLF_CLN, HLF_R, HLF_S, HLF_SNC, HLF_C, HLF_T, HLF_V, HLF_VNC, HLF_W, HLF_WM, HLF_FL, HLF_FC, HLF_ADD, HLF_CHD, HLF_DED, HLF_TXD, HLF_CONCEAL, HLF_SC, HLF_SPB, HLF_SPC, HLF_SPR, HLF_SPL, HLF_PNI, HLF_PSI, HLF_PSB, HLF_PST, HLF_TP, HLF_TPS, HLF_TPF, HLF_CUC, HLF_CUL, HLF_MC, HLF_QFL, HLF_ST, HLF_STNC, HLF_COUNT} hlf_T;
typedef struct qf_list_S qf_list_T;
typedef int (*pytotvfunc) (PyObject *, typval_T *, PyObject *);
typedef enum {aid_none = 0, aid_qf_dirname_start, aid_qf_dirname_now, aid_qf_namebuf, aid_qf_errmsg, aid_qf_pattern, aid_last} alloc_id_T;
typedef enum CMD_index cmdidx_T;
typedef int scid_T;
typedef struct _XmEnhancedButtonRec *XmEnhancedButtonWidget;
typedef struct _XmEnhancedButtonClassRec *XmEnhancedButtonWidgetClass;
typedef long  idx_T;
typedef struct _ScrollbarClassRec *ScrollbarWidgetClass;
typedef struct _ScrollbarRec *ScrollbarWidget;
typedef int GtkWidget;
typedef struct filemark fmark_T;
typedef struct nfa_state nfa_state_T;
typedef enum regstate_E {RS_NOPEN = 0, RS_MOPEN, RS_MCLOSE, RS_ZOPEN, RS_ZCLOSE, RS_BRANCH, RS_BRCPLX_MORE, RS_BRCPLX_LONG, RS_BRCPLX_SHORT, RS_NOMATCH, RS_BEHIND1, RS_BEHIND2, RS_STAR_LONG, RS_STAR_SHORT} regstate_T;
typedef struct trystate_S trystate_T;
typedef enum {STATE_START = 0, STATE_NOPREFIX, STATE_SPLITUNDO, STATE_ENDNUL, STATE_PLAIN, STATE_DEL, STATE_INS_PREP, STATE_INS, STATE_SWAP, STATE_UNSWAP, STATE_SWAP3, STATE_UNSWAP3, STATE_UNROT3L, STATE_UNROT3R, STATE_REP_INI, STATE_REP, STATE_REP_UNDO, STATE_FINAL} state_T;
typedef struct regengine regengine_T;
typedef struct posmatch posmatch_T;
typedef struct matchinf_S matchinf_T;
typedef struct wordcount_S wordcount_T;
typedef struct dictitem16_S dictitem16_T;
typedef unsigned  long  uvarnumber_T;
typedef long  varnumber_T;
typedef struct mapblock mapblock_T;
typedef struct signlist signlist_T;
typedef struct u_header u_header_T;
typedef struct wininfo_S wininfo_T;
typedef struct timeval proftime_T;
typedef struct buf_state bufstate_T;
typedef struct memline memline_T;
typedef struct qfline_S qfline_T;
typedef struct sb_line_S sb_line_T;
typedef struct vim_exception except_T;
typedef enum auto_event event_T;
typedef struct keyentry keyentry_T;
typedef struct keyqueue keyQ_T;
typedef long  __w64 long_i;
typedef struct regprog regprog_T;
typedef struct hashtable_S hashtab_T;
typedef struct syn_state synstate_T;
typedef struct mf_hashtab_S mf_hashtab_T;
typedef unsigned  short  short_u;
typedef struct diffblock_S diff_T;
typedef struct buffheader buffheader_T;
typedef struct buffblock buffblock_T;
typedef off_t off_T;
typedef struct affheader_S affheader_T;
typedef struct affentry_S affentry_T;
typedef struct afffile_S afffile_T;
typedef struct ff_search_ctx_T ff_search_ctx_T;
typedef struct ff_visited_list_hdr ff_visited_list_hdr_T;
typedef struct ff_visited ff_visited_T;
typedef struct ff_stack ff_stack_T;
typedef struct ml_chunksize chunksize_T;
typedef struct jobvar_S job_T;
typedef enum {JSON_ARRAY, JSON_OBJECT_KEY, JSON_OBJECT} json_decode_T;
typedef struct matchitem matchitem_T;
typedef struct w_line wline_T;
typedef struct qf_info_S qf_info_T;
typedef struct dictitem_S dictitem_T;
typedef struct dictvar_S dict_T;
typedef struct arglist alist_T;
typedef struct taggy taggy_T;
typedef struct xfilemark xfmark_T;
typedef struct file_buffer buf_T;
typedef struct frame_S frame_T;
typedef struct growarray garray_T;
typedef long  linenr_T;
typedef unsigned  long  __w64 long_u;
typedef enum {VW_POS_MOUSE, VW_POS_CENTER, VW_POS_TOP_CENTER} gui_win_pos_T;
typedef struct nbbuf_struct nbbuf_T;
typedef struct backpos_S backpos_T;
typedef int colnr_T;
typedef long  guicolor_T;
typedef struct terminal_S term_T;
typedef time_t time_T;
typedef enum {TYPE_UNKNOWN = 0, TYPE_EQUAL, TYPE_NEQUAL, TYPE_GREATER, TYPE_GEQUAL, TYPE_SMALLER, TYPE_SEQUAL, TYPE_MATCH, TYPE_NOMATCH} exptype_T;
typedef enum {VAR_UNKNOWN = 0, VAR_NUMBER, VAR_STRING, VAR_FUNC, VAR_PARTIAL, VAR_LIST, VAR_DICT, VAR_FLOAT, VAR_SPECIAL, VAR_JOB, VAR_CHANNEL} vartype_T;
typedef enum {ET_USER, ET_ERROR, ET_INTERRUPT} except_type_T;
typedef enum {ASSERT_EQUAL, ASSERT_NOTEQUAL, ASSERT_MATCH, ASSERT_NOTMATCH, ASSERT_OTHER} assert_type_T;
typedef enum {BVAL_NR, BVAL_STRING, BVAL_EMPTY} btype_T;
typedef enum {MATCH_END, MATCH_MATCH, MATCH_STR, MATCH_LIST, MATCH_POS} matchtype_T;
typedef struct stat stat_T;
typedef struct window_S win_T;
typedef void (*writefn) (char_u *);
typedef unsigned  char char_u;
extern OutputObject Output;
extern writefn old_fn;
extern EXTERN int p_write;
extern EXTERN int p_wmnu;
extern EXTERN int p_warn;
extern EXTERN char_u *p_viminfofile;
extern EXTERN char_u *p_viminfo;
extern EXTERN long  p_ut;
extern EXTERN char_u *p_ttym;
extern EXTERN int p_tf;
extern EXTERN int p_tbi;
extern EXTERN int p_ta;
extern EXTERN int p_tr;
extern EXTERN long  p_tl;
extern EXTERN char_u *p_tal;
extern EXTERN long  p_tpm;
extern EXTERN char_u *p_rtp;
extern EXTERN long  p_report;
extern EXTERN long  p_rdt;
extern EXTERN char_u *p_pt;
extern EXTERN long  p_mmt;
extern EXTERN long  p_mat;
extern EXTERN int p_lnr;
extern EXTERN char_u *p_langmap;
extern EXTERN int p_prompt;
extern EXTERN char_u *p_popt;
extern EXTERN char_u *p_pfn;
extern EXTERN char_u *p_breakat;
extern EXTERN char *ignoredp;
extern EXTERN int ignored;
extern EXTERN char_u e_nbreadonly [];
extern EXTERN char_u e_write [];
extern EXTERN char_u e_wildexpand [];
extern EXTERN char_u e_trailing [];
extern EXTERN char_u e_readonly [];
extern EXTERN char_u e_number_exp [];
extern EXTERN char_u e_null [];
extern EXTERN char_u e_notread [];
extern EXTERN char_u e_norange [];
extern EXTERN char_u e_nomap [];
extern EXTERN char_u e_nobang [];
extern EXTERN char_u e_noabbr [];
extern EXTERN char_u e_noalt [];
extern EXTERN char_u e_invrange [];
extern EXTERN char_u e_interr [];
extern EXTERN char_u e_intern2 [];
extern EXTERN char_u e_internal [];
extern EXTERN char_u e_abort [];
extern EXTERN linenr_T printer_page_num;
extern VTerm *vt;
extern int prt_tumble;
extern int prt_portrait;
extern int prt_media;
extern int prt_page_num;
extern float prt_text_run;
extern taggy_T ptag_entry;
extern int menu_enabled;
extern Widget menuBar;
extern Widget textArea;
extern VALUE eDeletedWindowError;
extern VALUE objtbl;
extern int ruby_initialized;
extern digr_T digraphdefault [];
extern int WSInitialized;
extern qf_info_T ql_info;
extern XtInputId inputHandler;
extern XtIntervalId timer;
extern Widget menuBar;
extern Widget textArea;
extern proftime_T *nfa_time_limit;
extern char *e_auabort;
extern int expand_emenu;
extern vimmenu_T *expand_menu_alt;
extern vimmenu_T *expand_menu;
extern char_u e_nomenu [];
extern char *tent;
extern TECObjectRef gUTF16ToUTF8Converter;
extern TECObjectRef gPathConverter;
extern HWND g_hWnd;
extern HANDLE g_hConOut;
extern HANDLE g_hConIn;
extern char *m_onlyone;
extern proftime_T prof_wait_time;
extern int old_indent;
extern char *e_letwrong;
extern char *e_letunexp;
extern int already_warned;
extern char *e_printf;
extern BPTR raw_in;
extern char *e_nofold;
extern int need_gather;
extern ATSUStyle gFontStyle;
extern RgnHandle dragRgn;
extern char_u *reginput;
extern int regnzpar;
extern CurrentObject TheCurrent;
extern float floatZero;
extern EXTERN char_u e_readonlyvar [];
extern EXTERN char_u e_noroom [];
extern char *e_illvar;
extern char *e_undefvar;
extern EXTERN char_u e_umark [];
extern EXTERN long  p_window;
extern BOOL win8_or_later;
extern foldinfo_T win_foldinfo;
extern struct Window *wb_window;
extern EventHandlerUPP winEventHandlerUPP;
extern EXTERN long  p_hi;
extern EXTERN char_u e_while [];
extern RETSIGTYPE deathtrap SIGPROTOARG;
extern int prt_file_error;
extern EXTERN char_u *empty_option;
extern Frag_T empty;
extern EXTERN char_u *p_titleold;
extern EXTERN int p_title;
extern char_u *oldtitle;
extern char_u *oldwindowtitle;
extern int nfa_ll_index;
extern int xt_index_in;
extern PyObject *py_find_module;
extern int prt_duplex;
extern int needupdate;
extern int g_fWindInitCalled;
extern pumitem_T *balloon_array;
extern char_u e_z1_not_allowed [];
extern char_u e_z_not_allowed [];
extern EXTERN char_u e_openerrf [];
extern char_u e_not_open [];
extern XtIntervalId blink_timer;
extern long_u blink_ontime;
extern long_u blink_waittime;
extern long_u blink_ontime;
extern long_u blink_waittime;
extern UINT blink_timer;
extern long_u blink_ontime;
extern long_u blink_waittime;
extern EXTERN char_u e_invaddr [];
extern char *sysdrive;
extern TabListObject TheTabPageList;
extern WinListObject TheWindowList;
extern char *CurrentAttrs [];
extern PyMappingMethods BufMapAsMapping;
extern char *RangeAttrs [];
extern char *WindowAttrs [];
extern char *TabPageAttrs [];
extern PyMappingMethods OptionsAsMapping;
extern PySequenceMethods OptionsAsSeq;
extern PyMappingMethods ListAsMapping;
extern PySequenceMethods ListAsSeq;
extern char *ListAttrs [];
extern char *OutputAttrs [];
extern PyObject *globals;
extern char_u e_py_systemexit [];
extern char ** (built_in_pixmaps []);
extern EXTERN int p_ws;
extern EXTERN long  p_verbose;
extern EXTERN char_u *p_tbis;
extern EXTERN long  p_transp;
extern EXTERN char_u *p_tsr;
extern EXTERN int p_terse;
extern EXTERN int p_tgst;
extern EXTERN char_u *p_tags;
extern EXTERN int p_tbs;
extern EXTERN char_u *p_swb;
extern EXTERN char_u *p_sws;
extern EXTERN char_u *p_su;
extern EXTERN int p_sol;
extern EXTERN int p_spr;
extern EXTERN char_u *p_sps;
extern EXTERN int p_sb;
extern EXTERN int p_sta;
extern EXTERN long  p_siso;
extern EXTERN long  p_ss;
extern EXTERN int p_smd;
extern EXTERN int p_sm;
extern EXTERN int p_sft;
extern EXTERN char_u *p_sbr;
extern EXTERN char_u *p_shm;
extern EXTERN int p_sr;
extern EXTERN char_u *p_stl;
extern EXTERN char_u *p_srr;
extern EXTERN char_u *p_sxe;
extern EXTERN char_u *p_sxq;
extern EXTERN char_u *p_shq;
extern EXTERN char_u *p_sp;
extern EXTERN char_u *p_sh;
extern EXTERN char_u *p_ssop;
extern EXTERN char_u *p_slm;
extern EXTERN char_u *p_sel;
extern EXTERN char_u *p_sbo;
extern EXTERN long  p_so;
extern EXTERN long  p_sj;
extern EXTERN int p_paste;
extern EXTERN long  p_mouset;
extern EXTERN char_u *p_mousem;
extern EXTERN int p_mousef;
extern EXTERN char_u *p_mouse;
extern EXTERN long  p_mls;
extern EXTERN char_u *p_msm;
extern EXTERN long  p_mis;
extern EXTERN long  p_stal;
extern EXTERN long  p_ls;
extern EXTERN int p_js;
extern EXTERN char_u *p_isp;
extern EXTERN char_u *p_isi;
extern EXTERN char_u *p_isf;
extern EXTERN int p_is;
extern EXTERN int p_arshape;
extern EXTERN char_u *p_mouseshape;
extern EXTERN char_u *p_fuoptions;
extern EXTERN long  p_fdls;
extern EXTERN char_u *p_bsk;
extern EXTERN char_u *p_bs;
extern EXTERN char_u e_shellempty [];
extern EXTERN char_u e_listreq [];
extern EXTERN char_u e_readonlysbx [];
extern EXTERN char_u e_noserver [];
extern EXTERN char_u e_nopresub [];
extern EXTERN char_u e_noinstext [];
extern EXTERN char_u e_nesting [];
extern EXTERN char_u e_marknotset [];
extern EXTERN char_u e_exists [];
extern EXTERN char *netbeansArg;
extern EXTERN char_u *serverName;
extern EXTERN option_table_T printer_opts [OPT_PRINT_NUM_OPTIONS];
extern EXTERN long  sub_nsubs;
extern EXTERN alist_T global_alist;
extern EXTERN tabpage_T *first_tabpage;
extern EXTERN win_T *firstwin;
extern EXTERN char_u hash_removed;
extern EXTERN short  *TabPageIdxs;
extern EXTERN char_u *LineWraps;
extern EXTERN char_u farsi_text_5 [];
extern EXTERN char_u farsi_text_3 [];
extern EXTERN char_u farsi_text_2 [];
extern EXTERN char_u farsi_text_1 [];
extern SPELL_EXTERN spelltab_T spelltab;
extern SPELL_EXTERN char_u *int_wordlist;
extern SPELL_EXTERN slang_T *first_lang;
extern struct prt_resfile_buffer_S prt_resfile;
extern FILE *prt_ps_fd;
extern char osver [];
extern char version [];
extern char * (main_errors []);
extern xfmark_T *vi_jumplist;
extern int dialogStatus;
extern garray_T user_digraphs;
extern const LOGFONT s_lfDefault;
extern garray_T reply_list;
extern HWND message_window;
extern int undo_undoes;
extern int is_ignore_draw;
extern PhPoint_t abs_mouse;
extern Boolean save_files;
extern int sd;
extern char defaultTranslations [];
extern int dialogStatus;
extern XtTranslations menuTrans;
extern XtTranslations parentTrans;
extern XtTranslations popupTrans;
extern char_u sha256_padding [64];
extern yankreg_T *y_read_regs;
extern yankreg_T y_regs [NUM_REGISTERS];
extern sortinfo_T *sortinfo;
extern garray_T ga_userinput;
extern int save_level;
extern VTermColor ansi_table [16];
extern int expand_isabbrev;
extern mapblock_T *first_abbr;
extern mapblock_T * (maphash [256]);
extern garray_T menutrans_ga;
extern char_u e_notsubmenu [];
extern long  _bauds [16];
extern short  ospeed;
extern char_u *old_sub;
extern int sort_abort;
extern int sort_flt;
extern int sort_rx;
extern int sort_nr;
extern int s_usenewlook;
extern void TrackUserActivity (UINT uMsg);
extern UINT s_wait_timer;
extern char_u *s_textfield;
extern UINT s_uMsg;
extern HWND s_textArea;
extern LPARAM s_lParam;
extern WPARAM s_wParam;
extern HBRUSH s_brush;
extern HINSTANCE s_hinst;
extern int destroying;
extern HMENU s_menuBar;
extern int ex_pressedreturn;
extern char g_szOrigTitle [256];
extern int g_yMouse;
extern int g_xMouse;
extern int g_fMouseAvail;
extern int g_fCtrlCPressed;
extern int g_fCBrkPressed;
extern proftime_T pause_time;
extern timer_T *first_timer;
extern int debug_skipped;
extern job_T *first_job;
extern list_T *first_list;
extern int ins_need_undo;
extern int revins_legal;
extern int revins_on;
extern int new_insert_skip;
extern dictitem_T vimvars_var;
extern dictitem_T globvars_var;
extern garray_T ignore_error_list;
extern FILE *verbose_fd;
extern struct IntuitionBase *IntuitionBase;
extern linenr_T lowest_marked;
extern int pum_first;
extern int disable_flush;
extern short  *gDialogHotKeys;
extern char_u *ta_str;
extern garray_T ga_users;
extern regsubmatch_T rsm;
extern int re_has_z;
extern char_u e_empty_sb [];
extern char_u e_missing_sb [];
extern char_u e_reverse_range [];
extern void _cdecl SaveInst (HINSTANCE hInst);
extern sftword_T dumsft;
extern int sps_limit;
extern sign_T *first_sign;
extern volatile int deadly_signal;
extern char_u e_nul_found [];
extern int old_mod_mask;
extern EXTERN int p_guipty;
extern int prt_font;
extern int prt_need_font;
extern struct prt_ps_font_S *prt_ps_font;
extern PtWidget_t *gui_ph_dialog_text;
extern PtCallbackF_t gui_ph_handle_menu_unrealized;
extern PtCallbackF_t gui_ph_handle_menu;
extern PtCallbackF_t gui_ph_handle_pulldown_menu;
extern PtCallbackF_t gui_ph_handle_mouse;
extern LOGFONT sub_logfont;
extern EXTERN char_u *p_toolbar;
extern EXTERN int p_to;
extern EXTERN char_u e_toomany [];
extern EXTERN char_u e_toomsbra [];
extern int prt_do_moveto;
extern int prt_need_moveto;
extern int ramp24 [];
extern Atom wm_atoms [2];
extern unsigned  char etoa64 [];
extern Widget toolBar;
extern Widget toolBarFrame;
extern PhImage_t *gui_ph_toolbar_images [];
extern Atom dialogatom;
extern Widget toolBar;
extern int dialog_default_button;
extern char_u *reg_tofree;
extern int reg_toolong;
extern char_u *repl_to;
extern char_u *repl_from;
extern EXTERN char_u e_toomanyarg [];
extern EXTERN char_u e_invarg2 [];
extern EXTERN char_u e_invarg [];
extern EXTERN char_u e_argreq [];
extern EXTERN char_u *edit_submode_extra;
extern EXTERN char_u *edit_submode_pre;
extern EXTERN char_u *edit_submode;
extern float prt_bottom_margin;
extern float prt_right_margin;
extern float prt_left_margin;
extern int VIsual_mode_orig;
extern int resel_VIsual_mode;
extern char *e_listarg;
extern int expand_mapmodes;
extern int expand_modes;
extern char_u *extra_shell_arg;
extern EXTERN struct msglist **msg_list;
extern EXTERN char_u *keep_msg;
extern char_u *bottommsg;
extern char *sha_self_test_msg [];
extern char *msg_qflist;
extern struct msg_hist *first_msg_hist;
extern EXTERN char_u *p_header;
extern HWND vim_parent_hwnd;
extern HWND s_toolbarhwnd;
extern HWND s_hwnd;
extern void _OnPaint (HWND hwnd);
extern int interactive;
extern PyObject * WinListNew (TabPageObject *tabObject);
extern char *FunctionAttrs [];
extern PyMappingMethods DictionaryAsMapping;
extern PySequenceMethods DictionaryAsSeq;
extern char *DictionaryAttrs [];
extern PyObject *py_getcwd;
extern EXTERN long  p_wic;
extern EXTERN long  p_wcm;
extern EXTERN long  p_wc;
extern EXTERN char_u *p_fcs;
extern EXTERN long  p_uc;
extern EXTERN long  p_ttyscroll;
extern EXTERN int p_ttimeout;
extern EXTERN int p_timeout;
extern EXTERN int p_tgc;
extern EXTERN char_u *p_tc;
extern EXTERN int p_scs;
extern EXTERN int p_sc;
extern EXTERN char_u *p_shcf;
extern EXTERN char_u *p_sections;
extern EXTERN char_u *p_opfunc;
extern EXTERN char_u *p_cc;
extern EXTERN char_u *p_scl;
extern EXTERN int p_magic;
extern EXTERN int p_macthinstrokes;
extern EXTERN int p_macligatures;
extern EXTERN char_u *p_lcs;
extern EXTERN int p_ic;
extern EXTERN int p_icon;
extern EXTERN char_u *p_penc;
extern EXTERN int p_fullscreen;
extern EXTERN char_u *p_fcl;
extern EXTERN long  p_fic;
extern EXTERN char_u *p_dict;
extern EXTERN char_u *p_inc;
extern EXTERN char_u *p_cpo;
extern EXTERN char_u *p_cot;
extern EXTERN int p_cp;
extern EXTERN long  p_ch;
extern EXTERN int p_beval;
extern EXTERN char_u *p_cm;
extern EXTERN char_u *p_bkc;
extern EXTERN int p_acd;
extern EXTERN int *eval_lavars_used;
extern EXTERN char_u e_toocompl [];
extern EXTERN char_u e_tagstack [];
extern EXTERN char_u e_swapclose [];
extern EXTERN char_u e_scroll [];
extern EXTERN char_u e_screenmode [];
extern EXTERN char_u e_listdictarg [];
extern EXTERN char_u e_dictreq [];
extern EXTERN char_u e_re_corr [];
extern EXTERN char_u e_loclist [];
extern EXTERN char_u e_quickfix [];
extern EXTERN char_u e_outofmem [];
extern EXTERN char_u e_notcreate [];
extern EXTERN char_u e_markinval [];
extern EXTERN char_u e_invargNval [];
extern EXTERN char_u e_backslash [];
extern EXTERN char_u langmap_mapchar [256];
extern EXTERN char_u *escape_chars;
extern EXTERN FILE *scriptout;
extern EXTERN FILE *scriptin [NSCRIPT];
extern EXTERN cmdmod_T cmdmod;
extern EXTERN win_T *aucmd_win;
extern EXTERN int called_emsg;
extern EXTERN int called_vim_beep;
extern EXTERN dict_T globvardict;
extern EXTERN dict_T vimvardict;
extern EXTERN sattr_T *ScreenAttrs;
extern EXTERN schar_T *ScreenLines;
extern void DWriteContext_Close (DWriteContext *ctx);
extern void DWriteContext_Flush (DWriteContext *ctx);
extern VTermScreenCallbacks screen_cbs;
extern int want_screen_scrollback;
extern int want_screen_damage_cells;
extern int want_screen_damage;
extern int want_moverect;
extern int want_scrollrect;
extern VTermParserCallbacks parser_cbs;
extern VTermEncodingInstance encoding;
extern VTermScreen *screen;
extern int prt_num_copies;
extern struct prt_ps_font_S prt_ps_courier_font;
extern VTermEncoding encoding_usascii;
extern VTermEncoding encoding_utf8;
extern XtResource vim_resources [];
extern long  compress_added;
extern long  compress_inc;
extern char *msg_compressing;
extern char *e_spell_trunc;
extern int has_dash_c_arg;
extern int A_is_special (int c);
extern int A_is_valid (int c);
extern int A_is_ok (int c);
extern int A_is_formb (int c);
extern int A_is_iso (int c);
extern int A_is_harakat (int c);
extern const VTermParserCallbacks parser_callbacks;
extern VTermAllocatorFunctions default_allocator;
extern VALUE cVimWindow;
extern int reply_received;
extern char_u *client_enc;
extern char *e_loc_list_changed;
extern PtCallbackF_t gui_ph_handle_focus;
extern PtCallbackF_t gui_ph_handle_scrollbar;
extern PtCallbackF_t gui_ph_handle_window_cb;
extern PtCallbackF_t gui_ph_handle_timer_timeout;
extern struct PxTransCtrl *charset_translate;
extern short  is_timeout;
extern PtWidget_t *gui_ph_timer_timeout;
extern ScrollbarClassRec vim_scrollbarClassRec;
extern XtActionsRec actions [];
extern XtResource resources [];
extern XtActionsRec pullAction [2];
extern char *sha_self_test_vector [];
extern char crypt_magic_head [];
extern int showcmd_visual;
extern int showcmd_is_clear;
extern int *nfa_timed_out;
extern char_u e_ill_char_class [];
extern char_u e_misplaced [];
extern char *msg_loclist;
extern char opchars [] [3];
extern int inputsecret_flag;
extern int cls_bigword;
extern int cmd_fkmap;
extern int cmd_hkmap;
extern int extra_char_shift;
extern int extra_char;
extern int cmd_showtail;
extern VTermScreenCallbacks screen_callbacks;
extern int inAtomic;
extern int r_cmdno;
extern channel_T *nb_channel;
extern int old_char;
extern int block_redo;
extern char_u menu_mode_chars [];
extern char *cmds [];
extern int viminfo_errcnt;
extern int sort_ic;
extern const char *dlg_icons [];
extern DWORD LastActivity;
extern UINT_PTR BevalTimerId;
extern int s_timed_out;
extern int s_getting_focus;
extern int s_need_activate;
extern WNDPROC s_toolbar_wndproc;
extern HDC s_hdc;
extern int s_busy_processing;
extern int cause_abort;
extern char_u dollar_command [2];
extern garray_T ucmds;
extern DWORD g_cmodeout;
extern DWORD g_cmodein;
extern CONSOLE_CURSOR_INFO g_cci;
extern BOOL g_fCanChangeIcon;
extern HICON g_hVimIcon;
extern HICON g_hOrigIcon;
extern HICON g_hOrigIconSmall;
extern int g_nMouseClick;
extern int g_fMouseActive;
extern BOOL g_fJustGotFocus;
extern int g_fForceExit;
extern COORD g_coord;
extern SMALL_RECT g_srScrollRegion;
extern int redrawing_for_callback;
extern proftime_T inchar_time;
extern char *pexpand_cmds [];
extern char_u *debug_newval;
extern char_u *debug_oldval;
extern garray_T script_items;
extern char *e_cannot_connect;
extern channel_T *first_channel;
extern int safe_to_invoke_callback;
extern int channel_need_redraw;
extern dict_T *first_dict;
extern char *e_nofunc;
extern char *e_funcref;
extern char *e_funcdict;
extern char *e_funcexts;
extern garray_T funcargs;
extern hashtab_T func_hashtab;
extern long  replace_stack_nr;
extern char_u *replace_stack;
extern char_u pc_bytes [MB_MAXBYTES + 1];
extern int pc_status;
extern int dont_sync_undo;
extern int revins_chars;
extern int can_cindent;
extern int compl_opt_refresh_always;
extern expand_T compl_xp;
extern int compl_cont_mode;
extern char_u *compl_orig_text;
extern int compl_busy;
extern int ctrl_x_mode;
extern int compl_was_interrupted;
extern int compl_no_select;
extern int compl_no_insert;
extern int compl_get_longest;
extern char_u *compl_leader;
extern int compl_enter_selects;
extern char *ctrl_x_msgs [];
extern volatile int in_mch_delay;
extern char_u *oldicon;
extern garray_T ga_scripts;
extern char *e_dictrange;
extern char *e_missbrac;
extern int autocmd_nested;
extern int autocmd_blocked;
extern int au_need_clean;
extern AutoPatCmd *active_apc_list;
extern int default_reload_choice;
extern sb_clear_T do_clear_sb_text;
extern int emsg_to_channel_log;
extern int close_win;
extern BPTR raw_out;
extern int process_still_running;
extern int fold_changed;
extern int pum_scrollbar;
extern int pum_selected;
extern int xt_index_out;
extern RGBColor specialColor;
extern UInt32 useAntialias_cached;
extern Boolean gIsFontFallbackSet;
extern ControlActionUPP gScrollDrag;
extern ControlActionUPP gScrollAction;
extern short  clickIsPopup;
extern short  dragRectControl;
extern short  dragRectEnbl;
extern Rect dragRect;
extern TSMDocumentID gTSMDocument;
extern int im_is_active;
extern long  bl_minval;
extern garray_T regstack;
extern char_u *classchars;
extern int reg_cpo_bsl;
extern int reg_cpo_lit;
extern int reg_strict;
extern int reg_magic;
extern int one_exactly;
extern long  brace_min [10];
extern int num_complex_braces;
extern short  class_tab [256];
extern char_u e_missingbracket [];
extern int im_was_set_active;
extern char_u g_chartab [256];
extern int chartab_initialized;
extern void *fdip_search_ctx;
extern int spell_expand_need_cap;
extern EXTERN char_u *p_lispwords;
extern EXTERN char_u e_invcmd [];
extern int dosetvisible;
extern int regnpar;
extern char_u *regparse;
extern EXTERN char_u *p_pexpr;
extern EXTERN char_u *p_bexpr;
extern EXTERN proftime_T bevalexpr_due;
extern EXTERN char_u e_invexpr2 [];
extern int nfa_has_zsubexpr;
extern int debug_expr;
extern int need_clear_zsubexpr;
extern int need_clear_subexpr;
extern EXTERN char_u e_au_recursive [];
extern EXTERN char_u e_secure [];
extern EXTERN pos_T saved_cursor;
extern EXTERN tabpage_T *curtab;
extern EXTERN win_T *curwin;
extern EXTERN int current_scrollbar;
extern EXTERN vimmenu_T *current_menu;
extern int want_movecursor;
extern long_u curr_fg;
extern long_u curr_bg;
extern int curr_bold;
extern int curr_italic;
extern int A_is_f (int cur_c);
extern int A_is_s (int cur_c);
extern int A_is_a (int cur_c);
extern PtCallbackF_t gui_ph_handle_timer_cursor;
extern PtWidget_t *gui_ph_timer_cursor;
extern vimmenu_T *a_cur_menu;
extern yankreg_T *y_current;
extern int desired_cursor_blink;
extern int desired_cursor_shape;
extern BalloonEval *cur_beval;
extern int s_cursor_visible;
extern schar_T *current_ScreenLine;
extern funccall_T *current_funccal;
extern int tv_equal_recurse_limit;
extern int current_copyID;
extern int initial_cursor_blink;
extern int initial_cursor_shape_blink;
extern int initial_cursor_shape;
extern int can_update_cursor;
extern RgnHandle cursorRgn;
extern int curchr;
extern EXTERN long  p_ttm;
extern EXTERN long  p_tm;
extern EXTERN int p_stmp;
extern EXTERN int p_lrm;
extern EXTERN int p_confirm;
extern EXTERN char_u e_invexprmsg [];
extern EXTERN char_u e_notmp [];
extern SPELL_EXTERN char e_format [];
extern int prt_attribute_change;
extern Widget textAreaForm;
extern Widget vimForm;
extern Pixmap pullerBitmap;
extern XtTranslations supermenuTrans;
extern Widget vimForm;
extern cryptmethod_T cryptmethods [CRYPT_M_COUNT];
extern char_u e_othermode [];
extern LOGFONT norm_logfont;
extern int quitmore;
extern WORD g_attrPreStandout;
extern int g_fTermcapMode;
extern ConsoleBuffer g_cbTermcap;
extern ConsoleBuffer g_cbNonTermcap;
extern DWORD g_PlatformId;
extern WORD g_attrCurrent;
extern WORD g_attrDefault;
extern int screen_char_attr;
extern int screen_attr;
extern int pc_attr;
extern int curr_tmode;
extern int echo_attr;
extern char_u *confirm_msg_tail;
extern char_u *confirm_msg;
extern int confirm_msg_used;
extern EXTERN char_u *p_titlestring;
extern EXTERN char_u *p_iconstring;
extern char *e_stringreq;
extern char *e_float_as_string;
extern int reg_string;
extern pylinkedlist_T *lastfunc;
extern pylinkedlist_T *lastlist;
extern pylinkedlist_T *lastdict;
extern PyObject *vim_special_path_object;
extern const char *vim_special_path;
extern EXTERN char_u *p_cdpath;
extern EXTERN char_u *p_path;
extern EXTERN char_u e_invalpat [];
extern EXTERN char_u e_patnotf2 [];
extern EXTERN char_u e_patnotf [];
extern EXTERN char_u e_nolastcmd [];
extern EXTERN char_u e_nogroup [];
extern EXTERN pos_T last_cursormoved;
extern EXTERN win_T *lastwin;
extern int last_shape;
extern int lastmark;
extern int last_shape;
extern char_u *lasticon;
extern char_u *lasttitle;
extern int execreg_lastc;
extern struct spat saved_last_search_spat;
extern int last_t_cmd;
extern char_u lastc [2];
extern int last_set_cursor_blink;
extern int last_set_cursor_shape;
extern char_u *exe_path;
extern int last_breakp;
extern int last_insert_skip;
extern char_u *last_insert;
extern hashtab_T compat_hashtab;
extern int include_groups;
extern int last_group;
extern int current_augroup;
extern char_u *deleted_augroup;
extern garray_T augroups;
extern msgchunk_T *last_msgchunk;
extern struct msg_hist *last_msg_hist;
extern int p_macatsui_last;
extern long  lastMouseTick;
extern char_u e_pathtoolong [];
extern EXTERN unsigned  ve_flags;
extern EXTERN unsigned  vop_flags;
extern EXTERN unsigned  ttym_flags;
extern EXTERN unsigned  tbis_flags;
extern EXTERN unsigned  toolbar_flags;
extern EXTERN unsigned  tc_flags;
extern EXTERN unsigned  ssop_flags;
extern EXTERN unsigned  fuoptions_flags;
extern EXTERN unsigned  fdo_flags;
extern EXTERN unsigned  dy_flags;
extern EXTERN unsigned  bo_flags;
extern EXTERN unsigned  bkc_flags;
extern EXTERN char_u wim_flags [4];
extern EXTERN char breakat_flags [256];
extern char_u META_flags [];
extern int sps_flags;
extern EXTERN char_u e_noprevre [];
extern EXTERN char_u e_noprev [];
extern EXTERN win_T *prevwin;
extern struct timeval prev_timeval;
extern yankreg_T *y_previous;
extern char_u *prevcmd;
extern funccall_T *previous_funccal;
extern int prevprevchr;
extern int prevchr;
extern char_u *reg_prev_sub;
extern EXTERN int p_hls;
extern EXTERN char_u *p_hl;
extern EXTERN char_u *p_hlg;
extern EXTERN char_u e_positive [];
extern EXTERN hlf_T edit_submode_highl;
extern EXTERN int highlight_attr [HLF_COUNT];
extern float prt_pos_y;
extern float prt_pos_x;
extern float prt_pos_y_moveto;
extern float prt_pos_x_moveto;
extern int popup_mouse_pos;
extern XtExposeProc old_label_expose;
extern int *post_ptr;
extern int saved_no_hlsearch;
extern int new_cmdpos;
extern match_T search_hl;
extern int out_pos;
extern regsave_T behind_pos;
extern garray_T backpos;
extern int nextchr;
extern int runtimeidx;
extern const unsigned  char cmdidxs2 [26] [26];
extern const unsigned  short  cmdidxs1 [26];
extern EXTERN int p_tbidi;
extern EXTERN int p_hid;
extern EXTERN char_u e_usingsid [];
extern EXTERN char_u e_listidx [];
extern EXTERN int ru_wid;
extern EXTERN int did_uncaught_emsg;
extern SPELL_EXTERN int did_set_spelltab;
extern int current_syn_id;
extern SharedFindReplace repl_widgets;
extern SharedFindReplace find_widgets;
extern const char * const menu_stock_ids [];
extern int mshape_ids [];
extern SharedFindReplace repl_widgets;
extern SharedFindReplace find_widgets;
extern int_u last_qf_id;
extern int mshape_ids [];
extern WidgetClass vim_scrollbarWidgetClass;
extern void AllocBotShadowGC (Widget);
extern void AllocTopShadowGC (Widget);
extern void Resize (Widget);
extern void Destroy (Widget);
extern short  nv_cmd_idx [NV_CMDS_SIZE];
extern int nfa_alt_listid;
extern int nfa_listid;
extern int saved_last_idx;
extern int last_idx;
extern UINT s_menu_id;
extern LPCSTR mshape_idcs [];
extern int did_lcd;
extern int did_create_conin;
extern int last_win_id;
extern long  last_timer_id;
extern int next_ch_id;
extern int did_log_msg;
extern int did_add_space;
extern int did_set_icon;
extern int did_set_title;
extern int verbose_did_open;
extern EXTERN int modified_was_set;
extern int globalsignmapused;
extern char **globalsignmap;
extern EXTERN pos_T where_paste_started;
extern VTermStateCallbacks state_cbs;
extern int want_state_erase;
extern int want_state_putglyph;
extern VTermPos state_pos;
extern VTermState *state;
extern int blink_state;
extern long  compress_start;
extern VTermStateCallbacks state_cbs;
extern void *ruby_stack_start;
extern efm_T *fmt_start;
extern int restart_VIsual_select;
extern nfa_state_T *state_ptr;
extern int istate;
extern int nstate;
extern int *post_start;
extern int nfa_nsubexpr;
extern int nfa_has_backref;
extern int blink_state;
extern proftime_T log_start;
extern int did_restart_edit;
extern int update_Insstart_orig;
extern pos_T compl_startpos;
extern int compl_started;
extern lpos_T reg_startzpos [NSUBEXP];
extern char_u *reg_startzp [NSUBEXP];
extern int prev_at_start;
extern int at_start;
extern int nfa_re_flags;
extern int regexp_engine;
extern regengine_T nfa_regengine;
extern regengine_T bt_regengine;
extern regengine_T nfa_regengine;
extern regengine_T bt_regengine;
extern unsigned  regflags;
extern const int command_count;
extern EXTERN char_u e_zerocount [];
extern EXTERN char_u e_nomatch2 [];
extern EXTERN char_u e_nomatch [];
extern EXTERN char_u *autocmd_match;
extern EXTERN reg_extmatch_T *re_extmatch_out;
extern EXTERN reg_extmatch_T *re_extmatch_in;
extern int page_count;
extern long  u_oldcount;
extern long  u_newcount;
extern int nfa_time_count;
extern int nfa_match;
extern pumitem_T *compl_match_array;
extern int compl_matches;
extern int compl_used_match;
extern compl_T *compl_old_match;
extern compl_T *compl_shown_match;
extern compl_T *compl_curr_match;
extern compl_T *compl_first_match;
extern long  temp_count;
extern long_u total_mem_used;
extern int breakcheck_count;
extern int can_f_submatch;
extern int brace_count [10];
extern char_u e_unmatchedpar [];
extern char_u e_unmatchedp [];
extern char_u e_unmatchedpp [];
extern EXTERN unsigned  swb_flags;
extern EXTERN char_u e_bufloaded [];
extern EXTERN char_u e_nobufnr [];
extern EXTERN char_u e_emptybuf [];
extern EXTERN char_u msg_buf [MSG_BUF_LEN];
extern EXTERN buf_T *curbuf;
extern EXTERN buf_T *lastbuf;
extern EXTERN buf_T *firstbuf;
extern int prt_bufsiz;
extern bufref_T qf_last_bufref;
extern char_u old_showcmd_buf [SHOWCMD_BUFLEN];
extern char_u showcmd_buf [SHOWCMD_BUFLEN];
extern hashtab_T buf_hashtab;
extern int buf_free_count;
extern char_u *arshape_buf;
extern int buf_list_used;
extern nbbuf_T *buf_list;
extern buffheader_T readbuf2;
extern buffheader_T readbuf1;
extern char_u noremapbuf_init [TYPELEN_INIT];
extern char_u *sortbuf2;
extern char_u *sortbuf1;
extern char *e_auchangedbuf;
extern char_u out_buf [OUT_SIZE + 1];
extern char_u transchar_buf [7];
extern EXTERN char_u e_invalidreg [];
extern int mr_pattern_alloced;
extern char_u *mr_pattern;
extern int maphash_valid;
extern char_u *compl_pattern;
extern linenr_T invalid_bot;
extern char installdir [BUFSIZE];
extern PyObject *py_fchdir;
extern PyObject *py_chdir;
extern EXTERN char_u *p_vdir;
extern EXTERN char_u *p_udir;
extern EXTERN long  p_linespace;
extern EXTERN char_u *p_dir;
extern EXTERN char_u *p_bdir;
extern EXTERN char_u e_dirnotf [];
extern EXTERN char_u e_prev_dir [];
extern EXTERN char_u e_isadir2 [];
extern EXTERN char_u e_endfor [];
extern EXTERN char_u e_endwhile [];
extern EXTERN char_u e_endtry [];
extern EXTERN char_u e_endif [];
extern EXTERN char_u e_curdir [];
extern EXTERN linenr_T sub_nlines;
extern EXTERN char_u no_lines_msg [];
extern EXTERN char_u *globaldir;
extern EXTERN FILE *redir_fd;
extern EXTERN char_u *repeat_cmdline;
extern EXTERN char_u *last_cmdline;
extern EXTERN char_u *vim_tempdir;
extern EXTERN win_T *au_pending_free_win;
extern EXTERN buf_T *au_pending_free_buf;
extern EXTERN linenr_T search_match_lines;
extern int prt_do_underline;
extern int prt_underline;
extern int prt_need_underline;
extern int curr_underline;
extern XrmOptionDescRec cmdline_options [];
extern char_u *start_dir;
extern linenr_T resel_VIsual_line_count;
extern save_se_T *nfa_endp;
extern int *post_end;
extern int nfa_has_zend;
extern char_u *expr_line;
extern int y_append;
extern garray_T redir_execute_ga;
extern int lastcdir;
extern int prev_ccline_used;
extern struct cmdline_info prev_ccline;
extern struct cmdline_info ccline;
extern int global_need_beginline;
extern int append_indent;
extern int mouse_scroll_lines;
extern UINT s_kFlags_pending;
extern int s_y_pending;
extern int s_x_pending;
extern int s_button_pending;
extern char_u *prev_dir;
extern int compl_pending;
extern int compl_shows_dir;
extern int compl_direction;
extern char e_hitend [];
extern int dont_check_job_ended;
extern char_u *redir_endp;
extern garray_T redir_ga;
extern lval_T *redir_lval;
extern char_u *foldendmarker;
extern char_u *homedir;
extern lpos_T reg_endzpos [NSUBEXP];
extern char_u *reg_endzp [NSUBEXP];
extern char_u *regline;
extern char_u had_endbrace [NSUBEXP];
extern EXTERN except_T *caught_stack;
extern EXTERN except_T *current_exception;
extern EXTERN int did_emsg_syntax;
extern EXTERN int did_emsg;
extern event_T last_event;
extern EXTERN int p_altkeymap;
extern EXTERN char need_key_msg [];
extern EXTERN char_u e_dictkey [];
extern EXTERN char_u e_emptykey [];
extern PtCallbackF_t gui_ph_handle_keyboard;
extern keyQ_T keyHead;
extern int dead_key;
extern EventHandlerUPP keyEventHandlerUPP;
extern char_u modifier_keys_table [];
extern linenr_T debug_breakpoint_lnum;
extern int last_sourcing_lnum;
extern int prev_lnum_lvl;
extern linenr_T prev_lnum;
extern linenr_T longest_lnum;
extern linenr_T reglnum;
extern BufMapObject TheBufferMap;
extern char *BufferAttrs [];
extern EXTERN char_u *p_ffs;
extern EXTERN char_u *NameBuff;
extern EXTERN char_u *IObuff;
extern EXTERN unsigned  *LineOffset;
extern garray_T prt_ps_buffer;
extern char_u prt_line_buffer [257];
extern long_u blink_offtime;
extern char *e_affrange;
extern char *e_affform;
extern char *e_afftrailing;
extern VALUE eDeletedBufferError;
extern VALUE cBuffer;
extern long_u blink_offtime;
extern PhPoint_t gui_ph_raw_offset;
extern int expand_buffer;
extern buffheader_T recordbuff;
extern buffheader_T old_redobuff;
extern buffheader_T redobuff;
extern long_u blink_offtime;
extern int diff_a_works;
extern int diff_flags;
extern int diff_busy;
extern int cursor_is_off;
extern int ta_off;
extern char_u *ff_file_to_find;
extern char_u *ff_expand_buffer;
extern EXTERN char bot_top_msg [];
extern EXTERN char top_bot_msg [];
extern EXTERN char_u e_maxmempat [];
extern EXTERN char_u e_winwidth [];
extern EXTERN char_u e_winheight [];
extern EXTERN char_u e_notopen [];
extern EXTERN int stop_insert_mode;
extern EXTERN frame_T *topframe;
extern EXTERN long_u scrollbar_value;
extern float prt_number_width;
extern float prt_first_line_height;
extern float prt_line_height;
extern float prt_top_margin;
extern float prt_page_height;
extern float prt_page_width;
extern char_u *topmsg;
extern int current_font_height;
extern PtCallbackF_t gui_ph_handle_menu_resize;
extern int puller_width;
extern int nv_max_linear;
extern char *e_noident;
extern int top_file_num;
extern int cube_value [];
extern int buf_list_size;
extern WORD s_dlgfntwidth;
extern WORD s_dlgfntheight;
extern int suppress_winsize;
extern int compl_match_arraysize;
extern volatile int do_resize;
extern AutoPat *last_autopat [NUM_EVENTS];
extern AutoPat *first_autopat [NUM_EVENTS];
extern int size_set;
extern linenr_T invalid_top;
extern int balloon_arraysize;
extern int pum_extra_width;
extern int pum_kind_width;
extern int pum_base_width;
extern int pum_width;
extern int pum_height;
extern int pum_size;
extern long  bl_maxval;
extern long  brace_max [10];
extern long  regsize;
extern char * (icon_link_names [ICON_COUNT]);
extern char * (icon_names [ICON_COUNT]);
extern int code_hdr_len;
extern const char *code_hdr;
extern EXTERN long  p_titlelen;
extern EXTERN char_u e_longname [];
extern EXTERN char_u e_noname [];
extern EXTERN int searchcmdlen;
extern EXTERN char_u *sourcing_name;
extern char_u *prt_ps_file_name;
extern char_u *tagmatchname;
extern char *mt_names [MT_COUNT / 2];
extern char *pname;
extern int vi_jumplist_len;
extern xfmark_T *vi_namedfm;
extern xfmark_T namedfm [NMARKS + EXTRA_MARKS];
extern char_u *altname_buf_ptr;
extern int nfa_classcodes [];
extern int globalsignmaplen;
extern int last_recorded_len;
extern const char *toolbar_names [];
extern char_u *debug_skipped_name;
extern char_u *debug_breakpoint_name;
extern char *part_names [];
extern long  replace_stack_len;
extern int spell_bad_len;
extern int varnamebuflen;
extern char_u *varnamebuf;
extern char_u *redir_varname;
extern char_u *last_sourcing_name;
extern int msg_hist_len;
extern int id1_codes [];
extern int foldendmarkerlen;
extern int foldstartmarkerlen;
extern int tc_len;
extern int tc_max_len;
extern int check_for_codes;
extern int ta_len;
extern unsigned  reg_tofreelen;
extern int classcodes [];
extern char_u *regcode;
extern int prevchr_len;
extern char_u *username;
extern EXTERN pos_T Insstart_orig;
extern EXTERN pos_T Insstart;
extern EXTERN pos_T VIsual;
extern int allow_scrollbar;
extern int show_shell_mess;
extern int allow_scrollbar;
extern EXTERN int p_cc_cols [256];
extern EXTERN long  p_columnspace;
extern EXTERN int fuoptions_bgcolor;
extern EXTERN int arrow_used;
extern EXTERN int sc_col;
extern EXTERN int ru_col;
extern EXTERN int mouse_col;
extern EXTERN int mouse_row;
extern EXTERN colnr_T search_match_endcol;
extern EXTERN int msg_row;
extern EXTERN int msg_col;
extern EXTERN int cmdline_row;
extern int prt_collate;
extern int prt_new_bgcol;
extern int prt_bgcol;
extern int prt_do_bgcol;
extern int prt_need_bgcol;
extern int prt_fgcol;
extern int prt_need_fgcol;
extern float prt_bgcol_offset;
extern float prt_char_width;
extern const VTermColor ansi_colors [];
extern guicolor_T prev_sp_color;
extern guicolor_T prev_bg_color;
extern guicolor_T prev_fg_color;
extern PgColor_t gui_ph_mouse_color;
extern colnr_T resel_VIsual_vcol;
extern char_u *desired_cursor_color;
extern char_u *last_set_cursor_color;
extern char *ExtEdProtocolVersion;
extern int old_mouse_col;
extern int old_mouse_row;
extern int screen_cur_col;
extern int screen_cur_row;
extern int pc_col;
extern int pc_row;
extern int revins_scol;
extern colnr_T Insstart_blank_vcol;
extern colnr_T Insstart_textlen;
extern colnr_T compl_col;
extern int compl_restarting;
extern int balloon_mouse_col;
extern int balloon_mouse_row;
extern int pum_col;
extern int pum_row;
extern int prev_which_scrollbars [3];
extern ControlHandle dragged_sb;
extern int rex_in_use;
extern EXTERN int p_bevalterm;
extern EXTERN char_u e_invargval [];
extern EXTERN int autocmd_fname_full;
extern EXTERN char_u *autocmd_fname;
extern int want_settermprop;
extern const long_u cterm_color_16 [16];
extern const long_u cterm_color_8 [8];
extern garray_T tag_fnames;
extern char_u *nofile_fname;
extern char **gui_argv;
extern int gui_argc;
extern char *e_affname;
extern char_u *qf_last_bufname;
extern int term_default_cterm_bg;
extern int term_default_cterm_fg;
extern int term_backspace_char;
extern term_T *in_terminal_loop;
extern term_T *first_term;
extern char_u *profile_fname;
extern char_u *old_termresponse;
extern struct termcode *termcodes;
extern int is_not_xterm;
extern char_u termleader [256 + 1];
extern char_u * (term_strings [(int) KS_LAST + 1]);
extern EXTERN typebuf_T typebuf;
extern char *prt_resource_types [];
extern int curPCtype;
extern typebuf_T saved_typebuf [NSCRIPT];
extern char_u typebuf_init [TYPELEN_INIT];
extern int typeahead_char;
extern int next_sign_typenr;
extern int filetype_indent;
extern int filetype_plugin;
extern int filetype_detect;
extern EXTERN vimmenu_T *root_menu;
extern EXTERN long  Rows;
extern EXTERN char_u *p_guifont;
extern EXTERN char *font_argument;
extern EXTERN int msg_scrolled;
extern EventHandlerUPP mouseWheelHandlerUPP;
extern SInt32 gMacSystemVersion;
extern EXTERN int p_secure;
extern EXTERN int p_exrc;
extern EXTERN char_u *use_gvimrc;
extern int detected_8bit;
extern gui_T gui;
extern EXTERN time_T starttime;
extern EXTERN FILE *time_fd;
extern mparm_T params;
extern char *mediumVersion;
extern EXTERN int p_im;
extern char * (extra_patches []);
extern int included_patches [];
extern EXTERN int KeyTyped;
extern EXTERN char_u *p_hf;
extern Widget vimShell;
typedef struct {
    char_u *from;
    char_u *to;
} kmap_T;
extern EXTERN int p_dg;
extern EXTERN char_u e_modifiable [];
extern EXTERN char_u e_guarded [];
extern EXTERN long  p_ul;
extern EXTERN char_u e_readerrf [];
extern EXTERN char_u *p_efm;
extern EXTERN char_u *p_gp;
typedef UINT32_TYPEDEF UINT32_T;
extern EXTERN char_u *p_kp;
extern EXTERN char_u *p_ww;
extern EXTERN long  p_bdlay;
extern EXTERN int p_fkmap;
extern EXTERN int p_hkmap;
extern EXTERN int KeyStuffed;
extern EXTERN char_u *p_fp;
extern EXTERN int VIsual_reselect;
struct vimoption;
typedef enum {PV_NONE = 0, PV_MAXVAL = 0xffff} idopt_T;
extern EXTERN long  p_wd;
extern EXTERN int p_wb;
extern EXTERN int p_wa;
extern EXTERN char_u *p_wig;
extern EXTERN int p_vb;
extern EXTERN long  p_ur;
extern EXTERN int p_ari;
extern EXTERN long  p_pvh;
extern EXTERN int p_remap;
extern EXTERN char_u *p_pex;
extern EXTERN char_u *p_para;
extern EXTERN int p_more;
extern EXTERN int p_mh;
extern EXTERN long  p_mmp;
extern EXTERN long  p_mm;
extern EXTERN long  p_mmd;
extern EXTERN long  p_mfd;
extern EXTERN char_u *p_mp;
extern EXTERN char_u *p_mef;
extern EXTERN int p_lpl;
extern EXTERN int p_lz;
extern EXTERN char_u *p_lm;
extern EXTERN int p_hkmapp;
extern EXTERN char_u *p_pdev;
extern EXTERN int p_gd;
extern EXTERN int p_ek;
extern EXTERN char_u *p_gefm;
extern EXTERN char_u *p_ef;
extern EXTERN int p_eb;
extern EXTERN int p_ed;
extern EXTERN char_u *p_dex;
extern EXTERN char_u *p_def;
extern EXTERN long  p_pw;
extern EXTERN long  p_ph;
extern EXTERN int p_bk;
extern EXTERN int p_awa;
extern EXTERN int p_aw;
extern EXTERN int p_ar;
extern EXTERN long  p_aleph;
extern int p_ro;
extern int p_mod;
extern int p_eol;
extern int p_bl;
extern EXTERN char_u *p_ep;
extern EXTERN char_u *p_pp;
extern EXTERN long  p_re;
extern EXTERN long  p_wiw;
extern EXTERN long  p_wmw;
extern EXTERN long  p_wmh;
extern EXTERN long  p_wh;
extern EXTERN long  p_blur;
extern EXTERN long  p_hh;
extern EXTERN int p_ri;
extern EXTERN int p_wiv;
extern EXTERN int p_ea;
extern EXTERN char_u *p_wim;
extern EXTERN char_u *p_wop;
extern EXTERN char_u *p_ve;
extern EXTERN char_u *p_vop;
extern EXTERN char_u *p_ruf;
extern EXTERN char_u *p_pm;
extern EXTERN char_u *p_km;
extern EXTERN char_u *p_go;
extern EXTERN char_u *p_fdo;
extern EXTERN char_u *p_ei;
extern EXTERN char_u *p_ead;
extern EXTERN char_u *p_dy;
extern EXTERN char_u *p_dip;
extern EXTERN char_u *p_debug;
extern EXTERN char_u *p_bo;
extern EXTERN char_u *p_bex;
extern EXTERN char_u *p_bg;
extern char_u *p_syn;
extern char_u *p_ft;
extern char_u *p_bt;
extern char_u *p_bh;
extern EXTERN int p_ru;
extern int p_ma;
extern long  p_ts;
extern char_u *p_isk;
extern char_u *p_ff;
extern int p_tx;
extern int p_udf;
extern char_u *p_qe;
extern char_u *p_inex;
extern long  p_iminsert;
extern int p_mmta;
extern char_u *p_keymap;
extern char_u *p_sua;
extern char_u *p_key;
extern char_u *p_fex;
extern char_u *p_indk;
extern char_u *p_inde;
extern char_u *p_spl;
extern char_u *p_spf;
extern int p_lisp;
extern int p_pi;
extern int p_si;
extern char_u *p_mps;
extern char_u *p_nf;
extern char_u *p_flp;
extern char_u *p_fo;
extern int p_sn;
extern long  p_sts_nopaste;
extern long  p_sts;
extern int p_swf;
extern int p_inf;
extern int p_ml_nobin;
extern int p_ml;
extern int p_et_nopaste;
extern int p_et_nobin;
extern int p_et;
extern int p_fixeol;
extern int p_bin;
extern long  p_wm_nobin;
extern long  p_wm_nopaste;
extern long  p_wm;
extern long  p_tw_nobin;
extern long  p_tw_nopaste;
extern long  p_tw;
extern long  p_sw;
extern int p_ai_nopaste;
extern int p_ai;
extern char_u expand_option_name [5];
extern int expand_option_flags;
extern char_u *p_spc;
extern long  p_smc;
extern long  p_imsearch;
extern char_u *p_cpt;
extern char_u *p_cms;
extern char_u *p_com;
extern char_u *p_cinw;
extern char_u *p_cino;
extern char_u *p_cink;
extern int p_cin;
extern int p_ci;
extern int expand_option_idx;
extern char * (p_scl_values []);
extern char * (p_cot_values []);
extern char * (p_fcl_values []);
extern char * (p_fdm_values []);
extern char * (p_bs_values []);
extern char * (p_bufhidden_values []);
extern char * (p_buftype_values []);
extern char * (p_ead_values []);
extern char * (p_debug_values []);
extern char * (p_scbopt_values []);
extern char * (p_km_values []);
extern char * (p_slm_values []);
extern char * (p_sel_values []);
extern char * (p_mousem_values []);
extern char * (p_wop_values []);
extern char * (p_cm_values []);
extern char * (p_ff_values []);
extern char * (p_nf_values []);
extern char * (p_bg_values []);
enum {VTERM_PROP_CURSORSHAPE_BLOCK = 1, VTERM_PROP_CURSORSHAPE_UNDERLINE, VTERM_PROP_CURSORSHAPE_BAR_LEFT};
typedef struct {
    int (*damage) (VTermRect rect, void *user);
    int (*moverect) (VTermRect dest, VTermRect src, void *user);
    int (*movecursor) (VTermPos pos, VTermPos oldpos, int visible, void *user);
    int (*settermprop) (VTermProp prop, VTermValue *val, void *user);
    int (*bell) (void *user);
    int (*resize) (int rows, int cols, void *user);
    int (*sb_pushline) (int cols, const VTermScreenCell *cells, void *user);
    int (*sb_popline) (int cols, VTermScreenCell *cells, void *user);
} VTermScreenCallbacks;
typedef struct {

    #define VTERM_MAX_CHARS_PER_CELL 6
    uint32_t chars [VTERM_MAX_CHARS_PER_CELL];
    char width;
    VTermScreenCellAttrs attrs;
    VTermColor fg, bg;
} VTermScreenCell;
typedef struct {
    unsigned  int bold : 1;
    unsigned  int underline : 2;
    unsigned  int italic : 1;
    unsigned  int blink : 1;
    unsigned  int reverse : 1;
    unsigned  int strike : 1;
    unsigned  int font : 4;
    unsigned  int dwl : 1;
    unsigned  int dhl : 2;
} VTermScreenCellAttrs;
typedef struct {
    int (*putglyph) (VTermGlyphInfo *info, VTermPos pos, void *user);
    int (*movecursor) (VTermPos pos, VTermPos oldpos, int visible, void *user);
    int (*scrollrect) (VTermRect rect, int downward, int rightward, void *user);
    int (*moverect) (VTermRect dest, VTermRect src, void *user);
    int (*erase) (VTermRect rect, int selective, void *user);
    int (*initpen) (void *user);
    int (*setpenattr) (VTermAttr attr, VTermValue *val, void *user);
    int (*settermprop) (VTermProp prop, VTermValue *val, void *user);
    int (*bell) (void *user);
    int (*resize) (int rows, int cols, VTermPos *delta, void *user);
    int (*setlineinfo) (int row, const VTermLineInfo *newinfo, const VTermLineInfo *oldinfo, void *user);
} VTermStateCallbacks;
typedef struct {
    int (*text) (const char *bytes, size_t len, void *user);
    int (*control) (unsigned  char control, void *user);
    int (*escape) (const char *bytes, size_t len, void *user);
    int (*csi) (const char *leader, const long  args [], int argcount, const char *intermed, char command, void *user);
    int (*osc) (const char *command, size_t cmdlen, void *user);
    int (*dcs) (const char *command, size_t cmdlen, void *user);
    int (*resize) (int rows, int cols, void *user);
} VTermParserCallbacks;
typedef struct {
    void * (*malloc) (size_t size, void *allocdata);
    void (*free) (void *ptr, void *allocdata);
} VTermAllocatorFunctions;
typedef struct {
    unsigned  int doublewidth : 1;
    unsigned  int doubleheight : 2;
} VTermLineInfo;
typedef struct {
    const uint32_t *chars;
    int width;
    unsigned  int protected_cell : 1;
    unsigned  int dwl : 1;
    unsigned  int dhl : 2;
} VTermGlyphInfo;
typedef union {
    int boolean;
    int number;
    char *string;
    VTermColor color;
} VTermValue;
typedef struct {
    uint8_t red, green, blue;
    uint8_t ansi_index;
} VTermColor;
typedef struct {
    int start_row;
    int end_row;
    int start_col;
    int end_col;
} VTermRect;
typedef struct {
    int row;
    int col;
} VTermPos;
typedef unsigned  int uint32_t;
typedef unsigned  char uint8_t;
typedef enum {VTERM_KEY_NONE, VTERM_KEY_ENTER, VTERM_KEY_TAB, VTERM_KEY_BACKSPACE, VTERM_KEY_ESCAPE, VTERM_KEY_UP, VTERM_KEY_DOWN, VTERM_KEY_LEFT, VTERM_KEY_RIGHT, VTERM_KEY_INS, VTERM_KEY_DEL, VTERM_KEY_HOME, VTERM_KEY_END, VTERM_KEY_PAGEUP, VTERM_KEY_PAGEDOWN, VTERM_KEY_FUNCTION_0 = 256, VTERM_KEY_FUNCTION_MAX = VTERM_KEY_FUNCTION_0 + 255, VTERM_KEY_KP_0, VTERM_KEY_KP_1, VTERM_KEY_KP_2, VTERM_KEY_KP_3, VTERM_KEY_KP_4, VTERM_KEY_KP_5, VTERM_KEY_KP_6, VTERM_KEY_KP_7, VTERM_KEY_KP_8, VTERM_KEY_KP_9, VTERM_KEY_KP_MULT, VTERM_KEY_KP_PLUS, VTERM_KEY_KP_COMMA, VTERM_KEY_KP_MINUS, VTERM_KEY_KP_PERIOD, VTERM_KEY_KP_DIVIDE, VTERM_KEY_KP_ENTER, VTERM_KEY_KP_EQUAL, VTERM_KEY_MAX} VTermKey;
typedef enum {VTERM_MOD_NONE = 0x00, VTERM_MOD_SHIFT = 0x01, VTERM_MOD_ALT = 0x02, VTERM_MOD_CTRL = 0x04} VTermModifier;
typedef enum {VTERM_ATTR_BOLD_MASK = 1 << 0, VTERM_ATTR_UNDERLINE_MASK = 1 << 1, VTERM_ATTR_ITALIC_MASK = 1 << 2, VTERM_ATTR_BLINK_MASK = 1 << 3, VTERM_ATTR_REVERSE_MASK = 1 << 4, VTERM_ATTR_STRIKE_MASK = 1 << 5, VTERM_ATTR_FONT_MASK = 1 << 6, VTERM_ATTR_FOREGROUND_MASK = 1 << 7, VTERM_ATTR_BACKGROUND_MASK = 1 << 8} VTermAttrMask;
typedef enum {VTERM_DAMAGE_CELL, VTERM_DAMAGE_ROW, VTERM_DAMAGE_SCREEN, VTERM_DAMAGE_SCROLL} VTermDamageSize;
typedef enum {VTERM_PROP_CURSORVISIBLE = 1, VTERM_PROP_CURSORBLINK, VTERM_PROP_ALTSCREEN, VTERM_PROP_TITLE, VTERM_PROP_ICONNAME, VTERM_PROP_REVERSE, VTERM_PROP_CURSORSHAPE, VTERM_PROP_MOUSE, VTERM_PROP_CURSORCOLOR} VTermProp;
typedef enum {VTERM_ATTR_BOLD = 1, VTERM_ATTR_UNDERLINE, VTERM_ATTR_ITALIC, VTERM_ATTR_BLINK, VTERM_ATTR_REVERSE, VTERM_ATTR_STRIKE, VTERM_ATTR_FONT, VTERM_ATTR_FOREGROUND, VTERM_ATTR_BACKGROUND} VTermAttr;
typedef enum {VTERM_VALUETYPE_BOOL = 1, VTERM_VALUETYPE_INT, VTERM_VALUETYPE_STRING, VTERM_VALUETYPE_COLOR} VTermValueType;
typedef struct VTermScreen VTermScreen;
typedef struct VTermState VTermState;
typedef struct VTerm VTerm;
extern int grey_ramp [];
extern int KeyNoremap;
extern char PC;
enum {EXP_SUBCMD, EXP_CASE, EXP_SPELL, EXP_SYNC} expand_what;
typedef struct {
    int flags;
    int keyword;
    int *sync_idx;
    char has_cont_list;
    short  *cont_list;
    short  *cont_in_list;
    short  *next_list;
} syn_opt_arg_T;
struct subcommand;
struct name_list;
struct syn_cluster_S;
struct hl_group;
struct state_item;
struct syn_pattern;
typedef struct syn_pattern synpat_T;
typedef struct syn_cluster_S syn_cluster_T;
typedef struct state_item stateitem_T;
extern int syn_time_on;
extern win_T *syn_win;
extern int keepend_level;
extern char msg_no_items [];
extern synblock_T *syn_block;
extern int running_syn_inc_tag;
extern char_u **syn_cmdlinep;
extern int include_link;
extern int include_default;
extern int include_none;
extern char * (spo_name_tab [SPO_COUNT]);
extern int current_finished;
extern int current_syn_inc_tag;
extern int current_sub_char;
extern int current_seqnr;
extern int current_flags;
extern garray_T gui_attr_table;
extern garray_T cterm_attr_table;
extern garray_T term_attr_table;
extern proftime_T *syn_tm;
extern buf_T *syn_buf;
extern int current_attr;
extern char * (highlight_init_dark []);
extern char * (highlight_init_light []);
extern char * (highlight_init_both []);
extern int current_next_flags;
extern short  *current_next_list;
extern int next_seqnr;
extern int hl_attr_table [];
extern char * (hl_name_table []);
extern garray_T highlight_ga;
extern int current_line_id;
extern int current_trans_id;
extern int current_id;
extern garray_T current_state;
extern int current_state_stored;
extern int last_matchgroup;
extern reg_extmatch_T *next_match_extmatch;
extern int next_match_end_idx;
extern lpos_T next_match_eoe_pos;
extern lpos_T next_match_eos_pos;
extern long  next_match_flags;
extern int next_match_idx;
extern lpos_T next_match_h_endpos;
extern lpos_T next_match_h_startpos;
extern lpos_T next_match_m_endpos;
extern int color_numbers_8 [28];
extern int color_numbers_256 [28];
extern int color_numbers_88 [28];
extern int color_numbers_16 [28];
extern char * (color_names [28]);
extern colnr_T current_col;
extern linenr_T current_lnum;
extern int next_match_col;
typedef struct {
    char_u *vir_line;
    FILE *vir_fd;
    int vir_version;
    garray_T vir_barlines;
} vir_T;
extern char wild [3];
extern int debug_greedy;
extern garray_T prof_ga;
extern garray_T dbg_breakp;
extern FILE *log_fd;
extern garray_T ga_loaded;
typedef struct nr_trans NR_TRANS;
typedef struct block0 ZERO_BL;
typedef struct pointer_block PTR_BL;
typedef struct data_block DATA_BL;
typedef struct {
    linenr_T fd_top;
    linenr_T fd_len;
    garray_T fd_nested;
    char fd_flags;
    char fd_small;
} fold_T;
extern int pum_do_redraw;
extern pumitem_T *pum_array;
extern int had_eol;
extern char_u REGEXP_ABBR [];
extern char_u REGEXP_INRANGE [];
extern EXTERN char_u e_re_damg [];
extern regexec_T rex;
int spell_check (win_T * wp, char_u * ptr, hlf_T * attrp, int * capcol, int docount);
void *vim_memset (void *ptr, int c, size_t size);
char_u *skipbin (char_u *q);
int vim_isbdigit (int c);
char_u *skiphex (char_u *q);
int vim_isxdigit (int c);
char_u *skipdigits (char_u *q);
static int spell_iswordp (char_u * p, win_T * wp);
char_u *vim_strchr (char_u *string, int c);
int vim_iswordc_buf (int c, buf_T * buf);
int spell_casefold (char_u * str, int len, char_u * buf, int buflen);
static void find_word (matchinf_T * mip, int mode);
static int fold_more (matchinf_T * mip);
int captype (char_u * word, char_u * end);
int spell_iswordp_nmw (char_u * p, win_T * wp);
static int spell_valid_case (int wordflags, int treeflags);
static int valid_word_prefix (int totprefcnt, int arridx, int flags, char_u * word, slang_T * slang, int cond_req);
int vim_regexec_prog (regprog_T * * prog, int ignore_case, char_u * line, colnr_T col);
static int regmatch (char_u * scan, proftime_T * tm, int * timed_out);
void fast_breakcheck (void);
void ui_breakcheck (void);
void ui_breakcheck_force (int force);
void gui_mch_update (void);
int gui_mch_wait_for_chars (int wtime);
pascal Boolean WaitNextEventWrp (EventMask eventMask, EventRecord * theEvent, UInt32 sleep, RgnHandle mouseRgn);
void gui_mac_handle_event (EventRecord * event);
void gui_mac_handle_menu (long menuChoice);
void gui_mch_beep (void);
static vimmenu_T *gui_mac_get_vim_menu (short  menuID, short  itemIndex, vimmenu_T *pMenu);
void gui_menu_cb (vimmenu_T * menu);
void add_long_to_buf (long_u val, char_u * dst);
void gui_mac_doMouseDownEvent (EventRecord * theEvent);
void gui_mac_doInContentClick (EventRecord * theEvent, WindowPtr whichWindow);
pascal void gui_mac_drag_thumb (ControlHandle theControl, short partCode);
scrollbar_T *gui_find_scrollbar (long  ident);
void gui_drag_scrollbar (scrollbar_T * sb, long value, int still_dragging);
int pum_visible (void);
int gui_do_scroll (void);
void scrolldown (long line_count, int byfold);
int hasFolding (linenr_T lnum, linenr_T * firstp, linenr_T * lastp);
int hasFoldingWin (win_T * win, linenr_T lnum, linenr_T * firstp, linenr_T * lastp, int cache, foldinfo_T * infop);
static void checkupdate (win_T * wp);
void foldUpdate (win_T * wp, linenr_T top, linenr_T bot);
static int foldFind (garray_T * gap, linenr_T lnum, fold_T * * fpp);
int foldmethodIsIndent (win_T * wp);
int foldmethodIsExpr (win_T * wp);
int foldmethodIsMarker (win_T * wp);
int foldmethodIsDiff (win_T * wp);
int foldmethodIsSyntax (win_T * wp);
static void foldUpdateIEMS (win_T * wp, linenr_T top, linenr_T bot);
static void setSmallMaybe (garray_T * gap);
static void foldlevelMarker (fline_T * flp);
char_u *ml_get_buf (buf_T *buf, linenr_T lnum, int will_change);
static void ml_flush_line (buf_T * buf);
static bhdr_T *ml_find_line (buf_T *buf, linenr_T lnum, int action);
void mf_put (memfile_T * mfp, bhdr_T * hp, int dirty, int infile);
static int mf_trans_add (memfile_T * mfp, bhdr_T * hp);
char_u *alloc (unsigned  size);
char_u *lalloc (long_u size, int message);
long_u mch_avail_mem (int special);
void clear_sb_text (int all);
void vim_free (void * x);
int mf_release_all (void);
void ml_open_file (buf_T * buf);
char_u *vim_tempname (int extra_char, int keep);
void expand_env (char_u * src, char_u * dst, int dstlen);
void expand_env_esc (char_u * srcp, char_u * dst, int dstlen, int esc, int one, char_u * startstr);
static int copy_char (char_u * from, char_u * to, int lowercase);
char_u *skipwhite (char_u *q);
int skip_expr (char_u * * pp);
int eval1 (char_u * * arg, typval_T * rettv, int evaluate);
static int eval2 (char_u * * arg, typval_T * rettv, int evaluate);
static int eval3 (char_u * * arg, typval_T * rettv, int evaluate);
static int eval4 (char_u * * arg, typval_T * rettv, int evaluate);
static int eval5 (char_u * * arg, typval_T * rettv, int evaluate);
static int eval6 (char_u * * arg, typval_T * rettv, int evaluate, int want_string);
static int eval7 (char_u * * arg, typval_T * rettv, int evaluate, int want_string);
int vim_isdigit (int c);
int string2float (char_u * text, float_T * value);
void vim_str2nr (char_u * start, int * prep, int * len, int what, varnumber_T * nptr, uvarnumber_T * unptr, int maxlen);
int hex2nr (int c);
static int get_string_tv (char_u * * arg, typval_T * rettv, int evaluate);
int trans_special (char_u * * srcp, char_u * dst, int keycode, int in_string);
int find_special_key (char_u * * srcp, int * modp, int keycode, int keep_x_key, int in_string);
int vim_isIDc (int c);
int name_to_mod_mask (int c);
int get_special_key_code (char_u * name);
int add_termcap_entry (char_u * name, int force);
int gui_mch_haskey (char_u * name);
char_u *find_termcode (char_u *name);
static int term_is_builtin (char_u * name);
static struct builtin_term *find_builtin_term (char_u *term);
int vim_is_iris (char_u * name);
int vim_is_xterm (char_u * name);
void add_termcode (char_u * name, char_u * string, int flags);
void del_termcode (char_u * name);
static void del_termcode_idx (int idx);
char_u *vim_strsave (char_u *string);
static int term_7to8bit (char_u * p);
static int termcode_star (char_u * code, int len);
int term_is_8bit (char_u * name);
int handle_x_keys (int key);
int simplify_key (int key, int * modifiers);
int extract_modifiers (int key, int * modp);
char_u *add_char2buf (int c, char_u *s);
static int get_lit_string_tv (char_u * * arg, typval_T * rettv, int evaluate);
int get_list_tv (char_u * * arg, typval_T * rettv, int evaluate);
list_T *list_alloc (void);
char_u *alloc_clear (unsigned  size);
listitem_T *listitem_alloc (void);
void list_append (list_T * l, listitem_T * item);
void clear_tv (typval_T * varp);
void func_unref (char_u * name);
static int func_name_refcount (char_u * name);
ufunc_T *find_func (char_u *name);
hashitem_T *hash_find (hashtab_T *ht, char_u *key);
hashitem_T *hash_lookup (hashtab_T *ht, char_u *key, hash_T hash);
hash_T hash_hash (char_u * key);
void internal_error (char * where);
static void func_clear_free (ufunc_T * fp, int force);
static void func_clear (ufunc_T * fp, int force);
void ga_clear_strings (garray_T * gap);
void ga_clear (garray_T * gap);
void ga_init (garray_T * gap);
static void funccal_unref (funccall_T * fc, ufunc_T * fp, int force);
static void free_funccal (funccall_T * fc, int free_val);
void vars_clear_ext (hashtab_T * ht, int free_val);
void hash_lock (hashtab_T * ht);
void hash_clear (hashtab_T * ht);
void vars_clear (hashtab_T * ht);
void func_ptr_unref (ufunc_T * fp);
static void func_free (ufunc_T * fp);
static int func_remove (ufunc_T * fp);
void hash_remove (hashtab_T * ht, hashitem_T * hi);
static int hash_may_resize (hashtab_T * ht, int minitems);
void partial_unref (partial_T * pt);
static void partial_free (partial_T * pt);
void dict_unref (dict_T * d);
static void dict_free (dict_T * d);
void dict_free_contents (dict_T * d);
void dictitem_free (dictitem_T * item);
static void dict_free_dict (dict_T * d);
void list_unref (list_T * l);
void list_free (list_T * l);
static void list_free_contents (list_T * l);
static void list_free_list (list_T * l);
void job_unref (job_T * job);
static int job_channel_still_useful (job_T * job);
static int channel_still_useful (channel_T * channel);
static int job_need_end_check (job_T * job);
static void job_free (job_T * job);
static void job_free_contents (job_T * job);
void ch_log (channel_T * ch, const char * fmt,...);
static void ch_log_lead (const char * what, channel_T * ch);
void profile_start (proftime_T * tm);
void profile_sub (proftime_T * tm, proftime_T * tm2);
char *profile_msg (proftime_T *tm);
int channel_unref (channel_T * channel);
static int channel_may_free (channel_T * channel);
static void channel_free (channel_T * channel);
static void channel_free_contents (channel_T * channel);
void channel_close (channel_T * channel, int invoke_close_cb);
static void channel_gui_unregister (channel_T * channel);
static void channel_gui_unregister_one (channel_T * channel, ch_part_T part);
static void ch_close_part (channel_T * channel, ch_part_T part);
static int may_invoke_callback (channel_T * channel, ch_part_T part);
int msg (char_u * s);
int msg_attr_keep (char_u * s, int attr, int keep);
int message_filtered (char_u * msg);
static Boolean match (SharedFontSelData * data, enum ListSpecifier l, int i);
static void encoding_part (char * font, char * buf);
static void get_part (char * in, int pos, char * out);
int vim_snprintf (char * str, size_t str_m, char * fmt,...);
int vim_vsnprintf (char * str, size_t str_m, char * fmt, va_list ap);
int vim_vsnprintf_typval (char * str, size_t str_m, char * fmt, va_list ap, typval_T * tvs);
static varnumber_T tv_nr (typval_T * tvs, int * idxp);
varnumber_T get_tv_number_chk (typval_T * varp, int * denote);
static char *tv_str (typval_T *tvs, int *idxp, char_u **tofree);
char_u *echo_string (typval_T *tv, char_u **tofree, char_u *numbuf, int copyID);
char_u *echo_string_core (typval_T *tv, char_u **tofree, char_u *numbuf, int copyID, int echo_style, int restore_copyID, int composite_val);
char_u *string_quote (char_u *str, int function);
char_u *partial_name (partial_T *pt);
void ga_init2 (garray_T * gap, int itemsize, int growsize);
void ga_concat (garray_T * gap, char_u * s);
int ga_grow (garray_T * gap, int n);
char_u *tv2string (typval_T *tv, char_u **tofree, char_u *numbuf, int copyID);
char_u *list2string (typval_T *tv, int copyID, int restore_copyID);
void ga_append (garray_T * gap, int c);
int list_join (garray_T * gap, list_T * l, char_u * sep, int echo_style, int restore_copyID, int copyID);
static int list_join_inner (garray_T * gap, list_T * l, char_u * sep, int echo_style, int restore_copyID, int copyID, garray_T * join_gap);
char_u *vim_strnsave (char_u *string, int len);
void line_breakcheck (void);
char_u *dict2string (typval_T *tv, int copyID, int restore_copyID);
char_u *get_tv_string_buf (typval_T *varp, char_u *buf);
char_u *get_tv_string_buf_chk (typval_T *varp, char_u *buf);
static char *get_var_special_name (int nr);
char *channel_status (channel_T *channel, int req_part);
int channel_has_readahead (channel_T * channel, ch_part_T part);
readq_T *channel_peek (channel_T *channel, ch_part_T part);
int channel_is_open (channel_T * channel);
int get_copyID (void);
char_u *get_tv_string_chk (typval_T *varp);
static double tv_float (typval_T * tvs, int * idxp);
static const char *infinity_str (int positive, char fmt_spec, int force_sign, int space_for_positive);
static char *fn (SharedFontSelData *data, int i);
static void name_part (char * font, char * buf);
static void style_part (char * font, char * buf);
static void size_part (char * font, char * buf, int inPixels);
int vim_regexec (regmatch_T * rmp, char_u * line, colnr_T col);
static int vim_regexec_string (regmatch_T * rmp, char_u * line, colnr_T col, int nl);
void vim_regfree (regprog_T * prog);
static void report_re_switch (char_u * pat);
void verbose_enter (void);
void verbose_leave (void);
regprog_T *vim_regcomp (char_u *expr_arg, int re_flags);
int smsg (char_u * s,...);
void set_vim_var_string (int idx, char_u * val, int len);
static void add_msg_hist (char_u * s, int len, int attr);
int delete_first_msg (void);
void msg_start (void);
void msg_clr_eos (void);
void msg_clr_eos_force (void);
int msg_use_printf (void);
static int msg_check_screen (void);
int screen_valid (int doclear);
void screenalloc (int doclear);
void win_new_shellsize (void);
void ui_new_shellsize (void);
void gui_new_shellsize (void);
void gui_reset_scroll_region (void);
void mch_new_shellsize (void);
void shell_new_rows (void);
static int frame_minheight (frame_T * topfrp, win_T * next_curwin);
static void frame_new_height (frame_T * topfrp, int height, int topfirst, int wfh);
void win_new_height (win_T * wp, int height);
void validate_cursor (void);
void check_cursor_moved (win_T * wp);
void curs_columns (int may_scroll);
void update_topline (void);
void redraw_later (int type);
void redraw_win_later (win_T * wp, int type);
static int check_top_offset (void);
int hasAnyFolding (win_T * win);
int foldmethodIsManual (win_T * wp);
static void topline_back (lineoff_T * lp);
int diff_check_fill (win_T * wp, linenr_T lnum);
int diff_check (win_T * wp, linenr_T lnum);
void ex_diffupdate (exarg_T * eap);
void diff_clear (tabpage_T * tp);
static int enc_canon_search (char_u * name);
int vim_isprintc (int c);
char_u *mac_string_convert (char_u *ptr, int len, int *lenp, int fail_on_error, int from_enc, int to_enc, int *unconvlenp);
static void diff_file (char_u * tmp_orig, char_u * tmp_new, char_u * tmp_diff);
void eval_diff (char_u * origfile, char_u * newfile, char_u * outfile);
int eval_to_bool (char_u * arg, int * error, char_u * * nextcmd, int skip);
int eval0 (char_u * arg, typval_T * rettv, char_u * * nextcmd, int evaluate);
int ends_excmd (int c);
int aborting (void);
char_u *check_nextcmd (char_u *p);
void vim_setenv (char_u * name, char_u * val);
int mch_setenv (char * var, char * value, int x);
void append_redir (char_u * buf, int buflen, char_u * opt, char_u * fname);
void block_autocmds (void);
char_u *get_vim_var_str (int idx);
char_u *get_tv_string (typval_T *varp);
int call_shell (char_u * cmd, int opt);
void out_char (unsigned c);
void out_flush (void);
void ui_write (char_u * s, int len);
void gui_write (char_u * s, int len);
void transchar_nonprint (char_u * buf, int c);
int get_fileformat (buf_T * buf);
void transchar_hex (char_u * buf, int c);
static unsigned  nr2hex (unsigned c);
char_u *transchar (int c);
int F_ischar (int c);
int vim_isprintc_strict (int c);
long  getdigits (char_u * * pp);
void gui_mch_clear_all (void);
void gui_mch_set_bg_color (guicolor_T color);
void gui_set_cursor (int row, int col);
static void gui_delete_lines (int row, int count);
void gui_clear_block (int row1, int col1, int row2, int col2);
void gui_mch_invert_rectangle (int r, int c, int nr, int nc);
void screen_draw_rectangle (int row, int col, int height, int width, int invert);
static void screen_char (unsigned off, int row, int col);
void screen_stop_highlight (void);
attrentry_T *syn_cterm_attr2entry (int attr);
attrentry_T *syn_term_attr2entry (int attr);
void out_str (char_u * s);
void out_str_nf (char_u * s);
static void out_char_nf (unsigned c);
int tputs (char * cp, int affcnt, void (* outc) (unsigned int));
void term_fg_rgb_color (guicolor_T rgb);
static void term_rgb_color (char_u * s, guicolor_T rgb);
void term_bg_rgb_color (guicolor_T rgb);
void term_fg_color (int n);
static void term_color (char_u * s, int n);
static char *tgoto (char *cm, int x, int y);
void term_bg_color (int n);
void windgoto (int row, int col);
void term_cursor_right (int i);
void term_windgoto (int row, int col);
static void screen_start_highlight (int attr);
void gui_mch_clear_block (int row1, int col1, int row2, int col2);
void gui_mch_delete_lines (int row, int num_lines);
static void gui_insert_lines (int row, int count);
void gui_mch_insert_lines (int row, int num_lines);
void gui_start_highlight (int mask);
void gui_stop_highlight (int mask);
void gui_mch_flash (int msec);
void ui_delay (long msec, int ignoreinput);
int gui_wait_for_chars (long wtime, int tb_change_cnt);
void gui_update_menus (int modes);
static int get_menu_mode (void);
static void gui_update_menus_recurse (vimmenu_T * menu, int mode);
int menu_is_toolbar (char_u * name);
void gui_mch_menu_grey (vimmenu_T * menu, int grey);
short  gui_mac_get_menu_item_index (vimmenu_T * pMenu);
void gui_mch_menu_hidden (vimmenu_T * menu, int hidden);
void gui_mch_draw_menubar (void);
void gui_mch_flush (void);
void gui_mch_start_blink (void);
void gui_update_cursor (int force, int clear_selection);
static void gui_check_pos (void);
void gui_undraw_cursor (void);
int gui_redraw_block (int row1, int col1, int row2, int col2, int flags);
int check_col (int col);
int check_row (int row);
static int gui_screenchar (int off, int flags, guicolor_T fg, guicolor_T bg, int back);
int gui_outstr_nowrap (char_u * s, int len, int flags, guicolor_T fg, guicolor_T bg, int back);
attrentry_T *syn_gui_attr2entry (int attr);
void gui_mch_set_font (GuiFont font);
void gui_mch_set_fg_color (guicolor_T color);
void gui_mch_set_sp_color (guicolor_T color);
void gui_mch_draw_string (int row, int col, char_u * s, int len, int flags);
unsigned  short  *mac_enc_to_utf16 (char_u *from, size_t fromLen, size_t *actualLen);
static UniChar *mac_utf8_to_utf16 (char_u *from, size_t fromLen, size_t *actualLen);
static void draw_undercurl (int flags, int row, int col, int cells);
static void draw_string_QD (int row, int col, char_u * s, int len, int flags);
void netbeans_draw_multisign_indicator (int row);
int netbeans_active (void);
int terminal_is_active ();
cursorentry_T *term_get_cursor_shape (guicolor_T *fg, guicolor_T *bg);
guicolor_T color_name2handle (char_u * name);
void gui_mch_getmouse (int * x, int * y);
int cmdline_at_end (void);
int cmdline_overstrike (void);
void gui_mch_set_blinking (long wait, long on, long off);
void gui_mch_stop_blink (int may_call_gui_update_cursor);
int syn_id2colors (int hl_id, guicolor_T * fgp, guicolor_T * bgp);
int syn_get_final_id (int hl_id);
int syn_name2id (char_u * name);
void vim_strncpy (char_u * to, char_u * from, size_t len);
void vim_strup (char_u * p);
void gui_mch_draw_hollow_cursor (guicolor_T color);
void gui_mch_draw_part_cursor (int w, int h, guicolor_T color);
static int gui_wait_for_chars_or_timer (long wtime);
int ui_wait_for_chars_or_timer (long wtime, int (* wait_func) (long wtime, int * interrupted, int ignore_input), int * interrupted, int ignore_input);
long  check_due_timer (void);
static long  proftime_time_left (proftime_T * due, proftime_T * now);
int get_pressedreturn (void);
static void timer_callback (timer_T * timer);
int call_func (char_u * funcname, int len, typval_T * rettv, int argcount_in, typval_T * argvars_in, int (* argv_func) (int, typval_T *, int), linenr_T firstline, linenr_T lastline, int * doesrange, int evaluate, partial_T * partial, dict_T * selfdict_in);
static char_u *fname_trans_sid (char_u *name, char_u *fname_buf, char_u **tofree, int *error);
int eval_fname_script (char_u * p);
static int eval_fname_sid (char_u * p);
void copy_tv (typval_T * from, typval_T * to);
void func_ref (char_u * name);
static int builtin_function (char_u * name, int len);
int apply_autocmds (event_T event, char_u * fname, char_u * fname_io, int force, buf_T * buf);
static int apply_autocmds_group (event_T event, char_u * fname, char_u * fname_io, int force, int group, buf_T * buf, exarg_T * eap);
static int event_ignored (event_T event);
static event_T event_name2nr (char_u * start, char_u * * end);
char_u *FullName_save (char_u *fname, int force);
int vim_FullName (char_u * fname, char_u * buf, int len, int force);
int path_with_url (char_u * fname);
static int path_is_url (char_u * p);
int mch_FullName (char_u * fname, char_u * buf, int len, int force);
static int lock2name (BPTR lock, char_u * buf, long len);
int mch_isFullName (char_u * fname);
void prof_child_enter (proftime_T * tm);
void script_prof_save (proftime_T * tm);
void profile_get_wait (proftime_T * tm);
void *save_funccal (void);
void save_search_patterns (void);
int ins_compl_active (void);
void saveRedobuff (save_redo_T * save_redo);
static char_u *get_buffcont (buffheader_T *buffer, int dozero);
static void add_buff (buffheader_T * buf, char_u * s, long slen);
char_u *gettail (char_u *fname);
char_u *get_past_head (char_u *path);
int vim_ispathsep (int c);
int vim_ispathsep_nocolon (int c);
static void auto_next_pat (AutoPatCmd * apc, int stop_at_last);
static int match_file_pat (char_u * pattern, regprog_T * * prog, char_u * fname, char_u * sfname, char_u * tail, int allow_dirs);
static char_u *event_nr2name (event_T event);
varnumber_T get_vim_var_nr (int idx);
char_u *set_cmdarg (exarg_T *eap, char_u *oldarg);
void set_vim_var_nr (int idx, varnumber_T val);
void check_lnums (int do_curwin);
int do_cmdline (char_u * cmdline, char_u * (* fgetline) (int, void *, int), void * cookie, int flags);
void do_errthrow (struct condstack * cstack, char_u * cmdname);
static int throw_exception (void * value, except_type_T type, char_u * cmdname);
char_u *get_exception_string (void *value, except_type_T type, char_u *cmdname, int *should_free);
void msg_puts (char_u * s);
void msg_puts_attr (char_u * s, int attr);
static void msg_puts_attr_len (char_u * str, int maxlen, int attr);
static void redir_write (char_u * str, int maxlen);
int verbose_open (void);
int redirecting (void);
void execute_redir_str (char_u * value, int value_len);
void write_reg_contents (int name, char_u * str, int maxlen, int must_append);
void write_reg_contents_ex (int name, char_u * str, int maxlen, int must_append, int yank_type, long block_len);
void set_last_search_pat (char_u * s, int idx, int magic, int setlast);
static void set_vv_searchforward (void);
void redraw_all_later (int type);
buf_T *buflist_findnr (int nr);
int buflist_findpat (char_u * pattern, char_u * pattern_end, int unlisted, int diffmode, int curtab_only);
int diff_mode_buf (buf_T * buf);
static int diff_buf_idx_tp (buf_T * buf, tabpage_T * tp);
char_u *file_pat_to_reg_pat (char_u *pat, char_u *pat_end, char *allow_dirs, int no_bslash);
int vim_isspace (int x);
char_u *home_replace_save (buf_T *buf, char_u *src);
void home_replace (buf_T * buf, char_u * src, char_u * dst, int dstlen, int one);
char_u *mch_getenv (char_u *var);
int modify_fname (char_u * src, int * usedlen, char_u * * fnamep, char_u * * bufp, int * fnamelen);
char_u *expand_env_save (char_u *src);
char_u *expand_env_save_opt (char_u *src, int one);
int vim_isAbsName (char_u * name);
int mch_isdir (char_u * name);
static struct FileInfoBlock *get_fib (char_u *fname);
int mch_dirname (char_u * buf, int len);
char_u *shorten_fname (char_u *full_path, char_u *dir_name);
char_u *do_string_sub (char_u *str, char_u *pat, char_u *sub, typval_T *expr, char_u *flags);
int vim_regexec_nl (regmatch_T * rmp, char_u * line, colnr_T col);
int vim_regsub (regmatch_T * rmp, char_u * source, typval_T * expr, char_u * dest, int copy, int magic, int backslash);
static int vim_regsub_both (char_u * source, typval_T * expr, char_u * dest, int copy, int magic, int backslash);
static int prog_magic_wrong (void);
static int fill_submatch_list (int argc, typval_T * argv, int argcount);
void init_static_list (staticList10_T * sl);
static void clear_submatch_list (staticList10_T * sl);
char_u *eval_to_string (char_u *arg, char_u **nextcmd, int convert);
char_u *vim_strsave_escaped (char_u *string, char_u *esc_chars);
char_u *vim_strsave_escaped_ext (char_u *string, char_u *esc_chars, int cc, int bsl);
int rem_backslash (char_u * str);
static fptr_T do_upper (int * d, int c);
static fptr_T do_Upper (int * d, int c);
static fptr_T do_lower (int * d, int c);
static fptr_T do_Lower (int * d, int c);
static char_u *reg_getline (linenr_T lnum);
void free_string_option (char_u * p);
char_u *vim_strsave_shellescape (char_u *string, int do_special, int do_newline);
int csh_like_shell (void);
int find_cmdline_var (char_u * src, int * usedlen);
char_u *concat_str (char_u *str1, char_u *str2);
char_u *get_expr_line_src (void);
void set_expr_line (char_u * new_line);
static int init_write_reg (int name, yankreg_T * * old_y_previous, yankreg_T * * old_y_current, int must_append, int * yank_type);
int valid_yank_reg (int regname, int writing);
void emsg_invreg (int name);
void get_yank_register (int regname, int writing);
static void free_yank_all (void);
static void free_yank (long n);
static void str_to_reg (yankreg_T * y_ptr, int yank_type, char_u * str, long len, long blocklen, int str_list);
static Ptrlist *append (Ptrlist *l1, Ptrlist *l2);
char_u *lalloc_clear (long_u size, int message);
time_T vim_time (void);
static void finish_write_reg (int name, yankreg_T * old_y_previous, yankreg_T * old_y_current);
int clip_mch_own_selection (VimClipboard * cbd);
int get_real_state (void);
void redraw_curbuf_later (int type);
void redraw_buf_later (buf_T * buf, int type);
void clip_mch_set_selection (VimClipboard * cbd);
void clear_oparg (oparg_T * oap);
void do_pending_operator (cmdarg_T * cap, int old_col, int gui_yank);
char_u *ml_get_cursor (void);
static void prep_redo (int regname, long num, int cmd1, int cmd2, int cmd3, int cmd4, int cmd5);
void ResetRedobuff (void);
void free_buff (buffheader_T * buf);
void AppendCharToRedobuff (int c);
static void add_char_buff (buffheader_T * buf, int c);
void AppendNumberToRedobuff (long  n);
static void add_num_buff (buffheader_T * buf, long n);
int get_op_char (int optype);
int get_extra_op_char (int optype);
void AppendToRedobuffLit (char_u * str, int len);
void AppendToRedobuff (char_u *s);
void validate_virtcol (void);
void validate_virtcol_win (win_T * wp);
void getvvcol (win_T * wp, pos_T * pos, colnr_T * start, colnr_T * cursor, colnr_T * end);
int virtual_active (void);
void getvcol (win_T * wp, pos_T * pos, colnr_T * start, colnr_T * cursor, colnr_T * end);
int char2cells (int c);
int win_col_off (win_T * wp);
int number_width (win_T * wp);
int signcolumn_on (win_T * wp);
int win_col_off2 (win_T * wp);
int win_lbr_chartabsize (win_T * wp, char_u * line, char_u * s, colnr_T col, int * headp);
int ptr2cells (char_u * p);
static int win_chartabsize (win_T * wp, char_u * p, colnr_T col);
int vim_strsize (char_u * s);
int vim_strnsize (char_u * s, int len);
int byte2cells (int b);
int get_breakindent_win (win_T * wp, char_u * line);
int get_indent_str (char_u * ptr, int ts, int list);
int coladvance (colnr_T wcol);
int getvpos (pos_T * pos, colnr_T wcol);
static int coladvance2 (pos_T * pos, int addspaces, int finetune, colnr_T wcol);
int linetabsize (char_u * s);
int linetabsize_col (int startcol, char_u * s);
int lbr_chartabsize_adv (char_u * line, char_u * * s, colnr_T col);
int lbr_chartabsize (char_u * line, unsigned char * s, colnr_T col);
int ml_replace (linenr_T lnum, char_u * line, int copy);
int open_buffer (int read_stdin, exarg_T * eap, int flags);
int ml_open (buf_T * buf);
memfile_T *mf_open (char_u *fname, int flags);
static void mf_do_open (memfile_T * mfp, char_u * fname, int flags);
void mf_set_ffname (memfile_T * mfp);
void mch_hide (char_u * name);
static void mf_hash_init (mf_hashtab_T * mht);
bhdr_T *mf_new (memfile_T *mfp, int negative, int page_count);
static bhdr_T *mf_release (memfile_T *mfp, int page_count);
static int mf_write (memfile_T * mfp, bhdr_T * hp);
static bhdr_T *mf_find_hash (memfile_T *mfp, blocknr_T nr);
static mf_hashitem_T *mf_hash_find (mf_hashtab_T *mht, blocknr_T key);
static int mf_write_block (memfile_T * mfp, bhdr_T * hp, off_T offset, unsigned size);
char_u *ml_encrypt_data (memfile_T *mfp, char_u *data, off_T offset, unsigned  size);
static cryptstate_T *ml_crypt_prepare (memfile_T *mfp, off_T offset, int reading);
int crypt_get_method_nr (buf_T * buf);
int crypt_method_nr_from_name (char_u * name);
cryptstate_T *crypt_create (int method_nr, char_u *key, char_u *salt, int salt_len, char_u *seed, int seed_len);
void crypt_encode (cryptstate_T * state, char_u * from, size_t len, char_u * to);
void crypt_free_state (cryptstate_T * state);
static void mf_rem_used (memfile_T * mfp, bhdr_T * hp);
static void mf_rem_hash (memfile_T * mfp, bhdr_T * hp);
static void mf_hash_rem_item (mf_hashtab_T * mht, mf_hashitem_T * mhi);
static bhdr_T *mf_alloc_bhdr (memfile_T *mfp, int page_count);
static bhdr_T *mf_rem_free (memfile_T *mfp);
static void mf_ins_used (memfile_T * mfp, bhdr_T * hp);
static void mf_ins_hash (memfile_T * mfp, bhdr_T * hp);
static void mf_hash_add_item (mf_hashtab_T * mht, mf_hashitem_T * mhi);
static int mf_hash_grow (mf_hashtab_T * mht);
static void long_to_char (long n, char_u * s);
static void set_b0_fname (ZERO_BL * b0p, buf_T * buf);
int get_user_name (char_u * buf, int len);
int mch_get_user_name (char_u * s, int len);
void buf_store_time (buf_T * buf, stat_T * st, char_u * fname);
long  mch_getperm (char_u * name);
void mch_get_host_name (char_u * s, int len);
long  mch_get_pid (void);
static void ml_set_b0_crypt (buf_T * buf, ZERO_BL * b0p);
void sha2_seed (char_u * header, int header_len, char_u * salt, int salt_len);
static unsigned  int get_some_time (void);
void sha256_start (context_sha256_T * ctx);
void sha256_update (context_sha256_T * ctx, char_u * input, UINT32_T length);
static void sha256_process (context_sha256_T * ctx, char_u data [64]);
void sha256_finish (context_sha256_T * ctx, char_u digest [32]);
int mf_sync (memfile_T * mfp, int flags);
int ui_char_avail (void);
int mch_char_avail (void);
static int WaitForChar (long msec, int * interrupted, int ignore_input);
static int WaitForCharOrMouse (long msec, int * interrupted, int ignore_input);
void mch_write (char_u * s, int len);
static int RealWaitForChar (int fd, long msec, int * check_for_gpm, int * interrupted);
static int channel_fill_poll_write (int nfd_in, struct pollfd * fds);
static void channel_read (channel_T * channel, ch_part_T part, char * func);
static void ch_error (channel_T * ch, const char * fmt,...);
static channel_wait_result channel_wait (channel_T * channel, sock_T fd, int timeout);
void channel_write_any_lines (void);
static void channel_write_input (channel_T * channel);
int channel_send (channel_T * channel, ch_part_T part, char_u * buf_arg, int len_arg, char * fun);
int ch_log_active (void);
static void remove_from_writeque (writeq_T * wq, writeq_T * entry);
void channel_write_new_lines (buf_T * buf);
static int can_write_buf_line (channel_T * channel);
static void write_buf_line (buf_T * buf, linenr_T lnum, channel_T * channel);
static void channel_write_in (channel_T * channel);
int bufref_valid (bufref_T * bufref);
int buf_valid (buf_T * buf);
void term_send_eof (channel_T * ch);
static int channel_save (channel_T * channel, ch_part_T part, char_u * buf, int len, int prepend, char * lead);
static void ch_close_part_on_error (channel_T * channel, ch_part_T part, int is_err, char * func);
static void handle_resize (void);
void shell_resized (void);
void set_shellsize (int width, int height, int mustset);
int ui_get_shellsize (void);
int gui_get_shellsize (void);
int mch_get_shellsize (void);
void check_shellsize (void);
int min_rows (void);
int tabline_height (void);
void limit_screen_size (void);
void set_number_default (char * name, long val);
static int findoption (char_u * arg);
void ui_set_shellsize (int mustset);
void gui_set_shellsize (int mustset, int fit_to_display, int direction);
int gui_mch_maximized (void);
void gui_mch_newfont (void);
void gui_resize_shell (int pixel_width, int pixel_height);
int gui_get_base_width (void);
int gui_get_base_height (void);
static void gui_position_components (int total_width);
void gui_mch_set_text_area_pos (int x, int y, int w, int h);
static void gui_mch_reset_focus (void);
void gui_position_menu (void);
void gui_mch_set_menu_pos (int x, int y, int w, int h);
void gui_mch_set_scrollbar_pos (scrollbar_T * sb, int x, int y, int w, int h);
void gui_update_scrollbars (int force);
static void gui_update_horiz_scrollbar (int force);
static linenr_T gui_find_longest_lnum (void);
static colnr_T scroll_line_len (linenr_T lnum);
char_u *ml_get (linenr_T lnum);
int chartabsize (char_u * p, colnr_T col);
int curwin_col_off (void);
void gui_mch_set_scrollbar_thumb (scrollbar_T * sb, long val, long size, long max);
void vim_XawScrollbarSetThumb (Widget w, double top, double shown, double max);
static void PaintThumb (ScrollbarWidget sbw);
static void FillArea (ScrollbarWidget sbw, Position top, Position bottom, int fill, int draw_shadow);
static void gui_do_scrollbar (win_T * wp, int which, int enable);
void gui_mch_enable_scrollbar (scrollbar_T * sb, int flag);
static int gui_mswin_get_menu_height (int fix_window);
int gui_mch_get_winpos (int * x, int * y);
Boolean workshop_get_width_height (int * width, int * height);
void gui_mch_get_screen_dimensions (int * screen_w, int * screen_h);
void gui_mch_set_shellsize (int width, int height, int min_width, int min_height, int base_width, int base_height, int direction);
void gui_mch_set_winpos (int x, int y);
void mch_set_shellsize (void);
static void out_num (long n);
void screenclear (void);
void check_for_delay (int check_msg_scroll);
static void screenclear2 (void);
static void lineclear (unsigned off, int width, int attr);
int can_clear (char_u * p);
static void lineinvalid (unsigned off, int width);
static void win_rest_invalid (win_T * wp);
void compute_cmdrow (void);
void screen_start (void);
void maketitle (void);
int redrawing (void);
int char_avail (void);
int vpeekc (void);
static int vgetorpeek (int advance);
static void init_typebuf (void);
static void start_stuff (void);
static int read_readbuffers (int advance);
static int read_readbuf (buffheader_T * buf, int advance);
static int inchar (char_u * buf, int maxlen, long wait_time);
void cursor_on (void);
void out_flush_cursor (int force UNUSED, int clear_selection UNUSED);
void gui_may_flush (void);
void mch_set_mouse_shape (int shape);
void channel_handle_events (int only_keep_open);
void netbeans_parse_messages (void);
char_u *channel_first_nl (readq_T *node);
int channel_collapse (channel_T * channel, ch_part_T part, int want_nl);
char_u *channel_get (channel_T *channel, ch_part_T part);
static void nb_parse_cmd (char_u * cmd);
static void netbeans_close (void);
void netbeans_send_disconnect (void);
static void nb_send (char * buf, char * fun);
void channel_clear (channel_T * channel);
static void channel_clear_one (channel_T * channel, ch_part_T part);
static void remove_cb_node (cbq_T * head, cbq_T * node);
void free_callback (char_u * callback, partial_T * partial);
void free_tv (typval_T * varp);
static void remove_json_node (jsonq_T * head, jsonq_T * node);
static void nb_free (void);
static void coloncmd (char * cmd,...);
void setcursor (void);
int gchar_cursor (void);
void changed_window_setting (void);
void changed_window_setting_win (win_T * wp);
void changed_line_abv_curs_win (win_T * wp);
int update_screen (int type_arg);
int screen_ins_lines (int off, int row, int line_count, int end, int clear_attr, win_T * wp);
int screen_del_lines (int off, int row, int line_count, int end, int force, int clear_attr, win_T * wp);
void gui_dont_update_cursor (int undraw);
static void linecopy (int to, int from, win_T * wp);
static void redraw_block (int row, int end, win_T * wp);
void term_delete_lines (int line_count);
void gui_can_update_cursor (void);
void term_append_lines (int line_count);
int highlight_changed (void);
char_u *get_highlight_default (void);
int syn_check_group (char_u * pp, int len);
static int syn_add_group (char_u * name);
void msg_source (int attr);
static char_u *get_emsg_source (void);
static int other_sourcing_name (void);
int msg_attr (char_u * s, int attr);
static char_u *get_emsg_lnum (void);
char_u *vim_strsave_up (char_u *string);
int syn_id2attr (int hl_id);
char_u *skip_to_option_part (char_u *p);
static void set_hl_attr (int idx);
static int get_attr_entry (garray_T * table, attrentry_T * aep);
void clear_hl_tables (void);
void update_curswant (void);
static void draw_tabline (void);
int tabpage_index (tabpage_T * ftp);
int was_set_insecurely (char_u * opt, int opt_flags);
static long_u *insecure_flag (int opt_idx, int opt_flags);
int build_stl_str_hl (win_T * wp, char_u * out, size_t outlen, char_u * fmt, int use_sandbox, int fillchar, int maxwidth, struct stl_hlrec * hltab, struct stl_hlrec * tabtab);
char_u *eval_to_string_safe (char_u *arg, char_u **nextcmd, int use_sandbox);
void restore_funccal (void * vfc);
char_u *buf_spname (buf_T *buf);
int bt_quickfix (buf_T * buf);
int find_win_for_buf (buf_T * buf, win_T * * wp, tabpage_T * * tp);
int bt_nofile (buf_T * buf);
char_u *term_get_status_text (term_T *term);
int term_job_running (term_T * term);
int term_none_open (term_T * term);
void trans_characters (char_u * buf, int bufsize);
void set_internal_string_var (char_u * name, char_u * value);
static typval_T *alloc_string_tv (char_u *s);
typval_T *alloc_tv (void);
void set_var (char_u * name, typval_T * tv, int copy);
hashtab_T *find_var_ht (char_u *name, char_u **varname);
hashtab_T *get_funccal_local_ht ();
static funccall_T *get_funccal (void);
hashtab_T *get_funccal_args_ht ();
dictitem_T *find_var_in_ht (hashtab_T *ht, int htname, char_u *varname, int no_autoload);
dictitem_T *get_funccal_local_var ();
dictitem_T *get_funccal_args_var ();
int script_autoload (char_u * name, int reload);
char_u *autoload_name (char_u *name);
char_u *vim_strrchr (char_u *string, int c);
int source_runtime (char_u * name, int flags);
int source_in_path (char_u * path, char_u * name, int flags);
static int do_in_path_and_pp (char_u * path, char_u * name, int flags, void (* callback) (char_u * fname, void * ck), void * cookie);
int do_in_path (char_u * path, char_u * name, int flags, void (* callback) (char_u * fname, void * ck), void * cookie);
int copy_option_part (char_u * * option, char_u * buf, int maxlen, char * sep_chars);
int mch_expand_wildcards (int num_pat, char_u * * pat, int * num_file, char_u * * * file, int flags);
static int have_wildcard (int num, char_u * * file);
int mch_has_wildcard (char_u * p);
static int save_patterns (int num_pat, char_u * * pat, int * num_file, char_u * * * file);
void backslash_halve (char_u * p);
int check_restricted (void);
int check_secure (void);
static int have_dollars (int num, char_u * * file);
void mch_delay (long msec, int ignoreinput);
void settmode (int tmode);
int vpeekc_nomap (void);
static void check_for_codes_from_term (void);
int vgetc (void);
int garbage_collect (int testing);
int set_ref_in_previous_funccal (int copyID);
int set_ref_in_ht (hashtab_T * ht, int copyID, list_stack_T * * list_stack);
int set_ref_in_item (typval_T * tv, int copyID, ht_stack_T * * ht_stack, list_stack_T * * list_stack);
int set_ref_in_list (list_T * l, int copyID, ht_stack_T * * ht_stack);
int set_ref_in_func (char_u * name, ufunc_T * fp_in, int copyID);
static int set_ref_in_funccal (funccall_T * fc, int copyID);
int set_ref_in_call_stack (int copyID);
int set_ref_in_functions (int copyID);
int set_ref_in_func_args (int copyID);
int set_ref_in_channel (int copyID);
int set_ref_in_job (int copyID);
static int job_still_useful (job_T * job);
int set_ref_in_nb_channel (int copyID);
int set_ref_in_timer (int copyID);
int set_ref_in_quickfix (int copyID);
static int mark_quickfix_ctx (qf_info_T * qi, int copyID);
int set_ref_in_term (int copyID);
static int free_unref_items (int copyID);
int dict_free_nonref (int copyID);
int list_free_nonref (int copyID);
int free_unused_jobs_contents (int copyID, int mask);
int free_unused_channels_contents (int copyID, int mask);
void dict_free_items (int copyID);
void list_free_items (int copyID);
void free_unused_jobs (int copyID, int mask);
static void job_free_job (job_T * job);
void free_unused_channels (int copyID, int mask);
static void channel_free_channel (channel_T * channel);
int free_unref_funccal (int copyID, int testing);
static int can_free_funccal (funccall_T * fc, int copyID);
int verb_msg (char_u * s);
void ui_focus_change (int in_focus);
int check_timestamps (int focus);
int stuff_empty (void);
int typebuf_typed (void);
void set_bufref (bufref_T * bufref, buf_T * buf);
int buf_check_timestamp (buf_T * buf, int focus);
int isNetbeansBuffer (buf_T * bufp);
static int time_differs (long t1, long t2);
int bufIsChanged (buf_T * buf);
int bufIsChangedNotTerm (buf_T * buf);
int bt_dontwrite (buf_T * buf);
int file_ff_differs (buf_T * buf, int ignore_empty);
int buf_contents_changed (buf_T * buf);
buf_T *buflist_new (char_u *ffname, char_u *sfname, linenr_T lnum, int flags);
void hash_init (hashtab_T * ht);
void fname_expand (buf_T * buf, char_u * * ffname, char_u * * sfname);
char_u *fix_fname (char_u *fname);
static buf_T *buflist_findname_stat (char_u *ffname, stat_T *stp);
static int otherfile_buf (buf_T * buf, char_u * ffname, stat_T * stp);
static int buf_same_ino (buf_T * buf, stat_T * stp);
void buf_setino (buf_T * buf);
static void buflist_setfpos (buf_T * buf, win_T * win, linenr_T lnum, colnr_T col, int copy_options);
void clear_winopt (winopt_T * wop);
void clear_string_option (char_u * * pp);
void deleteFoldRecurse (garray_T * gap);
void copy_winopt (winopt_T * from, winopt_T * to);
static void check_winopt (winopt_T * wop);
static void check_string_option (char_u * * pp);
void cloneFoldGrowArray (garray_T * from, garray_T * to);
void buf_copy_options (buf_T * buf, int flags);
void free_buf_options (buf_T * buf, int free_p_ff);
void keymap_clear (garray_T * kmap);
static char_u *compile_cap_prog (synblock_T *synblock);
void check_buf_options (buf_T * buf);
void parse_cino (buf_T * buf);
long  get_sw_value (buf_T * buf);
int buf_init_chartab (buf_T * buf, int global);
int F_isalpha (int c);
int F_isdigit (int c);
dict_T *dict_alloc (void);
void init_var_dict (dict_T * dict, dictitem_T * dict_var, int scope);
static void init_changedtick (buf_T * buf);
int dict_add (dict_T * d, dictitem_T * item);
int hash_add (hashtab_T * ht, char_u * key);
int hash_add_item (hashtab_T * ht, hashitem_T * hi, char_u * key, hash_T hash);
static void clear_wininfo (buf_T * buf);
static void free_buffer (buf_T * buf);
static void free_buffer_stuff (buf_T * buf, int free_options);
void uc_clear (garray_T * gap);
void buf_delete_signs (buf_T * buf);
void changed_cline_bef_curs (void);
void netbeans_file_killed (buf_T * bufp);
static int nb_getbufno (buf_T * bufp);
static nbbuf_T *nb_get_buf (int bufno);
void map_clear_int (buf_T * buf, int mode, int local, int abbr);
static void validate_maphash (void);
static void map_free (mapblock_T * * mpp);
void dictitem_remove (dict_T * dict, dictitem_T * item);
void unref_var_dict (dict_T * dict);
void ruby_buffer_free (buf_T * buf);
void channel_buffer_free (buf_T * buf);
void free_terminal (buf_T * buf);
int job_stop (job_T * job, typval_T * argvars, char * type);
int mch_signal_job (job_T * job, char_u * how);
static void free_scrollback (term_T * term);
static void term_free_vterm (term_T * term);
INTERNAL void vterm_screen_free (VTermScreen * screen);
INTERNAL void vterm_allocator_free (VTerm * vt, void * ptr);
INTERNAL void vterm_state_free (VTermState * state);
static void buf_hashtab_remove (buf_T * buf);
void aubuflocal_remove (buf_T * buf);
static void au_remove_pat (AutoPat * ap);
static void au_cleanup (void);
void buf_freeall (buf_T * buf, int flags);
int win_valid_any_tab (win_T * win);
void goto_tabpage_win (tabpage_T * tp, win_T * wp);
void goto_tabpage_tp (tabpage_T * tp, int trigger_enter_autocmds, int trigger_leave_autocmds);
void set_keep_msg (char_u * s, int attr);
static int leave_tabpage (buf_T * new_curbuf, int trigger_leave_autocmds);
void reset_VIsual_and_resel (void);
void end_visual_mode (void);
void setmouse (void);
int mouse_has (int c);
static void may_clear_cmdline (void);
void clear_showcmd (void);
void getvcols (win_T * wp, pos_T * pos1, pos_T * pos2, colnr_T * left, colnr_T * right);
char_u *ml_get_pos (pos_T *pos);
static void display_showcmd (void);
void cursor_off (void);
void screen_puts (char_u * text, int row, int col, int attr);
void screen_puts_len (char_u * text, int textlen, int row, int col, int attr);
int arabic_shape (int c, int * ccp, int * c1p, int prev_c, int prev_c1, int next_c);
static int A_is_ok (int c);
static int A_is_iso (int c);
static int A_is_formb (int c);
static int half_shape (int c);
static int A_is_a (int cur_c);
static int chg_c_a2i (int cur_c);
static int A_is_valid (int c);
static int A_is_special (int c);
static int A_is_f (int cur_c);
static int chg_c_f2m (int cur_c);
static int A_firstc_laa (int c, int c1);
static int A_is_harakat (int c);
static int A_is_s (int cur_c);
static int chg_c_laa2f (int hid_c);
static int chg_c_laa2i (int hid_c);
static int chg_c_a2s (int cur_c);
static int chg_c_a2m (int cur_c);
static int chg_c_a2f (int cur_c);
int syn_attr2attr (int attr);
void adjust_cursor_eol (void);
int dec_cursor (void);
int dec (pos_T * lp);
void gui_remove_scrollbars (void);
int valid_tabpage (tabpage_T * tpc);
static void enter_tabpage (tabpage_T * tp, buf_T * old_curbuf, int trigger_enter_autocmds, int trigger_leave_autocmds);
static void win_enter_ext (win_T * wp, int undo_sync, int curwin_invalid, int trigger_new_autocmds, int trigger_enter_autocmds, int trigger_leave_autocmds);
int win_valid (win_T * win);
void u_sync (int force);
static long  get_undolevel (void);
static void u_getbot (void);
static u_entry_T *u_get_headentry (void);
void check_cursor (void);
void check_cursor_lnum (void);
void check_cursor_col (void);
void check_cursor_col_win (win_T * win);
void changed_line_abv_curs (void);
void shorten_fnames (int force);
void mf_fullname (memfile_T * mfp);
void status_redraw_all (void);
void win_setheight (int height);
void win_setheight_win (int height, win_T * win);
static void frame_setheight (frame_T * curfrp, int height);
int win_comp_pos (void);
static void frame_comp_pos (frame_T * topfrp, int * row, int * col);
void screen_fill (int start_row, int end_row, int start_col, int end_col, int c1, int c2, int attr);
static void space_to_screenline (int off, int attr);
void win_setwidth (int width);
void win_setwidth_win (int width, win_T * wp);
static void frame_setwidth (frame_T * curfrp, int width);
static int frame_minwidth (frame_T * topfrp, win_T * next_curwin);
static void frame_new_width (frame_T * topfrp, int width, int leftfirst, int wfw);
void win_new_width (win_T * wp, int width);
void invalidate_botline_win (win_T * wp);
static int frame_fixed_width (frame_T * frp);
void last_status (int morewin);
static void last_status_rec (frame_T * fr, int statusline);
void comp_col (void);
static void frame_fix_height (win_T * wp);
void shell_new_columns (void);
static int frame_check_width (frame_T * topfrp, int width);
void win_equal (win_T * next_curwin, int current, int dir);
static void win_equal_rec (win_T * next_curwin, int current, frame_T * topfr, int dir, int col, int row, int width, int height);
static int frame_has_win (frame_T * frp, win_T * wp);
static int frame_fixed_height (frame_T * frp);
void gui_may_update_scrollbars (void);
void gui_init_which_components (char_u * oldval);
int win_hasvertsplit (void);
void gui_mch_enable_menu (int flag);
void gui_mch_show_toolbar (int showit);
void gui_mch_enable_beval_area (BalloonEval * beval);
static VOID CALLBACK BevalTimerProc (HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
void gui_mch_disable_beval_area (BalloonEval * beval);
int menu_is_separator (char_u * name);
int gui_mch_compute_toolbar_height (void);
void gui_mch_toggle_tearoffs (int enable);
void win_enter (win_T * wp, int undo_sync);
void unblock_autocmds (void);
void diff_buf_delete (buf_T * buf);
static void diff_redraw (int dofold);
void foldUpdateAll (win_T * win);
void check_topfill (win_T * wp, int down);
int plines_win_nofill (win_T * wp, linenr_T lnum, int winheight);
int lineFolded (win_T * win, linenr_T lnum);
long  foldedCount (win_T * win, linenr_T lnum, foldinfo_T * infop);
int plines_win_nofold (win_T * wp, linenr_T lnum);
int win_linetabsize (win_T * wp, char_u * line, colnr_T len);
void reset_synblock (win_T * wp);
void syntax_clear (synblock_T * block);
static void clear_keywtab (hashtab_T * ht);
static void syn_clear_pattern (synblock_T * block, int i);
static void syn_clear_cluster (synblock_T * block, int i);
void syn_stack_free_all (synblock_T * block);
static void syn_stack_free_block (synblock_T * block);
static void clear_syn_state (synstate_T * p);
void unref_extmatch (reg_extmatch_T * em);
static void invalidate_current_state (void);
static void clear_current_state (void);
void clearFolding (win_T * win);
void ml_close (buf_T * buf, int del_file);
void mf_close (memfile_T * mfp, int del_file);
int mch_remove (char_u * name);
int mch_isdir (char_u * name);
static int win32_getattrs (char_u * name);
int mch_is_symbolic_link (char_u * name);
int mch_rmdir (char_u * name);
static int win32_setattrs (char_u * name, int attrs);
static void mf_free_bhdr (bhdr_T * hp);
static void mf_hash_free (mf_hashtab_T * mht);
static void mf_hash_free_all (mf_hashtab_T * mht);
void u_blockfree (buf_T * buf);
static void u_freeheader (buf_T * buf, u_header_T * uhp, u_header_T * * uhpp);
static void u_freebranch (buf_T * buf, u_header_T * uhp, u_header_T * * uhpp);
static void u_freeentries (buf_T * buf, u_header_T * uhp, u_header_T * * uhpp);
static void u_freeentry (u_entry_T * uep, long n);
void u_clearall (buf_T * buf);
static void buf_hashtab_add (buf_T * buf);
void buf_clear_file (buf_T * buf);
void unchanged (buf_T * buf, int ff);
void ml_setflags (buf_T * buf);
void save_file_ff (buf_T * buf);
void check_status (buf_T * buf);
void netbeans_unmodified (buf_T * bufp);
void netbeans_deleted_all_lines (buf_T * bufp);
static nbbuf_T *nb_bufp2nbbuf_fire (buf_T *bufp, int *bufnop);
void clrallmarks (buf_T * buf);
void fmarks_check_names (buf_T * buf);
static void fmarks_check_one (xfmark_T * fm, char_u * name, buf_T * buf);
int prep_exarg (exarg_T * eap, buf_T * buf);
void wipe_buffer (buf_T * buf, int aucmd);
void close_buffer (win_T * win, buf_T * buf, int action, int abort_if_last);
int bt_terminal (buf_T * buf);
void set_last_cursor (win_T * win);
int one_window (void);
int diffopt_hiddenoff (void);
void aucmd_prepbuf (aco_save_T * aco, buf_T * buf);
void win_alloc_aucmd_win (void);
static win_T *win_alloc (win_T *after, int hidden);
int win_alloc_lines (win_T * wp);
void win_free_lsize (win_T * wp);
void win_append (win_T * after, win_T * wp);
void gui_create_scrollbar (scrollbar_T * sb, int type, win_T * wp);
void gui_mch_create_scrollbar (scrollbar_T * sb, int orient);
static void gui_athena_scroll_cb_jump (Widget w, XtPointer client_data, XtPointer call_data);
static void gui_athena_scroll_cb_scroll (Widget w, XtPointer client_data, XtPointer call_data);
void foldInitWin (win_T * new_win);
static void win_init_some (win_T * newp, win_T * oldp);
void win_copy_options (win_T * wp_from, win_T * wp_to);
static int briopt_check (win_T * wp);
static void new_frame (win_T * wp);
void win_init_empty (win_T * wp);
void make_snapshot (int idx);
static void clear_snapshot (tabpage_T * tp, int idx);
static void clear_snapshot_rec (frame_T * fr);
static void make_snapshot_rec (frame_T * fr, frame_T * * frp);
int win_split_ins (int size, int flags, win_T * new_wp, int dir);
static void win_free (win_T * wp, tabpage_T * tp);
void alist_unlink (alist_T * al);
void alist_clear (alist_T * al);
void ruby_window_free (win_T * win);
void clear_matches (win_T * wp);
void free_jumplist (win_T * wp);
void qf_free_all (win_T * wp);
static void ll_free_all (qf_info_T * * pqi);
static void qf_free (qf_info_T * qi, int idx);
static void qf_free_items (qf_info_T * qi, int idx);
static void qf_clean_dir_stack (struct dir_stack_T * * stackptr);
void gui_mch_destroy_scrollbar (scrollbar_T * sb);
void remove_winbar (win_T * wp);
static int remove_menu (vimmenu_T * * menup, char_u * name, int modes, int silent);
char_u *menu_name_skip (char_u *name);
static int menu_name_equal (char_u * name, vimmenu_T * menu);
static int menu_namecmp (char_u * name, char_u * mname);
static void free_menu_string (vimmenu_T * menu, int idx);
static void free_menu (vimmenu_T * * menup);
void gui_mch_destroy_menu (vimmenu_T * menu);
static Boolean gui_athena_menu_has_submenus (Widget id, Widget ignore);
static Boolean has_submenu (Widget widget);
void gui_mch_destroy_beval_area (BalloonEval * beval);
void win_remove (win_T * wp, tabpage_T * tp);
static void win_init (win_T * newp, win_T * oldp, int flags);
void copy_jumplist (win_T * from, win_T * to);
void copy_loclist (win_T * from, win_T * to);
static qf_info_T *ll_new_list (void);
static int qf_add_entry (qf_info_T * qi, int qf_idx, char_u * dir, char_u * fname, int bufnum, char_u * mesg, long lnum, int col, int vis_col, char_u * pattern, int nr, int type, int valid);
static int qf_get_fnum (qf_info_T * qi, int qf_idx, char_u * directory, char_u * fname);
char_u *concat_fnames (char_u *fname1, char_u *fname2, int sep);
void add_pathsep (char_u * p);
static char_u *qf_guess_filepath (qf_info_T *qi, int qf_idx, char_u *filename);
void copyFoldingState (win_T * wp_from, win_T * wp_to);
char_u *check_colorcolumn (win_T *wp);
void qsort (void * base, size_t elm_count, size_t elm_size, int (* cmp) (const void *, const void *));
static int int_cmp (const void * a, const void * b);
static void frame_insert (frame_T * before, frame_T * frp);
static void frame_append (frame_T * after, frame_T * frp);
void set_fraction (win_T * wp);
static void frame_add_vsep (frame_T * frp);
static void frame_fix_width (win_T * wp);
static void frame_add_statusline (frame_T * frp);
int readfile (char_u * fname, char_u * sfname, linenr_T from, linenr_T lines_to_skip, linenr_T lines_to_read, exarg_T * eap, int flags);
static int check_readonly (int * forceit, buf_T * buf);
int check_file_readonly (char_u * fname, int perm);
int mch_access (char * n, int p);
void getout (int exitval);
void hash_debug_results (void);
void write_viminfo (char_u * file, int forceit);
static int no_viminfo (void);
static char_u *viminfo_filename (char_u *file);
char_u *find_viminfo_parameter (int type);
char_u *buf_modname (int shortname, char_u *fname, char_u *ext, int prepend_dot);
int mch_setperm (char_u * name, long perm);
static void do_viminfo (FILE * fp_in, FILE * fp_out, int flags);
void prepare_viminfo_registers (void);
void prepare_viminfo_marks (void);
static int read_viminfo_up_to_marks (vir_T * virp, int forceit, int writing);
int viminfo_readline (vir_T * virp);
int vim_fgets (char_u * buf, int size, FILE * fp);
static int read_viminfo_barline (vir_T * virp, int got_encoding, int force, int writing);
void ga_add_string (garray_T * gap, char_u * p);
static int barline_parse (vir_T * virp, char_u * text, garray_T * values);
void handle_viminfo_register (garray_T * values, int force);
int get_register_name (int num);
void handle_viminfo_mark (garray_T * values, int force);
static int viminfo_encoding (vir_T * virp);
int get_viminfo_parameter (int type);
int read_viminfo_varlist (vir_T * virp, int writing);
static void tab (VTermState * state, int count, int direction);
static int is_col_tabstop (VTermState * state, int col);
char_u *viminfo_readstring (vir_T *virp, int off, int convert);
typval_T *eval_expr (char_u *arg, char_u **nextcmd);
void *clear_current_funccal ();
void restore_current_funccal (void * f);
int read_viminfo_bufferlist (vir_T * virp, int writing);
int read_viminfo_register (vir_T * virp, int force);
int viminfo_error (char * errnum, char * message, char_u * line);
int emsg (char_u * s);
int emsg_not_now (void);
static int ignore_error (char_u * msg);
int cause_errthrow (char_u * mesg, int severe, int * ignore);
void discard_current_exception (void);
static void discard_exception (except_T * excp, int was_finished);
static void free_msglist (struct msglist * l);
void beep_flush (void);
void flush_buffers (int flush_typeahead);
void vim_beep (unsigned val);
void out_str_cf (char_u * s);
void do_sleep (long msec);
int has_any_channel (void);
char_u *skiptowhite (char_u *p);
int read_viminfo_search_pattern (vir_T * virp, int force);
int read_viminfo_sub_string (vir_T * virp, int force);
int read_viminfo_filemark (vir_T * virp, int force);
static void write_viminfo_version (FILE * fp_out);
void write_viminfo_search_pattern (FILE * fp);
static void wvsp_one (FILE * fp, int idx, char * s, int sc);
void viminfo_writestring (FILE * fd, char_u * p);
void write_viminfo_sub_string (FILE * fp);
int barline_writestring (FILE * fd, char_u * s, int remaining_start);
void write_viminfo_registers (FILE * fp);
void finish_viminfo_registers (void);
void write_viminfo_varlist (FILE * fp);
static var_flavour_T var_flavour (char_u * varname);
void write_viminfo_filemarks (FILE * fp);
static void write_one_filemark (FILE * fp, xfmark_T * fm, int c1, int c2);
char_u *buflist_nr2name (int n, int fullname, int helptail);
static int skip_for_viminfo (buf_T * buf);
int removable (char_u * name);
void setpcmark (void);
void cleanup_jumplist (win_T * wp, int loadfiles);
void fname2fnum (xfmark_T * fm);
void finish_viminfo_marks (void);
void write_viminfo_bufferlist (FILE * fp);
int vim_snprintf_add (char * str, size_t str_m, char * fmt,...);
static void write_viminfo_barlines (vir_T * virp, FILE * fp_out);
void write_viminfo_marks (FILE * fp_out, garray_T * buflist);
static void write_buffer_marks (buf_T * buf, FILE * fp_out);
static void write_one_mark (FILE * fp_out, int c, pos_T * pos);
void copy_viminfo_marks (vir_T * virp, FILE * fp_out, garray_T * buflist, int eof, int flags);
static int buf_compare (const void * s1, const void * s2);
void set_vim_var_list (int idx, list_T * val);
int list_append_string (list_T * l, char_u * str, int len);
int vim_rename (char_u * from, char_u * to);
void profile_dump (void);
static void script_dump_profile (FILE * fd);
int profile_equal (proftime_T * tm1, proftime_T * tm2);
void func_dump_profile (FILE * fd);
static void prof_func_line (FILE * fd, int count, proftime_T * total, proftime_T * self, int prefer_self);
static int prof_total_cmp (const void * s1, const void * s2);
int profile_cmp (const proftime_T * tm1, const proftime_T * tm2);
static void prof_sort_list (FILE * fd, ufunc_T * * sorttab, int st_len, char * title, int prefer_self);
static int prof_self_cmp (const void * s1, const void * s2);
void wait_return (int redraw);
static void hit_return_msg (void);
void msg_putchar (int c);
void msg_putchar_attr (int c, int attr);
int safe_vgetc (void);
int get_keystroke (void);
void do_outofmem_msg (long_u size);
int ui_inchar (char_u * buf, int maxlen, long wtime, int tb_change_cnt);
void prof_inchar_enter (void);
int mch_inchar (char_u * buf, int maxlen, long time, int tb_change_cnt);
int trigger_cursorhold (void);
int has_cursorhold (void);
void before_blocking (void);
void updatescript (int c);
void ml_sync_all (int check_file, int check_char);
int mf_need_trans (memfile_T * mfp);
void ml_preserve (buf_T * buf, int message);
int typebuf_changed (int tb_change_cnt);
void read_error_exit (void);
void preserve_exit (void);
void prepare_to_exit (void);
void out_trash (void);
void stoptermcap (void);
void reset_cterm_colors (void);
void mch_delay (long msec, int ignoreinput);
void ml_close_notmod (void);
void ml_close_all (int del_file);
void spell_delete_wordlist (void);
static void int_wordlist_spl (char_u * fname);
char_u *spell_enc (void);
void vim_deltempdir (void);
int delete_recursive (char_u * name);
int mch_isrealdir (char_u * name);
void FreeWild (int count, char_u * * files);
int vim_handle_signal (int sig);
int gui_inchar (char_u * buf, int maxlen, long wtime, int tb_change_cnt);
void prof_inchar_exit (void);
void profile_end (proftime_T * tm);
void profile_add (proftime_T * tm, proftime_T * tm2);
int fix_input_buffer (char_u * buf, int len);
int check_termcode (int max_offset, char_u * buf, int bufsize, int * buflen);
static void gather_termleader (void);
char_u *set_option_value (char_u *name, long  number, char_u *string, int opt_flags);
static int find_key_option (char_u * arg);
void ttest (int pairs);
void check_options (void);
static char_u *get_varp (struct vimoption *p);
void free_one_termoption (char_u * var);
static void set_color_count (int nr);
void set_string_option_direct (char_u * name, int opt_idx, char_u * val, int opt_flags, int set_sid);
static char_u *get_varp_scope (struct vimoption *p, int opt_flags);
static void set_string_option_global (int opt_idx, char_u * * varp);
static void set_option_scriptID_idx (int opt_idx, int opt_flags, int id);
static char_u *set_string_option (int opt_idx, char_u *value, int opt_flags);
static char_u *did_set_string_option (int opt_idx, char_u **varp, int new_value_alloced, char_u *oldval, char_u *errbuf, int opt_flags);
char_u *vim_strpbrk (char_u *s, char_u *charset);
int term_is_gui (char_u * name);
int set_termname (char_u * term);
void clear_termoptions (void);
void mch_restore_title (int which);
void mch_settitle (char_u * title, char_u * icon);
void free_termoptions (void);
static int istermoption (struct vimoption * p);
void clear_termcodes (void);
int tgetflag (char * id);
char *tgetstr (char *id, char **buf);
static char *_find (char *s, char *set);
static int _match (char * s1, char * s2);
int tgetnum (char * id);
int is_not_a_term ();
int do_dialog (int type, char_u * title, char_u * message, char_u * buttons, int dfltbutton, char_u * textfield, int ex_cmd);
int gui_mch_dialog (int type, char_u * title, char_u * message, char_u * buttons, int dfltbutton, char_u * textfield, int ex_cmd);
void gui_mch_mousehide (int hide);
static void gui_athena_menu_colors (Widget id);
static void keyhit_callback (Widget w, XtPointer client_data, XEvent * event, Boolean * cont);
static void butproc (Widget w, XtPointer client_data, XtPointer call_data);
static void dialog_wm_handler (Widget w, XtPointer client_data, XEvent * event, Boolean * dum);
static char_u *msg_show_console_dialog (char_u *message, char_u *buttons, int dfltbutton);
void display_confirm_msg (void);
void ins_char_typebuf (int c);
int ins_typebuf (char_u * str, int noremap, int offset, int nottyped, int silent);
void msg_end_prompt (void);
static void parse_builtin_tcap (char_u * term);
void set_term_option_alloced (char_u * * p);
void gui_init (void);
int gui_init_check (void);
int gui_mch_init_check (void);
int do_source (char_u * fname, int check_other, int is_vimrc);
int has_autocmd (event_T event, char_u * sfname, buf_T * buf);
void vimrc_found (char_u * fname, char_u * envname);
int option_was_set (char_u * name);
static void set_option_default (int opt_idx, int opt_flags, int compatible);
void win_comp_scroll (win_T * wp);
static void didset_options (void);
int init_chartab (void);
static int opt_strings_flags (char_u * val, char * * values, unsigned * flagp, int list);
static int check_fuoptions (p_fuoptions, flags, bgcolor);
int spell_check_msm (void);
int spell_check_sps (void);
static char_u *did_set_spell_option (int is_spellfile);
char_u *did_set_spelllang (win_T *wp);
static void clear_midword (win_T * wp);
int fullpathcmp (char_u * s1, char_u * s2, int checkname);
slang_T *spell_load_file (char_u *fname, char_u *lang, slang_T *old_lp, int silent);
slang_T *slang_alloc (char_u *lang);
int get4c (FILE * fd);
char_u *read_string (FILE *fd, int cnt);
static int read_region_section (FILE * fd, slang_T * lp, int len);
static int read_charflags_section (FILE * fd);
static char_u *read_cnt_string (FILE *fd, int cnt_bytes, int *cntp);
static void set_spell_charflags (char_u * flags, int cnt, char_u * fol);
void clear_spell_chartab (spelltab_T * sp);
static int set_spell_finish (spelltab_T * new_st);
static int read_prefcond_section (FILE * fd, slang_T * lp);
int get2c (FILE * fd);
static int read_rep_section (FILE * fd, garray_T * gap, short * first);
static int read_sal_section (FILE * fd, slang_T * slang);
static void set_sal_first (slang_T * lp);
static int read_sofo_section (FILE * fd, slang_T * slang);
static int set_sofo (slang_T * lp, char_u * from, char_u * to);
static void set_map_str (slang_T * lp, char_u * map);
static int read_words_section (FILE * fd, slang_T * lp, int len);
void count_common_word (slang_T * lp, char_u * word, int len, int count);
time_T get8ctime (FILE * fd);
static int read_compound (FILE * fd, slang_T * slang, int len);
int byte_in_str (char_u * str, int n);
int init_syl_tab (slang_T * slang);
static int spell_read_tree (FILE * fd, char_u * * bytsp, idx_T * * idxsp, int prefixtree, int prefixcnt);
static idx_T read_tree_node (FILE * fd, char_u * byts, idx_T * idxs, int maxidx, idx_T startidx, int prefixtree, int maxprefcondnr);
int get3c (FILE * fd);
void slang_free (slang_T * lp);
void slang_clear (slang_T * lp);
void hash_clear_all (hashtab_T * ht, int off);
void slang_clear_sug (slang_T * lp);
void close_spellbuf (buf_T * buf);
static void spell_load_lang (char_u * lang);
int do_in_runtimepath (char_u * name, int flags, void (* callback) (char_u * fname, void * ck), void * cookie);
static void spell_load_cb (char_u * fname, void * cookie);
static int find_region (char_u * rp, char_u * region);
static void use_midword (slang_T * lp, win_T * wp);
static void fill_breakat_flags (void);
static void didset_options2 (void);
static int check_opt_wim (void);
static char_u *set_chars_option (char_u **varp);
char_u *vim_getenv (char_u *name, int *mustfree);
static char_u *vim_version_dir (char_u *vimdir);
static char_u *remove_tail (char_u *p, char_u *pend, char_u *name);
linenr_T dbg_find_breakpoint (int file, char_u * fname, linenr_T after);
static linenr_T debuggy_find (int file, char_u * fname, linenr_T after, garray_T * gap, int * fp);
char_u *typval_tostring (arg);
int typval_compare (typval_T * typ1, typval_T * typ2, exptype_T type, int type_is, int ic);
int list_equal (list_T * l1, list_T * l2, int ic, int recursive);
long  list_len (list_T * l);
int tv_equal (typval_T * tv1, typval_T * tv2, int ic, int recursive);
static int func_equal (typval_T * tv1, typval_T * tv2, int ic);
int dict_equal (dict_T * d1, dict_T * d2, int ic, int recursive);
long  dict_len (dict_T * d);
dictitem_T *dict_find (dict_T *d, char_u *key, int len);
varnumber_T get_tv_number (typval_T * varp);
static int pattern_match (char_u * pat, char_u * text, int ic);
void time_push (void * tv_rel, void * tv_start);
void new_script_vars (scid_T id);
int has_profiling (int file, char_u * fname, int * fp);
static void script_do_profile (scriptitem_T * si);
void profile_zero (proftime_T * tm);
char_u *getsourceline (int c, void *cookie, int indent);
void script_line_end (void);
void profile_sub_wait (proftime_T * tm, proftime_T * tma);
void profile_self (proftime_T * self, proftime_T * total, proftime_T * children);
static char_u *get_one_sourceline (struct source_cookie *sp);
void script_line_start (void);
void dbg_breakpoint (char_u * name, linenr_T lnum);
void time_msg (char * mesg, void * tv_start);
static void time_diff (struct timeval * then, struct timeval * now);
void time_pop (void * tp);
void prof_child_exit (proftime_T * tm);
void script_prof_restore (proftime_T * tm);
int process_env (char_u * env, int is_viminit);
int do_cmdline_cmd (char_u * cmd);
int gui_mch_init (void);
void reset_VIsual (void);
char_u **new_fnames_from_AEDesc (AEDesc *theList, long  *numFiles, OSErr *error);
char_u * FullPathFromFSSpec_save (FSSpec file);
void mch_exit (int r);
void win_resize_off (void);
void alist_add (alist_T * al, char_u * fname, int set_fnum);
int buflist_add (char_u * fname, int flags);
int vim_chdirfile (char_u * fname, char * trigger_autocmd);
char_u *gettail_sep (char_u *fname);
char_u *alist_name (aentry_T *aep);
void handle_drop (int filec, char_u * * filev, int split);
int text_locked (void);
int curbuf_locked (void);
int allbuf_locked (void);
int buf_hide (buf_T * buf);
int check_changed (buf_T * buf, int flags);
int autowrite (buf_T * buf, int forceit);
int buf_write_all (buf_T * buf, int forceit);
int buf_write (buf_T * buf, char_u * fname, char_u * sfname, linenr_T start, linenr_T end, exarg_T * eap, int append, int forceit, int reset_changed, int filtering);
unsigned  int get_bkc_value (buf_T * buf);
static int set_rw_fname (char_u * fname, char_u * sfname);
int setfname (buf_T * buf, char_u * ffname, char_u * sfname, int message);
void fname_case (char_u * name, int len);
void buf_name_changed (buf_T * buf);
void ml_setname (buf_T * buf);
static char_u *findswapname (buf_T *buf, char_u **dirp, char_u *old_fname);
char_u *makeswapname (char_u *fname, char_u *ffname, buf_T *buf, char_u *dir_name);
static char_u *make_percent_swname (char_u *dir, char_u *name);
char_u *modname (char_u *fname, char_u *ext, int prepend_dot);
char_u *get_file_in_dir (char_u *fname, char_u *dname);
int same_directory (char_u * f1, char_u * f2);
static long  char_to_long (char_u * s);
static int do_swapexists (buf_T * buf, char_u * fname);
void gui_start (void);
void getout_preserve_modified (int exitval);
static void gui_attempt_start (void);
void termcapinit (char_u * name);
void set_string_default (char * name, char_u * val);
static void set_string_default_esc (char * name, char_u * val, int escape);
int gui_get_x11_windis (Window * win, Display * * dis);
void set_title_defaults (void);
int mch_can_restore_title (void);
int mch_can_restore_icon (void);
static void attention_message (buf_T * buf, char_u * fname);
void msg_home_replace (char_u * fname);
static void msg_home_replace_attr (char_u * fname, int attr);
int msg_outtrans_attr (char_u * str, int attr);
int msg_outtrans_len_attr (char_u * msgstr, int len, int attr);
static time_t swapfile_info (char_u * fname);
int mch_get_uname (uid_t uid, char_u * s, int len);
int msg_outtrans (char_u * str);
static int ml_check_b0_id (ZERO_BL * b0p);
void msg_outnum (long n);
static int b0_magic_wrong (ZERO_BL * b0p);
static void ml_upd_block0 (buf_T * buf, upd_block0_T what);
bhdr_T *mf_get (memfile_T *mfp, blocknr_T nr, int page_count);
static int mf_read (memfile_T * mfp, bhdr_T * hp);
void ml_decrypt_data (memfile_T * mfp, char_u * data, off_T offset, unsigned size);
void crypt_decode_inplace (cryptstate_T * state, char_u * buf, size_t len);
static void ml_set_mfp_crypt (buf_T * buf);
static void set_b0_dir_flag (ZERO_BL * b0p, buf_T * buf);
void check_arg_idx (win_T * win);
static int editing_arg_idx (win_T * win);
void ml_timestamp (buf_T * buf);
int au_has_group (char_u * name);
static int au_find_group (char_u * name);
static char_u *get_deleted_augroup (void);
int do_doautocmd (char_u * arg, int do_msg, int * did_something);
static int au_get_grouparg (char_u * * argp);
static char_u *find_end_event (char_u *arg, int have_group);
void do_modelines (int flags);
static int chk_modeline (linenr_T lnum, int flags);
int do_set (char_u * arg, int opt_flags);
static void showoptions (int all, int opt_flags);
static int optval_default (struct vimoption * p, char_u * varp);
static void option_value2string (struct vimoption * opp, int opt_flags);
static int wc_use_keyname (char_u * varp, long * wcp);
int find_special_key_in_table (int c);
char_u *get_special_key_name (int c, int modifiers);
void str2specialbuf (char_u * sp, char_u * buf, int len);
char_u *str2special (char_u **sp, int from);
static void showoneopt (struct vimoption * p, int opt_flags);
int curbufIsChanged (void);
static void set_options_default (int opt_flags);
void show_termcodes (void);
int show_one_termcode (char_u * name, char_u * code, int printit);
void gotocmdline (int clr);
void last_set_msg (scid_T scriptID);
char_u *get_scriptname (scid_T id);
static char_u *set_bool_option (int opt_idx, char_u *varp, int value, int opt_flags);
static void compatible_set (void);
void u_compute_hash (char_u * hash);
void u_read_undo (char_u * name, char_u * hash, char_u * orig_name);
char_u *u_get_undo_file_name (char_u *buf_ffname, int reading);
cryptstate_T *crypt_create_from_file (FILE *fp, char_u *key);
int crypt_method_nr_from_magic (char * ptr, int len);
int crypt_get_header_len (int method_nr);
cryptstate_T *crypt_create_from_header (int method_nr, char_u *key, char_u *header);
int crypt_whole_undofile (int method_nr);
static int undo_read (bufinfo_T * bi, char_u * buffer, size_t size);
static void corruption_error (char * mesg, char_u * file_name);
static int undo_read_4c (bufinfo_T * bi);
void give_warning (char_u * message, int hl);
static char_u *read_string_decrypt (bufinfo_T *bi, int len);
static time_t undo_read_time (bufinfo_T * bi);
static int undo_read_byte (bufinfo_T * bi);
static int undo_read_2c (bufinfo_T * bi);
static u_header_T *unserialize_uhp (bufinfo_T *bi, char_u *file_name);
static void unserialize_pos (bufinfo_T * bi, pos_T * pos);
static void unserialize_visualinfo (bufinfo_T * bi, visualinfo_T * info);
static u_entry_T *unserialize_uep (bufinfo_T *bi, int *error, char_u *file_name);
static void u_free_uhp (u_header_T * uhp);
static void redraw_titles (void);
int term_in_normal_mode (void);
int term_is_finished (buf_T * buf);
void set_options_bin (int oldval, int newval, int opt_flags);
void mf_close_file (buf_T * buf, int getlines);
static void paste_option_changed (void);
void do_check_scrollbind (int check);
void check_scrollbind (linenr_T topline_diff, long leftcol_diff);
void diff_set_topline (win_T * fromwin, win_T * towin);
static int diff_buf_idx (buf_T * buf);
void scrollup (long line_count, int byfold);
void cursor_correct (void);
void validate_botline (void);
static void comp_botline (win_T * wp);
int plines_win (win_T * wp, linenr_T lnum, int winheight);
static void redraw_for_cursorline (win_T * wp);
void set_empty_rows (win_T * wp, int used);
int plines (linenr_T lnum);
int leftcol_changed (void);
void set_fileformat (int t, int opt_flags);
static void did_set_title (int icon);
void diff_buf_adjust (win_T * win);
void diff_buf_add (buf_T * buf);
void redraw_later_clear (void);
void highlight_gui_started (void);
void set_normal_colors (void);
static int set_group_colors (char_u * name, guicolor_T * fgp, guicolor_T * bgp, int do_menu, int use_norm, int do_tooltip);
static void gui_do_one_color (int idx, int do_menu, int do_tooltip);
static void hl_do_font (int idx, char_u * arg, int do_normal, int do_menu, int do_tooltip, int free_font);
void gui_mch_free_font (GuiFont font);
static GuiFont font_name2handle (char_u * name);
GuiFont gui_mch_get_font (char_u * name, int giveErrorIfMissing);
GuiFont gui_mac_find_font (char_u * font_name);
void changed (void);
void change_warning (int col);
int msg_end (void);
int showmode (void);
void msg_clr_cmdline (void);
static void msg_pos_mode (void);
int shortmess (int x);
int get_keymap_str (win_T * wp, char_u * fmt, char_u * buf, int len);
static void recording_mode (int attr);
static void win_redr_ruler (win_T * wp, int always);
static void win_redr_custom (win_T * wp, int draw_ruler);
static int fillchar_status (int * attr, win_T * wp);
char_u *transstr (char_u *s);
void col_print (char_u * buf, size_t buflen, int col, int vcol);
void get_rel_pos (win_T * wp, char_u * buf, int buflen);
void changed_int (void);
char_u * C2Pascal_save_and_remove_backslash (char_u *Cstring);
static int points_to_pixels (char_u * str, char_u * * end, int vertical);
int gui_init_font (char_u * font_list, int fontset);
int gui_mch_init_font (char_u * font_name, int fontset);
static GuiFont gui_mac_select_font (char_u * font_name);
static void GetFontPanelSelection (char_u *outName);
void hl_set_font_name (char_u * font_name);
void gui_mch_new_colors (void);
void gui_mch_new_menu_colors (void);
static void gui_mch_submenu_change (vimmenu_T * menu, int colors);
static void get_toolbar_pixmap (vimmenu_T * menu, Pixmap * sen);
static void createXpmImages (char_u * path, char * * xpm, Pixmap * sen);
void gui_mch_get_toolbar_colors (Pixel * bgp, Pixel * fgp, Pixel * bsp, Pixel * tsp, Pixel * hsp);
static void gui_athena_menu_font (Widget id);
void gui_mch_new_tooltip_colors (void);
vimmenu_T *gui_find_menu (char_u *path_name);
static vimmenu_T **get_root_menu (char_u *name);
static int menu_is_winbar (char_u * name);
void gui_mch_set_scrollbar_colors (scrollbar_T * sb);
static void gui_athena_scroll_colors (Widget id);
void reset_v_option_vars (void);
static void check_redraw (long_u flags);
int string_to_key (char_u * arg, int multi_byte);
static char_u *set_num_option (int opt_idx, char_u *varp, long  value, char_u *errbuf, size_t errbuflen, int opt_flags);
void win_setminheight (void);
int gui_mch_adjust_charheight (void);
int gui_mch_adjust_charwidth (void);
void newFoldLevel (void);
static void newFoldLevelWin (win_T * wp);
void status_redraw_curbuf (void);
void command_height (void);
static void frame_add_height (frame_T * frp, int n);
void ml_open_files (void);
static char_u *gui_bg_default (void);
int gui_get_lightness (guicolor_T pixel);
guicolor_T gui_mch_get_rgb (guicolor_T pixel);
static char_u *term_bg_default (void);
static char_u *option_expand (int opt_idx, char_u *val);
static void trigger_optionsset_string (int opt_idx, int opt_flags, char_u * oldval, char_u * newval);
static void did_set_option (int opt_idx, int opt_flags, int new_value);
static int apply_autocmds_exarg (event_T event, char_u * fname, char_u * fname_io, int force, buf_T * buf, exarg_T * eap);
void u_unchanged (buf_T * buf);
static void u_unch_branch (u_header_T * uhp);
void u_update_save_nr (buf_T * buf);
void aucmd_restbuf (aco_save_T * aco);
void win_goto (win_T * wp);
void text_locked_msg (void);
char_u *get_text_locked_msg (void);
void update_single_line (win_T * wp, linenr_T lnum);
void profile_setlimit (long msec, proftime_T * tm);
void syn_set_timeout (proftime_T * tm);
static void update_prepare (void);
static void start_search_hl (void);
void last_pat_prog (regmmatch_T * regmatch);
int search_regcomp (char_u * pat, int pat_save, int pat_use, int options, regmmatch_T * regmatch);
char_u *reverse_text (char_u *s);
void save_re_pat (int idx, char_u * pat, int magic);
int ignorecase (char_u * pat);
int ignorecase_opt (char_u * pat, int ic_in, int scs);
int ctrl_x_mode_not_default (void);
int pat_has_uppercase (char_u * pat);
static void init_search_hl (win_T * wp);
static void prepare_search_hl (win_T * wp, linenr_T lnum);
int re_multiline (regprog_T * prog);
static void next_search_hl (win_T * win, match_T * shl, linenr_T lnum, colnr_T mincol, matchitem_T * cur);
int profile_passed_limit (proftime_T * tm);
long  vim_regexec_multi (regmmatch_T * rmp, win_T * win, buf_T * buf, linenr_T lnum, colnr_T col, proftime_T * tm, int * timed_out);
static int next_search_hl_pos (match_T * shl, linenr_T lnum, posmatch_T * posmatch, colnr_T mincol);
static int win_line (win_T * wp, linenr_T lnum, int startrow, int endrow, int nochange);
int syntax_present (win_T * win);
void syntax_start (win_T * wp, linenr_T lnum);
static void syn_stack_alloc (void);
static int syn_stack_cleanup (void);
static void syn_stack_free_entry (synblock_T * block, synstate_T * p);
static int syn_finish_line (int syncing);
static int syn_current_attr (int syncing, int displaying, int * can_spell, int keep_state);
static char_u *syn_getcurline (void);
static stateitem_T *push_next_match (stateitem_T *cur_si);
static int push_current_state (int idx);
reg_extmatch_T *ref_extmatch (reg_extmatch_T *em);
static void update_si_end (stateitem_T * sip, int startcol, int force);
static void find_endpos (int idx, lpos_T * startpos, lpos_T * m_endpos, lpos_T * hl_endpos, long * flagsp, lpos_T * end_endpos, int * end_idx, reg_extmatch_T * start_ext);
static void save_chartab (char_u * chartab);
static int syn_regexec (regmmatch_T * rmp, linenr_T lnum, colnr_T col, syn_time_T * st);
static void syn_add_end_off (lpos_T * result, regmmatch_T * regmatch, synpat_T * spp, int idx, int extra);
static void limit_pos (lpos_T * pos, lpos_T * limit);
static void restore_chartab (char_u * chartab);
static void check_keepend (void);
static void limit_pos_zero (lpos_T * pos, lpos_T * limit);
static void update_si_attr (int idx);
int vim_iswordp_buf (char_u * p, buf_T * buf);
static int check_keyword_id (char_u * line, int startcol, int * endcolp, long * flagsp, short * * next_listp, stateitem_T * cur_si, int * ccharp);
char_u *str_foldcase (char_u *str, int orglen, char_u *buf, int buflen);
static int in_id_list (stateitem_T * cur_si, short * list, struct sp_syn * ssp, int contained);
static void syn_add_start_off (lpos_T * result, regmmatch_T * regmatch, synpat_T * spp, int idx, int extra);
static int did_match_already (int idx, garray_T * gap);
static void check_state_ends (void);
static void pop_current_state (void);
static void syn_update_ends (int startofline);
static synstate_T *store_current_state (void);
static synstate_T *syn_stack_find_entry (linenr_T lnum);
static void load_current_state (synstate_T * from);
static void validate_current_state (void);
static void syn_sync (win_T * wp, linenr_T start_lnum, synstate_T * last_valid);
pos_T *find_start_comment (int ind_maxcomment);
pos_T *findmatchlimit (oparg_T *oap, int initc, int flags, int maxtravel);
void find_mps_values (int * initc, int * findc, int * backwards, int switchit);
static int check_prevcol (char_u * linep, int col, int ch, int * prevcol);
static int check_linecomment (char_u * line);
static int find_rawstring_end (char_u * linep, pos_T * startpos, pos_T * endpos);
static char_u *skip_string (char_u *p);
static int syn_match_linecont (linenr_T lnum);
static void syn_start_line (void);
static int syn_stack_equal (synstate_T * sp);
static int advance_color_col (int vcol, int * * color_cols);
int term_show_buffer (buf_T * buf);
int term_get_attr (buf_T * buf, linenr_T lnum, int col);
static int cell2attr (VTermScreenCellAttrs cellattrs, VTermColor cellfg, VTermColor cellbg);
guicolor_T gui_mch_get_rgb_color (int r, int g, int b);
guicolor_T gui_get_rgb_color_cmn (int r, int g, int b);
int get_gui_attr_idx (int attr, guicolor_T fg, guicolor_T bg);
int get_tgc_attr_idx (int attr, guicolor_T fg, guicolor_T bg);
static int color2index (VTermColor * color, int fg, int * boldp);
int lookup_color (int idx, int foreground, int * boldp);
int get_cterm_attr_idx (int attr, int fg, int bg);
void spell_cat_line (char_u * buf, char_u * line, int maxlen);
int gchar_pos (pos_T * pos);
int diff_find_change (win_T * wp, linenr_T lnum, int * startp, int * endp);
static int diff_check_sanity (tabpage_T * tp, diff_T * dp);
static int diff_equal_char (char_u * p1, char_u * p2, int * len);
int buf_getsigntype (buf_T * buf, linenr_T lnum, int type);
char_u *sign_get_text (int typenr);
int sign_get_attr (int typenr, int line);
linenr_T qf_current_entry (win_T * wp);
int getwhitecols (char_u * p);
int spell_move_to (win_T * wp, int dir, int allwords, int curline, hlf_T * attrp);
static int no_spell_checking (win_T * wp);
static int check_need_cap (linenr_T lnum, colnr_T col);
char_u *ml_get_curline (void);
int syn_get_id (win_T * wp, long lnum, colnr_T col, int trans, int * spellp, int keep_state);
int get_syntax_attr (colnr_T col, int * can_spell, int keep_state);
char_u *spell_to_word_end (char_u *start, win_T *win);
static int compute_foldcolumn (win_T * wp, int col);
static void fill_foldcolumn (char_u * p, win_T * wp, int closed, linenr_T lnum);
linenr_T get_cursor_rel_lnum (win_T * wp, linenr_T lnum);
void rl_mirror (char_u * str);
int hl_combine_attr (int char_attr, int prim_attr);
void screen_line (int row, int coloff, int endcol, int clear_width, int rlflag);
static int char_needs_redraw (int off_from, int off_to, int cols);
static int fillchar_vsep (int * attr);
int get_syntax_info (int * seqnrp);
int conceal_cursor_line (win_T * wp);
int syn_get_sub_char (void);
static void win_draw_end (win_T * wp, int c1, int c2, int row, int endrow, hlf_T hl);
static void draw_vsep_win (win_T * wp, int row);
static void end_search_hl (void);
static void update_finish (void);
void gui_may_resize_shell (void);
win_T *winframe_remove (win_T *win, int *dirp, tabpage_T *tp);
static frame_T *win_altframe (win_T *win, tabpage_T *tp);
static tabpage_T *alt_tabpage (void);
static win_T *frame2win (frame_T *frp);
static void frame_remove (frame_T * frp);
int valid_tabpage_win (tabpage_T * tpc);
void close_tabpage (tabpage_T * tab);
void free_tabpage (tabpage_T * tp);
void restore_snapshot (int idx, int close_curwin);
static int check_snapshot_rec (frame_T * sn, frame_T * fr);
static win_T *restore_snapshot_rec (frame_T *sn, frame_T *fr);
int isNetbeansModified (buf_T * bufp);
void netbeans_save_buffer (buf_T * bufp);
void filemess (buf_T * buf, char_u * name, char_u * s, int attr);
void msg_add_fname (buf_T * buf, char_u * fname);
char_u *msg_may_trunc (int force, char_u *s);
int mch_nodetype (char_u * name);
static int check_mtime (buf_T * buf, stat_T * st);
int ask_yesno (char_u * str, int direct);
int smsg_attr (int attr, char_u * s,...);
int plain_vgetc (void);
int bracketed_paste (paste_mode_T mode, int drop, garray_T * gap);
int put_on_cmdline (char_u * str, int len, int redraw);
static int realloc_cmdbuff (int len);
static void alloc_cmdbuff (int len);
static void cursorcmd (void);
static void draw_cmdline (int start, int len);
int msg_outtrans_len (char_u * str, int len);
static int cmdline_charsize (int idx);
void msg_check (void);
int stop_arrow (void);
int u_save_cursor (void);
int u_save (linenr_T top, linenr_T bot);
void u_saveline (linenr_T lnum);
void u_clearline (void);
static char_u *u_save_line (linenr_T lnum);
int u_savecommon (linenr_T top, linenr_T bot, linenr_T newbot, int reload);
int undo_allowed (void);
int netbeans_is_guarded (linenr_T top, linenr_T bot);
void term_change_in_curbuf (void);
int getviscol (void);
void foldOpenCursor (void);
static linenr_T setManualFold (linenr_T lnum, int opening, int recurse, int * donep);
linenr_T diff_lnum_win (linenr_T lnum, win_T * wp);
static linenr_T setManualFoldWin (win_T * wp, linenr_T lnum, int opening, int recurse, int * donep);
static void foldOpenNested (fold_T * fpr);
static int ins_eol (int c);
static int echeck_abbr (int c);
int check_abbr (int c, char_u * ptr, int col, int mincol);
int vim_iswordp (char_u * p);
int vim_iswordc (int c);
char_u *vim_strbyte (char_u *string, int c);
void vim_unescape_csi (char_u * p);
static char_u *eval_map_expr (char_u *str, int c);
char_u *save_cmdline_alloc (void);
static void save_cmdline (struct cmdline_info * ccp);
void set_vim_var_char (int c);
void restore_cmdline_alloc (char_u * p);
static void restore_cmdline (struct cmdline_info * ccp);
char_u *vim_strsave_escape_csi (char_u *p);
static void undisplay_dollar (void);
void redrawWinline (linenr_T lnum, int invalid);
int find_wl_entry (win_T * win, linenr_T lnum);
void replace_push (int c);
int fkmap (int c);
static void chg_c_toX_orX (void);
int inc_cursor (void);
int inc (pos_T * lp);
static int F_is_TyB_TyC_TyD (int src, int offset);
int cmd_gchar (int offset);
static void put_and_redo (int c);
void pchar_cursor (int c);
static void chg_l_toXor_X (void);
static void chg_r_to_Xor_X_ (void);
static int toF_Xor_X_ (int c);
static void put_curr_and_l_to_X (int c);
static int F_is_TyC_TyD (int c);
static int toF_TyB (int c);
static int toF_TyA (int c);
static void chg_c_to_X_or_X (void);
int del_char (int fixpos);
int del_bytes (long count, int fixpos_arg, int use_delcombine);
int ml_line_alloced (void);
void changed_bytes (linenr_T lnum, colnr_T col);
static void changedOneline (buf_T * buf, linenr_T lnum);
static void changed_common (linenr_T lnum, colnr_T col, linenr_T lnume, long xtra);
int comp_textwidth (int ff);
void changed_cline_bef_curs_win (win_T * wp);
void approximate_botline_win (win_T * wp);
void set_topline (win_T * wp, linenr_T lnum);
static int F_is_TyE (int c);
static void chg_c_to_X_orX_ (void);
static void chg_l_to_X_orX_ (void);
int open_line (int dir, int flags, int second_line_indent);
int get_leader_len (char_u * line, char_u * * flags, int backward, int include_space);
int get_indent (void);
pos_T *findmatch (oparg_T *oap, int initc);
static int cin_is_cinword (char_u * line);
int ml_append (linenr_T lnum, char_u * line, colnr_T len, int newfile);
static int ml_append_int (buf_T * buf, linenr_T lnum, char_u * line, colnr_T len, int newfile, int mark);
static bhdr_T *ml_new_data (memfile_T *mfp, int negative, int page_count);
static void ml_lineadd (buf_T * buf, int count);
static bhdr_T *ml_new_ptr (memfile_T *mfp);
static void ml_updatechunk (buf_T * buf, linenr_T line, long len, int updtype);
void netbeans_inserted (buf_T * bufp, linenr_T linenr, colnr_T col, char_u * txt, int newlen);
static long  pos2off (buf_T * buf, pos_T * pos);
long  ml_find_line_or_offset (buf_T * buf, linenr_T lnum, long * offp);
static char_u *nb_quote (char_u *txt);
void mark_adjust (linenr_T line1, linenr_T line2, long amount, long amount_after);
static void mark_adjust_internal (linenr_T line1, linenr_T line2, long amount, long amount_after, int adjust_folds);
void qf_mark_adjust (win_T * wp, linenr_T line1, linenr_T line2, long amount, long amount_after);
void sign_mark_adjust (linenr_T line1, linenr_T line2, long amount, long amount_after);
void foldMarkAdjust (win_T * wp, linenr_T line1, linenr_T line2, long amount, long amount_after);
static void foldMarkAdjustRecurse (garray_T * gap, linenr_T line1, linenr_T line2, long amount, long amount_after);
static void deleteFoldEntry (garray_T * gap, int idx, int recursive);
void diff_mark_adjust (linenr_T line1, linenr_T line2, long amount, long amount_after);
static void diff_mark_adjust_tp (tabpage_T * tp, int idx, linenr_T line1, linenr_T line2, long amount, long amount_after);
static diff_T *diff_alloc_new (tabpage_T *tp, diff_T *dprev, diff_T *dp);
static void diff_check_unchanged (tabpage_T * tp, diff_T * dp);
static int diff_cmp (char_u * s1, char_u * s2);
static int copy_indent (int size, char_u * src);
int set_indent (int size, int flags);
int u_savesub (linenr_T lnum);
void truncate_spaces (char_u * line);
static void replace_join (int off);
void changed_lines (linenr_T lnum, colnr_T col, linenr_T lnume, long xtra);
static void changed_lines_buf (buf_T * buf, linenr_T lnum, linenr_T lnume, long xtra);
void mark_col_adjust (linenr_T lnum, colnr_T mincol, long lnum_amount, long col_amount);
void fixthisline (int (* get_the_indent) (void));
void change_indent (int type, int amount, int round, int replaced, int call_changed_bytes);
colnr_T getvcol_nolist (pos_T * posp);
void beginline (int flags);
void shift_line (int left, int round, int amount, int call_changed_bytes);
void ins_str (char_u * s);
int coladvance_force (colnr_T wcol);
char_u *alloc_check (unsigned  size);
void backspace_until_column (int col);
static void replace_do_bs (int limit_col);
static int replace_pop (void);
static int del_char_after_col (int limit_col);
static void replace_pop_ins (void);
void ins_bytes_len (char_u * p, int len);
void ins_char_bytes (char_u * buf, int charlen);
static int linelen (int * has_tab);
void showmatch (int c);
void gui_update_cursor_later (void);
void conceal_check_cursur_line (void);
void showruler (int always);
static void redraw_custom_statusline (win_T * wp);
void ins_char (int c);
void ins_bytes (char_u * p);
int linewhite (linenr_T lnum);
int get_lisp_indent (void);
static int lisp_match (char_u * p);
int getwhitecols_curline ();
int in_cinkeys (int keytyped, int when, int line_is_empty);
int cin_iscase (char_u * s, int strict);
static char_u *cin_skipcomment (char_u *s);
static int cin_starts_with (char_u * s, char * word);
static int cin_isdefault (char_u * s);
int cin_isscopedecl (char_u * s);
int cin_islabel (void);
static int cin_islabel_skip (char_u * * s);
static pos_T *ind_find_start_CORS (linenr_T *is_raw);
static pos_T *find_start_rawstring (int ind_maxcomment);
static int cin_ispreproc (char_u * s);
static int cin_isterminated (char_u * s, int incl_open, int incl_comma);
static int cin_iselse (char_u * p);
static int cin_nocode (char_u * s);
void do_c_expr_indent (void);
int get_expr_indent (void);
varnumber_T eval_to_number (char_u * expr);
int get_c_indent (void);
static pos_T *ind_find_start_comment (void);
static int cin_islinecomment (char_u * p);
static pos_T *find_line_comment (void);
static int cin_iscomment (char_u * p);
int get_indent_lnum (linenr_T lnum);
static pos_T *find_match_char (int c, int ind_maxparen);
static int cin_skip2pos (pos_T * trypos);
static pos_T *find_match_paren (int ind_maxparen);
static pos_T *find_start_brace (void);
static int cin_ispreproc_cont (char_u * * pp, linenr_T * lnump, int * amount);
static int corr_ind_maxparen (pos_T * startpos);
static int cin_is_if_for_while_before_offset (char_u * line, int * poffset);
static int skip_label (linenr_T lnum, char_u * * pp);
static int get_indent_nolabel (linenr_T lnum);
static char_u *after_label (char_u *l);
static int cin_ends_in (char_u * s, char_u * find, char_u * ignore);
static pos_T *find_match_paren_after_brace (int ind_maxparen);
static int find_last_paren (char_u * l, int start, int end);
static int cin_has_js_key (char_u * text);
static int cin_iswhileofdo (char_u * p, linenr_T lnum);
static int find_match (int lookfor, linenr_T ourscope);
static int cin_isif (char_u * p);
static int cin_isdo (char_u * p);
static int cin_is_cpp_namespace (char_u * s);
static int cin_is_cpp_extern_c (char_u * s);
static int cin_isbreak (char_u * p);
static int cin_isfuncdecl (char_u * * sp, linenr_T first_lnum, linenr_T min_lnum);
static int cin_isinit (void);
static int cin_is_cpp_baseclass (cpp_baseclass_cache_T * cached);
static int get_baseclass_amount (int col);
static int cin_first_id_amount (void);
static int cin_get_equal_amount (linenr_T lnum);
static int cin_iswhileofdo_end (int terminated);
int has_format_option (int x);
int match_file_list (char_u * list, char_u * sfname, char_u * ffname);
static int buf_write_bytes (struct bw_info * ip);
int enc2macroman (char_u * from, size_t fromlen, char_u * to, int * tolenp, int maxtolen, char_u * rest, int * restlenp);
int crypt_works_inplace (cryptstate_T * state);
void crypt_encode_inplace (cryptstate_T * state, char_u * buf, size_t len);
long  crypt_encode_alloc (cryptstate_T * state, char_u * from, size_t len, char_u * * newptr);
static void set_file_time (char_u * fname, time_t atime, time_t mtime);
char_u *enc_canonize (char_u *enc);
char_u *enc_skip (char_u *p);
static int enc_alias_search (char_u * name);
cryptstate_T *crypt_create_for_writing (int method_nr, char_u *key, char_u **header, int *header_len);
int get_fileformat_force (buf_T * buf, exarg_T * eap);
static void msg_add_eol (void);
static int msg_add_fileformat (int eol_type);
void crypt_append_msg (buf_T * buf);
void msg_add_lines (int insert_space, long lnum, off_T nchars);
char_u *msg_trunc_attr (char_u *s, int force, int attr);
void u_write_undo (char_u * name, int forceit, buf_T * buf, char_u * hash);
static int serialize_header (bufinfo_T * bi, char_u * hash);
static int undo_write_bytes (bufinfo_T * bi, long_u nr, int len);
static int undo_write (bufinfo_T * bi, char_u * ptr, size_t len);
static int undo_flush (bufinfo_T * bi);
static int fwrite_crypt (bufinfo_T * bi, char_u * ptr, size_t len);
static void put_header_ptr (bufinfo_T * bi, u_header_T * uhp);
void time_to_bytes (time_T the_time, char_u * buf);
static int serialize_uhp (bufinfo_T * bi, u_header_T * uhp);
static void serialize_pos (bufinfo_T * bi, pos_T pos);
static void serialize_visualinfo (bufinfo_T * bi, visualinfo_T * info);
static int serialize_uep (bufinfo_T * bi, u_entry_T * uep);
int should_abort (int retcode);
void dialog_changed (buf_T * buf, int checkall);
int vim_dialog_save_all_changes (buf);
void dialog_msg (char_u * buff, char * format, char_u * fname);
int vim_dialog_save_changes (buf);
int vim_dialog_yesnoallcancel (int type, char_u * title, char_u * message, int dflt);
int vim_dialog_yesnocancel (int type, char_u * title, char_u * message, int dflt);
int check_overwrite (exarg_T * eap, buf_T * buf, char_u * fname, char_u * ffname, int other);
int vim_fexists (char_u * fname);
int vim_dialog_yesno (int type, char_u * title, char_u * message, int dflt);
void no_write_message (void);
void no_write_message_nobang (void);
int win_split (int size, int flags);
int may_open_tabpage (void);
int win_new_tabpage (int after);
static tabpage_T *alloc_tabpage (void);
static int win_alloc_firstwin (win_T * oldwin);
void curwin_init (void);
void win_init_size (void);
void alist_new (void);
void alist_init (alist_T * al);
void alist_set (alist_T * al, int count, char_u * * files, int use_curbuf, int * fnum_list, int fnum_len);
void buf_set_name (int fnum, char_u * name);
void do_argfile (exarg_T * eap, int argn);
int otherfile (char_u * ffname);
int do_ecmd (int fnum, char_u * ffname, char_u * sfname, exarg_T * eap, linenr_T newlnum, int flags, win_T * oldwin);
buf_T *setaltfname (char_u *ffname, char_u *sfname, linenr_T lnum);
void buflist_altfpos (win_T * win);
pos_T *buflist_findfpos (buf_T *buf);
static wininfo_T *find_wininfo (buf_T *buf, int skip_diff_buffer);
static int wininfo_other_tab_diff (wininfo_T * wip);
static void delbuf_msg (char_u * name);
void set_file_options (int set_options, exarg_T * eap);
int default_fileformat (void);
void get_winopts (buf_T * buf);
int check_fname (void);
static void prepare_help_buffer (void);
void set_buflisted (int on);
void enter_cleanup (cleanup_T * csp);
void report_make_pending (int pending, void * value);
static void report_pending (int action, int pending, void * value);
char_u *get_return_cmd (void *rettv);
void enter_buffer (buf_T * buf);
int inindent (int extra);
void buflist_getfpos (void);
void scroll_cursor_halfway (int atend);
int plines_nofill (linenr_T lnum);
static void botline_forw (lineoff_T * lp);
void netbeans_file_activated (buf_T * bufp);
char_u *keymap_init (void);
static void keymap_unload (void);
int do_map (int maptype, char_u * arg, int mode, int abbrev);
char_u *replace_termcodes (char_u *from, char_u **bufp, int from_part, int do_lt, int special);
int find_term_bykeys (char_u * src);
char_u *get_var_value (char_u *name);
dictitem_T *find_var (char_u *name, hashtab_T **htp, int no_autoload);
dictitem_T *find_var_in_scoped_ht (char_u *name, int no_autoload);
char_u *lrswap (char_u *ibuf);
static void lrswapbuf (char_u * buf, int len);
static void showmap (mapblock_T * mp, int local);
char_u *map_mode_to_chars (int mode);
int msg_outtrans_special (char_u * strstart, int from);
void leave_cleanup (cleanup_T * csp);
void report_discard_pending (int pending, void * value);
void free_global_msglist (void);
void report_resume_pending (int pending, void * value);
void ml_recover (void);
int recover_names (char_u * fname, int list, int nr, char_u * * fname_out);
static int recov_file_names (char_u * * names, char_u * path, int prepend_dot);
int expand_wildcards (int num_pat, char_u * * pat, int * num_files, char_u * * * files, int flags);
int match_suffix (char_u * fname);
int get_number (int colon, int * mouse_used);
void stuffcharReadbuff (int c);
void crypt_set_cm_option (buf_T * buf, int method_nr);
void mf_new_page_size (memfile_T * mfp, unsigned new_size);
int ml_delete (linenr_T lnum, int message);
static int ml_delete_int (buf_T * buf, linenr_T lnum, int message);
void netbeans_removed (buf_T * bufp, linenr_T linenr, colnr_T col, long len);
void mf_free (memfile_T * mfp, bhdr_T * hp);
static void mf_ins_free (memfile_T * mfp, bhdr_T * hp);
char_u *crypt_get_key (int store, int twice);
char_u *getcmdline_prompt (int firstc, char_u *prompt, int attr, int xp_context, char_u *xp_arg);
char_u *getcmdline (int firstc, long  count, int indent);
void sb_text_start_cmdline (void);
void msg_sb_eol (void);
void ExpandInit (expand_T *xp);
static void redrawcmdprompt (void);
static void set_cmdspos (void);
static void trigger_cmd_autocmd (int typechar, int evt);
int do_digraph (int c);
int getdigraph (int char1, int char2, int meta_char);
static int getexactdigraph (int char1, int char2, int meta_char);
void redrawcmd (void);
static void set_cmdspos_cursor (void);
void putcmdline (int c, int shift);
int hkmap (int c);
int cmdl_fkmap (int c);
void cmd_pchar (int c, int offset);
void redrawcmdline (void);
void redrawcmdline_ex (int do_compute_cmdrow);
char_u *ExpandOne (expand_T *xp, char_u *str, char_u *orig, int options, int mode);
void win_redr_status_matches (expand_T * xp, int num_matches, char_u * * matches, int match, int showtail);
static int status_match_len (expand_T * xp, char_u * s);
static int skip_status_match_char (expand_T * xp, char_u * s);
void win_redraw_last_status (frame_T * frp);
static int ExpandFromContext (expand_T * xp, char_u * pat, int * num_file, char_u * * * file, int options);
int expand_wildcards_eval (char_u * * pat, int * num_file, char_u * * * file, int flags);
char_u *eval_vars (char_u *src, char_u *srcstart, int *usedlen, linenr_T *lnump, char_u **errormsg, int *escaped);
int find_ident_under_cursor (char_u * * string, int find_type);
int find_ident_at_pos (win_T * wp, linenr_T lnum, colnr_T startcol, char_u * * string, int find_type);
static int find_is_eval_item (char_u * ptr, int * colp, int * bnp, int dir);
static char_u *arg_all (void);
char_u *list_find_str (list_T *l, long  idx);
listitem_T *list_find (list_T *l, long  n);
list_T *get_vim_var_list (int idx);
char_u *file_name_at_cursor (int options, long  count, linenr_T *file_lnum);
char_u *file_name_in_line (char_u *line, int col, int options, long  count, char_u *rel_fname, linenr_T *file_lnum);
int vim_isfilec (int c);
char_u *find_file_name_in_path (char_u *ptr, int len, int options, long  count, char_u *rel_fname);
static char_u *eval_includeexpr (char_u *ptr, int len);
char_u *find_file_in_path (char_u *ptr, int len, int options, int first, char_u *rel_fname);
char_u *find_file_in_path_option (char_u *ptr, int len, int options, int first, char_u *path_option, int find_what, char_u *rel_fname, char_u *suffixes);
void vim_findfile_free_visited (void * search_ctx_arg);
static void vim_findfile_free_visited_list (ff_visited_list_hdr_T * * list_headp);
static void ff_free_visited_list (ff_visited_T * vl);
char_u *vim_findfile (void *search_ctx_arg);
static ff_stack_T *ff_pop (ff_search_ctx_T *search_ctx);
static int ff_check_visited (ff_visited_T * * visited_list, char_u * fname, char_u * wc_path);
static int ff_wc_equal (char_u * s1, char_u * s2);
void verbose_enter_scroll (void);
void verbose_leave_scroll (void);
static void ff_free_stack_element (ff_stack_T * stack_ptr);
static void ff_push (ff_search_ctx_T * search_ctx, ff_stack_T * stack_ptr);
void simplify_filename (char_u * filename);
char_u *getnextcomp (char_u *fname);
static ff_stack_T *ff_create_stack_element (char_u *fix_part, char_u *wc_part, int level, int star_star_empty);
static int ff_path_in_stoplist (char_u * path, int path_len, char_u * * stopdirs_v);
void vim_findfile_cleanup (void * ctx);
static void ff_clear (ff_search_ctx_T * search_ctx);
char_u *vim_findfile_stopdir (char_u *buf);
void *vim_findfile_init (char_u *path, char_u *filename, char_u *stopdirs, int level, int free_visited, int find_what, void *search_ctx_arg, int tagfile, char_u *rel_fname);
static ff_visited_list_hdr_T *ff_get_visited_list (char_u *filename, ff_visited_list_hdr_T **list_headp);
int find_help_tags (char_u * arg, int * num_matches, char_u * * * matches, int keep_lang);
int find_tags (char_u * pat, int * num_matches, char_u * * * matchesp, int flags, int mincount, char_u * buf_ffname);
static void prepare_pats (pat_T * pats, int has_re);
int get_tagfname (tagname_T * tnp, int first, char_u * buf);
static void found_tagfile_cb (char_u * fname, void * cookie);
void ins_compl_check_keys (int frequency, int in_compl_func);
int using_script (void);
int vpeekc_any (void);
int vim_is_ctrl_x_key (int c);
static int ins_compl_pum_key (int c);
static int ins_compl_key2dir (int c);
static int ins_compl_next (int allow_get_expansion, int count, int insert_match, int in_compl_func);
static int ins_compl_equal (compl_T * match, char_u * str, int len);
static void ins_compl_delete (void);
void set_vim_var_dict (int idx, dict_T * val);
void dict_set_items_ro (dict_T * di);
dict_T *dict_alloc_lock (int lock);
static int ins_compl_get_exp (pos_T * ini);
static buf_T *ins_compl_next_buf (buf_T *buf, int flag);
void find_pattern_in_path (char_u * ptr, int dir, int len, int whole, int skip_comments, int type, long count, int action, linenr_T start_lnum, linenr_T end_lnum);
void msg_home_replace_hl (char_u * fname);
char_u *find_word_start (char_u *ptr);
char_u *find_word_end (char_u *ptr);
int ins_compl_add_infercase (char_u * str, int len, int icase, char_u * fname, int dir, int flags);
static int ins_compl_add (char_u * str, int len, int icase, char_u * fname, char_u * * cptext, int cdir, int flags, int adup);
static void ins_compl_del_pum (void);
void pum_undisplay (void);
static void ins_compl_longest_match (compl_T * match);
static int ins_compl_len (void);
static void ins_redraw (int ready);
int has_cursormovedI (void);
int has_textchangedI (void);
int has_textchangedP (void);
static void show_pat_in_path (char_u * line, int type, int did_show, int action, FILE * fp, linenr_T * lnum, long count);
void msg_prt_line (char_u * s, int list);
int prepare_tagpreview (int undo_sync);
int getfile (int fnum, char_u * ffname, char_u * sfname, int setpm, linenr_T lnum, int forceit);
static void ins_compl_dictionaries (char_u * dict_start, char_u * pat, int flags, int thesaurus);
void spell_dump_compl (char_u * pat, int ic, int * dir, int dumpflags_arg);
static void dump_word (slang_T * slang, char_u * word, char_u * pat, int * dir, int dumpflags, int wordflags, linenr_T lnum);
static void make_case_word (char_u * fword, char_u * cword, int flags);
static void allcap_copy (char_u * word, char_u * wcopy);
void onecap_copy (char_u * word, char_u * wcopy, int upper);
static linenr_T dump_prefixes (slang_T * slang, char_u * word, char_u * pat, int * dir, int dumpflags, int flags, linenr_T startlnum);
static void ins_compl_files (int count, char_u * * files, int thesaurus, int flags, regmatch_T * regmatch, char_u * buf, int * dir);
static char_u *find_line_end (char_u *ptr);
static void ins_compl_add_matches (int num_matches, char_u * * matches, int icase);
void tilde_replace (char_u * orig_pat, int num_files, char_u * * files);
int expand_cmdline (expand_T * xp, char_u * str, int col, int * matchcount, char_u * * * matches);
char_u *addstar (char_u *fname, int len, int context);
int expand_spelling (linenr_T lnum, char_u * pat, char_u * * * matchp);
void spell_suggest_list (garray_T * gap, char_u * word, int maxcount, int need_cap, int interactive);
static void spell_find_suggest (char_u * badptr, int badlen, suginfo_T * su, int maxcount, int banbadword, int need_cap, int interactive);
static int badword_captype (char_u * word, char_u * end);
void spell_soundfold (slang_T * slang, char_u * inword, int folded, char_u * res);
static void spell_soundfold_sofo (slang_T * slang, char_u * inword, char_u * res);
static void spell_soundfold_sal (slang_T * slang, char_u * inword, char_u * res);
static void add_suggestion (suginfo_T * su, garray_T * gap, char_u * goodword, int badlenarg, int score, int altscore, int had_bonus, slang_T * slang, int maxsf);
static void rescore_one (suginfo_T * su, suggest_T * stp);
static int stp_sal_score (suggest_T * stp, suginfo_T * su, slang_T * slang, char_u * badsound);
static int soundalike_score (char_u * goodstart, char_u * badstart);
static int cleanup_suggestions (garray_T * gap, int maxscore, int keep);
static int sug_compare (const void * s1, const void * s2);
static void add_banned (suginfo_T * su, char_u * word);
static void spell_suggest_expr (suginfo_T * su, char_u * expr);
list_T *eval_spell_expr (char_u *badword, char_u *expr);
static void prepare_vimvar (int idx, typval_T * save_tv);
static void restore_vimvar (int idx, typval_T * save_tv);
int get_spellword (list_T * list, char_u * * pp);
static void check_suggestions (suginfo_T * su, garray_T * gap);
static void spell_suggest_file (suginfo_T * su, char_u * fname);
static void spell_suggest_intern (suginfo_T * su, int interactive);
void suggest_load_files (void);
buf_T *open_spellbuf (void);
int ml_append_buf (buf_T * buf, linenr_T lnum, char_u * line, colnr_T len, int newfile);
static void tree_count_words (char_u * byts, idx_T * idxs);
static void suggest_try_special (suginfo_T * su);
static void suggest_try_change (suginfo_T * su);
static void suggest_trie_walk (suginfo_T * su, langp_T * lp, char_u * fword, int soundfold);
static void go_deeper (trystate_T * stack, int depth, int score_add);
static int score_wordcount_adj (slang_T * slang, int score, char_u * word, int split);
static int match_checkcompoundpattern (char_u * ptr, int wlen, garray_T * gap);
static int can_compound (slang_T * slang, char_u * word, char_u * flags);
static int count_syllables (slang_T * slang, char_u * word);
static void find_keepcap_word (slang_T * slang, char_u * fword, char_u * kword);
static void add_sound_suggest (suginfo_T * su, char_u * goodword, int score, langp_T * lp);
static int soundfold_find (slang_T * slang, char_u * word);
static int bytes2offset (char_u * * pp);
static int spell_edit_score (slang_T * slang, char_u * badword, char_u * goodword);
static int similar_chars (slang_T * slang, int c1, int c2);
static int spell_edit_score_limit (slang_T * slang, char_u * badword, char_u * goodword, int limit);
static int can_be_compound (trystate_T * sp, slang_T * slang, char_u * compflags, int flag);
static int match_compoundrule (slang_T * slang, char_u * compflags);
static void score_comp_sal (suginfo_T * su);
static void rescore_suggestions (suginfo_T * su);
static void suggest_try_soundalike_prep (void);
static void suggest_try_soundalike (suginfo_T * su);
static void suggest_try_soundalike_finish (void);
static void score_combine (suginfo_T * su);
static void spell_find_cleanup (suginfo_T * su);
int search_for_exact_line (buf_T * buf, pos_T * pos, int dir, char_u * pat);
int searchit (win_T * win, buf_T * buf, pos_T * pos, int dir, char_u * pat, long count, int options, int pat_use, linenr_T stop_lnum, proftime_T * tm, int * timed_out);
static int first_submatch (regmmatch_T * rp);
static int ins_compl_make_cyclic (void);
static void ins_compl_insert (int in_compl_func);
int dict_add_nr_str (dict_T * d, char * key, varnumber_T nr, char_u * str);
dictitem_T *dictitem_alloc (char_u *key);
static void ins_compl_upd_pum (void);
void ins_compl_show_pum (void);
static int pum_wanted (void);
static int pum_enough_matches (void);
void pum_display (pumitem_T * array, int size, int selected);
void validate_cursor_col (void);
int curwin_col_off2 (void);
static void pum_compute_size (void);
static int pum_set_selected (int n, int repeat);
void pum_redraw (void);
void screen_putchar (int c, int row, int col, int attr);
static int ins_compl_key2count (int c);
int pum_get_height (void);
void vungetc (int c);
int vim_isblankline (char_u * lbuf);
static char_u *expand_tag_fname (char_u *fname, char_u *tag_fname, int expand);
int mch_has_wildcard (char_u * p);
static int tag_strnicmp (char_u * s1, char_u * s2, size_t len);
static int parse_tag_line (char_u * lbuf, int is_etag, tagptrs_T * tagp);
static int test_for_current (int is_etag, char_u * fname, char_u * fname_end, char_u * tag_fname, char_u * buf_ffname);
static int test_for_static (tagptrs_T * tagp);
int help_heuristic (char_u * matched_string, int offset, int wrong_case);
void tagname_free (tagname_T * tnp);
static int help_compare (const void * s1, const void * s2);
static void cleanup_help_tags (int num_file, char_u * * file);
static int expand_shellcmd (char_u * filepat, int * num_file, char_u * * * file, int flagsarg);
int ExpandOldSetting (int * num_file, char_u * * * file);
int ExpandBufnames (char_u * pat, int * num_file, char_u * * * file, int options);
int expand_tags (int tagnames, char_u * pat, int * num_file, char_u * * * file);
static int parse_match (char_u * lbuf, tagptrs_T * tagp);
static int find_extra (char_u * * pp);
char_u *skip_regexp (char_u *startp, int dirc, int magic, char_u **newp);
static void get_cpo_flags (void);
static char_u *skip_anyof (char_u *p);
static int get_char_class (char_u * * pp);
static int get_equi_class (char_u * * pp);
static int get_coll_element (char_u * * pp);
static int ExpandRTDir (char_u * pat, int flags, int * num_file, char_u * * * file, char * dirnames []);
void globpath (char_u * path, char_u * file, garray_T * ga, int expand_options);
void ExpandEscape (expand_T * xp, char_u * str, int numfiles, char_u * * files, int options);
char_u *vim_strsave_fnameescape (char_u *fname, int shell);
static void escape_fname (char_u * * pp);
void sort_strings (char_u * * files, int count);
static int sort_compare (const void * s1, const void * s2);
static int ExpandUserList (expand_T * xp, int * num_file, char_u * * * file);
static void *call_user_expand_func (void * (*user_expand_func) (char_u *, int, char_u **, int), expand_T *xp, int *num_file, char_u ***file);
void *call_func_retlist (char_u *func, int argc, char_u **argv, int safe);
int call_vim_function (char_u * func, int argc, char_u * * argv, int safe, int str_arg_only, typval_T * rettv);
static int ExpandPackAddDir (char_u * pat, int * num_file, char_u * * * file);
int ExpandSettings (expand_T * xp, regmatch_T * regmatch, int * num_file, char_u * * * file);
char_u *get_termcode (int i);
char_u *get_key_name (int i);
int ExpandMappings (regmatch_T * regmatch, int * num_file, char_u * * * file);
char_u *translate_mapping (char_u *str, int expmap);
static int ExpandUserDefined (expand_T * xp, regmatch_T * regmatch, int * num_file, char_u * * * file);
void *call_func_retstr (char_u *func, int argc, char_u **argv, int safe);
char_u *get_command_name (expand_T *xp, int idx);
static char_u *get_user_command_name (int idx);
char_u *get_user_commands (expand_T *xp, int idx);
char_u *get_behave_arg (expand_T *xp, int idx);
char_u *get_mapclear_arg (expand_T *xp, int idx);
char_u *get_messages_arg (expand_T *xp, int idx);
char_u *get_user_cmd_addr_type (expand_T *xp, int idx);
char_u *get_user_cmd_flags (expand_T *xp, int idx);
char_u *get_user_cmd_nargs (expand_T *xp, int idx);
char_u *get_user_cmd_complete (expand_T *xp, int idx);
char_u *get_user_var_name (expand_T *xp, int idx);
static char_u *cat_prefix_varname (int prefix, char_u *name);
char_u *get_function_name (expand_T *xp, int idx);
char_u *get_user_func_name (expand_T *xp, int idx);
static void cat_func_name (char_u * buf, ufunc_T * fp);
char_u *get_expr_name (expand_T *xp, int idx);
char_u *get_menu_name (expand_T *xp, int idx);
static int menu_is_hidden (char_u * name);
int menu_is_popup (char_u * name);
static int menu_is_tearoff (char_u * name);
char_u *get_menu_names (expand_T *xp, int idx);
char_u *get_syntax_name (expand_T *xp, int idx);
char_u *get_syntime_arg (expand_T *xp, int idx);
char_u *get_highlight_name (expand_T *xp, int idx);
char_u *get_highlight_name_ext (expand_T *xp, int idx, int skip_cleared);
char_u *get_event_name (expand_T *xp, int idx);
char_u *get_augroup_name (expand_T *xp, int idx);
char_u *get_sign_name (expand_T *xp, int idx);
char_u *get_profile_name (expand_T *xp, int idx);
char_u *get_cmd_output (char_u *cmd, char_u *infile, int flags, int *ret_len);
char_u *make_filter_cmd (char_u *cmd, char_u *itmp, char_u *otmp);
char_u *get_isolated_shell_name (void);
char_u *get_env_name (expand_T *xp, int idx);
char_u *get_users (expand_T *xp, int idx);
static void init_users (void);
int ExpandGeneric (expand_T * xp, regmatch_T * regmatch, int * num_file, char_u * * * file, char_u * ((* func) (expand_T *, int)), int escaped);
static int sort_func_compare (const void * s1, const void * s2);
void reset_expand_highlight (void);
void ExpandCleanup (expand_T *xp);
void redraw_statuslines (void);
void win_redr_status (win_T * wp);
void get_trans_bufname (buf_T * buf);
int bt_help (buf_T * buf);
int stl_connected (win_T * wp);
static void cmdline_del (int from);
int get_expr_register (void);
char_u *get_expr_line (void);
static int ccheck_abbr (int c);
static int showmatches (expand_T * xp, int wildmenu);
static void set_expand_context (expand_T * xp);
void set_cmd_context (expand_T * xp, char_u * str, int len, int col, int use_ccline);
void set_context_for_expression (expand_T * xp, char_u * arg, cmdidx_T cmdidx);
char_u *set_one_cmd_context (expand_T *xp, char_u *buff);
char_u *skip_range (char_u *cmd, int *ctx);
static char_u *find_ucmd (exarg_T *eap, char_u *p, int *full, expand_T *xp, int *compl);
static char_u *skip_cmd_arg (char_u *p, int rembs);
int vim_isfilec_or_wc (int c);
int match_user (char_u * name);
char_u *skip_vimgrep_pat (char_u *p, char_u **s, int *flags);
void set_context_in_echohl_cmd (expand_T * xp, char_u * arg);
char_u *find_nextcmd (char_u *p);
char_u *set_context_in_autocmd (expand_T *xp, char_u *arg, int doautocmd);
void set_context_in_set_cmd (expand_T * xp, char_u * arg, int opt_flags);
void set_context_in_syntax_cmd (expand_T * xp, char_u * arg);
void set_context_in_highlight_cmd (expand_T * xp, char_u * arg);
static void highlight_list (void);
static void highlight_list_two (int cnt, int attr);
void set_context_in_sign_cmd (expand_T * xp, char_u * arg);
static int sign_cmd_idx (char_u * begin_cmd, char_u * end_cmd);
char_u *set_context_in_menu_cmd (expand_T *xp, char_u *cmd, char_u *arg, int forceit);
static int get_menu_cmd_modes (char_u * cmd, int forceit, int * noremap, int * unmenu);
char_u *set_context_in_map_cmd (expand_T *xp, char_u *cmd, char_u *arg, int forceit, int isabbrev, int isunmap, cmdidx_T cmdidx);
int get_map_mode (char_u * * cmdp, int forceit);
void set_context_in_profile_cmd (expand_T * xp, char_u * arg);
static int expand_showtail (expand_T * xp);
void msg_advance (int col);
void msg_puts_long_attr (char_u * longstr, int attr);
void msg_puts_long_len_attr (char_u * longstr, int len, int attr);
char_u *backslash_halve_save (char_u *p);
static int nextwild (expand_T * xp, int type, int options, int escape);
int map_to_exists_mode (char_u * rhs, int mode, int abbr);
void set_iminsert_global (void);
void set_imsearch_global (void);
static int cmdline_paste (int regname, int literally, int remcr);
int get_spec_reg (int regname, char_u * * argp, int * allocated, int errmsg);
char_u *getaltfname (int errmsg);
int buflist_name_nr (int fnum, char_u * * fname, linenr_T * lnum);
linenr_T buflist_findlnum (buf_T * buf);
char_u *last_search_pat (void);
char_u *get_last_insert_save (void);
void cmdline_paste_str (char_u * s, int literally);
int cmdline_paste_reg (int regname, int literally, int remcr);
int get_mouse_button (int code, int * is_click, int * is_drag);
int mouse_model_popup (void);
int gui_do_horiz_scroll (long_u leftcol, int compute_longest_lnum);
char_u *last_search_pattern (void);
void save_last_search_pattern (void);
int decl (pos_T * lp);
int incl (pos_T * lp);
static void set_search_match (pos_T * t);
void restore_last_search_pattern (void);
int get_literal (void);
int add_to_showcmd (int c);
int get_digraph (int cmdline);
int do_search (oparg_T * oap, int dirc, char_u * pat, long count, int options, proftime_T * tm, int * timed_out);
int messaging (void);
char_u *msg_strtrunc (char_u *s, int force);
void trunc_string (char_u * s, char_u * buf, int room_in, int buflen);
char_u *lrFswap (char_u *cmdbuf, int len);
static int empty_pattern (char_u * p);
void msg_starthere (void);
static void abandon_cmdline (void);
void sb_text_end_cmdline (void);
void crypt_free_key (char_u * key);
static int ml_add_stack (buf_T * buf);
int apply_autocmds_retval (event_T event, char_u * fname, char_u * fname_io, int force, buf_T * buf, int * retval);
void diff_invalidate (buf_T * buf);
void fileinfo (int fullname, int shorthelp, int dont_truncate);
static int append_arg_number (win_T * wp, char_u * buf, int buflen, int add_file);
int vim_fnamecmp (char_u * x, char_u * y);
void do_autochdir (void);
void netbeans_file_opened (buf_T * bufp);
int setmark (int c);
int setmark_pos (int c, pos_T * pos, int fnum);
void goto_byte (long cnt);
static OSErr receiveHandler (WindowRef theWindow, void * handlerRefCon, DragRef theDrag);
int_u EventModifiers2VimMouseModifiers (EventModifiers macModifiers);
win_T *mouse_find_win (int *rowp, int *colp);
pascal void gui_mac_scroll_action (ControlHandle theControl, short partCode);
void gui_mch_set_scrollbar_thumb (scrollbar_T * sb, long val, long size, long max);
static void InstallFontPanelHandler (void);
static OSStatus FontPanelHandler (EventHandlerCallRef inHandlerCallRef, EventRef inEvent, void * inUserData);
void gui_check_colors (void);
static void gui_set_bg_color (char_u * name);
guicolor_T gui_get_color (char_u * name);
guicolor_T gui_mch_get_color (char_u * name);
guicolor_T gui_get_color_cmn (char_u * name);
static int hex_digit (int c);
void hl_set_bg_color_name (char_u * name);
static void gui_set_fg_color (char_u * name);
void hl_set_fg_color_name (char_u * name);
static pascal OSStatus gui_mac_mouse_wheel (EventHandlerCallRef nextHandler, EventRef theEvent, void * data);
void gui_send_mouse_event (int button, int x, int y, int repeated_click, int_u modifiers);
int gui_xy2colrow (int x, int y, int * colp);
static void fill_mouse_coord (char_u * p, int col, int row);
static int_u EventModifiers2VimModifiers (EventModifiers macModifiers);
char_u *mac_utf16_to_enc (unsigned  short  *from, size_t fromLen, size_t *actualLen);
static char_u *mac_utf16_to_utf8 (UniChar *from, size_t fromLen, size_t *actualLen);
char_u *hl_get_font_name (void);
void gui_create_initial_menus (vimmenu_T * menu);
void gui_mch_add_menu (vimmenu_T * menu, int idx);
static Cardinal athena_calculate_ins_pos (Widget widget);
int menu_is_menubar (char_u * name);
static Pixmap gui_athena_create_pullright_pixmap (Widget w);
static char_u *make_pull_name (char_u *name);
static void gui_athena_popup_callback (Widget w, XtPointer client_data, XtPointer call_data);
void gui_mch_add_menu_item (vimmenu_T * menu, int idx);
void gui_x11_menu_cb (Widget w, XtPointer client_data, XtPointer call_data);
void gui_mch_menu_set_tip (vimmenu_T * menu);
int gui_mch_open (void);
void resettitle (void);
void init_gui_options (void);
BalloonEval *gui_mch_create_beval_area (void *target, char_u *mesg, void (*mesgCB) (BalloonEval *, int), void *clientData);
void general_beval_cb (BalloonEval * beval, int state);
int can_use_beval (void);
int get_beval_info (BalloonEval * beval, int getword, win_T * * winp, linenr_T * lnump, char_u * * textp, int * colp);
int mouse_comp_pos (win_T * win, int * rowp, int * colp, linenr_T * lnump);
void netbeans_gutter_click (linenr_T lnum);
void update_debug_sign (buf_T * buf, linenr_T lnum);
static void win_update (win_T * wp);
int term_update_window (win_T * wp);
static VTermScreen *screen_new (VTerm *vt);
static VTermState *vterm_state_new (VTerm *vt);
INTERNAL void *vterm_allocator_malloc (VTerm *vt, size_t size);
void vterm_state_newpen (VTermState * state);
VTermEncoding *vterm_lookup_encoding (VTermEncodingType type, char designation);
static ScreenCell *realloc_buffer (VTermScreen *screen, ScreenCell *buffer, int new_rows, int new_cols);
static void term_report_winsize (term_T * term, int rows, int cols);
int mch_report_winsize (int fd, int rows, int cols);
static void position_cursor (win_T * wp, VTermPos * pos);
int screen_get_current_line_off ();
static ScreenCell *getcell (const VTermScreen *screen, int row, int col);
int winbar_height (win_T * wp);
static void redraw_win_toolbar (win_T * wp);
int syn_name2attr (char_u * name);
static int text_to_screenline (win_T * wp, char_u * text, int col);
int plines_m_win (win_T * wp, linenr_T first, linenr_T last);
int win_ins_lines (win_T * wp, int row, int line_count, int invalid, int mayclear);
static int win_do_lines (win_T * wp, int row, int line_count, int mayclear, int del, int clear_attr);
void scroll_region_set (win_T * wp, int off);
void scroll_region_reset (void);
int win_del_lines (win_T * wp, int row, int line_count, int invalid, int mayclear, int clear_attr);
int syntax_check_changed (linenr_T lnum);
static void fold_line (win_T * wp, long fold_count, foldinfo_T * foldinfo, linenr_T lnum, int row);
static void copy_text_attr (int off, char_u * buf, int len, int attr);
char_u *get_foldtext (win_T *wp, linenr_T lnum, linenr_T lnume, foldinfo_T *foldinfo, char_u *buf);
void syntax_end_parsing (linenr_T lnum);
void post_balloon (BalloonEval * beval, char_u * mesg, list_T * list);
void ui_post_balloon (char_u * mesg, list_T * list);
void ui_remove_balloon (void);
int split_message (char_u * mesg, pumitem_T * * array);
void gui_mch_post_balloon (BalloonEval * beval, char_u * mesg);
static void make_tooltip (BalloonEval * beval, char * text, POINT pt);
int multiline_balloon_available (void);
void netbeans_beval_cb (BalloonEval * beval, int state);
void gui_mch_uninit (void);
void gui_x11_destroy_widgets (void);
void get_stty (void);
int get_tty_info (int fd, ttyinfo_T * info);
void do_fixdel (exarg_T * eap);
int use_xterm_like_mouse (char_u * name);
void reset_option_was_set (char_u * name);
int vim_is_fastterm (char_u * name);
int vim_is_vt300 (char_u * name);
void set_term_defaults (void);
void starttermcap (void);
void may_req_termresponse (void);
void check_map_keycodes (void);
static int check_opt_strings (char_u * val, char * * values, int list);
void init_highlight (int both, int reset);
int load_colors (char_u * name);
void do_highlight (char_u * line, int forceit, int init);
static void highlight_list_one (int id);
static int highlight_list_arg (int id, int didh, int type, int iarg, char_u * sarg, char * name);
void vim_strcat (char_u * to, char_u * from, size_t tosize);
static int syn_list_header (int did_header, int outlen, int id);
int syn_namen2id (char_u * linep, int len);
static int hl_has_settings (int idx, int check_link);
void gui_init_tooltip_font (void);
void gui_mch_def_colors (void);
void gui_mch_new_menu_font (void);
int do_unlet (char_u * name, int forceit);
dict_T *get_current_funccal_dict (hashtab_T *ht);
hashitem_T *find_hi_in_scoped_ht (char_u *name, hashtab_T **pht);
int var_check_fixed (int flags, char_u * name, int use_gettext);
int var_check_ro (int flags, char_u * name, int use_gettext);
int tv_check_lock (int lock, char_u * name, int use_gettext);
static void delete_var (hashtab_T * ht, hashitem_T * hi);
void restore_cterm_colors (void);
static void highlight_clear (int idx);
char_u *vim_strnsave_up (char_u *string, int len);
char_u *get_term_code (char_u *tname);
static void syn_unadd_group (void);
void set_terminal_default_colors (int cterm_fg, int cterm_bg);
int check_ei (void);
void init_spell_chartab (void);
static int valid_filetype (char_u * val);
void ml_set_crypt_key (buf_T * buf, char_u * old_key, char_u * old_cm);
int crypt_self_test (void);
static char_u *illegal_char (char_u *errbuf, int c);
void verbose_stop (void);
char_u *parse_printoptions (void);
static char_u *parse_list_options (char_u *option_str, option_table_T *table, int table_size);
static void langmap_set (void);
static void langmap_init (void);
char_u *check_stl_option (char_u *s);
void completeopt_was_set (void);
int diffopt_changed (void);
int redraw_asap (int type);
void maybe_intro_message (void);
void intro_message (int colon);
static void do_intro_line (int row, char_u * mesg, int add_version, int attr);
int highest_patch (void);
static void switch_to_8bit (void);
static void req_codes_from_term (void);
static void req_more_codes_from_term (void);
static void may_adjust_color_count (int val);
void set_keep_msg_from_hist (void);
int hexhex2nr (char_u * p);
static void got_code_from_term (char_u * code, int len);
static int get_bytes_from_buf (char_u * buf, char_u * bytes, int num_bytes);
int get_pseudo_mouse_code (int button, int is_click, int is_drag);
static int get_long_from_buf (char_u * buf, long_u * val);
int check_menu_pointer (vimmenu_T * root, vimmenu_T * menu_to_check);
void del_typebuf (int len, int offset);
int is_mouse_key (int c);
static int do_more_prompt (int typed_char);
static msgchunk_T *msg_sb_start (msgchunk_T *mps);
void msg_moremsg (int full);
int get_menu_index (vimmenu_T * menu, int state);
void typeahead_noflush (int c);
static msgchunk_T *disp_sb_line (int row, msgchunk_T *smp);
static void msg_puts_display (char_u * str, int maxlen, int attr, int recurse);
static void t_puts (int * t_col, char_u * t_s, char_u * s, int attr);
static void msg_scroll_up (void);
static void msg_screen_putchar (int c, int attr);
static void store_sb_text (char_u * * sb_str, char_u * s, int attr, int * sb_col, int finish);
static void inc_msg_scrolled (void);
int jump_to_mouse (int flags, int * inclusive, int which_button);
void winbar_click (win_T * wp, int col);
static void execute_menu (exarg_T * eap, vimmenu_T * menu);
int save_current_state (save_state_T * sst);
void save_typeahead (tasave_T * tp);
int alloc_typebuf (void);
void free_typebuf (void);
void exec_normal_cmd (char_u * cmd, int remap, int silent);
void exec_normal (int was_typed);
void update_topline_cursor (void);
void normal_cmd (oparg_T * oap, int toplevel);
int typebuf_maplen (void);
int readbuf1_empty (void);
static void set_vcount_ca (cmdarg_T * cap, int * set_prevcount);
void set_vcount (long count, long count1, int set_prevcount);
static void del_from_showcmd (int len);
static int find_command (int cmdchar);
static void clearopbeep (oparg_T * oap);
static void clearop (oparg_T * oap);
static void unshift_special (cmdarg_T * cap);
int get_op_type (int char1, int char2);
int goto_im (void);
void start_selection (void);
void may_start_select (int c);
static void n_start_visual_mode (int c);
void foldAdjustVisual (void);
void set_reg_var (int c);
void checkpcmark (void);
void do_check_cursorbind (void);
linenr_T diff_get_corresponding_line (buf_T * buf1, linenr_T lnum1);
static linenr_T diff_get_corresponding_line_int (buf_T * buf1, linenr_T lnum1);
int edit (int cmdchar, int startln, long count);
static void ins_compl_clear (void);
char_u *get_inserted (void);
void gui_mouse_correct (void);
static win_T *xy2win (int x, int y);
void validate_cline_row (void);
static void curs_rows (win_T * wp);
static void redraw_for_ligatures (wp);
void gui_mch_setmouse (int x, int y);
void foldCheckClose (void);
static int checkCloseRec (garray_T * gap, linenr_T lnum, int level);
static int ins_compl_bs (void);
int can_bs (int what);
static int ins_compl_need_restart (void);
static void ins_compl_restart (void);
static void ins_compl_free (void);
void pum_clear (void);
static void ins_compl_new_leader (void);
static void ins_compl_set_original_text (char_u * str);
static int ins_complete (int c, int enable_pum);
static int ins_compl_use_match (int c);
static unsigned  quote_meta (char_u * dest, char_u * src, int len);
int spell_word_start (int startcol);
void spell_expand_check_cap (colnr_T col);
static void ins_compl_fixRedoBufForLeader (char_u * ptr_arg);
static void show_pum (int prev_w_wrow, int prev_w_leftcol);
static void ins_compl_addfrommatch (void);
static void ins_compl_addleader (int c);
static int ins_compl_accept_char (int c);
static char_u *do_insert_char_pre (int c);
int has_insertcharpre (void);
static int ins_compl_prep (int c);
static void spell_back_to_badword (void);
static void start_arrow (pos_T * end_insert_pos);
static void start_arrow_common (pos_T * end_insert_pos, int end_change);
static void stop_insert (pos_T * end_insert_pos, int esc, int nomove);
void stop_redo_ins (void);
static void replace_flush (void);
void auto_format (int trailblank, int prev_line);
static void check_auto_format (int end_insert);
int paragraph_start (linenr_T lnum);
static int fmt_check_par (linenr_T lnum, int * leader_len, char_u * * leader_flags, int do_comments);
int startPS (linenr_T lnum, int para, int both);
static int inmacro (char_u * opt, char_u * s);
static int ends_in_white (linenr_T lnum);
int get_number_indent (linenr_T lnum);
static int same_leader (linenr_T lnum, int leader1_len, char_u * leader1_flags, int leader2_len, char_u * leader2_flags);
void format_lines (linenr_T line_count, int avoid_fex);
void insertchar (int c, int flags, int second_indent);
static colnr_T get_nolist_virtcol (void);
int fex_format (linenr_T lnum, long count, int c);
static void internal_format (int textwidth, int second_indent, int flags, int format_only, int c);
static int cindent_on (void);
static void redo_literal (int c);
int do_join (long count, int insert_space, int save_undo, int use_formatoptions, int setmark);
char_u *skip_comment (char_u *line, int process, int include_space, int *is_comment);
int get_last_leader_offset (char_u * line, char_u * * flags);
void del_lines (long nlines, int undo);
int u_savedel (linenr_T lnum, long nlines);
void deleted_lines_mark (linenr_T lnum, long count);
static void check_spell_redraw (void);
static void ins_ctrl_o (void);
static void ins_ctrl_v (void);
void edit_putchar (int c, int highlight);
void screen_getbytes (int row, int col, char_u * bytes, int * attrp);
void add_to_showcmd_c (int c);
void edit_unputchar (void);
static void insert_special (int c, int allow_modmask, int ctrlv);
static int ins_start_select (int c);
void stuffReadbuff (char_u * s);
static int ins_esc (long * count, int cmdchar, int nomove);
int start_redo_ins (void);
static int read_redo (int init, int old_redo);
static void copy_redo (int old_redo);
void stuffRedoReadbuff (char_u * s);
int oneleft (void);
static void ins_insert (int replaceState);
int netbeans_keycommand (int key);
static void netbeans_keyname (int key, char * buf);
static int netbeans_keystring (char_u * keyName);
static void postpone_keycommand (char_u * keystr);
int stuff_inserted (int c, long count, int no_esc);
char_u *get_last_insert (void);
static void ins_reg (void);
void do_put (int regname, int dir, long count, int flags);
int preprocs_left (void);
void msgmore (long n);
int insert_reg (int regname, int literally);
static void stuffescaped (char_u * arg, int literally);
void stuffReadbuffLen (char_u * s, long len);
static void ins_ctrl_g (void);
static void ins_up (int startcol);
int cursor_up (long n, int upd_topline);
static void ins_down (int startcol);
int cursor_down (long n, int upd_topline);
static void ins_ctrl_hat (void);
static void ins_ctrl_ (void);
static int has_compl_option (int dict_opt);
static void ins_shift (int c, int lastc);
static void ins_del (void);
static int ins_bs (int c, int mode, int * inserted_space_p);
long  get_sts_value (void);
static void ins_bs_one (colnr_T * vcolp);
static void ins_mouse (int c);
int do_mouse (oparg_T * oap, int c, int dir, long count, int fixindent);
void ui_may_remove_balloon (void);
void stuffnumReadbuff (long n);
int yank_register_mline (int regname);
void tabpage_move (int nr);
void tabpage_new (void);
void ex_splitview (exarg_T * eap);
void do_exedit (exarg_T * eap, win_T * old_curwin);
void main_loop (int cmdwin, int noexmode);
int has_cursormoved (void);
int has_textchanged (void);
void update_curbuf (int type);
void may_clear_sb_text (void);
void do_exmode (int improved);
char_u *getexline (int c, void *cookie, int indent);
char_u *getexmodeline (int promptc, void *cookie, int indent);
void print_line_no_prefix (linenr_T lnum, int use_number, int list);
int term_use_loop (void);
int terminal_loop (int blocking);
static ch_part_T get_tty_part (term_T * term);
static void may_set_cursor_props (term_T * term);
static void may_output_cursor_props (void);
static void update_cursor (term_T * term, int redraw);
static int term_vgetc ();
static void term_enter_normal_mode (void);
static void move_terminal_to_buffer (term_T * term);
static void cell2cellattr (const VTermScreenCell * cell, cellattr_T * attr);
static int equal_celattr (cellattr_T * a, cellattr_T * b);
static void add_scrollback_line_to_buffer (term_T * term, char_u * text, int len);
static void set_terminal_mode (term_T * term, int normal_mode);
int send_keys_to_term (term_T * term, int c, int typed);
static int term_convert_key (term_T * term, int c, char * buf);
static int term_send_mouse (VTerm * vterm, int button, int pressed);
static void output_mouse (VTermState * state, int code, int pressed, int modifiers, int col, int row);
INTERNAL void vterm_push_output_sprintf_ctrl (VTerm * vt, unsigned char ctrl, const char * fmt,...);
INTERNAL void vterm_push_output_sprintf (VTerm * vt, const char * format,...);
INTERNAL void vterm_push_output_vsprintf (VTerm * vt, const char * format, va_list args);
static int outbuffer_is_full (VTerm * vt);
INTERNAL void vterm_push_output_bytes (VTerm * vt, const char * bytes, size_t len);
static void term_paste_register (int prev_c);
char_u *get_reg_contents (int regname, int flags);
static char_u *getreg_wrap_one_line (char_u *s, int flags);
char_u get_reg_type (int regname, long * reglen);
static void prepare_restore_cursor_props (void);
int win_close (win_T * win, int free_buf);
static int last_window (void);
static int close_last_window_tabpage (win_T * win, int free_buf, tabpage_T * prev_curtab);
void win_close_othertab (win_T * win, int free_buf, tabpage_T * tp);
static win_T *win_free_mem (win_T *win, int *dirp, tabpage_T *tp);
int only_one_window (void);
void goto_tabpage (int n);
tabpage_T *find_tabpage (int n);
void tabpage_close (int forceit);
void close_others (int message, int forceit);
int can_abandon (buf_T * buf, int forceit);
static void ex_win_close (int forceit, win_T * win, tabpage_T * tp);
void tabpage_close_other (tabpage_T * tp, int forceit);
void gui_show_popupmenu (void);
void gui_mch_show_popupmenu (vimmenu_T * menu);
void netbeans_button_release (int button);
void openFold (linenr_T lnum, long count);
static void setFoldRepeat (linenr_T lnum, long count, int do_open);
void closeFold (linenr_T lnum, long count);
void scroll_redraw (int up, long count);
void check_visual_highlight (void);
static void find_start_of_word (pos_T * pos);
static int get_mouse_class (char_u * p);
static void find_end_of_word (pos_T * pos);
static void ins_mousescroll (int dir);
void ins_scroll (void);
void ins_horscroll (void);
static void ins_home (int c);
static void ins_end (int c);
static void ins_s_left (void);
int bck_word (long count, int bigword, int stop);
static int cls (void);
static int skip_chars (int cclass, int dir);
static void ins_left (int end_change);
static void start_arrow_with_change (pos_T * end_insert_pos, int end_change);
static void ins_s_right (void);
int fwd_word (long count, int bigword, int eol);
static void ins_right (int end_change);
int oneright (void);
static void ins_pageup (void);
int onepage (int dir, long count);
static void get_scroll_overlap (lineoff_T * lp, int dir);
static void max_topfill (void);
static void botline_topline (lineoff_T * lp);
static void topline_botline (lineoff_T * lp);
void foldAdjustCursor (void);
void scroll_cursor_top (int min_scroll, int always);
static void validate_cheight (void);
static void ins_pagedown (void);
static int ins_tab (void);
static int ins_digraph (void);
static void ins_ctrl_x (void);
static int ins_ctrl_ey (int tc);
void scrolldown_clamp (void);
void scrollup_clamp (void);
int ins_copychar (linenr_T lnum);
static void ins_try_si (int c);
void restore_current_state (save_state_T * sst);
void restore_typeahead (tasave_T * tp);
void win_drag_status_line (win_T * dragwin, int offset);
void win_drag_vsep_line (win_T * dragwin, int offset);
int swapping_screen (void);
void reset_last_sourcing (void);
void job_stop_on_exit (void);
void ruby_end (void);
void netbeans_end (void);
static void read_stdin (void);
static int read_buffer (int read_stdin, exarg_T * eap, int flags);
int GetFSSpecFromPath (char_u * file, FSSpec * fileFSSpec);
int C2PascalString (char_u * CString, Str255 * PascalString);
void check_need_swap (int newfile);
int dir_of_file_exists (char_u * fname);
static void check_marks_read (void);
int read_viminfo (char_u * file, int flags);
static char_u *check_for_cryptkey (char_u *cryptkey, char_u *ptr, long  *sizep, off_T *filesizep, int newfile, char_u *fname, int *did_ask);
void crypt_check_method (int method);
long  crypt_decode_alloc (cryptstate_T * state, char_u * ptr, long len, char_u * * newptr);
int macroman2enc (char_u * ptr, long * sizep, long real_size);
void appended_lines_mark (linenr_T lnum, long count);
void u_find_first_changed (void);
void buf_reload (buf_T * buf, int orig_mode);
static int move_lines (buf_T * frombuf, buf_T * tobuf);
void repeat_message (void);
void mch_settmode (int tmode);
long  mch_getperm (char_u * name);
int mch_isdir (char_u * name);
int mch_can_exe (char_u * name, char_u * * path, int use_path);
int mch_isFullName (char_u * fname);
static int executable_file (char_u * name);
int mch_can_exe (char_u * name, char_u * * path, int use_path);
int mch_has_exp_wildcard (char_u * p);
char_u *ga_concat_strings (garray_T *gap, char *sep);
int mch_expandpath (garray_T * gap, char_u * pat, int flags);
static int sortcmp (const void * a, const void * b);
static char_u *gettail_dir (char_u *fname);
static void source_callback (char_u * fname, void * cookie);
int var_check_func_name (char_u * name, int new_var);
int function_exists (char_u * name, int no_deref);
char_u *trans_function_name (char_u **pp, int skip, int flags, funcdict_T *fdp, partial_T **partial);
int get_id_len (char_u * * arg);
int eval_isnamec (int c);
char_u *get_lval (char_u *name, typval_T *rettv, lval_T *lp, int unlet, int skip, int flags, int fne_flags);
char_u *find_name_end (char_u *arg, char_u **expr_start, char_u **expr_end, int flags);
int eval_isnamec1 (int c);
static char_u *make_expanded_name (char_u *in_start, char_u *expr_start, char_u *expr_end, char_u *in_end);
int valid_varname (char_u * varname);
long  list_idx_of_item (list_T * l, listitem_T * item);
char_u *deref_func_name (char_u *name, int *lenp, partial_T **partialp, int no_autoload);
void clear_lval (lval_T * lp);
int translated_function_exists (char_u * name);
int find_internal_func (char_u * name);
void set_search_direction (int cdir);
void init_tv (typval_T * varp);
void shorten_dir (char_u * str);
void *mac_enc_to_cfstring (char_u *from, size_t fromLen);
void syn_stack_apply_changes (buf_T * buf);
static void syn_stack_apply_changes_block (synblock_T * block, buf_T * buf);
int gui_mch_is_blink_off (void);
static int nb_do_cmd (int bufno, char_u * cmd, int func, int cmdno, char_u * args);
static void nb_reply_nr (int cmdno, long result);
static int count_changed_buffers (void);
static void nb_reply_text (int cmdno, char_u * result);
int buf_findsign (buf_T * buf, int id);
static long  get_buf_size (buf_T * bufp);
static void nb_reply_nil (int cmdno);
static void nb_set_curbuf (buf_T * buf);
win_T *buf_jump_open_win (buf_T *buf);
win_T *buf_jump_open_tab (buf_T *buf);
void set_curbuf (buf_T * buf, int action);
void close_windows (buf_T * buf, int keep_curwin);
static pos_T *off2pos (buf_T *buf, long  offset);
static void nb_partialremove (linenr_T lnum, colnr_T first, colnr_T last);
static void nb_joinlines (linenr_T first, linenr_T other);
int buf_findsign_id (buf_T * buf, linenr_T lnum);
linenr_T buf_delsign (buf_T * buf, int id);
static char *nb_unquote (char_u *p, char_u **endp);
static void print_read_msg (nbbuf_T * buf);
static void print_save_msg (nbbuf_T * buf, off_T nchars);
char_u *do_bufdel (int command, char_u *arg, int addr_count, int start_bnr, int end_bnr, int forceit);
int do_buffer (int action, int start, int dir, int count, int forceit);
static int empty_curbuf (int close_others, int forceit, int action);
char_u *skiptowhite_esc (char_u *p);
static void handle_key_queue (void);
buf_T *buflist_findname (char_u *ffname);
void goto_buffer (exarg_T * eap, int start, int dir, int count);
void gui_mch_set_foreground (void);
static pos_T *get_off_or_lnum (buf_T *buf, char_u **argp);
static void addsigntype (nbbuf_T * buf, int typeNum, char_u * typeName, char_u * tooltip, char_u * glyphFile, char_u * fg, char_u * bg);
static int mapsigntype (nbbuf_T * buf, int localsigntype);
static void nb_init_graphics (void);
int buf_findsigntype_id (buf_T * buf, linenr_T lnum, int typenr);
static void special_keys (char_u * args);
void channel_consume (channel_T * channel, ch_part_T part, int len);
int channel_parse_messages (void);
static void channel_close_now (channel_T * channel);
void redraw_after_callback (int call_update_screen);
char_u *serverConvert (char_u *client_enc, char_u *data, char_u **tofree);
void server_to_input_buf (char_u * str);
char_u *eval_client_expr_to_string (char_u *expr);
void job_check_ended (void);
job_T *mch_detect_ended_job (job_T *job_list);
void job_cleanup (job_T * job);
static void closescript (void);
static void gotchars (char_u * chars, int len);
static void may_sync_undo (void);
void unshowmode (int force);
void clearmode (void);
void push_showcmd (void);
void pop_showcmd (void);
void unputcmdline (void);
static int ti_change (char_u * str, char_u * * last);
void invalidate_botline (void);
void fix_help_buffer (void);
static int unadjust_for_sel (void);
void check_pos (buf_T * buf, pos_T * pos);
static void get_op_vcol (oparg_T * oap, colnr_T redo_VIsual_vcol, int initial);
int op_on_lines (int op);
void op_shift (oparg_T * oap, int curs_top, int amount);
static void shift_block (oparg_T * oap, int amount);
static void block_prep (oparg_T * oap, struct block_def * bdp, linenr_T lnum, int is_del);
void CancelRedo (void);
int op_delete (oparg_T * oap);
int op_yank (oparg_T * oap, int deleting, int mess);
static int yank_copy_line (struct block_def * bd, long y_idx);
void update_topline_redraw (void);
static char_u *reg (int paren, int *flagp);
static char_u *regnode (int op);
static char_u *regbranch (int *flagp);
static char_u *regconcat (int *flagp);
static int peekchr (void);
static int no_Magic (int x);
static int toggle_Magic (int x);
static int backslash_trans (int c);
static void skipchr_keepstart (void);
static void skipchr (void);
static char_u *regpiece (int *flagp);
static char_u *regatom (int *flagp);
static int getchr (void);
static void regc (int b);
static int seen_endbrace (int refnum);
static int re_mult_next (char * what);
static int re_multi_type (int c);
static void regtail (char_u * p, char_u * val);
static char_u *regnext (char_u *p);
static void ungetchr (void);
static long  getdecchrs (void);
static long  getoctchrs (void);
static long  gethexchrs (int maxinputlen);
static char_u *re_put_long (char_u *p, long_u val);
static int coll_get_char (void);
static void reg_equi_class (int c);
static void reginsert (int op, char_u * opnd);
static void regoptail (char_u * p, char_u * val);
static void reginsert_nr (int op, long val, char_u * opnd);
static int read_limits (long * minval, long * maxval);
static void reginsert_limits (int op, long minval, long maxval, char_u * opnd);
int has_textyankpost (void);
static void yank_do_autocmd (oparg_T * oap, yankreg_T * reg);
dict_T *get_vim_var_dict (int idx);
int dict_add_list (dict_T * d, char * key, list_T * list);
void shift_delete_registers ();
int truncate_line (int fixpos);
int getviscol2 (colnr_T col, colnr_T coladd);
void display_dollar (colnr_T col);
int op_change (oparg_T * oap);
void fix_indent (void);
char_u *get_equalprg (void);
void op_reindent (oparg_T * oap, int (* how) (void));
static void op_colon (oparg_T * oap);
void op_tilde (oparg_T * oap);
static int swapchars (int op_type, pos_T * pos, int length);
int swapchar (int op_type, pos_T * pos);
void op_formatexpr (oparg_T * oap);
void op_format (oparg_T * oap, int keep_cursor);
static void op_function (oparg_T * oap);
varnumber_T call_func_retnr (char_u * func, int argc, char_u * * argv, int safe);
void op_insert (oparg_T * oap, long count1);
static void block_insert (oparg_T * oap, char_u * s, int b_insert, struct block_def * bdp);
int op_replace (oparg_T * oap, int c);
void foldCreate (linenr_T start, linenr_T end);
static void foldCreateMarkers (linenr_T start, linenr_T end);
static void parseMarker (win_T * wp);
static void foldAddMarker (linenr_T lnum, char_u * marker, int markerlen);
void opFoldRange (linenr_T first, linenr_T last, int opening, int recurse, int had_visual);
void deleteFold (linenr_T start, linenr_T end, int recursive, int had_visual);
static int check_closed (win_T * win, fold_T * fp, int * use_levelp, int level, int * maybe_smallp, linenr_T lnum_off);
static void checkSmall (win_T * wp, fold_T * fp, linenr_T lnum_off);
static void deleteFoldMarkers (fold_T * fp, int recursive, linenr_T lnum_off);
static void foldDelMarker (linenr_T lnum, char_u * marker, int markerlen);
void op_addsub (oparg_T * oap, linenr_T Prenum1, int g_cmd);
static int do_addsub (int op_type, pos_T * pos, int length, linenr_T Prenum1);
void clip_mch_request_selection (VimClipboard * cbd);
void var_redir_str (char_u * value, int value_len);
void var_redir_stop (void);
static void set_var_lval (lval_T * lp, char_u * endp, typval_T * rettv, int copy, char_u * op);
int get_var_tv (char_u * name, int len, typval_T * rettv, dictitem_T * * dip, int verbose, int no_autoload);
static int tv_op (typval_T * tv1, typval_T * tv2, char_u * op);
int list_extend (list_T * l1, list_T * l2, listitem_T * bef);
int list_insert_tv (list_T * l, typval_T * tv, listitem_T * item);
void list_insert (list_T * l, listitem_T * ni, listitem_T * item);
int list_append_number (list_T * l, varnumber_T n);
static void msg_puts_printf (char_u * str, int maxlen);
void do_throw (struct condstack * cstack);
int cleanup_conditionals (struct condstack * cstack, int searched_cond, int inclusive);
void discard_pending_return (void * rettv);
static void finish_exception (except_T * excp);
int getline_equal (char_u * (* fgetline) (int, void *, int), void * cookie, char_u * (* func) (int, void *, int));
static char_u *get_loop_line (int c, void *cookie, int indent);
static int store_loop_line (garray_T * gap, char_u * line);
char_u *get_func_line (int c, void *cookie, int indent);
void func_line_end (void * cookie);
int aborted_in_try (void);
void func_line_start (void * cookie);
void *getline_cookie (char_u * (*fgetline) (int, void *, int), void *cookie);
int func_level (void * cookie);
char_u *func_name (void *cookie);
linenr_T *func_breakpoint (void *cookie);
int *func_dbg_tick (void *cookie);
linenr_T *source_breakpoint (void *cookie);
int *source_dbg_tick (void *cookie);
static void save_dbg_stuff (struct dbg_stuff * dsp);
char_u *v_exception (char_u *oldval);
char_u *v_throwpoint (char_u *oldval);
int func_has_abort (void * cookie);
int func_has_ended (void * cookie);
int source_finished (char_u * (* fgetline) (int, void *, int), void * cookie);
int has_loop_cmd (char_u * p);
int modifier_len (char_u * cmd);
static char_u *do_one_cmd (char_u **cmdlinep, int sourcing, struct condstack *cstack, char_u * (*fgetline) (int, void *, int), void *cookie);
char_u *getnextac (int c, void *cookie, int indent);
int checkforcmd (char_u * * pp, char * cmd, int len);
static linenr_T get_address (exarg_T * eap, char_u * * ptr, int addr_type, int skip, int to_other_file, int address_count);
int qf_get_cur_valid_idx (exarg_T * eap);
int qf_get_size (exarg_T * eap);
pos_T *getmark (int c, int changefile);
pos_T *getmark_buf_fnum (buf_T *buf, int c, int changefile, int *fnum);
int findpar (int * pincl, int dir, long count, int what, int both);
int findsent (int dir, long count);
int buflist_getfile (int n, linenr_T lnum, int options, int forceit);
int check_mark (pos_T * pos);
static int compute_buffer_local_count (int addr_type, int lnum, int offset);
void func_line_exec (void * cookie);
void script_line_exec (void);
void dbg_check_breakpoint (exarg_T * eap);
void do_debug (char_u * cmd);
static void do_showbacktrace (char_u * cmd);
static int get_maxbacktrace_level (void);
static void do_setdebugtracelevel (char_u * arg);
static void do_checkbacktracelevel (void);
int do_intthrow (struct condstack * cstack);
static char_u *find_command (exarg_T *eap, int *full);
void iemsg (char_u * s);
void get_wincmd_addr_type (char_u * arg, exarg_T * eap);
static char_u *invalid_range (exarg_T *eap);
static void correct_range (exarg_T * eap);
static void ex_print (exarg_T * eap);
void print_line (linenr_T lnum, int use_number, int list);
int has_cmdundefined (void);
static char_u *uc_fun_cmd (void);
static void append_command (char_u * cmd);
void ex_ni (exarg_T * eap);
char_u *script_get (exarg_T *eap, char_u *cmd);
static char_u *replace_makeprg (exarg_T *eap, char_u *p, char_u **cmdlinep);
int grep_internal (cmdidx_T cmdidx);
void msg_make (char_u * arg);
static int getargopt (exarg_T * eap);
int check_ff_value (char_u * p);
static char_u *getargcmd (char_u **argp);
void separate_nextcmd (exarg_T * eap);
static char_u *skip_grep_pat (exarg_T *eap);
void del_trailing_spaces (char_u * ptr);
static void get_flags (exarg_T * eap);
int expand_filename (exarg_T * eap, char_u * * cmdlinep, char_u * * errormsgp);
static char_u *repl_cmdline (exarg_T *eap, char_u *src, int srclen, char_u *repl, char_u **cmdlinep);
static void do_ucmd (exarg_T * eap);
static size_t uc_check_code (char_u * code, size_t len, char_u * buf, ucmd_T * cmd, exarg_T * eap, char_u * * split_buf, size_t * split_len);
static char_u *uc_split_args (char_u *arg, size_t *lenp);
static size_t add_cmd_modifier (char_u * buf, char * mod_str, int * multi_mods);
void do_finish (exarg_T * eap, int reanimate);
int current_func_returned (void);
int do_return (exarg_T * eap, int reanimate, int is_cmd, void * rettv);
void rewind_conditionals (struct condstack * cstack, int idx, int cond_type, int * cond_level);
void free_for_info (void * fi_void);
void list_rem_watch (list_T * l, listwatch_T * lwrem);
int has_watchexpr (void);
static void free_cmdlines (garray_T * gap);
int source_level (void * cookie);
static void restore_dbg_stuff (struct dbg_stuff * dsp);
void restore_search_patterns (void);
void restoreRedobuff (save_redo_T * save_redo);
static void call_user_func (ufunc_T * fp, int argcount, typval_T * argvars, typval_T * rettv, linenr_T firstline, linenr_T lastline, dict_T * selfdict);
void func_ptr_ref (ufunc_T * fp);
static void add_nr_var (dict_T * dp, dictitem_T * v, char * name, varnumber_T nr);
static void func_do_profile (ufunc_T * fp);
static void cleanup_function_call (funccall_T * fc);
int call_internal_func (char_u * name, int argcount, typval_T * argvars, typval_T * rettv);
void update_force_abort (void);
static void emsg_funcname (char * ermsg, char_u * name);
void set_pressedreturn (int val);
static void remove_timer (timer_T * timer);
static void free_timer (timer_T * timer);
static int gui_wait_for_chars_3 (long wtime, int * interrupted, int ignore_input);
static void gui_outstr (char_u * s, int len);
void mch_write (char_u * p, int len);
void tag_freematch (void);
int mch_call_shell (char_u * cmd, int options);
void win_resize_on (void);
void shell_resized_check (void);
static int diff_write (buf_T * buf, char_u * fname);
static void diff_read (int idx_orig, int idx_new, char_u * fname);
static void diff_copy_entry (diff_T * dprev, diff_T * dp, int idx_orig, int idx_new);
static int diff_equal_entry (diff_T * dp, int idx1, int idx2);
static int scrolljump_value (void);
void scroll_cursor_bot (int min_scroll, int set_topbot);
void scroll_to_fraction (win_T * wp, int prev_height);
int plines_win_col (win_T * wp, linenr_T lnum, long column);
static int frame_check_height (frame_T * topfrp, int height);
void free_screenlines (void);
static int channel_get_json (channel_T * channel, ch_part_T part, int id, int without_callback, typval_T * * rettv);
static int channel_parse_json (channel_T * channel, ch_part_T part);
static int channel_fill (js_read_T * reader);
int json_decode (js_read_T * reader, typval_T * res, int options);
static void json_skip_white (js_read_T * reader);
static void fill_numbuflen (js_read_T * reader);
static int json_decode_item (js_read_T * reader, typval_T * res, int options);
int rettv_list_alloc (typval_T * rettv);
void rettv_list_set (typval_T * rettv, list_T * l);
int rettv_dict_alloc (typval_T * rettv);
void rettv_dict_set (typval_T * rettv, dict_T * d);
static int json_decode_string (js_read_T * reader, typval_T * res, int quote);
static void channel_exe_cmd (channel_T * channel, ch_part_T part, typval_T * argv);
void ex_normal (exarg_T * eap);
void ex_redraw (exarg_T * eap);
int func_call (char_u * name, typval_T * args, partial_T * partial, dict_T * selfdict, typval_T * rettv);
char_u *json_encode_nr_expr (int nr, typval_T *val, int options);
int list_append_tv (list_T * l, typval_T * tv);
static int json_encode_gap (garray_T * gap, typval_T * val, int options);
static int json_encode_item (garray_T * gap, typval_T * val, int copyID, int options);
static void write_string (garray_T * gap, char_u * str);
static int is_simple_key (char_u * key);
dictitem_T *dict_lookup (hashitem_T *hi);
static void drop_messages (channel_T * channel, ch_part_T part);
static char_u *channel_get_all (channel_T *channel, ch_part_T part);
static void invoke_one_time_callback (channel_T * channel, cbq_T * cbhead, cbq_T * item, typval_T * argv);
static void invoke_callback (channel_T * channel, char_u * callback, partial_T * partial, typval_T * argv);
static void channel_push_json (channel_T * channel, ch_part_T part, typval_T * rettv);
char_u *json_encode (typval_T *val, int options);
void write_to_term (buf_T * buffer, char_u * msg, channel_T * channel);
static void term_write_job_output (term_T * term, char_u * msg, size_t len);
static void append_strbuffer (VTerm * vt, const char * str, size_t len);
static void do_control (VTerm * vt, unsigned char control);
static size_t do_string (VTerm * vt, const char * str_frag, size_t len);
static void do_string_csi (VTerm * vt, const char * args, size_t arglen, char command);
static int moverect (VTermRect dest, VTermRect src, void * user);
static int moverect_user (VTermRect dest, VTermRect src, void * user);
void vterm_screen_flush_damage (VTermScreen * screen);
static int erase_user (VTermRect rect, int selective, void * user);
static void damagerect (VTermScreen * screen, VTermRect rect);
static void append_to_buffer (buf_T * buffer, char_u * msg, channel_T * channel, ch_part_T part);
void switch_to_win_for_buf (buf_T * buf, win_T * * save_curwinp, tabpage_T * * save_curtabp, bufref_T * save_curbuf);
void switch_buffer (bufref_T * save_curbuf, buf_T * buf);
int switch_win (win_T * * save_curwin, tabpage_T * * save_curtab, win_T * win, tabpage_T * tp, int no_display);
void restore_win (win_T * save_curwin, tabpage_T * save_curtab, int no_display);
void restore_win_for_buf (win_T * save_curwin, tabpage_T * save_curtab, bufref_T * save_curbuf);
void restore_buffer (bufref_T * save_curbuf);
void redraw_buf_and_status_later (buf_T * buf, int type);
void term_channel_closed (channel_T * ch);
static void cleanup_vterm (term_T * term);
void mch_clear_job (job_T * job);
int get_lambda_tv (char_u * * arg, typval_T * rettv, int evaluate);
static int get_function_args (char_u * * argp, char_u endchar, garray_T * newargs, int * varargs, int skip);
static int register_closure (ufunc_T * fp);
int prof_def_func (void);
int get_dict_tv (char_u * * arg, typval_T * rettv, int evaluate);
int get_option_tv (char_u * * arg, typval_T * rettv, int evaluate);
static char_u *find_option_end (char_u **arg, int *opt_flags);
int get_option_value (char_u * name, long * numval, char_u * * stringval, int opt_flags);
static int get_env_tv (char_u * * arg, typval_T * rettv, int evaluate);
static int get_env_len (char_u * * arg);
int get_name_len (char_u * * arg, char_u * * alias, int evaluate, int verbose);
static void check_vars (char_u * name, int len);
int get_func_tv (char_u * name, int len, typval_T * rettv, char_u * * arg, linenr_T firstline, linenr_T lastline, int * doesrange, int evaluate, partial_T * partial, dict_T * selfdict);
int handle_subscript (char_u * * arg, typval_T * rettv, int evaluate, int verbose);
static int eval_index (char_u * * arg, typval_T * rettv, int evaluate, int verbose);
dict_T *make_partial (dict_T *selfdict_in, typval_T *rettv);
int list_concat (list_T * l1, list_T * l2, typval_T * tv);
list_T *list_copy (list_T *orig, int deep, int copyID);
int item_copy (typval_T * from, typval_T * to, int deep, int copyID);
dict_T *dict_copy (dict_T *orig, int deep, int copyID);
static void vim_settempdir (char_u * tempdir);
int mf_open_file (memfile_T * mfp, char_u * fname);
void mf_set_dirty (memfile_T * mfp);
blocknr_T mf_trans_del (memfile_T * mfp, blocknr_T old_nr);
static int foldLevelWin (win_T * wp, linenr_T lnum);
static void foldlevelExpr (fline_T * flp);
int eval_foldexpr (char_u * arg, int * cp);
static void foldlevelSyntax (fline_T * flp);
int syn_get_foldlevel (win_T * wp, long lnum);
static void foldlevelDiff (fline_T * flp);
int diff_infold (win_T * wp, linenr_T lnum);
static void foldlevelIndent (fline_T * flp);
int get_indent_buf (buf_T * buf, linenr_T lnum);
static linenr_T foldUpdateIEMSRecurse (garray_T * gap, int level, linenr_T startlnum, fline_T * flp, void (* getlevel) (fline_T *), linenr_T bot, int topflags);
static void foldRemove (garray_T * gap, linenr_T top, linenr_T bot);
static void foldSplit (garray_T * gap, int i, linenr_T top, linenr_T bot);
static int foldInsert (garray_T * gap, int i);
static void foldMerge (fold_T * fp1, garray_T * gap, fold_T * fp2);
void updateWindow (win_T * wp);
void gui_mac_doInDragClick (Point where, WindowPtr whichWindow);
void gui_mac_doInGrowClick (Point where, WindowPtr whichWindow);
int check_changed_any (int hidden, int unload);
static void add_bufnum (int * bufnrs, int * bufnump, int nr);
static void gui_mac_doInZoomClick (EventRecord * theEvent, WindowPtr whichWindow);
void gui_mac_doKeyEvent (EventRecord * theEvent);
void gui_mac_doMouseUpEvent (EventRecord * theEvent);
void gui_mac_doUpdateEvent (EventRecord * event);
void gui_redraw (int x, int y, int w, int h);
void gui_mac_doActivateEvent (EventRecord * event);
void gui_focus_change (int in_focus);
void gui_mac_doMouseMovedEvent (EventRecord * event);
void gui_mouse_moved (int x, int y);
void gui_mac_doSuspendEvent (EventRecord * event);
void mch_breakcheck (int force);
static void reg_nextline (void);
pos_T *getmark_buf (buf_T *buf, int c, int changefile);
static int reg_match_visual (void);
static int re_num_cmp (long_u val, char_u * scan);
static int cstrncmp (char_u * s1, char_u * s2, int * n);
static char_u *cstrchr (char_u *s, int c);
static int reg_save_equal (regsave_T * save);
static void reg_save (regsave_T * save, garray_T * gap);
static void cleanup_subexpr (void);
static regitem_T *regstack_push (regstate_T state, char_u *scan);
static void cleanup_zsubexpr (void);
static int match_with_backref (linenr_T start_lnum, colnr_T start_col, linenr_T end_lnum, colnr_T end_col, int * bytelen);
static int regrepeat (char_u * p, long maxcount);
static void save_subexpr (regbehind_T * bp);
static void regstack_pop (char_u * * scan);
static void reg_restore (regsave_T * save, garray_T * gap);
static void restore_subexpr (regbehind_T * bp);
static void find_prefix (matchinf_T * mip, int mode);
int spell_check_GRAFT_INTERFACE (typval_T * $_host_rettv, typval_T * $_host_argvars, int $_host_capcol, int $_host_len, hlf_T $_host_attr, char_u * $_host_str, char_u * $_host_word);
