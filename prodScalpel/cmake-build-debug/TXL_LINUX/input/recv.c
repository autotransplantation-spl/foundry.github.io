#include "interpolate.h"
#include "assert.h"

/* write a packet's worth of silence */
void write_silence(FILE *ofile, int num_samples) {
    short missing_pkt[num_samples];
    int i;
    for (i = 0; i < num_samples; i++) {
        missing_pkt[i] = 0;
    }
    fwrite(missing_pkt, 1, num_samples * 2, ofile);
}

/* uniformly distribute differences between packet bounderies - just in the second packet*/
void distribute_last_packet(short value, short * packet, int num_samples) {
    //the value of the last element from the previous packet
    short lastElement = value;
    //the number of samples involved in fixing boundaries
    int lastPosShaping = 0.30 * num_samples;
    //the differences between the current values and the medium one
    double difference = packet [0] - lastElement;
    double step_size = difference / lastPosShaping;
    int i;
    //decrease linearly in the second packet, for smoothly reaching the medium point
    for (i = 0; i < lastPosShaping; i++) {
        packet [i] -= step_size * (lastPosShaping - i);
    }
}

/* uniformly distribute differences between packet boundaries half in every packet*/
void distribute_both_packets(short * packet1, short * packet2, int num_samples) {
    //the number of samples involved in fixing boundaries 
    int lastPosShaping = 0.15 * num_samples;
    //the medium value where the last sample in the first packet and the first
    //sample in the second packet must be
    double mediumPoint = (packet2[0] + packet1[num_samples - 1]) / 2;
    //the differences between the current values and the medium one
    //should be equal
    double difference1 = mediumPoint - packet1[num_samples - 1];
    double difference2 = packet2[0] - mediumPoint;
    //every step size
    double step_size1 = difference1 / lastPosShaping;
    double step_size2 = difference2 / lastPosShaping;
    int i;
    //increase linearly in the first packet, for smoothly reaching the medium point
    for (i = num_samples - lastPosShaping; i < num_samples; i++) {
        packet1 [i] += step_size1 * (i - num_samples + lastPosShaping);
    }
    //decrease linearly in the second packet, for smoothly reaching the medium point
    for (i = 0; i < lastPosShaping; i++) {
        packet2[i] -= step_size2 * (lastPosShaping - i);
    }
}

