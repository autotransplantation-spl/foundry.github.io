/*
 * main.c
 * FolderContent
 *
 * Created by Marginean ---andru on 09/03/14.
 * Copyright (c) 2014 Marginean ---andru. All rights reserved.
 *
 * Edited by --- on 14 January 2018, 22:54
 *   - Add functions: renameFileToFunctionName and generateCallGraphs
 */
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include "GenTrans.h"
#include "folderContent.h"

char isUserRule(rulename)
char rulename[256];
{
    return ((strcmp(rulename, "getid") == 0) || (strcmp(rulename, "sum") == 0));
}

int recursiveDelete(char* dirname) {

    DIR *dp;
    struct dirent *ep;

    char abs_filename[FILENAME_MAX];

    dp = opendir (dirname);
    if (dp != NULL)
    {
        while (ep = readdir (dp)) {
            struct stat stFileInfo;

            snprintf(abs_filename, FILENAME_MAX, "%s/%s", dirname, ep->d_name);

            if (lstat(abs_filename, &stFileInfo) < 0)
                perror ( abs_filename );

            if(S_ISDIR(stFileInfo.st_mode)) {
                if(strcmp(ep->d_name, ".") &&
                   strcmp(ep->d_name, "..")) {
                    printf("%s directory\n",abs_filename);
                    recursiveDelete(abs_filename);
                }
            } else {
                printf("%s file\n",abs_filename);
                remove(abs_filename);
            }
        }
        (void) closedir (dp);
    }
    else
        perror ("Couldn't open the directory");


    remove(dirname);
    return 0;

}

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

/* LOS rename file to function name in order to be used by callGraphParser
 * */
void renameFileToFunctionName( char * path, char * fileType){

    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    if(d){
        while ((dir = readdir(d)) != NULL) {
            if (strstr(dir->d_name, fileType)){
                char * filePath;
                filePath = (char *) malloc(500 * sizeof(char));
                sprintf(filePath, "%s%s", path, dir->d_name);
                FILE *fileStream = fopen(filePath, "r");
                char * line;
                line = (char *) malloc(4000 * sizeof (char));
                char * functionName;
                if (fgets(line,300, fileStream)){
                    functionName = strstr(line, " ")+2;
                    strtok(functionName, "\"");
                    strcat(functionName,fileType);
                    char * newFileName = (char *) malloc(500 * sizeof(char));;
                    sprintf(newFileName, "%s%s", path,functionName);
                   // printf("\tRenaming: %s\n", filePath);
                    rename(filePath, newFileName);
                }
                fclose(fileStream);
            }
        }
    }
}

int copyFilesFromADirToAnother(char * src, char * dest) {
    char *commandCopyInterface = NULL;
    commandCopyInterface = (char *) malloc(5000 * sizeof(char));
    fflush(stdout);
    sprintf(commandCopyInterface, "cp -R %s* %s", src, dest);
    int commandCopyStatus = system(commandCopyInterface);

    return commandCopyStatus;

}

int copyAFilesToAnotherAtBegging(char * src, char * dest) {

    FILE *fpSource, *fpDestination;

    // opening files
    fpSource = fopen(src, "a+");
    fpDestination = fopen(dest, "a+");

    // If file is not found then return.
    if (!fpSource && !fpDestination) {
        printf("ERROR: Unable to open %d file\n", src);
        return 0;
    }

    // If file is not found then return.
    if (!fpDestination) {
        printf("ERROR: Unable to open %d file\n", dest);
        return 0;
    }

    char buf[100];

    fprintf(fpDestination, "\n");

    // writing the contents of
    // source file to destination file.
    while (!feof(fpSource)) {
        fgets(buf, sizeof(buf), fpSource);
        fprintf(fpDestination, "%s", buf);
    }

    rewind(fpDestination);

    // printing contents of
    // destination file to stdout.
    while (!feof(fpDestination)) {
        fgets(buf, sizeof(buf), fpDestination);
        printf("%s", buf);
    }
}

int isDirectory(const char* name)
{
    DIR* directory = opendir(name);

    if(directory != NULL)
    {
        closedir(directory);
        return 0;
    }else{
        int dir_result = mkdir(name, 0777); // Create file case it does not exits
        if (dir_result > 0)
            return 0;
    }

    if(errno == ENOTDIR)
    {
     return 1;
    }

    return -1;
}

