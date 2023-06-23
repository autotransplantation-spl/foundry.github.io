/* 
 * File:   main.c
 * Author: ---
 *
 * Created on 26 May 2014, 03:56
 */

//
//  main.c
//  ResearchProject
//
//  Created by Marginean ---andru on 27/02/14.
//  Copyright (c) 2014 Marginean ---andru. All rights reserved.
//
#include <unistd.h>
#include "PrepareForGP.h"
#include "GenTrans.h"
#include "FunctionCallDependency.h"
#include "FunctionElement.h"
#include "Skeleton.h"
#include "GlobalDeclarations.h"
#include "DependencyList.h"
#include "DependencyListWithID.h"
#include "IndividualInstantiator.h"
#include "GIReduction.h"

#include "IndividualInstantiator.h"
#include "DeclarationSymbolTable.h"
#include "GP.h"
#include "OptionParser.h"

#include <stdio.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

#include <sys/resource.h>


// LOS
#include "ListOfFunctionSourceFile.h"
///#include <boost/predef.h>
#include <pthread.h>
#include <sys/file.h>

//LOS
#include "folderContent.h"
#include "CallGraph.h"
#include "Utils.h"
#include "ListOfFunctionSourceFile.h"
#include "ListOfFunctionForGraph.h"
#include "GlobalDeclarations.h"
#include "FeatureInterface.h"

#define CORE_FUNCTION_MARK "--coreFunction"
#define DONOR_CORE_FUNCTION_TARGET_FILE "--donorFileTarget"
#define HOST_CORE_FUNCTION_TARGET_PATH "--hostFileTarget"
#define DONOR_SYSTEM_NAME "--donorSystem"

struct listOfCoreFunction {
    char * functionName;
    char * donorSystemName;
    char * sourceFile;
    char * hostTargetFile;
    int qtdCoreFunctions;
    struct listOfCoreFunction * next;
};

typedef struct listOfCoreFunction ListOfCoreFunction;


char initFunctionMarker [255];
char initFunctionMarkerSourceFile[255];
char tempDonorSourceFileFolder [250];

ListOfString * ListOfCoreFunctions;
char * hostWithInterfaceOutputFile;
char * inputFileGraft;
char * donorSystemName;
char * GraftFunctionName;
char * transplantHostInputFile;
extern int errno;

int referenceOfCurrentTransplant = 0;

void copyInterfaceToTransplantCodeFolder();

void resetFolders();

#if 1 /* DEBUGGING */
char * ConsoleStderrOutput = " > /dev/null 2> ErrorFile.out";

#else
char * ConsoleStderrOutput = " > /dev/null 2>&1";
#endif

char * ConsoleNullOutput = " > /dev/null 2>&1";


//this function calls the TXL program for generating a transplant candidate

void generateNewProgram(char * inputFile, char * txlFile, char * parameters,
		char * outputFile, char * listOfNeededIncludeFiles) {
	char * command;
	command = malloc(400 * sizeof(char *));
	sprintf(command, "%s %s %s %s %s %s", TXLToolsPath, txlFile, inputFile,
			outputFile, parameters, ConsoleNullOutput);
	int status = system(command);
	if (status != 0) {
		printf("ERROR");
	}

	char *command2;
	command2 = (char *) malloc(500 * sizeof(char));
	sprintf(command2, "%s%s %s %s %s %s", TXLToolsPath,
			"multiplFiles.x -s 1000", inputFile, "graft.c",
			listOfNeededIncludeFiles, ConsoleNullOutput);
	status = system(command2);
	if (status != 0) {
		printf("ERROR");
	}
	//copyNeededFiles(listOfNeededIncludeFiles);
}

//this function compiles the resulted program and then executes it

void compileAndExecuteNewProgram(char * pathToFolderCompileCommand,
		char * outputFileName, char * transplantCFile) {
	char command[400];
	sprintf(command, "%s %s %s %s %s", TXLToolsPath, pathToFolderCompileCommand,
			outputFileName, transplantCFile, ConsoleNullOutput);
	int status = system(command);
	if (status != 0) {
		printf("ERROR");
	}
	char PathForCommand[250];
	strcpy(PathForCommand, "cd ");
	strcat(PathForCommand, TXLToolsPath);
	strcat(PathForCommand, "Transplant/ \n ");
	strcat(PathForCommand, "./transplantedResults");
	system(PathForCommand);
}

//this function generates the list of all defined symbols at the point of insertion
//this list is neded in the TLX program that generates the transplant candidate

char * generateAllDefinedSymbolsInHost(SymbolTable * hostSymbols) {
	char * parameters;
	parameters = (char*) malloc(300 * sizeof(char));
	while (hostSymbols) {
		while (hostSymbols->ListOfIdentifiers) {
			strcat(parameters, hostSymbols->ListOfIdentifiers->ID);
			strcat(parameters, " ");
			hostSymbols->ListOfIdentifiers =
					hostSymbols->ListOfIdentifiers->next;
		}
		hostSymbols = hostSymbols->next;
	}
	return parameters;
}

//this function just takes the first variable name from the host, which is the same type as
//the one in the graft, for mapping them
//for the moment it is checked just the first one
//here will be inserted the logic for generating multiple candidates

char* generateParametersForTransplant(SymbolTable * hostSymbols,
		SymbolTable * graftSymbols) {
	char *parameters;
	parameters = (char*) malloc(300 * sizeof(char));
	while (graftSymbols) {
		while (graftSymbols->ListOfIdentifiers) {
			strcat(parameters, graftSymbols->ListOfIdentifiers->ID);
			strcat(parameters, " ");
			char typeOfVarInGraft[250];
			strcpy(typeOfVarInGraft, graftSymbols->TypeOfVar);

			SymbolTable * newHostHead = hostSymbols;
			while (strcmp(newHostHead->TypeOfVar, typeOfVarInGraft)
					&& newHostHead->next) {
				newHostHead = newHostHead->next;
			}
			strcat(parameters, newHostHead->ListOfIdentifiers->ID);
			strcat(parameters, " ");
			graftSymbols->ListOfIdentifiers =
					graftSymbols->ListOfIdentifiers->next;
		}
		graftSymbols = graftSymbols->next;
	}
	strcat(parameters, "+ ");
	strcat(parameters, generateAllDefinedSymbolsInHost(hostSymbols));
	return parameters;
}

void createADirIfItNotExists(char * name) {
	int e;
	struct stat sb;

	e = stat(name, &sb);
	printf("e=%d errno=%d\n", e, errno);
	if (e == 0) {
		if (sb.st_mode & S_IFDIR)
			printf("%s is a directory.\n", name);
		if (sb.st_mode & S_IFREG)
			printf("%s is a regular file.\n", name);
		// etc.
	} else {
		printf("stat failed.\n");
		if (errno == ENOENT) {
			printf("The directory does not exist. Creating new directory...\n");
			// Add more flags to the mode if necessary.
			e = mkdir(name, S_IRWXU);
			if (e != 0) {
				printf("mkdir failed; errno=%d\n", errno);
			} else {
				printf("created the directory %s\n", name);
			}
		}
	}
}

void cleanTransplantWorkFolder(char * workFolder) {
}

void freeGlobalVariables() {
	free(TXLTemporaryMultiFileFolder);
	free(TXLTemporaryFolderMainThread);
	free(SkeletonFile);
	free(TransplantResultLocation);
	free(ConsoleNullOutput);
	free(AcceptedFunctionsForGP);
	free(SourceOutputCoreFunctionalities);
	free(SkeletonCoreFeatureHeader);
}


void generateMakeFile(char * checkWithMainMethodFile,
		char * InterfaceWithCoreFeature, char * interfaceHeader,
		char * programOutput) {
	ListOfString * makefileLines = NULL;

	char * lineCFLAGS;
	char * testFgets = NULL;

	if (has_cflags) {
		FILE * finCFLAGS = fopen(CFLAGS_FILE, "r");

		lineCFLAGS = (char *) malloc(1000 * sizeof(char));

		testFgets = (char *) malloc(1000 * sizeof(char));
		testFgets = fgets(lineCFLAGS, 999, finCFLAGS);

		fclose(finCFLAGS);
	}

	if (!testFgets) {

		addNewString(&makefileLines,
				"CHECKPACKAGE = `pkg-config --cflags --libs check`\n\n");

		char * checkWithMainMethodObjectFile = NULL;
		char * interfaceWithCoreFeatureObjectFile = NULL;

		checkWithMainMethodObjectFile = (char *) malloc(500 * sizeof(char));
		interfaceWithCoreFeatureObjectFile = (char *) malloc(
				500 * sizeof(char));

		strcpy(checkWithMainMethodObjectFile, checkWithMainMethodFile);
		strtok(checkWithMainMethodObjectFile, ".");
		strcat(checkWithMainMethodObjectFile, ".o");

		strcpy(interfaceWithCoreFeatureObjectFile, InterfaceWithCoreFeature);
		strtok(interfaceWithCoreFeatureObjectFile, ".");
		strcat(interfaceWithCoreFeatureObjectFile, ".o");

		char * line;
		line = (char *) malloc(1000 * sizeof(char));

		sprintf(line, "%s:\t%s %s\n", programOutput,
				checkWithMainMethodObjectFile,
				interfaceWithCoreFeatureObjectFile);
		addNewString(&makefileLines, line);

		sprintf(line, "\tgcc -std=gnu99 -o %s %s %s -lm $(CHECKPACKAGE)\n\n",
				programOutput, checkWithMainMethodObjectFile,
				interfaceWithCoreFeatureObjectFile);

		addNewString(&makefileLines, line);

		sprintf(line, "%s:\t%s\n", checkWithMainMethodObjectFile,
				checkWithMainMethodFile);
		addNewString(&makefileLines, line);
		sprintf(line, "\tgcc -std=gnu99 -c -o %s %s\n\n",
				checkWithMainMethodObjectFile, checkWithMainMethodFile);
		addNewString(&makefileLines, line);

		sprintf(line, "%s:\t%s %s\n", interfaceWithCoreFeatureObjectFile,
				interfaceHeader, InterfaceWithCoreFeature);
		addNewString(&makefileLines, line);
		sprintf(line, "\tgcc -std=gnu99 -c -o %s %s\n\n",
				interfaceWithCoreFeatureObjectFile, InterfaceWithCoreFeature);
		addNewString(&makefileLines, line);

		char * makefileOutputFile;
		makefileOutputFile = (char *) malloc(500 * sizeof(char));
		sprintf(makefileOutputFile, "%sMakefile", TransplantResultLocation);

		printAListOfStrings(makefileLines, makefileOutputFile);
	} else {

		char * cflagsInMakeFile = (char *) malloc(2000 * sizeof(char));
		sprintf(cflagsInMakeFile, "%s\n", lineCFLAGS);

		addNewString(&makefileLines, cflagsInMakeFile);

		addNewString(&makefileLines,
				"CHECKPACKAGE = `pkg-config --cflags --libs check`\n\n");

		char * checkWithMainMethodObjectFile = NULL;
		char * interfaceWithCoreFeatureObjectFile = NULL;

		checkWithMainMethodObjectFile = (char *) malloc(500 * sizeof(char));
		interfaceWithCoreFeatureObjectFile = (char *) malloc(
				500 * sizeof(char));

		strcpy(checkWithMainMethodObjectFile, checkWithMainMethodFile);
		strtok(checkWithMainMethodObjectFile, ".");
		strcat(checkWithMainMethodObjectFile, ".o");

		strcpy(interfaceWithCoreFeatureObjectFile, InterfaceWithCoreFeature);
		strtok(interfaceWithCoreFeatureObjectFile, ".");
		strcat(interfaceWithCoreFeatureObjectFile, ".o");

		char * line;
		line = (char *) malloc(1000 * sizeof(char));

		sprintf(line, "%s:\t%s %s\n", programOutput,
				checkWithMainMethodObjectFile,
				interfaceWithCoreFeatureObjectFile);
		addNewString(&makefileLines, line);

		sprintf(line,
				"\tgcc -std=gnu99 -o %s %s %s -lm $(CHECKPACKAGE) $(CFLAGS)\n\n",
				programOutput, checkWithMainMethodObjectFile,
				interfaceWithCoreFeatureObjectFile);

		addNewString(&makefileLines, line);

		sprintf(line, "%s:\t%s\n", checkWithMainMethodObjectFile,
				checkWithMainMethodFile);
		addNewString(&makefileLines, line);
		sprintf(line, "\tgcc -std=gnu99 -c -o %s %s $(CFLAGS)\n\n",
				checkWithMainMethodObjectFile, checkWithMainMethodFile);
		addNewString(&makefileLines, line);

		sprintf(line, "%s:\t%s %s\n", interfaceWithCoreFeatureObjectFile,
				interfaceHeader, InterfaceWithCoreFeature);
		addNewString(&makefileLines, line);
		sprintf(line, "\tgcc -std=gnu99 -c -o %s %s $(CFLAGS)\n\n",
				interfaceWithCoreFeatureObjectFile, InterfaceWithCoreFeature);
		addNewString(&makefileLines, line);

		char * makefileOutputFile;
		makefileOutputFile = (char *) malloc(500 * sizeof(char));
		sprintf(makefileOutputFile, "%sMakefile", TransplantResultLocation);

		printAListOfStrings(makefileLines, makefileOutputFile);
	}
}

