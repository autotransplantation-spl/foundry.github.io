#include "PrepareForGP.h"
#include "Mapping.h"
#include "MappingCandidate.h"
#include "DependencyList.h"
#include "GenTrans.h"
#include "FeatureInterface.h"
#include "Skeleton.h"
#include "SymbolTable.h"
#include "coreFunctionExtractor.h"
#include "FunctionExtractor.h"
#include "reverseCallGraph.h"
#include "folderContent.h"
#include "MarkFunctionCall.h"
#include "ListOfString.h"
#include "FunctionCallDependency.h"
#include "Utils.h"
#include "FunctionElement.h"
#include "DeclarationSymbolTable.h"
#include "GlobalDeclarations.h"
#include "IndividualInstantiator.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListOfString.h"
#include <sys/stat.h>

#include <dirent.h>


#include "except.h"
//LOS
#include "CallGraph.h"
#include "GenTrans.h"

#include "ListOfFunctionSourceFile.h"
#include <unistd.h>
//send the command for generating the simbol table, and then call the previous method for putting
//it in the SymbolTable structure
void printArrayOfString(ArrayOfStrings initial, char * outputFile) {
    FILE * fout = fopen(outputFile, "w");
    for (int i = 0; i < initial.count; i++)
        fprintf(fout, "%s\n", initial.array[i]);

    fclose(fout);
}

SymbolTable * readFromFileHostSymbolTable(char * inputFile, char * txlFile, char * TempOutputDirectory) {
    char * command;
    command = (char *) malloc(500 * sizeof(char));

    char *symbolTableFile;
    symbolTableFile = (char *) malloc(500 * sizeof(char));
    sprintf(symbolTableFile, "%stemp_symbol_table_host.out",
            TempOutputDirectory);

	printf("[TXL] hostSymbolTable.x >> Generate Host Symbol Table\n");
	sprintf(command, "ulimit -s 65353 && %s%s %s %s %s", TXLToolsPath, txlFile, inputFile,
			symbolTableFile, ConsoleStderrOutput);
	int status = system(command);
    if (status != 0) {
		printf("ERROR! readFromFileHostSymbolTable \n");
        system("open ErrorFile.out");
        if(file_exists(symbolTableFile))
            printf("temp_symbol_table_host was not generated. Please check if the graft tag is in the host insert  point\ne");
        exit(1);
	} else{
        /* Fixing void symbol */
        //TODO implement the removeSymbolTable(..)
        ListOfString * listOfSymbolTableHost = readListOfStringFromFile(symbolTableFile);
        ListOfString * auxlistOfSymbolTableHost = listOfSymbolTableHost;
        while(auxlistOfSymbolTableHost){
            if(!strcmp(auxlistOfSymbolTableHost->el, "void;\n"))
                removeString(&listOfSymbolTableHost, auxlistOfSymbolTableHost->el);
            auxlistOfSymbolTableHost = auxlistOfSymbolTableHost->next;
        }
        printAListOfStrings(listOfSymbolTableHost, symbolTableFile);
        freeListOfStrings(&auxlistOfSymbolTableHost);
        freeListOfStrings(&listOfSymbolTableHost);
    }

	FILE *fin = fopen(symbolTableFile, "r");
    SymbolTable *symbolTable = NULL;
    if(fin!=NULL) {

        symbolTable = readSymbolTableForHost(fin);
        fclose(fin);
    }else {
        printf("ERROR: Inserting point not found at the host environment!");
        exit(1);
    }
	free(command);
    free(symbolTableFile);
    fflush(stdout);
	return symbolTable;
}

//send the command for generating the simbol table, and then call the previous method for putting
//it in the SymbolTable structure

SymbolTable * readFromGraftSymbolTable(char * inputFile, char * txlFile,
		char * symbolTableFile, char * graftFunctionName) {
	char * ifdefFile;
	char * hostFile;

	if (!strcmp(TXLToolsPath, "./")) {
		ifdefFile = (char *) malloc((strlen(TXLToolsPath) + 10) * sizeof(char));
		sprintf(ifdefFile, "%sifdef.x", TXLToolsPath);
	} else {
		ifdefFile = (char *) malloc(10 * sizeof(char));
		sprintf(ifdefFile, "./ifdef.x");
	}
	hostFile = transplantHostInputFile;

	char command[1000];
	sprintf(command, "%s%s %s %s %s %s %s %s", TXLToolsPath, txlFile, hostFile,
			graftFunctionName, symbolTableFile, ifdefFile, inputFile,
			ConsoleNullOutput);

	int status = system(command);
	if (status != 0) {
		printf("ERROR! readFromGraftSymbolTable\n");
		return NULL;
	}
	FILE *fin = fopen(symbolTableFile, "r");
	SymbolTable * symbolTable = readSymbolTable(fin);
	fclose(fin);

	return symbolTable;
}

void createFinalHostInterface(char * interfaceFile, char * coreFeatureFile,
		char * TXLProgsPath, char * finalTransplantLocation) {
	char * commandTXL;
	commandTXL = (char *) malloc(500 * sizeof(char));
	sprintf(commandTXL, "%saddCoreFeatureToInterface.x %s %s %s %s",
			TXLProgsPath, interfaceFile, coreFeatureFile,
			finalTransplantLocation, ConsoleNullOutput);
	int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR! MutationCandidateExtractor.c\n");
	}
	free(commandTXL);
}

char * statementBeginning = "/* STM:";
char * declBeginning = "/* DECL:";
char * compoundBeginning = "/* COMPOUND:";