// C
int copySpecificFilesFromADirToAnother(char * src, char * dest, char * fileType ) {

    int checkDiretory = isDirectory(dest); // Check if dest directory exits. If not create one.

    if(checkDiretory)
        printf("[AUTOSCALPEL] Creating Directory");

    char *commandCopyInterface = NULL;
    commandCopyInterface = (char *) malloc(5000 * sizeof(char));
    sprintf(commandCopyInterface, "find %s -name \"*%s\" -exec cp {} %s \\;", src, fileType, dest);
    int commandCopyStatus = system(commandCopyInterface);

    if(commandCopyStatus)
        printf("ERRO: There is no %s Directory and It could'nt be created.",dest);

    return commandCopyStatus;

}


int removeSpecificTypeOfFileFromDirectory(char * dirPath, char * fileType) {
    DIR *dir = opendir(dirPath);
    if (dir) {
        /* Directory exists. */
        closedir(dir);
        char *commandCleanDempDonorSourceFileFolder = NULL;
        commandCleanDempDonorSourceFileFolder = (char *) malloc(1000 * sizeof(char));
        sprintf(commandCleanDempDonorSourceFileFolder, "cd %s \n rm -r *.%s", dirPath, fileType);
        int comandStatus = system(commandCleanDempDonorSourceFileFolder);
    } else {
        int dir_result = mkdir(dirPath, 0777);
        if (dir_result > 0) {
           return 0;
        }
    }
    return 1;
}



int removeAllFilesFromADirectory(char * dirPath) {
    DIR *dir = opendir(dirPath);
    if (dir) {
        /* Directory exists. */
        closedir(dir);
        char *commandCleanDempDonorSourceFileFolder = NULL;
        commandCleanDempDonorSourceFileFolder = (char *) malloc(1000 * sizeof(char));
        sprintf(commandCleanDempDonorSourceFileFolder, "cd %s \n rm -r *", dirPath);
        int comandStatus = system(commandCleanDempDonorSourceFileFolder);
    } else {
        int dir_result = mkdir(dirPath, 0777);
        if (dir_result > 0) {
           return 0;
        }
    }
    return 1;
}


int removeAFileFromADirectory(char * filePath) {
    char *commandCleanDempDonorSourceFileFolder = NULL;
    commandCleanDempDonorSourceFileFolder = (char *) malloc(1000 * sizeof(char));
    sprintf(commandCleanDempDonorSourceFileFolder, "rm -r %s", filePath);
    int comandStatus = system(commandCleanDempDonorSourceFileFolder);

    if(comandStatus != 0)
        return 0;

    return 1;
}


// TODO Handly error

int removeFilesTempDoxygenAutoScalpelDirectory(char * dirPath) {
    DIR *dir = opendir(dirPath);
    if (dir) {
        /* Directory exists. */
        closedir(dir);
        char *commandCleanDempDonorSourceFileFolder = NULL;
        commandCleanDempDonorSourceFileFolder = (char *) malloc(1000 * sizeof(char));
        sprintf(commandCleanDempDonorSourceFileFolder, "find %s -name \"*.*\" -exec rm {} \\;", dirPath);
        int comandStatus = system(commandCleanDempDonorSourceFileFolder);
    } else {
        int dir_result = mkdir(dirPath, 0777);
        if (dir_result > 0) {
           return 0;
        }
    }
    return 1;
}

int copyFilesFromDir(char * src, char * dest, char * fileType ) {

    int isDirectoryStatus = isDirectory(dest); // Check if dest directory exits. If not create one.
    char *commandCopyInterface = NULL;
    commandCopyInterface = (char *) malloc(5000 * sizeof(char));
    sprintf(commandCopyInterface, "find %s -name \"*%s\" -exec cp {} %s \\;", src, fileType, dest);
    int commandCopyStatus = system(commandCopyInterface);
    return commandCopyStatus;
}

int copyAFileFromDirToOther(char * src, char * dest) {

    char *commandCopyFile = (char *) malloc(500 * sizeof(char));
    sprintf(commandCopyFile, "cp -r %s %s", src, dest);

    if (system(commandCopyFile) != 0) {
        printf("ERROR: Copy Host with interface header to TestSuites directory. \n\tNo such file or directory: %s\n",src);
        exit(1);
    }
}


