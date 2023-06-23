/* 
 * File:   FunctionExtractor.c
 * Author: ---
 *
 * Created on 12 Jun 2017, 23:20
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "folderContent.h"
#include "GenTrans.h"
#include "Utils.h"
#include <errno.h>
#include "CallGraph.h"
#include "ListOfFunctionForGraph.h"
#include "IndividualInstantiator.h"
#include "FunctionExtractor.h"

ListOfString * getFormattedListOfFunctionsSourceFile(ListOfFunctionForGraph * ListOfFunctionSourceFile, char * tempSourceFilesFolderPath){
    ListOfString * ListOfFunctionsTargetFiles = NULL;
    char *formattedCurrentFile;
    char *formattedCurrentFunction;
    formattedCurrentFile = (char *) malloc(500 * sizeof(char));
    formattedCurrentFunction = (char *) malloc(500 * sizeof(char));

    while (ListOfFunctionSourceFile) {
        char * sourceFile = NULL;
        sourceFile = constructSubDirectoryPath(donorSourceFileFolder, ListOfFunctionSourceFile->sourceFile);
        sprintf(formattedCurrentFunction, "\"%s\" \"%s%s\"\n", ListOfFunctionSourceFile->functionName,
        tempSourceFilesFolderPath, sourceFile);
        sprintf(formattedCurrentFile, "%s%s", tempSourceFilesFolderPath, sourceFile);
        fflush(stdout);
        addNewString(&ListOfFunctionsTargetFiles,formattedCurrentFunction);
        ListOfFunctionSourceFile = ListOfFunctionSourceFile->next;
    }
    return ListOfFunctionsTargetFiles;
}

ListOfString * getFormattedListOfExtractedFilesFullPath(ListOfFunctionForGraph * ListOfFunctionSourceFile, char * tempSourceFilesFolderPath) {
    ListOfString * ListOfFilesExtractedFullPath = NULL;
    char *formattedCurrentFile = (char *) malloc(500 * sizeof(char));
    char *formattedCurrentFunction = (char *) malloc(500 * sizeof(char));

    while (ListOfFunctionSourceFile) {
        sprintf(formattedCurrentFunction, "\"%s\" \"%s%s\"\n", ListOfFunctionSourceFile->functionName,
                tempSourceFilesFolderPath, ListOfFunctionSourceFile->sourceFile);
        sprintf(formattedCurrentFile, "%s%s", tempSourceFilesFolderPath, ListOfFunctionSourceFile->sourceFile);
        fflush(stdout);
        if (!searchStringInListOfStrings(ListOfFilesExtractedFullPath, formattedCurrentFile)) {
            addNewString(&ListOfFilesExtractedFullPath, formattedCurrentFile);
        }
        ListOfFunctionSourceFile = ListOfFunctionSourceFile->next;
    }
    free(formattedCurrentFile);
    free(formattedCurrentFunction);
    return ListOfFilesExtractedFullPath;
}

ListOfString * fixFileFullPath(ListOfString * listOfFilesExtracted, char * tempSourceFilesFolderPath){

    ListOfString *ListOfFilesFullPath = NULL;
    char *formattedCurrentFile = (char *) malloc(500 * sizeof(char));;
    while(listOfFilesExtracted){
        sprintf(formattedCurrentFile, "%s%s", tempSourceFilesFolderPath, listOfFilesExtracted->el);
        addNewString(&ListOfFilesFullPath,  formattedCurrentFile);
        listOfFilesExtracted = listOfFilesExtracted->next;
    }
    return ListOfFilesFullPath;
}

void extractFunction(char * txlProgsPath, char * graftFileFullPath, char * headerOutputFile,
                     char * currentFunctionExtracted, char * tempCurrentTargetFunctionPath, char * sourceFiles, char * headerFiles,
                     char * listOfNeededHeadFilesForCoreGraftFunction, char * TXLToolsPath,
                     char * ConsoleStderrOutput){

    /* Set TXL path */
    char *ifDefProgramPath = (char *) malloc(100 * sizeof(char *));
  //  if (!strcmp(TXLToolsPath, "./")) {
     //   ifDefProgramPath = (char *) malloc((strlen(TXLToolsPath) + 10) * sizeof(char));
     ///   sprintf(ifDefProgramPath, "%sifdef.x", TXLToolsPath);
     strcpy(ifDefProgramPath, "ifdef.x");

    /*} else {
        ifDefProgramPath = (char *) malloc(10 * sizeof(char));
        sprintf(ifDefProgramPath, "./ifdef.x");
    }*/

    /* Execute TXL multifile extractor */
    char *command = (char *) malloc(1000 * sizeof(char *));
    sprintf(command, "./%smultiplFiles.x %s %s %s %s %s %s %s %s %s%s %s",
        txlProgsPath, graftFileFullPath, graftFileFullPath, headerOutputFile,
        currentFunctionExtracted, tempCurrentTargetFunctionPath, sourceFiles, headerFiles,
        listOfNeededHeadFilesForCoreGraftFunction, TXLToolsPath, ifDefProgramPath,
        ConsoleStderrOutput);

    int commandStatus = system(command);
    if (commandStatus != 0) {
        printf(stderr, "ERROR: %s\n\tExtracting function", strerror(errno));
        printf("\t%s\n", command);
        system("open ErrorFile.out");
        //system("open -a \"Sublime Text\" ErrorFile.out");
        exit(1);
    }
}
/*
void addNewFunctionDeclaration(ListOfFunctionDeclaration ** head, char * declaration, char * file) {
    ListOfFunctionDeclaration * newEl = (ListOfFunctionDeclaration *) malloc(1 * sizeof (ListOfFunctionDeclaration));
    newEl->declaration = (char *) malloc((strlen(declaration) + 2) * sizeof (char *));
    newEl->file = (char *) malloc((strlen(file) + 2) * sizeof (char *));
    strcpy(newEl->declaration, declaration);
    strcpy(newEl->file, file);
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfFunctionDeclaration * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }

}
*/
void addNewFunctionDeclarationList(ListOfFunctionDeclaration ** head, ListOfString * listOfDeclaration, char * file ){
    ListOfFunctionDeclaration * newEl = (ListOfFunctionDeclaration *) malloc(1 * sizeof (ListOfFunctionDeclaration));
    newEl->file = (char *) malloc((strlen(file) + 2) * sizeof (char *));
    strcpy(newEl->file,file);
    newEl->listOfDeclaration = copyCompleteListOfString(listOfDeclaration);

    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfFunctionDeclaration * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }

}


