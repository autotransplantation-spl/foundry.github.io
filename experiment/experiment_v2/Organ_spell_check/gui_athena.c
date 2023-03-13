
#include "InterfaceHeader.h"
XtIntervalId timer = 0;
XtTranslations parentTrans;
XtTranslations menuTrans;
XtTranslations supermenuTrans;
XtTranslations popupTrans;
vimmenu_T *a_cur_menu = NULL;
Pixmap pullerBitmap = None;
Atom dialogatom;
int dialogStatus;
int puller_width = 0;
Widget toolBar = (Widget) 0;
Widget menuBar = (Widget) 0;
Widget vimForm = (Widget) 0;
Widget textArea = (Widget) 0;

void gui_mch_set_text_area_pos (int x, int y, int w, int h) {
    XtUnmanageChild (textArea);
    XtVaSetValues (textArea, XtNhorizDistance, x, XtNvertDistance, y, XtNwidth, w, XtNheight, h, NULL);
    XtManageChild (textArea);
    gui_mch_reset_focus ();
}

static void gui_mch_reset_focus (void) {
    XtSetKeyboardFocus (vimForm, textArea);
}

void gui_mch_set_menu_pos (int x, int y, int w, int h) {
    Dimension border;
    int height;
    XtUnmanageChild (menuBar);
    XtVaGetValues (menuBar, XtNborderWidth, & border, NULL);
    height = h - 2 * border;
    if (height < 0)
        height = 1;
    XtVaSetValues (menuBar, XtNhorizDistance, x, XtNvertDistance, y, XtNwidth, w - 2 * border, XtNheight, height, NULL);
    XtManageChild (menuBar);
}

void gui_mch_set_scrollbar_pos (scrollbar_T *sb, int x, int y, int w, int h) {
    if (sb->id == (Widget) 0)
        return;
    XtUnmanageChild (sb -> id);
    XtVaSetValues (sb -> id, XtNhorizDistance, x, XtNvertDistance, y, XtNwidth, w, XtNheight, h, NULL);
    XtManageChild (sb -> id);
}

void gui_mch_set_scrollbar_thumb (scrollbar_T *sb, long  val, long  size, long  max) {
    double v, s;
    if (sb->id == (Widget) 0)
        return;
    if (max == 0) {
        vim_XawScrollbarSetThumb (sb -> id, 0.0, 1.0, 0.0);
    }
    else {
        v = (double) val / (double) (max + 1);
        s = (double) size / (double) (max + 1);
        vim_XawScrollbarSetThumb (sb -> id, v, s, 1.0);
    }
}

void gui_mch_enable_scrollbar (scrollbar_T *sb, int flag) {
    if (sb->id != (Widget) 0) {
        if (flag)
            XtManageChild (sb->id);
        else
            XtUnmanageChild (sb->id);
    }
}

void gui_mch_enable_menu (int flag) {
    if (flag) {
        XtManageChild (menuBar);
        if (XtIsManaged (toolBar)) {
            XtVaSetValues (toolBar, XtNvertDistance, gui.menu_height, NULL);
            XtVaSetValues (textArea, XtNvertDistance, gui.menu_height + gui.toolbar_height, NULL);
        }
    }
    else {
        XtUnmanageChild (menuBar);
        if (XtIsManaged (toolBar)) {
            XtVaSetValues (toolBar, XtNvertDistance, 0, NULL);
        }
    }
}

void gui_mch_show_toolbar (int showit) {
    Cardinal numChildren;
    if (toolBar == (Widget) 0)
        return;
    XtVaGetValues (toolBar, XtNnumChildren, & numChildren, NULL);
    if (showit && numChildren > 0) {
        WidgetList children;
        XtVaGetValues (toolBar, XtNchildren, & children, NULL);
        {
            void (*action) (BalloonEval *);
            int text = 0;
            if (strstr ((const char *) p_toolbar, "tooltips"))
                action = &gui_mch_enable_beval_area;
            else
                action = &gui_mch_disable_beval_area;
            if (strstr ((const char *) p_toolbar, "text"))
                text = 1;
            else if (strstr ((const char *) p_toolbar, "icons"))
                text = -1;
            if (text != 0) {
                vimmenu_T *toolbar;
                vimmenu_T *cur;
                for (toolbar = root_menu; toolbar; toolbar = toolbar->next)
                    if (menu_is_toolbar (toolbar->dname))
                        break;
                if (toolbar) {
                    for (cur = toolbar->children; cur; cur = cur->next) {
                        Arg args [2];
                        int n = 0;
                        if (cur->tip != NULL)
                            (*action) (cur->tip);
                        if (text == 1) {
                            XtSetArg (args [n], XtNbitmap, None);
                            n++;
                            XtSetArg (args [n], XtNlabel, menu_is_separator (cur -> name) ? "" : (char *) cur -> dname);
                            n++;
                        }
                        else {
                            XtSetArg (args [n], XtNbitmap, cur -> image);
                            n++;
                            XtSetArg (args [n], XtNlabel, (cur -> image == None) ? menu_is_separator (cur -> name) ? "" : (char *) cur -> dname : (char *) None);
                            n++;
                        }
                        if (cur->id != NULL) {
                            XtUnmanageChild (cur -> id);
                            XtSetValues (cur -> id, args, n);
                            XtManageChild (cur -> id);
                        }
                    }
                }
            }
        }
        gui.toolbar_height = gui_mch_compute_toolbar_height ();
        XtManageChild (toolBar);
        if (XtIsManaged (menuBar)) {
            XtVaSetValues (textArea, XtNvertDistance, gui.toolbar_height + gui.menu_height, NULL);
            XtVaSetValues (toolBar, XtNvertDistance, gui.menu_height, NULL);
        }
        else {
            XtVaSetValues (textArea, XtNvertDistance, gui.toolbar_height, NULL);
            XtVaSetValues (toolBar, XtNvertDistance, 0, NULL);
        }
    }
    else {
        gui.toolbar_height = 0;
        if (XtIsManaged (menuBar))
            XtVaSetValues (textArea, XtNvertDistance, gui.menu_height, NULL);
        else
            XtVaSetValues (textArea, XtNvertDistance, 0, NULL);
        XtUnmanageChild (toolBar);
    }
    gui_set_shellsize (FALSE, FALSE, RESIZE_VERT);
}

