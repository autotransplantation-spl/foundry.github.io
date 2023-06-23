
/*
 * File:   main.c
 * Author: ---
 *
 * Created on 09 June 2014, 17:49
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GenTrans.h"
#include "reverseCallGraph.h"
#include "Utils.h"
#include "CallGraph.h"
#include "folderContent.h"
#include "ListOfFunctionSourceFile.h"
#include "ListOfFunctionForGraph.h"
#include "GlobalDeclarations.h"
#include <unistd.h>

#define END_PATH_MARK "END_PATH_MARK"
char TempVeinDirectory [250];

#if 1 // LOS Using doxygen

void dfsR(struct Graph* graph, int vertex);
//#include "reverseCallGraph.h"

char ** completeCallGraphs(char ** CallGraph, int n, int * newL) {
	char ** NewCallGraph = NULL;
	NewCallGraph = (char**) malloc(100000 * sizeof(char*));
	for (int i = 0; i < 100000; i++) {
		NewCallGraph[i] = (char*) malloc(4000 * sizeof(char));
	}
	int NoOfSpaces = 0;
	int k = 1;
	strcpy(NewCallGraph[0], CallGraph[0]);
	strcpy(NewCallGraph[k], "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	k = 2;
	int firstNoSpaces = 0;
	while (CallGraph[1][firstNoSpaces] == ' ') {
		firstNoSpaces++;
	}
	for (int i = 1; i < n; i++) {
		int count = 0;
		while (CallGraph[i][count] == ' ') {
			count++;
		}

		if (count > NoOfSpaces) {
			NoOfSpaces = count;
			strcpy(NewCallGraph[k], CallGraph[i]);
			k++;
		} else {
			//empty line for new graph
			strcpy(NewCallGraph[k], "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
			k++;
			int newPos = 1;
			int countForOldLines;
			countForOldLines = 0;
			int positionInNewGraph = 1;
			int tt = 1;
			while (tt < k) {
				int newCountSpaces = 0;
				while (NewCallGraph[tt][newCountSpaces] == ' ') {
					newCountSpaces++;
				}
				if (newCountSpaces == firstNoSpaces) {
					positionInNewGraph = tt;
				}
				tt++;
			}
			while (NewCallGraph[positionInNewGraph][countForOldLines] == ' ') {
				countForOldLines++;
			}
			newPos = positionInNewGraph;
			while (countForOldLines < count && newPos < k) {
				strcpy(NewCallGraph[k], NewCallGraph[newPos]);
				newPos++;
				countForOldLines = 0;
				while (NewCallGraph[newPos][countForOldLines] == ' ') {
					countForOldLines++;
				}
				k++;
			}
			NoOfSpaces = count;
			strcpy(NewCallGraph[k], CallGraph[i]);
			k++;

		}
	}
	*newL = k;
	return NewCallGraph;
}

void callCFlowReversed(char * donorSourceFiles, char * transplantWorkingFolder,
					   char * outputFileFullPath) {
	char * gcov = " cflow --reverse";
	char * restOfParams = "--brief -i _ --omit-arguments *.c >";
	//char * restOfParams = "-i _ --omit-arguments *.c >";

	char gcovCommand[400];
	sprintf(gcovCommand, "cd %s \n %s %s %s", donorSourceFiles, gcov,
			restOfParams, outputFileFullPath);

	char * copyFile = (char *) malloc(2000 * sizeof(char));
	sprintf(copyFile, "cp %s%s %s%s", donorSourceFiles, outputFileFullPath,
			TXLTemporaryFolderMainThread, outputFileFullPath);
	//printf("%s \n", gcovCommand);
	//int status2 = system(gcovCommand);
	//if (status2 != 0) {
//		printf("ERROR: CFLOW reverse call grath generation");
//	}
	system(copyFile);
}

#ifdef GENERATE_REVERSE_CALL_GRAPH
void transformReverseCallGraph(char * TXLPath, char * donorSourceFiles,
							   char * reversedCflowOutput, char * modifiedFunctionLOCsOutput,
							   char * SkeletonInstantiateMappings, char * HostSymbolTable,
							   char * CurrentExistingMappings, char * allCalledFunctionsList,
							   char * outputFileLabels) {
	char * command = (char *) malloc(100 * sizeof(char));
	sprintf(command, "%sreadReverseCallGraph.x", TXLPath);
	char * commandTXL = (char *) malloc(500 * sizeof(char));

	char * txlIfDefProg = NULL;
	txlIfDefProg = (char *) malloc(100 * sizeof(char));
	sprintf(txlIfDefProg, "%sifdef.x", TXLPath);

	printf("[TXL] ReadReverseCallGraph.x >> read reverse call graph\n");
	sprintf(commandTXL, "ulimit -s 65353 && %s %s %s %s %s %s %s %s %s %s %s", command,
			reversedCflowOutput, donorSourceFiles, modifiedFunctionLOCsOutput,
			SkeletonInstantiateMappings, HostSymbolTable,
			CurrentExistingMappings, txlIfDefProg, allCalledFunctionsList,
			outputFileLabels, ConsoleStderrOutput);

    fflush(stdout);
    /*LOSTEMP*/
    int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR read reverse call graph!\n");
		printf("\tCommand: %s\n", commandTXL);
		system("open ErrorFile.out");
		fflush(stdout);
		exit(1);
	}
    ///sleep(30);
	fflush(stdout);
	free(txlIfDefProg);
    fflush(stdout);
	free(commandTXL);
	free(command);
}
#endif

