
#include "vi.h"

#include "conf.h"

#include "kmap.h"

#include "regex.h"

#include "InterfaceHeader.h"

#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <check.h>

int file_exists (char *filename) {
    FILE *file;
    file = fopen (filename, "r");
    if (file) {
        fclose (file);
        return 0;
    }
    return 1;
}

START_TEST (test_1) {
    char *commandRemoveOldFile = "rm RESULT_MYTAR.TAR";
    system (commandRemoveOldFile);
    dir_init_GRAFT_INTERFACE (NULL, "NEATVI", 1, 0);
    if (dir_rslr == NULL) {
        ck_abort ();
    }
}

START_TEST (test_2) {
    char *commandRemoveOldFile = "rm RESULT_MYTAR.TAR";
    system (commandRemoveOldFile);
    dir_init_GRAFT_INTERFACE (NULL, "NEATVI", 1, 0);
    if (dir_rsrl == NULL) {
        ck_abort ();
    }
}

START_TEST (test_3) {
    char *commandRemoveOldFile = "rm RESULT_MYTAR.TAR";
    system (commandRemoveOldFile);
    dir_init_GRAFT_INTERFACE ();
    if (dir_rsctx == NULL) {
        ck_abort ();
    }
}

END_TEST Suite *money_suite (void) {
    Suite *s = suite_create ("GenTransSuite");
    TCase *tc_core = tcase_create ("Core");
    tcase_add_test (tc_core, test_1);
    tcase_add_test (tc_core, test_2);
    tcase_add_test (tc_core, test_3);
    suite_add_tcase (s, tc_core);
    return s;
}

int main (int argc, char **argv) {
    int number_failed;
    Suite *s = money_suite ();
    SRunner *sr = srunner_create (s);
    srunner_run_all (sr, CK_SILENT);
    printf ("\n\n");
    srunner_print (sr, CK_NORMAL);
    number_failed = srunner_ntests_failed (sr);
    srunner_free (sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

