/* 
 * File:   main.c
 * Author: ---
 *
 * Created on 12 June 2014, 04:20
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GenTrans.h"
#include "Skeleton.h"
#include "SkeletonMapping.h"
#include "ListOfString.h"
#include "FunctionElement.h"
#include "DependencyList.h"
#include "folderContent.h"

/*
 * 
 */

int abstractIDNumber = 0;

void solveAbstractValues(SkeletonMapping * mappingsForSkeletonInstantiation,
		Mapping * localExistingMappings, char * callerName,
		SkeletonMapping * currentExistingMappings, char * currentCalled,
		Mapping ** newListOfAbstractMappings, Mapping ** newAbstractValues,
		SymbolTable * GraftSymbolTable,
		SymbolTable ** ChanghedAbstractIDSymbolTable) {
	SkeletonMapping * currentSkeletonMappings;
	currentSkeletonMappings = returnMappingsForFunction( //HERE SHOULD BE ADDED!!!
			mappingsForSkeletonInstantiation, callerName);
//LOSTEMP
    if(!currentSkeletonMappings)
        printf("ERROR");

    SkeletonMapping * currentAbstractMappings;
	currentAbstractMappings = returnMappingsForFunction(currentExistingMappings,
			currentCalled);
	Mapping * aux = currentAbstractMappings->mappings;

	Mapping * auxLocalMappings = localExistingMappings;

	while (auxLocalMappings && currentSkeletonMappings) {

		    addNewMapping(&currentSkeletonMappings->mappings, auxLocalMappings->source, auxLocalMappings->destination);

		auxLocalMappings = auxLocalMappings->next;
	}

	while (aux) {
		Mapping * skeletonMappingAux = NULL;
		if (currentSkeletonMappings) {
			skeletonMappingAux = currentSkeletonMappings->mappings;
		}
		int signal = 0;
		while (skeletonMappingAux && !signal) {
			if (!strcmp(skeletonMappingAux->source, aux->destination)) {
				signal = 1;
			} else {
				skeletonMappingAux = skeletonMappingAux->next;
			}
		}
		char * newAbstractName;
		newAbstractName = (char *) malloc(500 * sizeof(char));
		//sprintf(newAbstractName, "called_from_%s_%s", callerName, aux->source);
		sprintf(newAbstractName, "$ABSTRACT_%d", abstractIDNumber);
		abstractIDNumber++;
		if (signal) {
			addNewMapping(&(*newListOfAbstractMappings), newAbstractName,
					skeletonMappingAux->destination);
		} else {
			addNewMapping(&(*newListOfAbstractMappings), newAbstractName,
					aux->destination);
		}
		addNewMapping(&(*newAbstractValues), aux->source, newAbstractName);

		char * typeOfID = searchForASymbolTableEntry(GraftSymbolTable,
				aux->source);
		if (typeOfID) {
			addNewVariableDeclaration(ChanghedAbstractIDSymbolTable, typeOfID,
					newAbstractName);
		}

		free(newAbstractName);
		aux = aux->next;
	}
}

int UniqueGlobalID = 0;

void callUniqueLocalDeclGenerator(char * tempFunctionFile,
		char * outputTempFile, char * initialFunctionName, char * uniqueId) {
	//TODO: Fix this!
	//call uniqueLocalDeclarationGeneralizer

	// Get just the ID of the current called function.

	char * token;
	char * state;
	token = strtok_r(uniqueId, initialFunctionName, &state);

	char * commandInstantiate;
	commandInstantiate = (char *) malloc(400 * sizeof(char));
	sprintf(commandInstantiate, "%suniqueLocalVarDecls.x", TXLToolsPath);

	char * commandTXL;
	commandTXL = (char *) malloc(5000 * sizeof(char));
	sprintf(commandTXL, "%s %s %s %s %s", commandInstantiate, tempFunctionFile,
			outputTempFile, token, ConsoleStderrOutput);
	//UniqueGlobalID ++;

	int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR! uniqueLocalVarDecls.x \n");
		return;
	//	exit(1);
	}

}

