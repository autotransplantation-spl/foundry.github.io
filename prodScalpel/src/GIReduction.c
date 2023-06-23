#include "GIReduction.h"
#include "Skeleton.h"
#include "GenTrans.h"
#include "PrepareForGP.h"
#include "GPIndividual.h"
#include "ReductionIndividual.h"
#include "GP.h"
#include "Utils.h"

//#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define REDUCTION_STEPS 5
#define REDUCTION_POPULATION_LENGTH 32


double InitialFitness;
int TotalIndividualLines;

void callLOCsMarker(char * TXLProgsPath, char * inputFileName, char * outputFileName) {

    char * commandTXL;
    commandTXL = (char *) malloc(5000 * sizeof (char));
    printf("[TXL] annotateLOCs.x >> ... annotate LOCs\n");
    sprintf(commandTXL, "%sannotateLOCs.x %s %s %s", TXLProgsPath, inputFileName, outputFileName,
            ConsoleNullOutput);
    int status = system(commandTXL);
    if (status != 0) {
        printf("ERROR! annotate LOCs for GI reduction");
    }
    free(commandTXL);
}

void createDependencyListReduction(char * TXLPath, char * skeletonOutput, char * dependencyListOutput) {
    char * command;
    command = (char *) malloc(400 * sizeof (char));
    sprintf(command, "%sSolveDeclarationDependenciesReduction.x", TXLPath);
    char * commandTXL;
    commandTXL = (char *) malloc(500 * sizeof (char));
    sprintf(commandTXL, "%s %s %s %s", command, skeletonOutput, dependencyListOutput, ConsoleNullOutput);
    int status = system(commandTXL);
    if (status != 0) {
        printf("ERROR! SolveDeclarationDependencies");
        return;
    }
    free(command);
    free(commandTXL);
}

ListOfString * annotateLOCsForGI(char * inputFile, DependencyList ** declarationDependList, char * TXLTemporaryFolder) {
    char * outputFile = (char *) malloc(3000 * sizeof (char)); 
    sprintf(outputFile, "%stemp_annotated_GI.out", TXLTemporaryFolder);
    callLOCsMarker(TXLToolsPath, inputFile,
            outputFile);
    ListOfString * markedOrgan = readListOfStringFromFile(outputFile);
    fixLineNumbers(markedOrgan);


    char * tempDepList = (char *) malloc(3000 * sizeof (char));
    sprintf(tempDepList, "%stemp_dependency_reduction.out", TXLTemporaryFolder);


    char * tempMarkedOrgan = (char *) malloc(3000 * sizeof (char));
    sprintf(tempMarkedOrgan, "%stemp_organ_with_annotations_depend.out", TXLTemporaryFolder);

    printAListOfStrings(markedOrgan, tempMarkedOrgan);

    createDependencyListReduction(TXLToolsPath, tempMarkedOrgan, tempDepList);

    (*declarationDependList) = readDependencyListFromFile(tempDepList);

    return markedOrgan;
}

