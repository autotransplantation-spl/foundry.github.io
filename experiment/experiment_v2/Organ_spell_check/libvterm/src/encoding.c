
#include "InterfaceHeader.h"
static struct {
    VTermEncodingType type;
    char designation;
    VTermEncoding *enc;
} encodings [] = {{ENC_UTF8, 'u', &encoding_utf8}, {ENC_SINGLE_94, '0', (VTermEncoding *) &encoding_DECdrawing}, {ENC_SINGLE_94, 'A', (VTermEncoding *) &encoding_uk}, {ENC_SINGLE_94, 'B', &encoding_usascii}, {0, 0, NULL},};

VTermEncoding *vterm_lookup_encoding (VTermEncodingType type, char designation) {
    int i;
    for (i = 0; encodings[i].designation; i++)
        if (encodings[i].type == type && encodings[i].designation == designation)
            return encodings[i].enc;
    return NULL;
}

