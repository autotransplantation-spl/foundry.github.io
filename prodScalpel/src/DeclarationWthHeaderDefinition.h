/* 
 * File:   DeclarationWthHeaderDefinition.h
 * Author: ---
 *
 * Created on 09 July 2014, 22:18
 */

#ifndef DECLARATIONWTHHEADERDEFINITION_H
#define	DECLARATIONWTHHEADERDEFINITION_H

#ifdef	__cplusplus
extern "C" {
#endif

    struct declarationWithHeaderDefinition {
        char * declaration;
        char * headerDefinition;

        struct declarationWithHeaderDefinition * next;
    };

    typedef struct declarationWithHeaderDefinition DeclarationWithHeaderDefinition;

    void freeListOfDeclarationWithHeaderDefinition(DeclarationWithHeaderDefinition ** head);
    
    void addNewDeclarationWithHeaderDefinition(DeclarationWithHeaderDefinition ** head, char * declaration,
            char * headerDef);
    
    void addNewDeclarationWithHeaderDefinitionNoHeaderDef(DeclarationWithHeaderDefinition ** head, char * declaration);
    
    DeclarationWithHeaderDefinition * copyListOfDeclarationWithHeaderDefinition(DeclarationWithHeaderDefinition * head);
    
    int removeDeclarationWithHeaderDefinition(DeclarationWithHeaderDefinition ** head, char * declaration);
    
    void printAListOfDeclarationWithHeaderDefinition(DeclarationWithHeaderDefinition * head, char * outputFile);
    
    int searchDeclarationWithHeaderDefinitionInListOfDeclarationWithHeaderDefinition
    (DeclarationWithHeaderDefinition * head, char * searchedDeclaration);
    
    int countElementsInListOfDeclarationWithHeaderDefinition(DeclarationWithHeaderDefinition * head);
    
    void addListOfDeclarationWithHeaderDefinitionToExistingOneUniqueEl(DeclarationWithHeaderDefinition ** destination,
            DeclarationWithHeaderDefinition * source);

#ifdef	__cplusplus
}
#endif

#endif	/* DECLARATIONWTHHEADERDEFINITION_H */

