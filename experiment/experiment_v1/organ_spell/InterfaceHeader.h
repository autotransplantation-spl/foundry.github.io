
#include <Devices.h> /* included first to avoid CR problems */

#include <Menus.h>

#include <Resources.h>

#include <Processes.h>

#include <exec/memory.h>

#include <libraries/dosextens.h>

#include <dos/dostags.h>	    /* for 2.0 functions */

#include <dos/dosasl.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>	/* for strncmp() */

#include <ctype.h>	/* for isalnum() */

#include <limits.h>

#include <assert.h>

#include <stdarg.h>

#include <stddef.h>

#include <signal.h>

#include <errno.h>

#include <time.h>

#include <dirent.h>

#define RESCORE(word_score, sound_score) ((3 * word_score + sound_score) / 4)

#define MAXSCORE(word_score, sound_score) ((4 * word_score - sound_score) / 3)

#define IN_SPELL_C

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

#define MB_FILLER_CHAR '<'  /* character used when a double-width character
			     * doesn't fit. */

#define TRUE (1)

#define FALSE (0)

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

#define BUFSIZE		8192	/* size of normal write buffer */

#define SMBUFSIZE	256	/* size of emergency write buffer */

#define USE_MCH_ACCESS

#define CONV_RESTLEN 30

#define ICONV_MULT 8

#define AUGROUP_NAME(i) (((char_u **)augroups.ga_data)[i])

#define MESSAGE_FILE		/* don't include prototype for smsg() */

#define USING_FLOAT_STUFF

#define MEMFILE_PAGE_SIZE 4096		/* default page size */

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

#define MENUDEPTH   10		/* maximum depth of menus */

#define MINIMAL_SIZE 20			/* minimal size for b_str */

#define MAP_HASH(mode, c1) (((mode) & (NORMAL + VISUAL + SELECTMODE + OP_PENDING + TERMINAL)) ? (c1) : ((c1) ^ 0x80))

#define RM_YES		0	/* tb_noremap: remap */

#define RM_NONE		1	/* tb_noremap: don't remap */

#define RM_SCRIPT	2	/* tb_noremap: remap local script mappings */

#define RM_ABBR		4	/* tb_noremap: don't remap, do abbrev. */

#define TYPELEN_INIT	(5 * (MAXMAPLEN + 3))

#define ARRAY_LENGTH(A)      (sizeof(A)/sizeof(A[0]))

#define BF_BLOCK    8

#define BF_BLOCK_MASK 7

#define BF_MAX_CFB_LEN  (8 * BF_BLOCK)

#define F1(i) xl ^= bfs->pax[i]; xr ^= ((bfs->sbx[0][xl >> 24] + bfs->sbx[1][(xl & 0xFF0000) >> 16]) ^ bfs->sbx[2][(xl & 0xFF00) >> 8]) +  bfs->sbx[3][xl & 0xFF];

#define F2(i)  xr ^= bfs->pax[i]; xl ^= ((bfs->sbx[0][xr >> 24] + bfs->sbx[1][(xr & 0xFF0000) >> 16]) ^ bfs->sbx[2][(xr & 0xFF00) >> 8]) + bfs->sbx[3][xr & 0xFF];

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

#define GUARDED		10000 /* typenr for "guarded" annotation */

#define GUARDEDOFFSET 1000000 /* base for "guarded" sign id's */

#define MAX_COLOR_LENGTH 32 /* max length of color name in defineAnnoType */

#define NETBEANS_OPEN (channel_can_write_to(nb_channel))

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

#define UH_MAGIC 0x18dade	/* value for uh_magic when in use */

#define UE_MAGIC 0xabc123	/* value for ue_magic when in use */

#define CRYPT_BUF_SIZE 8192

#define U_ALLOC_LINE(size) lalloc((long_u)(size), FALSE)

#define LISTCOUNT   10

#define FMT_PATTERNS 10		/* maximum number of % recognized */

#define IS_QF_WINDOW(wp) (bt_quickfix(wp->w_buffer) && wp->w_llist_ref == NULL)

#define IS_LL_WINDOW(wp) (bt_quickfix(wp->w_buffer) && wp->w_llist_ref != NULL)

#define GET_LOC_LIST(wp) (IS_LL_WINDOW(wp) ? wp->w_llist_ref : wp->w_llist)

#define SCRIPT_ITEM(id) (((scriptitem_T *)script_items.ga_data)[(id) - 1])

#define BREAKP(idx)		(((struct debuggy *)dbg_breakp.ga_data)[idx])

