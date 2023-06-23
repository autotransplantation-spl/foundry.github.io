#include "DeclarationSymbolTable.h"
#include "ListOfString.h"
#include "SymbolTable.h"
#include "GenTrans.h"

#include <stdio.h>
//#include <malloc.h>
#include <string.h>
#include <stdlib.h>

void freeDeclarationSymbolTable(DeclarationSymbolTable ** head) {
    DeclarationSymbolTable * aux;
    while (* head) {
        aux = *head;
        * head = (*head) -> next;
        freeListOfStrings(&(aux->possibleMappings));
        aux->possibleMappings = NULL;
        free(aux->currentMapping);
        free(aux->id);
        free(aux->type);
        free(aux->declarationMarker);
        aux->declarationMarker = NULL;
        aux->currentMapping = NULL;
        aux->id = NULL;
        aux->type = NULL;
        aux->next = NULL;
        free(aux);
        aux = NULL;
    }
    (* head) = NULL; //just in case...
}

DeclarationSymbolTable * searchDeclarationSymbolTableForID(DeclarationSymbolTable * head, char * id) {
    DeclarationSymbolTable * p;
    p = head;
    int s = 0;
    while (p && !s) {
        if (!strcmp(p->id, id)) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void addNewDeclarationSymbolTableCompleteElement(DeclarationSymbolTable ** head, char * id, char * type, char * decl,
        ListOfString * possibleMappings, char * currentMapping) {
    DeclarationSymbolTable * newEl = (DeclarationSymbolTable *) malloc(1 * sizeof (DeclarationSymbolTable));

    newEl->id = (char *) malloc((strlen(id) + 1) * sizeof (char));
    newEl->type = (char *) malloc((strlen(type) + 1) * sizeof (char));
    newEl->declarationMarker = (char *) malloc((strlen(decl) + 1) * sizeof (char));
    strcpy(newEl->id, id);
    strcpy(newEl->type, type);
    strcpy(newEl->declarationMarker, decl);
    newEl->possibleMappings = NULL;
    newEl->currentMapping = NULL;
    if (currentMapping) {
        newEl->currentMapping = (char *) malloc((strlen(currentMapping) + 1) * sizeof (char));
        strcpy(newEl->currentMapping, currentMapping);
    }
    if (possibleMappings) {
        newEl->possibleMappings = copyCompleteListOfString(possibleMappings);
    }
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        DeclarationSymbolTable * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

void addNewDeclarationSymbolTableFromDeclSymbolTableEl(DeclarationSymbolTable ** head,
        DeclarationSymbolTable * elementToBeAdded) {
    DeclarationSymbolTable * newEl = (DeclarationSymbolTable *) malloc(1 * sizeof (DeclarationSymbolTable));

    newEl->id = (char *) malloc((strlen(elementToBeAdded->id) + 1) * sizeof (char));
    newEl->type = (char *) malloc((strlen(elementToBeAdded->type) + 1) * sizeof (char));
    newEl->declarationMarker = (char *) malloc((strlen(elementToBeAdded->declarationMarker) + 1) * sizeof (char));
    strcpy(newEl->id, elementToBeAdded->id);
    strcpy(newEl->type, elementToBeAdded->type);
    strcpy(newEl->declarationMarker, elementToBeAdded->declarationMarker);
    newEl->possibleMappings = NULL;
    newEl->currentMapping = NULL;
    if (elementToBeAdded->currentMapping) {
        newEl->currentMapping = (char *) malloc((strlen(elementToBeAdded->currentMapping) + 1) * sizeof (char));
        strcpy(newEl->currentMapping, elementToBeAdded->currentMapping);
    }
    if (elementToBeAdded->possibleMappings) {
        newEl->possibleMappings = copyCompleteListOfString(elementToBeAdded->possibleMappings);
    }
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        DeclarationSymbolTable * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

DeclarationSymbolTable * returnNewDeclSymbolTableJustForElementsWithPossibleMappings(DeclarationSymbolTable * initial) {
    DeclarationSymbolTable * aux = initial;
    DeclarationSymbolTable * newSymbolTable = NULL;

    while (aux) {
        if (countElementsInListOfString(aux->possibleMappings) > 0) {
            addNewDeclarationSymbolTableCompleteElement(&newSymbolTable, aux->id, aux->type,
                    aux->declarationMarker, aux->possibleMappings, aux->currentMapping);
        }
        aux = aux->next;
    }
    return newSymbolTable;
}

DeclarationSymbolTable * copyDeclarationSymbolTableList(DeclarationSymbolTable * initial) {
    DeclarationSymbolTable * aux = initial;
    DeclarationSymbolTable * newSymbolTable = NULL;

    while (aux) {
        addNewDeclarationSymbolTableCompleteElement(&newSymbolTable, aux->id, aux->type,
                aux->declarationMarker, aux->possibleMappings, aux->currentMapping);
        aux = aux->next;
    }
    return newSymbolTable;
}

void addNewDeclarationSymbolTableElement(DeclarationSymbolTable ** head, char * id, char * type, char * decl) {
    DeclarationSymbolTable * newEl = (DeclarationSymbolTable *) malloc(1 * sizeof (DeclarationSymbolTable));
    newEl->id = (char *) malloc((strlen(id) + 1) * sizeof (char));
    newEl->type = (char *) malloc((strlen(type) + 1) * sizeof (char));
    newEl->declarationMarker = (char *) malloc((strlen(decl) + 1) * sizeof (char));
    strcpy(newEl->id, id);
    strcpy(newEl->type, type);
    strcpy(newEl->declarationMarker, decl);
    newEl->possibleMappings = NULL;
    newEl->currentMapping = NULL;
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        DeclarationSymbolTable * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

int addNewPossibleDeclarationSymbolTableMapping(DeclarationSymbolTable ** head, char * id, char * possibleMapping) {
    DeclarationSymbolTable * p;
    p = *head;
    int s = 0;
    while (p -> next && s == 0) {
        if (!strcmp(id, p->id)) {
            s = 1;
        } else {
            p = p->next;
        }
    }
    if (!strcmp(p->id, id)) {
        s = 1;
    }
    if (s == 0) {
        return 0;
    } else {
        addNewString(&(p->possibleMappings), possibleMapping);
        return 1;
    }
}

void addPossibleDeclarationSymbolTableMappingsForAllCandidatesWhereTypeMatch(DeclarationSymbolTable ** head,
        char * type, char * id) {
    DeclarationSymbolTable * aux = *head;
    while (aux) {
        char * copyAuxType;
        copyAuxType = (char *) malloc(500 * sizeof (char));
        strcpy(copyAuxType, aux->type);

        if (!strcmp(copyAuxType, type)) {
            addNewString(&(aux->possibleMappings), id);
        } else {
            //aux->type, type

            //replace all [] with *, since they are compatible; what if: [333]?

            char * copyReplacementType = (char *) malloc(500 * sizeof (int));
            char * copyReplacementAuxType = (char *) malloc(500 * sizeof (int));

            strcpy(copyReplacementType, type);
            strcpy(copyReplacementAuxType, aux->type);

            copyReplacementType = removeArraySizeInString(copyReplacementType);
            copyReplacementAuxType = removeArraySizeInString(copyReplacementAuxType);

            char * auxReplace;

            while ((auxReplace = replace_str(copyReplacementType, "[]", "*")) && (auxReplace)) {
                strcpy(copyReplacementType, auxReplace);
            }
            while ((auxReplace = replace_str(copyReplacementAuxType, "[]", "*")) && (auxReplace)) {
                strcpy(copyReplacementAuxType, auxReplace);
            }

            if (!strcmp(copyReplacementType, copyReplacementAuxType)) {
                addNewString(&(aux->possibleMappings), id);
            }
        }

        /*
        strcat(copyAuxType,"*");
        if(!strcmp(copyAuxType, type)){
            char * referencedID;
            referencedID = (char*) malloc (500 * sizeof(char));
            sprintf(referencedID,"*%s", id);
            addNewString(&(aux->possibleMappings), referencedID);
        }
         */
        aux = aux->next;
    }
}

void addNewPossibleMappingsDeclarationSymbolTableFromSymbolTable(DeclarationSymbolTable ** head,
        SymbolTable * headSymbolTable) {
    printf("\t\tAdding new possible mappings declaration symbol table from symbol table\n");
    SymbolTable * aux = headSymbolTable;
    DeclarationSymbolTable * auxMappingCand;
    auxMappingCand = *head;
    while (aux) {
        IdOfVariable * auxIDs = aux->ListOfIdentifiers;
        while (auxIDs) {
            addPossibleDeclarationSymbolTableMappingsForAllCandidatesWhereTypeMatch(&auxMappingCand,
                    aux->TypeOfVar, auxIDs->ID);
            auxIDs = auxIDs->next;
        }
        aux = aux->next;
    }
}

void printDeclarationSymbolTable(char * outputFile, DeclarationSymbolTable * head) {
    FILE * fout = fopen(outputFile, "w");
    DeclarationSymbolTable * p;
    p = head;
    while (p) {
        ListOfString * aux;
        aux = p->possibleMappings;
        fprintf(fout, "Variable: %s %s\n", p->type, p->id);
        fprintf(fout, "Declaration marker: %s\n", p->declarationMarker);
        fprintf(fout, "CurrentMapping: %s\n", p->currentMapping);
        fprintf(fout, "List of possible mappings: \n");
        while (aux) {
            fprintf(fout, "%s\n", aux->el);
            aux = aux->next;
        }
        p = p ->next;
    }
    fclose(fout);
}



// /* DECL: 0 */ @ FILE @ *$_main_ifile
// /* DECL: 1 */ @ FILE @ *$_main_ofile

DeclarationSymbolTable * readDeclarationSymbolTableFromFile(char * inputFile) {
    FILE * fin = fopen(inputFile, "r");
    DeclarationSymbolTable * FinalDeclSymbolTable = NULL;
    char * line;
    line = (char *) malloc(1000 * sizeof (char));
    while (fgets(line, 400, fin) != NULL) {
        char * declarationMarker;
        declarationMarker = (char *) malloc(500 * sizeof (char));
        char * varType;
        varType = (char *) malloc(500 * sizeof (char));
        char * variableNameAndArray;
        variableNameAndArray = (char *) malloc(500 * sizeof (char));
        char * token = strtok(line, "@");
        strcpy(declarationMarker, token);
        declarationMarker [strlen(declarationMarker) - 1] = '\0';
        token = strtok(NULL, "@");
        strcpy(varType, token + 1);
        varType [strlen(varType) - 1] = '\0';
        token = strtok(NULL, "@");
        strcpy(variableNameAndArray, token + 1);
        variableNameAndArray [strlen(variableNameAndArray) - 1] = '\0';


        token = strtok(variableNameAndArray, " ");

        char * justVariableName;
        justVariableName = (char *) malloc(500 * sizeof (char));
        strcpy(justVariableName, token);

        token = strtok(NULL, " ");
        if (token) {
            unsigned long lengthAdd = strlen(varType);
            varType[lengthAdd] = '[';
            varType[lengthAdd + 1] = ']';
            varType[lengthAdd + 2] = 0;
        }
        while (justVariableName[0] == '*') {
            int length = (int) strlen(varType);
            varType[length] = '*';
            varType[length + 1] = 0;

            justVariableName = justVariableName + 1;
        }




        addNewDeclarationSymbolTableElement(&FinalDeclSymbolTable, justVariableName, varType, declarationMarker);
    }
    free(line);
    fclose(fin);
    return FinalDeclSymbolTable;
}









DeclarationSymbolTable * readDeclarationSymbolTableFromFileForHost(char * inputFile) {
    FILE * fin = fopen(inputFile, "r");
    DeclarationSymbolTable * FinalDeclSymbolTable = NULL;
    char * line;
    line = (char *) malloc(1000 * sizeof (char));
    while (fgets(line, 400, fin) != NULL) {
        char * declarationMarker;
        declarationMarker = (char *) malloc(500 * sizeof (char));
        char * varType;
        varType = (char *) malloc(500 * sizeof (char));
        char * variableNameAndArray;
        variableNameAndArray = (char *) malloc(500 * sizeof (char));
        char * token = strtok(line, "@");
        strcpy(declarationMarker, token);
        declarationMarker [strlen(declarationMarker) - 1] = '\0';
        token = strtok(NULL, "@");
        strcpy(varType, token + 1);
        varType [strlen(varType) - 1] = '\0';
        token = strtok(NULL, "@");
        strcpy(variableNameAndArray, token + 1);
        variableNameAndArray [strlen(variableNameAndArray) - 1] = '\0';


        token = strtok(variableNameAndArray, " ");

        char * justVariableName;
        justVariableName = (char *) malloc(500 * sizeof (char));
        strcpy(justVariableName, token);

        token = strtok(NULL, " ");
        if (token) {
            unsigned long lengthAdd = strlen(varType);
            varType[lengthAdd] = '[';
            varType[lengthAdd + 1] = ']';
            varType[lengthAdd + 2] = 0;
        }
        while (justVariableName[0] == '*') {
            int length = (int) strlen(varType);
            varType[length] = '*';
            varType[length + 1] = 0;

            justVariableName = justVariableName + 1;
        }




        /*!
         * Append the $_host_marker for all variables from here!
         * It is the host symbol table.
         */
        char * hostVariableName = (char *) malloc (2000 * sizeof(char));
        sprintf(hostVariableName, "$_host_%s", justVariableName);

        addNewDeclarationSymbolTableElement(&FinalDeclSymbolTable, hostVariableName, varType, declarationMarker);
    }
    free(line);
    fclose(fin);
    return FinalDeclSymbolTable;
}


void generateSymbolTableFileFromDeclarations(char * declarationFile, char * outputFile, char * TXLProgsPath) {
    char * commandTXL;
    commandTXL = (char *) malloc(500 * sizeof (char));

    printf("\t\t[TXL] GenerateSymbolTableForLocalDefinedVariables.x >> Generate Symbol Table For Local Defined Variables \n");
    sprintf(commandTXL, "%sGenerateSymbolTableForLocalDefinedVariables.x %s %s %s", TXLProgsPath, declarationFile,
            outputFile, ConsoleStderrOutput);
    int status = system(commandTXL);
    if (status != 0) {
        printf("ERROR! GenerateSymbolTableForLocalDefinedVariables.x\n");
        printf("\t%s\n", commandTXL);
        exit(1);
    }
#ifdef DEBUGING
    else
        printf("\t\t\t|>> temp_symbol_table_declarations_file.out\n");
#endif
    free(commandTXL);
    fflush(stdout);
}

DeclarationSymbolTable * GenerateDeclarationsSymbolTable(ListOfString * Skeleton,
        DependencyList * currentDependencyList, SymbolTable * HostSymbolTable, char * TXLTemporaryFolder) {
    printf("[AUTOSCALPEL] Generate Declarations sysmbol table\n");
    DependencyList * auxDepLst = currentDependencyList;
    ListOfString * listOfAllNeededDecl = NULL;
    while (auxDepLst) {
        ListOfString * auxLstOfDep = auxDepLst->ListOfDependencies;
        while (auxLstOfDep) {
            if (!searchStringInListOfStrings(listOfAllNeededDecl, auxLstOfDep->el)) {
                addNewString(&listOfAllNeededDecl, auxLstOfDep->el);
            }
            auxLstOfDep = auxLstOfDep->next;
        }
        auxDepLst = auxDepLst->next;
    }
    ListOfString * listOfCompleteDeclarations = NULL;
    ListOfString * auxListOfAllNeededDecl = listOfAllNeededDecl;
    while (auxListOfAllNeededDecl) {
        ListOfString * auxSkeleton = Skeleton;
        int signal = 0;
        while (auxSkeleton && !signal) {
            if (strstr(auxSkeleton->el, auxListOfAllNeededDecl->el)) {
                addNewString(&listOfCompleteDeclarations, auxSkeleton->el);
            }
            auxSkeleton = auxSkeleton->next;
        }
        auxListOfAllNeededDecl = auxListOfAllNeededDecl->next;
    }
    char * tempDeclarationListOutput;
    tempDeclarationListOutput = (char *) malloc(100 * sizeof (char));
    sprintf(tempDeclarationListOutput, "%stemp_decl_list_output.out", TXLTemporaryFolder);
    printAListOfStrings(listOfCompleteDeclarations, tempDeclarationListOutput);
#ifdef DEBUGING
    printf("\t\t|>> temp_decl_list_output.out\n");
#endif
    char * tempSTFileOutput;
    tempSTFileOutput = (char *) malloc(100 * sizeof (char));
    sprintf(tempSTFileOutput, "%stemp_symbol_table_declarations_file.out", TXLTemporaryFolder);

    generateSymbolTableFileFromDeclarations(tempDeclarationListOutput, tempSTFileOutput, TXLToolsPath);
    DeclarationSymbolTable * FinalDeclSymbolTable = readDeclarationSymbolTableFromFile(tempSTFileOutput);

    /* Add new possible mappings ceclarations symbol table from symbol table */
    addNewPossibleMappingsDeclarationSymbolTableFromSymbolTable(&FinalDeclSymbolTable, HostSymbolTable);

    return FinalDeclSymbolTable;
}

int countElementsInDeclarationSymbolTable(DeclarationSymbolTable * head) {
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    return count;
}

/*
ListOfString * declarationSymbolTableToListOfStringForGPIndividual(DeclarationSymbolTable * head) {
    ListOfString * finalListOfString = NULL;
    while (head) {
        char * stringDeclaration;
        stringDeclaration = (char *) malloc(1000 * sizeof (char));
        sprintf(stringDeclaration, "%s@%s@%s", head->declarationMarker, head->id, head->currentMapping);
        addNewString(&finalListOfString, stringDeclaration);
        free(stringDeclaration);
        head = head->next;
    }
    return finalListOfString;
}
 */

ListOfString * declarationSymbolTableToListOfStringForGPIndividual(DeclarationSymbolTable * currentDeclSymbolTable) {
    DeclarationSymbolTable * aux = currentDeclSymbolTable;
    ListOfString * result = NULL;

    while (aux) {
        if (aux->currentMapping) {
            addNewDeclarationSymbolTableToListOfStringForGPIndividual(&result, aux->declarationMarker, aux->id,
                    aux->currentMapping);
        }
        aux = aux->next;
    }

    return result;
}

void addNewDeclarationSymbolTableToListOfStringForGPIndividual(ListOfString ** head, char * declarationMarker, char * id,
        char * currentMapping) {
    char * newStringElement;
    newStringElement = (char *) malloc(1000 * sizeof (char));
    sprintf(newStringElement, "%s@%s@%s", declarationMarker, id, currentMapping);
    addNewString(&(*head), newStringElement);
}

int addNewCurrentMappingDeclarationSymbolTable(DeclarationSymbolTable ** head, char * id, char * currentMapping) {
    DeclarationSymbolTable * p;
    p = *head;
    int s = 0;
    while (p -> next && s == 0) {
        if (!strcmp(id, p->id)) {
            s = 1;
        } else {
            p = p->next;
        }
    }
    if (!strcmp(p->id, id)) {
        s = 1;
    }
    if (s == 0) {
        return 0;
    } else {
        if (currentMapping) {
            free(p->currentMapping);

            p->currentMapping = (char *) malloc((strlen(currentMapping) + 1) * sizeof (char));
            strcpy(p->currentMapping, currentMapping);
            return 1;
        }
    }
    return 0;
}

DeclarationSymbolTable * nthElementInDeclarationSymbolTable(DeclarationSymbolTable * head, int n) {
    while (n > 0 && head) {
        head = head->next;
        n--;
    }
    if (n == 0) {
        DeclarationSymbolTable * selectedDeclaration = NULL;

        addNewDeclarationSymbolTableElement(&selectedDeclaration, head->id, head->type, head->declarationMarker);
        addNewCurrentMappingDeclarationSymbolTable(&selectedDeclaration, head->id, head->currentMapping);
        selectedDeclaration->possibleMappings = copyCompleteListOfString(head->possibleMappings);

        return selectedDeclaration;
    } else {
        return NULL;
    }
}

DeclarationSymbolTable * nthElementInDeclarationSymbolTablePointer(DeclarationSymbolTable * head, int n) {
    while (n > 0 && head) {
        head = head->next;
        n--;
    }
    if (n == 0) {
        return head;
    } else {
        return NULL;
    }
}


//functions for GP algorithm declaration selection

int numberOfElementsWithCurrentMapping(DeclarationSymbolTable * head) {
    int count = 0;

    while (head) {
        if (head->currentMapping) {
            count++;
        }
        head = head->next;
    }

    return count;
}

int numberOfElementsWithCurrentMappingWithMoreThanOnePossibleMappings(DeclarationSymbolTable * head) {
    int count = 0;

    while (head) {
        if (head->currentMapping && (countElementsInListOfString(head->possibleMappings) > 1)) {
            count++;
        }
        head = head->next;
    }

    return count;
}

int numberOfElementsNOCurrentMapping(DeclarationSymbolTable * head) {
    int count = 0;

    while (head) {
        if (!(head->currentMapping)) {
            count++;
        }
        head = head->next;
    }

    return count;
}

DeclarationSymbolTable * nthElementWithCurrentMapping(DeclarationSymbolTable * head, int n) {
    while (head && n) {
        if (head->currentMapping && (countElementsInListOfString(head->possibleMappings) > 1)) {
            n--;
        }
        head = head->next;
    }

    return head;
}

DeclarationSymbolTable * nthElementWithCurrentMappingMoreThanOnePossible(DeclarationSymbolTable * head, int n) {
    n++;
    DeclarationSymbolTable * searchedEl = NULL;
    while (head && n) {
        if (head->currentMapping && (countElementsInListOfString(head->possibleMappings) > 1)) {
            n--;
            searchedEl = head;
        }
        head = head->next;
    }

    return searchedEl;
}

DeclarationSymbolTable * nthElementWithNOCurrentMapping(DeclarationSymbolTable * head, int n) {
    while (head && n) {
        if (!(head->currentMapping)) {
            n--;
        }
        head = head->next;
    }

    return head;
}

DeclarationSymbolTable * searchAnElementInDeclarationSymbolTable(DeclarationSymbolTable * head,
        DeclarationSymbolTable * searchedEl) {
    while (head) {

        if (head->type &&
                head->declarationMarker && !strcmp(head->declarationMarker, searchedEl->declarationMarker) &&
                !strcmp(head->type, searchedEl->type)) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

int countElementsWithMoreThenOnePossibleMappingsDeclarationSymbolTable(DeclarationSymbolTable * head) {

    int count = 0;

    while (head) {

        if (countElementsInListOfString(head->possibleMappings) > 1) {
            count++;
        }

        head = head->next;
    }

    return count;
}
