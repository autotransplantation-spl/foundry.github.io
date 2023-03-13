#
# config.mk.in -- autoconf template for Vim on Unix		vim:ts=8:sw=8:
#
# DO NOT EDIT config.mk!!  It will be overwritten by configure.
# Edit Makefile and run "make" or run ./configure with other arguments.
#
# Configure does not edit the makefile directly. This method is not the
# standard use of GNU autoconf, but it has two advantages:
#   a) The user can override every choice made by configure.
#   b) Modifications to the makefile are not lost when configure is run.
#
# I hope this is worth being nonstandard. jw.



VIMNAME		= Vim
EXNAME		= ex
VIEWNAME	= view

CC		= gcc
DEFS		= -DHAVE_CONFIG_H
CFLAGS		= -O2   -Wall -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=1
CPPFLAGS	=  -DMACOS_X -DMACOS_X_DARWIN
XCODEFLAGS	=  MACOSX_DEPLOYMENT_TARGET=10.13 VIM_SHORT_VERSION_STRING=8.0.1520
srcdir		= .

LDFLAGS		=  -L/usr/local/lib
LIBS		= -lm -lncurses  -liconv -framework AppKit
TAGPRG		= ctags -t

CPP		= gcc -E
CPP_MM		= M
DEPEND_CFLAGS_FILTER = | sed 's+-I */+-isystem /+g'
LINK_AS_NEEDED	= 
X_CFLAGS	= 
X_LIBS_DIR	= 
X_PRE_LIBS	= 
X_EXTRA_LIBS	= 
X_LIBS		= 

LUA_LIBS	= 
LUA_SRC		= 
LUA_OBJ		= 
LUA_CFLAGS	= 
LUA_PRO		= 

MZSCHEME_LIBS	= 
MZSCHEME_SRC	= 
MZSCHEME_OBJ	= 
MZSCHEME_CFLAGS	= 
MZSCHEME_PRO	= 
MZSCHEME_EXTRA	= 
MZSCHEME_MZC	= 

PERL		= 
PERLLIB		= 
PERLSITELIB	= 
PERL_XSUBPP	= 
PERL_LIBS	= 
SHRPENV		= 
PERL_SRC	= 
PERL_OBJ	= 
PERL_PRO	= 
PERL_CFLAGS	= 

PYTHON_SRC	= 
PYTHON_OBJ	= 
PYTHON_CFLAGS	= 
PYTHON_LIBS	= 
PYTHON_CONFDIR	= 
PYTHON_GETPATH_CFLAGS = 

PYTHON3_SRC	= 
PYTHON3_OBJ	= 
PYTHON3_CFLAGS	= 
PYTHON3_LIBS	= 
PYTHON3_CONFDIR	= 

TCL		= 
TCL_SRC		= 
TCL_OBJ		= 
TCL_PRO		= 
TCL_CFLAGS	= 
TCL_LIBS	= 

HANGULIN_SRC	= 
HANGULIN_OBJ	= 

WORKSHOP_SRC	= 
WORKSHOP_OBJ	= 

NETBEANS_SRC	= netbeans.c
NETBEANS_OBJ	= objects/netbeans.o
CHANNEL_SRC	= channel.c
CHANNEL_OBJ	= objects/channel.o
TERM_SRC	= libvterm/src/encoding.c libvterm/src/keyboard.c libvterm/src/mouse.c libvterm/src/parser.c libvterm/src/pen.c libvterm/src/screen.c libvterm/src/state.c libvterm/src/unicode.c libvterm/src/vterm.c
TERM_OBJ	= objects/term_encoding.o objects/term_keyboard.o objects/term_mouse.o objects/term_parser.o objects/term_pen.o objects/term_screen.o objects/term_state.o objects/term_unicode.o objects/term_vterm.o

RUBY		= 
RUBY_SRC	= 
RUBY_OBJ	= 
RUBY_PRO	= 
RUBY_CFLAGS	= 
RUBY_LIBS	= 

AWK		= awk

STRIP		= strip

EXEEXT		= 
CROSS_COMPILING = 

COMPILEDBY	= 

INSTALLVIMDIFF	= installvimdiff
INSTALLGVIMDIFF	= installgvimdiff
INSTALL_LANGS	= install-languages
INSTALL_TOOL_LANGS	= install-tool-languages

### sed command to fix quotes while creating pathdef.c
QUOTESED        = sed -e 's/[\\"]/\\&/g' -e 's/\\"/"/' -e 's/\\";$$/";/'

### Line break character as octal number for "tr"
NL		= "\\012"

### Top directory for everything
prefix		= /Applications

### Top directory for the binary
exec_prefix	= ${prefix}

### Prefix for location of data files
BINDIR		= ${exec_prefix}/bin

### For autoconf 2.60 and later (avoid a warning)
datarootdir	= ${prefix}/share

### Prefix for location of data files
DATADIR		= ${prefix}/MacVim.app/Contents/Resources

### Prefix for location of man pages
MANDIR		= ${datarootdir}/man

### Do we have a GUI
GUI_INC_LOC	= 
GUI_LIB_LOC	= 
GUI_SRC		= $(MACVIMGUI_SRC)
GUI_OBJ		= $(MACVIMGUI_OBJ)
GUI_DEFS	= $(MACVIMGUI_DEFS)
GUI_IPATH	= $(MACVIMGUI_IPATH)
GUI_LIBS_DIR	= $(MACVIMGUI_LIBS_DIR)
GUI_LIBS1	= $(MACVIMGUI_LIBS1)
GUI_LIBS2	= $(MACVIMGUI_LIBS2)
GUI_INSTALL	= $(MACVIMGUI_INSTALL)
GUI_TARGETS	= $(MACVIMGUI_TARGETS)
GUI_MAN_TARGETS	= $(MACVIMGUI_MAN_TARGETS)
GUI_TESTTARGET	= $(MACVIMGUI_TESTTARGET)
GUI_TESTARG	= $(MACVIMGUI_TESTARG)
GUI_BUNDLE	= $(MACVIMGUI_BUNDLE)
NARROW_PROTO	= 
GUI_X_LIBS	= 
MOTIF_LIBNAME	= 
GTK_LIBNAME	= 

GLIB_COMPILE_RESOURCES = 
GRESOURCE_SRC = 
GRESOURCE_OBJ = 

GTK_UPDATE_ICON_CACHE = 
UPDATE_DESKTOP_DATABASE = 

### Any OS dependent extra source and object file
OS_EXTRA_SRC	= os_macosx.m os_mac_conv.c
OS_EXTRA_OBJ	= objects/os_macosx.o objects/os_mac_conv.o

### If the *.po files are to be translated to *.mo files.
MAKEMO		= 

MSGFMT		= 

# Make sure that "make first" will run "make all" once configure has done its
# work.  This is needed when using the Makefile in the top directory.
first: all
