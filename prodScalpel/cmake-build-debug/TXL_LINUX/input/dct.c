#include <assert.h>
#include "interpolate.h"
#include <math.h>
/* The code in this file is a naive implementation of a type-II DCT and I-DCT */
/* It is very inefficient O(N^2) - really only good for illustrating what the
   DCT calculates.  For a higher performance implementation, you want
   a Fast Cosine Transform */

/* globals used by the DCT code */
static double scale0, scale, N_d;
static int N;

/* you MUST call init_dct before using the DCT functions */
/* N_init is the number of samples you want to perform the DCT on */
void init_dct(int N_init) {
  N_d = N_init;
  N = N_init;
  scale0 = sqrt(1.0/N);
  scale = sqrt(2.0/N);
}

/* Perform the DCT of the input data */
/* input is an array of N signed shorts (16-bit integers) */
/* output is an array of N signed ints (32-bit integers) to avoid any risk of overflow */
int *dct(short *idata)
{
  int* odata = malloc(N*sizeof(int)); 
  double out_val;
  int n, k;
  for (k = 0; k < N; k++) {
    out_val = 0;
    for (n = 0; n < N; n++) {
      out_val += idata[n]*cos( (M_PI/N) * k * (n + 0.5));
    }
    if (k==0)
      out_val *= scale0;
    else
      out_val *= scale;
    odata[k] = (int)out_val;
  }
  return odata;
}

/* Perform the IDCT of the input data */
/* input is an array of N signed ints (32-bit integers), as generated by dct() */
/* output is an array of N signed shorts (16-bit integers) */
short *idct(int *idata)
{
  short* odata = malloc(N*sizeof(short)); 
  double out_val;
  int n, k;
  for (k = 0; k < N; k++) {
    out_val = idata[0]/2.0;
    for (n = 1; n < N; n++) {
      out_val += idata[n]*cos( (M_PI/N) * n * (k + 0.5));
    }
    if (k==0)
      out_val *= scale0;
    else
      out_val *= scale;
    odata[k] = (short)out_val;
  }
  return odata;
}