void addMissingLabels(ListOfString * skeletonSourceCode, char * allLabelsFile) {

	ListOfString * listOfUsedLabels = NULL;

	ListOfString * listOfDefinedLabels = NULL;
	//not used any more the list from the TXL program.
	// compute here the list of used labels!!!

	listOfDefinedLabels = readListOfStringFromFile(allLabelsFile);
	//remove the ones that are already existing in the skeleton
	ListOfString * aux = skeletonSourceCode;
	while (aux) {
		//this statement contains a label
		if (strstr(aux->el, "goto LABEL_")) {

			//first case when we have a marker
			if (strstr(aux->el, "/* COMPOUND:")) {
				char * gotoMarker = (char *) malloc(10 * sizeof(char));
				char * labelMarker = (char *) malloc(2000 * sizeof(char));
				int compNo;
				sscanf(aux->el, "%*s %*s %*s %*s %s %s ", gotoMarker,
						labelMarker);

				//sscanf(aux->el, "%s %s", gotoMarker, labelMarker);
				labelMarker[strlen(labelMarker) - 1] = 0;
				sprintf(labelMarker, "%s :", labelMarker);

				if (!searchStringInListOfStrings(listOfUsedLabels,
						labelMarker)) {
					addNewString(&listOfUsedLabels, labelMarker);
				}
			} else {
				// we do not have a marker
				char * gotoMarker = (char *) malloc(10 * sizeof(char));
				char * labelMarker = (char *) malloc(2000 * sizeof(char));

				sscanf(aux->el, "%s %s", gotoMarker, labelMarker);
				labelMarker[strlen(labelMarker) - 1] = 0;
				sprintf(labelMarker, "%s :", labelMarker);

				if (!searchStringInListOfStrings(listOfUsedLabels,

				labelMarker)) {

					addNewString(&listOfUsedLabels, labelMarker);

				}
			}

		}

		if (listOfUsedLabels) {
			removeStringLabels(&listOfUsedLabels, aux->el);
		}
		aux = aux->next;
	}

	int signal = 0;
	ListOfString * auxSkeleton = skeletonSourceCode;

    if (listOfUsedLabels) {
        // No need to check here if auxSkeleton->next exist. If there was no problem up to here it should always exist
        while (auxSkeleton->next && !signal) {
            if (strstr(auxSkeleton->next->el, RETURN_MARKER)) {
                aux = auxSkeleton->next;
                auxSkeleton->next = listOfUsedLabels;
                while (listOfUsedLabels->next) {
                    listOfUsedLabels = listOfUsedLabels->next;
                }
                listOfUsedLabels->next = aux;
                signal = 1;
            }

            auxSkeleton = auxSkeleton->next;
        }
    }


}


#ifdef REPLACE_STATIC_FUNCTION_DECLARATIONS
void solveDonorStaticFunctionDeclarationsUniqueNamesAndMarkersReplacement(
		char * donorSourceFiles, char * TXLTemporaryFolder) {
	//AcceptedFunctionsForGP GraftFunctionName

	char * tempSourceFilesOutput = (char *) malloc(1000 * sizeof(char));

	sprintf(tempSourceFilesOutput, "%stemp_donor_source_file_for_static.out",
			TXLTemporaryFolder);
	FILE * outputDonorSourceFiles = fopen(tempSourceFilesOutput, "w");

	readFilesFromDir(donorSourceFiles, outputDonorSourceFiles, 'c');
	fclose(outputDonorSourceFiles);

	char * tempCoreFctOutputFile = (char *) malloc(1000 * sizeof(char));
	sprintf(tempCoreFctOutputFile, "%stemp_new_core_fct_name.out",
			TXLTemporaryFolder);
	char * commandTXL;
	commandTXL = (char *) malloc(5000 * sizeof(char));

#ifdef REPLACE_STATIC_BY_FILE

    /* LOS RUNNIG IT IN A MACBOOK:  Keep it off for running MuScalpel using a machine with reduced stack size
 * create file temp_new_core_fct_name.out manually and insert the core function name*/

	int numberOfFiles = countlines(tempSourceFilesOutput);

    printf("TXL: replaceStaticFunctions.x >> Replace Static Functions\n");

	char * line;
	line = (char *) malloc(400 * sizeof(char));
	FILE * fin = fopen(tempSourceFilesOutput, "r");
	char * tempPartialSourceFilesOutput = (char *) malloc(1000 * sizeof(char));

	sprintf(tempPartialSourceFilesOutput, "%stemp_partial_donor_source_file_for_static.out",
				TXLTemporaryFolder);
	int count = 1;
	//LOS_TEMP
	remove(tempPartialSourceFilesOutput);
	while (fgets(line, 1000, fin) != NULL) {
		char * currentFile=NULL;
		currentFile = (char *) malloc(400 * sizeof(char));
		sscanf(line, "%s", currentFile);
       // if(!strstr(currentFile,"eval.c")) {
            FILE *fTempPartialSourceFiles = fopen(tempPartialSourceFilesOutput, "a+");
            fprintf(fTempPartialSourceFiles, "%s", currentFile);
            printf("\t[%d] File:>> %s\n", count, currentFile);
            fclose(fTempPartialSourceFiles);
            sprintf(commandTXL, "%sreplaceStaticFunctions.x %s %s %s %s %s %s", TXLToolsPath,
                    tempPartialSourceFilesOutput, AcceptedFunctionsForGP,
                    AcceptedFunctionsForGP, GraftFunctionName, tempCoreFctOutputFile,
                    ConsoleStderrOutput);

            int status = system(commandTXL);
            if (status != 0) {
                printf("ERROR replace static function! File: >> %s\n", currentFile);
               // fprintf(stderr, "Error: %s", strerror(errno));
                txlErrorMessage("replaceStaticFunctions");
              //  exit(1);
            }
            //free(commandTXL);
            remove(tempPartialSourceFilesOutput);
            count++;
      //  }
		fflush(stdout);
	}

	char * newTargetFunctionName = (char *) malloc(100 * sizeof(char));
	FILE * finCoreFctName = fopen(tempCoreFctOutputFile, "r");
	fscanf(finCoreFctName, "%s", newTargetFunctionName);
	free(GraftFunctionName);
	GraftFunctionName = newTargetFunctionName;
#else
    //LOSCOMMENTTEMP to run VIM

	sprintf(commandTXL, "%sreplaceStaticFunctions.x %s %s %s %s %s %s",
			TXLToolsPath, tempSourceFilesOutput, AcceptedFunctionsForGP,
			AcceptedFunctionsForGP,"idct", tempCoreFctOutputFile,
			ConsoleNullOutput);

	sprintf(commandTXL, "%sreplaceStaticFunctions.x %s %s %s %s %s %s",
			TXLToolsPath, tempSourceFilesOutput, AcceptedFunctionsForGP,
			AcceptedFunctionsForGP, GraftFunctionName, tempCoreFctOutputFile,
			ConsoleStderrOutput);
	printf("[TXL] replaceStaticFunctions.x >> sreplaceStaticFunctions\n");

	int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR replace static function!");

	}else {
		free(commandTXL);
		char *newTargetFunctionName = (char *) malloc(100 * sizeof(char));
		FILE *finCoreFctName = fopen(tempCoreFctOutputFile, "r");
		fscanf(finCoreFctName, "%s", newTargetFunctionName);
		free(GraftFunctionName);
		GraftFunctionName = newTargetFunctionName;
	}
