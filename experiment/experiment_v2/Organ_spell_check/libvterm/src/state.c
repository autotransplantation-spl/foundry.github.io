
#include "InterfaceHeader.h"

INTERNAL void vterm_state_free (VTermState *state) {
    vterm_allocator_free (state -> vt, state -> tabstops);
    vterm_allocator_free (state -> vt, state -> lineinfo);
    vterm_allocator_free (state -> vt, state -> combine_chars);
    vterm_allocator_free (state -> vt, state);
}

static void tab (VTermState *state, int count, int direction) {
    while (count > 0) {
        if (direction > 0) {
            if (state->pos.col >= THISROWWIDTH (state) - 1)
                return;
            state->pos.col++;
        }
        else if (direction < 0) {
            if (state->pos.col < 1)
                return;
            state->pos.col--;
        }
        if (is_col_tabstop (state, state->pos.col))
            count--;
    }
}

#define NO_FORCE 0

#define FORCE    1

#define DWL_OFF 0

#define DWL_ON  1

#define DHL_OFF    0

#define DHL_TOP    1

#define DHL_BOTTOM 2

static int is_col_tabstop (VTermState *state, int col) {
    unsigned  char mask = 1 << (col & 7);
    return state->tabstops[col >> 3] & mask;
}

static VTermState *vterm_state_new (VTerm *vt) {
    VTermState *state = vterm_allocator_malloc (vt, sizeof (VTermState));
    state->vt = vt;
    state->rows = vt->rows;
    state->cols = vt->cols;
    state->mouse_col = 0;
    state->mouse_row = 0;
    state->mouse_buttons = 0;
    state->mouse_protocol = MOUSE_X10;
    state->callbacks = NULL;
    state->cbdata = NULL;
    vterm_state_newpen (state);
    state->bold_is_highbright = 0;
    return state;
}

static void set_col_tabstop (VTermState *state, int col) {
    unsigned  char mask = 1 << (col & 7);
    state->tabstops[col >> 3] |= mask;
}

static void clear_col_tabstop (VTermState *state, int col) {
    unsigned  char mask = 1 << (col & 7);
    state->tabstops[col >> 3] &= ~mask;
}

static void set_lineinfo (VTermState *state, int row, int force, int dwl, int dhl) {
    VTermLineInfo info = state->lineinfo[row];
    if (dwl == DWL_OFF)
        info.doublewidth = DWL_OFF;
    else if (dwl == DWL_ON)
        info.doublewidth = DWL_ON;
    if (dhl == DHL_OFF)
        info.doubleheight = DHL_OFF;
    else if (dhl == DHL_TOP)
        info.doubleheight = DHL_TOP;
    else if (dhl == DHL_BOTTOM)
        info.doubleheight = DHL_BOTTOM;
    if ((state->callbacks && state->callbacks->setlineinfo && (*state->callbacks->setlineinfo) (row, &info, state->lineinfo + row, state->cbdata)) || force)
        state->lineinfo[row] = info;
}

static int settermprop_bool (VTermState *state, VTermProp prop, int v) {
    VTermValue val;
    val.boolean = v;
    return vterm_state_set_termprop (state, prop, &val);
}

int vterm_state_set_termprop (VTermState *state, VTermProp prop, VTermValue *val) {
    if (state->callbacks && state->callbacks->settermprop)
        if (!(*state->callbacks->settermprop) (prop, val, state->cbdata))
            return 0;
    switch (prop) {
    case VTERM_PROP_TITLE :
    case VTERM_PROP_ICONNAME :
    case VTERM_PROP_CURSORCOLOR :
        return 1;
    case VTERM_PROP_CURSORVISIBLE :
        state->mode.cursor_visible = val->boolean;
        return 1;
    case VTERM_PROP_CURSORBLINK :
        state->mode.cursor_blink = val->boolean;
        return 1;
    case VTERM_PROP_CURSORSHAPE :
        state->mode.cursor_shape = val->number;
        return 1;
    case VTERM_PROP_REVERSE :
        state->mode.screen = val->boolean;
        return 1;
    case VTERM_PROP_ALTSCREEN :
        state->mode.alt_screen = val->boolean;
        if (state->mode.alt_screen) {
            VTermRect rect = {0, 0, 0, 0};
            rect.end_row = state->rows;
            rect.end_col = state->cols;
            erase (state, rect, 0);
        }
        return 1;
    case VTERM_PROP_MOUSE :
        state->mouse_flags = 0;
        if (val->number)
            state->mouse_flags |= MOUSE_WANT_CLICK;
        if (val->number == VTERM_PROP_MOUSE_DRAG)
            state->mouse_flags |= MOUSE_WANT_DRAG;
        if (val->number == VTERM_PROP_MOUSE_MOVE)
            state->mouse_flags |= MOUSE_WANT_MOVE;
        return 1;
    }
    return 0;
}

static void erase (VTermState *state, VTermRect rect, int selective) {
    if (state->callbacks && state->callbacks->erase)
        if ((*state->callbacks->erase) (rect, selective, state->cbdata))
            return;
}

static int settermprop_int (VTermState *state, VTermProp prop, int v) {
    VTermValue val;
    val.number = v;
    return vterm_state_set_termprop (state, prop, &val);
}

static void scroll (VTermState *state, VTermRect rect, int downward, int rightward) {
    int rows;
    int cols;
    if (!downward && !rightward)
        return;
    rows = rect.end_row - rect.start_row;
    if (downward > rows)
        downward = rows;
    else if (downward < -rows)
        downward = -rows;
    cols = rect.end_col - rect.start_col;
    if (rightward > cols)
        rightward = cols;
    else if (rightward < -cols)
        rightward = -cols;
    if (rect.start_col == 0 && rect.end_col == state->cols && rightward == 0) {
        int height = rect.end_row - rect.start_row - abs (downward);
        if (downward > 0)
            memmove (state->lineinfo + rect.start_row, state->lineinfo + rect.start_row + downward, height * sizeof (state->lineinfo[0]));
        else
            memmove (state->lineinfo + rect.start_row - downward, state->lineinfo + rect.start_row, height * sizeof (state->lineinfo[0]));
    }
    if (state->callbacks && state->callbacks->scrollrect)
        if ((*state->callbacks->scrollrect) (rect, downward, rightward, state->cbdata))
            return;
    if (state->callbacks)
        vterm_scroll_rect (rect, downward, rightward, state->callbacks->moverect, state->callbacks->erase, state->cbdata);
}