ArrayOfStrings createArrayOfLineMarkersGIReduction(ListOfString * SkeletonSourceCode, char * TXLTemporaryFolder) {
    char * outputFileAbstractMarkers;
    outputFileAbstractMarkers = (char *) malloc(500 * sizeof (char));
    sprintf(outputFileAbstractMarkers, "%stemp_markers_for_abstract_vars.out", TXLTemporaryFolder);

    char * skeletonTemporaryFile;
    skeletonTemporaryFile = (char *) malloc(500 * sizeof (char));
    sprintf(skeletonTemporaryFile, "%stemp_skeleton_for_mutation_candidates.out", TXLTemporaryFolder);
    printAListOfStrings(SkeletonSourceCode, skeletonTemporaryFile);
    char * tempListOfMarkers;
    tempListOfMarkers = (char *) malloc(500 * sizeof (char));
    sprintf(tempListOfMarkers, "%stemp_file_of_line_markers.out", TXLTemporaryFolder);
    extractStmOrCompoundMarkers(skeletonTemporaryFile, tempListOfMarkers, TXLToolsPath, outputFileAbstractMarkers);

    ListOfString * TempListOfStrings = returnListOfStringFromMarkersFile(tempListOfMarkers);

    free(tempListOfMarkers);
    int numberOfElements = countElementsInListOfString(TempListOfStrings);
    char ** arrayOfStrings;
    arrayOfStrings = (char **) malloc(numberOfElements * sizeof (char *));
    for (int i = 0; i < numberOfElements; i++) {
        arrayOfStrings[i] = (char *) malloc(100 * sizeof (char));
    }
    int count = 0;
    ArrayOfStrings arrayOfMarkers;
    arrayOfMarkers.count = numberOfElements;
    arrayOfMarkers.array = arrayOfStrings;
    ListOfString * auxListOfStr = TempListOfStrings;
    while (auxListOfStr) {
        strcpy(arrayOfMarkers.array[count], auxListOfStr->el);
        count++;
        auxListOfStr = auxListOfStr->next;
    }
    arrayOfMarkers.count = count;
    freeListOfStrings(&TempListOfStrings);
    return arrayOfMarkers;
    /*
    for(int i = 0; i < 5000; i++){
        free(arrayOfStrings [i]);
    }
    free(arrayOfStrings);
     */
}

void computeFitnessReductionIndividual(Reduction_Individual * individual) {
    double fitnessTestCases = computeFitness("Individual.x", 0, 0, 0, TransplantResultLocation);
    double fitnessReduction = (countElementsInListOfInt(individual->deletedLines) / (double) TotalIndividualLines) / 2;
    individual->fitness = fitnessTestCases + fitnessReduction;
#ifdef DEBUGING
    printf("Fitness: %2.4f ; test cases: %2.4f ; reduction: %2.4f\n",
            individual->fitness, fitnessTestCases, fitnessReduction);
#endif
}

void computeFitnessListOfReductionIndividual(Reduction_Individual * population, char * fileForCompilation,
        ListOfString * initialCandidateLOCs, DependencyList * declarationDependencies,
        ArrayOfStrings candidateArrayOfLOCs) {
    Reduction_Individual * auxPopulation = population;
    while (auxPopulation) {

        instantiateReductionIndividualInFile(fileForCompilation, auxPopulation, initialCandidateLOCs,
                declarationDependencies, candidateArrayOfLOCs);

        computeFitnessReductionIndividual(auxPopulation);
        auxPopulation = auxPopulation->next;
    }
}

Reduction_Individual * initialPopulation(ListOfString * candidate, ArrayOfStrings arrayOfLineMarkers,
        DependencyList * declarationDependencies, char * fileForCompilation) {
    Reduction_Individual * newPopulation = NULL;
    for (int i = 0; i < REDUCTION_POPULATION_LENGTH; i++) {
        ListOfInt * currentDeletedLines = randomlySelectOneLOC(arrayOfLineMarkers, NULL);
        addNewReductionIndividualWithLines(&newPopulation, currentDeletedLines);
    }
    computeFitnessListOfReductionIndividual(newPopulation, fileForCompilation, candidate, declarationDependencies,
            arrayOfLineMarkers);

    return newPopulation;
}