void listOfMarkersThatContainsAbstractValues(ListOfString * skeletonSourceCode) {
	while (skeletonSourceCode) {
		skeletonSourceCode = skeletonSourceCode->next;
	}
}

/* set the stack size to 64MB stack.
 * */
void setDefaultStackSize(){

    const rlim_t kStackSize = 67104768;   // min stack size = 64 Mb
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "ERROR: Set stack size limit returned result = %d\n", result);
                printf("(Warning) Stack limit less than recommended for TXL size (probable cause: shell stack limit)");
            } else
                printf("\nRecursion stack limit changed to: %lld\n", (long long int)rl.rlim_cur);
        }
    }
}

// Call function f with a 256MB stack.

/*
static int bigstack(void *(*f)(void *), void* userdata) {

	pthread_t thread;
	pthread_attr_t attr;

	// allocate a 256MB region for the stack.
	size_t stacksize = 256*1024*1024;
	pthread_attr_init(&attr);
	pthread_attr_setstacksize(&attr, stacksize);

	int rc = pthread_create(&thread, &attr, f, userdata);
	if (rc){
		printf("ERROR: return code from pthread_create() is %d\n", rc);
		return 0;
	}
	pthread_join(thread, NULL);
	return 1;

}*/

strlimit(){
    struct rlimit lim;
    getrlimit(RLIMIT_STACK, &lim);
    printf("limite soft = %d, limite hard = %d\n", (int)lim.rlim_cur, (int)lim.rlim_max);
    lim.rlim_cur = 67104768;
    lim.rlim_max = 70000000;
    if (setrlimit(RLIMIT_STACK, &lim) == -1)
        printf("Erro setrlimit( )\n");
    else
    {
        getrlimit(RLIMIT_STACK, &lim);
        printf("novo limite soft = %d, novo limite hard = %d\n", (int)lim.rlim_cur, (int)lim.rlim_max);
    }
}




//LOS insert id into global_dependencies
void addGlobalDependenciesIntoUniqueFileToInterface(int * globalDecCount, int * structDeclCount, int * typeDeclCount) {

	/* LOS: Create list of old and new IDs */
   	char *tempGlobalTypeVarDeclarationsFile;
   	tempGlobalTypeVarDeclarationsFile = (char *) malloc(500 * sizeof(char));
   	sprintf(tempGlobalTypeVarDeclarationsFile,
    	          "%stemp_global_type_var_declarations.out",
    	            TXLTemporaryMultiFileFolder);

    ListOfString *tempListGlobalOfDeclaration = NULL;
	tempListGlobalOfDeclaration = readListOfStringFromFile(tempGlobalTypeVarDeclarationsFile);

	ListOfString *auxTempListGlobalOfDeclaration= NULL;
	auxTempListGlobalOfDeclaration = tempListGlobalOfDeclaration;

	ListGlobalTypeVarDeclaration * tempListGlobalTypeVarDeclaration = NULL;

	while(auxTempListGlobalOfDeclaration){
		if (strstr(auxTempListGlobalOfDeclaration->el, "DECLARED_TYPES")) {

			auxTempListGlobalOfDeclaration = auxTempListGlobalOfDeclaration->next;

			char * currentDeclarationID = (char *) malloc((strlen(auxTempListGlobalOfDeclaration->el) + 1) * sizeof (char *));
			strcpy(currentDeclarationID, auxTempListGlobalOfDeclaration->el);
			auxTempListGlobalOfDeclaration = auxTempListGlobalOfDeclaration->next;

			char * currentDeclaration = (char *) malloc((strlen(auxTempListGlobalOfDeclaration->el) + 1) * sizeof (char *));;
			strcpy(currentDeclaration, auxTempListGlobalOfDeclaration->el);
			addNewGlobalDeclarationType(&tempListGlobalTypeVarDeclaration, currentDeclarationID, currentDeclaration);
		}

		auxTempListGlobalOfDeclaration = auxTempListGlobalOfDeclaration->next;
	}

	/* LOS: Create list of declarations have already added*/
	char *listOfGlobalTypeVarDeclarationsForInterface;
	listOfGlobalTypeVarDeclarationsForInterface = (char *) malloc(500 * sizeof(char));
	sprintf(listOfGlobalTypeVarDeclarationsForInterface,
			"%stemp_global_type_var_declarations.out",
			TXLTemporaryFolderMainThread);

	ListOfString *listGlobalOfDeclarationForInterface = NULL;
	listGlobalOfDeclarationForInterface = readListOfStringFromFile(listOfGlobalTypeVarDeclarationsForInterface);

	ListGlobalTypeVarDeclaration * auxTempListGlobalTypeVarDeclaration = tempListGlobalTypeVarDeclaration;

	int currentDeclaration = NULL;
	while(auxTempListGlobalTypeVarDeclaration){
		auxTempListGlobalTypeVarDeclaration->occurrence = searchOccurrenceOfStringInListOfStrings(listGlobalOfDeclarationForInterface,auxTempListGlobalTypeVarDeclaration->declaredType);

        auxTempListGlobalTypeVarDeclaration = auxTempListGlobalTypeVarDeclaration->next;
	}

	ListGlobalTypeVarDeclaration * auxlistGlobalTypeVarDeclaration = tempListGlobalTypeVarDeclaration;

	ListOfIdsForGrobalDeclaration *listOfIds = NULL;
	ListOfString * newListGlobalOfDeclaration = NULL;

	char * formatCurrentId = NULL;
	formatCurrentId = (char *) malloc(100 * sizeof(char));

    while(auxlistGlobalTypeVarDeclaration) {
    	char oldID[40];
    	char newId[40];

		if(auxlistGlobalTypeVarDeclaration->occurrence == 1) {
			//printf("%s", auxCurrentFileContent->el);

			if (strstr(auxlistGlobalTypeVarDeclaration->declaredTypeID, "GLOBAL_DECL")) {
				strcpy(oldID, auxlistGlobalTypeVarDeclaration->declaredTypeID);
				sprintf(newId, "/* GLOBAL_DECL_%d */", *globalDecCount);
				//sprintf(newListGlobalOfDeclaration->el, "/* %s */", newId);
				//printf("- %s\n", auxCurrentFileContent->el);
				addIDs(&listOfIds, oldID, newId);
				(*globalDecCount)++;

			} else if (strstr(auxlistGlobalTypeVarDeclaration->declaredTypeID, "STRUCT_DECL_")) {
				strcpy(oldID, auxlistGlobalTypeVarDeclaration->declaredTypeID);
				sprintf(newId,  "/* STRUCT_DECL_%d */", *structDeclCount);
			//	sprintf(newListGlobalOfDeclaration->el, "/* %s */", newId);
				//printf("- %s\n", auxCurrentFileContent->el);
				addIDs(&listOfIds, oldID, newId);
				(*structDeclCount)++;
			} else if (strstr(auxlistGlobalTypeVarDeclaration->declaredTypeID, "TYPEDEF_DECL_")) {
				strcpy(oldID, auxlistGlobalTypeVarDeclaration->declaredTypeID);
				char *auxOldId = NULL;
				auxOldId = (char *) malloc(100 * sizeof(char));
				strcpy(auxOldId, oldID);
				sprintf(newId, "/* TYPEDEF_DECL_%d */", *typeDeclCount);
				//sprintf(newListGlobalOfDeclaration->el, "/* %s */", newId);
				//	printf("- %s\n", auxCurrentFileContent->el);
				addIDs(&listOfIds, oldID, newId);
				(*typeDeclCount)++;
			}
		}
		auxlistGlobalTypeVarDeclaration = auxlistGlobalTypeVarDeclaration->next;
    }
/*

 */
	/*while(listOfIds){
		printf("= %s\n",listOfIds->newId);
		listOfIds = listOfIds->next;
	}
	/* LOS: Add new global type var declarations into the interface ------------------------------------------------------------------------*/
	//printf("##########\nTEM_GLOBAL_TYPE_VAR_DECLARATIONS\n##########\n");

    char * tempGlobalTypeVarDeclarationsInterface;
    tempGlobalTypeVarDeclarationsInterface = (char *) malloc(500 * sizeof(char));
   	sprintf(tempGlobalTypeVarDeclarationsInterface,
        	          "%stemp_global_type_var_declarations.out",
        	            TXLTemporaryFolderMainThread);

	ListOfString *listGlobalTypeVarDeclarationsFile = NULL;
	ListOfString *newListGlobalTypeVarDeclarationsFile = NULL;

	listGlobalTypeVarDeclarationsFile = readListOfStringFromFile(tempGlobalTypeVarDeclarationsFile);

	ListOfIdsForGrobalDeclaration *auxListOfIds = NULL;

	int changed = 0;

	char * formatCurrentList = NULL;
	formatCurrentList = (char *) malloc(100 * sizeof(char));

	ListOfString * listGlobalTypeVarDeclaration = listGlobalTypeVarDeclarationsFile;

	while(listGlobalTypeVarDeclaration) {
		auxListOfIds = listOfIds;
		while (auxListOfIds) {
			if (strstr(listGlobalTypeVarDeclaration->el, auxListOfIds->oldId)) {
				sprintf(formatCurrentList, "%s\n", auxListOfIds->newId);
				addNewString(&newListGlobalTypeVarDeclarationsFile, formatCurrentList);
				//printf("- %s", formatCurrentList);
				changed = 1;
			}
			auxListOfIds = auxListOfIds->next;
		}

		if(changed ==0){
			addNewString(&newListGlobalTypeVarDeclarationsFile, listGlobalTypeVarDeclaration->el);
			//printf("%s", listGlobalTypeVarDeclaration->el);
		}
		listGlobalTypeVarDeclaration = listGlobalTypeVarDeclaration->next;
		changed = 0;
	}

	/* LOS: Insert LOCs from  file to interface */
	addAListOfStringsInTheEnd(newListGlobalTypeVarDeclarationsFile, tempGlobalTypeVarDeclarationsInterface);
	fflush(stdout);

	/* LOS: Add new global dependencies into the Interface ------------------------------------------------------------------------*/
    //printf("##########\nTEM_GLOBAL_DEPENDENCIES\n##########\n");

	char *tempGlobalDependenciesInterface;
	tempGlobalDependenciesInterface = (char *) malloc(500 * sizeof(char));
	sprintf(tempGlobalDependenciesInterface,
			"%stemp_global_dependencies.out",
			TXLTemporaryFolderMainThread);

    char *tempGlobalDependenciesFile;
    tempGlobalDependenciesFile = (char *) malloc(500 * sizeof(char));
    sprintf(tempGlobalDependenciesFile,
              "%stemp_global_dependencies.out",
                TXLTemporaryMultiFileFolder);

    ListOfString *listGlobalDependenciesFile = NULL;
	ListOfString *newListGlobalDependenciesFile = NULL;

    listGlobalDependenciesFile = readListOfStringFromFile(tempGlobalDependenciesFile);

	while(listGlobalDependenciesFile){
		auxListOfIds = listOfIds;
		while(auxListOfIds){
			if (strstr(listGlobalDependenciesFile->el, auxListOfIds->oldId)) {
				sprintf(formatCurrentList, "/* %s */\n", auxListOfIds->newId);
				addNewString(&newListGlobalDependenciesFile, formatCurrentList);
			//	printf("- %s", formatCurrentList);
				changed = 1;
			}
			auxListOfIds = auxListOfIds->next;
		}

		if(changed ==0) {
			addNewString(&newListGlobalDependenciesFile, listGlobalDependenciesFile->el);
			//printf("%s", listGlobalDependenciesFile->el);
		}
		listGlobalDependenciesFile = listGlobalDependenciesFile->next;
		changed = 0;
	}

	/* LOS: Insert LOCs from  file to interface */
	addAListOfStringsInTheEnd(newListGlobalDependenciesFile, tempGlobalDependenciesInterface);
	fflush(stdout);

	/* LOS: Add new global defs output ---------------------------------------------------------------------------------------------*/
    //printf("##########\nTEM_GLOBAL_DEFS_OUTPUT\n##########\n");

	char *tempGlobalDefsOutputInterface;
	tempGlobalDefsOutputInterface = (char *) malloc(500 * sizeof(char));
	sprintf(tempGlobalDefsOutputInterface, "%stemp_global_defs_output.out",
			TXLTemporaryFolderMainThread);

	char *tempGlobalDefsOutputFile;
	tempGlobalDefsOutputFile = (char *) malloc(500 * sizeof(char));
	sprintf(tempGlobalDefsOutputFile, "%stemp_global_defs_output.out",
	            TXLTemporaryMultiFileFolder);

    ListOfString *listGlobalDefsOutputFile = NULL;
    listGlobalDefsOutputFile = readListOfStringFromFile(tempGlobalDefsOutputFile);

	ListOfString *newListGlobalDefsOutputFile = NULL;

	while(listGlobalDefsOutputFile){

		auxListOfIds = listOfIds;

	    while(auxListOfIds){

			if (strstr(listGlobalDefsOutputFile->el, auxListOfIds->oldId)) {

				char * auxOldId = NULL;
				auxOldId = (char *) malloc(100 * sizeof(char));
				strcpy(auxOldId, auxListOfIds->oldId);

				char * listOldId = NULL;
				listOldId = (char *) malloc(100 * sizeof(char));
				strcpy(listOldId, listGlobalDefsOutputFile->el);


				char * getCurrentDeclaration = strtok(listGlobalDefsOutputFile->el, "*/");
				getCurrentDeclaration = strtok(NULL, "\n");
				if(getCurrentDeclaration != NULL) {
					sprintf(formatCurrentList, "%s*%s\n", auxListOfIds->newId, getCurrentDeclaration);
					addNewString(&newListGlobalDefsOutputFile, formatCurrentList);
					//printf("- %s\n", formatCurrentList);
					changed = 1;
				}

			}
			auxListOfIds = auxListOfIds->next;
		}
		if(changed ==0) {
			addNewString(&newListGlobalDefsOutputFile, listGlobalDefsOutputFile->el);
		//	printf("%s", newListGlobalDefsOutputFile->el);
		}
		listGlobalDefsOutputFile = listGlobalDefsOutputFile->next;
		changed = 0;

	}
	/* LOS: Insert LOCs from  file to interface */
	addAListOfStringsInTheEnd(newListGlobalDefsOutputFile, tempGlobalDefsOutputInterface);

	/* LOS: Add new needed funtions for grobal declarations ------------------------------------------------------------------------ */
	//printf("##########\nTEM_NEEDED_FUNCTIONS_FOR_GLOGAL_DECLARATIONS\n##########\n");

	char *tempNeededFunctionsForGlobalDeclarationsInterface;
	tempNeededFunctionsForGlobalDeclarationsInterface = (char *) malloc(500 * sizeof(char));
	sprintf(tempNeededFunctionsForGlobalDeclarationsInterface,
			"%stemp_needed_functions_for_global_declarations.out",
			TXLTemporaryFolderMainThread);

	char *tempNeededFunctionsForGlobalDeclarationsFile;
	tempNeededFunctionsForGlobalDeclarationsFile = (char *) malloc(500 * sizeof(char));
	sprintf(tempNeededFunctionsForGlobalDeclarationsFile,
			"%stemp_needed_functions_for_global_declarations.out",
			TXLTemporaryMultiFileFolder);

	ListOfString *listNeededFunctionsForGlobalDeclarationsFile = NULL;
	listNeededFunctionsForGlobalDeclarationsFile = readListOfStringFromFile(tempNeededFunctionsForGlobalDeclarationsFile);

	ListOfString * newlistNeededFunctionsForGlobalDeclarationsFile = NULL;

	while(listNeededFunctionsForGlobalDeclarationsFile) {

		auxListOfIds = listOfIds;
		while (auxListOfIds) {
			if (strstr(listNeededFunctionsForGlobalDeclarationsFile->el, auxListOfIds->oldId)) {
				sprintf(formatCurrentList, "%s\n", auxListOfIds->newId);

				addNewString(&newlistNeededFunctionsForGlobalDeclarationsFile, formatCurrentList);
			//	printf("- %s", newlistNeededFunctionsForGlobalDeclarationsFile->el);
				changed = 1;
			}
			auxListOfIds = auxListOfIds->next;
		}

		if(changed ==0){
			addNewString(&newlistNeededFunctionsForGlobalDeclarationsFile, listNeededFunctionsForGlobalDeclarationsFile->el);
		//	printf("%s", listNeededFunctionsForGlobalDeclarationsFile->el);
		}
		listNeededFunctionsForGlobalDeclarationsFile = listNeededFunctionsForGlobalDeclarationsFile->next;
		changed = 0;
	}

	/* LOS: Insert LOCs from  file to interface -----------------------------------------------------------------------------*/
	addAListOfStringsInTheEnd(newlistNeededFunctionsForGlobalDeclarationsFile, tempNeededFunctionsForGlobalDeclarationsInterface);

	/* LOS: Add new include lib files */
	//printf("##########\nTEM_INCLUDE_LIB_FILE\n##########\n");
	char *tempIncludeLibFile;
	tempIncludeLibFile = (char *) malloc(500 * sizeof(char));
	sprintf(tempIncludeLibFile, "%stemp_include_lib_file.out",
        TXLTemporaryMultiFileFolder);

	char *tempIncludeLibInterface;
	tempIncludeLibInterface = (char *) malloc(500 * sizeof(char));
	sprintf(tempIncludeLibInterface, "%stemp_include_lib_file.out",
        TXLTemporaryFolderMainThread);

	addLocsFromSourceToDestination(tempIncludeLibInterface, tempIncludeLibFile, TXLToolsPath);

	/* LOS: Add new include lib files */
	//printf("##########\nTEM_DEFINE_FILE\n##########\n");
	char *tempDefineFile;
	tempDefineFile = (char *) malloc(500 * sizeof(char));
	sprintf(tempDefineFile, "%stemp_define_file.out",
			TXLTemporaryMultiFileFolder);

	char *tempDefineFileInterface;
	tempDefineFileInterface = (char *) malloc(500 * sizeof(char));
	sprintf(tempDefineFileInterface, "%stemp_define_file.out",
			TXLTemporaryFolderMainThread);

	ListOfString *listDefineFileInterface = NULL;
	listDefineFileInterface = readListOfStringFromFile(tempDefineFile);

	addAListOfStringsInTheEnd(listDefineFileInterface, tempDefineFileInterface);

}


