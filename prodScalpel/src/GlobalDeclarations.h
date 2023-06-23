/* 
 * File:   GlobalDeclarations.h
 * Author: ---
 *
 * Created on 04 July 2014, 18:18
 */

#ifndef GLOBALDECLARATIONS_H
#define	GLOBALDECLARATIONS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "ListOfString.h"
#include "DeclarationWthHeaderDefinition.h"
#include "DependencyList.h"
#include "FunctionCallDependency.h"

#define MULTIFILE_VAR_EXTRACTION
#define MAC_OSX


typedef struct listOfStatementToMirror ListOfStatementToMirror;



    struct listOfDefinedTypesAndVars {
        char * lineMarker;
        ListOfString * definedVar;
        ListOfString * definedTypes;
        char * declType;
        struct listOfDefinedTypesAndVars * next;
    };

typedef struct listOfDefinedTypesAndVars ListOfDefinedTypesAndVars;

    struct listOfDefinedTypesAndVarsDecl {
        char * lineMarker;
        char * definedTypes;
        ListOfString * definedVar;
        struct listOfDefinedTypesAndVarsDecl * next;
    };

typedef struct listOfDefinedTypesAndVarsDecl ListOfDefinedTypesAndVarsDecl;



#ifdef MULTIFILE_VAR_EXTRACTION
struct listOfStructDefinitions {
    ListOfString * structDef;
    char * headerDefinition;
    char * file;
    long int occurrenceLine;
    struct listOfStructDefinitions * next;
};
#else

struct listOfStructDefinitions {
    ListOfString * structDef;
    char * headerDefinition;
    struct listOfStructDefinitions * next;
};
#endif

    typedef struct listOfStructDefinitions ListOfStructDefinitions;

    struct globalDeclarations {
        ListOfStructDefinitions * normalDeclarations;
        ListOfStructDefinitions * structUnionDeclarations;
        ListOfStructDefinitions * typedefDeclarations;
    };


#ifdef MAC_OSX

struct listOfStructMark{
    char * oldStatment;
    char * newStatment;
    struct listOfStructMark * next;
};

typedef struct listOfStructMark ListOfStructMark;

struct globalDeclarationsMark {
    ListOfStructMark * normalDeclarations;
    ListOfStructMark * structUnionDeclarations;
    ListOfStructMark * typedefDeclarations;
};

typedef struct globalDeclarationsMark GlobalDeclarationsMark;



struct listOfGlobalForTransplant {
    char * marker;
    int visited;
    struct listOfGlobalForTransplant *next;
};

typedef struct listOfGlobalForTransplant ListOfGlobalForTransplant;

#endif

    typedef struct globalDeclarations GlobalDeclarations;

    GlobalDeclarations readGlobalDeclarationFromFile(char * inputFile);

    void insertFileNameIntoListOfFinalGlobalDeclarations( ListOfStructDefinitions * source, ListOfStructDefinitions * destination, char * inputFile);

    void addFileNameInListOfFinalGlobalDeclarations(char * directory, GlobalDeclarations * destination, char * inputFile);

    void addGlobalDeclarationListToExistingOneWithNewDefinitionID(GlobalDeclarations * head, GlobalDeclarations toBeAdded,
                                                              int  * newNormalDeclarationsID, int * newStructUnionDeclarationsID, int * newTypedefDeclarationsID, ListOfStructMark ** ListOfDeclarationMark  );

   /* GlobalDeclarations constructListOfGlobalDeclarations(DependencyList ** globalDependencyList,
            ListOfDefinedTypesAndVars ** globalListOfDefinedTypeVar, char * tempGlobalTypeVarDeclaration,
            char * tempDefinesFile, char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor,
            char * GlobalFctDependOutput, char * TXLTemporaryFolder);*/


    DependencyList * generateGlobalDependencyListForSkeleton(ListOfString * FinalSkeletonSourceCode,
            char * definedGlobalTypesAndVariablesFile, GlobalDeclarations ListOfFinalGlobalDeclarations,
            char * tempGlobalDeclarations, char * TXLTemporaryFolder);

    GlobalDeclarations fixGlobalDeclarationsForSkeleton(ListOfString * FinalSkeletonSourceCode,
            DependencyList ** GlobalDependencyList, DependencyList ** SkeletonDependenciesOnGlobals,
            char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile, char * tempDefinesFile,
            char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor, char * GlobalFctDependOutput,
			char * TXLTemporaryFolder);

