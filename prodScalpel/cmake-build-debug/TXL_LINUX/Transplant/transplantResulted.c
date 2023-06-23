#include "TransplantCode/TransplantHeader.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <math.h>
static double scale0, scale, N_d;
static int N;

void init_dct (int N_init) {
    N_d = N_init;
    N = N_init;
    scale0 = sqrt (1.0 / N);
    scale = sqrt (2.0 / N);
}

int *dct (short *idata) {
    int *odata = malloc (N * sizeof (int));
    double out_val;
    int n, k;
    for (k = 0; k < N; k++) {
        out_val = 0;
        for (n = 0; n < N; n++) {
            out_val += idata[n] * cos ((M_PI / N) * k * (n + 0.5));
        }
        if (k == 0)
            out_val *= scale0;
        else
            out_val *= scale;
        odata[k] = (int) out_val;
    }
    return odata;
}

int main () {
    FILE *fin = fopen ("/home/alex/NetBeansProjects/HostExample/input.in", "r");
    FILE *fout = fopen ("output.out", "w");
    int *arrayC;
    const int length;
    int test1, *test2, test3 [500];
    fscanf (fin, "%d", &length);
    arrayC = (int *) malloc ((length + 1) * sizeof (int));
    for (int i = 0; i < length; i++) {
        fscanf (fin, "%d", &arrayC[i]);
    }
    for (int i = 0; i < length; i++) {
        fprintf (fout, "%d ", arrayC[i]);
    }
    short *odata = malloc (N * sizeof (short));
    double out_val;
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
    ;
    return (EXIT_SUCCESS);
}