// TODO LOS: Change the name of this function
void copyDonorSourceFilesToTempDonorSourceFilesFolder(char * tempDonorSourceFileFolder, char * donorSourceFileFolder) {
     if(isDirectoryExists(tempDonorSourceFileFolder)) {
         if (isDirectoryEmpty(tempDonorSourceFileFolder))
             removeAllFilesFromADirectory(tempDonorSourceFileFolder);
     }else
       createADirectory(tempDonorSourceFileFolder);
    
    int copyFileFromDonorToTemp = copyFilesFromADirToAnother(donorSourceFileFolder, tempDonorSourceFileFolder);
    if (copyFileFromDonorToTemp) {
        printf("ERROR: Copy Ice Box Tests from donor to tempDonorSourceFile directory. \n");
        exit(1);
    }
}

#ifdef PREOPERATIVE_REMOVE_DIRECTIVES_FROM_HOST
* LOS: remove conditional directives if donor is a configurable system */
void removeConditionalDirectives(char * donorSourceFileFolder, char * listOfConditionalDirectivesPath, char * tempDonorSourceFileFolder){

	/* create new donor temporary directory */
	char * sourceFileList = (char *) malloc(400 * sizeof(char));
	sprintf(sourceFileList, "%stempSourceFiles.out", tempDonorSourceFileFolder);
	FILE * fSourceFileList = fopen(sourceFileList, "w");
	readFilesFromDirWithOutQuotationMarks(tempDonorSourceFileFolder, fSourceFileList, 'c');
	readFilesFromDirWithOutQuotationMarks(tempDonorSourceFileFolder, fSourceFileList, 'h');
	fclose(fSourceFileList);

	char * donorSourceFileList = (char *) malloc(400 * sizeof(char));
	sprintf(donorSourceFileList, "%sdonorSourceFiles.out", tempDonorSourceFileFolder);
	FILE * fDonorSourceFileList = fopen(donorSourceFileList, "w");
	readFilesFromDirWithOutQuotationMarks(donorSourceFileFolder, fDonorSourceFileList, 'c');
	readFilesFromDirWithOutQuotationMarks(donorSourceFileFolder, fDonorSourceFileList, 'h');
	fclose(fDonorSourceFileList);

	/* remove directives */
	char * unifdefCommand;
	unifdefCommand = (char *) malloc(20000 * sizeof(char));
	strcpy(unifdefCommand, "unifdef");

	ListOfString *listOfSourceFiles = readListOfStringFromFile(sourceFileList);
	ListOfString *listOfConditionalDirectives = readListOfStringFromFile(listOfConditionalDirectivesPath);

	int cont =0;

	while(listOfConditionalDirectives){
		if ((strstr(listOfConditionalDirectives->el, "-U") || strstr(listOfConditionalDirectives->el, "-D")) && (!strstr(listOfConditionalDirectives->el, "%%") && !strstr(listOfConditionalDirectives->el, "/*") && !strstr(listOfConditionalDirectives->el, "    "))){
			//  printf("%s",listOfConditionalDirectives->el);
			strcat(unifdefCommand, " ");
			strtok(listOfConditionalDirectives->el, "\n");
			printf("%s\n",listOfConditionalDirectives->el);
			strcat(unifdefCommand, listOfConditionalDirectives->el);

		}
		listOfConditionalDirectives = listOfConditionalDirectives->next;
		cont++;
	}
	//strcat(unifdefCommand,listOfConditionalDirectives->el);
	//printf("\n%s\n",unifdefCommand);
	char * line;
	line = (char *) malloc(1000 * sizeof(char));
	char * currentFilePath;
	currentFilePath = (char *) malloc(1000 * sizeof(char));



	FILE * fin = fopen(donorSourceFileList, "r");


	while (fgets(line, 1000, fin) != NULL) {
		char * endCommandFiles=NULL;
		endCommandFiles = (char *) malloc(100000 * sizeof(char));
		sscanf(line, "%s", currentFilePath);

		if (strstr(currentFilePath, ".c") || strstr(currentFilePath, ".h")) {
			printf("\tFile: %s\n", currentFilePath);
			//strcpy(endCommandFiles, unifdefCommand);
			sprintf(endCommandFiles, "%s %s > %s", unifdefCommand, currentFilePath, listOfSourceFiles->el);
			//printf("\tEndCommandFiles: %s\n", endCommandFiles);
			int status = system(endCommandFiles);
			if (status == 2) {
				printf("ERROR: %d. System could conditional directive(s) from file: %s !!!!!\n", status,
					   currentFilePath);
			} else {
				listOfSourceFiles = listOfSourceFiles->next;
			}
			fflush(stdout);
		}
	}
	strcpy(donorSourceFileFolder, tempDonorSourceFileFolder );
	//sprintf(graftFileFullPath, "%s%s", tempDonorSourceFileFolder, GraftFunctionName);

}
#endif


