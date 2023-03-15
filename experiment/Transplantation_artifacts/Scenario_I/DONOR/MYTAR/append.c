
#include "archiver.h"

int append_file (struct archive *archive, char *file_name) {
    struct descr *new_descr = archive->file_descriptors + archive->files_count;
    if (archive->files_count) {
        struct descr *last_descr = new_descr - 1;
        new_descr->data_start = last_descr->data_start + last_descr->data_length;
    }
    else
        new_descr->data_start = 0;
    struct stat stat_data;
    if (-1 == stat (file_name, &stat_data)) {
        return 0;
    }
    new_descr->data_length = stat_data.st_size;
    int fd = open (file_name, O_RDONLY);
    if (-1 == fd) {
        return 0;
    }
    void *file_data = mmap (NULL, new_descr->data_length, PROT_READ, MAP_PRIVATE, fd, 0);
    if (MAP_FAILED == file_data) {
        close (fd);
        return 0;
    }
    check_io_errors (write (archive -> fd, file_data, new_descr -> data_length), "write()");
    munmap (file_data, new_descr -> data_length);
    close (fd);
    strncpy (new_descr -> file_name, file_name, 255);
    return ++archive->files_count;
}

int write_archive_data (char *input_file_name, struct archive *archive) {
    lseek (archive -> fd, archive -> headers_offset, SEEK_END);
    printf ("Archive %s: writing file %s\n", archive -> file_name, input_file_name);
    append_file (archive, input_file_name);
    return 0;
}

void write_archive (char *in_file, struct archive *archive) {
    char *input_file = (char *) malloc (1000 * sizeof (char));
    strcpy (input_file, in_file);
    write_archive_data (input_file, archive);
    write_archive_header (archive);
}