#endif
}
#endif

#ifdef VEIN_GLOBAL_EXTRACTION

void extractVeinFunctions(char * sourceOutputFile, char * tempCurrentTargetFunctionPath, char *  graftSourceCodeFile, char * tempSourceFilesFolderPath, char * transplantWorkingFolder,
                           char * txlProgsPath, char * TXLTemp, char * tempFolder, char * TXLTempMultiFiles){

    char * listOfFunctionVeinPath = (char *) malloc(100 * sizeof (char));
    sprintf(listOfFunctionVeinPath, "%stemp_list_vein_functions.out", TempVeinDirectory);

    char * listOfFilesToVeinPath = (char *) malloc(100 * sizeof (char));
    sprintf(listOfFilesToVeinPath, "%stemp_list_vein_files.out", TempVeinDirectory);

	/* Create NeedFunctionHeader.h to vein functions declaration */
	char * headerOutputFile = (char *) malloc(100 * sizeof (char));
	sprintf(headerOutputFile, "%sNeedFunctionHeader.h", TempVeinDirectory);
	createFile(headerOutputFile);

	/* Create NeedFunctionHeader.c to vein functions declaration */
	char * partialSourceOutputFile = (char *) malloc(100 * sizeof (char));
	sprintf(partialSourceOutputFile, "%sPartialNeedSourceCode.c", TempVeinDirectory);
	createFile(partialSourceOutputFile);

	/* Create headerContentFile.h to vein functions declaration */
	char * sourceFile = (char *) malloc(100 * sizeof (char));
	sprintf(sourceFile, "%ssourceFilesInDonor.out", TempVeinDirectory);
	createFile(sourceFile);

	/* Create headerContentFile.h to vein functions declaration */
	char * headerContentFile = (char *) malloc(100 * sizeof (char));
	sprintf(headerContentFile, "%stemp_list_of_header_files.out", TXLTempMultiFiles);
	createFile(headerContentFile);

	char *command;
    command = (char *) malloc(2000 * sizeof(char *));

   // ListOfString *listOfFunctionInVeinFile = readListOfStringFromFileAsWords(listOfFunctionVeinPath);
    ListOfString *listOfVeinFile = readListOfStringFromFileAsWords(listOfFilesToVeinPath);

    int countFunctions = 1;

	/* Create veinContentFile to print  vein file list */
	char * veinContentFile;
	veinContentFile = (char *) malloc(100 * sizeof (char));
	sprintf(veinContentFile, "%sVeinContentFile.out", TempVeinDirectory);

	ListOfString * listOfFiles = NULL;
    while (listOfVeinFile) {
        char *formattedFilePath = NULL;
		formattedFilePath = (char *) malloc((strlen(listOfVeinFile->el) + strlen(tempDonorSourceFileFolder)  + 10) * sizeof(char));
		sprintf(formattedFilePath, "\"%s%s\" ", tempDonorSourceFileFolder, listOfVeinFile->el);
		addNewString(&listOfFiles,formattedFilePath);

		listOfVeinFile = listOfVeinFile->next;
		fflush(stdout);
	}
	printAListOfStrings(listOfFiles,veinContentFile);

	/* Create list of functions target */
	char * listOfNeededHeadFilesForVein;
	listOfNeededHeadFilesForVein = (char *) malloc(100 * sizeof (char));
	sprintf(listOfNeededHeadFilesForVein, "%stemp_list_of_header_files.out", TempVeinDirectory);
	//createFile(listOfNeededHeadFilesForVein);

	char * ifDefProgramPath;

	if (strcmp(TXLToolsPath, "./")) {
		ifDefProgramPath = (char *) malloc(
				(strlen(TXLToolsPath) + 10) * sizeof(char));
		sprintf(ifDefProgramPath, "%sifdef.x", TXLToolsPath);
	} else {
		ifDefProgramPath = (char *) malloc(10 * sizeof(char));
		sprintf(ifDefProgramPath, "./ifdef.x");
	}

	//printf("[TXL] MultiFilesExtraction.x - Extract vein\n");
//TODO  Remove transplantHostInputFile from MUltiFilesExtraction.x inputs
	/*sprintf(command, "ulimit -s 65353 && ./%smultiFilesExtraction.x %s %s %s %s %s %s %s %s %s%s %s",
			txlProgsPath, transplantHostInputFile, graftSourceCodeFile, headerOutputFile,
			partialSourceOutputFile, tempCurrentTargetFunctionPath, veinContentFile, headerContentFile,
			listOfNeededHeadFilesForVein, TXLToolsPath, ifDefProgramPath,
			ConsoleStderrOutput);*/

    sprintf(command, "ulimit -s 65353 && ./%smultiFilesExtraction.x %s %s %s %s %s %s %s %s %s%s %s",
            txlProgsPath, graftSourceCodeFile, graftSourceCodeFile, headerOutputFile,
            partialSourceOutputFile, tempCurrentTargetFunctionPath, veinContentFile, headerContentFile,
            listOfNeededHeadFilesForVein, TXLToolsPath, ifDefProgramPath,
            ConsoleStderrOutput);

	int commandStatus = system(command);
	if (commandStatus != 0) {
		printf("ERROR vein extraction!!!!!\n");
		system("open ErrorFile.out");
		exit(1);
	}else{
		/* Add current function LOCs in the final file with functions in vein */
		addLocsFromSourceToDestination(sourceOutputFile, partialSourceOutputFile, TXLToolsPath);
	}

    free(listOfFunctionVeinPath);
    free(listOfFilesToVeinPath);
    free(headerOutputFile);
    free(partialSourceOutputFile);
    free(sourceFile);
    free(headerContentFile);
    free(veinContentFile);
    free(listOfNeededHeadFilesForVein);
}

#endif

