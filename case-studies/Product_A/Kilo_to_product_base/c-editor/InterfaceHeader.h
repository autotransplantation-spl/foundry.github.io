
#include <ctype.h>

#include <errno.h>

#include <fcntl.h>

#include <stdarg.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <sys/ioctl.h>

#include <termios.h>

#include <time.h>

#include <unistd.h>

#define KILO_VERSION "0.0.1"

#define KILO_TAB_STOP 8

#define KILO_QUIT_TIMES 3

#define CTRL_KEY(k) ((k)&0x1f)

#define HL_HIGHLIGHT_NUMBERS (1 << 0)

#define HL_HIGHLIGHT_STRINGS (1 << 1)

#define ABUF_INIT                                                              \
  { NULL, 0 }

#define HLDB_ENTRIES (sizeof(HLDB) / sizeof(HLDB[0]))
void editorOpen (char * filename);
void die (const char * s);
void editorInsertRow (int at, char * s, size_t len);
void editorUpdateRow (struct erow * row);
void editorUpdateSyntax (struct erow * row);
int is_separator (int c);
void editorSelectSyntaxHighlight ();
int getCursorPosition (int * rows, int * cols);
void editorSetStatusMessage (const char * fmt,...);
void editorRefreshScreen ();
void abAppend (struct abuf * ab, const char * s, int len);
void abFree (struct abuf * ab);
void editorDrawMessageBar (struct abuf * ab);
void editorDrawRows (struct abuf * ab);
int editorSyntaxToColor (int hl);
void editorDrawStatusBar (struct abuf * ab);
void editorScroll ();
int editorRowCxToRx (struct erow * row, int cx);
void editorProcessKeypress ();
void editorDelChar ();
void editorDelRow (int at);
void editorFreeRow (struct erow * row);
void editorRowAppendString (struct erow * row, char * s, size_t len);
void editorRowDelChar (struct erow * row, int at);
void editorFind ();
void editorFindCallback (char * query, int key);
int editorRowRxToCx (struct erow * row, int rx);
char *editorPrompt (char *prompt, void (*callback) (char *, int));
int editorReadKey ();
void editorInsertChar (int c);
void editorRowInsertChar (struct erow * row, int at, int c);
void editorInsertNewLine ();
void editorMoveCursor (int key);
void editorSave ();
char *editorRowsToString (int *buflen);
void editorOpen_GRAFT_INTERFACE (char * $_host_argv [], int $_host_argc);
