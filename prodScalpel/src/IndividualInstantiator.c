#include "IndividualInstantiator.h"
#include "ListOfString.h"
#include "PrepareForGP.h"
#include "GenTrans.h"
#include "Skeleton.h"
#include "ListOfInt.h"
#include "FunctionElement.h"
#include "coreFunctionExtractor.h"
#include "FunctionExtractor.h"
#include "GP.h"
#include "GPIndividual.h"

//#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "folderContent.h"
#include "MarkFunctionCall.h"

#include "Utils.h"

int readTransplantCandidadateFile(char * inputCandidate,
		Mapping ** FinalMappingsInIndividual,
		ListOfString ** MappedDeclarations,
		ListOfInt ** ListOfCandidateSelectedLines) {

	//count the number of mapped graft IDs to Host Symbol Table
	int mappedIDsToHostVariables = 0;

	FILE * fin = fopen(inputCandidate, "r");

	char * line;
	line = (char *) malloc(3000 * sizeof(char));

	//read abstract mappings
	fgets(line, 2999, fin);
	fgets(line, 2999, fin);
	while (strcmp(line, DeclarationMappingsMarker)) {

		mappedIDsToHostVariables = mappedIDsToHostVariables + 1;

		char * source;
		char * destination;
		source = (char*) malloc(500 * sizeof(char));
		destination = (char*) malloc(500 * sizeof(char));

		//+1 for the space
		sscanf(line, "%s", source);
		line += strlen(source) + 1;

		//remove end line character
		line[strlen(line) - 1] = '\0';
		strcpy(destination, line);

		//sscanf(line, "%s %s", source, destination);
		addNewMapping(&(*FinalMappingsInIndividual), source, destination);
		free(source);
		free(destination);
		fgets(line, 2999, fin);
	}

	fgets(line, 2999, fin);
	while (strcmp(line, IndividualLinesMarker)) {

		mappedIDsToHostVariables = mappedIDsToHostVariables + 1;

		char * declMarker;
		char * source;
		char * destination;

		declMarker = (char*) malloc(500 * sizeof(char));
		source = (char*) malloc(500 * sizeof(char));
		destination = (char*) malloc(500 * sizeof(char));
		char * token = strtok(line, "@");
		strcpy(declMarker, token);
		token = strtok(NULL, "@");
		strcpy(source, token);
		token = strtok(NULL, "@");
		strcpy(destination, token);
		//last character in destination is end of line
		destination[strlen(destination) - 1] = '\0';

		addNewMapping(&(*FinalMappingsInIndividual), source, destination);
		addNewString(&(*MappedDeclarations), declMarker);
		fgets(line, 2999, fin);
		free(declMarker);
		free(source);
		free(destination);
	}

	while (fgets(line, 2999, fin)) {
		int value;
		sscanf(line, "%d", &value);
		addNewInt(&(*ListOfCandidateSelectedLines), value);
	}

	//free(line);
	fclose(fin);
	return mappedIDsToHostVariables;
}


void extractCoreFunctionsCalledInIndividual(
		CallDependency * ListOfNeededFunctionsForAllLOCs,
		ListOfString * candidateLOCsInstantiated,
		char * headerFilesForCoreFunctions, char * sourceFileForCoreFunction,
		ListOfString ** FinalListOfTransplantedFunctions,
		CallDependency * calledFunctionsByGlobals,
		char * TXLTemporaryFolder) {
/*
#ifdef DONOR_IS_HOST
	char * listOfSourceFilesFromHost;
	listOfSourceFilesFromHost = (char *) malloc(500 * sizeof (char));
	sprintf(listOfSourceFilesFromHost, "%stemp_host_files_for_function_list.out", TXLTemporaryFolder);

	FILE * listOfSourceFilesFromHostFile = fopen(listOfSourceFilesFromHost, "w");
	readFilesFromDir(transplantHostInputFile, listOfSourceFilesFromHostFile, 'c');
	fclose(listOfSourceFilesFromHostFile);

	char * outputAllDefinedFunctionsInHost;
	outputAllDefinedFunctionsInHost = (char *) malloc(1000 * sizeof(char));
	sprintf(outputAllDefinedFunctionsInHost,
			"%stemp_all_defined_functions_int_host.out",
			TXLTemporaryFolderMainThread);

	createListOfDonorFunctions(TXLToolsPath, listOfSourceFilesFromHost, outputAllDefinedFunctionsInHost);
#endif
*/
	//this is needed for knowing what global dependencies to transplant
	ListOfString * listOfTransplantedFunctions =
			*FinalListOfTransplantedFunctions;
	//extract core functionalities!!!
	CallDependency * auxCallDepend = ListOfNeededFunctionsForAllLOCs;
    int countFunctions = 0;
	printf("[AUTOSCALPEL] Extracting functions\n");

	while (ListOfNeededFunctionsForAllLOCs){
		printf("\tListNeedFunctions: %s File: %s\n",ListOfNeededFunctionsForAllLOCs->calledFunctions->functionName,ListOfNeededFunctionsForAllLOCs->calledFunctions->sourceFile);
		ListOfNeededFunctionsForAllLOCs = ListOfNeededFunctionsForAllLOCs->next;
	}

    while (auxCallDepend) {
		ListOfString * auxCandidateInstLoc = candidateLOCsInstantiated;
		int signal = 0;
		while (auxCandidateInstLoc && !signal) {
			if (strstr(auxCandidateInstLoc->el, auxCallDepend->LOCMarker)) {
				signal = 1;
			}
			auxCandidateInstLoc = auxCandidateInstLoc->next;
		}
		if (signal == 1) {
			//the line was called, so all its dependencies must be transplanted
			ListOfFunctionSourceFile * auxFunction =
					auxCallDepend->calledFunctions;

			while (auxFunction) {
				char * functionHeaderFile;
				functionHeaderFile = (char *) malloc(500 * sizeof(char));
				sprintf(functionHeaderFile, "%s%s_header_file.out",
						TransplantResultLocation, auxFunction->functionName);

				//transplanted function marker for global dependency extractor
				char * transplantedFunctionMarker;
				transplantedFunctionMarker = (char *) malloc(
						500 * sizeof(char));
				sprintf(transplantedFunctionMarker, "/* %s */",
						auxFunction->functionName);

				if (!searchStringInListOfStrings(listOfTransplantedFunctions,
						transplantedFunctionMarker)) {
					addNewString(&listOfTransplantedFunctions,
							transplantedFunctionMarker);
					/*extractCoreFunctionality(auxFunction->functionName,
							auxFunction->sourceFile, donorSourceFileFolder,
							transplantWorkFolderMainThread, TXLToolsPath,
							TXLTemporaryFolder, TXLTemporaryFolder,
							headerFilesForCoreFunctions,
							sourceFileForCoreFunction);*/
#if !defined(DONOR_IS_HOST)
					extractFunctionality(auxFunction->functionName, auxFunction->sourceFile,
										 donorSourceFileFolder,
                                         TXLToolsPath, TXLTemporaryFolder, TXLTemporaryMultiFileFolder);
#endif
                }
				auxFunction = auxFunction->next;

				free(functionHeaderFile);
			}
		}
		auxCallDepend = auxCallDepend->next;
        countFunctions++;
	}

	//now add the ones called by globals!

	ListOfFunctionSourceFile * auxFunction =
			calledFunctionsByGlobals->calledFunctions;


	while (auxFunction) {
		char * functionHeaderFile;
		functionHeaderFile = (char *) malloc(500 * sizeof(char));
		sprintf(functionHeaderFile, "%s%s_header_file.out",
				TransplantResultLocation, auxFunction->functionName);

		//transplanted function marker for global dependency extractor
		char * transplantedFunctionMarker;
		transplantedFunctionMarker = (char *) malloc(500 * sizeof(char));
		sprintf(transplantedFunctionMarker, "/* %s */",
				auxFunction->functionName);

		if (!searchStringInListOfStrings(listOfTransplantedFunctions,
				transplantedFunctionMarker)) {
			addNewString(&listOfTransplantedFunctions,
					transplantedFunctionMarker);

			/*extractCoreFunctionality(auxFunction->functionName,
					auxFunction->sourceFile, donorSourceFileFolder,
					transplantWorkFolderMainThread, TXLToolsPath, TXLTemporaryFolder,
					TXLTemporaryFolder, headerFilesForCoreFunctions,
					sourceFileForCoreFunction);*/
#if !defined(DONOR_IS_HOST)
			printf("\tFunctionName[%d]: %s File: %s\n",countFunctions+1, auxFunction->functionName, auxFunction->sourceFile);
			extractFunctionality(auxFunction->functionName, auxFunction->sourceFile,
								 donorSourceFileFolder,
                                 TXLToolsPath, TXLTemporaryFolder, TXLTemporaryMultiFileFolder);
#endif
		}
		auxFunction = auxFunction->next;

		//free(functionHeaderFile);
	}

	// * FinalListOfTransplantedFunctions = listOfTransplantedFunctions;
	//extract needed globals for the core file
}

ListOfString * instantiateCurrentIndividualInSkeleton(
		char * initialFunctionFile, char * initialMappingsFile, char * TXLTemporaryFolder) {
   /// printf("\tInstantiate Current Individual In Skeleton\n");
	//instantiate the current candidate in skeleton

	char * command;
	command = (char *) malloc(400 * sizeof(char));
	sprintf(command, "ulimit -s 65353 && %sinstantiateFunctionsInSkeleton.x", TXLToolsPath);
    fflush(stdout);
    /* LOSCHANGE Change input for instantiateCurrentIndificualInSkeleton() from temp_mapping_file_abstract_dependencies.out to temp_initial_mappings.
    * any problem found until ...*/
    //TODO Check for possible side effects
	char * skeletonFctInstantiate;
	skeletonFctInstantiate = (char *) malloc(400 * sizeof(char));
	sprintf(skeletonFctInstantiate,
			"%stemp_candidate_skeleton_instantiated.out", TXLTemporaryFolder);

	char * commandTXL;
	commandTXL = (char *) malloc(5000 * sizeof(char));
    sprintf(commandTXL, "ulimit -s 65353 && %s %s %s %s %s", command, initialFunctionFile,
			initialMappingsFile, skeletonFctInstantiate, ConsoleStderrOutput);
#ifdef INSTANTIATE_CURRENT_INDIVIDUAL_IN_SKELETON
#ifdef DEBUGING2
    printf("\t\t[TXL] instantiateFunctionsInSkeleton.x >> Instantiate functions in Skeleton\n");
#endif
	int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR! instantiateCurrentIndividualInSkeleton.x\n");
		system("open ErrorFile.out");
		exit(1);
	} else
#ifdef DEBUGING
	    printf("\t\t\t|>> temp_candidate_skeleton_instantiated.out\n");
#endif
#endif
	free(commandTXL);
	FILE * resultedFunction = fopen(skeletonFctInstantiate, "r");

	ListOfString * candidateLOCsInstantiated = NULL;
	char * line = (char *) malloc(1000 * sizeof(char));
	while (fgets(line, 400, resultedFunction) != NULL) {
		if (strcmp(line, "\n")) {
			addNewString(&candidateLOCsInstantiated, line);
		}
	}
	fclose(resultedFunction);
	return candidateLOCsInstantiated;
}

ListOfString * generateNewSkeletonForCandidate(ArrayOfStrings SkeletonLOCsArray,
		ListOfString * SkeletonSourceCode, char * candidateFile,
		DependencyList * ListOfDependenciesForStatements,
		ListOfString ** TheListOfTransplantedMarkers,
		int * MappedGraftHostVariables,
		char * TXLTemporaryFolder) {

	Mapping * FinalMappingsInIndividual = NULL;
	ListOfString * MappedDeclarations = NULL;
	ListOfInt * ListOfCandidateSelectedLines = NULL;

	//mapped declarations are declarations from the skeleton, which are mapped to variables from the host,
	//so there is no need to transplant the variable declarations on which these are dependent
	*MappedGraftHostVariables = readTransplantCandidadateFile(candidateFile,
			&FinalMappingsInIndividual, &MappedDeclarations,
			&ListOfCandidateSelectedLines);

	ListOfString * neededMarkersForTransplant = NULL;

	//add all the line markers from the SkeletonLOC array, at the position selected by GP
	ListOfInt * aux = ListOfCandidateSelectedLines;
	while (aux) {
		if (!searchStringInListOfStrings(neededMarkersForTransplant,
				SkeletonLOCsArray.array[aux->value])) {
			addNewString(&neededMarkersForTransplant,
					SkeletonLOCsArray.array[aux->value]);
		}
		aux = aux->next;
	}

	//add the return marker, since it is the return of the interface and must always be presented
	addNewString(&neededMarkersForTransplant, RETURN_MARKER);

	ListOfString * auxNeededMarkers = neededMarkersForTransplant;

	//for all added line markers, add the one from dependency, if they are not mapped
	while (auxNeededMarkers) {
		//memory leak!!! returnDependencyForAMarker makes new one, while adding adds also
		ListOfString * neededDepsForCurrent =
				returnDependencyForAMarkerNewPointers(
						ListOfDependenciesForStatements, auxNeededMarkers->el);
		if (neededDepsForCurrent) {
			ListOfString * auxListString = neededDepsForCurrent;
			//maybe this is infinite.. it should be checked that the new marker is not already in the list
			while (auxListString) {
				if (!searchStringInListOfStrings(MappedDeclarations,
						auxListString->el)) {
					addNewString(&neededMarkersForTransplant,
							auxListString->el);
				}
				auxListString = auxListString->next;
			}
			freeListOfStrings(&neededDepsForCurrent);
		}
		auxNeededMarkers = auxNeededMarkers->next;
	}

	*TheListOfTransplantedMarkers = neededMarkersForTransplant;

	ListOfString * candidateLOCs = NULL;
	ListOfString * auxSkeletonCode = SkeletonSourceCode;

	while (auxSkeletonCode) {
		//add some marker for LABEL ABST!!!, not like this
		if (!strstr(auxSkeletonCode->el, "/*")
				&& !strstr(auxSkeletonCode->el, "//")
				&& !strstr(auxSkeletonCode->el, "LABEL_ABST")
				&& !strstr(auxSkeletonCode->el, "break")) {
			addNewString(&candidateLOCs, auxSkeletonCode->el);
		} else {
			auxNeededMarkers = neededMarkersForTransplant;
			while (auxNeededMarkers) {
				if (strstr(auxSkeletonCode->el, auxNeededMarkers->el)) {
					addNewString(&candidateLOCs, auxSkeletonCode->el);
				}
				auxNeededMarkers = auxNeededMarkers->next;
			}
		}
		auxSkeletonCode = auxSkeletonCode->next;
	}

	//print the initial function file, for individual instantiator
	char * initialFunctionFile;
	initialFunctionFile = (char *) malloc(500 * sizeof(char));
	sprintf(initialFunctionFile, "%stemp_individual_for_instantiation.out",
			TXLTemporaryFolder);

	printAListOfStrings(candidateLOCs, initialFunctionFile);

	//print the initial mappings file, for individual instantiator
	char * initialMappingsFile;
	initialMappingsFile = (char *) malloc(500 * sizeof(char));

	sprintf(initialMappingsFile,
			"%stemp_mappings_for_candidate_instantiation.out",
			TXLTemporaryFolder);

	FILE * symbolTableResults = fopen(initialMappingsFile, "w");
	Mapping * currentListOfMappings = FinalMappingsInIndividual;

	while (currentListOfMappings) {
		fprintf(symbolTableResults, "\"%s\" \"%s\" ",
				currentListOfMappings->source,
				currentListOfMappings->destination);
		currentListOfMappings = currentListOfMappings->next;
	}
	fclose(symbolTableResults);

	ListOfString * candidateLOCsInstantiated =
			instantiateCurrentIndividualInSkeleton(initialFunctionFile,
					initialMappingsFile, TXLTemporaryFolder);
	return candidateLOCsInstantiated;
}

void callCoreFeatureGlobalDependencySolver(char * tempSkeletonFile,
		char * tempGlobalDeclarations, char * tempGlobalTypeVarDecl,
		char * TXLProgsPath, char * temporaryOutputFile) {
	char * commandTXL;
	commandTXL = (char *) malloc(1500 * sizeof(char));
#ifdef DEBUGING2
	printf("\t[TXL] GlobalVarTypesDeclDependencyCOREFUNCTIONS.x >> Extract global var types declaration dependency core functions\n");
#endif
	sprintf(commandTXL,
			"%sGlobalVarTypesDeclDependencyCOREFUNCTIONS.x %s %s %s %s %s",
			TXLProgsPath, tempSkeletonFile, tempGlobalDeclarations,
			tempGlobalTypeVarDecl, temporaryOutputFile, ConsoleStderrOutput);
	int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR! GlobalVarTypesDeclDependencyCOREFUNCTIONS.x\n");
		printf("\t%s\n", commandTXL);
		exit(1);
	}
	free(commandTXL);
}


#ifdef SEARCH_VAR_UNION

void callCoreFeatureGlobalDependencySolverForVarUnion(char * tempSkeletonFile,
										   char * tempGlobalDeclarations, char * tempGlobalTypeVarDecl,
										   char * TXLProgsPath, char * temporaryOutputFile) {
	char * commandTXL;
	commandTXL = (char *) malloc(1500 * sizeof(char));
	printf("[TXL] GlobalVarTypesDeclDependencyVarUnion.x >> Extract global var types declaration union dependency \n");
	sprintf(commandTXL,
			"%sGlobalVarTypesDeclDependencyVarUnion.x %s %s %s %s %s",
			TXLProgsPath, tempSkeletonFile, tempGlobalDeclarations,
			tempGlobalTypeVarDecl, temporaryOutputFile, ConsoleStderrOutput);
	int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR! GlobalVarTypesDeclDependencyCOREFUNCTIONS.x\n");
		printf("\t%s\n", commandTXL);
		//exit(1);
	}
	free(commandTXL);
}

