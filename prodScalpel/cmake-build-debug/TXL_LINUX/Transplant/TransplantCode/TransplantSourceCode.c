#include "TransplantHeader.h"
#include <assert.h>
#include <math.h>

short *idct (int *idata) {
    short *odata = malloc (N * sizeof (short));
    __ADDGRAFTHERE__JUSTHERE double out_val;
    int n, k;
    for (k = 0; k < N; k++) {
        out_val = idata[0] / 2.0;
        for (n = 1; n < N; n++) {
            out_val += idata[n] * cos ((M_PI / N) * n * (k + 0.5));
        }
        if (k == 0)
            out_val *= scale0;
        else
            out_val *= scale;
        odata[k] = (short) out_val;
    }
    return odata;
}