/*LOS Only when run the tool on MACOSX*/
#ifdef MAC_OSX
    GlobalDeclarationsMark  createGlobalDeclarationsMark(GlobalDeclarations ListOfFinalGlobalDeclarations, GlobalDeclarations ListOfCurrentGlobalDeclarations);
   // void addNewDependencyListMarkFromExistingOne(DependencyList ** GlobalCurrentDependencyList, GlobalDeclarationsMark globalDeclarationsMark );
 //  void addNewDependencyListMarkFromExistingOne(DependencyList * NewListOfDependency, DependencyList * GlobalCurrentDependencyList, GlobalDeclarationsMark globalDeclarationsMark );
  //  void addNewDependencyListMarkFromExistingOne(DependencyList ** NewListOfDependency, DependencyList * GlobalCurrentDependencyList, GlobalDeclarationsMark globalDeclarationsMark );
  // void addNewDependencyListMarkFromExistingOne(DependencyList * NewListOfDependency, DependencyList * GlobalCurrentDependencyList, ListOfStructMark * listOfDeclarationMark);
    void addNewDependencyListMark(DependencyList ** NewListOfDependency, DependencyList * GlobalCurrentDependencyList, ListOfStructMark * listOfStructMark );
    void addNewListOfDependencies(ListOfStructMark ** head, char * newStatment,  char * oldStatment);
    void addStatementMark(ListOfStructMark ** listOfStructDefMark, ListOfStructDefinitions * finalGlobalDeclarations, ListOfStructDefinitions * currentGlobalDeclarations, char *mark);
    void addNewStatmentMark(ListOfStructMark ** head, char * currentDG, char * finalDG);
    void freeListOfGlobalDeclarationMak(ListOfStructMark ** head);

    void printListOfGlobalDeclarationsinDefsOutput(GlobalDeclarations ListOfDecl, char * outputFile);

    ListOfDefinedTypesAndVars * readListOfDefinedTypesAndVarsFromFile(char * inputFile);

    void addNewListOfDefinedTypesAndVars(ListOfDefinedTypesAndVars ** head, char * lineMarker,
                                     ListOfString * definedTypes, ListOfString * definedVars, char * currentTypeDef);
    char * returnNewMark(ListOfStructMark * listOfStructMark, char * oldMark);

    void printListOfGlobalListOfDefinedTypeVar(ListOfDefinedTypesAndVars * FinalGlobalListOfDefinedTypeVar, char * outputFile);

    void printListOfNeededFunctionsForGlobalDeclaration(CallDependency * FinalListOfNeededFunctionsForGlobals, char * outputFile);

    GlobalDeclarations extractGlobalDeclaration( char * AllDefinedFunctionsInDonor, char * definedGlobalTypesAndVariablesFile);

    GlobalDeclarations extractGlobalDeclarationFromHost(char * tempDirectory, char * finalDirectory, GlobalDeclarations ListOfFinalGlobalDeclarations,
                                                    char * listOfSourceHeaderFilePaph, char * tempSourceHeaderFilesTargetPath,
                                                    char * AllDefinedFunctionsInDonor);

  /*  DependencyList * extractGlobalDependenciesMultFile(GlobalDeclarations ListOfFinalGlobalDeclarations,
                                         char * tempSourceHeaderFilesTargetPath, char * tempGlobalTypeVarDeclaration, char * tempDefinesFile,
                                         char * AllDefinedFunctionsInDonor,
                                         char * GlobalFctDependOutput, char * TXLTemporaryMultiFileFolder);*/
#endif

    void addNewStructDefinition(ListOfStructDefinitions ** head, ListOfString * structLOCs,
            char * headerDefinition, char * file, long int line);

#if 0 /* MULTIFILES Using in mulitple header files*/

GlobalDeclarations fixGlobalDeclarationsForSkeletonMultiFiles(ListOfString * FinalSkeletonSourceCode,
                                                              DependencyList ** GlobalDependencyList, DependencyList ** SkeletonDependenciesOnGlobals,
                                                              char * tempGlobalDeclarations, char * tempDefinesFile,
                                                              char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor, char * GlobalFctDependOutput,
                                                              char * TXLTemporaryFolder, ListOfFunctionSourceFile * listOfFunctionSourceFileExtracted,
                                                              CallDependency * ListOfNeededFunctionsForAllLOCs, char * listOfSourceFilesTargetPath, DependencyList * GlobalDependencyListMultiFiles );
#endif

#if 1 /* MULTIFILES */
/*GlobalDeclarations fixGlobalDeclarationsForSkeletonInterface(ListOfString * FinalSkeletonSourceCode,
                                                              DependencyList ** GlobalDependencyList, DependencyList ** SkeletonDependenciesOnGlobals,
                                                              char * tempGlobalDeclarations, char * definedGlobalTypesAndVariablesFile, char * tempDefinesFile,
                                                              char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor, char * GlobalFctDependOutput,
                                                              char * TXLTemporaryFolder);*/