ListOfString * solveCalledIDs(FunctionElement * head,
		SkeletonMapping * currentMappings, char * mappedFunctionID,
		char * command, char * initialFunctionFile, char * initialMappingsFile,
		char * skeletonFctInstantiate, SkeletonMapping * mappingsForSkeleton,
		SkeletonMapping * ListOfExistingMappings,
		Mapping ** FinalListOfAbstractMappings, SymbolTable * GraftSymbolTable,
		SymbolTable ** ChanghedAbstractIDSymbolTable, char * TXLTemporaryFolder) {
	SkeletonMapping * current;
	Mapping * newAbstractValues = NULL;
	ListOfString * aux = NULL;
	aux = head->LOCs;

	FILE * inputForInstantiation = fopen(initialFunctionFile, "w");
	printAFunctionElement(inputForInstantiation, head);
	fclose(inputForInstantiation);

	char * outputAdditionalMappingsFile = (char *) malloc(3000 * sizeof(char));
	sprintf(outputAdditionalMappingsFile, "%s%s", TXLTemporaryFolder,
			"temp_output_additional_mappings.out");
	// TODO: write the rest of the mappings from the output of the following function call:

	callUniqueLocalDeclGenerator(initialFunctionFile,
			outputAdditionalMappingsFile, head->NameOfFunction,
			mappedFunctionID);

	Mapping * localExistingMappings = NULL;

	FILE * outputLocalVarMappingsForAbstract = fopen(
			outputAdditionalMappingsFile, "r");

	char * sourceLAbst = (char *) malloc(1000 * sizeof(char));
	char * destLAbst = (char *) malloc(1000 * sizeof(char));

	while (fscanf(outputLocalVarMappingsForAbstract, "%s %s", sourceLAbst,
			destLAbst) != EOF) {
		addNewMapping(&localExistingMappings, sourceLAbst, destLAbst);
	}

	fclose(outputLocalVarMappingsForAbstract);

	while (aux) {
		char * marker;
		marker = (char *) malloc(400 * sizeof(char));
		char * uniqueFunctionName;
		uniqueFunctionName = (char *) malloc(400 * sizeof(char));
		sscanf(aux->el, "%s", marker);
		if (!strcmp(marker, FUNCTION_CALL_MARKER)) {
			char * functionName;
			functionName = (char*) malloc(400 * sizeof(char));
			sscanf(aux->el, "%s %s %s", marker, functionName,
					uniqueFunctionName);

			fflush(stdout);

			solveAbstractValues(mappingsForSkeleton, localExistingMappings,
					mappedFunctionID, ListOfExistingMappings,
					uniqueFunctionName, &(*FinalListOfAbstractMappings),
					&newAbstractValues, GraftSymbolTable,
					ChanghedAbstractIDSymbolTable);

			fflush(stdout);
		}
		aux = aux->next;
		free(marker);
		free(uniqueFunctionName);
	}

	Mapping * auxAbstract;
	auxAbstract = newAbstractValues;

	current = returnMappingsForFunction(currentMappings, mappedFunctionID);

	//fix current. Search in the list of all previous mapping, and if
	//the current destination is the source of an another mapping, replace the current destination with the other
	//mapping!!!
#if 1
	Mapping * currentExistingMappingsAux = current->mappings;
	while (currentExistingMappingsAux) {
		SkeletonMapping * auxForArgs = currentMappings;
		while (auxForArgs) {

			Mapping * auxMappingLocal = auxForArgs->mappings;
			while(auxMappingLocal) {
				if(!strcmp(currentExistingMappingsAux->destination, auxMappingLocal->source)) {
					currentExistingMappingsAux->destination = (char *) malloc (1000 * sizeof(char));
					strcpy(currentExistingMappingsAux->destination, auxMappingLocal->destination);
				}
				auxMappingLocal = auxMappingLocal->next;
			}
			auxForArgs = auxForArgs->next;
		}

		currentExistingMappingsAux = currentExistingMappingsAux->next;
	}

	fflush(stdout);
#endif

	fflush(stdout);

	FILE * symbolTableResults = fopen(initialMappingsFile, "w");
	Mapping * currentListOfMappings = NULL;
	if (current) {
		currentListOfMappings = current->mappings;
	}
	while (currentListOfMappings) {
		fprintf(symbolTableResults, "\"%s\" \"%s\" ",
				currentListOfMappings->source,
				currentListOfMappings->destination);
		currentListOfMappings = currentListOfMappings->next;
	}

	// fix label
	fprintf(symbolTableResults, "\"LABEL_%s\" \"LABEL_%s\" ",
			head->NameOfFunction, mappedFunctionID);

	// fix the return value -> add the unique ID of the function call!!!
	fprintf(symbolTableResults,
			"\"$ABSTRETVAL_ret_%s\" \"$ABSTRETVAL_ret_%s\" ",
			head->NameOfFunction, mappedFunctionID);

	FILE * outputLocalVarMappings = fopen(outputAdditionalMappingsFile, "r");

	char * sourceL = (char *) malloc(1000 * sizeof(char));
	char * destL = (char *) malloc(1000 * sizeof(char));

	while (fscanf(outputLocalVarMappings, "%s %s", sourceL, destL) != EOF) {
		fprintf(symbolTableResults, "\"%s\" \"%s\" ", sourceL, destL);
	}

	fclose(outputLocalVarMappings);

	while (auxAbstract) {
		fprintf(symbolTableResults, "\"%s\" \"%s\" ", auxAbstract->source,
				auxAbstract->destination);
		auxAbstract = auxAbstract->next;
	}
	fclose(symbolTableResults);
	char * commandTXL;
	commandTXL = (char *) malloc(5000 * sizeof(char));
	//printf("[TXL] InstantiateFunctionsInSkeleton.x >> Instantiate functions in skeleton\n");
	sprintf(commandTXL, "%s %s %s %s %s", command, initialFunctionFile,
			initialMappingsFile, skeletonFctInstantiate, ConsoleNullOutput);
	//TODO: In initial mappings file add mappings from all the declarations to new names with the unique id!
#ifdef INSTANTIATE_FUCNTIONS_IN_SKELETON
	int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR! InstantiateFunctionsInSkeleton.x \n");
		return NULL;
	}
#endif
	free(commandTXL);
	FILE * resultedFunction = fopen(skeletonFctInstantiate, "r");
	ListOfString * newListOfString = NULL;
	char * line = (char *) malloc(1000 * sizeof(char));
	while (fgets(line, 400, resultedFunction) != NULL) {
		if (strcmp(line, "\n")) {
			addNewString(&newListOfString, line);
		}
	}
	addNewString(&newListOfString, LINE_END);
	free(line);
	fclose(resultedFunction);

	fflush(stdout);

	return newListOfString;

}

void solveAbstractValuesFromProgramEntryPoint(char * callerName,
		SkeletonMapping * currentExistingMappings, char * currentCalled,
		Mapping ** newListOfAbstractMappings, Mapping ** newAbstractValues,
		SymbolTable * GraftSymbolTable,
		SymbolTable ** ChanghedAbstractIDSymbolTable) {
	SkeletonMapping * currentAbstractMappings;
	currentAbstractMappings = returnMappingsForFunction(currentExistingMappings,
			currentCalled);
	Mapping * aux = currentAbstractMappings->mappings;
	while (aux) {
		char * newAbstractName;
		newAbstractName = (char *) malloc(500 * sizeof(char));
		//sprintf(newAbstractName, "called_from_%s_%s", callerName, aux->source);
		sprintf(newAbstractName, "$ABSTRACT_%d", abstractIDNumber);
		abstractIDNumber++;
		addNewMapping(&(*newListOfAbstractMappings), newAbstractName,
				aux->destination);
		addNewMapping(&(*newAbstractValues), aux->source, newAbstractName);

		char * typeOfID = searchForASymbolTableEntry(GraftSymbolTable,
				aux->source);
		if (typeOfID) {
			addNewVariableDeclaration(ChanghedAbstractIDSymbolTable, typeOfID,
					newAbstractName);
		}

		free(newAbstractName);
		aux = aux->next;
	}
}

