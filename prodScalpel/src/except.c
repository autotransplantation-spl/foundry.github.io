//
//
//  except.c
//
//  Created by --- on 23/10/17.
//  Copyright (c) 2017 ---. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "except.h"
#include "Utils.h"


void txlErrorMessage(char * txlFile){

    int c;
    FILE *file;
    file = fopen("errorFile.out", "r");

    if (file) {
        const size_t line_size = 300;
        char* line = malloc(line_size);
        printf("\n===========================================================\n");
        while (fgets(line, line_size, file) != NULL)  {
            printf(line);
        }
        printf("\n===========================================================\n");
        free(line);

        fclose(file);
    }else{
        printf("file does not exists \"ErrorFile\"");
    }
}