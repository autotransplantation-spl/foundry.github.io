CFLAGS = -I ../Host/macvim/src/ `pkg-config --cflags glib-2.0` `pkg-config --libs glib-2.0`

CHECKPACKAGE = `pkg-config --cflags --libs check`

Individual.x:	main.o InterfaceWithCoreFeature.o spell.o  misc2.o  charset.o  os_w32exe.o  mbyte.o  regexp.o  misc1.o  ui.o  gui_mac.o  gui.o  term.o  popupmnu.o  move.o  fold.o  memline.o  memfile.o  os_amiga.o  message.o  fileio.o  eval.o  os_unix.o  edit.o  list.o  userfunc.o  hashtab.o  dict.o  channel.o  ex_cmds2.o  gui_xmdlg.o  screen.o  window.o  diff.o  os_win32.o  winclip.o  os_mac_conv.o  ex_docmd.o  ex_eval.o  gui_w32.o  ex_cmds.o  farsi.o  syntax.o  termlib.o  menu.o  getchar.o  netbeans.o  terminal.o  ex_getln.o  search.o  evalfunc.o  ops.o  buffer.o  option.o  regexp_nfa.o  normal.o  crypt.o  sha256.o  gui_athena.o  gui_at_sb.o  integration.o  gui_photon.o  quickfix.o  undo.o  os_mswin.o  digraph.o  if_ruby.o  libvterm/src/screen.o  libvterm/src/vterm.o  libvterm/src/state.o  arabic.o  gui_motif.o  mark.o  main.o  xxd/xxd.o  spellfile.o  gui_x11.o  tag.o  gui_gtk.o  beval.o  libvterm/src/pen.o  libvterm/src/encoding.o  hardcopy.o  version.o  libvterm/src/mouse.o  if_xcmdsrv.o  json.o  libvterm/src/parser.o  libvterm/t/harness.o  
	gcc -std=gnu99 -o Individual.x main.o InterfaceWithCoreFeature.o spell.o  misc2.o  charset.o  os_w32exe.o  mbyte.o  regexp.o  misc1.o  ui.o  gui_mac.o  gui.o  term.o  popupmnu.o  move.o  fold.o  memline.o  memfile.o  os_amiga.o  message.o  fileio.o  eval.o  os_unix.o  edit.o  list.o  userfunc.o  hashtab.o  dict.o  channel.o  ex_cmds2.o  gui_xmdlg.o  screen.o  window.o  diff.o  os_win32.o  winclip.o  os_mac_conv.o  ex_docmd.o  ex_eval.o  gui_w32.o  ex_cmds.o  farsi.o  syntax.o  termlib.o  menu.o  getchar.o  netbeans.o  terminal.o  ex_getln.o  search.o  evalfunc.o  ops.o  buffer.o  option.o  regexp_nfa.o  normal.o  crypt.o  sha256.o  gui_athena.o  gui_at_sb.o  integration.o  gui_photon.o  quickfix.o  undo.o  os_mswin.o  digraph.o  if_ruby.o  libvterm/src/screen.o  libvterm/src/vterm.o  libvterm/src/state.o  arabic.o  gui_motif.o  mark.o  main.o  xxd/xxd.o  spellfile.o  gui_x11.o  tag.o  gui_gtk.o  beval.o  libvterm/src/pen.o  libvterm/src/encoding.o  hardcopy.o  version.o  libvterm/src/mouse.o  if_xcmdsrv.o  json.o  libvterm/src/parser.o  libvterm/t/harness.o   -lm $(CHECKPACKAGE) $(CFLAGS)

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

os_w32exe.o :	InterfaceHeader.h os_w32exe.c
	gcc -std=gnu99 -c -o os_w32exe.o  os_w32exe.c $(CFLAGS)

mbyte.o :	InterfaceHeader.h mbyte.c
	gcc -std=gnu99 -c -o mbyte.o  mbyte.c $(CFLAGS)

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

popupmnu.o :	InterfaceHeader.h popupmnu.c
	gcc -std=gnu99 -c -o popupmnu.o  popupmnu.c $(CFLAGS)