void extractFunctionDeclarationFromFile( ListOfFunctionDeclaration ** ListOfFunctionDeclarations ){
    /* Set path TempCallerGraphs */

    char *tempFunctionFileDeclarationFromHeaders = (char *) malloc(100 * sizeof(char));
    sprintf(tempFunctionFileDeclarationFromHeaders, "%stemp_list_of_js_files.out", TXLTemporaryMultiFileFolder);
    char * jsDirectory = (char *) malloc(100 * sizeof(char));
    sprintf(jsDirectory, "%sTempDoxygenAutoScalpel/JS/",DoxygenFolder);
    fflush(stdout);
    FILE *fSourceFileName = fopen(tempFunctionFileDeclarationFromHeaders, "w");
    readFilesFromDirWithFormat(jsDirectory, fSourceFileName, ".j");
    fclose(fSourceFileName);

    ListOfString * listOfFile = readListOfStringFromFile(tempFunctionFileDeclarationFromHeaders);
    ListOfString * listOfDeclarations = NULL;
    ListOfString * formattedListOfDeclarations = NULL;

    char * currentFile = (char *) malloc(200 * sizeof(char));
    char * currentDeclaration = (char *) malloc(200 * sizeof(char));;
    while(listOfFile){
        if(strstr(listOfFile->el,"_8c.js") || strstr(listOfFile->el,"_8h.js")) {
            strcpy(currentFile, readSubstring("\"", listOfFile->el, "\""));
            listOfDeclarations = readListOfStringFromFile(currentFile);
            if(strstr(currentFile,"_8c.js")) {
                strcpy(currentFile, readSubstring(jsDirectory, listOfFile->el, "_8c"));
                strcat(currentFile,".c");
            }else {
                strcpy(currentFile, readSubstring(jsDirectory, listOfFile->el, "_8h"));
                strcat(currentFile,".h");
            }
            while (listOfDeclarations) {
                if (strstr(listOfDeclarations->el, "[ \"") && strstr(listOfDeclarations->el, "\"")) {
                    strcpy(currentDeclaration, readSubstring("[ \"", listOfDeclarations->el, "\""));
                    addNewString(&formattedListOfDeclarations, currentDeclaration);
                }
                listOfDeclarations = listOfDeclarations->next;
            }

            addNewFunctionDeclarationList(ListOfFunctionDeclarations, formattedListOfDeclarations,currentFile);
            freeListOfStrings(&formattedListOfDeclarations);
            fflush(stdout);
        }
        freeListOfStrings(&listOfDeclarations);
        listOfFile = listOfFile->next;
    }
    removeAFileFromADirectory(tempFunctionFileDeclarationFromHeaders);
    free(tempFunctionFileDeclarationFromHeaders);
    freeListOfStrings(&listOfFile);
}
void extractFunctionality(char * targetFunction, char * targetFileFullPath,
                          char * tempSourceFilesFolderPath, char * txlProgsPath, char * tempFolder, char * TXLTempMultiFiles) {
    if(strstr(targetFunction,  "uc_len"))
        printf("pare aqui");

    ListOfFunctionDeclaration * ListOfFunctionDeclarations = NULL;
    extractFunctionDeclarationFromFile(&ListOfFunctionDeclarations);
    ListOfFunctionDeclaration * auxListOfFunctionDeclarations = ListOfFunctionDeclarations;
    ListOfString * LisfOfAllFunctionDeclarationInHeaders = NULL;
    while(auxListOfFunctionDeclarations){
        if(strstr(auxListOfFunctionDeclarations->file,".h"))
            addListOfStringToExistingOne(&LisfOfAllFunctionDeclarationInHeaders, auxListOfFunctionDeclarations->listOfDeclaration);
        auxListOfFunctionDeclarations = auxListOfFunctionDeclarations->next;
    }
    fflush(stdout);
    int rootFunctionCallGraph = 1;

    /* Parser to read call graph from function */
    char * targetFile = strrchr(targetFileFullPath, '/');
    targetFile++;
    ListOfFunctionForGraph *ListOfFunctionSourceFileGraph = readACallGraphAsList(targetFunction);
    if(ListOfFunctionSourceFileGraph == NULL || strcmp(targetFile, ListOfFunctionSourceFileGraph->sourceFile)) { // There is no call graph or the found call graph does not match to the current function
        ListOfFunctionSourceFileGraph = NULL;
        addNewFunctionForGraph(&ListOfFunctionSourceFileGraph, targetFunction, targetFile);
    }
    //--------------------

#ifdef DEBUGING
    if(targetFileFullPath){
        char * targetFile = strrchr(targetFileFullPath, '/');
        printf("\tFunctionName: %s File: %s\n", targetFunction, targetFile);
    }
    else
        printf("\tFunctionName: %s File: %s\n", targetFunction, ListOfFunctionSourceFileGraph->sourceFile);
#endif
    char *tempCurrentTargetFunctionPath = (char *) malloc(100 * sizeof(char));
    sprintf(tempCurrentTargetFunctionPath, "%stemp_list_of_functions_target.out", TXLTempMultiFiles);

    /* Create/Open file with a list of functions files target if it does not exist yet */
    char *listOfFunctionsFilesExtractedFullPath = (char *) malloc(100 * sizeof(char));
    sprintf(listOfFunctionsFilesExtractedFullPath, "%slist_of_functions_file_target.out", TXLTempMultiFiles);
    openFileInAppendMode(listOfFunctionsFilesExtractedFullPath);

    char *headerOutputFile;
    headerOutputFile = (char *) malloc(100 * sizeof(char));
    sprintf(headerOutputFile, "%sNeededFunctionsHeader.h", tempFolder);

    char *fSoureFilesExtracted = (char *) malloc(100 * sizeof(char));
    sprintf(fSoureFilesExtracted, "%stemp_list_of_source_files_extracted.out", TXLTempMultiFiles);
    if(file_exists(fSoureFilesExtracted))
        createFile(fSoureFilesExtracted);

    char * currentFunctionExtracted = (char *) malloc(100 * sizeof(char));
    sprintf(currentFunctionExtracted, "%scurrentFunctionExtracted.c", TXLTemporaryFolderMainThread);

    char * currentHeaderOutputFile = (char *) malloc(100 * sizeof(char));
    sprintf(currentHeaderOutputFile, "%scurrentHeaderOutputFile.h", TXLTemporaryFolderMainThread);

    char * sourceFiles = (char *) malloc(100 * sizeof(char));
    sprintf(sourceFiles, "%ssourceFilesInDonor.out", TXLTempMultiFiles);

    char * headerFiles = (char *) malloc(100 * sizeof(char));
    sprintf(headerFiles, "%sheaderFilesInDonor.out", TXLTempMultiFiles);

    char *listOfNeededHeadFilesForCoreGraftFunction = (char *) malloc(100 * sizeof(char));
    sprintf(listOfNeededHeadFilesForCoreGraftFunction, "%stemp_list_of_header_files.out", TXLTempMultiFiles);
    fflush(stdout);

    int countNumberOfFunctions = 1;

    ListOfString * ListOfFilesExtracted = readListOfStringFromFileAsWords(fSoureFilesExtracted);
    ListOfString * ListOfFunctionsExtracted = readListOfStringFromFile(listOfFunctionsFilesExtractedFullPath);
    ListOfString * ListOfFunctionsTargetFiles = getFormattedListOfFunctionsSourceFile(ListOfFunctionSourceFileGraph, tempSourceFilesFolderPath);
    ListOfFunctionForGraph *auxListOfFunctionSourceFile = ListOfFunctionSourceFileGraph; //Initiate required file for Multifile extraction
    ListOfFunctionSourceFile * ListOfDuplicatedFunctions = NULL;
    /* Read all function in donor as a list of function source file */
    ListOfFunctionSourceFile * AllFunctionSourceFileInDonor = NULL;
    char * AllDefinedFunctionsInDonorPath = (char *) malloc(100 * sizeof(char));;
    sprintf(AllDefinedFunctionsInDonorPath, "%stemp_all_defined_functions_int_donor.out",
            TXLTemporaryFolderMainThread);
    AllFunctionSourceFileInDonor = readAllFunctionSourceFileFromAllDefinitionInDonor(AllDefinedFunctionsInDonorPath);

    char * sourceOutputFile = (char *) malloc(500 * sizeof(char));
    char *listOfNeededHeadFunctionDeclaration = (char *) malloc(100 * sizeof(char));
    ListOfString * functionAsAList;
    printf("\t[TXL] multiFilesExtraction.x >> MultiFile extraction\n");
 ///   ListOfFunctionDeclaration * ListOfFuncDeclaration = NULL;
    while(auxListOfFunctionSourceFile) {
        char * functionDeclaration = NULL;
        char * sourceFile = NULL;
        char *currentFunctionSourceFile = ListOfFunctionsTargetFiles->el;
        char *currentFunctionName =  auxListOfFunctionSourceFile->functionName;
        if(strstr(currentFunctionName,  "uc_len"))
            printf("pare aqui");
        if(!searchOccurrenceOfStringInListOfStringsUsingSTRSTR(ListOfFunctionsExtracted,currentFunctionSourceFile)){
            sourceFile = constructSubDirectoryPath(donorSourceFileFolder, auxListOfFunctionSourceFile->sourceFile);
            sprintf(sourceOutputFile, "%s%s", TXLTempMultiFiles, sourceFile);
            openFileInAppendMode(sourceOutputFile); // Create target c file if it does not exist

            clearFile(currentFunctionExtracted); // Create file to inset current function
            addAStringsInTheFile(currentFunctionSourceFile, tempCurrentTargetFunctionPath); // Add current function file path
            createFile(currentHeaderOutputFile);
            /* Extract function */
            fflush(stdout);
            printf("\t\tFunction[%d]: %s from file: %s\n", countNumberOfFunctions, currentFunctionName,  auxListOfFunctionSourceFile->sourceFile);
            extractFunction(txlProgsPath, targetFileFullPath, currentHeaderOutputFile,
                        currentFunctionExtracted, tempCurrentTargetFunctionPath, sourceFiles, headerFiles,
                        listOfNeededHeadFilesForCoreGraftFunction, TXLToolsPath, ConsoleStderrOutput);

            functionDeclaration = readAStringFromFile(currentHeaderOutputFile);
        /* Insert function prototype if it is a root of the current call graph */
           /// if(rootFunctionCallGraph == 1) {
            if(!strcmp(sourceFile, donorEntryFile)) {
                //Replace static in the function prototype
                functionAsAList = readListOfStringFromFile(currentFunctionExtracted);
                if (strstr(functionDeclaration, "static")) {
                    /* Comment static declaration */
                  //  functionDeclaration = replace_str(functionDeclaration, "static", "extern");
                    addAStringsInTheFile(replace_str(functionDeclaration, "static", "extern"), currentHeaderOutputFile);
                    addLocsFromSourceToDestination(headerOutputFile,currentHeaderOutputFile, TXLToolsPath);
                    /* remove static declaration from function signature */
                    functionAsAList->el = replace_str(functionAsAList->el, "static", "/*static*/");
                    printAListOfStrings(functionAsAList, currentFunctionExtracted);

                } else{/* add extern in function definition before insert it into headerOutputFile */
                    char * functionDefinitionWithExtern = (char *) malloc(500 * sizeof(char));
                    sprintf(functionDefinitionWithExtern, "extern %s", functionDeclaration);
                    addAStringsInTheFile(functionDefinitionWithExtern, currentHeaderOutputFile);

                }

                ///addLocsFromSourceToDestination(headerOutputFile, currentHeaderOutputFile, TXLToolsPath);
                rootFunctionCallGraph = 0; // To ensure that only the root of current call graph will be inserted into interfaceHeader
                /* add current function extracted in the begging of the target file*/
            }

            addLocsFromSourceToDestination(sourceOutputFile, currentFunctionExtracted, TXLToolsPath);
        //    char *functionDeclaration = readAStringFromFile(currentHeaderOutputFile);
           /// if (strstr(functionDeclaration, "static")) {
                //addLocsFromSourceToDestination(sourceOutputFile, currentHeaderOutputFile, TXLToolsPath);
             ///   addNewFunctionDeclaration(&ListOfFuncDeclaration,functionDeclaration, sourceOutputFile);
          ///  }


            sprintf(listOfNeededHeadFunctionDeclaration, "%s%sDEC", TXLTempMultiFiles, sourceFile);


            char *FormattedListOfDuplicatatedFunctions = (char *) malloc(200 * sizeof(char));

            if (!searchStringInListOfStrings(ListOfFilesExtracted, sourceFile)) {
                addNewString(&ListOfFilesExtracted, sourceFile);
                printAListOfStringsNL(ListOfFilesExtracted, fSoureFilesExtracted);
                createFile(listOfNeededHeadFunctionDeclaration);
            }
/* TODO POST-EXPERIMENT
            if(strstr(functionDeclaration, "static") && searchStringInListOfStrings(LisfOfAllFunctionDeclarationInHeaders, currentFunctionName) ) {
                ListOfDuplicatedFunctions = searchFunctionInListOfFunctionsSourceFileFromFunction (AllFunctionSourceFileInDonor, currentFunctionName);
               if(ListOfDuplicatedFunctions->next) {
                   ListOfFunctionsExtracted = readListOfStringFromFile(listOfFunctionsFilesExtractedFullPath);
                   while (ListOfDuplicatedFunctions && !searchOccurrenceOfStringInListOfStrings(ListOfFunctionsExtracted,currentFunctionSourceFile)) {
                       sprintf(FormattedListOfDuplicatatedFunctions, "\"%s\" \"%s\"\n", ListOfDuplicatedFunctions->functionName, ListOfDuplicatedFunctions->sourceFile);
                       if (strcmp(FormattedListOfDuplicatatedFunctions, currentFunctionSourceFile))
                           extractFunctionality(ListOfDuplicatedFunctions->functionName, ListOfDuplicatedFunctions->sourceFile,
                                                donorSourceFileFolder, TXLToolsPath, TXLTemporaryFolderMainThread, TXLTemporaryMultiFileFolder);
                          /// addNewFunctionSourceFile(&ListOfDuplicatedFunctions, ListOfDuplicatedFunctions->functionName, ListOfDuplicatedFunctions->sourceFile);
                           ListOfDuplicatedFunctions = ListOfDuplicatedFunctions->next;
                   }
               }
              ///  addANewStringLNInTheEndFile(replace_str(functionDeclaration, "static", "/*static*//*"), listOfNeededHeadFunctionDeclaration); //Add function declaration in the file
              }*/

            if(strstr(functionDeclaration, "static"))
                addANewStringLNInTheEndFile(functionDeclaration, listOfNeededHeadFunctionDeclaration); //Add function declaration in the file if static*/

            /*Add file in NeededSourceCode.c */
            /*addLocsFromSourceToDestination(currentFunctionSourceFile, tempSourceCodeGlobalsContent, TXLToolsPath);*/
            ///    addLocsFromSourceToDestination(allFunctionsExtracted,sourceOutputFile, TXLToolsPath);

        } else {

       //     printf("\t\tFunction[%d]: %s from file: %s\n", countNumberOfFunctions,currentFunctionName, sourceFile);
        }
        addAStringsInTheEndFile(currentFunctionSourceFile, listOfFunctionsFilesExtractedFullPath);
        auxListOfFunctionSourceFile = auxListOfFunctionSourceFile->next;
        ListOfFunctionsTargetFiles = ListOfFunctionsTargetFiles->next;
        ListOfDuplicatedFunctions = NULL;
        countNumberOfFunctions++;
      ///  free(functionDeclaration);
    }
/*
    while(ListOfDuplicatedFunctions){
        extractFunctionality(ListOfDuplicatedFunctions->functionName, ListOfDuplicatedFunctions->sourceFile,
                             donorSourceFileFolder,
                             TXLToolsPath, TXLTemporaryFolderMainThread, TXLTemporaryMultiFileFolder);

        ListOfDuplicatedFunctions = ListOfDuplicatedFunctions->next;
    }
*/
    //Add static functions declaration
    /*char * currentDeclarationOutputFile = (char *) malloc(100 * sizeof(char));
    sprintf(currentDeclarationOutputFile, "%scurrentDeclarationOutputFile.c", TXLTemporaryFolderMainThread);
    while(ListOfFuncDeclaration){
        addAStringsInTheFile(ListOfFuncDeclaration->declaration,currentDeclarationOutputFile);
        addLocsFromSourceToDestination(ListOfFuncDeclaration->file, currentDeclarationOutputFile, TXLToolsPath);
        ListOfFuncDeclaration = ListOfFuncDeclaration->next;
    }
    removeAFileFromADirectory(currentDeclarationOutputFile); // Delete temporary file currentFunctionExtracted.c*/
  ///  removeAFileFromADirectory(currentFunctionExtracted); // Delete temporary file currentFunctionExtracted.c

    // Extract function declaration
    ListOfString * ListOfFunctionsFileExtracted =  readListOfStringFromFile(listOfFunctionsFilesExtractedFullPath);

    while(ListOfFunctionsFileExtracted){

        ListOfFunctionsFileExtracted = ListOfFunctionsFileExtracted->next;
    }

    /* Create sourceContentFilesTarget with formatted file full path */
    char *sourceFilesPath = (char *) malloc(100 * sizeof(char));
    sprintf(sourceFilesPath, "%ssourceContentFilesTarget.out", TXLTemporaryFolderMainThread);

    ListOfString * ListOfFilesExtractedFullPath = getFormattedListOfExtractedFilesFullPath(ListOfFunctionSourceFileGraph, tempSourceFilesFolderPath);
   /* ListOfString * ListOfSourceFilesExtractedFullPath = fixFileFullPath(listOfFilesExtracted,tempSourceFilesFolderPath);
    addQuotesInAList(&ListOfSourceFilesExtractedFullPath);
    ListOfString * listOfDonorHeaderFiles = readListOfStringFromFile(headerFiles);
   // ListOfString * ListOfHeaderFilesExtractedFullPath = fixFileFullPath(listOfDonorHeaderFiles,tempSourceFilesFolderPath);

    ListOfString * AllSourceHeaderFilesExtracted = concatTwoListOfStrings(ListOfSourceFilesExtractedFullPath, listOfDonorHeaderFiles);
    printAListOfStringsExstingFileNL(AllSourceHeaderFilesExtracted, sourceFilesPath);*/

    ListOfString *auxListOfFiles = ListOfFilesExtractedFullPath;
    ListOfString *ListOfFilesFormatted = NULL;
    char *formattedCurrentFile =  (char *) malloc(500 * sizeof(char));
    while(auxListOfFiles){
        sprintf(formattedCurrentFile, "\"%s\"", auxListOfFiles->el);
        addNewString(&ListOfFilesFormatted,  formattedCurrentFile);
        auxListOfFiles = auxListOfFiles->next;
    }


    /* Get all header filed required by extracted files
    auxListOfFiles = ListOfFilesExtractedFullPath;
    char *outputHeaderFileList[400];
    sprintf(outputHeaderFileList, "%soutputHeaderFileList.out", tempSourceFilesFolderPath);

    char * gccCommand;
    char *currentFile;
    gccCommand = (char *) malloc(500 * sizeof(char *));
    currentFile = (char *) malloc(400 * sizeof(char));

    ListOfString * ListOfFilesForHeader = NULL;
    while(auxListOfFiles) {
        sprintf(gccCommand, "gcc -MM %s > %s", auxListOfFiles->el, outputHeaderFileList);
        int status = system(gccCommand);
        ListOfString *tempListOffiles = readListOfStringFromFileAsWords(outputHeaderFileList);
        while (tempListOffiles) {
            strcpy(currentFile, tempListOffiles->el);
            if (strstr(currentFile, ".h") != NULL) {
                if(!searchOccurrenceOfStringInListOfStringsUsingSTRSTR(ListOfFilesForHeader,currentFile)){
                    addNewString(&ListOfFilesForHeader, currentFile);
                }
            }
            tempListOffiles = tempListOffiles->next;
        }
        auxListOfFiles = auxListOfFiles->next;
    }*/

    /* Print all header files required */
    ListOfString * listOfDonorHeaderFiles = readListOfStringFromFile(headerFiles);
    while(listOfDonorHeaderFiles) {
        sprintf(formattedCurrentFile, "%s", listOfDonorHeaderFiles->el);
        strtok(formattedCurrentFile, "\n");
        addNewString(&ListOfFilesFormatted,  formattedCurrentFile);
        listOfDonorHeaderFiles = listOfDonorHeaderFiles->next;
    }
    printAListOfStringsExstingFileNL(ListOfFilesFormatted, sourceFilesPath);

    /*LOS Creating file temp_all_source_files_target.out */
    /*char *tempAllSourceFilesTargetPath = (char *) malloc(500 * sizeof(char));
    sprintf(tempAllSourceFilesTargetPath, "%stemp_all_source_files_target.out", TXLTempMultiFiles);
    ListOfString * tempAllSourceFilesExtracted = readListOfStringFromFile(tempAllSourceFilesTargetPath);
    FILE *fSourceFiles = fopen(tempAllSourceFilesTargetPath, "a");
    auxListOfFiles = ListOfFilesExtractedFullPath;
    while (auxListOfFiles) {
        sprintf(formattedCurrentFile, "\"%s\"\n", auxListOfFiles->el);
        if(!searchStringInListOfStrings(tempAllSourceFilesExtracted,formattedCurrentFile)) {
            fprintf(fSourceFiles, "%s", formattedCurrentFile);
        }
        auxListOfFiles = auxListOfFiles->next;
    }
    fclose(fSourceFiles);*/

    //freeListOfStrings(&ListOfFilesForHeader);
    freeListOfFunctionSourceFile(&ListOfDuplicatedFunctions);
   /// freeListOfStrings(&AllFunctionSourceFileInDonor);
    freeListOfFunctionForGraph(&ListOfFunctionSourceFileGraph);
    freeListOfFunctionForGraph(&auxListOfFunctionSourceFile);
    free(listOfNeededHeadFilesForCoreGraftFunction);
    freeListOfStrings(&ListOfFilesExtracted);
    freeListOfStrings(&ListOfFilesExtractedFullPath);
    freeListOfStrings(&ListOfFunctionsTargetFiles);
    freeListOfStrings(&ListOfFunctionsExtracted);
    free(headerFiles);
  //  free(targetFile);
    free(formattedCurrentFile);
    free(fSoureFilesExtracted);
    free(tempCurrentTargetFunctionPath);
    free(listOfFunctionsFilesExtractedFullPath);
}