ListOfString * fixAbstractsFromProgramEntryPoint(FunctionElement * head,
		char * mappedFunctionID, char * command, char * initialFunctionFile,
		char * initialMappingsFile, char * skeletonFctInstantiate,
		SkeletonMapping * ListOfExistingMappings,
		Mapping ** FinalListOfAbstractMappings, SymbolTable * GraftSymbolTable,
		SymbolTable ** ChanghedAbstractIDSymbolTable) {
    printf("\tFixing abstract first.\n");
	Mapping * newAbstractValues = NULL;
	ListOfString * aux = NULL;
	aux = head->LOCs;
	while (aux) {
		char * marker;
		marker = (char *) malloc(400 * sizeof(char));
		char * uniqueFunctionName;
		uniqueFunctionName = (char *) malloc(400 * sizeof(char));
		sscanf(aux->el, "%s", marker);
		if (!strcmp(marker, FUNCTION_CALL_MARKER)) {
			char * functionName;
			functionName = (char*) malloc(400 * sizeof(char));
			sscanf(aux->el, "%s %s %s", marker, functionName,
					uniqueFunctionName);

			solveAbstractValuesFromProgramEntryPoint(mappedFunctionID,
					ListOfExistingMappings, uniqueFunctionName,
					&(*FinalListOfAbstractMappings), &newAbstractValues,
					GraftSymbolTable, ChanghedAbstractIDSymbolTable);
		}
		aux = aux->next;
		free(marker);
		free(uniqueFunctionName);
	}

	ListOfString * anewListOfString  = head->LOCs;

	Mapping * auxAbstract;
	auxAbstract = newAbstractValues;
	FILE * inputForInstantiation = fopen(initialFunctionFile, "w");
	fflush(stdout);
	printAFunctionElement(inputForInstantiation, head);
	FILE * symbolTableResults = fopen(initialMappingsFile, "w");
	while (auxAbstract) {
		// TODO: check here
		fprintf(symbolTableResults, "\"%s\" \"%s\" ", auxAbstract->source,
				auxAbstract->destination);
		auxAbstract = auxAbstract->next;
	}
	fflush(stdout);
	fclose(inputForInstantiation);
	fclose(symbolTableResults);
	char * commandTXL;
	commandTXL = (char *) malloc(5000 * sizeof(char));

    printf("\t\t[TXL] InstantiateFunctionsInSkeleton >> instantate function in skeleton\n");
	sprintf(commandTXL, "%s %s %s %s %s", command, initialFunctionFile,
			initialMappingsFile, skeletonFctInstantiate, ConsoleNullOutput);
	int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR! fixAbstractsFromProgramEntryPoint");
		system("open ErrorFile.out");
		exit(1);
	}

	FILE * resultedFunction = fopen(skeletonFctInstantiate, "r");

	ListOfString * newListOfString = NULL;
	char * line = (char *) malloc(1000 * sizeof(char));
	while (fgets(line, 400, resultedFunction) != NULL) {
		if (strcmp(line, "\n")) {
			addNewString(&newListOfString, line);
		}
	}
	fclose(resultedFunction);
	//addNewString(&newListOfString, LINE_END);
	free(line);
    free(commandTXL);
	return newListOfString;
}

ListOfString * ListOfRecursiveFunctionsInlined = NULL;

void ReplaceFunctionCalls(ListOfString * ListOfRecursiveFunc, char * currentFunctionName, FunctionElement * Original, FunctionElement ** Output,
		SkeletonMapping * mappingsForSkeleton, char * command,
		char * initialFunctionFile, char * initialMappingsFile,
		char * skeletonFctInstantiate, SkeletonMapping * ListOfExistingMappings,
		char * callerUniqueName, Mapping ** FinalListOfAbstractMappings,
		SymbolTable * GraftSymbolTable,
		SymbolTable ** ChanghedAbstractIDSymbolTable, char * TXLTemporaryFolder) {

    char *listOfFunctionFoundForCallID = NULL;
    listOfFunctionFoundForCallID = (char *) malloc(100 * sizeof(char));
    sprintf(listOfFunctionFoundForCallID, "%slist_function_found_for_call_ID.out", TXLTemporaryFolder);

#ifdef DEBUGING
    char *skeletonExtended = NULL;
    skeletonExtended = (char *) malloc(100 * sizeof(char));
    sprintf(skeletonExtended, "%spartial_skeleton_extended.out", DebugFolder);
#endif

	FunctionElement * ExtendedSk;
	ExtendedSk = *Output;
	int signal = 0;
	ListOfString * aux = NULL;
	char * antAux = (char *) malloc(400 * sizeof(char));
    char * marker;
	aux = ExtendedSk->LOCs;
	int countFunctions  = 1;
	while (aux) {
		marker = (char *) malloc(400 * sizeof(char));
		char * uniqueFunctionName;
		uniqueFunctionName = (char *) malloc(400 * sizeof(char));
		if (aux->el) {
			sscanf(aux->el, "%s", marker);
			if (!strcmp(marker, FUNCTION_CALL_MARKER)) {
				char * functionName;
				functionName = (char*) malloc(400 * sizeof(char));
				sscanf(aux->el, "%s %s %s", marker, functionName,
						uniqueFunctionName);

				// Do not inline the core function!
				if (strcmp(functionName, GraftFunctionName)) {
					FunctionElement * searchedEl = NULL;
					searchedEl = searchAnElement(Original, functionName);
					ListOfString * searchedListOfString = NULL;
					if (searchedEl != NULL) {

                       if( searchStringInListOfStrings(ListOfRecursiveFunc, functionName) ) {
                             printf("\t\t[%d] %s\n",countFunctions, functionName);
                             countFunctions++;
                            if(!searchStringInListOfStrings(ListOfRecursiveFunctionsInlined,functionName)){
                                searchedListOfString = solveCalledIDs(searchedEl,
                                                                      mappingsForSkeleton, uniqueFunctionName,
                                                                      command, initialFunctionFile,
                                                                      initialMappingsFile, skeletonFctInstantiate,
                                                                      mappingsForSkeleton, ListOfExistingMappings,
                                                                      &(*FinalListOfAbstractMappings),
                                                                      GraftSymbolTable, ChanghedAbstractIDSymbolTable,
                                                                      TXLTemporaryFolder);

                                addNewString(&ListOfRecursiveFunctionsInlined, functionName);
                            }
                        } else {
                            printf("\t\t[%d] %s\n",countFunctions, functionName);
                            countFunctions++;
                            searchedListOfString = solveCalledIDs(searchedEl,
                                                                  mappingsForSkeleton, uniqueFunctionName,
                                                                  command, initialFunctionFile,
                                                                  initialMappingsFile, skeletonFctInstantiate,
                                                                  mappingsForSkeleton, ListOfExistingMappings,
                                                                  &(*FinalListOfAbstractMappings),
                                                                  GraftSymbolTable, ChanghedAbstractIDSymbolTable,
                                                                  TXLTemporaryFolder);
                        }
						//Save list of function from last execution
                //        addAStringsInTheEndFileLN(functionName, listOfFunctionFoundForCallID);

                        if (searchedListOfString != NULL) {
                            //first is the function call, so not add it
                            replaceOneLineWithAList(&ExtendedSk->LOCs,
                                                    searchedListOfString->next, aux->el);
#ifdef DEBUGING
                            /* show partial skeleton with remained call the funcitons */
                            printAListOfStringsNL(ExtendedSk->LOCs, skeletonExtended);
#endif
                            signal = 1;
						}

					}

					strcpy(callerUniqueName, uniqueFunctionName);
                    strcpy(currentFunctionName, functionName);
					freeListOfStrings(&searchedListOfString);
				}
                strcpy(antAux,functionName);
              ///  removeString(ListOfRecursiveFunc, functionName);
                free(functionName);
			}
		}
		aux = aux->next;
		free(marker);
		free(uniqueFunctionName);
        fflush(stdout);
	}

//TODO delete here skeletonExtended.out
//replacleFunctionCalls() is no more recursive
	///if (signal && !searchStringInListOfStrings(ListOfRecursiveFunctionsInlined, currentFunctionName)) {
    if (signal) {
        ReplaceFunctionCalls(ListOfRecursiveFunc, currentFunctionName, Original, Output, mappingsForSkeleton, command,
                             initialFunctionFile, initialMappingsFile,
                             skeletonFctInstantiate, ListOfExistingMappings,
                             callerUniqueName, FinalListOfAbstractMappings, GraftSymbolTable,
                             ChanghedAbstractIDSymbolTable, TXLTemporaryFolder);
	} else
		return;

}

