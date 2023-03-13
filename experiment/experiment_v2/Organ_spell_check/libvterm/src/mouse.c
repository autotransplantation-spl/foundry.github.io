
#include "InterfaceHeader.h"

static void output_mouse (VTermState *state, int code, int pressed, int modifiers, int col, int row) {
    modifiers <<= 2;
    switch (state->mouse_protocol) {
    case MOUSE_X10 :
        if (col + 0x21 > 0xff)
            col = 0xff - 0x21;
        if (row + 0x21 > 0xff)
            row = 0xff - 0x21;
        if (!pressed)
            code = 3;
        vterm_push_output_sprintf_ctrl (state -> vt, C1_CSI, "M%c%c%c", (code | modifiers) + 0x20, col + 0x21, row + 0x21);
        break;
    case MOUSE_UTF8 :
        {
            char utf8 [18];
            size_t len = 0;
            if (!pressed)
                code = 3;
            len += fill_utf8 ((code | modifiers) + 0x20, utf8 +len);
            len += fill_utf8 (col +0x21, utf8 +len);
            len += fill_utf8 (row +0x21, utf8 +len);
            utf8[len] = 0;
            vterm_push_output_sprintf_ctrl (state -> vt, C1_CSI, "M%s", utf8);
        }
        break;
    case MOUSE_SGR :
        vterm_push_output_sprintf_ctrl (state->vt, C1_CSI, "<%d;%d;%d%c", code | modifiers, col +1, row +1, pressed ? 'M' : 'm');
        break;
    case MOUSE_RXVT :
        if (!pressed)
            code = 3;
        vterm_push_output_sprintf_ctrl (state -> vt, C1_CSI, "%d;%d;%dM", code | modifiers, col + 1, row + 1);
        break;
    }
}

