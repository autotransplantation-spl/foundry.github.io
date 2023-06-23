#include "MarkFunctionCall.h"
#include "GenTrans.h"
#include "folderContent.h"
#include "FunctionCallDependency.h"
#include "Utils.h"
#include "ListOfFunctionSourceFile.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createListOfDonorFunctions(char * TXLProgsPath, char * listOfSourceFiles, char * outputFile) {
    printListOfFunctionNameInADirectory(donorSourceFileFolder, listOfSourceFiles, 'c');
    printf("\t[TXL] Extract all defined functions name from donor\n");
    char * txlIfDefProg = (char *) malloc(100 * sizeof (char));
    sprintf(txlIfDefProg, "%sifdef.x", TXLProgsPath);

    char * commandTXL = (char *) malloc(5000 * sizeof (char));
    sprintf(commandTXL, "ulimit -s 65353 && %sExtractAllDefinedFunctionsName.x %s %s %s %s", TXLProgsPath, listOfSourceFiles, outputFile,
            txlIfDefProg, ConsoleStderrOutput);
    int status = system(commandTXL);
    if (status != 0) {
        printf("ERROR! ExtractAllDefinedFunctionsName");
        system("open ErrorFile.out");
        exit(1);
    }
#ifdef DEBUGING
    else
        printf("\t\t|>> temp_all_defined_functions_in_donor.out\n");
#endif
    free(txlIfDefProg);
    free(commandTXL);
}

void createListOfFileFunctions(char * directoryPah, char * TXLProgsPath, char * listOfSourceFiles, char * outputFile) {
    printListOfFunctionNameInADirectory(directoryPah, listOfSourceFiles, 'c');
    printf("\t[TXL] Extract all defined functions name from donor\n");
    char * txlIfDefProg = (char *) malloc(100 * sizeof (char));
    sprintf(txlIfDefProg, "%sifdef.x", TXLProgsPath);

    char * commandTXL = (char *) malloc(5000 * sizeof (char));
    sprintf(commandTXL, "ulimit -s 65353 && %sExtractAllDefinedFunctionsName.x %s %s %s %s", TXLProgsPath, listOfSourceFiles, outputFile,
            txlIfDefProg, ConsoleStderrOutput);
    int status = system(commandTXL);
    if (status != 0) {
        printf("ERROR! ExtractAllDefinedFunctionsName");
        system("open ErrorFile.out");
        exit(1);
    }

    /* Remove temp file from host directory*/
    removeSpecificTypeOfFileFromDirectory(directoryPah, "cNONExt");

#ifdef DEBUGING
        printf("\t\t|>> temp_all_defined_functions_in_donor.out\n");
#endif
    free(txlIfDefProg);
    free(commandTXL);
}




void addTheMarkingsToSkeleton(char * TXLProgsPath, char * skeletonFile, char * outputFile, char * existingFctFile) {
    char * commandTXL = (char *) malloc(5000 * sizeof (char));
    printf("\t\t[TXL] MarkFunctionCall.x >> Mark Function Call \n");
    sprintf(commandTXL, "%sMarkFunctionCall.x %s %s %s %s", TXLProgsPath, skeletonFile, outputFile, existingFctFile,
            ConsoleStderrOutput);
    int status = system(commandTXL);
    if (status != 0) {
        printf("ERROR! MarkFunctionCall.x\n");
        printf("\t%s\n", commandTXL);
        exit(1);
    }
#ifdef DEBUGING
    else
        printf("\t\t|>> temp_list_of_call_dependency.out\n");
#endif
    free(commandTXL);
}

CallDependency * markFunctionCallsInSkeleton(char * skeletonFileName, char * outputDefinedFunctions,
		char * TXLTemporaryFolder) {

    char * outputFileName = (char *) malloc(100 * sizeof (char));
    sprintf(outputFileName, "%stemp_list_of_call_dependency.out", TXLTemporaryFolder);

    char * outputListOfSourceFilesFromDonor = (char *) malloc(100 * sizeof (char));
    sprintf(outputListOfSourceFilesFromDonor, "%stemp_donor_files_for_function_list.out", TXLTemporaryFolder);

    createListOfDonorFunctions(TXLToolsPath, outputListOfSourceFilesFromDonor, outputDefinedFunctions);

    addTheMarkingsToSkeleton(TXLToolsPath, skeletonFileName, outputFileName, outputDefinedFunctions);
    CallDependency * ListOfCallDependencies = readCallDependencyFromFile(outputFileName);

    free(outputListOfSourceFilesFromDonor);
    free(outputFileName);

    return ListOfCallDependencies;
}

