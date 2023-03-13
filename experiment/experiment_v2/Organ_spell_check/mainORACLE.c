#include "InterfaceHeader.h"


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <check.h>


int main(int argc, char** argv) {

	write_archive_GRAFT_INTERFACE("RESULT_MYTAR_ORIGINAL.TAR", "FILE.in");

    return 0;
    //  return (EXIT_SUCCESS);
}




/*
int main () {
   
    FILE *fin = fopen ("/home/alex/NetBeansProjects/HostExample/input.in", "r");
    FILE *fout = fopen ("output.out", "w");
    
    int *arrayC;
    int length;
    fscanf (fin, "%d", & length);
    arrayC = (int *) malloc ((length + 1) * sizeof (int));
    int i;
    for (i = 0; i < length; i++) {
        fscanf (fin, "%d", & arrayC [i]);
    }
    for (i = 0; i < length; i++) {
        fprintf (fout, "%d ", arrayC [i]);
    }
    
    
    
    //result: 45 39 -104 61 7 -44 42 -20 45 -85
    int length = 10;
    int myArray[10] = { 3, 45, 1, 67, 8, 98, 12, -12, -133, 0 };
    
    
    short *TRANSPLANT_RESULT;
    TRANSPLANT_RESULT = GRAFT_INTERFACE (length, myArray, NULL, NULL);
    return (EXIT_SUCCESS);
}
 */