/* simulate the reception of a packet, and apply a loss repair strategy */
void recv_packet(int seqno, int len, char *data, FILE *ofile, int strategy) {
    static int prev_seqno = -1;
    static short* prev_samples = 0;
    static long stream_position = 0;

    /* interpret the data as signed 16 bit integers */
    short *samples = (short*) data;
    int num_samples = len / 2;

    printf("recv_packet: seqno=%d\n", seqno);

    if (prev_seqno != -1 && (prev_seqno + 1 != seqno)) {
        int i, missing_seqno;
        /* there was missing data */

        printf("s=%d\n", strategy);
        switch (strategy) {
            case SILENCE:
            {
                /* create a packet containing silence */
                missing_seqno = prev_seqno + 1;
                while (missing_seqno < seqno) {
                    write_silence(ofile, num_samples);
                    missing_seqno++;
                }
                break;
            }
            case REPEAT_PREV:
            {
                /* repeat the previous packet */
                fwrite(prev_samples, 2, num_samples, ofile);
                missing_seqno = prev_seqno + 2;
                while (missing_seqno < seqno) {
                    /* repeating the same packet more than once sounds bad */
                    write_silence(ofile, num_samples);
                    missing_seqno++;
                }
                break;
            }
            case REPEAT_PREV_NEXT:
            {
                /****************************************************************/
                /**                     your code goes here                    **/
                /****************************************************************/
                /* REPEAT_PREV_NEXT */
                int nrOfLostPackets = seqno - prev_seqno - 1;
                switch (nrOfLostPackets) {
                    case 1:
                    {
                        //if just one missing packet, then write the second half
                        //of the previous packet and the first half of the current packet
                        fwrite(prev_samples + num_samples / 2, 2, num_samples / 2, ofile);
                        fwrite(samples, 2, num_samples / 2, ofile);
                        break;
                    }
                    default:
                    {
                        //if more then one first write the previous packet
                        fwrite(prev_samples, 2, num_samples, ofile);
                        nrOfLostPackets = nrOfLostPackets - 2;
                        //write silence for nr of lost packet - 2 times
                        while (nrOfLostPackets > 0) {
                            write_silence(ofile, num_samples);
                            nrOfLostPackets--;
                        }
                        //write the current packet
                        fwrite(samples, 2, num_samples, ofile);
                        break;
                    }
                }
                break;
            }
            case INTERPOLATE:
            {
                /****************************************************************/
                /**                     your code goes here                    **/
                /****************************************************************/
                /*interpolate*/
                //DCT coefficients of the previous and the current packet
                int * dctPrev = dct(prev_samples);
                int * dctCurr = dct(samples);
                //number of lost packets
                int nrOfLostPackets = seqno - prev_seqno - 1;
                int kk;
                if (nrOfLostPackets == 1) {
                    //if just one missing packet
                    int* odata = malloc(num_samples * sizeof (int));
                    //interpolate the DCT coefficients, by using the same weight
                    for (kk = 0; kk < num_samples; kk++) {
                        double intermediate = abs(0.5 * dctPrev[kk] + 0.5 * dctCurr[kk]);
                        //randomise the sign of the coefficients
                        int sign = (rand()) % 2;
                        if (sign = 1) {
                            intermediate = 0 - intermediate;
                        }
                        odata[kk] = (int) intermediate;
                    }
                    //the predicted packets
                    short * newPacket = idct(odata);
                    //distribute the boundaries differences across the previous packet
                    //and the predicted packet
                    distribute_both_packets(prev_samples, newPacket, num_samples);
                    //overwrite the previous packet in the file
                    fseek(ofile, stream_position, SEEK_SET);
                    fwrite(prev_samples, 2, num_samples, ofile);
                    //distribute the boundaries differences across the predicted packet
                    //and the current packet
                    distribute_both_packets(newPacket, samples, num_samples);
                    fwrite(newPacket, 2, num_samples, ofile);
                } else if (nrOfLostPackets == 2) {
                    //two missing packets
                    int* odata1 = malloc(num_samples * sizeof (int));
                    int* odata2 = malloc(num_samples * sizeof (int));
                    //for the first one, the weights are 0.7 from the previous and
                    //0.3 from the current
                    for (kk = 0; kk < num_samples; kk++) {
                        double intermediate = abs(0.7 * dctPrev[kk] + 0.3 * dctCurr[kk]);
                        int sign = (rand()) % 2;
                        if (sign = 1) {
                            intermediate = 0 - intermediate;
                        }
                        odata1[kk] = (int) intermediate;
                    }
                    short * newPacket1 = idct(odata1);
                    //distribute the boundaries differences across the previous packet
                    //and the predicted packet
                    distribute_both_packets(prev_samples, newPacket1, num_samples);
                    //overwrite the previous packet in the file
                    fseek(ofile, stream_position, SEEK_SET);
                    fwrite(prev_samples, 2, num_samples, ofile);
                    //for the second packet, the weights are 0.3 from the previous and
                    //0.7 from the current
                    for (kk = 0; kk < num_samples; kk++) {
                        double intermediate = abs(0.3 * dctPrev[kk] + 0.7 * dctCurr[kk]);
                        int sign = (rand()) % 2;
                        if (sign = 1) {
                            intermediate = 0 - intermediate;
                        }
                        odata2[kk] = (int) intermediate;
                    }
                    short * newPacket2 = idct(odata2);
                    //distribute the boundaries differences across the first predicted packet
                    //and the second predicted packet
                    distribute_both_packets(newPacket1, newPacket2, num_samples);
                    //distribute the boundaries differences across the second predicted packet
                    //and the current packet
                    distribute_both_packets(newPacket2, samples, num_samples);
                    fwrite(newPacket1, 2, num_samples, ofile);
                    fwrite(newPacket2, 2, num_samples, ofile);
                } else if (nrOfLostPackets >= 3) {
                    //three missing packets
                    int* odata1 = malloc(num_samples * sizeof (int));
                    int* odata2 = malloc(num_samples * sizeof (int));
                    int* odata3 = malloc(num_samples * sizeof (int));
                    //for the first one, the weights are 0.9 from the previous and
                    //0.1 from the current
                    for (kk = 0; kk < num_samples; kk++) {
                        double intermediate = abs(0.9 * dctPrev[kk] + 0.1 * dctCurr[kk]);
                        int sign = (rand()) % 2;
                        if (sign = 1) {
                            intermediate = 0 - intermediate;
                        }
                        odata1[kk] = (int) intermediate;
                    }
                    short * newPacket1 = idct(odata1);
                    //distribute the boundaries differences across the previous packet
                    //and the predicted packet
                    distribute_both_packets(prev_samples, newPacket1, num_samples);
                    //overwrite the previous packet in the file
                    fseek(ofile, stream_position, SEEK_SET);
                    fwrite(prev_samples, 2, num_samples, ofile);
                    //distribute_last_packet(prev_samples[num_samples - 1], newPacket1, num_samples);
                    //for the second packet, the weights are 0.5 from the previous and
                    //0.5 from the current
                    for (kk = 0; kk < num_samples; kk++) {
                        double intermediate = abs(0.5 * dctPrev[kk] + 0.5 * dctCurr[kk]);
                        int sign = (rand()) % 2;
                        if (sign = 1) {
                            intermediate = 0 - intermediate;
                        }
                        odata2[kk] = (int) intermediate;
                    }
                    short * newPacket2 = idct(odata2);
                    //distribute the boundaries differences across the first predicted packet
                    //and the second predicted packet
                    distribute_both_packets(newPacket1, newPacket2, num_samples);
                    //for the third packet, the weights are 0.1 from the previous and
                    //0.9 from the current
                    for (kk = 0; kk < num_samples; kk++) {
                        double intermediate = abs(0.1 * dctPrev[kk] + 0.9 * dctCurr[kk]);
                        int sign = (rand()) % 2;
                        if (sign = 1) {
                            intermediate = 0 - intermediate;
                        }
                        odata3[kk] = (int) intermediate;
                    }
                    short * newPacket3 = idct(odata3);
                    //distribute the boundaries differences across the second predicted packet
                    //and the third predicted packet
                    distribute_both_packets(newPacket2, newPacket3, num_samples);
                    fwrite(newPacket1, 2, num_samples, ofile);
                    fwrite(newPacket2, 2, num_samples, ofile);
                    //already fixed 3 missing packets, so remove 3 from the number of lost packets
                    nrOfLostPackets = nrOfLostPackets - 3;
                    if (nrOfLostPackets <= 0) {
                        //just 3 missing packets, so distribute the boundaries differences across
                        //the third predicted packet and the current packet
                        distribute_both_packets(newPacket3, samples, num_samples);
                        fwrite(newPacket3, 2, num_samples, ofile);
                    } else {
                        //more then 3 missing packets, so no point in fixing the boundaries
                        //just write the third packet, and fill the rest with silence
                        fwrite(newPacket3, 2, num_samples, ofile);
                        while (nrOfLostPackets > 0) {
                            write_silence(ofile, num_samples);
                            nrOfLostPackets--;
                        }
                    }
                }
                break;
            }
            default:
                abort();
        }
    }
    /* hold onto the stream position before writing the current packet 
     * we may need it for overwriting the previous packet, after fixing the
     * boundaries */
    stream_position = ftell(ofile);
    fwrite(samples, 1, num_samples * 2, ofile);
    /* hold onto the last received packet - we may need it */
    if (prev_samples != 0)
        free(prev_samples);
    prev_samples = samples;
    prev_seqno = seqno;
};
