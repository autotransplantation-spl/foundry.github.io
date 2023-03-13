CFLAGS = -I ../includes/ `pkg-config --cflags glib-2.0` `pkg-config --libs glib-2.0`

CHECKPACKAGE = `pkg-config --cflags --libs check`

Individual.x:	main.o InterfaceWithCoreFeature.o spell.o  misc2.o  charset.o  regexp.o  misc1.o  ui.o  gui_mac.o  gui.o  term.o  move.o  screen.o  os_amiga.o  window.o  diff.o  fileio.o  message.o  memfile.o  memline.o  buffer.o  ex_getln.o  menu.o  farsi.o  syntax.o  getchar.o  blowfish.o  eval.o  sha256.o  netbeans.o  ops.o  search.o  regexp_nfa.o  normal.o  undo.o  quickfix.o  option.o  ex_eval.o  ex_cmds2.o  ex_docmd.o  os_unix.o  edit.o  hashtab.o  tag.o  xxd/xxd.o  main.o  arabic.o  ex_cmds.o  version.o  mark.o  gui_beval.o  mbyte.o  digraph.o  hardcopy.o  
	gcc -std=gnu99 -o Individual.x main.o InterfaceWithCoreFeature.o spell.o  misc2.o  charset.o  regexp.o  misc1.o  ui.o  gui_mac.o  gui.o  term.o  move.o  screen.o  os_amiga.o  window.o  diff.o  fileio.o  message.o  memfile.o  memline.o  buffer.o  ex_getln.o  menu.o  farsi.o  syntax.o  getchar.o  blowfish.o  eval.o  sha256.o  netbeans.o  ops.o  search.o  regexp_nfa.o  normal.o  undo.o  quickfix.o  option.o  ex_eval.o  ex_cmds2.o  ex_docmd.o  os_unix.o  edit.o  hashtab.o  tag.o  xxd/xxd.o  main.o  arabic.o  ex_cmds.o  version.o  mark.o  gui_beval.o  mbyte.o  digraph.o  hardcopy.o   -lm $(CHECKPACKAGE) $(CFLAGS)

main.o:	main.c
	gcc -std=gnu99 -c -o main.o main.c $(CFLAGS)

InterfaceWithCoreFeature.o:	InterfaceHeader.h InterfaceWithCoreFeature.c
	gcc -std=gnu99 -c -o InterfaceWithCoreFeature.o InterfaceWithCoreFeature.c $(CFLAGS)

spell.o :	InterfaceHeader.h spell.c
	gcc -std=gnu99 -c -o spell.o  spell.c $(CFLAGS)

misc2.o :	InterfaceHeader.h misc2.c
	gcc -std=gnu99 -c -o misc2.o  misc2.c $(CFLAGS)

charset.o :	InterfaceHeader.h charset.c
	gcc -std=gnu99 -c -o charset.o  charset.c $(CFLAGS)

regexp.o :	InterfaceHeader.h regexp.c
	gcc -std=gnu99 -c -o regexp.o  regexp.c $(CFLAGS)

misc1.o :	InterfaceHeader.h misc1.c
	gcc -std=gnu99 -c -o misc1.o  misc1.c $(CFLAGS)

ui.o :	InterfaceHeader.h ui.c
	gcc -std=gnu99 -c -o ui.o  ui.c $(CFLAGS)

gui_mac.o :	InterfaceHeader.h gui_mac.c
	gcc -std=gnu99 -c -o gui_mac.o  gui_mac.c $(CFLAGS)

gui.o :	InterfaceHeader.h gui.c
	gcc -std=gnu99 -c -o gui.o  gui.c $(CFLAGS)

term.o :	InterfaceHeader.h term.c
	gcc -std=gnu99 -c -o term.o  term.c $(CFLAGS)

move.o :	InterfaceHeader.h move.c
	gcc -std=gnu99 -c -o move.o  move.c $(CFLAGS)

screen.o :	InterfaceHeader.h screen.c
	gcc -std=gnu99 -c -o screen.o  screen.c $(CFLAGS)

os_amiga.o :	InterfaceHeader.h os_amiga.c
	gcc -std=gnu99 -c -o os_amiga.o  os_amiga.c $(CFLAGS)

window.o :	InterfaceHeader.h window.c
	gcc -std=gnu99 -c -o window.o  window.c $(CFLAGS)

diff.o :	InterfaceHeader.h diff.c
	gcc -std=gnu99 -c -o diff.o  diff.c $(CFLAGS)

fileio.o :	InterfaceHeader.h fileio.c
	gcc -std=gnu99 -c -o fileio.o  fileio.c $(CFLAGS)

message.o :	InterfaceHeader.h message.c
	gcc -std=gnu99 -c -o message.o  message.c $(CFLAGS)

memfile.o :	InterfaceHeader.h memfile.c
	gcc -std=gnu99 -c -o memfile.o  memfile.c $(CFLAGS)

memline.o :	InterfaceHeader.h memline.c
	gcc -std=gnu99 -c -o memline.o  memline.c $(CFLAGS)

buffer.o :	InterfaceHeader.h buffer.c
	gcc -std=gnu99 -c -o buffer.o  buffer.c $(CFLAGS)

