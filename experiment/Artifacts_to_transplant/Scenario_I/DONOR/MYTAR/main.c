
#include "archiver.h"
struct archive archive = {0};

int main (int argc, char **argv) {
    process_command_line (& archive, argc, argv);
    open_archive_file (& archive);
    switch (archive.command) {
    case COM_CREATE :
        {
            char *in_file = argv[argc - 1];
            read_archive_header (& archive);
            write_archive (in_file, & archive);
            break;
        }
    case COM_APPEND :
        {
        }
    case COM_LIST :
        {
            read_archive_header (& archive);
            list_archive_content (& archive);
            break;
        }
    case COM_UNKNOWN :
        {
        }
    default :
        {
            cleanup (& archive);
            return (usage (argc, argv));
        }
    }
    cleanup (& archive);
    return 0;
}

