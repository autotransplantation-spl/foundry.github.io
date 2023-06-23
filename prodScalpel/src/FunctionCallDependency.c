#include "FunctionCallDependency.h"
#include "ListOfString.h"
#include "GenTrans.h"

#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
#include <string.h>


#define DEPENDENCIES_FOR_GLOBALS_MARKER "DEPENDENCIES_FOR_GLOBAL"

void freeListOfCallDependency(CallDependency ** head) {
    CallDependency * aux;
    while (* head) {
        aux = *head;
        * head = (*head) -> next;
        freeListOfFunctionSourceFile(&(aux->calledFunctions));
        aux->calledFunctions = NULL;
        free(aux->LOCMarker);
        aux->LOCMarker = NULL;
        aux->next = NULL;
        free(aux);
        aux = NULL;
    }
    (* head) = NULL; //just in case...
}

CallDependency * searchCallDependencyForALOC(CallDependency * head, char * locName) {
    CallDependency * p;
    p = head;
    int s = 0;
    while (p && !s) {
        if (!strcmp(p->LOCMarker, locName)) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

CallDependency * searchCallDependencyForGlobalMark(CallDependency * head, char * LOCMark) {
    CallDependency * p;
    p = head;
    int s = 0;
    while (p && !s) {
        if (!strcmp(p->LOCMarker, LOCMark)) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void addNewLOCMarker(CallDependency ** head, char * locName) {
    CallDependency * newEl = (CallDependency *) malloc(1 * sizeof (CallDependency));
    newEl->LOCMarker = (char *) malloc((strlen(locName) + 1) * sizeof (char));
    strcpy(newEl->LOCMarker, locName);
    newEl->calledFunctions = NULL;
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        CallDependency * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

int addCalledFunction(CallDependency ** head, char * LOCMarker, char * calledFunction, char * functionSourceFile) {
    CallDependency * p;
    p = *head;
    int s = 0;
    while (p -> next && s == 0) {
        if (!strcmp(LOCMarker, p->LOCMarker)) {
            s = 1;
        } else {
            p = p->next;
        }
    }
    if (!strcmp(p->LOCMarker, LOCMarker)) {
        s = 1;
    }
    if (s == 0) {
        return 0;
    } else {
        addNewFunctionSourceFile(&(p->calledFunctions), calledFunction, functionSourceFile);
        return 1;
    }
}

CallDependency * readCallDependencyFromFile(char * inputFile) {

    FILE * fin = fopen(inputFile, "r");

    char * line;
    line = (char *) malloc(800 * sizeof (char));
    CallDependency * ListOfCallDependencies = NULL;
    char * currentName;
    currentName = (char*) malloc(800 * sizeof (char));
    while (fgets(line, 400, fin) != NULL) {


        char * locMarker;
        locMarker = (char *) malloc(500 * sizeof (char));

        strcpy(locMarker, line);
        locMarker[strlen(locMarker) - 1] = 0;

        addNewLOCMarker(&ListOfCallDependencies, locMarker);
        
        while (strcmp(fgets(line, 400, fin), LINE_END)) {
            char * calledFunctionsString;
            calledFunctionsString = (char *) malloc(1000 * sizeof (char));
            char * calledFunctionSourceFile;
            calledFunctionSourceFile = (char *) malloc(3000 * sizeof (char));

            sscanf(line, "%s %s", calledFunctionsString, calledFunctionSourceFile);


            addCalledFunction(&ListOfCallDependencies, locMarker, calledFunctionsString, calledFunctionSourceFile);
            
            free(calledFunctionSourceFile);
            free(calledFunctionsString);
        }
    }
    free(line);
    free(currentName);
    fclose(fin);
    return ListOfCallDependencies;
}


void addNeededCalledFunction(ListOfFunctionSourceFile ** head, char *  calledFunctionsString, char * calledFunctionSourceFile) {

    ListOfFunctionSourceFile * newEl = (ListOfFunctionSourceFile *) malloc(1 * sizeof (ListOfFunctionSourceFile));

    newEl->functionName = (char *) malloc((strlen(calledFunctionsString) + 1) * sizeof (char));
    strcpy(newEl->functionName, calledFunctionsString);

    newEl->sourceFile = (char *) malloc((strlen(calledFunctionSourceFile) + 1) * sizeof (char));
    strcpy(newEl->sourceFile, calledFunctionSourceFile);

    newEl->next = NULL;

    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfFunctionSourceFile * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}


void addNeededCalledFunctions(ListOfFunctionSourceFile ** head, char *  calledFunctionsString, char * calledFunctionSourceFile) {

    ListOfFunctionSourceFile * newEl = (ListOfFunctionSourceFile *) malloc(1 * sizeof (ListOfFunctionSourceFile));

    newEl->functionName = (char *) malloc((strlen(calledFunctionsString) + 1) * sizeof (char));
    strcpy(newEl->functionName, calledFunctionsString);

    newEl->sourceFile = (char *) malloc((strlen(calledFunctionSourceFile) + 1) * sizeof (char));
    strcpy(newEl->sourceFile, calledFunctionSourceFile);

    newEl->next = NULL;

    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfFunctionSourceFile * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}


void addNeededFunctionsDeclaration(CallDependency ** head, char * locName) {
    CallDependency * newEl = (CallDependency *) malloc(1 * sizeof (CallDependency));
    newEl->LOCMarker = (char *) malloc((strlen(locName) + 1) * sizeof (char));
    strcpy(newEl->LOCMarker, locName);
    newEl->calledFunctions = NULL;
    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        CallDependency * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}

CallDependency * readListOfNeededFunctionsDeclaration(char * inputFile) {

    CallDependency * ListOfCalledDependencies = NULL;

    FILE * fin = fopen(inputFile, "r");

    char * line;
    line = (char *) malloc(400 * sizeof (char));
    int marker;
    while (fgets(line, 399, fin) != NULL) {
        strtok(line, "\n");
        if (!strcmp(line, DEPENDENCIES_FOR_GLOBALS_MARKER)) {
            fgets(line, 399, fin);
            strtok(line, "\n");
        }
        char * LOCMarker = (char *) malloc((strlen(line) +1) * sizeof (char));
        strcpy(LOCMarker, line);

        addNeededFunctionsDeclaration(&ListOfCalledDependencies, LOCMarker);
        marker = 0;

        while (marker == 0 && fgets(line, 399, fin) != NULL) {
            strtok(line, "\n");
            if (!strcmp(line, DEPENDENCIES_FOR_GLOBALS_MARKER)) {
                marker = 1;
            } else {

                char *calledFunctionsString;
                calledFunctionsString = (char *) malloc(399 * sizeof(char));
                char *calledFunctionSourceFile;
                calledFunctionSourceFile = (char *) malloc(399 * sizeof(char));

                sscanf(line, "%s %s", calledFunctionsString, calledFunctionSourceFile);

                addCalledFunction(&ListOfCalledDependencies, LOCMarker, calledFunctionsString,
                                        calledFunctionSourceFile);

                free(calledFunctionSourceFile);
                free(calledFunctionsString);
            }

        }
    }

    free(line);
    fclose(fin);
    return ListOfCalledDependencies;
}
/* TODO delete
void addCalledFunctionFroNeededFuntionsGlobalDeclaration(ListOfFunctionSourceFile ** head, char * sourceFile, char * functionName) {
    ListOfFunctionSourceFile * newEl = (ListOfFunctionSourceFile *) malloc(1 * sizeof (ListOfFunctionSourceFile));

    newEl->functionName = (char *) malloc((strlen(functionName) + 1) * sizeof (char *));
    strcpy(newEl->functionName, sourceFile);

    newEl->sourceFile = (char *) malloc((strlen(sourceFile) + 1) * sizeof (char *));
    strcpy(newEl->sourceFile, sourceFile);

    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        ListOfFunctionSourceFile * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}
*/

ListOfFunctionSourceFile * copyListOfCalledFunctions(ListOfFunctionSourceFile * head) {

    ListOfFunctionSourceFile * pHead = NULL;
    ListOfFunctionSourceFile * newHead = NULL; //= (ListOfFunctionSourceFile *) malloc(1 * sizeof (ListOfFunctionSourceFile));
    pHead = head;

    if (head == NULL) {
        return NULL;
    }
    while (pHead) {
        addNeededCalledFunction(&newHead,  pHead->functionName, pHead->sourceFile);
        pHead = pHead->next;
    }

    return newHead;
}

void addNewListOfNeededFunctionsForGlobals(CallDependency ** head, CallDependency * source, char * newMark) {
    CallDependency * newEl = (CallDependency *) malloc(1 * sizeof (CallDependency));
    newEl->LOCMarker = NULL;
    newEl->calledFunctions = NULL;

    ListOfFunctionSourceFile * sourceCalledFunctions = source->calledFunctions;

    newEl->calledFunctions = copyListOfCalledFunctions(sourceCalledFunctions);

    newEl->LOCMarker = (char *) malloc((strlen(source->LOCMarker) + 1) * sizeof (char));
    strcpy(newEl->LOCMarker, source->LOCMarker);

    newEl->next = NULL;
    if (* head == NULL) {
        * head = newEl;
    } else {
        CallDependency * p;
        p = *head;
        while (p ->next) {
            p = p->next;
        }
        p ->next = newEl;
    }
}


/*
int addNewCalledFunctionInExistingOneDeclaration(ListOfFunctionSourceFile ** head, char  * sourceListOfFunctionSourceFile ){
    ListOfFunctionSourceFile * p;
    p = *head;
    int s = 0, d = 0;
    while (p -> next && s == 0) {
        if (!strcmp(sourceListOfFunctionSourceFile, p->functionName)) {
            s = 1;
        } else {
            p = p->next;
        }
    }
    if (!strcmp(p->calledFunctions, sourceListOfFunctionSourceFile)) {
        s = 1;
    }
    ListOfString * currentDependencies = p->calledFunctions;
    while(currentDependencies && d == 0){

        if(!strcmp(currentDependencies->el, sourceListOfFunctionSourceFile))
            d = 1;
        // if(!strncmp(declaration ,p->ListOfDependencies->el,strlen(declaration)))
        //if(strstr(p->ListOfDependencies->el, declaration))

        currentDependencies = currentDependencies->next;
    }
    if (s == 0 || d == 1) {
        return 0;
    } else {
        addNeededCalledFunction(ListOfFunctionSourceFile ** head, char *  calledFunctionsString, char * calledFunctionSourceFile)
        addNewString(&(p->ListOfDependencies), declaration);
        return 1;
    }
}*/
/*
void addNewListOfNeededFunctionsToAnExistingOneSearchingIfVarExisting(ListOfStructMark * ListOfDeclarationMark, CallDependency ** destination, CallDependency * source) {
    CallDependency  * auxSource = source;
    CallDependency * auxDestination = NULL;
    while (auxSource) {
        char * newGobalDeclMark = NULL;
        newGobalDeclMark = returnNewMark(ListOfDeclarationMark, source->globalDeclMark);
        auxDestination = searchGlobalDeclMark(*destination, newGobalDeclMark);
        if(auxDestination == NULL){
            addNewLOCMarker(&(*destination), auxSource->globalDeclMark);
            ListOfFunctionSourceFile * auxDep = auxSource->calledFunctions;
            while (auxDep) {
                addNeededCalledFunction(&(*destination), auxDep->functionName, auxDep->sourceFile);
                auxDep = auxDep->next;
            }
        } else {
            // if(auxSource->next == NULL) {
            // addNewStatement(&destination, auxSource->Statement);
            ListOfFunctionSourceFile *auxDep = auxSource->calledFunctions;
            while (auxDep) {

                //addNewCalledFunctionInExistingOneDeclaration(&(*destination)->calledFunctions, auxSource->calledFunctions);
                auxDep = auxDep->next;
            }
            //}
        }
        auxSource = auxSource->next;
    }


    fflush(stdout);
}
*/

int addCallFunctionInExistingOne(CallDependency ** head, char * functionName, char * sourceFile) {
    CallDependency * p;
    p = *head;
    ListOfFunctionSourceFile * sourceCalledFunctions = p->calledFunctions;
    int s = 0, d = 0;
    while (p -> next && s == 0) {
        if (!strcmp(functionName, sourceCalledFunctions->functionName)) {
            s = 1;
        } else {
            p = p->next;
        }
    }
    if (!strcmp( sourceCalledFunctions->functionName, functionName)) {
        s = 1;
    }
    ListOfFunctionSourceFile * currentCallFunctionList = p->calledFunctions;
    while(currentCallFunctionList && d == 0){

        if(!strcmp(currentCallFunctionList->functionName, functionName))
            d = 1;
        currentCallFunctionList = currentCallFunctionList->next;
    }
    if (s == 0 || d == 1) {
        return 0;
    } else {
        addCalledFunction(&(p->calledFunctions), p->LOCMarker, functionName,sourceFile);
        return 1;
    }
}

void addNeededCallFunctionDeclarationListToAnExistingOne(CallDependency ** destination, CallDependency * source) {
    CallDependency * auxSource = source;
    CallDependency * auxDestination = NULL;
    while (auxSource) {
        auxDestination = searchCallDependencyForGlobalMark(*destination, auxSource->LOCMarker);
        if(auxDestination == NULL){
            addNeededFunctionsDeclaration(&(*destination), auxSource->LOCMarker);
            ListOfFunctionSourceFile * auxCallFunction = auxSource->calledFunctions;
            while (auxCallFunction) {
                addCalledFunction(&(*destination), auxSource->LOCMarker, auxCallFunction->functionName,auxCallFunction->sourceFile);
                auxCallFunction = auxCallFunction->next;
            }
        } else {
            // if(auxSource->next == NULL) {
            // addNewStatement(&destination, auxSource->Statement);
            ListOfFunctionSourceFile * auxCallFunction = auxSource->calledFunctions;
            while (auxCallFunction) {
                addCallFunctionInExistingOne(&(*destination), auxCallFunction->functionName,auxCallFunction->sourceFile);
                auxCallFunction = auxCallFunction->next;
            }
            //}
        }
        auxSource = auxSource->next;
    }


    fflush(stdout);
}