#ifdef RESET_TRANSPLANT
/* Reset the transplantation environment */
void resetFolders(char * testSuitesDirectory) {
   char *commandCleanTempFolder = NULL;
   commandCleanTempFolder = (char *) malloc(500 * sizeof(char));
   sprintf(commandCleanTempFolder, "cd %s \n rm -r -f TEMP-*", transplantWorkFolderMainThread);
   system(commandCleanTempFolder);

   char *commandCleanTransplantCodeFolders = NULL;
   commandCleanTransplantCodeFolders = (char *) malloc(500 * sizeof(char));
   sprintf(commandCleanTransplantCodeFolders, "cd %s \n rm -r -f TransplantCode-*", transplantWorkFolderMainThread);
   system(commandCleanTransplantCodeFolders);
 //LOSTESTANDO
    char *tempDirectory = NULL;
    tempDirectory = (char *) malloc(500 * sizeof(char));
    sprintf(tempDirectory, "%sTemp", transplantWorkFolderMainThread);
    if(isDirectoryExists(tempDirectory)){
        if (!isDirectoryEmpty(tempDirectory))
            removeAllFilesFromADirectory(tempDirectory);
    }else
        createADirectory(tempDirectory);

   char *tempSourceFilesDirectory = NULL;
   tempSourceFilesDirectory = (char *) malloc(500 * sizeof(char));
   sprintf(tempSourceFilesDirectory, "%sTempSourceFiles", transplantWorkFolderMainThread);
   if(isDirectoryExists(tempSourceFilesDirectory)) {
       if (!isDirectoryEmpty(tempSourceFilesDirectory))
           removeAllFilesFromADirectory(tempSourceFilesDirectory);
   }else
     createADirectory(tempSourceFilesDirectory);

    char *tempDonorDirectory = NULL;
    tempDonorDirectory = (char *) malloc(500 * sizeof(char));
  ///  sprintf(tempDonorDirectory, "%sTempDonorFiles", transplantWorkFolderMainThread);
    strcpy(tempDonorDirectory, replace_str(donorSourceFileFolder,"Donor/", "TempDonorFiles/"));
    if(isDirectoryExists(tempDonorDirectory)) {
        if (!isDirectoryEmpty(tempDonorDirectory))
            removeAllFilesFromADirectory(tempDonorDirectory);
    }else
        createADirectory(tempDonorDirectory);

   char *tempVeinDirectory = NULL;
   tempVeinDirectory = (char *) malloc(500 * sizeof(char));
   sprintf(tempVeinDirectory, "%sTempVeinDirectory", transplantWorkFolderMainThread);
   if(isDirectoryExists(tempVeinDirectory)) {
       if (!isDirectoryEmpty(tempVeinDirectory))
           removeAllFilesFromADirectory(tempVeinDirectory);
   }else
        createADirectory(tempVeinDirectory);


   // char *tempImplantationDirectory = NULL;
   // tempImplantationDirectory = (char *) malloc(500 * sizeof(char));
    sprintf(TempImplantationDirectory, "%sTempImplantationDirectory/", transplantWorkFolderMainThread);
    if(isDirectoryExists(TempImplantationDirectory)) {
        if (!isDirectoryEmpty(TempImplantationDirectory))
            removeAllFilesFromADirectory(TempImplantationDirectory);
    }else
        createADirectory(TempImplantationDirectory);

    if(!isDirectoryExists(testSuitesDirectory))
        createADirectory(testSuitesDirectory);

    if(isDirectoryExists(DebugFolder)){
        if (!isDirectoryEmpty(DebugFolder))
            removeAllFilesFromADirectory(DebugFolder);
    }else
        createADirectory(DebugFolder);

    //{
    //   printf("Error: Unit test directory not found! %s\nPlease provide almost one unit test for transplantation process\n", testSuitesDirectory);
    //   exit(1);
    //}

   free(commandCleanTempFolder);
   free(commandCleanTransplantCodeFolders);
  /*LOSTESTANDO*/ free(tempDirectory);
   free(tempSourceFilesDirectory);
   free(tempVeinDirectory);
   free(tempDonorDirectory);
   //free(tempImplantationDirectory);
}
#endif
/*
 * LOS: Copy Test suites to Transplant Code Directory
 */
// TODO LOS: Change the name of this function
void copyInterfaceToTransplantCodeFolder() {

	//LOS: Clean TransplantCode Folder
	if(isDirectoryExists(TransplantResultLocation)){
	    if(!isDirectoryEmpty(TransplantResultLocation)) {
            int cleanStatus = removeAllFilesFromADirectory(TransplantResultLocation);
            if (!cleanStatus) {
                printf("ERROR - Clean Transplantation Directory. \n\tNo such file or directory: %s\n",
                       TransplantResultLocation);
                exit(1);
            }
        }
	}else{
	    createADirectory(TransplantResultLocation);
	}

	//LOS: Copy all files from organ folder to TransplantCode folder
	char * testSuitesDirectory  = NULL;
	testSuitesDirectory = (char *) malloc(1000 * sizeof(char));
	sprintf(testSuitesDirectory, "%sTestSuites/%s/", transplantWorkFolderMainThread,GraftFunctionName);

    if(isDirectoryExists(testSuitesDirectory)) {
        int copyStatus = copyFilesFromADirToAnother(testSuitesDirectory, TransplantResultLocation);
        if (copyStatus) {
			printf("ERROR: Copy Ice Box Tests from TestSuites file. \n\tNo such file or directory: %s\n",testSuitesDirectory);
            exit(1);
		}
	}else{
		printf("ERROR - TestSuites directory was not found or does not exit!\n");
	}

}

#ifdef MAKEFILE_MULTIFILES
void generateMakeFileMultiFiles(char * checkWithMainMethodFile,
								char * InterfaceWithCoreFeature, char * interfaceHeader, char * listOfSourceFilesPath,
								char * tempAllHeaderFilesExtractedPath,
								char * programOutput, char * outputMakeFilePath) {

	printf("[AUTOSCALPEL] Generating Makefile\n");

	ListOfString * makefileLines = NULL;
	ListOfString * listOfSourceFiles = readListOfStringFromFileAsWords(listOfSourceFilesPath);
    ListOfString * listOfObjectSourceFiles = readListOfStringFromFileAsWords(listOfSourceFilesPath);

	//ListOfString * listOfHeaderFiles = readListOfStringFromFileAsWords(listOfSourceFilesPath);
	//ListOfString * listOfObjectSourceFiles = listOfSourceFiles;
/*	ListOfString * auxListOfSourceFiles = listOfSourceFiles;

	while(auxListOfSourceFiles){
		addNewString(&listOfObjectSourceFiles, auxListOfSourceFiles->el);
		auxListOfSourceFiles = auxListOfSourceFiles->next;
	}*/

	ListOfString * listOfHeaderFiles = readListOfStringFromFileAsWords(tempAllHeaderFilesExtractedPath);



    ListOfString * auxListOfHeaderFiles = listOfHeaderFiles; //headers.h
	char * formatListOfObjectHeaderFiles = (char *) malloc(10000 * sizeof(char));
    strcpy(formatListOfObjectHeaderFiles, "");

    fflush(stdout);
	while (auxListOfHeaderFiles){
	    /* Remove "/" */
       /* if(strstr(auxListOfHeaderFiles->el,"/")){
            char *position = strstr(auxListOfHeaderFiles->el, "/");
            while(strstr(position+1, "/"))
                position = strstr(position+1, "/");

            strcat(formatListOfObjectHeaderFiles, position+1);
        } else*/
            strcat(formatListOfObjectHeaderFiles, auxListOfHeaderFiles->el);
        fflush(stdout);
		strcat(formatListOfObjectHeaderFiles, ".gch ");

		auxListOfHeaderFiles = auxListOfHeaderFiles->next;
	}

	char * lineCFLAGS;

    ListOfString * listOfCFLAGS = NULL;
    if (has_cflags) {
        FILE * finCFLAGS = fopen(CFLAGS_FILE, "r");
        lineCFLAGS = (char *) malloc(1000 * sizeof(char)); //flags
        while (fgets(lineCFLAGS, 999, finCFLAGS) != NULL) {
            addNewString(&listOfCFLAGS, lineCFLAGS);
        }
        fflush(stdout);
        fclose(finCFLAGS);
    }

	ListOfString * auxlistOfObjectSourceFiles = listOfObjectSourceFiles; //c objects
	char * currentObjectSourceFile;
    fflush(stdout);
	while (auxlistOfObjectSourceFiles){
		strtok(auxlistOfObjectSourceFiles->el, ".");
		strcat(auxlistOfObjectSourceFiles->el, ".o ");
       // addNewString(&listOfObjectSourceFiles, auxlistOfObjectSourceFiles);
		auxlistOfObjectSourceFiles = auxlistOfObjectSourceFiles ->next;
        fflush(stdout);
	}
    char *line;
    line = (char *) malloc(3000 * sizeof(char));

	if (!listOfCFLAGS) {
        fflush(stdout);
		addNewString(&makefileLines,
					 "CHECKPACKAGE = `pkg-config --cflags --libs check`\n\n");

		char *checkWithMainMethodObjectFile = NULL;
		char *interfaceWithCoreFeatureObjectFile = NULL;

		checkWithMainMethodObjectFile = (char *) malloc(500 * sizeof(char));
		interfaceWithCoreFeatureObjectFile = (char *) malloc(
				500 * sizeof(char));

		strcpy(checkWithMainMethodObjectFile, checkWithMainMethodFile);
		strtok(checkWithMainMethodObjectFile, ".");
		strcat(checkWithMainMethodObjectFile, ".o");

		strcpy(interfaceWithCoreFeatureObjectFile, InterfaceWithCoreFeature);
		strtok(interfaceWithCoreFeatureObjectFile, ".");
		strcat(interfaceWithCoreFeatureObjectFile, ".o");

		ListOfString * auxListOfObjectSourceFiles = listOfObjectSourceFiles;
		char * formatListOfObjectSourceFiles = (char *) malloc(10000 * sizeof(char));

		while (auxListOfObjectSourceFiles){
			strcpy(formatListOfObjectSourceFiles, auxListOfObjectSourceFiles ->el);
			strcat(formatListOfObjectSourceFiles, " ");

			auxListOfObjectSourceFiles = auxListOfObjectSourceFiles ->next;
		}

		sprintf(line, "%s:\t%s %s %s\n", programOutput,
				checkWithMainMethodObjectFile,
				interfaceWithCoreFeatureObjectFile, formatListOfObjectSourceFiles);
		addNewString(&makefileLines, line);

		sprintf(line, "\tgcc -std=gnu99 -o %s %s %s  %s -lm $(CHECKPACKAGE)\n\n",
				programOutput, checkWithMainMethodObjectFile,
				interfaceWithCoreFeatureObjectFile, formatListOfObjectSourceFiles);

		addNewString(&makefileLines, line);

		//main.o:	InterfaceHeader.h main.c
		sprintf(line, "%s:\t%s %s\n", checkWithMainMethodObjectFile, interfaceHeader,
				checkWithMainMethodFile);
		addNewString(&makefileLines, line);
		//gcc -std=gnu99 -c -o main.o main.c $(CFLAGS)
		sprintf(line, "\tgcc -std=gnu99 -c -o %s %s\n\n",
				checkWithMainMethodObjectFile, checkWithMainMethodFile);
		addNewString(&makefileLines, line);

		//InterfaceWithCoreFeature.o:	x_header.h InterfaceHeader.h InterfaceWithCoreFeature.c
		sprintf(line, "%s:\t%s %s %s\n", interfaceWithCoreFeatureObjectFile, formatListOfObjectHeaderFiles,
				interfaceHeader, InterfaceWithCoreFeature);
		addNewString(&makefileLines, line);
		//gcc -std=gnu99 -c -o InterfaceWithCoreFeature.o InterfaceWithCoreFeature.c $(CFLAGS)
		sprintf(line, "\tgcc -std=gnu99 -c -o %s %s\n\n",
				interfaceWithCoreFeatureObjectFile, InterfaceWithCoreFeature);
		addNewString(&makefileLines, line);

		auxListOfObjectSourceFiles = listOfObjectSourceFiles;
        ListOfString * auxListOfSourceFiles = listOfSourceFiles;
		while(auxListOfObjectSourceFiles){
            fflush(stdout);
			//x_souceFile.o:	InterfaceHeader.h x_sourceFile.c
			sprintf(line, "%s:\t%s %s %s\n", auxListOfObjectSourceFiles->el,
					formatListOfObjectHeaderFiles, auxListOfObjectSourceFiles->el);
			addNewString(&makefileLines, line);
			//gcc -std=gnu99 -c -o x_souceFile.o x_sourceFile.c $(CFLAGS)
			sprintf(line, "\tgcc -std=gnu99 -c -o %s %s\n\n",
					auxListOfObjectSourceFiles->el, auxListOfSourceFiles->el);
			addNewString(&makefileLines, line);

			auxListOfObjectSourceFiles = auxListOfObjectSourceFiles->next;
			auxListOfSourceFiles = auxListOfSourceFiles->next;
		}
		//LOS Add clean
		addNewString(&makefileLines,  "clean:\n\trm -rf *.o Individual.x\n");

		char * makefileOutputFile;
		makefileOutputFile = (char *) malloc(500 * sizeof(char));
		sprintf(makefileOutputFile, "%sMakefile", TransplantResultLocation);

		printAListOfStrings(makefileLines, makefileOutputFile);
	} else {
        fflush(stdout);
		char * cflagsInMakeFile = (char *) malloc(2000 * sizeof(char));
		sprintf(cflagsInMakeFile, "%s ", lineCFLAGS);

        //Add CC = cc and conditional directive
        sprintf(line, "CC = cc\n\n", conditionalDirectives);
        addNewString(&makefileLines, line);

        if(conditionalDirectives) {
            sprintf(line, " -D%s\n\n", conditionalDirectives);
            addNewString(&listOfCFLAGS, line);
        }

         addListOfStringToExistingOne(&makefileLines,listOfCFLAGS);

		addNewString(&makefileLines, "CHECKPACKAGE = `pkg-config --cflags --libs check`\n\n");

		char * checkWithMainMethodObjectFile = NULL;
		char * interfaceWithCoreFeatureObjectFile = NULL;

		checkWithMainMethodObjectFile = (char *) malloc(500 * sizeof(char));
		interfaceWithCoreFeatureObjectFile = (char *) malloc(
				500 * sizeof(char));
        char * formatListOfObjectSourceFiles = (char *) malloc(10000 * sizeof(char));
        strcpy(formatListOfObjectSourceFiles, "OBJS = ");
		strcpy(checkWithMainMethodObjectFile, checkWithMainMethodFile);
		strtok(checkWithMainMethodObjectFile, ".");
		strcat(checkWithMainMethodObjectFile, ".o ");
        strcat(formatListOfObjectSourceFiles, checkWithMainMethodObjectFile);

		strcpy(interfaceWithCoreFeatureObjectFile, InterfaceWithCoreFeature);
		strtok(interfaceWithCoreFeatureObjectFile, ".");
		strcat(interfaceWithCoreFeatureObjectFile, ".o ");
        strcat(formatListOfObjectSourceFiles, interfaceWithCoreFeatureObjectFile);

		ListOfString * auxListOfObjectSourceFiles = listOfObjectSourceFiles;

		while (auxListOfObjectSourceFiles){
			strcat(formatListOfObjectSourceFiles, auxListOfObjectSourceFiles->el);
			strcat(formatListOfObjectSourceFiles, " ");
            fflush(stdout);
			auxListOfObjectSourceFiles = auxListOfObjectSourceFiles->next;
		}
        addNewString(&makefileLines, formatListOfObjectSourceFiles);//OBJS =  test_suite.o InterfaceWithCoreFeature.o ...

		//char * line;
		//line = (char *) malloc(3000 * sizeof(char));

		sprintf(line, "\n\nall: %s\n\n", programOutput); //all: Individual.x
		addNewString(&makefileLines, line);

        char * interfaceHeaderObject = (char *) malloc(10000 * sizeof(char));
        strcpy(interfaceHeaderObject, interfaceHeader);
        strtok(interfaceHeaderObject, ".");
        strcat(interfaceHeaderObject, ".o ");
        sprintf(line, "%s: %s\n",interfaceHeaderObject, interfaceHeader); //InterfaceHeader.o:  InterfaceHeader.h

        ListOfString * auxListHeaderFiles = listOfHeaderFiles;
        char * formatListOfHeaderFiles = (char *) malloc(100 * sizeof(char));

        while (auxListHeaderFiles){
            strcpy(formatListOfHeaderFiles, auxListHeaderFiles->el);
            strtok(formatListOfHeaderFiles, ".");
            strcat(formatListOfHeaderFiles, ".o ");
            sprintf(formatListOfHeaderFiles, "%s: %s\n\n", formatListOfHeaderFiles, auxListHeaderFiles->el);
            fflush(stdout);
            addNewString(&makefileLines, formatListOfHeaderFiles);
            auxListHeaderFiles = auxListHeaderFiles->next;
        }

        //%.o:  %.c
        //	$(CC) -c  $(CFLAGS)  $<
        //Individual.x: $(OBJS)
        //	$(CC) -o $@ $(OBJS) -lm $(CHECKPACKAGE) $(CFLAGS)
        sprintf(line,"%%.o:  %%.c\n\t$(CC) -c  $(CFLAGS)  $<\n%s: $(OBJS)\n\t$(CC) -o $@ $(OBJS) -lm $(CHECKPACKAGE) $(CFLAGS)\n\n", programOutput);
        addNewString(&makefileLines, line);
		//clean:
        //	rm -rf *.o Individual.x
		addNewString(&makefileLines,  "clean:\n\trm -rf *.o Individual.x\n");

		char * makefileOutputFile;
		makefileOutputFile = (char *) malloc(500 * sizeof(char));
		sprintf(makefileOutputFile, "%sMakefile", outputMakeFilePath);
        fflush(stdout);
		printAListOfStrings(makefileLines, makefileOutputFile);

        freeListOfStrings(&auxListHeaderFiles);
        freeListOfStrings(&auxListOfObjectSourceFiles);
        freeListOfStrings(&listOfCFLAGS);
        free(cflagsInMakeFile);
        free(formatListOfObjectSourceFiles);
        free(checkWithMainMethodObjectFile);
        free(makefileOutputFile);
	}

}