#endif
DependencyList * extractDependencyGlobalListForCoreFunctions(
		char * coreFunctionSourceFile, char * globalDeclarationFile,
		char * globalDefinedTypesVarFile, char * TXLTemporaryFolder) {

	char * tempOutputFile;
	tempOutputFile = (char *) malloc(500 * sizeof(char));
	sprintf(tempOutputFile, "%stemp_core_function_global_dependencies.out",
			TXLTemporaryFolder);

	fflush(stdout);

	callCoreFeatureGlobalDependencySolver(coreFunctionSourceFile,
			globalDeclarationFile, globalDefinedTypesVarFile, TXLToolsPath,
			tempOutputFile);

#if 0 //SEARCH_VAR_UNION
	char * tempOutputVarUnionDependencyFile;
	tempOutputVarUnionDependencyFile = (char *) malloc(500 * sizeof(char));
	sprintf(tempOutputVarUnionDependencyFile, "%stemp_core_function_global_dependencies.out",
			TempVeinDirectory);

	char * FinalListOfAllVarExtracted;
	FinalListOfAllVarExtracted = (char *) malloc(500 * sizeof(char));
	sprintf(FinalListOfAllVarExtracted, "%sAllGlobalVarExtracted.h",
			TempVeinDirectory);

	/* temp global type variable declarations: temp_global_type_var_declarations.out */
	char *definedGlobalTypesAndVariablesFile;
	definedGlobalTypesAndVariablesFile = (char *) malloc(500 * sizeof(char));
	sprintf(definedGlobalTypesAndVariablesFile, "%stemp_global_type_var_declarations.out", TXLTemporaryFolderMainThread);

	callCoreFeatureGlobalDependencySolverForVarUnion(FinalListOfAllVarExtracted,
										  globalDeclarationFile, globalDefinedTypesVarFile, TXLToolsPath,
													 tempOutputVarUnionDependencyFile);
	ListOfString * listOfVars = readListOfStringFromFile(tempOutputVarUnionDependencyFile);

	addAListOfStringsInTheEnd(listOfVars, tempOutputFile);

#endif
	fflush(stdout);


	DependencyList * skeletonGlobalDependencies = readDependencyListFromFile(
			tempOutputFile);

	//return skeletonGlobalDependencies;
	return skeletonGlobalDependencies;
}

#ifdef SEARCH_VAR_UNION
DependencyList * extractDependencyGlobalListForVarUnionDependency(
		char * coreFunctionSourceFile, char * globalDeclarationFile,
		char * globalDefinedTypesVarFile, char * TXLTemporaryFolder) {

	char * tempOutputFile;
	tempOutputFile = (char *) malloc(500 * sizeof(char));
	sprintf(tempOutputFile, "%stemp_core_function_global_dependencies.out",
			TXLTemporaryFolder);

	fflush(stdout);
/*
	callCoreFeatureGlobalDependencySolver(coreFunctionSourceFile,
										  globalDeclarationFile, globalDefinedTypesVarFile, TXLToolsPath,
										  tempOutputFile);
*/
#ifdef SEARCH_VAR_UNION
	char * tempOutputVarUnionDependencyFile;
	tempOutputVarUnionDependencyFile = (char *) malloc(500 * sizeof(char));
	sprintf(tempOutputVarUnionDependencyFile, "%stemp_core_function_global_dependencies.out",
			TempVeinDirectory);

	char * FinalListOfAllVarExtracted;
	FinalListOfAllVarExtracted = (char *) malloc(500 * sizeof(char));
	sprintf(FinalListOfAllVarExtracted, "%sAllGlobalVarExtracted.h",
			TempVeinDirectory);

	callCoreFeatureGlobalDependencySolverForVarUnion(FinalListOfAllVarExtracted,
										  globalDeclarationFile, globalDefinedTypesVarFile, TXLToolsPath,
													 tempOutputVarUnionDependencyFile);
	ListOfString * listOfVars = readListOfStringFromFile(tempOutputVarUnionDependencyFile);

	addAListOfStringsInTheEnd(listOfVars, tempOutputFile);

#endif
	fflush(stdout);


	DependencyList * skeletonGlobalDependencies = readDependencyListFromFile(
			tempOutputVarUnionDependencyFile);

	//return skeletonGlobalDependencies;
	return skeletonGlobalDependencies;
}
#endif

#if 1 /* MULTIFILES */
DependencyList * extractDependencyGlobalListForCoreFunctionsMultFiles(
		char * coreFunctionSourceFile, char * globalDeclarationFile,
		char * globalDefinedTypesVarFile, char * TXLTempMultiFilesFolder) {

	char * tempOutputFile;
	tempOutputFile = (char *) malloc(500 * sizeof(char));
	sprintf(tempOutputFile, "%stemp_core_function_global_dependencies.out",
			TXLTempMultiFilesFolder);

	fflush(stdout);

	callCoreFeatureGlobalDependencySolver(coreFunctionSourceFile,
										  globalDeclarationFile, globalDefinedTypesVarFile, TXLToolsPath,
										  tempOutputFile);

	fflush(stdout);

	DependencyList * skeletonGlobalDependencies = NULL;
	skeletonGlobalDependencies = readDependencyListFromFile(
			tempOutputFile);
	//return skeletonGlobalDependencies;
	return skeletonGlobalDependencies;
}
#endif

#if 0  /* MULTIFILES */
DependencyList * extractDependencyGlobalListForCoreFunctionsMultFiles( char * globalDeclarationFile,
        char * globalDefinedTypesVarFile, char * TXLTemporaryFolder, char * TXLTempMultiFiles) {

    char * tempOutputFile;
    tempOutputFile = (char *) malloc(500 * sizeof(char));
    sprintf(tempOutputFile, "%stemp_core_function_global_dependencies.out",
            TXLTempMultiFiles);

    char * sourceContentFilesTarget;
    sourceContentFilesTarget = (char *) malloc(500 * sizeof(char));
    sprintf(sourceContentFilesTarget, "%stemp_list_of_source_files_extracted.out", TXLTempMultiFiles);

    fflush(stdout);

    char * currentSourceFile;
    currentSourceFile = (char*) malloc(400 * sizeof(char));
    char *line;
    line = (char *) malloc(400 * sizeof(char));
    FILE * fin = fopen(sourceContentFilesTarget, "r");

    char * coreFunctionSourceFile;
    coreFunctionSourceFile = (char *) malloc(500 * sizeof(char));

    while (fgets(line, 400, fin) != NULL) {
        sscanf(line, "%s", currentSourceFile);

        sprintf(coreFunctionSourceFile, "%s%s", TXLTempMultiFiles, currentSourceFile);

        callCoreFeatureGlobalDependencySolver(coreFunctionSourceFile,
                                              globalDeclarationFile, globalDefinedTypesVarFile, TXLToolsPath,
                                              tempOutputFile);

        fflush(stdout);
    }
    DependencyList * skeletonGlobalDependencies = readDependencyListFromFile(
            tempOutputFile);
    //return skeletonGlobalDependencies;
    return skeletonGlobalDependencies;
}

#endif

void addLocsFromSourceToDestination(char * destinationFileName,
		char * sourceFileName, char * TXLProgsPath) {
	fflush(stdout);
	char * commandTXL;
	commandTXL = (char *) malloc(1000 * sizeof(char));
	//printf("TXL: InsertAllSourceCodeFromInputAtTheBegginingOfOutput.x >> Insert All Source Code From Input At The Beggining Of Output\n");
	sprintf(commandTXL,
			"ulimit -s 65353 && %sInsertAllSourceCodeFromInputAtTheBegginingOfOutput.x %s %s %s",
			TXLProgsPath, sourceFileName, destinationFileName,
			ConsoleStderrOutput);
	int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR! InsertAllSourceCodeFromInputAtTheBegginingOfOutput");
		printf("\t%s\n", commandTXL);
		fflush(stdout);
		system("open ErrorFile.out");
		/* add var into its correspondent file
		char * outputFile = (char *) malloc((strlen(TXLTemporaryFolderMainThread) + 30) * sizeof (char));
		sprintf(outputFile, "%slist_of_global_vars_do_not_inserted.out", TXLTemporaryFolderMainThread);
		addLocsFromSourceToDestination(sourceFileName,
				outputFile, TXLToolsPath);*/
		exit(1);
	}
	free(commandTXL);
	fflush(stdout);
}

void addLocsFromSourceToDestinationWithDirectives(char * destinationFileName,
									char * sourceFileName, char * TXLProgsPath) {
	char * commandTXL;
	commandTXL = (char *) malloc(1000 * sizeof(char));
	//printf("TXL: InsertAllSourceCodeFromInputAtTheBegginingOfOutput.x >> Insert All Source Code From Input At The Beggining Of Output\n");
	sprintf(commandTXL,
			"ulimit -s 65353 && %sInsertAllSourceCodeFromInputAtTheBegginingOfOutputWithPreprocessDirective.x %s %s %s",
			TXLProgsPath, sourceFileName, destinationFileName,
			ConsoleStderrOutput);
	int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR! InsertAllSourceCodeFromInputAtTheBegginingOfOutputWithPreprocessDirective.x");
		printf("\t%s\n", commandTXL);
		fflush(stdout);

		/* add var into its correspondent file */
		char * outputFile = (char *) malloc((strlen(TXLTemporaryFolderMainThread) + 30) * sizeof (char));
		sprintf(outputFile, "%slist_of_global_vars_do_not_inserted.out", TXLTemporaryFolderMainThread);

		addLocsFromSourceToDestination(sourceFileName,
									   outputFile, TXLToolsPath);
		//exit(1);
	}
	free(commandTXL);
    fflush(stdout);
}

void removeLocsFromSourceFile(char * sourceFile,
									char * sourceFileWithLocsToBeRemoved, char * TXLProgsPath) {
	char * commandTXL;
	commandTXL = (char *) malloc(1000 * sizeof(char));
	//printf("TXL: InsertAllSourceCodeFromInputAtTheBegginingOfOutput.x >> Insert All Source Code From Input At The Beggining Of Output\n");
	sprintf(commandTXL,
			"ulimit -s 65353 && %sRemoveDuplicatedSourceCodeFromInputStatement.x %s %s %s",
			TXLProgsPath, sourceFileWithLocsToBeRemoved, sourceFile,
			ConsoleStderrOutput);
	int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR! InsertAllSourceCodeFromInputAtTheBegginingOfOutput");
		exit(1);
		fflush(stdout);
	}
	free(commandTXL);
    fflush(stdout);
}



#ifdef VEIN_GLOBAL_EXTRACTION
// TODO rewrite this funcition to MULTIFILE
void extractNeededGlobalDeclarationsAndHeaderForCoreFunction2(
        GlobalDeclarations ListOfFinalGlobalDeclarations,
        DependencyList * GlobalDependencyList,
        DependencyList * SkeletonDependenciesOnGlobals,
        DependencyList * DependencyListGlobalCoreFunctions,
        ListOfString * ListOfSkeletonSelectedLOCs,
        ListOfString * ListOfSelectedFunctionNames,
        char * tempSourceCodeGlobalsContent, char * tempHeaderGlobalsContent) {

    GlobalDeclarations AllGlobalNeededDeclarationsSkeleton =
            extractNeededGlobalDeclarationsForSkeleton(
                    ListOfSkeletonSelectedLOCs, ListOfFinalGlobalDeclarations,
                    GlobalDependencyList, SkeletonDependenciesOnGlobals);

    GlobalDeclarations AllGlobalNeededDeclarationsCoreFunctions =
            extractNeededGlobalDeclarationsForSkeleton(
                    ListOfSelectedFunctionNames, ListOfFinalGlobalDeclarations,
                    GlobalDependencyList, DependencyListGlobalCoreFunctions);

    GlobalDeclarations GlobalNeededCoreAndSkeleton;
    GlobalNeededCoreAndSkeleton.normalDeclarations = NULL;
    GlobalNeededCoreAndSkeleton.structUnionDeclarations = NULL;
    GlobalNeededCoreAndSkeleton.typedefDeclarations = NULL;

    addGlobalDeclarationListToExistingOne(&GlobalNeededCoreAndSkeleton,
                                          AllGlobalNeededDeclarationsSkeleton);
    addGlobalDeclarationListToExistingOne(&GlobalNeededCoreAndSkeleton,
                                          AllGlobalNeededDeclarationsCoreFunctions);

    printListOfGlobalDeclarations2(GlobalNeededCoreAndSkeleton,
                                              tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);


    char * tempListOfVarsExtracted;
    tempListOfVarsExtracted = (char *) malloc(500 * sizeof(char));
    sprintf(tempListOfVarsExtracted, "%stemp_list_of_vars_extracted.out",
            TempVeinDirectory);

    printAllListOfGlobalDeclarationsExtracted(GlobalNeededCoreAndSkeleton,
                                              tempListOfVarsExtracted);

#if 0 /* MULTIFILES */
    /* LOS: add declarations in its respective source file */
	printListOfGlobalDeclarations(AllGlobalNeededDeclarationsCoreFunctions,
								  tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);
#endif
}

#endif

#ifdef HEADER_FILE
// TODO rewrite this funcition to MULTIFILE
void extractNeededGlobalDeclarationsAndHeaderForCoreFunction(
		GlobalDeclarations ListOfFinalGlobalDeclarations,
		DependencyList * GlobalDependencyList,
		DependencyList * SkeletonDependenciesOnGlobals,
		DependencyList * DependencyListGlobalCoreFunctions,
		ListOfString * ListOfSkeletonSelectedLOCs,
		ListOfString * ListOfSelectedFunctionNames,
		char * tempSourceCodeGlobalsContent, char * tempHeaderGlobalsContent) {

	GlobalDeclarations AllGlobalNeededDeclarationsSkeleton =
			extractNeededGlobalDeclarationsForSkeleton(
					ListOfSkeletonSelectedLOCs, ListOfFinalGlobalDeclarations,
					GlobalDependencyList, SkeletonDependenciesOnGlobals);

	GlobalDeclarations AllGlobalNeededDeclarationsCoreFunctions =
			extractNeededGlobalDeclarationsForSkeleton(
					ListOfSelectedFunctionNames, ListOfFinalGlobalDeclarations,
					GlobalDependencyList, DependencyListGlobalCoreFunctions);

	GlobalDeclarations GlobalNeededCoreAndSkeleton;
	GlobalNeededCoreAndSkeleton.normalDeclarations = NULL;
	GlobalNeededCoreAndSkeleton.structUnionDeclarations = NULL;
	GlobalNeededCoreAndSkeleton.typedefDeclarations = NULL;

	addGlobalDeclarationListToExistingOne(&GlobalNeededCoreAndSkeleton,
										  AllGlobalNeededDeclarationsSkeleton);
	addGlobalDeclarationListToExistingOne(&GlobalNeededCoreAndSkeleton,
										  AllGlobalNeededDeclarationsCoreFunctions);

	printListOfGlobalDeclarationsCoreFunction(GlobalNeededCoreAndSkeleton,
								  tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);

#if 0 /* MULTIFILES */
	/* LOS: add declarations in its respective source file */
	printListOfGlobalDeclarations(AllGlobalNeededDeclarationsCoreFunctions,
								  tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);
#endif
}

#endif
// TODO rewrite this funcition to MULTIFILE
void extractNeededGlobalDeclarationsAndHeaderForSkeletonAndInterface(
		GlobalDeclarations ListOfFinalGlobalDeclarations,
		DependencyList * GlobalDependencyList,
		DependencyList * SkeletonDependenciesOnGlobals,
		DependencyList * DependencyListGlobalCoreFunctions,
		ListOfString * ListOfSkeletonSelectedLOCs,
		ListOfString * ListOfSelectedFunctionNames,
		char * tempSourceCodeGlobalsContent, char * tempHeaderGlobalsContent) {

	GlobalDeclarations AllGlobalNeededDeclarationsSkeleton =
			extractNeededGlobalDeclarationsForSkeleton(
					ListOfSkeletonSelectedLOCs, ListOfFinalGlobalDeclarations,
					GlobalDependencyList, SkeletonDependenciesOnGlobals);

	GlobalDeclarations AllGlobalNeededDeclarationsCoreFunctions =
			extractNeededGlobalDeclarationsForSkeleton(
					ListOfSelectedFunctionNames, ListOfFinalGlobalDeclarations,
					GlobalDependencyList, DependencyListGlobalCoreFunctions);

	GlobalDeclarations GlobalNeededCoreAndSkeleton;
	GlobalNeededCoreAndSkeleton.normalDeclarations = NULL;
	GlobalNeededCoreAndSkeleton.structUnionDeclarations = NULL;
	GlobalNeededCoreAndSkeleton.typedefDeclarations = NULL;


	addGlobalDeclarationListToExistingOne(&GlobalNeededCoreAndSkeleton,
			AllGlobalNeededDeclarationsSkeleton);
	addGlobalDeclarationListToExistingOne(&GlobalNeededCoreAndSkeleton,
			AllGlobalNeededDeclarationsCoreFunctions);

	printListOfGlobalDeclarationsForSkeleton(GlobalNeededCoreAndSkeleton,GlobalDependencyList,
			tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);

// TODO LOS DELETE UNUSED
#if 0
     /* MULTIFILES */
	/* LOS: add declarations in its respective source file */
	printListOfGlobalDeclarations(AllGlobalNeededDeclarationsCoreFunctions,
								  tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);
#endif
}