void constructFinalSkeletonJustWithNeededLOCs(char * skeletonFile, ListOfString * LinesToBeRemoved,
        char * FinalSkeletonOutput, char * TXLTemporaryFolder) {
    fflush(stdout);
    ListOfString * interfaceCode = NULL;
    interfaceCode = readListOfStringFromFile(skeletonFile);
    ListOfString * aux = copyCompleteListOfString(interfaceCode);
    while (aux->next) {
        ListOfString * auxLineToBeRemoved = LinesToBeRemoved;
        int signal = 0;
        fflush(stdout);//TODO LOSCHANGE23
        while (auxLineToBeRemoved && !signal) {
            fflush(stdout);
            if (strstr(aux->el, auxLineToBeRemoved->el)) {
                signal = 1;
            }
            auxLineToBeRemoved = auxLineToBeRemoved->next;
        }
        if (signal) {
            removeString(&interfaceCode, aux->el);
        }
        aux = aux->next;
    }
    //first write to a temp file, since it needs to be pretty printed before sending it further
    char * tempSkeleton;
    tempSkeleton = (char *) malloc(500 * sizeof (int));
    sprintf(tempSkeleton, "%stemp_skeleton_output_not_formatted.out", TXLTemporaryFolder);
    printAListOfStrings(interfaceCode, tempSkeleton);
#ifdef DEBUGING
    printf("\t\t|>> temp_skeleton_output_not_formatted.out\n");
#endif
    fflush(stdout);
    prettyPrintSourceCode(TXLToolsPath, tempSkeleton, FinalSkeletonOutput);
    fflush(stdout);
}

void removeLOCsWithUnwantedFunctions(char * skeletonFile, DependencyList * ListOfDependencies,
        CallDependency * ListOfFunctionCallDependencies, char * DesiredFunctionsFile, char * FinalSkeletonOutput,
		char * TXLTemporaryFolder) {
    ListOfString * userWantedFunction = NULL;
    userWantedFunction = readListOfStringFromFileAsWords(DesiredFunctionsFile);
    ListOfString * linesToBeRemoved = NULL;
    CallDependency * auxCallDep = ListOfFunctionCallDependencies;
    fflush(stdout);
    //remove statement, compound, and declarations that calls unwanted functions
    while (auxCallDep) {
        ListOfFunctionSourceFile * currentCalledFct = auxCallDep->calledFunctions;
        int signal = 1;
        while (currentCalledFct && signal) {
            if (exclude_functions) {
                if (searchStringInListOfStrings(userWantedFunction, currentCalledFct->functionName)) {
                    signal = 0;
                }
            }
            currentCalledFct = currentCalledFct->next;
        }
        if (!signal) {
            addNewString(&linesToBeRemoved, auxCallDep->LOCMarker);
        }
        auxCallDep = auxCallDep->next;
    }
    //remove statements, compound statements or declarations that are use removed declaration
    ListOfString * auxRemovedLocs = linesToBeRemoved;
    while (auxRemovedLocs) {
        DependencyList * auxListOfDependencies = ListOfDependencies;
        while (auxListOfDependencies) {
            if (searchStringInListOfStrings(auxListOfDependencies->ListOfDependencies, auxRemovedLocs->el)) {
                if (!searchStringInListOfStrings(linesToBeRemoved, auxListOfDependencies->Statement)) {
                    addNewString(&linesToBeRemoved, auxListOfDependencies->Statement);
                }
            }
            auxListOfDependencies = auxListOfDependencies->next;

        }
        auxRemovedLocs = auxRemovedLocs->next;
    }
    //TODO keep or not?
    /* Look for "goto LABEL_main;" to be removed from skeleton */
    ListOfString * interfaceCode = NULL;
    interfaceCode = readListOfStringFromFile(skeletonFile);
    while(interfaceCode){
        if(strstr(interfaceCode->el,"goto LABEL_main;"))
            addNewString(&linesToBeRemoved, interfaceCode->el);
        interfaceCode = interfaceCode->next;
    }

    printf("\t\tNLOCs to be removed: %d\n", countElementsInListOfString(linesToBeRemoved));
    constructFinalSkeletonJustWithNeededLOCs(skeletonFile, linesToBeRemoved, FinalSkeletonOutput, TXLTemporaryFolder);
    printf("\tConstructing final skeleton junst with needed LOCs\n");
}

CallDependency * removeUnwantedFunctionsAndReturnCallDependencies(char * SkeletonFile, char * FinalSkeletonOut,
        DependencyList * ListOfDependenciesForStatements, char * outputDefinedFunctions,
		char * TXLTemporaryFolder) {
    printf("[AUTOSCALPEL] Remove unwanted functions\n");
    CallDependency * finalCallDependencies = markFunctionCallsInSkeleton(SkeletonFile, outputDefinedFunctions,
    		TXLTemporaryFolder);

    //this are statements that use an unwanted function, declarations that use an unwanted
    //function, or statements that use a declaration that use an unwanted function

    fflush(stdout);
    printf("\tRemoving LOCs with unwanted functions\n");
    removeLOCsWithUnwantedFunctions(SkeletonFile, ListOfDependenciesForStatements, finalCallDependencies,
            AcceptedFunctionsForGP, FinalSkeletonOut, TXLTemporaryFolder);
    fflush(stdout);

    return finalCallDependencies;
}
