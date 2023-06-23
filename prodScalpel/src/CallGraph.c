#include "CallGraph.h"
#include "ListOfString.h"
#include "GenTrans.h"

#include <stdio.h>
#include <stdlib.h>

//#include <malloc.h>
#include <string.h>
#include "ListOfFunctionForGraph.h"
#include <errno.h>
#include "Utils.h"
#include "folderContent.h"
#include <unistd.h>
#include <dirent.h>

#ifdef GENERATE_DONOR_CALL_AND_CALLED_GRAPHS
/* LOS rename file to function name in order to be used by callGraphParser
 * */

void renameDotFileToFunctionName(const char *doxyDirect, char * path, char * fileType){
    ListOfString *ListOfDotFiles = NULL;
    DIR *dr;
    struct dirent *dir;
    dr = opendir(path);
    if(dr) {
        while ((dir = readdir(dr)) != NULL)
            addNewString(&ListOfDotFiles, dir->d_name);

        closedir(dr);
    } else {
        printf("Could not open current directory");
        exit(1);
    }

    while (ListOfDotFiles) {
        if (strstr(ListOfDotFiles->el, fileType)){
            char * filePath;
            filePath = (char *) malloc(500 * sizeof(char));
            sprintf(filePath, "%s%s", path, ListOfDotFiles->el);
            FILE *fileStream = fopen(filePath, "r+");
            char * line;
            line = (char *) malloc(4000 * sizeof (char));
            char * functionName;

            if (fgets(line,300, fileStream)) {
                functionName = strstr(line, " ") + 2;
                /* Add file name */
                char *fileName = NULL;
                char * currentFileName = NULL;
                fileName = (char *) malloc(200 * sizeof(char));
                currentFileName = (char *) malloc(200 * sizeof(char));
                char *formattedFileName = (char *) malloc(200 * sizeof(char));
                strtok(line, "\n");
                fflush(stdout);
                strtok(functionName, "\"");

                if (strstr(filePath, "_8c")) {
                    strcpy(fileName, readSubstring(doxyDirect, filePath, "_8c"));
                    while (strstr(fileName, "__") != NULL) {
                        strcpy(currentFileName,fileName);
                        fileName = replace_str(currentFileName, "__", "_");
                    }
                    while (strstr(fileName, "_2") != NULL) {
                        strcpy(currentFileName, fileName);
                        fileName = replace_str(currentFileName, "_2", "/");
                    }
                        sprintf(formattedFileName, "%s SourceFile= %s.c\n{\n", line, fileName);
                } else
                    if (strstr(filePath, "_8h")){
                        strcpy(fileName, readSubstring(doxyDirect, filePath, "_8h"));

                        while (strstr(fileName, "__") != NULL) {
                            strcpy(currentFileName,fileName);
                            fileName = replace_str(currentFileName, "__", "_");
                        }
                        while (strstr(fileName, "_2") != NULL) {
                            fileName = replace_str(fileName, "_2", "/");
                            strcpy(currentFileName, fileName);
                        }
                        sprintf(formattedFileName, "%s SourceFile= %s.h\n{\n", line, fileName);
                        strcat(functionName,"_8h");
                    } else {
                        printf("%s\n", fileName);
                        printf("ERROR: Type file not recognised!\n");
                       /// exit(1); // TODO CHECK REQUIREMENT
                    }
             ///   if (strstr(fileName, "tputs"))
              ///      printf("tputs\n");

                    fseek(fileStream, 0, SEEK_SET);
                    fprintf(fileStream, "%s", formattedFileName);


                    strcat(functionName,fileType);
                    char * newFileName = (char *) malloc(500 * sizeof(char));;
                    sprintf(newFileName, "%s%s", path,functionName);
                    // printf("\tRenaming: %s\n", filePath);
                    int renameStatus = rename(filePath, newFileName);

                }
                fclose(fileStream);

            }
            ListOfDotFiles = ListOfDotFiles->next;
        }
}


void generateDoxyFile(char * doxyfileFolder, char * doxyfileName){

    char * DoxygenConfiguration = "Doxyfile_config";

    if(file_exists(DoxygenConfiguration)) {
             printf("ERROR: There is no Doxyfile_config in root folder. It is required to automatically generate the Doxyfile.");
             exit(1);
    }
    ListOfString * ListOfCoreFunctions = readListOfStringFromFile(DoxygenConfiguration);

    if(ListOfCoreFunctions) {
        char *outputDirectory = (char *) malloc(100 * sizeof (char));
        sprintf(outputDirectory, "OUTPUT_DIRECTORY       = \"../../../%s\"\n", doxyfileFolder);
        replaceOneLineInALIst(&ListOfCoreFunctions, "OUTPUT_DIRECTORY       =", outputDirectory);
        char *stripFromPath = (char *) malloc(100 * sizeof (char));
        sprintf(stripFromPath, "STRIP_FROM_PATH        = ../../../%s\n", donorSourceFileFolder);
        replaceOneLineInALIst(&ListOfCoreFunctions, "STRIP_FROM_PATH        =", stripFromPath);
        char *stripFromIncPath = (char *) malloc(100 * sizeof (char));
        sprintf(stripFromIncPath, "STRIP_FROM_INC_PATH    = ../%s\n", donorSourceFileFolder);
        replaceOneLineInALIst(&ListOfCoreFunctions, "STRIP_FROM_INC_PATH    =", stripFromIncPath);
        char *inputPath = (char *) malloc(100 * sizeof (char));
        sprintf(inputPath, "INPUT                  = \"../../../%s\"\n", donorSourceFileFolder);
        replaceOneLineInALIst(&ListOfCoreFunctions, "INPUT                  =", inputPath);
        char *includePath = (char *) malloc(100 * sizeof (char));
        sprintf(includePath, "INCLUDE_PATH           = ../../../%s\n", donorSourceFileFolder);
        replaceOneLineInALIst(&ListOfCoreFunctions, "INCLUDE_PATH           =", includePath);
        printAListOfStrings(ListOfCoreFunctions, doxyfileName);
    } else {
        printf("Doxyfile_config not found in the root directory!\n");
        exit(1);
    }
}