void extractNeededGlobalDeclarationsAndHeaderForOrgan(
		GlobalDeclarations ListOfFinalGlobalDeclarations,
		DependencyList * GlobalDependencyList,
		DependencyList * SkeletonDependenciesOnGlobals,
		DependencyList * DependencyListGlobalCoreFunctions,
		ListOfString * ListOfSkeletonSelectedLOCs,
		ListOfString * ListOfSelectedFunctionNames,
		char * tempSourceCodeGlobalsContent, char * tempHeaderGlobalsContent) {

#ifdef DEBUGING2
    printf("\t\tExtracting needed global declarations and header for organ\n");
#endif
    GlobalDeclarations AllGlobalNeededDeclarationsSkeleton =
            extractNeededGlobalDeclarationsForSkeleton(
                    ListOfSkeletonSelectedLOCs, ListOfFinalGlobalDeclarations,
                    GlobalDependencyList, SkeletonDependenciesOnGlobals);

	GlobalDeclarations AllGlobalNeededDeclarationsCoreFunctions =
			extractNeededGlobalDeclarationsForSkeleton(
					ListOfSelectedFunctionNames, ListOfFinalGlobalDeclarations,
					GlobalDependencyList, DependencyListGlobalCoreFunctions);

	GlobalDeclarations GlobalNeededCoreAndSkeleton;
	GlobalNeededCoreAndSkeleton.normalDeclarations = NULL;
	GlobalNeededCoreAndSkeleton.structUnionDeclarations = NULL;
	GlobalNeededCoreAndSkeleton.typedefDeclarations = NULL;

    addGlobalDeclarationListToExistingOne(&GlobalNeededCoreAndSkeleton,
                                          AllGlobalNeededDeclarationsSkeleton);

	addGlobalDeclarationListToExistingOne(&GlobalNeededCoreAndSkeleton,
										  AllGlobalNeededDeclarationsCoreFunctions);

    char * tempGlobalFctDependOutputMultiFile = (char *) malloc(100 * sizeof(char));
    sprintf(tempGlobalFctDependOutputMultiFile, "%stemp_needed_functions_for_global_declarations.out",
            TXLTemporaryFolderMainThread);
    fflush(stdout);
    CallDependency * ListOfNeededFunctionsForGlobals = readListOfNeededFunctionsDeclaration( tempGlobalFctDependOutputMultiFile);
    ListOfStructDefinitions * auxNormalElements;

    while (ListOfNeededFunctionsForGlobals) {
        auxNormalElements = GlobalNeededCoreAndSkeleton.normalDeclarations;
        while (auxNormalElements) {
            if (strstr(auxNormalElements->structDef->el, ListOfNeededFunctionsForGlobals->LOCMarker)) {
             ////   printf("%s == %s", ListOfNeededFunctionsForGlobals->LOCMarker, auxNormalElements->structDef->el);
                removeGlobalDeclaration(&(GlobalNeededCoreAndSkeleton).normalDeclarations, auxNormalElements->headerDefinition);
            }
            auxNormalElements = auxNormalElements->next;
        }
        ListOfNeededFunctionsForGlobals = ListOfNeededFunctionsForGlobals->next;
    }


#ifdef MULTIFILE_VAR_EXTRACTION
    /* Print needed global declaration in the correspondent file */
	printListOfGlobalDeclarationsForOrgan(ListOfFinalGlobalDeclarations, GlobalNeededCoreAndSkeleton,
											tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);
#endif
// TODO LOS DELETE UNUSED
#if 1 //LOSCHANGE23
	/* MULTIFILES */
	/* LOS: add declarations in its respective source file *///DELETE
	printListOfGlobalDeclarations(AllGlobalNeededDeclarationsCoreFunctions,
								  tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);
    /* Print needed global declaration in the correspondent file */
  /*  printListOfGlobalDeclarationsForOrgan(AllGlobalNeededDeclarationsCoreFunctions,
                                          tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);*/
#endif
}

void extractNeededGlobalDeclarationsAndHeaderForSkeletonAndMultiFiles(
		GlobalDeclarations ListOfFinalGlobalDeclarations,
		DependencyList * GlobalDependencyList,
		DependencyList * SkeletonDependenciesOnGlobals,
		DependencyList * DependencyListGlobalCoreFunctions,
		ListOfString * ListOfSkeletonSelectedLOCs,
		ListOfString * ListOfSelectedFunctionNames,
		char * tempSourceCodeGlobalsContent, char * tempHeaderGlobalsContent) {

	GlobalDeclarations AllGlobalNeededDeclarationsSkeleton =
			extractNeededGlobalDeclarationsForSkeleton(
					ListOfSkeletonSelectedLOCs, ListOfFinalGlobalDeclarations,
					GlobalDependencyList, SkeletonDependenciesOnGlobals);

	GlobalDeclarations AllGlobalNeededDeclarationsCoreFunctions =
			extractNeededGlobalDeclarationsForSkeleton(
					ListOfSelectedFunctionNames, ListOfFinalGlobalDeclarations,
					GlobalDependencyList, DependencyListGlobalCoreFunctions);

	GlobalDeclarations GlobalNeededCoreAndSkeleton;
	GlobalNeededCoreAndSkeleton.normalDeclarations = NULL;
	GlobalNeededCoreAndSkeleton.structUnionDeclarations = NULL;
	GlobalNeededCoreAndSkeleton.typedefDeclarations = NULL;

	addGlobalDeclarationListToExistingOne(&GlobalNeededCoreAndSkeleton,
										  AllGlobalNeededDeclarationsSkeleton);
	addGlobalDeclarationListToExistingOne(&GlobalNeededCoreAndSkeleton,
										  AllGlobalNeededDeclarationsCoreFunctions);

	printListOfGlobalDeclarations(GlobalNeededCoreAndSkeleton,
								  tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);

#if 0 /* MULTIFILES */
	/* LOS: add declarations in its respective source file */
	printListOfGlobalDeclarations(AllGlobalNeededDeclarationsCoreFunctions,
								  tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);
#endif
}

int instantiateGPCandidateWithExistingGlobalAndCoreFeature(
		ListOfString * SkeletonSourceCode, ArrayOfStrings SkeletonLOCsArray,
		char * individualFile, DependencyList * ListOfDependenciesForStatements,
		char * GraftInterfaceTempOutput,
		char * skeletonInterfaceSourceCodeOutput,
		char * finalGraftInterfaceFile,
		char * TXLTemporaryFolder) {

	int MappedHostGraftIDs;

	char * finalHostInterfaceOutput;
	finalHostInterfaceOutput = (char *) malloc(500 * sizeof(char));
	sprintf(finalHostInterfaceOutput, "%stemp_interface_source_file.out",
			TXLTemporaryFolder);
	ListOfString * TheListOfTransplantedMarkers = NULL;
	ListOfString * candidateSourceCode = generateNewSkeletonForCandidate(
			SkeletonLOCsArray, SkeletonSourceCode, individualFile,
			ListOfDependenciesForStatements, &TheListOfTransplantedMarkers,
			&MappedHostGraftIDs, TXLTemporaryFolder);
	instantiateGraftSkeletonInInterface(candidateSourceCode,
			GraftInterfaceTempOutput, skeletonInterfaceSourceCodeOutput,
			JustCoreFeatureHeaderName);

	addLocsFromSourceToDestination(skeletonInterfaceSourceCodeOutput,
			SourceOutputCoreFunctionalities, TXLToolsPath);
	addLocsFromSourceToDestination(finalGraftInterfaceFile,
			SkeletonCoreFeatureHeader, TXLToolsPath);

	return MappedHostGraftIDs;
}

void readGPIndividual(GPIndividual * candidate,
		Mapping ** FinalMappingsInIndividual,
		ListOfString ** MappedDeclarations,
		ListOfInt ** ListOfCandidateSelectedLines) {

	char * line;
	line = (char *) malloc(3000 * sizeof(char));

	Mapping * auxCandidateAbstractMappings = candidate->listOfAbstractMappings;

	while (auxCandidateAbstractMappings) {

		addNewMapping(&(*FinalMappingsInIndividual),
				auxCandidateAbstractMappings->source,
				auxCandidateAbstractMappings->destination);
		auxCandidateAbstractMappings = auxCandidateAbstractMappings->next;
	}

	ListOfString * auxDeclMappings = candidate->MappedDeclarations;
	while (auxDeclMappings) {

		strcpy(line, auxDeclMappings->el);

		char * declMarker;
		char * source;
		char * destination;

		declMarker = (char*) malloc(1500 * sizeof(char));
		source = (char*) malloc(1500 * sizeof(char));
		destination = (char*) malloc(1500 * sizeof(char));
		char * token = strtok(line, "@");
		strcpy(declMarker, token);
		token = strtok(NULL, "@");
		strcpy(source, token);
		token = strtok(NULL, "@");

		strcpy(destination, token);
		//last character in destination is end of line .... It is not the case here, since
		//it was generated from the variables in the individual
		//destination[strlen(destination) - 1] = '\0';

		addNewMapping(&(*FinalMappingsInIndividual), source, destination);
		addNewString(&(*MappedDeclarations), declMarker);

		free(declMarker);
		free(source);
		free(destination);

		auxDeclMappings = auxDeclMappings->next;
	}

	ListOfInt * auxSourceCodeLines = candidate->selectedLOCs;
	while (auxSourceCodeLines) {
		addNewInt(&(*ListOfCandidateSelectedLines), auxSourceCodeLines->value);
		auxSourceCodeLines = auxSourceCodeLines->next;
	}
	free(line);
}

ListOfString * returnDependencyListWithIDForAMarkerNewPointersTTT(
		DependencyListWithID * head, char * ID, char ** dependencyLineMarker) {
	ListOfString * dependencyListForMarker = NULL;
	int signal = 0;
	while (head && !signal) {
		if (strstr(ID, head->DependendID)/* !strcmp(head->DependendID, ID)*/) {
			signal = 1;
		} else {
			head = head->next;
		}
	}
	if (signal) {
		free(*dependencyLineMarker);
		*dependencyLineMarker = (char *) malloc(
				(sizeof(head->Statement) + 1) * sizeof(char));
		strcpy(*dependencyLineMarker, head->Statement);
		dependencyListForMarker = copyCompleteListOfString(
				head->ListOfDependencies);
	}
	return dependencyListForMarker;
}

DependencyList * generateAdditionalsDeclarationsDependenciesForAbstractInstantiationsToDonorIDs(
		DependencyListWithID * DonorIdsDeclarationDependences,
		Mapping * FinalMappingsInGraft) {

	DependencyList * additionalDependencies = NULL;

	Mapping * auxMapping = FinalMappingsInGraft;

	while (auxMapping) {
		char * dependencyLineMarker = NULL;

		ListOfString * dependencyListForMarker = NULL;
		DependencyListWithID * auxDependList = DonorIdsDeclarationDependences;

		while (auxDependList) {
			if (strstr(auxMapping->destination,
					auxDependList->DependendID)/* !strcmp(head->DependendID, ID)*/) {
				dependencyLineMarker = (char *) malloc(
						1000 * sizeof(char));
				strcpy(dependencyLineMarker, auxDependList->Statement);
				dependencyListForMarker = copyCompleteListOfString(
						auxDependList->ListOfDependencies);

				addNewStatement(&additionalDependencies, dependencyLineMarker);

				while (dependencyListForMarker) {
					addNewDependency(&additionalDependencies,
							dependencyLineMarker, dependencyListForMarker->el);
					dependencyListForMarker = dependencyListForMarker->next;
				}

			}
			auxDependList = auxDependList -> next;
		}

		/*
		ListOfString * auxListOfStrings =
				returnDependencyListWithIDForAMarkerNewPointers(
						DonorIdsDeclarationDependences, auxMapping->destination,
						&dependencyLineMarker);

		if (auxListOfStrings && dependencyLineMarker) {

			addNewStatement(&additionalDependencies, dependencyLineMarker);

			while (auxListOfStrings) {
				addNewDependency(&additionalDependencies, dependencyLineMarker,
						auxListOfStrings->el);
				auxListOfStrings = auxListOfStrings->next;
			}
		}
		*/

		auxMapping = auxMapping->next;
	}

	return additionalDependencies;
}

ListOfString * generateNewSkeletonForCandidateFromGPIndividual(
		ArrayOfStrings SkeletonLOCsArray, ListOfString * SkeletonSourceCode,
		GPIndividual * individual,
		DependencyList * ListOfDependenciesForStatements,
		ListOfString ** TheListOfTransplantedMarkers,
		DependencyListWithID * dependencyListForAbstract,
		char * TXLTemporaryFolder) {

	Mapping * FinalMappingsInIndividual = NULL;
	ListOfString * MappedDeclarations = NULL;
	ListOfInt * ListOfCandidateSelectedLines = NULL;

	//mapped declarations are declarations from the skeleton, which are mapped to variables from the host,
	//so there is no need to transplant the variable declarations on which these are dependent
	readGPIndividual(individual, &FinalMappingsInIndividual,
			&MappedDeclarations, &ListOfCandidateSelectedLines);

	DependencyList * additionalDependenciesForAbstract =
			generateAdditionalsDeclarationsDependenciesForAbstractInstantiationsToDonorIDs(
					dependencyListForAbstract, FinalMappingsInIndividual);

	ListOfString * neededMarkersForTransplant = NULL;

	//add all the line markers from the SkeletonLOC array, at the position selected by GP
	ListOfInt * aux = ListOfCandidateSelectedLines;
	while (aux) {
		if (!searchStringInListOfStrings(neededMarkersForTransplant,
				SkeletonLOCsArray.array[aux->value])) {
			addNewString(&neededMarkersForTransplant,
					SkeletonLOCsArray.array[aux->value]);
		}
		aux = aux->next;
	}

	//add the return marker, since it is the return of the interface and must always be presented
	addNewString(&neededMarkersForTransplant, RETURN_MARKER);

	ListOfString * auxNeededMarkers = neededMarkersForTransplant;

	//generate the complete list of dependencies into new one
	DependencyList * completeListOfDependencies = NULL;
	addDependencyListToAnExistingOne(&completeListOfDependencies,
			ListOfDependenciesForStatements);
	addDependencyListToAnExistingOne(&completeListOfDependencies,
			additionalDependenciesForAbstract);

	//for all added line markers, add the one from dependency, if they are not mapped
	//BUGGGGGGGGGGG!!!!!!!!!!!
	// TODO: check here
	while (auxNeededMarkers) {
		//memory leak!!! returnDependencyForAMarker makes new one, while adding adds also
		ListOfString * neededDepsForCurrent =
				returnDependencyForAMarkerNewPointers(
						completeListOfDependencies, auxNeededMarkers->el);
		if (neededDepsForCurrent) {
			ListOfString * auxListString = neededDepsForCurrent;
			//maybe this is infinite.. it should be checked that the new marker is not already in the list
			while (auxListString) {
				if (!searchStringInListOfStrings(MappedDeclarations,
						auxListString->el)
						&& !searchStringInListOfStrings(
								neededMarkersForTransplant,
								auxListString->el)) {
					addNewString(&neededMarkersForTransplant,
							auxListString->el);
				}
				auxListString = auxListString->next;
			}
			freeListOfStrings(&neededDepsForCurrent);
		}
		auxNeededMarkers = auxNeededMarkers->next;
	}

	*TheListOfTransplantedMarkers = neededMarkersForTransplant;

	ListOfString * candidateLOCs = NULL;
	ListOfString * auxSkeletonCode = SkeletonSourceCode;

	while (auxSkeletonCode) {
		//add some marker for LABEL ABST!!!, not like this
		if (!strstr(auxSkeletonCode->el, "/*")
				&& !strstr(auxSkeletonCode->el, "//")
				&& !strstr(auxSkeletonCode->el, "LABEL_ABST")
				&& !strstr(auxSkeletonCode->el, "break")) {
			addNewString(&candidateLOCs, auxSkeletonCode->el);
		} else {
			auxNeededMarkers = neededMarkersForTransplant;
			//add just once every line, even if it is needed for more then one declaration
			int signal = 0;
			while (auxNeededMarkers && !signal) {
				if (strstr(auxSkeletonCode->el, auxNeededMarkers->el)) {
					//the current line in skeleton was identified, so it should be added just once
					signal = 1;
					addNewString(&candidateLOCs, auxSkeletonCode->el);
					//printf("%s\n", auxSkeletonCode->el);

				}
				auxNeededMarkers = auxNeededMarkers->next;
			}
		}
		auxSkeletonCode = auxSkeletonCode->next;
	}

	//print the initial function file, for individual instantiator
	char * initialFunctionFile;
	initialFunctionFile = (char *) malloc(500 * sizeof(char));
	sprintf(initialFunctionFile, "%stemp_individual_for_instantiation.out",
			TXLTemporaryFolder);

	printAListOfStrings(candidateLOCs, initialFunctionFile);

	//print the initial mappings file, for individual instantiator
	char * initialMappingsFile;
	initialMappingsFile = (char *) malloc(500 * sizeof(char));

	sprintf(initialMappingsFile,
			"%stemp_mappings_for_candidate_instantiation.out",
			TXLTemporaryFolder);

	FILE * symbolTableResults = fopen(initialMappingsFile, "w");
	Mapping * currentListOfMappings = FinalMappingsInIndividual;

	while (currentListOfMappings) {
	    if(strchr(currentListOfMappings->destination, '\"')){
            char *formatedDestinationTypeString = (char *) malloc((strlen(currentListOfMappings->destination) + 4) * sizeof(char));
            //sprintf(formatedDestinationTypeString,"\\%s \\\"", strtok(currentListOfMappings->destination, "\"");
            sprintf(formatedDestinationTypeString,"\\\"%s \\\"", readSubstring("\"",currentListOfMappings->destination, "\""));
            fprintf(symbolTableResults, "\"%s\" \"%s\" ", currentListOfMappings->source,
                formatedDestinationTypeString);
	    }
        else
            fprintf(symbolTableResults, "\"%s\" \"%s\" ", currentListOfMappings->source, currentListOfMappings->destination);

        currentListOfMappings = currentListOfMappings->next;
	}
	fclose(symbolTableResults);

	ListOfString * candidateLOCsInstantiated =
			instantiateCurrentIndividualInSkeleton(initialFunctionFile,
					initialMappingsFile, TXLTemporaryFolder);
	return candidateLOCsInstantiated;
}

