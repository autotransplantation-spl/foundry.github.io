#include "MappingCandidate.h"
#include "ListOfString.h"
#include "SymbolTable.h"
#include "Mapping.h"
#include "GenTrans.h"

#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
#include <string.h>

void freeMappingCandidateList(MappingCandidate ** head) {
    MappingCandidate * aux;
    while (* head) {
        aux = *head;
        * head = (*head) -> next;
        freeListOfStrings(&(aux->possibleMappings));
        aux->possibleMappings = NULL;
        free(aux->currentMapping);
        free(aux->id);
        free(aux->type);
        aux->currentMapping = NULL;
        aux->id = NULL;
        aux->type = NULL;
        aux->next = NULL;
        free(aux);
        aux = NULL;
    }
    (* head) = NULL; //just in case...
}

int removeMappingCandidate(MappingCandidate ** head, char * id, char * type) {
    MappingCandidate * p;
    p = *head;
    int s = 0;
    if ((!strcmp(p->id, id)) && (!strcmp(p->type, type))) {
        *head = p->next;
        free(p->id);
        free(p->type);
        freeListOfStrings(&(p->possibleMappings));
        free(p->currentMapping);
        free(p);
        p = NULL;
        s = 1;
    } else {
        while (p->next && s == 0) {
            if ((!strcmp(p->next->id, id)) && (!strcmp(p->next->type, type))) {
                MappingCandidate * aux;
                aux = p->next;
                p -> next = p -> next -> next;
                free(aux->id);
                free(aux->type);
                freeListOfStrings(&aux->possibleMappings);
                free(aux->currentMapping);
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

MappingCandidate * searchMappingCandidateForID(MappingCandidate * head, char * id) {
    MappingCandidate * p;
    p = head;
    int s = 0;
    while (p && !s) {
        if (!strcmp(p->id, id)) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void addNewMappingCandidateElement(MappingCandidate ** head, char * id, char * type) {
    MappingCandidate * newEl = (MappingCandidate *) malloc(1 * sizeof (MappingCandidate));
    newEl->id = (char *) malloc((strlen(id) + 1) * sizeof (char));
    newEl->type = (char *) malloc((strlen(type) + 1) * sizeof (char));
    strcpy(newEl->id, id);
    strcpy(newEl->type, type);
    newEl->possibleMappings = NULL;
    newEl->currentMapping = NULL;
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        MappingCandidate * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

void addNewMappingCandidateElementCompleteDeclaration(MappingCandidate ** head, char * id, char * type,
        char * currentMapping, ListOfString * possibleMappings) {
    MappingCandidate * newEl = (MappingCandidate *) malloc(1 * sizeof (MappingCandidate));
    newEl->id = (char *) malloc((strlen(id) + 1) * sizeof (char));
    newEl->type = (char *) malloc((strlen(type) + 1) * sizeof (char));
    strcpy(newEl->id, id);
    strcpy(newEl->type, type);
    newEl->possibleMappings = NULL;
    newEl->currentMapping = NULL;
    if (currentMapping) {
        newEl->currentMapping = (char *) malloc((strlen(currentMapping) + 1) * sizeof (char));
        strcpy(newEl->currentMapping, currentMapping);
    }
    if (possibleMappings) {
        newEl->possibleMappings = copyCompleteListOfString(possibleMappings);
    }
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        MappingCandidate * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

void addNewMappingCandidateFromMappingCandidateElement(MappingCandidate ** head, MappingCandidate * candidateToBeAdded) {
    MappingCandidate * newEl = (MappingCandidate *) malloc(1 * sizeof (MappingCandidate));
    newEl->id = (char *) malloc((strlen(candidateToBeAdded->id) + 1) * sizeof (char));
    newEl->type = (char *) malloc((strlen(candidateToBeAdded->type) + 1) * sizeof (char));
    strcpy(newEl->id, candidateToBeAdded->id);
    strcpy(newEl->type, candidateToBeAdded->type);
    newEl->possibleMappings = NULL;
    newEl->currentMapping = NULL;
    if (candidateToBeAdded->currentMapping) {
        newEl->currentMapping = (char *) malloc((strlen(candidateToBeAdded->currentMapping) + 1) * sizeof (char));
        strcpy(newEl->currentMapping, candidateToBeAdded->currentMapping);
    }
    if (candidateToBeAdded->possibleMappings) {
        newEl->possibleMappings = copyCompleteListOfString(candidateToBeAdded->possibleMappings);
    }
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        MappingCandidate * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

int addNewPossibleMapping(MappingCandidate ** head, char * id, char * possibleMapping) {
    MappingCandidate * p;
    p = *head;
    int s = 0;
    if (!p) {
        return 0;
    }
    while (p -> next && s == 0) {
        if (!strcmp(id, p->id)) {
            s = 1;
        } else {
            p = p->next;
        }
    }
    if (!strcmp(p->id, id)) {
        s = 1;
    }
    if (s == 0) {
        return 0;
    } else {
        addNewString(&(p->possibleMappings), possibleMapping);
        return 1;
    }
}

int addNewCurrentMapping(MappingCandidate ** head, char * id, char * currentMapping) {
    MappingCandidate * p;
    p = *head;
    int s = 0;
    if (!p) {
        return 0;
    }
    while (p -> next && s == 0) {
        if (!strcmp(id, p->id)) {
            s = 1;
        } else {
            p = p->next;
        }
    }
    if (!strcmp(p->id, id)) {
        s = 1;
    }
    if (s == 0) {
        return 0;
    } else {
        if (currentMapping) {
            free(p->currentMapping);

            p->currentMapping = (char *) malloc((strlen(currentMapping) + 1) * sizeof (char));
            strcpy(p->currentMapping, currentMapping);
            return 1;
        }
    }
    return 0;
}

MappingCandidate * addNewMappingCandidatesFromSymbolTable(SymbolTable * headSymbolTable) {
    SymbolTable * aux = headSymbolTable;
    MappingCandidate * newMappingCandidateList = NULL;
    while (aux) {
        IdOfVariable * auxIDs = aux->ListOfIdentifiers;
        while (auxIDs) {
            addNewMappingCandidateElement(&newMappingCandidateList, auxIDs->ID, aux->TypeOfVar);
            auxIDs = auxIDs->next;
        }
        aux = aux->next;
    }
    return newMappingCandidateList;
}

void addPossibleMappingsForAllCandidatesWhereTypeMatch(MappingCandidate ** head,
        char * type, char * id) {
    MappingCandidate * aux = *head;

    while (aux) {

        char * copyAuxType;
        copyAuxType = (char *) malloc(500 * sizeof (char));
        strcpy(copyAuxType, aux->type);

        if (!strcmp(copyAuxType, type)) {
            addNewString(&(aux->possibleMappings), id);
        } else {
            //aux->type, type

            //replace all [] with *, since they are compatible; what if: [333]?
#if 0
            char * copyReplacementType = (char *) malloc(500 * sizeof (int));
            char * copyReplacementAuxType = (char *) malloc(500 * sizeof (int));

            strcpy(copyReplacementType, type);
            strcpy(copyReplacementAuxType, aux->type);

            copyReplacementType = removeArraySizeInString(copyReplacementType);
            copyReplacementAuxType = removeArraySizeInString(copyReplacementAuxType);

            char * auxReplace;

            while ((auxReplace = replace_str(copyReplacementType, "[]", "*")) && (auxReplace)) {
                strcpy(copyReplacementType, auxReplace);
            }
            while ((auxReplace = replace_str(copyReplacementAuxType, "[]", "*")) && (auxReplace)) {
                strcpy(copyReplacementAuxType, auxReplace);
            }

            if (!strcmp(copyReplacementType, copyReplacementAuxType)) {
                addNewString(&(aux->possibleMappings), id);
            }
#endif
        }
        /*else {

            strcat(copyAuxType, "*");
            if (!strcmp(copyAuxType, type)) {
                char * referencedID;
                referencedID = (char*) malloc(500 * sizeof (char));
                sprintf(referencedID, "*%s", id);
                addNewString(&(aux->possibleMappings), referencedID);
            }
            else {
                //aux->type, type

                //replace all [] with *, since they are compatible; what if: [333]?

                char * copyReplacementType = (char *) malloc(500 * sizeof (int));
                char * copyReplacementAuxType = (char *) malloc(500 * sizeof (int));

                strcpy(copyReplacementType, type);
                strcpy(copyReplacementAuxType, aux->type);

                char * auxReplace;

                while ((auxReplace = replace_str(copyReplacementType, "[]", "*")) && (auxReplace)) {
                    strcpy(copyReplacementType, auxReplace);
                }
                while ((auxReplace = replace_str(copyReplacementAuxType, "[]", "*")) && (auxReplace)) {
                    strcpy(copyReplacementAuxType, auxReplace);
                }

                if (!strcmp(copyReplacementType, copyReplacementAuxType)) {
                    addNewString(&(aux->possibleMappings), id);
                }
            }

        }
         */
        aux = aux->next;
    }
}

void addNewPossibleMappingsFromSymbolTable(MappingCandidate ** head, SymbolTable * headSymbolTable) {
    SymbolTable * aux = headSymbolTable;
    MappingCandidate * auxMappingCand;
    auxMappingCand = *head;
    while (aux) {
        IdOfVariable * auxIDs = aux->ListOfIdentifiers;
        while (auxIDs) {
            addPossibleMappingsForAllCandidatesWhereTypeMatch(&auxMappingCand, aux->TypeOfVar, auxIDs->ID);
            auxIDs = auxIDs->next;
        }
        aux = aux->next;
    }
}

void addNewPossibleMappingsFromMappings(MappingCandidate ** head, Mapping * headMapping) {
    MappingCandidate * auxMappingCand = *head;
    Mapping * auxMapping = headMapping;
    while (auxMapping) {
        addNewPossibleMapping(&auxMappingCand, auxMapping->source, auxMapping->destination);
        auxMapping = auxMapping->next;
    }
}

void addNewPossibleMappingsFromListOfString(MappingCandidate ** head, ListOfString * possibleMappingsList) {
    (*head)->possibleMappings = copyCompleteListOfString(possibleMappingsList);
}

void addNewCurrentMappingFromMappings(MappingCandidate ** head, Mapping * headMapping) {
    MappingCandidate * auxMappingCand = *head;
    Mapping * auxMapping = headMapping;
    while (auxMapping) {
        addNewCurrentMapping(&auxMappingCand, auxMapping->source, auxMapping->destination);
        auxMapping = auxMapping->next;
    }
}

MappingCandidate * createMappingCandidateFromSymbolTablesAndMappings(SymbolTable * GraftSymbolTable,
        SymbolTable * HostSymbolTable, Mapping * CurrentMappings) {
    printf("[AUTOSCALPEL] Create mapping candidate from symbol tables and mappins\n");
    MappingCandidate * newCandidate = NULL;
    newCandidate = addNewMappingCandidatesFromSymbolTable(GraftSymbolTable);

    addNewPossibleMappingsFromSymbolTable(&newCandidate, HostSymbolTable);
    addNewPossibleMappingsFromMappings(&newCandidate, CurrentMappings);

    fflush(stdout);
    return newCandidate;
}

void printAMappingCandidateList(char * outputFile, MappingCandidate * head) {
    FILE * fout = fopen(outputFile, "w");
    MappingCandidate * p;
    p = head;
    while (p) {
        ListOfString * aux;
        aux = p->possibleMappings;
        fprintf(fout, "Variable: %s %s\n", p->type, p->id);
        fprintf(fout, "CurrentMapping: %s\n", p->currentMapping);
        fprintf(fout, "List of possible mappings: \n");
        while (aux) {
            fprintf(fout, "%s\n", aux->el);
            aux = aux->next;
        }
        p = p ->next;
    }
    fclose(fout);
}

int countElementsInListOfMappingCandidate(MappingCandidate * head) {
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    return count;
}

MappingCandidate * nthElementInListOfMappingCandidate(MappingCandidate * head, int n) {
    while (n > 0 && head) {
        head = head->next;
        n--;
    }
    if (n == 0) {
        MappingCandidate * selectedMappingCandidate = NULL;

        addNewMappingCandidateElement(&selectedMappingCandidate, head->id, head->type);
        addNewCurrentMapping(&selectedMappingCandidate, head->id, head->currentMapping);
        addNewPossibleMappingsFromListOfString(&selectedMappingCandidate, head->possibleMappings);

        return selectedMappingCandidate;
    } else {
        return NULL;
    }
}

MappingCandidate * nthElementInListOfMappingCandidateJustPointer(MappingCandidate * head, int n) {
    while (n > 0 && head) {
        head = head->next;
        n--;
    }
    if (n == 0) {
        return head;
    } else {
        return NULL;
    }
}

Mapping * mappingCandidateToListOfMappingsForCurrent(MappingCandidate * head) {
    Mapping * ListOfMappings = NULL;

    while (head) {
        if (head->currentMapping) {
            addNewMapping(&ListOfMappings, head->id, head->currentMapping);
        }
        head = head->next;
    }

    return ListOfMappings;
}

MappingCandidate * copyListOfMappingCandidate(MappingCandidate * original) {
    MappingCandidate * newMappingCandidate = NULL;
    while (original) {
        addNewMappingCandidateElementCompleteDeclaration(&newMappingCandidate, original->id, original->type,
                original->currentMapping, original->possibleMappings);
        original = original->next;
    }

    return newMappingCandidate;
}

ArrayOfMappingCandidates returnListOfCandidatesWithMoreThanOnePossibleMappingPointers(MappingCandidate * head) {
    MappingCandidate * auxHead = head;
    int lengthOfMappingCandidateList = countElementsInListOfMappingCandidate(head);
    ArrayOfMappingCandidates arrayOfCandidates;
    //here should be just the length of candidates with more than one possible mapping
    (arrayOfCandidates.array) = (MappingCandidate **) malloc(lengthOfMappingCandidateList * sizeof (MappingCandidate *));

    int count = 0;


    while (auxHead) {
        if (countElementsInListOfString(auxHead->possibleMappings) > 1) {
            arrayOfCandidates.array[count] = auxHead;
            count++;
        }

        auxHead = auxHead->next;
    }
    arrayOfCandidates.count = count;
    return arrayOfCandidates;
}