#endif



/* Initialize all transplantation environment */
void initializeTransplantationEnvironment(char * donorSystemName){

    DoxygenFolder = (char *) malloc(200 * sizeof(char));
  //  sprintf(DoxygenFolder, "Doxygen_%s/",donorSystemName);
    sprintf(DoxygenFolder, "%sDoxygen_%s/", transplantWorkFolderMainThread,donorSystemName);
    fflush(stdout);

    /* Copy files from unit test directory to Transplant Code Directory */
    printf("[AUTOSCALPEL] Copying ice box test(s) from TestSuites/%s to TransplantCode\n", GraftFunctionName);
    copyInterfaceToTransplantCodeFolder();

    /* Create fakeExcludeFile.in required by TXL modules*/
    if (!exclude_functions) {
        //system("pwd");
        //write an empty file, needed by a TXL program
        AcceptedFunctionsForGP = (char *) malloc((strlen(TXLTemporaryFolderMainThread) + 25) * sizeof (char));
        sprintf(AcceptedFunctionsForGP, "%sfakeExcludeFile.in", TXLTemporaryFolderMainThread);
        FILE * fakeFile = fopen(AcceptedFunctionsForGP, "w");
        fclose(fakeFile);
    }

   strcpy(tempDonorSourceFileFolder, replace_str(donorSourceFileFolder,"Donor/", "TempDonorFiles/"));

    /* Copy donor Source Files to Temp Donor Source File Directory */
    copyDonorSourceFilesToTempDonorSourceFilesFolder(tempDonorSourceFileFolder, donorSourceFileFolder);

    /* Replace donor path to tempoDonorFiles path */
    strcpy(donorSourceFileFolder, replace_str(donorSourceFileFolder,"Donor/", "TempDonorFiles/"));
  ///  strcpy(inputFileGraft, replace_str(inputFileGraft,"Donor/", "TempDonorFiles/"));
    strcpy(donorSourceFileFolder, tempDonorSourceFileFolder);

    /* Create initial files */
    openFileInAppendMode(SourceOutputCoreFunctionalities);
    openFileInAppendMode(SkeletonCoreFeatureHeader);
    openFileInAppendMode(InterfaceCoreFunctionality);

    if (!isDirectoryExists(DoxygenFolder))
        createADirectory(DoxygenFolder);

    if(!isDirectoryExists(DebugFolder))
        createADirectory(DebugFolder);

}

#ifdef GENERATE_DATAS_FROM_TRANSPLANT
void generateTransplantDatas() {
    Generate data from transplantation
    /*Generate list with the number of functions per core function*/
    char * hostTargetFolder = NULL;
        hostTargetFolder = (char *) malloc(500 * sizeof(char));

        char * sourceFilesInHost;
        sourceFilesInHost = (char *) malloc(500 * sizeof(char));
        sprintf(sourceFilesInHost, "%sANALYSE_FUNC_PER_ORGAN.csv", TXLTemporaryMultiFileFolder);
        FILE * fSourceFile = fopen(sourceFilesInHost, "w");
        countFunctionFilesFromDir(hostTargetFolder, fSourceFile, "dot");
        fclose(fSourceFile);
}
#endif

void addNewCoreFunction(ListOfFunctionForGraph ** head, char * functionName, char * donorSystemName, char * sourceFile, char * hostTargetFile) {
    ListOfCoreFunction * newEl = (ListOfFunctionForGraph *) malloc(1 * sizeof (ListOfFunctionForGraph));
    newEl->functionName = (char *) malloc((strlen(functionName) + 1) * sizeof (char *));
    newEl->donorSystemName = (char *) malloc((strlen(functionName) + 1) * sizeof (char *));
    newEl->sourceFile = (char *) malloc((strlen(sourceFile) + 1) * sizeof (char *));
    newEl->hostTargetFile = (char *) malloc((strlen(sourceFile) + 1) * sizeof (char *));
    strcpy(newEl->functionName, functionName);
    strcpy(newEl->donorSystemName, donorSystemName);
    strcpy(newEl->sourceFile, sourceFile);
    strcpy(newEl->hostTargetFile, hostTargetFile);
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfFunctionForGraph * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}


ListOfCoreFunction * readCoreFunctionListFromFile() {
    ListOfFunctionForGraph *listOfCoreFunction = NULL;
    if(!file_exists(listOfCoreFunctionsFile)) {
        ListOfString * ListOfCoreFunctions = readListOfStringFromFile(listOfCoreFunctionsFile);

        while (ListOfCoreFunctions) {
            ListOfString * currentCoreFunction = NULL;
            readStringAsWords(ListOfCoreFunctions->el, &currentCoreFunction);
            char *coreFunction = NULL;
            char *targetFile = NULL;
            char *donorSystemName = NULL;
            char *hostTargetFile = NULL;
            if (!strcmp(currentCoreFunction->el, CORE_FUNCTION_MARK)) {
                currentCoreFunction = currentCoreFunction->next;
                coreFunction = currentCoreFunction->el;
                currentCoreFunction = currentCoreFunction->next;
                if (!strcmp(currentCoreFunction->el,  DONOR_SYSTEM_NAME)) {
                    currentCoreFunction = currentCoreFunction->next;
                    donorSystemName = currentCoreFunction->el;
                    currentCoreFunction = currentCoreFunction->next;
                }else{
                    printf("Donor system name does not defined in: %s\n", listOfCoreFunctionsFile);
                    exit(1);
                }
                if (!strcmp(currentCoreFunction->el, DONOR_CORE_FUNCTION_TARGET_FILE)) {
                    currentCoreFunction = currentCoreFunction->next;
                    targetFile = currentCoreFunction->el;
                    currentCoreFunction = currentCoreFunction->next;
                }else{
                    printf("Donor target file does not defined in: %s\n", listOfCoreFunctionsFile);
                    exit(1);
                }
                if (!strcmp(currentCoreFunction->el, HOST_CORE_FUNCTION_TARGET_PATH)) {
                    currentCoreFunction = currentCoreFunction->next;
                    hostTargetFile = currentCoreFunction->el;
                    strtok(hostTargetFile, "\n");
                }else{
                    printf("Host target file does not defined in: %s\n", listOfCoreFunctionsFile);
                    exit(1);
                }
                addNewCoreFunction(&listOfCoreFunction, coreFunction, donorSystemName, targetFile, hostTargetFile);
            }

            ListOfCoreFunctions = ListOfCoreFunctions->next;
            if(ListOfCoreFunctions)
                ListOfCoreFunctions = ListOfCoreFunctions->next;
        }

    }else{
        printf("ERROR Input file not found: %s", listOfCoreFunctionsFile);
        exit(1);
    }
    return listOfCoreFunction;
}

int countElementsInListOfCoreFunctions(ListOfCoreFunction * head) {
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    return count;
}

void includeInterfaceHeaderIntoExtractedSourceFiles(ListOfString * listOfSourceFilesExtracted) {

    ListOfString * auxListOfSourceFilesExtracted = listOfSourceFilesExtracted;

    char *sourceFilesOutputPath = (char *) malloc(1000 * sizeof(char));
    char *sourceFilesInputPath = (char *) malloc(1000 * sizeof(char));
    char *currentSourceFile = (char *) malloc(1000 * sizeof(char));

    while (auxListOfSourceFilesExtracted) {

        strcpy(currentSourceFile, auxListOfSourceFilesExtracted->el);

        /* Add InterfaceHeadeer in all .c extracted at result folder (TransplantCode) */
        char *includeHeader;
        includeHeader = (char *) malloc(
                (strlen(TXLTemporaryMultiFileFolder) + strlen("include_header.out") + 5) * sizeof(char));
        sprintf(includeHeader, "%sinclude_header.out", TXLTemporaryMultiFileFolder);

        sprintf(sourceFilesInputPath, "%s%s", TXLTemporaryMultiFileFolder, currentSourceFile);

       if(strstr(currentSourceFile,"/"))
            addAStringsInTheFile("#include \"../InterfaceHeader.h\"\n", includeHeader);
        else
            addAStringsInTheFile("#include \"InterfaceHeader.h\"\n", includeHeader);

        addLocsFromSourceToDestination(sourceFilesInputPath, includeHeader, TXLToolsPath);

        auxListOfSourceFilesExtracted = auxListOfSourceFilesExtracted->next;
    }
}

