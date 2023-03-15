
#include "archiver.h"

int list_archive_content (struct archive *archive) {
    fprintf (stdout, "%d files in archive\n", archive -> files_count);
    struct descr *cur_descr = archive->file_descriptors;
    int index;
    for (index = 0; index < archive->files_count; index++, cur_descr++) {
        fprintf (stdout, "Offset: %lu\tLength: %lu\tName: %s\n", cur_descr -> data_start, cur_descr -> data_length, cur_descr -> file_name);
    }
    return 0;
}