#ifdef VEIN_GLOBAL_EXTRACTION
/*
/*LOS Create main call function list with files used to extract global declaration to the vein*/
//TODO LOSIMPLEMENT reescrever este codigo organizado em algum modulo
void createTheVeinCallListOfFunctions(	ListOfFunctionSourceFile *listOfFunctionSourceFile){

	removeFunctionSourceFile(&listOfFunctionSourceFile, GraftFunctionName);
	ListOfFunctionSourceFile *auxListOfFunctionSourceFile = listOfFunctionSourceFile;
		/* Create temp directory */
    fflush(stdout);
	sprintf(TempVeinDirectory, "%sTempVeinDirectory/", transplantWorkFolderMainThread);
	isDirectory(TempVeinDirectory);

	/* Create list of files in vein */
	char * listOfFilesToVeinPath = (char *) malloc(500 * sizeof (char));
	sprintf(listOfFilesToVeinPath, "%stemp_list_vein_files.out", TempVeinDirectory);

	ListOfString * listOfFiles = NULL;
	while (auxListOfFunctionSourceFile) {
		char *currentFiles;
		currentFiles = (char *) malloc((strlen(auxListOfFunctionSourceFile->sourceFile) + 1) * sizeof(char));
		strcpy(currentFiles,auxListOfFunctionSourceFile->sourceFile);

		if (!searchStringInListOfStrings(listOfFiles, currentFiles)) {
			addNewString(&listOfFiles, currentFiles);
		}
		auxListOfFunctionSourceFile = auxListOfFunctionSourceFile->next;
		fflush(stdout);
	}
	printAListOfStringsNL(listOfFiles,listOfFilesToVeinPath);

	/* Create list of functions in vein */ //TODO LOSDELETE unecessary
	char * listOfFunctionVeinPath = (char *) malloc(500 * sizeof (char));
	sprintf(listOfFunctionVeinPath, "%stemp_list_vein_functions.out", TempVeinDirectory);

	auxListOfFunctionSourceFile = listOfFunctionSourceFile;

	ListOfString * listOfFunctions = NULL;
	while (auxListOfFunctionSourceFile) {
		char *currentFunction;
		currentFunction = (char *) malloc((strlen(auxListOfFunctionSourceFile->functionName) + 1) * sizeof(char));
		strcpy(currentFunction,auxListOfFunctionSourceFile->functionName);
		addNewString(&listOfFunctions,currentFunction);

		auxListOfFunctionSourceFile = auxListOfFunctionSourceFile->next;
		fflush(stdout);
	}
	printAListOfStringsNL(listOfFunctions,listOfFunctionVeinPath);

	/* Create list of functions files in vein */
	char * listOfVeinFunctionsFilesPath = (char *) malloc(500 * sizeof (char));
	sprintf(listOfVeinFunctionsFilesPath, "%stemp_list_vein_function_files.out", TempVeinDirectory);

    char * sourceFunctionFilesExtracted;
    sourceFunctionFilesExtracted = (char *) malloc(500 * sizeof (char));
    sprintf(sourceFunctionFilesExtracted, "%slist_of_functions_file_target.out", TXLTemporaryMultiFileFolder);

    ListOfString * ListOfFunctionFilesExtracted = readListOfStringFromFile(sourceFunctionFilesExtracted);

	auxListOfFunctionSourceFile = listOfFunctionSourceFile;

	ListOfString * listOfFunctionsFilesInVein = NULL;
	while (auxListOfFunctionSourceFile) {
		char *formattedFilePath;
		formattedFilePath = (char *) malloc((strlen(auxListOfFunctionSourceFile->functionName) + strlen(tempDonorSourceFileFolder)  + strlen(auxListOfFunctionSourceFile->sourceFile) + 10) * sizeof(char));
		sprintf(formattedFilePath, "\"%s\" \"%s%s\"", auxListOfFunctionSourceFile->functionName, tempDonorSourceFileFolder,auxListOfFunctionSourceFile->sourceFile);

        if(!searchStringInListOfStrings(ListOfFunctionFilesExtracted, formattedFilePath)) {
            addNewString(&listOfFunctionsFilesInVein, formattedFilePath);
        }

		auxListOfFunctionSourceFile = auxListOfFunctionSourceFile->next;
		fflush(stdout);
	}
	printAListOfStringsNL(listOfFunctionsFilesInVein,listOfVeinFunctionsFilesPath);

}


