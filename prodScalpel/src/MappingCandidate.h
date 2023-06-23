/* 
 * File:   MappingCandidate.h
 * Author: ---
 *
 * Created on 30 June 2014, 02:04
 */

#ifndef MAPPINGCANDIDATE_H
#define	MAPPINGCANDIDATE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "SymbolTable.h"
#include "Mapping.h"
#include "ListOfString.h"

#include <stdio.h>

    struct mappingCandidate {
        char * type;
        char * id;
        ListOfString * possibleMappings;
        char * currentMapping;
        struct mappingCandidate * next;
    };

    typedef struct mappingCandidate MappingCandidate;

    struct arrayOfMappingCandidates {
        MappingCandidate ** array;
        int count;
    };

    typedef struct arrayOfMappingCandidates ArrayOfMappingCandidates;

    void addNewPossibleMappingsFromSymbolTable(MappingCandidate ** head, SymbolTable * headSymbolTable);

    void addNewPossibleMappingsFromMappings(MappingCandidate ** head, Mapping * headMapping);

    MappingCandidate * createMappingCandidateFromSymbolTablesAndMappings(SymbolTable * GraftSymbolTable,
            SymbolTable * HostSymbolTable, Mapping * CurrentMappings);

    void printAMappingCandidateList(char * outputFile, MappingCandidate * head);

    void addNewCurrentMappingFromMappings(MappingCandidate ** head, Mapping * headMapping);

    int countElementsInListOfMappingCandidate(MappingCandidate * head);

    MappingCandidate * nthElementInListOfMappingCandidate(MappingCandidate * head, int n);

    Mapping * mappingCandidateToListOfMappingsForCurrent(MappingCandidate * head);

    int addNewCurrentMapping(MappingCandidate ** head, char * id, char * currentMapping);

    MappingCandidate * copyListOfMappingCandidate(MappingCandidate * original);

    MappingCandidate * nthElementInListOfMappingCandidateJustPointer(MappingCandidate * head, int n);

    ArrayOfMappingCandidates returnListOfCandidatesWithMoreThanOnePossibleMappingPointers(MappingCandidate * head);

    void addNewMappingCandidateFromMappingCandidateElement(MappingCandidate ** head, MappingCandidate * candidateToBeAdded);

    void freeMappingCandidateList(MappingCandidate ** head);

    int removeMappingCandidate(MappingCandidate ** head, char * id, char * type);


#ifdef	__cplusplus
}
#endif

#endif	/* MAPPINGCANDIDATE_H */

