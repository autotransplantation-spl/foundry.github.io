/* 
 * File:   GPIndividual.h
 * Author: ---
 *
 * Created on 12 July 2014, 19:36
 */

#ifndef GPINDIVIDUAL_H
#define	GPINDIVIDUAL_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#include "ListOfInt.h"
#include "ListOfString.h"
#include "Mapping.h"
#include "SymbolTable.h"
#include "DeclarationSymbolTable.h"
#include "MappingCandidate.h"

#include <stdio.h>

struct gPIndividual {
    int ID;
    double fitness;

    ListOfInt * selectedLOCs;
    Mapping * listOfAbstractMappings;
    ListOfString * MappedDeclarations;

    DeclarationSymbolTable * candidateDeclarationSymbolTable;
    MappingCandidate * candidateMappings;

    //for easy random selection of mutations, where this is possible also we should keep
    //an array of the mapping candidates for which there are more than 1 possible mapping
    ArrayOfMappingCandidates arrayOfCandidateMappingsWithMoreThanOnePossibleMapping;

    struct gPIndividual * next;
};

typedef struct gPIndividual GPIndividual;


void freeListOfGPIndividual(GPIndividual ** head);

GPIndividual * addNewGPIndividual(GPIndividual ** head, ListOfString * ListOfMappedDeclarations, ListOfInt * ListOfSelectedLOCs,
        Mapping * ListOfMappings, double fitness, MappingCandidate * currentMappingCandidate,
        DeclarationSymbolTable * currentDeclarationSymbolTable);

GPIndividual * copyListOfGPIndividual(GPIndividual * head);

int removeGPIndividual(GPIndividual ** head, int removedID);

void printAListOfGPIndividual(GPIndividual * head, char * outputFile);

int countElementsInListOfGPIndividual(GPIndividual * head);

void sortPopulationByFitness(GPIndividual ** head);

int returnNumberOfMappedIDsToHostSymbolTable(SymbolTable * HostSymbolTable, GPIndividual * candidate);

GPIndividual * nthElementInListOfGPIndividualJustPointer(GPIndividual * head, int n);

GPIndividual * nthElementInListOfGPIndividual(GPIndividual * head, int n);

void syncronizeAListOfGPIndividuals(GPIndividual * head);

ListOfInt * syncronizeGPIndividualID(GPIndividual * head);

GPIndividual * addGPCandidateToAListPointerCopy(GPIndividual ** head, GPIndividual * newIndividual);

GPIndividual * copyAnGPIndividualCandidate(GPIndividual * candidate);

void addListOfGPIndividualToAnExistingOne(GPIndividual ** destination, GPIndividual * source);

int removeNthGPIndividual(GPIndividual ** head, int n, GPIndividual ** removedIndividual);

void printAGPIndividual(GPIndividual * head, char * outputFile);

void freeGPIndividual(GPIndividual ** head);

#endif	/* GPINDIVIDUAL_H */

