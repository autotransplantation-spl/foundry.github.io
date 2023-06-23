#include "interpolate.h"

/* read in the Wav file header from the input file, sanity check it,
   and write it to the output file */

/* we only cope with 16KHz sampled 16-bit linear mono audio.  That's
   sufficient for proof of concept, but a real implementation would
   obviously be somewhat more flexible */

int process_wav_header(FILE *ifile, FILE *ofile, int msPerPacket, int *bytesPerPacket) {
  char buf[4096];
  char teststr[5];
  size_t size;
  struct riffchunkhdr* riffhdr;
  struct fmthdr* fhdr;
  struct datahdr* dhdr;
  size = fread(buf, 1, sizeof(struct riffchunkhdr), ifile);
  if (size < sizeof(struct riffchunkhdr)) {
    fprintf(stderr, "Too few bytes in wav header: %u\n", (unsigned int)size);
    exit(1);
  }
  riffhdr = (struct riffchunkhdr*)buf;

  /* sanity checks - check it's a WAV file */
  printf("=====RIFF HEADER=====\n");
  strncpy(teststr, (char*)&(riffhdr->chunkID), 4);
  printf("ChunkID: %s\n", teststr);
  if (strcmp(teststr, "RIFF")!=0) {
    fprintf(stderr, "File is not a RIFF file\n");
    exit(1);
  }
  printf("ChunkSize: %u\n", riffhdr->chunkSize);
  strncpy(teststr, (char*)&(riffhdr->format), 4);
  printf("Format: %s\n", teststr);
  if (strcmp(teststr, "WAVE")!=0) {
    fprintf(stderr, "File is not a WAVE file\n");
    exit(1);
  }
  fwrite(buf, 1, sizeof(struct riffchunkhdr), ofile);

  size = fread(buf, 1, sizeof(struct fmthdr), ifile);
  if (size < sizeof(struct fmthdr)) {
    fprintf(stderr, "Too few bytes in fmt header: %u\n", (unsigned int)size);
    exit(1);
  }
  fhdr = (struct fmthdr*)buf;


  strncpy(teststr, (char*)&(fhdr->subChunk1ID), 4);
  printf("SubChunk1ID: %s\n", teststr);
  if (strcmp(teststr, "fmt ")!=0) {
    fprintf(stderr, "File has incorrect format\n");
    exit(1);
  }

  printf("SubChunk1Size: %d\n", fhdr->subChunk1Size);
  if (fhdr->subChunk1Size != 16) {
    fprintf(stderr, "File is not a PCM file\n");
    exit(1);
  }

  printf("AudioFormat: %d ", fhdr->audioFormat);
  if (fhdr->audioFormat != 1) {
    fprintf(stderr, "File is not a PCM file\n");
    exit(1);
  }
  printf(" (linear encoding)\n");  

  printf("NumChannels:  %d ", fhdr->numChannels);
  if (fhdr->numChannels != 1) {
    fprintf(stderr, "File is not mono - we don't handle stereo!\n");
    exit(1);
  }
  printf(" (mono)\n");  

  printf("SampleRate:  %d\n", fhdr->sampleRate);
  if (fhdr->sampleRate != 16000) {
    fprintf(stderr, "We only handle 16KHz sampling\n");
    exit(1);
  }

  printf("BlockAlign: %d\n", fhdr->blockAlign);
  if (fhdr->blockAlign != 2) {
    fprintf(stderr, "Incorrect block align\n");
    exit(1);
  }

  printf("BitsPerSample: %d\n", fhdr->bitsPerSample);
  if (fhdr->bitsPerSample != 16) {
    fprintf(stderr, "Code assumes 16 bits per sample\n");
    exit(1);
  }
  fwrite(buf, 1, sizeof(struct fmthdr), ofile);

  size = fread(buf, 1, sizeof(struct datahdr), ifile);
  if (size < sizeof(struct datahdr)) {
    fprintf(stderr, "Too few bytes in data header: %u\n", (unsigned int)size);
    exit(1);
  }
  dhdr = (struct datahdr*)buf;

  strncpy(teststr, (char*)&(dhdr->subChunk2ID), 4);
  printf("SubChunk2ID: %s\n", teststr);
  if (strcmp(teststr, "data")!=0) {
    fprintf(stderr, "Data chunk has incorrect header\n");
    exit(1);
  }
  
  printf("Data length: %u\n", dhdr->subChunk2Size);
  printf("=====END OF HEADER=====\n");
  fwrite(buf, 1, sizeof(struct datahdr), ofile);


  *bytesPerPacket = ((fhdr->bitsPerSample/8) * fhdr->sampleRate * msPerPacket)/1000;
  printf("bytesPerPacket: %d\n", *bytesPerPacket);

  return dhdr->subChunk2Size;
}

