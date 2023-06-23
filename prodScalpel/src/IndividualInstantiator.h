/* 
 * File:   IndividualInstantiator.h
 * Author: ---
 *
 * Created on 02 July 2014, 00:32
 */

#ifndef INDIVIDUALINSTANTIATOR_H
#define	INDIVIDUALINSTANTIATOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "ListOfString.h"
#include "PrepareForGP.h"
#include "GlobalDeclarations.h"
#include "GPIndividual.h"
#include "DependencyListWithID.h"


    void instantiateAnIndividual(ListOfString * SkeletonSourceCode, char * GraftInterfaceTempOutput,
            char * sourceOutputCoreFunctionality, char * skeletonInterfaceSourceCodeOutput,
            ArrayOfStrings SkeletonLOCsArray, DependencyList * ListOfDependenciesForStatements,
            CallDependency * ListOfNeededFunctionsForAllLOCs, GlobalDeclarations ListOfFinalGlobalDeclarations,
            DependencyList * GlobalDependencyList, DependencyList * SkeletonDependenciesOnGlobals,
            char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile,
            char * GraftFunctionName, char * finalGraftInterfaceFile, int TotalIDsInHostSymbolTable,
            char * individualFileName, char * GlobalFctDependOutput, char * TXLTemporaryFolder);

    void completeInstantiation(ListOfString * SkeletonSourceCode, char * GraftInterfaceTempOutput,
            char * sourceOutputCoreFunctionality, char * skeletonInterfaceSourceCodeOutput,
            ArrayOfStrings SkeletonLOCsArray, DependencyList * ListOfDependenciesForStatements,
            CallDependency * ListOfNeededFunctionsForAllLOCs, GlobalDeclarations ListOfFinalGlobalDeclarations,
            DependencyList * GlobalDependencyList, DependencyList * SkeletonDependenciesOnGlobals,
            char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile,
            char * GraftFunctionName, char * finalGraftInterfaceFile, int TotalIDsInHostSymbolTable,
            char * GlobalDependenciesOnFunctions, char * TXLTemporaryFolder);

//TODO LOS DELETE UNUSED
    void extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCs(char * sourceOutputCoreFunctionality,
            CallDependency * ListOfNeededFunctionsForAllLOCs, GlobalDeclarations ListOfFinalGlobalDeclarations,
            DependencyList * GlobalDependencyList, DependencyList * SkeletonDependenciesOnGlobals,
            char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile,
            ListOfString * candidateSourceCode, ListOfString * TheListOfTransplantedMarkers,
            char * outputFileGlobalDependenciesOnFunctions, char * TXLTemporaryFolder);
//ENDTODO
    void extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsFromSkeleton(char * sourceOutputCoreFunctionality,
                                                                            CallDependency * ListOfNeededFunctionsForAllLOCs, GlobalDeclarations ListOfFinalGlobalDeclarations,
                                                                            DependencyList * GlobalDependencyList, DependencyList * SkeletonDependenciesOnGlobals,
                                                                            char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile,
                                                                            ListOfString * candidateSourceCode, ListOfString * TheListOfTransplantedMarkers,
                                                                            char * outputFileGlobalDependenciesOnFunctions, char * TXLTemporaryFolder);

    void extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsFromOrgan(ListOfString * ListOfSourceHeaderFilesNeeded, char * sourceOutputCoreFunctionality,
                                                                CallDependency * ListOfNeededFunctionsForAllLOCs, GlobalDeclarations ListOfFinalGlobalDeclarations,
                                                                DependencyList * GlobalDependencyList, DependencyList * SkeletonDependenciesOnGlobals,
                                                                char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile,
                                                                ListOfString * candidateSourceCode, ListOfString * TheListOfTransplantedMarkers,
                                                                char * outputFileGlobalDependenciesOnFunctions, char * TXLTemporaryFolder);