move.o :	InterfaceHeader.h move.c
	gcc -std=gnu99 -c -o move.o  move.c $(CFLAGS)

fold.o :	InterfaceHeader.h fold.c
	gcc -std=gnu99 -c -o fold.o  fold.c $(CFLAGS)

memline.o :	InterfaceHeader.h memline.c
	gcc -std=gnu99 -c -o memline.o  memline.c $(CFLAGS)

memfile.o :	InterfaceHeader.h memfile.c
	gcc -std=gnu99 -c -o memfile.o  memfile.c $(CFLAGS)

os_amiga.o :	InterfaceHeader.h os_amiga.c
	gcc -std=gnu99 -c -o os_amiga.o  os_amiga.c $(CFLAGS)

message.o :	InterfaceHeader.h message.c
	gcc -std=gnu99 -c -o message.o  message.c $(CFLAGS)

fileio.o :	InterfaceHeader.h fileio.c
	gcc -std=gnu99 -c -o fileio.o  fileio.c $(CFLAGS)

eval.o :	InterfaceHeader.h eval.c
	gcc -std=gnu99 -c -o eval.o  eval.c $(CFLAGS)

os_unix.o :	InterfaceHeader.h os_unix.c
	gcc -std=gnu99 -c -o os_unix.o  os_unix.c $(CFLAGS)

edit.o :	InterfaceHeader.h edit.c
	gcc -std=gnu99 -c -o edit.o  edit.c $(CFLAGS)

list.o :	InterfaceHeader.h list.c
	gcc -std=gnu99 -c -o list.o  list.c $(CFLAGS)

userfunc.o :	InterfaceHeader.h userfunc.c
	gcc -std=gnu99 -c -o userfunc.o  userfunc.c $(CFLAGS)

hashtab.o :	InterfaceHeader.h hashtab.c
	gcc -std=gnu99 -c -o hashtab.o  hashtab.c $(CFLAGS)

dict.o :	InterfaceHeader.h dict.c
	gcc -std=gnu99 -c -o dict.o  dict.c $(CFLAGS)

channel.o :	InterfaceHeader.h channel.c
	gcc -std=gnu99 -c -o channel.o  channel.c $(CFLAGS)

ex_cmds2.o :	InterfaceHeader.h ex_cmds2.c
	gcc -std=gnu99 -c -o ex_cmds2.o  ex_cmds2.c $(CFLAGS)

gui_xmdlg.o :	InterfaceHeader.h gui_xmdlg.c
	gcc -std=gnu99 -c -o gui_xmdlg.o  gui_xmdlg.c $(CFLAGS)

screen.o :	InterfaceHeader.h screen.c
	gcc -std=gnu99 -c -o screen.o  screen.c $(CFLAGS)

window.o :	InterfaceHeader.h window.c
	gcc -std=gnu99 -c -o window.o  window.c $(CFLAGS)

diff.o :	InterfaceHeader.h diff.c
	gcc -std=gnu99 -c -o diff.o  diff.c $(CFLAGS)

os_win32.o :	InterfaceHeader.h os_win32.c
	gcc -std=gnu99 -c -o os_win32.o  os_win32.c $(CFLAGS)

winclip.o :	InterfaceHeader.h winclip.c
	gcc -std=gnu99 -c -o winclip.o  winclip.c $(CFLAGS)

os_mac_conv.o :	InterfaceHeader.h os_mac_conv.c
	gcc -std=gnu99 -c -o os_mac_conv.o  os_mac_conv.c $(CFLAGS)

ex_docmd.o :	InterfaceHeader.h ex_docmd.c
	gcc -std=gnu99 -c -o ex_docmd.o  ex_docmd.c $(CFLAGS)

ex_eval.o :	InterfaceHeader.h ex_eval.c
	gcc -std=gnu99 -c -o ex_eval.o  ex_eval.c $(CFLAGS)

gui_w32.o :	InterfaceHeader.h gui_w32.c
	gcc -std=gnu99 -c -o gui_w32.o  gui_w32.c $(CFLAGS)

