#include "Mapping.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"

void freeMapping(Mapping ** head) {
    Mapping * aux;
    while (* head) {
        aux = *head;
        * head = (*head) -> next;
        free(aux->destination);
        free(aux->source);
        aux->destination = NULL;
        aux->source = NULL;
        aux->next = NULL;
        free(aux);
        aux = NULL;
    }
    (* head) = NULL; //just in case...
}

void addNewMapping(Mapping ** head, char * source, char * destination) {
    Mapping * newEl = (Mapping *) malloc(1 * sizeof (Mapping));
    newEl->destination = (char *) malloc((strlen(destination) + 1) * sizeof (char *));
    newEl->source = (char *) malloc((strlen(source) + 1) * sizeof (char *));
    strcpy(newEl->destination, destination);
    strcpy(newEl->source, source);
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        Mapping * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

Mapping * copyListOfMapping(Mapping * head) {
    Mapping * newHead = NULL;
    Mapping * pHead = NULL;
    pHead = head;
    if (head == NULL) {
        return NULL;
    }
    //the last element is the bracket from function call
    while (pHead) {
        addNewMapping(&newHead, pHead->source, pHead->destination);
        pHead = pHead->next;
    }
    return newHead;
}

void printAListOfMappings(Mapping * head, char * outputFile) {
    FILE * fout = fopen(outputFile, "w");
    while (head) {
        fprintf(fout, "%s %s ", head->source, head->destination);
        head = head->next;
    }
    fclose(fout);
}

void printAListOfMappingsStringlit(Mapping * head, char * outputFile) {
    FILE * fout = fopen(outputFile, "w");
    while (head) {
       // fprintf(fout, "\"%s\" \"%s\" ", head->source, head->destination);

        if(strchr(head->destination, '\"')){
            char *formatedDestinationTypeString = (char *) malloc((strlen(head->destination) + 4) * sizeof(char));
            //sprintf(formatedDestinationTypeString,"\\%s \\\"", strtok(currentListOfMappings->destination, "\"");
            sprintf(formatedDestinationTypeString,"\\\"%s \\\"", readSubstring("\"",head->destination, "\""));
            fprintf(fout, "\"%s\" \"%s\" ", head->source,
                    formatedDestinationTypeString);
        }
        else
            fprintf(fout, "\"%s\" \"%s\" ", head->source, head->destination);

        head = head->next;
    }
    fclose(fout);
}