int gui_mch_compute_toolbar_height (void) {
    Dimension height;
    Dimension whgt;
    Dimension marginHeight;
    Dimension shadowThickness;
    WidgetList children;
    Cardinal numChildren;
    int i;
    height = 0;
    shadowThickness = 0;
    marginHeight = 0;
    if (toolBar != (Widget) 0) {
        XtVaGetValues (toolBar, XtNborderWidth, & shadowThickness, XtNvSpace, & marginHeight, XtNchildren, & children, XtNnumChildren, & numChildren, NULL);
        for (i = 0; i < (int) numChildren; i++) {
            whgt = 0;
            XtVaGetValues (children [i], XtNheight, & whgt, NULL);
            if (height < whgt)
                height = whgt;
        }
    }
    return (int) (height + (marginHeight << 1) + (shadowThickness << 1));
}

void gui_mch_toggle_tearoffs (int enable) {
}

void gui_mch_create_scrollbar (scrollbar_T *sb, int orient) {
    sb->id = XtVaCreateWidget ("scrollBar", vim_scrollbarWidgetClass, vimForm, XtNresizable, True, XtNtop, XtChainTop, XtNbottom, XtChainTop, XtNleft, XtChainLeft, XtNright, XtChainLeft, XtNborderWidth, 0, XtNorientation, (orient == SBAR_VERT) ? XtorientVertical : XtorientHorizontal, XtNforeground, gui.scroll_fg_pixel, XtNbackground, gui.scroll_bg_pixel, NULL);
    if (sb->id == (Widget) 0)
        return;
    XtAddCallback (sb -> id, XtNjumpProc, gui_athena_scroll_cb_jump, (XtPointer) sb -> ident);
    XtAddCallback (sb -> id, XtNscrollProc, gui_athena_scroll_cb_scroll, (XtPointer) sb -> ident);
    vim_XawScrollbarSetThumb (sb -> id, 0.0, 1.0, 0.0);
}

static void gui_athena_scroll_cb_jump (Widget w, XtPointer client_data, XtPointer call_data) {
    scrollbar_T *sb, *sb_info;
    long  value;
    sb = gui_find_scrollbar ((long ) client_data);
    if (sb == NULL)
        return;
    else if (sb->wp != NULL) {
        sb_info = &sb->wp->w_scrollbars[0];
    }
    else
        sb_info = sb;
    value = (long ) (*((float *) call_data) * (float) (sb_info->max + 1) + 0.001);
    if (value > sb_info->max)
        value = sb_info->max;
    gui_drag_scrollbar (sb, value, TRUE);
}

static void gui_athena_scroll_cb_scroll (Widget w, XtPointer client_data, XtPointer call_data) {
    scrollbar_T *sb, *sb_info;
    long  value;
    int data = (int) (long ) call_data;
    int page;
    sb = gui_find_scrollbar ((long ) client_data);
    if (sb == NULL)
        return;
    if (sb->wp != NULL) {
        sb_info = &sb->wp->w_scrollbars[0];
        if (sb_info->size > 5)
            page = sb_info->size - 2;
        else
            page = sb_info->size;
        switch (data) {
        case ONE_LINE_DATA :
            data = 1;
            break;
        case -ONE_LINE_DATA :
            data = -1;
            break;
        case ONE_PAGE_DATA :
            data = page;
            break;
        case -ONE_PAGE_DATA :
            data = -page;
            break;
        case END_PAGE_DATA :
            data = sb_info->max;
            break;
        case -END_PAGE_DATA :
            data = -sb_info->max;
            break;
        default :
            data = 0;
            break;
        }
    }
    else {
        sb_info = sb;
        if (data < -1) {
            if (sb->size > 8)
                data = -(sb->size - 5);
            else
                data = -sb->size;
        }
        else if (data > 1) {
            if (sb->size > 8)
                data = (sb->size - 5);
            else
                data = sb->size;
        }
    }
    value = sb_info->value + data;
    if (value > sb_info->max)
        value = sb_info->max;
    else if (value < 0)
        value = 0;
    if (sb->wp == NULL)
        gui_mch_set_scrollbar_thumb (sb, value, sb->size, sb->max);
    gui_drag_scrollbar (sb, value, FALSE);
}

void gui_mch_destroy_scrollbar (scrollbar_T *sb) {
    if (sb->id != (Widget) 0)
        XtDestroyWidget (sb->id);
}