SkeletonMapping * readSkeletonMappings(char * mappingsFilePath) {

    FILE * finMappings = fopen(mappingsFilePath, "r");
    if (finMappings == NULL) {
        printf("ERROR: %s not found%s.\n", mappingsFilePath);
        exit(1);
    }

	SkeletonMapping * currentMappings = NULL;
	char * source;
	char * destination;
	source = (char *) malloc(800 * sizeof(char));
	destination = (char *) malloc(800 * sizeof(char));
	char * line;
	line = (char *) malloc(800 * sizeof(char));
	char * currentName;
	currentName = (char*) malloc(800 * sizeof(char));
	while (fgets(line, 400, finMappings) != NULL) {
		sscanf(line, "%s", currentName);
		SkeletonMapping * current = addNewSkeletonMapping(&currentMappings,
				currentName);
		int s = 0;
		while (s == 0 && fgets(line, 400, finMappings) != NULL) {
			if (!strcmp(line, LINE_END)) {
				s = 1;
			} else {
				char * token;
				token = strtok(line, " ");
				strcpy(source, token);
				token = strtok(NULL, "\n");
				if(token == NULL){
					token = (char *) malloc(8 * sizeof(char));
					strcpy(token, "void1");
				}

				strcpy(destination, token);
				//sscanf(line, "%s %s", source, destination);
				addNewMapping(&current->mappings, source, destination);
			}
		}
	}
    fclose(finMappings);
	free(source);
	free(destination);
	free(line);
	free(currentName);
	return currentMappings;
}

SkeletonMapping * readExistingMappings(FILE * fin) {
	SkeletonMapping * currentMappings = NULL;
	char * source;
	char * destination;
	source = (char *) malloc(800 * sizeof(char));
	destination = (char *) malloc(800 * sizeof(char));
	char * line;
	line = (char *) malloc(800 * sizeof(char));
	SkeletonMapping * current = addNewSkeletonMapping(&currentMappings,
			"PROGRAM");
	while (fgets(line, 400, fin) != NULL) {
		sscanf(line, "%s %s", source, destination);
		addNewMapping(&current->mappings, source, destination);
	}
	free(source);
	free(destination);
	free(line);
	return currentMappings;
}

ListOfString * InstantiateACandidate(FunctionElement * head,
		Mapping * currentMappings, char * command, char * initialFunctionFile,
		char * initialMappingsFile, char * skeletonFctInstantiate) {

	if (!currentMappings) {
		return NULL;
	} else {
		FILE * inputForInstantiation = fopen(initialFunctionFile, "w");
		printAFunctionElement(inputForInstantiation, head);
		FILE * symbolTableResults = fopen(initialMappingsFile, "w");
		Mapping * currentListOfMappings = currentMappings;
		while (currentListOfMappings) {
			// TODO: check this
			//first check if the current string has quatations:
			if ((currentListOfMappings->destination[0]) == '"') {
				char * newDestination = (char *) malloc(3000 * sizeof(char));
				sprintf(newDestination, "\\%s",
						currentListOfMappings->destination);
				int originalLength = strlen(newDestination);
				newDestination[originalLength - 1] = '\\';
				newDestination[originalLength] = '"';
				newDestination[originalLength + 1] = 0;

				fprintf(symbolTableResults, "\"%s\" \"%s\" ",
						currentListOfMappings->source, newDestination);
			}

			else {
				fprintf(symbolTableResults, "\"%s\" \"%s\" ",
						currentListOfMappings->source,
						currentListOfMappings->destination);
			}
			currentListOfMappings = currentListOfMappings->next;
		}
		fclose(inputForInstantiation);
		fclose(symbolTableResults);
		char * commandTXL;
		commandTXL = (char *) malloc(5000 * sizeof(char));
		fflush(stdout);
		sprintf(commandTXL, "%s %s %s %s %s", command, initialFunctionFile,
				initialMappingsFile, skeletonFctInstantiate, ConsoleStderrOutput);
        printf("\t\t[TXL] instantiateFunctionsInSkeleton.x >> Instantiate functions in skeleton\n");
//LOSCHANGE23
#if !defined(FAST_RUNNING)
		int status = system(commandTXL);
		if (status != 0) {
			printf("ERROR! Instantiate Functions in Skeleton");
			system("open ErrorFile.out");
			exit(1);
		}
#endif
		fflush(stdout);
		FILE * resultedFunction = fopen(skeletonFctInstantiate, "r");
		ListOfString * newListOfString = NULL;
		char * line = (char *) malloc(1000 * sizeof(char));
		while (fgets(line, 400, resultedFunction) != NULL) {
			if (strcmp(line, "\n")) {
				addNewString(&newListOfString, line);
			}
		}
		addNewString(&newListOfString, LINE_END);
		free(line);
		free(commandTXL);
		fclose(resultedFunction);
		return newListOfString;
	}
}

