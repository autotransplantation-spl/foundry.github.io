#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "wav.h"

#define SILENCE 0
#define REPEAT_PREV 1
#define REPEAT_PREV_NEXT 2
#define INTERPOLATE 3

#include "config.h"

void transmit_packet(int seqno, int len, char *data, FILE* ofile, int strategy);
void recv_packet(int seqno, int len, char *data, FILE *ofile, int strategy);
int process_wav_header(FILE *ifile, FILE *ofile, int msPerPacket, int *bytesPerPacket);
void init_dct(int N_init);
int *dct(short *idata);
short *idct(int *idata);
