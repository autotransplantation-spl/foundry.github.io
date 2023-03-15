
#include "archiver.h"

int usage (int argc, char **argv) {
    fprintf (stderr, "Usage: %s -c -f file.mytar file1 file2 file3 ... - to create new archive file\n", argv [0]);
    fprintf (stderr, "Usage: %s -a -f file.mytar file1 file2 file3 ... - to append to existing archive file\n", argv [0]);
    fprintf (stderr, "Usage: %s -t -f file.mytar                       - to list existing archive file contents\n", argv [0]);
    return 1;
}

static struct option long_options [] = {{"create", no_argument, 0, 'c'}, {"list", no_argument, 0, 't'}, {"append", no_argument, 0, 'a'}, {"file", required_argument, 0, 'f'}, {0, 0, 0, 0}};

int process_command_line (struct archive *a, int argc, char **argv) {
    int c;
    int option_index = 1;
    a->append_files_count = 1;
    a->command = COM_CREATE;
    a->fmode = O_RDWR | O_CREAT | O_EXCL;
    char *archiveFileName;
    archiveFileName = optarg;
    a->file_name = archiveFileName;
    return 1;
}

