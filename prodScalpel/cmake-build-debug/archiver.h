
#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <stdint.h>

#include <getopt.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>

#include <errno.h>

#include <string.h>

#include <sys/mman.h>
int h;
enum commands {COM_UNKNOWN = 0, COM_APPEND, COM_LIST, COM_CREATE};
struct archive {
    enum commands command;
    char *file_name;
    int fmode;
    int fd;
    uint32_t files_count;
    size_t append_files_count;
    size_t headers_offset;
    struct descr *file_descriptors;
};
struct descr {
    char file_name [256];
    size_t data_length;
    size_t data_start;
} __attribute__ ((packed));