void generateFunctionsForSkeleton(char * graftMethod, char * donorSourceFiles,
		char * transplantWorkingFolder) {
	char sourceFiles[400];
	sprintf(sourceFiles, "%s/sourceFilesInDonor.out", transplantWorkingFolder);
	char headerFiles[400];
	sprintf(headerFiles, "%s/headerFilesInDonor.out", transplantWorkingFolder);
	char * graftFile = "dct.c";
	char resultFileFullPath[400];
	sprintf(resultFileFullPath, "%sgcovParsedResults.out",
			transplantWorkingFolder);
	char * gcovMainMethodMarker = "--main";
	char gcovMainMethod[400];
	sprintf(gcovMainMethod, "%s %s", gcovMainMethodMarker, graftMethod);
	char * outputFile = "outputCFLOW.out";
	char * gcov = " ";
	//char * restOfParams = "-i _ --omit-arguments *.c >";
	char * restOfParams = "--brief -i _ --omit-arguments *.c >";
	char gcovCommand[400];
	char outputFileFullPath[400];
	sprintf(outputFileFullPath, "%s%s", donorSourceFiles, outputFile);
	char graftFileFullPath[400];
	sprintf(graftFileFullPath, "%s%s", donorSourceFiles, graftFile);
	sprintf(gcovCommand, "cd %s \n %s %s %s %s", donorSourceFiles, gcov,
			gcovMainMethod, restOfParams, outputFileFullPath);
	//printf("%s \n", gcovCommand);
	//printf("%s \n", outputFileFullPath);
	fflush(stdout);
	printf("[CFLOW] Obtaining the direct call graph of >%s< function dependencies\n",graftMethod);
	int status1 = system(gcovCommand);
	if (status1 != 0) {
		printf("ERROR");
	}
}

char * statementMarker = "/*@STM*/";
char * declMarker = "/*@DECL*/";
char * compoundStartMarker = "//COMPOUND START:";
char * compoundEndMarker = "//COMPOUND END:";
char * compoundCloseMarker = "/* COMPOUND_CLOSED */";
int currentStmNumber = 0;
int currentDeclNumber = 0;
int currentCompoundNumber = 0;

void fixLineNumbers(ListOfString * element) {
	ListOfString * aux = element;

	while (aux) {
		if (strstr(aux->el, statementMarker)) {
			char * restOfLine;
			restOfLine = strstr((aux->el), statementMarker)
					+ strlen(statementMarker) + 1;
			char * tempString = (char *) malloc(
					(strlen(aux->el) + 10) * sizeof(char));
			strcpy(tempString, restOfLine);

			sprintf(aux->el, "/* STM: %d */%s", currentStmNumber, tempString);
			currentStmNumber++;
		} else if (strstr(aux->el, declMarker)) {
			char * restOfLine;
			restOfLine = strstr((aux->el), declMarker) + strlen(declMarker) + 1;
			char * tempString = (char *) malloc(
					(strlen(aux->el) + 10) * sizeof(char));
			strcpy(tempString, restOfLine);

			sprintf(aux->el, "/* DECL: %d */%s", currentDeclNumber, tempString);
			currentDeclNumber++;
		}
		aux = aux->next;
	}

	aux = element;
	while (aux) {
		if (strstr(aux->el, compoundStartMarker)) {
			ListOfString * auxEndMarker = aux->next;
			int signal = 0;

			char * auxCurrentBeginComp;
			auxCurrentBeginComp = (char *) malloc(500 * sizeof(char));
			strcpy(auxCurrentBeginComp, aux->next->el);

			sprintf(aux->next->el, "/* COMPOUND: %d */%s",
					currentCompoundNumber, auxCurrentBeginComp);

			free(auxCurrentBeginComp);

			//this looks pretty strange... The comparison is between a pointer to the position in the line to look
			//for the end marker, the next after the end marker +1 (one space), and a pointer to the position in the
			//line of start of the compound, the next after the start marker +1 (one space). This should be the same
			//since the same number is for the beginning and the end of a compound statement
			//first check is just for checking the end marker exist, otherwise the second part would crash
			while (auxEndMarker->next && !signal) {
				//char * first = strstr(auxEndMarker->next->el, compoundEndMarker) + strlen(compoundEndMarker) + 1;
				// char * sec = strstr(aux->el, compoundStartMarker) + strlen(compoundStartMarker) + 1;

				if (strstr(auxEndMarker->next->el, compoundEndMarker)
						&& !strcmp(
								strstr(auxEndMarker->next->el,
										compoundEndMarker)
										+ strlen(compoundEndMarker) + 1,
								strstr(aux->el, compoundStartMarker)
										+ strlen(compoundStartMarker) + 1)) {

					char * auxCurrentEndComp;
					auxCurrentEndComp = (char *) malloc(500 * sizeof(char));
					strcpy(auxCurrentEndComp, auxEndMarker->el);
					sprintf(auxEndMarker->el, "/* COMPOUND: %d */%s",
							currentCompoundNumber, auxCurrentEndComp);
					free(auxCurrentEndComp);

					signal = 1;
				}
				auxEndMarker = auxEndMarker->next;
			}
			//the end was not found, so replace the last }\n found

			//       }
			//COMPOUND END: if ($_main_ofile == 0) {}

			if (!signal) {
				auxEndMarker = aux->next;
				ListOfString * foundElement = NULL;
				while (auxEndMarker) {
					if (strstr(auxEndMarker->el, compoundCloseMarker)) {
						signal = 1;
						foundElement = auxEndMarker;
					}
					auxEndMarker = auxEndMarker->next;
				}
				if (signal) {
					char * restOfLine;
					restOfLine = strstr((foundElement->el), compoundCloseMarker)
							+ strlen(compoundCloseMarker);
					sprintf(foundElement->el, "/* COMPOUND: %d */ %s",
							currentCompoundNumber, restOfLine);
				}
			}

			currentCompoundNumber++;
		}

		aux = aux->next;
	}
}