/* create a list with source and header file names from donor*/
createListOfSourceAndHeaderFilesFromDonor(){
    char *sourceFiles;
    sourceFiles = (char *) malloc(100 * sizeof(char));
    sprintf(sourceFiles, "%ssourceFilesInDonor.out", TXLTemporaryMultiFileFolder);

    char *headerFiles;
    headerFiles = (char *) malloc(100 * sizeof(char));
    sprintf(headerFiles, "%sheaderFilesInDonor.out", TXLTemporaryMultiFileFolder);

    FILE *sourceFileName = fopen(sourceFiles, "w");
    printf("\tCreate list of 'c' source file names from the Donor\n");
    readFilesFromDir(donorSourceFileFolder, sourceFileName, 'c');
    fclose(sourceFileName);

    FILE *donorHeaderFiles = fopen(headerFiles, "w");
    printf("\tCreate list of '.h' source file names from the Donor\n");
    readFilesFromDir(donorSourceFileFolder, donorHeaderFiles, 'h');
    fclose(donorHeaderFiles);

    /* create list of all source header files in donor AllSourceHeaderFilesInDonor.out*/
    char *allSourceHeaderFilesInDonor;
    allSourceHeaderFilesInDonor = (char *) malloc(100 * sizeof(char));
    sprintf(allSourceHeaderFilesInDonor, "%sAllSourceHeaderFilesInDonor.out", TXLTemporaryMultiFileFolder);

    ListOfString * ListOfAllSourceHeaderFilesInDonor = readListOfStringFromFile(sourceFiles);
    ListOfString * ListOfHeaderFilesInDonor = readListOfStringFromFile(headerFiles);
    while(ListOfHeaderFilesInDonor) {
        addNewString(&ListOfAllSourceHeaderFilesInDonor, ListOfHeaderFilesInDonor->el);
        ListOfHeaderFilesInDonor = ListOfHeaderFilesInDonor->next;
    }
    /*print list of source and reader files AllSourceHeaderFilesInDonor.out*/
    printAListOfStrings(ListOfAllSourceHeaderFilesInDonor,allSourceHeaderFilesInDonor);

    free(sourceFiles);
    free(headerFiles);
    freeListOfStrings(&ListOfAllSourceHeaderFilesInDonor);
    freeListOfStrings(&ListOfHeaderFilesInDonor);
    free(allSourceHeaderFilesInDonor);

}

void replaceHostWithInterfaceKeepingComments(){
    char * hostInterfaceOutput;
    hostInterfaceOutput = (char *) malloc(500 * sizeof(char));
    sprintf(hostInterfaceOutput, "%sHostWithInterface.c",
            TransplantResultLocation);

    /* Copy HostWith file*/
    char *commandCopyFileContent = (char *) malloc(500 * sizeof(char));
    sprintf(commandCopyFileContent, "cp -r %s %s", transplantHostInputFile, hostInterfaceOutput);
    int statusCommand = system(commandCopyFileContent);
    if (statusCommand != 0) {
        printf("ERROR: Copy Host with interface to TestSuites directory. \n\tNo such file or directory: %s\n",TransplantResultLocation);
        exit(1);
    }

    /* Getting interfaceDeclaration */
    char * tempInterfaceDecl;
    tempInterfaceDecl = (char *) malloc(500 * sizeof (char));
    strcpy(tempInterfaceDecl, TXLTemporaryFolderMainThread);
    strcat(tempInterfaceDecl, "temp_decl_from_interface.out");

    ListOfString * interterfaceDecl = readListOfStringFromFile(tempInterfaceDecl);
    ListOfString * interfaceCall = NULL;
    char * currentLine = (char *) malloc(500 * sizeof(char));
    char * interfaceDeclaration = (char *) malloc(500 * sizeof(char));
    while(interterfaceDecl){
    strcpy(currentLine, interterfaceDecl->el);

    if (strstr(interterfaceDecl->next->el,  "__INTERFACE_FUNCTION")) {
        currentLine = strtok(currentLine, "{");
        sprintf(interfaceDeclaration,"extern %s;\n", currentLine);
    }

    if (strstr(currentLine,  "__ADDGRAFTHERE__JUSTHERE")) {
        interterfaceDecl = interterfaceDecl->next;
        while(interterfaceDecl){
            strcpy(currentLine, interterfaceDecl->el);
            addNewString(&interfaceCall, currentLine);
            interterfaceDecl = interterfaceDecl->next;
        }
    } else
        interterfaceDecl = interterfaceDecl->next;
    }

    /* Replace graft input and add include InterfaceHeader.h */
    /*char * includeCoreFeatureHeader;
    includeCoreFeatureHeader = (char *) malloc(1000 * sizeof(char));
    sprintf(includeCoreFeatureHeader, "#include \"%s\"\n",
            InterfaceHeaderFileName);*/
    ListOfString * hostWithInterfaceContent = readListOfStringFromFile(hostInterfaceOutput);
   /// addNewStringInTheBegging(&hostWithInterfaceContent,includeCoreFeatureHeader);
  ///  addNewStringInTheBegging(&hostWithInterfaceContent,interfaceDeclaration);
    replaceOneLineInALIst(&hostWithInterfaceContent,"//__ADDINTERFACE_DECL\n", interfaceDeclaration);
    replaceOneLineWithAListWithStr(&hostWithInterfaceContent, interfaceCall, "__ADDGRAFTHERE__JUSTHERE\n");
    printAListOfStrings(hostWithInterfaceContent, hostInterfaceOutput);

    freeListOfStrings(&hostWithInterfaceContent);
    freeListOfStrings(&interterfaceDecl);
    freeListOfStrings(&interfaceCall);
    free(currentLine);
    ///free(includeCoreFeatureHeader);
    free(hostInterfaceOutput);
    free(tempInterfaceDecl);
    free(commandCopyFileContent);
    fflush(stdout);
}

