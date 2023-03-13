#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <check.h>
#include "InterfaceHeader.h"

typedef struct window_S        win_T;

typedef unsigned char    char_u;
typedef char_u schar_T;
EXTERN win_T    *curwin;    /* currently active window */


/*
 * 
 */
int compare_size_two_words(char_u *fp1, char_u *fp2) {
    
    char_u ch1, ch2;
    
    if (strlen(fp1) == strlen(fp2)) {
        printf("Two string are not equal : %s != %s",fp1,fp2);
        return 1;
    } else {
        printf("Two string are Equal\n ", fp1,fp2);
        return 0;
    }
}


START_TEST(test_1) {
    char_u    *word = (char_u *)"";
    hlf_T    attr = HLF_COUNT;
    int        len = 0;
    int    capcol = -1;

    char_u    *str = "wong";
    
    
    int spell_check_TRANSPLANT_RESULT = 0;
    spell_check_TRANSPLANT_RESULT = spell_check_GRAFT_INTERFACE(NULL, str, &attr, &capcol, FALSE);
    
    if(spell_check_TRANSPLANT_RESULT == 0 ){
        ck_abort();
    }
  /*  if (compare_size_two_words(str, spell_check_TRANSPLANT_RESULT)) {
        ck_abort();
    }*/
    
}

END_TEST


Suite *
money_suite(void) {
    Suite *s = suite_create("GenTransSuite");
    // Core test case 
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_1);
    suite_add_tcase(s, tc_core);
    return s;
}
int main(int argc, char** argv) {
    int number_failed;
    Suite *s = money_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