void gui_mch_destroy_menu (vimmenu_T *menu) {
    Widget parent;
    if (menu->id == (Widget) 0)
        return;
    parent = XtParent (menu->id);
    if (menu->submenu_id != (Widget) 0) {
        {
            WidgetList children;
            Cardinal num_children;
            int i;
            Dimension right_margin = 0;
            Boolean get_left_margin = False;
            XtVaGetValues (parent, XtNchildren, & children, XtNnumChildren, & num_children, NULL);
            if (gui_athena_menu_has_submenus (parent, menu->id))
                right_margin = puller_width;
            else
                get_left_margin = True;
            for (i = 0; i < (int) num_children; ++i) {
                if (children[i] == menu->id)
                    continue;
                if (get_left_margin == True) {
                    Dimension left_margin;
                    XtVaGetValues (children [i], XtNleftMargin, & left_margin, NULL);
                    XtVaSetValues (children [i], XtNrightMargin, left_margin, NULL);
                }
                else
                    XtVaSetValues (children[i], XtNrightMargin, right_margin, NULL);
            }
        }
    }
    if (menu->id != (Widget) 0) {
        Cardinal num_children;
        Dimension height, space, border;
        XtVaGetValues (menuBar, XtNvSpace, & space, XtNborderWidth, & border, NULL);
        XtVaGetValues (menu -> id, XtNheight, & height, NULL);
        if (parent == toolBar && menu->tip != NULL) {
            gui_mch_destroy_beval_area (menu -> tip);
            menu->tip = NULL;
        }
        {
            if (parent != menuBar && parent != toolBar) {
                XtVaGetValues (parent, XtNnumChildren, & num_children, NULL);
                if (num_children > 1)
                    XtDestroyWidget (menu->id);
            }
            else
                XtDestroyWidget (menu->id);
            menu->id = (Widget) 0;
        }
        if (parent == menuBar) {
            if (!gui.menu_height_fixed)
                gui.menu_height = height + 2 * (space + border);
        }
        else if (parent == toolBar) {
            XtVaGetValues (toolBar, XtNnumChildren, & num_children, NULL);
            if (num_children == 0)
                gui_mch_show_toolbar (FALSE);
            else
                gui.toolbar_height = gui_mch_compute_toolbar_height ();
        }
    }
    if (menu->submenu_id != (Widget) 0) {
        XtDestroyWidget (menu -> submenu_id);
        menu->submenu_id = (Widget) 0;
    }
}

static Boolean gui_athena_menu_has_submenus (Widget id, Widget ignore) {
    WidgetList children;
    Cardinal num_children;
    int i;
    XtVaGetValues (id, XtNchildren, & children, XtNnumChildren, & num_children, NULL);
    for (i = 0; i < (int) num_children; ++i) {
        if (children[i] == ignore)
            continue;
        if (has_submenu (children[i]))
            return True;
    }
    return False;
}

static Boolean has_submenu (Widget widget) {
    if ((widget != NULL) && XtIsSubclass (widget, smeBSBObjectClass)) {
        Pixmap p;
        XtVaGetValues (widget, XtNrightBitmap, & p, NULL);
        if ((p != None) && (p != XtUnspecifiedPixmap))
            return True;
    }
    return False;
}

