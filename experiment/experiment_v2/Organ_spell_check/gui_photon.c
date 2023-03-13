
#include "InterfaceHeader.h"
static struct {
    int key_sym;
    char_u vim_code0;
    char_u vim_code1;
} special_keys [] = {{Pk_Up, 'k', 'u'}, {Pk_Down, 'k', 'd'}, {Pk_Left, 'k', 'l'}, {Pk_Right, 'k', 'r'}, {Pk_F1, 'k', '1'}, {Pk_F2, 'k', '2'}, {Pk_F3, 'k', '3'}, {Pk_F4, 'k', '4'}, {Pk_F5, 'k', '5'}, {Pk_F6, 'k', '6'}, {Pk_F7, 'k', '7'}, {Pk_F8, 'k', '8'}, {Pk_F9, 'k', '9'}, {Pk_F10, 'k', ';'}, {Pk_F11, 'F', '1'}, {Pk_F12, 'F', '2'}, {Pk_F13, 'F', '3'}, {Pk_F14, 'F', '4'}, {Pk_F15, 'F', '5'}, {Pk_F16, 'F', '6'}, {Pk_F17, 'F', '7'}, {Pk_F18, 'F', '8'}, {Pk_F19, 'F', '9'}, {Pk_F20, 'F', 'A'}, {Pk_F21, 'F', 'B'}, {Pk_F22, 'F', 'C'}, {Pk_F23, 'F', 'D'}, {Pk_F24, 'F', 'E'}, {Pk_F25, 'F', 'F'}, {Pk_F26, 'F', 'G'}, {Pk_F27, 'F', 'H'}, {Pk_F28, 'F', 'I'}, {Pk_F29, 'F', 'J'}, {Pk_F30, 'F', 'K'}, {Pk_F31, 'F', 'L'}, {Pk_F32, 'F', 'M'}, {Pk_F33, 'F', 'N'}, {Pk_F34, 'F', 'O'}, {Pk_F35, 'F', 'P'}, {Pk_Help, '%', '1'}, {Pk_BackSpace, 'k', 'b'}, {Pk_Insert, 'k', 'I'}, {Pk_Delete, 'k', 'D'}, {Pk_Home, 'k', 'h'}, {Pk_End, '@', '7'}, {Pk_Prior, 'k', 'P'}, {Pk_Next, 'k', 'N'}, {Pk_Print, '%', '9'}, {Pk_KP_Add, 'K', '6'}, {Pk_KP_Subtract, 'K', '7'}, {Pk_KP_Divide, 'K', '8'}, {Pk_KP_Multiply, 'K', '9'}, {Pk_KP_Enter, 'K', 'A'}, {Pk_KP_0, KS_EXTRA, KE_KINS}, {Pk_KP_Decimal, KS_EXTRA, KE_KDEL}, {Pk_KP_4, 'k', 'l'}, {Pk_KP_6, 'k', 'r'}, {Pk_KP_8, 'k', 'u'}, {Pk_KP_2, 'k', 'd'}, {Pk_KP_7, 'K', '1'}, {Pk_KP_1, 'K', '4'}, {Pk_KP_9, 'K', '3'}, {Pk_KP_3, 'K', '5'}, {Pk_KP_5, '&', '8'}, {Pk_Return, CAR, NUL}, {Pk_space, ' ', NUL}, {Pk_Tab, TAB, NUL}, {Pk_Escape, ESC, NUL}, {NL, NL, NUL}, {CAR, CAR, NUL}, {0, 0, 0}};
PtCallbackF_t gui_ph_handle_mouse;
PhPoint_t abs_mouse;
long_u blink_waittime = 700;
int is_ignore_draw = FALSE;
short  is_timeout;
long_u blink_ontime = 400;
long_u blink_offtime = 250;
PtWidget_t *gui_ph_timer_cursor;
int mshape_ids [] = {Ph_CURSOR_POINTER, Ph_CURSOR_NONE, Ph_CURSOR_INSERT, Ph_CURSOR_DRAG_VERTICAL, Ph_CURSOR_DRAG_VERTICAL, Ph_CURSOR_DRAG_HORIZONTAL, Ph_CURSOR_DRAG_HORIZONTAL, Ph_CURSOR_WAIT, Ph_CURSOR_DONT, Ph_CURSOR_CROSSHAIR, Ph_CURSOR_FINGER, Ph_CURSOR_FINGER, Ph_CURSOR_FINGER, Ph_CURSOR_QUESTION_POINT, Ph_CURSOR_POINTER, Ph_CURSOR_POINTER, Ph_CURSOR_POINTER};
int last_shape = 0;

