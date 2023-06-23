/* 
 * File:   main.c
 * Author: ---
 *
 * Created on 26 May 2014, 22:45
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "folderContent.h"
#include "coreFunctionExtractor.h"
#include "GenTrans.h"
#include "Utils.h"

void extractCoreFunctionality(char * graftMethod, char * graftFileFullPath,
		char * donorSourceFiles, char * transplantWorkingFolder,
		char * txlProgsPath, char * TXLTemp, char * tempFolder,
		char * headerOutputFile, char * sourceOutputFile) {

	char * sourceFiles;
	sourceFiles = (char *) malloc(500 * sizeof(char));
	sprintf(sourceFiles, "%ssourceFilesInDonor.out", tempFolder);
	char * headerFiles;
	headerFiles = (char *) malloc(500 * sizeof(char));
	sprintf(headerFiles, "%sheaderFilesInDonor.out", tempFolder);
	char * resultFileFullPath;
	resultFileFullPath = (char *) malloc(500 * sizeof(char));

	sprintf(resultFileFullPath, "%sgcovParsedResults.out", tempFolder);
	char * gcovMainMethodMarker = "--main";
	char gcovMainMethod[400];
	sprintf(gcovMainMethod, "%s %s", gcovMainMethodMarker, graftMethod);
	char * outputFile = "outputCFLOW.out";
	char * gcov = " cflow";
	//char * restOfParams = "-i _ --omit-arguments *.c >";
	char * restOfParams = "--brief -i _ --omit-arguments *.c >";
	char * command;
	command = (char *) malloc(2000 * sizeof(char *));
	char gcovCommand[1000];
	char outputFileFullPath[1000];
	sprintf(outputFileFullPath, "%s%s", donorSourceFiles, outputFile);
	//sprintf(graftFileFullPath, "%s%s", donorSourceFiles, graftFile);
	sprintf(gcovCommand, "cd %s \n %s %s %s %s", donorSourceFiles, gcov,
			gcovMainMethod, restOfParams, outputFile);
	//("%s \n", gcovCommand);
	//printf("%s \n", outputFileFullPath);
	fflush(stdout);
	printf("[CFLOW] Obtaining the direct call graph of >%s< function dependencies\n",graftMethod);
	int status1 = system(gcovCommand);
	if (status1 != 0) {
		printf("ERROR");
	}
	char **listOfFiles = NULL;
	listOfFiles = (char**) malloc(10000000 * sizeof(char*));
	for (long int i = 0; i < 10000000; i++) {
		listOfFiles[i] = (char*) malloc(2000 * sizeof(char));
	}
	char * currentFct;
	currentFct = (char *) malloc(2000 * sizeof(char));
	char * line;
	line = (char *) malloc(2000 * sizeof(char));
	FILE * fin = fopen(outputFileFullPath, "r");
	long int n = 0;

	char * line2;
	char * line3;
	line2 = (char *) malloc(2000 * sizeof(char));
	line3 = (char *) malloc(2000 * sizeof(char));

    long int count =0;
	while (fgets(line, 2000, fin) != NULL) {

		sscanf(line, "%s", currentFct);
        //printf("%d: %s \n", count, currentFct);

		if (currentFct[strlen(currentFct) - 1] == ':') {
			currentFct[strlen(currentFct) - 3] = 0;
		} else {
			currentFct[strlen(currentFct) - 2] = 0;
		}

		char * formattedCurrentFunction;
		formattedCurrentFunction = (char *) malloc(2000 * sizeof(char));

		char * searchedStringFirst;
		searchedStringFirst = (char *) malloc(2000 * sizeof(char));
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

			sprintf(formattedCurrentFunction, "\"%s\" \"%s%s\"\n", currentFct,
					donorSourceFiles, line2);

		} else {
			sprintf(formattedCurrentFunction, "\"%s\" \"NOT_INTERNAL\"\n",
					currentFct);
		}

		if (!isInListOfNeededFiles(listOfFiles, n, formattedCurrentFunction)) {
			strcpy(listOfFiles[n], formattedCurrentFunction);
			//printf("%d: %s \n", count, formattedCurrentFunction);
			n++;
		}
        count++;
	}
	FILE *fout = fopen(resultFileFullPath, "w");
	for (long int i = 0; i < n; i++) {
		fprintf(fout, "%s", listOfFiles[i]);
	}
	fclose(fout);
	/*FILE * sourceFileName = fopen(sourceFiles, "w");
	FILE * headerFileName = fopen(headerFiles, "w");
	readFilesFromDir(donorSourceFiles, sourceFileName, 'c');
	readFilesFromDir(donorSourceFiles, headerFileName, 'h');
	fclose(sourceFileName);
	fclose(headerFileName);*/

	char * tempSourceFile;
	tempSourceFile = (char *) malloc(500 * sizeof(char));
	sprintf(tempSourceFile, "%stemp_souce_file_path.out", TXLTemporaryMultiFileFolder);
	FILE *fTempSouceFilePath = fopen(tempSourceFile, "w");

	char * formattedCurrentFile;
	formattedCurrentFile = (char *) malloc(2000 * sizeof(char));
	sprintf(formattedCurrentFile, "\"%s\"\n", graftFileFullPath);

	fprintf(fTempSouceFilePath, "%s", formattedCurrentFile);
	fclose(fout);

	char * listOfNeededFilesForCoreGraftFunction;
	listOfNeededFilesForCoreGraftFunction = (char *) malloc(100 * sizeof(char));
	strcpy(listOfNeededFilesForCoreGraftFunction, TXLTemp);
	strcat(listOfNeededFilesForCoreGraftFunction,
			"temp_list_of_header_files.out");
	//first is just a program that must be correct according to the grammar; it is not used, is needed just for
	//txl program to run!!!
	char * originalHOST;
	char * ifDefProgramPath;

	if (!strcmp(TXLToolsPath, "./")) {
		ifDefProgramPath = (char *) malloc(
				(strlen(TXLToolsPath) + 10) * sizeof(char));
		sprintf(ifDefProgramPath, "%sifdef.x", TXLToolsPath);
	} else {
		ifDefProgramPath = (char *) malloc(10 * sizeof(char));
		sprintf(ifDefProgramPath, "./ifdef.x");
	}
	originalHOST = transplantHostInputFile;
	printf("[TXL] MultplFiles.x >> Extract core function to Interface\n");
	sprintf(command, "./%smultiplFiles.x %s %s %s %s %s %s %s %s %s%s %s",
			txlProgsPath, originalHOST, graftFileFullPath, headerOutputFile,
			sourceOutputFile, resultFileFullPath, tempSourceFile, headerFiles,
			listOfNeededFilesForCoreGraftFunction, TXLToolsPath, ifDefProgramPath,
			ConsoleStderrOutput);
	int status2 = system(command);
	if (status2 != 0) {
		printf("\t%s\n", command);
		printf("ERROR multiplFiles !!!!!\n");
		exit(1);
	}
	//copyNeededFiles(listOfNeededFilesForCoreGraftFunction, donorSourceFiles, transplantWorkingFolder,
	//locationToCopyFiles);
	fclose(fin);

	//free memory
	for (long int i = 0; i < 10000000; i++) {
		free(listOfFiles[i]);
	}

	free(listOfFiles);
	free(currentFct);
	free(listOfNeededFilesForCoreGraftFunction);
	free(line);
}
