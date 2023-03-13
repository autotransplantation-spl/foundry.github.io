
#include "InterfaceHeader.h"
struct VTermScreen {
    VTerm *vt;
    VTermState *state;
    const VTermScreenCallbacks *callbacks;
    void *cbdata;
    VTermDamageSize damage_merge;
    VTermRect damaged;
    VTermRect pending_scrollrect;
    int pending_scroll_downward, pending_scroll_rightward;
    int rows;
    int cols;
    int global_reverse;
    ScreenCell *buffers [2];
    ScreenCell *buffer;
    VTermScreenCell *sb_buffer;
    ScreenPen pen;
};
VTermStateCallbacks state_cbs = {&putglyph, &movecursor, &scrollrect, NULL, &erase, NULL, &setpenattr, &settermprop, &bell, &resize, &setlineinfo};

INTERNAL void vterm_screen_free (VTermScreen *screen) {
    vterm_allocator_free (screen -> vt, screen -> buffers [0]);
    if (screen->buffers[1])
        vterm_allocator_free (screen->vt, screen->buffers[1]);
    vterm_allocator_free (screen -> vt, screen -> sb_buffer);
    vterm_allocator_free (screen -> vt, screen);
}

static VTermScreen *screen_new (VTerm *vt) {
    VTermState *state = vterm_obtain_state (vt);
    VTermScreen *screen;
    int rows, cols;
    if (!state)
        return NULL;
    screen = vterm_allocator_malloc (vt, sizeof (VTermScreen));
    vterm_get_size (vt, & rows, & cols);
    screen->vt = vt;
    screen->state = state;
    screen->damage_merge = VTERM_DAMAGE_CELL;
    screen->damaged.start_row = -1;
    screen->pending_scrollrect.start_row = -1;
    screen->rows = rows;
    screen->cols = cols;
    screen->callbacks = NULL;
    screen->cbdata = NULL;
    screen->buffers[0] = realloc_buffer (screen, NULL, rows, cols);
    screen->buffer = screen->buffers[0];
    screen->sb_buffer = vterm_allocator_malloc (screen->vt, sizeof (VTermScreenCell) * cols);
    vterm_state_set_callbacks (screen -> state, & state_cbs, screen);
    return screen;
}

static ScreenCell *realloc_buffer (VTermScreen *screen, ScreenCell *buffer, int new_rows, int new_cols) {
    ScreenCell *new_buffer = vterm_allocator_malloc (screen->vt, sizeof (ScreenCell) * new_rows * new_cols);
    int row, col;
    for (row = 0; row < new_rows; row++) {
        for (col = 0; col < new_cols; col++) {
            ScreenCell *new_cell = new_buffer + row * new_cols + col;
            if (buffer && row < screen->rows && col < screen->cols)
                *new_cell = buffer[row * screen->cols + col];
            else {
                new_cell->chars[0] = 0;
                new_cell->pen = screen->pen;
            }
        }
    }
    if (buffer)
        vterm_allocator_free (screen->vt, buffer);
    return new_buffer;
}

static ScreenCell *getcell (const VTermScreen *screen, int row, int col) {
    if (row < 0 || row >= screen->rows)
        return NULL;
    if (col < 0 || col >= screen->cols)
        return NULL;
    return screen->buffer + (screen->cols * row) + col;
}

static int moverect_user (VTermRect dest, VTermRect src, void *user) {
    VTermScreen *screen = user;
    if (screen->callbacks && screen->callbacks->moverect) {
        if (screen->damage_merge != VTERM_DAMAGE_SCROLL)
            vterm_screen_flush_damage (screen);
        if ((*screen->callbacks->moverect) (dest, src, screen->cbdata))
            return 1;
    }
    damagerect (screen, dest);
    return 1;
}

void vterm_screen_flush_damage (VTermScreen *screen) {
    if (screen->pending_scrollrect.start_row != -1) {
        vterm_scroll_rect (screen -> pending_scrollrect, screen -> pending_scroll_downward, screen -> pending_scroll_rightward, moverect_user, erase_user, screen);
        screen->pending_scrollrect.start_row = -1;
    }
    if (screen->damaged.start_row != -1) {
        if (screen->callbacks && screen->callbacks->damage)
            (*screen->callbacks->damage) (screen->damaged, screen->cbdata);
        screen->damaged.start_row = -1;
    }
}

static int erase_user (VTermRect rect, int selective, void *user) {
    VTermScreen *screen = user;
    damagerect (screen, rect);
    return 1;
}

static void damagerect (VTermScreen *screen, VTermRect rect) {
    VTermRect emit;
    switch (screen->damage_merge) {
    case VTERM_DAMAGE_CELL :
        emit = rect;
        break;
    case VTERM_DAMAGE_ROW :
        if (rect.end_row > rect.start_row + 1) {
            vterm_screen_flush_damage (screen);
            emit = rect;
        }
        else if (screen->damaged.start_row == -1) {
            screen->damaged = rect;
            return;
        }
        else if (rect.start_row == screen->damaged.start_row) {
            if (screen->damaged.start_col > rect.start_col)
                screen->damaged.start_col = rect.start_col;
            if (screen->damaged.end_col < rect.end_col)
                screen->damaged.end_col = rect.end_col;
            return;
        }
        else {
            emit = screen->damaged;
            screen->damaged = rect;
        }
        break;
    case VTERM_DAMAGE_SCREEN :
    case VTERM_DAMAGE_SCROLL :
        if (screen->damaged.start_row == -1)
            screen->damaged = rect;
        else {
            rect_expand (& screen -> damaged, & rect);
        }
        return;
    default :
        DEBUG_LOG1 ("TODO: Maybe merge damage for level %d\n", screen->damage_merge);
        return;
    }
    if (screen->callbacks && screen->callbacks->damage)
        (*screen->callbacks->damage) (emit, screen->cbdata);
}

