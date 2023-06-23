#include "ListOfInt.h"

#include "ListOfString.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void freeListOfInt(ListOfInt ** head) {
    ListOfInt * aux;

    while (* head) {
        aux = *head;
        * head = (*head) -> next;
        aux->value = 0;
        aux->next = NULL;
        free(aux);
        aux = NULL;
    }
    (* head) = NULL; //just in case...
}

void addNewInt(ListOfInt ** head, int value) {
    ListOfInt * newEl = (ListOfInt *) malloc(1 * sizeof (ListOfInt));
    newEl->value = value;
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfInt * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

ListOfInt * copyListOfInt(ListOfInt * head) {
    ListOfInt * newHead = NULL;
    ListOfInt * pHead = NULL;
    pHead = head;
    while (pHead) {
        addNewInt(&newHead, pHead->value);
        pHead = pHead->next;
    }
    return newHead;
}

int removeInt(ListOfInt ** head, int value) {
    ListOfInt * p;
    p = *head;
    int s = 0;
    if (p->value == value) {
        *head = p->next;
        free(p);
        p = NULL;
        s = 1;
    } else {
        while (p->next && s == 0) {
            if (p->value == value) {
                ListOfInt * aux;
                aux = p->next;
                p -> next = p -> next -> next;
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

void deleteElementInListOfIntAtPosition(ListOfInt ** head, int position) {
    if (position == 0) {
        ListOfInt * aux = *head;
        * head = (* head)->next;
        free(aux);
    } else {
        ListOfInt * auxListOfInt = *head;
        while (position && auxListOfInt) {

            if (position == 1) {
                ListOfInt * auxRemoveEl;
                auxRemoveEl = auxListOfInt->next;
                auxListOfInt -> next = auxListOfInt -> next -> next;
                free(auxRemoveEl);
                auxRemoveEl = NULL;
            }
            position--;
            auxListOfInt = auxListOfInt->next;
        }
    }
}

void printAListOfInt(ListOfInt * head, char * outputFile) {
    ListOfInt * p;
    p = head;
    FILE * fout = fopen(outputFile, "w");
    while (p) {
        fprintf(fout, "%d ", p->value);
        p = p->next;
    }
    fclose(fout);
}

int searchAnIntInListOfInt(ListOfInt * head, int searchedEl) {
    while (head) {
        if (head->value == searchedEl) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int countElementsInListOfInt(ListOfInt * head) {
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    return count;
}

int nthElementInListOfInt(ListOfInt * head, int n) {
    while (n > 0 && head) {
        head = head->next;
        n--;
    }
    if (n == 0) {

        return head->value;
    } else {
        return -1;
    }
}

int searchIntInListOfInts(ListOfInt * head, int searchedEl) {
    while (head) {
        if (head->value == searchedEl) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}