void reductionOperator(Reduction_Individual ** initialPopulation, ListOfString * candidate, ArrayOfStrings arrayOfLineMarkers,
        DependencyList * declarationDependencies, char * fileForCompilation) {
    sortReductionPopulationByFitness(&*initialPopulation);
    int newPopulationLength = REDUCTION_POPULATION_LENGTH / 10 * 8;
    //int reproductedPopulationLength = REDUCTION_POPULATION_LENGTH / 10;
    Reduction_Individual * reproductedPopulation = copyListOfReductionIndividual(*initialPopulation);
    //first copy the old population, into a new GPIndividual list
    Reduction_Individual * newPopulation = copyListOfReductionIndividual(*initialPopulation);
    Reduction_Individual * populationForCrossover = removeExcedingReductionIndividualsRandomForSameFitness(&newPopulation, newPopulationLength);
    Reduction_Individual * auxPopulation = newPopulation;
    Reduction_Individual * addedIndividualsAfterCrossOver = NULL;
    int lengthPopForCrossover = countElementsInListOfGPReductionIndividual(populationForCrossover);

    while (auxPopulation) {
        int randCrossoverMutation = randomIndexJKISSOperation(4, NULL);
        //add also reproduction!!!!
        if (randCrossoverMutation == 0 || randCrossoverMutation == 1) {
            //MUTATION
            //LOC mutation
            int typeOfLOCMutation = randomIndexJKISSOperation(2, NULL);
            int elementsInListOfLOCs = countElementsInListOfInt(auxPopulation->deletedLines);
            //just now!!!
            //typeOfLOCMutation = 0;
            if (typeOfLOCMutation == 0 || !elementsInListOfLOCs) {
                //ADDITION
                ListOfInt * selectedLOC = randomlySelectOneLOC(arrayOfLineMarkers, auxPopulation->deletedLines);
                addNewInt(&auxPopulation->deletedLines, selectedLOC->value);
            } else {
                //DELETION
                int randomDeletionPosition = randomIndexJKISSOperation(elementsInListOfLOCs, NULL);
                deleteElementInListOfIntAtPosition(&auxPopulation->deletedLines, randomDeletionPosition);
            }
        } else if (randCrossoverMutation == 2 || randCrossoverMutation == 3) {
            //crossover
            int randomSecondIndividual = randomIndexJKISSCrossoverSelector(lengthPopForCrossover, NULL); //lengthPopForCrossover should be here!!!
            Reduction_Individual * copyOfIndividualInOldPopulation = nthElementInListOfGPReductionIndividual(populationForCrossover,
                    randomSecondIndividual);
            Reduction_Individual * springIndividual = crossoverTwoGPReductionIndividuals(auxPopulation, copyOfIndividualInOldPopulation);
            Reduction_Individual * springIndividual2 = crossoverTwoGPReductionIndividuals(copyOfIndividualInOldPopulation, auxPopulation);
            freeListOfInt(&(auxPopulation->deletedLines));
            auxPopulation->fitness = 0;
            auxPopulation->deletedLines = springIndividual->deletedLines;
            addGPReductionCandidateToAListPointerCopy(&addedIndividualsAfterCrossOver, springIndividual2);
        } else {
            //reproduction
        }
        auxPopulation = auxPopulation->next;
    }
    //add the population together
    //reproductedPopulation
    addListOfGPReductionIndividualToAnExistingOne(&newPopulation, addedIndividualsAfterCrossOver);
    addListOfGPReductionIndividualToAnExistingOne(&newPopulation, reproductedPopulation);
    //sort the population according to the fitness
    computeFitnessListOfReductionIndividual(newPopulation, fileForCompilation, candidate, declarationDependencies,
            arrayOfLineMarkers);
    sortReductionPopulationByFitness(&newPopulation);
    //keep just population length individual in current population
    //for the moment just the first ones, but in the case that there are individuals at the end
    //with equal fitness this should be randomly selection
    removeExcedingReductionIndividualsRandomForSameFitness(&newPopulation, REDUCTION_POPULATION_LENGTH);
    ListOfInt * existingLOCs = returnExistingLOCs(newPopulation);
    ListOfInt * unselectedLines = NULL;
    for (int i = 0; i < arrayOfLineMarkers.count; i++) {
        if (!searchAnIntInListOfInt(existingLOCs, i)) {
            addNewInt(&unselectedLines, i);
        }
    }
    int countOfNonSelectedLOCs = countElementsInListOfInt(unselectedLines);
    int lengthOfNonSelectedLOCs = countOfNonSelectedLOCs;
    //if population length is too low
    int currentLength = countElementsInListOfGPReductionIndividual(newPopulation);
    if (currentLength < REDUCTION_POPULATION_LENGTH) {
        //first add chromosomes that does not exists!!!
        ListOfInt * newSelectedLOCs = NULL;
        while (currentLength < REDUCTION_POPULATION_LENGTH && countOfNonSelectedLOCs) {
            int randLOCIndex = randomIndexJKISS(lengthOfNonSelectedLOCs, newSelectedLOCs);
            int randLOC = nthElementInListOfInt(unselectedLines, randLOCIndex);
            addNewInt(&newSelectedLOCs, randLOC);
            currentLength++;
            countOfNonSelectedLOCs--;
            //first generate a random LOC addition
            ListOfInt * listOfSelectedLOCsForIndividual = NULL;
            addNewInt(&listOfSelectedLOCsForIndividual, randLOC);
            //make a new copy, since it should be new
            addNewReductionIndividualWithLines(&newPopulation, listOfSelectedLOCsForIndividual);
        }
        while (currentLength < REDUCTION_POPULATION_LENGTH) {
            //write in the final interface header, the initial one, with global declarations + graft function header
            //for instantiating it again, without keeping the other declarations
            //first generate a random LOC addition
            ListOfInt * listOfSelectedLOCsForIndividual = randomlySelectOneLOC(arrayOfLineMarkers, NULL);
            addNewReductionIndividualWithLines(&newPopulation,
                    listOfSelectedLOCsForIndividual);
            currentLength++;
        }
    }
    //sort the population according to the fitness
    computeFitnessListOfReductionIndividual(newPopulation, fileForCompilation, candidate, declarationDependencies,
            arrayOfLineMarkers);
    sortReductionPopulationByFitness(&newPopulation);
    freeListOfReductionIndividual(&(*initialPopulation));
    (*initialPopulation) = newPopulation;
}