#if 1 /* MULTIFILES */
#if 0 // LOS MULTHEADERFILE
void extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsInMultiFiles2(char * sourceOutputCoreFunctionality, char * headerOutputCoreFunctionality,
                                                                            CallDependency * ListOfNeededFunctionsForAllLOCs, GlobalDeclarations ListOfFinalGlobalDeclarations,
                                                                            DependencyList * GlobalDependencyList, DependencyList * SkeletonDependenciesOnGlobals,
                                                                            char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile,
                                                                            ListOfString * candidateSourceCode, ListOfString * TheListOfTransplantedMarkers,
                                                                            char * outputFileGlobalDependenciesOnFunctions, char * TXLTemporaryFolder);
#else

void extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsInMultiFiles2(char * sourceOutputCoreFunctionality,
                                                                             CallDependency * ListOfNeededFunctionsForAllLOCs, GlobalDeclarations ListOfFinalGlobalDeclarations,
                                                                             DependencyList * GlobalDependencyList, DependencyList * SkeletonDependenciesOnGlobals,
                                                                             char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile,
                                                                             ListOfString * candidateSourceCode, ListOfString * TheListOfTransplantedMarkers,
                                                                             char * outputFileGlobalDependenciesOnFunctions, char * TXLTemporaryFolder);

#endif


#ifdef VEIN_GLOBAL_EXTRACTION
extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsInHeaderFile2(char * currentHeaderFiles, char * sourceOutputCoreFunctionality,
                                                                       CallDependency * ListOfNeededFunctionsForAllLOCs, GlobalDeclarations ListOfFinalGlobalDeclarations,
                                                                       DependencyList * GlobalDependencyList, DependencyList * SkeletonDependenciesOnGlobals,
                                                                       char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile,
                                                                       ListOfString * candidateSourceCode, ListOfString * TheListOfTransplantedMarkers,
                                                                       char * outputFileGlobalDependenciesOnFunctions, char * TXLTemporaryFolder);
#endif

#ifdef HEADER_FILE
extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsInHeaderFile(char * currentHeaderFiles, char * sourceOutputCoreFunctionality,
        CallDependency * ListOfNeededFunctionsForAllLOCs, GlobalDeclarations ListOfFinalGlobalDeclarations,
        DependencyList * GlobalDependencyList, DependencyList * SkeletonDependenciesOnGlobals,
char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile,
        ListOfString * candidateSourceCode, ListOfString * TheListOfTransplantedMarkers,
char * outputFileGlobalDependenciesOnFunctions, char * TXLTemporaryFolder);

#endif


void extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsInMultiFiles(char * sourceOutputCoreFunctionality,
                                                                CallDependency * ListOfNeededFunctionsForAllLOCs, GlobalDeclarations ListOfFinalGlobalDeclarations,
                                                                DependencyList * GlobalDependencyList, DependencyList * SkeletonDependenciesOnGlobals,
                                                                char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile,
                                                                ListOfString * candidateSourceCode, ListOfString * TheListOfTransplantedMarkers,
                                                                char * outputFileGlobalDependenciesOnFunctions, char * TXLTemporaryFolder);