#define DEBUGGY(gap, idx)	(((struct debuggy *)gap->ga_data)[idx])

#define DBG_FUNC	1

#define DBG_FILE	2

#define DBG_EXPR	3

#define AL_SET	1

#define AL_ADD	2

#define AL_DEL	3

#define UC_BUFFER	1	/* -buffer: local to current buffer */

#define USER_CMD(i) (&((ucmd_T *)(ucmds.ga_data))[i])

#define USER_CMD_GA(gap, i) (&((ucmd_T *)((gap)->ga_data))[i])

#define DO_DECLARE_EXCMD

#define BACKSPACE_CHAR		    1

#define BACKSPACE_WORD		    2

#define BACKSPACE_WORD_NOT_SPACE    3

#define BACKSPACE_LINE		    4

#define PC_STATUS_UNSET	0	/* pc_bytes was not set */

#define PC_STATUS_RIGHT	1	/* right halve of double-wide char */

#define PC_STATUS_LEFT	2	/* left halve of double-wide char */

#define PC_STATUS_SET	3	/* pc_bytes was filled */

#define PERTURB_SHIFT 5

#define MT_ST_CUR	0		/* static match in current file */

#define MT_GL_CUR	1		/* global match in current file */

#define MT_GL_OTH	2		/* global match in other file */

#define MT_ST_OTH	3		/* static match in other file */

#define MT_IC_OFF	4		/* add for icase match */

#define MT_RE_OFF	8		/* add for regexp match */

#define MT_MASK		7		/* mask for printing priority */

#define MT_COUNT	16

#define NOTAGFILE	99		/* return value for jumpto_tag */

#define TRY_SEEK	/* attempt to use lseek, or skip forward by reading */

#define COLS 256	/* change here, if you ever need more columns */

#define LLEN (12 + (9*COLS-1) + COLS + 2)

#define HEX_NORMAL 0

#define HEX_POSTSCRIPT 1

#define HEX_CINCLUDE 2

#define HEX_BITS 3		/* not hex a dump, but bits: 01111001 */

#define HEX_LITTLEENDIAN 4

#define EXTERN

#define EDIT_NONE   0	    /* no edit type yet */

#define EDIT_FILE   1	    /* file name argument[s] given, use argument list */

#define EDIT_STDIN  2	    /* read file from stdin */

#define EDIT_TAG    3	    /* tag name argument given, use tagname */

#define EDIT_QF	    4	    /* start in quickfix mode */

#define EXTRA_MARKS 10					/* marks 0-9 */

#define KMAP_MAXLEN 20	    /* maximum length of "from" or "to" */

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

#define SESSION_FILE	"Session.vim"

#define MAC_CLIENTSERVER

#define USE_CMD_KEY

#define USE_UNIXFILENAME

#define FEAT_SOURCE_FFS

#define FEAT_SOURCE_FF_MAC

#define USE_EXE_NAME		    /* to find  $VIM */

#define CASE_INSENSITIVE_FILENAME   /* ignore case when comparing file names */

#define SPACE_IN_FILENAME

#define BREAKCHECK_SKIP	   32	    /* call mch_breakcheck() each time, it's
				       quite fast. Did I forgot to update the
				       comment */

#define USE_FNAME_CASE		/* make ":e os_Mac.c" open the file in its
				   original case, as "os_mac.c" */

#define BINARY_FILE_IO

#define EOL_DEFAULT EOL_MAC

#define HAVE_AVAIL_MEM

#define DFLT_ERRORFILE		"errors.err"

#define CMDBUFFSIZE 1024	/* size of the command processing buffer */

#define WILDCHAR_LIST "*?[{`$"

#define mch_rename(src, dst) rename(src, dst)

#define mch_remove(x) unlink((char *)(x))

#define UNKNOWN_CREATOR '\?\?\?\?'

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

#define _REGEXP_H

#define NSUBEXP  10

#define NFA_MAX_BRACES 20

#define NFA_MAX_STATES 100000

#define NFA_TOO_EXPENSIVE -1

#define	    AUTOMATIC_ENGINE	0

#define	    BACKTRACKING_ENGINE	1

#define	    NFA_ENGINE		2

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

#define VIMSUGMAGIC "VIMsug"	/* string at start of Vim .sug file */

#define VIMSUGMAGICL 6

#define VIMSUGVERSION 1

#define FOR_ALL_BUFFERS(buf) for (buf = firstbuf; buf != NULL; buf = buf->b_next)

#define NSCRIPT 15

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
int spell_check_GRAFT_INTERFACE (char * $_host_in_file, char * $_host_tarArchive);