int gui_mch_dialog (int type, char_u *title, char_u *message, char_u *buttons, int dfltbutton, char_u *textfield, int ex_cmd) {
    char_u *buts;
    char_u *p, *next;
    XtAppContext app;
    XEvent event;
    Position wd, hd;
    Position wv, hv;
    Position x, y;
    Widget dialog;
    Widget dialogshell;
    Widget dialogmessage;
    Widget dialogtextfield = 0;
    Widget dialogButton;
    Widget prev_dialogButton = NULL;
    int butcount;
    int vertical;
    if (title == NULL)
        title = (char_u *) _ ("Vim dialog");
    dialogStatus = -1;
    gui_mch_mousehide (FALSE);
    vertical = (vim_strchr (p_go, GO_VERTICAL) != NULL);
    dialogshell = XtVaCreatePopupShell ("dialogShell", transientShellWidgetClass, vimShell, XtNtitle, title, NULL);
    if (dialogshell == (Widget) 0)
        goto error;
    dialog = XtVaCreateManagedWidget ("dialog", formWidgetClass, dialogshell, XtNdefaultDistance, 20, NULL);
    if (dialog == (Widget) 0)
        goto error;
    gui_athena_menu_colors (dialog);
    dialogmessage = XtVaCreateManagedWidget ("dialogMessage", labelWidgetClass, dialog, XtNlabel, message, XtNtop, XtChainTop, XtNbottom, XtChainTop, XtNleft, XtChainLeft, XtNright, XtChainLeft, XtNresizable, True, XtNborderWidth, 0, NULL);
    gui_athena_menu_colors (dialogmessage);
    if (textfield != NULL) {
        dialogtextfield = XtVaCreateManagedWidget ("textfield", asciiTextWidgetClass, dialog, XtNwidth, 400, XtNtop, XtChainTop, XtNbottom, XtChainTop, XtNleft, XtChainLeft, XtNright, XtChainRight, XtNfromVert, dialogmessage, XtNresizable, True, XtNstring, textfield, XtNlength, IOSIZE, XtNuseStringInPlace, True, XtNeditType, XawtextEdit, XtNwrap, XawtextWrapNever, XtNresize, XawtextResizeHeight, NULL);
        XtManageChild (dialogtextfield);
        XtAddEventHandler (dialogtextfield, KeyPressMask, False, (XtEventHandler) keyhit_callback, (XtPointer) NULL);
        XawTextSetInsertionPoint (dialogtextfield, (XawTextPosition) STRLEN (textfield));
        XtSetKeyboardFocus (dialog, dialogtextfield);
    }
    buts = vim_strsave (buttons);
    if (buts == NULL)
        return -1;
    p = buts;
    for (butcount = 0; *p; ++butcount) {
        for (next = p; *next; ++next) {
            if (*next == DLG_HOTKEY_CHAR)
                STRMOVE (next, next +1);
            if (*next == DLG_BUTTON_SEP) {
                *next++ = NUL;
                break;
            }
        }
        dialogButton = XtVaCreateManagedWidget ("button", commandWidgetClass, dialog, XtNlabel, p, XtNtop, XtChainBottom, XtNbottom, XtChainBottom, XtNleft, XtChainLeft, XtNright, XtChainLeft, XtNfromVert, textfield == NULL ? dialogmessage : dialogtextfield, XtNvertDistance, vertical ? 4 : 20, XtNresizable, False, NULL);
        gui_athena_menu_colors (dialogButton);
        if (butcount > 0)
            XtVaSetValues (dialogButton, vertical ? XtNfromVert : XtNfromHoriz, prev_dialogButton, NULL);
        XtAddCallback (dialogButton, XtNcallback, butproc, (XtPointer) (long_u) butcount);
        p = next;
        prev_dialogButton = dialogButton;
    }
    vim_free (buts);
    XtRealizeWidget (dialogshell);
    dialogatom = XInternAtom (gui.dpy, "WM_DELETE_WINDOW", False);
    XSetWMProtocols (gui.dpy, XtWindow (dialogshell), & dialogatom, 1);
    XtAddEventHandler (dialogshell, NoEventMask, True, dialog_wm_handler, NULL);
    XtVaGetValues (dialogshell, XtNwidth, & wd, XtNheight, & hd, NULL);
    XtVaGetValues (vimShell, XtNwidth, & wv, XtNheight, & hv, NULL);
    XtTranslateCoords (vimShell, (Position) ((wv - wd) / 2), (Position) ((hv - hd) / 2), & x, & y);
    if (x < 0)
        x = 0;
    if (y < 0)
        y = 0;
    XtVaSetValues (dialogshell, XtNx, x, XtNy, y, NULL);
    XWarpPointer (gui.dpy, (Window) 0, XtWindow (dialogshell), 0, 0, 0, 0, 20, 40);
    app = XtWidgetToApplicationContext (dialogshell);
    XtPopup (dialogshell, XtGrabNonexclusive);
    for (;;) {
        XtAppNextEvent (app, & event);
        XtDispatchEvent (& event);
        if (dialogStatus >= 0)
            break;
    }
    XtPopdown (dialogshell);
    if (textfield != NULL && dialogStatus < 0)
        *textfield = NUL;
error :
    XtDestroyWidget (dialogshell);
    return dialogStatus;
}

static void gui_athena_menu_colors (Widget id) {
    if (gui.menu_bg_pixel != INVALCOLOR)
        XtVaSetValues (id, XtNbackground, gui.menu_bg_pixel, NULL);
    if (gui.menu_fg_pixel != INVALCOLOR)
        XtVaSetValues (id, XtNforeground, gui.menu_fg_pixel, NULL);
}

static void keyhit_callback (Widget w, XtPointer client_data, XEvent *event, Boolean *cont) {
    char buf [2];
    if (XLookupString (&(event->xkey), buf, 2, NULL, NULL) == 1) {
        if (*buf == CAR)
            dialogStatus = 1;
        else if (*buf == ESC)
            dialogStatus = 0;
    }
}

static void butproc (Widget w, XtPointer client_data, XtPointer call_data) {
    dialogStatus = (int) (long ) client_data + 1;
}

static void dialog_wm_handler (Widget w, XtPointer client_data, XEvent *event, Boolean *dum) {
    if (event->type == ClientMessage && (Atom) ((XClientMessageEvent *) event)->data.l[0] == dialogatom)
        dialogStatus = 0;
}

void gui_mch_new_menu_colors (void) {
    if (menuBar == (Widget) 0)
        return;
    if (gui.menu_fg_pixel != INVALCOLOR)
        XtVaSetValues (menuBar, XtNborderColor, gui.menu_fg_pixel, NULL);
    gui_athena_menu_colors (menuBar);
    gui_athena_menu_colors (toolBar);
    gui_mch_submenu_change (root_menu, TRUE);
}

static void gui_mch_submenu_change (vimmenu_T *menu, int colors) {
    vimmenu_T *mp;
    for (mp = menu; mp != NULL; mp = mp->next) {
        if (mp->id != (Widget) 0) {
            if (colors) {
                gui_athena_menu_colors (mp -> id);
                if (mp->image != (Pixmap) 0) {
                    XFreePixmap (gui.dpy, mp -> image);
                    get_toolbar_pixmap (mp, & mp -> image);
                    if (mp->image != (Pixmap) 0)
                        XtVaSetValues (mp->id, XtNbitmap, mp->image, NULL);
                }
                if (mp->tip != NULL) {
                    Arg args [2];
                    args[0].name = XtNbackground;
                    args[0].value = gui.tooltip_bg_pixel;
                    args[1].name = XtNforeground;
                    args[1].value = gui.tooltip_fg_pixel;
                    XtSetValues (mp -> tip -> balloonLabel, & args [0], XtNumber (args));
                }
            }
            else {
                gui_athena_menu_font (mp -> id);
                if (mp->tip != NULL) {
                    Arg args [1];
                    args[0].name = XtNfontSet;
                    args[0].value = (XtArgVal) gui.tooltip_fontset;
                    XtSetValues (mp -> tip -> balloonLabel, & args [0], XtNumber (args));
                }
            }
        }
        if (mp->children != NULL) {
            if (mp->submenu_id != (Widget) 0) {
                if (colors)
                    gui_athena_menu_colors (mp->submenu_id);
                else
                    gui_athena_menu_font (mp->submenu_id);
            }
            gui_mch_submenu_change (mp -> children, colors);
        }
    }
}