void createDependencyList(char * TXLPath, char * skeletonOutput,
		char * dependencyListOutput) {
    printf("\tCreate and read dependency list from instantiatedSkeleton\n");
	char * command;
	command = (char *) malloc(400 * sizeof(char));
	sprintf(command, "%sSolveDeclarationDependencies.x", TXLPath);
	char * commandTXL;
	commandTXL = (char *) malloc(500 * sizeof(char));
	sprintf(commandTXL, "%s %s %s %s", command, skeletonOutput,
			dependencyListOutput, ConsoleNullOutput);
	printf("\t\t[TXL] SolveDeclarationDependencies.x\n");
	int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR! SolveDeclarationDependencies\n");
		return;
	}
#ifdef DEBUGING
	else
        printf("\t\t\t|>> temp_dependency_list\n");
#endif
	free(command);
	free(commandTXL);
}

void addMarkersAtGotoExtractor(char * skeletonFile, char * markersOutput) {
    printf("\tAdd markers at goto extractor.\n");
	char * command;
	command = (char *) malloc(400 * sizeof(char));
	sprintf(command, "%saddMarkersAtGoto.x", TXLToolsPath);
	char * commandTXL;
	commandTXL = (char *) malloc(1000 * sizeof(char));
    printf("\t\t[TXL] AddMarkersAtGoto.x >> add markers at goto\n");
	sprintf(commandTXL, "%s %s %s %s", command, skeletonFile, markersOutput,
			ConsoleNullOutput);
	int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR! addMarkersAtGoto.x\n");
		system("open ErrorFile.out");
		exit(1);
	}
	free(command);
	free(commandTXL);
}
/*
 * Check if there is any .c file in the current directory and get all functions name
 */
ListOfString * getListOfFunctionsInASourceDirectory(char * dirctoryFullPath, char * outputFileFullPath, char * outputFile){
    ListOfString * ListOfFunctions = NULL;
    char findCommand[400];
    sprintf(findCommand, "cd %s \n find *.c %s", dirctoryFullPath, ConsoleNullOutput);
    int findStatus = system(findCommand);
    char cflowCommand[400];
    sprintf(cflowCommand, "cflow --brief --number *.c >");

    if(findStatus==0) {
        char runCommand[1000];
        sprintf(runCommand, "cd %s \n %s %s", dirctoryFullPath, cflowCommand, outputFile);
        int status = system(runCommand);  // Generate list of recursive functions
        if (status != 0) {
            printf("ERROR: running %s", runCommand);
            exit(1);
        }

        ListOfFunctions = readListOfStringFromFile(outputFileFullPath);
    }
    removeAFileFromADirectory(outputFileFullPath);
    return ListOfFunctions;
}
void findRecursiveFunctions(ListOfString  ** ListOfRecursiveFunctions, char * subdirectory ){

    char * outputFile = "listOfRecursiveFunctionsInDonor.out";
    char * fullPath = (char *) malloc(1000 * sizeof (char));
    sprintf(fullPath, "%s%s", tempDonorSourceFileFolder,&subdirectory[2] );
    strtok(fullPath,"\n");

    char outputFileFullPath[1000];
    sprintf(outputFileFullPath, "%s%s", fullPath, outputFile);
    createFile(outputFileFullPath);

    ListOfString * ListOfFunctions = getListOfFunctionsInASourceDirectory(fullPath, outputFileFullPath, outputFile);

    char * currentLine;
    currentLine = (char *) malloc(4000 * sizeof (char));
    while(ListOfFunctions){
        if(strstr(ListOfFunctions->el, "recursive: see ")){
            strcpy(currentLine, ListOfFunctions->el);
            ListOfString * lineAsWords = NULL;
            readStringAsWords(currentLine,&lineAsWords);
            while(lineAsWords){
                 if(strstr(lineAsWords->el,"()")){
                     strtok(lineAsWords->el,")");
                     strtok(lineAsWords->el,"(");
                     if(!searchStringInListOfStrings(*ListOfRecursiveFunctions,lineAsWords->el))
                        addNewString(ListOfRecursiveFunctions,lineAsWords->el);
                 }

                lineAsWords = lineAsWords->next;
            }
              freeListOfStrings(&lineAsWords) ;
        }
        ListOfFunctions = ListOfFunctions->next;
    }
    free(currentLine);
    freeListOfStrings(&ListOfFunctions);
#ifdef DEBUGING
    char * outputRecursiveFunctions = (char *) malloc(100 * sizeof (char));
    sprintf(outputRecursiveFunctions, "%s%s",DebugFolder, outputFile);
    printAListOfStringsNL(*ListOfRecursiveFunctions,outputRecursiveFunctions);
#endif
}
/*
 * Create subdirectories in TempSourceFolder
 * */
void createSubdirectoriesInTempSourceFolder( ListOfString * ListOfSubdirectories){
    while (ListOfSubdirectories) {
// if(!strcmp(auxListOfSubdirectories->el,".\n")) {
        char subDirectoryFullPath[1000];
        sprintf(subDirectoryFullPath, "%s%s", TXLTemporaryMultiFileFolder, ListOfSubdirectories->el);
        strtok(subDirectoryFullPath, "\n");
        createADirectory(subDirectoryFullPath);
//  }
        ListOfSubdirectories = ListOfSubdirectories->next;
    }
}
/*
 * Read list of subdirectories in Donor
 */
