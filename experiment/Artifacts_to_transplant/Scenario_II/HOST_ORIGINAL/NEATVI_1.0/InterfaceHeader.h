
#define REG_EXTENDED		0x01

#define REG_NOSUB		0x02

#define REG_ICASE		0x04

#define REG_NEWLINE		0x08

#define REG_NOTBOL		0x10

#define REG_NOTEOL		0x20

#define MKFILE_MODE		0600

#define SYN_LINE		(SYN_BGMK(11))

#define SYN_REVDIR		(SYN_BGMK(7))

#define CR2L		"ءآأؤإئابةتثجحخدذرزسشصضطظعغـفقكلمنهوىييپچژکگی‌‍؛،»«؟ًٌٍَُِّْ"

#define CNEUT		"-!\"#$%&'()*+,./:;<=>?@^_`{|}~ "

#define LEN(a)		(sizeof(a) / sizeof((a)[0]))

#define MIN(a, b)	((a) < (b) ? (a) : (b))

#define MAX(a, b)	((a) < (b) ? (b) : (a))

#define RE_ICASE		1

#define RE_NOTBOL		2

#define RE_NOTEOL		4

#define xrows		(term_rows() - 1)

#define xcols		(term_cols())

#define TK_CTL(x)	((x) & 037)

#define TK_INT(c)	((c) < 0 || (c) == TK_ESC || (c) == TK_CTL('c'))

#define TK_ESC		(TK_CTL('['))

#define EXLEN	512		/* ex line length */

#define xb 	ex_lbuf()

#define SYN_BD		0x010000

#define SYN_IT		0x020000

#define SYN_RV		0x040000

#define SYN_FGMK(f)	(0x100000 | (f))

#define SYN_BGMK(b)	(0x200000 | ((b) << 8))

#define SYN_FLG		0xff0000

#define SYN_FGSET(a)	((a) & 0x1000ff)

#define SYN_BGSET(a)	((a) & 0x20ff00)

#define SYN_FG(a)	((a) & 0xff)

#define SYN_BG(a)	(((a) >> 8) & 0xff)

#include <ctype.h>

#include <fcntl.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

extern struct rset *dir_rslr;
extern struct rset *dir_rsrl;
extern struct rset *dir_rsctx;

extern void dir_init (void);
void dir_init_GRAFT_INTERFACE ();
