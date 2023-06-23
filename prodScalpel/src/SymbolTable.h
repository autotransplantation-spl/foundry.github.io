/* 
 * File:   SymbolTable.h
 * Author: ---
 *
 * Created on 26 May 2014, 03:56
 */

#ifndef SYMBOLTABLE_H
#define	SYMBOLTABLE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdio.h>

    struct idOfVariable {
        char * ID;
        struct idOfVariable *next;

    };
    typedef struct idOfVariable IdOfVariable;

    struct symbolTable {
        char * TypeOfVar;
        IdOfVariable * ListOfIdentifiers;
        struct symbolTable *next;
    };

    typedef struct symbolTable SymbolTable;


    void addNewID(IdOfVariable **head, char * idName);

    void addNewVarType(SymbolTable **head, char* varTypeName);

    void addNewVariableDeclaration(SymbolTable ** head, char * varType, char * varID);

    void freeSymbolTableMemory();

    void freeListOfSymbolTable(SymbolTable ** head);

    char * searchForASymbolTableEntry(SymbolTable * head, char * varID);

    void printSymbolTable(SymbolTable * head, char * outputFile);

    SymbolTable * readSymbolTable(FILE *fin);
    
    int countIDsInSymbolTable(SymbolTable * head);
    
    SymbolTable * readSymbolTableAddedEntryPoint(char * HostSymbolTableFile, SymbolTable ** EntryPointSymbolTable);
    
    void addOneSymbolTableToTheOther(SymbolTable ** destination, SymbolTable * source);

    SymbolTable * copySymbolTableList(SymbolTable * initial);

    SymbolTable * readSymbolTableForHost(FILE *fin);


#ifdef	__cplusplus
}
#endif


#endif	/* SYMBOLTABLE_H */

