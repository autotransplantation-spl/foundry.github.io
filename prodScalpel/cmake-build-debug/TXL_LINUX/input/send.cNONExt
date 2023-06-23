#include "interpolate.h"

/* simulate sending the packet */
void send_packet(int seqno, int len, char *data, FILE *ofile, int * repair_strategy) {
  char *pktbuf = malloc(len);
  memcpy(pktbuf, data, len);
  transmit_packet(seqno, len, pktbuf, ofile, * repair_strategy);
};

/* simulate the packet traversing the net.  Sometimes it gets lost */
void transmit_packet(int seqno, int len, char *data, FILE* ofile, int repair_strategy) {
  long r = random();
  if ( (r%1000000)/1000000.0 < LOSS_PROB) {
    /* ooops - packet was lost */
    free(data);
    return;
  }
  recv_packet(seqno, len, data, ofile, repair_strategy);
}

