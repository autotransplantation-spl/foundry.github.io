#include "GPIndividual.h"
#include "ListOfString.h"
#include "ListOfInt.h"
#include "Mapping.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <malloc.h>

void freeListOfGPIndividual(GPIndividual ** head) {
    GPIndividual * aux;
    //BUGGGGGGGGg
    while (* head) {
        aux = *head;
        * head = (*head) -> next;




        freeGPIndividual(&aux);



        /*
        
        freeListOfStrings(&aux->MappedDeclarations);
        aux->MappedDeclarations = NULL;

        freeListOfInt(&aux->selectedLOCs);
        aux->selectedLOCs = NULL;

        freeMapping(&aux->listOfAbstractMappings);
        aux->listOfAbstractMappings = NULL;

        aux->ID = -1;
        aux->fitness = -1.00;

        aux->next = NULL;
        free(aux);
         * */
        aux = NULL;
    }
    (* head) = NULL; //just in case...
}

void freeGPIndividual(GPIndividual ** head) {
    GPIndividual * aux;


    aux = *head;
    free(aux->arrayOfCandidateMappingsWithMoreThanOnePossibleMapping.array);

    freeDeclarationSymbolTable(&(aux->candidateDeclarationSymbolTable));
    aux->candidateDeclarationSymbolTable = NULL;

    freeMappingCandidateList(&(aux->candidateMappings));
    aux->candidateMappings = NULL;

    freeListOfStrings(&aux->MappedDeclarations);
    aux->MappedDeclarations = NULL;

    freeListOfInt(&aux->selectedLOCs);
    aux->selectedLOCs = NULL;

    freeMapping(&aux->listOfAbstractMappings);
    aux->listOfAbstractMappings = NULL;

    aux->ID = -1;
    aux->fitness = -1.00;

    aux->next = NULL;
    free(aux);
    aux = NULL;

    (* head) = NULL; //just in case...
}

GPIndividual * addNewGPIndividual(GPIndividual ** head, ListOfString * ListOfMappedDeclarations, ListOfInt * ListOfSelectedLOCs,
        Mapping * ListOfMappings, double fitness, MappingCandidate * currentMappingCandidate,
        DeclarationSymbolTable * currentDeclarationSymbolTable) {
    GPIndividual * newEl = (GPIndividual *) malloc(1 * sizeof (GPIndividual));
    newEl->MappedDeclarations = NULL;
    newEl->listOfAbstractMappings = NULL;
    newEl->selectedLOCs = NULL;
    newEl->next = NULL;
    newEl->candidateMappings = currentMappingCandidate;
    newEl->candidateDeclarationSymbolTable = currentDeclarationSymbolTable;


    newEl->arrayOfCandidateMappingsWithMoreThanOnePossibleMapping =
            returnListOfCandidatesWithMoreThanOnePossibleMappingPointers(newEl->candidateMappings);

    if (ListOfMappedDeclarations) {
        newEl->MappedDeclarations = copyCompleteListOfString(ListOfMappedDeclarations);
    } else {
        newEl->MappedDeclarations = declarationSymbolTableToListOfStringForGPIndividual
                (newEl->candidateDeclarationSymbolTable);
    }




    newEl->listOfAbstractMappings = copyListOfMapping(ListOfMappings);
    newEl->selectedLOCs = copyListOfInt(ListOfSelectedLOCs);

    newEl->fitness = fitness;

    if (* head == NULL) {
        //first individual has ID = 0
        newEl->ID = 0;
        * head = newEl;
    } else {
        GPIndividual * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        //the new individual ID is the ID of previous one + 1
        newEl->ID = p->ID + 1;
        p ->next = newEl;
    }

    //return a pointer to the newly added element
    return newEl;
}

