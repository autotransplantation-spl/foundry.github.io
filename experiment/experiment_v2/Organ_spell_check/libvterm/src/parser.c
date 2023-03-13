
#include "InterfaceHeader.h"

static void append_strbuffer (VTerm *vt, const char *str, size_t len) {
    if (len > vt->strbuffer_len - vt->strbuffer_cur) {
        len = vt->strbuffer_len - vt->strbuffer_cur;
        DEBUG_LOG1 ("Truncating strbuffer preserve to %zd bytes\n", len);
    }
    if (len > 0) {
        strncpy (vt -> strbuffer + vt -> strbuffer_cur, str, len);
        vt->strbuffer_cur += len;
    }
}

static void do_control (VTerm *vt, unsigned  char control) {
    if (vt->parser_callbacks && vt->parser_callbacks->control)
        if ((*vt->parser_callbacks->control) (control, vt->cbdata))
            return;
    DEBUG_LOG1 ("libvterm: Unhandled control 0x%02x\n", control);
}

static size_t do_string (VTerm *vt, const char *str_frag, size_t len) {
    size_t eaten;
    if (vt->strbuffer_cur) {
        if (str_frag)
            append_strbuffer (vt, str_frag, len);
        str_frag = vt->strbuffer;
        len = vt->strbuffer_cur;
    }
    else if (!str_frag) {
        DEBUG_LOG ("parser.c: TODO: No strbuffer _and_ no final fragment???\n");
        len = 0;
    }
    vt->strbuffer_cur = 0;
    switch (vt->parser_state) {
    case NORMAL :
        if (vt->parser_callbacks && vt->parser_callbacks->text)
            if ((eaten = (*vt->parser_callbacks->text) (str_frag, len, vt->cbdata)))
                return eaten;
        DEBUG_LOG1 ("libvterm: Unhandled text (%zu chars)\n", len);
        return 0;
    case ESC :
        if (len == 1 && str_frag[0] >= 0x40 && str_frag[0] < 0x60) {
            do_control (vt, str_frag [0] + 0x40);
            return 0;
        }
        if (vt->parser_callbacks && vt->parser_callbacks->escape)
            if ((*vt->parser_callbacks->escape) (str_frag, len, vt->cbdata))
                return 0;
        DEBUG_LOG1 ("libvterm: Unhandled escape ESC 0x%02x\n", str_frag [len - 1]);
        return 0;
    case CSI :
        do_string_csi (vt, str_frag, len -1, str_frag[len - 1]);
        return 0;
    case OSC :
        if (vt->parser_callbacks && vt->parser_callbacks->osc)
            if ((*vt->parser_callbacks->osc) (str_frag, len, vt->cbdata))
                return 0;
        DEBUG_LOG2 ("libvterm: Unhandled OSC %.*s\n", (int) len, str_frag);
        return 0;
    case DCS :
        if (vt->parser_callbacks && vt->parser_callbacks->dcs)
            if ((*vt->parser_callbacks->dcs) (str_frag, len, vt->cbdata))
                return 0;
        DEBUG_LOG2 ("libvterm: Unhandled DCS %.*s\n", (int) len, str_frag);
        return 0;
    case ESC_IN_OSC :
    case ESC_IN_DCS :
        DEBUG_LOG ("libvterm: ARGH! Should never do_string() in ESC_IN_{OSC,DCS}\n");
        return 0;
    }
    return 0;
}

static void do_string_csi (VTerm *vt, const char *args, size_t arglen, char command) {
    int i = 0;
    int leaderlen = 0;
    char leader [CSI_LEADER_MAX];
    int argcount = 1;
    long  csi_args [CSI_ARGS_MAX];
    int argi;
    int intermedlen = 0;
    char intermed [CSI_INTERMED_MAX];
    for (; i < (int) arglen; i++) {
        if (args[i] < 0x3c || args[i] > 0x3f)
            break;
        if (leaderlen < CSI_LEADER_MAX - 1)
            leader[leaderlen++] = args[i];
    }
    leader[leaderlen] = 0;
    for (; i < (int) arglen; i++)
        if (args[i] == 0x3b || args[i] == 0x3a)
            argcount++;
    if (argcount > CSI_ARGS_MAX)
        argcount = CSI_ARGS_MAX;
    for (argi = 0; argi < argcount; argi++)
        csi_args[argi] = CSI_ARG_MISSING;
    argi = 0;
    for (i = leaderlen; i < (int) arglen && argi < argcount; i++) {
        switch (args[i]) {
        case 0x30 :
        case 0x31 :
        case 0x32 :
        case 0x33 :
        case 0x34 :
        case 0x35 :
        case 0x36 :
        case 0x37 :
        case 0x38 :
        case 0x39 :
            if (csi_args[argi] == CSI_ARG_MISSING)
                csi_args[argi] = 0;
            csi_args[argi] *= 10;
            csi_args[argi] += args[i] - '0';
            break;
        case 0x3a :
            csi_args[argi] |= CSI_ARG_FLAG_MORE;
        case 0x3b :
            argi++;
            break;
        default :
            goto done_leader;
        }
    }
done_leader :
    ;
    for (; i < (int) arglen; i++) {
        if ((args[i] & 0xf0) != 0x20)
            break;
        if (intermedlen < CSI_INTERMED_MAX - 1)
            intermed[intermedlen++] = args[i];
    }
    intermed[intermedlen] = 0;
    if (i < (int) arglen) {
        DEBUG_LOG2 ("libvterm: TODO unhandled CSI bytes \"%.*s\"\n", (int) (arglen - i), args + i);
    }
    if (vt->parser_callbacks && vt->parser_callbacks->csi)
        if ((*vt->parser_callbacks->csi) (leaderlen ? leader : NULL, csi_args, argcount, intermedlen ? intermed : NULL, command, vt->cbdata))
            return;
    DEBUG_LOG3 ("libvterm: Unhandled CSI %.*s %c\n", (int) arglen, args, command);
}