void createInterfaceHeader(char * skeletonInterfaceHeaderFileOutput, char * testSuitesDirectory, char * headerForInterfaceJustName){
    char * headerForInterfaceJustNameInTestDirectory;
    headerForInterfaceJustNameInTestDirectory = (char *) malloc(500 * sizeof(char));
    sprintf(headerForInterfaceJustNameInTestDirectory, "%s%s", testSuitesDirectory, headerForInterfaceJustName);

    char *commandCopyFileContent = (char *) malloc(500 * sizeof(char));
    sprintf(commandCopyFileContent, "cp -r %s %s", skeletonInterfaceHeaderFileOutput, headerForInterfaceJustNameInTestDirectory);
    int statusCommand = system(commandCopyFileContent);
    if (statusCommand != 0) {
        printf("ERROR: Copy Host with interface header to TestSuites directory. \n\tNo such file or directory: %s\n",headerForInterfaceJustNameInTestDirectory);
        exit(1);
    }
    free(commandCopyFileContent);
    free(headerForInterfaceJustNameInTestDirectory);
    fflush(stdout);
}
void generateUnitTests(char * testSuitesDirectory, char * skeletonInterfaceHeaderFileOutput,
		char * headerForInterfaceJustName,  char * TXLTemporaryFolder){

    SymbolTable * HostSymbolTable = readFromFileHostSymbolTable(transplantHostInputFile,
                                                  txlFileHost, TXLTemporaryFolderMainThread);
    /* Create InterfaceWithCoreFeature.c */
    char * interfaceOutput = (char *) malloc(500 * sizeof(char));
    sprintf(interfaceOutput, "%sInterfaceWithCoreFeature.c", testSuitesDirectory);

    if(!file_exists(interfaceOutput))
    	removeAFileFromADirectory(interfaceOutput);//remove old temp_InterfaceSourceFile.out

    generateHostInterface(HostSymbolTable, TXLTemporaryFolder, TXLToolsPath,
                          inputFileGraft, hostWithInterfaceOutputFile, skeletonInterfaceHeaderFileOutput,
                          transplantHostInputFile, interfaceOutput,
                          headerForInterfaceJustName, GraftFunctionName);

    /* Insert a comment in the interface annotation - InterfaceWithCoreFeature.c */

    ListOfString * interfaceContent = readListOfStringFromFile(interfaceOutput);
    replaceOneLineInALIst(&interfaceContent, "__INTERFACE_FUNCTION", "\t//__INTERFACE_FUNCTION\n");
    printAListOfStrings(interfaceContent, interfaceOutput);
#ifdef DEBUGING
    printf("\t>> InterfaceWithCoreFunction.c\n");
#endif

#ifdef DEBUGING
    printf("\t>> HostWithInterface.c\n");
#endif
    /*Create InterfaceHeader.h */
    createInterfaceHeader(skeletonInterfaceHeaderFileOutput, testSuitesDirectory, headerForInterfaceJustName);
#ifdef DEBUGING
    printf("\t>> InterfaceHeader.c\n");
#endif
    free(interfaceOutput);
    fflush(stdout);
}

//pruner
void pruner_vein(char *outputFile){
    struct Stack* stackOfCompounds = createAStack(100);
    //pruning unnecessary compounds from outputFCTLOCS.out
    int removeStatement = 0;
    char * graftFunctionNameSTM = (char *) malloc(100 * sizeof (char));
    sprintf(graftFunctionNameSTM, "%s %s",STATEMENT_MARKER, GraftFunctionName);

    char *graftFunctionNameWithReturnMarker = (char *) malloc(100 * sizeof(char));
    sprintf(graftFunctionNameWithReturnMarker, "%s %s", RETURN_MARKER, GraftFunctionName);

    char *mainReturnMarkerSTM = (char *) malloc(100 * sizeof(char));
    sprintf(mainReturnMarkerSTM, "%s %s", STATEMENT_MARKER, MAIN_RETURN_MARKER);

    ListOfString *ListOutputFCTLOCS = readListOfStringFromFile(outputFile);
    ListOfString *prunedOutputFCTLOCS = NULL;
    char *currentSTM = (char *) malloc(1000 * sizeof(char));

    while(ListOutputFCTLOCS){
        strcpy(currentSTM,ListOutputFCTLOCS->el);
        if(strstr(currentSTM, COMPOUND_START_MARKER) && removeStatement==0)
            push(stackOfCompounds, 1);
        if(strstr(currentSTM, COMPOUND_END_MARKER))
            pop(stackOfCompounds);

        if(strstr(currentSTM, graftFunctionNameSTM)) {
            currentSTM = replace_str(currentSTM, graftFunctionNameSTM,
                                                   graftFunctionNameWithReturnMarker);
            removeStatement = 1;
            addNewString(&prunedOutputFCTLOCS, currentSTM);
        }
        if(strstr(ListOutputFCTLOCS->el, mainReturnMarkerSTM))
            removeStatement = 0;

        if( removeStatement==0)
            addNewString(&prunedOutputFCTLOCS, currentSTM);
        else
            if(!isEmpty(stackOfCompounds) && strstr(ListOutputFCTLOCS->next->el, COMPOUND_END_MARKER))
                addNewString(&prunedOutputFCTLOCS, currentSTM);

        fflush(stdout);
        ListOutputFCTLOCS = ListOutputFCTLOCS->next;
    }

    printAListOfStrings(prunedOutputFCTLOCS,outputFile);
    free(graftFunctionNameSTM);
    free(mainReturnMarkerSTM);
    free(graftFunctionNameWithReturnMarker);
    //free(currentSTM);
    freeListOfStrings(&ListOutputFCTLOCS);
    freeListOfStrings(&prunedOutputFCTLOCS);

}
  int xx;