/*
/*LOS Create main call function list with files used to extract global declaration to the vein*/
//TODO LOSIMPLEMENT reescrever este codigo organizado em algum modulo
void createTheVeinCallListOfFunctions1(	ListOfFunctionSourceFile *listOfFunctionSourceFile){

	//removeFunctionForGraph(&listOfFunctionSourceFile, GraftFunctionName);
	ListOfFunctionSourceFile *auxListOfFunctionSourceFile = listOfFunctionSourceFile;
	/* Create temp directory */
	sprintf(TempVeinDirectory, "%sTempVeinDirectory/", transplantWorkFolderMainThread);
	isDirectory(TempVeinDirectory);

	/* Create list of files in vein */
	char * listOfFilesToVeinPath;
	listOfFilesToVeinPath = (char *) malloc(500 * sizeof (char));
	sprintf(listOfFilesToVeinPath, "%stemp_list_vein_files.out", TempVeinDirectory);

	ListOfString * listOfFiles = NULL;
	while (auxListOfFunctionSourceFile) {
		char *currentFiles;
		currentFiles = (char *) malloc((strlen(auxListOfFunctionSourceFile->sourceFile) + 1) * sizeof(char));
		strcpy(currentFiles,auxListOfFunctionSourceFile->sourceFile);

		if (!searchStringInListOfStrings(listOfFiles, currentFiles)) {
			addNewString(&listOfFiles, currentFiles);
		}
		auxListOfFunctionSourceFile = auxListOfFunctionSourceFile->next;
		fflush(stdout);
	}
	printAListOfStringsNL(listOfFiles,listOfFilesToVeinPath);

	/* Create list of functions in vein */ //TODO LOSDELETE unecessary
	char * listOfFunctionVeinPath;
	listOfFunctionVeinPath = (char *) malloc(500 * sizeof (char));
	sprintf(listOfFunctionVeinPath, "%stemp_list_vein_functions.out", TempVeinDirectory);

	auxListOfFunctionSourceFile = listOfFunctionSourceFile;

	ListOfString * listOfFunctions = NULL;
	while (auxListOfFunctionSourceFile) {
		char *currentFunction;
		currentFunction = (char *) malloc((strlen(auxListOfFunctionSourceFile->functionName) + 1) * sizeof(char));
		strcpy(currentFunction,auxListOfFunctionSourceFile->functionName);
		addNewString(&listOfFunctions,currentFunction);

		auxListOfFunctionSourceFile = auxListOfFunctionSourceFile->next;
		fflush(stdout);
	}
	printAListOfStringsNL(listOfFunctions,listOfFunctionVeinPath);


	/* Create list of functions files in vein */
	char * listOfVeinFunctionsFilesPath;
	listOfVeinFunctionsFilesPath = (char *) malloc(500 * sizeof (char));
	sprintf(listOfVeinFunctionsFilesPath, "%stemp_list_vein_function_files.out", TempVeinDirectory);

	auxListOfFunctionSourceFile = listOfFunctionSourceFile;

	ListOfString * listOfFunctionsFiles = NULL;
	while (auxListOfFunctionSourceFile) {
		char *formattedFilePath;
		formattedFilePath = (char *) malloc((strlen(auxListOfFunctionSourceFile->functionName) + strlen(tempDonorSourceFileFolder)  + strlen(auxListOfFunctionSourceFile->sourceFile) + 10) * sizeof(char));
		sprintf(formattedFilePath, "\"%s\" \"%s%s\"", auxListOfFunctionSourceFile->functionName, tempDonorSourceFileFolder,auxListOfFunctionSourceFile->sourceFile);
		addNewString(&listOfFunctionsFiles,formattedFilePath);

		auxListOfFunctionSourceFile = auxListOfFunctionSourceFile->next;
		fflush(stdout);
	}
	printAListOfStringsNL(listOfFunctionsFiles,listOfVeinFunctionsFilesPath);

}
#endif