void mch_set_mouse_shape (int shape) {
    int id;
    if (!gui.in_use)
        return;
    if (shape == MSHAPE_HIDE || gui.pointer_hidden)
        PtSetResource (gui.vimTextArea, Pt_ARG_CURSOR_TYPE, Ph_CURSOR_NONE, 0);
    else {
        if (shape >= MSHAPE_NUMBERED)
            id = Ph_CURSOR_POINTER;
        else
            id = mshape_ids[shape];
        PtSetResource (gui.vimTextArea, Pt_ARG_CURSOR_TYPE, id, 0);
    }
    if (shape != MSHAPE_HIDE)
        last_shape = shape;
}

static int gui_ph_handle_timer_cursor (PtWidget_t *widget, void *data, PtCallbackInfo_t *info) {
    if (blink_state == BLINK_ON) {
        gui_undraw_cursor ();
        blink_state = BLINK_OFF;
        PtSetResource (gui_ph_timer_cursor, Pt_ARG_TIMER_INITIAL, blink_offtime, 0);
    }
    else {
        gui_update_cursor (TRUE, FALSE);
        blink_state = BLINK_ON;
        PtSetResource (gui_ph_timer_cursor, Pt_ARG_TIMER_INITIAL, blink_ontime, 0);
    }
    return Pt_CONTINUE;
}

static int gui_ph_handle_timer_timeout (PtWidget_t *widget, void *data, PtCallbackInfo_t *info) {
    is_timeout = TRUE;
    return Pt_CONTINUE;
}

static int gui_ph_handle_window_cb (PtWidget_t *widget, void *data, PtCallbackInfo_t *info) {
    PhWindowEvent_t *we = info->cbdata;
    ushort_t *width, *height;
    switch (we->event_f) {
    case Ph_WM_CLOSE :
        gui_shell_closed ();
        break;
    case Ph_WM_FOCUS :
        gui_mch_mousehide (MOUSE_SHOW);
        if (we->event_state == Ph_WM_EVSTATE_FOCUS) {
            gui_focus_change (TRUE);
            gui_mch_start_blink ();
        }
        else {
            gui_focus_change (FALSE);
            gui_mch_stop_blink (TRUE);
        }
        break;
    case Ph_WM_RESIZE :
        PtGetResource (gui.vimWindow, Pt_ARG_WIDTH, &width, 0);
        PtGetResource (gui.vimWindow, Pt_ARG_HEIGHT, & height, 0);
        gui_resize_shell (* width, * height);
        gui_set_shellsize (FALSE, FALSE, RESIZE_BOTH);
        is_ignore_draw = FALSE;
        PtEndFlux (gui.vimContainer);
        PtContainerRelease (gui.vimContainer);
        break;
    default :
        break;
    }
    return Pt_CONTINUE;
}

void gui_mch_mousehide (int hide) {
    if (gui.pointer_hidden != hide) {
        gui.pointer_hidden = hide;
        if (hide)
            PtSetResource (gui.vimTextArea, Pt_ARG_CURSOR_TYPE, Ph_CURSOR_NONE, 0);
        else
            mch_set_mouse_shape (last_shape);
    }
}

void gui_mch_start_blink (void) {
    if (blink_waittime && blink_ontime && blink_offtime && gui.in_focus) {
        PtSetResource (gui_ph_timer_cursor, Pt_ARG_TIMER_INITIAL, blink_waittime, 0);
        blink_state = BLINK_ON;
        gui_update_cursor (TRUE, FALSE);
    }
}

void gui_mch_stop_blink (int may_call_gui_update_cursor) {
    PtSetResource (gui_ph_timer_cursor, Pt_ARG_TIMER_INITIAL, 0, 0);
    if (blink_state == BLINK_OFF && may_call_gui_update_cursor)
        gui_update_cursor (TRUE, FALSE);
    blink_state = BLINK_NONE;
}

