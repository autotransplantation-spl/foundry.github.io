
#include "archiver.h"

int cleanup (struct archive *a) {
    close (a -> fd);
    free (a -> file_descriptors);
    return 0;
}

int check_io_errors (int ret_code, const char *operation) {
    if (-1 == ret_code) {
        exit (- 1);
    }
    return ret_code;
}

int open_archive_file (struct archive *archive) {
    archive->fd = open (archive->file_name, archive->fmode, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    return 1;
}