/*
void addNewString(ListOfString ** head, char * string) {
    ListOfString * newEl = (ListOfString *) malloc(1 * sizeof (ListOfString));
    newEl->el = (char *) malloc((strlen(string) + 1) * sizeof (char *));
    strcpy(newEl->el, string);
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfString * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}*/
void readFilesFromDirWithFormat(char * path, FILE * fout, char * endChar) {
    DIR *d;
    struct dirent *dir;

    if (!(d = opendir(path)))
        return;

    while ((dir = readdir(d)) != NULL) {
        if (dir->d_type == DT_DIR) {
            char * newPath;
            newPath = (char*) malloc(1000 * sizeof (char));
            strcpy(newPath, path);
            if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
                continue;
            strcat(newPath, dir->d_name);
            strcat(newPath, "/");

            readFilesFromDir(newPath, fout, endChar);
            free(newPath);
        } else
        if (strstr(dir->d_name, endChar) ){
            fprintf(fout, "\"%s%s\"\n", path, dir->d_name);
        }
    }

}
void readFilesFromDir(char * path, FILE * fout, char endChar) {
    DIR *d;
    struct dirent *dir;

    if (!(d = opendir(path)))
        return;

    while ((dir = readdir(d)) != NULL) {
        if (dir->d_type == DT_DIR) {
            char * newPath;
            newPath = (char*) malloc(1000 * sizeof (char));
            strcpy(newPath, path);
            if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
                continue;
            strcat(newPath, dir->d_name);
            strcat(newPath, "/");

            readFilesFromDir(newPath, fout, endChar);
            free(newPath);
        } else
        if (dir->d_name[strlen(dir->d_name) - 1] == endChar && dir->d_name[strlen(dir->d_name) - 2] == '.') {


            //fprintf(fout, "%s%s\n", path, dir->d_name);
            fprintf(fout, "\"%s%s\"\n", path, dir->d_name);
            //fprintf("\"%s%s\" \n", path, dir->d_name);
        }
    }

}
//LOSCHANGE ajust function to selection only files that end with '.c'
/*
void readFilesFromDir(char * path, FILE * fout, char endChar) {
    DIR *d;
    struct dirent *dir;
    char * newPath;
    newPath = (char*) malloc(500 * sizeof (char));
    strcpy(newPath, path);
    d = opendir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_type == 4 && strcmp(".", dir->d_name) && strcmp("..", dir->d_name)) {
                
                
                //void readDirContent(char * path, char** listOfNeededHeaderFiles, int length, char * outputFolder)
                strcat(newPath, dir->d_name);
                strcat(newPath, "/");
                readFilesFromDir(newPath, fout, endChar);
            } else if (dir->d_name[strlen(dir->d_name) - 1] == endChar && dir->d_name[strlen(dir->d_name)] == '\0' && dir->d_name[strlen(dir->d_name)-2] == '.'){
                fprintf(fout, "\"%s%s\" ", path, dir->d_name);
                //printf("\"%s%s\" \n", path, dir->d_name);
            }
        }
        closedir(d);
    }
  //  free(newPath);
}*/
//LOS ANALYSIS
void countFunctionFilesFromDir(char * path, FILE * fout, char * endChar) {
    DIR *d;
    struct dirent *dir;
    char * newPath;
    newPath = (char*) malloc(500 * sizeof (char));
    strcpy(newPath, path);
    d = opendir(path);
    int countFunctions = 0;
    char *word;
    word = (char *) malloc(500 * sizeof(char));

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strstr(dir->d_name, ".dot")) {
                char *sourceFile = NULL;
                sourceFile = (char *) malloc(500 * sizeof(char));

                sprintf(sourceFile, "%s%s", path, dir->d_name);

                FILE *fSourceFile = fopen(sourceFile, "r");

                while (fscanf(fSourceFile, "%s", word) != EOF){
                    if (strstr(word, "label=")) {
                        countFunctions = countFunctions + 1;
                    }
                }
                fprintf(fout, "%s, %d\n", dir->d_name, countFunctions);
                printf("File: %s%d\n", dir->d_name, countFunctions);

                fclose(fSourceFile);
                countFunctions = 0;

            }

            }
    }
    closedir(d);
    free(newPath);
}