GPIndividual * copyListOfGPIndividual(GPIndividual * head) {
    GPIndividual * newHead = NULL;
    GPIndividual * pHead = NULL;
    pHead = head;
    while (pHead) {

        MappingCandidate * newMappingCandidate = copyListOfMappingCandidate(pHead->candidateMappings);
        DeclarationSymbolTable * newDeclSymbolTable = copyDeclarationSymbolTableList(pHead->candidateDeclarationSymbolTable);

        addNewGPIndividual(&newHead, pHead->MappedDeclarations, pHead->selectedLOCs, pHead->listOfAbstractMappings,
                pHead->fitness, newMappingCandidate, newDeclSymbolTable);
        pHead = pHead->next;
    }
    return newHead;
}

int removeGPIndividual(GPIndividual ** head, int removedID) {
    GPIndividual * p;
    p = *head;
    int s = 0;
    if (p->ID == removedID) {
        *head = p->next;
        free(p);
        p = NULL;
        s = 1;
    } else {
        while (p->next && s == 0) {
            if (p->ID == removedID) {
                GPIndividual * aux;
                aux = p->next;
                p -> next = p -> next -> next;

                freeListOfStrings(&aux->MappedDeclarations);
                freeMapping(&aux->listOfAbstractMappings);
                freeListOfInt(&aux->selectedLOCs);

                aux->MappedDeclarations = NULL;
                aux->listOfAbstractMappings = NULL;
                aux->selectedLOCs = NULL;

                aux->ID = -1;
                aux->fitness = -1;

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

void printAListOfGPIndividual(GPIndividual * head, char * outputFile) {
    GPIndividual * p;
    p = head;
    FILE * fout = fopen(outputFile, "w");
    while (p) {
        fprintf(fout, "Abstract_Mappings:\n");
        Mapping * auxMapping = p->listOfAbstractMappings;

        while (auxMapping) {
            fprintf(fout, "%s %s\n", auxMapping->source, auxMapping->destination);
            auxMapping = auxMapping->next;
        }

        fprintf(fout, "Declaration_Mappings:\n");

        ListOfString * auxDeclMappings = p->MappedDeclarations;

        while (auxDeclMappings) {
            fprintf(fout, "%s\n", auxDeclMappings->el);
            auxDeclMappings = auxDeclMappings->next;
        }

        fprintf(fout, "Statement_Line_Number:\n");

        ListOfInt * auxListOfInt = p->selectedLOCs;

        while (auxListOfInt) {
            fprintf(fout, "%d\n", auxListOfInt->value);
            auxListOfInt = auxListOfInt->next;
        }

        fprintf(fout, "FITNESS: %4.2f\n", p->fitness);

        fprintf(fout, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        p = p->next;
    }
    fclose(fout);
}

int countElementsInListOfGPIndividual(GPIndividual * head) {
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    return count;
}


//bubble sort for the moment, to be replaced with qsort for lists

void sortPopulationByFitness(GPIndividual ** head) {
    int signal = 1;
    while (signal) {
        signal = 0;
        GPIndividual * auxPopulation = *head;

        if (auxPopulation->next) {
            if (auxPopulation->fitness < auxPopulation->next->fitness) {
                GPIndividual * auxIndividual = auxPopulation->next;
                auxPopulation->next = auxPopulation->next->next;
                auxIndividual->next = auxPopulation;

                *head = auxIndividual;

                signal = 1;
            }
        }

        while (auxPopulation->next->next) {
            if (auxPopulation->next->fitness < auxPopulation->next->next->fitness) {
                GPIndividual * auxIndividual = auxPopulation->next->next;
                auxPopulation->next->next = auxPopulation->next->next->next;
                auxIndividual->next = auxPopulation->next;
                auxPopulation->next = auxIndividual;

                signal = 1;
            }
            auxPopulation = auxPopulation->next;
        }
    }
}

int returnNumberOfMappedIDsToHostSymbolTable(SymbolTable * HostSymbolTable, GPIndividual * candidate) {
    int mappedIDs = 0;

    mappedIDs += countElementsInListOfString(candidate->MappedDeclarations);

    Mapping * auxMapping = candidate->listOfAbstractMappings;

    while (auxMapping) {
        if (searchForASymbolTableEntry(HostSymbolTable, auxMapping->destination)) {
            mappedIDs++;
        }
        auxMapping = auxMapping->next;
    }

    return mappedIDs;
}

ListOfInt * syncronizeGPIndividualID(GPIndividual * head) {
    GPIndividual * aux = head;
    ListOfInt * existentLOCs = NULL;
    int currentID = 0;
    while (aux) {
        aux->ID = currentID;
        currentID++;
        ListOfInt * auxSelectedLOCs = aux->selectedLOCs;
        while (auxSelectedLOCs) {
            if (!searchAnIntInListOfInt(existentLOCs, auxSelectedLOCs->value)) {
                addNewInt(&existentLOCs, auxSelectedLOCs->value);
            }
            auxSelectedLOCs = auxSelectedLOCs->next;
        }
        aux = aux->next;
    }
    return existentLOCs;
}

void syncronizeAListOfGPIndividuals(GPIndividual * head) {
    GPIndividual * aux = head;

    while (aux) {
        freeListOfStrings(&(aux->MappedDeclarations));
        freeMapping(&(aux->listOfAbstractMappings));
        aux->MappedDeclarations = NULL;
        aux->listOfAbstractMappings = NULL;

        aux->listOfAbstractMappings = mappingCandidateToListOfMappingsForCurrent(aux->candidateMappings);
        aux->MappedDeclarations = declarationSymbolTableToListOfStringForGPIndividual
                (aux->candidateDeclarationSymbolTable);

        free(aux->arrayOfCandidateMappingsWithMoreThanOnePossibleMapping.array);
        aux->arrayOfCandidateMappingsWithMoreThanOnePossibleMapping =
                returnListOfCandidatesWithMoreThanOnePossibleMappingPointers(aux->candidateMappings);

        /*
        free(aux->arrayOfCandidateMappingsWithMoreThanOnePossibleMapping);
        aux->arrayOfCandidateMappingsWithMoreThanOnePossibleMapping = 
                returnListOfCandidatesWithMoreThanOnePossibleMappingPointers(aux->candidateMappings);
         */

        //ListOfString * listOfDeclarationMappings = NULL;
        //addNewDeclarationSymbolTableToListOfStringForGPIndividual(&listOfDeclarationMappings, searchedEl->declarationMarker,
        //searchedEl->id, selectedItemDeclaration);
        aux = aux->next;
    }
}

GPIndividual * nthElementInListOfGPIndividual(GPIndividual * head, int n) {
    while (n > 0 && head) {
        head = head->next;
        n--;
    }
    if (n == 0) {
        GPIndividual * selectedMappingCandidate = NULL;

        MappingCandidate * newMappingCandidate = copyListOfMappingCandidate(head->candidateMappings);
        DeclarationSymbolTable * newDeclSymbolTable = copyDeclarationSymbolTableList(head->candidateDeclarationSymbolTable);
        addNewGPIndividual(&selectedMappingCandidate, head->MappedDeclarations, head->selectedLOCs, head->listOfAbstractMappings,
                head->fitness, newMappingCandidate, newDeclSymbolTable);
        return selectedMappingCandidate;
    } else {
        return NULL;
    }
}

int removeNthGPIndividual(GPIndividual ** head, int n, GPIndividual ** removedIndividual) {
    GPIndividual * auxHead = *head;


    if (n == 0) {
        return 0;
    }

    while (n > 1 && auxHead) {
        auxHead = auxHead->next;
        n--;
    }

    if (n == 0) {
        return 0;
    } else {
        while (n > 1 && auxHead) {
            auxHead = auxHead->next;
            n--;
        }
        if (auxHead->next) {
            GPIndividual * aux;
            aux = auxHead->next;
            auxHead -> next = auxHead -> next -> next;

            
            //create a new instance of the removed individual, and add it to the list!
            MappingCandidate * newMappingCandidate = copyListOfMappingCandidate(aux->candidateMappings);
            DeclarationSymbolTable * newDeclSymbolTable = copyDeclarationSymbolTableList(aux->candidateDeclarationSymbolTable);
            addNewGPIndividual(&(*removedIndividual), aux->MappedDeclarations, aux->selectedLOCs, aux->listOfAbstractMappings,
                    aux->fitness, newMappingCandidate, newDeclSymbolTable);



            freeListOfStrings(&aux->MappedDeclarations);
            freeMapping(&aux->listOfAbstractMappings);
            freeListOfInt(&aux->selectedLOCs);

            aux->MappedDeclarations = NULL;
            aux->listOfAbstractMappings = NULL;
            aux->selectedLOCs = NULL;

            aux->ID = -1;
            aux->fitness = -1;

            free(aux);
            aux = NULL;
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

GPIndividual * nthElementInListOfGPIndividualJustPointer(GPIndividual * head, int n) {
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

GPIndividual * copyAnGPIndividualCandidate(GPIndividual * candidate) {
    GPIndividual * newCandidate = NULL;

    MappingCandidate * newMappingCandidate = copyListOfMappingCandidate(candidate->candidateMappings);
    DeclarationSymbolTable * newDeclSymbolTable = copyDeclarationSymbolTableList(candidate->candidateDeclarationSymbolTable);
    addNewGPIndividual(&newCandidate, candidate->MappedDeclarations, candidate->selectedLOCs, candidate->listOfAbstractMappings,
            candidate->fitness, newMappingCandidate, newDeclSymbolTable);

    return newCandidate;
}

void addListOfGPIndividualToAnExistingOne(GPIndividual ** destination, GPIndividual * source) {
    while (source) {
        MappingCandidate * newMappingCandidate = copyListOfMappingCandidate(source->candidateMappings);
        DeclarationSymbolTable * newDeclSymbolTable = copyDeclarationSymbolTableList(source->candidateDeclarationSymbolTable);
        addNewGPIndividual(&(*destination), source->MappedDeclarations, source->selectedLOCs, source->listOfAbstractMappings,
                source->fitness, newMappingCandidate, newDeclSymbolTable);
        source = source->next;
    }
}

GPIndividual * addGPCandidateToAListPointerCopy(GPIndividual ** head, GPIndividual * newIndividual) {

    if (* head == NULL) {
        //first individual has ID = 0
        newIndividual->ID = 0;
        * head = newIndividual;
    } else {
        GPIndividual * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        //the new individual ID is the ID of previous one + 1
        newIndividual->ID = p->ID + 1;
        p ->next = newIndividual;
    }

    //return a pointer to the newly added element
    return newIndividual;
}

void printAGPIndividual(GPIndividual * head, char * outputFile) {
    GPIndividual * p;
    p = head;
    FILE * fout = fopen(outputFile, "w");

    fprintf(fout, "Abstract_Mappings:\n");
    Mapping * auxMapping = p->listOfAbstractMappings;

    while (auxMapping) {
        fprintf(fout, "%s %s\n", auxMapping->source, auxMapping->destination);
        auxMapping = auxMapping->next;
    }

    fprintf(fout, "Declaration_Mappings:\n");

    ListOfString * auxDeclMappings = p->MappedDeclarations;

    while (auxDeclMappings) {
        fprintf(fout, "%s\n", auxDeclMappings->el);
        auxDeclMappings = auxDeclMappings->next;
    }

    fprintf(fout, "Statement_Line_Number:\n");

    ListOfInt * auxListOfInt = p->selectedLOCs;

    while (auxListOfInt) {
        fprintf(fout, "%d\n", auxListOfInt->value);
        auxListOfInt = auxListOfInt->next;
    }

    //fprintf(fout, "FITNESS: %4.2f\n", p->fitness);

    //fprintf(fout, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    fclose(fout);
}