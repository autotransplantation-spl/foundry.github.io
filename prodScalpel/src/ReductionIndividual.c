#include "ListOfInt.h"
#include "ListOfString.h"
#include "DependencyList.h"
#include "PrepareForGP.h"
#include "ReductionIndividual.h"
#include "GP.h"

#include <stdio.h>
//#include <malloc.h>
#include <stdlib.h>
#include <string.h>

void freeListOfReductionIndividual(Reduction_Individual ** head) {
    Reduction_Individual * aux;

    while (* head) {
        aux = *head;
        * head = (*head) -> next;
        freeListOfInt(&aux->deletedLines);
        aux->deletedLines = NULL;
        aux->next = NULL;
        free(aux);
        aux = NULL;
    }
    (* head) = NULL; //just in case...
}

void addNewReductionIndividual(Reduction_Individual ** head) {
    Reduction_Individual * newEl = (Reduction_Individual *) malloc(1 * sizeof (Reduction_Individual));
    newEl->deletedLines = NULL;
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        Reduction_Individual * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

void addNewReductionIndividualWithLines(Reduction_Individual ** head, ListOfInt * delLines) {
    Reduction_Individual * newEl = (Reduction_Individual *) malloc(1 * sizeof (Reduction_Individual));
    newEl->fitness = 0;
    newEl->deletedLines = copyListOfInt(delLines);
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        Reduction_Individual * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

Reduction_Individual * copyListOfReductionIndividual(Reduction_Individual * head) {
    Reduction_Individual * newHead = NULL;
    Reduction_Individual * pHead = NULL;
    pHead = head;
    while (pHead) {
        addNewReductionIndividualWithLines(&newHead, pHead->deletedLines);
        pHead = pHead->next;
    }
    return newHead;
}

void instantiateReductionIndividualInFile(char * fileName, Reduction_Individual * individual,
        ListOfString * succesfullCandidateLOCs, DependencyList * declarationDependencies,
        ArrayOfStrings candidateArrayOfLocs) {
    ListOfString * neededMarkersForTransplant = NULL;

    for (int i = 0; i < candidateArrayOfLocs.count; i++) {
        if (!searchIntInListOfInts(individual->deletedLines, i)) {
            addNewString(&neededMarkersForTransplant, candidateArrayOfLocs.array[i]);
        }
    }


    ListOfString * auxNeededMarkers = neededMarkersForTransplant;

    DependencyList * completeListOfDependencies = declarationDependencies;
    //to be added the other dependencies if we will decide to use them here also

    while (auxNeededMarkers) {
        //memory leak!!! returnDependencyForAMarker makes new one, while adding adds also
        ListOfString * neededDepsForCurrent = returnDependencyForAMarkerNewPointers(completeListOfDependencies,
                auxNeededMarkers->el);
        if (neededDepsForCurrent) {
            ListOfString * auxListString = neededDepsForCurrent;
            //maybe this is infinite.. it should be checked that the new marker is not already in the list
            while (auxListString) {
                if (!searchStringInListOfStrings(neededMarkersForTransplant, auxListString->el)) {
                    addNewString(&neededMarkersForTransplant, auxListString->el);
                }
                auxListString = auxListString->next;
            }
            freeListOfStrings(&neededDepsForCurrent);
        }
        auxNeededMarkers = auxNeededMarkers->next;
    }

    ListOfString * candidateLOCs = NULL;
    ListOfString * auxSkeletonCode = succesfullCandidateLOCs;

    while (auxSkeletonCode) {
        //add some marker for LABEL ABST!!!, not like this
        if (!strstr(auxSkeletonCode->el, "/*") && !strstr(auxSkeletonCode->el, "//")) {
            addNewString(&candidateLOCs, auxSkeletonCode->el);
        } else {
            auxNeededMarkers = neededMarkersForTransplant;
            //add just once every line, even if it is needed for more then one declaration
            int signal = 0;
            while (auxNeededMarkers && !signal) {
                if (strstr(auxSkeletonCode->el, auxNeededMarkers->el)) {
                    //the current line in skeleton was identified, so it should be added just once
                    signal = 1;
                    addNewString(&candidateLOCs, auxSkeletonCode->el);
                }
                auxNeededMarkers = auxNeededMarkers->next;
            }
        }
        auxSkeletonCode = auxSkeletonCode->next;
    }
    printAListOfStrings(candidateLOCs, fileName);
}


//bubble sort for the moment, to be replaced with qsort for lists

void sortReductionPopulationByFitness(Reduction_Individual ** head) {
    int signal = 1;
    while (signal) {
        signal = 0;
        Reduction_Individual * auxPopulation = *head;

        if (auxPopulation->next) {
            if (auxPopulation->fitness < auxPopulation->next->fitness) {
                Reduction_Individual * auxIndividual = auxPopulation->next;
                auxPopulation->next = auxPopulation->next->next;
                auxIndividual->next = auxPopulation;

                *head = auxIndividual;

                signal = 1;
            }
        }

        while (auxPopulation->next->next) {
            if (auxPopulation->next->fitness < auxPopulation->next->next->fitness) {
                Reduction_Individual * auxIndividual = auxPopulation->next->next;
                auxPopulation->next->next = auxPopulation->next->next->next;
                auxIndividual->next = auxPopulation->next;
                auxPopulation->next = auxIndividual;

                signal = 1;
            }
            auxPopulation = auxPopulation->next;
        }
    }
}

int countElementsInListOfGPReductionIndividual(Reduction_Individual * head) {
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    return count;
}

int removeNthGPReductionIndividual(Reduction_Individual ** head, int n, Reduction_Individual ** removedIndividual) {
    Reduction_Individual * auxHead = *head;
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
            Reduction_Individual * aux;
            aux = auxHead->next;
            auxHead -> next = auxHead -> next -> next;
            //create a new instance of the removed individual, and add it to the list!
            addNewReductionIndividualWithLines(&(*removedIndividual), aux->deletedLines);
            freeListOfInt(&aux->deletedLines);
            aux->deletedLines = NULL;
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

Reduction_Individual * removeExcedingReductionIndividualsRandomForSameFitness(Reduction_Individual ** head, int desiredLength) {
    //starting from 1, since 1 is added from beginning, for holding the previous element in list
    int count = 1;
    Reduction_Individual * listOfRemovedIndividuals = NULL;

    double currentFitness;

    Reduction_Individual * auxFirstWithCurrentFitness = *head;
    Reduction_Individual * auxPrev = *head;
    Reduction_Individual * auxForRemoveIndividuals = auxPrev->next;
    while (count < desiredLength && auxForRemoveIndividuals) {
        //add all the individuals with the same fitness
        currentFitness = auxForRemoveIndividuals->fitness;

        auxFirstWithCurrentFitness = auxForRemoveIndividuals;
        auxForRemoveIndividuals = auxForRemoveIndividuals->next;
        auxPrev = auxPrev->next;
        count++;

        while (auxForRemoveIndividuals && auxForRemoveIndividuals->fitness == currentFitness) {
            auxForRemoveIndividuals = auxForRemoveIndividuals->next;
            auxPrev = auxPrev->next;
            count++;
        }
    }

    if (auxForRemoveIndividuals) {

        Reduction_Individual * auxAddRemovedIndividuals = auxForRemoveIndividuals;

        //first add all removed individuals in the list for crossover
        while (auxAddRemovedIndividuals) {
            addNewReductionIndividualWithLines(&listOfRemovedIndividuals, auxAddRemovedIndividuals->deletedLines);
            auxAddRemovedIndividuals = auxAddRemovedIndividuals->next;
        }

        //then remove it from the initial population
        freeListOfReductionIndividual(&auxForRemoveIndividuals);
        auxPrev->next = NULL;
        auxForRemoveIndividuals = NULL;
    }

    if (count == desiredLength) {

    } else {
        int elementsToBeRemoved = count - desiredLength;
        while (elementsToBeRemoved > 0) {
            int elementsWithSameFitnessAtTheEnd = countElementsInListOfGPReductionIndividual(auxFirstWithCurrentFitness);

            if (elementsWithSameFitnessAtTheEnd) {
                int randomRemoveIndex = randomIndexJKISSPopulationSelection(elementsWithSameFitnessAtTheEnd, NULL);
                if (!removeNthGPReductionIndividual(&auxFirstWithCurrentFitness, randomRemoveIndex, &listOfRemovedIndividuals)) {
                    elementsToBeRemoved++;
                }
            }

            elementsToBeRemoved--;
        }
    }

    return listOfRemovedIndividuals;

}

Reduction_Individual * nthElementInListOfGPReductionIndividual(Reduction_Individual * head, int n) {
    while (n > 0 && head) {
        head = head->next;
        n--;
    }
    if (n == 0) {
        Reduction_Individual * selectedMappingCandidate = NULL;

        addNewReductionIndividualWithLines(&selectedMappingCandidate, head->deletedLines);
        return selectedMappingCandidate;
    } else {
        return NULL;
    }
}

Reduction_Individual * copyAnGPReductionIndividualCandidate(Reduction_Individual * candidate) {
    Reduction_Individual * newCandidate = NULL;
    addNewReductionIndividualWithLines(&newCandidate, candidate->deletedLines);
    return newCandidate;
}

Reduction_Individual * crossoverTwoGPReductionIndividuals(Reduction_Individual * first, 
        Reduction_Individual * secondIndividual) {
    Reduction_Individual * springIndividual = copyAnGPReductionIndividualCandidate(first);
    Reduction_Individual * second = copyAnGPReductionIndividualCandidate(secondIndividual);
    //in current individual, keep first half from its LOC and add the second half from the second individual
    ListOfInt * newListOfLOCs = NULL;
    int countOfLOCsInCurrentIndividual = countElementsInListOfInt(springIndividual->deletedLines);
    int countOfLOCsInSecondIndividual = countElementsInListOfInt(second->deletedLines);
    //if one of them has just 1 LOC, add it for both of them
    if (countOfLOCsInCurrentIndividual == 1) {
        countOfLOCsInCurrentIndividual++;
    }
    if (countOfLOCsInSecondIndividual == 1) {
        //since here, it will be parsed the first countOfLOCsInSecondIndividualElements
        countOfLOCsInSecondIndividual--;
    }
    //half from both of them
    countOfLOCsInCurrentIndividual = countOfLOCsInCurrentIndividual / 2;
    countOfLOCsInSecondIndividual = countOfLOCsInSecondIndividual / 2;
    ListOfInt * auxLOCsFirstIndividual = springIndividual->deletedLines;
    ListOfInt * auxLOCsSecondIndividual = second->deletedLines;
    while (auxLOCsFirstIndividual && countOfLOCsInCurrentIndividual) {
        if (!searchAnIntInListOfInt(newListOfLOCs, auxLOCsFirstIndividual->value)) {
            addNewInt(&newListOfLOCs, auxLOCsFirstIndividual->value);
            countOfLOCsInCurrentIndividual--;
        }
        auxLOCsFirstIndividual = auxLOCsFirstIndividual->next;
    }
    while (countOfLOCsInSecondIndividual) {
        auxLOCsSecondIndividual = auxLOCsSecondIndividual->next;
        countOfLOCsInSecondIndividual--;
    }

    while (auxLOCsSecondIndividual) {
        if (!searchAnIntInListOfInt(newListOfLOCs, auxLOCsSecondIndividual->value)) {
            addNewInt(&newListOfLOCs, auxLOCsSecondIndividual->value);
        }
        auxLOCsSecondIndividual = auxLOCsSecondIndividual->next;
    }
    //HERE ADD NEW INDIVIDUAL!!!
    freeListOfInt(&springIndividual->deletedLines);
    springIndividual->deletedLines = newListOfLOCs;
    return springIndividual;
}


Reduction_Individual * addGPReductionCandidateToAListPointerCopy(Reduction_Individual ** head, 
        Reduction_Individual * newIndividual) {

    if (* head == NULL) {
        * head = newIndividual;
    } else {
        Reduction_Individual * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newIndividual;
    }
    //return a pointer to the newly added element
    return newIndividual;
}


void addListOfGPReductionIndividualToAnExistingOne(Reduction_Individual ** destination, 
        Reduction_Individual * source) {
    while (source) {
        addNewReductionIndividualWithLines(&(*destination), source->deletedLines);
        source = source->next;
    }
}

ListOfInt * returnExistingLOCs(Reduction_Individual * head) {
    Reduction_Individual * aux = head;
    ListOfInt * existentLOCs = NULL;
    while (aux) {
        ListOfInt * auxSelectedLOCs = aux->deletedLines;
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