#endif


    int instantiateGPCandidateWithExistingGlobalAndCoreFeature(ListOfString * SkeletonSourceCode,
            ArrayOfStrings SkeletonLOCsArray, char * individualFile, DependencyList * ListOfDependenciesForStatements,
            char * GraftInterfaceTempOutput, char * skeletonInterfaceSourceCodeOutput, char * finalGraftInterfaceFile,
			char * TXLTemporaryFolder);

    void instantiateGPCandidateWithExistingGlobalAndCoreFeatureGromGPIndividual(ListOfString * SkeletonSourceCode,
            ArrayOfStrings SkeletonLOCsArray, GPIndividual * individual, DependencyList * ListOfDependenciesForStatements,
            char * GraftInterfaceTempOutput, char * skeletonInterfaceSourceCodeOutput, char * finalGraftInterfaceFile,
            DependencyListWithID * dependencyListForAbstract, char * TXLTemporaryFolder, ListOfString * listOfSourceFiles);

    ListOfString * instantiateCurrentIndividualInSkeleton(char * initialFunctionFile, char * initialMappingsFile,
    		char * TXlTemporaryFolder);

    void addLocsFromSourceToDestination(char * destinationFileName, char * sourceFileName, char * TXLProgsPath);

    ListOfString * generateNewSkeletonForCandidateFromGPIndividual(ArrayOfStrings SkeletonLOCsArray,
            ListOfString * SkeletonSourceCode, GPIndividual * individual, DependencyList * ListOfDependenciesForStatements,
            ListOfString ** TheListOfTransplantedMarkers,
            DependencyListWithID * dependencyListForAbstract,
			char * TXLTemporaryFolder);

    void instantiateAnIndividualFromGPIndividual(ListOfString * SkeletonSourceCode, char * GraftInterfaceTempOutput,
            char * sourceOutputCoreFunctionality, char * skeletonInterfaceSourceCodeOutput,
            ArrayOfStrings SkeletonLOCsArray, DependencyList * ListOfDependenciesForStatements,
            CallDependency * ListOfNeededFunctionsForAllLOCs, GlobalDeclarations ListOfFinalGlobalDeclarations,
            DependencyList * GlobalDependencyList, DependencyList * SkeletonDependenciesOnGlobals,
            char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile,
            char * GraftFunctionName, char * finalGraftInterfaceFile, int TotalIDsInHostSymbolTable,
            GPIndividual * individual, DependencyListWithID * dependencyListForAbstract, char * GlobalDependenciesOnFunctions,
			char * TXLTemporaryFolder);

    DependencyList * generateAdditionalsDeclarationsDependenciesForAbstractInstantiationsToDonorIDs(
    		DependencyListWithID * DonorIdsDeclarationDependences,
    		Mapping * FinalMappingsInGraft);

void extractNeededFunctionsAndGlobalDeclarations(
        char * sourceOutputCoreFunctionality,
        GlobalDeclarations ListOfFinalGlobalDeclarations,
        DependencyList * GlobalDependencyList,
        DependencyList * SkeletonDependenciesOnGlobals,
        char * tempGlobalDeclarations,
        char * definedGlobalTypesAndVariablesFile,
        ListOfString * TheListOfTransplantedMarkers,
        char * TXLTemporaryFolder);
//LOS
void extractFunctionMarkers(char * sourceFile, char * outputFile, char * TXLProgsPath);

void extractNeededFunctionsAndGlobalDeclarationsForGlobalVarUnion(
        char * currentHeaderFiles,
        char * sourceOutputCoreFunctionality,
        CallDependency * ListOfNeededFunctionsForAllLOCs,
        GlobalDeclarations ListOfFinalGlobalDeclarations,
        DependencyList * GlobalDependencyList,
        DependencyList * SkeletonDependenciesOnGlobals,
        char * tempGlobalDeclarations,
        char * definedGlobalTypesAndVariablesFile,
        ListOfString * candidateSourceCode,
        ListOfString * TheListOfTransplantedMarkers,
        char * outputFileGlobalDependenciesOnFunctions,
        char * TXLTemporaryFolder);

void removeLocsFromSourceFile(char * sourceFile, char * sourceFileWithLocsToBeRemoved, char * TXLProgsPath);

void addLocsFromSourceToDestinationWithDirectives(char * destinationFileName,
                                                  char * sourceFileName, char * TXLProgsPath);

void extractCoreFunctionsCalledInIndividual(
        CallDependency * ListOfNeededFunctionsForAllLOCs,
        ListOfString * candidateLOCsInstantiated,
        char * headerFilesForCoreFunctions, char * sourceFileForCoreFunction,
        ListOfString ** FinalListOfTransplantedFunctions,
        CallDependency * calledFunctionsByGlobals,
        char * TXLTemporaryFolder);

#ifdef	__cplusplus
}
#endif

#endif	/* INDIVIDUALINSTANTIATOR_H */