ListOfString * prepareForGP(Mapping ** ListOfMappingsFromCurrentDonor,
		DependencyList ** ListOfDependenciesForStatements,
		MappingCandidate ** MappingCandidatesForGP,
		CallDependency ** ListOfNeededFunctionsForAllLOCs,
		DeclarationSymbolTable ** FinalDeclSymbolTable,
		char * skeletonInterfaceSourceCodeOutput,
		char * skeletonInterfaceHeaderFileOutput,
		char * headerForInterfaceJustName, char * skeletonCoreFeatureHeader,
		char * hostWithInterfaceOutputFile, char * interfaceOutput,
		char * sourceOutputCoreFunctionality, char * interfaceCoreFunctionalityCode, char * graftSourceCodeFile,
        int * countOfHostIDs,
		SymbolTable ** finalHostSymbolTable, char * outputDefinedFunctions,
		char * TXLTemporaryFolder, char * listOfSourceFilesTargetPath) {

    printf("[AUTOSCALPEL] Preparing for GP.\n");
    /* Generate call and caller graphs, if they have not been generated */
#ifdef GENERATE_DONOR_CALL_AND_CALLED_GRAPHS
    generateCallAndCallerGraphs();
#endif

#ifdef READ_FROM_FILE_HOST_SYMBOL_TABLE
    /* first prepare the donor, by solving the static functions declarations! */
    SymbolTable *HostSymbolTable = NULL;
    HostSymbolTable = readFromFileHostSymbolTable(transplantHostInputFile,
                                                  txlFileHost, TXLTemporaryFolderMainThread);

    /* count the IDs in host symbol table for fitness computation */
    *countOfHostIDs = countIDsInSymbolTable(HostSymbolTable);
    fflush(stdout);
#endif

#ifdef GENERATE_HOST_INTERFACE
    generateHostInterface(HostSymbolTable, TXLTemporaryFolder, TXLToolsPath,
                          inputFileGraft, hostWithInterfaceOutputFile, skeletonInterfaceHeaderFileOutput,
                          transplantHostInputFile, interfaceOutput,
                          headerForInterfaceJustName, GraftFunctionName);
    replaceHostWithInterfaceKeepingComments();
    /* Create a host file with interface call - HostWithInterface.c*/
    fflush(stdout);
#endif


    /* Extract List of all source files and functions in donor */
    char *outputListOfSourceFilesFromDonor = (char *) malloc(100 * sizeof(char));
    sprintf(outputListOfSourceFilesFromDonor, "%stemp_donor_files_for_function_list.out", TXLTemporaryFolder);
    createListOfDonorFunctions(TXLToolsPath, outputListOfSourceFilesFromDonor, outputDefinedFunctions);

    /* Extract List of all source files and functions in donor */
    char *allDefinedFunctionsInHost = (char *) malloc(100 * sizeof(char));
    sprintf(allDefinedFunctionsInHost, "%stemp_all_defined_functions_in_host.out", TXLTemporaryFolder);
    char *outputListOfSourceFilesFromHost = (char *) malloc(100 * sizeof(char));
    sprintf(outputListOfSourceFilesFromHost, "%stemp_host_files_for_function_list.out", TXLTemporaryFolder);
    char *formattedHostProject = (char *) malloc(100 * sizeof(char));
    sprintf(formattedHostProject, "%s/", HostProject);
    createListOfFileFunctions(formattedHostProject, TXLToolsPath, outputListOfSourceFilesFromHost,
                              allDefinedFunctionsInHost);
    //----------------------
//#if !defined(FAST_RUNNING)//LOSCHANGE23
#ifdef EXTRACT_FUNCTIONALITY_MULTIFILE//LOSCHANGE23
    createListOfSourceAndHeaderFilesFromDonor();
    //TODO reset list of file extracted. Improve this bloc passing lisOfFuncitonsFileExtractedFullPath to the function extractFunctionality.
    /* Create file with a list of functions files target */
    char *listOfFunctionsFilesExtractedFullPath = (char *) malloc(100 * sizeof(char));
    sprintf(listOfFunctionsFilesExtractedFullPath, "%slist_of_functions_file_target.out", TXLTemporaryMultiFileFolder);
    createFile(listOfFunctionsFilesExtractedFullPath);
    //------------------------------------
    printf("[AUTOSCALPEL] Extracting functionality from entry function: [ %s ]\n", GraftFunctionName);
    extractFunctionality(GraftFunctionName, graftSourceCodeFile, donorSourceFileFolder,
                         TXLToolsPath, TXLTemporaryFolder, TXLTemporaryMultiFileFolder);
    fflush(stdout);
#endif
//#endif
    /* Set CurrentExistingMappings.out */
    char *CurrentExistingMappings = (char *) malloc(
            (strlen(TXLTemporaryFolder) + 40) * sizeof(char));
    sprintf(CurrentExistingMappings, "%sCurrentExistingMappings.out",
            TXLTemporaryFolder);

    /* Set outputFCTLOCS.out */
    char *modifiedFunctionLOCs = (char *) malloc(
            (strlen(TXLTemporaryFolder) + 20) * sizeof(char));
    sprintf(modifiedFunctionLOCs, "%soutputFCTLOCS.out", TXLTemporaryFolder);
    fflush(stdout);

    /* Set SkeletonInstantiateMappings.out */
    char *skeletonInstantiationMappings = (char *) malloc(
            (strlen(TXLTemporaryFolder) + 40) * sizeof(char));
    sprintf(skeletonInstantiationMappings, "%sSkeletonInstantiateMappings.out",
            TXLTemporaryFolder);

    /* Set HostSymbolTable.out */
    char *HostSymbolTableFile = (char *) malloc(
            (strlen(TXLTemporaryFolder) + 40) * sizeof(char));
    sprintf(HostSymbolTableFile, "%sHostSymbolTable.out", TXLTemporaryFolder);

    /* Set temp_output_labels.out */
    char *outputFileLabels = (char *) malloc(500 * sizeof(char));
    sprintf(outputFileLabels, "%stemp_output_labels.out", TXLTemporaryFolderMainThread);
    fflush(stdout);

///#ifdef GENERATE_REVERSE_CALL_GRAPH
    ListOfString *reverseCallGraph = NULL;
    generateReverseCallGraph(allDefinedFunctionsInHost, TXLToolsPath, modifiedFunctionLOCs,
                             skeletonInstantiationMappings, HostSymbolTableFile,
                             CurrentExistingMappings, TXLTemporaryFolder,
                             GraftFunctionName, &reverseCallGraph,
                             outputFileLabels);
///#endif

#ifdef PRUNER //fix error in dependencyList before able it
    pruner_vein(modifiedFunctionLOCs);
#else


    char *graftFunctionNameSTM = (char *) malloc(100 * sizeof(char));
    sprintf(graftFunctionNameSTM, "%s %s", STATEMENT_MARKER, GraftFunctionName);
    char *graftFunctionNameWithReturnMarker = (char *) malloc(100 * sizeof(char));
    sprintf(graftFunctionNameWithReturnMarker, "%s %s", RETURN_MARKER, GraftFunctionName);
    ListOfString *ListOutputFCTLOCS = readListOfStringFromFile(modifiedFunctionLOCs);
    ListOfString *prunedOutputFCTLOCS = NULL;
    char *currentSTM = (char *) malloc(1000 * sizeof(char));
    int grafitFuncionSTMFound = 0;
    while (ListOutputFCTLOCS) {
        strcpy(currentSTM, ListOutputFCTLOCS->el);

        if (strstr(currentSTM, graftFunctionNameSTM) && grafitFuncionSTMFound != 1) {
            currentSTM = replace_str(currentSTM, graftFunctionNameSTM, graftFunctionNameWithReturnMarker);
            addNewString(&prunedOutputFCTLOCS, currentSTM);
            grafitFuncionSTMFound = 1;
        } else
            addNewString(&prunedOutputFCTLOCS, currentSTM);
        fflush(stdout);
        ListOutputFCTLOCS = ListOutputFCTLOCS->next;
    }
    printAListOfStrings(prunedOutputFCTLOCS, modifiedFunctionLOCs);
    free(graftFunctionNameSTM);
    free(graftFunctionNameWithReturnMarker);
    freeListOfStrings(&ListOutputFCTLOCS);
    freeListOfStrings(&prunedOutputFCTLOCS);
#endif

#ifdef VEIN_GLOBAL_EXTRACTION

    char *tempCurrentTargetFunctionPath; // Create list of functions target
    tempCurrentTargetFunctionPath = (char *) malloc(500 * sizeof(char));
    sprintf(tempCurrentTargetFunctionPath, "%stemp_function_files_target.out", TempVeinDirectory);

    char *sourceOutputFile; // Create NeedFunctionHeader.c to vein functions declaration
    sourceOutputFile = (char *) malloc(500 * sizeof(char));
    sprintf(sourceOutputFile, "%sNeedSourceCode.c", TempVeinDirectory);

    char *tempListOfFunctionsExtracted; // Create NeedFunctionHeader.c to vein functions declaration
    tempListOfFunctionsExtracted = (char *) malloc(500 * sizeof(char));
    sprintf(tempListOfFunctionsExtracted, "%stemp_list_of_functions_extracted.out", TempVeinDirectory);

    /* Read list of functions already extracted*/
    ListOfString *ListOfFunctionsExtracted = readListOfStringFromFile(tempListOfFunctionsExtracted);
    if (ListOfFunctionsExtracted == NULL) {
        createFile(sourceOutputFile);
    }

    char *tempListOfTargetFunctionPath; // Create list of functions target
    tempListOfTargetFunctionPath = (char *) malloc(500 * sizeof(char));
    sprintf(tempListOfTargetFunctionPath, "%stemp_list_vein_function_files.out", TempVeinDirectory);

    ListOfString *ListOfTargetFunctionsFiles = readListOfStringFromFile(tempListOfTargetFunctionPath);

    int countFunction = 1;
    printf("[TXL] MultiFilesExtraction.x: Extracting functions in vein...\n");
    while (ListOfTargetFunctionsFiles) {
        if (!searchStringInListOfStrings(ListOfFunctionsExtracted, ListOfTargetFunctionsFiles->el)) {
            printf("\t[%d] %s", countFunction, ListOfTargetFunctionsFiles->el);
            addAStringsInTheFile(ListOfTargetFunctionsFiles->el, tempCurrentTargetFunctionPath);
            extractVeinFunctions(sourceOutputFile, tempCurrentTargetFunctionPath, graftSourceCodeFile,
                                 donorSourceFileFolder,
                                 transplantWorkFolderMainThread, TXLToolsPath,
                                 TXLTemporaryFolder, TXLTemporaryFolder, TXLTemporaryMultiFileFolder);
            /* Add function in list functions extracted ----------------------------*/
            addNewString(&ListOfFunctionsExtracted, ListOfTargetFunctionsFiles->el);
            /* Add function in file with list of functions extracted ----------------------------*/
            addAStringsInTheEndFile(ListOfTargetFunctionsFiles->el, tempListOfFunctionsExtracted);
            countFunction++;
        }
        ListOfTargetFunctionsFiles = ListOfTargetFunctionsFiles->next;
    }
#endif
///#endif

#ifdef CONSTRUCT_GRAFT_SKELETON
    /* remove all LOCs for which the called function were not specified by the user for transplant */
    char *FinalSkeletonOutput = (char *) malloc(100 * sizeof(char));
    sprintf(FinalSkeletonOutput, "%stemp_final_skeleton_output.out", TXLTemporaryFolder);

    SymbolTable *finalGraftSymbolTable = NULL; // create Graft skeleton
    *ListOfMappingsFromCurrentDonor = createGraftSkeleton(modifiedFunctionLOCs,
                                                          skeletonInstantiationMappings, TXLToolsPath, SkeletonFile,
                                                          CurrentExistingMappings, TXLTemporaryFolder,
                                                          HostSymbolTableFile,
                                                          &finalGraftSymbolTable, &(*ListOfDependenciesForStatements),
                                                          reverseCallGraph, TXLTemporaryFolder);

    /* Construct final Skeleton */
    *MappingCandidatesForGP = createMappingCandidateFromSymbolTablesAndMappings(
            finalGraftSymbolTable, HostSymbolTable,
            *ListOfMappingsFromCurrentDonor);

    *ListOfNeededFunctionsForAllLOCs = removeUnwantedFunctionsAndReturnCallDependencies(SkeletonFile,
                                                                                        FinalSkeletonOutput,
                                                                                        *ListOfDependenciesForStatements,
                                                                                        outputDefinedFunctions,
                                                                                        TXLTemporaryFolder);

    /* Read final list of skeleton source code from temp_final_skeleton_output.out */
    ///sleep(30);
    ListOfString *finalListOfSkeletonSourceCode = readListOfStringFromFile(
            FinalSkeletonOutput);

    ListOfString *interface_for_ind_instantiation = readListOfStringFromFile(skeletonInterfaceHeaderFileOutput);
    while (interface_for_ind_instantiation) {
        if(strstr(interface_for_ind_instantiation->el, "void")) break;
            interface_for_ind_instantiation = interface_for_ind_instantiation->next;
    }
    if(interface_for_ind_instantiation==NULL) {
        removeLastString(&finalListOfSkeletonSourceCode);
        addNewString(&finalListOfSkeletonSourceCode, RETURN_MARKER);
        addNewString(&finalListOfSkeletonSourceCode, "\n}");
    }
        //replaceOneLineInALIst(&interfaceContent, "__INTERFACE_FUNCTION", "\t//__INTERFACE_FUNCTION\n");
    printAListOfStrings(finalListOfSkeletonSourceCode, FinalSkeletonOutput);
#endif

    /* MODULE: GENERATE_SYMBOL_TABLE_FILE_FROM_DECLARATIONS -----------------------*/
	*FinalDeclSymbolTable = GenerateDeclarationsSymbolTable(
			finalListOfSkeletonSourceCode, *ListOfDependenciesForStatements,
			HostSymbolTable, TXLTemporaryFolder);

	*finalHostSymbolTable = HostSymbolTable;

	freeSymbolTableMemory();
	addMissingLabels(finalListOfSkeletonSourceCode, outputFileLabels);


    ///addReturnMark(&finalListOfSkeletonSourceCode);
   /// printAListOfStrings(finalListOfSkeletonSourceCode, FinalSkeletonOutput);

    return finalListOfSkeletonSourceCode;
}

