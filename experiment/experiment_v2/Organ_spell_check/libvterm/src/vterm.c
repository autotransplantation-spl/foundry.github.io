
#include "InterfaceHeader.h"

INTERNAL void vterm_allocator_free (VTerm *vt, void *ptr) {
    (*vt->allocator->free) (ptr, vt->allocdata);
}

INTERNAL void *vterm_allocator_malloc (VTerm *vt, size_t size) {
    return (*vt->allocator->malloc) (size, vt->allocdata);
}

INTERNAL void vterm_push_output_sprintf_ctrl (VTerm *vt, unsigned  char ctrl, const char *fmt, ... ) {
    size_t orig_cur = vt->outbuffer_cur;
    va_list args;
    if (ctrl >= 0x80 && !vt->mode.ctrl8bit)
        vterm_push_output_sprintf (vt, ESC_S "%c", ctrl -0x40);
    else
        vterm_push_output_sprintf (vt, "%c", ctrl);
    va_start (args, fmt);
    vterm_push_output_vsprintf (vt, fmt, args);
    va_end (args);
    if (outbuffer_is_full (vt))
        vt->outbuffer_cur = orig_cur;
}

INTERNAL void vterm_push_output_sprintf (VTerm *vt, const char *format, ... ) {
    va_list args;
    va_start (args, format);
    vterm_push_output_vsprintf (vt, format, args);
    va_end (args);
}

INTERNAL void vterm_push_output_vsprintf (VTerm *vt, const char *format, va_list args) {
    int written;
    char buffer [1024];
    if (outbuffer_is_full (vt)) {
        DEBUG_LOG ("vterm_push_output(): buffer overflow; truncating output\n");
        return;
    }
    written = vsprintf (buffer, format, args);
    if (written >= (int) (vt->outbuffer_len - vt->outbuffer_cur)) {
        written = vt->outbuffer_len - vt->outbuffer_cur;
    }
    if (written > 0) {
        strncpy (vt -> outbuffer + vt -> outbuffer_cur, buffer, written + 1);
        vt->outbuffer_cur += written;
    }
}

static int outbuffer_is_full (VTerm *vt) {
    return vt->outbuffer_cur >= vt->outbuffer_len - 1;
}

INTERNAL void vterm_push_output_bytes (VTerm *vt, const char *bytes, size_t len) {
    if (len > vt->outbuffer_len - vt->outbuffer_cur) {
        DEBUG_LOG ("vterm_push_output(): buffer overflow; truncating output\n");
        len = vt->outbuffer_len - vt->outbuffer_cur;
    }
    memcpy (vt -> outbuffer + vt -> outbuffer_cur, bytes, len);
    vt->outbuffer_cur += len;
}

VTerm *vterm_new_with_allocator (int rows, int cols, VTermAllocatorFunctions *funcs, void *allocdata) {
    VTerm *vt = (*funcs->malloc) (sizeof (VTerm), allocdata);
    vt->allocator = funcs;
    vt->allocdata = allocdata;
    vt->rows = rows;
    vt->cols = cols;
    vt->parser_state = NORMAL;
    vt->parser_callbacks = NULL;
    vt->cbdata = NULL;
    vt->strbuffer_len = 64;
    vt->strbuffer_cur = 0;
    vt->strbuffer = vterm_allocator_malloc (vt, vt->strbuffer_len);
    vt->outbuffer_len = 64;
    vt->outbuffer_cur = 0;
    vt->outbuffer = vterm_allocator_malloc (vt, vt->outbuffer_len);
    return vt;
}

