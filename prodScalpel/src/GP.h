/* 
 * File:   GP.h
 * Author: ---
 *
 * Created on 11 July 2014, 19:06
 */

#ifndef GP_H
#define	GP_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#include "DependencyListWithID.h"
#include "PrepareForGP.h"
#include "GlobalDeclarations.h"
#include "ListOfInt.h"

#if 1 //LOSMULTIFILESIMPLEMENTATION
void GPAlgorithm2(ListOfString * SkeletonSourceCode, char * GraftInterfaceTempOutput,
                 char * sourceOutputCoreFunctionality, char * InterfaceCoreFunctionality, char * skeletonInterfaceSourceCodeOutput,
                 ArrayOfStrings SkeletonLOCsArray, DependencyList * ListOfDependenciesForStatements,
                 CallDependency * ListOfNeededFunctionsForAllLOCs, GlobalDeclarations ListOfFinalGlobalDeclarations,
                 DependencyList * GlobalDependencyList, DependencyList * SkeletonDependenciesOnGlobals,
                 char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile,
                 char * GraftFunctionName, char * interfaceHeaderGlobalsAndGraftFunction, int TotalIDsInHostSymbolTable,
                 MappingCandidate * MappingCandidatesForGP,
                 DeclarationSymbolTable * GraftSymbolTablePossibleMatching, Mapping * CurrentDonorMappings,
                 DependencyListWithID * dependencyListForAbstract, char * tempDefinesFile,
                 char *tempIncludeLibFile, char * finalInterfaceForCompilation,
                 SymbolTable * HostSymbolTable, char * GlobalFctDependOutput, ListOfString * listOfSourceFiles, ListOfString * listOfHeaderFiles,
                 DependencyList * GlobalDependencyListMultiFiles, 		ListOfString * TheListOfTransplantedMarkers);
#else
void GPAlgorithm(ListOfString * SkeletonSourceCode, char * GraftInterfaceTempOutput,
        char * sourceOutputCoreFunctionality, char * InterfaceCoreFunctionality, char * skeletonInterfaceSourceCodeOutput,
        ArrayOfStrings SkeletonLOCsArray, DependencyList * ListOfDependenciesForStatements,
        CallDependency * ListOfNeededFunctionsForAllLOCs, GlobalDeclarations ListOfFinalGlobalDeclarations,
        DependencyList * GlobalDependencyList, DependencyList * SkeletonDependenciesOnGlobals,
        char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile,
        char * GraftFunctionName, char * interfaceHeaderGlobalsAndGraftFunction, int TotalIDsInHostSymbolTable,
        MappingCandidate * MappingCandidatesForGP,
        DeclarationSymbolTable * GraftSymbolTablePossibleMatching, Mapping * CurrentDonorMappings,
        DependencyListWithID * dependencyListForAbstract, char * tempDefinesFile,
        char *tempIncludeLibFile, char * finalInterfaceForCompilation,
        SymbolTable * HostSymbolTable, char * GlobalFctDependOutput, char * listOfSourceFilesTargetPath, GlobalDeclarations ListOfFinalGlobalDeclarationsMultiFiles,
                 DependencyList * GlobalDependencyListMultiFiles);
#endif


ListOfInt * randomlySelectOneLOC(ArrayOfStrings SkeletonLOCsArray, ListOfInt * alreadySelectedLOCs);

double computeFitness(char * IndividualMakeFileTarget, int TotalIDsInHostSymbolTable, int MappedHostIDsInIndividual,
        int LOCsInCurrentIndividual, char * localTransplantResultLocation);

unsigned int randomIndexJKISSOperation(unsigned int max, ListOfInt * listOfExisting);

unsigned int randomIndexJKISSCrossoverSelector(unsigned int max, ListOfInt * listOfExisting);

unsigned int randomIndexJKISS(unsigned int max, ListOfInt * listOfExisting);

unsigned int randomIndexJKISSPopulationSelection(unsigned int max, ListOfInt * listOfExisting);

void organImplantation(char * graftSourceCodeFile);

void implantationOrgan(char * skeletonInterfaceSourceCodeOutput, char * listOfSourceFilesTargetPath,
                       char * listOfHeaderFilesTargetPath, char * graftSourceCodeFile);


#endif	/* GP_H */

