#include "SkeletonMapping.h"
#include "Mapping.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void freeSkeletonMapping(SkeletonMapping ** head) {
    SkeletonMapping * aux;

    while (* head) {
        aux = *head;
        * head = (*head) -> next;
        free(aux->functionName);
        aux->functionName = NULL;
        freeMapping(&(aux->mappings));
        aux->mappings = NULL;
        aux->next = NULL;
        free(aux);
        aux = NULL;
    }
    (* head) = NULL; //just in case...
}

SkeletonMapping * returnMappingsForFunction(SkeletonMapping * head, char * name) {
    SkeletonMapping * p;
    p = head;
    int signal = 0;
    while (p && !signal) {
        if (!strcmp(p->functionName, name)) {
            signal = 1;
        } else {
            p = p-> next;
        }
    }
    if (signal) {
        return p;
    } else {
        return NULL;
    }
}

SkeletonMapping * addNewSkeletonMapping(SkeletonMapping ** head, char * name) {
    SkeletonMapping * newEl = (SkeletonMapping *) malloc(1 * sizeof (SkeletonMapping));
    newEl->functionName = (char *) malloc((strlen(name) + 1) * sizeof (char));
    strcpy(newEl->functionName, name);
    newEl->mappings = NULL;
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        SkeletonMapping * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
    return newEl;
}