GlobalDeclarations fixGlobalDeclarationsForSkeletonMultiFiles(char * definedGlobalTypesAndVariablesFile, char * tempGlobalDefsOutput, char * tempDefinesFile,
                                                              char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor, char * GlobalFctDependOutput,
                                                              char * sourceFileTargetNames, char * TXLTemporaryFolder, char * tempGlobalDependencies);

GlobalDeclarations fixGlobalDeclarations(char * tempDir, char * sourceFile,
                                         char * AllDefinedFunctions, char * tempSourceHeaderFilesTargetPath,
                                         char * TXLTemporaryFolder);

GlobalDeclarations constructListOfGlobalDeclarations1(char * finalDirectory, ListOfDefinedTypesAndVars ** globalListOfDefinedTypeVar, char * tempGlobalDefsOutput, char * tempGlobalTypeVarDeclaration,
                                                      char * tempDefinesFile, char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor,
                                                      char * GlobalFctDependOutput, char * TXLTemporaryFolder, char * sourceFileTargetNames, char * TXLTemporaryMultiFileFolder, char * tempGlobalDependencies) ;

        GlobalDeclarations constructListOfGlobalDeclarationsMultiFiles( ListOfDefinedTypesAndVars **CurrentGlobalListOfDefinedTypeVar, CallDependency **ListOfNeededFunctionsForGlobals, char * tempGlobalDefsOutput, char * tempGlobalTypeVarDeclaration, char * tempDefinesFile, char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor,
                char * GlobalFctDependOutput, char * TXLTemporaryFolder,  char * sourceFileTargetNames, char * TXLTemporaryMultiFileFolder, char * tempGlobalDependencies);

    /*LOS extract definitions and includes */
    GlobalDeclarations constructListOfGlobalDeclarationsForSGD(DependencyList ** globalDependencyList,
                                                                char * AllDefinedFunctionsInDonor,
                                                                char * TXLTemporaryMultiFileFolder);


    void extractDefinitionsAndIncludes(ListOfString ** ListOfNeededLocalHeaderForInterface, char * currentSourceFile, char * sourceFileTargetNames, char * tempDefinesFile, char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor,
                                       char * GlobalFctDependOutput, char * TXLTemporaryMultiFileFolder);

    void extractDefinitionsToInterfaceHeader( char * currentSourceFile, char * sourceFileTargetNames, char * tempDefinesFile, char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor,
                                          char * GlobalFctDependOutput, char * TXLTemporaryMultiFileFolder);

    void insertNeededHeaderFileIncludeIntoInterfaceCFAndMainFile(ListOfString * ListOfNeededLocalHeaderForInterface);

#endif

    GlobalDeclarations returnMarkerGlobalDeclaration(GlobalDeclarations currentGlobal, ListOfString * markers);

    GlobalDeclarations extractNeededGlobalDeclarationsForSkeleton(ListOfString * SelectedMarkers,
            GlobalDeclarations ListOfFinalGlobalDeclarations,
            DependencyList * GlobalDependencyList, DependencyList * SkeletonDependenciesOnGlobals);

    void printListOfGlobalDeclarations(GlobalDeclarations ListOfDecl, char * outputFile, char * outputFileHeader);

    void printListOfGlobalDeclarationsForOrgan(GlobalDeclarations ListOfFinalGlobalDeclarations, GlobalDeclarations ListOfDecl, char * outputFile, char * outputFileHeader);

    void printListOfGlobalDeclarationsForSkeleton(GlobalDeclarations ListOfDecl, DependencyList * GlobalDependencyList,char * outputFile, char * outputFileHeader);

    void printListOfGlobalDeclarations2(GlobalDeclarations ListOfDecl, char * outputFile, char * outputFileHeader);

    void printAllListOfGlobalDeclarationsExtracted(GlobalDeclarations ListOfDecl, char * outputVarExtracted);

    void printListOfGlobalDeclarationsCoreFunction(GlobalDeclarations ListOfDecl, char * outputFile, char * outputFileHeader);

    void addNewListOfStructToAnExistingOne(ListOfStructDefinitions ** destination, ListOfStructDefinitions * source);

    void addGlobalDeclarationListToExistingOne(GlobalDeclarations * head, GlobalDeclarations toBeAdded);

    CallDependency * extractNeededFunctionsForGlobals(GlobalDeclarations ListOfGlobalDeclarations,
        char * GlobalsDependenciesOnFunctFileName);
    ListOfString * extractNeededFunctionsForDeclaration(char * GlobalsDependenciesOnFunctFileName);

