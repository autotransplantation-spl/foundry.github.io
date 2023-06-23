#include "ListOfFunctionSourceFile.h"
#include "ListOfString.h"
#include "GenTrans.h"
#include "Utils.h"
#include "folderContent.h"
#include <stdlib.h>
#include <stdio.h>
//#include <malloc.h>
#include <string.h>

//LOS
#include <getopt.h>


void freeListOfFunctionSourceFile(ListOfFunctionSourceFile ** head) {
    ListOfFunctionSourceFile * aux;

    while (* head) {
        aux = *head;
        * head = (*head) -> next;
        free(aux->functionName);
        free(aux->sourceFile);
        aux->functionName = NULL;
        aux->sourceFile = NULL;
        aux->next = NULL;
        free(aux);
        aux = NULL;
    }
    (* head) = NULL; //just in case...
}

void addNewFunctionSourceFile(ListOfFunctionSourceFile ** head, char * functionName, char * sourceFile) {
    ListOfFunctionSourceFile * newEl = (ListOfFunctionSourceFile *) malloc(1 * sizeof (ListOfFunctionSourceFile));
    newEl->functionName = (char *) malloc((strlen(functionName) + 1) * sizeof (char *));
    newEl->sourceFile = (char *) malloc((strlen(sourceFile) + 1) * sizeof (char *));
    strcpy(newEl->functionName, functionName);
    strcpy(newEl->sourceFile, sourceFile);
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfFunctionSourceFile * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

int removeFunctionSourceFile(ListOfFunctionSourceFile ** head, char * functionName) {
    ListOfFunctionSourceFile * p;
    p = *head;
    int s = 0;
    if (!strcmp(p->functionName, functionName)) {
        *head = p->next;
        free(p->functionName);
        free(p->sourceFile);
        p->functionName = NULL;
        p->sourceFile = NULL;
        free(p);
        p = NULL;
        s = 1;
    } else {
        while (p->next && s == 0) {
            fflush(stdout);
            if (!strcmp(p->next->functionName, functionName)) {
                ListOfFunctionSourceFile * aux;
                aux = p->next;
                p -> next = p -> next -> next;
                free(aux->sourceFile);
                free(aux->functionName);
                aux->sourceFile = NULL;
                aux->functionName = NULL;
                free(aux);
                aux = NULL;
                s = 1;
            } else {
                p = p->next;
            }

        }
    }
    return s;
}

void printAListOfFunctionSourceFile(ListOfFunctionSourceFile * head, char * outputFile) {
    ListOfFunctionSourceFile * p;
    p = head;
    FILE * fout = fopen(outputFile, "w");
    while (p) {
        fprintf(fout, "%s %s\n", p->functionName, p->sourceFile);
        p = p->next;
    }
    fclose(fout);
}

int searchForFunction(ListOfFunctionSourceFile * head, char * searchedFunctionName) {
    while (head) {
        if (!strcmp(head->functionName, searchedFunctionName)) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int countElementsInListOfFunctionsSourceFile(ListOfFunctionSourceFile * head) {
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    return count;
}

ListOfFunctionSourceFile * searchFunctionInListOfFunctionsSourceFileFromFunction (ListOfFunctionSourceFile * head, char * searchedFunctionName){
    ListOfFunctionSourceFile * FoundFunctionSourceFile = NULL;
    while(head){
        if(!strcmp(head->functionName, searchedFunctionName)){
            addNewFunctionSourceFile(&FoundFunctionSourceFile, head->functionName, head->sourceFile);
        }
        fflush(stdout);
        head = head->next;
    }
    return FoundFunctionSourceFile;
}

int searchFunctionInListOfFunctionsSourceFile (ListOfFunctionSourceFile * head, char * searchedFunctionName){
    while(head){
        if(!strcmp(head->functionName, searchedFunctionName)){
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int searchFunctionAndFileInListOfFunctionsSourceFile (ListOfFunctionSourceFile * head, char * searchedFunctionName, char * searchedFileName ){

    /*char * currentFct = NULL;
    currentFct = (char *) malloc(100 * sizeof (char));
    strcpy(currentFct, readSubstring("\"", searchedFunctionName, "\""));*/

    while(head){
        if(!strcmp(head->functionName, searchedFunctionName) && !strcmp(head->sourceFile, searchedFileName)){
            return 1;
        }
        head = head->next;
    }
    return 0;
}

ListOfFunctionSourceFile * readFunctionsFilesFromFile(char * inputFile) {

    FILE * fin = fopen(inputFile, "r");

    char * line;
    line = (char *) malloc(400 * sizeof (char));

    ListOfFunctionSourceFile * listOfFunctionSourceFile = NULL;

    while (fgets(line, 399, fin) != NULL) {
        strtok(line, "\n");
        char * currentFct = NULL;
        currentFct = (char *) malloc(1000 * sizeof (char));
        char * sourceFile = NULL;
        sourceFile = (char *) malloc(3000 * sizeof (char));

        sscanf(line, "%s %s", currentFct, sourceFile);

        if(strcmp(currentFct, "") && strcmp(sourceFile, ""))
        addNewFunctionSourceFile(&listOfFunctionSourceFile, currentFct, sourceFile);

        free(currentFct);
        free(sourceFile);
    }

    free(line);
    fclose(fin);
    return listOfFunctionSourceFile;
}

char * extractOnlyFileName(char * directory,  char * sourceFile){
    char * fileName = NULL;
    fileName = (char *) malloc(100 * sizeof (char));

    if(strstr(sourceFile,".h")){
        strcpy(fileName, readSubstring(directory, sourceFile, ".h"));
        strcat(fileName,".h");
    }
    else
    if(strstr(sourceFile,".c")){
        strcpy(fileName, readSubstring(directory, sourceFile, ".c"));
        strcat(fileName,".c");
    }
    return fileName;
}

void replaceSourceFilePahtByFileName(ListOfFunctionSourceFile ** head, char * directory){

    ListOfFunctionSourceFile * newHead = (*head);
    ListOfFunctionSourceFile * auxNewHead = newHead;

    while(auxNewHead) {
        if (strstr(auxNewHead->sourceFile, ".h")) {
            strcpy(newHead->sourceFile, readSubstring(directory, auxNewHead->sourceFile, ".h"));
            strcat(newHead->sourceFile, ".h");
        } else if (strstr(auxNewHead->sourceFile, ".c")) {
            strcpy(newHead->sourceFile, readSubstring(directory, auxNewHead->sourceFile, ".c"));
            strcat(newHead->sourceFile, ".c");
        }
        auxNewHead = auxNewHead->next;
        newHead = newHead->next;
    }

    freeListOfFunctionSourceFile(&newHead);
    freeListOfFunctionSourceFile(&auxNewHead);
}

void replaceListOfSourceFilePahtByFileName(ListOfString ** head, char * directory){

    ListOfString * newHead = (*head);
    ListOfString * auxNewHead = newHead;

    while(auxNewHead) {
        if (strstr(auxNewHead->el, ".h")) {
            strcpy(newHead->el, readSubstring(directory, auxNewHead->el, ".h"));
            strcat(newHead->el, ".h");
        } else if (strstr(auxNewHead->el, ".c")) {
            strcpy(newHead->el, readSubstring(directory, auxNewHead->el, ".c"));
            strcat(newHead->el, ".c");
        }
        auxNewHead = auxNewHead->next;
        newHead = newHead->next;
    }

    freeListOfStrings(&newHead);
    freeListOfStrings(&auxNewHead);
}

ListOfFunctionSourceFile * createListOfFunctionsFromAFile(char * TXLProgsPath, char * listOfSourceFiles, char * outputFile) {
    char * txlIfDefProg;
    txlIfDefProg = (char *) malloc(5000 * sizeof (char));
    sprintf(txlIfDefProg, "%sifdef.x", TXLProgsPath);
    ListOfFunctionSourceFile * listOfFile = NULL;

    char * commandTXL;
    commandTXL = (char *) malloc(5000 * sizeof (char));
    sprintf(commandTXL, "ulimit -s 65353 && %sExtractAllDefinedFunctionsName.x %s %s %s %s", TXLProgsPath, listOfSourceFiles, outputFile,
            txlIfDefProg, ConsoleNullOutput);
    int status = system(commandTXL);
    if (status != 0) {
        printf("ERROR! ExtractAllDefinedFunctionsName");
        fflush(stdout);
        exit(1);
    }else {
        listOfFile = readFunctionsFilesFromFile(outputFile);
        free(commandTXL);
        return listOfFile;
    }
}

void createListOfHostFunctions(char * TXLProgsPath, char * listOfSourceFiles, char * outputFile) {
    char * txlIfDefProg;
    txlIfDefProg = (char *) malloc(5000 * sizeof (char));
    sprintf(txlIfDefProg, "%sifdef.x", TXLProgsPath);


    char * commandTXL;
    commandTXL = (char *) malloc(5000 * sizeof (char));
    sprintf(commandTXL, "ulimit -s 65353 && %sExtractAllDefinedFunctionsName.x %s %s %s %s", TXLProgsPath, listOfSourceFiles, outputFile,
            txlIfDefProg, ConsoleStderrOutput);
    int status = system(commandTXL);
    if (status != 0) {
        printf("ERROR! ExtractAllDefinedFunctionsName");
        fflush(stdout);
        exit(1);
    }
    free(commandTXL);
}

ListOfFunctionSourceFile * extractListOfFunctionsFilesFromDir(char * directory, char * temporaryFolder, char * outputAllDefinedFunctionsInHost){
    ListOfFunctionSourceFile * listOfFile = NULL;

    FILE *fSourceFileName = fopen(temporaryFolder, "w");
    readFilesFromDir(directory, fSourceFileName, 'c');
    readFilesFromDir(directory, fSourceFileName, 'h');
    fclose(fSourceFileName);// LOS: write lista with sourcefiles.c full path existing in donor file

    createListOfHostFunctions(TXLToolsPath, temporaryFolder, outputAllDefinedFunctionsInHost);

    listOfFile = readFunctionsFilesFromFile(outputAllDefinedFunctionsInHost);

    return listOfFile;

}

SourceFileElementsList * searchSourceFile(SourceFileElementsList * head, char * sourceFile) {
    SourceFileElementsList * p;
    p = head;
    int s = 0;
    while (p && !s) {
        if (!strcmp(p->sourceFile, sourceFile)) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void addNewSourceFile(SourceFileElementsList ** head, char * sourceFile) {
    SourceFileElementsList * newEl = (SourceFileElementsList *) malloc(1 * sizeof (SourceFileElementsList));
    newEl->sourceFile = (char *) malloc(1000 * sizeof (char));
    strcpy(newEl->sourceFile, sourceFile);
    newEl->functions = NULL;
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        SourceFileElementsList * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}


int addNewFunctionInExistingSourceFile(SourceFileElementsList ** head, char * sourceFile, char * function) {
    SourceFileElementsList * p;
    p = *head;
    int s = 0, d = 0;
    while (p -> next && s == 0) {
        if (!strcmp(sourceFile, p->sourceFile)) {
            s = 1;
        } else {
            p = p->next;
        }
    }
    if (!strcmp(p->sourceFile, sourceFile)) {
        s = 1;
    }
    ListOfString * currentDependencies = p->functions;
    while(currentDependencies && d == 0){

        if(!strcmp(currentDependencies->el, function))
            d = 1;
        // if(!strncmp(declaration ,p->ListOfDependencies->el,strlen(declaration)))
        //if(strstr(p->ListOfDependencies->el, declaration))

        currentDependencies = currentDependencies->next;
    }
    if (s == 0 || d == 1) {
        return 0;
    } else {
        addNewString(&(p->functions), function);
        return 1;
    }
}

void addFunctionListToAnExistingOneFile(SourceFileElementsList ** destination, ListOfFunctionSourceFile * source) {
    ListOfFunctionSourceFile * auxSource = source;
    SourceFileElementsList * auxDestination = NULL;
    while (auxSource) {
        auxDestination = searchSourceFile(*destination, auxSource->sourceFile);
        if(auxDestination == NULL){
            addNewSourceFile(&(*destination), auxSource->sourceFile);
            addNewFunctionInExistingSourceFile(&(*destination), auxSource->sourceFile, auxSource->functionName);
        } else {
            addNewFunctionInExistingSourceFile(&(*destination), auxSource->sourceFile, auxSource->functionName);
        }
        auxSource = auxSource->next;
    }

    fflush(stdout);
}

ListOfString * readListOfFunctionInASourceFile(SourceFileElementsList * head, char * sourceFile) {
    SourceFileElementsList * p;
    p = head;
    int s = 0;
    while (p && !s) {
        if (!strcmp(p->sourceFile, sourceFile)) {
            return p->functions;
        }
        p = p->next;
    }
    return NULL;
}

int countElementsInListOfFunctions(ListOfFunctionSourceFile * head) {
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    return count;
}

ListOfString * reverseListOfFunctions(ListOfFunctionSourceFile * head) {
    ListOfFunctionSourceFile * newHead = NULL;
    int n = countElementsInListOfFunctions(head);
    int j = n - 1;
    char **function= NULL;
    char **file= NULL;
    function = (char**) malloc(n * sizeof(char*));
    file = (char**) malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        function[i] = (char*) malloc(100 * sizeof(char));
        file[i] = (char*) malloc(100 * sizeof(char));
    }
    for (int i = 0; i < n; i++) {
        strcpy(function[i], head->functionName);
        strcpy(file[i], head->sourceFile);
        head = head->next;
    }
    char* temp;
    char* tempFile;
    for (int i = 0; i < j; i++) {
        temp = function[i];
        function[i] = function[j];
        function[j] = temp;

        tempFile = file[i];
        file[i] = file[j];
        file[j] = tempFile;
        j--;
    }

    for (int i = 0; i < n; i++) {
        char* function1 = (char *) malloc((strlen(function[i]) + 1) * sizeof (char *));
        strcpy(function1, function[i]);
        char* file1 = (char *) malloc((strlen(file[i]) + 1) * sizeof (char *));
        strcpy(file1, file[i]);
        addNewFunctionSourceFile(&newHead, function1, file1);
    }
    free(function);
    free(file);
    return newHead;
}

/*
void freeListOfFunctionSourceFile(ListOfFunctionSourceFile ** head) {
    ListOfFunctionSourceFile * aux;

    while (* head) {
        aux = *head;
        * head = (*head) -> next;
        free(aux->functionName);
        free(aux->sourceFile);
        aux->functionName = NULL;
        aux->sourceFile = NULL;
        aux->hostTargetFile = NULL;
        aux->next = NULL;
        free(aux);
        aux = NULL;
    }
    (* head) = NULL; //just in case...
}

void addNewFunctionSourceFile(ListOfFunctionSourceFile ** head, char * functionName, char * sourceFile) {
    ListOfFunctionSourceFile * newEl = (ListOfFunctionSourceFile *) malloc(1 * sizeof (ListOfFunctionSourceFile));
    newEl->functionName = (char *) malloc((strlen(functionName) + 1) * sizeof (char *));
    newEl->sourceFile = (char *) malloc((strlen(sourceFile) + 1) * sizeof (char *));
    strcpy(newEl->functionName, functionName);
    strcpy(newEl->sourceFile, sourceFile);
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfFunctionSourceFile * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

void addNewFunctionSourceFileNode(ListOfFunctionSourceFile ** head, char * functionName, char * sourceFile, char *nodeId, long int id) {
    ListOfFunctionSourceFile * newEl = (ListOfFunctionSourceFile *) malloc(1 * sizeof (ListOfFunctionSourceFile));
    newEl->functionName = (char *) malloc((strlen(functionName) + 1) * sizeof (char *));
    newEl->sourceFile = (char *) malloc((strlen(sourceFile) + 1) * sizeof (char *));
    newEl->nodeId = (char *) malloc((strlen(nodeId) + 1) * sizeof (char *));
    strcpy(newEl->functionName, functionName);
    strcpy(newEl->sourceFile, sourceFile);
    strcpy(newEl->nodeId, nodeId);
    newEl->id = id;
    newEl->next = NULL;

    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfFunctionSourceFile * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

void addNewFunctionSourceFileWithstartFunctionMarkerArguments(ListOfFunctionSourceFile ** head, char * functionName, char * sourceFile, char * hostTargetFile, char * startFunctionMarker, char * startFunctionMarkerSourceFile) {
    ListOfFunctionSourceFile * newEl = (ListOfFunctionSourceFile *) malloc(1 * sizeof (ListOfFunctionSourceFile));
    newEl->functionName = (char *) malloc((strlen(functionName) + 1) * sizeof (char *));
    newEl->sourceFile = (char *) malloc((strlen(sourceFile) + 1) * sizeof (char *));
    newEl->hostTargetFile = (char *) malloc((strlen(hostTargetFile) + 1) * sizeof (char *));
    newEl->startFunctionMarker = (char *) malloc((strlen(startFunctionMarker) + 1) * sizeof (char *));
    newEl->startFunctionMarkerSourceFile = (char *) malloc((strlen(startFunctionMarkerSourceFile) + 1) * sizeof (char *));
    strcpy(newEl->functionName, functionName);
    strcpy(newEl->sourceFile, sourceFile);
    strcpy(newEl->hostTargetFile, hostTargetFile);
    strcpy(newEl->startFunctionMarker, startFunctionMarker);
    strcpy(newEl->startFunctionMarkerSourceFile, startFunctionMarkerSourceFile);
    newEl->next = NULL;

    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfFunctionSourceFile * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

void addNewFunctionHeaderSourceFile(ListOfFunctionSourceFile ** head, char * functionName, char * sourceFile, char * headerFile) {
    ListOfFunctionSourceFile * newEl = (ListOfFunctionSourceFile *) malloc(1 * sizeof (ListOfFunctionSourceFile));
    newEl->functionName = (char *) malloc((strlen(functionName) + 1) * sizeof (char *));
    newEl->sourceFile = (char *) malloc((strlen(sourceFile) + 1) * sizeof (char *));
 //   newEl->headerFile = (char *) malloc((strlen(sourceFile) + 1) * sizeof (char *));
    strcpy(newEl->functionName, functionName);
    strcpy(newEl->sourceFile, sourceFile);
//    strcpy(newEl->headerFile, headerFile);

    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfFunctionSourceFile * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

void addNewFunctionDonorHostSourceFile(ListOfFunctionSourceFile ** head, char * functionName, char * sourceFile, char * hostTargetFile) {
    ListOfFunctionSourceFile * newEl = (ListOfFunctionSourceFile *) malloc(1 * sizeof (ListOfFunctionSourceFile));
    newEl->functionName = (char *) malloc((strlen(functionName) + 1) * sizeof (char *));
    newEl->sourceFile = (char *) malloc((strlen(sourceFile) + 1) * sizeof (char *));
    newEl->hostTargetFile = (char *) malloc((strlen(sourceFile) + 1) * sizeof (char *));
    strcpy(newEl->functionName, functionName);
    strcpy(newEl->sourceFile, sourceFile);
    strcpy(newEl->hostTargetFile, hostTargetFile);
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfFunctionSourceFile * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

int removeFunctionSourceFile(ListOfFunctionSourceFile ** head, char * functionName) {
    ListOfFunctionSourceFile * p;
    p = *head;
    int s = 0;
    if (!strcmp(p->functionName, functionName)) {
        *head = p->next;
        free(p->functionName);
        free(p->sourceFile);
       // free(p->hostTargetFile);
        p->functionName = NULL;
        p->sourceFile = NULL;
        p->hostTargetFile = NULL;
        free(p);
        p = NULL;
        s = 1;
    } else {
        while (p->next && s == 0) {
            if (!strcmp(p->next->functionName, functionName)) {
                ListOfFunctionSourceFile * aux;
                aux = p->next;
                p -> next = p -> next -> next;
                fflush(stdout);
                free(aux->sourceFile);
                free(aux->functionName);
                //free(p->hostTargetFile);
                aux->sourceFile = NULL;
                aux->functionName = NULL;
                free(aux);
                aux = NULL;
                s = 1;
            } else {
                p = p->next;
            }

        }
    }
    return s;
}

void printAListOfFunctionSourceFile(ListOfFunctionSourceFile * head, char * outputFile) {
    ListOfFunctionSourceFile * p;
    p = head;
    FILE * fout = fopen(outputFile, "w");
    while (p) {
        fprintf(fout, "%s %s\n", p->functionName, p->sourceFile);
        p = p->next;
    }
    fclose(fout);
}

int searchForFunction(ListOfFunctionSourceFile * head, char * searchedFunctionName) {
    while (head) {
        if (!strcmp(head->functionName, searchedFunctionName)) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int countElementsInListOfFunctionsSourceFile(ListOfFunctionSourceFile * head) {
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    return count;
}


int searchFunctionInListOfFunctionsSourceFile (ListOfFunctionSourceFile * head, char * searchedFunctionName){
    while(head){
        if(!strcmp(head->functionName, searchedFunctionName)){
            return 1;
        }
        head = head->next;
    }
    return 0;
}

ListOfFunctionSourceFile * readCoreFunctionFromFile() {

    ListOfString *currentCoreFunction = NULL;
    ListOfFunctionSourceFile *listOfCoreFunction = NULL;

    if(listOfCoreFunctionsFile) {
        currentCoreFunction = readListOfStringFromFileAsWords(listOfCoreFunctionsFile);
        while (currentCoreFunction->next != NULL) {
            if (!strcmp(currentCoreFunction->el, "--coreFunction:")) {
                currentCoreFunction = currentCoreFunction->next;
                char *coreFunction = currentCoreFunction->el;
                currentCoreFunction = currentCoreFunction->next;
                char *targetFile = currentCoreFunction->el;
                currentCoreFunction = currentCoreFunction->next;
                char *hostTargetFile = currentCoreFunction->el;
                addNewFunctionDonorHostSourceFile(&listOfCoreFunction, coreFunction, targetFile, hostTargetFile);
            } else {
                currentCoreFunction = currentCoreFunction->next;
            }
        }
    }else{
        printf("ERROR Input file not found! ");
    }
    return listOfCoreFunction;
}

#if 0
ListOfFunctionSourceFile * readInputFile(char * inputFile) {

    ListOfString *currentCoreFunction = NULL;
    ListOfFunctionSourceFile *listOfCoreFunction = NULL;
    char *currentWord = NULL;
    char *coreFunction = NULL;
    char *donorTarget = NULL;
    char *hostTarget = NULL;
    char *startFunctionMarker = NULL;
    char *startFunctionMarkerSourceFile = NULL;
    startFunctionMarkerSourceFile = (char *) malloc(500 * sizeof (char));
    sprintf(startFunctionMarkerSourceFile, "%s%s", donorSourceFileFolder, "main.c");

    currentCoreFunction = readListOfStringFromFileAsWords(inputFile);
    if(currentCoreFunction) {
        while (currentCoreFunction != NULL) {
            if (!strcmp(currentCoreFunction->el, "toTransplant:") &&
                !strcmp(currentCoreFunction->next->el, "yes")) {
                for(int i = 0; i < 7; i++) {
                    currentWord = currentCoreFunction->el;
                    if (strstr(currentWord, "--")){
                        // switch (keyfromstring(currentWord)) {
                        if (!strcmp(currentWord, "--core_function:")) {
                            currentCoreFunction = currentCoreFunction->next;
                            if(strcmp(currentCoreFunction->el,"--"))
                                coreFunction = currentCoreFunction->el;
                            else {
                                printf("ERROR No core function!\n");
                                exit(1);
                            }
                        } else if (!strcmp(currentWord, "--donor_target:")) {
                            currentCoreFunction = currentCoreFunction->next;
                            if(strcmp(currentCoreFunction->el,"--"))
                                donorTarget = currentCoreFunction->el;
                            else{
                                printf("ERROR No donor target path!\n");
                                exit(1);
                            }
                        } else if (!strcmp(currentWord, "--host_target:")) {
                            currentCoreFunction = currentCoreFunction->next;
                            if(strcmp(currentCoreFunction->el,"--"))
                                hostTarget = currentCoreFunction->el;
                            else{
                                printf("ERROR No host target path\n");
                                exit(1);
                            }
                        } else if (!strcmp(currentWord, "--start_function_marker:")) {
                            currentCoreFunction = currentCoreFunction->next;
                            if(!strcmp(currentCoreFunction->el,""))
                                startFunctionMarker = currentCoreFunction->el;
                            else
                                startFunctionMarker = "main";
                        } else if (!strcmp(currentWord, "--start_function_markerSourceFile:")) {
                            currentCoreFunction = currentCoreFunction->next;
                            if(strcmp(currentCoreFunction->el,""))
                                startFunctionMarkerSourceFile = currentCoreFunction->el;
                        } else {
                            printf("ERROR Invalid input file");
                            exit(1);
                        }

                    }
                    currentCoreFunction = currentCoreFunction->next;
                }
                addNewFunctionSourceFileWithstartFunctionMarkerArguments(&listOfCoreFunction, coreFunction,
                                                                         donorTarget, hostTarget,
                                                                         startFunctionMarker,
                                                                         startFunctionMarkerSourceFile);
            }else
                currentCoreFunction = currentCoreFunction->next;
        }
    }else
        printf("ERROR Input file not found! ");

    return listOfCoreFunction;
}
#endif

int countElementsInListOfFunctionSourceFile(ListOfFunctionSourceFile * head) {
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    return count;
}


int searchNodeId(ListOfFunctionSourceFile * head, char * searchedNode) {

    // adjlist_node_p adjListPtr = graph->adjListArr[0].head;
    ListOfFunctionSourceFile * listFunctions = head;
    while(listFunctions) {
        char * nodeId = listFunctions->nodeId;
        if (!strcmp(nodeId, searchedNode)){
           // printf("%d: %s\n", listFunctions->id,listFunctions->nodeId);
            return listFunctions->id;
        }
        listFunctions = listFunctions->next;
    }
    return NULL;
}



ListOfFunctionSourceFile *searchNodeReference(ListOfFunctionSourceFile * head, char * searchedIdNode) {

    // adjlist_node_p adjListPtr = graph->adjListArr[0].head;
    ListOfFunctionSourceFile * listFunctions = head;
    while(listFunctions) {
        char * nodeId = listFunctions->nodeId;
        if (!strcmp(nodeId, searchedIdNode)){
          //  printf("%d: %s\n", head->id,head->nodeId);
            return listFunctions;
        }
        listFunctions = listFunctions->next;
    }
    return NULL;
}

ListOfFunctionSourceFile *searchNodeReferenceFromId(ListOfFunctionSourceFile * head, int searchedId) {

    ListOfFunctionSourceFile * listFunctions = head;
    while(listFunctions) {
        //int id = listFunctions->id;
        //printf(">> %d -%d",searchedId, listFunctions->id);
        if (searchedId == listFunctions->id){
            return listFunctions;
        }
        listFunctions = listFunctions->next;
        fflush(stdout);
    }
    return NULL;
}*/