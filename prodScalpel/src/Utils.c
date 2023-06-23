#include "Utils.h"
#include "GenTrans.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
//#include <malloc.h>
#include <string.h>
#include <sys/stat.h>
#define __USE_XOPEN_EXTENDED

//LOS
#include <ctype.h>
#include "ListOfFunctionSourceFile.h"
#include <time.h>


void replace_multi_space_with_single_space(char *str)
{
    char *dest = str;  /* Destination to copy to */

    /* While we're not at the end of the string, loop... */
    while (*str != '\0')
    {
        /* Loop while the current character is a space, AND the next
         * character is a space
         */
        while (*str == ' ' && *(str + 1) == ' ')
            str++;  /* Just skip to next character */

        /* Copy from the "source" string to the "destination" string,
         * while advancing to the next character in both
         */
        *dest++ = *str++;
    }

    /* Make sure the string is properly terminated */
    *dest = '\0';
}

char * removeSpaceInString(char * str){
    int len = strlen(str); //só pra dar melhor performance
    replace_multi_space_with_single_space(str);

    for (int i = 0, position = 0; i < len; i++, position++) {
        /*if (str[0] == ' ') {
            position++;
            while(str[position] == ' ')
                position++;
        }*/
       /* if (str[position] == ' ' && str[position+1] == ' ') {
            position++;
            while(str[position] == ' ')
                position++;
        }*/
        if (str[position] == '\t') {
            str[i] = ' ';
            i++;
            position++;
            while(str[position] == '\t')
                position++;
        }

        str[i] = str[position];
    }

    return str;
}

char * removeArraySizeInString(char * originalString) {
    char * newString = (char *) malloc((strlen(originalString) + 1) * sizeof (char));
    strcpy(newString, originalString);

    int signal = 1;

    while (signal) {
        signal = 0;
        char * position = strstr(newString, "[");
        if (position) {
            if (* (position + 1) != ']') {
                signal = 1;
                int i =0;
                while (* (position + 1) != ']') {
                    memmove(position + 1, position + 2, sizeof(char*));
                }

            }
        }

    }
    return newString;
}

char* str_replace(char* string, const char* substr, const char* replacement) {
    char* tok = NULL;
    char* newstr = NULL;
    char* oldstr = NULL;
    int   oldstr_len = 0;
    int   substr_len = 0;
    int   replacement_len = 0;

    newstr = strdup(string);
    substr_len = strlen(substr);
    replacement_len = strlen(replacement);

    if (substr == NULL || replacement == NULL) {
        return newstr;
    }

    while ((tok = strstr(newstr, substr))) {
        oldstr = newstr;
        oldstr_len = strlen(oldstr);
        newstr = (char*)malloc(sizeof(char) * (oldstr_len - substr_len + replacement_len + 1));

        if (newstr == NULL) {
            free(oldstr);
            return NULL;
        }

        memcpy(newstr, oldstr, tok - oldstr);
        memcpy(newstr + (tok - oldstr), replacement, replacement_len);
        memcpy(newstr + (tok - oldstr) + replacement_len, tok + substr_len, oldstr_len - substr_len - (tok - oldstr));
        memset(newstr + oldstr_len - substr_len + replacement_len, 0, 1);

        free(oldstr);
    }

    free(string);

    return newstr;
}


char *replace_str(char *str, char *orig, char *rep)
{
  static char buffer[4096];
  char *p;

  if(!(p = strstr(str, orig)))  // Is 'orig' even in 'str'?
    return NULL;
  fflush(stdout);
  strncpy(buffer, str, p-str); // Copy characters from 'str' start to 'orig' st$
  buffer[p-str] = '\0';

  sprintf(buffer+(p-str), "%s%s", rep, p+strlen(orig));

  return buffer;
}
// Function to replace a string with another
// string
/*
///LOSCHANGED CASE STUDY
char* replace_str(char* s, char* oldW, char* newW)
{
    char* result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);

    // Counting the number of times old word
    // occur in the string
    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], oldW) == &s[i]) {
            cnt++;

            // Jumping to index after the old word.
            i += oldWlen - 1;
        }
    }

    // Making new string of enough length
    result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1);

    i = 0;
    while (*s) {
        // compare the substring with the result
        if (strstr(s, oldW) == s) {
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result[i++] = *s++;
    }

    result[i] = '\0';
    return result;
}
*/

int isInListOfNeededFiles(char ** listOfFiles, int length, char * currentFile) {
    for (int i = 0; i < length; i++) {
        if (!strcmp(listOfFiles[i], currentFile)) {
            return 1;
        }
    }
    return 0;
}

int isInListOfNeededFunctions(char ** listOfFunctionsTarget, char * currentFile) {

    ListOfFunctionSourceFile *auxLlistOfFunctionsTarget = listOfFunctionsTarget;
    while(auxLlistOfFunctionsTarget){
        if (!strcmp(auxLlistOfFunctionsTarget->functionName, currentFile)) {
            return 1;
        }
        auxLlistOfFunctionsTarget = auxLlistOfFunctionsTarget->next;
    }
    return 0;
}

