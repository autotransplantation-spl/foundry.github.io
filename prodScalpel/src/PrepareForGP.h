/* 
 * File:   PrepareForGP.h
 * Author: ---
 *
 * Created on 30 June 2014, 04:06
 *
 * Added  exception message on 24 Octuber 2017, 2:12
 * ---
 */

#ifndef PREPAREFORGP_H
#define	PREPAREFORGP_H

#define EXCEPTION_MESSAGE

#ifdef	__cplusplus
extern "C" {
#endif

#include "Mapping.h"
#include "DependencyList.h"
#include "MappingCandidate.h"
#include "FunctionCallDependency.h"
#include "DeclarationSymbolTable.h"

struct arrayOfStrings {
    int count;
    char ** array;
};

typedef struct arrayOfStrings ArrayOfStrings;

void printArrayOfString(ArrayOfStrings initial, char * outputFile);

ListOfString * prepareForGP(Mapping ** ListOfMappingsFromCurrentDonor,
                            DependencyList ** ListOfDependenciesForStatements, MappingCandidate ** MappingCandidatesForGP,
                            CallDependency ** ListOfNeededFunctionsForAllLOCs, DeclarationSymbolTable ** FinalDeclSymbolTable,
                            char * skeletonInterfaceSourceCodeOutput, char * skeletonInterfaceHeaderFileOutput,
                            char * headerForInterfaceJustName, char * skeletonCoreFeatureHeader, char * hostWithInterfaceOutputFile,
                            char * interfaceOutput, char * sourceOutputCoreFunctionality, char * interfaceCoreFunctionalityCode, char * graftSourceCodeFile,
                            int * countOfHostIDs, SymbolTable ** finalHostSymbolTable, char * outputDefinedFunctions,
                            char * TXLTemporaryFolder, char * listOfSourceFilesTargetPath);

void createFinalHostInterface(char * interfaceFile, char * coreFeatureFile, char * TXLProgsPath,
                              char * finalTransplantLocation);

ArrayOfStrings createArrayOfLineMutationCandidates(ListOfString * SkeletonSourceCode,
                                                   ListOfString ** MarkersForLineWithAbstract, char * TXLTemporaryFolder);

ListOfString * createTheListOfAllMarkers(ListOfString * SkeletonSourceCode, char * TXLTemporaryFolder);

void solveDonorStaticFunctionDeclarationsUniqueNamesAndMarkersReplacement(char * donorSourceFiles, char * TXLTemporaryFolder);

void extractStmOrCompoundMarkers(char * Skeleton, char * outputFile, char * TXLProgsPath, char * outputFileAbstractMarkers);

ArrayOfStrings copyArrayOfStrings(ArrayOfStrings initial);

void generateUnitTests(char * testSuitesDirectory, char * skeletonInterfaceHeaderFileOutput, char * headerForInterfaceJustName,char * TXLTemporaryFolder);

void replaceHostWithInterfaceKeepingComments();
extern int xx;
void pruner_vein(char *outputFile);
#ifdef	__cplusplus
}
#endif

#endif	/* PREPAREFORGP_H */