static int gui_ph_handle_scrollbar (PtWidget_t *widget, void *data, PtCallbackInfo_t *info) {
    PtScrollbarCallback_t *scroll;
    scrollbar_T *sb;
    int value, dragging = FALSE;
    scroll = info->cbdata;
    sb = (scrollbar_T *) data;
    if (sb != NULL) {
        value = scroll->position;
        switch (scroll->action) {
        case Pt_SCROLL_DRAGGED :
            dragging = TRUE;
            break;
        case Pt_SCROLL_SET :
            return Pt_CONTINUE;
            break;
        }
        gui_drag_scrollbar (sb, value, dragging);
    }
    return Pt_CONTINUE;
}

static int gui_ph_handle_keyboard (PtWidget_t *widget, void *data, PtCallbackInfo_t *info) {
    PhKeyEvent_t *key;
    unsigned  char string [6];
    int len, i;
    int ch, modifiers;
    key = PhGetData (info->event);
    ch = modifiers = len = 0;
    if (p_mh)
        gui_mch_mousehide (MOUSE_HIDE);
    if (key->key_flags & Pk_KF_Compose) {
        return Pt_CONTINUE;
    }
    if ((key->key_flags & Pk_KF_Cap_Valid) && PkIsKeyDown (key->key_flags)) {
        if (((key->key_mods & Pk_KM_Alt) && !(key->key_mods & Pk_KM_Shift) && !(key->key_mods & Pk_KM_Ctrl)) && gui.menu_is_active && (*p_wak == 'y' || (*p_wak == 'm' && gui_is_menu_shortcut (key->key_cap)))) {
            return Pt_CONTINUE;
        }
        for (i = 0; special_keys[i].key_sym != 0; i++) {
            if (special_keys[i].key_sym == key->key_cap) {
                len = 0;
                if (special_keys[i].vim_code1 == NUL)
                    ch = special_keys[i].vim_code0;
                else {
                    if (key->key_cap >= Pk_KP_Enter && key->key_cap <= Pk_KP_9 && (key->key_mods & Pk_KM_Num_Lock)) {
                        ch = key->key_cap - 0xf080;
                    }
                    else
                        ch = TO_SPECIAL (special_keys[i].vim_code0, special_keys[i].vim_code1);
                }
                break;
            }
        }
        if (key->key_mods & Pk_KM_Ctrl)
            modifiers |= MOD_MASK_CTRL;
        if (key->key_mods & Pk_KM_Alt)
            modifiers |= MOD_MASK_ALT;
        if (key->key_mods & Pk_KM_Shift)
            modifiers |= MOD_MASK_SHIFT;
        if (special_keys[i].key_sym == 0) {
            ch = PhTo8859_1 (key);
            if (ch == -1) {
                ch = key->key_cap;
                if (ch < 0xff) {
                    if (modifiers & MOD_MASK_CTRL) {
                        modifiers &= ~MOD_MASK_CTRL;
                        if ((ch >= 'a' && ch <= 'z') || ch == '[' || ch == ']' || ch == '\\')
                            ch = Ctrl_chr (ch);
                        else if (ch == '2')
                            ch = NUL;
                        else if (ch == '6')
                            ch = 0x1e;
                        else if (ch == '-')
                            ch = 0x1f;
                        else
                            modifiers |= MOD_MASK_CTRL;
                    }
                    if (modifiers & MOD_MASK_ALT) {
                        ch = Meta (ch);
                        modifiers &= ~MOD_MASK_ALT;
                    }
                }
                else {
                    return Pt_CONTINUE;
                }
            }
            else
                modifiers &= ~MOD_MASK_SHIFT;
        }
        ch = simplify_key (ch, &modifiers);
        if (modifiers) {
            string[len++] = CSI;
            string[len++] = KS_MODIFIER;
            string[len++] = modifiers;
        }
        if (IS_SPECIAL (ch)) {
            string[len++] = CSI;
            string[len++] = K_SECOND (ch);
            string[len++] = K_THIRD (ch);
        }
        else {
            string[len++] = ch;
        }
        if (len == 1 && ((ch == Ctrl_C && ctrl_c_interrupts) || ch == intr_char)) {
            trash_input_buf ();
            got_int = TRUE;
        }
        if (len == 1 && string[0] == CSI) {
            string[len++] = KS_EXTRA;
            string[len++] = KE_CSI;
        }
        if (len > 0) {
            add_to_input_buf (string, len);
            return Pt_CONSUME;
        }
    }
    return Pt_CONTINUE;
}