static void get_toolbar_pixmap (vimmenu_T *menu, Pixmap *sen) {
    char_u buf [MAXPATHL];
    char **xpm = NULL;
    buf[0] = NUL;
    if (menu->iconfile != NULL) {
        gui_find_iconfile (menu -> iconfile, buf, "xpm");
        createXpmImages (buf, NULL, sen);
        if (*sen == (Pixmap) 0 && gui_find_bitmap (menu->name, buf, "xpm") == OK)
            createXpmImages (buf, NULL, sen);
        if (*sen != (Pixmap) 0)
            return;
    }
    if (menu->icon_builtin || gui_find_bitmap (menu->name, buf, "xpm") == FAIL) {
        if (menu->iconidx >= 0 && menu->iconidx < (int) (sizeof (built_in_pixmaps) / sizeof (built_in_pixmaps[0])))
            xpm = built_in_pixmaps[menu->iconidx];
        else
            xpm = tb_blank_xpm;
    }
    if (xpm != NULL || buf[0] != NUL)
        createXpmImages (buf, xpm, sen);
}

static void createXpmImages (char_u *path, char **xpm, Pixmap *sen) {
    Window rootWindow;
    XpmAttributes attrs;
    XpmColorSymbol color [5] = {{"none", "none", 0}, {"iconColor1", NULL, 0}, {"bottomShadowColor", NULL, 0}, {"topShadowColor", NULL, 0}, {"selectColor", NULL, 0}};
    int screenNum;
    int status;
    Pixmap mask;
    Pixmap map;
    gui_mch_get_toolbar_colors (& color [BACKGROUND].pixel, & color [FOREGROUND].pixel, & color [BOTTOM_SHADOW].pixel, & color [TOP_SHADOW].pixel, & color [HIGHLIGHT].pixel);
    attrs.valuemask = XpmColorSymbols;
    attrs.colorsymbols = color;
    attrs.numsymbols = 5;
    screenNum = DefaultScreen (gui.dpy);
    rootWindow = RootWindow (gui.dpy, screenNum);
    if (xpm != NULL)
        status = XpmCreatePixmapFromData (gui.dpy, rootWindow, xpm, &map, &mask, &attrs);
    else
        status = XpmReadFileToPixmap (gui.dpy, rootWindow, (char *) path, &map, &mask, &attrs);
    if (status == XpmSuccess && map != 0) {
        XGCValues gcvalues;
        GC back_gc;
        GC mask_gc;
        gcvalues.foreground = color[BACKGROUND].pixel;
        back_gc = XCreateGC (gui.dpy, map, GCForeground, &gcvalues);
        mask_gc = XCreateGC (gui.dpy, map, GCForeground, &gcvalues);
        XSetClipMask (gui.dpy, mask_gc, mask);
        *sen = XCreatePixmap (gui.dpy, rootWindow, attrs.width, attrs.height, DefaultDepth (gui.dpy, screenNum));
        XFillRectangle (gui.dpy, * sen, back_gc, 0, 0, attrs.width, attrs.height);
        XCopyArea (gui.dpy, map, * sen, mask_gc, 0, 0, attrs.width, attrs.height, 0, 0);
        XFreeGC (gui.dpy, back_gc);
        XFreeGC (gui.dpy, mask_gc);
        XFreePixmap (gui.dpy, map);
    }
    else
        *sen = 0;
    XpmFreeAttributes (& attrs);
}

void gui_mch_get_toolbar_colors (Pixel *bgp, Pixel *fgp, Pixel *bsp, Pixel *tsp, Pixel *hsp) {
    XtVaGetValues (toolBar, XtNbackground, bgp, XtNborderColor, fgp, NULL);
    *bsp = *bgp;
    *tsp = *fgp;
    *hsp = *tsp;
}

static void gui_athena_menu_font (Widget id) {
    int managed = FALSE;
    if (gui.menu_font != NOFONT) {
        if (XtIsManaged (id)) {
            XtUnmanageChild (id);
            managed = TRUE;
        }
        XtVaSetValues (id, XtNfont, gui.menu_font, NULL);
        if (has_submenu (id))
            XtVaSetValues (id, XtNrightBitmap, pullerBitmap, NULL);
        if (managed)
            XtManageChild (id);
    }
}

void gui_mch_new_tooltip_colors (void) {
    vimmenu_T *menu;
    if (toolBar == (Widget) 0)
        return;
    menu = gui_find_menu ((char_u *) "ToolBar");
    if (menu != NULL)
        gui_mch_submenu_change (menu, TRUE);
}

void gui_mch_set_scrollbar_colors (scrollbar_T *sb) {
    if (sb->id != (Widget) 0)
        XtVaSetValues (sb->id, XtNforeground, gui.scroll_fg_pixel, XtNbackground, gui.scroll_bg_pixel, NULL);
    if (sb == &gui.bottom_sbar && vimForm != (Widget) 0)
        gui_athena_scroll_colors (vimForm);
}