ex_cmds.o :	InterfaceHeader.h ex_cmds.c
	gcc -std=gnu99 -c -o ex_cmds.o  ex_cmds.c $(CFLAGS)

farsi.o :	InterfaceHeader.h farsi.c
	gcc -std=gnu99 -c -o farsi.o  farsi.c $(CFLAGS)

syntax.o :	InterfaceHeader.h syntax.c
	gcc -std=gnu99 -c -o syntax.o  syntax.c $(CFLAGS)

termlib.o :	InterfaceHeader.h termlib.c
	gcc -std=gnu99 -c -o termlib.o  termlib.c $(CFLAGS)

menu.o :	InterfaceHeader.h menu.c
	gcc -std=gnu99 -c -o menu.o  menu.c $(CFLAGS)

getchar.o :	InterfaceHeader.h getchar.c
	gcc -std=gnu99 -c -o getchar.o  getchar.c $(CFLAGS)

netbeans.o :	InterfaceHeader.h netbeans.c
	gcc -std=gnu99 -c -o netbeans.o  netbeans.c $(CFLAGS)

terminal.o :	InterfaceHeader.h terminal.c
	gcc -std=gnu99 -c -o terminal.o  terminal.c $(CFLAGS)

ex_getln.o :	InterfaceHeader.h ex_getln.c
	gcc -std=gnu99 -c -o ex_getln.o  ex_getln.c $(CFLAGS)

search.o :	InterfaceHeader.h search.c
	gcc -std=gnu99 -c -o search.o  search.c $(CFLAGS)

evalfunc.o :	InterfaceHeader.h evalfunc.c
	gcc -std=gnu99 -c -o evalfunc.o  evalfunc.c $(CFLAGS)

ops.o :	InterfaceHeader.h ops.c
	gcc -std=gnu99 -c -o ops.o  ops.c $(CFLAGS)

buffer.o :	InterfaceHeader.h buffer.c
	gcc -std=gnu99 -c -o buffer.o  buffer.c $(CFLAGS)

option.o :	InterfaceHeader.h option.c
	gcc -std=gnu99 -c -o option.o  option.c $(CFLAGS)

regexp_nfa.o :	InterfaceHeader.h regexp_nfa.c
	gcc -std=gnu99 -c -o regexp_nfa.o  regexp_nfa.c $(CFLAGS)

normal.o :	InterfaceHeader.h normal.c
	gcc -std=gnu99 -c -o normal.o  normal.c $(CFLAGS)

crypt.o :	InterfaceHeader.h crypt.c
	gcc -std=gnu99 -c -o crypt.o  crypt.c $(CFLAGS)

sha256.o :	InterfaceHeader.h sha256.c
	gcc -std=gnu99 -c -o sha256.o  sha256.c $(CFLAGS)

gui_athena.o :	InterfaceHeader.h gui_athena.c
	gcc -std=gnu99 -c -o gui_athena.o  gui_athena.c $(CFLAGS)

gui_at_sb.o :	InterfaceHeader.h gui_at_sb.c
	gcc -std=gnu99 -c -o gui_at_sb.o  gui_at_sb.c $(CFLAGS)

integration.o :	InterfaceHeader.h integration.c
	gcc -std=gnu99 -c -o integration.o  integration.c $(CFLAGS)

gui_photon.o :	InterfaceHeader.h gui_photon.c
	gcc -std=gnu99 -c -o gui_photon.o  gui_photon.c $(CFLAGS)

quickfix.o :	InterfaceHeader.h quickfix.c
	gcc -std=gnu99 -c -o quickfix.o  quickfix.c $(CFLAGS)

undo.o :	InterfaceHeader.h undo.c
	gcc -std=gnu99 -c -o undo.o  undo.c $(CFLAGS)

os_mswin.o :	InterfaceHeader.h os_mswin.c
	gcc -std=gnu99 -c -o os_mswin.o  os_mswin.c $(CFLAGS)

digraph.o :	InterfaceHeader.h digraph.c
	gcc -std=gnu99 -c -o digraph.o  digraph.c $(CFLAGS)