ex_getln.o :	InterfaceHeader.h ex_getln.c
	gcc -std=gnu99 -c -o ex_getln.o  ex_getln.c $(CFLAGS)

menu.o :	InterfaceHeader.h menu.c
	gcc -std=gnu99 -c -o menu.o  menu.c $(CFLAGS)

farsi.o :	InterfaceHeader.h farsi.c
	gcc -std=gnu99 -c -o farsi.o  farsi.c $(CFLAGS)

syntax.o :	InterfaceHeader.h syntax.c
	gcc -std=gnu99 -c -o syntax.o  syntax.c $(CFLAGS)

getchar.o :	InterfaceHeader.h getchar.c
	gcc -std=gnu99 -c -o getchar.o  getchar.c $(CFLAGS)

blowfish.o :	InterfaceHeader.h blowfish.c
	gcc -std=gnu99 -c -o blowfish.o  blowfish.c $(CFLAGS)

eval.o :	InterfaceHeader.h eval.c
	gcc -std=gnu99 -c -o eval.o  eval.c $(CFLAGS)

sha256.o :	InterfaceHeader.h sha256.c
	gcc -std=gnu99 -c -o sha256.o  sha256.c $(CFLAGS)

netbeans.o :	InterfaceHeader.h netbeans.c
	gcc -std=gnu99 -c -o netbeans.o  netbeans.c $(CFLAGS)

ops.o :	InterfaceHeader.h ops.c
	gcc -std=gnu99 -c -o ops.o  ops.c $(CFLAGS)

search.o :	InterfaceHeader.h search.c
	gcc -std=gnu99 -c -o search.o  search.c $(CFLAGS)

regexp_nfa.o :	InterfaceHeader.h regexp_nfa.c
	gcc -std=gnu99 -c -o regexp_nfa.o  regexp_nfa.c $(CFLAGS)

normal.o :	InterfaceHeader.h normal.c
	gcc -std=gnu99 -c -o normal.o  normal.c $(CFLAGS)

undo.o :	InterfaceHeader.h undo.c
	gcc -std=gnu99 -c -o undo.o  undo.c $(CFLAGS)

quickfix.o :	InterfaceHeader.h quickfix.c
	gcc -std=gnu99 -c -o quickfix.o  quickfix.c $(CFLAGS)

option.o :	InterfaceHeader.h option.c
	gcc -std=gnu99 -c -o option.o  option.c $(CFLAGS)

ex_eval.o :	InterfaceHeader.h ex_eval.c
	gcc -std=gnu99 -c -o ex_eval.o  ex_eval.c $(CFLAGS)

ex_cmds2.o :	InterfaceHeader.h ex_cmds2.c
	gcc -std=gnu99 -c -o ex_cmds2.o  ex_cmds2.c $(CFLAGS)

ex_docmd.o :	InterfaceHeader.h ex_docmd.c
	gcc -std=gnu99 -c -o ex_docmd.o  ex_docmd.c $(CFLAGS)

os_unix.o :	InterfaceHeader.h os_unix.c
	gcc -std=gnu99 -c -o os_unix.o  os_unix.c $(CFLAGS)

edit.o :	InterfaceHeader.h edit.c
	gcc -std=gnu99 -c -o edit.o  edit.c $(CFLAGS)

hashtab.o :	InterfaceHeader.h hashtab.c
	gcc -std=gnu99 -c -o hashtab.o  hashtab.c $(CFLAGS)

tag.o :	InterfaceHeader.h tag.c
	gcc -std=gnu99 -c -o tag.o  tag.c $(CFLAGS)

xxd/xxd.o :	InterfaceHeader.h xxd/xxd.c
	gcc -std=gnu99 -c -o xxd/xxd.o  xxd/xxd.c $(CFLAGS)

main.o :	InterfaceHeader.h main.c
	gcc -std=gnu99 -c -o main.o  main.c $(CFLAGS)

arabic.o :	InterfaceHeader.h arabic.c
	gcc -std=gnu99 -c -o arabic.o  arabic.c $(CFLAGS)

ex_cmds.o :	InterfaceHeader.h ex_cmds.c
	gcc -std=gnu99 -c -o ex_cmds.o  ex_cmds.c $(CFLAGS)

version.o :	InterfaceHeader.h version.c
	gcc -std=gnu99 -c -o version.o  version.c $(CFLAGS)

mark.o :	InterfaceHeader.h mark.c
	gcc -std=gnu99 -c -o mark.o  mark.c $(CFLAGS)

gui_beval.o :	InterfaceHeader.h gui_beval.c
	gcc -std=gnu99 -c -o gui_beval.o  gui_beval.c $(CFLAGS)

mbyte.o :	InterfaceHeader.h mbyte.c
	gcc -std=gnu99 -c -o mbyte.o  mbyte.c $(CFLAGS)

digraph.o :	InterfaceHeader.h digraph.c
	gcc -std=gnu99 -c -o digraph.o  digraph.c $(CFLAGS)

hardcopy.o :	InterfaceHeader.h hardcopy.c
	gcc -std=gnu99 -c -o hardcopy.o  hardcopy.c $(CFLAGS)

