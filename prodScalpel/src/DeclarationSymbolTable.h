/* 
 * File:   DeclarationSymbolTable.h
 * Author: ---
 *
 * Created on 02 July 2014, 22:59
 */

#ifndef DECLARATIONSYMBOLTABLE_H
#define	DECLARATIONSYMBOLTABLE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "ListOfString.h"
#include "SymbolTable.h"
#include "DependencyList.h"

    struct declarationSymbolTable {
        char * type;
        char * id;
        ListOfString * possibleMappings;
        char * currentMapping;
        char * declarationMarker;
        struct declarationSymbolTable *next;
    };

    typedef struct declarationSymbolTable DeclarationSymbolTable;

    DeclarationSymbolTable * readDeclarationSymbolTableFromFile(char * inputFile);

    void addNewPossibleMappingsDeclarationSymbolTableFromSymbolTable(DeclarationSymbolTable ** head,
            SymbolTable * headSymbolTable);

    DeclarationSymbolTable * GenerateDeclarationsSymbolTable(ListOfString * Skeleton,
            DependencyList * currentDependencyList, SymbolTable * HostSymbolTable,
			char * TXLTemporaryFolder);

    void printDeclarationSymbolTable(char * outputFile, DeclarationSymbolTable * head);

    int countElementsInDeclarationSymbolTable(DeclarationSymbolTable * head);

    ListOfString * declarationSymbolTableToListOfStringForGPIndividual(DeclarationSymbolTable * head);

    DeclarationSymbolTable * nthElementInDeclarationSymbolTable(DeclarationSymbolTable * head, int n);

    int addNewCurrentMappingDeclarationSymbolTable(DeclarationSymbolTable ** head, char * id, char * currentMapping);

    DeclarationSymbolTable * returnNewDeclSymbolTableJustForElementsWithPossibleMappings(DeclarationSymbolTable * initial);

    void addNewDeclarationSymbolTableToListOfStringForGPIndividual(ListOfString ** head, char * declarationMarker, char * id,
            char * currentMapping);

    DeclarationSymbolTable * nthElementInDeclarationSymbolTablePointer(DeclarationSymbolTable * head, int n);

    DeclarationSymbolTable * copyDeclarationSymbolTableList(DeclarationSymbolTable * initial);

    ListOfString * declarationSymbolTableToListOfStringForGPIndividual(DeclarationSymbolTable * currentDeclSymbolTable);

    int numberOfElementsWithCurrentMapping(DeclarationSymbolTable * head);
    
    int numberOfElementsWithCurrentMappingWithMoreThanOnePossibleMappings(DeclarationSymbolTable * head);
    
    int numberOfElementsNOCurrentMapping(DeclarationSymbolTable * head);
    
    DeclarationSymbolTable * nthElementWithCurrentMapping(DeclarationSymbolTable * head, int n);
    
    DeclarationSymbolTable * nthElementWithCurrentMappingMoreThanOnePossible(DeclarationSymbolTable * head, int n);
    
    DeclarationSymbolTable * nthElementWithNOCurrentMapping(DeclarationSymbolTable * head, int n);
    
    void addNewDeclarationSymbolTableFromDeclSymbolTableEl(DeclarationSymbolTable ** head, 
        DeclarationSymbolTable * elementToBeAdded);
    
    void freeDeclarationSymbolTable(DeclarationSymbolTable ** head);
    
    DeclarationSymbolTable * searchAnElementInDeclarationSymbolTable(DeclarationSymbolTable * head, 
        DeclarationSymbolTable * searchedEl);
    
    int countElementsWithMoreThenOnePossibleMappingsDeclarationSymbolTable (DeclarationSymbolTable * head);
    
    DeclarationSymbolTable * readDeclarationSymbolTableFromFileForHost(char * inputFile);

#ifdef	__cplusplus
}
#endif

#endif	/* DECLARATIONSYMBOLTABLE_H */