void generateCallAndCallerGraphs() {
    /* Set path Doxygen/html */
    char *TemporaryDoxygenAutoScalpelFolder = (char *) malloc((strlen(DoxygenFolder) + 30) * sizeof(char));
    sprintf(TemporaryDoxygenAutoScalpelFolder, "%sTempDoxygenAutoScalpel/", DoxygenFolder);
    if(!isDirectoryExists(TemporaryDoxygenAutoScalpelFolder))
         createADirectory(TemporaryDoxygenAutoScalpelFolder);

    /* Set path TempCallGraphs */
    char * tempDoxygenCallGraphDir = (char *) malloc((strlen(TemporaryDoxygenAutoScalpelFolder) + 21) * sizeof (char));
    sprintf(tempDoxygenCallGraphDir, "%sTempCallGraphs/", TemporaryDoxygenAutoScalpelFolder);
    fflush(stdout);

    /* Set path TempCallerGraphs */
    char * tempDoxygenCallerGraphDir = (char *) malloc((strlen(TemporaryDoxygenAutoScalpelFolder) + 21) * sizeof (char));
    sprintf(tempDoxygenCallerGraphDir, "%sTempCallerGraphs/",TemporaryDoxygenAutoScalpelFolder);
    fflush(stdout);

    /* Set path Doxygen/html */
    char * TemporaryDoxygenOutputFolder = NULL;
    TemporaryDoxygenOutputFolder = (char *) malloc(200 * sizeof (char));
    sprintf(TemporaryDoxygenOutputFolder, "%shtml/", DoxygenFolder);
    fflush(stdout);
    //if(isDirectoryExists(TemporaryDoxygenOutputFolder))
   //     removeAllFilesFromADirectory(TemporaryDoxygenOutputFolder); // remove html directory
    /* Run Doxygen to create call graphs */
#ifdef RUN_DOXYGEN

  // if(!isDirectoryExists(tempDoxygenCallGraphDir) && isDirectoryEmpty(tempDoxygenCallGraphDir)) {
   // if(!isDirectoryExists(TemporaryDoxygenOutputFolder) && isDirectoryEmpty(TemporaryDoxygenOutputFolder)){
        char *doxyfileName = (char *) malloc(200 * sizeof(char));
        sprintf(doxyfileName, "%sDoxyfile", DoxygenFolder);
        generateDoxyFile(DoxygenFolder, doxyfileName);

        /* Reset Doxygen Environment */
        if (isDirectoryExists(tempDoxygenCallGraphDir))
            recursiveDelete(tempDoxygenCallGraphDir);
        if (isDirectoryExists(tempDoxygenCallerGraphDir))
            recursiveDelete(tempDoxygenCallerGraphDir);

        /* Run Doxygen Command */
        char *doxygenCommandToCreateCallGraphs = "doxygen Doxyfile";
        char *doxygenCommand = (char *) malloc(200 * sizeof(char));
        sprintf(doxygenCommand, "cd %s \n %s", DoxygenFolder, doxygenCommandToCreateCallGraphs);
        printf("[DOXYGEN] Creating call graphs...\n");
        int commandDoxygeStatus = system(doxygenCommand);
        if (commandDoxygeStatus == 0) {
            if (isDirectoryExists(TemporaryDoxygenOutputFolder))
                printf("[DOXYGEN] Call graphs have successfully been created!\n");
            else
                printf("ERROR: Directory %s was not created!", TemporaryDoxygenOutputFolder);
        } else {
            printf("ERROR Doxygen Command: %s\n", doxygenCommand);
            exit(1);
        }
        free(doxygenCommand);
        free(doxyfileName);
  //  } else
    //    printf("\t.dot files already created.");

#endif

    char *callFileType = "_cgraph.dot"; // Define type file with "."
    char *callerFileType = "_icgraph.dot";
    char *fileTypeDot = ".dot";
    char *fileTypeJs = ".js";

   /* check whether call graphs already been generated and renamed. It runs if
    * there are no folders TempCallGraphs and TempCallerGraphs*/
    printf("[AUTOSCALPEL] Copying dot files to TempDoxygenAutoScalpel directory...\n");
    if(isDirectoryEmpty(tempDoxygenCallGraphDir)) {
        createADirectory(tempDoxygenCallGraphDir);
            int commandCopyCallGraphStatus = copyFilesFromDir(TemporaryDoxygenOutputFolder, tempDoxygenCallGraphDir,
                                                              callFileType);
            if (commandCopyCallGraphStatus == 0) {
                printf("[AUTOSCALPEL] Renaming all call.dot files...\n");
                renameDotFileToFunctionName(tempDoxygenCallGraphDir, tempDoxygenCallGraphDir, fileTypeDot); // Rename dot files
            } else
                printf("ERROR Move Call files!\n");
        } else
            printf("[AUTOSCALPEL] The Call graphs already been generated.\n");

    /* check whether caller graphs already been generated and renamed. */
    if(isDirectoryEmpty(tempDoxygenCallerGraphDir)){
        createADirectory(tempDoxygenCallerGraphDir);

        int commandCopyDotFilesStatus = copyFilesFromDir(TemporaryDoxygenOutputFolder, tempDoxygenCallerGraphDir, callerFileType);
        if (commandCopyDotFilesStatus == 0) {
            printf("[AUTOSCALPEL] Renaming all caller.dot files...\n");
            renameDotFileToFunctionName(tempDoxygenCallerGraphDir, tempDoxygenCallerGraphDir, fileTypeDot);
        } else
            printf("ERROR Move Caller files!\n");
    } else
        printf("[AUTOSCALPEL] The Caller graphs have already been generated.\n");

    /* Set path TempCallerGraphs */
    char * jsDirectory = (char *) malloc(100 * sizeof(char));
    sprintf(jsDirectory, "%sJS/",TemporaryDoxygenAutoScalpelFolder);
    fflush(stdout);

    if(isDirectoryEmpty(jsDirectory)){
        createADirectory(jsDirectory);

        int commandCopyJSFilesStatus = copyFilesFromDir(TemporaryDoxygenOutputFolder, jsDirectory, fileTypeJs);
        if (commandCopyJSFilesStatus != 0) {
            printf("ERROR Move Caller files!\n");
            exit(0);
        }

    } else
        printf("[AUTOSCALPEL] The Caller graphs have already been generated.\n");
    free(jsDirectory);
    free(TemporaryDoxygenAutoScalpelFolder);
    free(tempDoxygenCallGraphDir);
    free(tempDoxygenCallerGraphDir);

}