ListOfString * readListOfSubDirectories() {
    char findSubDirectoriesCommand[400]; // Create list of subdirectories in Donor
    char *outputListOfSubdirectories = "ListOfSubdirectoriesInDonor.out";
    char outputSubDirectoryFullPath[100];
    sprintf(outputSubDirectoryFullPath, "%s%s", tempDonorSourceFileFolder, outputListOfSubdirectories);

    sprintf(findSubDirectoriesCommand, "cd %s \n find . -type d > %s", tempDonorSourceFileFolder,
            outputListOfSubdirectories);
    int subDirCommstatus = system(findSubDirectoriesCommand);
    if (subDirCommstatus != 0) {
        printf("ERROR - command: %s\n", findSubDirectoriesCommand);
        exit(1);
    }

    ListOfString *ListOfSubdirectories = readListOfStringFromFile(outputSubDirectoryFullPath);
    createSubdirectoriesInTempSourceFolder(ListOfSubdirectories);
    removeAFileFromADirectory(outputSubDirectoryFullPath); //Remove ListOfSubdirectoriesInDonor.out from TempDonorFiles

    return ListOfSubdirectories;
}

ListOfString * readListOfRecursiveFunctions(){

    ListOfString * ListOfSubdirectories = readListOfSubDirectories();
    ListOfString * ListOfRecursiveFunctions = NULL;
    while(ListOfSubdirectories) {
        findRecursiveFunctions(&ListOfRecursiveFunctions,ListOfSubdirectories->el);
        ListOfSubdirectories = ListOfSubdirectories->next;
    }

    return ListOfRecursiveFunctions;
}
void replaceGotoMarkerInSkeleton(ListOfString * finalSkeletonLOCs, char * tempGotoMarkers, char * skeletonOutput){

    FILE * finGoto = fopen(tempGotoMarkers, "r");
    char * line = (char *) malloc(1000 * sizeof(char));

    while (fgets(line, 1000, finGoto) != NULL) {
        char * initialLabel = (char *) malloc(300 * sizeof(char));
        char * gotoReplacement = (char *) malloc(10 * sizeof(char));

        sscanf(line, "%s %s", gotoReplacement, initialLabel);
        char * newAnnotatedLine = (char *) malloc(1000 * sizeof(char));

        fgets(newAnnotatedLine, 1000, finGoto);

        ListOfString * auxSkeleton = finalSkeletonLOCs;
        while (auxSkeleton) {
            if (strstr(auxSkeleton->el, gotoReplacement)
            && strstr(auxSkeleton->el, initialLabel)) {
                //identified the current label
                free(auxSkeleton->el);
                auxSkeleton->el = (char *) malloc(
                        (strlen(newAnnotatedLine) + 1) * sizeof(char));
                strcpy(auxSkeleton->el, newAnnotatedLine);
            }
            auxSkeleton = auxSkeleton->next;
        }
    }
    fclose(finGoto);
    fflush(stdout);
#ifdef DEBUGING
    printf("\t\t\t|>> InstantiatedSkeleton\n");
#endif
    printAListOfStrings(finalSkeletonLOCs,skeletonOutput);
}