void readFilesFromDirWithOutQuotationMarks(char * path, FILE * fout, char endChar) {
    DIR *d;
    struct dirent *dir;
    char * newPath;
    newPath = (char*) malloc(500 * sizeof (char));
    strcpy(newPath, path);
    d = opendir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_type == 4 && strcmp(".", dir->d_name) && strcmp("..", dir->d_name)) {


                //void readDirContent(char * path, char** listOfNeededHeaderFiles, int length, char * outputFolder)
                strcat(newPath, dir->d_name);
                strcat(newPath, "/");
                readFilesFromDirWithOutQuotationMarks(newPath, fout, endChar);
            } else if (dir->d_name[strlen(dir->d_name) - 1] == endChar) {
                fprintf(fout, "%s%s\n", path, dir->d_name);
                //printf("\"%s%s\" \n", path, dir->d_name);
            }
        }
        closedir(d);
    }
    free(newPath);
}

void readFilesNameFromDir(char * path, FILE * fout, char endChar) {
    DIR *d;
    struct dirent *dir;
    char * newPath;
    newPath = (char*) malloc(500 * sizeof (char));
    strcpy(newPath, path);
    d = opendir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_type == 4 && strcmp(".", dir->d_name) && strcmp("..", dir->d_name)) {


                //void readDirContent(char * path, char** listOfNeededHeaderFiles, int length, char * outputFolder)
                strcat(newPath, dir->d_name);
                strcat(newPath, "/");
                readFilesNameFromDir(newPath, fout, endChar);
            } else if (dir->d_name[strlen(dir->d_name) - 1] == endChar) {
                fprintf(fout, "%s\n", dir->d_name);
              //  printf("%s\n", dir->d_name);
            }
        }
        closedir(d);
    }
    free(newPath);
}

void addANewStringLNInTheEndFile(char* inString, char * outputFile) {

    FILE * fout = fopen(outputFile, "a");
    if (fout) {
        fprintf(fout, "%s", inString);
        fclose(fout);
    } else {
        printf("Error trying open file: %s", outputFile);
        exit(1);
    }
}

void addAStringsInTheEndFile(char* inString, char * outputFile) {

    FILE * fout = fopen(outputFile, "a");
    if (fout) {
        fprintf(fout, "%s ", inString);
        fclose(fout);
    } else {
        printf("Error trying open file: %s", outputFile);
        exit(1);
    }
}


void addAStringsInTheEndFileLN(char* inString, char * outputFile) {

    FILE * fout = fopen(outputFile, "a");
    if (fout) {
        fprintf(fout, "%s\n", inString);
        fclose(fout);
    } else {
        printf("Error trying open file: %s", outputFile);
        exit(1);
    }
}

void addAStringsInTheFile(char* inString, char * outputFile) {

    FILE * fout = fopen(outputFile, "w");
    if (fout) {
        fprintf(fout, "%s\n", inString);
        fclose(fout);
    } else {
        printf("Error trying open file: %s", outputFile);
        exit(1);
    }
}

void addAStringsInTheExitingFileLN(char* inString, char * outputFile) {

    FILE * fout = fopen(outputFile, "w+");
    if (fout) {
        fprintf(fout, "%s\n", inString);
        fclose(fout);
    } else {
        printf("Error trying open file: %s", outputFile);
        exit(1);
    }
}

void createFile(char * outputFile) {
    FILE *fout = fopen(outputFile, "w");
    fclose(fout);
}

void clearFile(const char *filename)
{
    FILE *output = fopen(filename, "w");
    fclose(output);
}
/* Open a file if it already exist, if not create it */
void openFileInAppendMode(char * outputFile) {
    FILE *fout = fopen(outputFile, "a");
    fclose(fout);
}

void createADirectory(char *outputFolder) {
    struct stat st = {0};
    if (stat(outputFolder, &st) == -1) {
        if (mkdir(outputFolder, 0777) && errno != EEXIST)
            printf("\tError while trying to create '%s'\n%m\n", outputFolder);
    }
}

/**
 * Function to check whether a directory exists or not.
 * It returns 1 if given path is directory and  exists
 * otherwise returns 0.
 */
int isDirectoryExists(const char *path)
{
    struct stat stats;

    stat(path, &stats);

    // Check for file existence
    if (S_ISDIR(stats.st_mode))
        return 1;

    return 0;

}

