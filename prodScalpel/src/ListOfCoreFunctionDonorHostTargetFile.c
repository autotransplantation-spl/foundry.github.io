#include "ListOfCoreFunctionDonorHostTargetFile.h"

#include <stdio.h>
//#include <malloc.h>
#include <string.h>

void freeListOfCoreFunctionDonoHostTargetFile(ListOfCoreFunctionDonorTargetFile ** head) {
    ListOfCoreFunctionDonorTargetFile * aux;

    while (* head) {
        aux = *head;
        * head = (*head) -> next;
        free(aux->functionName);
        free(aux->sourceFile);
        free(aux->hostTargetFile);
        aux->functionName = NULL;
        aux->sourceFile = NULL;
        aux->hostTargetFile = NULL;
        aux->next = NULL;
        free(aux);
        aux = NULL;
    }
    (* head) = NULL; //just in case...
}

void addNewCoreFunctionDonorHostTargetFile(ListOfCoreFunctionDonorHostTargetFile ** head, char * functionName, char * sourceFile, char * hostTargetFile) {
    ListOfCoreFunctionDonorTargetFile * newEl = (ListOfCoreFunctionDonorTargetFile *) malloc(1 * sizeof (ListOfCoreFunctionDonorTargetFile));
    newEl->functionName = (char *) malloc((strlen(functionName) + 1) * sizeof (char *));
    newEl->sourceFile = (char *) malloc((strlen(sourceFile) + 1) * sizeof (char *));
    newEl->hostTargetFile = (char *) malloc((strlen(sourceFile) + 1) * sizeof (char *));
    strcpy(newEl->functionName, functionName);
    strcpy(newEl->sourceFile, sourceFile);
    strcpy(newEl->hostTargetFile, hostTaregetFile);
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfCoreFunctionDonorTargetFile * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

int removeCoreFunctionDonorHostSourceFile(ListOfCoreFunctionDonorTargetFile ** head, char * functionName) {
    ListOfCoreFunctionDonorTargetFile * p;
    p = *head;
    int s = 0;
    if (!strcmp(p->functionName, functionName)) {
        *head = p->next;
        free(p->functionName);
        free(p->sourceFile);
        p->functionName = NULL;
        p->sourceFile = NULL;
        p->hostTargetFile = NULL;
        free(p);
        p = NULL;
        s = 1;
    } else {
        while (p->next && s == 0) {
            if (!strcmp(p->next->functionName, functionName)) {
                ListOfCoreFunctionDonorTargetFile * aux;
                aux = p->next;
                p -> next = p -> next -> next;
                free(aux->sourceFile);
                free(aux->functionName);
                aux->sourceFile = NULL;
                aux->hostTargetFile = NULL;
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

void printAListOfCoreFunctionDonorHostTargetFile(ListOfCoreFunctionDonorTargetFile * head, char * outputFile) {
    ListOfCoreFunctionDonorTargetFile * p;
    p = head;
    FILE * fout = fopen(outputFile, "w");
    while (p) {
        fprintf(fout, "%s %s\n", p->functionName, p->sourceFile, p->hostTargetFile);
        p = p->next;
    }
    fclose(fout);
}

int searchForFunction(ListOfCoreFunctionDonorTargetFile * head, char * searchedFunctionName) {
    while (head) {
        if (!strcmp(head->functionName, searchedFunctionName)) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int countElementsInListOfFunctionsSourceFile(ListOfCoreFunctionDonorTargetFile * head) {
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    return count;
}


int searchFunctionInListOfFunctionsSourceFile (ListOfCoreFunctionDonorTargetFile * head, char * searchedFunctionName){
    while(head){
        if(!strcmp(head->functionName, searchedFunctionName)){
            return 1;
        }
        head = head->next;
    }
    return 0;
}