int isInListOfExtractedFunctions(char * listOfFiles, char * currentFile) {

    char * line;
    line = (char *) malloc(400 * sizeof(char));
    FILE * fout = fopen(listOfFiles, "r");
    while (fgets(line, 400, fout) != NULL) {
        if (!strcmp(line, currentFile)) {
            close(fout);
            return 1;
        }
    }
    close(fout);
    return 0;
}


/*
 * Check if a file exist using stat() function
 * return 1 if the file exist otherwise return 0
 */
int fileExists(const char* filename){
    struct stat buffer;
    int exist = stat(filename,&buffer);
    if(exist == 0)
        return 1;
    else // -1
        return 0;
}

int isInFile(char * search, char * currentFilePath) {

    char * line;
    line = (char *) malloc(400 * sizeof(char));
    FILE * fout = fopen(currentFilePath, "r");
    while (fgets(line, 400, fout) != NULL) {
        if (!strcmp(line, search)) {
            close(fout);
            return 1;
        }
    }
    close(fout);
    return 0;
}

//this functions will read the content of the input directory and will paste the needed files
//into OriginalHeader dir

void readDirContent(char * path, char** listOfNeededHeaderFiles, int length, char * outputFolder) {

    DIR *d;
    struct dirent *dir;
    char * newPath;
    newPath = (char*) malloc(500 * sizeof (char));
    strcpy(newPath, path);
    strcat(newPath, "/");
    unsigned char c;
    int source, destination;
    struct stat statbuff;

    d = opendir(path);
    chdir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            //printf("%s \n", dir->d_name);
            if (dir->d_type == 4 && strcmp(".", dir->d_name) && strcmp("..", dir->d_name)) {
                readDirContent(strcat(newPath, dir->d_name), listOfNeededHeaderFiles, length, outputFolder);
            } else if (isInListOfNeededFiles(listOfNeededHeaderFiles, length, dir->d_name)) {
                // printf("%s\n", dir->d_name);

                if (lstat(dir->d_name, &statbuff) < 0) {
                    return;
                }
                if ((source = open(dir->d_name, O_RDONLY)) < 0) {
                    return;
                }

                char * destinationPath;
                destinationPath = (char*) malloc(255 * sizeof (char));

                strcpy(destinationPath, outputFolder);
                strcat(destinationPath, dir->d_name);

                if ((destination = open(destinationPath, O_CREAT | O_TRUNC | O_WRONLY, (statbuff.st_mode & S_IRWXU) | (statbuff.st_mode & S_IRWXG) | (statbuff.st_mode & S_IRWXO))) < 0) {
                    return;
                }
                while (read(source, &c, 1) == 1) {
                    write(destination, &c, 1);
                }
                close(destination);
                close(source);

                free(destinationPath);
            }
        }

        closedir(d);
    }
    free(newPath);
}

//this function will copy the needed header files into OriginalHeaders

void copyNeededFiles(char * listOfNeededIncludeFiles, char * pathToDonor, char * transplantWorkingFolder,
        char * locationToCopyFiles) {
    
    
    /*
    
    
    
    FILE *fin = fopen(listOfNeededIncludeFiles, "r");
    char **listOfFiles = NULL;
    listOfFiles = (char**) malloc(5000 * sizeof (char*));
    for (int i = 0; i < 5000; i++) {
        listOfFiles[i] = (char*) malloc(5000 * sizeof (char));
    }
    char * line;
    line = (char *) malloc(5000 * sizeof (char));
    char * auxLine;
    auxLine = line;
    int count = 0;
    while (fscanf(fin, "%s", line) != EOF) {
        line++;
        line[strlen(line) - 1] = 0;
        line = strstr(line, "/") + 1;
        strcpy(listOfFiles[count], line);
        count++;
    }
    free(auxLine);
    fclose(fin);
    readDirContent(pathToDonor, listOfFiles, count, locationToCopyFiles);
    //free memory
    for (int i = 0; i < 5000; i++) {
        free(listOfFiles[i]);
    }
    free(listOfFiles);
     * 
     */ 
}


void prettyPrintSourceCode(char * TXLProgsPath, char * tempSkeleton, char * finalSkeleton) {
    char * commandTXL;
    commandTXL = (char *) malloc(500 * sizeof (char));
    printf("\t\t[TXL] PrettyPrintWithAnnotations.x >> Pretty print with annotations\n");
    sprintf(commandTXL, "%sPrettyPrintWithAnnotations.x %s %s %s", TXLProgsPath, tempSkeleton, finalSkeleton,
            ConsoleNullOutput);
    int status = system(commandTXL);
    if (status != 0) {
        printf("ERROR! sPrettyPrintWithAnnotations.x\n");
        printf("\t%s\n", commandTXL);
        system("open ErrorFile.out");
        fflush(stdout);
        exit(1);
    }
#ifdef DEBUGING
    else
        printf("\t\t|>> temp_final_skeleton_output.out\n");
#endif

    free(commandTXL);
}