static int gui_ph_handle_mouse (PtWidget_t *widget, void *data, PtCallbackInfo_t *info) {
    PhPointerEvent_t *pointer;
    PhRect_t *pos;
    int button = 0, repeated_click, modifiers = 0x0;
    short  mouse_x, mouse_y;
    pointer = PhGetData (info->event);
    pos = PhGetRects (info->event);
    gui_mch_mousehide (MOUSE_SHOW);
    mouse_x = pos->ul.x + gui.border_width;
    mouse_y = pos->ul.y + gui.border_width;
    if (info->event->type == Ph_EV_PTR_MOTION_NOBUTTON) {
        gui_mouse_moved (mouse_x, mouse_y);
        return Pt_CONTINUE;
    }
    if (pointer->key_mods & Pk_KM_Shift)
        modifiers |= MOUSE_SHIFT;
    if (pointer->key_mods & Pk_KM_Ctrl)
        modifiers |= MOUSE_CTRL;
    if (pointer->key_mods & Pk_KM_Alt)
        modifiers |= MOUSE_ALT;
    if (pointer->buttons & Ph_BUTTON_SELECT)
        button = MOUSE_LEFT;
    if (pointer->buttons & Ph_BUTTON_MENU) {
        button = MOUSE_RIGHT;
        abs_mouse.x = pointer->pos.x;
        abs_mouse.y = pointer->pos.y;
    }
    if (pointer->buttons & Ph_BUTTON_ADJUST)
        button = MOUSE_MIDDLE;
    if (info->event->type == Ph_EV_BUT_RELEASE)
        button = MOUSE_RELEASE;
    if (info->event->type & Ph_EV_PTR_MOTION_BUTTON)
        button = MOUSE_DRAG;
    if ((button != MOUSE_RELEASE) || (info->event->subtype == Ph_EV_RELEASE_REAL)) {
        repeated_click = (pointer->click_count >= 2) ? TRUE : FALSE;
        gui_send_mouse_event (button, mouse_x, mouse_y, repeated_click, modifiers);
    }
    return Pt_CONTINUE;
}

static int gui_ph_handle_pulldown_menu (PtWidget_t *widget, void *data, PtCallbackInfo_t *info) {
    if (data != NULL) {
        vimmenu_T *menu = (vimmenu_T *) data;
        PtPositionMenu (menu -> submenu_id, NULL);
        PtRealizeWidget (menu -> submenu_id);
    }
    return Pt_CONTINUE;
}

static int gui_ph_handle_menu (PtWidget_t *widget, void *data, PtCallbackInfo_t *info) {
    if (data != NULL) {
        vimmenu_T *menu = (vimmenu_T *) data;
        gui_menu_cb (menu);
    }
    return Pt_CONTINUE;
}

static int gui_ph_handle_focus (PtWidget_t *widget, void *data, PtCallbackInfo_t *info) {
    if (info->reason == Pt_CB_LOST_FOCUS) {
        PtRemoveEventHandler (gui.vimTextArea, Ph_EV_PTR_MOTION_NOBUTTON, gui_ph_handle_mouse, NULL);
        gui_mch_mousehide (MOUSE_SHOW);
    }
    else {
        PtAddEventHandler (gui.vimTextArea, Ph_EV_PTR_MOTION_NOBUTTON, gui_ph_handle_mouse, NULL);
    }
    return Pt_CONTINUE;
}

static int gui_ph_handle_menu_resize (PtWidget_t *widget, void *other, PtCallbackInfo_t *info) {
    PtContainerCallback_t *sizes = info->cbdata;
    PtWidget_t *container;
    PhPoint_t below_menu;
    int_u height;
    height = sizes->new_dim.h;
    if (gui.menu_is_active) {
        gui.menu_height = height;
        gui.toolbar_height = 0;
    }
    else
        gui.toolbar_height = height;
    below_menu.x = 0;
    below_menu.y = height;
    container = gui.vimContainer;
    PtSetResource (container, Pt_ARG_POS, & below_menu, 0);
    gui_ph_resize_container ();
    return Pt_CONTINUE;
}

static void gui_ph_resize_container (void) {
    PhArea_t area;
    PtWidgetArea (gui.vimWindow, & area);
    PtWidgetPos (gui.vimContainer, & area.pos);
    PtSetResource (gui.vimContainer, Pt_ARG_AREA, & area, 0);
}

static int gui_ph_handle_menu_unrealized (PtWidget_t *widget, void *data, PtCallbackInfo_t *info) {
    PtGiveFocus (gui.vimTextArea, NULL);
    return Pt_CONTINUE;
}