Mapping * createGraftSkeleton(char * transformedFctLOCs,
		char * instantiatonMappings, char * TXLPath, char * skeletonOutput,
		char * existingMappings, char * temporaryFolder,
		char * HostSymbolTableFile, SymbolTable ** FinalGraftSymbolTable,
		DependencyList ** GraftStatementsDependencies,
		ListOfString * reverseCallGraph, char * TXLTemporaryFolder) {
    printf("[AUTOSCALPEL] Create Graft Skeleton \n");

    char * initialFunctionFile= (char *) malloc(100 * sizeof(char));
    sprintf(initialFunctionFile, "%stemp_initial_function.out", temporaryFolder);

    char * initialMappingsFile = (char *) malloc(100 * sizeof(char));
    sprintf(initialMappingsFile, "%stemp_initial_mappings.out", temporaryFolder);

    char * skeletonFctInstantiate = (char *) malloc(100 * sizeof(char));
    sprintf(skeletonFctInstantiate, "%stemp_skeleton_fct_instantiate.out", temporaryFolder);

    SymbolTable * entryPointSymbolTable = NULL;
	SymbolTable * GraftSymbolTable = readSymbolTableAddedEntryPoint( HostSymbolTableFile, &entryPointSymbolTable);

    SkeletonMapping * currentMappings = readSkeletonMappings(instantiatonMappings);
	SkeletonMapping * MappingCandidates = readSkeletonMappings(existingMappings);

	FunctionElement * listOfFunctions = NULL;
	listOfFunctions = readFunctionElemenentListFromFile(transformedFctLOCs, reverseCallGraph);

    FunctionElement * extendedSkeleton = NULL;
	addNewFunctionElement(&extendedSkeleton, listOfFunctions);

	char * uniqueCallerName = (char *) malloc(1000 * sizeof(char));
	strcpy(uniqueCallerName, extendedSkeleton->NameOfFunction);

    char * commandInstantiate = (char *) malloc(100 * sizeof(char));
    sprintf(commandInstantiate, "%sinstantiateFunctionsInSkeleton.x", TXLPath);

    Mapping * finalListOfMappings = NULL;
	ListOfString * fixedAbstractFirst = fixAbstractsFromProgramEntryPoint(
			extendedSkeleton, extendedSkeleton->NameOfFunction,
			commandInstantiate, initialFunctionFile, initialMappingsFile,
			skeletonFctInstantiate, MappingCandidates, &finalListOfMappings,
			GraftSymbolTable, &(*FinalGraftSymbolTable));
	fflush(stdout);

	freeListOfStrings(&(extendedSkeleton->LOCs));
	extendedSkeleton->LOCs = fixedAbstractFirst;

    /* Get list of recursive functions in donor. Used to skip recursive function during inline process*/
    ListOfString * ListOfRecursiveFunctions = readListOfRecursiveFunctions();

    /* Replace (Remaining functions in skeleton are inlined) Function Calls from temp_initial_function.out. */
    printf("\tReplancing remaining function in skeleton\n");
    char * functionName = (char *) malloc(100 * sizeof(char));
    strcpy(functionName, extendedSkeleton->NameOfFunction);
    //LOSCHANGE 5.23 //TODO REMOVE COMMENTS BEFORE RUNNING OTHER TRANSPLANT
/*	ReplaceFunctionCalls(ListOfRecursiveFunctions, functionName, listOfFunctions, &extendedSkeleton, currentMappings,
			commandInstantiate, initialFunctionFile, initialMappingsFile,
			skeletonFctInstantiate, MappingCandidates, uniqueCallerName,
			&finalListOfMappings, GraftSymbolTable, &(*FinalGraftSymbolTable),
			TXLTemporaryFolder);
*/
#ifdef DEBUGING
    /* Remove partial skeleton extended.out used only to analysis */
    char *skeletonExtended = NULL;
    skeletonExtended = (char *) malloc(100 * sizeof(char));
    sprintf(skeletonExtended, "%spartial_skeleton_extended.out", DebugFolder);
   // removeAFileFromADirectory(skeletonExtended);
    free(skeletonExtended);
#endif

    fflush(stdout);
#ifdef DEBUGING
    char *testSkeleton = NULL;
    testSkeleton = (char *) malloc(100 * sizeof(char));
    sprintf(testSkeleton, "%spartialSkeleton.out", DebugFolder);
    printAListOfStrings(extendedSkeleton->LOCs, testSkeleton);
    free(testSkeleton);
#endif

    /* Instantiate a candidate */
    printf("\tInstantiating a candidate.\n");
	ListOfString * instantiatedCandidate = InstantiateACandidate(
			extendedSkeleton, finalListOfMappings, commandInstantiate,
			initialFunctionFile, initialMappingsFile, skeletonFctInstantiate);
	fflush(stdout);
	ListOfString * finalSkeletonLOCs = extendedSkeleton->LOCs;
	fixLineNumbers(finalSkeletonLOCs);

    /* Add and replace goto markers for the goto statements in Skeleton. */
	printAListOfStrings(finalSkeletonLOCs, skeletonOutput); // Print Skeleton >> InstantiatedSkeleton.out
	char * tempGotoMarkers = (char *) malloc(100 * sizeof(char));
	sprintf(tempGotoMarkers, "%stemp_goto_markers.out", TXLTemporaryFolder);
	addMarkersAtGotoExtractor(skeletonOutput, tempGotoMarkers); // Add markers for the goto statements.
    replaceGotoMarkerInSkeleton(finalSkeletonLOCs, tempGotoMarkers, skeletonOutput); // Replace Skeleton for goto statements.

	/* Create and read dependency list from instantiatedSkeleton */
	char * dependencyListTempFile = (char *) malloc(100 * sizeof(char));
	sprintf(dependencyListTempFile, "%stemp_dependency_list.out", temporaryFolder);
#if !defined(FAST_RUNNING)
	createDependencyList(TXLPath, skeletonOutput, dependencyListTempFile);
#endif
	fflush(stdout);

	*GraftStatementsDependencies = readDependencyListFromFile( dependencyListTempFile);
	fflush(stdout);

    addOneSymbolTableToTheOther(&(*FinalGraftSymbolTable), entryPointSymbolTable);

	free(dependencyListTempFile);
	freeListOfFunctionElement(&listOfFunctions);
	freeListOfFunctionElement(&extendedSkeleton);
	freeListOfStrings(&instantiatedCandidate);
	freeSkeletonMapping(&currentMappings);
	freeSkeletonMapping(&MappingCandidates);
    free(uniqueCallerName);
	free(initialFunctionFile);
	free(initialMappingsFile);
	free(skeletonFctInstantiate);
	free(commandInstantiate);
    free(tempGotoMarkers);

	return finalListOfMappings;
}

void instantiateGraftSkeletonInInterface(ListOfString * Skeleton,
		char * InterfaceSourceCode, char * finalHostInterfaceOutput,
		char * headerFileForCoreFeature) {
	ListOfString * interfaceCode = NULL;
	ListOfString * skeletonCode = NULL;

	interfaceCode = readListOfStringFromFile(InterfaceSourceCode);
	skeletonCode = Skeleton; //readListOfStringFromFile(Skeleton);

	removeFirstEl(&skeletonCode);
	//removeLastString(&skeletonCode);

	int signal = 0;

	ListOfString * aux;
	aux = interfaceCode;

	while (aux && !signal) {
		char * lineString;
		lineString = (char *) malloc(200 * sizeof(char));
		sscanf(aux->el, "%s", lineString);
		if (!strcmp(lineString, "__INTERFACE_FUNCTION")) {
			signal = 1;
			replaceOneLineWithAListKeepPenultimate(&interfaceCode, skeletonCode,
					aux->el);
		} else {
			aux = aux->next;
		}
		free(lineString);
	}

	//not needed any more, since all the declarations and header are now in the same place
	char * includeCoreFeatureHeader;
	includeCoreFeatureHeader = (char *) malloc(1000 * sizeof(char));

	sprintf(includeCoreFeatureHeader, "#include \"%s\"\n",
			headerFileForCoreFeature);
	//put this as the first Line;

	//ListOfString * finalHostInterfaceOutputWithInclude = NULL;
	//addNewString(&finalHostInterfaceOutputWithInclude,includeCoreFeatureHeader);

	//finalHostInterfaceOutputWithInclude->next = interfaceCode;
	//UNTIL HERE it was the previous version, with the header file included

	ListOfString * finalHostInterfaceOutputWithInclude = interfaceCode;
/* Insert interface code in InterfaceWithCoreFeature.c */
	printAListOfStrings(finalHostInterfaceOutputWithInclude,
			finalHostInterfaceOutput);

	//free memory
	//sfreeListOfStrings(&interfaceCode);
	freeListOfStrings(&skeletonCode);
	//free(finalHostInterfaceOutput);
	freeListOfStrings(&finalHostInterfaceOutputWithInclude);

}
