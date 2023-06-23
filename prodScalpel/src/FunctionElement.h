/* 
 * File:   FunctionElement.h
 * Author: ---
 *
 * Created on 27 June 2014, 18:45
 */

#ifndef FUNCTIONELEMENT_H
#define	FUNCTIONELEMENT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "ListOfString.h"
#include <stdio.h>
    
    struct functionElement {
        char * NameOfFunction;
        ListOfString * LOCs;
        struct functionElement *next;
    };

    typedef struct functionElement FunctionElement;
    
    void freeListOfFunctionElement(FunctionElement ** head);
    
    FunctionElement * searchAnElement(FunctionElement * head, char * name);
    
    void addNewFunction(FunctionElement ** head, char * name);
    
    int addNewLOC(FunctionElement ** head, char * name, char * LOC);
    
    void addNewFunctionElement(FunctionElement ** head, FunctionElement * newElement);
    
    void printListOfFunctions(FILE * fout, FunctionElement * head);
    
    void printAFunctionElement(FILE * fout, FunctionElement * head);
    
    void fixCloseBrackets(ListOfString ** head);
    
    void removeLOCsFromAListOfStringAfterCall(ListOfString ** head, char * nextFunction);
    
    void removeLOCsAfterCallForAList(FunctionElement ** head,
    		ListOfString * reverseCallGraph);
    
    FunctionElement * readFunctionElemenentListFromFile(char * inputFile, ListOfString * reverseCallGraph);
    


#ifdef	__cplusplus
}
#endif

#endif	/* FUNCTIONELEMENT_H */