void printOutputCallFile(char * resultFileFullPath, ListOfFunctionForGraph * listOfFunctionSourceFile){
    ListOfFunctionForGraph * auxlistOfFunctionSourceFile = listOfFunctionSourceFile;

    /* Get list of target files forward from core function */
#ifdef VEIN_GLOBAL_EXTRACTION
    char * sourceFileTargetNames;
    sourceFileTargetNames = (char *) malloc(500 * sizeof (char));
    sprintf(sourceFileTargetNames, "%ssourceContentFilesTarget.out", TXLTemporaryFolderMainThread);

    ListOfString * ListOfSourceFilesTarget = readListOfStringFromFile(sourceFileTargetNames);
    ListOfString * ListOfFilesFormatted = NULL;
#endif

    int coreFunctionFound = 0;
    long int countFunctions = 0;
    long int countFiles = 0;
    char * formattedCurrentFile;
    formattedCurrentFile = (char *) malloc(500 * sizeof(char));
    ListOfFunctionSourceFile * ListOfCalledFunctionsFiles = NULL;
    ListOfString * ListOfFiles = NULL;
    ListOfString * ListOfTargetFiles = NULL;

    FILE *fout = fopen(resultFileFullPath, "w");

    while(auxlistOfFunctionSourceFile && !coreFunctionFound){
       // sprintf(formattedCurrentFunction, "\"%s\" \"%s%s\"\n", auxlistOfFunctionSourceFile->functionName, donorSourceFileFolder, auxlistOfFunctionSourceFile->sourceFile);
        sprintf(formattedCurrentFile, "@@%s@@ ", auxlistOfFunctionSourceFile->sourceFile);
        addNewFunctionSourceFile(&ListOfCalledFunctionsFiles, auxlistOfFunctionSourceFile->functionName,formattedCurrentFile );

        if (!strcmp(auxlistOfFunctionSourceFile->functionName, GraftFunctionName))
            coreFunctionFound = 1;

        if(!searchOccurrenceOfStringInListOfStrings(ListOfFiles,formattedCurrentFile)){
            addNewString(&ListOfFiles, formattedCurrentFile);
            /* Get list of target files forward from core function */
            if(!searchOccurrenceOfStringInListOfStrings(ListOfTargetFiles,auxlistOfFunctionSourceFile->sourceFile)){
                addNewString(&ListOfTargetFiles, auxlistOfFunctionSourceFile->sourceFile);
#ifdef VEIN_GLOBAL_EXTRACTION
                sprintf(formattedCurrentFile, "\"%s%s\"\n", donorSourceFileFolder, auxlistOfFunctionSourceFile->sourceFile);
                if(!searchOccurrenceOfStringInListOfStrings(ListOfSourceFilesTarget,formattedCurrentFile)){
                    strtok(formattedCurrentFile, "\n");
                    addNewString(&ListOfFilesFormatted,  formattedCurrentFile);
                }
#endif
            }
            countFiles++;
        }
        printf("\tFunction [%d]: %s << %s\n",countFunctions+1,auxlistOfFunctionSourceFile->functionName, auxlistOfFunctionSourceFile->sourceFile);
        countFunctions++;
        auxlistOfFunctionSourceFile = auxlistOfFunctionSourceFile->next;
        fflush(stdout);
    }


    while(ListOfFiles) {
        fprintf(fout, "%s", ListOfFiles->el);
        ListOfFiles = ListOfFiles->next;
    }

    fprintf(fout, "\n______________________________\n\n");
    fprintf(fout, "^^%s^^ %s\n", ListOfCalledFunctionsFiles->functionName, ListOfCalledFunctionsFiles->sourceFile);
    while(ListOfCalledFunctionsFiles) {
        fprintf(fout, "%s source_file: %s\n", ListOfCalledFunctionsFiles->functionName, ListOfCalledFunctionsFiles->sourceFile);
        ListOfCalledFunctionsFiles = ListOfCalledFunctionsFiles->next;
    }
    fprintf(fout, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    fclose(fout);

    freeListOfFunctionSourceFile(&ListOfCalledFunctionsFiles);
    freeListOfStrings(&ListOfFiles);
    freeListOfStrings(&ListOfTargetFiles);
    free(formattedCurrentFile);

#ifdef VEIN_GLOBAL_EXTRACTION
    addAListOfStringsInTheEndOfFileLN(ListOfFilesFormatted,  sourceFileTargetNames);
    free(sourceFileTargetNames);
    freeListOfStrings(&ListOfSourceFilesTarget);
    freeListOfStrings(&ListOfFilesFormatted);
#endif

}
void generateCalledFunctionsListWithCFLOW( char * allFuncFileInHost, char * graftMethod, char * donorSourceFiles, char * resultFileFullPath) {

    char *gcovMainMethodMarker = "--brief --main";
    char gcovMainMethod[400];
    sprintf(gcovMainMethod, "%s %s", gcovMainMethodMarker, graftMethod);
    char *outputFile = "outputCFLOWCalledFunctions.out";
    char *gcov = " cflow";
    char *restOfParams = "-i _ --omit-arguments *.c >";
    char *command;
    command = (char *) malloc(2000 * sizeof(char *));
    char gcovCommand[1000];
    char outputFileFullPath[1000];
    sprintf(outputFileFullPath, "%s%s", donorSourceFiles, outputFile);
    sprintf(gcovCommand, "cd %s \n %s %s %s %s", donorSourceFiles, gcov,
            gcovMainMethod, restOfParams, outputFile);
    fflush(stdout);
    int status1 = system(gcovCommand);
    if (status1 != 0) {
        printf("ERROR");
    }

    char **listOfFiles = NULL;
    listOfFiles = (char **) malloc(60000 * sizeof(char *));
    for (int i = 0; i < 59999; i++) {
        listOfFiles[i] = (char *) malloc(400 * sizeof(char));
    }
    char *currentFct;
    currentFct = (char *) malloc(400 * sizeof(char));
    char *line;
    line = (char *) malloc(400 * sizeof(char));
    FILE *fin = fopen(outputFileFullPath, "r");
    int n = 0;

    char *line2;
    char *line3;
    line2 = (char *) malloc(4000 * sizeof(char));
    line3 = (char *) malloc(4000 * sizeof(char));


    char **listOfSourceFiles = NULL;
    listOfSourceFiles = (char **) malloc(60000 * sizeof(char *));
    for (int i = 0; i < 59999; i++) {
        listOfSourceFiles[i] = (char *) malloc(400 * sizeof(char));
    }
    //char listOfSourceFiles[3000][200];
    int countFiles = 0;

    //char listOfCalledFunctions[3000][200];
    char **listOfCalledFunctions = NULL;
    listOfCalledFunctions = (char **) malloc(60000 * sizeof(char *));
    for (int i = 0; i < 59999; i++) {
        listOfCalledFunctions[i] = (char *) malloc(400 * sizeof(char));
    }

    int coreFunctionFound = 0;

    int shouldAddFunction = 1;
    int currentUnnededFunctionSpaceLength = 0;

    ListOfFunctionSourceFile *ListOfFuncFiles = NULL;
    while (fgets(line, 400, fin) != NULL && !coreFunctionFound) {
        int currentSpaceLength = 0;
        char *tempLine = (char *) malloc((strlen(line) + 5) * sizeof(char));
        strcpy(tempLine, line);
        int countSpaces = 0;
        while (tempLine[countSpaces] == ' ') {
            currentSpaceLength++;
            countSpaces++;
        }

        sscanf(line, "%s", currentFct);
        if (currentFct[strlen(currentFct) - 1] == ':') {
            currentFct[strlen(currentFct) - 3] = 0;
        } else {
            currentFct[strlen(currentFct) - 2] = 0;
        }

        char *formattedCurrentFunction;
        formattedCurrentFunction = (char *) malloc(500 * sizeof(char));

        char *searchedStringFirst;
        searchedStringFirst = (char *) malloc(4000 * sizeof(char));
        strcpy(searchedStringFirst, " at ");
        line3 = strstr(line, searchedStringFirst);
        if (line3) {
            line3 = line3 + 4;
            strcpy(line2, "");

            int posForLocationFirst = 0;
            while (line3[posForLocationFirst] != ':') {
                line2[posForLocationFirst] = line3[posForLocationFirst];
                posForLocationFirst++;
            }
            line2[posForLocationFirst] = 0;

            if (!searchStringInListOfStrings(ListOfCoreFunctions, currentFct)) {
                if (shouldAddFunction) {

                    sprintf(formattedCurrentFunction, "\"%s\" \"%s%s\"\n",
                            currentFct, donorSourceFiles, line2);
                    sprintf(listOfSourceFiles[countFiles], "@@%s@@ ", line2);
                    sprintf(listOfCalledFunctions[countFiles], "%s",
                            currentFct);
                    addNewFunctionSourceFile(&ListOfFuncFiles, currentFct, line2);
                    countFiles++;
                } else {
                    if (currentSpaceLength
                        <= currentUnnededFunctionSpaceLength) {
                        shouldAddFunction = 1;
                        sprintf(formattedCurrentFunction, "\"%s\" \"%s%s\"\n",
                                currentFct, donorSourceFiles, line2);
                        sprintf(listOfSourceFiles[countFiles], "@@%s@@ ",
                                line2);
                        sprintf(listOfCalledFunctions[countFiles], "%s",
                                currentFct);
                        addNewFunctionSourceFile(&ListOfFuncFiles, currentFct, line2);
                        countFiles++;
                    }
                }
            } else {
                if (shouldAddFunction) {
                    shouldAddFunction = 0;
                    currentUnnededFunctionSpaceLength = currentSpaceLength;
                }
            }
            if (!strcmp(currentFct, GraftFunctionName)) {
                coreFunctionFound = 1;
            }

        } else {
            sprintf(formattedCurrentFunction, "\"%s\" \"NOT_INTERNAL\"\n",
                    currentFct);
        }

        if (!isInListOfNeededFiles(listOfFiles, n, formattedCurrentFunction)) {
            strcpy(listOfFiles[n], formattedCurrentFunction);
            n++;
        }
    }
    ListOfFunctionSourceFile *allFunctionSourceFileInHost = readAllFunctionSourceFileFromAllDefinitionInDonor(
            allFuncFileInHost);
    ListOfFunctionSourceFile * auxListOfFuncFiles = ListOfFuncFiles;
#ifdef REDUCED_VEIN
    ListOfFunctionSourceFile *reducedListOfFuncFiles = NULL;
    while (auxListOfFuncFiles) {
     //   if(!searchFunctionInListOfFunctionsSourceFile(allFunctionSourceFileInHost, auxListOfFuncFiles->functionName)
       // && !strcmp(auxListOfFuncFiles->functionName, "main"))
            addNewFunctionSourceFile(&reducedListOfFuncFiles, auxListOfFuncFiles->functionName,auxListOfFuncFiles->sourceFile);

            auxListOfFuncFiles = auxListOfFuncFiles->next;
    }

#endif


#ifdef REDUCED_VEIN
    auxListOfFuncFiles = reducedListOfFuncFiles;
#else
    auxListOfFuncFiles = ListOfFuncFiles;
#endif

    char *formattedFileName = (char *) malloc(1000 * sizeof(char *));
    FILE *fout = fopen(resultFileFullPath, "w");
    while(auxListOfFuncFiles){
        sprintf(formattedFileName, "@@%s@@ ", auxListOfFuncFiles->sourceFile);
        fprintf(fout, "%s", formattedFileName);

        auxListOfFuncFiles = auxListOfFuncFiles->next;
    }
   /* for (int i = 0; i < countFiles-1; i++) {
        fprintf(fout, "%s", listOfSourceFiles[i]);
    }*/
    fprintf(fout, "\n______________________________\n\n");
    auxListOfFuncFiles = ListOfFuncFiles;
    fprintf(fout, "^^%s^^ @@%s@@\n", auxListOfFuncFiles->functionName,
            auxListOfFuncFiles->sourceFile);

  /*  fprintf(fout, "^^%s^^ %s\n", listOfCalledFunctions[0],
            listOfSourceFiles[0]);*/

#ifdef REDUCED_VEIN
    auxListOfFuncFiles = reducedListOfFuncFiles;
#else
    auxListOfFuncFiles = ListOfFuncFiles;
#endif
    while(auxListOfFuncFiles->next){
        sprintf(formattedFileName, "@@%s@@ ", auxListOfFuncFiles->sourceFile);
        fprintf(fout, "%s source_file: %s\n", auxListOfFuncFiles->functionName, formattedFileName);
        auxListOfFuncFiles = auxListOfFuncFiles->next;
    }

   /* for (int i = 0; i < countFiles-1; i++) {
        fprintf(fout, "%s source_file: %s\n", listOfCalledFunctions[i],
                listOfSourceFiles[i]);
    }*/

    fprintf(fout, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");

    fclose(fout);


}

#if 0 //TODO LOS DELETE
ListOfFunctionSourceFile * generateCalledFunctionsList(char * tempFolder, char * donorSourceFiles, char * currentCoreTransplantFunction,
								 char * resultFileFullPath) {

    /* Get list of target files forward from core function */
    char **listOfFilesExtracted = NULL;
    listOfFilesExtracted = (char**) malloc(30000 * sizeof(char*));
    for (int i = 0; i < 29999; i++) {
        listOfFilesExtracted[i] = (char*) malloc(400 * sizeof(char));
    }

    /* Read temp_list_of_source_files_extracted */
	char * sourceFilesExtracted;
	sourceFilesExtracted = (char *) malloc(500 * sizeof (char));
	sprintf(sourceFilesExtracted, "%stemp_list_of_source_files_extracted.out", TXLTemporaryMultiFileFolder);
	ListOfString *listOfTargetFilesPath = readListOfStringFromFile(sourceFilesExtracted);

    // Extract call graph with all call from  mainFunctiontarget (can be the main function or initial function) to corefunction
	ListOfFunctionForGraph *listOfFunctionSourceFile = readACallGraphAsList(donorEntryFunction);

/*#ifdef VEIN_GLOBAL_EXTRACTION
	 /*LOS Create main call function list used to extract global declaration to the vein
	createTheVeinCallListOfFunctions(listOfFunctionSourceFile);
#endif*/

	//writeCalleGraph(listOfFunctionSourceFile, TempDoxygenCallGraphDir, "main");

	/* print govParsedResultsCalledFunctions.out */
    printOutputCallFile(resultFileFullPath, listOfFunctionSourceFile);

    /* Copy functionSourceFile as graph to list */
    ListOfFunctionForGraph * auxlistOfFunctionSourceFile = listOfFunctionSourceFile;
	ListOfFunctionSourceFile *  ListOfFunctionSourceFile = NULL;
	while(auxlistOfFunctionSourceFile) {
		addNewFunctionSourceFile(&ListOfFunctionSourceFile, auxlistOfFunctionSourceFile->functionName, auxlistOfFunctionSourceFile->sourceFile);
		auxlistOfFunctionSourceFile = auxlistOfFunctionSourceFile->next;
	}
	/* List for vein */
	return ListOfFunctionSourceFile;
}

#endif
/* Print reverse call at temp_output_reversed_CFLOW.out*/


FILE *fout = NULL;
char **tempListOfFunctionSourceFile = NULL;
char **tempListOfFunction = NULL;
char ** fileLocations = NULL;
ListOfString * ListOfFileFunction = NULL;
long int m = 0;
long int nFunctions = 0;

void printOutputReverseFile(char * outputFile, ListOfFunctionForGraph * ListOfFuncitonSourceFilePath){
    printf("\tPrinting output reverse file: temp_output_reversed.out\n");
    ListOfFunctionForGraph * auxListOfFuncitonSourceFilePath = ListOfFuncitonSourceFilePath;
    ListOfString * ListOfFiles = NULL;
    FILE * fout = fopen(outputFile, "w");
    while(auxListOfFuncitonSourceFilePath!=NULL){
        char * currentFile = NULL;
        currentFile = (char *) malloc((strlen(ListOfFuncitonSourceFilePath->sourceFile) + 1) * sizeof (char));
        strcpy(currentFile,auxListOfFuncitonSourceFilePath->sourceFile );
        if (!searchStringInListOfStrings(ListOfFiles, currentFile)) {
            fprintf(fout, "@@%s@@ ", currentFile);
            addNewString(&ListOfFiles, currentFile);
        }
        free(currentFile);
        fflush(stdout);

        auxListOfFuncitonSourceFilePath = auxListOfFuncitonSourceFilePath->next;
    }
    auxListOfFuncitonSourceFilePath = ListOfFuncitonSourceFilePath;
    fprintf(fout, "%s", "\n");
    fprintf(fout, "%s", "______________________________\n\n");
    fprintf(fout, "^^%s^^ @@%s@@\n", auxListOfFuncitonSourceFilePath->functionName, auxListOfFuncitonSourceFilePath->sourceFile);

    auxListOfFuncitonSourceFilePath = auxListOfFuncitonSourceFilePath->next;
    while(auxListOfFuncitonSourceFilePath!=NULL){
        fprintf(fout, "%s source_file: @@%s@@\n", auxListOfFuncitonSourceFilePath->functionName, auxListOfFuncitonSourceFilePath->sourceFile);
        auxListOfFuncitonSourceFilePath = auxListOfFuncitonSourceFilePath->next;
    }
    fprintf(fout, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    fclose(fout);
}


int graphPathMemory [7000];
int maxNode = 0;
int numberOfVeins = 0;
#if 0 //TODO LOS DELETE
void readReverseGraph2(struct Graph* graph, int vertex, int countSpace, ListOfFunctionForGraph *listFunctions, int maxSpace, int n) {
    struct node *adjList = graph->adjLists[vertex];
    struct node *temp = adjList;

    graph->visited[vertex] = 0;

    int recursiveCall = 0;
    for (int i = 1; i < n; i++) {
        if (vertex == graphPathMemory[i]) {
            recursiveCall = 1;
        }
    }

    if (recursiveCall != 1){
        graphPathMemory[n] = vertex;
        if (n > maxNode)
            maxNode = n;
    }


    while(temp != NULL ) {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0) {

            if(recursiveCall!=1)
                readReverseGraph2(graph, connectedVertex, countSpace + 1, listFunctions, maxSpace,n+1);
            //graph->visited[connectedVertex] = 1;
        }


        if(temp != NULL || vertex == 1 ){
            ListOfFunctionForGraph *lastNode = searchNodeReferenceFromId(listFunctions, graphPathMemory[maxNode] );
            //TODO fix it to insert any last function
            //if(!strcmp(lastNode->functionName,"call_vim_function" )) {
            //if(!strcmp(lastNode->functionName,"ex_vmain" )) {
            if(!strcmp(lastNode->functionName,"main" )) {
                for (int i = maxNode; i > 0; i--) {
                    int currentId = graphPathMemory[i];

                    ListOfFunctionForGraph *currentNode = searchNodeReferenceFromId(listFunctions, currentId);

                    char *formattedCurrentSourceFile;
                    formattedCurrentSourceFile = (char *) malloc(10000 * sizeof(char));
                    char *spaces = (char *) malloc(600 * sizeof(char));
                    char *space = "    ";

                    /*for (int j = i; j > 0; j--)
                        strcat(spaces, space);*/

                    char * formattedNeedSourceFileLocations = NULL;
                    formattedNeedSourceFileLocations = (char *) malloc(500 * sizeof(char));
                    sprintf(formattedNeedSourceFileLocations, "@@%s@@ ", currentNode->sourceFile);
                    /*if (!isInListOfNeededFiles(fileLocations, m, formattedNeedSourceFileLocations)) {
                        fflush(stdout);
                        strcpy(fileLocations[m], formattedNeedSourceFileLocations);
                        m++;
                    }*/

                    if (!searchStringInListOfStrings(ListOfFileFunction,formattedNeedSourceFileLocations)) {
                        fflush(stdout);
                        addNewString(&ListOfFileFunction, formattedNeedSourceFileLocations);
                    }

                    sprintf(formattedCurrentSourceFile, "%s%s source_file: @@%s@@ \n", spaces, currentNode->functionName, currentNode->sourceFile);
                    // sprintf(formattedCurrentSourceFile, "%s source_file: @@%s@@ \n", currentNode->functionName, currentNode->sourceFile);
                    printf("%s", formattedCurrentSourceFile);
                    //printf("\t%s\n", currentNode->functionName);
                    //  fprintf(fout, "%s%s", spaces,formattedCurrentSourceFile);

                    // fprintf(fout, "%s", formattedCurrentSourceFile);
                    strcpy(tempListOfFunctionSourceFile[nFunctions], formattedCurrentSourceFile);
                    strcpy(tempListOfFunction[nFunctions], currentNode->functionName);
                    //printf(": %s\n", tempListOfFunctionSourceFile[nFunctions]);
                    nFunctions++;
                    fflush(stdout);
                    //free(formattedCurrentSourceFile);
                    //free(spaces);
                    if(i==1)
                        strcpy(tempListOfFunctionSourceFile[nFunctions], "OK");
                }

                printf("@@@@@@@@@@@@@@@@[%d]@@@@@@@@@@@@@@\n", numberOfVeins);
                numberOfVeins ++;
                maxNode = n;
                if (vertex == 1)
                    temp = NULL;
            }
            else
            if(numberOfVeins > 0)
                return;

        }
        if(temp==NULL)
            return;
        else
            temp = temp->next;


    }

}
#endif

ListOfFunctionForGraph * searchVeinPath(struct Graph *graph, ListOfFunctionForGraph * ListOfFuncitonSourceFile){

    Stack * path = searchPath(graph, ListOfFuncitonSourceFile);
    ListOfFunctionForGraph * ListOfFunctionSourceFilePath = readPath(path, ListOfFuncitonSourceFile);

    return ListOfFunctionSourceFilePath;
}

ListOfFunctionForGraph * gererateReversePathFromCoreFunctionCalledGraph(ListOfFunctionSourceFile * AllDefinedFunctionsInDonorPath,
        char * currentCoreTransplantFunction, char * outputFile) {
    ListOfFunctionForGraph *ListOfFunctionSourceFilePath = NULL;
    struct Graph *graph = NULL;

    ListOfFunctionForGraph *ListOfFuncitonSourceFile = readACallerGraphAsList(currentCoreTransplantFunction);
    graph = readACallerGraph(ListOfFuncitonSourceFile, currentCoreTransplantFunction);
    ListOfFunctionSourceFilePath = searchVeinPath(graph, ListOfFuncitonSourceFile);
/*#ifdef REDUCED_VEIN
    while(AllDefinedFunctionsInDonorPath){
        if(strcmp(ListOfFunctionSourceFilePath->functionName, AllDefinedFunctionsInDonorPath->functionName)){
            removeFunctionForGraph(ListOfFunctionSourceFilePath,ListOfFunctionSourceFilePath->functionName);
        }
            AllDefinedFunctionsInDonorPath = AllDefinedFunctionsInDonorPath->next;
    }
#endif*/
    printOutputReverseFile(outputFile, ListOfFuncitonSourceFile);

    freeListOfFunctionForGraph(&ListOfFuncitonSourceFile);

    return ListOfFunctionSourceFilePath;
}

void generateReverseCallGraph(char * AllDefinedFunctionsInDonorPath, char * TXLPath, char * reversedCflowOutput,
							  char * SkeletonInstantiateMappings, char * HostSymbolTable,
							  char * CurrentExistingMappings, char * temporaryFolder,
							  char * currentCoreTransplantFunction,
							  ListOfString ** ListOfReverseCallGraph, char * outputFileLabels) {

    ListOfFunctionSourceFile * AllFunctionSourceFileInDonor = NULL;
    AllFunctionSourceFileInDonor = readAllFunctionSourceFileFromAllDefinitionInDonor(AllDefinedFunctionsInDonorPath);

    printf("\tGetting the path from donor entry to organ entry point\n");
    char * resultFileFullPath = (char *) malloc(100 * sizeof(char));
	sprintf(resultFileFullPath, "%sgcovParsedResultsCalledFunctions.out", temporaryFolder);
    generateCalledFunctionsListWithCFLOW( AllDefinedFunctionsInDonorPath, donorEntryFunction, donorSourceFileFolder,
                                              resultFileFullPath);

    printf("\tGetting path from core function reverse call graph \n");
    char * outputFile = (char *) malloc(100 * sizeof(char));
    sprintf(outputFile, "%stemp_output_reversed.out", temporaryFolder);
    ListOfFunctionForGraph * ListOfFuncitonSourceFilePath = gererateReversePathFromCoreFunctionCalledGraph(AllDefinedFunctionsInDonorPath, currentCoreTransplantFunction,
                                                                                                           outputFile);
    ListOfFunctionForGraph * auxListOfFuncitonSourceFilePath  = ListOfFuncitonSourceFilePath;
    while(auxListOfFuncitonSourceFilePath->next){
        addNewString(ListOfReverseCallGraph, auxListOfFuncitonSourceFilePath->functionName);
        auxListOfFuncitonSourceFilePath = auxListOfFuncitonSourceFilePath->next;
    }

#ifdef GENERATE_REVERSE_CALL_GRAPH
#if !defined(FAST_RUNNING2) //LOSCHANGE
    /* Transform Reverse Call Graph in one unique and small path */
/*LOSTESTANDO*/    transformReverseCallGraph(TXLPath, donorSourceFileFolder, outputFile,
							  reversedCflowOutput, SkeletonInstantiateMappings, HostSymbolTable,
							  CurrentExistingMappings, resultFileFullPath, outputFileLabels);
#endif
#endif
#ifdef VEIN_GLOBAL_EXTRACTION
	ListOfFunctionForGraph * auxListOfFuncitonSourceFileForVein  = ListOfFuncitonSourceFilePath;
	ListOfFunctionSourceFile * ListOfFunctionsAndSourceFileInVein = NULL;
	while(auxListOfFuncitonSourceFileForVein){
		//if(searchOccurrenceOfStringInListOfStringsUsingSTRSTR(ListOfLabesFromVein, ListOfFunctionSourceFileInReverseGraph->functionName))
		addNewFunctionSourceFile(&ListOfFunctionsAndSourceFileInVein, auxListOfFuncitonSourceFileForVein->functionName, auxListOfFuncitonSourceFileForVein->sourceFile);
		auxListOfFuncitonSourceFileForVein = auxListOfFuncitonSourceFileForVein->next;
	}
	/*LOS Create main call function list used to extract global declaration to the vein*/
	createTheVeinCallListOfFunctions(ListOfFunctionsAndSourceFileInVein);
	freeListOfFunctionForGraph(&auxListOfFuncitonSourceFileForVein);
#endif
	fflush(stdout);
    free(outputFile);
    free(fileLocations);
    free(resultFileFullPath);
    free(tempListOfFunctionSourceFile);
    freeListOfFunctionForGraph(&ListOfFuncitonSourceFilePath);
}

/* Read  reverse call recursively from generated graph */
void readReverseFunctionFromGraph(struct Graph* graph, int vertex, int countSpace, ListOfFunctionForGraph *listFunctions, int maxSpace, int n) {
	struct node *adjList = graph->adjLists[vertex];
	struct node *temp = adjList;
	graph->visited[vertex] = 0;

    char *spaces = (char *) malloc(600 * sizeof(char));
    char *formattedCurrentSourceFile = NULL;
    char * formattedNeedSourceFileLocations = NULL;
    formattedCurrentSourceFile = (char *) malloc(10000 * sizeof(char));
    formattedNeedSourceFileLocations = (char *) malloc(500 * sizeof(char));

	int recursiveCall = 0;
	for (int i = 1; i < n; i++) {
		if (vertex == graphPathMemory[i]) {
			recursiveCall = 1;
		}
	}
	if (recursiveCall != 1){
		graphPathMemory[n] = vertex;
		if (n > maxNode)
			maxNode = n;
	}

	while(temp != NULL ) {
		int connectedVertex = temp->vertex;
		if (graph->visited[connectedVertex] == 0) {
			if(recursiveCall!=1)
                readReverseFunctionFromGraph(graph, connectedVertex, countSpace + 1, listFunctions, maxSpace,n+1);
		}
		if(temp != NULL || vertex == 1 ){
			ListOfFunctionForGraph *lastNode = searchNodeReferenceFromId(listFunctions, graphPathMemory[maxNode] );
                if(!strcmp(lastNode->functionName, donorEntryFunction)) {
                    printf("\t\tPath [%d] --------------------------\n", numberOfVeins);
				for (int i = maxNode; i > 0; i--) {
					int currentId = graphPathMemory[i];
					ListOfFunctionForGraph *currentNode = searchNodeReferenceFromId(listFunctions, currentId);

					/* spaces is used to format output required for txl parser */
					strcpy(spaces, "    ");
					sprintf(formattedNeedSourceFileLocations, "@@%s@@ ", currentNode->sourceFile);

					if (!searchStringInListOfStrings(ListOfFileFunction,formattedNeedSourceFileLocations)) {
						fflush(stdout);
						addNewString(&ListOfFileFunction, formattedNeedSourceFileLocations);
					}
					sprintf(formattedCurrentSourceFile, "%s%s source_file: @@%s@@ \n", spaces, currentNode->functionName, currentNode->sourceFile);
					strcpy(tempListOfFunctionSourceFile[nFunctions], formattedCurrentSourceFile);
                    strcpy(tempListOfFunction[nFunctions], currentNode->functionName);
					nFunctions++;
					fflush(stdout);
                    printf("\t\t%s", formattedCurrentSourceFile);
					if(i==1)
						strcpy(tempListOfFunctionSourceFile[nFunctions], END_PATH_MARK);
				}
				numberOfVeins++;
				maxNode = n;
				if (vertex == 1)
					temp = NULL;
			}
			else
			if(numberOfVeins > 0)
				return;
		}
        if(temp==NULL)
            return;
        else
		    temp = temp->next;
	}
    free(formattedCurrentSourceFile);
	free(formattedNeedSourceFileLocations);
	free(spaces);
}
#endif