#endif
typedef struct elemento Elem;
Stack *path;

int searchShortestDistance(float *dist, int *visitado, int NV){
    int i, menor = -1, primeiro = 1;
    for(i=0; i < NV; i++){
        if(dist[i] >= 0 && visitado[i] == 0){
            if(primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if(dist[menor] > dist[i])
                    menor = i;
            }
        }
    }
    return menor;
}

Stack* createStack(){
    Stack* pi = (Stack*) malloc(sizeof(Stack));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_Pilha(Stack* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int pushStack(Stack* pi, int noId){
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->nodeId = noId;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int popStack(Stack* pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int stackSize(Stack* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int stackFull(Stack* pi){
    return 0;
}

int StackEmpty(Stack* pi){
    if(pi == NULL)
        return 1;
    if(*pi == NULL)
        return 1;
    return 0;
}

void printfStack(Stack* pi){
    if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL){
        printf(" %d ",no->nodeId);
        no = no->prox;
        if(no)
            printf("->");
    }
    printf("\n");
}

//TODO move this function to folderContent.c
char * constructSubDirectoryPath(const char *subPath, const char *sourceFileName){

    char * outputFile =  "outputFile.out";
    fflush(stdout);
    char * commandFind = (char *) malloc(200 * sizeof (char));
    sprintf(commandFind, "find %s -name %s >> %s",subPath, sourceFileName, outputFile);
  //  sprintf(commandFind, "pwd >> %s",outputFile);
    int found = system(commandFind);
    if (found != 0)
        return NULL;
    else {
        char *completePath = NULL;
        completePath = (char *) malloc(100 * sizeof(char));
        FILE *fp = fopen(outputFile, "r");
        if(fp==NULL)
            printf("Wait");
        fgets(completePath, 99, fp);
        fclose(fp);
        strtok(completePath, "\n");
        char *removeOutputFile = NULL;
        removeOutputFile = (char *) malloc(100 * sizeof(char));
        sprintf(removeOutputFile, "rm %s", outputFile);
        int removeCommand = system(removeOutputFile);

        char *finalSourcePath;
        finalSourcePath = (char *) malloc(200 * sizeof(char));

        if (removeCommand == 0) {
            char * pch = NULL;
            strcpy(finalSourcePath, &completePath[strlen(subPath)+1]);

            /* Create subDirectory in TXLTemporaryMultiFileFolder */
            char * newSubdirectoryInTempSourceDirectory = NULL;
            newSubdirectoryInTempSourceDirectory = readSubstring(subPath, completePath,sourceFileName);
            char *subTemporaryMultiFileFolder;
            subTemporaryMultiFileFolder = (char *) malloc(200 * sizeof(char));
            strcpy(subTemporaryMultiFileFolder,&newSubdirectoryInTempSourceDirectory[1]);
            sprintf(newSubdirectoryInTempSourceDirectory, "%s%s",TXLTemporaryMultiFileFolder ,subTemporaryMultiFileFolder);
            if(!isDirectoryExists(newSubdirectoryInTempSourceDirectory))
                createADirectory(newSubdirectoryInTempSourceDirectory);

            return finalSourcePath;
        }else {
            printf("ERROR: outputFile does not find!!\n");
            exit(1);
        }
    }

}
char * findFunctionFileFromCallGraph(const char *doxyDirect, char * targetFunction){

    char *filePath = (char *) malloc(1000 * sizeof(char));
    char *functionSourceFile = NULL;
    sprintf(filePath, "%s%s.dot", doxyDirect, targetFunction);
   // printf("\tFind function.\n");
    ListOfString *ListOfDotFiles = NULL;
    DIR *dr;
    struct dirent *dir;
    dr = opendir(doxyDirect);
    if(dr) {
        while ((dir = readdir(dr)) != NULL)
            addNewString(&ListOfDotFiles, dir->d_name);

        closedir(dr);
    } else {
        printf("Could not open current directory");
        exit(1);
    }
    int foundFlag = 0;
    while (ListOfDotFiles && foundFlag ==0) {
        if (strstr(ListOfDotFiles->el, targetFunction) && !strstr(ListOfDotFiles->el, "_8h")) {
            char *filePath;
            filePath = (char *) malloc(500 * sizeof(char));
            sprintf(filePath, "%s%s", doxyDirect, ListOfDotFiles->el);
            FILE *fileStream = fopen(filePath, "r");
            char *word;
            word = (char *) malloc(500 * sizeof(char));
            char *line;
            line = (char *) malloc(4000 * sizeof(char));
            char *functionName;
            while (fscanf(fileStream, "%s", word) != EOF && foundFlag ==0) {
                if (strstr(word, "SourceFile=")) {
                    fgets(word, 500, fileStream);
                    functionSourceFile = (char *) malloc(100 * sizeof(char));
                    strcpy(functionSourceFile, word + 1);
                    strtok(functionSourceFile, "\n");
                    foundFlag = 1;
                }
            }
            fclose(fileStream);
        }
        ListOfDotFiles = ListOfDotFiles->next;
    }
    return functionSourceFile;
}
/*
 * Fix function name variations
 */
void fixFunctionName(char ** functionName) {
    while (strstr((*functionName), "\\l") != NULL)
        (*functionName) = replace_str((*functionName), "\\l", "");
}
/*
 * Fix source file name variations
 */
void fixSourceFileName(char ** sourceFile){
    char * currentFileName = (char *) malloc(200 * sizeof(char));
    while (strstr((*sourceFile), "__") != NULL) {
        strcpy(currentFileName,(*sourceFile));
        (*sourceFile) = replace_str(currentFileName, "__", "_");
    }
    while (strstr((*sourceFile), "_2") != NULL) {
        strcpy(currentFileName,(*sourceFile));
        (*sourceFile) = replace_str(currentFileName, "_2", "/");
    }
}
/*
 * Parser to both call and caller graph. Define graphType as callGraph or callerGraph
 */
readCallCallerGrafGeneratedByDoxygen(ListOfFunctionForGraph ** ListOfFunctionsSourceFilesTarget, char * graphTargetDir, char * graphSecondaryDir,
        char * targetFunction) {
    /* Call graph parser */
    char *word = (char *) malloc(500 * sizeof(char));
    char *currentNode = (char *) malloc(100 * sizeof(char));
    long int idFunction = 1;
    char * sourceFile = (char *) malloc(100 * sizeof(char));

    char *filePath = (char *) malloc(100 * sizeof(char));
    sprintf(filePath, "%s%s.dot", graphTargetDir, targetFunction);

    FILE *fout = fopen(filePath, "r");
    if (fout == NULL) {  // Catch Core Function without call graph
        printf("\tThere is no call graph from function %s.\n", targetFunction);
        sourceFile = findFunctionFileFromCallGraph(graphSecondaryDir,targetFunction);// Try to get file name from caller graft
        if(sourceFile != NULL && targetFunction != NULL) {
            strcpy(sourceFile, constructSubDirectoryPath(donorSourceFileFolder, sourceFile));
            strcpy(currentNode, "Node1");
            addNewFunctionForGraphNode(ListOfFunctionsSourceFilesTarget, targetFunction, sourceFile, currentNode,
                                       idFunction);
        } else{
            printf("There is no call graph from function: %s\n", targetFunction);
            ListOfFunctionsSourceFilesTarget = NULL;
        ///    exit(1);
        }
    } else { // Catch function with call graph
        sourceFile = (char *) malloc(100 * sizeof(char));
        while (fscanf(fout, "%s", word) != EOF) {
            char *functionName = NULL;
            char *headerFile = NULL;
            if (strstr(word, "SourceFile=")) { // Catch core function source file name
                fgets(word, 500, fout);
                strcpy(sourceFile, word + 1);
                strtok(sourceFile, "\n");
                strcpy(currentNode, "Node1");
                if(targetFunction != NULL && sourceFile != NULL) {
                    if (!searchForFunctionForGraph(*ListOfFunctionsSourceFilesTarget, targetFunction)) {
                        addNewFunctionForGraphNode(ListOfFunctionsSourceFilesTarget, targetFunction, sourceFile,
                                               currentNode, idFunction);
                        idFunction++;
                    }
                } else{
                    printf("Error function name or source file did not find! Function: %s Source file: %s", targetFunction, sourceFile);
                    exit(1);
                }
            }
            if (strstr(word, "Node") && strcmp(word, "Node1")) { // Catch all nodes called from core function
                strcpy(currentNode, word);
                fscanf(fout, "%s", word);
                char *label = "label=\"";
                if (strstr(word, "label=\"")) { // get function name
                    functionName = readSubstring(label, word, "\"");
                    fixFunctionName(&functionName);//Fix source file name anomalies
                    fscanf(fout, "%s", word);
                    fscanf(fout, "%s", word);
                    char *fileLabel = "URL=\"$";
                    if (strstr(word, fileLabel)) { // Catch source file name
                        if (strstr(word, "_8c.")) { // Check if the current one is a .c file
                            sourceFile = readSubstring(fileLabel, word, "_8c.");
                            strcat(sourceFile, ".c");
                            fixSourceFileName(&sourceFile);//Fix source file name anomalies
                        } else {
                            if (strstr(word, "_8h.")) {// Check if the current one is a .h file
                                headerFile = readSubstring(fileLabel, word, "_8h.");
                                strcat(headerFile, ".h");
                                fixSourceFileName(&headerFile);// Replace duple underline generated by Doxygen
                                ///TODO put here the implementation of ListOfFunctionsSourceFilesTarget with the header file when the function is declared
                                sourceFile = findFunctionFileFromCallGraph(graphTargetDir,functionName); // Look for call graph file from function name
                                if(sourceFile == NULL) // There is no call graph for this function
                                    sourceFile = findFunctionFileFromCallGraph(graphSecondaryDir, functionName); // Look for caller graph file from function name
                                if(sourceFile == NULL) // There is no caller graph for this function. The function is declared but the implementation is not in the donor project
                                    sourceFile = headerFile;
                            } else {
                                printf("Parsing incorrect! Unknown Source file format.\n");
                                exit(1);
                            }
                        }
                        /* Add new function at List of funcitons target files */
                        if(functionName != NULL && sourceFile!= NULL) {
                            //if (!searchForFunctionForGraph(*ListOfFunctionsSourceFilesTarget, functionName)) {
                       ///         if(strstr(functionName,  "linecount"))
                     ///               printf("pare aqui");
                                addNewFunctionForGraphNode(ListOfFunctionsSourceFilesTarget, functionName, sourceFile,
                                                           currentNode, idFunction);
                                idFunction++;
                           // }
                        } else{
                            printf("Error function name or source file did not find! Function: %s Source file: %s", functionName, sourceFile);
                            exit(1);
                        }
                    }
                }
            }
        }
    }
    fclose(fout);

    free(word);
    free(currentNode);
    free(filePath);
}

ListOfFunctionForGraph * callAndCallerGraphParser(char * functionFile, char * targetFunction, char * graphType) {

    char * TemporaryDoxygenMuscalpelFolder = (char *) malloc((strlen(DoxygenFolder) + 30) * sizeof (char));
    sprintf(TemporaryDoxygenMuscalpelFolder, "%sTempDoxygenAutoScalpel/", DoxygenFolder);
    fflush(stdout);

    //Define which graph will be graph will be parsed. Call graph in TempCallGraphs directory or caller graph in TempCallerGraphs
    char *TempDoxygenCallGraphDir = (char *) malloc((strlen(TemporaryDoxygenMuscalpelFolder) + 18) * sizeof(char));
    if(!strcmp(graphType, "callGraph"))
        sprintf(TempDoxygenCallGraphDir, "%sTempCallGraphs/", TemporaryDoxygenMuscalpelFolder);
    else {
        if (!strcmp(graphType, "callerGraph"))
            sprintf(TempDoxygenCallGraphDir, "%TempCallerGraphs/", TemporaryDoxygenMuscalpelFolder);
        else { // It is not a valid graph
            printf("ERROR This parser is unable to read this kind of graph! Please use callGraph or CallerGraph as graphType");
            exit(1);
        }
    }

    /* Format file path .dot from target function name */
    char *filePath = (char *) malloc(200 * sizeof(char));
    sprintf(filePath, "%s%s.dot", TempDoxygenCallGraphDir, targetFunction);
    fflush(stdout);

    /* List of Functions Source Files transplanted */
    ListOfFunctionForGraph * ListOfFunctionsSourceFilesTarget = NULL;

    readCallCallerGrafGeneratedByDoxygen( &ListOfFunctionsSourceFilesTarget, filePath,TempDoxygenCallGraphDir,targetFunction );

    //LOS Generate done list to sAnalsyze
#if 0 // ANALYZE = 1
    char *sourceOutputFilePath = NULL;
    sourceOutputFilePath = (char *) malloc(200 * sizeof(char));
    sprintf(sourceOutputFilePath, "%sAnalyze/%s_LIST_OF_NODES.csv", TemporaryDoxygenFolder,targetFunction);

    FILE *fSoureOutputFile = fopen(sourceOutputFilePath, "w+");

    char * label = "Id, Nodes";
    fprintf(fSoureOutputFile, "Id, Nodes\n");

    while(auxlistOfFunctionsSourceFilesTarget){
        char * currentNode = NULL;
        currentNode = (char *) malloc(40 * sizeof(char));
        sprintf(currentNode, "%d, %s\n", auxlistOfFunctionsSourceFilesTarget->id, auxlistOfFunctionsSourceFilesTarget->functionName);
        fprintf(fSoureOutputFile, "%s", currentNode);

        // printf("%d, ",auxlistOfFunctionsSourceFilesTarget->id);
        //printf("N: %s\n", auxlistOfFunctionsSourceFilesTarget->nodeId);
        // printf("S: %s\n", auxlistOfFunctionsSourceFilesTarget->sourceFile);
        // printf("----------------------------\n");

        auxlistOfFunctionsSourceFilesTarget = auxlistOfFunctionsSourceFilesTarget->next;

    }
    fclose(fSoureOutputFile);
#endif
    free(filePath);
    free(TempDoxygenCallGraphDir);
    free(TemporaryDoxygenMuscalpelFolder);
    return ListOfFunctionsSourceFilesTarget;
}

/*
 * Parser to both call and caller graph. Define graphType as callGraph or callerGraph
 */
ListOfFunctionForGraph * readACallGraphAsList( char * targetFunction) {
    printf("\tReading the Call Graph from Function: %s\n",targetFunction);

    char * TempDoxygenCallGraphDir = (char *) malloc(100 * sizeof (char));
    sprintf(TempDoxygenCallGraphDir, "%sTempDoxygenAutoScalpel/TempCallGraphs/", DoxygenFolder);
    fflush(stdout);
    char * TempDoxygenCallerGraphDir = (char *) malloc(100 * sizeof (char));
    sprintf(TempDoxygenCallerGraphDir, "%sTempDoxygenAutoScalpel/TempCallerGraphs/", DoxygenFolder);
    fflush(stdout);
    ListOfFunctionForGraph * ListOfFunctionsSourceFilesTarget = NULL;

    readCallCallerGrafGeneratedByDoxygen(&ListOfFunctionsSourceFilesTarget, TempDoxygenCallGraphDir,TempDoxygenCallerGraphDir, targetFunction);

    return ListOfFunctionsSourceFilesTarget;
}

/*
 * Parser to caller graph. Define graphType as callGraph or callerGraph
 */
ListOfFunctionForGraph * readACallerGraphAsList( char * targetFunction) {

    ListOfFunctionForGraph * ListOfFunctionsSourceFilesTarget = NULL;

    char * TempDoxygenCallerGraphDir =  (char *) malloc(100 * sizeof (char));
    sprintf(TempDoxygenCallerGraphDir, "%sTempDoxygenAutoScalpel/TempCallerGraphs/", DoxygenFolder);

    char * TempDoxygenCallGraphDir =  (char *) malloc(100 * sizeof (char));
    sprintf(TempDoxygenCallGraphDir, "%sTempDoxygenAutoScalpel/TempCallGraphs/", DoxygenFolder);
    fflush(stdout);
    readCallCallerGrafGeneratedByDoxygen(&ListOfFunctionsSourceFilesTarget, TempDoxygenCallerGraphDir,TempDoxygenCallGraphDir, targetFunction);

    free(TempDoxygenCallerGraphDir);
    free(TempDoxygenCallGraphDir);
    return ListOfFunctionsSourceFilesTarget;
}
//-------------------------------------------------------------------------------------------------------------


struct Graph * readACallerGraph( ListOfFunctionForGraph * ListOfFuncitonSourceFile, char * targetFunction) {
    printf("[AUTOSCALPEL] Transform Reverse Call Graph\n");

    ListOfFunctionForGraph * ListOfFunctionsSourceFilesTarget = NULL;
    char * TempDoxygenCallerGraphDir = (char *) malloc((strlen(DoxygenFolder) + 30) * sizeof (char));
    sprintf(TempDoxygenCallerGraphDir, "%sTempDoxygenAutoScalpel/TempCallerGraphs/", DoxygenFolder);
    fflush(stdout);
    struct Graph * graph = readAGraph(ListOfFuncitonSourceFile, TempDoxygenCallerGraphDir, targetFunction);
    free(TempDoxygenCallerGraphDir);
    return graph;
}

found = 0;
void DFSPath(struct Graph *graph, int vertex, int sourceNode) {
    struct node* ptr = graph->adjLists[vertex];

    graph->visited[vertex] = 1;
    ///printf("-> %d", vertex);
    pushStack(path,vertex);
    if (vertex == sourceNode) {
        found = 1;
        return;
    }
    while(ptr!=NULL && found == 0) {
        int adj_vertex = ptr->vertex;
        if(graph->visited[adj_vertex] == 0) {
            DFSPath(graph, adj_vertex, sourceNode);
        }
        ptr = ptr->next;
    }
    if(found == 0 )
        popStack(path);
}

Stack *searchPath(struct Graph *graph, ListOfFunctionForGraph * listOfFunction){
    int destNodeId = searchIdFromFunctionName(listOfFunction, donorEntryFunction);
    int sourceNodeId = searchIdFromFunctionName(listOfFunction, GraftFunctionName);
    path = createStack();
    DFSPath(graph, sourceNodeId, destNodeId);
    return path;
}

int array[10];

Stack * inverter(Stack *pi){
    Stack * auxPi = createStack();
    Elem* no = *pi;
    while(no != NULL){
        popStack(pi);
        pushStack(auxPi, no);
    }
    return auxPi;
}

ListOfFunctionForGraph *  readPath(Stack* path, ListOfFunctionForGraph * listOfFunction){
    ListOfFunctionForGraph * currentFunctionContent = NULL;
    ListOfFunctionForGraph * ListOfFunctionPath = NULL;
    if(path == NULL)
        return NULL;

    Elem* no = *path;
    while(no != NULL){
        currentFunctionContent = searchNodeReferenceFromId(listOfFunction, no->nodeId);
        addNewFunctionForGraphNode(&ListOfFunctionPath, currentFunctionContent->functionName, currentFunctionContent->sourceFile,
                                   currentFunctionContent->nodeId, currentFunctionContent->id);
        no = no->prox;
    }
    return ListOfFunctionPath;
}

void printPath(Stack* pi, ListOfFunctionForGraph * listOfFunction){
    ListOfFunctionForGraph * currentFunctionContent;
    if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL){
        printf(" %d ",no->nodeId);
        currentFunctionContent = searchNodeReferenceFromId(listOfFunction, no->nodeId);
        printf("%s\n",currentFunctionContent->functionName);
        no = no->prox;
    }
    printf("\n");
}

/*
 * Parser to call and caller graph
 */
struct Graph * readAGraph(ListOfFunctionForGraph * listOfFunction, char * graphDir, char * targetFunction){

    char *filePath = NULL;
    filePath = (char *) malloc(300 * sizeof(char));
    sprintf(filePath, "%s%s.dot", graphDir, targetFunction);
    fflush(stdout);

    long int countNumberOfFunctions = countElementsInListOfFunctionSourceFileForGraph(listOfFunction);

    struct Graph* graph = createGraph(countNumberOfFunctions+1);

    FILE * foutCaller = fopen(filePath, "r");
    if(foutCaller == NULL)
        return graph; // Return graph equal NULL case there is no caller graph

    char * wordCaller = NULL;
    wordCaller = (char *) malloc(300 * sizeof (char));

    long int countNodes = 0;
    ListOfFunctionForGraph * auxlistOfFunctionsSourceFilesTarget = listOfFunction;
    ListOfFunctionForGraph * origNodeReference = NULL;
    ListOfFunctionForGraph * destNodeReference = NULL;


    while (fscanf(foutCaller, "%s", wordCaller) != EOF) {
        if (strstr(wordCaller, "Node")) {
            char *nodeOrig = (char *) malloc(300 * sizeof(char));
            strcpy(nodeOrig, wordCaller);
            fscanf(foutCaller, "%s", wordCaller);  // get new word
            if (strstr(wordCaller, "->")) {
                char *nodeDest = (char *) malloc(300 * sizeof(char));
                fscanf(foutCaller, "%s", wordCaller);  // get new word
                strcpy(nodeDest, wordCaller);

                origNodeReference = searchNodeReference(auxlistOfFunctionsSourceFilesTarget, nodeOrig);
                destNodeReference = searchNodeReference(auxlistOfFunctionsSourceFilesTarget, nodeDest);

                long int idNodeOrig = origNodeReference->id;
                long int idNodeDest = destNodeReference->id;
                char * funcNameOrig = (char *) malloc(100 * sizeof (char));
                strcpy(funcNameOrig, origNodeReference);
                fflush(stdout);
                char * funcNameDest = NULL;
                funcNameDest = (char *) malloc(100 * sizeof (char));
                strcpy(funcNameDest, destNodeReference);

                if(funcNameDest ==NULL){
                    funcNameDest = (char *) malloc((strlen(auxlistOfFunctionsSourceFilesTarget->functionName) + 1) * sizeof (char *));
                    strcpy(funcNameDest, auxlistOfFunctionsSourceFilesTarget->functionName);
                }

                if(funcNameOrig ==NULL){
                    funcNameOrig = (char *) malloc((strlen(auxlistOfFunctionsSourceFilesTarget->functionName) + 1) * sizeof (char *));
                    strcpy(funcNameOrig, auxlistOfFunctionsSourceFilesTarget->functionName);
                 }

                addEdge(graph, idNodeOrig, idNodeDest);

              //  addNewFunctionHeaderSourceFileGraph1(&graph, auxlistOfFunctionsSourceFilesTarget->functionName, auxlistOfFunctionsSourceFilesTarget->sourceFile, auxlistOfFunctionsSourceFilesTarget->nodeId, nodeDest) ;
                //printf("\tNode: [%d]\n",countNodes);
                countNodes++;
            }
        }
        fflush(stdout);
    }

    /*  int eh_digrafo = 1;
      Grafo* gr = cria_Grafo(10, 10, 0);
      insereAresta(gr, 1, 2, eh_digrafo, 1);
      insereAresta(gr, 2, 3, eh_digrafo, 1);
      insereAresta(gr, 3, 4, eh_digrafo, 1);
      insereAresta(gr, 4, 2, eh_digrafo, 1);
      insereAresta(gr, 4, 5, eh_digrafo, 1);
      insereAresta(gr, 5, 2, eh_digrafo, 1);
      insereAresta(gr, 2, 6, eh_digrafo, 1);
      insereAresta(gr, 6, 10, eh_digrafo, 1);
      insereAresta(gr, 2, 1, eh_digrafo, 1);
      insereAresta(gr, 2, 7, eh_digrafo, 1);
      insereAresta(gr, 2, 8, eh_digrafo, 1);
      insereAresta(gr, 8, 2, eh_digrafo, 1);
      insereAresta(gr, 8, 5, eh_digrafo, 1);
      insereAresta(gr, 8, 9, eh_digrafo, 1);
      insereAresta(gr, 9, 2, eh_digrafo, 1);
      int vis[10];
      pi = cria_Pilha();
      imprime_Grafo(gr);
      printf("Profundidade\n");
      buscaProfundidade_Grafo(gr,1,vis,10);
      printf("Largura\n");
      buscaLargura_Grafo(gr,1,vis);
      printf("pilha\n");
      imprime_Pilha(pi);
      printf("menor distancia\n");
      int ant[5];
      float dist[5];
      menorCaminho_Grafo(gr, 1, ant, dist);*/

    /*addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 2);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 7);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 2);
    addEdge(graph, 2, 1);
    addEdge(graph, 2, 8);
    addEdge(graph, 8, 2);
    addEdge(graph, 8, 5);
    addEdge(graph, 2, 9);
    addEdge(graph, 9, 2);*/
    /*addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 4, 2);
    addEdge(graph, 3, 5);
    addEdge(graph, 3, 6);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 2);*/
        fclose(foutCaller);
    return graph;

}

void DFS(struct Graph* graph, int vertex) {
    struct node* ptr = graph->adjLists[vertex];

    graph->visited[vertex] = 1;
    printf("-> %d", vertex);

    while(ptr!=NULL) {
        int adj_vertex = ptr->vertex;

        if(graph->visited[adj_vertex] == 0) {
            DFS(graph, adj_vertex);

        }

        ptr = ptr->next;
    }
}

char * searchNodeFunctionName(ListOfFunctionForGraph * head, char * searchedNode) {

    // adjlist_node_p adjListPtr = graph->adjListArr[0].head;
    ListOfFunctionForGraph * listFunctions = head;
    while(listFunctions) {
        char * nodeId = listFunctions->nodeId;
        if (!strcmp(nodeId, searchedNode)){
           // printf("%d: %s\n", listFunctions->id,listFunctions->nodeId);
            return listFunctions->functionName;
        }
        listFunctions = listFunctions->next;
    }
    return NULL;
}

void addNewFunctionHeaderSourceFileGraph1(struct Graph ** head, char * functionName, char * sourceFile, char * nodeId, char * nodeAd) {
    struct Graph * newEl = (ListOfFunctionForGraph *) malloc(1 * sizeof (ListOfFunctionForGraph));
    newEl->functionName = (char *) malloc((strlen(functionName) + 1) * sizeof (char *));
    newEl->sourceFile = (char *) malloc((strlen(sourceFile) + 1) * sizeof (char *));
    newEl->nodeId = (char *) malloc((strlen(nodeId) + 1) * sizeof (char *));
 //   newEl->headerFile = (char *) malloc((strlen(sourceFile) + 1) * sizeof (char *));
    strcpy(newEl->functionName, functionName);
    strcpy(newEl->sourceFile, sourceFile);
    strcpy(newEl->nodeId, nodeId);
//    strcpy(newEl->headerFile, headerFile);

    newEl->adjLists = NULL;
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

//LOS TODO Try to use itoa()
void tostring(char str[], int num)
{
    int i, rem, len = 0, n;

    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

// Creating a node
struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(long int vertices)
{
    fflush(stdout);
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    fflush(stdout);
    graph->adjLists = malloc(vertices * sizeof(struct node*));

    graph->visited = malloc(vertices * sizeof(int));

    long int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

// Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void addEdgeWithFunctionName(struct Graph* graph, int src, ListOfFunctionForGraph *destNodeReference )
{
    // Add edge from src to dest
    struct node* newNode = createNodeWithFunctionName(destNodeReference);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    /*  newNode = createNode(src);
      newNode->next = graph->adjLists[dest];
      graph->adjLists[dest] = newNode;*/
}


struct node* createNodeWithFunctionName(ListOfFunctionForGraph *destNodeReference )
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = destNodeReference->id;
    newNode->functionName = destNodeReference->functionName;
    newNode->next = NULL;
    return newNode;
}
