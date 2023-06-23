#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    FILE * fin = fopen("/home/alex/NetBeansProjects/HostExample/input.in", "r");
    FILE * fout = fopen("output.out", "w");
    int * arrayC;
    const int length;
    fscanf(fin, "%d", &length);
    arrayC = (int *) malloc((length + 1) * sizeof (int));
    for (int i = 0; i < length; i++) {
        fscanf(fin, "%d", &arrayC[i]);
    }
    for (int i = 0; i < length; i++) {
        fprintf(fout, "%d ", arrayC[i]);
    }
    __ADDGRAFTHERE__JUSTHERE
    return (EXIT_SUCCESS);
}

