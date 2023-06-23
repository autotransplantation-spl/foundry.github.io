#include "DeclarationWthHeaderDefinition.h"

#include <stdio.h>
#include <string.h>
//#include <malloc.h>
#include <stdlib.h>

void freeListOfDeclarationWithHeaderDefinition(DeclarationWithHeaderDefinition ** head) {
    DeclarationWithHeaderDefinition * aux;

    while (* head) {
        aux = *head;
        * head = (*head) -> next;
        free(aux->declaration);
        free(aux->headerDefinition);
        aux->declaration = NULL;
        aux->headerDefinition = NULL;
        aux->next = NULL;
        free(aux);
        aux = NULL;
    }
    (* head) = NULL; //just in case...
}

void addNewDeclarationWithHeaderDefinition(DeclarationWithHeaderDefinition ** head, char * declaration,
        char * headerDef) {
    DeclarationWithHeaderDefinition * newEl = (DeclarationWithHeaderDefinition *) malloc
            (1 * sizeof (DeclarationWithHeaderDefinition));
    newEl->declaration = (char *) malloc((strlen(declaration) + 1) * sizeof (char *));
    strcpy(newEl->declaration, declaration);
    
    newEl->headerDefinition = NULL;

    if (headerDef) {
        newEl->headerDefinition = (char *) malloc((strlen(headerDef) + 1) * sizeof (char *));
        strcpy(newEl->headerDefinition, headerDef);
    }
    
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        DeclarationWithHeaderDefinition * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

void addNewDeclarationWithHeaderDefinitionNoHeaderDef(DeclarationWithHeaderDefinition ** head, char * declaration) {
    DeclarationWithHeaderDefinition * newEl = (DeclarationWithHeaderDefinition *) malloc
            (1 * sizeof (DeclarationWithHeaderDefinition));
    newEl->declaration = (char *) malloc((strlen(declaration) + 1) * sizeof (char *));
    newEl->headerDefinition = NULL;
    strcpy(newEl->declaration, declaration);
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        DeclarationWithHeaderDefinition * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

DeclarationWithHeaderDefinition * copyListOfDeclarationWithHeaderDefinition(DeclarationWithHeaderDefinition * head) {
    DeclarationWithHeaderDefinition * newHead = NULL;
    DeclarationWithHeaderDefinition * pHead = NULL;
    pHead = head;
    if (head == NULL) {
        return NULL;
    }
    while (pHead) {
        addNewDeclarationWithHeaderDefinition(&newHead, pHead->declaration, pHead->headerDefinition);
        pHead = pHead->next;
    }
    return newHead;
}

int removeDeclarationWithHeaderDefinition(DeclarationWithHeaderDefinition ** head, char * declaration) {
    DeclarationWithHeaderDefinition * p;
    p = *head;
    int s = 0;
    if (!strcmp(p->declaration, declaration)) {
        *head = p->next;
        free(p->declaration);
        free(p->headerDefinition);
        free(p);
        p = NULL;
        s = 1;
    } else {
        while (p->next && s == 0) {
            if (!strcmp(p->next->declaration, declaration)) {
                DeclarationWithHeaderDefinition * aux;
                aux = p->next;
                p -> next = p -> next -> next;
                free(aux->declaration);
                free(aux->headerDefinition);
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

void printAListOfDeclarationWithHeaderDefinition(DeclarationWithHeaderDefinition * head, char * outputFile) {
    DeclarationWithHeaderDefinition * p;
    p = head;
    FILE * fout = fopen(outputFile, "w");
    while (p) {
        fprintf(fout, "%s %s", p->declaration, p->headerDefinition);
        p = p->next;
    }
    fclose(fout);
}

int searchDeclarationWithHeaderDefinitionInListOfDeclarationWithHeaderDefinition
(DeclarationWithHeaderDefinition * head, char * searchedDeclaration) {
    while (head) {
        if (!strcmp(head->declaration, searchedDeclaration)) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int countElementsInListOfDeclarationWithHeaderDefinition(DeclarationWithHeaderDefinition * head) {
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    return count;
}

void addListOfDeclarationWithHeaderDefinitionToExistingOneUniqueEl(DeclarationWithHeaderDefinition ** destination,
        DeclarationWithHeaderDefinition * source) {
    DeclarationWithHeaderDefinition * aux = source;

    while (aux) {
        if (!searchDeclarationWithHeaderDefinitionInListOfDeclarationWithHeaderDefinition((*destination),
                aux->declaration)) {
            addNewDeclarationWithHeaderDefinition(&(*destination), aux->declaration, aux->headerDefinition);
        }
        aux = aux->next;
    }
}