int isDirectoryEmpty(char *dirname) {
    int n = 0;
    struct dirent *d;
    DIR *dir = opendir(dirname);
    if (dir == NULL) //Not a directory or doesn't exist
        return 1;
    while ((d = readdir(dir)) != NULL) {
        if(++n > 2)
            break;
    }
    closedir(dir);
    if (n <= 2) //Directory Empty
        return 1;
    else
        return 0;
}

ListOfString * getListOfFilesFromDir(char * directory, char * temporaryFolder){
    ListOfString * listOfFile = NULL;

    FILE *fSourceFileName = fopen(temporaryFolder, "w");
    readFilesFromDir(directory, fSourceFileName, 'c');
    readFilesFromDir(directory, fSourceFileName, 'h');
    fclose(fSourceFileName);// LOS: write lista with sourcefiles.c full path existing in donor file

    listOfFile = readListOfStringFromFile(temporaryFolder);

    return listOfFile;

}


int diffIsStatic(char * sourceFileASTFromOrgan, char * sourceFileASTFromHost){
    printf("\t\t\tComparing ASTs...\n");
    fflush(stdout);
    ListOfString * FunctionDeclarationAsList = NULL;
    char *commandDIFF;
    commandDIFF = (char *) malloc(2000 * sizeof(char *));
    char * outputFile = (char *) malloc(2000 * sizeof(char *));
    sprintf(outputFile, "%sstatic.out",TempImplantationDirectory) ;
    sprintf(commandDIFF, "diff %s %s |grep \">\"|cut -c 3- > %s", sourceFileASTFromOrgan, sourceFileASTFromHost,outputFile);
    //sprintf(commandDIFF, "cmp -s %s %s", sourceFileASTFromOrgan, sourceFileASTFromHost);

    int status = system(commandDIFF);
    free(commandDIFF);
    if (status != 1 || status != 0) {
        fflush(stdout);
        FunctionDeclarationAsList = readListOfStringFromFile(outputFile);
        removeAFileFromADirectory(outputFile);
        if (FunctionDeclarationAsList != NULL && strstr(FunctionDeclarationAsList->el, "static")) {
            freeListOfStrings(&FunctionDeclarationAsList);
            return 0; // keeping host version
        }else {
            freeListOfStrings(&FunctionDeclarationAsList);
            return 1; // merge organ and host source code
        }
    }else{
        printf("ERROR Comparing %s x %s !\n", sourceFileASTFromOrgan, sourceFileASTFromHost);
        exit(1);
    }

}

int ASTIsEqual(char * sourceFileASTFromOrgan, char * sourceFileASTFromHost){
    printf("\t\t\tComparing ASTs...\n");
    fflush(stdout);
    char *commandDIFF;
    commandDIFF = (char *) malloc(2000 * sizeof(char *));

    //sprintf(commandDIFF, "diff -q %s %s", sourceFileASTFromOrgan, sourceFileASTFromHost);
    sprintf(commandDIFF, "cmp -s %s %s", sourceFileASTFromHost, sourceFileASTFromOrgan);

    int status = system(commandDIFF);
    free(commandDIFF);
    if (status == 0)
        return 0;//equals
    else
        return 1; // different
      /*  else{
            printf("ERROR Comparing %s x %s !\n", sourceFileASTFromOrgan, sourceFileASTFromHost);
            exit(1);
        }*/

}


int mergeElements( char * mergeResultFile, char * sourceFileASTFromOrgan, char * sourceFileASTFromHost, char * organIFDEFMarker){

    createFile(mergeResultFile);

    char *commandDIFF;
    commandDIFF = (char *) malloc(2000 * sizeof(char *));

    sprintf(commandDIFF, "diff -D %s %s %s > %s",organIFDEFMarker, sourceFileASTFromHost, sourceFileASTFromOrgan, mergeResultFile);

    int status = system(commandDIFF);
    /*if (status == 0) {
        printf("File merged\n");
        return status;
    }else{
        printf("ERROR Try to merge: %s >< %s\n", sourceFileASTFromOrgan, sourceFileASTFromHost);
        exit(1);
    }*/
}

void printListOfFunctionNameInADirectory(char * sourceDirectory, char * outputListOfSourceFilesFromDonor, char type ){
    FILE * listOfSourceFilesFromDonorFile = fopen(outputListOfSourceFilesFromDonor, "w");
    readFilesFromDir(sourceDirectory, listOfSourceFilesFromDonorFile, type);
    fclose(listOfSourceFilesFromDonorFile);
}