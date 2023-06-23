/* 
 * File:   ListOfFunctionSourceFile.h
 * Author: ---
 *
 * Created on 03 July 2014, 19:12
 */

#ifndef LISTOFFUNCTIONSOURCEFILE_H
#define	LISTOFFUNCTIONSOURCEFILE_H

#include "ListOfString.h"
#ifdef	__cplusplus
extern "C" {
#endif

struct listOfFunctionSourceFile {
    char * functionName;
    char * sourceFile;
    struct listOfFunctionSourceFile * next;
};

typedef struct listOfFunctionSourceFile ListOfFunctionSourceFile;

struct sourceFileElementsList {
    char * sourceFile;
    ListOfString * functions;
    struct sourceFileElementsList *next;
};

typedef struct sourceFileElementsList SourceFileElementsList;

void freeListOfFunctionSourceFile(ListOfFunctionSourceFile ** head);

void addNewFunctionSourceFile(ListOfFunctionSourceFile ** head, char * functionName, char * sourceFile);

int removeFunctionSourceFile(ListOfFunctionSourceFile ** head, char * functionName);

void printAListOfFunctionSourceFile(ListOfFunctionSourceFile * head, char * outputFile);

int searchForFunction(ListOfFunctionSourceFile * head, char * searchedFunctionName);

int countElementsInListOfFunctionsSourceFile(ListOfFunctionSourceFile * head);

ListOfFunctionSourceFile * readFunctionsFilesFromFile(char * inputFile);

char * extractOnlyFileName(char * directory, char * sourceFile);

int searchFunctionInListOfFunctionsSourceFile (ListOfFunctionSourceFile * head, char * searchedFunctionName);

ListOfFunctionSourceFile * searchFunctionInListOfFunctionsSourceFileFromFunction (ListOfFunctionSourceFile * head, char * searchedFunctionName);

int searchFunctionAndFileInListOfFunctionsSourceFile (ListOfFunctionSourceFile * head, char * searchedFunctionName, char * searchedFileName );

void replaceSourceFilePahtByFileName(ListOfFunctionSourceFile ** head, char * directory);

ListOfFunctionSourceFile * extractListOfFunctionsFilesFromDir(char * directory, char * temporaryFolder, char * outputAllDefinedFunctionsInHost);

void addFunctionListToAnExistingOneFile(SourceFileElementsList ** destination, ListOfFunctionSourceFile * source);

ListOfString * readListOfFunctionInASourceFile(SourceFileElementsList * head, char * sourceFile);

SourceFileElementsList * searchSourceFile(SourceFileElementsList * head, char * sourceFile);

void replaceListOfSourceFilePahtByFileName(ListOfString ** head, char * directory);

ListOfFunctionSourceFile * createListOfFunctionsFromAFile(char * TXLProgsPath, char * listOfSourceFiles, char * outputFile) ;

ListOfString * reverseListOfFunctions(ListOfFunctionSourceFile * head) ;
#ifdef	__cplusplus
}
#endif

#endif	/* LISTOFFUNCTIONSOURCEFILE_H */