/* LOS: function rewritten to support multifiles */
void instantiateGPCandidateWithExistingGlobalAndCoreFeatureGromGPIndividual(
		ListOfString * SkeletonSourceCode, ArrayOfStrings SkeletonLOCsArray,
		GPIndividual * individual,
		DependencyList * ListOfDependenciesForStatements,
		char * GraftInterfaceTempOutput,
		char * skeletonInterfaceSourceCodeOutput,
		char * finalGraftInterfaceFile,
		DependencyListWithID * dependencyListForAbstract,
		char * TXLTemporaryFolder, ListOfString * listOfSourceFiles) {

	//Mapped Host Graft IDs used here just for compiliance with the instantiate a candidate with just its own needed
	//global declarations, where this will be also changed

	char * finalHostInterfaceOutput;
	finalHostInterfaceOutput = (char *) malloc(500 * sizeof(char));
	sprintf(finalHostInterfaceOutput, "%stemp_interface_source_file.out",
			TXLTemporaryFolder);
	ListOfString * TheListOfTransplantedMarkers = NULL;
	fflush(stdout);
	//bug place!!!!
	ListOfString * candidateSourceCode =
			generateNewSkeletonForCandidateFromGPIndividual(SkeletonLOCsArray,
															SkeletonSourceCode, individual,
															ListOfDependenciesForStatements,
															&TheListOfTransplantedMarkers, dependencyListForAbstract,
															TXLTemporaryFolder);

	fflush(stdout);
	instantiateGraftSkeletonInInterface(candidateSourceCode,
										GraftInterfaceTempOutput, skeletonInterfaceSourceCodeOutput,
										JustCoreFeatureHeaderName);
	fflush(stdout);

	char * localSourceOutputCoreFunctionalities = (char *) malloc (1000 * sizeof(char));
	sprintf(localSourceOutputCoreFunctionalities, "%sInterfaceCoreFunctionality.c", TXLTemporaryFolder);
/* LOS: Copy LOCs from NeedSourceCode.c to InterfaceWithCoreFeature.c*/
	addLocsFromSourceToDestination(skeletonInterfaceSourceCodeOutput,
								   localSourceOutputCoreFunctionalities, TXLToolsPath);

	char * localSkeletonCoreFeatureHeader = (char *) malloc (1000 * sizeof(char));
	sprintf(localSkeletonCoreFeatureHeader, "%sNeededFunctionsHeader.h", TXLTemporaryFolder);



	//addLocsFromSourceToDestination(finalGraftInterfaceFile,
			//					   localSkeletonCoreFeatureHeader, TXLToolsPath);
/* TODO DELETE rewrite the file copy to TransplantResultLocation
	ListOfString * listOfSourceFiles = readListOfStringFromFileAsWords(listOfSourceFilesTargetPath);

	char * sourceFilesOutputPath = (char *) malloc(1000 * sizeof(char));
	char * sourceFilesInputPath = (char *) malloc(1000 * sizeof(char));
	char * currentSourceFile = (char *) malloc(1000 * sizeof(char));

	while(listOfSourceFiles) {

		strcpy(currentSourceFile, listOfSourceFiles->el);

		sprintf(sourceFilesInputPath, "%s%s", TXLTemporaryMultiFileFolder,currentSourceFile );
		sprintf(sourceFilesOutputPath, "%s%s", TransplantResultLocation, currentSourceFile);
		FILE * fout = fopen(sourceFilesOutputPath, "w");
		fclose(fout);
		addLocsFromSourceToDestination(sourceFilesOutputPath, sourceFilesInputPath, TXLToolsPath);
		listOfSourceFiles = listOfSourceFiles->next;
	}
	//HERE write to source files
	addLocsFromSourceToDestination(finalGraftInterfaceFile,
								   localSkeletonCoreFeatureHeader, TXLToolsPath);
*/


//HERE write to interface
	addLocsFromSourceToDestination(finalGraftInterfaceFile,
								   localSkeletonCoreFeatureHeader, TXLToolsPath);

	fflush(stdout);
}
void extractFunctionMarkers(char * sourceFile, char * outputFile,
		char * TXLProgsPath) {
	char * commandTXL;
	commandTXL = (char *) malloc(500 * sizeof(char));
#ifdef DEBUGING2
	printf("\t\t[TXL] ExtractAllFunctionsNameInAFile.x >> Extract All Functions Name In A File\n");
#endif
	sprintf(commandTXL, "%sExtractAllFunctionsNameInAFile.x %s %s %s",
			TXLProgsPath, sourceFile, outputFile, ConsoleStderrOutput);
	int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR! ExtractAllFunctionsNameInAFile\n");
		printf("\t%s\n", commandTXL);
		system("open ErroFile.out");
		exit(1);
	}
#ifdef DEBUGING
	else
        printf("\t\t\t|>> temp_needed_functions_markers.out\n");
#endif
	free(commandTXL);
}

ListOfString * extractFunctionsAsMarkersFromSourceFile(char * sourceFile, char * TXLTemporaryFolder) {
#ifdef DEBUGING2
    printf("\t\tExtracting functions as markers from source file\n");
#endif
	char * outputTempFile;
	outputTempFile = (char *) malloc(500 * sizeof(char));
	sprintf(outputTempFile, "%stemp_needed_functions_markers.out",
			TXLTemporaryFolder);

  //LOS TEMP: remove comment
	extractFunctionMarkers(sourceFile, outputTempFile, TXLToolsPath);
	ListOfString * result = returnListOfStringFromMarkersFile(outputTempFile);

	return result;
}

//TODO LOS DELETE UNUSED
void extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCs(
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
		char * TXLTemporaryFolder) {
	//needed for extraction of global dependencies for core feature
	ListOfString * FinalListOfTransplantedFunctionsAsMarkersOld = NULL;
	//first add the feature markerd for extraction, since globals for this too must be added
	char * GraftFunctionMarker;
	GraftFunctionMarker = (char *) malloc(500 * sizeof(char));
	sprintf(GraftFunctionMarker, "/* %s */", GraftFunctionName);
	addNewString(&FinalListOfTransplantedFunctionsAsMarkersOld,
				 GraftFunctionMarker);

	//to be checked not to add all functions for all globals, but just for one possible to be transplanted!!!
	CallDependency * ListOfNeededFunctionsForGlobals =
			extractNeededFunctionsForGlobals(ListOfFinalGlobalDeclarations,
                                             outputFileGlobalDependenciesOnFunctions);

	extractCoreFunctionsCalledInIndividual(ListOfNeededFunctionsForAllLOCs,
										   candidateSourceCode, SkeletonCoreFeatureHeader,
										   sourceOutputCoreFunctionality,
										   &FinalListOfTransplantedFunctionsAsMarkersOld,
										   ListOfNeededFunctionsForGlobals, TXLTemporaryFolder);

	fflush(stdout);

	ListOfString * FinalListOfTransplantedFunctionsAsMarkers =
			extractFunctionsAsMarkersFromSourceFile(
					sourceOutputCoreFunctionality, TXLTemporaryFolder);

	//for the source core output file extract all the called files
	//this will be the final list of transplated functions as markers

	//ListOfString * TempListOfStrings = returnListOfStringFromMarkersFile(tempListOfMarkers);

	//FOR ALL EXTRACTED FUNCTIONS, ADD THE DEPENDENCIES!!!

	fflush(stdout);
	//maybe HERE!!!!
	DependencyList * DependencyListGlobalCoreFunctions =
			extractDependencyGlobalListForCoreFunctions(
					SourceOutputCoreFunctionalities, tempGlobalDeclarations,
					definedGlobalTypesAndVariablesFile, TXLTemporaryFolder);
	char * tempHeaderGlobalsContent;
	tempHeaderGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempHeaderGlobalsContent, "%stemp_header_decl_for_globals.out",
			TXLTemporaryFolder);
	char * tempSourceCodeGlobalsContent;
	tempSourceCodeGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempSourceCodeGlobalsContent, "%stemp_source_for_globals.out",
			TXLTemporaryFolder);

	fflush(stdout);

	extractNeededGlobalDeclarationsAndHeaderForSkeletonAndInterface(
			ListOfFinalGlobalDeclarations, GlobalDependencyList,
			SkeletonDependenciesOnGlobals, DependencyListGlobalCoreFunctions,
			TheListOfTransplantedMarkers,
			FinalListOfTransplantedFunctionsAsMarkers,
			tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);

	fflush(stdout);

/*	addLocsFromSourceToDestination(sourceOutputCoreFunctionality,
								   tempSourceCodeGlobalsContent, TXLToolsPath);
	addLocsFromSourceToDestination(SkeletonCoreFeatureHeader,
								   tempHeaderGlobalsContent, TXLToolsPath);*/
}

#ifdef MAC_OSX

void callCoreFeatureGlobalDependencySolverByGlobal(char * tempSkeletonFile,
												   char * tempGlobalDeclarations, char * tempGlobalTypeVarDecl,
												   char * TXLProgsPath, char * temporaryOutputFile) {
	char * commandTXL;
	commandTXL = (char *) malloc(1500 * sizeof(char));
	sprintf(commandTXL,
			"ulimit -s 65353 && %sGlobalVarTypesDeclDependencyCOREFUNCTIONS.x %s %s %s %s %s",
			TXLProgsPath, tempSkeletonFile, tempGlobalDeclarations,
			tempGlobalTypeVarDecl, temporaryOutputFile, ConsoleStderrOutput);
  /// printf("\t[TXL] GlobalVarTypesDeclDependencyCOREFUNCTIONS.x >> Extract global var types declaration dependency core functions\n");
    int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR! GlobalVarTypesDeclDependencyCOREFUNCTIONS.x\n");
		printf("\t%s\n", commandTXL);
		system("open ErrorFile.out");
		exit(1);
	}else{
    ///    printf("\t\t|>> partial_core_function_global_dependencies.out\n");
	}
	free(commandTXL);
}

DependencyList * extractDependencyGlobalListByGlobal(GlobalDeclarations ListOfFinalGlobalDeclarations,
                                                     char * coreFunctionSourceFile, char * globalDeclarationFile,
                                                     char * globalDefinedTypesVarFile, char * TXLTemporaryFolder) {

    char *tempOutputFile;
    tempOutputFile = (char *) malloc(500 * sizeof(char));
    sprintf(tempOutputFile, "%stemp_core_function_global_dependencies.out",
            TXLTemporaryFolder);

    char * partialOutputFile;
    partialOutputFile = (char *) malloc(500 * sizeof(char));


    char *partialGlobalVariableDeclarationsFile = NULL;
    partialGlobalVariableDeclarationsFile = (char *) malloc(500 * sizeof(char));
    sprintf(partialGlobalVariableDeclarationsFile, "%spartial_global_variable_declarations.out", TXLTemporaryMultiFileFolder);
    createFile(partialGlobalVariableDeclarationsFile);

    fflush(stdout);
    ListOfStructDefinitions *auxDeclHeader = ListOfFinalGlobalDeclarations.normalDeclarations;

    DependencyList * skeletonGlobalDependencies = NULL;


#if 1 /* ALL  EXECUTION */
    sprintf(partialOutputFile, "%spartial_core_function_global_dependencies.out",
			TXLTemporaryFolder);

  ///  printf("\t\t[TXL] GlobalVarTypesDeclDependencyCOREFUNCTIONS.x >> Extract global var types declaration dependency core functions\n");
//#if  !defined(FAST_RUNNING) //LOSCHANGE23
    callCoreFeatureGlobalDependencySolver(coreFunctionSourceFile,
			globalDeclarationFile, globalDefinedTypesVarFile, TXLToolsPath,
			tempOutputFile);
//#endif
	fflush(stdout);

	skeletonGlobalDependencies = readDependencyListFromFile(
			tempOutputFile);
#else
    sprintf(partialOutputFile, "%spartial_core_function_global_dependencies.out",
            TXLTemporaryMultiFileFolder);

    DependencyList * currentSkeletonGlobalDependencies = NULL;
    while (auxDeclHeader){
        ListOfString * auxStruct = auxDeclHeader->structDef;
        addAStringsInTheFile(auxStruct->el, partialGlobalVariableDeclarationsFile);
        ///printf("\t%s\n",readSubstring("/* ", auxDeclHeader->structDef->el," */"));
        auxStruct = auxStruct->next;
        while(auxStruct){
            addAStringsInTheEndFile(auxStruct->el, partialGlobalVariableDeclarationsFile);
            auxStruct = auxStruct->next;
        }
        callCoreFeatureGlobalDependencySolverByGlobal(coreFunctionSourceFile,
                                                      partialGlobalVariableDeclarationsFile, globalDefinedTypesVarFile, TXLToolsPath,
                                                      partialOutputFile);
        currentSkeletonGlobalDependencies = readDependencyListFromFile(
                partialOutputFile);
        addDependencyListToAnExistingOne(&skeletonGlobalDependencies,
                                         currentSkeletonGlobalDependencies);

        auxDeclHeader = auxDeclHeader->next;
    }

    free(auxDeclHeader);
    fflush(stdout);
    removeAFileFromADirectory(partialOutputFile);
    //TODO fix problem here. Repeting function
    printADependencyList(skeletonGlobalDependencies, tempOutputFile);
#endif
    return skeletonGlobalDependencies;
}
#if 0 // TESTLOS
DependencyList * extractDependencyGlobalListByGlobal(GlobalDeclarations ListOfFinalGlobalDeclarations,
													 char * coreFunctionSourceFile, char * globalDeclarationFile,
													 char * globalDefinedTypesVarFile, char * TXLTemporaryFolder) {

	char *tempOutputFile;
	tempOutputFile = (char *) malloc(500 * sizeof(char));
	sprintf(tempOutputFile, "%stemp_core_function_global_dependencies.out",
			TXLTemporaryFolder);

	char *partialOutputFile;
	partialOutputFile = (char *) malloc(500 * sizeof(char));
	sprintf(partialOutputFile, "%spartial_core_function_global_dependencies.out",
			TXLTemporaryFolder);

	char *partialGlobalVariableDeclarationsFile = NULL;
	partialGlobalVariableDeclarationsFile = (char *) malloc(500 * sizeof(char));
	sprintf(partialGlobalVariableDeclarationsFile, "%spartial_global_variable_declarations.out",
			TXLTemporaryMultiFileFolder);
	createFile(partialGlobalVariableDeclarationsFile);

	fflush(stdout);
	ListOfStructDefinitions *auxDeclHeader = ListOfFinalGlobalDeclarations.normalDeclarations;
	ListOfStructDefinitions *neededDeclHeader = NULL;
	/*while (auxDeclHeader){
		if(searchStringInListOfStrings(ListOfSourceHeaderFilesNeeded, auxDeclHeader->file))
			addNewStructDefinition(&neededDeclHeader, auxDeclHeader->structDef, auxDeclHeader->headerDefinition, auxDeclHeader->file, auxDeclHeader->occurrenceLine);
		auxDeclHeader = auxDeclHeader->next;
	}*/
	DependencyList * skeletonGlobalDependencies = NULL;
	DependencyList * currentSkeletonGlobalDependencies = NULL;

	printf("[TXL] GlobalVarTypesDeclDependencyCOREFUNCTIONS >> Extract global declaration dependency\n");
	int agroup_globals;
	while (neededDeclHeader) {
		agroup_globals = 0;
		while(agroup_globals < 30 && neededDeclHeader){
		ListOfString *auxStruct = neededDeclHeader->structDef;
			if(agroup_globals == 0)
				addAStringsInTheFile(auxStruct->el, partialGlobalVariableDeclarationsFile);
			else
				addAStringsInTheEndFile(auxStruct->el, partialGlobalVariableDeclarationsFile);

			printf("\t%s\n", readSubstring("/* ", neededDeclHeader->structDef->el, " */"));
			auxStruct = auxStruct->next;
			while (auxStruct) {
				addAStringsInTheEndFile(auxStruct->el, partialGlobalVariableDeclarationsFile);
				auxStruct = auxStruct->next;
			}
			neededDeclHeader = neededDeclHeader->next;
			agroup_globals++;
		}
		callCoreFeatureGlobalDependencySolverByGlobal(coreFunctionSourceFile,
													  partialGlobalVariableDeclarationsFile, globalDefinedTypesVarFile, TXLToolsPath,
													  partialOutputFile);
		currentSkeletonGlobalDependencies = readDependencyListFromFile(
				partialOutputFile);
	/*	addDependencyListToAnExistingOne(&skeletonGlobalDependencies,
										 currentSkeletonGlobalDependencies);*/

		addDependencyListToAnExistingOne(&skeletonGlobalDependencies, currentSkeletonGlobalDependencies);
		agroup_globals = 0;
	}
	free(auxDeclHeader);
	free(neededDeclHeader);
	fflush(stdout);
	removeAFileFromADirectory(partialOutputFile);
	//TODO fix problem here. Repeting function
	printADependencyList(skeletonGlobalDependencies, tempOutputFile);

	//return skeletonGlobalDependencies;
	return skeletonGlobalDependencies;
}
#endif

#endif


DependencyList * extractDependencyGlobal(GlobalDeclarations ListOfFinalGlobalDeclarations,
													 char * coreFunctionSourceFile, char * globalDeclarationFile,
													 char * globalDefinedTypesVarFile, char * TXLTemporaryFolder) {

	char *tempOutputFile;
	tempOutputFile = (char *) malloc(500 * sizeof(char));
	sprintf(tempOutputFile, "%stemp_core_function_global_dependencies.out",
			TXLTemporaryFolder);

	fflush(stdout);
	DependencyList * skeletonGlobalDependencies = NULL;

	callCoreFeatureGlobalDependencySolverByGlobal(coreFunctionSourceFile,
													  globalDeclarationFile, globalDefinedTypesVarFile, TXLToolsPath,
													  tempOutputFile);

	skeletonGlobalDependencies = readDependencyListFromFile(tempOutputFile);

	return skeletonGlobalDependencies;
}
void extractNeededFunctionsAndGlobalDeclarations(
		char * sourceOutputCoreFunctionality,
		GlobalDeclarations ListOfFinalGlobalDeclarations,
		DependencyList * GlobalDependencyList,
		DependencyList * SkeletonDependenciesOnGlobals,
		char * tempGlobalDeclarations,
		char * definedGlobalTypesAndVariablesFile,
		ListOfString * TheListOfTransplantedMarkers,
		char * TXLTemporaryFolder) {
	//needed for extraction of global dependencies for core feature
	ListOfString * FinalListOfTransplantedFunctionsAsMarkers = NULL;
	//first add the feature markerd for extraction, since globals for this too must be added
	char * GraftFunctionMarker;
	GraftFunctionMarker = (char *) malloc(500 * sizeof(char));
	sprintf(GraftFunctionMarker, "/* %s */", GraftFunctionName);
	addNewString(&FinalListOfTransplantedFunctionsAsMarkers,
				 GraftFunctionMarker);

	fflush(stdout);

	DependencyList * DependencyListGlobalCoreFunctions =
			extractDependencyGlobalListForCoreFunctions(
					SourceOutputCoreFunctionalities, tempGlobalDeclarations,
					definedGlobalTypesAndVariablesFile, TXLTemporaryFolder);
	char * tempHeaderGlobalsContent;
	tempHeaderGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempHeaderGlobalsContent, "%stemp_header_decl_for_globals.out",
			TXLTemporaryFolder);
	char * tempSourceCodeGlobalsContent;
	tempSourceCodeGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempSourceCodeGlobalsContent, "%stemp_source_for_globals.out",
			TXLTemporaryFolder);

	fflush(stdout);

	extractNeededGlobalDeclarations(
			ListOfFinalGlobalDeclarations, GlobalDependencyList,
			SkeletonDependenciesOnGlobals, DependencyListGlobalCoreFunctions,
			TheListOfTransplantedMarkers);

	fflush(stdout);

	addLocsFromSourceToDestination(sourceOutputCoreFunctionality,
								   tempSourceCodeGlobalsContent, TXLToolsPath);
	addLocsFromSourceToDestination(SkeletonCoreFeatureHeader,
								   tempHeaderGlobalsContent, TXLToolsPath);
}

void extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsFromSkeleton(
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
		char * TXLTemporaryFolder) {
	//needed for extraction of global dependencies for core feature
	ListOfString * FinalListOfTransplantedFunctionsAsMarkersOld = NULL;
	//first add the feature markerd for extraction, since globals for this too must be added
	char * GraftFunctionMarker;
	GraftFunctionMarker = (char *) malloc(500 * sizeof(char));
	sprintf(GraftFunctionMarker, "/* %s */", GraftFunctionName);
	addNewString(&FinalListOfTransplantedFunctionsAsMarkersOld,
			GraftFunctionMarker);

	//to be checked not to add all functions for all globals, but just for one possible to be transplanted!!!
	CallDependency * ListOfNeededFunctionsForGlobals =
			extractNeededFunctionsForGlobals(ListOfFinalGlobalDeclarations,
					outputFileGlobalDependenciesOnFunctions);

	extractCoreFunctionsCalledInIndividual(ListOfNeededFunctionsForAllLOCs,
			candidateSourceCode, SkeletonCoreFeatureHeader,
			sourceOutputCoreFunctionality,
			&FinalListOfTransplantedFunctionsAsMarkersOld,
			ListOfNeededFunctionsForGlobals, TXLTemporaryFolder);

	fflush(stdout);
#ifdef NEW_FUNCTIONS_FILE
    //LOS TODO Temp allfunctions extracted to solve problem with ExtractAllFunctionsNameInAFile.x
    char * allFunctionExtracted;
    allFunctionExtracted = (char *) malloc(500 * sizeof(char));
    sprintf(allFunctionExtracted, "%sNeededSourceCode.c",
            TXLTemporaryFolderMainThread);

    ListOfString * FinalListOfTransplantedFunctionsAsMarkers =
            extractFunctionsAsMarkersFromSourceFile(
                    allFunctionExtracted, TXLTemporaryFolder);
#else
	ListOfString * FinalListOfTransplantedFunctionsAsMarkers =
			extractFunctionsAsMarkersFromSourceFile(
					sourceOutputCoreFunctionality, TXLTemporaryFolder);
#endif

	//for the source core output file extract all the called files
	//this will be the final list of transplated functions as markers

	//ListOfString * TempListOfStrings = returnListOfStringFromMarkersFile(tempListOfMarkers);

	//FOR ALL EXTRACTED FUNCTIONS, ADD THE DEPENDENCIES!!!

	fflush(stdout);
	//maybe HERE!!!!

#if 0
	#ifdef EXTRACT_DEPENDENCY_GLOBAL_LIST_FROM_VEIN
	DependencyList * DependencyListGlobalCoreFunctions =
			extractDependencyGlobalListByGlobal(ListOfFinalGlobalDeclarations,
					sourceOutputCoreFunctionality, tempGlobalDeclarations,
					definedGlobalTypesAndVariablesFile, TXLTemporaryFolder);
	#else
	char * tempOutputFile;
	tempOutputFile = (char *) malloc(500 * sizeof(char));
	sprintf(tempOutputFile, "%stemp_core_function_global_dependencies.out",
			TXLTemporaryFolder);
	DependencyList * DependencyListGlobalCoreFunctions  = readDependencyListFromFile(
			tempOutputFile);
	#endif

#else
	DependencyList * DependencyListGlobalCoreFunctions =
			extractDependencyGlobalListForCoreFunctions(
					sourceOutputCoreFunctionality, tempGlobalDeclarations,
					definedGlobalTypesAndVariablesFile, TXLTemporaryFolder);
#endif
	char * tempHeaderGlobalsContent;
	tempHeaderGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempHeaderGlobalsContent, "%stemp_header_decl_for_globals.out",
			TXLTemporaryFolder);
	char * tempSourceCodeGlobalsContent;
	tempSourceCodeGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempSourceCodeGlobalsContent, "%stemp_source_for_globals.out",
			TXLTemporaryFolder);

	fflush(stdout);

	extractNeededGlobalDeclarationsAndHeaderForSkeletonAndInterface(
			ListOfFinalGlobalDeclarations, GlobalDependencyList,
			SkeletonDependenciesOnGlobals, DependencyListGlobalCoreFunctions,
			TheListOfTransplantedMarkers,
			FinalListOfTransplantedFunctionsAsMarkers,
			tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);

}

void extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsFromOrgan( ListOfString * ListOfSourceHeaderFilesNeeded,
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
		char * TXLTemporaryFolder) {
	//needed for extraction of global dependencies for core feature
	/*ListOfString * FinalListOfTransplantedFunctionsAsMarkersOld = NULL;
	//first add the feature markerd for extraction, since globals for this too must be added
	char * GraftFunctionMarker;
	GraftFunctionMarker = (char *) malloc(500 * sizeof(char));*/
///	sprintf(GraftFunctionMarker, "/* %s */", GraftFunctionName);
	/*addNewString(&FinalListOfTransplantedFunctionsAsMarkersOld,
				 GraftFunctionMarker);
    /*call once
	//to be checked not to add all functions for all globals, but just for one possible to be transplanted!!!
	CallDependency * ListOfNeededFunctionsForGlobals =
			extractNeededFunctionsForGlobals(ListOfFinalGlobalDeclarations,
											 outputFileGlobalDependenciesOnFunctions);

	extractCoreFunctionsCalledInIndividual(ListOfNeededFunctionsForAllLOCs,
										   candidateSourceCode, SkeletonCoreFeatureHeader,
										   sourceOutputCoreFunctionality,
										   &FinalListOfTransplantedFunctionsAsMarkersOld,
										   ListOfNeededFunctionsForGlobals, TXLTemporaryFolder);*/

	fflush(stdout);
#ifdef NEW_FUNCTIONS_FILE
	//LOS TODO Temp allfunctions extracted to solve problem with ExtractAllFunctionsNameInAFile.x
    char * allFunctionExtracted;
    allFunctionExtracted = (char *) malloc(500 * sizeof(char));
    sprintf(allFunctionExtracted, "%sNeededSourceCode.c",
            TXLTemporaryFolderMainThread);

    ListOfString * FinalListOfTransplantedFunctionsAsMarkers =
            extractFunctionsAsMarkersFromSourceFile(
                    allFunctionExtracted, TXLTemporaryFolder);
#else
	ListOfString * FinalListOfTransplantedFunctionsAsMarkers =
			extractFunctionsAsMarkersFromSourceFile(
					sourceOutputCoreFunctionality, TXLTemporaryFolder);
#endif

	//for the source core output file extract all the called files
	//this will be the final list of transplanted functions as markers

	//ListOfString * TempListOfStrings = returnListOfStringFromMarkersFile(tempListOfMarkers);

	//FOR ALL EXTRACTED FUNCTIONS, ADD THE DEPENDENCIES!!!

	fflush(stdout);
	//maybe HERE!!!!

//#ifdef	ADD_FUNCTION_IN_A_SINGLE_FILE
    /* Extract function global dependency */
	DependencyList * DependencyListGlobalCoreFunctions =
			extractDependencyGlobalListByGlobal(ListOfFinalGlobalDeclarations,
												sourceOutputCoreFunctionality, tempGlobalDeclarations,
												definedGlobalTypesAndVariablesFile, TXLTemporaryFolder);

	/*DependencyList * DependencyListGlobalCoreFunctions = extractDependencyGlobalListByGlobal(ListOfSourceHeaderFilesNeeded, ListOfFinalGlobalDeclarations,
												sourceOutputCoreFunctionality, tempGlobalDeclarations,
												definedGlobalTypesAndVariablesFile, TXLTemporaryFolder);*/
//#else
/*	DependencyList * DependencyListGlobalCoreFunctions = extractDependencyGlobal(ListOfFinalGlobalDeclarations,
							sourceOutputCoreFunctionality, tempGlobalDeclarations,
							definedGlobalTypesAndVariablesFile, TXLTemporaryFolder);
*/
//#endif

/*#ifdef MAC_OSX
	//TODO Delete
	#ifdef DEBUGING
	DependencyList * DependencyListGlobalCoreFunctions =
			extractDependencyGlobalListByGlobal(ListOfFinalGlobalDeclarations,
												sourceOutputCoreFunctionality, tempGlobalDeclarations,
												definedGlobalTypesAndVariablesFile, TXLTemporaryFolder);

	#else
	char * tempOutputFile;
	tempOutputFile = (char *) malloc(500 * sizeof(char));
	sprintf(tempOutputFile, "%stemp_core_function_global_dependencies.out",
			TXLTemporaryFolder);
	DependencyList * DependencyListGlobalCoreFunctions  = readDependencyListFromFile(
			tempOutputFile);
	#endif
#else

	DependencyList * DependencyListGlobalCoreFunctions =
			extractDependencyGlobalListForCoreFunctions(
					sourceOutputCoreFunctionality, tempGlobalDeclarations,
					definedGlobalTypesAndVariablesFile, TXLTemporaryFolder);
#endif*/

	char * tempHeaderGlobalsContent;
	tempHeaderGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempHeaderGlobalsContent, "%stemp_header_decl_for_globals.out",
			TXLTemporaryFolder);
	char * tempSourceCodeGlobalsContent;
	tempSourceCodeGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempSourceCodeGlobalsContent, "%stemp_source_for_globals.out",
			TXLTemporaryFolder);

	fflush(stdout);

	extractNeededGlobalDeclarationsAndHeaderForOrgan(
			ListOfFinalGlobalDeclarations, GlobalDependencyList,
			SkeletonDependenciesOnGlobals, DependencyListGlobalCoreFunctions,
			TheListOfTransplantedMarkers,
			FinalListOfTransplantedFunctionsAsMarkers,
			tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);


}



#if 0 /* MULTIHEADER FILES*/
void extractNeededFunctionsAndGlobalDeclarations( ListOfString * SkeletonSourceCode,
												  CallDependency * ListOfNeededFunctionsForAllLOCs,
												  DependencyList * SkeletonDependenciesOnGlobals,
												  char * GraftFunctionName,
												  char * GlobalFctDependOutput,
												  char * listOfSourceFilesTargetPath,
												  GlobalDeclarations ListOfFinalGlobalDeclarationsMultiFiles,
												  DependencyList * GlobalDependencyListMultiFiles ) {

	ListOfString * TheListOfTransplantedMarkers = createTheListOfAllMarkers(
			SkeletonSourceCode, TXLTemporaryFolderMainThread);

	char * sourceContentFilesTarget;
	sourceContentFilesTarget = (char *) malloc(500 * sizeof(char));
	sprintf(sourceContentFilesTarget, "%stemp_list_of_source_files_extracted.out", TXLTemporaryMultiFileFolder);

	/* rewrite tempGlobalDeclarations for tempGlobalDeclarationsMultiFiles */
	char * tempGlobalDeclarationsMultiFiles;
	tempGlobalDeclarationsMultiFiles = (char *) malloc(500 * sizeof(char));
	sprintf(tempGlobalDeclarationsMultiFiles, "%stemp_global_variable_declarations",
			TXLTemporaryMultiFileFolder);

	/* rewrite definedGlobalTypesAndVariablesFile for definedGlobalTypesAndVariablesMultiFiles */
	char * definedGlobalTypesAndVariablesMultiFiles;
	definedGlobalTypesAndVariablesMultiFiles = (char *) malloc(500 * sizeof(char));
	sprintf(definedGlobalTypesAndVariablesMultiFiles, "%stemp_global_type_var_declarations.out",
			TXLTemporaryMultiFileFolder);

	char * currentSourceFile;
	currentSourceFile = (char*) malloc(400 * sizeof(char));
	char *line;
	line = (char *) malloc(400 * sizeof(char));
	FILE * fin = fopen(sourceContentFilesTarget, "r");

	char * currentOutputSourcePath;
	currentOutputSourcePath = (char *) malloc(500 * sizeof(char));

	DependencyList * DependencyListGlobalCoreFunctionsMultiFiles = NULL;

	// TODO rewrite this MULTIFILES code, add include core feature heade
	char * includeCoreFeatureHeader;
	includeCoreFeatureHeader = (char *) malloc(1000 * sizeof(char));
	sprintf(includeCoreFeatureHeader, "#include \"%s\"\n",
			InterfaceHeaderFileName);

	char * headerFileForCoreFeaturePath;
	headerFileForCoreFeaturePath = (char *) malloc(400 * sizeof(char));
	sprintf(headerFileForCoreFeaturePath, "%stemp_interface_header.out", TXLTemporaryMultiFileFolder);
	//printAListOfStrings(includeCoreFeatureHeader, headerFileForCoreFeaturePath);
	FILE * fout = fopen(headerFileForCoreFeaturePath, "w");
	fprintf(fout, "%s", includeCoreFeatureHeader);
	fclose(fout);

	char * listOfHeadFilesTargetPath;
	listOfHeadFilesTargetPath = (char *) malloc(500 * sizeof(char));
	sprintf(listOfHeadFilesTargetPath, "%stemp_list_of_header_files.out", TXLTemporaryMultiFileFolder);

/* LOS: Insert global declaration in each source file extracted */
	while (fgets(line, 400, fin) != NULL) {
		sscanf(line, "%s", currentSourceFile);

		sprintf(currentOutputSourcePath, "%s%s", TXLTemporaryMultiFileFolder, currentSourceFile);

		extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsInMultiFiles(
				currentOutputSourcePath, ListOfNeededFunctionsForAllLOCs,
				ListOfFinalGlobalDeclarationsMultiFiles, GlobalDependencyListMultiFiles,
				SkeletonDependenciesOnGlobals, tempGlobalDeclarationsMultiFiles,
				definedGlobalTypesAndVariablesMultiFiles, SkeletonSourceCode,
				TheListOfTransplantedMarkers, GlobalFctDependOutput,
				TXLTemporaryMultiFileFolder);

		/* Insert include InterfaceHeade.h */
		addLocsFromSourceToDestination(currentOutputSourcePath,
									   headerFileForCoreFeaturePath, TXLToolsPath);

	}
	fclose(fin);

}
#endif

#if 0 // LOSMULTIHEADERFILES
void extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsInMultiFiles2(
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
		char * TXLTemporaryFolder) {
	//needed for extraction of global dependencies for core feature
	ListOfString * FinalListOfTransplantedFunctionsAsMarkersOld = NULL;
	//first add the feature markerd for extraction, since globals for this too must be added
	/* LOS TODO DELETE
	 * char * GraftFunctionMarker;
	GraftFunctionMarker = (char *) malloc(500 * sizeof(char));*/
	//sprintf(GraftFunctionMarker, "/* %s */", GraftFunctionName);
	//addNewString(&FinalListOfTransplantedFunctionsAsMarkersOld, GraftFunctionMarker);
	// LOS

	//to be checked not to add all functions for all globals, but just for one possible to be transplanted!!!
	CallDependency * ListOfNeededFunctionsForGlobals =
			extractNeededFunctionsForGlobals(ListOfFinalGlobalDeclarations,
											 outputFileGlobalDependenciesOnFunctions);

	extractCoreFunctionsCalledInIndividual(ListOfNeededFunctionsForAllLOCs,
										   candidateSourceCode, headerOutputCoreFunctionality,
										   sourceOutputCoreFunctionality,
										   &FinalListOfTransplantedFunctionsAsMarkersOld,
										   ListOfNeededFunctionsForGlobals, TXLTemporaryFolder);

	fflush(stdout);

	ListOfString * FinalListOfTransplantedFunctionsAsMarkers =
			extractFunctionsAsMarkersFromSourceFile(
					sourceOutputCoreFunctionality, TXLTemporaryFolder);

	//for the source core output file extract all the called files
	//this will be the final list of transplated functions as markers

	//ListOfString * TempListOfStrings = returnListOfStringFromMarkersFile(tempListOfMarkers);

	//FOR ALL EXTRACTED FUNCTIONS, ADD THE DEPENDENCIES!!!

	fflush(stdout);
	//maybe HERE!!!!
	DependencyList * DependencyListGlobalCoreFunctions =
			extractDependencyGlobalListForCoreFunctions(
					sourceOutputCoreFunctionality, tempGlobalDeclarations,
					definedGlobalTypesAndVariablesFile, TXLTemporaryFolder);
	char * tempHeaderGlobalsContent;
	tempHeaderGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempHeaderGlobalsContent, "%stemp_header_decl_for_globals.out",
			TXLTemporaryFolder);
	char * tempSourceCodeGlobalsContent;
	tempSourceCodeGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempSourceCodeGlobalsContent, "%stemp_source_for_globals.out",
			TXLTemporaryFolder);

	fflush(stdout);

	extractNeededGlobalDeclarationsAndHeaderForSkeletonAndInterface(
			ListOfFinalGlobalDeclarations, GlobalDependencyList,
			SkeletonDependenciesOnGlobals, DependencyListGlobalCoreFunctions,
			TheListOfTransplantedMarkers,
			FinalListOfTransplantedFunctionsAsMarkers,
			tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);

	fflush(stdout);

	addLocsFromSourceToDestination(sourceOutputCoreFunctionality,
								   tempSourceCodeGlobalsContent, TXLToolsPath);
	addLocsFromSourceToDestination(SkeletonCoreFeatureHeader,
								   tempHeaderGlobalsContent, TXLToolsPath);