void GPReduction(ListOfString * candidate, ArrayOfStrings arrayOfLineMarkers,
        DependencyList * declarationDependencies, char * fileForCompilation, char * fileOfReducedIndividual) {
    Reduction_Individual * population = NULL;
#ifdef DEBUGING
    printf("Initial Population:\n");
#endif
    population = initialPopulation(candidate, arrayOfLineMarkers, declarationDependencies, fileForCompilation);
    for (int i = 0; i < REDUCTION_STEPS; i++) {
#ifdef DEBUGING
        printf("Generation number: %d", i);
#endif
        reductionOperator(&population, candidate, arrayOfLineMarkers, declarationDependencies, fileForCompilation);
    }

    //save the fittest individual
    instantiateReductionIndividualInFile(fileOfReducedIndividual, population, candidate,
            declarationDependencies, arrayOfLineMarkers);
    //remove the annotations made by the reduction algorithm
    prettyPrintSourceCodeNoAnnotations(TXLToolsPath, fileOfReducedIndividual, fileOfReducedIndividual);
}

void reduceCandidate(char * candidateFile, char * fileOfReducedIndividual, char * TXLTemporaryFolder) {
    ListOfString * initialCandidate = readListOfStringFromFile(candidateFile);


    DependencyList * declarationDependencies = NULL;
    ListOfString * annotatedCandidate = annotateLOCsForGI(candidateFile, &declarationDependencies, TXLTemporaryFolder);
    ArrayOfStrings arrayOfLineMarkers = createArrayOfLineMarkersGIReduction(annotatedCandidate, TXLTemporaryFolder);
    TotalIndividualLines = arrayOfLineMarkers.count;

    GPReduction(annotatedCandidate, arrayOfLineMarkers, declarationDependencies, candidateFile,
            fileOfReducedIndividual);

#ifdef DEBUG
    printADependencyList("dependReductionList.out", declarationDependencies);
    FILE * foutArrayLineMarkers = fopen("lineMarkersArrayGIREDUCTION.out", "w");
    for (int kk = 0; kk < arrayOfLineMarkers.count; kk++) {
        fprintf(foutArrayLineMarkers, "%d :   %s\n", kk, arrayOfLineMarkers.array[kk]);
    }
    fclose(foutArrayLineMarkers);
#endif
    printAListOfStrings(initialCandidate, candidateFile);
}