void prettyPrintSourceCodeNoAnnotations(char * TXLProgsPath, char * source, char * destination) {
    char * commandTXL;
    commandTXL = (char *) malloc(500 * sizeof (char));
    sprintf(commandTXL, "%sprettyPrintNoAnnotations.x %s %s %s", TXLProgsPath, source, destination,
            ConsoleNullOutput);
    int status = system(commandTXL);
    if (status != 0) {
        printf("ERROR! sprettyPrintNoAnnotations.x\n");
    }
    free(commandTXL);
}

int countlines(char *filename)
{
    // count the number of lines in the file called filename
    FILE *fp = fopen(filename,"r");
    int ch=0;
    int lines=0;

    if (fp == NULL)
        return 0;

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
            lines++;
    }
    fclose(fp);
    return lines;
}

//LOS
void addLinesFromTempIntoDestinationFile(char * tempFileSource, char  * listDestination){

    FILE *fSource, *fDestination;
    fSource = fopen(tempFileSource,"r");
    fDestination = fopen(listDestination,"a+");
    char * line;
    line = (char *) malloc(400 * sizeof(char));

    while(fgets(line, 400, fSource) != NULL) {
        fprintf(fDestination, "%s", line);
    }
    fclose(fSource);
    fclose(fDestination);
    remove(fSource);
}
/*
char  *readSubstring( char *from, char *str, char * delim ) {

    char *target = NULL;
    char *start, *end;
    char targetA = NULL;
    targetA = (char *) malloc(100 * sizeof(char));
    if ( start = strstr( str, from ) )
    {
        start += strlen( from );
        if ( end = strstr( start, delim ) )
        {
            target = ( char * )malloc( end - start + 1 );
            memcpy( target, start, end - start );
            target[end - start] = '\0';

            //strcpy(targetA,target);
            //free(target);

        }
    }

    return target;
}
*/

char * readSubstring( const char *p1, const char *str, const char *p2) {
    const char *i1 = strstr(str, p1);
    if (i1 != NULL) {
        const size_t pl1 = strlen(p1);
        const char *i2 = strstr(i1 + pl1, p2);
        if (p2 != NULL) {
            const size_t mlen = i2 - (i1 + pl1);
            char *ret = (char*)malloc(sizeof(char)*(mlen + 100));
           // char *ret = (char *) malloc(500 * sizeof(char));
            if (ret != NULL) {
                memcpy(ret, i1 + pl1, mlen);
                ret[mlen] = '\0';
                return ret;
            }
        }
    }

}
/*
char * readSubstring( const char *p1, const char *str, const char *p2) {
    const char *i1 = strstr(str, p1);

    size_t len = p2-p1;
    char *res = (char*)malloc(sizeof(char)*(len+1));
    strncpy(res, p1, len);
    res[len] = '\0';
    return res;
}*/

static void removeSpecialCharacter(char *data)
{
    unsigned long i = 0; /* Scanning index */
    unsigned long x = 0; /* Write back index */
    char c;

    while ((c = data[i++]) != '\0') {
        if (isalnum(c)) {
            data[x++] = c;
        }
    }

    data[x] = '\0';
}


int isValidFuncitonName(char *data)
{
    unsigned long i = 0; /* Scanning index */
    unsigned long x = 0; /* Write back index */

    char c;

    for (int i = 0; i < strlen(data); ++i) {
        if (!isalnum(data[i])) {
            return 1;
        }
    }
    return 0;
}

int get_size(const char* file_name)
{
    FILE *file = fopen(file_name, "r");

    if(file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}

/**
 * Remove first occurrence of a word from string
 */
void removeFirst(char * str, const char * toRemove)
{
    int i, j;
    int len, removeLen;
    int found = 0;

    len = strlen(str);
    removeLen = strlen(toRemove);

    for(i=0; i<len; i++)
    {
        found = 1;
        for(j=0; j<removeLen; j++)
        {
            if(str[i+j] != toRemove[j])
            {
                found = 0;
                break;
            }
        }

        /* If word has been found then remove it by shifting characters  */
        if(found == 1)
        {
            for(j=i; j<=len-removeLen; j++)
            {
                str[j] = str[j + removeLen];
            }

            // Terminate from loop so only first occurrence is removed
            break;
        }
    }
}


char * getTime(){
    time_t current_time;
    char* c_time_string;

    /* Obtain current time. */
    current_time = time(NULL);

    if (current_time == ((time_t)-1))
    {
        (void) fprintf(stderr, "Failure to obtain the current time.\n");
        exit(EXIT_FAILURE);
    }

    /* Convert to local time format. */
    c_time_string = ctime(&current_time);

    if (c_time_string == NULL)
    {
        (void) fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }
    return c_time_string;
    /* Print to stdout. ctime() has already added a terminating newline character. */
   // (void) printf("Current time is %s", c_time_string);
  //  exit(EXIT_SUCCESS);

}

/* STACK */
// C program for array implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>



// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createAStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;

}

// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    printf("pop to stack\n");
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}