// LOS
void compareGlobalVarListParwise( GlobalDeclarations ListOfFinalGlobalDeclarations, char * GlobalTypeAndVarDependencyListPairOnePath,
                                  char * GlobalTypeAndVarDependencyListPairTwoPath,
                                  char * GlobalDependenciesPath);

void extractAllLocalIncludesDefinitions(char * sourceAndHeaderFileNames, char * TXLProgsPath, char * tempIncludeLibFile,
                                        char * AllDefinedFunctionsInDonor);
//LOS DELETE IF IT IS NOT USED
DependencyList * extractGlobalDependenciesOrgan(GlobalDeclarations ListOfFinalGlobalDeclarations,
                                              char * tempSourceHeaderFilesTargetPath, char * tempGlobalTypeVarDeclaration, char * tempDefinesFile,
                                              char * tempIncludeLibFile, char * AllDefinedFunctionsInDonor,
                                              char * GlobalFctDependOutput, char * TXLTemporaryMultiFileFolder);


void callInterfaceGlobalDependencySolver(char * tempSkeletonFile, char * tempGlobalDeclarations, char * tempGlobalTypeVarDecl,
                                         char * TXLProgsPath, char * temporaryOutputFile);

void printListOfGlobalDeclarations1(int * newDeclarationImplanted, char * currentFile, char * TempImplantationDirectory, GlobalDeclarations ListOfDeclInHost, GlobalDeclarations ListOfDeclInOrgan, char * outputFileSource,
                                    char * outputFileHeader);
//TODO rewrite to be generic
void addFileNameInListOfFinalGlobalDeclarations1( GlobalDeclarations * destination, char * inputFile) ;

int searchForGlobal(GlobalDeclarations ListOfGlobalDeclarations, char * marker) ;

GlobalDeclarations readGlobalDeclarationFromFileWithFile(char * inputFile);


void insertFileNameIntoListOfFinalGlobalDeclarations1( ListOfStructDefinitions * head, char * inputFile) ;
void checkTypeDefDependency(DependencyList ** FinalGlobalDependencyList, GlobalDeclarations ListOfFinalGlobalDeclarations);

void checkDependecyFromDeclaration(DependencyList ** FinalGlobalDependencyList, GlobalDeclarations ListOfFinalGlobalDeclarations);

void checkStrucDependency(DependencyList ** FinalGlobalDependencyList, GlobalDeclarations ListOfFinalGlobalDeclarations);

void extractNeededGlobalDeclarationsForExtractedLOCsMultiFiles( CallDependency * ListOfNeededFunctionsForAllLOCs,
                                                      DependencyList * SkeletonDependenciesOnGlobals,
                                                      GlobalDeclarations ListOfFinalGlobalDeclarations,
                                                      DependencyList * FinalGlobalDependencyList,
                                                      char * tempGlobalDeclarations,
                                                      char * definedGlobalTypesAndVariablesFile,
                                                      ListOfString * candidateSourceCode,
                                                      ListOfString * TheListOfTransplantedMarkers,
                                                      char * outputFileGlobalDependenciesOnFunctions);


DependencyList * extractGlobalDependencies2(char * AllDefinedFunctionsInDonor, char * inputFilesPath );

DependencyList * extractGlobalDependenciesMultFile(GlobalDeclarations ListOfFinalGlobalDeclarations,
                                                   char * tempSourceHeaderFilesTargetPath, char * tempGlobalTypeVarDeclaration,
                                                   char * AllDefinedFunctionsInDonor,
                                                   char * TXLTemporaryMultiFileFolder);

ListOfString * getListOfHeaderDependency(char * sourceFile, char * outputFile, char *headerFilesTarget);
void extractNeededGlobalDeclarations(
        GlobalDeclarations ListOfFinalGlobalDeclarations,
        DependencyList * GlobalDependencyList,
        DependencyList * DependencyListGlobalCoreFunctions,
        ListOfString * ListOfSelectedFunctionNames,
        char * tempSourceCodeGlobalsContent);

void moveExtractedFunctionDeclarationMultiFile(char * tempAllSourceFilesTargetPath);

GlobalDeclarations extractNeededGlobalDeclaractionsForFunctions(GlobalDeclarations ListOfFinalGlobalDeclarations, char * GlobalFctDependOutput);
int removeGlobalDeclaration(ListOfStructDefinitions ** head, char * decl);
ListOfFunctionSourceFile * readAllFunctionSourceFileFromAllDefinitionInDonor( char * ListOfAllFunctionsSourceFileInDonor);
#ifdef	__cplusplus
}
#endif

#endif	/* GLOBALDECLARATIONS_H */