static void gui_athena_scroll_colors (Widget id) {
    if (gui.scroll_bg_pixel != INVALCOLOR)
        XtVaSetValues (id, XtNbackground, gui.scroll_bg_pixel, NULL);
    if (gui.scroll_fg_pixel != INVALCOLOR)
        XtVaSetValues (id, XtNforeground, gui.scroll_fg_pixel, NULL);
}

void gui_mch_add_menu (vimmenu_T *menu, int idx) {
    char_u *pullright_name;
    Dimension height, space, border;
    vimmenu_T *parent = menu->parent;
    a_cur_menu = menu;
    if (parent == NULL) {
        if (menu_is_popup (menu->dname)) {
            menu->submenu_id = XtVaCreatePopupShell ((char *) menu->dname, simpleMenuWidgetClass, vimShell, XtNinsertPosition, athena_calculate_ins_pos, XtNtranslations, popupTrans, NULL);
            gui_athena_menu_colors (menu -> submenu_id);
        }
        else if (menu_is_menubar (menu->dname)) {
            menu->id = XtVaCreateManagedWidget ((char *) menu->dname, menuButtonWidgetClass, menuBar, XtNmenuName, menu->dname, NULL);
            if (menu->id == (Widget) 0)
                return;
            gui_athena_menu_colors (menu -> id);
            gui_athena_menu_font (menu -> id);
            menu->submenu_id = XtVaCreatePopupShell ((char *) menu->dname, simpleMenuWidgetClass, menu->id, XtNinsertPosition, athena_calculate_ins_pos, XtNtranslations, supermenuTrans, NULL);
            gui_athena_menu_colors (menu -> submenu_id);
            gui_athena_menu_font (menu -> submenu_id);
            if (!gui.menu_height_fixed) {
                XtVaGetValues (menuBar, XtNvSpace, & space, XtNborderWidth, & border, NULL);
                XtVaGetValues (menu -> id, XtNheight, & height, NULL);
                gui.menu_height = height + 2 * (space + border);
            }
        }
    }
    else if (parent->submenu_id != (Widget) 0) {
        menu->id = XtVaCreateManagedWidget ((char *) menu->dname, smeBSBObjectClass, parent->submenu_id, XtNlabel, menu->dname, NULL);
        if (menu->id == (Widget) 0)
            return;
        if (pullerBitmap == None)
            pullerBitmap = gui_athena_create_pullright_pixmap (menu->id);
        XtVaSetValues (menu -> id, XtNrightBitmap, pullerBitmap, NULL);
        {
            WidgetList children;
            Cardinal num_children;
            int i;
            XtVaGetValues (parent -> submenu_id, XtNchildren, & children, XtNnumChildren, & num_children, NULL);
            for (i = 0; i < (int) num_children; ++i) {
                XtVaSetValues (children [i], XtNrightMargin, puller_width, NULL);
            }
        }
        gui_athena_menu_colors (menu -> id);
        gui_athena_menu_font (menu -> id);
        pullright_name = make_pull_name (menu->dname);
        menu->submenu_id = XtVaCreatePopupShell ((char *) pullright_name, simpleMenuWidgetClass, parent->submenu_id, XtNtranslations, menuTrans, NULL);
        gui_athena_menu_colors (menu -> submenu_id);
        gui_athena_menu_font (menu -> submenu_id);
        vim_free (pullright_name);
        XtAddCallback (menu -> submenu_id, XtNpopupCallback, gui_athena_popup_callback, (XtPointer) menu);
        if (parent->parent != NULL)
            XtOverrideTranslations (parent->submenu_id, parentTrans);
    }
    a_cur_menu = NULL;
}

static Cardinal athena_calculate_ins_pos (Widget widget) {
    WidgetList children;
    Cardinal num_children = 0;
    int retval;
    Arg args [2];
    int n = 0;
    int i;
    XtSetArg (args [n], XtNchildren, & children);
    n++;
    XtSetArg (args [n], XtNnumChildren, & num_children);
    n++;
    XtGetValues (XtParent (widget), args, n);
    retval = num_children;
    for (i = 0; i < (int) num_children; ++i) {
        Widget current = children[i];
        vimmenu_T *menu = NULL;
        for (menu = (a_cur_menu->parent == NULL) ? root_menu : a_cur_menu->parent->children; menu != NULL; menu = menu->next)
            if (current == menu->id && a_cur_menu->priority < menu->priority && i < retval)
                retval = i;
    }
    return retval;
}

