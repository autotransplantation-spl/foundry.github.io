/* 
 * File:   coreFunctionExtractor.h
 * Author: ---
 *
 * Created on 19 June 2014, 17:53
 */

#ifndef FUNCTIONEXTRACTOR_H
#define	FUNCTIONEXTRACTOR_H

#ifdef	__cplusplus
extern "C" {
#endif

struct listOfFunctionDeclaration {
    char * file;
    ListOfString * listOfDeclaration;
    struct listOfFunctionDeclaration * next;
};

typedef struct listOfFunctionDeclaration ListOfFunctionDeclaration;
#if 0 /* MULTHEADER FILES */
ListOfFunctionSourceFile * extractFunctionality(char * graftMethod, char * graftFileFullPath, char * donorSourceFiles, char * transplantWorkingFolder,
        char * txlProgsPath, char * TXLTemp, char * tempFolder, char * TXLTempMultiFiles) ;
#else
void extractFunctionality(char * graftMethod, char * graftFileFullPath, char * donorSourceFiles,
                          char * txlProgsPath, char * tempFolder, char * TXLTempMultiFiles) ;

#endif

// TODO remove
//void createListOfFunctionsTarget(char * TXLProgsPath, char * listOfSourceFiles, char * outputFile);

#ifdef	__cplusplus
}
#endif

#endif	/* FUNCTIONEXTRACTOR_H */

