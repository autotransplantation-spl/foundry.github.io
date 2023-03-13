
#include "InterfaceHeader.h"
int want_moverect = 0;

static int moverect (VTermRect dest, VTermRect src, void *user) {
    if (!want_moverect)
        return 0;
    printf ("moverect %d..%d,%d..%d -> %d..%d,%d..%d\n", src.start_row, src.end_row, src.start_col, src.end_col, dest.start_row, dest.end_row, dest.start_col, dest.end_col);
    return 1;
}