static Pixmap gui_athena_create_pullright_pixmap (Widget w) {
    Pixmap retval;
    XFontStruct *font = NULL;
    if (gui.menu_font == NOFONT) {
        XrmValue from, to;
        WidgetList children;
        Cardinal num_children;
        from.size = strlen (from.addr = XtDefaultFont);
        to.addr = (XtPointer) &font;
        to.size = sizeof (XFontStruct *);
        XtVaGetValues (menuBar, XtNchildren, & children, XtNnumChildren, & num_children, NULL);
        if (XtConvertAndStore (w ? w : (num_children > 0) ? children[0] : menuBar, XtRString, &from, XtRFontStruct, &to) == False)
            return None;
    }
    else
        font = (XFontStruct *) gui.menu_font;
    {
        int width, height;
        GC draw_gc, undraw_gc;
        XGCValues gc_values;
        XPoint points [3];
        height = font->max_bounds.ascent + font->max_bounds.descent;
        width = height - 2;
        puller_width = width + 4;
        retval = XCreatePixmap (gui.dpy, DefaultRootWindow (gui.dpy), width, height, 1);
        gc_values.foreground = 1;
        gc_values.background = 0;
        draw_gc = XCreateGC (gui.dpy, retval, GCForeground | GCBackground, &gc_values);
        gc_values.foreground = 0;
        gc_values.background = 1;
        undraw_gc = XCreateGC (gui.dpy, retval, GCForeground | GCBackground, &gc_values);
        points[0].x = 0;
        points[0].y = 0;
        points[1].x = width - 1;
        points[1].y = (height - 1) / 2;
        points[2].x = 0;
        points[2].y = height - 1;
        XFillRectangle (gui.dpy, retval, undraw_gc, 0, 0, height, height);
        XFillPolygon (gui.dpy, retval, draw_gc, points, XtNumber (points), Convex, CoordModeOrigin);
        XFreeGC (gui.dpy, draw_gc);
        XFreeGC (gui.dpy, undraw_gc);
    }
    return retval;
}

static char_u *make_pull_name (char_u *name) {
    char_u *pname;
    char_u *p;
    pname = vim_strnsave (name, STRLEN (name) +strlen ("-pullright"));
    if (pname != NULL) {
        strcat ((char *) pname, "-pullright");
        while ((p = vim_strchr (pname, '.')) != NULL)
            *p = '_';
    }
    return pname;
}

static void gui_athena_popup_callback (Widget w, XtPointer client_data, XtPointer call_data) {
    vimmenu_T *menu = (vimmenu_T *) client_data;
    Dimension width;
    Position root_x, root_y;
    {
        vimmenu_T *i;
        for (i = menu->parent->children; i != NULL; i = i->next) {
            if (i->submenu_id != NULL && XtIsManaged (i->submenu_id))
                XtPopdown (i->submenu_id);
        }
    }
    XtVaGetValues (XtParent (w), XtNwidth, & width, NULL);
    XtTranslateCoords (menu -> id, width - 5, 0, & root_x, & root_y);
    XtVaSetValues (w, XtNx, root_x, XtNy, root_y, NULL);
}

void gui_mch_add_menu_item (vimmenu_T *menu, int idx) {
    vimmenu_T *parent = menu->parent;
    a_cur_menu = menu;
    if (menu_is_toolbar (parent->name)) {
        WidgetClass type;
        int n;
        Arg args [21];
        n = 0;
        if (menu_is_separator (menu->name)) {
            XtSetArg (args [n], XtNlabel, "");
            n++;
            XtSetArg (args [n], XtNborderWidth, 0);
            n++;
        }
        else {
            get_toolbar_pixmap (menu, & menu -> image);
            XtSetArg (args [n], XtNlabel, menu -> dname);
            n++;
            XtSetArg (args [n], XtNinternalHeight, 1);
            n++;
            XtSetArg (args [n], XtNinternalWidth, 1);
            n++;
            XtSetArg (args [n], XtNborderWidth, 1);
            n++;
            if (menu->image != 0)
                XtSetArg (args[n], XtNbitmap, menu->image);
            n++;
        }
        XtSetArg (args [n], XtNhighlightThickness, 0);
        n++;
        type = commandWidgetClass;
        if (menu->id == NULL) {
            menu->id = XtCreateManagedWidget ((char *) menu->dname, type, toolBar, args, n);
            XtAddCallback (menu -> id, XtNcallback, gui_x11_menu_cb, menu);
        }
        else
            XtSetValues (menu->id, args, n);
        gui_athena_menu_colors (menu -> id);
        gui_mch_menu_set_tip (menu);
        menu->parent = parent;
        menu->submenu_id = NULL;
        if (!XtIsManaged (toolBar) && vim_strchr (p_go, GO_TOOLBAR) != NULL)
            gui_mch_show_toolbar (TRUE);
        gui.toolbar_height = gui_mch_compute_toolbar_height ();
        return;
    }
    if (menu_is_separator (menu->name)) {
        menu->submenu_id = (Widget) 0;
        menu->id = XtVaCreateManagedWidget ((char *) menu->dname, smeLineObjectClass, parent->submenu_id, NULL);
        if (menu->id == (Widget) 0)
            return;
        gui_athena_menu_colors (menu -> id);
    }
    else {
        if (parent != NULL && parent->submenu_id != (Widget) 0) {
            menu->submenu_id = (Widget) 0;
            menu->id = XtVaCreateManagedWidget ((char *) menu->dname, smeBSBObjectClass, parent->submenu_id, XtNlabel, menu->dname, NULL);
            if (menu->id == (Widget) 0)
                return;
            {
                Dimension left_margin;
                XtVaGetValues (menu -> id, XtNleftMargin, & left_margin, NULL);
                XtVaSetValues (menu -> id, XtNrightMargin, gui_athena_menu_has_submenus (parent -> submenu_id, NULL) ? puller_width : left_margin, NULL);
            }
            gui_athena_menu_colors (menu -> id);
            gui_athena_menu_font (menu -> id);
            XtAddCallback (menu -> id, XtNcallback, gui_x11_menu_cb, (XtPointer) menu);
        }
    }
    a_cur_menu = NULL;
}

void gui_x11_destroy_widgets (void) {
    textArea = NULL;
    menuBar = NULL;
    toolBar = NULL;
}

# include "gui_x11_pm.h"