#if 0 /* LOS: MULTIFILES */
	// TODO rewrite add include core feature header
	// TODO rewrite this MULTIFILES code
	char * includeCoreFeatureHeader;
	includeCoreFeatureHeader = (char *) malloc(1000 * sizeof(char));
	sprintf(includeCoreFeatureHeader, "#include \"%s\"\n",
			InterfaceHeaderFileName);

	char * sourceContentFilesTarget;
	sourceContentFilesTarget = (char *) malloc(500 * sizeof(char));
	sprintf(sourceContentFilesTarget, "%stemp_list_of_source_files_extracted.out", TXLTemporaryMultiFileFolder);

	fflush(stdout);

	char * currentSourceFile;
	currentSourceFile = (char*) malloc(400 * sizeof(char));
	char *line;
	line = (char *) malloc(400 * sizeof(char));
	FILE * fin = fopen(sourceContentFilesTarget, "r");

	char * coreFunctionSourceFile;
	coreFunctionSourceFile = (char *) malloc(500 * sizeof(char));

	DependencyList * DependencyListGlobalCoreFunctionsMultiFiles = NULL;

	while (fgets(line, 400, fin) != NULL) {
		sscanf(line, "%s", currentSourceFile);

		sprintf(coreFunctionSourceFile, "%s%s", TXLTemporaryMultiFileFolder, currentSourceFile);

		DependencyListGlobalCoreFunctionsMultiFiles =
				extractDependencyGlobalListForCoreFunctionsMultFiles(
						coreFunctionSourceFile, tempGlobalDeclarations,
						definedGlobalTypesAndVariablesFile, TXLTemporaryMultiFileFolder);

		fflush(stdout);


// TODO  remove comment when I'm create diferents header files
		/* Add includeCoreFeatureHeader in each source file */
		//addCoreFeatureHeader(sourceContentFilesTarget, TXLTemporaryMultiFileFolder);

		char * headerFileForCoreFeaturePath;
		headerFileForCoreFeaturePath = (char *) malloc(400 * sizeof(char));
		sprintf(headerFileForCoreFeaturePath, "%s/%s", HostProject, currentSourceFile);
		//printAListOfStrings(includeCoreFeatureHeader, headerFileForCoreFeaturePath);


	//	FILE * fout = fopen(headerFileForCoreFeaturePath, "w");
	//		fprintf(fout, "%s", includeCoreFeatureHeader);

		sprintf(tempHeaderGlobalsContent, "%stemp_header_decl_for_globals.out",
				TXLTemporaryMultiFileFolder);

		sprintf(tempSourceCodeGlobalsContent, "%stemp_source_for_globals.out",
				TXLTemporaryMultiFileFolder);

		fflush(stdout);
		DependencyList * auxSkeleton = SkeletonDependenciesOnGlobals;
		extractNeededGlobalDeclarationsAndHeaderForSkeletonAndInterface(
				ListOfFinalGlobalDeclarations, GlobalDependencyList,
				auxSkeleton, DependencyListGlobalCoreFunctionsMultiFiles,
				TheListOfTransplantedMarkers,
				FinalListOfTransplantedFunctionsAsMarkers,
				tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);

		fflush(stdout);

		addLocsFromSourceToDestination(coreFunctionSourceFile,
									   tempSourceCodeGlobalsContent, TXLToolsPath);

		// TODO rewrite sGlobalVarTypesDeclDependencyCOREFUNCTIONS to include interfaceHeader.h
		/* LOS temporary code to add include */
		char * listOfNeededHeadFilesForCoreGraftFunction;
		listOfNeededHeadFilesForCoreGraftFunction = (char *) malloc(500 * sizeof(char));
		sprintf(listOfNeededHeadFilesForCoreGraftFunction, "%stemp_interface_header.out", TXLTemporaryMultiFileFolder);

		FILE *fCurrentSourceFiles = fopen(listOfNeededHeadFilesForCoreGraftFunction, "w+");
		fprintf(fCurrentSourceFiles, "#include \"InterfaceHeader.h\"\n");
		fclose(fCurrentSourceFiles);

		ListOfString * listOfHeaderFilesForInclude = readListOfStringFromFileAsWords(listOfNeededHeadFilesForCoreGraftFunction);

		addLocsFromSourceToDestination(coreFunctionSourceFile, listOfNeededHeadFilesForCoreGraftFunction, TXLToolsPath);
       /* LOS temporary code to add include */

		DependencyListGlobalCoreFunctionsMultiFiles = NULL;
	}

	char * SkeletonCoreFeatureHeaderMultiFiles;
	SkeletonCoreFeatureHeaderMultiFiles = (char *) malloc(500 * sizeof(char));
	sprintf(SkeletonCoreFeatureHeaderMultiFiles, "%sInterfaceHeader2.h", TXLTemporaryMultiFileFolder);

	addLocsFromSourceToDestination(SkeletonCoreFeatureHeaderMultiFiles,
								   tempHeaderGlobalsContent, TXLToolsPath);


#endif
}
#else

#ifdef SEARCH_VAR_UNION

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
		char * TXLTemporaryFolder) {
	//needed for extraction of global dependencies for core feature
	ListOfString * FinalListOfTransplantedFunctionsAsMarkersOld = NULL;
	//first add the feature markerd for extraction, since globals for this too must be added
	/* LOS TODO DELETE
     * char * GraftFunctionMarker;
    GraftFunctionMarker = (char *) malloc(500 * sizeof(char));*/
	//sprintf(GraftFunctionMarker, "/* %s */", GraftFunctionName);
	//addNewString(&FinalListOfTransplantedFunctionsAsMarkersOld, GraftFunctionMarker);
	// LOS

	//to be checked not to add all functions for all globals, but just for one possible to be transplanted!!!
	CallDependency * ListOfNeededFunctionsForGlobals =
			extractNeededFunctionsForGlobals(ListOfFinalGlobalDeclarations,
											 outputFileGlobalDependenciesOnFunctions);

/*	extractCoreFunctionsCalledInIndividual(ListOfNeededFunctionsForAllLOCs,
										   candidateSourceCode, SkeletonCoreFeatureHeader,
										   sourceOutputCoreFunctionality,
										   &FinalListOfTransplantedFunctionsAsMarkersOld,
										   ListOfNeededFunctionsForGlobals, TXLTemporaryFolder);
*/
	fflush(stdout);

	ListOfString * FinalListOfTransplantedFunctionsAsMarkers =
			extractFunctionsAsMarkersFromSourceFile(
					sourceOutputCoreFunctionality, TXLTemporaryFolder);

	//for the source core output file extract all the called files
	//this will be the final list of transplated functions as markers

	//ListOfString * TempListOfStrings = returnListOfStringFromMarkersFile(tempListOfMarkers);

	//FOR ALL EXTRACTED FUNCTIONS, ADD THE DEPENDENCIES!!!

	fflush(stdout);
	//maybe HERE!!!!
	DependencyList * DependencyListGlobalCoreFunctions =
			extractDependencyGlobalListForVarUnionDependency(
					sourceOutputCoreFunctionality, tempGlobalDeclarations,
					definedGlobalTypesAndVariablesFile, TXLTemporaryFolder);
	char * tempHeaderGlobalsContent;
	tempHeaderGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempHeaderGlobalsContent, "%stemp_header_decl_for_globals.out",
			TXLTemporaryFolderMainThread);
	char * tempSourceCodeGlobalsContent;
	tempSourceCodeGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempSourceCodeGlobalsContent, "%stemp_source_for_globals.out",
			TXLTemporaryFolder);

	fflush(stdout);
#ifdef HEADER_FILE
	extractNeededGlobalDeclarationsAndHeaderForCoreFunction2(
			ListOfFinalGlobalDeclarations, GlobalDependencyList,
			SkeletonDependenciesOnGlobals, DependencyListGlobalCoreFunctions,
			TheListOfTransplantedMarkers,
			FinalListOfTransplantedFunctionsAsMarkers,
			tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);
#else
	extractNeededGlobalDeclarationsAndHeaderForSkeletonAndInterface(
			ListOfFinalGlobalDeclarations, GlobalDependencyList,
			SkeletonDependenciesOnGlobals, DependencyListGlobalCoreFunctions,
			TheListOfTransplantedMarkers,
			FinalListOfTransplantedFunctionsAsMarkers,
			tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);
#endif
	fflush(stdout);

	char *headerFileName = (char *) malloc((strlen(currentHeaderFiles)+1) * sizeof(char));
	strcpy(headerFileName, readSubstring(donorSourceFileFolder, currentHeaderFiles, "\""));
	fflush(stdout);

	char *newCurrentHeaderFilePath = NULL;
	newCurrentHeaderFilePath = (char *) malloc((strlen(TXLTemporaryMultiFileFolder) + strlen(headerFileName) + 2) * sizeof(char));
	sprintf(newCurrentHeaderFilePath, "%s%s", TXLTemporaryMultiFileFolder,headerFileName);
	fflush(stdout);


/*
	//LOS Temp list of files which all global declarations have been already extracted
	char *tempListOfFilesExtracted;
	tempListOfFilesExtracted = (char *) malloc(500 * sizeof(char));
	sprintf(tempListOfFilesExtracted, "%stemp_list_of_source_files_extracted.out",
			TXLTemporaryMultiFileFolder);

	char *temHeaderFilePath;
	temHeaderFilePath = (char *) malloc(400 * sizeof(char));
	sprintf(temHeaderFilePath, "%stemp_interface_header.out", TXLTemporaryMultiFileFolder);

	FILE *fInterfaceHeader = fopen(temHeaderFilePath, "w");
	fprintf(fInterfaceHeader, "#include \"%s\"\n", InterfaceHeaderFileName);
	fclose(fInterfaceHeader);

	printf("[AUTOSCALPEL] Insert include interface header in all extracted files\n");
	//char *formattedCurrentFileDestinationPath = (char *) malloc(500 * sizeof(char));
	//	ListOfString * listOfFilesToInsertInterfaceHeader = readListOfStringFromFileAsWords(tempListOfFilesExtracted);
	//	while (listOfFilesToInsertInterfaceHeader) {
	//	char *sourceFileTarget = (char *) malloc(500 * sizeof(char));
	//strcpy(sourceFileTarget, readSubstring(donorSourceFileFolder, listOfFilesToInsertInterfaceHeader->el, ".c"));
	// strcpy(sourceFileTarget, readSubstring(donorSourceFileFolder, listOfFilesToInsertInterfaceHeader->el, ".c"));
	//	sprintf(formattedCurrentFileDestinationPath, "%s%s", TXLTemporaryMultiFileFolder,
	//			listOfFilesToInsertInterfaceHeader->el);
	addLocsFromSourceToDestination(formattedCurrentFileDestinationPath,
								   temHeaderFilePath, TXLToolsPath);
	//		listOfFilesToInsertInterfaceHeader = listOfFilesToInsertInterfaceHeader->next;
	//	}
*/
#ifdef	SEARCH_VAR_UNION
	char *finalListOfAllVarExtracted;
	finalListOfAllVarExtracted = (char *) malloc(500 * sizeof(char));
	sprintf(finalListOfAllVarExtracted, "%sAllGlobalVarExtracted.h",
			TempVeinDirectory);

	char * tempListOfVarsExtracted;
	tempListOfVarsExtracted = (char *) malloc(500 * sizeof(char));
	sprintf(tempListOfVarsExtracted, "%stemp_list_of_vars_extracted.out",
			TempVeinDirectory);

	addLocsFromSourceToDestination(finalListOfAllVarExtracted,
								   tempListOfVarsExtracted, TXLToolsPath);
#endif

	char *tempListOfHeaderFilesExtracted;
	tempListOfHeaderFilesExtracted = (char *) malloc(500 * sizeof(char));
	sprintf(tempListOfHeaderFilesExtracted, "%stemp_list_of_header_files_extracted.out",
			TXLTemporaryMultiFileFolder);


	if(get_size(tempSourceCodeGlobalsContent)!=0)
	{
		FILE * fout = fopen(newCurrentHeaderFilePath, "a");
		fclose(fout);

		addLocsFromSourceToDestination(newCurrentHeaderFilePath, tempSourceCodeGlobalsContent, TXLToolsPath);
		addLocsFromSourceToDestination(SkeletonCoreFeatureHeader, tempHeaderGlobalsContent, TXLToolsPath);
		char *headerFileName = (char *) malloc((strlen(newCurrentHeaderFilePath) + 18) * sizeof(char));
		strcpy(headerFileName, readSubstring(TXLTemporaryMultiFileFolder, newCurrentHeaderFilePath, ".h"));
		strcat(headerFileName, ".h");
		fflush(stdout);

		char *headerFileNameLN = (char *) malloc((strlen(headerFileName) + 3) * sizeof(char));
		sprintf(headerFileNameLN, "%s%s",headerFileName, "\n");
		fflush(stdout);
		ListOfString *listOfTargetFiles = readListOfStringFromFile(tempListOfHeaderFilesExtracted);
		if (!searchStringInListOfStrings(listOfTargetFiles, headerFileNameLN)){

			addAStringsInTheEndFileLN(headerFileName, tempListOfHeaderFilesExtracted);
		}


		char *formatIncludeHeader;
		formatIncludeHeader = (char *) malloc(500 * sizeof(char));
		sprintf(formatIncludeHeader, "#include \"%s\"\n", headerFileName);

		char *tempHeaderFilePath;
		tempHeaderFilePath = (char *) malloc(400 * sizeof(char));
		sprintf(tempHeaderFilePath, "%stemp_include_header.out", TXLTemporaryMultiFileFolder);

		addAStringsInTheFile(formatIncludeHeader, tempHeaderFilePath);

		addLocsFromSourceToDestination(sourceOutputCoreFunctionality,
									   tempHeaderFilePath, TXLToolsPath);

		char *tempIncludeLibInHeaderFile;
		tempIncludeLibInHeaderFile = (char *) malloc(500 * sizeof(char));
		sprintf(tempIncludeLibInHeaderFile, "%stemp_include_lib_file.out",
				TXLTemporaryMultiFileFolder);

		addLocsFromSourceToDestination(newCurrentHeaderFilePath, tempIncludeLibInHeaderFile, TXLToolsPath);

		char *tempIncludeLocalLibInHeaderFile;
		tempIncludeLocalLibInHeaderFile = (char *) malloc(500 * sizeof(char));
		sprintf(tempIncludeLocalLibInHeaderFile, "%stemp_include_local_lib_file.out",
				TXLTemporaryMultiFileFolder);

		addLocsFromSourceToDestination(newCurrentHeaderFilePath, tempIncludeLocalLibInHeaderFile, TXLToolsPath);

		char *tempDefineInHeaderFile;
		tempDefineInHeaderFile = (char *) malloc(500 * sizeof(char));
		sprintf(tempDefineInHeaderFile, "%stemp_define_file.out",
				TXLTemporaryFolderMainThread);

		addLocsFromSourceToDestination(newCurrentHeaderFilePath,tempDefineInHeaderFile, TXLToolsPath);

	}

	// addLocsFromSourceToDestination(currentHeaderFiles, tempSourceCodeGlobalsContent, TXLToolsPath);



//	addLocsFromSourceToDestination(SkeletonCoreFeatureHeader, tempHeaderGlobalsContent, TXLToolsPath);


}
#endif