void extractStmOrCompoundMarkers(char * Skeleton, char * outputFile,
		char * TXLProgsPath, char * outputFileAbstractMarkers) {
	char * commandTXL;
	commandTXL = (char *) malloc(5000 * sizeof(char));
	printf("\t[TXL] MutationCandidateExtractor.x >> Mutation Candidate Extractor\n");
	sprintf(commandTXL, "%sMutationCandidateExtractor.x %s %s %s %s",
			TXLProgsPath, Skeleton, outputFile, outputFileAbstractMarkers,
			ConsoleNullOutput);
	int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR! sMutationCandidateExtractor.x\n");
		system("open ErrorFile.out");
		system(1);
	}
#ifdef DEBUGING
	else
        printf("\t\t|>> temp_markers_for_abstract_vars.out\n");
#endif
	free(commandTXL);
}

void extractAllLineMarkersMarkers(char * Skeleton, char * outputFile,
		char * TXLProgsPath) {
    printf("\tExtract all line markers\n");

	char * commandTXL;
	commandTXL = (char *) malloc(5000 * sizeof(char));
    printf("\t\t[TXL] AllLineMarkersExtractor.x\n");
	sprintf(commandTXL, "%sAllLineMarkersExtractor.x %s %s %s", TXLProgsPath,
			Skeleton, outputFile, ConsoleNullOutput);
	int status = system(commandTXL);
	if (status != 0) {
		printf("ERROR! AllLineMarkersExtractor.x\n");
		system("open ErrorFile.out");
		exit(1);
	}
#ifdef DEBUGING
	else
        printf("\t\t\t|>> temp_file_of_line_markers.out\n");
#endif
	free(commandTXL);
}