void gui_mch_def_colors (void) {
    if (gui.in_use) {
        gui.menu_fg_pixel = gui_get_color ((char_u *) gui.rsrc_menu_fg_name);
        gui.menu_bg_pixel = gui_get_color ((char_u *) gui.rsrc_menu_bg_name);
        gui.scroll_fg_pixel = gui_get_color ((char_u *) gui.rsrc_scroll_fg_name);
        gui.scroll_bg_pixel = gui_get_color ((char_u *) gui.rsrc_scroll_bg_name);
        gui.tooltip_fg_pixel = gui_get_color ((char_u *) gui.rsrc_tooltip_fg_name);
        gui.tooltip_bg_pixel = gui_get_color ((char_u *) gui.rsrc_tooltip_bg_name);
    }
}

void gui_mch_new_menu_font (void) {
    Pixmap oldpuller = None;
    if (menuBar == (Widget) 0)
        return;
    if (pullerBitmap != None) {
        oldpuller = pullerBitmap;
        pullerBitmap = gui_athena_create_pullright_pixmap (NULL);
    }
    gui_mch_submenu_change (root_menu, FALSE);
    {
        vimmenu_T *mp;
        int max_height = 9999;
        for (mp = root_menu; mp != NULL; mp = mp->next) {
            if (menu_is_menubar (mp->dname)) {
                Dimension height;
                XtVaGetValues (mp -> id, XtNheight, & height, NULL);
                if (height < max_height)
                    max_height = height;
            }
        }
        if (max_height != 9999) {
            if (!gui.menu_height_fixed) {
                Dimension space, border;
                XtVaGetValues (menuBar, XtNvSpace, & space, XtNborderWidth, & border, NULL);
                gui.menu_height = max_height + 2 * (space + border);
            }
        }
    }
    {
        Position w, h;
        XtVaGetValues (vimShell, XtNwidth, & w, XtNheight, & h, NULL);
        gui_resize_shell (w, h);
    }
    gui_set_shellsize (FALSE, TRUE, RESIZE_VERT);
    ui_new_shellsize ();
    if (oldpuller != None)
        XFreePixmap (gui.dpy, oldpuller);
}

void gui_mch_show_popupmenu (vimmenu_T *menu) {
    int rootx, rooty, winx, winy;
    Window root, child;
    unsigned  int mask;
    if (menu->submenu_id == (Widget) 0)
        return;
    if (XQueryPointer (gui.dpy, XtWindow (vimShell), &root, &child, &rootx, &rooty, &winx, &winy, &mask)) {
        rootx -= 30;
        if (rootx < 0)
            rootx = 0;
        rooty -= 5;
        if (rooty < 0)
            rooty = 0;
        XtVaSetValues (menu -> submenu_id, XtNx, rootx, XtNy, rooty, NULL);
    }
    XtOverrideTranslations (menu -> submenu_id, popupTrans);
    XtPopupSpringLoaded (menu -> submenu_id);
}

static void gui_athena_popdown_submenus_action (Widget w, XEvent *event, String *args, Cardinal *nargs) {
    WidgetList children;
    Cardinal num_children;
    XtVaGetValues (w, XtNchildren, & children, XtNnumChildren, & num_children, NULL);
    for (; num_children > 0; --num_children) {
        Widget child = children[num_children - 1];
        if (has_submenu (child)) {
            Widget temp_w;
            temp_w = submenu_widget (child);
            gui_athena_popdown_submenus_action (temp_w, event, args, nargs);
            XtPopdown (temp_w);
        }
    }
}

static Widget submenu_widget (Widget widget) {
    char_u *pullright_name;
    Widget popup;
    pullright_name = make_pull_name ((char_u *) XtName (widget));
    popup = XtNameToWidget (XtParent (widget), (char *) pullright_name);
    vim_free (pullright_name);
    return popup;
}

static void gui_athena_delayed_arm_action (Widget w, XEvent *event, String *args, Cardinal *nargs) {
    Dimension width, height;
    if (event->type != MotionNotify)
        return;
    XtVaGetValues (w, XtNwidth, & width, XtNheight, & height, NULL);
    if (event->xmotion.x >= (int) width || event->xmotion.y >= (int) height)
        return;
    {
        static Widget previous_active_widget = NULL;
        Widget current;
        current = XawSimpleMenuGetActiveEntry (w);
        if (current != previous_active_widget) {
            if (timer) {
                XtRemoveTimeOut (timer);
            }
            gui_athena_popdown_submenus_action (w, event, args, nargs);
            if (has_submenu (current)) {
                XtAppAddTimeOut (XtWidgetToApplicationContext (w), 600L, gui_athena_menu_timeout, (XtPointer) current);
            }
            previous_active_widget = current;
        }
    }
}

static void gui_athena_menu_timeout (XtPointer client_data, XtIntervalId *id) {
    Widget w = (Widget) client_data;
    Widget popup;
    timer = 0;
    if (XtIsSubclass (w, smeBSBObjectClass)) {
        Pixmap p;
        XtVaGetValues (w, XtNrightBitmap, & p, NULL);
        if ((p != None) && (p != XtUnspecifiedPixmap)) {
            popup = get_popup_entry (XtParent (w));
            if (popup == (Widget) 0)
                return;
            XtPopup (popup, XtGrabNonexclusive);
        }
    }
}

static Widget get_popup_entry (Widget w) {
    Widget menuw;
    if ((menuw = XawSimpleMenuGetActiveEntry (w)) == (Widget) 0)
        return NULL;
    return submenu_widget (menuw);
}

