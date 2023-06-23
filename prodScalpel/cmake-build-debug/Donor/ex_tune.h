/*
 * This code contains changes by
 *      Gunnar Ritter, Freiburg i. Br., Germany, 2002. All rights reserved.
 *
 * Conditions 1, 2, and 4 and the no-warranty notice below apply
 * to these changes.
 *
 *
 * Copyright (c) 1980, 1993
 * 	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 * 	This product includes software developed by the University of
 * 	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *
 * Copyright(C) Caldera International Inc. 2001-2002. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *   Redistributions of source code and documentation must retain the
 *    above copyright notice, this list of conditions and the following
 *    disclaimer.
 *   Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *   All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed or owned by Caldera
 *      International, Inc.
 *   Neither the name of Caldera International, Inc. nor the names of
 *    other contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * USE OF THE SOFTWARE PROVIDED FOR UNDER THIS LICENSE BY CALDERA
 * INTERNATIONAL, INC. AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL CALDERA INTERNATIONAL, INC. BE
 * LIABLE FOR ANY DIRECT, INDIRECT INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *	from ex_tune.h	7.8.1 (2.11BSD) 1996/10/23
 *
 *	Sccsid @(#)ex_tune.h	1.14 (gritter) 8/4/05
 */

/*
 * Note: the parameters that are actually tuneable have been moved to
 * config.h. Do not make changes here unless you know what you are
 * doing! GR
 */

/*
 * Definitions of editor parameters and limits
 */

/*
 * Pathnames (will be predefined in Makefile).
 */

/*
 * If your system believes that tabs expand to a width other than
 * 8 then your makefile should cc with -DTABS=whatever, otherwise we use 8.
 */
#define	TABS	8

/*
 * Maximums
 *
 * Most definitions are quite generous.
 */
/* FNSIZE is also defined in expreserve.c */
#define	FNSIZE		_POSIX_PATH_MAX
#define CRSIZE		BUFSIZ		/* Crypt buffer size */
#define	NBRA		9		/* Number of re \( \) pairs */
#define	GBSIZE		256		/* Buffer size */
#define	UXBSIZE		128		/* Unix command buffer size */
#define	VBSIZE		128		/* Partial line max size in visual */
/* LBLKS is also defined in expreserve.c */
#define	LBLKS		20000
#define	HBLKS		(1 + (FNSIZE + LBLKS * sizeof(bloc)) / BUFSIZ)
#define	MAXDIRT		12		/* Max dirtcnt before sync tfile */

/*
 * Size of in-core buffers for temporary file. Since this is
 * sizeof (char) * (INCORB + 1) * BUFSIZ, it should not be too
 * large.
 *
 * If not defined, no in-core buffers are used.
 */
#if	(BUFSIZ - 0) <= 16384
#define	INCORB		(65536/BUFSIZ)
#else	/* Huge-memory systems. */
#define	INCORB		4
#endif	/* Huge-memory systems. */

/*
 * Except on VMUNIX, these are a ridiculously small due to the
 * lousy arglist processing implementation which fixes core
 * proportional to them.  Argv (and hence NARGS) is really unnecessary,
 * and argument character space not needed except when
 * arguments exist.  Argument lists should be saved before the "zero"
 * of the incore line information and could then
 * be reasonably large.
 */
#undef NCARGS
#define	NCARGS	5120
#define	NARGS	(NCARGS/6)

/*
 * Output column (and line) are set to this value on cursor addressible
 * terminals when we lose track of the cursor to force cursor
 * addressing to occur.
 */
#define	UKCOL		-20	/* Prototype unknown column */

/*
 * Attention is the interrupt character (normally 0177 -- delete).
 * Quit is the quit signal (normally FS -- control-\) and quits open/visual.
 */
extern int	ATTN;
#define	QUIT	('\\' & 037)

#define	LRGINT	INT_MAX		/* largest normal length positive integer */

#define	MAXOCT	11		/* Maximum octal digits in a long */
#define	BIG	1000000000UL	/* largest power of 10 < unsigned long */
#define	MAXDIGS	10		/* number of digits in BIG */