ListOfString * createTheListOfAllMarkers(ListOfString * SkeletonSourceCode,
		char * TXLTemporaryFolder) {
    printf("[AUTOSCALPEL] Creating the list of all markers\n");
	//char * outputFileAbstractMarkers;
	//outputFileAbstractMarkers = (char *) malloc(500 * sizeof (char));
	//sprintf(outputFileAbstractMarkers, "%stemp_markers_for_abstract_vars.out", TXLTemporaryFolder);

	char * skeletonTemporaryFile;
	skeletonTemporaryFile = (char *) malloc(5000 * sizeof(char));
	sprintf(skeletonTemporaryFile,
			"%stemp_skeleton_for_mutation_candidates.out", TXLTemporaryFolder);

	printAListOfStrings(SkeletonSourceCode, skeletonTemporaryFile);
	char * tempListOfMarkers;
	tempListOfMarkers = (char *) malloc(5000 * sizeof(char));
	sprintf(tempListOfMarkers, "%stemp_file_of_line_markers.out",
			TXLTemporaryFolder);
	extractAllLineMarkersMarkers(skeletonTemporaryFile, tempListOfMarkers,
			TXLToolsPath);

	ListOfString * TempListOfStrings = returnListOfStringFromMarkersFile(
			tempListOfMarkers);

	//maybe here output also the list of abstract markers

	free(tempListOfMarkers);
	return TempListOfStrings;
}

ArrayOfStrings createArrayOfLineMutationCandidates(
		ListOfString * SkeletonSourceCode,
		ListOfString ** MarkersForLineWithAbstract, char * TXLTemporaryFolder) {
    printf("[AUTOSCALPEL] Create array of line mutation candidates\n");

	char * outputFileAbstractMarkers = (char *) malloc(100 * sizeof(char));
	sprintf(outputFileAbstractMarkers, "%stemp_markers_for_abstract_vars.out", TXLTemporaryFolder);

	char * skeletonTemporaryFile = (char *) malloc(100 * sizeof(char));
	sprintf(skeletonTemporaryFile, "%stemp_skeleton_for_mutation_candidates.out", TXLTemporaryFolder);
#ifdef DEBUGING
	printf("\t|>> temp_skeleton_for_mutation_candidates.out\n");
#endif
	printAListOfStrings(SkeletonSourceCode, skeletonTemporaryFile);

	char * tempListOfMarkers = (char *) malloc(100 * sizeof(char));
	sprintf(tempListOfMarkers, "%stemp_file_of_line_markers.out", TXLTemporaryFolder);
#if !defined(FAST_RUNNING)
	extractStmOrCompoundMarkers(skeletonTemporaryFile, tempListOfMarkers,
			TXLToolsPath, outputFileAbstractMarkers);
#endif
	ListOfString * TempListOfStrings = returnListOfStringFromMarkersFile(
			tempListOfMarkers);

	*MarkersForLineWithAbstract = returnListOfStringFromMarkersFile(
			outputFileAbstractMarkers);

	int numberOfElements = countElementsInListOfString(TempListOfStrings);
#ifdef DEBUGING
	printf("\tThe number of statements and compounds mapped to GP handle: %d\n",numberOfElements );
#endif
	/* Move elements to the array */
	char ** arrayOfStrings;
	arrayOfStrings = (char **) malloc(numberOfElements * sizeof(char *));
	for (int i = 0; i < numberOfElements; i++) {
		arrayOfStrings[i] = (char *) malloc(100 * sizeof(char));
	}
	int count = 0;
	ArrayOfStrings arrayOfMarkers;
	arrayOfMarkers.count = numberOfElements;
	arrayOfMarkers.array = arrayOfStrings;
	ListOfString * auxListOfStr = TempListOfStrings;
	while (auxListOfStr) {
		strcpy(arrayOfMarkers.array[count], auxListOfStr->el);
		count++;
		auxListOfStr = auxListOfStr->next;
	}
	arrayOfMarkers.count = count;

	freeListOfStrings(&TempListOfStrings);
	free(outputFileAbstractMarkers);
	free(skeletonTemporaryFile);
	free(tempListOfMarkers);

	return arrayOfMarkers;
}

ArrayOfStrings copyArrayOfStrings(ArrayOfStrings initial) {
	ArrayOfStrings newArrayOfStrings;
	newArrayOfStrings.count = initial.count;
	char ** arrayOfStrings;
	arrayOfStrings = (char **) malloc(initial.count * sizeof(char *));
	for (int i = 0; i < initial.count; i++) {
		arrayOfStrings[i] = (char *) malloc(100 * sizeof(char));
		strcpy(arrayOfStrings[i], initial.array[i]);
	}
	newArrayOfStrings.array = arrayOfStrings;
	return newArrayOfStrings;
}