if_ruby.o :	InterfaceHeader.h if_ruby.c
	gcc -std=gnu99 -c -o if_ruby.o  if_ruby.c $(CFLAGS)

libvterm/src/screen.o :	InterfaceHeader.h libvterm/src/screen.c
	gcc -std=gnu99 -c -o libvterm/src/screen.o  libvterm/src/screen.c $(CFLAGS)

libvterm/src/vterm.o :	InterfaceHeader.h libvterm/src/vterm.c
	gcc -std=gnu99 -c -o libvterm/src/vterm.o  libvterm/src/vterm.c $(CFLAGS)

libvterm/src/state.o :	InterfaceHeader.h libvterm/src/state.c
	gcc -std=gnu99 -c -o libvterm/src/state.o  libvterm/src/state.c $(CFLAGS)

arabic.o :	InterfaceHeader.h arabic.c
	gcc -std=gnu99 -c -o arabic.o  arabic.c $(CFLAGS)

gui_motif.o :	InterfaceHeader.h gui_motif.c
	gcc -std=gnu99 -c -o gui_motif.o  gui_motif.c $(CFLAGS)

mark.o :	InterfaceHeader.h mark.c
	gcc -std=gnu99 -c -o mark.o  mark.c $(CFLAGS)

main.o :	InterfaceHeader.h main.c
	gcc -std=gnu99 -c -o main.o  main.c $(CFLAGS)

xxd/xxd.o :	InterfaceHeader.h xxd/xxd.c
	gcc -std=gnu99 -c -o xxd/xxd.o  xxd/xxd.c $(CFLAGS)

spellfile.o :	InterfaceHeader.h spellfile.c
	gcc -std=gnu99 -c -o spellfile.o  spellfile.c $(CFLAGS)

gui_x11.o :	InterfaceHeader.h gui_x11.c
	gcc -std=gnu99 -c -o gui_x11.o  gui_x11.c $(CFLAGS)

tag.o :	InterfaceHeader.h tag.c
	gcc -std=gnu99 -c -o tag.o  tag.c $(CFLAGS)

gui_gtk.o :	InterfaceHeader.h gui_gtk.c
	gcc -std=gnu99 -c -o gui_gtk.o  gui_gtk.c $(CFLAGS)

beval.o :	InterfaceHeader.h beval.c
	gcc -std=gnu99 -c -o beval.o  beval.c $(CFLAGS)

libvterm/src/pen.o :	InterfaceHeader.h libvterm/src/pen.c
	gcc -std=gnu99 -c -o libvterm/src/pen.o  libvterm/src/pen.c $(CFLAGS)

libvterm/src/encoding.o :	InterfaceHeader.h libvterm/src/encoding.c
	gcc -std=gnu99 -c -o libvterm/src/encoding.o  libvterm/src/encoding.c $(CFLAGS)

hardcopy.o :	InterfaceHeader.h hardcopy.c
	gcc -std=gnu99 -c -o hardcopy.o  hardcopy.c $(CFLAGS)

version.o :	InterfaceHeader.h version.c
	gcc -std=gnu99 -c -o version.o  version.c $(CFLAGS)

libvterm/src/mouse.o :	InterfaceHeader.h libvterm/src/mouse.c
	gcc -std=gnu99 -c -o libvterm/src/mouse.o  libvterm/src/mouse.c $(CFLAGS)

if_xcmdsrv.o :	InterfaceHeader.h if_xcmdsrv.c
	gcc -std=gnu99 -c -o if_xcmdsrv.o  if_xcmdsrv.c $(CFLAGS)

json.o :	InterfaceHeader.h json.c
	gcc -std=gnu99 -c -o json.o  json.c $(CFLAGS)

libvterm/src/parser.o :	InterfaceHeader.h libvterm/src/parser.c
	gcc -std=gnu99 -c -o libvterm/src/parser.o  libvterm/src/parser.c $(CFLAGS)

libvterm/t/harness.o :	InterfaceHeader.h libvterm/t/harness.c
	gcc -std=gnu99 -c -o libvterm/t/harness.o  libvterm/t/harness.c $(CFLAGS)

