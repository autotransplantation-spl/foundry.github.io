
#include "InterfaceHeader.h"
const VTermColor ansi_colors [] = {{0, 0, 0, 1}, {224, 0, 0, 2}, {0, 224, 0, 3}, {224, 224, 0, 4}, {0, 0, 224, 5}, {224, 0, 224, 6}, {0, 224, 224, 7}, {224, 224, 224, 8}, {128, 128, 128, 9}, {255, 64, 64, 10}, {64, 255, 64, 11}, {255, 255, 64, 12}, {64, 64, 255, 13}, {255, 64, 255, 14}, {64, 255, 255, 15}, {255, 255, 255, 16},};

void vterm_state_newpen (VTermState *state) {
    int col;
    state->default_fg.red = state->default_fg.green = state->default_fg.blue = 240;
    state->default_fg.ansi_index = VTERM_ANSI_INDEX_DEFAULT;
    state->default_bg.red = state->default_bg.green = state->default_bg.blue = 0;
    state->default_bg.ansi_index = VTERM_ANSI_INDEX_DEFAULT;
    for (col = 0; col < 16; col++)
        state->colors[col] = ansi_colors[col];
}

void vterm_state_resetpen (VTermState *state) {
    state->pen.bold = 0;
    setpenattr_bool (state, VTERM_ATTR_BOLD, 0);
    state->pen.underline = 0;
    setpenattr_int (state, VTERM_ATTR_UNDERLINE, 0);
    state->pen.italic = 0;
    setpenattr_bool (state, VTERM_ATTR_ITALIC, 0);
    state->pen.blink = 0;
    setpenattr_bool (state, VTERM_ATTR_BLINK, 0);
    state->pen.reverse = 0;
    setpenattr_bool (state, VTERM_ATTR_REVERSE, 0);
    state->pen.strike = 0;
    setpenattr_bool (state, VTERM_ATTR_STRIKE, 0);
    state->pen.font = 0;
    setpenattr_int (state, VTERM_ATTR_FONT, 0);
    state->fg_index = -1;
    state->bg_index = -1;
    state->pen.fg = state->default_fg;
    setpenattr_col (state, VTERM_ATTR_FOREGROUND, state -> default_fg);
    state->pen.bg = state->default_bg;
    setpenattr_col (state, VTERM_ATTR_BACKGROUND, state -> default_bg);
}

static void setpenattr_bool (VTermState *state, VTermAttr attr, int boolean) {
    VTermValue val;
    val.boolean = boolean;
    setpenattr (state, attr, VTERM_VALUETYPE_BOOL, & val);
}

static void setpenattr (VTermState *state, VTermAttr attr, VTermValueType type, VTermValue *val) {
    if (state->callbacks && state->callbacks->setpenattr)
        (*state->callbacks->setpenattr) (attr, val, state->cbdata);
}

static void setpenattr_int (VTermState *state, VTermAttr attr, int number) {
    VTermValue val;
    val.number = number;
    setpenattr (state, attr, VTERM_VALUETYPE_INT, & val);
}

static void setpenattr_col (VTermState *state, VTermAttr attr, VTermColor color) {
    VTermValue val;
    val.color = color;
    setpenattr (state, attr, VTERM_VALUETYPE_COLOR, & val);
}