#ifdef VEIN_GLOBAL_EXTRACTION
void extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsInHeaderFile2(
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
        char * TXLTemporaryFolder) {
    //needed for extraction of global dependencies for core feature
    ListOfString * FinalListOfTransplantedFunctionsAsMarkersOld = NULL;
    //first add the feature markerd for extraction, since globals for this too must be added
    /* LOS TODO DELETE
     * char * GraftFunctionMarker;
    GraftFunctionMarker = (char *) malloc(500 * sizeof(char));*/
    //sprintf(GraftFunctionMarker, "/* %s */", GraftFunctionName);
    //addNewString(&FinalListOfTransplantedFunctionsAsMarkersOld, GraftFunctionMarker);
    // LOS

    //to be checked not to add all functions for all globals, but just for one possible to be transplanted!!!
    CallDependency * ListOfNeededFunctionsForGlobals =
            extractNeededFunctionsForGlobals(ListOfFinalGlobalDeclarations,
                                             outputFileGlobalDependenciesOnFunctions);

/*	extractCoreFunctionsCalledInIndividual(ListOfNeededFunctionsForAllLOCs,
										   candidateSourceCode, SkeletonCoreFeatureHeader,
										   sourceOutputCoreFunctionality,
										   &FinalListOfTransplantedFunctionsAsMarkersOld,
										   ListOfNeededFunctionsForGlobals, TXLTemporaryFolder);
*/
    fflush(stdout);

    ListOfString * FinalListOfTransplantedFunctionsAsMarkers =
            extractFunctionsAsMarkersFromSourceFile(
                    sourceOutputCoreFunctionality, TXLTemporaryFolder);

    //for the source core output file extract all the called files
    //this will be the final list of transplated functions as markers

    //ListOfString * TempListOfStrings = returnListOfStringFromMarkersFile(tempListOfMarkers);

    //FOR ALL EXTRACTED FUNCTIONS, ADD THE DEPENDENCIES!!!

    fflush(stdout);
    //maybe HERE!!!!
    DependencyList * DependencyListGlobalCoreFunctions =
			extractDependencyGlobalListForCoreFunctions(
                    sourceOutputCoreFunctionality, tempGlobalDeclarations,
                    definedGlobalTypesAndVariablesFile, TXLTemporaryFolder);
    char * tempHeaderGlobalsContent;
    tempHeaderGlobalsContent = (char *) malloc(500 * sizeof(char));
    sprintf(tempHeaderGlobalsContent, "%stemp_header_decl_for_globals.out",
            TXLTemporaryFolderMainThread);
    char * tempSourceCodeGlobalsContent;
    tempSourceCodeGlobalsContent = (char *) malloc(500 * sizeof(char));
    sprintf(tempSourceCodeGlobalsContent, "%stemp_source_for_globals.out",
            TXLTemporaryFolder);

    fflush(stdout);
#ifdef HEADER_FILE
    extractNeededGlobalDeclarationsAndHeaderForCoreFunction2(
            ListOfFinalGlobalDeclarations, GlobalDependencyList,
            SkeletonDependenciesOnGlobals, DependencyListGlobalCoreFunctions,
            TheListOfTransplantedMarkers,
            FinalListOfTransplantedFunctionsAsMarkers,
            tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);
#else
    extractNeededGlobalDeclarationsAndHeaderForSkeletonAndInterface(
			ListOfFinalGlobalDeclarations, GlobalDependencyList,
			SkeletonDependenciesOnGlobals, DependencyListGlobalCoreFunctions,
			TheListOfTransplantedMarkers,
			FinalListOfTransplantedFunctionsAsMarkers,
			tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);
#endif
    fflush(stdout);

    char *headerFileName = (char *) malloc((strlen(currentHeaderFiles)+1) * sizeof(char));
    strcpy(headerFileName, readSubstring(donorSourceFileFolder, currentHeaderFiles, "\""));
    fflush(stdout);

    char *newCurrentHeaderFilePath = NULL;
    newCurrentHeaderFilePath = (char *) malloc((strlen(TXLTemporaryMultiFileFolder) + strlen(headerFileName) + 2) * sizeof(char));
    sprintf(newCurrentHeaderFilePath, "%s%s", TXLTemporaryMultiFileFolder,headerFileName);
    fflush(stdout);


/*
	//LOS Temp list of files which all global declarations have been already extracted
	char *tempListOfFilesExtracted;
	tempListOfFilesExtracted = (char *) malloc(500 * sizeof(char));
	sprintf(tempListOfFilesExtracted, "%stemp_list_of_source_files_extracted.out",
			TXLTemporaryMultiFileFolder);

	char *temHeaderFilePath;
	temHeaderFilePath = (char *) malloc(400 * sizeof(char));
	sprintf(temHeaderFilePath, "%stemp_interface_header.out", TXLTemporaryMultiFileFolder);

	FILE *fInterfaceHeader = fopen(temHeaderFilePath, "w");
	fprintf(fInterfaceHeader, "#include \"%s\"\n", InterfaceHeaderFileName);
	fclose(fInterfaceHeader);

	printf("[AUTOSCALPEL] Insert include interface header in all extracted files\n");
	//char *formattedCurrentFileDestinationPath = (char *) malloc(500 * sizeof(char));
	//	ListOfString * listOfFilesToInsertInterfaceHeader = readListOfStringFromFileAsWords(tempListOfFilesExtracted);
	//	while (listOfFilesToInsertInterfaceHeader) {
	//	char *sourceFileTarget = (char *) malloc(500 * sizeof(char));
	//strcpy(sourceFileTarget, readSubstring(donorSourceFileFolder, listOfFilesToInsertInterfaceHeader->el, ".c"));
	// strcpy(sourceFileTarget, readSubstring(donorSourceFileFolder, listOfFilesToInsertInterfaceHeader->el, ".c"));
	//	sprintf(formattedCurrentFileDestinationPath, "%s%s", TXLTemporaryMultiFileFolder,
	//			listOfFilesToInsertInterfaceHeader->el);
	addLocsFromSourceToDestination(formattedCurrentFileDestinationPath,
								   temHeaderFilePath, TXLToolsPath);
	//		listOfFilesToInsertInterfaceHeader = listOfFilesToInsertInterfaceHeader->next;
	//	}
*/
#if	0 //SEARCH_VAR_UNION
	char *finalListOfAllVarExtracted;
	finalListOfAllVarExtracted = (char *) malloc(500 * sizeof(char));
	sprintf(finalListOfAllVarExtracted, "%sAllGlobalVarExtracted.h",
			TempVeinDirectory);

	char * tempListOfVarsExtracted;
	tempListOfVarsExtracted = (char *) malloc(500 * sizeof(char));
	sprintf(tempListOfVarsExtracted, "%stemp_list_of_vars_extracted.out",
			TempVeinDirectory);

	addLocsFromSourceToDestination(finalListOfAllVarExtracted,
								   tempListOfVarsExtracted, TXLToolsPath);
#endif

    char *tempListOfHeaderFilesExtracted;
    tempListOfHeaderFilesExtracted = (char *) malloc(500 * sizeof(char));
    sprintf(tempListOfHeaderFilesExtracted, "%stemp_list_of_header_files_extracted.out",
            TXLTemporaryMultiFileFolder);


    if(get_size(tempSourceCodeGlobalsContent)!=0)
    {
        FILE * fout = fopen(newCurrentHeaderFilePath, "a");
        fclose(fout);

        addLocsFromSourceToDestination(newCurrentHeaderFilePath, tempSourceCodeGlobalsContent, TXLToolsPath);
		addLocsFromSourceToDestination(SkeletonCoreFeatureHeader, tempHeaderGlobalsContent, TXLToolsPath);
        char *headerFileName = (char *) malloc((strlen(newCurrentHeaderFilePath) + 18) * sizeof(char));
        strcpy(headerFileName, readSubstring(TXLTemporaryMultiFileFolder, newCurrentHeaderFilePath, ".h"));
        strcat(headerFileName, ".h");
        fflush(stdout);

        char *headerFileNameLN = (char *) malloc((strlen(headerFileName) + 3) * sizeof(char));
        sprintf(headerFileNameLN, "%s%s",headerFileName, "\n");
		fflush(stdout);
        ListOfString *listOfTargetFiles = readListOfStringFromFile(tempListOfHeaderFilesExtracted);
        if (!searchStringInListOfStrings(listOfTargetFiles, headerFileNameLN)){

            addAStringsInTheEndFileLN(headerFileName, tempListOfHeaderFilesExtracted);
        }


        char *formatIncludeHeader;
        formatIncludeHeader = (char *) malloc(500 * sizeof(char));
        sprintf(formatIncludeHeader, "#include \"%s\"\n", headerFileName);

        char *tempHeaderFilePath;
        tempHeaderFilePath = (char *) malloc(400 * sizeof(char));
        sprintf(tempHeaderFilePath, "%stemp_include_header.out", TXLTemporaryMultiFileFolder);

        addAStringsInTheFile(formatIncludeHeader, tempHeaderFilePath);

        addLocsFromSourceToDestination(sourceOutputCoreFunctionality,
                                       tempHeaderFilePath, TXLToolsPath);

        char *tempIncludeLibInHeaderFile;
        tempIncludeLibInHeaderFile = (char *) malloc(500 * sizeof(char));
        sprintf(tempIncludeLibInHeaderFile, "%stemp_include_lib_file.out",
                TXLTemporaryMultiFileFolder);

        addLocsFromSourceToDestination(newCurrentHeaderFilePath, tempIncludeLibInHeaderFile, TXLToolsPath);

		char *tempIncludeLocalLibInHeaderFile;
		tempIncludeLocalLibInHeaderFile = (char *) malloc(500 * sizeof(char));
		sprintf(tempIncludeLocalLibInHeaderFile, "%stemp_include_local_lib_file.out",
				TXLTemporaryMultiFileFolder);

		addLocsFromSourceToDestination(newCurrentHeaderFilePath, tempIncludeLocalLibInHeaderFile, TXLToolsPath);

        char *tempDefineInHeaderFile;
        tempDefineInHeaderFile = (char *) malloc(500 * sizeof(char));
        sprintf(tempDefineInHeaderFile, "%stemp_define_file.out",
                TXLTemporaryFolderMainThread);

        addLocsFromSourceToDestination(newCurrentHeaderFilePath,tempDefineInHeaderFile, TXLToolsPath);

    }

   // addLocsFromSourceToDestination(currentHeaderFiles, tempSourceCodeGlobalsContent, TXLToolsPath);



//	addLocsFromSourceToDestination(SkeletonCoreFeatureHeader, tempHeaderGlobalsContent, TXLToolsPath);


}
#endif
void extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsInHeaderFile(
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
		char * TXLTemporaryFolder) {
	//needed for extraction of global dependencies for core feature
	ListOfString * FinalListOfTransplantedFunctionsAsMarkersOld = NULL;
	//first add the feature markerd for extraction, since globals for this too must be added
	/* LOS TODO DELETE
	 * char * GraftFunctionMarker;
	GraftFunctionMarker = (char *) malloc(500 * sizeof(char));*/
	//sprintf(GraftFunctionMarker, "/* %s */", GraftFunctionName);
	//addNewString(&FinalListOfTransplantedFunctionsAsMarkersOld, GraftFunctionMarker);
	// LOS

	//to be checked not to add all functions for all globals, but just for one possible to be transplanted!!!
	CallDependency * ListOfNeededFunctionsForGlobals =
			extractNeededFunctionsForGlobals(ListOfFinalGlobalDeclarations,
											 outputFileGlobalDependenciesOnFunctions);

/*	extractCoreFunctionsCalledInIndividual(ListOfNeededFunctionsForAllLOCs,
										   candidateSourceCode, SkeletonCoreFeatureHeader,
										   sourceOutputCoreFunctionality,
										   &FinalListOfTransplantedFunctionsAsMarkersOld,
										   ListOfNeededFunctionsForGlobals, TXLTemporaryFolder);
*/
	fflush(stdout);

	ListOfString * FinalListOfTransplantedFunctionsAsMarkers =
			extractFunctionsAsMarkersFromSourceFile(
					sourceOutputCoreFunctionality, TXLTemporaryFolder);

	//for the source core output file extract all the called files
	//this will be the final list of transplated functions as markers

	//ListOfString * TempListOfStrings = returnListOfStringFromMarkersFile(tempListOfMarkers);

	//FOR ALL EXTRACTED FUNCTIONS, ADD THE DEPENDENCIES!!!

	fflush(stdout);
	//maybe HERE!!!!
	DependencyList * DependencyListGlobalCoreFunctions =
			extractDependencyGlobalListForCoreFunctions(
					sourceOutputCoreFunctionality, tempGlobalDeclarations,
					definedGlobalTypesAndVariablesFile, TXLTemporaryFolder);
	char * tempHeaderGlobalsContent;
	tempHeaderGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempHeaderGlobalsContent, "%stemp_header_decl_for_globals.out",
			TXLTemporaryFolder);
	char * tempSourceCodeGlobalsContent;
	tempSourceCodeGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempSourceCodeGlobalsContent, "%stemp_source_for_globals.out",
			TXLTemporaryFolder);

	fflush(stdout);
#ifdef HEADER_FILE
	extractNeededGlobalDeclarationsAndHeaderForCoreFunction(
			ListOfFinalGlobalDeclarations, GlobalDependencyList,
			SkeletonDependenciesOnGlobals, DependencyListGlobalCoreFunctions,
			TheListOfTransplantedMarkers,
			FinalListOfTransplantedFunctionsAsMarkers,
			tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);
#else
	extractNeededGlobalDeclarationsAndHeaderForSkeletonAndInterface(
			ListOfFinalGlobalDeclarations, GlobalDependencyList,
			SkeletonDependenciesOnGlobals, DependencyListGlobalCoreFunctions,
			TheListOfTransplantedMarkers,
			FinalListOfTransplantedFunctionsAsMarkers,
			tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);
#endif
	fflush(stdout);

	char *headerFileName = (char *) malloc((strlen(currentHeaderFiles)+1) * sizeof(char));
	strcpy(headerFileName, readSubstring(donorSourceFileFolder, currentHeaderFiles, "\""));
	fflush(stdout);

	char *newCurrentHeaderFilePath = NULL;
	newCurrentHeaderFilePath = (char *) malloc((strlen(TXLTemporaryMultiFileFolder) + strlen(headerFileName) + 2) * sizeof(char));
	sprintf(newCurrentHeaderFilePath, "%s%s", TXLTemporaryMultiFileFolder,headerFileName);
	fflush(stdout);


/*
	//LOS Temp list of files which all global declarations have been already extracted
	char *tempListOfFilesExtracted;
	tempListOfFilesExtracted = (char *) malloc(500 * sizeof(char));
	sprintf(tempListOfFilesExtracted, "%stemp_list_of_source_files_extracted.out",
			TXLTemporaryMultiFileFolder);

	char *temHeaderFilePath;
	temHeaderFilePath = (char *) malloc(400 * sizeof(char));
	sprintf(temHeaderFilePath, "%stemp_interface_header.out", TXLTemporaryMultiFileFolder);

	FILE *fInterfaceHeader = fopen(temHeaderFilePath, "w");
	fprintf(fInterfaceHeader, "#include \"%s\"\n", InterfaceHeaderFileName);
	fclose(fInterfaceHeader);

	printf("[AUTOSCALPEL] Insert include interface header in all extracted files\n");
	//char *formattedCurrentFileDestinationPath = (char *) malloc(500 * sizeof(char));
	//	ListOfString * listOfFilesToInsertInterfaceHeader = readListOfStringFromFileAsWords(tempListOfFilesExtracted);
	//	while (listOfFilesToInsertInterfaceHeader) {
	//	char *sourceFileTarget = (char *) malloc(500 * sizeof(char));
	//strcpy(sourceFileTarget, readSubstring(donorSourceFileFolder, listOfFilesToInsertInterfaceHeader->el, ".c"));
	// strcpy(sourceFileTarget, readSubstring(donorSourceFileFolder, listOfFilesToInsertInterfaceHeader->el, ".c"));
	//	sprintf(formattedCurrentFileDestinationPath, "%s%s", TXLTemporaryMultiFileFolder,
	//			listOfFilesToInsertInterfaceHeader->el);
	addLocsFromSourceToDestination(formattedCurrentFileDestinationPath,
								   temHeaderFilePath, TXLToolsPath);
	//		listOfFilesToInsertInterfaceHeader = listOfFilesToInsertInterfaceHeader->next;
	//	}
*/

	char *tempListOfHeaderFilesExtracted;
    tempListOfHeaderFilesExtracted = (char *) malloc(500 * sizeof(char));
	sprintf(tempListOfHeaderFilesExtracted, "%stemp_list_of_header_files_extracted.out",
			TXLTemporaryMultiFileFolder);


	if(get_size(tempSourceCodeGlobalsContent)!=0)
	{
		FILE * fout = fopen(newCurrentHeaderFilePath, "a");
		fclose(fout);

        addLocsFromSourceToDestination(newCurrentHeaderFilePath, tempSourceCodeGlobalsContent, TXLToolsPath);

		char *headerFileName = (char *) malloc((strlen(newCurrentHeaderFilePath) + 18) * sizeof(char));
		strcpy(headerFileName, readSubstring(TXLTemporaryMultiFileFolder, newCurrentHeaderFilePath, ".h"));
		strcat(headerFileName, ".h");
		fflush(stdout);

		char *headerFileNameLN = (char *) malloc((strlen(headerFileName) + 3) * sizeof(char));
		sprintf(headerFileNameLN, "%s%s",headerFileName, "\n");

		ListOfString *listOfTargetFiles = readListOfStringFromFile(tempListOfHeaderFilesExtracted);
		if (!searchStringInListOfStrings(listOfTargetFiles, headerFileNameLN)){

			addAStringsInTheEndFileLN(headerFileName, tempListOfHeaderFilesExtracted);
		}


			char *formatIncludeHeader;
			formatIncludeHeader = (char *) malloc(500 * sizeof(char));
			sprintf(formatIncludeHeader, "#include \"%s\"\n", headerFileName);

			char *tempHeaderFilePath;
			tempHeaderFilePath = (char *) malloc(400 * sizeof(char));
			sprintf(tempHeaderFilePath, "%stemp_include_header.out", TXLTemporaryMultiFileFolder);

			addAStringsInTheFile(formatIncludeHeader, tempHeaderFilePath);

			addLocsFromSourceToDestination(sourceOutputCoreFunctionality,
										   tempHeaderFilePath, TXLToolsPath);

        char *tempIncludeLibInHeaderFile;
		tempIncludeLibInHeaderFile = (char *) malloc(500 * sizeof(char));
        sprintf(tempIncludeLibInHeaderFile, "%stemp_include_lib_file.out",
                TXLTemporaryMultiFileFolder);

        addLocsFromSourceToDestination(newCurrentHeaderFilePath, tempIncludeLibInHeaderFile, TXLToolsPath);

		char *tempDefineInHeaderFile;
		tempDefineInHeaderFile = (char *) malloc(500 * sizeof(char));
		sprintf(tempDefineInHeaderFile, "%stemp_define_file.out",
				TXLTemporaryFolderMainThread);

		addLocsFromSourceToDestination(newCurrentHeaderFilePath,tempDefineInHeaderFile, TXLToolsPath);

	}

	//addLocsFromSourceToDestination(currentHeaderFiles, tempSourceCodeGlobalsContent, TXLToolsPath);
	addLocsFromSourceToDestination(SkeletonCoreFeatureHeader, tempHeaderGlobalsContent, TXLToolsPath);

//	addLocsFromSourceToDestination(SkeletonCoreFeatureHeader, tempHeaderGlobalsContent, TXLToolsPath);


}

void extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsInMultiFiles2(
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
		char * TXLTemporaryFolder) {
	//needed for extraction of global dependencies for core feature
	ListOfString * FinalListOfTransplantedFunctionsAsMarkersOld = NULL;
	//first add the feature markerd for extraction, since globals for this too must be added
	/* LOS TODO DELETE
	 * char * GraftFunctionMarker;
	GraftFunctionMarker = (char *) malloc(500 * sizeof(char));*/
	//sprintf(GraftFunctionMarker, "/* %s */", GraftFunctionName);
	//addNewString(&FinalListOfTransplantedFunctionsAsMarkersOld, GraftFunctionMarker);
    // LOS

	//to be checked not to add all functions for all globals, but just for one possible to be transplanted!!!
	CallDependency * ListOfNeededFunctionsForGlobals =
			extractNeededFunctionsForGlobals(ListOfFinalGlobalDeclarations,
											 outputFileGlobalDependenciesOnFunctions);

/*	extractCoreFunctionsCalledInIndividual(ListOfNeededFunctionsForAllLOCs,
										   candidateSourceCode, SkeletonCoreFeatureHeader,
										   sourceOutputCoreFunctionality,
										   &FinalListOfTransplantedFunctionsAsMarkersOld,
										   ListOfNeededFunctionsForGlobals, TXLTemporaryFolder);
*/
	fflush(stdout);

	ListOfString * FinalListOfTransplantedFunctionsAsMarkers =
			extractFunctionsAsMarkersFromSourceFile(
					sourceOutputCoreFunctionality, TXLTemporaryFolder);

	//for the source core output file extract all the called files
	//this will be the final list of transplated functions as markers

	//ListOfString * TempListOfStrings = returnListOfStringFromMarkersFile(tempListOfMarkers);

	//FOR ALL EXTRACTED FUNCTIONS, ADD THE DEPENDENCIES!!!

	fflush(stdout);
	//maybe HERE!!!!
	DependencyList * DependencyListGlobalCoreFunctions =
			extractDependencyGlobalListForCoreFunctions(
					sourceOutputCoreFunctionality, tempGlobalDeclarations,
					definedGlobalTypesAndVariablesFile, TXLTemporaryFolder);
	char * tempHeaderGlobalsContent;
	tempHeaderGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempHeaderGlobalsContent, "%stemp_header_decl_for_globals.out",
			TXLTemporaryFolder);
	char * tempSourceCodeGlobalsContent;
	tempSourceCodeGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempSourceCodeGlobalsContent, "%stemp_source_for_globals.out",
			TXLTemporaryFolder);

	fflush(stdout);

	extractNeededGlobalDeclarationsAndHeaderForSkeletonAndInterface(
			ListOfFinalGlobalDeclarations, GlobalDependencyList,
			SkeletonDependenciesOnGlobals, DependencyListGlobalCoreFunctions,
			TheListOfTransplantedMarkers,
			FinalListOfTransplantedFunctionsAsMarkers,
			tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);

	fflush(stdout);

	addLocsFromSourceToDestination(sourceOutputCoreFunctionality, tempSourceCodeGlobalsContent, TXLToolsPath);
	//addLocsFromSourceToDestination(SkeletonCoreFeatureHeader, tempHeaderGlobalsContent, TXLToolsPath);

	//addLocsFromSourceToDestination(SkeletonCoreFeatureHeader, tempHeaderGlobalsContent, TXLToolsPath);


