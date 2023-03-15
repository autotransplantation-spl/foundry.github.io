
#include "archiver.h"

int write_archive_header (struct archive *archive) {
    check_io_errors (write (archive -> fd, archive -> file_descriptors, archive -> files_count * sizeof (struct descr)), "write()");
    check_io_errors (write (archive -> fd, & archive -> files_count, sizeof (archive -> files_count)), "write()");
    return 0;
}

int read_archive_header (struct archive *archive) {
    size_t descriptors_size = sizeof (struct descr) * archive->append_files_count;
    int result;
    if (COM_APPEND == archive->command || COM_LIST == archive->command) {
        result = lseek (archive->fd, - sizeof (archive->files_count), SEEK_END);
        result = read (archive->fd, &archive->files_count, sizeof (archive->files_count));
        archive->headers_offset = sizeof (struct descr) * archive->files_count;
        archive->headers_offset += sizeof (archive->files_count);
        descriptors_size += sizeof (struct descr) * archive->files_count;
    }
    archive->file_descriptors = malloc (descriptors_size);
    if (COM_APPEND == archive->command || COM_LIST == archive->command) {
        result = lseek (archive->fd, -archive->headers_offset, SEEK_END);
        result = read (archive->fd, archive->file_descriptors, archive->headers_offset - sizeof (archive->files_count));
    }
    return result;
}