int main(int argc, char * argv[]) {

    printf("Starting transplantation process\n");
    char * stepTime = (char *) malloc(500 * sizeof(int));

    sprintf(stepTime, "Starting Transplantation..: %s", getTime());
    printf("%s",getTime());
    addNewString(&execution_log, stepTime);

#ifdef EXPERIMENT_RUN
    /*Getting begin time */
    begin_execution_time = clock();
#endif

#if PREOPERATIVE_REMOVE_DIRECTIVES
    /* LOSDEBUG: Handle conditional directives if donor is a configurable system, LOS_RAN = 0 */
		if(conditionalDirectives != NULL) {
        printf("[UNIDEF] Removing unwanted conditional directives...\n");
		removeConditionalDirectives(donorSourceFileFolder, conditionalDirectives,tempDonorSourceFileFolder);
    }
#endif

#if defined(BOOST_OS_MACOS)
    /* set up StackSize to 64MB */
    setDefaultStackSize();
#endif

	parse_args(argc, argv);
    setDefaultStackSize();

	char * skeletonInterfaceSourceCodeOutput;
	char * skeletonInterfaceHeaderFileOutput;

	Mapping * ListOfMappingsFromCurrentDonor = NULL;
	ListOfFunctionSourceFile * listOfFunctionSourceFileExtracted = NULL;
	DependencyList * ListOfDependenciesForStatements = NULL;
	MappingCandidate * MappingCandidatesForGP = NULL;
	CallDependency * ListOfNeededFunctionsForAllLOCs = NULL;
	DeclarationSymbolTable * FinalDeclSymbolTable = NULL;
	ListOfString * ListOfMarkersForAbstractVariables = NULL;
	SymbolTable * HostSymbolTable = NULL;

#ifdef GENERATE_DATAS_FROM_TRANSPLANT
    generateTransplantDatas();
#endif
    ListOfCoreFunction * ListCoreFunctionWithDonorHostTarget = NULL;

    /* Get list of corefunctions */
    ListCoreFunctionWithDonorHostTarget = readCoreFunctionListFromFile();
    int numberOfCoreFunctions = 0;
    numberOfCoreFunctions = countElementsInListOfCoreFunctions(ListCoreFunctionWithDonorHostTarget);

	/* Start sequence of Transplantation*/
	int transplantNumber = 1;

    /* Get current coreFunction that will be transplanted into the new feature */
    GraftFunctionName = ListCoreFunctionWithDonorHostTarget->functionName;
    transplantHostInputFile = ListCoreFunctionWithDonorHostTarget->hostTargetFile;
    donorSystemName = ListCoreFunctionWithDonorHostTarget->donorSystemName;
    inputFileGraft = ListCoreFunctionWithDonorHostTarget->sourceFile;

    printf("\n===========================================================\n");
    printf("STARTING TRANSPLANT %d of %d\n", transplantNumber, numberOfCoreFunctions);
    printf("\tCore function: %s\n", GraftFunctionName);
    printf("\tTarget file: %s\n", inputFileGraft);
    printf("\tHost target file: %s\n", transplantHostInputFile);
    printf("===========================================================\n");

    /* Create InterfaceHeader.h */
    InterfaceHeaderFileName = (char *) malloc(100 * sizeof(char));
    sprintf(InterfaceHeaderFileName, "InterfaceHeader.h");

    /* Set interface for individual instantiation path */
    TemporaryInterface = (char *) malloc(500 * sizeof(char));
    sprintf(TemporaryInterface, "%stemp_interface_for_individual_instantiation.out",
            TXLTemporaryFolderMainThread);

    /* Set path InterfaceHeader.h  */
    skeletonInterfaceHeaderFileOutput = (char *) malloc(100 * sizeof(char));
    sprintf(skeletonInterfaceHeaderFileOutput, "%s%s", TransplantResultLocation,
            InterfaceHeaderFileName);

    //transplant result, the new Host's transplant target file, with transplant added
    hostWithInterfaceOutputFile = (char *) malloc(100 * sizeof(char));
    sprintf(hostWithInterfaceOutputFile, "%sHostWithInterface.c",
            TransplantResultLocation);

    /* Create InterfaceWithCoreFeature.c */
    InterfaceWithCoreFeatureFileName = (char *) malloc(100 * sizeof(char));
    sprintf(InterfaceWithCoreFeatureFileName, "InterfaceWithCoreFeature.c");

    /* Set InterfaceInterfaceWithCoreFeature.c path */
    skeletonInterfaceSourceCodeOutput = (char *) malloc(100 * sizeof(char));
    sprintf(skeletonInterfaceSourceCodeOutput, "%s%s", TransplantResultLocation,
            InterfaceWithCoreFeatureFileName);

    /* Create InterfaceWithCoreFeature.c */
    char * interfaceOutput;
    interfaceOutput = (char *) malloc(100 * sizeof(char));
    sprintf(interfaceOutput, "%stemp_InterfaceSourceFile.out",
            TXLTemporaryFolderMainThread);

    char * AllDefinedFunctionsInDonor;
    AllDefinedFunctionsInDonor = (char *) malloc(100 * sizeof(char));
    sprintf(AllDefinedFunctionsInDonor,	"%stemp_all_defined_functions_int_donor.out",
            TXLTemporaryFolderMainThread);

    //Set TestSuit directory path to send the interfaceFunction
    char * testSuitesDirectory  = (char *) malloc(100 * sizeof(char));
    sprintf(testSuitesDirectory, "%sTestSuites/", transplantWorkFolderMainThread);

    //Set TestSuit directory path to send the interfaceFunction
    char * testSuitesDirectoryForGraft  = (char *) malloc(100 * sizeof(char));
    sprintf(testSuitesDirectoryForGraft, "%s%s/", testSuitesDirectory, GraftFunctionName);



#ifdef RESET_TRANSPLANT
#if  !defined(FAST_RUNNING2)
    printf("[AUTOSCALPEL] Reset transplantation environment\n");
///LOSTEMP
resetFolders(testSuitesDirectoryForGraft);
#endif
#endif

#ifdef GENERATE_HOST_INTERFACE_FOR_ICEBOX_TESTS
    printf("[AUTOSCALPEL] Create interface files to the Unit Test Suite\n");

    generateUnitTests(testSuitesDirectoryForGraft, TemporaryInterface, InterfaceHeaderFileName, TXLTemporaryFolderMainThread);
    // Temporary generating just a symbol table to be used to write the interface function
    printf("InterfaceFunction generated. Press any key to continue the transplant process:\n");
    //getchar();

    /* Generate MakeFile for unit tests */
    generateMakeFileMultiFiles("test_suite.c", InterfaceWithCoreFeatureFileName, InterfaceHeaderFileName, NULL, NULL, "Individual.x", testSuitesDirectoryForGraft);

    /* Run make clean */
    char * commandMakeClean = (char *) malloc(100 * sizeof(char));
    sprintf(commandMakeClean, "cd %s \nmake clean %s", testSuitesDirectoryForGraft, ConsoleStderrOutput);
    if (system(commandMakeClean)!= 0)
        printf("\tError trying to clean Unit test suite directory!");

    /* Compile unit test suite */
    char * commandCompile = (char *) malloc(100 * sizeof(char));
    sprintf(commandCompile, "cd %s \nmake %s", testSuitesDirectoryForGraft, ConsoleStderrOutput);
    if (system(commandCompile) != 0) {
        printf("\tError trying to compile the unit test suites! Please, check it.");
///        exit(1);
    }
#else

#endif
/*  DoxygenFolder = (char *) malloc((strlen(transplantWorkFolderMainThread) + 20) * sizeof(char));
    sprintf(DoxygenFolder, "%sDoxygen_%s/", transplantWorkFolderMainThread,ListCoreFunctionWithDonorHostTarget->donorSystemName);
    fflush(stdout);*/

    /* Initialize Transplantation Enviroment */
    initializeTransplantationEnvironment(donorSystemName);

    char *tempAllHeaderFilesExtractedPath  = (char *) malloc(100 * sizeof(char));
    sprintf(tempAllHeaderFilesExtractedPath, "%stemp_list_of_header_files_extracted.out", TXLTemporaryMultiFileFolder);

    char *listOfFunctionsFilesExtractedFullPath = (char *) malloc(100 * sizeof(char));
    sprintf(listOfFunctionsFilesExtractedFullPath, "%slist_of_functions_file_target.out", TXLTemporaryMultiFileFolder);
    fflush(stdout);

    // TODO rewrite stemp_list_of_header_files and stemp_list_of_source_files_extracted
    char * listOfSourceFilesTargetPath = (char *) malloc(100 * sizeof(char));
    sprintf(listOfSourceFilesTargetPath, "%stemp_list_of_source_files_extracted.out", TXLTemporaryMultiFileFolder);

    createFile(listOfSourceFilesTargetPath);
    createFile(tempAllHeaderFilesExtractedPath);
    createFile(listOfFunctionsFilesExtractedFullPath);
    createFile(InterfaceCoreFunctionality);
#ifdef REPLACE_STATIC_FUNCTION_DECLARATIONS
    solveDonorStaticFunctionDeclarationsUniqueNamesAndMarkersReplacement(
        donorSourceFileFolder, TXLTemporaryFolderMainThread);
#else
    /* Create temp_new_core_fct_name.out with core function with out replace static */
    char * tempCoreFctOutputFile = (char *) malloc(1000 * sizeof(char));
    sprintf(tempCoreFctOutputFile, "%stemp_new_core_fct_name.out",
            TXLTemporaryFolderMainThread);
    createFile(tempCoreFctOutputFile);
    addAStringsInTheEndFile(GraftFunctionName, tempCoreFctOutputFile);
    fflush(stdout);
#endif

    /* Used for fitness computation */
    int TotalIDsInHostSymbolTable;

    ListOfString *FinalSkeletonSourceCode = prepareForGP(
            &ListOfMappingsFromCurrentDonor, &ListOfDependenciesForStatements,
            &MappingCandidatesForGP, &ListOfNeededFunctionsForAllLOCs,
            &FinalDeclSymbolTable, skeletonInterfaceSourceCodeOutput,
            TemporaryInterface, InterfaceHeaderFileName,
            SkeletonCoreFeatureHeader, hostWithInterfaceOutputFile,
            interfaceOutput, SourceOutputCoreFunctionalities, InterfaceCoreFunctionality, inputFileGraft,
            &TotalIDsInHostSymbolTable, &HostSymbolTable,
            AllDefinedFunctionsInDonor, TXLTemporaryFolderMainThread, listOfSourceFilesTargetPath);

    //TODO look if they can be moved to GP */
    /*  Create the List of all markers */
    ListOfString * TheListOfTransplantedMarkers = createTheListOfAllMarkers( FinalSkeletonSourceCode, TXLTemporaryFolderMainThread);

#ifdef TEST_RESULTS
    compileAndExecuteNewProgram(compileCommand, outputFileName, transplantCFile);
#endif

#ifdef DEBUGING..
 int countNeedFunctions = 1;
 CallDependency *  AuxListOfNeededFunctionsForAllLOCs = ListOfNeededFunctionsForAllLOCs;
 printf("\tList Of Need Functions\n");
    while (AuxListOfNeededFunctionsForAllLOCs){
        printf(" \t[%d]: %s File: %s\n",countNeedFunctions, AuxListOfNeededFunctionsForAllLOCs->calledFunctions->functionName,AuxListOfNeededFunctionsForAllLOCs->calledFunctions->sourceFile);
        AuxListOfNeededFunctionsForAllLOCs = AuxListOfNeededFunctionsForAllLOCs->next;
        countNeedFunctions++;
    }
#endif 
    //GENERATE GLOBAL DEPENDENCY LIST FOR THE SKELETON!!!
    sprintf(stepTime, "Identificating feature dependences..: %s", getTime());
    printf("%s",getTime());
    addNewString(&execution_log, stepTime);
    fflush(stdout);
    DependencyList *GlobalDependencyList;
    DependencyList *GlobalDependencyListMultiFiles;
    DependencyList *SkeletonDependenciesOnGlobalsMultFiles;

    char *definedGlobalTypesAndVariablesFile = (char *) malloc(100 * sizeof(char));
    sprintf(definedGlobalTypesAndVariablesFile, "%stemp_global_type_var_declarations.out", TXLTemporaryFolderMainThread);

    char *tempGlobalDefsOutputInterface = (char *) malloc(100 * sizeof(char));
    sprintf(tempGlobalDefsOutputInterface, "%stemp_global_defs_output.out", TXLTemporaryFolderMainThread);
    fflush(stdout);

    char *tempGlobalDefsFileOutputInterface = (char *) malloc(100 * sizeof(char));
    sprintf(tempGlobalDefsFileOutputInterface, "%stemp_global_defs_file_output.out", TXLTemporaryFolderMainThread);
    fflush(stdout);

    char *tempGlobalDeclarations = (char *) malloc(100 * sizeof(char));
    sprintf(tempGlobalDeclarations, "%stemp_global_variable_declarations", TXLTemporaryFolderMainThread);

    fflush(stdout);

    char *GlobalFctDependOutput = (char *) malloc(100 * sizeof(char));
    sprintf(GlobalFctDependOutput, "%stemp_needed_functions_for_global_declarations.out",
            TXLTemporaryFolderMainThread);
    fflush(stdout);

#ifdef DEBUGING
    createFile(GlobalFctDependOutput);
#endif

    char *tempGlobalDependenciesInterface = (char *) malloc(100 * sizeof(char));
    sprintf(tempGlobalDependenciesInterface, "%stemp_global_dependencies.out", TXLTemporaryFolderMainThread);
    fflush(stdout);

    char * tempSourceHeaderFilesTargetPath = (char *) malloc(100 * sizeof(char));
    sprintf(tempSourceHeaderFilesTargetPath, "%stemp_source_header_files_target.out", TXLTemporaryMultiFileFolder);

/*   GlobalDeclarations ListOfFinalGlobalDeclarations1	= fixGlobalDeclarationsForSkeleton(FinalSkeletonSourceCode,
                                                   &GlobalDependencyList, &SkeletonDependenciesOnGlobals,
                                                   tempGlobalDeclarations, definedGlobalTypesAndVariablesFile,
                                                   tempDefinesFile, tempIncludeLibFile,
                                                   AllDefinedFunctionsInDonor, GlobalFctDependOutput,
                                                   TXLTemporaryFolderMainThread);*/
    DependencyList *SkeletonDependenciesOnGlobals;
    char *tempDefinesFile;
    tempDefinesFile = (char *) malloc(100 * sizeof(char));
    sprintf(tempDefinesFile, "%stemp_define_file.out", TXLTemporaryFolderMainThread);

    char *tempIncludeLibFile;
    tempIncludeLibFile = (char *) malloc(100 * sizeof(char));
    sprintf(tempIncludeLibFile, "%stemp_include_lib_file.out", TXLTemporaryFolderMainThread);
    GlobalDeclarations ListOfFinalGlobalDeclarations2;
    DependencyList * FinalGlobalDependencyList = NULL;
//#ifdef EXTRACT_GLOBAL_DECLARATION
#if  !defined(FAST_RUNNING)//LOSCHANGE23
    /* Create list of all global declarations */
    ListOfFinalGlobalDeclarations2 = extractGlobalDeclaration(AllDefinedFunctionsInDonor,
            definedGlobalTypesAndVariablesFile);


    FinalGlobalDependencyList = extractGlobalDependenciesMultFile(ListOfFinalGlobalDeclarations2,
                                                                  tempSourceHeaderFilesTargetPath, definedGlobalTypesAndVariablesFile,
                                                                 AllDefinedFunctionsInDonor, TXLTemporaryMultiFileFolder);

#else
   // ListOfFinalGlobalDeclarations2 = readGlobalDeclarationFromFile(tempGlobalDefsOutputInterface);
    ListOfFinalGlobalDeclarations2 = readGlobalDeclarationFromFileWithFile(tempGlobalDefsFileOutputInterface);
    FinalGlobalDependencyList = readDependencyListFromFile(tempGlobalDefsFileOutputInterface);

#endif
//#else
    GlobalDeclarations ListOfFinalGlobalDeclarations =
            fixGlobalDeclarationsForSkeleton(FinalSkeletonSourceCode,
                                             &GlobalDependencyList, &SkeletonDependenciesOnGlobals,
                                             tempGlobalDeclarations, definedGlobalTypesAndVariablesFile,
                                             tempDefinesFile, tempIncludeLibFile,
                                             AllDefinedFunctionsInDonor, GlobalFctDependOutput,
                                             TXLTemporaryFolderMainThread);
//#endif

//------------------------------
/*      char * AllDefinedFunctionsInHostInsetionPoint;
    AllDefinedFunctionsInHostInsetionPoint = (char *) malloc(500 * sizeof(char));
    sprintf(AllDefinedFunctionsInHostInsetionPoint,	"%stemp_all_defined_functions_int_host.out",
            TempVeinDirectory);

    char *coreFunctionName = NULL;
    coreFunctionName = (char *) malloc(500 * sizeof(char));
    sprintf(coreFunctionName, "%s_GRAFT_INTERFACE \"%s\"", GraftFunctionName,HostProject);
    addAStringsInTheFile(coreFunctionName,AllDefinedFunctionsInHostInsetionPoint);

    char *outputHeaderFilesInHost = (char *) malloc((strlen("temp_list_header_file_dependencies.out") + strlen(TXLTemporaryMultiFileFolder) + 5) * sizeof (char));
    sprintf(outputHeaderFilesInHost, "%stemp_list_header_file_dependencies.out",
            TempVeinDirectory);

    char * tempSourceHeaderFilesTargetPathFromHost;
    tempSourceHeaderFilesTargetPathFromHost= (char *) malloc(500 * sizeof(char));
    sprintf(tempSourceHeaderFilesTargetPathFromHost, "%stemp_source_header_files_target_in_host.out", TempVeinDirectory);

    char * tempSourceFiles;
    tempSourceFiles= (char *) malloc(500 * sizeof(char));
    sprintf(tempSourceFiles, "%stemp_source.out", TempVeinDirectory);

    char *tempGlobalDeclarationsFromHost;
    tempGlobalDeclarationsFromHost = (char *) malloc(500 * sizeof(char));
    sprintf(tempGlobalDeclarationsFromHost, "%stemp_global_variable_declarations",
            TempVeinDirectory);

    char *definedGlobalTypesAndVariablesFileFromHost;
    definedGlobalTypesAndVariablesFileFromHost = (char *) malloc(500 * sizeof(char));
    sprintf(definedGlobalTypesAndVariablesFileFromHost,
            "%stemp_global_type_var_declarations.out",
            TempVeinDirectory);

    char *tempDefinesFileFromHost;
    tempDefinesFileFromHost = (char *) malloc(500 * sizeof(char));
    sprintf(tempDefinesFileFromHost, "%stemp_define_file.out",
            TempVeinDirectory);

    char *GlobalFctDependOutputFromHost;
    GlobalFctDependOutputFromHost = (char *) malloc(1000 * sizeof(char));
    sprintf(GlobalFctDependOutputFromHost, "%stemp_needed_functions_for_global_declarations.out",
            TempVeinDirectory);

    ListOfString * ListOfSourceHeaderFilesNeeded = NULL;
    ListOfSourceHeaderFilesNeeded = getListOfHeaderDependency(transplantHostInputFile, outputHeaderFilesInHost, HostProject);
    ListOfString *ListOfFilesFormatted = NULL;
    char *formattedHeaderFilesPath;
    formattedHeaderFilesPath = (char *) malloc(500 * sizeof(char));
    sprintf(formattedHeaderFilesPath, "\"%s\" ", transplantHostInputFile);
    addNewString(&ListOfFilesFormatted,  formattedHeaderFilesPath);
    while(ListOfSourceHeaderFilesNeeded){
        sprintf(formattedHeaderFilesPath, "\"%s\" ", ListOfSourceHeaderFilesNeeded->el);
        addNewString(&ListOfFilesFormatted,  formattedHeaderFilesPath);
        ListOfSourceHeaderFilesNeeded = ListOfSourceHeaderFilesNeeded->next;
    }

    printAListOfStrings(ListOfFilesFormatted,tempSourceHeaderFilesTargetPathFromHost);

    /*GlobalDeclarations ListOfFinalGlobalDeclarationsInHost	= fixGlobalDeclarationsForSkeleton(FinalSkeletonSourceCode,
                                                 &GlobalDependencyList, &SkeletonDependenciesOnGlobals,
                                                 tempGlobalDeclarationsFromHost, definedGlobalTypesAndVariablesFileFromHost,
                                                 tempDefinesFileFromHost, tempDefinesFileFromHost,
                                                 AllDefinedFunctionsInHostInsetionPoint, GlobalFctDependOutputFromHost,
                                                                                                 TempVeinDirectory);

    GlobalDeclarations ListOfFinalGlobalDeclarationsInHost	= fixGlobalDeclarations(TempVeinDirectory,transplantHostInputFile ,
                          AllDefinedFunctionsInHostInsetionPoint,tempSourceHeaderFilesTargetPathFromHost ,
                          TempVeinDirectory);

    /* temp global dependencies: temp_global_dependencies.out
    char * tempGlobalDependenciesFromHost;
    tempGlobalDependenciesFromHost = (char *) malloc(500 * sizeof (char));
    sprintf(tempGlobalDependenciesFromHost, "%stemp_global_dependencies.out", TempVeinDirectory);

    DependencyList * GlobalDependenciesFromHost = readDependencyListFromFile(
            tempGlobalDependenciesFromHost);

    CallDependency * ListOfNeededFunctionsForGlobalsHost =
            extractNeededFunctionsForGlobals(ListOfFinalGlobalDeclarations2,
                                             GlobalFctDependOutput);
/*
    extractNeededFunctionsAndGlobalDeclarations(InterfaceCoreFunctionality,
            ListOfFinalGlobalDeclarationsInHost,
            FinalSkeletonSourceCode,
                                                ListOfNeededFunctionsForGlobalsHost,
                                                SkeletonDependenciesOnGlobals,
                                                GraftFunctionName,
                                                GlobalFctDependOutput,
                                                listOfSourceFilesTargetPath,
                                                ListOfFinalGlobalDeclarationsInHost,
                                                GlobalDependencyListMultiFiles);
*/
///COntinuar
  /*  extractNeededGlobalDeclarations(ListOfNeededFunctionsForAllLOCs, SkeletonDependenciesOnGlobals, ListOfFinalGlobalDeclarations2,GlobalDependenciesFromHost,
                                                                    tempGlobalDeclarations, definedGlobalTypesAndVariablesFile,
                                                                    FinalSkeletonSourceCode, TheListOfTransplantedMarkers,
                                                                    GlobalFctDependOutput);*/

 /*   DependencyList * FinalGlobalDependencyListInHostInsertPoint = NULL;
  FinalGlobalDependencyListInHostInsertPoint = extractGlobalDependencies2(AllDefinedFunctionsInHostInsetionPoint, TempVeinDirectory );
    //the output file of needed functions to be extracted for globals!
    char *GlobalFctDependOutputForHostInsertionPoint;
    GlobalFctDependOutputForHostInsertionPoint = (char *) malloc(1000 * sizeof(char));
    sprintf(GlobalFctDependOutputForHostInsertionPoint, "%stemp_needed_functions_for_global_declarations.out",
            TempVeinDirectory);
    fflush(stdout);
 CallDependency * ListOfNeededFunctionsForHostInsertionPoint = extractNeededFunctionsForGlobals(ListOfFinalGlobalDeclarationsInHost,
                                             GlobalFctDependOutputForHostInsertionPoint);*/

    /* Generate global dependency list for skeleton */

    SkeletonDependenciesOnGlobals = generateGlobalDependencyListForSkeleton(FinalSkeletonSourceCode,
                                                                              definedGlobalTypesAndVariablesFile,
                                                                              ListOfFinalGlobalDeclarations2,
                                                                              tempGlobalDeclarations,
                                                                              TXLTemporaryFolderMainThread);

    /* CREATE_ARRAY_OF_LINE_MUTATION_CANDIDATES */
    ArrayOfStrings ArrayOfLineMarkers = createArrayOfLineMutationCandidates(
            FinalSkeletonSourceCode, &ListOfMarkersForAbstractVariables,
            TXLTemporaryFolderMainThread);
#ifdef DEBUG
    char * tempArrayOfLineMarkers = (char *) malloc(100 * sizeof(char));
    sprintf(tempArrayOfLineMarkers, "%stemp_array_of_markers.out", TXLTemporaryFolderMainThread);
    printArrayOfString(ArrayOfLineMarkers, tempArrayOfLineMarkers);
#endif
        /* MODULE: GENERATE_DECLARATION_DEPENDENCIES_FOR_DONOR_VARIABLE_IN_ABSTRACT_MAPPINGS----------- */
    /*generate the dependency list for abstract values, which should be added if
     * the line is selected, and the mapping is done to an ID in the donor   */
#if !defined(FAST_RUNNING)
    DependencyListWithID * dependencyListForAbstract = dependencyListWithIDForDeclWithAbstractValues(
            ListOfMappingsFromCurrentDonor, FinalSkeletonSourceCode,
            ListOfMarkersForAbstractVariables, TXLTemporaryFolderMainThread);
    fflush(stdout);
#else
    char * tempOutputFileNeededDependenciesForAbstract;
    tempOutputFileNeededDependenciesForAbstract = (char *) malloc(500 * sizeof (char));
    sprintf(tempOutputFileNeededDependenciesForAbstract, "%stemp_dependencies_for_abstract.out", TXLTemporaryFolderMainThread);

    DependencyListWithID * dependencyListForAbstract = NULL;

    dependencyListForAbstract = readDependencyListWithIDFromFile(tempOutputFileNeededDependenciesForAbstract);
#endif
/*TEST*/



//TODO remove


    /* Create NeedFunctionHeader.c to vein functions declaration */
    char * sourceOutputFile;
    sourceOutputFile = (char *) malloc(500 * sizeof (char));
    sprintf(sourceOutputFile, "%sNeedSourceCode.c", TempVeinDirectory);

    /*call once */
    //to be checked not to add all functions for all globals, but just for one possible to be transplanted!!!
    CallDependency * ListOfNeededFunctionsForGlobals =
            extractNeededFunctionsForGlobals(ListOfFinalGlobalDeclarations2,
                                             GlobalFctDependOutput);

    //needed for extraction of global dependencies for core feature --------------------------------
    ListOfString * FinalListOfTransplantedFunctionsAsMarkersOld = NULL;
    //first add the feature marker for extraction, since globals for this too must be added
    char * GraftFunctionMarker;
    GraftFunctionMarker = (char *) malloc(500 * sizeof(char));
    sprintf(GraftFunctionMarker, "/* %s */", GraftFunctionName);
    addNewString(&FinalListOfTransplantedFunctionsAsMarkersOld,
                 GraftFunctionMarker);
     extractCoreFunctionsCalledInIndividual(ListOfNeededFunctionsForAllLOCs,
                                           FinalSkeletonSourceCode, SkeletonCoreFeatureHeader,
                                           listOfSourceFilesTargetPath,
                                           &FinalListOfTransplantedFunctionsAsMarkersOld,
                                           ListOfNeededFunctionsForGlobals, TXLTemporaryFolderMainThread);


    /* Insert Global declaration needed by functions. Return the final global declaration without
     * Global declaration that have already been inserted */
    GlobalDeclarations ListOfFinalGlobalDeclarationsWithNeededFunctionDecl;
    ListOfFinalGlobalDeclarationsWithNeededFunctionDecl = extractNeededGlobalDeclaractionsForFunctions( ListOfFinalGlobalDeclarations2, GlobalFctDependOutput);
    //-------------------------------------------------------------------------

    /* Copy functions declaration from DEC files to original files */
    char *tempAllSourceFilesTargetPath = (char *) malloc(500 * sizeof(char));
    sprintf(tempAllSourceFilesTargetPath, "%stemp_list_of_source_files_extracted.out", TXLTemporaryMultiFileFolder);
    moveExtractedFunctionDeclarationMultiFile(tempAllSourceFilesTargetPath);
    //-------------------------------------------------------------------------
///#if!defined(FAST_RUNNING2)
    /* Insert Global declaration needed by source code extracted *///LOSFIND
    extractNeededGlobalDeclarationsForExtractedLOCsMultiFiles(ListOfNeededFunctionsForAllLOCs,
                                                SkeletonDependenciesOnGlobals, ListOfFinalGlobalDeclarationsWithNeededFunctionDecl,FinalGlobalDependencyList,
                                                tempGlobalDeclarations, definedGlobalTypesAndVariablesFile,
                                                FinalSkeletonSourceCode, TheListOfTransplantedMarkers,
                                                GlobalFctDependOutput);
    //-------------------------------------------------------------------------
///#endif
    /*LOS Reading file temp_all_source_files_target.out */

    /*TEST	FILE *fListOHeaderExtracted = fopen(tempAllHeaderFilesExtractedPath, "w");
    fclose(fListOHeaderExtracted);*/

    char * allFunctionsExtracted;
    allFunctionsExtracted = (char *) malloc(500 * sizeof(char));
    sprintf(allFunctionsExtracted, "%sNeededSourceCode.c",
            TXLTemporaryFolderMainThread);

    /*LOS Forward slicing  Extract vein gobal declaration and struct */
    int countFiles;

    ListOfString * ListOfSourceFilesExtracted = readListOfStringFromFileAsWords(tempAllSourceFilesTargetPath);
    ListOfString * ListOfHeaderFilesExtracted  = readListOfStringFromFileAsWords(tempAllHeaderFilesExtractedPath);

    /* Insert directive include InterfaceHeader.h in all source files */
    ///LOSTESTEFINAL
   /// includeInterfaceHeaderIntoExtractedSourceFiles(ListOfSourceFilesExtracted);

    ListOfString * ListOfNeededLocalHeaderForInterface = ListOfHeaderFilesExtracted;
    ListOfString * auxListOfHeaderFilesExtracted = ListOfHeaderFilesExtracted;
    ListOfString * ListOfSourceHeaderFilesExtracted = ListOfSourceFilesExtracted;
    while(auxListOfHeaderFilesExtracted){
        addNewString(&ListOfSourceHeaderFilesExtracted, auxListOfHeaderFilesExtracted->el);
        auxListOfHeaderFilesExtracted = auxListOfHeaderFilesExtracted->next;
    }
    ///TODO changed to extracet all header file
    ///ListOfString * auxListOfSourceHeaderFilesExtracted = ListOfSourceHeaderFilesExtracted;
    ListOfSourceFilesExtracted = readListOfStringFromFileAsWords(tempAllSourceFilesTargetPath);;
    ListOfString * auxListOfSourceFilesExtracted = ListOfSourceFilesExtracted;

    auxListOfSourceFilesExtracted = ListOfSourceFilesExtracted;
    char *tempDefinesFileMultiFiles;
    tempDefinesFileMultiFiles = (char *) malloc(500 * sizeof(char));
    sprintf(tempDefinesFileMultiFiles, "%stemp_define_file.out", TXLTemporaryMultiFileFolder);

    char *tempIncludeLibFileMultiFiles;
    tempIncludeLibFileMultiFiles = (char *) malloc(500 * sizeof(char));
    sprintf(tempIncludeLibFileMultiFiles, "%stemp_include_lib_file.out",
            TXLTemporaryMultiFileFolder);

    countFiles = 1;
#ifdef  EXTRACT_INCLUDES_AND_DIRECTIVES
    while (auxListOfSourceFilesExtracted) {
        char * currentSourceFile = NULL;
        currentSourceFile = (char *) malloc((strlen(auxListOfSourceFilesExtracted->el) + 1) * sizeof (char));
        strcpy(currentSourceFile, auxListOfSourceFilesExtracted->el);


        strtok(currentSourceFile, "\n");
        char *formattedCurrentFileOrigenPath = (char *) malloc(500 * sizeof(char));
        sprintf(formattedCurrentFileOrigenPath, "\"%s%s\"", donorSourceFileFolder, currentSourceFile);

        addAStringsInTheFile(formattedCurrentFileOrigenPath,tempSourceHeaderFilesTargetPath);
        printf("\tFile[%d]: %s\n",
               countFiles, currentSourceFile);
        extractDefinitionsAndIncludes(&ListOfNeededLocalHeaderForInterface, currentSourceFile, tempSourceHeaderFilesTargetPath, tempDefinesFileMultiFiles, tempIncludeLibFileMultiFiles,
                                       AllDefinedFunctionsInDonor, GlobalFctDependOutput, TXLTemporaryMultiFileFolder);


        fflush(stdout);
        countFiles++;
        auxListOfSourceFilesExtracted = auxListOfSourceFilesExtracted->next;
    }

    auxListOfHeaderFilesExtracted  = readListOfStringFromFileAsWords(tempAllHeaderFilesExtractedPath);

    while (auxListOfHeaderFilesExtracted) {
        char * currentHeaderFile = NULL;
        currentHeaderFile = (char *) malloc((strlen(auxListOfHeaderFilesExtracted->el) + 1) * sizeof (char));
        strcpy(currentHeaderFile, auxListOfHeaderFilesExtracted->el);

        strtok(currentHeaderFile, "\n");
        char *formattedCurrentFileOrigenPath = (char *) malloc(500 * sizeof(char));
        sprintf(formattedCurrentFileOrigenPath, "\"%s%s\"", donorSourceFileFolder, currentHeaderFile);

        addAStringsInTheFile(formattedCurrentFileOrigenPath,tempSourceHeaderFilesTargetPath);
        extractDefinitionsToInterfaceHeader( currentHeaderFile, tempSourceHeaderFilesTargetPath, tempDefinesFileMultiFiles, tempIncludeLibFileMultiFiles,
                                                  AllDefinedFunctionsInDonor, GlobalFctDependOutput, TXLTemporaryMultiFileFolder);

        auxListOfHeaderFilesExtracted = auxListOfHeaderFilesExtracted->next;
    }
    // TODO rewrite the file copy to TransplantResultLocation
   /// ListOfString * listOfSourceFiles = readListOfStringFromFileAsWords(listOfSourceFilesTargetPath);



   /// ListOfString * listOfHeaderFiles = readListOfStringFromFileAsWords(listOfHeaderFilesTargetPath);
    fflush(stdout);
#endif
#ifdef  MAKEFILE_MULTIFILES /* Generate Makefile for multifiles */
    fflush(stdout);
    generateMakeFileMultiFiles("test_suite.c", InterfaceWithCoreFeatureFileName, InterfaceHeaderFileName, listOfSourceFilesTargetPath, tempAllHeaderFilesExtractedPath, "Individual.x", TransplantResultLocation);
#else
    generateMakeFile("main.c", InterfaceWithCoreFeatureFileName, InterfaceHeaderFileName, "Individual.x");
#endif
  ///  char *tempDefinesFile;
  ///  tempDefinesFile = (char *) malloc(100 * sizeof(char));
   /// sprintf(tempDefinesFile, "%stemp_define_file.out", TXLTemporaryFolderMainThread);

    fflush(stdout);
///    char *tempIncludeLibFile;
///    tempIncludeLibFile = (char *) malloc(100 * sizeof(char));
///    sprintf(tempIncludeLibFile, "%stemp_include_lib_file.out", TXLTemporaryFolderMainThread);

    /*LOS Insert needed header files include into over organ Interface core function and main file */
    insertNeededHeaderFileIncludeIntoInterfaceCFAndMainFile(ListOfNeededLocalHeaderForInterface);
    ListOfSourceFilesExtracted = readListOfStringFromFileAsWords(tempAllSourceFilesTargetPath);
    GPAlgorithm2(FinalSkeletonSourceCode, interfaceOutput,
                SourceOutputCoreFunctionalities, InterfaceCoreFunctionality, skeletonInterfaceSourceCodeOutput,
                ArrayOfLineMarkers, ListOfDependenciesForStatements,
                ListOfNeededFunctionsForAllLOCs, ListOfFinalGlobalDeclarations2,
                 FinalGlobalDependencyList, SkeletonDependenciesOnGlobals,
                tempGlobalDeclarations, definedGlobalTypesAndVariablesFile,
                GraftFunctionName, TemporaryInterface, TotalIDsInHostSymbolTable,
                MappingCandidatesForGP, FinalDeclSymbolTable,
                ListOfMappingsFromCurrentDonor, dependencyListForAbstract,
                tempDefinesFile, tempIncludeLibFile,
                skeletonInterfaceHeaderFileOutput, HostSymbolTable,
                GlobalFctDependOutput, ListOfSourceFilesExtracted, ListOfHeaderFilesExtracted, GlobalDependencyListMultiFiles, TheListOfTransplantedMarkers);
#if 1 /* MULTIORGAN TRANSPLANT*/
    // LOS: next transplant
    ListCoreFunctionWithDonorHostTarget = ListCoreFunctionWithDonorHostTarget->next;
    transplantNumber++;

#endif
		/*       instantiateAnIndividual(FinalSkeletonSourceCode, interfaceOutput, SourceOutputCoreFunctionalities,
	 	skeletonInterfaceSourceCodeOutput, ArrayOfLineMarkers, ListOfDependenciesForStatements,
	 	ListOfNeededFunctionsForAllLOCs,  ListOfFinalGlobalDeclarations, GlobalDependencyList,
	 	SkeletonDependenciesOnGlobals, tempGlobalDeclarations, definedGlobalTypesAndVariablesFile,
	 	GraftFunctionName, skeletonInterfaceHeaderFileOutput, TotalIDsInHostSymbolTable);
	 	*/

    //----------------
	printf("\n=====================FINISHED !!!!!=========================\n");
		free(skeletonInterfaceHeaderFileOutput);
		free(skeletonInterfaceSourceCodeOutput);
		free(hostWithInterfaceOutputFile);
		//freeListOfSymbolTable(&HostSymbolTable);
		//free(finalHostInterfaceOutput);

	//	printf("Hello, World!\n");
	return EXIT_SUCCESS;
}