#if 0 /* LOS: MULTIFILES */
	// TODO rewrite add include core feature header
	// TODO rewrite this MULTIFILES code
	char * includeCoreFeatureHeader;
	includeCoreFeatureHeader = (char *) malloc(1000 * sizeof(char));
	sprintf(includeCoreFeatureHeader, "#include \"%s\"\n",
			InterfaceHeaderFileName);

	char * sourceContentFilesTarget;
	sourceContentFilesTarget = (char *) malloc(500 * sizeof(char));
	sprintf(sourceContentFilesTarget, "%stemp_list_of_source_files_extracted.out", TXLTemporaryMultiFileFolder);

	fflush(stdout);

	char * currentSourceFile;
	currentSourceFile = (char*) malloc(400 * sizeof(char));
	char *line;
	line = (char *) malloc(400 * sizeof(char));
	FILE * fin = fopen(sourceContentFilesTarget, "r");

	char * coreFunctionSourceFile;
	coreFunctionSourceFile = (char *) malloc(500 * sizeof(char));

	DependencyList * DependencyListGlobalCoreFunctionsMultiFiles = NULL;

	while (fgets(line, 400, fin) != NULL) {
		sscanf(line, "%s", currentSourceFile);

		sprintf(coreFunctionSourceFile, "%s%s", TXLTemporaryMultiFileFolder, currentSourceFile);

		DependencyListGlobalCoreFunctionsMultiFiles =
				extractDependencyGlobalListForCoreFunctionsMultFiles(
						coreFunctionSourceFile, tempGlobalDeclarations,
						definedGlobalTypesAndVariablesFile, TXLTemporaryMultiFileFolder);

		fflush(stdout);


// TODO  remove comment when I'm create diferents header files
		/* Add includeCoreFeatureHeader in each source file */
		//addCoreFeatureHeader(sourceContentFilesTarget, TXLTemporaryMultiFileFolder);

		char * headerFileForCoreFeaturePath;
		headerFileForCoreFeaturePath = (char *) malloc(400 * sizeof(char));
		sprintf(headerFileForCoreFeaturePath, "%s/%s", HostProject, currentSourceFile);
		//printAListOfStrings(includeCoreFeatureHeader, headerFileForCoreFeaturePath);


	//	FILE * fout = fopen(headerFileForCoreFeaturePath, "w");
	//		fprintf(fout, "%s", includeCoreFeatureHeader);

		sprintf(tempHeaderGlobalsContent, "%stemp_header_decl_for_globals.out",
				TXLTemporaryMultiFileFolder);

		sprintf(tempSourceCodeGlobalsContent, "%stemp_source_for_globals.out",
				TXLTemporaryMultiFileFolder);

		fflush(stdout);
		DependencyList * auxSkeleton = SkeletonDependenciesOnGlobals;
		extractNeededGlobalDeclarationsAndHeaderForSkeletonAndInterface(
				ListOfFinalGlobalDeclarations, GlobalDependencyList,
				auxSkeleton, DependencyListGlobalCoreFunctionsMultiFiles,
				TheListOfTransplantedMarkers,
				FinalListOfTransplantedFunctionsAsMarkers,
				tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);

		fflush(stdout);

		addLocsFromSourceToDestination(coreFunctionSourceFile,
									   tempSourceCodeGlobalsContent, TXLToolsPath);

		// TODO rewrite sGlobalVarTypesDeclDependencyCOREFUNCTIONS to include interfaceHeader.h
		/* LOS temporary code to add include */
		char * listOfNeededHeadFilesForCoreGraftFunction;
		listOfNeededHeadFilesForCoreGraftFunction = (char *) malloc(500 * sizeof(char));
		sprintf(listOfNeededHeadFilesForCoreGraftFunction, "%stemp_interface_header.out", TXLTemporaryMultiFileFolder);

		FILE *fCurrentSourceFiles = fopen(listOfNeededHeadFilesForCoreGraftFunction, "w+");
		fprintf(fCurrentSourceFiles, "#include \"InterfaceHeader.h\"\n");
		fclose(fCurrentSourceFiles);

		ListOfString * listOfHeaderFilesForInclude = readListOfStringFromFileAsWords(listOfNeededHeadFilesForCoreGraftFunction);

		addLocsFromSourceToDestination(coreFunctionSourceFile, listOfNeededHeadFilesForCoreGraftFunction, TXLToolsPath);
       /* LOS temporary code to add include */

		DependencyListGlobalCoreFunctionsMultiFiles = NULL;
	}

	char * SkeletonCoreFeatureHeaderMultiFiles;
	SkeletonCoreFeatureHeaderMultiFiles = (char *) malloc(500 * sizeof(char));
	sprintf(SkeletonCoreFeatureHeaderMultiFiles, "%sInterfaceHeader2.h", TXLTemporaryMultiFileFolder);

	addLocsFromSourceToDestination(SkeletonCoreFeatureHeaderMultiFiles,
								   tempHeaderGlobalsContent, TXLToolsPath);


#endif
}

#endif

/* LOS: Extract need functions and global declaration for selcted LOCS */
void extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCsByFile(
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
		char * TXLTemporaryFolder) {
	//needed for extraction of global dependencies for core feature
	ListOfString * FinalListOfTransplantedFunctionsAsMarkersOld = NULL;
	//first add the feature markerd for extraction, since globals for this too must be added
	char * GraftFunctionMarker;
	GraftFunctionMarker = (char *) malloc(500 * sizeof(char));
	sprintf(GraftFunctionMarker, "/* %s */", GraftFunctionName);
	addNewString(&FinalListOfTransplantedFunctionsAsMarkersOld,
				 GraftFunctionMarker);

	//to be checked not to add all functions for all globals, but just for one possible to be transplanted!!!
	CallDependency * ListOfNeededFunctionsForGlobals =
			extractNeededFunctionsForGlobals(ListOfFinalGlobalDeclarations,
					outputFileGlobalDependenciesOnFunctions);

	extractCoreFunctionsCalledInIndividual(ListOfNeededFunctionsForAllLOCs,
			candidateSourceCode, SkeletonCoreFeatureHeader,
			sourceOutputCoreFunctionality,
			&FinalListOfTransplantedFunctionsAsMarkersOld,
			ListOfNeededFunctionsForGlobals, TXLTemporaryFolder);

	fflush(stdout);

	ListOfString * FinalListOfTransplantedFunctionsAsMarkers =
			extractFunctionsAsMarkersFromSourceFile(
					sourceOutputCoreFunctionality, TXLTemporaryFolder);

	//for the source core output file extract all the called files
	//this will be the final list of transplated functions as markers

	//ListOfString * TempListOfStrings = returnListOfStringFromMarkersFile(tempListOfMarkers);

	//FOR ALL EXTRACTED FUNCTIONS, ADD THE DEPENDENCIES!!!

	fflush(stdout);
	//maybe HERE!!!!
	DependencyList * DependencyListGlobalCoreFunctions =
			extractDependencyGlobalListForCoreFunctions(
					SourceOutputCoreFunctionalities, tempGlobalDeclarations,
					definedGlobalTypesAndVariablesFile, TXLTemporaryFolder);
	char * tempHeaderGlobalsContent;
	tempHeaderGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempHeaderGlobalsContent, "%stemp_header_decl_for_globals.out",
			TXLTemporaryFolder);
	char * tempSourceCodeGlobalsContent;
	tempSourceCodeGlobalsContent = (char *) malloc(500 * sizeof(char));
	sprintf(tempSourceCodeGlobalsContent, "%stemp_source_for_globals.out",
			TXLTemporaryFolder);

	fflush(stdout);

	extractNeededGlobalDeclarationsAndHeaderForSkeletonAndInterface(
			ListOfFinalGlobalDeclarations, GlobalDependencyList,
			SkeletonDependenciesOnGlobals, DependencyListGlobalCoreFunctions,
			TheListOfTransplantedMarkers,
			FinalListOfTransplantedFunctionsAsMarkers,
			tempSourceCodeGlobalsContent, tempHeaderGlobalsContent);

	fflush(stdout);

	addLocsFromSourceToDestination(sourceOutputCoreFunctionality,
			tempSourceCodeGlobalsContent, TXLToolsPath);
	addLocsFromSourceToDestination(SkeletonCoreFeatureHeader,
			tempHeaderGlobalsContent, TXLToolsPath);
}

/*
 double computeFitness(char * IndividualMakeFileTarget, int TotalIDsInHostSymbolTable, int MappedHostIDsInIndividual) {
 double fitness;
 double fitnessForCompile;
 double fitnessForTestCases = 0;
 double fitnessForMappedIDs;

 fitnessForMappedIDs = 0.3 * MappedHostIDsInIndividual / TotalIDsInHostSymbolTable;

 char * command;
 command = (char *) malloc(1000 * sizeof (char));
 sprintf(command, "cd %s \nmake %s", TransplantResultLocation, IndividualMakeFileTarget);

 int result = system(command);
 if (result != 0) {
 fitnessForCompile = 0;
 } else {
 fitnessForCompile = 0.35;

 //just if it compiled is sense in running the test suite!
 char * commandRunTestCases;
 commandRunTestCases = (char *) malloc(500 * sizeof (char));

 sprintf(commandRunTestCases, "%s%s", TransplantResultLocation, IndividualMakeFileTarget);


 FILE *fp;
 char * line;
 line = (char *) malloc(1000 * sizeof (char));

 fp = popen(commandRunTestCases, "r");
 if (fp == NULL) {
 printf("Failed to run command\n");
 fitnessForTestCases = 0;
 } else {
 while (fgets(line, 1000, fp) != NULL) {
 printf("%s", line);
 }
 pclose(fp);

 int fitnessPercentage;
 sscanf(line, "%d", &fitnessPercentage);

 fitnessForTestCases = 0.35 * (fitnessPercentage / 100);

 }
 }
 fitness = fitnessForCompile + fitnessForTestCases + fitnessForMappedIDs;
 return fitness;
 }
 */

void instantiateAnIndividual(ListOfString * SkeletonSourceCode,
		char * GraftInterfaceTempOutput, char * sourceOutputCoreFunctionality,
		char * skeletonInterfaceSourceCodeOutput,
		ArrayOfStrings SkeletonLOCsArray,
		DependencyList * ListOfDependenciesForStatements,
		CallDependency * ListOfNeededFunctionsForAllLOCs,
		GlobalDeclarations ListOfFinalGlobalDeclarations,
		DependencyList * GlobalDependencyList,
		DependencyList * SkeletonDependenciesOnGlobals,
		char * tempGlobalDeclarations,
		char * definedGlobalTypesAndVariablesFile, char * GraftFunctionName,
		char * finalGraftInterfaceFile, int TotalIDsInHostSymbolTable,
		char * individualFileName, char * GlobalFctDependOutput,
		char * TXLTemporaryFolder) {

	int MappedGraftHostIDs;

	char * finalHostInterfaceOutput;
	finalHostInterfaceOutput = (char *) malloc(500 * sizeof(char));
	sprintf(finalHostInterfaceOutput, "%stemp_interface_source_file.out",
			TXLTemporaryFolder);
	ListOfString * TheListOfTransplantedMarkers = NULL;
	ListOfString * candidateSourceCode = generateNewSkeletonForCandidate(
			SkeletonLOCsArray, SkeletonSourceCode, individualFileName,
			ListOfDependenciesForStatements, &TheListOfTransplantedMarkers,
			&MappedGraftHostIDs, TXLTemporaryFolder);

	extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCs(
			sourceOutputCoreFunctionality, ListOfNeededFunctionsForAllLOCs,
			ListOfFinalGlobalDeclarations, GlobalDependencyList,
			SkeletonDependenciesOnGlobals, tempGlobalDeclarations,
			definedGlobalTypesAndVariablesFile, candidateSourceCode,
			TheListOfTransplantedMarkers, GlobalFctDependOutput, TXLTemporaryFolder);

	instantiateGraftSkeletonInInterface(candidateSourceCode,
			GraftInterfaceTempOutput, skeletonInterfaceSourceCodeOutput,
			JustCoreFeatureHeaderName);

	addLocsFromSourceToDestination(skeletonInterfaceSourceCodeOutput,
			SourceOutputCoreFunctionalities, TXLToolsPath);
	addLocsFromSourceToDestination(finalGraftInterfaceFile,
			SkeletonCoreFeatureHeader, TXLToolsPath);

	double fitness = computeFitness("Individual.x", TotalIDsInHostSymbolTable,
			MappedGraftHostIDs, 0, TransplantResultLocation);
	printf("Fitness for individual: %s is : %0.2f\n", "Individual.x", fitness);
	fflush(stdout);
}

void instantiateAnIndividualFromGPIndividual(ListOfString * SkeletonSourceCode,
		char * GraftInterfaceTempOutput, char * sourceOutputCoreFunctionality,
		char * skeletonInterfaceSourceCodeOutput,
		ArrayOfStrings SkeletonLOCsArray,
		DependencyList * ListOfDependenciesForStatements,
		CallDependency * ListOfNeededFunctionsForAllLOCs,
		GlobalDeclarations ListOfFinalGlobalDeclarations,
		DependencyList * GlobalDependencyList,
		DependencyList * SkeletonDependenciesOnGlobals,
		char * tempGlobalDeclarations,
		char * definedGlobalTypesAndVariablesFile, char * GraftFunctionName,
		char * finalGraftInterfaceFile, int TotalIDsInHostSymbolTable,
		GPIndividual * individual,
		DependencyListWithID * dependencyListForAbstract,
		char * GlobalDependenciesOnFunctions, char * TXLTemporaryFolder) {

	//int MappedGraftHostIDs;

	char * finalHostInterfaceOutput;
	finalHostInterfaceOutput = (char *) malloc(500 * sizeof(char));
	sprintf(finalHostInterfaceOutput, "%stemp_interface_source_file.out",
			TXLTemporaryFolder);
	ListOfString * TheListOfTransplantedMarkers = NULL;
	ListOfString * candidateSourceCode =
			generateNewSkeletonForCandidateFromGPIndividual(SkeletonLOCsArray,
					SkeletonSourceCode, individual,
					ListOfDependenciesForStatements,
					&TheListOfTransplantedMarkers, dependencyListForAbstract, TXLTemporaryFolder);

	extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCs(
			sourceOutputCoreFunctionality, ListOfNeededFunctionsForAllLOCs,
			ListOfFinalGlobalDeclarations, GlobalDependencyList,
			SkeletonDependenciesOnGlobals, tempGlobalDeclarations,
			definedGlobalTypesAndVariablesFile, candidateSourceCode,
			TheListOfTransplantedMarkers, GlobalDependenciesOnFunctions,
			TXLTemporaryFolder);

	instantiateGraftSkeletonInInterface(candidateSourceCode,
			GraftInterfaceTempOutput, skeletonInterfaceSourceCodeOutput,
			JustCoreFeatureHeaderName);

	addLocsFromSourceToDestination(skeletonInterfaceSourceCodeOutput,
			SourceOutputCoreFunctionalities, TXLToolsPath);
	addLocsFromSourceToDestination(finalGraftInterfaceFile,
			SkeletonCoreFeatureHeader, TXLToolsPath);

	double fitness = computeFitness("Individual.x", TotalIDsInHostSymbolTable,
			0, 0, TransplantResultLocation);
	printf("Fitness for individual: %s is : %0.2f\n", "Individual.x", fitness);
	fflush(stdout);
}

void completeInstantiation(ListOfString * SkeletonSourceCode,
		char * GraftInterfaceTempOutput, char * sourceOutputCoreFunctionality,
		char * skeletonInterfaceSourceCodeOutput,
		ArrayOfStrings SkeletonLOCsArray,
		DependencyList * ListOfDependenciesForStatements,
		CallDependency * ListOfNeededFunctionsForAllLOCs,
		GlobalDeclarations ListOfFinalGlobalDeclarations,
		DependencyList * GlobalDependencyList,
		DependencyList * SkeletonDependenciesOnGlobals,
		char * tempGlobalDeclarations,
		char * definedGlobalTypesAndVariablesFile, char * GraftFunctionName,
		char * finalGraftInterfaceFile, int TotalIDsInHostSymbolTable,
		char * GlobalDependenciesOnFunctions,
		char * TXLTemporaryFolder) {

	ListOfString * TheListOfTransplantedMarkers = createTheListOfAllMarkers(
			SkeletonSourceCode, TXLTemporaryFolder);

	extractNeededFunctionsAndGlobalDeclarationsForSelectedLOCs(
			sourceOutputCoreFunctionality, ListOfNeededFunctionsForAllLOCs,
			ListOfFinalGlobalDeclarations, GlobalDependencyList,
			SkeletonDependenciesOnGlobals, tempGlobalDeclarations,
			definedGlobalTypesAndVariablesFile, SkeletonSourceCode,
			TheListOfTransplantedMarkers, GlobalDependenciesOnFunctions,
			TXLTemporaryFolder);

	//this is the place for GP!!!
	//for loop instantiation for all population, params for instantiateGPCandidateWithExistingGlobalAndCoreFeature
	//are send to GP algorithm

	int MappedGraftHostIDs;
	MappedGraftHostIDs = instantiateGPCandidateWithExistingGlobalAndCoreFeature(
			SkeletonSourceCode, SkeletonLOCsArray, "individual.in",
			ListOfDependenciesForStatements, GraftInterfaceTempOutput,
			skeletonInterfaceSourceCodeOutput, finalGraftInterfaceFile, TXLTemporaryFolder);

	double fitness = computeFitness("Individual.x", TotalIDsInHostSymbolTable,
			MappedGraftHostIDs, 0, TransplantResultLocation);
	printf("Fitness for individual: %s is : %0.2f\n", "Individual.x", fitness);
	fflush(stdout);
}
