/* 
 * File:   FunctionCallDependency.h
 * Author: ---
 *
 * Created on 01 July 2014, 18:49
 */

#ifndef FUNCTIONCALLDEPENDENCY_H
#define	FUNCTIONCALLDEPENDENCY_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "ListOfFunctionSourceFile.h"
#include <stdio.h>

    struct callDependency {
        char * LOCMarker;
        ListOfFunctionSourceFile * calledFunctions;
        struct callDependency *next;
    };

    typedef struct callDependency CallDependency;

    CallDependency * readCallDependencyFromFile(char * inputFile);


#ifdef	__cplusplus
}
#endif

#define MAC_OSX
#ifdef MAC_OSX
    CallDependency * readListOfNeededFunctionsDeclaration(char * inputFile);
    void addNewListOfNeededFunctionsForGlobals(CallDependency ** head, CallDependency * source, char * newMark);
    void addNewListOfNeededFunctionsForGlobalsInExistingOne(CallDependency ** head, CallDependency * source, char * newMark);
    void addNewListOfNeededFunctionsToAnExistingOneSearchingIfVarExisting(CallDependency ** destination, CallDependency * source);
    CallDependency * searchGlobalDeclMark(CallDependency * head, char * searchedGlobalDeclMark);
    void addNeededFunctionsDeclaration(CallDependency ** head, char * locMarker);
    int addCalledFunction(CallDependency ** head, char * locName, char * calledFunction, char * functionSourceFile);
    void freeListOfCallDependency(CallDependency ** head) ;
    void addNeededCallFunctionDeclarationListToAnExistingOne(CallDependency ** destination, CallDependency * source);
#endif

#endif	/* FUNCTIONCALLDEPENDENCY_H */

