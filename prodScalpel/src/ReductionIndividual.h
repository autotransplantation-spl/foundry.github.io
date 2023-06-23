/* 
 * File:   ReductionIndividual.h
 * Author: ---
 *
 * Created on 14 October 2014, 21:16
 */

#ifndef REDUCTIONINDIVIDUAL_H
#define	REDUCTIONINDIVIDUAL_H

#include "ListOfInt.h"


#ifdef	__cplusplus
extern "C" {
#endif
    
    struct reduction_individual {
        ListOfInt * deletedLines;
        double fitness;
        struct reduction_individual * next;
    };

    typedef struct reduction_individual Reduction_Individual;
    
    void freeListOfReductionIndividual(Reduction_Individual ** head);
    
    void addNewReductionIndividual(Reduction_Individual ** head);
    
    void addNewReductionIndividualWithLines(Reduction_Individual ** head, ListOfInt * delLines);
    
    Reduction_Individual * copyListOfReductionIndividual(Reduction_Individual * head);
    
    void instantiateReductionIndividualInFile(char * fileName, Reduction_Individual * individual,
        ListOfString * succesfullCandidateLOCs, DependencyList * declarationDependencies,
        ArrayOfStrings candidateArrayOfLocs);
    
    void sortReductionPopulationByFitness(Reduction_Individual ** head);
    
    Reduction_Individual * crossoverTwoGPReductionIndividuals(Reduction_Individual * first, 
        Reduction_Individual * secondIndividual);
    
    Reduction_Individual * addGPReductionCandidateToAListPointerCopy(Reduction_Individual ** head, 
        Reduction_Individual * newIndividual);
    
    void addListOfGPReductionIndividualToAnExistingOne(Reduction_Individual ** destination, 
        Reduction_Individual * source);
    
    Reduction_Individual * removeExcedingReductionIndividualsRandomForSameFitness(Reduction_Individual ** head, int desiredLength);
    
    int countElementsInListOfGPReductionIndividual(Reduction_Individual * head);
    
    Reduction_Individual * nthElementInListOfGPReductionIndividual(Reduction_Individual * head, int n);
    
    ListOfInt * returnExistingLOCs(Reduction_Individual * head);
    

#ifdef	__cplusplus
}
#endif

#endif	/* REDUCTIONINDIVIDUAL_H */

