/*
 Ice-box test for transplanting the organ write_archive
 */
#include "InterfaceHeader.h"

#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <check.h>


int file_exists(char * filename)
{
   FILE * file;
   file = fopen(filename, "r");

    if (file) {
        fclose(file);
        return 0;
    }
    return 1;
}

int compare_two_binary_files (FILE *fp1, FILE *fp2) {
    char ch1, ch2;
    int flag = 0;
    while (((ch1 = fgetc (fp1)) != EOF) && ((ch2 = fgetc (fp2)) != EOF)) {
        if (ch1 == ch2) {
            flag = 1;
            continue;
        }
        else {
            fseek (fp1, - 1, SEEK_CUR);
            flag = 0;
            break;
        }
    }
    if ((fgetc (fp1) != EOF) || (fgetc (fp2) != EOF)) {
        flag = 0;
    }
    if (flag == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

START_TEST (test_1) {
    char * commandRemoveOldFile = "rm TEXT.txt";
    system (commandRemoveOldFile);
    
    write_archive_GRAFT_INTERFACE (NULL, "TEXT.txt", "FILE.in");
    
    FILE * resultedFile = fopen("TEXT.txt", "r");
    FILE * oracleFile = fopen("TEXT_ORACLE.txt", "r");
    if (compare_two_binary_files (resultedFile, oracleFile)) {
        ck_abort ();
    }
}


END_TEST Suite *money_suite (void) {
    Suite *s = suite_create ("GenTransSuite");
    TCase *tc_core = tcase_create ("Core");
    tcase_add_test (tc_core, test_1);
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

