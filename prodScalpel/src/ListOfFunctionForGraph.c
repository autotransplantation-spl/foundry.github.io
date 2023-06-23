#include "ListOfFunctionForGraph.h"
#include "ListOfString.h"
#include "GenTrans.h"

#include <stdlib.h>
#include <stdio.h>
//#include <malloc.h>
#include <string.h>
#include "folderContent.h"

//LOS
#include <getopt.h>

#define CORE_FUNCTION_MARK "--coreFunction"
#define DONOR_CORE_FUNCTION_TARGET_FILE "--donorFileTarget"
#define HOST_CORE_FUNCTION_TARGET_PATH "--hostFileTarget"

void freeListOfFunctionForGraph(ListOfFunctionForGraph ** head) {
    ListOfFunctionForGraph * aux;

    while (* head) {
        fflush(stdout);
        aux = *head;
        * head = (*head) -> next;
        fflush(stdout);
        aux->sourceFile = NULL;
        free(aux->sourceFile);
        aux->functionName = NULL;
        free(aux->functionName);
        aux->hostTargetFile = NULL;
        free(aux->hostTargetFile);
        aux->next = NULL;
        aux = NULL;
        free(aux);
    }
    (* head) = NULL; //just in case...
}

void addNewFunctionForGraph(ListOfFunctionForGraph ** head, char * functionName, char * sourceFile) {
    ListOfFunctionForGraph * newEl = (ListOfFunctionForGraph *) malloc(1 * sizeof (ListOfFunctionForGraph));
    newEl->functionName = (char *) malloc((strlen(functionName) + 1) * sizeof (char *));
    newEl->sourceFile = (char *) malloc((strlen(sourceFile) + 1) * sizeof (char *));
    strcpy(newEl->functionName, functionName);
    strcpy(newEl->sourceFile, sourceFile);
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfFunctionForGraph * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

void addNewFunctionForGraphNode(ListOfFunctionForGraph ** head, char * functionName, char * sourceFile, char *nodeId, long int id) {
    ListOfFunctionForGraph * newEl = (ListOfFunctionForGraph *) malloc(1 * sizeof (ListOfFunctionForGraph));
    newEl->functionName =  NULL;
    newEl->sourceFile =  NULL;
    newEl->nodeId =  NULL;
    newEl->functionName = (char *) malloc((strlen(functionName) + 1) * sizeof (char *));
    newEl->sourceFile = (char *) malloc((strlen(sourceFile) + 1) * sizeof (char *));
    newEl->nodeId = (char *) malloc((strlen(nodeId) + 1) * sizeof (char *));
    newEl->hostTargetFile = NULL;
    newEl->startFunctionMarker = NULL;
    newEl->startFunctionMarkerSourceFile = NULL;
    strcpy(newEl->functionName, functionName);
    strcpy(newEl->sourceFile, sourceFile);
    strcpy(newEl->nodeId, nodeId);
    newEl->id = id;
    newEl->next = NULL;

    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfFunctionForGraph * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

void addNewFunctionGraphWithstartFunctionMarkerArguments(ListOfFunctionForGraph ** head, char * functionName, char * sourceFile, char * hostTargetFile, char * startFunctionMarker, char * startFunctionMarkerSourceFile) {
    ListOfFunctionForGraph * newEl = (ListOfFunctionForGraph *) malloc(1 * sizeof (ListOfFunctionForGraph));
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
        ListOfFunctionForGraph * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

void addNewFunctionHeaderSourceFileForGraph(ListOfFunctionForGraph ** head, char * functionName, char * sourceFile, char * headerFile) {
    ListOfFunctionForGraph * newEl = (ListOfFunctionForGraph *) malloc(1 * sizeof (ListOfFunctionForGraph));
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
        ListOfFunctionForGraph * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

void addNewFunctionDonorHostSourceFile(ListOfFunctionForGraph ** head, char * functionName, char * sourceFile, char * hostTargetFile) {
    ListOfFunctionForGraph * newEl = (ListOfFunctionForGraph *) malloc(1 * sizeof (ListOfFunctionForGraph));
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
        ListOfFunctionForGraph * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

int removeFunctionForGraph(ListOfFunctionForGraph ** head, char * functionName) {
    ListOfFunctionForGraph * p;
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
                ListOfFunctionForGraph * aux;
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

void printAListOfFunctionForGraph(ListOfFunctionForGraph * head, char * outputFile) {
    ListOfFunctionForGraph * p;
    p = head;
    FILE * fout = fopen(outputFile, "w");
    while (p) {
        fprintf(fout, "%s %s\n", p->functionName, p->sourceFile);
        p = p->next;
    }
    fclose(fout);
}

int searchForFunctionForGraph(ListOfFunctionForGraph * head, char * searchedFunctionName) {
    while (head) {
        if (!strcmp(head->functionName, searchedFunctionName)) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int countElementsInListOfFunctionsForGraph(ListOfFunctionForGraph * head) {
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    return count;
}


int searchFunctionInListOfFunctionsForGraph(ListOfFunctionForGraph * head, char * searchedFunctionName){
    while(head){
        if(!strcmp(head->functionName, searchedFunctionName)){
            return 1;
        }
        head = head->next;
    }
    return 0;
}

ListOfFunctionForGraph * readCoreFunctionFromFileForGraph() {
    ListOfString *currentCoreFunction = NULL;
    ListOfFunctionForGraph *listOfCoreFunction = NULL;
    if(!file_exists(listOfCoreFunctionsFile)) {
        ListOfString * ListOfCoreFunctions = readListOfStringFromFile(listOfCoreFunctionsFile);
        while (ListOfCoreFunctions) {
            ListOfString * currentCoreFunction = NULL;
            readStringAsWords(ListOfCoreFunctions->el, &currentCoreFunction);

            char *coreFunction = NULL;
            char *targetFile = NULL;
            char *hostTargetFile = NULL;
            if (!strcmp(currentCoreFunction->el, CORE_FUNCTION_MARK)) {
                currentCoreFunction = currentCoreFunction->next;
                coreFunction = currentCoreFunction->el;
                currentCoreFunction = currentCoreFunction->next;
                if (!strcmp(currentCoreFunction->el, DONOR_CORE_FUNCTION_TARGET_FILE)) {
                    currentCoreFunction = currentCoreFunction->next;
                    targetFile = currentCoreFunction->el;
                    currentCoreFunction = currentCoreFunction->next;
                }else{
                    printf("Donor target file does not defined in: %s\n", listOfCoreFunctionsFile);
                    exit(1);
                }
                if (!strcmp(currentCoreFunction->el, HOST_CORE_FUNCTION_TARGET_PATH)) {
                    currentCoreFunction = currentCoreFunction->next;
                    hostTargetFile = currentCoreFunction->el;
                }else{
                    printf("Host target file does not defined in: %s\n", listOfCoreFunctionsFile);
                    exit(1);
                }
                addNewFunctionDonorHostSourceFile(&listOfCoreFunction, coreFunction, targetFile, hostTargetFile);

            }
                ListOfCoreFunctions = ListOfCoreFunctions->next->next;
        }
    }else{
        printf("ERROR Input file not found: %s", listOfCoreFunctionsFile);
        exit(1);
    }
    return listOfCoreFunction;
}

#if 0
ListOfFunctionForGraph * readInputFileForGraph(char * inputFile) {

    ListOfString *currentCoreFunction = NULL;
    ListOfFunctionForGraph *listOfCoreFunction = NULL;
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

int countElementsInListOfFunctionSourceFileForGraph(ListOfFunctionForGraph * head) {
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    return count;
}


int searchNodeId(ListOfFunctionForGraph * head, char * searchedNode) {

    // adjlist_node_p adjListPtr = graph->adjListArr[0].head;
    ListOfFunctionForGraph * listFunctions = head;
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



ListOfFunctionForGraph *searchNodeReference(ListOfFunctionForGraph * head, char * searchedIdNode) {

    // adjlist_node_p adjListPtr = graph->adjListArr[0].head;
    ListOfFunctionForGraph * listFunctions = head;
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

ListOfFunctionForGraph * searchNodeIdFromFunctionName(ListOfFunctionForGraph * head, char * searchedName) {

    // adjlist_node_p adjListPtr = graph->adjListArr[0].head;
    ListOfFunctionForGraph * listFunctions = head;
    while(listFunctions) {
        char * nodeId = listFunctions->functionName;
        if (!strcmp(nodeId, searchedName)){
            //  printf("%d: %s\n", head->id,head->nodeId);
            return listFunctions;
        }
        listFunctions = listFunctions->next;
    }
    return NULL;
}

int searchIdFromFunctionName(ListOfFunctionForGraph * head, char * searchedName) {

    // adjlist_node_p adjListPtr = graph->adjListArr[0].head;
    ListOfFunctionForGraph * listFunctions = head;
    while(listFunctions) {
        char * nodeId = listFunctions->functionName;
        if (!strcmp(nodeId, searchedName)){
            //  printf("%d: %s\n", head->id,head->nodeId);
            return listFunctions->id;
        }
        listFunctions = listFunctions->next;
    }
    return NULL;
}


ListOfFunctionForGraph *searchNodeReferenceFromId(ListOfFunctionForGraph * head, long int searchedId) {

    ListOfFunctionForGraph * listFunctions = head;
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
}
/*
ListOfString * reverseListOfFunctions(ListOfFunctionForGraph * head) {
    ListOfFunctionForGraph * newHead = NULL;
    int n = countElementsInListOfFunctionSourceFileForGraph(head);
        int j = n - 1;
    char **function= NULL;
    char **file= NULL;
    int *idNode;
    int *id;
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
       // addNewFunctionSourceFile(&newHead, function1, file1);
        addNewFunctionForGraphNode(&newHead, function1, file1, char *nodeId, long int id) {

        }
    free(function);
    free(file);
    return newHead;
}
    */

ListOfString  * addDirectivesInFunction(char * sourceOutputFileForOrgan){
    ListOfString * functionWithDirective = NULL;

    char * formattedDirective = (char *) malloc(500 * sizeof (char));
    ListOfString * functionAsAList = readListOfStringFromFile(sourceOutputFileForOrgan);
    if(!strstr(functionAsAList->el, "#ifdef") ) { // There is any directive
        sprintf(formattedDirective, "#ifdef %s\n", conditionalDirectives);
        addNewString(&functionWithDirective, formattedDirective);
        addListOfStringToExistingOne(&functionWithDirective, functionAsAList);
        addNewString(&functionWithDirective, "#endif");
    } else{//There is directive
        sprintf(formattedDirective, " && %s\n", conditionalDirectives);
        functionAsAList->el = replace_str(functionAsAList->el, "\n", formattedDirective);
        addListOfStringToExistingOne(&functionWithDirective, functionAsAList);
    }

    return functionWithDirective;
}